"""Compare how many arguments retail sets up per call against how many we do.

Twice now a function with a large `DEST_ROLE` cluster has turned out to have ONE
cause: a call written in our source with fewer arguments than retail passes.
bp_tut `FUN_002510d0` (19 such rows, nd 24) and btlBoss `FUN_002fd8a0` (24 rows,
nd 43) both went straight to MATCH once the missing argument was supplied. A
missing argument occupies an argument register at the callsite and pushes every
other live value one register along, so the damage looks like a register
allocation catastrophe and is actually a one-line prototype defect.

This finds them without hand-decoding. For each call in a function it counts the
argument registers written since the previous call, on BOTH sides, and reports
the calls where retail sets up more (or fewer) than we do.

    python tools/call_arity.py --report build/baselines/W448_gate.json \\
        --out build/wip/arity.md [--max-nd 400] [--file-filter btlBoss]

Reads fndiff's full two-column listing, so it needs no separate disassembler.
A `retail > ours` row is the actionable case: look at which register retail
loads and pass that value.
"""
import argparse
import json
import re
import subprocess
import sys
import concurrent.futures as cf
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
# offset, our word, our disasm (25 cols), retail word, retail disasm (25 cols)
ROW = re.compile(r"^\s*(\d+) [ !] ([0-9a-f]{8})\s\s(.{25})([0-9a-f]{8})\s\s(.{0,25})")
HALF = re.compile(r"^\s*(\d+) [ !] ([0-9a-f]{8})\s\s(.{0,25})")
INT_ARGS = ["$a0", "$a1", "$a2", "$a3"]
FP_ARGS = ["$f12", "$f13", "$f14", "$f15", "$f16", "$f17", "$f18", "$f19"]
ARGS = set(INT_ARGS) | set(FP_ARGS)
# instructions whose FIRST operand is a destination register
STORES = {"sw", "sb", "sh", "sd", "sq", "swc1", "sdc1", "sqc2", "cache"}
BRANCH = {"b", "beq", "bne", "beqz", "bnez", "blez", "bgtz", "bltz", "bgez",
          "bc1t", "bc1f", "j", "jr", "jal", "jalr"}


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def parse_stream(text, side):
    """Return [(offset, mnemonic, [operands])] for one column of fndiff output."""
    out = []
    for line in text.splitlines():
        m = ROW.match(line)
        if m:
            off, ow, od, rw, rd = m.groups()
            body = od if side == "ours" else rd
        else:
            m = HALF.match(line)
            if not m or side == "retail":
                continue
            off, ow, body = m.groups()
        body = body.strip()
        if not body or body == "??":
            continue
        parts = body.split(None, 1)
        mnem = parts[0]
        ops = [o.strip() for o in parts[1].split(",")] if len(parts) > 1 else []
        out.append((int(off), mnem, ops))
    return out


def arity_per_call(stream):
    """For each jal/jalr, which argument registers were written since the last call."""
    calls = []
    pending = set()
    for _off, mnem, ops in stream:
        if mnem in ("jal", "jalr"):
            calls.append((ops[-1] if ops else "?", frozenset(pending)))
            pending = set()
            continue
        if mnem in BRANCH or mnem in STORES or not ops:
            continue
        dest = ops[0]
        if dest in ARGS:
            pending.add(dest)
        # a register written to something else is no longer a pending argument
        elif dest in pending:
            pending.discard(dest)
    return calls


def marker_for(path, line):
    txt = open(REPO / path.replace("\\", "/"), newline="").read().split("\n")
    if line - 1 >= len(txt):
        return None
    m = re.search(r"\b(?:FUN|func|sub)_([0-9a-fA-F]{8})\b", txt[line - 1])
    return "FUN_" + m.group(1).lower() if m else None


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--max-nd", type=int, default=400)
    ap.add_argument("--min-nd", type=int, default=1)
    ap.add_argument("--file-filter", default="")
    ap.add_argument("--status", default="NONMATCHING",
                    help="MATCH is a self-test: a byte-identical function MUST "
                         "report CLEAN, so any finding there is a parser bug")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--jobs", type=int, default=12)
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    sel = [r for r in rows
           if not is3(r["file"]) and r["status"] == args.status
           and args.min_nd <= (r["normalized_diff"] or 0) <= args.max_nd
           and (not args.file_filter or args.file_filter in r["file"])]
    sel.sort(key=lambda r: -(r["normalized_diff"] or 0))

    if args.limit:
        sel = sel[:args.limit]

    def scan(r):
        """fndiff one function and return (row, kind, ours, retail, bad)."""
        out = ""
        for argv in ([marker_for(r["file"], r["line"])], [r["name"]],
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
            return (r, "LOOKUP_FAILED", 0, 0, [])
        ours = arity_per_call(parse_stream(out, "ours"))
        retail = arity_per_call(parse_stream(out, "retail"))
        if len(ours) != len(retail):
            return (r, "CALL_COUNT_DIFFERS", len(ours), len(retail), [])
        bad = []
        for i, ((_ot, oa), (rt, ra)) in enumerate(zip(ours, retail)):
            if len(oa) < len(ra):
                bad.append((i, rt, sorted(ra - oa), "MISSING"))
            elif len(oa) > len(ra):
                bad.append((i, rt, sorted(oa - ra), "EXTRA"))
        kind = "ARITY_MISMATCH" if bad else "CLEAN"
        return (r, kind, len(ours), len(retail), bad)

    findings = []
    totals = Counter()
    with cf.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for r, kind, no, nr, bad in pool.map(scan, sel):
            totals[kind] += 1
            if kind == "CALL_COUNT_DIFFERS":
                findings.append((r, kind, no, nr, bad))
                print(f"{r['addr']} nd {r['normalized_diff']:5d}  CALL COUNT "
                      f"ours {no} retail {nr}", flush=True)
            elif kind == "ARITY_MISMATCH":
                findings.append((r, kind, no, nr, bad))
                miss = sum(1 for b in bad if b[3] == "MISSING")
                print(f"{r['addr']} nd {r['normalized_diff']:5d}  "
                      f"{len(bad)} call(s) differ ({miss} missing)", flush=True)

    out_lines = ["# Call argument-arity census", ""]
    out_lines.append("For each call, the argument registers written since the "
                     "previous call, ours versus retail. A **MISSING** row means "
                     "retail passes an argument we do not — that single defect "
                     "took bp_tut `002510d0` and btlBoss `002fd8a0` straight to "
                     "MATCH from nd 24 and nd 43.")
    out_lines.append("")
    for k, v in totals.most_common():
        out_lines.append(f"- {k} {v}")
    out_lines.append("")
    findings.sort(key=lambda f: -sum(1 for b in f[4] if b[3] == "MISSING"))
    for r, kind, no, nr, bad in findings:
        out_lines.append(f"## {r['addr']} `{r['name']}` — nd {r['normalized_diff']}"
                         f" — {r['file'].replace(chr(92), '/')}")
        out_lines.append("")
        if kind == "CALL_COUNT_DIFFERS":
            out_lines.append(f"Call COUNT differs: ours {no}, retail {nr}. "
                             f"Run an ordered call census before anything else.")
            out_lines.append("")
            continue
        out_lines.append("| call # | retail target | kind | registers |")
        out_lines.append("|---:|---|---|---|")
        for i, tgt, regs, kindx in bad:
            out_lines.append(f"| {i} | `{tgt}` | {kindx} | {', '.join(regs)} |")
        out_lines.append("")

    text = "\n".join(out_lines) + "\n"
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(findings)} functions with call differences")
    else:
        print(text)


main()
