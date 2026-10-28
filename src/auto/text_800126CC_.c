#include "decomp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E317C(void *, ...);
extern char lbl_802FC638[];
extern char lbl_802FC69C[];
extern char lbl_80352AD0[];
extern char lbl_802FC610[];
extern int lbl_8055D51C;
extern int lbl_8055D50C;
extern int lbl_8055D510;
extern int lbl_8055D514;
extern int lbl_80558AD8;
extern int lbl_8055D508;
extern void *lbl_8055D504;
extern int lbl_8055D518;
extern char lbl_8055D500;
extern char lbl_803518C0[];
extern void fn_80013A34(void);
extern void fn_80013618(int);
extern void fn_8013C804(void);
extern void fn_8013C8B8(void);
extern int fn_8019B3C(void);
extern int fn_8019B54(void);
extern void fn_80013724(void);
extern int fn_80007F90(int);
extern int fn_801345D8(void *, int, const char *, ...);
void fn_80012984();
#pragma scheduling invalid_target
void *fn_800126CC(int arg0) {
    volatile int *table = (volatile int *)lbl_802FC638;
    int i = 0;
    if (arg0 != table[0]) {
        i = 1;
        if (arg0 != table[5]) {
            i = 2;
            if (arg0 != table[10]) {
                i = 3;
                if (arg0 != table[15]) {
                    i = 4;
                    if (arg0 != table[20])
                        i = 5;
                }
            }
        }
    }
    if (i >= 5)
        fn_802E317C(lbl_802FC69C, arg0);
    return lbl_802FC638 + i * 0x14;
}
#pragma scheduling on
void fn_80012778(void) { fn_80012984(0x12F); }

void fn_80012780(void) { fn_80012984(0x130); }

void fn_80012788(void) { fn_80012984(0x132); }

void fn_80012790(void) {
    fn_80012984();
}

extern int lbl_80558AD8;
void* fn_80012810(void) {
    return (void*)lbl_80558AD8;
}

extern void *lbl_8055D504;
void* fn_80012818(void) {
    return lbl_8055D504;
}

extern int lbl_8055D508;
void* fn_80012854(void) {
    return (void*)lbl_8055D508;
}

void *fn_8001285C(int arg0) DECOMP_DONT_INLINE {
    return &lbl_80352AD0[arg0 * 0x28];
}

extern char lbl_80352AD0[];
extern char lbl_802FC700[];
extern void fn_80131818(void *);
extern char lbl_8035183C[];
extern char lbl_8055D500;
extern int lbl_8055D514;
#pragma scheduling invalid_target
void fn_80012794(void) {
    void **base = (void **)&lbl_8035183C[0];
    void **p = base;
    int i = 0;
    lbl_80558AD8 = 0x134;
    while (i < *(int *)((char *)base + 0x80)) {
        fn_80131818(*p);
        p++;
        i++;
    }
    *(int *)((char *)base + 0x80) = 0;
    lbl_8055D500 = 0;
    lbl_8055D514 = 0;
}
#pragma scheduling on
extern char lbl_803518C0[];
extern char lbl_803551E0[];
char *fn_80012820(int arg0) DECOMP_DONT_INLINE {
    if (arg0 >= 0) {
        return &lbl_803518C0[arg0 * 0x84];
    }
    return &lbl_803551E0[(-1 - arg0) * 0x88];
}
#pragma scheduling invalid_target
void *fn_80012870(int arg0, int arg1) {
    unsigned char *p = (unsigned char *)lbl_80352AD0;
    unsigned int i;
    int j = 0;
    int count = lbl_8055D508;
    for (i = 0; count > 0; i++, count--, p += 0x28) {
        if (arg0 == *(int *)(p + 4) && p[0x24] != 0 && j == arg1)
            return &lbl_80352AD0[i * 0x28];
        j++;
    }
    fn_802E317C(lbl_802FC700, arg0, arg1);
    return 0;
}
#pragma scheduling on
extern void *fn_8001285C();
extern char *fn_80012820(int);
extern const char *fn_80007FF0(int);
extern int fn_80012938(float);
extern volatile float lbl_80560358;
void fn_80012910(void) {
    fn_80007FF0(*(int *)((char *)fn_8001285C() + 8));
}

#pragma dont_inline on
int fn_80012938(float f) {
    if (f > lbl_80560358) {
        return 2;
    }
    return 1;
}
#pragma dont_inline reset

#pragma dont_inline fn_80012938
void fn_80012954(void) {
    char *p = fn_80012820(*(int *)((char *)fn_8001285C() + 4));
    fn_80012938(*(float *)(p + 0x78));
}
int fn_800132E4(void *arg0, int arg1, int arg2) {
    if (((int (*)(void))(*(void ***)arg0)[3])() != 0) {
        return ((int (*)(void *, int))(*(void ***)arg0)[7])(arg0, arg1);
    }
    return arg2;
}

extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int fn_80131808(int);
extern void fn_8001335C(int, int);
#pragma scheduling invalid_target
void fn_80013618(int arg0) {
    int count;
    int result;
    if (arg0 == 0)
        return;
    if (fn_8012C33C() == 0)
        return;
    result = fn_80131808(arg0);
    count = *(int *)(lbl_8035183C + 0x80);
    *(int *)(lbl_8035183C + count * 4) = result;
    *(int *)(lbl_8035183C + 0x80) = count + 1;
    fn_8001335C(result, arg0);
}

int fn_80013680(void *arg0, void *arg1) {
    void *a = *(void **)((char *)arg0 + 0x80);
    void *b = *(void **)((char *)arg1 + 0x80);
    int x = (*(int (**)(void *, char *, int))(*(char **)a + 0x20))(a, lbl_802FCB74, 0x63);
    int y = (*(int (**)(void *, char *, int))(*(char **)b + 0x20))(b, lbl_802FCB74, 0x63);
    return x - y;
}

#pragma scheduling on
int fn_800136FC(void *arg0, void *arg1) {
    int a = ((int *)arg0)[0x1A];
    int b = ((int *)arg1)[0x1A];
    if (b == a) {
        return ((int *)arg0)[0x1B] - ((int *)arg1)[0x1B];
    }
    return a - b;
}

extern int lbl_8055D518;
void fn_80013A34(void) {
    int count = lbl_8055D518;
    char *p = lbl_803551E0;
    int blocks, i;
    if (count > 0) {
        blocks = (unsigned int)count >> 3;
        for (i = 0; i < blocks; i++) {
            *(int *)(p + 0x84) += *(int *)(p + 0x70); *(int *)(p + 0x70) = 0;
            *(int *)(p + 0x10C) += *(int *)(p + 0xF8); *(int *)(p + 0xF8) = 0;
            *(int *)(p + 0x194) += *(int *)(p + 0x180); *(int *)(p + 0x180) = 0;
            *(int *)(p + 0x21C) += *(int *)(p + 0x208); *(int *)(p + 0x208) = 0;
            *(int *)(p + 0x2A4) += *(int *)(p + 0x290); *(int *)(p + 0x290) = 0;
            *(int *)(p + 0x32C) += *(int *)(p + 0x318); *(int *)(p + 0x318) = 0;
            *(int *)(p + 0x3B4) += *(int *)(p + 0x3A0); *(int *)(p + 0x3A0) = 0;
            *(int *)(p + 0x43C) += *(int *)(p + 0x428); *(int *)(p + 0x428) = 0;
            p += 0x440;
        }
        for (i = 0; i < (count & 7); i++) {
            *(int *)(p + 0x84) += *(int *)(p + 0x70);
            *(int *)(p + 0x70) = 0;
            p += 0x88;
        }
    }
    {
        char *entry = lbl_80352AD0;
        int x;
        for (x = 0; x < lbl_8055D508; x++, entry += 0x28) {
            int y;
            for (y = 0; y < lbl_8055D518; y++) {
                if (*(int *)(entry + 4) == *(int *)(lbl_803551E0 + y * 0x88))
                    entry[0x24] = 0;
            }
        }
    }
}

extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int fn_80131808(int);
extern void fn_8001335C(int, int);
