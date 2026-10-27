// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

typedef struct {
    char unk_0x00[0xC];
    char unk_0x0C[0xC];
    char unk_0x18[0xC];
    char unk_0x24[0xC];
    char unk_0x30[0xC];
    char unk_0x3C[4];
} fn_80203C50Data;


void fn_80203D84(s32* arg0);
void fn_80203DC8(void);
void fn_80203E88(void);
void fn_80203EC4(void);
extern void fn_802CAC54(s32);
extern void fn_802CB228(void);
extern void fn_802CB288(s32);
extern void fn_802CA294(s32);
extern void fn_802D050C(s32);
extern void fn_802D30DC(s32);
extern void fn_802D9230(void);
extern void fn_80203B20(s32, s32, s32);
extern void fn_802D050C_var(void);
#define fn_802D050C(...) fn_802D050C_var()
extern u32 fn_80202BE4(void);
typedef struct { s32 w0; s32 w1; } lbl_8048897C_entry;
struct lbl_8048897C_t { lbl_8048897C_entry* ptr; s32 count; s32 unk_08; s32 unk_0C; };
extern struct lbl_8048897C_t lbl_8048897C;
extern s32 lbl_8055ECFC;
extern s32 lbl_8055ED00;
extern s32 lbl_8055ED04;
extern s32 lbl_8055ED0C;
extern u8 lbl_8055ED10;
extern u8 lbl_8055ED08;
extern int __cntlzw(unsigned int);
extern f32 lbl_80563134, lbl_80563138, lbl_8056313C;
extern void fn_802CB274(s32);
extern void fn_802C9294(s32, s32);
extern void fn_802C8638(f32 *, f32, f32, f32);
extern void fn_802C87B4(s32, s32, s32, s32);
extern void fn_802C974C(f32, f32, f32);
extern void fn_802C86E8(s32);
extern void fn_802C88BC(s32);
extern s32 lbl_8055ED14;
#pragma use_lmw_stmw off
#pragma dont_inline on
extern s8 lbl_8055ED18;
extern s32 lbl_8055ED1C;
extern f32 lbl_80563130;
struct lbl_80488B88_t { s32 w[12]; };
extern struct lbl_80488B88_t lbl_80488B88;
extern void fn_80202BFC(s32);
extern void fn_80203380(void*);
extern void fn_802036E4(void);
extern s32 fn_802BE07C(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 fn_802C8BD0(s32);
extern void fn_802C8D74(void);
extern void fn_802D3050(s32);
extern void fn_802D306C(s32);
typedef struct { u8 pad[0x24]; f32 x; f32 y; f32 z; } unk_80203A88_dest;
void fn_802039CC(s32 arg0, struct lbl_80488B88_t* arg1);
extern s32 fn_802C8DBC(s32, ...);
extern void fn_80202D50();
extern void fn_802C8B98(s32, s32);
extern f32 PSVECMag(const void *);
extern float __fabsf(float);
extern double __fabs(double);
extern double fn_8002F234(f32, f32);
extern double fn_8002EFB0(f32, f32);
extern void *fn_802C9A40(void);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);
extern double cos(double);
extern double sin(double);
extern f32 lbl_805630D8, lbl_805630F0, lbl_805630F4, lbl_805630F8, lbl_805630FC;
extern f32 lbl_80563100, lbl_80563104, lbl_80563110;
extern f64 lbl_80563108, lbl_80563118;

u32 fn_80202BE4(void) {
    return (u32)((2 - lbl_8055ED14) | (lbl_8055ED14 - 2)) >> 0x1FU;
}

extern s32 lbl_805630B8, lbl_805630C0, lbl_805630C4;
extern f32 lbl_805630C8, lbl_805630CC, lbl_805630D0, lbl_805630D4;
extern u16 lbl_802F9D48[];
extern void fn_802C8C04(s32);
extern void fn_802C8DB8(f32*, s32, u16*, s32, u16, u16, u16, u16);
void fn_80202BFC(s32 arg0) {
    f32 sp84, sp80, sp78, sp74, sp70, sp6C, sp68, sp60, sp5C, sp58, sp54, sp50, sp48, sp44, sp40, sp3C, sp38, sp30, sp2C, sp28;
    s32 sp7C, sp64, sp4C, sp34, sp14, sp10, spC, sp8;
    u16 sp22, sp20, sp1E, sp1C, sp1A, sp18;
    f32 f28 = lbl_805630C8, f29 = lbl_805630CC, f30 = lbl_805630D0, f31 = lbl_805630D4;
    s32 *p1 = &sp10, *p2 = &sp8;
    s32 i = 0;
    sp10=lbl_805630B8; sp8=lbl_805630C0; spC=lbl_805630C4; sp14=arg0;
    do {
        fn_802C8C04(*p1);
        sp18=lbl_802F9D48[0]; sp1A=lbl_802F9D48[1]; sp1C=lbl_802F9D48[2]; sp1E=lbl_802F9D48[3]; sp20=lbl_802F9D48[4]; sp22=lbl_802F9D48[5];
        sp28=f28; sp2C=f28; sp30=f29; sp40=f30; sp44=f28; sp48=f29; sp58=f28; sp5C=f30; sp60=f29; sp70=f30; sp74=f30; sp78=f29; sp68=f29; sp38=f29; sp80=f31; sp50=f31; sp54=f29; sp3C=f29; sp84=f31; sp6C=f31;
        sp7C=*p2; sp64=*p2; sp4C=*p2; sp34=*p2;
        fn_802C8DB8(&sp28,4,&sp18,6,lbl_802F9D48[4],lbl_802F9D48[3],lbl_802F9D48[2],lbl_802F9D48[1]);
        fn_802C8D74(); i++; p1++; p2++;
    } while(i<2);
}

#pragma paired_single off
void fn_80202F58(void *arg0, void *arg1, void *arg2) {
    union { f32 f; u32 u; } work[28];
    f32 temp_f0, temp_f0_2, temp_f0_3;
    f32 temp_f1, temp_f1_2, temp_f1_3, temp_f1_4, temp_f1_5, temp_f1_6, temp_f1_7, temp_f1_8;
    f32 temp_f2, temp_f2_2, temp_f2_3;
    f32 temp_f30, temp_f30_2, temp_f30_3, temp_f31;
    f32 temp_f3, temp_f3_10, temp_f3_2, temp_f3_3, temp_f3_4, temp_f3_5, temp_f3_6, temp_f3_7, temp_f3_8, temp_f3_9;
    f32 temp_f4, temp_f4_2, temp_f4_3, temp_f5, temp_f5_2, temp_f6, temp_f6_2, temp_f7;
    f32 var_f1, var_f2;
    f64 temp_f29;
    void *temp_r3;
    f32 scale, zero, one;
    u32 copy0, copy1;

    if ((f32)__fabs((double)(*(f32 *)((u8 *)arg1 + 0x1C))) < lbl_805630F0) {
        temp_f6 = (*(f32 *)((u8 *)arg0 + 0)) - (*(f32 *)((u8 *)arg1 + 0x24));
        temp_f3 = (*(f32 *)((u8 *)arg0 + 8)) - (*(f32 *)((u8 *)arg1 + 0x2C));
        temp_f5 = (*(f32 *)((u8 *)arg0 + 4));
        temp_f1 = temp_f6 * lbl_805630F4;
        work[13].f = temp_f6;
        temp_f4 = temp_f5 - (*(f32 *)((u8 *)arg1 + 0x28));
        temp_f0 = temp_f3 * lbl_805630F4;
        work[15].f = temp_f3;
        work[14].f = temp_f4;
        work[25].f = lbl_805630CC;
        work[26].f = lbl_805630CC;
        work[27].f = lbl_805630CC;
        work[22].f = temp_f1;
        work[24].f = temp_f0;
        work[23].f = lbl_805630CC;
        temp_f1_2 = PSVECMag((const void *)&work[22].f);
        var_f2 = lbl_805630D8;
        var_f2 = var_f2 > temp_f1_2 ? var_f2 : temp_f1_2;
        temp_f4_2 = lbl_805630D4 / var_f2;
        temp_f3_2 = work[22].f * temp_f4_2;
        temp_f2 = work[23].f * temp_f4_2;
        temp_f1_3 = work[24].f * temp_f4_2;
        work[22].f = temp_f3_2;
        work[23].f = temp_f2;
        work[24].f = temp_f1_3;
        work[19].f = lbl_805630CC;
        work[20].f = lbl_805630D4;
        work[21].f = lbl_805630CC;
        work[10].u = work[13].u;
        work[11].u = work[14].u;
        work[12].u = work[15].u;
        fn_80202D50((void *)&work[10].f);
        PSVECCrossProduct((f32 *)&work[19].f, (f32 *)&work[22].f, (f32 *)&work[16].f);
        fn_802C8B98(lbl_8055ED00, (s32)&work[16].f);
        copy0 = ((volatile u32 *)&work[16].f)[0];
        copy1 = ((volatile u32 *)&work[16].f)[1];
        scale = lbl_805630F4;
        (*(u32 *)((u8 *)arg2 + 0)) = copy0;
        (*(u32 *)((u8 *)arg2 + 4)) = copy1;
        (*(u32 *)((u8 *)arg2 + 8)) = ((volatile u32 *)&work[16])[2];
        (*(u32 *)((u8 *)arg2 + 0xC)) = ((volatile u32 *)&work[16].f)[3];
        (*(u32 *)((u8 *)arg2 + 0x10)) = ((volatile u32 *)&work[16].f)[4];
        (*(u32 *)((u8 *)arg2 + 0x14)) = ((volatile u32 *)&work[16].f)[5];
        (*(u32 *)((u8 *)arg2 + 0x18)) = ((volatile u32 *)&work[16].f)[6];
        (*(u32 *)((u8 *)arg2 + 0x1C)) = ((volatile u32 *)&work[16].f)[7];
        (*(u32 *)((u8 *)arg2 + 0x20)) = ((volatile u32 *)&work[16].f)[8];
        (*(u32 *)((u8 *)arg2 + 0x24)) = ((volatile u32 *)&work[16].f)[9];
        (*(u32 *)((u8 *)arg2 + 0x28)) = ((volatile u32 *)&work[16].f)[10];
        (*(u32 *)((u8 *)arg2 + 0x2C)) = ((volatile u32 *)&work[16].f)[11];
        (*(f32 *)((u8 *)arg2 + 0)) = (f32)((*(f32 *)((u8 *)arg2 + 0)) * scale);
        (*(f32 *)((u8 *)arg2 + 4)) = (f32)((*(f32 *)((u8 *)arg2 + 4)) * scale);
        (*(f32 *)((u8 *)arg2 + 8)) = (f32)((*(f32 *)((u8 *)arg2 + 8)) * scale);
    } else {
        work[4].f = lbl_805630CC;
        work[5].f = lbl_805630CC;
        work[6].f = lbl_805630D4;
        work[7].f = work[4].f;
        work[8].f = work[5].f;
        work[9].f = work[6].f;
        fn_80202D50((void *)&work[7].f);
        fn_802C8BD0(lbl_8055ED00);
        zero = lbl_805630CC;
        one = lbl_805630D4;
        (*(f32 *)((u8 *)arg2 + 4)) = zero;
        (*(f32 *)((u8 *)arg2 + 0)) = one;
        (*(f32 *)((u8 *)arg2 + 8)) = zero;
        (*(f32 *)((u8 *)arg2 + 0xC)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x10)) = one;
        (*(f32 *)((u8 *)arg2 + 0x14)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x18)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x1C)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x20)) = one;
        (*(f32 *)((u8 *)arg2 + 0x24)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x28)) = zero;
        (*(f32 *)((u8 *)arg2 + 0x2C)) = zero;
    }
    if (fn_802C8DBC(4) != 0) {
        temp_r3 = fn_802C9A40();
        temp_f0 = (*(f32 *)((u8 *)temp_r3 + 0));
        temp_f2_2 = (*(f32 *)((u8 *)temp_r3 + 8));
        work[2].f = temp_f0;
        work[3].f = temp_f2_2;
        temp_f0_2 = (f32)fn_8002F234((temp_f0 * temp_f0) + (temp_f2_2 * temp_f2_2), temp_f2_2);
        var_f1 = lbl_805630F8;
        var_f1 = var_f1 > temp_f0_2 ? var_f1 : temp_f0_2;
        temp_f4_3 = lbl_805630D4 / var_f1;
        temp_f3_3 = work[2].f * temp_f4_3;
        temp_f0_3 = temp_f3_3 * lbl_805630F4;
        temp_f2_3 = work[3].f * temp_f4_3 * lbl_805630F4;
        work[2].f = temp_f0_3;
        work[3].f = temp_f2_3;
        temp_f1_4 = (f32)fn_8002EFB0(-temp_f0_3, temp_f2_3);
        temp_f31 = lbl_805630FC;
        work[0].f = temp_f31;
        temp_f29 = -temp_f1_4;
        work[1].f = lbl_80563100;
        temp_f30 = (f32)cos(temp_f29);
        temp_f3_4 = (f32)sin(temp_f29);
        temp_f1_5 = ((f32)temp_f31 * temp_f30) - (work[1].f * temp_f3_4);
        work[0].f = temp_f1_5;
        temp_f3_5 = (temp_f31 * temp_f3_4) + (work[1].f * temp_f30);
        work[1].f = temp_f3_5;
        fn_802C8E00(-1, 0, temp_f1_5, lbl_805630CC, temp_f3_5, lbl_80563104, lbl_80563104);
        temp_f30_2 = (f32)cos(lbl_80563108);
        temp_f5_2 = (f32)sin(lbl_80563108);
        temp_f7 = work[0].f * temp_f30_2;
        temp_f6_2 = temp_f3_5 * temp_f5_2;
        temp_f3_6 = (work[0].f * temp_f5_2) + (temp_f3_5 * temp_f30_2);
        temp_f1_6 = temp_f7 - temp_f6_2;
        work[1].f = temp_f3_6;
        work[0].f = temp_f1_6;
        ((void (*)(s32, s32, f32, f32, f32, f32, f32, f32, f32))fn_802C8E00)(-1, 0, temp_f1_6, lbl_805630CC, temp_f3_6, lbl_80563110, lbl_80563104, temp_f6_2, temp_f7);
        temp_f1_7 = temp_f1_6 * lbl_805630F4;
        temp_f3_7 = work[1].f * lbl_805630F4;
        work[0].f = temp_f1_7;
        work[1].f = temp_f3_7;
        fn_802C8E00(-1, 1, temp_f1_7, lbl_805630CC, temp_f3_7, lbl_80563104, lbl_80563110);
        temp_f30_3 = (f32)cos(lbl_80563118);
        temp_f3_8 = (f32)sin(lbl_80563118);
        temp_f3_9 = work[0].f * temp_f3_8;
        temp_f1_8 = (work[0].f * temp_f30_3) - (work[1].f * temp_f3_8);
        work[0].f = temp_f1_8;
        temp_f3_10 = temp_f3_9 + (work[1].f * temp_f30_3);
        work[1].f = temp_f3_10;
        fn_802C8E00(-1, 1, temp_f1_8, lbl_805630CC, temp_f3_10, lbl_80563110, lbl_80563110);
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma paired_single reset
extern s32 fn_802C8DBC(s32, ...);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);
extern double fn_801DCF48(s32, f32, f32);
extern f32 PSVECMag(const void *);
extern double cos(double);
extern double sin(double);
extern u32 lbl_802F9D58[4];
extern f32 lbl_805630CC;
extern f32 lbl_805630D4;
extern f32 lbl_805630E0;
extern double lbl_805630E8;
extern f32 lbl_805630F8;
extern f32 lbl_80563120;
extern f32 lbl_80563124;
extern f32 lbl_80563128;
extern f32 lbl_805630CC, lbl_805630D4, lbl_805630E0, lbl_805630F8;
extern f32 lbl_80563120, lbl_80563124, lbl_80563128;
#pragma scheduling invalid_target
void fn_80203380(void *argp) {
    f32 *arg0 = (f32 *)argp;
    struct {
        volatile f32 radius;
        volatile f32 height;
        f32 vec2[3];
        f32 vec1[3];
        volatile f32 x;
        volatile f32 y;
        volatile f32 z;
        f32 pad;
        u32 heights[4];
        u32 cvt[2];
    } work;
    u32 *data;
    f32 *height;
    f32 secondY, colorScale, one, minMag, radius, angleDivisor, angleScale;
    double bias;
    s32 angle;
    u32 row;
    s32 count;
    u32 first, second, third, fourth;

    fn_802C8BD0(-1);
    data = lbl_802F9D58;
    first = *data++;
    second = data[0];
    third = data[1];
    fourth = data[2];
    work.heights[0] = first;
    work.heights[1] = second;
    work.heights[2] = third;
    work.heights[3] = fourth;
    fn_802C8DBC(0xA0, third, second, first);

    minMag = lbl_805630F8;
    height = (f32 *)work.heights;
    bias = lbl_805630E8;
    one = lbl_805630D4;
    angleScale = lbl_805630E0;
    angleDivisor = lbl_80563120;
    radius = lbl_805630CC;
    colorScale = lbl_80563124;
    secondY = lbl_80563128;

    for (row = 0; row < 4; row++, height++) {
        f32 h = *height;
        for (count = 0, angle = 0; count < 0x14; count++, angle += 2) {
            union { f64 d; u32 w[2]; } *cvt = (void *)work.cvt;
            f32 c, theta, s, x, z, y, q0, q1, q2, q3, baseX, baseZ, dx, dy, dz, mag, scale, denom, t0, t1, t2, t3, t4, t5;

            work.radius = radius;
            work.height = h;
            cvt->w[0] = 0x43300000;
            cvt->w[1] = ((u32)angle) ^ 0x80000000U;
            theta = angleScale * (f32)(cvt->d - bias) / angleDivisor;
            c = (f32)cos((double)theta);
            s = (f32)sin((double)theta);
            baseX = arg0[9];
            q0 = h * c;
            q1 = radius * s;
            q2 = radius * c;
            baseZ = arg0[11];
            q3 = h * s;
            z = (q1 + q0) + baseZ;
            x = (q2 - q3) + baseX;
            work.height = z;
            work.radius = x;
            y = (f32)fn_801DCF48(0, x, z);
            work.y = y;
            work.x = work.radius;
            work.z = z;

            dx = work.radius - arg0[9];
            dy = work.y - arg0[10];
            dz = z - arg0[11];
            t0 = dy * arg0[1];
            t1 = dx * arg0[0];
            t2 = dx * arg0[3];
            t3 = dy * arg0[4];
            t4 = dx * arg0[6];
            t5 = dy * arg0[7];
            t1 = t1 + t0;
            t2 = t2 + t3;
            t4 = t4 + t5;
            t0 = dz * arg0[2];
            t3 = dz * arg0[5];
            t5 = dz * arg0[8];
            work.vec1[0] = t0 + t1;
            work.vec1[1] = t3 + t2;
            work.vec1[2] = t5 + t4;
            mag = PSVECMag((const void *)work.vec1);
            if (minMag > mag) {
                mag = minMag;
                scale = one / mag;
                work.vec1[0] *= scale;
                work.vec1[1] *= scale;
                work.vec1[2] *= scale;
                denom = one + work.vec1[1];
                fn_802C8E00((s32)0xFF000000, 1,
                    (colorScale * work.vec1[0]) / denom, lbl_805630CC,
                    (colorScale * work.vec1[2]) / denom, lbl_805630CC, lbl_805630CC);
            }

            dx = work.x - arg0[9];
            dy = secondY - arg0[10];
            dz = z - arg0[11];
            t0 = dy * arg0[1];
            t1 = dx * arg0[0];
            t2 = dx * arg0[3];
            t3 = dy * arg0[4];
            t4 = dx * arg0[6];
            t5 = dy * arg0[7];
            t1 = t1 + t0;
            t2 = t2 + t3;
            t4 = t4 + t5;
            t0 = dz * arg0[2];
            t3 = dz * arg0[5];
            t5 = dz * arg0[8];
            work.vec2[0] = t0 + t1;
            work.vec2[1] = t3 + t2;
            work.vec2[2] = t5 + t4;
            mag = PSVECMag((const void *)work.vec2);
            if (minMag > mag) {
                mag = minMag;
                scale = one / mag;
                work.vec2[0] *= scale;
                work.vec2[1] *= scale;
                work.vec2[2] *= scale;
                denom = one + work.vec2[1];
                fn_802C8E00((s32)0xFF000000, 1,
                    (colorScale * work.vec2[0]) / denom, lbl_805630CC,
                    (colorScale * work.vec2[2]) / denom, lbl_805630CC, lbl_805630CC);
            }
        }
    }
    fn_802C8E48();
    fn_802C8D74();
}
#pragma scheduling invalid_target
void fn_802039CC(s32 arg0, struct lbl_80488B88_t* arg1) {
    struct lbl_80488B88_t* dest;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
    s32 w4;
    s32 w5;
    s32 w6;
    s32 w7;
    s32 w8;
    s32 w9;
    s32 w10;
    s32 w11;

    lbl_8055ED1C = -1;
    fn_802C8BD0(-1);
    dest = &lbl_80488B88;
    w0 = arg1->w[0];
    w1 = arg1->w[1];
    w2 = arg1->w[2];
    w3 = arg1->w[3];
    w4 = arg1->w[4];
    w5 = arg1->w[5];
    w6 = arg1->w[6];
    w7 = arg1->w[7];
    w8 = arg1->w[8];
    w9 = arg1->w[9];
    w10 = arg1->w[10];
    w11 = arg1->w[11];
    dest->w[0] = w0;
    dest->w[1] = w1;
    dest->w[2] = w2;
    dest->w[3] = w3;
    dest->w[4] = w4;
    dest->w[5] = w5;
    dest->w[6] = w6;
    dest->w[7] = w7;
    dest->w[8] = w8;
    dest->w[9] = w9;
    dest->w[10] = w10;
    dest->w[11] = w11;
    fn_802BE07C(arg0 + 0x24, (s32)fn_802036E4, w10, w9, w8, w7, w6, w5);
    fn_802C8D74();
}
#pragma scheduling on
void fn_80203A88(void* arg0, s32 arg1, unk_80203A88_dest* arg2) {
    f32 var_f0;
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;
    volatile f32* input = (volatile f32*)arg0;

    if (fn_80202BE4() == 0) {
        fn_802D3050(1);
        fn_802D306C(0x5A);
        var_f2 = input[1];
        var_f0 = lbl_80563130;
        var_f3 = input[0];
        var_f0 = var_f2 + var_f0;
        var_f1 = input[2];
        arg2->x = var_f3;
        arg2->z = var_f1;
        arg2->y = var_f0;
        fn_802039CC(arg1, (struct lbl_80488B88_t*)arg2);
        fn_80203380(arg2);
        fn_802D306C(0);
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80203B20(s32 arg0, s32 arg1, s32 arg2) {
    u8 stack[0x60];

    fn_802CB274(lbl_8055ECFC);
    if (lbl_8055ED08 == 0)
        return;
    fn_802C9294(lbl_8055ECFC, 0);
    ((f32 *)(stack + 0x30))[9] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[10] = lbl_80563134;
    ((f32 *)(stack + 0x30))[11] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[0] = lbl_805630D4;
    ((f32 *)(stack + 0x30))[1] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[2] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[3] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[4] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[5] = lbl_805630D4;
    ((f32 *)(stack + 0x30))[6] = lbl_805630CC;
    ((f32 *)(stack + 0x30))[7] = lbl_805630F4;
    ((f32 *)(stack + 0x30))[8] = lbl_805630CC;
    fn_802C8638((f32 *)(stack + 0x30), lbl_805630D4, lbl_80563134, lbl_805630CC);
    fn_802C87B4(0, 0, 0x100, 0x100);
    fn_802C974C(lbl_805630D4, lbl_80563138, lbl_8056313C);
    fn_802C86E8(0xFF00FF00);
    fn_802C88BC(-1);
    fn_80202F58((void *)arg1, (void *)arg0, (s32 *)stack);
    if (fn_80202BE4() == 0 && arg2 != 0)
        fn_80203A88((void *)arg1, arg0, (unk_80203A88_dest *)stack);
    fn_802C9294(-1, 0);
    lbl_8055ED08 = (u8)((u32)__cntlzw((u32)lbl_8055ED08) >> 5);
}
#pragma pop
extern s32 fn_8012C33C(char *);
extern void fn_801345D8(char *, s32, const char *, ...);
extern s32 fn_802CAC28(const char *, s32);
extern s32 fn_802CAE98(s32, const char *);
extern s32 fn_802CAF1C(s32, s32, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern const char lbl_8033BA88[];
extern u8 lbl_8055ED08;
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw on
void fn_80203C50(s32 arg0) {
    char name[0x20];
    const char *base;
    const char *first;
    s32 i;
    s32 count;
    lbl_8048897C_entry *entries;
    s32 resource;

    base = lbl_8033BA88;
    lbl_8055ED14 = arg0;
    lbl_8055ED18 = 1;
    first = base;
    if (arg0 == 1) {
        first = base + 0xC;
    }
    lbl_8055ED00 = fn_802CAC28(first, 0);
    lbl_8055ED04 = fn_802CAC28(lbl_8033BA88 + 0x18, 0);
    lbl_8055ED0C = fn_802CAC28(lbl_8033BA88 + 0x24, 0);

    for (i = 0; i < 0x5A; i++) {
        fn_801345D8(name, 0x20, lbl_8033BA88 + 0x30, i);
        if (fn_8012C33C(name) != 0) {
            resource = fn_802CAC28(name, 0);
            count = lbl_8048897C.count;
            entries = lbl_8048897C.ptr;
            lbl_8048897C.count = count + 1;
            entries[count].w0 = resource;
            entries[count].w1 = i;
        }
    }

    resource = fn_802CB128(0x100, 0x100, 0, 1);
    lbl_8055ECFC = resource;
    fn_802CAE98(resource, base);
    fn_802CAE98(lbl_8055ED00, lbl_8033BA88 + 0x3C);
    fn_802CAF1C(lbl_8055ECFC, 6, 0x50);
    fn_80202BE4();
    lbl_8055ED08 = 1;
}
#pragma pop
void fn_80203D84(s32* arg0) {
    s32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}
#pragma dont_inline off

#pragma scheduling invalid_target
void fn_80203DC8(void) {
    struct lbl_8048897C_t* var_r30;
    struct lbl_8048897C_t* var_r31;
    s32 var_r29;
    s32 var_r28;
    s32 temp;

    temp = lbl_8055ECFC;
    *(volatile u8*)&lbl_8055ED18 = 0;
    if (temp != -2) {
        fn_802CB228();
        lbl_8055ECFC = -2;
    }
    fn_80203D84(&lbl_8055ED00);
    fn_80203D84(&lbl_8055ED04);
    fn_80203D84(&lbl_8055ED0C);
    ((void(*)(void*))fn_802D050C)(0);
    fn_802D30DC(0);
    var_r30 = (struct lbl_8048897C_t*)((s32)&lbl_8048897C - 0x8000);
    var_r31 = (struct lbl_8048897C_t*)((s32)var_r30 + 0x8000);
    var_r28 = 0;
    var_r29 = 0;
    while (var_r28 < var_r31->count) {
        fn_80203D84((s32*)((u8*)lbl_8048897C.ptr + var_r29));
        var_r29 += 8;
        var_r28 += 1;
    }
    var_r31->count = 0;
}
#pragma scheduling on
extern void fn_802D050C(void*);
void fn_80203E88(void) {
    ((void (*)(void))fn_80203B20)();
    fn_802CA294(lbl_8055ECFC);
    fn_802D9230();
    fn_802CA294(lbl_8055ED04);
    fn_802D050C(0);
}

void fn_80203EC0(void) {

}

void fn_80203EC4(void) {
    if (fn_80202BE4() == 0) {
        fn_802CB288(lbl_8055ECFC);
    }
}

void fn_80203EF4(void) {
    if (lbl_8055ED10 == 0) {
        return;
    }
    fn_80202BFC(lbl_8055ECFC);
}

void fn_80203F0C(void) {

}

