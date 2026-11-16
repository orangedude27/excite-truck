// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055EFB0;
extern s32 lbl_8055EFB8;
extern s32 lbl_80490920[];
void fn_8000D838(void *);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8022A594(void) {
    /* Initialize global UI/state block: reset slots, set default value 0x7B, set color 0x7F000000. */
    s32 value;
    s32 *state;
    fn_8000D838(&lbl_8055EFB0);
    state = lbl_80490920 + 1;
    lbl_80490920[0] = 0;
    value = 0x7B;
    lbl_80490920[1] = value;
    lbl_80490920[2] = 0;
    lbl_80490920[3] = 0;
    lbl_80490920[4] = 0;
    lbl_8055EFB8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED3B8 = fn_8022A594;
