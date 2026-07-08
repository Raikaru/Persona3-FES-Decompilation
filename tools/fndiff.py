#!/usr/bin/env python3
"""Instruction-level diff of one function against retail.

Usage:
  python tools/fndiff.py src/Battle/btlUnit.c btlUnitDestroyMoveToUnitPacket
  python tools/fndiff.py src/foo.c FunctionName --addr 00281ab0   # override marker

Compiles the file exactly like tools/verify.py, extracts the function, and
prints a side-by-side MIPS disassembly (object vs retail) with relocations
annotated and differing lines marked with '!'. Relocated fields are masked
from the comparison, mirroring verify.py.
"""

from pathlib import Path
import argparse
import json
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, ObjectFile, RetailElf, load_config,
                    mask_bytes, scan_markers, window_for)

try:
    from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, CS_MODE_LITTLE_ENDIAN
    _md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)

    def dis(word_bytes, pc):
        for ins in _md.disasm(word_bytes, pc):
            return f"{ins.mnemonic} {ins.op_str}"
        return "??"
except ImportError:
    def dis(word_bytes, pc):
        return ""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("function")
    ap.add_argument("--addr", help="retail address (hex), else taken from marker")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))

    cpath = Path(args.file).resolve()
    markers = scan_markers(cpath)
    if args.addr:
        addr = int(args.addr, 16)
    else:
        mk = next((m for m in markers if m["name"] == args.function), None)
        if not mk:
            sys.exit(f"no // FUN_ marker found for {args.function} in {args.file}")
        addr = mk["addr"]

    bounds = {int(a, 16) for a in sizes["windows"]}
    for c in sorted((REPO / "src").rglob("*.c")):
        for m in scan_markers(c):
            bounds.add(m["addr"])
    window = window_for(addr, sorted(bounds))

    with tempfile.TemporaryDirectory(prefix="p3fndiff_") as td:
        opath = Path(td) / "out.o"
        proc = subprocess.run(
            [cfg["mwcc"], "-O2", "-Iinclude", "-c", str(cpath), "-o", str(opath)],
            cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if proc.returncode:
            sys.exit(proc.stdout)
        body, rels = ObjectFile(opath).function(args.function)

    tgt = retail.bytes_at(addr, window)
    mask = mask_bytes(max(len(body), len(tgt)), rels)
    rel_at = {}
    for r in rels:
        rel_at.setdefault(r["offset"] & ~3, []).append(f"{r['type']}:{r['symbol']}")

    print(f"{args.function} @ {addr:#010x}  obj {len(body)}B  window {window}B")
    print(f"{'off':>6} {'':1} {'object':<34} {'retail':<34} reloc")
    ndiff = 0
    for o in range(0, max(len(body), len(tgt)), 4):
        ob = body[o:o+4]
        tb = tgt[o:o+4]
        differ = any((ob[i] if i < len(ob) else None) != (tb[i] if i < len(tb) else None)
                     for i in range(4) if not mask[o+i] if o+i < len(mask))
        if differ:
            ndiff += 1
        if o >= len(body) and not any(tb):
            continue  # zero padding tail
        odis = f"{ob.hex():<9} {dis(ob, addr+o)}" if len(ob) == 4 else ob.hex()
        tdis = f"{tb.hex():<9} {dis(tb, addr+o)}" if len(tb) == 4 else tb.hex()
        markc = "!" if differ else " "
        relinfo = ",".join(rel_at.get(o, []))
        print(f"{o:6} {markc} {odis:<34} {tdis:<34} {relinfo}")
    print(f"\ndiffering words (reloc-masked): {ndiff}")


if __name__ == "__main__":
    main()
