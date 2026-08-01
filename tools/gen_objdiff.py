#!/usr/bin/env python3
"""Generate objdiff (https://github.com/encounter/objdiff) inputs.

For every eligible C translation unit this writes a matching pair of objects:
  build/objdiff/target/<unit>.o   assembled from the retail splat asm (expected)
  build/objdiff/base/<unit>.o     compiled from src/ via mwccgap (current)
and an objdiff.json listing them, so `objdiff` can show a live symbol-by-symbol
diff of the decompiled C against retail.

Usage:  python tools/gen_objdiff.py
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import build as B  # noqa: E402
import build_cache as BC  # noqa: E402
import asm as A  # noqa: E402

TARGET = REPO / "build" / "objdiff" / "target"
BASE = REPO / "build" / "objdiff" / "base"


def unit_asm(name, seg_lo, seg_hi, start, end):
    """Assemble one TU's retail asm blocks into a target object."""
    src = B.ASM / f"{name}.s"
    preamble, blocks = B.split_blocks(src.read_text())
    body = [ln for addr, blk in blocks if addr is not None and start <= addr < end for ln in blk]
    if not body:
        return None
    TARGET.mkdir(parents=True, exist_ok=True)
    spath = TARGET / "_tmp.s"
    spath.write_text("".join(preamble) + "".join(body))
    obj = TARGET / "unit.o"
    ok, log, _ = A.assemble(spath, obj, B.AS_TOOL, B.OBJCOPY_TOOL,
                            ref=B.IMAGE.read_bytes(), vram=start, ref_lo=start - B.VRAM, keep_text=True)
    if not ok:
        sys.stderr.write(log + "\n")
        return None
    return obj


def main():
    c = B.cfg()
    B.AS_TOOL = A.find_gnu_tool("mipsel-linux-gnu-as", "P3_AS")
    B.OBJCOPY_TOOL = A.find_gnu_tool("mipsel-linux-gnu-objcopy", "P3_OBJCOPY")
    gp, defs = B.load_lcf_symbols()
    resolvable = set(defs) | B.load_symbol_names()
    boundaries = B.load_windows()
    cache = BC.ObjectCache(REPO / "build" / "cache" / "c", REPO)
    cobjs = B.eligible_c_objects(c, resolvable, boundaries, gp, cache)

    TARGET.mkdir(parents=True, exist_ok=True)
    BASE.mkdir(parents=True, exist_ok=True)
    units = []
    for o in cobjs:
        rel = o["src"].relative_to(REPO / "src").as_posix()
        stem = rel.replace("/", "_").removesuffix(".c")
        # which segment holds this TU
        seg = next((s for s in B.SEGMENTS if s[1] == "code"
                    and B.VRAM + s[2] <= o["start"] < B.VRAM + s[3]), None)
        if not seg:
            continue
        tgt = unit_asm(seg[0], B.VRAM + seg[2], B.VRAM + seg[3], o["start"], o["end"])
        if tgt is None:
            continue
        tgt_final = TARGET / f"{stem}.o"
        tgt.replace(tgt_final)
        base = BASE / f"{stem}.o"
        B.compile_c(c, o["src"], base, cache)
        units.append({
            "name": rel,
            "target_path": f"build/objdiff/target/{stem}.o",
            "base_path": f"build/objdiff/base/{stem}.o",
            "metadata": {"complete": True},
        })

    for junk in (TARGET / "_tmp.s", TARGET / "unit.o"):
        junk.unlink(missing_ok=True)

    config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "make",
        "build_target": False,
        "watch_patterns": ["*.c", "*.h", "*.s"],
        "units": units,
    }
    (REPO / "objdiff.json").write_text(json.dumps(config, indent=2) + "\n")
    print(f"objdiff: wrote objdiff.json with {len(units)} units")


if __name__ == "__main__":
    main()
