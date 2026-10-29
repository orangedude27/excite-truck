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
    u16 *p;
    s32 i;

    if (fn_802ECC10() != 0) {
        return;
    }
    lbl_8055FF5C = fn_802E2C20();
    for (i = 0; i < 31; i++) {
        lbl_804FC418[i] = lbl_804FC418[i + 1];
    }
    lbl_804FC418[31] = arg0 & 0xFFF;

    p = &lbl_8055FF50;
    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            ((u16 *)&lbl_8055FF50)[i] = arg0;
            return;
        }
        p++;
    }
    p = &lbl_8055FF50;
    {
        u16 a = p[1];
        u16 b = p[2];
        u16 c = p[3];
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = arg0;
    }
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
    unsigned char *src = lbl_804FC3B0;
    if (lbl_8055FF58 != 0) {
        *(float *)(dst+0)=*(float *)(src+0); *(float *)(dst+4)=*(float *)(src+4);
        *(float *)(dst+8)=*(float *)(src+8); *(float *)(dst+12)=*(float *)(src+12);
        *(float *)(dst+16)=*(float *)(src+16); *(float *)(dst+20)=*(float *)(src+20);
        *(float *)(dst+24)=*(float *)(src+24); *(float *)(dst+28)=*(float *)(src+28);
        dst[32]=src[32]; dst[33]=src[33]; dst[34]=src[34]; dst[35]=src[35];
        dst[36]=src[36]; dst[37]=src[37]; dst[38]=src[38]; dst[39]=src[39];
        dst[40]=src[40]; dst[41]=src[41]; dst[42]=src[42]; dst[43]=src[43];
        dst[44]=src[44]; dst[45]=src[45]; dst[46]=src[46]; dst[47]=src[47];
        dst[48]=src[48]; dst[49]=src[49]; dst[50]=src[50]; dst[51]=src[51];
        dst[52]=src[52]; dst[53]=src[53]; dst[54]=src[54]; dst[55]=src[55];
        dst[56]=src[56]; dst[57]=src[57]; dst[58]=src[58]; dst[59]=src[59];
        dst[60]=src[60]; dst[61]=src[61]; dst[62]=src[62]; dst[63]=src[63];
        *(unsigned int *)(dst+64)=*(unsigned int *)(src+64);
        *(unsigned int *)(dst+68)=*(unsigned int *)(src+68);
        *(unsigned int *)(dst+72)=*(unsigned int *)(src+72);
        *(unsigned int *)(dst+76)=*(unsigned int *)(src+76);
        *(unsigned int *)(dst+80)=*(unsigned int *)(src+80);
        *(unsigned int *)(dst+84)=*(unsigned int *)(src+84);
        *(unsigned int *)(dst+88)=*(unsigned int *)(src+88);
        *(unsigned int *)(dst+92)=*(unsigned int *)(src+92);
        dst[96]=src[96];
        return 1;
    }
    return 0;
}

