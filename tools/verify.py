#!/usr/bin/env python3
"""Repo-wide match verifier for the Persona 3 FES decompilation.

For every `// FUN_xxxxxxxx` marker in src/**/*.c this tool:
  1. compiles the containing file with the project toolchain (mwccps2 -O2 -Iinclude),
  2. extracts the function's bytes and MIPS relocations from the object,
  3. masks relocated instruction fields,
  4. compares against the retail SLUS_216.21 bytes at the marker address.

Statuses:
  MATCH          normalized diff == 0 and the retail tail up to the next function
                 entry is zero padding (so short/stub bodies cannot false-pass)
  MISMATCH       compiled bytes differ from retail outside relocated fields
  SIZE_MISMATCH  bytes match but object size disagrees with the retail window
  STUB           function body is a `// TODO` placeholder
  NO_SYMBOL      marker present but symbol missing from the object
  COMPILE_ERROR  the containing file failed to compile
  UNKNOWN_ADDR   marker address is not a known Ghidra function entry

Configuration (first hit wins):
  1. environment: P3_MWCC, P3_RETAIL_ELF
  2. tools/verify_config.local.json   (machine-local, gitignored)
  3. tools/verify_config.json         (committed defaults)

Usage:
  python tools/verify.py                  # verify whole repo, print summary
  python tools/verify.py src/rw/rprandom.c [more files...]
  python tools/verify.py --json report.json
  python tools/verify.py --show-mismatches
Exit code is nonzero if any MISMATCH / SIZE_MISMATCH / NO_SYMBOL /
COMPILE_ERROR / UNKNOWN_ADDR is found (stubs are expected and do not fail).
"""

from pathlib import Path
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import tempfile

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"

R_MIPS_NAMES = {
    1: "R_MIPS_16", 2: "R_MIPS_32", 3: "R_MIPS_REL32", 4: "R_MIPS_26",
    5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16",
    8: "R_MIPS_LITERAL", 9: "R_MIPS_GOT16", 10: "R_MIPS_PC16",
    11: "R_MIPS_CALL16", 12: "R_MIPS_GPREL32",
}
# relocation type -> number of masked bytes at the reloc offset
RELOC_MASK_SIZE = {2: 4, 4: 4, 5: 2, 6: 2, 7: 2}


# ---------------------------------------------------------------- config

def load_config():
    cfg = {}
    for name in ("verify_config.json", "verify_config.local.json"):
        p = TOOLS / name
        if p.is_file():
            cfg.update(json.loads(p.read_text()))
    if os.environ.get("P3_MWCC"):
        cfg["mwcc"] = os.environ["P3_MWCC"]
    if os.environ.get("P3_RETAIL_ELF"):
        cfg["retail_elf"] = os.environ["P3_RETAIL_ELF"]
    missing = [k for k in ("mwcc", "retail_elf") if not cfg.get(k)]
    if missing:
        sys.exit(
            "verify: missing config value(s): %s\n"
            "Set P3_MWCC / P3_RETAIL_ELF or create tools/verify_config.local.json, e.g.\n"
            '  {"mwcc": "D:/mwcps2-3.0b52-030722/mwccps2.exe",\n'
            '   "retail_elf": "C:/tmp/p3_discs/fes/SLUS_216.21"}' % ", ".join(missing)
        )
    for k in ("mwcc", "retail_elf"):
        if not Path(cfg[k]).is_file():
            sys.exit(f"verify: {k} does not exist: {cfg[k]}")
    return cfg


# ---------------------------------------------------------------- ELF parsing

def _cstr(buf, off):
    end = buf.find(b"\0", off)
    return buf[off:end if end >= 0 else len(buf)].decode("ascii", "replace")


def elf_sections(data):
    assert data[:4] == b"\x7fELF", "not an ELF"
    endian = "<" if data[5] == 1 else ">"
    eh = struct.unpack_from(endian + "HHIIIIIHHHHHH", data, 16)
    e_shoff, e_shentsize, e_shnum, e_shstrndx = eh[5], eh[10], eh[11], eh[12]
    sh = []
    for i in range(e_shnum):
        f = struct.unpack_from(endian + "IIIIIIIIII", data, e_shoff + i * e_shentsize)
        sh.append(dict(idx=i, name_off=f[0], type=f[1], flags=f[2], addr=f[3],
                       offset=f[4], size=f[5], link=f[6], info=f[7],
                       addralign=f[8], entsize=f[9]))
    if sh:
        shstr = sh[e_shstrndx]
        blob = data[shstr["offset"]:shstr["offset"] + shstr["size"]]
        for s in sh:
            s["name"] = _cstr(blob, s["name_off"]) if s["name_off"] < len(blob) else ""
    return endian, sh


class ObjectFile:
    """Parsed relocatable object: symbol bytes + symbol-relative relocations."""

    def __init__(self, path):
        self.data = Path(path).read_bytes()
        self.endian, self.sh = elf_sections(self.data)
        self.symtabs = {}
        self.symbols = []
        for s in self.sh:
            if s["type"] in (2, 11):  # SYMTAB / DYNSYM
                strsec = self.sh[s["link"]]
                blob = self.data[strsec["offset"]:strsec["offset"] + strsec["size"]]
                ents = s["entsize"] or 16
                syms = []
                for j in range(s["size"] // ents):
                    off = s["offset"] + j * ents
                    st_name, st_value, st_size, st_info, _o, st_shndx = \
                        struct.unpack_from(self.endian + "IIIBBH", self.data, off)
                    syms.append(dict(
                        name=_cstr(blob, st_name) if st_name < len(blob) else "",
                        value=st_value, size=st_size, shndx=st_shndx))
                self.symtabs[s["idx"]] = syms
                self.symbols += syms

    def function(self, name):
        """-> (bytes, relocations) with reloc offsets relative to the symbol."""
        cands = [s for s in self.symbols
                 if s["name"] == name and s["size"] and s["shndx"] not in (0, 0xFFF1)]
        if not cands:
            raise KeyError(name)
        sym = cands[0]
        sec = self.sh[sym["shndx"]]
        body = self.data[sec["offset"] + sym["value"]:
                         sec["offset"] + sym["value"] + sym["size"]]
        rels = []
        for s in self.sh:
            if s["type"] == 9 and s["info"] == sec["idx"]:  # SHT_REL for this section
                syms = self.symtabs[s["link"]]
                ents = s["entsize"] or 8
                for j in range(s["size"] // ents):
                    r_offset, r_info = struct.unpack_from(
                        self.endian + "II", self.data, s["offset"] + j * ents)
                    if sym["value"] <= r_offset < sym["value"] + sym["size"]:
                        rtype = r_info & 0xFF
                        symidx = r_info >> 8
                        rels.append(dict(
                            offset=r_offset - sym["value"],  # symbol-relative
                            r_type=rtype,
                            type=R_MIPS_NAMES.get(rtype, str(rtype)),
                            symbol=syms[symidx]["name"] if symidx < len(syms) else None))
        return body, rels


class RetailElf:
    def __init__(self, path, expect_sha1=None):
        self.data = Path(path).read_bytes()
        if expect_sha1:
            got = hashlib.sha1(self.data).hexdigest()
            if got != expect_sha1:
                sys.exit(f"verify: retail ELF sha1 mismatch: got {got}, expected {expect_sha1}")
        endian = "<" if self.data[5] == 1 else ">"
        eh = struct.unpack_from(endian + "HHIIIIIHHHHHH", self.data, 16)
        e_phoff, e_phentsize, e_phnum = eh[4], eh[8], eh[9]
        self.segs = []
        for i in range(e_phnum):
            p_type, p_offset, p_vaddr, _pa, p_filesz, _ms, _fl, _al = \
                struct.unpack_from(endian + "IIIIIIII", self.data, e_phoff + i * e_phentsize)
            if p_type == 1:
                self.segs.append((p_vaddr, p_offset, p_filesz))

    def bytes_at(self, addr, size):
        for vaddr, offset, filesz in self.segs:
            if vaddr <= addr and addr + size <= vaddr + filesz:
                off = offset + (addr - vaddr)
                return self.data[off:off + size]
        raise ValueError(f"address {addr:#x}+{size:#x} not in any PT_LOAD segment")


# ---------------------------------------------------------------- source scanning

MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))")
# function definition header: return type stuff then `name(`
NAME_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(")


def strip_line_comment(line):
    return line.split("//", 1)[0]


def scan_markers(cpath):
    """-> list of dicts {addr, name, line, stub} for each // FUN_ marker."""
    lines = cpath.read_text(errors="replace").splitlines()
    out = []
    i = 0
    while i < len(lines):
        m = MARKER_RE.match(lines[i])
        if not m:
            i += 1
            continue
        addr = int(m.group(2), 16)
        # find the definition header: accumulate until '{'
        name = None
        j = i + 1
        header = ""
        while j < len(lines) and j < i + 12:
            code = strip_line_comment(lines[j]).strip()
            if code.startswith("#"):  # pragma etc.
                j += 1
                continue
            header += " " + code
            if "{" in header:
                break
            j += 1
        nm = NAME_RE.search(header.split("{", 1)[0])
        if nm:
            name = nm.group(1)
        # stub detection: body up to matching '}' contains only TODO / return
        stub = False
        depth = 0
        body_lines = []
        k = j
        while k < len(lines):
            code = strip_line_comment(lines[k])
            depth += code.count("{") - code.count("}")
            body_lines.append(lines[k])
            if depth <= 0 and "{" in "".join(body_lines):
                break
            k += 1
        body = "\n".join(body_lines)
        if "// TODO" in body or "/* TODO" in body:
            meat = [strip_line_comment(l).strip() for l in body_lines]
            meat = [l for l in meat if l and l not in ("{", "}")
                    and not l.startswith("return")
                    and not re.match(r"^[A-Za-z_].*\)\s*\{?$", l)]
            stub = not meat
        out.append(dict(addr=addr, name=name, line=i + 1, stub=stub))
        i = k + 1 if name else i + 1
    return out


# ---------------------------------------------------------------- comparison

def mask_bytes(n, rels):
    mask = bytearray(n)
    for r in rels:
        size = RELOC_MASK_SIZE.get(r["r_type"], 0)
        for k in range(size):
            if 0 <= r["offset"] + k < n:
                mask[r["offset"] + k] = 1
    return mask


def compare(body, rels, retail_win):
    """-> (normalized_diff_count, first_diff_offsets) over len(body) bytes."""
    n = len(body)
    mask = mask_bytes(n, rels)
    diffs = [i for i in range(n)
             if not mask[i] and (retail_win[i] if i < len(retail_win) else None) != body[i]]
    return len(diffs), diffs[:16]


def decode_reloc_values(rels, retail_win):
    """Attach the retail-encoded immediate for each relocated field (informational)."""
    for r in rels:
        o = r["offset"]
        if o + 4 <= len(retail_win):
            word = struct.unpack_from("<I", retail_win, o & ~3)[0]
            if r["r_type"] == 4:  # R_MIPS_26
                r["retail_target"] = f"{(word & 0x03FFFFFF) << 2:#010x}"
            elif r["r_type"] in (5, 6, 7):  # HI16/LO16/GPREL16
                r["retail_imm"] = f"{word & 0xFFFF:#06x}"
    return rels


# ---------------------------------------------------------------- driver

def window_for(addr, boundaries):
    """Distance from addr to the next known function boundary above it."""
    import bisect
    i = bisect.bisect_right(boundaries, addr)
    if i < len(boundaries):
        return boundaries[i] - addr
    return None


def verify_file(cpath, cfg, retail, boundaries, objdir):
    rel = cpath.relative_to(REPO)
    markers = scan_markers(cpath)
    results = []
    if not markers:
        return results
    opath = objdir / (rel.as_posix().replace("/", "_") + ".o")
    proc = subprocess.run(
        [cfg["mwcc"], "-O2", "-Iinclude", "-c", str(cpath), "-o", str(opath)],
        cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if proc.returncode or not opath.is_file():
        for mk in markers:
            results.append(dict(file=str(rel), **mk, status="COMPILE_ERROR",
                                detail=proc.stdout.strip()[:400]))
        return results
    obj = ObjectFile(opath)
    for mk in markers:
        entry = dict(file=str(rel), addr=f"{mk['addr']:08x}", name=mk["name"], line=mk["line"])
        if mk["stub"]:
            entry["status"] = "STUB"
            results.append(entry)
            continue
        window = window_for(mk["addr"], boundaries)
        if window is None or window > 0x10000:
            entry["status"] = "UNKNOWN_ADDR"
            entry["detail"] = "no plausible function boundary above marker address"
            results.append(entry)
            continue
        if not mk["name"]:
            entry["status"] = "NO_SYMBOL"
            entry["detail"] = "could not parse function name after marker"
            results.append(entry)
            continue
        try:
            body, rels = obj.function(mk["name"])
        except KeyError:
            entry["status"] = "NO_SYMBOL"
            results.append(entry)
            continue
        win_bytes = retail.bytes_at(mk["addr"], window)
        ndiff, first = compare(body, rels, win_bytes)
        tail = win_bytes[len(body):]
        entry["object_size"] = len(body)
        entry["window"] = window
        entry["normalized_diff"] = ndiff
        if ndiff:
            entry["status"] = "MISMATCH"
            entry["first_diffs"] = first
        elif len(body) > window or any(tail):
            entry["status"] = "SIZE_MISMATCH"
            entry["detail"] = (f"object {len(body)}B vs retail window {window}B; "
                               f"tail is not zero padding")
        else:
            entry["status"] = "MATCH"
        entry["relocations"] = decode_reloc_values(rels, win_bytes)
        results.append(entry)
    return results


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("files", nargs="*", help="specific .c files (default: all of src/)")
    ap.add_argument("--json", metavar="PATH", help="write full JSON report")
    ap.add_argument("--show-mismatches", action="store_true",
                    help="print per-function detail for every non-MATCH/non-STUB")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))

    files = ([Path(f).resolve() for f in args.files] if args.files
             else sorted((REPO / "src").rglob("*.c")))

    # Function boundaries: every Ghidra entry plus every marker address in the
    # whole repo (Ghidra misses many small functions; markers fill the gaps).
    bounds = {int(a, 16) for a in sizes["windows"]}
    last = max(bounds)
    last_window = sizes["windows"][f"{last:08x}"]
    if last_window:
        bounds.add(last + last_window)
    for cpath in sorted((REPO / "src").rglob("*.c")):
        for mk in scan_markers(cpath):
            bounds.add(mk["addr"])
    boundaries = sorted(bounds)

    all_results = []
    with tempfile.TemporaryDirectory(prefix="p3verify_") as td:
        for cpath in files:
            all_results += verify_file(cpath, cfg, retail, boundaries, Path(td))

    counts = {}
    for r in all_results:
        counts[r["status"]] = counts.get(r["status"], 0) + 1
    total = len(all_results)
    print(f"functions scanned: {total}")
    for st in ("MATCH", "STUB", "MISMATCH", "SIZE_MISMATCH",
               "NO_SYMBOL", "COMPILE_ERROR", "UNKNOWN_ADDR"):
        if counts.get(st):
            print(f"  {st:<14} {counts[st]}")

    bad = [r for r in all_results if r["status"] not in ("MATCH", "STUB")]
    if args.show_mismatches:
        for r in bad:
            print(f"\n{r['status']}: {r['file']}:{r.get('line','?')} "
                  f"{r.get('name')} @ {r.get('addr')}")
            if r.get("normalized_diff") is not None:
                print(f"  obj {r.get('object_size')}B window {r.get('window')}B "
                      f"normalized_diff {r['normalized_diff']} first {r.get('first_diffs', [])}")
            if r.get("detail"):
                print(f"  {r['detail']}")

    if args.json:
        Path(args.json).write_text(json.dumps(
            dict(summary=counts, results=all_results), indent=1), newline="\n")
        print(f"report: {args.json}")

    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
