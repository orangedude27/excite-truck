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
/* Load a STAB resource chunk and byte-swap its fields in place when the data is flagged as endian-swapped. */
void *fn_8012F150(s32 resource) {
    s32 chunkType;
    u8 needsSwap;
    void *data;
    volatile u8 *base;
    volatile u8 *entry;
    u8 tmp;
    s32 i;
    data = fn_8012C370((void *)resource, 0x53544142, &chunkType, 0, 0, &needsSwap);
    if (data == 0) {
        fn_802E317C(lbl_8032AF68, resource);
    }
    if (chunkType != 0) {
        fn_802E317C(lbl_8032AF84, chunkType, 0, resource);
    }
    if (needsSwap != 0) {
        base = (volatile u8 *)data;
        tmp = base[0];
        base[0] = base[3];
        base[3] = tmp;
        tmp = base[1];
        base[1] = base[2];
        base[2] = tmp;
        tmp = base[4];
        base[4] = base[7];
        base[7] = tmp;
        tmp = base[5];
        base[5] = base[6];
        base[6] = tmp;
        entry = base + 8;
        for (i = 0; i < 4; i++) {
            tmp = entry[0];
            entry[0] = entry[3];
            entry[3] = tmp;
            tmp = entry[1];
            entry[1] = entry[2];
            entry[2] = tmp;
            tmp = entry[4];
            entry[4] = entry[7];
            entry[7] = tmp;
            tmp = entry[5];
            entry[5] = entry[6];
            entry[6] = tmp;
            tmp = entry[8];
            entry[8] = entry[0xB];
            entry[0xB] = tmp;
            tmp = entry[9];
            entry[9] = entry[0xA];
            entry[0xA] = tmp;
            tmp = entry[0xC];
            entry[0xC] = entry[0xF];
            entry[0xF] = tmp;
            tmp = entry[0xD];
            entry[0xD] = entry[0xE];
            entry[0xE] = tmp;
            entry += 0x10;
        }
        tmp = base[0x48];
        base[0x48] = base[0x4B];
        base[0x4B] = tmp;
        tmp = base[0x49];
        base[0x49] = base[0x4A];
        base[0x4A] = tmp;
    }
    return data;
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

