

#include <types.h>

extern float lbl_8056208C;
extern float lbl_80562090;
extern float lbl_805620AC;
extern float lbl_80562080;
extern int lbl_8055E3C4;
extern int lbl_8055E524;
void fn_80191084(int, int);
int fn_801B89E0(void);
int fn_8018FD38(void) {
    int result = 0;
    if (lbl_8055E3C4 + 1 >= lbl_8055E524 || fn_801B89E0() != 0) result = 1;
    return result;
}

extern s32 fn_801293A4(void);
extern void fn_8018FC38(void);
extern void fn_801B664C(void);
extern s32 fn_801B6668(s32, s32, s32);
extern u8 lbl_80333018[];
extern void* lbl_804349A0[];
extern f32 lbl_8055A468, lbl_8055A46C;
extern s32 lbl_8055E518;
extern u8 lbl_8055E520, lbl_8055E523;
extern f64 lbl_80562070;
extern f32 lbl_80562078, lbl_8056207C, lbl_80562080;
void* fn_8018FD88(void* arg0, s32 arg1, s32 arg2) {
    f32 value;
    f32 result;
    f32 limit;
    s32 index;
    *(void**)arg0 = lbl_80333018;
    if (lbl_8055E518 == 0) fn_8018FC38();
    index = lbl_8055E518;
    lbl_804349A0[index] = arg0;
    lbl_8055E518 = index + 1;
    ((u8*)arg0)[0x38] = 1;
    lbl_8055E520 = 0;
    lbl_8055E523 = 0;
    *(s32*)((u8*)arg0 + 8) = arg1;
    *(s32*)((u8*)arg0 + 0xC) = arg2;
    *(s32*)((u8*)arg0 + 0x10) = 0;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 0x28) = 0x10000;
    if (fn_801B6668(0, 1, index + 1) == 0) fn_801B664C();
    value = lbl_80562078 * (f32)fn_801293A4();
    result = value - lbl_8056207C;
    limit = lbl_80562080;
    lbl_8055A46C = value;
    if (limit > result) limit = result;
    lbl_8055A468 = limit;
    return arg0;
}

int fn_8018FF84(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_80190184(void *arg0, void *arg1) {
    struct Dummy0 {
        virtual void v0();
        virtual void v1();
        virtual void v2();
    };
    struct Dummy1 {
        virtual void v0();
        virtual void v1();
        virtual void v2(void *);
    };
    Dummy0 *obj;
    Dummy1 *obj2;

    *(void **)((char *)arg0 + 0x20) = arg1;
    *(s32 *)((char *)arg0 + 0x1C) = *(s32 *)((char *)arg1 + 0x1EC);
    obj = *(Dummy0 **)((char *)arg0 + 8);
    obj->v2();
    obj2 = *(Dummy1 **)((char *)arg0 + 0xC);
    obj2->v2(arg1);
}
#pragma cplusplus reset
void fn_80190360(int arg0) {
    fn_80191084(arg0, 0);
}

#pragma scheduling off
int fn_80190D38(float a, float b, float c) { float lower; float value; lower = lbl_80562090; value = (a - b) / (c - b); if (lower < value) { lower = value; } else { lower = lower; } if (lower > lbl_8056208C) { lower = lbl_8056208C; } else { lower = lower; } return (int)(lbl_80562080 + (lbl_8056208C + (lower * lbl_805620AC))); }
#pragma scheduling on
int fn_80190E00(void *arg0) { return ((int *)arg0)[2]; }

void fn_80190E6C(void) {
    fn_80190E08();
}

void fn_80190F90(void) {
    fn_80191758();
}

void fn_80191060(void) {
    fn_801B6664();
}

int fn_80191100(void *arg0) { return ((int *)arg0)[3]; }

#pragma cplusplus on
extern "C" void fn_801914F8(void *arg0) {
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f8();
}
#pragma cplusplus off
u8 fn_8019157C(void *arg0) { return *((u8 *)arg0 + 0x14); }

#pragma cplusplus on
extern "C" void fn_80191688(void *arg0) {
    class Inner {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
    };
    struct DummyWrapper {
        int pad;
        Inner *inner;
    };
    ((DummyWrapper *)arg0)->inner->f26();
}
#pragma cplusplus off

void fn_8019169C(void *arg0, void *arg1) {
    *(void **)((char *)arg0 + 0x34) = arg1;
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg1 + 0x1EC);
}

void *fn_801916AC(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0x38) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern char *strcpy(char *, const char *);
extern unsigned char lbl_804A16E8[];
int fn_80191758(arg0)
void *arg0;
{
    char *dst;
    dst = (char *)lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    strcpy(dst, *(char **)((char *)arg0 + 0x20) + 0x234);
    dst = (char *)lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x28) = lbl_8056208C;
    *(float *)(dst + 0x24) = lbl_8056208C;
    *(float *)(dst + 0x20) = lbl_8056208C;
    *(float *)(dst + 0x34) = lbl_80562090;
    *(float *)(dst + 0x30) = lbl_80562090;
    *(float *)(dst + 0x2C) = lbl_80562090;
    *(float *)(dst + 0x38) = lbl_80562090;
    *(float *)(dst + 0x3C) = lbl_80562090;
    dst = (char *)lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x48) = lbl_8056208C;
    *(float *)(dst + 0x44) = lbl_8056208C;
    *(float *)(dst + 0x40) = lbl_8056208C;
    *(float *)(dst + 0x54) = lbl_80562090;
    *(float *)(dst + 0x50) = lbl_80562090;
    *(float *)(dst + 0x4C) = lbl_80562090;
    *(float *)(dst + 0x58) = lbl_80562090;
    *(float *)(dst + 0x5C) = lbl_80562090;
    dst = (char *)lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x68) = lbl_8056208C;
    *(float *)(dst + 0x64) = lbl_8056208C;
    *(float *)(dst + 0x60) = lbl_8056208C;
    *(float *)(dst + 0x74) = lbl_80562090;
    *(float *)(dst + 0x70) = lbl_80562090;
    *(float *)(dst + 0x6C) = lbl_80562090;
    *(float *)(dst + 0x78) = lbl_80562090;
    *(float *)(dst + 0x7C) = lbl_80562090;
    dst = (char *)lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x88) = lbl_8056208C;
    *(float *)(dst + 0x84) = lbl_8056208C;
    *(float *)(dst + 0x80) = lbl_8056208C;
    *(float *)(dst + 0x94) = lbl_80562090;
    *(float *)(dst + 0x90) = lbl_80562090;
    *(float *)(dst + 0x8C) = lbl_80562090;
    *(float *)(dst + 0x98) = lbl_80562090;
    *(float *)(dst + 0x9C) = lbl_80562090;
}

int fn_80191A98(void *arg0) {
    int bit = (*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 1) & 1;
    return (int)((unsigned int)(-bit | bit) >> 31);
}

void fn_80192BE4(void) {

}

#pragma cplusplus on
extern "C" void fn_80192C10(void *arg0) {
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f20();
}

#pragma cplusplus on
extern "C" void fn_80192C24(void *arg0) {
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f19();
}
#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80192C38(void *arg0) {
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f18();
}
#pragma cplusplus reset

s32 fn_80192C4C(void *arg0) {
    s32 bit = (*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 2) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

int fn_80192C68(void *arg0) {
    return (((unsigned char)*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 5) & 7) - 1;
}

unsigned char fn_80192F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_80192F74(void *arg0) {
    *(int *)((char *)arg0 + 0xC) = lbl_8055E3C4;
}

int fn_80193010(void) { return 0x20; }

void fn_8019304C(void *arg0) {
    *(float *)((char *)arg0 + 0x40) = lbl_8056208C;
}

void fn_80193058(void) {
}

unsigned char fn_8019305C(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

unsigned char fn_80193064(void *arg0) {
    return *((unsigned char *)arg0 + 0x13);
}

