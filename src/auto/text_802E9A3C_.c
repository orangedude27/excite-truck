extern void *lbl_80560078;
extern char lbl_80560060;
extern char lbl_8052E658[0x610];
extern int lbl_80560090;
extern char lbl_805600D0;
extern char lbl_805600D1;
extern float lbl_805651C4;
extern float lbl_8055D270;
extern int fn_802E622C(int, float);
extern int fn_802E61E4(int, float);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_805600C8;
extern void *lbl_80560080;
extern int fn_802EBD40(void);
extern long lbl_80507600[];
extern long lbl_8034E9C8;
__declspec(section ".rodata") extern long lbl_8034E9B0;
extern long fn_800B7BDC(long);
extern char lbl_8055D278;
extern char lbl_8055D280;
__declspec(section ".rodata") extern long lbl_8034E260;
extern long jumptable_8034E2F8[];
extern int OSReport(const char *, ...);
extern char lbl_8034E370;
extern char lbl_80560061;
extern int lbl_80560068;
extern int lbl_805600A0;
extern int lbl_805600A4;
extern int lbl_805600B8;
extern char lbl_80560062;
extern char lbl_80560063;
extern char lbl_8034E95C;
extern char lbl_8034E980;
extern int fn_802E2C20(void);
long *fn_802E9A3C(long arg0, long arg1) {
    lbl_80560060 = 1;
    if (lbl_80507600 != 0) {
        lbl_80507600[1] = arg0;
        lbl_80507600[0] = (long)&lbl_8034E9C8;
        lbl_80507600[3] = arg1;
    }
    return lbl_80507600;
}

extern char lbl_8055D258;
extern long fn_800B7C34(long, void *);
extern long fn_800B7C08(long, long *);
#pragma push
#pragma processor 750
long *fn_802E9A6C(long arg0) {
    extern long fn_802E30C8(char *, long);
    long info[8];
    long *p;
    lbl_80560060 = 1;
    p = lbl_80507600;
    if (p != 0) {
        p[0] = (long)&lbl_8034E9B0;
        p[1] = fn_800B7C34(arg0, &lbl_8055D258);
        p[2] = 0;
        if (p[1] != 0) {
            if (fn_800B7C08(p[1], info) == 0) p[2] = info[0];
            else {
                ((long (*)(char *, ...))fn_802E30C8)((char *)&lbl_8034E260, arg0);
                fn_800B7BDC(p[1]);
                p[1] = 0;
            }
        }
    }
    if (p[1] != 0) return p;
    if (p != 0) ((void (*)(long *, long))((long *)p[0])[2])(p, 1);
    return 0;
}
#pragma pop
void *fn_802E9B54(void *arg0, long arg1) {
    long *p = (long *)arg0;
    long value;
    if (p != 0) {
        value = p[1];
        p[0] = (long)&lbl_8034E9B0;
        if (value != 0) {
            fn_800B7BDC(value);
            p[1] = 0;
        }
        if (arg1 > 0) lbl_80560060 = 0;
    }
    return arg0;
}

void *fn_802E9BEC(long arg0) {
    long v = arg0 + 10;
    if ((unsigned long)v > 29) return 0;
    switch (v) {
    case 0: return &lbl_8055D278;
    case 1: return (char *)&lbl_8034E260 + 0x2c;
    case 2: return (char *)&lbl_8034E260 + 0x38;
    case 3: return (char *)&lbl_8034E260 + 0x44;
    case 4: return (char *)&lbl_8034E260 + 0x50;
    case 5: return (char *)&lbl_8034E260 + 0x5c;
    case 6: return (char *)&lbl_8034E260 + 0x6c;
    case 7: return (char *)&lbl_8034E260 + 0x7c;
    case 8: return (char *)&lbl_8034E260 + 0x88;
    case 9: return &lbl_8055D280;
    default: return 0;
    }
}

void fn_802E9C68(long arg0) {
    OSReport(&lbl_8034E370, arg0);
    lbl_80560061 = 1;
    lbl_80560068++;
}

extern char lbl_8034E390;
extern char lbl_8034E3E0;
extern char lbl_8034E3F0;
extern char lbl_805076B8;
extern int lbl_8056007C;
extern void *lbl_8055D274;
extern char lbl_8055D2A4;
extern int fn_800B7E5C(signed char, int);
extern int fn_800B7B34(signed char);
extern int fn_802EA5D4(void *, int);
void fn_802E9CAC(int arg0) {
    OSReport(&lbl_8034E390, arg0);
    lbl_80560061 = 0;
    lbl_80560068++;
}

extern long fn_800B7CE8(long, void *, void *);
extern long fn_800B7DB0(long, void (*)(long), void (*)(int));
extern long fn_800B7968(long, long, long, void *);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma optimization_level 2
void fn_802E9CF0(void) {
    char *strings = (char *)&lbl_8034E260;
    char *base = (char *)lbl_80507600;
    char *config = base + 0xC4;
    char *state;
    *(void *volatile *)(base + 0xC4) = base + 0xD8;
    *(void *volatile *)(config + 4) = base + 0x218;
    state = base + 0xB8;
    *(volatile short *)(config + 8) = 4;
    *(volatile short *)(config + 10) = 4;
    *(volatile long *)(config + 12) = 1;
    *(void *volatile *)(state + 4) = config;
    if (fn_800B7CE8(0x20000, state, config) != 0)
        fn_802E317C(strings + 0x14C);
    if (fn_800B7DB0(0, fn_802E9C68, fn_802E9CAC) != 0)
        fn_802E317C(strings + 0x15C);
    if (fn_800B7968(0, 0, 0, base + 0xB8) != 0)
        fn_802E317C(strings + 0x170);
    lbl_80560061 = ((unsigned char *)(base + 0xB8))[9] >> 4 & 1;
}
#pragma pop
extern char lbl_8034E3E0, lbl_8034E3F0, lbl_805076B8, lbl_80560061, lbl_8055D2A4;
void fn_802E9E54(unsigned char *arg0, unsigned char *arg1, int arg2) {
    unsigned char *dst = arg0;
    unsigned char *src = arg1;
    int count = arg2;
    for (;;) {
        if (count <= 1 || (signed char)*src == 0) { *dst = 0; return; }
        if (*src < 0x80) { *dst++ = *src++; count--; }
        else {
            unsigned char ch = *++src;
            count--;
            *dst++ = 0x3F;
            if ((signed char)ch != 0) src++;
        }
    }
}

void fn_802EA7E0(void) {
    lbl_8056007C = 0;
    if ((unsigned char)lbl_80560061 != 0) {
        fn_802EA5D4(lbl_8055D274, 0);
        if (lbl_8056007C == 0) fn_802EA5D4(&lbl_8055D2A4, 8);
    }
}

void fn_802EAA08(void) {
    if (lbl_805600B8 >= lbl_805600A4) {
        memmove((char *)&lbl_805600A0, (char *)&lbl_805600A0 + lbl_805600A4, lbl_805600B8 - lbl_805600A4);
        lbl_805600B8 -= lbl_805600A4;
    }
}

int fn_802EAA58(int *arg0, int arg1) {
    int sizeOk;
    int channelOk;
    int channels;
    int valid;
    int result;
    int rate;
    int size;
    if (arg1 != 0) {
        switch (arg0[1]) {
        case 11025: case 22050: case 44100: break;
        default: return 0;
        }
    }
    channels = arg0[2];
    result = 0;
    valid = 0;
    channelOk = 1;
    if (channels != 1 && channels != 2) channelOk = 0;
    if (channelOk) {
        int rateOk;
        rate = arg0[1];
        rateOk = 0;
        if (rate >= 8000 && rate <= 60000) rateOk = 1;
        if (rateOk) valid = 1;
    }
    if (valid) {
        size = arg0[4];
        sizeOk = 0;
        if (size != 0 && (unsigned int)size <= 0x1200) sizeOk = 1;
        if (sizeOk) result = 1;
    }
    return result;
}

int fn_802EBE00(int arg0) {
    if (arg0 == 1) fn_802EBD40();
    return 0;
}

extern int lbl_80560088, lbl_8056009C, lbl_805600A8;
extern void fn_802E61D8(int);
extern void fn_802E6138(int);
extern void fn_802E5FE4(int);
extern void fn_802E9EB8(void);
extern void fn_80127D58(void (*)(void));
extern void fn_802E9DDC(void);
extern void fn_80128670(int);
void fn_802EC038(void) {
    int *p30;
    int *p29;
    int i;
    p30 = &lbl_80560090;
    p29 = &lbl_80560088;
    i = 0;
    do {
        if (*p30 != 0) {
            fn_802E61D8(*p30);
            fn_802E6138(*p30);
        }
        *p30 = 0;
        fn_802E5FE4(*p29);
        i++;
        *p29 = 0;
        p30++;
        p29++;
    } while (i < 2);
    fn_80127D58(fn_802E9EB8);
    fn_802EBD40();
    fn_802E9DDC();
    fn_80128670(lbl_8056009C);
    lbl_8056009C = 0;
    fn_80128670(lbl_805600A0);
    lbl_805600A0 = 0;
    fn_80128670(lbl_805600A8);
    lbl_805600A8 = 0;
}

void* fn_802EC0FC(void) {
    return lbl_80560080;
}

char *fn_802EC104(int arg0) {
    return lbl_8052E658 + arg0 * 0x610 + 0x408;
}

void fn_802EC11C(void *arg0) {
    lbl_80560078 = arg0;
}

extern void *lbl_80560078;
void* fn_802EC124(void) {
    return lbl_80560078;
}

void fn_802EC12C(void) {
    lbl_80560078 = (void*)-1;
}

#pragma dont_inline fn_802EC138
void fn_802EC138(void) {
    if ((unsigned char)lbl_805600D0 == 0) {
        lbl_805600D1 = 1;
    }
    lbl_805600D0 = 1;
}

void fn_802EC158(void) {
    int *ptr;
    int i;

    lbl_805600D0 = 0;
    lbl_805600D1 = 0;
    ptr = &lbl_80560090;
    i = 0;
    do {
        fn_802E622C(*ptr, lbl_805651C4);
        fn_802E61E4(*ptr, lbl_805651C4);
        i++;
        ptr++;
    } while (i < 2);
}

void fn_802EC1C0(float arg0) {
    unsigned char flag = lbl_805600D0;
    lbl_8055D270 = arg0;
    if (flag == 0) {
        return;
    }
    fn_802EC138();
}
#pragma dont_inline reset
void fn_802EC1D8(void) {
    lbl_805600C8 = 1;
}

extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern char lbl_8034E990;
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
void fn_802EC294(long arg0, long arg1) {
    long spC = 0;
    long sp8 = 0;
    long temp_r3;
    long *temp_r31 = &lbl_805076A0[arg0 * 2];
    temp_r3 = fn_8012C370(arg1, 0x4D4D5033, &spC, &sp8, 0, 0);
    if (temp_r3 != 0) {
        temp_r31[0] = temp_r3;
        temp_r31[1] = sp8;
    } else {
        fn_802E30C8(&lbl_8034E990, arg1);
    }
}

void fn_802EC32C(long arg0, long arg1) {
    if (arg0 != 0 && arg1 > 0) {
        lbl_80560060 = 0;
    }
}

long fn_802EC348(void *arg0, long arg1) {
    if (arg1 < 0) {
        return 0;
    }
    if (arg1 >= ((long *)arg0)[3]) {
        return 0;
    }
    ((long *)arg0)[2] = arg1;
    return 1;
}

long fn_802EC370(void *arg0) {
    return ((long *)arg0)[3];
}

long fn_802EC3F0(void *arg0, long arg1, long arg2) {
    long value = ((long *)arg0)[1];
    return fn_800B7C60(arg1, arg2, 1, value) == 1;
}

long fn_802EC42C(void *arg0) {
    return fn_800B7C64(((long *)arg0)[1], 0) == 0;
}

long fn_802EC45C(void *arg0) { return ((long *)arg0)[2]; }

typedef signed long s32;
extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern char lbl_8034E990;
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_80560060;
