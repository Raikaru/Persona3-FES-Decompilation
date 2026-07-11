#!/usr/bin/env python3

import struct
import sys
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build


class _Retail:
    def __init__(self, ranges):
        self.ranges = ranges

    def bytes_at(self, address, size):
        for start, data in self.ranges.items():
            if start <= address and address + size <= start + len(data):
                offset = address - start
                return data[offset:offset + size]
        raise ValueError(f"missing retail range {address:#x}+{size:#x}")


class _Object:
    """Small ELF-shaped object sufficient for build.py's placement checks."""

    endian = "<"

    def __init__(self, table_word):
        data = bytearray(b"\0\0\0\0")
        data += struct.pack("<I", table_word)
        data += struct.pack("<II", 0, (1 << 8) | 2)  # R_MIPS_32 target
        self.data = bytes(data)
        self.sh = [
            {"idx": 0, "type": 0, "flags": 0, "size": 0, "offset": 0},
            {"idx": 1, "name": ".text", "type": 1, "flags": 6,
             "size": 4, "offset": 0, "addralign": 4},
            {"idx": 2, "name": ".rodata", "type": 1, "flags": 2,
             "size": 4, "offset": 4, "addralign": 4},
            {"idx": 3, "name": ".rel.rodata", "type": 9, "flags": 0,
             "size": 8, "offset": 8, "link": 4, "info": 2, "entsize": 8},
        ]
        target = {"name": "internal_label", "value": 0x20,
                  "size": 0, "shndx": 1}
        self.symtabs = {4: [{"name": ""}, target]}
        self.symbols = [
            {"name": "f", "value": 0, "size": 4, "shndx": 1},
            target,
        ]

    def function(self, name):
        if name != "f":
            raise KeyError(name)
        return self.data[:4], []


class DataRelocationEligibilityTests(unittest.TestCase):
    real = [{"name": "f", "addr": 0x1000}]

    def plan(self, table_word):
        obj = _Object(table_word)
        retail = _Retail({
            0x1000: b"\0\0\0\0",
            0x2000: struct.pack("<I", 0x1020),
        })
        # In a real object this base is recovered from a matched function's
        # relocation to the owned rodata. The synthetic function has no such
        # relocation, so pin only that fixture fact while exercising all of the
        # relocated-section validation below.
        with mock.patch.object(build, "recover_section_bases", return_value={2: 0x2000}):
            return build.plan_data_sections(obj, self.real, retail, 0, set())

    def test_internal_label_addend_mismatch_rejects_object(self):
        # The function bytes match, but the table's addend points 0x1c bytes
        # into the function while retail points 0x20 bytes into it.
        ok, sections = self.plan(0x1C)
        self.assertFalse(ok)
        self.assertEqual(sections, {})

    def test_identical_internal_label_addend_accepts_object(self):
        ok, sections = self.plan(0)
        self.assertTrue(ok)
        self.assertEqual(sections, {".rodata": (0x2000, 4)})


if __name__ == "__main__":
    unittest.main()
