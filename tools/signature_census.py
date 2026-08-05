"""Classify every NONMATCHING function by its dominant ACTIONABLE mnemonic delta.

`opcode_census.py` ranks by a coarse semantic weight and truncates to the top
rows; `mnemonic_census.py` answers a question about one mnemonic you already
suspect.  This tool asks the open question: for each function, which specific
instruction-selection defect dominates, and therefore which source mechanism
should be reached for.

Every family below is tied to a mechanism the campaign has already measured, so
a row is a work order rather than an observation:

  NARROW    retail lacks `dsll32`/`dsra32`/`sll`+`sra` pairs we emit -- a local
            declared too narrow forces sign-extension.  Widen to s32/u32.
  CVT       `cvt.s.w`/`cvt.w.s` differ -- an int/float conversion one side does
            and the other does not.  A wrong declared type.
  XFER      `mfc1`/`mtc1` differ -- a value crossing the integer/FPU register
            boundary that should not, or should.  Usually downstream of CVT.
  MACFUSE   `madd.s`/`msub.s`/`adda.s`/`suba.s`/`mula.s` differ -- MWCC fused a
            multiply-add we should split, or vice versa.  Split with ONE reused
            temporary; distinct single-use temporaries fold straight back.
  NEG       `neg.s` -- retail spells a negation we fold away.  Hoist into a
            NAMED, REUSED local; inline `a + (-b)` is folded back.  Only works
            when retail's neg.s feeds an `add.s`, not a `mul.s`.
  ARITH     `mul.s`/`div.s`/`add.s`/`sub.s`/`sqrt.s`/`abs.s` -- genuinely
            missing or surplus computation.  Reconstruction, not spelling.
  CALL      `jal`/`jalr` -- a call genuinely absent or surplus.  Unlike the
            alignment-based misscall census this cannot be displacement.
  DIVMOD    integer `mult`/`div`/`multu`/`divu` -- a computation one side does.
  MEM       loads/stores -- liveness, or a float held in an integer register.
  BRANCH    control-flow shape; use the block census instead.
  OTHER     everything else.

Ranking is by the delta magnitude in the SEMANTIC families (everything except
MEM, BRANCH, MOVE and OTHER), because those name a computation present on one
side and absent on the other.  MEM and MOVE deltas are frequently downstream of
a semantic one -- fix the semantic row first and re-measure.

Multiset comparison aligns nothing, so these rows stay meaningful in the badly
aligned functions where most of the remaining residual sits.

    python tools/signature_census.py --report build/baselines/W470_gate.json \
        --out build/wip/W471_signature.md
"""
import argparse
import collections
import json
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from opcode_census import (                                    # noqa: E402
    REPO, TOOLS, RetailElf, compile_object, first_party,
    histogram, load_config, scan_markers, window_for, words_of,
)

FAMILY = {}
for m in ("dsll32", "dsra32", "dsrl32", "sll", "sra", "srl", "seb", "seh"):
    FAMILY[m] = "NARROW"
for m in ("cvt.s.w", "cvt.w.s"):
    FAMILY[m] = "CVT"
for m in ("mfc1", "mtc1", "cfc1", "ctc1"):
    FAMILY[m] = "XFER"
for m in ("madd.s", "msub.s", "adda.s", "suba.s", "mula.s", "madda.s",
          "msuba.s"):
    FAMILY[m] = "MACFUSE"
FAMILY["neg.s"] = "NEG"
for m in ("mul.s", "div.s", "add.s", "sub.s", "sqrt.s", "abs.s", "max.s",
          "min.s"):
    FAMILY[m] = "ARITH"
for m in ("jal", "jalr"):
    FAMILY[m] = "CALL"
for m in ("mult", "multu", "div", "divu", "dmult", "dmultu", "ddiv", "ddivu",
          "mfhi", "mflo", "mthi", "mtlo"):
    FAMILY[m] = "DIVMOD"
for m in ("lb", "lh", "lw", "lbu", "lhu", "lwu", "ld", "lq", "lwl", "lwr",
          "ldl", "ldr", "lwc1", "ldc1", "sb", "sh", "sw", "sd", "sq",
          "swl", "swr", "sdl", "sdr", "swc1", "sdc1"):
    FAMILY[m] = "MEM"
for m in ("j", "jr", "beq", "bne", "blez", "bgtz", "bltz", "bgez", "beql",
          "bnel", "blezl", "bgtzl", "bltzl", "bgezl", "bc1f", "bc1t",
          "bc1fl", "bc1tl", "c.f.s", "c.eq.s", "c.lt.s", "c.le.s"):
    FAMILY[m] = "BRANCH"
FAMILY["move"] = "MOVE"
FAMILY["mov.s"] = "MOVE"

SEMANTIC = ("NARROW", "CVT", "XFER", "MACFUSE", "NEG", "ARITH", "CALL",
            "DIVMOD")

# What to do about it, printed with the row so a lane needs no lookup.
REMEDY = {
    "NARROW": "widen a narrow local to s32/u32 (W464)",
    "CVT": "wrong declared type on an int/float value",
    "XFER": "value crossing int/FPU boundary; check CVT first",
    "MACFUSE": "split a*b+c with ONE reused temporary (W465)",
    "NEG": "named+reused negation local; only if neg.s feeds add.s (W469/470)",
    "ARITH": "missing or surplus computation -- reconstruction",
    "CALL": "call genuinely absent or surplus",
    "DIVMOD": "integer computation one side performs",
    "MEM": "liveness or int-held float; fix a semantic family first",
    "BRANCH": "control-flow shape -- use block_census instead",
    "MOVE": "allocation noise, downstream of something else",
    "OTHER": "-",
}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--min-margin", type=int, default=None,
                    help="drop rows with less window headroom than this")
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

    rows = []
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3sg_") as td:
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
                    fam = collections.Counter()
                    detail = collections.defaultdict(list)
                    for m in set(cand) | set(ret):
                        d = ret[m] - cand[m]
                        if d == 0:
                            continue
                        f = FAMILY.get(m, "OTHER")
                        fam[f] += abs(d)
                        detail[f].append((m, ret[m], cand[m], d))
                    sem = sum(fam[f] for f in SEMANTIC)
                    margin = (r.get("window") or 0) - (r.get("object_size") or 0)
                    if args.min_margin is not None and margin < args.min_margin:
                        continue
                    top = max((f for f in SEMANTIC if fam[f]),
                              key=lambda f: fam[f], default="none")
                    rows.append({
                        "name": r["name"], "file": path, "addr": r["addr"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "margin": margin,
                        "fam": fam, "detail": detail, "sem": sem, "top": top})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    rows.sort(key=lambda x: (-x["sem"], -x["nd"]))
    tot_fam = collections.Counter()
    pop = collections.Counter()
    nd_by_top = collections.Counter()
    for x in rows:
        tot_fam.update(x["fam"])
        pop[x["top"]] += 1
        nd_by_top[x["top"]] += x["nd"]

    clean = [x for x in rows if x["sem"] == 0]
    out = ["# Mnemonic-signature census", "",
           "Source report: `%s`" % args.report, "",
           "Every first-party NONMATCHING function classified by its dominant "
           "**semantic** instruction-selection delta. A positive delta means "
           "retail emits more. Multiset comparison aligns nothing, so these "
           "rows stay meaningful in badly-aligned functions.", "",
           "`sem` sums the semantic families (everything except MEM, BRANCH, "
           "MOVE, OTHER); those name a computation present on one side and "
           "absent on the other, which is a source defect. MEM and MOVE are "
           "frequently downstream -- fix a semantic row first and re-measure.",
           "",
           "**%d functions scanned. %d have a nonzero semantic delta (%d nd); "
           "%d are semantically clean (%d nd).**"
           % (len(rows), len(rows) - len(clean),
              sum(x["nd"] for x in rows if x["sem"]),
              len(clean), sum(x["nd"] for x in clean)), "",
           "## Population by dominant semantic family", "",
           "|family|functions|nd|total delta|remedy|",
           "|---|-:|-:|-:|---|"]
    for f in sorted(pop, key=lambda f: -nd_by_top[f]):
        out.append("|%s|%d|%d|%d|%s|"
                   % (f, pop[f], nd_by_top[f], tot_fam[f],
                      REMEDY.get(f, "-")))

    out += ["", "## Total delta by family, all functions", "",
            "|family|total delta|", "|---|-:|"]
    for f in sorted(tot_fam, key=lambda f: -tot_fam[f]):
        out.append("|%s|%d|" % (f, tot_fam[f]))

    out += ["", "## Functions with a semantic delta, ranked", "",
            "|#|function|file|nd|object/window|margin|sem|dominant|detail|",
            "|-:|---|---|-:|---|-:|-:|---|---|"]
    for i, x in enumerate([r for r in rows if r["sem"]], 1):
        bits = []
        for f in SEMANTIC:
            if not x["fam"][f]:
                continue
            inner = " ".join("`%s`%+d" % (m, d) for m, _r, _c, d
                             in sorted(x["detail"][f], key=lambda t: -abs(t[3])))
            bits.append("**%s** %s" % (f, inner))
        out.append("|%d|`%s`|`%s`|%d|%d/%s|%d|%d|%s|%s|"
                   % (i, x["name"], x["file"], x["nd"], x["object"],
                      x["window"], x["margin"], x["sem"], x["top"],
                      "; ".join(bits)))

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d rows (%d with semantic delta) -> %s"
              % (len(rows), len(rows) - len(clean), args.out))
        print("dominant-family population: %s" % dict(pop))
    else:
        print(text)


if __name__ == "__main__":
    main()
