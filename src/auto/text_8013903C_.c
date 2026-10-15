// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern char lbl_8055E0F8[4];
void fn_8000D838(void *arg0);

void fn_8013903C(void) {
    fn_8000D838(lbl_8055E0F8);
}

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00")
funcptr_t D_802ED18C = fn_8013903C;
