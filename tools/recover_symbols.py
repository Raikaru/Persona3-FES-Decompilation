#!/usr/bin/env python3
"""Recover named data/function symbol addresses from matched C.

The retail ELF is stripped, so there is no symbol table to link C objects
against. This tool bootstraps one: it compiles every source file, and for each
relocation in a byte-matching function it reads the resolved value out of the
retail bytes and backs out the compiled addend, yielding the referenced
symbol's address. A symbol is only emitted when every matched reference agrees
on the same address (cross-file consistency is the validator), so a single
wrong or shared-%hi reference drops the symbol instead of poisoning the table.

Output: config/symbols_recovered.txt, consumed by the linker command file
generator in tools/build.py. `_gp` comes from the ELF `.reginfo` `ri_gp_value`.

Usage:
  python tools/recover_symbols.py            # write config/symbols_recovered.txt
  python tools/recover_symbols.py --print     # print, do not write
"""
from __future__ import annotations

import collections
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402

OUT = REPO / "config" / "symbols_recovered.txt"


def _s16(x: int) -> int:
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


def _w32(b: bytes, o: int) -> int:
    return struct.unpack_from("<I", b, o)[0]

def address_name_mismatches(symbols):
    """Return address-encoded names whose recovered value contradicts the name."""
    mismatches = {}
    for name, address in symbols.items():
        if not name.startswith(("D_", "DAT_", "jtbl_", "PTR_")):
            continue
        match = re.search(r"(?:^|_)([0-9A-Fa-f]{8})(?:$|_)", name)
        if match is None:
            continue
        named_address = int(match.group(1), 16)
        if named_address != address:
            mismatches[name] = (named_address, address)
    return mismatches


def gp_value(retail_path: str) -> int:
    """Read ri_gp_value from the ELF .reginfo section (o32 layout)."""
    data = Path(retail_path).read_bytes()
    _endian, sh = V.elf_sections(data)
    for s in sh:
        if s.get("name") == ".reginfo" and s["size"] >= 24:
            off = s["offset"]
            return struct.unpack_from("<I", data, off + 20)[0]  # after gprmask + 4*cprmask
    raise SystemExit("recover_symbols: no .reginfo/ri_gp_value in retail ELF")


def recover(cfg):
    retail = V.RetailElf(cfg["retail_elf"])
    gp = gp_value(cfg["retail_elf"])
    recovered: dict[str, collections.Counter] = collections.defaultdict(collections.Counter)
    kinds: dict[str, set] = collections.defaultdict(set)

    for cpath in sorted((REPO / "src").rglob("*.c")):
        markers = V.scan_markers(cpath)
        if not markers:
            continue
        obj, _log = V.compile_object(cpath, cfg)
        if obj is None:
            continue
        symtab = {s["name"]: s.get("shndx", 0) for s in obj.symbols}
        for mk in markers:
            if mk["stub"] or mk["nonmatching"] or not mk["name"]:
                continue
            try:
                body, rels = obj.function(mk["name"])
            except KeyError:
                continue
            addr = mk["addr"]
            try:
                win = retail.bytes_at(addr, len(body))
            except ValueError:
                continue
            if V.compare(body, rels, win)[0] != 0:
                continue  # only trust matched functions
            pend: dict[str, list] = collections.defaultdict(list)
            for r in rels:
                off, t, nm = r["offset"], r["r_type"], r["symbol"]
                if not nm or off + 4 > len(win) or off + 4 > len(body):
                    continue
                if symtab.get(nm, 0) != 0:
                    continue  # defined in this object (local/static) -> not external
                wc, wr = _w32(body, off), _w32(win, off)
                if t == 4:  # R_MIPS_26
                    addend = (wc & 0x03FFFFFF) << 2
                    target = ((wr & 0x03FFFFFF) << 2) | ((addr + off) & 0xF0000000)
                    recovered[nm][target - addend] += 1
                    kinds[nm].add("func")
                elif t == 5:  # HI16
                    pend[nm].append((wc, wr))
                elif t == 6:  # LO16
                    lo_c, lo_r = _s16(wc), _s16(wr)
                    for hc, hr in pend[nm]:
                        base = (((hr & 0xFFFF) << 16) + lo_r) - (((hc & 0xFFFF) << 16) + lo_c)
                        recovered[nm][base] += 1
                        kinds[nm].add("abs")
                    pend[nm] = []
                elif t == 7:  # GPREL16
                    recovered[nm][gp + (_s16(wr) - _s16(wc))] += 1
                    kinds[nm].add("gp")

    consistent = {nm: c.most_common(1)[0][0] for nm, c in recovered.items() if len(c) == 1}
    conflicts = {nm: dict(c) for nm, c in recovered.items() if len(c) > 1}
    return gp, consistent, kinds, conflicts


def main():
    cfg = V.load_config()
    gp, consistent, kinds, conflicts = recover(cfg)
    name_mismatches = address_name_mismatches(consistent)
    for name in name_mismatches:
        del consistent[name]
    lines = [
        "// Recovered symbol addresses (generated by tools/recover_symbols.py).",
        "// Addresses inferred from matched-function relocations against retail;",
        "// only cross-file-consistent symbols are listed. Do not hand-edit.",
        f"_gp = {gp:#010x}; // type:gp",
    ]
    for nm, addr in sorted(consistent.items(), key=lambda kv: kv[1]):
        kind = "func" if "func" in kinds[nm] else "data"
        lines.append(f"{nm} = {addr:#010x}; // type:{kind}")
    text = "\n".join(lines) + "\n"
    data_n = sum(1 for nm in consistent if "func" not in kinds[nm])
    func_n = len(consistent) - data_n
    if "--print" in sys.argv:
        sys.stdout.write(text)
    else:
        OUT.write_text(text)
    sys.stderr.write(
        f"recover_symbols: gp={gp:#x} data={data_n} func={func_n} "
        f"conflicts={len(conflicts)} name_mismatches={len(name_mismatches)} -> {OUT.name}\n"
    )
    if conflicts:
        sys.stderr.write("  dropped (inconsistent): " + ", ".join(sorted(conflicts)) + "\n")
    if name_mismatches:
        sys.stderr.write(
            "  dropped (address encoded in name): "
            + ", ".join(
                f"{name}={actual:#x} (name says {named:#x})"
                for name, (named, actual) in sorted(name_mismatches.items())
            )
            + "\n"
        )


if __name__ == "__main__":
    main()
