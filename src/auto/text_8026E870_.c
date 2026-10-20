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

extern f32 lbl_80563E5C;
extern f32 lbl_8055F530;
extern f32 lbl_8055F534;
extern f32 lbl_8055F528;
extern f32 lbl_80563E60;
extern f32 lbl_80563E64;
extern f32 fn_8026EAEC(f32);
extern int fn_801769F8(void);
extern int fn_800216D0(void);
extern void *fn_801B2ED0(s32);
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" f32 fn_8026EB4C(void *arg0) {
    class Obj {
    public:
        virtual void dummy0();
        virtual void dummy1();
        virtual void *getMethod();
    };

    f32 temp_f31;
    f32 f30;
    f32 f1;
    f32 f2;
    f32 diff;
    f32 t;
    int c;
    int flag;

    char *sub = *(char **)((char *)arg0 + 0x140);
    f1 = !(*(f32 *)(sub + 0x258C) > lbl_80563E5C) ? lbl_8055F534 : lbl_8055F530;
    f30 = fn_8026EAEC(f1);

    f2 = lbl_8055F528;
    diff = lbl_8055F52C - f2;
    t = *(f32 *)((char *)arg0 + 0x13C);
    temp_f31 = fn_8026EAEC(f2 + t * diff);

    sub = *(char **)((char *)arg0 + 0x140);
    flag = 0;
    c = 1;
    int cond2 = *(f32 *)(sub + 0x258C) > lbl_80563E5C;
    if (!cond2 && *(u8 *)(sub + 0x259C) == 0) {
        c = 0;
    }
    if (c != 0) {
        int cond3 = *(f32 *)(sub + 0x25E0) > lbl_80563E50;
        if (cond3 != 0) {
            flag = 1;
        }
    }

    if (*(s32 *)((char *)arg0 + 4) != *(s32 *)((char *)arg0 + 0x10)) {
        f30 = flag ? f30 : temp_f31;
    } else if (fn_801769F8() != 0 || fn_800216D0() != 0 || *(s32 *)(*(char **)((char *)arg0 + 0x140) + 0x2620) < 1) {
        f30 = *(f32 *)((char *)arg0 + 0x194);
    } else {
        if (flag) {
            void *obj = fn_801B2ED0(*(s32 *)(*(char **)((char *)arg0 + 0x140) + 0x1EC));
            void *res = ((Obj *)obj)->getMethod();
            if (*(s32 *)((char *)res + 0x24) != 1) {
                f2 = *(f32 *)((char *)arg0 + 0x194);
                f30 = f2 + lbl_80563E60 * (f30 - f2);
                goto end;
            }
        }
        f2 = *(f32 *)((char *)arg0 + 0x194);
        f30 = f2 + lbl_80563E64 * (temp_f31 - f2);
    }

end:
    return f30;
}
#pragma cplusplus reset
#pragma pop

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

void fn_802704D4(void *arg0, void *arg1) {
    ((void (*)(void *, s32, void *))fn_802704D0)(arg0, *(s32 *)((u8 *)arg1 + 4), arg1);
}

void fn_802704E0(void) { fn_8026EA8C(); }

