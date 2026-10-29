#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D1C0;
extern u16 lbl_8055FF50;
void fn_802E4A2C(void);
extern s32 lbl_8055FF5C;
extern u16 lbl_8055FF5A;
extern u16 lbl_804FC418[];
extern s32 fn_802ECC10(void);
extern s32 fn_802E2C20(void);
extern void fn_802E47E8(void);
#pragma dont_inline on
void fn_802E46AC(void) {}
#pragma dont_inline off

#pragma dont_inline on
#pragma dont_inline off
void fn_802E46B0(void) {
    lbl_8055FF5C = 0;
    fn_802E47E8();
    lbl_8055D1C0 = (void *)-1;
    fn_802E46AC();
}
void fn_802E46E4(void) {
    lbl_8055D1C0 = (void*)-1;
}

extern int sprintf(char *, const char *, ...);
extern void fn_802D07E4(char *, s32);
extern u16 lbl_8055FF60;
extern u32 lbl_8055FF64;
extern const char lbl_8034D1C0[];
#pragma scheduling invalid_target
s32 fn_802E46F0(void) {
    u16 raw;
    u32 mask;
    u32 mode;
    char buffer[0x20];
    volatile u16 *p;
    u16 a, b, c;

    fn_802E4A2C();
    raw = lbl_8055FF50;
    mask = (u32)raw & 0xFFFF0FFF;
    lbl_8055FF5A = raw;
    if (mask != 0) {
        p = &lbl_8055FF50;
        a = p[1];
        b = p[2];
        c = p[3];
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = 0;
    }
    mode = (u16)mask;
    if (mode == 0x17A)
        goto special;
    if (mode != 0x17B || lbl_8055FF60 != 0x112)
        goto done;
special:
    sprintf(buffer, lbl_8034D1C0, lbl_8055FF64);
    fn_802D07E4(buffer, mode == 0x17B);
    mode = 0;
    lbl_8055FF64++;
done:
    if (mode != 0)
        lbl_8055FF60 = mode;
    return mode;
}
void* memset(void*, int, unsigned long);
extern u16 lbl_8055FF50;
void fn_802E4A2C(void); /* extern */
s32 fn_802E47B8(void) {
    fn_802E4A2C();
    return lbl_8055FF50 != 0;
}

void fn_802E47E8(void) {
    memset(&lbl_8055FF50, 0, 8);
}

s32 fn_802E47F8(void) {
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_802E4800(u16 arg0) {
    u16 *history;
    volatile u16 *p;
    s32 i;
    u16 a, b, c;

    if (fn_802ECC10() != 0) {
        return;
    }
    lbl_8055FF5C = fn_802E2C20();
    history = lbl_804FC418;
    p = &lbl_8055FF50;
    for (i = 0; i < 31; i++) {
        history[i] = history[i + 1];
    }
    history[31] = arg0 & 0xFFF;

    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            ((volatile u16 *)&lbl_8055FF50)[i] = arg0;
            return;
        }
        p++;
    }
    p = &lbl_8055FF50;
    a = p[1];
    b = p[2];
    c = p[3];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = arg0;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
s32 fn_802E499C(u16 *str) {
    s32 len;
    u16 *p;
    u16 *q;
    u16 a;
    u16 b;
    len = 0;
    p = str;
    while (*p != 0) { len++; p++; }
    q = lbl_804FC418 + (0x20 - len);
    while (len > 0) {
        a = *str;
        b = *q;
        if (b != a && a != 0xFFFF) return 0;
        str++;
        q++;
        len--;
    }
    return 1;
}
#pragma pop
s32 fn_802E4A10(void) { return (lbl_8055FF5A >> 12) & 0xF; }

extern u8 lbl_804FC458[];
u8 fn_802E4A1C(s32 arg0) { return lbl_804FC458[arg0]; }

void fn_802E4A2C(void) {
    volatile u32 stack[64];
    volatile u32 *p;
    if ((s32)lbl_8055D1C0 < 0) return;
    p = &stack[0];
    do {
        *p = 0;
        p[1] = 0;
        p += 2;
    } while (p < &stack[64]);
}

extern unsigned char lbl_8055FF58;
extern unsigned char lbl_804FC3B0[];
int fn_802E4A60(void *arg0) {
    unsigned char *dst = (unsigned char *)arg0;
    if (lbl_8055FF58 != 0) {
        volatile unsigned char *src = lbl_804FC3B0;
        unsigned char a, b;
        unsigned int wordA, wordB;

        *(float *)(dst + 0x00) = *(float *)(src + 0x00);
        *(float *)(dst + 0x04) = *(float *)(src + 0x04);
        *(float *)(dst + 0x08) = *(float *)(src + 0x08);
        *(float *)(dst + 0x0C) = *(float *)(src + 0x0C);
        *(float *)(dst + 0x10) = *(float *)(src + 0x10);
        *(float *)(dst + 0x14) = *(float *)(src + 0x14);
        *(float *)(dst + 0x18) = *(float *)(src + 0x18);
        *(float *)(dst + 0x1C) = *(float *)(src + 0x1C);
#define COPY_PAIR(o) b = src[(o)]; a = src[(o) + 1]; dst[(o)] = b; dst[(o) + 1] = a
        COPY_PAIR(0x20);
        COPY_PAIR(0x22);
        COPY_PAIR(0x24);
        COPY_PAIR(0x26);
        COPY_PAIR(0x28);
        COPY_PAIR(0x2A);
        COPY_PAIR(0x2C);
        COPY_PAIR(0x2E);
        COPY_PAIR(0x30);
        COPY_PAIR(0x32);
        COPY_PAIR(0x34);
        COPY_PAIR(0x36);
        COPY_PAIR(0x38);
        COPY_PAIR(0x3A);
        COPY_PAIR(0x3C);
        COPY_PAIR(0x3E);
#undef COPY_PAIR
        *(unsigned int *)(dst + 0x40) = *(unsigned int *)(src + 0x40);
        wordB = *(volatile unsigned int *)(src + 0x44);
        wordA = *(volatile unsigned int *)(src + 0x48);
        *(unsigned int *)(dst + 0x44) = wordB;
        *(unsigned int *)(dst + 0x48) = wordA;
        wordA = *(volatile unsigned int *)(src + 0x4C);
        wordB = *(volatile unsigned int *)(src + 0x50);
        *(unsigned int *)(dst + 0x4C) = wordA;
        *(unsigned int *)(dst + 0x50) = wordB;
        wordA = *(volatile unsigned int *)(src + 0x54);
        wordB = *(volatile unsigned int *)(src + 0x58);
        *(unsigned int *)(dst + 0x54) = wordA;
        *(unsigned int *)(dst + 0x58) = wordB;
        *(unsigned int *)(dst + 0x5C) = *(unsigned int *)(src + 0x5C);
        dst[0x60] = src[0x60];
        return 1;
    }
    return 0;
}

