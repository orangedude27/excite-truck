#include "types.h"

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
extern int lbl_8055ED80;
extern "C" void fn_80208620(int, void *);
extern "C" void fn_8020899C(int, int);
extern "C" int fn_80128668(void *);
extern "C" void fn_802073A4(void);
extern int lbl_8055ED8C;
extern void *lbl_8055ED90;
extern char lbl_8033BD3C;
extern char lbl_8033BD4C;
extern char lbl_8055B4C0[8];
extern char lbl_8055B4C8[];
extern "C" void *fn_80206BF8(int, void*);
extern int lbl_8055ED80;
extern float lbl_805631F8;
extern "C" void *fn_80208994(int, int, int, float);
extern "C" void fn_802085E8(int, void *);
extern char lbl_8033BD90;
extern float lbl_805631FC;
extern float lbl_80563204;
extern "C" int fn_8012A364(void*, void*);
extern "C" int fn_801284F8(int, void*);
extern "C" void *fn_8012A13C(void*, int, int);
extern "C" int fn_8012A2D8(void*);
extern "C" float PSVECMag(void*);

extern void *lbl_8055ED88;
extern "C" void fn_8020A400(void);
extern "C" void fn_80208D80(int);
extern unsigned char lbl_8055ED84;
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
    *(unsigned char*)((unsigned char*)&lbl_8055ED80 + 5) = 0;
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
    extern void fn_80208D70(void);
    extern void *fn_80208D4C(void);
    fn_80208D70();
    void *obj = fn_80208D4C();
    void **vtable = *(void ***)obj;
    ((void (*)(void *, int))vtable[11])(obj, arg0);
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
extern int lbl_802F9DA0;
extern void* fn_80208D4C(void);
extern void fn_80208D70(void);
extern "C" void* fn_80206570(int index) {
    int values[10]; int* p=(int*)&lbl_802F9DA0; int i;
    for(i=0;i<10;i++) values[i]=p[i];
    if(index<10) return (void*)values[index];
    return (void*)0x8033BD30;
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

extern "C" void fn_80206820(void) {
}

extern "C" void fn_80206A5C(void* arg0) {
    if (*(unsigned char*)((char*)arg0 + 0x34)) {
        float value = *(float*)((char*)arg0 + 0x28);
        *(unsigned char*)((char*)arg0 + 0x34) = 0;
        void* obj = *(void**)((char*)arg0 + 0xC);
        void** vtable = *(void***)obj;
        ((void (*)(void*, float))vtable[0x44 / 4])(obj, value);
    }
    if (*(unsigned char*)((char*)arg0 + 0x35)) {
        void* obj = *(void**)((char*)arg0 + 0xC);
        *(unsigned char*)((char*)arg0 + 0x35) = 0;
        float value = *(float*)((char*)arg0 + 0x2C);
        void** vtable = *(void***)obj;
        ((void (*)(void*, float))vtable[0x48 / 4])(obj, value);
    }
    if (*(unsigned char*)((char*)arg0 + 0x36)) {
        void* obj = *(void**)((char*)arg0 + 0xC);
        *(unsigned char*)((char*)arg0 + 0x36) = 0;
        float value = *(float*)((char*)arg0 + 0x30);
        void** vtable = *(void***)obj;
        ((void (*)(void*, float))vtable[0x4C / 4])(obj, value);
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

extern "C" void fn_80206B14(void *arg0, int arg1, int arg2) {
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

extern "C" void fn_80206BF4(void) {
	return;
}

extern float lbl_80563200;
extern char lbl_8033BDC0;
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

extern "C" float fn_80206CD0(void* arg0, float arg1) {
    float f = lbl_805631FC;
    float x = lbl_80563204 * *(float*)((char*)arg0 + 8);
    if (f <= x) f = x;
    float y = PSVECMag(arg0) - f;
    if (y <= arg1) y = arg1;
    return arg1 / y;
}

extern "C" void fn_802065F8(void);
extern "C" void *fn_80208998(int, int, int, float);
extern "C" void fn_802085EC(int, void *);
extern float lbl_80563220;
extern char lbl_8033BDA8;
__declspec(section ".rodata") extern char lbl_8033BDA8;
extern "C" void *fn_80207218(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    float value;
    ObjIface80207218 *obj;
    fn_802065F8();
    value = lbl_805631FC;
    *(void **)arg0 = &lbl_8033BDA8;
    *(float *)((char *)arg0 + 0x68) = value;
    *(float *)((char *)arg0 + 0x6C) = lbl_80563220;
    *(char *)((char *)arg0 + 0x64) = 1;
    *(int *)((char *)arg0 + 0x70) = arg3;
    *(int *)((char *)arg0 + 0x74) = arg4;
    obj = (ObjIface80207218 *)fn_80208998(lbl_8055ED80, arg1, arg2, lbl_805631FC);
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

extern "C" f32 fn_802072DC(void) {
    return lbl_805631FC;
}

extern "C" void *fn_802072E4(void *arg0, int arg1, int arg2) {
    float value;
    struct Callback {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
        virtual float get();
    };
    fn_802065F8();
    value = lbl_805631FC;
    *(void **)arg0 = &lbl_8033BD90;
    *(float *)((char *)arg0 + 0x64) = value;
    *(char *)((char *)arg0 + 0x6C) = 1;
    *(float *)((char *)arg0 + 0x68) = lbl_805631F8;
    *(char *)((char *)arg0 + 0x6D) = 1;
    *(void **)((char *)arg0 + 0xC) = fn_80208994(lbl_8055ED80, arg1, arg2, lbl_805631FC);
    if (*(void **)((char *)arg0 + 0xC))
        fn_802085E8(lbl_8055ED80, arg0);
    if (*(void **)((char *)arg0 + 0xC))
        value = ((Callback *)*(void **)((char *)arg0 + 0xC))->get();
    else
        value = lbl_805631FC;
    *(float *)((char *)arg0 + 0x24) = value;
    return arg0;
}

extern "C" void *fn_802072E4(void *, int, int);
extern void fn_802065F8(void);
extern void fn_802085E8(int, void *);
extern void *fn_80208994(int, int, int, float);
extern float lbl_805631F8;
extern char lbl_8033BD90;
extern char lbl_8033BD78;
#pragma dont_inline on
__declspec(section ".rodata") extern char lbl_8033BD78;
extern "C" void *fn_80207428(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    fn_802072E4(arg0, arg1, arg2);
    *(void **)arg0 = &lbl_8033BD78;
    *(int *)((char *)arg0 + 0x10) = arg3;
    fn_80206750(arg0, arg3, arg4);
    return arg0;
}

extern "C" void fn_80207490(void *arg0, void *arg1, int arg2) {
    int i = 0;
    *(unsigned char *)((char *)arg0 + 0x6E) = 0;
    if (arg2 > 0 && (unsigned)arg2 < 0x7fffffffU) {
        if (arg2 > 8) {
            int n = arg2 - 8;
            int blocks = (n + 7) >> 3;
            int *p = (int *)arg1;
            do {
                int key = *(int *)((char *)arg0 + 0x10);
                unsigned int found = (key == p[0]) | (key == p[3]) | (key == p[6]) | (key == p[9]) |
                                     (key == p[12]) | (key == p[15]) | (key == p[18]) | (key == p[21]);
                *(unsigned char *)((char *)arg0 + 0x6E) |= found;
                p += 24;
                i += 8;
            } while (--blocks);
        }
        for (; i < arg2; i++) {
            int key = *(int *)((char *)arg0 + 0x10);
            int value = *(int *)((char *)arg1 + i * 12);
            *(unsigned char *)((char *)arg0 + 0x6E) |= key == value;
        }
    }
    *(unsigned char *)((char *)arg0 + 0x18) =
        ((*(unsigned char *)((char *)arg0 + 0x18) & *(unsigned char *)((char *)arg0 + 0x6E)) != 0);
}

#pragma dont_inline reset
extern "C" void fn_8020769C(void) {
	fn_802073A4();
}

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
#pragma scheduling reset
extern "C" void *fn_802078CC(int arg0, int arg1, void *arg2) {
    void *value = arg2;
    if (arg2 != 0) {
        value = fn_802072E4(arg2, arg0, arg1);
    }
    return (*(int *)((u8 *)value + 0xC) != 0) ? value : 0;
}

extern "C" void fn_80207924(void *arg0) {
    struct Obj { virtual void v0(int); };
    ((Obj *)arg0)->v0(-1);
}

extern int lbl_8055ED94;
extern char lbl_8033BD58;
extern "C" void fn_80206B14(void *, int, int);
extern "C" void *fn_802072E4(void *, int, int);
extern "C" void fn_802E30C8(const char *, ...);
extern int lbl_8055ED94;
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_80207938(int arg0) {
    fn_802E30C8(&lbl_8033BD58, ++lbl_8055ED94, arg0);
}

