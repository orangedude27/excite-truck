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
extern long lbl_8034E9B0;
extern long fn_800B7BDC(long);
extern char lbl_8055D278;
extern char lbl_8055D280;
extern long lbl_8034E260;
extern long jumptable_8034E2F8[];
extern int OSReport(const char *, ...);
extern char lbl_8034E370;
extern char lbl_80560061;
extern int lbl_80560068;
long *fn_802E9A3C(long arg0, long arg1) {
    lbl_80560060 = 1;
    if (lbl_80507600 != 0) {
        lbl_80507600[1] = arg0;
        lbl_80507600[0] = (long)&lbl_8034E9C8;
        lbl_80507600[3] = arg1;
    }
    return lbl_80507600;
}

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

extern char lbl_8034E3E0, lbl_8034E3F0, lbl_805076B8, lbl_80560061, lbl_8055D2A4;
void fn_802E9E54(unsigned char *arg0, unsigned char *arg1, int arg2) {
    unsigned char *dst = arg0, *src = arg1;
    int count = arg2;
    do {
        if (count <= 1) break;
        if ((signed char)*src == 0) break;
        if (*src < 0x80) {
            *dst++ = *src++;
            count--;
        } else {
            unsigned char ch = *++src;
            count--;
            *dst++ = 0x3F;
            if ((signed char)ch == 0) break;
            src++;
        }
    } while (1);
    *dst = 0;
}

void fn_802EA7E0(void) {
    lbl_8056007C = 0;
    if ((unsigned char)lbl_80560061 != 0) {
        fn_802EA5D4(lbl_8055D274, 0);
        if (lbl_8056007C == 0) fn_802EA5D4(&lbl_8055D2A4, 8);
    }
}

int fn_802EBE00(int arg0) {
    if (arg0 == 1) fn_802EBD40();
    return 0;
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
