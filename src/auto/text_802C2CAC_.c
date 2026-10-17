// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_8055CFF8;
extern u8 lbl_8055D000;
extern void *fn_801284E8(void *, s32);
void fn_802C2CE8(void *, s32, s32, s8);
void fn_802C3014(void *);

void fn_802C5024(s32, s32, s32, s32);

extern void fn_8012C4D8(void);

extern s32 lbl_8055FC00;
s32 fn_802C2CAC(s32 arg0) {
    return ((arg0 * 8) & 0xF8) | (((((arg0 << 9) & 0xF80000) | 0xFF000000) & ~0xF800) | ((arg0 << 6) & 0xF800));
}

s32 fn_802C2CC4(s32 arg0) {
    return ((arg0 * 8) & 0xF8) | (((((arg0 << 8) & 0xF80000) | 0xFF000000) & ~0xFC00) | ((arg0 << 5) & 0xFC00));
}

void fn_802C2CDC(void *arg0, s32 arg1, s32 arg2) {
    fn_802C2CE8(arg0, arg1, arg2, (s8)lbl_8055CFF8);
}

void fn_802C2CE8(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 scale;
    *(s8 *)arg0 = arg3;
    *(s8 *)((u8 *)arg0 + 1) = 0x82;
    scale = (arg3 == 5) ? 4 : 2;
    *(void **)((u8 *)arg0 + 4) = fn_801284E8(&lbl_8055D000, arg1 * arg2 * scale);
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = arg2;
    if (arg3 == 5)
        *(s32 *)((u8 *)arg0 + 0x10) = arg1 * 4;
    fn_802C3014(arg0);
}

void fn_802C2D94(void *arg0) {
    fn_80128658(*(s32 *)((u8 *)arg0 + 4));
    memset(arg0, 0, 0x24);
}

void fn_802C2FC4(void) {
    ((void (*)(void))fn_8012C4D8)();
}

void fn_802C2FC8(void *arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    volatile s32 *p = (volatile s32 *)arg0;
    s32 var_r10 = p[2];
    s32 var_r0;
    p[5] = (s32)(arg1 & ((arg1 >> 31) - 1));
    if (arg3 < var_r10)
        var_r10 = arg3;
    p[6] = (s32)(arg2 & ((arg2 >> 31) - 1));
    p[7] = var_r10;
    var_r0 = p[3];
    if (arg4 < var_r0)
        var_r0 = arg4;
    p[8] = var_r0;
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

s32 fn_802C3060(void *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((u8 *)arg0 + 0x10) * arg2 + (*(s32 *)((u8 *)arg0 + 4) + arg1 * 4);
}

s32 fn_802C307C(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 x0 = *arg1;
    s32 x1;
    s32 x2;
    if (x0 >= *(s32 *)((u8 *)arg0 + 0x1C)) return 0;
    if (*arg2 >= *(s32 *)((u8 *)arg0 + 0x20)) return 0;
    x1 = *(s32 *)((u8 *)arg0 + 0x14);
    if (x0 < x1) *arg1 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x18);
    if (*arg2 < x1) *arg2 = x1;
    x1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (*arg3 > x1) *arg3 = x1;
    x2 = *(s32 *)((u8 *)arg0 + 0x20);
    if (*arg4 > x2) *arg4 = x2;
    if (*arg1 >= *arg3) return 0;
    return *arg2 < *arg4;
}

s32 fn_802C3130(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 >= *(s32 *)((u8 *)arg0 + 0x14) && arg2 >= *(s32 *)((u8 *)arg0 + 0x18) && arg1 < *(s32 *)((u8 *)arg0 + 0x1C) && arg2 < *(s32 *)((u8 *)arg0 + 0x20)) return 1;
    return 0;
}

extern const char lbl_8034B060[];
extern void fn_802C3320();
extern void fn_802C33A8();
extern void fn_802E317C(const char *, ...);
void fn_802C32B8(void) {
    u8 *state = (u8 *)lbl_8055FC00;
    s8 mode;
    s32 flag;
    if (state[1] & 4) return;
    mode = (s8)state[0];
    flag = 0;
    if (mode != 5 && mode != 6) flag = 1;
    if (flag != 0) {
        fn_802C3320();
        return;
    }
    if ((s8)state[0] == 5) {
        fn_802C33A8();
        return;
    }
    fn_802E317C(lbl_8034B060, (s32)(s8)*(u8 *)lbl_8055FC00);
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

void fn_802C4F2C(void *arg0, s32 *arg1, s32 *arg2) {
    if (arg0 == 0) {
        *arg2 = 0;
        *arg1 = 0;
    } else {
        *arg1 = *(s32 *)((u8 *)arg0 + 8);
        *arg2 = *(s32 *)((u8 *)arg0 + 0xC);
    }
}

void fn_802C4F58(void *arg0, s32 arg1, const char *arg2, s32 arg3) {
    s32 var_r28 = (s32)arg0;
    const unsigned char *var_r30 = (const unsigned char *)arg2;
    unsigned char temp_r0;
    for (;;) {
        temp_r0 = *var_r30++;
        if ((s8)temp_r0 == 0)
            break;
        if ((s8)temp_r0 < 0x20 || temp_r0 > 0x7f)
            fn_802C5024(var_r28, arg1, 0x23, arg3);
        else
            fn_802C5024(var_r28, arg1, (s32)(s8)temp_r0, arg3);
        var_r28 += 8;
    }
}

extern unsigned int strlen(const char *);
unsigned int fn_802C4FF8(const char *s) { return strlen(s) * 8; }

int fn_802C501C(void) {
    return 8;
}

void fn_802C5024(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {}
extern const char lbl_8034B060[];
extern void fn_802C3320(void);
extern void fn_802C33A8(void);
extern void fn_802E317C(const char *, ...);
extern void fn_802C3850(s32, s32, s32, s32, s32, s32, s32);
extern void fn_802C3754(s32, s32, s32, s32, s32, s32);
extern void fn_802DB2C8(void);
extern void fn_802C3478(void);
extern void fn_802C365C(void);
extern void fn_802C356C(void);
