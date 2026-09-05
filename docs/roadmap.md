# Excite Truck Decomp Roadmap

This is the short day-to-day roadmap. `PROJECT_STATUS.md` remains the deep
technical record for blockers, structural facts, and deferred promotion notes.
For a concrete starter list, see `docs/next_targets.md`.

## Current strategy

We are doing a **soft restart**, not throwing away the existing project.

- Preserve the byte-identical linked DOL.
- Prefer clean, attributable source over large messy promotion attempts.
- Use `NonMatching` / review TUs for credible recovered source when ownership is
  unresolved.
- Treat promotion as a scheduled pass, not the default work mode.
- Keep blocker notes short and move on when exact MWCC scheduling or shared-data
  ownership becomes disproportionately expensive.

## Current baseline

Last verified during the roadmap cleanup:

```text
ninja: passes
check_hash.py: OK byte-identical
units fully matched: 103/929
all code: 81,352 / 3,050,236 bytes
SDK code: 81,352 / 156,600 bytes
```

Regenerate live numbers with:

```sh
ninja
python ../python_tools/check_hash.py
python ../python_tools/decomp_queue.py refresh
python ../python_tools/decomp_queue.py summary
python ../python_tools/decomp_quantification.py
```

## Work lanes

### Lane 1 — small library/runtime functions

Use this lane when you want concrete progress with likely external references.
Start with small named functions surfaced by the queue, especially MSL/runtime
and math/string/io helpers.

Good target examples from the current queue:

- `wcstombs`
- `round_decimal`
- `vsnprintf`, `snprintf`, `sprintf`, `sscanf`
- `qsort`
- `strcpy`, `strcmp`
- `atof`
- `ceil`, `cos`, `floor`, `frexp`

### Lane 2 — bounded SDK holes

Use this lane for short subsystem batches. Prefer modules with few remaining
functions and clear sibling-project references.

Current bounded targets:

- `MetroTRK` — 19 todo
- `KPAD` — 6 todo
- `AXFX` — 3 todo
- `VI` — 4 todo
- `EUART` — 1 todo
- `WENC` — 1 todo
- small remaining `DVD`, `DSP`, `NWC24`, `NAND` items only when not blocked by
  ownership/promotion issues

### Lane 3 — game attribution and naming

Use this lane to make the project feel less anonymous before attempting large
gameplay decompilation.

- Name authored `fn_XXXXXXXX` functions only when supported by callers, strings,
  sibling code, or clear behavior.
- Keep the original `fn_XXXXXXXX` symbol and append readable aliases; do not
  delete symbol entries.
- Focus first on the bootstrap/menu cluster and authored WPAD helper comments.

### Lane 4 — deliberate promotion passes

Promotion is not day-to-day cleanup. Start one only when the return is worth the
cost and the owning ranges/data are well understood.

Promotion pass checklist:

1. Confirm function order and neighboring auto symbols.
2. Inspect all emitted sections in `build/REXE01/src/<tu>.o`.
3. Map all shared data providers and external users.
4. Preserve original placeholder aliases.
5. Run `python configure.py`, `ninja`, `python ../python_tools/check_hash.py`,
   and `git diff --check`.

## Do-not-touch unless explicitly scheduled

These clusters are known time sinks. Leave them alone during normal queue work.

- WUDCB layout drift.
- AX aux / AXVPB shared-data promotion.
- GX symbol misattribution around getter names.
- WPAD anonymous HID helpers where source-shape tuning is the only remaining
  obstacle.
- NANDCore pooled-data/linker-placement promotion.
- DVD/DSP/AI callback ownership carve.

## How to choose the next task

```sh
python ../python_tools/decomp_queue.py refresh
python ../python_tools/decomp_queue.py next --limit 20
python ../python_tools/decomp_queue.py show <item>
```

Then classify the task into one of the lanes above. If it falls into the
Do-not-touch list, skip it and record/keep the blocker rather than fighting it.
