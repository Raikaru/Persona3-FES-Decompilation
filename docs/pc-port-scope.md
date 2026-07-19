# PC Port — Decompilation Scope

What actually needs to be decompiled to enable a PC port of Persona 3 FES, and
— just as important — what does not. Counts are verifier measurements from
2026-07-18 (`build/wip/v_repo2.json`, 13,808 function windows).

The core distinction: the repo's completion criteria (ROADMAP.md) target
byte-exact retail identity, which is the right goal for *archival* decomp. A PC
port has a different bar — it needs every piece of game logic in compilable C
with correct semantics, but only needs middleware *identified*, not matched.
Byte-exactness is the gold standard for proving game-code semantics; for
middleware it is wasted effort, since a port replaces the backend regardless.

## Tier 1 — Game code: decompile fully (byte-exact preferred)

Everything unique to P3. This is the irreplaceable part and where matching
effort should stay. Current state:

| Subsystem | MATCH / total | % | Contents |
|---|---|---|---|
| `src/Script` | 113 / 115 | 98.3% | Flow-script VM (`scrScriptProcess`, opcode commands) — effectively done |
| `src/Kernel` | 126 / 138 | 91.3% | `h_malloc`, `h_memcard` (save system), Kwln |
| `src/Main` | 1,442 / 1,808 | 79.8% | Social link system, OpEd, game support, battle UI (Cmd/Data/Panel/Result), `main.c`, `admini.c` |
| `src/Battle` | 1,177 / 1,562 | 75.4% | Battle core: action, camera, order, target, packet, formation, boss, support |
| `src/Kosaka` | 517 / 786 | 65.8% | Field/world system: sequences, commands, windows, vpad, footsteps |
| `src/Scene` | 66 / 129 | 51.2% | Scene manager, resource manager |
| `src/Event` | 327 / 1,273 | 25.7% | Event/cutscene system (`mt_evt*`: messages, menus, effects, PM-file reader, load/save) |
| `(root)` game files | ~300 / 1,027 | 29.2% | Mixed — see split below |
| `src/Camp` | 68 / 298 | 22.8% | Camp/pause menu (`_h_camp_*`: equip, item, persona, skill, status, comu) |
| `src/Graphics` | 162 / 750 | 21.6% | `primitive.c`, Effect/, Model/ — rendering glue *semantics* needed |
| `src/Yajima` | 59 / 317 | 18.6% | Small utility/runtime lib |

Root-file split (both live in the `(root)` count above):

- **Tier 1 game files:** `comuData.c`, `comuEventExec.c`, `comuSasoi.c`,
  `comuTimerSequence.c`, `datCalendar.c`, `itfMesManager.c`, `itfPanel.c`,
  `nmCmdList.c`, `nmSequence.c`, `nmlist.c`, `code2.c`, `temporary.c`,
  `frFont*.c`, `frTagTable.c`.
- **Tier 3 platform wrappers** (see below): `crt0.c`, `libc_core.c`,
  `libcdvd.c`, `h_cdvd.c`, `h_pad.c`, `h_snd.c`, `h_sfdply.c`, `h_cursor.c`,
  `h_dbprt.c`, `h_fade.c`, `h_maestro.c`, `h_chrdsp.c`, `dds3Process.c`,
  `fmGslCont.c`.

## Tier 2 — Binding layer: decompile for semantics, not bytes

These call the RenderWare API; a port re-binds them against a replacement
backend. They must be *understood* (signatures, argument meaning, call order),
which the matching campaign has largely pinned already:

- `src/Kosaka/k_draw.c`, `k_clump.c`, `k_view.c` — the main RW call sites
  (clump/world rendering, camera).
- `src/Graphics/` — primitive batching, model/effect paths.
- `src/Kosaka/Field/` — field rendering paths.
- The 235 already-matched `src/rw` functions — these double as ground-truth
  documentation of the RW API surface the game actually uses (rpworld
  sectors/clumps, rtanim keyframe interpolation, rt2d sprite path, rtquat
  math, animation timing).

Deliverable from this tier is a **complete RW API call-site inventory**
(every `FUN_004…`/`Rp*`/`Rt*`/`Rw*` callee reachable from Tier 1 code, typed),
not byte-matches.

## Tier 3 — Middleware and platform: replace, do not decompile

Byte-matching these is confirmed wasted effort for a port. Several are also
*not MWCC-matchable at all* (vendor toolchain objects — documented walls in
rwcore's Deci2Call/SIO wrappers and the cri/libm forwarder stubs).

**Decision (2026-07-18):** matching effort on `src/rw` is *stopped*. The ~235
verified matches are kept as semantic ground truth; everything else stays as
compiling C reference bodies (no inline-asm stubs — the repo-wide no-asm rule
holds; the seven `.word` stubs introduced during the window sweep were
reverted to C). Remaining rw work is Tier 2 inventory only: signatures and
semantics of RW entry points reachable from game code, not byte-matches.

| Subsystem | MATCH / total | Replacement strategy |
|---|---|---|
| `src/rw` | 209 / 1,683 (12.4%) | RenderWare 3.x → clean-room reimplementation (librw-style) or custom renderer behind the Tier 2 inventory. Needs the RW SDK version pinned from ELF sections/strings first. |
| `src/cri` | 806 / 3,471 (23.2%) | CRI ADX audio → existing open ADX decoders (VGAudio/ffmpeg) behind an `h_snd`-compatible interface. Note: most of the 806 "matches" are nullsub/trivial stubs, not real decoder code. |
| `src/sce` | 43 / 451 (9.5%) | Sony SDK (sifrpc, mc, loadfile, iopheap, libmc2) → platform shims. |
| Root platform wrappers | (in root count) | `crt0` → host runtime; `h_pad` → SDL/other input; `h_cdvd`/`libcdvd` → filesystem; `h_snd`/`h_maestro` → audio backend; `h_sfdply` → Sofdec/SFD movie playback (replace with a modern decoder or re-encode); `h_memcard` (Kernel) → save files; `h_fade`/`h_cursor`/`h_chrdsp` → small rewrites over the new renderer; `libc_core`/`libm` → host libc. |

## Non-code prerequisites (not decompilation, but blocking)

1. **RW version pin** — identify the exact RenderWare SDK version from ELF
   sections/embedded strings; determines the replacement API generation.
2. **Asset pipeline** — model/texture/animation container formats, script
   bytecode (`.bf`, consumed by `scrScriptProcess`), message archives
   (via `itfMesManager`), cutscene PM packages (`mt_evtPMFileReader`), ADX
   audio, SFD movies. Decompilation does not produce these; they need
   extractors/converters.
3. **Save format** — `h_memcard` semantics pinned, then a host-side
   serialization.

## Bottom line

Port-blocking decomp work = Tier 1 + Tier 2 semantics: roughly **8,200 of the
13,808 windows**, of which ~4,400 already match (driven by Main/Battle/Script/
Kernel). Tier 3 (~5,600 windows across rw/cri/sce/platform wrappers) should be
frozen at "identified and typed," not matched — that alone redirects ~40% of
the total function mass off the critical path.
