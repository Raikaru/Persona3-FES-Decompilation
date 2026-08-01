# Persona 3 FES Matching Decompilation Roadmap

This roadmap describes the remaining work for the Persona 3 FES matching decompilation. It is a public guide to useful contributions, not a progress log. The README progress badge and `python tools/progress.py` report the current state; generated reports are authoritative and numbers are intentionally not copied here.

## What done means

Persona 3 FES is done when a clean checkout rebuilds `SLUS_216.21` from C and produces a byte-identical retail load image and ELF.

A function window is the byte range in the retail executable occupied by one function. Every window must have an intentional source owner, a stable boundary, and one marker. Final source must use typed structures, meaningful names where evidence permits, explicit ABI details, and readable control flow rather than raw decompiler artifacts.

The per-function verifier must report `MATCH` for every function. C-owned translation units must be selected by the matching build, with section ownership, alignment, relocations, and zero-filled data reproducing retail. Startup, SDK, and compiler-runtime assembly may remain only when its provenance and interface are documented and it does not hide unknown game logic.

Build and release checks must be reproducible from a clean checkout with the documented toolchain and user-supplied legal inputs. See the README for setup and legal information.

## First priority: close understood work

Turn existing understanding into verified matches before opening another large subsystem.

- Reconcile markers and verifier status where candidate bytes already agree.
- Inspect functions with small byte differences directly in source and disassembly, then group related differences by compiler code-generation family.
- Capture reusable source-shaping rules in `docs/matching.md`; add a focused compiler-debugger test case when the responsible phase is unknown.
- Record compiler limitations that source changes cannot remove so exhausted variants are not retried, while continuing to fix semantic C errors.
- Review near-complete translation units first: `scrTraceCode.c`, `scrComuCommand.c`, `kwlnRoot.c`, `br_res.c`, `dds3Process.c`, `bpp_panel.c`, `h_cursor.c`, `bp_persona.c`, `br_persona.c`, `datScript.c`, and `bp_tuta.c`.

Fully matching files that are not yet C-linked are also immediate priorities: `src/Camp/_h_camp_item.c`, `src/Kosaka/k_spipe.c`, `src/Main/Battle/Cmd/bcm_main.c`, `src/Main/Battle/Cmd/bpm_main.c`, `src/Main/Battle/Panel/bp_misc.c`, `src/Main/OpEd/op_res.c`, `src/Main/Social/sfl_persona.c`, `src/Scene/resrcManager.c`, and `src/Script/scrCommonCommand.c`.

For each linkage issue, identify whether the cause is noncontiguous text, an unresolved external symbol, owned-data placement, conflicting recovered bases, section padding or alignment, or retail nonzero bytes in a claimed BSS range. Fix source ownership or the build model instead of suppressing eligibility checks.

## Engine and script priorities

Advance subsystems where shared types and conventions unlock many callers.

- Finish Script helpers, then stabilize Kernel task and root structures.
- Close the resource manager, scene, CDVD, and command interfaces shared by the field and battle engines.
- Complete Kosaka field and runtime families before isolated presentation code.
- Work Main and Battle by coherent state-machine family: lifecycle, units, targeting, action and order, camera, panels, result, and boss-specific logic.
- After a translation unit matches, settle its data ownership and linkage rather than deferring that decision.

## Game-specific content and presentation

Work through remaining game-owned regions in dependency order:

- Camp data and menu primitives, followed by state machines and presentation.
- Event command dispatch, message, effect, and menu helpers, followed by FCL shop and combine flows.
- Model loading, animation cursors, resource dispatch, effects, and primitive drawing.
- Interface message and panel managers, font, and tag paths.
- Yajima runtime and time-limit helpers, then calendar, social, communication, opening, ending, and result UI families.

Large generated-looking functions should be split conceptually during review even when they remain one retail function. Names should follow proven behavior and call relationships, not guesses based only on constants.

## Middleware and standard-library regions

Handle CRI middleware, RenderWare, SCE libraries, the C runtime and math code, and startup/platform code by family and with clear provenance.

- Identify library versions and public SDK signatures before inventing names.
- Group thin accessors, allocation wrappers, callbacks, and table-driven routines into mechanical batches.
- Recover common structures once and apply them consistently, with size and offset assertions where supported.
- Separate genuine game wrappers from third-party library bodies.
- Use upstream source only as evidence; retail bytes and the verifier remain authoritative for this build.
- Document retained startup or SDK assembly and verify every interface crossing into C.

## Compiler code-generation tail

For functions whose semantics are understood but whose bytes still differ, classify the first differing instructions as register allocation, scheduling, FPU allocation, signedness or extension, switch lowering, mask propagation, commutative operand order, return layout, or delay-slot placement.

Apply the established matching catalog before searching for new variants. Use the MWCC debugger to find the first compiler phase where retail and candidate behavior diverge. Use bounded text or AST permutation only around a proven source change. Promote a discovered family rule across affected functions and verify each independently.

Do not use opaque assembly to hide incorrect semantics. An unavoidable exact assembly shim must be isolated, explained, and tracked as an exception until it can be removed.

## Release verification

Before declaring the project complete:

- Select every fully matching C-owned translation unit in the matching build.
- Resolve data-section bases, alignment, padding, relocations, and BSS ownership.
- Confirm that no linked function is absent from the matching set.
- Rebuild from a clean checkout using only documented tools and legal inputs.
- Run the complete verifier, tests, boundary reconciliation, progress validation, and whole-image and ELF comparisons.
- Regenerate published progress and linkage reports from the release build.

The project is done only when the completion criteria above hold and the rebuilt `SLUS_216.21` is byte-identical to the verified retail executable. Canonical function windows are in `tools/slus21621_functions.json`; per-function checks use `tools/verify.py`, and `make` wraps `tools/build.py`.
