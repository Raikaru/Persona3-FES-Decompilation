"""Find near-duplicate functions, especially a NONMATCHING one whose twin MATCHes.

Two of the last three waves' best results came from twins and nobody was looking
for them deliberately:

* W451's only MATCHes — y_misc `0043c180` and `0043c340`, identical nd and
  identical object/window. One signed alias took both from nd 15 to 0.
* W452's largest cluster — fclShopMisc `003f86a0`, `003f8a00`, `003f8e10`, the
  same subject and constants. One conversion moved all three, −210 nd.

A cluster that contains a MATCH function is worth far more than either: the
matching sibling is a *worked example of the correct source* for that shape.
Diff the two bodies and the difference is the defect, with no disassembly at all.

    python tools/twin_census.py --report build/baselines/W452_gate.json \\
        --out build/wip/twins.md [--min-sim 0.72] [--scope file|dir]

Similarity is Jaccard over 5-token shingles of the normalised body: comments and
whitespace removed, integer literals folded to `#`, and Ghidra-style temporaries
(`uVar3`, `iStack_50`, `puVar11`, `local_28`, `param_4`, `fVar1`) folded to `$`,
so two functions differing only in temp numbering score 1.0. Symbol names are NOT
folded — `FUN_00320810` and `FUN_00320380` stay distinct, because a shared call
graph is exactly the signal worth keeping.
"""
import argparse
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
BLOCK = re.compile(r"/\*.*?\*/", re.S)
LINE = re.compile(r"//[^\n]*")
TEMP = re.compile(r"\b(?:[iufbslp]{1,3}(?:Var|Stack)_?\d+|local_[0-9a-fA-F]+|"
                  r"param_\d+|auStack_[0-9a-fA-F]+|[a-z]Stack_[0-9a-fA-F]+)\b")
NUM = re.compile(r"\b(?:0[xX][0-9a-fA-F]+|\d+)\b")
TOKEN = re.compile(r"[A-Za-z_][\w]*|[0-9#$]+|[^\s\w]")


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def shingles(text, k=5):
    text = LINE.sub(" ", BLOCK.sub(" ", text))
    text = TEMP.sub("$", text)
    text = NUM.sub("#", text)
    toks = TOKEN.findall(text)
    if len(toks) < k:
        return frozenset([" ".join(toks)]) if toks else frozenset()
    return frozenset(" ".join(toks[i:i + k]) for i in range(len(toks) - k + 1))


def bodies(rows):
    byfile = defaultdict(list)
    for r in rows:
        byfile[r["file"]].append(r)
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


def jaccard(a, b):
    if not a or not b:
        return 0.0
    inter = len(a & b)
    return inter / (len(a) + len(b) - inter)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--min-sim", type=float, default=0.42,
                    help="0.72 finds only near-identical twins and "
                         "reported ZERO clusters containing a MATCH; "
                         "0.42 finds 21, which is where the value is")
    ap.add_argument("--scope", choices=("file", "dir"), default="dir")
    ap.add_argument("--min-tokens", type=int, default=40,
                    help="skip bodies smaller than this; tiny stubs are all alike")
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    items = []
    for r, text in bodies(rows):
        if is3(r["file"]) or r["status"] not in ("MATCH", "NONMATCHING"):
            continue
        sh = shingles(text)
        if len(sh) < args.min_tokens:
            continue
        items.append((r, sh))

    groups = defaultdict(list)
    for r, sh in items:
        f = r["file"].replace("\\", "/")
        groups[f if args.scope == "file" else f.rsplit("/", 1)[0]].append((r, sh))

    # union-find over near-duplicates inside each group
    parent = {}

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[rb] = ra

    for r, _ in items:
        parent[r["addr"]] = r["addr"]
    for _key, v in groups.items():
        for i in range(len(v)):
            for j in range(i + 1, len(v)):
                if jaccard(v[i][1], v[j][1]) >= args.min_sim:
                    union(v[i][0]["addr"], v[j][0]["addr"])

    byaddr = {r["addr"]: r for r, _ in items}
    clusters = defaultdict(list)
    for a in parent:
        clusters[find(a)].append(byaddr[a])

    teach, pure, totals = [], [], Counter()
    for _root, members in clusters.items():
        if len(members) < 2:
            continue
        nm = [m for m in members if m["status"] == "NONMATCHING"]
        mt = [m for m in members if m["status"] == "MATCH"]
        if not nm:
            continue
        (teach if mt else pure).append((sorted(nm, key=lambda m: m["normalized_diff"]),
                                        sorted(mt, key=lambda m: m["addr"])))
        totals["CLUSTER_WITH_MATCH" if mt else "CLUSTER_ALL_NONMATCHING"] += 1
        totals["NONMATCHING_IN_CLUSTERS"] += len(nm)

    teach.sort(key=lambda c: -sum(m["normalized_diff"] for m in c[0]))
    pure.sort(key=lambda c: -sum(m["normalized_diff"] for m in c[0]))

    L = ["# Twin census — near-duplicate function bodies", ""]
    L.append("Similarity is Jaccard over 5-token shingles with temporaries and "
             "integer literals folded, so two functions differing only in "
             f"`uVarN` numbering score 1.0. Threshold {args.min_sim}, "
             f"scope: same {args.scope}.")
    L.append("")
    for k, v in totals.most_common():
        L.append(f"- {k} {v}")
    L.append("")
    L.append("## Clusters containing a MATCH — a worked example of correct source")
    L.append("")
    L.append("**Diff the NONMATCHING body against the MATCH one. The difference "
             "is the defect**, and no disassembly is needed to find it. This is "
             "the highest-value table in the file.")
    L.append("")
    L.append("| nd | NONMATCHING | already MATCH | file |")
    L.append("|---:|---|---|---|")
    for nm, mt in teach:
        for m in nm:
            L.append(f"| {m['normalized_diff']} | `{m['addr']}` {m['name']} | " +
                     ", ".join(f"`{x['addr']}` {x['name']}" for x in mt[:3]) +
                     f" | {m['file'].replace(chr(92), '/')} |")
    L.append("")
    L.append("## Clusters with no MATCH — fix one, fix all")
    L.append("")
    L.append("| total nd | members | file |")
    L.append("|---:|---|---|")
    for nm, _ in pure:
        L.append(f"| {sum(m['normalized_diff'] for m in nm)} | " +
                 ", ".join(f"`{m['addr']}` ({m['normalized_diff']})" for m in nm) +
                 f" | {nm[0]['file'].replace(chr(92), '/')} |")

    text = "\n".join(L) + "\n"
    for k, v in totals.most_common():
        print(f"{k:28s} {v}")
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}")
    else:
        print(text)


main()
