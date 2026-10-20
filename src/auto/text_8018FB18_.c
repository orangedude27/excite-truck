// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef signed char schar;
typedef unsigned char uchar;
typedef signed short sshort;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef struct { u8 pad[7]; u8 low:5; u8 index:3; } Fn8019150CState;

extern int fn_801B526C(void);
extern int fn_801769F8(void);

extern void *lbl_804349A0[];
extern int lbl_8055E518;
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_80562094, lbl_805620AC, lbl_80562138;
extern double lbl_805620B0;
int fn_801B665C();
void fn_80191084();
void fn_801B6650();
int fn_80191100(void *);
extern int lbl_8055E3C4;
extern int lbl_8055E524;
extern unsigned char lbl_8055E521;
extern void *__AXGetStudio_80178C90(void);
extern int fn_801B2F54(int);
extern float fn_8018AE3C(void *);
extern float fn_8018AE4C(void *);
void fn_802793B0();
extern int lbl_8055E524;
extern s32 fn_80137C74(void);
extern s32 fn_80128670(s32);
extern s32 fn_8012850C(s32, const char *);
extern s32 fn_802E30C8(const char *, s32);
extern s32 lbl_804349B0;
extern char lbl_80332E94[];
extern char lbl_80332EA0[];
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void **fn_801B83A0(void);
extern u8 lbl_8055E522;
extern s32 lbl_80332E70;
extern s32 lbl_80332E80;
extern s32 lbl_8055A470;
extern s32 fn_80134E90(void);
extern s32 fn_80134EC8(void);
extern s32 fn_80135078(void);
extern s32 fn_801284F8(s32, s32 *);
extern s32 fn_801912B4(void);
extern s32 fn_8018FD88(s32, s32);
extern s32 fn_801A520C(s32);
void fn_8018FB18(void) {
    s32 value;
    u32 *table = (u32 *)__AXFXGetLfoSinTable_801769CC();
    s32 mode = ((s32 (*)(void))(*(void ***)fn_801B83A0())[0xEC / 4])();
    value = mode;
    lbl_8055E522 = (table[1] >> 8) & 1;
    if ((table[1] - 0x18000000) == 0x304) lbl_8055E522 = 0;
    if (mode == 0) {
        if (table[1] & 0x100) value = fn_80134E90();
        else if ((table[1] - 0x18000000) == 0x201) value = fn_80134EC8();
        else value = fn_80135078();
    }
    {
        s32 ptr = fn_801284F8(0x44, &lbl_80332E70);
        if (ptr != 0) ptr = fn_801912B4();
        {
            s32 obj = fn_801284F8(0x3C, &lbl_8055A470);
            if (obj != 0) obj = fn_8018FD88(value, ptr);
            if (fn_801284F8(0x2844, &lbl_80332E80) != 0) fn_801A520C(obj);
        }
    }
}

void fn_8018FC38(void) {
    s32 count = fn_80137C74();
    s32 *p = &lbl_804349B0;
    s32 i = 0;
    while (i < count) {
        *p = fn_8012850C(0x46500, lbl_80332E94);
        p++;
        i++;
    }
    fn_802E30C8(lbl_80332EA0, ((u32)(count * 0x8CA0) >> 7) & 0x3FFFFF);
}

void fn_8018FCC4(void) {
    s32 count = fn_80137C74();
    s32 *p = &lbl_804349B0;
    s32 i = 0;
    while (i < count) {
        fn_80128670(*p);
        *p = 0;
        p++;
        i++;
    }
}

int fn_8018FD38(void) {
    int result = 0;
    if (lbl_8055E3C4 + 1 >= lbl_8055E524 || fn_801B89E0() != 0) result = 1;
    return result;
}

  extern char lbl_80333018[];
  extern int fn_801B6668(void *);
  extern void fn_801B6654(void);
  #define fn_80128668_void() ((void (*)(void))fn_80128668)()
  #define fn_80128668_void_star(p) fn_80128668(p)
#pragma cplusplus on
class DummyVtable8018FE8C {
public:
    virtual void d0(int);
    virtual void d1(int);
    virtual void d2(int);
    virtual void d3(int);
    virtual void d4(int);
    virtual void d5(int);
    virtual void d6(int);
    virtual void d7(int);
    virtual void d8(int);
    virtual void d9(int);
    virtual void d10(int);
    virtual void d11(int);
    virtual void d12(int);
    virtual void d13(int);
    virtual void d14(int);
    virtual void d15(int);
    virtual void d16(int);
    virtual void d17(int);
    virtual void d18(int);
    virtual void d19(int);
    virtual void d20(int);
    virtual void d21(int);
    virtual void d22(int);
    virtual void d23(int);
    virtual void d24(int);
    virtual void d25(int);
    virtual void d26(int);
    virtual void d27(int);
    virtual void d28(int);
    virtual void d29(int);
    virtual void d30(int);
    virtual void d31(int);
    virtual void d32(int);
};
extern "C" void *fn_8018FE8C(void *arg0, s32 arg1) {
    class Obj {
    public:
        virtual void v0(int);
        virtual void v1(int);
        virtual void v2(int);
        virtual void v3(int);
        virtual void v4(int);
        virtual void v5(int);
        virtual void v6(int);
        virtual void v7(int);
        virtual void v8(int);
        virtual void v9(int);
        virtual void v10(int);
        virtual void v11(int);
        virtual void v12(int);
        virtual void v13(int);
        virtual void v14(int);
        virtual void v15(int);
        virtual void v16(int);
        virtual void v17(int);
        virtual void v18(int);
        virtual void v19(int);
        virtual void v20(int);
        virtual void v21(int);
        virtual void v22(int);
        virtual void v23(int);
        virtual void v24(int);
        virtual void v25(int);
        virtual void v26(int);
        virtual void v27(int);
        virtual void v28(int);
        virtual void v29(int);
        virtual void v30(int);
        virtual void v31(int);
        virtual void v32(int);
    };
    void (*fn_80128668_ptr)(void *) = (void (*)(void *))0x80128668;
    s32 temp_r0;
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80333018;
        if (fn_801B6668(arg0) != 0) fn_801B6654();
        obj = *(void **)((char *)arg0 + 4);
        if (obj != 0) ((Obj *)obj)->v32(1);
        obj = *(void **)((char *)arg0 + 8);
        *(void **)((char *)arg0 + 4) = 0;
        if (obj != 0) ((Obj *)obj)->v2(1);
        obj = *(void **)((char *)arg0 + 0xC);
        *(void **)((char *)arg0 + 8) = 0;
        if (obj != 0) ((Obj *)obj)->v2(1);
        *(void **)((char *)arg0 + 0xC) = 0;
        temp_r0 = lbl_8055E518 - 1;
        lbl_8055E518 = temp_r0;
        if (temp_r0 == 0) { void (*cleanup)(void) = fn_8018FCC4; cleanup(); }
        if (arg1 > 0) fn_80128668_ptr(arg0);
    }
    return arg0;
}
#pragma cplusplus off

int fn_8018FF84(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80190184(void *arg0, void *arg1) {
    *(void **)((char *)arg0 + 0x20) = arg1;
    *(int *)((char *)arg0 + 0x1c) = *(int *)((char *)arg1 + 0x1ec);
    ((void (*)(void *))(*(void ***)(*(void **)((char *)arg0 + 8)))[4])(*(void **)((char *)arg0 + 8));
    ((void (*)(void *, void *))(*(void ***)(*(void **)((char *)arg0 + 0xc)))[4])(*(void **)((char *)arg0 + 0xc), arg1);
}

int fn_801901F0(void *arg0) {
    int result;
    if (fn_801B526C() == 0) {
        if (*(void **)((char *)arg0 + 4) != 0 && fn_801769F8() != 0) {
            void *obj = *(void **)((char *)arg0 + 4);
            (*(int (**)(void *, int))(*(char **)obj + 0x78))(obj, 0);
        }
        if (*(void **)((char *)arg0 + 0x10) != 0) {
            void *obj = *(void **)((char *)arg0 + 0x10);
            result = (*(int (**)(void *))(*(char **)obj + 0x14))(obj);
            if (*(unsigned char *)((char *)arg0 + 0x34) == 0)
                result |= 0x10;
            if (lbl_8055E521 != 0)
                result |= 0x100;
        } else {
            result = 4;
        }
    } else {
        result = 0;
    }
    return result;
}

#pragma cplusplus on
extern "C" void fn_801902A0(void *arg0) {
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
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
        virtual void f27();
        virtual void f28();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f28();
}
#pragma cplusplus on
void fn_801902B4(void *arg0) {
    unsigned int temp_r3;
    int (*callback)(void *);

    fn_80191084(arg0, 0);
    fn_801B6650(*(int *)((char *)arg0 + 0x20));
    callback = (int (*)(void *))fn_80191100;
    temp_r3 = callback(arg0);
    if (temp_r3 != *(unsigned int *)((char *)arg0 + 8)) {
        fn_80191084(arg0);
    } else {
        fn_80191084(arg0, *(unsigned int *)((char *)arg0 + 0xC));
    }
    fn_80191084(arg0, temp_r3);
    if (*(unsigned char *)((char *)arg0 + 0x38) != 0) {
        *(unsigned char *)((char *)arg0 + 0x38) = 0;
        fn_802793B0(*(int *)((char *)arg0 + 0x28));
    }
    ((void (**)(void *))(*(void ***)arg0))[12](arg0);
}
#pragma cplusplus off
void fn_80190360(int arg0) {
    fn_80191084(arg0, 0);
}

int fn_80190368(int arg0) {
    return (arg0 == 1) || (arg0 == 0);
}

BOOL fn_80190B60(void *arg0) {
    int bit;
    bit = (*(s8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 4) & 1;
    return (int)((u32)(-bit | bit) >> 31);
}

f32 fn_80190B7C(void *arg0) {
    f32 var_f4;
    double d;
    double d2;

    d = (double)*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 2);
    var_f4 = lbl_80562090;
    if (var_f4 < (f32)((d - lbl_805620B0) / lbl_805620AC)) {
        d2 = d - lbl_805620B0;
        var_f4 = (f32)(d2 / lbl_805620AC);
    }
    if (var_f4 > lbl_8056208C) {

    } else {
        var_f4 = lbl_8056208C;
    }
    return lbl_8056208C + (var_f4 * lbl_80562090);
}

f32 fn_80190C04(void *arg0) {
    f32 var_f4;

    var_f4 = lbl_80562090;
    if (var_f4 < (((f32)(u8)*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 3) - lbl_8056208C) / lbl_805620AC)) {
    } else {
        var_f4 = (((f32)(u8)*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 3) - lbl_8056208C) / lbl_805620AC);
    }
    if (var_f4 > lbl_8056208C) {
    } else {
        var_f4 = lbl_8056208C;
    }
    return lbl_8056208C + (var_f4 * lbl_80562090);
}

int fn_80190C8C(void *arg0) {
    return (int)(*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) & 8);
}

#pragma cplusplus on
extern "C" void fn_80190CA8(void *arg0) {
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
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
        virtual void f27();
        virtual void f28();
        virtual void f29();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f29();
}
#pragma cplusplus on
extern "C" void fn_80190CBC(void *arg0) {
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
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
        virtual void f27();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f27();
}
#pragma cplusplus off
int fn_80190CD0(float a, float b, float c) {
    float y;
    float x;
    x = a - b;
    y = lbl_80562090;
    x = c - b;
    x = (a - b) / (c - b);
    if (y >= x) {
        y = y;
    } else {
        y = x;
    }
    if (y <= lbl_8056208C) {
        y = y;
    } else {
        y = lbl_8056208C;
    }
    return (((int)(lbl_80562080 + (lbl_8056208C + (y * lbl_805620AC)))) >> 4) & 0xF;
}

extern void *lbl_804349A0[];
extern int lbl_8055E518;
int fn_801B665C();
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_805620AC;
static inline float clampf(float x, float lo, float hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}
int fn_80190D38(float a, float b, float c) {
    float lower;
    float value;
    lower = lbl_80562090;
    value = (a - b) / (c - b);
    if (lower < value) { lower = value; } else { lower = lower; }
    if (lower > lbl_8056208C) { lower = lbl_8056208C; } else { lower = lower; }
    return (int)(lbl_80562080 + (lbl_8056208C + (lower * lbl_805620AC)));
}

int fn_80190E00(void *arg0) { return ((int *)arg0)[2]; }

#pragma dont_inline on
void fn_80190E08(void) {
    int i;
    for (i = 0; i < lbl_8055E518; i++) {
        void *obj = lbl_804349A0[i];
        void **vt;
        vt = *(void ***)obj;
        ((void (*)(void **))vt[18])(vt);
    }
}
#pragma dont_inline reset

void fn_80190E6C(void) {
    fn_80190E08();
}

void fn_80190E70(void *arg0) {
    void **obj = *(void ***)((char *)arg0 + 0x10);
    if (obj != 0) {
        volatile void **vtable = (volatile void **)*obj;
        ((void (*)(void *))vtable[11])(obj);
    }
    fn_801B665C();
}

extern unsigned char lbl_8055E520;
extern int fn_801CF050(int);
extern int fn_801B6658(void);
extern float lbl_805620BC;
void fn_80190EAC(void *arg0) {
    s32 zero = 0;
    s32 one = 1;
    void *obj;
    *(u8 *)((char *)arg0 + 0x25) = zero;
    *(u8 *)((char *)arg0 + 0x26) = (u8)(zero == 0);
    *(u8 *)((char *)arg0 + 0x24) = one;
    lbl_8055E520 = zero;
    obj = *(void **)((char *)arg0 + 4);
    if (fn_801CF050(one) != 0) {
        *(s32 *)((char *)obj + 0xC) = zero;
        lbl_8055E524 = zero;
    }
    *(s32 *)((char *)obj + 8) = *(s32 *)((char *)obj + 0x18);
    obj = *(void **)((char *)arg0 + 8);
    ((void (**)(void))(*(void **)obj))[12]();
    obj = *(void **)((char *)arg0 + 0xC);
    ((void (**)(void))(*(void **)obj))[12]();
    fn_80191084(arg0, 0);
    fn_80191084(arg0, fn_80191100(arg0));
    fn_801B6658();
    *(u8 *)((char *)arg0 + 0x34) = 0;
    *(f32 *)((char *)arg0 + 0x30) = lbl_8056208C;
    *(u8 *)((char *)arg0 + 0x34) = 1;
    *(f32 *)((char *)arg0 + 0x2C) = lbl_805620BC;
}

void fn_80190F90(void) {
    fn_80191758();
}

#pragma cplusplus on
extern "C" void fn_80190F94(void *arg0) {
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
    };
    VTable *obj = *(VTable **)((char *)arg0 + 0x10);
    obj->f12();
}
#pragma cplusplus off
void fn_80191060(void) {
    fn_801B6664();
}

void fn_80191064(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x10);
    if (obj != 0) {
        void **vtable = *(void ***)obj;
        void (*call)(void *) = (void (*)(void *))vtable[17];
        call(obj);
    }
}

void fn_80191084(void *arg0, void *arg1) {
    void *volatile old = *(void **)((char *)arg0 + 0x10);
    if (arg1 != old) {
        if (old != 0) {
            ((void (**)(void *))*(void **)old)[10](old);
        }
        *(void **)((char *)arg0 + 0x10) = arg1;
        if (arg1 != 0) {
            ((void (**)(void *))*(void **)arg1)[9](arg1);
        }
    }
}

int fn_80191100(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_80191108(void *arg0, int arg1) {
    void *base = arg0;
    int amount = arg1;
    int result = ((int (**)(void *))(*(void ***)((char *)base + 0xC)))[6](*(void **)((char *)base + 0xC));
    return result + ((int (**)(void *, int))(*(void ***)*(void **)((char *)base + 8)))[6](*(void **)((char *)base + 8), amount + result);
}

#pragma processor 750
void fn_80191178(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4, f32 arg5) {
    s32 x, y, dx, dy;
    void *obj;

    obj = *(void **)((u8 *)arg0 + 0xC);
    ((void (*)(void *, s32, s32, s32 *, s32 *))(*(void ***)obj)[7])(obj, arg1, arg2, &x, &y);
    obj = *(void **)((u8 *)arg0 + 8);
    ((void (*)(void *, s32, s32, s32 *, s32 *, f32))(*(void ***)obj)[7])(obj, arg1 + x, arg2 + y, &dx, &dy, arg5);
    *arg3 = x + dx;
    *arg4 = y + dy;
    fn_801B6660(y);
    *(u8 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x260C) = 0;
}
#pragma reset
s32 fn_80191240(void *arg0, s32 arg1) {
    void *obj;
    s32 temp;
    obj = *(void **)((char *)arg0 + 0xC);
    temp = arg1 + ((s32 (**)(void))(*(void ***)obj))[8]();
    obj = *(void **)((char *)arg0 + 8);
    return temp + ((s32 (**)(s32))(*(void ***)obj))[8](temp) - arg1;
}

extern int lbl_8055A480;
extern void *memset(void *, int, unsigned int);
extern int fn_801331C4(void *, void *);
extern char lbl_80332FC4;
extern int fn_80128668(void);
#pragma push
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
#pragma pop
void fn_8019150C(void *arg0, int arg1) {
    void *obj = *(void **)((char *)arg0 + 4);
    void *state;
    ((void (**)(void))(*(void ***)obj))[9]();
    state = *(void **)((char *)arg0 + 8);
    *(unsigned char *)((char *)state + 7) =
        (unsigned char)((*(unsigned char *)((char *)state + 7) & ~0xe0) | (((arg1 + 1) << 5) & 0xe0));
}

#pragma cplusplus on
extern "C" void fn_80191568(void *arg0) {
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
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f25();
}
#pragma cplusplus off
unsigned char fn_8019157C(void *arg0) {
    return *((unsigned char *)arg0 + 0x14);
}

extern int fn_8018AE24(void *, int);
void fn_80191584(void *arg0) {
    u8 *p;
    void *obj = *(void **)((char *)arg0 + 0x34);
    p = (u8 *)((char *)obj + 0x2680);
    *p = 0;
    fn_8018AE24(*(void **)((char *)arg0 + 0x34), 0);
    *(u8 *)((char *)*(void **)((char *)arg0 + 0x34) + 0x260e) = 0;
    ((void (**)(void *, int))(*(void **)*(void **)((char *)arg0 + 0x38)))[30](*(void **)((char *)arg0 + 0x38), 0);
    *(u8 *)((char *)*(void **)((char *)arg0 + 0x34) + 0x260c) = 0;
    *(int *)((char *)arg0 + 8) = -1;
}

void fn_801915FC(void *arg0, void *arg1) {
    void *obj;
    *(void **)((char *)arg0 + 0x34) = arg1;
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg1 + 0x1EC);
    ((void (**)(void *))*(void **)arg0)[9](arg0);
    *(float *)((char *)arg0 + 0x10) = lbl_8056208C;
    *(float *)((char *)arg0 + 0x14) = lbl_8056208C;
    *(float *)((char *)arg0 + 0x18) = lbl_8056208C;
    memset((char *)arg0 + 0x20, 0, 0x10);
    *(float *)((char *)arg0 + 0x1C) = lbl_80562090;
    obj = *(void **)((char *)arg0 + 0x38);
    ((void (**)(void *))*(void **)obj)[28](obj);
    fn_801331C4(&lbl_8055A480, (char *)arg0 + 0x1C);
}

#pragma cplusplus on
struct DummyInner_80191688 {
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

struct DummyWrapper_80191688 {
    char pad[4];
    DummyInner_80191688 *inner;
};
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80191688(DummyWrapper_80191688 *arg0) {
    arg0->inner->f26();
}
#pragma cplusplus off
void fn_8019169C(void *arg0, void *arg1) {
    *(void **)((char *)arg0 + 0x34) = arg1;
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg1 + 0x1EC);
}

void *fn_801916AC(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int*)((char*)arg0 + 0x38) = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void fn_801916F4(void *arg0) {
    void **obj;
    obj = *(void ***)((char*)arg0 + 0x38);
    ((void (**)(void*, int))(*(void ***)obj))[9](obj, 0);
    if (*(int*)((char*)arg0 + 0x30) != 0) {
        *(int*)((char*)arg0 + 0x30) = 4;
        *(int*)((char*)arg0 + 0xC) = -1;
        *(float*)((char*)arg0 + 0x40) = lbl_8056208C;
    }
}

__declspec(section ".data") extern u32 lbl_802F9550[];
extern int fn_8018B06C(void *);
void fn_80191860(void *arg0, void *arg1) {
    u32 sp[9];
    u32 *p = lbl_802F9550;
    void *saved1 = arg1;
    void *saved0 = arg0;
    void *obj;

    sp[0] = *p++;
    sp[3] = p[2];
    sp[1] = p[0];
    sp[2] = p[1];
    sp[4] = p[3];
    sp[5] = p[4];
    sp[6] = p[5];
    sp[7] = p[6];
    sp[8] = p[7];
    sp[0] = (u32)((char *)arg0 + 4);
    sp[3] = (u32)((char *)arg0 + 5);
    obj = *(void **)((char *)arg0 + 0x38);
    ((void (**)(void *, int))(*(void ***)obj))[9](obj, fn_8018B06C(*(void **)((char *)arg0 + 0x34)));
    ((void (**)(void *, u32 *))(*(void ***)saved1))[2](saved1, sp);
}

extern float lbl_805620C4, lbl_805620C8, lbl_805620CC;
extern float PSVECDotProduct(void *, void *);
void fn_80191928(void *arg0) {
    int state = *(int *)((char *)arg0 + 0x30);
    int result;
    int hit;
    float speed;
    float dot;
    void *obj;
    void **vtable;
    if (state == 0) return;
    obj = *(void **)((char *)arg0 + 0x34);
    if (*(float *)((char *)obj + 0x2618) > lbl_80562090) {
        *(int *)((char *)arg0 + 0x30) = 4;
        return;
    }
    obj = *(void **)((char *)arg0 + 0x38);
    vtable = *(void ***)obj;
    speed = ((float (*)(void *))vtable[5])(obj);
    vtable = *(void ***)obj;
    result = ((int (*)(void *))vtable[11])(obj);
    hit = speed < 0.0f;
    dot = PSVECDotProduct((char *)*(void **)((char *)arg0 + 0x34) + 0x54,
                          (char *)*(void **)((char *)arg0 + 0x34) + 0x118);
    state = *(int *)((char *)arg0 + 0x30);
    if (state == 4) {
        hit = hit && dot < lbl_805620C4;
    } else {
        hit = hit && dot < lbl_805620C8;
    }
    if (hit) {
        if (result == 0)
            *(int *)((char *)arg0 + 0x30) = 4;
        return;
    }
    if (state == 4) {
        *(int *)((char *)arg0 + 0x30) = 5;
        return;
    }
    if (state >= 5) {
        state++;
        *(int *)((char *)arg0 + 0x30) = state;
        if (state - 5 == 0x1D)
            *(int *)((char *)arg0 + 0x30) = 3;
        if (dot < lbl_805620CC)
            *(int *)((char *)arg0 + 0x30) = 3;
    }
}

s32 fn_80191A98(void *arg0) {
    s32 bit = (*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 1) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

void fn_80192BE4(void) {

}

#pragma cplusplus on
extern "C" void fn_80192BE8(void *arg0) {
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
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f17();
}
#pragma cplusplus on
extern "C" void fn_80192BFC(void *arg0) {
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
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    obj->f14();
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
#pragma cplusplus off
s32 fn_80192C4C(void *arg0) {
    s32 bit = (*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 2) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

s32 fn_80192C68(void *arg0) {
    return (((u8)*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 5) & 7) - 1;
}

extern f32 lbl_8056208C;
extern f32 lbl_80562090;
extern f32 lbl_805620AC;
extern f64 lbl_805620B0;
f32 fn_80192C7C(void *arg0) {
    f32 var_f4;
    u8 temp_r4 = *(u8 *)((char *)*(void **)((char *)arg0 + 8) + 6);
    u8 temp_r0 = ((temp_r4 >> 4) & 0xF & ~0xF0) | (temp_r4 & 0xF0);
    f32 value = ((f32)temp_r0 - lbl_8056208C) / lbl_805620AC;
    var_f4 = lbl_80562090;
    if (var_f4 < value) {
        var_f4 = value;
    }
    value = ((f32)temp_r0 - lbl_8056208C) / lbl_805620AC;
    if (var_f4 > lbl_8056208C) {
    } else {
        var_f4 = lbl_8056208C;
    }
    return lbl_8056208C + (var_f4 * lbl_80562090);
}

extern f32 lbl_80562094;
extern f32 lbl_80562138;
f32 fn_80192D10(void *arg0) {
    f32 var_f4;
    f64 d;

    d = (double)*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 5);
    var_f4 = lbl_80562090;
    if (var_f4 < (f32)((d - lbl_805620B0) / lbl_805620AC)) {
        d = d - lbl_805620B0;
        var_f4 = (f32)(d / lbl_805620AC);
    }
    if (var_f4 > lbl_8056208C) {
    } else {
        var_f4 = lbl_8056208C;
    }
    return lbl_80562094 + (var_f4 * lbl_80562138);
}

f32 fn_80192D98(void *arg0) {
    f32 var_f4;
    f64 d;

    d = (double)*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 4);
    var_f4 = lbl_80562090;
    if (var_f4 < (f32)((d - lbl_805620B0) / lbl_805620AC)) {
        d = d - lbl_805620B0;
        var_f4 = (f32)(d / lbl_805620AC);
    }
    if (var_f4 > lbl_8056208C) {
    } else {
        var_f4 = lbl_8056208C;
    }
    return lbl_80562094 + (var_f4 * lbl_80562138);
}

s32 fn_80192E20(void *arg0) {
    s32 bit = *(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

float fn_80192E3C(void *arg0) {
    unsigned char x = *((unsigned char *)*(void **)((char *)arg0 + 8) + 6);
    unsigned char y = (x & 0xF) | ((x << 4) & 0xF0);
    float z = (float)y;
    z = (z - lbl_8056208C) / lbl_805620AC;
    if (z < lbl_80562090) z = lbl_80562090;
    if (z > lbl_8056208C) z = lbl_8056208C;
    return lbl_8056208C + z * lbl_80562090;
}

extern float lbl_80562084;
extern float lbl_8056208C;
extern float lbl_80562090;
extern float lbl_805620A4;
extern float lbl_805620AC;
extern float lbl_805620B8;
float fn_80192ED0(void *arg0) {
    float x = (float)*(unsigned short *)*(void **)((char *)arg0 + 8);
    float y = (x - lbl_8056208C) / lbl_805620B8;
    if (y < lbl_80562090) y = lbl_80562090;
    if (y > lbl_8056208C) y = lbl_8056208C;
    return lbl_80562084 + y * lbl_805620A4;
}

#pragma cplusplus on
extern "C" int fn_80192F58(void *arg0) {
    class VTable {
    public:
        virtual int f0();
    };
    VTable *obj = *(VTable **)((char *)arg0 + 4);
    return obj->f0();
}
#pragma cplusplus off
unsigned char fn_80192F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_80192F74(void *arg0) {
    *(int *)((char *)arg0 + 0xC) = lbl_8055E3C4;
}

void fn_80192F80(void *arg0) {
    float value;
    int result;
    *(int *)__AXGetStudio_80178C90() = 0;
    result = fn_801B2F54(*(int *)((char *)arg0 + 0x3C));
    *(int *)((char *)__AXGetStudio_80178C90() + 4) = result;
    value = *(float *)((char *)*(void **)((char *)arg0 + 0x34) + 0x25CC);
    *(float *)((char *)__AXGetStudio_80178C90() + 8) = value;
    value = fn_8018AE3C(*(void **)((char *)arg0 + 0x34));
    *(float *)((char *)__AXGetStudio_80178C90() + 0xC) = value;
    value = fn_8018AE4C(*(void **)((char *)arg0 + 0x34));
    *(float *)((char *)__AXGetStudio_80178C90() + 0x10) = value;
}

int fn_80193010(void) { return 0x20; }

void fn_80193018(void *arg0, void *arg1) {
float x=*(float*)((char*)arg0+0x10)+*(float*)arg1;
float y=*(float*)((char*)arg0+0x14)+*(float*)((char*)arg1+4);
float z=*(float*)((char*)arg0+0x18)+*(float*)((char*)arg1+8);
*(float*)((char*)arg0+0x10)=x; *(float*)((char*)arg0+0x14)=y; *(float*)((char*)arg0+0x18)=z;
}

void fn_8019304C(void *arg0) {
    *(float *)((char *)arg0 + 0x40) = lbl_8056208C;
}

void fn_80193058(void) {
}

unsigned char fn_8019305C(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

unsigned char fn_80193064(void *arg0) { return *((unsigned char*)arg0+0x13); }

