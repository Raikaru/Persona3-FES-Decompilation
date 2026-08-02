#!/usr/bin/env python3
"""Corpus prologue census.

For every first-party NONMATCHING function, decode the frame size and the exact
callee-saved register set from BOTH our compiled object and the retail image,
then classify the discrepancy.

The prologue is the highest-yield diagnostic this project has: it produced the
nd774->MATCH conversion, the nd835->326 reduction, and several 100+ point wins.
Running it per function costs a sibdiff invocation each; running it corpus-wide
costs one compile per file and turns the whole NONMATCHING population into a
ranked, pre-classified work list.

Classification
  LIVENESS   retail saves registers we do not -> a value must stay live across
             calls that our source reloads or recomputes. Cache it in a local.
  SURPLUS    we save registers retail does not -> surplus temporaries, or a
             surplus stack local.
  FRAME      identical saved set, different frame size -> a stack aggregate is
             the wrong size (scalar where retail has an array, or wrong extent).
  CLEAN      frame and saved set both agree -> nothing missing, nothing surplus;
             the entire residual is arrangement (shape / colouring).

Usage:  python tools/prologue_census.py [--report <verify.json>] [--out <md>]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify as V  # noqa: E402

GPR = {16: "s0", 17: "s1", 18: "s2", 19: "s3", 20: "s4", 21: "s5", 22: "s6",
       23: "s7", 28: "gp", 30: "fp", 31: "ra"}
# Store opcodes that can spill a callee-saved register to the frame.
ST_GPR = {0x2B: "sw", 0x3F: "sd", 0x1F: "sq"}
ST_FPR = {0x39: "swc1"}
# addiu / daddiu, used to open the frame.
ADDI = {0x09, 0x19}
SP = 29


def decode_prologue(words, limit=48):
    """Return (frame_size, saved_set) from the leading instructions.

    Scanning stops at the first control transfer, which is past every prologue
    MWCC emits. frame_size is positive (the amount subtracted from $sp).
    """
    frame = None
    saved = set()
    for i, w in enumerate(words[:limit]):
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op in ADDI and rs == SP and rt == SP:
            if simm < 0 and frame is None:
                frame = -simm
            continue
        if op in ST_GPR and rs == SP:
            if rt in GPR:
                saved.add(GPR[rt])
            continue
        if op in ST_FPR and rs == SP:
            # f20 and above are the callee-saved half on the EE ABI.
            if rt >= 20:
                saved.add(f"f{rt}")
            continue
        # jr / jal / branch: prologue is over.
        if op == 0 and (w & 0x3F) in (0x08, 0x09):
            break
        if op in (0x02, 0x03) or 0x04 <= op <= 0x07 or op == 0x01:
            break
    return frame, saved


def words_of(buf):
    n = len(buf) // 4
    return list(struct.unpack_from("<%dI" % n, buf, 0))


def fmt(regs):
    order = ["s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "gp", "fp", "ra"]
    g = [r for r in order if r in regs]
    f = sorted((r for r in regs if r[0] == "f" and r[1:].isdigit()),
               key=lambda x: int(x[1:]))
    return ",".join(g + f) or "-"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/baselines/W433_gate.json")
    ap.add_argument("--out", default="build/prologue_census.md")
    ap.add_argument("--min-nd", type=int, default=100)
    args = ap.parse_args()

    cfg = V.load_config()
    retail = V.RetailElf(cfg["retail_elf"], cfg.get("retail_sha1"))

    rows = json.load(open(args.report))["results"]
    want = {}
    for r in rows:
        f = r["file"].replace("\\", "/")
        n = f[4:] if f.startswith("src/") else f
        if n in ("crt0.c", "libc_core.c", "libcdvd.c") or n.startswith(("rw/", "cri/", "sce/")):
            continue
        if r["status"] != "NONMATCHING":
            continue
        if (r.get("normalized_diff") or 0) < args.min_nd:
            continue
        want.setdefault(f, []).append(r)

    import tempfile
    objdir = Path(tempfile.mkdtemp())
    out = []
    counts = {"LIVENESS": 0, "SURPLUS": 0, "FRAME": 0, "CLEAN": 0, "MIXED": 0}
    ndc = dict.fromkeys(counts, 0)

    for i, (f, funcs) in enumerate(sorted(want.items()), 1):
        cpath = V.REPO / f
        obj, log = V.compile_object(cpath, cfg, objdir)
        if obj is None:
            print(f"  [{i}/{len(want)}] COMPILE FAIL {f}", file=sys.stderr)
            continue
        for r in funcs:
            try:
                body, _ = obj.function(r["name"])
            except KeyError:
                continue
            addr = int(r["addr"], 16)
            win = retail.bytes_at(addr, r["window"])
            of, os_ = decode_prologue(words_of(body))
            rf, rs_ = decode_prologue(words_of(win))
            if of is None or rf is None:
                continue
            missing = rs_ - os_          # retail saves, we do not
            extra = os_ - rs_            # we save, retail does not
            if missing and extra:
                kind = "MIXED"
            elif missing:
                kind = "LIVENESS"
            elif extra:
                kind = "SURPLUS"
            elif of != rf:
                kind = "FRAME"
            else:
                kind = "CLEAN"
            counts[kind] += 1
            ndc[kind] += r["normalized_diff"]
            out.append((kind, r["normalized_diff"], f, r["addr"], r["name"],
                        of, rf, fmt(missing), fmt(extra),
                        r["object_size"], r["window"]))
        print(f"  [{i}/{len(want)}] {f}", file=sys.stderr)

    out.sort(key=lambda x: (x[0], -x[1]))
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as fh:
        fh.write("# Prologue census\n\n")
        fh.write("| class | count | nd |\n|---|---:|---:|\n")
        for k in ("LIVENESS", "SURPLUS", "MIXED", "FRAME", "CLEAN"):
            fh.write(f"| {k} | {counts[k]} | {ndc[k]:,} |\n")
        fh.write("\nframe values are the bytes subtracted from $sp.\n")
        fh.write("`missing` = retail saves it, we do not (cache a value across calls).\n")
        fh.write("`extra`   = we save it, retail does not (surplus temporary/local).\n")
        cur = None
        for kind, nd, f, addr, name, of, rf, miss, extra, osz, win in out:
            if kind != cur:
                fh.write(f"\n\n## {kind}\n")
                cur = kind
            fh.write(f"\n{f}  {addr}  {name}\n"
                     f"    nd {nd}  obj {osz}/{win}"
                     f"{'  EXACT' if osz == win else ''}\n"
                     f"    frame ours -0x{of:x} retail -0x{rf:x}"
                     f"{'  SAME' if of == rf else ''}\n"
                     f"    missing {miss}   extra {extra}\n")
    for k in ("LIVENESS", "SURPLUS", "MIXED", "FRAME", "CLEAN"):
        print(f"{k:9} {counts[k]:5d} functions   nd {ndc[k]:,}")
    print(f"\nwrote {args.out}")


if __name__ == "__main__":
    main()
