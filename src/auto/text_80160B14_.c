// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80128658(void);

void fn_80160B14(void) {
	fn_80128658();
}

void fn_80160B7C(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] - arg2[0];
    float y = arg1[1] - arg2[1];
    arg0[0] = x;
    arg0[1] = y;
}

void fn_80160BA0(float *arg0, float *arg1, float farg0) {
    arg0[0] = arg1[0] * farg0;
    arg0[1] = arg1[1] * farg0;
}

void fn_80160BBC(float *arg0, float *arg1, float *arg2) {
    arg0[0] = arg1[0] + arg2[0];
    arg0[1] = arg1[1] + arg2[1];
}

#pragma scheduling off
float fn_80160BE0(float *arg0, float *arg1) {
    float dy;
    float sp8;
    float dx = arg0[1] - arg1[1];
    float spC = dx;
    dy = arg0[0] - arg1[0];
    sp8 = dy;
    return dx * dx + dy * dy;
}
#pragma scheduling on
long fn_80160C18(void) {
    return 0;
}

extern float lbl_80561834;
extern float lbl_80561830;
double fn_8002F234(float);
float fn_80160C20(void) {
    return lbl_80561834;
}

void fn_80160C28(void) {
}
