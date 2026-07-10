# Optional MWCCPS2 compiler debugger

The sibling `mwccps2-debugger` project can capture selected internal stages of
the exact CodeWarrior PS2 compiler used by this decomp. Use it to diagnose
compiler-artifact mismatches after the C implementation is semantically
credible and compiles successfully.

It is optional. The normal P3 split, build, link, and verification pipeline does
not import or require the debugger.

## Repository layout

The supported local layout is:

```text
source/
  Persona3-FES-Decompilation/
  mwccps2-debugger/
```

Full debugger documentation is in the sibling repository:

```text
../mwccps2-debugger/README.md
../mwccps2-debugger/docs/getting-started.md
../mwccps2-debugger/docs/experiments.md
../mwccps2-debugger/docs/p3-workflow.md
../mwccps2-debugger/docs/architecture.md
../mwccps2-debugger/docs/troubleshooting.md
```

Optional integration configuration:

```text
config/mwccps2-debugger.json
```

The configuration points at the sibling repository, exact compiler profile,
local verifier reports, and ignored bundle output. It is not read by
`tools/build.py`, `make`, or `tools/verify.py`.

## Supported compiler

The fully validated live profile is exact:

```text
Release:     mwcps2-3.0.1b210-060308
SHA-256:     286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7
PE timestamp: 0x440f429b
Image base:  0x00400000
P3 flags:    -O2 -Iinclude
```

Do not use b210 breakpoint addresses with a different executable. The debugger
fingerprints the compiler before installing breakpoints.

## When it helps

Use the debugger for a compiled, near-matching function when `fndiff.py` shows:

- the same operations assigned to different registers;
- the same operations in a different order;
- unexplained commutative operand/evaluation order;
- sign/zero-extension placement differences;
- loop-invariant versus loop-local mask/address behavior;
- equivalent boolean or switch source forms producing different blocks;
- uncertainty about whether a source permutation reaches compiler PCode at all.

Do not use it as a substitute for reconstructing correct calls, types, branches,
constants, and side effects. Do not use it to explain `COMPILE_ERROR`, a stub,
or an unresolved relocation before fixing those problems.

## Required P3 workflow

### 1. Establish the real residual

```powershell
python tools/fndiff.py src/path/file.c FunctionName
python tools/verify.py src/path/file.c
```

Record the exact non-relocation instruction pairs and check whether the count
includes tail padding.

### 2. Build one small compiler reducer

In the sibling debugger, create:

```text
experiments/<question>/
  experiment.json
  baseline.c
  variant.c
```

Preserve the relevant P3 types, signedness, storage roles, loop shape, and
`-O2` behavior. Change one property per variant. Do not copy an entire P3
translation unit when a small stand-in struct/global reproduces the compiler
question.

### 3. Run direct and instrumented compilations

From `../mwccps2-debugger`:

```powershell
python mwccps2_experiment.py experiments/<question> --output build/<question>-run
```

Use a fresh output directory. Reject the evidence if any variant's direct and
instrumented object SHA-256 values differ.

### 4. Classify the first semantic difference

Read:

```text
build/<question>-run/experiment-summary-v1.json
```

Use `earliest_pcode_divergence`, not a raw graph difference:

| First difference | Action |
| --- | --- |
| `codegen_entry` | Change source/frontend/selector shape: types, casts, expression order, control flow, address form. |
| After scheduling | Inspect scheduler dependencies, latency, resources, deadlines, critical path, or stable ties. |
| After allocation | Inspect virtual roles, liveness/interference, coalescing, simplify order, masks, and colors. |
| Semantic PCode and object equal | Stop trying that source spelling; it is not a demonstrated b210 object-code lever. |
| PCode equal but object differs | Cause remains after the captured semantic boundary; do not invent one. |

At normal P3 `-O2`, scheduling breakpoints may not execute. Missing scheduler
captures are expected and must not be treated as empty graphs.

### 5. Apply exactly one supported source change

Return to this repository and make the smallest source edit supported by the
experiment. Then rerun:

```powershell
python tools/fndiff.py src/path/file.c FunctionName
python tools/verify.py src/path/file.c
```

Only `tools/verify.py` may establish `MATCH`. A debugger snapshot, experiment
object equality, smaller normalized diff, or permuter score is not sufficient.

## Optional deterministic analysis bundle

Generate a focused verifier report:

```powershell
python tools/verify.py src/path/file.c --json build/target-verify.json
```

From `../mwccps2-debugger`:

```powershell
python mwccps2_p3_reduce.py --config ../Persona3-FES-Decompilation/config/mwccps2-debugger.json --report ../Persona3-FES-Decompilation/build/target-verify.json --function FunctionName --output build/FunctionName-analysis
```

The bundle records normalized function metadata and fingerprints of supplied
experiment/analysis evidence. It does not edit source or claim a match.

## Relationship to the permuter

The debugger and permuter solve different parts of the problem:

- **Debugger:** localizes the compiler phase and proves whether a source lever
  changes PCode, schedule, allocation, or final object bytes.
- **Permuter:** searches many source variants and scores them against retail.

Recommended escalation for a semantically correct residual:

1. inspect `fndiff.py` and classify the actual instructions;
2. check `docs/matching.md` for known source-shaping rules;
3. use a small debugger reducer when the phase or useful lever is unclear;
4. run `tools/permute.py` for cheap text mutations;
5. run `tools/permute_ast.py` for broader source-shape search;
6. extract the minimal clean source change from any hit;
7. re-run `tools/verify.py`.

Debugger evidence can narrow the permuter search. It does not make mutated
source semantically correct automatically.

## Evidence language for agents

A valid handoff distinguishes:

```text
Observed locally: direct/instrumented hashes, captured PCode, scheduler winner,
                  or allocator graph/assignment.
Inference about retail: likely phase/role explanation; explicitly labeled.
Authoritative result: P3 tools/verify.py status after the source edit.
```

Never say the debugger observed retail AST, retail PCode, retail scheduler
state, or retail interference graph. Those transient structures do not exist in
the final retail executable.

## Existing reusable evidence

In the sibling debugger:

```text
analysis/p3-retail-reachability-v1.json
analysis/frontend-pass-reducers-v1.json
reports/p3-allocation-explanation-v1.json
```

These cover tested behavior for operand order, masks, sign extension, boolean
and switch layout, and one real physical-register-role mismatch. Their
conclusions are scoped to the listed reducers and exact compiler profile; they
are not universal source rules.

## Generated-output policy

Keep local debugger artifacts under:

```text
../mwccps2-debugger/build/
```

Do not commit snapshot directories, compiler binaries, retail ELF data, or
extracted retail bytes. Check in only reusable minimal reducers, deterministic
schema artifacts, tests, and documentation.
