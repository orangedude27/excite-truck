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
#pragma push
#pragma scheduling invalid_target
#pragma optimize_for_size on
#pragma use_lmw_stmw off
float fn_80138DF4(void *arg0) {
    float spC;
    float sp8;
    float temp_f1;
    float temp_f1_2;
    float temp_f2;
    float temp_f3;
    float temp_f3_2;
    float var_f31;
    float var_f4;

    if (fn_80138BFC(*(float *)((char *)arg0 + 0xC) - *(float *)arg0) == 0) {
        if (fn_80138BFC(*(float *)((char *)arg0 + 0x14) - *(float *)((char *)arg0 + 8)) == 0) {
            if (fn_80138C28(arg0, &spC, &sp8) != 0) {
                var_f4 = spC;
                temp_f1 = (*(float *)((char *)arg0 + 0x10) + (var_f4 * *(float *)((char *)arg0 + 0x14))) - *(float *)((char *)arg0 + 4);
                if (var_f4 > lbl_805613D0) {
                } else {
                    var_f4 = lbl_805613D0;
                }
                var_f31 = temp_f1 / var_f4;
                lbl_8055E100 = -5;
            } else {
                var_f31 = sp8;
                lbl_8055E100 = -4;
            }
        } else {
            temp_f2 = *(float *)((char *)arg0 + 0xC) - *(float *)arg0;
            temp_f1_2 = *(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 4);
            temp_f3 = temp_f1_2 * temp_f1_2;
            var_f31 = temp_f3 / (lbl_805613C8 * temp_f2);
            if (fn_80138BE4(temp_f1_2, temp_f2) != 0) {
                var_f31 = -var_f31;
            }
            temp_f3_2 = *(float *)((char *)arg0 + 0xC);
            if (fn_80138BE4(*(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 4), temp_f3_2 - *(float *)arg0) != 0) {
                lbl_8055E100 = -3;
            } else {
                lbl_8055E100 = -2;
            }
        }
    } else {
        var_f31 = lbl_805613B8;
        lbl_8055E100 = -1;
    }
    return var_f31;
}
#pragma pop
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
