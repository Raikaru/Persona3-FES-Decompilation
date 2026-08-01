# Optional MWCCPS2 compiler debugger

> The MWCCPS2 debugger lives in a separate repository and is optional. It is not required
> for this repository's build, link, or verification commands.

The separate `mwccps2-debugger` project can capture selected internal stages of the exact
CodeWarrior PS2 compiler used by this decompilation. Use it to diagnose compiler-artifact
differences after the C implementation is semantically credible and compiles successfully.

If both repositories are checked out under `source/`, they appear as siblings. The sibling
repository contains the full debugger documentation, including getting started, experiment,
P3 workflow, architecture, and troubleshooting guides.

No debugger configuration is tracked here. If you use the optional tool, create a local,
gitignored configuration containing the sibling repository path, exact compiler profile,
local verifier reports, and ignored bundle output. The normal P3 split, build, link, and
verification commands do not read it.

## Supported compiler

The fully validated live profile is:

```text
Release:     mwcps2-3.0.1b210-060308
SHA-256:     286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7
PE timestamp: 0x440f429b
Image base:  0x00400000
P3 flags:    -O2 -Iinclude
```

Do not use b210 breakpoint addresses with a different executable. The debugger fingerprints
the compiler before installing breakpoints.

## When it helps

Use the debugger for a compiled, near-matching function when `fndiff.py` shows:

- the same operations assigned to different registers;
- the same operations in a different order;
- unexplained commutative operand or evaluation-order differences;
- sign or zero-extension placement differences;
- loop-invariant versus loop-local mask or address behavior;
- equivalent boolean or switch source forms producing different blocks; or
- uncertainty about whether a source permutation reaches compiler PCode.

Do not use it as a substitute for reconstructing correct calls, types, branches, constants,
and side effects. Do not use it to explain `COMPILE_ERROR`, a stub, or an unresolved relocation before fixing those problems.

## Required P3 workflow

### 1. Establish the real residual

```powershell
python tools/fndiff.py src/path/file.c FunctionName
python tools/verify.py src/path/file.c
```

Record the non-relocation instruction pairs and check whether the diff includes tail padding.

### 2. Build one small compiler reducer

In the sibling debugger, create `experiments/<question>/` with `experiment.json`,
`baseline.c`, and `variant.c`. Preserve the relevant P3 types, signedness, storage roles,
loop shape, and `-O2` behavior. Change one property per variant. Do not copy an entire P3
translation unit when a small stand-in struct or global reproduces the compiler question.

### 3. Run direct and instrumented compilations

From `../mwccps2-debugger`:

```powershell
python mwccps2_experiment.py experiments/<question> --output build/<question>-run
```

Use a fresh output directory. Reject the evidence if any variant's direct and instrumented object SHA-256 values differ.

### 4. Classify the first semantic difference

Read `build/<question>-run/experiment-summary-v1.json` and use
`earliest_pcode_divergence`, not a raw graph difference:

| First difference | Action |
| --- | --- |
| `codegen_entry` | Change source, frontend, or selector shape: types, casts, expression order, control flow, or address form. |
| After scheduling | Inspect scheduler dependencies, latency, resources, deadlines, critical path, or stable ties. |
| After allocation | Inspect virtual roles, liveness/interference, coalescing, simplify order, masks, and colors. |
| Semantic PCode and object equal | Stop trying that source spelling. It is not a demonstrated b210 object-code lever. |
| PCode equal but object differs | The cause remains after the captured semantic boundary. Do not invent one. |

At normal P3 `-O2`, scheduling breakpoints may not execute. Missing scheduler captures are expected and must not be treated as empty graphs.

### 5. Apply one supported source change

Return to this repository and make the smallest source edit supported by the experiment.
Then rerun the commands above. Only `tools/verify.py` may establish `MATCH`; a debugger
snapshot, experiment object equality, smaller normalized diff, or permuter score is not
sufficient.

## Optional deterministic analysis bundle

Generate a focused verifier report:

```powershell
python tools/verify.py src/path/file.c --json build/target-verify.json
```

From `../mwccps2-debugger`, pass the local configuration you created:

```powershell
python mwccps2_p3_reduce.py --config <local-debugger-config.json> --report ../Persona3-FES-Decompilation/build/target-verify.json --function FunctionName --output build/FunctionName-analysis
```

The bundle records normalized function metadata and fingerprints of supplied
experiment/analysis evidence. It does not edit source or claim a match.

## Relationship to the permuter

The debugger and permuter solve different parts of the problem:

- **Debugger:** localizes the compiler phase and tests whether a source lever changes PCode,
  schedule, allocation, or final object bytes.
- **Permuter:** searches many source variants and scores them against retail.

For a semantically correct residual, inspect `fndiff.py` and `docs/matching.md`, then use a
small debugger reducer when the phase or useful lever is unclear, followed by `tools/permute.py`
or `tools/permute_ast.py`. Extract the minimal clean source change from any hit and rerun
`tools/verify.py`. Debugger evidence can narrow the permuter search; it does not make mutated
source semantically correct automatically.

## Limits of debugger evidence

> Never say the debugger observed retail AST, retail PCode, retail scheduler state, or retail interference graph. Those transient structures do not exist in the final retail executable.

Reusable evidence in the sibling debugger includes:

```text
analysis/p3-retail-reachability-v1.json
analysis/frontend-pass-reducers-v1.json
reports/p3-allocation-explanation-v1.json
```

These cover tested behavior for operand order, masks, sign extension, boolean and switch
layout, and one physical-register-role mismatch. Their conclusions are scoped to the listed
reducers and exact compiler profile; they are not universal source rules.

## Generated-output policy

Keep local debugger artifacts under `../mwccps2-debugger/build/`. Do not commit snapshot directories, compiler binaries, retail ELF data, or extracted retail bytes.
Check in only reusable minimal reducers, deterministic schema artifacts, tests, and documentation.
