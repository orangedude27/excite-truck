// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <macros.h>
extern void fn_802E317C(const char *, ...);
extern char lbl_8034B538[];
extern int lbl_8055D038;
extern int lbl_8055D040;
extern int fn_8012850C(int, int *);
extern void fn_802CB424(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802D92B8(int);
extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);

#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
DECL_SECTION(".sdata") extern int lbl_8055FCB4;
DECL_SECTION(".sdata") extern int lbl_8055FCB8;
void fn_802D8FB4(void);
void fn_802D9160(int, int);
void fn_802DBDE8(int, int);
#pragma small_data off
#pragma pop

extern char lbl_8055D07D;
extern float lbl_80564F30;
void fn_802CA1E0(void) {
    int i;
    int offset;
    if (lbl_8055D03C != -1) {
        fn_802CAC54(lbl_8055D03C);
        lbl_8055D03C = -1;
    }
    fn_802CAC54(lbl_8055FCB4);
    lbl_8055FCB4 = -1;
    i = 0;
    offset = 0;
    do {
        if (*(int *)(lbl_8055FCB0 + offset) != 0)
            fn_802E317C(lbl_8034B5F0, i, lbl_8055FCB0 + offset + 4);
        i++;
        offset += 0x4C;
    } while (i < 0x200);
    fn_802CB6B4();
    fn_80128670(lbl_8055FCB0);
    lbl_8055FCB0 = 0;
}

int fn_802CA294(int arg0) {
    int offset = arg0 * 0x4C;
    int *base = (int *)lbl_8055FCB0;
    return *(int *)((char *)base + offset + 0x28);
}

extern char *fn_80029004(char *, int);
extern char lbl_8055D048;
int fn_802CA2A8(void *arg0, int arg1, int arg2) {
    char *dst = (char *)arg0;
    const char *src = (const char *)arg2;
    int remaining = arg1;
    char *p = dst;
    do {
        char c = *src++;
        *p++ = c;
        if ((signed char)c == 0) break;
        remaining--;
        if (remaining <= 0) {
            p[-1] = 0;
            break;
        }
    } while (1);
    *fn_80029004(dst, '.') = 0;
    p = dst;
    while ((signed char)*p != 0) {
        remaining--;
        p++;
    }
    if (remaining > 0) {
        const char *suffix = &lbl_8055D048;
        do {
            char c = *suffix++;
            *p++ = c;
            if ((signed char)c == 0) break;
            remaining--;
            if (remaining <= 0) {
                p[-1] = 0;
                break;
            }
        } while (1);
    }
    return (int)dst;
}

int fn_802CA380(int arg0) {
    char sp10[0x20];
    int sp8;
    int result;
    int temp;
    result = 0;
    fn_802CA2A8(sp10, 0x20, arg0);
    temp = fn_8012C5B8(sp10, 0x54455820, &sp8);
    if (temp != 0) {
        result = fn_8012C6F0();
        fn_8012C958(temp);
    }
    return result;
}

int fn_802CA3F4(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    unsigned char *src = (unsigned char *)arg1;
    int *dst = (int *)arg0;
    unsigned char c12, c7, c6, c11, c5, c4, c10;
    unsigned short h12, h0, h2;
    int ptr14;
    memset(arg0, 0, 0x34);
    c5 = src[5];
    c12 = src[0xB];
    c4 = src[4];
    c7 = src[7];
    c6 = src[6];
    h12 = *(unsigned short *)(src + 0xC);
    c10 = src[0xA];
    h0 = *(unsigned short *)src;
    h2 = *(unsigned short *)(src + 2);
    ptr14 = *(int *)(src + 0x14);
    dst[2] = c12 & 1;
    dst[0] = c5 & 0x7F;
    dst[5] = c7;
    dst[4] = c6;
    dst[3] = h12;
    dst[6] = c12;
    *(unsigned char *)((char *)arg0 + 0x1C) = c10;
    dst[1] = arg2;
    dst[8] = (signed char)c4;
    dst[9] = h0;
    dst[10] = h2;
    dst[11] = ptr14;
    dst[12] = arg3;
    if (arg4 == 2)
        dst[2] = (c12 & 1) | 1;
    else if (arg4 == 6)
        dst[2] = (c12 & 1) | 2;
    else if (arg4 == 5)
        dst[2] = (c12 & 1) | 4;
}

extern int fn_8012C370(const char *, int *, int *, signed char *, unsigned char *);
extern char lbl_8034B634[];
extern char lbl_8034B658[];
int fn_802CA658(int arg0, int arg1) {
    int sp10;
    int spC;
    signed char sp9 = 0;
    unsigned char sp8 = 0;
    int result;
    result = fn_8012C370("TEX ", &sp10, &spC, &sp9, &sp8);
    if (result != 0) {
        if ((result & 0x7F) != 0)
            fn_802E317C(lbl_8034B634, arg0, result);
        if (sp10 != 0xF)
            fn_802E317C(lbl_8034B658, arg0);
        if (sp8 != 0)
            fn_802CA57C(result, arg0, 0);
    }
    return result;
}

char fn_802CA7D4(void) { return 1; }

char fn_802CA7DC(const char *arg0) { return (signed char)*arg0 == 0x2A; }

int fn_802CA7F4(const char *arg0) { return strchr(arg0, 0x2F) != 0; }

void fn_802CAC28(int arg0, int arg1) {
    fn_802CA898(arg0, arg1, 0, 0xE);
}

void fn_802CAC34(int arg0, int arg1) {
    fn_802CA898(arg0, 0, arg1, 0xE);
}

void fn_802CAC44(int arg0, int arg1) {
    fn_802CA898(arg0, 0, 0, arg1);
}

void fn_802CAD28(int arg0) {
    int *p;
    int value;
    if (arg0 == -1)
        return;
    p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    value = --p[0];
    if (value != 0)
        return;
    if (p[0x2C / 4] == 0)
        return;
    p[0x2C / 4] = 0;
    ((void (*)(int))fn_802D8FB4)(p[0x28 / 4]);
}

void fn_802CAD68(void) {
    lbl_8055FCB8 = -2;
}

#pragma dont_inline fn_802CAD74
void fn_802CAD74(int arg0) {
    int *p;
    int value;
    if (arg0 == lbl_8055FCB8)
        return;
    if (arg0 == -1) {
        lbl_8055FCB8 = arg0;
        return;
    }
    lbl_8055FCB8 = arg0;
    p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    p[0x48 / 4]++;
    value = p[0x40 / 4];
    if (value != 0)
        fn_802D9160(value, 0);
    else
        fn_802D9160(p[0x28 / 4], 0);
}
void fn_802CADD0(int arg0, int arg1) {
    if (arg0 == -1) {
        fn_802DBDE8(arg1, 0);
    } else {
        fn_802DBDE8(arg1, *(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x28));
    }
}

int fn_802CAE00(int arg0) {
    int value = 0;
    if (arg0 >= 0 && arg0 < 0x200 &&
        *(int *)(lbl_8055FCB0 + arg0 * 0x4C) > 0) {
        value = 1;
    }
    return value;
}

extern int fn_802C90E0(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802CA3F4(void *, int, int, int, int);
extern int fn_802D8E9C(void *, unsigned int);
extern char lbl_8034B618[];
extern char lbl_8034B538[];
extern void *jumptable_8034B794[];
extern int fn_802CAE00(int);
extern int lbl_8055FCB0;
extern char lbl_8034B904[];
extern char lbl_8034B914[];
char *fn_802CAE34(int arg0) {
    int offset;
    char *result;
    if (arg0 == -1)
        return lbl_8034B904;
    if (!((int (*)(int))fn_802CAE00)(arg0))
        return lbl_8034B914;
    offset = arg0 * 0x4C;
    result = (char *)lbl_8055FCB0 + offset;
    return result + 4;
}
#pragma dont_inline on
void fn_802CAE98(int arg0, char *arg1) {
    char *dst;
    int count;
    if (!((int (*)(int))fn_802CAE00)(arg0))
        return;
    dst = (char *)lbl_8055FCB0 + arg0 * 0x4C + 4;
    count = 0x20;
    do {
        count--;
        if (count <= 0) {
            dst[-1] = 0;
            break;
        }
        *dst = *arg1;
        if ((signed char)*arg1++ == 0)
            break;
        dst++;
    } while (1);
}

void fn_802CAF1C(int arg0, signed char arg1, signed char arg2) {
    int offset;
    int ptr;
    if (fn_802CAE00(arg0)) {
        offset = arg0 * 0x4C;
        ptr = *(int *)(lbl_8055FCB0 + offset + 0x2C);
        *(signed char *)(ptr + 8) = arg1;
        ptr = *(int *)(lbl_8055FCB0 + offset + 0x2C);
        *(signed char *)(ptr + 9) = arg2;
    }
}

#pragma dont_inline reset
int fn_802DB2C0(int);
int fn_802CA57C(int, int, int);
int fn_802CA4E0(int, int, int, int, int);
int fn_802CA898(int, int, int, int);
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
void fn_802D8FB4(void);
extern int lbl_8055D058;
extern int lbl_8055D078;
void fn_802CB38C(int arg0, int arg1, int arg2) {
    fn_802CA57C(lbl_8055D078, 0, arg2);
    fn_802CA4E0(arg0, lbl_8055D058, 0, arg1, arg0);
}

void fn_802CB3F4(void) {
    fn_802D8FB4();
}

void fn_802CB3F8(void) {
}

extern char lbl_8055FCBC[];
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
extern float lbl_80564F40;
extern float lbl_80564F44;
extern float lbl_8055FCC4;
  extern unsigned short lbl_8055FCA8;
int fn_802CAF8C(int arg0) {
    if (arg0 == -1)
        return 0;
    return *(unsigned short *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 0xC) != lbl_8055FCA8;
}
void fn_802CC550(int, float, float);
int fn_802CB274(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C0(p[0x28 / 4]);
}

int fn_802DB2C4(int);
int fn_802CB288(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C4(p[0x28 / 4]);
}

char fn_802CAFC8(int arg0) {
    if (arg0 == -1)
        return 5;
    return *(char *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 8);
}

char fn_802CAFF0(int arg0) {
    if (arg0 == -1)
        return 0x32;
    return *(char *)(*(int *)(lbl_8055FCB0 + arg0 * 0x4C + 0x2C) + 9);
}

unsigned short fn_802CB3FC(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    unsigned short *q = (unsigned short *)p[0x2C / 4];
    if ((int)q[1] > (int)q[0])
        return q[1];
    return q[0];
}

void fn_802CBB9C(int **arg0, int arg1, int *arg2) {
    fn_802CBBE8(arg1, arg2);
    *(int **)((char *)arg2 + 0x14) = *arg0;
    *arg0 = arg2;
}

void fn_802CBD7C(void **, void *);
extern char lbl_8034BA04[];
void fn_802CBD7C(void **arg0, void *arg1) {
    int removed = 0;
    for (;;) {
        void *node = *arg0;
        if (node == 0) {
            if (removed)
                return;
            fn_802E317C(lbl_8034BA04);
            return;
        }
        if (node == arg1) {
            removed = 1;
            *arg0 = *(void **)((char *)arg1 + 0x10);
            *(void **)((char *)arg1 + 0x10) = 0;
            if (*arg0 == 0) {
                if (removed)
                    return;
                fn_802E317C(lbl_8034BA04);
                return;
            }
        } else {
            arg0 = (void **)((char *)node + 0x10);
        }
    }
}

extern char lbl_8034BA34[];
extern char lbl_8034BA70[];
int fn_802D9154(void);
void fn_802CC03C(int **arg0, int *arg1, int arg2) {
    char sp10[0x20];
    int sp8;
    fn_802CA2A8(sp10, 0x20, lbl_8055FCB0 + arg2 * 0x4C + 4);
    arg1[0] = fn_8012C5B8(sp10, 0x54455820, &sp8);
    arg1[1] = arg2;
    arg1[3] = fn_802D9154();
    if (arg1[0] == 0)
        fn_802E317C(lbl_8034BA34, sp10);
    if (sp8 != 0xF)
        fn_802E317C(lbl_8034BA70, sp10, 0xF);
    ((void (*)(int **, int, int *))fn_802CBB9C)(arg0, (int)arg0 + 4, arg1);
}

int fn_802CC404(void *arg0) {
    return *(int *)(*(char **)((char *)arg0 + 0x38) + 4);
}

void fn_802CC518(int arg0, float arg1) {
    lbl_8055FCC4 = (lbl_80564F30 * arg1) / (float)arg0;
}

void fn_802CC73C(char arg0) {
    lbl_8055D07D = arg0;
}

char fn_802CC744(void) {
    return lbl_8055D07D;
}

int fn_802CC74C(void) {
    char *p = *(char **)lbl_8055FCBC;
    if (p == 0)
        return 0;
    if (*(int *)(p + 4) == 0)
        return 0;
    return 1;
}

extern void fn_802E317C(const char *, ...);
extern char lbl_8034B7D0[];
extern char fn_802CA7DC(const char *);
extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);
extern char lbl_8034B538[];
extern char lbl_8034B904[];
extern char lbl_8034B914[];
extern int fn_802CAE00(int);
extern char lbl_8034B538[];
