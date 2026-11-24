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
    register float a, b, c, d;
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
    c = lbl_80562904;
    d = lbl_80562900;
    b = lbl_80562908;
    a = lbl_8056290C;
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

/* J2DAnmTexPattern::J2DAnmTexPatternTIMGPointer::~J2DAnmTexPatternTIMGPointer()
 * -- CodeWarrior's deleting destructor.  fn_801C1C1C allocates the 0x70-byte
 * object and fn_801C109C stores at +0 the one block fn_8012850C made for all
 * of its arrays; this frees that block (fn_80128670 is the free routine for
 * fn_8012850C blocks) and, when the destructor was called through delete
 * (flag > 0), the object itself (fn_80128668).  fn_801C1C7C is the release
 * helper that passes 0 here and frees the object itself afterwards. */
extern "C" int __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(int self, int shouldDelete) {
    if (self != 0) {
        fn_80128670(*(int *)self);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}
#pragma dont_inline reset
extern float lbl_80562910, lbl_80562914;
#pragma opt_common_subs off
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
    float z;
    float y;
    float x;
    float scale;
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
    x += *(float *)(p1 + 0) * factor1;
    *(float *)(p0 + 0) = x;
    y += *(float *)(p1 + 4) * factor1;
    *(float *)(p0 + 4) = y;
    z += *(float *)(p1 + 8) * factor1;
    *(float *)(p0 + 8) = z;
    scale = *(float *)(base + 0x54);
    scale = scale * scale;
    *(float *)(p0 + 8) = z + *(float *)(p2 + 8) * scale;
    *(float *)(p0 + 4) = y + *(float *)(p2 + 4) * scale;
    *(float *)(p0 + 0) = x + *(float *)(p2 + 0) * scale;
    *(float *)(p1 + 0) = *(float *)&savedX;
    *(float *)(p1 + 4) = *(float *)&savedY;
    *(float *)(p1 + 8) = *(float *)&savedZ;
check:
    if (count < *(int *)(base + 0x14))
        goto loop;
}
#pragma opt_common_subs reset
void fn_801C1320(void *arg0) {
    /* Fill all output vectors (+0x2C array, count +0x14, stride 12) with vec3 at +0x3C. */
    #define outCount (*(int *)((char *)arg0 + 0x14))
    #define outBase  (*(char * volatile *)((char *)arg0 + 0x2C))
    #define fillX    (*(float *)((char *)arg0 + 0x3C))
    #define fillY    (*(float *)((char *)arg0 + 0x40))
    #define fillZ    (*(float *)((char *)arg0 + 0x44))

    int offset;
    int i;
    char *dst;
    i = 0;
    offset = 0;
    while (i < outCount) {
        dst = outBase;
        i++;
        *(float *)(dst + offset) = fillX;
        float *out = (float *)(dst + offset);
        offset += 12;
        out[1] = fillY;
        out[2] = fillZ;
    }

    #undef outCount
    #undef outBase
    #undef fillX
    #undef fillY
    #undef fillZ
}
extern "C" float PSVECDotProduct(float *, float *);
extern "C" float PSVECMag(float *);
extern "C" double fn_8002F234();
extern "C" float lbl_80562904, lbl_8056290C, lbl_80562918, lbl_8056291C, lbl_80562920, lbl_80562924;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801C1364(int arg0) {
    char *base = (char *)arg0;
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
    int iter;
    for (iter = 0; iter < 2; iter++) {
        for (i = 0, offset = 0; i < *(int *)(base + 0x1C); offset += 0x18, i++) {
            e = *(char **)(base + 0x4C) + offset;
            if (*(unsigned char *)(e + 0x14) != 0) {
                m = *(float **)(e + 4);
                out = (float *)((char *)*(float **)(base + 0x24) + *(int *)e * 12);
                if ((char *)out == e + 8) {
                    y = *(float *)(e + 0xC); x = *(float *)(e + 8);
                    y0 = m[3] * y;
                    x0 = m[0] * x;
                    y1 = m[4] * y;
                    x1 = m[1] * x;
                    z = *(float *)(e + 0x10);
                    z0 = m[6] * z;
                    x2 = m[2] * x;
                    y2 = m[5] * y;
                    z1 = m[7] * z;
                    z2 = m[8] * z;
                    out[0] = z0 + (x0 + y0);
                    out[1] = z1 + (x1 + y1);
                    out[2] = z2 + (x2 + y2);
                } else {
                    out[0] = m[6] * *(float *)(e + 0x10) + (m[0] * *(float *)(e + 8) + m[3] * *(float *)(e + 0xC));
                    out[1] = m[7] * *(float *)(e + 0x10) + (m[1] * *(float *)(e + 8) + m[4] * *(float *)(e + 0xC));
                    out[2] = m[8] * *(float *)(e + 0x10) + (m[2] * *(float *)(e + 8) + m[5] * *(float *)(e + 0xC));
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
            for (count = 0, stride = 0; count < *(int *)(base + 0x20); stride += 0x1C, count++) {
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
                scale = mag * (w2 + w1);
                scale = (scale > c91C) ? scale : c91C;
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
            float w2, w1;
            float *p1, *p2;
            float mag, scale, ratio, fa, fb;
            for (count = 0, stride = 0; count < *(int *)(base + 0x18); stride += 0x14, count++) {
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
                scale = (scale > c91C) ? scale : c91C;
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
            for (count = 0, stride = 0, foff = 0; count < *(int *)(base + 0x14); stride += 0xC, foff += 4, count++) {
                p = (float *)((char *)*(float **)(base + 0x24) + stride);
                q = (float *)((char *)*(float **)(base + 0x28) + stride);
                d1[0] = p[0] - q[0];
                d1[1] = p[1] - q[1];
                d1[2] = p[2] - q[2];
                d2[0] = p[0] - *(float *)(base + 0x58);
                d2[1] = p[1] - *(float *)(base + 0x5C);
                d2[2] = p[2] - *(float *)(base + 0x60);
                dot = PSVECDotProduct(d2, (float *)(base + 0x64)) - *(float *)((char *)*(char **)(base + 0x30) + foff);
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
                        if (c90C < r) {
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
#define IntegrateParticles fn_801C1218  // advance particle positions from velocity/acceleration
#define SolveConstraints   fn_801C1364  // two passes of link/distance constraint corrections
#define WriteOutputs       fn_801C1320  // fill the output vectors
#pragma dont_inline on
// Run one particle-simulation step: integrate positions, solve constraints, then write outputs.
extern "C" void fn_801C1B60(int state) {
    IntegrateParticles((void *)state);
    SolveConstraints(state);
    WriteOutputs((void*)state);
}
#undef IntegrateParticles
#undef SolveConstraints
#undef WriteOutputs
#pragma dont_inline reset
#pragma force_active reset
/* No-op hook: called from the global setup sequence (fn_80178DD4) among the
 * subsystem initialization routines, but its body is empty. */
extern "C" void fn_801C1B9C(void) {
}

/* No-op teardown hook: called by the global shutdown sequence (fn_801791A8)
 * among the subsystem shutdown routines, but its body is empty. */
extern "C" void fn_801C1BA0(void) {
}

extern "C" int fn_801C1BA4(int arg0, int arg1, int arg2) {
    /* Allocate a 0x70-byte object using the shared tag and initialize it with the given parameters. */
    int obj = fn_801284F8(0x70, &lbl_8055A950);
    if (obj != 0) {
        fn_801C109C(obj, arg0, arg1, arg2, 0);
    }
    return obj;
}

extern "C" int fn_801C109C(int, int, int, int);
extern "C" int fn_801C109C(int, int, int, int, int);
/* Allocates a 0x70-byte object from the "ppsys" heap and initializes it
 * using the four 32-bit values stored at offsets 0x10-0x1C of params. */
extern "C" int fn_801C1C1C(void *params) {
    int obj = fn_801284F8(0x70, &lbl_8055A950);
    if (obj != 0) {
        fn_801C109C(obj,
                    *(int *)((char *)params + 0x10),
                    *(int *)((char *)params + 0x14),
                    *(int *)((char *)params + 0x18),
                    *(int *)((char *)params + 0x1C));
    }
    return obj;
}

/* Destroys a J2DAnmTexPatternTIMGPointer object and frees its storage. */
extern "C" void fn_801C1C7C(int object) {
    if (object != 0) {
        __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv(object, 0);
        fn_80128668(object);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_801C1CBC(void *arg0, int arg1, void *arg2, int arg3, void *arg4, int arg5, void *arg6) {
    register float zero = 0.0f;
    register int one = 1;
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
        for (; count != 0; count--) {
#pragma unroll 2
            for (int pairIter = 0; pairIter < 2; pairIter++) {
                float (*p)[3];
                index = *(int *)(base + 0x14);
                index++;
                *(int *)(base + 0x14) = index;
                p = (float (*)[3])*(char **)(base + 0x24);
                p[index - 1][0] = x = *(float *)(src + 0);
                p[index - 1][1] = y = *(float *)(src + 4);
                p[index - 1][2] = z = *(float *)(src + 8);
                p = (float (*)[3])*(char **)(base + 0x28);
                p[index - 1][0] = x;
                p[index - 1][1] = y;
                p[index - 1][2] = z;
                p = (float (*)[3])*(char **)(base + 0x2C);
                p[index - 1][0] = zero;
                p[index - 1][1] = zero;
                p[index - 1][2] = zero;
                (*(float **)(base + 0x30))[index - 1] = *(float *)(src + 0x10);
                (*(float **)(base + 0x34))[index - 1] = *(float *)(src + 0xC);
                (*(int **)(base + 0x38))[index - 1] = one;
                src += 0x14;
            }
        }
        int odd = arg1 & 1;
        if (odd != 0) {
            do {
                float (*p)[3];
                index = *(int *)(base + 0x14);
                index++;
                *(int *)(base + 0x14) = index;
                p = (float (*)[3])*(char **)(base + 0x24);
                p[index - 1][0] = x = *(float *)(src + 0);
                p[index - 1][1] = y = *(float *)(src + 4);
                p[index - 1][2] = z = *(float *)(src + 8);
                p = (float (*)[3])*(char **)(base + 0x28);
                p[index - 1][0] = x;
                p[index - 1][1] = y;
                p[index - 1][2] = z;
                p = (float (*)[3])*(char **)(base + 0x2C);
                p[index - 1][0] = zero;
                p[index - 1][1] = zero;
                p[index - 1][2] = zero;
                (*(float **)(base + 0x30))[index - 1] = *(float *)(src + 0x10);
                (*(float **)(base + 0x34))[index - 1] = *(float *)(src + 0xC);
                (*(int **)(base + 0x38))[index - 1] = one;
                odd--;
            } while (odd != 0);
        }
    }
    {
        char *p = (char *)arg4;
        int i;
        float bound = -0.001f;
        for (i = 0; i < arg3; i++) {
            float factor;
            float v;
            char *q;
            int idx, first, second;
            factor = *(float *)(p + 0xC);
            if ((float)__fabs(factor) <= lbl_80558DC4[0])
                factor = 1.0f;
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
            char *object = *(char **)(rec + 8);
            int index;
            char *q;
            float dx, dy, dz, x, y, z;
            if (object != 0) {
                float *mat = (float *)*(int *)(rec + 4);
                index = *(int *)(base + 0x1C);
                q = *(char **)(base + 0x4C) + index * 0x18;
                dx = *(float *)object - mat[9];
                dy = *((float *)object + 1) - mat[10];
                dz = *((float *)object + 2) - mat[11];
                x = dz * mat[6] + (dx * mat[0] + dy * mat[3]);
                y = dz * mat[7] + (dx * mat[1] + dy * mat[4]);
                z = dz * mat[8] + (dx * mat[2] + dy * mat[5]);
                *(int *)(base + 0x1C) = index + 1;
                *(unsigned char *)(q + 0x14) = 1;
                *(int *)q = first;
                *(float **)(q + 4) = mat;
                *(float *)(q + 8) = x;
                *(float *)(q + 0xC) = y;
                *(float *)(q + 0x10) = z;
            } else {
                float *mat = (float *)*(int *)(rec + 4);
                char *points = *(char **)(base + 0x24) + first * 12;
                index = *(int *)(base + 0x1C);
                q = *(char **)(base + 0x4C) + index * 0x18;
                dx = *(float *)points - mat[9];
                dy = *((float *)points + 1) - mat[10];
                dz = *((float *)points + 2) - mat[11];
                x = dz * mat[6] + (dx * mat[0] + dy * mat[3]);
                y = dz * mat[7] + (dx * mat[1] + dy * mat[4]);
                z = dz * mat[8] + (dx * mat[2] + dy * mat[5]);
                *(int *)(base + 0x1C) = index + 1;
                *(unsigned char *)(q + 0x14) = 1;
                *(int *)q = first;
                *(float **)(q + 4) = mat;
                *(float *)(q + 8) = x;
                *(float *)(q + 0xC) = y;
                *(float *)(q + 0x10) = z;
            }
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
    #pragma scheduling invalid_target
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
    zero = 0.0f;
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
        char *qbase = *(char **)(a + 0x48);
        p = *(char **)(b + 4) + k * 0x10;
        index = *(int *)(a + 0x18);
        e = *(float *)(p + 12); d = *(float *)(p + 8);
        second = *(int *)(p + 4); first = *(int *)p;
        *(int *)(a + 0x18) = index + 1;
        *(int *)(qbase + index * 0x14) = first;
        *(int *)(qbase + index * 0x14 + 4) = second;
        base = *(float **)(a + 0x24);
        x = PSQUATMultiply((float *)((char *)base + first*12), (float *)((char *)base + second*12), (void *)first);
        y = (float)__fabs(e);
        *(float *)(qbase + index * 0x14 + 8) = d + x;
        *(float *)(qbase + index * 0x14 + 0x10) = y;
        *(unsigned char *)(qbase + index * 0x14 + 0xc) = e < bound;
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
        char *p2 = *(char **)(b + 0xc) + i * 0x1c;
        char *qbase = *(char **)(a + 0x50);
        index = *(int *)(a + 0x20);
        d = *(float *)(p2 + 8); second = *(int *)(p2 + 4); first = *(int *)p2;
        *(int *)(a + 0x20) = index + 1;
        *(int *)(qbase + index * 0x1c) = first;
        *(int *)(qbase + index * 0x1c + 4) = second;
        *(float *)(qbase + index * 0x1c + 8) = d;
        *(float *)(qbase + index * 0x1c + 12) = *(float *)(p2 + 0xc);
        *(float *)(qbase + index * 0x1c + 16) = *(float *)(p2 + 0x10);
        *(float *)(qbase + index * 0x1c + 20) = *(float *)(p2 + 0x14);
        *(float **)(qbase + index * 0x1c + 24) = m;
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
#pragma opt_common_subs off
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
        char *dst = dstBase + offset;
        char *src = srcBase + offset;
        float sourceOutX = *(float *)(srcBase + offset);
        *(float *)(dstBase + offset) = sourceOutX + xs;
        offset += 0xC;
        *(float *)(dst + 4) = *(float *)(src + 4) + cross[1] * scale;
        *(float *)(dst + 8) = *(float *)(src + 8) + cross[2] * scale;
    }
check:
    if (index < *(int *)(base + 0x14))
        goto loop;
}
#pragma scheduling on
extern "C" void fn_801C2694(void *arg0, float *arg1, int *arg2, float *arg3, float *arg4, float *arg5) {
    float v0 = arg5[0], v1 = arg5[1], v2 = arg5[2];
    float scaled[3];
    float b2 = arg4[2];
    float b1 = arg4[1];
    float b0 = arg4[0];
    float a2 = arg3[2];
    float a1 = arg3[1];
    float a0 = arg3[0];
    int i = 0;
    float *p;
    int off = 0;
    int i2;
    int off2;

    scaled[0] = 0.0110053914f * v0;
    scaled[1] = 0.0110053914f * v1;
    scaled[2] = 0.0110053914f * v2;
    *(float *)((char *)arg0 + 0x58) = a0;
    *(float *)((char *)arg0 + 0x5C) = a1;
    *(float *)((char *)arg0 + 0x60) = a2;
    *(float *)((char *)arg0 + 0x64) = b0;
    *(float *)((char *)arg0 + 0x68) = b1;
    *(float *)((char *)arg0 + 0x6C) = b2;
    goto check1;
loop1:
    p = (float *)(*(char **)((char *)arg0 + 0x2C) + off);
    ++i;
    p[0] += scaled[0];
    off += 0xC;
    p[1] += scaled[1];
    p[2] += scaled[2];
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
#pragma scheduling invalid_target
    float f5 = arg3[0] * lbl_80562930;
    float f0 = arg3[2] * lbl_80562930;
    float f4 = arg3[1] * lbl_80562930;
    float a0 = arg1[0];
    float a1 = arg1[1];
    float a2 = arg1[2];
    float b0 = arg2[0];
    float b1 = arg2[1];
    float b2 = arg2[2];
    int i = 0;
    float *p;
    int off = 0;
    *(float *)((char *)arg0 + 0x58) = a0;
    *(float *)((char *)arg0 + 0x5C) = a1;
    *(float *)((char *)arg0 + 0x60) = a2;
    *(float *)((char *)arg0 + 0x64) = b0;
    *(float *)((char *)arg0 + 0x68) = b1;
    *(float *)((char *)arg0 + 0x6C) = b2;
    goto check;
loop:
    p = (float *)(*(char **)((char *)arg0 + 0x2C) + off);
    ++i;
    p[0] += f5;
    off += 0xC;
    p[1] += f4;
    p[2] += f0;
check:
    if (i < *(int *)((char *)arg0 + 0x14))
        goto loop;
    fn_801C1B60((int)arg0);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801C28A8(void *obj, int mtx, float *pos, void *mat, int arg4, int first, int count, int draw, int out) {
    float v5C[3], v50[3], v44[3], v38[3], v2C[3], v20[3], v14[3], v8[3];
    int limit, idx, off, i;
    float f31, f30, f29, f28, f27, f26, f25, f24, f23, f22;

    limit = count;
    if (count < 0)
        limit = *(int *)((char *)obj + 0x14);
    GXInitLightAttnA_80144B44(v8, lbl_80562904, lbl_80562904, lbl_80562904);
    GXInitLightAttnA_80144B44(v14, lbl_80562904, lbl_80562904, lbl_80562904);
    f30 = lbl_80562904;
    off = first * 0xC;
    f31 = lbl_80562934;
    f26 = f30;
    f25 = lbl_80562938;
    f27 = f30;
    f28 = f30;
    f29 = lbl_80562940;
    idx = first * 4;
    i = first;
    for (; i < limit; idx += 4, off += 0xC, i++) {
        if (*(int *)(*(int *)((char *)obj + 0x38) + idx) == 0)
            continue;
        {
            float f3 = *(float *)(*(int *)((char *)obj + 0x30) + idx);
            float x, y, z;
            x = pos[0] + f3;
            y = pos[1] + f3;
            z = pos[2] + f3;
            f22 = f31 + x;
            f23 = f31 + y;
            f24 = f31 + z;
            fn_80144D64((int *)v20, (int *)(*(int *)((char *)obj + 0x24) + off));
            fn_8001BA68(v2C);
            fn_80144CD0(v2C, v20, mtx);
            fn_8001BA68(v38);
            fn_8001BA68(v44);
            fn_80144D64((int *)v50, (int *)mat);
            fn_801C2B9C(v44, (float *)(*(int *)((char *)obj + 0x28) + off), v50, lbl_80562900);
            fn_80144CD0(v38, v44, mtx);
            if (!(fn_8017F70C(v2C[0]) < f22))
                continue;
            if (!(fn_8017F70C(v2C[1]) < f23))
                continue;
            if (!(fn_8017F70C(v2C[2]) < f24))
                continue;
            if (fn_8017F70C(v38[0]) > f25 + f22) {
                if (v2C[0] >= f26) {
                    f22 = f22;
                } else {
                    f22 = -f22;
                }
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
            fn_801BFD34((int *)(*(int *)((char *)obj + 0x24) + off), v2C, mtx);
            fn_8001BA68(v5C);
            fn_801C0E60(v5C, v20, (int *)(*(int *)((char *)obj + 0x24) + off));
            f24 = fn_801429D0(fn_801C0E44(v5C), lbl_8056293C);
            fn_801C2B9C(v14, v14, v5C, f29 * *(float *)(*(int *)((char *)obj + 0x34) + idx));
            fn_801C2B9C(v8, v8, (float *)(*(int *)((char *)obj + 0x24) + off), f24);
            f30 += f24;
        }
    }
    if (draw != 0)
        fn_801C0124(draw, v8, lbl_8056290C / fn_801429D0(f30, lbl_80562944));
    if (out != 0)
        fn_80144DAC((void *)out, v14);
}
#pragma pop
/* Computes out = base + delta * scale component-wise for a 3D vector (Vec3 scale-and-add). */
void fn_801C2B9C(float * __restrict out, float * __restrict base, float * __restrict delta, float scale) {
    float x = base[0] + delta[0] * scale;
    float y = base[1] + delta[1] * scale;
    float z = base[2] + delta[2] * scale;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

/* Extract three 32-bit fields from obj: the element count at +0x14, the data-list pointer at +0x24 and an extra value at +0x28. */
extern "C" void fn_801C2BDC(void *obj, unsigned int *outCount, unsigned int *outList, unsigned int *outExtra) {
    *outCount = *(unsigned int *)((unsigned char *)obj + 0x14);
    *outList = *(unsigned int *)((unsigned char *)obj + 0x24);
    *outExtra = *(unsigned int *)((unsigned char *)obj + 0x28);
}

extern "C" int lbl_8055E7C8;
extern "C" float lbl_80562948;
extern "C" void fn_801E41D8(float *, float *, int, float);
struct Vec3f { float x, y, z; };
static inline void Mtx43MultVec(const float *m, const Vec3f *src, Vec3f *dst) {
    if (dst == src) {
        float p0 = m[3] * src->y;
        float p1 = m[4] * src->y;
        float p2 = m[0] * src->x;
        float p3 = m[1] * src->x;
        float p4 = m[2] * src->x;
        float p5 = m[5] * src->y;
        float p6 = m[6] * src->z;
        float p7 = m[7] * src->z;
        float p8 = m[8] * src->z;
        float x = p6 + (p2 + p0);
        float y = p7 + (p3 + p1);
        float z = p8 + (p4 + p5);
        dst->x = x;
        dst->y = y;
        dst->z = z;
    } else {
        float p0 = m[3] * src->y;
        float p1 = m[4] * src->y;
        float p2 = m[0] * src->x;
        float p3 = m[1] * src->x;
        float p4 = m[2] * src->x;
        float p5 = m[5] * src->y;
        float p6 = m[6] * src->z;
        float p7 = m[7] * src->z;
        float p8 = m[8] * src->z;
        float x = p6 + (p2 + p0);
        float y = p7 + (p3 + p1);
        float z = p8 + (p4 + p5);
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
    unsigned int color;
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
