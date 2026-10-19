// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
extern f32 lbl_80563E78;
extern f32 lbl_8049A218[];
extern f32 lbl_8055F52C;
extern f32 lbl_80563E68;
extern f32 lbl_80563E30;
extern f32 lbl_80563E38;
extern f32 lbl_80563E3C;
extern f32 lbl_80563E50;
extern f32 lbl_80563E54;
extern f32 lbl_80563E58;
extern f32 fn_8026EB4C(void *);
extern s32 fn_80178CA4(void);
extern double cos(double);
extern double atan(double);
extern double fn_8002EF30(f32);
extern void fn_8026FCFC(void);
extern void fn_8026EA8C(void);

s32 fn_8026EA14(s32 arg0) {
    s32 shift = arg0 - 4;
    s32 result = 0;
    if ((unsigned)shift > 0x13)
        return result;
    if ((1 << shift) & 0x80017)
        result = 1;
    return result;
}

f32 fn_8026EA44(s32 arg0) {
    switch (arg0) {
    case 6:
        return lbl_80563E38;
    case 8:
    case 4:
        return lbl_80563E3C;
    case 7:
        return lbl_80563E30;
    default:
        return lbl_80563E3C;
    }
}

#pragma push
#pragma dont_inline on
f32 fn_8026EAEC(f32 farg0) {
    f32 value;
    if (fn_80178CA4() > 1) {
        value = lbl_80563E58 * (f32)atan(lbl_80563E54 * (f32)fn_8002EF30(farg0 * lbl_80563E50));
    } else {
        value = farg0;
    }
    return value;
}
#pragma pop
f32 fn_8026ECE4(void *arg0, f32 *arg1) {
    f32 value = fn_8026EB4C(arg0);
    if (value > lbl_8055F52C) {
        f32 denom = (f32)cos((double)(lbl_8055F52C * lbl_80563E68));
        *arg1 *= (f32)cos((double)(value * lbl_80563E68)) / denom;
    }
    return value;
}

s32 fn_8026F408(s32 arg0) { return arg0 <= 8; }

f32 fn_8026FCE0(f32 farg0, f32 farg1) {
    f32 diff = lbl_80563E30 - farg1;
    f32 square = farg0 * farg0;
    return (diff * farg0) + (farg1 * square);
}

extern f32 lbl_80563ED8;
extern f32 lbl_80563F1C;
extern f32 lbl_80563E40;
extern f32 lbl_80563E44;
extern f32 lbl_80563E48;
extern f32 lbl_80563E4C;
extern f32 lbl_80563E38;
extern f32 lbl_80563E3C;
extern f32 lbl_80563E38;
extern f32 lbl_80563E38;
extern s32 lbl_8049A208[];
void fn_8027045C(void) {
    ((f32 *)&lbl_8049A208)[0] = lbl_80563ED8;
    ((f32 *)&lbl_8049A208)[1] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[2] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[3] = lbl_80563F1C;
}

void fn_80270484(void) {
    f32 value = lbl_80563E78;
    f32 *p = lbl_8049A218 - 1;
    *++p = value;
    p[1] = value;
    p[3] = value;
    p[2] = value;
    p[4] = value;
    p[5] = value;
    p[7] = value;
    p[6] = value;
    p[8] = value;
    p[9] = value;
    p[11] = value;
    p[10] = value;
    p[12] = value;
    p[13] = value;
    p[15] = value;
    p[14] = value;
}

void fn_802704D0(void) { fn_8026FCFC(); }

void fn_802704D4(void *unused, void *arg1) {
    ((void (*)(s32, void *))fn_802704D0)(*(s32 *)((u8 *)arg1 + 4), arg1);
}

void fn_802704E0(void) { fn_8026EA8C(); }

