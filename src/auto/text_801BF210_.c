// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8019EECC(void *, void *);
extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);

void fn_801BF210(void) {

}

void fn_801BFE7C(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] + arg2[0];
    float y = arg1[1] + arg2[1];
    float z = arg1[2] + arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

void fn_801BFEB0(void) {

}

long fn_801BFEB4(long arg0) { return arg0 + 0x6C; }

void GXInitLightAttnA_801BFEBC(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

void fn_801BFECC(void *arg0, void *arg1) {
    int a0 = *(int *)((char *)arg1 + 0x00);
    int a1 = *(int *)((char *)arg1 + 0x04);
    int a2 = *(int *)((char *)arg1 + 0x08);
    int a3 = *(int *)((char *)arg1 + 0x0C);
    int a4 = *(int *)((char *)arg1 + 0x10);
    int a5 = *(int *)((char *)arg1 + 0x14);
    int a6 = *(int *)((char *)arg1 + 0x18);
    int a7 = *(int *)((char *)arg1 + 0x1C);
    int a8 = *(int *)((char *)arg1 + 0x20);
    int a9 = *(int *)((char *)arg1 + 0x24);
    int a10 = *(int *)((char *)arg1 + 0x28);
    int a11 = *(int *)((char *)arg1 + 0x2C);
    *(int *)((char *)arg0 + 0x3C) = a0;
    *(int *)((char *)arg0 + 0x40) = a1;
    *(int *)((char *)arg0 + 0x44) = a2;
    *(int *)((char *)arg0 + 0x48) = a3;
    *(int *)((char *)arg0 + 0x4C) = a4;
    *(int *)((char *)arg0 + 0x50) = a5;
    *(int *)((char *)arg0 + 0x54) = a6;
    *(int *)((char *)arg0 + 0x58) = a7;
    *(int *)((char *)arg0 + 0x5C) = a8;
    *(int *)((char *)arg0 + 0x60) = a9;
    *(int *)((char *)arg0 + 0x64) = a10;
    *(int *)((char *)arg0 + 0x68) = a11;
    fn_8017A580(a5, a6, a7, a8, a9, a10);
}

extern void fn_8019EECC(void *, void *);
void fn_801C00B8(void *arg0, float *arg1) {
    void *callback = *(void **)((char *)arg0 + 4);
    void *self = arg0;
    float x = arg1[0];
    float y = arg1[1];
    float z = arg1[2];
    *(float *)((char *)self + 0x28) = x;
    *(float *)((char *)self + 0x2C) = y;
    *(float *)((char *)self + 0x30) = z;
    if (callback == 0) return;
    fn_8019EECC(callback, (char *)self + 0x28);
}

long fn_801C00F0(void *arg0) { return *(long *)((char *)arg0 + 0x18); }

long fn_801C00F8(void *arg0, long arg1) {
    if (arg1 >= 0 && arg1 < *(long *)((char *)arg0 + 0x24))
        return *(long *)((char *)arg0 + arg1 * 4 + 0x14);
    return 0;
}

void fn_801C0124(float *arg0, float *arg1, float arg2) {
    float x = arg1[0];
    float y = arg1[1];
    float z = arg1[2];
    x *= arg2;
    y *= arg2;
    z *= arg2;
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);
void fn_801C014C(void *arg0, float *arg1) {
    float temp_f2 = arg1[0];
    float temp_f1 = arg1[1];
    float temp_f0 = arg1[2];
    *(float *)((char *)arg0 + 0x30) = temp_f2;
    *(float *)((char *)arg0 + 0x34) = temp_f1;
    *(float *)((char *)arg0 + 0x38) = temp_f0;
    fn_8017A57C(temp_f1, temp_f2);
}

int fn_801C0168(void *arg0) { return *(int *)((char *)arg0 + 0x5A4); }

int fn_801C0170(void *arg0) { return *(int *)((char *)arg0 + 0x59C); }

float fn_801C0178(void) { extern float lbl_8055E3C8; return lbl_8055E3C8; }

extern void fn_801C1C7C(void *, int);
extern void fn_80179EE8(void *, int);
extern void fn_80128668(void *);
extern int lbl_8055E7BC;
extern char lbl_80336A90[];
void *fn_801C0180(void *arg0, int arg1) {
    int temp_r4;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80336A90;
        temp_r4 = lbl_8055E7BC;
        lbl_8055E7BC = temp_r4 - 1;
        fn_801C1C7C(*(void **)((char *)arg0 + 0x214), temp_r4);
        if (arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_801C0440(void *arg0) {
    return *(int *)((char *)arg0 + 0x1EC) != 0;
}

extern void PSVECDotProduct(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_805628B8;
extern float lbl_805628BC;
void fn_801C0E44(void *arg0) { PSVECDotProduct(arg0, arg0); }

void fn_801C0E4C(void *arg0, void *arg1, void *arg2) {
    PSVECCrossProduct(arg1, arg2, arg0);
}

void fn_801C0E60(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] - arg2[0];
    float y = arg1[1] - arg2[1];
    float z = arg1[2] - arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

