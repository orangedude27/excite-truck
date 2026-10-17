// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
#include <stdarg.h>

typedef struct { s32 a, b, c, d; f32 e, f; s32 g; } Copy8014C6F0;

extern s32 lbl_8032E1A0[];
extern f32 lbl_80561648;
extern f32 lbl_8056171C;

extern s32 lbl_8055E238;
extern s32 lbl_8055E23C;
extern s32 fn_80179650(void);
extern s32 fn_801E85A4(void);
extern s32 fn_801E86F8(s32);
extern s32 fn_801E866C(s32);
extern s32 fn_8014CA48(s32, s32, s32);
extern s32 fn_8014AFD4(void *, void *, s32);
extern s32 fn_801CB7BC(s32);
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
extern void fn_802E30C8();
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
extern void fn_801E7E18(void);
extern void fn_802AE220(void *);
extern void fn_8002F634(void *, void *, s32, s32);
extern f32 lbl_80561648, lbl_80561688, lbl_805616C0, lbl_805616C4;
extern void *lbl_8032E190;
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

void fn_80149210(void *arg0) {
    u32 *p = (u32 *)arg0;
    u32 x = p[1] + 1;
    u32 t = x << 30;
    u32 b = x >> 31;
    p[1] = (t - b) * 4 + b;
}

s32 fn_80149234(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93D0;
    return sp8.v[((s32 *)arg0)[1]];
}

extern s32 fn_8014D918(void*, s32, s32);
extern s32 lbl_8055E240;
extern f32 lbl_80561714, lbl_80561718;
s32 fn_80149274(void **arg0) {
    s32 (*fn)(void*) = (s32 (*)(void*))*arg0;
    return fn(arg0) & 0xFF7F7F7F;
}

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

extern s32 lbl_802F93F0[];
s32 fn_80149380(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93F0;
    return sp8.v[((s32 *)arg0)[1]];
}

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
    float temp_f1 = arg1[0];
    float temp_f3 = arg1[1];
    arg2[1] += temp_f1;
    arg2[4] -= temp_f1;
    arg2[2] += temp_f3;
    arg2[5] -= temp_f3;
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
    float value = arg2[4] + lbl_8056162C * *arg1;
    if (value < lbl_80561630) value = lbl_80561630;
    if (value > lbl_80561634) value = lbl_80561634;
    arg2[4] = value;
}

s32 *fn_80149580(void) {
    return &lbl_80559EA4;
}

void fn_80149588(s32 arg0) {
    s32 sp8;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    fn_80130980(&sp8, 0x20, 3);
    if (1) {
        if (1) {
            fn_801474EC(arg0, &lbl_80559EC4, &sp8);
        }
    }
}

extern s32 lbl_8055E3C4;
extern f32 lbl_80561638, lbl_8056163C;
extern f64 lbl_80561640;
extern f64 sin(f64);
#pragma dont_inline on
f32 fn_801495D4(s32 arg0) {
    f32 angle;
    f32 fraction;
    s32 quotient;
    s32 remainder;
    union { f64 d; u32 words[2]; } bits;
    bits.words[0] = 0x43300000;
    bits.words[1] = arg0 ^ 0x8000;
    angle = (f32)(bits.d - lbl_80561640);
    quotient = lbl_8055E3C4 / arg0;
    remainder = lbl_8055E3C4 - quotient * arg0;
    bits.words[1] = remainder ^ 0x8000;
    fraction = (f32)(bits.d - lbl_80561640);
    return lbl_8056163C + lbl_8056163C * (f32)sin((f64)(lbl_80561638 * fraction / angle));
}
#pragma dont_inline off

void fn_80149650(void) { fn_801495D4(0x40); }

void fn_80149CEC(void *arg0, void *arg1) {
    typedef struct { void *pad[4]; void (*fn)(void *); } Vt80149CEC;
    void *r5;
    void *r3;
    s32 val;
    r5 = *(void **)((u8 *)arg1 + 0x68);
    *(f32 *)((u8 *)arg0 + 0x28) = *(f32 *)((u8 *)r5 + 0x8D4);
    r3 = *(void **)((u8 *)fn_8017960C(*(s32 *)arg1) + 0x270);
    (*(Vt80149CEC **)r3)->fn(r3);
    val = *(s32 *)((u8 *)r3 + 4);
    *(s32 *)((u8 *)arg0 + 4) = val;
    *(s32 *)((u8 *)arg0 + 0x10) = val - 1;
    fn_80149D64(arg0, arg1, val);
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

s32 fn_8014ACD8(void *arg0, s32 arg1) {
    Obj8014ACD8 *obj;
    s32 result;
    obj = (Obj8014ACD8 *)fn_801B2ED0(arg1);
    obj = (Obj8014ACD8 *)obj->vtable->fn();
    result = 0;
    if (obj->state != 3 && obj->flags == 0) {
        result = 1;
    }
    if (result != 0 && *(f32 *)((u8 *)arg0 + 0x8D4) <= *(f32 *)((u8 *)arg0 + 0x8DC)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

s32 fn_8014AD64(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x108); }

f32 fn_8014AD6C(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 8);
}

extern s32 fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_8056164C;
extern f32 lbl_80561650;
extern void fn_8001DFF0(void);
extern void fn_80149658(s32, void *, void *, s32);
extern unsigned long lbl_80559E94;
void fn_8014AD74(void *arg0) {
    f32 step;
    s32 state = fn_80176A1C() - 2;
    if ((state | -state) == 0) {
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
    struct Node8014AE60 {
        u8 pad[0x11C];
        struct Node8014AE60 *prev;
        struct Node8014AE60 *next;
    };
    struct Head8014AE60 {
        struct Node8014AE60 *first;
        struct Node8014AE60 *last;
    };
    struct Head8014AE60 *head = (struct Head8014AE60 *)*(void **)arg0;
    struct Node8014AE60 *obj = (struct Node8014AE60 *)*((void **)arg0 + 1);
    struct Node8014AE60 *node;

    node = obj->next;
    if (node != 0) {
        node->prev = obj->prev;
    } else {
        head->first = obj->prev;
    }
    node = obj->prev;
    if (node != 0) {
        node->next = obj->next;
    } else {
        head->last = obj->next;
    }
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
    s32 state;
    if (*((u8 *)arg0 + 4) != 0) {
        state = fn_80176A1C() - 2;
        if ((state | -state) == 0) {
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

void fn_8014C72C(void **arg0) {
    register void *obj = *arg0;
    register void **vtable = *(void ***)obj;
    ((void (*)(void))vtable[3])();
    fn_801476C4();
}

s64 fn_8014C770(f32 *arg0, f32 *arg1, f32 t) {
    union { struct { f32 x, y; } f; s64 bits; } out;
    out.f.y = arg0[1] + t * (arg1[1] - arg0[1]);
    out.f.x = arg0[0] + t * (arg1[0] - arg0[0]);
    return out.bits;
}

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
    t = (t > lbl_80561648) ? lbl_80561648 : t;
    return farg2 + t * (farg3 - farg2);
}

float fn_8014C8F8(float farg0, float farg1, float farg2) {
    float value = farg2;
    if (value < farg0) {
        goto first;
    }
    goto second;
first:
    value = farg0;
second:
    if (value > farg1) {
        goto third;
    }
    goto fourth;
third:
    value = farg1;
fourth:
    return value;
}

void fn_8014C920(void *arg0, void *arg1) {
    int a = ((int *)arg1)[0];
    int b = ((int *)arg1)[1];
    int c = ((int *)arg1)[2];
    int d = ((int *)arg1)[3];
    float e = ((float *)arg1)[4];
    int f = ((int *)arg1)[5];
    int g = ((int *)arg1)[6];
    int h = ((int *)arg1)[7];
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

void fn_8014D700(void *arg0, s32 arg1) {
    s32 var_r6;
    void *temp_r5;
    void *temp_r5_2;
    void **temp_r3;
    void (*fn)(void *, void *, void *);

    temp_r5 = *(void **)((u8 *)arg0 + 0xC);
    *(s32 *)((u8 *)temp_r5 + 8) = 0;
    temp_r3 = *(void ***)((u8 *)arg0 + 0x10);
    fn = (void (*)(void *, void *, void *))*(void **)((u8 *)*temp_r3 + 0x48);
    fn(*temp_r3, *(void **)((u8 *)arg0 + 0xC), temp_r5);
    temp_r5_2 = *(void **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)temp_r5_2 + 0x8F4) != 0) {
        var_r6 = *(s32 *)((u8 *)temp_r5_2 + 0x8F4 + *(s32 *)arg0 * 0x1C + 8);
    } else {
        var_r6 = 0;
    }
    fn_80149658(arg1, (void *)((u8 *)arg0 + 0x6C), *(void **)((u8 *)arg0 + 0xC), var_r6);
}

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

void fn_8014DE4C(void) {

}

void fn_8014E704(void) {

}

extern void fn_80128670(s32);
extern void *lbl_8055E268;
extern s32 lbl_80559F40;
s32 fn_8014E708(s32 arg0) {
    u8 *base=(u8 *)lbl_8055E268;
    if(base!=0) {
        ObjE708 *obj=*(ObjE708 **)(base+arg0*0xC0+0x9F4);
        return obj->vtable->fn7();
    }
    return 0;
}

s32 fn_8014E738(void) { return 0; }

void fn_8014E7D8(void) {

}

s32 fn_8014EFC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
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
extern s32 lbl_8032DB34;
extern s32 lbl_8032DB40;
s32 *fn_801500F8(void *arg0, s32 *arg1) {
    s32 next;
    s32 value;
    s32 index;
    s32 *data;
    value = *arg1;
    index = ((s32 *)arg0)[1];
    next = index + 1;
    data = *(s32 **)arg0;
    ((s32 *)arg0)[1] = next;
    data[index] = value;
    return &data[index];
}

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
void fn_80150B60(void *arg0) {
    fn_8016783C(arg0);
    if (((u8 *)arg0)[0x8F4] != 0) {
        memset((char *)arg0 + 0x8F8, 0, 0xE0);
        fn_801688FC(1);
        fn_80168020();
    }
    fn_8016A0D4();
    if (((void **)arg0)[0x113] != 0) {
        ((u8 *)arg0)[0x450] = 0;
        ((u8 *)(((void **)arg0)[0x113]))[0x4A] = 1;
        ((u8 *)(((void **)arg0)[0x113]))[0x4C] = 0;
    }
}

s32 fn_80151604(void) { return 0; }

void fn_80151654(void *a0, void *a1, s32 a2, s32 a3, s32 a4) {
    s32 index;
    void *obj;
    if (a4 != 0x3EB) return;
    index = *(s32 *)((char *)a1 + 0x1EC);
    obj = (char *)a0 + index * 0xC0 + 0x9E4;
    if (obj == 0) return;
    (*(void (**)(void))(*(void ***)((char *)obj + 0x10))[4])();
}

void fn_80151688(void) {

}

void fn_80151914(void) {

}

void fn_801537C8(void) {

}

void *fn_801538E4(void *arg0) {
    return (void *)((u8 *)arg0 + ((*(s32 *)((u8 *)arg0 + 0x38) + *(s32 *)((u8 *)arg0 + 0x14)) * 0x14) + 0x3C);
}

void fn_80153900(void *arg0, s32 arg1) {
    void **v;
    s32 p;
    if (*(u8 *)((u8 *)arg0 + 0x9E0)) {
        (*(void (**)(void))(*(u32 *)arg0 + 0x88))();
    } else {
        v = fn_801E85A4() == 2 ? (void **)lbl_8055E23C : (void **)lbl_8055E238;
        (*(void (**)(void))(*(u32 *)*v + 0x1C))();
    }
    p = (s32)arg0 + fn_801E866C(arg1) * 0xC0 + 0x9E4;
    if (p != 0) {
        v = fn_801E85A4() == 2 ? (void **)lbl_8055E23C : (void **)lbl_8055E238;
        fn_8014AFD4((void *)p, v, arg1);
        fn_801CB7BC(0);
    }
}

void fn_801539C0(s32 arg0, s32 arg1) {
    s32 p = arg0 + fn_801E866C(arg1) * 0xC0 + 0x9E4;
    if (p != 0) {
        s32 value;
        if (fn_801E85A4() == 2) value = lbl_8055E23C;
        else value = lbl_8055E238;
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
    void *p;
    s32 i;
    fn_80179650();
    p = arg0;
    i = 0;
    while (i < fn_801E85A4()) {
        if (*(u8 *)((u8 *)arg0 + fn_801E86F8(i) * 0xC0 + 0xA84) == 0 &&
            *(s32 *)((u8 *)p + 0x454) != 2) return 0;
        p = (u8 *)p + 0x240;
        i++;
    }
    return 1;
}

u32 fn_80153AC8(void) { return 1; }

u32 fn_80153CF8(void) { return 1; }

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

s32 fn_80154618(void *arg0) {
    s32 **it = (s32 **)&lbl_804348E8;
    s32 found = 0;
    s32 i = 0;
    while (i < fn_801B2F24()) {
        if (*(s32 *)((u8 *)*it + 0x1F0) == 0x50) {
            if (((VTable80154618 *)(*(s32 **)arg0))->fn(arg0, i) != 0) {
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

void fn_801556F0(void) {

}

void fn_801556F4(void) {

}

void fn_801556F8(void) {

}

void fn_801556FC(void) {

}

void fn_80155AEC(void) {

}

u32 fn_80155C88(void) { return 1; }

extern int vsprintf(char *, const char *, ...);
void fn_80155C90(char *arg0, ...) {
    char buffer[0x200];
    vsprintf(arg0 + 0x14, buffer);
}

void fn_80155D20(void *arg0, const char *fmt, ...) {
    char *dest = (char *)arg0 + 0x64;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(dest, fmt, ap);
    va_end(ap);
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

void fn_80155F44(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf(dst + 4, fmt, args);
    va_end(args);
}

void fn_80155FD4(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0x54, fmt, args);
    va_end(args);
}

void fn_80156064(void *arg0, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)arg0 + 0xA4, fmt, args);
    va_end(args);
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

s32 fn_8015610C(void *arg0) {
    s32 temp_r4 = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 8) = temp_r4 + 1;
    return *(s32 *)((u8 *)arg0 + 4) + temp_r4 * 0xF8;
}

s32 fn_8014F0C8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8014F088(s32 arg0, s32 arg1);
void fn_8014F108(void *arg0) {
    void *base = arg0;
    void *entry = arg0;
    u8 *member = (u8 *)arg0 + 0x454;
    u32 i = 0;
    do {
        s32 result = fn_801284F8(8, &lbl_8032DB34);
        if (result == 0) {
            result = fn_802ADDD8(2);
        }
        *(s32 *)((u8 *)entry + 0x45C) = result;
        fn_8014F194(member);
        i++;
        entry = (u8 *)entry + 0x240;
        member += 0x240;
    } while (i < 2);
    *(s32 *)((u8 *)base + 0x9D8) = fn_80145E70(&lbl_8032DB40);
}
extern unsigned long lbl_80559E94;
extern unsigned long lbl_80559E9C;
extern s32 fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_8056164C;
extern f32 lbl_80561650;