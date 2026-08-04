"""Find if/else-if chains that retail almost certainly compiled as a switch.

W450 established the mechanism: MWCC lays switch case BODIES out in declaration
order while an if/else-if chain emits them in test order, so where retail used a
switch and the reconstruction produced a chain, every call inside those bodies
comes out mis-sequenced. `tools/call_census.py` reports that as `ORDER`. Six
functions were closed that way (datScript `0030fdf0` 1919->1800, op_root
`00265030` 1289->1178 ORDER->CLEAN, fclShopMisc `003f9220` 463->383).

It is not universal. W450 lanes found six `ORDER` functions that were ALREADY
switches and four with no state chain at all, and each of those cost a lane
twenty minutes to establish by reading. This answers that question mechanically.

For every function in a verify report it scans the source body between its
marker and the next function's, and reports chains of the form

    if (X == k1) ... else if (X == k2) ... else if (X == k3) ...

on the same subject `X` against distinct integer constants — plus whether the
body already contains a `switch`, and whether the constants are tested in
descending order, which is retail's usual shape.

    python tools/chain_census.py --report build/baselines/W451_gate.json \\
        --census build/wip/W452_callcensus.md --out build/wip/W452_chains.md

With `--census`, only functions the call census flagged `ORDER` are reported and
the output is ranked for a lane to work top-down.
"""
import argparse
import json
import re
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
# `if (subject == 0x1c)` / `if (subject == 3)`, subject is any C lvalue text
IFEQ = re.compile(r"\b(?:else\s+)?if\s*\(\s*([^()=<>!&|]{1,60}?)\s*==\s*"
                  r"(0x[0-9a-fA-F]+|\d+)\s*\)")


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def bodies(rows):
    """(row, source text) for each function, cut at the next marker in its file."""
    byfile = {}
    for r in rows:
        byfile.setdefault(r["file"], []).append(r)
    for f, v in byfile.items():
        v.sort(key=lambda r: r["line"])
        try:
            lines = (REPO / f.replace("\\", "/")).read_text(
                errors="replace").split("\n")
        except OSError:
            continue
        for i, r in enumerate(v):
            end = v[i + 1]["line"] - 1 if i + 1 < len(v) else len(lines)
            yield r, "\n".join(lines[r["line"] - 1:end])


def chains(text):
    """Longest SYNTACTIC else-if run on one subject. Returns (subj, consts).

    Must be nesting-aware. The first version simply grouped every `X == const`
    test in the body, which reported mt_evtMenu `003760a0` as a 40-case chain
    when it is several independent nested chains, and op_root `00265030` as a
    3-case chain when those are singleton checks in mutually exclusive branches.
    Both cost a lane a probe. A run only counts when each test after the first
    is an `else if` at the SAME brace depth as its predecessor.
    """
    depth, runs, cur = 0, [], None
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        m = IFEQ.match(text, i) if c in "ie" else None
        if m:
            subj = " ".join(m.group(1).split())
            k = int(m.group(2), 0)
            chained = m.group(0).lstrip().startswith("else")
            if (cur and chained and cur["depth"] == depth
                    and cur["subj"] == subj):
                cur["ks"].append(k)
            else:
                cur = {"depth": depth, "subj": subj, "ks": [k]}
                runs.append(cur)
            i = m.end()
            continue
        i += 1
    best = ("", [])
    for r in runs:
        uniq = list(dict.fromkeys(r["ks"]))
        if len(uniq) > len(best[1]):
            best = (r["subj"], uniq)
    return best


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--census", help="only report functions this census calls ORDER")
    ap.add_argument("--out")
    ap.add_argument("--min-cases", type=int, default=3)
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    order = None
    if args.census:
        order = set()
        for s in Path(args.census).read_text(errors="replace").split("## ")[1:]:
            head = s.split("\n")[0]
            if " — ORDER — " in head:
                order.add(head.split()[0])

    hits, totals = [], Counter()
    for r, text in bodies(rows):
        if is3(r["file"]) or r["status"] != "NONMATCHING":
            continue
        if order is not None and r["addr"] not in order:
            continue
        subj, ks = chains(text)
        has_switch = re.search(r"\bswitch\s*\(", text) is not None
        if len(ks) < args.min_cases:
            totals["NO_CHAIN (already a switch)" if has_switch
                   else "NO_CHAIN"] += 1
            continue
        totals["CHAIN_INSIDE_SWITCH" if has_switch else "CHAIN"] += 1
        hits.append((len(ks), r, subj, ks, has_switch))

    hits.sort(key=lambda h: (-h[0], h[1].get("normalized_diff") or 0))

    L = ["# if/else-if chains that should probably be switches", ""]
    L.append("MWCC lays switch case BODIES out in declaration order and tests "
             "them in reverse; an if/else-if chain emits bodies in test order. "
             "Where retail used a switch and we rebuilt a chain, every call "
             "inside comes out mis-sequenced — which is what the call census "
             "reports as `ORDER`.")
    L.append("")
    L.append("**Declare the case labels in ASCENDING value order regardless of "
             "the order retail tests them.** Retail's body layout follows "
             "declaration order and its test order is the reverse. The rule "
             "applies per individual case label, not per fallthrough group.")
    L.append("")
    for k, v in totals.most_common():
        L.append(f"- {k} {v}")
    L.append("")
    L.append("| cases | nd | addr | subject | constants | note | file |")
    L.append("|---:|---:|---|---|---|---|---|")
    for n, r, subj, ks, has_switch in hits:
        desc = ", ".join(hex(k) if k > 9 else str(k) for k in ks)
        note = "has a switch too" if has_switch else "descending" if \
            ks == sorted(ks, reverse=True) else ""
        L.append(f"| {n} | {r['normalized_diff']} | `{r['addr']}` | "
                 f"`{subj}` | {desc} | {note} | "
                 f"{r['file'].replace(chr(92), '/')} |")
    text = "\n".join(L) + "\n"
    for k, v in totals.most_common():
        print(f"{k:32s} {v}")
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(hits)} candidate chains")
    else:
        print(text)


main()
