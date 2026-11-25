#include <math.h>
extern void *DrawList_getCurrentMatrix(void);
extern void fn_802C8DB8(void *, int, void *, int);
extern void fn_802C9904(void);
extern unsigned short lbl_80562D20, lbl_80562D22, lbl_80562D24;
extern float PSVECMag(float *);
extern float lbl_80558DC4[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562CF4, lbl_80562CF8, lbl_80562CFC, lbl_80562D00, lbl_80562D04, lbl_80562D28;
extern int beginDrawListPass(int);
extern void fn_802C8BD0(int);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802C8E00(int, int, float, float, float, float, float);
extern void DrawList_endMeshPass(void);

typedef struct {
    float x, y, z;
    int id;
    float u, v;
} TrailPt;

typedef struct {
    float x, y, z;
} Vec3;

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
/* Halve the red, green and blue bytes of a packed 0xAARRGGBB colour, passing the alpha byte through. */
#pragma push
#pragma dont_inline on
int fn_801E36F0(int color) {
    return (((unsigned int)color >> 1) & 0x7F7F7F) | ((unsigned int)color & 0xFF000000);
}
#pragma pop
#pragma dont_inline off

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801E370C(float *arg0, int arg1, int arg2) {
    float outbuf[3], inbuf[3];
    float *out = outbuf;
    float *in = inbuf;
    float c, half;
    int i;
    fn_802C8BD0(lbl_8055EA6C);
    if (beginDrawListPass(0x11) != 0) {
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
            if (out == in) {
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
        out[0] += arg0[3] * lbl_80562D00 + arg0[0] * lbl_80562D04;
        out[1] += arg0[4] * lbl_80562D00 + arg0[1] * lbl_80562D04;
        out[2] += arg0[5] * lbl_80562D00 + arg0[2] * lbl_80562D04;
        fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[1] += arg0[1] * lbl_80562D00;
        out[0] += arg0[0] * lbl_80562D00;
        out[2] += arg0[2] * lbl_80562D00;
        fn_802C8E00(arg2, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[6] * lbl_80562D04;
        out[1] += arg0[7] * lbl_80562D04;
        out[2] += arg0[8] * lbl_80562D04;
        fn_802C8E00(arg1, 0, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D04;
        out[1] += arg0[1] * lbl_80562D04;
        out[2] += arg0[2] * lbl_80562D04;
        fn_802C8E00(arg1, 0, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[3] * lbl_80562D04 + arg0[0] * lbl_80562D00;
        out[1] += arg0[4] * lbl_80562D04 + arg0[1] * lbl_80562D00;
        out[2] += arg0[5] * lbl_80562D04 + arg0[2] * lbl_80562D00;
        fn_802C8E00(arg1, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        out[0] += arg0[0] * lbl_80562D04;
        out[1] += arg0[1] * lbl_80562D04;
        out[2] += arg0[2] * lbl_80562D04;
        fn_802C8E00(arg1, 1, out[0], out[1], out[2], lbl_80562CF4, lbl_80562CF4);
        DrawList_endMeshPass();
    }
    DrawList_RestoreNormalMode();
}
#pragma scheduling on
#pragma pop
/* Load the white texture/model resources and cache half the sphere bounds height. */
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

/* Release the white_zr.tex texture and sphere.mod model handles cached by fn_801E3C04. */
void fn_801E3C88(void) {
#define s_whiteTex    lbl_8055EA6C
#define s_sphereModel lbl_8055EA64
    fn_802CAC54(s_whiteTex);
    fn_802C6CF8(s_sphereModel);
#undef s_sphereModel
#undef s_whiteTex
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
    extern void DrawList_RestoreNormalMode(void);
    extern void fn_802C9904(void);
    float vec[9];
    TrailPt pts[5];
    unsigned short frame[6];
    float scale;
    float mag;
    float s;
    int result;
    TrailPt *p;
    int i;

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
    p = pts;
    for (i = 0; i < 5; i++, p++) {
        float ax = ((float *)arg0)[0];
        float ay = ((float *)arg0)[1];
        float az = ((float *)arg0)[2];
        p->id = arg2;
        p->u = lbl_80562D10 * i;
        p->v = lbl_80562D10 * i;
        p->x = p->x + ax;
        p->y = p->y + ay;
        p->z = p->z + az;
    }
    pts[0].id = result;
    {
        unsigned short *up = lbl_802F99E8;
        for (i = 0; i < 6; i++) {
            frame[i] = *up++;
        }
    }
    fn_802C8BD0(lbl_8055EA6C);
    fn_802C8DB8(pts, 5, frame, 6);
    DrawList_RestoreNormalMode();
    fn_802C9904();
}
#pragma scheduling reset
void fn_801E3FC8(void *__restrict position, float radius) {
    /* Place the cached sphere model (lbl_8055EA64) at `position`, scaling it by
     * `radius` over the cached half-height lbl_8055EA68. Builds a 4x3 affine
     * transform (uniform scale on the diagonal, translation in the last column)
     * and applies it to the model instance with MRModel_SetInstanceTransform. */
    f32 transform[12];
    float posZ;
    float posY;
    float posX;
    float zero;
    float scale;
    int sphereModel;

    zero = 0.0f;
    *(volatile f32 *)&transform[9] = zero;
    posX = ((f32 *)position)[0];
    posZ = ((f32 *)position)[2];
    scale = radius / lbl_8055EA68;
    posY = ((f32 *)position)[1];
    *(volatile f32 *)&transform[10] = zero;
    sphereModel = lbl_8055EA64;
    transform[0] = scale;
    transform[1] = zero;
    transform[2] = zero;
    transform[3] = zero;
    transform[4] = scale;
    transform[5] = zero;
    transform[6] = zero;
    transform[7] = zero;
    transform[8] = scale;
    transform[9] = posX;
    transform[10] = posY;
    transform[11] = posZ;
    MRModel_SetInstanceTransform(sphereModel, transform);
}
#pragma push
#pragma processor 750
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
#pragma pop
extern float lbl_8055EA68, lbl_80562CF4;
extern int MRModel_SetInstanceTransform(int, float *);
extern int fn_801E4040(void *, void *, int, int, float);
#pragma dont_inline fn_801E41D8
void fn_801E41D8(void *arg0, void *arg1, int arg2, float farg0);
#pragma dont_inline fn_801E41D8
/* Draw a solid-colour 3D beam between the two points: the fn_801E4040 convenience
   form that passes the same RGBA colour for both ends of the beam's colour
   gradient. `width` is the beam's cross-section size, applied half-and-half. */
void fn_801E41D8(void *from, void *to, int color, float width) {
    fn_801E4040(from, to, color, color, width);
}

#pragma scheduling invalid_target
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
    f64 seedXY = *(volatile f64 *)&local.seed.x;
    s32 seedZ = *(volatile s32 *)&local.seed.z;
    float x, y, z;
    float sidePositive;
    float negScale;
    float depthNegative;
    float sideNegative;
    float zero = lbl_80562CF4;

    local.seed.v = zero;
    local.seed.u = zero;
    local.seed.id = arg1;
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

    matrix = (float *)DrawList_getCurrentMatrix();
    sidePositive = lbl_80562D28 * farg0;
    negScale = -farg0;
    depthNegative = lbl_80562D08 * negScale;
    sideNegative = lbl_80562D28 * negScale;
    x = base[0];
    y = base[1];
    z = base[2];

    ((TrailPt *)(void *)local.points)[0].x = x + matrix[3] * farg0;
    ((TrailPt *)(void *)local.points)[0].y = y + matrix[4] * farg0;
    ((TrailPt *)(void *)local.points)[0].z = z + matrix[5] * farg0;

    ((TrailPt *)(void *)local.points)[1].x = x + matrix[3] * depthNegative;
    ((TrailPt *)(void *)local.points)[1].y = y + matrix[4] * depthNegative;
    ((TrailPt *)(void *)local.points)[1].z = z + matrix[5] * depthNegative;
    ((TrailPt *)(void *)local.points)[1].x += matrix[0] * sidePositive;
    ((TrailPt *)(void *)local.points)[1].y += matrix[1] * sidePositive;
    ((TrailPt *)(void *)local.points)[1].z += matrix[2] * sidePositive;

    ((TrailPt *)(void *)local.points)[2].x = x + matrix[3] * depthNegative;
    ((TrailPt *)(void *)local.points)[2].y = y + matrix[4] * depthNegative;
    ((TrailPt *)(void *)local.points)[2].z = z + matrix[5] * depthNegative;
    ((TrailPt *)(void *)local.points)[2].x += matrix[0] * sideNegative;
    ((TrailPt *)(void *)local.points)[2].y += matrix[1] * sideNegative;
    ((TrailPt *)(void *)local.points)[2].z += matrix[2] * sideNegative;

    fn_802C8BD0(lbl_8055EA6C);
    fn_802C8DB8((void *)local.points, 3, (void *)local.frame, 3);
    DrawList_RestoreNormalMode();
    fn_802C9904();
}
void fn_801E43BC(void *arg0, float scale, float alpha) {
    typedef void (*LineCall)(void *, void *, int, float);
    float p[3];
    float *v = (float *)arg0;
    float x, y, z, bx, by, bz;

    x = v[0] * scale;
    bx = v[9];
    y = v[1] * scale;
    by = v[10];
    z = v[2] * scale;
    bz = v[11];
    p[0] = bx + x;
    p[1] = by + y;
    p[2] = bz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFFFF0000, alpha);

    x = v[3] * scale;
    bx = v[9];
    y = v[4] * scale;
    by = v[10];
    z = v[5] * scale;
    bz = v[11];
    p[0] = bx + x;
    p[1] = by + y;
    p[2] = bz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFF00FF00, alpha);

    x = v[6] * scale;
    bx = v[9];
    y = v[7] * scale;
    by = v[10];
    z = v[8] * scale;
    bz = v[11];
    p[0] = bx + x;
    p[1] = by + y;
    p[2] = bz + z;
    ((LineCall)fn_801E41D8)((char *)arg0 + 0x24, p, 0xFF0000FF, alpha);
}
#pragma scheduling on
#pragma pop
extern void fn_801E370C();
#pragma processor 7400
#pragma scheduling on
/* Scale the three basis columns of a 3x4 transform (three axis vectors followed
 * by a translation) by xScale/yScale/zScale, keep the translation, and pass the
 * result to the debug line drawer fn_801E370C with the packed colour `color`. */
void fn_801E44F4(const void *mat, void *color, float xScale, float yScale, float zScale) {
    const float *m = (const float *)mat;
    float scaled[12];

    scaled[9] = m[0x09];
    scaled[10] = m[0x0A];
    scaled[11] = m[0x0B];
    scaled[0] = m[0x00] * xScale;
    scaled[1] = m[0x01] * xScale;
    scaled[2] = m[0x02] * xScale;
    scaled[3] = m[0x03] * yScale;
    scaled[4] = m[0x04] * yScale;
    scaled[5] = m[0x05] * yScale;
    scaled[6] = m[0x06] * zScale;
    scaled[7] = m[0x07] * zScale;
    scaled[8] = m[0x08] * zScale;
    fn_801E370C(scaled, (int)color, (int)color);
}
