# Contributing

This repository is a matching decompilation of Persona 3 FES (USA), retail ELF `SLUS_216.21`.

The target ELF is stripped, little-endian MIPS R5900 code for the PS2 Emotion Engine. The expected retail whole-ELF sha1 is:

```text
3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb  SLUS_216.21
```

The build extracts the single loadable image from that ELF, compiles the fully-decompiled source files into real C objects (mwccps2 via `tools/mwccgap`), assembles the rest of the disassembly with GNU R5900 binutils, links everything with the original CodeWarrior PS2 linker, and verifies the linked loadable image is byte-identical to retail. Decompiled C in `src/` is validated per function with `tools/verify.py`.

## Prerequisites

### CodeWarrior PS2 toolchain

Install the original CodeWarrior PS2 suite locally. It is not stored in this repository.

Required toolchain version:

```text
mwcps2-3.0.1b210-060308
```

Required programs from that toolchain:

```text
mwccps2.exe
mwldps2.exe
```

Required GNU binutils programs:

```text
mipsel-linux-gnu-as
mipsel-linux-gnu-objcopy
```

On Debian/WSL, install them with `binutils-mipsel-linux-gnu`.

C files are compiled with these verified compiler flags:

```text
-O2 -Iinclude
```

The PS2 R5900 core does not have 64-bit `ddiv` or `ddivu` instructions. If a disassembly appears to contain one of those instructions, treat it as data, not executable code.

### FLEXlm DLL quirk

The 3.0.1 toolchain has a FLEXlm DLL issue. Copy `LMGR326B.DLL` from the decomp.dev GC compilers into the 3.0.1 toolchain directory twice, using both of these destination names:

```text
LMGR326B.DLL
LMGR8C.DLL
```

### Python tools

Install Python and `splat64`. `splat64` pulls in `spimdisasm` and `rabbitizer`.

```sh
pip install splat64
```

### Retail ELF

Bring your own retail `SLUS_216.21`. It is copyrighted and must not be committed. The retail ELF and extracted `image.bin` are gitignored.

Expected retail whole-ELF sha1:

```text
3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb
```

## Setup

Create a local verification config file:

```json
{
  "mwcc": "<path>/mwccps2.exe",
  "retail_elf": "<path>/SLUS_216.21"
}
```

Save it here:

```text
tools/verify_config.local.json
```

That file is local-only and gitignored.

You can also provide the same paths with these environment variables:

```text
P3_MWCC
P3_RETAIL_ELF
```

Extract the loadable image from your retail ELF:

```sh
make setup
```

Run splat once, or rerun it after changing the splat config:

```sh
make split
```

`make split` runs:

```sh
python -m splat split config/slus21621.yaml
```

It generates the disassembly and data, including:

```text
asm/code1.s
asm/code2.s
```

## Building & verifying

Build the current asm baseline:

```sh
make
```

The build assembles, links, writes `build/slus21621.elf`, and verifies the linked loadable image sha1:

```text
9203646d9aa48ff24eb4ba4b328b02df468a9483
```

A successful build prints:

```text
loadable image sha1: 9203646d9aa48ff24eb4ba4b328b02df468a9483 OK
```

The full build takes about 45 seconds on the verified setup.

Run the per-function C verification gate:

```sh
make verify
```

`make check` is an alias:

```sh
make check
```

Both run:

```sh
python tools/verify.py
```

Verify one file:

```sh
python tools/verify.py src/rw/rprandom.c
```

Show mismatch details:

```sh
python tools/verify.py --show-mismatches
```

Write a JSON report:

```sh
python tools/verify.py --json report.json
```

`tools/verify.py` compiles functions in `src/` marked with `// FUN_XXXXXXXX`, byte-compares them against retail, masks relocated fields, and checks tail padding.

Verification statuses are:

```text
MATCH
STUB
NONMATCHING
STALE_NONMATCHING
MISMATCH
SIZE_MISMATCH
NO_SYMBOL
COMPILE_ERROR
UNKNOWN_ADDR
```

The verify command exits nonzero if any checked function is not one of:

```text
MATCH
STUB
NONMATCHING
```

How C reaches the image: a source file links as a real C object once it is fully decompiled (no stub/NONMATCHING functions), contiguous, and every owned data section is placeable byte-exact. The build carves the function range out of the asm baseline and places the `mwccgap`-built object's `.text` there; it likewise carves and places the object's `.rodata`/`.data`/`.sdata` at their recovered addresses and links `.sbss`/`.bss` as zero-filled PROGBITS. A file stays on the asm baseline only when a data symbol's address can't be recovered, a data relocation target is unresolvable, or a function is WIP. `config/symbols_recovered.txt` (regenerate with `make symbols`) supplies the data-symbol addresses and `_gp` the linker needs.

## The matching workflow

1. Pick an unmapped function.

   Start from a `func_XXXXXXXX` in `asm/`, or from Ghidra. The `XXXXXXXX` value is the retail address.

2. Write the C implementation in the appropriate file under `src/`.

   Put the function marker on the line immediately above the function definition:

   ```c
   // FUN_XXXXXXXX
   ReturnType functionName(...)
   {
       ...
   }
   ```

   Add the prototype to the matching header under `include/`.

3. Diff the function against retail.

   ```sh
   python tools/fndiff.py src/path/file.c functionName
   ```

   Iterate until the diff reports:

   ```text
   differing words (reloc-masked): 0
   ```

   Window-tail padding may still show a small nonzero count. Search the `fndiff` output for lines containing `!`; if there are no `!` body diff lines, the function body is clean.

4. Verify the file.

   ```sh
   python tools/verify.py src/path/file.c
   ```

   The function must report `MATCH` before you claim it as matched.

5. If the function is implemented but not byte-exact, mark it explicitly:

   ```c
   // FUN_XXXXXXXX NONMATCHING
   ```

   Leave `NONMATCHING` only for real work-in-progress C that intentionally does not match yet.

## m2c first-pass workflow

Use `m2c` to turn a retail assembly function into a typed control-flow draft
before hand decompilation. The project pins a known m2c revision and supplies
the PS2/MWCC target, an isolated function assembly file, and declarations from
the function's translation unit:

```sh
make m2c-setup
make m2c FILE=src/Battle/btlVoice.c FUNC=func_002e3d50
```

The generated draft, assembly slice, and context are written under
`build/m2c/`. Add `STACK=1` to emit m2c's inferred stack-structure template:

```sh
make m2c FILE=src/Battle/btlVoice.c FUNC=func_002e3d50 STACK=1
```

`M2C=/path/to/m2c.py` can override the pinned local installation. Treat m2c
output as evidence, not finished source: recover semantic names and project
types, compare every call and condition with retail assembly, and remove
decompiler casts/gotos when clean C expresses the same behavior. Only
`tools/verify.py` establishes a match.

## Optional compiler-debugger workflow

For a semantically correct function whose residual appears to be instruction
selection, evaluation order, scheduling, or register allocation, the sibling
`mwccps2-debugger` project can capture selected internal stages of the exact
b210 compiler.

Read [`docs/mwccps2-debugger.md`](docs/mwccps2-debugger.md) before using it.
The short workflow is:

1. establish the exact residual with `fndiff.py` and `verify.py`;
2. create a minimal source-variant experiment in the sibling debugger;
3. require equal direct and instrumented object hashes;
4. locate the first semantic PCode divergence;
5. apply one evidence-backed source change here;
6. rerun `tools/verify.py`.

The debugger is optional and is not imported by the P3 build. It cannot observe
the retail compiler's transient AST, PCode, scheduler queue, or interference
graph. Only `tools/verify.py` can establish a function `MATCH`.

## Automated matching (permuter)

When a function is implemented and semantically correct but still differs from
retail only in register allocation, instruction scheduling, or comparison /
eval-order codegen, `tools/permute.py` can search for a byte-exact source
variant automatically. It mutates only the target function's source text
(optimization_level pragma, local-declaration reorder, statement reorder,
commutative operand swap, additive reassociation, integer relational-bound
rewrite, compound-assignment expansion, and parameter-copy temporaries),
recompiles the translation unit with the project mwccps2 flags, and scores each
candidate with `verify.py`'s reloc-masked comparison.

```sh
python tools/permute.py src/path/file.c functionName --time 60
```

On a hit it prints the winning region and writes it to `--out` (or
`file.match.c`). Apply it by hand, drop the `NONMATCHING` tag, and re-confirm
with `tools/verify.py` -- a permuter hit is a byte match, not a proof of
semantics, so read the diff before committing.

Sweep every non-matching function with a worker pool:

```sh
python tools/permute_sweep.py --time 30 --workers 3
```

The permuter is strongest on functions with several locals or statements
(reordering room); tiny control-flow stubs usually need a hand-chosen structure
(for example `switch` vs `if`/`||`).

### AST search (decomp-permuter randomizer)

For register-allocation and scheduling walls that text mutation can't reach,
`tools/permute_ast.py` drives the full upstream decomp-permuter randomizer
(~30 AST-level passes: temporary-for-expression, type randomization, statement
reordering, reassociation, ...) against this repo's mwccps2 compile and
`verify.py` scoring.

```sh
python tools/permute_ast.py src/Battle/btlMain.c btlMainUpdateStateLose --time 120
```

On first run it clones decomp-permuter into `tools/decomp-permuter` (gitignored).
It requires WSL Debian with `cpp` (from `build-essential`) and a system Python
with `pycparser`, `attrs`, and `toml`; it preprocesses the TU with `cpp
-nostdinc` (the repo is self-contained), parses it with decomp-permuter's
pycparser, and hill-climbs one mutation at a time.

A hit's source is normally heavily mutated (dead temporaries, `if (1)`,
reassociations) yet compiles byte-exact. Read it, extract the single change
that matters, write clean C, and re-confirm with `tools/verify.py` -- the raw
output is a lead, not a patch. This is the standard decomp-permuter workflow.

## Conventions

### Function markers

Every C function that participates in verification needs a marker immediately above the definition:

```c
// FUN_XXXXXXXX
```

Use the retail address in hexadecimal. If the implementation is intentionally not byte-matching yet, add the status on the same marker line:

```c
// FUN_XXXXXXXX NONMATCHING
```

Do not claim a function matches unless `tools/verify.py` reports `MATCH` for it.

### Type and control-flow fingerprints

Use the retail asm to recover source-level intent. These instruction patterns are useful fingerprints:

- `lb` / `lh` versus `lbu` / `lhu` distinguish signed and unsigned loads.
- `div` versus `divu` distinguishes signed and unsigned division.
- `dsll32` followed by `dsra32` is an `s16` sign-extension pattern.
- `slt` versus `sltu` distinguishes signed and unsigned comparisons.
- `bgez`, `bltz`, and `blez` expose signed branch conditions.

Known project idioms:

```c
IS_HERO(pcId) == (pcId == PC_HERO)
```

Hero branches use `gGlobalWork.heroX`. Non-hero branches use `gPcs[...]`.

Assertion pattern:

```c
if (!(cond)) K_Assert(__FILE__, line);
```

Use the project macro form:

```c
K_ASSERT(cond, line)
```

An unconditional assert is represented as:

```c
K_ASSERT(false, line)
```

Unconditional asserts appear in hero-only accessors. Assert `__FILE__` strings in the binary identify the original source file for a function.

### When source may not match cleanly

Some differences often resist clean source-level matching. It is acceptable to leave these as `NONMATCHING` while the C remains useful and honest:

- Register allocation differences.
- Subexpression evaluation order.
- Loop-invariant address or constant hoisting.
- Instruction scheduling.
- VU/COP2 macro output.

## Repo layout

```text
config/slus21621.yaml       splat config
config/symbol_addrs.txt     function symbol map, about 13,586 entries
tools/build.py              build driver (asm carve + C objects + link)
tools/asm.py                GNU as wrapper and byte-correction step
tools/recover_symbols.py    recover data-symbol addresses + _gp from retail
tools/mwccgap/              vendored mwcc global assembly processor
tools/verify.py             per-function C verifier
tools/fndiff.py             single-function diff helper
tools/permute.py            per-function source-mutation permuter
tools/permute_sweep.py      batch permuter driver
tools/permute_ast.py        AST-level permuter (decomp-permuter randomizer)
tools/m2ctx.py              decomp.me context generator
tools/setup_m2c.py          pinned m2c installer
tools/m2c_decompile.py      one-function m2c/context driver
tools/progress.py           progress report
tools/gen_objdiff.py        objdiff target/base object generator
asm/macro.inc               committed assembler macro include
asm/*.s                     generated disassembly, gitignored
asm/*.o                     generated objects, gitignored
src/                        decompiled C
include/                    headers
docs/prefixes.md            prefix notes
Makefile                    setup, split, build, verify targets
image.bin                   extracted loadable image, gitignored
SLUS_216.21                 retail ELF, bring your own, gitignored
```

## Submitting changes

Keep changes small and coherent. A good submission usually contains one matched function, or a small cluster of directly related functions and headers.

Before submitting a matched function, run:

```sh
python tools/fndiff.py src/path/file.c functionName
python tools/verify.py src/path/file.c
```

Only describe a function as matched when `tools/verify.py` reports `MATCH` for that function.

If a function is useful but not byte-exact, keep the marker honest:

```c
// FUN_XXXXXXXX NONMATCHING
```

Do not commit local-only or copyrighted artifacts:

```text
tools/verify_config.local.json
image.bin
SLUS_216.21
```
