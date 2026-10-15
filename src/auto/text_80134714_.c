// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "macros.h"

extern char lbl_8055E090[4];
extern void fn_8000D838(void *);

void fn_80134714(void) {
    fn_8000D838(lbl_8055E090);
}

#pragma section ".ctors$00"
DECL_SECTION(".ctors$00")
static void (*__ctors_80134714)(void) = fn_80134714;
