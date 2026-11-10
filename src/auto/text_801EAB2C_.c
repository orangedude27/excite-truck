// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern char lbl_80488228[];
extern void fn_802DAC54(void);
extern int fn_802C7A40(int, void *, int, int, void *, int);
extern void fn_802C70AC(int, void *, int, int);
extern u8 lbl_80339E18[];
extern void *memset(void *, int, unsigned int);

extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
#pragma cplusplus on
class Dummy_801EAB90 {
public:
    virtual void d0(int);
    virtual void d1(int);
    virtual void d2(int);
    virtual void d3(int);
    virtual void d4(int);
    virtual void d5(int);
    virtual void m6(int);
};
#pragma cplusplus off
extern void fn_801EABA8(void *, void *);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];

extern int fn_80176948(int, int, int);
extern float lbl_80562E60;
extern float lbl_80562E64;
extern short lbl_80562E28;
extern u8 lbl_80339E60[];
void fn_801EAB2C(void *arg0) {
    float a = lbl_80562E60;
    void *vptr = &lbl_80339E60;
    float b = lbl_80562E64;
    float *p = (float *)arg0;
    p[1] = a;
    *(short *)((char *)arg0 + 0x38) = lbl_80562E28;
    *(int *)arg0 = (int)vptr;
    p[1] = a;
    p[2] = b;
    p[3] = b;
    p[4] = b;
    p[5] = a;
    p[6] = b;
    p[7] = b;
    p[8] = b;
    p[9] = a;
    p[10] = b;
    p[11] = b;
    p[12] = b;
}

void fn_801EAB80(void *arg0, long arg1) {
    fn_80176948(arg1, (long)arg0 + 0x34, (long)arg0);
}

#pragma cplusplus on
extern "C" void fn_801EAB90(void *arg0, int arg1) {
    int offset = *(int *)((char *)arg0 + 0x34);
    ((Dummy_801EAB90 *)arg0)->m6(arg1 + offset);
}
#pragma cplusplus off
void fn_801EABA8(void *arg0, void *arg1) {
    s32 l, k, j, i, h, g, f, e, d, c, b, a;
    s16 m;

    e = *(volatile s32 *)((u8 *)arg1 + 0x10);
    d = *(volatile s32 *)((u8 *)arg1 + 0x0C);
    c = *(volatile s32 *)((u8 *)arg1 + 0x08);
    b = *(volatile s32 *)((u8 *)arg1 + 0x04);
    a = *(volatile s32 *)((u8 *)arg1 + 0x00);
    f = *(volatile s32 *)((u8 *)arg1 + 0x14);
    g = *(volatile s32 *)((u8 *)arg1 + 0x18);
    h = *(volatile s32 *)((u8 *)arg1 + 0x1C);
    i = *(volatile s32 *)((u8 *)arg1 + 0x20);
    j = *(volatile s32 *)((u8 *)arg1 + 0x24);
    k = *(volatile s32 *)((u8 *)arg1 + 0x28);
    l = *(volatile s32 *)((u8 *)arg1 + 0x2C);
    m = *(volatile s16 *)((u8 *)arg1 + 0x30);

    *(s32 *)((u8 *)arg0 + 0x04) = a;
    *(s32 *)((u8 *)arg0 + 0x08) = b;
    *(s32 *)((u8 *)arg0 + 0x0C) = c;
    *(s32 *)((u8 *)arg0 + 0x10) = d;
    *(s32 *)((u8 *)arg0 + 0x14) = e;
    *(s32 *)((u8 *)arg0 + 0x18) = f;
    *(s32 *)((u8 *)arg0 + 0x1C) = g;
    *(s32 *)((u8 *)arg0 + 0x20) = h;
    *(s32 *)((u8 *)arg0 + 0x24) = i;
    *(s32 *)((u8 *)arg0 + 0x28) = j;
    *(s32 *)((u8 *)arg0 + 0x2C) = k;
    *(s32 *)((u8 *)arg0 + 0x30) = l;
    *(s16 *)((u8 *)arg0 + 0x38) = m;
}
#pragma scheduling on
s16 fn_801EAC3C(void* arg0) {
    return *(s16*)((u8*)arg0 + 0x38);
}

#pragma dont_inline on
#pragma scheduling invalid_target
void* fn_801EAC44(void* this_, s32 arg1, s32 arg2) {
    fn_801EAB2C(this_);
    *(u32*)this_ = (u32)lbl_80339E3C;
    *(s32*)((u8*)this_ + 0x3C) = fn_802C6FC0(arg2, 0, 0);
    fn_801EAB80(this_, arg1);
    return this_;
}
#pragma scheduling on
#pragma dont_inline off
s32 fn_801EACB8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void* __dt__Q28PSSystem7SeqHeapFv_801EACF8(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_80339E3C;
        fn_802C6CF8(*(s32*)((u8*)this_ + 0x3C));

        if (flag > 0) {
            fn_80128668(this_);
        }
    }

    return this_;
}

void fn_801EAD5C(void* arg0) {
    fn_802C744C(*(s32*)((u8*)arg0 + 0x3C), (u8*)arg0 + 4);
}

#pragma dont_inline on
void *fn_801EAD6C(void *arg0, s32 arg1) {
    fn_801EAB2C(arg0);
    *(void **)arg0 = lbl_80339E18;
    fn_801EAB80(arg0, arg1);
    memset((u8 *)arg0 + 0x3C, 0, 0x40);
    *(s32 *)((u8 *)arg0 + 0x70) = -1;
    return arg0;
}
void fn_801EADD8(void *arg0) {
    s32 value;
    s32 sp[2];
    if (*(s32 *)((char *)arg0 + 0x70) == -1) {
        return;
    }
    if (*(s32 *)((char *)arg0 + 0x78) == 0) {
        value = 0;
    } else {
        fn_802DAC54();
        sp[0] = *(s32 *)((char *)arg0 + 0x78);
        sp[1] = -0x100;
        value = fn_802C7A40(1, lbl_80488228, 0x50, 1, sp, 2);
    }
    fn_802C70AC(*(s32 *)((char *)arg0 + 0x70), (char *)arg0 + 4, value, *(s32 *)((char *)arg0 + 0x74));
}

#pragma dont_inline fn_801EABA8
void fn_801EAE68(void *arg0, void *arg1) {
    register s16 half;
    s32 o, n, m, l, k, j, i, h, g, f, e, d, c, b, a;

    fn_801EABA8(arg0, arg1);
    a = *(volatile s32 *)((u8 *)arg1 + 0x00);
    b = *(volatile s32 *)((u8 *)arg1 + 0x04);
    c = *(volatile s32 *)((u8 *)arg1 + 0x08);
    d = *(volatile s32 *)((u8 *)arg1 + 0x0C);
    e = *(volatile s32 *)((u8 *)arg1 + 0x10);
    f = *(volatile s32 *)((u8 *)arg1 + 0x14);
    g = *(volatile s32 *)((u8 *)arg1 + 0x18);
    h = *(volatile s32 *)((u8 *)arg1 + 0x1C);
    i = *(volatile s32 *)((u8 *)arg1 + 0x20);
    j = *(volatile s32 *)((u8 *)arg1 + 0x24);
    k = *(volatile s32 *)((u8 *)arg1 + 0x28);
    l = *(volatile s32 *)((u8 *)arg1 + 0x2C);
    half = *(volatile s16 *)((u8 *)arg1 + 0x30);
    m = *(volatile s32 *)((u8 *)arg1 + 0x34);
    n = *(volatile s32 *)((u8 *)arg1 + 0x38);
    o = *(volatile s32 *)((u8 *)arg1 + 0x3C);

    *(s32 *)((u8 *)arg0 + 0x54) = g;
    *(s32 *)((u8 *)arg0 + 0x3C) = a;
    *(s32 *)((u8 *)arg0 + 0x40) = b;
    *(s32 *)((u8 *)arg0 + 0x44) = c;
    *(s32 *)((u8 *)arg0 + 0x48) = d;
    *(s32 *)((u8 *)arg0 + 0x4C) = e;
    *(s32 *)((u8 *)arg0 + 0x50) = f;
    *(s32 *)((u8 *)arg0 + 0x58) = h;
    *(s32 *)((u8 *)arg0 + 0x5C) = i;
    *(s32 *)((u8 *)arg0 + 0x60) = j;
    *(s32 *)((u8 *)arg0 + 0x64) = k;
    *(s32 *)((u8 *)arg0 + 0x68) = l;
    *(s16 *)((u8 *)arg0 + 0x6C) = half;
    *(s32 *)((u8 *)arg0 + 0x70) = m;
    *(s32 *)((u8 *)arg0 + 0x74) = n;
    *(s32 *)((u8 *)arg0 + 0x78) = o;
}
s32 fn_801EAF20(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801EAF60(void) {

}

void *fn_802C86DC(void);
float PSVECDotProduct(float *, float *, float);
float fn_801EAF64(void *arg0) {
    float delta[3];
    void *camera;

    camera = fn_802C86DC();
    delta[0] = *(float *)((u8 *)arg0 + 0x28) - *(float *)((u8 *)camera + 0x24);
    delta[1] = *(float *)((u8 *)arg0 + 0x2C) - *(float *)((u8 *)camera + 0x28);
    delta[2] = *(float *)((u8 *)arg0 + 0x30) - *(float *)((u8 *)camera + 0x2C);
    return ((float (*)(float *, float *))PSVECDotProduct)(
        delta, (float *)((u8 *)camera + 0x18));
}

extern void *fn_802C86DC(void);
extern float PSVECDotProduct(float *, float *, float);
extern void fn_801EABA8(void *, void *);
extern void fn_802DAC54(void);
extern int fn_802C7A40(int, void *, int, int, void *, int);
extern void fn_802C70AC(int, void *, int, int);
extern int fn_80128668(void);
extern void fn_802C6CF8(s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_801EAB2C(void*);
extern void fn_801EAB80(void*, s32);
extern u8 lbl_80339E3C[];
