#!/usr/bin/env python3
"""Revert MSL C library queue items from "completed" back to "blocked".

Background: these 24 items were marked completed on 2026-09-04/05 with notes
saying "authored in msl_clones.c" but the authored source does NOT byte-match
the reference asm (ref was compiled at O0 with no inlining, project compiles
at O4 by default which inlines small loops + reorders scheduling). This is a
ledger-cleanup: the count was inflated; the items need real per-TU
compile-config work (-O0 -inline off) to become strict-MATCH candidates.

The 13 functions in msl_clones.c are still authored (correct source
semantics, just not byte-equivalent). They stay in source as review code;
the queue ledger is reset to reflect the actual state.

See AGENTS.md: "Function-level MATCH is not a promotion gate. Promotion
also requires correct section sizes, ownership, placement, and final
DOL bytes."
"""
import os
import json

os.chdir(r'C:\Users\Orangedude27\Desktop\ExciteTruck_Decomp\excite-truck')

state = json.load(open('build/REXE01/decomp_queue_state.json', encoding='utf-8'))
items = state['items']

# Items to revert: any completed item whose note mentions msl_clones.c or
# Petari MSL_C (and was marked in this session).
reverted = []
preserved = []
for k, v in list(items.items()):
    if v['status'] != 'completed':
        continue
    note = v.get('note', '') or ''
    if ('msl_clones.c' in note) or ('Petari MSL_C' in note):
        v['status'] = 'blocked'
        v['note'] = ('BLOCKED: authored in src/runtime/msl_clones.c but does not byte-match '
                     'reference asm. Original was compiled at O0 (full prologues, no inlining); '
                     'project compiles at O4 by default which inlines small loops + reorders '
                     'scheduling. To get strict-MATCH these TUs would need a per-TU compile '
                     'config with -O0 -inline off, which is a real promotion-pass task. '
                     'Source semantics are correct.')
        reverted.append(k)
    else:
        preserved.append(k)

json.dump(state, open('build/REXE01/decomp_queue_state.json', 'w', encoding='utf-8'),
          indent=2, ensure_ascii=False)

print(f'reverted {len(reverted)} items: completed -> blocked')
for k in sorted(reverted):
    print(f'  {k}')
print(f'preserved {len(preserved)} other completed items')
