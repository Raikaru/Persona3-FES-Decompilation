#!/usr/bin/env python3
"""Report decompilation progress and generate validated progress endpoints.

Usage:
  python tools/progress.py                 # run verify.py and report
  python tools/progress.py --report build/verify_report.json
  python tools/progress.py --json          # machine-readable progress summary
  python tools/progress.py --report REPORT --linked-report REPORT --write-dir progress
  python tools/progress.py --validate-dir progress
"""
from __future__ import annotations

import argparse
import collections
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Any

REPO = Path(__file__).resolve().parents[1]
METADATA = REPO / "tools" / "slus21621_functions.json"
SCHEMA_VERSION = 1
CACHE_SECONDS = 3600


class ProgressError(ValueError):
    """Raised for invalid progress inputs or generated endpoint files."""


def load_json(path: Path, description: str) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ProgressError(f"{description} is missing: {path}") from exc
    except OSError as exc:
        raise ProgressError(f"cannot read {description}: {path}: {exc}") from exc
    except json.JSONDecodeError as exc:
        raise ProgressError(f"malformed {description}: {path}: {exc}") from exc


def load_windows(path: Path = METADATA) -> dict[int, int | None]:
    """Load the function-window map, failing explicitly on malformed metadata."""
    metadata = load_json(path, "function metadata")
    if not isinstance(metadata, dict):
        raise ProgressError("malformed function metadata: top level must be an object")
    windows = metadata.get("windows")
    if not isinstance(windows, dict) or not windows:
        raise ProgressError("malformed function metadata: 'windows' must be a non-empty object")

    parsed: dict[int, int | None] = {}
    for address, size in windows.items():
        if not isinstance(address, str):
            raise ProgressError("malformed function metadata: window addresses must be strings")
        try:
            numeric_address = int(address, 16)
        except ValueError as exc:
            raise ProgressError(f"malformed function metadata: invalid window address {address!r}") from exc
        if numeric_address in parsed:
            raise ProgressError(f"malformed function metadata: duplicate window address {address!r}")
        if size is not None and (not isinstance(size, int) or isinstance(size, bool) or size < 0):
            raise ProgressError(f"malformed function metadata: invalid window size for {address!r}")
        parsed[numeric_address] = size
    return parsed


def load_report(path: Path | None) -> tuple[dict[str, Any], str]:
    if path is not None:
        return load_json(path, "verifier report"), str(path)
    out = REPO / "build" / "verify_report.json"
    out.parent.mkdir(exist_ok=True)
    subprocess.run(
        [sys.executable, str(REPO / "tools" / "verify.py"), "--json", str(out)],
        cwd=str(REPO),
        stdout=subprocess.DEVNULL,
        stderr=subprocess.STDOUT,
        check=False,
    )
    return load_json(out, "verifier report"), str(out)


def canonical_address(address: Any) -> int:
    """Return a verifier address encoded as an integer or an unprefixed hex string."""
    if isinstance(address, int) and not isinstance(address, bool):
        return address
    if (isinstance(address, str)
            and address
            and all(character in "0123456789abcdefABCDEF" for character in address)):
        return int(address, 16)
    raise ProgressError("malformed verifier report: every result needs an integer or hexadecimal string addr")

def canonical_linked_address(address: Any) -> int:
    """Validate and parse a canonical link-manifest address."""
    if (not isinstance(address, str)
            or len(address) != 8
            or any(character not in "0123456789abcdef" for character in address)):
        raise ProgressError(
            "malformed linked report: linked function address must be an 8-digit lowercase hexadecimal string"
        )
    return int(address, 16)




def report_results(report: dict[str, Any], windows: dict[int, int | None]) -> list[dict[str, Any]]:
    """Validate verifier rows without requiring every verifier label to be a window."""
    if not isinstance(report, dict) or not isinstance(report.get("results"), list):
        raise ProgressError("malformed verifier report: 'results' must be a list")

    results = report["results"]
    for row in results:
        if not isinstance(row, dict) or not isinstance(row.get("status"), str):
            raise ProgressError("malformed verifier report: every result needs a string status")
        canonical_address(row.get("addr"))
    return results


def matching_diagnostics(
    results: list[dict[str, Any]], windows: dict[int, int | None],
) -> tuple[set[int], int, int, int, int]:
    """Summarize known verifier rows while treating aliases as one mapped function."""
    known_addresses: set[int] = set()
    matched_addresses: set[int] = set()
    known_rows = 0
    duplicate_rows = 0
    ignored_unknown_rows = 0
    for row in results:
        address = canonical_address(row["addr"])
        if address not in windows:
            ignored_unknown_rows += 1
            continue
        known_rows += 1
        if address in known_addresses:
            duplicate_rows += 1
        known_addresses.add(address)
        if row["status"] == "MATCH":
            matched_addresses.add(address)
    return matched_addresses, known_rows, len(known_addresses), duplicate_rows, ignored_unknown_rows


def percentage(count: int, total: int) -> float:
    return round(100 * count / total, 3) if total else 0.0


def progress_color(percent: float) -> str:
    if percent == 0:
        return "red"
    if percent < 25:
        return "orange"
    if percent < 50:
        return "yellow"
    if percent < 75:
        return "yellowgreen"
    if percent < 100:
        return "green"
    return "brightgreen"


def badge(label: str, count: int, total: int) -> dict[str, Any]:
    percent = percentage(count, total)
    return {
        "schemaVersion": SCHEMA_VERSION,
        "label": label,
        "message": f"{count}/{total} ({percent:.3f}%)",
        "color": progress_color(percent),
        "cacheSeconds": CACHE_SECONDS,
    }


def validate_linked_report(report: Any, windows: dict[int, int | None]) -> dict[str, Any]:
    if not isinstance(report, dict):
        raise ProgressError("malformed linked report: top level must be an object")
    required = (
        "schema_version", "build_succeeded", "image_sha1", "retail_sha1",
        "function_total", "linked_tu_count", "linked_function_count", "linked_functions",
    )
    missing = [field for field in required if field not in report]
    if missing:
        raise ProgressError(f"malformed linked report: missing {', '.join(missing)}")
    if report["schema_version"] != SCHEMA_VERSION:
        raise ProgressError(f"unsupported linked report schema_version: {report['schema_version']!r}")
    if report["build_succeeded"] is not True:
        raise ProgressError("linked report says build_succeeded is not true")
    for field in ("image_sha1", "retail_sha1"):
        if not isinstance(report[field], str) or not report[field]:
            raise ProgressError(f"malformed linked report: {field} must be a non-empty string")
    if report["function_total"] != len(windows):
        raise ProgressError("linked report function_total does not match function metadata")
    functions = report["linked_functions"]
    if not isinstance(functions, list):
        raise ProgressError("malformed linked report: linked_functions must be a list")

    addresses: set[int] = set()
    files: set[str] = set()
    for row in functions:
        if not isinstance(row, dict):
            raise ProgressError("malformed linked report: linked_functions entries must be objects")
        address = canonical_linked_address(row.get("address"))
        if address in addresses:
            raise ProgressError(f"malformed linked report: duplicate linked address 0x{address:08x}")
        if address not in windows:
            raise ProgressError(f"malformed linked report: unknown linked address 0x{address:08x}")
        if not isinstance(row.get("name"), str) or not row["name"]:
            raise ProgressError("malformed linked report: linked function name must be a non-empty string")
        if not isinstance(row.get("file"), str) or not row["file"]:
            raise ProgressError("malformed linked report: linked function file must be a non-empty string")
        addresses.add(address)
        files.add(row["file"])

    if report["linked_function_count"] != len(addresses):
        raise ProgressError("linked report linked_function_count does not agree with linked_functions")
    if report["linked_tu_count"] != len(files):
        raise ProgressError("linked report linked_tu_count does not agree with linked function files")
    return report


def make_metrics(
    report: dict[str, Any], windows: dict[int, int | None], linked_report: dict[str, Any] | None,
    verifier_source: str, linked_source: str | None,
) -> tuple[dict[str, Any], dict[str, Any], dict[str, Any]]:
    results = report_results(report, windows)
    status_counts = dict(sorted(collections.Counter(row["status"] for row in results).items()))
    matched_addresses, known_rows, unique_known_addresses, duplicate_rows, ignored_unknown_rows = (
        matching_diagnostics(results, windows)
    )
    matched_bytes_by_address: dict[int, int] = {}
    for row in results:
        address = canonical_address(row["addr"])
        object_size = row.get("object_size")
        if (address in matched_addresses
                and row["status"] == "MATCH"
                and isinstance(object_size, int)
                and not isinstance(object_size, bool)
                and object_size >= 0):
            matched_bytes_by_address[address] = max(matched_bytes_by_address.get(address, 0), object_size)
    matching = len(matched_addresses)
    matched_bytes = sum(matched_bytes_by_address.values())
    total = len(windows)
    matching_addresses = [f"{address:08x}" for address in sorted(matched_addresses)]
    linked_addresses: list[str] = []
    hashes: dict[str, str | None] = {"retail_sha1": None, "image_sha1": None}
    build_succeeded = False
    if linked_report is not None:
        linked_numeric_addresses = {
            canonical_linked_address(row["address"])
            for row in linked_report["linked_functions"]
        }
        for address in sorted(linked_numeric_addresses):
            if address not in matched_addresses:
                raise ProgressError(
                    f"linked address {address:08x} is not in the matching address set"
                )
        linked_addresses = [f"{address:08x}" for address in sorted(linked_numeric_addresses)]
        hashes = {"retail_sha1": linked_report["retail_sha1"], "image_sha1": linked_report["image_sha1"]}
        build_succeeded = linked_report["build_succeeded"]
    metrics = {
        "schema_version": SCHEMA_VERSION,
        "source": {
            "verifier_report": verifier_source,
            "linked_report": linked_source,
            "raw_rows": len(results),
            "ignored_unknown_rows": ignored_unknown_rows,
        },
        "total": total,
        "matching": {
            "count": len(matching_addresses),
            "percent": percentage(len(matching_addresses), total),
            "addresses": matching_addresses,
            "matched_body_bytes": matched_bytes,
            "known_rows": known_rows,
            "unique_known_addresses": unique_known_addresses,
            "duplicate_rows": duplicate_rows,
        },
        "linked": {
            "count": len(linked_addresses),
            "percent": percentage(len(linked_addresses), total),
            "addresses": linked_addresses,
        },
        "status_counts": status_counts,
        "hashes": hashes,
        "build_succeeded": build_succeeded,
    }
    return metrics, badge("matching", matching, total), badge("linked", len(linked_addresses), total)


def atomic_write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=f".{path.name}.", suffix=".tmp", dir=path.parent, text=True)
    try:
        with os.fdopen(fd, "w", encoding="utf-8", newline="\n") as handle:
            json.dump(payload, handle, indent=2, sort_keys=True)
            handle.write("\n")
        os.replace(temporary, path)
    except BaseException:
        try:
            os.unlink(temporary)
        except FileNotFoundError:
            pass
        raise


def write_endpoints(directory: Path, metrics: dict[str, Any], matching_badge: dict[str, Any], linked_badge: dict[str, Any]) -> None:
    atomic_write_json(directory / "metrics.json", metrics)
    atomic_write_json(directory / "matching.json", matching_badge)
    atomic_write_json(directory / "linked.json", linked_badge)


def validate_badge(payload: Any, label: str, count: int, total: int) -> None:
    expected = badge(label, count, total)
    if payload != expected:
        raise ProgressError(f"invalid {label}.json: expected schema, message, and color do not agree with metrics")


def validate_address_list(value: Any, name: str, windows: dict[int, int | None]) -> set[str]:
    """Validate a canonical endpoint address list against function metadata."""
    if not isinstance(value, list):
        raise ProgressError(f"malformed metrics endpoint: {name} addresses must be a list")

    addresses: set[str] = set()
    for address in value:
        if (not isinstance(address, str)
                or len(address) != 8
                or any(character not in "0123456789abcdef" for character in address)):
            raise ProgressError(
                f"invalid metrics endpoint: {name} address must be canonical lowercase 8-digit hex"
            )
        if address in addresses:
            raise ProgressError(f"invalid metrics endpoint: duplicate {name} address {address}")
        if int(address, 16) not in windows:
            raise ProgressError(f"invalid metrics endpoint: unknown {name} address {address}")
        addresses.add(address)
    return addresses


def validate_endpoints(directory: Path, windows: dict[int, int | None]) -> None:
    metrics = load_json(directory / "metrics.json", "metrics endpoint")
    matching_badge = load_json(directory / "matching.json", "matching endpoint")
    linked_badge = load_json(directory / "linked.json", "linked endpoint")
    if not isinstance(metrics, dict):
        raise ProgressError("malformed metrics endpoint: top level must be an object")
    required = {"schema_version", "source", "total", "matching", "linked", "status_counts", "hashes", "build_succeeded"}
    missing = sorted(required - metrics.keys())
    if missing:
        raise ProgressError(f"malformed metrics endpoint: missing {', '.join(missing)}")
    if metrics["schema_version"] != SCHEMA_VERSION:
        raise ProgressError("invalid metrics endpoint schema_version")
    if metrics["total"] != len(windows):
        raise ProgressError("invalid metrics endpoint total")
    if not isinstance(metrics["matching"], dict) or not isinstance(metrics["linked"], dict):
        raise ProgressError("malformed metrics endpoint: matching and linked must be objects")
    if not isinstance(metrics["status_counts"], dict):
        raise ProgressError("malformed metrics endpoint: status_counts must be an object")
    status_counts = metrics["status_counts"]
    if any(not isinstance(status, str) or not isinstance(count, int) or isinstance(count, bool) or count < 0
           for status, count in status_counts.items()):
        raise ProgressError("malformed metrics endpoint: invalid status count")
    source = metrics["source"]
    hashes = metrics["hashes"]
    if (not isinstance(source, dict)
            or not isinstance(source.get("verifier_report"), str)
            or not source["verifier_report"]
            or not isinstance(source.get("linked_report"), str)
            or not source["linked_report"]):
        raise ProgressError("malformed metrics endpoint: invalid source report provenance")
    raw_rows = source.get("raw_rows")
    ignored_unknown_rows = source.get("ignored_unknown_rows")
    if (not isinstance(raw_rows, int)
            or isinstance(raw_rows, bool)
            or raw_rows < 0
            or not isinstance(ignored_unknown_rows, int)
            or isinstance(ignored_unknown_rows, bool)
            or ignored_unknown_rows < 0
            or ignored_unknown_rows > raw_rows):
        raise ProgressError("invalid metrics endpoint: source row diagnostics")
    if sum(status_counts.values()) != raw_rows:
        raise ProgressError("invalid metrics endpoint: raw rows must equal status count total")
    if (not isinstance(hashes, dict)
            or not isinstance(hashes.get("retail_sha1"), str)
            or not hashes["retail_sha1"]
            or not isinstance(hashes.get("image_sha1"), str)
            or not hashes["image_sha1"]):
        raise ProgressError("malformed metrics endpoint: invalid build hashes")
    if metrics["build_succeeded"] is not True:
        raise ProgressError("invalid metrics endpoint: build_succeeded must be true")
    matched_body_bytes = metrics["matching"].get("matched_body_bytes")
    if (not isinstance(matched_body_bytes, int)
            or isinstance(matched_body_bytes, bool)
            or matched_body_bytes < 0):
        raise ProgressError("invalid metrics endpoint: matched_body_bytes")
    matching_count = metrics["matching"].get("count")
    linked_count = metrics["linked"].get("count")
    known_rows = metrics["matching"].get("known_rows")
    unique_known_addresses = metrics["matching"].get("unique_known_addresses")
    duplicate_rows = metrics["matching"].get("duplicate_rows")
    diagnostic_counts = (
        ("known_rows", known_rows),
        ("unique_known_addresses", unique_known_addresses),
        ("duplicate_rows", duplicate_rows),
    )
    if any(not isinstance(count, int) or isinstance(count, bool) or count < 0
           for _, count in diagnostic_counts):
        raise ProgressError("invalid metrics endpoint: matching row diagnostics")
    if known_rows + ignored_unknown_rows != raw_rows:
        raise ProgressError("invalid metrics endpoint: known and ignored rows must equal raw rows")
    if unique_known_addresses > known_rows or duplicate_rows != known_rows - unique_known_addresses:
        raise ProgressError("invalid metrics endpoint: inconsistent matching row diagnostics")
    if unique_known_addresses > len(windows):
        raise ProgressError("invalid metrics endpoint: too many unique known addresses")
    for name, count in (("matching", matching_count), ("linked", linked_count)):
        value = metrics[name]
        if not isinstance(count, int) or isinstance(count, bool) or count < 0 or count > len(windows):
            raise ProgressError(f"invalid metrics endpoint: {name} count")
        if value.get("percent") != percentage(count, len(windows)):
            raise ProgressError(f"invalid metrics endpoint: {name} percent")
    matching_addresses = validate_address_list(
        metrics["matching"].get("addresses"), "matching", windows,
    )
    linked_addresses = validate_address_list(
        metrics["linked"].get("addresses"), "linked", windows,
    )
    if matching_count != len(matching_addresses):
        raise ProgressError("invalid metrics endpoint: matching count does not agree with addresses")
    if linked_count != len(linked_addresses):
        raise ProgressError("invalid metrics endpoint: linked count does not agree with addresses")
    if matching_count > unique_known_addresses:
        raise ProgressError("invalid metrics endpoint: matching count exceeds unique known addresses")
    if linked_count > matching_count:
        raise ProgressError("invalid metrics endpoint: linked count cannot exceed matching count")
    if not linked_addresses.issubset(matching_addresses):
        raise ProgressError("invalid metrics endpoint: linked addresses must be a subset of matching addresses")
    validate_badge(matching_badge, "matching", matching_count, len(windows))
    validate_badge(linked_badge, "linked", linked_count, len(windows))


def print_human(report: dict[str, Any], windows: dict[int, int | None], metrics: dict[str, Any]) -> None:
    results = report_results(report, windows)
    per_dir: dict[str, list[int]] = collections.defaultdict(lambda: [0, 0])
    for row in results:
        file = str(row.get("file", ""))
        pieces = Path(file.replace("\\", "/")).parts
        top = pieces[1] if len(pieces) > 1 else "."
        per_dir[top][1] += 1
        if row["status"] == "MATCH":
            per_dir[top][0] += 1

    matching = metrics["matching"]
    print("Persona 3 FES decompilation progress")
    print("=" * 40)
    print(f"functions in executable : {len(windows)}")
    print(f"functions with C        : {len(results)} scanned")
    print(f"  MATCH                 : {matching['count']}  ({matching['percent']}% of all)")
    for status, count in metrics["status_counts"].items():
        if status != "MATCH":
            print(f"  {status:21}: {count}")
    print(f"matched code bytes      : {matching['matched_body_bytes']:,}")
    print()
    print("by directory (matched / written):")
    for directory in sorted(per_dir):
        matched, written = per_dir[directory]
        print(f"  {directory:20} {matched:4d} / {written:4d}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", type=Path)
    ap.add_argument("--linked-report", type=Path)
    ap.add_argument("--write-dir", type=Path)
    ap.add_argument("--validate-dir", type=Path)
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    try:
        windows = load_windows()
        if args.validate_dir is not None:
            if args.report is not None or args.linked_report is not None or args.write_dir is not None or args.json:
                raise ProgressError("--validate-dir cannot be combined with report, write, or json options")
            validate_endpoints(args.validate_dir, windows)
            return

        report, verifier_source = load_report(args.report)
        linked_report = None
        linked_source = None
        if args.linked_report is not None:
            linked_report = validate_linked_report(load_json(args.linked_report, "linked report"), windows)
            linked_source = str(args.linked_report)
        if args.write_dir is not None and linked_report is None:
            raise ProgressError("--write-dir requires a successful --linked-report")

        metrics, matching_badge, linked_badge = make_metrics(
            report, windows, linked_report, verifier_source, linked_source,
        )
        if args.write_dir is not None:
            write_endpoints(args.write_dir, metrics, matching_badge, linked_badge)
        if args.json:
            raw_rows = metrics["source"]["raw_rows"]
            json.dump({
                "functions_total": metrics["total"],
                "functions_scanned": raw_rows,
                "functions_matched": metrics["matching"]["count"],
                "functions_nonmatching": metrics["status_counts"].get("NONMATCHING", 0),
                "matched_code_bytes": metrics["matching"]["matched_body_bytes"],
                "matched_pct_of_known": metrics["matching"]["percent"],
                "matched_pct_of_scanned": round(
                    100 * metrics["matching"]["count"] / raw_rows, 2,
                ) if raw_rows else 0,
            }, sys.stdout, indent=2)
            sys.stdout.write("\n")
        else:
            print_human(report, windows, metrics)
    except ProgressError as exc:
        print(f"progress: error: {exc}", file=sys.stderr)
        raise SystemExit(2) from exc


if __name__ == "__main__":
    main()
