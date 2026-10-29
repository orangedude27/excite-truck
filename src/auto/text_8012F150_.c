// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed long s32;

extern void *fn_8012C370(void *, s32, s32 *, s32 *, s32, u8 *);
extern void fn_802E317C(const char *, ...);
extern char lbl_8032AF68[];
extern char lbl_8032AF84[];
#pragma scheduling invalid_target
#pragma unroll off
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void *fn_8012F150(s32 arg0) {
    s32 type;
    u8 flag;
    void *result;
    volatile u8 *base;
    volatile u8 *p;
    u8 temp;
    s32 i;
    result = fn_8012C370((void *)arg0, 0x53544142, &type, 0, 0, &flag);
    if (result == 0) {
        fn_802E317C(lbl_8032AF68, arg0);
    }
    if (type != 0) {
        fn_802E317C(lbl_8032AF84, type, 0, arg0);
    }
    if (flag != 0) {
        base = (volatile u8 *)result;
        temp = base[0];
        base[0] = base[3];
        base[3] = temp;
        temp = base[1];
        base[1] = base[2];
        base[2] = temp;
        temp = base[4];
        base[4] = base[7];
        base[7] = temp;
        temp = base[5];
        base[5] = base[6];
        base[6] = temp;
        p = base + 8;
        for (i = 0; i < 4; i++) {
            temp = p[0];
            p[0] = p[3];
            p[3] = temp;
            temp = p[1];
            p[1] = p[2];
            p[2] = temp;
            temp = p[4];
            p[4] = p[7];
            p[7] = temp;
            temp = p[5];
            p[5] = p[6];
            p[6] = temp;
            temp = p[8];
            p[8] = p[0xB];
            p[0xB] = temp;
            temp = p[9];
            p[9] = p[0xA];
            p[0xA] = temp;
            temp = p[0xC];
            p[0xC] = p[0xF];
            p[0xF] = temp;
            temp = p[0xD];
            p[0xD] = p[0xE];
            p[0xE] = temp;
            p += 0x10;
        }
        temp = base[0x48];
        base[0x48] = base[0x4B];
        base[0x4B] = temp;
        temp = base[0x49];
        base[0x49] = base[0x4A];
        base[0x4A] = temp;
    }
    return result;
}
#pragma use_lmw_stmw reset
#pragma optimize_for_size reset
#pragma unroll reset
#pragma scheduling on
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

