// Code of main that had no source file yet: decomp.wtf gave it this one.
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
extern int lbl_80332478;
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
extern void fn_8018185C(float *, float, float, float, float, float, float);
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
void fn_801819A0(int unused, void *arg1, float scale, float farg1, float farg2) {
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;
    float temp_f1;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f7;
    float temp_f8;
    temp_f7 = *((float *)((unsigned char *)arg1 + 0x50)) * scale;
    temp_f8 = (*((float *)((unsigned char *)arg1 + 0x54)) * scale) / lbl_80561CC4;
    temp_f5 = *((float *)((unsigned char *)arg1 + 0x5c));
    temp_f6 = temp_f7 / lbl_80561CC8;
    temp_f4 = *((float *)((unsigned char *)arg1 + 0x58));
    sp18 = *((float *)((unsigned char *)arg1 + 0x68));
    sp1C = *((float *)((unsigned char *)arg1 + 0x60));
    temp_f1 = temp_f5 * farg2;
    sp8 = temp_f8;
    sp10 = temp_f6;
    spC = temp_f1;
    sp14 = temp_f4 * farg1;
    fn_8018185C(&sp8, temp_f1, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8);
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

extern float lbl_80561D38;
extern float lbl_80561D3C;
extern float lbl_80561D0C;
extern float lbl_80561CFC;
extern float fn_80129DC4(int, float, float);
extern float fn_802798E8(int);
extern void fn_802799EC(int, float);
void fn_80181EAC(int arg0) {
    float temp_f1;
    float temp_f30;
    float temp_f31;
    temp_f30 = fn_80129DC4(4, lbl_80561D38, lbl_80561D3C);
    temp_f31 = fn_80129DC4(4, lbl_80561D0C, lbl_80561CFC);
    temp_f1 = fn_802798E8(arg0);
    if (temp_f1 <= temp_f30) return;
    if (temp_f1 <= temp_f31) return;
    fn_802799EC(arg0, temp_f1 - temp_f31);
}

void fn_80181F30(void) {
    unsigned int bits = *(unsigned int *)((unsigned char *)__AXFXGetLfoSinTable_801769CC() + 4);
    signed char mode = (bits >> 19) & 1;
    lbl_8055E4D0 = 0;
    lbl_8055E4F4 = mode;
    fn_801BD694(8, mode);
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
extern int lbl_803326F8;
extern int lbl_8055E4D0;
void *fn_80182010(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    fn_8017B0B0();
    *(int **)p = &lbl_803326F8;
    *(short *)(p + 0x2B4) = -1;
    fn_801BD808(&lbl_803326F8);
    ((void **)lbl_804348E8)[lbl_8055E4D0] = arg0;
    lbl_8055E4D0++;
    return arg0;
}

void fn_801836DC(void) {

}

int fn_801837DC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8018381C(void *arg0) {
    volatile int *p = (volatile int *)arg0;
    int l = p[0x2A0 / 4];
    int k = p[0x29C / 4];
    int j = p[0x298 / 4];
    int i = p[0x294 / 4];
    int h = p[0x290 / 4];
    int g = p[0x28C / 4];
    int f = p[0x288 / 4];
    int e = p[0x284 / 4];
    int d = p[0x280 / 4];
    int c = p[0x27C / 4];
    int b = p[0x278 / 4];
    int a = p[0x274 / 4];
    p[0x3C / 4] = a; p[0x40 / 4] = b; p[0x44 / 4] = c; p[0x48 / 4] = d;
    p[0x4C / 4] = e; p[0x50 / 4] = f; p[0x54 / 4] = g; p[0x58 / 4] = h;
    p[0x5C / 4] = i; p[0x60 / 4] = j; p[0x64 / 4] = k; p[0x68 / 4] = l;
    fn_8017A580(k, j, i, h, g, f, e);
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
void fn_80186DE8(void) {
    int sp78;
    int sp84;
    int sp88;
    int sp80;
    int sp7C;
    int i;
    int count;
    int *table;
    float f18, f14, f15;
    void *r18;

    fn_80190E6C();
    if (fn_801C5B60() != 0) return;
    fn_80196A9C();
    fn_801C56AC();
    r18 = *fn_801B83A0();
    ((void (*)(void))r18)();
    sp78 = 0;
    fn_801BEDA8(&sp88, &sp84, &sp80, &sp7C, &sp78);
    table = (int *)lbl_804348E8;
    f18 = lbl_80561CAC;
    f14 = lbl_80561D34;
    f15 = lbl_80561CE4;
    i = 0;
    count = 0;
    while (i < 1) {
        r18 = (void *)table[0];
        fn_80183E7C(r18);
        if (*((float *)r18 + 0x4C / 4) >= f18) {
            /* body */
        }
        table += 1;
        i += 0xB0;
        count += 1;
    }
    fn_801BEDD4();
}

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
void fn_80189C64(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x26AC) != 0) {
        *(unsigned char *)((char *)arg0 + 0x26AC) = 0;
        fn_801BF1B8(*(int *)((char *)arg0 + 0x1EC), *(unsigned char *)((char *)arg0 + 0x26AC));
    }
    *(float *)((char *)arg0 + 0x26A8) = lbl_80561CAC;
}

void fn_8018A088(void) {

}

void fn_8018A08C(void *arg0) {
    *(float *)((unsigned char *)arg0 + 0x26d8) = lbl_8055E3C8;
}

#pragma dont_inline fn_80181AEC
void fn_8018A098(void *arg0, float arg1) {
    float temp_f3;
    *(signed char *)((unsigned char *)arg0 + 0x259d) = 1;
    temp_f3 = *(float *)((unsigned char *)arg0 + 0x2cc) * fn_80181AEC();
    *(float *)((unsigned char *)arg0 + 0x258c) =
        *(float *)((unsigned char *)arg0 + 0x3a0) *
        (temp_f3 + arg1 * (lbl_80434930[0] - temp_f3));
}
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

void fn_8018A180(void *arg0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11) {
    int value;
    float x, y, z;
#pragma unused(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)
    value = *(int *)((char *)arg0 + 0x328);
    if (value != 0) {
        fn_80279B28(value, (char *)arg0 + 0x1E44);
        fn_8018F2C0(arg0, (char *)arg0 + 0x1E44);
        if (*(int *)((char *)arg0 + 0x20DC) < 9) {
            if (((int (*)(void *))(*(void ***)*(void **)((char *)arg0 + 0x270))[14])(*(void **)((char *)arg0 + 0x270)) != 0) {
                fn_802E30C8(lbl_803325E8, *(int *)((char *)arg0 + 0x1EC));
                ((void (*)(void *))(*(void ***)*(void **)((char *)arg0 + 0x270))[13])(*(void **)((char *)arg0 + 0x270));
                fn_8018AF04(arg0);
            }
        }
    }
    x = *(float *)((char *)arg0 + 0x458); y = *(float *)((char *)arg0 + 0x45C); z = *(float *)((char *)arg0 + 0x460);
    *(float *)((char *)arg0 + 0x30) = x; *(float *)((char *)arg0 + 0x34) = y; *(float *)((char *)arg0 + 0x38) = z;
    fn_8017A57C(arg0);
    fn_8017B2D0(arg0, *(float *)((char *)arg0 + 0x32C) / lbl_80561D54,
        *(float *)((char *)arg0 + 0x330) / lbl_80561D58,
        *(float *)((char *)arg0 + 0x334) / lbl_80561D58,
        *(float *)((char *)arg0 + 0x338) / lbl_80561D58);
    x = *(float *)((char *)arg0 + 0x32C);
    *(float *)((char *)arg0 + 0xD4) = x;
    *(float *)((char *)arg0 + 0xE4) = lbl_80561CD0 / x;
    fn_801BDA74(*(int *)((char *)arg0 + 0x1EC), (char *)arg0 + 0x32C, x);
    value = *(int *)((char *)arg0 + 0x1EC);
    fn_801D11D8((char *)lbl_8055E908 + value * 0x34);
    value = *(int *)((char *)arg0 + 0x1EC);
    fn_801D1540((char *)lbl_8055E918 + value * 0x9C);
}

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
    int count;
    void *result;
    if (*(signed char *)((unsigned char *)arg1 + 0xec) != 0) {
        result = fn_801D2008((unsigned char *)arg1 + 0xec);
        *(void **)((unsigned char *)arg0 + 0x26c0) = result;
        if (*(int *)((unsigned char *)result + 0x10) > 0)
            *(int *)((unsigned char *)arg0 + 0x26c4) = fn_801C1C1C();
        else
            *(int *)((unsigned char *)arg0 + 0x26c4) = 0;
        count = *(int *)((unsigned char *)result + 0xc8);
        if (count > 0)
            *(int *)((unsigned char *)arg0 + 0x26c8) = fn_801C1BA4(count * 2, count);
        else
            *(int *)((unsigned char *)arg0 + 0x26c8) = 0;
    } else {
        *(int *)((unsigned char *)arg0 + 0x26c0) = 0;
        *(int *)((unsigned char *)arg0 + 0x26c4) = 0;
        *(int *)((unsigned char *)arg0 + 0x26c8) = 0;
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
extern void fn_801BEB30(int, void **, int, int, int, float, float, float);
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
    int index = *(int *)((unsigned char *)arg0 + 0x1ec);
    return ((int *)lbl_8055E918)[index * 0x9c / 4 + 5];
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
#pragma cplusplus reset
void fn_8018BDEC(void *arg0) {
    f32 sp[12];
    int value;
    sp[0]=lbl_80561CD0; sp[1]=lbl_80561CAC; sp[2]=lbl_80561CAC; sp[3]=lbl_80561CAC;
    sp[4]=lbl_80561CD0; sp[5]=lbl_80561CAC; sp[6]=lbl_80561CAC; sp[7]=lbl_80561CAC;
    sp[8]=lbl_80561CD0; sp[9]=lbl_80561CAC; sp[10]=lbl_80561CAC; sp[11]=lbl_80561CAC;
    value=*(int *)((u8 *)arg0+0x26C4);
    if(value) fn_801C2BF8(value,sp);
}

extern float __fabsf(float);
void fn_8018BE54(void *arg0, float farg0) {
    float temp_f10, temp_f11, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, temp_f9;
    char *p = (char *)arg0;
    float diff = *(float *)(p + 0x5E4) - farg0;
    if (__fabsf(diff) > lbl_80558DC4) {
        *(float *)(p + 0x5E4) = farg0;
        fn_801A1474(*(int *)(p + 0x268), farg0);
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
        fn_8018A180(arg0, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, temp_f9, temp_f10, temp_f11);
    }
}

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
extern int lbl_803326F8;
extern int lbl_8055E4D0;
