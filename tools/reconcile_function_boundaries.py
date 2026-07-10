#!/usr/bin/env python3
"""Reconcile verified source markers with the canonical retail function boundaries."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path

from verify import REPO, TOOLS, scan_markers


METADATA = TOOLS / "slus21621_functions.json"


def is_generated(path: Path) -> bool:
    return path.name.endswith(".match.c") or path.name.startswith(".permute_")


def source_markers() -> dict[int, list[tuple[Path, dict]]]:
    markers: dict[int, list[tuple[Path, dict]]] = defaultdict(list)
    for path in sorted(p for p in (REPO / "src").rglob("*.c") if not is_generated(p)):
        for marker in scan_markers(path):
            markers[marker["addr"]].append((path.relative_to(REPO), marker))
    return markers

def reconciled_windows(old_windows: dict[int, int], source: set[int]) -> dict[str, int]:
    boundaries = sorted(set(old_windows) | source)
    windows: dict[str, int] = {}
    for index, address in enumerate(boundaries):
        next_address = boundaries[index + 1] if index + 1 < len(boundaries) else None
        if address in old_windows:
            size = old_windows[address]
            if next_address is not None:
                size = min(size, next_address - address)
        elif next_address is not None:
            size = next_address - address
        else:
            raise ValueError(f"cannot infer final window at {address:08x}")
        windows[f"{address:08x}"] = size
    return windows


def format_locations(entries: list[tuple[Path, dict]]) -> str:
    return ", ".join(f"{path}:{marker['line']} ({marker['name']})" for path, marker in entries)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--write", action="store_true", help="rewrite the canonical metadata")
    parser.add_argument("--write-map", action="store_true", help="rewrite build/function_map.txt")
    parser.add_argument(
        "--base",
        type=Path,
        help="metadata whose original Ghidra windows must be preserved",
    )
    args = parser.parse_args()

    metadata = json.loads(METADATA.read_text())
    base_metadata = json.loads(args.base.read_text()) if args.base else metadata
    canonical = {int(address, 16) for address in base_metadata["windows"]}
    markers = source_markers()
    source = set(markers)
    duplicates = {address: entries for address, entries in markers.items() if len(entries) > 1}
    nameless = {
        address: entries
        for address, entries in markers.items()
        if any(marker["name"] is None for _path, marker in entries)
    }

    print(f"canonical boundaries: {len(canonical)}")
    print(f"unique source markers: {len(source)}")
    print(f"canonical without source: {len(canonical - source)}")
    print(f"source-only boundaries: {len(source - canonical)}")
    print(f"duplicate source addresses: {len(duplicates)}")
    print(f"markers without definitions: {len(nameless)}")

    for label, problems in (("duplicate", duplicates), ("nameless", nameless)):
        for address, entries in sorted(problems.items()):
            print(f"{label} {address:08x}: {format_locations(entries)}")

    if duplicates or nameless:
        return 1
    if not args.write and not args.write_map:
        return 0

    old_windows = {
        int(address, 16): size for address, size in base_metadata["windows"].items()
    }
    windows = reconciled_windows(old_windows, source)
    boundaries = sorted(old_windows.keys() | source)

    if args.write:
        metadata["function_count"] = len(boundaries)
        metadata["generated_from"] = (
            "Ghidra function list plus verified source marker boundaries "
            "(tools/reconcile_function_boundaries.py)"
        )
        metadata["windows"] = windows
        METADATA.write_text(json.dumps(metadata, indent=1) + "\n", newline="\n")
        print(f"wrote {METADATA.relative_to(REPO)} with {len(boundaries)} boundaries")

    if args.write or args.write_map:
        rows = []
        for address in boundaries:
            entries = markers.get(address)
            if entries:
                path, _marker = entries[0]
                rows.append(f"{address:08x} {windows[f'{address:08x}']:>6} MAPPED   {path}")
            else:
                rows.append(f"{address:08x} {windows[f'{address:08x}']:>6} UNMAPPED")
        function_map = REPO / "build" / "function_map.txt"
        function_map.write_text("\n".join(rows) + "\n", newline="\n")
        print(f"wrote {function_map.relative_to(REPO)} with {len(rows)} boundaries")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
