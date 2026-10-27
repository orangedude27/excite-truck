// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern void *lbl_8055F618;
extern s32 lbl_8055F61C;
extern void fn_80128670(s32);
extern void *fn_8012850C(s32, const char *);
extern void fn_8027974C(void);
extern void fn_802795E8();
extern void fn_802E30C8(const char *, ...);
extern char lbl_80347818[];
extern char lbl_80347824[];
extern void *memset(void *, int, u32);
void fn_8027974C(void) {
    s32 offset;
    s32 i;
    offset = 0;
    i = 0;
    goto check;
loop:
    fn_802795E8((char *)lbl_8055F618 + offset + 4);
    offset += 0x2B8;
    i++;
check:
    if (i < lbl_8055F61C) goto loop;
}

void fn_802797A8(s32 *arg0, s32 arg1) {
    s32 offset;
    s32 i;
    char *entry;
    s32 value;

    lbl_8055F61C = arg1;
    lbl_8055F618 = fn_8012850C(arg1 * 0x2B8, lbl_80347818);
    i = 0;
    offset = 0;
    while (i < lbl_8055F61C) {
        entry = (char *)lbl_8055F618 + offset;
        memset(entry, 0, 0x2B8);
        value = *arg0;
        i++;
        offset += 0x2B8;
        arg0++;
        *(s32 *)entry = value;
    }
    fn_802795E8();
}

void fn_80279848(void) {
    fn_80128670((s32)lbl_8055F618);
    lbl_8055F618 = 0;
}

#pragma scheduling invalid_target
void *fn_80279874(s32 arg0) {
    char *entry;
    char *base;
    s32 count;
    s32 i;

    i = 0;
    count = lbl_8055F61C;
    base = (char *)lbl_8055F618;
    entry = base;
    for (; i < count; entry += 0x2B8, ++i) {
        if (arg0 == *(s32 *)entry)
            return base + i * 0x2B8;
    }
    fn_802E30C8(lbl_80347824, arg0);
    return 0;
}
#pragma scheduling reset
f32 fn_802798E8(void *arg0) {
    return *(f32 *)((char *)arg0 + 0x294);
}

extern f32 lbl_805640F0;
extern f32 lbl_805640F4;
extern f32 lbl_805640F0;
unsigned char fn_802798F0(u32 arg0, u32 arg1, f32 farg0) {
    s32 var_r0;
    s32 temp_r3;
    s32 temp_r4;
    f32 var_f0;
    if (((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0))) < lbl_805640F0) {
        var_f0 = ((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0))) - lbl_805640F4;
    } else {
        var_f0 = lbl_805640F4 + ((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0)));
    }
    var_r0 = 0xFF;
    temp_r4 = (s32)var_f0;
    temp_r3 = -temp_r4;
    temp_r3 &= ~temp_r4;
    temp_r3 >>= 31;
    temp_r3 = temp_r3 & temp_r4;
    if (temp_r3 < 0xFF) var_r0 = temp_r3;
    return (unsigned char)var_r0;
}

extern unsigned char fn_802798F0(unsigned int, unsigned int, float);
extern float lbl_80564100, lbl_80564104;
#pragma dont_inline on
void fn_802799EC(void *arg0, float amount) {
    unsigned char *p;
    unsigned char *base;
    int i;
    float end;
    float current;
    float remaining;
    float selected;
    float limit;
    register float factor;

    base = (unsigned char *)arg0 + 4;
    end = *(float *)((unsigned char *)arg0 + 0x294);
    current = *(float *)((unsigned char *)arg0 + 0x298);
    remaining = end - amount;
    selected = current;
    if (current > remaining) {
        selected = current;
    } else {
        selected = remaining;
    }
    if (end > lbl_80564100) {
        limit = lbl_80564100;
    } else {
        limit = end;
    }

    factor = lbl_80564104 - selected / limit;
    *(float *)(base + 0x290) = selected;
    *(int *)(base + 0x298) = 0;

    p = base;
    for (i = 0; i < 0xA4; ++i, p += 4) {
        p[0] = fn_802798F0(p[0], 0x80, factor);
        p[1] = fn_802798F0(p[1], 0x80, factor);
        p[2] = fn_802798F0(p[2], 0x80, factor);
        p[3] = fn_802798F0(p[3], 0, factor);
    }

    base[0x2A0] = 0;
    base[0x2A1] = 0;
    base[0x2A2] = 0;
    base[0x2A3] = 0;
    base[0x2A4] = 0;
    base[0x2A5] = 0;
    base[0x2A6] = 0;
    base[0x2A7] = 0;
    base[0x2A8] = 0;
    base[0x2A9] = 0;
    base[0x2AA] = 0;
    base[0x2AB] = 0;
    base[0x2AC] = 0;
    base[0x2AD] = 0;
    base[0x2AE] = 0;
    base[0x2AF] = 0;
    base[0x2B0] = 0;
    base[0x2B1] = 0;
}
void fn_80279B28(unsigned char *arg0, unsigned char *arg1) {
    unsigned char *target = arg1 - 1;
    unsigned char *source = arg0 + 3;
    int count = 0x148;

    do {
        unsigned char first = source[1];
        unsigned char second = *(source += 2);
        target[1] = first;
        *(target += 2) = second;
    } while (--count != 0);

    *(f32 *)(arg1 + 0x290) = *(f32 *)(arg0 + 0x294);
    *(f32 *)(arg1 + 0x294) = *(f32 *)(arg0 + 0x298);
    *(s32 *)(arg1 + 0x298) = *(s32 *)(arg0 + 0x29C);
    *(s32 *)(arg1 + 0x29C) = *(s32 *)(arg0 + 0x2A0);
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A4];
        unsigned char odd = p[0x2A5];
        arg1[0x2A0] = even;
        arg1[0x2A1] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A6];
        unsigned char odd = p[0x2A7];
        arg1[0x2A2] = even;
        arg1[0x2A3] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A8];
        unsigned char odd = p[0x2A9];
        arg1[0x2A4] = even;
        arg1[0x2A5] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AA];
        unsigned char odd = p[0x2AB];
        arg1[0x2A6] = even;
        arg1[0x2A7] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AC];
        unsigned char odd = p[0x2AD];
        arg1[0x2A8] = even;
        arg1[0x2A9] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AE];
        unsigned char odd = p[0x2AF];
        arg1[0x2AA] = even;
        arg1[0x2AB] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2B0];
        unsigned char odd = p[0x2B1];
        arg1[0x2AC] = even;
        arg1[0x2AD] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2B2];
        unsigned char odd = p[0x2B3];
        arg1[0x2AE] = even;
        arg1[0x2AF] = odd;
    }
    arg1[0x2B0] = arg0[0x2B4];
    arg1[0x2B1] = arg0[0x2B5];
}

void fn_80279C00(unsigned char *dst, unsigned char *src) {
    unsigned char *source = src - 1;
    unsigned char *target = dst + 3;
    int count = 0x148;

    do {
        unsigned char first;
        unsigned char second;
        first = source[1];
        second = *(source += 2);
        target[1] = first;
        *(target += 2) = second;
    } while (--count != 0);

    *(f32 *)(dst + 0x294) = *(f32 *)(src + 0x290);
    *(f32 *)(dst + 0x298) = *(f32 *)(src + 0x294);
    *(s32 *)(dst + 0x29C) = *(s32 *)(src + 0x298);
    *(s32 *)(dst + 0x2A0) = *(s32 *)(src + 0x29C);
    {
        unsigned char a, b;
        a = src[0x2A0]; b = src[0x2A1];
        dst[0x2A4] = a; dst[0x2A5] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2A2]; b = src[0x2A3];
        dst[0x2A6] = a; dst[0x2A7] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2A4]; b = src[0x2A5];
        dst[0x2A8] = a; dst[0x2A9] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2A6]; b = src[0x2A7];
        dst[0x2AA] = a; dst[0x2AB] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2A8]; b = src[0x2A9];
        dst[0x2AC] = a; dst[0x2AD] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2AA]; b = src[0x2AB];
        dst[0x2AE] = a; dst[0x2AF] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2AC]; b = src[0x2AD];
        dst[0x2B0] = a; dst[0x2B1] = b;
    }
    {
        unsigned char a, b;
        a = src[0x2AE]; b = src[0x2AF];
        dst[0x2B2] = a; dst[0x2B3] = b;
    }
    dst[0x2B4] = src[0x2B0];
    dst[0x2B5] = src[0x2B1];
}

void fn_80279CD8(void) { fn_802795E8(); }

