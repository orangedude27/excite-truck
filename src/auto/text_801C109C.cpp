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
void fn_801C1218(void);
void fn_801C1364(int);
void fn_801C1320(void*);
void fn_801C1B60(int arg0);
extern "C" void fn_801C1218(void);
extern "C" void fn_801C1364(int);
extern "C" void fn_801C1320(void*);
extern "C" void fn_801C1B60(int arg0) {
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
extern float lbl_80562928;
extern "C" float PSQUATMultiply(void *, void *, void *);
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

#pragma push
#pragma ppc_psq_save off
extern "C" void fn_801C28A8(void *arg0, int arg1, float *arg2, void *arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    float v5C[3], v50[3], v44[3], v38[3], v2C[3], v20[3], v14[3], v8[3];
    float f22, f23, f24, f25, f26, f27, f28, f29, f30, f31;
    int i, off, idx, limit;

    limit = arg6;
    if (arg6 < 0)
        limit = *(int *)((char *)arg0 + 0x14);
    GXInitLightAttnA_80144B44(v8, lbl_80562904, lbl_80562904, lbl_80562904);
    GXInitLightAttnA_80144B44(v14, lbl_80562904, lbl_80562904, lbl_80562904);
    f30 = lbl_80562904;
    f31 = lbl_80562934;
    f26 = f30;
    f25 = lbl_80562938;
    f27 = f30;
    f28 = f30;
    f29 = lbl_80562940;
    i = arg5;
    off = arg5 * 0xC;
    idx = arg5 * 4;
    for (; i < limit; i++, off += 0xC, idx += 4) {
        if (*(int *)(*(int *)((char *)arg0 + 0x38) + idx) == 0)
            continue;
        {
            float f3 = *(float *)(*(int *)((char *)arg0 + 0x30) + idx);
            float x, y, z;
            x = arg2[0] + f3;
            y = arg2[1] + f3;
            z = arg2[2] + f3;
            f22 = f31 + x;
            f23 = f31 + y;
            f24 = f31 + z;
            fn_80144D64((int *)v20, (int *)(*(int *)((char *)arg0 + 0x24) + off));
            fn_8001BA68(v2C);
            fn_80144CD0(v2C, v20, arg1);
            fn_8001BA68(v38);
            fn_8001BA68(v44);
            fn_80144D64((int *)v50, (int *)arg3);
            fn_801C2B9C(v44, (float *)(*(int *)((char *)arg0 + 0x28) + off), v50, lbl_80562900);
            fn_80144CD0(v38, v44, arg1);
            if (fn_8017F70C(v2C[0]) >= f22)
                continue;
            if (fn_8017F70C(v2C[1]) >= f23)
                continue;
            if (fn_8017F70C(v2C[2]) >= f24)
                continue;
            if (fn_8017F70C(v38[0]) > f25 + f22) {
                if (v2C[0] < f26)
                    f22 = -f22;
                v2C[0] = f22;
            }
            if (fn_8017F70C(v38[1]) >= f25 + f23) {
                if (v2C[1] > f27)
                    v2C[1] = f23;
                else
                    v2C[1] = -f23;
            }
            if (fn_8017F70C(v38[2]) >= f25 + f24) {
                if (v2C[2] > f28)
                    v2C[2] = f24;
                else
                    v2C[2] = -f24;
            }
            fn_801BFD34((int *)(*(int *)((char *)arg0 + 0x24) + off), v2C, arg1);
            fn_8001BA68(v5C);
            fn_801C0E60(v5C, v20, (int *)(*(int *)((char *)arg0 + 0x24) + off));
            f24 = fn_801429D0(fn_801C0E44(v5C), lbl_8056293C);
            fn_801C2B9C(v14, v14, v5C, f29 * *(float *)(*(int *)((char *)arg0 + 0x34) + idx));
            fn_801C2B9C(v8, v8, (float *)(*(int *)((char *)arg0 + 0x24) + off), f24);
            f30 += f24;
        }
    }
    if (arg7 != 0)
        fn_801C0124(arg7, v8, lbl_8056290C / fn_801429D0(f30, lbl_80562944));
    if (arg8 != 0)
        fn_80144DAC((void *)arg8, v14);
}
#pragma pop
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

