# Decompilation Workflow

This is the practical loop for day-to-day work. See `docs/roadmap.md` for task
selection and `PROJECT_STATUS.md` for deep blocker notes.

## Baseline safety

Run from the repository root:

```sh
ninja
python ../python_tools/check_hash.py
git status --short
```

Do not start editing on top of unexplained local changes.

## Pick one bounded target

```sh
python ../python_tools/decomp_queue.py refresh
python ../python_tools/decomp_queue.py next --limit 20
python ../python_tools/decomp_queue.py show <item>
```

Before authoring source, identify:

- function address and exact boundaries;
- subsystem / likely original TU;
- current linked owner or auto-unit provider;
- callers, callees, strings, and referenced data;
- whether this is normal source work or a promotion-only problem.

## Research

Useful commands:

```sh
python ../python_tools/search_refs.py <symbol-or-keyword>
python ../python_tools/ghidra_decompile_unit.py <auto-unit-or-address>
python ../python_tools/game_data_ownership.py <address-or-symbol>
```

Preferred evidence order:

1. REXE01 assembly / Ghidra behavior.
2. Callers, strings, and data references in this game.
3. Sibling decomp projects: ogws, Rhae, pik2wii, mscharged-decomp, then other
   RVL/DOL SDK references.

Sibling source is guidance, not authority.

## Author source

Use the cleanest destination available:

- linked `Matching` TU only when it is truly the linked owner;
- `NonMatching` / review TU when source coverage is useful but ownership is
  unresolved;
- temporary workspace trial only for experiments that should not enter the
  project yet.

When adding aliases, keep the original `fn_XXXXXXXX` symbol and append a
same-address readable alias rather than deleting anything.

## Check one function

```sh
python ../python_tools/match_check.py src/<tu>.c \
  --ref build/REXE01/asm/<reference>.s \
  --fn <FunctionName> \
  --strict-immediates
```

If the function lives inside an auto-unit, use that auto-unit `.s` as the
reference. Function-level match is useful evidence but does not prove linked
ownership.

## Classify the result

Use one of these outcomes:

- `MATCH` — strict function comparison matches.
- `FUZZY` — semantics are correct and differences are source-shape/scheduling
  only.
- `BLOCKED` — needs struct layout, data ownership, helper shape, or symbol
  correction.
- `UNATTRIBUTED` — behavior is understood but the original TU/owner is not.

Record only concise evidence: instruction counts, first meaningful difference,
and the next concrete blocker. Avoid long experiment logs.

## Final checks for normal source work

```sh
ninja
python ../python_tools/check_hash.py
git diff --check
```

The linked DOL should remain byte-identical unless you are intentionally doing a
promotion pass.

## Promotion warning

Promotion is a separate task. Before moving auto-unit bytes into compiled source,
confirm section sizes on `build/REXE01/src/<tu>.o`, not `obj/` or `asm/obj/`.
Check all data ownership and neighboring function boundaries first.
