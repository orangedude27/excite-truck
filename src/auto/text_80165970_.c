extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void fn_80165FAC(void);
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

#pragma push
#pragma dont_inline on
float fn_801659D0(int arg0) {
    float temp_f31;
    temp_f31 = fn_8013672C(arg0);
    return temp_f31 * (float)fn_800081F0(arg0);
}

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

void fn_801663C8(int count, void *records, void *config) {
    void *obj;
    void *holder;
    void *array;
    int i;
    float value;
    lbl_8055E324 = fn_801659D0((int)config);
    fn_80165FAC();
    obj = *(void **)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    value = (*(float (***)(void *, char *, float))obj)[10](obj, lbl_8032FCC0 + 0x270, *(float *)((char *)&lbl_8042FE38 + 0xC));
    *(float *)((char *)&lbl_8042FE38 + 0xC) = value;
    fn_802E30C8(lbl_8032FCC0 + 0x280, *(float *)((char *)&lbl_8042FE38 + 8), (float)value, *(float *)((char *)&lbl_8042FE38 + 4), *(float *)&lbl_8042FE38);
    holder = fn_801284F8(16, lbl_8032FCC0 + 0x2A0);
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
        int type = *(int *)((char *)records + i * 0x78);
        void *h = *(void **)&lbl_8055E32C;
        int index = *(int *)((char *)h + 4);
        char *p = *(char **)h + index * 0x88;
        *(int *)((char *)h + 4) = index + 1;
        *(int *)p = i;
        p[4] = type == 0x50;
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
#pragma pop
unsigned char fn_801671AC(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5C)); }

unsigned char fn_80167544(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5D)); }

unsigned char fn_80167594(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5E)); }

unsigned char fn_801675E4(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5F)); }

unsigned char fn_80167634(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x60)); }

extern float lbl_8055E324;
extern float fn_801660C0(void);

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
extern float lbl_80561898;
extern float lbl_805618D8;
extern float lbl_805618DC;
extern float lbl_805618E0;
extern float lbl_8055E318;

extern float fn_80129DC4(int, float, float, float);
extern void fn_80128670(void *);
extern void fn_80139E18(void);
extern unsigned char lbl_8055E32C;
extern unsigned char lbl_8055E334;
