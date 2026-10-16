// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern void *lbl_8055EA10;

void fn_801E1250(s32 arg0, s8 arg1) {
    u8 *p = (u8 *)lbl_8055EA10;
    if (p == 0) return;
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
    p += 0x30;
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
}

s32 fn_801E137C(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_801E1510(s32 *arg0, s32 arg1) { return *arg0 + arg1 * 0x1C; }

void fn_801E1684(void) {

}

void fn_801E1688(void) {

}

void fn_801E1868(void) {

}

