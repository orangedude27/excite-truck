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

extern void fn_801E9DC4(short *, void *, float, float, float, float, float, float, float, float, float, float, float, float);
void fn_801A6C14(void *arg0) {
    short sp54;
    int sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;
    float sp20;
    float sp1C;
    float sp18;
    float sp14[9];
    float sp10;
    float spC;
    float sp8;
    float temp_f10;
    float temp_f10_2;
    float temp_f11;
    float temp_f12;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f3;
    float temp_f3_2;
    float temp_f4;
    float temp_f4_2;
    float temp_f5;
    float temp_f5_2;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_f7_2;
    float temp_f8;
    float temp_f9;
    float temp_f9_2;
    void *temp_r3;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;

    sp54 = -1;
    temp_r4 = M2C_FIELD(arg0, void **, 0x2700);
    temp_f8 = M2C_FIELD(temp_r4, float *, 0x2A);
    temp_f2 = M2C_FIELD(temp_r4, float *, 0x2E);
    temp_f1 = M2C_FIELD(temp_r4, float *, 0x32);
    temp_f3 = 2.0f * temp_f8;
    temp_f12 = 2.0f * temp_f2;
    temp_f7 = M2C_FIELD(temp_r4, float *, 0x36);
    temp_f11 = 2.0f * temp_f1;
    temp_f5 = temp_f8 * temp_f3;
    temp_f4 = temp_f2 * temp_f12;
    temp_f1_2 = temp_f1 * temp_f11;
    temp_f10 = temp_f7 * temp_f3;
    temp_f9 = temp_f2 * temp_f11;
    sp14[0] = lbl_8056242C - (temp_f4 + temp_f1_2);
    temp_f2_2 = temp_f9 + temp_f10;
    temp_f10_2 = temp_f7 * temp_f12;
    temp_f6 = temp_f8 * temp_f11;
    temp_f9_2 = temp_f7 * temp_f11;
    sp14[4] = lbl_8056242C - (temp_f5 + temp_f1_2);
    temp_f7_2 = temp_f8 * temp_f12;
    temp_f5_2 = temp_f6 + temp_f10_2;
    temp_f3_2 = temp_f6 - temp_f10_2;
    temp_f6_2 = temp_f7_2 - temp_f9_2;
    sp14[7] = temp_f9 - temp_f10;
    temp_f4_2 = temp_f7_2 + temp_f9_2;
    sp14[6] = temp_f5_2;
    sp14[3] = temp_f6_2;
    sp14[1] = temp_f4_2;
    sp14[2] = temp_f3_2;
    sp14[5] = temp_f2_2;
    sp14[8] = lbl_8056242C - (temp_f5 + temp_f4);
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x2700);
    sp38 = M2C_FIELD(temp_r4_2, float *, 0x1E);
    sp3C = M2C_FIELD(temp_r4_2, float *, 0x22);
    temp_f1_3 = M2C_FIELD(temp_r4_2, float *, 0x26);
    sp40 = temp_f1_3;
    sp44 = lbl_80562430;
    sp48 = lbl_80562430;
    sp4C = lbl_80562430;
    sp50 = 0;
    fn_801E9DC4(&sp54, temp_r4_2, temp_f1_3, temp_f2_2, temp_f3_2, temp_f4_2, temp_f5_2, temp_f6_2, temp_f7_2, temp_f8, temp_f9_2, temp_f10_2, temp_f11, temp_f12);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), int (**)(void *, float *), 0x54)(arg0, sp14);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_3, int *, 0x9A) = (int) M2C_FIELD(temp_r4_3, int *, 0);
    M2C_FIELD(temp_r4_3, int *, 0x9E) = (int) M2C_FIELD(temp_r4_3, int *, 4);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xA2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 8);
    M2C_FIELD(temp_r4_3, float *, 0xA3) = (float) M2C_FIELD(temp_r4_3, float *, 9);
    M2C_FIELD(temp_r4_3, float *, 0xA7) = (float) M2C_FIELD(temp_r4_3, float *, 0xD);
    M2C_FIELD(temp_r4_3, float *, 0xAB) = (float) M2C_FIELD(temp_r4_3, float *, 0x11);
    M2C_FIELD(temp_r4_3, int *, 0xAF) = (int) M2C_FIELD(temp_r4_3, int *, 0x15);
    M2C_FIELD(temp_r4_3, float *, 0xB3) = (float) M2C_FIELD(temp_r4_3, float *, 0x19);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB7) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x1D);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB8) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x1E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xB9) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x1F);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBA) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x20);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBB) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x21);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBC) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x22);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBD) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x23);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBE) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x24);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xBF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x25);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x26);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x27);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x28);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC3) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x29);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC4) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2A);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC5) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2B);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC6) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2C);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC7) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2D);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC8) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xC9) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x2F);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCA) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x30);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCB) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x31);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCC) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x32);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCD) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x33);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCE) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x34);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xCF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x35);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x36);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x37);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x38);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD3) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x39);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD4) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3A);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD5) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3B);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD6) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3C);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD7) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3D);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD8) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3E);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xD9) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x3F);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDA) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x40);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDB) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x41);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDC) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x42);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDD) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x43);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDE) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x44);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xDF) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x45);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE0) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x46);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE1) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x47);
    M2C_FIELD(temp_r4_3, unsigned char *, 0xE2) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0x48);
    M2C_FIELD(temp_r4_3, int *, 0xE3) = (int) M2C_FIELD(temp_r4_3, int *, 0x49);
    temp_r3 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r3, int *, 0x4D) = (int) M2C_FIELD(temp_r4_3, int *, 0x9A);
    M2C_FIELD(temp_r3, int *, 0x51) = (int) M2C_FIELD(temp_r4_3, int *, 0x9E);
    M2C_FIELD(temp_r3, unsigned char *, 0x55) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xA2);
    M2C_FIELD(temp_r3, float *, 0x56) = (float) M2C_FIELD(temp_r4_3, float *, 0xA3);
    M2C_FIELD(temp_r3, float *, 0x5A) = (float) M2C_FIELD(temp_r4_3, float *, 0xA7);
    M2C_FIELD(temp_r3, float *, 0x5E) = (float) M2C_FIELD(temp_r4_3, float *, 0xAB);
    M2C_FIELD(temp_r3, int *, 0x62) = (int) M2C_FIELD(temp_r4_3, int *, 0xAF);
    M2C_FIELD(temp_r3, float *, 0x66) = (float) M2C_FIELD(temp_r4_3, float *, 0xB3);
    M2C_FIELD(temp_r3, unsigned char *, 0x6A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB7);
    M2C_FIELD(temp_r3, unsigned char *, 0x6B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB8);
    M2C_FIELD(temp_r3, unsigned char *, 0x6C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xB9);
    M2C_FIELD(temp_r3, unsigned char *, 0x6D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBA);
    M2C_FIELD(temp_r3, unsigned char *, 0x6E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBB);
    M2C_FIELD(temp_r3, unsigned char *, 0x6F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBC);
    M2C_FIELD(temp_r3, unsigned char *, 0x70) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBD);
    M2C_FIELD(temp_r3, unsigned char *, 0x71) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBE);
    M2C_FIELD(temp_r3, unsigned char *, 0x72) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xBF);
    M2C_FIELD(temp_r3, unsigned char *, 0x73) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC0);
    M2C_FIELD(temp_r3, unsigned char *, 0x74) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC1);
    M2C_FIELD(temp_r3, unsigned char *, 0x75) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC2);
    M2C_FIELD(temp_r3, unsigned char *, 0x76) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC3);
    M2C_FIELD(temp_r3, unsigned char *, 0x77) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC4);
    M2C_FIELD(temp_r3, unsigned char *, 0x78) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC5);
    M2C_FIELD(temp_r3, unsigned char *, 0x79) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC6);
    M2C_FIELD(temp_r3, unsigned char *, 0x7A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC7);
    M2C_FIELD(temp_r3, unsigned char *, 0x7B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC8);
    M2C_FIELD(temp_r3, unsigned char *, 0x7C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xC9);
    M2C_FIELD(temp_r3, unsigned char *, 0x7D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCA);
    M2C_FIELD(temp_r3, unsigned char *, 0x7E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCB);
    M2C_FIELD(temp_r3, unsigned char *, 0x7F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCC);
    M2C_FIELD(temp_r3, unsigned char *, 0x80) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCD);
    M2C_FIELD(temp_r3, unsigned char *, 0x81) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCE);
    M2C_FIELD(temp_r3, unsigned char *, 0x82) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xCF);
    M2C_FIELD(temp_r3, unsigned char *, 0x83) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD0);
    M2C_FIELD(temp_r3, unsigned char *, 0x84) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD1);
    M2C_FIELD(temp_r3, unsigned char *, 0x85) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD2);
    M2C_FIELD(temp_r3, unsigned char *, 0x86) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD3);
    M2C_FIELD(temp_r3, unsigned char *, 0x87) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD4);
    M2C_FIELD(temp_r3, unsigned char *, 0x88) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD5);
    M2C_FIELD(temp_r3, unsigned char *, 0x89) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD6);
    M2C_FIELD(temp_r3, unsigned char *, 0x8A) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD7);
    M2C_FIELD(temp_r3, unsigned char *, 0x8B) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD8);
    M2C_FIELD(temp_r3, unsigned char *, 0x8C) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xD9);
    M2C_FIELD(temp_r3, unsigned char *, 0x8D) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDA);
    M2C_FIELD(temp_r3, unsigned char *, 0x8E) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDB);
    M2C_FIELD(temp_r3, unsigned char *, 0x8F) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDC);
    M2C_FIELD(temp_r3, unsigned char *, 0x90) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDD);
    M2C_FIELD(temp_r3, unsigned char *, 0x91) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDE);
    M2C_FIELD(temp_r3, unsigned char *, 0x92) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xDF);
    M2C_FIELD(temp_r3, unsigned char *, 0x93) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE0);
    M2C_FIELD(temp_r3, unsigned char *, 0x94) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE1);
    sp8 = lbl_80562430;
    M2C_FIELD(temp_r3, unsigned char *, 0x95) = (unsigned char) M2C_FIELD(temp_r4_3, unsigned char *, 0xE2);
    spC = lbl_80562430;
    M2C_FIELD(temp_r3, int *, 0x96) = (int) M2C_FIELD(temp_r4_3, int *, 0xE3);
    temp_r4_4 = M2C_FIELD(arg0, void **, 0x2700);
    sp10 = lbl_80562430;
    M2C_FIELD(temp_r4_4, int *, 0x51) = (int) (M2C_FIELD(temp_r4_4, int *, 0x51) - 1);
    temp_r4_5 = M2C_FIELD(arg0, void **, 0x2700);
    M2C_FIELD(temp_r4_5, int *, 0x9E) = (int) (M2C_FIELD(temp_r4_5, int *, 0x9E) - 2);
    M2C_FIELD(arg0, float *, 0x2720) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2724) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2728) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2714) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2718) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x271C) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2708) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x270C) = (float) lbl_80562430;
    M2C_FIELD(arg0, float *, 0x2710) = (float) lbl_80562430;
}
#pragma scheduling reset
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

