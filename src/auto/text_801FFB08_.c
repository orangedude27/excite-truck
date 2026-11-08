// Code of main that had no source file yet: decomp.wtf gave it this one.
typedef struct { float x, y, z; } V802009CC;
typedef struct { float m[9]; float p[3]; } M802009CC;
extern float lbl_80563058, lbl_8056305C, lbl_8056306C, lbl_80563070, lbl_80563068;
extern float PSVECMag(float *);
extern void PSVECCrossProduct(const float *, const float *, float *);
extern double sin(double), cos(double);
extern float fn_80144514(float, float, float, float, float, float);
extern int fn_801E2CCC();
extern int fn_802E30C8(const char *, ...);
extern int lbl_8055ECA8;
extern char lbl_8033B938[];
extern char lbl_804888A8[];
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
char *fn_801FFB08(int arg0, int arg1) {
    char *sp8;
    if (fn_801E2CCC(arg0, arg1, &sp8) == 0) {
        fn_802E30C8(lbl_8033B938, arg1, lbl_8055ECA8);
        return lbl_804888A8;
    }
    return sp8 + 0x24;
}
#pragma scheduling on
void fn_801FFB6C(void) {

}

void fn_801FFB70(void) {

}

extern int fn_801E320C(int, void *);
extern void *fn_801284F8(int, void *);
extern void *memset(void *, int, unsigned long);
extern int fn_801E3004(int, void *, int);
extern int fn_801E31D8(int, void *, int);
extern int fn_802C6FC0(void *, int, int);
extern int fn_801E592C(void);
extern void fn_801E3488(float *, int);
extern void *fn_801FFB74(int, int, int);
extern int fn_802E317C(const char *, ...);
extern double fn_8002EFB0(float, float);
static inline void xformv(float *v, float *m, float *out) {
    if (out == v) {
        float x = v[0], y = v[1], z = v[2];
        out[0] = z * m[6] + (x * m[0] + y * m[3]);
        out[1] = z * m[7] + (x * m[1] + y * m[4]);
        out[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        out[0] = v[2] * m[6] + (v[0] * m[0] + v[1] * m[3]);
        out[1] = v[2] * m[7] + (v[0] * m[1] + v[1] * m[4]);
        out[2] = v[2] * m[8] + (v[0] * m[2] + v[1] * m[5]);
    }
}
extern char lbl_8055B3E0, lbl_8055B3E8, lbl_8055B3F0, lbl_8055B3F8, lbl_8055B400, lbl_8055B408;
extern float lbl_80563050, lbl_80563060, lbl_80563054, lbl_80563064;
extern void fn_801E33E4(float *, int);
extern void fn_801E5998(void *, void *, void *);
extern int fn_801C1BA4();
extern void fn_801C1CBC();
extern char lbl_802F9C60[], lbl_802F9CC0[];
void *fn_802002D4(int arg0, int arg1, int arg2) {
    float *o;
    struct { int n; float r[3]; float P[3]; float Q[3]; } sp8;
    float v60[3], v54[3], v48[3], v3C[3], v30[3];
    struct { float v[3]; float pad[2]; } bufA[7];
    int bufB[24];
    int *bufC_[15];
    float out198[0x40];
    char *p;
    int *tc;
    int i;
    lbl_8055ECA8 = arg0;
    if (fn_801E320C(arg1, &lbl_8055B3E0)) return fn_801FFB74(arg0, arg1, arg2);
    if (!fn_801E320C(arg1, &lbl_8055B408)) return 0;
    o = fn_801284F8(0xD0, lbl_8033B938 + 0x40);
    memset(o, 0, 0xD0);
    ((int *)o)[7] = fn_801E3004(arg1, &lbl_8055B3E8, -1);
    ((int *)o)[8] = fn_801E31D8(arg1, &lbl_8055B3F0, -1);
    ((int *)o)[9] = fn_801E31D8(((int *)o)[7], &lbl_8055B3F8, -1);
    ((int *)o)[10] = fn_801E3004(arg1, &lbl_8055B400, -1);
    ((int *)o)[2] = fn_802C6FC0(lbl_8033B938 + 0x4C, 0, 0);
    ((int *)o)[3] = fn_801E592C();
    p = fn_801FFB08(arg1, (int)(lbl_8033B938 + 0x84));
    v60[0] = ((float *)p)[0]; v60[1] = ((float *)p)[1]; v60[2] = ((float *)p)[2];
    fn_801E3488(v54, ((int *)o)[8]);
    v48[0] = v54[0] * lbl_80563050 + v60[0] * lbl_80563050;
    v48[2] = v54[2] * lbl_80563050 + v60[2] * lbl_80563050;
    v48[1] = v54[1] * lbl_80563050 + v60[1] * lbl_80563050 - lbl_80563060;
    p = fn_801FFB08(arg1, (int)(lbl_8033B938 + 0x90));
    v3C[0] = ((float *)p)[0]; v3C[1] = ((float *)p)[1]; v3C[2] = ((float *)p)[2];
    fn_801E3488(v30, ((int *)o)[9]);
    sp8.Q[0] = v30[0] * lbl_80563050 + v3C[0] * lbl_80563050;
    sp8.Q[2] = v30[2] * lbl_80563050 + v3C[2] * lbl_80563050;
    sp8.Q[1] = v30[1] * lbl_80563050 + v3C[1] * lbl_80563050 - lbl_80563060;
    sp8.P[0] = v60[0] * lbl_80563050 + v3C[0] * lbl_80563050;
    sp8.P[2] = v60[2] * lbl_80563050 + v3C[2] * lbl_80563050;
    sp8.P[1] = v60[1] * lbl_80563050 + v3C[1] * lbl_80563050 - lbl_80563054;
    sp8.n = 0x20;
    fn_801E5998((void *)((int *)o)[3], out198, &sp8);
    o[4] = v3C[0] - out198[0x104 / 4];
    o[5] = v3C[1] - out198[0x108 / 4];
    o[6] = v3C[2] - out198[0x10C / 4];
    o[5] = o[5] + lbl_80563064;
    o[13] = lbl_80563058; o[14] = lbl_8056305C; o[15] = lbl_8056305C;
    o[16] = lbl_8056305C; o[17] = lbl_80563058; o[18] = lbl_8056305C;
    o[19] = lbl_8056305C; o[20] = lbl_8056305C; o[21] = lbl_80563058;
    o[22] = lbl_8056305C; o[23] = lbl_8056305C; o[24] = lbl_8056305C;
    sp8.r[0] = o[6] * o[19] + (o[4] * o[13] + o[5] * o[16]);
    sp8.r[1] = o[6] * o[20] + (o[4] * o[14] + o[5] * o[17]);
    sp8.r[2] = o[6] * o[21] + (o[4] * o[15] + o[5] * o[18]);
    o[22] += sp8.r[0];
    o[23] += sp8.r[1];
    o[24] += sp8.r[2];
    for (i = 0; i < 12; i++) o[37 + i] = o[13 + i];
    fn_801E33E4(o + 25, ((int *)o)[7]);
    bufA[0].v[0] = v60[0]; bufA[0].v[1] = v60[1]; bufA[0].v[2] = v60[2];
    bufA[1].v[0] = v48[0]; bufA[1].v[1] = v48[1]; bufA[1].v[2] = v48[2];
    bufA[2].v[0] = v54[0]; bufA[2].v[1] = v54[1]; bufA[2].v[2] = v54[2];
    bufA[3].v[0] = v3C[0]; bufA[3].v[1] = v3C[1]; bufA[3].v[2] = v3C[2];
    bufA[4].v[0] = sp8.Q[0]; bufA[4].v[1] = sp8.Q[1]; bufA[4].v[2] = sp8.Q[2];
    bufA[5].v[0] = v30[0]; bufA[5].v[1] = v30[1]; bufA[5].v[2] = v30[2];
    bufA[6].v[0] = sp8.P[0]; bufA[6].v[1] = sp8.P[1]; bufA[6].v[2] = sp8.P[2];
    for (i = 0; i < 7; i++) { bufA[i].pad[0] = lbl_80563058; bufA[i].pad[1] = lbl_80563058; }
    for (i = 0; i < 24; i++) bufB[i] = ((int *)lbl_802F9C60)[i];
    tc = (int *)lbl_802F9CC0;
    for (i = 0; i < 15; i++) bufC_[i] = (int *)tc[i];
    bufC_[1] = (int *)(o + 37);
    bufC_[4] = (int *)(o + 25);
    bufC_[7] = (int *)(o + 37);
    bufC_[10] = (int *)(o + 25);
    bufC_[13] = (int *)(o + 13);
    i = fn_801C1BA4(7, 6, 5, o + 25, o + 37, (void *)tc[14], (void *)tc[12], (void *)tc[11]);
    fn_801C1CBC(7, bufA, 6, bufB, 5, bufC_);
    ((int *)o)[0] = i;
    o[49] = lbl_8056305C;
    o[51] = lbl_8056305C;
    o[50] = lbl_8056305C;
    return o;
}

extern int fn_801E323C(int);
extern int fn_801C1C7C(int);
extern int fn_801E598C(int);
extern int fn_802C6CF8(int);
extern int fn_80128668(void *);
void fn_8020095C(int *arg0) {
    if (arg0 != 0) {
        fn_801E323C(arg0[7]);
        fn_801E323C(arg0[8]);
        fn_801E323C(arg0[9]);
        fn_801E323C(arg0[10]);
        fn_801C1C7C(arg0[0]);
        fn_801E598C(arg0[3]);
        fn_802C6CF8(arg0[2]);
        fn_80128668(arg0);
    }
}

#pragma push
#pragma processor 750
void fn_802009CC(M802009CC *out, float *verts, int *tri, int count, unsigned char *arr, float *M) {
    struct { float axis[3]; float d[3]; float w[3]; float p[3]; float R[9]; float res[9]; } s;
    int i;
    for (i = 0; i < count; i++, tri += 3) {
        int i0 = tri[0], i2 = tri[2];
        float *vp = (float *)((unsigned char *)verts + tri[1] * 12);
        float vx = vp[0] - M[9], vy = vp[1] - M[10], vz = vp[2] - M[11];
        M802009CC *o = (M802009CC *)((unsigned char *)out + i0 * 0x30);
        float *B = (float *)(arr + i0 * 0x38);
        float px, py, pz;
        px = vz * M[2] + (vx * M[0] + vy * M[1]);
        py = vz * M[5] + (vx * M[3] + vy * M[4]);
        pz = vz * M[8] + (vx * M[6] + vy * M[7]);
        o->p[0] = px;
        o->p[1] = py;
        s.p[0] = px; s.p[1] = py; s.p[2] = pz;
        o->p[2] = pz;
        if (i2 >= 0) {
            float *wp = (float *)((unsigned char *)verts + i2 * 12);
            float wx = wp[0] - M[9], wy = wp[1] - M[10], wz = wp[2] - M[11];
            float mag;
            s.w[0] = wz * M[2] + (wx * M[0] + wy * M[1]);
            s.w[1] = wz * M[5] + (wx * M[3] + wy * M[4]);
            s.w[2] = wz * M[8] + (wx * M[6] + wy * M[7]);
            s.d[0] = s.w[0] - s.p[0];
            s.d[1] = s.w[1] - s.p[1];
            s.d[2] = s.w[2] - s.p[2];
            mag = PSVECMag(s.d);
            if (mag > lbl_80563068) {
                float k = lbl_8056306C / mag;
                s.res[0] = s.d[0] * k;
                s.res[1] = s.d[1] * k;
                s.res[2] = s.d[2] * k;
                PSVECCrossProduct(B, s.res, s.axis);
                mag = PSVECMag(s.axis);
                if (mag > lbl_80563070) {
                    float inv = lbl_80563058 / mag;
                    float ax = inv * s.axis[0], ay = inv * s.axis[1], az = inv * s.axis[2];
                    float sn = (float)sin(mag);
                    float cs = (float)cos(mag);
                    float t = lbl_80563058 - cs;
                    float txy = t * ax;
                    float a = ay * txy;
                    float b = sn * az;
                    float c = az * txy;
                    float e = sn * ay;
                    float g = az * (t * ay);
                    float h = sn * ax;
                    s.R[0] = cs + t * (ax * ax);
                    s.R[1] = a + b;
                    s.R[2] = c - e;
                    s.R[3] = a - b;
                    s.R[4] = cs + t * (ay * ay);
                    s.R[5] = g + h;
                    s.R[6] = c + e;
                    s.R[7] = g - h;
                    s.R[8] = cs + t * (az * az);
                } else {
                    s.R[0] = lbl_80563058; s.R[1] = lbl_8056305C; s.R[2] = lbl_8056305C;
                    s.R[3] = lbl_8056305C; s.R[4] = lbl_80563058; s.R[5] = lbl_8056305C;
                    s.R[6] = lbl_8056305C; s.R[7] = lbl_8056305C; s.R[8] = lbl_80563058;
                }
                if (s.res == s.R || s.res == B) {
                    float r0 = fn_80144514(B[0], s.R[0], B[3], s.R[1], B[6], s.R[2]);
                    float r3 = fn_80144514(B[0], s.R[3], B[3], s.R[4], B[6], s.R[5]);
                    float r6 = fn_80144514(B[0], s.R[6], B[3], s.R[7], B[6], s.R[8]);
                    float r1 = fn_80144514(B[1], s.R[0], B[4], s.R[1], B[7], s.R[2]);
                    float r4 = fn_80144514(B[1], s.R[3], B[4], s.R[4], B[7], s.R[5]);
                    float r7 = fn_80144514(B[1], s.R[6], B[4], s.R[7], B[7], s.R[8]);
                    float r2 = fn_80144514(B[2], s.R[0], B[5], s.R[1], B[8], s.R[2]);
                    float r5 = fn_80144514(B[2], s.R[3], B[5], s.R[4], B[8], s.R[5]);
                    float r8 = fn_80144514(B[2], s.R[6], B[5], s.R[7], B[8], s.R[8]);
                    s.res[0] = r0; s.res[3] = r3; s.res[6] = r6;
                    s.res[1] = r1; s.res[4] = r4; s.res[7] = r7;
                    s.res[2] = r2; s.res[5] = r5; s.res[8] = r8;
                } else {
                    s.res[0] = fn_80144514(B[0], s.R[0], B[3], s.R[1], B[6], s.R[2]);
                    s.res[3] = fn_80144514(B[0], s.R[3], B[3], s.R[4], B[6], s.R[5]);
                    s.res[6] = fn_80144514(B[0], s.R[6], B[3], s.R[7], B[6], s.R[8]);
                    s.res[1] = fn_80144514(B[1], s.R[0], B[4], s.R[1], B[7], s.R[2]);
                    s.res[4] = fn_80144514(B[1], s.R[3], B[4], s.R[4], B[7], s.R[5]);
                    s.res[7] = fn_80144514(B[1], s.R[6], B[4], s.R[7], B[7], s.R[8]);
                    s.res[2] = fn_80144514(B[2], s.R[0], B[5], s.R[1], B[8], s.R[2]);
                    s.res[5] = fn_80144514(B[2], s.R[3], B[5], s.R[4], B[8], s.R[5]);
                    s.res[8] = fn_80144514(B[2], s.R[6], B[5], s.R[7], B[8], s.R[8]);
                }
            } else {
                s.res[0] = lbl_80563058; s.res[1] = lbl_8056305C; s.res[2] = lbl_8056305C;
                s.res[3] = lbl_8056305C; s.res[4] = lbl_80563058; s.res[5] = lbl_8056305C;
                s.res[6] = lbl_8056305C; s.res[7] = lbl_8056305C; s.res[8] = lbl_80563058;
            }
            ((V802009CC *)o)[0] = ((V802009CC *)s.res)[0];
            ((V802009CC *)o)[1] = ((V802009CC *)s.res)[1];
            ((V802009CC *)o)[2] = ((V802009CC *)s.res)[2];
        } else {
            ((V802009CC *)o)[0] = ((V802009CC *)B)[0];
            ((V802009CC *)o)[1] = ((V802009CC *)B)[1];
            ((V802009CC *)o)[2] = ((V802009CC *)B)[2];
        }
    }
}
#pragma pop
extern float lbl_80563050, lbl_80563058, lbl_8056305C, lbl_8056306C;
extern float lbl_8056307C;
extern void fn_801E353C(int, float);
extern void fn_801E34E4(int, void *);
extern float lbl_80563070, lbl_80563074, lbl_80563078, lbl_80563080;
extern float lbl_80563074;
extern float PSVECMag(float *);
extern double sin(double), cos(double);
extern float fn_80144514(float, float, float, float, float, float);
extern float lbl_80563070, lbl_80563074, lbl_80563078, lbl_80563080, lbl_80563084;
extern void fn_801E3284(void *, void *, int);
extern void fn_801C2694(void *, int *, float *, float *, float *, float *, float *, float, float);
extern void fn_801E5998(void *, void *, void *);
#pragma scheduling invalid_target
extern double __fabs(double);
void fn_80201018(void *object, const float *input, int enabled) {
    volatile unsigned char scratch[0x10F0];
    unsigned int *src = (unsigned int *)input;
    float *obj = (float *)object;
    float x, y, zero;
    int mode;
    float *position = (float *)(scratch + 0x14);
    float *axis = (float *)(scratch + 0x68);
    float *rotation = (float *)(scratch + 0x218);
    if (enabled == 0) return;
    if (object == 0) return;
    ((unsigned int *)(scratch + 0x240))[0] = src[0]; ((unsigned int *)(scratch + 0x240))[1] = src[1]; ((unsigned int *)(scratch + 0x240))[2] = src[2]; ((unsigned int *)(scratch + 0x240))[3] = src[3];
    ((unsigned int *)(scratch + 0x240))[4] = src[4]; ((unsigned int *)(scratch + 0x240))[5] = src[5]; ((unsigned int *)(scratch + 0x240))[6] = src[6]; ((unsigned int *)(scratch + 0x240))[7] = src[7];
    ((unsigned int *)(scratch + 0x240))[8] = src[8]; ((unsigned int *)(scratch + 0x240))[9] = src[9]; ((unsigned int *)(scratch + 0x240))[10] = src[10]; ((unsigned int *)(scratch + 0x240))[11] = src[11];
    x = obj[0xC8 / 4];
    y = obj[0xCC / 4];
    zero = lbl_8056305C;
    obj[0xC8 / 4] = zero;
    obj[0xCC / 4] = zero;
    mode = (int)src[0x48 / 4] + 1;
    switch (mode) {
    case 0: {
        float b = lbl_8056306C, a = lbl_80563058;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 1: {
        float a = x, b = zero;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 2: {
        float a = lbl_8056306C, b = lbl_80563058;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 3: {
        float a = lbl_8056306C, b = lbl_8056306C;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 4: {
        float a = zero, b = lbl_80563058;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 5: {
        float a = zero, b = lbl_8056306C;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 6: {
        float a = lbl_80563058, b = lbl_80563058;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    case 7: {
        float b = lbl_8056306C, a = lbl_80563058;
        obj[0xC8 / 4] = a;
        obj[0xCC / 4] = b;
        break;
    }
    }
    {
        float value = obj[0xCC / 4];
        float mag;
        obj[0xCC / 4] = lbl_80563050 * y + lbl_80563050 * value;
        mag = obj[0xCC / 4];
        mag = (float)__fabs((double)mag);
        if (mag >= lbl_80563074 && value * y > lbl_8056305C && src[0x48 / 4] == 0)
            obj[0xC8 / 4] = lbl_80563078 * x;
        fn_801E353C(*(int *)((unsigned char *)object + 0x1C),
                    -lbl_8056307C * input[0x3C / 4]);
        fn_801E34E4(*(int *)((unsigned char *)object + 0x1C), (void *)((unsigned int *)(scratch + 0x240)));
    }
    {
        unsigned int *dst = (unsigned int *)((unsigned char *)object + 0x34);
        dst[0] = ((unsigned int *)(scratch + 0x240))[0]; dst[1] = ((unsigned int *)(scratch + 0x240))[1]; dst[2] = ((unsigned int *)(scratch + 0x240))[2]; dst[3] = ((unsigned int *)(scratch + 0x240))[3];
        dst[4] = ((unsigned int *)(scratch + 0x240))[4]; dst[5] = ((unsigned int *)(scratch + 0x240))[5]; dst[6] = ((unsigned int *)(scratch + 0x240))[6]; dst[7] = ((unsigned int *)(scratch + 0x240))[7];
        dst[8] = ((unsigned int *)(scratch + 0x240))[8]; dst[9] = ((unsigned int *)(scratch + 0x240))[9]; dst[10] = ((unsigned int *)(scratch + 0x240))[10]; dst[11] = ((unsigned int *)(scratch + 0x240))[11];
    }
    if (position != (float *)((unsigned char *)object + 0x10)) {
        position[0] = obj[0x18 / 4] * obj[0x4C / 4] +
                      (obj[0x10 / 4] * obj[0x34 / 4] + obj[0x14 / 4] * obj[0x40 / 4]);
        position[1] = obj[0x18 / 4] * obj[0x50 / 4] +
                      (obj[0x10 / 4] * obj[0x38 / 4] + obj[0x14 / 4] * obj[0x44 / 4]);
        position[2] = obj[0x18 / 4] * obj[0x54 / 4] +
                      (obj[0x10 / 4] * obj[0x3C / 4] + obj[0x14 / 4] * obj[0x48 / 4]);
    } else {
        position[0] = obj[0x18 / 4] * obj[0x4C / 4] +
                      (obj[0x10 / 4] * obj[0x34 / 4] + obj[0x14 / 4] * obj[0x40 / 4]);
        position[1] = obj[0x18 / 4] * obj[0x50 / 4] +
                      (obj[0x10 / 4] * obj[0x38 / 4] + obj[0x14 / 4] * obj[0x44 / 4]);
        position[2] = obj[0x18 / 4] * obj[0x54 / 4] +
                      (obj[0x10 / 4] * obj[0x3C / 4] + obj[0x14 / 4] * obj[0x48 / 4]);
    }
    obj[0x58 / 4] += position[0];
    obj[0x5C / 4] += position[1];
    obj[0x60 / 4] += position[2];
    {
        float angle = -input[0x238 / 4], limit = lbl_80563080;
        float magnitude, inverse, nx, ny, nz, sine, cosine, temp;
        if (angle > limit) angle = limit;
        if (angle < -limit) angle = -limit;
        axis[0] = obj[0x30 / 4] + input[0x240 / 4];
        axis[1] = lbl_8056305C;
        axis[2] = angle;
        magnitude = PSVECMag(axis);
        if (magnitude > lbl_80563070) {
            inverse = lbl_80563058 / magnitude;
            nx = inverse * axis[0]; ny = inverse * axis[1]; nz = inverse * axis[2];
            sine = (float)sin(magnitude);
            cosine = (float)cos(magnitude);
            temp = lbl_80563058 - cosine;
            rotation[0] = cosine + temp * (nx * nx);
            rotation[1] = ny * (temp * nx) + sine * nz;
            rotation[2] = nz * (temp * nx) - sine * ny;
            rotation[3] = ny * (temp * nx) - sine * nz;
            rotation[4] = cosine + temp * (ny * ny);
            rotation[5] = nz * (temp * ny) + sine * nx;
            rotation[6] = nz * (temp * nx) + sine * ny;
            rotation[7] = nz * (temp * ny) - sine * nx;
            rotation[8] = cosine + temp * (nz * nz);
        } else {
            rotation[0] = lbl_80563058; rotation[1] = lbl_8056305C; rotation[2] = lbl_8056305C;
            rotation[3] = lbl_8056305C; rotation[4] = lbl_80563058; rotation[5] = lbl_8056305C;
            rotation[6] = lbl_8056305C; rotation[7] = lbl_8056305C; rotation[8] = lbl_80563058;
        }
    }
    if (((float *)((unsigned char *)object + 0x94)) != rotation) {
        if (((float *)((unsigned char *)object + 0x94)) != ((float *)((unsigned char *)object + 0x34))) {
            float a0 = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[0], ((float *)((unsigned char *)object + 0x34))[3], rotation[1], ((float *)((unsigned char *)object + 0x34))[6], rotation[2]);
            float a1 = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[3], ((float *)((unsigned char *)object + 0x34))[3], rotation[4], ((float *)((unsigned char *)object + 0x34))[6], rotation[5]);
            float a2 = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[6], ((float *)((unsigned char *)object + 0x34))[3], rotation[7], ((float *)((unsigned char *)object + 0x34))[6], rotation[8]);
            float b0 = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[0], ((float *)((unsigned char *)object + 0x34))[4], rotation[1], ((float *)((unsigned char *)object + 0x34))[7], rotation[2]);
            float b1 = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[3], ((float *)((unsigned char *)object + 0x34))[4], rotation[4], ((float *)((unsigned char *)object + 0x34))[7], rotation[5]);
            float b2 = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[6], ((float *)((unsigned char *)object + 0x34))[4], rotation[7], ((float *)((unsigned char *)object + 0x34))[7], rotation[8]);
            float c0 = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[0], ((float *)((unsigned char *)object + 0x34))[5], rotation[1], ((float *)((unsigned char *)object + 0x34))[8], rotation[2]);
            float c1 = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[3], ((float *)((unsigned char *)object + 0x34))[5], rotation[4], ((float *)((unsigned char *)object + 0x34))[8], rotation[5]);
            float c2 = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[6], ((float *)((unsigned char *)object + 0x34))[5], rotation[7], ((float *)((unsigned char *)object + 0x34))[8], rotation[8]);
            ((float *)((unsigned char *)object + 0x94))[0]=a0; ((float *)((unsigned char *)object + 0x94))[3]=a1; ((float *)((unsigned char *)object + 0x94))[6]=a2;
            ((float *)((unsigned char *)object + 0x94))[1]=b0; ((float *)((unsigned char *)object + 0x94))[4]=b1; ((float *)((unsigned char *)object + 0x94))[7]=b2;
            ((float *)((unsigned char *)object + 0x94))[2]=c0; ((float *)((unsigned char *)object + 0x94))[5]=c1; ((float *)((unsigned char *)object + 0x94))[8]=c2;
        } else {
            ((float *)((unsigned char *)object + 0x94))[0] = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[0], ((float *)((unsigned char *)object + 0x34))[3], rotation[1], ((float *)((unsigned char *)object + 0x34))[6], rotation[2]);
            ((float *)((unsigned char *)object + 0x94))[3] = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[3], ((float *)((unsigned char *)object + 0x34))[3], rotation[4], ((float *)((unsigned char *)object + 0x34))[6], rotation[5]);
            ((float *)((unsigned char *)object + 0x94))[6] = fn_80144514(((float *)((unsigned char *)object + 0x34))[0], rotation[6], ((float *)((unsigned char *)object + 0x34))[3], rotation[7], ((float *)((unsigned char *)object + 0x34))[6], rotation[8]);
            ((float *)((unsigned char *)object + 0x94))[1] = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[0], ((float *)((unsigned char *)object + 0x34))[4], rotation[1], ((float *)((unsigned char *)object + 0x34))[7], rotation[2]);
            ((float *)((unsigned char *)object + 0x94))[4] = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[3], ((float *)((unsigned char *)object + 0x34))[4], rotation[4], ((float *)((unsigned char *)object + 0x34))[7], rotation[5]);
            ((float *)((unsigned char *)object + 0x94))[7] = fn_80144514(((float *)((unsigned char *)object + 0x34))[1], rotation[6], ((float *)((unsigned char *)object + 0x34))[4], rotation[7], ((float *)((unsigned char *)object + 0x34))[7], rotation[8]);
            ((float *)((unsigned char *)object + 0x94))[2] = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[0], ((float *)((unsigned char *)object + 0x34))[5], rotation[1], ((float *)((unsigned char *)object + 0x34))[8], rotation[2]);
            ((float *)((unsigned char *)object + 0x94))[5] = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[3], ((float *)((unsigned char *)object + 0x34))[5], rotation[4], ((float *)((unsigned char *)object + 0x34))[8], rotation[5]);
            ((float *)((unsigned char *)object + 0x94))[8] = fn_80144514(((float *)((unsigned char *)object + 0x34))[2], rotation[6], ((float *)((unsigned char *)object + 0x34))[5], rotation[7], ((float *)((unsigned char *)object + 0x34))[8], rotation[8]);
        }
    }
    obj[0xB8 / 4] = obj[0x58 / 4];
    obj[0xBC / 4] = obj[0x5C / 4];
    obj[0xC0 / 4] = obj[0x60 / 4];
    fn_801E3284((unsigned char *)object + 0x64,
                *(void **)((unsigned char *)object + 0x1C), (int)((unsigned int *)(scratch + 0x240)));
    {
        float *base = (float *)(scratch + 0x38);
        *(int *)(scratch + 4) = 0x20;
        base[0] = lbl_8056305C; base[1] = lbl_8056305C; base[2] = lbl_8056305C;
        base[3] = lbl_8056305C; base[4] = lbl_8056305C; base[5] = lbl_8056305C;
        base[6] = lbl_8056305C; base[7] = lbl_80563058; base[8] = lbl_8056305C;
        base[9] = lbl_8056305C; base[10] = lbl_80563084; base[11] = lbl_8056305C;
        fn_801C2694(*(void **)object, (int *)(scratch + 0x2B8),
                    (float *)(scratch + 4), base + 9, base + 6,
                    base + 3, base, lbl_80563058, lbl_8056305C);
    }
    *(int *)scratch = 0x20;
    fn_801E5998(*(void **)((unsigned char *)object + 0x0C),
                (void *)(scratch + 0x438), (void *)scratch);
}
#pragma scheduling on
