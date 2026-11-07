#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
typedef struct { float m[12]; } Matrix8018;
extern void PSVECCrossProduct(float *, float *, int *);
extern float PSVECDotProduct(int *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(int);
extern void fn_80015A20(void *, void *);
extern void fn_80015B20(float *, int *, float *);
extern int fn_80129D18(int, int);
extern void fn_8014452C(int *, float, float, float);
extern void fn_8017B6D4(void *, float *, float *, float, float);
extern void fn_8017B778(void *, float *, float *);
extern void fn_8018BFA0(void *, float *, int *, int, float, float);
extern float lbl_80561F88, lbl_80561F90, lbl_80561F94, lbl_80561F98, lbl_80561F9C, lbl_80561FA0, lbl_80561FA4, lbl_80561FA8, lbl_80561FAC, lbl_80561FB0, lbl_80561FB4, lbl_80561FB8, lbl_80561FBC, lbl_80561FC0, lbl_80561FC4;
typedef struct Vec_8018 { float x, y, z; } Vec_8018;
static inline void matVec_8018(Vec_8018 *dest, const float *m, const Vec_8018 *v) {
    dest->x = m[0] * v->x + m[3] * v->y + m[6] * v->z;
    dest->y = m[1] * v->x + m[4] * v->y + m[7] * v->z;
    dest->z = m[2] * v->x + m[5] * v->y + m[8] * v->z;
}
static inline Vec_8018 matVecRet_8018(const float *m, const Vec_8018 *v) {
    Vec_8018 r;
    r.x = m[0] * v->x + m[3] * v->y + m[6] * v->z;
    r.y = m[1] * v->x + m[4] * v->y + m[7] * v->z;
    r.z = m[2] * v->x + m[5] * v->y + m[8] * v->z;
    return r;
}
static inline void matVecCopy_8018(Vec_8018 *dest, const float *m, Vec_8018 *src) {
    *dest = *src;
    dest->x = m[0] * dest->x + m[3] * dest->y + m[6] * dest->z;
    dest->y = m[1] * dest->x + m[4] * dest->y + m[7] * dest->z;
    dest->z = m[2] * dest->x + m[5] * dest->y + m[8] * dest->z;
}
static inline void matVecAlias_8018(Vec_8018 *dest, const float *m, const Vec_8018 *src) {
    if (dest == src) {
        float tx = m[0] * src->x + m[3] * src->y + m[6] * src->z;
        float ty = m[1] * src->x + m[4] * src->y + m[7] * src->z;
        float tz = m[2] * src->x + m[5] * src->y + m[8] * src->z;
        dest->x = tx;
        dest->y = ty;
        dest->z = tz;
    } else {
        dest->x = m[0] * src->x + m[3] * src->y + m[6] * src->z;
        dest->y = m[1] * src->x + m[4] * src->y + m[7] * src->z;
        dest->z = m[2] * src->x + m[5] * src->y + m[8] * src->z;
    }
}

#pragma push
#pragma processor 750
extern float fn_80144514(float, float, float, float, float, float);
#pragma push
#pragma processor 750
void fn_8018BFA0(void *out0, float *a, int *b0, int arg3, float arg4, float arg5) {
    float *out = (float *)out0;
    float *b = (float *)b0;
    float x0, x1, x2, x3, x4, x5, x7, x6, x8;
    Vec_8018 scratch;
    if (out == b || out == a) {
        x0 = fn_80144514(a[0], b[0], a[3], b[1], a[6], b[2]);
        x1 = fn_80144514(a[0], b[3], a[3], b[4], a[6], b[5]);
        x2 = fn_80144514(a[0], b[6], a[3], b[7], a[6], b[8]);
        x3 = fn_80144514(a[1], b[0], a[4], b[1], a[7], b[2]);
        x4 = fn_80144514(a[1], b[3], a[4], b[4], a[7], b[5]);
        x5 = fn_80144514(a[1], b[6], a[4], b[7], a[7], b[8]);
        x7 = fn_80144514(a[2], b[0], a[5], b[1], a[8], b[2]);
        x6 = fn_80144514(a[2], b[3], a[5], b[4], a[8], b[5]);
        x8 = fn_80144514(a[2], b[6], a[5], b[7], a[8], b[8]);
        out[0] = x0; out[3] = x1; out[6] = x2; out[1] = x3; out[4] = x4; out[7] = x5; out[2] = x7; out[5] = x6; out[8] = x8;
    } else {
        out[0] = fn_80144514(a[0], b[0], a[3], b[1], a[6], b[2]);
        out[3] = fn_80144514(a[0], b[3], a[3], b[4], a[6], b[5]);
        out[6] = fn_80144514(a[0], b[6], a[3], b[7], a[6], b[8]);
        out[1] = fn_80144514(a[1], b[0], a[4], b[1], a[7], b[2]);
        out[4] = fn_80144514(a[1], b[3], a[4], b[4], a[7], b[5]);
        out[7] = fn_80144514(a[1], b[6], a[4], b[7], a[7], b[8]);
        out[2] = fn_80144514(a[2], b[0], a[5], b[1], a[8], b[2]);
        out[5] = fn_80144514(a[2], b[3], a[5], b[4], a[8], b[5]);
        out[8] = fn_80144514(a[2], b[6], a[5], b[7], a[8], b[8]);
    }
    matVecAlias_8018(&scratch, a, (Vec_8018 *)(b + 9));
    out[9] = a[9] + scratch.x;
    out[10] = a[10] + scratch.y;
    out[11] = a[11] + scratch.z;
    matVecAlias_8018(&scratch, out, (Vec_8018 *)(b + 9));
    out[9] -= scratch.x;
    out[10] -= scratch.y;
    out[11] -= scratch.z;
}
#pragma pop

void fn_8018C50C(void) {

}

void fn_8018C510(void) {

}

extern float lbl_80332840[16];
extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern float PSQUATMultiply(void *, void *);
extern float lbl_80562038;
extern float lbl_8056203C;
extern float lbl_80562040;
extern char lbl_80332758[];
static inline void matVecAliasV_8018(Vec_8018 *dest, const float *m, const Vec_8018 *src) {
    if (dest == src) {
        float tx = src->y * m[3] + src->x * m[0] + src->z * m[6];
        float ty = src->y * m[4] + src->x * m[1] + src->z * m[7];
        float tz = src->y * m[5] + src->x * m[2] + src->z * m[8];
        dest->x = tx;
        dest->y = ty;
        dest->z = tz;
    } else {
        dest->x = src->y * m[3] + src->x * m[0] + src->z * m[6];
        dest->y = src->y * m[4] + src->x * m[1] + src->z * m[7];
        dest->z = src->y * m[5] + src->x * m[2] + src->z * m[8];
    }
}
typedef struct { char b[0x290]; } Blob290_8018;
typedef struct { float a, b; int c, d; unsigned char e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17; } Blob22_8018;
extern float lbl_80561F78, lbl_80561F7C, lbl_80561F80, lbl_80561F84;
static inline float Chan_8018F2C0(unsigned char v) {
    float t = (lbl_80561F88 < (((float)v - lbl_80561F74) / lbl_80562038)) ? lbl_80561F88 : (((float)v - lbl_80561F74) / lbl_80562038);
    t = (t > lbl_80561F74) ? t : lbl_80561F74;
    return lbl_8056203C + t * lbl_80562040;
}
#pragma dont_inline on
#pragma scheduling invalid_target
int fn_8018C514(void *arg0, void *arg1) {
    float min = lbl_80561F70;
    int best = 0;
    int i = 1;
    int offset = 0x34;
    int *count = (int *)((char *)arg0 + 0x26C);
    while (i < *count) {
        float value = PSQUATMultiply(arg1, (char *)arg0 + offset + 0x20);
        if (value < min) {
            min = value;
            best = i;
        }
        offset += 0x34;
        i++;
    }
    return best;
}
#pragma dont_inline reset

extern void *memset(void *, int, unsigned long);
extern int fn_801E2CCC(int, void *, void *);
extern void fn_80279B28(void *);
extern void fn_80279CD8(void *);
extern void fn_802E317C(void *, ...);
extern void *fn_8001285C(int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8018C5A0(char *arg0, char *arg1) {
    char *base = lbl_80332758;
    char *p19;
    char *p20;
    int i;
    int j;
    char *p30;
    Vec_8018 v;
    Vec_8018 zero;
    void *sp8;
    float f31, f30;

    memset(arg0 + 0x152C, 0, 0x900);
    f31 = lbl_80561F74;
    p19 = base + 0xE8;
    f30 = lbl_80561F78;
    p20 = arg0 + 0x152C;
    for (i = 0; i < 0x11; i++, p19 += 0x40, p20 += 0x80) {
        if (fn_801E2CCC(M2C_FIELD(arg0, int *, 0x59C), M2C_FIELD(p19, void **, 4), p20) != 0) {
            float *m = M2C_FIELD(p20, float **, 0);
            matVecAliasV_8018(&v, m, (Vec_8018 *)(p19 + 0x24));
            v.x += m[9];
            v.y += m[10];
            v.z += m[11];
            M2C_FIELD(p20, int *, 4) = fn_8018C514(arg0, &v);
            zero.x = f31;
            zero.y = f31;
            zero.z = f31;
            m = M2C_FIELD(p20, float **, 0);
            matVecAliasV_8018(&v, m, &zero);
            v.x += m[9];
            v.y += m[10];
            v.z += m[11];
            M2C_FIELD(p20, int *, 8) = fn_8018C514(arg0, &v);
            M2C_FIELD(p20, float *, 0x14) = f30;
        }
    }
    M2C_FIELD(arg0, int *, 0x5F8) = *M2C_FIELD(arg0, int **, 0x26C);
    {
        float a = M2C_FIELD(arg0, float *, 0x314);
        float r = lbl_80561F7C / (lbl_80561F80 * M2C_FIELD(arg1, float *, 8));
        M2C_FIELD(arg0, float *, 0x5F4) = r;
        if (a >= lbl_80561F84) {
            M2C_FIELD(arg0, float *, 0x5F4) = r * a;
        } else {
            M2C_FIELD(arg0, float *, 0x5F4) = fabs(a);
        }
    }
    if (M2C_FIELD(arg0, int *, 0x1F0) == 0x50) {
        void *o = M2C_FIELD(fn_8001285C(*(int *)__AXFXGetLfoSinTable_801769CC(0)), void **, 0x20);
        float t = (*(float (**)(void *, void *, float))(*(char **)o + 0x28))(o, base + 0x680, lbl_80561F88);
        M2C_FIELD(arg0, float *, 0x5F4) = M2C_FIELD(arg0, float *, 0x5F4) * t;
    }
    M2C_FIELD(arg0, float *, 0x5F4) = M2C_FIELD(arg0, float *, 0x5F4) * lbl_80561F8C;
    if (M2C_FIELD(arg0, int *, 0x328) != 0) {
        fn_80279B28(arg0 + 0x1E44);
    } else {
        fn_80279CD8(arg0 + 0x1E44);
    }
    *(Blob290_8018 *)(arg0 + 0x20F8) = *(Blob290_8018 *)(arg0 + 0x1E44);
    {
        Blob22_8018 *d = (Blob22_8018 *)(arg0 + 0x2388);
        Blob22_8018 *s = (Blob22_8018 *)(arg0 + 0x20D4);
        d->a = s->a;
        d->b = s->b;
        d->c = s->c;
        d->d = s->d;
        d->e0 = s->e0; d->e1 = s->e1; d->e2 = s->e2; d->e3 = s->e3;
        d->e4 = s->e4; d->e5 = s->e5; d->e6 = s->e6; d->e7 = s->e7;
        d->e8 = s->e8; d->e9 = s->e9; d->e10 = s->e10; d->e11 = s->e11;
        d->e12 = s->e12; d->e13 = s->e13; d->e14 = s->e14; d->e15 = s->e15;
        d->e16 = s->e16; d->e17 = s->e17;
    }
    for (j = 0; j < 16; j++) {
        M2C_FIELD(arg0, unsigned char *, 0x1E2C + j) = 0xFF;
    }
    p30 = base + 0x5B0;
    for (j = 0; j < 0xD; j++, p30 += 0x10) {
        char *s4;
        char *t26;
        sp8 = 0;
        s4 = M2C_FIELD(p30, char **, 0);
        t26 = arg0 + M2C_FIELD(p30, int *, 4);
        if (s4[0] == 0x24) {
            if (s4[1] == 0x57) {
                M2C_FIELD(t26, char *, 0x1E2C) = fn_8018C514(arg0, arg0 + (s4[2] - 0x30) * 0x74 + 0x23DC);
            } else {
                fn_802E317C(base + 0x694);
            }
        }
        if (fn_801E2CCC(M2C_FIELD(arg0, int *, 0x59C), M2C_FIELD(p30, void **, 0), &sp8) != 0) {
            M2C_FIELD(t26, char *, 0x1E2C) = fn_8018C514(arg0, (char *)sp8 + 0x24);
        }
    }
}
#pragma pop
void fn_8018CB3C(char *arg0) {
    float force[3];
    float rotation[12];
    float transform[12];
    float scaleMatrix[12];
    float origin[3];
    float world[3];
    float velocity[3];
    float delta[3];
    float localAxis[3];
    float worldAxis[3];
    float rotated[3];
    float matrix[16];
    register char *var_r19;
    float var_f1_2;
    float var_f1;
    float var_f0_3;
    float var_f0_2;
    float var_f0;
    float temp_r6;
    register float temp_f8_4;
    register float temp_f8_3;
    register float temp_f8_2;
    register float temp_f8;
    register float temp_f7_4;
    register float temp_f7_3;
    register float temp_f7_2;
    register float temp_f7;
    register float temp_f6_3;
    register float temp_f6_2;
    register float temp_f6;
    register float temp_f5_4;
    register float temp_f5_3;
    register float temp_f5_2;
    register float temp_f5;
    register float temp_f4_3;
    register float temp_f4_2;
    register float temp_f4;
    register float temp_f3_5;
    register float temp_f3_4;
    register float temp_f3_3;
    register float temp_f3_2;
    register float temp_f3;
    register float temp_f31;
    register float temp_f30;
    register float temp_f2_9;
    register float temp_f2_8;
    register float temp_f2_7;
    register float temp_f2_6;
    register float temp_f2_5;
    register float temp_f2_4;
    register float temp_f2_3;
    register float temp_f2_2;
    register float temp_f2_10;
    register float temp_f2;
    register float temp_f29;
    register float temp_f28;
    register float temp_f27;
    register float temp_f26;
    register float temp_f25;
    register float temp_f24;
    register float temp_f23;
    register float temp_f22;
    register float temp_f21;
    register float temp_f20;
    register float temp_f1_7;
    register float temp_f1_6;
    register float temp_f1_5;
    register float temp_f1_4;
    register float temp_f1_3;
    register float temp_f1_2;
    register float temp_f1;
    register float temp_f19;
    register float temp_f18;
    register float temp_f17;
    register float temp_f16;
    register float temp_f0_5;
    register float temp_f0_4;
    register float temp_f0_3;
    register float temp_f0_2;
    register float temp_f0;
    int temp_r3_10;
    int temp_r6_2;
    int temp_r6_3;
    register int var_r18;
    char *temp_r3;
    char *temp_r3_2;
    char *temp_r3_3;
    char *temp_r3_4;
    char *temp_r3_5;
    char *temp_r3_6;
    char *temp_r3_7;
    char *temp_r3_8;
    char *temp_r3_9;
    void *temp_r5;
    register char *var_r20;

    temp_f27 = lbl_80561F74;
    temp_f17 = lbl_80561F90;
    temp_f18 = lbl_80561F94;
    var_r20 = arg0 + 0x152C;
    temp_f19 = lbl_80561F98;
    temp_f20 = lbl_80561F9C;
    var_r19 = (char *)&lbl_80332840;
    temp_f21 = lbl_80561FA0;
    temp_f22 = lbl_80561FA8;
    temp_f23 = lbl_80561FA4;
    temp_f24 = lbl_80561FAC;
    temp_f25 = lbl_80561FB0;
    temp_f26 = lbl_80561F88;
    temp_f28 = lbl_80561FB4;
    temp_f29 = lbl_80561FB8;
    temp_f30 = lbl_80561FBC;
    temp_f16 = lbl_80561FC4;
    temp_f31 = lbl_80561FC0;
    var_r18 = 0;
    do {
        temp_r5 = M2C_FIELD(var_r20, char **, 0);
        if ((temp_r5 != 0) && ((int) M2C_FIELD(var_r20, int *, 0x7C) == 2)) {
            temp_r6_2 = M2C_FIELD(temp_r5, int *, 0);
            temp_r6_3 = M2C_FIELD(temp_r5, int *, 4);
            *(int *)&matrix[0] = temp_r6_2;
            *(int *)&matrix[1] = temp_r6_3;
            *(int *)&matrix[2] = M2C_FIELD(temp_r5, int *, 8);
            *(int *)&matrix[3] = M2C_FIELD(temp_r5, int *, 0xC);
            *(int *)&matrix[4] = M2C_FIELD(temp_r5, int *, 0x10);
            *(int *)&matrix[5] = M2C_FIELD(temp_r5, int *, 0x14);
            *(int *)&matrix[6] = M2C_FIELD(temp_r5, int *, 0x18);
            *(int *)&matrix[7] = M2C_FIELD(temp_r5, int *, 0x1C);
            *(int *)&matrix[8] = M2C_FIELD(temp_r5, int *, 0x20);
            *(int *)&matrix[9] = M2C_FIELD(temp_r5, int *, 0x24);
            *(int *)&matrix[10] = M2C_FIELD(temp_r5, int *, 0x28);
            *(int *)&matrix[11] = M2C_FIELD(temp_r5, int *, 0x2C);
            temp_f3 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3;
            temp_f1 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3;
            force[0] = temp_f2;
            force[1] = temp_f1;
            force[2] = M2C_FIELD(var_r19, float *, 0x14) * temp_f3;
            fn_80015A20((int *)scaleMatrix, &force[0]);
            fn_80015B20(&matrix[0], (int *)scaleMatrix, &matrix[0]);
            if (&force[0] == (void *) (var_r19 + 0x18)) {
                temp_f7 = M2C_FIELD(var_r19, float *, 0x1C);
                temp_f2_2 = M2C_FIELD(var_r19, float *, 0x18);
                temp_f8 = M2C_FIELD(var_r19, float *, 0x20);
                force[0] = (temp_f8 * matrix[6]) + ((temp_f2_2 * matrix[0]) + (temp_f7 * matrix[3]));
                force[1] = (temp_f8 * matrix[7]) + ((temp_f2_2 * matrix[1]) + (temp_f7 * matrix[4]));
                force[2] = (temp_f8 * matrix[8]) + ((temp_f2_2 * matrix[2]) + (temp_f7 * matrix[5]));
            } else {
                temp_f7_2 = M2C_FIELD(var_r19, float *, 0x1C);
                temp_f2_3 = M2C_FIELD(var_r19, float *, 0x18);
                temp_f8_2 = M2C_FIELD(var_r19, float *, 0x20);
                force[0] = (temp_f8_2 * matrix[6]) + ((temp_f2_3 * matrix[0]) + (temp_f7_2 * matrix[3]));
                force[1] = (temp_f8_2 * matrix[7]) + ((temp_f2_3 * matrix[1]) + (temp_f7_2 * matrix[4]));
                force[2] = (temp_f8_2 * matrix[8]) + ((temp_f2_3 * matrix[2]) + (temp_f7_2 * matrix[5]));
            }
            force[0] += matrix[9];
            force[1] += matrix[10];
            force[2] += matrix[11];
            temp_r3 = M2C_FIELD(var_r20, char **, 0);
            temp_r3_2 = temp_r3 + 0x24;
            if ((void *)&origin[0] == temp_r3_2) {
                temp_f7_3 = M2C_FIELD(temp_r3_2, float *, 4);
                temp_f2_4 = M2C_FIELD(temp_r3, float *, 0x24);
                temp_f8_3 = M2C_FIELD(temp_r3_2, float *, 8);
                origin[0] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x54)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x3C)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x48)));
                origin[1] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x58)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x40)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x4C)));
                origin[2] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x5C)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x44)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                origin[0] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x54)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x3C)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x48)));
                origin[1] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x58)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x40)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x4C)));
                origin[2] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x5C)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x44)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x50)));
            }
            origin[0] += M2C_FIELD(arg0, float *, 0x60);
            origin[1] += M2C_FIELD(arg0, float *, 0x64);
            origin[2] += M2C_FIELD(arg0, float *, 0x68);
            if (&world[0] == &force[0]) {
                world[0] = (force[2] * M2C_FIELD(arg0, float *, 0x54)) + ((force[0] * M2C_FIELD(arg0, float *, 0x3C)) + (force[1] * M2C_FIELD(arg0, float *, 0x48)));
                world[1] = (force[2] * M2C_FIELD(arg0, float *, 0x58)) + ((force[0] * M2C_FIELD(arg0, float *, 0x40)) + (force[1] * M2C_FIELD(arg0, float *, 0x4C)));
                world[2] = (force[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((force[0] * M2C_FIELD(arg0, float *, 0x44)) + (force[1] * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                world[0] = (force[2] * M2C_FIELD(arg0, float *, 0x54)) + ((force[0] * M2C_FIELD(arg0, float *, 0x3C)) + (force[1] * M2C_FIELD(arg0, float *, 0x48)));
                world[1] = (force[2] * M2C_FIELD(arg0, float *, 0x58)) + ((force[0] * M2C_FIELD(arg0, float *, 0x40)) + (force[1] * M2C_FIELD(arg0, float *, 0x4C)));
                world[2] = (force[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((force[0] * M2C_FIELD(arg0, float *, 0x44)) + (force[1] * M2C_FIELD(arg0, float *, 0x50)));
            }
            temp_f2_5 = world[1];
            temp_f1_2 = world[2];
            world[0] += M2C_FIELD(arg0, float *, 0x60);
            world[1] = temp_f2_5 + M2C_FIELD(arg0, float *, 0x64);
            world[2] = temp_f1_2 + M2C_FIELD(arg0, float *, 0x68);
            fn_8017B6D4(arg0, &velocity[0], &world[0], temp_f1_2, temp_f2_5);
            fn_8017B778(arg0, &force[0], &origin[0]);
            temp_f2_6 = force[0] * temp_f18;
            temp_f1_3 = (force[1] + temp_f17) * temp_f18;
            temp_f6 = world[0] - origin[0];
            force[0] = temp_f2_6;
            temp_f5 = world[1] - origin[1];
            delta[0] = temp_f6;
            temp_f3_2 = world[2] - origin[2];
            delta[1] = temp_f5;
            delta[2] = temp_f3_2;
            force[1] = temp_f1_3;
            force[2] *= temp_f18;
            if (fn_80129D18(4, 4) < 3) {
                force[1] += velocity[1] * temp_f19;
                force[0] += velocity[0] * temp_f19;
                force[2] += velocity[2] * temp_f19;
            }
            PSVECCrossProduct(&delta[0], &force[0], (int *)force);
            temp_r3_3 = M2C_FIELD(var_r20, char **, 0);
            if (&localAxis[0] == (void *) (var_r19 + 0xC)) {
                temp_f7_4 = M2C_FIELD(var_r19, float *, 0x10);
                temp_f2_7 = M2C_FIELD(var_r19, float *, 0xC);
                temp_f8_4 = M2C_FIELD(var_r19, float *, 0x14);
                localAxis[0] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x18)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 0)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0xC)));
                localAxis[1] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x1C)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 4)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0x10)));
                localAxis[2] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x20)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 8)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0x14)));
            } else {
                temp_f4 = M2C_FIELD(var_r19, float *, 0x10);
                temp_f3_3 = M2C_FIELD(var_r19, float *, 0xC);
                temp_f5_2 = M2C_FIELD(var_r19, float *, 0x14);
                localAxis[0] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x18)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 0)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0xC)));
                localAxis[1] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x1C)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 4)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0x10)));
                localAxis[2] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x20)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 8)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0x14)));
            }
            if (&worldAxis[0] == &localAxis[0]) {
                worldAxis[0] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x54)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x3C)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x48)));
                worldAxis[1] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x58)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x40)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x4C)));
                worldAxis[2] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x44)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                worldAxis[0] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x54)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x3C)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x48)));
                worldAxis[1] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x58)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x40)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x4C)));
                worldAxis[2] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x44)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x50)));
            }
            var_f1 = -PSVECDotProduct((int *)force, &worldAxis[0]);
            if (temp_f20 < var_f1) {
                var_f1 = temp_f20;
            }
            if (var_f1 > temp_f21) {

            } else {
                var_f1 = temp_f21;
            }
            temp_f1_4 = M2C_FIELD(var_r20, float *, 0x10) + var_f1;
            var_f0 = temp_f1_4 - (temp_f23 * (temp_f22 * temp_f1_4));
            M2C_FIELD(var_r20, float *, 0x10) = var_f0;
            if (temp_f24 < var_f0) {
                var_f0 = temp_f24;
            }
            if (var_f0 > temp_f25) {

            } else {
                var_f0 = temp_f25;
            }
            M2C_FIELD(var_r20, float *, 0x10) = var_f0;
            temp_f0 = M2C_FIELD(var_r20, float *, 0xC);
            if (temp_f0 > temp_f26) {
                M2C_FIELD(var_r20, float *, 0xC) = temp_f26;
                var_f0_2 = M2C_FIELD(var_r20, float *, 0x10);
                if (var_f0_2 < temp_f27) {

                } else {
                    var_f0_2 = temp_f27;
                }
                M2C_FIELD(var_r20, float *, 0x10) = var_f0_2;
            } else if (temp_f0 < temp_f28) {
                if ((M2C_FIELD(__AXFXGetLfoSinTable_801769CC(0), int *, 4) & 0x4000) && (M2C_FIELD(var_r20, float *, 0x10) < temp_f27) && (fn_80129D18(4, 0xA) < 1)) {
                    M2C_FIELD(var_r20, float *, 0xC) = temp_f27;
                    M2C_FIELD(var_r20, float *, 0x10) = temp_f27;
                    M2C_FIELD(var_r20, int *, 0x7C) = 0;
                } else {
                    M2C_FIELD(var_r20, float *, 0x10) = (float) (M2C_FIELD(var_r20, float *, 0x10) + (temp_f22 * (temp_f29 * (temp_f28 - M2C_FIELD(var_r20, float *, 0xC)))));
                }
            }
            var_f0_3 = M2C_FIELD(var_r20, float *, 0xC) + (temp_f22 * M2C_FIELD(var_r20, float *, 0x10));
            M2C_FIELD(var_r20, float *, 0xC) = var_f0_3;
            if (var_f0_3 > temp_f30) {

            } else {
                var_f0_3 = temp_f30;
            }
            M2C_FIELD(var_r20, float *, 0xC) = var_f0_3;
            temp_r3_4 = M2C_FIELD(var_r20, char **, 0);
            temp_f6_2 = M2C_FIELD(temp_r3_4, float *, 0x24);
            force[0] = temp_f6_2;
            temp_f5_3 = M2C_FIELD(temp_r3_4, float *, 0x28);
            force[1] = temp_f5_3;
            temp_f4_2 = M2C_FIELD(temp_r3_4, float *, 0x2C);
            force[2] = temp_f4_2;
            temp_r3_5 = arg0 + (M2C_FIELD(var_r20, int *, 8) * 0xC);
            force[0] = temp_f6_2 + M2C_FIELD(temp_r3_5, float *, 0xD94);
            force[1] = temp_f5_3 + M2C_FIELD(temp_r3_5, float *, 0xD98);
            force[2] = temp_f4_2 + M2C_FIELD(temp_r3_5, float *, 0xD9C);
            temp_f3_4 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2_8 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3_4;
            temp_f1_5 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3_4;
            temp_f0_2 = M2C_FIELD(var_r19, float *, 0x14) * temp_f3_4;
            force[0] = temp_f2_8;
            force[1] = temp_f1_5;
            force[2] = temp_f0_2;
            temp_r3_6 = M2C_FIELD(var_r20, char **, 0);
            if (&rotated[0] == &force[0]) {
                rotated[0] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x18)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 0)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0xC)));
                rotated[1] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x1C)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 4)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x10)));
                rotated[2] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x20)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 8)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x14)));
            } else {
                rotated[0] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x18)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 0)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0xC)));
                rotated[1] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x1C)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 4)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x10)));
                rotated[2] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x20)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 8)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x14)));
            }
            fn_8014452C((int *)rotation, rotated[1], rotated[0], rotated[2]);
            M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
            M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
            M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
            M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
            M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
            M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
            M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
            M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
            M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
            temp_r6_2 = M2C_FIELD(var_r20, int *, 0x3C);
            M2C_FIELD(var_r20, int *, 0x6C) = temp_r6_2;
            M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
            M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            fn_8018BFA0(var_r20 + 0x18, (float *)(arg0 + 0x70), (int *)rotation, temp_r6_2, 0, 0);
            if ((int) M2C_FIELD(var_r20, unsigned char *, 0x78) == 0) {
                M2C_FIELD(var_r20, unsigned char *, 0x78) = 1U;
                M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
                M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
                M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
                M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
                M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
                M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
                M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
                M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
                M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
                M2C_FIELD(var_r20, int *, 0x6C) = (int) M2C_FIELD(var_r20, int *, 0x3C);
                M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
                M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            }
            M2C_FIELD(var_r20, float *, 0x10) = temp_f27;
        } else if ((temp_r5 != 0) && ((int) M2C_FIELD(var_r20, int *, 0x7C) == 4)) {
            temp_f0_3 = M2C_FIELD(var_r20, float *, 0xC) + (temp_f22 * M2C_FIELD(var_r20, float *, 0x10));
            M2C_FIELD(var_r20, float *, 0xC) = temp_f0_3;
            if ((temp_f0_3 < temp_f27) || (M2C_FIELD(var_r20, float *, 0xC) > M2C_FIELD(var_r20, float *, 0x14))) {
                var_f1_2 = M2C_FIELD(var_r20, float *, 0x14);
                temp_f0_4 = M2C_FIELD(var_r20, float *, 0xC);
                if (var_f1_2 < temp_f0_4) {

                } else {
                    var_f1_2 = temp_f0_4;
                }
                if (var_f1_2 > temp_f27) {

                } else {
                    var_f1_2 = temp_f27;
                }
                M2C_FIELD(var_r20, float *, 0xC) = (float) ((temp_f31 * var_f1_2) - M2C_FIELD(var_r20, float *, 0xC));
                M2C_FIELD(var_r20, float *, 0x10) = (float) -M2C_FIELD(var_r20, float *, 0x10);
            }
            temp_r3_7 = M2C_FIELD(var_r20, char **, 0);
            temp_f6_3 = M2C_FIELD(temp_r3_7, float *, 0x24);
            force[0] = temp_f6_3;
            temp_f5_4 = M2C_FIELD(temp_r3_7, float *, 0x28);
            force[1] = temp_f5_4;
            temp_f4_3 = M2C_FIELD(temp_r3_7, float *, 0x2C);
            force[2] = temp_f4_3;
            temp_r3_8 = arg0 + (M2C_FIELD(var_r20, int *, 8) * 0xC);
            force[0] = temp_f6_3 + M2C_FIELD(temp_r3_8, float *, 0xD94);
            force[1] = temp_f5_4 + M2C_FIELD(temp_r3_8, float *, 0xD98);
            force[2] = temp_f4_3 + M2C_FIELD(temp_r3_8, float *, 0xD9C);
            temp_f3_5 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2_9 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3_5;
            temp_f1_6 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3_5;
            temp_f0_5 = M2C_FIELD(var_r19, float *, 0x14) * temp_f3_5;
            force[0] = temp_f2_9;
            force[1] = temp_f1_6;
            force[2] = temp_f0_5;
            temp_r3_9 = M2C_FIELD(var_r20, char **, 0);
            if (&rotated[0] == &force[0]) {
                rotated[0] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x18)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 0)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0xC)));
                rotated[1] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x1C)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 4)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x10)));
                rotated[2] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x20)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 8)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x14)));
            } else {
                rotated[0] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x18)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 0)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0xC)));
                rotated[1] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x1C)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 4)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x10)));
                rotated[2] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x20)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 8)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x14)));
            }
            fn_8014452C((int *)rotation, rotated[1], rotated[0], rotated[2]);
            M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
            M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
            M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
            M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
            M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
            M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
            M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
            M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
            M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
            temp_r3_10 = M2C_FIELD(var_r20, int *, 0x3C);
            M2C_FIELD(var_r20, int *, 0x6C) = temp_r3_10;
            M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
            M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(0), int *, 0x10) & 2) {
                transform[0] = M2C_FIELD(arg0, float *, 0x70);
                transform[1] = M2C_FIELD(arg0, float *, 0x74);
                temp_f2_10 = transform[0] * temp_f16;
                transform[2] = M2C_FIELD(arg0, float *, 0x78);
                temp_f1_7 = transform[1] * temp_f16;
                *(int *)&transform[3] = M2C_FIELD(arg0, int *, 0x7C);
                *(int *)&transform[4] = M2C_FIELD(arg0, int *, 0x80);
                *(int *)&transform[5] = M2C_FIELD(arg0, int *, 0x84);
                *(int *)&transform[6] = M2C_FIELD(arg0, int *, 0x88);
                *(int *)&transform[7] = M2C_FIELD(arg0, int *, 0x8C);
                *(int *)&transform[8] = M2C_FIELD(arg0, int *, 0x90);
                temp_r6_3 = M2C_FIELD(arg0, int *, 0x94);
                *(int *)&transform[9] = temp_r6_3;
                *(int *)&transform[10] = M2C_FIELD(arg0, int *, 0x98);
                *(int *)&transform[11] = M2C_FIELD(arg0, int *, 0x9C);
                transform[0] = temp_f2_10;
                transform[1] = temp_f1_7;
                transform[2] *= temp_f16;
                fn_8018BFA0(var_r20 + 0x18, &transform[0], (int *)rotation, temp_r6_3, temp_f1_7, temp_f2_10);
                M2C_FIELD(var_r20, float *, 0x18) = (float) (M2C_FIELD(var_r20, float *, 0x18) * temp_f16);
                M2C_FIELD(var_r20, float *, 0x1C) = (float) (M2C_FIELD(var_r20, float *, 0x1C) * temp_f16);
                M2C_FIELD(var_r20, float *, 0x20) = (float) (M2C_FIELD(var_r20, float *, 0x20) * temp_f16);
            } else {
                fn_8018BFA0(var_r20 + 0x18, (float *)(arg0 + 0x70), (int *)rotation, 0, 0, 0);
            }
            if ((int) M2C_FIELD(var_r20, unsigned char *, 0x78) == 0) {
                M2C_FIELD(var_r20, unsigned char *, 0x78) = 1U;
                M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
                M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
                M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
                M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
                M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
                M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
                M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
                M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
                M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
                M2C_FIELD(var_r20, int *, 0x6C) = (int) M2C_FIELD(var_r20, int *, 0x3C);
                M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
                M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            }
        }
        var_r18 += 1;
        var_r20 += 0x80;
        var_r19 += 0x40;
    } while (var_r18 < 0x11);
}

extern float lbl_80561FC8, lbl_80561FCC, lbl_80561FD8, lbl_80561FDC, lbl_80561FE0, lbl_80561FE4, lbl_80561FE8, lbl_8055E460;
extern float lbl_80561FD0, lbl_80561FD4, lbl_80558DC4;
void fn_8018DA5C(char *arg0, char *arg1) {
    int n; float *v = (float *)(arg0 + 0xd94); char *out = arg1; char *p = arg0;
    float smooth=lbl_80561FC8, inv=lbl_80561FCC;
    for (n=0; n < M2C_FIELD(arg0,int*,0x5f8); n++) {
        float x = M2C_FIELD(p,float*,0xd94) * smooth;
        float y = M2C_FIELD(p,float*,0xd98) * smooth;
        float z = M2C_FIELD(p,float*,0xd9c) * smooth;
        M2C_FIELD(p,float*,0xd94) = x + M2C_FIELD(p,float*,0x5fc) * inv;
        M2C_FIELD(p,float*,0xd98) = y + M2C_FIELD(p,float*,0x600) * inv;
        M2C_FIELD(p,float*,0xd9c) = z + M2C_FIELD(p,float*,0x604) * inv;
        p += 12;
        M2C_FIELD(out,float*,0x2e0)=v[0]; M2C_FIELD(out,float*,0x2e4)=v[1]; M2C_FIELD(out,float*,0x2e8)=v[2];
        v+=3; out+=12;
    }
    if (M2C_FIELD(arg0,unsigned char*,0x26e0)) {
        float cached=lbl_80561F74;
        float f = M2C_FIELD(arg0,float*,0x26e8);
        float bias = lbl_80561FD0 * M2C_FIELD(arg0,float*,0x26e4);
        float scale = lbl_80561FD4 * M2C_FIELD(arg0,float*,0x26ec);
        float mult;
        f = f > lbl_80561FD8 ? f : lbl_80561FD8;
        mult=lbl_80561F8C*f;
        out=arg1+12;
        for (n=1;n<M2C_FIELD(arg0,int*,0x5f8);n++,out+=12) {
            float x,y,z,dist,t;
            char *entry=M2C_FIELD(arg0,char**,0x26c)+n*0x34;
            float ex=M2C_FIELD(entry,float*,0x20), ey=M2C_FIELD(entry,float*,0x24), ez=M2C_FIELD(entry,float*,0x28);
            dist=(float)fabs(ez);
            t=dist-lbl_80561FE0;
            z=cached+lbl_80561FE4*ez*scale;
            x=cached+scale*(lbl_80561FDC*(ex*t));
            y=cached+scale*(lbl_80561FDC*(ey*t));
            t=lbl_80561FE8-dist;
            t = t > cached ? t : cached;
            y += mult*(ey*t);
            t=lbl_80561FE8-(float)fabs(ez);
            t = t > cached ? t : cached;
            x += bias*t;
            M2C_FIELD(out,float*,0x2e0)=x; M2C_FIELD(out,float*,0x2e4)=y; M2C_FIELD(out,float*,0x2e8)=z;
        }
    }
    M2C_FIELD(arg1,int*,0x29c) |= M2C_FIELD(arg0,int*,0x1e40);
    M2C_FIELD(arg1,int*,0xa78)=0;
    {
        float blend=lbl_8055E460, one=lbl_80561F88;
        char *entry=arg0+0x152c;
        char *table=(char *)lbl_80332840;
        for (n=0;n<17;n++,entry+=0x80,table+=0x40) {
            int state;
            if (!M2C_FIELD(entry,int*,0)) continue;
            state=M2C_FIELD(entry,int*,0x7c);
            if (!state || state==1) continue;
            if (state==3) M2C_FIELD(arg1,int*,0x29c) &= ~(1 << M2C_FIELD(table,int*,8));
            state=M2C_FIELD(entry,int*,0x7c);
            if (state==2 || state==4) {
                int index=M2C_FIELD(arg1,int*,0xa78)++;
                char *dest=arg1+index*0x34;
                if ((float)fabs(blend-one) <= lbl_80558DC4) {
                    *(Matrix8018*)(dest+0xa7c) = M2C_FIELD(entry,Matrix8018*,0x18);
                } else {
                    Matrix8018 tmp;
                    float *a=(float*)(entry+0x18), *b=(float*)(entry+0x48), *d=tmp.m;
                    int k;
                    for(k=0;k<12;k++) d[k]=b[k]+blend*(a[k]-b[k]);
                    *(Matrix8018*)(dest+0xa7c)=tmp;
                }
                M2C_FIELD(dest,int*,0xaac)=1<<M2C_FIELD(table,int*,8);
            }
        }
    }
}

#pragma scheduling on
extern float PSVECMag(void *);
extern void PSVECNormalize(float *, float *);
extern float lbl_80561F74, lbl_80561F88, lbl_80561FC0;
extern float lbl_80561FEC, lbl_80561FF0, lbl_80561FF4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8018DE94(void *arg0, int arg1, float *arg2, int arg3, int arg4) {
    char *base = (char *)arg0;
    char *record = *(char **)(base + 0x26C) + arg1 * 0x34;
    register float factor;
    register float speed;
    float gain;
    float damping;
    float scaled[3];
    int normal[3];
    float center[3];
    float sum[3];
    float delta[3];
    float next[3];
    float basis[3];
    float *velocity;
    char *velBase;
    float dot;
    float clampLo;
    float clampHi;
    float tmp0;
    float tmp1;
    float tmp2;
    int id;
    int other;
    int selected;
    int offset;
    int i;
    char *link;
    char *manager;
    char *otherRecord;
    float *otherVelocity;

    gain = lbl_80561FF0 * *(float *)(record + 0x30);
    factor = lbl_80561FEC * gain;
    speed = PSVECMag(arg2);
    scaled[1] = arg2[1] * factor;
    scaled[0] = arg2[0] * factor;
    scaled[2] = arg2[2] * factor;
    scaled[1] = scaled[1] < lbl_80561F74 ? lbl_80561F74 : scaled[1];
    damping = lbl_80561FC0;
    velBase = base + *(int *)(record + 4) * 0xC;
    velocity = (float *)(velBase + 0x5FC);
    velocity[0] = velocity[0] + scaled[0] * damping;
    velocity[1] = velocity[1] + scaled[1] * damping;
    velocity[2] = velocity[2] + scaled[2] * damping;
    dot = PSVECDotProduct((int *)velocity, (float *)(record + 0x20));
    if (dot > lbl_80561F74) {
        normal[0] = *(int *)(record + 0x20);
        normal[1] = *(int *)(record + 0x24);
        normal[2] = *(int *)(record + 0x28);
        PSVECNormalize((float *)normal, (float *)normal);
        dot = -PSVECDotProduct((int *)velocity, (float *)normal);
        velocity[0] = velocity[0] + ((float *)normal)[0] * dot;
        velocity[1] = velocity[1] + ((float *)normal)[1] * dot;
        velocity[2] = velocity[2] + ((float *)normal)[2] * dot;
    }
    clampHi = *(float *)(record + 8);
    clampLo = *(float *)(record + 0x14);
    velocity[0] = velocity[0] < clampLo ? clampLo : (velocity[0] > clampHi ? clampHi : velocity[0]);
    clampHi = *(float *)(record + 0xC);
    clampLo = *(float *)(record + 0x18);
    velocity[1] = velocity[1] < clampLo ? clampLo : (velocity[1] > clampHi ? clampHi : velocity[1]);
    clampHi = *(float *)(record + 0x10);
    clampLo = *(float *)(record + 0x1C);
    velocity[2] = velocity[2] < clampLo ? clampLo : (velocity[2] > clampHi ? clampHi : velocity[2]);
    if (arg4 <= 2) {
        register float limit;
        register float unit;
        register float zero;
        float distance;
        float scale;
        center[0] = *(float *)(record + 0x20) + *(float *)(base + arg1 * 0xC + 0x5FC);
        center[1] = *(float *)(record + 0x24) + *(float *)(base + arg1 * 0xC + 0x600);
        center[2] = *(float *)(record + 0x28) + *(float *)(base + arg1 * 0xC + 0x604);
        limit = lbl_80561FF4;
        unit = lbl_80561F88;
        zero = lbl_80561F74;
        i = 0;
        offset = 0;
        while (i < *(int *)(*(char **)(base + 0x26C) + 0x20F0)) {
            manager = *(char **)(base + 0x26C);
            link = *(char **)(manager + 0x20EC) + offset;
            id = *(int *)link;
            other = *(int *)(link + 4);
            if ((id == arg1 && other != arg3) || (other == arg1 && id != arg3)) {
                selected = (id == arg1) ? other : id;
                otherRecord = manager + selected * 0x34;
                otherVelocity = (float *)(base + selected * 0xC + 0x5FC);
                sum[0] = *(float *)(otherRecord + 0x20) + otherVelocity[0];
                sum[1] = *(float *)(otherRecord + 0x24) + otherVelocity[1];
                sum[2] = *(float *)(otherRecord + 0x28) + otherVelocity[2];
                delta[0] = sum[0] - center[0];
                delta[1] = sum[1] - center[1];
                delta[2] = sum[2] - center[2];
                distance = PSVECMag(delta);
                if (distance > limit) {
                    scale = unit / distance;
                    delta[0] = delta[0] * scale;
                    delta[1] = delta[1] * scale;
                    delta[2] = delta[2] * scale;
                    dot = -PSVECDotProduct((int *)delta, arg2);
                    tmp0 = arg2[0] + delta[0] * dot;
                    tmp1 = arg2[1] + delta[1] * dot;
                    tmp2 = arg2[2] + delta[2] * dot;
                    next[0] = tmp0;
                    next[1] = tmp1;
                    next[2] = tmp2;
                    tmp0 = next[0] * *(float *)(link + 0xC);
                    tmp1 = next[1] * *(float *)(link + 0xC);
                    tmp2 = next[2] * *(float *)(link + 0xC);
                    next[0] = tmp0;
                    next[1] = tmp1;
                    next[2] = tmp2;
                    dot = PSVECDotProduct((int *)arg2, delta);
                    scale = dot * *(float *)(link + 8);
                    tmp0 = next[0] + delta[0] * scale;
                    tmp1 = next[1] + delta[1] * scale;
                    tmp2 = next[2] + delta[2] * scale;
                    next[0] = tmp0;
                    next[1] = tmp1;
                    next[2] = tmp2;
                    scale = speed * *(float *)(link + 0x10);
                    basis[0] = zero;
                    basis[1] = unit;
                    basis[2] = zero;
                    next[0] = next[0] + basis[0] * scale;
                    next[1] = next[1] + basis[1] * scale;
                    next[2] = next[2] + basis[2] * scale;
                } else {
                    tmp0 = arg2[0] * *(float *)(link + 8);
                    tmp1 = arg2[1] * *(float *)(link + 8);
                    tmp2 = arg2[2] * *(float *)(link + 8);
                    next[0] = tmp0;
                    next[1] = tmp1;
                    next[2] = tmp2;
                }
                fn_8018DE94(arg0, selected, next, arg1, arg4 + 1);
            }
            offset += 0x14;
            i++;
        }
    }
}
#pragma pop
void fn_8018E330(void *arg0) {
    void *manager;
    void *object;
    register float f0;
    register float f1;
    manager = (void *)fn_801B83A0();
    ((void (*)(void *))(*(void **)((char *)*(void **)manager + 0xA4)))(arg0);
    fn_80161A38(0, *(int *)((char *)arg0 + 0x1EC), 0);
    fn_801DFF1C(*(int *)((char *)arg0 + 0x1EC));
    f0 = lbl_80561F74;
    f1 = lbl_80561F8C;
    *(float *)((char *)arg0 + 0x258C) = f0;
    object = *(void **)((char *)arg0 + 0x270);
    *(float *)((char *)arg0 + 0x2690) = f1;
    *(float *)((char *)arg0 + 0x25BC) = f0;
    *(float *)((char *)arg0 + 0x26A0) = lbl_8055E3C8;
    object = ((void *(*)(void *))(*(void **)((char *)*(void **)object + 0x10)))(object);
    *(int *)((char *)arg0 + 0x26A4) = *(int *)((char *)object + 4);
    f0 = lbl_80561F74;
    *(float *)((char *)arg0 + 0x2588) = f0;
    *(float *)((char *)arg0 + 0x25A0) = f0;
    *(char *)((char *)arg0 + 0x259D) = 0;
    *(char *)((char *)arg0 + 0x259C) = 0;
    *(int *)((char *)arg0 + 0x2638) = 0;
    *(int *)((char *)arg0 + 0x2644) = 0;
    *(float *)((char *)arg0 + 0x2630) = f0;
    *(float *)((char *)arg0 + 0x262C) = f0;
    *(float *)((char *)arg0 + 0x2628) = f0;
}
#pragma scheduling on
float PSVECSquareDistance(float *, float *);         /* extern */
void *__AXFXGetLfoSinTable_801769CC();              /* extern */
void *fn_8017960C(int);                             /* extern */
int fn_801796CC(int, float *, int);       /* extern */
int fn_80189BDC(float, float, float, float, float, float);      /* extern */
int fn_8018A174(void *);                        /* extern */
void fn_8018F76C(void *, int);                   /* extern */
int fn_801B8610(int, int);                      /* extern */
void fn_801BF2A4(void *, int, float *, void *, void *, int, void *, float, float, float); /* extern */
void fn_802E30C8(void *, int);                   /* extern */
extern float lbl_80558DC4;
extern float lbl_8055A460;
extern float lbl_80561F98;
extern float lbl_80561FC4;
extern float lbl_80561FD0;
extern float lbl_80561FD4;
extern float lbl_80561FEC;
extern float lbl_80561FF4;
extern float lbl_80561FF8;
extern float lbl_80561FFC;
extern float lbl_80562000;
extern float lbl_80562004;
extern float lbl_80562008;
extern float lbl_8056200C;
extern float lbl_80562010;
extern float lbl_80562014;
extern float lbl_80562018;
extern float lbl_8056201C;
extern float lbl_80562020;
extern float lbl_80562024;
extern float lbl_80562028;
extern float lbl_8056202C;
extern float lbl_80562030;
extern float lbl_80562034;
#pragma push
#pragma ppc_psq_save off
void fn_8018E3EC(char *arg0, float *arg1, void *arg2, int arg3, int arg4, int arg5, int arg_sp0) {
    extern float __fabsf(float);
extern float lbl_80561FE8;
extern float lbl_80558DC4;
extern float lbl_8055A460;
extern float lbl_80561F74;
extern float lbl_80561F88;
extern float lbl_80561F8C;
extern float lbl_80561F98;
extern float lbl_80561FC4;
extern float lbl_80561FD0;
extern float lbl_80561FD4;
extern float lbl_80561FE4;
extern float lbl_80561FEC;
extern float lbl_80561FF4;
extern float lbl_80561FF8;
extern float lbl_80561FFC;
extern float lbl_80562000;
extern float lbl_80562004;
extern float lbl_80562008;
extern float lbl_8056200C;
extern float lbl_80562010;
extern float lbl_80562014;
extern float lbl_80562018;
extern float lbl_8056201C;
extern float lbl_80562020;
extern float lbl_80562024;
extern float lbl_80562028;
extern float lbl_8056202C;
extern float lbl_80562030;
extern float lbl_80562034;

    short spEC;
    float spE0[3];
    float spDC;
    float spD8;
    float spD4;
    float spD0;
    float spCC;
    float spC8;
    volatile float spC4;
    volatile int spC0;
    volatile float spBC;
    float spB8;
    float spB4;
    float spB0;
    float spA4;
    float spA0;
    float sp9C;
    float sp98;
    float sp94;
    float sp90;
    float sp8C;
    float sp88;
    float sp84;
    float sp80;
    float sp7C;
    float sp78;
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    float sp64;
    float sp60;
    float sp5C;
    float sp58;
    float sp54;
    float sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp30;
    float sp20;
    float sp1C;
    float spC;
    float *temp_r3_3;
    float *temp_r3_4;
    float *temp_r3_7;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f0_5;
    float temp_f0_6;
    float temp_f0_7;
    float temp_f0_8;
    float temp_f0_9;
    float temp_f1;
    float temp_f1_10;
    float temp_f1_11;
    float temp_f1_12;
    float temp_f1_13;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f1_5;
    float temp_f1_6;
    float temp_f1_7;
    float temp_f1_8;
    float temp_f1_9;
    float temp_f23;
    float temp_f23_2;
    float temp_f23_3;
    float temp_f23_4;
    float temp_f24;
    float temp_f25;
    float temp_f25_2;
    float temp_f26;
    float temp_f26_2;
    float temp_f28;
    float temp_f29;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f2_5;
    float temp_f2_6;
    float temp_f2_7;
    float temp_f30;
    float temp_f31;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f4;
    float temp_f4_2;
    float temp_f4_3;
    float temp_f5;
    float temp_f5_2;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_r5;
    float temp_r8;
    float var_f0;
    float var_f0_2;
    float var_f0_3;
    float var_f1;
    float var_f1_2;
    float var_f1_3;
    float var_f1_4;
    float var_f1_5;
    float var_f22;
    float var_f22_2;
    float var_f22_3;
    float var_f25;
    float var_f2;
    float var_f2_2;
    float var_f2_3;
    float var_f2_4;
    float var_f3;
    int temp_cr0_eq;
    int temp_cr0_eq_2;
    int temp_r0;
    int temp_r0_2;
    int temp_r21;
    int temp_r22;
    int temp_r3_5;
    int temp_r3_9;
    int temp_r4;
    int temp_r4_2;
    int temp_r7;
    int var_r0;
    int var_r17;
    int var_r17_2;
    int var_r19;
    int var_r19_2;
    int var_r20;
    int var_r20_2;
    int var_r20_3;
    int var_r4;
    int var_r4_2;
    unsigned char temp_r3_6;
    void **temp_r3_10;
    void **temp_r3_11;
    void *temp_r17;
    void *temp_r18;
    void *temp_r20;
    void *temp_r26;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_8;
    void *temp_r4_3;
    void *temp_r5_2;
    void *temp_r6;
    void *temp_r9;
    char *var_r18;
    void *var_r21;
    char *var_r21_2;
    char *var_r22;
    char *var_r24;

    register float divisor = *(volatile float *)((char *)arg0 + 0xD4);
    register float numerator = lbl_80561FF8;
    temp_f6 = numerator / divisor;
    temp_f5 = M2C_FIELD(arg1, float *, 0) * temp_f6;
    temp_f3 = M2C_FIELD(arg1, float *, 4) * temp_f6;
    temp_f1 = M2C_FIELD(arg1, float *, 8) * temp_f6;
    temp_f4 = M2C_FIELD(arg0, float *, 0x26F0) + temp_f5;
    temp_f2 = M2C_FIELD(arg0, float *, 0x26F4) + temp_f3;
    M2C_FIELD(arg0, float *, 0x26F0) = temp_f4;
    M2C_FIELD(arg0, float *, 0x26F4) = temp_f2;
    M2C_FIELD(arg0, float *, 0x26F8) = (float) (M2C_FIELD(arg0, float *, 0x26F8) + temp_f1);
    if (fn_80189BDC(temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6) != 0) {
        0;
        if ((__fabsf(M2C_FIELD(arg0, float *, 0x2690)) <= lbl_80558DC4) && (((M2C_FIELD(arg0, float *, 0x4C) < lbl_80561F74) && (arg5 != 0x6D)) || (arg5 == 0x3E7))) {
            fn_8018E330(arg0);
        }
        if (arg5 == 0x73) {
            var_r4 = 1;
            if (((int) M2C_FIELD(arg0, unsigned char *, 0x25C8) == 0) && (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4)) {
                var_r4 = 0;
            }
            if (var_r4 == 0) {
                goto block_11;
            }
        } else {
block_11:
            if (arg5 == 0x74) {
                return;
            }
            spC8 = M2C_FIELD(arg1, float *, 0);
            spCC = M2C_FIELD(arg1, float *, 4);
            spD0 = M2C_FIELD(arg1, float *, 8);
            if (arg3 != 0) {
                spC8 *= lbl_80561FC4;
                spCC *= lbl_80561FC4;
                spD0 *= lbl_80561FC4;
            }
            temp_r5 = M2C_FIELD(arg2, float *, 0);
            temp_r4 = M2C_FIELD(arg2, int *, 4);
            spBC = temp_r5;
            spC0 = temp_r4;
            spC4 = M2C_FIELD(arg2, float *, 8);
            temp_f24 = PSVECMag(&spC8);
            if (!(M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) & 0x4000) && (M2C_FIELD(arg0, float *, 0x2690) < lbl_80561FFC)) {
                if (!(temp_f24 < lbl_80562000) && (lbl_8055E3C8 >= (lbl_80561FE8 + M2C_FIELD(arg0, float *, 0x26D8))) && ((arg4 < 0) || (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4))) {
                    spB4 = spCC;
                    var_f1 = lbl_80561F74;
                    spB0 = spC8;
                    spB8 = spD0;
                    if (var_f1 < spB4) {

                    } else {
                        var_f1 = spB4;
                    }
                    spB4 = var_f1;
                    temp_f1_2 = PSVECMag(&spB0);
                    var_f22 = temp_f1_2;
                    if (arg4 >= 0) {
                        var_f22 = temp_f1_2 * lbl_80561F98;
                        if (((int) M2C_FIELD(arg0, int *, 0x1F0) != 0x50) && (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4) && ((M2C_FIELD(fn_8017960C(arg4), float *, 0x25BC) > lbl_80558DC4) || (var_f22 > lbl_80562004)) && (M2C_FIELD(fn_8017960C(arg4), float *, 0x25D4) > M2C_FIELD(arg0, float *, 0x25D4))) {
                            fn_8018A174(arg0);
                        }
                    } else if (arg5 == 0x73) {
                        var_f22 = temp_f1_2 * lbl_8055A460;
                    }
                    if ((((arg4 >= 0) && (M2C_FIELD(fn_8017960C(arg4), float *, 0x25BC) > lbl_80558DC4)) || (!(var_f22 < lbl_80562008) && ((arg4 >= 0) || !(M2C_FIELD(arg0, float *, 0x25D4) < lbl_8056200C) || !(var_f22 < lbl_80562010)))) && (((unsigned int) (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) + 0xFFE80000) != 0x304U) || ((int) M2C_FIELD(arg0, int *, 0x1F0) != 0x50) || (arg4 < 0))) {
                        fn_8018E330(arg0);
                        goto block_43;
                    }
                }
            } else {
block_43:
                var_r18 = (char *)arg0 + 0xC;
                var_f25 = lbl_80562014;
                var_r21 = 0;
                spA4 = lbl_80561F74;
                temp_f26 = lbl_80562018;
                var_r19 = 1;
                spC = lbl_80561F74;
                var_r17 = 0x34;
                temp_f23 = lbl_8056201C;
                sp1C = lbl_80561F74;
loop_49:
                if (var_r19 < (int) M2C_FIELD(arg0, int *, 0x5F8)) {
                    temp_r3 = M2C_FIELD(arg0, char **, 0x26C) + var_r17;
                    temp_r20 = (char *)temp_r3 + 4;
                    if ((int) M2C_FIELD(temp_r3, unsigned char *, 0x34) == 0) {
                        sp98 = M2C_FIELD(temp_r20, float *, 0x1C) + (M2C_FIELD(var_r18, float *, 0x5FC) * temp_f26);
                        sp9C = M2C_FIELD(temp_r20, float *, 0x20) + (M2C_FIELD(var_r18, float *, 0x600) * temp_f26);
                        temp_f1_3 = M2C_FIELD(var_r18, float *, 0x604) * temp_f26;
                        spA0 = M2C_FIELD(temp_r20, float *, 0x24) + temp_f1_3;
                        temp_f1_4 = PSVECSquareDistance(&sp98, (float *)&spBC);
                        if ((temp_f1_4 < temp_f23) && (temp_f1_4 < var_f25)) {
                            var_f25 = temp_f1_4;
                            var_r21 = temp_r20;
                            sp20 = sp98;
                            sp30 = sp9C;
                            sp40 = spA0;
                        }
                    }
                    var_r17 += 0x34;
                    var_r18 += 0xC;
                    var_r19 += 1;
                    goto loop_49;
                }
                if (var_r21 != 0) {
                    temp_r4_2 = M2C_FIELD(var_r21, int *, 0);
                    temp_r9 = (char *)arg0 + (temp_r4_2 * 0xC);
                    temp_r8 = M2C_FIELD(temp_r9, float *, 0x600);
                    sp8C = M2C_FIELD(temp_r9, float *, 0x5FC);
                    sp90 = temp_r8;
                    sp94 = M2C_FIELD(temp_r9, float *, 0x604);
                    fn_8018DE94(arg0, temp_r4_2, &spC8, -1, 0);
                    temp_f2_2 = spC8 * lbl_80561FC4;
                    temp_f1_5 = spCC * lbl_80561FC4;
                    sp80 = temp_f2_2;
                    sp84 = temp_f1_5;
                    sp88 = spD0 * lbl_80561FC4;
                    PSVECNormalize(&sp80, &sp80);
                    temp_r5_2 = (char *)arg0 + (M2C_FIELD(var_r21, int *, 0) * 0xC);
                    sp74 = sp8C - M2C_FIELD(temp_r5_2, float *, 0x5FC);
                    sp78 = sp90 - M2C_FIELD(temp_r5_2, float *, 0x600);
                    sp7C = sp94 - M2C_FIELD(temp_r5_2, float *, 0x604);
                    var_r20 = 1;
                    temp_f23_2 = (float) fabs(PSVECDotProduct((int *)(&sp80), &sp74));
                    temp_r3_2 = (char *)arg0 + (M2C_FIELD(var_r21, int *, 0) * 0xC);
                    var_r19_2 = 0x34;
                    temp_f4_2 = M2C_FIELD(var_r21, float *, 0x1C) + M2C_FIELD(temp_r3_2, float *, 0x5FC);
                    temp_f2_3 = M2C_FIELD(var_r21, float *, 0x20) + M2C_FIELD(temp_r3_2, float *, 0x600);
                    temp_f0 = M2C_FIELD(var_r21, float *, 0x24) + M2C_FIELD(temp_r3_2, float *, 0x604);
                    temp_f29 = lbl_80561FD4;
                    sp68 = temp_f4_2;
                    sp6C = temp_f2_3;
                    sp70 = temp_f0;
                    temp_f30 = lbl_80561FD0;
                    temp_f31 = lbl_80561F88;
                    temp_f28 = lbl_80561F74;
loop_80:
                    if (var_r20 < (int) M2C_FIELD(arg0, int *, 0x5F8)) {
                        temp_r18 = M2C_FIELD(arg0, char **, 0x26C) + var_r19_2;
                        temp_r17 = (char *)arg0 + (M2C_FIELD(temp_r18, int *, 4) * 0xC);
                        temp_f5_2 = M2C_FIELD(temp_r18, float *, 0x20) + M2C_FIELD(temp_r17, float *, 0x5FC);
                        temp_f4_3 = M2C_FIELD(temp_r18, float *, 0x24) + M2C_FIELD(temp_r17, float *, 0x600);
                        temp_f3_2 = M2C_FIELD(temp_r18, float *, 0x28) + M2C_FIELD(temp_r17, float *, 0x604);
                        temp_f2_4 = temp_f5_2 - (float) temp_f4_2;
                        temp_f1_6 = temp_f4_3 - (float) temp_f2_3;
                        sp5C = temp_f5_2;
                        sp60 = temp_f4_3;
                        sp64 = temp_f3_2;
                        sp50 = temp_f2_4;
                        sp54 = temp_f1_6;
                        sp58 = temp_f3_2 - (float) temp_f0;
                        temp_f1_7 = PSVECDotProduct((int *)(&sp80), &sp50);
                        if (temp_f1_7 < temp_f23_2) {
                            var_f22_2 = temp_f1_7;
                        } else {
                            var_f22_2 = temp_f23_2;
                        }
                        if (var_f22_2 > temp_f28) {
                            var_f1_2 = PSVECDotProduct((int *)(&sp50), &sp50);
                            if (temp_f29 > var_f1_2) {
                                var_f1_2 = temp_f29;
                            }
                            var_f3 = temp_f30 / var_f1_2;
                            if (temp_f31 < var_f3) {
                                var_f3 = temp_f31;
                            }
                            temp_f3_3 = -var_f22_2 * var_f3;
                            temp_f2_5 = M2C_FIELD(temp_r17, float *, 0x5FC) + (sp80 * temp_f3_3);
                            M2C_FIELD(temp_r17, float *, 0x5FC) = temp_f2_5;
                            M2C_FIELD(temp_r17, float *, 0x600) = (float) (M2C_FIELD(temp_r17, float *, 0x600) + (sp84 * temp_f3_3));
                            M2C_FIELD(temp_r17, float *, 0x604) = (float) (M2C_FIELD(temp_r17, float *, 0x604) + (sp88 * temp_f3_3));
                            var_f1_3 = M2C_FIELD(temp_r18, float *, 0x14);
                            temp_f0_2 = M2C_FIELD(temp_r18, float *, 8);
                            if (var_f1_3 < temp_f2_5) {

                            } else {
                                var_f1_3 = temp_f2_5;
                            }
                            if (var_f1_3 > temp_f0_2) {

                            } else {
                                var_f1_3 = temp_f0_2;
                            }
                            M2C_FIELD(temp_r17, float *, 0x5FC) = var_f1_3;
                            var_f2 = M2C_FIELD(temp_r18, float *, 0x18);
                            temp_f0_3 = M2C_FIELD(temp_r17, float *, 0x600);
                            temp_f1_8 = M2C_FIELD(temp_r18, float *, 0xC);
                            if (var_f2 < temp_f0_3) {

                            } else {
                                var_f2 = temp_f0_3;
                            }
                            if (var_f2 > temp_f1_8) {

                            } else {
                                var_f2 = temp_f1_8;
                            }
                            M2C_FIELD(temp_r17, float *, 0x600) = var_f2;
                            var_f2_2 = M2C_FIELD(temp_r18, float *, 0x1C);
                            temp_f0_4 = M2C_FIELD(temp_r17, float *, 0x604);
                            temp_f1_9 = M2C_FIELD(temp_r18, float *, 0x10);
                            if (var_f2_2 < temp_f0_4) {

                            } else {
                                var_f2_2 = temp_f0_4;
                            }
                            if (var_f2_2 > temp_f1_9) {

                            } else {
                                var_f2_2 = temp_f1_9;
                            }
                            M2C_FIELD(temp_r17, float *, 0x604) = var_f2_2;
                        }
                        var_r19_2 += 0x34;
                        var_r20 += 1;
                        goto loop_80;
                    }
                    temp_f26_2 = lbl_80561FF4;
                    var_r22 = (char *)arg0 + 0x152C;
                    temp_f25 = lbl_80561FD0;
                    var_r21_2 = (char *)&lbl_80332758 + 0xE8;
                    temp_f23_3 = lbl_80561FE4;
                    var_r20_2 = 0;
                    do {
                        if ((((int) M2C_FIELD(var_r22, int *, 0) != 0) && ((int) M2C_FIELD(var_r22, int *, 4) > 0) && ((int) M2C_FIELD(var_r22, int *, 0x7C) == 0)) || ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2)) {
                            temp_r3_3 = (float *)((char *)arg0 + (M2C_FIELD(var_r22, int *, 4) * 0xC) + 0x5FC);
                            temp_f0_5 = M2C_FIELD(var_r21_2, float *, 0x30);
                            if (PSVECDotProduct((int *)(temp_r3_3), temp_r3_3) > (temp_f0_5 * temp_f0_5)) {
                                temp_r3_4 = (float *)((char *)var_r21_2 + 0xC);
                                0;
                                if ((float) fabs(PSVECDotProduct((int *)(temp_r3_4), temp_r3_4)) != lbl_80558DC4) {
                                    if ((unsigned int) M2C_FIELD(var_r21_2, unsigned int *, 0) <= 1U) {
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) != 2) {
                                            M2C_FIELD(var_r22, int *, 0x7C) = 2;
                                            M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                        }
                                    } else {
                                        temp_r3_5 = fn_80129D18(4, 0xA);
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2) {
                                            if (temp_r3_5 < 2) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                                M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                            }
                                        } else {
                                            if (temp_r3_5 < 7) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 2;
                                            } else if (temp_r3_5 < 8) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                            } else {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 1;
                                            }
                                            M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                        }
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2) {
                                            var_f0 = M2C_FIELD(var_r22, float *, 0xC);
                                            if (var_f0 > temp_f26_2) {

                                            } else {
                                                var_f0 = temp_f26_2;
                                            }
                                            M2C_FIELD(var_r22, float *, 0xC) = var_f0;
                                            var_f0_2 = M2C_FIELD(var_r22, float *, 0x10);
                                            if (var_f0_2 > temp_f25) {

                                            } else {
                                                var_f0_2 = temp_f25;
                                            }
                                            M2C_FIELD(var_r22, float *, 0x10) = var_f0_2;
                                        }
                                    }
                                } else {
                                    M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                    M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                }
                                if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 3) {
                                    temp_r7 = M2C_FIELD(var_r21_2, int *, 8);
                                    temp_r4_3 = M2C_FIELD(arg0, char **, 0x26C) + (temp_r7 * 0x18);
                                    temp_r6 = (char *)temp_r4_3 + 0x2138;
                                    temp_f0_6 = M2C_FIELD(temp_r4_3, float *, 0x2138) + M2C_FIELD(temp_r4_3, float *, 0x2144);
                                    sp44 = temp_f0_6;
                                    temp_f1_10 = temp_f0_6 * temp_f23_3;
                                    temp_f0_7 = M2C_FIELD(temp_r6, float *, 4) + M2C_FIELD(temp_r6, float *, 0x10);
                                    sp48 = temp_f0_7;
                                    temp_f3_4 = M2C_FIELD(temp_r6, float *, 8);
                                    temp_f2_6 = temp_f3_4 + M2C_FIELD(temp_r6, float *, 0x14);
                                    sp48 = temp_f0_7 * temp_f23_3;
                                    sp44 = temp_f1_10;
                                    sp4C = temp_f2_6 * temp_f23_3;
                                    fn_801BF2A4(arg0, 1 << temp_r7, &sp44, temp_r6, (char *)temp_r6 + 0xC, M2C_FIELD(var_r21_2, int *, 0x34), (char *)var_r21_2 + 0x38, temp_f1_10, temp_f2_6, temp_f3_4);
                                }
                            }
                        }
                        var_r20_2 += 1;
                        var_r22 += 0x80;
                        var_r21_2 += 0x40;
                    } while (var_r20_2 < 0x11);
                    temp_f25_2 = lbl_80561FEC;
                    var_r24 = (char *)&lbl_80332758 + 0x5B0;
                    temp_f23_4 = lbl_80561F8C;
                    var_r20_3 = 0;
                    do {
                        temp_r21 = M2C_FIELD(var_r24, int *, 4);
                        temp_r26 = arg0 + temp_r21;
                        temp_r3_6 = M2C_FIELD(temp_r26, unsigned char *, 0x1E2C);
                        temp_r22 = 1 << temp_r21;
                        if ((temp_r3_6 != 0xFF) && !(M2C_FIELD(arg0, int *, 0x1E3C) & temp_r22)) {
                            temp_r3_7 = (float *)((char *)arg0 + (temp_r3_6 * 0xC) + 0x5FC);
                            temp_f0_8 = M2C_FIELD(var_r24, float *, 8);
                            if (PSVECDotProduct((int *)(temp_r3_7), temp_r3_7) > (temp_f0_8 * temp_f0_8)) {
                                M2C_FIELD(arg0, int *, 0x1E3C) = (int) (M2C_FIELD(arg0, int *, 0x1E3C) | temp_r22);
                                temp_r0 = M2C_FIELD(var_r24, int *, 0xC);
                                if (temp_r0 > 0) {
                                    M2C_FIELD(arg0, int *, 0x1E40) = (int) (M2C_FIELD(arg0, int *, 0x1E40) | (1 << temp_r0));
                                }
                                if ((temp_r21 >= 2) && (temp_r21 <= 7)) {
                                    temp_r3_8 = M2C_FIELD(arg0, char **, 0x26C) + (M2C_FIELD(temp_r26, unsigned char *, 0x1E2C) * 0x34);
                                    if (&spD4 == (float *)((char *)temp_r3_8 + 0x20)) {
                                        temp_f6_2 = M2C_FIELD(temp_r3_8, float *, 0x24);
                                        temp_f0_9 = M2C_FIELD(temp_r3_8, float *, 0x20);
                                        temp_f7 = M2C_FIELD(temp_r3_8, float *, 0x28);
                                        spD4 = (temp_f7 * M2C_FIELD(arg0, float *, 0x54)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x3C)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x48)));
                                        spD8 = (temp_f7 * M2C_FIELD(arg0, float *, 0x58)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x40)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x4C)));
                                        spDC = (temp_f7 * M2C_FIELD(arg0, float *, 0x5C)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x44)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x50)));
                                    } else {
                                        spD4 = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x54)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x3C)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x48)));
                                        spD8 = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x58)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x40)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x4C)));
                                        spDC = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x5C)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x44)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x50)));
                                    }
                                    temp_f2_7 = spD8;
                                    temp_f1_11 = spDC;
                                    spD4 += M2C_FIELD(arg0, float *, 0x60);
                                    spD8 = temp_f2_7 + M2C_FIELD(arg0, float *, 0x64);
                                    spDC = temp_f1_11 + M2C_FIELD(arg0, float *, 0x68);
                                    fn_8017B6D4(arg0, spE0, &spD4, temp_f1_11, temp_f2_7);
                                    spEC = M2C_FIELD(arg0, short *, 0x6C);
                                    fn_801796CC(7, &spD4, 0x1C);
                                }
                                if ((temp_r21 >= 8) && (temp_r21 <= 0xB) && (fn_80129D18(4, 0xA) < 5)) {
                                    fn_8018F76C(arg0, temp_r21 - 8);
                                }
                                if (temp_r21 == 0xC) {
                                    if (fn_80129D18(4, 0xA) < 5) {
                                        M2C_FIELD(arg0, int *, 0x268C) = 6;
                                    } else {
                                        M2C_FIELD(arg0, int *, 0x268C) = 3;
                                    }
                                    if ((int) M2C_FIELD(arg0, int *, 0x15A8) != 3) {
                                        var_f0_3 = M2C_FIELD(arg0, float *, 0x1538);
                                        M2C_FIELD(arg0, int *, 0x15A8) = 2;
                                        M2C_FIELD(arg0, signed char *, 0x15A4) = 0;
                                        M2C_FIELD(arg0, float *, 0x153C) = temp_f25_2;
                                        if (var_f0_3 > temp_f23_4) {

                                        } else {
                                            var_f0_3 = temp_f23_4;
                                        }
                                        M2C_FIELD(arg0, float *, 0x1538) = var_f0_3;
                                    }
                                }
                            }
                        }
                        var_r20_3 += 1;
                        var_r24 += 0x10;
                    } while (var_r20_3 < 0xD);
                }
                var_f22_3 = M2C_FIELD(arg0, float *, 0x2690);
                if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) & 0x4000) {
                    temp_r0_2 = M2C_FIELD(arg0, int *, 0x268C);
                    var_r17_2 = 0;
                    if (temp_r0_2 == 0) {
                        if (temp_f24 > lbl_80562020) {
                            if (arg5 != 0x70) {
                                var_f1_4 = lbl_80561FD4;
                            } else {
                                var_f1_4 = lbl_80562024;
                            }
                            var_f2_3 = lbl_80562028 * temp_f24;
                            if (var_f2_3 < var_f1_4) {

                            } else {
                                var_f2_3 = var_f1_4;
                            }
                            temp_f1_12 = M2C_FIELD(arg0, float *, 0x2690) + var_f2_3;
                            M2C_FIELD(arg0, float *, 0x2690) = temp_f1_12;
                            if ((temp_f1_12 > lbl_8056202C) || ((temp_f1_12 > lbl_80561F8C) && (var_f2_3 > lbl_80562030))) {
                                if (fn_80129D18(4, 2) != 0) {
                                      M2C_FIELD(arg0, int *, 0x268C) = 2;
                                  } else {
                                      M2C_FIELD(arg0, int *, 0x268C) = 3;
                                  }
                                if (((int) M2C_FIELD(arg0, int *, 0x26B0) < 0) && (fn_80129D18(4, 6) == 0)) {
                                    var_r0 = 2;
                                      if ((spC4 > lbl_80561F74) && (spBC < lbl_80561F74)) {
                                          var_r0 = 3;
                                      }
                                      M2C_FIELD(arg0, int *, 0x26B0) = var_r0;
                                }
                            }
                        }
                    } else if ((temp_r0_2 >= 1) && (temp_r0_2 <= 4)) {
                        if (temp_f24 > lbl_80562020) {
                            if (arg5 != 0x70) {
                                var_f1_5 = lbl_80561FD4;
                            } else {
                                var_f1_5 = lbl_80562024;
                            }
                            var_f2_4 = lbl_80562028 * temp_f24;
                            if (var_f2_4 < var_f1_5) {

                            } else {
                                var_f2_4 = var_f1_5;
                            }
                            temp_f1_13 = M2C_FIELD(arg0, float *, 0x2690) + var_f2_4;
                            M2C_FIELD(arg0, float *, 0x2690) = temp_f1_13;
                            if ((arg5 == 0x70) && (arg4 == (int) M2C_FIELD(arg0, int *, 0x1EC)) && (temp_f1_13 > lbl_80562034)) {
                                if (var_f22_3 > lbl_80562034) {

                                } else {
                                    var_f22_3 = lbl_80562034;
                                }
                                M2C_FIELD(arg0, float *, 0x2690) = var_f22_3;
                            }
                            if (M2C_FIELD(arg0, float *, 0x2690) > lbl_80561F88) {
                                M2C_FIELD(arg0, float *, 0x2690) = (float) lbl_80561F88;
                                temp_r3_9 = fn_80129D18(4, 3);
                                switch (temp_r3_9) { /* irregular */
                                case 0:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xA;
                                    break;
                                case 1:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xB;
                                    break;
                                default:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xC;
                                    break;
                                }
                                if (fn_80129D18(4, 4) == 0) {
                                    if (spC4 > lbl_80561F74) {
                                          var_r4_2 = (spBC >= lbl_80561F74) ? 1 : 0;
                                      } else {
                                          var_r4_2 = (spBC < lbl_80561F74) ? 3 : 2;
                                      }
                                      if (!(M2C_FIELD(((char *)arg0 + (var_r4_2 * 0x74)), int *, 0x241C) & 8)) {
                                        fn_8018F76C(arg0, var_r4_2);
                                    }
                                }
                                fn_802E30C8((char *)&lbl_80332758 + 0x6B8, M2C_FIELD(arg0, int *, 0x1EC));
                                var_r17_2 = 1;
                                fn_801B8610(M2C_FIELD(arg0, int *, 0x1EC), arg4);
                            }
                        }
                    } else if (temp_r0_2 >= 9) {
                        temp_r3_10 = M2C_FIELD(arg0, void ***, 0x270);
                        if (M2C_FIELD(*temp_r3_10, int (**)(void **), 0x38)(temp_r3_10) == 0) {
                            fn_802E30C8((char *)&lbl_80332758 + 0x6CC, M2C_FIELD(arg0, int *, 0x1EC));
                            var_r17_2 = 1;
                        }
                    }
                    if (var_r17_2 != 0) {
                        temp_r3_11 = M2C_FIELD(arg0, void ***, 0x270);
                        M2C_FIELD(*temp_r3_11, int (**)(void **, int), 0x30)(temp_r3_11, arg4);
                    }
                }
                M2C_FIELD(arg0, float *, 0x269C) = (float) lbl_80561F74;
            }
        }
    }
}

void fn_8018F2C0(void *arg0, void *arg1) {
    char *d = (char *)arg0;
    unsigned char *p = (unsigned char *)arg1;
    char *s = (char *)arg1;
    int i;
    float t;
    float f = *(float *)(s + 0x290);
    *(float *)(d + 0x2690) = f;
    *(float *)(d + 0x2694) = f;
    *(float *)(d + 0x2698) = *(float *)(s + 0x294);
    *(int *)(d + 0x268C) = *(int *)(s + 0x298);
    for (i = 0; i < *(int *)((char *)arg0 + 0x5F8); i++) {
        float b;
        t = (lbl_80561F88 < (((float)p[0] - lbl_80561F74) / lbl_80562038)) ? lbl_80561F88 : (((float)p[0] - lbl_80561F74) / lbl_80562038);
        t = (t > lbl_80561F74) ? t : lbl_80561F74;
        *(float *)(d + 0x5FC) = lbl_8056203C + t * lbl_80562040;
        t = (lbl_80561F88 < (((float)p[1] - lbl_80561F74) / lbl_80562038)) ? lbl_80561F88 : (((float)p[1] - lbl_80561F74) / lbl_80562038);
        t = (t > lbl_80561F74) ? t : lbl_80561F74;
        *(float *)(d + 0x600) = lbl_8056203C + t * lbl_80562040;
        t = (lbl_80561F88 < (((float)p[2] - lbl_80561F74) / lbl_80562038)) ? lbl_80561F88 : (((float)p[2] - lbl_80561F74) / lbl_80562038);
        t = (t > lbl_80561F74) ? t : lbl_80561F74;
        b = lbl_8056203C + t * lbl_80562040;
        *(float *)(d + 0x604) = b;
        *(float *)(d + 0xD94) = *(float *)(d + 0x5FC);
        *(float *)(d + 0xD98) = *(float *)(d + 0x600);
        *(float *)(d + 0xD9C) = b;
        p += 4;
        d += 0xC;
    }
    d = (char *)arg0;
    *(int *)(d + 0x15A8) = ((unsigned char *)s)[0x2A0]; *(char *)(d + 0x15A4) = 0;
    *(int *)(d + 0x1628) = ((unsigned char *)s)[0x2A1]; *(char *)(d + 0x1624) = 0;
    *(int *)(d + 0x16A8) = ((unsigned char *)s)[0x2A2]; *(char *)(d + 0x16A4) = 0;
    *(int *)(d + 0x1728) = ((unsigned char *)s)[0x2A3]; *(char *)(d + 0x1724) = 0;
    *(int *)(d + 0x17A8) = ((unsigned char *)s)[0x2A4]; *(char *)(d + 0x17A4) = 0;
    *(int *)(d + 0x1828) = ((unsigned char *)s)[0x2A5]; *(char *)(d + 0x1824) = 0;
    *(int *)(d + 0x18A8) = ((unsigned char *)s)[0x2A6]; *(char *)(d + 0x18A4) = 0;
    *(int *)(d + 0x1928) = ((unsigned char *)s)[0x2A7]; *(char *)(d + 0x1924) = 0;
    *(int *)(d + 0x19A8) = ((unsigned char *)s)[0x2A8]; *(char *)(d + 0x19A4) = 0;
    *(int *)(d + 0x1A28) = ((unsigned char *)s)[0x2A9]; *(char *)(d + 0x1A24) = 0;
    *(int *)(d + 0x1AA8) = ((unsigned char *)s)[0x2AA]; *(char *)(d + 0x1AA4) = 0;
    *(int *)(d + 0x1B28) = ((unsigned char *)s)[0x2AB]; *(char *)(d + 0x1B24) = 0;
    *(int *)(d + 0x1BA8) = ((unsigned char *)s)[0x2AC]; *(char *)(d + 0x1BA4) = 0;
    *(int *)(d + 0x1C28) = ((unsigned char *)s)[0x2AD]; *(char *)(d + 0x1C24) = 0;
    *(int *)(d + 0x1CA8) = ((unsigned char *)s)[0x2AE]; *(char *)(d + 0x1CA4) = 0;
    *(int *)(d + 0x1D28) = ((unsigned char *)s)[0x2AF]; *(char *)(d + 0x1D24) = 0;
    *(int *)(d + 0x1DA8) = ((unsigned char *)s)[0x2B0]; *(char *)(d + 0x1DA4) = 0;
    *(int *)(d + 0x1E3C) = *(int *)(s + 0x29C);
}

#pragma pop
extern float lbl_80561F88;
extern float lbl_80562038;
extern float lbl_8056203C;
extern float lbl_80562040;
#pragma scheduling invalid_target
void fn_8018F538(void *arg0, void *arg1) {
    unsigned char *src;
    unsigned char *dst;
    register float bias;
    register float scale;
    register float upper;
    register float divisor;
    register float origin;
    register float lower;
    float v;
    float first;
    float second;
    int word;
    int i;

    src = (unsigned char *)arg0;
    lower = *(volatile float *)&lbl_80561F88;
    dst = (unsigned char *)arg1;
    first = *(float *)(src + 0x2690);
    upper = *(volatile float *)&lbl_80561F74;
    i = 0;
    *(float *)(dst + 0x290) = first;
    origin = *(volatile float *)&lbl_8056203C;
    second = *(float *)(src + 0x2698);
    divisor = *(volatile float *)&lbl_80562040;
    *(float *)(dst + 0x294) = second;
    scale = *(volatile float *)&lbl_80562038;
    word = *(volatile int *)(src + 0x268C);
    bias = *(volatile float *)&lbl_80561F8C;
    *(int *)(dst + 0x298) = word;

    while (i < *(int *)((unsigned char *)arg0 + 0x5F8)) {
        v = (*(float *)(src + 0x5FC) - origin) / divisor;
        if (lower < v) v = lower;
        if (v > upper) v = upper;
        dst[0] = (unsigned char)(int)(bias + (upper + v * scale));
        v = (*(float *)(src + 0x600) - origin) / divisor;
        if (lower < v) v = lower;
        if (v > upper) v = upper;
        dst[1] = (unsigned char)(int)(bias + (upper + v * scale));
        v = (*(float *)(src + 0x604) - origin) / divisor;
        if (lower < v) v = lower;
        if (v > upper) v = upper;
        dst[2] = (unsigned char)(int)(bias + (upper + v * scale));
        src += 0xC;
        dst += 4;
        i++;
    }

    dst = (unsigned char *)arg1;
    *(unsigned char *)(dst + 0x2A0) = *(int *)((unsigned char *)arg0 + 0x15A8);
    *(unsigned char *)(dst + 0x2A1) = *(int *)((unsigned char *)arg0 + 0x1628);
    *(unsigned char *)(dst + 0x2A2) = *(int *)((unsigned char *)arg0 + 0x16A8);
    *(unsigned char *)(dst + 0x2A3) = *(int *)((unsigned char *)arg0 + 0x1728);
    *(unsigned char *)(dst + 0x2A4) = *(int *)((unsigned char *)arg0 + 0x17A8);
    *(unsigned char *)(dst + 0x2A5) = *(int *)((unsigned char *)arg0 + 0x1828);
    *(unsigned char *)(dst + 0x2A6) = *(int *)((unsigned char *)arg0 + 0x18A8);
    *(unsigned char *)(dst + 0x2A7) = *(int *)((unsigned char *)arg0 + 0x1928);
    *(unsigned char *)(dst + 0x2A8) = *(int *)((unsigned char *)arg0 + 0x19A8);
    *(unsigned char *)(dst + 0x2A9) = *(int *)((unsigned char *)arg0 + 0x1A28);
    *(unsigned char *)(dst + 0x2AA) = *(int *)((unsigned char *)arg0 + 0x1AA8);
    *(unsigned char *)(dst + 0x2AB) = *(int *)((unsigned char *)arg0 + 0x1B28);
    *(unsigned char *)(dst + 0x2AC) = *(int *)((unsigned char *)arg0 + 0x1BA8);
    *(unsigned char *)(dst + 0x2AD) = *(int *)((unsigned char *)arg0 + 0x1C28);
    *(unsigned char *)(dst + 0x2AE) = *(int *)((unsigned char *)arg0 + 0x1CA8);
    *(unsigned char *)(dst + 0x2AF) = *(int *)((unsigned char *)arg0 + 0x1D28);
    *(unsigned char *)(dst + 0x2B0) = *(int *)((unsigned char *)arg0 + 0x1DA8);
    *(int *)(dst + 0x29C) = *(int *)((unsigned char *)arg0 + 0x1E3C);
}
#pragma scheduling on
void fn_8018F6F8(void *arg0) {
    int i;
    float divisor;
    float value;
    char *type;
    char *entry;

    i = 0x11;
    value = lbl_80561F74;
    type = (char *)&lbl_80332840;
    entry = (char *)arg0 + 0x152C;
    divisor = lbl_80562050;
    for (; i != 0; i--) {
        if (*(int *)entry != 0 && *(int *)(entry + 0x7C) == 0 &&
            (unsigned int)(*(int *)type - 0xE) <= 2U) {
            *(int *)(entry + 0x7C) = 4;
            *(char *)(entry + 0x78) = 0;
            *(float *)(entry + 0xC) = value;
            *(float *)(entry + 0x10) = *(float *)(entry + 0x14) / divisor;
        }
        type += 0x40;
        entry += 0x80;
    }
}

void fn_8018F76C(void *arg0, int arg1) {
    extern void fn_801BEB30(int, void **);
    extern void fn_801AFC44();
    extern float lbl_80562054;
    extern float lbl_80561F98;
    extern float lbl_80561F74;
    extern float lbl_80561F9C;
    extern char lbl_80332E40[];
    char *base = (char *)arg0;
    char *state = base + arg1 * 0x74;
    float *q;
    float *src;
    float quat[4];
    float mtx[9];
    float pos[3];
    float vel[3];
    float out[3];
    void *p;
    if (*(int *)(state + 0x241C) & 8)
        fn_802E30C8(lbl_80332E40, *(int *)(base + 0x1EC));
    fn_801BEB30(*(int *)(base + 0x1EC), &p);
    q = (float *)((char *)p + 0x70);
    quat[0] = q[0]; quat[1] = q[1]; quat[2] = q[2]; quat[3] = q[3];
    quat[arg1] *= lbl_80562054;
    q[0] = quat[0]; q[1] = quat[1]; q[2] = quat[2]; q[3] = quat[3];
    src = (float *)(base + 0x3C);
    mtx[0] = src[0]; mtx[1] = src[1]; mtx[2] = src[2];
    mtx[3] = src[3]; mtx[4] = src[4]; mtx[5] = src[5];
    mtx[6] = src[6]; mtx[7] = src[7]; mtx[8] = src[8];
    pos[0] = *(float *)(state + 0x23D0) + mtx[3] * lbl_80561F98;
    pos[1] = *(float *)(state + 0x23D4) + mtx[4] * lbl_80561F98;
    pos[2] = *(float *)(state + 0x23D8) + mtx[5] * lbl_80561F98;
    ((void (*)(void *, float *, float *))fn_8017B6D4)(arg0, vel, pos);
    if (fabsf(*(float *)(state + 0x23AC)) < lbl_80561F9C && *(float *)(state + 0x23AC) < lbl_80561F74) {
        float k = *(float *)(state + 0x23AC);
        out[0] = mtx[0] * k + *(float *)(base + 0x124);
        out[1] = mtx[1] * k + *(float *)(base + 0x128);
        out[2] = mtx[2] * k + *(float *)(base + 0x12C);
        fn_801AFC44(*(int *)(base + 0x1EC), arg1, mtx, vel, out);
    }
    *(int *)(state + 0x241C) |= 8;
}

extern void fn_801BF2A4(void *, int, float *, void *, void *, int, void *, float, float, float);
extern float lbl_80561FE4;
void fn_8018F9B4(void *arg0) {
    struct Values { float x; float y; float z; };
    unsigned char *base = (unsigned char *)arg0;
    char *slot = (char *)arg0 + 0x152C;
    char *table = (char *)&lbl_80332840;
    float scale = lbl_80561FE4;
    int i = 0;
    int one = 1;
    int three = 3;
    int zero = 0;

    do {
        if (*(int *)slot != 0 && *(int *)(slot + 4) > 0) {
            if (*(volatile int *)(slot + 0x7C) == 0 ||
                *(volatile int *)(slot + 0x7C) == 2) {
                int row = *(int *)(table + 8);
                char *rowBase = *(char **)(base + 0x26C) + row * 0x18;
                int context = *(int *)(table + 0x34);
                float first = *(float *)(rowBase + 0x2138);
                struct Values values;
                float *position = (float *)(rowBase + 0x2138);
                float second = *(float *)(rowBase + 0x2144);

                values.x = second + first;
                values.y = position[1] + position[4];
                values.z = position[2] + position[5];
                values.x *= scale;
                values.y *= scale;
                values.z *= scale;
                fn_801BF2A4(arg0, one << row, &values.x, position,
                            (char *)position + 0xC, context, table + 0x38,
                            values.x, values.y, values.z);
                *(int *)(slot + 0x7C) = three;
                *(char *)(slot + 0x78) = zero;
            }
        }
        i++;
        slot += 0x80;
        table += 0x40;
    } while (i < 0x11);
}

extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
int fn_80161A38(int, int, int);
int fn_801DFF1C(int);
float PSQUATMultiply(void *, void *);

