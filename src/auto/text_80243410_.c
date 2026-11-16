// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern s32 lbl_80498810[];
extern s32 lbl_8055F1E8;
extern s32 lbl_8055F1F0;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
/* Static initializer for this unit's menu/UI state: reset the control block
 * fields and set the default alpha/color value. */
void fn_80243410(void) {
    s32 defaultValue;
    s32 *entryPtr;

    fn_8000D838(&lbl_8055F1E8);

    entryPtr = lbl_80498810 + 1;
    lbl_80498810[0] = 0;
    defaultValue = 0x7B;
    lbl_80498810[1] = defaultValue;
    lbl_80498810[2] = 0;
    lbl_80498810[3] = 0;
    lbl_80498810[4] = 0;

    lbl_8055F1F0 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED418 = fn_80243410;
