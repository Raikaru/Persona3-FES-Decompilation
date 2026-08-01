# Contributing

This repository is a matching decompilation of Persona 3 FES (USA), retail ELF `SLUS_216.21`, for the PlayStation 2 Emotion Engine. Read the [README](README.md) for project scope and its legal notice before obtaining game files.

## Prerequisites

### CodeWarrior PS2 toolchain

Install the original CodeWarrior PS2 suite locally. It is not stored in this repository.

Required version and programs:

```text
mwcps2-3.0.1b210-060308
mwccps2.exe
mwldps2.exe
```

C files use these compiler flags:

```text
-O2 -Iinclude
```

### FLEXlm DLL

The 3.0.1 toolchain needs a FLEXlm DLL workaround. Obtain `LMGR326B.DLL` from the decomp.dev GameCube compilers; copy it into the 3.0.1 toolchain directory twice, as both destination names:

```text
LMGR326B.DLL
LMGR8C.DLL
```

### GNU binutils and Python

Install GNU MIPS little-endian binutils with R5900 support:

```text
mipsel-linux-gnu-as
mipsel-linux-gnu-objcopy
```

On Debian or WSL, install `binutils-mipsel-linux-gnu`. Install Python and `splat64` (which provides `spimdisasm` and `rabbitizer`):

```sh
pip install splat64
```

The R5900 does not have 64-bit `ddiv` or `ddivu` instructions. Treat apparent instances in disassembly as data, not executable code.

## Retail executable

Bring your own retail `SLUS_216.21`. It is copyrighted and must not be committed. The retail ELF and extracted `image.bin` are gitignored.

The NTSC-U executable has this SHA-1 and size:

```text
SHA-1: 3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb
Size:  9,096,860 bytes
```

## Local setup

Create the machine-local verification config at `tools/verify_config.local.json`:

```json
{
  "mwcc": "<path>/mwccps2.exe",
  "retail_elf": "<path>/SLUS_216.21"
}
```

The file is gitignored. You may provide the same paths with `P3_MWCC` and `P3_RETAIL_ELF` environment variables.

Extract the loadable image and generate assembly/data with:

```sh
make setup
make split
```

`make split` runs `python -m splat split config/slus21621.yaml` and generates files including `asm/code1.s` and `asm/code2.s`.

## Build and per-function verification

Build and link the current image:

```sh
make
```

A successful `make` proves that the final loadable image is byte-identical to retail. It does not prove that a particular function's C produced those bytes. Use `tools/verify.py` for that per-function claim.

Run the complete per-function report (`make check` is an alias):

```sh
make verify
# or: python tools/verify.py
```

Check one file, show differences, or write JSON:

```sh
python tools/verify.py src/rw/rprandom.c
python tools/verify.py --show-mismatches
python tools/verify.py --json report.json
```

`tools/verify.py` compiles marked functions, compares their bytes with retail, masks relocation fields, and checks padding up to the next retail function entry.

| Status | Meaning |
| --- | --- |
| `MATCH` | Compiled bytes match retail and the function-range padding is valid. |
| `NONMATCHING` | Useful implementation intentionally marked while its bytes still differ. |
| `STUB` | Marker identifies a placeholder body, normally containing `// TODO`. |
| `SIZE_MISMATCH` | Compiled bytes do not occupy the same size as the retail function range. |

Only `MATCH` is a byte-match claim. Fix verifier errors before submitting a change.

## Matching workflow

1. **Select an unmapped function.** Start with a `func_XXXXXXXX` in `asm/` or inspect the retail code in Ghidra. `XXXXXXXX` is the retail address.

2. **Write the C implementation.** Use the appropriate file under `src/` and add its prototype to the matching header under `include/`. Follow an existing nearby file when one shows the required pattern.

3. **Add the function marker.** Put it immediately above the definition, with no intervening comment:

   ```c
   // FUN_XXXXXXXX
   ReturnType functionName(...)
   {
       ...
   }
   ```

   Use the retail address in hexadecimal. For useful C that is not byte-exact yet, put `NONMATCHING` on the same marker line:

   ```c
   // FUN_XXXXXXXX NONMATCHING
   ```

   Do not claim a match or remove `NONMATCHING` until `tools/verify.py` reports `MATCH` for that function.

4. **Compare against retail.**

   ```sh
   python tools/fndiff.py src/path/file.c functionName
   ```

   `differing words (reloc-masked): 0` means the relocation-masked body words agree. Padding after the retail function range can produce a small count; if there are no `!` lines in the body, the body is clean.

5. **Run the per-file check.**

   ```sh
   python tools/verify.py src/path/file.c
   ```

   Keep iterating until the function reports `MATCH`. Do not edit a function that already matches.

**Grep before writing a new module file.** Search for an existing home
(`git ls-files '*name*'`, then grep for the addresses) before creating one. A
made-up directory causes duplicate definitions; an existing file whose name
matches the subsystem is the safe place to put the function.

## m2c first-pass workflow

Use `m2c` to turn a retail assembly function into a typed control-flow draft before hand decompilation. The project pins a known m2c revision and supplies the PS2/MWCC target, an isolated function assembly file, and declarations from the function's translation unit:

```sh
make m2c-setup
make m2c FILE=src/Battle/btlVoice.c FUNC=func_002e3d50
```

The generated draft, assembly slice, and context are written under `build/m2c/`. Add `STACK=1` to emit m2c's inferred stack-structure template:

```sh
make m2c FILE=src/Battle/btlVoice.c FUNC=func_002e3d50 STACK=1
```

`M2C=/path/to/m2c.py` can override the pinned local installation. Treat m2c output as evidence, not finished source: recover semantic names and project types, compare every call and condition with retail assembly, and remove decompiler casts and gotos when clean C expresses the same behavior. Only `tools/verify.py` establishes a match.

## Permuter usage

When clean C is semantically correct but differs in register assignment, scheduling, operand order, or evaluation order, use:

```sh
python tools/permute.py src/path/file.c functionName --time 60
```

It mutates only the target function's source text, recompiles with project flags, and scores each candidate with relocation-masked verification. On a hit, read the diff, apply the useful change by hand, remove `NONMATCHING`, and rerun `tools/verify.py`. A byte match from the permuter does not prove source semantics.

For source changes outside text mutation, use the AST randomizer:

```sh
python tools/permute_ast.py src/Battle/btlMain.c btlMainUpdateStateLose --time 120
```

It needs WSL Debian with `cpp` and Python packages `pycparser`, `attrs`, and `toml`; its first run clones the upstream decomp-permuter into gitignored `tools/decomp-permuter`. Treat heavily mutated output as a lead, write clean C, and confirm it with `tools/verify.py`. A batch run is available when needed:

```sh
python tools/permute_sweep.py --time 30
```

## Code style and assembly clues

Use project types, macros, and naming conventions from nearby source files. Keep decompiled C readable and remove casts or gotos introduced only by a decompiler when ordinary C expresses the same behavior.

Use retail assembly to recover type and control-flow intent:

- `lb` and `lh` are signed loads; `lbu` and `lhu` are unsigned loads.
- `div` and `slt` are signed; `divu` and `sltu` are unsigned.
- `bgez`, `bltz`, and `blez` expose signed branch conditions.
- `dsll32` followed by `dsra32` is an `s16` sign-extension pattern.

Project idioms include:

```c
IS_HERO(pcId) == (pcId == PC_HERO)
K_ASSERT(cond, line)
```

Hero branches use `gGlobalWork.heroX`; non-hero branches use `gPcs[...]`. An unconditional assertion is `K_ASSERT(false, line)`. See [`docs/prefixes.md`](docs/prefixes.md) for naming conventions and the [README glossary](README.md#glossary) for project terms.

Some implementations can remain `NONMATCHING` while useful source is preserved. Common compiler differences include register assignment, evaluation order, loop-invariant hoisting, scheduling, and VU/COP2 macro output.

## Repository layout

```text
config/slus21621.yaml       splat configuration
config/symbol_addrs.txt     function symbol map
tools/build.py              build driver (asm baseline + C objects + link)
tools/asm.py                GNU as wrapper and byte-correction step
tools/recover_symbols.py    recover data-symbol addresses and _gp
tools/mwccgap/              vendored mwcc global assembly processor
tools/verify.py             per-function C verifier
tools/fndiff.py             single-function diff helper
tools/permute.py            source-mutation permuter
tools/permute_sweep.py      batch permuter driver
tools/permute_ast.py        AST-level permuter
tools/m2ctx.py              decomp.me context generator
asm/macro.inc               committed assembler macro include
asm/*.s                     generated disassembly, gitignored
src/                        decompiled C
include/                    headers
docs/prefixes.md            naming convention notes
Makefile                    setup, split, build, and verify targets
image.bin                   extracted loadable image, gitignored
SLUS_216.21                 retail ELF, bring your own, gitignored
```

A source file links as a real C object after its functions and owned data are fully decompiled and placeable. Files with WIP functions or unresolved data remain on the assembly baseline. See the README for the build model.

## Submitting changes

Keep changes small and coherent. Before submitting a matched function, run:

```sh
python tools/fndiff.py src/path/file.c functionName
python tools/verify.py src/path/file.c
```

Describe a function as matched only when `tools/verify.py` reports `MATCH`. Do not commit local-only or copyrighted artifacts:

```text
tools/verify_config.local.json
image.bin
SLUS_216.21
```
