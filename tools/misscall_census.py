#!/usr/bin/env python3
"""Missing-call census: retail calls we never make, named.

`gap_census.py` reports that a block of retail-only instructions contains a
`jal`.  This resolves that `jal` to a **symbol**, which turns "some code is
missing here" into "we never call `func_00286540`".

The asymmetry that makes this work: retail is a fully linked ELF, so its `jal`
encodes a real absolute target.  Our candidate's calls are relocations against
a symbol and their instruction field is zero, so `verify.py` masks them --- but
retail's side is never masked and can always be decoded.

Blocks are aligned exactly as in `gap_census.py`, so a reported call is one
retail genuinely makes at a point where we emit nothing, not a displacement
artifact.

The mirror direction is reported too: a candidate-only block containing a call
is a call **we** make that retail does not, which is either a helper retail
inlines or a call that does not belong.

Usage:
  python tools/misscall_census.py --report build/baselines/W460_gate.json \
                                  --out build/wip/W461_misscall.md
  python tools/misscall_census.py --report <gate> --file src/Camp/h_camp.c
"""

from pathlib import Path
import argparse
import bisect
import collections
import difflib
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, ObjectFile, RetailElf, compile_object,
                    load_config, mask_bytes, scan_markers, window_for)

THIRD_PARTY_DIRS = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}

OP_J, OP_JAL = 0x02, 0x03
SPECIAL, FUNCT_JALR = 0x00, 0x09


def first_party(path):
    norm = str(path).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[4:]
    return not (norm in THIRD_PARTY_FILES
                or any(norm.startswith(d) for d in THIRD_PARTY_DIRS))


def call_target(word, pc):
    """-> absolute target of a j/jal at `pc`, or None; 'INDIRECT' for jalr."""
    op = word >> 26
    if op in (OP_J, OP_JAL):
        return ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
    if op == SPECIAL and (word & 0x3F) == FUNCT_JALR:
        return "INDIRECT"
    return None


class SymbolTable:
    """Address -> best name, from the catalogue plus every source marker."""

    def __init__(self, results):
        self.by_addr = {}
        for r in results:
            self.by_addr[int(r["addr"], 16)] = (r["name"], r["file"], r["status"])
        self.addrs = sorted(self.by_addr)

    def name(self, addr):
        hit = self.by_addr.get(addr)
        if hit:
            return hit[0], hit[2]
        i = bisect.bisect_right(self.addrs, addr) - 1
        if i >= 0 and addr - self.addrs[i] < 0x2000:
            base = self.by_addr[self.addrs[i]]
            return "%s+%#x" % (base[0], addr - self.addrs[i]), base[2]
        return "%#010x" % addr, "?"


def words_of(buf, mask=None):
    out = []
    for i in range(0, len(buf) - 3, 4):
        if mask is not None and any(mask[i:i + 4]):
            out.append(-1)
        else:
            out.append(int.from_bytes(buf[i:i + 4], "little"))
    return out


def analyse(body, rels, target, retail_base, syms):
    mask = mask_bytes(max(len(body), len(target)), rels)
    cand = words_of(body, mask)
    ret = words_of(target, mask[:len(target)] if len(mask) >= len(target) else None)

    sm = difflib.SequenceMatcher(a=cand, b=ret, autojunk=False)
    missing, extra = [], []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag not in ("insert", "delete", "replace"):
            continue
        if tag in ("insert", "replace"):
            for k in range(j1, j2):
                tgt = call_target(ret[k], retail_base + k * 4)
                if tgt is None:
                    continue
                if tgt == "INDIRECT":
                    missing.append({"at": i1 * 4, "target": "INDIRECT",
                                    "name": "(indirect call)", "status": "-"})
                else:
                    nm, st = syms.name(tgt)
                    missing.append({"at": i1 * 4, "target": "%#010x" % tgt,
                                    "name": nm, "status": st})
        if tag in ("delete", "replace"):
            for k in range(i1, i2):
                if cand[k] < 0:
                    continue                 # relocated: our own call, unresolvable here
                tgt = call_target(cand[k], k * 4)
                if tgt == "INDIRECT":
                    extra.append({"at": k * 4, "name": "(indirect call)"})
    # `replace` blocks pair up: drop a missing call that has an extra at the
    # same offset, since that is a target difference, not an omission.
    ex_off = {e["at"] for e in extra}
    missing = [m for m in missing if m["at"] not in ex_off]
    return missing, extra


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--file")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21621_functions.json").read_text())
    retail = RetailElf(cfg["retail_elf"], expect_sha1=sizes.get("sha1"))
    results = json.load(open(args.report))["results"]
    syms = SymbolTable(results)
    wanted = args.file.replace("\\", "/") if args.file else None

    by_file = collections.defaultdict(list)
    for r in results:
        if r["status"] != "NONMATCHING":
            continue
        path = r["file"].replace("\\", "/")
        if not first_party(path) or (wanted and path != wanted):
            continue
        by_file[path].append(r)

    bounds = {int(a, 16) for a in sizes["windows"]}
    for c in sorted((REPO / "src").rglob("*.c")):
        for m in scan_markers(c):
            bounds.add(m["addr"])
    bounds = sorted(bounds)

    findings = []
    for path in sorted(by_file):
        cpath = (REPO / path).resolve()
        if not cpath.exists():
            continue
        try:
            with tempfile.TemporaryDirectory(prefix="p3mc_") as td:
                obj, _log = compile_object(cpath, cfg, objdir=Path(td))
                if obj is None:
                    print("  ! %s: compile failed" % path, file=sys.stderr)
                    continue
                for r in by_file[path]:
                    try:
                        body, rels = obj.function(r["name"])
                    except Exception:
                        continue
                    addr = int(r["addr"], 16)
                    tgt = retail.bytes_at(addr, window_for(addr, bounds))
                    missing, extra = analyse(body, rels, tgt, addr, syms)
                    if missing or extra:
                        findings.append({
                            "file": path, "addr": r["addr"], "name": r["name"],
                            "nd": r["normalized_diff"], "object": r["object_size"],
                            "window": r.get("window"),
                            "missing": missing, "extra": extra})
        except Exception as exc:
            print("  ! %s: %s" % (path, exc), file=sys.stderr)

    findings.sort(key=lambda f: (-len(f["missing"]), -f["nd"]))

    called = collections.Counter()
    for f in findings:
        for m in f["missing"]:
            called[(m["name"], m["status"])] += 1
    tot_missing = sum(len(f["missing"]) for f in findings)
    tot_extra = sum(len(f["extra"]) for f in findings)

    lines = ["# Missing-call census", "",
             "Source report: `%s`" % args.report, "",
             "%d NONMATCHING functions omit at least one call retail makes, or "
             "make one it does not." % len(findings), "",
             "**%d missing calls** (retail calls at a point where we emit nothing) "
             "and **%d extra indirect calls**." % (tot_missing, tot_extra), "",
             "Retail is a linked ELF, so its `jal` targets decode directly; our own "
             "calls are relocations and are masked. A row here therefore names a "
             "function retail calls and we do not.", "",
             "## Most-omitted callees", "", "|callee|status|omissions|", "|---|---|---:|"]
    for (nm, st), n in called.most_common(40):
        lines.append("|`%s`|%s|%d|" % (nm, st, n))

    byfile = collections.Counter()
    for f in findings:
        byfile[f["file"]] += len(f["missing"])
    lines += ["", "## Missing calls by file", "", "|file|missing|", "|---|---:|"]
    for f, n in byfile.most_common(30):
        lines.append("|%s|%d|" % (f, n))

    lines += ["", "## Functions", ""]
    for f in findings:
        win = "%s/%s" % (f["object"], f["window"]) if f["window"] else str(f["object"])
        lines.append("### `%s` %s — nd %d — %s — %s"
                     % (f["name"], f["addr"], f["nd"], win, f["file"]))
        lines.append("")
        for m in f["missing"][:16]:
            lines.append("- MISSING call to `%s` (%s, %s) at candidate offset %d"
                         % (m["name"], m["target"], m["status"], m["at"]))
        if len(f["missing"]) > 16:
            lines.append("- … %d more missing" % (len(f["missing"]) - 16))
        for e in f["extra"][:6]:
            lines.append("- EXTRA %s at candidate offset %d" % (e["name"], e["at"]))
        lines.append("")

    text = "\n".join(lines)
    if args.out:
        Path(args.out).write_text(text, encoding="utf-8")
        print("%d functions, %d missing calls, %d extra -> %s"
              % (len(findings), tot_missing, tot_extra, args.out))
        for (nm, st), n in called.most_common(12):
            print("   %-34s %-12s %d" % (nm, st, n))
    else:
        print(text)


if __name__ == "__main__":
    main()
