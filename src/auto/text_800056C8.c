#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
extern s32 fn_80005564(void);
extern void *fn_801B83A0(void);
extern void *lbl_8055D350;
extern f32 lbl_8056011C;
extern s32 fn_801E866C(void);
extern void *fn_801EA9A0(void);
extern s32 fn_801B84D8(s32, s32);
extern s32 fn_801B8570(s32);
extern s32 fn_80230DA0(void);
extern void *lbl_8034EE84;
extern u8 lbl_8055F024;

extern s32 lbl_8034EEB8[0x100];
void fn_800056C8(s32 arg0, s32 arg1) {
    s32 *p = &lbl_8034EEB8[arg0];
    p[4] = arg1;
}

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
    f32 f2;
    s32 r0;
    s32 r12;

    r0 = 0;
    r12 = ((s32 *)lbl_8055D350)[7];
    f2 = ((f32 *)((s8 *)arg0 + r12 * 4))[1];
    if (f2 >= lbl_8056011C) {
        f32 f0 = ((f32 *)lbl_8055D350)[4] - f2;
        if (f0 > lbl_8056011C) {
            r0 = 1;
        }
    }
    if (r0 && fn_80005564()) {
        void *obj = fn_801B83A0();
        r12 = ((s32 *)obj)[0];
        r12 = ((s32 *)r12)[0x60 / 4];
        ((void (*)(s32))r12)(arg1);
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

s32 fn_80007664(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007724(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007764(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800077A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007990(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007A84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80007BE8(void) {
    return;
}

