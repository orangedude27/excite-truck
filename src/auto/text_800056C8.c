#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
extern s32 fn_80005564(void);
extern void *fn_801B83A0(void);
extern void *lbl_8055D350;
extern f32 lbl_8056011C;

void fn_80005B54(void) {
    return;
}

void fn_80005B58(void) {
    return;
}

void fn_80005B64(void) {
    return;
}

void fn_80005B68(void) {

}

void fn_80005B6C(void) {
    return;
}

void fn_80005B70(void) {
}

s32 fn_80005FE0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006020(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006060(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_800060B4(void) {
    return;
}

void fn_800060DC(void) {
}

s32 fn_80006244(void) {
    return 0;
}

s32 fn_8000624C(void) {
    return 0;
}

void fn_80006254(s32 arg0, s32 arg1) {
    f32 var_f2;
    s32 var_r0;
    s32 idx;

    var_r0 = 0;
    idx = ((s32 *)lbl_8055D350)[0x1C];
    var_f2 = ((f32 *)((s32 *)arg0 + idx * 4))[1];
    if (var_f2 >= lbl_8056011C) {
        f32 diff = ((f32 *)lbl_8055D350)[0x10 / 4] - var_f2;
        if (diff > lbl_8056011C) {
            var_r0 = 1;
        }
    }
    if (var_r0 && fn_80005564()) {
        void *ptr = fn_801B83A0();
        void (*fn)(s32) = (void (*)(s32))((void **)ptr)[0x60 / 4];
        fn(arg1);
    }
}

void fn_800062E4(void) {
    return;
}

void fn_800063A4(void) {
    fn_801C6B70();
}

void fn_80006E50(void) {
}

void fn_800070D4(void) {
    return;
}

void fn_800070D8(void) {
}

void fn_80007498(void) {
    fn_80011A50();
}

s32 fn_800075E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007624(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80007BE8(void) {
    return;
}

