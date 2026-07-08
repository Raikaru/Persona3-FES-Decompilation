#!/usr/bin/env python3
"""Link decompiled C into the image.

The retail ELF is stripped, so there is no symbol table to link against. This
module recovers one: every relocation in an already-matching C function, read
against the retail bytes, yields the resolved value of the symbol it references
(a called function's address, a global's address, a gp-relative offset). Those
values are aggregated into a symbol map, which is then used to re-encode the
relocations in each decompiled function's *compiled C* and overlay the result
into the loadable image.

For a matched function this reproduces the retail bytes exactly, but the bytes
now come from compiled C resolved through a recovered symbol table -- real
C-in-link, not a copy of the disassembly. A function whose C does not fully
reconstruct retail (encoding or a still-unknown symbol) is reported and left to
the assembly baseline.

Reloc types handled: R_MIPS_26, R_MIPS_HI16/LO16 (paired), R_MIPS_GPREL16.
"""
import struct


def s16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


def _w(buf, off):
    return struct.unpack_from("<I", buf, off)[0]


def recover_symbols(functions):
    """functions: iterable of (addr, c_body, rels, retail_win).
    Returns (symmap, conflicts) where symmap[name] = recovered value."""
    symmap, conflicts = {}, {}

    def record(name, val):
        if name is None:
            return
        if name in symmap and symmap[name] != val:
            conflicts.setdefault(name, {symmap[name]}).add(val)
        else:
            symmap[name] = val

    for addr, body, rels, win in functions:
        pend_hi = []  # (name, c_word, retail_word)
        for r in rels:
            o = r["offset"]
            if o + 4 > len(body) or o + 4 > len(win):
                continue
            wc, wr = _w(body, o), _w(win, o)
            t = r["r_type"]
            if t == 4:  # R_MIPS_26
                addend = (wc & 0x03FFFFFF) << 2
                target = ((wr & 0x03FFFFFF) << 2) | ((addr + o) & 0xF0000000)
                record(r["symbol"], target - addend)
            elif t == 5:  # HI16 (resolve when its LO16 arrives)
                pend_hi.append((r["symbol"], wc, wr))
            elif t == 6:  # LO16
                lo_ad, lo_r = s16(wc), s16(wr)
                still = []
                for (nm, wch, wrh) in pend_hi:
                    if nm == r["symbol"]:
                        ahl = ((wch & 0xFFFF) << 16) + lo_ad
                        rv = ((wrh & 0xFFFF) << 16) + lo_r
                        record(nm, rv - ahl)
                    else:
                        still.append((nm, wch, wrh))
                pend_hi = still
                # the LO16 alone also encodes value = sym + AHL; its own addend
                # is lo_ad, paired hi addend already used above -- nothing extra.
            elif t == 7:  # GPREL16 (value is sym - gp)
                record(r["symbol"], s16(wr) - s16(wc))
    return symmap, conflicts


def resolve_function(addr, body, rels, symmap):
    """Re-encode body's relocations from symmap. Returns (bytes, missing set)."""
    out = bytearray(body)
    missing = set()
    pend_hi = []  # (offset, symbol)
    for r in rels:
        o, t, nm = r["offset"], r["r_type"], r["symbol"]
        if nm not in symmap:
            missing.add(nm)
            continue
        val = symmap[nm]
        w = _w(out, o)
        if t == 4:
            addend = (w & 0x03FFFFFF) << 2
            tgt = val + addend
            w = (w & 0xFC000000) | ((tgt >> 2) & 0x03FFFFFF)
            struct.pack_into("<I", out, o, w)
        elif t == 5:
            pend_hi.append((o, nm))
        elif t == 6:
            lo_ad = s16(w)
            for (ho, hnm) in [p for p in pend_hi if p[1] == nm]:
                hw = _w(out, ho)
                value = val + (((hw & 0xFFFF) << 16) + lo_ad)
                hw = (hw & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
                struct.pack_into("<I", out, ho, hw)
            pend_hi = [p for p in pend_hi if p[1] != nm]
            value = val + lo_ad  # AHL for a bare lo; hi addend folded above
            w = (w & 0xFFFF0000) | (value & 0xFFFF)
            struct.pack_into("<I", out, o, w)
        elif t == 7:
            w = (w & 0xFFFF0000) | ((val + s16(w)) & 0xFFFF)
            struct.pack_into("<I", out, o, w)
    return bytes(out), missing
