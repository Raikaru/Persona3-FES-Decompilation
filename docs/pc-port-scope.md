# PC Port: Decompilation Scope

This document identifies what must be decompiled to enable a PC port of Persona 3 FES and
what can be replaced. For current progress, see the [README](../README.md) badge or run
`python tools/progress.py`; this document intentionally does not repeat progress figures.

The core distinction is the repo's completion criteria (ROADMAP.md): byte-exact retail
identity, the right goal for archival decompilation. A PC port has a different bar. It
needs every piece of game logic in compilable C with correct semantics, but only needs
middleware identified, not matched. Byte-exactness is the gold standard for proving
game-code semantics. For middleware, matching is wasted effort because a port replaces
the backend regardless.

## Tier 1: Game code, decompile fully (byte-exact preferred)

Everything unique to P3 belongs here. This is the irreplaceable part and where matching
effort should stay.

Tier 1 includes:

- `src/Script`: Flow-script VM (`scrScriptProcess`, opcode commands).
- `src/Kernel`: `h_malloc`, `h_memcard` (save system), and Kwln.
- `src/Main`: Social link system, OpEd, game support, battle UI (Cmd/Data/Panel/Result),
  `main.c`, and `admini.c`.
- `src/Battle`: Battle core, including action, camera, order, target, packet, formation,
  boss, and support.
- `src/Kosaka`: Field and world systems, including sequences, commands, windows, vpad,
  and footsteps.
- `src/Scene`: Scene manager and resource manager.
- `src/Event`: Event and cutscene systems, including messages, menus, effects, the PM-file
  reader, and load/save.
- `src/Camp`: Camp and pause-menu systems for equipment, items, personas, skills, status,
  and social links.
- `src/Graphics`: Primitive batching and model/effect paths whose semantics the port needs.
- `src/Yajima`: Small utility and runtime libraries.

Root-file split:

- **Tier 1 game files:** `comuData.c`, `comuEventExec.c`, `comuSasoi.c`,
  `comuTimerSequence.c`, `datCalendar.c`, `itfMesManager.c`, `itfPanel.c`,
  `nmCmdList.c`, `nmSequence.c`, `nmlist.c`, `code2.c`, `temporary.c`,
  `frFont*.c`, `frTagTable.c`.
- **Tier 3 platform wrappers:** `crt0.c`, `libc_core.c`, `libcdvd.c`, `h_cdvd.c`,
  `h_pad.c`, `h_snd.c`, `h_sfdply.c`, `h_cursor.c`, `h_dbprt.c`, `h_fade.c`,
  `h_maestro.c`, `h_chrdsp.c`, `dds3Process.c`, `fmGslCont.c`.

## Tier 2: Binding layer, decompile for semantics, not bytes

These call the RenderWare API. A port re-binds them against a replacement backend. They
must be understood, including signatures, argument meaning, and call order. Existing
matching work has largely pinned these details:

- `src/Kosaka/k_draw.c`, `k_clump.c`, `k_view.c`: the main RW call sites for clump/world
  rendering and the camera.
- `src/Graphics/`: primitive batching and model/effect paths.
- `src/Kosaka/Field/`: field-rendering paths.
- Existing `src/rw` matches: ground-truth documentation of the RW API surface used by the
  game, including rpworld sectors/clumps, rtanim keyframe interpolation, rt2d sprites,
  rtquat math, and animation timing.

The deliverable from this tier is a complete RW API call-site inventory. Record every
`FUN_004…`, `Rp*`, `Rt*`, and `Rw*` callee reachable from Tier 1 code, with its type. Do
not treat this inventory as a byte-matching target.

## Tier 3: Middleware and platform, replace, do not decompile

Byte-matching these components is wasted effort for a port. Several are also not
MWCC-matchable at all because they are vendor toolchain objects, including rwcore's
Deci2Call/SIO wrappers and the cri/libm forwarder stubs.

**Policy:** Middleware under `src/rw` is identified, not matched. Existing matches remain
semantic ground truth. The repo-wide no-asm rule holds; middleware remains compiling C
reference code. Remaining RW work is Tier 2 inventory only: signatures and semantics of
RW entry points reachable from game code, not byte-matches.

| Subsystem | Replacement strategy |
|---|---|
| `src/rw` | RenderWare 3.x becomes a clean-room reimplementation (librw-style) or custom renderer behind the Tier 2 inventory. Pin the RW SDK version from ELF sections and strings first. |
| `src/cri` | CRI ADX audio uses open ADX decoders such as VGAudio or ffmpeg behind an `h_snd`-compatible interface. Most trivial stubs do not represent decoder logic. |
| `src/sce` | Sony SDK components (sifrpc, mc, loadfile, iopheap, libmc2) become platform shims. |
| Root platform wrappers | `crt0` uses the host runtime; `h_pad` uses SDL or another input layer; `h_cdvd` and `libcdvd` use a filesystem; `h_snd` and `h_maestro` use an audio backend; `h_sfdply` uses a modern Sofdec/SFD decoder or re-encoded movies; `h_memcard` uses save files; `h_fade`, `h_cursor`, and `h_chrdsp` become small rewrites over the new renderer; `libc_core` and `libm` use the host libc. |

## Non-code prerequisites (not decompilation, but blocking)

1. **RW version pin:** identify the exact RenderWare SDK version from ELF sections and
   embedded strings. This determines the replacement API generation.
2. **Asset pipeline:** model, texture, animation, and container formats; script bytecode
   (`.bf`, consumed by `scrScriptProcess`); message archives (via `itfMesManager`);
   cutscene PM packages (`mt_evtPMFileReader`); ADX audio; and SFD movies. Decompilation
   does not produce these assets, so they need extractors and converters.
3. **Save format:** pin `h_memcard` semantics, then implement host-side serialization.

## Bottom line

Port-blocking decompilation work is Tier 1 plus Tier 2 semantics. Tier 3 should remain
identified and typed, not matched, so the port can focus on game logic and binding semantics.
