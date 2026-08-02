"""Census of hardcoded data-address literals (defect class A) per function.

A bare 0x006xxxxx/0x007xxxxx/0x008xxxxx constant compiles to lui/ori with no
relocations; the named global it denotes compiles to lui/addiu with HI16+LO16
relocations. Converting a literal to `extern u8 DAT_xxxxxxxx[];` used as
base+offset is the fix. This tool ranks the remaining sites by the enclosing
function's normalized_diff so the densest, most valuable ones are worked first.

    python tools/literal_census.py --report build/baselines/W441_gate.json \
        [--out build/wip/literals.md] [--min-nd 1] [--file-filter k_field]
"""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
LIT = re.compile(r"0x00[6-8][0-9a-fA-F]{5}\b")
THIRD_PARTY_PREFIXES = ("rw/", "cri/", "sce/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}


def is_third_party(rel_file):
    norm = rel_file.replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[len("src/"):]
    return norm in THIRD_PARTY_FILES or norm.startswith(THIRD_PARTY_PREFIXES)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True, help="verify.py --json output")
    ap.add_argument("--out", help="write markdown here instead of stdout")
    ap.add_argument("--min-nd", type=int, default=1)
    ap.add_argument("--file-filter", default="")
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    by_file = defaultdict(list)
    for r in rows:
        if is_third_party(r["file"]):
            continue
        by_file[r["file"]].append(r)
    for v in by_file.values():
        v.sort(key=lambda r: r["line"])

    out = []
    grand = 0
    per_func = defaultdict(lambda: defaultdict(int))   # (file, addr) -> literal -> count
    meta = {}
    for rel, funcs in sorted(by_file.items()):
        if args.file_filter and args.file_filter not in rel:
            continue
        path = REPO / rel.replace("\\", "/")
        if not path.exists():
            continue
        lines = open(path, newline="").read().split("\n")
        starts = [f["line"] for f in funcs]
        for i, text in enumerate(lines, 1):
            hits = LIT.findall(text)
            if not hits:
                continue
            # last marker at or before this line
            lo, hi = 0, len(starts)
            while lo < hi:
                mid = (lo + hi) // 2
                if starts[mid] <= i:
                    lo = mid + 1
                else:
                    hi = mid
            if lo == 0:
                continue
            f = funcs[lo - 1]
            if f["status"] == "MATCH":
                continue
            if (f.get("normalized_diff") or 0) < args.min_nd:
                continue
            key = (rel, f["addr"])
            meta[key] = f
            for h in hits:
                per_func[key][h.lower()] += 1
                grand += 1

    ranked = sorted(per_func.items(),
                    key=lambda kv: (-sum(kv[1].values()),
                                    -(meta[kv[0]].get("normalized_diff") or 0)))
    out.append("# Class-A address-literal census")
    out.append("")
    out.append(f"{grand} literal occurrences across {len(per_func)} NONMATCHING functions.")
    out.append("")
    out.append("| sites | distinct | nd | obj/window | slack | addr | file | function |")
    out.append("|---|---|---|---|---|---|---|---|")
    for (rel, addr), lits in ranked:
        f = meta[(rel, addr)]
        slack = f["window"] - f["object_size"]
        out.append(f"| {sum(lits.values())} | {len(lits)} | {f['normalized_diff']} | "
                   f"{f['object_size']}/{f['window']} | {slack} | {addr} | "
                   f"{rel.replace(chr(92), '/')} | {f['name']} |")
    out.append("")
    out.append("## Per-function literal values")
    out.append("")
    for (rel, addr), lits in ranked:
        f = meta[(rel, addr)]
        vals = ", ".join(f"{k} x{v}" if v > 1 else k
                         for k, v in sorted(lits.items(), key=lambda kv: -kv[1]))
        out.append(f"- `{addr}` {f['name']} ({rel.replace(chr(92), '/')}, nd {f['normalized_diff']}): {vals}")

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {grand} sites, {len(per_func)} functions")
    else:
        print(text)


main()
