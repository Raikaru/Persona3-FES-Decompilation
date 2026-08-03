"""Audit call relocations against retail's actual call targets.

`verify.py` MASKS relocation fields when it compares bytes, because the linker
fills them in. That is correct for byte matching, but it means a function can
report MATCH with normalized_diff 0 while its `jal` relocations name a
DIFFERENT function than retail calls. Such a function is byte-identical and
semantically wrong: it would link to the wrong code.

This tool cross-checks every `R_MIPS_26` relocation in a verify report. For each
one it resolves the symbol our object references to an address (via the report's
own name -> address map, the `FUN_xxxxxxxx`/`func_xxxxxxxx` convention, or by
stripping a `#pragma alias` suffix) and compares it with the `retail_target`
the report already records.

    python tools/reloc_audit.py --report build/baselines/W442_gate.json \
        [--out build/wip/reloc_audit.md] [--status MATCH] [--first-party]

`--status MATCH` is the important mode: those are the functions the campaign
currently believes are finished.
"""
import argparse
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

THIRD_PARTY_PREFIXES = ("rw/", "cri/", "sce/", "lib/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}
# `thunk_FUN_xxxxxxxx` encodes the address the thunk JUMPS TO, not its own, so
# it must never be resolved by the naming convention — only by the symbol table.
HEXNAME = re.compile(r"^(?:FUN|func|sub)_([0-9a-fA-F]{8})")
# `#pragma alias` variants share the aliased symbol's address; strip the suffix.
ALIAS_SUFFIX = re.compile(
    r"_(?:abs|sda|ptr|typed|u32|u64|s16|s32|i|f|y2|y3|i2f1i3f3|[0-9a-fA-F]{4,8}|\d+)$")


def is_third_party(rel_file):
    norm = rel_file.replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[len("src/"):]
    return norm in THIRD_PARTY_FILES or norm.startswith(THIRD_PARTY_PREFIXES)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--status", default="", help="only audit rows with this status")
    ap.add_argument("--first-party", action="store_true")
    args = ap.parse_args()

    rows = json.loads(Path(args.report).read_text())["results"]
    name2addr = {}
    for r in rows:
        name2addr.setdefault(r["name"], int(r["addr"], 16))

    def resolve(sym):
        if not sym or sym.startswith("@"):
            return None
        if sym in name2addr:
            return name2addr[sym]
        m = HEXNAME.match(sym)
        if m:
            return int(m.group(1), 16)
        base = ALIAS_SUFFIX.sub("", sym)
        if base != sym:
            if base in name2addr:
                return name2addr[base]
            m = HEXNAME.match(base)
            if m:
                return int(m.group(1), 16)
        return None

    addr2names = defaultdict(list)
    for n, a in name2addr.items():
        addr2names[a].append(n)

    findings = {}
    checked = unresolved = 0
    for r in rows:
        if args.status and r["status"] != args.status:
            continue
        if args.first_party and is_third_party(r["file"]):
            continue
        hits = []
        for rel in r.get("relocations") or []:
            if rel.get("type") != "R_MIPS_26":
                continue
            target = rel.get("retail_target")
            if not target:
                continue
            want = int(target, 16)
            # A thunk's retail target is a tiny relative value, not an address.
            if want < 0x100000:
                continue
            got = resolve(rel.get("symbol"))
            if got is None:
                unresolved += 1
                continue
            checked += 1
            if got != want:
                hits.append((rel["offset"], rel["symbol"], got, want))
        if hits:
            findings[(r["file"], r["addr"], r["name"], r["status"])] = hits

    out = ["# Call-relocation audit", ""]
    out.append(f"{checked} R_MIPS_26 relocations resolved and compared "
               f"({unresolved} symbols could not be resolved and were skipped).")
    out.append("")
    out.append(f"**{len(findings)} functions reference at least one call target that is not "
               f"the address retail calls.** `verify.py` masks relocation fields, so these are "
               f"invisible to normalized_diff: a MATCH row here is byte-identical but calls the "
               f"wrong function.")
    out.append("")
    ordered = sorted(findings.items(), key=lambda kv: (kv[0][3] != "MATCH", -len(kv[1])))
    for (rel_file, addr, name, status), hits in ordered:
        out.append(f"## {addr} `{name}` — {status}")
        out.append("")
        out.append(f"`{rel_file.replace(chr(92), '/')}`")
        out.append("")
        out.append("| sites | our symbol | our address | retail target | retail symbol |")
        out.append("|---:|---|---|---|---|")
        grouped = Counter((s, g, w) for _, s, g, w in hits)
        for (sym, got, want), count in grouped.most_common():
            retail_names = addr2names.get(want) or ["?"]
            out.append(f"| {count} | `{sym}` | `0x{got:08x}` | `0x{want:08x}` | "
                       f"`{'`, `'.join(retail_names)}` |")
        out.append("")

    text = "\n".join(out) + "\n"
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(findings)} functions, {checked} relocations checked")
    else:
        print(text)


main()
