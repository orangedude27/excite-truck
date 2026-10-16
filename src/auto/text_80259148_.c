// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80258354(void);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80345158;
extern float lbl_80563AE0;
extern float lbl_80563B14;
extern double fn_8002F234(double);
extern float PSVECDotProduct();
void fn_80259148(void) {
    int *base = lbl_80344DE0;
    void *obj = fn_80258354();
    void **vtable;
    lbl_8055F394 = obj;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, base, (char *)base + 0x10, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x20, (char *)base + 0x30, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x40, (char *)base + 0x50, 1);
}

int fn_8025921C(void) { return 0; }

void *fn_80259680(void *arg0, int arg1) {
    volatile int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 0x50);
        *(int **)arg0 = &lbl_80345158;
        if (value != -1) {
            fn_802C6CF8(value);
            *(int *)((char *)arg0 + 0x50) = -1;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0xA8));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80259700(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
void fn_80259740(int arg0, float farg0) {
    fn_80236914();
    lbl_8055F3A4 = farg0;
    lbl_8055F3A0 = (arg0 - 2) == 0;
}

void fn_8025AD3C(float *out, float *a, float *b, float t) {
    float z = a[2];
    float y = a[1];
    float x = a[0];
    float dz = b[2] - z;
    float dy = b[1] - y;
    float dx = b[0] - x;
    float rz = z + t * dz;
    float ry = y + t * dy;
    float rx = x + t * dx;
    out[2] = rz;
    out[1] = ry;
    out[0] = rx;
}

void fn_8025AD88(void) { PSVECDotProduct(); }

void fn_8025AD8C(void *unused, float *out, float *a, float *b, float t) {
    float scale = lbl_80563B14 * t;
    float max = lbl_80563AE0;
    float dx, dy, dz, x, y, z;
    if (max < scale)
        max = scale;
    dx = b[0] - a[0];
    dy = b[1] - a[1];
    dz = b[2] - a[2];
    x = a[0] + max * dx;
    y = a[1] + max * dy;
    z = a[2] + max * dz;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

float fn_8025ADF4(float arg0) { return (float)fn_8002F234(arg0); }

extern double sin(double);
typedef unsigned int u32;
typedef float f32;
extern f32 lbl_80563B1C;
f32 fn_8025B0A8(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 out = p[0];
    f32 d = p[1] - p[0];
    out += d * lbl_80563B1C;
    return out;
}

f32 fn_8025B0C4(f32 arg0) {
    return (f32)sin(arg0);
}

void fn_8025B0E8(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_8025B134(void) {
}

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
void fn_8025B22C(void *arg0) {
    int i;
    for (i = 1; i <= 5; i++) {
        if (*(int *)((char *)arg0 + 0x74) == i)
            fn_80214AF0(i + 5);
        else
            fn_80214A9C(i + 5);
        if (i <= *(int *)((char *)arg0 + 0x1C)) {
            fn_80214AF0(i);
            fn_80214A9C(i + 10);
        } else {
            fn_80214AF0(i + 10);
            fn_80214A9C(i);
        }
    }
}

extern void *fn_80258354(void);
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int lbl_80345158;
extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
