#include "revolution/MTX/mtxtypes.h"
extern int lbl_8034AC48, lbl_8055FAA8, lbl_8055FAAC;
extern void fn_802C126C(void);
extern void fn_802B8AE0(void *, void *);
extern int fn_802B05E4(void);
extern int fn_802BD210();
extern void fn_802C2914(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FAB8;
extern int lbl_804C00D4;
extern void *lbl_8055FABC;
int fn_8012C33C(void);
extern float lbl_80564D14;
extern float lbl_80564D18;
int fn_802CAC28(int, int);
void fn_802BD018(void *);
int fn_802BD070(void *);
void fn_80128668(void *);
extern int fn_802C9C24(int);
extern void fn_802E317C(void *, int);
extern void fn_802B110C(void *, int);
extern int lbl_8034AB38;
int fn_802BC334(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

#pragma dont_inline on
  int stricmp(const char *, const char *);
  __declspec(section ".sdata") extern const char lbl_8055CF38[];
#pragma push
#pragma cplusplus on
extern "C" int fn_802BC39C(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&lbl_8055CF38, ((Obj *)arg0)->getName()) == 0;
}
#pragma cplusplus reset
#pragma pop

void *fn_802BE844(short, short, short);
int fn_802BC39C();
void fn_802BC3DC(void) {
    fn_802BC39C();
}

#pragma scheduling invalid_target
void fn_802BC3E0(short arg0, short arg1, short arg2, char *arg3) {
    char *obj = fn_802BE844(arg0, arg1, arg2);
    *(char **)arg3 = *(char **)(obj + 4);
    *(char **)(obj + 4) = arg3;
}
#pragma scheduling on
short fn_802BC424(int arg0) {
    int mask = 0x1FF;
    short value = arg0 + 0x200;
    do {
        mask >>= 1;
    } while (value & mask);
    return mask + 1;
}

void fn_802BC44C(void *arg0) {
    char *entry;
    int offset;
    int i;

    offset = 0;
    i = 0;
    goto check;
loop:
    entry = *(char **)arg0 + offset;
    fn_802BC3E0(*(short *)(entry + 4), *(short *)(entry + 6), fn_802BC424(*(short *)(entry + 4)), entry);
    offset += 0x10;
    i++;
check:
    if (i < *(int *)((char *)arg0 + 4)) goto loop;
}

void *fn_802BC4D4(void *arg0) {
    return *(void **)(*(char **)((char *)arg0 + 4) + 0xC);
}

#pragma scheduling invalid_target
int fn_802BC4E0(void *arg0) {
    int result = fn_802C9C24(*(int *)((char *)arg0 + 4));
    if (fn_8012C33C() != 0)
        fn_802E317C(&lbl_8034AB38, result);
    fn_802B110C(&fn_802BC334, result);
    return result;
}
#pragma scheduling on
double fn_8002F234(float, float);
float fn_802BC540(void *arg0, float farg0) {
    float x = *(float *)arg0;
    float z = *(float *)((char *)arg0 + 8);
    return farg0 * (float)fn_8002F234(x * x + z * z, z);
}

void PSVECCrossProduct(Vec *, Vec *, Vec *);
void PSVECNormalize(const Vec *, Vec *);
void fn_801EA18C(void *, s32, s32);
#pragma push
#pragma scheduling invalid_target
void fn_802BC588(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
volatile float sp14[3];
volatile float sp8[3];
float *m0 = (float *)arg0;
float *m1 = (float *)arg1;
float *v = (float *)arg2;
float *in = (float *)arg3;
float *basis = (float *)arg4;
float one, f1, f2, f3, zero, f5;

zero = lbl_80564D14;
f5 = ((float *)arg3)[0];
f3 = ((float *)arg3)[1];
f2 = ((float *)arg3)[2];
f1 = ((float *)arg3)[3];
one = lbl_80564D18;

m0[9] = f5;
m0[10] = zero;
m0[11] = f3;
m0[6] = f2;
m0[7] = zero;
m0[8] = f1;
m0[3] = zero;
m0[4] = one;
m0[5] = zero;
PSVECCrossProduct((Vec *)(m0 + 3), (Vec *)(m0 + 6), (Vec *)m0);

sp14[0] = lbl_80564D14;
sp14[1] = lbl_80564D18;
sp14[2] = lbl_80564D14;
fn_801EA18C(m0 + 9, (s32)sp14, 0);
v[0] = sp14[0];
v[1] = sp14[1];
v[2] = sp14[2];
m0[10] -= fn_802BC540((void *)sp14, basis[21]);

if ((u32)sp8 == (u32)((char *)arg4 + 0x34)) {
float a, b, c, x3, x4, x5, x0, x1, x2, x6, x7, x8;
float q0, q1, q2, p0, p1, p2, r0, r1, r2;
x3 = m0[3];
b = basis[14];
x4 = m0[4];
x5 = m0[5];
q0 = b * x3;
x0 = m0[0];
q1 = b * x4;
a = basis[13];
x1 = m0[1];
p0 = a * x0;
x2 = m0[2];
p1 = a * x1;
x6 = m0[6];
q2 = b * x5;
x7 = m0[7];
p2 = a * x2;
x8 = m0[8];
c = basis[15];
r0 = c * x6;
r1 = c * x7;
r2 = c * x8;
sp8[0] = r0 + (p0 + q0);
sp8[1] = r1 + (p1 + q1);
sp8[2] = r2 + (p2 + q2);
} else {
sp8[0] = basis[15] * m0[6] + (basis[13] * m0[0] + basis[14] * m0[3]);
sp8[1] = basis[15] * m0[7] + (basis[13] * m0[1] + basis[14] * m0[4]);
sp8[2] = basis[15] * m0[8] + (basis[13] * m0[2] + basis[14] * m0[5]);
}
sp8[0] *= in[4];
sp8[1] *= in[4];
sp8[2] *= in[4];
m1[9] = m0[9] + sp8[0];
m1[10] = m0[10] + sp8[1];
m1[11] = m0[11] + sp8[2];

if ((u32)(m1 + 6) == (u32)((char *)arg4 + 0x40)) {
float m1v = basis[17];
float m0v = basis[16];
float m2v = basis[18];
float x3 = m0[3];
float x4 = m0[4];
float x5 = m0[5];
float x0 = m0[0];
float x1 = m0[1];
float x2 = m0[2];
float x6 = m0[6];
float x7 = m0[7];
float x8 = m0[8];
float q0 = m1v * x3;
float q1 = m1v * x4;
float q2 = m1v * x5;
float p0 = m0v * x0;
float p1 = m0v * x1;
float p2 = m0v * x2;
float r0 = m2v * x6;
float r1 = m2v * x7;
float r2 = m2v * x8;
m1[6] = r0 + (p0 + q0);
m1[7] = r1 + (p1 + q1);
m1[8] = r2 + (p2 + q2);
} else {
m1[6] = basis[18] * m0[6] + (basis[16] * m0[0] + basis[17] * m0[3]);
m1[7] = basis[18] * m0[7] + (basis[16] * m0[1] + basis[17] * m0[4]);
m1[8] = basis[18] * m0[8] + (basis[16] * m0[2] + basis[17] * m0[5]);
}
m1[1] = lbl_80564D14;
m1[0] = lbl_80564D18;
m1[2] = lbl_80564D14;
PSVECCrossProduct((Vec *)(m1 + 6), (Vec *)m1, (Vec *)(m1 + 3));
PSVECCrossProduct((Vec *)(m1 + 3), (Vec *)(m1 + 6), (Vec *)m1);
PSVECNormalize((Vec *)(m1 + 3), (Vec *)(m1 + 3));
PSVECNormalize((Vec *)m1, (Vec *)m1);

{
float scale = in[4];
m0[0] *= scale;
m0[1] *= scale;
m0[2] *= scale;
m0[3] *= scale;
m0[4] *= scale;
m0[5] *= scale;
m0[6] *= scale;
m0[7] *= scale;
m0[8] *= scale;
}
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
void *fn_802BC9B0(void *arg0, int arg1, float scale) {
    extern void *fn_801284F8(int, int);
    extern float lbl_80564D1C, lbl_80564D20;
    extern int lbl_8034AB54[], lbl_80333918[];
    float bInput = *(float *)((char *)arg0 + 0x1C);
    float aInput = *(float *)((char *)arg0 + 0x18);
    float value = lbl_80564D1C;
    float b = bInput * scale;
    float a = aInput * scale;
    char *obj = fn_801284F8(0x2C, (int)&lbl_8034AB54);
    if (obj != 0) {
        float initial = lbl_80564D20;
        *(int *)(obj + 0xC) = 0;
        *(int *)(obj + 4) = 0;
        *(int *)(obj + 8) = 0;
        *(int *)(obj + 0x18) = 0x54554245;
        *(float *)(obj + 0x10) = value;
        *(float *)(obj + 0x14) = initial;
        *(int *)(obj + 0x20) = 100;
        *(int *)(obj + 0x1C) = 0;
        *(float *)(obj + 0x24) = b;
        *(float *)(obj + 0x28) = a;
        *(void **)obj = &lbl_80333918;
    }
    ((void (*)(void *, int))(*(void (**)(void *, int))((char *)*(void **)obj + 0x40)))(obj, arg1);
    return obj;
}

struct CurveData {
    int w0, w1, w2, w3, w4, w5;
    float f6;
    float f7;
};
extern void fn_802BC588(void *, void *, void *, void *, void *);
extern int fn_802C1500(void *, int);
extern void *fn_801FA8E0(void *, void *, int);
extern int lbl_8055FAB0;
extern float lbl_80564D14, lbl_80564D24, lbl_80564D28;
void fn_802BCA8C(void *arg0, void *arg1, void *arg2) {
    char pad[0x20];
    int sp28;
    int sp8, spC, sp10, sp14, sp18, sp1C;
    float sp20, sp24;
    int value;
    void *curve, *result;
    fn_802BC588((char *)arg0 + 0xC, &sp28, arg0, arg1, arg2);
    value = fn_802C1500((char *)arg0 + 0xC, *(int *)((char *)arg2 + 0x28));
    if (*(unsigned char *)&lbl_8055FAB0 != 0) {
        curve = fn_802BC9B0((char *)arg2 + 0x34, *(int *)((char *)arg2 + 0x2C), *(float *)((char *)arg1 + 0x10));
        result = ((void *(*)(void *, void *, int))fn_801FA8E0)(curve, &sp28, value);
        *(void **)((char *)arg0 + 0x3C) = result;
        *(float *)((char *)arg0 + 0x40) = *(float *)((char *)arg0 + 0x34) - *(float *)((char *)result + 0x28);
        if (*(unsigned char *)((char *)arg2 + 0x30) != 0 && *(int *)((char *)arg2 + 0x2C) != 0x74) {
            float f3 = *(float *)((char *)arg2 + 0x4C);
            float f2 = *(float *)((char *)arg2 + 0x50) + lbl_80564D24;
            sp8 = *(int *)((char *)arg2 + 0x34);
            spC = *(int *)((char *)arg2 + 0x38);
            sp10 = *(int *)((char *)arg2 + 0x3C);
            sp14 = *(int *)((char *)arg2 + 0x40);
            sp18 = *(int *)((char *)arg2 + 0x44);
            sp1C = *(int *)((char *)arg2 + 0x48);
            sp20 = f3 + lbl_80564D28;
            sp24 = f2;
            curve = ((void *(*)(void *, int, float, int, int, int, int, int, int, float, float, float))fn_802BC9B0)(&sp8, 0x3EB, *(float *)((char *)arg1 + 0x10), sp18, sp14, sp10, spC, sp8, sp1C, f2, f3 + lbl_80564D28, f3);
            ((void *(*)(void *, void *, int))fn_801FA8E0)(curve, &sp28, value);
        }
    } else {
        *(void **)((char *)arg0 + 0x3C) = 0;
        *(float *)((char *)arg0 + 0x40) = lbl_80564D14;
    }
    *(int *)((char *)arg0 + 4) = 0;
}

extern void fn_80131810(void);
extern void fn_802C6B44(void);
extern void *fn_802B561C(void *, const char *);
extern void *fn_802B2C34(void *, int);
extern int fn_802BC4E0(void *);
void fn_802BCFB0(int *);
void fn_802CAC54(int);
int fn_802C6C20(int);
void fn_80131818(void);
extern int fn_802B1DA0(void *);
extern int fn_801D04D0(void);
extern int fn_802C143C(void *);
extern float PSVECMag(const Vec *);
extern void PSVECNormalize(const Vec *, Vec *);
extern int lbl_8034AB38;
extern void *lbl_8055FAB4;
__declspec(section ".sdata") extern const char lbl_8055CF40[];
__declspec(section ".sdata") extern const char lbl_8055CF48[];
__declspec(section ".sdata") extern const char lbl_8055CF50[];
__declspec(section ".sdata") extern const char lbl_8055CF58[];
__declspec(section ".sdata") extern const char lbl_8055CF60[];
extern float lbl_80564D2C;
__declspec(section ".data") extern int lbl_8034AB38;
__declspec(section ".data") extern int lbl_804C00D4;
extern void *fn_802BC4D4(void *);
#pragma push
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
extern "C" void fn_802BCBDC(void) {
    class Query {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual Vec get(const char *, ...);
    };
    void *list;
    register void *item;
    register int i;
    int count;
    register char *entry;
    register char *rdata = (char *)&lbl_8034AB38;
    float half;
    float min[3], max[3], center[3];
    float dx, nx, dy, dz;
    float cx, cy, cz;
    void *value;

    list = fn_802B561C(fn_80131810, rdata + 0x28);
    lbl_8055FAB4 = list;
    if (list == 0)
        return;
    half = lbl_80564D2C;
    for (i = 0; (item = ((void *(*)(void *, int))(*(void ***)lbl_8055FAB4)[3])(lbl_8055FAB4, i)) != 0; i++) {
        if (((int (*)(void *))fn_802BC3DC)(item) != 0) {
            count = *(int *)((char *)&lbl_804C00D4 + 4);
            *(int *)((char *)&lbl_804C00D4 + 4) = count + 1;
            entry = *(char **)&lbl_804C00D4 + count * 0x60;
            *(void **)entry = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, lbl_8055CF40);
            *(void **)(entry + 4) = ((void *(*)(void *, const char *))(*(void ***)item)[23])(item, rdata + 0x38);
            value = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, rdata + 0x44);
            *(void **)(entry + 0x18) = fn_802B2C34(fn_802C6B44, (int)value);
            *(void **)(entry + 0x1C) = fn_802BC4D4(*(void **)(entry + 0x18));
            *(int *)(entry + 0x20) = fn_802BC4E0(*(void **)(entry + 0x18));
            *(int *)(entry + 0x24) = fn_802B1DA0(*(void **)(entry + 0x1C));
            value = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, rdata + 0x50);
            *(void **)(entry + 8) = fn_802B2C34(fn_802C6B44, (int)value);
            *(void **)(entry + 0xC) = fn_802BC4D4(*(void **)(entry + 8));
            *(int *)(entry + 0x10) = fn_802BC4E0(*(void **)(entry + 8));
            *(int *)(entry + 0x14) = fn_802B1DA0(*(void **)(entry + 0xC));
            *(float *)(entry + 0x5C) = ((float (*)(void *, const char *, float))(*(void ***)item)[10])(item, rdata + 0x5C, lbl_80564D14);
            *(unsigned char *)(entry + 0x30) = ((int (*)(void *, const char *, int))(*(void ***)item)[12])(item, rdata + 0x68, 1);
            ((void (*)(void *, const char *, const char *))(*(void ***)item)[6])(item, rdata + 0x74, lbl_8055CF48);
            *(int *)(entry + 0x2C) = fn_801D04D0();
            *(int *)(entry + 0x28) = fn_802C143C(item);
            *(Vec *)min = ((Query *)item)->get(lbl_8055CF50);
            *(Vec *)max = ((Query *)item)->get(lbl_8055CF58, *(unsigned int *)&min[0], *(unsigned int *)&min[1], *(unsigned int *)&min[2]);
            {
                float minX = min[0], minY = min[1], minZ = min[2];
                float maxX = max[0], maxY = max[1], maxZ = max[2];
                dx = maxX - minX;
                nx = minX - maxX;
                dy = maxY - minY;
                dz = maxZ - minZ;
                cx = minX + half * dx;
                cy = minY + half * dy;
                cz = minZ + half * dz;
            }
            *(float *)(entry + 0x34) = cx;
            *(float *)(entry + 0x38) = cy;
            *(float *)(entry + 0x3C) = cz;
            center[0] = cx;
            center[1] = cy;
            center[2] = cz;
            *(float *)(entry + 0x40) = nx;
            *(float *)(entry + 0x44) = min[1] - max[1];
            *(float *)(entry + 0x48) = min[2] - max[2];
            *(float *)(entry + 0x4C) = PSVECMag((Vec *)(entry + 0x40)) * half;
            PSVECNormalize((Vec *)(entry + 0x40), (Vec *)(entry + 0x40));
            *(float *)(entry + 0x50) = ((float (*)(void *, const char *))(*(void ***)item)[9])(item, lbl_8055CF60);
            *(float *)(entry + 0x54) = ((float (*)(void *, const char *))(*(void ***)item)[9])(item, rdata + 0x80);
            *(int *)(entry + 0x58) = 0;
        }
        i++;
    }
}

void fn_802BCF04(void) {
    void *base;
    char *entry;
    int i;
    int offset;

    base = *(void **)&lbl_804C00D4;
    i = 0;
    offset = 0;
    goto check;
loop:
    entry = (char *)base + offset;
    fn_802BCFB0((int *)(entry + 0x58));
    fn_802CAC54(*(int *)(entry + 0x20));
    fn_802C6C20(*(int *)(entry + 0x18));
    *(int *)(entry + 0x18) = 0;
    fn_802CAC54(*(int *)(entry + 0x10));
    fn_802C6C20(*(int *)(entry + 8));
    *(int *)(entry + 8) = 0;
    offset += 0x60;
    i++;
check:
    if (i < *(int *)((char *)&lbl_804C00D4 + 4)) goto loop;
    *(int *)((char *)&lbl_804C00D4 + 4) = 0;
    if (lbl_8055FAB4 != 0) {
        fn_80131818();
        lbl_8055FAB4 = 0;
    }
}
void fn_802BCFB0(int *arg0) {
    int temp_r31;
    temp_r31 = *arg0;
    if (temp_r31 != 0) {
        if (temp_r31 != 0) {
            fn_802BD018((char *)temp_r31 + 8);
            fn_802BD018((char *)temp_r31 + 4);
            fn_802BD070((void *)temp_r31);
            fn_80128668((void *)temp_r31);
        }
        *arg0 = 0;
    }
}

#pragma pop

int fn_802BD0C8(void *arg0) {
    int result = 0;
    if (*(int *)((char *)arg0 + 4) != 0) {
        void **ptr = *(void ***)((char *)arg0 + 0x58);
        if (ptr != 0)
            result = *(int *)((char *)*ptr + 4);
    }
    return result;
}

int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD0F4(void *arg0) {
    int i, offset, count;
    char *entries, *entry;
    void *array;
    float pos[2];
    if (*(int *)((char *)arg0 + 4) != 0 && (array = *(void **)((char *)arg0 + 0x58)) != 0) {
        entries = *(char **)array;
        count = *(int *)(entries + 4);
        i = 0;
        offset = 0;
        while (i < count) {
            array = *(void **)((char *)arg0 + 0x58);
            entries = *(char **)array;
            entry = *(char **)entries + offset;
            pos[0] = *(float *)(entry + 0x30);
            pos[1] = *(float *)(entry + 0x38);
            *(int *)(entry + 4) = fn_802BA580(*(int *)((char *)arg0 + 4), pos, *(float *)(entry + 0x1c));
            offset += 0x44;
            i++;
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
void *fn_802BD194(void *arg0, const char *arg1) {
    unsigned int count = *(unsigned int *)arg0;
    unsigned int offset = 0;
    unsigned int i = 0;
    char *base;
    while (i < count) {
        base = *(char **)((char *)arg0 + 4);
        if (strcmp(base + offset, arg1) == 0)
            return base + i * 0x38;
        offset += 0x38;
        i++;
    }
    return 0;
}
#pragma pop
void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
#pragma scheduling on
void fn_802BD414(int arg0, volatile int *arg1)
{
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result == 0)
        return;
    {
        int first = arg1[0];
        result[0] = arg1[1];
        result[2] = first;
        result[1] = 0;
        result[1] = result[1] + arg1[0];
    }
}
#pragma scheduling reset
void fn_802BD478(int arg0, volatile int *arg1) {
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result != 0) {
        int second = arg1[1];
        int first = arg1[0];
        result[0] = second;
        result[2] = first;
        result[1] = 0;
        result[1] = result[1] + arg1[0];
    }
}

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD4DC(void *arg0, int arg1) {
    extern void fn_802BD69C(void *, int);
    extern void fn_802BD5B0(void *, int);
    unsigned char *p = arg0;
    char *entry;
    int offset;
    unsigned int i;
    unsigned char b5, b4, b1, b0, b3, b2, b6;
    b4 = p[4];
    b5 = p[5];
    b6 = p[6];
    p[4] = p[7];
    b0 = p[0];
    b3 = p[3];
    p[7] = b4;
    b1 = p[1];
    b2 = p[2];
    p[5] = b6;
    p[6] = b5;
    p[0] = b3;
    p[3] = b0;
    p[1] = b2;
    p[2] = b1;
    *(int *)(p + 4) = fn_802BD5A8(*(int *)(p + 4), arg1);
    i = 0;
    offset = 0;
    while (i < *(unsigned int *)p) {
        entry = *(char **)(p + 4) + offset;
        fn_802BD69C(entry + 0x20, arg1);
        fn_802BD5B0(entry + 0x28, arg1);
        fn_802BD5B0(entry + 0x30, arg1);
        offset += 0x38;
        i++;
    }
}
#pragma pop

int fn_802BD5A8(int arg0, int arg1) { return arg0 + arg1; }

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD5B0(void *arg0, int arg1) {
    extern int fn_802BD694(int, int);
    extern float lbl_80564D30;
    unsigned char *p = arg0;
    unsigned char *entry;
    int offset;
    unsigned int i;
    float zero;
    unsigned char b6, b2, b3, b0, b1, b4, b5;
    b4 = p[4]; b5 = p[5]; b6 = p[6];
    p[4] = p[7]; b0 = p[0]; b3 = p[3]; p[7] = b4;
    b1 = p[1]; b2 = p[2]; p[5] = b6; p[6] = b5;
    p[0] = b3; p[3] = b0; p[1] = b2; p[2] = b1;
    *(int *)(p + 4) = fn_802BD694(*(int *)(p + 4), arg1);
    i = 0; zero = lbl_80564D30; offset = 0;
    while (i < *(unsigned int *)p) {
        unsigned char tmp;
        entry = *(unsigned char **)(p + 4) + offset;
        tmp = entry[4]; entry[4] = entry[5]; entry[5] = tmp;
        tmp = entry[6]; entry[6] = entry[7]; entry[7] = tmp;
        tmp = entry[8]; entry[8] = entry[9]; entry[9] = tmp;
        tmp = entry[10]; entry[10] = entry[11]; entry[11] = tmp;
        *(float *)(entry + 12) = zero;
        offset += 0x10; i++;
    }
}
#pragma pop

int fn_802BD694(int arg0, int arg1) { return arg0 + arg1; }

void fn_802BD69C(void *arg0, int arg1) {
    unsigned char *p = arg0;
    unsigned char *entry;
    unsigned int i;
    int offset;
    unsigned char a, b, c, d, e, f, g, h;
    a=p[4]; b=p[7]; c=p[5]; d=p[6];
    p[4]=b; e=p[0]; f=p[3]; p[7]=a;
    g=p[1]; h=p[2]; p[5]=d; p[6]=c;
    p[0]=f; p[3]=e; p[1]=h; p[2]=g;
    *(int *)(p+4)=fn_802BD80C(*(int *)(p+4),arg1);
    i=0; offset=0;
    while (i < *(unsigned int *)p) {
        int j;
        entry=*(unsigned char **)(p+4)+offset+0xC;
        for (j=0;j<2;j++,entry+=0x18) {
            a=entry[0]; b=entry[3]; entry[0]=b; entry[3]=a;
            a=entry[1]; b=entry[2]; entry[1]=b; entry[2]=a;
            a=entry[4]; b=entry[7]; entry[4]=b; entry[7]=a;
            a=entry[5]; b=entry[6]; entry[5]=b; entry[6]=a;
            a=entry[8]; b=entry[11]; entry[8]=b; entry[11]=a;
            a=entry[9]; b=entry[10]; entry[9]=b; entry[10]=a;
            a=entry[12]; b=entry[15]; entry[12]=b; entry[15]=a;
            a=entry[13]; b=entry[14]; entry[13]=b; entry[14]=a;
            a=entry[16]; b=entry[19]; entry[16]=b; entry[19]=a;
            a=entry[17]; b=entry[18]; entry[17]=b; entry[18]=a;
            a=entry[20]; b=entry[23]; entry[20]=b; entry[23]=a;
            a=entry[21]; b=entry[22]; entry[21]=b; entry[22]=a;
        }
        offset+=0x44; i++;
    }
}

int fn_802BD80C(int arg0, int arg1) { return arg0 + arg1; }

__declspec(section ".data") extern int lbl_8034AC48;
#pragma scheduling invalid_target
void fn_802BDBA8(void) {
    char *strings = (char *)&lbl_8034AB38;
    void *object;
    int result;
    int failed;

    fn_802C126C();
    fn_802BCBDC();
    fn_802B8AE0(strings + 0xE8, &lbl_8055FAA8);
    fn_802B8AE0(strings + 0xF4, &lbl_8055FAAC);
    result = fn_802B05E4();
    failed = result == 0;
    *(unsigned char *)&lbl_8055FAB0 = failed;
    if (result == 0) {
        return;
    }
    fn_802BD210();
    object = fn_801284F8(8, (int)(strings + 0x104));
    if (object != 0) {
        fn_802C2914(object);
        *(void **)((char *)object + 4) = &lbl_8034AC48;
    }
    lbl_8055FABC = object;
}
#pragma scheduling on
void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

void fn_802BCF04(void);
void fn_8012C4D8(void);
void fn_802C13A4(void);
void deleteThreads__6SystemFv_802BDCA4(void **);
void fn_802BDC60(void) {
    int flag;
    fn_802BCF04();
    flag = lbl_8055FAB8;
    if (flag != 0) {
        ((int (*)(int))fn_8012C4D8)(flag);
        lbl_8055FAB8 = 0;
    }
    fn_802C13A4();
    deleteThreads__6SystemFv_802BDCA4(&lbl_8055FABC);
}

extern int lbl_8034AB38, lbl_8034AC48;
extern int lbl_8055FAA8, lbl_8055FAAC, lbl_8055FAB0;
extern void *lbl_8055FABC;
void deleteThreads__6SystemFv_802BDCA4(void **arg0) {
    void *obj = *arg0;
    if (obj) {
        if (*arg0) {
            void (**vtable)(void *, int) = *(void (***)(void *, int))((char *)obj + 4);
            vtable[4](obj, 1);
        }
        *arg0 = 0;
    }
}

void fn_802C2930(void*, unsigned int);
#pragma push
#pragma scheduling invalid_target
void fn_802BD018(void *arg0) {
    void *obj = *(void **)arg0;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)arg0 = 0;
    }
}

int fn_802BD070(void *arg0) {
    void *obj = *(void **)arg0;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)arg0 = 0;
    }
}

#pragma pop
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802C2930((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_802BDD54(void) {
    fn_802BD814();
}

void fn_802BDD58(void) {
    fn_801E7E18();
    fn_802C173C();
    if (fn_8020403C() != 0) fn_802BD814();
}

extern int lbl_8055FAA8;
extern int lbl_8055FAAC;
extern float lbl_80564D4C;
void fn_802DBE4C(void);
int fn_8020403C(void);
void fn_802C28C0(void);
void fn_802C8BD0(void);
void fn_802DC71C(int, int);
void fn_801F1C24(float *);
char *fn_801E8718(int);
float PSVECSquareDistance(void *, void *);
void fn_802DCAE4(int, float *, float);
void fn_802DC8B4(void);
void fn_802C8D74(void);
void fn_802DBECC(void);
void fn_802BDD8C(float arg0) {
    float mtx[9];
    float out[12];
    int i, j;
    fn_802DBE4C();
    if (fn_8020403C() != 0) {
        float one = lbl_80564D18;
        float lim = lbl_80564D14;
        float half = lbl_80564D4C;
        int *g = (int *)&lbl_804C00D4;
        lbl_8055FAAC = 0;
        lbl_8055FAA8 = 0;
        for (i = 0; i < g[1]; i++) {
            char *e = (char *)g[0] + i * 0x60;
            int *obj = *(int **)(e + 0x58);
            if (obj != 0) {
                int *data = (int *)obj[1];
                int *pts = (int *)obj[0];
                if (*(int *)(e + 0x24) <= 10) {
                    float sq, den;
                    char *cam;
                    fn_802C28C0();
                    fn_802C8BD0();
                    fn_802DC71C(*(int *)(e + 0x1c), *(int *)(e + 0x20));
                    sq = arg0 * arg0;
                    den = sq - (arg0 - half) * (arg0 - half);
                    fn_801F1C24(mtx);
                    cam = fn_801E8718(-1) + 0x24;
                    for (j = 0; j < data[1]; j++) {
                        char *r = (char *)data[0] + j * 0x10;
                        if (*(float *)(r + 0xc) >= lim) {
                            short idx = *(short *)(r + 0xa);
                            int h = *(int *)(e + 0x1c);
                            for (; idx < *(short *)(r + 0xa) + *(short *)(r + 8); idx++) {
                                char *p = (char *)pts[0] + idx * 0x44;
                                float d = PSVECSquareDistance(p + 0x30, cam);
                                if (d <= sq) {
                                    float f = (sq - d) / den;
                                    float s = *(float *)(p + 0x1c);
                                    int k;
                                    if (one < f) f = one;
                                    for (k = 0; k < 9; k++) out[k] = mtx[k] * s;
                                    out[9] = *(float *)(p + 0x30);
                                    out[10] = *(float *)(p + 0x34);
                                    out[11] = *(float *)(p + 0x38);
                                    fn_802DCAE4(h, out, f);
                                }
                            }
                        }
                    }
                    fn_802DC8B4();
                    fn_802C8D74();
                }
            }
        }
        fn_802DBECC();
    }
}

void fn_802BDFBC(void *arg0, int arg1, float farg0) {
    float value = farg0;
    void *node;
    if (arg1 < 8) {
        value = lbl_80564D18;
    } else if (arg1 == 8) {
        value = farg0;
    } else {
        value = lbl_80564D14;
    }
    node = *(void **)((char *)arg0 + 4);
    while (node != 0) {
        *(float *)((char *)node + 0xC) = value;
        node = *(void **)node;
    }
}

extern float lbl_80564D14;
extern float lbl_80564D18;
void fn_802BAF98(void *, int);
void fn_802BDFF4(void *arg0, int arg1) {
    arg0 = *(void **)((char *)arg0 - 8);
    if (arg0 != 0) {
        fn_802BAF98(arg0, arg1);
    }
}

#pragma scheduling invalid_target
void *fn_802BE008(void *arg0) {
    int count = *(int *)((char *)&lbl_804C00D4 + 4);
    char *entry = *(char **)&lbl_804C00D4;
    int i;
    for (i = 0; i < count; i++, entry += 0x60) {
        char *list = *(char **)(entry + 0x58);
        if (list != 0) {
            char *item = *(char **)(list + 8);
            int found = 0;
            if ((unsigned)arg0 >= (unsigned)*(int *)item && (unsigned)arg0 < (unsigned)*(int *)item + (unsigned)*(int *)(item + 4) * 0x10) {
                found = 1;
            }
            if (found != 0) {
                return entry;
            }
        }
    }
    return 0;
}
#pragma scheduling on
extern void *fn_802BE008(void *);
extern void *fn_802BE844(short, short, short);
extern float lbl_80564D10, lbl_80564D2C;
void fn_802BE07C(void *arg0, float (*arg1)(int, int, int, short, float, float, float)) {
    int x = (int)(*(float *)arg0 / lbl_80564D10);
    int z = (int)(*(float *)((char *)arg0 + 8) / lbl_80564D10);
    short baseX = ((short)x & (short)~0x7F) + 0x40;
    short baseZ = ((short)z & (short)~0x7F) + 0x40;
    short row;
    short col;
    for (row = baseZ - 0x80; row <= baseZ; row += 0x80) {
        for (col = baseX - 0x80; col <= baseX; col += 0x80) {
            void *cell = fn_802BE844(row, col, 0x40);
            void *node = *(void **)((char *)cell + 4);
            while (node) {
                void *obj = fn_802BE008(node);
                void *map = *(void **)((char *)obj + 0x58);
                if (map && *(int *)((char *)obj + 0x24) <= 10) {
                    void *mesh = *(void **)((char *)obj + 0x18);
                    short ix = *(short *)((char *)node + 0xA);
                    short iz = *(short *)((char *)node + 8);
                    float dx = *(float *)((char *)mesh + 0x30) - *(float *)((char *)mesh + 0x2C);
                    float dz = *(float *)((char *)mesh + 0x38) - *(float *)((char *)mesh + 0x34);
                    int (*callback)(int, int, int, short, float, float, float) = (int (*)(int,int,int,short,float,float,float))arg1;
                    callback(*(int *)((char *)obj + 0x20),
                        *(int *)*(void **)map + ix * 0x44 + 0x30, 0x44, iz,
                        dx * lbl_80564D2C, dz, dx);
                }
                node = *(void **)node;
            }
        }
    }
}

extern int lbl_804C00D4;
#pragma scheduling invalid_target
int fn_802BE1D8(void) {
    int i = 0;
    int sum = 0;
    int offset = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        sum += fn_802BD0C8(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
    }
    return sum;
}
#pragma scheduling on
void fn_802BE244(void) {
    int offset = 0;
    int i = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        fn_802BD0F4(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
    }
}

void *fn_801284F8(int, int);
