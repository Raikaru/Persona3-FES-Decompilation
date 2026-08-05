"""Detect retail functions that were NOT built by MWCC.

Premise (from parallel Persona 4 work): MWCCPS2 and EE GCC differ in which
scratch register they use to materialise a global address.  A "first-party"
retail function showing the GCC convention would be misclassified third-party
code that no amount of MWCC source shaping can ever match.

An ABSOLUTE test on retail alone does NOT work: "retail `$v0` dominates" flags
37% of the MATCHing first-party functions, which MWCC provably built from our
own source.  MWCC uses `$v0` freely and the register alone carries little
information.

So this is a DIFFERENTIAL test.  Each function's retail profile is compared
against our own MWCC-compiled candidate for the SAME function, which supplies a
per-function control, and a balance gate drops rows where retail simply emits
far more `lui` than we do -- that is the W467 `to_abs` addressing mechanism,
not a register convention.  Against 493 MATCHing controls with signal the
false-positive rate is 0%.

    python tools/toolchain_census.py --report build/baselines/W469_gate.json \
        --control --out build/wip/W470_toolchain.md

Read the verdict as a prior, not a proof.  Confirm with `tools/decompme.py
--try <addr> --against ee-gcc2.96,mwcps2-3.0.1b210-060308`, which compiles the
function under each candidate toolchain and scores it against retail.  The
first P3FES row tested this way, `func_001b02c0`, came back MWCC 5653 against
ee-gcc 21825 -- a false positive, and evidence P3FES may be single-toolchain
where P4 is mixed.
"""
import argparse
import collections
import json
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from opcode_census import (                                    # noqa: E402
    REPO, TOOLS, RetailElf, compile_object, first_party, load_config,
    scan_markers, window_for, words_of,
)

LUI = 0x0F
REG = {2: "v0", 3: "v1"}


def lui_profile(words):
    """Count lui by destination register, plus the total."""
    hist = collections.Counter()
    total = 0
    for w in words:
        if w < 0 or w == 0:
            continue
        if (w >> 26) == LUI:
            total += 1
            hist[(w >> 16) & 0x1F] += 1
    return hist, total


def skew(hist):
    """+1.0 = all $v0, -1.0 = all $v1, None = neither register used."""
    v0, v1 = hist[2], hist[3]
    if v0 + v1 == 0:
        return None
    return (v0 - v1) / float(v0 + v1)


def verdict(cand, ret):
    """Differential: retail's skew minus our MWCC candidate's skew."""
    cs, rs = skew(cand), skew(ret)
    if cs is None or rs is None:
        return "no signal"
    if cand[2] + cand[3] < 4 or ret[2] + ret[3] < 4:
        return "too few"
    # Balance gate.  If retail emits far more `lui` than we do, the difference
    # is the ADDRESSING MODE (retail materialises absolutely where we go
    # through $gp -- the W467 `to_abs` mechanism), not the register
    # convention, and the skew comparison is meaningless.  Require the two
    # sides to emit comparable numbers of `lui` before reading the register.
    ct, rt = cand[2] + cand[3], ret[2] + ret[3]
    if max(ct, rt) > 1.6 * min(ct, rt):
        return "unbalanced (addressing mode)"

    delta = rs - cs                       # positive => retail leans $v0 more
    if delta >= 1.2 and ret[3] == 0:
        return "GCC (retail $v1 absent)"
    if delta >= 1.0:
        return "GCC likely"
    if delta >= 0.6:
        return "leaning GCC"
    if delta <= -0.6:
        return "inverted (we use $v0)"
    return "agree"


FLAG = ("GCC", "leaning")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--control", action="store_true",
                    help="also profile MATCHing functions as a control group")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    wanted = args.file.replace("\\", "/") if args.file else None

    keep = {"NONMATCHING"} | ({"MATCH"} if args.control else set())
    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] not in keep:
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

    rows, control = [], collections.Counter()
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3tc_") as td:
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
                    cand, _ = lui_profile(words_of(body))
                    ret, _ = lui_profile(words_of(tgt))
                    v = verdict(cand, ret)
                    if r["status"] == "MATCH":
                        control[v] += 1
                        continue
                    rows.append({
                        "name": r["name"], "file": path,
                        "nd": r.get("normalized_diff") or 0,
                        "object": r.get("object_size"), "window": r.get("window"),
                        "cv0": cand[2], "cv1": cand[3],
                        "rv0": ret[2], "rv1": ret[3], "verdict": v})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    flagged = [x for x in rows if x["verdict"].startswith(FLAG)]
    flagged.sort(key=lambda x: -x["nd"])
    per_file, nd_file = collections.Counter(), collections.Counter()
    for x in flagged:
        per_file[x["file"]] += 1
        nd_file[x["file"]] += x["nd"]

    out = ["# Toolchain census -- `lui` destination register, differential", "",
           "Source report: `%s`" % args.report, "",
           "MWCC and EE GCC differ in which scratch register they use to "
           "materialise a global address. A first-party retail function built "
           "by GCC is misclassified third-party code and unmatchable from "
           "MWCC source.", "",
           "**Differential test.** An absolute \"retail uses `$v0`\" rule flags "
           "37% of the MATCHing first-party functions, which MWCC provably "
           "built from our own source, so the register alone carries little "
           "information. Each function's retail profile is instead compared "
           "against our own MWCC-compiled candidate for the same function, "
           "which supplies a per-function control. The signal is retail "
           "leaning `$v0` while our MWCC build leans `$v1`.", "",
           "`skew` = (v0-v1)/(v0+v1); the verdict keys off retail skew minus "
           "candidate skew.", "",
           "**%d of %d first-party NONMATCHING functions flagged (%d nd).**"
           % (len(flagged), len(rows), sum(x["nd"] for x in flagged)), ""]

    if args.control:
        tot = sum(control.values()) or 1
        bad = sum(v for k, v in control.items() if k.startswith(FLAG))
        out += ["## Control: MATCHing first-party functions", "",
                "Provably MWCC-built. A sound instrument flags almost none.", ""]
        for k in sorted(control, key=lambda k: -control[k]):
            out.append("- `%s`: %d (%.1f%%)"
                       % (k, control[k], 100.0 * control[k] / tot))
        out += ["", "**False-positive rate: %.1f%% (%d of %d).**"
                % (100.0 * bad / tot, bad, tot), ""]

    out += ["## Flagged NONMATCHING functions", "",
            "|#|function|file|nd|object/window|cand v0/v1|retail v0/v1|verdict|",
            "|-:|---|---|-:|---|---|---|---|"]
    for i, x in enumerate(flagged, 1):
        out.append("|%d|`%s`|`%s`|%d|%s/%s|%d/%d|%d/%d|%s|"
                   % (i, x["name"], x["file"], x["nd"], x["object"],
                      x["window"], x["cv0"], x["cv1"], x["rv0"], x["rv1"],
                      x["verdict"]))

    out += ["", "## Flagged counts by file", "", "|file|functions|nd|",
            "|---|-:|-:|"]
    for f in sorted(per_file, key=lambda f: -nd_file[f]):
        out.append("|`%s`|%d|%d|" % (f, per_file[f], nd_file[f]))

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d flagged of %d scanned -> %s"
              % (len(flagged), len(rows), args.out))
        if args.control:
            print("control verdicts: %s" % dict(control))
    else:
        print(text)


if __name__ == "__main__":
    main()
