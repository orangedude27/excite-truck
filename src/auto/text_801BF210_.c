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
    float x = arg1[0];
    float y = arg1[1];
    float z = arg1[2];
    *(float *)((char *)arg0 + 0x28) = x;
    *(float *)((char *)arg0 + 0x2C) = y;
    if (callback == 0) return;
    *(float *)((char *)arg0 + 0x30) = z;
    fn_8019EECC(callback, (char *)arg0 + 0x28);
}

long fn_801C00F0(void *arg0) { return *(long *)((char *)arg0 + 0x18); }

long fn_801C00F8(void *arg0, long arg1) {
    if (arg1 >= 0 && arg1 < *(long *)((char *)arg0 + 0x24))
        return *(long *)((char *)arg0 + arg1 * 4 + 0x14);
    return 0;
}

void fn_801C0124(float *arg0, float *arg1, float arg2) {
    arg0[0] = arg1[0] * arg2;
    arg0[1] = arg1[1] * arg2;
    arg0[2] = arg1[2] * arg2;
}

