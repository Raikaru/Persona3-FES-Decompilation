"""Rank functions by how far their byte-perfect prefix extends before diverging.

`verify.py` already records `first_diffs` per function — the word indices that
differ from retail. The smallest of those, times four, is the byte offset where
our object FIRST departs. Everything before it is byte-identical, so the defect
is localised there and every later difference is downstream displacement.

That single number reframes the endgame. Over the first-party NONMATCHING
population it distributes as:

    byte-perfect prefix  0-63     951 functions   1,002,638 nd
                        64-255    283 functions     181,417 nd
                       256-511     31 functions      11,878 nd
                       512+         13 functions       6,347 nd

**Three quarters of the remaining catalogue diverges inside the first 64 bytes.**
nd is large everywhere because an early defect displaces the whole body, not
because the whole body is wrong.

Cross-referencing against `tools/prologue_census.py` splits that further:

    CLEAN prologue, diverges 0-63     531 fn   353,694 nd
    SURPLUS prologue                  157 fn   276,450 nd
    CLEAN prologue, diverges 64-255   280 fn   180,907 nd
    FRAME prologue                    113 fn   158,844 nd
    LIVENESS prologue                  92 fn   135,627 nd

The largest cell is the one nobody has targeted: a frame and saved-register set
that already match retail exactly, and divergence anyway within the first 64
bytes — so the defect is in the first few BODY instructions, which is argument
setup or first-statement ordering.

    python tools/firstdiff_census.py --report build/baselines/W456_gate.json \\
        --prologue build/wip/W457_prologue.md --out build/wip/firstdiff.md
"""
import argparse
import collections
import json
import re
from pathlib import Path

TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
HDR = re.compile(r"^## (LIVENESS|SURPLUS|MIXED|FRAME|CLEAN)\s*$")
ROW = re.compile(r"^(src[^\s]+)\s+([0-9a-f]{8})\s")


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def band(off):
    return ("prologue(0-63)" if off < 64 else "early(64-255)" if off < 256
            else "mid(256-511)" if off < 512 else "late(512+)")


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--prologue", help="tools/prologue_census.py markdown output")
    ap.add_argument("--out")
    args = ap.parse_args()

    cls, cur = {}, None
    if args.prologue:
        for line in Path(args.prologue).read_text(errors="replace").splitlines():
            m = HDR.match(line.strip())
            if m:
                cur = m.group(1)
                continue
            mm = ROW.match(line.strip())
            if mm and cur:
                cls[mm.group(2)] = cur

    rows = [r for r in json.loads(Path(args.report).read_text())["results"]
            if not is3(r["file"]) and r["status"] == "NONMATCHING"
            and r.get("first_diffs") and r.get("object_size")]
    for r in rows:
        # first_diffs are BYTE offsets already, and the list is capped at 16
        # entries; a function with nd 3 carries exactly three. Verified against
        # btlCamera 002b17a0 (nd 3, first_diffs [509, 510, 719], object 1052).
        r["prefix"] = min(r["first_diffs"])
        r["pcls"] = cls.get(r["addr"], "UNCLASSIFIED")

    cell, cellnd = collections.Counter(), collections.Counter()
    for r in rows:
        cell[(r["pcls"], band(r["prefix"]))] += 1
        cellnd[(r["pcls"], band(r["prefix"]))] += r["normalized_diff"]

    L = ["# First-divergence census — where the byte-perfect prefix ends", ""]
    L.append("`prefix` is the byte offset at which our object first departs from "
             "retail. **Everything before it is byte-identical.** The defect is "
             "there; every later difference is downstream displacement, which is "
             "why `normalized_diff` is large even for functions that are almost "
             "right.")
    L.append("")
    L.append("| prologue class | first divergence | functions | nd |")
    L.append("|---|---|---:|---:|")
    for k, n in sorted(cell.items(), key=lambda x: -cellnd[x[0]]):
        L.append(f"| {k[0]} | {k[1]} | {n} | {cellnd[k]:,} |")
    L.append("")
    L.append("A `CLEAN` prologue means frame size and callee-saved set already "
             "match retail exactly. `CLEAN` + divergence inside 64 bytes "
             "therefore means the defect is in the first few BODY instructions — "
             "argument setup or first-statement order — not in the frame.")
    L.append("")
    L.append("`SURPLUS` means we save registers retail does not: a surplus "
             "temporary or stack local. `LIVENESS` means retail saves registers "
             "we do not, so a value it keeps across a call we reload. `FRAME` "
             "means the saved set agrees and the frame size does not.")
    L.append("")
    rows.sort(key=lambda r: (-r["prefix"], -r["normalized_diff"]))
    L.append("| prefix | nd | prologue | addr | object/window | function | file |")
    L.append("|---:|---:|---|---|---|---|---|")
    for r in rows:
        L.append(f"| {r['prefix']} | {r['normalized_diff']} | {r['pcls']} | "
                 f"`{r['addr']}` | {r['object_size']}/{r['window']} | "
                 f"`{r['name']}` | {r['file'].replace(chr(92), '/')} |")
    text = "\n".join(L) + "\n"
    for k, n in sorted(cell.items(), key=lambda x: -cellnd[x[0]]):
        print(f"{k[0]:14s} {k[1]:16s} {n:6d} {cellnd[k]:10d}")
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(rows)} functions")
    else:
        print(text)


main()
