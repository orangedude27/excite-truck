// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern void *lbl_8055F618;
extern s32 lbl_8055F61C;
extern void fn_80128670(s32);
extern void *fn_8012850C(s32, const char *);
extern void fn_8027974C(void);
extern void fn_802795E8();
extern void fn_802E30C8(const char *);
extern char lbl_80347818[];
extern char lbl_80347824[];
extern void *memset(void *, int, u32);
void fn_8027974C(void) {
    s32 offset;
    s32 i;
    offset = 0;
    i = 0;
    goto check;
loop:
    fn_802795E8((char *)lbl_8055F618 + offset + 4);
    offset += 0x2B8;
    i++;
check:
    if (i < lbl_8055F61C) goto loop;
}

void fn_802797A8(s32 *arg0, s32 arg1) {
    s32 offset;
    s32 i;
    char *entry;

    lbl_8055F61C = arg1;
    lbl_8055F618 = fn_8012850C(arg1 * 0x2B8, lbl_80347818);
    i = 0;
    offset = 0;
    while (i < lbl_8055F61C) {
        entry = (char *)lbl_8055F618 + offset;
        memset(entry, 0, 0x2B8);
        *(s32 *)entry = *arg0;
        i++;
        offset += 0x2B8;
        arg0++;
    }
    fn_8027974C();
}

void fn_80279848(void) {
    fn_80128670((s32)lbl_8055F618);
    lbl_8055F618 = 0;
}

void *fn_80279874(s32 arg0) {
    s32 i;
    s32 count;
    char *entry;
    char *base;

    i = 0;
    count = lbl_8055F61C;
    base = (char *)lbl_8055F618;
    entry = base;
    if (count > 0) {
        do {
            if (arg0 == *(s32 *)entry) {
                return base + i * 0x2B8;
            }
            entry += 0x2B8;
            i++;
        } while (i < count);
    }
    fn_802E30C8(lbl_80347824);
    return 0;
}

f32 fn_802798E8(void *arg0) {
    return *(f32 *)((char *)arg0 + 0x294);
}

extern f32 lbl_805640F0;
extern f32 lbl_805640F4;
unsigned char fn_802798F0(u32 arg0, u32 arg1, f32 farg0) {
    s32 var_r0;
    s32 temp_r3;
    s32 temp_r4;
    f32 var_f0;
    if (((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0))) < lbl_805640F0) {
        var_f0 = ((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0))) - lbl_805640F4;
    } else {
        var_f0 = lbl_805640F4 + ((f32)arg0 + (farg0 * ((f32)arg1 - (f32)arg0)));
    }
    var_r0 = 0xFF;
    temp_r4 = (s32)var_f0;
    temp_r3 = -temp_r4;
    temp_r3 &= ~temp_r4;
    temp_r3 >>= 31;
    temp_r3 = temp_r3 & temp_r4;
    if (temp_r3 < 0xFF) var_r0 = temp_r3;
    return (unsigned char)var_r0;
}

void fn_80279B28(unsigned char *arg0, unsigned char *arg1) {
    unsigned int i;
    for (i = 0; i < 0x148; i++) {
        arg1[i + 1] = arg0[i + 3];
    }
    *(f32 *)(arg1 + 0x290) = *(f32 *)(arg0 + 0x294);
    *(f32 *)(arg1 + 0x294) = *(f32 *)(arg0 + 0x298);
    *(s32 *)(arg1 + 0x298) = *(s32 *)(arg0 + 0x29c);
    *(s32 *)(arg1 + 0x29c) = *(s32 *)(arg0 + 0x2a0);
    arg1[0x2a0] = arg0[0x2a4];
    arg1[0x2a1] = arg0[0x2a5];
    arg1[0x2a2] = arg0[0x2a6];
    arg1[0x2a3] = arg0[0x2a7];
    arg1[0x2a4] = arg0[0x2a8];
    arg1[0x2a5] = arg0[0x2a9];
    arg1[0x2a6] = arg0[0x2aa];
    arg1[0x2a7] = arg0[0x2ab];
    arg1[0x2a8] = arg0[0x2ac];
    arg1[0x2a9] = arg0[0x2ad];
    arg1[0x2aa] = arg0[0x2ae];
    arg1[0x2ab] = arg0[0x2af];
    arg1[0x2ac] = arg0[0x2b0];
    arg1[0x2ad] = arg0[0x2b1];
    arg1[0x2ae] = arg0[0x2b2];
    arg1[0x2af] = arg0[0x2b3];
    arg1[0x2b0] = arg0[0x2b4];
    arg1[0x2b1] = arg0[0x2b5];
}

void fn_80279C00(unsigned char* dst, unsigned char* src) {
    int i;
    for (i = 0; i < 0x148; i++) {
        dst[i * 2 + 4] = src[i * 2];
        dst[i * 2 + 5] = src[i * 2 + 1];
    }
    *(f32*)(dst + 0x294) = *(f32*)(src + 0x290);
    *(f32*)(dst + 0x298) = *(f32*)(src + 0x294);
    *(s32*)(dst + 0x29C) = *(s32*)(src + 0x298);
    *(s32*)(dst + 0x2A0) = *(s32*)(src + 0x29C);
    dst[0x2A4] = src[0x2A0]; dst[0x2A5] = src[0x2A1];
    dst[0x2A6] = src[0x2A2]; dst[0x2A7] = src[0x2A3];
    dst[0x2A8] = src[0x2A4]; dst[0x2A9] = src[0x2A5];
    dst[0x2AA] = src[0x2A6]; dst[0x2AB] = src[0x2A7];
    dst[0x2AC] = src[0x2A8]; dst[0x2AD] = src[0x2A9];
    dst[0x2AE] = src[0x2AA]; dst[0x2AF] = src[0x2AB];
    dst[0x2B0] = src[0x2AC]; dst[0x2B1] = src[0x2AD];
    dst[0x2B2] = src[0x2AE]; dst[0x2B3] = src[0x2AF];
    dst[0x2B4] = src[0x2B0]; dst[0x2B5] = src[0x2B1];
}

void fn_80279CD8(void) { fn_802795E8(); }

