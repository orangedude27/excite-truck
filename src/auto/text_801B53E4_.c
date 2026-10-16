// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stddef.h>

extern f32 lbl_80562690;
extern void fn_8002F6AC(void *(*)(void *, s32));
extern void fn_80128668(void *);

s32 fn_801B53E4(void *arg0) {
    s32 var_r5;

    var_r5 = 0;
    if (((u32)(*(s32 *)((u8 *)arg0 + 0x18) + 0xBDB10000) == 0x5820U) &&
        (*(s32 *)((u8 *)arg0 + 0x20) == 0x6E)) {
        var_r5 = 1;
    }
    return var_r5;
}

void fn_801B5410(void *arg0, void *arg1, void *arg2) {
    void *temp_r6;
    f32 temp_f3;

    temp_r6 = *(void **)((u8 *)arg0 + 0xC);
    temp_f3 = *(f32 *)((u8 *)arg0 + 0x2C);
    *(f32 *)arg1 = *(f32 *)((u8 *)temp_r6 + 0x24) +
                   (*(f32 *)((u8 *)temp_r6 + 0x18) * temp_f3);
    *(f32 *)((u8 *)arg1 + 4) = *(f32 *)((u8 *)temp_r6 + 0x28) +
                   (*(f32 *)((u8 *)temp_r6 + 0x1C) * temp_f3);
    *(f32 *)((u8 *)arg1 + 8) = *(f32 *)((u8 *)temp_r6 + 0x2C) +
                   (*(f32 *)((u8 *)temp_r6 + 0x20) * temp_f3);
    temp_f3 = -*(f32 *)((u8 *)arg0 + 0x2C);
    *(f32 *)arg2 = *(f32 *)((u8 *)temp_r6 + 0x24) +
                   (*(f32 *)((u8 *)temp_r6 + 0x18) * temp_f3);
    *(f32 *)((u8 *)arg2 + 4) = *(f32 *)((u8 *)temp_r6 + 0x28) +
                   (*(f32 *)((u8 *)temp_r6 + 0x1C) * temp_f3);
    *(f32 *)((u8 *)arg2 + 4) = lbl_80562690;
    *(f32 *)((u8 *)arg2 + 8) = *(f32 *)((u8 *)temp_r6 + 0x2C) +
                   (*(f32 *)((u8 *)temp_r6 + 0x20) * temp_f3);
    *(f32 *)((u8 *)arg1 + 4) = lbl_80562690;
}

s32 fn_801B54A8(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

void *fn_801B591C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 temp = *(s32 *)((u8 *)arg0 + 8);
        if (temp != 0) {
            ((void (*)(void *, void *(*)(void *, s32)))fn_8002F6AC)((void *)temp, fn_801B591C);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

