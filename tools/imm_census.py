#!/usr/bin/env python3
"""Immediate-field census: differing words that share a mnemonic and registers.

Where candidate and retail emit the *same instruction* on the *same registers*
but a different immediate, the defect is almost always in the C source rather
than in register allocation:

  SHIFT    sll/sra/srl/dsll with a different shift amount
           -> array element size (stride) or an integer-width error.
           W458 sfl_psel func_00217780: `i * 0x40` where the BP texture quad is
           0x100 bytes.  nd 1,582 -> 1,225.
  OFFSET   lw/sw/lh/sh/lb/sb/lwc1/swc1 with a different displacement on the
           same base register -> wrong struct field offset or wrong struct type.
  FRAME    the same, but based on $sp -> local layout / declaration order.
  ADDEND   addiu/daddiu with a different constant.
  MASK     andi/ori/xori -> integer width or a bitfield mask.
  CONST    lui and everything else.

Unlike a raw register mismatch, every one of these names a specific wrong
number in the source, so each row is directly actionable.

Usage:
  python tools/imm_census.py --report build/baselines/W458_gate.json \
                             --out build/wip/W459_imm.md
  python tools/imm_census.py --report <gate> --file src/Camp/h_camp.c
"""

from pathlib import Path
import argparse
import collections
import difflib
import json
import re
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, ObjectFile, RetailElf, compile_object,
                    load_config, mask_bytes, scan_markers, window_for)

from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, CS_MODE_LITTLE_ENDIAN

_md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)

THIRD_PARTY_DIRS = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}

# I-type opcodes whose low 16 bits are a source-visible immediate.  Branches
# and jumps are deliberately absent: their displacement shifts whenever an
# earlier defect changes the instruction count, so they are consequences of
# other defects rather than defects themselves.
OP_KIND = {
    0x08: "ADDEND", 0x09: "ADDEND",           # addi  addiu
    0x18: "ADDEND", 0x19: "ADDEND",           # daddi daddiu
    0x0A: "ADDEND", 0x0B: "ADDEND",           # slti  sltiu
    0x0C: "MASK", 0x0D: "MASK", 0x0E: "MASK",  # andi ori xori
    0x0F: "CONST",                            # lui
    0x20: "OFFSET", 0x21: "OFFSET", 0x23: "OFFSET", 0x24: "OFFSET",
    0x25: "OFFSET", 0x27: "OFFSET",           # lb lh lw lbu lhu lwu
    0x28: "OFFSET", 0x29: "OFFSET", 0x2B: "OFFSET",   # sb sh sw
    0x37: "OFFSET", 0x3F: "OFFSET",           # ld sd
    0x1E: "OFFSET", 0x1F: "OFFSET",           # lq sq
    0x31: "OFFSET", 0x39: "OFFSET",           # lwc1 swc1
    0x35: "OFFSET", 0x3D: "OFFSET",           # ldc1 sdc1
}
SHIFT_FUNCTS = {0x00, 0x02, 0x03, 0x38, 0x3A, 0x3B, 0x3C, 0x3E, 0x3F}
SP = 29


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or any(norm.startswith(d) for d in THIRD_PARTY_DIRS))


def decode(word, pc):
    for ins in _md.disasm(word, pc):
        return f"{ins.mnemonic} {ins.op_str}"
    return "??"


def immediate_form(word):
    """-> (kind, register-signature, immediate) or None.

    Decoded from the encoding rather than from disassembly text, so a register
    number can never be mistaken for an immediate.
    """
    op = word >> 26
    if op == 0:                                    # SPECIAL: shifts only
        funct = word & 0x3F
        if funct not in SHIFT_FUNCTS:
            return None
        rt, rd = (word >> 16) & 0x1F, (word >> 11) & 0x1F
        return "SHIFT", f"f{funct}:r{rd},r{rt}", (word >> 6) & 0x1F
    kind = OP_KIND.get(op)
    if kind is None:
        return None
    rs, rt = (word >> 21) & 0x1F, (word >> 16) & 0x1F
    imm = word & 0xFFFF
    if kind != "MASK" and imm >= 0x8000:           # these fields are signed
        imm -= 0x10000
    if rs == SP and kind in ("OFFSET", "ADDEND"):
        kind = "FRAME"
    return kind, f"o{op}:r{rs},r{rt}", imm


def _words(buf, n):
    return [int.from_bytes(buf[i:i + 4], "little") for i in range(0, n - 3, 4)]


def rows_for_function(body, rels, target):
    """Aligned immediate diff.

    Candidate and retail are aligned with difflib before comparison, so an
    inserted or deleted instruction earlier in the function shifts everything
    after it in the *alignment* rather than smearing a false "wrong constant"
    across every later row.  Only words difflib pairs one-to-one inside an
    equal-length `replace` block are considered.  `shifted` marks a row that
    sits after an insertion or deletion, so its offset no longer corresponds
    to retail's.
    """
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = _words(body, len(body))
    ret = _words(target, len(target))

    # Neutralise relocated fields so they cannot break the alignment either.
    for i in range(len(cand)):
        if any(mask[i * 4:i * 4 + 4]):
            cand[i] = -1
            if i < len(ret):
                ret[i] = -1

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    out = []
    shifted = False
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag in ("insert", "delete"):
            shifted = True
            continue
        if tag != "replace":
            continue
        if (i2 - i1) != (j2 - j1):
            shifted = True
            continue                     # unequal block: no one-to-one pairing
        for k in range(i2 - i1):
            off = (i1 + k) * 4
            if any(mask[off:off + 4]):
                continue
            ow, tw = cand[i1 + k], ret[j1 + k]
            of, tf = immediate_form(ow), immediate_form(tw)
            if of is None or tf is None:
                continue
            if of[0] != tf[0] or of[1] != tf[1] or of[2] == tf[2]:
                continue
            out.append({"offset": off, "kind": of[0], "shifted": shifted,
                        "text": decode(ow.to_bytes(4, "little"), off),
                        "retail_text": decode(tw.to_bytes(4, "little"), off),
                        "candidate": of[2], "retail": tf[2]})
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True, help="verify.py gate JSON")
    ap.add_argument("--out", help="write markdown here (default stdout)")
    ap.add_argument("--file", help="restrict to one source file")
    ap.add_argument("--min-rows", type=int, default=1)
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
        if not first_party(path):
            continue
        if wanted and path != wanted:
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
            with tempfile.TemporaryDirectory(prefix="p3imm_") as td:
                obj, log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print(f"  ! {path}: compile failed", file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    target = retail.bytes_at(addr, window_for(addr, bounds))
                    rows = rows_for_function(body, rels, target)
                    if len(rows) >= args.min_rows:
                        findings.append({"file": path, "addr": r["addr"],
                                         "name": r["name"],
                                         "nd": r["normalized_diff"], "rows": rows})
        except Exception as exc:                       # keep the census going
            print(f"  ! {path}: {exc}", file=sys.stderr)

    findings.sort(key=lambda f: (-len(f["rows"]), -f["nd"]))

    kinds = collections.Counter(row["kind"] for f in findings for row in f["rows"])
    files = collections.Counter()
    for f in findings:
        files[f["file"]] += len(f["rows"])

    lines = ["# Immediate-field census", "",
             f"Source report: `{args.report}`", "",
             f"{len(findings)} NONMATCHING functions carry at least {args.min_rows} "
             f"word(s) where candidate and retail share a mnemonic and register "
             f"operands but differ in the immediate.", "",
             "Each row names a specific wrong number in the C source.", "",
             "## Rows by kind", "", "|kind|rows|meaning|", "|---|---:|---|"]
    meaning = {"SHIFT": "array element size (stride) or integer width",
               "OFFSET": "struct field offset or wrong struct type",
               "FRAME": "local stack layout / declaration order",
               "MASK": "integer width or bitfield mask",
               "ADDEND": "constant addend",
               "CONST": "other constant"}
    for k, n in kinds.most_common():
        lines.append(f"|{k}|{n}|{meaning.get(k, '')}|")
    lines += ["", "## Rows by file", "", "|file|rows|", "|---|---:|"]
    for f, n in files.most_common(30):
        lines.append(f"|{f}|{n}|")
    lines += ["", "## Functions", ""]
    for f in findings:
        lines.append(f"### `{f['name']}` {f['addr']} — nd {f['nd']} — {f['file']}")
        lines.append("")
        lines.append("|offset|kind|candidate|retail|")
        lines.append("|---:|---|---|---|")
        for row in f["rows"][:24]:
            flag = " *" if row.get("shifted") else ""
            lines.append(f"|{row['offset']}{flag}|{row['kind']}|"
                         f"`{row['text']}`|`{row['retail_text']}`|")
        if len(f["rows"]) > 24:
            lines.append(f"|…|…|{len(f['rows']) - 24} more rows|||")
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print(f"{len(findings)} functions, {sum(kinds.values())} rows -> {args.out}")
        for k, n in kinds.most_common():
            print(f"   {k:8s} {n}")
    else:
        print(text)


if __name__ == "__main__":
    main()
