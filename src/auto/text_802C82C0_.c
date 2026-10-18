extern float lbl_8055FC6C;
extern float lbl_8055FC4C;
extern float lbl_8055FC40;
extern float lbl_8055D020;
extern int lbl_8055FC30;
extern int lbl_8055FC84;
extern void fn_802D08CC(void);
extern void fn_802CAD68(void);
extern int fn_802D31D8(int);
extern void fn_801E7888(int);
extern unsigned int lbl_804C1410[];
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
extern float lbl_80564EF8, lbl_80564F00;
extern void fn_802C7758(int);
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;

extern int lbl_8055FC70;
extern void fn_802CFDE0(void);
extern void fn_802CC770(void);
extern void fn_802CC60C(void);
extern void fn_802CFCA0(void);
extern int lbl_8055FC78;
extern void fn_802CFFAC(unsigned char, unsigned char, unsigned char);
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[3];
extern unsigned char lbl_8055FC8F;
extern int fn_801E4F3C(void);
extern int fn_801E4F20(void);
extern void fn_802D68C4(void);

extern int lbl_8055FC70;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern char lbl_8055FC8C;
extern char lbl_8055FC8D;
extern float lbl_8055D024;
extern float lbl_80564EFC;
extern char lbl_8034B498[];
extern int fn_80019B9C(void);
extern int fn_802E9A0C(void);
extern void fn_80133348(int, const char *, int);
extern void *lbl_8055FC90;
void fn_802C82C0(void) {
}

void* fn_802C83C4(void) {
    return lbl_8055FC90;
}

extern int fn_80133010(void);
extern void fn_801336E0(int, void (*)(void));
extern void fn_802C6080(void);
extern int lbl_8055D028;
extern int fn_802C9E94(void);
extern int fn_801E7894(int);
void fn_802C84EC(void) {
    if (fn_80133010() != 0) {
        fn_801336E0(lbl_8055D028, fn_802C82C0);
        lbl_8055D028 = -1;
    }
    fn_802C6080();
}

void fn_802C8530(void) {
    lbl_8055FC70 = 1;
    fn_802CC60C();
    fn_802CFCA0();
}

void fn_802C855C(void) {
    fn_802CFDE0();
    fn_802CC770();
    lbl_8055FC70 = 0;
}

extern void fn_802C7758(int);
extern unsigned int lbl_804C13E0[];
extern char lbl_8055FC35;
extern void fn_802C89E8(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void fn_802C8638(unsigned int *);
extern float lbl_80564EF8, lbl_80564F00;
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
void fn_802C8588(void *arg0, float *arg1, float *arg2) {
    float x = arg1[0], y = arg1[1], z = arg1[2];
    float sp[3];
    ((float *)arg0)[9] = x;
    ((float *)arg0)[10] = y;
    ((float *)arg0)[11] = z;
    ((float *)arg0)[6] = arg2[0] - x;
    ((float *)arg0)[7] = arg2[1] - y;
    ((float *)arg0)[8] = arg2[2] - z;
    sp[0] = lbl_80564F00; sp[1] = lbl_80564EF8; sp[2] = lbl_80564F00;
    PSVECNormalize((char *)arg0 + 0x18, (char *)arg0 + 0x18);
    PSVECCrossProduct(sp, (char *)arg0 + 0x18, arg0);
    PSVECNormalize(arg0, arg0);
    PSVECCrossProduct((char *)arg0 + 0x18, arg0, (char *)arg0 + 0xC);
}

void *fn_802C86DC(void) {
    return lbl_804C1410;
}

extern void *lbl_8055D018;
void fn_802C86E8(void* hi) {
    lbl_8055D018 = hi;
}

void fn_802C88CC(unsigned int arg0) {
    fn_802D02F8(arg0, 1);
}

extern unsigned int lbl_804C1410[];
extern void PSQUATMultiply(void *, unsigned int, void *);
extern void fn_802C7734(unsigned int);
extern void fn_802C8B70(void);
#pragma scheduling off
void fn_802C88D4(unsigned int arg0) {
    register unsigned int q;
    q = arg0;
    PSQUATMultiply((void *)&lbl_804C1410[9], q, lbl_804C1410);
}

extern void *lbl_8055FC5C, *lbl_8055FC60, *lbl_8055FC64, *lbl_8055FC68;
extern double lbl_80564F10;
extern float lbl_80564F18, lbl_80564F1C;
void fn_802C88FC(float *arg0) {
    float x, y, z;
    arg0[0] = lbl_80564EF8;
    arg0[1] = lbl_80564F00;
    arg0[2] = lbl_80564F00;
    arg0[3] = lbl_80564F00;
    arg0[5] = lbl_80564F00;
    arg0[4] = lbl_80564F1C;
    arg0[6] = lbl_80564F00;
    arg0[7] = lbl_80564F00;
    arg0[8] = lbl_80564EF8;
    x = (float)(unsigned int)lbl_8055FC64;
    y = (lbl_80564F18 * x) / lbl_8055FC44;
    z = lbl_80564EF8 / lbl_8055D020;
    arg0[11] = -(y * z);
    arg0[10] = (float)(unsigned int)lbl_8055FC60 + lbl_80564F18 * (float)(unsigned int)lbl_8055FC68;
    arg0[9] = (float)(unsigned int)lbl_8055FC5C + lbl_80564F18 * (float)(unsigned int)lbl_8055FC64;
}

#pragma scheduling on
void fn_802C8B08(unsigned int *arg0) {
    unsigned int *src = lbl_804C1410;
    arg0[0] = src[0]; arg0[1] = src[1];
    arg0[2] = src[2]; arg0[3] = src[3];
    arg0[4] = src[4]; arg0[5] = src[5];
    arg0[6] = src[6]; arg0[7] = src[7];
    arg0[8] = src[8]; arg0[9] = src[9];
    arg0[10] = src[10]; arg0[11] = src[11];
}

extern void fn_802CAD74(void);
void fn_802C8B70(void) {
    fn_802CAD74();
    lbl_8055FC70 = 2;
}

void fn_802C8B98(unsigned int arg0, unsigned int arg1) {
    fn_802C7734(arg1);
    fn_802C8B70();
}

#pragma dont_inline on
void fn_802C8BD0(int arg0) {
    fn_802C7758(arg0);
    ((void (*)(int))fn_802C8B70)(arg0);
}
#pragma dont_inline off

#pragma use_lmw_stmw off
void fn_802C8C04(int arg0) {
    unsigned int src[12];
    unsigned int *dst = lbl_804C13E0;
    unsigned int sp8[12];
    unsigned int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
    v0 = lbl_804C1410[0];
    v1 = lbl_804C1410[1]; v2 = lbl_804C1410[2]; v3 = lbl_804C1410[3];
    v4 = lbl_804C1410[4]; v5 = lbl_804C1410[5]; v6 = lbl_804C1410[6];
    v7 = lbl_804C1410[7]; v8 = lbl_804C1410[8]; v9 = lbl_804C1410[9];
    v10 = lbl_804C1410[10]; v11 = lbl_804C1410[11];
    *dst++ = v0; *dst++ = v1; *dst++ = v2; *dst++ = v3; *dst++ = v4; *dst++ = v5;
    *dst++ = v6; *dst++ = v7; *dst++ = v8; *dst++ = v9; *dst++ = v10; *dst++ = v11;
    lbl_8055FC35 = 1;
    fn_802C89E8(sp8, v11, v10, v9, v8, v7, v6, v5);
    fn_802C8638(sp8);
    fn_802C8BD0(arg0);
}
void fn_802C8DB8(void) {
    fn_802D68C4();
}

int fn_802C8DBC(void) {
    if (fn_801E4F20() != 0) {
        lbl_8055FC8F = 1;
        lbl_8055FC70 = 6;
        return 1;
    }
    return 0;
}

void fn_802C8E00(void) {
    unsigned char result = 0;
    if (lbl_8055FC8F != 0 && fn_801E4F3C() == 0) {
        result = 1;
    }
    lbl_8055FC8F = result;
}

extern void fn_801E4FF4(void);
void fn_802C8E48(void) {
    fn_801E4FF4();
    lbl_8055FC70 = 2;
}

float fn_802C8FEC(void) { return lbl_8055FC6C; }

extern float lbl_80558DC4;
extern float lbl_8055FC38, lbl_8055FC3C;
#pragma scheduling off
int fn_802C8FF4(float *arg0, float arg1) {
    float x;
    float y;
    float z;
    int result = 0;

    z = arg0[2];
    if (z > lbl_8055FC38 + lbl_80558DC4 &&
        z < lbl_8055FC3C - lbl_80558DC4) {
        x = arg0[0];
        if (x >= (float)(int)lbl_8055FC5C - arg1 &&
            x < arg1 + (float)((int)lbl_8055FC5C + (int)lbl_8055FC64)) {
            y = arg0[1];
            if (y >= (float)(int)lbl_8055FC60 - arg1 &&
                y < arg1 + (float)((int)lbl_8055FC60 + (int)lbl_8055FC68)) {
                result = 1;
            }
        }
    }
    return result;
}
#pragma scheduling on
int fn_802C90E0(void) {
    return lbl_8055FC70 == 0;
}

void fn_802C9294(int arg0, int arg1) {
    if (arg0 != -1 && arg0 != -2) {
        char value = arg1 != 1;
        lbl_8055FC75 = !value;
        lbl_8055FC74 = 1;
    } else {
        lbl_8055FC74 = 0;
        lbl_8055FC75 = 0;
    }
    fn_802CB29C();
}

extern void fn_802C8C04(int);
extern void fn_802C8D74(void);
extern int lbl_8055FC70;
extern int fn_802CB29C(void);
extern char lbl_8055FC74;
extern char lbl_8055FC75;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern void fn_802C92DC(int, int, int, int, int);
#pragma dont_inline on
void fn_802C92D0(void) {
#pragma dont_inline off
    fn_802C8C04(-1);
}

void fn_802C92D8(void) {
    fn_802C8D74();
}

void fn_802C9118(void) {
    lbl_8055FC70 = 2;
    fn_802C8D74();
}

void fn_802C942C(int arg0) {
    fn_802C92D0();
    fn_802C92DC(0, 0, lbl_8055CFF0, lbl_8055CFF4, arg0);
    fn_802C92D8();
}

void fn_802C9474(void) {
    if ((unsigned char)lbl_8055FC94 != 0) return;
    lbl_8055FC94 = 1;
    fn_802E30C8(lbl_8055D030, lbl_8034B4E0);
}

int fn_802C94A0();
void fn_802C9638(int arg0, int arg1) {
    fn_802C94A0(arg0, arg1, 0);
}

#pragma dont_inline on
void fn_802C9640(int arg0) {
    fn_802C9638(arg0, 0);
}
#pragma dont_inline off
extern void fn_802C9638(int, int);
extern void fn_802C974C();
extern float lbl_8055FC38;
extern float lbl_8055FC3C;
extern float lbl_8055FC40;
extern float lbl_804C144C[];
void fn_802C9648(float arg0) {
    float f3 = lbl_8055FC38;
    float f4 = lbl_8055FC3C;
    float f0 = f3 * arg0;
    float f2 = f4 * arg0;
    lbl_804C144C[0] = f3;
    lbl_804C144C[1] = f4;
    lbl_8055FC38 = f0;
    lbl_8055FC3C = f2;
    fn_802C974C(lbl_804C144C, f0, f2, lbl_804C144C[2], f4);
}

void fn_802C967C(void) {
    fn_802C974C(lbl_804C144C, lbl_804C144C[0], lbl_804C144C[1], lbl_804C144C[2]);
}

void *fn_802C9694(void *arg0) {
    ((float *)arg0)[0] = lbl_8055FC38;
    ((float *)arg0)[1] = lbl_8055FC3C;
    ((float *)arg0)[2] = lbl_8055FC40;
    fn_802C974C(arg0);
    return arg0;
}

void *fn_802C96DC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802C974C(((float *)arg0)[0], ((float *)arg0)[1], ((float *)arg0)[2]);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

float fn_802C973C(void) { return lbl_8055FC4C; }

float fn_802C9744(void) { return lbl_8055FC40; }

void fn_802C98DC(float *arg0, float *arg1, float *arg2, float *arg3) {
    *arg0 = lbl_8055FC44;
    *arg1 = lbl_8055FC38;
    *arg2 = lbl_8055FC3C;
    *arg3 = lbl_8055FC48;
}

#pragma dont_inline off
extern float lbl_80564EF8;
extern void fn_802D007C(float);
void fn_802C9904(void) {
    fn_802D007C(lbl_80564EF8);
}

int fn_802C990C(int arg0) {
    int previous = lbl_8055FC78;
    lbl_8055FC78 = arg0;
    fn_802CFFAC((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC7C;
extern void fn_802D0160(unsigned char, unsigned char, unsigned char);
int fn_802C9950(int arg0) {
    int previous = lbl_8055FC7C;
    lbl_8055FC7C = arg0;
    fn_802D0160((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern int lbl_8055FC80;
extern void fn_802D0188(unsigned char, unsigned char, unsigned char);
int fn_802C9994(int arg0) {
    int previous = lbl_8055FC80;
    lbl_8055FC80 = arg0;
    fn_802D0188((arg0 >> 16) & 0xFF, (arg0 >> 8) & 0xFF, arg0 & 0xFF);
    return previous;
}

extern char lbl_804C1440[];
extern float lbl_8055D01C;
void fn_802C99D8(void) {
    fn_802D01B0(lbl_804C1440, lbl_8055D01C);
}

float fn_802C99E8(float arg0) {
    float previous = lbl_8055D01C;
    lbl_8055D01C = arg0;
    fn_802C99D8();
    return previous;
}

void fn_802C9A1C(float *arg0) {
    float x = arg0[0];
    float y = arg0[1];
    float z = arg0[2];
    lbl_804C1440[0] = x;
    lbl_804C1440[1] = y;
    lbl_804C1440[2] = z;
    fn_802C99D8();
}

void *fn_802C9A40(void) {
    return lbl_804C1440;
}

void fn_802C9A4C(void) {
    fn_802D93E0();
}

float fn_802C9A50(void) { return lbl_8055D020; }

#pragma dont_inline off
char fn_802C9A58(void) {
    return lbl_8055FC8C;
}

extern char lbl_8055FC8D;
char fn_802C9A60(void) {
    return lbl_8055FC8D;
}

extern char lbl_8055FC8E;
char fn_802C9A68(void) {
    return lbl_8055FC8E;
}

int fn_802C9C24(void *arg0) {
    void *p = *(void **)((char *)arg0 + 8);
    void *q = *(void **)((char *)p + 4);
    return *(int *)q + 4;
}

extern void *lbl_8055FC68;
void* fn_802C9C38(void) {
    return lbl_8055FC68;
}

extern void *lbl_8055FC60;
void* fn_802C9C40(void) {
    return lbl_8055FC60;
}

extern void *lbl_8055FC64;
void* fn_802C9C48(void) {
    return lbl_8055FC64;
}

extern void *lbl_8055FC5C;
void* fn_802C9C50(void) {
    return lbl_8055FC5C;
}

int fn_802C9C58(int arg0) {
    int old = lbl_8055FC30;
    lbl_8055FC30 = arg0;
    fn_802D08CC();
    return old;
}

int fn_802C9C8C(int arg0) {
    fn_802CAD68();
    if (fn_802D31D8(1) != 0) {
        lbl_8055FC84 = arg0;
        lbl_8055FC70 = 4;
        return 1;
    }
    return 0;
}

extern int lbl_8055FC98;
extern void *lbl_8055FC9C;
extern int lbl_8055FC84;
extern float lbl_80564F00;
extern char lbl_8034B514[];
extern int fn_8012A364(void *, int);
extern void *fn_801E7840(int);
extern void *fn_801284F8(int, const char *);
extern void *fn_8012A13C(const char *, int, int);
extern int fn_8012A2D8(void *);
extern void fn_802D362C(int);
extern void fn_802D3304(void);
#pragma dont_inline on
void fn_802C9D88(int arg0) {
    fn_8012A364(lbl_8055FC9C, arg0);
    if (--lbl_8055FC98 == 0) {
        if (lbl_8055FC9C != 0) {
            void **vtable = *(void ***)lbl_8055FC9C;
            ((void (*)(void *, int))vtable[2])(lbl_8055FC9C, 1);
        }
        lbl_8055FC9C = 0;
    }
}

void *fn_802C9DE8(void *arg0, int arg1) {
    *(void **)arg0 = fn_801E7840(arg1);
    {
        float zero = lbl_80564F00;
        *(float *)((char *)arg0 + 4) = zero;
        *(float *)((char *)arg0 + 8) = zero;
        *(float *)((char *)arg0 + 12) = zero;
        *(float *)((char *)arg0 + 16) = zero;
    }
    *(int *)((char *)arg0 + 20) = 0;
    return arg0;
}

int *__dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(int *arg0, int arg1) {
    if (arg0 != 0) {
        fn_801E7888(*arg0);
        if (arg1 > 0) fn_802C9D88((int)arg0);
    }
    return arg0;
}

void fn_802CA008(void *arg0) {
    if (((int (*)(int, float))fn_802C9640)((int)((char *)arg0 + 4), *(float *)((char *)arg0 + 0x10)) != 0) {
        fn_801E7894(*(int *)arg0);
    }
}

extern void *fn_802C9D10(int, void *);
extern void *fn_802C9DE8(void *, int);
extern char lbl_8034B52C[];
void fn_802CA04C(int arg0) {
    void *obj;
    obj = fn_802C9D10(0x18, lbl_8034B52C);
    if (obj != 0)
        fn_802C9DE8(obj, arg0);
}

void fn_802CA094(int *arg0) {
    __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_802C9E3C(arg0, 1);
}

void fn_802CA09C(void) {
    fn_802C9E94();
}

void fn_802CA0A0(void *arg0) { fn_802CA008(arg0); }

extern char lbl_8055FC94;
extern char lbl_8055D030[];
extern char lbl_8034B4E0[];
extern void fn_802E30C8(const char *, ...);
extern float lbl_8055FC44;
extern float lbl_8055FC48;
