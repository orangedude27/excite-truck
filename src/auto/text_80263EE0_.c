// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
#include "macros.h"
extern void *lbl_8055F428;
extern s32 lbl_8055F430;
extern s32 lbl_80498F40[];
typedef void (*funcptr_t)(void);
void fn_8000D838(void *);
void fn_80263EE0(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED474 = fn_80263EE0;

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80263EE0(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F428);
    p = lbl_80498F40 + 1;
    lbl_80498F40[0] = 0;
    v = 0x7B;
    lbl_80498F40[1] = v;
    lbl_80498F40[2] = 0;
    lbl_80498F40[3] = 0;
    lbl_80498F40[4] = 0;
    lbl_8055F430 = 0x7F000000;
}
