// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A50(float *);

extern void *lbl_8055EDA8;
void* fn_802090B4(void) {
    return lbl_8055EDA8;
}

extern void *lbl_8055B4D8;
void* fn_802090CC(void) {
    return lbl_8055B4D8;
}

void fn_80209190(float *arg0, float arg1) {
    if (arg0 != 0) {
        float value = lbl_80563230 < arg1 ? lbl_80563230 : arg1;
        value = value > lbl_80563234 ? value : lbl_80563234;
        *arg0 = value;
        fn_80208A50(arg0);
    }
}

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A18(float);
extern void fn_80208A50(float *);
extern int fn_80128668(void);
void fn_802091CC(void) {
    fn_80208A18(lbl_80563230);
}

int fn_802091D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80209214(void) {
    return 0;
}

int fn_80209260(int arg0) { return arg0 + 4; }

int fn_80209268(void) { return 1; }

int fn_80209270(void) { return 1; }

void fn_80209278(void) {

}

void fn_8020927C(void) {

}

extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
void fn_80209280(void) {
    char *ptr = (char *)fn_801284F8(12, lbl_8033C1C0);
    if (ptr != 0) {
        *(char **)ptr = lbl_8033C0E8;
        *(int *)(ptr + 8) = 3;
    }
}

void fn_802093EC(void) {

}

void fn_802093F0(void) {

}

void fn_802093F4(void) {

}

void fn_802093F8(void) {

}

void fn_80209404(void) {

}

void fn_80209408(void) {

}

void fn_8020940C(void) {

}
extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
