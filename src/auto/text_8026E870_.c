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
extern f32 lbl_80563E50;
extern f32 lbl_80563E54;
extern f32 lbl_80563E58;
extern f32 fn_8026EB4C(void);
extern s32 fn_80178CA4(void);
extern double cos(double);
extern double atan(double);
extern double fn_8002EF30(f32);
extern void fn_8026FCFC(void);
extern void fn_8026EA8C(void);

s32 fn_8026EA14(s32 arg0) {
    s32 shift = arg0 - 4;
    if ((unsigned)shift > 0x13)
        return 0;
    return ((1 << shift) & 0x80017) != 0;
}

f32 fn_8026EAEC(f32 farg0) {
    f32 value = farg0;
    if (fn_80178CA4() > 1)
        value = lbl_80563E58 * (f32)atan((double)(lbl_80563E54 * (f32)fn_8002EF30(value * lbl_80563E50)));
    return value;
}

f32 fn_8026ECE4(f32 *arg1) {
    f32 value = fn_8026EB4C();
    if (value > lbl_8055F52C) {
        f32 denom = (f32)cos((double)(lbl_8055F52C * lbl_80563E68));
        *arg1 *= (f32)cos((double)(value * lbl_80563E68)) / denom;
    }
    return value;
}

s32 fn_8026F408(s32 arg0) { return arg0 <= 8; }

f32 fn_8026FCE0(f32 farg0, f32 farg1) {
    return ((lbl_80563E30 - farg1) * farg0) + (farg1 * (farg0 * farg0));
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
extern s32 lbl_8049A208[];
void fn_8027045C(void) {
    ((f32 *)&lbl_8049A208)[0] = lbl_80563ED8;
    ((f32 *)&lbl_8049A208)[1] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[2] = lbl_80563E78;
    ((f32 *)&lbl_8049A208)[3] = lbl_80563F1C;
}

void fn_80270484(void) {
    f32 value = lbl_80563E78;
    lbl_8049A218[0] = value;
    lbl_8049A218[1] = value;
    lbl_8049A218[3] = value;
    lbl_8049A218[2] = value;
    lbl_8049A218[4] = value;
    lbl_8049A218[5] = value;
    lbl_8049A218[7] = value;
    lbl_8049A218[6] = value;
    lbl_8049A218[8] = value;
    lbl_8049A218[9] = value;
    lbl_8049A218[11] = value;
    lbl_8049A218[10] = value;
    lbl_8049A218[12] = value;
    lbl_8049A218[13] = value;
    lbl_8049A218[15] = value;
    lbl_8049A218[14] = value;
}

void fn_802704D0(void) { fn_8026FCFC(); }

void fn_802704E0(void) { fn_8026EA8C(); }

