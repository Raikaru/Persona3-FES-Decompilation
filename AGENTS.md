# AGENTS.md

This guide is for AI coding agents contributing to this Persona 3 FES (USA) matching decompilation.

Stay deterministic. Use the verified commands below. Do not invent paths, flags, build targets, or tool behavior. Do not claim a match unless `tools/verify.py` reports `MATCH`.

## Ground truth

Target retail ELF:

```text
SLUS_216.21
sha1: 3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb
```

Target properties:

```text
Machine: MIPS R5900, PS2 Emotion Engine
Endian: little
Loadable image: one PT_LOAD segment
VRAM: 0x100000
Loadable size: 0x8acc80
Symbols: stripped, no symtab
```

The current matching build links the asm baseline. Decompiled C in `src/` is validated per function by `tools/verify.py`. Treat `verify.py` as the C match gate.

## Required local setup

The contributor must provide the original CodeWarrior PS2 toolchain locally. It is not in the repo.

Required version:

```text
mwcps2-3.0.1b210-060308
```

Required programs:

```text
mwccps2.exe
asm_r5900_elf.exe
mwldps2.exe
```

C compiler flags used by the verifier:

```text
-O2 -Iinclude
```

Python dependency:

```sh
pip install splat64
```

`splat64` pulls in `spimdisasm` and `rabbitizer`.

FLEXlm quirk: copy `LMGR326B.DLL` from `mwcps2-3.0b52` into the 3.0.1 toolchain directory twice, with both destination names:

```text
LMGR326B.DLL
LMGR8C.DLL
```

Local config file:

```text
tools/verify_config.local.json
```

Contents:

```json
{
  "mwcc": "<path>/mwccps2.exe",
  "retail_elf": "<path>/SLUS_216.21"
}
```

The environment variables `P3_MWCC` and `P3_RETAIL_ELF` also work.

Do not commit:

```text
tools/verify_config.local.json
image.bin
SLUS_216.21
```

## Repository setup loop

If the loadable image has not been extracted yet:

```sh
make setup
```

If the splat output is missing or `config/slus21621.yaml` changed:

```sh
make split
```

`make split` runs:

```sh
python -m splat split config/slus21621.yaml
```

It generates disassembly and data, including:

```text
asm/code1.s
asm/code2.s
```

## Build and verification commands

Build the asm baseline:

```sh
make
```

Expected successful loadable image check:

```text
loadable image sha1: 9203646d9aa48ff24eb4ba4b328b02df468a9483 OK
```

Run the full per-function C verifier:

```sh
make verify
```

Alias:

```sh
make check
```

Direct verifier command:

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

Write JSON output:

```sh
python tools/verify.py --json report.json
```

Diff one function:

```sh
python tools/fndiff.py src/path/file.c functionName
```

## Deterministic function-matching loop

Use this loop for one function at a time.

### 1. Select a function

Pick an unmapped function from generated asm or Ghidra.

The source symbol usually has this shape:

```text
func_XXXXXXXX
```

`XXXXXXXX` is the retail address. Preserve that address in the C marker.

### 2. Locate the destination C file and header

Put C in the appropriate file under:

```text
src/
```

Put the prototype in the matching header under:

```text
include/
```

Do not create a second convention when an existing nearby file already shows the pattern.

### 3. Add the marker and implementation

The marker must be immediately above the function definition:

```c
// FUN_XXXXXXXX
ReturnType functionName(...)
{
    ...
}
```

If the function is implemented but intentionally not byte-exact yet, use:

```c
// FUN_XXXXXXXX NONMATCHING
```

Do not use `NONMATCHING` for an untouched stub. Do not remove `NONMATCHING` until `verify.py` reports `MATCH`.

### 4. Run the single-function diff

```sh
python tools/fndiff.py src/path/file.c functionName
```

Read the result this way:

- `differing words (reloc-masked): 0` means the reloc-masked body words match.
- A small nonzero count can be window-tail padding.
- Search the output for lines containing `!`.
- If there are no `!` lines in the function body, the body is clean.
- If there are `!` body lines, keep iterating on the C.

Do not guess from source similarity. Let `fndiff.py` drive the work.

### 5. Run file-level verification

```sh
python tools/verify.py src/path/file.c
```

Interpret statuses exactly:

```text
MATCH              byte-matches retail for that function
STUB               marker exists, but the body is still a TODO stub
NONMATCHING        implemented and intentionally marked nonmatching
STALE_NONMATCHING  marker says NONMATCHING, but verifier no longer agrees with that state
MISMATCH           compiled bytes differ from retail
SIZE_MISMATCH      compiled function size differs from retail
NO_SYMBOL          verifier could not resolve the marked function symbol
COMPILE_ERROR      CodeWarrior compilation failed
UNKNOWN_ADDR       marker address is not known to the verifier
```

The verifier exits nonzero if any checked function is outside this allowed set:

```text
MATCH
STUB
NONMATCHING
```

Only claim completion for a matched function when the relevant function reports:

```text
MATCH
```

### 6. Decide the marker state

Use this rule:

```text
verify.py reports MATCH       -> marker is // FUN_XXXXXXXX
implemented but not matching  -> marker is // FUN_XXXXXXXX NONMATCHING
TODO stub                     -> leave it as a stub, not a claimed match
```

If source-level matching is blocked by compiler artifacts, keep the implementation honest with `NONMATCHING`.

Common compiler-artifact blockers:

- Register allocation.
- Subexpression evaluation order.
- Loop-invariant address or constant hoisting.
- Instruction scheduling.
- VU/COP2 macro output.

## Fingerprint checklist

Before changing types or control flow, check the retail asm for these fingerprints.

Signedness and widths:

- `lb` means signed 8-bit load.
- `lbu` means unsigned 8-bit load.
- `lh` means signed 16-bit load.
- `lhu` means unsigned 16-bit load.
- `div` means signed division.
- `divu` means unsigned division.
- `slt` means signed less-than.
- `sltu` means unsigned less-than.
- `bgez`, `bltz`, and `blez` reveal signed branch conditions.
- `dsll32` followed by `dsra32` is an `s16` sign-extension pattern.

Project idioms:

```c
IS_HERO(pcId) == (pcId == PC_HERO)
```

Hero branch:

```text
gGlobalWork.heroX
```

Non-hero branch:

```text
gPcs[...]
```

Assert pattern:

```c
if (!(cond)) K_Assert(__FILE__, line);
```

Use the macro:

```c
K_ASSERT(cond, line)
```

Unconditional assert:

```c
K_ASSERT(false, line)
```

Unconditional asserts are used in hero-only accessors. Assert `__FILE__` strings in the binary identify the original source file for a function.

Instruction validity:

- The R5900 core does not have 64-bit `ddiv` or `ddivu`.
- Any apparent `ddiv` or `ddivu` instruction is data, not code.

## How the matching build works

Use this model when debugging build or asm issues:

1. `splat` disassembles the image. The config uses numeric register names:

   ```text
   mips_abi_gpr: numeric
   ```

2. `tools/desym.py` rewrites splat GAS asm into raw-immediate asm accepted by the CodeWarrior assembler:

   ```text
   %hi/%lo(sym[+off]) -> literal hi/lo
   jal/j sym           -> jal/j 0xADDR
   div/divu/mult/multu 3-operand form -> 2-operand form
   not pseudo          -> nor rd,rs,$0
   ```

   Symbols are resolved through `config/symbol_addrs.txt` or through `func_` / `D_` addresses in names.

3. `tools/asm.py` assembles with:

   ```text
   asm_r5900_elf -gnu -endian little
   ```

   If the assembler rejects a line, or if an assembled word differs from the retail image, `tools/asm.py` rewrites that original byte range as `.word` or `.byte`. This keeps generated objects byte-exact and handles data inside code.

4. `tools/build.py` patches bogus section alignment to 1, links with:

   ```text
   build/slus21621.lcf
   ```

   The generated linker command file places `code1`, `data1`, `code2`, and `data2` contiguously from:

   ```text
   0x100000
   ```

5. The build verifies the linked loadable image sha1:

   ```text
   9203646d9aa48ff24eb4ba4b328b02df468a9483
   ```

Remember: this is currently an asm-baseline matching build. The C acceptance gate is per-function verification.

## Repo map

```text
config/slus21621.yaml       splat config
config/symbol_addrs.txt     function symbol map, about 13,407 entries
tools/build.py              build driver
tools/desym.py              asm rewrite step
tools/asm.py                assembler wrapper and byte-correction step
tools/verify.py             per-function C verifier
tools/fndiff.py             single-function diff helper
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

## Final response rules for agents

Before reporting success on code work, provide the exact command evidence you ran.

For a matched function, the minimum useful evidence is:

```sh
python tools/fndiff.py src/path/file.c functionName
python tools/verify.py src/path/file.c
```

The claim must be limited to what those commands prove:

- Say `MATCH` only when `verify.py` says `MATCH`.
- Say `NONMATCHING` when the implementation is useful but not byte-exact and the marker says `// FUN_XXXXXXXX NONMATCHING`.
- Do not present the asm-baseline `make` result as proof that C functions are linked into the final image.
