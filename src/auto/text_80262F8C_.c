// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern s32 lbl_8055F434;
extern s32 lbl_8055C440;
extern f32 lbl_80563BC8;
extern s32 fn_80230E90(s32);
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
extern s32 fn_80128668(void);
extern s32 fn_80131234(const u8 *, const u8 *);
extern void fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 fn_802328D4(s32);
extern const u8 lbl_80346324[];
extern const u8 lbl_80346120[];
extern f32 lbl_80563BD4;
s32 fn_80262F8C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80262FCC(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = fn_8023659C();
    *((u8 *)arg0 + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

void fn_8026300C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x18);
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80563BC8)) {
        *((u8 *)arg0 + 0x1C) = 1;
    }
    if (*((u8 *)arg0 + 0x1C) != 0) {
        fn_80214AF0(0x1D);
    }
}

s32 fn_80263070(void *arg0) {
    return *((u8 *)arg0 + 0x1C) == 0;
}

s32 fn_80263080(void) {
    s32 temp_r0;
    temp_r0 = lbl_8055F434 - 1;
    lbl_8055F434 = temp_r0;
    if (temp_r0 < 0) {
        lbl_8055F434 = 0;
    }
    fn_80230E90(0);
    return 0;
}

s32 fn_802630C0(void) {
    s32 next;
    next = lbl_8055F434 + 1;
    lbl_8055F434 = next;
    if (next > lbl_8055C440) {
        lbl_8055F434 = lbl_8055C440;
    }
    fn_80230E90(0);
    return 0;
}

extern int fn_80263104(void);
int fn_80263104(void) {
    return lbl_8055F434 == lbl_8055C440;
}

s32 fn_80263658(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_802638C8(void *arg0, s32 arg1) {
    if (*((u8 *)arg0 + 0x29) != 0 && arg1 != 0x126) {
        if (arg1 < 0x126) {
            if (arg1 >= 0x125 && *((u8 *)arg0 + 0x28) == 0) {
                *((u8 *)arg0 + 0x28) = 1;
            }
        } else if (arg1 < 0x128 && *((u8 *)arg0 + 0x28) != 0) {
            *((u8 *)arg0 + 0x28) = 0;
        }
    }
    return 0;
}

void fn_8026392C(void *arg0) {
    s32 value;
    value = lbl_8055F434;
    if (value == *(s32 *)((u8 *)arg0 + 0x20)) {
        *(s32 *)((u8 *)arg0 + 0x1C) = 1;
        *((u8 *)arg0 + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
        *((u8 *)arg0 + 0x29) = 0;
    }
}

extern s32 fn_80133460(s32, const u8 *, u8, s32);
extern s32 fn_801333E8(s32, const u8 *, u8 *, u8 *);
extern const u8 lbl_803462B8[];
extern const u8 lbl_803462A8[];
void fn_80263980(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    fn_80133460(value + 8, lbl_803462B8, *((u8 *)arg0 + 0x28), value);
}

extern const u8 lbl_80346294[];
void fn_80263BCC(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    fn_80133460(value + 8, lbl_80346294, *((u8 *)arg0 + 0x28), value);
}

