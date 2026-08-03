"""Census of NONMATCHING functions whose object is materially under its window.

Retail pads every function to a 16-byte boundary, so a deficit under 16 bytes is
noise. A larger gap means one of three things, and the lane must decide which
BEFORE writing code:

  * genuine missing body            -> reconstruct (p3-big-unimplemented-reconstruction)
  * unmarked sibling functions      -> split      (p3-window-nullsub-discovery)
  * arrangement / frame difference  -> neither; the body is complete

The `nd_per_byte` column separates them in practice. A function whose diff rate
is near 1.0 diverges from its very first instruction and is usually a real
reconstruction target; a low rate with a big gap is usually frame or layout.

    python tools/deficit_census.py --report build/baselines/W442_gate.json \
        [--out build/wip/deficit.md] [--min-deficit 64] [--file-filter h_camp]
"""
import argparse
import json
from collections import defaultdict
from pathlib import Path

THIRD_PARTY_PREFIXES = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}


def is_third_party(rel_file):
    norm = rel_file.replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[len("src/"):]
    return norm in THIRD_PARTY_FILES or norm.startswith(THIRD_PARTY_PREFIXES)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--min-deficit", type=int, default=64)
    ap.add_argument("--file-filter", default="")
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    sel = []
    for r in rows:
        if is_third_party(r["file"]) or r["status"] != "NONMATCHING":
            continue
        if args.file_filter and args.file_filter not in r["file"]:
            continue
        obj, win = r.get("object_size") or 0, r.get("window") or 0
        if win - obj < args.min_deficit:
            continue
        sel.append(r)

    by_file = defaultdict(list)
    for r in sel:
        by_file[r["file"]].append(r)

    out = ["# Under-window census (candidate reconstruction targets)", ""]
    total = sum(r["window"] - r["object_size"] for r in sel)
    out.append(f"{len(sel)} NONMATCHING functions at least {args.min_deficit} bytes "
               f"under window, {total} bytes of deficit in total.")
    out.append("")
    out.append("`rate` is normalized_diff / object_size. High rate plus a large gap "
               "usually means a genuine missing body; low rate with a large gap "
               "usually means frame or arrangement, not missing code.")
    out.append("")
    for rel in sorted(by_file, key=lambda f: -sum(x["window"] - x["object_size"]
                                                  for x in by_file[f])):
        fns = sorted(by_file[rel], key=lambda r: -(r["window"] - r["object_size"]))
        gap = sum(r["window"] - r["object_size"] for r in fns)
        out.append(f"## {rel.replace(chr(92), '/')} — {len(fns)} functions, {gap} bytes")
        out.append("")
        out.append("| deficit | nd | rate | obj/window | addr | function |")
        out.append("|---:|---:|---:|---|---|---|")
        for r in fns:
            d = r["window"] - r["object_size"]
            nd = r["normalized_diff"] or 0
            rate = nd / r["object_size"] if r["object_size"] else 0
            out.append(f"| {d} | {nd} | {rate:.2f} | "
                       f"{r['object_size']}/{r['window']} | {r['addr']} | {r['name']} |")
        out.append("")

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(sel)} functions, {total} bytes deficit")
    else:
        print(text)


main()
