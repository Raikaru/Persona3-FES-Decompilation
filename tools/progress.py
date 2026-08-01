#!/usr/bin/env python3
"""Report decompilation progress and generate validated progress endpoints.

The published progress scope is the explicit essential-function policy in
``config/function_scope.json``. Replaceable vendor/runtime/generic machinery is
excluded; whole-executable verifier totals remain under ``whole_executable``.

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
import provenance
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Any

REPO = Path(__file__).resolve().parents[1]
METADATA = REPO / "tools" / "slus21621_functions.json"
SCHEMA_VERSION = 1
CACHE_SECONDS = 3600


def repo_relative(path):
    """Render a path relative to the repository root.

    Reports are committed, so an absolute path would leak the author's
    machine layout into version control.
    """
    try:
        return Path(path).resolve().relative_to(REPO).as_posix()
    except (TypeError, ValueError):
        return str(path)


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
    """Validate verifier rows and their source provenance."""
    if not isinstance(report, dict) or not isinstance(report.get("results"), list):
        raise ProgressError("malformed verifier report: 'results' must be a list")

    results = report["results"]
    for row in results:
        if not isinstance(row, dict) or not isinstance(row.get("status"), str):
            raise ProgressError("malformed verifier report: every result needs a string status")
        canonical_address(row.get("addr"))
        if not isinstance(row.get("file"), str) or not row["file"]:
            raise ProgressError("malformed verifier report: every result needs a source file")
    return results


def scope_diagnostics(
    results: list[dict[str, Any]],
    windows: dict[int, int | None],
    completion_scope: str | None = None,
    policy: dict[str, Any] | None = None,
) -> dict[str, Any]:
    """Summarize rows in the whole image or one completion-gate scope."""
    if completion_scope is not None and policy is None:
        raise ProgressError("completion-scope diagnostics require a function scope policy")
    scoped_rows = [
        row for row in results
        if completion_scope is None
        or provenance.classify_function_scope(
            row["file"], row.get("name"), row["addr"], policy,
        )[0] == completion_scope
    ]
    known_addresses: set[int] = set()
    matched_addresses: set[int] = set()
    matched_bytes_by_address: dict[int, int] = {}
    known_rows = 0
    duplicate_rows = 0
    ignored_unknown_rows = 0
    for row in scoped_rows:
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
            object_size = row.get("object_size")
            if (isinstance(object_size, int)
                    and not isinstance(object_size, bool)
                    and object_size >= 0):
                matched_bytes_by_address[address] = max(
                    matched_bytes_by_address.get(address, 0), object_size,
                )
    return {
        "rows": len(scoped_rows),
        "status_counts": dict(sorted(collections.Counter(
            row["status"] for row in scoped_rows
        ).items())),
        "known_addresses": known_addresses,
        "matched_addresses": matched_addresses,
        "matched_body_bytes": sum(matched_bytes_by_address.values()),
        "known_rows": known_rows,
        "unique_known_addresses": len(known_addresses),
        "duplicate_rows": duplicate_rows,
        "ignored_unknown_rows": ignored_unknown_rows,
    }


def matching_diagnostics(
    results: list[dict[str, Any]], windows: dict[int, int | None],
) -> tuple[set[int], int, int, int, int]:
    """Preserve the whole-image diagnostics API for callers and tests."""
    diagnostics = scope_diagnostics(results, windows)
    return (
        diagnostics["matched_addresses"],
        diagnostics["known_rows"],
        diagnostics["unique_known_addresses"],
        diagnostics["duplicate_rows"],
        diagnostics["ignored_unknown_rows"],
    )


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
    whole = scope_diagnostics(results, windows)
    try:
        policy = provenance.load_scope_policy()
        essential = scope_diagnostics(results, windows, "essential", policy)
        unclassified = scope_diagnostics(results, windows, "unclassified", policy)
    except provenance.ProvenanceError as exc:
        raise ProgressError(f"invalid function scope policy: {exc}") from exc
    if unclassified["rows"]:
        raise ProgressError(
            f"function scope policy leaves {unclassified['rows']} verifier rows unclassified"
        )
    if essential["ignored_unknown_rows"]:
        raise ProgressError(
            "essential verifier rows are missing from canonical function metadata"
        )
    whole_total = len(windows)
    essential_total = essential["unique_known_addresses"]

    def matching_summary(diagnostics: dict[str, Any], total: int) -> dict[str, Any]:
        addresses = [
            f"{address:08x}" for address in sorted(diagnostics["matched_addresses"])
        ]
        return {
            "count": len(addresses),
            "percent": percentage(len(addresses), total),
            "addresses": addresses,
            "matched_body_bytes": diagnostics["matched_body_bytes"],
            "known_rows": diagnostics["known_rows"],
            "unique_known_addresses": diagnostics["unique_known_addresses"],
            "duplicate_rows": diagnostics["duplicate_rows"],
        }

    whole_matching = matching_summary(whole, whole_total)
    essential_matching = matching_summary(essential, essential_total)
    essential_addresses = {
        address for address in essential["known_addresses"]
    }
    linked_numeric_addresses: set[int] = set()
    hashes: dict[str, str | None] = {"retail_sha1": None, "image_sha1": None}
    build_succeeded = False
    if linked_report is not None:
        linked_numeric_addresses = {
            canonical_linked_address(row["address"])
            for row in linked_report["linked_functions"]
        }
        for address in sorted(linked_numeric_addresses):
            if address not in whole["matched_addresses"]:
                raise ProgressError(
                    f"linked address {address:08x} is not in the matching address set"
                )
        hashes = {"retail_sha1": linked_report["retail_sha1"], "image_sha1": linked_report["image_sha1"]}
        build_succeeded = linked_report["build_succeeded"]

    whole_linked_addresses = [
        f"{address:08x}" for address in sorted(linked_numeric_addresses)
    ]
    essential_linked_addresses = [
        f"{address:08x}"
        for address in sorted(linked_numeric_addresses & essential_addresses)
    ]
    essential_remaining = essential_total - len(essential_matching["addresses"])
    essential_gate = {
        "name": "essential_functions",
        "label": "Essential Persona-specific functions",
        "complete": essential_total > 0 and essential_remaining == 0,
        "remaining": essential_remaining,
        "requires_every_function_to_match": True,
        "whole_executable_identity_is_separate": True,
    }

    metrics = {
        "schema_version": SCHEMA_VERSION,
        "scope": {
            "name": "essential",
            "label": "Essential Persona-specific functions",
            "policy": repo_relative(policy["source"]),
            "addresses": [f"{address:08x}" for address in sorted(essential_addresses)],
        },
        "source": {
            "verifier_report": verifier_source,
            "linked_report": linked_source,
            "function_scope_policy": repo_relative(policy["source"]),
            "raw_rows": len(results),
            "scope_rows": essential["rows"],
            "ignored_unknown_rows": whole["ignored_unknown_rows"],
            "scope_ignored_unknown_rows": essential["ignored_unknown_rows"],
        },
        "total": essential_total,
        "matching": essential_matching,
        "linked": {
            "count": len(essential_linked_addresses),
            "percent": percentage(len(essential_linked_addresses), essential_total),
            "addresses": essential_linked_addresses,
        },
        "status_counts": essential["status_counts"],
        "gate": essential_gate,
        "whole_executable": {
            "total": whole_total,
            "matching": whole_matching,
            "linked": {
                "count": len(whole_linked_addresses),
                "percent": percentage(len(whole_linked_addresses), whole_total),
                "addresses": whole_linked_addresses,
            },
            "status_counts": whole["status_counts"],
        },
        "hashes": hashes,
        "build_succeeded": build_succeeded,
    }
    return (
        metrics,
        badge("matching", len(essential_matching["addresses"]), essential_total),
        badge("linked", len(essential_linked_addresses), essential_total),
    )


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


def _validate_status_counts(value: Any, name: str) -> dict[str, int]:
    if not isinstance(value, dict):
        raise ProgressError(f"malformed metrics endpoint: {name} must be an object")
    if any(
        not isinstance(status, str)
        or not isinstance(count, int)
        or isinstance(count, bool)
        or count < 0
        for status, count in value.items()
    ):
        raise ProgressError(f"malformed metrics endpoint: invalid {name}")
    return value


def _validate_matching_summary(
    summary: Any,
    name: str,
    total: int,
    allowed_addresses: set[str],
    raw_rows: int,
    ignored_unknown_rows: int,
    windows: dict[int, int | None],
) -> set[str]:
    if not isinstance(summary, dict):
        raise ProgressError(f"malformed metrics endpoint: {name} must be an object")
    matched_body_bytes = summary.get("matched_body_bytes")
    if (
        not isinstance(matched_body_bytes, int)
        or isinstance(matched_body_bytes, bool)
        or matched_body_bytes < 0
    ):
        raise ProgressError(f"invalid metrics endpoint: {name}.matched_body_bytes")
    matching_count = summary.get("count")
    if (
        not isinstance(matching_count, int)
        or isinstance(matching_count, bool)
        or matching_count < 0
        or matching_count > total
    ):
        raise ProgressError(f"invalid metrics endpoint: {name}.count")
    if summary.get("percent") != percentage(matching_count, total):
        raise ProgressError(f"invalid metrics endpoint: {name}.percent")
    addresses = validate_address_list(summary.get("addresses"), f"{name}.matching", windows)
    if not addresses.issubset(allowed_addresses):
        raise ProgressError(f"invalid metrics endpoint: {name} addresses outside its scope")
    if matching_count != len(addresses):
        raise ProgressError(f"invalid metrics endpoint: {name} count does not agree with addresses")

    known_rows = summary.get("known_rows")
    unique_known_addresses = summary.get("unique_known_addresses")
    duplicate_rows = summary.get("duplicate_rows")
    diagnostic_counts = (known_rows, unique_known_addresses, duplicate_rows)
    if any(
        not isinstance(count, int) or isinstance(count, bool) or count < 0
        for count in diagnostic_counts
    ):
        raise ProgressError(f"invalid metrics endpoint: {name} row diagnostics")
    if known_rows + ignored_unknown_rows != raw_rows:
        raise ProgressError(f"invalid metrics endpoint: {name} row totals")
    if (
        unique_known_addresses > known_rows
        or duplicate_rows != known_rows - unique_known_addresses
        or unique_known_addresses > total
        or matching_count > unique_known_addresses
    ):
        raise ProgressError(f"invalid metrics endpoint: inconsistent {name} row diagnostics")
    return addresses


def _validate_linked_summary(
    summary: Any,
    name: str,
    total: int,
    allowed_addresses: set[str],
    matching_addresses: set[str],
    windows: dict[int, int | None],
) -> set[str]:
    if not isinstance(summary, dict):
        raise ProgressError(f"malformed metrics endpoint: {name} must be an object")
    count = summary.get("count")
    if not isinstance(count, int) or isinstance(count, bool) or count < 0 or count > total:
        raise ProgressError(f"invalid metrics endpoint: {name}.count")
    if summary.get("percent") != percentage(count, total):
        raise ProgressError(f"invalid metrics endpoint: {name}.percent")
    addresses = validate_address_list(summary.get("addresses"), name, windows)
    if not addresses.issubset(allowed_addresses):
        raise ProgressError(f"invalid metrics endpoint: {name} addresses outside its scope")
    if count != len(addresses):
        raise ProgressError(f"invalid metrics endpoint: {name} count does not agree with addresses")
    if not addresses.issubset(matching_addresses):
        raise ProgressError(f"invalid metrics endpoint: {name} addresses must be a subset of matching addresses")
    return addresses


def validate_endpoints(directory: Path, windows: dict[int, int | None]) -> None:
    metrics = load_json(directory / "metrics.json", "metrics endpoint")
    matching_badge = load_json(directory / "matching.json", "matching endpoint")
    linked_badge = load_json(directory / "linked.json", "linked endpoint")
    if not isinstance(metrics, dict):
        raise ProgressError("malformed metrics endpoint: top level must be an object")
    required = {
        "schema_version", "scope", "source", "total", "matching", "linked",
        "status_counts", "gate", "whole_executable", "hashes", "build_succeeded",
    }
    missing = sorted(required - metrics.keys())
    if missing:
        raise ProgressError(f"malformed metrics endpoint: missing {', '.join(missing)}")
    if metrics["schema_version"] != SCHEMA_VERSION:
        raise ProgressError("invalid metrics endpoint schema_version")

    scope = metrics["scope"]
    if (
        not isinstance(scope, dict)
        or scope.get("name") != "essential"
        or scope.get("label") != "Essential Persona-specific functions"
        or not isinstance(scope.get("policy"), str)
        or not scope["policy"]
    ):
        raise ProgressError("invalid metrics endpoint: essential scope")
    scope_addresses = validate_address_list(scope.get("addresses"), "scope", windows)
    if metrics["total"] != len(scope_addresses):
        raise ProgressError("invalid metrics endpoint total")
    essential_total = metrics["total"]
    whole = metrics["whole_executable"]
    if not isinstance(whole, dict) or whole.get("total") != len(windows):
        raise ProgressError("invalid metrics endpoint whole-executable total")
    whole_total = whole["total"]

    source = metrics["source"]
    if not isinstance(source, dict):
        raise ProgressError("malformed metrics endpoint: source must be an object")
    if (
        not isinstance(source.get("verifier_report"), str)
        or not source["verifier_report"]
        or not isinstance(source.get("linked_report"), str)
        or not source["linked_report"]
        or source.get("function_scope_policy") != scope["policy"]
    ):
        raise ProgressError("malformed metrics endpoint: invalid source report provenance")
    raw_rows = source.get("raw_rows")
    scope_rows = source.get("scope_rows")
    ignored_unknown_rows = source.get("ignored_unknown_rows")
    scope_ignored_unknown_rows = source.get("scope_ignored_unknown_rows")
    source_counts = (raw_rows, scope_rows, ignored_unknown_rows, scope_ignored_unknown_rows)
    if any(
        not isinstance(count, int) or isinstance(count, bool) or count < 0
        for count in source_counts
    ):
        raise ProgressError("invalid metrics endpoint: source row diagnostics")
    if scope_rows > raw_rows or ignored_unknown_rows > raw_rows or scope_ignored_unknown_rows > scope_rows:
        raise ProgressError("invalid metrics endpoint: inconsistent source row diagnostics")

    essential_status_counts = _validate_status_counts(metrics["status_counts"], "status_counts")
    whole_status_counts = _validate_status_counts(whole.get("status_counts"), "whole_executable.status_counts")
    if sum(essential_status_counts.values()) != scope_rows:
        raise ProgressError("invalid metrics endpoint: scope rows must equal status count total")
    if sum(whole_status_counts.values()) != raw_rows:
        raise ProgressError("invalid metrics endpoint: raw rows must equal whole status count total")
    hashes = metrics["hashes"]
    if (
        not isinstance(hashes, dict)
        or not isinstance(hashes.get("retail_sha1"), str)
        or not hashes["retail_sha1"]
        or not isinstance(hashes.get("image_sha1"), str)
        or not hashes["image_sha1"]
    ):
        raise ProgressError("malformed metrics endpoint: invalid build hashes")
    if metrics["build_succeeded"] is not True:
        raise ProgressError("invalid metrics endpoint: build_succeeded must be true")

    matching_addresses = _validate_matching_summary(
        metrics["matching"], "matching", essential_total, scope_addresses,
        scope_rows, scope_ignored_unknown_rows, windows,
    )
    gate = metrics["gate"]
    expected_remaining = essential_total - len(matching_addresses)
    if (
        not isinstance(gate, dict)
        or gate.get("name") != "essential_functions"
        or gate.get("label") != "Essential Persona-specific functions"
        or gate.get("remaining") != expected_remaining
        or gate.get("complete") != (essential_total > 0 and expected_remaining == 0)
        or gate.get("requires_every_function_to_match") is not True
        or gate.get("whole_executable_identity_is_separate") is not True
    ):
        raise ProgressError("invalid metrics endpoint: essential completion gate")
    whole_matching_addresses = _validate_matching_summary(
        whole.get("matching"), "whole_executable.matching", whole_total, set(
            f"{address:08x}" for address in windows
        ), raw_rows, ignored_unknown_rows, windows,
    )
    linked_addresses = _validate_linked_summary(
        metrics["linked"], "linked", essential_total, scope_addresses,
        matching_addresses, windows,
    )
    whole_linked_addresses = _validate_linked_summary(
        whole.get("linked"), "whole_executable.linked", whole_total, set(
            f"{address:08x}" for address in windows
        ), whole_matching_addresses, windows,
    )
    if not linked_addresses.issubset(whole_linked_addresses):
        raise ProgressError("invalid metrics endpoint: essential linked addresses exceed whole linked addresses")
    validate_badge(matching_badge, "matching", len(matching_addresses), essential_total)
    validate_badge(linked_badge, "linked", len(linked_addresses), essential_total)


def print_human(report: dict[str, Any], windows: dict[int, int | None], metrics: dict[str, Any]) -> None:
    results = report_results(report, windows)
    per_dir: dict[str, list[int]] = collections.defaultdict(lambda: [0, 0])
    essential_addresses = set(metrics["scope"]["addresses"])
    for row in results:
        if f"{canonical_address(row['addr']):08x}" not in essential_addresses:
            continue
        pieces = Path(row["file"].replace("\\", "/")).parts
        top = pieces[1] if len(pieces) > 1 else "."
        per_dir[top][1] += 1
        if row["status"] == "MATCH":
            per_dir[top][0] += 1

    matching = metrics["matching"]
    whole = metrics["whole_executable"]
    print("Persona 3 FES decompilation progress")
    print("=" * 40)
    print(f"essential functions       : {metrics['total']}")
    print(f"functions in executable   : {whole['total']}")
    print(f"essential functions with C: {metrics['source']['scope_rows']} scanned")
    print(f"all functions with C      : {metrics['source']['raw_rows']} scanned")
    print(f"  essential MATCH         : {matching['count']}  ({matching['percent']}% of essential)")
    gate = metrics["gate"]
    print(
        f"  essential gate          : "
        f"{'PASS' if gate['complete'] else 'INCOMPLETE'} "
        f"({gate['remaining']} remaining)"
    )
    print(
        f"  whole-image MATCH       : {whole['matching']['count']}  "
        f"({whole['matching']['percent']}% of all)"
    )
    for status, count in metrics["status_counts"].items():
        if status != "MATCH":
            print(f"  essential {status:13}: {count}")
    print(f"matched essential bytes   : {matching['matched_body_bytes']:,}")
    print(f"matched all-image bytes   : {whole['matching']['matched_body_bytes']:,}")
    print()
    print("essential by directory (matched / written):")
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
            linked_report = validate_linked_report(
                load_json(args.linked_report, "linked report"), windows,
            )
            linked_source = str(args.linked_report)
        if args.write_dir is not None and linked_report is None:
            raise ProgressError("--write-dir requires a successful --linked-report")

        metrics, matching_badge, linked_badge = make_metrics(
            report, windows, linked_report, verifier_source, linked_source,
        )
        if args.write_dir is not None:
            write_endpoints(args.write_dir, metrics, matching_badge, linked_badge)
        if args.json:
            source = metrics["source"]
            whole = metrics["whole_executable"]
            json.dump({
                "functions_total": metrics["total"],
                "functions_total_whole_executable": whole["total"],
                "functions_scanned": source["scope_rows"],
                "functions_scanned_whole_executable": source["raw_rows"],
                "functions_matched": metrics["matching"]["count"],
                "essential_gate_complete": metrics["gate"]["complete"],
                "essential_functions_remaining": metrics["gate"]["remaining"],
                "functions_matched_whole_executable": whole["matching"]["count"],
                "functions_nonmatching": metrics["status_counts"].get("NONMATCHING", 0),
                "functions_nonmatching_whole_executable": whole["status_counts"].get("NONMATCHING", 0),
                "matched_code_bytes": metrics["matching"]["matched_body_bytes"],
                "matched_code_bytes_whole_executable": whole["matching"]["matched_body_bytes"],
                "matched_pct_of_known": metrics["matching"]["percent"],
                "matched_pct_of_whole_executable": whole["matching"]["percent"],
                "matched_pct_of_scanned": round(
                    100 * metrics["matching"]["count"] / source["scope_rows"], 2,
                ) if source["scope_rows"] else 0,
            }, sys.stdout, indent=2)
            sys.stdout.write("\n")
        else:
            print_human(report, windows, metrics)
    except ProgressError as exc:
        print(f"progress: error: {exc}", file=sys.stderr)
        raise SystemExit(2) from exc


if __name__ == "__main__":
    main()
