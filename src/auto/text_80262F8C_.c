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
s32 fn_80262F8C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
    s32 next = lbl_8055F434 + 1;
    if (next > lbl_8055C440) {
        lbl_8055F434 = lbl_8055C440;
    } else {
        lbl_8055F434 = next;
    }
    fn_80230E90(0);
    return 0;
}

