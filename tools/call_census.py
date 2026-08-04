"""Ordered call-target census: which functions we call that retail does not.

`tools/call_arity.py` reports that a function's call COUNT differs. This says
WHICH targets differ, which is the difference between a lead and a fix.

Both sides are read without compiling anything:

* ours    — the `R_MIPS_26` relocations already recorded per function in a
            `verify.py --json` report, ordered by offset.
* retail  — every `jal` in the function's retail window, decoded straight from
            the ELF (opcode 3; target = (word & 0x03ffffff) << 2, in the current
            256 MB segment).

Comparing the two ordered lists classifies each function:

    PHANTOM  we call a target retail never calls
    MISSING  retail calls a target we never call
    ORDER    same multiset of targets, different sequence
    CLEAN    identical

PHANTOM is the highest-yield class discovered so far. mdlEffect `0034cc00`
carried a phantom `FUN_00326030(*puVar7, color)` that was really a structure
assignment, `renderStack[0] = matrixStack[0];` — removing it took nd 161 to 1.
bp_root `001fd890` and gc_pose `0024dc90` each carried a phantom `K_Assert` the
original code did not have.

A phantom call is NOT licence to delete a statement. It says our source calls
something retail does not; the fix is to work out what the original wrote
instead, which is usually inline code, a different helper, or a macro that does
not expand to a call in the retail build.

    python tools/call_census.py --report build/baselines/W449_gate.json \\
        --out build/wip/callcensus.md [--kind PHANTOM] [--max-nd 4000]
"""
import argparse
import json
import re
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import REPO, RetailElf, load_config

TP_PRE = ("rw/", "cri/", "sce/", "lib/")
TP_F = {"crt0.c", "libc_core.c", "libcdvd.c"}
# `FUN_0040e3c0`, and the `#pragma alias` retype variants `FUN_0040e3c0_u32`,
# `FUN_00531230_typed`, `FUN_001b9120_u32` — all name the same retail address.
# `thunk_` is deliberately excluded: its digits are the address it JUMPS TO.
HEXNAME = re.compile(r"^(?:FUN|func|sub)_([0-9a-fA-F]{8})(?:_\w+)?$")


def is3(f):
    n = f.replace("\\", "/")
    if n.startswith("src/"):
        n = n[4:]
    return n in TP_F or n.startswith(TP_PRE)


def linked_elf_symbols(path=REPO / "build" / "slus21621.elf"):
    """name -> address from our own linked executable's symbol table.

    The build reproduces retail's sha1, so every symbol in it — including SDK
    and RenderWare entry points that no config table names — sits at its retail
    address. This is what turns `UNRESOLVED_SYMBOL` from 509 functions into a
    handful.
    """
    if not path.exists():
        return {}
    d = path.read_bytes()
    en = "<" if d[5] == 1 else ">"
    eh = struct.unpack_from(en + "HHIIIIIHHHHHH", d, 16)
    shoff, shentsize, shnum = eh[5], eh[10], eh[11]
    secs = [struct.unpack_from(en + "IIIIIIIIII", d, shoff + i * shentsize)
            for i in range(shnum)]
    out = {}
    for _nm, ty, _fl, _ad, off, sz, lnk, _inf, _al, ent in secs:
        if ty != 2 or not ent:                       # SHT_SYMTAB
            continue
        stroff = secs[lnk][4]
        for i in range(sz // ent):
            st_name, st_value, _sz, st_info, _o, st_shndx = \
                struct.unpack_from(en + "IIIBBH", d, off + i * ent)
            if st_shndx == 0 or (st_info & 0xF) != 2:   # undefined / not STT_FUNC
                continue
            end = d.index(b"\0", stroff + st_name)
            name = d[stroff + st_name:end].decode("ascii", "replace")
            if name:
                out.setdefault(name, st_value)
    return out


def load_symbols(rows):
    """name -> address, from the linked ELF, the config tables and the gate."""
    m = dict(linked_elf_symbols())
    for rel in ("config/symbol_addrs.txt", "config/symbols_recovered.txt"):
        p = REPO / rel
        if not p.exists():
            continue
        for line in p.read_text(errors="replace").splitlines():
            mm = re.match(r"\s*([A-Za-z_$][\w$]*)\s*=\s*(?:0x)?([0-9a-fA-F]+)", line)
            if mm:
                m.setdefault(mm.group(1), int(mm.group(2), 16))
    for r in rows:
        m.setdefault(r["name"], int(r["addr"], 16))
    return m


def retail_calls(elf, addr, window):
    """Ordered j/jal targets in the retail window.

    Opcode 2 (`j`) counts as well as opcode 3 (`jal`): an `R_MIPS_26`
    relocation on our side covers both, and an 8-byte thunk tail-jumps with
    `j`. Counting only `jal` reported three MATCH thunks as phantoms.
    """
    data = elf.bytes_at(addr, window)
    out = []
    for i in range(0, len(data) - 3, 4):
        w = struct.unpack_from("<I", data, i)[0]
        if (w >> 26) in (2, 3):
            pc = addr + i
            out.append(((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2))
    return out


def our_calls(row, syms):
    """Ordered R_MIPS_26 targets from the recorded relocations.

    Returns (targets, unresolved). A `thunk_` name encodes the address the thunk
    JUMPS TO, never its own, so it is only ever resolved through the symbol
    table — never by parsing its digits.
    """
    out, unresolved = [], 0
    for rel in sorted(row.get("relocations") or [], key=lambda r: r["offset"]):
        if rel.get("type") != "R_MIPS_26":
            continue
        name = rel["symbol"]
        if name in syms:
            out.append(syms[name])
            continue
        m = HEXNAME.match(name)
        if m:
            out.append(int(m.group(1), 16))
        else:
            unresolved += 1
            out.append(None)
    return out, unresolved


def addressed_symbols(row, syms):
    """Addresses our object MATERIALISES rather than calls.

    A `HI16`/`LO16` pair on a function symbol means we load its address and
    reach it with `jalr`, where retail emits a direct `jal`. The census sees
    only the missing `R_MIPS_26` and calls that `MISSING`, which is wrong: the
    call is present, the DECLARATION is. frFont `FUN_003b1360` was misread that
    way for a whole wave — both sides prepare identical arguments at offsets
    340/344/348/352, then retail emits `jal 003b0f50` at 364 while we
    materialise the address at 356/360 and `jalr` at 364.
    """
    out = set()
    for rel in row.get("relocations") or []:
        if rel.get("type") == "R_MIPS_26":
            continue
        rec = rel.get("symbol_record") or {}
        if rec.get("sym_type") != 2:            # STT_FUNC only
            continue
        name = rel["symbol"]
        if name in syms:
            out.add(syms[name])
        else:
            m = HEXNAME.match(name)
            if m:
                out.add(int(m.group(1), 16))
    return out


def classify(ours, retail, addressed):
    co, cr = Counter(x for x in ours if x is not None), Counter(retail)
    phantom = co - cr
    missing = cr - co
    # A "missing" target whose address we materialise is not missing at all:
    # we call it through a pointer where retail calls it by name. That is a
    # declaration defect, and a different fix from supplying an absent call.
    indirect = Counter({t: c for t, c in missing.items() if t in addressed})
    if indirect and len(indirect) == len(missing) and not phantom:
        return "INDIRECT", phantom, indirect
    if phantom or missing:
        return ("PHANTOM" if phantom else "MISSING"), phantom, missing
    if [x for x in ours if x is not None] != retail:
        return "ORDER", phantom, missing
    return "CLEAN", phantom, missing


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--report", required=True)
    ap.add_argument("--out")
    ap.add_argument("--kind", help="only report this class")
    ap.add_argument("--max-nd", type=int, default=10 ** 9)
    ap.add_argument("--status", default="NONMATCHING")
    args = ap.parse_args()

    cfg = load_config()
    elf = RetailElf(cfg["retail_elf"])
    rows = json.loads(Path(args.report).read_text())["results"]
    syms = load_symbols(rows)
    # `thunk_` stubs tail-jump; retail encodes that jump PC-relative as `b`,
    # which carries no R_MIPS_26 target to compare against. Three already-MATCH
    # thunks reported as phantoms before this exclusion.
    sel = [r for r in rows if not is3(r["file"]) and r["status"] == args.status
           and (r.get("normalized_diff") or 0) <= args.max_nd
           and r.get("window") and not r["name"].startswith("thunk_")]

    totals = Counter()
    found = []
    for r in sel:
        ours, unresolved = our_calls(r, syms)
        if unresolved:
            totals["UNRESOLVED_SYMBOL"] += 1
            continue
        rc = retail_calls(elf, int(r["addr"], 16), r["window"])
        kind, phantom, missing = classify(ours, rc, addressed_symbols(r, syms))
        totals[kind] += 1
        if kind != "CLEAN" and (not args.kind or kind == args.kind):
            found.append((r, kind, phantom, missing, len(ours), len(rc)))

    found.sort(key=lambda f: (sum((f[2] + f[3]).values()),
                              f[0].get("normalized_diff") or 0))

    L = ["# Ordered call-target census", ""]
    L.append("`PHANTOM` = we call a target retail never calls. That is the "
             "highest-yield class found so far: mdlEffect `0034cc00` carried a "
             "phantom call that was really a structure assignment (nd 161 -> 1), "
             "and bp_root `001fd890` and gc_pose `0024dc90` each carried a "
             "phantom `K_Assert`.")
    L.append("")
    L.append("A phantom call is not licence to delete a statement. It says our "
             "source calls something retail does not; find what the original "
             "wrote instead.")
    L.append("")
    for k, v in totals.most_common():
        L.append(f"- {k} {v}")
    L.append("")
    for r, kind, phantom, missing, no, nr in found:
        L.append(f"## {r['addr']} `{r['name']}` — {kind} — nd "
                 f"{r['normalized_diff']} — {r['file'].replace(chr(92), '/')}")
        L.append("")
        L.append(f"calls: ours {no}, retail {nr} · object {r.get('object_size')}"
                 f"/window {r.get('window')}")
        L.append("")
        if phantom:
            L.append("**phantom (ours only):** " +
                     ", ".join(f"`{t:08x}`×{c}" if c > 1 else f"`{t:08x}`"
                               for t, c in sorted(phantom.items())))
            L.append("")
        if missing and kind == "INDIRECT":
            L.append("**called through a pointer (retail calls by name):** " +
                     ", ".join(f"`{t:08x}`×{c}" if c > 1 else f"`{t:08x}`"
                               for t, c in sorted(missing.items())))
            L.append("")
            L.append("Our object materialises this address and reaches it with "
                     "`jalr`. Fix the DECLARATION so the callee is an ordinary "
                     "prototyped function at the call site, not the call.")
            L.append("")
        elif missing:
            L.append("**missing (retail only):** " +
                     ", ".join(f"`{t:08x}`×{c}" if c > 1 else f"`{t:08x}`"
                               for t, c in sorted(missing.items())))
            L.append("")
        if kind == "ORDER":
            for i, (a, b) in enumerate(zip(ours_of := [x for x in
                                           our_calls(r, syms)[0]], retail_calls(
                                           elf, int(r["addr"], 16), r["window"]))):
                if a != b:
                    L.append(f"first divergence at ordered index {i}: "
                             f"ours `{a:08x}`, retail `{b:08x}`")
                    L.append("")
                    break

    text = "\n".join(L) + "\n"
    for k, v in totals.most_common():
        print(f"{k:20s} {v}")
    if args.out:
        Path(args.out).write_text(text, newline="\n")
        print(f"wrote {args.out}: {len(found)} functions")
    else:
        print(text)


main()
