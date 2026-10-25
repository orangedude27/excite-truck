extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern void fn_80128670(int);
extern const char lbl_80347580[];
extern int fn_8012850C(int, const char *, int);
extern void *fn_8002F37C();
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

void fn_80278214(void) {
    lbl_8055F5B4 = 0;
    lbl_8055F5C8 = 0;
    lbl_8055F5BB = 0;
    lbl_8055F5BA = 0;
    lbl_8055F5B9 = 0;
    lbl_8055F5BC = -1;
    lbl_8055F5C4 = -1;
    lbl_8055F5B8 = 0;
    fn_8012850C(0x80, lbl_80347580, 0);
    lbl_8055F5B0 = (int)fn_8002F37C(fn_80278284, 0, 0x38, 2);
}

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
void fn_80278360(void *arg0) {
    int count;
    int *dst;
    int *src;
    if (lbl_8055F5B8 != 0 && lbl_8055F5B4 == 0) {
        if (lbl_8055E3C4 > 10) return;
        if (lbl_8055F5B8 == 0 || lbl_8055F5B4 >= 2) goto error;
        if (lbl_8055F5B4 == 0) {
            lbl_8055F5C9 = 1;
            fn_802E30C8(lbl_803475D8);
            return;
        }
        count = lbl_8055F5B4;
        if (lbl_8055E3C4 - *(int *)(lbl_8055F5B0 + (count - 1) * 0x38 + 0x34) < 2) return;
    }
    count = lbl_8055F5B4;
    dst = (int *)(lbl_8055F5B0 + count * 0x38);
    lbl_8055F5B4 = count + 1;
    *(int *)((char *)dst + 0x34) = lbl_8055E3C4;
    src = (int *)arg0;
    dst[0] = src[0x16]; dst[1] = src[0x17]; dst[2] = src[0x18]; dst[3] = src[0x19];
    dst[4] = src[0x1A]; dst[5] = src[0x1B]; dst[6] = src[0x1C]; dst[7] = src[0x1D];
    dst[8] = src[0x1E]; dst[9] = src[0x1F]; dst[10] = src[0x20]; dst[11] = src[0x21];
    dst[12] = src[0x22];
    *(float *)((char *)dst + 0x30) = *(float *)((char *)src + 0xBC);
    return;
error:
    if (lbl_8055F5C9 == 0) {
        lbl_8055F5C9 = 1;
        fn_802E30C8(lbl_803475D8);
    }
}

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
    do {
        char c = *arg0++;
        *dst++ = c;
        if (c == 0) {
            break;
        }
    } while (1);
    lbl_8055F5B9 = 1;
    lbl_8055F5BA = 0;
}

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
void fn_8027889C(float arg0) {
    float t;
    float result;
    t = arg0 / lbl_805640B8;
    result = t < lbl_805640A8 ? t - lbl_805640BC : lbl_805640BC + t;
    lbl_8055F5C0 = (int)result;
}

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
