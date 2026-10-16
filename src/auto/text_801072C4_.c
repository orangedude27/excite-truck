// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_8055DEA8;
extern u32 lbl_8055DEA0;
void fn_801072C4(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED110 = fn_801072C4;

void fn_801072C4(void) {
    lbl_8055DEA0 = (u32)&lbl_8055DEA8;
}
