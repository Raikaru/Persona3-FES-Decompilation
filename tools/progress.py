#!/usr/bin/env python3
"""Report decompilation progress.

Runs the per-function verifier (or reads its JSON report) and summarises how
much of the executable is matched: function counts, matched code bytes, and a
per-directory breakdown. Also reports how many files link as real C objects.

Usage:
  python tools/progress.py                 # run verify.py and report
  python tools/progress.py --report build/verify_report.json
  python tools/progress.py --json          # machine-readable (frogress-style)
"""
from __future__ import annotations

import argparse
import collections
import json
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOTAL_FUNCS = 13407  # entries in config/symbol_addrs.txt


def load_report(path: Path | None) -> dict:
    if path and path.is_file():
        return json.loads(path.read_text())
    out = REPO / "build" / "verify_report.json"
    out.parent.mkdir(exist_ok=True)
    subprocess.run([sys.executable, str(REPO / "tools" / "verify.py"), "--json", str(out)],
                   cwd=str(REPO), stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    return json.loads(out.read_text())


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", type=Path)
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()
    rep = load_report(args.report)
    results = rep["results"]

    matched = [r for r in results if r["status"] == "MATCH"]
    nonmatching = [r for r in results if r["status"] == "NONMATCHING"]
    scanned = len(results)
    matched_bytes = sum(r.get("object_size", 0) for r in matched)

    per_dir = collections.defaultdict(lambda: [0, 0])
    for r in results:
        top = Path(r["file"].replace("\\", "/")).parts[1] if len(Path(r["file"].replace("\\", "/")).parts) > 1 else "."
        per_dir[top][1] += 1
        if r["status"] == "MATCH":
            per_dir[top][0] += 1

    payload = {
        "functions_total": TOTAL_FUNCS,
        "functions_scanned": scanned,
        "functions_matched": len(matched),
        "functions_nonmatching": len(nonmatching),
        "matched_code_bytes": matched_bytes,
        "matched_pct_of_known": round(100 * len(matched) / TOTAL_FUNCS, 3),
        "matched_pct_of_scanned": round(100 * len(matched) / scanned, 2) if scanned else 0,
    }
    if args.json:
        json.dump(payload, sys.stdout, indent=2)
        sys.stdout.write("\n")
        return

    print("Persona 3 FES decompilation progress")
    print("=" * 40)
    print(f"functions in executable : {TOTAL_FUNCS}")
    print(f"functions with C        : {scanned} scanned")
    print(f"  MATCH                 : {len(matched)}  "
          f"({payload['matched_pct_of_known']}% of all, {payload['matched_pct_of_scanned']}% of written)")
    print(f"  NONMATCHING           : {len(nonmatching)}")
    print(f"matched code bytes      : {matched_bytes:,}")
    print()
    print("by directory (matched / written):")
    for d in sorted(per_dir):
        m, t = per_dir[d]
        print(f"  {d:20} {m:4d} / {t:4d}")


if __name__ == "__main__":
    main()
