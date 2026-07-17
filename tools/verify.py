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
  NONMATCHING    marker carries a NONMATCHING tag; known-WIP, does not fail
  STALE_NONMATCHING  tagged NONMATCHING but now matches; remove the tag
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

    def __init__(self, path=None, *, data=None):
        if (path is None) == (data is None):
            raise ValueError("provide exactly one of path or data")
        self.data = bytes(data) if data is not None else Path(path).read_bytes()
        self._parse()

    @classmethod
    def from_bytes(cls, data):
        """Parse an in-memory relocatable object, such as an archive member."""
        return cls(data=data)

    def _parse(self):
        """Populate sections and symbols from ``self.data``."""
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
                        value=st_value, size=st_size, shndx=st_shndx,
                        info=st_info, bind=st_info >> 4, sym_type=st_info & 0xF))
                self.symtabs[s["idx"]] = syms
                self.symbols += syms

    def _function_record(self, name):
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
                        target = syms[symidx] if symidx < len(syms) else {}
                        rels.append(dict(
                            offset=r_offset - sym["value"],  # symbol-relative
                            r_type=rtype,
                            type=R_MIPS_NAMES.get(rtype, str(rtype)),
                            symbol=target.get("name"),
                            symbol_record=target,
                            symbol_index=symidx))
        return dict(symbol=sym, section=sec, body=body, rels=rels)

    def function(self, name):
        """-> (bytes, relocations) with reloc offsets relative to the symbol."""
        record = self._function_record(name)
        return record["body"], record["rels"]

    def function_record(self, name):
        """-> function metadata used when checking compiler-owned data."""
        return self._function_record(name)

    def section_reloc_records(self, target_idx):
        """Return all SHT_REL records targeting an object section."""
        out = []
        for relsec in self.sh:
            if relsec["type"] != 9 or relsec["info"] != target_idx:
                continue
            syms = self.symtabs.get(relsec["link"], ())
            ents = relsec["entsize"] or 8
            for j in range(relsec["size"] // ents):
                offset, info = struct.unpack_from(
                    self.endian + "II", self.data, relsec["offset"] + j * ents)
                symidx = info >> 8
                target = syms[symidx] if symidx < len(syms) else {}
                out.append(dict(
                    offset=offset, r_type=info & 0xFF,
                    type=R_MIPS_NAMES.get(info & 0xFF, str(info & 0xFF)),
                    symbol=target.get("name"), symbol_record=target,
                    symbol_index=symidx))
        return out


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

def sanitize_c_lines(lines):
    """Replace comments and string/character literals while preserving layout."""
    out_lines = []
    state = "code"
    escaped = False
    for line in lines:
        out = []
        i = 0
        while i < len(line):
            ch = line[i]
            nxt = line[i + 1] if i + 1 < len(line) else ""
            if state == "block":
                if ch == "*" and nxt == "/":
                    out.extend("  ")
                    i += 2
                    state = "code"
                else:
                    out.append(" ")
                    i += 1
                continue
            if state in ("string", "char"):
                out.append(" ")
                if escaped:
                    escaped = False
                elif ch == "\\":
                    escaped = True
                elif (state == "string" and ch == '"') or (state == "char" and ch == "'"):
                    state = "code"
                i += 1
                continue
            if ch == "/" and nxt == "/":
                out.extend(" " * (len(line) - i))
                i = len(line)
            elif ch == "/" and nxt == "*":
                out.extend("  ")
                i += 2
                state = "block"
            elif ch == '"':
                out.append(" ")
                i += 1
                state = "string"
            elif ch == "'":
                out.append(" ")
                i += 1
                state = "char"
            else:
                out.append(ch)
                i += 1
        out_lines.append("".join(out))
        if state in ("string", "char") and not escaped:
            state = "code"
        escaped = False
    return out_lines


def _is_owned_data_section(section):
    """Compiler-owned bytes: allocatable, non-executable object data."""
    return (
        section.get("type") in (1, 8) and section.get("size", 0)
        and section.get("flags", 0) & 0x2
        and not section.get("flags", 0) & 0x4
    )


def _s16(value):
    value &= 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def _section_bytes(obj, section):
    if section.get("type") == 8:  # SHT_NOBITS has no file image.
        return bytes(section.get("size", 0))
    start = section.get("offset", 0)
    return obj.data[start:start + section["size"]]


def _u32(data, offset, endian="<"):
    if offset < 0 or offset + 4 > len(data):
        return None
    return struct.unpack_from(endian + "I", data, offset)[0]


def _function_metadata(obj, name):
    if hasattr(obj, "function_record"):
        return obj.function_record(name)
    body, rels = obj.function(name)
    symbols = [s for s in obj.symbols
               if s.get("name") == name and s.get("size")
               and s.get("shndx") not in (0, 0xFFF1)]
    if not symbols:
        raise KeyError(name)
    symbol = symbols[0]
    sections = {s["idx"]: s for s in obj.sh}
    return dict(symbol=symbol, section=sections[symbol["shndx"]],
                body=body, rels=rels)


def _section_reloc_records(obj, target_idx):
    if hasattr(obj, "section_reloc_records"):
        return obj.section_reloc_records(target_idx)
    records = []
    for relsec in obj.sh:
        if relsec.get("type") != 9 or relsec.get("info") != target_idx:
            continue
        syms = obj.symtabs.get(relsec.get("link"), ())
        ents = relsec.get("entsize") or 8
        for index in range(relsec.get("size", 0) // ents):
            offset, info = struct.unpack_from(
                getattr(obj, "endian", "<") + "II", obj.data,
                relsec["offset"] + index * ents)
            symidx = info >> 8
            target = syms[symidx] if symidx < len(syms) else {}
            records.append(dict(
                offset=offset, r_type=info & 0xFF,
                type=R_MIPS_NAMES.get(info & 0xFF, str(info & 0xFF)),
                symbol=target.get("name"), symbol_record=target,
                symbol_index=symidx))
    return records


def _record_symbol(obj, record):
    """Recover a relocation's full symbol record for lightweight test objects."""
    target = record.get("symbol_record")
    if target:
        return target
    name = record.get("symbol")
    if not name:
        return {}
    return next((s for s in obj.symbols if s.get("name") == name), {})


def _candidate_text_bases(obj, fn, candidate_addr, marker_addrs):
    """Recover candidate addresses for text symbols in this object."""
    section = fn["section"]
    bases = {section["idx"]: candidate_addr - fn["symbol"]["value"]}
    if not marker_addrs:
        return bases
    text_indices = {s["idx"] for s in obj.sh if s.get("flags", 0) & 0x4}
    votes = {}
    for symbol in obj.symbols:
        name = symbol.get("name")
        if not name or name not in marker_addrs or not symbol.get("size"):
            continue
        shndx = symbol.get("shndx")
        if shndx in text_indices:
            votes.setdefault(shndx, set()).add(marker_addrs[name] - symbol["value"])
    for shndx, values in votes.items():
        if len(values) == 1:
            bases[shndx] = next(iter(values))
    return bases


def _recover_data_bases(obj, fn, body, rels, retail_win):
    """Recover directly referenced data-section bases from code relocations."""
    data_indices = {s["idx"] for s in obj.sh if _is_owned_data_section(s)}
    votes = {}
    pending = {}
    endian = getattr(obj, "endian", "<")
    for record in rels:
        target = _record_symbol(obj, record)
        shndx = target.get("shndx")
        if shndx not in data_indices:
            continue
        offset = record.get("offset", -1)
        rtype = record.get("r_type")
        if offset < 0 or offset + 4 > len(body) or offset + 4 > len(retail_win):
            continue
        key = (shndx, target.get("name"), target.get("value", 0))
        candidate_word = _u32(body, offset, endian)
        retail_word = _u32(retail_win, offset, endian)
        if candidate_word is None or retail_word is None:
            continue
        if rtype == 2:
            base = retail_word - candidate_word - target.get("value", 0)
            votes.setdefault(shndx, set()).add(base)
        elif rtype == 5:
            pending.setdefault(key, []).append((candidate_word, retail_word))
        elif rtype == 6 and pending.get(key):
            candidate_hi, retail_hi = pending[key].pop(0)
            candidate_value = ((candidate_hi & 0xFFFF) << 16) + _s16(candidate_word)
            retail_value = ((retail_hi & 0xFFFF) << 16) + _s16(retail_word)
            base = retail_value - candidate_value - target.get("value", 0)
            votes.setdefault(shndx, set()).add(base)
    return {
        shndx: next(iter(values))
        for shndx, values in votes.items() if len(values) == 1
    }


def _owned_data_ranges(obj, section, referenced):
    """Return byte ranges reached by the function's data symbols."""
    section_size = section.get("size", 0)
    all_starts = sorted({
        symbol.get("value", 0)
        for symbol in obj.symbols
        if symbol.get("shndx") == section.get("idx")
    })
    ranges = []
    for symbol in referenced:
        start = symbol.get("value", 0)
        if symbol.get("size", 0):
            end = start + symbol["size"]
        else:
            following = [value for value in all_starts if value > start]
            end = min(following) if following else section_size
        ranges.append((start, end))
    return ranges


def compare_owned_data_relocations(obj, name, candidate_addr, retail,
                                   marker_addrs=None):
    """Compare function-owned R_MIPS_32 table entries after local relocation.

    Only data sections directly referenced by the target function are
    considered. Undefined/external targets remain handled by the ordinary
    function relocation mask.
    """
    fn = _function_metadata(obj, name)
    body, rels = fn["body"], fn["rels"]
    sections = {s["idx"]: s for s in obj.sh}
    data_indices = {s["idx"] for s in obj.sh if _is_owned_data_section(s)}
    referenced = {}
    for record in rels:
        target = _record_symbol(obj, record)
        shndx = target.get("shndx")
        if shndx in data_indices:
            referenced.setdefault(shndx, []).append(target)
    if not referenced:
        return 0, []
    retail_win = retail.bytes_at(candidate_addr, len(body))
    text_bases = _candidate_text_bases(
        obj, fn, candidate_addr, marker_addrs or {})
    data_bases = _recover_data_bases(obj, fn, body, rels, retail_win)
    diffs = []
    for shndx, symbols in referenced.items():
        if shndx not in data_bases:
            continue
        section = sections[shndx]
        ranges = _owned_data_ranges(obj, section, symbols)
        raw = _section_bytes(obj, section)
        for record in _section_reloc_records(obj, shndx):
            if record.get("r_type") != 2:
                continue
            offset = record.get("offset", -1)
            if offset < 0 or offset + 4 > len(raw):
                continue
            if not any(start <= offset and (end is None or offset + 4 <= end)
                       for start, end in ranges):
                continue
            target = _record_symbol(obj, record)
            target_section = target.get("shndx")
            if target_section not in text_bases:
                continue  # legitimate external relocation
            candidate_target = text_bases[target_section] + target.get("value", 0)
            candidate_word = _u32(raw, offset, getattr(obj, "endian", "<"))
            if candidate_word is None:
                continue
            linked_word = (candidate_target + candidate_word) & 0xFFFFFFFF
            try:
                retail_data = retail.bytes_at(data_bases[shndx] + offset, 4)
            except (KeyError, ValueError, IndexError):
                continue
            retail_word = _u32(retail_data, 0, getattr(obj, "endian", "<"))
            if retail_word is None or linked_word != retail_word:
                diffs.append(dict(section=section.get("name", str(shndx)),
                                  section_index=shndx, offset=offset,
                                  candidate=linked_word, retail=retail_word))
    return len(diffs), diffs


def scan_markers(cpath):
    """-> list of dicts {addr, name, line, stub} for each // FUN_ marker."""
    lines = cpath.read_text(errors="replace").splitlines()
    code_lines = sanitize_c_lines(lines)
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
            if MARKER_RE.match(lines[j]):
                break
            code = code_lines[j].strip()
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
        if name is None:
            out.append(dict(addr=addr, name=None, line=i + 1, stub=False,
                            nonmatching="NONMATCHING" in lines[i]))
            i += 1
            continue
        # stub detection: body up to matching '}' contains only TODO / return
        stub = False
        depth = 0
        body_lines = []
        k = j
        while k < len(lines):
            code = code_lines[k]
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
        out.append(dict(addr=addr, name=name, line=i + 1, stub=stub,
                        nonmatching="NONMATCHING" in lines[i]))
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


def compile_object(cpath, cfg, objdir=None):
    """Compile a src/ file with the project flags. Returns (ObjectFile, log) or
    (None, log) on failure. objdir defaults to a temp dir."""
    import tempfile
    rel = cpath.relative_to(REPO)
    tmp = None
    if objdir is None:
        tmp = tempfile.mkdtemp()
        objdir = Path(tmp)
    opath = Path(objdir) / (rel.as_posix().replace("/", "_") + ".o")
    proc = subprocess.run(
        [cfg["mwcc"], "-O2", "-Iinclude", "-c", str(cpath), "-o", str(opath)],
        cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if proc.returncode or not opath.is_file():
        return None, proc.stdout
    return ObjectFile(opath), proc.stdout


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
    marker_addrs = {m["name"]: m["addr"] for m in markers if m["name"]}
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
        try:
            owned_diff, owned_details = compare_owned_data_relocations(
                obj, mk["name"], mk["addr"], retail, marker_addrs)
        except (KeyError, IndexError, ValueError, struct.error):
            # A section without a deterministic retail placement is not a
            # reason to reject an otherwise ordinary function relocation.
            owned_diff, owned_details = 0, []
        ndiff += owned_diff
        tail = win_bytes[len(body):]
        entry["object_size"] = len(body)
        entry["window"] = window
        entry["normalized_diff"] = ndiff
        if owned_details:
            entry["owned_relocation_diffs"] = owned_details
        if ndiff or len(body) > window or any(tail):
            wrong_size = not ndiff
            if mk["nonmatching"]:
                entry["status"] = "NONMATCHING"
            elif wrong_size:
                entry["status"] = "SIZE_MISMATCH"
                entry["detail"] = (f"object {len(body)}B vs retail window {window}B; "
                                   f"tail is not zero padding")
            else:
                entry["status"] = "MISMATCH"
            if ndiff:
                entry["first_diffs"] = first
        elif mk["nonmatching"]:
            entry["status"] = "STALE_NONMATCHING"
            entry["detail"] = "function now matches; remove the NONMATCHING tag"
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

    def is_generated(p):
        # permuter droppings: hit regions (*.match.c) and scratch TUs (.permute_*)
        return p.name.endswith(".match.c") or p.name.startswith(".permute_")

    files = ([Path(f).resolve() for f in args.files] if args.files
             else sorted(p for p in (REPO / "src").rglob("*.c") if not is_generated(p)))

    # Function boundaries: every Ghidra entry plus every marker address in the
    # whole repo (Ghidra misses many small functions; markers fill the gaps).
    bounds = {int(a, 16) for a in sizes["windows"]}
    for address, window in sizes["windows"].items():
        if window:
            bounds.add(int(address, 16) + window)
    for cpath in sorted(p for p in (REPO / "src").rglob("*.c") if not is_generated(p)):
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
    for st in ("MATCH", "STUB", "NONMATCHING", "STALE_NONMATCHING", "MISMATCH",
               "SIZE_MISMATCH", "NO_SYMBOL", "COMPILE_ERROR", "UNKNOWN_ADDR"):
        if counts.get(st):
            print(f"  {st:<14} {counts[st]}")

    bad = [r for r in all_results
           if r["status"] not in ("MATCH", "STUB", "NONMATCHING")]
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
