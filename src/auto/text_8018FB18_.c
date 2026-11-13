

#include <types.h>

extern f32 PSVECDotProduct(const void *, const void *);
extern f32 lbl_805620C0, lbl_805620C4, lbl_805620C8, lbl_805620CC;
extern int __cntlzw(unsigned int);

typedef s32 M2C_UNK;
#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#endif
#ifndef M2C_BITWISE
#define M2C_BITWISE(type, expr) ((type)(expr))
#endif

extern void fn_801333E8(void *, void *, void *);
extern s32 fn_8018B06C(void *);
extern void *memset(void *, int, u32);
extern char lbl_80332E70[];
extern s32 lbl_8055D430;
typedef struct VObj318 { void **vtbl; } VObj318;
#define VCALL0(o, off, ret) ((ret (*)(void *))((VObj318 *)(o))->vtbl[(off) / 4])(o)
extern void fn_801B6650(int);
extern void fn_802793B0(int);

extern int fn_80191100(void *);

extern float lbl_8056208C;
extern float lbl_80562090;
extern float lbl_805620AC;
extern float lbl_80562080;
extern int lbl_8055E3C4;
extern int lbl_8055E524;
extern f32 lbl_8055E3C8;
extern f32 lbl_80562084;
extern f32 lbl_80562088;
extern f32 lbl_80562094;
extern f32 lbl_80562098;
extern f32 lbl_8056209C;
extern f32 lbl_805620A0;
extern f32 lbl_805620A4;
extern f32 lbl_805620A8;
extern u8 lbl_8055E529;
extern f32 fn_80158E80(void *);
extern s32 fn_801B851C(s32);
extern s32 fn_8026B7B4(s32);
extern s32 fn_80019B54(void);
extern s32 fn_80176A34(s32);
extern void __AXDSPInitCallback_801769E0(void);
extern s32 fn_801CF064(void);
extern int fn_80190D9C(float, float, float);
extern void DBPrintf_801797A8(const char *, ...);
extern int fn_80190CD0(float, float, float);
extern int fn_80190D38(float, float, float);
extern int fn_80190E00(void *);
extern void *fn_801B83A0(void);
extern s32 fn_80190368(s32);
extern s32 fn_802B02C8(void *);
extern s32 fn_801796C4(void);
extern void fn_801B86A4(s32);
extern u8 lbl_8055E522;
extern f32 lbl_80558DC4;
extern char lbl_80332EC4[];
extern double fabs(double);
void fn_80191084(int, int);
int fn_801B89E0(void);
extern s32 fn_801CF050(void);
extern void fn_801B6658(void);
extern f32 lbl_805620BC;
extern char lbl_804349B0[];
extern char lbl_80332F40[];
extern s32 lbl_8055A478;
extern u8 lbl_8055E528;
extern void *fn_801284F8(s32, const void *);
extern void *fn_8018108C(s32);
extern void *fn_801B2EC0(s32);
extern s32 fn_80019B78(void);
#pragma scheduling invalid_target
extern s32 fn_8012850C(s32, void *);
extern s32 fn_80137C74(void);
extern void fn_802E30C8(const char *, ...);
extern char lbl_80332E94[], lbl_80332EA0[];
#pragma use_lmw_stmw off
#pragma inline off(fn_8018FC38)
#pragma cplusplus on
extern "C" void *__AXFXGetLfoSinTable_801769CC(void);
extern "C" void *fn_801B83A0(void);
extern "C" unsigned char lbl_8055E522;
extern "C" void *fn_801284F8(s32, const void *);
extern "C" void fn_801912B4(void *);
extern "C" void *fn_8018FD88(void *, s32, s32);
extern "C" void *fn_80134E90(void);
extern "C" void *fn_80134EC8(int);
extern "C" void *fn_80135078(void);
extern "C" void *fn_801A520C(void *, void *);
extern "C" char lbl_80332E70[];
extern "C" char lbl_80332E80[];
extern "C" char lbl_8055A470[7];
/* Builds the local player's car for a race.
 * The current game mode's master object (fn_801B83A0, one of the masters chosen by
 * fn_801B81E0 from the mode id in the session settings record) says which driver
 * object drives the car; when it has none, one is made here: an AI driver
 * ("AIDriver", fn_80134E90) for modes flagged 0x100 or for the 0x180201 mode,
 * otherwise a park driver ("ParkDriver", fn_80135078).
 * Then, in order: the player's input driver ("PlayerDriver", fn_801912B4), the
 * "Hybrid" that ties the driver to that input driver (fn_8018FD88) and finally the
 * car itself ("LocalCar (player)", fn_801A520C) built on top of the hybrid.
 * Also latches bit 8 of the mode word into lbl_8055E522, which the 0x180304 mode
 * always clears. */
extern "C" void fn_8018FB18(void) {
    class ModeMaster {
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
        virtual void f30();
        virtual void f31();
        virtual void f32();
        virtual void f33();
        virtual void f34();
        virtual void f35();
        virtual void f36();
        virtual void f37();
        virtual void f38();
        virtual void f39();
        virtual void f40();
        virtual void f41();
        virtual void f42();
        virtual void f43();
        virtual void f44();
        virtual void f45();
        virtual void f46();
        virtual void f47();
        virtual void f48();
        virtual void f49();
        virtual void f50();
        virtual void f51();
        virtual void f52();
        virtual void f53();
        virtual void f54();
        virtual void f55();
        virtual void f56();
        virtual int getDriver();
    };
    /* Session settings record: [0] = manager id, [1] = game mode id/flags.
     * ptr is reused for the PlayerDriver once the record has been read. */
    void *ptr = __AXFXGetLfoSinTable_801769CC();
    void *hybrid;
    void *driver;
    driver = (void *)((ModeMaster *)fn_801B83A0())->getDriver();
    lbl_8055E522 = (unsigned char)((((unsigned int *)ptr)[1] >> 8) & 1);
    if (((unsigned int *)ptr)[1] == 0x180304) lbl_8055E522 = 0;
    if (driver == 0) {
        unsigned int mode = ((unsigned int *)ptr)[1];
        if ((mode & 0x100) != 0) driver = fn_80134E90();
        else if (mode == 0x180201) driver = fn_80134EC8(mode);
        else driver = fn_80135078();
    }
    ptr = fn_801284F8(0x44, lbl_80332E70);
    if (ptr != 0) ptr = ((void *(*)(void *))fn_801912B4)(ptr);
    hybrid = fn_801284F8(0x3C, lbl_8055A470);
    if (hybrid != 0) hybrid = fn_8018FD88(hybrid, (s32)driver, (s32)ptr);
    {
        void *localCar = fn_801284F8(0x2844, lbl_80332E80);
        if (localCar != 0) fn_801A520C(localCar, hybrid);
    }
}
#pragma cplusplus reset

void fn_8018FC38(void) {
    /* Allocate a 0x46500-byte replay-packet buffer per player (fn_80137C74) and log total KB allocated. */
    s32 playerCount = fn_80137C74();
    s32 *slot = (s32 *)lbl_804349B0;
    s32 i = 0;
    while (i < playerCount) {
        *slot = fn_8012850C(0x46500, lbl_80332E94);
        slot++;
        i++;
    }
    fn_802E30C8(lbl_80332EA0, ((u32)(playerCount * 0x8CA0) >> 7) & 0x3FFFFF);
}
#pragma use_lmw_stmw reset
void fn_8018FCC4(void) {
    s32 count = fn_80137C74();
    register s32 *p = (s32 *)lbl_804349B0;
    register s32 i;
    for (i = 0; i < count; p++, i++) {
        fn_80128670(*p);
        *p = 0;
    }
}
#pragma scheduling on
int fn_8018FD38(void) {
    int result = 0;
    if (lbl_8055E3C4 + 1 >= lbl_8055E524 || fn_801B89E0() != 0) result = 1;
    return result;
}

extern s32 fn_801293A4(void);
#pragma dont_inline fn_8018FC38
extern void fn_8018FC38(void);
extern void fn_801B664C(void);
extern s32 fn_801B6668();
extern u8 lbl_80333018[];
extern void* lbl_804349A0[];
extern f32 lbl_8055A468, lbl_8055A46C;
extern s32 lbl_8055E518;
extern u8 lbl_8055E520, lbl_8055E523;
extern f64 lbl_80562070;
extern f32 lbl_80562078, lbl_8056207C, lbl_80562080;
#pragma dont_inline fn_8018FC38
#pragma scheduling invalid_target
/* Initialize an object instance (vtable/registry/state), ensure related subsystems are ready, and seed timing/limit globals from a random value. */
void* fn_8018FD88(void* arg0, s32 arg1, s32 arg2) {
    f32 randScaled;
    f32 adjusted;
    f32 minLimit;
    s32 zeroInit = 0;

    *(void**)arg0 = lbl_80333018;
    if (lbl_8055E518 == 0) ((void (*)(void))fn_8018FC38)();
    lbl_804349A0[lbl_8055E518++] = arg0;
    ((u8*)arg0)[0x38] = 1;
    lbl_8055E520 = (u8)zeroInit;
    lbl_8055E523 = (u8)zeroInit;
    *(s32*)((u8*)arg0 + 8) = arg1;
    *(s32*)((u8*)arg0 + 0xC) = arg2;
    *(s32*)((u8*)arg0 + 0x10) = zeroInit;
    *(s32*)((u8*)arg0 + 4) = zeroInit;
    *(s32*)((u8*)arg0 + 0x28) = 0x10000;
    if (fn_801B6668() == 0) fn_801B664C();
    randScaled = lbl_80562078 * (f32)fn_801293A4();
    adjusted = randScaled - lbl_8056207C;
    minLimit = lbl_80562080;
    lbl_8055A46C = randScaled;
    minLimit = (minLimit > adjusted) ? minLimit : adjusted;
    lbl_8055A468 = minLimit;
    return arg0;
}
#pragma scheduling on

void *fn_8018FE8C(void *arg0, s32 arg1) {
    s32 temp_r0;
    void *obj;
    register void **vtable;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80333018;
        if (fn_801B6668(arg0) != 0) fn_801B6654();
        obj = *(void **)((char *)arg0 + 4);
        if (obj != 0) {
            vtable = *(void ***)obj;
            ((void (**)(void *, int))vtable)[0x20](obj, 1);
        }
        obj = *(void **)((char *)arg0 + 8);
        *(void **)((char *)arg0 + 4) = 0;
        if (obj != 0) {
            vtable = *(void ***)obj;
            ((void (**)(void *, int))vtable)[2](obj, 1);
        }
        obj = *(void **)((char *)arg0 + 0xC);
        *(void **)((char *)arg0 + 8) = 0;
        if (obj != 0) {
            vtable = *(void ***)obj;
            ((void (**)(void *, int))vtable)[2](obj, 1);
        }
        *(void **)((char *)arg0 + 0xC) = 0;
        temp_r0 = lbl_8055E518 - 1;
        lbl_8055E518 = temp_r0;
        if (temp_r0 == 0) fn_8018FCC4();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_8018FF84(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8018FFC4(void *arg0, void *arg1, void *arg2) {
    class ResultMethods {
    public:
        virtual u8 f0();
        virtual u8 f1();
        virtual u8 f2();
        virtual u8 f3();
        virtual u8 f4();
        virtual u8 f5();
        virtual u8 f6();
        virtual u8 f7();
        virtual u8 f8();
        virtual u8 f9();
        virtual u8 f10();
        virtual u8 f11();
        virtual u8 f12();
        virtual u8 f13();
        virtual u8 f14();
        virtual u8 f15();
        virtual u8 f16();
        virtual u8 f17();
        virtual u8 f18();
        virtual u8 f19();
        virtual u8 f20();
        virtual u8 get5c();
        virtual u8 get60();
        virtual u8 get64();
        virtual u8 get68();
    };
    class Method18 {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 get18();
    };
    class Method0C1 {
    public:
        virtual void f0();
        virtual void call(void *, void *);
    };
    class Method0C2 {
    public:
        virtual void f0();
        virtual void call(void *, void *);
    };
    s32 temp_r0;
    s32 temp_r27;
    s32 temp_r3_6;
    void *temp_r3;
    ResultMethods *resultObj;
    Method18 *method18Obj;
    Method0C1 *method0C1Obj;
    Method0C2 *method0C2Obj;
    *(s32 *)((u8 *)arg0 + 0x28) = *(u8 *)((u8 *)arg1 + 0x260) & 3;
    temp_r3 = fn_801284F8(0x24, &lbl_8055A478);
    if (temp_r3 != 0) {
        temp_r27 = *(s32 *)((u8 *)arg0 + 0x28);
        *(void **)temp_r3 = lbl_80332F40;
        *(s32 *)((u8 *)temp_r3 + 0x20) = temp_r27;
        fn_80137C74();
        *(s32 *)((u8 *)temp_r3 + 0x1C) = 0x8CA0;
        temp_r0 = ((s32 *)lbl_804349B0)[temp_r27];
        *(s32 *)((u8 *)temp_r3 + 0x18) = temp_r0;
        *(s32 *)((u8 *)temp_r3 + 8) = temp_r0;
        *(void **)((u8 *)temp_r3 + 4) = fn_8018108C(temp_r27);
        *(s32 *)((u8 *)temp_r3 + 0xC) = 0;
        lbl_8055E524 = 0;
        if (fn_801CF050() != 0) {
            resultObj = *(ResultMethods **)((u8 *)temp_r3 + 4);
            *(u8 *)((u8 *)temp_r3 + 0x11) = resultObj->get5c();
            resultObj = *(ResultMethods **)((u8 *)temp_r3 + 4);
            *(u8 *)((u8 *)temp_r3 + 0x12) = resultObj->get64();
            resultObj = *(ResultMethods **)((u8 *)temp_r3 + 4);
            *(u8 *)((u8 *)temp_r3 + 0x13) = resultObj->get60();
            resultObj = *(ResultMethods **)((u8 *)temp_r3 + 4);
            *(u8 *)((u8 *)temp_r3 + 0x14) = resultObj->get68();
        }
    }
    *(void **)((u8 *)arg0 + 4) = temp_r3;
    *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0x38) = temp_r3;
    int leading = __cntlzw(*(int *)((u8 *)arg2 + 0x5C));
    leading >>= 5;
    *(u8 *)((u8 *)arg0 + 0x25) = leading;
    {
        s32 value = *(s32 *)((u8 *)arg2 + 0x5C);
        s32 negative = -value;
        *(void **)((u8 *)arg0 + 0x20) = arg1;
        *(u8 *)((u8 *)arg0 + 0x26) = (u32)(negative | value) >> 31;
    }
    temp_r3_6 = *(s32 *)((u8 *)arg1 + 0x1EC);
    *(s32 *)((u8 *)arg0 + 0x1C) = temp_r3_6;
    method18Obj = (Method18 *)fn_801B2EC0(temp_r3_6);
    *(void **)((u8 *)arg0 + 0x14) = method18Obj;
    *(s32 *)((u8 *)arg0 + 0x18) = method18Obj->get18();
    method0C1Obj = *(Method0C1 **)((u8 *)arg0 + 8);
    method0C1Obj->call(arg1, arg2);
    method0C2Obj = *(Method0C2 **)((u8 *)arg0 + 0xC);
    method0C2Obj->call(arg1, arg2);
    if (fn_80019B78() != 0) {
        lbl_8055E528 = 1;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset
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

extern "C" int fn_801B526C(void);
extern "C" int fn_801769F8(void);
extern "C" unsigned char lbl_8055E521;
#pragma cplusplus on
/* Query the current status/result flags for this object, combining subobject state
 * and applying additional flags when local conditions (at +0x34, lbl_8055E521) hold. */
extern "C" int fn_801901F0(void *self) {
    class VT1 {
    public:
        virtual int d0(void );
        virtual int d1(void );
        virtual int d2(void );
        virtual int d3(void );
        virtual int d4(void );
        virtual int d5(void );
        virtual int d6(void );
        virtual int d7(void );
        virtual int d8(void );
        virtual int d9(void );
        virtual int d10(void );
        virtual int d11(void );
        virtual int d12(void );
        virtual int d13(void );
        virtual int d14(void );
        virtual int d15(void );
        virtual int d16(void );
        virtual int d17(void );
        virtual int d18(void );
        virtual int d19(void );
        virtual int d20(void );
        virtual int d21(void );
        virtual int d22(void );
        virtual int d23(void );
        virtual int d24(void );
        virtual int d25(void );
        virtual int d26(void );
        virtual int d27(void );
        virtual int d28(int arg);
    };
    class VT2 {
    public:
        virtual int e0();
        virtual int e1();
        virtual int e2();
        virtual int e3();
        virtual int e4();
        virtual int e5();
    };
    int result;
    if (fn_801B526C() == 0) {
        if (*(void **)((char *)self + 4) != 0 && fn_801769F8() != 0) {
            VT1 *obj = *(VT1 **)((char *)self + 4);
            obj->d28(0);
        }
        if (*(void **)((char *)self + 0x10) != 0) {
            VT2 *obj = *(VT2 **)((char *)self + 0x10);
            result = obj->e3();
            if (*(unsigned char *)((char *)self + 0x34) == 0)
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

#pragma push
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
#pragma pop

extern void fn_801B6650(int);
extern void fn_802793B0(int);
#pragma cplusplus on
extern "C" void fn_801B6650(int);
extern "C" void fn_802793B0(int);
#pragma cplusplus on
extern "C" void fn_80191084(int, int);
extern "C" int fn_80191100(void *);
#pragma cplusplus on
extern "C" void fn_801902B4(void *arg0) {
    /* Refresh this object's active references and notify listeners/virtual slot 10. */
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
    };
    unsigned int selectedRef;
    unsigned int primaryRef;
    VTable *obj;
    int (*callback)(void *);

    fn_80191084((int)arg0, 0);
    fn_801B6650(*(int *)((char *)arg0 + 0x20));
    callback = (int (*)(void *))fn_80191100;
    selectedRef = callback(arg0);
    primaryRef = *(unsigned int *)((char *)arg0 + 8);
    if (selectedRef != primaryRef) {
        fn_80191084((int)arg0, primaryRef);
    } else {
        fn_80191084((int)arg0, *(unsigned int *)((char *)arg0 + 0xC));
    }
    fn_80191084((int)arg0, selectedRef);
    if (*(unsigned char *)((char *)arg0 + 0x38) != 0) {
        *(unsigned char *)((char *)arg0 + 0x38) = 0;
        fn_802793B0(*(int *)((char *)arg0 + 0x28));
    }
    obj = (VTable *)arg0;
    obj->f10();
}
#pragma cplusplus off
void fn_80190360(int arg0) {
    fn_80191084(arg0, 0);
}

s32 fn_80190368(s32 arg0) {
    return arg0 == 1 || arg0 == 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80190388(void *arg0)
{
    void *first;
    void *r31v;
    void *sub;
    void *base;
    void *cObj;
    void *o20;
    void *mgr;
    void *obj270;
    void *res18;
    void *innerObj;
    void *r10ret;
    f32 f31v;
    f32 f30v;
    f32 f29v;
    f32 rC;
    f32 r14;
    f32 r10;
    f32 r18;
    f32 r1C;
    f32 r44;
    f32 r48;
    f32 diff;
    f32 newF30;
    f32 tmpF;
    s32 idx;
    s32 lim;
    s32 nw;
    s32 f24;
    s32 isLess;
    s32 virt38;
    s32 saved;
    s32 e0ret;
    s32 c1;
    s32 c2;
    s32 bit29;
    s32 any;
    s32 i;
    s32 off;
    int v0;
    int v1;
    int rec;
    u8 sp8v;
    first = *(void **)((char *)arg0 + 0x14);
    r31v = ((void *(*)(void *))(*(void ***)first)[4])(first);
    f31v = lbl_8055E3C8;
    sub = *(void **)((char *)arg0 + 4);
    f30v = fn_80158E80(*(void **)((char *)arg0 + 0x20));
    idx = lbl_8055E3C4;
    lim = *(s32 *)((char *)sub + 0x1C);
    if (idx >= lim) {
        idx = lim - 1;
    }
    base = *(void **)((char *)sub + 0x18);
    *(void **)((char *)sub + 8) = (char *)base + idx * 8;
    if (((s32 (*)(void *))fn_801CF050)(base) != 0) {
        if (idx >= *(s32 *)((char *)sub + 0xC)) {
            nw = idx + 1;
            *(s32 *)((char *)sub + 0xC) = nw;
            lbl_8055E524 = nw;
        }
        rC = ((f32 (*)(void *, f32))(*(void ***)(*(void **)((char *)sub + 4)))[3])(*(void **)((char *)sub + 4), f30v);
        *(s16 *)(void *)fn_80190E00(sub) = fn_80190D9C(rC, lbl_80562084, lbl_80562088);
        r14 = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[5])(*(void **)((char *)sub + 4));
        *(s8 *)(void *)((int)fn_80190E00(sub) + 3) = fn_80190D38(r14, lbl_8056208C, lbl_80562090);
        r10 = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[4])(*(void **)((char *)sub + 4));
        *(s8 *)(void *)((int)fn_80190E00(sub) + 2) = fn_80190D38(r10, lbl_8056208C, lbl_80562090);
        r18 = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[6])(*(void **)((char *)sub + 4));
        v1 = fn_80190CD0(r18, lbl_8056208C, lbl_80562090);
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 6) = __rlwimi(*(u8 *)(void *)(rec + 6), v1, 4, 24, 27);
        r1C = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[7])(*(void **)((char *)sub + 4));
        v1 = fn_80190CD0(r1C, lbl_8056208C, lbl_80562090);
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 6) = __rlwimi(*(u8 *)(void *)(rec + 6), v1, 0, 28, 31);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[8])(*(void **)((char *)sub + 4)) + 1;
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 5, 24, 26);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[13])(*(void **)((char *)sub + 4));
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 4, 27, 27);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[14])(*(void **)((char *)sub + 4));
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 3, 28, 28);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[15])(*(void **)((char *)sub + 4));
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 2, 29, 29);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[11])(*(void **)((char *)sub + 4));
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 1, 30, 30);
        v0 = ((s32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[12])(*(void **)((char *)sub + 4));
        rec = fn_80190E00(sub);
        *(u8 *)(void *)(rec + 7) = __rlwimi(*(u8 *)(void *)(rec + 7), v0, 0, 31, 31);
        r44 = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[17])(*(void **)((char *)sub + 4));
        *(s8 *)(void *)((int)fn_80190E00(sub) + 4) = fn_80190D38(r44, lbl_80562094, lbl_80562090);
        r48 = ((f32 (*)(void *))(*(void ***)(*(void **)((char *)sub + 4)))[18])(*(void **)((char *)sub + 4));
        *(s8 *)(void *)((int)fn_80190E00(sub) + 5) = fn_80190D38(r48, lbl_80562094, lbl_80562090);
    }
    if (fn_801CF064() != 0 && idx >= *(s32 *)((char *)sub + 0xC) - 1) {
        __AXDSPInitCallback_801769E0();
        fn_80176A34(lbl_8055E3C4);
    }
    ((void (*)(void *))(*(void ***)sub)[29])(sub);
    if (*(s32 *)((char *)(*(void **)((char *)arg0 + 0x20)) + 0x2620) != 0) {
        ((void (*)(void *))(*(void ***)sub)[31])(sub);
    }
    if (lbl_8055E529 == 0) {
        o20 = *(void **)((char *)arg0 + 0x20);
        diff = f31v - *(f32 *)((char *)o20 + 0x26D8);
        isLess = (diff < lbl_80562098) ? 1 : 0;
        f24 = *(s32 *)((char *)r31v + 0x24);
        if (f24 == 3 || lbl_8055E528 != 0 || fn_80019B54() != 0) {
            if (*(u8 *)((char *)arg0 + 0x25) != 0 && *(u8 *)((char *)arg0 + 0x26) != 0) {
                fn_80191084((int)arg0, *(int *)((char *)arg0 + 8));
            } else {
                fn_80191084((int)arg0, *(int *)((char *)arg0 + 0xC));
            }
        } else if (isLess != 0) {
            fn_80191084((int)arg0, *(int *)((char *)arg0 + 8));
        } else if (f24 == 1) {
            fn_80191084((int)arg0, *(int *)((char *)arg0 + 8));
        } else if (fn_801B851C(*(int *)((char *)arg0 + 0x1C)) == 0) {
            fn_80191084((int)arg0, *(int *)((char *)arg0 + 0xC));
        } else if (fn_8026B7B4(*(int *)((char *)arg0 + 0x1C)) == 0) {
            fn_80191084((int)arg0, *(int *)((char *)arg0 + 0xC));
        } else {
            fn_80191084((int)arg0, *(int *)((char *)arg0 + 8));
        }
    } else {
        fn_80191084((int)arg0, *(int *)((char *)arg0 + 0xC));
    }
    cObj = *(void **)((char *)arg0 + 0xC);
    if (*(void **)((char *)arg0 + 0x10) == cObj) {
        ((void (*)(void *))(*(void ***)cObj)[18])(cObj);
    } else {
        ((void (*)(void *, s32))(*(void ***)sub)[30])(sub, 0);
    }
    virt38 = ((s32 (*)(void *))(*(void ***)sub)[14])(sub);
    saved = 0;
    if (virt38 != 0 && *(u8 *)((char *)arg0 + 0x24) == 0) {
        saved = 1;
        *(u8 *)((char *)arg0 + 0x24) = 1;
    } else {
        *(u8 *)((char *)arg0 + 0x24) = 0;
    }
    sp8v = 0;
    mgr = fn_801B83A0();
    e0ret = ((s32 (*)(void *, s32, u8 *))(*(void ***)mgr)[56])(mgr, *(s32 *)((char *)arg0 + 0x1C), &sp8v);
    if (e0ret != 0) {
        *(u8 *)((char *)arg0 + 0x34) = (u8)(__cntlzw(sp8v) >> 5);
        if (*(u8 *)((char *)arg0 + 0x34) != 0) {
            tmpF = *(f32 *)((char *)arg0 + 0x2C);
            if (tmpF <= f31v) {
            } else {
                *(f32 *)((char *)arg0 + 0x2C) = f31v;
            }
        }
    } else {
        o20 = *(void **)((char *)arg0 + 0x20);
        obj270 = *(void **)((char *)o20 + 0x270);
        res18 = ((void *(*)(void *))(*(void ***)obj270)[6])(obj270);
        newF30 = *(f32 *)((char *)res18 + 0x48);
        f30v = newF30;
        f29v = newF30 - *(f32 *)((char *)arg0 + 0x30);
        r10ret = ((void *(*)(void *))(*(void ***)obj270)[4])(obj270);
        bit29 = (*(s32 *)r10ret >> 29) & 1;
        tmpF = (f32)fabs((double)*(f32 *)((char *)o20 + 0x2690));
        c1 = (tmpF <= lbl_80558DC4) ? 1 : 0;
        c2 = ((f31v - *(f32 *)((char *)o20 + 0x26D8)) >= lbl_8056207C) ? 1 : 0;
        if (c1 != 0 && bit29 != 0 && c2 != 0) {
            *(u8 *)((char *)arg0 + 0x34) = 0;
        } else if (f29v > lbl_8056209C || f29v < lbl_805620A0 || c2 == 0 || fn_802B02C8((char *)o20 + 0x60) == 0) {
            *(f32 *)((char *)arg0 + 0x30) = newF30;
            tmpF = *(f32 *)((char *)arg0 + 0x2C);
            if (tmpF > f31v) {
            } else {
                *(f32 *)((char *)arg0 + 0x2C) = f31v;
            }
            *(u8 *)((char *)arg0 + 0x34) = 1;
        } else if ((f31v - *(f32 *)((char *)arg0 + 0x2C)) > lbl_805620A4) {
            *(u8 *)((char *)arg0 + 0x34) = 0;
            *(f32 *)((char *)arg0 + 0x2C) = lbl_80562090 + (f31v - lbl_805620A4);
            *(f32 *)((char *)arg0 + 0x30) = lbl_805620A8 + (newF30 - lbl_8056209C);
            if (fn_801796C4() != 0) {
                tmpF = *(f32 *)((char *)arg0 + 0x2C);
            } else {
                if (lbl_8055E522 == 0) {
                    *(f32 *)((char *)arg0 + 0x2C) = f31v;
                    *(u8 *)((char *)arg0 + 0x34) = 1;
                }
            }
        }
    }
    if (fn_801796C4() != 0 || lbl_8055E522 == 0) {
        *(f32 *)((char *)arg0 + 0x2C) = f31v;
        *(u8 *)((char *)arg0 + 0x34) = 1;
    }
    if (*(u8 *)((char *)arg0 + 0x34) == 0 && saved != 0) {
        *(u8 *)((char *)arg0 + 0x34) = 1;
        tmpF = *(f32 *)((char *)arg0 + 0x2C);
        if (tmpF > f31v) {
        } else {
            *(f32 *)((char *)arg0 + 0x2C) = f31v;
        }
        fn_801B86A4(*(int *)((char *)arg0 + 0x1C));
    }
    if (*(u8 *)((char *)arg0 + 0x26) == 0) {
        innerObj = *(void **)((char *)arg0 + 0x18);
        v0 = 3;
        if (innerObj != 0) {
            v0 = *(u8 *)((char *)(*(void **)((char *)innerObj + 4)) + 0x34);
        }
        if (v0 == 0) {
            *(u8 *)((char *)arg0 + 0x26) = 1;
            *(s32 *)((char *)innerObj + 0xC) = 0;
        }
    }
    if (*(void **)((char *)arg0 + 0x10) == *(void **)((char *)arg0 + 0xC) && lbl_8055E523 != 0 && lbl_8055E520 == 0) {
        any = 0;
        i = 0;
        off = 0;
        do {
            if (fn_80190368(*(s32 *)((char *)(*(void **)((char *)arg0 + 0x20)) + off + 0x2410)) == 0) {
                any = 1;
            }
            i++;
            off += 0x74;
        } while (i < 4);
        if (any != 0) {
            lbl_8055E520 = 1;
            DBPrintf_801797A8(*(const char **)((char *)arg0 + 0x28), lbl_80332EC4);
        }
    }
}
#pragma use_lmw_stmw reset
#pragma pop
s32 fn_80190B60(void *arg0) {
    s32 bit = (*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 4) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

#pragma scheduling invalid_target
f32 fn_80190B7C(void *arg0) {
    u8 raw = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 2);
    f32 normalized = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    f32 value;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_8056208C + value * lbl_80562090;
}

#pragma scheduling invalid_target
f32 fn_80190C04(void *arg0) {
    u8 raw = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 3);
    f32 normalized = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    f32 value;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_8056208C + value * lbl_80562090;
}
#pragma scheduling on

#pragma scheduling on

s32 fn_80190C8C(void *arg0) {
    s32 bit = (*(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 3) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

#pragma push
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

#pragma push
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
#pragma pop

#pragma pop

#pragma scheduling invalid_target
int fn_80190CD0(float a, float b, float c) {
    float y;
    float x;
    y = lbl_80562090;
    x = (a - b) / (c - b);
    if (y < x) {
        y = x;
    } else {
        y = y;
    }
    if (y > lbl_8056208C) {
        y = lbl_8056208C;
    } else {
        y = y;
    }
    return (((int)(lbl_80562080 + (lbl_8056208C + (y * lbl_805620AC)))) >> 4) & 0xF;
}
#pragma scheduling on
int fn_80190D38(float a, float b, float c) { float lower; float value; lower = lbl_80562090; value = (a - b) / (c - b); if (lower < value) { lower = value; } else { lower = lower; } if (lower > lbl_8056208C) { lower = lbl_8056208C; } else { lower = lower; } return (int)(lbl_80562080 + (lbl_8056208C + (lower * lbl_805620AC))); }

extern float lbl_805620B8;
#pragma scheduling on
int fn_80190D9C(float a, float b, float c) { float lower; float value; value = (a - b) / (c - b); lower = lbl_80562090; if (lower < value) { lower = value; } else { lower = lower; } if (lower > lbl_8056208C) { lower = lbl_8056208C; } else { lower = lower; } return (int)(lbl_80562080 + (lbl_8056208C + (lower * lbl_805620B8))); }
#pragma scheduling pop

#pragma scheduling pop
int fn_80190E00(void *arg0) { return ((int *)arg0)[2]; }

#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_80190E08(void) {
    class Dummy_80190E08 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
    };
    int i;
    for (i = 0; i < lbl_8055E518; i++) {
        Dummy_80190E08 *obj = (Dummy_80190E08 *)lbl_804349A0[i];
        obj->m16();
    }
}
#pragma cplusplus reset
#pragma dont_inline reset

void fn_80190E6C(void) {
    fn_80190E08();
}

#pragma cplusplus on
extern "C" void fn_801B665C(void);
extern "C" void fn_80190E70(void *arg0) {
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
    };
    void *obj = *(void **)((char *)arg0 + 0x10);
    if (obj != 0) {
        ((VTable *)obj)->f9();
    }
    fn_801B665C();
}
#pragma cplusplus reset

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_propagation off
extern "C" void fn_80190EAC(void *arg0) {
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
    };
    s32 zero = 0;
    s32 one = 1;
    void *sub;
    s8 z;
    f32 f0;
    f32 f1;
    *(s8 *)((s8 *)arg0 + 0x25) = (s8)zero;
    *(s8 *)((s8 *)arg0 + 0x26) = (zero == 0);
    *(s8 *)((s8 *)arg0 + 0x24) = (s8)one;
    lbl_8055E520 = (u8)zero;
    sub = *(void **)((s8 *)arg0 + 4);
    if (fn_801CF050() != 0) {
        *(s32 *)((s8 *)sub + 0xC) = zero;
        lbl_8055E524 = zero;
    }
    *(s32 *)((s8 *)sub + 8) = *(s32 *)((s8 *)sub + 0x18);
    (*(VTable **)((s8 *)arg0 + 8))->f10();
    (*(VTable **)((s8 *)arg0 + 0xC))->f10();
    fn_80191084((int)arg0, zero);
    fn_80191084((int)arg0, fn_80191100(arg0));
    fn_801B6658();
    z = 0;
    f1 = lbl_8056208C;
    f0 = lbl_805620BC;
    *(volatile s8 *)((s8 *)arg0 + 0x34) = z;
    *(f32 *)((s8 *)arg0 + 0x30) = f1;
    *(s8 *)((s8 *)arg0 + 0x34) = 1;
    *(f32 *)((s8 *)arg0 + 0x2C) = f0;
}
#pragma opt_propagation reset
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma cplusplus reset
#pragma pop

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

#pragma cplusplus on
extern "C" void DBPrintf_801797A8(const char *, ...);
extern "C" char lbl_80332EDC[];
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_80190FA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    /* Dispatch a virtual event call to the current target, warning once if it hits the fallback object. */
    class Dummy {
    public:
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
        virtual void v13(s32, s32, s32, s32);
    };
    void *currentTarget = *(void **)((u8 *)arg0 + 0x10);

    if (currentTarget != 0) {
        if (currentTarget == *(void **)((u8 *)arg0 + 0xC) &&
            lbl_8055E523 != 0 &&
            lbl_8055E520 == 0 &&
            arg3 != 1) {
            lbl_8055E520 = 1;
            DBPrintf_801797A8((const char *)*(void **)((u8 *)arg0 + 0x28), lbl_80332EDC);
        }
        ((Dummy *)*(void **)((u8 *)arg0 + 0x10))->v13(arg1, arg2, arg3, arg4);
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus off

void fn_80191060(void) {
    fn_801B6664();
}

#pragma cplusplus on
extern "C" void fn_80191064(void *arg0) {
    class Object {
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
    };
    Object *obj = (Object *)*(void **)((char *)arg0 + 0x10);
    if (obj == 0) return;
    obj->f15();
}

#pragma cplusplus on
extern "C" void fn_80191084(int arg0, int arg1) {
    class Dummy {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8(int);
    };
    void *old;
    old = *(void **)((char *)arg0 + 0x10);
    if ((unsigned int)arg1 != (unsigned int)old) {
        if (old != 0) {
            ((Dummy *)old)->f8(arg1);
        }
        *(void **)((char *)arg0 + 0x10) = (void *)arg1;
        if (arg1 != 0) {
            ((Dummy *)(void *)arg1)->f7();
        }
    }
}
#pragma cplusplus off

#pragma cplusplus off
int fn_80191100(void *arg0) { return ((int *)arg0)[3]; }

#pragma cplusplus on
extern "C" s32 fn_80191108(void *arg0, s32 arg1) {
    class Object1 {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 method();
    };
    class Object2 {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 method(s32);
    };
    Object1 *obj1 = *(Object1 **)((u8 *)arg0 + 0xC);
    s32 result = obj1->method();
    Object2 *obj2 = *(Object2 **)((u8 *)arg0 + 8);
    return result + obj2->method(arg1 + result);
}

#pragma cplusplus on
extern "C" void fn_801B6660(s32);
#pragma use_lmw_stmw off
extern "C" void fn_80191178(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4, f32 farg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5(s32, s32, s32 *, s32 *, f32);
    };
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    register f32 value = farg0;

    ((Dummy *)*(void **)((u8 *)arg0 + 0xC))->v5(arg1, arg2, &sp14, &sp10, value);
    ((Dummy *)*(void **)((u8 *)arg0 + 8))->v5(arg1 + sp14, arg2 + sp10, &spC, &sp8, value);
    *arg3 = sp14 + spC;
    *arg4 = sp10 + sp8;
    fn_801B6660(sp10);
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x260C) = 0;
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

extern "C" s32 fn_80191240(void *arg0, s32 arg1) {
    class Object1 {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 method();
    };
    class Object2 {
    public:
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 method(s32);
    };
    Object1 *obj1 = *(Object1 **)((u8 *)arg0 + 0xC);
    s32 result = arg1 + obj1->method();
    Object2 *obj2 = *(Object2 **)((u8 *)arg0 + 8);
    result += obj2->method(result);
    return result - arg1;
}

#pragma cplusplus reset
extern u8 lbl_80332FC4[];
void fn_801912B4(void *arg0) {
    *(void **)arg0 = lbl_80332FC4;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(s32 *)((u8 *)arg0 + 8) = -1;
}

#pragma cplusplus on
extern "C" void fn_801912D8(void *arg0) {
    class Obj {
    public:
        virtual void m08(); virtual void m0C(); virtual void m10(); virtual void m14();
        virtual void m18(); virtual void m1C(); virtual void m20();
        virtual void setA(int);
        virtual void setB(void *, float);
        virtual void m2C(); virtual void m30(); virtual void m34(); virtual void m38(); virtual void m3C();
        virtual void m40(); virtual void m44(); virtual void m48(); virtual void m4C(); virtual void m50();
        virtual void m54(); virtual void m58(); virtual void m5C(); virtual void m60(); virtual void m64();
        virtual unsigned char getFlag();
        virtual void *getKey();
    };
    unsigned char *self = (unsigned char *)arg0;
    char *base = lbl_80332E70;
    int enabled;
    int mask;
    unsigned char spA, sp9, sp8;
    *(unsigned char *)(*(unsigned char **)(self + 0x34) + 0x2680) = (*(Obj **)(self + 0x38))->getFlag();
    *(int *)(*(unsigned char **)(self + 0x34) + 0x267C) = 0;
    *(float *)(*(unsigned char **)(self + 0x34) + 0x5F0) = lbl_80562090;
    enabled = 1;
    self[4] = 1;
    fn_801333E8((*(Obj **)(self + 0x38))->getKey(), base + 0x7C, self + 4);
    self[5] = 1;
    fn_801333E8((*(Obj **)(self + 0x38))->getKey(), base + 0x8C, self + 5);
    if (self[4] != 0) {
        self[5] = 1;
    }
    if (self[4] == 0) {
        enabled = 0;
    }
    {
        int v = 0;
        if (enabled != 0) {
            v = 4;
        }
        *(int *)(self + 0x30) = v;
    }
    spA = 1;
    sp9 = 1;
    sp8 = 0;
    fn_801333E8((*(Obj **)(self + 0x38))->getKey(), base + 0x98, &spA);
    fn_801333E8((*(Obj **)(self + 0x38))->getKey(), base + 0xAC, &sp9);
    fn_801333E8((*(Obj **)(self + 0x38))->getKey(), base + 0xC0, &sp8);
    mask = 0;
    if ((lbl_8055D430 & 1) && (lbl_8055D430 & 4)) {
        mask = 1;
    }
    if (mask != 0) {
        sp8 = 1;
    }
    if (sp8 != 0) {
        spA = 0;
        sp9 = 0;
    }
    (*(Obj **)(self + 0x38))->setA(fn_8018B06C(*(void **)(self + 0x34)));
    (*(Obj **)(self + 0x38))->setB(*(void **)(self + 0x34), *(float *)(*(unsigned char **)(self + 0x34) + 0x25F4));
    *(int *)(self + 8) = *(int *)(*(unsigned char **)(self + 0x38) + 0x20);
    *(float *)(self + 0x10) = lbl_8056208C;
    *(float *)(self + 0x14) = lbl_8056208C;
    *(float *)(self + 0x18) = lbl_8056208C;
    memset(self + 0x20, 0, 0x10);
}
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

#pragma push
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
#pragma pop

#pragma cplusplus off
u8 fn_8019157C(void *arg0) { return *((u8 *)arg0 + 0x14); }

#pragma cplusplus on
extern "C" void fn_80191584(void *arg0) {
    class Dummy {
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
        virtual void f28(s32);
    };
    extern void fn_8018AE24(void *, s32);
    register int zero = 0;
    void *obj;
    Dummy *obj38;
    obj = *(void **)((char *)arg0 + 0x34);
    *(unsigned char *)((char *)obj + 0x2680) = (unsigned char)zero;
    fn_8018AE24(*(void **)((char *)arg0 + 0x34), zero);
    obj = *(void **)((char *)arg0 + 0x34);
    *(unsigned char *)((char *)obj + 0x260E) = (unsigned char)zero;
    obj38 = *(Dummy **)((char *)arg0 + 0x38);
    obj38->f28(zero);
    obj = *(void **)((char *)arg0 + 0x34);
    *(unsigned char *)((char *)obj + 0x260C) = (unsigned char)zero;
    *(int *)((char *)arg0 + 8) = -1;
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_801331C4(s32, void *, f32 *);
extern char lbl_8055A480;
extern "C" void *memset(void *, int, u32);
#pragma cplusplus on
extern "C" void fn_801915FC(void *arg0, void *arg1) {
    class FirstVTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
    };
    class SecondVTable {
    public:
        virtual void g0();
        virtual void g1();
        virtual void g2();
        virtual void g3();
        virtual void g4();
        virtual void g5();
        virtual void g6();
        virtual void g7();
        virtual void g8();
        virtual void g9();
        virtual void g10();
        virtual void g11();
        virtual void g12();
        virtual void g13();
        virtual void g14();
        virtual void g15();
        virtual void g16();
        virtual void g17();
        virtual void g18();
        virtual void g19();
        virtual void g20();
        virtual void g21();
        virtual void g22();
        virtual void g23();
        virtual void g24();
        virtual void g25();
        virtual int g26();
    };
    register u8 *self = (u8 *)arg0;
    SecondVTable *second;
    s32 result;
    f32 zero;
    *(void **)(self + 0x34) = arg1;
    *(s32 *)(self + 0x3C) = *(s32 *)((u8 *)arg1 + 0x1EC);
    ((FirstVTable *)self)->f7();
    zero = lbl_8056208C;
    *(f32 *)(self + 0x10) = zero;
    *(f32 *)(self + 0x14) = zero;
    *(f32 *)(self + 0x18) = zero;
    memset(self + 0x20, 0, 0x10);
    *(f32 *)(self + 0x1C) = lbl_80562090;
    second = *(SecondVTable **)(self + 0x38);
    result = second->g26();
    fn_801331C4(result, &lbl_8055A480, (f32 *)(self + 0x1C));
}
#pragma cplusplus reset

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

void fn_801916F4(void *arg0) {
    register void *obj;
    register void **vtable;
    f32 value;
    s32 invalid;
    obj = *(void **)((u8 *)arg0 + 0x38);
    vtable = *(void ***)obj;
    ((void (**)(void *, s32))vtable)[9](obj, 0);
    if (*(s32 *)((u8 *)arg0 + 0x30) != 0) {
        *(s32 *)((u8 *)arg0 + 0x30) = 4;
        value = lbl_8056208C;
        invalid = -1;
        *(s32 *)((u8 *)arg0 + 0x0C) = invalid;
        *(f32 *)((u8 *)arg0 + 0x40) = value;
    }
}

extern char *strcpy(char *, const char *);
extern unsigned char lbl_804A16E8[];
#pragma scheduling invalid_target
int fn_80191758(void *arg0) {
    unsigned char *dst;
    dst = lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    strcpy((char *)dst, *(char **)((char *)arg0 + 0x20) + 0x234);
    dst = lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x28) = lbl_8056208C;
    *(float *)(dst + 0x24) = lbl_8056208C;
    *(float *)(dst + 0x20) = lbl_8056208C;
    *(float *)(dst + 0x34) = lbl_80562090;
    *(float *)(dst + 0x30) = lbl_80562090;
    *(float *)(dst + 0x2C) = lbl_80562090;
    *(float *)(dst + 0x38) = lbl_80562090;
    *(float *)(dst + 0x3C) = lbl_80562090;
    dst = lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x48) = lbl_8056208C;
    *(float *)(dst + 0x44) = lbl_8056208C;
    *(float *)(dst + 0x40) = lbl_8056208C;
    *(float *)(dst + 0x54) = lbl_80562090;
    *(float *)(dst + 0x50) = lbl_80562090;
    *(float *)(dst + 0x4C) = lbl_80562090;
    *(float *)(dst + 0x58) = lbl_80562090;
    *(float *)(dst + 0x5C) = lbl_80562090;
    dst = lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x68) = lbl_8056208C;
    *(float *)(dst + 0x64) = lbl_8056208C;
    *(float *)(dst + 0x60) = lbl_8056208C;
    *(float *)(dst + 0x74) = lbl_80562090;
    *(float *)(dst + 0x70) = lbl_80562090;
    *(float *)(dst + 0x6C) = lbl_80562090;
    *(float *)(dst + 0x78) = lbl_80562090;
    *(float *)(dst + 0x7C) = lbl_80562090;
    dst = lbl_804A16E8 + *(int *)((char *)arg0 + 0x28) * 0xA0;
    *(float *)(dst + 0x88) = lbl_8056208C;
    *(float *)(dst + 0x84) = lbl_8056208C;
    *(float *)(dst + 0x80) = lbl_8056208C;
    *(float *)(dst + 0x94) = lbl_80562090;
    *(float *)(dst + 0x90) = lbl_80562090;
    *(float *)(dst + 0x8C) = lbl_80562090;
    *(float *)(dst + 0x98) = lbl_80562090;
    *(float *)(dst + 0x9C) = lbl_80562090;
}

void fn_80191860(void *arg0, void *arg1) {
    extern int lbl_802F9550[];
    int buf[9];
    int v;
    int *p = lbl_802F9550;
    buf[0] = *p++;
    buf[1] = *p++;
    buf[2] = *p++;
    buf[3] = *p++;
    buf[4] = *p++;
    buf[5] = *p++;
    buf[6] = *p++;
    buf[7] = *p++;
    buf[8] = *p;
    buf[0] = (int)((char *)arg0 + 4);
    buf[3] = (int)((char *)arg0 + 5);
    v = ((int (*)(int, int, int, int, int, int, int, int))fn_8018B06C)(*(int *)((char *)arg0 + 0x34), lbl_802F9550[8], (int)((char *)arg0 + 4), lbl_802F9550[7], lbl_802F9550[6], lbl_802F9550[5], lbl_802F9550[4], lbl_802F9550[2]);
    ((void (*)(void *, int))((void **)*(void ***)((char *)arg0 + 0x38))[9])(*(void ***)((char *)arg0 + 0x38), v);
    ((void (*)(void *, void *))((void **)*(void ***)arg1)[2])(arg1, buf);
}

#pragma push
#pragma processor 750
#pragma cplusplus on
/* Per-frame state machine for the controller at ctrl: state at +0x30 (0 = off,
   4 = ready, 5.. = counting, 3 = loop), actor pointer at +0x34, and a
   speed()/result() interface at +0x38. Returns while off. If the actor's
   +0x2618 timer exceeds 1.0 it drops back to state 4. Otherwise it samples the
   interface's speed() and result() and the dot product of the actor's +0x54 and
   +0x118 vectors; when moving fast enough (speed > 0.1) and that dot is under
   the per-state threshold (0.888889 in state 4, else 2.66667) and result() == 0,
   it advances 4 -> 5 and then counts up each frame, wrapping to 3 after 0x1D
   frames or as soon as the dot falls under -1.33333. Any other failure -> 4. */
extern "C" void fn_80191928(void *ctrl) {
    class Interface {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual f32 speed();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual s32 result();
    };
    s32 aligned;
    s32 state;
    bool fast;
    s32 result;
    s32 next;
    f32 speed;
    f32 dot;
    if (*(s32 *)((u8 *)ctrl + 0x30) == 0)
        return;
    if (*(f32 *)((u8 *)*(void **)((u8 *)ctrl + 0x34) + 0x2618) > lbl_80562090) {
        *(s32 *)((u8 *)ctrl + 0x30) = 4;
        return;
    }
    speed = ((Interface *)*(void **)((u8 *)ctrl + 0x38))->speed();
    result = ((Interface *)*(void **)((u8 *)ctrl + 0x38))->result();
    fast = speed > lbl_805620C0;
    dot = PSVECDotProduct((u8 *)*(void **)((u8 *)ctrl + 0x34) + 0x54,
                          (u8 *)*(void **)((u8 *)ctrl + 0x34) + 0x118);
    state = *(s32 *)((u8 *)ctrl + 0x30);
    if (state == 4) {
        aligned = 0;
        if (fast && dot < lbl_805620C4)
            aligned = 1;
    } else {
        aligned = 0;
        if (fast && dot < lbl_805620C8)
            aligned = 1;
    }
    if ((aligned == 0) || (result != 0)) {
        *(s32 *)((u8 *)ctrl + 0x30) = 4;
        return;
    }
    if (state == 4) {
        *(s32 *)((u8 *)ctrl + 0x30) = 5;
        return;
    }
    if (state >= 5) {
        next = *(volatile s32 *)((u8 *)ctrl + 0x30) + 1;
        *(s32 *)((u8 *)ctrl + 0x30) = next;
        if (next - 5 == 0x1D)
            *(s32 *)((u8 *)ctrl + 0x30) = 3;
        if (dot < lbl_805620CC)
            *(s32 *)((u8 *)ctrl + 0x30) = 3;
    }
}
#pragma cplusplus off
#pragma pop

#pragma scheduling on
int fn_80191A98(void *arg0) {
    int bit = (*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 1) & 1;
    return (int)((unsigned int)(-bit | bit) >> 31);
}

extern void fn_80191928(void *);
extern char *fn_8018AE5C(void);
extern f32 PSVECMag(const void *);
extern f32 PSVECDotProduct(const void *, const void *);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_8018B084(void *);
extern void fn_80136EA4(int, int);
extern void fn_8018ADA4(void *, f32);
extern void fn_8018ADB4(void *, f32);
extern void fn_8018ADBC(void *, f32);
extern volatile f32 lbl_8055E51C;
extern int lbl_8055E0D0;
extern f32 lbl_8056208C, lbl_80562090, lbl_80562094, lbl_805620D0;
extern f32 lbl_805620D4, lbl_805620D8;
extern u8 lbl_8055E52A;
extern void fn_8017B3A8(void *, f32 *, f32 *);
extern f64 cos(f32);
extern f64 sin(f32, f32, f32);
extern M2C_UNK fn_8002EFB4(f32, f64);
extern s32 fn_801796B4(void);
extern s32 fn_801796C4(void);
extern void fn_8018ADC4(void *, f32);
extern void fn_8018ADCC(void *);
extern void fn_8018ADD4(void *, s32);
extern void fn_8018ADEC(void *);
extern void fn_8018AE24(void *, s32);
extern void fn_8018AE2C(void *);
extern void fn_8018AE34(void *, f32);
extern f32 fn_8018AE4C(void *, f32);
extern void fn_8018AE54(void *, f32);
extern s32 fn_8018B06C();
extern void fn_801B86A4(s32);
extern s32 fn_801CF050(void);
extern void **fn_801D0BF8(s32, M2C_UNK);
extern s32 lbl_8055D430;
extern f32 lbl_8055E3C8;
extern u8 lbl_8055E52B, lbl_8055E52C;
extern f32 lbl_80562098, lbl_805620A8, lbl_805620BC, lbl_805620C0;
extern f32 lbl_805620DC, lbl_805620E0, lbl_805620E4, lbl_805620E8;
extern f32 lbl_805620EC, lbl_805620F0, lbl_805620F4, lbl_805620F8;
extern f32 lbl_805620FC, lbl_80562100, lbl_80562104, lbl_80562108;
extern f32 lbl_8056210C, lbl_80562110, lbl_80562114, lbl_80562118;
extern f64 lbl_80562120;
extern f32 lbl_80562128, lbl_8056212C, lbl_80562130, lbl_80562134;
#pragma scheduling invalid_target
extern f32 lbl_80558DC4, lbl_80562098, lbl_805620A8, lbl_805620BC, lbl_805620C0;
extern f32 __fabsf(f32);
#pragma scheduling invalid_target
void fn_80191AB4(u8 *arg0) {
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    struct { f32 pad[4]; f32 vecE[3], vecD[3], vecC[3], vecB[3], vecA[3]; } vectors;
    f32 sp10;
    M2C_UNK spC;
    s8 sp8;                                        /* compiler-managed */
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f24_4;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f5_5;
    f32 temp_f5_6;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 temp_f7_3;
    f32 temp_f9;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f24;
    f32 var_f24_2;
    f32 var_f28;
    f32 var_f29;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f3_3;
    f32 var_f4;
    f32 var_f4_2;
    f32 var_f5;
    f32 var_f8;
    s32 temp_r29;
    s32 temp_r30_2;
    s32 var_r3;
    u32 temp_r0;
    u32 temp_r3_30;
    void **temp_r3;
    void **temp_r3_10;
    void **temp_r3_11;
    void **temp_r3_12;
    void **temp_r3_13;
    void **temp_r3_14;
    void **temp_r3_15;
    void **temp_r3_16;
    void **temp_r3_17;
    void **temp_r3_18;
    void **temp_r3_19;
    void **temp_r3_20;
    void **temp_r3_21;
    void **temp_r3_22;
    void **temp_r3_23;
    void **temp_r3_24;
    void **temp_r3_25;
    void **temp_r3_26;
    void **temp_r3_27;
    void **temp_r3_28;
    void **temp_r3_29;
    void **temp_r3_2;
    void **temp_r3_31;
    void **temp_r3_36;
    void **temp_r3_37;
    void **temp_r3_38;
    void **temp_r3_39;
    void **temp_r3_3;
    void **temp_r3_40;
    void **temp_r3_41;
    void **temp_r3_42;
    void **temp_r3_4;
    void **temp_r3_5;
    void **temp_r3_6;
    void **temp_r3_8;
    void **temp_r3_9;
    void *temp_r30;
    void *temp_r30_3;
    void *temp_r30_4;
    void *temp_r3_32;
    void *temp_r3_33;
    void *temp_r3_34;
    void *temp_r3_35;
    void *temp_r3_7;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;

    fn_80191928(arg0);
    lbl_8055E51C = PSVECMag(((char *(*)(void *))fn_8018AE5C)(M2C_FIELD(arg0, void **, 0x34)));
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    temp_r3 = M2C_FIELD(arg0, void ***, 0x38);
    temp_f31 = PSVECDotProduct(((u8 *)temp_r4 + 0x118), ((u8 *)temp_r4 + 0x54));
    M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x64)(M2C_FIELD(arg0, void ***, 0x38));
    if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), s32 *, 0x10) & 2) {
        var_f29 = lbl_80562094;
    } else {
        var_f29 = lbl_80562090;
    }
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x38);
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void **, s32), 8)(temp_r3_2, fn_8018B084(M2C_FIELD(arg0, void **, 0x34)));
    fn_80136EA4(lbl_8055E0D0, M2C_FIELD(arg0, s32 *, 0x3C));
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x34);
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x38);
    temp_f24 = lbl_8056208C;
    fn_8018ADA4(M2C_FIELD(arg0, void **, 0x34), var_f29 * (temp_f24 + M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **, f32), 0xC)(M2C_FIELD(arg0, void ***, 0x38), (f32) __fabsf(PSVECDotProduct(((u8 *)temp_r4_2 + 0x118), ((u8 *)temp_r4_2 + 0x54))))));
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x38);
    if (M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x1C)(M2C_FIELD(arg0, void ***, 0x38)) < lbl_805620D0) {
        temp_r3_5 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x10)(M2C_FIELD(arg0, void ***, 0x38));
        ((void (*)(void *))fn_8018ADB4)(M2C_FIELD(arg0, void **, 0x34));
    } else {
        fn_8018ADB4(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
    }
    temp_r3_6 = M2C_FIELD(arg0, void ***, 0x38);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(temp_r4_3, s8 *, 0x260E) = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s8 (**)(void **), 0x30)(M2C_FIELD(arg0, void ***, 0x38));
    if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), s32 *, 4) & 0x20000) {
        var_f28 = lbl_80562090;
    } else {
        var_f28 = lbl_80562080;
    }
    if ((s32) (lbl_8055E3C4 - M2C_FIELD(arg0, s32 *, 0xC)) > 0xA) {
        temp_r4_4 = M2C_FIELD(arg0, void **, 0x34);
        if ((M2C_FIELD(temp_r4_4, f32 *, 0x25F4) > lbl_805620D4) && (temp_f31 < lbl_805620D8) && ((s32) M2C_FIELD(temp_r4_4, s32 *, 0x2620) >= 3) && ((s32) lbl_8055E52A == 0)) {
            var_f0 = lbl_80562090;
            vectors.vecA[0] = M2C_FIELD(temp_r4_4, f32 *, 0x54) + (M2C_FIELD(temp_r4_4, f32 *, 0x48) * lbl_8056208C);
            vectors.vecA[1] = M2C_FIELD(temp_r4_4, f32 *, 0x58) + (M2C_FIELD(temp_r4_4, f32 *, 0x4C) * lbl_8056208C);
            vectors.vecA[2] = M2C_FIELD(temp_r4_4, f32 *, 0x5C) + (M2C_FIELD(temp_r4_4, f32 *, 0x50) * lbl_8056208C);
            temp_r3_7 = M2C_FIELD(arg0, void **, 0x34);
            temp_f1 = M2C_FIELD(temp_r3_7, f32 *, 0x25F0);
            if (var_f0 >= temp_f1) var_f0 = temp_f1;
            if (var_f0 <= lbl_80562094) var_f0 = lbl_80562094;
            if (lbl_80562090 < ((M2C_FIELD(temp_r3_7, f32 *, 0x25D4) - lbl_805620DC) / lbl_805620E0)) {

            }
            var_f4 = lbl_80562090;
            temp_f2 = var_f4 - lbl_8056208C;
            temp_f1_2 = lbl_805620E4 * (var_f0 * -M2C_FIELD(temp_r3_7, f32 *, 0x128));
            if (var_f4 >= temp_f1_2) var_f4 = temp_f1_2;
            if (var_f4 <= lbl_8056208C) var_f4 = lbl_8056208C;
            var_f8 = lbl_80562090;
            temp_f5 = var_f8 - (temp_f2 * var_f4 * (var_f0 * var_f0));
            vectors.vecA[0] *= temp_f5;
            vectors.vecA[1] *= temp_f5;
            vectors.vecA[2] *= temp_f5;
            temp_f1_3 = var_f8 - (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), f32 *, 0x25D4) / lbl_805620A8);
            if (var_f8 >= temp_f1_3) var_f8 = temp_f1_3;
            if (var_f8 <= lbl_8056208C) var_f8 = lbl_8056208C;
            temp_f7 = var_f8 * (lbl_805620E8 * (var_f0 * (f32) __fabsf(var_f0)));
            temp_f5_2 = vectors.vecA[0] + (M2C_FIELD(temp_r4_4, f32 *, 0x3C) * temp_f7);
            vectors.vecA[0] = temp_f5_2;
            temp_f4 = vectors.vecA[1] + (M2C_FIELD(temp_r4_4, f32 *, 0x40) * temp_f7);
            vectors.vecA[1] = temp_f4;
            temp_f0 = vectors.vecA[2] + (M2C_FIELD(temp_r4_4, f32 *, 0x44) * temp_f7);
            vectors.vecA[2] = temp_f0;
            temp_f6 = lbl_805620EC * var_f28 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), f32 *, 0x25F8);
            temp_f3 = temp_f5_2 * temp_f6;
            vectors.vecA[0] = temp_f3;
            vectors.vecA[1] = temp_f4 * temp_f6;
            vectors.vecA[2] = temp_f0 * temp_f6;
            vectors.vecB[0] = M2C_FIELD(temp_r4_4, f32 *, 0x60) + (M2C_FIELD(temp_r4_4, f32 *, 0x54) * lbl_805620F0);
            vectors.vecB[1] = M2C_FIELD(temp_r4_4, f32 *, 0x64) + (M2C_FIELD(temp_r4_4, f32 *, 0x58) * lbl_805620F0);
            temp_f1_4 = M2C_FIELD(temp_r4_4, f32 *, 0x5C) * lbl_805620F0;
            vectors.vecB[2] = M2C_FIELD(temp_r4_4, f32 *, 0x68) + temp_f1_4;
            if (fn_8018B06C(M2C_FIELD(arg0, void **, 0x34), temp_f1_4, lbl_805620F0, temp_f3, temp_f4, temp_f5_2, temp_f6, temp_f7) < 0) {
                if ((f32) __fabsf(temp_f31) < lbl_805620D8) {
                    vectors.vecA[0] *= lbl_80562094;
                    vectors.vecA[1] *= lbl_80562094;
                    vectors.vecA[2] *= lbl_80562094;
                } else {
                    vectors.vecA[0] *= lbl_8056208C;
                    vectors.vecA[1] *= lbl_8056208C;
                    vectors.vecA[2] *= lbl_8056208C;
                }
            }
            fn_8017B3A8(M2C_FIELD(arg0, void **, 0x34), &vectors.vecA[0], &vectors.vecB[0]);
        }
    }
    if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s32 *, 0x2620) >= 3) {
        temp_r3_8 = M2C_FIELD(arg0, void ***, 0x38);
        if (M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x14)(M2C_FIELD(arg0, void ***, 0x38)) > lbl_805620C0) {
            temp_r30 = M2C_FIELD(arg0, void **, 0x34);
            temp_f2_2 = lbl_805620F4 * var_f28;
            temp_f30 = M2C_FIELD(temp_r30, f32 *, 0x25F0);
            temp_f0_2 = M2C_FIELD(temp_r30, f32 *, 0x54) + (M2C_FIELD(temp_r30, f32 *, 0x48) * lbl_8056208C);
            vectors.vecC[0] = temp_f0_2;
            temp_f0_3 = M2C_FIELD(temp_r30, f32 *, 0x58) + (M2C_FIELD(temp_r30, f32 *, 0x4C) * lbl_8056208C);
            vectors.vecC[1] = temp_f0_3;
            temp_f3_2 = M2C_FIELD(temp_r30, f32 *, 0x5C);
            temp_f4_2 = M2C_FIELD(temp_r30, f32 *, 0x50) * lbl_8056208C;
            vectors.vecC[0] = temp_f0_2 * temp_f2_2;
            temp_f1_5 = temp_f3_2 + temp_f4_2;
            vectors.vecC[1] = temp_f0_3 * temp_f2_2;
            temp_f0_4 = temp_f1_5 * temp_f2_2;
            vectors.vecC[2] = temp_f0_4;
            temp_r3_9 = M2C_FIELD(arg0, void ***, 0x38);
            temp_f1_6 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **, f32, f32, f32, f32, f32), 0x14)(M2C_FIELD(arg0, void ***, 0x38), temp_f1_5, temp_f2_2, temp_f3_2, temp_f4_2, lbl_8056208C);
            temp_f7_2 = lbl_80562090 - (temp_f30 * temp_f30);
            vectors.vecC[0] = vectors.vecC[0] * temp_f1_6 * temp_f7_2;
            vectors.vecC[1] = vectors.vecC[1] * temp_f1_6 * temp_f7_2;
            vectors.vecC[2] = temp_f0_4 * temp_f1_6 * temp_f7_2;
            vectors.vecD[0] = M2C_FIELD(temp_r30, f32 *, 0x60) + (M2C_FIELD(temp_r30, f32 *, 0x54) * lbl_805620F0);
            vectors.vecD[1] = M2C_FIELD(temp_r30, f32 *, 0x64) + (M2C_FIELD(temp_r30, f32 *, 0x58) * lbl_805620F0);
            vectors.vecD[2] = M2C_FIELD(temp_r30, f32 *, 0x68) + (M2C_FIELD(temp_r30, f32 *, 0x5C) * lbl_805620F0);
            if (temp_f31 > lbl_805620F8) {
                fn_8017B3A8(M2C_FIELD(arg0, void **, 0x34), &vectors.vecC[0], &vectors.vecD[0]);
            }
        }
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) != 3) {
        temp_r3_10 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x14)(M2C_FIELD(arg0, void ***, 0x38));
        ((void (*)(void *))fn_8018ADBC)(M2C_FIELD(arg0, void **, 0x34));
    } else {
        fn_8018ADBC(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
    }
    temp_r3_11 = M2C_FIELD(arg0, void ***, 0x38);
    M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x1C)(M2C_FIELD(arg0, void ***, 0x38));
    fn_8018ADCC(M2C_FIELD(arg0, void **, 0x34));
    temp_r3_12 = M2C_FIELD(arg0, void ***, 0x38);
    M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x44)(M2C_FIELD(arg0, void ***, 0x38));
    fn_8018AE2C(M2C_FIELD(arg0, void **, 0x34));
    temp_r3_13 = M2C_FIELD(arg0, void ***, 0x38);
    fn_8018AE34(M2C_FIELD(arg0, void **, 0x34), var_f29 * M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x48)(M2C_FIELD(arg0, void ***, 0x38)));
    temp_r3_14 = M2C_FIELD(arg0, void ***, 0x38);
    temp_r3_15 = M2C_FIELD(arg0, void ***, 0x38);
    var_f24 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x18)(M2C_FIELD(arg0, void ***, 0x38));
    if ((M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s32 (**)(void **), 0x34)(M2C_FIELD(arg0, void ***, 0x38)) != 0) || ((s32) M2C_FIELD(arg0, s32 *, 0x30) == 3)) {
        fn_8018ADD4(M2C_FIELD(arg0, void **, 0x34), -1);
        temp_r4_5 = M2C_FIELD(arg0, void **, 0x34);
        if ((PSVECDotProduct(((u8 *)temp_r4_5 + 0x118), ((u8 *)temp_r4_5 + 0x54)) < lbl_805620FC) || (temp_r3_16 = M2C_FIELD(arg0, void ***, 0x38), ((M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x10)(M2C_FIELD(arg0, void ***, 0x38)) > lbl_80562100) != 0))) {
            temp_r3_17 = M2C_FIELD(arg0, void ***, 0x38);
            temp_f1_7 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x10)(M2C_FIELD(arg0, void ***, 0x38));
            var_f0_2 = lbl_80562090;
            if (var_f0_2 <= temp_f1_7) var_f0_2 = temp_f1_7;
            fn_8018ADB4(M2C_FIELD(arg0, void **, 0x34), var_f0_2);
        } else {
            fn_8018ADBC(M2C_FIELD(arg0, void **, 0x34), lbl_80562090);
            var_f24 = lbl_8056208C;
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), f32 *, 0x25D0) < lbl_80562104) {
                temp_r3_18 = M2C_FIELD(arg0, void ***, 0x38);
                temp_f1_8 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x10)(M2C_FIELD(arg0, void ***, 0x38));
                var_f0_3 = lbl_80562090;
                if (var_f0_3 <= temp_f1_8) var_f0_3 = temp_f1_8;
                fn_8018ADB4(M2C_FIELD(arg0, void **, 0x34), var_f0_3);
            }
        }
    } else if ((s32) M2C_FIELD(arg0, u8 *, 4) != 0) {
        if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), f32 *, 0x25CC) > lbl_8056208C) || (fn_8018B06C() > 0) || (temp_r3_19 = M2C_FIELD(arg0, void ***, 0x38), ((M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x10)(M2C_FIELD(arg0, void ***, 0x38)) > lbl_80562080) != 0))) {
            fn_8018ADEC(M2C_FIELD(arg0, void **, 0x34));
        }
    } else {
        temp_r3_20 = M2C_FIELD(arg0, void ***, 0x38);
        fn_8018ADD4(M2C_FIELD(arg0, void **, 0x34), M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s32 (**)(void **), 0x20)(M2C_FIELD(arg0, void ***, 0x38)));
        temp_r3_21 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, s32), 0x24)(M2C_FIELD(arg0, void ***, 0x38), fn_8018B06C(M2C_FIELD(arg0, void **, 0x34)));
    }
    temp_r3_22 = M2C_FIELD(arg0, void ***, 0x38);
    temp_f0_5 = lbl_80562090 - M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), f32 (**)(void **), 0x1C)(M2C_FIELD(arg0, void ***, 0x38));
    if (var_f24 <= temp_f0_5) var_f24 = temp_f0_5;
    fn_8018ADC4(M2C_FIELD(arg0, void **, 0x34), var_f24);
    if (((s32) lbl_8055E52B != 0) && (temp_r3_23 = M2C_FIELD(arg0, void ***, 0x38), ((M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s32 (**)(void **), 0x3C)(M2C_FIELD(arg0, void ***, 0x38)) == 0) == 0))) {
        0;
        if (((s32) lbl_8055E52C == 0) && (((s32) lbl_8055E52B != 0) || ((s32) (((u32) 0 >> 0x1DU) & 1) != 0))) {
            fn_801B86A4(M2C_FIELD(arg0, s32 *, 0x3C));
        }
        lbl_8055E52C = 1;
    } else {
        lbl_8055E52C = 0;
    }
    temp_r3_24 = M2C_FIELD(arg0, void ***, 0x38);
    temp_r30_2 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s32 (**)(void **), 0x2C)(M2C_FIELD(arg0, void ***, 0x38));
    if ((fn_801796B4() != 0) || (fn_801796C4() != 0)) {
        fn_8018ADBC(M2C_FIELD(arg0, void **, 0x34), lbl_80562090);
        fn_8018ADB4(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
        fn_8018ADA4(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
        if ((s32) M2C_FIELD(arg0, u8 *, 4) == 0) {
            fn_8018ADD4(M2C_FIELD(arg0, void **, 0x34), 0);
            temp_r3_25 = M2C_FIELD(arg0, void ***, 0x38);
            M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, M2C_UNK), 0x24)(M2C_FIELD(arg0, void ***, 0x38), 0);
        }
        fn_8018AE24(M2C_FIELD(arg0, void **, 0x34), 0);
    } else {
        fn_8018AE24(M2C_FIELD(arg0, void **, 0x34), temp_r30_2);
        var_r3 = 0;
        if ((lbl_8055D430 & 1) && (lbl_8055D430 & 8)) {
            var_r3 = 1;
        }
        if (var_r3 != 0) {
            temp_r3_26 = fn_801D0BF8(M2C_FIELD(arg0, s32 *, 0x3C), 0);
            if (temp_r3_26 != NULL) {
                sp8 = 0;
                temp_r3_27 = M2C_FIELD(arg0, void ***, 0x38);
                sp8 = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s8 (**)(void **), 0x2C)(M2C_FIELD(arg0, void ***, 0x38));
                temp_r3_28 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void ***, 0x270);
                if ((s32) M2C_FIELD(M2C_FIELD(*temp_r3_28, void *(**)(void **), 0x10)(temp_r3_28), u8 *, 0x28) == 0) {
                    M2C_FIELD(*temp_r3_26, M2C_UNK (**)(void **, void *, s8 *), 8)(temp_r3_26, M2C_FIELD(arg0, void **, 0x34), (s8 *)&sp8);
                }
            }
        }
    }
    temp_r3_29 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void ***, 0x270);
    if ((s32) M2C_FIELD(M2C_FIELD(*temp_r3_29, void *(**)(void **), 0x10)(temp_r3_29), u8 *, 0x28) != 0) {
        fn_8018ADBC(M2C_FIELD(arg0, void **, 0x34), lbl_80562090);
        fn_8018ADB4(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
        fn_8018ADA4(M2C_FIELD(arg0, void **, 0x34), lbl_8056208C);
    }
    temp_f24_2 = -PSVECDotProduct(((u8 *)arg0 + 0x10), ((u8 *)M2C_FIELD(arg0, void **, 0x34) + 0x3C));
    temp_f1_9 = (f32) __fabsf(PSVECDotProduct(((u8 *)arg0 + 0x10), ((u8 *)M2C_FIELD(arg0, void **, 0x34) + 0x54)));
    if (temp_f24_2 < lbl_8056208C) {
        var_f2 = lbl_80562094;
    } else {
        var_f2 = lbl_80562090;
    }
    temp_r3_30 = (u32) lbl_8055E3C4 >> 0x1FU;
    temp_r0 = (lbl_8055E3C4 << 0x1E) - temp_r3_30;
    M2C_FIELD(((u8 *)arg0 + ((((temp_r0 << 2) | (temp_r0 >> 0x1EU)) + temp_r3_30) * 4)), f32 *, 0x20) = (f32) (lbl_805620C0 * (temp_f24_2 + (var_f2 * (lbl_80562098 * temp_f1_9))));
    temp_f5_3 = M2C_FIELD(arg0, f32 *, 0x20);
    temp_f5_4 = M2C_FIELD(arg0, f32 *, 0x24);
    temp_f5_5 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_f5_6 = M2C_FIELD(arg0, f32 *, 0x2C);
    temp_f4_3 = lbl_8056208C + (f32) __fabsf(temp_f5_3) + (f32) __fabsf(temp_f5_4) + (f32) __fabsf(temp_f5_5) + (f32) __fabsf(temp_f5_6);
    if ((lbl_8056208C + temp_f5_3 + temp_f5_4 + temp_f5_5 + temp_f5_6) > lbl_8056208C) {
        var_f0_4 = lbl_80562090;
    } else {
        var_f0_4 = lbl_80562094;
    }
    temp_r4_6 = M2C_FIELD(arg0, void **, 0x34);
    temp_f1_10 = M2C_FIELD(temp_r4_6, f32 *, 0x2570);
    temp_f2_3 = M2C_FIELD(temp_r4_6, f32 *, 0x24FC);
    temp_f28 = temp_f4_3 * var_f0_4 * M2C_FIELD(arg0, f32 *, 0x1C) * lbl_80562108;
    temp_f24_3 = temp_f2_3 + temp_f1_10;
    temp_f1_11 = ((f32 (*)(void *, void *, f32, f32))PSVECMag)((u8 *)((u8 *)temp_r4_6 + 0x26B4), temp_r4_6, temp_f1_10, temp_f2_3);
    var_f5 = lbl_80562090;
    temp_f0_6 = lbl_805620BC * M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), f32 *, 0x264C);
    if (var_f5 >= temp_f0_6) var_f5 = temp_f0_6;
    var_f3 = lbl_80562090;
    temp_f27 = (lbl_8056210C * temp_f1_11) + var_f5;
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) ((lbl_80562110 * M2C_FIELD(arg0, f32 *, 0x40)) + (lbl_80562114 * temp_f1_11));
    if (var_f3 >= temp_f24_3) var_f3 = temp_f24_3;
    if (var_f3 <= lbl_8056208C) var_f3 = lbl_8056208C;
    temp_f1_12 = lbl_80562118 * var_f3;
    temp_f26 = M2C_FIELD(arg0, f32 *, 0x40) + temp_f1_12;
    fn_8018AE54(M2C_FIELD(arg0, void **, 0x34), temp_f1_12);
    temp_r29 = ((u32) lbl_8055E3C4 >> 1U) & 1;
    if ((fn_801796B4() == 0) && (fn_801CF050() != 0) && (fn_801796C4() == 0) && (temp_r30_3 = M2C_FIELD(arg0, void **, 0x34), __fabsf(M2C_FIELD(temp_r30_3, f32 *, 0x2690)) <= lbl_80558DC4)) {
        fn_8002EFB4(lbl_8055E3C8, lbl_80562120);
        if (temp_r29 != 0) {
            var_f2_2 = lbl_80562094;
        } else {
            var_f2_2 = lbl_80562090;
        }
        temp_f1_13 = lbl_805620D0 * temp_f27;
        temp_f24_4 = (temp_f1_13 + (lbl_805620D0 * temp_f26)) * var_f2_2;
        temp_r3_31 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, f32, f32, f32), 0x50)(M2C_FIELD(arg0, void ***, 0x38), lbl_8056208C, lbl_805620D0 * fn_8018AE4C(temp_r30_3, temp_f1_13), temp_f28 + temp_f24_4);
        temp_r30_4 = M2C_FIELD(arg0, void **, 0x34);
        var_f1 = M2C_FIELD(temp_r30_4, f32 *, 0x25D4) / lbl_805620D8;
        if (lbl_80562090 < var_f1) {
            var_f1 = lbl_80562090;
        }
        if (var_f1 <= lbl_8056208C) var_f1 = lbl_8056208C;
        temp_f25 = lbl_80562090 * var_f1;
        vectors.vecE[0] = M2C_FIELD(temp_r30_4, f32 *, 0x124) * lbl_80562128;
        vectors.vecE[1] = M2C_FIELD(temp_r30_4, f32 *, 0x128) * lbl_80562128;
        vectors.vecE[2] = M2C_FIELD(temp_r30_4, f32 *, 0x12C) * lbl_80562128;
        temp_f1_14 = PSVECMag(&vectors.vecE[0]);
        if (temp_f1_14 > lbl_8056212C) {
            temp_f4_4 = lbl_80562090 / temp_f1_14;
            temp_f29 = temp_f4_4 * vectors.vecE[0];
            temp_f30_2 = temp_f4_4 * vectors.vecE[1];
            temp_f31_2 = temp_f4_4 * vectors.vecE[2];
            temp_f28_2 = (f32) sin(vectors.vecE[1], vectors.vecE[0], temp_f4_4);
            temp_f9 = (f32) cos(temp_f1_14);
            temp_f0_7 = lbl_80562090 - temp_f9;
            temp_f3_3 = temp_f28_2 * temp_f31_2;
            temp_f6_2 = temp_f0_7 * temp_f29;
            temp_f4_5 = temp_f30_2 * temp_f6_2;
            sp68 = temp_f9 + (temp_f0_7 * (temp_f29 * temp_f29));
            temp_f6_3 = temp_f31_2 * temp_f6_2;
            temp_f2_4 = temp_f28_2 * temp_f30_2;
            sp6C = temp_f4_5 + temp_f3_3;
            temp_f3_4 = temp_f31_2 * (temp_f0_7 * temp_f30_2);
            temp_f0_8 = temp_f28_2 * temp_f29;
            sp74 = temp_f4_5 - temp_f3_3;
            sp70 = temp_f6_3 - temp_f2_4;
            sp78 = temp_f9 + (temp_f0_7 * (temp_f30_2 * temp_f30_2));
            sp7C = temp_f3_4 + temp_f0_8;
            sp80 = temp_f6_3 + temp_f2_4;
            sp84 = temp_f3_4 - temp_f0_8;
            sp88 = temp_f9 + (temp_f0_7 * (temp_f31_2 * temp_f31_2));
        } else {
            sp6C = lbl_8056208C;
            sp68 = lbl_80562090;
            sp70 = lbl_8056208C;
            sp74 = lbl_8056208C;
            sp78 = lbl_80562090;
            sp7C = lbl_8056208C;
            sp80 = lbl_8056208C;
            sp84 = lbl_8056208C;
            sp88 = lbl_80562090;
        }
        temp_r3_32 = M2C_FIELD(arg0, void **, 0x34);
        temp_r3_33 = ((u8 *)temp_r3_32 + 0x3C);
        if (&sp20 == temp_r3_33) {
            temp_f6_4 = M2C_FIELD(temp_r3_33, f32 *, 4);
            temp_f0_9 = M2C_FIELD(temp_r3_32, f32 *, 0x3C);
            temp_f7_3 = M2C_FIELD(temp_r3_33, f32 *, 8);
            sp20 = (temp_f7_3 * sp80) + ((temp_f0_9 * sp68) + (temp_f6_4 * sp74));
            sp24 = (temp_f7_3 * sp84) + ((temp_f0_9 * sp6C) + (temp_f6_4 * sp78));
            sp28 = (temp_f7_3 * sp88) + ((temp_f0_9 * sp70) + (temp_f6_4 * sp7C));
        } else {
            sp20 = (M2C_FIELD(temp_r3_33, f32 *, 8) * sp80) + ((M2C_FIELD(temp_r3_32, f32 *, 0x3C) * sp68) + (M2C_FIELD(temp_r3_33, f32 *, 4) * sp74));
            sp24 = (M2C_FIELD(temp_r3_33, f32 *, 8) * sp84) + ((M2C_FIELD(temp_r3_32, f32 *, 0x3C) * sp6C) + (M2C_FIELD(temp_r3_33, f32 *, 4) * sp78));
            sp28 = (M2C_FIELD(temp_r3_33, f32 *, 8) * sp88) + ((M2C_FIELD(temp_r3_32, f32 *, 0x3C) * sp70) + (M2C_FIELD(temp_r3_33, f32 *, 4) * sp7C));
        }
        var_f3_2 = lbl_8056208C;
        temp_f0_10 = lbl_80562090 - (lbl_80562080 * (M2C_FIELD(temp_r30_4, f32 *, 0x2414) + M2C_FIELD(temp_r30_4, f32 *, 0x2488)));
        if (var_f3_2 <= temp_f0_10) var_f3_2 = temp_f0_10;
        temp_r3_34 = M2C_FIELD(arg0, void **, 0x34);
        var_f24_2 = lbl_805620C0;
        temp_f0_11 = M2C_FIELD(temp_r3_34, f32 *, 0x25D4);
        if (var_f24_2 <= temp_f0_11) var_f24_2 = temp_f0_11;
        var_f2_3 = lbl_805620D4;
        temp_f0_12 = lbl_805620BC * (PSVECDotProduct(((u8 *)temp_r3_34 + 0x118), &sp20) / var_f24_2);
        if (var_f2_3 >= temp_f0_12) var_f2_3 = temp_f0_12;
        if (var_f2_3 <= lbl_80562130) var_f2_3 = lbl_80562130;
        temp_r3_35 = M2C_FIELD(arg0, void **, 0x34);
        var_f3_3 = lbl_80562090;
        temp_f0_13 = (f32) __fabsf(M2C_FIELD(temp_r3_35, f32 *, 0x25F0)) / lbl_805620D0;
        if (var_f3_3 >= temp_f0_13) var_f3_3 = temp_f0_13;
        if (var_f3_3 <= lbl_8056208C) var_f3_3 = lbl_8056208C;
        var_f1_2 = M2C_FIELD(temp_r3_35, f32 *, 0x242C);
        if (var_f1_2 <= lbl_8056208C) var_f1_2 = lbl_8056208C;
        var_f4_2 = M2C_FIELD(temp_r3_35, f32 *, 0x23B8);
        if (var_f4_2 <= lbl_8056208C) var_f4_2 = lbl_8056208C;
        var_f1_3 = lbl_80562134 * (var_f4_2 + var_f1_2);
        if (var_f1_3 >= lbl_80562090) var_f1_3 = lbl_80562090;
        temp_r3_36 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, f32, f32, f32), 0x54)(M2C_FIELD(arg0, void ***, 0x38), temp_f25 * var_f3_2 * var_f1_3, var_f2_3 * var_f3_3, lbl_805620D4);
        temp_r3_37 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, f32, f32), 0x58)(M2C_FIELD(arg0, void ***, 0x38), temp_f27, temp_f26);
        temp_r3_38 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, M2C_UNK), 0x78)(M2C_FIELD(arg0, void ***, 0x38), 1);
    } else {
        temp_r3_39 = M2C_FIELD(arg0, void ***, 0x38);
        M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **, M2C_UNK), 0x78)(M2C_FIELD(arg0, void ***, 0x38), 0);
    }
    temp_r3_40 = M2C_FIELD(arg0, void ***, 0x38);
    M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), M2C_UNK (**)(void **), 0x40)(M2C_FIELD(arg0, void ***, 0x38));
    temp_r3_41 = M2C_FIELD(arg0, void ***, 0x38);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s8 *, 0x260C) = M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x38), s8 (**)(void **), 0x4C)(M2C_FIELD(arg0, void ***, 0x38));
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) lbl_8056208C;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) lbl_8056208C;
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) lbl_8056208C;
    sp18 = lbl_8056208C;
    sp1C = lbl_8056208C;
    sp10 = lbl_8056208C;
    temp_r3_42 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void ***, 0x270);
    M2C_FIELD(*temp_r3_42, M2C_UNK (**)(void **, f32 *, f32 *, M2C_UNK *), 0x28)(temp_r3_42, &sp18, &sp10, &spC);
}
#pragma scheduling on
void fn_80192BE4(void) {

}

#pragma push
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
#pragma cplusplus off

#pragma pop

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

#pragma scheduling invalid_target
extern f32 lbl_8056208C, lbl_80562090, lbl_805620AC;
#pragma scheduling invalid_target
/* Reads a packed byte at +6 in the object's linked data (+8), normalizes it to [0,1], and returns the scaled value. */
f32 fn_80192C7C(void *arg0) {
    u8 byte = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 6);
    u8 raw;
    f32 normalized;
    f32 value;
    raw = (byte & 0xF0) | ((byte >> 4) & 0xF);
    normalized = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_8056208C + value * lbl_80562090;
}
#pragma scheduling on

#pragma scheduling invalid_target
extern f32 lbl_8056208C, lbl_80562090, lbl_805620AC, lbl_80562094, lbl_80562138;
#pragma scheduling invalid_target
f32 fn_80192D10(void *arg0) {
    u8 raw = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 5);
    f32 normalized = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    f32 value;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_80562094 + value * lbl_80562138;
}
#pragma scheduling on
extern f32 lbl_8056208C, lbl_80562090, lbl_80562094, lbl_805620AC, lbl_80562138;
#pragma scheduling invalid_target
f32 fn_80192D98(void *arg0) {
    u8 raw = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 8) + 4);
    f32 normalized = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    f32 value;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)raw - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_80562094 + value * lbl_80562138;
}
#pragma scheduling on

s32 fn_80192E20(void *arg0) {
    s32 bit = *(u8 *)((char *)*(void **)((char *)arg0 + 8) + 7) & 1;
    return (s32)((u32)(-bit | bit) >> 31);
}

#pragma scheduling invalid_target
/* Return a normalized [0..1] value from the swapped low/high nibbles of the byte at state->data[6]. */
f32 fn_80192E3C(void *state) {
    register u32 swappedNibbleByte;
    register u32 packedByte;
    f32 normalized;
    f32 value;
    packedByte = *(u8 *)((u8 *)*(void **)((u8 *)state + 8) + 6);
    swappedNibbleByte = packedByte & 0x0F;
    swappedNibbleByte = __rlwimi(swappedNibbleByte, packedByte, 4, 24, 27);
    normalized = ((f32)swappedNibbleByte - lbl_8056208C) / lbl_805620AC;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)(u8)swappedNibbleByte - lbl_8056208C) / lbl_805620AC;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_8056208C + value * lbl_80562090;
}
#pragma scheduling on

extern f64 lbl_805620B0;
extern f32 lbl_805620B8, lbl_80562084, lbl_805620A4;
#pragma scheduling invalid_target
f32 fn_80192ED0(void *arg0) {
    u16 angle = *(u16 *)*(void **)((u8 *)arg0 + 8);
    f32 normalized = ((f32)angle - lbl_8056208C) / lbl_805620B8;
    f32 value;
    if (lbl_80562090 < normalized) {
        value = lbl_80562090;
    } else {
        value = ((f32)angle - lbl_8056208C) / lbl_805620B8;
    }
    value = value > lbl_8056208C ? value : lbl_8056208C;
    return lbl_80562084 + value * lbl_805620A4;
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

#pragma scheduling on
unsigned char fn_80192F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_80192F74(void *arg0) {
    *(int *)((char *)arg0 + 0xC) = lbl_8055E3C4;
}

extern void *__AXGetStudio_80178C90(void);
extern s32 fn_801B2F54(s32);
extern f32 fn_8018AE3C(void *);
#pragma push
#pragma processor 750
void fn_80192F80(void *source) {
    /* Populate AX studio/state fields from source object data. */
    s32 result;
    f32 value;
    *(s32 *)__AXGetStudio_80178C90() = 0;
    result = fn_801B2F54(*(s32 *)((u8 *)source + 0x3C));
    *(s32 *)((u8 *)__AXGetStudio_80178C90() + 4) = result;
    value = *(f32 *)((u8 *)*(void **)((u8 *)source + 0x34) + 0x25CC);
    *(f32 *)((u8 *)__AXGetStudio_80178C90() + 8) = value;
    value = fn_8018AE3C(*(void **)((u8 *)source + 0x34));
    *(f32 *)((u8 *)__AXGetStudio_80178C90() + 0xC) = value;
    value = ((f32 (*)(void *))fn_8018AE4C)(*(void **)((u8 *)source + 0x34));
    *(f32 *)((u8 *)__AXGetStudio_80178C90() + 0x10) = value;
}
#pragma pop
int fn_80193010(void) { return 0x20; }

void fn_80193018(void *arg0, void *arg1) {
    float *dst = (float *)((u8 *)arg0 + 0x10);
    float *src = (float *)arg1;
    float x = dst[0] + src[0];
    float y = dst[1] + src[1];
    float z = src[2] + dst[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

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

