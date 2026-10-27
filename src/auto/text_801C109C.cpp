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

extern "C" void fn_801C1218(void *);
extern "C" void fn_801C1364(int);
extern "C" void fn_801C1320(void*);
extern "C" void fn_801C1B60(int);
extern "C" int fn_801284F8(int, int *);
extern int fn_801C109C(int, int, int, int);
extern "C" int fn_80128668(int);
extern int lbl_8055A950;
extern "C" int __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int, int);
extern "C" int fn_80128670(int);
#pragma dont_inline on
extern "C" int fn_8012850C(int, const char *);
extern "C" char lbl_80336AF0[];
extern "C" float lbl_80562908;
extern "C" int fn_801C109C(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int *base = (int *)arg0;
    int size1 = arg2 * 0x14;
    base[2] = arg2;
    base[1] = arg1;
    int size2 = arg3 * 0x18;
    base[3] = arg3;
    int size3 = arg4 * 0x1C;
    base[4] = arg4;
    int size4 = arg1 * 0x30;
    int total = size3 + size4;
    int size = size2 + size1;
    int memory = fn_8012850C(total + size, lbl_80336AF0);
    int step12 = arg1 * 0xC;
    base[0] = memory;
    base[9] = memory;
    int p = memory + step12;
    base[10] = p;
    p += step12;
    base[11] = p;
    p += step12;
    base[12] = p;
    int step4 = arg1 * 4;
    p += step4;
    base[13] = p;
    p += step4;
    base[14] = p;
    p += step4;
    base[18] = p;
    p += size1;
    base[19] = p;
    p += size2;
    if (arg4 > 0) base[20] = p;
    else base[20] = 0;
    register float a = lbl_8056290C;
    register float b = lbl_80562908;
    register float c = lbl_80562904;
    register float d = lbl_80562900;
    base[5] = 0;
    base[6] = 0;
    base[7] = 0;
    base[8] = 0;
    *(float *)(arg0 + 0x54) = d;
    *(float *)(arg0 + 0x3C) = c;
    *(float *)(arg0 + 0x40) = b;
    *(float *)(arg0 + 0x44) = c;
    *(float *)(arg0 + 0x64) = c;
    *(float *)(arg0 + 0x68) = a;
    *(float *)(arg0 + 0x6C) = c;
    *(float *)(arg0 + 0x58) = c;
    *(float *)(arg0 + 0x5C) = c;
    *(float *)(arg0 + 0x60) = c;
    return arg0;
}

extern "C" int __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*(int *)arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma dont_inline reset
extern float lbl_80562910, lbl_80562914;
void fn_801C1218(void *arg0) {
    char *base = (char *)arg0;
    int count = 0;
    register float factor0 = lbl_80562910;
    int offset = 0;
    register float factor1 = lbl_80562914;
    char *p0;
    char *p1;
    char *p2;
    float x;
    float y;
    float z;
    float scale;
    volatile unsigned int savedX;
    volatile unsigned int savedY;
    volatile unsigned int savedZ;

    goto check;
loop:
    count += 1;
    p0 = *(char **)(base + 0x24) + offset;
    p1 = *(char **)(base + 0x28) + offset;
    p2 = *(char **)(base + 0x2C) + offset;

    x = *(float *)(p0 + 0);
    savedX = *(unsigned int *)(p0 + 0);
    x = x * factor0;
    y = *(float *)(p0 + 4);
    savedY = *(unsigned int *)(p0 + 4);
    offset += 0xC;
    z = *(float *)(p0 + 8);
    savedZ = *(unsigned int *)(p0 + 8);
    *(float *)(p0 + 0) = x;
    x = *(volatile float *)&savedX;
    y = *(float *)(p0 + 4) * factor0;
    *(float *)(p0 + 4) = y;
    z = *(float *)(p0 + 8) * factor0;
    *(float *)(p0 + 8) = z;

    x += *(float *)(p1 + 0) * factor1;
    *(float *)(p0 + 0) = x;
    y += *(float *)(p1 + 4) * factor1;
    *(float *)(p0 + 4) = y;
    z += *(float *)(p1 + 8) * factor1;
    *(float *)(p0 + 8) = z;

    scale = *(float *)(base + 0x54);
    scale = scale * scale;
    *(float *)(p0 + 0) = x + *(float *)(p2 + 0) * scale;
    *(float *)(p0 + 4) = y + *(float *)(p2 + 4) * scale;
    *(float *)(p0 + 8) = z + *(float *)(p2 + 8) * scale;

    *(float *)(p1 + 0) = *(volatile float *)&savedX;
    *(float *)(p1 + 4) = *(volatile float *)&savedY;
    *(float *)(p1 + 8) = *(volatile float *)&savedZ;
check:
    if (count < *(int *)(base + 0x14))
        goto loop;
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801C1320(void *arg0) {
    int offset;
    int i;
    char *dst;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)arg0 + 0x14)) {
        dst = *(char * volatile *)((char *)arg0 + 0x2C);
        i++;
        *(float *)(dst + offset) = *(float *)((char *)arg0 + 0x3C);
        float *out = (float *)(dst + offset);
        offset += 12;
        out[1] = *(float *)((char *)arg0 + 0x40);
        out[2] = *(float *)((char *)arg0 + 0x44);
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern void fn_801C1B60(int);
#pragma force_active on
void fn_801C1218(void *);
void fn_801C1364(int);
void fn_801C1320(void*);
void fn_801C1B60(int arg0);
extern "C" void fn_801C1218(void *);
extern "C" void fn_801C1364(int);
extern "C" void fn_801C1320(void*);
#pragma dont_inline on
extern "C" void fn_801C1B60(int arg0) {
    fn_801C1218((void *)arg0);
    fn_801C1364(arg0);
    fn_801C1320((void*)arg0);
}
#pragma dont_inline reset
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
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(arg0, 0);
        fn_80128668(arg0);
    }
}

extern float lbl_8056292C;
extern "C" void PSVECCrossProduct(const float *, const float *, float *);
extern "C" void PSVECCrossProduct(const float *, const float *, float *);
extern "C" void fn_801C256C(void *arg0, float *arg1, float *arg2, float *arg3) {
    char *base = (char *)arg0;
    float cross[3];
    float delta[3];
    int index = 0;
    int offset = 0;
    register float scale = lbl_8056292C;
    goto check;
loop:
    {
        float dx = *(float *)(*(char **)(base + 0x24) + offset) - arg2[0];
        float dy = *(float *)(*(char **)(base + 0x24) + offset + 4) - arg2[1];
        float dz = *(float *)(*(char **)(base + 0x24) + offset + 8) - arg2[2];
        delta[0] = dx;
        delta[1] = dy;
        delta[2] = dz;
        PSVECCrossProduct(arg3, delta, cross);
        index++;
        float x = cross[0] + arg1[0];
        float y = cross[1] + arg1[1];
        float z = cross[2] + arg1[2];
        cross[0] = x;
        cross[1] = y;
        cross[2] = z;
        *(float *)(*(char **)(base + 0x28) + offset) =
            *(float *)(*(char **)(base + 0x24) + offset) + x * scale;
        offset += 0xC;
        *(float *)(*(char **)(base + 0x28) + offset - 8) =
            *(float *)(*(char **)(base + 0x24) + offset - 8) + y * scale;
        *(float *)(*(char **)(base + 0x28) + offset - 4) =
            *(float *)(*(char **)(base + 0x24) + offset - 4) + z * scale;
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
extern "C" void fn_801C27D8(void *arg0, float *arg1, float *arg2, float *arg3) {
    float f5 = arg3[0] * lbl_80562930;
    float f4 = arg3[1] * lbl_80562930;
    float f0 = arg3[2] * lbl_80562930;
    float a0 = arg1[0];
    float a1 = arg1[1];
    float a2 = arg1[2];
    float b0 = arg2[0];
    float b1 = arg2[1];
    float b2 = arg2[2];
    int i = 0;
    int off = 0;

    *(float *)((char *)arg0 + 0x58) = a0;
    *(float *)((char *)arg0 + 0x5C) = a1;
    *(float *)((char *)arg0 + 0x60) = a2;
    *(float *)((char *)arg0 + 0x64) = b0;
    *(float *)((char *)arg0 + 0x68) = b1;
    *(float *)((char *)arg0 + 0x6C) = b2;
    goto check;
loop:
    {
        float *p = (float *)(*(char **)((char *)arg0 + 0x2C) + off);
        ++i;
        p[0] += f5;
        off += 0xC;
        p[1] += f4;
        p[2] += f0;
    }
check:
    if (i < *(int *)((char *)arg0 + 0x14))
        goto loop;
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
void fn_801C2B9C(float *out, float *a, float *b, float scale) {
    float x = a[0] + b[0] * scale;
    float y = a[1] + b[1] * scale;
    float z = a[2] + b[2] * scale;
    out[1] = y;
    out[0] = x;
    out[2] = z;
}

extern "C" void fn_801C2BDC(void *arg0, unsigned int *arg1, unsigned int *arg2, unsigned int *arg3) {
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
    volatile float inA[3];
    volatile float inB[3];
    volatile float outA[3];
    volatile float outB[3];
    register volatile float *pInA = inA;
    register volatile float *pInB = inB;
    register volatile float *pOutA = outA;
    register volatile float *pOutB = outB;

    if (count <= 0) return;
    color = lbl_8055E7C8;
    goto check;
loop:
    {
        int *indices = *(int **)(base + 0x48);
        unsigned char *points = *(unsigned char **)(base + 0x24);
        int first = *(int *)((char *)indices + offset);
        int second = *(int *)((char *)indices + offset + 4);
        *(volatile unsigned int *)&pInA[0] = *(unsigned int *)(points + first * 12);
        *(volatile unsigned int *)&pInA[1] = *(unsigned int *)(points + first * 12 + 4);
        *(volatile unsigned int *)&pInA[2] = *(unsigned int *)(points + first * 12 + 8);
        *(volatile unsigned int *)&pInB[0] = *(unsigned int *)(points + second * 12);
        *(volatile unsigned int *)&pInB[1] = *(unsigned int *)(points + second * 12 + 4);
        *(volatile unsigned int *)&pInB[2] = *(unsigned int *)(points + second * 12 + 8);
        if (pOutA == pInA) {
            pOutA[0] = pInA[2] * matrix[6] + (pInA[0] * matrix[0] + pInA[1] * matrix[3]);
            pOutA[1] = pInA[2] * matrix[7] + (pInA[0] * matrix[1] + pInA[1] * matrix[4]);
            pOutA[2] = pInA[2] * matrix[8] + (pInA[0] * matrix[2] + pInA[1] * matrix[5]);
        } else {
            pOutA[0] = pInA[2] * matrix[6] + (pInA[0] * matrix[0] + pInA[1] * matrix[3]);
            pOutA[1] = pInA[2] * matrix[7] + (pInA[0] * matrix[1] + pInA[1] * matrix[4]);
            pOutA[2] = pInA[2] * matrix[8] + (pInA[0] * matrix[2] + pInA[1] * matrix[5]);
        }
        pOutA[0] += matrix[9];
        pOutA[1] += matrix[10];
        pOutA[2] += matrix[11];
        if (pOutB == pInB) {
            pOutB[0] = pInB[2] * matrix[6] + (pInB[0] * matrix[0] + pInB[1] * matrix[3]);
            pOutB[1] = pInB[2] * matrix[7] + (pInB[0] * matrix[1] + pInB[1] * matrix[4]);
            pOutB[2] = pInB[2] * matrix[8] + (pInB[0] * matrix[2] + pInB[1] * matrix[5]);
        } else {
            pOutB[0] = pInB[2] * matrix[6] + (pInB[0] * matrix[0] + pInB[1] * matrix[3]);
            pOutB[1] = pInB[2] * matrix[7] + (pInB[0] * matrix[1] + pInB[1] * matrix[4]);
            pOutB[2] = pInB[2] * matrix[8] + (pInB[0] * matrix[2] + pInB[1] * matrix[5]);
        }
        pOutB[0] += matrix[9];
        pOutB[1] += matrix[10];
        pOutB[2] += matrix[11];
        fn_801E41D8((float *)pOutA, (float *)pOutB, color, lbl_80562948);
        offset += 0x14;
        i++;
    }
check:
    if (i < count) goto loop;
}
