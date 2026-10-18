// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804B4010;
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
extern int lbl_80349158;
extern int lbl_8055C938;
extern int lbl_8055C948;
extern void *fn_802AE414(int *);
extern int fn_802CAC28(int *, int);
extern int fn_802D39A4(float);
float fn_80291784(float a, float b, float c, float d) {
    int x, y;
    float value;
    int w;
    fn_802C98DC(&x, &y, &value, &w);
    return value - lbl_80564480;
}

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

void fn_80291A1C(void) {
    float value = lbl_805644A0;
    void **obj = (void **)fn_802AE414(&lbl_8055C948);
    int *settings = (int *)&lbl_804B4010;
    if (obj != 0) {
        value = ((float (*)(void *, float))(*(void **)((char *)*obj + 0x28)))(&lbl_8055C938, lbl_805644A0);
    }
    ((float *)settings)[0] = lbl_80564484;
    ((float *)settings)[1] = lbl_80564484;
    ((float *)settings)[2] = lbl_80564484;
    settings[3] = fn_802CAC28(&lbl_80349158, 0);
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
#pragma dont_inline off
void fn_80291B14(float *arg0) {
    float value = arg0[0];
    int result;
    int *settings = (int *)&lbl_804B4010;
    fn_802C8E70(settings);
    *((float *)settings + 2) = value;
    result = fn_802C8FF4(settings, *((float *)settings + 7));
    if (result != 0 && fn_802D3A5C(settings[4], settings) != 0) {
        *((unsigned char *)settings + 0x14) = 1;
    } else {
        *((unsigned char *)settings + 0x14) = 0;
    }
}

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
void fn_80292114(void) {
    void *state;
    void *object;
    int enabled;
    unsigned char active;
    void **vtable;
    int (*query)(void *, int *);
    int (*get)(void *, int *);
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
            vtable = *(void ***)object;
            query = (int (*)(void *, int *))vtable[4];
            if (query(object, &lbl_8055C948) != 0) {
                vtable = *(void ***)object;
                get = (int (*)(void *, int *))vtable[2];
                fn_802917C0(&lbl_804B3EC0, (void *)get(object, &lbl_8055C948), &lbl_804B3EC0);
            }
            fn_80131818(object);
        } else {
            *((int *)((char *)&lbl_804B3EC0 + 0x120)) = 0;
        }
        fn_80291A1C();
    }
}

void fn_802921F4(void) {
    if (lbl_8055F75C != 0) {
        fn_80291AC8();
        fn_802919AC((int *)&lbl_804B3EC0);
    }
}

void fn_8029222C(void) {
    int i;
    char *p;
    if (lbl_8055F75C == 0) return;
    p = (char *)&lbl_804B3EC0;
    for (i = 0; i < *((int *)&lbl_804B3EC0 + 0x48); i++, p += 0x24)
        p[0x14] = 0;
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

void fn_8029231C(float *arg0) {
    float sp[3]; float dt; float result; float *base;
    if (!lbl_8055F75C) return;
    dt = fn_801EC114(); base = (float *)fn_802C86DC();
    sp[0] = base[9] + arg0[0] * dt; sp[1] = base[10] + arg0[1] * dt; sp[2] = base[11] + arg0[2] * dt;
    result = fn_80291784(arg0[2] * dt, arg0[1] * dt, sp[0], arg0[0] * dt);
    fn_80291B14(sp); fn_80291B9C(&lbl_804B3EC0, sp, result);
}

void fn_802923C4(int arg0) {
    int *p;
    if (lbl_8055F75C == 0) return;
    p = (int *)&lbl_804B4010;
    p[6] = (arg0 & 0xFFFFFF) | (p[6] & 0xFF000000);
}

extern float lbl_8056449C;
extern double lbl_805644C8;
__declspec(section ".data") extern int lbl_804B4010;
__declspec(section ".data") extern int lbl_804B3EC0;
void fn_802923EC(float arg0) {
    float value;
    int i;
    int *base;
    int *entry;
    unsigned int packed;
    if (lbl_8055F75C != 0) {
        value = lbl_80564480;
        if (value < arg0) value = arg0;
        if (value > lbl_80564484) value = lbl_80564484;
        base = &lbl_804B4010;
        base[6] = (base[6] & 0xFFFFFF) | ((int)(lbl_8056449C * value) << 24);
        entry = &lbl_804B3EC0;
        i = 0;
        do {
            packed = entry[6];
            entry[6] = ((unsigned int)(int)(value * (float)(packed >> 24)) << 24) | (packed & 0xFFFFFF);
            entry = (int *)((char *)entry + 0x24);
            i++;
        } while (i < base[0x48]);
    }
}

