#!/usr/bin/env python3
"""Batch-drive tools/permute.py across many functions.

Runs the permuter on a list of (file, function) targets with a per-function
time budget and a small worker pool, then reports which functions were cracked
(byte-exact) and where the winning source region was written.

Targets come from either --targets (a JSON list of [file, function] pairs) or,
by default, every NONMATCHING/MISMATCH function found by a fresh verify.py scan.

Usage:
  python tools/permute_sweep.py --time 30 --workers 2
  python tools/permute_sweep.py --targets targets.json --time 60 --workers 3
  python tools/permute_sweep.py --outdir build/permute --json build/sweep.json

Each per-function subprocess is hard-bounded (budget + 40s) so a stuck compile
cannot wedge the sweep. Re-confirm every hit with `python tools/verify.py`
before committing; a permuter match is a byte match, not a semantic proof.
"""

from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
import argparse
import json
import subprocess
import sys
import time

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent


def discover_targets():
    """Fresh verify scan -> [(file, function, ndiff)] for non-matching funcs."""
    out = REPO / "build" / "_sweep_verify.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([sys.executable, str(TOOLS / "verify.py"), "--json", str(out)],
                   cwd=str(REPO), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    d = json.loads(out.read_text())
    res = [f for f in d["results"]
           if f["status"] in ("NONMATCHING", "MISMATCH") and f.get("normalized_diff", 0) > 0
           and f.get("name")]
    res.sort(key=lambda f: f["normalized_diff"])
    return [(f["file"].replace("\\", "/"), f["name"], f["normalized_diff"]) for f in res]


def run_one(file, func, seconds, seed, outdir):
    outp = outdir / f"{func}.c"
    try:
        proc = subprocess.run(
            [sys.executable, str(TOOLS / "permute.py"), file, func,
             "--iters", "100000000", "--time", str(seconds), "--seed", str(seed),
             "--out", str(outp)],
            cwd=str(REPO), capture_output=True, text=True, timeout=seconds + 40)
        out = (proc.stdout or "") + (proc.stderr or "")
    except subprocess.TimeoutExpired:
        return dict(func=func, file=file, matched=False, note="hard-timeout")
    lines = [l for l in out.splitlines() if l.strip()]
    matched = "MATCH at iter" in out
    best = None
    for l in lines:
        if "base_score=" in l:
            try:
                best = int(l.split("base_score=")[1].split()[0])
            except (IndexError, ValueError):
                pass
        if "new best score" in l:
            try:
                best = int(l.split("new best score")[1].split()[0])
            except (IndexError, ValueError):
                pass
    return dict(func=func, file=file, matched=matched,
                out=str(outp) if matched else None, best=best,
                note=lines[-1] if lines else "")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--targets", help="JSON list of [file, function] pairs")
    ap.add_argument("--time", type=float, default=30.0, help="seconds per function")
    ap.add_argument("--workers", type=int, default=2)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--max-ndiff", type=int, default=10 ** 9,
                    help="skip discovered targets whose baseline diff exceeds this")
    ap.add_argument("--outdir", default="build/permute")
    ap.add_argument("--json", help="write full sweep result JSON here")
    args = ap.parse_args()

    if args.targets:
        pairs = json.loads(Path(args.targets).read_text())
        targets = [(p[0], p[1], p[2] if len(p) > 2 else -1) for p in pairs]
    else:
        targets = discover_targets()
    targets = [t for t in targets if t[2] <= args.max_ndiff or t[2] < 0]

    outdir = (REPO / args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    print(f"sweep: {len(targets)} targets, {args.workers} workers, "
          f"{args.time:.0f}s each", flush=True)

    results = []
    t0 = time.time()
    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futs = {ex.submit(run_one, f, n, args.time, args.seed, outdir): (f, n)
                for f, n, _ in targets}
        done = 0
        for fut in as_completed(futs):
            r = fut.result()
            results.append(r)
            done += 1
            tag = "MATCH " if r["matched"] else "      "
            print(f"[{done}/{len(targets)}] {tag} {r['func']:40s} "
                  f"best={r.get('best')}  ({r['note']})", flush=True)

    hits = [r for r in results if r["matched"]]
    print(f"\nsweep done in {time.time()-t0:.0f}s: {len(hits)} MATCH / "
          f"{len(results)} tried", flush=True)
    for r in hits:
        print(f"  MATCH {r['func']}  ->  {r['out']}")
    if args.json:
        Path(args.json).write_text(json.dumps(results, indent=1), newline="\n")
        print(f"report: {args.json}")


if __name__ == "__main__":
    main()
