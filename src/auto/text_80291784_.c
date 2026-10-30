// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma cplusplus on
struct QueryObject_80292114 {
    virtual int f0(int *);
    virtual int f1(int *);
    virtual int f2(int *);
    virtual int f3(int *);
    virtual int f4(int *);
};
struct QueryObject_80291A1C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float f8(int *, float);
    virtual void f8_unused();
    virtual void f9_unused();
    virtual float f10(int *, float);
};
#pragma cplusplus reset

extern char lbl_804B4010[];
extern unsigned char lbl_8055F75C;
extern float fn_801EC114(void);
extern float fn_80291784(float, float, float, float);
extern void fn_80291B14(float *);
extern void fn_80291B9C(void *, float *, float);
extern void *fn_802C86DC(void);
__declspec(section ".data") extern int lbl_804B3EC0;
extern unsigned char lbl_8055C920;
extern int fn_802C2C00(int);
extern void fn_802D3BB0(int);
extern void fn_802920D0(void);
extern void fn_80291E64(void);
#pragma dont_inline on
extern float lbl_80564480;
extern float lbl_805644A0;
extern float lbl_80564484;
extern float lbl_80564490;
extern char lbl_80349158[];
extern int lbl_8055C938;
extern int lbl_8055C948;
extern void *fn_802AE414(int *);
extern int fn_802CAC28(int *, int);
extern int fn_802D39A4(float);
extern float fn_80129DC4(int, float, float);
extern char lbl_8055C924[];
extern char lbl_8055C930[];
extern char lbl_8055C940[];
extern char lbl_80349140[];
extern char lbl_8034914C[];
extern float lbl_80564488;
extern float lbl_8056448C;
extern float lbl_80564494;
extern float lbl_80564498;
extern float lbl_8056449C;
float fn_80291784(float a, float b, float c, float d) {
    int x, y;
    float value;
    int w;
    fn_802C98DC(&x, &y, &value, &w);
    return value - lbl_80564480;
}

int fn_802917C0(void *arg0, void *arg1, void *arg2) {
    typedef struct {
        float x;
        float y;
        float z;
        int id;
        int unk10;
        unsigned char flags;
        unsigned char pad[3];
        unsigned int color;
        float value1;
        float value2;
    } Entry;
    volatile int *count = (volatile int *)((unsigned char *)arg0 + 0x120);
    float best = lbl_80564484;
    float initial = best;
    float scale = lbl_8056449C;
    void *query_object;

    *count = 0;
    goto check_count;

loop:
    query_object = ((void *(*)(void *))(*(void **)((char *)*(void **)arg1 + 0x60)))(arg1);
    if (query_object != 0) {
        float result1 = fn_80129DC4(0, lbl_80564488, lbl_8056448C);
        float result2 = fn_80129DC4(0, lbl_80564490, lbl_80564494);
        float result3 = fn_80129DC4(0, lbl_80564498, lbl_80564494);
        float value = ((float (*)(void *, char *, float))(*(void **)((char *)*(void **)query_object + 0x28)))(query_object, lbl_8055C924, result2);
        int index = *count;
        Entry *entry = (Entry *)arg0 + index;
        entry->x = initial;
        entry->y = initial;
        entry->z = initial;
        {
            int *setting = ((int *(*)(void *, char *))(*(void **)((char *)*(void **)query_object + 0x14)))(query_object, lbl_8055C930);
            entry->id = fn_802CAC28(setting, 0);
        }
        entry->unk10 = 0;
        entry->flags = 0;
        entry->color = ((int)(scale * value) << 24) | 0x00FFFFFF;
        entry->value1 = ((float (*)(void *, char *, float))(*(void **)((char *)*(void **)query_object + 0x28)))(query_object, (char *)&lbl_8055C938, result1);
        entry->value2 = ((float (*)(void *, char *, float))(*(void **)((char *)*(void **)query_object + 0x28)))(query_object, lbl_8055C940, result3);
        if (best > entry->value1) best = entry->value1;
        *count = *count + 1;
    }

check_count:
    if (*count < 8) goto loop;
    *(float *)((unsigned char *)arg0 + 0x124) = ((float (*)(void *, char *))(*(void **)((char *)*(void **)arg1 + 0x24)))(arg1, lbl_80349140);
    *(float *)((unsigned char *)arg0 + 0x128) = ((float (*)(void *, char *))(*(void **)((char *)*(void **)arg1 + 0x24)))(arg1, lbl_8034914C);
    *(float *)((unsigned char *)arg0 + 0x12C) = best;
}

#pragma scheduling invalid_target
void fn_802919AC(void *arg0) {
    void *saved = arg0;
    void *cursor = saved;
    int i = 0;
    while (i < *((int *)((char *)saved + 0x120))) {
        fn_802CAC54(*((int *)((char *)cursor + 0xC)));
        *((int *)((char *)cursor + 0xC)) = -1;
        cursor = (char *)cursor + 0x24;
        i++;
    }
}
#pragma scheduling on
void fn_80291A1C(void) {
    /* Fix note: initialize settings using either the virtual query result or the default value. */
    struct QueryObject_80291A1C *obj;
    float value;
    int *settings;

    obj = (struct QueryObject_80291A1C *)fn_802AE414(&lbl_8055C948);
    if (obj != 0) {
        value = obj->f8(&lbl_8055C938, lbl_805644A0);
    } else {
        value = lbl_805644A0;
    }
    *(float *)&lbl_804B4010 = lbl_80564484;
    settings = (int *)&lbl_804B4010;
    ((float *)settings)[1] = lbl_80564484;
    ((float *)settings)[2] = lbl_80564484;
    settings[3] = fn_802CAC28((int *)&lbl_80349158, 0);
    fn_802CA294();
    settings[4] = fn_802D39A4(lbl_80564490);
    *((unsigned char *)settings + 0x14) = 0;
    settings[6] = -1;
    ((float *)settings)[7] = value;
}

void fn_80291AC8(void) {
    int *settings = (int *)&lbl_804B4010;
    fn_802CAC54(settings[3]);
    {
        int next = settings[4];
        settings[3] = -1;
        fn_802D3A50(next);
    }
    settings[4] = 0;
}
#pragma scheduling invalid_target
void fn_80291B14(float *arg0) {
    float value = arg0[0];
    int result;
    signed char success;
    fn_802C8E70((int *)lbl_804B4010);
    *((float *)(lbl_804B4010 + 8)) = value;
    result = fn_802C8FF4((int *)lbl_804B4010, *((float *)(lbl_804B4010 + 0x1C)));
    success = 0;
    if (result != 0 && fn_802D3A5C(*((int *)(lbl_804B4010 + 0x10)), (int *)lbl_804B4010) != 0) {
        success = 1;
    }
    *((unsigned char *)(lbl_804B4010 + 0x14)) = success;
}
#pragma scheduling on
void fn_80291B9C(void *arg0, float *arg1, float arg2) {
    float a = arg1[0];
    float b = arg1[1];
    float c = arg1[2];
    int i;
    char *entry;

    *((float *)((char *)arg0 + 0x130)) = a;
    *((float *)((char *)arg0 + 0x134)) = b;
    *((float *)((char *)arg0 + 0x138)) = c;
    fn_802C8E70(arg1, (char *)arg0 + 0x13C);
    *((float *)((char *)arg0 + 0x144)) = arg2;
    if (fn_802C8FF4((char *)arg0 + 0x13C, *((float *)((char *)arg0 + 0x12C)))) {
        *((unsigned char *)arg0 + 0x148) = *((int *)((char *)arg0 + 0x120)) != 0;
        entry = (char *)arg0;
        i = 0;
        do {
            *((unsigned char *)entry + 0x14) = 1;
            entry += 0x24;
            i++;
        } while (i < *((int *)((char *)arg0 + 0x120)));
    } else {
        *((unsigned char *)arg0 + 0x148) = 0;
        entry = (char *)arg0;
        i = 0;
        do {
            *((unsigned char *)entry + 0x14) = 0;
            entry += 0x24;
            i++;
        } while (i < *((int *)((char *)arg0 + 0x120)));
    }
}

extern double fabs(double);
extern double sin(double);
extern double cos(double);
extern double fn_8002EFB4(float, double);
extern void fn_802D3BB4(int, float *, float *, float *, unsigned int, float);
extern int lbl_8055CFF0;
extern float lbl_80564494, lbl_805644A4, lbl_805644A8, lbl_805644AC;
extern double lbl_805644B0;
extern float lbl_805644B8, lbl_805644BC;
void fn_80291C7C(void *arg0, int arg1) {
    float *p = (float *)arg0;
    float pos[3];
    float a[3], b[3];
    float ratio;
    float angle, s, c;
    unsigned int color;
    int amount;
    double d;

    pos[0] = p[0];
    pos[1] = p[1];
    pos[2] = p[2];
    pos[2] = lbl_80564484;

    d = (double)(p[0] - lbl_80564494 * (float)lbl_8055CFF0);
    d = fabs(d);
    ratio = ((float)d - lbl_805644A4 * (float)lbl_8055CFF0) /
        (lbl_80564494 * (float)lbl_8055CFF0 - lbl_805644A4 * (float)lbl_8055CFF0);
    if (ratio < 0.0f) {
        ratio = 0.0f;
    }
    if (ratio > 1.0f) {
        ratio = 1.0f;
    }

    color = *(unsigned int *)((char *)arg0 + 0x18);
    amount = (int)((lbl_80564480 + ratio * lbl_805644A8) * (float)(color >> 24));
    if (amount <= 0) {
        return;
    }
    color = (color & 0xFFFFFF) | (amount << 24);
    if (arg1 == 0) {
        angle = (float)fn_8002EFB4((p[0] - p[1]) / lbl_805644AC, lbl_805644B0);
        s = (float)sin(angle);
        c = (float)cos(angle);
        a[0] = c;
        a[1] = s;
        a[2] = 1.0f;
        b[0] = s;
        b[1] = -c;
        b[2] = 1.0f;
    } else {
        a[0] = lbl_805644B8;
        a[1] = lbl_805644BC;
        a[2] = 1.0f;
        b[0] = lbl_805644BC;
        b[1] = lbl_805644BC;
        b[2] = 1.0f;
    }
    fn_802D3BB4(*(int *)((char *)&lbl_804B4010 + 0x10), pos, a, b, color, p[7]);
}
#pragma scheduling on

#pragma dont_inline off
void fn_802920D0(void) {
    int *settings = (int *)&lbl_804B4010;
    fn_802C8C04(settings[3]);
    fn_80291C7C(settings, 1);
    fn_802C8D74();
}

extern void *fn_801E1F44(void);
extern void *fn_80131810(int *);
extern void fn_80131818(void *);
extern int fn_802917C0(void *, void *, void *);
extern void fn_80291A1C(void);
extern int lbl_80349164;
__declspec(section ".data") extern int lbl_80349164;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80292114(void) {
    void *state;
    void *object;
    int enabled;
    unsigned char active;
    state = fn_801E1F44();
    active = 0;
    enabled = 0;
    if (*((unsigned char *)state + 4) == 0 && *((int *)state) == 0)
        enabled = 1;
    if (enabled != 0)
        active = 1;
    lbl_8055F75C = active;
    if (active != 0) {
        object = fn_80131810(&lbl_80349164);
        if (object != 0) {
            if (((QueryObject_80292114 *)object)->f2(&lbl_8055C948) != 0) {
                int value = ((QueryObject_80292114 *)object)->f0(&lbl_8055C948);
                ((int (*)(void *, void *))fn_802917C0)(&lbl_804B3EC0, (void *)value);
            }
            fn_80131818(object);
        } else {
            int *p = (int *)((char *)&lbl_804B3EC0 + 0x120);
            *p = 0;
        }
        fn_80291A1C();
    }
}
#pragma scheduling on
#pragma cplusplus reset
void fn_802921F4(void) {
    if (lbl_8055F75C != 0) {
        fn_80291AC8();
        fn_802919AC((int *)&lbl_804B3EC0);
    }
}

void fn_8029222C(void) {
    register int *base;
    register char *p;
    register int count;
    register char zero;
    if (lbl_8055F75C == 0) return;
    p = (char *)&lbl_804B3EC0;
    base = (int *)p;
    count = 0;
    zero = 0;
    goto check;
loop:
    p[0x14] = zero;
    p += 0x24;
    count++;
check:
    if (count < base[0x48]) goto loop;
    *((char *)&lbl_804B4010 + 0x14) = 0;
}

void fn_8029227C(void) {
    int old; int *settings;
    if (!lbl_8055F75C) return;
    if (!lbl_8055C920) goto done;
    old=fn_802C2C00(0); settings=(int *)&lbl_804B4010;
    if (*((unsigned char *)settings+0x14)) fn_802D3BB0(settings[4]);
    if (*((unsigned char *)settings+0x14)) fn_802920D0();
    if (*((unsigned char *)&lbl_804B3EC0+0x148)) fn_80291E64();
    fn_802C2C00(old);
done: ;
}

#pragma scheduling invalid_target
void fn_8029231C(float *arg0) {
    /* Fix note: scale the vector, store the translated point, and forward the result. */
    float *base;
    register float dt;
    volatile float sp[3];
    register float temp_f1;
    register float temp_f2;
    register float temp_f3;
    register float temp_f4;

    if (lbl_8055F75C != 0) {
        dt = fn_801EC114();
        base = (float *)fn_802C86DC();
        temp_f4 = arg0[0] * dt;
        temp_f2 = arg0[1] * dt;
        temp_f3 = base[9];
        temp_f3 += temp_f4;
        temp_f1 = arg0[2] * dt;
        sp[0] = temp_f3;
        sp[1] = base[10] + temp_f2;
        sp[2] = base[11] + temp_f1;
        dt = fn_80291784(temp_f1, temp_f2, temp_f3, temp_f4);
        fn_80291B14((float *)sp);
        fn_80291B9C(&lbl_804B3EC0, (float *)sp, dt);
    }
}
#pragma scheduling on
void fn_802923C4(int arg0) {
    register unsigned int *p;
    register unsigned int old;
    register unsigned int value;
    if (lbl_8055F75C == 0) return;
    p = (unsigned int *)lbl_804B4010;
    old = p[6];
    value = (unsigned int)arg0 << 8;
    value >>= 8;
    p[6] = value | (old & 0xFF000000);
}

extern float lbl_8056449C;
extern double lbl_805644C8;
__declspec(section ".data") extern int lbl_804B3EC0;
void fn_802923EC(float arg0) {
    register float value;
    register int *settings;
    register int *table;
    register int *entry;
    register int i;
    register unsigned int packed;
    register int amount;

    if (lbl_8055F75C != 0) {
        value = lbl_80564480;
        if (value < arg0) value = arg0;
        if (value > lbl_80564484) value = lbl_80564484;
        settings = (int *)&lbl_804B4010;
        packed = settings[6];
        packed <<= 8;
        packed >>= 8;
        amount = (int)(lbl_8056449C * value);
        settings[6] = packed | (((unsigned int)amount & 0xFF) << 24);
        entry = (int *)&lbl_804B3EC0;
        table = entry;
        i = 0;
        goto check;
    loop:
        packed = entry[6];
        i++;
        entry[6] = ((unsigned int)(int)(value * (float)(packed >> 24)) << 24) |
                   (packed & 0xFFFFFF);
        entry = (int *)((char *)entry + 0x24);
    check:
        if (i < table[0x48]) goto loop;
    }
}

