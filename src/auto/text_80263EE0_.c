// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

extern void *lbl_8055F428;
extern s32 lbl_8055F430;
extern s32 lbl_80498F40[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80263EE0(void) {
    /* Initialize a state block and its associated word. */
#define sStateBlock lbl_80498F40
#define sStateWord  lbl_8055F430

    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F428);
    p = sStateBlock + 1;
    sStateBlock[0] = 0;
    v = 0x7B;
    sStateBlock[1] = v;
    sStateBlock[2] = 0;
    sStateBlock[3] = 0;
    sStateBlock[4] = 0;
    sStateWord = 0x7F000000;

#undef sStateBlock
#undef sStateWord
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED474 = fn_80263EE0;
