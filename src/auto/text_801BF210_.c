// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8019EECC(void *, void *);

void fn_801BF210(void) {

}

void fn_801BFEB0(void) {

}

long fn_801BFEB4(long arg0) { return arg0 + 0x6C; }

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

extern void PSVECDotProduct(void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_805628B8;
extern float lbl_805628BC;
void fn_801C0E44(void *arg0) {
    PSVECDotProduct(arg0);
}

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

