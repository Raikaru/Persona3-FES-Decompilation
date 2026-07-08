# Persona 3 FES

A work-in-progress matching decompilation of **Shin Megami Tensei: Persona 3 FES**
(USA, `SLUS_216.21`) for the Sony PlayStation 2.

This repo splits the retail executable into assembly and data with
[splat](https://github.com/ethteck/splat), assembles the generated R5900 GAS
with GNU `mipsel-linux-gnu-as`, and links a **byte-identical** program image
with the game's original CodeWarrior PS2 linker. Functions are decompiled to C
one at a time; each is verified against the exact retail bytes.

> This project needs a copy of the game you legally own. No copyrighted data
> (the ELF or any extracted bytes) is included in this repository.

## Status

| Artifact | State |
| --- | --- |
| Full retail ELF, rebuilt from split sources (`make` → `build/SLUS_216.21`) | **byte-identical** to retail (SHA-1 `3929cd7c…`) |
| Functions in the executable | 13,407 |
| Function map (`config/symbol_addrs.txt`) | complete |
| Decompiled to matching C | ongoing (see `make verify`) |

`make` assembles the splat output with GNU R5900 binutils, links the whole image
with mwldps2, splices it into the retail ELF wrapper, and checks the result is
byte-for-byte identical to retail. Decompilation replaces assembly with C
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
  (`mwccps2.exe`, `mwldps2.exe`). Windows-native, or run under Wine/wibo.
- GNU MIPS little-endian binutils with R5900 support:
  `mipsel-linux-gnu-as` and `mipsel-linux-gnu-objcopy`
  (Debian/WSL package: `binutils-mipsel-linux-gnu`).
- Your own retail `SLUS_216.21`.


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
        │
        ├─ decompiled TUs ─ src/*.c ─ tools/mwccgap ─▶ C objects
        │      (mwccps2 compiles C; GNU as assembles any INCLUDE_ASM;
        │       the retail range is carved out of the asm baseline)
        │
        └─ everything else ─ tools/asm.py ─▶ asm objects
               mipsel-linux-gnu-as -march=r5900 -mabi=eabi
               - keeps real %hi/%lo/jal relocations for mwldps2
               - rewrites data-disguised-as-code to .word from retail bytes
        ▼
   all objects ──mwldps2 + generated build/slus21621.lcf──▶ loadable image
        │      the LCF defines _gp and data-symbol addresses recovered from
        │      matched relocations (config/symbols_recovered.txt) plus splat's
        │      undefined_syms_auto.txt / undefined_funcs_auto.txt
        ▼
   splice into the retail ELF wrapper ──▶ build/SLUS_216.21
        ▼
   verify: whole-file SHA-1 == retail (3929cd7c…)
```

`tools/build.py` drives the whole pipeline; `make` is a thin wrapper over it.

Decompiled files link as **real C objects** the standard mwcc way (`mwccgap` +
`mwldps2`), not via a post-link byte overlay. Because the retail ELF is
stripped, `tools/recover_symbols.py` bootstraps the symbol table: it reads each
matched function's relocations against retail, backs out the addend, and keeps
only cross-file-consistent symbol addresses (`make symbols` →
`config/symbols_recovered.txt`, plus `_gp` from the ELF `.reginfo`). The build
automatically links every fully-decompiled, contiguous TU whose owned data
sections can be placed byte-exact — `.rodata`/`.data`/`.sdata` at their recovered
addresses (carved out of the data blob) and `.sbss`/`.bss` as zero-filled
PROGBITS. A file stays on the asm baseline only when a data symbol's address
can't be recovered, a reloc target is unresolvable, or a function is WIP. The
image is byte-identical either way.

`tools/verify.py` is the per-function gate (`make verify`): it compiles each
`src/` file and byte-compares every `// FUN_xxxxxxxx` function against retail
(relocated fields masked, tail padding checked).

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

Helper tools / targets:

```sh
make progress                 # matched-function / byte progress report
make ctx FILE=src/…/foo.c     # flatten includes -> ctx.c for decomp.me
make symbols                  # regenerate config/symbols_recovered.txt
make objdiff                  # regenerate objdiff.json + target/base objects
make format                   # clang-format the C sources
./diff.py -o <func>           # asm-differ (see diff_settings.py)
```
`objdiff.json`, `diff_settings.py`, `permuter_settings.toml`, the `Dockerfile`,
and CI (`.github/workflows/ci.yml`) follow the standard mwcc/PS2 decomp layout.

## Layout

```
config/     splat config, symbol_addrs.txt, generated symbols_recovered.txt
tools/      build.py, asm.py, verify.py, fndiff.py, recover_symbols.py,
            m2ctx.py, progress.py, gen_objdiff.py, vendored mwccgap/
asm/        macro.inc (committed); *.s / *.o / chunks are generated (gitignored)
src/        decompiled C
include/    headers (include_asm.h defines INCLUDE_ASM/INCLUDE_RODATA)
build/      build outputs, objects, objdiff inputs (gitignored)
```
