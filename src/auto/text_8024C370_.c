// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8024CC54(void *, void *, int);
extern void fn_8024C768(void);
extern signed char lbl_8055F2C8;
extern int fn_8024CEF0;
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

void *fn_8024C374(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 0x78 != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x78));
            *(void **)((char *)arg0 + 0x78) = 0;
        }
        if ((char *)arg0 + 0x18 != 0 && (char *)arg0 + 0x4C != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x4C));
            *(void **)((char *)arg0 + 0x4C) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

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

int fn_8024C6F4(void) {
    int result = 0;
    int temp;
    if (((int (*)())fn_8000DBAC)() != 0) {
        temp = fn_80131234(lbl_80343F78);
        fn_80131234(lbl_80343F68);
        if (fn_80215214(temp, 0) != 0)
            result = 1;
    }
    return result;
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
    int a = *(int *)((char *)arg0 + 0x10);
    int b = fn_80232B70(*(int *)((char *)arg0 + 0x34));
    *(float *)((char *)arg0 + 0x40) = (float)a / (float)b;
}

int fn_8024D054(void *arg0, int arg1) {
    int value;
    switch (arg1) {
    case 0x6f:
        value = (int)strlen(*(char **)((char *)arg0 + 0x2c));
        if (value < *(int *)((char *)arg0 + 0x30) + 1)
            *(int *)((char *)arg0 + 0x30) = value;
        else
            *(int *)((char *)arg0 + 0x30) += 1;
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

