// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
#include <stdarg.h>
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

extern s32 lbl_8032E1A0[];
extern f32 lbl_80561648;
extern f32 lbl_8056171C;
extern f32 lbl_805616CC;
extern s32 lbl_8055E244;
extern s32 lbl_8055E248;
extern s32 lbl_8055E250;
extern void *lbl_8055E268;
extern u8 lbl_8032D970[];

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
    virtual void d0();
    virtual void d1();
    virtual void *open(char *);
    virtual int has(char *);
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void *next(char *);
    virtual s32 get(char *, s32);
};
#pragma cplusplus off
extern void fn_802E30C8();
extern u8 lbl_8032D358[];
extern void *fn_80131808(void *, s32, s32);
extern void fn_80131818(void *);
extern void *fn_8012850C(s32, void *);
extern s32 fn_801345D8(char *, s32, char *, s32);
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

void fn_80149210(int *p) {
    p[1] = (p[1] + 1) % 4;
}

s32 fn_80149234(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93D0;
    return sp8.v[((s32 *)arg0)[1]];
}

extern s32 fn_8014D918(void*, s32, s32);
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
    do {
        fn_80130980(&sp8, 0x20, 3);
        fn_801474EC(arg0, &lbl_80559EC4, &sp8);
    } while (0);
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

#pragma cplusplus on
extern "C" void fn_80149CEC(void *arg0, void *arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void* f2();
    };
    void *r5 = *(void **)((u8 *)arg1 + 0x68);
    void *r3;
    s32 val;
    *(volatile f32 *)((u8 *)arg0 + 0x28) = *(volatile f32 *)((u8 *)r5 + 0x8D4);
    r3 = *(void **)((u8 *)fn_8017960C(*(s32 *)arg1) + 0x270);
    r3 = ((Dummy *)r3)->f2();
    val = *(s32 *)((u8 *)r3 + 4);
    *(s32 *)((u8 *)arg0 + 4) = val;
    *(s32 *)((u8 *)arg0 + 0x10) = val - 1;
    fn_80149D64(arg0, arg1, val);
}
#pragma cplusplus reset
extern f32 fn_80149F00(void *, void *);
extern s32 fn_801609C4(s32);
void fn_80149D64(void *arg0, void *arg1, s32 arg2) {
    int index;
    f32 rate;
    int value;
    int count;
    void *object;
    f32 end;
    if (*(u8 *)((char*)arg0+0x34) != 0) index = 0;
    else {
        f32 frame = *(f32*)((char*)arg1+0x14);
        index = (int)(frame < lbl_80561648 ? frame-lbl_8056163C : lbl_8056163C+frame);
    }
    *(int*)arg0 = index;
    if (fn_80179650() > 1) {
        rate = fn_80149F00(arg0,arg1);
        value = *(int*)((char*)arg0+0x10) == 0
            ? *(int*)((char*)arg0+0x14) + (int)((f32)*(int*)((char*)arg0+0x18) * rate)
            : 0;
        if (value != *(int*)((char*)arg0+0x20)) {
            object = *(void**)((char*)arg1+8);
            if (object != 0 && *(void**)((char*)object+0x1258) != 0) {
                char *p = *(char**)((char*)object+0x1258);
                p[0x49]=1; p[0x4b]=0; p[0x4a]=0;
            }
        }
        *(int*)((char*)arg0+0x20)=value;
    } else {
        count = *(int*)((char*)arg0+0x10);
        value = count >= 0 && count < *(int*)((char*)arg0+0xc)
            ? *(int*)(*(char**)((char*)arg0+8)+count*4) : 0;
        *(int*)((char*)arg0+0x20)=value;
    }
    object=*(void**)((char*)arg1+0x68);
    end=*(f32*)((char*)object+0x8dc)-*(f32*)((char*)object+0x8d4);
    if (end < lbl_80561648) end=lbl_80561648;
    *(int*)((char*)arg0+0x24)=*(int*)arg0+*(int*)((char*)arg0+0x20);
    *(int*)((char*)arg0+0x1c)=(int)end;
    *(int*)((char*)arg0+0x30)=fn_801609C4(*(int*)((char*)arg0+0x24));
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
extern void fn_80149658(s32, void *, void *, s32);
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

void fn_8014C72C(void **arg0) {
    void * volatile *vtable = (void * volatile *)*arg0;
    ((void (*)(void))vtable[3])();
    fn_801476C4();
}

f32 fn_8014C75C(f32 *arg0, const f32 *arg1) {
    f32 v0 = arg1[0];
    f32 v1 = arg1[1];
    arg0[0] = v0;
    arg0[1] = v1;
    return v0;
}

#pragma scheduling invalid_target
s64 fn_8014C770(f32 *arg0, f32 *arg1, f32 t) {
    union { struct { f32 x, y; } f; s64 bits; } out;
    volatile f32 *a = (volatile f32 *)arg0;
    volatile f32 *b = (volatile f32 *)arg1;
    f32 y1 = b[1];
    f32 y0 = a[1];
    f32 x1 = b[0];
    f32 x0 = a[0];
    out.f.y = y0 + t * (y1 - y0);
    out.f.x = x0 + t * (x1 - x0);
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
    t = (t < lbl_80561648) ? t : lbl_80561648;
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
    void *temp_r5_2;
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
    temp_r5_2 = *(void **)((u8 *)arg0 + 0x68);
    index = *(s32 *)arg0;
    if (*(u8 *)((u8 *)temp_r5_2 + 0x8F4) != 0) {
        var_r6 = *(s32 *)((u8 *)temp_r5_2 + 0x8F4 + index * 0x1C + 8);
    } else {
        var_r6 = 0;
    }
    fn_80149658(arg1, (void *)((u8 *)arg0 + 0x6C), *(void **)((u8 *)arg0 + 0xC), var_r6);
}

void fn_8014D794(void *arg0, void *arg1) {
    fn_801E7E18();
    if (*(u8 *)((u8 *)arg0 + 0xA0) == 0) {
        if (fn_800167F4() == 2) {
            f32 values[4];
            values[0] = lbl_80561688;
            values[1] = lbl_805616C0;
            values[2] = lbl_805616C4;
            values[3] = lbl_80561648;
            if (*(s32 *)((u8 *)arg1 + 8) != 0) {
                fn_802AE220(values);
            }
        } else if (*(s32 *)((u8 *)arg1 + 8) != 0) {
            fn_802AE220(0);
        }
    }
    (void)(*(f32 *)((u8 *)arg0 + 0x64) >= lbl_80561648);
}

#pragma cplusplus reset
s32 fn_8014D918(void *arg0, s32 arg1, s32 arg2) {
    void **accessor=(void **)arg1; void *a,*b,*obj; u8 storage[0x1C];
    f32 t,d,time,vals[7],x,y,w,h;
    obj=*(void **)((u8 *)arg0+0x68); t=lbl_80561648;
    d=*(f32 *)((u8 *)obj+0x8DC)-*(f32 *)((u8 *)obj+0x8D4); if(t>d)t=d;
    if(d<lbl_8056164C)return 0;
    fn_801345D8((char *)storage,0x64,(char *)lbl_8032D358+0x384,arg2);
    a=((void *(*)(void *,void *))(*(void ***)accessor)[5])(accessor,storage);
    fn_801345D8((char *)storage,0x64,(char *)lbl_8032D358+0x398,arg2);
    b=((void *(*)(void *,void *))(*(void ***)accessor)[5])(accessor,storage);
    fn_80149F00((u8 *)arg0+0x6C,arg0);
    if(!a||!b)return 0;
    time=(f32)fn_8002EFB4(lbl_805616A0,0.0);
    *(s32 *)&vals[0]=*(s32 *)a; vals[1]=*(f32 *)((u8 *)a+4); vals[2]=*(f32 *)((u8 *)a+8);
    *(s32 *)&vals[3]=*(s32 *)((u8 *)a+0xC); vals[4]=*(f32 *)((u8 *)a+0x10); vals[5]=*(f32 *)((u8 *)a+0x14);
    *(s32 *)&vals[6]=*(s32 *)((u8 *)a+0x18);
    if(time<lbl_8056163C){
        x=(time-lbl_80561648)/lbl_805616C8;
        if(lbl_8056164C<x)x=lbl_8056164C;if(x<lbl_80561648)x=lbl_80561648;
        *(s32 *)&vals[6]=fn_80147C50(*(s32 *)((u8 *)a+0x18),*(s32 *)((u8 *)a+0x18),lbl_80561648+x*lbl_8056164C,0,0,0);
    }else{
        x=lbl_80561670*time-lbl_8056164C;y=lbl_8056164C-x;w=x*x;h=lbl_8056164C-y*y;
        vals[1]+=h*(*(f32 *)((u8 *)b+4)-vals[1]); vals[2]+=w*(*(f32 *)((u8 *)b+8)-vals[2]);
        vals[4]+=w*(*(f32 *)((u8 *)b+0x10)-vals[4]); vals[5]+=w*(*(f32 *)((u8 *)b+0x14)-vals[5]);
        *(s32 *)&vals[6]=fn_80147C50(*(s32 *)((u8 *)a+0x18),*(s32 *)((u8 *)b+0x18),x,vals[5],h,w);
    }
    return fn_80147940(accessor,vals,(char *)lbl_8032D358+0x27C,0);
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
        register u8 *vtableBase = (u8 *)lbl_8032D970;
        void **table = (void **)obj;
        table[0] = vtableBase;
        void *initFn = fn_8014E4BC;
        table[1] = vtableBase + 0x100;
        void *cleanupFn = fn_8014E3CC;
        table[2] = vtableBase + 0x11C;
        table[3] = vtableBase + 0x130;
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
        ((void (*)(void *, void *, void *, s32, s32, s32, void *))fn_8002F53C)(obj + 0x454, fn_8014E4BC, fn_8014E3CC, 0x240, 2, vectorSize, obj + 0x338);
        LfoObj *lfo = *(LfoObj **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        f64 value = lfo->eval((void *)(strings + 0x344), lbl_805616CC);
        *(volatile f32 *)(obj + 0x8DC) = value;
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
extern "C" void *fn_8014E1D0(void *arg0, s32 arg1) {
    void *table;
    Iter_8014E1D0 *iter;
    char name[0x64];
    s32 count;
    s32 i;
    void **items;
    *(void **)((u8 *)arg0 + 0x74) = 0;
    *(s32 *)((u8 *)arg0 + 0x78) = 0;
    *(s32 *)((u8 *)arg0 + 0x7c) = -1;
    *(s32 *)((u8 *)arg0 + 0x80) = 1;
    *(s32 *)((u8 *)arg0 + 0x84) = 1;
    table = fn_80131808(lbl_8032D358 + 0x4c8, -1, 0);
    if (table != 0) {
        iter = (Iter_8014E1D0 *)((Iter_8014E1D0 *)table)->open((char *)(lbl_8032D358 + 0x4d8));
        if (iter != 0) {
            *(s32 *)((u8 *)arg0 + 0x78) = 1;
            do { fn_801345D8(name, 0x64, (char *)(lbl_8032D358 + 0x4e4), *(s32 *)((u8 *)arg0 + 0x78)); }
            while (iter->has(name) != 0 && ++*(s32 *)((u8 *)arg0 + 0x78));
            count = *(s32 *)((u8 *)arg0 + 0x78);
            items = (void **)fn_8012850C((count + 1) * 4, lbl_8032D358 + 0x4f0);
            *(void ***)((u8 *)arg0 + 0x74) = items;
            for (i = 0; i < count - 1; i++) {
                fn_801345D8(name, 0x64, (char *)(lbl_8032D358 + 0x4e4), i + 1);
                items[i] = iter->next(name);
            }
            items[count - 1] = 0;
            *(s32 *)((u8 *)arg0 + 0x80) = iter->get((char *)(lbl_8032D358 + 0x500), *(s32 *)((u8 *)arg0 + 0x80));
            *(s32 *)((u8 *)arg0 + 0x84) = iter->get((char *)(lbl_8032D358 + 0x50c), *(s32 *)((u8 *)arg0 + 0x84));
        }
        fn_80131818(table);
    }
    if (*(void **)((u8 *)arg0 + 0x74) == 0) {
        fn_802E30C8();
        items = (void **)fn_8012850C(4, lbl_8032D358 + 0x4f0);
        *(void ***)((u8 *)arg0 + 0x74) = items; *items = 0;
        *(s32 *)((u8 *)arg0 + 0x78) = 1;
    }
    return arg0;
}
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

extern void *memset(void *, s32, s32);
void *fn_8014E4BC(void *arg0) {
    u8 *base = (u8*)arg0;
    u8 *p;
    u8 *end;
    *(u32*)(base + 8) = 0; *(u32*)(base + 0x10) = 0;
    *(u32*)(base + 0x14) = 0; *(u32*)(base + 0x18) = 0;
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
s32 fn_8014E708(s32 arg0) {
    u8 *base = (u8 *)lbl_8055E268;
    if (base != 0) {
        volatile void *obj = *(void **)(base + arg0 * 0xC0 + 0x9F4);
        volatile void **vt = *(volatile void ***)obj;
        return ((s32 (*)(void))vt[14])();
    }
    return 0;
}

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
#pragma scheduling invalid_target
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
        ((u8 *)arg0)[0x450] = 0;
    }
}
#pragma scheduling on
s32 fn_80151604(void) { return 0; }

s32 fn_8015160C(void) {
    if (fn_80161C38() != 0) {
        return 0x5608;
    }
    return (fn_80179650() > 1 ? 0x160B : 0x564B) & 0xFFFFFFBF;
}

void fn_80151654(void *a0, void *a1, s32 selector) {
    s32 index;
    void *obj;
    if (selector != 0x3EB) return;
    index = *(s32 *)((char *)a1 + 0x1EC);
    obj = (char *)a0 + index * 0xC0;
    obj = (char *)obj + 0x9E4;
    if (obj == 0) return;
    obj = *(void **)((char *)obj + 0x10);
    (*(void (**)(void))(*(char **)obj + 0x24))();
}

void fn_80151688(void) {

}

extern f32 PSVECMag(void *);
#pragma cplusplus on
extern "C" void fn_8015180C(void *ctx, void *a, void *b, void *unused, void *vec) {
    f32 mag = PSVECMag(vec);
    s32 first = 1;
    s32 second = 1;
    if (*(s32 *)((u8 *)a + 0x1F0) == 0x50 && *(s32 *)((u8 *)b + 0x1F0) == 0x50) {
        first = *(f32 *)((u8 *)a + 0x25D4) > *(f32 *)((u8 *)b + 0x25D4);
        second = !first;
    }
    if (first) {
        void *slot = (u8 *)ctx + *(s32 *)((u8 *)a + 0x1EC) * 0xC0 + 0x9E4;
        if (slot) ((Dummy_8015180C *)*(void **)((u8 *)slot + 0x10))->call(*(s32 *)((u8 *)b + 0x1EC), mag);
    }
    if (second) {
        void *slot = (u8 *)ctx + *(s32 *)((u8 *)b + 0x1EC) * 0xC0 + 0x9E4;
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

s32 fn_80151984(void *arg0, s32 arg1, s32 arg2) {
    s32 count;
    s32 i;
    void *object;
    void **vtable;
    s32 (*check)(void *);

    if (arg2 == 0x58) {
        vtable = *(void ***)arg0;
        check = (s32 (*)(void *))vtable[0x1A];
        if (check(arg0) != 0) {
            count = fn_801E85A4();
            object = arg0;
            for (i = 0; i < count; i++) {
                if (*((u8 *)arg0 + fn_801E86F8(i) * 0xC0 + 0xA84) == 0) {
                    if (count > 1) {
                        *(s32 *)((u8 *)object + 0x454) = 4;
                    } else if (*(s32 *)((u8 *)object + 0x454) == 2) {
                        *((u8 *)object + 0x460) = 1;
                    }
                }
                object = (u8 *)object + 0x240;
            }
        }
    }
    return 0;
}

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
void fn_80151B48(void *arg0) {
    s32 self = fn_801E85B4();
    s32 index = fn_801E866C(self);
    s32 i, j;
    s32 flag;
    void *entry;
    void *obj;
    void *p;
    f32 f;

    if (((s32 (*)(s32, s32))((void **)self)[5])(self, index) == 0) goto done;
    if (self + index * 0xC0 + 0x9E4 == 0) goto done;
    if (*(s32 *)(self + index * 0xC0 + 0x9E4 + 4) == 0) {
        flag = 0;
    } else if (*(s32 *)(self + index * 0xC0 + 0x9E4 + 4) == 1) {
        flag = 1;
    } else {
        flag = (f32)__fabs((f64)(*(f32 *)(self + index * 0xC0 + 0x9E4 + 0x1C) - lbl_8056164C)) <= lbl_80558DC4[0];
    }
    i = 0;
    j = 0;
    while (i < *(s32 *)(self + 0x18)) {
        entry = *(void **)(*(s32 *)(self + 0x14) + j);
        f = ((f32 *)entry)[0x34 / 4];
        if (fn_80141F7C(f) != 0 && flag != 0 && ((u8 *)entry)[0xCC] != 0) {
            fn_801495D4(0x40);
            obj = fn_801538E4(entry);
            p = fn_801538E4(entry);
            fn_801537CC(*(s32 *)((char *)p + 4), *(s32 *)obj, f);
            fn_80151C98(entry, (s32)obj);
        }
        j += 4;
        i += 1;
    }
done:
    fn_80167844();
    fn_8016A438();
}

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
extern void fn_802C86DC(void);
extern void fn_802C77F0(void *, f32 *);
extern void fn_802C744C(s32, f32 *);
extern void *fn_801E87A8(void);
extern s32 lbl_80559ED4, lbl_80559ED8;
extern f32 lbl_8056163C, lbl_80561648, lbl_8056164C, lbl_805616B8;
void fn_801533E8(void *arg0, f32 *arg1) {
    f32 values[12];
    f32 out[3];
    f32 mat[12];
    f32 x, y, z, a, b, c;
    s32 i;
    fn_802C86DC();
    for (i = 0; i < 12; i++) values[i] = ((f32 *)arg1)[i];
    fn_802C77F0(*(void **)arg1, values);
    x = values[0] + (values[1] - values[0]) * lbl_8056163C;
    y = values[2] + (values[3] - values[2]) * lbl_8056163C;
    z = values[4] + (values[5] - values[4]) * lbl_8056163C;
    a = x * lbl_805616B8;
    b = y * lbl_805616B8;
    c = z * lbl_805616B8;
    out[0] = a; out[1] = b; out[2] = c;
    out[0] = a * values[8] + b * values[0] + c * values[4];
    out[1] = a * values[9] + b * values[1] + c * values[5];
    out[2] = a * values[10] + b * values[2] + c * values[6];
    for (i = 0; i < 12; i++) mat[i] = values[i] * lbl_8056164C;
    if ((*(u32 *)((u8 *)fn_801E87A8() + 0x10) & 2) != 0) {
        values[0] = -values[0]; values[1] = -values[1]; values[2] = -values[2];
        mat[0] = -mat[0]; mat[1] = -mat[1]; mat[2] = -mat[2];
    }
    fn_802C744C(lbl_80559ED8, mat);
    fn_802C744C(lbl_80559ED4, values);
}

#pragma pop
void fn_801537C8(void) {

}

s32 fn_801537CC(s32 arg0, s32 arg1, f32 t) {
    u8 *a = (u8 *)&arg0;
    u8 *b = (u8 *)&arg1;
    s8 out0 = (s8)(a[0] + t * ((f32)b[0] - (f32)a[0]));
    s8 out1 = (s8)(a[1] + t * ((f32)b[1] - (f32)a[1]));
    s8 out2 = (s8)(a[2] + t * ((f32)b[2] - (f32)a[2]));
    s8 out3 = (s8)(a[3] + t * ((f32)b[3] - (f32)a[3]));
    u8 *dst = (u8 *)&arg0;
    dst[0] = out0; dst[1] = out1; dst[2] = out2; dst[3] = out3;
    return arg0;
}

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
#pragma scheduling invalid_target
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
#pragma scheduling on
void fn_80155368(void) {

}

extern s32 fn_80161BB8(void);
extern s32 lbl_80559EC0;
#pragma push
#pragma use_lmw_stmw on
void fn_8015536C(void *arg0, void *arg1, s32 index) {
    s32 offset=index*0xC0;
    u8 *p=(u8*)arg0+offset;
    s32 state=*(s32 *)((u8 *)(p)+0x9E8);
    s32 count,positive,id,j,i,flag;
    u8 *entry,*flags,*owner,*node,*next,*prev,*obj;
    if(state==0)flag=0;
    else if(state==1)flag=1;
    else flag=(f32)__fabs(*(f32 *)((u8 *)(p)+0xA00)-lbl_8056164C)<=lbl_80558DC4[0];
    if(flag){
        i=0;j=0;
        while(i<*(s32 *)((u8 *)(arg0)+0x18)){
            entry=*(u8**)(*(u8* *)((u8 *)(arg0)+0x14)+j);
            id=*(s32 *)((u8 *)(entry)+0xC0);
            if(id==((s32(*)(void*,void*))(*(void***)arg1)[9])(arg1,entry)){
                entry=*(u8**)(*(u8* *)((u8 *)(arg0)+0x14)+j);
                if((f32)__fabs(*(f32 *)((u8 *)(entry)+0x34))<=lbl_80558DC4[0]){
                    if((f32)__fabs(*(f32 *)((u8 *)(lbl_804348E8[index])+0x2690))<=lbl_80558DC4[0] && fn_80161BB8()==0)
                        entry[index+0xC4]=1;
                }
            }
            j+=4;i++;
        }
    }
    if(((s32(*)(void*))(*(void***)arg1)[8])(arg1)==0x73){
        positive=*(f32 *)((u8 *)(lbl_804348E8[index])+0x25BC)>lbl_80558DC4[0];
        p=(u8*)arg0+offset;
        flags=p+0xA8C;
        if(*flags){
            obj=*(u8* *)((u8 *)(p)+0x9F4);
            ((void(*)(void*,s32))(*(void***)obj)[15])(obj,lbl_804348E8[*(s32 *)((u8 *)(p)+0x9E4)]);
        }
        if(flags[1]){
            p=(u8*)arg0+offset;
            *(f32 *)((u8 *)(p)+0xA20)=lbl_80561648;
            *(f32 *)((u8 *)(p)+0xA00)=lbl_8056163C**(f32 *)((u8 *)(p)+0xA00);
            *(s32 *)((u8 *)(p)+0xA88)=0;
            owner=*(u8* *)((u8 *)(p)+0x9EC);
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
            p=(u8*)arg0+offset;
            *(f32 *)((u8 *)(p)+0x9F8)=*(f32 *)((u8 *)(p)+0x9F8)+lbl_80561648;
            obj=*(u8* *)((u8 *)(p)+0x9F4);
            ((void(*)(void*))(*(void***)obj)[4])(obj);
            p=(u8*)arg0+offset;
            if(*(s32 *)((u8 *)(p)+0xA18)>1)*(f32 *)((u8 *)(p)+0xA24)=lbl_80561688;
            count=*(s32 *)((u8 *)(p)+0xA18)-1;
            *(s32 *)((u8 *)(p)+0xA18)=count>1?count:1;
            p=(u8*)arg0+offset;
            *(f32 *)((u8 *)(p)+0xA34)=lbl_80561648;
            *(f32 *)((u8 *)(p)+0xA30)=lbl_80561648;
            *(f32 *)((u8 *)(p)+0xA2C)=lbl_80561648;
            *(f32 *)((u8 *)(p)+0xA28)=lbl_80561648;
        }
        if(positive){
            if(lbl_80559EC0==1)flags[2]=1;
            if(lbl_80559EC0==3){flags[3]=1;flags[1]=1;}
        }
        obj=*(u8* *)((u8 *)((u8*)arg0+offset)+0x9F4);
        ((void(*)(void*,s32))(*(void***)obj)[13])(obj,lbl_804348E8[*(s32 *)((u8 *)(p)+0x9E4)]);
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
    void *node;
    void *next;
    void *prev;
    void *tail;
    s32 zero = 0;
    s32 one = 1;

    node = *(void **)((u8 *)arg0 + 0x1244);
    if (node == 0) {
        return 0;
    }
    next = *(void **)((u8 *)node + 0x120);
    if (next != 0) {
        *(void **)((u8 *)next + 0x11C) = *(void **)((u8 *)node + 0x11C);
    } else {
        *(void **)((u8 *)arg0 + 0x1244) = *(void **)((u8 *)node + 0x11C);
    }
    prev = *(void **)((u8 *)node + 0x11C);
    if (prev != 0) {
        *(void **)((u8 *)prev + 0x120) = *(void **)((u8 *)node + 0x120);
    } else {
        *(void **)((u8 *)arg0 + 0x1248) = *(void **)((u8 *)node + 0x120);
    }
    *(void **)((u8 *)node + 0x120) = 0;
    *(void **)((u8 *)node + 0x11C) = 0;
    *(void **)((u8 *)node + 0x120) = *(void **)((u8 *)arg0 + 0x1250);
    tail = *(void **)((u8 *)arg0 + 0x1250);
    if (tail != 0) {
        *(void **)((u8 *)tail + 0x11C) = node;
    }
    *(void **)((u8 *)arg0 + 0x1250) = node;
    if (*(void **)((u8 *)arg0 + 0x124C) == 0) {
        *(void **)((u8 *)arg0 + 0x124C) = node;
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
    *(s32 *)((u8 *)node + 0x108) = zero;
    *(s32 *)((u8 *)node + 0x114) = one;
    return node;
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
extern "C" void fn_8014FB7C(void *arg0) {
    class VObj { public: virtual void d0(s32); };
    VObj *p;
    u8 *base = (u8 *)arg0;
    p = *(VObj **)(base + 0x9D8);
    if (p != 0) {
        if (p != 0) p->d0(1);
        *(VObj **)(base + 0x9D8) = 0;
    }
    s32 i;
    u8 *obj;
    i = 1;
    obj = base + 0x240;
    do {
        if (*(void **)(obj + 0x45C) != 0) {
            fn_802ADE60((void **)(obj + 0x45C), 1);
            *(s32 *)(obj + 0x45C) = 0;
        }
        p = *(VObj **)(obj + 0x464);
        if (p != 0) { if (p != 0) p->d0(1); *(VObj **)(obj + 0x464) = 0; }
        p = *(VObj **)(obj + 0x468);
        if (p != 0) { if (p != 0) p->d0(1); *(VObj **)(obj + 0x468) = 0; }
        p = *(VObj **)(obj + 0x46C);
        if (p != 0) { if (p != 0) p->d0(1); *(VObj **)(obj + 0x46C) = 0; }
        i--;
        obj -= 0x240;
    } while (i >= 0);
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
