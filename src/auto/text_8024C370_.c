// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8024CC54(void *, void *, int);
extern void fn_8024C768(void);
extern signed char lbl_8055F2C8;
int fn_8024CEF0(void);
extern int fn_8000D984(int);
extern void fn_8000DA80(void);
extern int fn_8000DC70(int);
extern void fn_8000DA1C(void *);
extern int fn_802E8D84(void);
extern void fn_802E7128(void);
void fn_802328D4(void *);
void fn_80128668(void *);
int fn_8000DA10(void);
int fn_8000DB34(int);
int fn_8000DB8C(int);
int fn_8000DBAC(int);
void fn_801345D8(void *, int, const char *, int);
extern char lbl_80498A00[];
extern int lbl_80498A48[];
extern char lbl_8055C018[];
void fn_8024C370(void) {}

#pragma push
#pragma use_lmw_stmw off
void *fn_8024C374(void *arg0, int arg1) {
    void *result = arg0;
    if (arg0 != 0) {
        if ((int)arg0 + 0x78 != 0) {
            fn_802328D4(((void **)arg0)[0x78 / 4]);
            ((void **)arg0)[0x78 / 4] = 0;
        }
        if ((int)arg0 + 0x18 != 0 && (int)arg0 + 0x4C != 0) {
            fn_802328D4(((void **)arg0)[0x4C / 4]);
            ((void **)arg0)[0x4C / 4] = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return result;
}
#pragma pop
void *fn_8024C3FC(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*(void **)((char *)arg0 + 0x34) != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x34));
            *(void **)((char *)arg0 + 0x34) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_8024C464(void) {
    int i;
    int state;
    for (i = 0; i < 4; ++i) {
        fn_801345D8(&lbl_80498A00[i * 0x12], 0x12, lbl_8055C018, fn_8000DB34(i));
        if (fn_8000DBAC(i) == 0 && i == fn_8000DA10()) {
            if (fn_8000DB8C(i) != 0)
                lbl_80498A48[i] = 2;
            else
                lbl_80498A48[i] = 1;
        } else {
            lbl_80498A48[i] = 0;
        }
    }
}

void fn_802E6FBC(void);
void fn_802E712C(void);
void fn_802E6CA8(void);
void fn_8000DA80(void);
int fn_8023FAD4(void *, int);
extern int lbl_8055F2C4;
extern char lbl_80343F78[];
extern char lbl_80343F68[];
int fn_80131234(const char *);
int fn_80215214(int, int);
int fn_8024C550(void) {
    fn_802E6FBC();
    fn_8024C464();
    return 0;
}

int fn_8024C578(int arg0) {
    int result;
    if (((int (*)())fn_8000DBAC)() != 0) {
        int sp[4];
        short last;
        sp[0] = 0;
        sp[1] = 0;
        sp[2] = 0;
        sp[3] = 0;
        last = 0;
        if (fn_8023FAD4(sp, 0x12) != 0) {
            fn_8000D984(arg0);
            fn_8000DA80();
            fn_8000DA1C(sp);
            fn_802E6FBC();
            fn_8024C464();
            result = 1;
        } else {
            result = 0;
        }
    } else {
        lbl_8055F2C4 = (int)(lbl_80498A00 + arg0 * 0x12);
        fn_8000D984(arg0);
        fn_8024C464();
        result = 1;
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
int fn_8027B8E4(int, int);
int fn_8027B984(int, int);
int fn_80214A9C(int);
extern int fn_80214CB4();
#pragma push
#pragma use_lmw_stmw off
void fn_8024C628(void) {
    int i, j, all, player, offset, active;
    player = fn_8000DA10();
    offset = 0;
    for (i = 0; i < 4; ++i) {
        all = 1;
        for (j = 0; j < 3; ++j) if (fn_8027B8E4(j, i) == 0) all = 0;
        for (j = 0; j < 2; ++j) if (fn_8027B984(j, i) == 0) all = 0;
        if (all) fn_80214A9C(i + 1); else fn_80214A9C(i + 0xB);
        if (i == player) { active = offset + all; fn_80214CB4(active); }
        offset += 2;
    }
}
#pragma pop

int fn_8024C6F4(void) {
    int first;
    int result = 0;
    if (((int (*)())fn_8000DBAC)() == 0 || ((int (*)(int, int, int))fn_80215214)(fn_80131234(lbl_80343F68), (first = fn_80131234(lbl_80343F78)), 0) != 0) {
        result = 1;
    }
    return result;
}

extern unsigned char lbl_8055F2D0;
int fn_80214B44(int);
int fn_80214CB4(void);
void fn_8024CBF4(void) {
    unsigned char *p = &lbl_8055F2D0;
    int i = 0;
    do {
        if (*p == 0)
            fn_80214B44(i + 1);
        i++;
        p++;
    } while (i < 4);
    fn_8000DA10();
    fn_80214CB4();
}

void fn_8024CF38(void) {
    fn_8024CC54(&fn_8024CEF0, 0, 1);
}

int fn_8024CF48(int *arg0) {
    fn_8024CC54(arg0, 0, 0);
}

void fn_8024CF54(void) {
    lbl_8055F2C8 = 1;
    fn_8024C768();
}

void fn_8024CFB4(void) {
    int sp8;
    if (((int (*)(int *))fn_8024CF48)(&sp8) != 0) fn_8000D984(sp8);
}

void fn_8024CFE8(void *arg0) {
    int numerator;
    int denominator;
    double bias = 4503601774854144.0;
    numerator = *(int *)((char *)arg0 + 0x10);
    denominator = fn_80232B70(*(int *)((char *)arg0 + 0x34));
    *(float *)((char *)arg0 + 0x40) = (float)numerator / (float)denominator;
}

int fn_8024D054(void *arg0, int arg1) {
    int value;
    switch (arg1) {
    case 0x6f:
        value = (int)strlen(*(char **)((char *)arg0 + 0x2c));
        if (value >= *(int *)((char *)arg0 + 0x30) + 1)
            value = *(int *)((char *)arg0 + 0x30) + 1;
        *(int *)((char *)arg0 + 0x30) = value;
        *(char *)((char *)arg0 + 0x48) = 1;
        return 1;
    case 0x20:
        *(char *)((char *)arg0 + 0x48) = 1;
        value = *(int *)((char *)arg0 + 0x30) - 1;
        *(int *)((char *)arg0 + 0x30) = value & ~(value >> 31);
        return 1;
    default:
        return 0;
    }
}

extern void fn_80230924(void *, float, float, float, float, float);
extern void fn_80230C30(float *, float *, int, int);
extern void fn_80234AFC(void *, const char *, int, float, float, int);
extern float lbl_80563940, lbl_80563944, lbl_80563948, lbl_80563950, lbl_80563954;
extern double lbl_80563938;
extern signed char lbl_80344120[], lbl_80344148[];
extern char lbl_8055C098[], lbl_8055C0A0[], lbl_8055C0A8[];
void fn_8024D810(void *arg0) {
    float x, y;
    float dx, dy, width, height, right, bottom;
    int row, col, base;
    fn_80230C30(&x, &y, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    dx = (float)*(int *)((char *)arg0 + 0xC) / lbl_80563948;
    dy = (float)*(int *)((char *)arg0 + 0x10) * lbl_80563944;
    width = (float)*(int *)((char *)arg0 + 0x64);
    height = (float)*(int *)((char *)arg0 + 0x68);
    x += dx * width;
    y -= dy * height;
    fn_80230924((void *)0xFFAF7F00, x, y, x + dx, y - lbl_80563950, lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, x, y, x + dx, lbl_80563950 + y - dy, lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, x, y, x + lbl_80563950, y - dy, lbl_80563940);
    fn_80230924((void *)0xFFAF7F00, x + dx, y, x + dx - lbl_80563950, y - dy, lbl_80563940);
    x += dx * lbl_80563954;
    y -= dy * lbl_80563954;
    for (row = 0, base = 0; row < 4; row++, base += 10, y -= dy) {
        float cur = x;
        for (col = 0; col < 10; col++, cur += dx) {
            if (row == 3 && col == 9)
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C098, 1, cur, y, 0);
            else if (row == 3 && col == 8)
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C0A0, 1, cur, y, 0);
            else {
                signed char *letters = *(unsigned char *)((char *)arg0 + 0x6C) ? lbl_80344120 : lbl_80344148;
                fn_80234AFC((char *)arg0 + 0x78, lbl_8055C0A8, 1, cur, y, letters[base + col]);
            }
        }
    }
}

