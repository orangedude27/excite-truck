// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

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
extern void fn_80203B20(void);
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

extern void fn_802C8DBC(s32, s32, s32, s32);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);
extern double fn_801DCF48(s32, f32, f32);
extern f32 PSVECMag(const void *);
extern double cos(f32);
extern double sin(f32);
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
#pragma scheduling on
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
            register f32 s;
            f32 c, theta, x, z, y, q0, q1, q2, q3, baseX, baseZ, dx, dy, dz, mag, scale, denom, t0, t1, t2, t3, t4, t5;

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
#pragma scheduling reset
void fn_802039CC(s32 arg0, struct lbl_80488B88_t* arg1) {
    struct lbl_80488B88_t* var_r28;
    s32 temp_r0;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r12;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r31;

    lbl_8055ED1C = -1;
    fn_802C8BD0(-1);
    temp_r29 = arg1->w[0];
    temp_r30 = arg1->w[1];
    temp_r31 = arg1->w[2];
    temp_r12 = arg1->w[3];
    temp_r11 = arg1->w[4];
    temp_r10 = arg1->w[5];
    temp_r9 = arg1->w[6];
    temp_r8 = arg1->w[7];
    temp_r7 = arg1->w[8];
    temp_r6 = arg1->w[9];
    temp_r5 = arg1->w[10];
    temp_r0 = arg1->w[11];
    var_r28 = &lbl_80488B88;
    var_r28->w[0] = temp_r29;
    var_r28->w[1] = temp_r30;
    var_r28->w[2] = temp_r31;
    var_r28->w[3] = temp_r12;
    var_r28->w[4] = temp_r11;
    var_r28->w[5] = temp_r10;
    var_r28->w[6] = temp_r9;
    var_r28->w[7] = temp_r8;
    var_r28->w[8] = temp_r7;
    var_r28->w[9] = temp_r6;
    var_r28->w[10] = temp_r5;
    var_r28->w[11] = temp_r0;
    fn_802BE07C(arg0 + 0x24, (s32)fn_802036E4, temp_r5, temp_r6, temp_r7, temp_r8, temp_r9, temp_r10);
    fn_802C8D74();
}

void fn_80203A88(void* arg0, s32 arg1, unk_80203A88_dest* arg2) {
    f32 var_f2;
    f32 var_f3;
    f32 var_f1;

    if (fn_80202BE4() == 0) {
        fn_802D3050(1);
        fn_802D306C(0x5A);
        var_f2 = ((f32*)arg0)[1];
        var_f3 = ((f32*)arg0)[0];
        var_f1 = ((f32*)arg0)[2];
        arg2->x = var_f3;
        arg2->z = var_f1;
        arg2->y = var_f2 + lbl_80563130;
        fn_802039CC(arg1, (struct lbl_80488B88_t*)arg2);
        fn_80203380(arg2);
        fn_802D306C(0);
    }
}

extern s32 fn_8012C33C(char *);
extern void fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802CAC28(const char *, s32);
extern s32 fn_802CAE98(s32, const char *);
extern s32 fn_802CAF1C(s32, s32, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern const char lbl_8033BA88[];
extern u8 lbl_8055ED08;
void fn_80203C50(s32 arg0) {
    char name[0x20];
    const char *base;
    s32 i, count, resource;
    lbl_8055ED14 = arg0;
    lbl_8055ED18 = 1;
    base = lbl_8033BA88;
    if (arg0 == 1) base += 0xC;
    lbl_8055ED00 = fn_802CAC28(base, 0);
    lbl_8055ED04 = fn_802CAC28(lbl_8033BA88 + 0x18, 0);
    lbl_8055ED0C = fn_802CAC28(lbl_8033BA88 + 0x24, 0);
    for (i = 0; i < 0x5A; i++) {
        fn_801345D8(name, 0x20, lbl_8033BA88 + 0x30, i);
        if (fn_8012C33C(name) != 0) {
            resource = fn_802CAC28(name, 0);
            count = lbl_8048897C.count;
            lbl_8048897C.count = count + 1;
            lbl_8048897C.ptr[count].w0 = resource;
            lbl_8048897C.ptr[count].w1 = i;
        }
    }
    lbl_8055ECFC = fn_802CB128(0x100, 0x100, 0, 1);
    fn_802CAE98(0, lbl_8033BA88);
    fn_802CAE98(lbl_8055ED00, lbl_8033BA88 + 0x3C);
    fn_802CAF1C(lbl_8055ECFC, 6, 0x50);
    fn_80202BE4();
    lbl_8055ED08 = 1;
}

void fn_80203D84(s32* arg0) {
    s32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}
#pragma dont_inline off

void fn_80203DC8(void) {
    struct lbl_8048897C_t* var_r30;
    struct lbl_8048897C_t* var_r31;
    s32 var_r28;
    s32 var_r29;

    lbl_8055ED18 = 0;
    if (lbl_8055ECFC != -2) {
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
    var_r29 = 0;
    var_r28 = 0;
    while (var_r29 < var_r31->count) {
        fn_80203D84((s32*)((u8*)lbl_8048897C.ptr + var_r28));
        var_r28 += 8;
        var_r29 += 1;
    }
    var_r31->count = 0;
}

extern void fn_802D050C(void*);
void fn_80203E88(void) {
    fn_80203B20();
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

