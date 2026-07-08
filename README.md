# Persona 3 FES

A work-in-progress matching decompilation of **Shin Megami Tensei: Persona 3 FES**
(USA, `SLUS_216.21`) for the Sony PlayStation 2.

This repo splits the retail executable into assembly and data with
[splat](https://github.com/ethteck/splat) and rebuilds a **byte-identical**
program image using the game's original **CodeWarrior for PlayStation 2**
toolchain. Functions are decompiled to C one at a time; each is verified to
assemble back to the exact retail bytes.

> This project needs a copy of the game you legally own. No copyrighted data
> (the ELF or any extracted bytes) is included in this repository.

## Status

| Artifact | State |
| --- | --- |
| Full retail ELF, rebuilt from split sources (`make` → `build/SLUS_216.21`) | **byte-identical** to retail (SHA-1 `3929cd7c…`) |
| Functions in the executable | 13,407 |
| Function map (`config/symbol_addrs.txt`) | complete |
| Decompiled to matching C | ongoing (see `make verify`) |

`make` disassembles, reassembles, and links the whole image with the original
toolchain, splices it into the retail ELF wrapper, and checks the result is
byte-for-byte identical to retail. Decompilation replaces the assembly with C
function by function, each verified against retail.

## Target

- `SLUS_216.21`, SHA-1 `3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb`.
- Single loadable segment at VRAM `0x100000` (`0x8acc80` bytes, ~8.7 MiB of
  code + data) plus BSS at `0x9acc80`. The retail ELF is stripped (no symbol
  table). Machine is the MIPS **R5900** Emotion Engine (little-endian). Note the
  R5900 omits the 64-bit `ddiv`/`ddivu` instructions, so any such disassembly is
  really data.
- The `.comment` section reads `MW MIPS C Compiler (2.4.1.01)`, but that string
  ships in MWLD across many CodeWarrior releases. Codegen evidence (far-global
  addressing bakes the symbol+offset into the hi16/lo16 relocs using an
  allocated register, not the `$at` form of 3.0/earlier) pins the compiler to
  the **3.0.1** line, build 198+ . This project builds with
  `mwcps2-3.0.1b210-060308` at `-O2`.

## Prerequisites

- **Python 3.8+** and splat: `pip install splat64`
- The **CodeWarrior PS2** toolchain `mwcps2-3.0.1b210-060308`
  (`mwccps2.exe`, `asm_r5900_elf.exe`, `mwldps2.exe`). Windows-native, or run
  the whole flow under Wine.
- Your own retail `SLUS_216.21`.

FLEXlm note: the 3.0.1 toolchain wants `LMGR326B.DLL` from the older
`mwcps2-3.0b52` release copied over **both** `LMGR326B.DLL` and `LMGR8C.DLL` in
the toolchain directory.

## Quick start

```sh
# 1. tell the tools where your compiler and retail ELF live (gitignored)
cat > tools/verify_config.local.json <<'JSON'
{ "mwcc": "D:/mwcps2-3.0.1b210-060308/mwccps2.exe",
  "retail_elf": "C:/path/to/SLUS_216.21" }
JSON

# 2. extract the loadable image from your ELF
make setup

# 3. split it into asm/ + data (run once, or after a config change)
make split

# 4. assemble + link, splice into the ELF wrapper, verify byte-identical,
#    then check every decompiled C function matches
make

# just the per-function C match report
make verify
```

A successful `make` prints (and writes the runnable ELF to `build/SLUS_216.21`):

```
loadable image sha1: 9203646d9aa48ff24eb4ba4b328b02df468a9483  OK
SLUS_216.21 sha1:    3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb  OK
```

## How the matching build works

```
retail SLUS_216.21 ──extract──▶ image.bin  (loadable payload, VRAM 0x100000)
        │
   splat split (config/slus21621.yaml, numeric registers)
        ▼
   asm/code1.s asm/code2.s  +  data ranges
        │  tools/desym.py     (%hi/%lo → literals, jal sym → jal 0xADDR,
        │                       div/mult 3-op → 2-op, `not` → explicit `nor`)
        ▼
   tools/asm.py  (asm_r5900_elf -gnu): assembles, and rewrites any line the
        │        assembler rejects or that differs from retail into a .word/.byte
        │        of its original bytes — this is how data-as-code becomes data
        ▼
   *.o  ──mwldps2 + build/slus21621.lcf──▶ linked loadable image
        │  tools/link_c.py: overlay compiled C for matched functions
        ▼
   splice into the retail ELF wrapper ──▶ build/SLUS_216.21
        ▼
   verify: whole-file SHA-1 == retail (3929cd7c…)
```

`tools/build.py` drives the whole pipeline; `make` is a thin wrapper over it.

Decompiled C is linked into the image. Because the retail ELF is stripped,
`tools/link_c.py` first *recovers* a symbol table: every relocation in an
already-matching function, read against the retail bytes, gives the resolved
value of the symbol it references (a callee, a global, a gp-relative offset).
Each matched function's compiled-C relocations are then re-encoded from that
map and written over its region of the image — so the linked bytes come from
your C, not the disassembly. Today 726 of 739 matched functions link cleanly
this way; a handful with a shared-`%hi`/multiple-`%lo` pattern still fall back
to the assembly baseline, so the image is byte-identical either way.

`tools/verify.py` remains the per-function gate (`make verify`): it compiles
each `src/` file and byte-compares every `// FUN_xxxxxxxx` function against
retail (relocated fields masked, tail padding checked).

## Contributing

New here? See **[CONTRIBUTING.md](CONTRIBUTING.md)**. Working with an AI agent?
See **[AGENTS.md](AGENTS.md)**. Naming conventions live in
[`docs/prefixes.md`](docs/prefixes.md).

The short version: pick an unmapped `func_XXXXXXXX`, write C for it with a
`// FUN_XXXXXXXX` marker and a header prototype, then iterate with

```sh
python tools/fndiff.py src/path/file.c yourFunction   # 0 diffs == match
python tools/verify.py src/path/file.c
```

## Layout

```
config/     splat config + symbol map (symbol_addrs.txt)
tools/      build.py, desym.py, asm.py, verify.py, fndiff.py
asm/        macro.inc (committed); *.s / *.o are generated (gitignored)
src/        decompiled C
include/     headers
build/      build outputs (gitignored)
```
