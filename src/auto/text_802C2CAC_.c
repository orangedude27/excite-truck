// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8012C4D8(void);

extern s32 lbl_8055FC00;
void fn_802C2FC4(void) {
    ((void (*)(void))fn_8012C4D8)();
}

void fn_802C2FC8(void *arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    s32 var_r10 = *(s32 *)((u8 *)arg0 + 8);
    s32 var_r0;
    *(s32 *)((u8 *)arg0 + 0x14) = (s32)(arg1 & ((arg1 >> 31) - 1));
    *(s32 *)((u8 *)arg0 + 0x18) = (s32)(arg2 & ((arg2 >> 31) - 1));
    if (arg3 < var_r10)
        var_r10 = arg3;
    var_r0 = *(s32 *)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)arg0 + 0x1C) = var_r10;
    if (arg4 < var_r0)
        var_r0 = arg4;
    *(s32 *)((u8 *)arg0 + 0x20) = var_r0;
}

void fn_802C3014(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)((u8 *)arg0 + 0xC);
}

s32 fn_802C3034(s32 value) {
    s32 old;

    old = lbl_8055FC00;
    lbl_8055FC00 = value;
    return old;
}

s32 fn_802C3044(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 2);
}

void fn_802C4C80(void* arg0) {
    if (arg0 == NULL) {
        return;
    }
    fn_8012C4D8();
}

s32 fn_802C4EE4(s32* arg0) {
    if (arg0 != NULL) {
        return *arg0;
    }
    return 0;
}

s32 fn_802C4EFC(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[1];
    }
    return 0;
}

s32 fn_802C4F14(s32* arg0) {
    if (arg0 != NULL) {
        return arg0[4];
    }
    return 0;
}

int fn_802C501C(void) {
    return 8;
}
