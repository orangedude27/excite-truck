# TU Attribution Analysis — recovering the original source-file map

Generated 2026-11-10 from read-only analysis of `orig/REXE01/sys/main.dol`,
`config/REXE01/splits.txt`, `config/REXE01/symbols.txt`, and the reference
disassembly in `build/REXE01/asm/`. No project sources were modified.

Machine-readable output: `docs/attribution/tu_windows.json` (per-window
profiles), `docs/attribution/tu_windows.tsv` (flat table),
`docs/attribution/modules.json` (module grouping).

## Key structural result: the `.ctors` table is a TU boundary map

The DOL `.ctors` table (`0x802ED060..0x802ED630`, 372 pointers) contains one
static-initialization thunk per C++ translation unit that has static objects,
in link order. Verified properties:

1. Entry 0 is the runtime's `__init_cpp_exceptions`; the remaining **371
   targets all lie in game `.text` and are strictly monotonic in table order**
   (= link order = address order).
2. **The thunk is the LAST function of its TU's `.text`.** Statistical test:
   for every thunk, the globals it initializes were cross-referenced against
   the preceding and following auto-units. Result: **97 windows where the
   preceding unit references them, 1 where the following unit does** (270
   windows had no neighboring references either way). Example: thunk
   `fn_80007D54` initializes `lbl_8055D330/D350`; those are referenced by the
   preceding unit `text_800056C8`, never by the following one.
3. dtk already pairs each `.ctors` slot with the auto unit whose `.text`
   starts at the thunk (370/370 exact), so thunk addresses are unambiguous.

**Consequence:** each window

```text
window_i = (end of thunk_{i-1}) .. (end of thunk_i)
```

contains one or more original TUs, and the LAST TU in each window ends
exactly at the window end. 372 windows tile the whole game `.text`
(`0x800049C0..0x802ED060`, 2.91 MB) with no gaps or overlaps. Windows whose
interior shows no ctor anchor may contain additional ctor-less TUs (plain C
files or C++ files without static init); splitting those further requires
call-graph/string evidence, but the outer boundaries are hard.

Window size distribution: 36 windows < 0x100 bytes (data-only TUs), median
~3.4 KB, p75 ~7.8 KB, largest single-TU window ~71.5 KB. One window
(`0x80021948..0x800D58C4`) is the **SDK library gap** — not a TU; see below.

## Explicit original filenames recovered from assert strings

Assert/log strings in `.rodata` name five source files directly, each inside
exactly one window:

| Original file | Window | fns | Evidence string |
|---|---|---:|---|
| `kernel.cpp` | `0x802E1728..0x802E3028` | 30 | `kernel.cpp` |
| `file.cpp` | `0x802E321C..0x802E3DF8` | 32 | `file.cpp` |
| `soundmgr.cpp` | `0x80207960..0x80208A18` | 33 | `soundmgr.cpp`, `SoundManager::*` |
| `mroll.cpp` | `0x8023FE20..0x80243460` | 37 | `mroll.cpp: get_player_info got bad index...` |
| `world/event.cpp` | `0x801EEFC8..0x801EF190` | 6 | `world/event.cpp: No handler for evt type %d` |

The `world/` path prefix implies the engine tree has at least a `world/`
subdirectory. Many more windows carry `Class::method` assert prefixes
(SoundManager, SndVoice/VoiceSound/VoiceSoundMixer, UIContext, CarMgr,
AIDriver, StatHandler, ResourceLoader, DrawListWrapper, QuadTree, FramePool,
ReplayPacketQueue, StackAlloc, CenterLine, RingType, ActionSequenceEvent,
LightStackAllocator, ...) — enough to name most files credibly.

Resource-path strings additionally map the content pipeline: `*.res/`
archives (`race.res`, `common.res`, `ct.res`, `uiaction.res`), `*.val`
config files (`weather.val`, `car_stats.val`, `catchup.val`, `ep_career.val`,
`%s.car/physics.val`, `%s.car/efx.val`, `roadsnd.val`, ...), `.lyt` layouts,
`.gtx`/`.tex` textures, `.sfx`/`.sng` audio.

## Module map (proposed `src/game/` directories)

Windows grouped by evidence into provisional modules. Windows are the atomic
unit; module assignment is a hypothesis to confirm at carve time.

| Module | Range | win | fns | auto B | Content evidence |
|---|---|---:|---:|---:|---|
| `boot` | 0x800049C0..0x80021948 | 28 | 768 | 116K | InterludeOverlay, gameloop, escape, unlock.val, DAVMap, car_stats, Stats/Identity; already-attributed game_menu_init/game_state_check live here |
| *(sdk-gap)* | 0x80021948..0x800D58C4 | 1 | 2656 | 580K | runtime+MSL+revolution+BTE+MetroTRK; 153K already attributed to revolution/*; remaining = SDK-unknown lane, NOT game TUs |
| `nw4hbm` | 0x800D58C4..0x801166C8 | 17 | 962 | 266K | nw4hbm::lyt Group/Picture/TextBox/Window, snd MemorySoundArchive/ChannelManager/SeqSound/StrmSound/WaveSound/Wsd*/TaskManager, ut ResFont/LinkList/streams — ported middleware; sibling projects have reference source |
| `engine` | 0x801166C8..0x8013471C | 23 | 530 | 123K | custom archive ("ARCInitHandle: bad archive format"), prof counters, bg tasks, LightStackAllocator, pools, OptionsFile, MemStream, nw4r::ef block |
| `race` | 0x8013471C..0x801BD628 | 67 | 2546 | 561K | LocalCar(ai), CenterLine, Drone, catchup, BetaRace, PlayerDriver/AIDriver, cardmg, netcar, LapResultTable, deity, ReplayPacketQueue/FramePool, QuadTree, physics/PlaceCar + interleaved JStudio/JAS/PSSystem sound-middleware windows |
| `world` | 0x801BD628..0x801F1C24 | 49 | 1115 | 215K | collide, masslist, surftype, car mesh, sobj.val, ActionSequenceEvent (181 fns), track.gnd/sol/grf, BoostMan, PhysicsWorld, world/event.cpp |
| `hud` | 0x801F1C24..0x80207960 | 13 | 493 | 89K | tire/mesh tuning, J2DBloSaver, SHMainMenu (0x801FC914..0x801FFB08), drivmod, terrain, tunedash, Difficulty, SplitScreen |
| `soundmgr` | 0x80207960..0x80215E68 | 13 | 396 | 59K | soundmgr.cpp, SoundManager, SndVoice/VoiceSound/VoiceSoundMixer, engsnd, roadsnd, TrackMusic, music volumes |
| `ui` | 0x80215E68..0x80265CE0 | 51 | 1538 | 327K | WidgetWindow, UIContext, StringList, layouts (.lyt), font system, Game::MemoryCard::Resource (71.5K window), profile/save, mroll.cpp, ResourceLoader, uiaction.res, unlocks, trophies |
| `camera` | 0x80265CE0..0x8027D264 | 22 | 352 | 96K | camera types, blimpcam, physcam, TV Set, cscript_node, CarTypeIsReal, carstate, %s.car/physics.val, ep_career.val |
| `efx` | 0x8027D264..0x802A4A50 | 21 | 738 | 162K | nw4r::ef windows, %s.car/efx.val, FlipBook, efx-seq, shadow volumes, particle textures |
| `envrender` | 0x802A4A50..0x802C2CAC | 29 | 630 | 123K | weather droplets, birds, water system, sky/sun, terrain materials (gmat/umat), roadbrush, swlmap, unified_material_set |
| `renderer` | 0x802C2CAC..0x802DEAC4 | 18 | 630 | 114K | gxCanvas/gxGetImage, mrModel/modpool, DrawListWrapper, mlist, Vid*, gx sync, drgc/surf, drgc/tex, StackAlloc, blur |
| `platform` | 0x802DEAC4..0x802ED060 | 20 | 414 | 59K | video/%s, kernel.cpp, file.cpp, mem, filecd/DVDRead, vmem, Spu, memcard, Strm*, rjoy (WPAD), NANDWriteAsync, SC config, mp3, homeButton2 |

## Agent-activity overlay (2026-11-10)

306 auto units have uncommitted agent edits. Mapped onto windows: activity is
spread thin (mostly 1–3 units per window; 25 in the SDK gap; hottest game
windows: `race` 50, `ui` 42, `world` 36). **66 windows >2 KB have zero agent
edits in flight**, including all five named-file windows except `kernel.cpp`
(1 unit). Per-window counts are in `tu_windows.tsv` column `agent_active`;
recompute before carving since agents keep claiming.

## Recommended pilots

1. **Mechanism pilot:** `world/event.cpp` window `0x801EEFC8..0x801EF190`
   (6 fns, 456 B, quiet, explicit filename). Smallest possible end-to-end
   validation of the carve workflow.
2. **First substantive batch:** `platform` tail — `kernel.cpp`
   (`0x802E1728..0x802E3028`) + `file.cpp` (`0x802E321C..0x802E3DF8`) +
   `video/%s` (`0x802DEAC4..0x802E1728`). Adjacent, explicitly named, small,
   nearly quiet.
3. **Best porting ROI:** `nw4hbm` module (17 windows, 962 fns, only 2
   authored). Sibling Wii decomps have nw4r lyt/snd/ut reference source; these
   windows likely correspond 1:1 to library .cpp files. Note the existing
   review files `src/game/iy_nw4r_*.cpp` already cover parts of this area and
   are NOT in splits.txt — reconcile during the carve.
4. **soundmgr.cpp + SndVoice cluster** (`0x80207960..0x80215E68`, 13 windows):
   self-contained game module with strong class-name evidence.

## Carve workflow (per window, once surgery is scheduled)

Requires agents paused or a separate worktree — these steps touch
`splits.txt`, `configure.py`, and move content out of live auto units.

1. Pick a window; re-check `agent_active` and the claims table in
   `.decomp/decomp.db` for its functions.
2. Create `src/game/<module>/<name>.cpp` (use recovered filename when known).
3. In `config/REXE01/splits.txt`: add the new file with the window's exact
   `.text` range **plus the `.ctors` slot currently owned by the auto unit
   whose text starts at the window's thunk**, and any `.rodata/.data/.sdata/
   .sbss/extab` ranges dtk attached to those auto units. Remove the covered
   ranges from the `auto/text_*` entries (ranges must partition the DOL
   exactly once — no gaps, no overlaps).
4. In `configure.py`: replace the removed `Object(..., "auto/text_*")` lines
   with `Object(NonMatching, "game/<module>/<name>.cpp")` at the same position
   (link order matters; use the `order:` attribute if ambiguous).
5. Move any already-authored function bodies from the old auto unit files
   into the new file; keep every original `fn_`/`lbl_` symbol as-is (alias
   later, per naming policy).
6. Gate: `python configure.py && ninja && sha1sum orig/REXE01/sys/main.dol
   build/REXE01/main.dol` — must stay `e51685814152f377e5c76a50067d8132e25f672b`.
   NonMatching status means the original extracted objects still provide the
   linked bytes, so the DOL cannot change if the ranges are correct.
7. Re-register source ownership in the decomp.wtf app ("Give them source
   files" workflow) so agent briefs point at the new file.
8. Only after every function in the window strictly matches: consider
   flipping to `Matching` per the promotion checklist in `docs/roadmap.md`.

## Caveats

- Windows are **upper bounds** on TU size: a window without interior evidence
  of further boundaries may still contain several ctor-less TUs (esp. the big
  ones: 0x80218E98..0x8022A5E4 71.5K/397 fns; 0x801166C8..0x801274C8 69K/163
  fns; 0x800F0E64..0x800FD9C8 52K/239 fns). Subdivide with call-graph and
  string-pool locality before naming individual files inside them.
- `extab`/`extabindex` sections (52 auto units) mark exception-using C++ TUs
  and provide additional interior boundaries where present.
- String→window attribution is by code reference (which function loads the
  string), which is reliable; but a window's *name* should still be confirmed
  against behavior when writing the real header.
- The SDK-gap window contains ~580 KB of auto units that are SDK holes
  (SDK-unknown/MetroTRK/KPAD/WPAD-anon etc.), not game files; keep working
  those through the existing SDK lanes.

## Reproduction

Analysis scripts were run ad-hoc; the pipeline is:

1. Parse DOL header sections; read `.ctors` pointers at `0x802ED060+`.
2. Resolve each pointer via `config/REXE01/symbols.txt` function sizes.
3. Parse `config/REXE01/splits.txt` for text ranges and `.ctors` ownership.
4. Build windows; per window collect: function counts (symbols.txt), authored
   status (`build/REXE01/decomp_queue.json`), referenced strings (lbl_* refs
   in `build/REXE01/asm/auto/text_*.s` resolved to C strings in DOL
   `.rodata`/`.data` 0x802ED680..0x8034EC40), mangled-name families, and
   agent activity (`git diff --name-only` mapped through unit start addrs).

## Carve log

Body-only carve pattern: the body auto unit is renamed to the recovered file
(same splits range, same configure.py position/flags); the ctor-thunk unit and
its `.ctors` slot stay in `src/auto/` until a promotion pass resolves C++
static-init source shape. Gate after each batch: `python3 configure.py &&
ninja` + DOL sha1 `e51685814152f377e5c76a50067d8132e25f672b`. Note: the first
`configure.py` run after a rename prints stale "Missing configuration"
warnings for the old unit name; they clear once `ninja` regenerates metadata.

| Date | New file | Original | Range | Status | Notes |
|---|---|---|---|---|---|
| 2026-11-10 | `src/game/world/event.c` | `world/event.cpp` | 0x801EEFC8..0x801EF188 | Matching | pilot; was `auto/text_801EEFC8_.c`; agent edits were zero |
| 2026-11-10 | `src/game/kernel.c` | `kernel.cpp` | 0x802E1728..0x802E3020 | NonMatching | was `auto/text_802E1728_.c`; preserved small uncommitted agent edits |
| 2026-11-10 | `src/game/file.c` | `file.cpp` | 0x802E321C..0x802E3DF0 | NonMatching | was `auto/text_802E321C_.c` |
| 2026-11-10 | `src/game/soundmgr.c` | `soundmgr.cpp` | 0x80207960..0x80208A10 | NonMatching | was `auto/text_80207960_.c`; preserved uncommitted agent edits |
| 2026-11-10 | `src/game/mroll.c` | `mroll.cpp` | 0x8023FE20..0x80243410 | NonMatching | was `auto/text_8023FE20_.c` |

Post-carve TODO per batch: re-register source ownership in the decomp.wtf
app ("Give them source files") so agent briefs point at the new files; the
app DB still references the old `main/auto/text_*` unit paths for these
functions.

