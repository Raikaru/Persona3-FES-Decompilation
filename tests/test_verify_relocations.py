#!/usr/bin/env python3

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import verify


class _Retail:
    def __init__(self, code, data):
        self.ranges = {0x1000: code, 0x2000: data}

    def bytes_at(self, address, size):
        for start, payload in self.ranges.items():
            if start <= address and address + size <= start + len(payload):
                offset = address - start
                return payload[offset:offset + size]
        raise ValueError(f"missing retail range {address:#x}+{size:#x}")


class _JumpTableObject:
    """ELF-shaped fixture with a function-owned .rodata jump table."""

    endian = "<"

    def __init__(self, table_targets):
        # The function's HI16/LO16 pair references the table.  Its unresolved
        # object addends are zero; retail encodes the recovered 0x2000 base.
        self.code = struct.pack("<II", 0, 0)
        raw_table = b"".join(struct.pack("<I", 0) for _ in table_targets)
        self.data = self.code + raw_table
        self.sh = [
            {"idx": 1, "name": ".text", "type": 1, "flags": 6,
             "size": len(self.code), "offset": 0},
            {"idx": 2, "name": ".rodata", "type": 1, "flags": 2,
             "size": len(raw_table), "offset": len(self.code)},
        ]
        self.function_symbol = {"name": "f", "value": 0, "size": len(self.code),
                                "shndx": 1, "bind": 1}
        self.table_symbol = {"name": "jump_table", "value": 0,
                             "size": len(raw_table), "shndx": 2, "bind": 0}
        self.labels = [
            {"name": f"label_{index}", "value": value, "size": 0,
             "shndx": 1, "bind": 0}
            for index, value in enumerate((0x10, 0x20, 0x30))
        ]
        self.external = {"name": "external_target", "value": 0,
                         "size": 0, "shndx": 0, "bind": 1}
        self.symbols = [self.function_symbol, self.table_symbol] + self.labels
        self.table_targets = table_targets

    def function_record(self, name):
        if name != "f":
            raise KeyError(name)
        table_relocs = [
            {"offset": 0, "r_type": 5, "symbol": "jump_table",
             "symbol_record": self.table_symbol},
            {"offset": 4, "r_type": 6, "symbol": "jump_table",
             "symbol_record": self.table_symbol},
        ]
        return {"symbol": self.function_symbol, "section": self.sh[0],
                "body": self.code, "rels": table_relocs}

    def function(self, name):
        record = self.function_record(name)
        return record["body"], record["rels"]

    def section_reloc_records(self, target_idx):
        if target_idx != 2:
            return []
        return [
            {"offset": index * 4, "r_type": 2,
             "symbol": self.labels[target], "symbol_record": self.labels[target]}
            for index, target in enumerate(self.table_targets)
        ]


class OwnedJumpTableTests(unittest.TestCase):
    def _run(self, table_targets, retail_targets=None):
        obj = _JumpTableObject(table_targets)
        retail_code = struct.pack("<II", 0, 0x2000)
        if retail_targets is None:
            retail_targets = (0, 1, 2)
        retail_data = b"".join(
            struct.pack("<I", 0x1000 + (0x10, 0x20, 0x30)[target])
            for target in retail_targets
        )
        retail = _Retail(retail_code, retail_data)
        return verify.compare_owned_data_relocations(
            obj, "f", 0x1000, retail, {"f": 0x1000})

    def test_identical_internal_targets_match(self):
        count, details = self._run((0, 1, 2))

        self.assertEqual(count, 0)
        self.assertEqual(details, [])

    def test_permuted_internal_targets_are_not_masked(self):
        count, details = self._run((0, 2, 1))

        self.assertEqual(count, 2)
        self.assertEqual([item["offset"] for item in details], [4, 8])

    def test_external_target_is_left_to_normal_relocation_handling(self):
        obj = _JumpTableObject((0, 1, 2))
        obj.labels[1] = obj.external
        retail = _Retail(
            struct.pack("<II", 0, 0x2000),
            struct.pack("<III", 0x1010, 0x00960000, 0x1030),
        )
        count, details = verify.compare_owned_data_relocations(
            obj, "f", 0x1000, retail, {"f": 0x1000})

        self.assertEqual(count, 0)
        self.assertEqual(details, [])


if __name__ == "__main__":
    unittest.main()
