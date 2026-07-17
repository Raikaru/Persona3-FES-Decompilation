#!/usr/bin/env python3

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import progress


class EssentialScopeTests(unittest.TestCase):
    def setUp(self):
        self.windows = {
            0x00100000: 8,
            0x00100010: 12,
            0x00100020: 16,
            0x00100030: 20,
        }
        self.report = {
            "summary": {"MATCH": 2, "NONMATCHING": 2},
            "results": [
                {
                    "file": "src/Main/main.c",
                    "addr": "00100000",
                    "name": "game_entry",
                    "status": "MATCH",
                    "object_size": 8,
                    "window": 8,
                },
                {
                    "file": "src/rw/rwcore.c",
                    "addr": "00100010",
                    "name": "rw_entry",
                    "status": "MATCH",
                    "object_size": 12,
                    "window": 12,
                },
                {
                    "file": "src/sce/libmc2.c",
                    "addr": "00100020",
                    "name": "sce_entry",
                    "status": "NONMATCHING",
                    "object_size": 16,
                    "window": 16,
                },
                {
                    "file": "src/Battle/battle.c",
                    "addr": "00100030",
                    "name": "battle_entry",
                    "status": "NONMATCHING",
                    "object_size": 20,
                    "window": 20,
                },
            ],
        }

    def test_primary_scope_excludes_vendor_functions(self):
        metrics, matching_badge, linked_badge = progress.make_metrics(
            self.report, self.windows, None, "report.json", "linked.json",
        )

        self.assertEqual(metrics["total"], 2)
        self.assertEqual(metrics["matching"]["count"], 1)
        self.assertEqual(metrics["scope"]["name"], "essential")
        self.assertEqual(metrics["scope"]["label"], "Essential Persona-specific functions")
        self.assertFalse(metrics["gate"]["complete"])
        self.assertEqual(metrics["gate"]["remaining"], 1)
        self.assertEqual(metrics["matching"]["percent"], 50.0)
        self.assertEqual(metrics["matching"]["matched_body_bytes"], 8)
        self.assertEqual(metrics["whole_executable"]["total"], 4)
        self.assertEqual(metrics["whole_executable"]["matching"]["count"], 2)
        self.assertEqual(metrics["whole_executable"]["matching"]["matched_body_bytes"], 20)
        self.assertEqual(metrics["status_counts"], {"MATCH": 1, "NONMATCHING": 1})
        self.assertEqual(metrics["whole_executable"]["status_counts"], {
            "MATCH": 2,
            "NONMATCHING": 2,
        })
        self.assertEqual(matching_badge["message"], "1/2 (50.000%)")
        self.assertEqual(linked_badge["message"], "0/2 (0.000%)")

    def test_function_override_controls_gate_scope(self):
        policy = progress.provenance.load_scope_policy()
        policy["overrides"] = {
            ("src/rw/rwcore.c", 0x00100010): {
                "file": "src/rw/rwcore.c",
                "addr": "00100010",
                "name": "rw_entry",
                "scope": "essential",
                "reason": "Persona-specific middleware glue",
            },
        }
        results = progress.report_results(self.report, self.windows)
        diagnostics = progress.scope_diagnostics(
            results, self.windows, "essential", policy,
        )
        self.assertEqual(diagnostics["unique_known_addresses"], 3)
        self.assertEqual(diagnostics["matched_addresses"], {0x00100000, 0x00100010})

    def test_generated_endpoints_validate_with_whole_image_backup(self):
        linked_report = {
            "schema_version": 1,
            "build_succeeded": True,
            "image_sha1": "image",
            "retail_sha1": "retail",
            "function_total": 4,
            "linked_tu_count": 1,
            "linked_function_count": 1,
            "linked_functions": [{
                "address": "00100000",
                "name": "game_entry",
                "file": "src/Main/main.c",
            }],
        }
        linked_report = progress.validate_linked_report(linked_report, self.windows)
        metrics, matching_badge, linked_badge = progress.make_metrics(
            self.report, self.windows, linked_report, "report.json", "linked.json",
        )
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory)
            progress.write_endpoints(output, metrics, matching_badge, linked_badge)
            progress.validate_endpoints(output, self.windows)

        self.assertEqual(metrics["linked"]["count"], 1)
        self.assertEqual(metrics["whole_executable"]["linked"]["count"], 1)


if __name__ == "__main__":
    unittest.main()
