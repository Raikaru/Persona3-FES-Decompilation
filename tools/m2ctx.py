#!/usr/bin/env python3
"""Generate a self-contained C context for decomp.me / the permuter.

Recursively inlines project (`#include "..."`) headers from include/ into one
file so a function can be pasted into decomp.me with the mwccps2 compiler. System
includes (`#include <...>`) are left as-is. Output goes to ctx.c by default.

Usage:
  python tools/m2ctx.py src/Battle/btlFade.c        # -> ctx.c
  python tools/m2ctx.py src/Battle/btlFade.c -o out.c
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
INCLUDE_DIRS = [REPO / "include", REPO]
QUOTE_INC = re.compile(r'^\s*#\s*include\s*"([^"]+)"')


def resolve(inc: str, current: Path) -> Path | None:
    for base in [current.parent, *INCLUDE_DIRS]:
        cand = (base / inc).resolve()
        if cand.is_file():
            return cand
    return None


def inline(path: Path, seen: set[Path], out: list[str]) -> None:
    rp = path.resolve()
    if rp in seen:
        return
    seen.add(rp)
    for line in path.read_text(errors="replace").splitlines():
        m = QUOTE_INC.match(line)
        if m:
            target = resolve(m.group(1), path)
            if target is not None:
                inline(target, seen, out)
                continue
        out.append(line)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("c_file", type=Path)
    ap.add_argument("-o", "--output", type=Path, default=REPO / "ctx.c")
    args = ap.parse_args()
    out: list[str] = []
    inline(args.c_file, set(), out)
    args.output.write_text("\n".join(out) + "\n")
    print(f"wrote {args.output} ({len(out)} lines)")


if __name__ == "__main__":
    main()
