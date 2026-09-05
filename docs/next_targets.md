# Next Targets

This is a concrete starter list for the soft-restart workflow. Pick one small
batch, finish or block it with evidence, then refresh the queue.

## Batch A — MSL/runtime momentum

These are good first targets because they are named, bounded, and likely have
reference implementations in MSL/libc/sibling projects.

1. `wcstombs@80024C54`
2. `round_decimal@800260E4`
3. `vsnprintf@80027374`
4. `snprintf@80027478`
5. `sprintf@80027550`
6. `qsort@80027620`
7. `__StringRead@80028BA4`
8. `sscanf@80028C34`
9. `strcpy@80028CFC`
10. `strcmp@80028E78`

## Batch B — small math/library functions

1. `atof@8002A4AC`
2. `fwide@8002AF04`
3. `__write_console@8002AF88`
4. `__kernel_cos@8002CB6C`
5. `__kernel_sin@8002E388`
6. `ceil@8002E8E0`
7. `cos@8002EA4C`
8. `floor@8002EB20`
9. `frexp@8002EC64`

## Batch C — bounded SDK modules

Use the queue to inspect each item before editing.

```sh
python ../python_tools/decomp_queue.py show <item>
```

Suggested subsystems:

- `MetroTRK` remaining functions.
- `KPAD` remaining functions.
- `AXFX` remaining functions.
- `VI` small functions, excluding known blocked/promotion cases.
- `EUART` / `WENC` one-off functions.

## Batch D — naming pass

Name only when there is evidence. Keep original `fn_XXXXXXXX` symbols and append
same-address aliases.

Start with:

- bootstrap/menu functions in `src/game/game_menu_init.c`;
- authored placeholder WPAD helpers in `src/revolution/WPAD/WPAD.c`;
- any placeholder whose behavior is obvious from strings/callers.

## Avoid for now

Do not start these unless explicitly doing a focused investigation:

- WUDCB layout drift;
- AX aux / AXVPB promotion;
- GX getter symbol misattribution;
- WPAD anonymous HID source-shape tuning;
- NANDCore data/promotion;
- DVD/DSP/AI callback carve.
