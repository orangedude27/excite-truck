// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_801298E8(f32 *, s32);
extern void fn_8002F234(void);
extern void fn_80010B80(s32, f32, f32, f32, f32);
extern f32 lbl_80560110;
extern f32 lbl_80560114;
extern f32 lbl_80560118;
extern u32 lbl_8034EEB8[];
extern f32 lbl_8056011C;
extern u8 lbl_8034EC78[];
extern u8 *lbl_8055D350;
extern void *fn_801E87A8(void);
extern s32 fn_801E86F8(s32);
extern void *fn_801EA9CC(void);
extern s32 fn_801B8570(s32);
extern s32 fn_802E2C20(void);
extern s32 fn_80005580(s32);

// split_file divides it into the game's real files (file_status shows its range).

static void fn_800053CC(void) {
    f32 sp8;
    f32 spC;

    if (fn_801298E8(&sp8, 0) != 0) {
        f32 f30;
        f32 f29;
        f32 f31;

        f30 = lbl_80560114 * sp8;
        f31 = lbl_80560110;
        f29 = lbl_80560118 * spC;
        fn_8002F234();
        fn_80010B80(0x800000FF, f30, f29, f31, f31);
    }
}

void fn_8000545C(void) {
    return;
}

void fn_80005460(void) {
    return;
}

extern u32 lbl_8034EEB8[];
extern void *fn_801E87A8(void);
extern s32 fn_801E86F8(s32);
extern void *fn_801EA9CC(void);
extern s32 fn_801B8570(s32);
extern f32 lbl_8056011C;
extern u8 lbl_8034EC78[];
extern s32 fn_802E2C20(void);
extern s32 fn_80005580(s32);
extern u8 *lbl_8055D350;
s32 fn_8000561C(void) {
    s32 i = 0;
    while (i < *(s32 *)(lbl_8055D350 + 0x14)) {
        if (fn_80005580(i) == 0)
            return 0;
        i++;
    }
    return 1;
}

