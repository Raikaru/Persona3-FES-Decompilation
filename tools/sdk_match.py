#!/usr/bin/env python3
"""Index SCE PS2 SDK archives and find relocation-normalized P3 retail matches.

The SDK remains external to the repository. Point --sdk-root (or
P3_PS2SDK_ROOT) at the Runtime directory containing ee/lib. Results are
candidate evidence: only tools/verify.py may declare reconstructed C a MATCH.
"""

from pathlib import Path
import argparse
import hashlib
import json
import os
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
DEFAULT_ARCHIVES = ("libcdvd.a", "libkernl.a", "libmc.a", "libmc2.a", "libpad.a", "libpad2.a")
SYMBOL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;")


class ArchiveError(ValueError):
    pass


def _decimal(field, context):
    try:
        return int(field.decode("ascii").strip() or "0")
    except ValueError as exc:
        raise ArchiveError(f"invalid {context}: {field!r}") from exc


def read_archive(path):
    """Return [(member_name, member_bytes)] from a GNU/BSD ar archive."""
    data = Path(path).read_bytes()
    if not data.startswith(b"!<arch>\n"):
        raise ArchiveError(f"not an ar archive: {path}")

    members = []
    strings = b""
    offset = 8
    while offset < len(data):
        if offset + 60 > len(data):
            raise ArchiveError(f"truncated member header at {offset:#x}: {path}")
        header = data[offset:offset + 60]
        offset += 60
        if header[58:60] != b"`\n":
            raise ArchiveError(f"invalid member header at {offset - 60:#x}: {path}")
        size = _decimal(header[48:58], "member size")
        if offset + size > len(data):
            raise ArchiveError(f"truncated member payload at {offset:#x}: {path}")
        payload = data[offset:offset + size]
        offset += size
        if offset & 1:
            offset += 1

        raw_name = header[:16].decode("ascii", "replace").rstrip()
        if raw_name == "//":
            strings = payload
            continue
        if raw_name in ("/", "/SYM64/"):
            continue
        if raw_name.startswith("#1/"):
            name_size = _decimal(raw_name[3:].encode("ascii"), "BSD name size")
            if name_size > len(payload):
                raise ArchiveError(f"truncated BSD member name: {path}")
            name = payload[:name_size].decode("utf-8", "replace").rstrip("\0")
            payload = payload[name_size:]
        elif raw_name.startswith("/") and raw_name[1:].isdigit():
            if not strings:
                raise ArchiveError(f"GNU long name without string table: {path}")
            name_offset = int(raw_name[1:])
            if name_offset >= len(strings):
                raise ArchiveError(f"GNU long name offset outside string table: {path}")
            end = strings.find(b"/\n", name_offset)
            if end < 0:
                end = strings.find(b"\0", name_offset)
            if end < 0:
                end = len(strings)
            name = strings[name_offset:end].decode("utf-8", "replace")
        else:
            name = raw_name.rstrip("/")

        if name:
            members.append((name, payload))
    return members


def archive_functions(member_data):
    """Return deterministic function records from one relocatable ELF member."""
    obj = verify.ObjectFile.from_bytes(member_data)
    grouped = {}
    for symbol in obj.symbols:
        section_index = symbol["shndx"]
        if not symbol["name"] or not symbol["size"] or section_index in (0, 0xFFF1):
            continue
        if section_index >= len(obj.sh):
            continue
        section = obj.sh[section_index]
        if not section["flags"] & 0x4:  # SHF_EXECINSTR
            continue
        if symbol["sym_type"] not in (0, 2):  # NOTYPE or FUNC
            continue
        key = (section_index, symbol["value"], symbol["size"])
        grouped.setdefault(key, []).append(symbol)

    records = []
    for symbols in grouped.values():
        symbols.sort(key=lambda item: (-item["bind"], item["name"]))
        primary = symbols[0]
        body, relocs = obj.function(primary["name"])
        records.append({
            "name": primary["name"],
            "aliases": sorted({item["name"] for item in symbols if item["name"] != primary["name"]}),
            "size": len(body),
            "section": obj.sh[primary["shndx"]]["name"],
            "section_index": primary["shndx"],
            "section_offset": primary["value"],
            "body": body,
            "relocations": sorted(relocs, key=lambda item: (item["offset"], item["r_type"], item.get("symbol") or "")),
        })
    records.sort(key=lambda item: (item["section_index"], item["section_offset"], item["name"]))
    return records


def canonical_bytes(body, relocations):
    """Zero exactly the bytes ignored by verify.compare()."""
    result = bytearray(body)
    mask = verify.mask_bytes(len(result), relocations)
    for index, ignored in enumerate(mask):
        if ignored:
            result[index] = 0
    return bytes(result), sum(mask)


def read_known_symbols(paths):
    names = {}
    addresses = {}
    for path in paths:
        if not path.is_file():
            continue
        for line in path.read_text(errors="replace").splitlines():
            match = SYMBOL_RE.match(line)
            if not match:
                continue
            name, raw_address = match.groups()
            address = int(raw_address, 16)
            names.setdefault(name, set()).add(address)
            addresses.setdefault(address, set()).add(name)
    return ({name: sorted(values) for name, values in names.items()},
            {address: sorted(values) for address, values in addresses.items()})


def load_retail_path(explicit, target_root):
    if explicit:
        path = Path(explicit)
    else:
        value = os.environ.get("P4_RETAIL_ELF") if target_root.name == "Persona4-Decompilation" else None
        value = value or os.environ.get("P3_RETAIL_ELF")
        if value:
            path = Path(value)
        else:
            config = {}
            for name in ("verify_config.json", "verify_config.local.json"):
                candidate = target_root / "tools" / name
                if candidate.is_file():
                    config.update(json.loads(candidate.read_text()))
            value = config.get("retail_elf")
            if not value:
                raise SystemExit(
                    "sdk_match: missing retail ELF; pass --retail or set "
                    "P3_RETAIL_ELF/P4_RETAIL_ELF")
            path = Path(value)
    if not path.is_file():
        raise SystemExit(f"sdk_match: retail ELF does not exist: {path}")
    return path


def resolve_library_dir(sdk_root):
    root = Path(sdk_root)
    candidates = (root / "ee" / "lib", root / "Runtime" / "ee" / "lib", root)
    for candidate in candidates:
        if candidate.is_dir() and any(candidate.glob("*.a")):
            return candidate
    raise SystemExit(f"sdk_match: cannot find ee/lib archives under: {root}")


def load_boundaries(path):
    metadata = json.loads(path.read_text())
    if not isinstance(metadata.get("windows"), dict):
        raise SystemExit(f"sdk_match: boundary file has no windows object: {path}")
    windows = {int(address, 16): size for address, size in metadata["windows"].items() if size}
    return metadata, windows


def build_retail_index(retail, windows, patterns):
    """Cache canonical retail hashes once per (size, relocation mask) pattern."""
    index = {}
    for size, relocations in patterns:
        key = (size, tuple((item["offset"], item["r_type"]) for item in relocations))
        if key in index:
            continue
        entries = {}
        for address, window in windows.items():
            if window < size:
                continue
            payload = retail.bytes_at(address, window)
            if any(payload[size:]):
                continue
            canonical, _ignored = canonical_bytes(payload[:size], relocations)
            digest = hashlib.sha256(canonical).hexdigest()
            entries.setdefault(digest, []).append(address)
        index[key] = entries
    return index


def public_relocations(relocations):
    return [{
        "offset": item["offset"],
        "type": item["type"],
        "type_id": item["r_type"],
        "symbol": item.get("symbol") or "",
    } for item in relocations]


def match_archives(library_dir, archive_names, retail, windows, known_names, known_addresses):
    indexed = []
    patterns = []
    for archive_name in archive_names:
        archive_path = library_dir / archive_name
        if not archive_path.is_file():
            raise SystemExit(f"sdk_match: archive does not exist: {archive_path}")
        archive_record = {
            "archive": archive_name,
            "path": str(archive_path),
            "sha256": hashlib.sha256(archive_path.read_bytes()).hexdigest(),
            "members": [],
        }
        for member_name, payload in read_archive(archive_path):
            if not payload.startswith(b"\x7fELF"):
                continue
            try:
                functions = archive_functions(payload)
            except (AssertionError, IndexError, ValueError) as exc:
                raise SystemExit(f"sdk_match: cannot parse {archive_name}:{member_name}: {exc}") from exc
            member_record = {
                "member": member_name,
                "sha256": hashlib.sha256(payload).hexdigest(),
                "functions": functions,
            }
            archive_record["members"].append(member_record)
            patterns.extend((item["size"], item["relocations"]) for item in functions)
        archive_record["members"].sort(key=lambda item: item["member"])
        indexed.append(archive_record)

    retail_index = build_retail_index(retail, windows, patterns)
    results = []
    for archive in indexed:
        for member in archive["members"]:
            for function in member["functions"]:
                canonical, ignored = canonical_bytes(function["body"], function["relocations"])
                digest = hashlib.sha256(canonical).hexdigest()
                pattern_key = (function["size"], tuple(
                    (item["offset"], item["r_type"]) for item in function["relocations"]))
                candidates = sorted(retail_index[pattern_key].get(digest, ()))
                aliases = [function["name"]] + function["aliases"]
                named_candidates = sorted({
                    address for name in aliases for address in known_names.get(name, ())
                    if address in candidates
                })
                status = "NO_MATCH"
                if named_candidates:
                    status = "KNOWN_SYMBOL_NORMALIZED" if len(named_candidates) == 1 else "AMBIGUOUS_KNOWN_SYMBOL"
                elif len(candidates) == 1:
                    status = "UNIQUE_NORMALIZED"
                elif candidates:
                    status = "AMBIGUOUS_NORMALIZED"
                results.append({
                    "archive": archive["archive"],
                    "archive_sha256": archive["sha256"],
                    "member": member["member"],
                    "member_sha256": member["sha256"],
                    "name": function["name"],
                    "aliases": function["aliases"],
                    "size": function["size"],
                    "section": function["section"],
                    "section_offset": function["section_offset"],
                    "canonical_sha256": digest,
                    "compared_bytes": function["size"] - ignored,
                    "ignored_relocation_bytes": ignored,
                    "relocations": public_relocations(function["relocations"]),
                    "status": status,
                    "candidates": [
                        {"address": f"0x{address:08X}", "known_names": known_addresses.get(address, [])}
                        for address in candidates
                    ],
                    "named_candidates": [f"0x{address:08X}" for address in named_candidates],
                })
    results.sort(key=lambda item: (item["archive"], item["member"], item["section_offset"], item["name"]))
    return indexed, results


def summarize(results):
    counts = {}
    for item in results:
        counts[item["status"]] = counts.get(item["status"], 0) + 1
    return dict(sorted(counts.items()))


def resolve_target_root(target, explicit):
    if explicit:
        root = Path(explicit).resolve()
    elif target == "p4":
        root = (REPO.parent / "Persona4-Decompilation").resolve()
    else:
        root = REPO
    if not (root / "config" / "symbol_addrs.txt").is_file():
        raise SystemExit(f"sdk_match: target repository is missing symbol_addrs.txt: {root}")
    return root


def resolve_boundary_path(target_root, explicit):
    if explicit:
        path = Path(explicit).resolve()
    else:
        candidates = sorted((target_root / "tools").glob("slus*_functions.json"))
        if len(candidates) != 1:
            raise SystemExit(
                f"sdk_match: expected exactly one slus*_functions.json under "
                f"{target_root / 'tools'}, found {len(candidates)}")
        path = candidates[0]
    if not path.is_file():
        raise SystemExit(f"sdk_match: boundary file does not exist: {path}")
    return path


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--target", choices=("p3", "p4"), default="p3",
                        help="repository target shortcut (default: p3)")
    parser.add_argument("--target-root",
                        help="target repository root; overrides --target")
    parser.add_argument("--windows",
                        help="target slus*_functions.json (auto-detected by default)")
    parser.add_argument("--sdk-root", default=os.environ.get("P3_PS2SDK_ROOT"),
                        help="SDK Runtime directory containing ee/lib (or P3_PS2SDK_ROOT)")
    parser.add_argument("--retail",
                        help="target retail ELF (or P3_RETAIL_ELF/P4_RETAIL_ELF/config)")
    parser.add_argument("--archive", action="append", dest="archives", metavar="NAME",
                        help="archive filename under ee/lib; repeatable (default: core SCE archives)")
    parser.add_argument("--json", metavar="PATH", help="write deterministic JSON report")
    parser.add_argument("--show-matches", action="store_true",
                        help="print each non-ambiguous normalized candidate")
    args = parser.parse_args()

    if not args.sdk_root:
        raise SystemExit("sdk_match: missing SDK root; pass --sdk-root or set P3_PS2SDK_ROOT")
    target_root = resolve_target_root(args.target, args.target_root)
    boundary_path = resolve_boundary_path(target_root, args.windows)
    library_dir = resolve_library_dir(args.sdk_root)
    archive_names = args.archives or list(DEFAULT_ARCHIVES)
    metadata, windows = load_boundaries(boundary_path)
    retail_path = load_retail_path(args.retail, target_root)
    retail = verify.RetailElf(retail_path, expect_sha1=metadata.get("sha1"))
    known_names, known_addresses = read_known_symbols((
        target_root / "config" / "symbol_addrs.txt",
        target_root / "config" / "symbols_recovered.txt",
    ))

    indexed, results = match_archives(
        library_dir, archive_names, retail, windows, known_names, known_addresses)
    summary = summarize(results)
    print(f"target repository: {target_root}")
    print(f"target program: {metadata.get('program')}")
    print(f"library directory: {library_dir}")
    print(f"archives scanned: {len(indexed)}")
    print(f"ELF members scanned: {sum(len(item['members']) for item in indexed)}")
    print(f"functions scanned: {len(results)}")
    for status, count in summary.items():
        print(f"  {status:<26} {count}")

    if args.show_matches:
        for item in results:
            if item["status"] not in ("KNOWN_SYMBOL_NORMALIZED", "UNIQUE_NORMALIZED"):
                continue
            candidate = item["candidates"][0]
            print(f"{item['status']}: {item['archive']}:{item['member']} "
                  f"{item['name']} ({item['size']}B) -> {candidate['address']}"
                  f" {', '.join(candidate['known_names'])}")

    if args.json:
        report = {
            "schema_version": 1,
            "retail": {
                "program": metadata.get("program"),
                "sha1": metadata.get("sha1"),
                "repository": str(target_root),
            },
            "sdk": {
                "library_directory": str(library_dir),
                "archives": [{
                    "name": item["archive"],
                    "sha256": item["sha256"],
                    "elf_members": len(item["members"]),
                } for item in indexed],
            },
            "summary": summary,
            "results": results,
        }
        output = Path(args.json)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(report, indent=1) + "\n", newline="\n")
        print(f"report: {output}")


if __name__ == "__main__":
    main()
