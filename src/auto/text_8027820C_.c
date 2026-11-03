extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern float lbl_805640A0, lbl_805640A4, lbl_805640A8, lbl_805640AC;
extern void fn_8026E22C(float *, void *, void *, float);
extern void fn_801345D8(char *, int, const char *, ...);
extern void fn_802D08B4(int, int, int);
extern void fn_802D07E4(char *, int);
extern void fn_80128670(int);
extern const char lbl_80347580[];
extern int fn_8012850C(int, const char *, int);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern void fn_80278284(void);
extern char lbl_8055F5BA;
extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern int lbl_8055F5B4;
extern int lbl_8055F5BC;
extern int lbl_8055F5C0;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F5B8;
void fn_8027820C(void) {}

void fn_80278210(void) {}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80278214(void) {
    int zero;
    int minus;

    zero = 0;
    minus = -1;
    lbl_8055F5B4 = zero;
    lbl_8055F5C8 = zero;
    lbl_8055F5BB = zero;
    lbl_8055F5BA = zero;
    lbl_8055F5B9 = zero;
    lbl_8055F5BC = minus;
    lbl_8055F5C4 = minus;
    lbl_8055F5B8 = zero;
    lbl_8055F5B0 = (int)fn_8002F37C(
        (void *)fn_8012850C(0x80, lbl_80347580, zero),
        fn_80278284, zero, 0x38, 2);
}
#pragma scheduling on
#pragma pop
void fn_80278284(void) {}

void fn_80278288(void) {
    if (lbl_8055F5B0 != 0) fn_80128670(lbl_8055F5B0 - 0x10);
    lbl_8055F5B0 = 0; lbl_8055F5B4 = 0;
}

#pragma scheduling invalid_target
void fn_802782C4(void) {
    lbl_8055F5B8 = 1;
    lbl_8055F5B4 = 0;
    lbl_8055F5BA = 0;
    lbl_8055F5B9 = 0;
    fn_802E30C8(lbl_80347590, lbl_8055E3C4);
    lbl_8055F5BC = -1;
    lbl_8055F5C0 = -1;
}
#pragma scheduling on

#pragma scheduling invalid_target
void fn_80278318(void) {
    fn_802E30C8(lbl_803475B4, lbl_8055E3C4);
    lbl_8055F5B8 = 0;
    lbl_8055F5BA = 0;
    lbl_8055F5B9 = 0;
}
#pragma scheduling on
char fn_80278358(void) {
    return lbl_8055F5B8;
}

extern char lbl_8055F5C9;
extern const char lbl_803475D8[];
#pragma push
#pragma scheduling invalid_target
void fn_80278360(void *arg0) {
    register unsigned char state;
    int count;
    int *base;
    volatile int *dst;
    volatile int *src;
    int now;
    int age;
    int old;
    int first;
    int second;
    int value;
    int offset;
    float f;

    state = (unsigned char)lbl_8055F5B8;
    if (state == 0)
        goto record;
    count = lbl_8055F5B4;
    if (count != 0)
        goto record;
    now = lbl_8055E3C4;
    if (now > 10)
        return;
    if (state == 0)
        goto report_once;
    count = lbl_8055F5B4;
    if (count >= 2)
        goto report_once;
    if (count == 0)
        goto report_always;
    base = (int *)lbl_8055F5B0;
    old = *(int *)((char *)base + (count - 1) * 0x38 + 0x34);
    age = lbl_8055E3C4 - old;
    if (age < 2)
        return;

record:
    src = (volatile int *)arg0;
    count = *(volatile int *)&lbl_8055F5B4;
    base = (int *)*(volatile int *)&lbl_8055F5B0;
    offset = count * 0x38;
    now = *(volatile int *)&lbl_8055E3C4;
    first = src[0x16];
    second = src[0x17];
    *(volatile int *)&lbl_8055F5B4 = count + 1;
    dst = (volatile int *)((char *)base + offset);
    value = src[0x18];
    dst[13] = now;
    now = src[0x19];
    dst[0] = first;
    first = src[0x1A];
    dst[1] = second;
    second = src[0x1B];
    dst[2] = value;
    value = src[0x1C];
    dst[3] = now;
    now = src[0x1D];
    dst[4] = first;
    first = src[0x1E];
    dst[5] = second;
    second = src[0x1F];
    dst[6] = value;
    value = src[0x20];
    dst[7] = now;
    now = src[0x21];
    dst[8] = first;
    f = *(volatile float *)((char *)src + 0xBC);
    dst[9] = second;
    dst[10] = value;
    dst[11] = now;
    *(volatile float *)((char *)dst + 0x30) = f;
    return;

report_always:
    lbl_8055F5C9 = 1;
    fn_802E30C8(lbl_803475D8);
    return;
report_once:
    if (lbl_8055F5C9 == 0) {
        lbl_8055F5C9 = 1;
        fn_802E30C8(lbl_803475D8);
    }
}
#pragma pop
void fn_80278778(char *arg0) {
    int i;
    char *dst;
    if ((unsigned char)lbl_8055F5B8 != 0) {
        fn_802E30C8(lbl_80347660);
        return;
    }
    dst = lbl_804A15D0;
    for (i = 0x100; i > 0; i--) {
    }
    dst[-1] = 0;
    while (1) {
        char c = *arg0++;
        *dst++ = c;
        if (c == 0) break;
    }
    lbl_8055F5B9 = 1;
    lbl_8055F5BA = 0;
}
#pragma opt_propagation reset
extern char lbl_8055F5B9;
void fn_802787E4(void) {
    lbl_8055F5BA = 0;
    lbl_8055F5B9 = 0;
}

extern char lbl_8055F5BA;
char fn_802787F4(void) {
    return lbl_8055F5BA;
}

int fn_802787FC(void) {
    int result = 0;
    if ((unsigned char)lbl_8055F5BA != 0) goto done;
    if ((unsigned char)lbl_8055F5BB == 0) goto done;
    result = 1;
done:
    return result;
}

extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern char lbl_8055F5C8;
extern int lbl_8055F5C0;
extern int lbl_8055E3C4;
extern float lbl_805640A8;
extern float lbl_805640B8;
extern float lbl_805640BC;
void *fn_802678E4(int);

extern int lbl_8055F5BC;
extern float lbl_805640B0;
#pragma scheduling invalid_target
void fn_8027889C(float arg0) {
    float t;
    float result = 0.0f;
    t = arg0 / lbl_805640B8;
    if (t < lbl_805640A8) {
        result = t - lbl_805640BC;
    } else {
        result = lbl_805640BC + t;
    }
    lbl_8055F5C0 = (int)result;
}
#pragma scheduling on
int fn_80278924(float *arg0, float *arg1) {
    int result = 0;
    float scale = lbl_805640B8;
    *arg0 = scale * (float)lbl_8055F5C0;
    *arg1 = scale * (float)lbl_8055F5BC;
    if (lbl_8055F5C0 >= 0 && lbl_8055F5BC >= lbl_8055F5C0) result = 1;
    return result;
}

void fn_8027888C(char arg0) {
    lbl_8055F5C8 = arg0;
}

void fn_80278894(char arg0) {
    lbl_8055F5BB = arg0;
}
extern int lbl_8055F5B4;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern const char lbl_80347580[];
extern int fn_8012850C(int, const char *, int);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern void fn_80128670(int);
