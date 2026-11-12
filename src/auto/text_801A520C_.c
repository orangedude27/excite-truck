void fn_8018956C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct D_801A520C {
    void **vtable;
    void *pad0; void *pad1; void *pad2; void *pad3; void *pad4; void *pad5; void *pad7; void *pad8; void *pad9;
    int (*d5)(struct D_801A520C *);
} D_801A520C;

void fn_8018B0D8(void *, int, int, int *, int *, float);
int fn_8018BA54();
void fn_80189CB4(void);
void fn_8018AF00(void);
void fn_80183DF8(void);
void fn_8018381C(void);
extern float lbl_805623C8, lbl_805623EC, lbl_805623F4, lbl_805623F8, lbl_805623FC, lbl_80562400;
extern int lbl_8055E3C4;
extern char lbl_80333C20[];
extern int lbl_80435050[];
extern void fn_801A5AD0(void *, unsigned int, void *, void *);
extern void fn_802E30C8(const char *, ...);
int fn_801E9E30(void *, int *, int *);
void *fn_801B83A0(void);
void fn_80265D3C(void *);
void fn_801836E0(void *, int);
void fn_80128668(void *);
void fn_80182010(void);
void fn_80182074(void);
void fn_8018B09C(void);
int fn_80265D38(void *, int);
extern char lbl_80333C48[];
extern float PSVECDotProduct(float *, float *);
void *fn_801A520C(void *arg0, void *arg1) {
    fn_80182010();
    *(void **)((char *)arg0 + 0x270C) = arg1;
    *(void **)arg0 = lbl_80333C48;
    return (void *)((char *)arg0 + 0);
}

#pragma cplusplus on
struct Dummy_801A5258_v2 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2(void *, void *) {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
};
struct Dummy_801A5660 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10() {}
    virtual void d11() {}
};
struct Dummy_801A5258 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2(void *, void *, void *) {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10(void *) {}
};
#pragma cplusplus on
extern "C" void fn_801A5258(void *self, void *initData) {
    /* Reset this object's runtime state, bind/init its subobject, and clear transient timers. */
    class SubobjectVTable {
    public:
        virtual void f0();
        virtual void f2(void *owner, void *data);
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f9();
    };
    SubobjectVTable *subobj;
    float zero;

    fn_80182074();
    fn_80265D38(self, *(int *)((char *)self + 0x1EC));

    subobj = (SubobjectVTable *)*(void **)((char *)self + 0x270C);
    *(int *)((char *)self + 0x2708) = 0;
    *(unsigned char *)((char *)self + 0x2704) = 0;
    *(int *)((char *)self + 0x2700) = 0;
    subobj->f2(self, initData);

    subobj = (SubobjectVTable *)*(void **)((char *)self + 0x270C);
    subobj->f9();

    zero = lbl_805623C8;
    *(int *)((char *)self + 0x2714) = 1;
    *(int *)((char *)self + 0x2720) = 0;
    *(float *)((char *)self + 0x271C) = zero;
    *(float *)((char *)self + 0x2718) = zero;
    *(unsigned char *)((char *)self + 0x2710) = 0;
}
#pragma cplusplus on
extern "C" void fn_801A5300(void *arg0, void **arg1) {
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2(void *);
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f9();
        virtual void f10();
    };
    Obj *old = *(Obj **)((char *)arg0 + 0x270C);
    if (old != 0) {
        old->f10();
    }
    *(void **)((char *)arg0 + 0x270C) = (void *)arg1;
    if (arg1 != 0) {
        ((Obj *)arg1)->f2(arg0);
        ((Obj *)*(void **)((char *)arg0 + 0x270C))->f9();
    }
}
#pragma cplusplus on
extern "C" void *fn_801A538C(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void f0(int);
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333C48;
        fn_80265D3C(arg0);
        obj = *(void **)((char *)arg0 + 0x270C);
        ((Obj *)obj)->f8();
        obj = *(void **)((char *)arg0 + 0x270C);
        if (obj != 0)
            ((Obj *)obj)->f0(1);
        *(volatile void **)((char *)arg0 + 0x270C) = 0;
        fn_801836E0(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
extern "C" void fn_801A5434(void *arg0) {
    /* Periodically validate this object's position and notify via v41 if stuck. */
    class Obj {
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
        virtual void f41(int);
    };
    int count;
    int position[3];
    int first;
    int second;
    void *obj;
    count = *(int *)((char *)arg0 + 0x2700);
    if (count == 0 &&
        ((lbl_8055E3C4 + *(int *)((char *)arg0 + 0x1EC)) & 0x1F) != 0)
        return;
    first = *(int *)((char *)arg0 + 0x60);
    second = *(int *)((char *)arg0 + 0x64);
    position[0] = first;
    position[1] = second;
    position[2] = *(int *)((char *)arg0 + 0x68);
    if (((int (*)(void *, int *, int))fn_801E9E30)((char *)arg0 + 0x6C, position, first) == 0) {
        *(int *)((char *)arg0 + 0x2700) = *(int *)((char *)arg0 + 0x2700) + 1;
    } else {
        *(int *)((char *)arg0 + 0x2700) = 0;
    }
    if (*(int *)((char *)arg0 + 0x2700) > 10) {
        obj = fn_801B83A0();
        ((Obj *)obj)->f41(*(int *)((char *)arg0 + 0x1EC));
        *(int *)((char *)arg0 + 0x2700) = 0;
    }
}
extern "C" void fn_80186DE4(void);
extern "C" void fn_801A5434(void *);
extern "C" void fn_801A56A0(void *, void *, float *);
extern "C" void fn_801A61B0(void *, void *, float);
extern unsigned char lbl_8055A518;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801A54EC(void *arg0) {
    /* Updates an object: runs per-frame helpers, conditionally refreshes state from a subobject, and initializes 8 child entries. */
    struct Dummy11 {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    };
    struct Dummy7 {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void *f5();
    };
    void *obj;
    void *ret;
    float vec[3];
    unsigned int i;
    char *base = (char *)arg0;
    fn_80186DE4();
    fn_801A5434(arg0);
    ((Dummy11 *)*(void **)(base + 0x270C))->f9();
    if (*(unsigned char *)(base + 0x2710) != 0 && lbl_8055A518 != 0) {
        ret = ((Dummy7 *)*(void **)(base + 0x270))->f5();
        fn_801A61B0(base + 0x2714, arg0, *(float *)((char *)*(void **)((char *)ret + 4) + 0x20));
    }
    vec[0] = lbl_805623C8;
    vec[1] = lbl_805623C8;
    vec[2] = lbl_805623C8;
    i = 0;
    obj = base + 0x2724;
    do {
        fn_801A56A0(obj, arg0, vec);
        i++;
        obj = (char *)obj + 0x24;
    } while (i < 8);
}
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801A55BC(void *arg0) {
    class Obj {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6();
        virtual void f7();
        virtual void f8(int);
    };
    Obj *obj;
    fn_8018381C();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
    *(int *)((char *)arg0 + 0x2714) = 1;
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = lbl_805623C8;
    *(float *)((char *)arg0 + 0x2718) = lbl_805623C8;
    obj->f8(0);
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f7();
    *(int *)((char *)arg0 + 0x2700) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
}
#pragma pop
extern "C" void fn_801A5660(void *arg0) {
    fn_80183DF8();
    ((Dummy_801A5660 *)*(void **)((char *)arg0 + 0x270C))->d11();
}

extern float lbl_805623CC, lbl_805623D0, lbl_805623D4, lbl_805623D8, lbl_805623DC, lbl_805623E0, lbl_805623E4, lbl_805623E8, lbl_805623F0, lbl_80558DC4;
extern double __fabs(double);
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_8017B3A8(void *, float *, float *);
extern "C" float fn_801A5A7C(void *, float *, float *);
extern "C" void fn_801A56A0(void *arg0, void *arg1, float *arg2) {
    float v[3], point[3], impulse[3], scaled[3], contact[3], direction[3];
    float ratio, dot, movement, other, push, f, scale, limit;
    int active;
    char *a = (char *)arg0;
    char *b = (char *)arg1;
    if (*(void **)(a + 0x20) != 0) {
        v[0] = arg2[0] + *(float *)(b + 0x118);
        v[1] = arg2[1] + *(float *)(b + 0x11c);
        v[2] = arg2[2] + *(float *)(b + 0x120);
        dot = PSVECDotProduct(v, (float *)arg0);
        ratio = *(float *)(a + 0x18) / *(float *)(a + 0x1c);
        ratio = lbl_805623CC < ratio ? lbl_805623CC : ratio;
        ratio = ratio > lbl_805623C8 ? ratio : lbl_805623C8;
        point[0] = *(float *)(b + 0x60) + v[0] * lbl_805623D0;
        point[1] = *(float *)(b + 0x64) + v[1] * lbl_805623D0;
        point[2] = *(float *)(b + 0x68) + v[2] * lbl_805623D0;
        movement = *(float *)(a + 0xc) + ratio * (*(float *)(a + 0x10) - *(float *)(a + 0xc));
        other = fn_801A5A7C(arg0, point, (float *)((char *)*(void **)((char *)*(void **)(a + 0x20) + 0xc) + 0x24));
        active = *(float *)(a + 0x18) < *(float *)(a + 0x1c);
        if (active) {
            push = movement - dot;
            push = lbl_805623C8 > push ? lbl_805623C8 : push;
            f = lbl_805623C8;
            if (dot < lbl_805623C8) {
                ratio = (other - lbl_805623D4) / lbl_805623D8;
                ratio = lbl_805623CC < ratio ? lbl_805623CC : ratio;
                ratio = ratio > lbl_805623C8 ? ratio : lbl_805623C8;
                push = lbl_805623C8;
                f = push + ratio * ((lbl_805623DC + -dot) - push);
            }
            scale = f + push;
            impulse[0] = *(float *)(a + 0) * scale;
            impulse[1] = *(float *)(a + 4) * scale;
            impulse[2] = *(float *)(a + 8) * scale;
            arg2[0] += impulse[0]; arg2[1] += impulse[1]; arg2[2] += impulse[2];
            ratio = *(float *)(b + 0xd4) / lbl_805623D0;
            scaled[0] = impulse[0] * ratio; scaled[1] = impulse[1] * ratio; scaled[2] = impulse[2] * ratio;
            limit = lbl_805623E0;
            if (v[1] > limit && *(int *)(b + 0x2620) == 0) {
                other = lbl_805623E4 * v[1];
                limit = limit < other ? limit : other;
                scaled[1] = -limit * (*(float *)(b + 0xd4) / lbl_805623D0);
            }
            scale = push + f;
            direction[0] = *(float *)(b + 0x54);
            direction[1] = *(float *)(b + 0x58);
            direction[2] = *(float *)(b + 0x5c);
            direction[1] = lbl_805623C8;
            if ((float)__fabs(scale) > lbl_80558DC4 && PSVECDotProduct(direction, (float *)arg0) < lbl_805623C8 && (float)__fabs(*(float *)(b + 0x128)) < lbl_805623E8) {
                ratio = lbl_805623EC / scale;
                ratio = lbl_805623CC < ratio ? lbl_805623CC : ratio;
                ratio *= lbl_805623F0;
                contact[0] = *(float *)(b + 0x60) + direction[0] * ratio;
                contact[1] = *(float *)(b + 0x64) + direction[1] * ratio;
                contact[2] = *(float *)(b + 0x68) + direction[2] * ratio;
            } else {
                contact[0] = *(float *)(b + 0x60);
                contact[1] = *(float *)(b + 0x64);
                contact[2] = *(float *)(b + 0x68);
            }
            fn_8017B3A8(arg1, scaled, contact);
            *(float *)(b + 0x26b4) = lbl_805623C8;
            *(float *)(b + 0x26b8) = lbl_805623C8;
            *(float *)(b + 0x26bc) = lbl_805623C8;
        }
        movement = *(float *)(a + 0x18) + lbl_805623D0;
        *(float *)(a + 0x18) = movement;
        if (movement > lbl_805623F4 + *(float *)(a + 0x1c) && !active)
            *(void **)(a + 0x20) = 0;
    }
}
#pragma pop

/* Signed distance of a world point from a contact plane: dot(normal, point - origin).
   `contact` is a contact record whose first three floats are its world-space normal
   (see fn_801A5AD0, which fills it at +0x00 and stores this result at +0x14). */
extern "C" float fn_801A5A7C(void * __restrict contact, float * __restrict point, float * __restrict origin) {
    float diff[3];
    diff[0] = point[0] - origin[0];
    diff[1] = point[1] - origin[1];
    diff[2] = point[2] - origin[2];
    return PSVECDotProduct((float *)contact, diff);
}

#pragma push
#pragma dont_inline on
extern "C" void fn_801A5AD0(void *arg0, unsigned int arg1, void *arg2, void *arg3) {
    float sp8[3];
    float *p4;
    float f1;
    float f0;
    float f2;
    float f3;
    float dot;
    char *p2 = (char *)arg2;
    if (*(volatile unsigned int *)((char *)arg0 + 0x20) == 0) {
        p4 = *(float **)((char *)arg1 + 0xC);
        f2 = lbl_805623F8;
        *(float *)((char *)arg0 + 0) = p4[0];
        *(float *)((char *)arg0 + 4) = p4[1];
        *(float *)((char *)arg0 + 8) = p4[2];
        sp8[0] = *(float *)(p2 + 0x60) + *(float *)(p2 + 0x118) * f2;
        sp8[1] = *(float *)(p2 + 0x64) + *(float *)(p2 + 0x11C) * f2;
        sp8[2] = *(float *)(p2 + 0x68) + *(float *)(p2 + 0x120) * f2;
        if (arg3) {
            dot = PSVECDotProduct((float *)arg3, (float *)arg0);
            if (dot < lbl_805623C8) {
                f2 = *(float *)((char *)arg0 + 0);
                f3 = lbl_805623FC;
                f1 = *(float *)((char *)arg0 + 4);
                f0 = *(float *)((char *)arg0 + 8);
                f1 *= f3;
                f2 *= f3;
                f0 *= f3;
                *(float *)((char *)arg0 + 4) = f1;
                *(float *)((char *)arg0 + 0) = f2;
                *(float *)((char *)arg0 + 8) = f0;
            }
        }
        *(float *)((char *)arg0 + 0x14) = fn_801A5A7C(arg0, sp8, (float *)((char *)*(void **)((char *)arg1 + 0xC) + 0x24));
        dot = PSVECDotProduct((float *)(p2 + 0x118), (float *)arg0);
        f3 = lbl_805623EC;
        f0 = -(float)(double)dot;
        *(float *)((char *)arg0 + 0xC) = dot;
        f3 = (f3 < f0) ? f3 : f0;
        f3 = (f3 > lbl_80562400) ? f3 : lbl_80562400;
        f2 = lbl_805623F4;
        f0 = lbl_805623C8;
        f1 = f2 * f3;
        *(float *)((char *)arg0 + 0x18) = f0;
        *(float *)((char *)arg0 + 0x1C) = f2;
        *(float *)((char *)arg0 + 0x10) = f1;
        *(unsigned int *)((char *)arg0 + 0x20) = arg1;
    } else if (*(volatile unsigned int *)((char *)arg0 + 0x20) == arg1) {
        *(float *)((char *)arg0 + 0x18) = lbl_805623C8;
    }
}
#pragma pop
extern "C" void fn_801A5C4C(void *arg0, unsigned int key) {
    float values[3];
    int count;
    int i;
    int val;
    void *slot = (char *)arg0 + 0x2724;
    void *candidate = 0;
    void *other = 0;
    void *record = arg0;

    for (count = 4, i = 0; count > 0; count--, i++) {
        val = *(int *)((char *)record + 0x2744);
        if (val != 0 && (unsigned int)val != key)
            other = slot;
        if (candidate == 0 || *(unsigned int *)((char *)candidate + 0x20) != key) {
            if ((unsigned int)val == key || val == 0)
                candidate = slot;
        }

        val = *(int *)((char *)record + 0x2768);
        slot = (char *)slot + 0x24;
        if (val != 0 && (unsigned int)val != key)
            other = slot;
        if (candidate == 0 || *(unsigned int *)((char *)candidate + 0x20) != key) {
            if ((unsigned int)val == key || val == 0)
                candidate = slot;
        }

        record = (char *)record + 0x48;
        slot = (char *)slot + 0x24;
    }

    if (candidate != 0) {
        fn_801A5AD0(candidate, key, arg0, other);
    } else {
        fn_802E30C8(lbl_80333C20, lbl_8055E3C4);
    }

    values[0] = lbl_805623C8;
    values[1] = lbl_805623C8;
    values[2] = lbl_805623C8;
    {
        class Obj {
        public:
            virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
            virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
            virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
            virtual void f12(float *, float *, int, int);
        };
        Obj *obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
        obj->f12(values, values, 0x3EA, 0);
    }
}
#pragma cplusplus on
extern "C" void fn_801A5D80(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    class Obj {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(int, int, int, int);
    };
    float zero;
    Obj *obj;
    fn_8018B09C();
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f12(arg1, arg2, arg3, arg4);
    if (arg3 == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)arg0 + 0x2714) = 1;
        *(int *)((char *)arg0 + 0x2720) = 0;
        *(float *)((char *)arg0 + 0x271C) = zero;
        *(float *)((char *)arg0 + 0x2718) = zero;
    }
}

#pragma cplusplus on
extern "C" void fn_801A5E0C(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    class Obj {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12();
        virtual void f13(int, int, int, int);
    };
    float zero;
    Obj *obj;
    fn_8018956C();
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f13(arg1, arg2, arg3, arg4);
    if (arg3 == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)arg0 + 0x2714) = 1;
        *(int *)((char *)arg0 + 0x2720) = 0;
        *(float *)((char *)arg0 + 0x271C) = zero;
        *(float *)((char *)arg0 + 0x2718) = zero;
    }
}
struct Dummy_801A5E98 {
    virtual void h0() {}
    virtual void h1() {}
    virtual void h2() {}
    virtual void h3() {}
    virtual void h4() {}
    virtual void h5() {}
    virtual void h6() {}
    virtual void h7() {}
    virtual void h8() {}
    virtual void h9() {}
    virtual void h10() {}
    virtual void h11() {}
    virtual void h12() {}
    virtual void h13() {}
    virtual void h14() {}
};
#pragma cplusplus on
extern "C" void fn_801A5E98(void *arg0) {
    fn_8018AF00();
    ((Dummy_801A5E98 *)*(void **)((char *)arg0 + 0x270C))->h14();
}
#pragma cplusplus off

#pragma cplusplus on
struct Dummy_801A5ED8 {
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
  struct Dummy_801A6088 {
      virtual void g0();
      virtual void g1();
      virtual void g2();
      virtual int g3();
      virtual void g4();
  };
  #pragma cplusplus off
  
#pragma cplusplus on
extern "C" void fn_801A5ED8(void *arg0) {
    fn_80189CB4();
    void *obj = *(void **)((char *)arg0 + 0x270C);
    *(unsigned char *)((char *)arg0 + 0x2704) = 1;
    ((Dummy_801A5ED8 *)obj)->f15();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
}
#pragma cplusplus off
  
#pragma cplusplus on
extern "C" int fn_801A5F44(void *arg0, int arg1) {
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(int);
    };
    VTable *obj = (VTable *)*(void **)((char *)arg0 + 0x270C);
    return (int)((char *)obj->f4(arg1 + 0x44) + 0x44);
}
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_801A5F7C(void *arg0, int inX, int inY, int *outX, int *outY, float scale) {
    /* Query a base offset and a child object's offset, returning their sums in outX/outY. */
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5(int, int, int *, int *, float);
    };
    int baseX, baseY, childX, childY;
    Obj *obj;
    fn_8018B0D8(arg0, inX, inY, &baseX, &baseY, scale);
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f5(inX + baseX, inY + baseY, &childX, &childY, scale);
    *outX = baseX + childX;
    *outY = baseY + childY;
}
#pragma use_lmw_stmw on
extern "C" int fn_801A6024(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int v6(int);
    };
    int base = arg1 + fn_8018BA54();
    Obj *obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    base += obj->v6(base);
    return base - arg1;
}
#pragma cplusplus off
  void fn_80188E2C(void);
  int fn_8018BA54(void);
  void fn_8018956C(void);
#pragma cplusplus on
extern "C" void fn_801A6088(void *arg0, int arg1) {
    void *obj;
    int offset;
    fn_80188E2C();
    obj = *(void **)((char *)arg0 + 0x270C);
    offset = arg1 + *(int *)((char *)arg0 + 8);
    *(int *)((char *)offset + 0x2C0) =
        ((Dummy_801A6088 *)obj)->g3();
}
#pragma cplusplus off
extern float lbl_80562404;
extern float lbl_80562408;
extern float lbl_8056240C;
extern void fn_8017B3A8(void *, float *, float *);
#pragma scheduling invalid_target
void fn_801A60E0(void *arg0, void *arg1) {
    float sp14[3];
    float sp8[3];
    float f1;
    float f0;
    float f2;
    char *p = (char *)arg1;

    if (*(float *)(p + 0x124) > lbl_80562404) {
        f0 = lbl_80562408 * (lbl_8056240C - *(float *)(p + 0x58));
        f2 = lbl_805623C8;
        if (f0 < f2) {
            f2 = f0;
        } else {
            f2 = f2;
        }
        sp14[0] = *(float *)(p + 0x60) + *(float *)(p + 0x54) * f2;
        sp14[1] = *(float *)(p + 0x64) + *(float *)(p + 0x58) * f2;
        sp14[2] = *(float *)(p + 0x68) + *(float *)(p + 0x5C) * f2;
    } else {
        sp14[0] = *(float *)(p + 0x60);
        sp14[1] = *(float *)(p + 0x64);
        sp14[2] = *(float *)(p + 0x68);
    }
    f1 = *(float *)((char *)arg0 + 4);
    sp8[0] = lbl_805623C8;
    sp8[1] = f1;
    sp8[2] = lbl_805623C8;
    fn_8017B3A8(arg1, sp8, sp14);
}
#pragma scheduling on
extern void fn_801A60E0(void *, void *);
extern float lbl_8055E3C8, lbl_805623C8, lbl_805623CC, lbl_805623D4, lbl_80562410, lbl_80562414;
#pragma cplusplus off
void fn_801A61B0(void *arg0, void *arg1, float arg2) { (void)arg0; (void)arg1; (void)arg2; }
