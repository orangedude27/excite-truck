__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_80564628;
extern int lbl_804B5030[];
extern void fn_8029E8E0(float *, int);
extern void fn_802C7040(int);
extern void fn_8029D644(void *);
extern float fn_802C88D4(void *);
extern void fn_8029D550(void *, float *, float *);
extern int fn_8029D4CC(void *);
extern int fn_8029EAE8(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8029CD14(void);
extern void fn_8029CB3C(void);
extern void fn_8029C934(void);
extern void fn_8029C650(void);
extern void fn_8029C3EC(void);
extern void *fn_8029D464(void *, int);
extern int lbl_8055F7F8;
extern int lbl_8055F7F0;
extern int lbl_804B5010[];
extern int lbl_8055CAA8;
extern void fn_8028E398(void);
extern void fn_802C6CF8(void);
extern void fn_802CAC54(int);
extern void fn_80128670(int);
extern void fn_80128668(void *);
extern unsigned char lbl_80349780[];
extern float lbl_80564648;
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void *, int);
extern float lbl_8056469C;
extern double lbl_80564680;
extern float fn_801E88F0(int);
extern float fn_802C88E8(void *);
extern int fn_802C9640(void *);

void fn_8029C1C4(void) {
    lbl_8055F7FC = 0;
    fn_8029C570(); fn_8029C73C(); fn_8029C998(); fn_8029CBA0(); fn_8029C664();
    if (fn_802BF4F0() == 0 && lbl_8055F7F0 <= 0 && lbl_8055F7F4 <= 0) return;
    fn_80287B38(fn_8029C450);
}

void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

void fn_8029C25C(void) {
    int *p;
    int i;
    float v = fn_801E7E24();
    if (__fabsf(v) > lbl_80558DC4) {
        p = (int *)&lbl_804B5010;
        i = 0;
        do { fn_8029D574(*p++); ++i; } while (i < lbl_8055F7F0);
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8029C2D4(void) {
    float spC[3];
    float sp8;
    float difference;
    float bestValue;
    int *entries;
    void *best;
    int i;

    if (lbl_8055CAA8 != -1)
        fn_802C7040(lbl_8055CAA8);

    bestValue = lbl_80564628;
    entries = lbl_804B5010;
    best = 0;
    i = 0;
    while (i < *(volatile int *)&lbl_8055F7F0) {
        void *object;
        object = (void *)*entries;
        if (fn_8029D4CC(object)) {
            fn_8029D550(object, spC, &sp8);
            difference = fn_802C88D4(spC) - sp8;
            if (best == 0 || difference < bestValue) {
                best = object;
                bestValue = difference;
            }
        }
        entries++;
        i++;
    }

    if (best != 0)
        fn_8029D644(best);

    {
        int j;
        entries = lbl_804B5030;
        j = 0;
        while (j < *(volatile int *)&lbl_8055F7F4) {
            if (fn_8029EAE8((void *)*entries))
                ((void (*)(void *))fn_8029E8E0)((void *)*entries);
            entries++;
            j++;
        }
    }
}
#pragma pop
void fn_8029C3EC(void) {
}

extern void fn_8029EF24();
void *__dt__Q34nw4r2ef6EffectFv_8029C3F0(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = (void *)lbl_80349780;
        fn_8029EF24(arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma ppc_psq_save on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8029C450(void *arg0, int arg1) {
    extern float fn_801E7E24(void);
    extern void fn_8029D7D0(int, void **);
    extern void fn_8029EA34(void *, void **);
    extern void fn_8029CD48(void *);
    extern int fn_802BF4F0(void);
    extern int lbl_8055F7F0, lbl_8055F7F4;
    extern int lbl_804B5010[], lbl_804B5030[];
    extern float lbl_80558DC4, lbl_80564638, lbl_8056463C;
    float f31, f30;
    void **p;
    int n, i;

    f30 = lbl_80564638;
    if ((float)__fabs((double)fn_801E7E24()) > lbl_80558DC4) {
        f31 = lbl_8056463C;
        n = 0;
        p = (void **)arg0;
        while (n < arg1) {
            if (((float *)p)[2] < f30 &&
                ((float *)p[0])[0x50 / 4] > f31 &&
                ((unsigned char *)p)[0xC] != 0) {
                i = 0;
                while (i < lbl_8055F7F0) {
                    fn_8029D7D0(lbl_804B5010[i], p);
                    i++;
                }
                i = 0;
                while (i < lbl_8055F7F4) {
                    fn_8029EA34((void *)lbl_804B5030[i], p);
                    i++;
                }
                if (fn_802BF4F0() != 0) {
                    fn_8029CD48(p[0]);
                }
            }
            p = (void **)((char *)p + 0x10);
            n++;
        }
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8029C570(void) {
 extern float lbl_80564640, lbl_80564644;
 extern char lbl_80349560[];
 extern int lbl_8055CAAC;
 extern int fn_8012C33C(void *);
 extern int fn_802C6FC0(void *, int, int);
 extern void **fn_802AE414(void *);
 extern void fn_802C8230(float), fn_802C8234(float);
 float a, b;
 char *base, *p, *q;
 void **obj;
 int result;
 a=lbl_80564640; b=lbl_80564644;
 base=lbl_80349560; p=base+0x70; q=base+0x7C;
 if(fn_8012C33C(q)) result=fn_802C6FC0(q,0,0); else result=-1;
 lbl_8055CAA8=result;
 obj=fn_802AE414(p);
 if(obj) {
  a=(*(float (**)(void *, void *))((char *)*obj+0x4C))(obj,&lbl_8055CAAC);
  b=(*(float (**)(void *, void *))((char *)*obj+0x4C))(obj,base+0x18);
 }
 fn_802C8230(a); fn_802C8234(b);
}
#pragma pop

void fn_8029C650(void) {
    int value = lbl_8055CAA8;
    if (value == -1) return;
    ((void (*)(int))fn_802C6CF8)(value);
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
#pragma inline_depth(0)
void fn_8029C664(void) {
    extern void fn_8029D550(void *, float *, float *);
    extern float PSQUATMultiply(float *, float *);
    extern char lbl_803495E8[];
    extern void fn_802E317C(const char *, ...);
    float a[3], b[3], radiusA, radiusB;
    float margin;
    int *base, *p, *q;
    int i, j;
    margin = lbl_80564648;
    p = lbl_804B5010;
    base = p;
    i = base == p ? 0 : 1;
    for (; i<lbl_8055F7F0; ++p, ++i) {
        fn_8029D550((void *)*p, a, &radiusA);
        j=i+1;
        q=base+j;
        for (; j<lbl_8055F7F0; ++q, ++j) {
            fn_8029D550((void *)*q, b, &radiusB);
            if (PSQUATMultiply(a,b)<radiusB+(margin+radiusA))
                fn_802E317C(lbl_803495E8);
        }
    }
}

void fn_8029C73C(void) {
    extern char lbl_80349560[];
    extern int lbl_804B5010[];
    extern int lbl_8055F7F0;
    extern float lbl_80564628, lbl_80564630, lbl_8056464C, lbl_80564650;
    extern int lbl_8055CAB4, lbl_8055CABC, lbl_8055CAC4;
    extern void *fn_80131810(void *);
    extern void fn_80131818(void *);
    extern int fn_801284F8(int, void *, float);
    extern void *fn_8029D148(void *, void *, float *, int);
    extern void fn_802E317C(const char *, ...);
    char init[0x20];
    float vec[3], x, y;
    void *owner, *item;
    int i, id, result;
    void *(*next)(void *, int);
    int (*getid)(void *, void *);
    void (*getvec)(void *, float *, int);
    float (*getval)(void *, int);
    lbl_8055F7F0 = 0;
    owner = fn_80131810(lbl_80349560 + 0xA4);
    if (owner != 0) {
        __builtin_memset(init, 0, 0x20);
        *(float *)(init + 0) = lbl_8056464C;
        *(float *)(init + 4) = lbl_80564628;
        *(float *)(init + 8) = lbl_80564628;
        *(float *)(init + 12) = lbl_80564650;
        *(float *)(init + 16) = lbl_80564630;
        *(float *)(init + 20) = lbl_80564630;
        *(int *)(init + 24) = -1;
        init[28] = 0x20;
        init[29] = (char)0xE4;
        i = 0;
        for (;;) {
            next = *(void *(**)(void *, int))(*(char **)owner + 0xC);
            item = next(owner, i);
            if (item == 0) break;
            if (lbl_8055F7F0 >= 8) fn_802E317C(lbl_80349560 + 0xB0, 8);
            getid = *(int (**)(void *, void *))(*(char **)item + 0x14);
            id = getid(item, lbl_80349560 + 0xD0);
            getvec = *(void (**)(void *, float *, int))(*(char **)item + 0x34);
            getvec(item, vec, lbl_8055CAB4);
            x = vec[0]; y = vec[1];
            getval = *(float (**)(void *, int))(*(char **)item + 0x3C);
            x = getval(item, lbl_8055CABC);
            y = getval(item, lbl_8055CAC4);
            result = fn_801284F8(0x78, lbl_80349560 + 0xE0, y);
            if (result) result = (int)((void *(*)(void *, void *, float *, int))fn_8029D148)((void *)result, init, vec, id);
            lbl_804B5010[lbl_8055F7F0++] = result;
            ++i;
        }
        fn_80131818(owner);
    }
}

#pragma pop

void fn_8029C934(void) {
    int *p = (int *)lbl_804B5010;
    int i = 0;
    while (i < lbl_8055F7F0) {
        fn_8029D464((void *)*p, 1);
        ++p;
        ++i;
    }
    lbl_8055F7F0 = 0;
}

#pragma push
#pragma cplusplus on
void fn_8029C998(void) {
    typedef struct { float x, y, z; } Vec;
    typedef struct { float x, y; } Vec2;
    typedef struct {
        Vec pos;
        Vec2 v1;
        Vec2 v2;
    } Params;
    extern char lbl_80349560[];
    extern int lbl_804B5030[];
    extern int lbl_8055F7F4;
    extern int lbl_8055CAB4, lbl_8055CABC, lbl_8055CAC4;
    extern void *fn_80131810(void *);
    extern void fn_80131818(void *);
    extern int fn_801284F8(int, void *, float);
    extern void *fn_8029E754(void *, void *, int);
    extern void fn_802E317C(const char *, ...);

    Vec2 t1;
    Vec2 t2;
    Vec temp;
    Params params;
    char *base;
    int *dest;
    void *owner;
    int i;

    base = lbl_80349560;
    lbl_8055F7F4 = 0;
    owner = fn_80131810(base + 0xEC);
    if (owner != 0) {
        dest = lbl_804B5030;
        for (i = 0; (*(void *(**)(void *, int))(*(char **)owner + 0xC))(owner, i) != 0; i++) {
            void *item;
            int id;
            void *res;

            if (lbl_8055F7F4 >= 16) {
                fn_802E317C(base + 0xF8, 16);
            }
            item = (*(void *(**)(void *, int))(*(char **)owner + 0xC))(owner, i);
            id = (*(int (**)(void *, void *))(*(char **)item + 0x14))(item, base + 0xD0);
            temp = (*(Vec (**)(void *, void *))(*(char **)item + 0x34))(item, &lbl_8055CAB4);
            params.pos.x = temp.x;
            params.pos.y = temp.y;
            params.pos.z = temp.z;
            t1 = (*(Vec2 (**)(void *, void *))(*(char **)item + 0x3C))(item, &lbl_8055CABC);
            params.v1.x = t1.x;
            params.v1.y = t1.y;
            t2 = (*(Vec2 (**)(void *, void *))(*(char **)item + 0x3C))(item, &lbl_8055CAC4);
            params.v2.x = t2.x;
            params.v2.y = t2.y;
            res = (void *)fn_801284F8(0x44, base + 0x11C, params.v2.x);
            if (res != 0) {
                res = fn_8029E754(res, &params, id);
            }
            dest[lbl_8055F7F4++] = (int)res;
        }
        fn_80131818(owner);
    }
}
#pragma pop
extern void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *, int);
extern int lbl_804B5030[];
void fn_8029CB3C(void) {
    int *p = (int *)lbl_804B5030;
    int i = 0;
    while (i < lbl_8055F7F4) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888((void *)*p, 1);
        ++p;
        ++i;
    }
    lbl_8055F7F4 = 0;
}

extern int fn_8028E2F8(void *, void *, void *, float, float, float, float);
extern void fn_8028E61C(int *);
extern int lbl_8055F7F0, lbl_8055F7F4, lbl_8055F7F8;
extern int lbl_8055CAC8, lbl_8055CAD0, lbl_8055CAD8;
extern float lbl_8056464C, lbl_80564654, lbl_80564658, lbl_8056465C, lbl_80564660;
#pragma push
#pragma small_data off
extern int lbl_8034968C, lbl_80349698;
#pragma pop
void fn_8029CBA0(void) {
    extern void **fn_802AE414(void *);
    float sp9C, sp94, sp8C, sp84, sp7C, sp78, sp74, sp70, sp68;
    int sp64;
    float sp54, sp50, sp48, sp44, sp40, sp3C, sp38, sp34, sp30, sp2C, sp28;
    int sp24, sp20;
    float sp1C, sp18, sp14, sp10, spC, sp8;
    int *var_r31 = &lbl_8034968C;
    float var_f31 = lbl_80564654;
    void **obj = fn_802AE414(&lbl_8055CAC8);
    if (obj != 0) {
        var_r31 = ((int *(*)(void *, void *, void *))(*(void ***)*obj)[0x18 / 4])
            (*obj, &lbl_80349698, var_r31);
        var_f31 = ((float (*)(void *, void *, float))(*(void ***)*obj)[0x28 / 4])
            (obj, &lbl_8055CAD0, var_f31);
    }
    if (fn_802BF4F0() != 0 || lbl_8055F7F0 > 0 || lbl_8055F7F4 > 0) {
        fn_8028E61C(&sp20);
        sp20 = 2;
        sp24 = 0x200;
        sp28 = lbl_80564654;
        sp2C = lbl_80564654;
        sp14 = lbl_80564658;
        sp18 = lbl_80564658;
        sp1C = lbl_80564658;
        sp30 = lbl_80564658;
        sp34 = lbl_80564658;
        sp38 = lbl_80564658;
        sp8 = lbl_80564658;
        spC = lbl_80564658;
        sp10 = lbl_80564658;
        sp3C = lbl_80564658;
        sp40 = lbl_80564658;
        sp44 = lbl_80564658;
        sp48 = lbl_8056465C;
        sp50 = lbl_80564654;
        sp54 = lbl_8056465C;
        sp64 = 5;
        sp68 = var_f31;
        sp74 = lbl_80564654;
        sp70 = lbl_8056464C;
        sp7C = lbl_80564658;
        sp78 = lbl_80564660;
        sp94 = lbl_80564658;
        sp8C = lbl_80564658;
        sp84 = lbl_80564658;
        sp9C = lbl_80564658;
        lbl_8055F7F8 = fn_8028E2F8(&sp20, &lbl_8055CAD8, var_r31,
            lbl_8056464C, lbl_8056465C, lbl_80564658, lbl_80564654);
        return;
    }
    lbl_8055F7F8 = 0;
}

void fn_8029CD14(void) {
    if (lbl_8055F7F8 != 0) {
        ((void (*)(int))fn_8028E398)(lbl_8055F7F8);
        lbl_8055F7F8 = 0;
    }
}

#pragma ppc_psq_save on
#pragma scheduling invalid_target
void fn_8029CD48(void *arg0) {
    extern double fn_8002F234(float);
    extern float fn_80287BC8(float, float);
    extern float fn_802BF590(void);
    extern void fn_8028E590(int, float *, float *, float);
    extern int lbl_8055F7F8;
    extern float lbl_80564628, lbl_80564634, lbl_80564640, lbl_8056464C;
    extern float lbl_80564658, lbl_8056465C, lbl_80564660, lbl_80564664;
    extern float lbl_80564668, lbl_8056466C, lbl_80564670, lbl_80564674;
    struct Vec3 { float x, y, z; } sp34, sp28, sp1C, sp10;
    volatile float sp8, spC;
    float f31 = lbl_8056464C, f30 = lbl_80564668, f29 = lbl_80564664;
    float f28 = lbl_80564634, f27 = lbl_8056465C, f26 = lbl_80564628;
    float range, f24 = lbl_80564670, f23 = lbl_80564640;
    unsigned char *obj = (unsigned char *)arg0;
    unsigned char *mat = (unsigned char *)arg0 + 0x70;
    int outer, inner;
    for (outer = 0; outer < 4; outer++, obj += 0x3c, mat += 0x3c) {
        float f0;
        if ((*(unsigned int *)(obj + 0x9c) & 8) != 0)
            continue;
        if ((unsigned char *)&sp34.x == mat) {
            register float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
            f0 = *(volatile float *)((char *)arg0 + 0x0c);
            f6 = *(volatile float *)(mat + 4);
            f2 = *(volatile float *)((char *)arg0 + 0x10);
            f4 = f6 * f0;
            f11 = *(volatile float *)((char *)arg0 + 0x14);
            f1 = *(volatile float *)arg0;
            f2 = f6 * f2;
            f0 = *(volatile float *)mat;
            f3 = *(volatile float *)((char *)arg0 + 0x04);
            f5 = f0 * f1;
            f10 = *(volatile float *)((char *)arg0 + 0x08);
            f3 = f0 * f3;
            f8 = *(volatile float *)((char *)arg0 + 0x18);
            f1 = f0 * f10;
            f0 = f6 * f11;
            f7 = *(volatile float *)(mat + 8);
            f9 = *(volatile float *)((char *)arg0 + 0x1c);
            f5 = f5 + f4;
            f6 = f7 * f8;
            f12 = *(volatile float *)((char *)arg0 + 0x20);
            f3 = f3 + f2;
            f4 = f7 * f9;
            f0 = f1 + f0;
            f2 = f7 * f12;
            f5 = f6 + f5;
            f1 = f4 + f3;
            f0 = f2 + f0;
            sp34.x = f5;
            sp34.y = f1;
            sp34.z = f0;
        } else {
            sp34.x = *(float *)((char *)arg0 + 0x0c) * *(float *)(mat + 4) +
                *(float *)arg0 * *(float *)mat +
                *(float *)((char *)arg0 + 0x18) * *(float *)(mat + 8);
            sp34.y = *(float *)((char *)arg0 + 0x10) * *(float *)(mat + 4) +
                *(float *)((char *)arg0 + 0x04) * *(float *)mat +
                *(float *)((char *)arg0 + 0x1c) * *(float *)(mat + 8);
            sp34.z = *(float *)((char *)arg0 + 0x14) * *(float *)(mat + 4) +
                *(float *)((char *)arg0 + 0x08) * *(float *)mat +
                *(float *)((char *)arg0 + 0x20) * *(float *)(mat + 8);
        }
        sp34.x += *(float *)((char *)arg0 + 0x24);
        sp34.y += *(float *)((char *)arg0 + 0x28);
        sp34.z += *(float *)((char *)arg0 + 0x2c);
        if (sp34.y > fn_802BF590())
            continue;
        sp34.y += f27;
        if (*(float *)mat > f26)
            f0 = lbl_80564658;
        else
            f0 = lbl_80564660;
        {
            float speed = *(float *)((char *)arg0 + 0x50);
            float scale = f29 + f28 * (speed * f0);
            float limit = f29 + f28 * speed;
            float x = *(float *)((char *)arg0 + 0x34);
            float z = *(float *)((char *)arg0 + 0x3c);
            sp28.x = x + *(float *)arg0 * scale;
            sp28.y = *(float *)((char *)arg0 + 0x38) + *(float *)((char *)arg0 + 0x04) * scale;
            sp28.z = z + *(float *)((char *)arg0 + 0x08) * scale;
            if (f30 < limit)
                limit = f30;
            sp28.x += *(float *)((char *)arg0 + 0x0c) * limit;
            sp28.y += *(float *)((char *)arg0 + 0x10) * limit;
            sp28.z += *(float *)((char *)arg0 + 0x14) * limit;
            {
                float squared = x * x + z * z;
                sp8 = x;
                spC = z;
                {
                    register float distance = fn_8002F234(squared);
                    {
                        float count = f31 * distance;
                        int iterations;
                        if ((int)count < 6)
                            iterations = (int)count;
                        else
                            iterations = 6;
                        range = f24 * distance;
                        for (inner = 0; inner < iterations; inner++) {
                            float step;
                            sp1C = sp34;
                            sp1C.x += fn_80287BC8(lbl_8056466C, lbl_8056465C);
                            sp1C.z += fn_80287BC8(lbl_8056466C, lbl_8056465C);
                            sp1C.y = fn_802BF590();
                            step = f23 < range ? f23 : range;
                            sp10 = sp28;
                            sp10.x += fn_80287BC8(-step, step);
                            sp10.y = f23 * fn_80287BC8(lbl_80564628, step);
                            sp10.z += fn_80287BC8(-step, step);
                            if (*(float *)mat > f26)
                                f0 = lbl_80564658;
                            else
                                f0 = lbl_80564660;
                            fn_8028E590(lbl_8055F7F8, &sp1C.x, &sp10.x,
                                -f0 * fn_80287BC8(lbl_80564628, lbl_80564674));
                        }
                    }
                }
            }
        }
    }
}
#pragma scheduling on
#pragma ppc_psq_save reset
void *fn_8029D148(void *arg0, void *arg1, float *arg2, int arg3) {
    extern double fn_8002F234(float);
    extern void *fn_8012850C(int, const char *);
    extern void *memset(void *, int, unsigned int);
    extern void fn_802E317C(const char *, ...);
    extern float PSQUATMultiply(float *, float *);
    extern void *fn_802CAC28(int, int);
    extern void fn_8014E740(float *, float, float, float, float, float, float, float, float, float, float, float, float);
    extern char lbl_80349560[];
    extern float lbl_80564628, lbl_80564658, lbl_8056465C, lbl_80564678;
    int dimX, dimY, twice, initId, data, end;
    unsigned char flag0, flag1;
    float sqX0, sqX1, sqY0, sqY1, rootX, rootY, ySquared;
    float stepX, stepY;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    float init0, init1;
    float scratch[3];
    char *base = lbl_80349560;

    memset((char *)arg0 + 0x14, 0, 0x20);
    sqX0 = arg2[4];
    sqX1 = arg2[3];
    rootX = (float)fn_8002F234(sqX1 * sqX1 + sqX0 * sqX0);
    sqY0 = arg2[5];
    sqY1 = arg2[6];
    ySquared = sqY0 * sqY0 + sqY1 * sqY1;
    dimX = (int)(lbl_80564678 * rootX);
    *(int *)((char *)arg0 + 0xC) = dimX;
    rootY = (float)fn_8002F234(ySquared);
    dimY = (int)(lbl_80564678 * rootY);
    *(int *)((char *)arg0 + 0x10) = dimY;
    if (*(int *)((char *)arg0 + 0xC) < 3 ||
        *(int *)((char *)arg0 + 0x10) < 3 ||
        *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x10) > 0x200)
        fn_802E317C(base + 0x148, *(int *)((char *)arg0 + 0x10));
    *(void **)arg0 = fn_8012850C(*(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 2) * 2, base + 0x16C);
    memset(*(void **)arg0, 0, *(int *)((char *)arg0 + 0x10) * (*(int *)((char *)arg0 + 0xC) * 4));

    stepX = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0xC) - 1);
    stepY = lbl_80564658 / (float)(*(int *)((char *)arg0 + 0x10) - 1);
    data = *(int *)arg0;
    end = data + *(int *)((char *)arg0 + 0xC) * *(int *)((char *)arg0 + 0x10) * 2;
    initId = *(int *)((char *)arg1 + 0x18);
    f10 = *(float *)((char *)arg1 + 4);
    f11 = *(float *)arg2;
    f8 = *(float *)((char *)arg2 + 8);
    f7 = *(float *)((char *)arg2 + 0xC);
    f2 = *(float *)((char *)arg2 + 0x10);
    f9 = *(float *)((char *)arg2 + 8);
    f5 = *(float *)((char *)arg2 + 0x14);
    f0 = *(float *)((char *)arg2 + 0x18);
    f6 = f7 * stepX;
    f7 = f2 * stepX;
    f4 = f5 * stepY;
    f3 = f0 * stepY;
    f1 = f2 + f0;
    f1 = lbl_8056465C * f1;
    f0 = f11 + (lbl_8056465C * (f7 + f5));
    f8 = f9 + f1;
    init0 = *(float *)arg1;
    init1 = *(float *)((char *)arg1 + 4);
    flag0 = *((unsigned char *)arg1 + 0x1C);
    flag1 = *((unsigned char *)arg1 + 0x1D);
    *(int *)((char *)arg0 + 4) = data;
    *(int *)((char *)arg0 + 8) = end;
    *(int *)((char *)arg0 + 0x2C) = initId & 0xFFFFFF;
    *(float *)((char *)arg0 + 0x14) = init0;
    *(float *)((char *)arg0 + 0x18) = init1;
    *(float *)((char *)arg0 + 0x1C) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)arg0 + 0x20) = *(float *)((char *)arg1 + 0xC);
    *(float *)((char *)arg0 + 0x24) = *(float *)((char *)arg1 + 0x10);
    *(float *)((char *)arg0 + 0x28) = *(float *)((char *)arg1 + 0x14);
    *(unsigned char *)((char *)arg0 + 0x30) = flag0;
    *(unsigned char *)((char *)arg0 + 0x31) = flag1;
    *(float *)((char *)arg0 + 0x34) = lbl_80564628;
    *(float *)((char *)arg0 + 0x38) = f11;
    *(float *)((char *)arg0 + 0x3C) = f10;
    *(float *)((char *)arg0 + 0x40) = f9;
    *(float *)((char *)arg0 + 0x44) = f6;
    *(float *)((char *)arg0 + 0x48) = f7;
    *(float *)((char *)arg0 + 0x4C) = f4;
    *(float *)((char *)arg0 + 0x50) = f3;
    *(float *)((char *)arg0 + 0x54) = f0;
    *(float *)((char *)arg0 + 0x58) = f10;
    *(float *)((char *)arg0 + 0x5C) = f8;
    *(float *)((char *)arg0 + 0x60) = PSQUATMultiply((float *)((char *)arg0 + 0x54), (float *)((char *)arg0 + 0x38));

    twice = *(int *)((char *)arg0 + 0xC) << 1;
    *(void **)((char *)arg0 + 0x70) = fn_8012850C(twice * 0x18, base + 0x178);
    *(void **)((char *)arg0 + 0x74) = fn_802CAC28(arg3, 0);

    f12 = *(float *)((char *)arg2 + 0xC);
    f7 = lbl_8056465C;
    f11 = lbl_80564628;
    f10 = *(float *)((char *)arg2 + 0x10);
    f2 = f12 * f7;
    f1 = *(float *)arg2;
    f9 = *(float *)((char *)arg2 + 0x14);
    f6 = f1 + f2;
    f8 = *(float *)((char *)arg2 + 0x18);
    f3 = f10 * f7;
    f0 = *(float *)((char *)arg2 + 4);
    f5 = f11 * f7;
    f4 = *(float *)((char *)arg2 + 8) + f3;
    f1 = f6 + f9 * f7;
    f0 = f0 + f5;
    scratch[0] = f1;
    scratch[1] = f0 + f5;
    scratch[2] = f4 + f8 * f7;
    fn_8014E740(scratch, *(float *)((char *)arg0 + 0x60), f1, f4, f0, f5, f6, f7, f8, f9, f10, f11, f12);
    return (void *)arg0;
}

void *fn_8029D464(void *arg0,int arg1) {
 if(arg0) { fn_802CAC54(*(int *)((unsigned char *)arg0+0x74)); fn_80128670(*(int *)((unsigned char *)arg0+0x70)); fn_80128670(*(int *)arg0); if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

extern float fn_801E88F0(int);
extern float fn_802C88E8(void *);
extern int fn_802C9640(void *);
extern float lbl_80564648;
extern unsigned char lbl_80349780[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_8029D4CC(void *arg0) {
    register void *object = arg0;
    register float temp_f31;
    register float temp_f2;
    register float temp_f0;
    register float temp_f1;
    register int result;
    temp_f31 = fn_801E88F0(-1);
    temp_f31 = temp_f31 * temp_f31;
    temp_f2 = fn_802C88E8((char *)object + 0x54);
    temp_f2 = temp_f2 * temp_f31;
    temp_f0 = lbl_80564648;
    temp_f1 = *(float *)((char *)object + 0x60);
    result = 0;
    temp_f0 = temp_f0 + temp_f1;
    temp_f0 = temp_f0 * temp_f0;
    if (temp_f2 < temp_f0 &&
        fn_802C9640((void *)((unsigned int)object + 0x54)) != 0) {
        result = 1;
    }
    return result;
}
#pragma pop
void fn_8029D550(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x54);
    arg1[1] = *(float *)((char *)arg0 + 0x58);
    arg1[2] = *(float *)((char *)arg0 + 0x5C);
    *arg2 = *(float *)((char *)arg0 + 0x60);
}

extern int fn_80287B94(int, int);
extern void fn_8029DF64(void *, int, int, float);
extern void fn_8029DDB8(void *);
#pragma push
#pragma processor 750
#pragma scheduling 7400
void fn_8029D574(int arg0) {
    extern float lbl_80564658;
    extern float fn_80287BC8(float, float);
    extern void fn_8029DF64(void *, int, int, float);
    float value;
    int y;
    char *p = (char *)arg0;
    if (*(float *)(p + 0x34) >= lbl_80564658 - lbl_80558DC4) {
        float range = *(float *)(p + 0x28);
        value = fn_80287BC8(-range, range);
        y = fn_80287B94(1, *(int *)(p + 0x10) - 2);
        fn_8029DF64(p, fn_80287B94(1, *(int *)(p + 0xC) - 2), y, value);
        *(float *)(p + 0x34) += *(float *)(p + 0x24) - lbl_80564658;
    } else {
        *(float *)(p + 0x34) += *(float *)(p + 0x24);
    }
    fn_8029DDB8(p);
}

void fn_8029DA24(void *arg0, float *arg1, int x, int z) {
    extern float lbl_80564628, lbl_80564658, lbl_8056465C, lbl_8056468C;
    extern double lbl_80564680;
    extern void PSVECNormalize(float *, float *);
    int width = *(int *)((char *)arg0 + 0xC);
    if (x == 0)
        goto border;
    if (x == width - 1)
        goto border;
    if (z == 0)
        goto border;
    if (z == *(int *)((char *)arg0 + 0x10) - 1)
        goto border;
    {
        short *heights = *(short **)((char *)arg0 + 4);
        int row = x + z * width;
        int v0 = heights[row - width];
        int v1 = heights[row + width];
        int v2 = heights[row + 1];
        int v3 = heights[row - 1];
        float dx = lbl_8056465C * (float)(v0 - v1);
        float dz = lbl_8056465C * (float)(v2 - v3);
        float nx = lbl_8056468C * dx;
        float nz = lbl_8056468C * dz;
        arg1[0] = nx * *(float *)((char *)arg0 + 0x44) + nz * *(float *)((char *)arg0 + 0x4C);
        arg1[1] = (lbl_80564658 - nx * nx) + (lbl_80564658 - nz * nz);
        arg1[2] = nx * *(float *)((char *)arg0 + 0x48) + nz * *(float *)((char *)arg0 + 0x50);
        PSVECNormalize(arg1, arg1);
        return;
    }
border:
    arg1[0] = lbl_80564628;
    arg1[1] = lbl_80564658;
    arg1[2] = lbl_80564628;
}

#pragma pop

extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450(void *, int);
extern float lbl_8056469C;
#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma optimization_level 4
void fn_8029DF64(void *arg0, int arg1, int arg2, float arg3) {
    short *data;
    int low = -32768;
    int index;
    int stride;
    float val;
    int cvt;
    int out;
    stride = *(int *)((char *)arg0 + 0xC);
    data = *(short **)((char *)arg0 + 4);
    index = arg1 + arg2 * stride;
    val = lbl_8056469C * arg3 + (float)data[index];
    cvt = (int)val;
    if (cvt > -32768) low = cvt;
    out = 32767;
    if (low < 32767) out = low;
    data[index] = out;
}
#pragma pop
int fn_8029DFE0(void *arg0, void *arg1) {
    extern float lbl_805646A0, lbl_8056465C, lbl_80564634;
    float delta[2];
    float z = *(float *)((char *)arg1 + 8) - *(float *)((char *)arg0 + 0x40);
    float x = *(float *)arg1 - *(float *)((char *)arg0 + 0x38);
    float u = x * *(float *)((char *)arg0 + 0x44) + z * *(float *)((char *)arg0 + 0x48);
    float v = x * *(float *)((char *)arg0 + 0x4C) + z * *(float *)((char *)arg0 + 0x50);
    float upper = (float)*(int *)((char *)arg0 + 0xC) - lbl_805646A0;
    int result = 0, inside = 0, test = 0;
    delta[0] = x; delta[1] = z;
    if (u >= lbl_8056465C - lbl_80558DC4 && u <= upper + lbl_80558DC4) test = 1;
    if (test) {
        float upper2 = (float)*(int *)((char *)arg0 + 0x10) - lbl_805646A0;
        test = 0;
        if (v >= lbl_8056465C - lbl_80558DC4 && v <= upper2 + lbl_80558DC4) test = 1;
        if (test) inside = 1;
    }
    if (inside && *(float *)((char *)arg1 + 4) < *(float *)((char *)arg0 + 0x3C) - lbl_80564634) result = 1;
    return result;
}

#pragma push
#pragma processor 750
#pragma scheduling 750
void fn_8029E130(void *arg0, float *pos, float *vel, float radius) {
 extern double fn_8002F234(float);
 extern float fn_80287BC8(float,float);
 extern void fn_8028E584(int,float *,float *);
 extern float lbl_80564628,lbl_80564634,lbl_80564640,lbl_8056464C,lbl_80564658,lbl_8056465C,lbl_8056466C,lbl_80564670,lbl_80564698,lbl_805646A4;
 float origin[3], outpos[3], outvel[3], delta[2], direction[2], hit[2], perpendicular[2];
 float factor, cap, lift;
 float height, reach, length, inv, scale, x, z, spread, vertical;
 int ix, iz, count, i;
 char *obj = arg0;
 height = *(float *)(obj+0x3c);
 if (pos[1]-radius > height-lbl_80564634) return;
 direction[0]=vel[0]; direction[1]=vel[2];
 delta[0]=pos[0]-*(float *)(obj+0x38);
 delta[1]=pos[2]-*(float *)(obj+0x40);
 if ((float)__fabs(direction[0]*direction[0]+direction[1]*direction[1]) <= lbl_80558DC4) return;
 x=pos[1]-height;
 reach=fn_8002F234(radius*radius-x*x);
 length=fn_8002F234(direction[0]*direction[0]+direction[1]*direction[1]);
 inv=lbl_80564658/length;
 scale=reach*inv;
 hit[0]=delta[0]+direction[0]*scale;
 hit[1]=delta[1]+direction[1]*scale;
 x=hit[0]**(float *)(obj+0x44)+hit[1]**(float *)(obj+0x48);
 ix=(int)(x<lbl_80564628 ? x-lbl_8056465C : lbl_8056465C+x);
 z=hit[0]**(float *)(obj+0x4c)+hit[1]**(float *)(obj+0x50);
 iz=(int)(z<lbl_80564628 ? z-lbl_8056465C : lbl_8056465C+z);
 if(ix<1 || ix>=*(int *)(obj+0xc)-1 || iz<1) return;
 if(iz>=*(int *)(obj+0x10)-1) return;
 (*(short **)(obj+4))[ix+iz**(int *)(obj+0xc)]=-32768;
 origin[2]=*(float *)(obj+0x40)+hit[1];
 origin[1]=lbl_8056464C+*(float *)(obj+0x3c);
 origin[0]=*(float *)(obj+0x38)+hit[0];
 perpendicular[0]=direction[1]*inv;
 perpendicular[1]=direction[0]*inv;
 spread=lbl_80564640;
 x=lbl_80564670*length;
 if (!(spread<x)) spread=x;
 count=(int)(lbl_8056464C*length)<10 ? (int)(lbl_8056464C*length):10;
 vertical=lbl_80564634*length;
 factor=lbl_80564698; cap=lbl_805646A4; lift=lbl_80564640;
 for(i=0;i<count;i++) {
   z=origin[2]+perpendicular[1]*fn_80287BC8(lbl_8056466C,lbl_8056465C);
   x=perpendicular[0]*fn_80287BC8(lbl_8056466C,lbl_8056465C);
   outpos[1]=origin[1]; outpos[2]=z; outpos[0]=origin[0]+x;
   z=direction[1]+perpendicular[1]*(factor*fn_80287BC8(-spread,spread));
   x=cap<vertical?cap:vertical;
   x=x+lift*fn_80287BC8(lbl_80564628,spread);
   scale=lbl_80564698*fn_80287BC8(-spread,spread);
   outvel[1]=x; outvel[2]=z; outvel[0]=direction[0]+perpendicular[0]*scale;
   fn_8028E584(lbl_8055F7F8,outpos,outvel);
 }
}
#pragma pop
extern float fn_80287BC8(float, float);
extern void fn_8028E590(int, float *, float *, float);
extern int fn_8029DFE0();
extern float lbl_80564628;
extern float lbl_80564634;
extern float lbl_80564658;
extern float lbl_8056465C;
extern float lbl_80564660;
extern float lbl_80564664;
extern float lbl_80564668;
extern float lbl_80564674;
void fn_8029E49C(int unused, void *arg1, int arg2) {
    float sp1C, sp18, sp14, sp10, spC, sp8;
    float temp_f0, temp_f0_2, temp_f1, temp_f2, temp_f3, temp_f6, temp_f7;
    float var_f1, var_f31, var_f5;
    unsigned char *temp_r31, *temp_r5;
    temp_r5 = (unsigned char *)arg1 + arg2 * 0x3C;
    temp_r31 = temp_r5 + 0x70;
    if ((unsigned char *)&sp14 == temp_r31) {
        temp_f6 = *(float *)(temp_r31 + 4); temp_f0 = *(float *)(temp_r31); temp_f7 = *(float *)(temp_r31 + 8);
        sp14 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x18) + (temp_f0 * *(float *)arg1 + temp_f6 * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = temp_f7 * *(float *)((unsigned char *)arg1 + 0x1C) + (temp_f0 * *(float *)((unsigned char *)arg1 + 4) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = temp_f7 * *(float *)((unsigned char *)arg1 + 0x20) + (temp_f0 * *(float *)((unsigned char *)arg1 + 8) + temp_f6 * *(float *)((unsigned char *)arg1 + 0x14));
    } else {
        sp14 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x18) + (*(float *)temp_r31 * *(float *)arg1 + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0xC));
        sp18 = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x1C) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 4) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x10));
        sp1C = *(float *)(temp_r31 + 8) * *(float *)((unsigned char *)arg1 + 0x20) + (*(float *)temp_r31 * *(float *)((unsigned char *)arg1 + 8) + *(float *)(temp_r31 + 4) * *(float *)((unsigned char *)arg1 + 0x14));
    }
    temp_f2 = sp18; temp_f1 = sp1C;
    sp14 += *(float *)((unsigned char *)arg1 + 0x24);
    sp18 = temp_f2 + *(float *)((unsigned char *)arg1 + 0x28);
    sp1C = temp_f1 + *(float *)((unsigned char *)arg1 + 0x2C);
    if (fn_8029DFE0(&sp14, temp_f1, temp_f2)) {
        sp18 += lbl_8056465C;
        if (*(float *)temp_r31 > lbl_80564628) var_f1 = lbl_80564658; else var_f1 = lbl_80564660;
        var_f5 = lbl_80564668;
        temp_f3 = lbl_80564664 + lbl_80564634 * (*(float *)((unsigned char *)arg1 + 0x50) * var_f1);
        sp8 = *(float *)((unsigned char *)arg1 + 0x34) + *(float *)arg1 * temp_f3;
        spC = *(float *)((unsigned char *)arg1 + 0x38) + *(float *)((unsigned char *)arg1 + 4) * temp_f3;
        sp10 = *(float *)((unsigned char *)arg1 + 0x3C) + *(float *)((unsigned char *)arg1 + 8) * temp_f3;
        temp_f0_2 = lbl_80564664 + lbl_80564634 * *(float *)((unsigned char *)arg1 + 0x50);
        if (var_f5 < temp_f0_2) {} else var_f5 = temp_f0_2;
        sp8 += *(float *)((unsigned char *)arg1 + 0xC) * var_f5;
        spC += *(float *)((unsigned char *)arg1 + 0x10) * var_f5;
        sp10 += *(float *)((unsigned char *)arg1 + 0x14) * var_f5;
        if (*(float *)temp_r31 > lbl_80564628) var_f31 = lbl_80564658; else var_f31 = lbl_80564660;
        fn_8028E590(lbl_8055F7F8, &sp14, &sp8, -var_f31 * fn_80287BC8(lbl_80564628, lbl_80564674));
    }
}

void *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_8029E888(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(int *)((char *)arg0 + 0x40));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern void *fn_802C86DC(void);
extern void fn_802C8BD0(int);
extern int fn_802C8DBC(int);
extern void fn_802C8E48(void);
extern void fn_802C8D74(void);
extern void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern float lbl_80564658, lbl_8056465C;
void fn_8029E8E0(float *arg0, int arg1) {
    extern void PSVECNormalize(float *, float *);
    extern double fn_8002F234(float);
    float *view;
    float sp8[3];
    float centerX, centerY, centerZ;
    float scaleX, one, radius, norm;
    int i;

    fn_802C8BD0(*(int *)((char *)arg0 + 0x40));
    if (fn_802C8DBC(4) != 0) {
        view = (float *)fn_802C86DC();
        centerX = *(float *)((char *)view + 0x24);
        centerY = *(float *)((char *)view + 0x28);
        centerZ = *(float *)((char *)view + 0x2C);
        scaleX = lbl_80564658;
        one = lbl_8056465C;
        i = 0;
        do {
            float px = arg0[0];
            float py = arg0[1];
            float pz = arg0[2];
            float dx = px - centerX;
            float dy = py - centerY;
            float dz = pz - centerZ;
            sp8[0] = dx;
            sp8[1] = -dy;
            sp8[2] = dz;
            PSVECNormalize(sp8, sp8);
            radius = scaleX + sp8[1];
            norm = (float)fn_8002F234(radius * radius + sp8[0] * sp8[0] + sp8[2] * sp8[2]);
            norm = one / norm;
            fn_802C8E00(-1, (unsigned int)(i >> 1), arg0[0], arg0[1], arg0[2],
                one + sp8[2] * norm, one + sp8[0] * norm);
            i++;
            arg0 += 3;
        } while (i < 4);
        fn_802C8E48();
    }
    fn_802C8D74();
}

extern void fn_8029EC64(void *, int);
extern float lbl_805646A8;
void fn_8029EA34(void *arg0, void **arg1) {
    void *temp = *arg1;
    register float radius = *(float *)((char *)arg0 + 0x3C);
    register float z1 = *(float *)((char *)temp + 0x2C);
    register float z0 = *(float *)((char *)arg0 + 0x38);
    register float radius_sq = radius * radius;
    register float x1 = *(float *)((char *)temp + 0x24);
    register float x0 = *(float *)((char *)arg0 + 0x30);
    register float dz = z1 - z0;
    register float dx = x1 - x0;
    register float distance_sq = dz * dz + dx * dx;
    int offset, i;

    if (!(distance_sq > radius_sq)) {
        i = 0;
        offset = 0;
        do {
            void *base = *arg1;
            if (!(*(unsigned int *)((char *)base + offset + 0x9C) & 8))
                ((void (*)(void *, void *, int))fn_8029EC64)(arg0, base, i);
            i++;
            offset += 0x3C;
        } while (i < 4);
    }
}

#pragma push
#pragma processor 750
int fn_8029EAE8(void *arg0) {
    register float temp_f31 = lbl_805646A8;
    int result = 0;
    if (fn_802C88E8((char *)arg0 + 0x30) < temp_f31) {
        void *second_obj = (char *)arg0 + 0x18;
        float value = *(float *)((char *)arg0 + 0x3C);
        second_obj = (char *)second_obj + 0x18;
        if (((int (*)(void *, float))fn_802C9640)(second_obj, value) != 0) {
            result = 1;
        }
    }
    return result;
}
#pragma pop
int fn_8029EB54(void *arg0, void *arg1) {
    float *a=(float *)arg0, *b=(float *)arg1;
    float minX, maxX, minY, maxY, point;
    int result=0;
    int inside=0;
    minX=a[9];
    if (a[0]>minX) minX=a[0];
    maxX=a[9];
    if (a[0]<maxX) maxX=a[0];
    point=b[0];
    if (point>=minX-lbl_80558DC4 && point<=maxX+lbl_80558DC4) inside=1;
    if (inside) {
        minY=a[11];
        if (a[2]>minY) minY=a[2];
        maxY=a[11];
        if (a[2]<maxY) maxY=a[2];
        point=b[2];
        if (point>=minY-lbl_80558DC4 && point<=maxY+lbl_80558DC4) inside=1;
    }
    if (inside && b[1]<a[1]-lbl_80564634) result=1;
    return result;
}

int fn_8029EF1C(void) {
    return 0;
}

void fn_8029EF24(void) {
}

void fn_8029EF28(void) {
}

void fn_8029EF2C(void) {
}

int fn_8029EF30(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8029EF38(void *arg0) {
    return *(int *)((char *)arg0 + 0x64);
}

#pragma dont_inline on
void fn_8029EF40(void) {
    fn_8029EF28();
}
void fn_8029EF44(void) {
    fn_8029EF2C();
}
#pragma dont_inline reset
void fn_8029EF48(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 1;
}

void fn_8029EF54(void *arg0) {
    *((unsigned char *)arg0 + 0x68) = 0;
}

int fn_8029EF60(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x68);
}
extern float fn_801E7E24(void);
extern void fn_8029D574(int);
extern float lbl_80558DC4;
extern void fn_8029C570(void);
extern void fn_8029C73C(void);
extern void fn_8029C998(void);
extern void fn_8029CBA0(void);
extern void fn_8029C664(void);
extern int fn_802BF4F0(void);
extern int lbl_8055F7F4;
extern int lbl_8055F7FC;
extern void fn_80287B38(void *);
extern void fn_8029C450();
extern float lbl_8056469C;
