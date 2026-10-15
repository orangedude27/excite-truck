// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern void *lbl_8055E130;

void fn_8013A1E0(void) {
    fn_8000D838(&lbl_8055E130);
}

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00") funcptr_t D_802ED198 = fn_8013A1E0;
