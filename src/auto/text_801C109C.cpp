// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" float PSQUATMultiply(void *, void *, void *);
extern "C" float lbl_80558DC4[];
extern float lbl_80562928;
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
    unsigned int size1 = (unsigned int)arg2 * 0x14;
    base[2] = arg2;
    base[1] = arg1;
    unsigned int size2 = (unsigned int)arg3 * 0x18;
    base[3] = arg3;
    unsigned int size3 = (unsigned int)arg4 * 0x1C;
    base[4] = arg4;
    unsigned int size4 = (unsigned int)arg1 * 0x30;
    unsigned int total = size3 + size4;
    unsigned int size = size2 + size1;
    int memory = fn_8012850C((int)(total + size), lbl_80336AF0);
    int step12 = arg1 * 0xC;
    base[0] = memory;
    base[9] = memory;
    int p = memory + step12;
    base[10] = p;
    p += step12;
    int step4 = arg1 * 4;
    base[11] = p;
    p += step12;
    base[12] = p;
    p += step4;
    base[13] = p;
    p += step4;
    base[14] = p;
    p += step4;
    base[18] = p;
    p += (int)size1;
    base[19] = p;
    p += (int)size2;
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
    int offset;
    int count;
    count = 0;
    register float factor0 = lbl_80562910;
    offset = 0;
    register float factor1 = lbl_80562914;
    char *p0;
    char *p1;
    char *p2;
    float x;
    float y;
    float z;
    float scale;
    float t0;
    float t1;
    float t2;
    unsigned int savedZ;
    unsigned int savedY;
    unsigned int savedX;
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
    y = *(float *)(p0 + 4) * factor0;
    *(float *)(p0 + 4) = y;
    z = *(float *)(p0 + 8) * factor0;
    *(float *)(p0 + 8) = z;
    t0 = *(float *)(p1 + 0) * factor1;
    x += t0;
    *(float *)(p0 + 0) = x;
    t1 = *(float *)(p1 + 4) * factor1;
    y += t1;
    *(float *)(p0 + 4) = y;
    t2 = *(float *)(p1 + 8) * factor1;
    z += t2;
    *(float *)(p0 + 8) = z;
    scale = *(float *)(base + 0x54);
    scale = scale * scale;
    *(float *)(p0 + 0) = x + *(float *)(p2 + 0) * scale;
    *(float *)(p0 + 4) = y + *(float *)(p2 + 4) * scale;
    *(float *)(p0 + 8) = z + *(float *)(p2 + 8) * scale;
    *(float *)(p1 + 0) = *(float *)&savedX;
    *(float *)(p1 + 4) = *(float *)&savedY;
    *(float *)(p1 + 8) = *(float *)&savedZ;
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

extern "C" float PSVECDotProduct(float *, float *);
extern "C" float PSVECMag(float *);
extern "C" double fn_8002F234();
extern "C" float lbl_80562904, lbl_8056290C, lbl_80562918, lbl_8056291C, lbl_80562920, lbl_80562924;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801C1364(int arg0) {
    register char *base = (char *)arg0;
    int iter;
    register float c90C;
    register float c924;
    register float c920;
    register float c904;
    register float c91C;
    c91C = lbl_8056291C;
    c924 = lbl_80562924;
    c90C = lbl_8056290C;
    c920 = lbl_80562920;
    c904 = lbl_80562904;
    float frame[3];
    float diffA[3];
    float scaled[3];
    float diffB[3];
    float d1[3];
    float d2[3];
    float *out;
    float *m;
    int offset;
    int i;
    char *e;
    float x, y, z, x0, x1, x2, y0, y1, y2, z0, z1, z2;
    for (iter = 0; iter < 2; iter++) {
        for (i = 0, offset = 0; i < *(int *)(base + 0x1C); offset += 0x18, i++) {
            e = *(char **)(base + 0x4C) + offset;
            if (*(unsigned char *)(e + 0x14) != 0) {
                m = *(float **)(e + 4);
                out = (float *)((char *)*(float **)(base + 0x24) + *(int *)e * 12);
                if ((char *)out == e + 8) {
                    y = *(float *)(e + 0xC); x = *(float *)(e + 8); z = *(float *)(e + 0x10);
                    y0 = y * m[3]; y1 = y * m[4];
                    x0 = x * m[0]; x1 = x * m[1]; x2 = x * m[2]; y2 = y * m[5];
                    z0 = z * m[6]; z1 = z * m[7]; z2 = z * m[8];
                    out[0] = z0 + (x0 + y0);
                    out[1] = z1 + (x1 + y1);
                    out[2] = z2 + (x2 + y2);
                } else {
                    out[0] = *(float *)(e + 0x10) * m[6] + (*(float *)(e + 8) * m[0] + *(float *)(e + 0xC) * m[3]);
                    out[1] = *(float *)(e + 0x10) * m[7] + (*(float *)(e + 8) * m[1] + *(float *)(e + 0xC) * m[4]);
                    out[2] = *(float *)(e + 0x10) * m[8] + (*(float *)(e + 8) * m[2] + *(float *)(e + 0xC) * m[5]);
                }
                out[0] += m[9];
                out[1] += m[10];
                out[2] += m[11];
            }
        }
        {
            int stride;
            int count;
            int i1, i2;
            char *en;
            float w2, w1;
            float *p1, *p2;
            float *mat;
            float dot, mag, scale, ratio, fa, fb;
            for (stride = 0, count = 0; count < *(int *)(base + 0x20); stride += 0x1C, count++) {
                en = (char *)*(int **)(base + 0x50) + stride;
                i1 = *(int *)en;
                i2 = *(int *)(en + 4);
                w1 = ((float *)*(char **)(base + 0x34))[i1];
                w2 = ((float *)*(char **)(base + 0x34))[i2];
                p1 = (float *)((char *)*(float **)(base + 0x24) + i1 * 12);
                p2 = (float *)((char *)*(float **)(base + 0x24) + i2 * 12);
                if (((int *)*(char **)(base + 0x38))[i1] == 0) {
                    w2 = lbl_80562918;
                }
                if (((int *)*(char **)(base + 0x38))[i2] == 0) {
                    w1 = lbl_80562918;
                }
                mat = *(float **)(en + 0x18);
                if ((char *)frame == en + 0xC) {
                    y = *(float *)(en + 0x10); x = *(float *)(en + 0xC); z = *(float *)(en + 0x14);
                    y0 = y * mat[3]; y1 = y * mat[4];
                    x0 = x * mat[0]; x1 = x * mat[1]; x2 = x * mat[2]; y2 = y * mat[5];
                    z0 = z * mat[6]; z1 = z * mat[7]; z2 = z * mat[8];
                    frame[0] = z0 + (x0 + y0);
                    frame[1] = z1 + (x1 + y1);
                    frame[2] = z2 + (x2 + y2);
                } else {
                    frame[0] = *(float *)(en + 0x14) * mat[6] + (*(float *)(en + 0xC) * mat[0] + *(float *)(en + 0x10) * mat[3]);
                    frame[1] = *(float *)(en + 0x14) * mat[7] + (*(float *)(en + 0xC) * mat[1] + *(float *)(en + 0x10) * mat[4]);
                    frame[2] = *(float *)(en + 0x14) * mat[8] + (*(float *)(en + 0xC) * mat[2] + *(float *)(en + 0x10) * mat[5]);
                }
                diffA[0] = p2[0] - p1[0];
                diffA[1] = p2[1] - p1[1];
                diffA[2] = p2[2] - p1[2];
                dot = PSVECDotProduct(frame, diffA);
                scaled[0] = frame[0] * dot;
                scaled[1] = frame[1] * dot;
                scaled[2] = frame[2] * dot;
                mag = PSVECMag(scaled);
                scale = mag * (w1 + w2);
                if (scale > c91C) {
                } else {
                    scale = c91C;
                }
                ratio = *(float *)(en + 8) * mag / scale;
                fa = w2 * ratio;
                fb = -w1 * ratio;
                p1[0] += scaled[0] * fa;
                p1[1] += scaled[1] * fa;
                p1[2] += scaled[2] * fa;
                p2[0] += scaled[0] * fb;
                p2[1] += scaled[1] * fb;
                p2[2] += scaled[2] * fb;
            }
        }
        {
            int stride;
            int count;
            int i1, i2;
            char *en;
            float w1, w2;
            float *p1, *p2;
            float mag, scale, ratio, fa, fb;
            for (stride = 0, count = 0; count < *(int *)(base + 0x18); stride += 0x14, count++) {
                en = (char *)*(int **)(base + 0x48) + stride;
                i1 = *(int *)en;
                i2 = *(int *)(en + 4);
                w1 = ((float *)*(char **)(base + 0x34))[i1];
                w2 = ((float *)*(char **)(base + 0x34))[i2];
                p1 = (float *)((char *)*(float **)(base + 0x24) + i1 * 12);
                p2 = (float *)((char *)*(float **)(base + 0x24) + i2 * 12);
                if (((int *)*(char **)(base + 0x38))[i1] == 0) {
                    w2 = lbl_80562918;
                }
                if (((int *)*(char **)(base + 0x38))[i2] == 0) {
                    w1 = lbl_80562918;
                }
                diffB[0] = p2[0] - p1[0];
                diffB[1] = p2[1] - p1[1];
                diffB[2] = p2[2] - p1[2];
                mag = PSVECMag(diffB);
                scale = mag * (w2 + w1);
                if (scale > c91C) {
                } else {
                    scale = c91C;
                }
                ratio = *(float *)(en + 0x10) * (mag - *(float *)(en + 8)) / scale;
                if (*(unsigned char *)(en + 0xC) == 0 || ratio > c904) {
                    fa = w1 * ratio;
                    fb = -w2 * ratio;
                    p1[0] += diffB[0] * fa;
                    p1[1] += diffB[1] * fa;
                    p1[2] += diffB[2] * fa;
                    p2[0] += diffB[0] * fb;
                    p2[1] += diffB[1] * fb;
                    p2[2] += diffB[2] * fb;
                }
            }
        }
        {
            int stride;
            int count;
            int foff;
            float *p;
            float *q;
            float dot, dm;
            for (stride = 0, count = 0, foff = 0; count < *(int *)(base + 0x14); stride += 0xC, count++, foff += 4) {
                p = (float *)((char *)*(float **)(base + 0x24) + stride);
                q = (float *)((char *)*(float **)(base + 0x28) + stride);
                d1[0] = p[0] - q[0];
                d1[1] = p[1] - q[1];
                d1[2] = p[2] - q[2];
                d2[0] = p[0] - *(float *)(base + 0x58);
                d2[1] = p[1] - *(float *)(base + 0x5C);
                d2[2] = p[2] - *(float *)(base + 0x60);
                dot = PSVECDotProduct(d2, (float *)(base + 0x64)) - ((float *)*(char **)(base + 0x30))[foff / 4];
                if (dot < c904) {
                    dot = -dot;
                    p[0] += *(float *)(base + 0x64) * dot;
                    p[1] += *(float *)(base + 0x68) * dot;
                    p[2] += *(float *)(base + 0x6C) * dot;
                    dm = -PSVECDotProduct((float *)(base + 0x64), d1);
                    d1[0] += *(float *)(base + 0x64) * dm;
                    d1[1] += *(float *)(base + 0x68) * dm;
                    d1[2] += *(float *)(base + 0x6C) * dm;
                    if (PSVECDotProduct(d1, d1) > c920) {
                        float denom = (float)fn_8002F234();
                        float r = c924 / denom;
                        if (r > c90C) {
                            r = c90C;
                        }
                        p[0] += d1[0] * -r;
                        p[1] += d1[1] * -r;
                        p[2] += d1[2] * -r;
                    } else {
                        p[0] -= d1[0];
                        p[1] -= d1[1];
                        p[2] -= d1[2];
                    }
                }
            }
        }
    }
}
#pragma pop
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

extern "C" int fn_801C1BA4(int arg0, int arg1, int arg2) {
    int result;
    result = fn_801284F8(0x70, &lbl_8055A950);
    if (result != 0) {
        fn_801C109C(result, arg0, arg1, arg2, 0);
    }
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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_801C1CBC(void *arg0, int arg1, void *arg2, int arg3, void *arg4, int arg5, void *arg6) {
    char *base = (char *)arg0;
    char *src = (char *)arg2;
    *(int *)(base + 0x14) = 0;
    *(int *)(base + 0x18) = 0;
    *(int *)(base + 0x1C) = 0;
    *(int *)(base + 0x20) = 0;
    if (arg1 > 0) {
        unsigned int count = (unsigned int)arg1 >> 1;
        int index;
        float x, y, z;
        char *dst;
        if (count != 0) {
            do {
                for (int pairIter = 0; pairIter < 2; pairIter++) {
                    index = *(int *)(base + 0x14);
                    dst = *(char **)(base + 0x24) + index * 12;
                    index++;
                    *(int *)(base + 0x14) = index;
                    x = *(float *)(src + 0);
                    y = *(float *)(src + 4);
                    z = *(float *)(src + 8);
                    *(float *)dst = x;
                    *(float *)(dst + 4) = y;
                    *(float *)(dst + 8) = z;
                    dst = *(char **)(base + 0x28) + (index - 1) * 12;
                    *(float *)dst = x;
                    *(float *)(dst + 4) = y;
                    *(float *)(dst + 8) = z;
                    dst = *(char **)(base + 0x2C) + (index - 1) * 12;
                    *(float *)dst = lbl_80562904;
                    *(float *)(dst + 4) = lbl_80562904;
                    *(float *)(dst + 8) = lbl_80562904;
                    (*(float **)(base + 0x30))[index - 1] = *(float *)(src + 0x10);
                    (*(float **)(base + 0x34))[index - 1] = *(float *)(src + 0xC);
                    (*(int **)(base + 0x38))[index - 1] = 1;
                    src += 0x14;
                }
                count--;
            } while (count != 0);
        }
        if (((unsigned int)arg1 & 1) != 0) {
            index = *(int *)(base + 0x14);
            dst = *(char **)(base + 0x24) + index * 12;
            index++;
            *(int *)(base + 0x14) = index;
            x = *(float *)(src + 0);
            y = *(float *)(src + 4);
            z = *(float *)(src + 8);
            *(float *)dst = x;
            *(float *)(dst + 4) = y;
            *(float *)(dst + 8) = z;
            dst = *(char **)(base + 0x28) + (index - 1) * 12;
            *(float *)dst = x;
            *(float *)(dst + 4) = y;
            *(float *)(dst + 8) = z;
            dst = *(char **)(base + 0x2C) + (index - 1) * 12;
            *(float *)dst = lbl_80562904;
            *(float *)(dst + 4) = lbl_80562904;
            *(float *)(dst + 8) = lbl_80562904;
            (*(float **)(base + 0x30))[index - 1] = *(float *)(src + 0x10);
            (*(float **)(base + 0x34))[index - 1] = *(float *)(src + 0xC);
            (*(int **)(base + 0x38))[index - 1] = 1;
        }
    }
    {
        char *p = (char *)arg4;
        int i;
        for (i = 0; i < arg3; i++) {
            float factor;
            float v;
            char *q;
            int idx, first, second;
            float bound = lbl_80562928;
            factor = *(float *)(p + 0xC);
            if ((float)__fabs(factor) == lbl_80558DC4[0])
                factor = lbl_8056290C;
            idx = *(int *)(base + 0x18);
            first = *(int *)p;
            second = *(int *)(p + 4);
            v = *(float *)(p + 8);
            *(int *)(base + 0x18) = idx + 1;
            q = *(char **)(base + 0x48) + idx * 0x14;
            *(int *)q = first;
            *(int *)(q + 4) = second;
            v = v + PSQUATMultiply((void *)(*(char **)(base + 0x24) + first * 12), (void *)(*(char **)(base + 0x24) + second * 12), (void *)(long)first);
            *(float *)(q + 8) = v;
            *(float *)(q + 0x10) = (float)__fabs(factor);
            *(unsigned char *)(q + 0xC) = factor < bound;
            p += 0x10;
        }
    }
    {
        char *rec = (char *)arg6;
        int i;
        for (i = 0; i < arg5; i++) {
            int first = *(int *)rec;
            char *transform = *(char **)(rec + 4);
            char *object = *(char **)(rec + 8);
            char *points;
            float diff[3];
            float m[9];
            int index;
            char *q;
            float x, y, z;
            if (object != 0) {
                points = object;
                diff[0] = *(float *)points - *(float *)(points + 0x24);
                diff[1] = *(float *)(points + 4) - *(float *)(points + 0x28);
                diff[2] = *(float *)(points + 8) - *(float *)(points + 0x2C);
                for (int j = 0; j < 9; j++)
                    m[j] = ((float *)points)[j];
            } else {
                points = *(char **)(base + 0x24) + first * 12;
                diff[0] = *(float *)points - *(float *)(transform + 0x24);
                diff[1] = *(float *)(points + 4) - *(float *)(transform + 0x28);
                diff[2] = *(float *)(points + 8) - *(float *)(transform + 0x2C);
                for (int j = 0; j < 9; j++)
                    m[j] = ((float *)transform)[j];
            }
            x = diff[2] * m[6] + (diff[0] * m[0] + diff[1] * m[3]);
            y = diff[2] * m[7] + (diff[0] * m[1] + diff[1] * m[4]);
            z = diff[2] * m[8] + (diff[0] * m[2] + diff[1] * m[5]);
            index = *(int *)(base + 0x1C);
            *(int *)(base + 0x1C) = index + 1;
            q = *(char **)(base + 0x4C) + index * 0x18;
            *(unsigned char *)(q + 0x14) = 1;
            *(int *)q = first;
            *(float **)(q + 4) = (float *)transform;
            *(float *)(q + 8) = x;
            *(float *)(q + 0xC) = y;
            *(float *)(q + 0x10) = z;
            (*(int **)(base + 0x38))[first] = 0;
            rec += 12;
        }
    }
}
#pragma pop
extern "C" double __fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801C2170(void *arg0, void *arg1, float *m) {
    char *a = (char *)arg0;
    char *b = (char *)arg1;
    char *p, *q;
    register float bound;
    float out[3], x, y, z, d, e, zero, x0,x1,x2,y0,y1,y2,z0,z1,z2;
    float *v, *dst, *base;
    int i, j, index, first, second;
    int k;
    int count = *(int *)(b + 0x10);
    *(int *)(a + 0x14) = 0;
    *(int *)(a + 0x18) = 0;
    *(int *)(a + 0x1c) = 0;
    *(int *)(a + 0x20) = 0;
    if (count > 0) {
    zero = lbl_80562904;
    for (i = 0; i < *(int *)(b + 0x10); i++) {
        p = *(char **)b + i * 0x14;
        v = (float *)p;
        if (out == v) {
            y = v[1]; x = v[0]; z = v[2];
            y0=y*m[3]; y1=y*m[4];
            x0=x*m[0]; x1=x*m[1]; x2=x*m[2]; y2=y*m[5];
            z0=z*m[6]; z1=z*m[7]; z2=z*m[8];
            out[0] = z0 + (x0 + y0);
            out[1] = z1 + (x1 + y1);
            out[2] = z2 + (x2 + y2);
        } else {
            out[0] = v[2]*m[6] + (v[0]*m[0] + v[1]*m[3]);
            out[1] = v[2]*m[7] + (v[0]*m[1] + v[1]*m[4]);
            out[2] = v[2]*m[8] + (v[0]*m[2] + v[1]*m[5]);
        }
        x = out[0] + m[9]; y = out[1] + m[10]; z = out[2] + m[11];
        out[0] = x; out[1] = y; out[2] = z;
        e = v[3]; d = v[4];
        index = (*(int *)(a + 0x14))++;
        dst = (float *)((char *)*(float **)(a + 0x24) + index * 12);
        dst[0] = out[0]; dst[1] = out[1]; dst[2] = out[2];
        dst = (float *)((char *)*(float **)(a + 0x28) + index * 12);
        dst[0] = out[0]; dst[1] = out[1]; dst[2] = out[2];
        dst = (float *)((char *)*(float **)(a + 0x2c) + index * 12);
        dst[0] = zero; dst[1] = zero; dst[2] = zero;
        (*(float **)(a + 0x30))[index] = d;
        (*(float **)(a + 0x34))[index] = e;
        (*(int **)(a + 0x38))[index] = 1;
    }
    }
    bound = lbl_80562928;
    for (k = 0; k < *(int *)(b + 0x14); k++) {
        p = *(char **)(b + 4) + k * 0x10;
        index = *(int *)(a + 0x18);
        q = *(char **)(a + 0x48) + index * 0x14;
        e = *(float *)(p + 12); d = *(float *)(p + 8);
        second = *(int *)(p + 4); first = *(int *)p;
        *(int *)(a + 0x18) = index + 1;
        *(int *)q = first; *(int *)(q + 4) = second;
        base = *(float **)(a + 0x24);
        x = PSQUATMultiply((float *)((char *)base + first*12), (float *)((char *)base + second*12), (void *)first);
        y = (float)__fabs(e);
        *(float *)(q + 8) = d + x;
        *(float *)(q + 0x10) = y;
        *(unsigned char *)(q + 0xc) = e < bound;
    }
    j = 0;
    for (i = 0; i < *(int *)(b + 0x18); j += 0xc, i++) {
        p = *(char **)(b + 8) + j;
        index = *(int *)(a + 0x1c);
        q = *(char **)(a + 0x4c) + index * 0x18;
        first = *(int *)p;
        v = *(float **)(p + 8);
        *(int *)(a + 0x1c) = index + 1;
        *(unsigned char *)(q + 0x14) = 1;
        *(int *)q = first;
        *(float **)(q + 4) = m;
        *(float *)(q + 8) = v[0]; *(float *)(q + 0xc) = v[1]; *(float *)(q + 0x10) = v[2];
        (*(int **)(a + 0x38))[first] = 0;
    }
    for (i = 0; i < *(int *)(b + 0x1c); i++) {
        p = *(char **)(b + 0xc) + i * 0x1c;
        index = *(int *)(a + 0x20);
        {
            int *qi = (int *)(*(char **)(a + 0x50)) + index * 7;
            float *qf = (float *)qi;
            d = *(float *)(p + 8); second = *(int *)(p + 4); first = *(int *)p;
            *(int *)(a + 0x20) = index + 1;
            qi[1] = second; qi[0] = first;
            qf[2] = d;
            qf[3] = *(float *)(p + 0xc);
            qf[4] = *(float *)(p + 0x10);
            qf[5] = *(float *)(p + 0x14);
            *(float **)(qi + 6) = m;
        }
    }
}
#pragma pop

extern float lbl_8056292C;
extern "C" void PSVECCrossProduct(const float *, const float *, float *);
extern "C" void PSVECCrossProduct(const float *, const float *, float *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801C256C(void *arg0, float *arg1, float *arg2, float *arg3) {
    char *base = (char *)arg0;
    volatile float cross[3];
    float delta[3];
    int index = 0;
    int offset = 0;
    register float scale = lbl_8056292C;
    goto check;
loop:
    {
        char *sourceData = *(char **)(base + 0x24);
        float cx = arg2[0];
        float cy = arg2[1];
        float cz = arg2[2];
        delta[0] = *(float *)(sourceData + offset) - cx;
        delta[1] = *(float *)(sourceData + offset + 4) - cy;
        delta[2] = *(float *)(sourceData + offset + 8) - cz;
        PSVECCrossProduct(arg3, delta, (float *)cross);
        ++index;
        float x = cross[0] + arg1[0];
        float y = cross[1] + arg1[1];
        float z = cross[2] + arg1[2];
        cross[0] = x;
        cross[1] = y;
        cross[2] = z;
        float xs = x * scale;
        char *srcBase = *(char **)(base + 0x24);
        char *dstBase = *(char **)(base + 0x28);
        float sourceOutX = *(float *)(srcBase + offset);
        char *src = srcBase + offset;
        char *dst = dstBase + offset;
        *(float *)dst = sourceOutX + xs;
        offset += 0xC;
        *(float *)(dstBase + offset + 4 - 0xC) = *(float *)(srcBase + offset + 4 - 0xC) + y * scale;
        *(float *)(dstBase + offset + 8 - 0xC) = *(float *)(srcBase + offset + 8 - 0xC) + z * scale;
    }
check:
    if (index < *(int *)(base + 0x14))
        goto loop;
}
#pragma pop
extern "C" void fn_801C2694(void *arg0, float *arg1, int *arg2, float *arg3, float *arg4, float *arg5) {
    extern float lbl_80562930;
    float sp8, spC, sp10;
    register float f5 = arg5[0] * lbl_80562930;
    register float f4 = arg5[2] * lbl_80562930;
    register float f0 = arg5[1] * lbl_80562930;
    float b2 = arg4[2];
    float b1 = arg4[1];
    float b0 = arg4[0];
    float a2 = arg3[2];
    float a1 = arg3[1];
    float a0 = arg3[0];
    float *p;
    int i = 0;
    int off = 0;
    int i2;
    int off2;

    *(float *)((char *)arg0 + 0x58) = a0;
    *(float *)((char *)arg0 + 0x5C) = a1;
    *(float *)((char *)arg0 + 0x60) = a2;
    *(float *)((char *)arg0 + 0x64) = b0;
    *(float *)((char *)arg0 + 0x68) = b1;
    *(float *)((char *)arg0 + 0x6C) = b2;
    sp8 = f5;
    spC = f0;
    sp10 = f4;
    goto check1;
loop1:
    p = (float *)(*(char **)((char *)arg0 + 0x2C) + off);
    ++i;
    p[0] += f5;
    off += 0xC;
    p[1] += f0;
    p[2] += f4;
check1:
    if (i < *(int *)((char *)arg0 + 0x14))
        goto loop1;

    fn_801C1B60((int)arg0);
    i2 = 0;
    off2 = 0;
    goto check2;
loop2:
    {
        float *q = (float *)(*(char **)((char *)arg0 + 0x24) + off2);
        ++i2;
        off2 += 0xC;
        arg1[0] = q[0];
        arg1[1] = q[1];
        arg1[2] = q[2];
        arg1 += 3;
    }
check2:
    if (i2 < *(int *)((char *)arg0 + 0x14))
        goto loop2;
    *arg2 = i2;
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
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801C28A8(void *arg0, int arg1, float *arg2, void *arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    float v5C[3], v50[3], v44[3], v38[3], v2C[3], v20[3], v14[3], v8[3];
    int limit, idx, off, i;
    float f31, f30, f29, f28, f27, f26, f25, f24, f23, f22;
    limit = arg6;
    if (arg6 < 0)
        limit = *(int *)((char *)arg0 + 0x14);
    GXInitLightAttnA_80144B44(v8, lbl_80562904, lbl_80562904, lbl_80562904);
    GXInitLightAttnA_80144B44(v14, lbl_80562904, lbl_80562904, lbl_80562904);
    f30 = lbl_80562904;
    off = arg5 * 0xC;
    f31 = lbl_80562934;
    f26 = f30;
    f25 = lbl_80562938;
    f27 = f30;
    f28 = f30;
    f29 = lbl_80562940;
    idx = arg5 * 4;
    i = arg5;
    for (; i < limit; idx += 4, off += 0xC, i++) {
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
            if (!(fn_8017F70C(v2C[0]) < f22))
                continue;
            if (!(fn_8017F70C(v2C[1]) < f23))
                continue;
            if (!(fn_8017F70C(v2C[2]) < f24))
                continue;
            if (fn_8017F70C(v38[0]) > f25 + f22) {
                if (v2C[0] >= f26)
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
void fn_801C2B9C(float * __restrict out, float * __restrict a, float * __restrict b, float scale) {
    float x = a[0] + b[0] * scale;
    float y = a[1] + b[1] * scale;
    float z = a[2] + b[2] * scale;
    out[0] = x;
    out[1] = y;
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
struct Vec3f { float x, y, z; };
static inline void Mtx43MultVec(const float *m, const Vec3f *src, Vec3f *dst) {
    if (dst == src) {
        float x = src->z * m[6] + (src->y * m[3] + src->x * m[0]);
        float y = src->z * m[7] + (src->y * m[4] + src->x * m[1]);
        float z = src->z * m[8] + (src->y * m[5] + src->x * m[2]);
        dst->x = x;
        dst->y = y;
        dst->z = z;
    } else {
        float sx = src->x;
        float sy = src->y;
        float sz = src->z;
        float x = sz * m[6] + (sy * m[3] + sx * m[0]);
        float y = sz * m[7] + (sy * m[4] + sx * m[1]);
        float z = sz * m[8] + (sy * m[5] + sx * m[2]);
        dst->x = x;
        dst->y = y;
        dst->z = z;
    }
    {
        float x = dst->x + m[9];
        float y = dst->y + m[10];
        float z = dst->z + m[11];
        dst->x = x;
        dst->y = y;
        dst->z = z;
    }
}
#pragma push
#pragma dont_inline off
extern "C" void fn_801C2BF8(void *arg0, float *arg1) {
    int color;
    int count = *(int *)((char *)arg0 + 0x18);
    int i = 0;
    if (count > 0) {
        color = lbl_8055E7C8;
        for (; i < count; i++) {
            int *indices = (int *)(*(char **)((char *)arg0 + 0x48) + i * 0x14);
            int ia = indices[0];
            int ib = indices[1];
            Vec3f a = (*(Vec3f **)((char *)arg0 + 0x24))[ia];
            Vec3f b = (*(Vec3f **)((char *)arg0 + 0x24))[ib];
            Vec3f outA;
            Vec3f outB;
            Mtx43MultVec(arg1, &a, &outA);
            Mtx43MultVec(arg1, &b, &outB);
            fn_801E41D8(&outA.x, &outB.x, color, lbl_80562948);
        }
    }
}
#pragma pop
