// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern signed char lbl_8055E4F8;
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

void fn_8018C510(void);
void __AXDSPInitCallback_801AFC38(void);
void fn_801BD790(void);
extern float lbl_80434930[];
extern float lbl_80434908[];
extern float lbl_80434950[];
extern float lbl_804348E8[];
extern unsigned char lbl_8055E4F4;
#pragma cplusplus on
struct Sub1_80181A48 {
    char pad[0x1c];
    float m_f;
    float get() const { return m_f; }
};
struct Sub2_80181A48 {
    char pad[0x34];
    float m_f;
    float get() const { return m_f; }
};
struct Big_80181A48 {
    char pad0[0x20];
    Sub1_80181A48 m_sub0;
    char pad1[0x48 - 0x20 - sizeof(Sub1_80181A48)];
    Sub1_80181A48 m_sub1;
    char pad2[0x68 - 0x48 - sizeof(Sub1_80181A48)];
    Sub2_80181A48 m_sub2;
};
#pragma cplusplus off
extern float lbl_80561CC4;
extern float lbl_80561CC8;
extern void fn_8018185C(float *, float, float, float, float, float, float);
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

void fn_8018A120(void *arg0) {
    register void *object;
    if (fn_801B2F2C(*(int *)((unsigned char *)arg0 + 0x1ec)) == 0) {
        object = *(void **)((unsigned char *)arg0 + 0x2584);
        *(float *)((unsigned char *)arg0 + 0x25bc) = lbl_8055E4E0;
        ((void (*)(void *))(*(void ***)object)[14])(object);
    }
}

void fn_8018A174(void *arg0) {
    *(float *)((unsigned char *)arg0 + 0x2650) = lbl_80561D2C;
}

void fn_8018A2BC(void) {

}

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
    volatile int *temp2;
    int temp = *(int *)((unsigned char *)arg0 + 0x26c8);
    if (temp != 0) fn_801C1C7C(temp);
    if (*(int *)((unsigned char *)arg0 + 0x26c4) != 0) fn_801C1C7C(*(int *)((unsigned char *)arg0 + 0x26c4));
    temp2 = (volatile int *)((unsigned char *)arg0 + 0x26c0);
    if (*temp2 != 0) fn_801D21B4();
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
