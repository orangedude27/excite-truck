// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_801298E8(f32 *, s32);
extern s32 fn_801769B8(void);
extern s32 fn_801EA994(void);
extern u8 lbl_8034EE84[];
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

#pragma push
#pragma processor 750
void fn_800053CC(void) {
    f32 sp8;
    f32 spC;
    if (fn_801298E8(&sp8, 0) != 0) {
        f32 f1;
        f32 f30;
        f32 f29;
        f32 f31;
        f1 = sp8 * sp8 + spC * spC;
        f30 = lbl_80560114 * sp8;
        f31 = lbl_80560110;
        f29 = lbl_80560118 * spC;
        fn_8002F234();
        fn_80010B80(0x800000FF, f30, f29, f31, f31);
    }
}
#pragma pop
/* Does nothing. */
void fn_8000545C(void) {
    return;
}

/* Does nothing. */
void fn_80005460(void) {
    return;
}

extern s32 fn_801769B8(void);
extern s32 fn_801EA994(void);
extern u8 lbl_8034EE84[];
#pragma scheduling invalid_target
void fn_80005464(void) {
    s32 mode = fn_801769B8();
    s32 *w = (s32 *)lbl_8034EE84;
    w[1] = mode;
    lbl_8034EE84[0] = 0;
    if (mode == 2 && fn_801EA994() > 1) {
        lbl_8034EE84[0] = 1;
    }
    lbl_8034EE84[1] = 1;
    if (((s32 *)lbl_8034EE84)[1] == 0) {
        lbl_8034EE84[1] = 0;
    }
}
#pragma unroll off
void fn_800054E0(void) {
    volatile f32 *p = (volatile f32 *)lbl_8034EC78;
    s32 i = 16;
    do {
        p[0] = lbl_8056011C; p[1] = lbl_8056011C;
        p[2] = lbl_8056011C; p[3] = lbl_8056011C;
        p[4] = lbl_8056011C; p[5] = lbl_8056011C;
        p[6] = lbl_8056011C; p[7] = lbl_8056011C;
        p += 8;
    } while (--i != 0);
    *(s32 *)(lbl_8034EC78 + 0x200) = 0;
    *(s32 *)(lbl_8034EC78 + 0x204) = fn_802E2C20();
    *(s32 *)(lbl_8034EC78 + 0x208) = 0;
}
#pragma unroll reset
s32 fn_80005564(void) { return lbl_8034EEB8[0x50 / 4] != 0; }

#pragma dont_inline on
s32 fn_80005580(s32 arg0) {
    s32 flags = ((s32 *)fn_801E87A8())[1];
    s32 obj = fn_801E86F8(arg0);
    u8 *state = (u8 *)fn_801EA9CC();

    if (fn_801B8570(obj) == 0) {
        return 1;
    }
    if (flags & 0x100) {
        s32 result = 0;
        if (*(s32 *)(state + 0x30) != 3) {
            if (state[0x34] != 0) {
                result = 1;
            }
        }
        return result;
    }
    return 0;
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

#pragma cplusplus on
extern "C" void fn_80005678(void) {
    struct TargetIface {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void call();
    };
    struct Container {
        char pad[0x58];
        TargetIface *obj;
    };
    ((Container *)lbl_8034EEB8)->obj->call();
}
#pragma cplusplus reset
