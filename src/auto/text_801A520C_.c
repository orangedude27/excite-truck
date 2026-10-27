void fn_8018956C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct D_801A520C {
    void **vtable;
    void *pad0; void *pad1; void *pad2; void *pad3; void *pad4; void *pad5; void *pad7; void *pad8; void *pad9;
    int (*d5)(struct D_801A520C *);
} D_801A520C;

void fn_8018B0D8(int *, int *);
int fn_8018BA54();
void fn_80189CB4(void);
void fn_8018AF00(void);
void fn_80183DF8(void);
void fn_8018381C(void);
extern float lbl_805623C8;
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
    *(void **)arg0 = (void *)((unsigned long)&lbl_80333C48);
    return arg0;
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
extern "C" void fn_801A5258(void *arg0, void *arg1) {
    class VTable {
    public:
        virtual void f0();
        virtual void f2(void *, void *);
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f9();
    };
    VTable *obj;
    float zero;
    fn_80182074();
    fn_80265D38(arg0, *(int *)((char *)arg0 + 0x1EC));
    obj = (VTable *)*(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2708) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
    *(int *)((char *)arg0 + 0x2700) = 0;
    obj->f2(arg0, arg1);
    obj = (VTable *)*(void **)((char *)arg0 + 0x270C);
    obj->f9();
    zero = lbl_805623C8;
    *(int *)((char *)arg0 + 0x2714) = 1;
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = zero;
    *(float *)((char *)arg0 + 0x2718) = zero;
    *(unsigned char *)((char *)arg0 + 0x2710) = 0;
}
#pragma cplusplus off
void fn_801A5300(void *arg0, void **arg1) {
    void **temp_r0;
    void **temp_r3;
    temp_r0 = *(void ***)((char *)arg0 + 0x270C);
    if (temp_r0 != 0) {
        ((int (**)(void **))(*temp_r0))[10](temp_r0);
    }
    *(void ***)((char *)arg0 + 0x270C) = arg1;
    if (arg1 != 0) {
        ((int (**)(void **, void *))(*arg1))[4](arg1, arg0);
        temp_r3 = *(void ***)((char *)arg0 + 0x270C);
        ((int (**)(void **))(*temp_r3))[9](temp_r3);
    }
}

void *fn_801A538C(void *arg0, int arg1) {
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333C48;
        fn_80265D3C(&lbl_80333C48);
        obj = *(void **)((char *)arg0 + 0x270C);
        ((void (*)(void *))(*(void ***)obj)[10])(obj);
        obj = *(void **)((char *)arg0 + 0x270C);
        if (obj != 0)
            ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
        *(void **)((char *)arg0 + 0x270C) = 0;
        fn_801836E0(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_801A5434(void *arg0) {
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
    int values[3];
    int first;
    int second;
    void *obj;
    count = *(int *)((char *)arg0 + 0x2700);
    if (count == 0 &&
        ((lbl_8055E3C4 + *(int *)((char *)arg0 + 0x1EC)) & 0x1F) != 0)
        return;
    first = *(int *)((char *)arg0 + 0x60);
    second = *(int *)((char *)arg0 + 0x64);
    values[0] = first;
    values[1] = second;
    values[2] = *(int *)((char *)arg0 + 0x68);
    if (((int (*)(void *, int *, int))fn_801E9E30)((char *)arg0 + 0x6C, values, first) == 0) {
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
extern void fn_80186DE4(void);
extern void fn_801A5434(void *);
extern void fn_801A56A0(void *, void *, float *);
extern void fn_801A61B0(void *, void *, float);
extern unsigned char lbl_8055A518;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801A54EC(void *arg0) {
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
#pragma cplusplus on
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
extern "C" void fn_801A5660(void *arg0) {
    fn_80183DF8();
    ((Dummy_801A5660 *)*(void **)((char *)arg0 + 0x270C))->d11();
}

float fn_801A5A7C(void *arg0, float *arg1, float *arg2) {
    float diff[3];
    diff[0] = arg1[0] - arg2[0];
    diff[1] = arg1[1] - arg2[1];
    diff[2] = arg1[2] - arg2[2];
    return PSVECDotProduct(diff, arg2);
}

#pragma cplusplus on
extern "C" void fn_801A5C4C(void *arg0, unsigned int key) {
    float values[3];
    int i;
    int val;
    void *slot = (char *)arg0 + 0x2724;
    void *candidate = 0;
    void *other = 0;
    void *record = arg0;

    for (i = 0; i < 4; i++) {
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
            virtual void f12(); virtual void f13();
            virtual void f14(float *, float *, int, int);
        };
        Obj *obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
        obj->f14(values, values, 0x3EA, 0);
    }
}
#pragma cplusplus off
void fn_801A5D80(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    void *obj;
    float zero;
    fn_8018B09C();
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *, int, int, int, int))(*(void ***)obj)[14])(obj, arg1, arg2, arg3, arg4);
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
#pragma scheduling invalid_target
void fn_801A5F7C(void *arg0, int arg1, int arg2, int *arg3, int *arg4, float farg0) {
    int x, y, a, b;
    void *obj;
    fn_8018B0D8(&x, &y);
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *, int, int, int *, int *, float))(*(void ***)obj)[7])(obj, arg1 + x, arg2 + y, &a, &b, farg0);
    *arg3 = x + a;
    *arg4 = y + b;
}
#pragma scheduling on
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
extern void fn_8017B3A8(void *, float *, float *, float);
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
        if (f2 > f0) {
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
    fn_8017B3A8(arg1, sp8, sp14, f1);
}
#pragma scheduling on
extern void fn_801A60E0(void *, void *);
extern float lbl_8055E3C8, lbl_805623C8, lbl_805623CC, lbl_805623D4, lbl_80562410, lbl_80562414;
void fn_801A61B0(void *arg0, void *arg1, float arg2) {
    int active;
    int counter;
    float value, ratio, limit, bound;
    if (*(int*)arg0) {
        active=1;
        if (!*(unsigned char*)((char*)arg1+0x23CC) && !*(unsigned char*)((char*)arg1+0x2440) &&
            *(unsigned char*)((char*)arg1+0x24B4) && *(unsigned char*)((char*)arg1+0x2528)) {
            value=*(float*)((char*)arg1+0x25D4); ratio=value/arg2;
            if(ratio>lbl_80562410) {
                limit=*(float*)((char*)arg1+0x11C);
                if(limit>lbl_805623C8 && limit<lbl_805623D4*value) {
                    counter=*(int*)((char*)arg0+0xC)+1; *(int*)((char*)arg0+0xC)=counter;
                    if(counter>4) {
                        bound=lbl_805623CC;
                        value=bound-ratio;
                        *(float*)((char*)arg0+8)=lbl_8055E3C8;
                        if(bound<value) bound=value;
                        if(bound>lbl_805623C8) bound=lbl_805623C8;
                        *(int*)arg0=0;
                        *(float*)((char*)arg0+4)=lbl_80562414*(bound**(float*)((char*)arg1+0xD4));
                        do {
                            fn_801A60E0(arg0,arg1);
                            counter=*(int*)((char*)arg0+0xC)-1;
                            *(int*)((char*)arg0+0xC)=counter;
                        } while(counter!=0);
                    } else active=0;
                }
            }
        }
        if(active) *(int*)((char*)arg0+0xC)=0;
    } else {
        fn_801A60E0(arg0,arg1);
        if(*(int*)((char*)arg1+0x2620)>0 && lbl_8055E3C8-*(float*)((char*)arg0+8)>lbl_805623CC) {
            *(int*)arg0=1; *(int*)((char*)arg0+0xC)=0;
            *(float*)((char*)arg0+8)=lbl_805623C8; *(float*)((char*)arg0+4)=lbl_805623C8;
        }
    }
}

