#!/usr/bin/env python3
"""Branch-polarity census: branches retail tests the opposite way round.

W461 established that **inverting a branch and swapping its bodies is a legal,
semantics-preserving source rewrite** and that it is one of the most productive
mechanisms available:

    btlFormation func_002bb0b0    88 -> 60
    fclCombineMisc 003d7ac0/da0  338 -> 330 each
    itfMesManager FUN_003a30c0   134 ->  89
    fclShopMisc FUN_003fef30      15 ->   4   (part of a 97 -> 0 MATCH)

This finds every place it might apply.  Candidate and retail are difflib-
aligned (relocated fields neutralised), then each aligned pair is checked for
being the *same branch on the same registers with the opposite polarity*:

    beq  <-> bne          beql  <-> bnel
    blez <-> bgtz         blezl <-> bgtzl
    bltz <-> bgez         bltzl <-> bgezl
    bc1f <-> bc1t

A hit means retail wrote `if (C) A else B` where our source has
`if (!C) B else A` — or the reverse.  Rewriting the source condition and
swapping the two arms is exact, not a behaviour change.

`FLIPPED` rows are the actionable ones.  `SHIFTED` rows sit after an insertion
or deletion, so the pairing is less certain; treat them as a hint.

Usage:
  python tools/branch_census.py --report build/baselines/W461_gate.json \
                                --out build/wip/W462_branch.md
  python tools/branch_census.py --report <gate> --file src/Camp/h_camp.c
"""

from pathlib import Path
import argparse
import collections
import difflib
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, ObjectFile, RetailElf, compile_object,
                    load_config, mask_bytes, scan_markers, window_for)

THIRD_PARTY_DIRS = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}

# opcode -> (mnemonic, opposite opcode)
OPPOSITE_OP = {
    0x04: ("beq", 0x05), 0x05: ("bne", 0x04),
    0x14: ("beql", 0x15), 0x15: ("bnel", 0x14),
    0x06: ("blez", 0x07), 0x07: ("bgtz", 0x06),
    0x16: ("blezl", 0x17), 0x17: ("bgtzl", 0x16),
}
# REGIMM rt -> (mnemonic, opposite rt)
OPPOSITE_REGIMM = {
    0x00: ("bltz", 0x01), 0x01: ("bgez", 0x00),
    0x02: ("bltzl", 0x03), 0x03: ("bgezl", 0x02),
}
REGIMM, COP1, COP1_BC = 0x01, 0x11, 0x08
REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or any(norm.startswith(d) for d in THIRD_PARTY_DIRS))


def branch_form(word):
    """-> (mnemonic, register-signature, opposite-key) or None.

    `opposite-key` is what the *other* polarity of this branch would produce
    for the same registers, so two words are an inversion iff each one's key
    equals the other's identity.
    """
    if word < 0:
        return None
    op = word >> 26
    rs, rt = (word >> 21) & 0x1F, (word >> 16) & 0x1F
    if op in OPPOSITE_OP:
        mn, opp = OPPOSITE_OP[op]
        if op in (0x06, 0x07, 0x16, 0x17):          # rt must be zero
            if rt != 0:
                return None
            sig = "$%s" % REG[rs]
        else:
            sig = "$%s,$%s" % (REG[rs], REG[rt])
        return mn, sig, (opp, sig)
    if op == REGIMM and rt in OPPOSITE_REGIMM:
        mn, opprt = OPPOSITE_REGIMM[rt]
        sig = "$%s" % REG[rs]
        return mn, sig, ((REGIMM, opprt), sig)
    if op == COP1 and rs == COP1_BC and (rt & ~1) == 0:
        mn = "bc1t" if (rt & 1) else "bc1f"
        return mn, "cc0", ((COP1, rt ^ 1), "cc0")
    return None


def identity(word):
    op = word >> 26
    rt = (word >> 16) & 0x1F
    if op == REGIMM:
        return (REGIMM, rt)
    if op == COP1:
        return (COP1, rt)
    return op


def words_of(buf, mask=None):
    out = []
    for i in range(0, len(buf) - 3, 4):
        if mask is not None and any(mask[i:i + 4]):
            out.append(-1)
        else:
            out.append(int.from_bytes(buf[i:i + 4], "little"))
    return out


def flips_for_function(body, rels, target):
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = words_of(body, mask)
    ret = words_of(target, mask[:len(target)] if len(mask) >= len(target) else None)

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    out = []
    shifted = False
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag in ("insert", "delete"):
            shifted = True
            continue
        if tag != "replace":
            continue
        n = min(i2 - i1, j2 - j1)
        if (i2 - i1) != (j2 - j1):
            shifted = True
        for k in range(n):
            cf, rf = branch_form(cand[i1 + k]), branch_form(ret[j1 + k])
            if cf is None or rf is None:
                continue
            if cf[2] == (identity(ret[j1 + k]), rf[1]) and cf[1] == rf[1]:
                out.append({"offset": (i1 + k) * 4, "shifted": shifted,
                            "candidate": "%s %s" % (cf[0], cf[1]),
                            "retail": "%s %s" % (rf[0], rf[1])})
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
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

    findings = []
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3br_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print("  ! %s: compile failed" % path, file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    tgt = retail.bytes_at(addr, window_for(addr, bounds))
                    flips = flips_for_function(body, rels, tgt)
                    if flips:
                        findings.append({
                            "file": path, "addr": r["addr"], "name": r["name"],
                            "nd": r["normalized_diff"], "object": r["object_size"],
                            "window": r.get("window"), "flips": flips})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    def firm(f):
        return sum(1 for x in f["flips"] if not x["shifted"])

    findings.sort(key=lambda f: (-firm(f), f["nd"]))

    tot_firm = sum(firm(f) for f in findings)
    tot_all = sum(len(f["flips"]) for f in findings)
    firm_fns = [f for f in findings if firm(f)]

    lines = ["# Branch-polarity census", "",
             "Source report: `%s`" % args.report, "",
             "%d NONMATCHING functions contain at least one branch that retail "
             "tests the opposite way round; **%d of them have a FLIPPED row "
             "before any insertion**." % (len(findings), len(firm_fns)), "",
             "%d firm flips, %d total including shifted." % (tot_firm, tot_all), "",
             "Inverting the source condition and swapping the two arms is exact "
             "and legal — `if (x != 0) {A} else {B}` is identical to "
             "`if (x == 0) {B} else {A}`. This is distinct from changing a "
             "comparison's *meaning*, which is banned.", "",
             "W461 results from this mechanism: btlFormation `func_002bb0b0` "
             "88 -> 60, fclCombineMisc `003d7ac0`/`003d7da0` 338 -> 330 each, "
             "itfMesManager `FUN_003a30c0` 134 -> 89, and fclShopMisc "
             "`FUN_003fef30` 15 -> 4 on its way to MATCH.", "",
             "It is not universal: scrComuCommand `FUN_00361270` measured flat "
             "and an h_camp persona inversion went 23 -> 56 differing words. "
             "Measure each one.", ""]

    byfile = collections.Counter()
    for f in findings:
        byfile[f["file"]] += firm(f)
    lines += ["## Firm flips by file", "", "|file|firm flips|", "|---|---:|"]
    for f, n in byfile.most_common(30):
        if n:
            lines.append("|%s|%d|" % (f, n))

    lines += ["", "## Functions with a firm flip", ""]
    for f in firm_fns:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        lines.append("### `%s` %s — nd %d — %s — %s"
                     % (f["name"], f["addr"], f["nd"], win, f["file"]))
        lines.append("")
        for x in f["flips"][:12]:
            mark = " *" if x["shifted"] else ""
            lines.append("- offset %d%s: ours `%s`, retail `%s`"
                         % (x["offset"], mark, x["candidate"], x["retail"]))
        if len(f["flips"]) > 12:
            lines.append("- … %d more" % (len(f["flips"]) - 12))
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions (%d with a firm flip), %d firm / %d total -> %s"
              % (len(findings), len(firm_fns), tot_firm, tot_all, args.out))
    else:
        print(text)


if __name__ == "__main__":
    main()
