// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <macros.h>

extern void *lbl_8055F3C8;
extern s32 lbl_8055F3D0;
extern s32 lbl_80498EE8[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8025FE3C(void) {
    /* Initialize a small global state block and its associated flag word. */
#define stateBlock lbl_80498EE8
#define stateWord  lbl_8055F3D0
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F3C8);
    p = stateBlock + 1;
    stateBlock[0] = 0;
    v = 0x7B;
    stateBlock[1] = v;
    stateBlock[2] = 0;
    stateBlock[3] = 0;
    stateBlock[4] = 0;
    stateWord = 0x7F000000;
#undef stateBlock
#undef stateWord
}
