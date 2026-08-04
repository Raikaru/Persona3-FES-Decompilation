#!/usr/bin/env python3
"""Structural-gap census: aligned blocks of instructions one side has and the
other does not.

`imm_census.py` answers "which numbers are wrong".  This answers the prior
question: **which code is missing or extra**.  Candidate and retail are aligned
with difflib over instruction words (relocated fields neutralised first), and
every `insert` / `delete` block is reported with its disassembly.

An `insert` block is code RETAIL HAS AND WE DO NOT.  A `delete` block is code
WE EMIT AND RETAIL DOES NOT.  Both are structural: no amount of register or
declaration tuning closes them, and they displace every later comparison,
which is why they dominate the residual of the functions that never move.

Blocks are tagged with a guess at the responsible construct:

  LOOPSHAPE   a lone branch (+ delay slot) retail has at a loop head.
              W459: a do/while where retail writes a pre-test `while` --
              two MATCHes in mdlEffect from exactly this.
  CALL        the block contains a jal: a missing or extra call.
  SPILL       sq/lq/sd/ld against $sp: a register-pressure difference.
              Retail-only means retail holds one MORE live value than we do.
  ZEROINIT    stores of $zero: a local aggregate retail initialises.
  FPU         the block is mostly coprocessor-1 work.
  BODY        anything larger and more general -- real missing logic.

Usage:
  python tools/gap_census.py --report build/baselines/W459_gate.json \
                             --out build/wip/W460_gap.md
  python tools/gap_census.py --report <gate> --file src/Camp/h_camp.c
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

from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, CS_MODE_LITTLE_ENDIAN

_md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)

THIRD_PARTY_DIRS = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}

BRANCH_OPS = {0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
JUMP_OPS = {0x02, 0x03}
SPILL_OPS = {0x1E, 0x1F, 0x37, 0x3F}          # lq sq ld sd
SP = 29


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or any(norm.startswith(d) for d in THIRD_PARTY_DIRS))


def dis(word, pc):
    if word < 0:
        return "<relocated>"
    for ins in _md.disasm(word.to_bytes(4, "little"), pc):
        return f"{ins.mnemonic} {ins.op_str}".strip()
    return f".word {word:#010x}"


def classify(words):
    """Guess the construct responsible for a gap block."""
    real = [w for w in words if w not in (0, -1)]
    if not real:
        return "PADDING"
    ops = [w >> 26 for w in real]
    if len(real) <= 2 and any(o in BRANCH_OPS for o in ops):
        return "LOOPSHAPE"
    if any(o in JUMP_OPS for o in ops):
        return "CALL"
    spill = [w for w in real if (w >> 26) in SPILL_OPS and ((w >> 21) & 0x1F) == SP]
    if spill and len(spill) * 2 >= len(real):
        return "SPILL"
    zero = [w for w in real if (w >> 26) in (0x28, 0x29, 0x2B, 0x3F)
            and ((w >> 16) & 0x1F) == 0]
    if zero and len(zero) * 2 >= len(real):
        return "ZEROINIT"
    fpu = [w for w in real if (w >> 26) in (0x11, 0x31, 0x39, 0x35, 0x3D)]
    if fpu and len(fpu) * 2 >= len(real):
        return "FPU"
    return "BODY"


def words_of(buf, mask=None):
    out = []
    for i in range(0, len(buf) - 3, 4):
        if mask is not None and any(mask[i:i + 4]):
            out.append(-1)                      # relocated: unusable for alignment
        else:
            out.append(int.from_bytes(buf[i:i + 4], "little"))
    return out


def gaps_for_function(body, rels, target):
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = words_of(body, mask)
    ret = words_of(target, mask[:len(target)] if len(mask) >= len(target) else None)

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    blocks = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "insert":
            ws = ret[j1:j2]
            blocks.append({"side": "retail-only", "at": i1 * 4, "words": len(ws),
                           "kind": classify(ws),
                           "text": [dis(w, (j1 + k) * 4) for k, w in enumerate(ws)]})
        elif tag == "delete":
            ws = cand[i1:i2]
            blocks.append({"side": "candidate-only", "at": i1 * 4, "words": len(ws),
                           "kind": classify(ws),
                           "text": [dis(w, (i1 + k) * 4) for k, w in enumerate(ws)]})
        elif tag == "replace" and (i2 - i1) != (j2 - j1):
            delta = (j2 - j1) - (i2 - i1)
            ws = ret[j1:j2] if delta > 0 else cand[i1:i2]
            blocks.append({"side": "retail-only" if delta > 0 else "candidate-only",
                           "at": i1 * 4, "words": abs(delta), "kind": classify(ws),
                           "text": [dis(w, (j1 + k) * 4) for k, w in enumerate(ws)]})
    return blocks


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--min-words", type=int, default=1)
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
            with tempfile.TemporaryDirectory(prefix="p3gap_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print(f"  ! {path}: compile failed", file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    tgt = retail.bytes_at(addr, window_for(addr, bounds))
                    blocks = [b for b in gaps_for_function(body, rels, tgt)
                              if b["words"] >= args.min_words and b["kind"] != "PADDING"]
                    if blocks:
                        findings.append({"file": path, "addr": r["addr"],
                                         "name": r["name"], "nd": r["normalized_diff"],
                                         "object": r["object_size"],
                                         "window": r.get("window"),
                                         "blocks": blocks})
        except Exception as exc:
            print(f"  ! {path}: {exc}", file=sys.stderr)

    def score(f):
        return sum(b["words"] for b in f["blocks"])

    findings.sort(key=lambda f: (-score(f), -f["nd"]))

    kinds = collections.Counter()
    sides = collections.Counter()
    for f in findings:
        for b in f["blocks"]:
            kinds[b["kind"]] += 1
            sides[b["side"]] += b["words"]

    lines = ["# Structural-gap census", "",
             f"Source report: `{args.report}`", "",
             f"{len(findings)} NONMATCHING functions contain at least one aligned "
             f"block of instructions that only one side emits.", "",
             "An `insert` (retail-only) block is code retail has and we do not; a "
             "`delete` (candidate-only) block is code we emit and retail does not. "
             "Both are structural — register and declaration tuning cannot close "
             "them, and each one displaces every later comparison.", "",
             "## Blocks by kind", "", "|kind|blocks|meaning|", "|---|---:|---|"]
    meaning = {
        "LOOPSHAPE": "lone branch at a loop head — do/while vs pre-test while",
        "CALL": "missing or extra call",
        "SPILL": "register-pressure difference; retail-only = retail holds one more live value",
        "ZEROINIT": "a local aggregate retail zero-initialises",
        "FPU": "floating-point work one side does not do",
        "BODY": "real missing or extra logic",
    }
    for k, n in kinds.most_common():
        lines.append(f"|{k}|{n}|{meaning.get(k, '')}|")
    lines += ["", f"Retail-only words: **{sides['retail-only']}**  ·  "
                  f"candidate-only words: **{sides['candidate-only']}**", ""]

    byfile = collections.Counter()
    for f in findings:
        byfile[f["file"]] += score(f)
    lines += ["## Gap words by file", "", "|file|words|", "|---|---:|"]
    for f, n in byfile.most_common(30):
        lines.append(f"|{f}|{n}|")

    lines += ["", "## Functions", ""]
    for f in findings:
        win = f"{f['object']}/{f['window']}" if f["window"] else f"{f['object']}"
        lines.append(f"### `{f['name']}` {f['addr']} — nd {f['nd']} — {win} — {f['file']}")
        lines.append("")
        for b in f["blocks"][:12]:
            lines.append(f"- **{b['kind']}** {b['side']}, {b['words']} word(s) "
                         f"at candidate offset {b['at']}")
            for t in b["text"][:10]:
                lines.append(f"    - `{t}`")
            if len(b["text"]) > 10:
                lines.append(f"    - … {len(b['text']) - 10} more")
        if len(f["blocks"]) > 12:
            lines.append(f"- … {len(f['blocks']) - 12} more blocks")
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print(f"{len(findings)} functions -> {args.out}")
        for k, n in kinds.most_common():
            print(f"   {k:10s} {n}")
        print(f"   retail-only words {sides['retail-only']}, "
              f"candidate-only words {sides['candidate-only']}")
    else:
        print(text)


if __name__ == "__main__":
    main()
