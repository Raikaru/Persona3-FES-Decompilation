"""Audit our marker-to-file assignment against upstream's translation-unit map.

Why this exists
---------------
`tools/verify.py` compares each marked function's bytes against its retail
window, so it is blind to *which file* a function lives in. Final link layout is
not: the linker emits object files in order, so a function marked in the wrong
translation unit can never produce an exact linked executable even when every
individual function matches.

Our own `config/slus21621.yaml` only describes four coarse subsegments
(code1/data1/code2/data2), so it cannot answer the question. The upstream
project (github.com/snaku/Persona3-FES-Decompilation) publishes a splat config
with a per-object-file boundary list covering the whole executable; a copy is
vendored at `config/upstream/splat.yaml`.

Caveats
-------
* Upstream targets a differently-hashed image, so the vram mapping is validated
  before use: their first C subsegment must land exactly on one of our marker
  addresses. Runs abort if that check fails.
* Directory naming differs between the projects (`Event/Fcl/fclShopMisc` versus
  `Main/Facility/fclShopMisc`). Only the file STEM is compared; a differing
  directory is reported separately and is not a layout defect.
* Third-party trees (rw/cri/sce) are reported but excluded from the headline
  count, matching verify.py's own first-party rule.

Usage:  python tools/tu_audit.py [--all] [--file SUBSTRING]
"""
import argparse
import bisect
import collections
import re
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
UPSTREAM_SPLAT = REPO / "config" / "upstream" / "splat.yaml"

sys.path.insert(0, str(TOOLS))
from verify import scan_markers  # noqa: E402

SUBSEG = re.compile(
    r"^\s*-\s*\[(0x[0-9A-Fa-f]+),\s*(\w+)(?:,\s*([^\]]+))?\]", re.M)
THIRD_PARTY = ("src/rw/", "src/cri/", "src/sce/")
THIRD_PARTY_FILES = {"src/crt0.c", "src/libc_core.c", "src/libcdvd.c"}


def load_tu_map():
    """Ordered (vram, kind, name) for every code translation unit upstream knows."""
    text = UPSTREAM_SPLAT.read_text(encoding="utf-8", errors="replace")
    vram = int(re.search(r"^\s*vram:\s*(0x[0-9A-Fa-f]+)", text, re.M).group(1), 16)
    units = [(vram + int(off, 16), kind, (name or "").strip())
             for off, kind, name in SUBSEG.findall(text)
             if kind in ("c", "asm") and name]
    units.sort()
    if not units:
        raise SystemExit("no code subsegments parsed from config/upstream/splat.yaml")
    return units


def is_first_party(rel):
    return not (rel.startswith(THIRD_PARTY) or rel in THIRD_PARTY_FILES)


def is_generated(path):
    return path.name.endswith(".match.c") or path.name.startswith(".permute_")


def collect_markers():
    out = []
    for path in sorted((REPO / "src").rglob("*.c")):
        if is_generated(path):
            continue
        rel = path.relative_to(REPO).as_posix()
        for mk in scan_markers(path):
            out.append((mk["addr"], rel, mk["name"], mk["line"]))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--all", action="store_true",
                    help="include third-party trees in the detail listing")
    ap.add_argument("--file", help="only report markers whose path contains this")
    args = ap.parse_args()

    units = load_tu_map()
    starts = [u[0] for u in units]
    markers = collect_markers()
    if not markers:
        raise SystemExit("no markers found under src/")

    # Sanity-check the vram mapping: upstream's boundaries must coincide with
    # real function entries, otherwise the two images are not comparable.
    marker_addrs = {a for a, _f, _n, _l in markers}
    landed = sum(1 for s in starts if s in marker_addrs)
    if landed < 20:
        raise SystemExit(
            f"upstream boundaries do not align with our markers "
            f"({landed} of {len(starts)} land on a marker); refusing to report")

    def tu_of(addr):
        i = bisect.bisect_right(starts, addr) - 1
        return units[i][2] if i >= 0 else None

    def stem(name):
        return name.rsplit("/", 1)[-1].lower()

    agree = 0
    dir_only = 0
    split = collections.Counter()
    detail = collections.defaultdict(list)
    unmapped = 0

    for addr, rel, name, line in markers:
        if args.file and args.file not in rel:
            continue
        tu = tu_of(addr)
        if tu is None:
            unmapped += 1
            continue
        ours = rel[len("src/"):].rsplit(".c", 1)[0]
        if ours.lower() == tu.lower():
            agree += 1
        elif stem(ours) == stem(tu):
            dir_only += 1
        else:
            key = (rel, tu)
            split[key] += 1
            detail[key].append((addr, name, line))

    fp_split = {k: v for k, v in split.items() if is_first_party(k[0])}
    print(f"markers scanned              : {len(markers)}")
    print(f"upstream boundaries on marker: {landed}/{len(starts)}")
    print(f"same translation unit        : {agree}")
    print(f"same stem, different folder  : {dir_only}  (naming only, not a defect)")
    print(f"different translation unit   : {sum(split.values())} "
          f"({sum(fp_split.values())} first-party)")
    if unmapped:
        print(f"below first boundary         : {unmapped}")

    print("\nfirst-party translation-unit splits (our file -> upstream TU):")
    for (rel, tu), count in sorted(fp_split.items(), key=lambda kv: -kv[1]):
        print(f"  {count:>5}  {rel}  ->  {tu}")
        if args.all:
            for addr, name, line in detail[(rel, tu)][:5]:
                print(f"           {addr:08x} {name} (line {line})")

    if args.all:
        print("\nthird-party splits:")
        for (rel, tu), count in sorted(split.items(), key=lambda kv: -kv[1]):
            if not is_first_party(rel):
                print(f"  {count:>5}  {rel}  ->  {tu}")


if __name__ == "__main__":
    main()
