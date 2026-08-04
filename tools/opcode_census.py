#!/usr/bin/env python3
"""Opcode-histogram census: what a function DOES, independent of layout.

W464 established the limit of every census this campaign has built so far.
`imm_census`, `gap_census`, `branch_census`, `regsub_census` and
`width_census` all align candidate against retail with difflib and then read
meaning off the offsets where they differ.  That works while a function is
mostly byte-identical.  Above roughly 30% divergence the alignment is an
artefact, and six lanes in W464 removed exactly the instructions a census row
named only to watch the metric refuse to move or go sharply worse.

Which leaves the bulk of the remaining work unaddressed: 1,303 first-party
functions, and the nd mass is concentrated in exactly the badly-aligned ones
those tools cannot read.

This census does not align anything.  It compares the MULTISET of instruction
mnemonics on each side.  A multiset difference is invariant under scheduling,
register allocation, block placement and branch polarity -- every degree of
freedom that makes alignment unreliable -- so what survives is a statement
about content:

    retail executes four more `mul.s` than we do
    we execute six more `lw` than retail
    retail has a `div` we never emit

That is a semantic claim about the source, not a layout observation.  A missing
`mul.s` means an arithmetic term our reconstruction does not compute.  A
surplus `lw` means we reload something retail keeps live.  A `jal` count
mismatch means a call is genuinely absent, not displaced -- which is the
distinction W461 had to make by hand across ten lanes.

Rows are grouped so the diagnosis is legible:

  FPU        float arithmetic -- a missing term in an expression
  MULDIV     integer multiply/divide -- a missing computation
  MEM        loads and stores -- liveness and reload behaviour
  CALL       jal/jalr -- genuinely absent or surplus calls
  BRANCH     branch and jump density -- control-flow shape
  MOVE       register moves -- allocation noise, usually ignorable
  OTHER      everything else

`--min-delta` filters rows; the default of 2 suppresses single-instruction
noise.  Functions are ranked by the weight of their semantic classes (FPU,
MULDIV and CALL count double) because those name a missing computation, while
MEM and MOVE deltas are frequently downstream of one.

Usage:
    python tools/opcode_census.py --report build/baselines/W464_gate.json \
                                  --out build/wip/W465_opcode.md [--file src/x.c]
"""

from pathlib import Path
import argparse
import collections
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, RetailElf, compile_object, load_config,
                    mask_bytes, scan_markers, window_for)
from regsub_census import first_party, words_of

SPECIAL, REGIMM, COP1 = 0x00, 0x01, 0x11

OPCODE = {
    0x02: "j", 0x03: "jal", 0x04: "beq", 0x05: "bne", 0x06: "blez",
    0x07: "bgtz", 0x08: "addi", 0x09: "addiu", 0x0A: "slti", 0x0B: "sltiu",
    0x0C: "andi", 0x0D: "ori", 0x0E: "xori", 0x0F: "lui",
    0x14: "beql", 0x15: "bnel", 0x16: "blezl", 0x17: "bgtzl",
    0x18: "daddi", 0x19: "daddiu", 0x1A: "ldl", 0x1B: "ldr",
    0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw", 0x24: "lbu",
    0x25: "lhu", 0x26: "lwr", 0x27: "lwu", 0x28: "sb", 0x29: "sh",
    0x2A: "swl", 0x2B: "sw", 0x2C: "sdl", 0x2D: "sdr", 0x2E: "swr",
    0x30: "ll", 0x31: "lwc1", 0x33: "pref", 0x35: "ldc1", 0x36: "lq",
    0x37: "ld", 0x38: "sc", 0x39: "swc1", 0x3D: "sdc1", 0x3E: "sq",
    0x3F: "sd",
}
FUNCT = {
    0x00: "sll", 0x02: "srl", 0x03: "sra", 0x04: "sllv", 0x06: "srlv",
    0x07: "srav", 0x08: "jr", 0x09: "jalr", 0x0A: "movz", 0x0B: "movn",
    0x0C: "syscall", 0x0D: "break", 0x0F: "sync",
    0x10: "mfhi", 0x11: "mthi", 0x12: "mflo", 0x13: "mtlo",
    0x14: "dsllv", 0x16: "dsrlv", 0x17: "dsrav",
    0x18: "mult", 0x19: "multu", 0x1A: "div", 0x1B: "divu",
    0x1C: "dmult", 0x1D: "dmultu", 0x1E: "ddiv", 0x1F: "ddivu",
    0x20: "add", 0x21: "addu", 0x22: "sub", 0x23: "subu", 0x24: "and",
    0x25: "or", 0x26: "xor", 0x27: "nor", 0x2A: "slt", 0x2B: "sltu",
    0x2C: "dadd", 0x2D: "daddu", 0x2E: "dsub", 0x2F: "dsubu",
    0x38: "dsll", 0x3A: "dsrl", 0x3B: "dsra", 0x3C: "dsll32",
    0x3E: "dsrl32", 0x3F: "dsra32",
}
COP1_FUNCT = {
    0x00: "add.s", 0x01: "sub.s", 0x02: "mul.s", 0x03: "div.s",
    0x04: "sqrt.s", 0x05: "abs.s", 0x06: "mov.s", 0x07: "neg.s",
    0x18: "adda.s", 0x19: "suba.s", 0x1A: "mula.s", 0x1C: "madd.s",
    0x1D: "msub.s", 0x1E: "madda.s", 0x1F: "msuba.s",
    0x24: "cvt.w.s", 0x20: "cvt.s.w", 0x28: "max.s", 0x29: "min.s",
    0x30: "c.f.s", 0x32: "c.eq.s", 0x34: "c.lt.s", 0x36: "c.le.s",
}
COP1_RS = {0x00: "mfc1", 0x02: "cfc1", 0x04: "mtc1", 0x06: "ctc1"}

CLASS = {}
for m in ("add.s", "sub.s", "mul.s", "div.s", "sqrt.s", "abs.s", "neg.s",
          "adda.s", "suba.s", "mula.s", "madd.s", "msub.s", "madda.s",
          "msuba.s", "max.s", "min.s", "cvt.w.s", "cvt.s.w",
          "c.f.s", "c.eq.s", "c.lt.s", "c.le.s"):
    CLASS[m] = "FPU"
for m in ("mult", "multu", "div", "divu", "dmult", "dmultu", "ddiv", "ddivu",
          "mfhi", "mflo", "mthi", "mtlo"):
    CLASS[m] = "MULDIV"
for m in ("lb", "lh", "lw", "lbu", "lhu", "lwu", "ld", "lq", "lwl", "lwr",
          "ldl", "ldr", "lwc1", "ldc1", "sb", "sh", "sw", "sd", "sq",
          "swl", "swr", "sdl", "sdr", "swc1", "sdc1", "ll", "sc"):
    CLASS[m] = "MEM"
for m in ("jal", "jalr"):
    CLASS[m] = "CALL"
for m in ("j", "jr", "beq", "bne", "blez", "bgtz", "beql", "bnel", "blezl",
          "bgtzl", "bltz", "bgez", "bltzl", "bgezl", "bc1f", "bc1t",
          "bc1fl", "bc1tl"):
    CLASS[m] = "BRANCH"
for m in ("mov.s", "mfc1", "mtc1", "cfc1", "ctc1", "movz", "movn"):
    CLASS[m] = "MOVE"

SEMANTIC = ("FPU", "MULDIV", "CALL")


def mnemonic(word):
    if word == 0:
        return None                      # nop and padding carry no meaning
    op = word >> 26
    if op == SPECIAL:
        fn = word & 0x3F
        if fn == 0x25 and ((word >> 21) & 0x1F) == 0:
            return "move"                # or $d,$zero,$t
        if fn == 0x2D and ((word >> 21) & 0x1F) == 0:
            return "move"                # daddu $d,$zero,$t
        return FUNCT.get(fn, "special%02x" % fn)
    if op == REGIMM:
        return {0x00: "bltz", 0x01: "bgez", 0x02: "bltzl", 0x03: "bgezl",
                0x10: "bltzal", 0x11: "bgezal"}.get((word >> 16) & 0x1F,
                                                    "regimm")
    if op == COP1:
        rs = (word >> 21) & 0x1F
        if rs in COP1_RS:
            return COP1_RS[rs]
        if rs == 0x08:
            return "bc1t" if (word >> 16) & 1 else "bc1f"
        return COP1_FUNCT.get(word & 0x3F, "cop1_%02x" % (word & 0x3F))
    return OPCODE.get(op, "op%02x" % op)


def histogram(words):
    h = collections.Counter()
    for w in words:
        if w < 0:                        # relocation-masked
            continue
        m = mnemonic(w)
        if m is not None:
            h[m] += 1
    return h


def deltas_for_function(body, rels, target, min_delta):
    # No relocation masking here, deliberately.  A relocation rewrites an
    # immediate or a jump target, never an opcode field, so the mnemonic is
    # readable either way -- and masking would be actively wrong: the mask is
    # built from the CANDIDATE's relocation offsets, so applying it to retail
    # blanks whatever happens to sit at those offsets on retail's side and
    # manufactures huge phantom deltas in `jal` and `lui`.
    cand = histogram(words_of(body))
    ret = histogram(words_of(target))
    rows = []
    for m in set(cand) | set(ret):
        d = ret[m] - cand[m]             # positive => retail has more
        if abs(d) >= min_delta:
            rows.append({"mnemonic": m, "delta": d, "cand": cand[m],
                         "retail": ret[m], "cls": CLASS.get(m, "OTHER")})
    rows.sort(key=lambda r: (-abs(r["delta"]), r["mnemonic"]))
    return rows


def weight(rows):
    w = 0
    for r in rows:
        w += abs(r["delta"]) * (2 if r["cls"] in SEMANTIC else 1)
    return w


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--min-nd", type=int, default=0)
    ap.add_argument("--min-delta", type=int, default=2)
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    wanted = args.file.replace("\\", "/") if args.file else None

    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] != "NONMATCHING" or r["normalized_diff"] < args.min_nd:
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
            with tempfile.TemporaryDirectory(prefix="p3op_") as td:
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
                    rows = deltas_for_function(body, rels, tgt, args.min_delta)
                    if not rows:
                        continue
                    cls = collections.Counter()
                    for x in rows:
                        cls[x["cls"]] += abs(x["delta"])
                    findings.append({
                        "file": path, "addr": r["addr"], "name": r["name"],
                        "nd": r["normalized_diff"], "object": r["object_size"],
                        "window": r.get("window"), "rows": rows,
                        "cls": cls, "weight": weight(rows),
                        "semantic": sum(cls[c] for c in SEMANTIC)})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    findings.sort(key=lambda f: (-f["semantic"], -f["weight"]))
    tot = collections.Counter()
    for f in findings:
        tot.update(f["cls"])

    lines = ["# Opcode-histogram census", "",
             "Source report: `%s`  (min delta %d)" % (args.report, args.min_delta),
             "",
             "%d functions execute a materially different MULTISET of "
             "instructions from retail." % len(findings), "",
             "This census aligns nothing. It compares how many of each "
             "mnemonic each side emits, which is invariant under scheduling, "
             "register allocation, block placement and branch polarity -- so "
             "unlike every other census in `tools/`, it stays meaningful in "
             "the badly-aligned functions where most of the remaining nd "
             "lives.", "",
             "A positive delta means **retail emits more** of that "
             "instruction than we do; negative means we emit more.", "",
             "|class|total delta|reading|", "|---|---:|---|",
             "|FPU|%d|a missing or surplus arithmetic term|" % tot["FPU"],
             "|MULDIV|%d|a computation one side performs and the other does "
             "not|" % tot["MULDIV"],
             "|CALL|%d|a call genuinely absent or surplus, not displaced|"
             % tot["CALL"],
             "|MEM|%d|liveness: reloads we make and retail does not, or "
             "values retail holds|" % tot["MEM"],
             "|BRANCH|%d|control-flow shape|" % tot["BRANCH"],
             "|MOVE|%d|allocation noise, usually downstream of something "
             "else|" % tot["MOVE"],
             "|OTHER|%d||" % tot["OTHER"], "",
             "Ranked by semantic weight: FPU, MULDIV and CALL deltas name a "
             "computation that is present on one side and absent on the "
             "other, which is a source defect. MEM and MOVE deltas are "
             "frequently downstream of one of those, so fix the semantic row "
             "first and re-measure before reading the rest.", "",
             "|function|address|nd|object/window|semantic|classes|file|",
             "|---|---|---:|---|---:|---|---|"]

    for f in findings[:200]:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        cls = " ".join("%s%+d" % (k, v) for k, v in sorted(f["cls"].items()))
        lines.append("|`%s`|%s|%d|%s|%d|%s|%s|"
                     % (f["name"], f["addr"], f["nd"], win, f["semantic"],
                        cls, f["file"]))

    lines += ["", "## Rows", ""]
    for f in findings[:200]:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        lines.append("### `%s` %s -- nd %d -- %s -- %s"
                     % (f["name"], f["addr"], f["nd"], win, f["file"]))
        for x in f["rows"][:18]:
            lines.append("- %-8s `%s` retail %d, candidate %d (%+d)"
                         % (x["cls"], x["mnemonic"], x["retail"], x["cand"],
                            x["delta"]))
        if len(f["rows"]) > 18:
            lines.append("- ... %d more rows" % (len(f["rows"]) - 18))
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions -> %s" % (len(findings), args.out))
        for k, n in tot.most_common():
            print("   %-8s %d" % (k, n))
    else:
        print(text)


if __name__ == "__main__":
    main()
