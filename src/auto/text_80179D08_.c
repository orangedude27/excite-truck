// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_80128668(void *);
extern void fn_801E9DC4(void *);
extern s32 lbl_80331C70[16];
extern f32 lbl_80561B78;
extern f32 lbl_80561B7C;
extern void fn_8017A580(void *);
extern f32 PSVECMag(f32 *);
extern f64 sin(f64);
extern f64 cos(f64);
extern void fn_8017AE94(void *, f32 *, f32 *, f32);
extern f64 lbl_80561B90;
extern f32 lbl_80561B80, lbl_80561B84, lbl_80561B88, lbl_80561B8C;

#pragma cplusplus on
struct Fn80179E00Dummy {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
};
struct Fn80179F94Dummy {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual f32 m13(void *, void *, s32) = 0;
};
extern "C" inline void fn_80179E00_virtual_call(void *obj) {
    ((Fn80179E00Dummy *)obj)->m8();
}
#pragma cplusplus reset
extern void fn_80179E00_virtual_call(void *);

#pragma scheduling off
static f32 fn_load(void) { return lbl_80561B78; }
#pragma scheduling invalid_target
void* fn_80179D08(void *arg0) {
    register f32 a = lbl_80561B7C;
    register f32 b = lbl_80561B78;
    *(s32 *)arg0 = (s32)&lbl_80331C70[0];
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_8017A580(arg0);
    fn_801E9DC4((u8 *)arg0 + 0x6C);
    return arg0;
}
#pragma scheduling on
void fn_80179D8C(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

void fn_80179D94(void *arg0, void *arg1) {
    f32 b;
    f32 a;
    s32 zero;
    a = lbl_80561B7C;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = (s32)arg1;
    b = lbl_80561B78;
    *(f32 *)((u8 *)arg0 + 0x30) = a;
    *(f32 *)((u8 *)arg0 + 0x34) = a;
    *(f32 *)((u8 *)arg0 + 0x38) = a;
    *(s32 *)((u8 *)arg0 + 0x24) = zero;
    *(s32 *)((u8 *)arg0 + 0x28) = zero;
    *(f32 *)((u8 *)arg0 + 0x2C) = a;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)arg1;
    *(s32 *)((u8 *)arg0 + 0x4) = zero;
    *(f32 *)((u8 *)arg0 + 0x3C) = b;
    *(f32 *)((u8 *)arg0 + 0x40) = a;
    *(f32 *)((u8 *)arg0 + 0x44) = a;
    *(f32 *)((u8 *)arg0 + 0x48) = a;
    *(f32 *)((u8 *)arg0 + 0x4C) = b;
    *(f32 *)((u8 *)arg0 + 0x50) = a;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = a;
    *(f32 *)((u8 *)arg0 + 0x5C) = b;
    *(f32 *)((u8 *)arg0 + 0x60) = a;
    *(f32 *)((u8 *)arg0 + 0x64) = a;
    *(f32 *)((u8 *)arg0 + 0x68) = a;
    fn_801E9DC4((u8 *)arg0 + 0x6C);
}

#pragma cplusplus on
extern "C" void fn_80179E00(void *arg0) {
    struct Dummy {
        virtual void m0() = 0; virtual void m1() = 0; virtual void m2() = 0;
        virtual void m3() = 0; virtual void m4() = 0; virtual void m5() = 0;
        virtual void m6() = 0; virtual void m7() = 0; virtual void m8() = 0;
    };
    s32 i;
    void *p;
    s32 m, l, k, j, h, g, f, e, d, c, b, a;
    volatile s32 *base = (volatile s32 *)arg0;

    *(s32 *)((u8 *)arg0 + 4) = 0;
    i = 0;
    p = arg0;
    goto check;
loop:
    ((struct Dummy *)*(void **)((u8 *)p + 0x14))->m8();
    p = (u8 *)p + 4;
    i++;
check:
    if (i < *(s32 *)((u8 *)arg0 + 0x28)) goto loop;
    fn_8017A580(arg0);
    b = base[0x70 / 4]; a = base[0x74 / 4];
    c = base[0x78 / 4]; d = base[0x7C / 4];
    e = base[0x80 / 4]; f = base[0x84 / 4];
    g = base[0x88 / 4]; h = base[0x8C / 4];
    j = base[0x90 / 4]; k = base[0x94 / 4];
    l = base[0x98 / 4]; m = base[0x9C / 4];
    *(s32 *)((u8 *)arg0 + 0xA0) = b; *(s32 *)((u8 *)arg0 + 0xA4) = a;
    *(s32 *)((u8 *)arg0 + 0xA8) = c; *(s32 *)((u8 *)arg0 + 0xAC) = d;
    *(s32 *)((u8 *)arg0 + 0xB0) = e; *(s32 *)((u8 *)arg0 + 0xB4) = f;
    *(s32 *)((u8 *)arg0 + 0xB8) = g; *(s32 *)((u8 *)arg0 + 0xBC) = h;
    *(s32 *)((u8 *)arg0 + 0xC0) = j; *(s32 *)((u8 *)arg0 + 0xC4) = k;
    *(s32 *)((u8 *)arg0 + 0xC8) = l; *(s32 *)((u8 *)arg0 + 0xCC) = m;
    fn_801E9DC4((u8 *)arg0 + 0x6C);
    return;
}
#pragma cplusplus reset
void fn_80179EE4(void) {

}

#pragma dont_inline on
#pragma cplusplus on
extern "C" void *fn_80179EE8(void *arg0, s32 arg1) {
    struct ItemDummy {
        virtual void m0(s32) = 0;
    };
    u8 *p;
    void *item;
    s32 i;

    if (arg0 != NULL) {
        *(s32 *)arg0 = (s32)&lbl_80331C70[0];
        p = (u8 *)arg0;
        i = 0;
        goto check;
    loop:
        item = *(void **)(p + 0x14);
        if (item != NULL)
            ((ItemDummy *)item)->m0(1);
        p += 4;
        i += 1;
    check:
        if (i < *(s32 *)((u8 *)arg0 + 0x28))
            goto loop;
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma cplusplus reset
#pragma dont_inline reset

#pragma push
#pragma scheduling off
#pragma cplusplus on
extern "C" void fn_80179F94(void *arg0, void *arg1) {
    s32 count;
    void *slot;
    f32 value;
    f32 old;

    count = *(s32 *)((u8 *)arg0 + 0x24);
    slot = (u8 *)arg0 + count * 4;
    *(void **)((u8 *)slot + 0x14) = arg1;
    count++;
    *(s32 *)((u8 *)arg0 + 0x24) = count;
    *(s32 *)((u8 *)arg0 + 0x28) = count;
    value = ((Fn80179F94Dummy *)arg1)->m13(arg1, slot, count - 1);
    old = *(f32 *)((u8 *)arg0 + 0x2C);
    old = old <= value ? value : old;
    *(f32 *)((u8 *)arg0 + 0x2C) = old;
}
#pragma cplusplus reset
#pragma pop
void fn_8017A004(void) {

}

void fn_8017A008(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}

extern f32 lbl_80561B80, lbl_80561B84, lbl_80561B88, lbl_80561B8C;
extern f64 lbl_80561B90;
extern f32 PSVECMag(f32 *);
extern f64 sin(f64);
extern f64 cos(f64);
extern void fn_8017AE94(void *, f32 *, f32 *, f32);
void fn_8017A028(void *arg0,u16 *arg1,u16 *arg2,s32 *arg3,s32 *arg4,f32 arg5) {
f32 a[3],b[3],m0[12],m1[12],x,y,z,mag,k,c,s,t;
fn_8017A008((u8*)a,(u8*)arg1+8,12); fn_8017A008((u8*)b,(u8*)arg2+8,12);
#define CL(v) ((v)<0.0f?0.0f:((v)>1.0f?1.0f:(v)))
x=CL(((f32)arg1[2]-1.0f)/65535.0f)*2.0f-1.0f; y=CL(((f32)arg1[1]-1.0f)/65535.0f)*2.0f-1.0f; z=CL(((f32)arg1[0]-1.0f)/65535.0f)*2.0f-1.0f; a[0]=x;a[1]=y;a[2]=z;
x=CL(((f32)arg2[2]-1.0f)/65535.0f)*2.0f-1.0f; y=CL(((f32)arg2[1]-1.0f)/65535.0f)*2.0f-1.0f; z=CL(((f32)arg2[0]-1.0f)/65535.0f)*2.0f-1.0f; b[0]=x;b[1]=y;b[2]=z;
mag=PSVECMag(a); if(mag>lbl_80561B8C){k=1.0f/mag;x=a[0]*k;y=a[1]*k;z=a[2]*k;s=(f32)sin(mag);c=(f32)cos(mag);t=1.0f-c;m0[0]=c+t*x*x;m0[1]=t*x*y+s*z;m0[2]=t*x*z-s*y;m0[3]=t*x*y-s*z;m0[4]=c+t*y*y;m0[5]=t*y*z+s*x;m0[6]=t*x*z+s*y;m0[7]=t*y*z-s*x;m0[8]=c+t*z*z;}else{m0[0]=1;m0[1]=0;m0[2]=0;m0[3]=0;m0[4]=1;m0[5]=0;m0[6]=0;m0[7]=0;m0[8]=1;}
mag=PSVECMag(b);if(mag>lbl_80561B8C){k=1.0f/mag;x=b[0]*k;y=b[1]*k;z=b[2]*k;s=(f32)sin(mag);c=(f32)cos(mag);t=1.0f-c;m1[0]=c+t*x*x;m1[1]=t*x*y+s*z;m1[2]=t*x*z-s*y;m1[3]=t*x*y-s*z;m1[4]=c+t*y*y;m1[5]=t*y*z+s*x;m1[6]=t*x*z+s*y;m1[7]=t*y*z-s*x;m1[8]=c+t*z*z;}else{m1[0]=1;m1[1]=0;m1[2]=0;m1[3]=0;m1[4]=1;m1[5]=0;m1[6]=0;m1[7]=0;m1[8]=1;}
fn_8017AE94((u8*)arg0+0x3c,m0,m1,arg5);fn_8017A580(arg0);*arg3=20;*arg4=20;}

void fn_8017A578(void *arg0) {
    fn_8017A580(arg0);
}

void fn_8017A57C(void) {

}

void fn_8017A580(void *arg0) {
    u8 *p = (u8 *)arg0;
    s32 i;
    f32 x, y, z;
    void *v;
    s32 n;
    for (i = 0; i < 12; i++) ((s32 *)p)[0x28/4 + i] = ((s32 *)p)[0x1C/4 + i];
    if (p + 0x94 == p + 0x30) {
        x = *(f32 *)(p+0x30); y = *(f32 *)(p+0x34); z = *(f32 *)(p+0x38);
        *(f32 *)(p+0x94) = (x * *(f32 *)(p+0x3C) + y * *(f32 *)(p+0x48)) + z * *(f32 *)(p+0x54);
        *(f32 *)(p+0x98) = (x * *(f32 *)(p+0x40) + y * *(f32 *)(p+0x4C)) + z * *(f32 *)(p+0x58);
        *(f32 *)(p+0x9C) = (x * *(f32 *)(p+0x44) + y * *(f32 *)(p+0x50)) + z * *(f32 *)(p+0x5C);
    } else {
        x = *(f32 *)(p+0x30); y = *(f32 *)(p+0x34); z = *(f32 *)(p+0x38);
        *(f32 *)(p+0x94) = (x * *(f32 *)(p+0x3C) + y * *(f32 *)(p+0x48)) + z * *(f32 *)(p+0x54);
        *(f32 *)(p+0x98) = (x * *(f32 *)(p+0x40) + y * *(f32 *)(p+0x4C)) + z * *(f32 *)(p+0x58);
        *(f32 *)(p+0x9C) = (x * *(f32 *)(p+0x44) + y * *(f32 *)(p+0x50)) + z * *(f32 *)(p+0x5C);
    }
    *(f32 *)(p+0x94) += *(f32 *)(p+0x60);
    *(f32 *)(p+0x98) += *(f32 *)(p+0x64);
    *(f32 *)(p+0x9C) += *(f32 *)(p+0x68);
    for (i=0;i<9;i++) ((s32 *)p)[0x1c+i] = ((s32 *)p)[0x0f+i];
    if (((s32 (**)(void *))*(void **)p)[17](arg0) && ((s32 (**)(void *))*(void **)p)[16](arg0)) {
      for (i=0;i<*(s32 *)(p+0x28);i++) {
        v=*(void **)(p+0x14+i*4);
        ((void (**)(void *))*(void **)v)[3](v);
      }
    }
}

void fn_8017A800(void) {

}

void fn_8017AB84(void *matrix, float *dst, const float *src) {
    if (dst == src) {
        float x = src[0], y = src[1], z = src[2];
        float ox = (x * *(float *)((char *)matrix + 0x3C) + y * *(float *)((char *)matrix + 0x48)) + z * *(float *)((char *)matrix + 0x54);
        float oy = (x * *(float *)((char *)matrix + 0x40) + y * *(float *)((char *)matrix + 0x4C)) + z * *(float *)((char *)matrix + 0x58);
        float oz = (x * *(float *)((char *)matrix + 0x44) + y * *(float *)((char *)matrix + 0x50)) + z * *(float *)((char *)matrix + 0x5C);
        dst[0] = ox;
        dst[1] = oy;
        dst[2] = oz;
    } else {
        dst[0] = (src[0] * *(float *)((char *)matrix + 0x3C) + src[1] * *(float *)((char *)matrix + 0x48)) + src[2] * *(float *)((char *)matrix + 0x54);
        dst[1] = (src[0] * *(float *)((char *)matrix + 0x40) + src[1] * *(float *)((char *)matrix + 0x4C)) + src[2] * *(float *)((char *)matrix + 0x58);
        dst[2] = (src[0] * *(float *)((char *)matrix + 0x44) + src[1] * *(float *)((char *)matrix + 0x50)) + src[2] * *(float *)((char *)matrix + 0x5C);
    }
    dst[0] += *(float *)((char *)matrix + 0x60);
    dst[1] += *(float *)((char *)matrix + 0x64);
    dst[2] += *(float *)((char *)matrix + 0x68);
}


void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017B038(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_8017B090(void) {

}

int fn_8017B094(void) {
    return 0x14;
}

void fn_8017B09C(void* arg0, signed char* arg1) {
    *arg1 = 0;
}
extern int lbl_80331C28[64];
#pragma scheduling off
void** fn_8017ACCC(void** arg0) {
    fn_80179D08(arg0);
    *arg0 = &lbl_80331C28;
    return arg0;
}

extern void *fn_801284F8(int, void *);
extern void fn_80179F94(void *, void *);
extern void fn_802E30C8(const char *);
extern f32 fn_8002F234(void *, int, int, f32, f32, f32, f32, f32, f32, f32);
extern f32 lbl_80561BA0, lbl_80561BA4;
extern const char lbl_80331BF8[], lbl_80331C04[], lbl_80333B98[], lbl_803338C0[];
#pragma dont_inline fn_80179F94
void fn_8017AD08(void *dst, void *src) {
    unsigned char *srcBytes = (unsigned char *)src;
    unsigned char *dstBytes = (unsigned char *)dst;
    void *obj;
    int first, second;
    int zero = 0;
    int box = 0x424F5820;
    float x, y, z;
    const char *vtable;

    ((void (*)(void *))fn_80179D94)(dst);

    first = *(int *)(srcBytes + 8);
    second = *(int *)(srcBytes + 0xC);
    *(int *)(dstBytes + 0x3C) = first;
    *(int *)(dstBytes + 0x40) = second;
    first = *(int *)(srcBytes + 0x10);
    second = *(int *)(srcBytes + 0x14);
    *(int *)(dstBytes + 0x44) = first;
    *(int *)(dstBytes + 0x48) = second;
    first = *(int *)(srcBytes + 0x18);
    second = *(int *)(srcBytes + 0x1C);
    *(int *)(dstBytes + 0x4C) = first;
    *(int *)(dstBytes + 0x50) = second;
    first = *(int *)(srcBytes + 0x20);
    second = *(int *)(srcBytes + 0x24);
    *(int *)(dstBytes + 0x54) = first;
    *(int *)(dstBytes + 0x58) = second;
    *(int *)(dstBytes + 0x5C) = *(int *)(srcBytes + 0x28);
    first = *(int *)(srcBytes + 0x2C);
    second = *(int *)(srcBytes + 0x30);
    *(int *)(dstBytes + 0x60) = first;
    *(int *)(dstBytes + 0x64) = second;
    *(int *)(dstBytes + 0x68) = *(int *)(srcBytes + 0x34);

    fn_8017A580(dst);
    if (*(int *)(srcBytes + 0x38) == 0) {
        obj = fn_801284F8(0x38, (void *)lbl_80331BF8);
        if (obj != 0) {
            z = *(float *)(srcBytes + 0x44);
            vtable = lbl_80333B98;
            y = *(float *)(srcBytes + 0x40);
            x = *(float *)(srcBytes + 0x3C);
            *(void **)obj = (void *)vtable;
            *(void **)((unsigned char *)obj + 0xC) = dstBytes + 0x3C;
            *(float *)((unsigned char *)obj + 0x10) = lbl_80561BA0;
            *(float *)((unsigned char *)obj + 0x14) = lbl_80561BA4;
            *(int *)((unsigned char *)obj + 0x18) = box;
            *(int *)((unsigned char *)obj + 0x20) = 100;
            *(int *)((unsigned char *)obj + 4) = zero;
            *(int *)((unsigned char *)obj + 8) = zero;
            *(int *)((unsigned char *)obj + 0x1C) = zero;
            *(void **)obj = (void *)lbl_803338C0;
            *(float *)((unsigned char *)obj + 0x24) = x;
            *(float *)((unsigned char *)obj + 0x28) = y;
            *(float *)((unsigned char *)obj + 0x2C) = z;
            *(int *)((unsigned char *)obj + 0x34) = zero;
            *(float *)((unsigned char *)obj + 0x30) = lbl_80561BA4 +
                (float)((double (*)(float))fn_8002F234)(x * x + y * y + z * z);
            fn_80179F94(dst, obj);
            return;
        }
    }
    fn_802E30C8(lbl_80331C04);
}

extern void PSVECCrossProduct(float *, float *, float *);
extern void PSVECNormalize(float *, float *);
void fn_8017AE94(void *arg0, float *arg1, float *arg2, float farg0) {
    float *base = (float *)arg0;
    float *out = base;
    float *a = arg1, *b = arg2;
    float sp8[3], sp14[3], sp20[3];
    int i;
    for (i = 0; i < 2; i++) {
        out[0] = a[0] + farg0 * (b[0] - a[0]);
        out[1] = a[1] + farg0 * (b[1] - a[1]);
        out[2] = a[2] + farg0 * (b[2] - a[2]);
        out[3] = a[3] + farg0 * (b[3] - a[3]);
        out[4] = a[4] + farg0 * (b[4] - a[4]);
        out[5] = a[5] + farg0 * (b[5] - a[5]);
        out += 6; a += 6; b += 6;
    }
    PSVECNormalize(base, base); PSVECNormalize(base + 3, base + 3); PSVECNormalize(base + 6, base + 6);
    sp8[0]=base[0]; sp8[1]=base[1]; sp8[2]=base[2];
    sp20[0]=base[6]; sp20[1]=base[7]; sp20[2]=base[8];
    PSVECCrossProduct(sp20, sp8, sp14);
    PSVECNormalize(sp8, sp8); PSVECNormalize(sp14, sp14);
    PSVECCrossProduct(sp8, sp14, sp20);
    base[0]=sp8[0]; base[1]=sp8[1]; base[2]=sp8[2];
    base[3]=sp14[0]; base[4]=sp14[1]; base[5]=sp14[2];
    base[6]=sp20[0]; base[7]=sp20[1]; base[8]=sp20[2];
}

#pragma scheduling on
