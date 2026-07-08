#!/usr/bin/env python3
"""Assemble splat/desym'd asm with the CodeWarrior EE assembler (asm_r5900_elf
-gnu) and guarantee byte-exact output.

Two self-correcting passes replace mis-disassembled *data* with `.byte`:
  1. error-driven  - any line the assembler rejects (e.g. R5900-illegal
     ddiv/ddivu) becomes `.byte` from the raw bytes in splat's line comment.
  2. reference-driven (optional) - if a reference image + vram base is given,
     the assembled .text is compared to the original and any differing word's
     source line is rewritten to `.byte` (catches data that happens to decode
     as a valid but wrong instruction, e.g. branch/jump tables).

Real R5900 code assembles directly; only data-as-code falls back to `.byte`.

usage: asm.py <in.s> <out.o> [reference.bin <vram_base_hex> <vram_lo_hex>]
"""
import json, os, re, struct, subprocess, sys, tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
BYTES_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})")
ERR_RE = re.compile(r"Line (\d+) # (?:Error|Fatal error)")


def find_asm():
    for name in ("verify_config.local.json", "verify_config.json"):
        p = REPO / "tools" / name
        if p.is_file():
            cfg = json.loads(p.read_text())
            if cfg.get("mwcc"):
                cand = Path(cfg["mwcc"]).with_name("asm_r5900_elf.exe")
                if cand.is_file():
                    return str(cand)
    if os.environ.get("P3_MWCC"):
        cand = Path(os.environ["P3_MWCC"]).with_name("asm_r5900_elf.exe")
        if cand.is_file():
            return str(cand)
    sys.exit("asm: could not locate asm_r5900_elf.exe next to mwcc")


def byte_line(line):
    """Rewrite an instruction line to a .word directive from its comment bytes.
    Idempotent: already-converted (.word/.byte) lines are left untouched."""
    s = line.lstrip()
    if s.startswith(".word") or s.startswith(".byte"):
        return None
    m = BYTES_RE.search(line)
    if not m:
        return None
    vram, hx = m.group(1), m.group(2)
    word = int(hx[6:8] + hx[4:6] + hx[2:4] + hx[0:2], 16)  # file bytes -> LE word
    indent = line[:len(line) - len(s)]
    return f"{indent}.word 0x{word:08X}  /* {vram}: data */\n"


def _run(asm_exe, lines, out_path):
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False,
                                     dir=str(Path(out_path).parent)) as tf:
        tf.writelines(lines)
        tmp = tf.name
    proc = subprocess.run([asm_exe, "-gnu", "-endian", "little", "-o", out_path, tmp],
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    os.unlink(tmp)
    return proc.stdout


def _text_section(path):
    d = Path(path).read_bytes()
    phoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shx = struct.unpack_from("<HHH", d, 0x2e)
    tab = [struct.unpack_from("<IIIIII", d, phoff + i * she) for i in range(shn)]
    sto = tab[shx][4]

    def nm(n):
        e = d.find(b"\0", sto + n)
        return d[sto + n:e].decode()
    for t in tab:
        if nm(t[0]) == ".text":
            return d[t[4]:t[4] + t[5]]
    return b""


def assemble(src_path, out_path, asm_exe, ref=None, vram=0, ref_lo=0):
    lines = Path(src_path).read_text().splitlines(keepends=True)
    # pass 1: error-driven
    for _ in range(64):
        out = _run(asm_exe, lines, out_path)
        bad = sorted({int(m.group(1)) for m in ERR_RE.finditer(out)})
        if not bad:
            break
        changed = False
        for ln in bad:
            i = ln - 1
            if 0 <= i < len(lines):
                repl = byte_line(lines[i])
                if repl and repl != lines[i]:
                    lines[i] = repl
                    changed = True
        if not changed:
            return False, out, lines
    # pass 2: reference-driven
    if ref is not None:
        addr_line = {}
        for idx, l in enumerate(lines):
            m = BYTES_RE.search(l)
            if m and "vram" not in l:
                addr_line[int(m.group(1), 16)] = idx
        for _ in range(64):
            text = _text_section(out_path)
            orig = ref[ref_lo:ref_lo + len(text)]
            diff_words = sorted({(i // 4) * 4 for i in range(min(len(text), len(orig)))
                                 if text[i] != orig[i]})
            if not diff_words:
                break
            changed = False
            for wo in diff_words:
                a = vram + wo
                idx = addr_line.get(a)
                if idx is not None:
                    repl = byte_line(lines[idx])
                    if repl and repl != lines[idx]:
                        lines[idx] = repl
                        changed = True
            if not changed:
                return False, f"unresolved diffs at {[hex(vram+w) for w in diff_words[:8]]}", lines
            _run(asm_exe, lines, out_path)
        _run(asm_exe, lines, out_path)
    return True, "", lines


if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.exit("usage: asm.py <in.s> <out.o> [reference.bin vram_base_hex vram_lo_hex]")
    ref = vram = lo = None
    if len(sys.argv) >= 6:
        ref = Path(sys.argv[3]).read_bytes()
        vram = int(sys.argv[4], 16)
        lo = int(sys.argv[5], 16)
    ok, log, lines = assemble(sys.argv[1], sys.argv[2], find_asm(),
                              ref=ref, vram=vram or 0, ref_lo=lo or 0)
    # persist any .byte fixups back to the source so the tree stays reproducible
    Path(sys.argv[1]).write_text("".join(lines))
    if not ok:
        sys.stderr.write(log + "\n")
        sys.exit(1)
