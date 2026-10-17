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
    int a = p[0x274 / 4];
    int b = p[0x278 / 4];
    int c = p[0x27C / 4];
    int d = p[0x280 / 4];
    int e = p[0x284 / 4];
    int f = p[0x288 / 4];
    int g = p[0x28C / 4];
    int h = p[0x290 / 4];
    int i = p[0x294 / 4];
    int j = p[0x298 / 4];
    int k = p[0x29C / 4];
    int l = p[0x2A0 / 4];
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
        fn_801BF1B8(*(int *)((char *)arg0 + 0x1EC), (*(unsigned char *)((char *)arg0 + 0x26AC) = 0, 0));
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
    void *object;
    void **vtable;
    void (*method)(void *);
    if (fn_801B2F2C(*(int *)((unsigned char *)arg0 + 0x1ec)) == 0) {
        object = *(void **)((unsigned char *)arg0 + 0x2584);
        *(float *)((unsigned char *)arg0 + 0x25bc) = lbl_8055E4E0;
        vtable = *(void ***)object;
        method = *(void (**)(void *))((unsigned char *)vtable + 0x38);
        method(object);
    }
}

void fn_8018A2BC(void) {

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
    if (*(u32 *)((u8 *)table + 4) - 0x18000000U == 0x304U) {
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
    int index = *(int *)((unsigned char *)arg0 + 0x1ec);
    return ((int *)lbl_8055E918)[index * 0x9c / 4 + 8];
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
