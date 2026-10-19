// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" {
void GXInitLightAttnA_80144B44(void *, float, float, float);
void fn_8001BA68(float *);
float fn_801429D0(float, float);
void fn_80144CD0(float *, float *, int);
void fn_80144D64(int *, int *);
void fn_80144DAC(void *, float *);
float fn_8017F70C(float);
void fn_801BFD34(int *, float *, int);
void fn_801C0124(int, float *, float);
float fn_801C0E44(float *);
void fn_801C0E60(float *, float *, int *);
void fn_801C2B9C(float *, float *, float *, float);
extern float lbl_80562900, lbl_80562904, lbl_8056290C;
extern float lbl_80562934, lbl_80562938, lbl_8056293C, lbl_80562940, lbl_80562944;
}

extern void fn_801C1218(void);
extern void fn_801C1364(int);
extern "C" int fn_801284F8(int, int *);
extern int fn_801C109C(int, int, int, int);
extern int fn_80128668(int);
extern int lbl_8055A950;
extern "C" int __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int);
extern int fn_80128670(int);
int *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*arg0);
        if (arg1 > 0) fn_80128668((int)arg0);
    }
    return arg0;
}

void fn_801C1320(void* arg0) {
    int i = 0;
    int offset = 0;
    while (i < *(int*)((char*)arg0 + 0x14)) {
        float* dst = *(float**)((char*)arg0 + 0x2C);
        float* out = (float*)((char*)dst + offset);
        out[0] = *(float*)((char*)arg0 + 0x3C);
        out[1] = *(float*)((char*)arg0 + 0x40);
        out[2] = *(float*)((char*)arg0 + 0x44);
        ++i;
        offset += 12;
    }
}

#pragma dont_inline on
extern void fn_801C1B60(int);
#pragma force_active on
void fn_801C1B60(int arg0) {
    fn_801C1218();
    fn_801C1364(arg0);
    fn_801C1320((void*)arg0);
}
#pragma force_active reset
void fn_801C1B9C(void) {
    return;
}

void fn_801C1BA0(void) {
    return;
}

int fn_801C1BA4(int arg0, int arg1, int arg2) {
    int result;
    result = fn_801284F8(0x70, &lbl_8055A950);
    if (result == 0) return result;
    fn_801C109C(arg0, arg1, arg2, 0);
    return result;
}

extern "C" int fn_801C109C(int, int, int, int);
extern "C" int fn_801C109C(int, int, int, int, int);
extern "C" int fn_801C1C1C(void *arg0) {
    int result = fn_801284F8(0x70, &lbl_8055A950);
    if (result != 0) {
        fn_801C109C(result,
                    *(int *)((char *)arg0 + 0x10),
                    *(int *)((char *)arg0 + 0x14),
                    *(int *)((char *)arg0 + 0x18),
                    *(int *)((char *)arg0 + 0x1C));
    }
    return result;
}

void fn_801C1C7C(int arg0) {
    if (arg0 != 0) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(0);
        fn_80128668(arg0);
    }
}

extern float lbl_80562930;
void fn_801C27D8(void *arg0, float *arg1, float *arg2, float *arg3) {
    float x = arg3[0] * lbl_80562930;
    float y = arg3[1] * lbl_80562930;
    float z = arg3[2] * lbl_80562930;
    int i = 0;
    int offset = 0;
    *(float *)((char *)arg0 + 0x58) = arg1[0];
    *(float *)((char *)arg0 + 0x5C) = arg1[1];
    *(float *)((char *)arg0 + 0x60) = arg1[2];
    *(float *)((char *)arg0 + 0x64) = arg2[0];
    *(float *)((char *)arg0 + 0x68) = arg2[1];
    *(float *)((char *)arg0 + 0x6C) = arg2[2];
    do {
        float *dst = *(float **)((char *)arg0 + 0x2C);
        float *p = (float *)((char *)dst + offset);
        ++i;
        p[0] += x;
        offset += 12;
        p[1] += y;
        p[2] += z;
    } while (i < *(int *)((char *)arg0 + 0x14));
    fn_801C1B60((int)arg0);
}

void fn_801C2B9C(float* out, float* a, float* b, float scale) {
    out[1] = a[1] + b[1] * scale;
    out[0] = a[0] + b[0] * scale;
    out[2] = a[2] + b[2] * scale;
}

void fn_801C2BDC(void *arg0, unsigned int *arg1, unsigned int *arg2, unsigned int *arg3) {
    *arg1 = *(unsigned int *)((unsigned char *)arg0 + 0x14);
    *arg2 = *(unsigned int *)((unsigned char *)arg0 + 0x24);
    *arg3 = *(unsigned int *)((unsigned char *)arg0 + 0x28);
}

