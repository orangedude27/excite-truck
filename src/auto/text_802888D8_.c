// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F6DC;
extern int lbl_8055F6E4;
extern int fn_80289554(int);
extern int fn_80289F54(int);
void fn_802889F0(void) {
    fn_80289554(lbl_8055F6DC);
    fn_80289F54(lbl_8055F6E4);
}

void fn_80288A1C(void) {}

extern void *lbl_8055F6E0;
extern int fn_8028E584(int, int, int);
void fn_80288A40(int arg0, int arg1) { fn_8028E584(*(int *)((char *)lbl_8055F6E0 + 4), arg0, arg1); }

void fn_80288A58(int arg0, int arg1) {
    fn_8028E584(*(int *)lbl_8055F6E0, arg0, arg1);
}

void fn_80288A70(void) {}

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

