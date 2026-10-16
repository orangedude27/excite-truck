// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *fn_801E87A8(void);
extern int lbl_8049F9D8;
extern int lbl_8055F554;
extern float lbl_80563E78;
void fn_80270AE8(void *arg0) {
    ((float *)arg0)[0] = lbl_80563E78;
    ((float *)arg0)[1] = lbl_80563E78;
    ((float *)arg0)[3] = lbl_80563E78;
    ((float *)arg0)[2] = lbl_80563E78;
}

void DBPrintf_80270B00(const char *fmt, ...) {
#pragma unused(fmt)
}

int fn_80270D1C(int arg0) {
    switch (arg0) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}

extern char lbl_80346E90[];
void fn_802712F8(void *);
void fn_8027156C(void) {
    fn_802712F8(lbl_80346E90);
}

typedef signed int s32;
typedef unsigned char u8;
void *fn_80178C9C(void);
s32 fn_80270B50(void);
s32 fn_80270EC4(void *, s32);
void fn_80271578(void) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r3;
    temp_r3 = fn_80178C9C();
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 0xC);
    temp_r30 = temp_r3;
    fn_80270EC4(temp_r30, fn_80270B50());
    *(s32 *)((u8 *)temp_r30 + 0xC) = temp_r31;
}

typedef float f32;
extern f32 lbl_80563F4C;
void fn_802715C4(void *arg0, void *arg1) {
    f32 x = *(f32 *)((u8 *)arg1 + 0x14);
    f32 scale = lbl_80563F4C;
    f32 y = *(f32 *)((u8 *)arg1 + 0x10);
    f32 z = *(f32 *)((u8 *)arg1 + 0xC);
    *(f32 *)((u8 *)arg0 + 8) = x * scale;
    *(f32 *)((u8 *)arg0 + 4) = y * scale;
    *(f32 *)((u8 *)arg0 + 0) = z * scale;
}

extern f32 lbl_8055F540;
extern f32 lbl_8055F544;
f32 fn_802715F0(void *arg0) {
    f32 value = lbl_80563F4C * *(f32 *)((u8 *)arg0 + 0x18);
    f32 min = lbl_8055F544;
    if (min < value) {
        min = value;
    }
    if (min > lbl_8055F540) {
        return min;
    }
    return lbl_8055F540;
}

