#include "types.h"

extern "C" void fn_80208D70(void);
extern "C" void *fn_80208D4C(void);
extern "C" void fn_80208D80(int);
extern "C" int fn_801284F8(int, void *);
extern "C" void fn_80208B8C(int);
extern int lbl_8055ED80;
extern unsigned char lbl_8055ED84;
extern "C" void *fn_80207990(void *, void *);
extern "C" void fn_8020A368(void);
extern "C" void fn_802E30C8(const char *, ...);
extern char lbl_8033BC50[];
extern char lbl_8033BC68[];

struct Rec80207490 { void *v; int pad[2]; };
struct Obj80207490 {
    char pad0[0x10]; void *key; char pad1[4]; bool flag18; char pad2[0x55]; bool flag6e;
};

class Obj80206518 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14();
};
class Dispatch80206B14 {
public:
    virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3();
    virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7();
    virtual void pad8(); virtual void pad9();
    virtual void f12(float); virtual void f13(float);
    virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17();
    virtual void pad18(); virtual void pad19(); virtual void f19(int);
};
class Dispatch4_80206B14 {
public:
    virtual void pad0(); virtual void pad1();
    virtual void f4(int, int);
};
class ObjIface80207218 {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21();
    virtual float get();
};
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8033BDC0;
__declspec(section ".rodata") extern char lbl_8033BDC0;
extern int lbl_8055ED80;
extern "C" void fn_80208620(int, void *);
extern "C" void fn_8020899C(int, int);
extern "C" int fn_80128668(void *);
extern "C" void fn_802073A4(void*, int, int);
extern int lbl_8055ED8C;
extern void *lbl_8055ED90;
extern char lbl_8033BD3C[];
extern char lbl_8033BD4C[];
extern char lbl_8055B4C0[8];
extern char lbl_8055B4C8[8];
extern "C" void *fn_80206BF8(int, void*);
extern int lbl_8055ED80;
extern float lbl_805631F8;
extern "C" void *fn_80208994(int, int, int, float);
extern "C" void fn_802085E8(int, void *);
__declspec(section ".rodata") extern char lbl_8033BD90;
extern float lbl_805631FC;
extern float lbl_80563200;
extern float lbl_80563204;
extern "C" int fn_8012A364(void*, void*);
extern "C" int fn_801284F8(int, void*);
extern "C" void *fn_8012A13C(void *, void *, int, int);
extern "C" int fn_8012A2D8(void*);
extern "C" float PSVECMag(void*);

extern void *lbl_8055ED88;
extern "C" void fn_8020A400(void);
extern "C" void fn_80208D80(int);
extern unsigned char lbl_8055ED84;
#pragma scheduling invalid_target
extern "C" int fn_802062E8(void) {
    struct Service {
        virtual void f0();
        virtual int f1();
    };
    struct Dispose {
        virtual void f0(int);
    };
    int mixerName;
    void *soundManager;

    /* Initialize the sound system and SoundManager; returns 1 on success, 0 on failure. */
    fn_80208B8C(lbl_8055ED84 == 0);
    fn_80208D70();
    mixerName = ((Service *)fn_80208D4C())->f1();
    fn_802E30C8(lbl_8033BC50, mixerName); /* "using sound mixer %s" */
    soundManager = (void *)fn_801284F8(0x118, lbl_8033BC68); /* "SoundManager" */
    if (soundManager != 0) {
        fn_80208D70();
        soundManager = fn_80207990(soundManager, fn_80208D4C());
    }
    lbl_8055ED80 = (int)soundManager;
    if (soundManager != 0) {
        if (((unsigned char *)soundManager)[4] != 0) {
            fn_8020A368();
            return 1;
        }
        if (soundManager != 0)
            ((Dispose *)soundManager)->f0(1);
        lbl_8055ED80 = 0;
    }
    fn_80208D80(lbl_8055ED84 == 0);
    return 0;
}
#pragma scheduling on
extern "C" void fn_802063D8(void) {
    extern int lbl_8055ED80;
    struct Callback { virtual void slot0(int); };
    fn_8020A400();
    if (lbl_8055ED80)
        ((Callback *)lbl_8055ED80)->slot0(1);
    int value = lbl_8055ED84 == 0;
    lbl_8055ED80 = 0;
    fn_80208D80(value);
}

extern "C" int fn_80206430(void) {
    extern int lbl_8055ED80;
    int val = lbl_8055ED80;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}

extern "C" void fn_80206444(void) {
    extern int lbl_8055ED80;
    ((u8 *)lbl_8055ED80)[5] = 1;
}

extern "C" void fn_80206454(void) {
    extern int lbl_8055ED80;
    ((u8 *)lbl_8055ED80)[5] = 0;
}

extern "C" void fn_80206464(void* hi) {
    lbl_8055ED88 = hi;
}

extern "C" void fn_8020646C(long, long);
extern long lbl_804891E8[];
extern "C" void fn_8020646C(long arg0, long arg1) {
    lbl_804891E8[arg0] = arg1;
}

extern "C" void fn_80206480(void) {
}

extern "C" void fn_80208D70(void);
extern "C" void *fn_80208D4C(void);
extern "C" int fn_80206430(void);
extern "C" void fn_80206484(int arg0) {
    struct Callback80206484 {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual void call(int);
    };
    fn_80208D70();
    ((Callback80206484 *)fn_80208D4C())->call(arg0);
}

extern "C" void fn_802064C8(void) {
}

extern "C" void fn_802064CC(void) {
}

extern "C" void fn_802064D0(int arg0) {
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10();
        virtual void call(int);
    };
    fn_80208D70();
    ((Callback *)fn_80208D4C())->call(arg0);
}

extern "C" void fn_80206514(void) {
}

extern "C" void fn_80206518(void) {
    extern void fn_80208D70(void); extern void* fn_80208D4C(void);
    fn_80208D70();
    ((Obj80206518*)fn_80208D4C())->f12();
}

extern "C" void fn_8020654C(void) {
}

extern "C" void fn_80206550(unsigned int size) {
    extern int lbl_8055ED80; extern void* fn_80207C74(int, unsigned int);
    fn_80207C74(lbl_8055ED80, size);
}

extern int lbl_8055ED80;
extern "C" int fn_80207C50(int,int,int);
extern "C" void fn_8020655C(int a, int b) { fn_80207C50(lbl_8055ED80,a,b); }

extern void* fn_80207C74(int, unsigned int);
extern int lbl_802F9DA0[10];
extern void* fn_80208D4C(void);
extern void fn_80208D70(void);
extern char lbl_8033BD30[];
extern "C" void *fn_80206570(int index) {
    struct Values {
        int value[10];
    };
    struct Values values = *(struct Values *)&lbl_802F9DA0;
    if (index < 10)
        return (void *)values.value[index];
    return lbl_8033BD30;
}

extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" void *fn_802065F8(void *arg0, int arg1, int arg2) {
    char *self = (char *)arg0;
    *(void **)self = &lbl_8033BDC0;
    strncpy(self + 0x37, (const char *)arg1, 0xC);
    float zero = lbl_805631FC;
    register int zeroInt = 0;
    register int oneInt = 1;
    float one = lbl_805631F8;
    int neg = -0x64;
    self[0x43] = zeroInt;
    *(int *)(self + 0xC) = zeroInt;
    *(int *)(self + 0x44) = arg2;
    *(float *)(self + 4) = one;
    *(float *)(self + 8) = one;
    self[0x49] = zeroInt;
    self[0x48] = zeroInt;
    self[0x4A] = oneInt;
    self[0x4C] = zeroInt;
    self[0x4B] = zeroInt;
    self[0x4E] = oneInt;
    self[0x4D] = oneInt;
    self[0x4F] = oneInt;
    *(int *)(self + 0x10) = neg;
    *(int *)(self + 0x14) = zeroInt;
    self[0x18] = zeroInt;
    self[0x19] = zeroInt;
    *(float *)(self + 0x20) = zero;
    *(float *)(self + 0x1C) = one;
    *(float *)(self + 0x24) = zero;
    *(int *)(self + 0x50) = zeroInt;
    *(float *)(self + 0x28) = zero;
    self[0x34] = oneInt;
    *(float *)(self + 0x2C) = zero;
    self[0x35] = oneInt;
    *(float *)(self + 0x30) = zero;
    self[0x36] = oneInt;
    return arg0;
}

#pragma dont_inline on
extern "C" void *fn_802066C8(void *arg0, u32 arg1) {
    if (arg0 != 0) {
        int value = *(int *)((char *)arg0 + 0xC);
        *(void **)arg0 = (void *)&lbl_8033BDC0;
        if (value != 0) {
            fn_80208620(lbl_8055ED80, arg0);
            fn_8020899C(lbl_8055ED80, *(int *)((char *)arg0 + 0xC));
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        if ((int)arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma dont_inline reset

extern "C" void fn_80206750(void *arg0, int arg1, int arg2) {
    int count = (int)(long)lbl_8055ED88;
    int found = -1;
    int i = 0;
    for (; i < count; i++) {
        if (arg1 == lbl_804891E8[i]) {
            found = i;
            break;
        }
    }
    if (found >= 0 && arg2) {
        *(unsigned char *)((char *)arg0 + 0x4F) = 1;
        *(int *)((char *)arg0 + 0x14) = 1 << found;
    } else {
        *(int *)((char *)arg0 + 0x14) = 0;
        *(unsigned char *)((char *)arg0 + 0x4F) = 1;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_802067C8(void *arg0, void *arg1, int arg2) {
    struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(void *, int); };
    int fieldEmpty = !*(int *)((u8 *)arg0 + 0x44);
    if ((*(u8 *)((u8 *)arg0 + 0x18) = (*(u8 *)((u8 *)arg0 + 0x19) != 0 &&
        (*(float *)((u8 *)arg0 + 8) > lbl_80563200 || fieldEmpty)))) {
        ((Obj *)arg0)->f3(arg1, arg2);
    }
}
#pragma scheduling on
extern "C" void fn_80206820(void) {
}

extern "C" void fn_80206824(void *arg0, int arg1, int arg2) {
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual int f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(void *);
    };
    struct Parent { virtual void f0(); virtual void f1(int, int); };
    extern int lbl_8055D430;
    u8 *self = (u8 *)arg0;
#define CB (*(Callback **)(self + 0xC))
    int state = CB->f7();
    self[0x19] = 1;
    switch (state) {
    case 1:
        if (self[0x4A]) {
            CB->f6();
        } else if (self[0x48]) {
            CB->f8();
        } else if (self[0x4C]) {
            self[0x4C] = 0;
            CB->f6();
        }
        break;
    case 3:
        if (self[0x49]) {
            bool ok = false;
            if ((lbl_8055D430 & 1) && (lbl_8055D430 & 0x200))
                ok = true;
            if (ok && *(int *)(self + 0x44) != 0)
                goto skip;
            {
                u8 flag = self[0x4B];
                self[0x49] = 0;
                if (flag)
                    CB->f5();
                else
                    CB->f4();
            }
        } else {
skip:
            self[0x19] = 0;
        }
        if (self[0x48])
            CB->f8();
        break;
    case 2:
        if (!self[0x48]) {
            if (self[0x4A])
                CB->f6();
            else
                CB->f9();
        }
        break;
    }
    if (*(int *)(self + 0x50)) {
        CB->f21(self + 0x50);
        *(int *)(self + 0x50) = 0;
    }
    if (!self[0x48]) {
        ((Parent *)arg0)->f1(arg1, arg2);
    }
#undef CB
}

extern "C" void fn_80206A5C(void* arg0) {
    unsigned char* p = (unsigned char*)arg0;
    class Dispatch {
    public:
        virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3();
        virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7();
        virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11();
        virtual void pad12(); virtual void pad13(); virtual void pad14();
        virtual void f17(float); virtual void f18(float); virtual void f19(float);
    };
    if (p[0x34]) {
        p[0x34] = 0;
        ((Dispatch*)*(void**)(p + 0xC))->f17(*(float*)((char*)arg0 + 0x28));
    }
    if (p[0x35]) {
        void* obj = *(void**)(p + 0xC);
        p[0x35] = 0;
        ((Dispatch*)obj)->f18(*(float*)(p + 0x2C));
    }
    if (p[0x36]) {
        void* obj = *(void**)(p + 0xC);
        p[0x36] = 0;
        ((Dispatch*)obj)->f19(*(float*)(p + 0x30));
    }
}

extern "C" void fn_80206B08(void) {
	return;
}

extern "C" void fn_80206B0C(void) {
	return;
}

extern "C" void fn_80206B10(void) {
	return;
}

#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80206B14(void *arg0, int arg1, int arg2) {
    /* Dispatch queued float/int commands then forward (arg1,arg2) via vtable slot 4. */
    unsigned char *p = (unsigned char *)arg0;
    if (p[0x4D]) {
        p[0x4D] = 0;
        ((Dispatch80206B14 *)*(void **)(p + 0xC))->f13(*(float *)((char *)arg0 + 8));
    }
    if (p[0x4E]) {
        void *obj = *(void **)(p + 0xC);
        p[0x4E] = 0;
        ((Dispatch80206B14 *)obj)->f12(*(float *)(p + 4));
    }
    if (p[0x4F]) {
        void *obj = *(void **)(p + 0xC);
        p[0x4F] = 0;
        ((Dispatch80206B14 *)obj)->f19(*(int *)(p + 0x14));
    }
    ((Dispatch4_80206B14 *)arg0)->f4(arg1, arg2);
}
#pragma scheduling on
#pragma dont_inline reset
extern "C" void fn_80206BF4(void) {
	return;
}

#pragma dont_inline on
extern "C" void *fn_80206BF8(int arg0, void *arg1) {
    void *value;
    (void)arg0;
    (void)arg1;
    if (lbl_8055ED8C == 0) {
        value = (void *)fn_801284F8(0x20, lbl_8033BD3C);
        if (value != 0) {
            value = fn_8012A13C(value, lbl_8033BD3C, 0xC0, 0x78);
        }
        lbl_8055ED90 = value;
    }
    if (fn_8012A2D8(lbl_8055ED90) != 0) {
        lbl_8055ED8C += 1;
    }
}
#pragma dont_inline off

extern float lbl_80563200;
extern char lbl_8033BDC0;
__declspec(section ".rodata") extern char lbl_8033BDC0;
extern "C" void fn_80208620(int, void *);
extern "C" void fn_8020899C(int, int);
extern "C" int fn_80128668(void *);
extern "C" void fn_80206C70(void *arg0) {
    struct Callback {
        virtual void slot1(int);
        virtual void slot0();
    };
    fn_8012A364(lbl_8055ED90, arg0);
    if (--lbl_8055ED8C == 0) {
        if (lbl_8055ED90)
            ((Callback *)lbl_8055ED90)->slot1(1);
        lbl_8055ED90 = 0;
    }
}

#pragma push
#pragma processor 750
extern "C" float fn_80206CD0(void* arg0, float arg1) {
    float f = lbl_805631FC;
    float x = lbl_80563204 * *(float*)((char*)arg0 + 8);
    f = (f > x) ? f : x;
    float y = PSVECMag(arg0) - f;
    y = (y > arg1) ? y : arg1;
    return arg1 / y;
}
#pragma pop
extern "C" float PSVECDotProduct(const void*, const void*);
extern float lbl_805631F8, lbl_805631FC, lbl_80563208;
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80206D3C(void *self, void *list, int count) {
    register unsigned char *p = (unsigned char *)self;
    float vec[3];
    register int i;
    register unsigned char *it;

    p[0x64] = 0;
    *(float *)(p + 0x68) = lbl_805631FC;
    if (p[0x18]) {
        register float threshold = lbl_805631F8;
        register float margin = lbl_80563208;
        it = (unsigned char *)list;
        for (i = 0; i < count; ++i, it += 0xC) {
            register float *pos = *(float **)(p + 0x74);
            register unsigned char *item = *(unsigned char **)(it + 4);
            float dx = pos[0] - *(float *)(item + 0x24);
            vec[0] = dx;
            float dy = pos[1] - *(float *)(item + 0x28);
            vec[1] = dy;
            float dz = pos[2] - *(float *)(item + 0x2C);
            vec[2] = dz;
            float outX = dx * *(float *)item +
                         dy * *(float *)(item + 4) +
                         dz * *(float *)(item + 8);
            float outY = dx * *(float *)(item + 0xC) +
                         dy * *(float *)(item + 0x10) +
                         dz * *(float *)(item + 0x14);
            float outZ = dx * *(float *)(item + 0x18) +
                         dy * *(float *)(item + 0x1C) +
                         dz * *(float *)(item + 0x20);
            vec[0] = outX;
            vec[1] = outY;
            vec[2] = outZ;
            float dot = PSVECDotProduct(vec, vec);
            float radius = margin + *(float *)(p + 0x6C);
            if (dot < radius * radius) {
                float value = *(float *)(p + 8);
                p[0x64] = 1;
                if (value >= threshold) value = threshold;
                value *= fn_80206CD0(vec, *(float *)(p + 0x6C));
                if (*(float *)(p + 0x68) > value) {
                } else {
                    *(float *)(p + 0x68) = value;
                }
            }
        }
        if (!p[0x64]) p[0x18] = 0;
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern "C" void *fn_802065F8(void *, int, int);
#define fn_802065F8() fn_802065F8(arg0, arg1, arg2)
extern "C" void *fn_80208998(int, int, int, float);
extern "C" void fn_802085EC(int, void *);
extern float lbl_80563220;
extern char lbl_8033BDA8;
__declspec(section ".rodata") extern char lbl_8033BDA8;
#pragma scheduling invalid_target
extern "C" void *fn_80207218(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    ObjIface80207218 *obj;
    float value;
    float value2;
    void *vtable;
    fn_802065F8();
    value = *(volatile float *)&lbl_805631FC;
    vtable = &lbl_8033BDA8;
    value2 = *(volatile float *)&lbl_80563220;
    *(volatile void **)arg0 = vtable;
    *(float *)((char *)arg0 + 0x68) = value;
    *(float *)((char *)arg0 + 0x6C) = value2;
    *(char *)((char *)arg0 + 0x64) = 1;
    *(int *)((char *)arg0 + 0x70) = arg3;
    *(int *)((char *)arg0 + 0x74) = arg4;
    obj = (ObjIface80207218 *)fn_80208998(lbl_8055ED80, arg1, arg2, value);
    *(ObjIface80207218 **)((char *)arg0 + 0xC) = obj;
    if (obj != 0)
        fn_802085EC(lbl_8055ED80, arg0);
    obj = *(ObjIface80207218 **)((char *)arg0 + 0xC);
    if (obj != 0)
        value = obj->get();
    else
        value = lbl_805631FC;
    *(float *)((char *)arg0 + 0x24) = value;
    return arg0;
}
#pragma scheduling on
extern "C" f32 fn_802072DC(void) {
    return lbl_805631FC;
}

#pragma scheduling invalid_target
extern "C" void *fn_802072E4(void *arg0, int arg1, int arg2) {
    void *vtable;
    float value;
    float value2;
    void *obj;
    fn_802065F8();
    value = *(volatile float *)&lbl_805631FC;
    vtable = &lbl_8033BD90;
    value2 = *(volatile float *)&lbl_805631F8;
    *(void **)arg0 = vtable;
    *(float *)((char *)arg0 + 0x64) = value;
    *(char *)((char *)arg0 + 0x6C) = 1;
    *(float *)((char *)arg0 + 0x68) = value2;
    *(char *)((char *)arg0 + 0x6D) = 1;
    obj = fn_80208994(lbl_8055ED80, arg1, arg2, value);
    *(void **)((char *)arg0 + 0xC) = obj;
    if (obj != 0)
        fn_802085E8(lbl_8055ED80, arg0);
    obj = *(void **)((char *)arg0 + 0xC);
    if (obj != 0) {
        struct Cb {
            virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
            virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
            virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
            virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
            virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
            virtual void m20(); virtual void m21();
            virtual float get();
        };
        value = ((Cb *)obj)->get();
    } else {
        value = lbl_805631FC;
    }
    *(float *)((char *)arg0 + 0x24) = value;
    return arg0;
}
#pragma scheduling on
extern "C" void fn_802073A4(void* arg0, int arg1, int arg2) {
    class Dispatch {
    public:
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
        virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
        virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
        virtual void p12();
        virtual void f0(float);
        virtual void f1(float);
    };
    fn_80206B14(arg0, arg1, arg2);
    unsigned char* p = (unsigned char*)arg0;
    if (p[0x6c] != 0) {
        void* obj = *(void**)(p + 0x0c);
        p[0x6c] = 0;
        ((Dispatch*)obj)->f0(*(float*)(p + 0x64));
    }
    if (p[0x6d] != 0) {
        void* obj = *(void**)(p + 0x0c);
        p[0x6d] = 0;
        ((Dispatch*)obj)->f1(*(float*)(p + 0x68));
    }
}

extern "C" void *fn_802072E4(void *, int, int);
#undef fn_802065F8
extern void fn_802085E8(int, void *);
extern void *fn_80208994(int, int, int, float);
extern float lbl_805631F8;
__declspec(section ".rodata") extern char lbl_8033BD90;
extern char lbl_8033BD78;
#pragma dont_inline on
__declspec(section ".rodata") extern char lbl_8033BD78;
extern "C" void *fn_80207428(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    void *self = arg0;
    fn_802072E4(self, arg1, arg2);
    *(int *)((char *)self + 0x10) = arg3;
    *(void **)self = &lbl_8033BD78;
    fn_80206750(self, arg3, arg4);
    return self;
}

extern "C" void fn_80207490(Obj80207490 *obj, Rec80207490 *arr, int n) {
    obj->flag6e = 0;
    for (int i = 0; i < n; i++) {
        obj->flag6e = (obj->flag6e | (obj->key == arr[i].v)) != 0;
    }
    obj->flag18 = (obj->flag18 & obj->flag6e) != 0;
}

#pragma dont_inline reset
#pragma dont_inline on
extern "C" void fn_8020769C(void* arg0, int arg1, int arg2) {
	fn_802073A4(arg0, arg1, arg2);
}

extern "C" void *fn_802076A0(int arg0, int arg1, int arg2, int arg3) {
    struct Callback {
        virtual ~Callback();
    };
    void *obj = (void *)fn_801284F8(0x70, lbl_8033BD4C);
    if (obj != 0)
        obj = fn_80207428(obj, arg0, arg1, arg2, arg3);
    if (obj != 0 && *(int *)((char *)obj + 0xC) == 0) {
        delete (Callback *)obj;
        obj = 0;
    }
    return obj;
}

#pragma dont_inline reset

extern "C" void *fn_802066C8(void*, u32);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80207748(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_802066C8(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma scheduling on
extern "C" void *fn_802077A4(int arg0, int arg1, int arg2, int arg3) {
    struct Callback { virtual ~Callback(); };
    void *obj = fn_80206BF8(0x78, lbl_8055B4C0);
    if (obj != 0)
        obj = fn_80207218(obj, arg0, arg1, arg2, arg3);
    if (obj != 0 && *(int *)((char *)obj + 0xC) == 0) {
        delete (Callback *)obj;
        obj = 0;
    }
    return obj;
}

extern "C" void *fn_80207848(int arg0, int arg1) {
    struct Callback { virtual ~Callback(); };
    void *obj = (void *)fn_801284F8(0x70, lbl_8055B4C8);
    if (obj != 0)
        obj = fn_802072E4(obj, arg0, arg1);
    if (obj != 0 && *(int *)((char *)obj + 0xC) == 0) {
        delete (Callback *)obj;
        obj = 0;
    }
    return obj;
}

#pragma scheduling invalid_target
extern "C" void *fn_802078CC(int arg0, int arg1, void *arg2) {
    void *value = arg2;
    if (arg2 != 0) {
        value = fn_802072E4(arg2, arg0, arg1);
    }
    return (*(int *)((u8 *)value + 0xC) != 0) ? value : 0;
}
#pragma scheduling on
extern "C" void fn_80207924(void *arg0) {
    struct Obj { virtual void v0(int); };
    ((Obj *)arg0)->v0(-1);
}

extern int lbl_8055ED94;
extern char lbl_8033BD58[];
extern "C" void fn_80206B14(void *, int, int);
extern "C" void *fn_802072E4(void *, int, int);
extern "C" void fn_802E30C8(const char *, ...);
extern int lbl_8055ED94;
extern "C" void fn_802E30C8(const char *, ...);
// Keep the format label array-typed so MWCC emits the original lis/addi address load.
extern "C" void fn_80207938(int arg0) {
    fn_802E30C8(lbl_8033BD58, ++lbl_8055ED94, arg0);
}

