// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804348E8[4];
extern double fn_8002EFB4(void);
extern void fn_801476D8(int, int);
extern void fn_80128668(void*);
extern void* lbl_8055EA04;
extern float lbl_8055AE30;
extern float lbl_80562C1C;
extern float lbl_80562C3C;
extern float lbl_80562C40;
extern float lbl_80562C44;
extern float lbl_80562C48;
extern int lbl_8055E4D0;
extern float PSVECMag(void*);
extern char lbl_8055AE2C;
void* fn_801DF678(void* arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int*)arg0 = 0;
            *((int*)arg0 + 1) = 0;
            *((int*)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_801DF6D0(void* arg0) {
    int zero = 0;
    void* ptr = &lbl_8055AE2C;
    *(int*)((char*)arg0 + 0x18) = zero;
    *(void**)((char*)arg0 + 4) = ptr;
    *(void**)((char*)arg0 + 8) = ptr;
    *(char*)arg0 = zero;
    *(int*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 0x10) = zero;
    *(int*)((char*)arg0 + 0x14) = -1;
}
#pragma scheduling on
extern void *fn_801284F8(int, void *);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_80145E70(void *);
extern void fn_801D0DDC(void *);
extern int fn_80207848(void *, int);
extern int fn_802CAC28(void *, int);
extern int stricmp(const char *, const char *);
extern char lbl_803381C0[], lbl_803395D8[], lbl_80339744[];
extern char lbl_8055AE44[], lbl_8055AE4C[];
extern void *lbl_8055EA04;
void fn_801DF6FC(void) {
    void *obj, *iter, *list, *entry;
    int i, j, n;
    char *p, *q;
    float f, keep;
    char *base = lbl_803395D8;
    obj = fn_801284F8(0x1B4, base);
    if (obj) {
        *(void **)obj = lbl_803381C0;
        fn_801D0DDC(obj);
        *(void **)obj = lbl_80339744;
        lbl_8055EA04 = obj;
        *(int *)((char *)obj + 0xE4) = fn_80145E70(base + 0xC);
        *(int *)((char *)obj + 0xF0) = fn_802CAC28(base + 0x1C, 0);
        *(int *)((char *)obj + 0xE8) = fn_802CAC28(base + 0x28, 0);
        *(int *)((char *)obj + 0xEC) = fn_802CAC28(base + 0x34, 0);
        *(int *)((char *)obj + 0xF4) = fn_802CAC28(base + 0x40, 0);
        *(int *)((char *)obj + 0xF8) = fn_80207848(base + 0x50, 1);
        for (i = 0; i < 3; i++) {
            ((int *)((char *)obj + 0xFC))[i] = fn_80207848(base + 0x60, 1);
        }
        *(int *)((char *)obj + 0x108) = 0;
        *(int *)((char *)obj + 0x10C) = fn_80207848(base + 0x70, 1);
        *(int *)((char *)obj + 0x1B0) = 0;
        iter = fn_80131808(base + 0x80);
        if (iter) {
            list = ((void *(*)(void *, void *))(*(void ***)iter)[2])(iter, base + 0x8C);
            for (j = 0; (entry = ((void *(*)(void *, int))(*(void ***)list)[0x18])(list, j)) != 0; j++) {
                p = ((char *(*)(void *))(*(void ***)entry)[2])(entry);
                if (stricmp(p, lbl_8055AE44) == 0) {
                    keep = ((float (*)(void *, const char *))(*(void ***)entry)[9])(entry, lbl_8055AE44);
                    p = ((char *(*)(void *, const char *))(*(void ***)entry)[5])(entry, lbl_8055AE4C);
                    f = ((float (*)(void *, const char *))(*(void ***)entry)[9])(entry, base + 0x9C);
                    n = *(int *)((char *)obj + 0x1B0);
                    *(int *)((char *)obj + 0x1B0) = n + 1;
                    q = (char *)obj + n * 0x28 + 0x114;
                    *(float *)(q - 4) = f;
                    i = 0x20;
                    while (1) {
                        *q++ = *p++;
                        if (q[-1] == 0) break;
                        if (--i <= 0) {
                            q[-1] = 0;
                            break;
                        }
                    }
                    *(float *)(q + 0x1C) = keep;
                }
            }
            fn_80131818(iter);
        }
    }
}

int fn_801DF93C(int arg0) { (void)arg0; return 1; }

void fn_801476D8(int, int);
void fn_801DFE44(int a1, int a2) { ((void (*)(int, int, int))fn_801476D8)(a1, -1, a2); }

#pragma cplusplus on
struct Dummy_801DFE50 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
};
extern "C" void fn_801DFE50(void *arg0, int arg1, int arg2) {
    struct Dummy_801DFE50_Local {
        virtual void d0();
        virtual void d1();
        virtual void* d2();
    };
    void *result = ((Dummy_801DFE50_Local *)arg0)->d2();
    ((void (*)(void *, int, int))fn_801476D8)(result, -1, arg2);
}
#pragma cplusplus reset

float fn_801DFE94(void) {
    return (float)fn_8002EFB4();
}

typedef void (*Fn)(void *);
#pragma cplusplus on
extern "C" void fn_801DFEB8(void *arg0, int arg1, int arg2, int arg3) {
    struct Dummy_801DFEB8_Local {
        virtual void d0();
        virtual void d1();
        virtual void* d2();
    };
    void *result = ((Dummy_801DFEB8_Local *)arg0)->d2();
    ((void (*)(void *, int, int))fn_801476D8)(result, arg2, arg3);
}
#pragma cplusplus reset
int fn_801DFF08(int index) { return lbl_804348E8[index]; }

void fn_801DFF1C(int arg0) {
    int index = arg0;
    char* entry = (char*)lbl_8055EA04 + index * 0x1C;
    void* vec = ((void**)lbl_804348E8)[index];
    *(float*)(entry + 4) = lbl_80562C3C;
    *(float*)(entry + 0x10) = lbl_80562C1C;
    *(float*)(entry + 8) = lbl_80562C40;
    *(char*)(entry + 0xC) = 0;
    *(float*)(entry + 0x14) = lbl_80562C44 * (lbl_8055AE30 * PSVECMag((char*)vec + 0x118)) / lbl_80562C48;
    *(char*)(entry + 0x18) = 0;
    *(int*)(entry + 0x1C) = -1;
}

extern float lbl_8055AE40, lbl_80562C18, lbl_80562C4C, lbl_80562C1C, lbl_80558DC4;
extern float lbl_80562C30, lbl_80562C20, lbl_80562C28;
extern double lbl_80562C50;
extern int lbl_8055CFF0;
extern char lbl_80339738[];
extern int fn_801E866C(int);
extern int fn_80179650(void);
extern int fn_801B8570(int);
extern int fn_801769F8(void);
extern int fn_80161BB8(void);
extern float fn_801E7E18(void);
extern float fn_802C9A50(void);
extern void fn_80148100(void *);
void fn_801DFFB4(void) {
    register int index;
    register float f31;
    register float f30;
    float x;
    float ratio;
    void *manager;
    void *object;

    manager = lbl_8055EA04;
    index = fn_801E866C(0);
    if (fn_80179650() != 1 || !fn_801B8570(index) || fn_801769F8() || fn_80161BB8())
        return;

    f31 = lbl_8055AE40 / lbl_80562C18;
    x = fn_801E7E18() - *(float *)((char *)manager + index * 0x1C + 8);
    x = f31 - x;
    x = lbl_80562C4C + x;
    f30 = lbl_80562C1C;
    if (f30 > x)
        f30 = x;

    if (__fabs(f30) <= lbl_80558DC4)
        return;

    object = *(void **)((char *)manager + 0xE4);
    object = (*(void * (**)(void *, const char *))(*(void ***)object + 5))(object, lbl_80339738);
    ratio = (f30 - f31 * lbl_80562C30) / (lbl_80562C4C - f31 * lbl_80562C30);
    if (ratio < lbl_80562C20)
        ratio = lbl_80562C20;
    if (ratio > lbl_80562C1C)
        ratio = lbl_80562C1C;
    *(int *)((char *)object + 0x18) = ((int)(ratio * lbl_80562C28 + lbl_80562C1C) << 24) | 0xFFFFFF;
    x = fn_802C9A50();
    *(float *)((char *)object + 0x10) = (float)lbl_8055CFF0 / x;
    fn_80148100(object);
}

#pragma cplusplus on
extern "C" void fn_801D0DFC(void *);
extern "C" void fn_802CAC54(int);
extern "C" void *fn_801E0150(void *arg0, int arg1) {
    struct LocalObj {
        virtual void d0(int);
    };
    LocalObj *object;
    char *p;
    int i;
    void *result = arg0;

    if (arg0 != 0) {
        object = *(LocalObj **)((char *)arg0 + 0x10C);
        *(void **)arg0 = lbl_80339744;
        if (object != 0) {
            if (object != 0)
                object->d0(1);
        }

        p = (char *)arg0;
        i = 0;
        do {
            object = *(LocalObj **)(p + 0xFC);
            if (object != 0) {
                if (object != 0)
                    object->d0(1);
            }
            ++i;
            p += 4;
        } while (i < 3);

        object = *(LocalObj **)((char *)arg0 + 0xF8);
        if (object != 0) {
            if (object != 0)
                object->d0(1);
        }

        fn_802CAC54(*(int *)((char *)arg0 + 0xF4));
        fn_802CAC54(*(int *)((char *)arg0 + 0xEC));
        fn_802CAC54(*(int *)((char *)arg0 + 0xE8));
        fn_802CAC54(*(int *)((char *)arg0 + 0xF0));
        lbl_8055EA04 = 0;

        object = *(LocalObj **)((char *)arg0 + 0xE4);
        if (object != 0)
            object->d0(1);

        if (arg0 != 0) {
            *(void **)arg0 = lbl_803381C0;
            fn_801D0DFC(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return result;
}
#pragma cplusplus reset

void fn_801E02A8(void) {

}

void fn_801E02AC(void) {

}

void fn_801E02B0(void* arg0) {
    float b;
    float a;
    char* entry;
    int i;
    a = lbl_80562C40;
    b = lbl_80562C1C;
    entry = (char*)arg0 + 4;
    i = 0;
    while (i < lbl_8055E4D0) {
        *(char*)(entry + 8) = 0;
        i++;
        *(float*)(entry + 4) = a;
        *(float*)(entry + 0xC) = b;
        *(float*)(entry + 0x10) = b;
        *(char*)(entry + 0x14) = 0;
        *(int*)(entry + 0x18) = -1;
        *(float*)entry = b;
        entry += 0x1C;
    }
}

/* One slip/skid instance of the manager built by fn_801DF6FC: its entry
 * array starts at +4 and holds lbl_8055E4D0 records, one per vehicle in
 * lbl_804348E8.  fn_801DFF1C and fn_801E02B0 set the fields up. */
struct SlipEntry {
    float charge;           /* 0x00: 0.15..1.0, how strong the effect is */
    float timer;            /* 0x04: when it was raised; < 0 while waiting */
    unsigned char active;   /* 0x08: it has been raised */
    char pad09[3];          /* 0x09 */
    float elapsed;          /* 0x0C: seconds it has been running */
    float slip;             /* 0x10: slip built up since it started */
    unsigned char started;  /* 0x14: its sound has been started */
    char pad15[3];          /* 0x15 */
    int zone;               /* 0x18: sound zone that slip reached, -1 none */
};

extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_8014E61C(int, int, float);
extern int fn_80009C84(void);
extern float PSVECDotProduct(void *, void *);
extern void *fn_801B83A0(void);
extern double __fabs(double);
extern float lbl_8055AE34, lbl_8055AE38, lbl_8055AE3C, lbl_8055E3C8;
extern float lbl_80562C58, lbl_80562C5C, lbl_80562C60, lbl_80562C64, lbl_80562C68, lbl_80562C6C, lbl_80562C70, lbl_80562C74;
__declspec(section ".data") extern float lbl_80558DC4;

extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_8014E61C(int, int, float);
extern int fn_80009C84(void);
extern float PSVECDotProduct(void *, void *);
extern void *fn_801B83A0(void);
extern float lbl_8055AE34, lbl_8055AE38, lbl_8055AE3C, lbl_8055E3C8;
extern float lbl_80562C58, lbl_80562C5C, lbl_80562C60, lbl_80562C64, lbl_80562C68, lbl_80562C6C, lbl_80562C70, lbl_80562C74;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801E0300(void *arg0) {
    struct FxIface {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
        virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
        virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
        virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void notify(int, int);
    };
    char *obj;
    char *p;
    int *tbl;
    char *e;
    int i, j, redraw, same;
    float f31, f30, f29, f28, f27, f26, f25, f24, f23, f22, f21, f20, f19, f18, f17, f16;
    if ((((int *)__AXFXGetLfoSinTable_801769CC())[1] & 0x4000) != 0) return;
    tbl = lbl_804348E8;
    f25 = lbl_80562C1C; f26 = lbl_80562C4C; f27 = lbl_80562C68;
    e = (char *)arg0 + 4;
    f29 = lbl_80562C6C; f30 = lbl_80562C3C;
    i = 0;
    f21 = lbl_80562C58; f22 = lbl_80562C60; f24 = lbl_80562C5C; f23 = lbl_80562C64;
    f31 = lbl_80562C70; f17 = lbl_80562C74; f16 = lbl_80562C18; f28 = lbl_80562C20;
    for (; i < lbl_8055E4D0; tbl++, e += 0x1C, i++) {
        obj = (char *)*tbl;
        if ((float)__fabs((double)*(float *)(obj + 0x2690)) <= lbl_80558DC4) continue;
        *(float *)(e + 0xC) += f21;
        if (*(unsigned char *)(e + 0x14) == 0) {
            float mag = PSVECMag(obj + 0x124);
            float mag2 = PSVECMag(obj + 0x118);
            *(float *)(e + 0x10) += f21 * (lbl_8055AE34 * mag2 + lbl_8055AE38 * mag);
            same = ((int *)__AXFXGetLfoSinTable_801769CC())[1] == 0x180201;
            if (!same && *(float *)(e + 0xC) > lbl_8055AE3C) {
                *(int *)(e + 0x18) = -1;
                p = (char *)arg0;
                for (j = 0; j < *(int *)((char *)arg0 + 0x1B0); p += 0x28, j++) {
                    if (*(float *)(e + 0x10) > *(float *)(p + 0x110)) *(int *)(e + 0x18) = j;
                }
                if (*(int *)(e + 0x18) >= 0)
                    fn_8014E61C(i, 4, *(float *)((char *)arg0 + *(int *)(e + 0x18) * 0x28 + 0x134));
                *(unsigned char *)(e + 0x14) = 1;
            }
        }
        {
            float spd = *(float *)(obj + 0x25D4);
            f20 = lbl_8055E3C8;
            f19 = f20 - *(float *)(obj + 0x26A0);
            f18 = lbl_80562C5C;
            if (spd > f22 || PSVECDotProduct(obj + 0x124, obj + 0x124) > f23)
                f18 *= f24;
        }
        redraw = 0;
        if (*(float *)(e + 4) < f25 && *(unsigned char *)(e + 8) == 0) {
            if (*(unsigned char *)(obj + 0x260E) != 0 && f19 < f18 && fn_80179650() == 1) {
                *(float *)e += f26;
                if (*(int *)((char *)arg0 + *(int *)((char *)arg0 + 0x108) * 4 + 0xFC) != 0 && *(int *)(obj + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *q = (char *)*(int *)((char *)arg0 + *(int *)((char *)arg0 + 0x108) * 4 + 0xFC);
                    q[0x49] = 1; q[0x4B] = 0; q[0x4A] = 0;
                    *(int *)((char *)arg0 + 0x108) = (*(int *)((char *)arg0 + 0x108) + 1) % 3;
                }
            }
            if (*(float *)e >= f27) {
                *(float *)e = f28;
                *(unsigned char *)(e + 8) = 1;
                *(float *)(e + 4) = f20;
                if (*(int *)((char *)arg0 + 0xF8) != 0 && *(int *)(obj + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *q = (char *)*(int *)((char *)arg0 + 0xF8);
                    q[0x49] = 1; q[0x4B] = 0; q[0x4A] = 0;
                }
            } else if (f19 >= f18) {
                *(float *)(e + 4) = f20;
                if (*(int *)((char *)arg0 + 0x10C) != 0 && *(int *)(obj + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *q = (char *)*(int *)((char *)arg0 + 0x10C);
                    q[0x49] = 1; q[0x4B] = 0; q[0x4A] = 0;
                }
            } else {
                float v = *(float *)e - f29;
                *(float *)e = v > f30 ? v : f30;
            }
        } else {
            if (*(unsigned char *)(e + 8) == 0) {
                float v = *(float *)e - f31;
                *(float *)e = v > f25 ? v : f25;
            }
            if (f20 - *(float *)(e + 4) > lbl_8055AE40 / f16) {
                redraw = 1;
                if (*(unsigned char *)(e + 8) != 0) {
                    *(float *)(obj + 0x258C) = f17;
                    *(unsigned char *)(obj + 0x259D) = 0;
                }
            }
        }
        if (redraw != 0) {
            FxIface *o = (FxIface *)fn_801B83A0();
            o->notify(i, *(int *)(obj + 0x26A4));
        }
    }
}
#pragma cplusplus reset
#pragma pop
