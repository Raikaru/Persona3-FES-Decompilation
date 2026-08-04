"""Rank functions whose stack frame is LARGER than retail's, with the likely cause.

W453's h_camp lane produced the campaign's sharpest unexplained diagnostic:
retail's frame for the `0015e150` cluster is -0x70 and ours is -0xc0. Eighty
bytes of stack we allocate and retail does not. That is not a symptom of the
residual, it is the CAUSE of the over-window wall — every probe on that family
died at the window because the frame was already 80 bytes too big.

`tools/prologue_census.py` classifies frame mismatches; this ranks the ones that
cost us bytes and names the source constructs that force stack residency, so a
lane can go straight at the local rather than at the codegen.

MWCC puts a local in memory when it cannot keep it in a register. In this
codebase that is nearly always one of:

  ADDRESS_TAKEN  `&local` appears — the local and anything aliased through it
                 are pinned to the frame.
  AGGREGATE      an array or struct local retail never had; retail reads the
                 fields directly and never materialises the object.
  MANY_LOCALS    more live values than registers, so the allocator spills.

    python tools/frame_census.py --report build/baselines/W453_gate.json \\
        --out build/wip/frames.md [--min-delta 16]

`excess` is our frame minus retail's, in bytes. `slack` is window minus object
size: negative means the function is already over its window, and for those the
frame excess is usually the entire reason.
"""
import argparse
import json
import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify as V  # noqa: E402
from prologue_census import decode_prologue, words_of  # noqa: E402

REPO = Path(__file__).resolve().parents[1]
TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
BLOCK = re.compile(r"/\*.*?\*/", re.S)
LINE = re.compile(r"//[^\n]*")
ADDROF = re.compile(r"&\s*([A-Za-z_]\w*)")
# `u8 buf[32];`, `RwV3d pos;`, `struct Foo bar[2];` at statement start
AGG = re.compile(r"^\s*(?:const\s+|static\s+|volatile\s+|struct\s+|union\s+)*"
                 r"[A-Za-z_]\w*\s*\**\s*([A-Za-z_]\w*)\s*\[", re.M)
DECL = re.compile(r"^\s*(?:const\s+|static\s+|volatile\s+|struct\s+|union\s+)*"
                  r"(?:u8|s8|u16|s16|u32|s32|f32|int|char|short|long|float|"
                  r"double|void|[A-Z]\w*)\s+\**\s*[A-Za-z_]\w*\s*[;,=\[]", re.M)


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def bodies(rows):
    byfile = {}
    for r in rows:
        byfile.setdefault(r["file"], []).append(r)
    out = {}
    for f, v in byfile.items():
        v.sort(key=lambda r: r["line"])
        try:
            lines = (REPO / f.replace("\\", "/")).read_text(
                errors="replace").split("\n")
        except OSError:
            continue
        for i, r in enumerate(v):
            end = v[i + 1]["line"] - 1 if i + 1 < len(v) else len(lines)
            out[r["addr"]] = "\n".join(lines[r["line"] - 1:end])
    return out


def cause(text):
    """Source constructs that force stack residency, most specific first."""
    text = LINE.sub(" ", BLOCK.sub(" ", text))
    taken = sorted(set(ADDROF.findall(text)))
    aggs = sorted(set(AGG.findall(text)))
    nloc = len(DECL.findall(text))
    tags = []
    if taken:
        tags.append(("ADDRESS_TAKEN", ", ".join("`&" + t + "`" for t in taken[:6])))
    if aggs:
        tags.append(("AGGREGATE", ", ".join("`" + a + "[]`" for a in aggs[:6])))
    if not tags and nloc >= 12:
        tags.append(("MANY_LOCALS", f"{nloc} declarations"))
    return tags or [("UNKNOWN", "")]


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--min-delta", type=int, default=8)
    args = ap.parse_args()

    cfg = V.load_config()
    elf = V.RetailElf(cfg["retail_elf"], cfg.get("retail_sha1"))
    rows = json.loads(Path(args.report).read_text())["results"]
    src = bodies(rows)

    want = {}
    for r in rows:
        if is3(r["file"]) or r["status"] != "NONMATCHING":
            continue
        if not r.get("window") or not r.get("object_size"):
            continue
        want.setdefault(r["file"].replace("\\", "/"), []).append(r)

    import tempfile
    objdir = Path(tempfile.mkdtemp())
    hits, totals = [], Counter()
    for i, (f, funcs) in enumerate(sorted(want.items()), 1):
        obj, _log = V.compile_object(V.REPO / f, cfg, objdir)
        if obj is None:
            print(f"  [{i}/{len(want)}] COMPILE FAIL {f}", file=sys.stderr)
            continue
        for r in funcs:
            try:
                body, _ = obj.function(r["name"])
            except KeyError:
                continue
            of, _ = decode_prologue(words_of(body))
            rf, _ = decode_prologue(
                words_of(elf.bytes_at(int(r["addr"], 16), min(r["window"], 192))))
            if of is None or rf is None:
                continue
            delta = of - rf
            totals["OUR_FRAME_LARGER" if delta > 0 else
                   "RETAIL_FRAME_LARGER" if delta < 0 else "EQUAL"] += 1
            if delta >= args.min_delta:
                hits.append((delta, r, cause(src.get(r["addr"], ""))))

    hits.sort(key=lambda h: (-h[0], -(h[1].get("normalized_diff") or 0)))
    L = ["# Frame-excess census — stack we allocate and retail does not", ""]
    L.append("`excess` is our frame minus retail's. `slack` is window minus "
             "object size; **negative slack means the function is already over "
             "its window, and the frame excess is usually the whole reason** — "
             "no amount of instruction-level work will fit it until the frame "
             "shrinks.")
    L.append("")
    L.append("Remove the local, not the codegen. `&local` pins that local and "
             "everything aliased through it; an array or struct local retail "
             "never had costs its full size.")
    L.append("")
    for k, v in totals.most_common():
        L.append(f"- {k} {v}")
    L.append("")
    L.append("| excess | nd | slack | addr | likely cause | detail | file |")
    L.append("|---:|---:|---:|---|---|---|---|")
    for delta, r, tags in hits:
        slack = r["window"] - r["object_size"]
        kinds = "/".join(t[0] for t in tags)
        detail = "; ".join(t[1] for t in tags if t[1])
        L.append(f"| {delta} | {r['normalized_diff']} | {slack} | "
                 f"`{r['addr']}` | {kinds} | {detail} | "
                 f"{r['file'].replace(chr(92), '/')} |")
    text = "\n".join(L) + "\n"
    for k, v in totals.most_common():
        print(f"{k:22s} {v}")
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(hits)} functions")
    else:
        print(text)


main()
