#!/usr/bin/env python3

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import provenance


class ClassificationRuleTests(unittest.TestCase):
    def test_vendor_and_runtime_paths_are_excluded(self):
        self.assertEqual(provenance.classify_source(r"src\cri\cri_adx.c")[0], "cri")
        self.assertEqual(provenance.classify_source("src/rw/rwcore.c")[0], "renderware")
        self.assertEqual(provenance.classify_source("src/sce/libmc2.c")[0], "sce")
        self.assertEqual(provenance.classify_source("src/libcdvd.c")[0], "sce")
        self.assertEqual(provenance.classify_source("src/libc_core.c")[0], "c_runtime")
        self.assertEqual(provenance.classify_source("src/libm.c")[0], "c_runtime")
        self.assertEqual(provenance.classify_source("src/crt0.c")[0], "startup_platform")
        self.assertEqual(provenance.classify_source("src/code2.c")[0], "startup_platform")

    def test_wrappers_and_game_subsystems_remain_game_code(self):
        self.assertEqual(provenance.classify_source("src/h_cdvd.c")[0], "atlus_game")
        self.assertEqual(provenance.classify_source("src/Graphics/primitive.c")[0], "atlus_game")
        self.assertEqual(provenance.classify_source("src/Main/main.c")[0], "atlus_game")

    def test_outside_source_tree_is_not_silently_game_code(self):
        self.assertEqual(provenance.classify_source("asm/code1.s")[0], "unclassified")

    def test_completion_scope_uses_policy_not_ownership_label(self):
        policy = provenance.load_scope_policy()
        self.assertEqual(
            provenance.classify_function_scope(
                "src/Main/main.c", "game_entry", "00100000", policy,
            )[0],
            "essential",
        )
        self.assertEqual(
            provenance.classify_function_scope(
                "src/rw/rwcore.c", "rw_entry", "00100010", policy,
            )[0],
            "replaceable",
        )

    def test_explicit_override_can_promote_middleware_glue(self):
        policy = provenance.load_scope_policy()
        policy["overrides"] = {
            ("src/rw/rwcore.c", 0x00100010): {
                "file": "src/rw/rwcore.c",
                "addr": "00100010",
                "name": "atlus_rw_bridge",
                "scope": "essential",
                "reason": "Persona-specific RenderWare bridge",
            },
        }
        scope, rule = provenance.classify_function_scope(
            "src/rw/rwcore.c", "atlus_rw_bridge", "00100010", policy,
        )
        self.assertEqual(scope, "essential")
        self.assertIn("Persona-specific", rule)


class ReportTests(unittest.TestCase):
    def test_report_aggregates_categories_and_bytes(self):
        source_report = {
            "summary": {"MATCH": 2, "NONMATCHING": 1},
            "results": [
                {
                    "file": "src/Main/main.c",
                    "addr": "00100000",
                    "name": "game_entry",
                    "status": "MATCH",
                    "object_size": 12,
                    "window": 16,
                },
                {
                    "file": "src\\cri\\cri_adx.c",
                    "addr": "00100010",
                    "name": "cri_entry",
                    "status": "NONMATCHING",
                    "object_size": 20,
                    "window": 24,
                },
                {
                    "file": "src/libm.c",
                    "addr": "00100028",
                    "name": "sinf",
                    "status": "MATCH",
                    "object_size": 8,
                    "window": 8,
                },
            ],
        }
        report = provenance.classify_report(source_report, "synthetic.json")

        self.assertEqual(report["function_total"], 3)
        self.assertEqual(report["matched_function_total"], 2)
        self.assertEqual(report["categories"]["atlus_game"]["matched_function_count"], 1)
        self.assertEqual(report["categories"]["atlus_game"]["object_bytes"], 12)
        self.assertEqual(report["categories"]["cri"]["function_count"], 1)
        self.assertEqual(report["categories"]["c_runtime"]["matched_object_bytes"], 8)
        self.assertTrue(report["validation"]["category_sum_matches_total"])
        self.assertEqual(report["validation"]["unclassified_function_count"], 0)
        self.assertEqual(report["scopes"]["essential"]["function_count"], 1)
        self.assertEqual(report["scopes"]["replaceable"]["function_count"], 2)
        self.assertTrue(report["coverage_gate"]["complete"])
        self.assertEqual(report["coverage_gate"]["remaining_function_count"], 0)

    def test_duplicate_addresses_are_rejected(self):
        source_report = {
            "results": [
                {"file": "src/Main/main.c", "addr": "00100000", "status": "MATCH"},
                {"file": "src/Battle/battle.c", "addr": "00100000", "status": "MATCH"},
            ]
        }
        with self.assertRaises(provenance.ProvenanceError):
            provenance.classify_report(source_report)


if __name__ == "__main__":
    unittest.main()
