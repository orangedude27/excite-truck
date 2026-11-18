// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
#include <stdarg.h>
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
extern f32 lbl_80561654, lbl_80561658, lbl_8056165C, lbl_80561660, lbl_80561664;
extern f32 lbl_80561668, lbl_8056166C, lbl_80561670, lbl_80561674, lbl_80561678, lbl_8056167C;
extern f32 lbl_80561648, lbl_8056164C, lbl_80561650;
extern f32 lbl_80559EB8;
extern void fn_801683F4(void *, s32);
extern f32 fn_80141C9C(f32);
extern s32 fn_80144C90(f32);
extern void fn_80142B60(void *);
extern void fn_802C744C(s32, f32 *);
extern s32 fn_8014ADD0(void *);
extern s32 fn_8014ADD8(void *);
extern void fn_8014AE1C(void *, void *);
extern void fn_8014AE54(void *);
extern void fn_8014AE60(void *);
extern s32 fn_8014AEB8(void *);
extern s32 fn_8014AEC0(void *);
extern f32 fn_8014AEC8(void *);
extern f32 fn_8014AED8(void *);
extern u8 fn_8014AEE0(void *);
extern u8 fn_8014AEE8(void *);
extern void fn_8014AEF0(void *);
extern s32 fn_8014AF58(void *);
extern void fn_8014AF60(void *, void *, s32);
extern s32 fn_8014AD64(void *);
extern f32 fn_8014AD6C(void *);
extern void fn_8014AD74(void *);
extern s32 fn_80141F7C(f32);
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
extern u8 lbl_8032E1E4[];
extern u8 lbl_8032E1D8[];
extern u8 lbl_8032E1CC[];
extern u8 lbl_80559FB8[];
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
/* One line of the game's on-screen text, as the printers of text_80144F40.cpp
 * draw it: the TextEntry80145C08 block fn_80145B94 reads (see the comment there
 * for the fields) plus the string pointer at +0x1C that fn_801476C4 hands to
 * it.  x, y and scale are floats, but a copy of an entry moves them as raw
 * words - it never converts them. */
typedef struct {
    s32 id;            /* +0x00 "name" */
    u32 x;             /* +0x04 f32 screen x */
    u32 y;             /* +0x08 f32 screen y */
    s32 justification; /* +0x0C "elem_just" */
    f32 scale;         /* +0x10 scale (the drawer of fn_80145B94 reads it as alpha) */
    s32 fontId;        /* +0x14 font the drawer picks */
    u32 color;         /* +0x18 colour, packed by fn_80144C68 */
    const char *text;  /* +0x1C string to draw */
} TextEntry8014C920;
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
class Layout_8014CA48 {
public:
    virtual void d0();
    virtual void *text(void *);
    virtual void *rect(void *);
    virtual void load(void *);
};
#pragma cplusplus off
extern u8 lbl_8032D358[];
extern void *fn_80131808(void *);
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
/* Clearing/deleting destructor-style helper: zeros the first three 32-bit fields of the object, frees it via fn_80128668 when deletingFlag > 0, and returns the object. (renames unavailable: fn_801491B8) */
void *fn_801491B8(void *object, s32 deletingFlag) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (deletingFlag > 0)
            fn_80128668(object);
    }
    return object;
}

void fn_80149210(int *object) {
    /* Advance the object's 4-entry palette color index (0..3) to the next entry, wrapping at 4. */
    object[1] = (object[1] + 1) % 4;
}

s32 fn_80149234(void *object) {
    /* Returns the color from the 4-entry palette at lbl_802F93D0 selected by the object's color-index field. */
    S4_80149234 palette;
    palette = *(S4_80149234 *)lbl_802F93D0;
    return palette.v[((s32 *)object)[1]];
}

extern s32 lbl_8055E240;
extern f32 lbl_80561714, lbl_80561718;
#pragma cplusplus on
extern "C" s32 fn_80149274(Dummy_80149274 *colorSource) {
    /* Return the source's packed color with the high bit cleared on each of the
     * three low (RGB) bytes, converting 8-bit channels to 7-bit. */
    return colorSource->d2() & 0xFF7F7F7F;
}
#pragma cplusplus off
/* Adjusts the byte field at offset 0x18 of an indexed sub-object by a delta and clamps it to [0, 255]. */
void fn_801492AC(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 clampedValue = lbl_80561628;
    f32 delta = *arg1;
    f32 newValue = delta + (f32)obj[0x18];
    clampedValue = (clampedValue < newValue) ? clampedValue : newValue;
    clampedValue = (clampedValue > lbl_805615D4) ? clampedValue : lbl_805615D4;
    obj[0x18] = (u8)(s32)clampedValue;
}

extern s32 lbl_802F93E0[];
/* Returns the indexed entry from a 4-element table selected by the object's index field. */
s32 fn_8014931C(void *object) {
    S4_80149234 tableCopy;
    tableCopy = *(S4_80149234 *)lbl_802F93E0;
    return tableCopy.v[((s32 *)object)[1]];
}

void fn_8014935C(int *object) {
    /* Advance the object's table index (0..3) to the next entry, wrapping at 4. */
    object[1] = (object[1] + 1) % 4;
}

extern s32 lbl_802F93F0[];
/* Returns the indexed entry from a 4-element table selected by the object's index field. */
s32 fn_80149380(void *object) {
    S4_80149234 tableCopy;
    tableCopy = *(S4_80149234 *)lbl_802F93F0;
    return tableCopy.v[((s32 *)object)[1]];
}

#pragma cplusplus on
extern "C" s32 fn_801493C0(Dummy_80149274 *colorSource) {
    /* Return the source's packed color with the high bit cleared on each of the
     * three low (RGB) bytes, converting 8-bit channels to 7-bit. */
    return colorSource->d2() & 0xFF7F7F7F;
}
#pragma cplusplus off
/* Adjusts the byte field at offset 0x18 of an indexed sub-object by a delta and clamps it to [0, 255]. */
void fn_801493F8(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 clampedValue = lbl_80561628;
    f32 delta = *arg1;
    f32 newValue = delta + (f32)obj[0x18];
    clampedValue = (clampedValue < newValue) ? clampedValue : newValue;
    clampedValue = (clampedValue > lbl_805615D4) ? clampedValue : lbl_805615D4;
    obj[0x18] = (u8)(s32)clampedValue;
}

extern s32 lbl_802F9400[];
/* Return a table entry selected by the object's index field. */
s32 fn_80149468(void *obj) {
    S4_80149234 table;
    table = *(S4_80149234 *)lbl_802F9400;
    return table.v[((s32 *)obj)[1]];
}

s32 fn_801494A8(void) {
    /* Return the packed color 0xFF00FF00 - opaque green in 0xAARRGGBB form. */
    return 0xFF00FF00;
}

void fn_801494B4(void *unused, f32 *delta, f32 *vec) {
    /* Add the 2D vector *delta to elements 1 and 2 of the 3D vector *vec. */
    f32 y = vec[1] + delta[0];
    f32 z = vec[2] + delta[1];
    vec[1] = y;
    vec[2] = z;
}

extern unsigned long lbl_80559E94;
// Getter returning a pointer to the "Move" name string (lbl_80559E94).
unsigned long *fn_801494D8(void) { return &lbl_80559E94; }

int fn_801494E0(void) {
    /* Return the packed color 0xFF0000FF - opaque blue in 0xAARRGGBB form. */
    return 0xFF0000FF;
}

void fn_801494EC(void *arg0, float *arg1, float *arg2) {
    float f2 = arg2[1];
    float f1 = arg1[0];
    float f0 = arg2[4];
    float f4 = f2 + f1;
    float f2b = arg2[2];
    float f1b = f0 - f1;
    float f3 = arg1[1];
    float f0b = arg2[5];
    float f2c = f2b + f3;
    float f0c = f0b - f3;
    arg2[1] = f4;
    arg2[4] = f1b;
    arg2[2] = f2c;
    arg2[5] = f0c;
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
// Getter returning a pointer to the "Resize" name string (lbl_80559E9C).
unsigned long *fn_80149528(void) { return &lbl_80559E9C; }

int fn_80149530(void) {
    /* Return the packed color 0xFFC0D9D9 - opaque light pink in 0xAARRGGBB form. */
    return 0xFFC0D9D9;
}

void fn_8014953C(void *unused, float *delta, float *params) {
    /* Add delta[0] scaled by 0.01 to params[4] and clamp the result to [0.05, 5.0]. */
    float f2 = lbl_8056162C;
    float v = params[4] + f2 * *delta;
    f2 = lbl_80561630;
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_80561634) ? f2 : lbl_80561634;
    params[4] = f2;
}

/* Getter returning a pointer to the "Scale" name string (lbl_80559EA4). */
s32 *fn_80149580(void) {
    return &lbl_80559EA4;
}

#pragma push
#pragma scheduling invalid_target
/* Format the caller's time value (arriving in f1) as a level-3 time string
 * (hours:minutes:seconds.tenths) into a 0x20-byte buffer, then append it to the
 * text object through the printf-style text logger with a "%s" format. */
void fn_80149588(s32 textObj) {
    u8 timeStr[0x20];
    fn_80130980(timeStr, 0x20, 3);
    ((void (*)(s32, s32 *, void *, ...))fn_801474EC)(textObj, &lbl_80559EC4, timeStr);
}
#pragma pop
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

/* Evaluate the shared frame-counter-driven sine oscillation with period 0x40;
 * a tail call into fn_801495D4 (callers read its f32 result from f1). */
void fn_80149650(void) { fn_801495D4(0x40); }

u32 fn_80149658(s32 selfAddr, void *aArg, void *listArg, s32 unused) {
    u8 *self = (u8 *)selfAddr;
    u8 *a = (u8 *)aArg;
    u8 *list = (u8 *)listArg;
    u8 buf[0x32];
    u8 *tbl = lbl_8032D358;
    s32 id, s30, s26, s25;
    f32 f4, t;
    int i;
    u8 *p;
    u8 *dst1, *dst2, *srcp;
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
    {
        s32 x = *(s32 *)(a + 0x1C);
        fn_801345D8(self + 0x225, 0x14, x != 0 ? lbl_80559F04 : lbl_80559F08, x);
    }
    {
        s32 x = fn_801609C4(s25);
        if (x != -1) StrCopyN80149658(self + 0x81, __AXGetStackHead(x), 10);
        else StrCopyN80149658(self + 0x81, lbl_80559F0C, 10);
    }
    {
        s32 x = *(s32 *)(a + 0x30);
        if (x != -1) StrCopyN80149658(self + 0x8B, __AXGetStackHead(x), 10);
        else StrCopyN80149658(self + 0x8B, lbl_80559F0C, 10);
    }
    dst1 = self + 0x95;
    dst2 = self + 0x149;
    for (i = 0; i < *(s32 *)(list + 8); i++) {
        srcp = *(u8 **)(list + 4) + i * 0xF8;
        StrCopyN80149658(dst1, srcp + 4, 0x14);
        StrCopyN80149658(dst2, srcp + 0xA4, 0x14);
        dst1 += 0x14; dst2 += 0x14;
    }
    dst1 = self + i * 0x14 + 0x95;
    dst2 = self + i * 0x14 + 0x149;
    for (; (u32)i < 9; i++) {
        StrCopyN80149658(dst1, lbl_80559F0C, 0x14);
        StrCopyN80149658(dst2, lbl_80559F0C, 0x14);
        dst1 += 0x14; dst2 += 0x14;
    }
    fn_802AE168(*(s32 *)(self + 8));
    switch (*(s32 *)self) {
    case 0:
        fn_802E30C8(tbl + 0x70, tbl + 0xA0, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
        fn_802ADFF4(*(s32 *)(self + 8), *(s32 *)(self + 0x1C));
        if (s30 > 0) {
            p = *(u8 **)(self + 0x10);
            if (p != 0) { p[0x49] = 1; p[0x4B] = 0; p[0x4A] = 0; }
        } else {
            p = *(u8 **)(self + 0x14);
            if (p != 0) { p[0x49] = 1; p[0x4B] = 0; p[0x4A] = 0; }
        }
        *(s32 *)self = 1;
        break;
    case 1:
        if (*(s32 *)(self + 0x20) != 0 && *(f32 *)(self + 4) < lbl_80561648) {
            fn_802E30C8(tbl + 0x70, tbl + 0xC4, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
            *(f32 *)(self + 4) = lbl_8055E3C8;
        }
        if (*(s32 *)(self + 0x24) != 0) {
            fn_802E30C8(tbl + 0x70, tbl + 0xE8, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
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
            fn_802E30C8(tbl + 0x70, tbl + 0x130, lbl_8055E3C4, *(s32 *)(self + 0x20), *(s32 *)(self + 0x24), *(s32 *)(self + 0x28));
            fn_802AE0E0((void *)*(s32 *)(self + 8));
            *(s32 *)self = 4;
        }
        break;
    case 4:
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
void fn_80149D64(void *state, void *sound, s32 arg2) {
    /* Update a sound-debug readout: derive a phase index from the sound's frame, pick the
       frame/voice value (live rate when more than one player, otherwise a table lookup),
       flag a voice sub-object when that value changes, and store the extent and its band. */
    int index;
    f32 rate;
    int value;
    int frameIndex;
    void *obj;
    f32 extent;
    int *words = (int *)state;
    if (*(u8 *)((char *)state + 0x34) != 0) index = 0;
    else {
        f32 frame = *(f32 *)((char *)sound + 0x14);
        index = (int)(frame < lbl_80561648 ? frame - lbl_8056163C : lbl_8056163C + frame);
    }
    words[0] = index;
    if (fn_80179650() > 1) {
        rate = fn_80149F00(state, sound);
        value = *(int *)((char *)state + 0x10) == 0
            ? *(int *)((char *)state + 0x14) + (int)((f32)*(int *)((char *)state + 0x18) * rate)
            : 0;
        if (value != words[8]) {
            obj = *(void **)((char *)sound + 8);
            if (obj != 0 && *(void **)((char *)obj + 0x1258) != 0) {
                char *subObj = *(char **)((char *)obj + 0x1258);
                subObj[0x49] = 1;
                subObj[0x4B] = 0;
                subObj[0x4A] = 0;
            }
        }
        words[8] = value;
    } else {
        frameIndex = *(int *)((char *)state + 0x10);
        if (frameIndex < 0) goto no_frame;
        if (frameIndex >= *(int *)((char *)state + 0x0C)) goto no_frame;
        value = *(int *)(*(char **)((char *)state + 8) + frameIndex * 4);
        goto frame_ready;
    no_frame:
        value = 0;
    frame_ready:
        words[8] = value;
    }
    obj = *(void **)((char *)sound + 0x68);
    {
        f32 bottom, top, threshold, difference;
        top = *(f32 *)((char *)obj + 0x8DC);
        bottom = *(f32 *)((char *)obj + 0x8D4);
        threshold = lbl_80561648;
        difference = top - bottom;
        extent = threshold > difference ? threshold : difference;
    }
    *(int *)((char *)state + 0x24) = words[0] + words[8];
    *(int *)((char *)state + 0x1C) = (int)extent;
    *(int *)((char *)state + 0x30) = fn_801609C4(*(int *)((char *)state + 0x24));
}

#define SOUND_DBG_ZERO lbl_80561648 /* 0.0f, the shared sound-debug zero constant */
/* Returns a non-negative amount: the sound's lower extent (sub-object at +0x68,
 * float at +0x8D4) minus the state's position at +0x2C, clamped to zero; a
 * negative position also yields zero. */
f32 fn_80149F00(void *state, void *sound) {
    f32 pos;
    f32 bound;
    void *info;
    pos = *(f32 *)((u8 *)state + 0x2C);
    if (pos < SOUND_DBG_ZERO) return SOUND_DBG_ZERO;
    info = *(void **)((u8 *)sound + 0x68);
    bound = *(f32 *)((u8 *)info + 0x8D4);
    pos = bound - pos;
    if (SOUND_DBG_ZERO > pos) return SOUND_DBG_ZERO;
    return pos;
}

void fn_80149F2C(void *arg0, void *arg1, void *arg2) {
    u8 *base = (u8 *)arg0;
    void *list1 = arg1;
    void *list2 = arg2;
    double d68 = 0, d70 = 0, d78 = 0;
    double c50 = 0, c58 = 0, c60 = 0;
    int count;
    int r3fill;
    u8 *p68;
    u8 *r20;
    u8 *r30;
    f32 f0;
    p68 = *(u8 **)(base + 0x68);
    r20 = p68 + 0x8F4;
    count = 0;
    r3fill = 0;
    if (*(u8 *)(p68 + 0x8F4) != 0) {
        u8 *e = r20 + (*(s32 *)base) * 0x1C;
        if (*(u8 *)(e + 4) != 0) {
            r30 = e + 4;
            fn_801683F4(&d68, *(s32 *)base);
            c50 = d68; c58 = d70; c60 = d78;
            f0 = *(f32 *)(r30 + 8);
            if (lbl_80561648 < f0) *(f32 *)(r30 + 8) = f0 - lbl_80561650;
            f0 = *(f32 *)(r30 + 0xC);
            if (lbl_80561648 < f0) *(f32 *)(r30 + 0xC) = f0 - lbl_80561650;
            f0 = *(f32 *)(r30 + 0x10);
            if (lbl_80561648 < f0) *(f32 *)(r30 + 8 + 8) = f0 - lbl_80561650;
            f0 = *(f32 *)(r30 + 8 + 0xC);
            if (lbl_80561648 < f0) *(f32 *)(r30 + 8 + 0xC) = f0 - lbl_80561650;
            count = ((int *)&c50)[1];
            *(s32 *)(r30 + 4) += count * (*(s32 *)(r20 + 0xE8));
            if (count > 0) {
                int n = count;
                int idx = *(s32 *)(r30 + 0x18);
                while (n-- > 0) {
                    *(f32 *)(r30 + idx * 4 + 8) = lbl_80561654;
                    idx = (idx + 1) & 3;
                    *(s32 *)(r30 + 0x18) = idx;
                    r3fill++;
                }
            }
        }
    }
    {
        u8 it[0x20];
        u8 *r24 = *(u8 **)(base + 8);
        f32 f30 = lbl_80561648;
        fn_8014AF60(it, r24 + 0x124C, 0);
        while (fn_8014ADD0(it) != 0) {
            fn_8014AF58(it);
            fn_8014AEF0(it);
            fn_8014AF58(it);
            if (fn_8014AEE8(it) == 0) {
                fn_8014AF58(it);
                if (fn_8014AEE0(it) != 0) {
                    fn_8014AF58(it);
                    fn_8014AED8(it);
                    {
                        f32 v = fn_80141C9C(fn_8014AED8(it));
                        fn_8014AF58(it);
                        (void)v;
                        if (*(s32 *)(r24 + 0x1254) == 0) {
                            fn_8017960C(*(s32 *)(r24 + 0x1268));
                            fn_8014AEC8(it);
                            if (fn_80141F7C(fn_8014AEC8(it)) == 0) {
                                fn_8014AF58(it);
                                if (fn_8014AEC0(it) == 0xD) {
                                    *(u8 *)(r24 + 0x1260) = 0;
                                    *(s32 *)(r24 + 0x1254) = fn_8014AEB8(it);
                                    fn_8014AED8(it);
                                    if (fn_80144C90(fn_8014AED8(it)) == 5 && *(s32 *)(r24 + 0x125C) != 0) fn_80142B60((void *)1);
                                    fn_8014AE60(it);
                                    fn_8014AE54(*(void **)(r24 + 0x1254));
                                }
                            }
                        }
                    }
                } else {
                    fn_8014AE60(it);
                    fn_8014AE1C(r24 + 0x1244, (void *)fn_8014AEB8(it));
                }
            }
            fn_8014ADD8(it);
        }
        if (*(s32 *)(r24 + 0x1254) != 0) {
            fn_8014AD74(r24);
            if (*(u8 *)(r24 + 0x1260) == 0 && fn_8014AD6C(r24) > lbl_80561658) {
                *(u8 *)(r24 + 0x1260) = 1;
                if (*(s32 *)(r24 + 0x1258) != 0) fn_80142B60((void *)1);
            }
            if (fn_8014AD6C(r24) > lbl_8056165C) {
                f30 = (f32)fn_8014AD64(r24);
                fn_8014AE1C(r24 + 0x1244, *(void **)(r24 + 0x1254));
                *(s32 *)(r24 + 0x1254) = 0;
            }
        }
        *(f32 *)(base + 0x14) += f30 + (f32)count;
    }
    {
        f32 v;
        v = *(f32 *)(base + 0x40) - lbl_80561650;
        if (v < lbl_80561648) v = lbl_80561648;
        *(f32 *)(base + 0x40) = v;
        v = *(f32 *)(base + 0x44) - lbl_80561650;
        if (v < lbl_80561648) v = lbl_80561648;
        *(f32 *)(base + 0x44) = v;
        v = *(f32 *)(base + 0x48) - lbl_80561650;
        if (v < lbl_80561648) v = lbl_80561648;
        *(f32 *)(base + 0x48) = v;
        v = *(f32 *)(base + 0x4C) - lbl_80561650;
        if (v < lbl_80561648) v = lbl_80561648;
        *(f32 *)(base + 0x4C) = v;
        v = *(f32 *)(base + 0x50) - lbl_80561650;
        if (v < lbl_80561648) v = lbl_80561648;
        *(f32 *)(base + 0x50) = v;
    }
    (void)list1; (void)list2; (void)r3fill;
}

// Trivial callback stub; always returns 0 (false).
s32 fn_8014ACBC(void) { return 0; }

// Trivial callback stub; always returns 0 (false).
s32 fn_8014ACC4(void) { return 0; }

/* Does nothing: the third of the five trivial callbacks laid out back to back at
 * fn_8014ACBC .. fn_8014ACD4 (two that answer 0, then three empty ones), just
 * before fn_8014ACD8, an entry of this file's big interface table lbl_8032D970.
 * Nothing in the game's code calls it by name, so it only ever runs through the
 * pointer table its entry sits in. */
void fn_8014ACCC(void) {

}

/* Does nothing: one of the trivial callbacks in the run fn_8014ACBC ..
 * fn_8014ACD4 (two that answer 0 and three empty ones) that sits just before
 * fn_8014ACD8, an entry of this file's big interface table lbl_8032D970.
 * Nothing in the game's code names it, so it runs only through the pointer
 * table its entry sits in. */
void fn_8014ACD0(void) {

}

/* Does nothing: the last of the five trivial callbacks laid out back to back at
 * fn_8014ACBC .. fn_8014ACD4 (two that answer 0, then three empty ones). It sits
 * directly before fn_8014ACD8, slot 8 of this file's big interface table
 * lbl_8032D970, but is not itself an entry of that table; nothing calls it by
 * name, so it only ever runs through whichever pointer table holds it. */
void fn_8014ACD4(void) {

}

#pragma cplusplus on
extern "C" s32 fn_8014ACD8(void *arg0, s32 arg1) {
    /* Return 1 when the racer for arg1 is active (state != 3, flags == 0) and arg0's float at +0x8D4 is not greater than at +0x8DC. */
    class Obj {
    public:
        virtual void *v0();
        virtual void *v1();
        virtual void *v2();
        u8 pad[0x20];
        s32 state;
        u8 flags;
    };
    Obj *racer = (Obj *)fn_801B2ED0(arg1);
    racer = (Obj *)racer->v2();
    register s32 result = 0;
    register s32 isActive = 0;
    if (racer->state != 3 && racer->flags == 0)
        isActive = 1;
    if (isActive != 0) {
        s32 isHigher = *(f32 *)((u8 *)arg0 + 0x8D4) > *(f32 *)((u8 *)arg0 + 0x8DC);
        if (isHigher == 0)
            result = 1;
    }
    return result;
}
#pragma cplusplus reset
/* Returns the 32-bit integer field at offset 0x108 of the given object. */
s32 fn_8014AD64(void *object) { return *(s32 *)((u8 *)object + 0x108); }

/* Getter: return the float timer at +0x8 of the object (advanced by fn_8014AD74). */
f32 fn_8014AD6C(void *object) {
    return *(f32 *)((u8 *)object + 8);
}

extern s32 fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_8056164C;
extern f32 lbl_80561650;
extern void fn_8001DFF0(void);
extern u32 fn_80149658(s32, void *, void *, s32);
extern unsigned long lbl_80559E94;
void fn_8014AD74(void *obj) {
    /* Advance the float timer at +0x8 by a fixed rate, scaled by the frame step
     * when fn_80176A1C() reports state 2. */
    f32 step;
    s32 state = fn_80176A1C() - 2;
    if (((u32)__cntlzw((u32)state) >> 5) != 0) {
        step = fn_80176A2C();
    } else {
        step = lbl_8056164C;
    }
    *(f32 *)((u8 *)obj + 8) += lbl_80561650 * step;
}

s32 fn_8014ADD0(void *arg0) {
    return ((s32 *)arg0)[1];
}

/* Advance an iterator: promote next to current, load the following node/key, and report if current is valid. */
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

void fn_8014AE1C(void *list, void *newNode) {
    /* Append newNode to the tail of a doubly-linked list: link it after the old
     * last node, then update the header's last (and first when empty) pointers. */
    #define NODE_NEXT  (0x11C / 4)  /* s32 index of a node's next pointer */
    #define NODE_PREV  (0x120 / 4)  /* s32 index of a node's previous pointer */
    #define HEAD_FIRST 0            /* s32 index of the header's first-node pointer */
    #define HEAD_LAST  1            /* s32 index of the header's last-node pointer */
    volatile s32 *head = (volatile s32 *)list;
    volatile s32 *nodeLinks = (volatile s32 *)newNode;
    void *oldLast;
    s32 oldFirst;
    nodeLinks[NODE_NEXT] = 0;
    nodeLinks[NODE_PREV] = head[HEAD_LAST];
    oldLast = (void *)head[HEAD_LAST];
    if (oldLast != 0) {
        *(void **)((u8 *)oldLast + 0x11C) = newNode;
    }
    oldFirst = head[HEAD_FIRST];
    head[HEAD_LAST] = (s32)newNode;
    if (oldFirst == 0) {
        head[HEAD_FIRST] = (s32)newNode;
    }
    #undef HEAD_LAST
    #undef HEAD_FIRST
    #undef NODE_PREV
    #undef NODE_NEXT
}

extern f32 lbl_8055E3C8;
/* Stamp the node's timestamp field (+0x10) with the current game time. */
void fn_8014AE54(void *node) {
    *(f32 *)((u8 *)node + 0x10) = lbl_8055E3C8;
}

/* Removes a node from the doubly-linked list referenced by the iterator/unlink context. */
void fn_8014AE60(void *context) {
    struct Node8014AE60 { u8 pad[0x11C]; struct Node8014AE60 *prev; struct Node8014AE60 *next; };
    struct Head8014AE60 { struct Node8014AE60 *first; struct Node8014AE60 *last; };
    struct Head8014AE60 *list;
    struct Node8014AE60 *node;
    struct Node8014AE60 *nextNode;
    struct Node8014AE60 *prevNode;
    list = *(struct Head8014AE60 **)context;
    node = *((struct Node8014AE60 **)context + 1);
    nextNode = node->next;
    if (nextNode != 0) nextNode->prev = node->prev;
    else list->first = node->prev;
    prevNode = node->prev;
    if (prevNode != 0) prevNode->next = node->next;
    else list->last = node->next;
    node->next = 0;
    node->prev = 0;
}

/* Return the current node (the s32 word at +4) of this linked-list iterator. */
s32 fn_8014AEB8(void *it) { return ((s32 *)it)[1]; }

/* Return the s32 type/id field at offset 0x10C of this event object. */
s32 fn_8014AEC0(void *event) { return *(s32 *)((u8 *)event + 0x10C); }

/* Return the floating-point field at offset 0x2690 of this event object. */
f32 fn_8014AEC8(void *event) { return *(f32 *)((u8 *)event + 0x2690); }

void fn_8014AED0(void *event, f32 value) {
    /* Set the floating-point value at offset 0x104 of the event object (paired getter: fn_8014AED8). */
    ((f32 *)event)[0x41] = value;
}

f32 fn_8014AED8(void *event) {
    /* Read the floating-point value at offset 0x104 of the event object (paired setter: fn_8014AED0). */
    return ((f32 *)event)[0x41];
}

/* Returns the boolean flag at byte 5 of this object (initialized to 0 when the node is created). */
u8 fn_8014AEE0(void *obj) {
    return ((u8 *)obj)[5];
}

u8 fn_8014AEE8(void *object) {
    /* Return the "active" flag byte at offset +4 of the iterator/object. */
    return ((u8 *)object)[4];
}

/* If active, advance the timer at offset 0xC by lbl_80561650 scaled by fn_80176A2C() when fn_80176A1C() == 2, otherwise by lbl_8056164C. */
void fn_8014AEF0(void *object) {
    f32 deltaScale;
    if (*((u8 *)object + 4) != 0) {
        s32 state = fn_80176A1C() - 2;
        if (((u32)__cntlzw((u32)state) >> 5) != 0) {
            deltaScale = fn_80176A2C();
        } else {
            deltaScale = lbl_8056164C;
        }
        *(f32 *)((u8 *)object + 0xC) += lbl_80561650 * deltaScale;
    }
}

/* Return the current node (the word at +4) of this linked-list iterator;
 * a second getter identical to fn_8014AEB8. */
s32 fn_8014AF58(void *it) {
    return ((s32 *)it)[1];
}

/* Initializes an iterator over a container's first (useSecond==0) or second child list entry, caching fields at offsets 0x11C and 0x120 from the selected node. */
void fn_8014AF60(void *dst, void *container, s32 useSecond) {
    void *next;

    ((void **)dst)[0] = container;
    if (useSecond == 0) {
        next = ((void **)container)[0];
        ((void **)dst)[1] = next;
        if (next != 0) {
            *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)next + 0x11C);
            *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)next + 0x120);
            return;
        }
        *(s32 *)((u8 *)dst + 0xC) = 0;
        *(s32 *)((u8 *)dst + 8) = 0;
        return;
    }
    next = ((void **)container)[1];
    ((void **)dst)[1] = next;
    if (next != 0) {
        *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)next + 0x11C);
        *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)next + 0x120);
        return;
    }
    *(s32 *)((u8 *)dst + 0xC) = 0;
    *(s32 *)((u8 *)dst + 8) = 0;
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

/* Copy a 0x1C-byte source record (four ints, two floats, one int) into dst, reading each source field through a volatile pointer. */
void fn_8014C6F0(void *dst, void *srcRecord) {
    s32 word6;
    s32 word3, word2, word1, word0;
    f32 float1, float0;
    volatile s32 *srcWords = (volatile s32 *)srcRecord;
    volatile f32 *srcFloats = (volatile f32 *)((u8 *)srcRecord + 0x10);
    word0 = srcWords[0]; word1 = srcWords[1]; word2 = srcWords[2]; word3 = srcWords[3];
    float0 = srcFloats[0]; float1 = srcFloats[1]; word6 = srcWords[6];
    *(s32 *)dst = word0;
    *((s32 *)dst + 1) = word1;
    *((s32 *)dst + 2) = word2;
    *((s32 *)dst + 3) = word3;
    *(f32 *)((u8 *)dst + 0x10) = float0;
    *(f32 *)((u8 *)dst + 0x14) = float1;
    *((s32 *)dst + 6) = word6;
}

#pragma cplusplus on
extern "C" void fn_8014C72C(void *textEntry) {
    struct TextEntryObj {
        virtual void v0();
        virtual void v1();
    };
    /* Run the entry's virtual hook, then print the text line it returns. */
    ((TextEntryObj *)textEntry)->v1();
    fn_801476C4();
}
#pragma cplusplus reset
f32 fn_8014C75C(f32 *dst, const f32 *src) {
    /* Copy a 2D point (x, y) from src to dst and return its x component. */
    f32 x = src[0];
    f32 y = src[1];
    dst[0] = x;
    dst[1] = y;
    return x;
}

#pragma scheduling invalid_target
/* Linear interpolation between two 2D points: returns start + t * (end - start) as packed (x, y) floats. */
s64 fn_8014C770(const f32 *start, const f32 *end, f32 t) {
    /* Linearly interpolate between two 2D points and return the result as packed x,y floats. */
    f32 dy = end[1] - start[1];
    f32 dx = end[0] - start[0];
    f32 y = start[1] + t * dy;
    f32 x = start[0] + t * dx;
    union { struct { f32 x, y; } f; s64 bits; } out;
    out.f.y = y;
    out.f.x = x;
    return out.bits;
}
#pragma scheduling on
/* Copy a 0x28-byte 2D draw descriptor - the block fn_801476D8 draws a rectangle
 * from - field by field: its four leading words and the six floats that follow
 * them.  fn_8014C978 is the same copy.  Reading the source through a volatile
 * pointer is what keeps the compiler from folding the ten loads into an
 * lmw/stmw pair. */
void fn_8014C7B4(void *dst, void *srcObj) {
    typedef struct {
        s32 tag;    /* 0x00 which descriptor this is */
        s32 x;      /* 0x04 */
        s32 y;      /* 0x08 */
        s32 mode;   /* 0x0C how the rectangle is drawn */
        f32 width;  /* 0x10 */
        f32 height; /* 0x14 */
        f32 x0;     /* 0x18 one corner ... */
        f32 y0;     /* 0x1C ... */
        f32 x1;     /* 0x20 ... and the other */
        f32 y1;     /* 0x24 */
    } DrawDesc;

    s32 mode, y, x, tag;
    f32 y1, x1, y0, x0, height, width;
    volatile DrawDesc *src = (volatile DrawDesc *)srcObj;
    DrawDesc *out = (DrawDesc *)dst;

    tag = src->tag; x = src->x; y = src->y; mode = src->mode;
    width = src->width; height = src->height; x0 = src->x0; y0 = src->y0; x1 = src->x1; y1 = src->y1;
    out->tag = tag;
    out->x = x;
    out->y = y;
    out->mode = mode;
    out->width = width;
    out->height = height;
    out->x0 = x0;
    out->y0 = y0;
    out->x1 = x1;
    out->y1 = y1;
}

/* Return the alpha channel (highest byte) of a packed RGBA8888 color. */
unsigned int fn_8014C808(unsigned int color) { return color >> 24; }

/* Return the red channel (lowest byte) of a packed RGBA8888 color. */
unsigned char fn_8014C810(unsigned char color) { return color; }

/* Extract the green channel (byte at bits 8-15) of a packed RGBA8888 color. */
unsigned char fn_8014C818(unsigned int color) { return (unsigned char)(color >> 8); }

/* Extract the red channel (byte at bits 16-23) of a packed RGBA8888 color. */
unsigned char fn_8014C820(unsigned int color) { return (unsigned char)(color >> 16); }

/* Address helper: returns the field at offset +0x64 of `obj`, an alternate
 * HUD label string (sibling of fn_8014C830, which uses +0x14). */
s32 fn_8014C828(s32 obj) { return obj + 0x64; }

/* Address helper: returns a pointer to the field at offset +0x14 of `obj`
 * (e.g. the label string used by the HUD), sibling of fn_8014C828 (+0x64). */
s32 fn_8014C830(s32 obj) { return obj + 0x14; }

/* Return the timestamp (f32 at offset 0x10) stamped on this node by fn_8014AE54. */
f32 fn_8014C838(void *node) { return *(f32 *)((u8 *)node + 0x10); }

/* Return the current node (the s32 word at +4) of this linked-list iterator; zero when exhausted. */
s32 fn_8014C840(void *it) { return ((s32 *)it)[1]; }

/* Advance the iterator to its next node and return whether a current node remains. */
s32 fn_8014C848(void *iter) {
    void *next = ((void **)iter)[2];
    ((void **)iter)[1] = next;
    if (next != 0) {
        ((void **)iter)[2] = *(void **)((u8 *)next + 0x11C);
        ((s32 *)iter)[3] = *(s32 *)((u8 *)next + 0x120);
    } else {
        ((s32 *)iter)[3] = 0;
        ((void **)iter)[2] = 0;
    }
    return ((void **)iter)[1] != 0;
}

extern f32 lbl_80558DC4[];
extern float fabsf(float);
// Returns true when a and b are equal within the floating-point epsilon tolerance.
s32 fn_8014C88C(f32 a, f32 b) {
    f32 difference = a - b;
    f64 absDifference = __fabs((f64)difference);
    return (f32)absDifference <= lbl_80558DC4[0];
}

f32 fn_8014C8B4(f32 inMin, f32 inMax, f32 outMin, f32 outMax, f32 value) {
    /* Normalize value from [inMin, inMax] into [0, 1], clamp to that range,
     * then linearly interpolate between outMin and outMax. */
    f32 t = (value - inMin) / (inMax - inMin);
    t = (lbl_8056164C < t) ? lbl_8056164C : t;
    t = (t > lbl_80561648) ? t : lbl_80561648;
    return outMin + t * (outMax - outMin);
}

/* Clamp value to the inclusive range [min, max]. */
float fn_8014C8F8(float value, float min, float max) {
    float clamped = max;
    clamped = clamped < value ? clamped : value;
    clamped = clamped > min ? clamped : min;
    return clamped;
}

/* RealName: CopyTextEntry */
void fn_8014C920(void *dst, void *srcObj) {
    /* Copy a 0x20-byte on-screen text entry (TextEntry8014C920) field by field:
     * the name, x, y and justification, the float scale at +0x10, then the
     * font, colour and the string pointer at +0x1C.  x, y and the string are
     * moved as raw words, never converted.  Reading the source through
     * volatile pointers is what keeps the compiler from folding the eight
     * loads into an lmw/stmw pair. */
    volatile s32 *src = (volatile s32 *)srcObj;
    TextEntry8014C920 *out = (TextEntry8014C920 *)dst;
    const char *text;
    u32 color;
    s32 fontId;
    s32 justification;
    u32 yBits;
    u32 xBits;
    s32 id;
    f32 scale;
    id = src[0];
    xBits = src[1];
    yBits = src[2];
    justification = src[3];
    scale = *(volatile f32 *)((u8 *)srcObj + 0x10);
    fontId = src[5];
    color = src[6];
    text = (const char *)src[7];
    out->id = id;
    out->x = xBits;
    out->y = yBits;
    out->justification = justification;
    out->scale = scale;
    out->fontId = fontId;
    out->color = color;
    out->text = text;
}

/* Returns nonzero when the id stored at entryId matches id. */
int fn_8014C964(int *entryId, int id) {
    return *entryId == id;
}

/* Copy a 0x28-byte 2D draw descriptor (the block fn_801476D8 draws a rectangle
 * from): its four leading words and the six floats that follow them, one by one.
 * Reading the source through volatile pointers is what keeps the compiler from
 * folding the ten loads into an lmw/stmw pair. */
void fn_8014C978(void *dst, void *srcObj) {
    s32 mode, y, x, tag;
    f32 y1, x1, y0, x0, height, width;
    volatile s32 *src = (volatile s32 *)srcObj;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)srcObj + 0x10);
    tag = src[0]; x = src[1]; y = src[2]; mode = src[3];
    width = fsrc[0]; height = fsrc[1]; x0 = fsrc[2]; y0 = fsrc[3]; x1 = fsrc[4]; y1 = fsrc[5];
    *(s32 *)dst = tag;
    *((s32 *)dst + 1) = x;
    *((s32 *)dst + 2) = y;
    *((s32 *)dst + 3) = mode;
    *(f32 *)((u8 *)dst + 0x10) = width;
    *(f32 *)((u8 *)dst + 0x14) = height;
    *(f32 *)((u8 *)dst + 0x18) = x0;
    *(f32 *)((u8 *)dst + 0x1c) = y0;
    *(f32 *)((u8 *)dst + 0x20) = x1;
    *(f32 *)((u8 *)dst + 0x24) = y1;
}

/* Return the current node pointer (the word at +4) of a linked-list iterator.
 * The caller uses it as the event object read by fn_8014AED8 / fn_8014AEC0. */
int fn_8014C9CC(void *it) {
    return ((int *)it)[1];
}

/* Copy a linked node's pair of values (at +0x11C/+0x120) into a record: store
 * the container and the selected next node (arg2 == 0 -> container->next0, else
 * container->next1), and copy that node's values, or clear them if there is no
 * next node. */
void fn_8014C9D4(void *dst, void *container, s32 useSecond) {
    void *next;

    ((void **)dst)[0] = container;
    if (useSecond == 0) {
        next = ((void **)container)[0];
        ((void **)dst)[1] = next;
        if (next != 0) {
            *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)next + 0x11C);
            *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)next + 0x120);
            return;
        }
        *(s32 *)((u8 *)dst + 0xC) = 0;
        *(s32 *)((u8 *)dst + 8) = 0;
        return;
    }
    next = ((void **)container)[1];
    ((void **)dst)[1] = next;
    if (next != 0) {
        *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)next + 0x11C);
        *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)next + 0x120);
        return;
    }
    *(s32 *)((u8 *)dst + 0xC) = 0;
    *(s32 *)((u8 *)dst + 8) = 0;
}

extern f32 lbl_80561648, lbl_8056163C;
extern s32 fn_801312EC(void *, void *);
extern s32 fn_8026B0C0(s32);
extern u8 lbl_8042FCB4[], lbl_8042FCC0[], lbl_8042FCCC[], lbl_8042FCD8[], lbl_8042FCE4[], lbl_8042FCF0[], lbl_8042FCFC[];
extern u8 lbl_8055E25C, lbl_8055E25D, lbl_8055E25E, lbl_8055E25F, lbl_8055E260, lbl_8055E261, lbl_8055E262;
extern f32 lbl_80561680, lbl_80561684, lbl_8056168C, lbl_80561690, lbl_80561694, lbl_80561698, lbl_8056169C;
extern f64 lbl_805616B0;
extern u8 lbl_802F9410[];
extern s32 lbl_802F9458[];
typedef struct { s32 a, b, c; } LabelNames_8014CA48;
extern char lbl_80559F10[8];
extern f32 fn_80144C80(f32, f32, f32);
extern void fn_801476D8(void *, ...);
extern void fn_80147EE0(void *, f32);
extern s32 fn_80144C68(u8, u8, u8, u8);
extern void fn_80147230(void *, void *, ...);
extern void fn_80232928(s32);
extern void fn_80232930(void);
extern void fn_801460F4(void *);
extern void fn_8001DF08(s32 p1, s32 p2);
extern void fn_8014784C(s32 p1, void *p2, void *p3, s32 p4);
extern void fn_801479A8(void *p1, s32 p2, void *p3, ...);
extern int sprintf(void *p1, void *p2, s32 p3);
#pragma push
#pragma dont_inline on
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_8014CA48(s32 a0, s32 a1, s32 a2) {
    typedef struct { s32 tag; f32 x; f32 y; s32 mode; f32 w; f32 h; f32 x0, y0, x1, y1; } Rect;
    typedef struct { s32 id; s32 x; s32 y; s32 just; f32 scale; s32 font; u32 color; char *text; } Text;
    typedef struct { int id; s32 num; s32 pad; } Slot;
    typedef struct { char s0[4]; } Strings;
    u8 *o = (u8 *)a0;
    Layout_8014CA48 *mgr = (Layout_8014CA48 *)a1;
    u8 *strings = lbl_8032D358;
    f32 f = *(f32 *)(o + 0x18);
    s32 bcVal;
    u8 *p8;
    s32 frameInt;
    s32 result;
    u32 k;
    s32 i;
    s32 count;
    Slot *slot;
    f32 f24, f25, f26, f27, f28, f29, f30;
    Rect r210, r1E8, r1C0, r198, r170, r148, r120;
    char name100[0x20];
    Text tE0, tC0, tA0, t80;
    char name60[0x20], name40[0x20];
    LabelNames_8014CA48 names;
    u8 it[0x10];
    s64 lerp18, lerp10;
    u8 shown[6];

    frameInt = (s32)((f < lbl_80561648) ? f - lbl_8056163C : lbl_8056163C + f);
    bcVal = *(s32 *)(o + 0xbc);
    p8 = *(u8 **)(o + 8);
    mgr->load(strings + 0x164);
    if ((s8)lbl_8055E25C == 0) { fn_801312EC(lbl_8042FCB4, strings + 0x178); lbl_8055E25C = 1; }
    if ((s8)lbl_8055E25D == 0) { fn_801312EC(lbl_8042FCC0, strings + 0x184); lbl_8055E25D = 1; }
    if ((s8)lbl_8055E25E == 0) { fn_801312EC(lbl_8042FCCC, strings + 0x194); lbl_8055E25E = 1; }
    if ((s8)lbl_8055E25F == 0) { fn_801312EC(lbl_8042FCD8, strings + 0x1a0); lbl_8055E25F = 1; }
    if ((s8)lbl_8055E260 == 0) { fn_801312EC(lbl_8042FCE4, strings + 0x1b0); lbl_8055E260 = 1; }
    if ((s8)lbl_8055E261 == 0) { fn_801312EC(lbl_8042FCF0, strings + 0x1c8); lbl_8055E261 = 1; }
    if ((s8)lbl_8055E262 == 0) { fn_801312EC(lbl_8042FCFC, strings + 0x1d4); lbl_8055E262 = 1; }
    result = fn_8026B0C0(a2);

    for (k = 0; k < 6; k++) shown[k] = 0;
    fn_8014C9D4(it, p8 + 0x124C, 0);
    f24 = lbl_8056164C;
    f26 = lbl_8056163C;
    f25 = lbl_80561680;

    while (fn_8014C840(it) != 0) {
        if (fn_8014AED8((void *)fn_8014C9CC(it)) > f26) {
            slot = (Slot *)lbl_802F9410;
            for (k = 0; k < 6; k++, slot++) {
                Rect *src;
                fn_801345D8(name40, 0x20, lbl_80559F10, slot->num);
                src = (Rect *)mgr->rect(name40);
                if (src != 0) {
                    fn_8014C978(&r120, src);
                    r120.x = r120.x - r120.w * f26 - f25 * r120.w * f26;
                    if (fn_8014C964(&((Slot *)lbl_802F9410)[k].id, fn_8014AEC0((void *)fn_8014C9CC(it))) != 0 && shown[k] == 0) {
                        Text *t;
                        fn_801345D8(name60, 0x20, strings + 0x1e0, slot->num);
                        t = (Text *)mgr->text(name60);
                        if (t != 0) {
                            fn_8014C920(&t80, t);
                            t80.color = (result != 0) ? 0x70FFFF00 : 0xFFFFFF00;
                            fn_801476C4(&t80);
                        }
                        for (f28 = lbl_80561648; f28 <= fn_8014AED8((void *)fn_8014C9CC(it)); f28 += f24) {
                            f27 = fn_8014C8F8(fn_8014AED8((void *)fn_8014C9CC(it)) - f28, lbl_80561648, lbl_8056164C);
                            fn_8014C978(&r148, &r120);
                            fn_80147EE0(&r148, fn_8014C8B4(lbl_80561648, lbl_8056164C, lbl_80561674, lbl_8056164C, f27));
                            r148.mode = 2;
                            ((s32 (*)(s32, s32, f32))fn_80147C50)(0xFFFFFF, 0x7FFFFFFF, f27);
                            if (fn_8014C88C(f27, lbl_8056164C) != 0) {
                                u32 c = ((Text *)mgr->text(strings + 0x1ec))->color;
                                if (result != 0) c = (c & 0xFFFFFF) | 0x70000000;
                                ((void (*)(void *, u32, s32))fn_801476D8)(&r148, c, bcVal);
                                r120.x = r120.x + r120.w;
                            }
                        }
                        shown[k] = 1;
                    }
                }
            }
        }
        fn_8014C848(it);
    }

    p8 = *(u8 **)(p8 + 0x1254);
    if (p8 != 0) {
        f25 = fn_801E7E18();
        f24 = (fn_80176A1C() == 2) ? fn_80176A2C() : lbl_8056164C;
        f25 = (f25 - fn_8014C838(p8)) * f24;
        f27 = fn_8014C8B4(lbl_8056163C, lbl_80561684, lbl_80561648, lbl_8056164C, f25);
        f30 = fn_8014C8B4(lbl_80561684, lbl_8056165C, lbl_80561648, lbl_8056164C, f25);
        count = fn_80144C90(fn_8014AED8(p8));
        if (fn_8014AD64(p8) > 0) {
            Rect *t;
            f24 = fn_8014C8F8(f27, lbl_80561648, lbl_8056164C);
            f28 = fn_8014C8B4(lbl_80561648, lbl_8056164C, lbl_8056164C, lbl_80561688, f24);
            names = *(LabelNames_8014CA48 *)lbl_802F9458;
            names.c = (count >= 5) ? fn_8014C830((s32)p8) : fn_8014C828((s32)p8);
            if (count >= 5) {
                s32 col;
                f24 = fn_8014C8B4(lbl_80561648, lbl_80561684, lbl_80561648, lbl_8056164C, f25);
                col = fn_80144C68(0xFF, 0xC1, 0, 0);
                fn_80232928(fn_80144C68(0xFF, 0xFF, 0xFF, 0xFF));
                if (f24 < lbl_8056168C) {
                    Text *tx;
                    f24 = fn_8014C8B4(lbl_80561648, lbl_8056168C, lbl_80561648, lbl_8056164C, f24);
                    tx = (Text *)mgr->text(((Strings *)strings)->s0);
                    if (tx != 0) {
                        fn_8014C920(&tA0, tx);
                        tA0.scale = fn_8014C8B4(lbl_80561648, lbl_8056164C, lbl_80561674 * tA0.scale, tA0.scale, f24);
                        f24 = fn_80144C80(lbl_80561648, lbl_8056164C, f24);
                        tA0.color = fn_80144C68((u8)(lbl_80561690 * f24),
                            ((u8 (*)(s32))fn_8014C820)(col), ((u8 (*)(s32))fn_8014C818)(col), ((u8 (*)(s32))fn_8014C810)(col));
                        fn_80147230(&tA0, &lbl_80559EC4, fn_8014C830((s32)p8));
                    }
                } else {
                    Text *ta, *tb;
                    f24 = fn_8014C8B4(lbl_80561694, lbl_8056164C, lbl_80561648, lbl_8056164C, f24);
                    ta = (Text *)mgr->text((void *)names.a);
                    tb = (Text *)mgr->text((void *)names.b);
                    if (ta != 0 && tb != 0) {
                        fn_8014C920(&tC0, ta);
                        fn_8014C920(&tE0, tb);
                        tC0.color = fn_80144C68(fn_8014C808(tC0.color),
                            ((u8 (*)(s32))fn_8014C820)(col), ((u8 (*)(s32))fn_8014C818)(col), ((u8 (*)(s32))fn_8014C810)(col));
                        tE0.color = fn_80144C68(fn_8014C808(tE0.color),
                            ((u8 (*)(s32))fn_8014C820)(col), ((u8 (*)(s32))fn_8014C818)(col), ((u8 (*)(s32))fn_8014C810)(col));
                        fn_801479A8(&tC0, (s32)&tE0, &lbl_80559EC4, names.c, f24);
                    }
                }
                fn_80232930();
            } else {
                Text *ta, *tb;
                ta = (Text *)mgr->text((void *)names.a);
                tb = (Text *)mgr->text((void *)names.b);
                if (ta != 0 && tb != 0)
                    fn_801479A8(ta, (s32)tb, &lbl_80559EC4, names.c, f24);
            }
            t = (Rect *)mgr->rect(strings + 0x1fc);
            if (t != 0) {
                fn_801460F4(&r170);
                if (fn_80141F7C(f30) != 0) {
                    Rect *found;
                    f24 = fn_8014C8B4(lbl_80561648, lbl_80561658, lbl_80561648, lbl_8056164C, f25);
                    found = 0;
                    for (k = 0; k < 6; k++) {
                        if (fn_8014C964(&((Slot *)lbl_802F9410)[k].id, fn_8014AEC0(p8)) != 0) {
                            ((int (*)(char *, const char *, ...))sprintf)(name100, lbl_80559F10, ((Slot *)lbl_802F9410)[k].num);
                            found = (Rect *)mgr->rect(name100);
                            break;
                        }
                    }
                    fn_8014C7B4(&r170, t);
                    if (found != 0) {
                        fn_8014C978(&r198, found);
                        r198.x = r198.x - r198.w * lbl_8056163C - lbl_80561680 * r198.w * lbl_8056163C;
                        r170.w = f28 * fn_80144C80(r198.w, r170.w, f24);
                        r170.h = f28 * fn_80144C80(r198.h, r170.h, f24);
                        r170.y = r170.y - lbl_8056163C * r170.h;
                        r170.x = r170.x - lbl_8056163C * r170.w * (f32)count;
                        lerp10 = fn_8014C770(&r198.x, &r170.x, f24);
                        fn_8014C75C(&r170.x, (f32 *)&lerp10);
                    } else {
                        r170.w = r170.w * f28;
                        r170.h = r170.h * f28;
                        r170.y = r170.y - lbl_8056163C * r170.h;
                        r170.x = r170.x - lbl_8056163C * r170.w * (f32)count;
                    }
                } else {
                    Rect *found2 = (Rect *)mgr->rect(strings + 0x20c);
                    if (found2 != 0) {
                        f24 = fn_8014C8B4(lbl_80561648, lbl_8056164C, lbl_80561688, lbl_8056164C, f30);
                        fn_8014C978(&r1C0, t);
                        fn_8014C7B4(&r170, found2);
                        r170.w = f24 * fn_80144C80(r1C0.w, r170.w, f30);
                        r170.h = f24 * fn_80144C80(r1C0.h, r170.h, f30);
                        r1C0.y = r1C0.y - lbl_8056163C * r170.h;
                        r1C0.x = r1C0.x - r170.w * (f32)count * lbl_8056163C;
                        lerp18 = fn_8014C770(&r1C0.x, &r170.x, f30);
                        fn_8014C75C(&r170.x, (f32 *)&lerp18);
                    }
                }
                fn_8014C978(&r1E8, &r170);
                {
                    u32 c = ((Text *)mgr->text(strings + 0x1ec))->color;
                    f29 = lbl_8056164C;
                    f26 = f29 - f30;
                    f28 = lbl_8056169C;
                    f25 = lbl_8056163C;
                    for (i = 0; i < count; i++) {
                        ((void (*)(void *, u32, s32))fn_801476D8)(&r1E8, c, bcVal);
                        if (count >= 5) {
                            f32 alpha;
                            s32 col2;
                            f24 = fn_8014C8B4(lbl_80561648, lbl_80561698, lbl_80561648, lbl_8056164C, f27);
                            fn_8014C978(&r210, &r1E8);
                            fn_80147EE0(&r210, f29 + f28 * f24);
                            alpha = (f29 - f24) * (f32)(u8)fn_8014C808(c);
                            col2 = fn_80144C68((u8)alpha,
                                ((u8 (*)(u32))fn_8014C820)(c), ((u8 (*)(u32))fn_8014C818)(c), ((u8 (*)(u32))fn_8014C810)(c));
                            r210.x = r210.x + f25 * ((f32)(i - 2) * (r210.w - r1E8.w));
                            ((void (*)(void *, u32, s32))fn_801476D8)(&r210, col2, bcVal);
                        }
                        r1E8.x = r1E8.x + r1E8.w * f26;
                    }
                }
            }
        }
    }

    fn_8014784C((s32)mgr, strings + 0x21c, strings + 0x228, 6);
    if (((TObj80154618 *)*(void **)(o + 0x68))->f6(*(s32 *)o) != 0)
        fn_8001DF08(*(s32 *)o, frameInt);
    else
        fn_8001DF08(*(s32 *)o, *(s32 *)(o + 0x90));
}
#pragma cplusplus reset
#pragma pop
// If the racer's out-of-time flag is set, display the "out of time" HUD overlay.
void fn_8014D6EC(void *racer) {
    if (((u8 *)racer)[0xA0] == 0) {
        return;
    }
    fn_8001DFF0();
}

#pragma cplusplus on
extern "C" void fn_8014D700(void *context, s32 param) {
    /* Finalize a subobject via vcall (slot 16), then forward to fn_80149658 with a table value when enabled. */
    s32 index;
    s32 tableValue;
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
    temp_r5 = *(void **)((u8 *)context + 0xC);
    *(s32 *)((u8 *)temp_r5 + 8) = 0;
    temp = *(void **)((u8 *)context + 0x10);
    ((TObjD1Call *)temp)->f16(*(void **)((u8 *)context + 0xC));

    temp_r5 = *(void **)((u8 *)context + 0x68);
    index = *(s32 *)context;
    void *table = (u8 *)temp_r5 + 0x8F4;
    if (*(u8 *)table != 0) {
        tableValue = *(s32 *)((u8 *)table + index * 0x1C + 8);
    } else {
        tableValue = 0;
    }
    fn_80149658(param, (void *)((u8 *)context + 0x6C), *(void **)((u8 *)context + 0xC), tableValue);
}

#pragma push
#pragma opt_propagation off
extern "C" void fn_8014D794(void *arg0, void *arg1) {
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
        if (*(f32 *)((u8 *)arg0 + 0x64) >= lbl_80561648) {
            return;
        }
    }
}
#pragma pop
extern char *lbl_80559F30;
extern char *lbl_80559F38;
#pragma push
#pragma cplusplus on
extern "C" void fn_8014D840(void *__restrict arg0, void *arg1) {
    struct Dummy {
        virtual void v0();
        virtual void m(const char *);
    };
    u8 *manager;
    s32 i;
    s32 best;
    s32 *entry;
    s32 count;
    manager = *(u8 **)((u8 *)arg0 + 0x68);
    best = -1;
    entry = (s32 *)(manager + 0x9E4);
    count = *(s32 *)(manager + 0xFE4);
    i = 0;
    while (count > 0) {
        if (best < 0) {
            best = i;
        } else {
            u8 *current = manager + best * 0xC0;
            s32 value = *(s32 *)(current + 0xA74);
            s32 threshold = entry[0x90 / 4];
            if (value < threshold) {
                best = i;
            } else if (value == threshold) {
                s32 tieValue = *(s32 *)(current + 0xA54);
                s32 tieThreshold = entry[0x70 / 4];
                if (tieValue > tieThreshold) {
                    best = i;
                }
            }
        }
        entry += 0xC0 / 4;
        i++;
        count--;
    }
    if (*(s32 *)arg0 == best) {
        ((Dummy *)arg1)->m((const char *)&lbl_80559F30);
        fn_801476C4();
    } else {
        ((Dummy *)arg1)->m((const char *)&lbl_80559F38);
        fn_801476C4();
    }
}
#pragma pop

#pragma cplusplus on
extern "C" void fn_8014D918(void *arg0, s32 arg1, s32 arg2) {
    struct Acc {
        virtual void d0(); virtual void d1(); virtual void d2();
        virtual void *get(void *);
    };
    struct Pair { s32 a, b; };
    struct Rec { s32 w0; Pair p; s32 w3; f32 f4, f5; s32 w6; };
    Rec *b, *a;
    void *obj;
    char storage[0x64];
    f32 t, time, rate, x;
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
            f32 y = lbl_8056164C - x;
            f32 w = x * x;
            f32 h = lbl_8056164C - y * y;
            x = lbl_80561670 * time - lbl_8056164C;
            y = lbl_8056164C - x;
            w = x * x;
            h = lbl_8056164C - y * y;
            v = *a;
            pv[1] = pa[1] + h * (pb[1] - pa[1]);
            pv[2] = pa[2] + w * (pb[2] - pa[2]);
            pv[4] = pa[4] + w * (pb[4] - pa[4]);
            pv[5] = pa[5] + w * (pb[5] - pa[5]);
            v.w6 = ((s32 (*)(s32, s32, f32))fn_80147C50)(a->w6, b->w6, x);
        }
        fn_80147940((void *)arg1, &v, strs + 0x27C, 0);
    }
}
#pragma cplusplus off
/* Latches the active/replay flag, refreshes the sub-object at +0x6C from the owner's +0x68 state, then applies a clamped time offset to the object at +0x00. */
void fn_8014DB94(void *owner) {
#define ownerFlagsA0      0xA0
#define ownerSubObject6C  0x6C
#define ownerState68      0x68
#define stateTime8D4      0x8D4
#define stateTime8DC      0x8DC
    f32 f0;
    f32 f2;
    void *state;
    *(u8 *)((u8 *)owner + ownerFlagsA0) = 1;
    fn_80149CEC((u8 *)owner + ownerSubObject6C, owner);
    state = *(void **)((u8 *)owner + ownerState68);
    f2 = lbl_80561648;
    f0 = *(f32 *)((u8 *)state + stateTime8DC) - *(f32 *)((u8 *)state + stateTime8D4);
    if (f2 > f0) f2 = f2; else f2 = f0;
    fn_801CB648(*(void **)owner, 0, *(f32 *)((u8 *)state + stateTime8DC) - f2);
#undef stateTime8DC
#undef stateTime8D4
#undef ownerState68
#undef ownerSubObject6C
#undef ownerFlagsA0
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
    float total;
    Lists *list;
    Node *node;
    Node *next;
    Node *pending;
    float diff;
    int a, b;
    void *obj;
    ((Callback *)*(void **)((char *)arg0 + 0x10))->call();
    list = *(Lists **)((char *)arg0 + 8);
    pending = list->pending;
    total = lbl_80561648;
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
            if (node->prev) node->prev->next = node->next; else list->active = node->next;
            if (node->next) node->next->prev = node->prev; else list->activeLast = node->prev;
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

/* Empty: the do-nothing destructor that CodeWarrior emits just ahead of
 * fn_8014DE50, the constructor that installs this file's interface table
 * lbl_8032D970 (and its three sub-tables at +0x100, +0x11C and +0x130) into a
 * new object. Nothing calls it by name; it runs only as the destroy entry of a
 * table, and freeing the object needs no work of its own. */
void fn_8014DE4C(void) {

}
  // test

extern s32 fn_801284F8(s32, void *);
extern s32 fn_80145E70(void *);
extern void *fn_8014E1D0(void *, s32);
extern void *fn_8014E3CC(void *, s32);
extern void *fn_8014E4BC(void *);
extern void *fn_8014E154(void *, s32);
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

extern void fn_80128670(long);
#pragma cplusplus on
extern "C" void fn_80128670(s32);
extern "C" void fn_80128668(void *);
extern "C" void *fn_8014E154(void *object, s32 shouldFree) {
    /* One of the 8 per-car race entries the betarace manager builds at
     * +0x9E4 (fn_8014DE50).  fn_8014E1D0 loads its place-bonus item list
     * (place_bonus.val) into items/itemCount with fn_8012850C. */
    struct RaceEntry {
        char pad[0x6C];
        void *field_6C;
        char pad2[4];
        void **items;
        s32 itemCount;
    };
    struct RaceEntry *entry = (struct RaceEntry *)object;
    if (object != 0) {
        /* Drop the bonus item list the entry owns (the two address tests are
         * the original's; only the pointer at 0x74 decides anything). */
        if (&entry->field_6C != 0 && &entry->items != 0 && entry->items != 0) {
            fn_80128670((s32)entry->items);
            entry->items = 0;
            entry->itemCount = 0;
        }
        if (shouldFree > 0) {
            fn_80128668(object);
        }
    }
    return object;
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw off
/* Initialize one race place-bonus entry: load its item list and config values
 * from the place-bonus data table, or fall back to an empty one-item list. */
extern "C" void *fn_8014E1D0(void *entryPtr, s32 unused) {
    struct PlaceBonusEntry {
        char pad[0x74];
        void **items;
        s32 count;
        s32 selectedIndex;
        s32 configValueA;
        s32 configValueB;
    };
    register u8 *strings = lbl_8032D358;
    register PlaceBonusEntry *entry = (PlaceBonusEntry *)entryPtr;
    s32 i;
    s32 lastIndex;
    Iter_8014E1D0 *iter;
    s32 found;
    void *table;
    char name[0x64];
    s32 offset;
    void **items;

    entry->items = 0;
    entry->count = 0;
    entry->selectedIndex = -1;
    entry->configValueA = 1;
    entry->configValueB = 1;
    table = fn_80131808(strings + 0x4c8);
    if (table != 0) {
        found = 0;
        iter = (Iter_8014E1D0 *)((Iter_8014E1D0 *)table)->open((char *)(strings + 0x4d8));
        if (iter != 0) {
            found = 1;
            entry->count = 1;
            for (;;) {
                ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(name, 0x64, (char *)(strings + 0x4e4), entry->count);
                if (iter->has(name) == 0)
                    break;
                entry->count++;
            }
            entry->items = (void **)fn_8012850C((entry->count + 1) * 4, strings + 0x4f0);
            for (i = 0, offset = 0; i < (lastIndex = entry->count - 1); i++, offset += 4) {
                ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(name, 0x64, (char *)(strings + 0x4e4), i + 1);
                *(void **)((u8 *)entry->items + offset) = iter->next(name);
            }
            entry->items[lastIndex] = 0;
            entry->configValueA = iter->get((char *)(strings + 0x500), entry->configValueA);
            entry->configValueB = iter->get((char *)(strings + 0x50c), entry->configValueB);
        }
        if (found)
            ((void (*)(char *, ...))fn_802E30C8)((char *)(strings + 0x518));
        fn_80131818(table);
    }
    if (entry->items == 0) {
        ((void (*)(char *, ...))fn_802E30C8)((char *)(strings + 0x54c));
        items = (void **)fn_8012850C(4, strings + 0x4f0);
        entry->items = items;
        *items = 0;
        entry->count = 1;
    }
    return entryPtr;
}
#pragma use_lmw_stmw reset
#pragma cplusplus off

#pragma cplusplus on
extern "C" void *fn_8014E3CC(void *object, s32 shouldFree) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    /* Destroys owned subobjects at offsets 0x8, 0x10, 0x14, 0x18, then frees the
       object itself when shouldFree > 0. */
    VObj *child;
    if (object != NULL) {
        child = *(VObj **)((char *)object + 8);
        if (child != NULL) {
            fn_802ADE60((void **)child, 1);
            *(VObj **)((char *)object + 8) = NULL;
        }
        child = *(VObj **)((char *)object + 0x10);
        if (child != NULL) {
            if (child != NULL) child->d0(1);
            *(VObj **)((char *)object + 0x10) = NULL;
        }
        child = *(VObj **)((char *)object + 0x14);
        if (child != NULL) {
            if (child != NULL) child->d0(1);
            *(VObj **)((char *)object + 0x14) = NULL;
        }
        child = *(VObj **)((char *)object + 0x18);
        if (child != NULL) {
            if (child != NULL) child->d0(1);
            *(VObj **)((char *)object + 0x18) = NULL;
        }
        if (shouldFree > 0) fn_80128668(object);
    }
    return object;
}
#pragma cplusplus off
extern void *memset(void *, s32, s32);
#pragma cplusplus on
extern "C" void *memset(void *, s32, s32);
#pragma cplusplus off
void *fn_8014E4BC(void *arg0) {
    u8 *base = (u8*)arg0;
    s32 zero = 0;
    u8 *p;
    u8 *end;
    *(u32*)(base + 8) = zero; *(u32*)(base + 0x10) = zero;
    *(u32*)(base + 0x14) = zero; *(u32*)(base + 0x18) = zero;
    memset(base + 0x2C, 0x7A, 3); base[0x2F] = 0;
    memset(base + 0x40, 0x7A, 3); base[0x43] = 0;
    memset(base + 0x45, 0x7A, 3); base[0x48] = 0;
    memset(base + 0x59, 0x7A, 3); base[0x5C] = 0;
    memset(base + 0x6D, 0x7A, 3); base[0x70] = 0;
    memset(base + 0x81, 0x7A, 3); base[0x84] = 0;
    memset(base + 0x8B, 0x7A, 3); base[0x8E] = 0;
    p = base + 0x95; end = base + 0x149;
    do { memset(p, 0x7A, 3); p[3] = 0; p += 0x14; } while (p < end);
    p = end; end = base + 0x1FD;
    do { memset(p, 0x7A, 3); p[3] = 0; p += 0x14; } while (p < end);
    memset(end, 0x7A, 3); base[0x200] = 0;
    memset(base + 0x225, 0x7A, 3); base[0x228] = 0;
    return arg0;
}
extern s32 fn_801DF074(s32, s32);
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_8014E61C(s32 arg0, s32 arg1, f32 arg2) {
    extern void *lbl_8055E268;
    extern s32 fn_801DF074(s32, s32);
    struct Entry8014E61C {
        u8 pad[0xC0];
    };
    struct Mgr8014E61C {
        u8 pad[0x9E4];
        Entry8014E61C entries[8];
    };
    class V8014E61C {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8();
        virtual void call(void *, s32, f32);
    };
    u8 *entry;
    f32 value;
    void *other;
    V8014E61C *obj;
    if (lbl_8055E268 != 0) {
        entry = (u8 *)&((Mgr8014E61C *)lbl_8055E268)->entries[arg0];
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
            obj = *(V8014E61C **)(entry + 0x10);
            obj->call(other, arg1, value);
        }
    }
}
#pragma cplusplus reset
#pragma processor reset
/* Empty stub callback in the bonus-entry group: does nothing. */
void fn_8014E704(void) {

}

extern void fn_80128670(s32);
extern void *lbl_8055E268;
extern s32 lbl_80559F40;
#pragma cplusplus on
extern "C" s32 fn_8014E708(s32 index) {
    struct BonusEntryObj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual s32 v12();
    };
    u8 *manager = (u8 *)lbl_8055E268;
    /* Query the v12() value of the bonus-entry object for this index (0 if no table). */
    if (manager != 0) {
        BonusEntryObj *entryObj = *(BonusEntryObj **)(manager + index * 0xC0 + 0x9F4);
        return entryObj->v12();
    }
    return 0;
}
#pragma cplusplus reset
/* Trivial stub callback in the bonus-entry group; always returns 0 (false). */
s32 fn_8014E738(void) { return 0; }

#pragma processor 750
void fn_8014E740(void *arg0, f32 arg1) {
    /* Allocate a 0x14-byte puddle entry, copy xyz from arg0 and store arg1, then append it to manager+0x220. */
    void *manager;
    void *puddleEntry;
    s32 count;
    void **entryList;
    f32 posX;
    f32 posY;
    f32 posZ;
    u32 zero;
    manager = lbl_8055E268;
    if (manager != 0) {
        puddleEntry = (void *)fn_801284F8(0x14, &lbl_80559F40);
        if (puddleEntry != 0) {
            posX = *(f32 *)((u8 *)arg0 + 0);
            zero = 0;
            posY = *(f32 *)((u8 *)arg0 + 4);
            *(f32 *)((u8 *)puddleEntry + 0) = posX;
            posZ = *(f32 *)((u8 *)arg0 + 8);
            *(f32 *)((u8 *)puddleEntry + 4) = posY;
            *(f32 *)((u8 *)puddleEntry + 8) = posZ;
            *(f32 *)((u8 *)puddleEntry + 0xC) = arg1;
            *((u8 *)puddleEntry + 0x10) = zero;
        }
        count = *(s32 *)((u8 *)manager + 0x224);
        entryList = *(void ***)((u8 *)manager + 0x220);
        *(s32 *)((u8 *)manager + 0x224) = count + 1;
        entryList[count] = puddleEntry;
    }
}
/* Trivial stub callback between the puddle-entry adder and the score lookup; does nothing. */
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
    /* Look up a per-entry score/value: try the file's direct getter, else load a resource by formatted path and compute a rounded rate. */
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

    char pathBuffer[0x104];
    void *file;
    char *fileText;
    void *entryName;
    void *resource;
    void *resourceEntry;
    s32 fileCountInt;
    f32 value;
    f32 fileCount;
    f32 scaled;
    f32 rate;

    fn_8012E81C(lbl_8032D358 + 0x5A4);
    file = fn_8001285C((void *)arg0);
    fileText = fn_80012820(*(s32 *)((u8 *)file + 4));
    entryName = fn_80205268(lbl_8032D358 + 0x5B8, arg1, arg0);
    register u8 *strings = lbl_8032D358;

    if (((MainInterface *)*(void **)((u8 *)file + 0x20))->check(entryName) == 0) {
        value = ((MainInterface *)*(void **)((u8 *)file + 0x20))->evaluate(
            (char *)(strings + 0x344), lbl_805616CC);
        entryName = ((MainInterface *)*(void **)((u8 *)file + 0x20))->lookup(
            (char *)(strings + 0x5D0), &lbl_80559F48);

        fn_8012E81C(strings + 0x5A4);
        ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(
            pathBuffer, 0x104, (char *)(strings + 0x5DC), entryName, fileText + 8);
        if (fn_8012C33C(pathBuffer) == 0) {
            ((s32 (*)(char *, s32, char *, ...))fn_801345D8)(
                pathBuffer, 0x104, (char *)(strings + 0x5E8), entryName, fileText + 8);
        }

        resource = fn_80131810(pathBuffer);
        if (resource != 0) {
            resourceEntry = ((ResourceInterface *)resource)->next((char *)&lbl_80559F4C);
            value = ((ResourceInterface *)resourceEntry)->value(
                (char *)(strings + 0x5F4));
            fn_80131818(resource);

            fileCountInt = *(s32 *)((u8 *)file + 0xC);
            fileCount = (f32)fileCountInt;
            scaled = value * fileCount;
            rate = lbl_80559EB0 * scaled;
            rate = rate / lbl_805616D0;
            value = lbl_805616D0 * (f32)ceil((double)rate);
        } else {
            ((void (*)(char *, ...))fn_802E30C8)(
                (char *)(strings + 0x600), pathBuffer);
        }
        return value;
    }

    return ((MainInterface *)*(void **)((u8 *)file + 0x20))->finish(entryName);
}

extern s32 lbl_8055E258, lbl_80559ED0, lbl_80559ED4, lbl_80559ED8, lbl_80559EDC, lbl_80559ECC, lbl_8055E254;
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_802328D4(s32);
extern "C" void fn_802CAC54(s32);
extern "C" void fn_802C6CF8(s32);
/* destructor body of an item in the 0x14 array; last one releases shared resources */
static inline void DestroyItem8014E9C4(char *item) {
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
}
/* delete of an item: destructor body, then free */
static inline void DeleteItem8014E9C4(char *item) {
    if (item) {
        DestroyItem8014E9C4(item);
        fn_80128668(item);
    }
}
extern "C" void fn_802CAC54(s32);
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_80167838(void), fn_8016A68C(void), fn_80167EEC(void);
extern "C" void fn_801777D0(void *), fn_801D05B4(void *), fn_801D0824(void *);
/* pointer array member (data, count, capacity) */
struct PtrArray8014E9C4 { void **data; s32 count; s32 capacity; };
static inline void FreeAll8014E9C4(PtrArray8014E9C4 *a) {
    int i;
    for (i = 0; i < a->count; i++)
        fn_80128668(a->data[i]);
}
static inline void DeleteAll8014E9C4(PtrArray8014E9C4 *a) {
    int i;
    for (i = 0; i < a->count; i++)
        DeleteItem8014E9C4((char *)a->data[i]);
}
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_8014E9C4(char *p, s32 arg1) {
    char *entry;
    int j;
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
        for (j=0; j<*(s32 *)(p+0xfe4); entry+=0xc0,j++) {
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
        {
            int i;
            for (i=0; i<*(s32 *)(p+0x18); i++)
                DeleteItem8014E9C4((*(char ***)(p+0x14))[i]);
            for (i=0; i<*(s32 *)(p+0x224); i++)
                fn_80128668((*(void ***)(p+0x220))[i]);
            for (i=0; i<*(s32 *)(p+0x330); i++)
                fn_80128668((*(void ***)(p+0x32c))[i]);
            for (i=0; i<*(s32 *)(p+0x3bc); i++)
                fn_80128668((*(void ***)(p+0x3b8))[i]);
        }
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
/* Destructor: restores vtable, destroys owned objects at +0x125C/+0x1258, cleans the array at +4, and optionally deletes self when deleteFlag > 0. */
extern "C" void *fn_8014EF00(void *object, s32 deleteFlag) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    if (object != 0) {
        VObj *firstOwned = *(VObj **)((char *)object + 0x125C);
        *(void **)object = lbl_8032E190;
        if (firstOwned != 0) {
            if (firstOwned != 0) firstOwned->d0(1);
        }
        VObj *secondOwned = *(VObj **)((char *)object + 0x1258);
        if (secondOwned != 0) {
            if (secondOwned != 0) secondOwned->d0(1);
        }
        fn_8002F634((char *)object + 4, (void *)fn_8014EFC0, 0x124, 0x10);
        if (deleteFlag > 0) {
            fn_80128668(object);
        }
    }
    return object;
}
#pragma cplusplus reset

s32 fn_8014EFC0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

extern s32 fn_8014F088(s32, s32);
void *fn_8014F000(void *object, int deleteFlag) {
    /* Destructor-like cleanup for an object with an embedded array at +0x10:
     * destroy array elements via fn_8002F634(..., fn_8014F088, 0xF8, 0x10),
     * clear the tracked fields at +4/+8/+C, and optionally free the object. */
    struct Local {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
    };
    struct Local *self = (struct Local *)object;
    if (object != 0) {
        if (&self->field_4 != 0) {
            fn_8002F634((char *)self + 0x10, (void *)fn_8014F088, 0xF8, 0x10);
            if (&self->field_4 != 0) {
                self->field_4 = 0;
                self->field_8 = 0;
                self->field_C = 0;
            }
        }
        if (deleteFlag > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}

s32 fn_8014F088(s32 object, s32 deleteFlag) {
#define MemFreeObject fn_80128668
    /* CodeWarrior array-element deleting-destructor helper: free the element with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        MemFreeObject((void *)object);
    }
    return object;
#undef MemFreeObject
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
#pragma optimization_level 3
#pragma opt_pointer_aliasing on
s32 *fn_801500F8(void *vec, s32 *__restrict pValue) {
    /* Append a value to the growable s32 array at vec (+0 data pointer, +4 count): bump the count, store the value, return the new slot. */
    s32 newIndex;
    s32 index = ((s32 *)vec)[1];
    s32 *data = *(s32 **)vec;
    newIndex = index + 1;
    ((s32 *)vec)[1] = newIndex;
    data[index] = *pValue;
    return &data[index];
}
#pragma cplusplus on
extern "C" void *fn_8015011C(void *arg0, void *arg1) {
    class Entry {
    public:
        virtual void d0();
        virtual void d1();
        virtual s32 m8();
        virtual s32 has(void *);
        virtual s32 m14(void *);
        virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10();
        virtual void d11();
        virtual s32 m30(void *, s32);
        virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual s32 m50(void *, void *);
        virtual s32 m54(void *, void *);
    };
    extern s32 fn_802CAC28(void *, s32);
    extern s32 fn_801D4888();
    extern u8 lbl_8032D358[];
    extern u8 lbl_80559F98[];
    extern u8 lbl_80559FA0[];
    ((s32 *)arg0)[8] = fn_802CAC28(lbl_8032D358 + 0xB28, 0);
    ((s32 *)arg0)[0xD0/4] = ((Entry *)arg1)->m8();
    ((Entry *)arg1)->m8();
    ((s32 *)arg0)[3] = fn_801D4888();
    if (((Entry *)arg1)->has(lbl_80559F98) != 0) {
        ((s32 *)arg0)[0x38/4] = ((Entry *)arg1)->m54(lbl_80559F98, lbl_8032D358 + 0xB38);
    } else {
        ((s32 *)arg0)[0x38/4] = 2;
    }
    ((u8 *)arg0)[0xCC] = (u8)((Entry *)arg1)->m30(lbl_80559FA0, 1);
    ((s32 *)arg0)[0x38/4] = 3;
    return arg0;
}
#pragma cplusplus off

#pragma pop
s32 fn_80150AD8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80150B18(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80150B58(void *obj, s32 value) {
    // Store a value in the s32 field at offset 0x20 of an object.
    ((s32 *)obj)[8] = value;
}

s32 fn_8014F088(s32 arg0, s32 arg1);
s32 fn_8014F088(s32, s32);
#pragma push
#pragma scheduling off
#pragma peephole off
/* Betamaster reset (vtable slot +0x10 of the "betamaster" object whose
 * vtable is lbl_8032D970, built by fn_8014DE50): clears the per-car coin
 * records when the coin_file feature is present, resets the growcoin /
 * MechaSimpleArray tables, stops the "prerace.sfx" sound and clears the
 * flag saying that sound has been started. */
void fn_80150B60(void *object) {
    /* One of the game's Sound objects (created by fn_80207848, pool tag
     * "Sound"); its update fn_80206824 stops the sound when +0x4A is set. */
    struct Sound {
        char pad_0[0x4A];
        u8 stopRequested; /* +0x4A */
        char pad_4B[1];
        u8 stopWhenDone;  /* +0x4C */
    };
    /* The bet/race manager, 0xFE8 bytes allocated as "betamaster". */
    struct BetaMaster {
        char pad_0[0x44C];
        struct Sound *preraceSfx; /* +0x44C: "prerace.sfx" */
        u8 preraceSfxStarted;     /* +0x450 */
        char pad_451[0x8F4 - 0x451];
        u8 coinEnabled;           /* +0x8F4: set when coin_file exists */
        char pad_8F5[3];
        u8 coinRecords[0xE0];     /* +0x8F8: 8 x 0x1C, one record per car */
    };
    struct BetaMaster *master = (struct BetaMaster *)object;
    struct Sound *preraceSfx;

    fn_8016783C(object);
    if (master->coinEnabled != 0) {
        memset(master->coinRecords, 0, sizeof(master->coinRecords));
        fn_801688FC(1);
        fn_80168020();
    }
    fn_8016A0D4();
    preraceSfx = master->preraceSfx;
    if (preraceSfx != 0) {
        preraceSfx->stopRequested = 1;
        preraceSfx->stopWhenDone = 0;
    }
    master->preraceSfxStarted = 0;
}

#pragma pop
#pragma push
extern f32 lbl_80561638, lbl_805616E0, lbl_805616E4, lbl_805616E8, lbl_805616B8;
extern f32 lbl_805616F8, lbl_80559EC8;
extern f64 lbl_805616F0;
extern double sin(double), cos(double), floor(double);
extern f32 fn_801B306C(void);
extern s32 fn_801B2F2C(s32), fn_80179630(s32), fn_8016A30C(s32);
extern void fn_80168328(void), fn_80167840(void), fn_80167684(f32);
extern void fn_801688B4(s32);
extern void *fn_801E87A8(void);
typedef void (*SetXf80150BDC)(void *, f32 *, f32 *, f32 *);
typedef s32 (*GetFn80150BDC)(void *);

/* Place an effect object at its stored position with an identity rotation
 * (vtable slot +0x28 of the object's model). */
static inline void fn_80150BDC_PlaceEffect(void *e, f32 one, f32 zero) {
    f32 m[12], scale[3], trans[3];
    m[0]=one; m[1]=zero; m[2]=zero; m[3]=zero; m[4]=one; m[5]=zero; m[6]=zero; m[7]=zero; m[8]=one; m[9]=zero; m[10]=zero; m[11]=zero;
    m[9]=*(f32 *)((char *)e + 8); m[10]=*(f32 *)((char *)e + 0xC); m[11]=*(f32 *)((char *)e + 0x10);
    scale[0]=zero; scale[1]=zero; scale[2]=zero; trans[0]=zero; trans[1]=zero; trans[2]=zero;
    (*(SetXf80150BDC *)(*(char **)*(void **)e + 0x28))(*(void **)e, m, trans, scale);
}
#pragma dont_inline on
void fn_80150BDC(void *arg0) {
    char *b = (char *)arg0;
    f32 f29 = lbl_80561650, f30 = lbl_8056164C, f31 = lbl_80561648;
    f32 f28 = lbl_805616E0, f27 = lbl_80561638;
    s32 r30, r31, played;
    void *r25, *r23, *r26;
    f32 f0, f1, f2, f25, f26;
    s32 tmpv;

    for (r30 = 0, r31 = 0; r30 < *(s32 *)(b + 0x18); r30++, r31 += 4) {
        r25 = *(void **)(*(char **)(b + 0x14) + r31);
        r23 = *(void **)((char *)r25 + 0xB8);
        if (r23 != 0) {
            f26 = (f32)sin(f27 * (f32)fn_8002EFB4(lbl_80559EC8 * lbl_8055E3C8, lbl_805616A0)) * f28 + *(f32 *)((char *)r25 + 0xBC);
            *(f32 *)((char *)r23 + 0x24) = *(f32 *)r25;
            *(f32 *)((char *)r23 + 0x28) = *(f32 *)((char *)r25 + 4);
            *(f32 *)((char *)r23 + 0x2C) = *(f32 *)((char *)r25 + 8);
            r26 = *(void **)((char *)r25 + 0xB8);
            f25 = (f32)cos(f26);
            f1 = (f32)sin(f26);
            *(f32 *)((char *)r26 + 0) = f25;
            *(f32 *)((char *)r26 + 4) = f31;
            *(f32 *)((char *)r26 + 8) = -f1;
            *(f32 *)((char *)r26 + 0xC) = f31;
            *(f32 *)((char *)r26 + 0x10) = f30;
            *(f32 *)((char *)r26 + 0x14) = f31;
            *(f32 *)((char *)r26 + 0x18) = f1;
            *(f32 *)((char *)r26 + 0x1C) = f31;
            *(f32 *)((char *)r26 + 0x20) = f25;
        }
        if (fn_801D48F8(*(s32 *)((char *)r25 + *(s32 *)((char *)r25 + 0x14) * 4 + 0xC)) != 0 ||
            fn_801D4904(*(s32 *)((char *)r25 + *(s32 *)((char *)r25 + 0x14) * 4 + 0xC)) != 0) {
            f0 = *(f32 *)((char *)r25 + 0x34) - f29;
            if (f31 > f0) f0 = f31;
            *(f32 *)((char *)r25 + 0x34) = f0;
        }
        if (fn_801D4900(*(s32 *)((char *)r25 + *(s32 *)((char *)r25 + 0x14) * 4 + 0xC)) == 0) {
            f0 = *(f32 *)((char *)r25 + 0x34);
            *(f32 *)((char *)r25 + 0x34) = (f0 > f29) ? f0 : f29;
        }
        if (*(s32 *)((char *)r25 + 0x38) == 4) {
            f0 = *(f32 *)((char *)r25 + 0x18) - f29;
            *(f32 *)((char *)r25 + 0x18) = f0;
            if (f0 < f31) {
                *(s32 *)((char *)r25 + 0x14) = 1 - *(s32 *)((char *)r25 + 0x14);
                *(f32 *)((char *)r25 + 0x18) = *(f32 *)((char *)r25 + 0x1C);
            }
        }
    }

    played = 0;
    f29 = fn_801B306C();
    if (*(u8 *)(b + 0x450) == 0 && f29 < lbl_805616E4) {
        *(u8 *)(b + 0x450) = 1;
        if (*(void **)(b + 0x44C) != 0 && fn_80161C38() == 0 && fn_80179650() == 1 && fn_80009C84() == 0) {
            void *p = *(void **)(b + 0x44C);
            *(s8 *)((char *)p + 0x49) = 1;
            *(s8 *)((char *)p + 0x4B) = 0;
            *(s8 *)((char *)p + 0x4A) = 0;
        }
    }
    if (*(u8 *)(b + 0x8E4) == 0 && f29 <= lbl_80561648 && fn_80161C38() == 0) {
        void *p = *(void **)(b + 0x8E8);
        *(u8 *)(b + 0x8E4) = 1;
        if (p != 0) {
            *(s8 *)((char *)p + 0x4A) = 1;
            *(s8 *)((char *)p + 0x4C) = 0;
        }
    }
    if (*(u8 *)(b + 0x8F4) != 0) fn_80168328();

    {
        char *r28 = b + 0x9E4, *r31p = b;
        s32 r29, r22;
        f32 ff30 = lbl_80561648, ff29 = lbl_8056166C;
        for (r29 = 0; r29 < lbl_8055E4D0; r29++, r28 += 0xC0, r31p += 0x1C) {
            fn_80149F2C(r28, b + 0x14, b + 0x220);
            if (fn_801B2F2C(r29) == 0) {
                s32 over = *(f32 *)(b + 0x8D4) > *(f32 *)(b + 0x8DC);
                if (over) {
                    if (*(u8 *)(r28 + 0xA0) == 0) fn_8014DB94(r28);
                } else if (*(s32 *)((char *)fn_8017960C(r29) + 0x1F0) == 0x50) {
                    played = 1;
                    if (fn_801609C4((s32)*(f32 *)(r28 + 0x14)) == 0 && *(u8 *)(b + 0x8F4) != 0) {
                        fn_801688B4(1);
                        *(s8 *)(r31p + 0x8F8) = 1;
                    }
                    if (fn_800167F4() == 1) { fn_8017960C(r29); fn_80167840(); }
                    tmpv = fn_8016A30C(r29);
                    if (tmpv > 0) fn_8014E61C(r29, 5, (f32)tmpv);
                }
            } else if (*(s32 *)((char *)fn_8017960C(r29) + 0x1F0) == 0x50) {
                char *r24 = b + 0x454, *r23p = b;
                for (r22 = 0; r22 < fn_80179650(); r22++, r24 += 0x240, r23p += 0x240) {
                    if (r29 == fn_80179630(r22)) {
                        if (*(u8 *)(r28 + 0xA0) == 0) fn_8014D700(r28, (s32)r24);
                        if (*(s32 *)(r23p + 0x454) == 2 && fn_80179650() > 1) {
                            s32 flag;
                            s32 lt = *(f32 *)(b + 0x8DC) - *(f32 *)(b + 0x8D4) < *(f32 *)(b + 0x8D8);
                            if (lt) {
                                flag = 0;
                            } else {
                                *(f32 *)(b + 0x8DC) = *(f32 *)(b + 0x8D4) + *(f32 *)(b + 0x8D8);
                                flag = 1;
                            }
                            if (flag != 0) {
                                if (*(f32 *)(r28 + 0x98) < ff30) *(f32 *)(r28 + 0x98) = *(f32 *)(b + 0x8D4);
                            } else {
                                f1 = *(f32 *)(b + 0x8DC) - *(f32 *)(b + 0x8D4);
                                if (ff30 > f1) f1 = ff30;
                                f0 = *(f32 *)(b + 0x8DC) - ((f32)floor(f1) - ff29);
                                if (*(f32 *)(r28 + 0x98) < ff30) *(f32 *)(r28 + 0x98) = f0;
                            }
                        }
                    }
                }
            }
        }
    }

    f31 = lbl_8056164C; f30 = lbl_80561648; f29 = lbl_805616E8;
    {
        s32 r22, r29;
        for (r22 = 0, r29 = 0; r22 < *(s32 *)(b + 0x330); r22++, r29 += 4) {
            void *e = *(void **)(*(char **)(b + 0x32C) + r29);
            if (*(u8 *)((char *)e + 4) != 0) {
                f32 m[12], w[3], q[3];
                m[0]=f31; m[1]=f30; m[2]=f30; m[3]=f30; m[4]=f31; m[5]=f30; m[6]=f30; m[7]=f30; m[8]=f31; m[9]=f30; m[10]=f30; m[11]=f30;
                m[9]=*(f32 *)((char *)e + 8); m[10]=*(f32 *)((char *)e + 0xC); m[11]=*(f32 *)((char *)e + 0x10);
                f25 = (f32)fn_8002EFB4(f29 * lbl_8055E3C8, lbl_805616F0);
                f26 = (f32)cos(f25); f1 = (f32)sin(f25);
                m[0]=f26; m[1]=f30; m[3]=f30; m[2]=-f1; m[4]=f31; m[5]=f30; m[6]=f1; m[7]=f30; m[8]=f26;
                if (*(u32 *)((char *)fn_801E87A8() + 0x10) & 2) { m[0]=-m[0]; m[1]=-m[1]; m[2]=-m[2]; }
                q[0]=f30; q[1]=f30; q[2]=f30; w[0]=f30; w[1]=f30; w[2]=f30;
                { void **vp = *(void ***)((char *)e + 0); void *vt = *vp; ((SetXf80150BDC)*(void **)((char *)vt + 0x28))(vp, m, w, q); }
            } else if (((GetFn80150BDC)*(void **)((char *)*(void **)((char *)e + 0x18) + 8))(e) != 0 && lbl_8055E3C8 > *(f32 *)((char *)e + 0x14)) {
                f32 m[12], w[3], q[3];
                *(u8 *)((char *)e + 4) = 1;
                m[0]=f31; m[1]=f30; m[2]=f30; m[3]=f30; m[4]=f31; m[5]=f30; m[6]=f30; m[7]=f30; m[8]=f31; m[9]=f30; m[10]=f30; m[11]=f30;
                m[9]=*(f32 *)((char *)e + 8); m[10]=*(f32 *)((char *)e + 0xC); m[11]=*(f32 *)((char *)e + 0x10);
                q[0]=f30; q[1]=f30; q[2]=f30; w[0]=f30; w[1]=f30; w[2]=f30;
                { void **vp = *(void ***)((char *)e + 0); void *vt = *vp; ((SetXf80150BDC)*(void **)((char *)vt + 0x28))(vp, m, w, q); }
            }
        }
    }

    f29 = lbl_8056164C; f30 = lbl_80561648; f31 = lbl_805616E8;
    {
        s32 r22, r29;
        for (r22 = 0, r29 = 0; r22 < *(s32 *)(b + 0x3BC); r22++, r29 += 4) {
            void *e = *(void **)(*(char **)(b + 0x3B8) + r29);
            if (*(u8 *)((char *)e + 4) != 0) {
                f32 m[12], w[3], q[3];
                m[0]=f29; m[1]=f30; m[2]=f30; m[3]=f30; m[4]=f29; m[5]=f30; m[6]=f30; m[7]=f30; m[8]=f29; m[9]=f30; m[10]=f30; m[11]=f30;
                m[9]=*(f32 *)((char *)e + 8); m[10]=*(f32 *)((char *)e + 0xC); m[11]=*(f32 *)((char *)e + 0x10);
                f25 = (f32)fn_8002EFB4(f31 * lbl_8055E3C8, lbl_805616F0);
                f26 = (f32)cos(f25); f1 = (f32)sin(f25);
                m[0]=f26; m[1]=f30; m[3]=f30; m[2]=-f1; m[4]=f29; m[5]=f30; m[6]=f1; m[7]=f30; m[8]=f26;
                if (*(u32 *)((char *)fn_801E87A8() + 0x10) & 2) { m[0]=-m[0]; m[1]=-m[1]; m[2]=-m[2]; }
                q[0]=f30; q[1]=f30; q[2]=f30; w[0]=f30; w[1]=f30; w[2]=f30;
                { void **vp = *(void ***)((char *)e + 0); void *vt = *vp; ((SetXf80150BDC)*(void **)((char *)vt + 0x28))(vp, m, w, q); }
            } else if (((GetFn80150BDC)*(void **)((char *)*(void **)((char *)e + 0x18) + 8))(e) != 0 && lbl_8055E3C8 > *(f32 *)((char *)e + 0x14)) {
                f32 m[12], w[3], q[3];
                *(u8 *)((char *)e + 4) = 1;
                m[0]=f29; m[1]=f30; m[2]=f30; m[3]=f30; m[4]=f29; m[5]=f30; m[6]=f30; m[7]=f30; m[8]=f29; m[9]=f30; m[10]=f30; m[11]=f30;
                m[9]=*(f32 *)((char *)e + 8); m[10]=*(f32 *)((char *)e + 0xC); m[11]=*(f32 *)((char *)e + 0x10);
                q[0]=f30; q[1]=f30; q[2]=f30; w[0]=f30; w[1]=f30; w[2]=f30;
                { void **vp = *(void ***)((char *)e + 0); void *vt = *vp; ((SetXf80150BDC)*(void **)((char *)vt + 0x28))(vp, m, w, q); }
            }
        }
    }

    f1 = *(f32 *)(b + 0x10);
    if (f1 > lbl_80561648 && lbl_8055E3C8 > f1) {
        *(u8 *)(b + 0x8E4) = 1;
        *(f32 *)(b + 0x10) = lbl_805616B8;
        *(f32 *)(b + 0x8D4) = *(f32 *)(b + 0x8DC) - lbl_805616F8;
    }
    if (played == 0) {
        void *p = *(void **)(b + 0x8E8);
        *(u8 *)(b + 0x8E4) = 0;
        if (p != 0) { *(s8 *)((char *)p + 0x4A) = 1; *(s8 *)((char *)p + 0x4C) = 0; }
    }
    if (*(u8 *)(b + 0x8E4) != 0) {
        void *p, *r4;
        s32 done;
        f0 = *(f32 *)(b + 0x8D4) + lbl_80561650;
        *(f32 *)(b + 0x8D4) = f0;
        done = f0 > *(f32 *)(b + 0x8DC);
        if (done) {
            p = *(void **)(b + 0x8E8);
            if (p != 0) { *(s8 *)((char *)p + 0x4A) = 1; *(s8 *)((char *)p + 0x4C) = 0; }
            r4 = *(void **)(b + 0x8EC);
            if (r4 != 0 && *(u8 *)(b + 0x8F0) == 0) {
                *(s8 *)((char *)r4 + 0x49) = 1; *(s8 *)((char *)r4 + 0x4B) = 0; *(s8 *)((char *)r4 + 0x4A) = 0;
                *(u8 *)(b + 0x8F0) = 1;
            }
        } else {
            p = *(void **)(b + 0x8E8);
            if (p != 0) {
                s32 near = *(f32 *)(b + 0x8DC) - f0 < *(f32 *)(b + 0x8D8);
                if (near && *(u8 *)((char *)p + 0x19) == 0) {
                    *(s8 *)((char *)p + 0x4A) = 0; *(s8 *)((char *)p + 0x4B) = 1; *(s8 *)((char *)p + 0x49) = 1;
                }
            }
        }
    }
    if (played != 0) {
        f0 = *(f32 *)(b + 0x8DC) - *(f32 *)(b + 0x8D4);
        fn_80167684(lbl_80561648 > f0 ? lbl_80561648 : f0);
    }
}
/* Constant-zero stub: always reports false / no value (likely a registered callback). */
s32 fn_80151604(void) { return 0; }

/* Return a status flag word: 0x5608 when the current race state is active,
   otherwise 0x160B or 0x564B depending on the stored value, with bit 6 masked off. */
s32 fn_8015160C(void) {
#define raceStateActive fn_80161C38
#define raceStateValue  fn_80179650
    if (raceStateActive() != 0) {
        return 0x5608;
    }
    return (raceStateValue() > 1 ? 0x160B : 0x564B) & 0xFFFFFFBF;
#undef raceStateActive
#undef raceStateValue
}

#pragma cplusplus on
extern "C" void fn_80151654(void *entityPool, void *msgParam, int messageId) {
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
    /* For message 0x3EB only: take the entity index stored at +0x1EC of the message
       parameter, index into the pool of 0xC0-byte records, follow the object pointer
       at +0x9E4, and invoke that object's v7 callback. */
    if (messageId != 0x3EB) return;
    index = *(int *)((char *)msgParam + 0x1EC);
    obj = (char *)entityPool + index * 0xC0;
    obj = (char *)obj + 0x9E4;
    if (obj == 0) return;
    ((Obj *)*(void **)((char *)obj + 0x10))->v7();
}
#pragma cplusplus reset
/* No-op handler in this message-dispatch group (reached through the handler table): does nothing. */
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
    u8 *entry;
    u8 *owner;
    u8 *cur;
    u8 *next;
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
        owner = *(u8 **)(entry + 8);
        cur = *(u8 **)(owner + 0x124C);
        next = cur != 0 ? *(u8 **)(cur + 0x11C) : 0;
        {
            u8 *link;
            while (cur != 0) {
                if (*(u8 *)(cur + 4) != 0) {
                    link = *(u8 **)(cur + 0x120);
                    if (link != 0)
                        *(u8 **)(link + 0x11C) = *(u8 **)(cur + 0x11C);
                    else
                        *(u8 **)(owner + 0x124C) = *(u8 **)(cur + 0x11C);
                    link = *(u8 **)(cur + 0x11C);
                    if (link != 0)
                        *(u8 **)(link + 0x120) = *(u8 **)(cur + 0x120);
                    else
                        *(u8 **)(owner + 0x1250) = *(u8 **)(cur + 0x120);
                    *(u8 **)(cur + 0x120) = 0;
                    *(u8 **)(cur + 0x11C) = 0;
                    *(u8 **)(cur + 0x120) = *(u8 **)(owner + 0x1248);
                    link = *(u8 **)(owner + 0x1248);
                    if (link != 0)
                        *(u8 **)(link + 0x11C) = cur;
                    *(u8 **)(owner + 0x1248) = cur;
                    if (*(u8 **)(owner + 0x1244) == 0)
                        *(u8 **)(owner + 0x1244) = cur;
                }
                cur = next;
                next = cur != 0 ? *(u8 **)(cur + 0x11C) : 0;
            }
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
extern "C" void fn_8015180C(void *ctx, void *objA, void *objB, void *unused, void *vec) {
    // Handle collision response between two objects based on priority.
    f32 mag = PSVECMag(vec);
    s32 callA = 1;
    s32 callB = 1;
    if (*(s32 *)((u8 *)objA + 0x1F0) == 0x50 && *(s32 *)((u8 *)objB + 0x1F0) == 0x50) {
        f32 valueB = *(f32 *)((u8 *)objB + 0x25D4);
        f32 valueA = *(f32 *)((u8 *)objA + 0x25D4);
        callA = valueA > valueB;
        callB = !callA;
    }
    if (callA) {
        s32 address = (s32)ctx;
        address += *(s32 *)((u8 *)objA + 0x1EC) * 0xC0;
        void *slot = (void *)(address + 0x9E4);
        if (slot) ((Dummy_8015180C *)*(void **)((u8 *)slot + 0x10))->call(*(s32 *)((u8 *)objB + 0x1EC), mag);
    }
    if (callB) {
        s32 address = (s32)ctx;
        address += *(s32 *)((u8 *)objB + 0x1EC) * 0xC0;
        void *slot = (void *)(address + 0x9E4);
        if (slot) ((Dummy_8015180C *)*(void **)((u8 *)slot + 0x10))->call(*(s32 *)((u8 *)objA + 0x1EC), mag);
    }
}
#pragma cplusplus off

/* No-op callback in the collision/clear handler group (reached through the handler table): does nothing. */
void fn_80151914(void) {

}

/* Clears the indexed sub-object (at owner + index*0xC0 + 0x9E4) via fn_8014DC08, and if the owner has the per-index flag table enabled at +0x8F4 clears that entry's byte (owner + index*0x1C + 0x8F8). The index is read from arg1 + 0x1EC. */
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
    register s32 entryCount;
    register u8 *objectIter;
    register s32 entryIndex;

    /* On event 0x58, updates per-entry state (+0x454/+0x460) using a flag byte at arg0 + index*0xC0 + 0xA84. */
    if (arg2 == 0x58 && ((Dummy_80151984 *)arg0)->check() != 0) {
        entryCount = fn_801E85A4();
        objectIter = (u8 *)arg0;
        for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
            if (*((u8 *)arg0 + fn_801E86F8(entryIndex) * 0xC0 + 0xA84) != 0 || entryCount > 1) {
                *(s32 *)(objectIter + 0x454) = 4;
            } else if (*(s32 *)(objectIter + 0x454) == 2) {
                *(objectIter + 0x460) = 1;
            }
            objectIter += 0x240;
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
    register s32 self = fn_801E85B4();
    register unsigned index = fn_801E866C(self);
    unsigned int entry_base = (s32)arg0 + index * 0xC0 + 0x9E4;
    s32 *check = (s32 *)entry_base;
    register s32 offset;
    u32 global_value;
    f32 y_offset;
    s32 i;
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
            u32 y = *(s32 *)(item + 4);
            register f32 y_minus;
            register f32 y_plus;
            first[1] = y;
            first[0] = (unsigned short)x;
            y_minus = ((f32 *)first)[1] - y_offset;
            first[2] = *(s32 *)(item + 8);
            x = *(s32 *)(item + 0);
            y = *(s32 *)(item + 4);
            second[1] = y;
            second[0] = (int)x;
            y_plus = ((f32 *)second)[1] + y_offset;
            second[2] = *(s32 *)(item + 8);
            ((f32 *)first)[1] = y_minus;
            ((f32 *)second)[1] = y_plus;
            fn_801E41D8(first, second, global_value, x, *(f32 *)(item + 0xC));
        }
        offset += 4;
        i++;
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
        virtual void f2();
        virtual void f0();
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual s32 check(s32);
    };
    void *self = arg0;
    s32 addr;
    s32 flag;
    register void *entry;
    void *p;
    void *obj;
    s32 index;
    s32 i;
    f32 f;

    fn_801E85B4();
    index = ((s32 (*)(void))fn_801E866C)();
    if (((struct Dummy *)self)->check(index) == 0) goto done;
    addr = (s32)self + index * 0xC0 + 0x9E4;
    if (!addr) goto done;
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
    w1 = ((u32 *)arg1)[1];
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
    ((u32 *)values.m)[1] = w1;
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
/* Initialises a GX light struct built on the caller's stack.  This build links an
 * empty routine: the light index the caller stores at offset 0 is never used, so
 * the light's remaining fields are taken straight from the caller's scratch buffer. */
void fn_801537C8(s32 *light) {

}

#pragma scheduling reset
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
    s32 c0 = (s32)(a0 + t * delta0);
    f32 delta1 = b1 - a1;
    s32 c1 = (s32)(a1 + t * delta1);
    f32 delta2 = b2 - a2;
    s32 c2 = (s32)(a2 + t * delta2);
    f32 delta3 = b3 - a3;
    s32 c3 = (s32)(a3 + t * delta3);
    u8 out[4];
    out[0] = (u8)c0;
    out[1] = (u8)c1;
    out[2] = (u8)c2;
    out[3] = (u8)c3;
    return *(s32 *)out;
}
void *fn_801538E4(void *entry) {
    s32 index = *(s32 *)((u8 *)entry + 0x38) + *(s32 *)((u8 *)entry + 0x14);
    /* Address the 0x14-byte record at index (sum of the two fields at +0x38 and +0x14) in the table at entry+0x3C. */
    return (void *)((u8 *)entry + (index * 0x14) + 0x3C);
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80153900(void *owner, long playerIndex) {
    struct FlagOwner {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void onFlagSet();
    };
    struct Manager {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void prepare();
    };
    extern long fn_801E85A4(void);
    extern long fn_801E866C(long);
    extern long fn_8014AFD4(void *, void *, long);
    extern long fn_801CB7BC(long);
    void *manager;
    long base;
    long entry;
    unsigned char flag;
    /* If owner's flag at +0x9E0 is set, notify it (vtable slot 0x88) and stop;
       otherwise pick one of the two shared managers by game mode, call its
       prepare() hook, then draw the player's 0xC0-byte entry at +0x9E4 via
       fn_8014AFD4 and run a fn_801CB7BC UI action. */
    flag = *(unsigned char *)((char *)owner + 0x9E0);
    if (flag != 0) {
        ((FlagOwner *)owner)->onFlagSet();
        return;
    }
    if (fn_801E85A4() == 2)
        manager = (void *)*(volatile long *)&lbl_8055E23C;
    else
        manager = (void *)*(volatile long *)&lbl_8055E238;
    ((Manager *)manager)->prepare();
    base = (long)owner + fn_801E866C(playerIndex) * 0xC0;
    entry = base + 0x9E4;
    if (entry != 0) {
        if (fn_801E85A4() == 2)
            manager = (void *)*(volatile long *)&lbl_8055E23C;
        else
            manager = (void *)*(volatile long *)&lbl_8055E238;
        fn_8014AFD4((void *)entry, manager, playerIndex);
        fn_801CB7BC(0);
    }
}
#pragma cplusplus reset
#pragma pop
void fn_801539C0(s32 owner, s32 playerIndex) {
    /* Locate the player's 0xC0-byte entry at owner+0x9E4 (indexed by the player's
       car-manager index); if present, pick one of two shared managers by game mode
       and draw the entry via fn_8014CA48. */
    s32 base = owner + fn_801E866C(playerIndex) * 0xC0;
    s32 entry = base + 0x9E4;
    s32 manager;
    if (entry != 0) {
        if (fn_801E85A4() == 2) manager = *(volatile long *)&lbl_8055E23C;
        else manager = *(volatile long *)&lbl_8055E238;
        fn_8014CA48(entry, manager, playerIndex);
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
/* Constant predicate (returns 0 / false); likely a virtual getter reached through a dispatch table. */
s32 fn_80153A30(void) { return 0; }

s32 fn_80153A38(void *base) {
    /* Returns 1 if every indexed entry is ready: per-index flag at (playerIndex*0xC0 + 0xA84) is set
       or the per-slot state at (index*0x240 + 0x454) is 2. */
    s32 i;

    fn_80179650();
    for (i = 0; i < fn_801E85A4(); i++) {
        if (*(u8 *)((u8 *)base + fn_801E86F8(i) * 0xC0 + 0xA84) == 0 &&
            *(s32 *)((u8 *)base + i * 0x240 + 0x454) != 2) {
            return 0;
        }
    }
    return 1;
}

u32 fn_80153AC8(void) {
    /* Constant predicate (returns 1 / true); likely a virtual getter reached through a dispatch table. */
    return 1;
}

#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_80153AD0(void *arg0, s32 arg1) {
    /* Update per-slot UI/state for arg1 based on active flags, optionally trigger setup on
     * a virtual condition, and return 1 if any player slot state (+0x454) is not 4. */
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
/* If multiple entries exist, OR a vtable query over all and dispatch an action when any is set. */
extern "C" void fn_80153C44(void *self, s32 id) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual s32 method(s32);
    };
    Dummy *obj = (Dummy *)self;
    s32 count = fn_801E85A4();
    if (count > 1) {
        s32 any = 0;
        s32 i;
        for (i = 0; i < count; i++) {
            any = (any | obj->method(fn_801E866C(i))) != 0;
        }
        if (any != 0) {
            fn_8014D918((char *)self + fn_801E86F8(id) * 0xC0 + 0x9E4, lbl_8055E240, id);
        }
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

u32 fn_80153CF8(void) {
    /* Constant predicate (returns 1 / true); likely a virtual getter reached through a dispatch table. */
    return 1;
}

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
    u8 *strings = lbl_8032D358;
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
    s32 v344;
    void *p = fn_801E7E3C();
    smooth = lbl_805616E4;
    v1 = smooth - lbl_80561694;
    v2 = v1 - lbl_8056168C;
    v3 = v2 - lbl_80561710;
    v4 = v3 - lbl_80561694;
    v5 = v4 - lbl_8056168C;
    v6 = v5 - lbl_80561710;
    v7 = v6 - lbl_80561694;
    v9 = v7 - lbl_8056168C;
    x = *(f32 *)((u8 *)p + 0x10);
    { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } r28 = ((Dummy *)obj)->method(strings + 0xC34); }
    { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } r27 = ((Dummy *)obj)->method(strings + 0xC44); }
    if (x < v9) fn_8000FBE4();
    if (fn_80161C38() == 0) {
    if (x < smooth) {
        clamped = lbl_8056164C;
        u = (x - v1) / (v2 - v1);
        clamped = (clamped < u) ? clamped : u;
        clamped = (clamped > lbl_80561648) ? clamped : lbl_80561648;
        fv = clamped * lbl_8056164C;
        v1 = lbl_80561648 + fv;
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } r30 = ((Dummy *)obj)->method(strings + 0xC54); }
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } r26 = ((Dummy *)obj)->method(strings + 0xC60); }
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
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } fn_8014784C(obj, strings + 0x334, strings + 0x228, r30); }
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } fn_8014784C(obj, strings + 0x350, strings + 0x360, 0); }
        clamped = lbl_8056164C;
        u = (x - v4) / (v5 - v4);
        clamped = (clamped < u) ? clamped : u;
        clamped = (clamped > lbl_80561648) ? clamped : lbl_80561648;
        fv = clamped * lbl_8056164C;
        v1 = lbl_80561648 + fv;
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } r26 = ((Dummy *)obj)->method(strings + 0xC90); }
        { s32 obj; switch (fn_801E85A4()) { default: obj = lbl_8055E238; break; case 2: obj = lbl_8055E23C; break; } v344 = ((Dummy *)obj)->method(strings + 0x344); }
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
        }
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
/* Returns a mode-dependent tuning value: 5.0 when the record count is 2, 9.0 otherwise. */
f32 fn_8015454C(void) {
    if (fn_800167F4() == 2) return lbl_80561714;
    return lbl_80561718;
}

/* BetaRace: log and copy each car's race score into the results buffer. */
void fn_80154580(s32 raceData, void *results) {
    s32 *carEntry;
    s32 i;
    s32 *resultEntry = (s32 *)results;

    fn_801B8A7C();
    fn_802E30C8(lbl_8032E030);
    carEntry = (s32 *)(raceData + 0x9E4);
    for (i = 0; i < lbl_8055E4D0; i++) {
        s32 score = *(s32 *)((u8 *)carEntry + 0x90);
        *(s32 *)((u8 *)resultEntry + 0x18) = score;
        fn_802E30C8(lbl_8032E048, i, score);
        carEntry = (s32 *)((u8 *)carEntry + 0xC0);
        resultEntry = (s32 *)((u8 *)resultEntry + 0x14);
    }
}

#pragma cplusplus on
extern "C" s32 fn_80154618(void *arg0) {
    s32 **playerIter = (s32 **)&lbl_804348E8;
    s32 anyMatched = 0;
    s32 index = 0;
    /* Returns 1 if no player in state 0x50 matched arg0's vf6 check but fn_801B8514() is set; otherwise returns whether any such match occurred. */
    while (index < fn_801B2F24()) {
        if (*(s32 *)((u8 *)*playerIter + 0x1F0) == 0x50) {
            if (((TObj80154618 *)arg0)->f6(index) != 0) {
                anyMatched = 1;
            }
        }
        playerIter++;
        index++;
    }
    playerIter = (s32 **)0;
    if (anyMatched == 0) {
        if (fn_801B8514() != 0) {
            playerIter = (s32 **)1;
        }
    }
    return (s32)playerIter;
}
#pragma cplusplus off
void fn_801546D4(s32 arg0) {
    /* When the current contest has no challenge sub-task manager, create the default one. */
    switch (fn_80161C94()) {
        case 0:
            fn_801B8A84(arg0);
            break;
    }
}

/* Default predicate: always reports true (1). */
s32 fn_80154714(void) {
    return 1;
}

extern void fn_801B0F70(s32, s32);
extern void fn_80168104(void);
/* Callback adapter: drop the leading context argument and forward the item index and value to fn_801B0F70. */
void fn_8015471C(s32 context, s32 itemIndex, s32 value) {
    fn_801B0F70(itemIndex, value);
}

/* Runs the coin-record update pass when the bet/race manager (allocated as
 * "betamaster") carries coin_file data, flagged by its +0x8F4 byte. */
void fn_80154728(void *object) {
    struct BetaMaster {
        char pad_0[0x8F4];
        u8 coinEnabled; /* +0x8F4: set when coin_file exists */
    };
    struct BetaMaster *master = (struct BetaMaster *)object;

    if (master->coinEnabled != 0) {
        fn_80168104();
    }
}

/* Default no-op status callback: always reports zero (success / nothing pending). */
s32 fn_8015473C(void) {
    return 0;
}

/* Empty default handler: one of a run of do-nothing callbacks this unit hands out
 * where a handler pointer must not be NULL (see fn_80154714 / fn_8015473C next to it). */
void fn_80154744(void) {

}

/* Second of the four empty default handlers at 0x80154744-0x80154750; reached only
 * through a handler/vtable pointer, so it has no callers in the sources. */
void fn_80154748(void) {

}

/* Third of the four empty default handlers at 0x80154744-0x80154750 (no-op: nothing
 * to do for this slot).  No source references it, so it is taken by pointer. */
void fn_8015474C(void) {

}

/* Fourth and last of the empty default handlers at 0x80154744-0x80154750; no-op. */
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
    u8 *strings;
    u8 *fallback, *sound1, *sound2;
    s32 z = 0;
    s32 one = 1;
    s32 sixteen = 16;
    strings = lbl_8032D358;
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
            ((void (*)(void *,void *,void *,s32,s32))fn_8002F53C)(obj+4,(void *)fn_80155318,(void *)fn_8014EFC0,0x124,sixteen);
            *(void **)(obj+0x1248)=0; *(void **)(obj+0x1244)=0;
            *(s32 *)(obj+0x1250)=z; *(s32 *)(obj+0x124c)=z;
            node=obj+4;
            for(j=z;j<sixteen;j++,node+=0x124) {
                *(void **)(node+0x118)=obj;
                *(s32 *)(node+0x110)=i;
                *(void **)(node+0x120)=0;
                *(void **)(node+0x11c)=*(void **)(obj+0x1244);
                prev=*(char * volatile *)(obj+0x1244);
                if(prev) *(void **)(prev+0x120)=node;
                *(void **)(obj+0x1244)=node;
                if(!*(void **)(obj+0x1248)) *(void **)(obj+0x1248)=node;
            }
            *(s32 *)(obj+0x1254)=z; obj[0x1260]=z; *(s32 *)(obj+0x1268)=i;
            if(iscar) *(void **)(obj+0x1258)=0; else *(void **)(obj+0x1258)=fn_802076A0(sound1,one,i,z);
            sound=*(char **)(obj+0x1258);
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=one; *(f32 *)(sound+8)=zero;}
            if(iscar) *(void **)(obj+0x125c)=0; else *(void **)(obj+0x125c)=fn_802076A0(sound2,one,i,2);
            sound=*(char **)(obj+0x125c);
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=one; *(f32 *)(sound+8)=zero;}
        }
        *(void **)(entry+0x9ec)=obj;
        obj=(char *)fn_801284F8(0xf90,strings+0xd4c);
        if(obj) {
            *(void **)obj=lbl_8032E150; *(void **)(obj+4)=obj+0x10;
            *(s32 *)(obj+0xc)=sixteen; *(s32 *)(obj+8)=z;
            ((void (*)(void *,void *,void *,s32,s32))fn_8002F53C)(obj+0x10,(void *)fn_801552C8,(void *)fn_8014F088,0xf8,sixteen);
        }
        *(void **)(entry+0x9f0)=obj;
        *(void **)(entry+0xa4c)=p;
        *(s32 *)(entry+0x9e4)=i;
        *(s32 *)(entry+0x9e8)=!iscar;
        *(s32 *)(entry+0xa98)=fn_802CAC28(strings+0xd5c,z);
        *(s32 *)(entry+0xa9c)=fn_802CAC28(strings+0xd68,z);
        name=fn_80012820(*(s32 *)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC())+4))+8;
        found=z;
        ((s32 (*)(char *,s32,char *,...))fn_801345D8)(path,0x40,(char *)lbl_8032D358+0xd78);
        fn_801332D0((char *)fn_8000DA10()+12,path,&found);
        if(!found) *(s32 *)(entry+0xaa0)=fn_802CAC28(fallback,z);
        else {
            memset(shortname,z,8); strncpy(shortname,name,3);
            ((s32 (*)(char *,s32,char *,...))fn_801345D8)(path2,0x40,(char *)lbl_8032D358+0xd84,shortname,found);
            if(fn_8012C33C(path2)) *(s32 *)(entry+0xaa0)=fn_802CAC28(path2,z);
            else { ((void (*)(char *,...))fn_802E30C8)((char *)lbl_8032D358+0xd90,path2); *(s32 *)(entry+0xaa0)=fn_802CAC28(fallback,z); }
        }
        *(s32 *)(entry+0x9f4)=fn_801572A4(*(void **)(entry+0x9ec),*(s32 *)(entry+0x9e4),&lbl_8055E24C);
        *(void **)(entry+0xa94)=0; *(void **)(entry+0xa90)=0;
        if(!iscar) {
            sound=fn_802076A0(strings+0xdb4,one,*(s32 *)(entry+0x9e4),2);
            *(void **)(entry+0xa90)=sound;
            if(sound && zero!=*(f32 *)(sound+8)) {sound[0x4d]=one; *(f32 *)(sound+8)=zero;}
            *(void **)(entry+0xa94)=fn_802076A0(strings+0xdc0,7,*(s32 *)(entry+0x9e4),z);
        }
    }
    }
    for(i=z,off=z;i<*(s32 *)(p+0x330);off+=4,i++) {
        other=*(char **)(*(char **)(p+0x32c)+off);
        fn_801EA1E0(other+12,one,*(f32 *)(other+8),*(f32 *)(other+0x10));
    }
    for(i=z,off=z;i<*(s32 *)(p+0x3bc);off+=4,i++) {
        other=*(char **)(*(char **)(p+0x3b8)+off);
        fn_801EA1E0(other+12,one,*(f32 *)(other+8),*(f32 *)(other+0x10));
    }
    table=__AXFXGetLfoSinTable_801769CC();
    value=fn_8014E7DC((s32)*__AXFXGetLfoSinTable_801769CC(),*(s32 *)((char *)table+8));
    if(*(s32 *)((char *)__AXFXGetLfoSinTable_801769CC()+0x10)&one) value=lbl_80561724;
    *(f32 *)(p+0x8dc)=value; *(f32 *)(p+0x8e0)=value;
    if(fn_80179650()>one) *(f32 *)(p+0x8d8)=lbl_80561728;
}
#pragma pop

s32 fn_80155288(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern void lbl_8032E160(void);
/* Constructor helper: point the object's vtable slot at the vtable lbl_8032E160. */
void fn_801552C8(void **vtableSlot) {
    *vtableSlot = (void *)&lbl_8032E160;
}

s32 fn_801552D8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern s32 lbl_8032E1A0[];
extern f32 lbl_8056171C;
void fn_80155318(void *arg0) {
    f32 f0 = lbl_80561648;
    s32 zero = 0;
    s32 *vtable = lbl_8032E1A0;
    f32 f1 = lbl_8056171C;
    s32 neg1 = -1;
    *(s32 **)arg0 = vtable;
    *(s32 *)((u8 *)arg0 + 0x120) = zero;
    *(s32 *)((u8 *)arg0 + 0x11C) = zero;
    *((u8 *)arg0 + 4) = (u8)zero;
    *(f32 *)((u8 *)arg0 + 8) = f1;
    *(f32 *)((u8 *)arg0 + 0xC) = f0;
    *(f32 *)((u8 *)arg0 + 0x10) = f0;
    *(s32 *)((u8 *)arg0 + 0x118) = zero;
    *(s32 *)((u8 *)arg0 + 0x10C) = neg1;
    *((u8 *)arg0 + 5) = (u8)zero;
    *((u8 *)arg0 + 0x14) = (u8)zero;
    *((u8 *)arg0 + 0x64) = (u8)zero;
    *((u8 *)arg0 + 0xB4) = (u8)zero;
}
/* Empty default handler: does nothing.  It follows the node constructor fn_80155318 and is
 * taken only by function pointer (no source calls it), like the stubs at 0x80154744-0x80154750. */
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
        while(i<*(s32 *)((u8 *)(arg0)+0x18)){
            entry=(*(u8***)((u8*)arg0+0x14))[i];
            id=*(s32 *)((u8 *)(entry)+0xC0);
            if(id==((s32(*)(void*,void*))(*(void***)arg1)[9])(arg1,entry)){
                entry=(*(u8***)((u8*)arg0+0x14))[i];
                if(lbl_80558DC4[0]>=(f32)__fabs(*(f32 *)((u8 *)(entry)+0x34))){
                    if(lbl_80558DC4[0]>=(f32)__fabs(*(f32 *)((u8 *)(lbl_804348E8[index])+0x2690)) && fn_80161BB8()==0)
                        entry[index+0xC4]=1;
                }
            }
            i++;
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

#pragma cplusplus on
extern "C" void fn_80155700(void *arg0, void *arg1, s32 index) {
    class VArg0 {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5();
        virtual s32 v6(s32);
    };
    class VArg1 {
    public:
        virtual void v0(); virtual void v1();
        virtual f32 *v2();
    };
    class VSub {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual f32 v8(void *, f32);
    };
    class VObj {
    public:
        virtual VSub *v0();
        virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(s32);
        virtual void v7();
        virtual void v8(f32 *, f32 *, f32 *);
    };
    register f32 *first, *second;
    u8 *self = (u8 *)arg0;
    register u8 *player = (u8 *)fn_8017960C(index);
    register u8 *slot;
    u8 *entry, *manager, *player2;
    VObj *obj;
    f32 mat1[12], mat2[12], rot1[3], pos1[3], rot2[3], pos2[3];
    Event80155700 event;
    f32 zero, height, duration, threshold, one, value;
    s32 i, active, kind, tmp;
    f32 *v;
    if (player && (f32)__fabs(*(f32 *)(player+0x2690)) <= lbl_80558DC4[0] &&
        ((VArg0 *)arg0)->v6(index) &&
        fn_80161BB8() == 0 && *(s32 *)(player+0x1F0) == 0x50) {
        one=lbl_8056164C; zero=lbl_80561648; height=lbl_8056172C; duration=lbl_80561730; threshold=lbl_8056163C;
        slot = self + index * 0xC0;
        first=mat1;
        for (i = 0; i < *(s32 *)(self+0x330); i++) {
            entry = (*(u8 ***)(self+0x32C))[i];
            if (arg1 == *(void **)entry && entry[4]) {
                entry[4]=0;
                first[0]=one; first[1]=zero; first[2]=zero;
                first[3]=zero; first[4]=one; first[5]=zero;
                first[6]=zero; first[7]=zero; first[8]=one;
                first[9]=zero; first[11]=zero; first[10]=height;
                rot1[0]=zero; rot1[1]=zero; rot1[2]=zero;
                pos1[0]=zero; pos1[1]=zero; pos1[2]=zero;
                obj=*(VObj **)entry;
                obj->v8(first,pos1,rot1);
                obj=*(VObj **)entry;
                obj->v6(0);
                *(f32 *)(entry+0x14)=duration+lbl_8055E3C8;
                obj=*(VObj **)entry;
                value=obj->v0()->v8(lbl_80559FB8,lbl_80561730);
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
            if (arg1 == *(void **)entry && entry[4]) {
                player2=(u8 *)fn_8017960C(index);
                if (player2) {
                    v=((VArg1 *)arg1)->v2();
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
                obj=*(VObj **)entry;
                obj->v8(second,pos2,rot2);
                obj=*(VObj **)entry;
                obj->v6(0);
                *(f32 *)(entry+0x14)=duration2+lbl_8055E3C8;
                active=1;
            } else active=0;
            if (active) {
                manager=*(u8 **)(self+0x448);
                if (manager) {
                    tmp=fn_80009C84();
                    kind=2;
                    if (tmp) kind=0;
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
#pragma cplusplus off

void fn_80155AEC(void) {

}

#pragma scheduling invalid_target
void fn_80155AF0(void *arg0, void *arg1) {
    u8 *b358 = lbl_8032D358;
    void *fn;
    void *tmp;
    s32 c;
    void *alloc;
    void *ret;
    float *fp;
    s32 idx;
    void **base;
    fn = *(void **)((u8 *)*(void **)arg1 + 8);
    tmp = ((void *(*)(void *))fn)(arg1);
    fn = *(void **)((u8 *)*(void **)tmp + 0xc);
    c = ((s32(*)(void *, void *))fn)(tmp, lbl_80559FB8);
    if (c != 0) {
        alloc = (void *)fn_801284F8(0x1c, b358 + 0xdcc);
        if (alloc != 0) {
            *(void **)((u8 *)alloc + 0x18) = lbl_8032E1E4;
            *(void **)alloc = arg1;
            fn = *(void **)((u8 *)*(void **)arg1 + 0x10);
            ret = ((void *(*)(void *, void *))fn)(arg1, lbl_8032E1E4);
            fp = (float *)ret;
            *(float *)((u8 *)alloc + 8) = fp[0];
            *(float *)((u8 *)alloc + 0xc) = fp[1];
            *(float *)((u8 *)alloc + 0x10) = fp[2];
            *(void **)((u8 *)alloc + 0x18) = lbl_8032E1D8;
        }
        idx = *(s32 *)((u8 *)arg0 + 0x330);
        base = *(void ***)((u8 *)arg0 + 0x32c);
        *(s32 *)((u8 *)arg0 + 0x330) = idx + 1;
        base[idx] = alloc;
        return;
    }
    fn = *(void **)((u8 *)*(void **)arg1 + 8);
    tmp = ((void *(*)(void *))fn)(arg1);
    fn = *(void **)((u8 *)*(void **)tmp + 0xc);
    c = ((s32(*)(void *, void *))fn)(tmp, b358 + 0xdd8);
    if (c != 0) {
        void *alloc2 = (void *)fn_801284F8(0x1c, b358 + 0xde8);
        if (alloc2 != 0) {
            *(void **)((u8 *)alloc2 + 0x18) = lbl_8032E1E4;
            *(void **)alloc2 = arg1;
            fn = *(void **)((u8 *)*(void **)arg1 + 0x10);
            ret = ((void *(*)(void *, void *))fn)(arg1, lbl_8032E1E4);
            fp = (float *)ret;
            *(float *)((u8 *)alloc2 + 8) = fp[0];
            *(float *)((u8 *)alloc2 + 0xc) = fp[1];
            *(float *)((u8 *)alloc2 + 0x10) = fp[2];
            *(void **)((u8 *)alloc2 + 0x18) = lbl_8032E1CC;
        }
        idx = *(s32 *)((u8 *)arg0 + 0x3bc);
        base = *(void ***)((u8 *)arg0 + 0x3b8);
        *(s32 *)((u8 *)arg0 + 0x3bc) = idx + 1;
        base[idx] = alloc2;
    }
}
/* Constant predicate in the UI text-object subsystem: always returns 1 (true). */
u32 fn_80155C88(void) { return 1; }

extern int vsprintf(char *, const char *, va_list);
/* Format a string into this object's text buffer at offset 0x14. */
void fn_80155C90(void *obj, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)obj + 0x14, fmt, args);
}

/* Formats a string into the buffer at offset 0x64 of the given object. */
void fn_80155D20(void *dst, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)dst + 0x64, fmt, ap);
}

/* Format a string into this object's text buffer at offset 0xB4. */
void fn_80155DB0(void *obj, const char *fmt, ...) {
    char *dest = (char *)obj + 0xB4;
    va_list args;
    va_start(args, fmt);
    vsprintf(dest, fmt, args);
    va_end(args);
}

/* Set the object's value field (+0x108) and mark it active by setting +0x114 to 1. */
void fn_80155E40(void *arg0, s32 arg1) {
    typedef struct {
        u8 pad[0x108];
        s32 value;
        u8 pad2[0x8];
        s32 active;
    } ObjFields;
    ObjFields *obj = (ObjFields *)arg0;
    obj->value = arg1;
    obj->active = 1;
}

void fn_80155E50(void *event, int value) {
    /* Set the s32 type/id field at +0x10C of an event object. */
    *(int *)((char *)event + 0x10C) = value;
}

/* Clear the byte flag at offset +4 of the object. */
void fn_80155E58(void *object) {
    ((u8 *)object)[4] = 0;
}

void fn_80155E64(void *object, signed char value) {
    /* Set the signed-char flag at +5 of the object. */
    *((signed char *)object + 5) = value;
}

void *fn_80155E6C(void *arg0)
{
  typedef struct Node Node;
  struct Node
  {
    unsigned char pad[0x11C];
    Node *prev;
    Node *next;
  };
  typedef struct 
  {
    unsigned char pad[0x1244];
    Node *head;
    Node *tail;
    Node *first;
    Node *list;
  } Owner;
  extern float lbl_8055E3C8;
  Owner *owner = (Owner *) arg0;
  Node *node = owner->head;
  Node *next;
  Node *prev;
  Node *tail;
  float f1648 = f1648;
  if (node != 0)
  {
    next = node->next;
    if (next != 0)
    {
      next->prev = node->prev;
    }
    else
    {
      owner->head = node->prev;
    }
    prev = node->prev;
    if (prev != 0)
    {
      prev->next = node->next;
    }
    else
    {
      owner->tail = node->next;
    }
    node->next = 0;
    node->prev = 0;
    node->next = owner->list;
    tail = owner->list;
    if (tail != 0)
    {
      tail->prev = node;
    }
    owner->list = node;
    if (owner->first == 0)
    {
      owner->first = node;
    }
    *(((unsigned char *) node) + 4) = 1;
    *((float *) (((unsigned char *) node) + 0x10)) = lbl_8055E3C8;
    *((float *) (((unsigned char *) node) + 0xC)) = f1648;
    *((float *) (((unsigned char *) node) + 8)) = f1648;
    *(((unsigned char *) node) + 0x14) = 0;
    *(((unsigned char *) node) + 0x64) = 0;
    *(((unsigned char *) node) + 0xB4) = 0;
    *(((unsigned char *) node) + 5) = 0;
    *((int *) (((unsigned char *) node) + 0x10C)) = -1;
    *((float *) (((unsigned char *) node) + 0x104)) = f1648;
    *((int *) (((unsigned char *) node) + 0x108)) = 0;
    *((int *) (((unsigned char *) node) + 0x114)) = 1;
    return node;
  }
  return 0;
}

/* Format a string into the buffer at dst + 4 using printf-style arguments. */
void fn_80155F44(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf(dst + 4, fmt, args);
}

/* Format a string into the buffer at arg0 + 0x54 using printf-style arguments. */
void fn_80155FD4(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0x54, fmt, args);
}

/* Format a string into the buffer at arg0 + 0xA4 using printf-style arguments. */
void fn_80156064(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0xA4, fmt, args);
}

void fn_801560F4(void) {

}

/* Set the trailing 32-bit field at +0xF4 of a 0xF8-byte text-entry record. */
void fn_801560F8(void *record, s32 value) {
    *(s32 *)((u8 *)record + 0xF4) = value;
}

void fn_80156100(void) {

}

void fn_80156104(void) {

}

void fn_80156108(void) {

}

s32 fn_8015610C(void *cursor) {
    /* Return the address of the next 0xF8-byte record in this pool, using the
     * base pointer at +4 and advancing the cursor index at +8. */
    s32 *base = *(s32 **)((u8 *)cursor + 4);
    s32 index = *(s32 *)((u8 *)cursor + 8);
    *(s32 *)((u8 *)cursor + 8) = index + 1;
    return (s32)base + index * 0xF8;
}

s32 fn_8014F0C8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_8014F088(s32 arg0, s32 arg1);
/* Initialize two art-anim manager slots and load the bonanza config. */
void fn_8014F108(void *owner) {
    void *base = owner;
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

void fn_8014F194(void *arg0) {
    (void)arg0;
    (void)fn_80179650();
    fn_802C9A58();
}

#pragma cplusplus on
extern "C" void fn_8014FB7C(void *arg0) {
    class VObj {
    public:
        virtual void d0(s32);
    };
    VObj *p;
    register u8 *obj = (u8 *)arg0;
    register s32 i = 1;
    p = *(VObj **)(obj + 0x9D8);
    if (p != 0) {
        if (p != 0) p->d0(1);
        *(VObj **)(obj + 0x9D8) = 0;
    }
    obj += 0x240;
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
    s32 sp8, spC;
    void *sp10p;
    u8 sp60[288];
    u8 sp40[32];
    f32 sp38, sp34, sp30, sp24, sp20, sp1C, sp18;
    s32 sp2C, sp28;
    void *manager;
    void *resource;
    void *entry;
    s32 i, j, k, size, handle;
    f32 f1v;
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
                fn_802E30C8(strings + 0xADC, v);
            }
        }
    }
    fn_8013A198(&sp10p, -1);
    manager = fn_80131810((const char *)((LfoObj *)(*(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20)))->lookup(strings + 0xAFC, strings + 0xB0C));
    if (manager != 0) {
        s32 idx = 0;
        void *e;
        while ((e = ((Manager *)manager)->get(idx)) != 0) {
            void *r = fn_80204CF0();
            void *check;
            if (((Entry *)e)->has(strings + 0xA30) != 0) {
                ((Entry *)e)->next(strings + 0xA30);
                check = (void *)fn_80204BB4();
            } else check = r;
            if (check == r) {
                void *alloc = (void *)fn_801284F8(0xD4, &lbl_80559F80);
                if (alloc != 0) alloc = fn_8015011C(alloc, e);
                    spC = (s32)alloc;
                fn_801500F8((void *)(arg0 + 0x14), &spC);
            }
            idx++;
        }
        fn_80131818(manager);
    } else {
        void *lfo = *(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        s32 idx = 0;
        void *e;
        while ((e = ((LfoObj *)lfo)->get(idx)) != 0) {
            if (((Entry *)e)->has(&lbl_80559F88) != 0) {
                void *alloc = (void *)fn_801284F8(0xD4, &lbl_80559F80);
                if (alloc != 0) alloc = fn_8015011C(alloc, e);
                    sp8 = (s32)alloc;
                fn_801500F8((void *)(arg0 + 0x14), &sp8);
            }
            idx++;
        }
    }
    resource = fn_80131810((const char *)(strings + 0xB1C));
    if (resource != 0) {
        s32 idx = 0;
        while ((entry = ((Manager *)resource)->get(idx)) != 0) {
            sp20 = lbl_80561648;
            sp24 = lbl_80561648;
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
                    f32 avg1 = sp20 * (lbl_8056164C / (f32)n);
                    f32 avg2 = sp24 * (lbl_8056164C / (f32)n);
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
                    s32 **a = (s32 **)(arg0 + 0x220);
                    s32 cnt = *(s32 *)(arg0 + 0x224);
                    *(s32 *)(arg0 + 0x224) = cnt + 1;
                    (*a)[cnt] = (s32)alloc;
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
extern f32 lbl_80561654, lbl_80561658, lbl_8056165C, lbl_80561660, lbl_80561664;
extern f32 lbl_80561668, lbl_8056166C, lbl_80561670, lbl_80561674, lbl_80561678, lbl_8056167C;
extern f32 lbl_80559EB8;
extern void fn_801683F4(void *, s32);
extern f32 fn_80141C9C(f32);
extern s32 fn_80144C90(f32);
extern void fn_80142B60(void *);
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
