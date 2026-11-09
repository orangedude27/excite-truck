// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
#include <stdarg.h>
extern void fn_802C744C(s32, f32 *);
extern int fn_801476C4();
extern u8 *__AXGetStackHead();
extern void fn_801308F4(void *, s32, s32);
extern void fn_801308F8(void *, s32, s32);
extern u8 *fn_80130FE0(s32);
extern u8 *fn_80131234(void *);
extern void fn_802ADFF4(s32, s32);
extern void fn_802AE02C(s32, s32);
extern void fn_802AE0B8(s32, s32);
extern void fn_802AE168(s32);
extern s32 fn_801609C4(s32);
extern s32 fn_801345D8(void *, s32, ...);
extern void fn_802E30C8(void *, ...);
extern void fn_802AE0E0(void *);
extern s32 fn_80179650(void);
extern u8 lbl_8032D358[];
extern s32 lbl_8055E3C4;
extern f32 lbl_8055E3C8, lbl_8056163C, lbl_8056164C;
extern u8 lbl_80559F04;
extern u8 lbl_80559F08;
extern u8 lbl_80559F0C;
#define lbl_80559F04 (&lbl_80559F04)
#define lbl_80559F08 (&lbl_80559F08)
#define lbl_80559F0C (&lbl_80559F0C)
/* copy at most n chars, always terminated; macro keeps source-first evaluation order */
#define StrCopyN80149658(d, s, cnt) do { \
    const u8 *sp_ = (s); \
    int n_; \
    u8 *dp_ = (d); \
    n_ = (cnt); \
    while ((s8)(*dp_++ = *sp_++) != 0) { \
        if (--n_ <= 0) { \
            dp_[-1] = 0; \
            break; \
        } \
    } \
} while (0)
#include "revolution/MTX/mtxtypes.h"
typedef struct { void *pad[3]; void *(*get)(void *, int); } IterFC;
typedef struct { void *pad[3]; int (*has)(void *, void *); void *(*next)(void *, void *); } IterFD;
typedef struct { void *pad[15]; int (*has)(void *, void *); void *(*value)(void *, void *); } IterFE;
typedef struct { void *pad[14]; void *(*begin)(void *, void *, void *); } ObjFA;
typedef struct { float x,y,z,w; u8 flag; } EntryFC;
extern f32 fn_80144514(f32,f32,f32,f32,f32,f32);
static inline void MatrixMul80151E60(f32 *dst, const f32 *left, const f32 *right) {
 if (dst == right || dst == left) {
 f32 t0 = fn_80144514(left[0],right[0],left[3],right[1],left[6],right[2]);
 f32 t3 = fn_80144514(left[0],right[3],left[3],right[4],left[6],right[5]);
 f32 t6 = fn_80144514(left[0],right[6],left[3],right[7],left[6],right[8]);
 f32 t1 = fn_80144514(left[1],right[0],left[4],right[1],left[7],right[2]);
 f32 t4 = fn_80144514(left[1],right[3],left[4],right[4],left[7],right[5]);
 f32 t7 = fn_80144514(left[1],right[6],left[4],right[7],left[7],right[8]);
 f32 t2 = fn_80144514(left[2],right[0],left[5],right[1],left[8],right[2]);
 f32 t5 = fn_80144514(left[2],right[3],left[5],right[4],left[8],right[5]);
 f32 t8 = fn_80144514(left[2],right[6],left[5],right[7],left[8],right[8]);
 dst[0]=t0;
 dst[3]=t3;
 dst[6]=t6;
 dst[1]=t1;
 dst[4]=t4;
 dst[7]=t7;
 dst[2]=t2;
 dst[5]=t5;
 dst[8]=t8;
 } else {
 dst[0]=fn_80144514(left[0],right[0],left[3],right[1],left[6],right[2]);
 dst[3]=fn_80144514(left[0],right[3],left[3],right[4],left[6],right[5]);
 dst[6]=fn_80144514(left[0],right[6],left[3],right[7],left[6],right[8]);
 dst[1]=fn_80144514(left[1],right[0],left[4],right[1],left[7],right[2]);
 dst[4]=fn_80144514(left[1],right[3],left[4],right[4],left[7],right[5]);
 dst[7]=fn_80144514(left[1],right[6],left[4],right[7],left[7],right[8]);
 dst[2]=fn_80144514(left[2],right[0],left[5],right[1],left[8],right[2]);
 dst[5]=fn_80144514(left[2],right[3],left[5],right[4],left[8],right[5]);
 dst[8]=fn_80144514(left[2],right[6],left[5],right[7],left[8],right[8]);
 }
}


typedef struct { s32 a, b, c, d; f32 e, f; s32 g; } Copy8014C6F0;
typedef struct { f32 m[12]; } Matrix801533E8;
typedef struct { f32 pos[3]; f32 velocity[3]; s16 angle; s32 value; } Event80155700;
extern u8 lbl_80559FB8[1];
extern f32 lbl_8056172C, lbl_80561730;
extern s32 fn_80009C84(void);
extern void fn_801796EC(s32, void *, s32);
extern void fn_8018A120(void *);
extern void fn_80161A38(s32, s32, s32);
extern void fn_80206750(void *, s32, s32);
static inline void Transform801533E8(f32 *dst, const f32 *src, const f32 *m) {
    if (dst == src) {
        f32 x = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        f32 y = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        f32 z = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}

extern s32 lbl_8032E1A0[];
extern f32 lbl_80561648;
extern f32 lbl_8056171C;
extern f32 lbl_805616CC;
extern s32 lbl_8055E244;
extern s32 lbl_8055E248;
extern s32 lbl_8055E250;
extern void *lbl_8055E268;
extern u8 lbl_8032D970[];
typedef struct { void *pad[2]; void (*destroy)(void *, int); } VTable8014E9C4;
typedef struct { VTable8014E9C4 *vtable; } Object8014E9C4;

extern s32 lbl_8055E238;
extern s32 lbl_8055E23C;
extern s32 fn_80179650(void);
extern s32 fn_801E85A4(void);
extern s32 fn_801E86F8(s32);
extern s32 fn_801E866C(s32);
extern s32 fn_8014CA48(s32, s32, s32);
extern s32 fn_8014AFD4(void *, void *, s32);
extern s32 fn_801CB7BC(s32);
extern void *fn_802ADE60(void **, int);
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801B2ED0(s32);
typedef struct {
    void *pad[4];
    s32 (*fn)(void);
} VTable8014ACD8;
typedef struct {
    VTable8014ACD8 *vtable;
    u8 pad[0x20];
    s32 state;
    u8 flags;
} Obj8014ACD8;

extern s32 fn_80161C94(void);
extern void fn_801B8A84(s32);
extern s32 fn_801B2F24(void);
extern s32 fn_801B8514(void);
extern s32 lbl_804348E8[];
extern void fn_801B8A7C(void);
extern s32 lbl_8032E030[];
extern s32 lbl_8032E048[];
extern s32 lbl_8055E4D0;
typedef struct {
    s32 pad[8];
    s32 (*fn)(void *, s32);
} VTable80154618;
#pragma cplusplus on
class TObj80154618 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual int f6(int);
    virtual void d7();
    virtual int f8(int);
};
class Dummy_8015180C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
      virtual void d4(); virtual void d5();
      virtual void call(s32, f32);
};
class Cleanup8014E9C4 {
public:
    virtual void destroy(int);
};
class Dummy_80149274 {
public:
    virtual void d0();
    virtual void d1();
    virtual s32 d2();
};
class Dummy_80151984 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual s32 check();
};
class Iter_8014E1D0 {
public:
    virtual void *open(char *);
    virtual int has(char *);
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void *next(char *);
    virtual s32 get(char *, s32);
};
#pragma cplusplus off
extern u8 lbl_8032D358[];
extern void *fn_80131808(void *, s32, s32);
extern void fn_80131818(void *);
extern void *fn_8012850C(s32, void *);
extern f32 lbl_8056163C, lbl_8056164C, lbl_80561670, lbl_805616C8;
extern f64 lbl_805616A0;
extern f64 fn_8002EFB4(f64, f64);
extern s32 fn_80147940(void *, void *, void *, s32);
extern s32 fn_80147C50(s32, s32, f32, f32, f32, f32);
typedef struct { s32 v[4]; } S4_80149234;
extern s32 lbl_802F93D0[];
extern f32 lbl_805615D4;
extern f64 lbl_805615D8;
extern f32 lbl_80561628;
extern f32 lbl_8056162C;
extern f32 lbl_80561630;
extern f32 lbl_80561634;
extern f32 lbl_8055E3C8;
typedef struct { void *pad[14]; s32 (*fn7)(void); } VTableE708;
typedef struct { VTableE708 *vtable; } ObjE708;

extern s32 fn_800167F4(void);
extern f32 fn_801E7E18(void);
extern void fn_802AE220(void *);
extern void fn_8002F634(void *, void *, s32, s32);
extern f32 lbl_80561648, lbl_80561688, lbl_805616C0, lbl_805616C4;
extern u8 lbl_8032E190[];
extern s32 fn_8014EFC0(s32, s32);
extern void fn_80128668(void *);
void *fn_801491B8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_80149210(int *p) {
    p[1] = (p[1] + 1) % 4;
}

s32 fn_80149234(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93D0;
    return sp8.v[((s32 *)arg0)[1]];
}

extern s32 lbl_8055E240;
extern f32 lbl_80561714, lbl_80561718;
#pragma cplusplus on
extern "C" s32 fn_80149274(Dummy_80149274 *arg0) {
    return arg0->d2() & 0xFF7F7F7F;
}
#pragma cplusplus off
void fn_801492AC(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 f2 = lbl_80561628;
    f32 b = *arg1;
    f32 v = b + (f32)obj[0x18];
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_805615D4) ? f2 : lbl_805615D4;
    obj[0x18] = (u8)(s32)f2;
}

extern s32 lbl_802F93E0[];
s32 fn_8014931C(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93E0;
    return sp8.v[((s32 *)arg0)[1]];
}

void fn_8014935C(int *p) {
    p[1] = (p[1] + 1) % 4;
}

extern s32 lbl_802F93F0[];
s32 fn_80149380(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93F0;
    return sp8.v[((s32 *)arg0)[1]];
}

#pragma cplusplus on
extern "C" s32 fn_801493C0(Dummy_80149274 *arg0) {
    return arg0->d2() & 0xFF7F7F7F;
}
#pragma cplusplus off
void fn_801493F8(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 f2 = lbl_80561628;
    f32 b = *arg1;
    f32 v = b + (f32)obj[0x18];
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_805615D4) ? f2 : lbl_805615D4;
    obj[0x18] = (u8)(s32)f2;
}

extern s32 lbl_802F9400[];
s32 fn_80149468(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F9400;
    return sp8.v[((s32 *)arg0)[1]];
}

s32 fn_801494A8(void) {
    return 0xFF00FF00;
}

void fn_801494B4(void *arg0, f32 *arg1, f32 *arg2) {
    f32 y = arg2[1] + arg1[0];
    f32 z = arg2[2] + arg1[1];
    arg2[1] = y;
    arg2[2] = z;
}

extern unsigned long lbl_80559E94;
unsigned long *fn_801494D8(void) { return &lbl_80559E94; }

int fn_801494E0(void) { return 0xFF0000FF; }

void fn_801494EC(void *arg0, float *arg1, float *arg2) {
    float a; float b; float c; float d; float e; float f; float g; float h; float i; float j;
    a = arg2[1];
    b = arg1[0];
    c = arg2[4];
    d = a + b;
    e = arg2[2];
    f = c - b;
    g = arg1[1];
    h = arg2[5];
    i = e + g;
    arg2[1] = d;
    j = h - g;
    arg2[4] = f;
    arg2[2] = i;
    arg2[5] = j;
}

extern unsigned long lbl_80559E94;
extern unsigned long lbl_80559E9C;
extern s32 lbl_80559EA4;
extern void fn_80130980(void *arg0, s32 arg1, s32 arg2);
extern void fn_801474EC(s32 arg0, s32 *arg1, void *arg2);
extern s32 lbl_80559EC4;
extern void *fn_8017960C(s32 arg0);
extern void fn_80149D64(void *arg0, void *arg1, s32 arg2);
extern f32 lbl_80561648;
unsigned long *fn_80149528(void) { return &lbl_80559E9C; }

int fn_80149530(void) {
    return 0xFFC0D9D9;
}

void fn_8014953C(void *arg0, float *arg1, float *arg2) {
    float f2 = lbl_8056162C;
    float v = arg2[4] + f2 * *arg1;
    f2 = lbl_80561630;
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_80561634) ? f2 : lbl_80561634;
    arg2[4] = f2;
}

s32 *fn_80149580(void) {
    return &lbl_80559EA4;
}

void fn_80149588(s32 arg0) {
    s32 sp8;
    fn_80130980(&sp8, 0x20, 3);
    fn_801474EC(arg0, &lbl_80559EC4, &sp8);
}

extern s32 lbl_8055E3C4;
extern f32 lbl_80561638, lbl_8056163C;
extern f64 lbl_80561640;
extern f64 sin(f64);
#pragma scheduling invalid_target
#pragma dont_inline on
f32 fn_801495D4(s32 arg0) {
    f32 scale = lbl_80561638;
    f32 fraction = (f32)(lbl_8055E3C4 % arg0);
    f32 angle = (f32)arg0;
    f32 wave = scale * fraction;
    f32 normalized = wave / angle;
    return lbl_8056163C + lbl_8056163C * (f32)sin((f64)normalized);
}
#pragma dont_inline off
#pragma scheduling on

void fn_80149650(void) { fn_801495D4(0x40); }

u32 fn_80149658(s32 selfAddr, void *aArg, void *listArg, s32 unused) {
    u8 *self = (u8 *)selfAddr;
    u8 *a = (u8 *)aArg;
    u8 *list = (u8 *)listArg;
    u8 buf[0x32];
    s32 s30, s25, s26;
    s32 id;
    f32 f4, t;
    int i;
    u8 *p;
    u8 *tbl = lbl_8032D358;

    if (*(s32 *)(self + 8) == 0) return 0;
    id = *(s32 *)(a + 4);
    fn_801345D8(self + 0x2C, 0x14, lbl_80559F04, id);
    StrCopyN80149658(self + 0x40, fn_80130FE0(id), 5);
    if (fn_80179650() == 1) {
        fn_801345D8(buf, 0x32, tbl + 0x30, *(s32 *)(a + 4));
        StrCopyN80149658(self + 0x1FD, fn_80131234(buf), 0x28);
    } else {
        StrCopyN80149658(self + 0x1FD, fn_80131234(tbl + 0x50), 0x28);
    }
    s30 = *(s32 *)(a + 0x20);
    i = 0;
    if (s30 != 0 && *(f32 *)(self + 4) > lbl_80561648) {
        f4 = lbl_8056164C;
        t = ((lbl_8055E3C8 - *(f32 *)(self + 4)) - lbl_80561648) / f4;
        f4 = (f4 < t) ? f4 : t;
        f4 = (f4 > lbl_80561648) ? f4 : lbl_80561648;
        i = (s32)(lbl_80561648 + f4 * ((lbl_8056163C + (f32)s30) - lbl_80561648));
    }
    fn_801308F4(self + 0x45, 0x14, i);
    s26 = *(s32 *)(a + 0x24);
    s25 = s26 - s30;
    fn_801308F4(self + 0x59, 0x14, s25);
    fn_801308F8(self + 0x6D, 0x14, s26);
    fn_801345D8(self + 0x225, 0x14, *(s32 *)(a + 0x1C) != 0 ? lbl_80559F04 : lbl_80559F08);
    if (fn_801609C4(s25) != -1) StrCopyN80149658(self + 0x81, __AXGetStackHead(), 10);
    else StrCopyN80149658(self + 0x81, lbl_80559F0C, 10);
    if (*(s32 *)(a + 0x30) != -1) StrCopyN80149658(self + 0x8B, __AXGetStackHead(), 10);
    else StrCopyN80149658(self + 0x8B, lbl_80559F0C, 10);
    for (i = 0; i < *(s32 *)(list + 8); i++) {
        p = *(u8 **)(list + 4) + i * 0xF8;
        StrCopyN80149658(self + 0x95 + i * 0x14, p + 4, 0x14);
        StrCopyN80149658(self + 0x149 + i * 0x14, p + 0xA4, 0x14);
    }
    for (; i < 9; i++) {
        StrCopyN80149658(self + 0x95 + i * 0x14, lbl_80559F0C, 0x14);
        StrCopyN80149658(self + 0x149 + i * 0x14, lbl_80559F0C, 0x14);
    }
    fn_802AE168(*(s32 *)(self + 8));
    switch (*(s32 *)self) {
    case 0:
        fn_802E30C8(tbl + 0x70, tbl + 0xA0, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
        fn_802ADFF4(*(s32 *)(self + 8), *(s32 *)(self + 0x1C));
        if (s30 > 0) p = *(u8 **)(self + 0x10);
        else p = *(u8 **)(self + 0x14);
        if (p != 0) { p[0x49] = 1; p[0x4B] = 0; p[0x4A] = 0; }
        *(s32 *)self = 1;
        break;
    case 1:
        if (*(s32 *)(self + 0x20) != 0 && *(f32 *)(self + 4) < lbl_80561648) {
            fn_802E30C8(tbl + 0x70, tbl + 0xC4, lbl_8055E3C4, *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
            *(f32 *)(self + 4) = lbl_8055E3C8;
        }
        if (*(s32 *)(self + 0x24) != 0) {
            fn_802E30C8(tbl + 0x70, tbl + 0xE8, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x28));
            fn_802AE02C(*(s32 *)(self + 8), *(s32 *)(self + 0x1C));
            *(s32 *)self = 2;
        }
        break;
    case 2:
        if (self[0xC] != 0) {
            fn_802E30C8(tbl + 0x70, tbl + 0x10C, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
            fn_802AE0B8(*(s32 *)(self + 8), *(s32 *)(self + 0x1C));
            p = *(u8 **)(self + 0x18);
            if (p != 0) { p[0x49] = 1; p[0x4B] = 0; p[0x4A] = 0; }
            *(s32 *)self = 3;
        }
        break;
    case 3:
        if (*(s32 *)(self + 0x28) != 0) {
            fn_802E30C8(tbl + 0x70, tbl + 0x130, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24));
            fn_802AE0E0((void *)*(s32 *)(self + 8));
            *(s32 *)self = 4;
        }
        break;
    }
    return *(s32 *)self != 4;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80149CEC(void *arg0, void * __restrict arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void* f2();
    };
    void *r5 = *(void **)((u8 *)arg1 + 0x68);
    void *r3;
    s32 val;
    *(f32 *)((u8 *)arg0 + 0x28) = *(f32 *)((u8 *)r5 + 0x8D4);
    r3 = *(void **)((u8 *)fn_8017960C(*(s32 *)arg1) + 0x270);
    r3 = ((Dummy *)r3)->f2();
    val = *(s32 *)((u8 *)r3 + 4);
    *(s32 *)((u8 *)arg0 + 4) = val;
    *(s32 *)((u8 *)arg0 + 0x10) = val - 1;
    fn_80149D64(arg0, arg1, val);
}
#pragma pop
#pragma dont_inline reset
extern f32 fn_80149F00(void *, void *);
extern s32 fn_801609C4(s32);
void fn_80149D64(void *arg0, void *arg1, s32 arg2) {
    int index;
    f32 rate;
    int value;
    int count;
    void *object;
    f32 end;
    if (*(u8 *)((char *)arg0 + 0x34) != 0) index = 0;
    else {
        f32 frame = *(f32 *)((char *)arg1 + 0x14);
        index = (int)(frame < lbl_80561648 ? frame - lbl_8056163C : lbl_8056163C + frame);
    }
    *(int *)arg0 = index;
    if (fn_80179650() > 1) {
        rate = fn_80149F00(arg0, arg1);
        value = *(int *)((char *)arg0 + 0x10) == 0
            ? *(int *)((char *)arg0 + 0x14) + (int)((f32)*(int *)((char *)arg0 + 0x18) * rate)
            : 0;
        if (value != *(int *)((char *)arg0 + 0x20)) {
            object = *(void **)((char *)arg1 + 8);
            if (object != 0 && *(void **)((char *)object + 0x1258) != 0) {
                char *p = *(char **)((char *)object + 0x1258);
                p[0x49] = 1;
                p[0x4B] = 0;
                p[0x4A] = 0;
            }
        }
        *(int *)((char *)arg0 + 0x20) = value;
    } else {
        count = *(int *)((char *)arg0 + 0x10);
        if (count < 0) goto no_frame;
        if (count >= *(int *)((char *)arg0 + 0x0C)) goto no_frame;
        value = *(int *)(*(char **)((char *)arg0 + 8) + count * 4);
        goto frame_ready;
    no_frame:
        value = 0;
    frame_ready:
        *(int *)((char *)arg0 + 0x20) = value;
    }

    object = *(void **)((char *)arg1 + 0x68);
    {
        f32 threshold = lbl_80561648;
        f32 top = *(f32 *)((char *)object + 0x8DC);
        f32 bottom = *(f32 *)((char *)object + 0x8D4);
        f32 difference = top - bottom;
        if (threshold > difference) {
            difference = threshold;
        }
        end = difference;
    }
    *(int *)((char *)arg0 + 0x24) = *(int *)arg0 + *(int *)((char *)arg0 + 0x20);
    *(int *)((char *)arg0 + 0x1C) = (int)end;
    *(int *)((char *)arg0 + 0x30) = fn_801609C4(*(int *)((char *)arg0 + 0x24));
}

f32 fn_80149F00(void *arg0, void *arg1) {
    f32 f0;
    f32 f2;
    void *r3;
    f0 = *(f32 *)((u8 *)arg0 + 0x2C);
    if (f0 < lbl_80561648) return lbl_80561648;
    r3 = *(void **)((u8 *)arg1 + 0x68);
    f2 = *(f32 *)((u8 *)r3 + 0x8D4);
    f0 = f2 - f0;
    if (lbl_80561648 > f0) return lbl_80561648;
    return f0;
}

s32 fn_8014ACBC(void) { return 0; }

s32 fn_8014ACC4(void) { return 0; }

void fn_8014ACCC(void) {

}

void fn_8014ACD0(void) {

}

void fn_8014ACD4(void) {

}

#pragma cplusplus on
extern "C" s32 fn_8014ACD8(void *arg0, s32 arg1) {
    class Obj {
    public:
        virtual void *v0();
        virtual void *v1();
        virtual void *v2();
        u8 pad[0x20];
        s32 state;
        u8 flags;
    };
    Obj *obj = (Obj *)fn_801B2ED0(arg1);
    obj = (Obj *)obj->v2();
    register s32 result = 0;
    register s32 valid = 0;
    if (obj->state != 3 && obj->flags == 0)
        valid = 1;
    if (valid != 0) {
        s32 greater = *(f32 *)((u8 *)arg0 + 0x8D4) > *(f32 *)((u8 *)arg0 + 0x8DC);
        if (greater == 0)
            result = 1;
    }
    return result;
}
#pragma cplusplus reset
s32 fn_8014AD64(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x108); }

f32 fn_8014AD6C(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 8);
}

extern s32 fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_8056164C;
extern f32 lbl_80561650;
extern void fn_8001DFF0(void);
extern u32 fn_80149658(s32, void *, void *, s32);
extern unsigned long lbl_80559E94;
void fn_8014AD74(void *arg0) {
    f32 step;
    s32 state = fn_80176A1C() - 2;
    if (((u32)__cntlzw((u32)state) >> 5) != 0) {
        step = fn_80176A2C();
    } else {
        step = lbl_8056164C;
    }
    *(f32 *)((u8 *)arg0 + 8) += lbl_80561650 * step;
}

s32 fn_8014ADD0(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_8014ADD8(void *arg0) {
    void *next = ((void **)arg0)[2];
    ((void **)arg0)[1] = next;
    if (next != 0) {
        ((void **)arg0)[2] = *(void **)((u8 *)next + 0x11C);
        ((s32 *)arg0)[3] = *(s32 *)((u8 *)next + 0x120);
    } else {
        ((s32 *)arg0)[3] = 0;
        ((void **)arg0)[2] = 0;
    }
    return ((void **)arg0)[1] != 0;
}

void fn_8014AE1C(void *arg0, void *arg1) {
    volatile s32 *head = (volatile s32 *)arg0;
    volatile s32 *node = (volatile s32 *)arg1;
    void *next;
    s32 first;
    node[0x11C / 4] = 0;
    node[0x120 / 4] = head[1];
    next = (void *)head[1];
    if (next != 0) {
        *(void **)((u8 *)next + 0x11C) = arg1;
    }
    first = head[0];
    head[1] = (s32)arg1;
    if (first == 0) {
        head[0] = (s32)arg1;
    }
}

extern f32 lbl_8055E3C8;
void fn_8014AE54(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C8;
}

void fn_8014AE60(void *arg0) {
    struct Node8014AE60 { u8 pad[0x11C]; struct Node8014AE60 *prev; struct Node8014AE60 *next; };
    struct Head8014AE60 { struct Node8014AE60 *first; struct Node8014AE60 *last; };
    struct Head8014AE60 *head;
    struct Node8014AE60 *obj;
    struct Node8014AE60 *next;
    struct Node8014AE60 *prev;
    head = *(struct Head8014AE60 **)arg0;
    obj = *((struct Node8014AE60 **)arg0 + 1);
    next = obj->next;
    if (next != 0) next->prev = obj->prev;
    else head->first = obj->prev;
    prev = obj->prev;
    if (prev != 0) prev->next = obj->next;
    else head->last = obj->next;
    obj->next = 0;
    obj->prev = 0;
}

s32 fn_8014AEB8(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_8014AEC0(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x10C); }

f32 fn_8014AEC8(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x2690); }

void fn_8014AED0(void *arg0, f32 farg0) {
    ((f32 *)arg0)[0x41] = farg0;
}

f32 fn_8014AED8(void *arg0) {
    return ((f32 *)arg0)[0x41];
}

u8 fn_8014AEE0(void *arg0) {
    return ((u8 *)arg0)[5];
}

u8 fn_8014AEE8(void *arg0) {
    return ((u8 *)arg0)[4];
}

void fn_8014AEF0(void *arg0) {
    f32 step;
    if (*((u8 *)arg0 + 4) != 0) {
        s32 state = fn_80176A1C() - 2;
        if (((u32)__cntlzw((u32)state) >> 5) != 0) {
            step = fn_80176A2C();
        } else {
            step = lbl_8056164C;
        }
        *(f32 *)((u8 *)arg0 + 0xC) += lbl_80561650 * step;
    }
}

s32 fn_8014AF58(void *arg0) {
    return ((s32 *)arg0)[1];
}

void fn_8014AF60(void *arg0, void *arg1, s32 arg2) {
    void *next;

    ((void **)arg0)[0] = arg1;
    if (arg2 == 0) {
        next = ((void **)arg1)[0];
        ((void **)arg0)[1] = next;
        if (next != 0) {
            *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)next + 0x11C);
            *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)next + 0x120);
            return;
        }
        *(s32 *)((u8 *)arg0 + 0xC) = 0;
        *(s32 *)((u8 *)arg0 + 8) = 0;
        return;
    }
    next = ((void **)arg1)[1];
    ((void **)arg0)[1] = next;
    if (next != 0) {
        *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)next + 0x11C);
        *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)next + 0x120);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
}

extern u8 lbl_8042FC70[];
extern s32 fn_80161C38(void);
extern s32 fn_80160A74(void);
s32 fn_8014AFD4(void *arg0, void *arg1, s32 arg2) {
    volatile u8 scratch[0x370];
    register u8 *text = lbl_8042FC70;
    register u8 *strings = lbl_8032D358;
    void *manager;
    void *object;
    void *first;
    void *second;
    f32 frame;
    s32 frameIndex;
    s32 value;
    s32 status;
    s32 flag;
    s32 sum;
    manager = fn_8017960C(*(s32 *)arg0);
    object = *(void **)((u8 *)manager + 0x270);
    first = ((void *(*)(void *))(*(void ***)object)[4])(object);
    object = *(void **)((u8 *)manager + 0x270);
    second = ((void *(*)(void *))(*(void ***)object)[6])(object);
    frame = *(f32 *)((u8 *)arg0 + 0x18);
    flag = (*(u32 *)first >> 2) & 1;
    if (frame >= lbl_80561648) frame = lbl_8056163C + frame;
    else frame = frame - lbl_8056163C;
    frameIndex = (s32)frame;
    value = fn_801609C4(frameIndex);
    status = fn_80161C38();
    if (status == 0 && lbl_8055E4D0 > 1 &&
        frameIndex > *(s32 *)((u8 *)arg0 + 0x24) &&
        frameIndex <= fn_80160A74() && frameIndex >= 0) {
        value += ((s32 (*)(void *, const char *))(*(void ***)arg1)[3])(arg1, (const char *)strings + 0x150);
    }
    sum = flag + value + status + (first != second) + arg2;
    sum += (manager != NULL);
    sum += text[0] + strings[0] + (s32)*(u8 *)arg0 + (s32)*(u8 *)arg1;
    scratch[0] = (u8)sum;
    return scratch[0];
}

void fn_8014C6F0(void *arg0, void *arg1) {
    s32 g;
    s32 d, c, b, a;
    f32 f, e;
    volatile s32 *src = (volatile s32 *)arg1;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)arg1 + 0x10);
    a = src[0]; b = src[1]; c = src[2]; d = src[3];
    e = fsrc[0]; f = fsrc[1]; g = src[6];
    *(s32 *)arg0 = a;
    *((s32 *)arg0 + 1) = b;
    *((s32 *)arg0 + 2) = c;
    *((s32 *)arg0 + 3) = d;
    *(f32 *)((u8 *)arg0 + 0x10) = e;
    *(f32 *)((u8 *)arg0 + 0x14) = f;
    *((s32 *)arg0 + 6) = g;
}

#pragma cplusplus on
extern "C" void fn_8014C72C(void *arg0) {
    struct Obj {
        virtual void v0();
        virtual void v1();
    };
    ((Obj *)arg0)->v1();
    fn_801476C4();
}
#pragma cplusplus reset
f32 fn_8014C75C(f32 *arg0, const f32 *arg1) {
    f32 v0 = arg1[0];
    f32 v1 = arg1[1];
    arg0[0] = v0;
    arg0[1] = v1;
    return v0;
}

#pragma scheduling invalid_target
s64 fn_8014C770(const f32 *arg0, const f32 *arg1, f32 t) {
    f32 dy = arg1[1] - arg0[1];
    f32 dx = arg1[0] - arg0[0];
    f32 y = arg0[1] + t * dy;
    f32 x = arg0[0] + t * dx;
    union { struct { f32 x, y; } f; s64 bits; } out;
    out.f.y = y;
    out.f.x = x;
    return out.bits;
}
#pragma scheduling on
void fn_8014C7B4(void *arg0, void *arg1) {
    s32 d, c, b, a;
    f32 j, i, h, g, f, e;
    volatile s32 *src = (volatile s32 *)arg1;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)arg1 + 0x10);
    a = src[0]; b = src[1]; c = src[2]; d = src[3];
    e = fsrc[0]; f = fsrc[1]; g = fsrc[2]; h = fsrc[3]; i = fsrc[4]; j = fsrc[5];
    *(s32 *)arg0 = a;
    *((s32 *)arg0 + 1) = b;
    *((s32 *)arg0 + 2) = c;
    *((s32 *)arg0 + 3) = d;
    *(f32 *)((u8 *)arg0 + 0x10) = e;
    *(f32 *)((u8 *)arg0 + 0x14) = f;
    *(f32 *)((u8 *)arg0 + 0x18) = g;
    *(f32 *)((u8 *)arg0 + 0x1c) = h;
    *(f32 *)((u8 *)arg0 + 0x20) = i;
    *(f32 *)((u8 *)arg0 + 0x24) = j;
}

unsigned int fn_8014C808(unsigned int arg0) { return arg0 >> 24; }

unsigned char fn_8014C810(unsigned char arg0) { return arg0; }

unsigned char fn_8014C818(unsigned int arg0) { return (unsigned char)(arg0 >> 8); }

unsigned char fn_8014C820(unsigned int arg0) { return (unsigned char)(arg0 >> 16); }

s32 fn_8014C828(s32 arg0) { return arg0 + 0x64; }

s32 fn_8014C830(s32 arg0) { return arg0 + 0x14; }

f32 fn_8014C838(void *arg0) { return *(f32 *)((u8 *)arg0 + 0x10); }

s32 fn_8014C840(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_8014C848(void *arg0) {
    void *next = ((void **)arg0)[2];
    ((void **)arg0)[1] = next;
    if (next != 0) {
        ((void **)arg0)[2] = *(void **)((u8 *)next + 0x11C);
        ((s32 *)arg0)[3] = *(s32 *)((u8 *)next + 0x120);
    } else {
        ((s32 *)arg0)[3] = 0;
        ((void **)arg0)[2] = 0;
    }
    return ((void **)arg0)[1] != 0;
}

extern f32 lbl_80558DC4[];
extern float fabsf(float);
s32 fn_8014C88C(f32 arg0, f32 arg1) {
    f32 diff = arg0 - arg1;
    f64 abs = __fabs((f64)diff);
    return (f32)abs <= lbl_80558DC4[0];
}

f32 fn_8014C8B4(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 t = (farg4 - farg0) / (farg1 - farg0);
    t = (lbl_8056164C < t) ? lbl_8056164C : t;
    t = (t > lbl_80561648) ? t : lbl_80561648;
    return farg2 + t * (farg3 - farg2);
}

float fn_8014C8F8(float farg0, float farg1, float farg2) {
    float value = farg2;
    value = value < farg0 ? value : farg0;
    value = value > farg1 ? value : farg1;
    return value;
}

void fn_8014C920(void *arg0, void *arg1) {
    volatile int *src = (volatile int *)arg1;
    int h;
    int g;
    int f;
    int d;
    int c;
    int b;
    int a;
    float e;
    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    e = *(volatile float *)((char *)arg1 + 0x10);
    f = src[5];
    g = src[6];
    h = src[7];
    ((int *)arg0)[0] = a;
    ((int *)arg0)[1] = b;
    ((int *)arg0)[2] = c;
    ((int *)arg0)[3] = d;
    ((float *)arg0)[4] = e;
    ((int *)arg0)[5] = f;
    ((int *)arg0)[6] = g;
    ((int *)arg0)[7] = h;
}

int fn_8014C964(int *arg0, int arg1) {
    return *arg0 == arg1;
}

void fn_8014C978(void *arg0, void *arg1) {
    s32 d, c, b, a;
    f32 j, i, h, g, f, e;
    volatile s32 *src = (volatile s32 *)arg1;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)arg1 + 0x10);
    a = src[0]; b = src[1]; c = src[2]; d = src[3];
    e = fsrc[0]; f = fsrc[1]; g = fsrc[2]; h = fsrc[3]; i = fsrc[4]; j = fsrc[5];
    *(s32 *)arg0 = a;
    *((s32 *)arg0 + 1) = b;
    *((s32 *)arg0 + 2) = c;
    *((s32 *)arg0 + 3) = d;
    *(f32 *)((u8 *)arg0 + 0x10) = e;
    *(f32 *)((u8 *)arg0 + 0x14) = f;
    *(f32 *)((u8 *)arg0 + 0x18) = g;
    *(f32 *)((u8 *)arg0 + 0x1c) = h;
    *(f32 *)((u8 *)arg0 + 0x20) = i;
    *(f32 *)((u8 *)arg0 + 0x24) = j;
}

int fn_8014C9CC(void *arg0) {
    return ((int *)arg0)[1];
}

void fn_8014C9D4(void *arg0, void *arg1, s32 arg2) {
    void *next;

    ((void **)arg0)[0] = arg1;
    if (arg2 == 0) {
        next = ((void **)arg1)[0];
        ((void **)arg0)[1] = next;
        if (next != 0) {
            *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)next + 0x11C);
            *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)next + 0x120);
            return;
        }
        *(s32 *)((u8 *)arg0 + 0xC) = 0;
        *(s32 *)((u8 *)arg0 + 8) = 0;
        return;
    }
    next = ((void **)arg1)[1];
    ((void **)arg0)[1] = next;
    if (next != 0) {
        *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)next + 0x11C);
        *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)next + 0x120);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
}

void fn_8014D6EC(void *arg0) {
    if (((u8 *)arg0)[0xA0] == 0) {
        return;
    }
    fn_8001DFF0();
}

#pragma cplusplus on
extern "C" void fn_8014D700(void *arg0, s32 arg1) {
    s32 index;
    s32 var_r6;
    void *temp_r5;
    void *temp;
    struct TObjD1Call {
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
        virtual void f16(void *);
    };
    temp_r5 = *(void **)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)temp_r5 + 8) = 0;
    temp = *(void **)((u8 *)arg0 + 0x10);
    ((TObjD1Call *)temp)->f16(*(void **)((u8 *)arg0 + 0xC));

    temp_r5 = *(void **)((u8 *)arg0 + 0x68);
    index = *(s32 *)arg0;
    void *table = (u8 *)temp_r5 + 0x8F4;
    if (*(u8 *)table != 0) {
        var_r6 = *(s32 *)((u8 *)table + index * 0x1C + 8);
    } else {
        var_r6 = 0;
    }
    fn_80149658(arg1, (void *)((u8 *)arg0 + 0x6C), *(void **)((u8 *)arg0 + 0xC), var_r6);
}

extern "C" BOOL fn_8014D794(void *arg0, void *arg1) {
    fn_801E7E18();
    if (*(u8 *)((u8 *)arg0 + 0xA0) == 0) {
        if (fn_800167F4() == 2) {
            void *target = *(void **)((u8 *)arg1 + 8);
            f32 values[4];
            values[0] = lbl_80561688;
            values[1] = lbl_805616C0;
            values[2] = lbl_805616C4;
            values[3] = lbl_80561648;
            if (target != 0) {
                ((void (*)(void *, void *))fn_802AE220)(target, values);
            }
        } else {
            void *target = *(void **)((u8 *)arg1 + 8);
            if (target != 0) {
                ((void (*)(void *, void *))fn_802AE220)(target, 0);
            }
        }
    }
    return *(f32 *)((u8 *)arg0 + 0x64) >= lbl_80561648;
}

#pragma cplusplus off
extern char *lbl_80559F30;
extern char *lbl_80559F38;
void fn_8014D840(void *arg0, void *arg1) {
    u8 *manager;
    s32 i;
    s32 best;
    u8 *entry;
    s32 count;
    manager = *(u8 **)((u8 *)arg0 + 0x68);
    best = -1;
    entry = manager + 0x9E4;
    count = *(s32 *)(manager + 0xFE4);
    i = 0;
    while (count > 0) {
        if (best < 0) {
            best = i;
        } else {
            u8 *current = manager + best * 0xC0;
            s32 value = *(s32 *)(current + 0xA74);
            s32 threshold = *(s32 *)(entry + 0x90);
            if (value < threshold) {
                best = i;
            } else if (value == threshold) {
                s32 tieValue = *(s32 *)(current + 0xA54);
                s32 tieThreshold = *(s32 *)(entry + 0x70);
                if (tieValue > tieThreshold) {
                    best = i;
                }
            }
        }
        entry += 0xC0;
        i++;
        count--;
    }
    if (*(s32 *)arg0 == best) {
        ((void (*)(void *, const char *))(*(void ***)arg1)[3])(arg1, (const char *)&lbl_80559F30);
        fn_801476C4();
    } else {
        ((void (*)(void *, const char *))(*(void ***)arg1)[3])(arg1, (const char *)&lbl_80559F38);
        fn_801476C4();
    }
}
#pragma cplusplus on

#pragma cplusplus on
extern "C" void fn_8014D918(void *arg0, s32 arg1, s32 arg2) {
    struct Acc {
        virtual void d0(); virtual void d1(); virtual void d2();
        virtual void *get(void *);
    };
    struct Rec { s32 w0, w1, w2, w3; f32 f4, f5; s32 w6; };
    Rec *b, *a;
    void *obj;
    char storage[0x64];
    f32 t, time, x, y, w, h, rate;
    Rec v;
    char *strs = (char *)lbl_8032D358;
    obj = *(void **)((u8 *)arg0 + 0x68);
    t = lbl_80561648;
    {
        f32 d = *(f32 *)((u8 *)obj + 0x8DC) - *(f32 *)((u8 *)obj + 0x8D4);
        t = (t > d) ? t : d;
    }
    if (t < lbl_8056164C) return;
    ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(storage, 0x64, strs + 0x384, arg2);
    a = (Rec *)((Acc *)arg1)->get(storage);
    ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(storage, 0x64, strs + 0x398, arg2);
    b = (Rec *)((Acc *)arg1)->get(storage);
    rate = ((f32 (*)(void *, void *))fn_80149F00)((u8 *)arg0 + 0x6C, arg0);
    if (a != 0 && b != 0) {
        time = (f32)fn_8002EFB4(rate, lbl_805616A0);
        if (time < lbl_8056163C) {
            x = (time - lbl_80561648) / lbl_805616C8;
            v = *a;
            x = (lbl_8056164C < x) ? lbl_8056164C : x;
            x = (lbl_80561648 > x) ? lbl_80561648 : x;
            v.w6 = ((s32 (*)(s32, s32, f32))fn_80147C50)(v.w6 & 0xFFFFFF, v.w6, lbl_80561648 + x * lbl_8056164C);
        } else {
            f32 *pa = (f32 *)a, *pb = (f32 *)b, *pv = (f32 *)&v;
            x = lbl_80561670 * time - lbl_8056164C;
            v = *a;
            y = lbl_8056164C - x; w = x * x; h = lbl_8056164C - y * y;
            pv[1] = pa[1] + h * (pb[1] - pa[1]); pv[2] = pa[2] + w * (pb[2] - pa[2]);
            pv[4] = pa[4] + w * (pb[4] - pa[4]); pv[5] = pa[5] + w * (pb[5] - pa[5]);
            v.w6 = ((s32 (*)(s32, s32, f32))fn_80147C50)(a->w6, b->w6, x);
        }
        fn_80147940((void *)arg1, &v, strs + 0x27C, 0);
    }
}
#pragma cplusplus off
void fn_8014DB94(void *arg0) {
    f32 f0;
    f32 f2;
    void *obj;
    *(u8 *)((u8 *)arg0 + 0xA0) = 1;
    fn_80149CEC((u8 *)arg0 + 0x6C, arg0);
    obj = *(void **)((u8 *)arg0 + 0x68);
    f2 = lbl_80561648;
    f0 = *(f32 *)((u8 *)obj + 0x8DC) - *(f32 *)((u8 *)obj + 0x8D4);
    if (f2 <= f0) f2 = f0;
    fn_801CB648(*(void **)arg0, 0, *(f32 *)((u8 *)obj + 0x8DC) - f2);
}

extern int fn_801CB648();
#pragma cplusplus on
extern "C" void fn_8014DC08(void *arg0) {
    struct Node { char pad0[4]; u8 flag; u8 timed; char pad1[0x102]; int duration; char pad2[0x10]; Node *next; Node *prev; };
    struct Lists { char pad[0x1244]; Node *first; Node *last; Node *active; Node *activeLast; Node *pending; };
    struct Callback { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void call(); };
    extern void fn_801CB5DC(void *, int, int);
    extern char lbl_8032D704[];
    extern float lbl_8055E3C8;
    register Lists *list;
    register Node *pending;
    Node *node, *next, *p;
    float total, diff;
    int a, b;
    void *obj;
    ((Callback *)*(void **)((char *)arg0 + 0x10))->call();
    list = *(Lists **)((char *)arg0 + 8);
    total = lbl_80561648;
    pending = list->pending;
    if (pending) {
        int duration = pending->duration;
        pending->next = 0;
        pending->prev = list->last;
        total += (float)duration;
        if (list->last) list->last->next = pending;
        list->last = pending;
        if (!list->first) list->first = pending;
        list->pending = 0;
    }
    node = list->active;
    next = node ? node->next : 0;
    while (node) {
        if (!node->flag) {
            if (node->timed) total += (float)node->duration;
            p = node->prev;
            if (p) p->next = node->next; else list->active = node->next;
            p = node->next;
            if (p) p->prev = node->prev; else list->activeLast = node->prev;
            node->prev = 0;
            node->next = 0;
            node->prev = list->last;
            if (list->last) list->last->next = node;
            list->last = node;
            if (!list->first) list->first = node;
        }
        node = next;
        next = next ? next->next : 0;
    }
    *(float *)((char *)arg0 + 0x14) += total;
    *(float *)((char *)arg0 + 0x64) = lbl_8055E3C8;
    fn_80149CEC((char *)arg0 + 0x6C, arg0);
    if (!*(u8 *)((char *)arg0 + 0xA0)) {
        a = *(int *)((char *)arg0 + 0x90);
        b = *(int *)((char *)arg0 + 0x9C);
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_8032D704, *(void **)arg0, a);
        fn_801CB5DC(*(void **)arg0, a, b);
        obj = *(void **)((char *)arg0 + 0x68);
        total = lbl_80561648;
        diff = *(float *)((char *)obj + 0x8DC) - *(float *)((char *)obj + 0x8D4);
        total = total > diff ? total : diff;
        ((void (*)(void *, int, float))fn_801CB648)(*(void **)arg0, 1, *(float *)((char *)obj + 0x8DC) - total);
    }
}
#pragma cplusplus reset

void fn_8014DE4C(void) {

  }
  // test

extern s32 fn_801284F8(s32, void *);
extern s32 fn_80145E70(void *);
extern void *fn_8014E1D0(void *, s32);
extern void *fn_8014E3CC(void *, s32);
extern void *fn_8014E4BC(void *);
extern void fn_8014E154(void);
extern void **__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(void *);
extern void fn_8002F53C(void *, ...);
extern f32 fn_80204CFC(void *);
extern void *fn_80207848(void *, s32);
extern void *fn_8000AC38(void);
extern void fn_801679F0(void);
extern void fn_801777CC(void *);
extern void fn_801D0590(void *);
extern void fn_801D0800(void *);
extern void fn_80167834(void);
extern void fn_8016A0B0(void);
extern s32 fn_802C9A58(void);
extern s32 fn_80232578(void *);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_8014DE50(void) {
    class LfoObj {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual f64 eval(void *, f32);
    };
    class Manager {
    public:
        virtual void d0();
        virtual s32 query(char *);
        virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5();
        virtual s32 get(char *, s32);
    };
    u8 *strings = lbl_8032D358;
    s32 raw = fn_801284F8(0xFE8, strings + 0x3D4);
    u8 *obj = (u8 *)raw;
    if (obj != 0) {
        u32 *vtables = (u32 *)lbl_8032D970;
        *(u32 **)(obj + 0x0) = vtables;
        u32 *table1 = vtables + 0x40;
        void *initFn = fn_8014E4BC;
        *(u32 **)(obj + 0x4) = table1;
        u32 *table2 = vtables + 0x47;
        void *cleanupFn = fn_8014E3CC;
        *(u32 **)(obj + 0x8) = table2;
        *(u32 **)(obj + 0xC) = vtables + 0x4C;
        *(u8 * *)(obj + 0x14) = obj + 0x20;
        *(s32 *)(obj + 0x1C) = 0x80;
        *(s32 *)(obj + 0x18) = 0;
        *(u8 * *)(obj + 0x220) = obj + 0x22C;
        *(s32 *)(obj + 0x228) = 0x40;
        *(s32 *)(obj + 0x224) = 0;
        *(u8 * *)(obj + 0x32C) = obj + 0x338;
        s32 vectorSize = 0x20;
        *(s32 *)(obj + 0x334) = vectorSize;
        *(s32 *)(obj + 0x330) = 0;
        *(u8 * *)(obj + 0x3B8) = obj + 0x3C4;
        *(s32 *)(obj + 0x3C0) = vectorSize;
        *(s32 *)(obj + 0x3BC) = 0;
        ((void (*)(void *, void *, void *, s32, s32, s32, void *))fn_8002F53C)(obj + 0x454, initFn, cleanupFn, 0x240, 2, vectorSize, obj + 0x338);
        LfoObj *lfo = *(LfoObj **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        f64 value = lfo->eval((void *)(strings + 0x344), lbl_805616CC);
        *(f32 *)(obj + 0x8DC) = value;
        *(f32 *)(obj + 0x8E0) = (f32)value;
        *(f32 *)(obj + 0x8D8) = fn_80204CFC(strings + 0x3E0);
        *(void * *)(obj + 0x8E8) = fn_80207848(strings + 0x3F0, 1);
        *(void * *)(obj + 0x8EC) = fn_80207848(strings + 0x400, 1);
        *(f32 *)(obj + 0x8D4) = lbl_80561648;
        obj[0x8E4] = 0;
        u8 *res = *(u8 * *)(obj + 0x8E8);
        if (res != 0) { res[0x4A] = 1; res[0x4C] = 0; }
        res = *(u8 * *)(obj + 0x8EC);
        if (res != 0) { res[0x4A] = 1; res[0x4C] = 0; }
        obj[0x8F0] = 0;
        *(f32 *)(obj + 0x8DC) = *(f32 *)(obj + 0x8E0);
        obj[0x8F4] = 0;
        Manager *manager = (Manager *)(*(u8 **)((u8 *)fn_8000AC38() + 0x20));
        if (manager->query((char *)strings + 0x40C) != 0) {
            fn_801679F0();
            *(s32 *)(obj + 0x9D8) = 0;
            *(s32 *)(obj + 0x9DC) = manager->get((char *)strings + 0x418, 3);
            obj[0x8F4] = 1;
        }
        ((void (*)(void *, void *, void *, s32, s32))fn_8002F53C)(obj + 0x9E4, fn_8014E1D0, fn_8014E154, 0xC0, 8);
        lbl_8055E268 = obj;
        lbl_8055E238 = fn_80145E70(strings + 0x424);
        lbl_8055E23C = fn_80145E70(strings + 0x430);
        lbl_8055E240 = fn_80145E70(fn_802C9A58() == 0 ? strings + 0x458 : strings + 0x440);
        lbl_8055E244 = fn_80145E70(strings + 0x46C);
        lbl_8055E248 = fn_80145E70(strings + 0x478);
        obj[0x9E0] = 0;
        *(s32 *)(obj + 0xFE4) = 0;
        if (obj != 0) fn_801777CC(obj + 4);
        if (obj != 0) fn_801D0590(obj + 8);
        if (obj != 0) fn_801D0800(obj + 0xC);
        *(void * *)(obj + 0x444) = fn_80207848(strings + 0x488, 1);
        *(void * *)(obj + 0x448) = fn_80207848(strings + 0x498, 1);
        *(void * *)(obj + 0x44C) = fn_80207848(strings + 0x4A8, 1);
        obj[0x450] = 0;
        lbl_8055E250 = fn_80232578(strings + 0x4B4);
        fn_80167834();
        fn_8016A0B0();
    }
    return obj;
}
#pragma cplusplus off
#pragma scheduling on

#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_8014E1D0(void *arg0, s32 arg1) {
    struct Obj {
        char pad[0x74];
        void **items;
        s32 count;
        s32 unk7c;
        s32 valueA;
        s32 valueB;
    };
    register Obj *obj = (Obj *)arg0;
    register u8 *strings = lbl_8032D358;
    void *table;
    s32 ok;
    Iter_8014E1D0 *iter;
    char name[0x64];
    s32 i;
    void **items;
    obj->items = 0;
    obj->count = 0;
    obj->unk7c = -1;
    obj->valueA = 1;
    obj->valueB = 1;
    table = fn_80131808(strings + 0x4c8, -1, 0);
    if (table != 0) {
        ok = 0;
        iter = (Iter_8014E1D0 *)((Iter_8014E1D0 *)table)->open((char *)(strings + 0x4d8));
        if (iter != 0) {
            ok = 1;
            obj->count = 1;
            for (;;) {
                ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(name, 0x64, (char *)(strings + 0x4e4), obj->count);
                if (iter->has(name) == 0)
                    break;
                obj->count++;
            }
            obj->items = (void **)fn_8012850C((obj->count + 1) * 4, strings + 0x4f0);
            for (i = 0; i < obj->count - 1; i++) {
                ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(name, 0x64, (char *)(strings + 0x4e4), i + 1);
                obj->items[i] = iter->next(name);
            }
            obj->items[obj->count - 1] = 0;
            obj->valueA = iter->get((char *)(strings + 0x500), obj->valueA);
            obj->valueB = iter->get((char *)(strings + 0x50c), obj->valueB);
        }
        if (ok)
            ((void (*)(char *, ...))fn_802E30C8)((char *)(strings + 0x518));
        fn_80131818(table);
    }
    if (obj->items == 0) {
        ((void (*)(char *, ...))fn_802E30C8)((char *)(strings + 0x54c));
        items = (void **)fn_8012850C(4, strings + 0x4f0);
        obj->items = items;
        *items = 0;
        obj->count = 1;
    }
    return arg0;
}
#pragma use_lmw_stmw reset
#pragma cplusplus off

#pragma cplusplus on
extern "C" void* fn_8014E3CC(void* arg0, s32 arg1) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    VObj* p;
    if (arg0 != NULL) {
        p = *(VObj**)((char*)arg0 + 8);
        if (p != NULL) {
            fn_802ADE60((void**)p, 1);
            *(VObj**)((char*)arg0 + 8) = NULL;
        }
        p = *(VObj**)((char*)arg0 + 0x10);
        if (p != NULL) {
            if (p != NULL) p->d0(1);
            *(VObj**)((char*)arg0 + 0x10) = NULL;
        }
        p = *(VObj**)((char*)arg0 + 0x14);
        if (p != NULL) {
            if (p != NULL) p->d0(1);
            *(VObj**)((char*)arg0 + 0x14) = NULL;
        }
        p = *(VObj**)((char*)arg0 + 0x18);
        if (p != NULL) {
            if (p != NULL) p->d0(1);
            *(VObj**)((char*)arg0 + 0x18) = NULL;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus off
extern void *memset(void *, s32, s32);
void *fn_8014E4BC(void *arg0) {
    u8 *base = (u8 *)arg0;
    u32 p;
    u32 end;
    s32 zero = 0;
    *(u32 *)(base + 8) = zero; *(u32 *)(base + 0x10) = zero;
    *(u32 *)(base + 0x14) = zero; *(u32 *)(base + 0x18) = zero;
    memset(base + 0x2C, 0x7A, 3); base[0x2F] = zero;
    memset(base + 0x40, 0x7A, 3); base[0x43] = zero;
    memset(base + 0x45, 0x7A, 3); base[0x48] = zero;
    memset(base + 0x59, 0x7A, 3); base[0x5C] = zero;
    memset(base + 0x6D, 0x7A, 3); base[0x70] = zero;
    memset(base + 0x81, 0x7A, 3); base[0x84] = zero;
    memset(base + 0x8B, 0x7A, 3); base[0x8E] = zero;
    p = (u32)base + 0x95; end = (u32)base + 0x149;
    do { memset((void *)p, 0x7A, 3); *(u8 *)(p + 3) = zero; p += 0x14; } while (p < end);
    p = end; end = (u32)base + 0x1FD;
    do { memset((void *)p, 0x7A, 3); *(u8 *)(p + 3) = zero; p += 0x14; } while (p < end);
    memset((void *)end, 0x7A, 3); base[0x200] = zero;
    memset(base + 0x225, 0x7A, 3); base[0x228] = zero;
    return arg0;
}

#pragma cplusplus off
extern s32 fn_801DF074(s32, s32);
#pragma paired_single off
void fn_8014E61C(s32 arg0, s32 arg1, f32 arg2) {
    extern void *lbl_8055E268;
    extern s32 fn_801DF074(s32, s32);
    u8 *entry;
    f32 value;
    void *other;
    void **obj;
    void (*callback)(void *, void *, s32, f32);
    if (lbl_8055E268 != 0) {
        entry = (u8 *)lbl_8055E268 + arg0 * 0xC0 + 0x9E4;
        if (entry != 0) {
            value = arg2;
            switch (arg1) {
            case 8:
                *(f32 *)(entry + 0x4C) = lbl_80561688;
                break;
            case 1:
                *(f32 *)(entry + 0x44) = lbl_80561688;
                if (*(s32 *)((u8 *)fn_8017960C(arg0) + 0x1F0) == 0x50)
                    fn_801DF074(1, 1);
                break;
            case 6:
                *(f32 *)(entry + 0x48) = lbl_80561688;
                break;
            case 0: case 2: case 3: case 4: case 5: case 7: case 9:
                break;
            }
            other = fn_8017960C(arg0);
            obj = *(void ***)(entry + 0x10);
            callback = *(void (**)(void *, void *, s32, f32))((u8 *)*obj + 0x2C);
            callback(obj, other, arg1, value);
        }
    }
}
#pragma paired_single reset
void fn_8014E704(void) {

}

extern void fn_80128670(s32);
extern void *lbl_8055E268;
extern s32 lbl_80559F40;
#pragma cplusplus on
extern "C" s32 fn_8014E708(s32 arg0) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual s32 v12();
    };
    u8 *base = (u8 *)lbl_8055E268;
    if (base != 0) {
        Obj *obj = *(Obj **)(base + arg0 * 0xC0 + 0x9F4);
        return obj->v12();
    }
    return 0;
}
#pragma cplusplus reset
s32 fn_8014E738(void) { return 0; }

#pragma processor 750
void fn_8014E740(void *arg0, f32 arg1) {
    void *manager;
    void *entry;
    s32 count;
    void **buffer;
    f32 first;
    f32 second;
    f32 third;
    u32 zero;
    manager = lbl_8055E268;
    if (manager != 0) {
        entry = (void *)fn_801284F8(0x14, &lbl_80559F40);
        if (entry != 0) {
            first = *(f32 *)((u8 *)arg0 + 0);
            zero = 0;
            second = *(f32 *)((u8 *)arg0 + 4);
            *(f32 *)((u8 *)entry + 0) = first;
            third = *(f32 *)((u8 *)arg0 + 8);
            *(f32 *)((u8 *)entry + 4) = second;
            *(f32 *)((u8 *)entry + 8) = third;
            *(f32 *)((u8 *)entry + 0xC) = arg1;
            *((u8 *)entry + 0x10) = zero;
        }
        count = *(s32 *)((u8 *)manager + 0x224);
        buffer = *(void ***)((u8 *)manager + 0x220);
        *(s32 *)((u8 *)manager + 0x224) = count + 1;
        buffer[count] = entry;
    }
}
#pragma processor reset
void fn_8014E7D8(void) {

}

#pragma processor 750
extern void fn_8012E81C(void *);
extern char *fn_80012820(s32);
extern void *fn_80205268(void *, s32, s32);
extern s32 fn_8012C33C(void *);
extern void *fn_80131810(const char *);
extern double ceil(double);
extern f32 lbl_80559EB0;
extern f32 lbl_805616D0;
extern s32 lbl_80559F48;
extern s32 lbl_80559F4C;
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" f32 fn_8014E7DC(s32 arg0, s32 arg1) {
    class MainInterface {
    public:
        virtual void d0();
        virtual s32 check(void *);
        virtual void d2();
        virtual void d3();
        virtual void *lookup(void *, void *);
        virtual void d5();
        virtual void d6();
        virtual f32 finish(void *);
        virtual f32 evaluate(void *, f32);
    };
    class ResourceInterface {
    public:
        virtual void *next(char *);
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual f32 value(char *);
    };

    char sp8[0x104];
    void *file;
    char *text;
    void *name;
    void *resource;
    void *resultObj;
    s32 temp;
    f32 value;
    f32 count;
    f32 scaled;
    f32 rate;

    fn_8012E81C(lbl_8032D358 + 0x5A4);
    file = fn_8001285C((void *)arg0);
    text = fn_80012820(*(s32 *)((u8 *)file + 4));
    name = fn_80205268(lbl_8032D358 + 0x5B8, arg1, arg0);
    register u8 *strings = lbl_8032D358;

    if (((MainInterface *)*(void **)((u8 *)file + 0x20))->check(name) == 0) {
        value = ((MainInterface *)*(void **)((u8 *)file + 0x20))->evaluate(
            (char *)(strings + 0x344), lbl_805616CC);
        name = ((MainInterface *)*(void **)((u8 *)file + 0x20))->lookup(
            (char *)(strings + 0x5D0), &lbl_80559F48);

        fn_8012E81C(strings + 0x5A4);
        ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(
            sp8, 0x104, (char *)(strings + 0x5DC), name, text + 8);
        if (fn_8012C33C(sp8) == 0) {
            ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(
                sp8, 0x104, (char *)(strings + 0x5E8), name, text + 8);
        }

        resource = fn_80131810(sp8);
        if (resource != 0) {
            resultObj = ((ResourceInterface *)resource)->next((char *)&lbl_80559F4C);
            value = ((ResourceInterface *)resultObj)->value(
                (char *)(strings + 0x5F4));
            fn_80131818(resource);

            temp = *(s32 *)((u8 *)file + 0xC);
            count = (f32)temp;
            scaled = value * count;
            rate = lbl_80559EB0 * scaled;
            rate = rate / lbl_805616D0;
            value = lbl_805616D0 * (f32)ceil((double)rate);
        } else {
            ((void (*)(char *, ...))fn_802E30C8)(
                (char *)(strings + 0x600), sp8);
        }
        return value;
    }

    return ((MainInterface *)*(void **)((u8 *)file + 0x20))->finish(name);
}

extern s32 lbl_8055E258, lbl_80559ED0, lbl_80559ED4, lbl_80559ED8, lbl_80559EDC, lbl_80559ECC, lbl_8055E254;
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_802328D4(s32);
extern "C" void fn_802CAC54(s32);
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_80167838(void), fn_8016A68C(void), fn_80167EEC(void);
extern "C" void fn_801777D0(void *), fn_801D05B4(void *), fn_801D0824(void *);
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_8014E9C4(char *p, s32 arg1) {
    int i;
    char *entry;
    int off;
    char *item;
    Cleanup8014E9C4 *obj;
    char *sub;
    if (p) {
        *(void **)(p+0) = lbl_8032D970;
        *(void **)(p+4) = lbl_8032D970+0x100;
        *(void **)(p+8) = lbl_8032D970+0x11c;
        *(void **)(p+12) = lbl_8032D970+0x130;
        fn_802328D4(lbl_8055E250);
        lbl_8055E250 = 0;
        obj = (Cleanup8014E9C4 *)lbl_8055E238;
        if (obj) obj->destroy(1);
        lbl_8055E238 = 0;
        obj = (Cleanup8014E9C4 *)lbl_8055E23C;
        if (obj) obj->destroy(1);
        lbl_8055E23C = 0;
        obj = (Cleanup8014E9C4 *)lbl_8055E240;
        if (obj) obj->destroy(1);
        lbl_8055E240 = 0;
        obj = (Cleanup8014E9C4 *)lbl_8055E244;
        if (obj) obj->destroy(1);
        lbl_8055E244 = 0;
        obj = (Cleanup8014E9C4 *)lbl_8055E248;
        if (obj) obj->destroy(1);
        lbl_8055E248 = 0;
        entry = p;
        for (i=0; i<*(s32 *)(p+0xfe4); entry+=0xc0,i++) {
            obj = *(Cleanup8014E9C4 **)(entry+0x9f4);
            if (obj) obj->destroy(1);
            obj = *(Cleanup8014E9C4 **)(entry+0xa90);
            if (obj) { if (obj) obj->destroy(1); }
            obj = *(Cleanup8014E9C4 **)(entry+0xa94);
            if (obj) { if (obj) obj->destroy(1); }
            fn_802CAC54(*(s32 *)(entry+0xaa0));
            fn_802CAC54(*(s32 *)(entry+0xa9c));
            fn_802CAC54(*(s32 *)(entry+0xa98));
            obj = *(Cleanup8014E9C4 **)(entry+0x9f0);
            if (obj) obj->destroy(1);
            obj = *(Cleanup8014E9C4 **)(entry+0x9ec);
            if (obj) obj->destroy(1);
            *(void **)(entry+0x9ec) = 0;
        }
        for (i=0,off=0; i<*(s32 *)(p+0x18); off+=4,i++) {
            item = *(char **)(*(char **)(p+0x14)+off);
            if (item) {
                if (--lbl_8055E258 == 0) {
                    fn_802CAC54(lbl_80559EDC);
                    lbl_80559EDC = -1;
                    fn_802C6CF8(lbl_80559ED4);
                    fn_802C6CF8(lbl_80559ED8);
                    fn_802C6CF8(lbl_80559ECC);
                    fn_802C6CF8(lbl_80559ED0);
                    fn_802C6CF8(lbl_8055E254);
                    lbl_80559ED0 = -1;
                    lbl_80559ECC = -1;
                    lbl_8055E254 = -1;
                }
                if (item+0x20) fn_802CAC54(*(s32 *)(item+0x20));
                fn_80128668(item);
            }
        }
        for (i=0,off=0; i<*(s32 *)(p+0x224); off+=4,i++)
            fn_80128668(*(void **)(*(char **)(p+0x220)+off));
        for (i=0,off=0; i<*(s32 *)(p+0x330); off+=4,i++)
            fn_80128668(*(void **)(*(char **)(p+0x32c)+off));
        for (i=0,off=0; i<*(s32 *)(p+0x3bc); off+=4,i++)
            fn_80128668(*(void **)(*(char **)(p+0x3b8)+off));
        obj = *(Cleanup8014E9C4 **)(p+0x44c);
        if (obj) { if (obj) obj->destroy(1); }
        obj = *(Cleanup8014E9C4 **)(p+0x444);
        if (obj) { if (obj) obj->destroy(1); }
        obj = *(Cleanup8014E9C4 **)(p+0x448);
        if (obj) { if (obj) obj->destroy(1); }
        sub = p; if (p) sub = p+12; fn_801D0824(sub);
        sub = p; if (p) sub = p+8; fn_801D05B4(sub);
        sub = p; if (p) sub = p+4; fn_801777D0(sub);
        lbl_8055E268 = 0;
        fn_80167838();
        fn_8016A68C();
        fn_8002F634(p+0x9e4,(void *)fn_8014E154,0xc0,8);
        if (p+0x8f4 && *(u8 *)(p+0x8f4)) {
            obj = *(Cleanup8014E9C4 **)(p+0x9d8);
            if (obj) { if (obj) obj->destroy(1); }
            fn_80167EEC();
            *(u8 *)(p+0x8f4)=0;
        }
        if (p+0x8d4) {
            obj = *(Cleanup8014E9C4 **)(p+0x8e8);
            if (obj) { if (obj) obj->destroy(1); }
            obj = *(Cleanup8014E9C4 **)(p+0x8ec);
            if (obj) { if (obj) obj->destroy(1); }
        }
        fn_8002F634(p+0x454,(void *)fn_8014E3CC,0x240,2);
        if (p+0x3b8) if (p+0x3b8) { *(s32 *)(p+0x3b8)=0; *(s32 *)(p+0x3bc)=0; *(s32 *)(p+0x3c0)=0; }
        if (p+0x32c) if (p+0x32c) { *(s32 *)(p+0x32c)=0; *(s32 *)(p+0x330)=0; *(s32 *)(p+0x334)=0; }
        if (p+0x220) if (p+0x220) { *(s32 *)(p+0x220)=0; *(s32 *)(p+0x224)=0; *(s32 *)(p+0x228)=0; }
        if (p+0x14) if (p+0x14) { *(s32 *)(p+0x14)=0; *(s32 *)(p+0x18)=0; *(s32 *)(p+0x1c)=0; }
        if (arg1>0) fn_80128668(p);
    }
    return p;
}
#pragma pop
#pragma cplusplus on

#pragma cplusplus off
#pragma processor reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void *fn_8014EF00(void *arg0, s32 arg1) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    if (arg0 != 0) {
        VObj *p0 = *(VObj **)((char *)arg0 + 0x125C);
        *(void **)arg0 = lbl_8032E190;
        if (p0 != 0) {
            if (p0 != 0) p0->d0(1);
        }
        VObj *p1 = *(VObj **)((char *)arg0 + 0x1258);
        if (p1 != 0) {
            if (p1 != 0) p1->d0(1);
        }
        fn_8002F634((char *)arg0 + 4, (void *)fn_8014EFC0, 0x124, 0x10);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset

s32 fn_8014EFC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern s32 fn_8014F088(s32, s32);
void *fn_8014F000(void *arg0, int arg1) {
    struct Local {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
    };
    struct Local *obj = (struct Local *)arg0;
    if (arg0 != 0) {
        if (&obj->field_4 != 0) {
            fn_8002F634((char *)obj + 0x10, (void *)fn_8014F088, 0xF8, 0x10);
            if (&obj->field_4 != 0) {
                obj->field_4 = 0;
                obj->field_8 = 0;
                obj->field_C = 0;
            }
        }
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(obj);
        }
    }
    return obj;
}

s32 fn_8014F088(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

      extern void fn_80128668();
extern void fn_8016783C(void *arg0);
extern void fn_801688FC(s32 arg0);
extern void fn_80168020(void);
extern void fn_8016A0D4(void);
extern void *memset(void *arg0, s32 arg1, s32 arg2);
extern s32 fn_801284F8(s32 arg0, void *arg1);
extern s32 fn_802ADDD8(s32 arg0);
extern void fn_8014F194(void *arg0);
extern s32 fn_80145E70(void *arg0);
extern char lbl_8032DB34[];
extern char lbl_8032DB40[];
#pragma push
#pragma opt_pointer_aliasing on
s32 *fn_801500F8(void *arg0, s32 *arg1) {
    s32 value = *arg1;
    s32 index = ((s32 *)arg0)[1];
    s32 *data = *(s32 **)arg0;
    ((s32 *)arg0)[1] = index + 1;
    data[index] = value;
    return &data[index];
}
#pragma pop
s32 fn_80150AD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80150B18(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80150B58(void *arg0, s32 arg1) {
    ((s32 *)arg0)[8] = arg1;
}

s32 fn_8014F088(s32 arg0, s32 arg1);
s32 fn_8014F088(s32, s32);
#pragma push
#pragma scheduling off
#pragma peephole off
void fn_80150B60(void *arg0) {
    u8 *p;
    fn_8016783C(arg0);
    if (((u8 *)arg0)[0x8F4] != 0) {
        memset((char *)arg0 + 0x8F8, 0, 0xE0);
        fn_801688FC(1);
        fn_80168020();
    }
    fn_8016A0D4();
    p = *(u8 **)((u8 *)arg0 + 0x44C);
    if (p != 0) {
        p[0x4A] = 1;
        p[0x4C] = 0;
    }
    ((u8 *)arg0)[0x450] = 0;
}
#pragma pop
s32 fn_80151604(void) { return 0; }

s32 fn_8015160C(void) {
    if (fn_80161C38() != 0) {
        return 0x5608;
    }
    return (fn_80179650() > 1 ? 0x160B : 0x564B) & 0xFFFFFFBF;
}

#pragma cplusplus on
extern "C" void fn_80151654(void *a0, void *a1, int selector) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
    };
    int index;
    void *obj;
    if (selector != 0x3EB) return;
    index = *(int *)((char *)a1 + 0x1EC);
    obj = (char *)a0 + index * 0xC0;
    obj = (char *)obj + 0x9E4;
    if (obj == 0) return;
    ((Obj *)*(void **)((char *)obj + 0x10))->v7();
}
#pragma cplusplus reset
void fn_80151688(void) {

}

#pragma cplusplus on
extern "C" void fn_8015168C(s32 arg0, void *arg1) {
    class VNode {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
    };
    struct Node {
        u8 pad0[4];
        u8 flag;
        u8 pad1[0x117];
        Node *prev;
        Node *next;
    };
    struct Owner {
        u8 pad[0x1244];
        Node *first;
        Node *tail;
        Node *last;
        Node *end;
    };
    u8 *entry;
    Owner *owner;
    Node *cur;
    Node *next;
    Node *link;
    u8 *obj;
    f32 factor;
    f32 delta;
    f32 zero;
    s32 zeroInt;
    s32 count;
    s32 value;
    entry = (u8 *)(arg0 + *(s32 *)((u8 *)arg1 + 0x1EC) * 0xC0 + 0x9E4);
    if (entry != 0) {
        delta = lbl_80561648;
        zeroInt = 0;
        factor = lbl_8056163C;
        *(volatile f32 *)(entry + 0x3C) = delta;
        *(f32 *)(entry + 0x1C) = factor * *(f32 *)(entry + 0x1C);
        *(s32 *)(entry + 0xA4) = zeroInt;
        owner = *(Owner **)(entry + 8);
        cur = owner->last;
        next = cur != 0 ? cur->prev : 0;
        while (cur != 0) {
            if (cur->flag != 0) {
                link = cur->next;
                if (link != 0)
                    link->prev = cur->prev;
                else
                    owner->last = cur->prev;
                link = cur->prev;
                if (link != 0)
                    link->next = cur->next;
                else
                    owner->end = cur->next;
                cur->next = 0;
                cur->prev = 0;
                cur->next = owner->tail;
                link = owner->tail;
                if (link != 0)
                    link->prev = cur;
                owner->tail = cur;
                if (owner->first == 0)
                    owner->first = cur;
            }
            cur = next;
            next = cur != 0 ? cur->prev : 0;
        }
        *(f32 *)(entry + 0x14) += delta;
        obj = *(u8 **)(entry + 0x10);
        ((VNode *)obj)->m2();
        if (*(s32 *)(entry + 0x34) > 1)
            *(f32 *)(entry + 0x40) = lbl_80561688;
        count = *(s32 *)(entry + 0x34) - 1;
        value = count > 1 ? count : 1;
        *(s32 *)(entry + 0x34) = value;
        zero = lbl_80561648;
        *(f32 *)(entry + 0x50) = zero;
        *(f32 *)(entry + 0x4C) = zero;
        *(f32 *)(entry + 0x48) = zero;
        *(f32 *)(entry + 0x44) = zero;
    }
}
#pragma cplusplus off
extern f32 PSVECMag(void *);
#pragma cplusplus on
extern "C" void fn_8015180C(void *ctx, void *a, void *b, void *unused, void *vec) {
    f32 mag = PSVECMag(vec);
    s32 first = 1;
    s32 second = 1;
    if (*(s32 *)((u8 *)a + 0x1F0) == 0x50 && *(s32 *)((u8 *)b + 0x1F0) == 0x50) {
        f32 valueB = *(f32 *)((u8 *)b + 0x25D4);
        f32 valueA = *(f32 *)((u8 *)a + 0x25D4);
        first = valueA > valueB;
        second = !first;
    }
    if (first) {
        s32 address = (s32)ctx;
        address += *(s32 *)((u8 *)a + 0x1EC) * 0xC0;
        void *slot = (void *)(address + 0x9E4);
        if (slot) ((Dummy_8015180C *)*(void **)((u8 *)slot + 0x10))->call(*(s32 *)((u8 *)b + 0x1EC), mag);
    }
    if (second) {
        s32 address = (s32)ctx;
        address += *(s32 *)((u8 *)b + 0x1EC) * 0xC0;
        void *slot = (void *)(address + 0x9E4);
        if (slot) ((Dummy_8015180C *)*(void **)((u8 *)slot + 0x10))->call(*(s32 *)((u8 *)a + 0x1EC), mag);
    }
}
#pragma cplusplus off

void fn_80151914(void) {

}

void fn_80151918(void *arg0, void *arg1) {
    u32 index = *(u32*)((u8*)arg1 + 0x1EC);
    u32 base = (u32)arg0 + index * 0xC0;
    u32 address = base + 0x9E4;
    volatile u32 *indexField = (volatile u32*)((u8*)arg1 + 0x1EC);
    u32 clearIndex;
    if (address != 0) {
        fn_8014DC08((void*)address);
    }
    clearIndex = *indexField;
    if (*(u8*)((u8*)arg0 + 0x8F4) != 0) {
        *(u8*)((u8*)arg0 + clearIndex * 0x1C + 0x8F8) = 0;
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_80151984(void *arg0, s32 arg1, s32 arg2) {
    register s32 count;
    register u8 *object;
    register s32 i;

    if (arg2 == 0x58 && ((Dummy_80151984 *)arg0)->check() != 0) {
        count = fn_801E85A4();
        object = (u8 *)arg0;
        for (i = 0; i < count; i++) {
            if (*((u8 *)arg0 + fn_801E86F8(i) * 0xC0 + 0xA84) != 0 || count > 1) {
                *(s32 *)(object + 0x454) = 4;
            } else if (*(s32 *)(object + 0x454) == 2) {
                *(object + 0x460) = 1;
            }
            object += 0x240;
        }
    }
    return 0;
}

#pragma cplusplus off
void fn_80151A40(void *arg0) {
    extern s32 fn_801E85B4(void);
    extern s32 fn_801E41D8(s32 *, s32 *, s32, s32, f32);
    extern s32 lbl_8055E230;
    extern f32 lbl_805616FC;
    s32 self = fn_801E85B4();
    s32 index = fn_801E866C(self);
    s32 entry_base = (s32)arg0 + index * 0xC0 + 0x9E4;
    s32 *check = (s32 *)entry_base;
    s32 offset;
    s32 global_value;
    s32 i;
    f32 y_offset;
    if (check != 0 && check[1] != 0) {
        global_value = lbl_8055E230;
        i = 0;
    }
    y_offset = lbl_805616FC;
    offset = 0;
    while (i < *(s32 *)((s32)arg0 + 0x224)) {
        s32 item = *(s32 *)(*(s32 *)((s32)arg0 + 0x220) + offset);
        if (*((u8 *)item + 0x10) != 0) {
            s32 second[3];
            s32 first[3];
            s32 x = *(s32 *)(item + 0);
            s32 y = *(s32 *)(item + 4);
            f32 y_minus;
            f32 y_plus;
            first[1] = y;
            first[0] = x;
            y_minus = ((f32 *)first)[1] - y_offset;
            first[2] = *(s32 *)(item + 8);
            x = *(s32 *)(item + 0);
            y = *(s32 *)(item + 4);
            second[1] = y;
            second[0] = x;
            y_plus = ((f32 *)second)[1] + y_offset;
            second[2] = *(s32 *)(item + 8);
            ((f32 *)first)[1] = y_minus;
            ((f32 *)second)[1] = y_plus;
            fn_801E41D8(first, second, global_value, x, *(f32 *)(item + 0xC));
        }
        offset += 4;
        i += 1;
    }
}

#pragma cplusplus off
#pragma pop
extern s32 fn_80141F7C(f32);
extern void fn_80149650(void);
extern void fn_80151C98(void *, s32);
extern s32 fn_801537CC(s32, s32, f32);
extern void *fn_801538E4(void *);
extern void fn_80167844(void);
extern void fn_8016A438(void);
extern s32 fn_801E85B4(void);
#pragma push
#pragma use_lmw_stmw off
extern f32 fn_801495D4(s32);
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80151B48(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual s32 check(s32);
    };
    void *self = arg0;
    void *obj;
    s32 flag;
    void *entry;
    s32 index;
    s32 i;
    void *p;
    s32 addr;
    f32 f;

    index = fn_801E866C(fn_801E85B4());
    if (((struct Dummy *)self)->check(index) == 0) goto done;
    addr = (s32)self + index * 0xC0 + 0x9E4;
    if (addr == 0) goto done;
    if (*(s32 *)(addr + 4) == 0) {
        flag = 0;
    } else if (*(s32 *)(addr + 4) == 1) {
        flag = 1;
    } else {
        flag = (f32)__fabs((f64)(*(f32 *)(addr + 0x1C) - lbl_8056164C)) <= lbl_80558DC4[0];
    }
    i = 0;
    index = 0;
    while (i < *(s32 *)((s32)self + 0x18)) {
        entry = *(void **)(*(s32 *)((s32)self + 0x14) + index);
        f = *(f32 *)((u8 *)entry + 0x34);
        if (fn_80141F7C(f) != 0 && flag != 0 && ((u8 *)entry)[0xCC] != 0) {
            f = ((f32 (*)(void))fn_80149650)();
            obj = fn_801538E4(entry);
            p = fn_801538E4(entry);
            fn_801537CC(*(s32 *)((char *)p + 4), *(s32 *)obj, f);
            fn_80151C98(entry, (s32)obj);
        }
        index += 4;
        i += 1;
    }
done:
    fn_80167844();
    fn_8016A438();
}

#pragma cplusplus off
extern f32 *GXInitLightAttnA_80144B44(void *, f32, f32, f32);
extern s32 fn_802C9950(s32);
extern s32 fn_802C9994(s32);
extern void fn_801533E8(void *, f32 *);
extern void fn_80151E60(void *, s32, s32);
extern double cos(double);
extern double sin(double);
extern s32 lbl_80559ECC;
extern f32 lbl_8056165C;
extern f32 lbl_80561638;
extern void fn_801537C8(s32 *);
void fn_80151C98(void *arg0, s32 arg1) {
    u8 scratch[0x68];
    void *base = arg0;
    s32 mode = *(s32 *)((u8 *)base + 0x38);
    if (mode == 3) {
        *(s32 *)scratch = arg1;
        fn_801537C8((s32 *)scratch);
        fn_801533E8(GXInitLightAttnA_80144B44(scratch + 0x10,
            *(f32 *)base, *(f32 *)((u8 *)base + 4), *(f32 *)((u8 *)base + 8)),
            *(f32 **)((u8 *)base + 0xB8));
        return;
    }
    if (mode == 4) {
        s32 state, context;
        f32 y, z, x, angle, rotation, c, s;
        f32 *matrix;
        context = fn_802C9950(arg1);
        state = fn_802C9994(0);
        y = lbl_8056165C;
        y += *(f32 *)((u8 *)base + 4);
        z = *(f32 *)((u8 *)base + 8);
        x = *(f32 *)base;
        *(f32 *)(scratch + 0x30) = z;
        *(f32 *)(scratch + 0x28) = x;
        *(f32 *)(scratch + 0x2C) = y;
        *(f32 *)(scratch + 0x1C) = x;
        *(f32 *)(scratch + 0x20) = y;
        *(f32 *)(scratch + 0x24) = z;
        angle = (f32)fn_8002EFB4(lbl_8056163C * fn_801E7E18(), lbl_805616A0);
        rotation = lbl_80561638 * angle;
        matrix = (f32 *)(scratch + 0x38);
        matrix[9] = *(f32 *)(scratch + 0x1C);
        matrix[10] = *(f32 *)(scratch + 0x20);
        matrix[11] = *(f32 *)(scratch + 0x24);
        c = (f32)cos(rotation);
        s = (f32)sin(rotation);
        matrix[0] = c;
        matrix[1] = lbl_80561648;
        matrix[2] = -s;
        matrix[3] = lbl_80561648;
        matrix[4] = lbl_8056164C;
        matrix[5] = lbl_80561648;
        matrix[6] = s;
        matrix[7] = lbl_80561648;
        matrix[8] = c;
        fn_802C744C(lbl_80559ECC, matrix);
        fn_802C9994(state);
        fn_802C9950(context);
        return;
    }
    {
        s32 state, context;
        context = fn_802C9950(arg1);
        state = fn_802C9994(0);
        fn_80151E60(GXInitLightAttnA_80144B44(scratch + 4, *(f32 *)base,
            lbl_8056165C + *(f32 *)((u8 *)base + 4), *(f32 *)((u8 *)base + 8)), 0, 0);
        fn_802C9994(state);
        fn_802C9950(context);
    }
}
#pragma cplusplus reset
extern double cos(double), sin(double), fn_8002EFB4(double,double);
extern f32 fn_80144514(f32,f32,f32,f32,f32,f32);
extern s32 fn_802E2C20(void);
extern void fn_802C744C(s32,f32*), fn_802C74D8(s32,f32*,s32);
extern s32 lbl_80559EDC, lbl_8055E254;
extern f32 lbl_80561638,lbl_8056163C,lbl_8056164C,lbl_805616FC,lbl_80561700;
extern f64 lbl_805616A0,lbl_80561708;
#pragma push
#pragma processor 750
void fn_80151E60(void *arg0, s32 arg1, s32 arg2) {
    f32 scale[9];
    f32 a[12];
    f32 b[12];
    f32 rotation[9];
    f32 position[3];
    f32 p0, p1, p2;
    f32 *r30;
    s32 *r29;
    f32 val_f21;
    f32 val_f31;
    f32 val_f30;
    f32 val_f29;
    f32 c, s;

    p2 = ((f32 *)arg0)[2];
    p1 = ((f32 *)arg0)[1];
    p0 = ((f32 *)arg0)[0];
    position[1] = p1;
    position[0] = p0;
    position[2] = p2;

    if (arg2 != 0) {
        val_f21 = lbl_80561700 * (f32)fn_802E2C20();
    } else {
        val_f21 = fn_801E7E18();
    }

    val_f31 = lbl_80561638 * (f32)fn_8002EFB4(lbl_80561688 * val_f21, lbl_805616A0);
    val_f30 = lbl_80561638 * (f32)fn_8002EFB4(lbl_8056163C * val_f21, lbl_805616A0);
    val_f29 = lbl_805616FC;

    r29 = &lbl_8055E254;

    scale[0] = val_f29;
    scale[1] = lbl_80561648;
    scale[2] = lbl_80561648;
    scale[3] = lbl_80561648;
    scale[4] = val_f29;
    scale[5] = lbl_80561648;
    scale[6] = lbl_80561648;
    scale[7] = lbl_80561648;
    scale[8] = val_f29;

    a[9] = position[0];
    a[10] = position[1];
    a[11] = position[2];
    b[9] = position[0];
    b[10] = position[1];
    b[11] = position[2];

    c = (f32)cos(val_f31);
    s = (f32)sin(val_f31);

    r30 = b;

    a[0] = c;
    a[1] = lbl_80561648;
    a[3] = lbl_80561648;
    a[2] = -s;
    a[4] = lbl_8056164C;
    a[5] = lbl_80561648;
    a[6] = s;
    a[7] = lbl_80561648;
    a[8] = c;

    c = (f32)cos(val_f30);
    s = (f32)sin(val_f30);

    b[0] = c;
    b[1] = lbl_80561648;
    b[3] = lbl_80561648;
    b[2] = -s;
    b[4] = lbl_8056164C;
    b[5] = lbl_80561648;
    b[6] = s;
    b[7] = lbl_80561648;
    b[8] = c;

    if (arg1 != 0) {
        fn_802C74D8(*r29, r30, lbl_80559EDC);
    } else {
        fn_802C744C(*(s32 *)r29, r30);
    }

    MatrixMul80151E60(a, scale, a);

    if (arg1 != 0) {
        fn_802C74D8(*(s32 *)r29, a, lbl_80559EDC);
    } else {
        fn_802C744C(*(s32 *)r29, a);
    }

    c = (f32)cos(val_f31);
    s = (f32)sin(val_f31);

    a[0] = lbl_8056164C;
    a[1] = lbl_80561648;
    a[2] = lbl_80561648;
    a[3] = lbl_80561648;
    a[4] = c;
    a[5] = s;
    a[6] = lbl_80561648;
    a[7] = -s;
    a[8] = c;

    c = (f32)cos(val_f30);
    s = (f32)sin(val_f30);

    val_f29 = val_f29 * lbl_805616FC;

    b[1] = lbl_80561648;
    b[0] = lbl_8056164C;
    b[2] = lbl_80561648;
    b[3] = lbl_80561648;
    b[4] = c;
    b[5] = s;
    b[6] = lbl_80561648;
    b[7] = -s;
    b[8] = c;

    scale[0] = val_f29;
    scale[1] = lbl_80561648;
    scale[2] = lbl_80561648;
    scale[3] = lbl_80561648;
    scale[4] = val_f29;
    scale[5] = lbl_80561648;
    scale[6] = lbl_80561648;
    scale[7] = lbl_80561648;
    scale[8] = val_f29;

    MatrixMul80151E60(b, scale, b);

    val_f29 = val_f29 * lbl_805616FC;

    scale[1] = lbl_80561648;
    scale[0] = val_f29;
    scale[2] = lbl_80561648;
    scale[3] = lbl_80561648;
    scale[4] = val_f29;
    scale[5] = lbl_80561648;
    scale[6] = lbl_80561648;
    scale[7] = lbl_80561648;
    scale[8] = val_f29;

    MatrixMul80151E60(a, scale, a);

    if (arg1 != 0) {
        fn_802C74D8(*(s32 *)r29, r30, lbl_80559EDC);
    } else {
        fn_802C744C(*(s32 *)r29, r30);
    }

    if (arg1 != 0) {
        fn_802C74D8(*(s32 *)r29, a, lbl_80559EDC);
    } else {
        fn_802C744C(*(s32 *)r29, a);
    }

    c = (f32)cos(lbl_80561708);
    s = (f32)sin(lbl_80561708);

    rotation[0] = c;
    rotation[1] = lbl_80561648;
    rotation[2] = -s;
    rotation[3] = lbl_80561648;
    rotation[4] = lbl_8056164C;
    rotation[5] = lbl_80561648;
    rotation[6] = s;
    rotation[7] = lbl_80561648;
    rotation[8] = c;

    MatrixMul80151E60(a, rotation, a);
    MatrixMul80151E60(b, rotation, b);

    val_f29 = val_f29 * lbl_805616FC;

    scale[1] = lbl_80561648;
    scale[0] = val_f29;
    scale[2] = lbl_80561648;
    scale[3] = lbl_80561648;
    scale[4] = val_f29;
    scale[5] = lbl_80561648;
    scale[6] = lbl_80561648;
    scale[7] = lbl_80561648;
    scale[8] = val_f29;

    MatrixMul80151E60(b, scale, b);

    val_f29 = val_f29 * lbl_805616FC;

    scale[1] = lbl_80561648;
    scale[0] = val_f29;
    scale[2] = lbl_80561648;
    scale[3] = lbl_80561648;
    scale[4] = val_f29;
    scale[5] = lbl_80561648;
    scale[6] = lbl_80561648;
    scale[7] = lbl_80561648;
    scale[8] = val_f29;

    MatrixMul80151E60(a, scale, a);

    if (arg1 != 0) {
        fn_802C74D8(*(s32 *)r29, r30, lbl_80559EDC);
    } else {
        fn_802C744C(*(s32 *)r29, r30);
    }

    if (arg1 != 0) {
        fn_802C74D8(*(s32 *)r29, a, lbl_80559EDC);
        return;
    }
    fn_802C744C(*(s32 *)r29, a);
}
#pragma pop
#pragma cplusplus on
extern "C" void fn_802C86DC(void);
extern "C" void fn_802C77F0(void *, f32 *);
extern "C" void fn_802C744C(s32, f32 *);
extern "C" void *fn_801E87A8(void);
#pragma cplusplus off
extern s32 lbl_80559ED4, lbl_80559ED8;
extern f32 lbl_8056163C, lbl_80561648, lbl_8056164C, lbl_805616B8;
void fn_801533E8(void *arg0, f32 *arg1) {
    Matrix801533E8 values, mat;
    f32 bounds[6], center[3], out[3];
    f32 x, y, z;
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
    u32 w6;
    u32 w7;
    u32 w8;
    u32 w9;
    u32 w10;
    u32 w11;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;
    f32 t6;
    f32 t7;
    f32 t8;
    f32 t9;
    f32 t10;
    f32 t11;
    f32 t12;
    f32 t13;
    f32 t14;
    f32 t15;
    f32 t16;
    f32 t17;
    fn_802C86DC();
    ((u32 *)values.m)[0] = ((u32 *)arg1)[0];
    w2 = ((u32 *)arg1)[2];
    w3 = ((u32 *)arg1)[3];
    w8 = ((u32 *)arg1)[8];
    w11 = ((u32 *)arg1)[11];
    w4 = ((u32 *)arg1)[4];
    w5 = ((u32 *)arg1)[5];
    w6 = ((u32 *)arg1)[6];
    w7 = ((u32 *)arg1)[7];
    w9 = ((u32 *)arg1)[9];
    w10 = ((u32 *)arg1)[10];
    ((u32 *)values.m)[1] = ((u32 *)arg1)[1];
    ((u32 *)values.m)[2] = w2;
    ((u32 *)values.m)[3] = w3;
    ((u32 *)values.m)[4] = w4;
    ((u32 *)values.m)[5] = w5;
    ((u32 *)values.m)[6] = w6;
    ((u32 *)values.m)[7] = w7;
    ((u32 *)values.m)[8] = w8;
    ((u32 *)values.m)[9] = w9;
    ((u32 *)values.m)[10] = w10;
    ((u32 *)values.m)[11] = w11;
    ((f64 *)mat.m)[0] = ((f64 *)values.m)[0];
    ((f64 *)mat.m)[1] = ((f64 *)values.m)[1];
    ((f64 *)mat.m)[2] = ((f64 *)values.m)[2];
    ((f64 *)mat.m)[3] = ((f64 *)values.m)[3];
    ((u32 *)mat.m)[8] = w8;
    *(f64 *)&mat.m[9] = *(f64 *)&values.m[9];
    ((u32 *)mat.m)[11] = w11;
    fn_802C77F0((void *)lbl_80559ED8, bounds);
    center[2] = bounds[4] + (bounds[5] - bounds[4]) * lbl_8056163C;
    center[1] = bounds[2] + (bounds[3] - bounds[2]) * lbl_8056163C;
    center[0] = bounds[0] + (bounds[1] - bounds[0]) * lbl_8056163C;
    out[2] = lbl_805616B8 * center[2];
    out[1] = lbl_805616B8 * center[1];
    out[0] = lbl_805616B8 * center[0];
    Transform801533E8(out, out, mat.m);
    mat.m[9] = out[0] + mat.m[9] + center[0];
    mat.m[10] = ((mat.m[10] + out[1]) + center[1]) + lbl_80561648;
    mat.m[11] = out[2] + mat.m[11] + center[2];
    values.m[10] += lbl_80561648;
    t0 = mat.m[0] * (f32)lbl_8056164C;
    t1 = mat.m[1] * (f32)lbl_8056164C;
    t2 = mat.m[2] * (f32)lbl_8056164C;
    t3 = mat.m[3] * (f32)lbl_8056164C;
    t4 = mat.m[4] * (f32)lbl_8056164C;
    t5 = mat.m[5] * (f32)lbl_8056164C;
    t6 = mat.m[6] * (f32)lbl_8056164C;
    t7 = mat.m[7] * (f32)lbl_8056164C;
    t8 = mat.m[8] * (f32)lbl_8056164C;
    t9 = values.m[0] * (f32)lbl_8056164C;
    t10 = values.m[1] * (f32)lbl_8056164C;
    t11 = values.m[2] * (f32)lbl_8056164C;
    t12 = values.m[3] * (f32)lbl_8056164C;
    t13 = values.m[4] * (f32)lbl_8056164C;
    t14 = values.m[5] * (f32)lbl_8056164C;
    t15 = values.m[6] * (f32)lbl_8056164C;
    t16 = values.m[7] * (f32)lbl_8056164C;
    t17 = values.m[8] * (f32)lbl_8056164C;
    mat.m[0] = t0;
    mat.m[1] = t1;
    mat.m[2] = t2;
    mat.m[3] = t3;
    mat.m[4] = t4;
    mat.m[5] = t5;
    mat.m[6] = t6;
    mat.m[7] = t7;
    mat.m[8] = t8;
    values.m[0] = t9;
    values.m[1] = t10;
    values.m[2] = t11;
    values.m[3] = t12;
    values.m[4] = t13;
    values.m[5] = t14;
    values.m[6] = t15;
    values.m[7] = t16;
    values.m[8] = t17;
    if ((*(u32 *)((u8 *)fn_801E87A8() + 0x10) & 2) != 0) {
        values.m[0] = -values.m[0]; values.m[1] = -values.m[1]; values.m[2] = -values.m[2];
        mat.m[0] = -mat.m[0]; mat.m[1] = -mat.m[1]; mat.m[2] = -mat.m[2];
    }
    fn_802C744C(lbl_80559ED8, mat.m);
    fn_802C744C(lbl_80559ED4, values.m);
}

#pragma pop
void fn_801537C8(s32 *arg0) {

}

#pragma push
#pragma scheduling invalid_target
s32 fn_801537CC(s32 arg0, s32 arg1, f32 t) {
    u8 *a = (u8 *)&arg0;
    u8 *b = (u8 *)&arg1;
    f32 b0 = (f32)b[0];
    f32 a0 = (f32)a[0];
    f32 b1 = (f32)b[1];
    f32 a1 = (f32)a[1];
    f32 b2 = (f32)b[2];
    f32 a2 = (f32)a[2];
    f32 b3 = (f32)b[3];
    f32 a3 = (f32)a[3];
    f32 delta0 = b0 - a0;
    f32 delta1 = b1 - a1;
    f32 delta2 = b2 - a2;
    f32 delta3 = b3 - a3;
    u8 c0 = (u8)(a0 + t * delta0);
    u8 c1 = (u8)(a1 + t * delta1);
    u8 c2 = (u8)(a2 + t * delta2);
    u8 c3 = (u8)(a3 + t * delta3);
    u8 out[4];
    out[0] = c0;
    out[1] = c1;
    out[2] = c2;
    out[3] = c3;
    return *(s32 *)out;
}
#pragma pop
void *fn_801538E4(void *arg0) {
    return (void *)((u8 *)arg0 + ((*(s32 *)((u8 *)arg0 + 0x38) + *(s32 *)((u8 *)arg0 + 0x14)) * 0x14) + 0x3C);
}

void fn_80153900(void *arg0, s32 arg1) {
    void *v;
    s32 p;
    if (*(u8 *)((u8 *)arg0 + 0x9E0)) {
        (*(void (**)(void))(*(u32 *)arg0 + 0x88))();
    } else {
        if (fn_801E85A4() == 2) v = (void *)lbl_8055E23C;
        else v = (void *)lbl_8055E238;
        (*(void (**)(void))(*(u32 *)v + 0x1C))();
    }
    p = (s32)arg0 + fn_801E866C(arg1) * 0xC0 + 0x9E4;
    if (p) {
        if (fn_801E85A4() == 2) v = (void *)lbl_8055E23C;
        else v = (void *)lbl_8055E238;
        fn_8014AFD4((void *)p, v, arg1);
        fn_801CB7BC(0);
    }
}

void fn_801539C0(s32 arg0, s32 arg1) {
    s32 offset = fn_801E866C(arg1) * 0xC0;
    s32 p = arg0 + offset;
    p += 0x9E4;
    if (p != 0) {
        s32 value;
        if (fn_801E85A4() != 2) goto use_other;
        value = lbl_8055E23C;
        goto call;
    use_other:
        value = lbl_8055E238;
    call:
        fn_8014CA48(p, value, arg1);
    }
}

extern s32 fn_80179650(void);
extern s32 fn_801E85A4(void);
extern s32 fn_801E86F8(s32);
extern s32 fn_801E866C(s32);
extern s32 fn_8014CA48(s32,s32,s32);
extern s32 fn_8014AFD4(void *, void *, s32);
extern s32 fn_801CB7BC(s32);
extern s32 lbl_8055E238;
extern s32 lbl_8055E23C;
s32 fn_80153A30(void) { return 0; }

s32 fn_80153A38(void *arg0) {
    s32 i;
    fn_80179650();
    for (i = 0; i < fn_801E85A4(); i++) {
        if (*(u8 *)((u8 *)arg0 + fn_801E86F8(i) * 0xC0 + 0xA84) == 0 &&
            *(s32 *)((u8 *)arg0 + i * 0x240 + 0x454) != 2) {
            return 0;
        }
    }
    return 1;
}

u32 fn_80153AC8(void) { return 1; }

#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_80153AD0(void *arg0, s32 arg1) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual s32 method();
    };
    extern void fn_8001DFCC(void);
    u8 *base = (u8 *)arg0;
    Dummy *obj = (Dummy *)arg0;
    s32 count = fn_80179650();
    u8 *entry = base + fn_801E86F8(arg1) * 0xC0;
    u8 *target = entry + 0x9E4;
    if (entry[0xA84] == 0) {
        u8 *entry2 = base + fn_801E866C(arg1) * 0xC0;
        u8 *target2 = entry2 + 0x9E4;
        if (target2 != 0 && arg1 >= 0 && (u32)arg1 < 2U) {
            fn_8014D794(target2, base + arg1 * 0x240 + 0x454);
        }
    } else {
        fn_8014D6EC(target);
    }
    if (obj->method() != 0 && count > 1) {
        s32 scanCount = *(s32 *)(base + 0xFE4);
        u8 *cursor = base + 0x9E4;
        s32 found = 0;
        s32 i;
        for (i = 0; i < scanCount; i++) {
            if (cursor[0xA0] == 0) found = 1;
            cursor += 0xC0;
        }
        if (found != 0) fn_8014D840(target, (void *)lbl_8055E248);
    }
    if (obj->method() != 0 && arg1 == 0) fn_8001DFCC();
    s32 i;
    s32 result;
    for (i = 0; i < count; i++) {
        if (*(s32 *)(base + 0x454) != 4) {
            result = 0;
            goto finish;
        }
        base += 0x240;
    }
    result = 1;
finish:
    return !result;
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_80153C44(void *arg0, s32 arg1) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual s32 method(s32);
    };
    Dummy *obj = (Dummy *)arg0;
    s32 count = fn_801E85A4();
    if (count > 1) {
        s32 flag = 0;
        s32 i;
        for (i = 0; i < count; i++) {
            flag = (flag | obj->method(fn_801E866C(i))) != 0;
        }
        if (flag != 0) {
            fn_8014D918((char *)arg0 + fn_801E86F8(arg1) * 0xC0 + 0x9E4, lbl_8055E240, arg1);
        }
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

u32 fn_80153CF8(void) { return 1; }

extern void *fn_801E7E3C(void);
extern void fn_8000FBE4(void);
extern void fn_8001DF08(s32, s32);
extern s32 fn_80160A90(void);
extern f32 fn_80147204(void *, void *);
extern void fn_801479A8(void *, s32, void *, ...);
extern void fn_80147CEC(void *, s32, s32, f32);
extern void *fn_80013DF0(s32, f32);
extern s32 fn_80013E1C(s32);
extern void fn_80013EAC(s32, s32, s32);
extern void fn_80130FCC(void *, s32, s32);
extern void *fn_80204CF0(void);
extern f32 lbl_805616E4, lbl_80561694, lbl_8056168C, lbl_80561710, lbl_8056164C, lbl_80561648, lbl_805616B8, lbl_805616BC, lbl_80561674, lbl_8056163C;
#pragma cplusplus off
extern void fn_8014784C(s32, void *, void *, s32);
#pragma cplusplus off
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" s32 fn_80153D00(s32 arg0, s32 arg1) {
    struct Dummy { virtual void d0(); virtual s32 method(void *); };
    register u8 *strings = lbl_8032D358;
    u8 buf80[0x20];
    u8 buf60[0x20];
    u8 buf40[0x20];
    u8 buf28[0x18];
    u8 buf8[0x20];
    f32 smooth;
    f32 v1;
    f32 x;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v9;
    f32 v2;
    f32 clamped;
    f32 u;
    f32 fv;
    f32 maxv;
    f32 diff;
    s32 r28;
    s32 r27;
    s32 r30;
    s32 r26;
    { void *p = fn_801E7E3C();
    smooth = lbl_805616E4;
    v1 = smooth - lbl_80561694;
    v2 = v1 - lbl_8056168C;
    v3 = v2 - lbl_80561710;
    v4 = v3 - lbl_80561694;
    v5 = v4 - lbl_8056168C;
    v6 = v5 - lbl_80561710;
    v7 = v6 - lbl_80561694;
    v9 = v7 - lbl_8056168C;
    x = *(f32 *)((u8 *)p + 0x10); }
    { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } r28 = ((Dummy *)obj)->method(strings + 0xC34); }
    { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } r27 = ((Dummy *)obj)->method(strings + 0xC44); }
    if (x < v9) fn_8000FBE4();
    if (fn_80161C38() == 0) {
    if (x < smooth) {
        clamped = lbl_8056164C;
        u = (x - v1) / (v2 - v1);
        clamped = (clamped < u) ? clamped : u;
        clamped = (clamped > lbl_80561648) ? clamped : lbl_80561648;
        fv = clamped * lbl_8056164C;
        v1 = lbl_80561648 + fv;
        { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } r30 = ((Dummy *)obj)->method(strings + 0xC54); }
        { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } r26 = ((Dummy *)obj)->method(strings + 0xC60); }
        fn_8001DF08(fn_801E866C(arg1), 0);
        if (r28 != 0 && r27 != 0 && r30 != 0 && r26 != 0) {
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_801E85A4();
            fn_801479A8((void *)r28, r27, fn_80131234(strings + 0xC74), smooth);
            fn_801308F4(buf80, 0x14, fn_80160A90());
            *(s32 *)(buf60 + 0) = *(s32 *)r30;
            *(s32 *)(buf60 + 4) = *(s32 *)(r30 + 4);
            *(s32 *)(buf60 + 8) = *(s32 *)(r30 + 8);
            *(s32 *)(buf60 + 0xC) = *(s32 *)(r30 + 0xC);
            *(f32 *)(buf60 + 0x10) = *(f32 *)(r30 + 0x10);
            *(s32 *)(buf60 + 0x14) = *(s32 *)(r30 + 0x14);
            *(s32 *)(buf60 + 0x18) = *(s32 *)(r30 + 0x18);
            *(s32 *)(buf60 + 0x1C) = *(s32 *)(r30 + 0x1C);
            fn_801E85A4();
            *(f32 *)(buf60 + 4) -= lbl_8056163C * fn_80147204(buf60, buf80);
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_801E85A4();
            fn_801479A8(buf60, r26, buf80, smooth);
        }
    }
    if (x < v3) {
        r30 = (s32)fn_80204CF0();
        switch (r30) {
        case 0: r30 = 1; break;
        case 1: r30 = 3; break;
        case 2: r30 = 5; break;
        default: fn_802E30C8(strings + 0x2F0, r30); r30 = 1; break;
        }
        { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } fn_8014784C(obj, strings + 0x334, strings + 0x228, r30); }
        { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } fn_8014784C(obj, strings + 0x350, strings + 0x360, 0); }
        clamped = lbl_8056164C;
        u = (x - v4) / (v5 - v4);
        clamped = (clamped < u) ? clamped : u;
        clamped = (clamped > lbl_80561648) ? clamped : lbl_80561648;
        fv = clamped * lbl_8056164C;
        v1 = lbl_80561648 + fv;
        { s32 obj; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } r26 = ((Dummy *)obj)->method(strings + 0xC90); }
        { s32 obj; s32 v344; switch (fn_801E85A4()) { case 2: obj = lbl_8055E23C; break; default: obj = lbl_8055E238; break; } v344 = ((Dummy *)obj)->method(strings + 0x344);
        if (r28 != 0 && r27 != 0 && r26 != 0 && v344 != 0) {
            diff = *(f32 *)(arg0 + 0x8DC) - *(f32 *)(arg0 + 0x8D4);
            maxv = lbl_80561648;
            maxv = (maxv <= diff) ? diff : maxv;
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_80147CEC(buf40, r26, v344, smooth);
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_801E85A4();
            fn_801479A8((void *)r28, r27, fn_80131234(strings + 0xC9C), smooth);
            ((void (*)(void *, f32))fn_80149588)(buf40, maxv);
        } }
    }
    if (x < v6) {
        clamped = lbl_8056164C;
        u = (x - v7) / (v9 - v7);
        clamped = (clamped < u) ? clamped : u;
        clamped = (clamped > lbl_80561648) ? clamped : lbl_80561648;
        fv = clamped * lbl_8056164C;
        v1 = lbl_80561648 + fv;
        r30 = (s32)fn_80013DF0(arg1, fv);
        r26 = fn_80013E1C(arg1);
        if (r28 != 0 && r27 != 0 && r30 != 0 && r26 != 0) {
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_801E85A4();
            fn_801479A8((void *)r28, r27, fn_80131234(strings + 0xCB8), smooth);
            r27 = *(s32 *)((u8 *)fn_801E7E3C() + 8);
            fn_80130FCC(buf28, 0x14, r27);
            *(s32 *)(buf8 + 0) = *(s32 *)r30;
            *(s32 *)(buf8 + 4) = *(s32 *)(r30 + 4);
            *(s32 *)(buf8 + 8) = *(s32 *)(r30 + 8);
            *(s32 *)(buf8 + 0xC) = *(s32 *)(r30 + 0xC);
            *(f32 *)(buf8 + 0x10) = *(f32 *)(r30 + 0x10);
            *(s32 *)(buf8 + 0x14) = *(s32 *)(r30 + 0x14);
            *(s32 *)(buf8 + 0x18) = *(s32 *)(r30 + 0x18);
            *(s32 *)(buf8 + 0x1C) = *(s32 *)(r30 + 0x1C);
            fn_801E85A4();
            *(f32 *)(buf8 + 4) -= lbl_8056163C * fn_80147204(buf8, buf28);
            smooth = (v1 < lbl_805616B8) ? lbl_805616B8 : (v1 > lbl_8056164C) ? lbl_8056164C : (v1 > lbl_80561648) ? (v1 * (lbl_805616BC * v1 * v1) + (lbl_80561674 * v1) * v1) : (v1 * (lbl_805616BC * v1 * v1) - (lbl_80561674 * v1) * v1);
            fn_801E85A4();
            fn_801479A8(buf8, r26, buf28, smooth);
            fn_80013EAC(arg1, 0, r27);
        }
    }
    }
    return 1;
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset
f32 fn_8015454C(void) { if(fn_800167F4()==2)return lbl_80561714; return lbl_80561718; }

void fn_80154580(s32 arg0, void *arg1) {
    s32 *p;
    s32 i;
    s32 *q = (s32 *)arg1;
    fn_801B8A7C();
    fn_802E30C8(lbl_8032E030);
    p = (s32 *)(arg0 + 0x9E4);
    for (i = 0; i < lbl_8055E4D0; i++) {
        s32 v = *(s32 *)((u8 *)p + 0x90);
        *(s32 *)((u8 *)q + 0x18) = v;
        fn_802E30C8(lbl_8032E048, i, v);
        p = (s32 *)((u8 *)p + 0xC0);
        q = (s32 *)((u8 *)q + 0x14);
    }
}

#pragma cplusplus on
extern "C" s32 fn_80154618(void *arg0) {
    s32 **it = (s32 **)&lbl_804348E8;
    s32 found = 0;
    s32 i = 0;
    while (i < fn_801B2F24()) {
        if (*(s32 *)((u8 *)*it + 0x1F0) == 0x50) {
            if (((TObj80154618 *)arg0)->f6(i) != 0) {
                found = 1;
            }
        }
        it++;
        i++;
    }
    it = (s32 **)0;
    if (found == 0) {
        if (fn_801B8514() != 0) {
            it = (s32 **)1;
        }
    }
    return (s32)it;
}
#pragma cplusplus off
void fn_801546D4(s32 arg0) {
    switch (fn_80161C94()) {
        case 0:
            fn_801B8A84(arg0);
            break;
    }
}

s32 fn_80154714(void) {
    return 1;
}

extern void fn_801B0F70(s32, s32);
extern void fn_80168104(void);
void fn_8015471C(s32 arg0, s32 arg1, s32 arg2) {
    fn_801B0F70(arg1, arg2);
}

void fn_80154728(void *arg0) {
    if (((u8 *)arg0)[0x8F4] != 0) {
        fn_80168104();
    }
}

s32 fn_8015473C(void) {
    return 0;
}

void fn_80154744(void) {

}

void fn_80154748(void) {

}

void fn_8015474C(void) {

}

void fn_80154750(void) {

}

#pragma cplusplus on
struct VObj3_80154754 {
    virtual void d0();
    virtual void call();
};
struct VObj10_80154754 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void call(f32 *, f32 *, f32 *);
};
struct VLfo10_80154754 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual f32 eval(void *, f32);
};
#pragma cplusplus off

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern void *fn_8000DA10();
extern void *fn_8001BB58(void *, void *, void *, s32);
extern void fn_802AE0E0(void *);
extern u8 lbl_8032E05C[];
extern f32 lbl_80559EBC;
extern f32 lbl_80561720;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void *fn_8001BB58(void *, void *, void *, s32);
extern "C" void fn_802AE0E0(void *);
extern "C" u8 lbl_8032E05C[];
extern "C" f32 lbl_80559EBC;
extern "C" f32 lbl_80561720;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80154754(u8 *self) {
    s32 i = 0;
    u8 *slot = self;
    f32 mat1[12], mat2[12], rot1[3], pos1[3], rot2[3], pos2[3];
    for (; i < *(s32 *)(self + 0xFE4); slot += 0xC0, i++) {
        void **lfo1, **lfo2;
        void *res;
        u8 *owner, *node, *next, *prev, *single;
        s32 tmp, kind;
        *(f32 *)(slot + 0xA48) = -1.0f;
        *(s32 *)(slot + 0xA50) = 0;
        *(s32 *)(slot + 0xA54) = 0;
        *(s32 *)(slot + 0xA60) = -2;
        *(s32 *)(slot + 0xA70) = 0;
        *(s32 *)(slot + 0xA6C) = 0;
        *(s32 *)(slot + 0xA74) = 0;
        *(s32 *)(slot + 0xA80) = -1;
        slot[0xA84] = 0;
        *(f32 *)(slot + 0xA7C) = -1.0f;
        *(s32 *)(slot + 0xA88) = 0;
        *(f32 *)(slot + 0x9FC) = 0.0f;
        *(f32 *)(slot + 0x9F8) = 0.0f;
        slot[0xA0C] = 0;
        *(f32 *)(slot + 0xA10) = 0.0f;
        *(f32 *)(slot + 0xA20) = 0.0f;
        *(f32 *)(slot + 0xA24) = 0.0f;
        *(f32 *)(slot + 0xA28) = 0.0f;
        *(f32 *)(slot + 0xA2C) = 0.0f;
        *(f32 *)(slot + 0xA30) = 0.0f;
        *(f32 *)(slot + 0xA34) = 0.0f;
        *(f32 *)(slot + 0xA38) = 0.0f;
        *(f32 *)(slot + 0xA40) = 0.0f;
        *(f32 *)(slot + 0xA44) = 0.0f;
        lfo1 = __AXFXGetLfoSinTable_801769CC();
        lfo2 = __AXFXGetLfoSinTable_801769CC();
        res = fn_8001BB58(fn_8000DA10(), lfo2[0], lfo1[2], 0);
        if (res != 0) {
            *(s32 *)(slot + 0xA08) = *(s32 *)((u8 *)res + 4);
        } else {
            *(s32 *)(slot + 0xA08) = 0;
        }
        *(f32 *)(slot + 0xA04) = 0.0f;
        *(f32 *)(slot + 0xA00) = 0.0f;
        if (*(s32 *)((u8 *)lbl_804348E8[*(s32 *)(slot + 0x9E4)] + 0x10) == 0x41434152) {
            *(f32 *)(slot + 0xA00) = lbl_80559EBC;
        }
        *(f32 *)(slot + 0xA14) = 0.0f;
        *(s32 *)(slot + 0xA18) = 1;
        *(f32 *)(slot + 0xA3C) = 0.0f;
        *(s32 *)(slot + 0xA1C) = 1;
        (*(VObj3_80154754 **)(slot + 0x9F4))->call();
        owner = *(u8 **)(slot + 0x9EC);
        node = *(u8 **)(owner + 0x124C);
        next = node ? *(u8 **)(node + 0x11C) : 0;
        while (node) {
            *(f32 *)(node + 8) = 99999.0f;
            *(f32 *)(node + 0xC) = 0.0f;
            prev = *(u8 **)(node + 0x120);
            if (prev) *(u8 **)(prev + 0x11C) = *(u8 **)(node + 0x11C);
            else *(u8 **)(owner + 0x124C) = *(u8 **)(node + 0x11C);
            prev = *(u8 **)(node + 0x11C);
            if (prev) *(u8 **)(prev + 0x120) = *(u8 **)(node + 0x120);
            else *(u8 **)(owner + 0x1250) = *(u8 **)(node + 0x120);
            *(u8 **)(node + 0x120) = 0;
            *(u8 **)(node + 0x11C) = 0;
            *(u8 **)(node + 0x120) = *(u8 **)(owner + 0x1248);
            prev = *(u8 **)(owner + 0x1248);
            if (prev) *(u8 **)(prev + 0x11C) = node;
            *(u8 **)(owner + 0x1248) = node;
            if (!*(u8 **)(owner + 0x1244)) *(u8 **)(owner + 0x1244) = node;
            node = next;
            next = next ? *(u8 **)(next + 0x11C) : 0;
        }
        single = *(u8 **)(owner + 0x1254);
        if (single) {
            *(u8 **)(single + 0x11C) = 0;
            *(u8 **)(single + 0x120) = *(u8 **)(owner + 0x1248);
            prev = *(u8 **)(owner + 0x1248);
            if (prev) *(u8 **)(prev + 0x11C) = single;
            *(u8 **)(owner + 0x1248) = single;
            if (!*(u8 **)(owner + 0x1244)) *(u8 **)(owner + 0x1244) = single;
            *(u8 **)(owner + 0x1254) = 0;
        }
        tmp = fn_80009C84();
        kind = 2;
        if (tmp) kind = 0;
        if (*(void **)(owner + 0x125C)) {
            fn_80206750(*(void **)(owner + 0x125C), *(s32 *)(owner + 0x1268), kind);
        }
        slot[0xA8C] = 0;
        slot[0xA8D] = 1;
        slot[0xA8E] = 0;
        tmp = fn_80009C84();
        kind = 2;
        if (tmp) kind = 0;
        if (*(void **)(slot + 0xA90)) {
            fn_80206750(*(void **)(slot + 0xA90), *(s32 *)(slot + 0x9E4), kind);
        }
    }
    i = 0;
    for (; i < *(s32 *)(self + 0x18); i++) {
        u8 *elem = (*(u8 ***)(self + 0x14))[i];
        *(f32 *)(elem + 0x34) = 0.0f;
        elem[0xC4] = 0;
        elem[0xC5] = 0;
        elem[0xC6] = 0;
        elem[0xC7] = 0;
        elem[0xC8] = 0;
        elem[0xC9] = 0;
        elem[0xCA] = 0;
        elem[0xCB] = 0;
        *(s32 *)(elem + 0x14) = 0;
        if (*(s32 *)(elem + 0x38) == 4) {
            *(f32 *)(elem + 0x18) = *(f32 *)(elem + 0x1C);
        }
    }
    i = 0;
    if (*(s32 *)(self + 0x330) > 0) {
        for (; i < *(s32 *)(self + 0x330); i++) {
            u8 *entry = (*(u8 ***)(self + 0x32C))[i];
            entry[4] = 1;
            *(f32 *)(entry + 0x14) = -99999.0f;
            mat1[0] = 1.0f; mat1[1] = 0.0f; mat1[2] = 0.0f;
            mat1[3] = 0.0f; mat1[4] = 1.0f; mat1[5] = 0.0f;
            mat1[6] = 0.0f; mat1[7] = 0.0f; mat1[8] = 1.0f;
            mat1[9] = 0.0f; mat1[10] = 0.0f; mat1[11] = 0.0f;
            mat1[9] = *(f32 *)(entry + 8);
            mat1[10] = *(f32 *)(entry + 0xC);
            mat1[11] = *(f32 *)(entry + 0x10);
            rot1[0] = 0.0f; rot1[1] = 0.0f; rot1[2] = 0.0f;
            pos1[0] = 0.0f; pos1[1] = 0.0f; pos1[2] = 0.0f;
            (*(VObj10_80154754 **)entry)->call(mat1, pos1, rot1);
        }
    }
    i = 0;
    if (*(s32 *)(self + 0x3BC) > 0) {
        for (; i < *(s32 *)(self + 0x3BC); i++) {
            u8 *entry = (*(u8 ***)(self + 0x3B8))[i];
            entry[4] = 1;
            *(f32 *)(entry + 0x14) = -99999.0f;
            mat2[0] = 1.0f; mat2[1] = 0.0f; mat2[2] = 0.0f;
            mat2[3] = 0.0f; mat2[4] = 1.0f; mat2[5] = 0.0f;
            mat2[6] = 0.0f; mat2[7] = 0.0f; mat2[8] = 1.0f;
            mat2[9] = 0.0f; mat2[10] = 0.0f; mat2[11] = 0.0f;
            mat2[9] = *(f32 *)(entry + 8);
            mat2[10] = *(f32 *)(entry + 0xC);
            mat2[11] = *(f32 *)(entry + 0x10);
            rot2[0] = 0.0f; rot2[1] = 0.0f; rot2[2] = 0.0f;
            pos2[0] = 0.0f; pos2[1] = 0.0f; pos2[2] = 0.0f;
            (*(VObj10_80154754 **)entry)->call(mat2, pos2, rot2);
        }
    }
    *(f32 *)(self + 0x8D4) = 0.0f;
    self[0x8E4] = 0;
    {
        u8 *p = *(u8 **)(self + 0x8E8);
        if (p) {
            p[0x4A] = 1;
            p[0x4C] = 0;
        }
        p = *(u8 **)(self + 0x8EC);
        if (p) {
            p[0x4A] = 1;
            p[0x4C] = 0;
        }
    }
    self[0x8F0] = 0;
    *(f32 *)(self + 0x8DC) = *(f32 *)(self + 0x8E0);
    {
        VLfo10_80154754 *lfo = *(VLfo10_80154754 **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        *(f32 *)(self + 0x10) = lfo->eval(lbl_8032E05C, -1.0f);
    }
    {
        u32 j = 0;
        do {
            if (*(void **)(self + 0x45C)) {
                u8 *sub;
                *(s32 *)(self + 0x454) = 0;
                *(f32 *)(self + 0x458) = -1.0f;
                *(s32 *)(self + 0x474) = 0;
                *(s32 *)(self + 0x478) = 0;
                *(s32 *)(self + 0x47C) = 0;
                self[0x460] = 0;
                fn_802AE0E0(*(void **)(self + 0x45C));
                sub = *(u8 **)(self + 0x464);
                if (sub) {
                    sub[0x4A] = 1;
                    sub[0x4C] = 0;
                }
                sub = *(u8 **)(self + 0x468);
                if (sub) {
                    sub[0x4A] = 1;
                    sub[0x4C] = 0;
                }
                sub = *(u8 **)(self + 0x46C);
                if (sub) {
                    sub[0x4A] = 1;
                    sub[0x4C] = 0;
                }
            }
            j++;
            self += 0x240;
        } while (j < 2U);
    }
}
#pragma cplusplus off
#pragma pop

#pragma cplusplus off
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern u8 lbl_8032E150[];
extern f32 lbl_8055E24C, lbl_80561724, lbl_80561728;
extern void fn_801552C8(void **), fn_80155318(void *);
extern s32 fn_8014F088(s32,s32);
extern void *fn_802076A0(void *,s32,s32,s32);
extern s32 fn_802CAC28(void *,s32);
extern s32 fn_801572A4(void *,s32,void *);
extern void fn_801EA1E0(void *,s32,f32,f32);
extern void *fn_8000DA10(void);
extern void fn_801332D0(void *,void *,s32 *);
extern char *strncpy(char *,const char *,unsigned long);
#pragma cplusplus off
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80154D30(char *p) {
    s32 iscar,found,off,j,i;
    char *obj,*entry,*node,*prev,*sound,*name,*other;
    char shortname[8], path2[64], path[64];
    void **table;
    f64 value;
    f32 zero;
    u8 *strings = lbl_8032D358;
    u8 *fallback, *sound2, *sound1;
    *(s32 *)(p+0xfe4)=lbl_8055E4D0;
    i=0;
    if (*(s32 *)(p+0xfe4) > 0) {
    fallback=strings+0xd14; sound1=strings+0xd30; sound2=strings+0xd3c;
    entry=p;
    table=(void **)lbl_804348E8;
    zero=lbl_8056164C;
    for(;i<*(s32 *)(p+0xfe4);table++,entry+=0xc0,i++) {
        iscar=(*(s32 *)((char *)*table+0x10)==0x41434152);
        obj=(char *)fn_801284F8(0x126c, strings+0xd24);
        if(obj) {
            *(void **)obj=lbl_8032E190;
            ((void (*)(void *,void *,void *,s32,s32))fn_8002F53C)(obj+4,(void *)fn_80155318,(void *)fn_8014EFC0,0x124,16);
            *(void **)(obj+0x1248)=0; *(void **)(obj+0x1244)=0;
            *(s32 *)(obj+0x1250)=0; *(s32 *)(obj+0x124c)=0;
            node=obj+4;
            for(j=0;j<16;j++,node+=0x124) {
                *(void **)(node+0x118)=obj;
                *(s32 *)(node+0x110)=i;
                *(void **)(node+0x120)=0;
                *(void **)(node+0x11c)=*(void **)(obj+0x1244);
                prev=*(char * volatile *)(obj+0x1244);
                if(prev) *(void **)(prev+0x120)=node;
                *(void **)(obj+0x1244)=node;
                if(!*(void **)(obj+0x1248)) *(void **)(obj+0x1248)=node;
            }
            *(s32 *)(obj+0x1254)=0; obj[0x1260]=0; *(s32 *)(obj+0x1268)=i;
            if(iscar) *(void **)(obj+0x1258)=0; else *(void **)(obj+0x1258)=fn_802076A0(sound1,1,i,0);
            sound=*(char **)(obj+0x1258);
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=1; *(f32 *)(sound+8)=zero;}
            if(iscar) *(void **)(obj+0x125c)=0; else *(void **)(obj+0x125c)=fn_802076A0(sound2,1,i,2);
            sound=*(char **)(obj+0x125c);
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=1; *(f32 *)(sound+8)=zero;}
        }
        *(void **)(entry+0x9ec)=obj;
        obj=(char *)fn_801284F8(0xf90,strings+0xd4c);
        if(obj) {
            *(void **)obj=lbl_8032E150; *(void **)(obj+4)=obj+0x10;
            *(s32 *)(obj+0xc)=16; *(s32 *)(obj+8)=0;
            ((void (*)(void *,void *,void *,s32,s32))fn_8002F53C)(obj+0x10,(void *)fn_801552C8,(void *)fn_8014F088,0xf8,16);
        }
        *(void **)(entry+0x9f0)=obj;
        *(void **)(entry+0xa4c)=p;
        *(s32 *)(entry+0x9e4)=i;
        *(s32 *)(entry+0x9e8)=!iscar;
        *(s32 *)(entry+0xa98)=fn_802CAC28(strings+0xd5c,0);
        *(s32 *)(entry+0xa9c)=fn_802CAC28(strings+0xd68,0);
        name=fn_80012820(*(s32 *)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC())+4))+8;
        found=0;
        ((s32 (*)(char *,s32,char *,...))fn_801345D8)(path,0x40,(char *)strings+0xd78);
        fn_801332D0((char *)fn_8000DA10()+12,path,&found);
        if(!found) *(s32 *)(entry+0xaa0)=fn_802CAC28(fallback,0);
        else {
            memset(shortname,0,8); strncpy(shortname,name,3);
            ((s32 (*)(char *,s32,char *,...))fn_801345D8)(path2,0x40,(char *)strings+0xd84,shortname,found);
            if(fn_8012C33C(path2)) *(s32 *)(entry+0xaa0)=fn_802CAC28(path2,0);
            else { ((void (*)(char *,...))fn_802E30C8)((char *)strings+0xd90,path2); *(s32 *)(entry+0xaa0)=fn_802CAC28(fallback,0); }
        }
        *(s32 *)(entry+0x9f4)=fn_801572A4(*(void **)(entry+0x9ec),*(s32 *)(entry+0x9e4),&lbl_8055E24C);
        *(void **)(entry+0xa94)=0; *(void **)(entry+0xa90)=0;
        if(!iscar) {
            sound=fn_802076A0(strings+0xdb4,1,*(s32 *)(entry+0x9e4),2);
            *(void **)(entry+0xa90)=sound;
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=1; *(f32 *)(sound+8)=zero;}
            *(void **)(entry+0xa94)=fn_802076A0(strings+0xdc0,7,*(s32 *)(entry+0x9e4),0);
        }
    }
    }
    for(i=0,off=0;i<*(s32 *)(p+0x330);off+=4,i++) {
        other=*(char **)(*(char **)(p+0x32c)+off);
        fn_801EA1E0(other+12,1,*(f32 *)(other+8),*(f32 *)(other+0x10));
    }
    for(i=0,off=0;i<*(s32 *)(p+0x3bc);off+=4,i++) {
        other=*(char **)(*(char **)(p+0x3b8)+off);
        fn_801EA1E0(other+12,1,*(f32 *)(other+8),*(f32 *)(other+0x10));
    }
    table=__AXFXGetLfoSinTable_801769CC();
    value=fn_8014E7DC((s32)*__AXFXGetLfoSinTable_801769CC(),*(s32 *)((char *)table+8));
    if(*(s32 *)((char *)__AXFXGetLfoSinTable_801769CC()+0x10)&1) value=lbl_80561724;
    *(f32 *)(p+0x8dc)=value; *(f32 *)(p+0x8e0)=value;
    if(fn_80179650()>1) *(f32 *)(p+0x8d8)=lbl_80561728;
}
#pragma pop

s32 fn_80155288(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern void lbl_8032E160(void);
void fn_801552C8(void **arg0) {
    *arg0 = (void *)&lbl_8032E160;
}

s32 fn_801552D8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern s32 lbl_8032E1A0[];
extern f32 lbl_8056171C;
void fn_80155318(void *arg0) {
    f32 f0 = lbl_80561648;
    f32 f1 = lbl_8056171C;
    *(s32 **)arg0 = lbl_8032E1A0;
    *(s32 *)((u8 *)arg0 + 0x120) = 0;
    *(s32 *)((u8 *)arg0 + 0x11C) = 0;
    *((u8 *)arg0 + 4) = 0;
    *(f32 *)((u8 *)arg0 + 8) = f1;
    *(f32 *)((u8 *)arg0 + 0xC) = f0;
    *(f32 *)((u8 *)arg0 + 0x10) = f0;
    *(s32 *)((u8 *)arg0 + 0x118) = 0;
    *(s32 *)((u8 *)arg0 + 0x10C) = -1;
    *((u8 *)arg0 + 5) = 0;
    *((u8 *)arg0 + 0x14) = 0;
    *((u8 *)arg0 + 0x64) = 0;
    *((u8 *)arg0 + 0xB4) = 0;
}
void fn_80155368(void) {

}

extern s32 fn_80161BB8(void);
extern s32 lbl_80559EC0;
#pragma push
#pragma use_lmw_stmw off
void fn_8015536C(void *arg0, void *arg1, s32 index) {
    s32 offset=index*0xC0;
    u8 *p=(u8*)arg0+0xa8c+offset;
    s32 state=*(s32 *)((u8 *)(p)-0xa4);
    s32 count,positive,id,i,j,flag;
    u8 *entry,*flags,*owner,*node,*next,*prev,*obj;
    if(state==0)flag=0;
    else if(state==1)flag=1;
    else flag=(f32)__fabs(*(f32 *)((u8 *)(p)-0x8c)-lbl_8056164C)<=lbl_80558DC4[0];
    if(flag){
        i=0;
        for (; i<*(s32 *)((u8 *)(arg0)+0x18); i++){
            entry=(*(u8***)((u8*)arg0+0x14))[i];
            id=*(s32 *)((u8 *)(entry)+0xC0);
            if(id==((s32(*)(void*,void*))(*(void***)arg1)[9])(arg1,entry)){
                entry=(*(u8***)((u8*)arg0+0x14))[i];
                if(lbl_80558DC4[0]>=(f32)__fabs(*(f32 *)((u8 *)(entry)+0x34))){
                    if(lbl_80558DC4[0]>=(f32)__fabs(*(f32 *)((u8 *)(lbl_804348E8[index])+0x2690)) && fn_80161BB8()==0)
                        entry[index+0xC4]=1;
                }
            }
        }
    }
    if(((s32(*)(void*))(*(void***)arg1)[8])(arg1)==0x73){
        positive=*(f32 *)((u8 *)(lbl_804348E8[index])+0x25BC)>lbl_80558DC4[0];
        p=(u8*)arg0+0xa8c+offset;
        flags=p+0x0;
        if(*flags){
            obj=*(u8* *)((u8 *)(p)-0x98);
            ((void(*)(void*,s32))(*(void***)obj)[15])(obj,lbl_804348E8[*(s32 *)((u8 *)(p)-0xa8)]);
        }
        if(flags[1]){
            p=(u8*)arg0+0xa8c+offset;
            *(f32 *)((u8 *)(p)-0x6c)=lbl_80561648;
            *(f32 *)((u8 *)(p)-0x8c)=lbl_8056163C**(f32 *)((u8 *)(p)-0x8c);
            *(s32 *)((u8 *)(p)-0x4)=0;
            owner=*(u8* *)((u8 *)(p)-0xa0);
            node=*(u8* *)((u8 *)(owner)+0x124C);
            next=node?*(u8* *)((u8 *)(node)+0x11C):0;
            while(node){
                if(node[4]){
                    prev=*(u8* *)((u8 *)(node)+0x120);
                    if(prev)*(u8* *)((u8 *)(prev)+0x11C)=*(u8* *)((u8 *)(node)+0x11C);
                    else *(u8* *)((u8 *)(owner)+0x124C)=*(u8* *)((u8 *)(node)+0x11C);
                    prev=*(u8* *)((u8 *)(node)+0x11C);
                    if(prev)*(u8* *)((u8 *)(prev)+0x120)=*(u8* *)((u8 *)(node)+0x120);
                    else *(u8* *)((u8 *)(owner)+0x1250)=*(u8* *)((u8 *)(node)+0x120);
                    *(u8* *)((u8 *)(node)+0x120)=0;
                    *(u8* *)((u8 *)(node)+0x11C)=0;
                    *(u8* *)((u8 *)(node)+0x120)=*(u8* *)((u8 *)(owner)+0x1248);
                    prev=*(u8* *)((u8 *)(owner)+0x1248);
                    if(prev)*(u8* *)((u8 *)(prev)+0x11C)=node;
                    *(u8* *)((u8 *)(owner)+0x1248)=node;
                    if(!*(u8* *)((u8 *)(owner)+0x1244))*(u8* *)((u8 *)(owner)+0x1244)=node;
                }
                node=next;
                next=next?*(u8* *)((u8 *)(next)+0x11C):0;
            }
            p=(u8*)arg0+0xa8c+offset;
            *(f32 *)((u8 *)(p)-0x94)=*(f32 *)((u8 *)(p)-0x94)+lbl_80561648;
            obj=*(u8* *)((u8 *)(p)-0x98);
            ((void(*)(void*))(*(void***)obj)[4])(obj);
            p=(u8*)arg0+0xa8c+offset;
            if(*(s32 *)((u8 *)(p)-0x74)>1)*(f32 *)((u8 *)(p)-0x68)=lbl_80561688;
            count=*(s32 *)((u8 *)(p)-0x74)-1;
            *(s32 *)((u8 *)(p)-0x74)=count>1?count:1;
            p=(u8*)arg0+0xa8c+offset;
            *(f32 *)((u8 *)(p)-0x58)=lbl_80561648;
            *(f32 *)((u8 *)(p)-0x5c)=lbl_80561648;
            *(f32 *)((u8 *)(p)-0x60)=lbl_80561648;
            *(f32 *)((u8 *)(p)-0x64)=lbl_80561648;
        }
        if(positive){
            if(lbl_80559EC0==1)flags[2]=1;
            if(lbl_80559EC0==3){flags[3]=1;flags[1]=1;}
        }
        obj=*(u8* *)((u8 *)((u8*)arg0+offset)+0x9F4);
        ((void(*)(void*,s32))(*(void***)obj)[13])(obj,lbl_804348E8[*(s32 *)((u8 *)(p)-0xa8)]);
    }
}
#pragma pop

void fn_801556F0(void) {

}

void fn_801556F4(void) {

}

void fn_801556F8(void) {

}

void fn_801556FC(void) {

}

#pragma push
#pragma use_lmw_stmw off
void fn_80155700(void *arg0, void *arg1, s32 index) {
    register f32 *first, *second;
    u8 *self = (u8 *)arg0;
    u8 *player = fn_8017960C(index);
    u8 *slot, *entry, *obj, *manager, *player2;
    f32 mat1[12], mat2[12], rot1[3], pos1[3], rot2[3], pos2[3];
    Event80155700 event;
    f32 zero, height, duration, threshold, one, value;
    s32 i, active;
    register s32 kind;
    f32 *v;
    if (player && (f32)__fabs(*(f32 *)(player+0x2690)) <= lbl_80558DC4[0] &&
        ((s32 (*)(void *,s32))(*(void ***)arg0)[8])(arg0,index) &&
        fn_80161BB8() == 0 && *(s32 *)(player+0x1F0) == 0x50) {
        one=lbl_8056164C; zero=lbl_80561648; height=lbl_8056172C; duration=lbl_80561730; threshold=lbl_8056163C;
        slot = self + index * 0xC0;
        first=mat1;
        for (i = 0; i < *(s32 *)(self+0x330); i++) {
            entry = (*(u8 ***)(self+0x32C))[i];
            if (*(void **)entry == arg1 && entry[4]) {
                entry[4]=0;
                first[0]=one; first[1]=zero; first[2]=zero;
                first[3]=zero; first[4]=one; first[5]=zero;
                first[6]=zero; first[7]=zero; first[8]=one;
                first[9]=zero; first[11]=zero; first[10]=height;
                rot1[0]=zero; rot1[1]=zero; rot1[2]=zero;
                pos1[0]=zero; pos1[1]=zero; pos1[2]=zero;
                obj=*(u8 **)entry;
                ((void (*)(void *,f32 *,f32 *,f32 *))(*(void ***)obj)[10])(obj,first,pos1,rot1);
                obj=*(u8 **)entry;
                ((void (*)(void *,s32))(*(void ***)obj)[8])(obj,0);
                *(f32 *)(entry+0x14)=duration+lbl_8055E3C8;
                obj=*(u8 **)entry;
                obj=((u8 *(*)(void *))(*(void ***)obj)[2])(obj);
                value=((f32 (*)(void *,void *,f32))(*(void ***)obj)[10])(obj,lbl_80559FB8,lbl_80561730);
            } else value=lbl_80561648;
            if (value > threshold) {
                manager=*(u8 **)(self+0x444);
                if (manager) {
                    fn_80206750(manager,index,0);
                    manager=*(u8 **)(self+0x444);
                    manager[0x49]=1; manager[0x4B]=0; manager[0x4A]=0;
                }
                *(f32 *)(slot+0x9F8) += value;
            }
        }
        {
        f32 one2=lbl_8056164C, zero2=lbl_80561648, height2=lbl_8056172C, duration2=lbl_80561730;
        second=mat2;
        for (i = 0; i < *(s32 *)(self+0x3BC); i++) {
            entry=(*(u8 ***)(self+0x3B8))[i];
            if (*(void **)entry == arg1 && entry[4]) {
                player2=fn_8017960C(index);
                if (player2) {
                    v=((f32 *(*)(void *))(*(void ***)arg1)[4])(arg1);
                    event.pos[0]=v[0]; event.pos[1]=v[1]; event.pos[2]=v[2];
                    event.velocity[0]=*(f32 *)(player2+0x118);
                    event.velocity[1]=*(f32 *)(player2+0x11C);
                    event.velocity[2]=*(f32 *)(player2+0x120);
                    event.angle=*(s16 *)(player2+0x6C); event.value=0x96;
                    fn_801796EC(10,&event,0x20);
                }
                entry[4]=0;
                second[0]=one2; second[1]=zero2; second[2]=zero2;
                second[3]=zero2; second[4]=one2; second[5]=zero2;
                second[6]=zero2; second[7]=zero2; second[8]=one2;
                second[9]=zero2; second[11]=zero2; second[10]=height2;
                rot2[0]=zero2; rot2[1]=zero2; rot2[2]=zero2;
                pos2[0]=zero2; pos2[1]=zero2; pos2[2]=zero2;
                obj=*(u8 **)entry;
                ((void (*)(void *,f32 *,f32 *,f32 *))(*(void ***)obj)[10])(obj,second,pos2,rot2);
                obj=*(u8 **)entry;
                ((void (*)(void *,s32))(*(void ***)obj)[8])(obj,0);
                *(f32 *)(entry+0x14)=duration2+lbl_8055E3C8;
                active=1;
            } else active=0;
            if (active) {
                manager=*(u8 **)(self+0x448);
                if (manager) {
                    kind=2;
                    if (fn_80009C84()) kind=0;
                    fn_80206750(*(u8 **)(self+0x448),index,kind);
                    manager=*(u8 **)(self+0x448);
                    manager[0x49]=1; manager[0x4B]=0; manager[0x4A]=0;
                }
                fn_8018A120(player);
                fn_80161A38(3,index,0);
            }
        }
        }
    }
}
#pragma pop

void fn_80155AEC(void) {

}

u32 fn_80155C88(void) { return 1; }

extern int vsprintf(char *, const char *, va_list);
void fn_80155C90(void *arg0, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)arg0 + 0x14, fmt, ap);
}

void fn_80155D20(void *arg0, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)arg0 + 0x64, fmt, ap);
}

void fn_80155DB0(void *arg0, const char *fmt, ...) {
    char *dest = (char *)arg0 + 0xB4;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(dest, fmt, ap);
    va_end(ap);
}

void fn_80155E40(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x108) = arg1;
    *(s32 *)((u8 *)arg0 + 0x114) = 1;
}

void fn_80155E50(void *arg0, int arg1) { *(int *)((char *)arg0 + 0x10C) = arg1; }

void fn_80155E58(void *arg0) {
    ((u8 *)arg0)[4] = 0;
}

void fn_80155E64(void *arg0, signed char arg1) { *((signed char *)arg0 + 5) = arg1; }

void *fn_80155E6C(void *arg0) {
    typedef struct Node Node;
    struct Node {
        u8 pad[0x11C];
        Node *prev;
        Node *next;
    };
    typedef struct {
        u8 pad[0x1244];
        Node *head;
        Node *tail;
        Node *first;
        Node *list;
    } Owner;
    Owner *owner = (Owner *)arg0;
    Node *node = owner->head;
    Node *next;
    Node *prev;
    Node *tail;

    if (node != 0) {
        next = node->next;
        if (next != 0) {
            next->prev = node->prev;
        } else {
            owner->head = node->prev;
        }
        prev = node->prev;
        if (prev != 0) {
            prev->next = node->next;
        } else {
            owner->tail = node->next;
        }

        node->next = 0;
        node->prev = 0;
        node->next = owner->list;
        tail = owner->list;
        if (tail != 0) {
            tail->prev = node;
        }
        owner->list = node;
        if (owner->first == 0) {
            owner->first = node;
        }

        *((u8 *)node + 4) = 1;
        *(f32 *)((u8 *)node + 0x10) = lbl_8055E3C8;
        *(f32 *)((u8 *)node + 0xC) = lbl_80561648;
        *(f32 *)((u8 *)node + 8) = lbl_80561648;
        *((u8 *)node + 0x14) = 0;
        *((u8 *)node + 0x64) = 0;
        *((u8 *)node + 0xB4) = 0;
        *((u8 *)node + 5) = 0;
        *(s32 *)((u8 *)node + 0x10C) = -1;
        *(f32 *)((u8 *)node + 0x104) = lbl_80561648;
        *(s32 *)((u8 *)node + 0x108) = 0;
        *(s32 *)((u8 *)node + 0x114) = 1;
        return node;
    }
    return 0;
}

void fn_80155F44(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf(dst + 4, fmt, args);
}

void fn_80155FD4(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0x54, fmt, args);
}

void fn_80156064(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0xA4, fmt, args);
}

void fn_801560F4(void) {

}

void fn_801560F8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xF4) = arg1;
}

void fn_80156100(void) {

}

void fn_80156104(void) {

}

void fn_80156108(void) {

}

s32 fn_8015610C(void *arg0) { s32 *base = *(s32 **)((u8 *)arg0 + 4); s32 index = *(s32 *)((u8 *)arg0 + 8); *(s32 *)((u8 *)arg0 + 8) = index + 1; return (s32)base + index * 0xF8; }

s32 fn_8014F0C8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8014F088(s32 arg0, s32 arg1);
void fn_8014F108(void *arg0) {
    void *base = arg0;
    void *entry = base;
    u8 *member = (u8 *)base + 0x454;
    u32 i = 0;
    do {
        s32 result = fn_801284F8(8, &lbl_8032DB34);
        if (result != 0)
            result = ((s32 (*)(s32, s32))fn_802ADDD8)(result, 2);
        *(s32 *)((u8 *)entry + 0x45C) = result;
        fn_8014F194(member);
        i++;
        entry = (u8 *)entry + 0x240;
        member += 0x240;
    } while (i < 2);
    *(s32 *)((u8 *)base + 0x9D8) = fn_80145E70(lbl_8032DB40);
}

#pragma cplusplus on
extern "C" void fn_8014FB7C(register u8 *arg0) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    register VObj *p;
    p = *(VObj **)(arg0 + 0x9D8);
    if (p != 0) {
        if (p != 0) p->d0(1);
        *(VObj **)(arg0 + 0x9D8) = 0;
    }
    register s32 i = 1;
    register u8 *obj = arg0 + 0x240;
    do {
        if (*(void **)(obj + 0x45C) != 0) {
            fn_802ADE60((void **)*(void **)(obj + 0x45C), 1);
            *(s32 *)(obj + 0x45C) = 0;
        }
        p = *(VObj **)(obj + 0x464);
        if (p != 0) {
            if (p != 0) p->d0(1);
            *(VObj **)(obj + 0x464) = 0;
        }
        p = *(VObj **)(obj + 0x468);
        if (p != 0) {
            if (p != 0) p->d0(1);
            *(VObj **)(obj + 0x468) = 0;
        }
        p = *(VObj **)(obj + 0x46C);
        if (p != 0) {
            if (p != 0) p->d0(1);
            *(VObj **)(obj + 0x46C) = 0;
        }
        --i;
        obj -= 0x240;
    } while (i >= 0);
}

extern "C" f32 lbl_8055E24C;
extern "C" f32 lbl_805616D4, lbl_805616D8, lbl_805616DC;
extern "C" s32 lbl_80559F88;
extern "C" void *lbl_80559F80;
extern "C" void *lbl_80559F90;
extern "C" f32 lbl_80559EB4;
extern "C" void fn_8013A0B0(void **, void *, void *);
extern "C" void fn_8013A198(void **, s32);
extern "C" void *fn_8015011C(void *);
extern "C" void *fn_80204CF0(void);
extern "C" void *fn_80204BB4(void);
extern "C" f32 fn_801EA0E8(f32, f32);
extern "C" f64 fn_8002F234(void);
extern "C" int sprintf(void *, void *, s32);
extern "C" void fn_8014FC8C(s32 arg0) {
    class EvalObj { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual f32 eval(void *, f32); };
    class LfoObj { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void *lookup(void *, void *); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void *get(s32); };
    class Manager { public: virtual void d0(); virtual void *get(s32); };
    class Entry { public: virtual void d0(); virtual s32 has(void *); virtual void d2(); virtual void next(void *); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void *value(void *); };
    u8 sp60[256];
    u8 sp40[32];
    f32 sp38, sp34, sp30, sp24, sp20, sp1C, sp18;
    s32 sp2C, sp28, spC, sp8;
    void *sp10p;
    void *manager;
    void *resource;
    void *entry;
    s32 i, j, k, size, handle;
    f32 f29v, f31v, f1v;
    u8 *strings = lbl_8032D358;
    lbl_8055E24C = lbl_805616D4;
    fn_8013A0B0(&sp10p, strings + 0xAB0, &lbl_80559F4C);
    {
        void *o = sp10p;
        if (o != 0) {
            lbl_8055E24C = lbl_805616D8 * ((EvalObj *)o)->eval(strings + 0xABC, lbl_805616DC);
            {
                f32 v = ((EvalObj *)o)->eval(strings + 0xACC, lbl_8056164C);
                lbl_80559EB4 = v;
                ((void (*)(char *, ...))fn_802E30C8)((char *)(strings + 0xADC), v);
            }
        }
    }
    fn_8013A198(&sp10p, -1);
    manager = fn_80131810((const char *)((LfoObj *)(*(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20)))->lookup(strings + 0xAFC, strings + 0xB0C));
    if (manager != 0) {
        s32 idx = 0;
        while (1) {
            void *e = ((Manager *)manager)->get(idx);
            if (e == 0) break;
            void *r = fn_80204CF0();
            void *check;
            if (((Entry *)e)->has(strings + 0xA30) != 0) {
                ((Entry *)e)->next(strings + 0xA30);
                check = (void *)fn_80204BB4();
            } else check = r;
            if (check == r) {
                void *alloc = (void *)fn_801284F8(0xD4, &lbl_80559F80);
                if (alloc != 0) alloc = fn_8015011C(e);
                spC = (s32)alloc;
                fn_801500F8((void *)(arg0 + 0x14), &spC);
            }
            idx++;
        }
        fn_80131818(manager);
    } else {
        void *lfo = *(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        s32 idx = 0;
        while (1) {
            void *e = ((LfoObj *)lfo)->get(idx);
            if (e == 0) break;
            if (((Entry *)e)->has(&lbl_80559F88) != 0) {
                void *alloc = (void *)fn_801284F8(0xD4, &lbl_80559F80);
                if (alloc != 0) alloc = fn_8015011C(e);
                sp8 = (s32)alloc;
                fn_801500F8((void *)(arg0 + 0x14), &sp8);
            }
            idx++;
        }
    }
    resource = fn_80131810((const char *)(strings + 0xB1C));
    if (resource != 0) {
        f29v = lbl_80561648;
        f31v = lbl_8056164C;
        s32 idx = 0;
        while (1) {
            entry = ((Manager *)resource)->get(idx);
            if (entry == 0) break;
            sp20 = f29v;
            sp24 = f29v;
            {
                u8 *dst = sp60;
                s32 n = 0;
                while (1) {
                    sprintf(sp40, &lbl_80559F90, n);
                    if (((Entry *)entry)->has(sp40) == 0) break;
                    void *tmp = ((Entry *)entry)->value(sp40);
                    sp28 = (s32)tmp;
                    sp2C = (s32)tmp;
                    {
                        f32 fy = *(f32 *)&sp28;
                        f32 fx = *(f32 *)&sp2C;
                        sp20 += fy;
                        *(f32 *)dst = fy;
                        *(f32 *)(dst + 4) = fx;
                        sp24 += fx;
                    }
                    dst += 8;
                    n++;
                }
                i = n;
                {
                    u8 *p = sp60;
                    f32 avg1 = sp20 * (f31v / (f32)n);
                    f32 avg2 = sp24 * (f31v / (f32)n);
                    sp20 = avg1;
                    sp24 = avg2;
                    if (n > 0) {
                        f32 maxv = lbl_80561648;
                        s32 ctr = n;
                        do {
                            f32 dy = *(f32 *)(p + 4) - avg2;
                            f32 dx = *(f32 *)p - avg1;
                            sp1C = dy;
                            sp18 = dx;
                            f32 dist = dx * dx + dy * dy;
                            if (!(maxv > dist)) maxv = dist;
                            p += 8;
                            ctr--;
                        } while (ctr != 0);
                        f1v = maxv;
                    } else f1v = lbl_80561648;
                }
            }
            {
                f32 rad = (f32)fn_8002F234();
                f32 diag = fn_801EA0E8(sp20, sp24);
                sp34 = diag;
                sp30 = sp20;
                sp38 = sp24;
                void *alloc = (void *)fn_801284F8(0x14, &lbl_80559F40);
                if (alloc != 0) {
                    *(f32 *)alloc = sp30;
                    *(f32 *)((u8 *)alloc + 4) = sp34;
                    *(f32 *)((u8 *)alloc + 8) = sp38;
                    *(f32 *)((u8 *)alloc + 12) = rad;
                    *((u8 *)alloc + 16) = 1;
                }
                {
                    s32 *a = (s32 *)(arg0 + 0x220);
                    s32 cnt = *(s32 *)(arg0 + 0x224);
                    *(s32 *)(arg0 + 0x224) = cnt + 1;
                    a[cnt] = (s32)alloc;
                }
            }
            idx++;
        }
        fn_80131818(resource);
    }
}

#pragma cplusplus reset

extern unsigned long lbl_80559E94;
extern unsigned long lbl_80559E9C;
extern s32 fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_8056164C;
extern f32 lbl_80561650;
extern u8 lbl_8032D358[];
extern u8 lbl_8032E1E4[];
extern u8 lbl_8032E1D8[];
extern u8 lbl_8032E1CC[];
extern u8 lbl_80559FB8[];
#pragma cplusplus on
class Obj80155AF0 {
public:
    virtual void d0();
    virtual void *get();
    virtual void d2();
    virtual int check(const void *);
    virtual void *values();
};
#pragma cplusplus off
#pragma cplusplus on
class Dummy_DC08 { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); };
#pragma cplusplus off
