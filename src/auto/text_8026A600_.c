// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80499E60[];
extern float PSVECDotProduct(const void *, const void *);
extern void Camera_InitBlock(void *);
extern void Camera_InitSplineCursor(void *);
/* Initialize a 0x228-byte camera object's two embedded state blocks - the one at
   +0x160 and the spline cursor at +0x178 - through their init helpers. */
void *fn_8026A600(void *camera) {
#define InitCameraBlock_160 Camera_InitBlock /* zeroes the 0x18-byte block at camera+0x160 */
#define InitCameraSplineCursor Camera_InitSplineCursor /* zeroes the spline cursor at camera+0x178 */
    InitCameraBlock_160((char *)camera + 0x160);
    InitCameraSplineCursor((char *)camera + 0x178);
    return camera;
#undef InitCameraBlock_160
#undef InitCameraSplineCursor
}

#pragma scheduling invalid_target
/* How far `point` lies along `direction` measured from `origin`:
 * dot(point - origin, direction).  The difference is built on the stack as a
 * plain 3-float vector before PSVECDotProduct; the camera code calls it with a
 * terrain ray hit, the ray's start and the ray's (normalised) direction to get
 * the distance the ray travelled (fn_8026A698). */
float fn_8026A63C(const float *point, const float *origin, const float *direction) {
    float diff[3];
    float dx = point[0];
    dx -= origin[0];
    diff[0] = dx;
    diff[1] = point[1] - origin[1];
    diff[2] = point[2] - origin[2];
    return PSVECDotProduct(diff, direction);
}

extern float lbl_80558DC4;
extern int lbl_8055E3C4;
extern float lbl_80563D18;
extern float lbl_80563D10;
extern float lbl_80563D14;
extern float lbl_80563D20;
extern float lbl_80563D24;
extern float lbl_80563D28;
extern float lbl_80563D2C;
extern float lbl_80563D1C;
extern int fn_801CF064(void);
extern void fn_80176A00(int);
extern int fn_80178CA4(void);
extern int fn_801B8570(int);
extern int fn_8026A38C(void);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern float lbl_80563D08;
extern float lbl_80563D30;
extern float lbl_80563D34;
extern float lbl_80563D38;
extern float lbl_80563D3C;
extern float lbl_80563D40;
extern float lbl_80563D44;
extern float lbl_80563D48;
extern float lbl_80563D4C;
extern float lbl_80563D50;
extern float lbl_80563D54;
extern float lbl_80563D58;
extern float lbl_80563D5C;
extern double lbl_80563D60;
extern void fn_80015A20(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern double fn_8002EFB0(float, float);
extern int fn_801784AC(void *, void *, void *, void *, void *, void *, int);
extern int fn_801EA03C(void *, void *);
extern void fn_80176A24(float);
extern void fn_8026E22C(void *, void *, void *, float);
extern double atan(double, double);
extern double fabs(double);
extern double __fabs(double);
#pragma push
#pragma processor 750
int fn_8026A698(void *arg0, int arg1) {
    char *p = (char *)arg0;
    char *o = *(char **)(p + 0x140);
    char *e = (char *)lbl_80499E60 + arg1 * 0x6C;
    int flag = 1;
    int r, inv, s, use;
    float t;
    float sp10, sp14;
    float mtxStart[3], mtxEnd[3];
    float spA8[3], spB4[3];
    float mtx114[9], mtxF0[9], mtxCC[9], mtx138[9];
    float ang114[3], angF0[3], angCC[3];
    float rayHit[3], rayVal[3], sp8_, spC_, sp9C_;
    float sp18[3], sp48[3], sp3C[3], sp24[3];
    float sp54[3], sp60[3], sp6C[3];
    float sp78_, sp7C_, sp80_;
    float v0, f30, f31, f29;
    int i;
    float a0, a1, a2, c0, c1, c2;
    float d0, d1, d2;
    float t3, t4, t5;
    float fv, fv2;
    int mode;

    if ((unsigned)(*(int *)(o + 0x10) + 0xAFBD0000) == 0x4152U) {
        char *q = *(char **)(o + 0x270C);
        int (*f)(void *) = *(int (**)(void *))(*(char **)q + 0x14);
        if (f(q) & 0x20) flag = 0;
    }
    mode = *(int *)(p + 0x10);
    if (fn_801CF064() != 0 || mode == 0x11 || mode == 0x15 ||
        (*(int *)((char *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x4000) || flag != 0) {
        if (*(unsigned char *)e) fn_80176A00(1);
        *(float *)(e + 0x60) = lbl_80563D18;
        *(unsigned char *)e = 0;
        return 0;
    }

    r = fn_80178CA4();
    inv = r ^ 1;
    s = (unsigned)((inv >> 1) - (inv & r)) >> 31;
    use = 0;
    t = *(float *)(o + 0x2690);
    if ((float)fabs(t) > lbl_80558DC4) {
        if (fn_801B8570(*(int *)(o + 0x1EC)) != 0) use = 1;
    }
    if (use == 0) {
        *(float *)(e + 0x60) = lbl_80563D18;
        if (*(unsigned char *)e) {
            *(unsigned char *)e = 0;
            if (s == 0) *(char *)(p + 0x138) = 1;
            fn_80176A00(1);
        }
        return 0;
    }
    if (s != 0) {
        *(unsigned char *)e = 1;
        return 0;
    }
    if (fn_8026A38C() != 0) {
        *(unsigned char *)e = 0;
        fn_80176A00(1);
        return 0;
    }
    if (*(unsigned char *)e != 0) {
        *(char *)(p + 0x138) = 0;
        goto common;
    }

    sp10 = lbl_80563D10;
    sp14 = lbl_80563D14;
    f30 = lbl_80563D18;
    f31 = lbl_80563D24;
    f29 = lbl_80563D28;
    for (i = 0; i < 2; i++) {
        c0 = *(float *)(o + 0xE4);
        c1 = *(float *)(o + 0xE8);
        c2 = *(float *)(o + 0xEC);
        v0 = (i != 0) ? lbl_80563D1C : lbl_80563D20;
        spB4[0] = v0; spB4[1] = f30; spB4[2] = f30;
        a0 = (f30 * *(float *)(o + 0xD8)) + ((v0 * *(float *)(o + 0xC0)) + (f30 * *(float *)(o + 0xCC)));
        a1 = (f30 * *(float *)(o + 0xDC)) + ((v0 * *(float *)(o + 0xC4)) + (f30 * *(float *)(o + 0xD0)));
        a2 = (f30 * *(float *)(o + 0xE0)) + ((v0 * *(float *)(o + 0xC8)) + (f30 * *(float *)(o + 0xD4)));
        spA8[0] = a0; spA8[1] = a1; spA8[2] = a2;
        mtxStart[0] = c0 + a0 * f31;
        mtxStart[1] = c1 + a1 * f31;
        mtxStart[2] = c2 + a2 * f31;
        mtxEnd[0] = mtxStart[0] + a0 * f29;
        mtxEnd[1] = mtxStart[1] + a1 * f29;
        mtxEnd[2] = mtxStart[2] + a2 * f29;
        if (fn_801784AC(mtxStart, mtxEnd, rayHit, rayVal, &sp9C_, &sp8_, 0) != 0) {
            if (i == 0) sp10 = fn_8026A63C(rayHit, mtxStart, spA8);
            else sp14 = fn_8026A63C(rayHit, mtxStart, spA8);
        }
    }
    *(char *)(p + 0x138) = 1;
    *(unsigned char *)e = 1;
    *(int *)(e + 4) = *(int *)(p + 0x88);
    *(int *)(e + 8) = *(int *)(p + 0x8C);
    *(int *)(e + 0xC) = *(int *)(p + 0x90);
    *(int *)(e + 0x10) = *(int *)(p + 0x94);
    *(int *)(e + 0x14) = *(int *)(p + 0x98);
    *(int *)(e + 0x18) = *(int *)(p + 0x9C);
    *(float *)(e + 0x1C) = *(float *)(p + 0xA0);
    *(int *)(e + 0x20) = *(int *)(p + 0xA4);
    *(float *)(e + 0x24) = *(float *)(p + 0xA8);
    *(int *)(e + 0x28) = *(int *)(p + 0xAC);
    *(int *)(e + 0x2C) = *(int *)(p + 0xB0);
    *(int *)(e + 0x30) = *(int *)(p + 0xB4);
    *(float *)(e + 0x34) = *(float *)(p + 0x194);
    *(float *)(e + 0x38) = (float)fn_8002EFB0(*(float *)(e + 0x1C), *(float *)(e + 0x24));
    f29 = lbl_80563D2C;
    if (!(PSVECDotProduct((char *)(*(void **)(p + 0x140)) + 0x118, p + 0xC0) > lbl_80563D18)) f29 = -f29;
    *(float *)(e + 0x64) = f29;
    t = sp10;
    if (t < sp14) t = sp14;
    if (t < lbl_80563D30) {
        if (sp10 > sp14) *(float *)(e + 0x64) = -(float)fabs(*(float *)(e + 0x64));
        else *(float *)(e + 0x64) = (float)fabs(*(float *)(e + 0x64));
    }
    if (*(float *)(e + 0x64) > lbl_80563D18) *(float *)(e + 0x38) += lbl_80563D2C;
    else *(float *)(e + 0x38) -= lbl_80563D2C;
    *(float *)(e + 0x64) = *(float *)(e + 0x64) * lbl_80563D34;
    *(float *)(e + 0x3C) = *(float *)(o + 0xE4);
    *(float *)(e + 0x40) = *(float *)(o + 0xE8);
    *(float *)(e + 0x44) = *(float *)(o + 0xEC);
    *(float *)(e + 0x48) = *(float *)(o + 0xE4);
    *(float *)(e + 0x4C) = *(float *)(o + 0xE8);
    *(float *)(e + 0x50) = *(float *)(o + 0xEC);
    *(float *)(e + 0x54) = lbl_80563D18;
    *(float *)(e + 0x58) = lbl_80563D18;
    *(float *)(e + 0x5C) = lbl_80563D18;
    *(int *)(e + 0x68) = lbl_8055E3C4;
    {
        int diff = lbl_8055E3C4 - *(int *)(e + 0x68);
        double dd = (double)(unsigned)diff;
        *(float *)(e + 0x60) = *(float *)(e + 0x60) + lbl_80563D38 * (float)(dd - 4503599627370496.0);
    }
    if (lbl_8055E3C4 != *(int *)(e + 0x68)) {
        sp78_ = *(float *)(o + 0xE4);
        sp7C_ = *(float *)(o + 0xE8);
        sp80_ = *(float *)(o + 0xEC);
        t3 = sp78_ + *(float *)(o + 0xCC) * lbl_80563D3C;
        t4 = sp7C_ + *(float *)(o + 0xD0) * lbl_80563D3C;
        t5 = sp80_ + *(float *)(o + 0xD4) * lbl_80563D3C;
        sp54[0] = t3 - *(float *)(e + 0x48);
        sp6C[0] = t4 - *(float *)(e + 0x4C);
        sp60[0] = t5 - *(float *)(e + 0x50);
        sp54[1] = *(float *)(e + 0x54) + lbl_80563D40 * (sp54[0] - *(float *)(e + 0x54));
        sp54[2] = *(float *)(e + 0x58) + lbl_80563D40 * (sp6C[0] - *(float *)(e + 0x58));
        sp6C[1] = *(float *)(e + 0x5C) + lbl_80563D40 * (sp60[0] - *(float *)(e + 0x5C));
        *(float *)(e + 0x54) = sp54[1];
        *(float *)(e + 0x58) = sp54[2];
        *(float *)(e + 0x5C) = sp6C[1];
        *(float *)(e + 0x48) += sp54[1] * lbl_80563D20;
        *(float *)(e + 0x4C) += sp54[2] * lbl_80563D20;
        *(float *)(e + 0x50) += sp6C[1] * lbl_80563D20;
    }
    sp48[0] = lbl_80563D18;
    sp48[1] = *(float *)(e + 0x38) + *(float *)(e + 0x60) * *(float *)(e + 0x64);
    sp48[2] = lbl_80563D18;
    ang114[0] = *(float *)(e + 0x48);
    ang114[1] = *(float *)(e + 0x4C);
    ang114[2] = *(float *)(e + 0x50);
    mtx138[0]=lbl_80563D20;mtx138[1]=lbl_80563D18;mtx138[2]=lbl_80563D18;
    mtx138[3]=lbl_80563D18;mtx138[4]=lbl_80563D20;mtx138[5]=lbl_80563D18;
    mtx138[6]=lbl_80563D18;mtx138[7]=lbl_80563D18;mtx138[8]=lbl_80563D20;
    fn_80015A20(mtx114, ang114);
    fn_80015B20(mtx138, mtx114, mtx138);
    angF0[0]=lbl_80563D44; angF0[1]=lbl_80563D18; angF0[2]=lbl_80563D18;
    fn_80015A20(mtxF0, angF0);
    fn_80015B20(mtx138, mtxF0, mtx138);
    sp18[0] = lbl_80563D48 * mtx138[6] + (lbl_80563D18 * mtx138[0] + lbl_80563D18 * mtx138[3]);
    sp18[1] = lbl_80563D48 * mtx138[7] + (lbl_80563D18 * mtx138[1] + lbl_80563D18 * mtx138[4]);
    sp18[2] = lbl_80563D48 * mtx138[8] + (lbl_80563D18 * mtx138[2] + lbl_80563D18 * mtx138[5]);
    sp48[0] += sp18[0]; sp48[1] += sp18[1]; sp48[2] += sp18[2];
    sp60[0]=sp48[0]; sp60[1]=sp48[1]; sp60[2]=sp48[2];
    if (fn_801EA03C((char *)(*(void **)(p + 0x140)) + 0x6C, sp60) != 0) {
        float delta = sp60[1] + lbl_80563D20 - *(float *)(sp48 + 1);
        float maxd = lbl_80563D18;
        *(float *)(sp48 + 1) += lbl_80563D20;
        if (maxd < delta) maxd = delta;
        *(float *)(sp48 + 1) = *(float *)(sp48 + 1) + maxd;
        angCC[0] = (float)atan(maxd / lbl_80563D4C, *(float *)(sp48 + 1));
        angCC[1] = lbl_80563D18;
        angCC[2] = lbl_80563D18;
        fn_80015A20(mtxCC, angCC);
        fn_80015B20(mtx138, mtxCC, mtx138);
    }
    fn_80176A24(lbl_80563D08);
    fn_80176A00(2);
    fv = lbl_80563D20;
    fv2 = lbl_80563D50 * (lbl_80563D54 * *(float *)(e + 0x60));
    if (fv2 > fv) fv = fv2;
    if (fv < lbl_80563D1C) f29 = lbl_80563D1C;
    else if (fv > lbl_80563D20) f29 = lbl_80563D20;
    else if (fv > lbl_80563D18) f29 = (fv * (lbl_80563D58 * fv * fv)) + (lbl_80563D54 * fv * fv);
    else f29 = (fv * (lbl_80563D58 * fv * fv)) - (lbl_80563D54 * fv * fv);
    fn_8026E22C((float *)p + 0x58/4, (float *)(e + 4), mtx138, f29);
    *(int *)(p + 0x10) = 5;
    *(float *)(p + 0xBC) = *(float *)(e + 0x34) + f29 * (lbl_80563D5C - *(float *)(e + 0x34));
    *(int *)(e + 0x68) = lbl_8055E3C4;
common:
    return 1;
}
 #pragma pop
 #pragma scheduling on
/* Returns the in-use flag of the given player's arena-event entry in the
   4-slot pool at lbl_80499E60; each entry is 0x6C bytes, flag at offset 0. */
unsigned char fn_8026B0C0(int playerIndex) {
#define ARENA_EVENT_SLOT_SIZE 0x6C
    extern unsigned char lbl_80499E60[];
    return lbl_80499E60[playerIndex * ARENA_EVENT_SLOT_SIZE];
#undef ARENA_EVENT_SLOT_SIZE
}

