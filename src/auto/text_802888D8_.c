// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F6DC;
extern void *lbl_8055F6E0;
extern int lbl_8055F6E4;
extern int fn_80289554(int);
extern int fn_80289F54(int);
extern int fn_80287B5C(void);
extern int fn_80287B14(void);
extern int fn_8028A330(int *, int);
extern int fn_8028E398(int);
extern int fn_80128668(void *);
extern void *fn_80288B88(void *, int);
extern void *fn_80289EE0(void *, int);
extern void *__dt__12PhysicsWorldFv_80289C20(void *, int);
extern void *__dt__Q210JASDrumSet5TPercFv_802894F4(void *, int);
extern int fn_80289084(void);
extern int fn_80289154(int);
extern int fn_80289268(int);
extern int fn_80289394(int);
extern void *fn_801284F8(int, void *);
extern int fn_80287B38(void *);
extern int lbl_8055F6D8;
extern char lbl_80348A90[];
extern void fn_80288A74(void **, int);
void fn_802888D8(void) {
    int r3;
    int r0;
    char *data = lbl_80348A90;
    r3 = (int)fn_801284F8(0x6c, data + 0xc);
    if (r3) r3 = fn_80288B40(r3);
    lbl_8055F6D8 = r3;
    r3 = (int)fn_801284F8(8, data + 0x20);
    if (r3) r3 = fn_80289BE8(r3);
    lbl_8055F6E0 = (void *)r3;
    r3 = (int)fn_801284F8(0xa8, data + 0x30);
    if (r3) r3 = fn_802894B4(r3);
    lbl_8055F6DC = r3;
    r3 = (int)fn_801284F8(8, data + 0x44);
    r0 = r3;
    if (r3) r0 = fn_80289EA0(r3);
    lbl_8055F6E4 = r0;
    fn_80287B38(fn_80288A74);
}

void fn_80288988(void) {
    fn_80289EE0((void *)lbl_8055F6E4, 1);
    lbl_8055F6E4 = 0;
    __dt__12PhysicsWorldFv_80289C20(lbl_8055F6E0, 1);
    lbl_8055F6E0 = 0;
    __dt__Q210JASDrumSet5TPercFv_802894F4((void *)lbl_8055F6DC, 1);
    lbl_8055F6DC = 0;
    fn_80288B88((void *)lbl_8055F6D8, 1);
    lbl_8055F6D8 = 0;
}

void fn_802889F0(void) {
    fn_80289554(lbl_8055F6DC);
    fn_80289F54(lbl_8055F6E4);
}

void fn_80288A1C(void) {}

extern void *lbl_8055F6E0;
extern int fn_8028E584(int, int, int);
void fn_80288A40(int arg0, int arg1) { fn_8028E584(*(int *)((char *)lbl_8055F6E0 + 4), arg0, arg1); }

void fn_80288A58(int arg0, int arg1) { fn_8028E584(*(int *)lbl_8055F6E0, arg0, arg1);}

void fn_80288A70(void) {}

extern float fn_801E7E24(void);
extern int lbl_8055F6D8, lbl_8055F6DC, lbl_8055F6E4;
extern float lbl_80558DC4, lbl_80564270;
extern int fn_80288BF0(int, int, int);
extern int fn_80289558(int, int);
extern void fn_80289FC4(int **, int, int);
__declspec(section ".data") extern float lbl_80558DC4;
void fn_80288A74(void **arg0, int arg1) {
    void **q;
    int i;
    void **p;
    int temp;
    int *obj;
    float limit;
    float value;

    value = __fabs(fn_801E7E24());
    if (!(value <= lbl_80558DC4)) {
        limit = lbl_80564270;
        p = arg0;
        q = arg0;
        for (i = 0; i < arg1; i++) {
            if (*((unsigned char *)q + 0xC) && *((float *)q + 2) < limit) {
                obj = (int *)*q;
                temp = obj[23];
                fn_80288BF0(lbl_8055F6D8, *(int *)((char *)p + 4), temp);
                fn_80289558(lbl_8055F6DC, *(int *)((char *)p + 4));
                fn_80289FC4((int **)lbl_8055F6E4, *(int *)((char *)p + 4), temp);
            }
            p = (void **)((char *)p + 0x10);
            q = (void **)((char *)q + 0x10);
        }
    }
}

int fn_80288B40(int arg0) {
    fn_80289084(); fn_80289154(arg0); fn_80289268(arg0); fn_80289394(arg0); return arg0;
}

int fn_80287B5C(void);
int fn_8028A330(int *, int);
int fn_80287B14(void);
int fn_8028E398(int);
int fn_80128668(void *);
void *fn_80288B88(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 0x68));
        fn_8028E398(*(int *)((char *)arg0 + 0x64));
        fn_8028E398(*(int *)((char *)arg0 + 0x60));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802896E4(void *);
int fn_802894B4(int arg0) {
    fn_802896E4((void *)arg0);
    fn_802897E0(arg0);
    fn_80289554(arg0);
    return arg0;
}

void *__dt__Q210JASDrumSet5TPercFv_802894F4(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 0xA4));
        fn_8028E398(*(int *)((char *)arg0 + 0xA0));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80289554(int arg0) {
    return fn_8028967C(arg0);
}

int fn_8028967C(int arg0) {
    int i;
    int *p = (int *)arg0;
    memset(p, 0, 0xA0);
    for (i = 0; i < fn_80287B14(); i++) {
        p[2] = *(int *)((char *)fn_80288208(i) + 0x24);
        p += 5;
    }
}

extern int fn_8028E61C(int *);
extern int fn_8028E2F8(int *, int *, int, int, float, float, float, float, float, float, float);
extern int lbl_80348B34;
extern int lbl_8055C880;
extern float lbl_8056427C, lbl_80564284, lbl_8056428C, lbl_8056429C;
extern float lbl_805642B0, lbl_805642F8, lbl_805642FC, lbl_80564300;
int fn_802897E0(int arg0) {
    volatile float sp94, sp90, sp8C, sp88, sp84, sp80, sp7C, sp78, sp74, sp70, sp68;
    volatile int sp64;
    volatile float sp54, sp50, sp44, sp40, sp3C, sp38, sp34, sp30, sp2C, sp28;
    volatile int sp24, sp20;
    volatile float sp1C, sp18, sp14, sp10, spC, sp8;

    fn_8028E61C((int *)&sp20);
    sp24 = 0x60;
    sp28 = lbl_805642FC;
    sp2C = lbl_8056428C;
    sp20 = 0;
    sp68 = lbl_80564284;
    sp64 = 6;
    sp14 = lbl_805642B0;
    sp18 = lbl_805642B0;
    sp1C = lbl_805642B0;
    sp30 = lbl_805642B0;
    sp34 = lbl_805642B0;
    sp38 = lbl_805642B0;
    sp8 = lbl_8056428C;
    spC = lbl_8056428C;
    sp10 = lbl_8056428C;
    sp3C = lbl_8056428C;
    sp40 = lbl_8056428C;
    sp44 = lbl_8056428C;
    sp50 = lbl_8056429C;
    sp54 = lbl_8056427C;
    sp8C = lbl_80564300;
    sp94 = lbl_80564300;
    sp84 = lbl_80564300;
    sp90 = lbl_80564300;
    sp88 = lbl_80564300;
    sp80 = lbl_80564300;
    sp78 = lbl_805642F8;
    sp7C = lbl_805642B0;
    sp70 = lbl_8056427C;
    sp74 = lbl_80564300;
    return *(int *)((char *)arg0 + 0xA4) = fn_8028E2F8((int *)&sp20, &lbl_80348B34, lbl_8055C880, 0, lbl_80564300, lbl_8056427C, lbl_8056429C, lbl_805642B0, lbl_80564284, lbl_8056428C, lbl_805642FC);
}

int fn_80289BE8(int arg0) {
    fn_80289C80();
    fn_80289D94(arg0);
    return arg0;
}

void *__dt__12PhysicsWorldFv_80289C20(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8028E398(*(int *)((char *)arg0 + 4));
        fn_8028E398(*(int *)arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80289EA0(int arg0) {
    fn_8028A084();
    fn_8028A1A4(arg0);
    fn_80289F54(arg0);
    return arg0;
}

void *fn_80289EE0(void *arg0, int arg1) {
    if (arg0 != 0) {
        int temp = *(int *)arg0;
        if (temp != 0)
            fn_80128670(temp - 0x10);
        *(int *)arg0 = 0;
        fn_8028E398(*(int *)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_80289FC4(int **arg0, int arg1, int arg2) {
    char *temp = (char *)*arg0 + arg1 * 0x68;
    if (arg2 == 3 && *(void **)(temp + 0x64) == 0 && *(int *)(temp + 0x60) > 0) {
        *(void **)(temp + 0x64) = temp + fn_80287B5C() * 0x18;
        fn_8028A330((int *)arg0, arg1);
    } else if (arg2 != 3 && *(void **)(temp + 0x64) != 0) {
        *(void **)(temp + 0x64) = 0;
    } else if (*(void **)(temp + 0x64) != 0) {
        fn_8028A330((int *)arg0, arg1);
    }
}

void fn_8028A32C(void) {}

