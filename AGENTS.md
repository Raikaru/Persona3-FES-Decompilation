# AGENTS.md

This repository is a matching decompilation of Persona 3 FES (USA) for the PlayStation 2.

## Contributor manual

[`CONTRIBUTING.md`](CONTRIBUTING.md) is the single manual for human and automated contributors.
Read it for:

- toolchain prerequisites and local configuration;
- the retail executable and build setup;
- build, per-function verification, and matching workflow;
- m2c and permuter usage;
- C style and repository layout.

Do not copy setup or workflow instructions into this file. Keep changes to this pointer and the automation rules below.

## Rules for automated contributors

### Verification

- `tools/verify.py` is the per-function acceptance check.
- A green `make` proves that the final image is byte-identical, but it does not prove that a specific function's C produced its bytes.
- Cite `tools/verify.py`, not `make`, when claiming a function match.
- Only claim `MATCH` when `tools/verify.py` reports `MATCH` for the relevant function.

### Source edits

- Never edit a function that already reports `MATCH`.
- Never use inline assembly to force a match on ordinary computation. Use C and the existing project interfaces instead.

### Marker hygiene

Every participating C function needs exactly one marker immediately above its definition, with no intervening comment:

```c
// FUN_XXXXXXXX
ReturnType functionName(...)
```

Use the retail address in hexadecimal. Add `NONMATCHING` on that same marker line only for a useful implementation whose bytes do not match yet. Remove the tag only after `tools/verify.py` reports `MATCH`.
