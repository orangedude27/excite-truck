#include "revolution/MTX/vec.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));
extern void fn_801AC240(void *);
extern void fn_801AC254(void *);
extern void fn_801ABFF8(int **);
extern int lbl_80335940;
extern float lbl_805624D0;

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern float lbl_8055E3C8;
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern int lbl_8055E5E4;
extern int lbl_8055E5EC;
extern int lbl_8055E5F0;
extern char lbl_80335718[];
extern char lbl_80335744[];
extern char lbl_80335808[];
extern void *lbl_80435628[];
extern void fn_802E317C(const char *, ...);
extern void **fn_801A9700(void **);
extern int lbl_8055E3C4;
extern int lbl_8055A858;
extern int jumptable_80335578[];
void fn_801A9660(void) {
    unsigned int index = *(unsigned int *)((char *)fn_801792F8() + 0x50) - 6;
    if (index < 0x11) {
        ((void (*)(void))jumptable_80335578[index])();
        return;
    }
    if (fn_801284F8(0x23c, &lbl_8055A858) != 0) fn_801A9700(0);
}

#pragma scheduling off
void** fn_801A9700(void** arg0) {
    fn_8017B0B0(arg0);
    *arg0 = &lbl_8033585C;
    return arg0;
}
#pragma scheduling on
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(void *this_, int flag) {
    if (this_) {
        if (this_ != 0) fn_80179EE8(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
}

void fn_801ABB54(void *arg0) {
    extern float lbl_80562478, lbl_8056247C, lbl_805624A4, lbl_805624AC, lbl_805624D8;
    float dot, magnitude, sign, limit;
    float scale;
    double absolute;
    float z, y, x;
    char *p = arg0;
    dot = PSVECDotProduct((Vec *)(p + 0x124), (Vec *)(p + 0x54));
    limit = *(float *)(p + 0x238);
    scale = lbl_8056247C;
    absolute = __fabs(dot);
    magnitude = (float)absolute;
    if (magnitude > limit) {
        limit = limit < magnitude ? limit : magnitude;
        if (dot > lbl_8056247C) sign = lbl_805624AC;
        else sign = lbl_805624A4;
        scale = -sign * limit;
    } else if (magnitude > lbl_805624D8) {
        scale = -dot * lbl_80562478;
    }
    x = *(float *)(p + 0x54) * scale;
    y = *(float *)(p + 0x58) * scale;
    z = *(float *)(p + 0x5C) * scale;
    y = *(float *)(p + 0x128) + y;
    x = *(float *)(p + 0x124) + x;
    z = *(float *)(p + 0x12C) + z;
    *(float *)(p + 0x128) = y;
    *(float *)(p + 0x124) = x;
    *(float *)(p + 0x12C) = z;
}

void fn_801ABFF4(void) {
    fn_8017A57C();
}

extern void fn_8017A580(void *, int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
void fn_801AC184(void *arg0) {
    int t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;

    fn_801AC240(arg0);
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg0 + 0x1EC);
    *(int *)((char *)arg0 + 0x40) = *(int *)((char *)arg0 + 0x1F0);
    *(int *)((char *)arg0 + 0x44) = *(int *)((char *)arg0 + 0x1F4);
    *(int *)((char *)arg0 + 0x48) = *(int *)((char *)arg0 + 0x1F8);
    t4 = *(int *)((char *)arg0 + 0x1FC);
    t5 = *(int *)((char *)arg0 + 0x200);
    t6 = *(int *)((char *)arg0 + 0x204);
    t7 = *(int *)((char *)arg0 + 0x208);
    t8 = *(int *)((char *)arg0 + 0x20C);
    t9 = *(int *)((char *)arg0 + 0x210);
    t10 = *(int *)((char *)arg0 + 0x214);
    *(int *)((char *)arg0 + 0x4C) = t4;
    *(int *)((char *)arg0 + 0x50) = t5;
    *(int *)((char *)arg0 + 0x54) = t6;
    *(int *)((char *)arg0 + 0x58) = t7;
    *(int *)((char *)arg0 + 0x5C) = t8;
    *(int *)((char *)arg0 + 0x60) = t9;
    *(int *)((char *)arg0 + 0x64) = t10;
    *(int *)((char *)arg0 + 0x68) = *(int *)((char *)arg0 + 0x218);

    fn_8017A580(arg0, t10, t9, t8, t7, t6, t5, t4);
    fn_8017B164(arg0);
    *(unsigned char *)((char *)arg0 + 0x223) = 1;
    *(unsigned char *)((char *)arg0 + 0x234) = *(unsigned char *)((char *)arg0 + 0x235);
}

#pragma dont_inline on
void fn_801AC240(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x220) = 1;
    *(float *)((char *)arg0 + 0x21C) = lbl_8055E3C8;
}
#pragma dont_inline off

void fn_801AC254(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x220) != 0) {
        *(unsigned char *)((char *)arg0 + 0x220) = 0;
    }
}

void *fn_801AC26C(void) {
    void *obj = fn_801284F8(0x244, &lbl_80335718);
    if (obj != 0) {
        fn_801A9700(obj);
        *(void **)obj = &lbl_80335744;
        *(void **)((char *)obj + 0x23C) = (char *)&lbl_80335744 + 0x54;
    }
    return obj;
}

void *fn_801AC330(void *arg0) {
    fn_801A9700(arg0);
    *(void **)arg0 = &lbl_80335808;
    if (lbl_8055E5EC == 0) {
        lbl_8055E5F0 = 0;
    }
    *(int *)((char *)arg0 + 0x250) = lbl_8055E5EC;
    lbl_8055E5EC = lbl_8055E5EC + 1;
    lbl_80435628[*(int *)((char *)arg0 + 0x250)] = arg0;
    *(int *)((char *)arg0 + 0x254) = -1;
    return arg0;
}

void fn_801AD5EC(void) {
    fn_801AC508();
}

void fn_801AD5F0(void) {
    fn_801ACF94();
}

extern void fn_801D0A24(void *, void *);
extern void fn_801AC0A0(void *, float *, float *, int, int);
extern void fn_801D09A8(void *, int);
extern void fn_801A9AB0(void);
extern void fn_801D08C0(void *);
extern void fn_801D0934(void *);
void *fn_801AD6B0(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80335744;
        *(void **)((char *)arg0 + 0x23C) = (char *)&lbl_80335744 + 0x54;
        fn_801D0934((char *)arg0 + 0x23C);
        *(int *)((char *)arg0 + 0x240) = 0;
        lbl_8055E5E4 = 0;
        fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

unsigned char fn_801AD860(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

long fn_801AD868(void) {
    return 0;
}

void fn_801AD870(void *arg0, void *arg1, void *arg2, long *arg3, long *arg4) {
    *arg4 = 0;
    *arg3 = 0;
}

long fn_801AD880(void) {
    return 0;
}

void fn_801AD888(void *arg0) {
    ((void (**)(void *))(*(void ***)arg0))[4](arg0);
    ((void (*)(void *))fn_801AC254)(arg0);
}

void fn_801AD8C8(void *arg0, int *arg1, float *arg2, float *arg3) {
    int l, k, j, i, h, g, f, e, d, c, b, a;
    float z1, y1, x1, z0, y0, x0;
    a=arg1[0]; b=arg1[1]; c=arg1[2]; d=arg1[3];
    e=arg1[4]; f=arg1[5]; g=arg1[6]; h=arg1[7];
    i=arg1[8]; j=arg1[9]; k=arg1[10]; l=arg1[11];
    *(int *)((char *)arg0+0x3c)=a;
    *(int *)((char *)arg0+0x40)=b;
    *(int *)((char *)arg0+0x44)=c;
    *(int *)((char *)arg0+0x48)=d;
    *(int *)((char *)arg0+0x4c)=e;
    *(int *)((char *)arg0+0x50)=f;
    *(int *)((char *)arg0+0x54)=g;
    *(int *)((char *)arg0+0x58)=h;
    *(int *)((char *)arg0+0x5c)=i;
    *(int *)((char *)arg0+0x60)=j;
    *(int *)((char *)arg0+0x64)=k;
    *(int *)((char *)arg0+0x68)=l;
    ((void (*)(void *))fn_8017A580)(arg0);
    x0=arg2[0]; y0=arg2[1]; z0=arg2[2];
    x1=arg3[0]; y1=arg3[1]; z1=arg3[2];
    *(float *)((char *)arg0+0x118)=x0;
    *(float *)((char *)arg0+0x11c)=y0;
    *(float *)((char *)arg0+0x120)=z0;
    *(float *)((char *)arg0+0x124)=x1;
    *(float *)((char *)arg0+0x128)=y1;
    *(float *)((char *)arg0+0x12c)=z1;
    fn_801AC240(arg0);
}

void fn_801AD99C(void *arg0, float *arg1, float *arg2) {
    float scale;
    float sp14[3];
    float sp8[3];
    scale = *(float *)((char *)arg0 + 0xD4) / lbl_805624D0;
    sp14[0] = arg1[0] * scale;
    sp14[1] = arg1[1] * scale;
    sp14[2] = arg1[2] * scale;
    sp8[0] = *(float *)((char *)arg0 + 0x60) + arg2[0];
    sp8[1] = *(float *)((char *)arg0 + 0x64) + arg2[1];
    sp8[2] = *(float *)((char *)arg0 + 0x68) + arg2[2];
    ((void (*)(float *, float *, int, int))(*(void ***)arg0)[18])(sp14, sp8, 100, 0);
}

void fn_801ADA38(void *arg0, int arg1) {
    int *sp8;
    if (arg1) {
        sp8 = &lbl_80335940;
        fn_801ABFF8(&sp8);
    } else {
        *((char *)arg0 + 0x220) = 0;
    }
}

unsigned char fn_801ADA7C(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

short fn_801ADA84(void *arg0) {
    return *(short *)((char *)arg0 + 0x6C);
}

long fn_801ADA8C(long arg0) { return arg0 + 0x118; }

long fn_801ADA94(long arg0) {
    return arg0 + 0x60;
}

extern float lbl_8055E3C8;
typedef void (*Fn801ADA9C)(void *, void *, void *);
extern unsigned char lbl_8055A8A0;
extern unsigned char lbl_8055A8B0;
void fn_801ADA9C(void *arg0) {
    (*(void (**)(void *, void *, void *))(*(char **)*(void **)((char *)arg0 + 0x240) + 0x18))(*(void **)((char *)arg0 + 0x240), &lbl_8055A8A0, &lbl_8055A8B0);
}

long fn_801ADAB8(void *arg0) {
    return *(long *)((char *)arg0 + 0x240);
}

void fn_801ADAC0(void *arg0, long arg1) {
    fn_801AC240((void *)arg1);
}

