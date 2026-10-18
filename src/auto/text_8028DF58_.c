// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(int, int);
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern float lbl_80564424;
extern void fn_8028FB98(float);
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028EE28(void *);
extern void fn_8028ED80(void *);
extern void fn_8028F2EC(void);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
extern int lbl_804B34B0_arr[];
#pragma push
#pragma small_data off
typedef int lbl_804B34B0_t;
#pragma push
#pragma small_data off
void fn_8028DFB0(void) {
    if (*((int *)((char *)&lbl_804B34B0_arr[0] + 0x100)) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0_arr[0];
    }
    lbl_8055F744 = 0;
}
#pragma pop
extern unsigned char lbl_8055F73D;
extern float lbl_80564420;
extern int lbl_8055F748;
void fn_8028DF58(void);
void fn_8028ED74(void *);
void fn_8028EE1C(void *);
void fn_8028F8C4(int);
float fn_801E7E18(void);
void fn_8028DFFC(void) {
    fn_8028DF58();
    lbl_8055F73D = 1;
}

void fn_8028E024(void) {
    if (*((int *)((char *)&lbl_804B34B0_arr[0] + 0x100)) > 0) {
        fn_8028F2EC();
        lbl_8055F740 = lbl_804B34B0_arr[0];
    }
    lbl_8055F744 = 0;
}

void fn_8028E070(float farg0) {
    lbl_8055F738 = farg0;
    lbl_8055F73C = 1;
}

#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_804B34B0;
#pragma push
#pragma small_data off
void fn_8028E080(void) {
    struct Table { int entries[64]; int count; } *base = (struct Table *)&lbl_804B34B0_arr[0];
    int *entries;
    int i;
    entries = base->entries;
    lbl_8055F73C = 0;
    i = 0;
    goto test;
body:
    fn_8028F8E0(*entries, lbl_8055F738);
    entries++;
    i++;
test:
    if (i < base->count) goto body;
}
#pragma pop
void fn_8028E0F0(void) {
    fn_8028F5A4();
    fn_8028EE28((char *)&lbl_804B34B0 + 0x208);
    fn_8028ED80((char *)&lbl_804B34B0 + 0x104);
    fn_8028ED80(&lbl_804B34B0);
}

extern void fn_8028ED74(void *);
extern void fn_8028EE1C(void *);
extern void fn_8028F8C4(int);
void fn_8028E138(void) {
    int *base = &lbl_804B34B0;
    int *ptr = base;
    int count = 0;
    lbl_8055F738 = lbl_80564420;
    while (count < *(int *)((char *)base + 0x100)) {
        fn_8028F8C4(*ptr);
        ptr++;
        count++;
    }
}

void fn_8028E1A4(void) {
    lbl_8055F738 = fn_801E7E18();
    lbl_8055F73C = 1;
}

int fn_8028E2F8(int arg0, int arg1, int arg2) {
    int result;
    result = fn_801284F8(0xB0, &lbl_8055C8E0);
    if (result != 0) {
        result = ((int (*)(int, int, int))fn_8028F7AC)(result, arg0, arg2);
    }
    fn_8028ED8C(&lbl_804B35B4[0], result);
    fn_8028ED8C(&lbl_804B34B0, result);
    fn_8028F5A0(arg1, result);
    return result;
}

extern float fn_802C9A4C(float);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern int fn_8028FA1C(int);
extern int fn_801284F8(int, void *);
extern int fn_8028F7AC(int, int);
extern void fn_8028ED8C(void *, int);
extern void fn_8028F5A0(int, int);
extern int lbl_8055C8E0;
extern int lbl_804B35B4[];
extern int fn_8028F858(int, int);
#pragma push
#pragma small_data off
void fn_8028E398(int arg0) {
    if (fn_8028EDA8(&lbl_804B35B4[0], arg0) != 0) {
        fn_8028EDA8((unsigned int *)lbl_804B34B0_arr, arg0);
        fn_8028F858(arg0, 1);
    }
}

extern int lbl_804B36B8[];
void fn_8028E528(int arg0) {
    if (fn_8028EF44(&lbl_804B36B8[0], arg0) != 0) {
        fn_8028EF44((unsigned int *)lbl_804B34B0_arr, arg0);
        fn_8028F858(arg0, 1);
    }
}

#pragma pop
void fn_8028E584(void) {
    fn_8028FB98(lbl_80564424);
}

void fn_8028E58C(void) { fn_8028FAE4(); }

void fn_8028E590(void) { fn_8028FC40(); }

void *memset(void *, int, unsigned int);
#pragma push
#pragma small_data off
int fn_8028E61C(void *arg0) {
    memset(arg0, 0, 0x8C);
    return (int)arg0;
}
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);

void fn_8028ED74(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED80(void *arg0) { *(int *)((char *)arg0 + 0x100) = 0; }

void fn_8028ED8C(void *arg0, int arg1) {
    *(int *)((char *)arg0 + (*(int *)((char *)arg0 + 0x100) << 2)) = arg1;
    *(int *)((char *)arg0 + 0x100) = *(int *)((char *)arg0 + 0x100) + 1;
}

extern int fn_802E317C(const char *, ...);
extern char lbl_80348CF8[];
extern char lbl_80348D28[];
extern int stricmp(const char *, const char *);
extern char lbl_80348F4C[];
int fn_8028EDA8(unsigned int *arg0, unsigned int arg1) {
    int i = 0;
    int count = *(int *)((char *)arg0 + 0x100);
    if (count > 0) {
        do {
            if (*arg0 == arg1) {
                arg0[i] = 0;
                return 1;
            }
            arg0 += 1;
            i += 1;
        } while (--count != 0);
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

void fn_8028EE1C(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

void fn_8028EE28(void *arg0) {
    *(int *)((char *)arg0 + 0x600) = 0;
}

int fn_8028EE34(void *arg0, int arg1, int *arg2) {
    char *p = (char *)arg0;
    int i = 0;
    while (i < *(int *)((char *)arg0 + 0x600)) {
        if (fn_8002B1D8(arg1, p, 15) == 0) {
            *arg2 = i;
            return 1;
        }
        p += 0x18;
        i++;
    }
    return 0;
}

extern int fn_8002B1D8(int, void *, int);
extern char *strncpy(char *, const char *, unsigned int);
void fn_8028EEB4(void *arg0, int arg1, const char *arg2) {
    int count;
    int *countp;
    char *p;
    char *q;
    count = *(int *)((char *)arg0 + 0x600);
    p = (char *)arg0 + count * 0x18;
    strncpy(p, arg2, 0x10);
    countp = (int *)((char *)arg0 + 0x600);
    q = (char *)arg0 + *countp * 0x18;
    q[0xF] = 0;
    q = (char *)arg0 + *countp * 0x18;
    *(int *)(q + 0x10) = arg1;
    q = (char *)arg0 + *countp * 0x18;
    *(int *)(q + 0x14) = 1;
    (*countp)++;
}

int fn_8028EF44(void *arg0, unsigned int arg1) {
    char *base = (char *)arg0;
    char *p = base;
    int i = 0;
    int count = *(int *)(base + 0x600);
    while (count > 0) {
        if (arg1 == *(unsigned int *)(p + 0x10)) {
            int *q = (int *)(base + i * 0x18 + 0x14);
            *q -= 1;
            return *q == 0;
        }
        p += 0x18;
        i++;
        count--;
    }
    fn_802E317C(lbl_80348F4C);
    return 0;
}

#pragma push
#pragma small_data off
void fn_8028EFC4(int arg0, int *arg1) {
    int i = 0;
    int *p = arg1;
    while (i < *(int *)((char *)arg1 + 0x100)) {
        int item = *p;
        int n = *(int *)((char *)item + 0x44);
        fn_8028ED8C((char *)arg0 + (n - 1) * 0x104, item);
        p++;
        i++;
    }
}

#pragma push
#pragma small_data off
int fn_8028F040(int *arg0, int *arg1, int arg2) {
    int n = *(int *)((char *)arg0 + 0x100);
    while (n > 0) {
        int id = *(int *)((char *)*arg0 + 0xA4);
        if (id != arg2) {
            int count = *(int *)((char *)arg1 + 0x100);
            int j = 0;
            int *p = arg1;
            while (j < count) {
                int other = *(int *)((char *)*p + 0xA4);
                p++;
                j++;
                if (id == other) return id;
            }
        }
        arg0++;
        n--;
    }
    return -2;
}

extern float fn_80129DC4(int, float, float);
#pragma push
#pragma processor 750
void fn_8028F444(float *arg0, float *arg1, float *arg2, float *arg3, float farg0, float farg1) {
    arg0[0] = arg1[0] * arg3[0] + farg1 * fn_80129DC4(0, -arg2[0], arg2[0]);
    arg0[1] = arg1[1] * arg3[1] + farg1 * fn_80129DC4(0, -arg2[1], arg2[1]);
    arg0[1] += farg1 * farg0;
    arg0[2] = arg1[2] * arg3[2] + farg1 * fn_80129DC4(0, -arg2[2], arg2[2]);
}
#pragma pop
void fn_8028F5A4(void) {
}

void fn_8028F854(void) {}

int fn_8028F858(int arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        fn_802CAC54(*(int *)(arg0 + 0xA4));
        value = *(int *)(arg0 + 0x8C);
        if (value != 0) fn_80128670(value - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8028F8C4(int arg0) {
    char *p = (char *)arg0;
    *(int *)(p + 0x90) = -1;
    *(int *)(p + 0x94) = 0;
    *(float *)(p + 0x9C) = lbl_80564420;
}

extern float lbl_80558DC4;
__declspec(section ".data") extern float lbl_80558DC4;
void fn_8028F8E0(int arg0, float farg0) {
    char *p = (char *)arg0;
    float *fp9c = (float *)(p + 0x9C);
    float threshold;
    int index, count, count2, i, j;

    if (*fp9c >= lbl_80564424 - lbl_80558DC4) {
        *fp9c = *fp9c - lbl_80564424;
    }
    index = *(int *)(p + 0x90);
    *fp9c = *fp9c + *(float *)(p + 0xC);
    if (index < 0) return;

    threshold = farg0 - *(float *)(p + 8);
    count = *(int *)(p + 0x94);
    i = index;
    if (i < count) {
        while (i < count && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
            i++;
        }
        if (i != count) {
            *(int *)(p + 0x90) = i;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }

    count2 = *(int *)(p + 0x98);
    while (i < count2 && *(float *)(*(char **)(p + 0x8C) + i * 0x28 + 0x18) < threshold) {
        i++;
    }
    if (i == count2) {
        j = 0;
        while (j < count && *(float *)(*(char **)(p + 0x8C) + j * 0x28 + 0x18) < threshold) {
            j++;
        }
        if (j != count) {
            *(int *)(p + 0x90) = j;
            return;
        }
        *(int *)(p + 0x90) = -1;
        *(int *)(p + 0x94) = 0;
        return;
    }
    *(int *)(p + 0x90) = i;
}

int fn_8028FA1C(int arg0) {
    int index;
    int count;
    int count2;
    char *entries;

    index = *(int *)(arg0 + 0x90);
    if (index < 0) goto done;
    count = *(int *)(arg0 + 0x94);
    if (index < count) {
        fn_8002F768((void *)arg0, (int)(*(char **)(arg0 + 0x8c) + index * 0x28), count - index);
        goto done;
    }
    count2 = *(int *)(arg0 + 0x98);
    entries = *(char **)(arg0 + 0x8c);
    fn_8002F768((void *)arg0, (int)(entries + index * 0x28), count2 - index);
    fn_8002F768((void *)arg0, (int)entries, count);
done:
    return 0;
}

extern float lbl_80564424, lbl_80564448, lbl_8056444C, lbl_80564450, lbl_80564454, lbl_80564458;
void fn_80290160(void *arg0, void *arg1, void *arg2, float farg0) {
    float a, b, c, d, e, f, g, h, i, j, k;
    volatile float sp8, spC, sp10;
    a = lbl_8056444C;
    b = *(float *)((char *)arg0 + 0xA0);
    c = a * farg0;
    d = farg0 * b;
    e = lbl_80564448;
    f = *(float *)((char *)arg0 + 0x34);
    g = lbl_80564454;
    h = g * f;
    i = lbl_80564450;
    j = e * d;
    k = lbl_80564424;
    a = f * d;
    b = h * d;
    e = *(float *)((char *)arg0 + 0x30);
    f = j - i;
    g = lbl_80564458;
    h = j - k;
    a = f * b;
    i = *(float *)((char *)arg2 + 0x10);
    b = h * a;
    j = *(float *)((char *)arg2 + 0xC);
    g = g * e;
    e = k + a;
    f = *(float *)((char *)arg2 + 0x14);
    h = k + b;
    a = *(float *)arg2;
    b = *(float *)((char *)arg2 + 4);
    c = c * e;
    e = *(float *)((char *)arg2 + 8);
    i = i * h;
    j = j * h;
    f = f * h;
    g = g * c;
    c = j * farg0;
    sp8 = j;
    a = a + c;
    c = f * farg0;
    sp10 = f;
    g = i - g;
    spC = g;
    c = g * farg0;
    b = b + c;
    e = e + c;
    *(float *)arg1 = a;
    *(float *)((char *)arg1 + 8) = e;
    *(float *)((char *)arg1 + 4) = b;
}

extern int fn_80128668(void);
int fn_8029169C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_802916DC(void) { return 0; }

void fn_802916E4(void) {}

void fn_802916E8(void) {}

void fn_802916EC(void) {}

int fn_802916F0(void *arg0) { return ((int *)arg0)[1]; }

int fn_802916F8(void *arg0) { return *(int *)((char *)arg0 + 0x118); }

#pragma dont_inline on
void fn_80291700(void) { fn_802916E8(); }
void fn_80291704(void) { fn_802916EC(); }

void fn_80291708(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 1;
}

void fn_80291714(void *arg0) {
    *((unsigned char *)arg0 + 0x11C) = 0;
}

unsigned char fn_80291720(void *arg0) {
    return *((unsigned char *)arg0 + 0x11C);
}

#pragma dont_inline reset
extern int lbl_8055F748;
extern float lbl_8055F738;
extern unsigned char lbl_8055F73C;
extern int lbl_804B34B0;
extern void fn_8028F8E0(int, float);
extern void fn_8028F5A4(void);
extern void fn_8028F2EC(void);
extern int lbl_8055F740;
extern unsigned char lbl_8055F744;
