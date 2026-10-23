#pragma push
#pragma cplusplus on
class Dummy8016707C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void *get();
    virtual void v5();
    virtual void v6();
    virtual void run(int, int);
};
#pragma cplusplus off
#pragma pop
extern float fn_801660C0(void);
extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void fn_80165FAC(void);
extern void fn_80163550(int);
extern void fn_80166754(void *);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void (*)(void *), void *, int, int);
extern float lbl_8055E324;
extern unsigned char lbl_8055E334;
extern char lbl_8055A190;
extern char lbl_8032FCC0[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
__declspec(section ".data") extern float lbl_80558DC4;
#pragma pop
extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_80139E18();
extern void *memset(void *, int, unsigned int);
extern unsigned char lbl_8055E32C;
extern float lbl_805618F0;
extern float lbl_8055E318;
extern float fn_80129DC4(int, float, float, float);

extern unsigned char lbl_8055E32A;
extern unsigned char lbl_8055E32B;
#pragma push
#pragma small_data off
__declspec(section ".data") extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
#pragma pop
extern float lbl_8056189C;
extern double lbl_80561890;
extern float lbl_8055E320;
extern float fn_8013672C(int);
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern float fn_8013672C(int);
extern float lbl_8056189C;
extern double lbl_80561890;
extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
extern float lbl_8055E320;
#pragma push
#pragma small_data off
void *fn_80165970(void *arg0, int arg1) {
    if (arg0 == 0) goto done;
    if (arg0 == 0) goto after_clear;
    *(int *)arg0 = 0;
    *((int *)arg0 + 1) = 0;
    *((int *)arg0 + 2) = 0;
after_clear:
    if (arg1 > 0) fn_80128668(arg0);
done:
    return arg0;
}

void fn_801659C8(int arg0) {
    fn_80163550(arg0 - 0x56C);
}

#pragma push
#pragma dont_inline on
float fn_801659D0(int arg0) {
    float temp_f31;
    temp_f31 = fn_8013672C(arg0);
    return temp_f31 * (float)fn_800081F0(arg0);
}

extern int strcmp(const char *, const char *);
extern float lbl_80561898;
extern float lbl_805618A0;
extern char lbl_8055A150[];
extern char lbl_8055A158[];
extern char lbl_8055A160[];
extern char lbl_8055A168[];
void fn_80165A30(void *arg0, int arg1) {
    int i;
    int count;
    int j = 0;
    void *item;
    void **vtable;
    float x, y, z;
    void *entry;
    *(int *)((char *)&lbl_8042FEB0 + 4) = 0;
    for (;;) {
        vtable = *(void ***)arg0;
        item = ((void *(*)(void *, int))vtable[24])(arg0, j);
        if (item == 0) break;
        vtable = *(void ***)item;
        if (strcmp(((char *(*)(void *))vtable[2])(item), lbl_8055A150) == 0) {
            count = *(int *)((char *)&lbl_8042FEB0 + 4);
            *(int *)((char *)&lbl_8042FEB0 + 4) = count + 1;
            entry = *(void **)&lbl_8042FEB0;
            entry = (char *)entry + count * 0x14;
            vtable = *(void ***)item;
            x = ((float (*)(void *, const char *))vtable[9])(item, lbl_8055A158);
            vtable = *(void ***)item;
            y = ((float (*)(void *, const char *))vtable[9])(item, lbl_8055A160);
            vtable = *(void ***)item;
            *(float *)entry = ((float (*)(void *, const char *))vtable[9])(item, lbl_8055A168);
            z = x * lbl_80561898;
            *(float *)((char *)entry + 4) = y;
            *(float *)((char *)entry + 8) = z;
            *(int *)((char *)entry + 0x10) = -1;
            *(float *)((char *)entry + 0xC) = lbl_8055E318 - fn_80129DC4(3, lbl_8056189C, lbl_805618A0 * z, 0.0f);
        }
        j++;
    }
}

#pragma pop
void *fn_80166040(int arg0) {
    void *base;
    void *cur;
    void *found;
    int count;
    int i;
    base = *(void **)&lbl_8042FEB0;
    count = *(int *)((char *)&lbl_8042FEB0 + 4);
    cur = base;
    found = 0;
    i = 0;
    while (count > 0) {
        if (*(int *)((char *)cur + 0x10) == -1) {
            found = (char *)base + i * 0x14;
            *(int *)((char *)found + 0x10) = arg0;
            break;
        }
        cur = (char *)cur + 0x14;
        i++;
        count--;
    }
    return found;
}
#pragma pop
void fn_80166098(void) {
    fn_80179630(-1);
    fn_801B2EC0();
}

int fn_8016616C(void) {
    return lbl_8055E320 > *(float *)((char *)&lbl_8042FE38 + 0x48);
}

#pragma processor 750
#pragma dont_inline on
float fn_8016618C(void *arg0) {
    float result;
    float a;
    float b;
    int index;
    void *other;
    other = ((void *(*)(void))fn_80166098)();
    a = *(float *)((char *)(*(void *(***)(void *))other)[6](other) + 0x48);
    b = *(float *)((char *)(*(void *(***)(void *))arg0)[6](arg0) + 0x48);
    index = *(int *)((char *)(*(void *(***)(void *))arg0)[4](arg0) + 4);
    if (*(int *)((char *)(*(void *(***)(void *))other)[4](other) + 4) < index) {
        if (a < b) a += ((float (*)(void))fn_8013672C)();
        result = b - a;
    } else {
        if (b < a) b += ((float (*)(void))fn_8013672C)();
        result = b - a;
    }
    return result + *(float *)((char *)&lbl_8042FE38 + 0x58);
}
#pragma dont_inline reset

extern void fn_80128668(void *);
extern void fn_80163550(int);
extern int fn_800081F0(int);
extern int fn_801B2EC0(void);
extern void *fn_8017960C(void);
extern float lbl_805618D0;
extern float lbl_805618D4;
#pragma push
#pragma dont_inline on
float fn_80166274(void) {
    float f2 = lbl_805618D0;
    void *p;
    fn_80179630(-1);
    p = *(void **)(*(int *)(fn_801B2EC0()) + 0x1C);
    p = ((void *(*)(void))p)();
    fn_80179630(-1);
    {
        void *r3 = fn_8017960C();
        float f0 = *(float *)(*(int *)((char *)p + 4) + 0x20);
        float f1 = *(float *)((char *)r3 + 0x25CC);
        if (f2 <= f0) f2 = f0;
        f0 = f1 / f2;
        if (lbl_805618D4 > f0) f0 = lbl_805618D4;
        return f0;
    }
}

#pragma pop
extern void fn_802E30C8(char *, ...);
extern int lbl_8055E330;
extern signed char lbl_8055E329;
extern unsigned char lbl_8055E328;
extern float lbl_8055E31C;
extern char lbl_8032FEC0[];
extern char lbl_8032FF08[];
#pragma push
void fn_801662FC(void) {
    int flag;
    int count = lbl_8055E330;
    lbl_8055E329 = flag = ((unsigned char)count == 255);
    lbl_8055E330 = count + 1;
    if (flag && lbl_8055E328) {
        if (!((float)__fabs(lbl_8055E31C - lbl_805618D0) <= lbl_80558DC4)) {
            fn_802E30C8(lbl_8032FEC0, lbl_8055E31C, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
        } else {
            fn_802E30C8(lbl_8032FF08, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
        }
    }
}

#pragma push
#pragma processor gekko
#pragma use_lmw_stmw off
void fn_801663C8(int count, void *records, void *config) {
    typedef struct Entry { int id; unsigned char flag; char pad[0x83]; } Entry;
    typedef struct Holder { Entry *entries; int used; int count; Entry *base; } Holder;
    typedef struct Record { int type; char pad[0x74]; } Record;
    char *strings = lbl_8032FCC0;
    void *obj;
    Holder *holder;
    void *array;
    int i;
    float value;
    lbl_8055E324 = fn_801659D0((int)config);
    fn_80165FAC();
    obj = *(void **)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    value = (*(float (***)(void *, char *, float))obj)[10](obj, strings + 0x270, *(float *)((char *)&lbl_8042FE38 + 0xC));
    *(float *)((char *)&lbl_8042FE38 + 0xC) = value;
    fn_802E30C8(strings + 0x280, *(float *)((char *)&lbl_8042FE38 + 8), (float)(double)value, *(float *)((char *)&lbl_8042FE38 + 4), *(float *)&lbl_8042FE38);
    holder = fn_801284F8(16, strings + 0x2A0);
    if (holder) {
        array = fn_8002F37C(fn_8012850C(count * 0x88 + 16, &lbl_8055A190), fn_80166754, 0, 0x88, count);
        *(void **)holder = array;
        *(int *)((char *)holder + 8) = count;
        *(int *)((char *)holder + 4) = 0;
        *(void **)((char *)holder + 12) = array;
    }
    *(void **)&lbl_8055E32C = holder;
    *(int *)((char *)holder + 4) = 0;
    for (i = 0; i < count; i++) {
        int type = ((Record *)records)[i].type;
        Holder *h = *(Holder **)&lbl_8055E32C;
        Entry *p = &h->entries[h->used++];
        p->id = i;
        p->flag = type == 0x50;
    }
    lbl_8055E32B = 0;
    lbl_8055E32A = *(int *)((char *)config + 4) != 0x180304;
    *(int *)&lbl_8055E334 = 0;
}
#pragma pop
int fn_801667F0(void) {
    int result = 0;
    if (lbl_8055E32A) {
        if (!lbl_8055E32B) result = 1;
    }
    return result;
}

void fn_80166814(void) {
    if (*(void **)&lbl_8055E334 != 0) {
        fn_80139E18(*(void **)&lbl_8055E334);
        *(void **)&lbl_8055E334 = 0;
    }
    {
        void *p = *(void **)&lbl_8055E32C;
        if (p != 0) {
            void *x = *(void **)((char *)p + 0xC);
            if (x != 0) {
                fn_80128670((char *)x - 0x10);
            }
            fn_80165970(p, 1);
            *(void **)&lbl_8055E32C = 0;
        }
    }
}

extern float lbl_805618A0, lbl_805618D0, lbl_805618E4, lbl_805618E8;
extern void *memset(void *, int, unsigned int);
void fn_80166898(void) {
    float zero = lbl_8056189C;
    float height = lbl_805618D0;
    float scale = lbl_805618A0;
    int zeroInt = 0;
    int i = 0;
    int offset = 0;
    lbl_8055E32B = zeroInt;
    lbl_8055E318 = zero;
    lbl_8055E320 = zero;
    lbl_8055E31C = zero;
    while (i < *(int *)(*(unsigned char **)&lbl_8055E32C + 4)) {
        unsigned char *base = *(unsigned char **)&lbl_8055E32C;
        unsigned char *p = base + offset;
        *(float *)(p + 0xC) = height;
        *(float *)(p + 8) = height;
        *(float *)(p + 0x14) = zero;
        *(float *)(p + 0x10) = zero;
        *(float *)(p + 0x1C) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618E4, lbl_805618E8);
        *(float *)(p + 0x20) = zero;
        *(float *)(p + 0x24) = height;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x3C) = zero;
        *(float *)(p + 0x54) = lbl_8055E318 - ((float (*)(int, float, float))fn_80129DC4)(3, zero, scale * *(float *)(p + 0x50));
        *(int *)(p + 0x58) = zeroInt;
        p[0x5C] = zeroInt; p[0x5E] = zeroInt; p[0x5D] = zeroInt; p[5] = zeroInt; p[0x5F] = zeroInt; p[0x60] = zeroInt; p[0x2C] = zeroInt;
        *(float *)(p + 0x30) = zero;
        memset(p + 0x64, zeroInt, 0x24);
        offset += 0x88;
        i++;
    }
    {
        unsigned char *base = *(unsigned char **)&lbl_8042FEB0;
        int count = *(int *)((unsigned char *)&lbl_8042FEB0 + 4);
        int j = zeroInt;
        offset = zeroInt;
        while (j < count) {
            unsigned char *p = base + offset;
            *(int *)(p + 0x10) = -1;
            *(float *)(p + 0xC) = lbl_8055E318 - ((float (*)(int, float, float))fn_80129DC4)(3, lbl_8056189C, scale * *(float *)(p + 8));
            offset += 0x14;
            j++;
        }
    }
}

extern char lbl_8032FF6C[];
extern float lbl_8055E3C8;
extern float fn_801429D0(float, float);
extern float fn_8014C8B4(float, float, float, float, float);
extern float fn_8014C8F8(float, float);
extern void *fn_80156A40(void);
extern void fn_801662FC(void);
extern float fn_80166DD4(void *);
extern void fn_80166E54(void *);
extern void fn_80166E68(float *, float);
extern void fn_80166F3C(float *);
extern int fn_80166F78(float *);
extern float fn_80166F90(float *);
extern void fn_8016707C(void *, void **);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80166A24(void) {
    int wasActive;
    int offset;
    int i;
    int zero = 0;
    float time;
    float previous;
    float delta;
    float amount;
    float stateValue;
    float emptyValue;
    int active;

    if (!((int (*)(void))fn_801667F0)()) return;

    wasActive = ((int (*)(void))fn_8016616C)();
    lbl_8055E318 = lbl_8055E3C8;
    lbl_8055E31C = lbl_805618D0;
    if (*((unsigned char *)&lbl_8042FE38 + 0x4D) != 0) {
        lbl_8055E31C *= fn_80166274();
    }
    lbl_8055E320 = fn_801660C0();

    if (((int (*)(void))fn_8016616C)() && !wasActive) {
        if (lbl_8055E328 != 0) {
            fn_802E30C8(lbl_8032FF6C);
        }
        for (i = 0, offset = 0;
             i < *(int *)((unsigned char *)(*(unsigned char * volatile *)&lbl_8055E32C) + 4);
             i++, offset += 0x88) {
            unsigned char *record =
                *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + offset;
            void *object = (void *)((int (*)(int))fn_801B2EC0)(*(int *)record);
            time = fn_8016618C(object);
            record[0x2C] = 1;
            *(float *)(record + 0x30) = time;
        }
    }

    ((void (*)(void))fn_801662FC)();
    previous = lbl_80561898;
    emptyValue = lbl_805618D0;
    for (i = 0, offset = 0;
         i < *(int *)((unsigned char *)(*(unsigned char * volatile *)&lbl_8055E32C) + 4);
         i++, offset += 0x88) {
        unsigned char *record =
            *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + offset;
        void *object = (void *)((int (*)(int))fn_801B2EC0)(*(int *)record);
        fn_8016707C(record, (void **)object);
        if (*(void **)(record + 0x58) != 0) {
            time = fn_8016618C(object);
            *(float *)(record + 0x28) = time;
            stateValue = fn_80166F90((float *)(record + 0x58));
            if (record[0x2C] != 0) {
                delta = time - *(float *)(record + 0x30);
            } else {
                delta = time - stateValue;
            }

            if (fn_80166F78((float *)(record + 0x1C))) {
                fn_801429D0(lbl_8056189C,
                            *(float *)((unsigned char *)&lbl_8042FE38 + 0x10) - previous);
                fn_80166F3C((float *)(record + 0x1C));
                amount = fn_8014C8B4(*(float *)&lbl_8042FE38,
                                     *(float *)((unsigned char *)&lbl_8042FE38 + 4),
                                     *(float *)((unsigned char *)&lbl_8042FE38 + 0xC),
                                     *(float *)((unsigned char *)&lbl_8042FE38 + 8), delta);
                active = time > *(float *)((unsigned char *)&lbl_8042FE38 + 0x18) &&
                         time < *(float *)((unsigned char *)&lbl_8042FE38 + 0x1C);
                record[5] = active;
                if (active) {
                    amount = fn_8014C8F8(*(float *)((unsigned char *)&lbl_8042FE38 + 0x20),
                                         *(float *)((unsigned char *)&lbl_8042FE38 + 0x24));
                }
                fn_80166E68((float *)(record + 8),
                            *(float *)((unsigned char *)&lbl_8042FE38 + 0x54) +
                            amount * lbl_8055E31C);
            }

            active = 0;
            if (*((unsigned char *)&lbl_8042FE38 + 0x4C) != 0 &&
                (delta < *(float *)&lbl_8042FE38 ||
                 delta > *(float *)((unsigned char *)&lbl_8042FE38 + 4))) {
                active = 1;
            }
            if (active) {
                fn_80166E54(*(void **)(record + 0x58));
            }

            active = delta > *(float *)((unsigned char *)&lbl_8042FE38 + 0x2C);
            if (delta > *(float *)((unsigned char *)&lbl_8042FE38 + 0x28) &&
                fn_80166F78((float *)(record + 0x20))) {
                if (active) {
                    ((Dummy8016707C *)fn_80156A40())->run(*(int *)record, 1);
                } else {
                    ((Dummy8016707C *)fn_80156A40())->run(*(int *)record, 0);
                }
                fn_80166F3C((float *)(record + 0x20));
            }

            if (active) {
                fn_80166E68((float *)(record + 0x34), lbl_805618D0);
            } else {
                fn_80166E68((float *)(record + 0x34), lbl_8056189C);
            }
            *(float *)(record + 0x24) = fn_80166DD4(record + 8);
            record[0x5D] = delta > *(float *)((unsigned char *)&lbl_8042FE38 + 0x34);
            record[0x5C] = delta > *(float *)((unsigned char *)&lbl_8042FE38 + 0x30);
            record[0x5E] = delta < *(float *)((unsigned char *)&lbl_8042FE38 + 0x38);
            record[0x5F] = delta < *(float *)((unsigned char *)&lbl_8042FE38 + 0x40);
            record[0x60] = delta < *(float *)((unsigned char *)&lbl_8042FE38 + 0x44);
        } else {
            record[0x5C] = zero;
            record[0x5E] = zero;
            record[0x5D] = zero;
            record[0x5F] = zero;
            record[0x60] = zero;
            *(float *)(record + 0x24) = emptyValue;
            memset(record + 0x64, zero, 0x24);
        }
    }
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
float fn_80166DD4(void *arg0) {
    float y0, y1, t, x0, x1;
    y1 = *(float *)((char *)arg0 + 0xC);
    y0 = *(float *)((char *)arg0 + 8);
    if (fabs(y0 - y1) <= lbl_80558DC4) return *(float *)arg0;
    t = (lbl_8055E318 - y0) / (y1 - y0);
    x1 = *(float *)((char *)arg0 + 4);
    x0 = *(float *)arg0;
    if (t < lbl_805618D0) t = lbl_805618D0;
    if (t > lbl_8056189C) t = lbl_8056189C;
    return x0 + t * (x1 - x0);
}

void fn_80166E54(void *arg0) {
    *(float *)((char *)arg0 + 0xC) += lbl_805618F0;
}

void fn_80166E68(float *arg0, float arg1) {
    float value;
    float factor;
    float start;
    float end;
    if ((float)__fabs(arg1 - arg0[1]) <= lbl_80558DC4) return;
    start = arg0[2];
    end = arg0[3];
    if ((float)__fabs(start - end) <= lbl_80558DC4) {
        value = arg0[0];
    } else {
        float oldValue = arg0[0];
        float oldTarget = ((volatile float *)arg0)[1];
        float ratio = (lbl_8055E318 - start) / (end - start);
        factor = lbl_805618D0;
        factor = factor < ratio ? factor : ratio;
        factor = factor > lbl_8056189C ? factor : lbl_8056189C;
        value = oldValue + factor * (oldTarget - oldValue);
    }
    arg0[1] = arg1;
    arg0[0] = value;
    arg0[2] = lbl_8055E318;
    {
        double target = arg1;
        double current = value;
        arg0[3] = lbl_8055E318 + (float)__fabs((float)current - (float)target) / arg0[4];
    }
}

void fn_80166F3C(float *arg0) {
    *arg0 = lbl_8055E318 + ((float (*)(int))fn_80129DC4)(3);
}

int fn_80166F78(float *arg0) {
    return lbl_8055E318 > *arg0;
}

extern double fn_8002EFB4(float, float, float);
extern float lbl_805618A0, lbl_805618F4, lbl_805618F8, lbl_805618FC;
#pragma push
#pragma optimization_level 2
#pragma scheduling on
float fn_80166F90(float *arg0) {
 float x, value, start, end;
 x = (float)fn_8002EFB4(lbl_8055E318 - arg0[3], lbl_805618A0 * arg0[2], lbl_805618A0);
 if (x > arg0[2]) x = lbl_805618A0 * arg0[2] - x;
 x /= arg0[2];
 value = lbl_805618F4;
 if (x < value) {} else {
 value = lbl_805618D0;
 if (x > value) {} else if (x > lbl_8056189C)
 value = x * (x * (lbl_805618F8 * x)) + x * (lbl_805618FC * x);
 else value = x * (x * (lbl_805618F8 * x)) - x * (lbl_805618FC * x);
 }
 end = arg0[1];
 start = arg0[0];
 return start + value * (end - start);
}

#pragma push
#pragma cplusplus on
extern int fn_801B8570(void);
extern void *fn_80166040(int);
extern float lbl_805618A0, lbl_805618DC, lbl_805618E0, lbl_805618E4;
extern "C" void fn_8016707C(void *arg0, void **arg1) {
    void *old;
    if (*(unsigned char *)((char *)arg0 + 4) != 0) return;
    fn_80179630(-1);
    if (fn_801B8570() == 0) {
        old = *(void **)((char *)arg0 + 0x58);
        if (old) *(int *)((char *)old + 0x10) = -1;
        *(void **)((char *)arg0 + 0x58) = 0;
        *(float *)((char *)arg0 + 0x1C) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618A0, lbl_805618E4);
        *(float *)((char *)arg0 + 0x20) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618DC, lbl_805618E0);
        return;
    }
    if (*(void **)((char *)arg0 + 0x58) != 0) return;
    if (((Dummy8016707C *)*arg1)->get() != 0) return;
    old = fn_80166040(*(int *)arg0);
    {
        void *current = *(void **)((char *)arg0 + 0x58);
        if (current) *(int *)((char *)current + 0x10) = -1;
    }
    *(void **)((char *)arg0 + 0x58) = old;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618A0, lbl_805618E4);
    *(float *)((char *)arg0 + 0x20) = lbl_8055E318 + ((float (*)(int, float, float))fn_80129DC4)(3, lbl_805618DC, lbl_805618E0);
}
#pragma cplusplus off
#pragma pop

#pragma pop
unsigned char fn_801671AC(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5C)); }

unsigned char fn_80167544(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5D)); }

unsigned char fn_80167594(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5E)); }

unsigned char fn_801675E4(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5F)); }

unsigned char fn_80167634(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x60)); }

extern float lbl_8055E324;

extern char lbl_8032FF8C[];
extern char lbl_8032FFC4[];
void fn_80167684(float arg0) {
    float temp_f31;
    if (!lbl_8055E32B && arg0 < *(float *)((char *)&lbl_8042FE38 + 0x5C)) {
        temp_f31 = (lbl_8055E324 - fn_801660C0()) / *(float *)((char *)&lbl_8042FE38 + 0x60);
        if (temp_f31 > arg0) {
            fn_802E30C8(lbl_8032FF8C);
            fn_802E30C8(lbl_8032FFC4, arg0, temp_f31);
            lbl_8055E32B = 1;
        }
    }
}

#pragma push
#pragma small_data off
unsigned char fn_80167758(void) { return *((unsigned char *)&lbl_8042FE38 + 0x4E); }
int fn_80167768(float arg0) { return arg0 > *(float *)((char *)&lbl_8042FE38 + 0x50); }
#pragma pop
extern float lbl_805618EC;
extern float lbl_805618D8;
extern float lbl_805618DC;
extern float lbl_805618E0;
extern float lbl_8055E318;

extern float fn_80129DC4(int, float, float, float);
extern void fn_80128670(void *);
extern void fn_80139E18(void);
extern unsigned char lbl_8055E32C;
extern unsigned char lbl_8055E334;
