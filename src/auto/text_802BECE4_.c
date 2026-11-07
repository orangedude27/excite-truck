// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8034AE40[];
extern int lbl_8055FAFC;
extern void *lbl_8055FB00;
extern float lbl_80564DA8;
extern void *fn_801284F8(int, const char *);
extern int fn_802CB128(int, int, int, int);
extern char lbl_8055CF84[4];
extern int fn_801E85A4(void);
extern double atan(double), fn_8002EF30(float);
extern void fn_802BDD8C(float);
extern void fn_802BFE48(void *, void *, float), fn_802C0054(void *, const void *), fn_802C00A0(void);
extern void fn_80144DAC(void *, void *), fn_80144DC8(void *);
extern void fn_802C10C8(void), fn_802C7040(int), fn_802C8638(void *), fn_802C86F0(void *, int, int, int, int), fn_802C8750(void *, int), fn_802C88BC(int), fn_802C8B08(void *), fn_802C8B98(int, float *), fn_802C8D74(void), fn_802C8DB8(void *, int, unsigned short *, int), fn_802C9294(int, int), fn_802C9694(void *, float, float, float), fn_802C96DC(void *, int), fn_802CB274(int);
extern float lbl_80564DAC, lbl_80564DB0, lbl_80564DB4, lbl_80564DB8, lbl_80564DBC, lbl_80564DC0, lbl_80564DC4, lbl_80564DC8;
extern void fn_80128668(void *);
extern int fn_802BF6AC(void);
extern int fn_802CAC28(void *, int);
extern char lbl_8034AE08[];
extern float lbl_8055FB04, lbl_80564DF0;
extern void fn_802BEDFC(void);
extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C();
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
extern void fn_802CAC54(int);
extern char lbl_8034AE20[];
typedef unsigned int u32;
extern int sscanf(const char *, const char *, ...);
extern float lbl_8055FAF4;
extern float lbl_8055FAE0;
extern int lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0;
extern float lbl_80564D84;
extern char lbl_8034ACA0[];
#pragma small_data on
extern char lbl_8055CF80;
#pragma small_data off
extern void *fn_80131808(void *, int, int);
extern int fn_80131818(void *);
#pragma dont_inline fn_802BECE4
extern int fn_802BECE4(const char *, int);
extern float lbl_80564D7C;
extern float lbl_80564D80;
extern float PSVECMag(void *);
extern char lbl_8034ACC0[];
extern char lbl_8055CF78[];
extern unsigned char lbl_8055CF71;
extern int fn_801E85B4(void);
extern void fn_802BF160(void);
extern int fn_802C2C00(int);
extern void fn_802C6CF8();
extern void *lbl_804C07F0[];
extern unsigned char lbl_8055CF70;
extern int lbl_8055FADC;
extern int lbl_8055CF6C;
#pragma dont_inline on
int fn_802BECE4(const char *arg0, int arg1) {
    int d, c, b, a;
    int result = arg1;
    a = b = c = d = 0;
    if (sscanf(arg0, lbl_8034ACC0, &d, &c, &b, &a) == 4) {
        result = ((d & 0xff) << 24) | ((c & 0xff) << 16) |
                 ((b & 0xff) << 8) | (a & 0xff);
    } else {
        sscanf(arg0, lbl_8055CF78, &result);
    }
    return result;
}
void fn_802BED90(float *arg0) {
    float mag = PSVECMag(arg0);
    float scale;
    if (lbl_80564D7C > mag) mag = lbl_80564D7C;
    scale = lbl_80564D80 / mag;
    arg0[0] *= scale;
    arg0[1] *= scale;
    arg0[2] *= scale;
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802BEDFC(void) {
    class Resource {
    public:
        virtual void *getStyle(const char *);
        virtual void unused1();
        virtual int hasStyle(const char *);
        virtual void unused3();
        virtual const char *setProperty(const char *, const char *);
        virtual void unused5();
        virtual void unused6();
        virtual void unused7();
        virtual float setScale(const char *, float);
    };
    char *strings = lbl_8034ACA0;
    Resource *resource;
    Resource *style;
    lbl_8055FAE4 = (int)(0xE0000000u | 0x5030u);
    lbl_8055FAEC = (int)((0x20u << 16) | 0x2040u);
    lbl_8055FAE0 = lbl_80564D84;
    lbl_8055FAE8 = (int)(0xE1000000u - 1);
    lbl_8055FAF0 = (int)(0xE0000000u | 0x1040u);
    resource = (Resource *)fn_80131808(strings + 0x2C, (int)(0xE1000000u - 1), (int)0xE0000000u);
    if (resource != 0) {
        if (resource->hasStyle(strings + 0x38) != 0)
            style = (Resource *)resource->getStyle(strings + 0x38);
        else
            style = 0;
        if (style != 0) {
            lbl_8055FAE0 = style->setScale(strings + 0x44, lbl_8055FAE0);
            lbl_8055FAE4 = fn_802BECE4(style->setProperty(strings + 0x54, (const char *)&lbl_8055CF80), lbl_8055FAE4);
            lbl_8055FAE8 = fn_802BECE4(style->setProperty(strings + 0x68, (const char *)&lbl_8055CF80), lbl_8055FAE8);
            lbl_8055FAEC = fn_802BECE4(style->setProperty(strings + 0x78, (const char *)&lbl_8055CF80), lbl_8055FAEC);
            lbl_8055FAF0 = fn_802BECE4(style->setProperty(strings + 0x90, (const char *)&lbl_8055CF80), lbl_8055FAF0);
            fn_802E30C8(strings + 0xA4, lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0);
        }
        fn_80131818(resource);
    }
    lbl_8055FAF4 = lbl_8055FAE0;
}
#pragma scheduling on
#pragma cplusplus reset

float fn_802BEFB4(void) {
    float value;
    float limit;
    float result;
    fn_801E866C(-1);
    value = (*(float *)((char *)*(void **)((char *)fn_801EA9A0() + 8) + 0x64) - lbl_80564D88) / lbl_80564D8C;
    limit = lbl_80564D80;
    result = limit < value ? value : limit;
    limit = result;
    limit = limit > lbl_80564D90 ? lbl_80564D90 : limit;
    result = limit * lbl_80564D94;
    return lbl_80564D84 + result;
}

extern u32 lbl_802FABA0[];
float fn_802BF02C(float arg0, int arg1) {
    struct Pair { float x, y; } points[7];
    register u32 *src = lbl_802FABA0;
    register u32 *dst = (u32 *)points;
    register struct Pair *p;
    register struct Pair *q;
    register int i;
    register float min, t;
    float highX, lowX, highY, numerator, lowY, denominator;

    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    p = points + 1;
    i = 1;

    for (; i <= 6; ++p, ++i) {
        if (p->x > arg0) {
            q = points;
            min = lbl_80564D80;
            highX = q[i].x;
            lowX = q[i - 1].x;
            highY = q[i].y;
            numerator = arg0 - lowX;
            lowY = q[i - 1].y;
            denominator = highX - lowX;
            t = numerator / denominator;
            if (t < min) t = min;
            if (t > lbl_80564D90) t = lbl_80564D90;
            return lowY + t * (highY - lowY);
        }
    }
    return points[6].y;
}

extern unsigned int lbl_802FABD8[], lbl_802FAC00[];
extern float lbl_8055FAF8, lbl_80564D98, lbl_80564D80, lbl_80564D90, lbl_80564DA8, lbl_80564DAC;
extern double lbl_80564DA0;
extern float fn_802BEFB4(void);
extern float fn_801E7E24(void);
extern double fn_8002EFB4(double, double);
extern double cos(double);
extern void fn_802C9648(float);
extern void fn_802D3D6C(void);
extern float fn_802BF02C(float, int);
extern void fn_802C9900(float);
extern void fn_802D3D94(void *, int);
extern void fn_802C7040(int);
extern void fn_802C9904(void);
extern void fn_802D3D80(void);
extern void fn_802C967C(void);
#pragma scheduling invalid_target
#pragma processor 750
void fn_802BF160(void) {
    unsigned int scratch[17];
    register unsigned int *table;
    register volatile float *point;
    register unsigned int *src;
    register unsigned int i;
    register float f27, f28, f29, f30, f31;
    register float f2, f0, f1, f3, f5, f4;
    register unsigned int m3, m5, m7, m0, m1, m2, m4, m6;
    float elapsed, rate;

    if (lbl_8055CF6C == -1) return;
    elapsed = fn_802BEFB4();
    rate = fn_801E7E24();
    lbl_8055FAF8 += elapsed * rate;
    src = lbl_802FABD8;
    scratch[8] = *src++; scratch[9] = *src++; scratch[10] = *src++;
    scratch[11] = *src++; scratch[12] = *src++; scratch[13] = *src++;
    scratch[14] = *src++; scratch[15] = *src++; scratch[16] = *src;
    fn_802C9648(lbl_80564D98);
    fn_802D3D6C();
    f31 = lbl_80564D80;
    f30 = lbl_80564DA8;
    point = (volatile float *)(scratch + 8);
    table = lbl_802FAC00;
    f29 = lbl_80564DAC;
    f28 = lbl_80564D90;
    i = 0;
    do {
        f1 = lbl_8055FAF8;
        f0 = point[2];
        f1 = f1 + f0;
        f27 = (float)fn_8002EFB4((double)f1, lbl_80564DA0);
        f1 = f27;
        f2 = (float)cos((double)f1);
        f0 = point[0];
        f1 = f31 - f0;
        f0 = f2 - f30;
        f2 = f0 * f29;
        if (f31 < f2) f2 = f31;
        if (f2 < f28) f2 = f28;
        f3 = point[0];
        f0 = f1 - f28;
        m3 = table[3];
        f1 = f27;
        f5 = f31 / f3;
        m5 = table[5];
        m7 = table[7];
        m0 = table[0];
        m1 = table[1];
        f2 = f2 * f0;
        m2 = table[2];
        f0 = -f5;
        m4 = table[4];
        m6 = table[6];
        f4 = f28 + f2;
        ((volatile unsigned int *)scratch)[3] = m3;
        f2 = point[1];
        scratch[5] = m5;
        f3 = f4 + f3;
        f4 = f0 * f4;
        scratch[7] = m7;
        f0 = f28 - f3;
        scratch[0] = m0;
        scratch[1] = m1;
        f0 = f5 * f0;
        scratch[2] = m2;
        f0 = f28 + f0;
        scratch[4] = m4;
        f0 = f0 - f4;
        scratch[6] = m6;
        ((volatile float *)scratch)[3] = f2;
        ((volatile float *)scratch)[5] = f0;
        ((volatile float *)scratch)[7] = f4;
        fn_802C9900(fn_802BF02C(f27, (int)m6));
        fn_802D3D94(0, (int)scratch);
        fn_802C7040(lbl_8055CF6C);
        ++i;
        point += 3;
    } while (i < 3);
    fn_802C9904();
    fn_802D3D80();
    fn_802C967C();
}
void fn_802BF350(void) {
    int i;
    fn_802BEDFC();
    lbl_8055FADC = fn_801E85AC();
    for (i = 0; i < lbl_8055FADC; i++) {
        lbl_804C07F0[i] = (void *)fn_802C00A4();
        if (i == 0 && lbl_804C07F0[i] != 0) {
            fn_802E30C8(lbl_8034AD78);
        }
    }
    if (fn_8012C33C(lbl_8055CF68) != 0) {
        lbl_8055CF6C = fn_802C6FC0(lbl_8055CF68, 0, 0);
    } else {
        lbl_8055CF6C = -1;
    }
}

void fn_802BF40C(void) {
    int i;
    void **obj;
    int handle;
    for (i = 0; i < lbl_8055FADC; i++) {
        obj = (void **)lbl_804C07F0[i];
        if (obj != 0) {
            if (obj != 0) {
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
            }
            lbl_804C07F0[i] = 0;
        }
    }
    handle = lbl_8055CF6C;
    lbl_8055FADC = 0;
    if (handle != -1) {
        fn_802C6CF8();
        lbl_8055CF6C = -1;
    }
}

int fn_802BF4B0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

int fn_802BF4F0(void) {
    return (int)(unsigned int)lbl_804C07F0 != 0;
}

void fn_802BF508(void) {
    int index = fn_801E85B4();
    int saved;
    if (lbl_804C07F0[index] != 0 && lbl_8055CF70 != 0) {
        saved = fn_802C2C00(0);
        ((void (*)(void *, int))(*(void ***)lbl_804C07F0[index])[4])(lbl_804C07F0[index], 0);
        fn_802C2C00(saved);
    }
    fn_802BF160();
}

float fn_802BF590(void) { return lbl_8055FAF4; }

#pragma cplusplus on
extern "C" void fn_802BF598(int arg0, float farg0) {
    class Dummy {
    public:
        virtual void f0();
        virtual void f1(int, float);
    };
    int index = fn_801E85B4();
    Dummy *obj = (Dummy *)lbl_804C07F0[index];
    if (obj != 0) {
        obj->f1(arg0, farg0);
    }
}

extern float lbl_80564DA8;
extern float lbl_80564DB0;
extern "C" void fn_802BF600(void *arg0, void *dst, void *src) {
    float v4 = *(float *)((char *)src + 4);
    float v10 = *(float *)((char *)src + 0x10);
    float v1c = *(float *)((char *)src + 0x1C);
    float v28 = *(float *)((char *)src + 0x28);
    float scale = lbl_80564DA8;
    int i0 = *(int *)((char *)src + 0);
    int i8 = *(int *)((char *)src + 8);
    int ic = *(int *)((char *)src + 0xC);
    int i14 = *(int *)((char *)src + 0x14);
    int i18 = *(int *)((char *)src + 0x18);
    int i20 = *(int *)((char *)src + 0x20);
    int i24 = *(int *)((char *)src + 0x24);
    int i2c = *(int *)((char *)src + 0x2C);
    *(float *)((char *)dst + 4) = v4;
    *(float *)((char *)dst + 0x10) = v10;
    *(float *)((char *)dst + 0x1C) = v1c;
    *(float *)((char *)dst + 0x28) = v28;
    *(int *)((char *)dst + 0) = i0;
    *(int *)((char *)dst + 8) = i8;
    *(int *)((char *)dst + 0xC) = ic;
    *(int *)((char *)dst + 0x14) = i14;
    *(int *)((char *)dst + 0x18) = i18;
    *(int *)((char *)dst + 0x20) = i20;
    *(int *)((char *)dst + 0x24) = i24;
    *(int *)((char *)dst + 0x2C) = i2c;
    *(float *)((char *)dst + 4) = v4 * scale;
    *(float *)((char *)dst + 0x10) = v10 * scale;
    *(float *)((char *)dst + 0x1C) = v1c * scale;
    *(float *)((char *)dst + 0x28) = v28 * scale;
    *(float *)((char *)dst + 0x28) += lbl_80564DB0 * lbl_8055FAE0;
}

extern "C" void *fn_802BF780(void *);
extern "C" int fn_802BF6AC(void) {
    struct Dummy {
        virtual ~Dummy();
        virtual int f0();
        virtual int f1();
        virtual int f2();
    };
    extern void *fn_801284F8(int, const char *);
    extern const char lbl_8034AD90[];
    Dummy *obj = (Dummy *)fn_801284F8(0x18, lbl_8034AD90);
    if (obj != 0) {
        obj = (Dummy *)fn_802BF780(obj);
    }
    if (obj != 0) {
        if (obj->f2() == 0) {
            delete obj;
            obj = 0;
        }
    }
    return (int)obj;
}
#pragma scheduling on
#pragma cplusplus reset
extern void *fn_801284F8(int, const char*);
extern const char lbl_8034AD90[];
extern void* lbl_804C07F0[];
extern float lbl_80564DA8, lbl_80564DB0, lbl_8055FAE0;
int fn_802BF740(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_802BF780(void *arg0) {
    float zero, neg, one;
    float temp_f30;
    float temp_f31;
    char *temp_r3;
    char *var_r26;
    char *var_r27;
    int *var_r28;
    int var_r30;
    void *temp_r26;
    void *temp_r26_2;
    void *temp_r30;
    char *strings = lbl_8034ACA0;

    (*(char **)((char *)(arg0) + (0))) = lbl_8034AE40;
    (*(int *)((char *)(arg0) + (8))) = fn_802CB128(0x100, 0x100, 0, 0);
    temp_r26 = strings + 0xFC;
    if (fn_8012C33C(temp_r26) != 0) {
        (*(int *)((char *)(arg0) + (0xC))) = fn_802C6FC0((int)temp_r26, 0, 0);
    } else {
        (*(int *)((char *)(arg0) + (0xC))) = -1;
    }
    temp_r26_2 = strings + 0x10C;
    if (fn_8012C33C(temp_r26_2) != 0) {
        (*(int *)((char *)(arg0) + (0x10))) = fn_802C6FC0((int)temp_r26_2, 0, 0);
    } else {
        (*(int *)((char *)(arg0) + (0x10))) = -1;
    }
    if ((int) lbl_8055FAFC == 0) {
        temp_r3 = (char *)fn_801284F8(0x1B8, lbl_8055CF84);
        if (temp_r3 != 0) {
            temp_r30 = strings + 0x11C;
            if (fn_8012C33C(temp_r30) != 0) {
                (*(int *)((char *)(temp_r3) + (0x18))) = fn_802CAC28(temp_r30, 0);
            } else {
                (*(int *)((char *)(temp_r3) + (0x18))) = -2;
            }
            temp_f30 = lbl_80564D80;
            var_r28 = (int *)temp_r3;
            temp_f31 = lbl_80564D90;
            var_r26 = temp_r3;
            var_r27 = temp_r3 + 0x1C;
            var_r30 = 0;
            do {
                *var_r28 = fn_802CB128(0x100, 0x100, 0, 0x60);
                var_r30 += 1;
                (*(float *)((char *)(var_r27) + (0))) = temp_f30;
                var_r28 += 1;
                (*(float *)((char *)(var_r27) + (4))) = temp_f31;
                (*(float *)((char *)(var_r27) + (8))) = temp_f31;
                (*(float *)((char *)(var_r27) + (0xC))) = temp_f31;
                (*(float *)((char *)(var_r27) + (0x10))) = temp_f30;
                (*(float *)((char *)(var_r27) + (0x14))) = temp_f31;
                (*(float *)((char *)(var_r27) + (0x18))) = temp_f31;
                (*(float *)((char *)(var_r27) + (0x1C))) = temp_f31;
                (*(float *)((char *)(var_r27) + (0x20))) = temp_f30;
                var_r27 += 0x30;
                (*(float *)((char *)(var_r26) + (0x40))) = temp_f31;
                (*(float *)((char *)(var_r26) + (0x44))) = temp_f31;
                (*(float *)((char *)(var_r26) + (0x48))) = temp_f31;
                var_r26 += 0x30;
            } while (var_r30 < 6);
            one = lbl_80564D80; neg = lbl_80564DA8; zero = (float)lbl_80564D90;
            (*(float *)((char *)(temp_r3) + (0x64))) = zero;
            (*(float *)((char *)(temp_r3) + (0x68))) = zero;
            (*(float *)((char *)(temp_r3) + (0x6C))) = neg;
            (*(float *)((char *)(temp_r3) + (0x4C))) = neg;
            (*(float *)((char *)(temp_r3) + (0x50))) = zero;
            (*(float *)((char *)(temp_r3) + (0x54))) = zero;
            (*(float *)((char *)(temp_r3) + (0x7C))) = zero;
            (*(float *)((char *)(temp_r3) + (0x80))) = zero;
            (*(float *)((char *)(temp_r3) + (0x84))) = neg;
            (*(float *)((char *)(temp_r3) + (0x94))) = one;
            (*(float *)((char *)(temp_r3) + (0x98))) = zero;
            (*(float *)((char *)(temp_r3) + (0x9C))) = zero;
            (*(float *)((char *)(temp_r3) + (0xAC))) = zero;
            (*(float *)((char *)(temp_r3) + (0xB0))) = zero;
            (*(float *)((char *)(temp_r3) + (0xB4))) = one;
            (*(float *)((char *)(temp_r3) + (0xC4))) = neg;
            (*(float *)((char *)(temp_r3) + (0xC8))) = zero;
            (*(float *)((char *)(temp_r3) + (0xCC))) = zero;
            (*(float *)((char *)(temp_r3) + (0xE8))) = zero;
            (*(float *)((char *)(temp_r3) + (0xEC))) = zero;
            (*(float *)((char *)(temp_r3) + (0xF0))) = neg;
            (*(float *)((char *)(temp_r3) + (0xF4))) = zero;
            (*(float *)((char *)(temp_r3) + (0xF8))) = one;
            (*(float *)((char *)(temp_r3) + (0xFC))) = zero;
            (*(float *)((char *)(temp_r3) + (0x118))) = zero;
            (*(float *)((char *)(temp_r3) + (0x11C))) = zero;
            (*(float *)((char *)(temp_r3) + (0x120))) = one;
            (*(float *)((char *)(temp_r3) + (0x124))) = zero;
            (*(float *)((char *)(temp_r3) + (0x128))) = neg;
            (*(float *)((char *)(temp_r3) + (0x12C))) = zero;
            (*(float *)((char *)(temp_r3) + (0x13C))) = neg;
            (*(float *)((char *)(temp_r3) + (0x140))) = one;
            (*(float *)((char *)(temp_r3) + (0x144))) = one;
            (*(int *)((char *)(temp_r3) + (0x148))) = -1;
            (*(float *)((char *)(temp_r3) + (0x14C))) = zero;
            (*(float *)((char *)(temp_r3) + (0x150))) = zero;
            (*(float *)((char *)(temp_r3) + (0x154))) = one;
            (*(float *)((char *)(temp_r3) + (0x158))) = one;
            (*(float *)((char *)(temp_r3) + (0x15C))) = one;
            (*(int *)((char *)(temp_r3) + (0x160))) = -1;
            (*(float *)((char *)(temp_r3) + (0x164))) = one;
            (*(float *)((char *)(temp_r3) + (0x168))) = zero;
            (*(float *)((char *)(temp_r3) + (0x16C))) = neg;
            (*(float *)((char *)(temp_r3) + (0x170))) = neg;
            (*(float *)((char *)(temp_r3) + (0x174))) = one;
            (*(int *)((char *)(temp_r3) + (0x178))) = -1;
            (*(float *)((char *)(temp_r3) + (0x17C))) = zero;
            (*(float *)((char *)(temp_r3) + (0x180))) = one;
            (*(float *)((char *)(temp_r3) + (0x184))) = one;
            (*(float *)((char *)(temp_r3) + (0x188))) = neg;
            (*(float *)((char *)(temp_r3) + (0x18C))) = one;
            (*(int *)((char *)(temp_r3) + (0x190))) = -1;
            (*(float *)((char *)(temp_r3) + (0x194))) = one;
            (*(float *)((char *)(temp_r3) + (0x198))) = one;
            (*(short *)((char *)(temp_r3) + (0x19C))) = 0;
            (*(short *)((char *)(temp_r3) + (0x19E))) = 1;
            (*(short *)((char *)(temp_r3) + (0x1A0))) = 2;
            (*(short *)((char *)(temp_r3) + (0x1A2))) = 1;
            (*(short *)((char *)(temp_r3) + (0x1A4))) = 2;
            (*(short *)((char *)(temp_r3) + (0x1A6))) = 3;
            (*(signed char *)((char *)(temp_r3) + (0x1A8))) = 0;
        }
        lbl_8055FB00 = temp_r3;
    }
    lbl_8055FAFC += 1;
    (*(int **)((char *)(arg0) + (4))) = lbl_8055FB00;
    (*(float *)((char *)(arg0) + (0x14))) = one;
    return arg0;
}
#pragma pop

extern void fn_802CB228(void *);
extern int lbl_8055FAFC;
extern void *lbl_8055FB00;
extern char lbl_8034AE40[];
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_802BFA58(void *arg0, int arg1) {
    struct SharedTable {
        void *items[6];
        int val;
        void cleanup() {
            void **cur = items;
            int i = 0;
            do {
                fn_802CB228(*cur);
                cur++;
                i++;
            } while (i < 6);
            if (val != -2) {
                fn_802CAC54(val);
            }
            fn_80128668(this);
        }
    };
    int id;
    int c;

    if (arg0 != 0) {
        id = *(int *)((char *)arg0 + 8);
        *(char **)arg0 = lbl_8034AE40;
        if (id != -2) {
            fn_802CB228((void *)id);
            *(int *)((char *)arg0 + 8) = -2;
        }
        c = *(int *)((char *)arg0 + 0xC);
        if (c != -1) {
            fn_802C6CF8(c);
            *(int *)((char *)arg0 + 0xC) = -1;
        }
        c = *(int *)((char *)arg0 + 0x10);
        if (c != -1) {
            fn_802C6CF8(c);
            *(int *)((char *)arg0 + 0x10) = -1;
        }
        if (*(int *)((char *)arg0 + 4) != 0) {
            if (--lbl_8055FAFC == 0) {
                SharedTable *table = (SharedTable *)lbl_8055FB00;
                if (table != 0) {
                    table->cleanup();
                }
                lbl_8055FB00 = 0;
            }
            *(int *)((char *)arg0 + 4) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_802BFB70(void *arg0, int arg1, float angle) {
    class Camera { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void unused(); virtual void e(void *, int, void *); };
    /* Draw the six views and restore the previous render state. */
    float transform[12], old2[12], old1[12], matrix[12];
    float rotation[3], viewport[4], direction[3], viewport0[4], initial[3], adjust[3], value;
    char *obj = (char *)arg0;
    char *views;
    char *p;
    int *handles;
    int i;
    float theta;
    *(float *)(obj + 0x14) = fn_801E85A4() == 2 ? lbl_80564DB4 : lbl_80564D80;
    views = *(char **)(obj + 4);
    if (!*(unsigned char *)(views + 0x1a8)) {
        p = views + 0x1c; handles = (int *)views;
        for (i=0; i<6; i++, handles++, p+=0x30) {
            fn_802CB274(*handles); fn_802C9294(*handles,0);
            fn_802C9694(initial,lbl_80564D80,lbl_80564DB8,lbl_80564DBC);
            fn_802C86F0(viewport0,0,0,0x100,0x100);
            fn_802C8B08(old1); fn_802C8638(p); fn_802C88BC(3); fn_802C10C8();
            fn_802C9294(-2,0); fn_802C8638(old1); fn_802C8750(viewport0,-1); fn_802C96DC(initial,-1);
        }
        *(unsigned char *)(views + 0x1a8) = 1;
    }
    fn_802CB274(*(int *)(obj+8)); fn_802C9294(*(int *)(obj+8),1);
    direction[0]=lbl_80564D90; direction[1]=lbl_80564D80; direction[2]=lbl_80564D90;
    ((Camera *)arg0)->e(transform,arg1,direction);
    theta=lbl_80564DB0 * (float)atan(*(float *)(obj+0x14) * (float)fn_8002EF30(lbl_80564DAC * angle));
    fn_802C9694(rotation,lbl_80564D80,lbl_80564DC0,theta);
    fn_802C86F0(viewport,0,0,0x100,0x100);
    fn_802C8B08(old2); fn_802C8638(transform); fn_802C88BC(2);
    if (*(void **)(obj+4)) {
        value=theta; views=*(char **)(obj+4);
        ((void (*)(float *))fn_802C00A0)(&value);
        fn_802C9694(adjust,lbl_80564DC4,lbl_80564DB0,value);
        handles=(int *)views; p=views+0x1c;
        for(i=0;i<6;i++,handles++,p+=0x30) {
            fn_80144DC8(matrix); fn_802C0054(matrix,p);
            fn_80144DAC((char *)matrix+0x24,(char *)transform+0x24);
            fn_802C8B98(*handles,matrix);
            fn_802C8DB8(views+0x13c,4,(unsigned short *)(views+0x19c),6); fn_802C8D74();
        }
        fn_802BFE48(views,transform,lbl_80564D80); fn_802C96DC(adjust,-1);
    }
    fn_802C7040(*(int *)(obj+0xc));
    if (fn_801E85A4()==1) fn_802BDD8C(lbl_80564DC8);
    if (*(int *)(obj+0x10)!=-1) fn_802C7040(*(int *)(obj+0x10));
    fn_802C9294(-2,0); fn_802C8638(old2); fn_802C8750(viewport,-1); fn_802C96DC(rotation,-1);
}
#pragma pop

#pragma cplusplus reset
extern float lbl_80564DCC, lbl_80564DD0, lbl_80564DD4;
extern unsigned short lbl_802FAC20;
extern void fn_80015A20(void *, float *);
extern void fn_80015B20(float *, void *, float *);
extern void fn_802C8B98(int, float *);
extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void fn_802C8D74(void);
void fn_802BFE48(void *arg0, void *arg1, float arg2) {
    if (*(int *)((char *)arg0 + 0x18) != -2) {
        struct V { float x, y, z; int color; float u, v; } v[4];
        float matbuf[12];
        float rot[9];
        unsigned short idx[6] = { 0, 1, 2, 2, 1, 3 };
        float vec[3];
        float x, y;
        float *mat = matbuf;
        struct V *p = v;
        int i;
        x = lbl_80564DCC * arg2;
        y = lbl_80564DD0 * arg2;
        for (i = 0; i < 4; i++) {
            p->x = (i & 1) ? x : -x;
            p->y = (i & 2) ? x : -x;
            p->z = y;
            p->color = -1;
            p->u = (i & 1) ? lbl_80564D80 : lbl_80564D90;
            p->v = (i & 2) ? lbl_80564D80 : lbl_80564D90;
            p++;
        }
        mat[0] = lbl_80564D80; mat[1] = lbl_80564D90; mat[2] = lbl_80564D90; mat[3] = lbl_80564D90;
        mat[4] = lbl_80564D80; mat[5] = lbl_80564D90; mat[6] = lbl_80564D90; mat[7] = lbl_80564D90;
        mat[8] = lbl_80564D80;
        mat[9] = ((float *)arg1)[9];
        mat[10] = ((float *)arg1)[10];
        mat[11] = ((float *)arg1)[11];
        vec[0] = lbl_80564DD4; vec[1] = lbl_80564D90; vec[2] = lbl_80564D90;
        fn_80015A20(rot, vec);
        fn_80015B20(mat, rot, mat);
        fn_802C8B98(*(int *)((char *)arg0 + 0x18), mat);
        fn_802C8DB8(v, 4, idx, 6);
        fn_802C8D74();
    }
}

void fn_802C0054(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_802C00A0(void) {
}

extern void *fn_801284F8(int, const char *);
extern void *fn_802C0138(void *);
extern char lbl_8034ADC8[];
int fn_802C00A4(void) {
    extern void *fn_801284F8(int, const char *);
    extern void *fn_802C0138(void *);
    extern char lbl_8034ADC8[];
    void *obj;
    obj = fn_801284F8(0x2c60, lbl_8034ADC8);
    if (obj == 0)
        return 0;
    obj = fn_802C0138(obj);
    if (obj != 0) {
        if (((int (*)(void *))(*(void ***)obj)[5])(obj) == 0) {
            if (obj != 0)
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
            obj = 0;
        }
    }
    return (int)obj;
}

void *fn_802C0138(void *arg0) {
    register char *resourceB = lbl_8034ACA0 + 0x144;
    register char *resourceA = lbl_8034ACA0 + 0x134;
    void *vtable = lbl_8034AE08;
    float initial = lbl_80564DF0;
    char *out;
    register int row;
    register int rowBase;
    int innerBase;

    *(unsigned char *)((char *)arg0 + 0x2C5C) = 0;
    *(void **)arg0 = vtable;
    *(int *)((char *)arg0 + 0x2C50) = -2;
    *(int *)((char *)arg0 + 0x2C54) = -2;
    *(int *)((char *)arg0 + 0x2C58) = 0;
    lbl_8055FB04 = initial;
    if (fn_8012C33C(lbl_8034ACA0 + 0x154, 0, vtable, lbl_8034ACA0) == 0)
        return arg0;
    if (fn_8012C33C(resourceA) != 0)
        *(int *)((char *)arg0 + 0x2C50) = fn_802CAC28(resourceA, 0);
    *(int *)((char *)arg0 + 0x2C58) = fn_802BF6AC();
    if (fn_8012C33C(resourceB) != 0)
        *(int *)((char *)arg0 + 0x2C54) = fn_802CAC28(resourceB, 0);

    out = (char *)arg0 + 4;
    row = 0;
    rowBase = 0;
    do {
        int r7 = (row + 1) << 4;
        int r6 = r7;
        int count;
        innerBase = 0;
        for (count = 0; count < 3; count++) {
            int r4 = innerBase + rowBase;
            int r3 = r4;
            int r9;
            int r8;
            int r10;
            int r12;
            int r29;
            int r11;
            int r30;
            *(short *)(out + 0x00) = r4;
            r3 = r3 + 1;
            *(short *)(out + 0x02) = r3;
            r9 = innerBase + r7;
            r8 = innerBase + r7;
            *(short *)(out + 0x04) = r6;
            *(short *)(out + 0x06) = r6;
            r8 = r8 + 1;
            r10 = r4 + 2;
            *(short *)(out + 0x08) = r3;
            r12 = r4 + 3;
            r29 = r4 + 4;
            *(short *)(out + 0x0A) = r8;
            r11 = r9 + 3;
            r30 = r9 + 4;
            *(short *)(out + 0x0C) = r3;
            r3 = r9;
            r9 = r9 + 2;
            *(short *)(out + 0x0E) = r10;
            r4 = r4 + 5;
            r3 = r3 + 5;
            *(short *)(out + 0x10) = r8;
            r6 = r6 + 5;
            innerBase = innerBase + 5;
            *(short *)(out + 0x12) = r8;
            *(short *)(out + 0x14) = r10;
            *(short *)(out + 0x16) = r9;
            *(short *)(out + 0x18) = r10;
            *(short *)(out + 0x1A) = r12;
            *(short *)(out + 0x1C) = r9;
            *(short *)(out + 0x1E) = r9;
            *(short *)(out + 0x20) = r12;
            *(short *)(out + 0x22) = r11;
            *(short *)(out + 0x24) = r12;
            *(short *)(out + 0x26) = r29;
            *(short *)(out + 0x28) = r11;
            *(short *)(out + 0x2A) = r11;
            *(short *)(out + 0x2C) = r29;
            *(short *)(out + 0x2E) = r30;
            *(short *)(out + 0x30) = r29;
            *(short *)(out + 0x32) = r4;
            *(short *)(out + 0x34) = r30;
            *(short *)(out + 0x36) = r30;
            *(short *)(out + 0x38) = r4;
            *(short *)(out + 0x3A) = r3;
            out += 0x3C;
        }
        row++;
        rowBase += 16;
    } while (row < 63);
    *(unsigned char *)((char *)arg0 + 0x2C5C) = 1;
    return arg0;
}

extern char lbl_8034AE08[];
#pragma cplusplus on
extern "C" void *fn_802C0310(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0(int);
    };
    int id;
    void *obj;
    if (arg0 != 0) {
        id = *(int *)((char *)arg0 + 0x2c50);
        *(void **)arg0 = lbl_8034AE08;
        if (id != -2) fn_802CAC54(id);
        id = *(int *)((char *)arg0 + 0x2c54);
        if (id != -2) fn_802CAC54(id);
        obj = *(void **)((char *)arg0 + 0x2c58);
        if (obj != 0) {
            if (obj != 0)
                ((Obj *)obj)->v0(1);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma cplusplus off
void fn_802C03B4(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x2c58);
    void (*fn)(void *);
    if (obj == 0) return;
    if (lbl_8055CF71 == 0) return;
    fn = (void (*)(void *))(*(void ***)obj)[3];
    fn(obj);
}

#pragma push
#pragma peephole off
int fn_802C03E0(unsigned int arg0) {
    unsigned int a = __rlwinm(arg0, 8, 8, 23);
    unsigned int b = (arg0 << 8) & 0xFF0000FF;
    return a | b;
}
#pragma pop
int fn_802C0C98(void *arg0) { return *(int *)((char *)arg0 + 8); }

float fn_802C0CA0(void *arg0) { return *(float *)((char *)arg0 + 0x14); }

int fn_802C0CA8(void) { return 1; }

void *fn_802C0CB0(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8034AE20;
        if (temp_r0 != -2) {
            fn_802CAC54(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_802C0D20(void) {
}

int fn_802C0D24(void *arg0) {
    return *(int *)((char *)arg0 + 4);
}

float fn_802C0D2C(void) {
    return lbl_80564D80;
}

unsigned int fn_802C0D34(void) {
    return 1;
}

unsigned char fn_802C0D3C(void *arg0) {
    return *((unsigned char *)arg0 + 0x2C5C);
}

extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C();
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
