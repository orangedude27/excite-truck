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

int fn_802894B4(int arg0) {
    fn_802896E4();
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

