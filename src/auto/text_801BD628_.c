// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801BD784(void) {

}

void fn_801BD788(void) {

}

void fn_801BD78C(void) {

}

void fn_801BDA70(void) {
    fn_80279D40();
}

extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
void fn_801BEDA8(int *arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    *arg0 = lbl_8055E794;
    *arg1 = lbl_8055E798;
    *arg2 = lbl_8055E79C;
    *arg3 = lbl_8055E7A4;
    *arg4 = lbl_8055E78C;
}

void fn_801BF0C4(void *arg0, void *arg1, int arg2) {
    if (fn_801E9E78(arg2, arg0, arg1) == 0) {
        ((float *)arg1)[0] = lbl_80562838;
        ((float *)arg1)[1] = lbl_8056283C;
        ((float *)arg1)[2] = lbl_80562838;
        ((float *)arg0)[1] = lbl_805628A4;
    }
}

void fn_801BF12C(float *arg0, float *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}

void fn_801BF150(void *arg0, float farg0, float farg1, float farg2, float farg3) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
    ((float *)arg0)[3] = farg3;
}

void GXInitLightAttnA_801BF188(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

void fn_801BF198(void *arg0, void *arg1) {
    float temp_f0 = ((float *)arg1)[0];
    float temp_f1 = ((float *)arg1)[1];
    float temp_f2 = ((float *)arg1)[2];
    ((float *)arg0)[1] = temp_f1;
    ((float *)arg0)[0] = temp_f0;
    ((float *)arg0)[2] = temp_f2;
}

void fn_801BF1B4(void) {

}
extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
