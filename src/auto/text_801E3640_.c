#include <math.h>
extern void *fn_802C86DC(void);
extern void fn_802C8DB8(void *, int, void *, int);
extern void fn_802C9904(void);
extern unsigned short lbl_80562D20, lbl_80562D22, lbl_80562D24;
extern float PSVECMag(float *);
extern float lbl_80558DC4[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562CF4, lbl_80562CF8, lbl_80562CFC, lbl_80562D00, lbl_80562D04, lbl_80562D28;
extern int fn_802C8DBC(int);
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern void fn_802C8E00(int, int, float, float, float, float, float);
extern void fn_802C8E48(void);

typedef struct {
    float x, y, z;
    int id;
    float u, v;
} TrailPt;

extern int lbl_8055EA6C;
extern int lbl_8055EA64;
extern int fn_802CAC54(int);
extern int fn_802C6CF8(int);
extern int lbl_8055EA6C, lbl_8055EA64;
extern float lbl_8055EA68, lbl_80562D08;
extern char lbl_80339910[], lbl_80339920[];
extern int fn_802CAC28(char *, int);
extern int fn_802C6FC0(char *, int, int);
extern int fn_802C7760(void *, float *, float *, float *, float *, float *, float *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern float lbl_80562CF0;
extern void PSVECCrossProduct(const float *, const float *, float *);
#pragma scheduling on
void fn_801E3640(void *arg0, float *arg1) {
    float basis[3];
    float x = *(float *)arg0;
    float y = *(float *)((char *)arg0 + 4);
    float z = *(float *)((char *)arg0 + 8);
    arg1[6] = x;
    arg1[7] = y;
    arg1[8] = z;
    if (__fabs(x) < lbl_80562CF0 && __fabs(z) < lbl_80562CF0) {
        basis[0] = lbl_80562CF4;
        basis[1] = lbl_80562CF4;
        basis[2] = lbl_80562CF8;
    } else {
        basis[0] = lbl_80562CF4;
        basis[1] = lbl_80562CF8;
        basis[2] = lbl_80562CF4;
    }
    PSVECCrossProduct(basis, arg1 + 6, arg1);
    PSVECCrossProduct(arg1 + 6, arg1, arg1 + 3);
}

int fn_801E36F0(int arg0) { unsigned int s = ((unsigned int)arg0 >> 1) & 0x7F7F7F; unsigned int a = (unsigned int)arg0 & 0xFF000000; return (int)(s | a); }

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801E370C(float *arg0, int arg1, int arg2) {
    float out[3];
    float in[3];
    float c, half;
    int i;

    fn_802C8BD0(lbl_8055EA6C);
    if (fn_802C8DBC(0x11) != 0) {
        c = lbl_80562CFC;
        half = lbl_80562D00;
        out[0] = lbl_80562CF4;
        out[1] = lbl_80562CF4;
        out[2] = lbl_80562CF4;
        i = 0;
        do {
            in[0] = ((i + (i >> 1)) & 1) ? lbl_80562CF8 : lbl_80562CFC;
            in[1] = (i & 2) ? lbl_80562CF8 : lbl_80562CFC;
            in[2] = c;
            if (&out[0] == &in[0]) {
                out[0] = (in[0] * arg0[0] + in[1] * arg0[3]) + in[2] * arg0[6];
                out[1] = (in[0] * arg0[1] + in[1] * arg0[4]) + in[2] * arg0[7];
                out[2] = (in[0] * arg0[2] + in[1] * arg0[5]) + in[2] * arg0[8];
            } else {
                out[0] = (in[1] * arg0[3] + in[0] * arg0[0]) + in[2] * arg0[6];
                out[1] = (in[1] * arg0[4] + in[0] * arg0[1]) + in[2] * arg0[7];
                out[2] = (in[1] * arg0[5] + in[0] * arg0[2]) + in[2] * arg0[8];
            }
            out[0] += arg0[9];
            out[1] += arg0[10];
            out[2] += arg0[11];
            fn_802C8E00(arg1, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
            out[0] += arg0[6] * half;
            out[1] += arg0[7] * half;
            out[2] += arg0[8] * half;
            fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
            ++i;
        } while (i < 5);
        out[1] += arg0[1] * lbl_80562D00;
        out[0] += arg0[0] * lbl_80562D00;
        out[2] += arg0[2] * lbl_80562D00;
        fn_802C8E00(arg2, 0, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[1] += arg0[4] * lbl_80562D00;
        out[0] += arg0[3] * lbl_80562D00;
        out[2] += arg0[5] * lbl_80562D00;
        fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D04 + arg0[6] * lbl_80562D00;
        out[1] += arg0[1] * lbl_80562D04 + arg0[7] * lbl_80562D00;
        out[2] += arg0[2] * lbl_80562D04 + arg0[8] * lbl_80562D00;
        fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D00;
        out[1] += arg0[1] * lbl_80562D00;
        out[2] += arg0[2] * lbl_80562D00;
        fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[3] * lbl_80562D04;
        out[1] += arg0[4] * lbl_80562D04;
        out[2] += arg0[5] * lbl_80562D04;
        fn_802C8E00(arg1, 0, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D04;
        out[1] += arg0[1] * lbl_80562D04;
        out[2] += arg0[2] * lbl_80562D04;
        fn_802C8E00(arg1, 0, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[6] * lbl_80562D04 + arg0[0] * lbl_80562D00 + arg0[3] * lbl_80562D00;
        out[1] += arg0[7] * lbl_80562D04 + arg0[1] * lbl_80562D00 + arg0[4] * lbl_80562D00;
        out[2] += arg0[8] * lbl_80562D04 + arg0[2] * lbl_80562D00 + arg0[5] * lbl_80562D00;
        fn_802C8E00(arg1, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D04;
        out[1] += arg0[1] * lbl_80562D04;
        out[2] += arg0[2] * lbl_80562D04;
        fn_802C8E00(arg1, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma scheduling on
#pragma pop
void fn_801E3C04(void) {
    float a, b, d, e, c, f;
    float t;
    int tmp;
    tmp = fn_802CAC28(lbl_80339910, 0);
    lbl_8055EA6C = tmp;
    tmp = fn_802C6FC0(lbl_80339920, 0, 0);
    lbl_8055EA64 = tmp;
    fn_802C7760((void *)tmp, &a, &b, &c, &d, &e, &f);
    t = (float)fabs(e - b);
    lbl_8055EA68 = t * lbl_80562D08;
}

void fn_801E3C88(void) {
    fn_802CAC54(lbl_8055EA6C);
    fn_802C6CF8(lbl_8055EA64);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801E3CB4(void *arg0, void *arg1, int arg2, float farg0) {
    extern float lbl_80558DC4[];
    extern float lbl_80562CF4;
    extern float lbl_80562CF8;
    extern float lbl_80562CFC;
    extern float lbl_80562D0C;
    extern float lbl_80562D10;
    extern float PSVECMag(float *);
    extern void fn_801E3640(void *, float *);
    extern int fn_801E36F0(int);
    extern unsigned short lbl_802F99E8[];
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *, int, void *, int);
    extern void fn_802C8D74(void);
    extern void fn_802C9904(void);
    float vec[9];
    TrailPt pts[5];
    unsigned short frame[6];
    float scale;
    float mag;
    float s;
    int i;
    int result;
    float ax, ay, az;

    fn_801E3640(arg1, vec);
    scale = lbl_80562D0C * farg0;
    mag = PSVECMag(&vec[6]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = -farg0 / mag;
        vec[6] = vec[6] * s;
        vec[7] = vec[7] * s;
        vec[8] = vec[8] * s;
    }
    mag = PSVECMag(&vec[0]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = (scale * lbl_80562D08) / mag;
        vec[0] = vec[0] * s;
        vec[1] = vec[1] * s;
        vec[2] = vec[2] * s;
    }
    mag = PSVECMag(&vec[3]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        s = (scale * lbl_80562D08) / mag;
        vec[3] = vec[3] * s;
        vec[4] = vec[4] * s;
        vec[5] = vec[5] * s;
    }
    pts[0].x = lbl_80562CF4;
    pts[0].y = lbl_80562CF4;
    pts[0].z = lbl_80562CF4;
    pts[1].x = vec[6] + vec[0] * lbl_80562CFC;
    pts[1].y = vec[7] + vec[1] * lbl_80562CFC;
    pts[1].z = vec[8] + vec[2] * lbl_80562CFC;
    pts[2].x = vec[6] + vec[0] * lbl_80562CF8;
    pts[2].y = vec[7] + vec[1] * lbl_80562CF8;
    pts[2].z = vec[8] + vec[2] * lbl_80562CF8;
    pts[3].x = vec[6] + vec[3] * lbl_80562CFC;
    pts[3].y = vec[7] + vec[4] * lbl_80562CFC;
    pts[3].z = vec[8] + vec[5] * lbl_80562CFC;
    pts[4].x = vec[6] + vec[3] * lbl_80562CF8;
    pts[4].y = vec[7] + vec[4] * lbl_80562CF8;
    pts[4].z = vec[8] + vec[5] * lbl_80562CF8;
    result = fn_801E36F0(arg2);
    ax = *(float *)((char *)arg0 + 0x0);
    ay = *(float *)((char *)arg0 + 0x4);
    az = *(float *)((char *)arg0 + 0x8);
    for (i = 0; i < 5; i++) {
        pts[i].id = arg2;
        pts[i].u = lbl_80562D10 * i;
        pts[i].v = lbl_80562D10 * i;
        pts[i].x = pts[i].x + ax;
        pts[i].y = pts[i].y + ay;
        pts[i].z = pts[i].z + az;
    }
    pts[0].id = result;
    {
        unsigned short *p = lbl_802F99E8;
        for (i = 0; i < 6; i++) {
            frame[i] = *p++;
        }
    }
    fn_802C8BD0(lbl_8055EA6C);
    fn_802C8DB8(pts, 5, frame, 6);
    fn_802C8D74();
    fn_802C9904();
}
#pragma pop
void fn_801E3FC8(void *arg0, float farg0) {
    f32 sp[12];
    float zero;
    float tx;
    float tz;
    float s;
    float ty;
    int handle;

    zero = lbl_80562CF4;
    sp[9] = zero;
    tx = ((f32 *)arg0)[0];
    tz = ((f32 *)arg0)[2];
    s = farg0 / lbl_8055EA68;
    ty = ((f32 *)arg0)[1];
    sp[10] = zero;
    handle = lbl_8055EA64;
    sp[0] = s;
    sp[1] = zero;
    sp[2] = zero;
    sp[3] = zero;
    sp[4] = s;
    sp[5] = zero;
    sp[6] = zero;
    sp[7] = zero;
    sp[8] = s;
    sp[9] = tx;
    sp[10] = ty;
    sp[11] = tz;
    fn_802C744C(handle, sp);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_801E4040(void *arg0, void *arg1, int arg2, int arg3, float farg0) {
    float *a = (float *)arg0;
    float *b = (float *)arg1;
    float delta[3];
    float matrix[4][3];
    float mag;
    float scale;
    float tx;
    float ty;
    float tz;

    delta[0] = b[0] - a[0];
    delta[1] = b[1] - a[1];
    delta[2] = b[2] - a[2];
    fn_801E3640(delta, &matrix[0][0]);
    matrix[2][0] = delta[0] * lbl_80562D08;
    matrix[2][1] = delta[1] * lbl_80562D08;
    matrix[2][2] = delta[2] * lbl_80562D08;
    mag = PSVECMag(&matrix[0][0]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        scale = (farg0 * lbl_80562D08) / mag;
        matrix[0][0] *= scale;
        matrix[0][1] *= scale;
        matrix[0][2] *= scale;
    }
    mag = PSVECMag(&matrix[1][0]);
    if (!((float)__fabs((double)mag) <= lbl_80558DC4[0])) {
        scale = (farg0 * lbl_80562D08) / mag;
        matrix[1][0] *= scale;
        matrix[1][1] *= scale;
        matrix[1][2] *= scale;
    }
    tx = a[0] + matrix[2][0];
    ty = a[1] + matrix[2][1];
    tz = a[2] + matrix[2][2];
    matrix[3][0] = tx;
    matrix[3][1] = ty;
    matrix[3][2] = tz;
    fn_801E370C(&matrix[0][0], arg2, arg3);
}
extern float lbl_8055EA68, lbl_80562CF4;
extern int fn_802C744C(int, float *);
extern int fn_801E4040(void *, void *, int, int, float);
#pragma dont_inline fn_801E41D8
void fn_801E41D8(void *arg0, void *arg1, int arg2, float farg0);
#pragma dont_inline fn_801E41D8
void fn_801E41D8(void *arg0, void *arg1, int arg2, float farg0) {
    fn_801E4040(arg0, arg1, arg2, arg2, farg0);
}

void fn_801E41E0(void *arg0, int arg1, float farg0) {
    struct LocalData {
        unsigned short frame[3];
        unsigned short padding;
        TrailPt seed;
        TrailPt points[3];
    };
    volatile struct LocalData local;
    float *base = (float *)arg0;
    float *matrix;
    register float zero;
    register f64 seedXY;
    register s32 seedZ;
    float x, y, z;
    float negScale;
    float sidePositive;
    float depthNegative;
    float sideNegative;

    zero = lbl_80562CF4;
    seedXY = *(volatile f64 *)&local.seed.x;
    seedZ = *(volatile s32 *)&local.seed.z;
    local.seed.id = arg1;
    local.seed.u = zero;
    local.seed.v = zero;
    *(volatile f64 *)&local.points[0].x = seedXY;
    *(volatile s32 *)&local.points[0].z = seedZ;
    local.points[0].id = arg1;
    local.points[0].u = zero;
    local.points[0].v = zero;
    *(volatile f64 *)&local.points[1].x = seedXY;
    *(volatile s32 *)&local.points[1].z = seedZ;
    local.points[1].id = arg1;
    local.points[1].u = zero;
    local.points[1].v = zero;
    *(volatile f64 *)&local.points[2].x = seedXY;
    *(volatile s32 *)&local.points[2].z = seedZ;
    local.points[2].id = arg1;
    local.points[2].u = zero;
    local.points[2].v = zero;
    local.frame[0] = lbl_80562D20;
    local.frame[1] = lbl_80562D22;
    local.frame[2] = lbl_80562D24;

    matrix = (float *)fn_802C86DC();
    negScale = -farg0;
    sidePositive = lbl_80562D28 * farg0;
    depthNegative = lbl_80562D08 * negScale;
    sideNegative = lbl_80562D28 * negScale;
    x = base[0];
    y = base[1];
    z = base[2];

    local.points[0].x = x + matrix[3] * farg0;
    local.points[0].y = y + matrix[4] * farg0;
    local.points[0].z = z + matrix[5] * farg0;

    local.points[1].x = x + matrix[3] * depthNegative;
    local.points[1].y = y + matrix[4] * depthNegative;
    local.points[1].z = z + matrix[5] * depthNegative;
    local.points[1].x += matrix[0] * sidePositive;
    local.points[1].y += matrix[1] * sidePositive;
    local.points[1].z += matrix[2] * sidePositive;

    local.points[2].x = x + matrix[3] * depthNegative;
    local.points[2].y = y + matrix[4] * depthNegative;
    local.points[2].z = z + matrix[5] * depthNegative;
    local.points[2].x += matrix[0] * sideNegative;
    local.points[2].y += matrix[1] * sideNegative;
    local.points[2].z += matrix[2] * sideNegative;

    fn_802C8BD0(lbl_8055EA6C);
    fn_802C8DB8((void *)local.points, 3, (void *)local.frame, 3);
    fn_802C8D74();
    fn_802C9904();
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801E43BC(void *arg0, float scale, float alpha) {
    typedef void (*LineCall)(void *, void *, int, float);
    float p[3];
    register float *base = (float *)arg0;
    register float x, y, z, vx, vy, vz;

    vx = base[0];
    vz = base[2];
    x = vx * scale;
    vy = base[1];
    y = vy * scale;
    vx = base[9];
    vy = base[10];
    z = vz * scale;
    vz = base[11];
    p[0] = vx + x;
    p[1] = vy + y;
    p[2] = vz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFFFF0000, alpha);

    vx = base[3];
    vz = base[5];
    x = vx * scale;
    vy = base[4];
    y = vy * scale;
    vx = base[9];
    vy = base[10];
    z = vz * scale;
    vz = base[11];
    p[0] = vx + x;
    p[1] = vy + y;
    p[2] = vz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFF00FF00, alpha);

    vx = base[6];
    vz = base[8];
    x = vx * scale;
    vy = base[7];
    y = vy * scale;
    vx = base[9];
    vy = base[10];
    z = vz * scale;
    vz = base[11];
    p[0] = vx + x;
    p[1] = vy + y;
    p[2] = vz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFF0000FF, alpha);
}
#pragma pop
extern void fn_801E370C();
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801E44F4(void *arg0, void *arg1, float farg0, float farg1, float farg2) {
    float sp[12];
    float temp_f11, temp_f10, temp_f9, temp_f8, temp_f7;
    float temp_f6, temp_f2, temp_f1, temp_f0, temp_f5, temp_f4, temp_f3;

    temp_f11 = *(float *)((char *)arg0 + 0x00) * farg0;
    temp_f10 = *(float *)((char *)arg0 + 0x04) * farg0;
    temp_f9 = *(float *)((char *)arg0 + 0x08) * farg0;
    temp_f8 = *(float *)((char *)arg0 + 0x0C) * farg1;
    temp_f7 = *(float *)((char *)arg0 + 0x10) * farg1;
    temp_f1 = *(float *)((char *)arg0 + 0x1C) * farg2;
    temp_f6 = *(float *)((char *)arg0 + 0x14) * farg1;
    temp_f2 = *(float *)((char *)arg0 + 0x18) * farg2;
    temp_f0 = *(float *)((char *)arg0 + 0x20) * farg2;
    temp_f5 = *(float *)((char *)arg0 + 0x24);
    temp_f4 = *(float *)((char *)arg0 + 0x28);
    temp_f3 = *(float *)((char *)arg0 + 0x2C);

    sp[9] = temp_f5;
    sp[10] = temp_f4;
    sp[11] = temp_f3;
    sp[0] = temp_f11;
    sp[1] = temp_f10;
    sp[2] = temp_f9;
    sp[3] = temp_f8;
    sp[4] = temp_f7;
    sp[5] = temp_f6;
    sp[6] = temp_f2;
    sp[7] = temp_f1;
    sp[8] = temp_f0;
    fn_801E370C(sp, (int)arg1, (int)arg1);
}
#pragma scheduling on
#pragma pop
