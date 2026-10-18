#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FB28, lbl_8055FB2C, lbl_8055FB30, lbl_8055FB34, lbl_8055CFA0;
extern int lbl_8055FB40;
extern int lbl_804C0810, lbl_804C0E10;
extern void fn_80128670(int);
extern void fn_801D05B4(void *);
extern void fn_801D0824(void *);
extern void fn_802C1180(void *);
extern int fn_802E317C(const char *);
void *fn_802C110C(int arg0) {
    int i;
    int *entry = (int *)((char *)&lbl_804C0810);
    for (i = 0; i < lbl_8055FB28; i++, entry = (int *)((char *)entry + 0x60)) {
        if (arg0 >= entry[0] && arg0 <= entry[1])
            return entry;
    }
    fn_802E317C((const char *)0x8034AED0);
    return 0;
}

#pragma scheduling off
void fn_802C1180(void *arg0) {
    volatile int *src = (volatile int *)arg0;
    volatile int *dst = (volatile int *)src[1];
    int zero = 0;
    int a, b;
    if (dst == 0) return;
    b = src[2]; a = src[3]; dst[0] = b; dst[1] = a;
    b = src[4]; a = src[5]; dst[2] = b; dst[3] = a;
    b = src[6]; a = src[7]; dst[4] = b; dst[5] = a;
    b = src[8]; a = src[9]; dst[6] = b; dst[7] = a;
    dst[8] = src[10];
    b = src[11]; a = src[12]; dst[9] = b; dst[10] = a;
    dst[11] = src[13];
    ((int **)lbl_8055FB30)[src[0]] = (int *)src[1];
    src[1] = zero;
}
#pragma scheduling on
void *fn_802C120C(void) {
    unsigned int n = lbl_8055FB34 + 1;
    void *entry = (char *)&lbl_804C0E10 + lbl_8055FB34 * 0x48;
    lbl_8055FB34 = ((n << 29) - (n >> 31));
    fn_802C1180(entry);
    return entry;
}

void fn_802C13A4(void) {
    int i;
    fn_801D05B4(&lbl_8055FB40);
    if (&lbl_8055FB40 != 0)
        fn_801D0824((char *)&lbl_8055FB40 + 4);
    for (i = 0; i < lbl_8055FB28; i++) {
        if (*(int *)((char *)&lbl_804C0810 + i * 0x60 + 0x34))
            fn_80128670(*(int *)((char *)&lbl_804C0810 + i * 0x60 + 0x34));
    }
    fn_80128670(lbl_8055FB30);
    lbl_8055FB30 = 0;
    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
}

extern int fn_801345D8(char *, int, const char *, int);
extern char lbl_8034AF14[];
extern int lbl_804C0810;
extern int lbl_8055FB28;
int fn_802C143C(void *arg0) {
    char buf[0x20];
    int index = lbl_8055FB28;
    int *entry = (int *)((char *)&lbl_804C0810 + index * 0x60);
    int i;

    entry[0] = -1;
    *((char *)entry + 0x28) = 1;
    lbl_8055FB28 = index + 1;
    entry[0x30 / 4] = (int)arg0;
    for (i = 0; i < 8; i++) {
        if (arg0 != 0) {
            fn_801345D8(buf, 0x20, lbl_8034AF14, i + 1);
            entry[0x40 / 4 + i] = ((int (**)(void *, char *, int))(*(int *)arg0))[4](arg0, buf, -1);
        } else {
            entry[0x40 / 4 + i] = -1;
        }
    }
    return index;
}

int fn_802C1500(int arg0, int arg1) {
    int index = lbl_8055FB2C;
    int *table = &lbl_804C0810;
    int *entry = (int *)((char *)table + arg1 * 0x60);
    lbl_8055FB2C = index + 1;
    ((int *)lbl_8055FB30)[index] = arg0;
    if (entry[0] < 0)
        entry[0] = index;
    entry[1] = index;
    return lbl_8055CFA0 + index;
}

extern f32 lbl_804C1050[16];
extern f32 lbl_80564E58;
extern f32 lbl_80564E70;
extern f32 lbl_80564E74;
extern void fn_802BDFF4(int *);
void fn_802C1928(void) {
    int *entry = (int *)&lbl_804C0E10;
    int i;
    f32 zero = lbl_80564E58;
    f32 *z = (f32 *)((char *)&lbl_804C1050 + 4);
    for (i = 0; i < 8; i++) {
        z[i * 2] = zero;
        entry = (int *)((char *)entry + 0x48);
    }
    for (i = 0; i < 8; i++)
        fn_802C1180(entry - (int)(0x48 / 4));
    {
        int *list = (int *)lbl_8055FB30;
        int j;
        f32 min = lbl_80564E70;
        f32 delta = lbl_80564E74;
        for (j = 0; j < lbl_8055FB2C; j++) {
            int *obj = (int *)list[j];
            if (*(f32 *)((char *)obj + 0x28) < min) {
                *(f32 *)((char *)obj + 0x28) -= delta;
                ((void (*)(int *, int))fn_802BDFF4)(obj, 1);
            }
        }
    }
}

void fn_802C1A08(void) {}
typedef struct { int a, b; } Pair802C;
