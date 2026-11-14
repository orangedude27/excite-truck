// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80129C64(int);

#define RNG_STATE_SIZE 0x19C
#define InitRngState fn_80129E34       /* initialize RNG state block with two seeds */
#define IsDebugSeedOverrideEnabled fn_80019B3C /* lbl_8055D5A0 bit 0 */
#define DebugPrintf fn_802E30C8
#define sSeedLogFormat lbl_8032A5C0    /* "seed[%d]: %d, %d" */
#define gRngStateBuffer lbl_804223F8   /* array of 0x19C-byte RNG state entries */
#define Rng_NextFloat fn_8012A080      /* next [0,1) float drawn from a state block */

/* One RNG state block (RNG_STATE_SIZE bytes): a table of 97 floats in [0,1)
   walked by two cursors 64 apart, whose differences (wrapped back into [0,1))
   feed a second subtract-with-borrow stage. */
typedef struct RngState {
    unsigned char initialized; /* 0x000: set once the table has been filled */
    float table[97];           /* 0x004: [0,1) values, indexed by the cursors */
    float acc;                 /* 0x188: second stage's running value */
    float lag;                 /* 0x18C: value subtracted from acc */
    float wrap;                /* 0x190: 0.99999994, added when a difference is negative */
    int index0;                /* 0x194: table cursor, wraps back to 96 */
    int index1;                /* 0x198: table cursor, wraps back to 96 */
} RngState;

void fn_80129C24(void) {
    int i = 0;
    do {
        fn_80129C64(i);
        i++;
    } while (i < 7);
}

void fn_80129C60(void) {

}

#pragma push
#pragma small_data off
extern char lbl_804223F8[];
#pragma pop
extern int fn_80129E34(void *, int, int);
extern int fn_80019B3C(void);
extern int fn_802E30C8(const char *, int, int, int);
extern char lbl_8032A5C0[];
extern float fn_8012A080(void *);
#pragma scheduling invalid_target
void fn_80129C64(int arg0) {
    char *entry = lbl_804223F8 + arg0 * 0x19C;
    fn_80129E34(entry, 0x5AC2, 0x43DB);
}
#pragma scheduling on
/* Set the RNG seed pair for slot `slotIndex`, logging non-debug seeds, then (re)initialize that slot's state. */
void fn_80129C80(int slotIndex, int seedA, int seedB) {
    int value0 = seedA;
    int value1 = seedB;
    if (IsDebugSeedOverrideEnabled() != 0) {
        value0 = 0x29885B;
        value1 = 0x1A5A7D;
    } else {
        ((int (*)(const char *, ...))DebugPrintf)(
            sSeedLogFormat, slotIndex, value0, value1);
    }
    InitRngState((char *)gRngStateBuffer + slotIndex * RNG_STATE_SIZE, value0, value1);
}

/* Draw a random integer in [0, range) from RNG slot `slot`: scale that slot's
   next [0,1) float by `range`, clamped so rounding can never reach `range`. */
int fn_80129D18(int slot, int range) {
    RngState *state = (RngState *)(gRngStateBuffer + slot * RNG_STATE_SIZE);
    int value = (int)((float)range * Rng_NextFloat(state));
    if (value < range - 1)
        return value;
    return range - 1;
}
#pragma dont_inline on
int fn_80129D90(int unused, int arg0, int arg1) {
    return arg0 + fn_80129D18(unused, arg1 - arg0);
}
#pragma dont_inline off
int fn_80129D18(int, int);
extern float lbl_80561258;
#pragma push
#pragma processor 750
#pragma dont_inline on
float fn_80129DC4(int arg2, float arg0, float arg1) {
    float f = fn_80129D18(arg2, 100000);
    float diff = arg1 - arg0;
    return arg0 + diff * (f / lbl_80561258);
}
#pragma dont_inline off
#pragma pop
extern double fn_8002EFB4(double, double);
extern float lbl_8056125C, lbl_80561298, lbl_80561260, lbl_80561270, lbl_80561288, lbl_8056129C, lbl_805612A8, lbl_805612AC, lbl_805612B0, lbl_805612B4;
extern double lbl_80561268, lbl_80561278, lbl_80561280, lbl_80561290, lbl_805612A0;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_80129E34(void *arg0, int arg1, int arg2) {
    int a = (int)(float)fn_8002EFB4((float)arg1 / lbl_80561260, lbl_80561268) + 2;
    int b = (int)(float)fn_8002EFB4((float)arg1, lbl_80561268) + 2;
    int c = (int)(float)fn_8002EFB4((float)arg2 / lbl_80561270, lbl_80561278) + 1;
    int d = (int)(float)fn_8002EFB4((float)arg2, lbl_80561280);
    float *out = (float *)arg0;
    float k125c = lbl_8056125C;
    float k1298 = lbl_80561298;
    float k129c = lbl_8056129C;
    float k12a8 = lbl_805612A8;
    float k1288 = lbl_80561288;
    int i, j;
    for (i = 0; i <= 0x60; ++i) {
        float total = k125c, v = k1288;
        for (j = 0; j <= 0x17; ++j) {
            int m = (int)(float)fn_8002EFB4((float)c * (float)fn_8002EFB4((float)(a * b), lbl_80561290), lbl_80561290);
            a = b; b = c; c = m;
            d = (int)(float)fn_8002EFB4(k1298 + k129c * (float)d, lbl_80561280);
            if ((float)fn_8002EFB4((float)(d * m), lbl_805612A0) >= k12a8) total += v;
            v *= k1288;
        }
        *++out = total;
    }
    *(float *)((char *)arg0 + 0x188) = lbl_805612AC;
    *(float *)((char *)arg0 + 0x18c) = lbl_805612B0;
    *(float *)((char *)arg0 + 0x190) = lbl_805612B4;
    *(int *)((char *)arg0 + 0x194) = 0x60;
    *(int *)((char *)arg0 + 0x198) = 0x20;
    *(char *)arg0 = 1;
    return 0;
}
#pragma pop
extern float lbl_8056125C;
extern float lbl_80561298;
float fn_8012A080(void *arg0) {
    int index0 = *(int *)((char *)arg0 + 404);
    int index1 = *(int *)((char *)arg0 + 408);
    float *value0 = (float *)((char *)arg0 + index0 * 4 + 4);
    float *value1 = (float *)((char *)arg0 + index1 * 4 + 4);
    float v = *value0 - *value1;
    float temp_f1;
    float temp_f2;
    if (v < lbl_8056125C) {
        v += lbl_80561298;
        *value0 = v;
    }
    index0 = *(int *)((char *)arg0 + 404) - 1;
    *(int *)((char *)arg0 + 404) = index0;
    if (index0 < 0)
        *(int *)((char *)arg0 + 404) = 96;
    index1 = *(int *)((char *)arg0 + 408) - 1;
    *(int *)((char *)arg0 + 408) = index1;
    if (index1 < 0)
        *(int *)((char *)arg0 + 408) = 96;
    temp_f2 = *(float *)((char *)arg0 + 392);
    temp_f1 = *(float *)((char *)arg0 + 396);
    temp_f1 = temp_f2 - temp_f1;
    {
        int wrap = temp_f1 < lbl_8056125C;
        *(volatile float *)((char *)arg0 + 392) = temp_f1;
        if (wrap) {
            temp_f1 += *(float *)((char *)arg0 + 400);
            *(float *)((char *)arg0 + 392) = temp_f1;
        }
    }
    temp_f1 = v - *(float *)((char *)arg0 + 392);
    if (temp_f1 < lbl_8056125C)
        return lbl_80561298 + temp_f1;
    return temp_f1;
}

