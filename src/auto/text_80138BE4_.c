// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E100;
extern float lbl_80558DC4;
extern float lbl_805613BC;
extern float lbl_805613B8;
void fn_80138F38(void *);
#pragma dont_inline on
int fn_80138BE4(float arg0, float arg1) {
    return (arg0 * arg1) < lbl_805613B8;
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_80138BFC(float arg0) {
    float a = __fabsf(arg0);
    float b = lbl_805613BC * lbl_80558DC4;
    return a <= b;
}
#pragma dont_inline reset

extern float lbl_805613C0;
extern float lbl_805613C8;
extern float lbl_805613D0;
extern int fn_80138C28(void *, float *, float *);
#pragma dont_inline fn_80138BFC
#pragma dont_inline fn_80138BE4
float fn_80138DF4(void *arg0) { return 0.0f; }
void fn_80138F38(void *arg0) {
    float sp8;
    struct {
        int a;
        int b;
        int c;
        float d;
        float e;
        float f;
    } sp10;
    register float x;
    register float y;
    register float ratio;
    register float square;
    register float product;
    register float value;

    if (*(float *)((char *)arg0 + 0x10) > lbl_805613B8 &&
        *(float *)((char *)arg0 + 0x14) < lbl_805613B8 &&
        fn_80138C28(arg0, &sp8, 0)) {
        x = *(float *)((char *)arg0 + 0x10);
        y = *(float *)((char *)arg0 + 0x14);
        ratio = -x / y;
        if (ratio <= sp8) {
            square = ratio * ratio;
            product = ratio * x;
            value = *(float *)((char *)arg0 + 0xC);
            value += product;
            value += (lbl_805613C0 * y) * square;
            sp10.a = ((int *)arg0)[0];
            sp10.b = ((int *)arg0)[1];
            sp10.c = ((int *)arg0)[2];
            sp10.d = value;
            sp10.e = lbl_805613B8;
            sp10.f = lbl_805613B8;
            fn_80138DF4(&sp10);
            lbl_8055E100 += 6;
            return;
        }
    }
    fn_80138DF4(arg0);
}

void fn_80139030(void *arg0) {
    lbl_8055E100 = -6;
    fn_80138F38(arg0);
}
