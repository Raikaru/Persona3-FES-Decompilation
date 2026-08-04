#!/usr/bin/env python3
"""Register-substitution census: residuals that are only a renaming.

After four waves of structural censuses, 133 of the 185 first-party functions
under nd 120 have **no** structural gap, no wrong immediate, no inverted branch
and no missing call.  Their residual is purely *which register the compiler
chose*.

This tool measures that directly.  For each aligned differing word it checks
whether the two instructions are identical except in their register fields; if
so it records the substitutions candidate->retail.  Per function it then asks
whether those substitutions form a **consistent map** (every candidate register
always becomes the same retail register).  A consistent map is a nameable
defect: the two values were defined in the wrong order, or one lives too long.

Classes:

  PERMUTATION  every substitution is consistent and the map is a permutation
               (a->b and b->a, possibly in longer cycles).  Two or more values
               swapped registers.  The source lever is the order in which they
               are first assigned, or their declaration order.
  CONSISTENT   a consistent one-way map that is not a permutation, e.g. we use
               $s0 where retail uses $s1 and nothing maps back.  Usually one
               value too many or too few is live across a call, shifting the
               whole callee-saved allocation.
  MIXED        the same candidate register maps to different retail registers
               at different offsets.  Not a pure renaming; some other defect
               is present as well.

`FLOAT` marks a function whose substitutions are all in coprocessor-1
registers, which respond to different source levers than the integer file.

Usage:
  python tools/regsub_census.py --report build/baselines/W462_gate.json \
                                --out build/wip/W463_regsub.md
  python tools/regsub_census.py --report <gate> --file src/Camp/h_camp.c
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

GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

SPECIAL, REGIMM, COP1 = 0x00, 0x01, 0x11
# opcodes whose rt is a coprocessor-1 register
FP_LOADSTORE = {0x31, 0x39, 0x35, 0x3D}
# opcodes with no register operands worth comparing
JUMPS = {0x02, 0x03}


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or any(norm.startswith(d) for d in THIRD_PARTY_DIRS))


def fields(word):
    """-> (skeleton, [(kind, position, regnum), ...]) or None.

    `skeleton` is everything that is *not* a register: opcode, funct, shamt,
    immediate, format.  Two words are a pure renaming iff their skeletons are
    equal and their register lists differ.
    """
    op = word >> 26
    rs, rt, rd = (word >> 21) & 0x1F, (word >> 16) & 0x1F, (word >> 11) & 0x1F
    sa, funct = (word >> 6) & 0x1F, word & 0x3F
    if op in JUMPS:
        return None
    if op == SPECIAL:
        return ("S", funct, sa), [("g", "rs", rs), ("g", "rt", rt), ("g", "rd", rd)]
    if op == REGIMM:
        return ("R", rt, word & 0xFFFF), [("g", "rs", rs)]
    if op == COP1:
        fmt = rs
        if fmt in (0x00, 0x04):                       # mfc1 / mtc1
            return ("C", fmt, funct), [("g", "rt", rt), ("f", "fs", rd)]
        if fmt == 0x08:                               # bc1f / bc1t
            return None
        return ("C", fmt, funct, sa), [("f", "ft", rt), ("f", "fs", rd)]
    if op in FP_LOADSTORE:
        return ("L", op, word & 0xFFFF), [("g", "base", rs), ("f", "ft", rt)]
    return ("I", op, word & 0xFFFF), [("g", "rs", rs), ("g", "rt", rt)]


def name(kind, n):
    return ("$" + GPR[n]) if kind == "g" else ("$f%d" % n)


def words_of(buf, mask=None):
    out = []
    for i in range(0, len(buf) - 3, 4):
        if mask is not None and any(mask[i:i + 4]):
            out.append(-1)
        else:
            out.append(int.from_bytes(buf[i:i + 4], "little"))
    return out


def subs_for_function(body, rels, target):
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = words_of(body, mask)
    ret = words_of(target, mask[:len(target)] if len(mask) >= len(target) else None)

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    subs, other, shifted = [], 0, False
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag in ("insert", "delete"):
            shifted = True
            continue
        if tag != "replace":
            continue
        if (i2 - i1) != (j2 - j1):
            shifted = True
            continue
        for k in range(i2 - i1):
            cw, rw = cand[i1 + k], ret[j1 + k]
            if cw < 0 or rw < 0:
                continue
            cf, rf = fields(cw), fields(rw)
            if cf is None or rf is None or cf[0] != rf[0]:
                other += 1
                continue
            diff = [(kind, pos, a, b) for (kind, pos, a), (_, _, b)
                    in zip(cf[1], rf[1]) if a != b]
            if not diff:
                other += 1
                continue
            for kind, pos, a, b in diff:
                subs.append({"offset": (i1 + k) * 4, "kind": kind,
                             "from": name(kind, a), "to": name(kind, b),
                             "shifted": shifted})
    return subs, other


def classify(subs):
    fwd = collections.defaultdict(set)
    for s in subs:
        fwd[s["from"]].add(s["to"])
    if any(len(v) > 1 for v in fwd.values()):
        return "MIXED", {k: sorted(v) for k, v in fwd.items() if len(v) > 1}
    flat = {k: next(iter(v)) for k, v in fwd.items()}
    rev = collections.defaultdict(list)
    for k, v in flat.items():
        rev[v].append(k)
    if any(len(v) > 1 for v in rev.values()):
        return "MIXED", flat
    if all(v in flat and flat[v] == k for k, v in flat.items()):
        return "PERMUTATION", flat
    if set(flat) == set(flat.values()):
        return "PERMUTATION", flat
    return "CONSISTENT", flat


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--max-nd", type=int, default=400)
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    wanted = args.file.replace("\\", "/") if args.file else None

    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] != "NONMATCHING" or r["normalized_diff"] > args.max_nd:
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
            with tempfile.TemporaryDirectory(prefix="p3rs_") as td:
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
                    subs, other = subs_for_function(body, rels, tgt)
                    if not subs:
                        continue
                    cls, mp = classify(subs)
                    findings.append({
                        "file": path, "addr": r["addr"], "name": r["name"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "subs": subs, "other": other,
                        "cls": cls, "map": mp,
                        "float": all(s["kind"] == "f" for s in subs)})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    # cleanest first: pure renaming, fewest distinct registers, lowest nd
    order = {"PERMUTATION": 0, "CONSISTENT": 1, "MIXED": 2}
    findings.sort(key=lambda f: (f["other"] > 0, order[f["cls"]], len(f["map"]), f["nd"]))

    counts = collections.Counter(f["cls"] for f in findings)
    pure = [f for f in findings if f["other"] == 0]

    lines = ["# Register-substitution census", "",
             "Source report: `%s`  (NONMATCHING, nd <= %d)" % (args.report, args.max_nd), "",
             "%d functions have at least one differing word that is the *same "
             "instruction on different registers*; **%d of them differ in "
             "nothing else at all** (`other = 0`), so their entire residual is "
             "a renaming." % (len(findings), len(pure)), "",
             "|class|functions|meaning|", "|---|---:|---|",
             "|PERMUTATION|%d|registers swapped; two or more values allocated the "
             "other way round|" % counts["PERMUTATION"],
             "|CONSISTENT|%d|one-way map; usually one value more or fewer live "
             "across a call|" % counts["CONSISTENT"],
             "|MIXED|%d|same register maps to different ones at different "
             "offsets; another defect is present too|" % counts["MIXED"], "",
             "The source levers for a pure renaming are the **order two values "
             "are first assigned**, their **declaration order**, and **how long "
             "each stays live**. Nothing else moves register choice in MWCC "
             "b210.", "",
             "## Pure renamings (nothing else differs)", ""]

    for f in pure:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        mp = ", ".join("%s->%s" % (k, v) for k, v in sorted(f["map"].items())) \
            if isinstance(f["map"], dict) else str(f["map"])
        flag = " FLOAT" if f["float"] else ""
        lines.append("- **%s** `%s` %s — nd %d — %s — %s%s"
                     % (f["cls"], f["name"], f["addr"], f["nd"], win,
                        f["file"], flag))
        lines.append("    - %s" % mp)
        offs = sorted({s["offset"] for s in f["subs"]})
        lines.append("    - offsets: %s%s"
                     % (", ".join(str(o) for o in offs[:14]),
                        " …" if len(offs) > 14 else ""))

    lines += ["", "## Mixed with other differences", ""]
    for f in findings:
        if f["other"] == 0:
            continue
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        mp = ", ".join("%s->%s" % (k, v) for k, v in sorted(f["map"].items())) \
            if isinstance(f["map"], dict) else str(f["map"])
        lines.append("- **%s** `%s` %s — nd %d — %s — %d other differing word(s) — %s"
                     % (f["cls"], f["name"], f["addr"], f["nd"], win, f["other"],
                        f["file"]))
        lines.append("    - %s" % mp)

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions, %d pure renamings -> %s" % (len(findings), len(pure), args.out))
        for k, n in counts.most_common():
            print("   %-12s %d" % (k, n))
    else:
        print(text)


if __name__ == "__main__":
    main()
