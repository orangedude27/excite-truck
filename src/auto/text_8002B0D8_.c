// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

extern double lbl_80560AE0;
extern double lbl_80560AD0;
extern double lbl_80560A98;
extern double __kernel_tan(int, double, double);
extern int __ieee754_rem_pio2(double, double *);


extern unsigned char lbl_802FE850[];
extern double lbl_805609D8, lbl_805609E0, lbl_805609E8, lbl_805609F0, lbl_805609F8, lbl_80560A00, lbl_80560A08;
void fn_8002B0D8(unsigned char *s) {
    unsigned char *p;
    int c;
    p = s;
    do {
        c = (signed char)*p;
        if (c >= 0 && c < 256)
            c = *((unsigned char *)(*(unsigned int *)(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x10)) + c);
        *p++ = c;
    } while ((signed char)*p != 0);
}

int stricmp(unsigned char *a, unsigned char *b) {
    int c1, c2;
    unsigned char *tbl;
    tbl = *(unsigned char **)(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x10);
    for (;;) {
        c1 = (signed char)*a++;
        if (c1 >= 0 && c1 < 256) c1 = tbl[c1];
        c2 = (signed char)*b++;
        if (c2 >= 0 && c2 < 256) c2 = tbl[c2];
        c1 = (signed char)c1;
        c2 = (signed char)c2;
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        if (c1 == 0) return 0;
    }
}

void fn_8002B1D8(void) {
    fn_800248A4();
}

double __kernel_sin(int iy, double x, double y) {
    double z, v, r;
    int hx;
    z = x;
    hx = *(int *)&z & 0x7fffffff;
    if (hx < 0x3e400000 && (int)x == 0) return x;
    z = x * x;
    v = z * x;
    r = lbl_805609D8 + z * (lbl_805609E0 + z * (lbl_805609E8 + z * (lbl_805609F0 + lbl_805609F8 * z)));
    if (iy == 0)
        return x + v * (lbl_80560A00 + z * r);
    return x - ((z * (lbl_80560A08 * y - v * r) - y) - lbl_80560A00 * v);
}

double copysign(double x, double y) {
    union { double d; unsigned int i[2]; } a, b;
    a.d = x; b.d = y;
    a.i[0] = (a.i[0] & 0x7fffffff) | (b.i[0] & 0x80000000);
    return a.d;
}

double frexp(double x, int *eptr) {
    union { double d; unsigned int i[2]; } u;
    int hx, lx;
    u.d = x;
    hx = u.i[0];
    lx = u.i[1];
    *eptr = 0;
    hx &= 0x7fffffff;
    if (hx < 0x7ff00000) {
        if ((hx | lx) == 0) return x;
        if (hx < 0x00100000) {
            *eptr = -54;
            x *= lbl_80560A98;
            u.d = x;
            hx = u.i[0] & 0x7fffffff;
        }
        *eptr += (hx >> 20) - 0x3fe;
        u.i[0] = (u.i[0] & 0x800fffff) | 0x3fe00000;
        return u.d;
    }
    return x;
}

double fn_8002EF30(double x) {
    int hx;
    double y[2];
    hx = *(int *)&x & 0x7fffffff;
    if (hx <= 0x3fe921fb) return __kernel_tan(1, x, 0.0);
    if (hx >= 0x7ff00000) return x - x;
    hx = __ieee754_rem_pio2(x, y);
    return __kernel_tan(1 - ((hx & 1) << 1), y[0], y[1]);
}

void fn_8002EFA8(void) {
    __ieee754_acos();
}

void fn_8002EFAC(void) {
    __ieee754_asin();
}

void fn_8002EFB0(void) {
    __ieee754_atan2();
}

void fn_8002EFB4(void) {
    __ieee754_fmod();
}

void fn_8002EFB8(void) {
    __ieee754_log();
}

void fn_8002EFBC(void) {
    __ieee754_pow();
}

double fn_8002F208(void) {
    fn_8002EFB8();
    return lbl_80560AE0 * __ieee754_log();
}

void fn_8002F230(void) {

}

void fn_8002F234(void) {
    __ieee754_sqrt();
}

