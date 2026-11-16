// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F2B8;
extern s32 lbl_8055F2C0;
extern s32 lbl_804989E8[];
void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* Initialize a small global state block and its associated flag word. */
void fn_8024DA88(void) {
#define sInitArg lbl_8055F2B8
#define sStateBlock lbl_804989E8
#define sStateWord lbl_8055F2C0
    s32 value;
    s32 *cursor;

    fn_8000D838(&sInitArg);
    cursor = sStateBlock + 1;
    sStateBlock[0] = 0;
    value = 0x7B;
    sStateBlock[1] = value;
    sStateBlock[2] = 0;
    sStateBlock[3] = 0;
    sStateBlock[4] = 0;
    sStateWord = 0x7F000000;
#undef sInitArg
#undef sStateBlock
#undef sStateWord
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
