// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
extern int fn_801DC258(float *, int *, short *, float, float);
extern int fn_80128670(void);
extern int fn_801D049C(void);

void fn_801DCA5C(void) {
    fn_8012C4D8();
}

void fn_801DCD24(void) {
    fn_80128668();
}

void fn_801DCDA0(void) {

}

void fn_801DCDA4(void) {
    if (lbl_80446F08[2] != 0) {
        fn_80128670();
        lbl_80446F08[2] = 0;
    }
    lbl_8055E994(lbl_8055E990);
    lbl_8055E994 = 0;
    lbl_8055E990 = 0;
    lbl_8055E9A4 = 0;
    fn_801D049C();
}

void fn_801DCE0C(void) {
    fn_801DCD28();
}

void fn_801DCE10(void) {

}

int fn_801DCE14(short *arg0, float *arg1, float *arg2, int *arg4) {
    float spC;
    int sp8;

    if (arg0 != 0) {
        *arg0 = 0;
    }
    sp8 = 0xFF;
    if (fn_801DC258(&spC, &sp8, arg0, arg1[0], arg1[2]) != 0) {
        if (arg4 != 0) {
            *arg4 = sp8;
        }
        arg2[1] = spC;
        arg2[0] = arg1[0];
        arg2[2] = arg1[2];
        return 1;
    }
    return 0;
}

float fn_801DCEC0(void) {
    return lbl_80562B70;
}

extern float lbl_804424B0[];
void fn_801DCEC8(int arg0, float arg1) {
    lbl_804424B0[arg0] = arg1;
}

extern float lbl_804425DC[];
void fn_801DCEDC(int arg0, float arg1) {
    lbl_804425DC[arg0] = arg1;
}

void fn_801DCEF0(void) {

}

extern void *lbl_8055E9A8;
void fn_801DCEF4(void) {
    lbl_8055E9A8 = 0;
}

extern void *lbl_8055E9A8;
void fn_801DCF00(void) {
    lbl_8055E9A8 = 0;
}
extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int fn_801DC258(float *, int *, short *, float, float);
extern int fn_80128670(void);
extern int fn_801D049C(void);
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
