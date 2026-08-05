#!/usr/bin/env python3
"""Global-addressing-mode census: `$gp`-relative access versus absolute
`lui`/`addiu` materialisation.

W466's CLEAN audit ranked the top 25 functions whose frame size and
callee-saved register set already agree with retail, and read the first
divergent instruction of each.  A recurring pair jumped out:

    candidate  lw $v0,($gp)          retail  lui $v0,0x87
    candidate  lw $s2,($gp)          retail  lw  $s1,-0x49e8($gp)
    candidate  lui $s0,0             retail  bnez $v1,...

The first of those is not a register or a scheduling difference.  It is a
different *addressing mode for the same global*: we load a pointer out of the
`$gp` table, retail materialises the address directly with `lui`/`addiu`.  That
is a source-level distinction in this codebase -- it is decided by how the
symbol is declared and by whether the `_abs` alias idiom is used -- and W458
established it as drivable, converting 25 functions including a 20-entry
dispatch table.

This census counts the two idioms per function on each side.  Counts are
multiset quantities, so like `opcode_census` they survive the misalignment that
makes every offset-based census unreadable above ~30% divergence -- which is
exactly the regime the CLEAN class lives in.

  GPLOAD    a load or store whose base register is `$gp`
  LUI       an address materialisation (`lui`, optionally paired with `addiu`)
  ADDIU_GP  `addiu rX,$gp,imm`, the address-of form of a `$gp` object

A positive delta means retail emits more.  The actionable signature is a
symmetric pair: retail `+N LUI` against candidate `+N GPLOAD` (our globals
should be absolute) or the mirror (ours should be `$gp`-relative).

Relocated words are NOT masked: a relocation rewrites an immediate, never an
opcode or a base register, so both idioms remain identifiable.  That matters
because nearly every one of these instructions carries a relocation and masking
them -- as an earlier draft of `opcode_census` did -- manufactures phantom
deltas.

Usage:
    python tools/addrmode_census.py --report build/baselines/W466_gate.json \
                                    --out build/wip/W467_addrmode.md [--file src/x.c]
"""

from pathlib import Path
import argparse
import collections
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, RetailElf, compile_object, load_config,
                    scan_markers, window_for)
from regsub_census import first_party, words_of

GP = 28
LUI = 0x0F
ADDIU, DADDIU = 0x09, 0x19
# every load and store opcode: rs is the base register
MEM_OPS = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
           0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,
           0x30, 0x31, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3D, 0x3E, 0x3F}


def classify(word):
    op = word >> 26
    rs = (word >> 21) & 0x1F
    if op == LUI:
        return "LUI"
    if op in MEM_OPS and rs == GP:
        return "GPLOAD"
    if op in (ADDIU, DADDIU) and rs == GP:
        return "ADDIU_GP"
    return None


def counts(words):
    h = collections.Counter()
    for w in words:
        if w < 0:
            continue
        c = classify(w)
        if c:
            h[c] += 1
    return h


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--min-delta", type=int, default=1)
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    wanted = args.file.replace("\\", "/") if args.file else None

    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] != "NONMATCHING":
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
            with tempfile.TemporaryDirectory(prefix="p3am_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print("  ! %s: compile failed" % path, file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, _rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    tgt = retail.bytes_at(addr, window_for(addr, bounds))
                    c, t = counts(words_of(body)), counts(words_of(tgt))
                    d = {k: t[k] - c[k] for k in ("LUI", "GPLOAD", "ADDIU_GP")}
                    if all(abs(v) < args.min_delta for v in d.values()):
                        continue
                    # the actionable shape: one idiom up, the other down
                    swap = min(abs(d["LUI"]), abs(d["GPLOAD"])) \
                        if d["LUI"] * d["GPLOAD"] < 0 else 0
                    findings.append({
                        "file": path, "addr": r["addr"], "name": r["name"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "d": d, "swap": swap,
                        "cand": c, "retail": t,
                        "dir": "to_abs" if d["LUI"] > 0 else "to_gp"})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    findings.sort(key=lambda f: (-f["swap"], -abs(f["d"]["LUI"]), -f["nd"]))
    swapped = [f for f in findings if f["swap"]]
    tot = collections.Counter()
    for f in findings:
        for k, v in f["d"].items():
            tot[k] += abs(v)

    lines = ["# Global-addressing-mode census", "",
             "Source report: `%s`" % args.report, "",
             "%d functions differ in how they reach globals; **%d show the "
             "symmetric swap** where one side materialises an address with "
             "`lui` and the other loads it through `$gp`."
             % (len(findings), len(swapped)), "",
             "Absolute class magnitudes: LUI %d, GPLOAD %d, ADDIU_GP %d."
             % (tot["LUI"], tot["GPLOAD"], tot["ADDIU_GP"]), "",
             "A positive delta means **retail emits more**. `to_abs` means "
             "retail materialises addresses that we load through `$gp`, so our "
             "declaration should be an absolute object (the `_abs` alias idiom "
             "this codebase already uses); `to_gp` is the inverse.", "",
             "Counts are multiset quantities and do not depend on difflib "
             "alignment, so unlike `imm_census`, `gap_census`, `branch_census`, "
             "`regsub_census` and `width_census` these rows stay meaningful in "
             "the badly-aligned functions where most of the remaining nd sits.",
             "",
             "|function|address|nd|object/window|swap|dLUI|dGPLOAD|dADDIU_GP|dir|file|",
             "|---|---|---:|---|---:|---:|---:|---:|---|---|"]

    for f in findings[:250]:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        lines.append("|`%s`|%s|%d|%s|%d|%+d|%+d|%+d|%s|%s|"
                     % (f["name"], f["addr"], f["nd"], win, f["swap"],
                        f["d"]["LUI"], f["d"]["GPLOAD"], f["d"]["ADDIU_GP"],
                        f["dir"], f["file"]))

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions, %d symmetric swaps -> %s"
              % (len(findings), len(swapped), args.out))
        for k in ("LUI", "GPLOAD", "ADDIU_GP"):
            print("   %-9s %d" % (k, tot[k]))
    else:
        print(text)


if __name__ == "__main__":
    main()
