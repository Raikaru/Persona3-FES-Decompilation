#!/usr/bin/env python3

import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import sdk_match
import verify


def _align(value, alignment=4):
    return (value + alignment - 1) & -alignment


def _elf_object(body=b"\x00\x00\x00\x0c\x08\x00\xe0\x03"):
    """Build a minimal little-endian MIPS relocatable object with one function."""
    strings = b"\0sample_function\0"
    section_strings = b"\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0"
    section_name = {
        name: section_strings.index(name.encode("ascii"))
        for name in (".text", ".rel.text", ".symtab", ".strtab", ".shstrtab")
    }
    symbol_table = bytes(16) + struct.pack("<IIIBBH", 1, 0, len(body), 0x12, 0, 1)
    relocations = struct.pack("<II", 0, (1 << 8) | 4)

    payload = bytearray(52)
    offsets = {}
    for name, blob in ((".text", body), (".rel.text", relocations),
                       (".symtab", symbol_table), (".strtab", strings),
                       (".shstrtab", section_strings)):
        while len(payload) < _align(len(payload)):
            payload.append(0)
        offsets[name] = len(payload)
        payload.extend(blob)
    section_offset = _align(len(payload))
    payload.extend(bytes(section_offset - len(payload)))

    sections = [bytes(40)]
    sections.append(struct.pack("<IIIIIIIIII", section_name[".text"], 1, 6, 0,
                                offsets[".text"], len(body), 0, 0, 4, 0))
    sections.append(struct.pack("<IIIIIIIIII", section_name[".rel.text"], 9, 0, 0,
                                offsets[".rel.text"], len(relocations), 3, 1, 4, 8))
    sections.append(struct.pack("<IIIIIIIIII", section_name[".symtab"], 2, 0, 0,
                                offsets[".symtab"], len(symbol_table), 4, 1, 4, 16))
    sections.append(struct.pack("<IIIIIIIIII", section_name[".strtab"], 3, 0, 0,
                                offsets[".strtab"], len(strings), 0, 0, 1, 0))
    sections.append(struct.pack("<IIIIIIIIII", section_name[".shstrtab"], 3, 0, 0,
                                offsets[".shstrtab"], len(section_strings), 0, 0, 1, 0))
    for section in sections:
        payload.extend(section)

    ident = b"\x7fELF" + bytes((1, 1, 1)) + bytes(9)
    header = ident + struct.pack("<HHIIIIIHHHHHH", 1, 8, 1, 0, 0, section_offset,
                                 0, 52, 0, 0, 40, len(sections), 5)
    payload[:52] = header
    return bytes(payload)


def _ar_member(name, payload):
    field = (name + "/").encode("ascii").ljust(16)
    header = (field + b"0".ljust(12) + b"0".ljust(6) + b"0".ljust(6)
              + b"100644".ljust(8) + str(len(payload)).encode("ascii").ljust(10) + b"`\n")
    return header + payload + (b"\n" if len(payload) & 1 else b"")


class _Retail:
    def __init__(self, ranges):
        self.ranges = ranges

    def bytes_at(self, address, size):
        payload = self.ranges[address]
        if size > len(payload):
            raise ValueError("range too small")
        return payload[:size]


class ArchiveTests(unittest.TestCase):
    def test_archive_member_parses_directly_as_object(self):
        object_data = _elf_object()
        archive_data = b"!<arch>\n" + _ar_member("sample.o", object_data)
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "sample.a"
            path.write_bytes(archive_data)
            members = sdk_match.read_archive(path)

        self.assertEqual([name for name, _payload in members], ["sample.o"])
        functions = sdk_match.archive_functions(members[0][1])
        self.assertEqual(len(functions), 1)
        self.assertEqual(functions[0]["name"], "sample_function")
        self.assertEqual(functions[0]["size"], 8)
        self.assertEqual(functions[0]["relocations"][0]["type"], "R_MIPS_26")

    def test_rejects_non_archive(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "bad.a"
            path.write_bytes(b"not an archive")
            with self.assertRaises(sdk_match.ArchiveError):
                sdk_match.read_archive(path)


class MatchingTests(unittest.TestCase):
    def test_canonicalization_matches_verifier_mask(self):
        body = bytes.fromhex("785634120800e003")
        relocations = [{"offset": 0, "r_type": 4}]
        canonical, ignored = sdk_match.canonical_bytes(body, relocations)

        self.assertEqual(canonical, bytes.fromhex("000000000800e003"))
        self.assertEqual(ignored, 4)
        self.assertEqual(verify.compare(body, relocations, bytes.fromhex("214365870800e003"))[0], 0)

    def test_retail_index_accepts_only_zero_boundary_tail(self):
        body = bytes.fromhex("785634120800e003")
        relocations = [{"offset": 0, "r_type": 4}]
        retail = _Retail({
            0x1000: bytes.fromhex("214365870800e00300000000"),
            0x2000: bytes.fromhex("214365870800e00301000000"),
        })
        index = sdk_match.build_retail_index(retail, {0x1000: 12, 0x2000: 12},
                                             [(len(body), relocations)])
        canonical, _ignored = sdk_match.canonical_bytes(body, relocations)
        digest = __import__("hashlib").sha256(canonical).hexdigest()
        key = (len(body), ((0, 4),))

        self.assertEqual(index[key][digest], [0x1000])


class TargetTests(unittest.TestCase):
    def test_explicit_target_root_and_boundary_file(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "config").mkdir()
            (root / "tools").mkdir()
            (root / "config" / "symbol_addrs.txt").write_text(
                "function = 0x00100000; // type:func\n")
            boundary = root / "tools" / "slus00000_functions.json"
            boundary.write_text(
                '{"program":"TEST","sha1":"abc","windows":{"00100000":8}}\n')

            resolved = sdk_match.resolve_target_root("p3", root)
            metadata, windows = sdk_match.load_boundaries(
                sdk_match.resolve_boundary_path(resolved, None))

        self.assertEqual(resolved, root.resolve())
        self.assertEqual(metadata["program"], "TEST")
        self.assertEqual(windows, {0x00100000: 8})

    def test_p4_shortcut_resolves_sibling_repository(self):
        root = sdk_match.resolve_target_root("p4", None)

        self.assertEqual(root.name, "Persona4-Decompilation")
        metadata, windows = sdk_match.load_boundaries(
            sdk_match.resolve_boundary_path(root, None))
        self.assertEqual(metadata["program"], "SLUS_217.82")
        self.assertTrue(windows)


if __name__ == "__main__":
    unittest.main()
