#!/usr/bin/env python3
"""Operand-width census: residuals caused by a local declared too narrow or
too wide.

W463 established this as the only mechanism that produced a large gain in an
otherwise register-bound wave.  fclShopMisc `FUN_003fc540` went from nd 757 to
nd 96 when an `s16` local became `s32`: MWCC b210 had been emitting a
`dsll32`/`dsra32` pair to sign-extend the narrow value through a 64-bit
register, retail emitted nothing there, and deleting those two instructions
freed the eight bytes that had been blocking a branch inversion.

The fingerprint generalises.  MIPS III gives most arithmetic two encodings, a
32-bit form and a 64-bit `d`-form, and MWCC picks between them from the
DECLARED WIDTH of the destination.  So wherever candidate and retail differ
only in which form they used, or wherever one side alone emits a shift-pair
sign extension, the defect is a declaration and not an allocation.  That
distinction matters because register allocation is a compiler floor in this
toolchain -- six functions proved it in W463 -- while declaration width is
fully source-drivable.

Three row classes, in descending order of how directly they name a fix:

  WIDTHSUB   Same instruction, same registers, same immediate, but one side
             used the 64-bit form and the other the 32-bit form.  Direction
             `cand32` means our local should be WIDER; `cand64` means ours is
             wider than the original.

  EXTEND     A `dsll32`+`dsra32` (or `sll`+`sra`) sign-extension pair that only
             one side emits.  `cand` means we are extending a value retail
             keeps naturally wide -- our local is too narrow.  `retail` is the
             inverse.

  LOADWIDTH  The same address is read or written at a different access width
             (`lw` vs `ld`, `lbu` vs `lw`, `sh` vs `sw` ...).  Usually a struct
             FIELD type rather than a local, so check the header before
             touching the function.

Usage:
    python tools/width_census.py --report build/baselines/W463_gate.json \
                                 --out build/wip/W464_width.md [--file src/x.c]
"""

from pathlib import Path
import argparse
import collections
import difflib
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, RetailElf, compile_object, load_config,
                    mask_bytes, scan_markers, window_for)
from regsub_census import first_party, words_of

SPECIAL = 0x00

# 32-bit opcode <-> 64-bit opcode for the I-type arithmetic and the accesses.
OP_PAIRS = {0x09: 0x19, 0x23: 0x37, 0x2B: 0x3F}   # addiu/daddiu lw/ld sw/sd
# SPECIAL funct, 32-bit <-> 64-bit
FN_PAIRS = {0x21: 0x2D, 0x23: 0x2F,               # addu/daddu   subu/dsubu
            0x20: 0x2C, 0x22: 0x2E,               # add/dadd     sub/dsub
            0x00: 0x38, 0x02: 0x3A, 0x03: 0x3B,   # sll/dsll srl/dsrl sra/dsra
            0x04: 0x14, 0x06: 0x16, 0x07: 0x17}   # sllv/dsllv ...

OP_NAME = {0x09: "addiu", 0x19: "daddiu", 0x23: "lw", 0x37: "ld",
           0x2B: "sw", 0x3F: "sd", 0x20: "lb", 0x24: "lbu", 0x21: "lh",
           0x25: "lhu", 0x28: "sb", 0x29: "sh"}
FN_NAME = {0x21: "addu", 0x2D: "daddu", 0x23: "subu", 0x2F: "dsubu",
           0x20: "add", 0x2C: "dadd", 0x22: "sub", 0x2E: "dsub",
           0x00: "sll", 0x38: "dsll", 0x02: "srl", 0x3A: "dsrl",
           0x03: "sra", 0x3B: "dsra", 0x3C: "dsll32", 0x3E: "dsrl32",
           0x3F: "dsra32", 0x04: "sllv", 0x14: "dsllv", 0x06: "srlv",
           0x16: "dsrlv", 0x07: "srav", 0x17: "dsrav"}

# narrow vs wide memory access on one base: a struct-field width question
ACCESS_WIDTH = {0x20: 1, 0x24: 1, 0x28: 1,        # lb lbu sb
                0x21: 2, 0x25: 2, 0x29: 2,        # lh lhu sh
                0x23: 4, 0x2B: 4,                 # lw sw
                0x37: 8, 0x3F: 8}                 # ld sd
IS_STORE = {0x28, 0x29, 0x2B, 0x3F}

SHIFT_LEFT = {0x00, 0x38, 0x3C}                   # sll dsll dsll32
SHIFT_RIGHT_ARITH = {0x03, 0x3B, 0x3F}            # sra dsra dsra32


def decode(word):
    op = word >> 26
    if op == SPECIAL:
        fn = word & 0x3F
        return {"kind": "R", "op": op, "fn": fn,
                "rs": (word >> 21) & 0x1F, "rt": (word >> 16) & 0x1F,
                "rd": (word >> 11) & 0x1F, "sa": (word >> 6) & 0x1F}
    return {"kind": "I", "op": op, "fn": None,
            "rs": (word >> 21) & 0x1F, "rt": (word >> 16) & 0x1F,
            "imm": word & 0xFFFF}


def same_operands(a, b):
    if a["kind"] == "R":
        return (a["rs"], a["rt"], a["rd"], a["sa"]) == \
               (b["rs"], b["rt"], b["rd"], b["sa"])
    return (a["rs"], a["rt"], a["imm"]) == (b["rs"], b["rt"], b["imm"])


def width_sub(cw, rw):
    """Same instruction on the same operands, 32-bit form vs 64-bit form."""
    c, r = decode(cw), decode(rw)
    if c["kind"] != r["kind"]:
        return None
    if c["kind"] == "R":
        fwd = FN_PAIRS.get(c["fn"]) == r["fn"]
        rev = FN_PAIRS.get(r["fn"]) == c["fn"]
        if not (fwd or rev):
            return None
        if c["fn"] in SHIFT_LEFT | SHIFT_RIGHT_ARITH:
            # sll 32 and dsll32 0 mean the same shift, so ignore sa here
            ok = (c["rs"], c["rt"], c["rd"]) == (r["rs"], r["rt"], r["rd"])
        else:
            ok = same_operands(c, r)
        if not ok:
            return None
        return ("cand32" if fwd else "cand64",
                FN_NAME.get(c["fn"], "?"), FN_NAME.get(r["fn"], "?"))
    fwd = OP_PAIRS.get(c["op"]) == r["op"]
    rev = OP_PAIRS.get(r["op"]) == c["op"]
    if not (fwd or rev) or not same_operands(c, r):
        return None
    return ("cand32" if fwd else "cand64",
            OP_NAME.get(c["op"], "?"), OP_NAME.get(r["op"], "?"))


def load_width(cw, rw):
    """Same base and displacement, different access width."""
    c, r = decode(cw), decode(rw)
    if c["kind"] != "I" or r["kind"] != "I":
        return None
    cwid, rwid = ACCESS_WIDTH.get(c["op"]), ACCESS_WIDTH.get(r["op"])
    if cwid is None or rwid is None or cwid == rwid:
        return None
    if (c["op"] in IS_STORE) != (r["op"] in IS_STORE):
        return None
    if (c["rs"], c["imm"]) != (r["rs"], r["imm"]):
        return None
    return (cwid, rwid, OP_NAME.get(c["op"], "?"), OP_NAME.get(r["op"], "?"))


def extend_pairs(words, base):
    """Sign-extension shift pairs inside a run of words only one side emits."""
    out = []
    for i in range(len(words) - 1):
        a, b = words[i], words[i + 1]
        if a < 0 or b < 0:
            continue
        da, db = decode(a), decode(b)
        if da["kind"] != "R" or db["kind"] != "R":
            continue
        # a MIPS shift is `op rd, rt, sa`; the source operand is rt, not rs
        if da["fn"] in SHIFT_LEFT and db["fn"] in SHIFT_RIGHT_ARITH \
                and da["sa"] == db["sa"] and da["rd"] == db["rt"]:
            out.append({"offset": (base + i) * 4,
                        "pair": "%s+%s" % (FN_NAME.get(da["fn"], "?"),
                                           FN_NAME.get(db["fn"], "?")),
                        "bits": da["sa"]})
    return out


def rows_for_function(body, rels, target):
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = words_of(body, mask)
    ret = words_of(target, mask[:len(target)] if len(mask) >= len(target) else None)

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    rows, other = [], 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        if tag in ("delete", "insert") or (i2 - i1) != (j2 - j1):
            if tag != "insert":
                for e in extend_pairs(cand[i1:i2], i1):
                    e.update(cls="EXTEND", side="cand")
                    rows.append(e)
            if tag != "delete":
                for e in extend_pairs(ret[j1:j2], j1):
                    e.update(cls="EXTEND", side="retail")
                    rows.append(e)
            continue
        for k in range(i2 - i1):
            cw, rw = cand[i1 + k], ret[j1 + k]
            if cw < 0 or rw < 0:
                continue
            ws = width_sub(cw, rw)
            if ws:
                rows.append({"cls": "WIDTHSUB", "offset": (i1 + k) * 4,
                             "side": ws[0], "cand": ws[1], "retail": ws[2]})
                continue
            lw = load_width(cw, rw)
            if lw:
                rows.append({"cls": "LOADWIDTH", "offset": (i1 + k) * 4,
                             "side": "cand%d" % lw[0], "cand": lw[2],
                             "retail": lw[3], "bits": lw[1]})
                continue
            other += 1
    return rows, other


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--max-nd", type=int, default=100000)
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    wanted = args.file.replace("\\", "/") if args.file else None

    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] != "NONMATCHING" or r["normalized_diff"] > args.max_nd:
            continue
        path = r["file"].replace("\\", "/")
        if not first_party(path) or (wanted and path != wanted):
            continue
        by_file[path].append(r)

    bounds = {int(a, 16) for a in sizes["windows"]}
    for c in sorted((REPO / "src").rglob("*.c")):
        for m in scan_markers(c):
            bounds.add(m["addr"])
    bounds = sorted(bounds)

    findings = []
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3wd_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print("  ! %s: compile failed" % path, file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    tgt = retail.bytes_at(addr, window_for(addr, bounds))
                    rows, other = rows_for_function(body, rels, tgt)
                    if not rows:
                        continue
                    findings.append({
                        "file": path, "addr": r["addr"], "name": r["name"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "rows": rows,
                        "other": other,
                        "kinds": collections.Counter(x["cls"] for x in rows)})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    # WIDTHSUB names a fix outright; EXTEND names a variable to widen;
    # LOADWIDTH is a field question.  Rank by the most direct class present,
    # then by how few other differences could confound the measurement.
    def rank(f):
        k = f["kinds"]
        best = 0 if k["WIDTHSUB"] else (1 if k["EXTEND"] else 2)
        return (best, f["other"], f["nd"])

    findings.sort(key=rank)
    tot = collections.Counter()
    for f in findings:
        tot.update(f["kinds"])

    lines = ["# Operand-width census", "",
             "Source report: `%s`" % args.report, "",
             "%d functions carry at least one width row. WIDTHSUB %d, "
             "EXTEND %d, LOADWIDTH %d." % (len(findings), tot["WIDTHSUB"],
                                           tot["EXTEND"], tot["LOADWIDTH"]), "",
             "A width row is a **declaration** defect, not an allocation one. "
             "MWCC b210 chooses between the 32-bit and the 64-bit form of an "
             "instruction from the declared width of the destination, so these "
             "rows are source-drivable -- unlike a register permutation, which "
             "W463 proved is a compiler floor on six functions.", "",
             "`cand32` = ours is the 32-bit form and retail's is 64-bit, so "
             "**our local is too narrow**; `cand64` is the inverse. An EXTEND "
             "row on side `cand` means we emit a sign-extension pair retail "
             "does not, which is the same diagnosis -- that is what took "
             "fclShopMisc `FUN_003fc540` from nd 757 to nd 96 in W463.", "",
             "Widening a local is only legal if it cannot change a value. "
             "Prove the range of every assignment and check no consumer relies "
             "on truncation before keeping any of these.", "",
             "|function|address|nd|object/window|classes|other|file|",
             "|---|---|---:|---|---|---:|---|"]

    for f in findings:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        cls = " ".join("%s x%d" % (k, n) for k, n in sorted(f["kinds"].items()))
        lines.append("|`%s`|%s|%d|%s|%s|%d|%s|"
                     % (f["name"], f["addr"], f["nd"], win, cls,
                        f["other"], f["file"]))

    lines += ["", "## Rows", ""]
    for f in findings:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        lines.append("### `%s` %s -- nd %d -- %s -- %s"
                     % (f["name"], f["addr"], f["nd"], win, f["file"]))
        for x in sorted(f["rows"], key=lambda y: y["offset"])[:24]:
            if x["cls"] == "EXTEND":
                lines.append("- +%d EXTEND %s (%d-bit) emitted by %s only"
                             % (x["offset"], x["pair"], x["bits"], x["side"]))
            else:
                lines.append("- +%d %s %s: candidate `%s` vs retail `%s`"
                             % (x["offset"], x["cls"], x["side"],
                                x["cand"], x["retail"]))
        if len(f["rows"]) > 24:
            lines.append("- ... %d more rows" % (len(f["rows"]) - 24))
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions -> %s" % (len(findings), args.out))
        for k, n in tot.most_common():
            print("   %-10s %d" % (k, n))
    else:
        print(text)


if __name__ == "__main__":
    main()
