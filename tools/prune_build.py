#!/usr/bin/env python3
"""Reclaim disk from build/ scratch.

Verify waves write a full-catalog JSON snapshot (~46 MB) per invocation, and each
matching attempt leaves a per-function scratch tree behind. Nothing ever removed
them, so build/ reached 61 GB across the two workspaces.

What is kept:
  * build/obj and build/cache      - the incremental build cache
  * build/baselines/*.json         - the most recent --keep-baselines gate reports
  * *.py and *.md anywhere         - lane tooling, decoded VU site tables, specs
  * the linked image and link maps - SLUS_216.21, *.elf, *.xMAP, *.lcf
  * anything modified within --min-age-hours, so a running lane is never cut

Everything else under build/ is a regenerable artifact: verify reports rebuild in
~90 s, objects rebuild from source, and *.orig backups only matter for the wave
that created them.

Usage:
    python tools/prune_build.py            # report only
    python tools/prune_build.py --apply    # delete
"""

import argparse
import os
import re
import time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

KEEP_DIRS = {"obj", "cache"}
KEEP_EXT = {".py", ".md"}
KEEP_ROOT_EXT = {".elf", ".xmap", ".lcf", ".21"}
KEEP_NAMES = {"SLUS_216.21"}
GATE_RE = re.compile(r"^W(\d+)_gate\.json$")


def baselines_to_keep(build_dir, keep_n):
    """Newest `keep_n` gate reports by wave number; the rest are regenerable."""
    d = os.path.join(build_dir, "baselines")
    if not os.path.isdir(d):
        return set()
    waves = []
    for name in os.listdir(d):
        m = GATE_RE.match(name)
        if m:
            waves.append((int(m.group(1)), name))
    waves.sort(reverse=True)
    return {name for _, name in waves[:keep_n]}


def plan(build_dir, min_age_s, keep_baselines):
    """Yield (path, size) for every prunable file under build_dir."""
    keep_gates = baselines_to_keep(build_dir, keep_baselines)
    now = time.time()
    for dirpath, _, filenames in os.walk(build_dir):
        rel = os.path.relpath(dirpath, build_dir)
        top = rel.split(os.sep)[0] if rel != "." else "."
        if top in KEEP_DIRS:
            continue
        for name in filenames:
            path = os.path.join(dirpath, name)
            try:
                st = os.stat(path)
            except OSError:
                continue
            ext = os.path.splitext(name)[1].lower()
            if ext in KEEP_EXT or name in KEEP_NAMES:
                continue
            if top == "." and ext in KEEP_ROOT_EXT:
                continue
            if top == "baselines" and name in keep_gates:
                continue
            if now - st.st_mtime < min_age_s:
                continue
            yield path, st.st_size


def drop_empty_dirs(build_dir):
    removed = 0
    for dirpath, _, _ in os.walk(build_dir, topdown=False):
        if dirpath == build_dir:
            continue
        try:
            if not os.listdir(dirpath):
                os.rmdir(dirpath)
                removed += 1
        except OSError:
            pass
    return removed


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true",
                    help="actually delete (default is a report)")
    ap.add_argument("--min-age-hours", type=float, default=2.0,
                    help="never touch files newer than this (default 2)")
    ap.add_argument("--keep-baselines", type=int, default=2,
                    help="gate reports to retain, newest first (default 2)")
    ap.add_argument("--build-dir", default=os.path.join(REPO, "build"))
    args = ap.parse_args()

    build_dir = os.path.abspath(args.build_dir)
    if not os.path.isdir(build_dir):
        raise SystemExit("no such build directory: " + build_dir)

    victims = list(plan(build_dir, args.min_age_hours * 3600, args.keep_baselines))
    total = sum(size for _, size in victims)

    print("build dir: %s" % build_dir)
    print("prunable:  %d files, %.2f GB" % (len(victims), total / 2 ** 30))

    if not args.apply:
        for path, size in sorted(victims, key=lambda t: -t[1])[:15]:
            print("   %8.1f MB  %s" % (size / 2 ** 20, os.path.relpath(path, build_dir)))
        print("\nre-run with --apply to delete")
        return

    freed = removed = failed = 0
    for path, size in victims:
        try:
            os.remove(path)
            freed += size
            removed += 1
        except OSError:
            failed += 1
    print("deleted %d files, freed %.2f GB (%d failed)"
          % (removed, freed / 2 ** 30, failed))
    print("removed %d empty directories" % drop_empty_dirs(build_dir))


if __name__ == "__main__":
    main()
