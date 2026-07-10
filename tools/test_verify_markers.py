#!/usr/bin/env python3

import tempfile
import unittest
from pathlib import Path

from reconcile_function_boundaries import reconciled_windows
from verify import scan_markers


class MarkerScannerTests(unittest.TestCase):
    def scan(self, source: str):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "markers.c"
            path.write_text(source)
            return scan_markers(path)

    def test_braces_in_literals_and_comments_do_not_swallow_next_marker(self):
        markers = self.scan(
            """// FUN_00100000 NONMATCHING
int first(char value)
{
    /* Neither } nor { changes function depth. */
    return value < '{' && value != '}';
}
// FUN_00100020 NONMATCHING
int second(void)
{
    return 2;
}
"""
        )

        self.assertEqual([marker["name"] for marker in markers], ["first", "second"])
        self.assertEqual([marker["addr"] for marker in markers], [0x00100000, 0x00100020])

    def test_empty_marker_does_not_inherit_following_definition(self):
        markers = self.scan(
            """// FUN_00100000 NONMATCHING
// FUN_00100010 NONMATCHING
int second(void)
{
    return 2;
}
"""
        )

        self.assertEqual(len(markers), 2)
        self.assertIsNone(markers[0]["name"])
        self.assertEqual(markers[1]["name"], "second")


class BoundaryReconciliationTests(unittest.TestCase):
    def test_source_boundary_splits_original_window(self):
        windows = reconciled_windows({0x1000: 0x100, 0x1100: 0x20}, {0x1040})

        self.assertEqual(windows["00001000"], 0x40)
        self.assertEqual(windows["00001040"], 0xC0)
        self.assertEqual(windows["00001100"], 0x20)

    def test_original_terminal_window_is_not_extended_across_gap(self):
        windows = reconciled_windows(
            {0x1000: 0x20, 0x20000: 0x40},
            {0x1010},
        )

        self.assertEqual(windows["00001000"], 0x10)
        self.assertEqual(windows["00001010"], 0x1EFF0)
        self.assertEqual(windows["00020000"], 0x40)


if __name__ == "__main__":
    unittest.main()
