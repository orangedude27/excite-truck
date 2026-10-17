#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80235380(void *);
extern s32 lbl_8055F8BC;
extern s32 lbl_8055F8C0;
extern void fn_802328D4(s32);
void fn_802A7C24(void) {
    fn_802328D4(lbl_8055F8BC);
    lbl_8055F8BC = 0;
    fn_80235380((void *)lbl_8055F8C0);
    lbl_8055F8C0 = 0;
}

void fn_802A7C64(void) {
}

void fn_802A7C68(void) {
    if ((fn_801C5B60() == 0) &&
        ((u32)(*(u32 *)((u8 *)fn_801E87A8() + 4) + 0xFFE80000) != 0x304U)) {
        fn_802A7EEC();
    }
}

