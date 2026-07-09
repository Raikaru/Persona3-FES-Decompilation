# Matching heuristics

Hard-won, reusable source-shaping tricks for making `mwccps2` (`mwcps2-3.0.1b210-060308`,
`-O2 -Iinclude`) reproduce retail codegen byte-for-byte. This complements the
**Fingerprint checklist** and **compiler-artifact blockers** in `AGENTS.md`: that lists the
raw signals; this lists the *source rewrites* that flip a `NONMATCHING` to `MATCH`.

Rules of engagement:

- Every entry is verified by `tools/verify.py` reporting `MATCH`. Confirm before you commit;
  never chain `verify && git commit` past a `MISMATCH` (the `&&` only checks the tool exit code,
  not the match status).
- Diff a single function with `python tools/fndiff.py <file> <fn> | grep -F "!"` (real body diffs;
  empty = body-clean).
- Techniques are **per-function**. The same construct that matches one function walls the next;
  always diff and adjust.
- If only register allocation, instruction scheduling, evaluation-order, FPU-reg choice,
  mask-fold, or commutative-`addu` operand order remains after exhausting these, it is a
  compiler-artifact wall — mark `NONMATCHING` and move on.

---

## Types and the EE ABI

- **Independent int/float argument register files.** The EE/o32-hardfloat ABI fills integer
  args (`$a0..`) and float args (`$f12..`) from *separate* counters. So `f(void*, float)` puts the
  pointer in `$a0` and the float in `$f12` (not `$a1`). Source argument order controls the
  *materialization* order of the two moves. If retail computes `addiu $a0,...` before
  `mov.s $f12,...`, put the pointer first in the C signature.
- **Ghidra mistypes float returns and args as `int`.** A callee that returns `float` shows as
  `undefined4`/`uint`; a `float` parameter shows as `undefined4`. Trust the disassembly, not the
  decompiler: `mov.s $f12`, `swc1`, `lwc1`, `cvt.*` mean float. Declare `float FUN_x();` and
  `void FUN_y(void*, float);` accordingly.
- **`bool` is not a valid type here.** Use `u8`/`u32` for predicate returns.
- **Typed `short`/`char` prototype params defeat mwcc's sign-extension CSE.** Retail re-sign-extends
  a `short`/`char` arg at *every* call site; a bare `(short)expr` gets CSE'd into one extension.
  Declaring the callee `int f(short)` / `void f(char)` forces per-call `dsll32;dsra32` (or `lbu`).
  This unlocked the entire `scrComuCommand` module.
- **`int`, not `char`, for a callee-saved local** whose extension retail defers to a `char`-typed
  callee param (scrComuCommand 35fbd0).
- **`u32`/`int` return, not `u8`,** to drop a spurious `andi 0xff` on the return value (datScript 3111f0).
- **`float` constant with a zero low half** (e.g. `100.0f` = `0x42c80000`) materializes inline as
  `lui;mtc1` with no rodata `lwc1` — declare the callee `void f(float,...)` and pass `100.0f`.
- **By-value 2-float struct param** (`sd`-spill + `lwc1/swc1` copy at the call): pass a
  `typedef struct { f32 x, y; }` by value.
- **12-byte float block copy** (retail loads all three then stores all three:
  `lwc1 f2,f1,f0` / `swc1 f2,f1,f0`) → struct assignment `*(RwV3d*)dst = *(RwV3d*)src` using the
  existing `RwV3d` (`#include "rw/rwplcore.h"`; `{ float x, y, z; }`). Plain per-field float
  assignments interleave `lwc1/swc1` and will not match (gc_pose 24f960/250500).
- **u16 field load width.** A direct `*(u16*)((int)p + off)` emits `lhu`; `*(short*)` emits `lh`.
  Only add a `(u16)`/`(short)` cast on the *other* operand when retail actually emits `andi`/sign-extend.

## Control flow and branch polarity

- **Branch polarity is per-`if` and nests.** Retail out-lines the taken block. Invert the `if` so the
  *fall-through* body matches retail's inline body. Nested `if`s may each need inverting independently
  — inverting only the outer leaves the inner `bnez`/`beqz` mismatched.
- **Early-return inversion.** `if (cond) { body } return X;` where retail out-lines `body` →
  `if (!cond) return X; body; return X;`.
- **Branch-materialized predicate.** `return (x == 0)` → `if (x != 0) return 0; return 1;`.
- **`!(...)` vs `== 0`.** Retail's `sltu $zero,v0; xori 1` needs `!(...)`, not `== 0` (datScript 3111f0).
- **`(~x & N) == 0` stays literal** — do not simplify to `(x & N) == N`.
- **Unconditional else-abort** → `K_ASSERT(0, line)` (folds `if(!0)` to an unconditional call).
- **Init function that asserts a global is already NULL** → `K_ASSERT(sG == NULL, line)`.
- **`slti $at` vs `slti $v0` branch-temp idiom (often a wall).** A `<` comparison against a small
  constant lowers to the `blt`/`bge` pseudo (`slti $at`); a `>=`/`!(x<k)` comparison materializes an
  explicit `slti $v0`. mwcc canonicalizes `>=` and `!(x<k)` to the `$v0` form, so the `$at`-pseudo
  layout is not always reachable while preserving the required inline/out-line arrangement
  (bp_persona 266f60).
- **Assert `field <= N` vs `field < N+1` flips the `slti` dest register.** When the compared value is
  dead after the test (e.g. an `K_ASSERT(field <= 3, line)` on a struct field never reused), retail
  reuses the value's own register (`lw $v1,off(base); slti $v1,$v1,4`). mwcc lowers the literal `<= N`
  through the `$at` pseudo (`slti $at,$v1,4`); rewriting it as the equivalent `< N+1` keeps the value's
  register and matches. If the value *is* reused after the test, retail itself uses `$at` — then keep
  `<= N` (gc_pose 24f960 vs 252060).
- **Switch case-order wall.** mwcc emits switch compares in **numeric-ascending** case order. If retail
  tests a higher case first, no switch or if-chain reproduces it (op_root 265f80: mwcc 8/9/0x11,
  retail 0x11/9/8). When retail *does* check the lowest case first, `switch (e) { case a: case b: ... }`
  reproduces its `beq→body` dispatch with a deferred default.

## Loops

- **Bottom-test loop idiom.** A natural `while (cond) { ... }` reproduces retail's bottom-test layout
  (jump to the condition, body, condition at the bottom). Prefer it over `while (1) { if (!cond) break; }`.
- **Hoist a loop-invariant mask into an explicit local.** mwcc does *not* LICM an `andi`/cast out of a
  loop at `-O2`. Write `int key = param & 0xffff;` (or the cast) *before* the loop and compare against
  `key`; that reproduces retail's single hoisted `andi` (sfl_camera 24d3b0/24d430). `#pragma
  optimization_level 3` enables LICM but also reschedules the prologue — usually worse.
- **Integer-arithmetic copy loops** (`*(u16*)(p + i*2 + 2)` with `p` as `int`) beat the `arr[i+1]`
  commutative-`addu` form (br_root 1f1df0).
- **Raw byte-offset addressing controls `addu` operand order.** `*(T*)((int)base + i*4 + off)` computes
  `base + index` (left-assoc), matching retail's `addu base,index`, where the `arr[i+off]` form emits
  `index + base` (op_res, bcm_main 203360). See also the commutative-`addu` note below.

## Register allocation and caching

- **Cache after the first assert / cache the base pointer.** Functions that reuse a gp-global load it
  once into a saved reg. Mirror with `K_ASSERT(sG != NULL, line); work = sG; ...use work...`. Setters
  that reload the global for each store also need `work = sG;`. Getters/setters that touch the base
  more than once almost always need this even when Ghidra prints the global at each access
  (sfl_cursor 25aa70, sfl_result).
- **Cache a global pointer into a local for indexed RMW stores.** A `static T* g;` accessed as
  `g[i] = g[i] + 1` (indexed read-modify-write) makes mwcc precompute the element address
  (`addiu v1,base,off; sw v0,(v1)`); retail keeps the base and uses `sw v0,off(base)`. Assign
  `T* p = g;` after the assert and use `p[0]`/`p[i]` throughout — mwcc then addresses every access as
  base+offset (bpo_main 252060). Writing `g[i]` directly (even with a temp for the value) keeps the
  precomputed-address form.
- **Cache the *cleared* value for a read-modify-test.** When retail clears one bit and tests another
  that the clear does not touch, it reuses the cleared register: `uVar1 = *g & ~1; *g = uVar1;
  if (uVar1 & 2) ...` reproduces `andi v1,v1,2` (op_wait 26ebf0).
- **Use a fresh temp for a final one-shot result.** If a handle lives in a callee-saved reg across
  several calls, reassigning that same variable for the last call forces a `move s,v0`; assign the
  last result to a *different* short-lived local so it stays in `$v0` (sfl_psel 260a50).
- **Declaration order sets callee-saved allocation.** Natural declaration order (not reverse) tends to
  reproduce retail's `s0/s1` assignment (sfl_result 1f9800). A **param vs surviving-local** fight over
  `s0` is generally a wall (bpRootCreateTasks, several camp creates — permuter-confirmed).

## Read-modify-write and flags

- **Chained flag OR → separate statements.** `*p |= a; *p |= b;` (two RMW statements on the pointer)
  reproduces retail's single-load running-value chain (`lw; ori a; sw; ori b; sw`). A cached
  `v = *p; *p = v|a; *p = v|b;` gets constant-folded to `ori v0,a` / `ori v0,a|b` (cached form).
  Match whichever the disassembly shows (bp_persona 266f60, br_root 1f1b60).

## Globals and addressing

- **Absolute globals outside the gp window** (`0x833xxx`, `0x871exx`, `0x95xxxx`, `0x96xxxx`, read as a
  value via `lui;lw`) → declare `extern T DAT_addr[]; DAT_addr[0]` (HI16/LO16 relocs). A `static`
  would emit GPREL16 and mismatch (datScript `DAT_00957190`, sfl_camera `DAT_00960070`).
- **gp base = `0x7d2cf0`** (`_mips_gp0_value`). This maps `puGpffffbXXX` (gp offset, sign-extended) to
  the absolute `DAT_007ceXXX` it aliases — e.g. `puGpffffb5f8` = `0x7d2cf0 - 0x4a08` = `0x7ce2e8`.
  Use it to avoid declaring a duplicate global for the same variable.

## Commutative-`addu` (frequent wall)

Retail's `addu` operand order for `base + index*scale` is context-dependent and often not
source-reachable. Levers to try, in order:

- The raw byte-offset form (above) flips it in some functions.
- **Inline pointer copy** (permuter-found, btlUnit 285fa0/286130): with `mdl = unit->mdl;` cached,
  `(m = mdl)->attachedWpns[i].flags` flips the condition's `addu` to retail's `index + base`, and
  `(m = unit->mdl)->attachedWpns[i].wpnMdl->flags |= x` does the same for a store path, while a
  plain `mdl->attachedWpns[i]` emits `base + index`.
- **Comma struct-copy for load order** (permuter-found, scrTraceCode 35ebf0):
  `(0, p[i].unionField).member` copies the whole operand word before extracting the member,
  reproducing retail's `lw`-then-`lh` order where plain `.member` access reorders the loads.
  A plain two-step temp (`str = base; str += off;`) is enough in simpler cases (CodeFunc_PushSTR).

When no order matches after trying these, drop the function. Indexed getters/setters are the
usual victims. Before dropping, give `tools/permute_ast.py` 120s — it found every one of the
levers above.

## Commutative-`mul.s` (float, frequent wall)

The float analog of commutative-`addu`. For `fresh * invariant` — e.g. `(a - b) * scale` where
`scale` is a loop-invariant `div.s` result forced into a higher FPU reg (`$f2`) and the subtraction
lands in the lowest free reg (`$f0`) — mwcc canonicalizes to *invariant-first* (`mul.s $f0,$f2,$f0`)
while retail emits *fresh-first* (`mul.s $f0,$f0,$f2`). Neither `(a-b)*scale` nor `scale*(a-b)` in the
source changes it; the operand registers are fixed by allocation. Drop when only this remains
(gc_pose 250a30 — otherwise a full byte match).

## Process

- **Disassemble before modeling any multi-call handler** (`disassemble_function`). Resolve ambiguous
  arg types (`(short)` vs raw, `lhu` vs `andi`, literal-const reuse, `char`/`u8` conversion, float vs
  int, branch polarity, `-1` width) from the real `move`/`dsll32`/`andi`/`lbu`/`mov.s` sequence rather
  than trusting the decompiler.
- **`__FILE__` deanonymization** is the scalable way to home a function: `list_data_items_by_xrefs`
  → module `__FILE__` string → `get_xrefs_to` that string → cluster of that module's functions →
  assign by gp-global identity. Assert `__FILE__` addresses drift; confirm the real address from a
  decompiled `FUN_0019d3f0(addr,line)` or `read_memory`.
- **Extend partial modules.** Pick a `.c` file that already has matches, pull its `__FILE__` cluster,
  and harvest the unharvested neighbours (getters, flag-checks, cleanups, copy-loops, loaders,
  destroys). These accessors match far more reliably than update/render functions.
- **Grep before writing a new module file** (`git ls-files '*name*'` + grep the addresses). A made-up
  directory causes duplicate definitions; an existing file whose name matches the task-name string is
  a safe home.
- **Camp task lifecycle.** `create` = `RwCalloc/RwMalloc` + `kwlnTaskCreate(parent,"<Name>",prio,
  update,destroy,workData)` + field inits + `if (x==NULL) return NULL;`. `destroy` = conditional frees
  + `RwFree(workData)`. Destroys almost always match; a `create` with a call *after* the create hits
  the param-vs-local `s0` wall.

## Known walls (mark NONMATCHING, do not fight)

Register allocation; param-vs-local `s0/s1`; instruction scheduling / subexpression evaluation order;
FPU-register allocation; u16-mask propagation (retail re-masks per use, mwcc elides); switch
case-order; the `slti $at` branch-temp idiom; commutative-`addu` and commutative-`mul.s` operand
order; render/float-math update functions (`(*DAT_00960090)()` indirect draw calls, per-frame vector
transforms).
