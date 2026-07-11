#!/usr/bin/env python3
"""Persona 3 FES matching build driver (standard object-linked model).

Pipeline:
  retail ELF --extract--> image.bin (loadable PT_LOAD payload, vram 0x100000)
  decompiled TUs:  src/*.c --mwccgap(mwccps2 + GNU as r5900)--> C objects
  everything else: splat GAS, carved around the C-owned ranges,
                   --mipsel-linux-gnu-as(r5900)--> asm objects
  data ranges:     .incbin from image.bin --mipsel-linux-gnu-as--> data objects
  all objects   --mwldps2 + generated build/slus21621.lcf--> loadable image
  verify:          linked PT_LOAD payload sha1 == retail loadable image

The linker command file defines `_gp` and the recovered data-symbol addresses
(config/symbols_recovered.txt, plus splat's undefined_*_auto.txt) so mwldps2 can
resolve the C objects' relocations to the retail values.  Eligible C TUs are
selected automatically: every marked function must match, the object must own no
data sections yet, and every external symbol it references must be resolvable.

Config: config/slus21621.yaml; toolchain via tools/verify_config*.json or
P3_MWCC / P3_RETAIL_ELF.  GNU binutils on PATH or through WSL Debian.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
BUILD = REPO / "build"
ASM = REPO / "asm"
OBJ = BUILD / "obj"
IMAGE = REPO / "image.bin"
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402
import asm as A  # noqa: E402

IMAGE_SHA1 = "9203646d9aa48ff24eb4ba4b328b02df468a9483"
IMAGE_SIZE = 0x8ACC80
VRAM = 0x100000
RETAIL_SHA1 = "3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb"

# (name, kind, file-offset lo, file-offset hi); code regions get carved for C.
SEGMENTS = [
    ("code1", "code", 0x000000, 0x4A2000),
    ("data1", "data", 0x4A2000, 0x67F710),
    ("code2", "code", 0x67F710, 0x681000),
    ("data2", "data", 0x681000, 0x8ACC80),
]
BYTES_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]{8}")


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
    c["ld_exe"] = str(Path(c["mwcc"]).with_name("mwldps2.exe"))
    return c


def sh(cmd, **kw):
    p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, **kw)
    if p.returncode:
        sys.stderr.write(p.stdout)
        sys.exit(f"build: command failed: {cmd[0]}")
    return p.stdout


def extract_image(c):
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


def progbitsify(path, names=(".sbss", ".bss")):
    """Convert a compiled object's NOBITS data sections (.sbss/.bss) to PROGBITS
    backed by real zero bytes. Retail keeps these small-bss regions inside the
    loadable image as zeros, so linking them as zero-filled PROGBITS reproduces
    the bytes and keeps file-offset == vaddr through the linked image (mwldps2
    will not advance the file offset across a NOBITS section placed mid-image)."""
    d = bytearray(path.read_bytes())
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shx = struct.unpack_from("<HHH", d, 0x2e)
    sto = struct.unpack_from("<IIIIII", d, shoff + shx * she)[4]

    def nm(n):
        e = d.find(b"\0", sto + n)
        return d[sto + n:e].decode()
    for i in range(shn):
        o = shoff + i * she
        name_off, s_type = struct.unpack_from("<II", d, o)
        size = struct.unpack_from("<I", d, o + 0x14)[0]
        if s_type == 8 and size and nm(name_off) in names:  # SHT_NOBITS
            zoff = len(d)
            d += b"\x00" * size
            struct.pack_into("<I", d, o + 0x04, 1)      # sh_type -> PROGBITS
            struct.pack_into("<I", d, o + 0x10, zoff)   # sh_offset -> the zeros
    path.write_bytes(d)


# ---------------------------------------------------------------- symbol table

def load_lcf_symbols():
    """Symbols the linker must DEFINE: _gp, recovered data symbols, and splat's
    auto undefined lists. Recovered *function* symbols are defined by the asm
    objects, so they are intentionally excluded here to avoid duplicates."""
    gp = None
    defs = {}  # name -> addr
    rec = REPO / "config" / "symbols_recovered.txt"
    if rec.is_file():
        for line in rec.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+).*?type:(\w+)", line)
            if not m:
                continue
            name, addr, kind = m.group(1), int(m.group(2), 16), m.group(3)
            if kind == "gp":
                gp = addr
            elif kind == "data":
                defs[name] = addr
    for fname in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        p = REPO / fname
        if not p.is_file():
            continue
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)", line)
            if m and m.group(1) not in defs:
                defs[m.group(1)] = int(m.group(2), 0)
    return gp, defs


def load_symbol_names():
    names = set()
    p = REPO / "config" / "symbol_addrs.txt"
    if p.is_file():
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=", line)
            if m:
                names.add(m.group(1))
    return names


def load_symbol_addr_map():
    """name -> address for every entry in config/symbol_addrs.txt."""
    out = {}
    p = REPO / "config" / "symbol_addrs.txt"
    if p.is_file():
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0[xX][0-9A-Fa-f]+|\d+)\s*;", line)
            if m:
                out[m.group(1)] = int(m.group(2), 0)
    return out


def c_object_exports(obj_path):
    """Global defined symbol names exported by a compiled C object."""
    obj = V.ObjectFile(obj_path)
    return {s["name"] for s in obj.symbols
            if s["name"] and s.get("shndx", 0) != 0}


def load_windows():
    p = REPO / "tools" / "slus21621_functions.json"
    return sorted(int(k, 16) for k in json.loads(p.read_text())["windows"])


# ---------------------------------------------------------------- C-object choice

DATA_SECTIONS = (".rodata", ".data", ".sdata", ".sbss", ".bss")


def _is_owned_data_section(section):
    """True for compiler-owned allocatable bytes (not executable text)."""
    return (
        section.get("type") in (1, 8)  # SHT_PROGBITS / SHT_NOBITS
        and section.get("size", 0)
        and section.get("flags", 0) & 0x2  # SHF_ALLOC
        and not section.get("flags", 0) & 0x4  # SHF_EXECINSTR
    )


def _s16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


def _s32(x):
    x &= 0xFFFFFFFF
    return x - 0x100000000 if x & 0x80000000 else x


def section_reloc_records(obj, target_idx):
    """Relocations targeting a section, including their symbol records."""
    out = []
    for s in obj.sh:
        if s["type"] != 9 or s["info"] != target_idx:  # SHT_REL
            continue
        syms = obj.symtabs[s["link"]]
        ent = s["entsize"] or 8
        for j in range(s["size"] // ent):
            ro, ri = struct.unpack_from("<II", obj.data, s["offset"] + j * ent)
            symidx = ri >> 8
            sym = syms[symidx] if symidx < len(syms) else {}
            out.append(dict(offset=ro, r_type=ri & 0xFF, symbol=sym.get("name"),
                            symbol_record=sym))
    return out


def section_relocs(obj, target_idx):
    """(offset, r_type, symbol_name) for relocations targeting a section."""
    return [(r["offset"], r["r_type"], r["symbol"])
            for r in section_reloc_records(obj, target_idx)]


def recover_text_section_bases(obj, real):
    """Recover linked addresses for executable sections from matched functions."""
    import collections
    votes = collections.defaultdict(set)
    sections = {
        s["idx"]: s for s in obj.sh
        if s.get("type") == 1 and s.get("flags", 0) & 0x4
    }
    for marker in real:
        candidates = [
            sym for sym in obj.symbols
            if sym["name"] == marker["name"]
            and sym.get("size")
            and sym.get("shndx") in sections
        ]
        for sym in candidates:
            votes[sym["shndx"]].add(marker["addr"] - sym["value"])
    bases = {
        idx: next(iter(values))
        for idx, values in votes.items() if len(values) == 1
    }
    # Linkers concatenate same-name sections with alignment.  Fill in
    # unreferenced text sections from a section whose base was recovered.
    by_name = collections.defaultdict(list)
    for section in sections.values():
        by_name[section.get("name", "")].append(section)
    for secs in by_name.values():
        secs.sort(key=lambda s: s["idx"])
        offsets = []
        off = 0
        for section in secs:
            align = section.get("addralign", 1) or 1
            off = (off + align - 1) & ~(align - 1)
            offsets.append(off)
            off += section["size"]
        group_bases = {
            bases[section["idx"]] - offset
            for section, offset in zip(secs, offsets)
            if section["idx"] in bases
        }
        if len(group_bases) == 1:
            base = next(iter(group_bases))
            for section, offset in zip(secs, offsets):
                bases.setdefault(section["idx"], base + offset)
    return bases


def _resolvable_info(resolvable):
    """Return (known names, known absolute addresses) for reloc validation."""
    names = set(resolvable)
    addresses = {
        name: value for name, value in resolvable.items()
        if isinstance(value, int)
    } if hasattr(resolvable, "items") else {}
    if not addresses:
        addresses.update(load_symbol_addr_map())
    for path in (REPO / "config" / "symbols_recovered.txt",
                 REPO / "undefined_syms_auto.txt",
                 REPO / "undefined_funcs_auto.txt"):
        if not path.is_file():
            continue
        for line in path.read_text().splitlines():
            match = re.match(
                r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)", line
            )
            if match and match.group(1) in names:
                addresses.setdefault(match.group(1), int(match.group(2), 0))
    return names, addresses


def _placed_symbol_addresses(obj, placements, external):
    """Map object symbols to their addresses after section placement."""
    addresses = {}
    for symbol in obj.symbols:
        name = symbol.get("name")
        if not name:
            continue
        shndx = symbol.get("shndx", 0)
        if shndx in placements:
            addresses.setdefault(name, placements[shndx] + symbol["value"])
        elif shndx == 0xFFF1:  # SHN_ABS
            addresses.setdefault(name, symbol["value"])
        elif shndx == 0 and name in external:
            addresses.setdefault(name, external[name])
    return addresses


def _relocated_section_bytes(obj, section, linked_addr, retail, placements, gp,
                             external):
    """Apply a section's SHT_REL records as mwldps2 will, then return its bytes."""
    if section["type"] == 8:  # SHT_NOBITS
        return bytes(section["size"])
    start = section["offset"]
    linked = bytearray(obj.data[start:start + section["size"]])
    records = section_reloc_records(obj, section["idx"])
    if not records:
        return bytes(linked)
    symbols = _placed_symbol_addresses(obj, placements, external)
    for record in records:
        if record["symbol"] not in symbols:
            return None
    endian = getattr(obj, "endian", "<")

    def u16(offset):
        return struct.unpack_from(endian + "H", linked, offset)[0]

    def u32(offset):
        return struct.unpack_from(endian + "I", linked, offset)[0]

    def put16(offset, value):
        struct.pack_into(endian + "H", linked, offset, value & 0xFFFF)

    def put32(offset, value):
        struct.pack_into(endian + "I", linked, offset, value & 0xFFFFFFFF)

    for record in records:
        offset, rtype = record["offset"], record["r_type"]
        target = symbols[record["symbol"]]
        if rtype == 2:  # R_MIPS_32: table entries and pointers
            put32(offset, target + u32(offset))
        elif rtype == 4:  # R_MIPS_26
            word = u32(offset)
            addend = (word & 0x03FFFFFF) << 2
            put32(offset, (word & 0xFC000000) | ((target + addend) >> 2))
        elif rtype == 5:  # R_MIPS_HI16 (pair with its following LO16)
            word = u32(offset)
            lo = next((
                other for other in records
                if other["offset"] > offset and other["r_type"] == 6
                and other["symbol"] == record["symbol"]
            ), None)
            addend = (word & 0xFFFF) << 16
            if lo is not None:
                addend += _s16(u16(lo["offset"]))
            put32(offset, (word & 0xFFFF0000)
                   | ((target + addend + 0x8000) >> 16))
        elif rtype == 6:  # R_MIPS_LO16
            put32(offset, (u32(offset) & 0xFFFF0000)
                   | (target + _s16(u16(offset))) & 0xFFFF)
        elif rtype in (7, 8):  # GPREL16 / LITERAL
            put16(offset, target + _s16(u16(offset)) - gp)
        elif rtype == 12:  # R_MIPS_GPREL32
            put32(offset, target + _s32(u32(offset)) - gp)
        elif rtype == 1:  # R_MIPS_16
            put16(offset, target + _s16(u16(offset)))
        elif rtype == 3:  # R_MIPS_REL32
            put32(offset, target + _s32(u32(offset)) - (linked_addr + offset))
        else:
            # Unknown data relocations are not safe to mask: reject the TU.
            return None
    return bytes(linked)
def _find_retail_data_bases(obj, section, retail, placements, gp, external):
    """Find unique retail placement for a section whose address is unreferenced."""
    if section["type"] == 8 or not hasattr(retail, "segs"):
        return []
    if any(r["r_type"] == 3 for r in section_reloc_records(obj, section["idx"])):
        return []  # R_MIPS_REL32 depends on the candidate address itself.
    expected = _relocated_section_bytes(
        obj, section, 0, retail, placements, gp, external
    )
    if expected is None:
        return []
    align = section.get("addralign", 1) or 1
    candidates = []
    for vaddr, offset, filesz in retail.segs:
        blob = retail.data[offset:offset + filesz]
        pos = blob.find(expected)
        while pos >= 0:
            address = vaddr + pos
            if address % align == 0:
                candidates.append(address)
            pos = blob.find(expected, pos + 1)
    return candidates


def _section_relocates_at(obj, section, address, retail, placements, gp, external):
    """Apply and compare one data section after all targets are placed."""
    linked = _relocated_section_bytes(
        obj, section, address, retail, placements, gp, external
    )
    return linked is not None and linked == retail.bytes_at(address, section["size"])


def recover_section_bases(obj, real, retail, gp):
    """shndx -> recovered base address (from matched functions' relocs to the
    object's own data symbols). Only sections with a single consistent vote."""
    import collections
    sym = {}
    for symbol in obj.symbols:
        if symbol["name"]:
            sym.setdefault(symbol["name"], (symbol.get("shndx", 0), symbol["value"]))
    alloc_data = {
        s["idx"] for s in obj.sh if _is_owned_data_section(s)
    }
    votes = collections.defaultdict(collections.Counter)
    for m in real:
        try:
            body, rels = obj.function(m["name"])
        except KeyError:
            continue
        win = retail.bytes_at(m["addr"], len(body))
        pend = collections.defaultdict(list)
        for r in rels:
            off, t, nm = r["offset"], r["r_type"], r["symbol"]
            if not nm or nm not in sym or off + 4 > len(win):
                continue
            shndx, stval = sym[nm]
            if shndx == 0 or shndx not in alloc_data:
                continue
            wc, wr = struct.unpack_from("<I", body, off)[0], struct.unpack_from("<I", win, off)[0]
            if t == 4:
                a = (((wr & 0x03FFFFFF) << 2) | ((m["addr"] + off) & 0xF0000000)) - ((wc & 0x03FFFFFF) << 2)
                votes[shndx][a - stval] += 1
            elif t == 5:
                pend[nm].append((wc, wr))
            elif t == 6:
                for hc, hr in pend[nm]:
                    a = (((hr & 0xFFFF) << 16) + _s16(wr)) - (((hc & 0xFFFF) << 16) + _s16(wc))
                    votes[shndx][a - stval] += 1
                pend[nm] = []
            elif t == 7:
                votes[shndx][gp + (_s16(wr) - _s16(wc))] += 1
    return {idx: c.most_common(1)[0][0] for idx, c in votes.items() if len(c) == 1}


def plan_data_sections(obj, real, retail, gp, resolvable, resolvable_addrs=None):
    """Place every compiler-owned allocatable data section byte-exactly.

    Relocations are applied using the recovered section placements before
    comparing with retail.  This deliberately checks relocation addends (for
    example, a switch-table entry targeting an internal text label) instead of
    inheriting the function-level relocation mask.
    """
    import collections
    _names, external = _resolvable_info(resolvable)
    if resolvable_addrs:
        external.update(resolvable_addrs)
    bases = recover_section_bases(obj, real, retail, gp)
    by_name = collections.defaultdict(list)
    for section in obj.sh:
        if _is_owned_data_section(section):
            by_name[section.get("name", "")].append(section)
    per_name = {}
    placements = recover_text_section_bases(obj, real)
    for name, secs in by_name.items():
        secs.sort(key=lambda s: s["idx"])  # mwld concatenates same-name sections in shndx order
        base = bases.get(secs[0]["idx"])
        offsets = []
        if base is not None:
            cursor = base
            for section in secs:
                align = section.get("addralign", 1) or 1
                cursor = (cursor + align - 1) & ~(align - 1)
                offsets.append(cursor - base)
                cursor += section["size"]
            total = cursor - base
        else:
            off = 0
            for section in secs:
                align = section.get("addralign", 1) or 1
                off = (off + align - 1) & ~(align - 1)
                offsets.append(off)
                off += section["size"]
            total = off
            for section, offset in zip(secs, offsets):
                if section["idx"] in bases:
                    base = bases[section["idx"]] - offset
                    break
            if base is None:
                candidates = []
                for section, offset in zip(secs, offsets):
                    found = _find_retail_data_bases(
                        obj, section, retail, placements, gp, external
                    )
                    if len(found) == 1:
                        candidates.append(found[0] - offset)
                if len(set(candidates)) != 1:
                    return False, {}
                base = candidates[0]
        for section, offset in zip(secs, offsets):
            addr = base + offset
            if section["idx"] in bases and bases[section["idx"]] != addr:
                return False, {}
            placements[section["idx"]] = addr
        per_name[name] = (base, total)

    for name, secs in by_name.items():
        for section in secs:
            addr = placements[section["idx"]]
            if not _section_relocates_at(
                obj, section, addr, retail, placements, gp, external
            ):
                return False, {}
    return True, per_name


def eligible_c_objects(c, resolvable, boundaries, gp):
    """Select decompiled TUs to link as real C objects: all markers match,
    contiguous function range, every external ref resolvable, and every owned
    data section placeable byte-exact. Returns dicts with .text range + data
    section placements, sorted by function start address."""
    import bisect
    retail = V.RetailElf(c["retail_elf"])
    out = []
    for cpath in sorted((REPO / "src").rglob("*.c")):
        markers = V.scan_markers(cpath)
        real = [m for m in markers if m["name"]]
        if not real or any(m["stub"] or m["nonmatching"] for m in real):
            continue
        obj, _ = V.compile_object(cpath, c)
        if obj is None:
            continue
        symtab = {s["name"]: s.get("shndx", 0) for s in obj.symbols}
        ok = True
        addrs = []
        for m in real:
            try:
                body, rels = obj.function(m["name"])
            except KeyError:
                ok = False
                break
            i = bisect.bisect_right(boundaries, m["addr"])
            win = boundaries[i] - m["addr"] if i < len(boundaries) else None
            if not win or win > 0x10000:
                ok = False
                break
            wb = retail.bytes_at(m["addr"], win)
            if V.compare(body, rels, wb[:len(body)])[0] != 0 or len(body) > win or any(wb[len(body):]):
                ok = False
                break
            for r in rels:
                nm = r["symbol"]
                if nm and symtab.get(nm, 0) == 0 and nm not in resolvable:
                    ok = False
                    break
            if not ok:
                break
            addrs.append((m["addr"], win))
        if not ok or not addrs:
            continue
        addrs.sort()
        if not all(addrs[k][0] + addrs[k][1] == addrs[k + 1][0] for k in range(len(addrs) - 1)):
            continue
        data_ok, sections = plan_data_sections(obj, real, retail, gp, resolvable)
        if not data_ok:
            continue
        out.append(dict(src=cpath, start=addrs[0][0], end=addrs[-1][0] + addrs[-1][1],
                        funcs=real, sections=sections))
    out.sort(key=lambda d: d["start"])
    return out


# ---------------------------------------------------------------- asm carving

def split_blocks(text):
    """Split a splat asm file into (preamble, [(addr, lines)]). A block begins
    at a `nonmatching`/`glabel` line; its address is the first byte comment."""
    lines = text.splitlines(keepends=True)
    i = 0
    while i < len(lines) and not re.match(r"\s*(nonmatching|glabel)\b", lines[i]):
        i += 1
    preamble = lines[:i]
    blocks = []
    cur = []
    for ln in lines[i:]:
        if re.match(r"\s*nonmatching\b", ln) and cur:
            blocks.append(cur)
            cur = []
        cur.append(ln)
    if cur:
        blocks.append(cur)
    parsed = []
    for blk in blocks:
        addr = None
        for ln in blk:
            m = BYTES_RE.search(ln)
            if m:
                addr = int(m.group(1), 16)
                break
        parsed.append((addr, blk))
    return preamble, parsed


def build_code_carved(c, name, lo, hi, cobjs, entries):
    """Assemble the splat asm for a code region, split into chunk objects around
    the C-owned ranges, and register each chunk + C object as a link entry."""
    src = ASM / f"{name}.s"
    preamble, blocks = split_blocks(src.read_text())
    seg_lo, seg_hi = VRAM + lo, VRAM + hi
    ranges = [(o["start"], o["end"], o) for o in cobjs if seg_lo <= o["start"] < seg_hi]
    ranges.sort()
    starts = [r[0] for r in ranges]
    import bisect
    chunks = {}  # chunk index -> list of block lines (order preserved)
    cur_idx = None
    for addr, blk in blocks:
        if addr is None:
            # carry address-less fragment forward with the current chunk
            tgt = cur_idx if cur_idx is not None else 0
            chunks.setdefault(tgt, []).extend(blk)
            continue
        if any(s <= addr < e for s, e, _ in ranges):
            continue  # carved: provided by a C object
        idx = bisect.bisect_right(starts, addr)
        cur_idx = idx
        chunks.setdefault(idx, []).extend(blk)
    # emit + assemble each chunk, compute its start address
    chunk_dir = ASM / "chunks"
    chunk_dir.mkdir(parents=True, exist_ok=True)
    for idx, body in sorted(chunks.items()):
        first = None
        for ln in body:
            m = BYTES_RE.search(ln)
            if m:
                first = int(m.group(1), 16)
                break
        if first is None:
            continue
        cpath = chunk_dir / f"{name}_{idx}.s"
        cpath.write_text("".join(preamble) + "".join(body))
        obj = OBJ / f"{name}_{idx}.o"
        ok, log, lines = A.assemble(cpath, obj, AS_TOOL, OBJCOPY_TOOL,
                                    ref=IMAGE.read_bytes(), vram=first, ref_lo=first - VRAM,
                                    keep_text=True)
        cpath.write_text("".join(lines))
        if not ok:
            sys.stderr.write(log + "\n")
            sys.exit(f"build: failed to assemble {cpath.name}")
        patch_align1(obj, ".text")
        entries.append((first, obj, ".text"))


def build_code_plain(c, name, lo, hi, entries):
    src = ASM / f"{name}.s"
    obj = OBJ / f"{name}.o"
    ok, log, lines = A.assemble(src, obj, AS_TOOL, OBJCOPY_TOOL,
                                ref=IMAGE.read_bytes(), vram=VRAM + lo, ref_lo=lo, keep_text=True)
    src.write_text("".join(lines))
    if not ok:
        sys.stderr.write(log + "\n")
        sys.exit(f"build: failed to assemble {name}")
    patch_align1(obj, ".text")
    entries.append((VRAM + lo, obj, ".text"))


def build_data_carved(name, lo, hi, data_carves, entries):
    """Emit the data blob as .incbin pieces around the C-owned data ranges."""
    seg_lo, seg_hi = VRAM + lo, VRAM + hi
    carves = sorted((s, e) for s, e in data_carves if seg_lo <= s < seg_hi)
    pieces = []
    cur = lo
    for s, e in carves:
        s_off, e_off = s - VRAM, e - VRAM
        if s_off > cur:
            pieces.append((cur, s_off))
        cur = max(cur, e_off)
    if cur < hi:
        pieces.append((cur, hi))
    chunk_dir = ASM / "chunks"
    chunk_dir.mkdir(parents=True, exist_ok=True)
    for i, (a, b) in enumerate(pieces):
        src = chunk_dir / f"{name}_{i}.s"
        obj = OBJ / f"{name}_{i}.o"
        src.write_text(f'.section .{name}, "aw"\n.incbin "../image.bin", {hex(a)}, {hex(b - a)}\n')
        ok, log, _ = A.assemble(src, obj, AS_TOOL, OBJCOPY_TOOL, keep_text=False)
        if not ok:
            sys.stderr.write(log + "\n")
            sys.exit(f"build: failed to assemble {name}_{i}")
        patch_align1(obj, f".{name}")
        entries.append((VRAM + a, obj, f".{name}"))


def compile_c(c, src, obj):
    obj.parent.mkdir(parents=True, exist_ok=True)
    mwccgap = REPO / "tools" / "mwccgap" / "mwccgap.py"
    sh([sys.executable, str(mwccgap), str(src), str(obj),
        "--mwcc-path", c["mwcc"], "--macro-inc-path", str(ASM / "macro.inc"),
        "--as-march", "r5900", "--as-mabi", "eabi", "-O2", "-Iinclude"],
       cwd=str(REPO))
    progbitsify(obj)


# ---------------------------------------------------------------- link

def write_lcf(entries, gp, defs):
    body = []
    if gp is not None:
        body.append(f"    _gp = {gp:#010x};")
    for nm, addr in sorted(defs.items(), key=lambda kv: kv[1]):
        body.append(f"    {nm} = {addr:#010x};")
    placed = []
    for start, obj, sec in sorted(entries, key=lambda e: e[0]):
        if sec == ".text":
            placed.append("        . = ALIGN(0x10);")
        placed.append(f"        {obj.name} ({sec})")
    lcf = (
        "MEMORY {\n"
        f"    image : ORIGIN = {VRAM:#x}, LENGTH = {IMAGE_SIZE:#x}\n"
        "}\n"
        "SECTIONS {\n"
        + "\n".join(body) + "\n"
        "    .image : {\n" + "\n".join(placed) + "\n    } > image\n"
        "}\n"
    )
    (BUILD / "slus21621.lcf").write_text(lcf)


def link(c, entries):
    objs, seen = [], set()
    for _a, obj, _s in sorted(entries, key=lambda e: e[0]):
        if str(obj) not in seen:
            seen.add(str(obj))
            objs.append(str(obj))
    args = [c["ld_exe"], "-nostdlib", "-nodeadstrip", "-m", "func_00100008",
            "-o", str(BUILD / "slus21621.elf"), str(BUILD / "slus21621.lcf"), *objs]
    response = BUILD / "slus21621.rsp"
    response.write_text(subprocess.list2cmdline(args[1:]), encoding="utf-8")
    sh([args[0], f"@{response}"])



def linked_function_records(cobjs, windows):
    """Return unique C-owned functions at authoritative window starts.

    ``scan_markers`` normally provides integer addresses, but progress-verifier
    rows encode them as hexadecimal strings. Normalize either representation
    before comparing against the integer window map loaded for this build.
    """
    authoritative_addresses = set(windows)
    by_address = {}
    for obj in cobjs:
        source = obj["src"].relative_to(REPO).as_posix()
        for func in obj["funcs"]:
            marker_address = func["addr"]
            try:
                address = (int(marker_address, 16)
                           if isinstance(marker_address, str) else int(marker_address))
            except (TypeError, ValueError):
                sys.exit(
                    f"build: invalid marker address {marker_address!r} "
                    f"for {func['name']} in {source}"
                )
            if address not in authoritative_addresses:
                sys.exit(
                    f"build: marker address {address:#010x} for {func['name']} "
                    f"in {source} is not an authoritative function window"
                )
            record = (func["name"], source)
            previous = by_address.get(address)
            if previous is not None and previous != record:
                sys.exit(
                    f"build: conflicting markers at {address:#010x}: "
                    f"{previous[0]} in {previous[1]} vs {record[0]} in {record[1]}"
                )
            by_address[address] = record
    return [
        {"address": f"{address:08x}", "name": name, "file": source}
        for address, (name, source) in sorted(by_address.items())
    ]


def write_progress_report(path, image_sha1, retail_sha1, function_total, cobjs, linked_functions):
    """Atomically publish successful real-C linkage information."""
    import tempfile

    path = Path(path)
    report = {
        "schema_version": 1,
        "build_succeeded": True,
        "image_sha1": image_sha1,
        "retail_sha1": retail_sha1,
        "function_total": function_total,
        "linked_tu_count": len(cobjs),
        "linked_function_count": len(linked_functions),
        "linked_functions": linked_functions,
    }
    path.parent.mkdir(parents=True, exist_ok=True)
    temp_path = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w", encoding="utf-8", dir=path.parent,
            prefix=f".{path.name}.", suffix=".tmp", delete=False,
        ) as temp:
            temp_path = Path(temp.name)
            json.dump(report, temp, indent=2, sort_keys=True)
            temp.write("\n")
        os.replace(temp_path, path)
    except Exception:
        if temp_path is not None:
            temp_path.unlink(missing_ok=True)
        raise

def build_matching_elf(c, n_cobj):
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
    print(f"C objects linked from source: {n_cobj}")
    image_sha1 = hashlib.sha1(payload).hexdigest()
    img_ok = payload == img
    print(f"loadable image sha1: {image_sha1}  {'OK' if img_ok else 'MISMATCH'}")
    if not img_ok:
        # report first divergence to aid debugging
        for i in range(min(len(payload), len(img))):
            if payload[i] != img[i]:
                print(f"  first diff at vram {VRAM + i:#x} (payload {payload[i:i+4].hex()} "
                      f"vs retail {img[i:i+4].hex()})")
                break
    retail = Path(c["retail_elf"]).read_bytes()
    rphoff = struct.unpack_from("<I", retail, 0x1c)[0]
    roff = None
    for i in range(struct.unpack_from("<H", retail, 0x2c)[0]):
        t, off, va, pa, fsz, msz = struct.unpack_from("<IIIIII", retail, rphoff + i * 0x20)
        if t == 1 and va == VRAM:
            roff = off
            break
    final = retail[:roff] + payload + retail[roff + len(payload):]
    (BUILD / "SLUS_216.21").write_bytes(final)
    got = hashlib.sha1(final).hexdigest()
    whole_ok = got == RETAIL_SHA1
    print(f"SLUS_216.21 sha1:    {got}  {'OK' if whole_ok else 'MISMATCH'}")
    return 0 if (img_ok and whole_ok) else 1


AS_TOOL = None
OBJCOPY_TOOL = None


def main():
    global AS_TOOL, OBJCOPY_TOOL
    parser = argparse.ArgumentParser()
    parser.add_argument("--progress-report", type=Path, metavar="PATH")
    parser.add_argument("--setup-only", action="store_true")
    args, _unknown = parser.parse_known_args()
    c = cfg()
    BUILD.mkdir(exist_ok=True)
    OBJ.mkdir(parents=True, exist_ok=True)
    ASM.mkdir(exist_ok=True)
    if args.setup_only:
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
            sys.exit(f"build: {name}.s missing; run `make split` first")

    AS_TOOL = A.find_gnu_tool("mipsel-linux-gnu-as", "P3_AS")
    OBJCOPY_TOOL = A.find_gnu_tool("mipsel-linux-gnu-objcopy", "P3_OBJCOPY")

    gp, defs = load_lcf_symbols()
    resolvable = set(defs) | load_symbol_names()
    boundaries = load_windows()
    cobjs = eligible_c_objects(c, resolvable, boundaries, gp) if c.get("retail_elf") else []
    print(f"eligible C objects: {len(cobjs)}  "
          f"({', '.join(o['src'].name for o in cobjs) if cobjs else 'none'})")
    linked_functions = linked_function_records(cobjs, boundaries)

    entries = []
    # Compile each decompiled TU once; place its .text and every owned data
    # section, and record the retail ranges to carve out of the baseline.
    c_text_ranges = []
    data_carves = []
    for o in cobjs:
        cobj = OBJ / (o["src"].relative_to(REPO / "src").as_posix().replace("/", "_") + ".o")
        compile_c(c, o["src"], cobj)
        o["obj"] = cobj
        entries.append((o["start"], cobj, ".text"))
        c_text_ranges.append((o["start"], o["end"], o))
        for sname, (base, size) in o["sections"].items():
            entries.append((base, cobj, sname))
            data_carves.append((base, base + size))

    # Splat asm references carved functions by their symbol_addrs names; when a
    # C object exports a canonical name instead, define the splat name as an
    # absolute address (the C object is placed byte-exact at retail).
    if c_text_ranges:
        exported = set()
        for o in cobjs:
            exported |= c_object_exports(o["obj"])
        for nm, addr in load_symbol_addr_map().items():
            if nm in exported or nm in defs:
                continue
            if any(s <= addr < e for s, e, _o in c_text_ranges):
                defs[nm] = addr

    for name, kind, lo, hi in SEGMENTS:
        if kind == "code":
            if any(VRAM + lo <= s < VRAM + hi for s, _e, _o in c_text_ranges):
                build_code_carved(c, name, lo, hi, cobjs, entries)
            else:
                build_code_plain(c, name, lo, hi, entries)
        else:
            build_data_carved(name, lo, hi, data_carves, entries)
    write_lcf(entries, gp, defs)
    link(c, entries)
    status = build_matching_elf(c, len(cobjs))
    if status == 0 and args.progress_report is not None:
        write_progress_report(
            args.progress_report,
            hashlib.sha1(IMAGE.read_bytes()).hexdigest(),
            hashlib.sha1((BUILD / "SLUS_216.21").read_bytes()).hexdigest(),
            len(boundaries),
            cobjs,
            linked_functions,
        )
    sys.exit(status)


if __name__ == "__main__":
    main()
