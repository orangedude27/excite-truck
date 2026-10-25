#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FB28, lbl_8055FB2C, lbl_8055FB30, lbl_8055FB34, lbl_8055CFA0;
extern int lbl_8055FB40;
extern char lbl_804C0810[];
extern char lbl_804C0E10[];
extern f32 lbl_8055FB38;
extern f32 lbl_80564E50;
extern char lbl_8034AEF8[], lbl_8034AF04[];
extern int fn_801FB1F4(int);
extern int fn_8012850C(int, const char *);
extern void fn_801D0590(void *);
extern void fn_801D0800(void *);
extern void *memset(void *, int, unsigned int);
void fn_802C1928(void);
void fn_802C1A08(void);
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

void fn_802C126C(void) {
    int *var_r29;
    char *var_r30;
    int var_r28, var_r28_2, var_r5;
    unsigned char *var_r4, *var_r6;
    unsigned char temp_r3;
    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
    lbl_8055CFA0 = fn_801FB1F4(0x1F40);
    lbl_8055FB38 = lbl_80564E50;
    lbl_8055FB30 = fn_8012850C(0x7D00, lbl_8034AEF8);
    fn_801D0590(&lbl_8055FB40);
    if (&lbl_8055FB40 != 0)
        fn_801D0800((char *)&lbl_8055FB40 + 4);
    var_r29 = (int *)((char *)&lbl_804C0810);
    var_r28 = 0;
    do {
        memset(var_r29, 0, 0x60);
        var_r4 = (unsigned char *)lbl_8034AF04;
        var_r6 = (unsigned char *)((char *)var_r29 + 8);
        var_r5 = 0x20;
        do {
            temp_r3 = *var_r4++;
            *var_r6++ = temp_r3;
            if ((signed char)temp_r3 == 0)
                break;
        } while (--var_r5 > 0);
        if (var_r5 == 0)
            var_r6[-1] = 0;
        var_r28++;
        var_r29 = (int *)((char *)var_r29 + 0x60);
    } while (var_r28 < 0x10);
    var_r30 = (char *)((char *)&lbl_804C0E10);
    var_r28_2 = 0;
    do {
        memset(var_r30, 0, 0x48);
        var_r28_2++;
        var_r30 += 0x48;
    } while (var_r28_2 < 8);
    lbl_8055FB34 = 0;
    fn_802C1928();
    fn_802C1A08();
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

#pragma optimization_level 2
#pragma scheduling invalid_target
int fn_802C1500(int arg0, int arg1) {
    struct Entry {
        int first;
        int second;
        char padding[0x58];
    };
    int index = lbl_8055FB2C;
    struct Entry *entry = (struct Entry *)lbl_804C0810 + arg1;
    int *list = (int *)lbl_8055FB30;
    lbl_8055FB2C = index + 1;
    list[index] = arg0;
    if (entry->first < 0) {
        entry->first = index;
        entry->second = index;
    } else {
        entry->second = index;
    }
    return lbl_8055CFA0 + index;
}
#pragma scheduling on
#pragma optimization_level reset
extern char lbl_8034AED0[];
extern f32 lbl_80564E54, lbl_80564E50, lbl_80564E58;
extern char lbl_8055CFA4[], lbl_8055CFAC[], lbl_8055CFB8[], lbl_8055CFC0[];
extern void fn_801FA7F4(int, f32 *, void *);
void fn_802C1550(void) {
    char *entry;
    int i, j;
    f32 pos[12];
    entry = (char *)&lbl_804C0810;
    for (i = 0; i < lbl_8055FB28; i++, entry += 0x60) {
        void *obj = *(void **)(entry + 0x30);
        int count;
        int index;
        char *name;
        *(u8 *)(entry + 0x28) = (((int (*)(void *, char *, int))(*(void ***)obj)[0x30 / 4])(obj, lbl_8034AED0 + 0x54, 0) == 0);
        obj = ((void *(*)(void *, char *))(*(void ***)obj)[0x5c / 4])(obj, lbl_8034AED0 + 0x60);
        if (obj == 0)
            continue;
        *(f32 *)(entry + 0x2c) = ((f32 (*)(void *, char *))(*(void ***)obj)[0x24 / 4])(obj, lbl_8034AED0 + 0x6c);
        index = ((int (*)(void *, char *))(*(void ***)obj)[0x14 / 4])(obj, lbl_8055CFA4);
        count = ((int (*)(void *, char *))(*(void ***)obj)[0x1c / 4])(obj, lbl_8055CFAC);
        *(int *)(entry + 0x38) = count;
        *(int *)(entry + 0x3c) = 0;
        *(void **)(entry + 0x34) = (void *)fn_8012850C(count * 4, lbl_8055CFB8);
        memset(0, 0, count * 4);
        name = ((char *(*)(void *, char *))(*(void ***)obj)[0x14 / 4])(obj, lbl_8055CFC0);
        for (j = 0; j < 0x20; j++) {
            char c = name[j];
            entry[8 + j] = c;
            if (c == 0)
                break;
        }
        if (j == 0x20)
            entry[0x27] = 0;
        if (count <= 0)
            continue;
        for (j = 0; j < count; j++) {
            pos[0] = lbl_80564E54;
            pos[1] = lbl_80564E50; pos[2] = lbl_80564E50;
            pos[3] = lbl_80564E50; pos[4] = lbl_80564E54;
            pos[5] = lbl_80564E50; pos[6] = lbl_80564E50;
            pos[7] = lbl_80564E50; pos[8] = lbl_80564E54;
            pos[9] = lbl_80564E50; pos[11] = lbl_80564E50;
            pos[10] = lbl_80564E58;
            fn_801FA7F4(index, pos, *(void **)(entry + 0x30));
        }
    }
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
