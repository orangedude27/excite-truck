extern float lbl_80561CA0, lbl_80561CA4, lbl_80561CA8;
extern float lbl_80561CB0, lbl_80561CB4, lbl_80561CB8, lbl_80561CBC;
extern float fabsf(float);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_801BEB30();
extern int fn_801D1184(void *);
extern void fn_801D14EC(int);
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
extern char lbl_803322B0[];
extern float lbl_80561CD4, lbl_80561CE0, lbl_80561CE4, lbl_80561CE8;
extern float lbl_80561CEC, lbl_80561CF0, lbl_80561CF4, lbl_80561CF8, lbl_80561CFC;
extern float lbl_80561D04, lbl_80561D08, lbl_80561D0C, lbl_80561D10, lbl_80561D14;
extern float lbl_80561D18, lbl_80561D1C, lbl_80561D20, lbl_80561D24, lbl_80561D28;
extern float lbl_80561D2C, lbl_80561D30;
extern int fn_80019BA8(void);
extern void fn_802049DC(int, int, float, float, float);
extern int fn_8020503C(void *);
extern char lbl_80434990[];
extern float lbl_80561CDC;
extern float lbl_80561DE0;
extern float lbl_80561F28;
extern float lbl_80558DC4;
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
extern void fn_801D11D8(void *);
extern void fn_801D1540(void *);
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
extern float lbl_80561CC4;
extern float lbl_80561CC8;
extern void fn_8018185C(void *, const float *);
extern void fn_8017B6A8(void *);
extern void fn_8018A750(void *, int);
extern void fn_801B30C0(int, int, int);
extern void fn_801BE400(int, float *, float);
extern void fn_801D1810(int, int);
extern void fn_801E9DD0(void *, float, float);
extern void fn_8026A394(void *, int, int);
extern void fn_8018A8A8();
extern double fn_8002EFB4(float, double);
extern double lbl_80561F20, lbl_80561F30, lbl_80561F40;
extern float lbl_80561F38, lbl_80561F3C, lbl_80561F48, lbl_80561F4C, lbl_80561F50;
typedef struct Mtx3x4Words { int value[12]; } Mtx3x4Words;
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
struct BA54CallObj {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void *method4(float, float);
};
#pragma cplusplus reset
void fn_8018185C(void *out_, const float *in) {
    float *out = (float *)out_;
    float x = in[1];
    float y;
    float t;
    float delta;
    float denom;
    float first;
    float slope1;
    float x2;
    float y2;
    float v;
    float slope2;

    out[7] = x;
    out[10] = in[3];
    out[6] = lbl_80561CA0 * in[5];

    if (x <= lbl_80561CA4) {
        x = lbl_80561CA4;
    }

    y = (lbl_80561CA8 * in[0]) / x;
    out[9] = lbl_80561CAC;
    delta = out[7] - in[3];
    first = lbl_80561CA0 * in[2];
    t = lbl_80561CA0 * y;
    denom = delta * delta;
    if (denom <= lbl_80561CA4) {
        denom = lbl_80561CA4;
    }
    slope1 = (t - first) / denom;
    out[8] = y / lbl_80561CB4;
    out[0] = slope1;
    out[1] = out[6] + lbl_80561CB0 * slope1 * in[3];
    out[2] = first + slope1 * (in[3] * in[3]);

    x2 = in[4] - out[10];
    y2 = x2 * x2;
    v = lbl_80561CA0 * (lbl_80561CB8 * in[2]) - first;
    if (y2 <= lbl_80561CBC) {
        y2 = lbl_80561CBC;
    }
    slope2 = v / y2;
    out[3] = slope2;
    out[5] = first + slope2 * (out[10] * out[10]);
    out[4] = out[6] + lbl_80561CB0 * slope2 * out[10];
}

void fn_801819A0(void *dst, void *arg1, void *arg2, float scale, float farg1, float farg2) {
    float values[6];
    float a;
    float b;
    float c;
    float d;
    a = *(float *)((char *)arg1 + 0x54);
    b = *(float *)((char *)arg1 + 0x50);
    c = *(float *)((char *)arg1 + 0x5C);
    d = *(float *)((char *)arg1 + 0x58);
    values[4] = *(float *)((char *)arg1 + 0x68);
    values[5] = *(float *)((char *)arg1 + 0x60);
    values[0] = (a * scale) / lbl_80561CC4;
    values[2] = (b * scale) / lbl_80561CC8;
    values[1] = c * farg2;
    values[3] = d * farg1;
    fn_8018185C(dst, values);
}

float fn_80181A14(void *arg0) {
    float value;
    if (*((unsigned char *)arg0 + 0x259d) != 0) value = lbl_80434930[6];
    else value = lbl_80434908[6];
    return *((float *)((unsigned char *)arg0 + 0x2d8)) * value;
}

float fn_80181A48(void *arg0) {
 volatile float *p = lbl_804348E8;
 if (*((unsigned char *)arg0 + 0x259D)) {
   p += 18;
 } else if (lbl_8055E4F4) {
   p += 26;
 } else {
   p += 8;
 }
 return *((float *)((unsigned char *)arg0 + 0x2D0)) + p[7];
}
float fn_80181A94(void) { if (lbl_8055E4F4) return lbl_80434950[14]; return lbl_80434908[2]; }

float fn_80181AC0(void) { if (lbl_8055E4F4) return lbl_80434950[15]; return lbl_80434908[3]; }

#pragma dont_inline fn_80181AEC
float fn_80181AEC(void) { return lbl_80434930[3]; }

#pragma paired_single off
#pragma scheduling invalid_target
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
register float *temp_r4;
register float *temp_r5;

register int initialize = lbl_8055A3B5;
if (initialize != 0) {
temp_r5 = (float *)((char *)base + 0x20);
temp_r4 = (float *)((char *)base + 0x48);
(*(float *)((char *)(base) + (0x20))) = (float) lbl_80561CD4;
temp_r5[1] = (float) lbl_80561CD8;
temp_r5[2] = (float) lbl_80561CDC;
temp_r5[3] = (float) lbl_80561CD0;
temp_r5[6] = (float) lbl_80561CD8;
temp_r5[7] = (float) lbl_80561CE0;
temp_r5[8] = (float) lbl_80561CE4;
temp_r5[4] = (float) lbl_80561CE8;
temp_r5[5] = (float) lbl_80561CE8;
(*(float *)((char *)(base) + (0x48))) = (float) lbl_80561CEC;
temp_r4[1] = (float) lbl_80561CD0;
temp_r4[2] = (float) lbl_80561CD8;
temp_r4[3] = (float) lbl_80561CD0;
temp_r4[6] = (float) lbl_80561CF0;
temp_r4[7] = (float) lbl_80561CE0;
temp_r4[4] = (float) lbl_80561CE8;
(*(float *)((char *)(&lbl_8055E4E8) + (0))) = (float) lbl_80561CF4;
(*(float *)((char *)(&lbl_8055E4E8) + (4))) = (float) lbl_80561CD8;
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
#pragma paired_single reset
#pragma scheduling on
extern float lbl_80561D38;
extern float lbl_80561D3C;
extern float lbl_80561D0C;
extern float lbl_80561CFC;
extern float fn_80129DC4(int, float, float);
extern float fn_802798E8(int);
extern void fn_802799EC(int, float);
#pragma ppc_psq_save off
void fn_80181EAC(int arg0) {
    float minA = lbl_80561D38;
    float maxA = lbl_80561D3C;
    float temp_f1;
    float temp_f30;
    float temp_f31;
    temp_f30 = fn_80129DC4(4, minA, maxA);
    temp_f31 = fn_80129DC4(4, lbl_80561D0C, lbl_80561CFC);
    temp_f1 = fn_802798E8(arg0);
    if ((temp_f1 > temp_f30) && (temp_f1 > temp_f31))
        fn_802799EC(arg0, temp_f1 - temp_f31);
}
#pragma push
#pragma small_data off
void fn_80181F30(void) {
    unsigned int bits = *(unsigned int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4);
    unsigned int mode = (bits >> 19) & 1;
    lbl_8055E4D0 = 0;
    lbl_8055E4F4 = (unsigned char)mode;
    ((void (*)(int, unsigned int))fn_801BD694)(8, mode);
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
void fn_80181FC4(void) {
    fn_8018C510();
    __AXDSPInitCallback_801AFC38();
    fn_801BD790();
}

void fn_80181FEC(void* alarm) {
    fn_801D14EC(fn_801D1184(alarm));
}

extern int fn_80128668(void);
extern void fn_8017A580(int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
extern void fn_801838C8(void *);
extern int fn_801769C4(void);
extern void fn_80181EAC(int);
extern void fn_8018F538(void *);
extern void fn_80279B28(int, void *);
extern void fn_80279C00(int, void *);
extern void fn_8017B0B0(void);
extern void fn_801BD808(void *);
extern char lbl_803326F8[];
extern int lbl_8055E4D0;
void *fn_80182010(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    int index;
    int offset;
    void **entries;

    fn_8017B0B0();
    *(int **)p = (int *)lbl_803326F8;
    *(short *)(p + 0x2B4) = -1;
    fn_801BD808(lbl_803326F8);
    index = lbl_8055E4D0;
    offset = index << 2;
    index++;
    entries = (void **)lbl_804348E8;
    *(void **)((unsigned char *)entries + offset) = arg0;
    lbl_8055E4D0 = index;
    return arg0;
}

void fn_801836DC(void) {

}

int fn_801837DC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

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

void fn_80183DF8(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    int obj = *(int *)(p + 0x328);
    if (obj != 0) {
        fn_8018F538(p + 0x1E44);
        fn_80279C00(obj, p + 0x1E44);
        if (fn_801769C4() == 2 && *(unsigned int *)(p + 0x10) != 0x50434152 &&
            (*(unsigned char *)(p + 0x260) & 4) == 0) {
            fn_80181EAC(obj);
            fn_80279B28(obj, p + 0x1E44);
        }
    }
}

extern int fn_800216D0(void);
extern void fn_801BEB1C(int, int *);
extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80561CAC, lbl_80561CD0, lbl_80561D9C;
extern float lbl_80561CAC, lbl_80561CD0, lbl_80561D9C, lbl_8055E4E0;
extern void fn_8017B4AC(void *, void *);
extern float lbl_80558DC4, lbl_80561DA0, lbl_80561CDC, lbl_80561CD8;
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
               for (i = 0; i != 2; i++) {
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
int fn_80186DDC(void) { return 0; }

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
extern void fn_801BEDD4(void);
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
extern float lbl_80561CB0;
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
    fn_801BEDD4();
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
#pragma cplusplus on
#pragma opt_propagation off
extern "C" void fn_80188A80(void *arg0, int arg_sp0) {
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
(void)arg_sp0;
int temp_i;
float sp1C;
float sp18;
float sp14;
float sp10;
float spC;
float sp8;
register float temp_f0;
register float temp_f0_2;
register float temp_f0_3;
register float temp_f0_4;
register float temp_f0_5;
register float temp_f10;
register float temp_f10_2;
register float temp_f11;
register float temp_f11_2;
register float temp_f13;
register float temp_f1;
register float temp_f1_2;
register float temp_f24;
register float temp_f25;
register float temp_f26;
register float temp_f27;
register float temp_f28;
register float temp_f29;
register float temp_f2;
register float temp_f30;
register float temp_f31;
register float temp_f5;
register float temp_f5_2;
register float temp_f6;
register float temp_f6_2;
register float temp_f7;
register float temp_f7_2;
register float temp_f8;
register float temp_f8_2;
register float temp_f9;
register float temp_f9_2;
register float var_f2;
register float var_f2_2;
register float var_f3;
ObjArg *temp_r3;
ObjArg *temp_r3_2;
ObjVoid *temp_r3_3;
ObjVoid *temp_r3_4;

fn_8017A57C(arg0);
if (*(void **)(p + 0x257C) != 0) {
temp_r3 = *(ObjArg **)(p + 0x270);
temp_i = temp_r3->v12();
temp_r3_2 = *(ObjArg **)(p + 0x257C);
temp_r3_2->v1(temp_i);
}
temp_r3_3 = *(ObjVoid **)(p + 0x2580);
if (temp_r3_3 != 0) temp_r3_3->v1();
temp_r3_4 = *(ObjVoid **)(p + 0x2584);
if (temp_r3_4 != 0) temp_r3_4->v1();
temp_f1 = *(float *)(p + 0x269C);
if (temp_f1 < lbl_80561CDC) {
*(float *)(p + 0x269C) = (float) (temp_f1 + lbl_80561D9C);
} else {
var_f2 = *(float *)(p + 0x2690);
temp_f0 = lbl_80561EE0 + *(float *)(p + 0x2694);
if (var_f2 < temp_f0) {

} else {
var_f2 = temp_f0;
}
*(float *)(p + 0x2694) = var_f2;
}
if (&sp14 == (void *)(p + 0x16C)) {
temp_f6 = *(float *)(p + 0x170);
temp_f0_2 = *(float *)(p + 0x16C);
temp_f7 = *(float *)(p + 0x174);
sp14 = (temp_f7 * *(float *)(p + 0x44)) + ((temp_f0_2 * *(float *)(p + 0x3C)) + (temp_f6 * *(float *)(p + 0x40)));
sp18 = (temp_f7 * *(float *)(p + 0x50)) + ((temp_f0_2 * *(float *)(p + 0x48)) + (temp_f6 * *(float *)(p + 0x4C)));
sp1C = (temp_f7 * *(float *)(p + 0x5C)) + ((temp_f0_2 * *(float *)(p + 0x54)) + (temp_f6 * *(float *)(p + 0x58)));
} else {
sp14 = (*(float *)(p + 0x174) * *(float *)(p + 0x44)) + ((*(float *)(p + 0x16C) * *(float *)(p + 0x3C)) + (*(float *)(p + 0x170) * *(float *)(p + 0x40)));
sp18 = (*(float *)(p + 0x174) * *(float *)(p + 0x50)) + ((*(float *)(p + 0x16C) * *(float *)(p + 0x48)) + (*(float *)(p + 0x170) * *(float *)(p + 0x4C)));
sp1C = (*(float *)(p + 0x174) * *(float *)(p + 0x5C)) + ((*(float *)(p + 0x16C) * *(float *)(p + 0x54)) + (*(float *)(p + 0x170) * *(float *)(p + 0x58)));
}
temp_f5 = sp14 * lbl_80561DE4;
temp_f7_2 = sp18 * lbl_80561DE4;
temp_f6_2 = sp1C * lbl_80561DE4;
sp14 = temp_f5;
sp18 = temp_f7_2;
sp1C = temp_f6_2;
temp_f9 = *(float *)(p + 0x266C);
temp_f11 = *(float *)(p + 0x2670);
temp_f24 = *(float *)(p + 0x2674);
temp_f10 = *(float *)(p + 0x2654);
temp_f8 = temp_f7_2 + (temp_f11 * lbl_80561E5C);
temp_f0_3 = *(float *)(p + 0x265C);
temp_f2 = temp_f6_2 + (temp_f24 * lbl_80561E5C);
temp_f25 = *(float *)(p + 0x2658);
temp_f27 = *(float *)(p + 0x2660);
temp_f5_2 = temp_f5 + (temp_f9 * lbl_80561E5C) + (temp_f10 * lbl_80561D90);
temp_f29 = *(float *)(p + 0x2664);
spC = temp_f8;
temp_f1_2 = temp_f8 + (temp_f25 * lbl_80561D90);
temp_f31 = *(float *)(p + 0x2668);
temp_f28 = temp_f5_2 + (temp_f27 * lbl_80561EE4);
sp8 = temp_f5_2;
temp_f8_2 = temp_f11 * lbl_80561EE8;
temp_f9_2 = temp_f9 * lbl_80561EE8;
sp10 = temp_f2;
temp_f30 = temp_f1_2 + (temp_f29 * lbl_80561EE4);
temp_f26 = temp_f2 + (temp_f0_3 * lbl_80561D90);
spC = temp_f1_2;
temp_f11_2 = temp_f10 + (temp_f28 * lbl_80561D9C);
*(float *)(p + 0x2654) = temp_f11_2;
temp_f10_2 = temp_f25 + (temp_f30 * lbl_80561D9C);
*(float *)(p + 0x2658) = temp_f10_2;
var_f3 = lbl_80561EF0;
temp_f13 = temp_f26 + (temp_f31 * lbl_80561EE4);
*(float *)(p + 0x2674) = (float) (temp_f24 * lbl_80561EE8);
*(float *)(p + 0x266C) = temp_f9_2;
*(float *)(p + 0x2664) = (float) (temp_f29 + (temp_f10_2 * lbl_80561D9C));
var_f2_2 = temp_f0_3 + (temp_f13 * lbl_80561D9C);
*(float *)(p + 0x2670) = temp_f8_2;
*(float *)(p + 0x2660) = (float) (temp_f27 + (temp_f11_2 * lbl_80561D9C));
*(float *)(p + 0x265C) = var_f2_2;
temp_f0_4 = temp_f31 + (var_f2_2 * lbl_80561D9C);
sp10 = temp_f26;
sp8 = temp_f28;
*(float *)(p + 0x2668) = temp_f0_4;
spC = temp_f30;
sp10 = temp_f13;
*(float *)(p + 0x266C) = (float) (temp_f9_2 + (sp14 * lbl_80561EEC));
*(float *)(p + 0x2674) = (float) lbl_80561CAC;
*(float *)(p + 0x2670) = (float) (temp_f8_2 + (sp18 * lbl_80561EEC));
*(float *)(p + 0x2670) = (float) lbl_80561CAC;
if (temp_f0_4 < lbl_80561EF4) {
*(float *)(p + 0x2668) = (float) lbl_80561EF4;
if (var_f2_2 > lbl_80561CAC) {

} else {
var_f2_2 = lbl_80561CAC;
}
*(float *)(p + 0x265C) = var_f2_2;
}
temp_f0_5 = *(float *)(p + 0x2668);
if (var_f3 < temp_f0_5) {

} else {
var_f3 = temp_f0_5;
}
*(float *)(p + 0x2668) = var_f3;
}
#pragma opt_propagation reset
#pragma cplusplus reset

int fn_80188E24(void) { return 0; }

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
void fn_80189C64(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x26AC) != 0) {
        *(unsigned char *)((char *)arg0 + 0x26AC) = 0;
        fn_801BF1B8(*(int *)((char *)arg0 + 0x1EC), *(unsigned char *)((char *)arg0 + 0x26AC));
    }
    *(float *)((char *)arg0 + 0x26A8) = lbl_80561CAC;
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
    int word0, word1, word2, word3, word4, word5;
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
    if (&out[0] == &scale[0]) {
        out[0] = temp_f7 * ((volatile float *)matrix)[6] + (temp_f1 * ((volatile float *)matrix)[0] + temp_f6 * ((volatile float *)matrix)[3]);
        out[1] = temp_f7 * ((volatile float *)matrix)[7] + (temp_f1 * ((volatile float *)matrix)[1] + temp_f6 * ((volatile float *)matrix)[4]);
        out[2] = temp_f7 * ((volatile float *)matrix)[8] + (temp_f1 * ((volatile float *)matrix)[2] + temp_f6 * ((volatile float *)matrix)[5]);
    } else {
        out[0] = temp_f7 * ((volatile float *)matrix)[6] + (temp_f1 * ((volatile float *)matrix)[0] + temp_f6 * ((volatile float *)matrix)[3]);
        out[1] = temp_f7 * ((volatile float *)matrix)[7] + (temp_f1 * ((volatile float *)matrix)[1] + temp_f6 * ((volatile float *)matrix)[4]);
        out[2] = temp_f7 * ((volatile float *)matrix)[8] + (temp_f1 * ((volatile float *)matrix)[2] + temp_f6 * ((volatile float *)matrix)[5]);
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
void fn_8018A088(void) {

}

void fn_8018A08C(void *arg0) {
    *(float *)((unsigned char *)arg0 + 0x26d8) = lbl_8055E3C8;
}

#pragma paired_single off
#pragma dont_inline on
void fn_8018A098(void *arg0, float arg1) {
    float temp_f3;
    *((unsigned char *)arg0 + 0x259d) = 1;
    temp_f3 = *(float *)((unsigned char *)arg0 + 0x2cc) * fn_80181AEC();
    *(float *)((unsigned char *)arg0 + 0x258c) =
        *(float *)((unsigned char *)arg0 + 0x3a0) *
        (temp_f3 + arg1 * (lbl_80434930[0] - temp_f3));
}
#pragma dont_inline reset
#pragma paired_single reset
int fn_8018A100(void *arg0) {
    return *(float *)((unsigned char *)arg0 + 0x2618) > lbl_80434930[1];
}

#pragma cplusplus on
extern "C" void fn_8018A120(void* arg0) {
    if (fn_801B2F2C(*(int*)((u8*)arg0 + 0x1EC)) == 0) {
        struct Obj {
            virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
            virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
            virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
            virtual int v12();
        };
        Obj* obj = *(Obj**)((u8*)arg0 + 0x2584);
        *(float*)((u8*)arg0 + 0x25BC) = lbl_8055E4E0;
        obj->v12();
    }
}
#pragma cplusplus off
void fn_8018A174(void *arg0) {
    *(float *)((unsigned char *)arg0 + 0x2650) = lbl_80561D2C;
}

#pragma cplusplus on
extern "C" void fn_8018A180(void *arg0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11) {
    class Driver {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual v4(); virtual v5(); virtual v6(); virtual v7();
        virtual void v8(); virtual void v9(); virtual void v10();
        virtual int slot34();
        virtual int slot38();
    };
    int value;
    float z;
    float y;
    float x;
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
    *(volatile float *)((char *)arg0 + 0xD4) = x;
    *(float *)((char *)arg0 + 0xE4) = lbl_80561CD0 / x;
    fn_801BDA74(*(volatile int *)((char *)arg0 + 0x1EC), (void *)((unsigned int)arg0 + 0x32C), x);
    value = *(int *)((char *)arg0 + 0x1EC);
    fn_801D11D8((char *)lbl_8055E908 + value * 0x34);
    value = *(int *)((char *)arg0 + 0x1EC);
    fn_801D1540((char *)lbl_8055E918 + value * 0x9C);
}
#pragma cplusplus reset
void fn_8018A2BC(void) {

}

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
extern "C" void fn_8018A2C0(void *arg0, void **arg1) {
    struct Obj {
        virtual void v0(void *, void *, int *, float, float, float);
    };
    register char *base = (char *)arg0;
    register char *names = lbl_803322B0;
    register char *offset = base + 0x32C;
    register int *style0 = &lbl_8055A3F8;
    register int *initial_style = &lbl_8055A3FC;
    register int *style1 = &lbl_8055A400;
    register int *style2 = &lbl_8055A408;
    register int *style3 = &lbl_8055A410;
    register int *initial_name = &lbl_8055A418;
    register Obj *obj = (Obj *)arg1;

    obj->v0(initial_name, offset, initial_style, lbl_80561CE4, lbl_80561F0C, lbl_80561F10);
    obj->v0(names + 0x350, offset + 8, style1, lbl_80561CE4, lbl_80561D68, lbl_80561F10);
    obj->v0(names + 0x35C, offset + 4, style1, lbl_80561CE4, lbl_80561D68, lbl_80561F10);
    obj->v0(names + 0x36C, offset + 0xC, style1, lbl_80561CE4, lbl_80561D68, lbl_80561F10);
    obj->v0(names + 0x378, base + 0x2DC, &lbl_8055A420, lbl_80561D00, lbl_80561D44, lbl_80561D0C);
    obj->v0(names + 0x388, offset + 0x30, &lbl_8055A420, lbl_80561CDC, lbl_80561CEC, lbl_80561D0C);
    obj->v0(names + 0x394, base + 0x5A8, &lbl_8055A424, lbl_80561D34, lbl_80561D28, lbl_80561CD0);
    obj->v0(names + 0x3A4, offset + 0x18, style0, lbl_80561D00, lbl_80561CF8, lbl_80561CCC);
    obj->v0(names + 0x3B0, offset + 0x10, style0, lbl_80561D00, lbl_80561CF8, lbl_80561CCC);
    obj->v0(names + 0x3BC, offset + 0x14, style0, lbl_80561D00, lbl_80561CF8, lbl_80561CCC);
    obj->v0(names + 0x3C8, offset + 0x20, style0, lbl_80561DE4, lbl_80561CD0, lbl_80561CCC);
    obj->v0(names + 0x3D4, offset + 0x80, style0, lbl_80561CAC, lbl_80561CD0, lbl_80561CCC);
    obj->v0(names + 0x3E4, offset + 0xC8, style0, lbl_80561CAC, lbl_80561CD0, lbl_80561CCC);
    obj->v0(names + 0x3F0, offset + 0x84, style2, lbl_80561EBC, lbl_80561D68, lbl_80561F14);
    obj->v0(names + 0x400, offset + 0xCC, style2, lbl_80561EBC, lbl_80561D68, lbl_80561F14);
    obj->v0(names + 0x410, offset + 0x8C, style3, lbl_80561F14, lbl_80561F18, lbl_80561F10);
    obj->v0(names + 0x420, offset + 0xD4, style3, lbl_80561F14, lbl_80561F18, lbl_80561F10);
    obj->v0(names + 0x430, offset + 0x110, &lbl_8055A42C, lbl_80561D00, lbl_80561D44, lbl_80561D00);
    obj->v0(names + 0x43C, offset + 0x114, &lbl_8055A420, lbl_80561D00, lbl_80561CEC, lbl_80561D00);
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

void fn_8018A6F4(void *arg0) {
    int temp = *(int *)((unsigned char *)arg0 + 0x26c8);
    if (temp != 0) fn_801C1C7C(temp);
    if (*(int *)((unsigned char *)arg0 + 0x26c4) != 0) fn_801C1C7C(*(int *)((unsigned char *)arg0 + 0x26c4));
    if (*(int *)((unsigned char *)arg0 + 0x26c0) != 0) fn_801D21B4(*(int *)((unsigned char *)arg0 + 0x26c0));
}

void fn_8018A750(void *arg0, int arg_sp0) {
    int count;
    int i;
    int j;
    int k;
    int n;
    int *indices;
    void **entries;
    float *vec;
    float *pts;
    float temp;
    char *base = (char *)arg0;
    count = *(int *)(base + 0x26C4);
    if (count != 0) fn_801C2170(count, *(void **)(base + 0x26C0), base + 0x70);
    if (*(int *)(base + 0x26C8) != 0) {
        count = *(int *)(*(char **)(base + 0x26C0) + 0xC8);
        if (count > 0) {
            vec = (float *)((char *)&arg_sp0 + 0x70);
            pts = (float *)((char *)&arg_sp0 + 0x30);
            indices = (int *)((char *)&arg_sp0 - 0x18);
            entries = (void **)((char *)&arg_sp0 - 0x58);
            for (i = 0, j = 0, k = 0; i < count; i++, j += 2, k += 8) {
                float *p = (float *)((char *)&arg_sp0 + 0x70 + i * 0x28);
                p[0] = *(float *)(base + 0x94);
                p[1] = *(float *)(base + 0x98);
                p[2] = *(float *)(base + 0x9C);
                p[3] = lbl_80561CD0;
                p[4] = lbl_80561CDC;
                p[5] = p[0];
                p[6] = p[1];
                p[7] = p[2];
                p[8] = lbl_80561CD0;
                p[9] = lbl_80561CDC;
                *(int *)((char *)pts + i * 16) = j;
                *(int *)((char *)pts + i * 16 + 4) = j + 1;
                *(float *)((char *)pts + i * 16 + 8) = lbl_80561CAC;
                *(float *)((char *)pts + i * 16 + 12) = lbl_80561CD0 - *(float *)((char *)*(void **)(base + 0x26C0) + 0xA8 + k);
                *(int *)((char *)entries + i * 12) = j;
                *(void **)((char *)entries + i * 12 + 4) = base + 0x70;
                *(int *)((char *)entries + i * 12 + 8) = 0;
            }
        }
        fn_801C1CBC(*(int *)(base + 0x26C8), count * 2, (void *)((char *)&arg_sp0 + 0x70), (void *)((char *)&arg_sp0 + 0x30), count, (void *)((char *)&arg_sp0 - 0x58));
    }
}

#pragma paired_single off
#pragma scheduling invalid_target
void fn_8018A8A8(void *arg0) {
    struct {
        float sp8[3];
        float sp14[3];
        float sp20[3];
        float sp2C[3];
        float sp38[3];
    } stack;
    float angle;
    float value;
    float calculated;
    register float temp_f31;
    register float temp_f30;

    stack.sp38[0] = lbl_80561CAC;
    stack.sp38[1] = lbl_80561DBC;
    stack.sp38[2] = lbl_80561CAC;
    stack.sp2C[0] = lbl_80561CAC;
    stack.sp2C[1] = lbl_80561CD0;
    stack.sp2C[2] = lbl_80561CAC;
    stack.sp20[0] = lbl_80561CAC;
    stack.sp20[1] = lbl_80561CAC;
    stack.sp20[2] = lbl_80561CAC;
    if (*(int *)((char *)arg0 + 0x26C4) != 0) {
        temp_f31 = lbl_8055E3C8;
        angle = (float)fn_8002EFB4(temp_f31, lbl_80561F20);
        value = angle - lbl_80561D00;
        temp_f30 = lbl_80561F28 * value;
        angle = (float)fn_8002EFB4(temp_f31, lbl_80561F30);
        value = angle - lbl_80561F3C;
        calculated = lbl_80561F38 * value;
        angle = (float)fn_8002EFB4(temp_f31, lbl_80561F40);
        stack.sp14[1] = calculated;
        value = angle - lbl_80561F4C;
        stack.sp14[2] = temp_f30;
        stack.sp14[0] = lbl_80561F48 * value;
        fn_801C27D8(*(void **)((char *)arg0 + 0x26C4), stack.sp38, stack.sp2C, stack.sp14, stack.sp20);
    }
    if (*(int *)((char *)arg0 + 0x26C8) != 0) {
        stack.sp8[0] = *(float *)((char *)arg0 + 0x118) * lbl_80561F50;
        stack.sp8[1] = *(float *)((char *)arg0 + 0x11C) * lbl_80561F50;
        stack.sp8[2] = *(float *)((char *)arg0 + 0x120) * lbl_80561F50;
        fn_801C27D8(*(void **)((char *)arg0 + 0x26C8), stack.sp38, stack.sp2C, stack.sp8, stack.sp20);
    }
}
#pragma scheduling on
#pragma paired_single reset

extern void fn_801C2BDC(void *, unsigned int *, unsigned int *, unsigned int *);
void fn_8018A9F0(void *arg0, void *arg1) {
    float sp54, sp50, sp4C, sp48, sp44, sp40, sp3C, sp38, sp34, sp30, sp2C;
    int sp28, sp24, sp20, sp1C, sp18, sp14;
    void *sp10;
    float spC, sp8;
    float temp_f1, temp_f6, temp_f6_2, temp_f7, temp_f7_2, temp_f8, temp_f8_2;
    int temp_r0, temp_r3, temp_r3_2, var_r3, var_r5, var_r6, var_r6_2, var_r7;
    void *temp_r3_3, *temp_r3_4, *temp_r3_5, *temp_r3_6, *temp_r3_7;
    void *temp_r4, *temp_r4_2, *temp_r4_3, *temp_r4_4, *temp_r5;

    if (*(int *)((char *)arg0 + 0x26C4) != 0) {
        sp28 = 0; sp24 = 0; sp20 = 0;
        fn_801C2BDC(*(void **)((char *)arg0 + 0x26C4), (unsigned int *)&sp20, (unsigned int *)&sp28, (unsigned int *)&sp24);
        var_r6 = 0;
        if (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xA4) > 0) {
            var_r5 = 0;
            do {
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
            } while (var_r6 < *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xA4));
        }
    }

    if (*(int *)((char *)arg0 + 0x26C8) != 0) {
        sp1C = 0; sp18 = 0; sp14 = 0;
        fn_801C2BDC(*(void **)((char *)arg0 + 0x26C8), (unsigned int *)&sp14, (unsigned int *)&sp1C, (unsigned int *)&sp18);
        var_r7 = 0;
        if (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xC8) > 0) {
            var_r3 = 0xC; var_r6_2 = 0;
            do {
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
            } while (var_r7 < *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xC8));
        }
    }

    sp10 = 0;
    fn_801BEB30(*(int *)((char *)arg0 + 0x1EC), (int *)&sp10);
    sp44 = *(float *)((char *)sp10 + 0x7C);
    sp8 = sp44;
    sp38 = *(float *)((char *)sp10 + 0x70);
    sp3C = *(float *)((char *)sp10 + 0x74);
    sp40 = *(float *)((char *)sp10 + 0x78);
    spC = sp8;
    sp48 = sp38; sp4C = sp3C; sp50 = sp40; sp54 = spC; sp2C = sp38;
    temp_r3_4 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xCC) * 0xC);
    sp30 = sp3C;
    *(float *)((char *)temp_r3_4 + 0xE24) = lbl_80561CAC;
    *(float *)((char *)temp_r3_4 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x80) + (float)sp38);
    *(float *)((char *)temp_r3_4 + 0xE2C) = lbl_80561CAC;
    sp34 = sp40;
    temp_r3_5 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD0) * 0xC);
    *(float *)((char *)temp_r3_5 + 0xE24) = lbl_80561CAC;
    *(float *)((char *)temp_r3_5 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0xEC) + (float)sp4C);
    *(float *)((char *)temp_r3_5 + 0xE2C) = lbl_80561CAC;
    temp_r3_6 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD4) * 0xC);
    *(float *)((char *)temp_r3_6 + 0xE24) = lbl_80561CAC;
    *(float *)((char *)temp_r3_6 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x158) + (float)sp50);
    *(float *)((char *)temp_r3_6 + 0xE2C) = lbl_80561CAC;
    temp_r3_7 = (char *)arg1 + (*(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xD8) * 0xC);
    *(float *)((char *)temp_r3_7 + 0xE24) = lbl_80561CAC;
    *(float *)((char *)temp_r3_7 + 0xE28) = *(float *)((char *)arg0 + 0x5AC) + (*(float *)((char *)arg1 + 0x1C4) + (float)sp54);
    *(float *)((char *)temp_r3_7 + 0xE2C) = lbl_80561CAC;
    *(int *)((char *)arg1 + 0xFA4) = *(int *)(*(char **)((char *)arg0 + 0x26C0) + 0xDC);
}

void fn_8018ADA4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25DC) = farg0; }

void fn_8018ADAC(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25DC) = farg0; }

void fn_8018ADB4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E0) = farg0; }

void fn_8018ADBC(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E4) = farg0; }

void fn_8018ADC4(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x25E8) = farg0; }

void fn_8018ADCC(void *arg0, float arg1) {
    *(float *)((unsigned char *)arg0 + 0x25EC) = arg1;
}

void fn_8018ADD4(void *arg0, int arg1) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C) + 8) = arg1;
}

extern int lbl_8055E918;
void fn_8018ADEC(void *arg0) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C) + 8) = -10;
}

void fn_8018AE08(void *arg0) {
    *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C) + 8) = -10;
}

void fn_8018AE24(void *arg0, signed char arg1) {
    *((signed char *)arg0 + 0x260D) = arg1;
}

void fn_8018AE2C(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x2600) = farg0; }

void fn_8018AE34(void *arg0, f32 farg0) { *(f32 *)((u8 *)arg0 + 0x2604) = farg0; }

extern f32 fn_8018AE3C(void);
f32 fn_8018AE3C(void) {
    return lbl_80561CAC;
}

extern f32 fn_8018AE44(void);
f32 fn_8018AE44(void) {
    return lbl_80561CAC;
}

extern f32 fn_8018AE4C(void);
f32 fn_8018AE4C(void) {
    return lbl_80561CAC;
}

extern f32 fn_8018AE54(void);
f32 fn_8018AE54(void) {
    return lbl_80561CAC;
}

char *fn_8018AE5C(void) {
    if (lbl_8055E4F8 == 0) {
        lbl_8055E4F8 = 1;
    }
    return lbl_80434990;
}

float fn_8018AE7C(void *arg0) {
    void *table = __AXFXGetLfoSinTable_801769CC();
    if (*(u32 *)((u8 *)table + 4) - 0x00180000U == 0x304U) {
        return lbl_80561DE0;
    }
    if (!(*(float *)((u8 *)arg0 + 0x25bc) <= lbl_80558DC4)) {
        return lbl_80561DE0;
    }
    if (*(float *)((u8 *)arg0 + 0xd4) > lbl_80561F28) {
        return lbl_80561DE0;
    }
    return lbl_80561CDC;
}

void fn_8018AF00(void) {

}

extern int fn_801CF064(void);
extern void fn_801BEB30();
extern int *fn_801E1F44(void);
extern void fn_8018F6F8(void *);
int fn_8018AF04(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    void *obj;
    float x = *(float *)(p + 0x23E8);
    float y = *(float *)(p + 0x245C);
    float z = *(float *)(p + 0x24D0);
    float w = *(float *)(p + 0x2544);
    int a = *(int *)(p + 0x241C) & ~8;
    int b = *(int *)(p + 0x2490) & ~8;
    int c = *(int *)(p + 0x2504) & ~8;
    int d = *(int *)(p + 0x2578) & ~8;
    fn_8018F2C0(arg0, p + (fn_801CF064() == 0 ? 0x1E44 : 0x20F8));
    *(int *)(p + 0x241C) = a;
    *(int *)(p + 0x2490) = b;
    *(int *)(p + 0x2504) = c;
    *(int *)(p + 0x2578) = d;
    fn_801BEB30(*(int *)(p + 0x1EC), &obj, c, b, a, w, z, y);
    *(float *)((unsigned char *)obj + 0x70) = x;
    *(float *)((unsigned char *)obj + 0x74) = y;
    *(float *)((unsigned char *)obj + 0x78) = z;
    *(float *)((unsigned char *)obj + 0x7C) = w;
    *(float *)((unsigned char *)obj + 0x130) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x134) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x138) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x13C) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x140) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x144) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x148) = lbl_80561CAC;
    *(float *)((unsigned char *)obj + 0x14C) = lbl_80561CAC;
    if (*(int *)(p + 0x26B0) >= 0) {
        *(int *)(p + 0x26B0) = -1;
        *(int *)(p + 0x1E40) = 0;
        if (*fn_801E1F44() == 1)
            fn_8018F6F8(arg0);
        *(float *)(p + 0x2650) = lbl_80561CAC;
        *(float *)(p + 0x264C) = lbl_80561CAC;
        *(float *)(p + 0x25C4) = lbl_80561CAC;
    }
}

int fn_8018B06C(void *arg0) {
    return *(int *)((unsigned char *)lbl_8055E918 +
                    *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C + 0x14);
}

int fn_8018B084(void *arg0) {
    return *(int *)((unsigned char *)(lbl_8055E918 + *(int *)((unsigned char *)arg0 + 0x1EC) * 0x9C) + 0x20);
}

void fn_8018B09C(void *arg0) {
    fn_8017D2C8();
    *(float *)((unsigned char *)arg0 + 0x26dc) = lbl_8055E3C8;
}

void fn_8018B0D0(void *arg0, int arg1) {
    *(int *)((unsigned char *)arg0 + 0x2610) = arg1;
}

extern void fn_8017D274(void);
extern int fn_801363A0(int);
extern float lbl_80561F54, lbl_80561F58, lbl_80561F5C, lbl_80561F60;
extern float lbl_80561F64, lbl_80561F68, lbl_80561F6C;
extern float lbl_80561CD0, lbl_80561CDC, lbl_80561D28, lbl_80561D34;
extern float lbl_80561E60, lbl_80561EE4;
#pragma cplusplus on
#pragma scheduling invalid_target
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
    middle1 = lbl_80561CAC + scaled1;
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
void fn_8018BDEC(void *arg0) {
    f32 sp[12];
    f32 *matrix = sp;
    register f32 zero = *(volatile f32 *)&lbl_80561CAC;
    register f32 one = lbl_80561CD0;
    int value;
    sp[0]=one; sp[1]=zero; sp[2]=zero; sp[3]=zero;
    sp[4]=one; sp[5]=zero; sp[6]=zero; sp[7]=zero;
    sp[8]=one; sp[9]=zero; sp[10]=zero; sp[11]=zero;
    value=*(int *)((u8 *)arg0+0x26C4);
    if(value) fn_801C2BF8(value,matrix);
}

extern float __fabsf(float);
#pragma push
#pragma small_data off
__declspec(section ".data") extern float lbl_80558DC4;
extern void fn_801A1474(void *, float);
void fn_8018BE54(void *arg0, float farg0) {
    float temp_f10, temp_f11, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, temp_f9;
    char *p = (char *)arg0;
    float diff = *(float *)(p + 0x5E4) - farg0;
    if (!(__fabsf(diff) <= lbl_80558DC4)) {
        *(float *)(p + 0x5E4) = farg0;
        fn_801A1474((void *)*(int *)(p + 0x268), farg0);
        temp_f11 = *(float *)(p + 0x5E4);
        temp_f6 = temp_f11 * temp_f11;
        temp_f7 = *(float *)(p + 0x47C) * temp_f11;
        temp_f10 = *(float *)(p + 0x468) * temp_f6;
        temp_f9 = *(float *)(p + 0x46C) * temp_f6;
        temp_f8 = *(float *)(p + 0x470) * temp_f6;
        temp_f5 = *(float *)(p + 0x478) * temp_f11;
        temp_f4 = *(float *)(p + 0x484) * temp_f11;
        temp_f6 = *(float *)(p + 0x474) * temp_f11;
        temp_f3 = temp_f11 * *(float *)(p + 0x4E4);
        temp_f2 = temp_f11 * *(float *)(p + 0x508);
        *(float *)(p + 0x330) = temp_f10;
        temp_f1 = temp_f11 * *(float *)(p + 0x52C);
        *(float *)(p + 0x334) = temp_f9;
        *(float *)(p + 0x338) = temp_f8;
        *(float *)(p + 0x344) = temp_f7;
        *(float *)(p + 0x33C) = temp_f6;
        *(float *)(p + 0x340) = temp_f5;
        *(float *)(p + 0x34C) = temp_f4;
        *(float *)(p + 0x3AC) = temp_f3;
        *(float *)(p + 0x3D0) = temp_f2;
        *(float *)(p + 0x3F4) = temp_f1;
        *(float *)(p + 0x418) = temp_f11 * *(float *)(p + 0x550);
        ((void (*)(void *))fn_8018A180)(arg0);
    }
}
#pragma pop
void fn_8018BF44(int *arg0) { *arg0 = 0x0FF807FF; }

int fn_8018BF54(void) { return 0; }

void fn_8018BF5C(void) {

}

void fn_8018BF60(void) {

}

int fn_8018BF64(void) { return 0x44; }
extern int fn_80128668(void);
extern void fn_8017A580(int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
extern void fn_801838C8(void *);
extern int fn_801769C4(void);
extern void fn_80181EAC(int);
extern void fn_8018F538(void *);
extern void fn_80279B28(int, void *);
extern void fn_80279C00(int, void *);
extern void fn_8017B0B0(void);
extern void fn_801BD808(void *);
extern int lbl_8055E4D0;
extern float lbl_80561CA0, lbl_80561CA4, lbl_80561CA8;
extern float lbl_80561CB0, lbl_80561CB4, lbl_80561CB8, lbl_80561CBC;
