#!/usr/bin/env python3
"""Rewrite splat GAS asm into raw-immediate asm the CodeWarrior EE assembler
(asm_r5900_elf -gnu) accepts, and that reassembles byte-exact without needing
link-time symbol resolution.

  %hi(SYM [+ off]) -> 0xHHHH
  %lo(SYM [+ off]) -> signed lo16
  jal/j SYM [+ off] -> jal/j 0xADDR
  div/divu/mult/multu $0, rs, rt -> 2-operand form (CW syntax)

Symbol addresses come from the name itself (func_ADDR / D_ADDR / jtbl_ADDR) or,
for named functions/data, from config/symbol_addrs.txt.  The R5900 lacks the
64-bit ddiv/ddivu instructions, so any such disassembled "instruction" is data;
those are handled by the assembler wrapper (tools/asm.py) as .byte fallbacks.
"""
import re, sys
from pathlib import Path

SYM = r"[A-Za-z_.][A-Za-z0-9_.]*"
ADD = r"(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?"
_NAMED = {}


def load_syms():
    p = Path(__file__).resolve().parents[1] / "config" / "symbol_addrs.txt"
    if p.is_file():
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.][\w.]*)\s*=\s*(0x[0-9A-Fa-f]+)", line)
            if m:
                _NAMED[m.group(1)] = int(m.group(2), 16)


def sym_addr(name):
    if name in _NAMED:
        return _NAMED[name]
    m = re.match(r"(?:func|D|jtbl|jpt)_([0-9A-Fa-f]+)$", name)
    return int(m.group(1), 16) if m else None


def hi16(a):
    return ((a + 0x8000) >> 16) & 0xFFFF


def lo16(a):
    v = a & 0xFFFF
    return v - 0x10000 if v >= 0x8000 else v


def _resolve(m):
    a = sym_addr(m.group(1))
    if a is None:
        return None
    if m.group(2):
        a += int(m.group(2), 0)
    return a


def conv(line):
    def hi(m):
        a = _resolve(m)
        return f"0x{hi16(a):X}" if a is not None else m.group(0)

    def lo(m):
        a = _resolve(m)
        if a is None:
            return m.group(0)
        v = lo16(a)
        return f"-0x{-v:X}" if v < 0 else f"0x{v:X}"

    line = re.sub(r"%hi\((" + SYM + r")" + ADD + r"\)", hi, line)
    line = re.sub(r"%lo\((" + SYM + r")" + ADD + r"\)", lo, line)

    def jal(m):
        a = sym_addr(m.group(2))
        if a is None:
            return m.group(0)
        if m.group(3):
            a += int(m.group(3), 0)
        return f"{m.group(1)} 0x{a:X}"

    line = re.sub(r"\b(jal|j)\s+(" + SYM + r")" + ADD + r"\b", jal, line)

    line = re.sub(r"\b(div|divu|mult|multu)\s+\$0,\s*(\$\d+),\s*(\$\d+)",
                  r"\1 \2, \3", line)
    # `not rd, rs` pseudo: original encodes nor rd, rs, $0 (CW swaps to nor rd,$0,rs)
    line = re.sub(r"\bnot\s+(\$\d+),\s*(\$\d+)", r"nor \1, \2, $0", line)
    return line


if __name__ == "__main__":
    load_syms()
    data = sys.stdin.read() if len(sys.argv) < 2 else open(sys.argv[1]).read()
    sys.stdout.write("".join(conv(l) for l in data.splitlines(keepends=True)))
