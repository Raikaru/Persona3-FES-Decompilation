#!/usr/bin/env python3
"""Classify verifier functions by ownership provenance and completion scope.

The verifier is authoritative for function boundaries and MATCH status.
Ownership comes only from checked-in source paths; completion scope comes from
the explicit policy and exact function overrides in config/function_scope.json.
Neither classifier uses symbol names or SDK similarity as proof of ownership.

Usage:
  python tools/provenance.py
  python tools/provenance.py --report build/FULL_PROGRESS_363.json \
      --json build/provenance_report.json
  python tools/provenance.py --report REPORT --show-files
"""
from __future__ import annotations

import argparse
import collections
import json
import sys
from pathlib import Path
from typing import Any

REPO = Path(__file__).resolve().parents[1]
SCHEMA_VERSION = 1
MATCH_STATUS = "MATCH"
CATEGORY_ORDER = (
    "atlus_game",
    "cri",
    "renderware",
    "sce",
    "c_runtime",
    "startup_platform",
    "unclassified",
)
CATEGORY_LABELS = {
    "atlus_game": "Atlus game code",
    "cri": "CRI middleware",
    "renderware": "RenderWare",
    "sce": "SCE libraries",
    "c_runtime": "C runtime/math",
    "startup_platform": "Startup/platform",
    "unclassified": "Unclassified",
}

SCOPE_POLICY_PATH = REPO / "config" / "function_scope.json"
SCOPE_ORDER = ("essential", "replaceable", "unclassified")
SCOPE_LABELS = {
    "essential": "Essential Persona-specific functions",
    "replaceable": "Replaceable generic machinery",
    "unclassified": "Unclassified",
}

# Rules are intentionally path based.  Game-facing wrappers (for example
# h_cdvd.c and h_sfdply.c) remain game code; only the implementation TUs in
# the vendor/platform regions are excluded.
PATH_RULES = (
    ("cri", "src/cri/", "src/cri/**"),
    ("renderware", "src/rw/", "src/rw/**"),
    ("sce", "src/sce/", "src/sce/**"),
    ("sce", "src/libcdvd.c", "src/libcdvd.c"),
    ("c_runtime", "src/libc_core.c", "src/libc_core.c"),
    ("c_runtime", "src/libm.c", "src/libm.c"),
    ("startup_platform", "src/crt0.c", "src/crt0.c"),
    ("startup_platform", "src/code2.c", "src/code2.c"),
)


class ProvenanceError(ValueError):
    """Raised when a verifier report cannot support exact classification."""


def normalize_source_path(value: str) -> str:
    """Normalize verifier's Windows/ POSIX source path to lowercase slashes."""
    return value.replace("\\", "/").lower()


def classify_source(source_file: str) -> tuple[str, str]:
    """Return (category, rule) for a verifier source path.

    Every current verifier row comes from src/.  The final src/ rule is an
    explicit project-layout policy: source outside named vendor/runtime TUs is
    Atlus-owned game code.  Paths outside src/ are retained as unclassified so
    a future build cannot silently inflate game coverage.
    """
    normalized = normalize_source_path(source_file)
    for category, pattern, rule in PATH_RULES:
        if pattern.endswith("/"):
            if normalized.startswith(pattern):
                return category, rule
        elif normalized == pattern:
            return category, rule
    if normalized.startswith("src/"):
        return "atlus_game", "src/** (default game-owned region)"
    return "unclassified", "outside src/**"


def load_json(path: Path, description: str) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ProvenanceError(f"{description} is missing: {path}") from exc
    except OSError as exc:
        raise ProvenanceError(f"cannot read {description}: {path}: {exc}") from exc
    except json.JSONDecodeError as exc:
        raise ProvenanceError(f"malformed {description}: {path}: {exc}") from exc


def resolve_report_path(path: Path | None, repo: Path = REPO) -> Path:
    """Resolve an explicit report or the report named by progress/metrics.json."""
    if path is not None:
        return path if path.is_absolute() else repo / path

    metrics_path = repo / "progress" / "metrics.json"
    if metrics_path.is_file():
        metrics = load_json(metrics_path, "progress metrics")
        source = metrics.get("source", {}).get("verifier_report") if isinstance(metrics, dict) else None
        if isinstance(source, str) and source:
            # Published metrics use Windows separators even when inspected from
            # a POSIX environment; normalizing here keeps the CLI portable.
            candidate = Path(source.replace("\\", "/"))
            if not candidate.is_absolute():
                candidate = repo / candidate
            if candidate.is_file():
                return candidate
    return repo / "build" / "verify_report.json"


def canonical_address(value: Any) -> int:
    if isinstance(value, int) and not isinstance(value, bool):
        return value
    if isinstance(value, str) and value:
        try:
            return int(value, 16)
        except ValueError as exc:
            raise ProvenanceError(f"malformed verifier report address: {value!r}") from exc
    raise ProvenanceError("malformed verifier report: every row needs an address")

def load_scope_policy(path: Path = SCOPE_POLICY_PATH) -> dict[str, Any]:
    """Load and validate the explicit essential/replaceable function policy."""
    payload = load_json(path, "function scope policy")
    if not isinstance(payload, dict) or payload.get("schema_version") != 1:
        raise ProvenanceError("malformed function scope policy: unsupported schema_version")

    defaults = payload.get("default_scope_by_provenance")
    if not isinstance(defaults, dict) or set(defaults) != set(CATEGORY_ORDER):
        raise ProvenanceError(
            "malformed function scope policy: default_scope_by_provenance "
            "must cover every provenance category"
        )
    if any(scope not in SCOPE_ORDER for scope in defaults.values()):
        raise ProvenanceError("malformed function scope policy: invalid default scope")
    if defaults["unclassified"] != "unclassified":
        raise ProvenanceError(
            "malformed function scope policy: unclassified provenance must remain unclassified"
        )

    raw_overrides = payload.get("function_overrides")
    if not isinstance(raw_overrides, list):
        raise ProvenanceError("malformed function scope policy: function_overrides must be a list")
    overrides: dict[tuple[str, int], dict[str, Any]] = {}
    for raw in raw_overrides:
        if not isinstance(raw, dict):
            raise ProvenanceError("malformed function scope policy: every override must be an object")
        source_file = raw.get("file")
        name = raw.get("name")
        scope = raw.get("scope")
        reason = raw.get("reason")
        if not isinstance(source_file, str) or not source_file:
            raise ProvenanceError("malformed function scope policy: override file is required")
        if not isinstance(name, str) or not name:
            raise ProvenanceError("malformed function scope policy: override name is required")
        if scope not in ("essential", "replaceable"):
            raise ProvenanceError(
                "malformed function scope policy: override scope must be essential or replaceable"
            )
        if not isinstance(reason, str) or not reason.strip():
            raise ProvenanceError("malformed function scope policy: override reason is required")
        address = canonical_address(raw.get("addr"))
        normalized_file = normalize_source_path(source_file)
        key = (normalized_file, address)
        if key in overrides:
            raise ProvenanceError(
                f"duplicate function scope override: {normalized_file} @ 0x{address:08x}"
            )
        overrides[key] = {
            "file": normalized_file,
            "addr": f"{address:08x}",
            "name": name,
            "scope": scope,
            "reason": reason.strip(),
        }
    return {
        "schema_version": 1,
        "source": str(path),
        "default_scope_by_provenance": defaults,
        "overrides": overrides,
    }


def classify_function_scope(
    source_file: str, name: Any, address: Any, policy: dict[str, Any],
) -> tuple[str, str]:
    """Return the completion-gate scope and the exact policy rule used."""
    category, _provenance_rule = classify_source(source_file)
    normalized_file = normalize_source_path(source_file)
    numeric_address = canonical_address(address)
    override = policy["overrides"].get((normalized_file, numeric_address))
    if override is not None:
        if name != override["name"]:
            raise ProvenanceError(
                "stale function scope override: "
                f"{normalized_file} @ 0x{numeric_address:08x} names "
                f"{override['name']!r}, verifier reports {name!r}"
            )
        return override["scope"], f"explicit override: {override['reason']}"
    scope = policy["default_scope_by_provenance"][category]
    return scope, f"default for provenance {category}"


def optional_nonnegative_int(row: dict[str, Any], field: str) -> int | None:
    value = row.get(field)
    if value is None:
        return None
    if isinstance(value, bool) or not isinstance(value, int) or value < 0:
        raise ProvenanceError(f"malformed verifier report: {field} must be a non-negative integer")
    return value


def percentage(count: int, total: int) -> float:
    return round(100 * count / total, 3) if total else 0.0


def _category_empty(category: str, rule: str) -> dict[str, Any]:
    return {
        "label": CATEGORY_LABELS[category],
        "rule": rule,
        "function_count": 0,
        "matched_function_count": 0,
        "match_percent": 0.0,
        "object_bytes": 0,
        "matched_object_bytes": 0,
        "matched_object_byte_percent": 0.0,
        "retail_window_bytes": 0,
        "matched_retail_window_bytes": 0,
        "matched_retail_window_byte_percent": 0.0,
        "source_file_count": 0,
        "source_files": [],
        "status_counts": {},
    }

def _scope_empty(scope: str, rule: str) -> dict[str, Any]:
    summary = _category_empty("unclassified", rule)
    summary["label"] = SCOPE_LABELS[scope]
    return summary


def classify_report(
    report: dict[str, Any],
    report_path: Path | str = "<memory>",
    policy: dict[str, Any] | None = None,
) -> dict[str, Any]:
    """Validate and classify a verifier report into a machine-readable result."""
    if not isinstance(report, dict) or not isinstance(report.get("results"), list):
        raise ProvenanceError("malformed verifier report: 'results' must be a list")

    if policy is None:
        policy = load_scope_policy()

    rows = report["results"]
    seen_addresses: set[int] = set()
    category_rows: dict[str, list[dict[str, Any]]] = collections.defaultdict(list)
    scope_rows: dict[str, list[dict[str, Any]]] = collections.defaultdict(list)
    file_rows: dict[str, list[dict[str, Any]]] = collections.defaultdict(list)
    normalized_rows: list[dict[str, Any]] = []
    used_override_keys: set[tuple[str, int]] = set()
    missing_object_size = 0
    missing_window = 0

    for row in rows:
        if not isinstance(row, dict):
            raise ProvenanceError("malformed verifier report: every result must be an object")
        address = canonical_address(row.get("addr"))
        if address in seen_addresses:
            raise ProvenanceError(f"duplicate verifier function address: 0x{address:08x}")
        seen_addresses.add(address)
        source_file = row.get("file")
        status = row.get("status")
        if not isinstance(source_file, str) or not source_file:
            raise ProvenanceError("malformed verifier report: every row needs a source file")
        if not isinstance(status, str) or not status:
            raise ProvenanceError("malformed verifier report: every row needs a status")

        object_size = optional_nonnegative_int(row, "object_size")
        window = optional_nonnegative_int(row, "window")
        missing_object_size += object_size is None
        missing_window += window is None
        category, rule = classify_source(source_file)
        name = row.get("name")
        scope, scope_rule = classify_function_scope(source_file, name, address, policy)
        override_key = (normalize_source_path(source_file), address)
        if override_key in policy["overrides"]:
            used_override_keys.add(override_key)
        normalized = {
            "addr": f"{address:08x}",
            "file": source_file.replace("\\", "/"),
            "name": name,
            "status": status,
            "category": category,
            "rule": rule,
            "scope": scope,
            "scope_rule": scope_rule,
            "object_size": object_size,
            "window": window,
        }
        normalized_rows.append(normalized)
        category_rows[category].append(normalized)
        scope_rows[scope].append(normalized)
        file_rows[normalized["file"]].append(normalized)

    categories: dict[str, dict[str, Any]] = {}
    for category in CATEGORY_ORDER:
        rows_for_category = category_rows.get(category, [])
        if rows_for_category:
            rules = sorted({row["rule"] for row in rows_for_category})
            rule = rules[0] if len(rules) == 1 else "; ".join(rules)
            summary = _category_empty(category, rule)
            summary["function_count"] = len(rows_for_category)
            summary["matched_function_count"] = sum(row["status"] == MATCH_STATUS for row in rows_for_category)
            summary["match_percent"] = percentage(
                summary["matched_function_count"], summary["function_count"]
            )
            object_rows = [row for row in rows_for_category if row["object_size"] is not None]
            window_rows = [row for row in rows_for_category if row["window"] is not None]
            summary["object_bytes"] = sum(row["object_size"] for row in object_rows)
            summary["matched_object_bytes"] = sum(
                row["object_size"] for row in object_rows if row["status"] == MATCH_STATUS
            )
            summary["matched_object_byte_percent"] = percentage(
                summary["matched_object_bytes"], summary["object_bytes"]
            )
            summary["retail_window_bytes"] = sum(row["window"] for row in window_rows)
            summary["matched_retail_window_bytes"] = sum(
                row["window"] for row in window_rows if row["status"] == MATCH_STATUS
            )
            summary["matched_retail_window_byte_percent"] = percentage(
                summary["matched_retail_window_bytes"], summary["retail_window_bytes"]
            )
            summary["source_file_count"] = len({row["file"] for row in rows_for_category})
            summary["source_files"] = sorted({row["file"] for row in rows_for_category})
            summary["status_counts"] = dict(sorted(collections.Counter(
                row["status"] for row in rows_for_category
            ).items()))
            categories[category] = summary
        else:
            rule = next((rule for cat, _pattern, rule in PATH_RULES if cat == category), "")
            categories[category] = _category_empty(category, rule)

    scopes: dict[str, dict[str, Any]] = {}
    for scope in SCOPE_ORDER:
        rows_for_scope = scope_rows.get(scope, [])
        rules = sorted({row["scope_rule"] for row in rows_for_scope})
        rule = rules[0] if len(rules) == 1 else "; ".join(rules)
        summary_for_scope = _scope_empty(scope, rule)
        summary_for_scope["function_count"] = len(rows_for_scope)
        summary_for_scope["matched_function_count"] = sum(
            row["status"] == MATCH_STATUS for row in rows_for_scope
        )
        summary_for_scope["match_percent"] = percentage(
            summary_for_scope["matched_function_count"],
            summary_for_scope["function_count"],
        )
        object_rows = [row for row in rows_for_scope if row["object_size"] is not None]
        window_rows = [row for row in rows_for_scope if row["window"] is not None]
        summary_for_scope["object_bytes"] = sum(row["object_size"] for row in object_rows)
        summary_for_scope["matched_object_bytes"] = sum(
            row["object_size"] for row in object_rows if row["status"] == MATCH_STATUS
        )
        summary_for_scope["matched_object_byte_percent"] = percentage(
            summary_for_scope["matched_object_bytes"], summary_for_scope["object_bytes"]
        )
        summary_for_scope["retail_window_bytes"] = sum(row["window"] for row in window_rows)
        summary_for_scope["matched_retail_window_bytes"] = sum(
            row["window"] for row in window_rows if row["status"] == MATCH_STATUS
        )
        summary_for_scope["matched_retail_window_byte_percent"] = percentage(
            summary_for_scope["matched_retail_window_bytes"],
            summary_for_scope["retail_window_bytes"],
        )
        summary_for_scope["source_file_count"] = len({row["file"] for row in rows_for_scope})
        summary_for_scope["source_files"] = sorted({row["file"] for row in rows_for_scope})
        summary_for_scope["status_counts"] = dict(sorted(collections.Counter(
            row["status"] for row in rows_for_scope
        ).items()))
        scopes[scope] = summary_for_scope

    files = []
    for source_file in sorted(file_rows):
        rows_for_file = file_rows[source_file]
        categories_for_file = sorted({row["category"] for row in rows_for_file})
        rules_for_file = sorted({row["rule"] for row in rows_for_file})
        scopes_for_file = sorted({row["scope"] for row in rows_for_file})
        scope_rules_for_file = sorted({row["scope_rule"] for row in rows_for_file})
        object_rows = [row for row in rows_for_file if row["object_size"] is not None]
        window_rows = [row for row in rows_for_file if row["window"] is not None]
        files.append({
            "file": source_file,
            "category": categories_for_file[0] if len(categories_for_file) == 1 else "mixed",
            "rule": rules_for_file[0] if len(rules_for_file) == 1 else "; ".join(rules_for_file),
            "scope": scopes_for_file[0] if len(scopes_for_file) == 1 else "mixed",
            "scope_rule": (
                scope_rules_for_file[0]
                if len(scope_rules_for_file) == 1
                else "; ".join(scope_rules_for_file)
            ),
            "function_count": len(rows_for_file),
            "matched_function_count": sum(row["status"] == MATCH_STATUS for row in rows_for_file),
            "object_bytes": sum(row["object_size"] for row in object_rows),
            "matched_object_bytes": sum(
                row["object_size"] for row in object_rows if row["status"] == MATCH_STATUS
            ),
            "retail_window_bytes": sum(row["window"] for row in window_rows),
            "matched_retail_window_bytes": sum(
                row["window"] for row in window_rows if row["status"] == MATCH_STATUS
            ),
            "status_counts": dict(sorted(collections.Counter(
                row["status"] for row in rows_for_file
            ).items())),
        })

    unused_override_keys = set(policy["overrides"]) - used_override_keys
    if unused_override_keys:
        source_file, address = sorted(unused_override_keys)[0]
        raise ProvenanceError(
            f"stale function scope override has no verifier row: "
            f"{source_file} @ 0x{address:08x}"
        )

    unclassified_rows = [row for row in normalized_rows if row["scope"] == "unclassified"]
    category_function_sum = sum(category["function_count"] for category in categories.values())
    scope_function_sum = sum(scope["function_count"] for scope in scopes.values())
    essential = scopes["essential"]
    essential_remaining = (
        essential["function_count"] - essential["matched_function_count"]
    )
    coverage_gate = {
        "name": "essential_functions",
        "label": SCOPE_LABELS["essential"],
        "complete": (
            essential["function_count"] > 0
            and essential_remaining == 0
            and not unclassified_rows
        ),
        "function_count": essential["function_count"],
        "matched_function_count": essential["matched_function_count"],
        "remaining_function_count": essential_remaining,
        "status_counts": essential["status_counts"],
        "requires_every_function_to_match": True,
        "whole_executable_identity_is_separate": True,
    }
    summary = report.get("summary", {})
    status_counts = dict(sorted(collections.Counter(row["status"] for row in normalized_rows).items()))
    return {
        "schema_version": SCHEMA_VERSION,
        "classification_basis": (
            "checked-in verifier source paths plus config/function_scope.json "
            "function overrides; verify.py MATCH is authoritative"
        ),
        "source": {
            "verifier_report": str(report_path),
            "verifier_summary": summary if isinstance(summary, dict) else {},
            "function_scope_policy": policy["source"],
        },
        "function_total": len(normalized_rows),
        "matched_function_total": sum(row["status"] == MATCH_STATUS for row in normalized_rows),
        "status_counts": status_counts,
        "categories": categories,
        "scopes": scopes,
        "coverage_gate": coverage_gate,
        "files": files,
        "validation": {
            "distinct_addresses": len(seen_addresses),
            "duplicate_addresses": len(normalized_rows) - len(seen_addresses),
            "category_function_sum": category_function_sum,
            "category_sum_matches_total": category_function_sum == len(normalized_rows),
            "scope_function_sum": scope_function_sum,
            "scope_sum_matches_total": scope_function_sum == len(normalized_rows),
            "scope_override_count": len(policy["overrides"]),
            "used_scope_override_count": len(used_override_keys),
            "unclassified_function_count": len(unclassified_rows),
            "unclassified_files": sorted({row["file"] for row in unclassified_rows}),
            "unclassified_functions": unclassified_rows,
            "missing_object_size_rows": missing_object_size,
            "missing_window_rows": missing_window,
        },
    }


def print_report(report: dict[str, Any], show_files: bool = False) -> None:
    print(f"verifier report: {report['source']['verifier_report']}")
    print(f"functions: {report['matched_function_total']}/{report['function_total']} MATCH")
    print()
    print("completion scope       matched/functions   match %   matched object bytes / object bytes")
    for scope in SCOPE_ORDER:
        scope_summary = report["scopes"][scope]
        print(
            f"{scope:<21} "
            f"{scope_summary['matched_function_count']:>7}/{scope_summary['function_count']:<10} "
            f"{scope_summary['match_percent']:>7.3f}%   "
            f"{scope_summary['matched_object_bytes']:>10}/{scope_summary['object_bytes']:<10}"
        )
    gate = report["coverage_gate"]
    print(
        f"essential gate: {'PASS' if gate['complete'] else 'INCOMPLETE'}; "
        f"{gate['remaining_function_count']} functions remain"
    )

    print()
    print("category              matched/functions   match %   matched object bytes / object bytes")
    for category in CATEGORY_ORDER:
        summary = report["categories"][category]
        print(
            f"{category:<21} "
            f"{summary['matched_function_count']:>7}/{summary['function_count']:<10} "
            f"{summary['match_percent']:>7.3f}%   "
            f"{summary['matched_object_bytes']:>10}/{summary['object_bytes']:<10}"
        )
    validation = report["validation"]
    print()
    print(
        "validation: "
        f"{validation['distinct_addresses']} distinct addresses; "
        f"{validation['unclassified_function_count']} unclassified functions; "
        f"category sum exact={validation['category_sum_matches_total']}; "
        f"scope sum exact={validation['scope_sum_matches_total']}"
    )
    if show_files:
        print()
        print("source file breakdown:")
        for row in report["files"]:
            print(
                f"{row['scope']:<12} {row['category']:<18} "
                f"{row['matched_function_count']:>4}/{row['function_count']:<4} {row['file']}"
            )


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", type=Path, help="verifier JSON report (default: progress metrics source)")
    parser.add_argument("--json", type=Path, help="write the classification JSON report")
    parser.add_argument("--show-files", action="store_true", help="print one line per source file")
    args = parser.parse_args(argv)

    report_path = resolve_report_path(args.report)
    source_report = load_json(report_path, "verifier report")
    classified = classify_report(source_report, report_path)
    print_report(classified, show_files=args.show_files)
    if args.json:
        output = args.json if args.json.is_absolute() else REPO / args.json
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(classified, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        print(f"classification report: {output}")
    validation = classified["validation"]
    if (
        not validation["category_sum_matches_total"]
        or not validation["scope_sum_matches_total"]
        or validation["unclassified_function_count"] != 0
    ):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
