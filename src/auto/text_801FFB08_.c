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
