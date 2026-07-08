# Persona 3 FES (USA) Decompilation

This is a WIP matching decompilation of Shin Megami Tensei: Persona 3 FES.
The goal is to fully decompile the game.

## Target

- `SLUS_216.21` (sha1 `3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb`)
- The retail ELF's `.comment` section says it was built with
  `MW MIPS C Compiler (2.4.1.01)`, but that string comes from MWLD and is
  shared across many CodeWarrior releases. Codegen evidence (far-global
  addressing uses an allocated register with the symbol+offset baked into the
  hi16/lo16 relocs, instead of the `$at`-based form emitted by 3.0/earlier)
  pins the compiler to the `3.0.1` line, build 198 (Oct 2005) or later.
  This project matches against `mwcps2-3.0.1b210-060308` with `-O2`; the
  switch from `mwcps2-3.0b52-030722` turned 120 previously NONMATCHING
  functions into byte-equivalent matches with their plain source shapes.

## Verification

Every decompiled function carries a `// FUN_xxxxxxxx` marker with its retail
address. `tools/verify.py` compiles each source file with the project
toolchain and byte-compares every marked function against the retail ELF
(relocated instruction fields masked, retail tail padding checked so stubs
cannot false-pass):

```sh
# one-time machine setup: point the tool at your compiler and retail ELF
# either export P3_MWCC / P3_RETAIL_ELF, or create tools/verify_config.local.json:
#   {"mwcc": "<path>/mwccps2.exe", "retail_elf": "<path>/SLUS_216.21"}

python tools/verify.py                          # verify the whole repo
python tools/verify.py src/rw/rprandom.c        # verify one file
python tools/verify.py --show-mismatches        # per-function failure detail
python tools/verify.py --json report.json       # full machine-readable report
```

Statuses: `MATCH` (byte-equivalent), `STUB` (`// TODO` body), `NONMATCHING`
(explicitly tagged WIP, see below), `STALE_NONMATCHING`, `MISMATCH`,
`SIZE_MISMATCH`, `NO_SYMBOL`, `COMPILE_ERROR`, `UNKNOWN_ADDR`. The exit code
is nonzero if anything other than `MATCH`/`STUB`/`NONMATCHING` is found, so
the tool can be used as a pre-commit / CI gate.

### NONMATCHING convention

A function that is implemented but not yet byte-equivalent MUST carry the tag
on its marker line:

```c
// FUN_0029a2c0 NONMATCHING
u32 btlOrderAddAction(BtlAction* action)
```

Untagged implementations are treated as match claims and fail verification if
they differ from retail. When a tagged function is brought to a byte-match,
the verifier reports `STALE_NONMATCHING` until the tag is removed. Commit
messages should only say "match" for functions that verify as `MATCH`.

`tools/slus21621_functions.json` holds the function-entry map exported from
Ghidra; function windows are entry-to-next-entry distances, tightened by the
marker addresses present in the source tree.
