// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed long s32;

void fn_8012F2E4(void) {
    fn_8012C4D8();
}

s32 fn_8012F2E8(s32 *arg0) {
    return *arg0;
}

void *fn_8012F2F0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 *r5 = arg0 + arg2;
    s32 w = *(r5 + 2);
    s32 m = *(arg0 + 0x12) * arg1;
    s32 result = (s32)arg0 + m;
    result = result + w;
    return (void *)(result + 0x4C);
}

