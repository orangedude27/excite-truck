// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80561BA8;
extern int lbl_8055E490;
extern int lbl_8055E488;
extern int lbl_8055E48C;
extern void fn_80128670(void*);
extern void fn_8012850C(void*, void*);
extern int fn_8002F37C(void*, int, int, int);
extern char lbl_80331CB8[16];
extern void fn_8017D330(void);
extern void fn_80179E00(void*);
extern void fn_8017B198(void*);
extern void fn_80179D94(void);
extern void fn_8017B2D0(void*, float, float, float, float);
extern void fn_80179D08(void);
extern char lbl_80331CC4[];
extern void PSVECCrossProduct();
extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80558DC4[];
typedef struct Vec { float x, y, z; } Vec;

void *fn_8017B0B0(void *arg0) {
    fn_80179D08();
    *(int *)((char *)arg0 + 0x184) = 0;
    *(char **)arg0 = lbl_80331CC4;
    *((char *)arg0 + 0x1E8) = 0;
    return arg0;
}

void fn_8017B0F8(void *arg0, float *arg1) {
    fn_80179D94();
    *(volatile int *)((char *)arg0 + 0xD0) = 0;
    fn_8017B2D0(arg0, arg1[2], arg1[3], arg1[4], arg1[5]);
    *(int *)((char *)arg0 + 0x184) = 0;
    fn_8017B198(arg0);
}

void fn_8017B164(void *arg0) {
    fn_80179E00(arg0);
    fn_8017B198(arg0);
}

extern float lbl_80561BA8, lbl_80561BAC, lbl_80561BB0, lbl_80561BB4;
void fn_8017B2D0(void *arg0, float a, float b, float c, float d) {
    union MatrixData {
        float f[106];
        unsigned int u[106];
    };
    union MatrixData *matrix = (union MatrixData *)arg0;
    float base;
    float zero;
    float x;
    float factor;
    float y;
    float z;
    float inverse_scale;
    float iy;
    float iz;
    float sa;
    float ix;
    float ia;

    base = *(volatile float *)&lbl_80561BAC;
    zero = *(volatile float *)&lbl_80561BA8;
    x = base * b;
    factor = *(volatile float *)&lbl_80561BB0;
    y = base * c;
    z = base * d;
    x = factor * x;
    matrix->f[0xf8 / 4] = zero;
    y = factor * y;
    z = factor * z;
    matrix->f[0xfc / 4] = zero;
    inverse_scale = *(volatile float *)&lbl_80561BB4;
    y = factor * y;
    z = factor * z;
    matrix->f[0x100 / 4] = zero;
    iy = inverse_scale / y;
    matrix->f[0x108 / 4] = zero;
    iz = inverse_scale / z;
    x = factor * x;
    matrix->f[0x10c / 4] = zero;
    matrix->f[0x110 / 4] = zero;
    matrix->f[0x104 / 4] = iy;
    matrix->f[0x114 / 4] = iz;
    sa = base * a;
    ix = inverse_scale / x;
    ia = inverse_scale / sa;
    matrix->f[0xd4 / 4] = sa;
    matrix->f[0xd8 / 4] = x;
    matrix->f[0xdc / 4] = y;
    matrix->f[0xe0 / 4] = z;
    matrix->f[0xe4 / 4] = ia;
    matrix->f[0xe8 / 4] = ix;
    matrix->f[0xec / 4] = iy;
    matrix->f[0xf0 / 4] = iz;
    matrix->f[0xf4 / 4] = ix;
    /* Copy the completed matrix values into the object's cached integer block. */
    matrix->u[0x148 / 4] = matrix->u[0xf4 / 4];
    matrix->u[0x14c / 4] = matrix->u[0xf8 / 4];
    matrix->u[0x150 / 4] = matrix->u[0xfc / 4];
    matrix->u[0x154 / 4] = matrix->u[0x100 / 4];
    matrix->u[0x158 / 4] = matrix->u[0x104 / 4];
    matrix->u[0x15c / 4] = matrix->u[0x108 / 4];
    matrix->u[0x160 / 4] = matrix->u[0x10c / 4];
    matrix->u[0x164 / 4] = matrix->u[0x110 / 4];
    matrix->u[0x168 / 4] = matrix->u[0x114 / 4];
}

#pragma scheduling invalid_target
void fn_8017B3A8(void *arg0, float *arg1, float *arg2) {
    float delta[3];
    float output[3];

    if (!((float)__fabs(PSVECDotProduct(arg1, arg1)) <= lbl_80558DC4[0])) {
        float a2_0, a2_1, a2_2, d0;
        float x, y, z;

        a2_0 = arg2[0];
        a2_1 = arg2[1];
        d0 = a2_0 - *(float *)((char *)arg0 + 0x60);
        a2_2 = arg2[2];
        delta[0] = d0;
        delta[1] = a2_1 - *(float *)((char *)arg0 + 0x64);
        delta[2] = a2_2 - *(float *)((char *)arg0 + 0x68);
        PSVECCrossProduct(delta, arg1, output);
        x = *(float *)((char *)arg0 + 0x130) + arg1[0];
        y = *(float *)((char *)arg0 + 0x134) + arg1[1];
        z = arg1[2] + *(float *)((char *)arg0 + 0x138);
        *(float *)((char *)arg0 + 0x130) = x;
        *(float *)((char *)arg0 + 0x134) = y;
        *(float *)((char *)arg0 + 0x138) = z;
        *(float *)((char *)arg0 + 0x13C) += output[0];
        *(float *)((char *)arg0 + 0x140) += output[1];
        *(float *)((char *)arg0 + 0x144) += output[2];
    }
}
#pragma scheduling on
void fn_8017B4AC(float *arg0, float *arg1) {
    float x = arg0[0x13C / 4] + arg1[0];
    float y = arg0[0x140 / 4] + arg1[1];
    float z = arg0[0x144 / 4] + arg1[2];
    arg0[0x13C / 4] = x;
    arg0[0x140 / 4] = y;
    arg0[0x144 / 4] = z;
}

#pragma scheduling invalid_target
void fn_8017B4E0(void *arg0, float *arg1, float *arg2, float arg3) {
    float delta[3];
    float output[3];
    float temp_f1;
    float temp_f2;
    float temp_f3;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f7;
    temp_f6 = arg1[0] * arg3;
    temp_f2 = arg1[2] * arg3;
    temp_f7 = *(float *)((char *)arg0 + 0x1A0) + arg3;
    temp_f5 = *(float *)((char *)arg0 + 0x188) + temp_f6;
    temp_f4 = *(float *)((char *)arg0 + 0x18C) + (arg1[1] * arg3);
    temp_f3 = *(float *)((char *)arg0 + 0x190) + temp_f2;
    *(float *)((char *)arg0 + 0x1A0) = temp_f7;
    *(float *)((char *)arg0 + 0x188) = temp_f5;
    temp_f2 = arg2[1];
    *(float *)((char *)arg0 + 0x18C) = temp_f4;
    temp_f1 = arg2[2];
    *(float *)((char *)arg0 + 0x190) = temp_f3;
    delta[0] = arg2[0] - *(float *)((char *)arg0 + 0x60);
    delta[1] = temp_f2 - *(float *)((char *)arg0 + 0x64);
    delta[2] = temp_f1 - *(float *)((char *)arg0 + 0x68);
    PSVECCrossProduct(delta, arg1, output, temp_f1, temp_f2);
    *(float *)((char *)arg0 + 0x194) += output[0] * arg3;
    *(float *)((char *)arg0 + 0x198) += output[1] * arg3;
    *(float *)((char *)arg0 + 0x19C) += output[2] * arg3;
}
#pragma scheduling on
extern void fn_8017B4E0(void *, float *, float *, float);
#pragma scheduling invalid_target
void fn_8017B5D4(void *arg0, int arg1, int arg2, float *arg3, float *arg4, int arg5, float *arg6, int arg7, float arg8) {
    int count;
    int index;
    void *entry;
    if (*(int *)((char *)arg0 + 0x1E4) < 16) {
        if (lbl_8055E488 < lbl_8055E48C) {
            index = lbl_8055E488;
            count = index * 0x28;
            lbl_8055E488 = index + 1;
            entry = (char *)lbl_8055E490 + count;
        } else {
            entry = 0;
        }
        if (entry != 0) {
            *(int *)((char *)entry + 0) = arg1;
            *(int *)((char *)entry + 4) = arg2;
            *(float *)((char *)entry + 8) = arg3[0] * arg8;
            *(float *)((char *)entry + 0xC) = arg3[1] * arg8;
            *(float *)((char *)entry + 0x10) = arg3[2] * arg8;
            if (arg6 != 0) {
                *(float *)((char *)entry + 0x14) = arg6[0];
                *(float *)((char *)entry + 0x18) = arg6[1];
                *(float *)((char *)entry + 0x1C) = arg6[2];
            } else {
                *(float *)((char *)entry + 0x14) = arg4[0];
                *(float *)((char *)entry + 0x18) = arg4[1];
                *(float *)((char *)entry + 0x1C) = arg4[2];
            }
            *(int *)((char *)entry + 0x20) = arg5;
            *(int *)((char *)entry + 0x24) = arg7;
            count = *(int *)((char *)arg0 + 0x1E4);
            *(void **)((char *)arg0 + 0x1A4 + count * 4) = entry;
            *(int *)((char *)arg0 + 0x1E4) = count + 1;
        }
    }
    fn_8017B4E0(arg0, arg3, arg4, arg8);
}
#pragma scheduling on
extern float lbl_80561BA8;
#pragma scheduling off
void fn_8017B6A8(void *arg0) {
    float value = lbl_80561BA8;
    *(int *)((char *)arg0 + 0x1E4) = 0;
    *(float *)((char *)arg0 + 0x188) = value;
    *(float *)((char *)arg0 + 0x18C) = value;
    *(float *)((char *)arg0 + 0x190) = value;
    *(float *)((char *)arg0 + 0x194) = value;
    *(float *)((char *)arg0 + 0x198) = value;
    *(float *)((char *)arg0 + 0x19C) = value;
    *(float *)((char *)arg0 + 0x1A0) = value;
}

extern float PSVECDotProduct(const void *, const void *);
extern void PSVECCrossProduct();
#pragma scheduling on
void fn_8017B6D4(void *arg0, float *arg1, float *arg2) {
    float vector[3];
    register float temp_f1;
    register float temp_f2;
    float delta0;

    temp_f1 = arg2[0];
    temp_f2 = arg2[1];
    delta0 = temp_f1 - *(float *)((char *)arg0 + 0x60);
    temp_f1 = arg2[2];
    vector[0] = delta0;
    vector[1] = temp_f2 - *(float *)((char *)arg0 + 0x64);
    vector[2] = temp_f1 - *(float *)((char *)arg0 + 0x68);
    PSVECCrossProduct((char *)arg0 + 0x124, vector, arg1, temp_f1, temp_f2);
    arg1[0] += *(float *)((char *)arg0 + 0x118);
    arg1[1] += *(float *)((char *)arg0 + 0x11C);
    arg1[2] += *(float *)((char *)arg0 + 0x120);
}
extern void PSVECCrossProduct(const float *, const float *, float *);
#pragma push
#pragma scheduling invalid_target
void fn_8017B778(void *arg0, float *arg1, float *arg2) {
    float vector[3];
    float temp_f1;
    float temp_f2;
    float temp_f0;

    temp_f1 = arg2[0];
    temp_f2 = arg2[1];
    vector[0] = temp_f1 - *(float *)((char *)arg0 + 0x60);
    vector[1] = temp_f2 - *(float *)((char *)arg0 + 0x64);
    temp_f0 = arg2[2];
    vector[2] = temp_f0 - *(float *)((char *)arg0 + 0x68);
    PSVECCrossProduct((const float *)((char *)arg0 + 0x178), vector, arg1);
    arg1[0] += *(float *)((char *)arg0 + 0x16c);
    arg1[1] += *(float *)((char *)arg0 + 0x170);
    arg1[2] += *(float *)((char *)arg0 + 0x174);
}
#pragma pop
extern float lbl_80561BB8, lbl_80561BBC, lbl_80561BC0, lbl_80561BC4, lbl_80561BC8, lbl_80561BCC, lbl_80561BD0, lbl_80561BD4, lbl_80561BD8;
extern void fn_8017D0C8(void *);
extern void fn_8017A578(void *);
extern float fn_80144514(float, float, float, float, float, float);
extern float PSVECMag(const void *);
extern void PSVECNormalize(const void *, void *);
extern double sin(double);
extern double cos(double);
extern void fn_801ADB44(void *, void *);
#pragma scheduling invalid_target
void fn_8017B81C(void *arg0) {
    union { float rotation[9]; float product[9]; } matrixScratch;
    float transpose[9], gravity[3], angle[3], midpoint[3];
    void **var_r29;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f0_5;
    float temp_f0_6;
    float temp_f10;
    float temp_f11;
    float temp_f12;
    float temp_f13;
    float temp_f1;
    float temp_f1_10;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f1_5;
    float temp_f1_6;
    float temp_f1_7;
    float temp_f1_8;
    float temp_f1_9;
    float temp_f24;
    float temp_f24_2;
    float temp_f24_3;
    float temp_f24_4;
    float temp_f24_5;
    float temp_f24_6;
    float temp_f25;
    float temp_f25_2;
    float temp_f25_3;
    float temp_f25_4;
    float temp_f25_5;
    float temp_f26;
    float temp_f26_2;
    float temp_f26_3;
    float temp_f27;
    float temp_f27_2;
    float temp_f27_3;
    float temp_f28;
    float temp_f28_2;
    float temp_f28_3;
    float temp_f29;
    float temp_f29_2;
    float temp_f29_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f30;
    float temp_f30_2;
    float temp_f30_3;
    float temp_f30_4;
    float temp_f31;
    float temp_f31_2;
    float temp_f31_3;
    float temp_f31_4;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f3_5;
    float temp_f3_6;
    float temp_f4;
    float temp_f4_2;
    float temp_f4_3;
    float temp_f4_4;
    float temp_f4_5;
    float temp_f4_6;
    float temp_f4_7;
    float temp_f4_8;
    float temp_f5;
    float temp_f5_2;
    float temp_f5_3;
    float temp_f6;
    float temp_f6_2;
    float temp_f6_3;
    float temp_f6_4;
    float temp_f6_5;
    float temp_f6_6;
    float temp_f6_7;
    float temp_f7;
    float temp_f7_2;
    float temp_f8;
    float temp_f9;
    int temp_r3;
    int temp_r3_2;
    int var_r30;
    int var_r6;
    int var_r8;
    void **temp_r3_3;
    void **var_r0;
    void **var_r3;
    void *temp_r29;
    void *temp_r30;
    void *temp_r30_2;
    void *temp_r30_3;
    void *temp_r3_4;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_7;
    void *temp_r7;
    void *temp_r8;
    void *temp_r9;
    void *var_r29_2;
    void *var_r4;
    void *var_r5;

    temp_f0 = (*(float *)((char *)(arg0) + 0xD4));
    temp_f1 = (*(float *)((char *)(arg0) + 0x130));
    temp_f2 = (*(float *)((char *)(arg0) + 0x134));
    temp_f3 = (*(float *)((char *)(arg0) + 0x138));
    gravity[0] = lbl_80561BA8;
    temp_f4 = lbl_80561BB8 * -temp_f0;
    gravity[1] = temp_f4;
    gravity[2] = lbl_80561BA8;
    temp_f1 += gravity[0];
    temp_f2 += gravity[1];
    temp_f3 += gravity[2];
    (*(float *)((char *)(arg0) + 0x130)) = temp_f1;
    (*(float *)((char *)(arg0) + 0x134)) = temp_f2;
    (*(float *)((char *)(arg0) + 0x138)) = temp_f3;
    var_r29 = (*(void **)((char *)(arg0) + 0xD0));
    while (var_r29 != 0) {
        fn_801ADB44(var_r29, arg0);
        var_r29 = *var_r29;
    }
    temp_r3 = (*(int *)((char *)(arg0) + 0x24));
    if (temp_r3 > 0) {
        var_r0 = (*(void ***)((char *)(arg0) + 0x14));
    } else {
        var_r0 = 0;
    }
    if ((var_r0 != 0) && ((int) (*(unsigned char *)((char *)(arg0) + 0x1E9)) != 0) && ((int) (*(unsigned char *)((char *)(arg0) + 0x1E8)) != 0)) {
        if (temp_r3 > 0) {
            var_r3 = (*(void ***)((char *)(arg0) + 0x14));
        } else {
            var_r3 = 0;
        }
        (*(void (**)(void *))((char *)(*var_r3) + 0x14))(var_r3);
    }
    temp_f1 = (*(float *)((char *)(arg0) + 0x1A0));
    if (!((float) __fabs(temp_f1) <= ((float *)&lbl_80558DC4)[0])) {
        var_r4 = arg0;
        var_r6 = 0;
        temp_f6 = lbl_80561BB4 / temp_f1;
        temp_f25 = (*(float *)((char *)(arg0) + 0x188)) * temp_f6;
        temp_f24 = (*(float *)((char *)(arg0) + 0x18C)) * temp_f6;
        temp_f13 = (*(float *)((char *)(arg0) + 0x190)) * temp_f6;
        temp_f11 = (*(float *)((char *)(arg0) + 0x198)) * temp_f6;
        temp_f12 = (*(float *)((char *)(arg0) + 0x194)) * temp_f6;
        temp_f10 = (*(float *)((char *)(arg0) + 0x19C)) * temp_f6;
        (*(float *)((char *)(arg0) + 0x188)) = temp_f25;
        (*(float *)((char *)(arg0) + 0x18C)) = temp_f24;
        (*(float *)((char *)(arg0) + 0x190)) = temp_f13;
        (*(float *)((char *)(arg0) + 0x194)) = temp_f12;
        (*(float *)((char *)(arg0) + 0x198)) = temp_f11;
        (*(float *)((char *)(arg0) + 0x19C)) = temp_f10;
        (*(float *)((char *)(arg0) + 0x130)) = (float) ((*(float *)((char *)(arg0) + 0x130)) + (temp_f25 * lbl_80561BBC));
        (*(float *)((char *)(arg0) + 0x134)) = (float) ((*(float *)((char *)(arg0) + 0x134)) + (temp_f24 * lbl_80561BBC));
        (*(float *)((char *)(arg0) + 0x138)) = (float) ((*(float *)((char *)(arg0) + 0x138)) + (temp_f13 * lbl_80561BBC));
        (*(float *)((char *)(arg0) + 0x13C)) = (float) ((*(float *)((char *)(arg0) + 0x13C)) + (temp_f12 * lbl_80561BBC));
        (*(float *)((char *)(arg0) + 0x140)) = (float) ((*(float *)((char *)(arg0) + 0x140)) + (temp_f11 * lbl_80561BBC));
        (*(float *)((char *)(arg0) + 0x144)) = (float) ((*(float *)((char *)(arg0) + 0x144)) + (temp_f10 * lbl_80561BBC));
        while (var_r6 < (int) (*(int *)((char *)(arg0) + 0x1E4))) {
            temp_r7 = (*(void **)((char *)(var_r4) + 0x1A4));
            if ((int) (*(int *)((char *)(temp_r7) + 4)) != 0) {
                var_r8 = var_r6 + 1;
                var_r5 = (char *)arg0 + (var_r8 * 4);
                while (var_r8 < (int) (*(int *)((char *)(arg0) + 0x1E4))) {
                    temp_r9 = (*(void **)((char *)(var_r5) + 0x1A4));
                    if ((unsigned int) (*(int *)((char *)(temp_r7) + 4)) == (unsigned int) (*(unsigned int *)((char *)(temp_r9) + 4))) {
                        (*(float *)((char *)(temp_r7) + 8)) = (float) ((*(float *)((char *)(temp_r7) + 8)) + (*(float *)((char *)(temp_r9) + 8)));
                        (*(float *)((char *)(temp_r7) + 0xC)) = (float) ((*(float *)((char *)(temp_r7) + 0xC)) + (*(float *)((char *)(temp_r9) + 0xC)));
                        (*(float *)((char *)(temp_r7) + 0x10)) = (float) ((*(float *)((char *)(temp_r7) + 0x10)) + (*(float *)((char *)(temp_r9) + 0x10)));
                        temp_f4_2 = (*(float *)((char *)(temp_r7) + 0x14));
                        temp_f5 = (*(float *)((char *)(temp_r7) + 0x18));
                        temp_f6_2 = (*(float *)((char *)(temp_r7) + 0x1C));
                        temp_f4_3 = temp_f4_2 + (lbl_80561BC0 * ((*(float *)((char *)(temp_r9) + 0x14)) - temp_f4_2));
                        temp_f1_2 = temp_f5 + (lbl_80561BC0 * ((*(float *)((char *)(temp_r9) + 0x18)) - temp_f5));
                        (*(float *)((char *)(temp_r7) + 0x14)) = temp_f4_3;
                        temp_f0 = temp_f6_2 + (lbl_80561BC0 * ((*(float *)((char *)(temp_r9) + 0x1C)) - temp_f6_2));
                        (*(float *)((char *)(temp_r7) + 0x18)) = temp_f1_2;
                        midpoint[0] = temp_f4_3;
                        (*(float *)((char *)(temp_r7) + 0x1C)) = temp_f0;
                        midpoint[1] = temp_f1_2;
                        temp_r3_2 = (*(int *)((char *)(arg0) + 0x1E4)) - 1;
                        (*(int *)((char *)(arg0) + 0x1E4)) = temp_r3_2;
                        midpoint[2] = temp_f0;
                        (*(void **)((char *)(var_r5) + 0x1A4)) = (void *) (*(void **)((char *)(((char *)arg0 + (temp_r3_2 * 4))) + 0x1A4));
                    }
                    var_r5 = (char *)var_r5 + 4;
                    var_r8 += 1;
                }
            }
            var_r4 = (char *)var_r4 + 4;
            var_r6 += 1;
        }
        temp_f24_2 = lbl_80561BB4;
        var_r29_2 = arg0;
        var_r30 = 0;
        while (var_r30 < (int) (*(int *)((char *)(arg0) + 0x1E4))) {
            temp_r8 = (*(void **)((char *)(var_r29_2) + 0x1A4));
            temp_f1_3 = temp_f24_2 / (*(float *)((char *)(arg0) + 0x1A0));
            (*(float *)((char *)(temp_r8) + 8)) = (float) ((*(float *)((char *)(temp_r8) + 8)) * temp_f1_3);
            (*(float *)((char *)(temp_r8) + 0xC)) = (float) ((*(float *)((char *)(temp_r8) + 0xC)) * temp_f1_3);
            (*(float *)((char *)(temp_r8) + 0x10)) = (float) ((*(float *)((char *)(temp_r8) + 0x10)) * temp_f1_3);
            temp_r3_3 = (*(void ***)((char *)(temp_r8) + 0));
            if (temp_r3_3 != 0) {
                (*(void (**)(void *, void *, void *, int, int, int))((char *)(*temp_r3_3) + 0x24))(temp_r3_3, (char *)temp_r8 + 8, (char *)temp_r8 + 0x14, (*(int *)((char *)(temp_r8) + 0x20)), (*(int *)((char *)(temp_r8) + 0x24)), (*(int *)((char *)(temp_r8) + 4)));
            } else {
                (*(void (**)(void *, void *, void *, int, int, int))((char *)((*(void **)((char *)(arg0) + 0))) + 0x4C))(arg0, (char *)temp_r8 + 8, (char *)temp_r8 + 0x14, (*(int *)((char *)(temp_r8) + 0x20)), (*(int *)((char *)(temp_r8) + 0x24)), (*(int *)((char *)(temp_r8) + 4)));
            }
            var_r29_2 = (char *)var_r29_2 + 4;
            var_r30 += 1;
        }
        (*(void (**)(void *, void *, void *))((char *)((*(void **)((char *)(arg0) + 0))) + 0x50))(arg0, (char *)arg0 + 0x188, (char *)arg0 + 0x194);
        (*(float *)((char *)(arg0) + 0x188)) = (float) lbl_80561BA8;
        (*(float *)((char *)(arg0) + 0x18C)) = (float) lbl_80561BA8;
        (*(float *)((char *)(arg0) + 0x190)) = (float) lbl_80561BA8;
        (*(float *)((char *)(arg0) + 0x194)) = (float) lbl_80561BA8;
        (*(float *)((char *)(arg0) + 0x198)) = (float) lbl_80561BA8;
        (*(float *)((char *)(arg0) + 0x19C)) = (float) lbl_80561BA8;
    }
    temp_f3 = (*(float *)((char *)(arg0) + 0xE4));
    temp_r3_4 = (char *)arg0 + 0x118;
    temp_f0_2 = (*(float *)((char *)(arg0) + 0x130));
    temp_f8 = lbl_80561BC4 * temp_f3;
    temp_f5_2 = (*(float *)((char *)(arg0) + 0x134));
    temp_f4_4 = (*(float *)((char *)(arg0) + 0x138));
    temp_f2 = temp_f0_2 * temp_f3;
    temp_f1_4 = temp_f5_2 * temp_f3;
    temp_f6_3 = (*(float *)((char *)(arg0) + 0x118)) + (temp_f0_2 * temp_f8);
    temp_f5_3 = (*(float *)((char *)(arg0) + 0x11C)) + (temp_f5_2 * temp_f8);
    temp_f4_5 = temp_f4_4 * temp_f8;
    (*(float *)((char *)(arg0) + 0x1A0)) = (float) lbl_80561BA8;
    temp_f3_2 = (*(float *)((char *)(arg0) + 0x120)) + temp_f4_5;
    (*(int *)((char *)(arg0) + 0x1E4)) = 0;
    (*(float *)((char *)(arg0) + 0x118)) = temp_f6_3;
    (*(float *)((char *)(arg0) + 0x11C)) = temp_f5_3;
    (*(float *)((char *)(arg0) + 0x120)) = temp_f3_2;
    (*(float *)((char *)(arg0) + 0x16C)) = temp_f2;
    (*(float *)((char *)(arg0) + 0x170)) = temp_f1_4;
    (*(float *)((char *)(arg0) + 0x174)) = (float) (temp_f4_4 * temp_f3);
    if (PSVECDotProduct(temp_r3_4, temp_r3_4) > lbl_80561BC8) {
        temp_r3_5 = (char *)arg0 + 0x118;
        PSVECNormalize(temp_r3_5, temp_r3_5);
        (*(float *)((char *)(arg0) + 0x118)) = (float) ((*(float *)((char *)(arg0) + 0x118)) * lbl_80561BCC);
        (*(float *)((char *)(arg0) + 0x11C)) = (float) ((*(float *)((char *)(arg0) + 0x11C)) * lbl_80561BCC);
        (*(float *)((char *)(arg0) + 0x120)) = (float) ((*(float *)((char *)(arg0) + 0x120)) * lbl_80561BCC);
    }
    (*(float *)((char *)(arg0) + 0x60)) = (float) ((*(float *)((char *)(arg0) + 0x60)) + ((*(float *)((char *)(arg0) + 0x118)) * lbl_80561BC4));
    (*(float *)((char *)(arg0) + 0x64)) = (float) ((*(float *)((char *)(arg0) + 0x64)) + ((*(float *)((char *)(arg0) + 0x11C)) * lbl_80561BC4));
    (*(float *)((char *)(arg0) + 0x68)) = (float) ((*(float *)((char *)(arg0) + 0x68)) + ((*(float *)((char *)(arg0) + 0x120)) * lbl_80561BC4));
    if ((void *) ((char *)arg0 + 0x178) == (void *) ((char *)arg0 + 0x13C)) {
        temp_f6_4 = (*(float *)((char *)(arg0) + 0x140));
        temp_f0_3 = (*(float *)((char *)(arg0) + 0x13C));
        temp_f7 = (*(float *)((char *)(arg0) + 0x144));
        (*(float *)((char *)(arg0) + 0x178)) = (float) ((temp_f7 * (*(float *)((char *)(arg0) + 0x160))) + ((temp_f0_3 * (*(float *)((char *)(arg0) + 0x148))) + (temp_f6_4 * (*(float *)((char *)(arg0) + 0x154)))));
        (*(float *)((char *)(arg0) + 0x17C)) = (float) ((temp_f7 * (*(float *)((char *)(arg0) + 0x164))) + ((temp_f0_3 * (*(float *)((char *)(arg0) + 0x14C))) + (temp_f6_4 * (*(float *)((char *)(arg0) + 0x158)))));
        (*(float *)((char *)(arg0) + 0x180)) = (float) ((temp_f7 * (*(float *)((char *)(arg0) + 0x168))) + ((temp_f0_3 * (*(float *)((char *)(arg0) + 0x150))) + (temp_f6_4 * (*(float *)((char *)(arg0) + 0x15C)))));
    } else {
        temp_f6_5 = (*(float *)((char *)(arg0) + 0x140));
        temp_f0_4 = (*(float *)((char *)(arg0) + 0x13C));
        temp_f7_2 = (*(float *)((char *)(arg0) + 0x144));
        (*(float *)((char *)(arg0) + 0x178)) = (float) ((temp_f7_2 * (*(float *)((char *)(arg0) + 0x160))) + ((temp_f0_4 * (*(float *)((char *)(arg0) + 0x148))) + (temp_f6_5 * (*(float *)((char *)(arg0) + 0x154)))));
        (*(float *)((char *)(arg0) + 0x17C)) = (float) ((temp_f7_2 * (*(float *)((char *)(arg0) + 0x164))) + ((temp_f0_4 * (*(float *)((char *)(arg0) + 0x14C))) + (temp_f6_5 * (*(float *)((char *)(arg0) + 0x158)))));
        (*(float *)((char *)(arg0) + 0x180)) = (float) ((temp_f7_2 * (*(float *)((char *)(arg0) + 0x168))) + ((temp_f0_4 * (*(float *)((char *)(arg0) + 0x150))) + (temp_f6_5 * (*(float *)((char *)(arg0) + 0x15C)))));
    }
    temp_r3_6 = (char *)arg0 + 0x124;
    temp_f4_6 = (*(float *)((char *)(arg0) + 0x178)) * lbl_80561BC4;
    temp_f1_5 = (*(float *)((char *)(arg0) + 0x180)) * lbl_80561BC4;
    temp_f3_3 = (*(float *)((char *)(arg0) + 0x124)) + temp_f4_6;
    temp_f2_2 = (*(float *)((char *)(arg0) + 0x128)) + ((*(float *)((char *)(arg0) + 0x17C)) * lbl_80561BC4);
    (*(float *)((char *)(arg0) + 0x124)) = temp_f3_3;
    (*(float *)((char *)(arg0) + 0x128)) = temp_f2_2;
    (*(float *)((char *)(arg0) + 0x12C)) = (float) ((*(float *)((char *)(arg0) + 0x12C)) + temp_f1_5);
    if (PSVECDotProduct(temp_r3_6, temp_r3_6) > lbl_80561BD0) {
        temp_r3_7 = (char *)arg0 + 0x124;
        PSVECNormalize(temp_r3_7, temp_r3_7);
        (*(float *)((char *)(arg0) + 0x124)) = (float) ((*(float *)((char *)(arg0) + 0x124)) * lbl_80561BD4);
        (*(float *)((char *)(arg0) + 0x128)) = (float) ((*(float *)((char *)(arg0) + 0x128)) * lbl_80561BD4);
        (*(float *)((char *)(arg0) + 0x12C)) = (float) ((*(float *)((char *)(arg0) + 0x12C)) * lbl_80561BD4);
    }
    angle[0] = (*(float *)((char *)(arg0) + 0x124)) * lbl_80561BC4;
    angle[1] = (*(float *)((char *)(arg0) + 0x128)) * lbl_80561BC4;
    angle[2] = (*(float *)((char *)(arg0) + 0x12C)) * lbl_80561BC4;
    temp_f1_6 = PSVECMag(&angle[0]);
    if (temp_f1_6 > lbl_80561BD8) {
        temp_f4_7 = lbl_80561BB4 / temp_f1_6;
        temp_f31 = temp_f4_7 * angle[0];
        temp_f25_2 = temp_f4_7 * angle[1];
        temp_f24_3 = temp_f4_7 * angle[2];
        temp_f30 = (float) sin(temp_f1_6);
        temp_f9 = (float) cos(temp_f1_6);
        temp_f0_5 = lbl_80561BB4 - temp_f9;
        temp_f3_4 = temp_f30 * temp_f24_3;
        temp_f6_6 = temp_f0_5 * temp_f31;
        temp_f4_8 = temp_f25_2 * temp_f6_6;
        matrixScratch.rotation[0] = temp_f9 + (temp_f0_5 * (temp_f31 * temp_f31));
        temp_f6_7 = temp_f24_3 * temp_f6_6;
        temp_f2_3 = temp_f30 * temp_f25_2;
        matrixScratch.rotation[1] = temp_f4_8 + temp_f3_4;
        temp_f3_5 = temp_f24_3 * (temp_f0_5 * temp_f25_2);
        temp_f0_6 = temp_f30 * temp_f31;
        matrixScratch.rotation[3] = temp_f4_8 - temp_f3_4;
        matrixScratch.rotation[2] = temp_f6_7 - temp_f2_3;
        matrixScratch.rotation[4] = temp_f9 + (temp_f0_5 * (temp_f25_2 * temp_f25_2));
        matrixScratch.rotation[5] = temp_f3_5 + temp_f0_6;
        matrixScratch.rotation[6] = temp_f6_7 + temp_f2_3;
        matrixScratch.rotation[7] = temp_f3_5 - temp_f0_6;
        matrixScratch.rotation[8] = temp_f9 + (temp_f0_5 * (temp_f24_3 * temp_f24_3));
    } else {
        matrixScratch.rotation[1] = lbl_80561BA8;
        matrixScratch.rotation[0] = lbl_80561BB4;
        matrixScratch.rotation[2] = lbl_80561BA8;
        matrixScratch.rotation[3] = lbl_80561BA8;
        matrixScratch.rotation[4] = lbl_80561BB4;
        matrixScratch.rotation[5] = lbl_80561BA8;
        matrixScratch.rotation[6] = lbl_80561BA8;
        matrixScratch.rotation[7] = lbl_80561BA8;
        matrixScratch.rotation[8] = lbl_80561BB4;
    }
    temp_r30 = (char *)arg0 + 0x3C;
    if ((temp_r30 == temp_r30) || (temp_r30 == &matrixScratch.rotation[0])) {
        temp_f31_2 = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 8)));
        temp_f30_2 = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 0x14)));
        temp_f29 = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 0x20)));
        temp_f28 = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 8)));
        temp_f27 = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 0x14)));
        temp_f26 = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 0x20)));
        temp_f25_3 = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 8)));
        temp_f24_4 = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 0x14)));
        temp_f1_7 = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 0x20)));
        (*(float *)((char *)(arg0) + 0x3C)) = temp_f31_2;
        (*(float *)((char *)(temp_r30) + 0xC)) = temp_f30_2;
        (*(float *)((char *)(temp_r30) + 0x18)) = temp_f29;
        (*(float *)((char *)(temp_r30) + 4)) = temp_f28;
        (*(float *)((char *)(temp_r30) + 0x10)) = temp_f27;
        (*(float *)((char *)(temp_r30) + 0x1C)) = temp_f26;
        (*(float *)((char *)(temp_r30) + 8)) = temp_f25_3;
        (*(float *)((char *)(temp_r30) + 0x14)) = temp_f24_4;
        (*(float *)((char *)(temp_r30) + 0x20)) = temp_f1_7;
    } else {
        (*(float *)((char *)(arg0) + 0x3C)) = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 8)));
        (*(float *)((char *)(temp_r30) + 0xC)) = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 0x14)));
        (*(float *)((char *)(temp_r30) + 0x18)) = fn_80144514(matrixScratch.rotation[0], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[3], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[6], (*(float *)((char *)(temp_r30) + 0x20)));
        (*(float *)((char *)(temp_r30) + 4)) = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 8)));
        (*(float *)((char *)(temp_r30) + 0x10)) = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 0x14)));
        (*(float *)((char *)(temp_r30) + 0x1C)) = fn_80144514(matrixScratch.rotation[1], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[4], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[7], (*(float *)((char *)(temp_r30) + 0x20)));
        (*(float *)((char *)(temp_r30) + 8)) = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(arg0) + 0x3C)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 4)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 8)));
        (*(float *)((char *)(temp_r30) + 0x14)) = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(temp_r30) + 0xC)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 0x10)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 0x14)));
        (*(float *)((char *)(temp_r30) + 0x20)) = fn_80144514(matrixScratch.rotation[2], (*(float *)((char *)(temp_r30) + 0x18)), matrixScratch.rotation[5], (*(float *)((char *)(temp_r30) + 0x1C)), matrixScratch.rotation[8], (*(float *)((char *)(temp_r30) + 0x20)));
    }
    transpose[1] = (*(float *)((char *)(arg0) + 0x40));
    temp_r30_2 = (char *)arg0 + 0xF4;
    transpose[0] = (*(float *)((char *)(arg0) + 0x3C));
    temp_f1_8 = transpose[1];
    transpose[2] = (*(float *)((char *)(arg0) + 0x44));
    temp_f3_6 = transpose[2];
    transpose[3] = (*(float *)((char *)(arg0) + 0x48));
    transpose[4] = (*(float *)((char *)(arg0) + 0x4C));
    transpose[5] = (*(float *)((char *)(arg0) + 0x50));
    temp_f2_4 = transpose[5];
    transpose[6] = (*(float *)((char *)(arg0) + 0x54));
    transpose[7] = (*(float *)((char *)(arg0) + 0x58));
    transpose[8] = (*(float *)((char *)(arg0) + 0x5C));
    transpose[1] = transpose[3];
    transpose[3] = temp_f1_8;
    transpose[2] = transpose[6];
    transpose[6] = temp_f3_6;
    transpose[5] = transpose[7];
    transpose[7] = temp_f2_4;
    if ((&matrixScratch.product[0] == &transpose[0]) || (&matrixScratch.product[0] == temp_r30_2)) {
        temp_f31_3 = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[2]);
        temp_f30_3 = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[5]);
        temp_f29_2 = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[8]);
        temp_f28_2 = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[2]);
        temp_f27_2 = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[5]);
        temp_f26_2 = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[8]);
        temp_f25_4 = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[2]);
        temp_f24_5 = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[5]);
        temp_f1_9 = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[8]);
        matrixScratch.product[0] = temp_f31_3;
        matrixScratch.product[3] = temp_f30_3;
        matrixScratch.product[6] = temp_f29_2;
        matrixScratch.product[1] = temp_f28_2;
        matrixScratch.product[4] = temp_f27_2;
        matrixScratch.product[7] = temp_f26_2;
        matrixScratch.product[2] = temp_f25_4;
        matrixScratch.product[5] = temp_f24_5;
        matrixScratch.product[8] = temp_f1_9;
    } else {
        matrixScratch.product[0] = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[2]);
        matrixScratch.product[3] = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[5]);
        matrixScratch.product[6] = fn_80144514((*(float *)((char *)(arg0) + 0xF4)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0xC)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x18)), transpose[8]);
        matrixScratch.product[1] = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[2]);
        matrixScratch.product[4] = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[5]);
        matrixScratch.product[7] = fn_80144514((*(float *)((char *)(temp_r30_2) + 4)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0x10)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x1C)), transpose[8]);
        matrixScratch.product[2] = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[0], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[1], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[2]);
        matrixScratch.product[5] = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[3], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[4], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[5]);
        matrixScratch.product[8] = fn_80144514((*(float *)((char *)(temp_r30_2) + 8)), transpose[6], (*(float *)((char *)(temp_r30_2) + 0x14)), transpose[7], (*(float *)((char *)(temp_r30_2) + 0x20)), transpose[8]);
    }
    temp_r29 = (char *)arg0 + 0x148;
    temp_r30_3 = (char *)arg0 + 0x3C;
    if ((temp_r29 == &matrixScratch.product[0]) || (temp_r29 == temp_r30_3)) {
        temp_f24_6 = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[2]);
        temp_f25_5 = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[5]);
        temp_f26_3 = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[8]);
        temp_f27_3 = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[2]);
        temp_f28_3 = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[5]);
        temp_f29_3 = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[8]);
        temp_f31_4 = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[2]);
        temp_f30_4 = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[5]);
        temp_f1_10 = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[8]);
        (*(float *)((char *)(arg0) + 0x148)) = temp_f24_6;
        (*(float *)((char *)(temp_r29) + 0xC)) = temp_f25_5;
        (*(float *)((char *)(temp_r29) + 0x18)) = temp_f26_3;
        (*(float *)((char *)(temp_r29) + 4)) = temp_f27_3;
        (*(float *)((char *)(temp_r29) + 0x10)) = temp_f28_3;
        (*(float *)((char *)(temp_r29) + 0x1C)) = temp_f29_3;
        (*(float *)((char *)(temp_r29) + 8)) = temp_f31_4;
        (*(float *)((char *)(temp_r29) + 0x14)) = temp_f30_4;
        (*(float *)((char *)(temp_r29) + 0x20)) = temp_f1_10;
    } else {
        (*(float *)((char *)(arg0) + 0x148)) = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[2]);
        (*(float *)((char *)(temp_r29) + 0xC)) = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[5]);
        (*(float *)((char *)(temp_r29) + 0x18)) = fn_80144514((*(float *)((char *)(arg0) + 0x3C)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0xC)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x18)), matrixScratch.product[8]);
        (*(float *)((char *)(temp_r29) + 4)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[2]);
        (*(float *)((char *)(temp_r29) + 0x10)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[5]);
        (*(float *)((char *)(temp_r29) + 0x1C)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 4)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0x10)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x1C)), matrixScratch.product[8]);
        (*(float *)((char *)(temp_r29) + 8)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[0], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[1], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[2]);
        (*(float *)((char *)(temp_r29) + 0x14)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[3], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[4], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[5]);
        (*(float *)((char *)(temp_r29) + 0x20)) = fn_80144514((*(float *)((char *)(temp_r30_3) + 8)), matrixScratch.product[6], (*(float *)((char *)(temp_r30_3) + 0x14)), matrixScratch.product[7], (*(float *)((char *)(temp_r30_3) + 0x20)), matrixScratch.product[8]);
    }
    (*(float *)((char *)(arg0) + 0x130)) = (float) lbl_80561BA8;
    (*(float *)((char *)(arg0) + 0x134)) = (float) lbl_80561BA8;
    (*(float *)((char *)(arg0) + 0x138)) = (float) lbl_80561BA8;
    (*(float *)((char *)(arg0) + 0x13C)) = (float) lbl_80561BA8;
    (*(float *)((char *)(arg0) + 0x140)) = (float) lbl_80561BA8;
    (*(float *)((char *)(arg0) + 0x144)) = (float) lbl_80561BA8;
    fn_8017A578(arg0);
    fn_8017D0C8(arg0);
}
#pragma scheduling on
void fn_8017C7BC(void) {

}

void fn_8017C7C0(void) {

}

void fn_8017C7C4(void) {

}

typedef unsigned int u32;
typedef float f32;
extern void fn_8017A580(u32, u32, u32, u32, u32, u32);
void fn_8017CFFC(void* arg0, u32* arg1, f32* arg2, f32* arg3, u32 arg_sp0) {
    volatile u32 *src = (volatile u32 *)arg1;
    f32 *vec1 = arg2;
    f32 *vec2 = arg3;
    u32 t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    f32 f0, f1, f2, f3, f4, f5;

    t0 = src[0];
    t1 = src[1];
    t2 = src[2];
    t3 = src[3];
    t4 = src[4];
    t5 = src[5];
    t6 = src[6];
    t7 = src[7];
    t8 = src[8];
    t9 = src[9];
    t10 = src[10];
    t11 = src[11];

    *(u32*)((char*)arg0 + 0x3C) = t0;
    *(u32*)((char*)arg0 + 0x40) = t1;
    *(u32*)((char*)arg0 + 0x44) = t2;
    *(u32*)((char*)arg0 + 0x48) = t3;
    *(u32*)((char*)arg0 + 0x4C) = t4;
    *(u32*)((char*)arg0 + 0x50) = t5;
    *(u32*)((char*)arg0 + 0x54) = t6;
    *(u32*)((char*)arg0 + 0x58) = t7;
    *(u32*)((char*)arg0 + 0x5C) = t8;
    *(u32*)((char*)arg0 + 0x60) = t9;
    *(u32*)((char*)arg0 + 0x64) = t10;
    *(u32*)((char*)arg0 + 0x68) = t11;

    ((void (*)(void *))fn_8017A580)(arg0);

    f5 = vec1[0];
    f4 = vec1[1];
    f3 = vec1[2];
    f2 = vec2[0];
    f1 = vec2[1];
    f0 = vec2[2];

    *(f32*)((char*)arg0 + 0x118) = f5;
    *(f32*)((char*)arg0 + 0x11C) = f4;
    *(f32*)((char*)arg0 + 0x120) = f3;
    *(f32*)((char*)arg0 + 0x124) = f2;
    *(f32*)((char*)arg0 + 0x128) = f1;
    *(f32*)((char*)arg0 + 0x12C) = f0;
}

extern unsigned int fn_801B60F4(void *, float);
extern void fn_801B6428(unsigned int, void *);
extern void fn_801B63E0(unsigned int, void *);
void fn_8017D0C8(void *arg0) {
    unsigned int next = fn_801B60F4((char *)arg0 + 0x60, *(float *)((char *)arg0 + 0x2C));
    unsigned int old = *(unsigned int *)((char *)arg0 + 0x184);
    if (next != old) {
        if (old != 0) fn_801B6428(old, arg0);
        *(unsigned int *)((char *)arg0 + 0x184) = next;
        if (next != 0) fn_801B63E0(next, arg0);
    }
}

#pragma dont_inline on
void fn_8017D140(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}
#pragma dont_inline reset

extern void fn_8017A028(void);
extern float lbl_80561BDC;
#pragma scheduling invalid_target
void fn_8017D160(void *arg0, unsigned char *arg1, unsigned char *arg2, int *arg3, int *arg4, float farg0) {
    float first[3];
    float second[3];
    float deltaZ;
    float deltaY;
    float deltaX;
    float scale;
    volatile float *output = (volatile float *)((char *)arg0 + 0x118);
    *(int *)((char *)arg0 + 0x1E4) = 0;
    fn_8017A028();
    fn_8017D140((unsigned char *)first, arg1 + 0x14, 0xC);
    fn_8017D140((unsigned char *)second, arg2 + 0x14, 0xC);
    deltaZ = second[2] - first[2];
    deltaY = second[1] - first[1];
    deltaX = second[0] - first[0];
    output[2] = first[2] + farg0 * deltaZ;
    output[1] = first[1] + farg0 * deltaY;
    output[0] = first[0] + farg0 * deltaX;
    *(volatile float *)((char *)arg0 + 0x16C) = deltaX;
    *(volatile float *)((char *)arg0 + 0x170) = deltaY;
    scale = lbl_80561BDC;
    *(volatile float *)((char *)arg0 + 0x170) = deltaY * scale;
    *(volatile float *)((char *)arg0 + 0x16C) = deltaX * scale;
    *(volatile float *)((char *)arg0 + 0x174) = deltaZ * scale;
    *arg4 = 0x20;
    *arg3 = 0x20;
}
extern void fn_8017A804(void);
int fn_8017D274(void *arg0, void *arg1) {
    fn_8017A804();
    *(float *)((char *)arg1 + 0x14) = *(float *)((char *)arg0 + 0x118);
    *(float *)((char *)arg1 + 0x18) = *(float *)((char *)arg0 + 0x11C);
    *(float *)((char *)arg1 + 0x1C) = *(float *)((char *)arg0 + 0x120);
    return 0x20;
}

#pragma dont_inline on
void fn_8017D2C8(void *arg0, float *arg1, float *arg2) {
    fn_8017B3A8(arg0, arg1, arg2);
}
#pragma dont_inline reset

void fn_8017D2CC(int arg0) {
    int (*create)(void *, void *, int, int, int) =
        (int (*)(void *, void *, int, int, int))fn_8002F37C;
    void *(*prepare)(void *, void *) = (void *(*)(void *, void *))fn_8012850C;
    lbl_8055E48C = arg0;
    lbl_8055E488 = 0;
    lbl_8055E490 = create(prepare((char *)(arg0 * 0x28 + 0x10), lbl_80331CB8),
                          fn_8017D330, 0, 0x28, arg0);
}

void fn_8017D330(void) {

}

void fn_8017D334(void) {
    int value = lbl_8055E490;
    lbl_8055E488 = 0;
    lbl_8055E48C = 0;
    if (value != 0) fn_80128670((char*)value - 0x10);
}

void fn_8017D358(void) {

}

int fn_8017D35C(void) { return 0x20; }

unsigned int fn_8017D364(void) { return 1; }

void fn_8017D36C(void) {

}

