#include <revolution/MTX/mtxtypes.h>
extern float lbl_80561830;
extern double fn_8002F234(float);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80128658(void);

void fn_80160B14(void) {
	fn_80128658();
}

/* Normalize a 2D float vector in place (x = x / |v|, y = y / |v|). */
void fn_80160B18(float *arg0) {
    float temp_f0;
    float temp_f1;
    float temp_f2;
    temp_f0 = arg0[1];
    temp_f1 = arg0[0];
    temp_f2 = lbl_80561830 / (float) fn_8002F234((temp_f1 * temp_f1) + (temp_f0 * temp_f0));
    arg0[0] = arg0[0] * temp_f2;
    arg0[1] = arg0[1] * temp_f2;
}

/* Store the 2D vector difference out = a - b. */
void fn_80160B7C(float *out, float *a, float *b) {
    float x = a[0] - b[0];
    float y = a[1] - b[1];
    out[0] = x;
    out[1] = y;
}

void fn_80160BA0(float *out, float *a, float scale) {
    /* Store the 2D vector scale out = a * scale. */
    float x = a[0] * scale;
    float y = a[1] * scale;
    out[0] = x;
    out[1] = y;
}

void fn_80160BBC(float *out, float *a, float *b) {
    /* Store the 2D vector sum out = a + b. */
    float x = a[0] + b[0];
    float y = a[1] + b[1];
    out[0] = x;
    out[1] = y;
}

float fn_80160BE0(float *arg0, float *arg1) {
    float dx = arg0[1] - arg1[1];
    float dy = arg0[0] - arg1[0];
    return dx * dx + dy * dy;
}
/* Return zero: the default/null value for this accessor stub. */
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
extern float lbl_80561830;
extern double fn_8002F234(float);
