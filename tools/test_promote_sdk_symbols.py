#!/usr/bin/env python3

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import promote_sdk_symbols


class PromotionTests(unittest.TestCase):
    def _target(self):
        root = Path(tempfile.mkdtemp())
        (root / "config").mkdir()
        (root / "src").mkdir()
        (root / "include").mkdir()
        (root / "config" / "symbol_addrs.txt").write_text(
            "// symbols\n"
            "func_00100000 = 0x00100000; // type:func\n"
            "func_00100010 = 0x00100010; // type:func\n"
            "func_00100020 = 0x00100020; // type:func\n")
        (root / "src" / "caller.c").write_text(
            "extern int func_00100000(void);\n"
            "int call(void) { return func_00100000(); }\n")
        return root

    @staticmethod
    def _item(name, address, archive="libkernl.a", member="kernel.o"):
        return {
            "status": "UNIQUE_NORMALIZED",
            "name": name,
            "archive": archive,
            "member": member,
            "size": 16,
            "canonical_sha256": "abc",
            "candidates": [{"address": f"0x{address:08X}", "known_names": [f"func_{address:08x}"]}],
        }

    def test_collision_free_row_is_selected_and_collision_is_skipped(self):
        root = self._target()
        _rows, by_address, names = promote_sdk_symbols.parse_symbol_map(
            root / "config" / "symbol_addrs.txt")
        report = {"results": [
            self._item("sceSafe", 0x00100000),
            self._item("sceOne", 0x00100010, member="one.o"),
            self._item("sceTwo", 0x00100010, member="two.o"),
        ]}

        selected, skipped, collisions = promote_sdk_symbols.eligible_rows(report, by_address, names)

        self.assertEqual([row["item"]["name"] for row in selected], ["sceSafe"])
        self.assertEqual(collisions, {0x00100010})
        self.assertEqual(len(skipped), 2)
        self.assertEqual({row["reason"] for row in skipped}, {"sdk_name_collision"})


    def test_report_target_rejects_wrong_retail_program(self):
        with self.assertRaises(SystemExit):
            promote_sdk_symbols.validate_report_target(
                "p4", {"retail": {"program": "SLUS_216.21"}})

    def test_apply_renames_sources_and_writes_provenance(self):
        root = self._target()
        _rows, by_address, names = promote_sdk_symbols.parse_symbol_map(
            root / "config" / "symbol_addrs.txt")
        report = {"retail": {"program": "TEST", "sha1": "deadbeef"}, "results": [
            self._item("sceSafe", 0x00100000),
        ]}
        selected, skipped, collisions = promote_sdk_symbols.eligible_rows(report, by_address, names)

        changed, provenance = promote_sdk_symbols.apply_promotions(
            root, selected, report, skipped, collisions, update_sources=True)

        symbols = (root / "config" / "symbol_addrs.txt").read_text()
        source = (root / "src" / "caller.c").read_text()
        self.assertIn("sceSafe = 0x00100000", symbols)
        self.assertNotIn("func_00100000", symbols)
        self.assertIn("sceSafe();", source)
        self.assertNotIn("func_00100000", source)
        self.assertEqual(len(changed), 1)
        self.assertTrue(provenance.is_file())
        self.assertIn("archive:libkernl.a:kernel.o", provenance.read_text())


if __name__ == "__main__":
    unittest.main()
