"""Classify every differing instruction row of NONMATCHING functions.

`fndiff` shows you the rows; this reads them and says WHAT KIND of difference each
row is, which is what decides the mechanism:

  COMMUTATIVE_SWAP  same mnemonic and destination, source operands transposed.
                    -> a `static inline` helper whose parameter order presents the
                       operands in retail's order. This produced four MATCHes in
                       W445-W446, including two functions that had been on the
                       confirmed-floor list for months.
  DEST_ROLE         same mnemonic and sources, DIFFERENT destination register.
                    -> NOT an operand-order problem; a helper cannot fix it. The
                       value is consumed differently: wrong argument index, wrong
                       live range, or a wrong return type. See
                       skill://mwccps2-hidden-argument-liveness.
  REG_SUBST         same mnemonic and shape, one register consistently different.
                    -> saved-register/liveness reading, tools/prologue_census.py.
  IMM_DIFF          same mnemonic and registers, different immediate.
                    -> a literal, a struct offset, or an array dimension.
  BRANCH_TARGET     same branch mnemonic and registers, different target.
                    -> block layout; switch/if-chain shape skills.
  WIDTH             ld/sd versus lwc1/swc1 and friends: an aggregate copy width.
  MNEMONIC          different operation entirely.
  ONE_SIDED         a row present in only one of the two.

    python tools/residual_classify.py --report build/baselines/W446_gate.json \\
        --out build/wip/residuals.md [--max-nd 40] [--file-filter btlEffect]

Ranks functions by how many rows fall in the mechanically-actionable classes.
"""
import argparse
import json
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
ROW = re.compile(r"^\s*(\d+) ! ([0-9a-f]{8})\s\s(.{25})([0-9a-f]{8})\s\s(.*?)\s*$")
LOOSE = re.compile(r"^\s*(\d+) ! ([0-9a-f]{8})\s+(.*)$")
COMMUTATIVE = {"addu", "daddu", "add", "and", "or", "xor", "nor", "mult", "multu",
               "add.s", "mul.s", "addu.qb", "pmaxw", "pminw"}
LOAD_STORE_INT = {"ld", "sd", "lw", "sw", "lh", "sh", "lb", "sb", "lq", "sq"}
LOAD_STORE_FP = {"lwc1", "swc1", "ldc1", "sdc1", "lqc2", "sqc2"}


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)

MEMOP = re.compile(r"^(-?(?:0x)?[0-9a-fA-F]*)\((\$\w+)\)$")


def split_row(text):
    """`mnemonic op1, op2, op3` -> (mnemonic, [operands]).

    A memory operand `off($base)` is split into its displacement and its base so
    a differing base register is reported as REG_SUBST rather than IMM_DIFF.
    """
    text = text.strip()
    if not text:
        return None, []
    parts = text.split(None, 1)
    mnem = parts[0]
    ops = []
    if len(parts) > 1:
        for o in parts[1].split(","):
            o = o.strip()
            m = MEMOP.match(o)
            if m:
                ops.append(m.group(1) or "0")
                ops.append(m.group(2))
            else:
                ops.append(o)
    return mnem, ops


def classify(ours, retail):
    om, oo = split_row(ours)
    rm, ro = split_row(retail)
    if om is None or rm is None:
        return "ONE_SIDED"
    if om != rm:
        if (om in LOAD_STORE_INT and rm in LOAD_STORE_FP) or \
           (om in LOAD_STORE_FP and rm in LOAD_STORE_INT):
            return "WIDTH"
        return "MNEMONIC"
    if len(oo) != len(ro):
        return "MNEMONIC"
    if oo == ro:
        return "SAME"
    diff = [i for i in range(len(oo)) if oo[i] != ro[i]]
    if om.startswith(("b", "j")) and diff and diff[-1] == len(oo) - 1:
        # branch/jump whose final operand is the target
        if all(oo[i] == ro[i] for i in diff[:-1]):
            return "BRANCH_TARGET"
    # destination is operand 0 for the arithmetic/logic forms we care about
    if len(oo) == 3:
        if oo[0] == ro[0] and oo[1] == ro[2] and oo[2] == ro[1]:
            return "COMMUTATIVE_SWAP" if om in COMMUTATIVE else "OPERAND_SWAP"
        if oo[0] != ro[0] and oo[1:] == ro[1:]:
            return "DEST_ROLE"
    if len(oo) == 2 and oo[0] != ro[0] and oo[1] == ro[1]:
        return "DEST_ROLE"
    # a single differing operand that is a register
    if len(diff) == 1 and oo[diff[0]].startswith("$") and ro[diff[0]].startswith("$"):
        return "REG_SUBST"
    if len(diff) == 1:
        return "IMM_DIFF"
    return "REG_SUBST"


def marker_for(path, line):
    txt = open(REPO / path.replace("\\", "/"), newline="").read().split("\n")
    if line - 1 >= len(txt):
        return None
    m = re.search(r"\b(?:FUN|func|sub)_([0-9a-fA-F]{8})\b", txt[line - 1])
    if m:
        return "FUN_" + m.group(1).lower()
    m = re.search(r"//\s*(\w+)", txt[line - 1])
    return m.group(1) if m else None


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--max-nd", type=int, default=40)
    ap.add_argument("--min-nd", type=int, default=1)
    ap.add_argument("--file-filter", default="")
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    sel = [r for r in rows
           if not is3(r["file"]) and r["status"] == "NONMATCHING"
           and args.min_nd <= (r["normalized_diff"] or 0) <= args.max_nd
           and (not args.file_filter or args.file_filter in r["file"])]
    sel.sort(key=lambda r: r["normalized_diff"])

    per_fn = {}
    totals = Counter()
    for r in sel:
        # fndiff resolves the marker comment for most functions, but some are
        # only findable by their definition symbol or by address. A failed lookup
        # prints "no marker found" and exits 0, which is indistinguishable from a
        # clean diff — W447 lost a lane to that, so try every form and shout if
        # none of them works rather than silently reporting zero rows.
        out = ""
        for argv in ([marker_for(r["file"], r["line"])],
                     [r["name"]],
                     [r["name"], "--addr", r["addr"]]):
            if not argv[0]:
                continue
            p = subprocess.run([sys.executable, "tools/fndiff.py",
                                r["file"].replace("\\", "/")] + argv,
                               cwd=REPO, capture_output=True, text=True,
                               stdin=subprocess.DEVNULL)
            out = p.stdout + p.stderr
            if "differing words" in out:
                break
        if "differing words" not in out:
            totals["LOOKUP_FAILED"] += 1
            print(f"{r['addr']} nd {r['normalized_diff']:4d}  LOOKUP_FAILED")
            continue
        kinds = Counter()
        detail = []
        for line in out.splitlines():
            m = ROW.match(line)
            if m:
                _off, _ow, od, _rw, rd = m.groups()
                k = classify(od, rd)
            elif LOOSE.match(line) and " ! " in line[:14]:
                k = "ONE_SIDED"
                od = rd = ""
            else:
                continue
            if k == "SAME":
                continue
            kinds[k] += 1
            totals[k] += 1
            detail.append((k, od.strip(), rd.strip()))
        if kinds:
            per_fn[(r["addr"], r["name"], r["file"], r["normalized_diff"])] = (kinds, detail)
        print(f"{r['addr']} nd {r['normalized_diff']:4d}  " +
              " ".join(f"{k}={v}" for k, v in kinds.most_common()))

    ACTIONABLE = ("COMMUTATIVE_SWAP", "DEST_ROLE", "BRANCH_TARGET", "IMM_DIFF")
    out = ["# Residual row classification", ""]
    out.append("Row-kind totals across the scanned band:")
    out.append("")
    for k, v in totals.most_common():
        out.append(f"- **{k}** {v}")
    out.append("")
    out.append("## Functions with mechanically-actionable rows")
    out.append("")
    out.append("| nd | addr | function | file | actionable rows |")
    out.append("|---:|---|---|---|---|")
    ranked = sorted(per_fn.items(),
                    key=lambda kv: -sum(kv[1][0][k] for k in ACTIONABLE))
    for (addr, name, rel, nd), (kinds, _d) in ranked:
        act = {k: kinds[k] for k in ACTIONABLE if kinds[k]}
        if not act:
            continue
        out.append(f"| {nd} | {addr} | {name} | {rel.replace(chr(92), '/')} | "
                   f"{', '.join(f'{k} x{v}' for k, v in act.items())} |")
    out.append("")
    out.append("## Every scanned function, with its rows")
    out.append("")
    for (addr, name, rel, nd), (kinds, detail) in ranked:
        out.append(f"### {addr} `{name}` — nd {nd} — {rel.replace(chr(92), '/')}")
        out.append("")
        for k, od, rd in detail[:16]:
            out.append(f"- `{k}` ours `{od}` retail `{rd}`")
        if len(detail) > 16:
            out.append(f"- ... {len(detail) - 16} more rows")
        out.append("")

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(per_fn)} functions classified")
    else:
        print(text)


main()
