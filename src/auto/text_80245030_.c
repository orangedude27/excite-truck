// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern s32 lbl_80498878[];
extern void *lbl_8055F228;
extern s32 lbl_8055F230;
void fn_8000D838(void *);
void fn_80245030(void);

#include <macros.h>

DECL_SECTION(".ctors") funcptr_t D_802ED424 = fn_80245030;

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80245030(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F228);
    p = lbl_80498878 + 1;
    lbl_80498878[0] = 0;
    v = 0x7B;
    lbl_80498878[1] = v;
    lbl_80498878[2] = 0;
    lbl_80498878[3] = 0;
    lbl_80498878[4] = 0;
    lbl_8055F230 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
