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

extern "C" void fn_801C1218(void);
extern "C" void fn_801C1364(int);
extern "C" void fn_801C1320(void*);
extern "C" void fn_801C1B60(int);
extern "C" int fn_801284F8(int, int *);
extern int fn_801C109C(int, int, int, int);
extern int fn_80128668(int);
extern int lbl_8055A950;
extern "C" void __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int);
extern int fn_80128670(int);
int *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*arg0);
        if (arg1 > 0) fn_80128668((int)arg0);
    }
    return arg0;
}

extern float lbl_80562910, lbl_80562914;
void fn_801C1218(void *arg0) {
    char *base = (char *)arg0;
    int i = 0;
    int count = 0;
    char *p0, *p1, *p2;
    float sp8, spC, sp10;
    float f4, f5, f6, f4b, f5b, f6b;
    float f9, f9b;
    goto check;
loop:
    count += 1;
    p0 = *(char **)(base + 0x24) + i;
    p1 = *(char **)(base + 0x28) + i;
    p2 = *(char **)(base + 0x2C) + i;
    sp8 = *(float *)(p0 + 0);
    f6 = *(float *)(p0 + 0) * lbl_80562910;
    spC = *(float *)(p0 + 4);
    i += 0xC;
    *(float *)(p0 + 0) = f6;
    f5 = *(float *)(p0 + 4) * lbl_80562910;
    sp10 = *(float *)(p0 + 8);
    *(float *)(p0 + 4) = f5;
    f4 = *(float *)(p0 + 8) * lbl_80562910;
    *(float *)(p0 + 8) = f4;
    f6b = f6 + *(float *)(p1 + 0) * lbl_80562914;
    *(float *)(p0 + 0) = f6b;
    f5b = f5 + *(float *)(p1 + 4) * lbl_80562914;
    *(float *)(p0 + 4) = f5b;
    f4b = f4 + *(float *)(p1 + 8) * lbl_80562914;
    *(float *)(p0 + 8) = f4b;
    f9 = *(float *)(base + 0x54);
    f9b = f9 * f9;
    *(float *)(p0 + 0) = f6b + *(float *)(p2 + 0) * f9b;
    *(float *)(p0 + 4) = f5b + *(float *)(p2 + 4) * f9b;
    *(float *)(p0 + 8) = f4b + *(float *)(p2 + 8) * f9b;
    *(float *)(p1 + 0) = sp8;
    *(float *)(p1 + 4) = spC;
    *(float *)(p1 + 8) = sp10;
check:
    if (count < *(int *)(base + 0x14))
        goto loop;
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
extern "C" void fn_801C1B9C(void) {
}

extern "C" void fn_801C1BA0(void) {
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

extern "C" void fn_801C1C7C(int arg0) {
    if (arg0 != 0) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(0);
        fn_80128668(arg0);
    }
}

extern float lbl_8056292C;
extern void PSVECCrossProduct(const float *, const float *, float *);
extern "C" void PSVECCrossProduct(const float *, const float *, float *);
extern "C" void fn_801C256C(void *arg0, float *arg1, float *arg2, float *arg3) {
    char *base = (char *)arg0;
    float cross[3];
    float delta[3];
    int index = 0;
    int offset = 0;
    float scale = lbl_8056292C;
    goto check;
loop:
    {
        float *src = (float *)(*(char **)(base + 0x24) + offset);
        float *dst = (float *)(*(char **)(base + 0x28) + offset);
        delta[0] = src[0] - arg2[0];
        delta[1] = src[1] - arg2[1];
        delta[2] = src[2] - arg2[2];
        PSVECCrossProduct(arg3, delta, cross);
        index++;
        cross[0] += arg1[0];
        cross[1] += arg1[1];
        cross[2] += arg1[2];
        dst[0] = src[0] + cross[0] * scale;
        offset += 0xC;
        dst[1] = src[1] + cross[1] * scale;
        dst[2] = src[2] + cross[2] * scale;
    }
check:
    if (index < *(int *)(base + 0x14))
        goto loop;
}

extern "C" void fn_801C2694(void *arg0, float *arg1, int *arg2, float *arg3, float *arg4, float *arg5) {
    extern float lbl_80562930;
    float sp8, spC, sp10;
    float f5 = arg5[0] * lbl_80562930;
    float f4 = arg5[1] * lbl_80562930;
    float f0 = arg5[2] * lbl_80562930;
    int i = 0;
    int off = 0;
    float *dst = arg1;
    *(float *)((char *)arg0 + 0x58) = arg3[0];
    *(float *)((char *)arg0 + 0x5C) = arg3[1];
    *(float *)((char *)arg0 + 0x60) = arg3[2];
    *(float *)((char *)arg0 + 0x64) = arg4[0];
    *(float *)((char *)arg0 + 0x68) = arg4[1];
    *(float *)((char *)arg0 + 0x6C) = arg4[2];
    sp8 = f5;
    spC = f4;
    sp10 = f0;
    goto check1;
loop1:
    {
        float *p = (float *)(*(char **)((char *)arg0 + 0x2C) + off);
        ++i;
        p[0] += f5;
        off += 0xC;
        p[1] += f4;
        p[2] += f0;
    }
check1:
    if (i < *(int *)((char *)arg0 + 0x14))
        goto loop1;
    fn_801C1B60((int)arg0);
    {
        int count = *(int *)((char *)arg0 + 0x14);
        float *src = *(float **)((char *)arg0 + 0x24);
        i = 0;
        off = 0;
        goto check2;
loop2:
        {
            float *p = (float *)((char *)src + off);
            ++i;
            off += 0xC;
            dst[0] = p[0];
            dst[1] = p[1];
            dst[2] = p[2];
            dst += 3;
        }
check2:
        if (i < count)
            goto loop2;
        *arg2 = count;
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

extern "C" int lbl_8055E7C8;
extern "C" float lbl_80562948;
extern "C" void fn_801E41D8(float *, float *, int, float);
extern "C" void fn_801C2BF8(void *arg0, float *arg1) {
    char *base = (char *)arg0;
    float *matrix = arg1;
    int count = *(int *)(base + 0x18);
    int i = 0;
    int offset = 0;
    int color;
    float sp2C, sp30, sp34, sp20, sp24, sp28;
    float sp14, sp18, sp1C, sp8, spC, sp10;
    float x, y, z;
    if (count <= 0) return;
    color = lbl_8055E7C8;
    goto check;
loop:
    {
        int *indices = *(int **)(base + 0x48);
        int *points = *(int **)(base + 0x24);
        int first = *(int *)((char *)indices + offset);
        int second = *(int *)((char *)indices + offset + 4);
        float *a = (float *)((char *)points + first * 12);
        float *b = (float *)((char *)points + second * 12);
        sp2C = a[0]; sp30 = a[1]; sp34 = a[2];
        sp20 = b[0]; sp24 = b[1]; sp28 = b[2];
        if (&sp14 == &sp2C) {
            sp14 = sp34 * matrix[6] + (sp2C * matrix[0] + sp30 * matrix[3]);
            sp18 = sp34 * matrix[7] + (sp2C * matrix[1] + sp30 * matrix[4]);
            sp1C = sp34 * matrix[8] + (sp2C * matrix[2] + sp30 * matrix[5]);
        } else {
            sp14 = sp34 * matrix[6] + (sp2C * matrix[0] + sp30 * matrix[3]);
            sp18 = sp34 * matrix[7] + (sp2C * matrix[1] + sp30 * matrix[4]);
            sp1C = sp34 * matrix[8] + (sp2C * matrix[2] + sp30 * matrix[5]);
        }
        sp14 += matrix[9]; sp18 += matrix[10]; sp1C += matrix[11];
        if (&sp8 == &sp20) {
            sp8 = sp28 * matrix[6] + (sp20 * matrix[0] + sp24 * matrix[3]);
            spC = sp28 * matrix[7] + (sp20 * matrix[1] + sp24 * matrix[4]);
            sp10 = sp28 * matrix[8] + (sp20 * matrix[2] + sp24 * matrix[5]);
        } else {
            sp8 = sp28 * matrix[6] + (sp20 * matrix[0] + sp24 * matrix[3]);
            spC = sp28 * matrix[7] + (sp20 * matrix[1] + sp24 * matrix[4]);
            sp10 = sp28 * matrix[8] + (sp20 * matrix[2] + sp24 * matrix[5]);
        }
        x = sp8 + matrix[9];
        y = spC + matrix[10];
        z = sp10 + matrix[11];
        fn_801E41D8(&sp14, &sp8, color, lbl_80562948);
        offset += 0x14;
        i++;
    }
check:
    if (i < count) goto loop;
}
