"""Per-mnemonic multiset census, unranked and untruncated.

`opcode_census.py` ranks by semantic weight and writes only the top rows, which
hides small but highly actionable deltas.  This tool emits EVERY function whose
histogram differs in one of the mnemonics you ask for, with the retail and
candidate counts side by side and the window margin joined in.

The motivating case is W469's construct 8: retail spells a subtraction as
`neg.s` + `add.s` where the candidate emits `sub.s`.  Writing `a + (-b)` inline
is folded straight back by MWCC; hoisting the negation into a NAMED, REUSED
local defeats the fold.  The stopping rule is countable -- convert until the
candidate's `neg.s` count equals retail's.

Because this compares multisets it is invariant under scheduling, register
allocation, block placement and branch polarity, so unlike the alignment-based
censuses it stays meaningful in badly-aligned functions.

    python tools/mnemonic_census.py --report build/baselines/W469_gate.json \
        --mnemonic neg.s --out build/wip/W470_negation.md

`--mnemonic` may be repeated.  `--direction retail` (default) keeps only rows
where retail emits MORE of it than we do; `candidate` inverts; `both` keeps
either.
"""
import argparse
import collections
import json
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from opcode_census import (                                    # noqa: E402
    CLASS, REPO, TOOLS, RetailElf, compile_object, first_party,
    histogram, load_config, scan_markers, window_for, words_of,
)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--mnemonic", action="append", required=True)
    ap.add_argument("--direction", choices=("retail", "candidate", "both"),
                    default="retail")
    ap.add_argument("--min-margin", type=int, default=0)
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

    # Companion mnemonics reported alongside, for context on the fix shape.
    context = ("sub.s", "add.s", "mul.s", "div.s", "abs.s", "madd.s", "msub.s")
    rows = []
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3mn_") as td:
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
                    cand = histogram(words_of(body))
                    ret = histogram(words_of(tgt))
                    hits = []
                    for m in args.mnemonic:
                        d = ret[m] - cand[m]
                        if args.direction == "retail" and d <= 0:
                            continue
                        if args.direction == "candidate" and d >= 0:
                            continue
                        if args.direction == "both" and d == 0:
                            continue
                        hits.append((m, ret[m], cand[m], d))
                    if not hits:
                        continue
                    margin = (r.get("window") or 0) - (r.get("object_size") or 0)
                    if margin < args.min_margin:
                        continue
                    rows.append({
                        "file": path, "name": r["name"], "addr": r["addr"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "margin": margin,
                        "hits": hits,
                        "context": {m: (ret[m], cand[m]) for m in context
                                    if ret[m] or cand[m]}})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    rows.sort(key=lambda x: (-sum(abs(h[3]) for h in x["hits"]), -x["nd"]))
    total_nd = sum(x["nd"] for x in rows)
    total_d = sum(sum(abs(h[3]) for h in x["hits"]) for x in rows)

    out = ["# Per-mnemonic multiset census", "",
           "Source report: `%s`" % args.report,
           "Mnemonics: %s  ---  direction: retail emits %s"
           % (", ".join("`%s`" % m for m in args.mnemonic),
              {"retail": "MORE", "candidate": "FEWER",
               "both": "a DIFFERENT number"}[args.direction]), "",
           "**%d functions / %d nd / %d total instruction delta.**"
           % (len(rows), total_nd, total_d), "",
           "Multiset comparison aligns nothing, so these rows stay meaningful "
           "in badly-aligned functions. `margin` is `window - object_size`; a "
           "`neg.s` costs 4 bytes, so a conversion needs margin to spare.", "",
           "|#|function|file|nd|object/window|margin|delta|retail/candidate|"
           "companion counts (retail/candidate)|",
           "|-:|---|---|-:|---|-:|-:|---|---|"]
    for i, x in enumerate(rows, 1):
        hit = "; ".join("`%s` %+d" % (m, d) for m, _r, _c, d in x["hits"])
        rc = "; ".join("%d/%d" % (r, c) for _m, r, c, _d in x["hits"])
        ctx = " ".join("`%s` %d/%d" % (m, v[0], v[1])
                       for m, v in sorted(x["context"].items()))
        out.append("|%d|`%s`|`%s`|%d|%d/%s|%d|%s|%s|%s|"
                   % (i, x["name"], x["file"], x["nd"], x["object"],
                      x["window"], x["margin"], hit, rc, ctx))

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d rows -> %s" % (len(rows), args.out))
    else:
        print(text)


if __name__ == "__main__":
    main()
