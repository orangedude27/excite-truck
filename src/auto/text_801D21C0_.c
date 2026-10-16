// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80438958[];
extern s32 lbl_8055E930;
extern s32 fn_801D2BF4(s32 *, s32 *);
extern void fn_802C6CF8(s32);
extern s32 fn_800241DC(s32 *, void *, s32, s32, void *);
extern void qsort(void *, s32, s32, void *);

#pragma dont_inline on
void fn_801D2B94(void) {
    u8 *var_r31;
    s32 var_r30;
    s32 temp;

    var_r31 = lbl_80438958;
    var_r30 = 0;
    while (var_r30 < lbl_8055E930) {
        temp = *(s32 *)(var_r31 + 0x6C);
        if (temp != -1) {
            fn_802C6CF8(temp);
        }
        var_r31 += 0x4C4;
        var_r30 += 1;
    }
}
#pragma dont_inline off

s32 fn_801D2BF4(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

#pragma dont_inline on
void fn_801D2C04(void) {
    qsort(lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}

s32 fn_801D2C20(s32 arg0) {
    s32 sp8;

    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    return fn_800241DC(&sp8, lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}
#pragma dont_inline off

void fn_801D2210(void) {
    fn_801D2B94();
}
