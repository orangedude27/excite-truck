// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_8055DDF8;
extern u32 lbl_8055DDE0;
void fn_800D58B8(void);

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED0D4 = fn_800D58B8;

void fn_800D58B8(void) {
    lbl_8055DDE0 = (u32)&lbl_8055DDF8;
}
