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
    float *dst = (float *)((char *)arg0 + 0x28);
    dst[0] = arg1[0];
    dst[1] = arg1[1];
    if (callback == 0) return;
    dst[2] = arg1[2];
    fn_8019EECC(callback, dst);
}

long fn_801C00F0(void *arg0) { return *(long *)((char *)arg0 + 0x18); }

