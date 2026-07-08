#!/usr/bin/env python3
"""Persona 3 FES matching build driver.

Pipeline (all with the original CodeWarrior EE toolchain):
  retail ELF --extract--> image.bin (loadable PT_LOAD payload, vram 0x100000)
  code segs:  splat asm --desym.py--> raw asm --asm.py--> byte-exact .o
  data segs:  .incbin from image.bin --asm--> .o
  all .o   --mwldps2 + build/slus21621.lcf--> build/slus21621.elf
  verify:  linked PT_LOAD payload sha1 == retail loadable image

Config lives in config/slus21621.yaml; toolchain paths come from
tools/verify_config*.json or P3_MWCC / P3_RETAIL_ELF.
"""
import bisect, hashlib, json, os, struct, subprocess, sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
BUILD = REPO / "build"
ASM = REPO / "asm"
IMAGE = REPO / "image.bin"

# loadable image layout (rom offset into image.bin, vram, kind)
IMAGE_SHA1 = "9203646d9aa48ff24eb4ba4b328b02df468a9483"
IMAGE_SIZE = 0x8ACC80
VRAM = 0x100000
RETAIL_SHA1 = "3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb"
RETAIL_PAYLOAD_OFF = 0x80
SEGMENTS = [
    ("code1", "code", 0x000000, 0x4A2000),
    ("data1", "data", 0x4A2000, 0x67F710),
    ("code2", "code", 0x67F710, 0x681000),
    ("data2", "data", 0x681000, 0x8ACC80),
]


def cfg():
    c = {}
    for n in ("verify_config.json", "verify_config.local.json"):
        p = REPO / "tools" / n
        if p.is_file():
            c.update(json.loads(p.read_text()))
    c["mwcc"] = os.environ.get("P3_MWCC", c.get("mwcc"))
    c["retail_elf"] = os.environ.get("P3_RETAIL_ELF", c.get("retail_elf"))
    if not c.get("mwcc"):
        sys.exit("build: set mwcc in tools/verify_config.local.json or P3_MWCC")
    d = Path(c["mwcc"]).parent
    c["asm_exe"] = str(d / "asm_r5900_elf.exe")
    c["ld_exe"] = str(d / "mwldps2.exe")
    return c


def sh(cmd):
    p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if p.returncode:
        sys.stderr.write(p.stdout)
        sys.exit(f"build: command failed: {cmd[0]}")
    return p.stdout


def extract_image(c):
    """Write image.bin = the retail ELF's loadable PT_LOAD payload."""
    elf = Path(c["retail_elf"]).read_bytes()
    phoff = struct.unpack_from("<I", elf, 0x1c)[0]
    for i in range(struct.unpack_from("<H", elf, 0x2c)[0]):
        t, off, va, pa, fsz, msz = struct.unpack_from("<IIIIII", elf, phoff + i * 0x20)
        if t == 1 and va == VRAM:
            IMAGE.write_bytes(elf[off:off + fsz])
            return
    sys.exit("build: could not find loadable segment in retail ELF")


def patch_align1(path, sec):
    d = bytearray(path.read_bytes())
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shx = struct.unpack_from("<HHH", d, 0x2e)
    sto = struct.unpack_from("<IIIIII", d, shoff + shx * she)[4]

    def nm(n):
        e = d.find(b"\0", sto + n)
        return d[sto + n:e].decode()
    for i in range(shn):
        o = shoff + i * she
        if nm(struct.unpack_from("<I", d, o)[0]) == sec:
            struct.pack_into("<I", d, o + 0x20, 1)
    path.write_bytes(d)


def build_code(c, name, lo, hi):
    src = ASM / f"{name}.s"
    raw = ASM / f"{name}_raw.s"
    obj = ASM / f"{name}.o"
    raw.write_text(subprocess.run([sys.executable, str(REPO / "tools/desym.py"), str(src)],
                                  stdout=subprocess.PIPE, text=True).stdout)
    sh([sys.executable, str(REPO / "tools/asm.py"), str(raw), str(obj),
        str(IMAGE), hex(VRAM + lo), hex(lo)])
    patch_align1(obj, ".text")


def build_data(c, name, lo, hi):
    src = ASM / f"{name}.s"
    obj = ASM / f"{name}.o"
    src.write_text(f'.section .{name}, "aw"\n.incbin "../image.bin", {hex(lo)}, {hex(hi - lo)}\n')
    sh([c["asm_exe"], "-gnu", "-endian", "little", "-o", obj.name, src.name])  # cwd=asm below
    patch_align1(obj, f".{name}")


def write_lcf():
    body = []
    for name, kind, lo, hi in SEGMENTS:
        sec = ".text" if kind == "code" else f".{name}"
        body.append(f"        {name}.o({sec})")
    lcf = (
        "MEMORY {\n"
        f"    image : ORIGIN = {hex(VRAM)}, LENGTH = {hex(IMAGE_SIZE)}\n"
        "}\n"
        "SECTIONS {\n"
        "    .image : {\n" + "\n".join(body) + "\n    } > image\n"
        "}\n"
    )
    (BUILD / "slus21621.lcf").write_text(lcf)


def link(c):
    objs = [str(ASM / f"{n}.o") for n, _, _, _ in SEGMENTS]
    sh([c["ld_exe"], "-nostdlib", "-nodeadstrip", "-m", "func_00100008",
        "-o", str(BUILD / "slus21621.elf"), str(BUILD / "slus21621.lcf")] + objs)


def overlay_c(payload, c):
    """Link decompiled C physically into the loadable image: compile each
    src/*.c, recover a symbol map from the matched functions (see link_c), then
    re-encode each matched function's compiled-C relocations from that map and
    write the result over its region in the payload. Only functions whose
    resolved C reproduces retail exactly are overlaid; the rest keep the
    assembly baseline, so the image stays byte-identical either way.
    Returns (payload, n_linked, n_matched)."""
    import verify as V
    import link_c as L
    retail = V.RetailElf(c["retail_elf"])
    bounds = sorted(int(k, 16) for k in
                    json.loads((REPO / "tools/slus21621_functions.json").read_text())["windows"])

    def window_for(a):
        i = bisect.bisect_right(bounds, a)
        return bounds[i] - a if i < len(bounds) else None

    payload = bytearray(payload)
    n_linked = n_matched = 0
    for cpath in sorted((REPO / "src").rglob("*.c")):
        mks = V.scan_markers(cpath)
        if not mks:
            continue
        op = BUILD / "c_obj.o"
        p = subprocess.run([c["mwcc"], "-O2", "-Iinclude", "-c", str(cpath), "-o", str(op)],
                           cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if p.returncode:
            continue
        obj = V.ObjectFile(op)
        ff = []
        for mk in mks:
            if mk["stub"] or mk["nonmatching"] or not mk["name"]:
                continue
            try:
                body, rels = obj.function(mk["name"])
            except KeyError:
                continue
            w = window_for(mk["addr"])
            if not w or w > 0x10000:
                continue
            win = retail.bytes_at(mk["addr"], w)
            if V.compare(body, rels, win)[0] != 0:
                continue
            ff.append((mk["addr"], body, rels, win[:len(body)]))
        if not ff:
            continue
        symmap, _ = L.recover_symbols([(a, b, r, w) for a, b, r, w in ff])
        for addr, body, rels, win in ff:
            n_matched += 1
            resolved, missing = L.resolve_function(addr, body, rels, symmap)
            if not missing and resolved == win:
                o = addr - VRAM
                payload[o:o + len(resolved)] = resolved
                n_linked += 1
    return bytes(payload), n_linked, n_matched


def build_matching_elf(c):
    """Splice our built loadable payload into the retail ELF structure and
    write the full, runnable, byte-identical SLUS_216.21. Returns exit status."""
    be = (BUILD / "slus21621.elf").read_bytes()
    img = IMAGE.read_bytes()
    phoff = struct.unpack_from("<I", be, 0x1c)[0]
    payload = None
    for i in range(struct.unpack_from("<H", be, 0x2c)[0]):
        t, off, va, pa, fsz, msz = struct.unpack_from("<IIIIII", be, phoff + i * 0x20)
        if t == 1 and va == VRAM:
            payload = be[off:off + fsz]
            break
    if payload is None:
        print("build: no loadable segment in linked output")
        return 1
    if c.get("retail_elf"):
        payload, n_linked, n_matched = overlay_c(payload, c)
        print(f"C linked into image: {n_linked}/{n_matched} matched functions "
              f"(rest use the asm baseline)")
    img_ok = payload == img
    print(f"loadable image sha1: {hashlib.sha1(payload).hexdigest()}  "
          f"{'OK' if img_ok else 'MISMATCH'}")
    out = BUILD / "SLUS_216.21"
    if not c.get("retail_elf"):
        print("build: retail_elf not set; skipping whole-file assembly")
        return 0 if img_ok else 1
    retail = Path(c["retail_elf"]).read_bytes()
    # find the retail loadable segment's file offset (don't assume 0x80)
    rphoff = struct.unpack_from("<I", retail, 0x1c)[0]
    roff = None
    for i in range(struct.unpack_from("<H", retail, 0x2c)[0]):
        t, off, va, pa, fsz, msz = struct.unpack_from("<IIIIII", retail, rphoff + i * 0x20)
        if t == 1 and va == VRAM:
            roff = off
            break
    if roff is None:
        print("build: no loadable segment in retail ELF")
        return 1
    # replace only the loadable payload region; keep the exact ELF wrapper
    final = retail[:roff] + payload + retail[roff + len(payload):]
    out.write_bytes(final)
    got = hashlib.sha1(final).hexdigest()
    whole_ok = got == RETAIL_SHA1
    print(f"SLUS_216.21 sha1:    {got}  {'OK' if whole_ok else 'MISMATCH'}")
    return 0 if (img_ok and whole_ok) else 1


def main():
    c = cfg()
    BUILD.mkdir(exist_ok=True)
    ASM.mkdir(exist_ok=True)
    if "--setup-only" in sys.argv:
        if not c.get("retail_elf"):
            sys.exit("build: set retail_elf in tools/verify_config.local.json or P3_RETAIL_ELF")
        extract_image(c)
        print("wrote image.bin")
        return
    if not IMAGE.is_file():
        if not c.get("retail_elf"):
            sys.exit("build: image.bin missing; set retail_elf and run `make setup`")
        extract_image(c)
    for name, kind, lo, hi in SEGMENTS:
        if kind == "code" and not (ASM / f"{name}.s").is_file():
            sys.exit(f"build: {name}.s missing; run `make split` (python -m splat "
                     "split config/slus21621.yaml) first")
    # data objects are assembled from asm/ so the incbin relative path resolves
    for name, kind, lo, hi in SEGMENTS:
        if kind == "code":
            build_code(c, name, lo, hi)
        else:
            cwd = os.getcwd()
            os.chdir(ASM)
            try:
                build_data(c, name, lo, hi)
            finally:
                os.chdir(cwd)
    write_lcf()
    link(c)
    sys.exit(build_matching_elf(c))


if __name__ == "__main__":
    main()
