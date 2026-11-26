extern const float lbl_80561CA0, lbl_80561CA4, lbl_80561CA8;
typedef struct { char pad[0xec]; signed char flag; } FlagStruct_8A654;
extern void fn_8017D160(void *, unsigned char *, unsigned char *, int *, int *, float);
extern float lbl_80561F54, lbl_80561F58, lbl_80561F5C, lbl_80561F60;
extern float lbl_80561F64, lbl_80561F68, lbl_80561F6C;
extern float lbl_80561D28, lbl_80561D34;
extern float lbl_80561E60, lbl_80561EE4;
extern const float lbl_80561CB0, lbl_80561CB4, lbl_80561CB8, lbl_80561CBC;
static inline void MultVecSR_inl(const float *m, const float *src, float *dst) {
    float x, y, z;
    if (src == dst) {
        x = src[0] * m[0] + src[1] * m[3] + src[2] * m[6];
        y = src[0] * m[1] + src[1] * m[4] + src[2] * m[7];
        z = src[0] * m[2] + src[1] * m[5] + src[2] * m[8];
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = src[0] * m[0] + src[1] * m[3] + src[2] * m[6];
        dst[1] = src[0] * m[1] + src[1] * m[4] + src[2] * m[7];
        dst[2] = src[0] * m[2] + src[1] * m[5] + src[2] * m[8];
    }
}
typedef struct V3 { float x, y, z; } V3;
typedef struct W3 { int a, b, c; } W3;
typedef struct M9 { V3 r[3]; } M9;
static inline void MultVecT_inl(const float *m, const float *src, float *dst) {
    float x, y, z;
    if (dst == src) {
        x = src[2] * m[2] + (src[0] * m[0] + src[1] * m[1]);
        y = src[2] * m[5] + (src[0] * m[3] + src[1] * m[4]);
        z = src[2] * m[8] + (src[0] * m[6] + src[1] * m[7]);
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = src[1] * m[1] + src[0] * m[0] + src[2] * m[2];
        dst[1] = src[1] * m[4] + src[0] * m[3] + src[2] * m[5];
        dst[2] = src[1] * m[7] + src[0] * m[6] + src[2] * m[8];
    }
}
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_801BEB30();
// split_file divides it into the game's real files (file_status shows its range).
extern signed char lbl_8055E4F8;
extern unsigned char lbl_8055A3B5;
extern int lbl_8055A3A4, lbl_8055A3A8, lbl_8055E4F0;
extern float lbl_8055E4D8, lbl_8055E4E8;
extern float lbl_80561CAC, lbl_80561CD0, lbl_80561CD4, lbl_80561CD8, lbl_80561CDC;
extern float lbl_80561CE0, lbl_80561CE4, lbl_80561CE8, lbl_80561CEC, lbl_80561CF0;
extern float lbl_80561CF4, lbl_80561CF8, lbl_80561CFC, lbl_80561D00, lbl_80561D04;
extern float lbl_80561D08, lbl_80561D0C, lbl_80561D10, lbl_80561D14, lbl_80561D18;
extern float lbl_80561D1C, lbl_80561D20, lbl_80561D24, lbl_80561D28, lbl_80561D2C;
extern float lbl_80561D30, lbl_80561D34;
extern float lbl_8055E460, lbl_80561CCC, lbl_80561D9C, lbl_80561EF8;
extern int lbl_8055E3C4;
extern unsigned char lbl_8055E4F5;
extern double fn_8002F234(float);
extern void fn_8018DA5C(void *, void *);
extern void fn_8018A9F0(void *, void *);
extern char lbl_803322B0[];
extern float lbl_80561CD4, lbl_80561CE0, lbl_80561CE4, lbl_80561CE8;
extern float lbl_80561CEC, lbl_80561CF0, lbl_80561CF4, lbl_80561CF8, lbl_80561CFC;
extern float lbl_80561D04, lbl_80561D08, lbl_80561D0C, lbl_80561D10, lbl_80561D14;
extern float lbl_80561D18, lbl_80561D1C, lbl_80561D20, lbl_80561D24, lbl_80561D28;
extern float lbl_80561D2C, lbl_80561D30;
extern int *fn_801E1F44(void);
extern int fn_80019BA8(void);
extern void fn_802049DC(int, int, float, float, float);
extern int fn_8020503C(void *);
extern char lbl_80434990[];
extern float lbl_80561CDC;
extern float lbl_80561DE0;
extern float lbl_80561F28;
__declspec(section ".data") extern float lbl_80558DC4;
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_8017D2C8();
extern float lbl_8055E3C8;
extern float lbl_80561D2C;
extern int fn_801C1BA4(int, int);
extern int fn_801C1C1C();
extern void *fn_801D2008(void *);
extern int fn_801C1C7C(int);
extern void fn_801D21B4();
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_801BD694(int, signed char);
extern void fn_801AFC28(void);
extern void fn_80181AFC(void);
extern void fn_8018C50C(void);
extern void fn_80204A1C(void *, void *);
extern unsigned char lbl_8055A3B6;
extern int lbl_8055E4D0;
extern int lbl_8055E4D4;
extern unsigned char lbl_8055E4F4;
extern unsigned char lbl_8055E4F6;
extern float lbl_80561CD8;
extern float lbl_80561D34;
extern char lbl_80332478[];
extern int lbl_8055A3AC;
extern int fn_801B2F2C(int);
extern float lbl_8055E4E0;
extern void fn_80279B28(int, void *);
extern void fn_8018F2C0(void *, void *);
extern int fn_8018AF04(void *);
extern void fn_8017A57C(void *);
extern void fn_8017B2D0(void *, float, float, float, float);
extern void fn_801BDA74(int, void *, float);
extern void fn_801D11D8();
extern void fn_801D1540();
extern void fn_802E30C8(const char *, ...);
extern int lbl_8055E908, lbl_8055E918;
extern float lbl_80561CD0, lbl_80561D54, lbl_80561D58;
extern char lbl_803325E8[];

void fn_8018C510(void);
void __AXDSPInitCallback_801AFC38(void);
void fn_801BD790(void);
extern float lbl_80434930[];
extern float lbl_80434908[];
extern float lbl_80434950[];
extern float lbl_804348E8[];
extern unsigned char lbl_8055E4F4;
extern const float lbl_80561CC4;
extern const float lbl_80561CC8;
extern void fn_8018185C(void *, const float *);
extern void fn_8017B6A8(void *);
extern void fn_8018A750(void *, int);
extern void fn_801B30C0(int, int, int);
extern void fn_801BE400(int, float *, float);
extern void fn_801D1810(int, int);
extern void fn_801E9DD0(void *, float, float);
extern void fn_8026A394(void *, int, int);
extern void fn_8018A8A8();
extern double fn_8002EFB4(float, double); /* fmod: frame-time phase wrapped by a wave period */
extern double lbl_80561F20, lbl_80561F30, lbl_80561F40; /* wave periods 1.575, 1.515, 1.535 */
extern float lbl_80561F38, lbl_80561F3C, lbl_80561F48, lbl_80561F4C, lbl_80561F50; /* wave scales/centres (z,y,x) and position scale -227.25 */
typedef struct Mtx3x4Words { int value[12]; } Mtx3x4Words;
typedef struct PhysParamB {
    int w0, w1, w2, w3, w4, w5, w6, w7;
    int w8, w9, w10, w11, w12, w13, w14, w15;
    short unk40;
    short unk42;
    int unk44, unk48, unk4C;
} PhysParamB;
typedef struct PhysParamA {
    int unk00;
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7;
    unsigned char b8, b9, b10, b11, b12, b13, b14, b15;
    unsigned char b16, b17, b18, b19, b20, b21, b22, b23;
    unsigned char b24, b25, b26, b27, b28, b29, b30, b31;
    unsigned char b32, b33, b34, b35, b36, b37, b38, b39;
    unsigned char b40, b41, b42, b43, b44, b45, b46, b47;
    unsigned char b48, b49, b50, b51, b52, b53, b54, b55;
    unsigned char b56, b57, b58, b59, b60, b61, b62, b63;
    unsigned char n0, n1, n2, n3, n4, n5, n6, n7;
    unsigned char n8, n9, n10, n11, n12, n13, n14, n15;
    unsigned char n16, n17, n18, n19, n20, n21, n22, n23;
    unsigned char n24, n25, n26, n27, n28, n29, n30, n31;
    int unk64, unk68, unk6C;
    unsigned char unk70;
    int unk74;
} PhysParamA;
typedef struct PhysRecord {
    unsigned char pad[0x18];
    float value;
    unsigned char pad2[8];
} PhysRecord;
typedef struct {
    unsigned char b[0x90];
} PhysBlob;
typedef struct {
    PhysRecord rec[4];
} PhysRecBlock;
typedef struct PhysStateScalars {
    float m0, m1, m2, m3, m4, m5, m6, m7;
    float m8, m9, m10, m11, m12, m13, m14, m15;
    float m16, m17, m18, m19, m20, m21, m22, m23;
    float m24, m25, m26, m27, m28, m29, m30, m31;
    PhysRecord rec[4];
    float g0, g1, g2, g3, g4, g5, g6;
    int t0, t1, t2;
} PhysStateScalars;
typedef struct PhysState {
    float m[32];
    PhysRecord rec[4];
    float g[7];
    int tail[3];
} PhysState;
#pragma cplusplus on
struct BA54Obj {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void *method6(float, float);
};
/* Collision shape group built by fn_80182DF4 (vtable lbl_803339B8, tag 'GRUP'). */
struct CollisionGroupObj {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void method14(int);
    virtual void method15(int);
};
struct BA54CallObj {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void *method4(float, float);
};
#pragma cplusplus reset
#pragma scheduling invalid_target
void fn_8018185C(void *arg0, const float *arg1)
{
  float *out = (float *) arg0;
  register float slope1;
  float x;
  float y;
  float delta;
  float denom;
  float first;
  float second;
  float x2;
  float y2;
  float t;
  x = arg1[1];
  out[7] = x;
  out[10] = arg1[3];
  out[6] = 1.35152f * arg1[5];
  x = (x > 1e-05f) ? (x) : (1e-05f);
  y = (5252.0f * arg1[0]) / x;
  out[9] = 0.0f;
  first = 1.35152f * arg1[2];
  y = 1.35152f * y;
  delta = out[7] - arg1[3];
  denom = delta * delta;
  denom = (denom > 1e-05f) ? (denom) : (1e-05f);
  slope1 = (y - first) / denom;
  out[8] = y / 8000.0f;
  out[0] = slope1;
  out[1] = out[6] + (((-2.0f) * slope1) * arg1[3]);
  out[2] = first + (slope1 * (arg1[3] * arg1[3]));
  x2 = arg1[4] - ((0, out[10]));
  y2 = x2 * x2;
  second = 1.35152f * (0.3f * arg1[2]);
  t = 1.35152f * arg1[2];
  y2 = (y2 > 0.0001f) ? (y2) : (0.0001f);
  second = (second - t) / y2;
  out[3] = second;
  out[5] = t + (second * (out[10] * out[10]));
  out[4] = out[6] + (((-2.0f) * second) * out[10]);
}
#pragma scheduling on

void fn_801819A0(void *dst, float * __restrict arg1, void *arg2, float scale, float farg1, float farg2) {
    float b, a, d, c;
    float values[6];
    a = arg1[0x54 / 4];
    b = arg1[0x50 / 4];
    c = arg1[0x5C / 4];
    d = arg1[0x58 / 4];
    values[4] = arg1[0x68 / 4];
    values[5] = arg1[0x60 / 4];
    values[0] = (a * scale) / lbl_80561CC4;
    values[2] = (b * scale) / lbl_80561CC8;
    values[1] = c * farg2;
    values[3] = d * farg1;
    fn_8018185C(dst, values);
}
float fn_80181A14(void *truck) {
#define dirtyParams lbl_80434930
#define normalParams lbl_80434908
    /* Scale the object's value at +0x2d8 by a tuning factor picked from the dirty or normal parameter table, based on the dirty flag at +0x259d. */
    float factor;
    if (*((unsigned char *)truck + 0x259d) != 0) factor = dirtyParams[6];
    else factor = normalParams[6];
    return *((float *)((unsigned char *)truck + 0x2d8)) * factor;
#undef normalParams
#undef dirtyParams
}

float fn_80181A48(void *arg0) {
    volatile float *p = lbl_804348E8;
    float f;
    if (*((unsigned char *)arg0 + 0x259D)) {
        p += 18;
    } else if (lbl_8055E4F4) {
        p += 26;
    } else {
        p += 8;
    }
    f = p[7];
    return *((float *)((unsigned char *)arg0 + 0x2D0)) + f;
}
/* Return a truck tuning value from the alternate parameter table when the LFO mode flag is set, otherwise from the normal table. */
float fn_80181A94(void) {
#define alternateParams lbl_80434950
#define normalParams    lbl_80434908
    if (lbl_8055E4F4) return alternateParams[14];
    return normalParams[2];
#undef normalParams
#undef alternateParams
}

/* Return a truck tuning value from the alternate parameter table when the LFO mode flag is set, otherwise from the normal table. */
float fn_80181AC0(void) {
#define alternateParams lbl_80434950
#define normalParams    lbl_80434908
    if (lbl_8055E4F4) return alternateParams[15];
    return normalParams[3];
#undef normalParams
#undef alternateParams
}

#pragma dont_inline fn_80181AEC
/* Return truck tuning parameter [3] from the shared "dirty"/interpolated
 * parameter table lbl_80434930; fn_8018A098 uses it as the base scale when
 * blending an object's value at +0x258C. */
float fn_80181AEC(void) { return lbl_80434930[3]; }

static inline void init_tuning_blocks_80181AFC(float *p, float *q, float *r) {
    p[0] = lbl_80561CD4;
    p[1] = lbl_80561CD8;
    p[2] = lbl_80561CDC;
    p[3] = lbl_80561CD0;
    p[6] = lbl_80561CD8;
    p[7] = lbl_80561CE0;
    p[8] = lbl_80561CE4;
    p[4] = lbl_80561CE8;
    p[5] = lbl_80561CE8;
    q[0] = lbl_80561CEC;
    q[1] = lbl_80561CD0;
    q[2] = lbl_80561CD8;
    q[3] = lbl_80561CD0;
    q[6] = lbl_80561CF0;
    q[7] = lbl_80561CE0;
    q[4] = lbl_80561CE8;
    r[0] = lbl_80561CF4;
    r[1] = lbl_80561CD8;
}

#pragma push
#pragma processor 750
#pragma opt_propagation off
void fn_80181AFC(void) {
register char *base = (char *)lbl_804348E8;
register char *names = lbl_803322B0;
char *temp_r31;
register float temp_f31;
float var_f1;
float var_f1_2;
float var_f1_3;
int temp_r3;
char *temp_r31_2;
char *temp_r3_2;

register int initialize = lbl_8055A3B5;
if (initialize != 0) {
init_tuning_blocks_80181AFC((float *)((char *)base + 0x20),
                            (float *)((char *)base + 0x48),
                            &lbl_8055E4E8);
}
fn_802049DC((int)(void *)(names), (int)(void *)(&lbl_8055E4F0), lbl_80561CAC, lbl_80561CF8, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0x18), (int)(void *)(&lbl_8055A3A4), lbl_80561D00, lbl_80561CD0, lbl_80561D00);
fn_802049DC((int)(void *)(names + 0x30), (int)(void *)(&lbl_8055A3A8), lbl_80561D00, lbl_80561CD0, lbl_80561D00);
temp_r3 = fn_80019BA8();
if (temp_r3 != 0) {
var_f1 = lbl_80561D04;
} else {
var_f1 = lbl_80561CD0;
}
temp_f31 = lbl_80561D08 * var_f1;
if ((int) lbl_8055A3B5 != 0) {
if (temp_r3 != 0) {
var_f1_2 = lbl_80561CF0;
} else {
var_f1_2 = lbl_80561CD0;
}
(*(float *)((char *)(base) + (0x68))) = (float) (lbl_80561D0C * var_f1_2);
if (temp_r3 != 0) {
var_f1_3 = lbl_80561CF0;
} else {
var_f1_3 = lbl_80561CD0;
}
temp_r3_2 = ((char *)base + 0x68);
(*(float *)((char *)(temp_r3_2) + (4))) = (float) (lbl_80561D00 * var_f1_3);
(*(float *)((char *)(temp_r3_2) + (8))) = (float) lbl_80561CD8;
(*(float *)((char *)(temp_r3_2) + (0xC))) = temp_f31;
(*(float *)((char *)(temp_r3_2) + (0x10))) = (float) lbl_80561CD0;
(*(float *)((char *)(temp_r3_2) + (0x14))) = (float) lbl_80561D10;
(*(float *)((char *)(temp_r3_2) + (0x18))) = (float) lbl_80561D04;
(*(float *)((char *)(temp_r3_2) + (0x1C))) = (float) lbl_80561CAC;
(*(float *)((char *)(temp_r3_2) + (0x20))) = (float) lbl_80561D14;
(*(float *)((char *)(temp_r3_2) + (0x28))) = (float) lbl_80561CDC;
(*(float *)((char *)(temp_r3_2) + (0x24))) = (float) lbl_80561CD0;
(*(float *)((char *)(temp_r3_2) + (0x2C))) = (float) lbl_80561D18;
(*(float *)((char *)(temp_r3_2) + (0x30))) = (float) lbl_80561CD0;
(*(float *)((char *)(temp_r3_2) + (0x38))) = (float) lbl_80561CD0;
(*(float *)((char *)(temp_r3_2) + (0x3C))) = (float) lbl_80561CDC;
(*(float *)((char *)(temp_r3_2) + (0x34))) = (float) lbl_80561D1C;
lbl_8055E4D8 = lbl_80561D20;
}
if ((*(int *)((char *)(__AXFXGetLfoSinTable_801769CC()) + (4))) & 0x100000) {
temp_r31 = ((char *)base + 0x20);
fn_802049DC((int)(void *)(names + 0x44), (int)(void *)(temp_r31 + 4), lbl_80561CAC, lbl_80561CF0, lbl_80561D00);
fn_802049DC((int)(void *)(names + 0x68), (int)(void *)(temp_r31 + 0x1C), lbl_80561D24, lbl_80561D28, lbl_80561CF8);
fn_802049DC((int)(void *)(names + 0x80), (int)(void *)(temp_r31 + 0x18), lbl_80561CFC, lbl_80561CEC, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0xA0), (int)(void *)(temp_r31 + 0xC), lbl_80561CAC, lbl_80561D2C, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0xB8), (int)(void *)(temp_r31 + 8), lbl_80561CAC, lbl_80561D2C, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0xE0), (int)(void *)(temp_r31), lbl_80561CD0, lbl_80561D30, lbl_80561CD0);
}
if ((*(int *)((char *)(__AXFXGetLfoSinTable_801769CC()) + (4))) & 0x80000) {
fn_802049DC((int)(void *)(names + 0x100), (int)(void *)(((char *)base + 0x68)), lbl_80561CAC, lbl_80561CD8, lbl_80561D0C);
temp_r31_2 = ((char *)base + 0x68);
fn_802049DC((int)(void *)(names + 0x118), (int)(void *)(temp_r31_2 + 4), lbl_80561CAC, lbl_80561CD8, lbl_80561D0C);
fn_802049DC((int)(void *)(names + 0x130), (int)(void *)(temp_r31_2 + 0xC), lbl_80561CAC, lbl_80561CD8, lbl_80561D0C);
fn_802049DC((int)(void *)(names + 0x140), (int)(void *)(temp_r31_2 + 0x14), lbl_80561CFC, lbl_80561CEC, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0x150), (int)(void *)(temp_r31_2 + 0x20), lbl_80561CAC, lbl_80561D34, lbl_80561CFC);
fn_802049DC((int)(void *)(names + 0x160), (int)(void *)(temp_r31_2 + 0x28), lbl_80561CAC, lbl_80561CD0, lbl_80561D00);
fn_802049DC((int)(void *)(names + 0x174), (int)(void *)(temp_r31_2 + 0x24), lbl_80561CAC, lbl_80561CD0, lbl_80561D00);
fn_802049DC((int)(void *)(names + 0x188), (int)(void *)(temp_r31_2 + 0x2C), lbl_80561CAC, lbl_80561CE0, lbl_80561CF8);
fn_802049DC((int)(void *)(names + 0x1A0), (int)(void *)(temp_r31_2 + 0x30), lbl_80561CAC, lbl_80561D34, lbl_80561CFC);
}
if (fn_8020503C(names + 0x1B8) != 0) {
(*(float *)((char *)(((char *)base + 0x68)) + (0xC))) = (float) lbl_80561CAC;
} else {
(*(float *)((char *)(((char *)base + 0x68)) + (0xC))) = temp_f31;
}
lbl_8055A3B5 = 0;
}
#pragma opt_propagation reset
#pragma pop
extern float lbl_80561D38;
extern float lbl_80561D3C;
extern float lbl_80561D0C;
extern float lbl_80561CFC;
extern float fn_80129DC4(int, float, float);
extern float fn_802798E8(int);
extern void fn_802799EC(int, float);
#pragma push
#pragma processor 750
#pragma dont_inline on
/* Clamps an object's value to a random threshold when it exceeds two sampled bounds, reducing it by the second threshold. */
void fn_80181EAC(int object) {
    float lowerBound = 0.6f;
    float upperBound = 0.85f;
    float currentValue;
    float randomUpper;
    float randomLower;
    randomUpper = fn_80129DC4(4, lowerBound, upperBound);
    randomLower = fn_80129DC4(4, lbl_80561D0C, lbl_80561CFC);
    currentValue = fn_802798E8(object);
    if ((currentValue > randomUpper) && (currentValue > randomLower))
        fn_802799EC(object, currentValue - randomLower);
}
void fn_80181F30(void) {
    /* Reset vehicle/audio state, read AXFX LFO config mode, and initialize related subsystems. */
    unsigned int lfoConfig = *(unsigned int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4);
    unsigned int lfoMode = (lfoConfig >> 19) & 1;

    lbl_8055E4D0 = 0;
    lbl_8055E4F4 = (unsigned char)lfoMode;
    ((void (*)(int, unsigned int))fn_801BD694)(8, lfoMode);
    fn_801AFC28();
    lbl_8055E4D4 = 1;
    fn_80181AFC();

    if (lbl_8055A3B6 != 0) {
        *(float *)&lbl_8055E4E0 = lbl_80561D34;
        *((float *)&lbl_8055E4E0 + 1) = lbl_80561CD8;
    }

    lbl_8055A3B6 = 0;
    fn_80204A1C(&lbl_80332478, &lbl_8055A3AC);
    lbl_8055E4F6 = 0;
    fn_8018C50C();
}
#pragma pop
/* Global-teardown step: run the (currently empty) reset hook, clear the
 * DSP-init flag, and free the physics allocation pools. */
void fn_80181FC4(void) {
    fn_8018C510();
    __AXDSPInitCallback_801AFC38();
    fn_801BD790();
}

void fn_80181FEC(void* alarm) {
#define createCarelmgr fn_801D1184
#define createCarelmgr2 fn_801D14EC
    /* Alarm callback: allocate the two "carelmgr" objects and install their vtables. */
    createCarelmgr2(createCarelmgr(alarm));
#undef createCarelmgr2
#undef createCarelmgr
}

extern int fn_80128668(void);
extern void fn_8017A580(int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
extern void fn_801838C8(void *);
extern int fn_801769C4(void);
extern void fn_80181EAC(int);
extern void fn_8018F538();
extern void fn_80279B28(int, void *);
extern void fn_80279C00(int, void *);
extern void fn_8017B0B0(void);
extern void fn_801BD808(void *);
extern char lbl_803326F8[];
extern int lbl_8055E4D0;
/* Construct/init an object: initialize base state, install vtable, initialize per-instance data, and register it in the global instance list. */
void *fn_80182010(void *object) {
    unsigned char *objectBytes = (unsigned char *)object;
    fn_8017B0B0();
    *(int **)objectBytes = (int *)lbl_803326F8;
    *(short *)(objectBytes + 0x2B4) = -1;
    fn_801BD808(lbl_803326F8);
    ((void **)lbl_804348E8)[lbl_8055E4D0++] = object;
    return object;
}

extern int fn_802792E4(char *);
extern void *fn_80279874(int);
extern int fn_8027AA48(void);
extern void fn_801345D8(char *, long, char *, ...);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern void fn_80279F58(void *, void *);
extern void *fn_8027A798(void *);
extern void fn_8027A8B4(void *, void *);
extern void fn_8017B0F8(void *, void *, float, float);
extern void fn_801795D8(void *, int);
extern int fn_801B2EDC(int, void *);
extern void fn_801B86BC(int, void *);
extern void fn_80016A48(void *, int);
extern void *fn_80016544(int);
extern void fn_801D108C(int);
extern int fn_80209448(void *, int);
extern int SquealSound_create(void *);
extern int fn_8020DE74(void *);
extern void fn_8018C5A0(void *, void *);
extern void fn_8018A654(void *, void *);
extern void fn_801836DC(void);
extern void fn_80182DF4(void *);
extern float lbl_80561D40, lbl_80561D44, lbl_80561D48, lbl_80561D4C, lbl_80561D50;
extern float lbl_80561D5C, lbl_80561D60, lbl_80561D64;
extern char lbl_8055A3B8[], lbl_8055A3C0[], lbl_8055A3C8[];
extern char lbl_8055A3D0[], lbl_8055A3D8[], lbl_8055A3E0[];
extern unsigned char lbl_8055E4F7;
extern void *memcpy(void *, const void *, unsigned int);
void fn_80182074(void *arg0, void *arg1) {
    unsigned char *a = (unsigned char *)arg0;
    unsigned char *b = (unsigned char *)arg1;
    void *node;
    V3 in, out1, out2;
    char path[0x50];
    volatile PhysStateScalars state;
    void *cfg, *chassis, *obj;
    unsigned char c0, c1;
    int w0, w1, v, i, isPcar, flag;
#define BCPY(OFF) c1 = *(unsigned char *)(b + OFF); c0 = *(unsigned char *)(b + OFF + 1); \
    *(unsigned char *)(a + OFF + 0x88) = c1; *(unsigned char *)(a + OFF + 0x89) = c0;
    *(unsigned char *)(a + 0x2680) = 0;
    *(int *)(a + 0x59C) = *(int *)(b + 0xE4);
    *(int *)(a + 0x5A4) = *(int *)(b + 0xE8);
    v = *(int *)(b + 0xDC);
    *(int *)(a + 0x5A0) = v;
    if (v == 0) *(int *)(a + 0x5A0) = 0x0FF807FF;
    if (*(int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x400)
        *(int *)(a + 0x5A0) |= 0x80000000;
    *(int *)(a + 0x1EC) = *(int *)(b + 0xE0);
    *(int *)(a + 0x1F0) = *(int *)(b + 0x68);
    BCPY(0x6C) BCPY(0x6E) BCPY(0x70) BCPY(0x72) BCPY(0x74) BCPY(0x76)
    BCPY(0x78) BCPY(0x7A) BCPY(0x7C) BCPY(0x7E) BCPY(0x80) BCPY(0x82)
    BCPY(0x84) BCPY(0x86) BCPY(0x88) BCPY(0x8A) BCPY(0x8C) BCPY(0x8E)
    BCPY(0x90) BCPY(0x92) BCPY(0x94) BCPY(0x96) BCPY(0x98) BCPY(0x9A)
    BCPY(0x9C) BCPY(0x9E) BCPY(0xA0) BCPY(0xA2) BCPY(0xA4) BCPY(0xA6)
    BCPY(0xA8) BCPY(0xAA)
    BCPY(0xAC) BCPY(0xAE) BCPY(0xB0) BCPY(0xB2) BCPY(0xB4) BCPY(0xB6)
    BCPY(0xB8) BCPY(0xBA) BCPY(0xBC) BCPY(0xBE) BCPY(0xC0) BCPY(0xC2)
    BCPY(0xC4) BCPY(0xC6) BCPY(0xC8) BCPY(0xCA)
#undef BCPY
    *(int *)(a + 0x254) = *(int *)(b + 0xCC);
    *(int *)(a + 0x258) = *(int *)(b + 0xD0);
    *(int *)(a + 0x25C) = *(int *)(b + 0xD4);
    *(unsigned char *)(a + 0x260) = *(unsigned char *)(b + 0xD8);
    *(int *)(a + 0x264) = *(int *)(b + 0xDC);
    *(int *)(a + 0x26C) = fn_802792E4((char *)(a + 0x234));
    w1 = *(int *)(b + 0x18); w0 = *(int *)(b + 0x1C);
    *(int *)(a + 0x274) = w1; *(int *)(a + 0x278) = w0;
    w1 = *(int *)(b + 0x20); w0 = *(int *)(b + 0x24);
    *(int *)(a + 0x27C) = w1; *(int *)(a + 0x280) = w0;
    w1 = *(int *)(b + 0x28); w0 = *(int *)(b + 0x2C);
    *(int *)(a + 0x284) = w1; *(int *)(a + 0x288) = w0;
    w1 = *(int *)(b + 0x30); w0 = *(int *)(b + 0x34);
    *(int *)(a + 0x28C) = w1; *(int *)(a + 0x290) = w0;
    w1 = *(int *)(b + 0x38); w0 = *(int *)(b + 0x3C);
    *(int *)(a + 0x294) = w1; *(int *)(a + 0x298) = w0;
    w1 = *(int *)(b + 0x40); w0 = *(int *)(b + 0x44);
    *(int *)(a + 0x29C) = w1; *(int *)(a + 0x2A0) = w0;
    w1 = *(int *)(b + 0x48); w0 = *(int *)(b + 0x4C);
    *(int *)(a + 0x2A4) = w1; *(int *)(a + 0x2A8) = w0;
    *(int *)(a + 0x2AC) = *(int *)(b + 0x50);
    *(int *)(a + 0x2B0) = *(int *)(b + 0x54);
    *(short *)(a + 0x2B4) = *(short *)(b + 0x58);
    *(int *)(a + 0x2B8) = *(int *)(b + 0x5C);
    *(int *)(a + 0x2BC) = *(int *)(b + 0x60);
    *(int *)(a + 0x2C0) = *(int *)(b + 0x64);
    *(int *)(a + 0x328) = (int)fn_80279874(*(int *)(a + 0x25C));
    if (fn_8027AA48() == 0) *(int *)(a + 0x328) = 0;
    fn_801345D8(path, 0x50, lbl_803322B0 + 0x1D8, (char *)(a + 0x234));
    cfg = fn_80131808(path);
    chassis = ((void *(*)(void *, char *))(*(void ***)cfg)[2])(cfg, lbl_8055A3B8);
    *(float *)(a + 0x5B4) = ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_803322B0 + 0x1EC, lbl_80561CAC);
    *(float *)(a + 0x5B8) = ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_803322B0 + 0x200, lbl_80561CAC);
    ((void (*)(V3 *, void *, char *))(*(void ***)chassis)[13])(&out2, chassis, lbl_803322B0 + 0x214);
    *(float *)(a + 0x5C4) = out2.x;
    *(float *)(a + 0x5C8) = out2.y;
    *(float *)(a + 0x5CC) = out2.z;
    *(float *)(a + 0x5D0) = out2.x * lbl_80561D40;
    *(float *)(a + 0x5D4) = out2.y + lbl_80561D44;
    *(float *)(a + 0x5D8) = out2.z;
    in.x = *(float *)(a + 0x5D0);
    in.y = *(float *)(a + 0x5D4);
    in.z = *(float *)(a + 0x5D8);
    ((void (*)(V3 *, void *, char *, V3 *))(*(void ***)chassis)[14])(&out1, chassis, lbl_803322B0 + 0x220, &in);
    *(float *)(a + 0x5D0) = out1.x;
    *(float *)(a + 0x5D4) = out1.y;
    *(float *)(a + 0x5C4) = *(float *)(a + 0x5C4) * lbl_80561D48;
    *(float *)(a + 0x5C8) = *(float *)(a + 0x5C8) * lbl_80561D48;
    *(float *)(a + 0x5CC) = *(float *)(a + 0x5CC) * lbl_80561D48;
    *(float *)(a + 0x5D0) = out1.x * lbl_80561D48;
    *(float *)(a + 0x5D4) = out1.y * lbl_80561D48;
    *(float *)(a + 0x5D8) = out1.z * lbl_80561D48;
    *(float *)(a + 0x5C0) = lbl_80561D4C * ((float (*)(void *, char *, float))(*(void ***)chassis)[9])(chassis, lbl_803322B0 + 0x234, out1.y * lbl_80561D48);
    if (((int (*)(void *, char *))(*(void ***)chassis)[3])(chassis, lbl_803322B0 + 0x258) != 0)
        flag = ((int (*)(void *, char *, char *))(*(void ***)chassis)[21])(chassis, lbl_803322B0 + 0x258, lbl_803322B0 + 0x240);
    else flag = 1;
    *(int *)(a + 0x5E8) = flag;
    fn_80016A48(a + 0x2C4, *(int *)(a + 0x25C));
    fn_801B86BC(*(int *)(b + 0xE0), a + 0x2C4);
    obj = fn_80016544(*(int *)(a + 0x25C));
    *(unsigned char *)(a + 0x25C0) = (*(unsigned int *)((unsigned char *)obj + 0xA0) >> 2) & 1;
    fn_80279F58((void *)&state, cfg);
    fn_8027A8B4((void *)&state, fn_8027A798(a + 0x234));
    state.m0 = state.m0 * *(float *)(a + 0x2EC);
    state.g0 = state.g0 * (lbl_80561CDC * (*(float *)(a + 0x2F4) + *(float *)(a + 0x2F8)));
    state.g1 = state.g1 * *(float *)(a + 0x2FC);
    for (i = 0; i < 4; i++) {
        obj = ((void *(*)(void *, char *))(*(void ***)cfg)[2])(cfg, (i == 0 || i == 1) ? lbl_8055A3C0 : lbl_8055A3C8);
        *(float *)(a + 0x23E8 + i * 0x74) = *(float *)(b + 0x10C + i * 4);
        *(float *)(a + 0x23EC + i * 0x74) = lbl_80561D48 * ((float (*)(void *, char *, float))(*(void ***)obj)[10])(obj, lbl_803322B0 + 0x268, lbl_80561D50) - *(float *)(a + 0x23E8 + i * 0x74);
        state.rec[i].value = *(float *)(a + 0x23E8 + i * 0x74);
    }
    *(float *)(b + 0x8) = state.m0 / lbl_80561D54;
    *(float *)(b + 0xC) = state.m1 / lbl_80561D58;
    *(float *)(b + 0x10) = state.m2 / lbl_80561D58;
    *(float *)(b + 0x14) = state.m3 / lbl_80561D58;
    fn_8017B0F8(a, b, lbl_80561D58, state.m0);
    *(int *)(a + 0x270) = fn_801B2EDC(*(int *)(a + 0x1EC), a);
    fn_801795D8(a, *(int *)(a + 0x1EC));
    *(float *)(a + 0x5AC) = -(lbl_80561D48 * ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_8055A3D0, lbl_80561CAC));
    *(float *)(a + 0x5B0) = state.g6;
    *(float *)(a + 0x5A8) = lbl_80561D5C;
    if ((unsigned int)(*(int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4) - 0x180000) != 0x201)
        *(float *)(a + 0x5A8) = lbl_80561D60 * (*(float *)(a + 0x2C8) + ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_803322B0 + 0x278, *(float *)(a + 0x5A8)));
    else if (lbl_8055E4F7 == 0) {
        lbl_8055E4F7 = 1;
        fn_802E30C8(lbl_8055A3D8, lbl_803322B0 + 0x288);
    }
    *(float *)(a + 0x5DC) = ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_803322B0 + 0x2B4, lbl_80561CAC);
    *(float *)(a + 0x5E0) = ((float (*)(void *, char *, float))(*(void ***)chassis)[10])(chassis, lbl_803322B0 + 0x2C4, *(float *)(a + 0x5DC));
    *(signed char *)(a + 0x26E0) = ((signed char (*)(void *, char *, int))(*(void ***)chassis)[12])(chassis, lbl_8055A3E0, 0);
    *(float *)(a + 0x30) = *(float *)&state.t0;
    *(float *)(a + 0x34) = *(float *)&state.t1;
    *(float *)(a + 0x38) = *(float *)&state.t2;
    fn_8017A57C(a);
    if (*(int *)(a + 0x10) == 0x41434152) state.m11 = lbl_80561D64;
    *(float *)(a + 0x32C) = state.m0; *(float *)(a + 0x330) = state.m1;
    *(float *)(a + 0x334) = state.m2; *(float *)(a + 0x338) = state.m3;
    *(float *)(a + 0x33C) = state.m4; *(float *)(a + 0x340) = state.m5;
    *(float *)(a + 0x344) = state.m6; *(float *)(a + 0x348) = state.m7;
    *(float *)(a + 0x34C) = state.m8; *(float *)(a + 0x350) = state.m9;
    *(float *)(a + 0x354) = state.m10; *(float *)(a + 0x358) = state.m11;
    *(float *)(a + 0x35C) = state.m12; *(float *)(a + 0x360) = state.m13;
    *(float *)(a + 0x364) = state.m14; *(float *)(a + 0x368) = state.m15;
    *(float *)(a + 0x36C) = state.m16; *(float *)(a + 0x370) = state.m17;
    *(float *)(a + 0x374) = state.m18; *(float *)(a + 0x378) = state.m19;
    *(float *)(a + 0x37C) = state.m20; *(float *)(a + 0x380) = state.m21;
    *(float *)(a + 0x384) = state.m22; *(float *)(a + 0x388) = state.m23;
    *(float *)(a + 0x38C) = state.m24; *(float *)(a + 0x390) = state.m25;
    *(float *)(a + 0x394) = state.m26; *(float *)(a + 0x398) = state.m27;
    *(float *)(a + 0x39C) = state.m28; *(float *)(a + 0x3A0) = state.m29;
    *(float *)(a + 0x3A4) = state.m30; *(float *)(a + 0x3A8) = state.m31;
    *(PhysRecBlock *)(a + 0x3AC) = *(PhysRecBlock *)state.rec;
    *(float *)(a + 0x43C) = state.g0; *(float *)(a + 0x440) = state.g1;
    *(float *)(a + 0x444) = state.g2; *(float *)(a + 0x448) = state.g3;
    *(float *)(a + 0x44C) = state.g4; *(float *)(a + 0x450) = state.g5;
    *(float *)(a + 0x454) = state.g6;
    *(int *)(a + 0x458) = state.t0; *(int *)(a + 0x45C) = state.t1; *(int *)(a + 0x460) = state.t2;
    for (i = 0; i < 0x20; i++) *(float *)(a + 0x464 + i * 4) = *(float *)(a + 0x32C + i * 4);
    *(PhysRecBlock *)(a + 0x4E4) = *(PhysRecBlock *)(a + 0x3AC);
    for (i = 0; i < 7; i++) *(float *)(a + 0x574 + i * 4) = *(float *)(a + 0x43C + i * 4);
    *(int *)(a + 0x590) = *(int *)(a + 0x458); *(int *)(a + 0x594) = *(int *)(a + 0x45C); *(int *)(a + 0x598) = *(int *)(a + 0x460);
    ((void (*)(int, void *, int, int, float, float, float, float, float, float))fn_801BDA74)(*(int *)(a + 0x1EC), a + 0x32C, *(int *)(a + 0x45C), *(int *)(a + 0x458), *(float *)(a + 0x450), *(float *)(a + 0x44C), *(float *)(a + 0x448), *(float *)(a + 0x444), *(float *)(a + 0x440), *(float *)(a + 0x43C));
    node = 0;
    fn_801BEB30(*(int *)(a + 0x1EC), &node);
    *(float *)(a + 0x23DC) = ((float *)node)[0]; *(float *)(a + 0x23E0) = ((float *)node)[1]; *(float *)(a + 0x23E4) = ((float *)node)[2];
    *(float *)(a + 0x2450) = ((float *)node)[4]; *(float *)(a + 0x2454) = ((float *)node)[5]; *(float *)(a + 0x2458) = ((float *)node)[6];
    *(float *)(a + 0x24C4) = ((float *)node)[8]; *(float *)(a + 0x24C8) = ((float *)node)[9]; *(float *)(a + 0x24CC) = ((float *)node)[10];
    *(float *)(a + 0x2538) = ((float *)node)[12]; *(float *)(a + 0x253C) = ((float *)node)[13]; *(float *)(a + 0x2540) = ((float *)node)[14];
    ((void (*)(void *, void *))fn_801836DC)(a, b);
    ((void (*)(void *, void *))fn_80182DF4)(a, b);
    fn_8018C5A0(a, b);
    fn_8018A654(a, b);
    isPcar = *(int *)(b) == 0x50434152;
    *(int *)(a + 0x257C) = fn_80209448(a, *(int *)(b));
    if (isPcar) *(int *)(a + 0x2580) = SquealSound_create(a); else *(int *)(a + 0x2580) = 0;
    *(int *)(a + 0x2584) = fn_8020DE74(a);
    fn_801D108C(*(int *)(a + 0x1EC));
    fn_80131818(cfg);
    flag = 0;
    if (isPcar && fn_8020503C(lbl_803322B0 + 0x2D8) != 0) flag = 1;
    *(signed char *)(a + 0x25C8) = flag;
    if ((unsigned int)(*(int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4) - 0x180000) == 0x304)
        *(signed char *)(a + 0x25C8) = 1;
    fn_801838C8(a);
}

extern void *fn_801284F8(int, const char *);
extern void fn_802C7760(void *, float *, float *, float *, float *, float *, float *);
extern void *fn_801E3004(void *, const char *, int);
extern float *fn_801E3630(void *);
extern void fn_801E323C(void *);
extern void *fn_801AE180(void);
extern void *fn_8019FFD8(void *, void *, void *);
extern void fn_801A0258(void *, V3 *, V3 *, float, float, float, float, float);
extern void *fn_801A2354(void *, void *, V3 *, void *, float, float, float, float, float);
extern void fn_801A0444(void *, void *);
extern void fn_80179F94(void *, void *);
extern char lbl_803325A0[], lbl_8055A3E8[], lbl_8055A3F0[];
extern float lbl_80561D40, lbl_80561D68, lbl_80561D6C, lbl_80561D70, lbl_80561D74, lbl_80561D78;
extern float lbl_80561D7C, lbl_80561D80, lbl_80561D84, lbl_80561D88, lbl_80561D8C;
extern char lbl_803325A0[], lbl_8055A3E8[8], lbl_8055A3F0[8];
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_80182DF4(void *arg0) {
    struct PushNode { void *next; float values[9]; };
    struct Truck {
        char pad0[0x10];
        unsigned int tag;
        char pad14[0x1C];
        V3 pos;
        char frame[0x94];
        void *pushNodes;
        char padD4[0x114];
        unsigned char unk1E8;
        char pad1E9[7];
        int unk1F0;
        char pad1F4[0x74];
        CollisionGroupObj *group;
        char pad26C[0x330];
        void *model;
        char pad5A0[0x1C];
        float rearZ;
    };
#define self ((Truck *)arg0)
    float minX = 0.0f, maxX = 0.0f, minY = 0.0f;
    float maxY = 0.0f, minZ = 0.0f, maxZ = 0.0f;
    V3 pos;
    V3 sizeB, sizeA, sizeC;
    V3 center;
    V3 nodeA, nodeB;
    V3 d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
    V3 q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11;
    float mass = lbl_80561D68;
    float f30 = lbl_80561CB8;
    float f29 = lbl_80561D6C;
    float f28 = 0.5f / f29;
    void *handle;
    float *v;
    PushNode *node;
    void *obj;
    void *obj2;
    float z27, y26, x25, x24, y23, hy, hz, z20, y19, x18, z17, y16, x15, z14;
    float x, y, z, m, half, zero, off;

    fn_802C7760(self->model, &minX, &maxX, &minY, &maxY, &minZ, &maxZ);
    handle = fn_801E3004(self->model, lbl_8055A3E8, -1);
    if (handle != 0) {
        v = fn_801E3630(handle);
        nodeA.z = v[2];
        nodeA.x = v[0];
        nodeA.y = lbl_80561D70 + (maxY + self->pos.y);
        node = (PushNode *)fn_801AE180();
        node->values[0] = nodeA.x;
        m = 2.0f * mass;
        node->values[1] = nodeA.y;
        half = 0.5f;
        node->values[2] = nodeA.z;
        zero = 0.0f;
        node->values[3] = m;
        off = lbl_80561D70;
        node->values[4] = half;
        node->values[6] = zero; node->values[7] = zero; node->values[8] = zero;
        node->values[5] = zero;
        node->next = self->pushNodes; self->pushNodes = node;
        nodeB.z = v[2];
        nodeB.y = off + (maxY + self->pos.y);
        nodeB.x = -v[0];
        node = (PushNode *)fn_801AE180();
        node->values[0] = nodeB.x;
        m = 2.0f * mass;
        node->values[1] = nodeB.y;
        half = 0.5f;
        node->values[2] = nodeB.z;
        zero = 0.0f;
        node->values[3] = m;
        node->values[4] = half;
        node->values[6] = zero; node->values[7] = zero; node->values[8] = zero;
        node->values[5] = zero;
        node->next = self->pushNodes; self->pushNodes = node;
        fn_801E323C(handle);
    }
    minY = minY > lbl_80561D40 ? minY : lbl_80561D40;
    pos = self->pos;
    minX += pos.x;
    maxX += pos.x;
    minY += pos.y;
    maxY += pos.y;
    minZ += pos.z;
    maxZ += pos.z;
    if (self->unk1F0 == 0x54 && !(*(int *)((char *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x1000)) {
        maxZ -= lbl_80561D74;
    }
    self->rearZ = maxZ;
    obj = fn_801284F8(0x184, lbl_803325A0);
    if (obj != 0) {
        obj = fn_8019FFD8(obj, self->frame, self);
    }
    self->group = (CollisionGroupObj *)obj;

    sizeB.x = 0.7f; sizeB.y = 0.1f; sizeB.z = 1.0f;
    sizeA.x = 0.7f; sizeA.y = 0.1f; sizeA.z = 1.0f;
    sizeC.x = 0.7f; sizeC.y = 0.1f; sizeC.z = 1.0f;

    x25 = maxX - 0.45f;
    y26 = 0.45f + minY;
    z27 = maxZ - 0.45f;
    x24 = 0.8f * x25;
    y23 = 0.36f + minY;
    hy = 0.5f * (maxY - minY);
    hz = 0.5f * (minZ + maxZ);
    x18 = maxX - hy;
    y19 = minY + hy;
    z20 = 0.5f * (z27 + hz);
    x15 = maxX - lbl_80561D88;
    y16 = lbl_80561D88 + minY;
    z17 = lbl_80561D88 + minZ;
    z14 = 0.5f * (z17 + hz);

    q0.x = -x24; q0.y = lbl_80561D8C + y23; q0.z = z27;
    d0.x = q0.x - self->pos.x; d0.y = q0.y - self->pos.y; d0.z = q0.z - self->pos.z;
    fn_801A0258(self->group, &d0, &sizeA, 0.36f, mass, f30, f29, f28);
    q1.x = 0.0f; q1.y = lbl_80561D8C + y23; q1.z = z27;
    d1.x = q1.x - self->pos.x; d1.y = q1.y - self->pos.y; d1.z = q1.z - self->pos.z;
    fn_801A0258(self->group, &d1, &sizeA, 0.36f, mass, f30, f29, f28);
    q2.x = x24; q2.y = lbl_80561D8C + y23; q2.z = z27;
    d2.x = q2.x - self->pos.x; d2.y = q2.y - self->pos.y; d2.z = q2.z - self->pos.z;
    fn_801A0258(self->group, &d2, &sizeA, 0.36f, mass, f30, f29, f28);
    q3.x = -x25; q3.y = lbl_80561D8C + y26; q3.z = z20;
    d3.x = q3.x - self->pos.x; d3.y = q3.y - self->pos.y; d3.z = q3.z - self->pos.z;
    fn_801A0258(self->group, &d3, &sizeA, 0.45f, mass, f30, f29, f28);
    q4.x = x25; q4.y = lbl_80561D8C + y26; q4.z = z20;
    d4.x = q4.x - self->pos.x; d4.y = q4.y - self->pos.y; d4.z = q4.z - self->pos.z;
    fn_801A0258(self->group, &d4, &sizeA, 0.45f, mass, f30, f29, f28);
    q5.x = 0.8f * -x18; q5.y = lbl_80561D8C + y19; q5.z = hz;
    d5.x = q5.x - self->pos.x; d5.y = q5.y - self->pos.y; d5.z = q5.z - self->pos.z;
    fn_801A0258(self->group, &d5, &sizeB, hy, mass, f30, f29, f28);
    q6.x = 0.8f * x18; q6.y = lbl_80561D8C + y19; q6.z = hz;
    d6.x = q6.x - self->pos.x; d6.y = q6.y - self->pos.y; d6.z = q6.z - self->pos.z;
    fn_801A0258(self->group, &d6, &sizeB, hy, mass, f30, f29, f28);
    q7.x = -x15; q7.y = lbl_80561D8C + y16; q7.z = z14;
    d7.x = q7.x - self->pos.x; d7.y = q7.y - self->pos.y; d7.z = q7.z - self->pos.z;
    fn_801A0258(self->group, &d7, &sizeC, lbl_80561D88, mass, f30, f29, f28);
    q8.x = x15; q8.y = lbl_80561D8C + y16; q8.z = z14;
    d8.x = q8.x - self->pos.x; d8.y = q8.y - self->pos.y; d8.z = q8.z - self->pos.z;
    fn_801A0258(self->group, &d8, &sizeC, lbl_80561D88, mass, f30, f29, f28);
    q9.x = -x15; q9.y = lbl_80561D8C + y16; q9.z = z17;
    d9.x = q9.x - self->pos.x; d9.y = q9.y - self->pos.y; d9.z = q9.z - self->pos.z;
    fn_801A0258(self->group, &d9, &sizeC, lbl_80561D88, mass, f30, f29, f28);
    q10.x = 0.0f; q10.y = lbl_80561D8C + y16; q10.z = z17;
    d10.x = q10.x - self->pos.x; d10.y = q10.y - self->pos.y; d10.z = q10.z - self->pos.z;
    fn_801A0258(self->group, &d10, &sizeC, lbl_80561D88, mass, f30, f29, f28);
    q11.x = x15; q11.y = lbl_80561D8C + y16; q11.z = z17;
    d11.x = q11.x - self->pos.x; d11.y = q11.y - self->pos.y; d11.z = q11.z - self->pos.z;
    fn_801A0258(self->group, &d11, &sizeC, lbl_80561D88, mass, f30, f29, f28);

    center.z = 0.5f * (maxZ + minZ);
    center.y = 0.5f * (maxY + minY);
    center.x = 0.5f * (maxX + minX);
    obj2 = fn_801284F8(0x74, lbl_8055A3F0);
    if (obj2 != 0) {
        obj2 = fn_801A2354(obj2, self->frame, &center, self, lbl_80561CF8 * mass, f30,
                           0.5f * (maxX - minX), 0.5f * (maxY - minY),
                           0.5f * (maxZ - minZ));
    }
    fn_801A0444(self->group, obj2);
    fn_80179F94(self, self->group);
    self->unk1E8 = 1;
    self->group->method14(0x6D);
    if (self->tag == 'PCAR') {
        self->group->method15(1);
    } else {
        self->group->method15(6);
    }
#undef self
}
#pragma cplusplus reset
#pragma pop
/* Empty stub (no operation). */
void fn_801836DC(void) {

}

extern void fn_801D1100(); /* tells every registered object that this one dies */
extern void fn_8018A6F4(void *);
extern void fn_80179EE8(void *, int);
extern void fn_802792EC(int);
#pragma push
#pragma cplusplus on
/* Destructor of the car/game object whose vtable is lbl_803326F8: the
   constructor fn_80182010 installs that vtable and files the instance in the
   lbl_804348E8[] list, of which lbl_8055E4D0 are alive.  Here the vtable goes
   back to this class, every registered listener is told the +0x1EC object is
   going away (fn_801D1100), the three sub-objects owned at +0x257C..+0x2584
   are deleted through their own virtual destructors, the sound/effect objects
   fn_8018A6F4 knows are released, the shared node at +0x26C loses one
   reference, the instance count drops, the base-class destructor fn_80179EE8
   runs and the memory itself is freed (fn_80128668, operator delete) when
   deleteFlag is positive. */
extern "C" void *fn_801836E0(void *object, int deleteFlag) {
    /* CodeWarrior keeps two destructor slots before the first declared virtual,
       so the one method below is fetched from vtable+8: the sub-object's
       deleting destructor, which the game always calls with the 1 flag. */
    class SubObject {
    public:
        virtual void deleteNow(int);
    };
    SubObject *child0;
    SubObject *child1;
    SubObject *child2;
    if (object != 0) {
        *(void **)object = (void *)lbl_803326F8;
        fn_801D1100(*(void **)((char *)object + 0x1EC));
        child0 = *(SubObject **)((char *)object + 0x257C);
        if (child0 != 0 && child0 != 0) {
            child0->deleteNow(1);
        }
        child1 = *(SubObject **)((char *)object + 0x2580);
        if (child1 != 0 && child1 != 0) {
            child1->deleteNow(1);
        }
        child2 = *(SubObject **)((char *)object + 0x2584);
        if (child2 != 0) {
            child2->deleteNow(1);
        }
        fn_8018A6F4(object);
        fn_802792EC(*(int *)((char *)object + 0x26C));
        lbl_8055E4D0--;
        if (object != 0) {
            fn_80179EE8(object, 0);
        }
        if (deleteFlag > 0) {
            ((void (*)(void *))fn_80128668)(object);
        }
    }
    return object;
}
#pragma cplusplus off
#pragma pop

int fn_801837DC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

/* Restore saved transform/state words from +0x274..+0x2A0 into +0x3C..+0x68, then refresh and reinitialize. */
void fn_8018381C(void *arg0) {
    int l, k, j, i, h, g, f, e, d, c, b, a;

    a = *(volatile int *)((char *)arg0 + 0x274);
    b = *(volatile int *)((char *)arg0 + 0x278);
    c = *(volatile int *)((char *)arg0 + 0x27C);
    d = *(volatile int *)((char *)arg0 + 0x280);
    e = *(volatile int *)((char *)arg0 + 0x284);
    f = *(volatile int *)((char *)arg0 + 0x288);
    g = *(volatile int *)((char *)arg0 + 0x28C);
    h = *(volatile int *)((char *)arg0 + 0x290);
    i = *(volatile int *)((char *)arg0 + 0x294);
    j = *(volatile int *)((char *)arg0 + 0x298);
    k = *(volatile int *)((char *)arg0 + 0x29C);
    l = *(volatile int *)((char *)arg0 + 0x2A0);
    *(int *)((char *)arg0 + 0x3C) = a;
    *(int *)((char *)arg0 + 0x40) = b;
    *(int *)((char *)arg0 + 0x44) = c;
    *(int *)((char *)arg0 + 0x48) = d;
    *(int *)((char *)arg0 + 0x4C) = e;
    *(int *)((char *)arg0 + 0x50) = f;
    *(int *)((char *)arg0 + 0x54) = g;
    *(int *)((char *)arg0 + 0x58) = h;
    *(int *)((char *)arg0 + 0x5C) = i;
    *(int *)((char *)arg0 + 0x60) = j;
    *(int *)((char *)arg0 + 0x64) = k;
    *(int *)((char *)arg0 + 0x68) = l;
    ((void (*)(void *))fn_8017A580)(arg0);
    fn_8017B164(arg0);
    fn_801838C8(arg0);
}

#pragma push
#pragma processor 750
extern float lbl_80561D90, lbl_80561D94, lbl_80561D98;
extern void fn_8018BE54(void *, float), fn_80189C64(void *), fn_8018B0D0(void *, int);
extern int fn_801BF1B8(int, int), fn_801CF064(void);
extern void resetSceneLights(void *), fn_801B8100(void *, int, int), fn_8013605C(void *);
extern void *fn_801B2ED0(int);
extern void *memset(void *, int, unsigned long);
void fn_801838C8(void *arg0)
{
  char *p = (char *) arg0;
  char *r;
  float one;
  float zero;
  int i;
  char *q;
  void *obj;
  void *v;
  void *path;
  *((float *) (p + 0x5e4)) = 0.0f;
  fn_8018BE54(p, 1.0f);
  one = 1.0;
  zero = 0.0f;
  *((float *) (p + 0x5ec)) = zero;
  *((float *) (p + 0x5f0)) = one;
  *((float *) (p + 0x26e4)) = zero;
  *((float *) (p + 0x26e8)) = zero;
  *((float *) (p + 0x26ec)) = zero;
  *((float *) (p + 0x26f0)) = zero;
  *((float *) (p + 0x26f4)) = zero;
  *((float *) (p + 0x26f8)) = zero;
  *((float *) (p + 0x26fc)) = zero;
  fn_80189C64(p);
  *((int *) (p + 0x24)) = *((int *) (p + 0x28));
  fn_8018B0D0(p, 0);
  zero = 0.0f;
  one = 1.0f;
  *((volatile float *) (p + 0x25e8)) = zero;
  *((float *) (p + 0x25d8)) = zero;
  *((float *) (p + 0x25d4)) = zero;
  *((float *) (p + 0x25d0)) = zero;
  *((float *) (p + 0x25cc)) = zero;
  *((float *) (p + 0x25ec)) = zero;
  *((float *) (p + 0x25e4)) = zero;
  *((float *) (p + 0x25e0)) = zero;
  *((float *) (p + 0x25dc)) = zero;
  *((float *) (p + 0x25e8)) = one;
  *((float *) (p + 0x25f8)) = zero;
  *((float *) (p + 0x25f4)) = zero;
  *((float *) (p + 0x25f0)) = zero;
  *((float *) (p + 0x25fc)) = zero;
  *((float *) (p + 0x2604)) = zero;
  *((float *) (p + 0x2600)) = zero;
  *((float *) (p + 0x2608)) = zero;
  *((char *) (p + 0x260c)) = 0;
  *((char *) (p + 0x260d)) = 0;
  *((char *) (p + 0x260e)) = 0;
  *((float *) (p + 0x2614)) = zero;
  *((float *) (p + 0x2618)) = zero;
  *((float *) (p + 0x2594)) = zero;
  *((float *) (p + 0x2598)) = zero;
  *((float *) (p + 0x261c)) = zero;
  *((float *) (p + 0x2588)) = zero;
  *((float *) (p + 0x2590)) = zero;
  *((float *) (p + 0x258c)) = -5.0f;
  *((char *) (p + 0x259c)) = 0;
  *((char *) (p + 0x259d)) = 0;
  *((float *) (p + 0x25bc)) = zero;
  *((float *) (p + 0x25c4)) = zero;
  *((float *) (p + 0x25a0)) = zero;
  *((float *) (p + 0x25a4)) = zero;
  *((float *) (p + 0x25a8)) = one;
  *((float *) (p + 0x25ac)) = zero;
  *((int *) (p + 0x2620)) = 0;
  *((float *) (p + 0x2654)) = zero;
  *((float *) (p + 0x2658)) = zero;
  *((float *) (p + 0x265c)) = zero;
  *((float *) (p + 0x2660)) = zero;
  *((float *) (p + 0x2664)) = zero;
  *((float *) (p + 0x2668)) = zero;
  *((float *) (p + 0x266c)) = zero;
  *((float *) (p + 0x2670)) = zero;
  *((float *) (p + 0x2674)) = zero;
  *((int *) (p + 0x2678)) = 0;
  *((int *) (p + 0x267c)) = 0;
  *((float *) (p + 0x2688)) = zero;
  *((int *) (p + 0x268c)) = 0;
  *((float *) (p + 0x2690)) = zero;
  *((float *) (p + 0x2694)) = zero;
  *((float *) (p + 0x2698)) = zero;
  *((float *) (p + 0x269c)) = zero;
  *((float *) (p + 0x26a8)) = zero;
  memset(p + 0x26a0, 0, 8);
  zero = 0.0f;
  *((int *) (p + 0x2648)) = 0;
  *((char *) (p + 0x2624)) = 0;
  *((char *) (p + 0x2625)) = 0;
  *((int *) (p + 0x263c)) = 0;
  *((int *) (p + 0x2638)) = 0;
  *((float *) (p + 0x2628)) = zero;
  *((float *) (p + 0x262c)) = zero;
  *((float *) (p + 0x2630)) = zero;
  *((float *) (p + 0x2634)) = zero;
  *((int *) (p + 0x2644)) = 0;
  *((char *) (p + 0x2640)) = 0;
  *((float *) (p + 0x264c)) = zero;
  *((float *) (p + 0x2650)) = zero;
  *((char *) (p + 0x26ac)) = 0;
  fn_801BF1B8(*((int *) (p + 0x1ec)), 0);
  zero = 0.0f;
  *((int *) (p + 0x26b0)) = -1;
  *((float *) (p + 0x26b4)) = zero;
  *((float *) (p + 0x26b8)) = zero;
  *((float *) (p + 0x26bc)) = zero;
  ((void (*)(int, void *)) fn_801BDA74)(*((int *) (p + 0x1ec)), p + 0x32c);
  zero = 0.0f;
  r = p + 0x5fc;
  q = p;
  for (i = 0; i < 0xa2; i++)
  {
    memset(r, 0, 12);
    *((float *) (q + 0x5fc)) = zero;
    *((float *) (q + 0x600)) = zero;
    *((float *) (q + 0x604)) = zero;
    *((float *) (q + 0xd94)) = zero;
    *((float *) (q + 0xd98)) = zero;
    *((float *) (q + 0xd9c)) = zero;
    r += 12;
    q += 12;
  }

  zero = 0.0f;
  one = 1.0f;
  q = p + 0x152c;
  for (i = 0; i < 9; i++)
  {
    *((float *) (q + 0x10)) = zero;
    *((float *) (q + 0xc)) = zero;
    *((int *) (q + 0x7c)) = 0;
    *((char *) (q + 0x78)) = 0;
    *((float *) (q + 0x18)) = one;
    *((float *) (q + 0x1c)) = zero;
    *((float *) (q + 0x20)) = zero;
    *((float *) (q + 0x24)) = zero;
    *((float *) (q + 0x28)) = one;
    *((float *) (q + 0x2c)) = zero;
    *((float *) (q + 0x30)) = zero;
    *((float *) (q + 0x34)) = zero;
    *((float *) (q + 0x38)) = one;
    *((float *) (q + 0x3c)) = zero;
    *((float *) (q + 0x40)) = zero;
    *((float *) (q + 0x44)) = zero;
    *((float *) (q + 0x48)) = one;
    *((float *) (q + 0x4c)) = zero;
    *((float *) (q + 0x50)) = zero;
    *((float *) (q + 0x54)) = zero;
    *((float *) (q + 0x58)) = one;
    *((float *) (q + 0x5c)) = zero;
    *((float *) (q + 0x60)) = zero;
    *((float *) (q + 0x64)) = zero;
    *((float *) (q + 0x68)) = one;
    *((float *) (q + 0x6c)) = zero;
    *((float *) (q + 0x70)) = zero;
    *((float *) (q + 0x74)) = zero;
    q += 0x80;
    *((float *) (q + 0x10)) = zero;
    *((float *) (q + 0xc)) = zero;
    *((int *) (q + 0x7c)) = 0;
    *((char *) (q + 0x78)) = 0;
    *((float *) (q + 0x18)) = one;
    *((float *) (q + 0x1c)) = zero;
    *((float *) (q + 0x20)) = zero;
    *((float *) (q + 0x24)) = zero;
    *((float *) (q + 0x28)) = one;
    *((float *) (q + 0x2c)) = zero;
    *((float *) (q + 0x30)) = zero;
    *((float *) (q + 0x34)) = zero;
    *((float *) (q + 0x38)) = one;
    *((float *) (q + 0x3c)) = zero;
    *((float *) (q + 0x40)) = zero;
    *((float *) (q + 0x44)) = zero;
    *((float *) (q + 0x48)) = one;
    *((float *) (q + 0x4c)) = zero;
    *((float *) (q + 0x50)) = zero;
    *((float *) (q + 0x54)) = zero;
    *((float *) (q + 0x58)) = one;
    *((float *) (q + 0x5c)) = zero;
    *((float *) (q + 0x60)) = zero;
    *((float *) (q + 0x64)) = zero;
    *((float *) (q + 0x68)) = one;
    *((float *) (q + 0x6c)) = zero;
    *((float *) (q + 0x70)) = zero;
    *((float *) (q + 0x74)) = zero;
    q += 0x80;
  }

  *((int *) (p + 0x1e3c)) = 0;
  *((int *) (p + 0x1e40)) = 0;
  q = p + 0x23ac;
  for (i = 0; i < 2; i++)
  {
    *((float *) (q + 8)) = zero;
    *((float *) (q + 4)) = zero;
    *((float *) q) = zero;
    *((float *) (q + 0x18)) = zero;
    *((float *) (q + 0x14)) = zero;
    *((float *) (q + 0x10)) = zero;
    *((float *) (q + 0x1c)) = zero;
    *((float *) (q + 0xc)) = zero;
    *((char *) (q + 0x20)) = 0;
    *((float *) (q + 0x24)) = zero;
    *((float *) (q + 0x28)) = zero;
    *((float *) (q + 0x2c)) = zero;
    *((float *) (q + 0x30)) = zero;
    *((float *) (q + 0x34)) = zero;
    *((float *) (q + 0x38)) = zero;
    *((float *) (q + 0x44)) = zero;
    *((float *) (q + 0x48)) = zero;
    *((float *) (q + 0x4c)) = zero;
    *((float *) (q + 0x50)) = zero;
    *((float *) (q + 0x54)) = zero;
    *((float *) (q + 0x58)) = zero;
    *((float *) (q + 0x5c)) = one;
    *((float *) (q + 0x60)) = zero;
    *((int *) (q + 0x64)) = 0;
    *((float *) (q + 0x68)) = zero;
    *((char *) (q + 0x6c)) = 0;
    *((int *) (q + 0x70)) = 0;
    q += 0x74;
    *((float *) (q + 8)) = zero;
    *((float *) (q + 4)) = zero;
    *((float *) q) = zero;
    *((float *) (q + 0x18)) = zero;
    *((float *) (q + 0x14)) = zero;
    *((float *) (q + 0x10)) = zero;
    *((float *) (q + 0x1c)) = zero;
    *((float *) (q + 0xc)) = zero;
    *((char *) (q + 0x20)) = 0;
    *((float *) (q + 0x24)) = zero;
    *((float *) (q + 0x28)) = zero;
    *((float *) (q + 0x2c)) = zero;
    *((float *) (q + 0x30)) = zero;
    *((float *) (q + 0x34)) = zero;
    *((float *) (q + 0x38)) = zero;
    *((float *) (q + 0x44)) = zero;
    *((float *) (q + 0x48)) = zero;
    *((float *) (q + 0x4c)) = zero;
    *((float *) (q + 0x50)) = zero;
    *((float *) (q + 0x54)) = zero;
    *((float *) (q + 0x58)) = zero;
    *((float *) (q + 0x5c)) = one;
    *((float *) (q + 0x60)) = zero;
    *((int *) (q + 0x64)) = 0;
    *((float *) (q + 0x68)) = zero;
    *((char *) (q + 0x6c)) = 0;
    *((int *) (q + 0x70)) = 0;
    q += 0x74;
  }

  obj = fn_801B2ED0(*((int *) (p + 0x1ec)));
  v = (*((void *(**)(void *)) ((*((char **) obj)) + 0x18)))(obj);
  *((int *) (((char *) v) + 0xc)) = 0;
  fn_801B8100(p + 0x274, *((int *) (p + 0x1ec)), *((int *) (p + 0x1f0)));
  (*((void (**)(void *, void *)) ((*((char **) p)) + 0x54)))(p, p + 0x274);
  fn_8013605C(v);
  if (fn_801CF064() == 0)
  {
    path = p + 0x1e44;
  }
  else
  {
    path = p + 0x20f8;
  }
  fn_8018F2C0(p, path);
  obj = *((void **) (p + 0x268));
  (*((void (**)(void *)) ((*((char **) obj)) + 0x28)))(obj);
  if ((*fn_801E1F44()) == 1)
  {
    resetSceneLights(p);
  }
  *((float *) (p + 0x26cc)) = 1.0f;
  *((float *) (p + 0x26d0)) = 1.0f;
  *((int *) (p + 0x26d4)) = 0;
  *((float *) (p + 0x26d8)) = -1000.0f;
  *((float *) (p + 0x26dc)) = -1000.0f;
  *((float *) (p + 0x2684)) = 9.81f;
  obj = *((void **) (p + 0x2584));
  (*((void (**)(void *)) ((*((char **) obj)) + 0x10)))(obj);
}
#pragma pop

/* Sync vehicle/replay state at 0x1E44 with the object at 0x328; when in mode 2 and not a PCAR record with flag 0x4 set, apply an adjustment and copy the state back. */
void fn_80183DF8(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    if (*(int *)(base + 0x328) != 0) {
        fn_8018F538(base, base + 0x1E44);
        fn_80279C00(*(int *)(base + 0x328), base + 0x1E44);
        if (fn_801769C4() == 2 && *(unsigned int *)(base + 0x10) != 0x50434152 && (*(unsigned char *)(base + 0x260) & 4) == 0) {
            fn_80181EAC(*(int *)(base + 0x328));
            fn_80279B28(*(int *)(base + 0x328), base + 0x1E44);
        }
    }
}

extern int fn_800216D0(void);
extern void fn_801BEB1C(int, int *);
extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80561CAC, lbl_80561CD0, lbl_80561D9C;
extern float lbl_80561CAC, lbl_80561CD0, lbl_80561D9C, lbl_8055E4E0;
extern void fn_8017B4AC(void *, void *);
extern float lbl_80561DA0, lbl_80561CDC, lbl_80561CD8;
extern float lbl_80561DA4, lbl_80561DA8, lbl_80561CE4, lbl_80561D98, lbl_80561DAC;
extern void fn_801796CC(int, void *, int);
extern int fn_80129D18(int, int);
extern float lbl_80561CCC, lbl_80561D40, lbl_80561DB0;
extern float lbl_80561D00, lbl_80561CF0, lbl_80561CF4, lbl_80561CF8;
extern float lbl_80561D44, lbl_80561DB4, lbl_80561D50, lbl_80561DB8;
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_80561CCC, lbl_80561D40, lbl_80561DB0, lbl_80561DBC;
#pragma paired_single off
void fn_80183E7C(void *arg0) {
    unsigned char *self = (unsigned char *)arg0;
    unsigned char stack_space[0x2b0];
    int i;
    if (fn_800216D0() != 0) {
        *(float *)(self + 0x25dc) = lbl_80561CAC;
        *(float *)(self + 0x25e0) = lbl_80561CAC;
        *(float *)(self + 0x25e4) = lbl_80561CD0;
        self[0x260d] = 0;
        if (self[0x25c0] != 0) {
            *(float *)(self + 0x25bc) = lbl_8055E4E0;
            fn_801BEB1C(*(int *)(self + 0x1ec), (int *)&stack_space[4]);
            for (i = 0; i < 2; i++) {
                unsigned char *src = (unsigned char *)*(int *)&stack_space[4] + i * 0x20;
                unsigned char *next = src + 0x10;
                unsigned char *dst = self + 0x23ac + i * 0xe8;
                *(float *)(dst + 0x4c) = *(float *)(src + 0x150);
                *(float *)(dst + 0x50) = *(float *)(src + 0x154);
                *(float *)(dst + 0x54) = *(float *)(src + 0x158);
                *(float *)(dst + 0x58) = *(float *)(src + 0x110);
                *(float *)(dst + 0x5c) = *(float *)(src + 0x114);
                *(float *)(dst + 0x60) = *(float *)(src + 0x118);
                *(float *)(dst + 0xc0) = *(float *)(next + 0x150);
                *(float *)(dst + 0xc4) = *(float *)(next + 0x154);
                *(float *)(dst + 0xc8) = *(float *)(next + 0x158);
                *(float *)(dst + 0xcc) = *(float *)(next + 0x110);
                *(float *)(dst + 0xd0) = *(float *)(next + 0x114);
                *(float *)(dst + 0xd4) = *(float *)(next + 0x118);
            }
        }
    }
    if (self[0x260d] != 0)
        *(float *)(self + 0x2598) += lbl_80561D9C;
    else
        *(float *)(self + 0x2598) = lbl_80561CAC;
    {
        float step = *(float *)(self + 0x2650) - lbl_80561D9C;
        if (step < lbl_80561CAC) step = lbl_80561CAC;
        *(float *)(self + 0x2650) = step;
        if (!(fabsf(step) <= lbl_80558DC4) && *(float *)(self + 0x25d4) < lbl_80561DA0) {
            if (step < lbl_80561CDC) step = lbl_80561CDC;
            *(float *)(self + 0x2650) = step;
            if (*(int *)(self + 0x2620) > 2) {
                float dot = PSVECDotProduct(self + 0x124, self + 0x48);
                if (fabsf(dot) < lbl_80561CD8) {
                    float t = (step - lbl_80561CAC) / lbl_80561CD0;
                    float q;
                    float amount;
                    float velocity;
                    float factor;
                    float vec[3];
                    if (t > lbl_80561CD0) t = lbl_80561CD0;
                    if (t < lbl_80561CAC) t = lbl_80561CAC;
                    q = (*(float *)(self + 0x25d4) - lbl_80561DA4) / lbl_80561DA8;
                    if (q < lbl_80561CD0) q = lbl_80561CD0;
                    if (q < lbl_80561CAC) q = lbl_80561CAC;
                    amount = lbl_80561CAC + t * lbl_80561CD0;
                    velocity = lbl_80561CE4 * *(float *)(self + 0xd4);
                    velocity = lbl_80561D98 * velocity;
                    velocity = lbl_80561DAC * velocity;
                    velocity = velocity * amount;
                    factor = (lbl_80561CAC + q * lbl_80561CD0) * velocity;
                    if (dot <= lbl_80561CAC) factor = -factor;
                    vec[0] = *(float *)(self + 0x48) * factor;
                    vec[1] = *(float *)(self + 0x4c) * factor;
                    vec[2] = *(float *)(self + 0x50) * factor;
                    fn_8017B4AC(self, vec);
                }
            }
        }
    }
    if (*(float *)(self + 0x258c) <= lbl_80561CCC && self[0x259c] != 0) {
        unsigned char *args = &stack_space[0x218];
        int *vtable;
        *(int *)(args + 0) = *(int *)(self + 0x1ec);
        *(float *)(args + 4) = lbl_80561CD0;
        *(float *)(args + 8) = *(float *)(self + 0x25d0);
        *(int *)(args + 12) = -1;
        fn_801796CC(4, args, 0x10);
        if (*(float *)(self + 0x2608) - *(float *)(self + 0x25e0) > lbl_80561D40) {
            *(float *)(self + 0x2608) = lbl_80561CAC;
            if (fn_80129D18(4, 0xa) < 3) {
                vtable = *(int **)*(void **)(self + 0x2584);
                ((void (*)(void *))vtable[7])(*(void **)(self + 0x2584));
            }
        }
        args = &stack_space[0x208];
        *(int *)(args + 0) = *(int *)(self + 0x1ec);
        *(float *)(args + 4) = lbl_80561CD0;
        *(float *)(args + 8) = *(float *)(self + 0x25d0);
        *(int *)(args + 12) = -1;
        fn_801796CC(4, args, 0x10);
        {
            float current = *(float *)(self + 0x2608);
            float target = *(float *)(self + 0x25e0);
            *(float *)(self + 0x2608) = target + lbl_80561DB0 * (current - target);
        }
    }
    {
        unsigned int flags = *(unsigned int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4);
        int active;
        if ((flags & 0x20000) == 0)
            active = fabsf(*(float *)(self + 0x2690)) <= lbl_80558DC4;
        else
            active = fabsf(*(float *)(self + 0x2690) - lbl_80561CD0) <= lbl_80558DC4;
        if (!(fabsf(*(float *)(self + 0x2650)) <= lbl_80558DC4) && active) {
            if (*(unsigned int *)(self + 0x10) == 0x50434152) {
                void *obj = *(void **)(self + 0x270);
                int *vt = *(int **)obj;
                if (((int (*)(void *))vt[5])(obj) != 0) {
                    int state = *(int *)(self + 0x2620);
                    float speed = *(float *)(self + 0x4c);
                    if (state <= 2 && speed < lbl_80561DB4) {
                        if (state == 0) *(float *)(self + 0x2614) = lbl_80561CAC;
                        else if (fabsf(*(float *)(self + 0x2614)) <= lbl_80558DC4) {
                            if (speed < lbl_80561CAC) {
                                float next = *(float *)(self + 0x2614) + lbl_80561D9C;
                                if (*(float *)(self + 0x25d4) < lbl_80561D50) next += lbl_80561DB8;
                                *(float *)(self + 0x2614) = next;
                            } else *(float *)(self + 0x2614) = lbl_80561CAC;
                        } else *(float *)(self + 0x2614) = lbl_80561CAC;
                    }
                    if (*(float *)(self + 0x2614) >= lbl_80561D44 &&
                        *(float *)(self + 0x4c) > lbl_80561CDC)
                        *(float *)(self + 0x2614) = lbl_80561CAC;
                    if (fabsf(*(float *)(self + 0x58)) <= lbl_80561CAC &&
                        fabsf(*(float *)(self + 0x40)) < lbl_80561CCC) {
                        float factor = -*(float *)(self + 0x40) * lbl_80561D00;
                        float *v = (float *)&stack_space[0x20c];
                        float *out = (float *)&stack_space[0x200];
                        float dot, scale;
                        v[0] = *(float *)(self + 0x54) * factor;
                        v[1] = *(float *)(self + 0x58) * factor;
                        v[2] = *(float *)(self + 0x5c) * factor;
                        dot = PSVECDotProduct(self + 0x124, v);
                        scale = (dot - lbl_80561CF0) * lbl_80561CF8;
                        if (scale > lbl_80561CD0) scale = lbl_80561CD0;
                        if (scale < lbl_80561CAC) scale = lbl_80561CAC;
                        scale = lbl_80561CD0 - scale;
                        out[0] = v[0] * scale;
                        out[1] = v[1] * scale;
                        out[2] = v[2] * scale;
                        fn_8017B4AC(self, out);
                    }
                }
            }
        }
    }
    {
        int state = *(int *)(self + 0x2620);
        if (state == 0) {
            *(int *)(self + 0x2648) = 7;
        } else if (state >= 3) {
            *(int *)(self + 0x2648) = 0;
            self[0x2624] = 0;
            self[0x2625] = 0;
        } else if (*(int *)(self + 0x2648) == 0) {
            *(int *)(self + 0x2648) = 1;
        }
        {
            int mode = *(int *)(self + 0x2648);
            if (mode >= 1 && mode <= 6) {
                float *vec = (float *)&stack_space[0x1e4];
                vec[0] = *(float *)(self + 0x124) * lbl_80561DBC;
                vec[1] = *(float *)(self + 0x128) * lbl_80561DBC;
                vec[2] = *(float *)(self + 0x12c) * lbl_80561DBC;
                if (!(fabsf(*(float *)(self + 0x2650)) <= lbl_80558DC4))
                    fn_8017B4AC(self, vec);
                *(int *)(self + 0x2648) = mode + 1;
                {
                    float *a = (float *)&stack_space[0x1d8];
                    float *b = (float *)&stack_space[0x1cc];
                    float *c = (float *)&stack_space[0x1c0];
                    a[0] = *(float *)(self + 0x23f8) - *(float *)(self + 0x2554);
                    a[1] = *(float *)(self + 0x23fc) - *(float *)(self + 0x2558);
                    a[2] = *(float *)(self + 0x2400) - *(float *)(self + 0x255c);
                    b[0] = *(float *)(self + 0x246c) - *(float *)(self + 0x24e0);
                    b[1] = *(float *)(self + 0x2470) - *(float *)(self + 0x24e4);
                    b[2] = *(float *)(self + 0x2474) - *(float *)(self + 0x24e8);
                    PSVECCrossProduct(a, b, c);
                    {
                        float x = c[2] - *(float *)(self + 0x25ac);
                        float y = c[1] - *(float *)(self + 0x25a8);
                        float z = c[0];
                        *(float *)(self + 0x25a4) = x * lbl_80561D0C;
                        (void)y;
                        (void)z;
                    }
                }
            }
        }
    }
}
// Default callback / stub: always reports failure (0).
int fn_80186DDC(void) { return 0; }

/* Tail-call wrapper that forwards to fn_8018A8A8. */
void fn_80186DE4(void) {
    fn_8018A8A8();
}

extern void fn_80190E6C(void);
extern int fn_801C5B60(void);
extern void fn_80196A9C(void);
extern void fn_801C56AC(void);
extern void **fn_801B83A0(void);
extern void fn_801BEDA8(void *, void *, void *, void *, void *);
extern void fn_80183E7C(void *);
extern void fn_801ADB44(void *, void *);
extern void fn_8017C7C8(void *, float *, float *);
extern float PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
extern float PSVECMag(const void *);
extern void carPostUpdate(void);
extern int fn_801D04A8(int);
extern float fn_80181A14(void *);
extern float fn_80181A48(void *);
extern int fn_8018B06C(void *);
extern float lbl_80561CAC;
extern float lbl_80561CD0;
extern float lbl_80561CE4;
extern float lbl_80561D44;
extern float lbl_80561DD0;
extern float lbl_80561D00;
extern float lbl_80561DA0;
extern float lbl_80561CC0;
/* lbl_80561CB0: declared const at file scope. */
extern float lbl_80561E6C;
extern float lbl_80561E58;
extern float lbl_80561E90;
extern float lbl_80561E94;
extern float lbl_80561D98;
extern float lbl_80561D60;
extern float lbl_80561E88;
extern float lbl_80561E8C;
extern float lbl_80561E70;
extern float lbl_80561E74;
extern float lbl_80561E78;
extern float lbl_80561E7C;
extern float lbl_80561D04;
extern float lbl_80561EA4;
extern float lbl_80561EAC;
extern float lbl_80561EA8;
extern float lbl_80561EA0;
extern float lbl_80561DEC;
extern float lbl_80561EB0;
extern float lbl_80561DE4;
extern float lbl_80561EB8;
extern float lbl_80561EB4;
extern float lbl_80561EBC;
extern float lbl_80561EC0;
extern float lbl_80561EC4;
extern float lbl_80561EC8;
extern float lbl_80561ECC;
extern float lbl_80561ED0;
extern float lbl_80561D50;
extern float lbl_80561DA4;
extern float lbl_80561CCC;
extern float lbl_80561E60;
extern float lbl_80561E64;
extern float lbl_80561E68;
extern float lbl_80561E5C;
extern float lbl_80561E80;
extern float lbl_80561ED8;
extern float lbl_8055E4E8;
extern float lbl_80561DC0;
#pragma scheduling invalid_target
void fn_80186DE8(void) {
    struct Frame {
        char pad0[0x70];
        int sp78, sp7c, sp80, sp84, sp88;
        char pad1[0x1a8 - 0x8c];
        volatile float resultSecond[3];
        volatile float tailB;
        volatile float resultFirst[3];
        volatile float tailC;
        char padToSums[0x480 - 0x1c8];
        volatile float sumSecond[3];
        volatile float sumFirst[3];
        volatile float second[3];
        volatile float first[3];
        char pad2[0x4f0 - 0x4b0];
        volatile double values[37];
        char pad3[4];
        volatile int state[8];
        char pad4[8];
        volatile int tableBase;
        char pad5[0x6c8 - 0x640];
    } frame;
    void **table;
    int count, i;
    float f18, f14, f15;
    float *velocity;
    void *r18, *node;
    char *r19;

    fn_80190E6C();
    if (fn_801C5B60()) return;
    fn_80196A9C();
    fn_801C56AC();
    r18 = fn_801B83A0();
    ((void (*)(void *))(*(void ***)r18)[0xC8 / 4])(r18);
    frame.sp78 = 0;
    fn_801BEDA8(&frame.sp88, &frame.sp84, &frame.sp80, &frame.sp7c, &frame.sp78);
    table = (void **)lbl_804348E8;
    f18 = lbl_80561CAC;
    f14 = lbl_80561D34;
    f15 = lbl_80561CE4;
    i = 0;
    count = 0;
    while (frame.sp78 > count) {
        r18 = table[0];
        r19 = (char *)(void *)frame.sp88 + i;
        fn_80183E7C(r18);
        *((unsigned char *)r18 + 0x1E9) = 1;
        if (*(float *)((char *)r18 + 0x4C) < f18) {
            node = *(void **)((char *)r18 + 0xD0);
            while (node != 0) {
                fn_801ADB44(node, r18);
                node = *(void **)node;
            }
            fn_8017C7C8(r18, (float *)frame.first, (float *)frame.second);
            if (*((unsigned char *)r18 + 0x26AC)) {
                frame.first[0] = f18;
                frame.first[1] = f18;
                frame.first[2] = f18;
                frame.second[0] = f18;
                frame.second[1] = f18;
                frame.second[2] = f18;
            }
            {
                float a0 = *(float *)(r19 + 0x90);
                float x0 = a0 + frame.first[0];
                float a2 = *(float *)(r19 + 0x98);
                float x2 = a2 + frame.first[2];
                float a1 = *(float *)(r19 + 0x94);
                float x1 = a1 + frame.first[1];
                float b2 = *(float *)(r19 + 0xA8);
                float y2 = b2 + frame.second[2];
                float b1 = *(float *)(r19 + 0xA4);
                float y1 = b1 + frame.second[1];
                float b0 = *(float *)(r19 + 0xA0);
                float y0 = b0 + frame.second[0];
                *(float *)(r19 + 0x90) = x0;
                *(float *)(r19 + 0x94) = x1;
                *(float *)(r19 + 0x9C) = frame.tailC;
                *(float *)(r19 + 0x98) = x2;
                *(float *)(r19 + 0xA0) = y0;
                *(float *)(r19 + 0xA4) = y1;
                *(float *)(r19 + 0xA8) = y2;
                frame.sumFirst[0] = a0;
                frame.sumFirst[1] = a1;
                frame.sumFirst[2] = a2;
                frame.sumFirst[0] = x0;
                frame.sumFirst[1] = x1;
                frame.sumFirst[2] = x2;
                frame.sumSecond[0] = y0;
                frame.sumSecond[1] = y1;
                frame.sumSecond[2] = y2;
                frame.resultFirst[0] = x0;
                frame.resultFirst[1] = x1;
                frame.resultFirst[2] = x2;
                frame.resultSecond[0] = y0;
                frame.resultSecond[1] = y1;
                frame.resultSecond[2] = y2;
                *(float *)(r19 + 0xAC) = frame.tailB;
            }
            velocity = (float *)((char *)r18 + 0x124);
            if (PSVECDotProduct(velocity, velocity) > f15) {
                PSVECNormalize(velocity, velocity);
                velocity[0] *= f14;
                velocity[1] *= f14;
                velocity[2] *= f14;
            }
        }
        table += 1;
        i += 0xB0;
        count += 1;
    }
    carPostUpdate();
    frame.values[1] = lbl_80561D2C;
    frame.tableBase = (int)0x80430000;
    frame.state[7] = (int)(void *)lbl_804348E8;
    frame.values[0] = lbl_80561D44;
    frame.state[0] = 0;
    frame.values[2] = lbl_80561DD0;
    frame.state[1] = 0;
    frame.values[3] = lbl_80561D00;
    frame.state[2] = 0;
    frame.values[4] = lbl_80561DA0;
    frame.values[5] = lbl_80561DC0;
    frame.values[6] = lbl_80561CB0;
    frame.state[3] = 0;
    frame.values[7] = lbl_80561CD8;
    frame.state[4] = 0;
    frame.values[8] = lbl_80561E58;
    frame.state[5] = 0;
    frame.values[10] = lbl_80561D38;
    frame.values[11] = lbl_80561E60;
    frame.values[12] = lbl_80561E64;
    frame.values[13] = lbl_80561E68;
    frame.tableBase += 0x4950;
    frame.values[9] = lbl_80561E5C;
    frame.values[14] = lbl_80561E70;
    frame.values[15] = lbl_80561E74;
    frame.state[6] = 0;
    frame.values[16] = lbl_80561E78;
    frame.values[17] = lbl_80561E7C;
    frame.values[18] = lbl_80561D04;
    frame.values[19] = lbl_80561DA4;
    frame.values[20] = lbl_80561EA4;
    frame.values[21] = lbl_80561EAC;
    frame.values[22] = lbl_80561EA8;
    frame.values[23] = lbl_80561DEC;
    frame.values[24] = lbl_80561EB0;
    frame.values[25] = lbl_80561DE4;
    frame.values[26] = lbl_80561EB8;
    frame.values[27] = lbl_80561EB4;
    frame.values[28] = lbl_80561EBC;
    frame.values[29] = lbl_80561EC0;
    frame.values[30] = lbl_80561DA4;
    frame.values[31] = lbl_80561EC4;
    frame.values[32] = *(double *)&lbl_80561ED8;
    frame.values[33] = lbl_80561EC8;
    frame.values[34] = lbl_80561ECC;
    frame.values[35] = lbl_80561ED0;
    frame.values[36] = lbl_80561D50;
}
#pragma scheduling on
extern float lbl_80561CAC, lbl_80561CDC, lbl_80561D90, lbl_80561D9C;
extern float lbl_80561DE4, lbl_80561E5C, lbl_80561EE0, lbl_80561EE4;
extern float lbl_80561EE8, lbl_80561EEC, lbl_80561EF0, lbl_80561EF4;
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_80188A80(void *arg0) {
struct ObjArg {
virtual int v0(); virtual int v1(int); virtual int v2(); virtual int v3();
virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
virtual int v12();
};
struct ObjVoid {
virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
virtual int v12();
};
char *p = (char *)arg0;
float v[3];
float s[3];
float t;
fn_8017A57C(arg0);
if (*(void **)(p + 0x257C) != 0) {
int i = ((ObjArg *)*(void **)(p + 0x270))->v12();
((ObjArg *)*(void **)(p + 0x257C))->v1(i);
}
if (*(void **)(p + 0x2580) != 0) ((ObjVoid *)*(void **)(p + 0x2580))->v1();
if (*(void **)(p + 0x2584) != 0) ((ObjVoid *)*(void **)(p + 0x2584))->v1();
t = *(float *)(p + 0x269C);
if (t < lbl_80561CDC) {
*(float *)(p + 0x269C) = t + lbl_80561D9C;
} else {
float a = *(float *)(p + 0x2690);
float b = lbl_80561EE0 + *(float *)(p + 0x2694);
a = (a < b) ? a : b;
*(float *)(p + 0x2694) = a;
}
{
const float *m = (const float *)(p + 0x3C);
const float *src = (const float *)(p + 0x16C);
float *dst = v;
if (dst == src) {
float x = src[2] * m[2] + (src[0] * m[0] + src[1] * m[1]);
float y = src[2] * m[5] + (src[0] * m[3] + src[1] * m[4]);
float z = src[2] * m[8] + (src[0] * m[6] + src[1] * m[7]);
dst[0] = x; dst[1] = y; dst[2] = z;
} else {
dst[0] = src[2] * m[2] + (src[0] * m[0] + src[1] * m[1]);
dst[1] = src[2] * m[5] + (src[0] * m[3] + src[1] * m[4]);
dst[2] = src[2] * m[8] + (src[0] * m[6] + src[1] * m[7]);
}
}
{
float kDE4 = lbl_80561DE4;
float kE5C = lbl_80561E5C;
float kD90 = lbl_80561D90;
float kEE4 = lbl_80561EE4;
float kD9C = lbl_80561D9C;
float kEE8 = lbl_80561EE8;
float kEEC = lbl_80561EEC;
float kCAC = lbl_80561CAC;
float kEF4 = lbl_80561EF4;
float kEF0 = lbl_80561EF0;
v[0] *= kDE4;
v[1] *= kDE4;
v[2] *= kDE4;
float *vel = (float *)(p + 0x2654);
float *acc = (float *)(p + 0x266C);
float a0 = acc[0], a1 = acc[1], a2 = acc[2];
float na0 = a0 * kEE8;
float na1 = a1 * kEE8;
float v0 = vel[0], v1 = vel[1], v2 = vel[2], v3 = vel[3], v4 = vel[4], v5 = vel[5];
s[1] = v[1] + a1 * kE5C;
s[0] = v[0] + a0 * kE5C + v0 * kD90;
s[2] = v[2] + a2 * kE5C;
s[1] = s[1] + v1 * kD90;
s[2] = s[2] + v2 * kD90;
s[0] = s[0] + v3 * kEE4;
s[1] = s[1] + v4 * kEE4;
s[2] = s[2] + v5 * kEE4;
vel[0] = v0 + s[0] * kD9C;
vel[1] = v1 + s[1] * kD9C;
acc[2] = a2 * kEE8;
acc[0] = na0;
vel[4] = v4 + vel[1] * kD9C;
acc[1] = na1;
vel[3] = v3 + vel[0] * kD9C;
vel[2] = v2 + s[2] * kD9C;
vel[5] = v5 + vel[2] * kD9C;
acc[0] = na0 + v[0] * kEEC;
acc[1] = na1 + v[1] * kEEC;
acc[2] = kCAC;
if (vel[5] < kEF4) {
vel[5] = kEF4;
vel[2] = vel[2] > kCAC ? vel[2] : kCAC;
}
acc[1] = kCAC;
float c = kEF0, d = vel[5];
vel[5] = (c < d) ? c : d;
}
}
#pragma cplusplus off
#pragma pop

// Default callback / stub: always reports failure (0).
int fn_80188E24(void) { return 0; }

#pragma push
#pragma ppc_psq_save off
#pragma paired off
#pragma paired_single off
void fn_80188E2C(void *arg0, void *arg1)
{
  unsigned char *a0 = (unsigned char *) arg0;
  unsigned char *a1 = (unsigned char *) arg1;
  unsigned char *dst;
  unsigned char *base;
  float t;
  unsigned short flags;
  void *obj;
  float v;
  float stack[12];
  dst = a1 + (*((int *) (a0 + 8)));
  memset(dst, 0, 0xFA8u);
  base = a1 + (*((int *) (a0 + 8)));
  t = lbl_8055E460;
  if (((float) __fabs((double) (t - lbl_80561CD0))) <= lbl_80558DC4)
  {
    int *bp = (int *) base;
    int *ap = (int *) (a0 + 0x70);
    int a;
    int b;
    a = ap[0]; b = ap[1]; bp[0] = a;
    bp[1] = b;
    a = ap[2]; b = ap[3]; bp[2] = a;
    bp[3] = b;
    a = ap[4]; b = ap[5]; bp[4] = a;
    bp[5] = b;
    a = ap[6]; b = ap[7]; bp[6] = a;
    bp[7] = b;
    a = ap[8]; bp[8] = a;
    a = ap[9]; b = ap[10]; bp[9] = a;
    bp[10] = b;
    a = ap[11]; bp[11] = a;
  }
  else
  {
    int i;
    float *d = stack;
    float *s2 = (float *) (a0 + 0xA0);
    float *s1 = (float *) (a0 + 0x70);
    for (i = 0; i < 2; i++)
    {
      float f0;
      float f1;
      f0 = s1[0]; f1 = s2[0]; d[0] = f1 + (t * (f0 - f1));
      f0 = s1[1]; f1 = s2[1]; d[1] = f1 + (t * (f0 - f1));
      f0 = s1[2]; f1 = s2[2]; d[2] = f1 + (t * (f0 - f1));
      f0 = s1[3]; f1 = s2[3]; d[3] = f1 + (t * (f0 - f1));
      f0 = s1[4]; f1 = s2[4]; d[4] = f1 + (t * (f0 - f1));
      f0 = s1[5]; f1 = s2[5]; d[5] = f1 + (t * (f0 - f1));
      s1 += 6; s2 += 6; d += 6;
    }

    {
      int *bp = (int *) base;
      int *sp = (int *) stack;
      int a;
      int b;
      a = sp[0]; b = sp[1]; bp[0] = a;
      bp[1] = b;
      a = sp[2]; b = sp[3]; bp[2] = a;
      bp[3] = b;
      a = sp[4]; b = sp[5]; bp[4] = a;
      bp[5] = b;
      a = sp[6]; b = sp[7]; bp[6] = a;
      bp[7] = b;
      a = sp[8]; bp[8] = a;
      a = sp[9]; b = sp[10]; bp[9] = a;
      bp[10] = b;
      a = sp[11]; bp[11] = a;
    }
  }
  flags = 0;
  *((short *) (base + 0x30)) = *((short *) (a0 + 0x6C));
  obj = *((void **) (a0 + 0x270));
  if (((int (*)(void *)) (*((void ***) ((char *) obj)))[14])(obj) != 0)
  {
    flags |= 0x40;
  }
  if (!(((float) __fabs((double) (*((float *) (a0 + 0x2690))))) <= lbl_80558DC4))
  {
    flags |= 0x20;
  }
  *((float *) (dst + 0x34)) = *((float *) (a0 + 0x25D0));
  *((float *) (dst + 0x4C)) = (float) fn_8002F234(((*((float *) (a0 + 0x118))) * (*((float *) (a0 + 0x118)))) + ((*((float *) (a0 + 0x120))) * (*((float *) (a0 + 0x120)))));
  *((float *) (dst + 0x3C)) = *((float *) (a0 + 0x25F0));
  *((float *) (dst + 0x38)) = *((float *) (a0 + 0x25F4));
  *((float *) (dst + 0x40)) = *((float *) (a0 + 0x25E4));
  *((float *) (dst + 0x44)) = *((float *) (a0 + 0x25F8));
  *((int *) (dst + 0x48)) = fn_8018B06C(arg0);
  *((float *) (dst + 0x50)) = lbl_80561CE4;
  if ((lbl_8055E4F5 != 0) && ((*((int *) (a0 + 0x24))) == 0))
  {
    if (lbl_8055E3C4 & 4)
    {
      *((float *) (dst + 0x22C)) = lbl_80561CAC;
    }
    else
    {
      *((float *) (dst + 0x22C)) = lbl_80561CD0;
    }
  }
  else
  {
    *((float *) (dst + 0x22C)) = lbl_80561CD0;
  }
  *((unsigned short *) (dst + 0x6E)) = flags;
  *((float *) (dst + 0x70)) = *((float *) (a0 + 0x118));
  *((float *) (dst + 0x74)) = *((float *) (a0 + 0x11C));
  *((float *) (dst + 0x78)) = *((float *) (a0 + 0x120));
  *((float *) (dst + 0x64)) = *((float *) (a0 + 0x25D4));
  *((float *) (dst + 0x2C4)) = *((float *) (a0 + 0x2588));
  if ((*((unsigned char *) (a0 + 0x26E0))) != 0)
  {
    v = *((float *) (a0 + 0x2690));
    if (v > lbl_80561CCC)
    {
    }
    else
    {
      v = lbl_80561CCC;
    }
  }
  else
  {
    v = *((float *) (a0 + 0x2690));
  }
  *((float *) (dst + 0x28C)) = v;
  *((float *) (dst + 0x290)) = *((float *) (a0 + 0x2694));
  *((float *) (dst + 0x294)) = *((float *) (a0 + 0x2698));
  *((int *) (dst + 0x298)) = *((int *) (a0 + 0x268C));
  if ((*((float *) (a0 + 0x25BC))) > lbl_80558DC4)
  {
    *((float *) (dst + 0x2D4)) = *((float *) (a0 + 0x25BC));
  }
  else
  {
    *((float *) (dst + 0x2D4)) = lbl_80561CAC;
  }
  *((float *) (dst + 0x2A8)) = *((float *) (a0 + 0x25A0));
  *((int *) (dst + 0x29C)) = *((int *) (a0 + 0x5A0));
  if (((*((float *) (a0 + 0x25E4))) > lbl_80561D00) && (!(flags & 0x20)))
  {
    *((int *) (dst + 0x29C)) |= 0x20000000;
  }
  else
  {
    *((int *) (dst + 0x29C)) |= 0x10000000;
  }
  *((float *) (dst + 0x238)) = *((float *) (a0 + 0x2660));
  *((float *) (dst + 0x23C)) = *((float *) (a0 + 0x2664));
  *((float *) (dst + 0x240)) = *((float *) (a0 + 0x2668));
  {
    float maxy;
    float zero;
    unsigned char *w;
    unsigned char *s;
    int i;
    float f1;
    float f5;
    float f3;
    zero = lbl_80561CAC;
    maxy = lbl_80561CAC;
    w = dst + 0x7C;
    f5 = lbl_80561CD0;
    s = a0 + 0x23AC;
    f3 = lbl_80561D9C;
    for (i = 0; i < 4; i++)
    {
      float sx = *((float *) (s + 0x30));
      float sy = *((float *) (s + 0x34));
      float sz = *((float *) (s + 0x38));
      float dx = sx - (*((float *) (a0 + 0x30)));
      float dy = sy - (*((float *) (a0 + 0x34)));
      float dz = sz - (*((float *) (a0 + 0x38)));
      float ox = *((float *) (s + 0x0C));
      float oy = *((float *) (s + 0x1C));
      float x2 = dx + ox;
      float y2;
      float ix = dx + (lbl_8055E460 * (x2 - dx));
      float iy = dy + (lbl_8055E460 * ((dy + oy) - dy));
      float iz = dz + (lbl_8055E460 * ((dz + (*((float *) (s + 0x14)))) - dz));
      float dv;
      *((float *) (w + 0x00)) = ix;
      *((float *) (w + 0x04)) = iy;
      *((float *) (w + 0x08)) = iz;
      dv = iy - (*((float *) (s + 0x40)));
      if (maxy <= dv)
      {
        maxy = dv;
      }
      else
      {
      }
      *((float *) (w + 0x0C)) = *((float *) (s + 0x4C));
      *((float *) (w + 0x10)) = *((float *) (s + 0x50));
      *((float *) (w + 0x14)) = *((float *) (s + 0x54));
      *((float *) (w + 0x18)) = *((float *) (s + 0x58));
      *((float *) (w + 0x1C)) = *((float *) (s + 0x5C));
      *((float *) (w + 0x20)) = *((float *) (s + 0x60));
      *((float *) (w + 0x24)) = *((float *) (s + 0x0C));
      *((float *) (w + 0x28)) = *((float *) (s + 0x14));
      *((float *) (w + 0x2C)) = *((float *) (s + 0x18));
      *((float *) (w + 0x30)) = *((float *) (s + 0x00));
      f1 = lbl_8055E460;
      *((float *) (w + 0x34)) = (*((float *) (s + 0x08))) + (f3 * ((*((float *) (s + 0x00))) * (f1 - f5)));
      *((float *) (w + 0x38)) = *((float *) (s + 0x68));
      *((float *) (w + 0x3C)) = *((float *) (s + 0x44));
      *((float *) (w + 0x40)) = *((float *) (s + 0x48));
      *((float *) (w + 0x44)) = *((float *) (s + 0x10));
      *((float *) (w + 0x48)) = zero;
      *((float *) (w + 0x54)) = zero;
      *((float *) (w + 0x50)) = zero;
      *((float *) (w + 0x4C)) = zero;
      *((float *) (w + 0x58)) = zero;
      *((float *) (w + 0x5C)) = zero;
      *((int *) (w + 0x60)) = *((int *) (s + 0x70));
      *((unsigned char *) (w + 0x64)) = *((unsigned char *) (s + 0x20));
      *((int *) (w + 0x68)) = *((int *) (s + 0x64));
      s += 0x74;
      w += 0x6C;
    }

    obj = *((void **) (a0 + 0x270));
    *((float *) (dst + 0x2C8)) = *((float *) (((unsigned char *) ((void *(*)(void *)) (*((void ***) ((char *) obj)))[6])(obj)) + 0x48));
    *((float *) (dst + 0x2CC)) = *((float *) (a0 + 0x26CC));
    *((float *) (dst + 0x2D0)) = *((float *) (a0 + 0x5E4));
    *((int *) (dst + 0x2D8)) = *((int *) (a0 + 0x26D4));
    fn_8018DA5C(arg0, dst);
    if (maxy > lbl_80561CCC)
    {
      *((float *) (dst + 0x24)) += (*((float *) (dst + 0x0C))) * maxy;
      *((float *) (dst + 0x28)) += (*((float *) (dst + 0x10))) * maxy;
      *((float *) (dst + 0x2C)) += (*((float *) (dst + 0x14))) * maxy;
      {
        int k;
        float *y4 = (float *) ((dst + 0x7C) + 4);
        for (k = 0; k < 4; k++)
        {
          float ny = y4[k * 0x1B] - maxy;
          if (ny <= lbl_80561EF8)
          {
            ny = lbl_80561EF8;
          }
          else
          {
          }
          y4[k * 0x1B] = ny;
        }

      }
      {
        int j;
        int n = *((int *) (dst + 0xA78));
        unsigned char *p = dst + 0xA7C;
        for (j = 0; 0 < n; j++)
        {
          *((float *) (p + 0x24)) += (*((float *) (dst + 0x0C))) * maxy;
          *((float *) (p + 0x28)) += (*((float *) (dst + 0x10))) * maxy;
          *((float *) (p + 0x2C)) += (*((float *) (dst + 0x14))) * maxy;
          p += 0x34;
        }

      }
    }
  }
  if ((*((int *) (a0 + 0x26C0))) != 0)
  {
    fn_8018A9F0(arg0, dst);
  }
  else
  {
    *((int *) (dst + 0xFA4)) = 0;
  }
}

extern double fabs(double);
extern float lbl_80561E00, lbl_80561EFC, lbl_80561DC0, lbl_80561D40, lbl_80561F00, lbl_80561F04, lbl_80561F08;
extern void fn_8018E3EC(void *, float *, float *, int, int, int, void *, int);
#pragma push
#pragma processor 750
extern double __fabs(double);
void fn_8018956C(void *arg0, float *arg1, float *arg2, int mode, void *obj, int arg5) {
#pragma use_lmw_stmw off
    float *o = (float *)arg0;
    char *ob = (char *)obj;
    float mag, f28, f30, scale;
    int flag, r30;
    float dir[3];
    float d[3];
    int dir2[3];
    float dd[3];
    int v[3];
    V3 m[3];
    float pos[3];
    V3 *msrc;
    int *src = (int *)arg1;

    fn_80189C64(arg0);
    mag = PSVECMag(arg1);
    flag = 0;
    if (obj != 0 && mode == 0x6d) {
        flag = 1;
    }
    f30 = lbl_80561CD0;
    r30 = -1;
    if (mode == 0x6d && obj != 0) {
        int t = *(int *)(ob + 0x10);
        if (t == 0x43415220 || t == 0x50434152 || t == 0x41434152 || t == 0x4e434152 || t == 0x54524c52) {
            float b, diff;
            int s0, s1, s2;
            r30 = *(int *)(ob + 0x1ec);
            s0 = src[0]; s1 = src[1]; s2 = src[2];
            v[0] = s0; v[1] = s1; v[2] = s2;
            if (mag > lbl_80561D00) {
                PSVECNormalize(v, v);
            }
            f28 = (float)__fabs(PSVECDotProduct(v, o + 70));
            b = (float)__fabs(PSVECDotProduct(v, ob + 0x118));
            diff = b - f28;
            if (diff > lbl_80561E00 && b > lbl_80561CF0 * f28) {
                f28 = f28 > lbl_80561DC0 ? f28 : lbl_80561DC0;
                f30 = b / f28;
                f30 = f30 < lbl_80561CF8 ? f30 : lbl_80561CF8;
            } else if (diff < lbl_80561EFC && f28 > lbl_80561CF0 * b) {
                f28 = f28 > lbl_80561DC0 ? f28 : lbl_80561DC0;
                f30 = b / f28;
                f30 = f30 > lbl_80561D40 ? f30 : lbl_80561D40;
                {
                    float x = arg2[0] - o[37];
                    float y = arg2[1] - o[38];
                    float z = arg2[2] - o[39];
                    dd[2] = z * o[36] + (x * o[34] + y * o[35]);
                    dd[0] = z * o[30] + (x * o[28] + y * o[29]);
                    dd[1] = z * o[33] + (x * o[31] + y * o[32]);
                }
                if (dd[2] < lbl_80561F00 && PSVECDotProduct(arg1, o + 34) > lbl_80561CAC) {
                    f30 = lbl_80561CAC;
                }
            }
        }
    } else if (mode == 0x70 && obj != 0) {
        int t = *(int *)(ob + 0x10);
        if (t == 0x43415220 || t == 0x50434152 || t == 0x41434152 || t == 0x4e434152) {
            r30 = *(int *)(ob + 0x1ec);
        }
    }
    {
        int s0 = src[0], s1 = src[1], s2 = src[2];
        dir2[0] = s0; dir2[1] = s1; dir2[2] = s2;
    }
    f28 = o[381];
    if (flag != 0) {
        f28 = f28 * f30;
    } else if (mode != 0x70) {
        f28 = f28 * (lbl_80561D08 * o[198]);
    } else {
        f28 = f28 * lbl_80561F04;
    }
    if (!(*(int *)((char *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x4000)) {
        f28 = f28 * lbl_80561D34;
    }
    ((float *)dir2)[0] = ((float *)dir2)[0] * f28;
    ((float *)dir2)[1] = ((float *)dir2)[1] * f28;
    ((float *)dir2)[2] = ((float *)dir2)[2] * f28;
    if (mag * f28 > lbl_80561F08) {
        msrc = (V3 *)(o + 15);
        m[0] = msrc[0]; m[1] = msrc[1]; m[2] = msrc[2];
        MultVecSR_inl(o + 15, o + 12, pos);
        pos[0] = pos[0] + o[24];
        pos[1] = pos[1] + o[25];
        pos[2] = pos[2] + o[26];
        {
            float t[3];
            t[0] = arg2[0] - pos[0];
            t[1] = arg2[1] - pos[1];
            t[2] = arg2[2] - pos[2];
            MultVecT_inl((float *)m, t, d);
        }
        MultVecT_inl((float *)m, (float *)dir2, dir);
        fn_8018E3EC(arg0, dir, d, 0, r30, mode, obj, arg5);
    }
}

#pragma cplusplus on
/* The truck's per-car race-progress entry: the 0x80-byte block
 * lbl_8055E684 + carIndex * 0x80 that the truck keeps at +0x270.  Its slot 0x10
 * hands back the progress record kept inline in the entry (entry + 4); that
 * record's +0x24 is the car's state: 0 racing, 1 just reset, 3 every checkpoint
 * done. */
struct CarProgress {
    virtual void v0() {}
    virtual void v1() {}
    virtual void *getRecord() { return 0; }
};
/* The arena-event master fn_801B83A0 returns (lbl_8055E744).  MWCC keeps two
 * reserved words above the first declared virtual, so slotCC is the vtable slot
 * at 0xCC, the master's answer about the car of a given element index. */
struct ArenaMaster {
    virtual void c0() {} virtual void c1() {} virtual void c2() {} virtual void c3() {}
    virtual void c4() {} virtual void c5() {} virtual void c6() {} virtual void c7() {}
    virtual void c8() {} virtual void c9() {} virtual void c10() {} virtual void c11() {}
    virtual void c12() {} virtual void c13() {} virtual void c14() {} virtual void c15() {}
    virtual void c16() {} virtual void c17() {} virtual void c18() {} virtual void c19() {}
    virtual void c20() {} virtual void c21() {} virtual void c22() {} virtual void c23() {}
    virtual void c24() {} virtual void c25() {} virtual void c26() {} virtual void c27() {}
    virtual void c28() {} virtual void c29() {} virtual void c30() {} virtual void c31() {}
    virtual void c32() {} virtual void c33() {} virtual void c34() {} virtual void c35() {}
    virtual void c36() {} virtual void c37() {} virtual void c38() {} virtual void c39() {}
    virtual void c40() {} virtual void c41() {} virtual void c42() {} virtual void c43() {}
    virtual void c44() {} virtual void c45() {} virtual void c46() {} virtual void c47() {}
    virtual void c48() {}
    virtual int slotCC(int) { return 0; }
};
#define CAR_TAG_TRAILER 0x54524C52 /* 'TRLR': the car-type FourCC at +0x10 */
extern "C" int fn_80189BDC(void *truck) {
    /* Whether the arena-event master still has something to do for this truck: a
     * car that is not a trailer and whose race progress is already reset (state 1)
     * or holds every checkpoint (state 3) reports 0; anything else is the master's
     * answer for the truck's element index. */
    if ((unsigned int)*(int *)((char *)truck + 0x10) != CAR_TAG_TRAILER) {
        void *progress = *(void **)((char *)truck + 0x270);
        void *record = ((CarProgress *)progress)->getRecord();
        if (record != 0) {
            int state = *(int *)((char *)record + 0x24);
            if (state == 1 || state == 3) {
                return 0;
            }
        }
    }
    void *amaster = (void *)fn_801B83A0();
    return ((ArenaMaster *)amaster)->slotCC(*(int *)((char *)truck + 0x1EC));
}
#undef CAR_TAG_TRAILER
#pragma cplusplus reset

#pragma pop
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern int lbl_8055E918;
extern f32 lbl_80561CD0;
int fn_801C2BF8(int, f32 *);
void **fn_801B83A0(void);
int fn_801BF1B8(int, int);
extern f32 lbl_80561CAC;
#pragma dont_inline fn_80189C64
/* Clears the pending flag and notifies its handler, then resets the object's timer. */
void fn_80189C64(void *object) {
#define sZero lbl_80561CAC
    if (*(unsigned char *)((char *)object + 0x26AC) != 0) {
        *(unsigned char *)((char *)object + 0x26AC) = 0;
        fn_801BF1B8(*(int *)((char *)object + 0x1EC), *(unsigned char *)((char *)object + 0x26AC));
    }
    *(float *)((char *)object + 0x26A8) = sZero;
#undef sZero
}

#pragma opt_propagation off
#pragma dont_inline on
void fn_80189CB4(void *arg0, void *arg1) {
    volatile float scale[3];
    volatile float out[3];
    volatile int matrix[12];
    float temp_f1, temp_f6, temp_f7;
    int count, index;
    register int i;
    int word1, word0, word2, word3, word4, word5;
    int word6, word7, word8, word9;
    char *cursor;
    {
        float zero = lbl_80561CAC;
        *(float *)((char *)arg0 + 0x130) = zero;
        *(float *)((char *)arg0 + 0x134) = zero;
        *(float *)((char *)arg0 + 0x138) = zero;
        *(float *)((char *)arg0 + 0x13C) = zero;
        *(float *)((char *)arg0 + 0x140) = zero;
        *(float *)((char *)arg0 + 0x144) = zero;
    }
    fn_8017B6A8(arg0);
    fn_80189C64(arg0);
    word0 = *(int *)(((char *)arg1) + 0x00);
    word1 = *(int *)(((char *)arg1) + 0x04);
    word2 = *(int *)(((char *)arg1) + 0x08);
    word3 = *(int *)(((char *)arg1) + 0x0C);
    word4 = *(int *)(((char *)arg1) + 0x10);
    word5 = *(int *)(((char *)arg1) + 0x14);
    word6 = *(int *)(((char *)arg1) + 0x18);
    word7 = *(int *)(((char *)arg1) + 0x1C);
    word8 = *(int *)(((char *)arg1) + 0x20);
    word9 = *(int *)(((char *)arg1) + 0x24);
    matrix[0] = word0;
    matrix[1] = word1;
    matrix[2] = word2;
    matrix[3] = word3;
    matrix[4] = word4;
    matrix[5] = word5;
    matrix[6] = word6;
    matrix[7] = word7;
    matrix[8] = word8;
    matrix[9] = word9;
    matrix[10] = *(int *)(((char *)arg1) + 0x28);
    matrix[11] = *(int *)(((char *)arg1) + 0x2C);
    temp_f1 = *(float *)((char *)arg0 + 0x30) * lbl_80561DE4;
    scale[0] = temp_f1;
    temp_f6 = *(float *)((char *)arg0 + 0x34) * lbl_80561DE4;
    scale[1] = temp_f6;
    temp_f7 = *(float *)((char *)arg0 + 0x38) * lbl_80561DE4;
    scale[2] = temp_f7;
    {
        volatile float *pOut = out;
        volatile float *pScale = scale;
        if (pOut == pScale) {
            float m0 = ((volatile float *)matrix)[0];
            float m3 = ((volatile float *)matrix)[3];
            float m6 = ((volatile float *)matrix)[6];
            float m1 = ((volatile float *)matrix)[1];
            float m4 = ((volatile float *)matrix)[4];
            float m7 = ((volatile float *)matrix)[7];
            float m2 = ((volatile float *)matrix)[2];
            float m5 = ((volatile float *)matrix)[5];
            float m8 = ((volatile float *)matrix)[8];
            pOut[0] = temp_f7 * m6 + (temp_f1 * m0 + temp_f6 * m3);
            pOut[1] = temp_f7 * m7 + (temp_f1 * m1 + temp_f6 * m4);
            pOut[2] = temp_f7 * m8 + (temp_f1 * m2 + temp_f6 * m5);
        } else {
            pOut[0] = temp_f7 * ((volatile float *)matrix)[6] + (temp_f1 * ((volatile float *)matrix)[0] + temp_f6 * ((volatile float *)matrix)[3]);
            pOut[1] = temp_f7 * ((volatile float *)matrix)[7] + (temp_f1 * ((volatile float *)matrix)[1] + temp_f6 * ((volatile float *)matrix)[4]);
            pOut[2] = temp_f7 * ((volatile float *)matrix)[8] + (temp_f1 * ((volatile float *)matrix)[2] + temp_f6 * ((volatile float *)matrix)[5]);
        }
    }
    {
        float f3 = ((volatile float *)matrix)[10];
        float f4 = ((volatile float *)matrix)[9] + out[0];
        float f1 = ((volatile float *)matrix)[11];
        float f2 = f3 + out[1];
        ((volatile float *)matrix)[9] = f4;
        ((volatile float *)matrix)[10] = f2;
        ((volatile float *)matrix)[11] = f1 + out[2];
    }
    *(int *)((char *)arg0 + 0x3C) = matrix[0];
    *(int *)((char *)arg0 + 0x40) = matrix[1];
    *(int *)((char *)arg0 + 0x44) = matrix[2];
    *(int *)((char *)arg0 + 0x48) = matrix[3];
    *(int *)((char *)arg0 + 0x4C) = matrix[4];
    *(int *)((char *)arg0 + 0x50) = matrix[5];
    *(int *)((char *)arg0 + 0x54) = matrix[6];
    *(int *)((char *)arg0 + 0x58) = matrix[7];
    *(int *)((char *)arg0 + 0x5C) = matrix[8];
    *(int *)((char *)arg0 + 0x60) = matrix[9];
    *(int *)((char *)arg0 + 0x64) = matrix[10];
    *(int *)((char *)arg0 + 0x68) = matrix[11];
    ((void (*)(void *))fn_8017A580)(arg0);
    *(float *)((char *)arg0 + 0x2A4) = *(float *)((char *)((char *)arg1) + 0x30);
    *(float *)((char *)arg0 + 0x2A8) = *(float *)((char *)((char *)arg1) + 0x34);
    *(float *)((char *)arg0 + 0x2AC) = *(float *)((char *)((char *)arg1) + 0x38);
    *(float *)((char *)arg0 + 0x118) = *(float *)((char *)((char *)arg1) + 0x30);
    *(float *)((char *)arg0 + 0x11C) = *(float *)((char *)((char *)arg1) + 0x34);
    *(float *)((char *)arg0 + 0x120) = *(float *)((char *)((char *)arg1) + 0x38);
    {
        float zero = lbl_80561CAC;
        *(float *)((char *)arg0 + 0x124) = zero;
        *(float *)((char *)arg0 + 0x128) = zero;
        *(float *)((char *)arg0 + 0x12C) = zero;
    }
    temp_f1 = PSVECDotProduct((char *)arg0 + 0x118, (char *)arg0 + 0x54);
    *(float *)((char *)arg0 + 0x25CC) = temp_f1;
    *(float *)((char *)arg0 + 0x25D8) = temp_f1;
    temp_f1 = PSVECMag((void *)((unsigned int)arg0 + 0x118));
    *(float *)((char *)arg0 + 0x25D4) = temp_f1;
    *(float *)((char *)arg0 + 0x261C) = temp_f1;
    {
        float zero = lbl_80561CAC;
        *(float *)((char *)arg0 + 0x16C) = zero;
        *(float *)((char *)arg0 + 0x170) = zero;
        *(float *)((char *)arg0 + 0x174) = zero;
        *(float *)((char *)arg0 + 0x26B4) = zero;
        *(float *)((char *)arg0 + 0x26B8) = zero;
        *(float *)((char *)arg0 + 0x26BC) = zero;
    }
    *(short *)((char *)arg0 + 0x6C) = *(short *)((char *)((char *)arg1) + 0x40);
    fn_801E9DD0((char *)arg0 + 0x6C, ((volatile float *)matrix)[9], ((volatile float *)matrix)[11]);
    index = *(int *)((char *)arg0 + 0x1EC);
    fn_801D1810(lbl_8055E918 + index * 0x9C, index);
    fn_801BE400(*(int *)((char *)arg0 + 0x1EC), (float *)matrix, *(float *)((char *)arg0 + 0x25CC));
    fn_801B30C0(*(int *)((char *)arg0 + 0x1EC), 0, *(int *)((char *)((char *)arg1) + 0x3C));
    cursor = (char *)arg0;
    i = 0;
    count = *(int *)((char *)arg0 + 0x24);
    while (i < count) {
        void *item;
        if (i < 0 || i >= count) item = 0;
        else item = *(void **)(cursor + 0x14);
        ((void (*)(void *))(*(void **)((char *)(*(void **)item) + 0x48)))(item);
        cursor += 4;
        i += 1;
        count = *(int *)((char *)arg0 + 0x24);
    }
    {
        float zero = lbl_80561CAC;
        *(float *)((char *)arg0 + 0x23AC) = zero;
        *(float *)((char *)arg0 + 0x2414) = zero;
        *(float *)((char *)arg0 + 0x2420) = zero;
        *(float *)((char *)arg0 + 0x2488) = zero;
        *(float *)((char *)arg0 + 0x2494) = zero;
        *(float *)((char *)arg0 + 0x24FC) = zero;
        *(float *)((char *)arg0 + 0x2508) = zero;
        *(float *)((char *)arg0 + 0x2570) = zero;
    }
    ((void (*)(void *))fn_8018A750)(arg0);
    index = *(int *)((char *)arg0 + 0x26D4);
    *(int *)((char *)arg0 + 0x2638) = 0;
    {
        float zero = lbl_80561CAC;
        *(float *)((char *)arg0 + 0x2628) = zero;
        *(float *)((char *)arg0 + 0x262C) = zero;
    }
    *(signed char *)((char *)arg0 + 0x2640) = 0;
    *(int *)((char *)arg0 + 0x26D4) = index + 1;
    fn_8026A394(arg0, index, 0);
}
#pragma dont_inline reset
#pragma opt_propagation reset
/* Empty stub (no operation). */
void fn_8018A088(void) {

}

/* Reset this object's float field at +0x26D8 to the shared zero value held in lbl_8055E3C8. */
void fn_8018A08C(void *object) {
    *(float *)((unsigned char *)object + 0x26d8) = lbl_8055E3C8;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
/* Mark this object dirty and update its scaled value at +0x258C by blending a base factor with the given interpolation factor. */
void fn_8018A098(void *object, float blendFactor) {
#define interpolatedValue lbl_80434930
    float baseValue;
    *((unsigned char *)object + 0x259d) = 1;
    baseValue = *(float *)((unsigned char *)object + 0x2cc) * fn_80181AEC();
    *(float *)((unsigned char *)object + 0x258c) =
        *(float *)((unsigned char *)object + 0x3a0) *
        (baseValue + blendFactor * (interpolatedValue[0] - baseValue));
#undef interpolatedValue
}
#pragma dont_inline reset
#pragma pop
int fn_8018A100(void *truck) {
    /* Return whether this truck's +0x2618 timer has exceeded the tuning threshold at lbl_80434930[1]. */
    return *(float *)((unsigned char *)truck + 0x2618) > lbl_80434930[1];
}

#pragma cplusplus on
/* fn_80155700 calls this on a truck just after queueing the hit sound for it:
   unless that truck's car slot has already finished the race -- fn_801B2F2C reads
   the "finished" byte at 0x79 of the slot's 0x80-byte record in the slot table
   lbl_8055E684, and the truck keeps its slot index at +0x1EC -- it clears the
   truck's +0x25BC timer and raises the flag of the sound set the truck owns at
   +0x2584.  That call is vtable slot 0x38 of that class (CarSound_RequestInvulnerable, which sets
   CarSound+0x72); its per-frame update uses the flag to start or stop the
   "invulnerable.sfx" sound (fn_8020E598). */
extern "C" void fn_8018A120(void *truck) {
    if (fn_801B2F2C(*(int *)((u8 *)truck + 0x1EC)) == 0) {
        /* The truck's CarSound (src/game/waterbounce.c).  MWCC keeps two reserved
           slots above the first declared virtual, so the flag setter is the 13th
           virtual declared here. */
        struct CarSound {
            virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
            virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
            virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
            virtual int raiseSoundFlag();
        };
        CarSound *sounds = *(CarSound **)((u8 *)truck + 0x2584);
        *(float *)((u8 *)truck + 0x25BC) = lbl_8055E4E0;
        sounds->raiseSoundFlag();
    }
}
#pragma cplusplus off
/* Reset the truck's countdown/timer field at offset 0x2650 to 4.0. */
void fn_8018A174(void *truck) {
    *(float *)((unsigned char *)truck + 0x2650) = lbl_80561D2C;
}

#pragma cplusplus on
extern "C" void fn_8018A180(void *arg0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11) {
    class Driver {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10();
        virtual int slot34();
        virtual int slot38();
    };
    int value;
    float z;
    float y;
    float x;
    float inv;
    void *p;
#pragma unused(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)
    value = *(int *)((char *)arg0 + 0x328);
    if (value != 0) {
        fn_80279B28(value, (void *)((unsigned int)arg0 + 0x1E44));
        fn_8018F2C0(arg0, (char *)arg0 + 0x1E44);
        if (*(int *)((char *)arg0 + 0x20DC) < 9) {
            if (((Driver *)*(void **)((char *)arg0 + 0x270))->slot38() != 0) {
                fn_802E30C8(lbl_803325E8, *(int *)((char *)arg0 + 0x1EC));
                ((Driver *)*(void **)((char *)arg0 + 0x270))->slot34();
                fn_8018AF04(arg0);
            }
        }
    }
    x = *(float *)((char *)arg0 + 0x458);
    y = *(float *)((char *)arg0 + 0x45C);
    z = *(float *)((char *)arg0 + 0x460);
    *(float *)((char *)arg0 + 0x30) = x;
    *(float *)((char *)arg0 + 0x34) = y;
    *(float *)((char *)arg0 + 0x38) = z;
    fn_8017A57C(arg0);
    fn_8017B2D0(arg0, *(float *)((char *)arg0 + 0x32C) / lbl_80561D54,
        *(float *)((char *)arg0 + 0x330) / lbl_80561D58,
        *(float *)((char *)arg0 + 0x334) / lbl_80561D58,
        *(float *)((char *)arg0 + 0x338) / lbl_80561D58);
    x = *(float *)((char *)arg0 + 0x32C);
    p = (void *)((unsigned int)arg0 + 0x32C);
    inv = lbl_80561CD0;
    *(volatile float *)((char *)arg0 + 0xD4) = x;
    *(volatile float *)((char *)arg0 + 0xE4) = inv / x;
    fn_801BDA74(*(int *)((char *)arg0 + 0x1EC), p, x);
    fn_801D11D8((char *)lbl_8055E908 + *(int *)((char *)arg0 + 0x1EC) * 0x34, *(int *)((char *)arg0 + 0x1EC));
    fn_801D1540((char *)lbl_8055E918 + *(int *)((char *)arg0 + 0x1EC) * 0x9C, *(int *)((char *)arg0 + 0x1EC));
}
#pragma cplusplus reset
/* Empty stub (no operation). */
void fn_8018A2BC(void) {

}

/* Names and units of the car's tunable physics parameters.
 * The names are short strings inside the .data string blob that starts at
 * lbl_803322B0 (the ones used below live at +0x350..+0x43C); the units are
 * their own strings in .sdata.  Kept as macro aliases because the original
 * code refers to the game's labels directly. */
#define UNIT_M       ((const char *)&lbl_8055A3F8)   /* " m" */
#define UNIT_KG      ((const char *)&lbl_8055A3FC)   /* " kg" */
#define UNIT_KG_M2   ((const char *)&lbl_8055A400)   /* " kg m2" */
#define UNIT_N_M     ((const char *)&lbl_8055A408)   /* " N/m" */
#define UNIT_N_S_M   ((const char *)&lbl_8055A410)   /* " N-s/m" */
#define NAME_MASS    ((const char *)&lbl_8055A418)   /* "Mass" */
#define UNIT_NONE    ((const char *)&lbl_8055A420)   /* "" (dimensionless) */
#define UNIT_M_S     ((const char *)&lbl_8055A424)   /* " m/s" */
#define UNIT_G       ((const char *)&lbl_8055A42C)   /* " G" */
/* .sdata2 float constants used as the sliders' minimum / maximum / step. */
#define F_NEG_1      lbl_80561DE4   /* -1.0f */
#define F_0          lbl_80561CAC   /* 0.0f */
#define F_0_01       lbl_80561CCC   /* 0.01f */
#define F_0_05       lbl_80561D0C   /* 0.05f */
#define F_0_1        lbl_80561D00   /* 0.1f */
#define F_0_5        lbl_80561CDC   /* 0.5f */
#define F_1          lbl_80561CD0   /* 1.0f */
#define F_3          lbl_80561D44   /* 3.0f */
#define F_5          lbl_80561CF8   /* 5.0f */
#define F_6          lbl_80561CEC   /* 6.0f */
#define F_10         lbl_80561D34   /* 10.0f */
#define F_50         lbl_80561F10   /* 50.0f */
#define F_100        lbl_80561CE4   /* 100.0f */
#define F_200        lbl_80561D28   /* 200.0f */
#define F_500        lbl_80561F14   /* 500.0f */
#define F_1000       lbl_80561EBC   /* 1000.0f */
#define F_5000       lbl_80561F0C   /* 5000.0f */
#define F_10000      lbl_80561F18   /* 10000.0f */
#define F_50000      lbl_80561D68   /* 50000.0f */

extern char lbl_803322B0[];
extern int lbl_8055A3F8, lbl_8055A3FC, lbl_8055A400, lbl_8055A408, lbl_8055A410;
extern int lbl_8055A418, lbl_8055A420, lbl_8055A424, lbl_8055A42C;
extern float lbl_80561CAC, lbl_80561CCC, lbl_80561CD0, lbl_80561CDC, lbl_80561CE4;
extern float lbl_80561CEC, lbl_80561CF8, lbl_80561D00, lbl_80561D0C, lbl_80561D28;
extern float lbl_80561D34, lbl_80561D44, lbl_80561D68, lbl_80561DE4, lbl_80561EBC;
extern float lbl_80561F0C, lbl_80561F10, lbl_80561F14, lbl_80561F18;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma cplusplus on
/* Offers every tunable physics parameter of the car `car` to the tuning
 * parameter collector `collector`, which records the value's address with its
 * display name, unit and its slider's minimum, maximum and step (see
 * fn_801DDED0).  fn_801DDF0C calls this whenever the selected car changes and
 * then snaps each collected value to a multiple of its step.
 * The names come from the string blob at lbl_803322B0; the floats at
 * +0x32C..+0x440 of the car are the ones being tuned. */
extern "C" void CarPhysics_registerTunables(void *car, void **collector) {
    /* The collector's second virtual method registers one tunable parameter. */
    struct ParamCollector {
        virtual void add_param(const char *name, void *value, const char *unit,
                               float min, float max, float step);
    };
    register char *base = (char *)car;
    register char *names = lbl_803322B0;
    register char *params = base + 0x32C;  /* the car's physics parameter block */
    register const char *unit_m = UNIT_M;
    register const char *unit_kg = UNIT_KG;
    register const char *unit_kg_m2 = UNIT_KG_M2;
    register const char *unit_n_m = UNIT_N_M;
    register const char *unit_n_s_m = UNIT_N_S_M;
    register const char *name_mass = NAME_MASS;
    register ParamCollector *sink = (ParamCollector *)collector;

    sink->add_param(name_mass, params, unit_kg, F_100, F_5000, F_50);
    sink->add_param(names + 0x350, params + 0x8, unit_kg_m2, F_100, F_50000, F_50);      /* Yaw Moment */
    sink->add_param(names + 0x35C, params + 0x4, unit_kg_m2, F_100, F_50000, F_50);      /* Pitch Moment */
    sink->add_param(names + 0x36C, params + 0xC, unit_kg_m2, F_100, F_50000, F_50);      /* Roll Moment */
    sink->add_param(names + 0x378, base + 0x2DC, UNIT_NONE, F_0_1, F_3, F_0_05);         /* Engine Power */
    sink->add_param(names + 0x388, params + 0x30, UNIT_NONE, F_0_5, F_6, F_0_05);        /* Final Drive */
    sink->add_param(names + 0x394, base + 0x5A8, UNIT_M_S, F_10, F_200, F_1);            /* Speed Limiter */
    sink->add_param(names + 0x3A4, params + 0x18, unit_m, F_0_1, F_5, F_0_01);           /* Wheelbase */
    sink->add_param(names + 0x3B0, params + 0x10, unit_m, F_0_1, F_5, F_0_01);           /* Front Track */
    sink->add_param(names + 0x3BC, params + 0x14, unit_m, F_0_1, F_5, F_0_01);           /* Rear Track */
    sink->add_param(names + 0x3C8, params + 0x20, unit_m, F_NEG_1, F_1, F_0_01);         /* CG Height */
    sink->add_param(names + 0x3D4, params + 0x80, unit_m, F_0, F_1, F_0_01);             /* Front Height */
    sink->add_param(names + 0x3E4, params + 0xC8, unit_m, F_0, F_1, F_0_01);             /* Rear Height */
    sink->add_param(names + 0x3F0, params + 0x84, unit_n_m, F_1000, F_50000, F_500);     /* Front Springs */
    sink->add_param(names + 0x400, params + 0xCC, unit_n_m, F_1000, F_50000, F_500);     /* Rear Springs */
    sink->add_param(names + 0x410, params + 0x8C, unit_n_s_m, F_500, F_10000, F_50);     /* Front Damping */
    sink->add_param(names + 0x420, params + 0xD4, unit_n_s_m, F_500, F_10000, F_50);     /* Rear Damping */
    sink->add_param(names + 0x430, params + 0x110, UNIT_G, F_0_1, F_3, F_0_1);           /* Tire Grip */
    sink->add_param(names + 0x43C, params + 0x114, UNIT_NONE, F_0_1, F_6, F_0_1);        /* Tire Slip */
}
#pragma cplusplus reset
#pragma opt_propagation reset
#pragma scheduling on

void fn_8018A654(void *arg0, void *arg1) {
    void *result;
    int count;

    if (*(volatile signed char *)((char *)arg1 + 0xec) != 0) {
        result = fn_801D2008((char *)arg1 + 0xec);
        *(void **)((char *)arg0 + 0x26c0) = result;
        if (*(int *)((char *)result + 0x10) > 0) {
            *(int *)((char *)arg0 + 0x26c4) = fn_801C1C1C();
        } else {
            *(int *)((char *)arg0 + 0x26c4) = 0;
        }
        count = *(int *)((char *)*(void **)((char *)arg0 + 0x26c0) + 0xc8);
        if (count > 0) {
            *(int *)((char *)arg0 + 0x26c8) =
                ((int (*)(int, int, int))fn_801C1BA4)(count * 2, count, count);
        } else {
            *(int *)((char *)arg0 + 0x26c8) = 0;
        }
    } else {
        *(int *)((char *)arg0 + 0x26c0) = 0;
        *(int *)((char *)arg0 + 0x26c4) = 0;
        *(int *)((char *)arg0 + 0x26c8) = 0;
    }
}

/* Release texture-pattern/animation resources owned by this object, if present. */
void fn_8018A6F4(void *object) {
    int texPattern = *(int *)((unsigned char *)object + 0x26c8);
    if (texPattern != 0) fn_801C1C7C(texPattern);
    if (*(int *)((unsigned char *)object + 0x26c4) != 0) fn_801C1C7C(*(int *)((unsigned char *)object + 0x26c4));
    if (*(int *)((unsigned char *)object + 0x26c0) != 0) fn_801D21B4(*(int *)((unsigned char *)object + 0x26c0));
}

extern void fn_801C1CBC(void *, int, void *, int, void *, int, void *);
void fn_8018A750(void *arg0, int arg_sp0)
{
  struct
  {
    int entries[4][3];
    float vectors[4][4];
    unsigned int records[4][10];
  } work;
  char *base = (char *) arg0;
  int handle = *((int *) (base + 0x26C4));
  int twice;
  int count;
  if (handle != 0)
  {
    fn_801C2170(handle, *((void **) (base + 0x26C0)), base + 0x70);
  }
  if ((*((volatile int *) (base + 0x26C8))) != 0)
  {
    count = *((int *) (((char *) (*((void * volatile *) (base + 0x26C0)))) + 0xC8));
    twice = count * 2;
    if (count > 0)
    {
      int i = 0;
      int slot = 0;
      int k = 0;
      unsigned int *record = work.records[0];
      float *vec = work.vectors[0];
      int *entry = work.entries[0];
      float one = lbl_80561CD0;
      float half = lbl_80561CDC;
      for (i = 0; i < (*((int *) (((char *) (*((void * volatile *) (base + 0x26C0)))) + 0xC8))); i += 1)
      {
        float *p = (float *) record;
        p[0] = *((float *) (base + 0x94));
        p[1] = *((float *) (base + 0x98));
        p[2] = *((float *) (base + 0x9C));
        p[3] = one;
        p[4] = half;
        record[5] = record[0];
        record[6] = record[1];
        record[7] = record[2];
        p[8] = one;
        p[9] = half;
        ((int *) vec)[0] = slot;
        ((int *) vec)[1] = slot + 1;
        vec[2] = lbl_80561CAC;
        vec[3] = one - (*((float *) (((char *) (*((void * volatile *) (base + 0x26C0))) + 0xA8) + k)));
        entry[0] = slot;
        entry[1] = (int) (base + 0x70);
        entry[2] = 0;
        record += 10;
        vec += 4;
        entry += 3;
        slot += 2;
        k += 8;
      }
    }
    fn_801C1CBC((void *) (*((int *) (base + 0x26C8))), twice, work.records, count, work.vectors, count, work.entries);
  }
}

#pragma push
#pragma processor 750
#pragma scheduling on
/* Apply time-varying offsets to an object's two animation resources (handles at
 * +0x26C4/+0x26C8): the first gets a sawtooth wave derived from three fmod phases of
 * the frame time, the second gets the object's position scaled by a fixed constant. */
void fn_8018A8A8(void *object) {
    float fallVector[3];
    float upVector[3];
    float zeroVector[3];
    float waveOffset[3];
    float positionOffset[3];
    float phase;
    float centered;
    float yWave;
    register float time;
    register float zWave;
    fallVector[0] = 0.0f;
    fallVector[1] = -10000.0f;
    fallVector[2] = 0.0f;
    upVector[0] = 0.0f;
    upVector[1] = 1.0f;
    upVector[2] = 0.0f;
    zeroVector[0] = 0.0f;
    zeroVector[1] = 0.0f;
    zeroVector[2] = 0.0f;
    if (*(int *)((char *)object + 0x26C4) != 0) {
        time = lbl_8055E3C8;
        phase = (float)fn_8002EFB4(time, lbl_80561F20);
        centered = phase - lbl_80561D00;
        zWave = lbl_80561F28 * centered;
        phase = (float)fn_8002EFB4(time, lbl_80561F30);
        centered = phase - lbl_80561F3C;
        yWave = lbl_80561F38 * centered;
        phase = (float)fn_8002EFB4(time, lbl_80561F40);
        waveOffset[1] = yWave;
        centered = phase - lbl_80561F4C;
        waveOffset[2] = zWave;
        waveOffset[0] = lbl_80561F48 * centered;
        fn_801C27D8(*(void **)((char *)object + 0x26C4), fallVector, upVector, waveOffset, zeroVector);
    }
    if (*(int *)((char *)object + 0x26C8) != 0) {
        positionOffset[0] = *(float *)((char *)object + 0x118) * lbl_80561F50;
        positionOffset[1] = *(float *)((char *)object + 0x11C) * lbl_80561F50;
        positionOffset[2] = *(float *)((char *)object + 0x120) * lbl_80561F50;
        fn_801C27D8(*(void **)((char *)object + 0x26C8), fallVector, upVector, positionOffset, zeroVector);
    }
}
#pragma pop
extern void fn_801C2BDC(void *, unsigned int *, unsigned int *, unsigned int *);
void fn_8018A9F0(void *arg0, void *arg1) {
    float f[11];
    int sp28, sp24, sp20, sp1C, sp18, sp14;
    void *sp10;
    float spC, sp8;
    float temp_f8_2, temp_f8, temp_f7_2, temp_f7, temp_f6_2, temp_f6, temp_f1;
    int temp_r0, temp_r3, temp_r3_2, var_r3, var_r5, var_r6, var_r6_2, var_r7;
    void *temp_r3_3, *temp_r3_4, *temp_r3_5, *temp_r3_6, *temp_r3_7;
    void *temp_r4, *temp_r4_2, *temp_r4_3, *temp_r4_4, *temp_r5;

    if (*(int *)((char *)arg0 + 0x26C4) != 0) {
        sp28 = 0; sp24 = 0; sp20 = 0;
        fn_801C2BDC(*(void **)((char *)arg0 + 0x26C4), (unsigned int *)&sp20, (unsigned int *)&sp28, (unsigned int *)&sp24);
        var_r6 = 0;
        if (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xA4) > 0) {
            var_r5 = 0;
            while (var_r6 < *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xA4)) {
                temp_r4 = *(void **)((char *)arg0 + 0x26C0);
                temp_r3 = *(int *)((char *)temp_r4 + var_r5 + 0x20);
                var_r5 += 4;
                temp_r3_2 = temp_r3 * 0xC;
                temp_r4_2 = (void *)((char *)sp28 + temp_r3_2);
                temp_f8 = *(float *)temp_r4_2 - *(float *)((char *)arg0 + 0x94);
                temp_r3_3 = (char *)arg1 + ((*(int *)((char *)temp_r4 + 0xA0) + var_r6) * 0xC);
                var_r6 += 1;
                *(float *)((char *)temp_r3_3 + 0xE24) = temp_f8;
                temp_f7 = *(float *)((char *)temp_r4_2 + 4) - *(float *)((char *)arg0 + 0x98);
                *(float *)((char *)temp_r3_3 + 0xE28) = temp_f7;
                temp_f6 = *(float *)((char *)temp_r4_2 + 8) - *(float *)((char *)arg0 + 0x9C);
                *(float *)((char *)temp_r3_3 + 0xE2C) = temp_f6;
                {
                    float c74 = *(float *)((char *)arg0 + 0x74);
                    float c70 = *(float *)((char *)arg0 + 0x70);
                    float c7C = *(float *)((char *)arg0 + 0x7C);
                    float p0 = temp_f7 * c74;
                    float p1 = temp_f8 * c70;
                    float c80 = *(float *)((char *)arg0 + 0x80);
                    float p2 = temp_f8 * c7C;
                    float p3 = temp_f7 * c80;
                    float c78 = *(float *)((char *)arg0 + 0x78);
                    float c8C = *(float *)((char *)arg0 + 0x8C);
                    float p4 = temp_f6 * c78;
                    float c88 = *(float *)((char *)arg0 + 0x88);
                    float p5 = p1 + p0;
                    float c84 = *(float *)((char *)arg0 + 0x84);
                    float p6 = temp_f8 * c88;
                    float p7 = temp_f7 * c8C;
                    float c90 = *(float *)((char *)arg0 + 0x90);
                    float out0 = p4 + p5;
                    float p8 = p2 + p3;
                    float p9 = temp_f6 * c84;
                    float p10 = p6 + p7;
                    float p11 = temp_f6 * c90;
                    *(float *)((char *)temp_r3_3 + 0xE24) = out0;
                    *(float *)((char *)temp_r3_3 + 0xE28) = p9 + p8;
                    *(float *)((char *)temp_r3_3 + 0xE2C) = p11 + p10;
                }
            }
        }
    }

    if (*(int *)((char *)arg0 + 0x26C8) != 0) {
        sp1C = 0; sp18 = 0; sp14 = 0;
        fn_801C2BDC(*(void **)((char *)arg0 + 0x26C8), (unsigned int *)&sp14, (unsigned int *)&sp1C, (unsigned int *)&sp18);
        var_r7 = 0;
        if (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xC8) > 0) {
            var_r3 = 0xC; var_r6_2 = 0;
            while (var_r7 < *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xC8)) {
                temp_r4_3 = (char *)*(void **)((char *)arg0 + 0x26C0) + var_r6_2;
                temp_r0 = *(int *)((char *)temp_r4_3 + 0xAC);
                var_r6_2 += 8;
                temp_f1 = *(float *)((char *)sp1C + var_r3);
                temp_r5 = (char *)sp1C + var_r3;
                var_r3 += 0x18;
                temp_f8_2 = temp_f1 - *(float *)((char *)arg0 + 0x94);
                temp_r4_4 = (char *)arg1 + (temp_r0 * 0xC);
                *(float *)((char *)temp_r4_4 + 0xE24) = temp_f8_2;
                var_r7 += 1;
                temp_f7_2 = *(float *)((char *)temp_r5 + 4) - *(float *)((char *)arg0 + 0x98);
                *(float *)((char *)temp_r4_4 + 0xE28) = temp_f7_2;
                temp_f6_2 = *(float *)((char *)temp_r5 + 8) - *(float *)((char *)arg0 + 0x9C);
                *(float *)((char *)temp_r4_4 + 0xE2C) = temp_f6_2;
                {
                    float c74 = *(float *)((char *)arg0 + 0x74);
                    float c70 = *(float *)((char *)arg0 + 0x70);
                    float c7C = *(float *)((char *)arg0 + 0x7C);
                    float p0 = temp_f7_2 * c74;
                    float p1 = temp_f8_2 * c70;
                    float c80 = *(float *)((char *)arg0 + 0x80);
                    float p2 = temp_f8_2 * c7C;
                    float p3 = temp_f7_2 * c80;
                    float c78 = *(float *)((char *)arg0 + 0x78);
                    float c8C = *(float *)((char *)arg0 + 0x8C);
                    float p4 = temp_f6_2 * c78;
                    float c88 = *(float *)((char *)arg0 + 0x88);
                    float p5 = p1 + p0;
                    float c84 = *(float *)((char *)arg0 + 0x84);
                    float p6 = temp_f8_2 * c88;
                    float p7 = temp_f7_2 * c8C;
                    float c90 = *(float *)((char *)arg0 + 0x90);
                    float out0 = p4 + p5;
                    float p8 = p2 + p3;
                    float p9 = temp_f6_2 * c84;
                    float p10 = p6 + p7;
                    float p11 = temp_f6_2 * c90;
                    *(float *)((char *)temp_r4_4 + 0xE24) = out0;
                    *(float *)((char *)temp_r4_4 + 0xE28) = p9 + p8;
                    *(float *)((char *)temp_r4_4 + 0xE2C) = p11 + p10;
                }
            }
        }
    }

    sp10 = 0;
    fn_801BEB30(*(int *)((char *)arg0 + 0x1EC), (int *)&sp10);
    {
        float zero = lbl_80561CAC;
        *(int*)&f[6] = *(int *)((char *)sp10 + 0x7C);
        sp8 = f[6];
        *(int*)&f[3] = *(int *)((char *)sp10 + 0x70);
        *(int*)&f[4] = *(int *)((char *)sp10 + 0x74);
        *(int*)&f[5] = *(int *)((char *)sp10 + 0x78);
        spC = sp8;
        f[7] = f[3]; f[8] = f[4]; f[9] = f[5]; f[10] = spC;
        f[0] = f[3];
        temp_r3_4 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xCC) * 0xC);
        f[1] = f[4];
        *(float *)((char *)temp_r3_4 + 0xE24) = zero;
        *(float *)((char *)temp_r3_4 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x80) + f[3]);
        *(float *)((char *)temp_r3_4 + 0xE2C) = zero;
        f[2] = f[5];
        temp_r3_5 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD0) * 0xC);
        *(float *)((char *)temp_r3_5 + 0xE24) = zero;
        *(float *)((char *)temp_r3_5 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0xEC) + f[8]);
        *(float *)((char *)temp_r3_5 + 0xE2C) = zero;
        temp_r3_6 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD4) * 0xC);
        *(float *)((char *)temp_r3_6 + 0xE24) = zero;
        *(float *)((char *)temp_r3_6 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x158) + f[9]);
        *(float *)((char *)temp_r3_6 + 0xE2C) = zero;
        temp_r3_7 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD8) * 0xC);
        *(float *)((char *)temp_r3_7 + 0xE24) = zero;
        *(float *)((char *)temp_r3_7 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x1C4) + f[10]);
        *(float *)((char *)temp_r3_7 + 0xE2C) = zero;
    }
    *(int *)((char *)arg1 + 0xFA4) = *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xDC);
}

/* Set the truck's physics float at +0x25DC, the first of the triplet at
 * +0x25DC/+0x25E0/+0x25E4 that reset code (fn_801838C8/fn_80183E7C) sets to 0/0/1. */
void fn_8018ADA4(void *truck, f32 value) { *(f32 *)((u8 *)truck + 0x25DC) = value; }

/* Set the truck's +0x25DC physics float (same field as fn_8018ADA4); callers such
 * as fn_801941A8 feed it a computed, sign-checked position value. */
void fn_8018ADAC(void *truck, f32 value) { *(f32 *)((u8 *)truck + 0x25DC) = value; }

void fn_8018ADB4(void *car, f32 value) {
    /* Set the car's float tuning parameter at offset 0x25E0 (one of a run of interpolated fields). */
    *(f32 *)((u8 *)car + 0x25E0) = value;
}

/* Set the truck's physics float at +0x25E4, the third of the triplet at
 * +0x25DC/+0x25E0/+0x25E4 that reset code (fn_801838C8/fn_80183E7C) sets to 0/0/1. */
void fn_8018ADBC(void *truck, f32 value) { *(f32 *)((u8 *)truck + 0x25E4) = value; }

void fn_8018ADC4(void *car, f32 value) {
    /* Set the car's float tuning parameter at offset 0x25E8 (one of a run of interpolated fields). */
    *(f32 *)((u8 *)car + 0x25E8) = value;
}

void fn_8018ADCC(void *car, float value) {
    /* Set the car's float tuning parameter at offset 0x25EC (one of a run of interpolated fields). */
    *(float *)((unsigned char *)car + 0x25EC) = value;
}

/* Set field +8 of this car's 0x9C-byte record in lbl_8055E918 to value,
 * indexing by the car's element index at +0x1EC. */
void fn_8018ADD4(void *car, int value) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)car + 0x1EC) * 0x9C) + 8) = value;
}

extern int lbl_8055E918;
void fn_8018ADEC(void *car) {
    /* Reset field +8 of this car's 0x9C-byte state record in lbl_8055E918 to -10. */
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)car + 0x1EC) * 0x9C) + 8) = -10;
}

/* Set this object's car-element +8 field to -10, indexing the 0x9C-byte entry set by the object's element index at +0x1EC. */
void fn_8018AE08(void *object) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)object + 0x1EC) * 0x9C) + 8) = -10;
}

/* Set the signed-byte state flag at offset 0x260D of the given object. */
void fn_8018AE24(void *object, signed char value) {
    *((signed char *)object + 0x260D) = value;
}

/* Set the car's float tuning parameter at offset 0x2600 (next to the 0x2604 field) to value. */
void fn_8018AE2C(void *car, f32 value) { *(f32 *)((u8 *)car + 0x2600) = value; }

/* Set the car's float tuning parameter at offset 0x2604 (next to the 0x2600 field) to value. */
void fn_8018AE34(void *car, f32 value) { *(f32 *)((u8 *)car + 0x2604) = value; }

extern f32 fn_8018AE3C(void);
/* Virtual getter called on a car object (which it ignores): this class stores no value for
   this float parameter, so it returns the constant 0.0f (.sdata2 float lbl_80561CAC). */
f32 fn_8018AE3C(void) {
    return 0.0f;
}

extern f32 fn_8018AE44(void);
f32 fn_8018AE44(void) {
    return F_0;
}

extern f32 fn_8018AE4C(void);
f32 fn_8018AE4C(void) {
    return F_0;
}

extern f32 fn_8018AE54(void);
f32 fn_8018AE54(void) {
    return F_0;
}

/* Returns the shared vector at lbl_80434990, marking the one-time init flag
 * lbl_8055E4F8 on first use. */
char *fn_8018AE5C(void) {
    if (lbl_8055E4F8 == 0) {
        lbl_8055E4F8 = 1;
    }
    return lbl_80434990;
}

/* Return an LFO scale factor based on the sine table state and object thresholds. */
float fn_8018AE7C(void *object) {
    void *table = __AXFXGetLfoSinTable_801769CC();
    int cond;
    if (*(u32 *)((u8 *)table + 4) - 0x00180000U == 0x304U) {
        return lbl_80561DE0;
    }
    cond = (*(float *)((u8 *)object + 0x25bc) > lbl_80558DC4);
    if (cond) {
        return lbl_80561DE0;
    }
    if (*(float *)((u8 *)object + 0xd4) > lbl_80561F28) {
        return lbl_80561DE0;
    }
    return lbl_80561CDC;
}

/* Empty stub (no operation). */
void fn_8018AF00(void) {

}

extern int fn_801CF064(void);
extern void fn_801BEB30();
extern int *fn_801E1F44(void);
extern void resetSceneLights(void *);
#pragma scheduling invalid_target
extern void fn_801BEB30(int, int *);
#pragma opt_common_subs off
int fn_8018AF04(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    void *path;
    unsigned char *obj;
    float zero;
    float tailZero;
    struct {
        void *obj;
        unsigned char pad[4];
        float matrix0[8];
        float values[4];
        float x;
        float y;
        float z;
        float w;
    } frame;
    int d;
    int b;
    int c;
    int a;
    int index;
    float tx;
    float tw;
    float tz;
    float ty;
    float x;
    float y;
    float z;
    float w;
    int cond;
    if (fn_801CF064() == 0)
        path = p + 0x1E44;
    else
        path = p + 0x20F8;
    fn_8018F2C0(arg0, path);
    a = *(int *)(p + 0x241C);
    b = *(int *)(p + 0x2490);
    d = *(int *)(p + 0x2578);
    c = *(int *)(p + 0x2504);
    tx = *(float *)(p + 0x23E8);
    ty = *(float *)(p + 0x245C);
    tz = *(float *)(p + 0x24D0);
    tw = *(float *)(p + 0x2544);
    a &= ~8;
    b &= ~8;
    c &= ~8;
    d &= ~8;
    *(int *)(p + 0x241C) = a;
    index = *(int *)(p + 0x1EC);
    frame.x = tx;
    *(int *)(p + 0x2490) = b;
    frame.y = ty;
    *(int *)(p + 0x2504) = c;
    frame.z = tz;
    *(int *)(p + 0x2578) = d;
    frame.w = tw;
    fn_801BEB30(index, (int *)&frame.obj);
    x = frame.x;
    obj = (unsigned char *)frame.obj;
    y = frame.y;
    *(float *)(obj + 0x70) = x;
    z = frame.z;
    *(float *)(obj + 0x74) = y;
    w = frame.w;
    *(float *)(obj + 0x78) = z;
    zero = lbl_80561CAC;
    *(float *)(obj + 0x7C) = w;
    frame.values[0] = x;
    *(float *)(obj + 0x130) = zero;
    *(float *)(obj + 0x134) = zero;
    *(float *)(obj + 0x138) = zero;
    *(float *)(obj + 0x13C) = zero;
    frame.values[1] = y;
    *(float *)(obj + 0x140) = zero;
    *(float *)(obj + 0x144) = zero;
    *(float *)(obj + 0x148) = zero;
    *(float *)(obj + 0x14C) = zero;
    frame.values[2] = z;
    cond = *(int *)(p + 0x26B0);
    frame.values[3] = w;
    frame.matrix0[4] = zero;
    frame.matrix0[5] = zero;
    frame.matrix0[6] = zero;
    frame.matrix0[7] = zero;
    frame.matrix0[0] = zero;
    frame.matrix0[1] = zero;
    frame.matrix0[2] = zero;
    frame.matrix0[3] = zero;
    if (cond >= 0) {
        *(int *)(p + 0x26B0) = -1;
        *(int *)(p + 0x1E40) = 0;
        if (*fn_801E1F44() == 1)
            resetSceneLights(arg0);
        tailZero = lbl_80561CAC;
        *(float *)(p + 0x2650) = tailZero;
        *(float *)(p + 0x264C) = tailZero;
        *(float *)(p + 0x25C4) = tailZero;
    }
}
#pragma opt_common_subs reset
int fn_8018B06C(void *car) {
    /* Returns field +0x14 of this car's 0x9C-byte state record in lbl_8055E918,
       indexed by the car's element index at +0x1EC. */
    return *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)car + 0x1EC) * 0x9C) + 0x14);
}

int fn_8018B084(void *car) {
    /* Returns field +0x20 of this car's 0x9C-byte state record in lbl_8055E918,
       indexed by the car's element index at +0x1EC. */
    return *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)car + 0x1EC) * 0x9C) + 0x20);
}

void fn_8018B09C(void *object) {
    /* Run the physics helper, then reset this object's float field at +0x26DC
       to the shared zero value held in lbl_8055E3C8. */
    fn_8017D2C8();
    *(float *)((unsigned char *)object + 0x26dc) = lbl_8055E3C8;
}

/* Set this object's integer field at offset 0x2610 to value. */
void fn_8018B0D0(void *object, int value) {
    *(int *)((unsigned char *)object + 0x2610) = value;
}

#pragma push
#pragma ppc_psq_save off
#pragma paired off
#pragma paired_single off
void fn_8018B0D8(void *arg0, void *arg1, void *arg2, int *arg3, int *arg4, float farg0) {
    float mag;
    float v5, v4, v7, v5b, v6, v5c, v4b, v5d;
    float f6, f4b, f1b, f1c;
    float f30, f13, f30b, f30c;
    unsigned short t0, t0b, t4;
    unsigned char b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17;
    unsigned char tc;
    int bit;
    int i;
    unsigned char *p5, *p6, *p7;
    int idx, tbl;
    unsigned char *src1, *src2;
    unsigned char *dst1, *dst2;
    float spC, sp8;
    float tmp;
    bit = ((*(unsigned short *)((char *)arg2 + 0x3A) >> 9) & 1);
    if (bit != 0) {
        fn_8017D160(arg0, (unsigned char *)arg1, (unsigned char *)arg1, arg3, arg4, farg0);
    } else {
        fn_8017D160(arg0, (unsigned char *)arg1, (unsigned char *)arg2, arg3, arg4, farg0);
    }
    mag = PSVECMag((char *)arg0 + 0x118);
    t0 = *(unsigned short *)((char *)arg2 + 0x20);
    v5 = lbl_80561CD0;
    *(float *)((char *)arg0 + 0x25D8) = mag;
    *(float *)((char *)arg0 + 0x25CC) = mag;
    *(float *)((char *)arg0 + 0x25D4) = mag;
    tmp = (((float)t0 - lbl_80561CAC) / lbl_80561F54);
    v5 = (v5 < tmp) ? v5 : tmp;
    v5 = (v5 > lbl_80561CAC) ? lbl_80561CAC : v5;
    t0b = *(unsigned short *)((char *)arg1 + 0x20);
    v4 = lbl_80561CD0;
    tmp = (((float)t0b - lbl_80561CAC) / lbl_80561F54);
    v4 = (v4 < tmp) ? v4 : tmp;
    v4 = (v4 > lbl_80561CAC) ? lbl_80561CAC : v4;
    b3 = *(unsigned char *)((char *)arg2 + 0x22);
    f6 = lbl_80561F58 + (v4 * lbl_80561F5C);
    v7 = lbl_80561CD0;
    *(float *)((char *)arg0 + 0x25D0) = (float)(f6 + (farg0 * ((lbl_80561F58 + (v5 * lbl_80561F5C)) - f6)));
    tmp = (((float)b3 - lbl_80561CAC) / lbl_80561F60);
    v7 = (v7 < tmp) ? v7 : tmp;
    v7 = (v7 > lbl_80561CAC) ? lbl_80561CAC : v7;
    b4 = *(unsigned char *)((char *)arg1 + 0x22);
    v5b = lbl_80561CD0;
    tmp = (((float)b4 - lbl_80561CAC) / lbl_80561F60);
    v5b = (v5b < tmp) ? v5b : tmp;
    v5b = (v5b > lbl_80561CAC) ? lbl_80561CAC : v5b;
    tc = *(unsigned char *)((char *)arg1 + 0x3C);
    f1b = lbl_80561F64 + (v5b * lbl_80561E60);
    f4b = f1b + (farg0 * ((lbl_80561F64 + (v7 * lbl_80561E60)) - f1b));
    *(float *)((char *)arg0 + 0x25F0) = f4b;
    *(float *)((char *)arg0 + 0x25DC) = f4b;
    if ((int)tc != 0) {
        if (bit != 0) {
            float vv = lbl_80561CD0;
            tmp = (((float)tc - lbl_80561CAC) / lbl_80561F60);
            vv = (vv < tmp) ? vv : tmp;
            vv = (vv > lbl_80561CAC) ? lbl_80561CAC : vv;
        } else {
            float vv2;
            unsigned char bb = *(unsigned char *)((char *)arg2 + 0x3C);
            vv2 = lbl_80561CD0;
            tmp = (((float)bb - lbl_80561CAC) / lbl_80561F60);
            vv2 = (vv2 < tmp) ? vv2 : tmp;
            tmp = (((float)tc - lbl_80561CAC) / lbl_80561F60);
            vv2 = (vv2 < tmp) ? vv2 : tmp;
        }
    }
    b5 = *(unsigned char *)((char *)arg2 + 0x23);
    v6 = lbl_80561CD0;
    *(float *)((char *)arg0 + 0x24A8) = (float)lbl_80561CAC;
    *(float *)((char *)arg0 + 0x251C) = (float)lbl_80561CAC;
    *(float *)((char *)arg0 + 0x25F8) = v6;
    *(float *)((char *)arg0 + 0x25E8) = v6;
    *(float *)((char *)arg0 + 0x23C0) = (*(float *)((char *)arg0 + 0x25F0)) * (*(float *)((char *)arg0 + 0x5B0));
    *(float *)((char *)arg0 + 0x2434) = (*(float *)((char *)arg0 + 0x25F0)) * (*(float *)((char *)arg0 + 0x5B0));
    tmp = (((float)b5 - lbl_80561CAC) / lbl_80561F60);
    v6 = (v6 < tmp) ? v6 : tmp;
    v6 = (v6 > lbl_80561CAC) ? lbl_80561CAC : v6;
    b6 = *(unsigned char *)((char *)arg1 + 0x23);
    v5c = lbl_80561CD0;
    f4b = lbl_80561CAC + (v6 * v5c);
    tmp = (((float)b6 - lbl_80561CAC) / lbl_80561F60);
    v5c = (v5c < tmp) ? v5c : tmp;
    v5c = (v5c > lbl_80561CAC) ? lbl_80561CAC : v5c;
    f1c = lbl_80561CAC + (v5c * lbl_80561CD0);
    fn_8018ADB4(arg0, f1c + (farg0 * (f4b - f1c)));
    b7 = *(unsigned char *)((char *)arg2 + 0x24);
    v4b = lbl_80561CD0;
    tmp = (((float)b7 - lbl_80561CAC) / lbl_80561F60);
    v4b = (v4b < tmp) ? v4b : tmp;
    v4b = (v4b > lbl_80561CAC) ? lbl_80561CAC : v4b;
    b8 = *(unsigned char *)((char *)arg1 + 0x24);
    v5d = lbl_80561CD0;
    f4b = lbl_80561CAC + (v4b * v5d);
    tmp = (((float)b8 - lbl_80561CAC) / lbl_80561F60);
    v5d = (v5d < tmp) ? v5d : tmp;
    v5d = (v5d > lbl_80561CAC) ? lbl_80561CAC : v5d;
    f1b = lbl_80561CAC + (v5d * lbl_80561CD0);
    fn_8018ADBC(arg0, f1b + (farg0 * (f4b - f1b)));
    t4 = *(unsigned short *)((char *)arg1 + 0x3A);
    *(int *)((char *)arg0 + 4) = (int)(t4 | *(unsigned short *)((char *)arg2 + 0x3A));
    *(signed char *)((char *)arg0 + 0x260D) = (signed char)((t4 >> 8) & 1);
    p5 = (unsigned char *)arg0 + 0x23AC;
    p6 = (unsigned char *)arg1 + 0x26;
    p7 = (unsigned char *)arg2 + 0x26;
    for (i = 0; i < 4; i++) {
        float a0, a1;
        unsigned char u4;
        float t13, t30;
        b9 = *(p7 + 2);
        a0 = lbl_80561CD0;
        tmp = (((float)b9 - lbl_80561CAC) / lbl_80561F60);
        a0 = (a0 < tmp) ? a0 : tmp;
        a0 = (a0 > lbl_80561CAC) ? lbl_80561CAC : a0;
        b10 = *(p6 + 2);
        a1 = lbl_80561CD0;
        tmp = (((float)b10 - lbl_80561CAC) / lbl_80561F60);
        a1 = (a1 < tmp) ? a1 : tmp;
        a1 = (a1 > lbl_80561CAC) ? lbl_80561CAC : a1;
        b11 = *(p6 + 0);
        t30 = lbl_80561CAC + (a1 * lbl_80561CD8);
        t13 = t30 + (farg0 * ((lbl_80561CAC + (a0 * lbl_80561CD8)) - t30));
        *(float *)(p5 + 0xC) = t13;
        *(float *)(p5 + 0x1C) = t13;
        a0 = lbl_80561CD0;
        tmp = (((float)b11 - lbl_80561CAC) / lbl_80561F60);
        a0 = (a0 < tmp) ? a0 : tmp;
        a0 = (a0 > lbl_80561CAC) ? lbl_80561CAC : a0;
        b12 = *(p7 + 0);
        f30 = lbl_80561F68 + (a0 * lbl_80561F6C);
        a1 = lbl_80561CD0;
        tmp = (((float)b12 - lbl_80561CAC) / lbl_80561F60);
        a1 = (a1 < tmp) ? a1 : tmp;
        a1 = (a1 > lbl_80561CAC) ? lbl_80561CAC : a1;
        f13 = lbl_80561F68 + (a1 * lbl_80561F6C);
        if (f13 > f30) {
            if ((f13 - f30) > lbl_80561E70) f30 += lbl_80561E6C;
        } else if ((f30 - f13) > lbl_80561E70) {
            f13 += lbl_80561E6C;
        }
        b13 = *(p7 + 1);
        *(float *)(p5 + 8) = (float)(f30 + (farg0 * (f13 - f30)));
        a0 = lbl_80561CD0;
        tmp = (((float)b13 - lbl_80561CAC) / lbl_80561F60);
        a0 = (a0 < tmp) ? a0 : tmp;
        a0 = (a0 > lbl_80561CAC) ? lbl_80561CAC : a0;
        b14 = *(p6 + 1);
        a1 = lbl_80561CD0;
        tmp = (((float)b14 - lbl_80561CAC) / lbl_80561F60);
        a1 = (a1 < tmp) ? a1 : tmp;
        a1 = (a1 > lbl_80561CAC) ? lbl_80561CAC : a1;
        b15 = *(p7 + 3);
        f30b = lbl_80561EE4 + (a1 * lbl_80561D28);
        *(float *)(p5 + 0) = (float)(f30b + (farg0 * ((lbl_80561EE4 + (a0 * lbl_80561D28)) - f30b)));
        a0 = lbl_80561CD0;
        tmp = (((float)b15 - lbl_80561CAC) / lbl_80561F60);
        a0 = (a0 < tmp) ? a0 : tmp;
        a0 = (a0 > lbl_80561CAC) ? lbl_80561CAC : a0;
        b16 = *(p6 + 3);
        a1 = lbl_80561CD0;
        tmp = (((float)b16 - lbl_80561CAC) / lbl_80561F60);
        a1 = (a1 < tmp) ? a1 : tmp;
        a1 = (a1 > lbl_80561CAC) ? lbl_80561CAC : a1;
        u4 = *(p6 + 4);
        f30c = lbl_80561CAC + (a1 * lbl_80561D34);
        *(float *)(p5 + 0x68) = (float)(f30c + (farg0 * ((lbl_80561CAC + (a0 * lbl_80561D34)) - f30c)));
        *(int *)(p5 + 0x70) = (int)u4;
        *(signed char *)(p5 + 0x6C) = 1;
        *(signed char *)(p5 + 0x20) = (signed char)(u4 & 1);
        p5 += 0x74;
        p6 += 5;
        p7 += 5;
    }
    b17 = *(unsigned char *)((char *)arg1 + 0x25);
    idx = *(int *)((char *)arg0 + 0x1EC);
    tbl = lbl_8055E918;
    *(int *)(tbl + idx * 0x9C + 0x14) = (int)(signed char)b17;
    *(int *)(tbl + idx * 0x9C + 8) = (int)(signed char)b17;
    *(int *)((char *)arg0 + 0x2678) = *(int *)((char *)arg1 + 0x40);
    *arg4 = 0x44;
    *arg3 = 0x44;
    src1 = (unsigned char *)arg2 + 8;
    dst1 = (unsigned char *)&spC;
    for (i = 0; i < 4; i++) {
        *dst1++ = *src1++;
    }
    src2 = (unsigned char *)arg2 + 0x10;
    dst2 = (unsigned char *)&sp8;
    for (i = 0; i < 4; i++) {
        *dst2++ = *src2++;
    }
    fn_801E9DD0((char *)arg0 + 0x6C, spC, sp8);
}
#pragma pop

extern void fn_8017D274(void);
extern int fn_801363A0(int);
extern float lbl_80561F54, lbl_80561F58, lbl_80561F5C, lbl_80561F60;
extern float lbl_80561F64, lbl_80561F68, lbl_80561F6C;
extern float lbl_80561CD0, lbl_80561CDC, lbl_80561D28, lbl_80561D34;
extern float lbl_80561E60, lbl_80561EE4;
#pragma cplusplus on
#pragma scheduling invalid_target
static inline float BA54_Clamp(float lo, float x) {
    float v = lo;
    v = (v < x) ? v : x;
    v = (v > lbl_80561CAC) ? lbl_80561CAC : v;
    return v;
}

extern "C" int fn_8018BA54(void *arg0, void *arg1) {
    float temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f3;
    float color, value3, second_offset, second_scale, scaled1, middle1, output1;
    float var_f0, var_f0_2, var_f0_3, var_f0_4;
    register float var_f2;
    float var_f3, var_f3_2, var_f4;
    float loop_y_scale, loop_x_scale, loop_x, loop_height_scale, loop_height;
    float loop_scale, loop_base, loop_max, loop_min;
    int i, var_r5;
    unsigned char *var_r3, *var_r4;
    void *obj, *ret;

    fn_8017D274();
    var_f2 = lbl_80561CD0;
    temp_f0 = (*(float *)((char *)arg0 + 0x25D0) - lbl_80561F58) / lbl_80561F5C;
    var_f2 = (var_f2 < temp_f0) ? var_f2 : temp_f0;
    var_f2 = (var_f2 > lbl_80561CAC) ? lbl_80561CAC : var_f2;
    var_f4 = lbl_80561CD0;
    second_offset = lbl_80561F64;
    second_scale = lbl_80561E60;
    scaled1 = var_f2 * lbl_80561F54;
    middle1 = (scaled1) + (lbl_80561CAC);
    output1 = lbl_80561CDC + middle1;
    *(short *)((char *)arg1 + 0x20) = (short)output1;
    temp_f0_2 = (*(float *)((char *)arg0 + 0x25F0) - second_offset) / second_scale;
    var_f4 = (var_f4 < temp_f0_2) ? var_f4 : temp_f0_2;
    var_f4 = (var_f4 > lbl_80561CAC) ? lbl_80561CAC : var_f4;
    var_f3 = lbl_80561CD0;
    *(signed char *)((char *)arg1 + 0x22) = (signed char)(lbl_80561CDC + (lbl_80561CAC + (var_f4 * lbl_80561F60)));
    temp_f0_3 = (*(float *)((char *)arg0 + 0x25F4) - lbl_80561CAC) / var_f3;
    var_f3 = (var_f3 < temp_f0_3) ? var_f3 : temp_f0_3;
    var_f3 = (var_f3 > lbl_80561CAC) ? lbl_80561CAC : var_f3;
    var_f3_2 = lbl_80561CD0;
    *(signed char *)((char *)arg1 + 0x23) = (signed char)(lbl_80561CDC + (lbl_80561CAC + (var_f3 * lbl_80561F60)));
    temp_f0_4 = (*(float *)((char *)arg0 + 0x25E4) - lbl_80561CAC) / var_f3_2;
    var_f3_2 = (var_f3_2 < temp_f0_4) ? var_f3_2 : temp_f0_4;
    var_f3_2 = (var_f3_2 > lbl_80561CAC) ? lbl_80561CAC : var_f3_2;
    temp_f3 = lbl_80561CAC + (var_f3_2 * lbl_80561F60);
    color = lbl_80561CDC + temp_f3;
    value3 = lbl_80561CDC + (lbl_80561CAC + (lbl_80561CD0 * lbl_80561F60));
    *(signed char *)((char *)arg1 + 0x24) = (signed char)color;
    *(signed char *)((char *)arg1 + 0x3C) = (signed char)value3;
    obj = *(void **)((char *)arg0 + 0x270);
    ret = ((BA54CallObj *)obj)->method4(color, lbl_80561CDC);
    *(int *)((char *)arg1 + 0x40) = ((int (*)(void *, void *))fn_801363A0)(ret, (char *)ret + 4);
    if (*(unsigned char *)((char *)arg1 + 0x3C) == 0) *(unsigned char *)((char *)arg1 + 0x3C) = 1;

    *(short *)((char *)arg1 + 0x3A) = *(int *)((char *)arg0 + 4);
    loop_min = lbl_80561CAC;
    loop_max = lbl_80561CD0;
    var_r4 = (unsigned char *)arg1 + 0x26;
    loop_base = lbl_80561CDC;
    {
        int idx = *(int *)((char *)arg0 + 0x1EC);
        int table = lbl_8055E918;
        *(unsigned char *)((char *)arg1 + 0x25) = *(int *)(table + idx * 0x9C + 0x14);
    }
    loop_scale = lbl_80561F60;
    loop_height = lbl_80561F68;
    var_r3 = (unsigned char *)arg0 + 0x23AC;
    loop_height_scale = lbl_80561F6C;
    loop_x = lbl_80561EE4;
    loop_x_scale = lbl_80561D28;
    loop_y_scale = lbl_80561D34;
    for (i = 0; i < 4; i++) {
        var_r5 = *(int *)(var_r3 + 0x70);
        if (*(unsigned char *)(var_r3 + 0x20) != 0) var_r5 |= 1;
        var_f0 = (*(float *)(var_r3 + 0xC) - loop_min) * loop_base;
        var_f0 = (loop_max < var_f0) ? loop_max : var_f0;
        var_f0 = (var_f0 > loop_min) ? loop_min : var_f0;
        var_r4[2] = (signed char)(loop_base + (loop_min + (var_f0 * loop_scale)));
        var_f0_2 = (*(float *)(var_r3 + 8) - loop_height) / loop_height_scale;
        var_f0_2 = (loop_max < var_f0_2) ? loop_max : var_f0_2;
        var_f0_2 = (var_f0_2 > loop_min) ? loop_min : var_f0_2;
        var_r4[0] = (signed char)(loop_base + (loop_min + (var_f0_2 * loop_scale)));
        var_f0_3 = (*(float *)(var_r3 + 0) - loop_x) / loop_x_scale;
        var_f0_3 = (loop_max < var_f0_3) ? loop_max : var_f0_3;
        var_f0_3 = (var_f0_3 > loop_min) ? loop_min : var_f0_3;
        var_r4[1] = (signed char)(loop_base + (loop_min + (var_f0_3 * loop_scale)));
        var_f0_4 = (*(float *)(var_r3 + 0x68) - loop_min) / loop_y_scale;
        var_f0_4 = (loop_max < var_f0_4) ? loop_max : var_f0_4;
        var_f0_4 = (var_f0_4 > loop_min) ? loop_min : var_f0_4;
        var_r3 += 0x74;
        var_r4[3] = (signed char)(loop_base + (loop_min + (var_f0_4 * loop_scale)));
        var_r4[4] = (signed char)var_r5;
        var_r4 += 5;
    }
    return 0x44;
}
#pragma scheduling on
#pragma cplusplus reset
/* Build an identity 3x4 transform (identity rotation, zero translation) and,
 * if the object has a debug-draw handle at +0x26C4, draw its wireframe through
 * that transform with fn_801C2BF8. */
void fn_8018BDEC(void *object) {
    f32 matrixData[12];
    f32 *matrix = matrixData;
    int debugHandle;
    matrixData[0]=1.0f; matrixData[1]=0.0f; matrixData[2]=0.0f; matrixData[3]=0.0f;
    matrixData[4]=1.0f; matrixData[5]=0.0f; matrixData[6]=0.0f; matrixData[7]=0.0f;
    matrixData[8]=1.0f; matrixData[9]=0.0f; matrixData[10]=0.0f; matrixData[11]=0.0f;
    debugHandle=*(int *)((u8 *)object+0x26C4);
    if(debugHandle) fn_801C2BF8(debugHandle,matrix);
}

extern float __fabsf(float);
#pragma push
#pragma small_data off
__declspec(section ".data") extern float lbl_80558DC4;
extern void fn_801A1474(void *, float);
/* Update the object's scale factor and recompute cached values derived from it when the new scale differs significantly. */
void fn_8018BE54(void *arg0, float newScale) {
    char *p = (char *)arg0;
    double d = __fabsf(*(float *)(p + 0x5E4) - newScale);
    float diff = (float)d;
    if (!(diff <= lbl_80558DC4)) {
        double scaleDouble = newScale;
        float scale;
        float scaleSquared;
        *(float *)(p + 0x5E4) = newScale;
        fn_801A1474((void *)*(int *)(p + 0x268), (float)scaleDouble);
        scale = *(float *)(p + 0x5E4);
        scaleSquared = scale * scale;
        *(float *)(p + 0x330) = *(float *)(p + 0x468) * scaleSquared;
        *(float *)(p + 0x334) = *(float *)(p + 0x46C) * scaleSquared;
        *(float *)(p + 0x338) = *(float *)(p + 0x470) * scaleSquared;
        *(float *)(p + 0x344) = *(float *)(p + 0x47C) * scale;
        *(float *)(p + 0x33C) = *(float *)(p + 0x474) * scale;
        *(float *)(p + 0x340) = *(float *)(p + 0x478) * scale;
        *(float *)(p + 0x34C) = *(float *)(p + 0x484) * scale;
        *(float *)(p + 0x3AC) = scale * *(float *)(p + 0x4E4);
        *(float *)(p + 0x3D0) = scale * *(float *)(p + 0x508);
        *(float *)(p + 0x3F4) = scale * *(float *)(p + 0x52C);
        *(float *)(p + 0x418) = scale * *(float *)(p + 0x550);
        ((void (*)(void *))fn_8018A180)(arg0);
    }
}
#pragma pop
/* Initializes the pointed-to flag word with the default bitmask 0x0FF807FF. */
void fn_8018BF44(int *flags) { *flags = 0x0FF807FF; }

/* Virtual accessor returning the fixed constant 0 (false). */
int fn_8018BF54(void) { return 0; }

/* No-op stub (empty function). */
void fn_8018BF5C(void) {
}

/* Empty stub (no operation). */
void fn_8018BF60(void) {

}

int fn_8018BF64(void) {
    /* Virtual accessor returning the fixed constant 0x44 (68). */
    return 0x44;
}
extern int fn_80128668(void);
extern void fn_8017A580(int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
extern void fn_801838C8(void *);
extern int fn_801769C4(void);
extern void fn_80181EAC(int);
extern void fn_8018F538();
extern void fn_80279B28(int, void *);
extern void fn_80279C00(int, void *);
extern void fn_8017B0B0(void);
extern void fn_801BD808(void *);
extern int lbl_8055E4D0;
