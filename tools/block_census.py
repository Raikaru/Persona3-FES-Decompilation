#!/usr/bin/env python3
"""Basic-block structural census: where code is placed, independent of offsets.

W466's CLEAN audit found 687 functions whose frame size and callee-saved
register set already agree with retail.  Seventy-five of those also have the
same instruction-mnemonic multiset, yet still differ in bytes.  The existing
censuses can say what instructions differ, but they cannot say whether the
same straight-line blocks were merely placed in another order, or whether a
branch split, joined, or changed the control flow.

This census partitions each candidate and retail function into MIPS basic
blocks.  A block signature contains its word count, the multiset of decoded
mnemonics (using :func:`opcode_census.mnemonic`), and its terminator kind.
Relocated words are deliberately not masked: relocations rewrite immediates or
jump targets, never the opcode or register fields needed by this census.
Retail is read only through the final ``jr $ra`` and its delay slot; the padded
verification window is not treated as code.

Blocks are matched by exact signature first, then by nearest mnemonic-multiset
(L1) distance.  The function classes are:

  LAYOUT  every block has an exact one-to-one match, but candidate order is a
          permutation of retail order;
  SPLIT   candidate has one extra branch-induced block;
  MERGE   candidate has one fewer branch-induced block;
  SHAPE   control-flow/block counts differ beyond a single split or merge, or
          equal-count blocks have incompatible terminators;
  BODY    block structure corresponds, but one or more block signatures differ.

The report's nd, object size, and window are copied unchanged from the input
verify report.  Candidate bytes are compiled from the current source tree, so
an active source edit can change only the structural block read, not those
baseline metrics.  LAYOUT permutations in the report are zero-based retail
block indices, listed in candidate block order.

Usage:
    python tools/block_census.py --report build/baselines/W466_gate.json \
        --out build/wip/W467_block.md [--file src/x.c]
"""

from pathlib import Path
import argparse
import collections
import datetime
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from opcode_census import mnemonic
from verify import (REPO, TOOLS, RetailElf, compile_object, load_config,
                    scan_markers, window_for)

# The verify driver treats these as third-party.  Keep this local rather than
# importing a census helper whose historical filter also excludes src/lib/.
THIRD_PARTY_PREFIXES = ("rw/", "cri/", "sce/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}

SPECIAL = 0x00
REGIMM = 0x01
COP1 = 0x11
COND_OPS = {0x04, 0x05, 0x06, 0x07}
REGIMM_BRANCH_RT = {0x00, 0x01, 0x02, 0x03, 0x10, 0x11}
MEMORY_BRANCH_RS = 0x08
J_OPS = {0x02, 0x03}


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or norm.startswith(THIRD_PARTY_PREFIXES))


def words_of(buf):
    """Decode complete little-endian words, retaining zero/nop words."""
    return [int.from_bytes(buf[i:i + 4], "little")
            for i in range(0, len(buf) - 3, 4)]


def is_jr_ra(word):
    return ((word >> 26) == SPECIAL and (word & 0x3F) == 0x08
            and ((word >> 21) & 0x1F) == 31)


def true_word_count(words):
    """Return words through the final ``jr $ra`` delay slot.

    A missing return is tolerated because hand-written stubs and malformed
    objects exist in historical reports; in that case the available extent is
    the only honest extent.
    """
    last = -1
    for i, word in enumerate(words):
        if is_jr_ra(word):
            last = i
    return min(len(words), last + 2) if last >= 0 else len(words)


def terminator_kind(word):
    """Return the requested block terminator kind, or ``None``."""
    op = word >> 26
    if op == 0x02:
        return "j"
    if op == 0x03:
        return "jal"
    if op == SPECIAL:
        funct = word & 0x3F
        if funct == 0x08:
            return "jr"
        if funct == 0x09:
            return "jal"
        return None
    if op in COND_OPS:
        if op == 0x04 and ((word >> 21) & 0x1F) == 0 \
                and ((word >> 16) & 0x1F) == 0:
            return "b"
        return mnemonic(word)
    if op == REGIMM and ((word >> 16) & 0x1F) in REGIMM_BRANCH_RT:
        return mnemonic(word)
    if op == COP1 and ((word >> 21) & 0x1F) == MEMORY_BRANCH_RS:
        return mnemonic(word)
    return None


def branch_target(word, pc):
    """Return a direct branch/jump target, or ``None`` for register jumps."""
    op = word >> 26
    if op in COND_OPS or (op == REGIMM
                          and ((word >> 16) & 0x1F) in REGIMM_BRANCH_RT) \
            or (op == COP1 and ((word >> 21) & 0x1F) == MEMORY_BRANCH_RS):
        imm = word & 0xFFFF
        if imm & 0x8000:
            imm -= 0x10000
        return (pc + 4 + (imm << 2)) & 0xFFFFFFFF
    if op in J_OPS:
        return (((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)) \
            & 0xFFFFFFFF
    return None


def internal_target(target, base, extent):
    return (target is not None and base <= target < base + extent
            and (target - base) % 4 == 0)


def _relocation_offsets(rels):
    return {r.get("offset", 0) & ~3 for r in rels
            if r.get("type") == "R_MIPS_26" or r.get("r_type") == 4}


def partition(words, base, rels=()):
    """Partition words into address-ordered basic blocks.

    Every direct control transfer ends a block after its delay slot.  Internal
    direct targets become leaders; external targets still terminate a block
    but do not create a leader in this function.
    """
    n = len(words)
    if not n:
        return []
    leaders = {0}
    reloc_jumps = _relocation_offsets(rels)
    for i, word in enumerate(words):
        kind = terminator_kind(word)
        if kind is None:
            continue
        if i + 2 < n:
            leaders.add(i + 2)
        # A relocated jal/j is a symbol call, not a computable local edge in
        # the relocatable object.  Conditional branch displacements are local
        # and are always safe to evaluate directly.
        if (i * 4) not in reloc_jumps:
            target = branch_target(word, base + i * 4)
            if internal_target(target, base, n * 4):
                leaders.add((target - base) // 4)
    starts = sorted(leaders)
    blocks = []
    for pos, start in enumerate(starts):
        end = starts[pos + 1] if pos + 1 < len(starts) else n
        term_index = None
        term = "fallthrough"
        # The normal terminator is immediately before its delay slot.  The
        # fallback handles a truncated final instruction with no delay word.
        if end - 2 >= start and terminator_kind(words[end - 2]) is not None:
            term_index = end - 2
            term = terminator_kind(words[term_index])
        elif end - 1 >= start and terminator_kind(words[end - 1]) is not None:
            term_index = end - 1
            term = terminator_kind(words[end - 1])
        block_words = words[start:end]
        hist = collections.Counter()
        for word in block_words:
            name = mnemonic(word)
            if name is not None:
                hist[name] += 1
        blocks.append({
            "start": start,
            "end": end,
            "words": len(block_words),
            "hist": hist,
            "term": term,
            "signature": (len(block_words), tuple(sorted(hist.items())), term),
            "term_index": term_index,
        })
    return blocks


def multiset_distance(left, right):
    keys = set(left) | set(right)
    return sum(abs(left[k] - right[k]) for k in keys)


def match_blocks(candidate, retail):
    """Return candidate-index -> retail-index matches and exact match count."""
    unmatched_c = set(range(len(candidate)))
    unmatched_r = set(range(len(retail)))
    pairs = {}
    exact = 0

    # Exact signatures are consumed first.  Sorting duplicate groups by
    # address gives a deterministic, nearest-order pairing without assigning
    # meaning to otherwise indistinguishable blocks.
    by_c = collections.defaultdict(list)
    by_r = collections.defaultdict(list)
    for i in unmatched_c:
        by_c[candidate[i]["signature"]].append(i)
    for i in unmatched_r:
        by_r[retail[i]["signature"]].append(i)
    for sig in sorted(set(by_c) & set(by_r), key=repr):
        cs = sorted(by_c[sig])
        rs = sorted(by_r[sig])
        for ci, ri in zip(cs, rs):
            pairs[ci] = ri
            unmatched_c.remove(ci)
            unmatched_r.remove(ri)
            exact += 1

    # The remaining pairing is intentionally simple and auditable: nearest
    # mnemonic multiset distance first, candidate/retail address order second.
    while unmatched_c and unmatched_r:
        best = min(
            ((multiset_distance(candidate[ci]["hist"], retail[ri]["hist"]),
              abs(ci - ri), ci, ri)
             for ci in unmatched_c for ri in unmatched_r),
            key=lambda x: x)
        _distance, _order_distance, ci, ri = best
        pairs[ci] = ri
        unmatched_c.remove(ci)
        unmatched_r.remove(ri)
    return pairs, exact


def classify(candidate, retail, pairs, exact):
    """Return (class, optional zero-based permutation)."""
    nc, nr = len(candidate), len(retail)
    if nc == nr and exact == nc:
        permutation = [pairs[i] for i in range(nc)]
        if permutation != list(range(nc)):
            return "LAYOUT", permutation
        return "BODY", None

    if nc == nr:
        # Equal block counts with compatible terminators are the same control
        # skeleton; the residual is in individual block contents/order.
        compatible = all(candidate[ci]["term"] == retail[ri]["term"]
                        for ci, ri in pairs.items())
        return ("BODY", None) if compatible else ("SHAPE", None)

    branch_c = sum(b["term"] != "fallthrough" for b in candidate)
    branch_r = sum(b["term"] != "fallthrough" for b in retail)
    if nc == nr + 1 and branch_c == branch_r + 1:
        return "SPLIT", None
    if nr == nc + 1 and branch_r == branch_c + 1:
        return "MERGE", None
    return "SHAPE", None


def row_for_result(result, obj, retail, bounds):
    addr = int(result["addr"], 16)
    body, rels = obj.function(result["name"])
    candidate_words_all = words_of(body)
    candidate_n = true_word_count(candidate_words_all)
    candidate_words = candidate_words_all[:candidate_n]
    window = result.get("window")
    if window is None:
        window = window_for(addr, bounds)
    if window is None:
        raise ValueError("no retail window for %s" % result["name"])
    target = retail.bytes_at(addr, window)
    retail_words_all = words_of(target)
    retail_n = true_word_count(retail_words_all)
    retail_words = retail_words_all[:retail_n]
    candidate_blocks = partition(candidate_words, addr, rels)
    retail_blocks = partition(retail_words, addr)
    pairs, exact = match_blocks(candidate_blocks, retail_blocks)
    cls, permutation = classify(candidate_blocks, retail_blocks, pairs, exact)
    return {
        "file": result["file"].replace("\\", "/"),
        "addr": result["addr"],
        "name": result["name"],
        "nd": result.get("normalized_diff", 0),
        "object": result.get("object_size"),
        "window": result.get("window"),
        "class": cls,
        "candidate_blocks": len(candidate_blocks),
        "retail_blocks": len(retail_blocks),
        "candidate_extent": candidate_n * 4,
        "retail_extent": retail_n * 4,
        "permutation": permutation,
    }


def markdown(findings, report, read_started, read_finished, errors):
    counts = collections.Counter(f["class"] for f in findings)
    nds = collections.Counter()
    for f in findings:
        nds[f["class"]] += f["nd"]
    lines = [
        "# Basic-block structural census", "",
        "Source report: `%s`" % report, "",
        "Structural candidate read window (current source, UTC): `%s` to `%s`."
        % (read_started, read_finished),
        "All functions listed here were compiled and read during that interval;"
        " candidate source may have changed while other lanes were active.",
        "`nd`, `object`, and `window` are copied unchanged from the W466 gate;"
        " they are not refreshed by this instrument.",
        "Retail extents stop after the final `jr $ra` and its delay slot, not at"
        " the padded verification window. Nops/padding count toward block words"
        " but are omitted from mnemonic multisets, exactly as in"
        " `opcode_census.mnemonic`.",
        "Relocated words are not masked. A relocation changes an immediate or"
        " jump target, never the opcode/register fields used here.",
        "A LAYOUT permutation is zero-based and lists the retail block index for"
        " each candidate block in candidate address order.", "",
        "%d first-party NONMATCHING functions structurally read." % len(findings),
        "",
        "|class|functions|nd|reading|", "|---|---:|---:|---|",
        "|LAYOUT|%d|%d|all exact blocks, address order differs|"
        % (counts["LAYOUT"], nds["LAYOUT"]),
        "|SPLIT|%d|%d|candidate has one extra branch-induced block|"
        % (counts["SPLIT"], nds["SPLIT"]),
        "|MERGE|%d|%d|candidate has one fewer branch-induced block|"
        % (counts["MERGE"], nds["MERGE"]),
        "|SHAPE|%d|%d|control-flow/block structure differs|"
        % (counts["SHAPE"], nds["SHAPE"]),
        "|BODY|%d|%d|same block skeleton, contents differ|"
        % (counts["BODY"], nds["BODY"]), "",
        "|rank|function|address|nd|object/window|class|candidate blocks|"
        "retail blocks|candidate extent|retail extent|permutation|file|",
        "|---:|---|---|---:|---|---|---:|---:|---:|---:|---|---|",
    ]
    ordered = sorted(findings,
                     key=lambda f: (-f["nd"], f["file"], f["addr"]))
    for rank, f in enumerate(ordered, 1):
        win = "%s/%s" % (f["object"], f["window"])
        perm = ("[%s]" % ", ".join(str(x) for x in f["permutation"])
                if f["permutation"] is not None else "—")
        lines.append(
            "|%d|`%s`|%s|%d|%s|%s|%d|%d|%d|%d|%s|%s|"
            % (rank, f["name"], f["addr"], f["nd"], win, f["class"],
               f["candidate_blocks"], f["retail_blocks"],
               f["candidate_extent"], f["retail_extent"], perm, f["file"]))
    if errors:
        lines += ["", "## Structural read errors", "",
                  "The catalogue run continued after these rows failed; no"
                  " class was fabricated for an unread function.", "",
                  "|file|function|error|", "|---|---|---|"]
        for e in errors:
            lines.append("|%s|`%s`|%s|" % (e["file"], e["name"], e["error"]))
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    ap.add_argument("--min-nd", type=int, default=0)
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.loads(Path(args.report).read_text())["results"]
    wanted = args.file.replace("\\", "/") if args.file else None
    by_file = collections.defaultdict(list)
    for result in results:
        path = result["file"].replace("\\", "/")
        if (result.get("status") != "NONMATCHING"
                or result.get("normalized_diff", 0) < args.min_nd
                or not first_party(path)
                or (wanted and path != wanted)):
            continue
        by_file[path].append(result)

    bounds = {int(a, 16) for a in sizes["windows"]}
    for cpath in sorted((REPO / "src").rglob("*.c")):
        for marker in scan_markers(cpath):
            bounds.add(marker["addr"])
    bounds = sorted(bounds)

    findings = []
    errors = []
    read_started = datetime.datetime.now(datetime.timezone.utc).isoformat(
        timespec="seconds")
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            for result in by_file[path]:
                errors.append({"file": path, "name": result["name"],
                               "error": "source file not found"})
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3block_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print("  ! %s: compile failed" % path, file=sys.stderr)
                    for result in by_file[path]:
                        errors.append({"file": path, "name": result["name"],
                                       "error": "compile failed"})
                    continue
                for result in by_file[path]:
                    try:
                        findings.append(row_for_result(result, obj, retail,
                                                        bounds))
                    except Exception as exc:
                        errors.append({"file": path, "name": result["name"],
                                       "error": str(exc)})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)
            for result in by_file[path]:
                errors.append({"file": path, "name": result["name"],
                               "error": str(exc)})
    read_finished = datetime.datetime.now(datetime.timezone.utc).isoformat(
        timespec="seconds")
    text = markdown(findings, args.report, read_started, read_finished, errors)
    if args.out:
        Path(args.out).write_text(text + "\n", encoding="utf-8")
        print("%d functions -> %s" % (len(findings), args.out))
        for cls in ("LAYOUT", "SPLIT", "MERGE", "SHAPE", "BODY"):
            n = sum(1 for f in findings if f["class"] == cls)
            print("   %-6s %d" % (cls, n))
        if errors:
            print("   errors %d" % len(errors), file=sys.stderr)
    else:
        print(text)


if __name__ == "__main__":
    main()
