#!/usr/bin/env python3
"""Promote unambiguous SDK archive matches into a target symbol map.

The matcher report is evidence produced by sdk_match.py. This tool only applies
UNIQUE_NORMALIZED rows whose retail candidate has no competing SDK symbol and
whose current target symbol is an address placeholder. It never copies SDK
bytes into the repository.
"""

from pathlib import Path
import argparse
import json
import re

REPO = Path(__file__).resolve().parents[1]
EXPECTED_PROGRAMS = {"p3": "SLUS_216.21", "p4": "SLUS_217.82"}
PLACEHOLDER_RE = re.compile(r"(?:func|FUN)_[0-9A-Fa-f]{8}")
SYMBOL_LINE_RE = re.compile(
    r"^(?P<prefix>\s*)(?P<name>[A-Za-z_.$][\w.$]*)"
    r"(?P<between>\s*=\s*)(?P<address>0[xX][0-9A-Fa-f]+|\d+)"
    r"(?P<suffix>\s*;.*)$"
)
IDENTIFIER_RE = re.compile(r"^[A-Za-z_.$][\w.$]*$")


def resolve_target_root(target, explicit):
    if explicit:
        root = Path(explicit).resolve()
    elif target == "p4":
        root = (REPO.parent / "Persona4-Decompilation").resolve()
    else:
        root = REPO
    config = root / "config" / "symbol_addrs.txt"
    if not config.is_file():
        raise SystemExit(f"promote_sdk_symbols: missing target symbol map: {config}")
    return root


def parse_symbol_map(path):
    rows = []
    by_address = {}
    names = {}
    for line_number, line in enumerate(path.read_text(errors="replace").splitlines(), 1):
        match = SYMBOL_LINE_RE.match(line)
        if not match:
            continue
        address = int(match.group("address"), 0)
        row = {
            "line": line_number,
            "name": match.group("name"),
            "address": address,
            "text": line,
        }
        rows.append(row)
        by_address[address] = row
        names.setdefault(row["name"], []).append(row)
    return rows, by_address, names


def load_report(path):
    try:
        report = json.loads(Path(path).read_text())
    except (OSError, json.JSONDecodeError) as exc:
        raise SystemExit(f"promote_sdk_symbols: cannot read report {path}: {exc}") from exc
    if not isinstance(report.get("results"), list):
        raise SystemExit(f"promote_sdk_symbols: report has no results array: {path}")
    return report


def validate_report_target(target, report):
    expected = EXPECTED_PROGRAMS[target]
    actual = Path(str(report.get("retail", {}).get("program", ""))).name.upper()
    if actual != expected:
        raise SystemExit(
            f"promote_sdk_symbols: {target} requires {expected} evidence, got {actual or '<missing>'}"
        )

def eligible_rows(report, by_address, names):
    candidates = [
        item for item in report["results"]
        if item.get("status") == "UNIQUE_NORMALIZED"
        and len(item.get("candidates", [])) == 1
        and item["candidates"][0].get("known_names")
    ]
    # One address can be claimed by multiple SDK archive symbols. Do not choose
    # between them automatically; those are useful evidence but unsafe names.
    address_rows = {}
    for item in candidates:
        address_rows.setdefault(int(item["candidates"][0]["address"], 16), []).append(item)
    collisions = {address for address, rows in address_rows.items() if len(rows) > 1}

    selected = []
    skipped = []
    for item in candidates:
        address = int(item["candidates"][0]["address"], 16)
        sdk_name = item.get("name", "")
        current = by_address.get(address)
        reason = None
        if address in collisions:
            reason = "sdk_name_collision"
        elif current is None:
            reason = "missing_target_symbol"
        elif not PLACEHOLDER_RE.fullmatch(current["name"]):
            reason = "target_already_named"
        elif not IDENTIFIER_RE.fullmatch(sdk_name):
            reason = "invalid_sdk_name"
        elif any(row["address"] != address for row in names.get(sdk_name, [])):
            reason = "target_name_collision"
        if reason:
            skipped.append({"reason": reason, "item": item})
        else:
            selected.append({"item": item, "current": current, "address": address})
    selected.sort(key=lambda row: (row["address"], row["item"]["name"]))
    skipped.sort(key=lambda row: (row["reason"], row["item"].get("name", "")))
    return selected, skipped, collisions


def source_files(root):
    for directory in (root / "src", root / "include"):
        if not directory.is_dir():
            continue
        for path in sorted(directory.rglob("*")):
            if path.is_file():
                yield path


def source_replacements(root, replacements):
    changes = []
    for path in source_files(root):
        original = path.read_text(errors="replace")
        updated = original
        for old, new in replacements.items():
            updated = re.sub(r"\b" + re.escape(old) + r"\b", new, updated)
        if updated != original:
            changes.append((path, original, updated))
    return changes


def provenance_text(target_root, report, selected, skipped, collisions):
    retail = report.get("retail", {})
    lines = [
        "# Archive-backed SCE symbol promotions.",
        "# Generated by the shared sdk_match.py/promote_sdk_symbols.py workflow.",
        "# Evidence status is UNIQUE_NORMALIZED: non-relocated bytes and the",
        "# canonical target boundary matched one P3/P4 retail candidate.",
        "# This file contains names and hashes only; it contains no SDK object bytes.",
        f"# target_repository = {target_root.name}",
        f"# target_program = {retail.get('program', '')}",
        f"# retail_sha1 = {retail.get('sha1', '')}",
        f"# promoted = {len(selected)}",
        f"# skipped = {len(skipped)}",
        f"# sdk_name_collisions = {len(collisions)}",
        "#",
        "# name = address; // archive:member; size:bytes; canonical_sha256:hash",
    ]
    for row in selected:
        item = row["item"]
        candidate = item["candidates"][0]
        lines.append(
            f"{item['name']} = {candidate['address']}; // "
            f"archive:{item['archive']}:{item['member']}; "
            f"size:{item['size']}; canonical_sha256:{item['canonical_sha256']}"
        )
    return "\n".join(lines) + "\n"


def apply_promotions(target_root, selected, report, skipped, collisions, update_sources):
    symbol_path = target_root / "config" / "symbol_addrs.txt"
    lines = symbol_path.read_text(errors="replace").splitlines(keepends=True)
    replacements = {}
    for row in selected:
        replacements[row["current"]["name"]] = row["item"]["name"]

    by_line = {row["current"]["line"]: row for row in selected}
    rewritten = []
    for line_number, line in enumerate(lines, 1):
        row = by_line.get(line_number)
        if row is None:
            rewritten.append(line)
            continue
        line_ending = "\n" if line.endswith("\n") else ""
        body = line[:-1] if line_ending else line
        match = SYMBOL_LINE_RE.match(body)
        if not match:
            raise RuntimeError(f"symbol line changed unexpectedly at {symbol_path}:{line_number}")
        rewritten.append(
            f"{match.group('prefix')}{row['item']['name']}{match.group('between')}"
            f"{match.group('address')}{match.group('suffix')}{line_ending}"
        )
    symbol_path.write_text("".join(rewritten), newline="")

    changed_sources = []
    if update_sources:
        changed_sources = source_replacements(target_root, replacements)
        for path, _original, updated in changed_sources:
            path.write_text(updated, newline="")

    provenance_path = target_root / "config" / "sdk_symbol_provenance.txt"
    provenance_path.write_text(
        provenance_text(target_root, report, selected, skipped, collisions), newline="\n")
    return changed_sources, provenance_path


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--target", choices=("p3", "p4"), default="p3")
    parser.add_argument("--target-root", help="target repository root")
    parser.add_argument("--report", required=True, help="sdk_match.py JSON report")
    parser.add_argument("--apply", action="store_true", help="write promotions; default is dry-run")
    parser.add_argument("--update-sources", action="store_true",
                        help="rename promoted placeholder references in src/ and include/")
    args = parser.parse_args()

    target_root = resolve_target_root(args.target, args.target_root)
    report = load_report(args.report)
    validate_report_target(args.target, report)
    symbol_path = target_root / "config" / "symbol_addrs.txt"
    _rows, by_address, names = parse_symbol_map(symbol_path)
    selected, skipped, collisions = eligible_rows(report, by_address, names)

    print(f"target repository: {target_root}")
    print(f"report program: {report.get('retail', {}).get('program')}")
    print(f"eligible promotions: {len(selected)}")
    print(f"skipped rows: {len(skipped)}")
    print(f"SDK name collisions: {len(collisions)}")
    if args.update_sources:
        changes = source_replacements(
            target_root,
            {row["current"]["name"]: row["item"]["name"] for row in selected})
        print(f"source files requiring renames: {len(changes)}")
        for path, _original, _updated in changes:
            print(f"  {path.relative_to(target_root)}")

    if not args.apply:
        print("dry-run: pass --apply to write symbol and provenance files")
        return

    changed_sources, provenance_path = apply_promotions(
        target_root, selected, report, skipped, collisions, args.update_sources)
    print(f"promoted symbols: {len(selected)}")
    print(f"renamed source files: {len(changed_sources)}")
    print(f"provenance: {provenance_path}")


if __name__ == "__main__":
    main()
