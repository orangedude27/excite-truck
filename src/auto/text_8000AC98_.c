// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8000AC98(void) {
}

int fn_8000AC9C(void) { return 0; }

void fn_8000ACA4(void) {
    return;
}

void fn_8000ACA8(void) {
}

void fn_8000ACAC(void) {
    return;
}

void fn_8000ACB0(void) {
    if (fn_802044E8() == 0) {
        fn_80007238();
    }
}

int fn_802044E8(void);
int fn_80007238();
int fn_80204870(void);
int fn_800074EC(int);
int fn_8000ACDC(int arg0) {
    if (fn_80204870() != 0) {
        return 1;
    }
    return fn_800074EC(arg0);
}

void fn_8000AD20(void) {
}

int fn_8000AD24(void) { return 0; }

int fn_800070DC(void);
void fn_8000AEC4(void) {
    fn_800070DC();
}

void fn_8000B288(void* alarm) {
    fn_801DF110(fn_8000B210(alarm));
}

void fn_8000BD98(void) {
    return;
}

int fn_8000BD9C(int, int, int);
extern float lbl_805601FC, lbl_80560204;
extern char lbl_8034F5F8, lbl_8034F604;
int fn_80230B5C(int *);
int fn_802C8638(int *);
int fn_802C974C(float, float, float);
int fn_80010074(int, int, int *, float, float, float);
int fn_80011A2C(void);
int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
extern int lbl_8034F5B8;
void fn_8000C630(int arg0, int arg1) {
    int i;
    if (arg1 == -1) {
        for (i = 0; i < 4; i++) fn_8000C630(arg0, i);
    } else {
        *(int *)((char *)&lbl_8034F5B8 + arg1 * 8 + 4) = arg0;
    }
}
int fn_8000BD9C(int, int, int);
extern float lbl_805601FC, lbl_80560204;
extern char lbl_8034F5F8, lbl_8034F604;
int fn_80230B5C(int *);
int fn_802C8638(int *);
int fn_802C974C(float, float, float);
int fn_80010074(int, int, int *, float, float, float);
int fn_80011A2C(void);
int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
extern int lbl_8034F5B8;
