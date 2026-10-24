// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))

extern float lbl_80562418;
extern float lbl_8056241C;
extern float lbl_80562420;
extern float lbl_80562428;
extern float *fn_80265D98(void);
extern void fn_8012F57C(int, void *, void *, float);
float fn_801A6370(float arg0, float arg1, float arg2, float arg3) {
    return arg0 + arg1 * arg3 + arg3 * (arg3 * (lbl_80562418 * arg2));
}

float fn_801A6390(int arg0, int arg1) {
    int delta = arg0 - arg1;
    return lbl_8056241C * (float)delta;
}

#pragma dont_inline on
float fn_801A63C4(int arg0, int arg1) {
    return (lbl_80562428 * fn_801A6390(arg0, arg1)) / lbl_8056241C;
}
#pragma dont_inline off

void fn_801A63F4(void *arg0, void *arg1, void *arg2, void *arg3) {
    float *out = (float *)arg0;
    float *a = (float *)arg1;
    float *b = (float *)arg2;
    float *t = (float *)arg3;
    float ax = a[0], ay = a[1], az = a[2];
    float bx = b[0], by = b[1], bz = b[2];
    float tx = t[0], ty = t[1], tz = t[2];
    out[2] = az + tz * (bz - az);
    out[1] = ay + ty * (by - ay);
    out[0] = ax + tx * (bx - ax);
}

void fn_801A6520(void) {

}

extern void fn_8018381C(void);
extern void fn_801A6558(void *);
extern void fn_801A67B0(void *);
extern void *fn_802E2C20(void);
extern void fn_80182010(void);
extern void *fn_801A644C(void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern float lbl_8056242C;
extern float lbl_80562430;
extern char lbl_80333CA8;
extern char lbl_80333CB8;
extern void fn_801A6520(void);
void fn_801A6524(void *arg0) {
    fn_8018381C();
    fn_801A6558(arg0);
}

void fn_801A6558(void *arg0) {
    *(int *)((char *)arg0 + 0x2778) = 4;
    *(void **)((char *)arg0 + 0x277C) = fn_802E2C20();
    *(float *)((char *)arg0 + 0x273C) = lbl_8056242C;
    *(float *)((char *)arg0 + 0x2738) = lbl_8056242C;
    *(int *)((char *)arg0 + 0x2704) = 0;
    *(float *)((char *)arg0 + 0x272C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2730) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2734) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2708) = lbl_80562430;
    *(float *)((char *)arg0 + 0x270C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2710) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2714) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2718) = lbl_80562430;
    *(float *)((char *)arg0 + 0x271C) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2720) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2724) = lbl_80562430;
    *(float *)((char *)arg0 + 0x2728) = lbl_80562430;
    memset(*(void **)((char *)arg0 + 0x2700), 0, 0xE7);
    if (*(unsigned char *)((char *)arg0 + 0x2740))
        fn_801A67B0(arg0);
}

extern int lbl_8055E3C4;
extern double lbl_80562440;
void fn_801A69F4(void *arg0, float *arg1) {
    char *p = (char *)arg0;
    char *data = *(char **)(p + 0x2700);
    float t0, t1, t2;
    float out0[3], out1[3];
    double a, b, c, d, e, f;
    double x, y, z;
    float *v = (float *)(p + 0x2700);

    a = fn_801A63C4(lbl_8055E3C4, *(int *)(data + 4));
    t0 = fn_801A6370(*(float *)(data + 0x1e), *(float *)(p + 0x2708), *(float *)(p + 0x272c), (float)a);
    t1 = fn_801A6370(*(float *)(data + 0x22), *(float *)(p + 0x270c), *(float *)(p + 0x2730), (float)a);
    t2 = fn_801A6370(*(float *)(data + 0x26), *(float *)(p + 0x2710), *(float *)(p + 0x2734), (float)a);

    a = fn_801A63C4(*(int *)(data + 0x51), *(int *)(data + 0x9e));
    b = fn_801A63C4(*(int *)(data + 4), *(int *)(data + 0x9e));
    c = fn_801A63C4(lbl_8055E3C4, *(int *)(data + 0x9e));
    d = c + c;
    e = d - lbl_80562440;
    f = a - b;
    x = (e - b) / ((a - lbl_80562440) * (a - b));
    y = ((d - a) - b) / ((lbl_80562440 - a) * (lbl_80562440 - b));
    z = (e - a) / ((b - lbl_80562440) * (b - a));
    out0[0] = (float)(*(float *)(data + 0x6b) * x + *(float *)(data + 0xb8) * y + *(float *)(data + 0x1e) * z);
    out0[1] = (float)(*(float *)(data + 0x6f) * x + *(float *)(data + 0xbc) * y + *(float *)(data + 0x22) * z);
    out0[2] = (float)(*(float *)(data + 0x73) * x + *(float *)(data + 0xc0) * y + *(float *)(data + 0x26) * z);
    fn_801A63F4(out1, p + 0x60, &t0, arg1 + 1);
    *(float *)(p + 0x60) = out1[0];
    *(float *)(p + 0x64) = out1[1];
    *(float *)(p + 0x68) = out1[2];
    fn_8017A580(arg0);
    fn_801A63F4(out1, p + 0x118, out0, arg1 + 1);
    *(float *)(p + 0x118) = out1[0];
    *(float *)(p + 0x11c) = out1[1];
    *(float *)(p + 0x120) = out1[2];
}

float fn_801A70EC(int arg0, void* arg1, void* arg2, int arg3) {
    float den=fn_801A63C4(*(int*)((char*)arg2+4),*(int*)((char*)arg1+4));
    float ratio=fn_801A63C4(arg3,*(int*)((char*)arg1+4))/den;
    fn_8012F57C(arg0,(char*)arg1+0x2a,(char*)arg2+0x2a,ratio);
    return ratio;
}

extern float lbl_8056242C, lbl_80562430, lbl_80562448;
extern void fn_801A69F4(void *, float *);
extern void fn_801A6C14(void *);
extern void fn_801A7178(void *, float *);
extern void fn_801A7530(void *, void *);
extern void fn_801BE168(void *, void *, void *, void *);
extern float PSVECDotProduct(void *, void *);
void fn_801A7444(void *arg0) {
    float sp8, one, up, side;
    char *p = (char *)arg0;
    fn_801A7530(p, &sp8);
    fn_801A69F4(p, &sp8);
    fn_801A7178(p, &sp8);
    one = lbl_8056242C;
    *(float *)(p + 0x124) *= one - sp8;
    *(float *)(p + 0x128) *= one - sp8;
    *(float *)(p + 0x12C) *= one - sp8;
    if (PSVECDotProduct(p + 0x118, p + 0x118) > lbl_80562448) {
        side = lbl_80562430;
        up = lbl_8056242C;
        *(float *)(p + 0x118) = side;
        *(float *)(p + 0x11C) = up;
        *(float *)(p + 0x120) = side;
    }
    fn_801BE168(*(void **)(p + 0x1EC), p + 0x3C, p + 0x118, p + 0x124);
    if (*(unsigned char *)(*(char **)(p + 0x2700) + 0x48)) {
        fn_801A6C14(p);
        *(unsigned char *)(*(char **)(p + 0x2700) + 0x48) = 0;
    }
}

#pragma scheduling reset
void fn_801A7530(void* arg0, void* arg1) {
    float zero;
    float* v;
    int second;
    int third;
    if (*(int*)((char*)arg0 + 0x2610) == 0 || *(unsigned char*)((char*)arg0 + 0x2741) != 0) {
        zero = lbl_8056242C;
        *(float*)((char*)arg1 + 4) = zero;
        *(float*)((char*)arg1 + 8) = zero;
        *(float*)((char*)arg1 + 0xc) = zero;
        *(float*)arg1 = zero;
    } else {
        v = fn_80265D98();
        *(float*)arg1 = *v;
        second = *(int*)((char*)v + 8);
        third = *(int*)((char*)v + 4);
        *(int*)((char*)arg1 + 4) = third;
        *(int*)((char*)arg1 + 8) = second;
        *(int*)((char*)arg1 + 0xc) = *(int*)((char*)v + 0xc);
    }
}

