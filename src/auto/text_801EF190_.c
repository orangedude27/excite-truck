// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801E323C(void*);
extern void fn_802C6CF8(void*);
extern void fn_80128668(void*);
extern void *fn_801284F8(int, const char *);
extern void *fn_802C6FC0(void *, int, int);
extern void *fn_801E3004(void *, const char *, int);
extern void *fn_801E31D8(void *, const char *, int);
extern int fn_801E3534(void *);
extern float fn_801EF190(int);
extern void fn_802C7760(void *, float *, float *, float *, float *, float *, float *);
extern float lbl_80562EE0;
extern float lbl_80562EE4;
extern char lbl_8033A380[];
typedef struct { char s0[0x10], s10[0xC], s1C[0xC], s28[0xC], s34[0xC], s40[0xC], s4C[0xC], s58[0xC], s64[0xC]; } Lbl801EF;
extern char lbl_8055B098[4];
extern char lbl_8055B0A0[4];
extern char lbl_8055B0A8[4];
extern char lbl_8055B0B0[4];
extern float lbl_80562EE8;
extern float lbl_80562EEC;
typedef struct { float x, y, z; } Vec801EF;
typedef struct { Vec801EF x, y, z, pos; } Matrix801EF;
#pragma scheduling invalid_target
float fn_801EF190(int arg0) {
    float a, c, e, b, d, f;
    if (arg0 == -1) {
        return lbl_80562EE0;
    }
    c = lbl_80562EE4;
    d = lbl_80562EE4;
    fn_802C7760((void *)arg0, &a, &b, &c, &d, &e, &f);
    return d - c;
}
#pragma scheduling on
void **fn_801EF1F0(void **arg0, void *arg1) {
    Lbl801EF *L = (Lbl801EF *)lbl_8033A380;
    *arg0 = fn_801284F8(0x4C, &L->s0[0]);
    * (void **)*arg0 = fn_802C6FC0(arg1, 0, 0);
    *((float *)*arg0 + 9) = lbl_80562EE8;
    *((void **)*arg0 + 1) = fn_802C6FC0(L->s10, 0, 0);
    *((void **)*arg0 + 10) = fn_802C6FC0(L->s1C, 0, 0);
    *((void **)*arg0 + 2) = fn_801E3004(**(void ***)arg0, L->s28, -1);
    *((void **)*arg0 + 3) = fn_801E3004(**(void ***)arg0, L->s34, -1);
    *((void **)*arg0 + 6) = fn_801E31D8(*((void **)*arg0 + 3), lbl_8055B098, -1);
    *((void **)*arg0 + 4) = fn_801E31D8(*((void **)*arg0 + 3), lbl_8055B0A0, -1);
    *((void **)*arg0 + 5) = fn_801E3004(**(void ***)arg0, L->s40, -1);
    *((void **)*arg0 + 7) = fn_801E3004(**(void ***)arg0, lbl_8055B0A8, -1);
    fn_801E3534(*((void **)*arg0 + 4));
    *((float *)*arg0 + 8) = fn_801EF190(0);
    *((float *)*arg0 + 18) = lbl_80562EEC;
    *((void **)*arg0 + 11) = fn_801E3004(**(void ***)arg0, L->s4C, -1);
    *((void **)*arg0 + 12) = fn_801E3004(**(void ***)arg0, L->s58, -1);
    *((void **)*arg0 + 15) = fn_801E31D8(*((void **)*arg0 + 12), lbl_8055B098, -1);
    *((void **)*arg0 + 13) = fn_801E31D8(*((void **)*arg0 + 12), lbl_8055B0A0, -1);
    *((void **)*arg0 + 14) = fn_801E3004(**(void ***)arg0, L->s64, -1);
    *((void **)*arg0 + 16) = fn_801E3004(**(void ***)arg0, lbl_8055B0B0, -1);
    fn_801E3534(*((void **)*arg0 + 13));
    *((float *)*arg0 + 17) = fn_801EF190(0);
    return arg0;
}

/* Releases the owned objects referenced by *objectPtr in the original order, clears the handle, and optionally frees the handle itself. */
int *fn_801EF428(int *objectPtr, int freeHandle) {
    if (objectPtr != 0) {
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[2]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[3]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[6]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[4]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[5]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[7]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)objectPtr))[1]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[11]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[12]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[15]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[13]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[14]);
        fn_801E323C((void *)((int *)(*(volatile int *)objectPtr))[16]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)objectPtr))[10]);
        fn_802C6CF8((void *)((int *)(*(volatile int *)objectPtr))[0]);
        fn_80128668((void *)*(volatile int *)objectPtr);
        *objectPtr = 0;
        if (freeHandle > 0) fn_80128668(objectPtr);
    }
    return objectPtr;
}

extern float lbl_80562EE4;
extern float lbl_80562EF0, lbl_80562EF4, lbl_80562EF8, lbl_80562EFC, lbl_80562F00;
extern void fn_80015A20(void *, Vec801EF *);
extern void fn_80015B20(void *, void *, void *);
extern void fn_802C744C(void *, void *);
extern void fn_801E3440(Vec801EF *, void *, Matrix801EF *);
extern void fn_801E353C(void *, float);
extern void fn_801E34E4(void *, Matrix801EF *);
extern void PSVECNormalize(Vec801EF *, Vec801EF *);
extern float PSVECDotProduct(Vec801EF *, Vec801EF *);
extern double fn_8002EFB0(float, float);
void fn_801EF53C(void *p0, Matrix801EF *arg1, void *p2) {
    void **arg0 = (void **)p0;
    Matrix801EF *arg2 = (Matrix801EF *)p2;
    Matrix801EF m;
    Vec801EF a, b, d, zv;
    float k = lbl_80562EF0 * -*(float *)((char *)arg0 + 0x20);
    float s, t, r;
    m = *arg2;
    m.pos.x += arg1->x.x * k;
    m.pos.y += arg1->x.y * k;
    m.pos.z += arg1->x.z * k;
    if (*(float *)((char *)arg0 + 0x20) > lbl_80562EE4) {
        zv.x = lbl_80562EE4; zv.y = lbl_80562EF4; zv.z = lbl_80562EE4;
        fn_80015A20(&d, &zv);
        fn_80015B20(&m, &d, &m);
    }
    fn_802C744C(arg0[0], &m);
    a.x = m.pos.x + m.x.y * lbl_80562EFC;
    a.y = m.pos.y + m.y.x * lbl_80562EFC;
    a.z = m.pos.z + m.y.z * lbl_80562EFC;
    fn_801E3440(&b, arg0[1], arg1);
    d.x = a.x - b.x; d.y = a.y - b.y; d.z = a.z - b.z;
    PSVECNormalize(&d, &d);
    s = *(float *)((char *)arg0 + 0x20) * PSVECDotProduct(&d, &arg1->x);
    r = fn_8002EFB0(s, PSVECDotProduct(&d, &arg1->y));
    t = lbl_80562EF8;
    fn_801E353C(arg0[1], *(float *)((char *)arg0 + 0x20) * r - *(float *)((char *)arg0 + 0x20) * t);
    fn_801E34E4(arg0[1], arg1);
}

extern float lbl_80562EE4, lbl_80562F04, lbl_80562F08, lbl_80562F0C;
extern float fn_801F159C(void **);
extern void fn_801EF53C(void *, Matrix801EF *, void *);
extern int fn_802C7A34(int, Vec801EF *, int);
extern void fn_802C70AC(void *, Matrix801EF *, int, int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801EFC90(void **arg0, void *arg1, void **arg2) {
    Matrix801EF base = *(Matrix801EF *)arg1;
    volatile Matrix801EF left, right;
    volatile Vec801EF offsets[2];
    float z = *(float *)((char *)arg1 + 0xf0) - lbl_80562F04;
    float y = fn_801F159C((void **)arg2[1]) - lbl_80562F08;
    float x = *(float *)((char *)arg1 + 0xe8) - lbl_80562F0C;
    int n;
    base.pos.x = base.pos.x + base.z.x * z + base.y.x * y;
    base.pos.y = base.pos.y + base.z.y * z + base.y.y * y;
    base.pos.z = base.pos.z + base.z.z * z + base.y.z * y;
    right = base;
    left = base;
    left.pos.x = base.pos.x + base.x.x * -x;
    left.pos.y = base.pos.y + base.x.y * -x;
    left.pos.z = base.pos.z + base.x.z * -x;
    right.pos.x = base.pos.x + base.x.x * x;
    right.pos.y = base.pos.y + base.x.y * x;
    right.pos.z = base.pos.z + base.x.z * x;
    offsets[0].x = x;
    offsets[0].y = lbl_80562EE4;
    offsets[0].z = lbl_80562EE4;
    offsets[1].x = -x;
    offsets[1].y = lbl_80562EE4;
    offsets[1].z = lbl_80562EE4;
    n = fn_802C7A34(1, (Vec801EF *)offsets, 2);
    fn_802C70AC(*(void **)*arg0, &base, n, -1);
    fn_801EF53C((char *)*arg0 + 4, (Matrix801EF *)&left, (char *)arg2[0] + 0x18);
    fn_801EF53C((char *)*arg0 + 0x28, (Matrix801EF *)&right, (char *)arg2[1] + 0x18);
}
#pragma pop

