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
#define InitRngSlot fn_80129C64
    int slotIndex = 0;
    /* Initialize all seven RNG state blocks with their default seed pair. */
    do {
        InitRngSlot(slotIndex);
        slotIndex++;
    } while (slotIndex < 7);
#undef InitRngSlot
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
void fn_80129C64(int slotIndex) {
    /* Initialize one RNG state slot with the default seed pair. */
    char *state = gRngStateBuffer + slotIndex * RNG_STATE_SIZE;
    InitRngState(state, 0x5AC2, 0x43DB);
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
int fn_80129D90(int slot, int min, int max) {
    /* Draw a random integer in [min, max) from RNG slot `slot`. */
    return min + fn_80129D18(slot, max - min);
}
#pragma dont_inline off
int fn_80129D18(int, int);
extern float lbl_80561258;
#pragma push
#pragma processor 750
#pragma dont_inline on
float fn_80129DC4(int rngSlot, float minValue, float maxValue) {
    /* Returns a random float in [minValue, maxValue) using the given RNG slot. */
    float f = fn_80129D18(rngSlot, 100000);
    float diff = maxValue - minValue;
    return minValue + diff * (f / lbl_80561258);
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
    #pragma optimize_for_size on
    extern double fn_8002EFB4(double, double);
    extern float lbl_80561260, lbl_80561270;
    extern double lbl_80561268, lbl_80561278, lbl_80561280, lbl_80561290, lbl_805612A0;
    int a = (int)(float)fn_8002EFB4((float)arg1 / lbl_80561260, lbl_80561268) + 2;
    int b = (int)(float)fn_8002EFB4((float)arg1, lbl_80561268) + 2;
    int c = (int)(float)fn_8002EFB4((float)arg2 / lbl_80561270, lbl_80561278) + 1;
    int d = (int)(float)fn_8002EFB4((float)arg2, lbl_80561280);
    float *out = (float *)arg0;
    float k125c = 0.0f;
    float k1298 = 1.0f;
    float k129c = 53.0f;
    float k12a8 = 32.0f;
    float k1288 = 0.5f;
    int i, j;
    for (i = 0; i <= 0x60; ++i) {
        float total = 0.0f, v = 0.5f;
        for (j = 0; j <= 0x17; ++j) {
            int m = (int)(float)fn_8002EFB4((float)c * (float)fn_8002EFB4((float)(a * b), lbl_80561290), lbl_80561290);
            a = b; b = c; c = m;
            d = (int)(float)fn_8002EFB4(1.0f + 53.0f * (float)d, lbl_80561280);
            if ((float)fn_8002EFB4((float)(d * m), lbl_805612A0) >= 32.0f) total += v;
            v *= 0.5f;
        }
        *++out = total;
    }
    *(float *)((char *)arg0 + 0x188) = 0.021602630615234375f;
    *(float *)((char *)arg0 + 0x18c) = 0.45629203224182129f;
    *(float *)((char *)arg0 + 0x190) = 0.99999982118606567f;
    *(int *)((char *)arg0 + 0x194) = 0x60;
    *(int *)((char *)arg0 + 0x198) = 0x20;
    *(char *)arg0 = 1;
    #pragma optimize_for_size reset
}
#pragma pop
extern float lbl_8056125C;
extern float lbl_80561298;
/* Advance one RNG state block by a subtract-with-borrow step and return the next
 * float in [0,1): difference the two table cursors (wrapping negatives back into
 * range), decrement both cursors, update the second-stage accumulator, then return
 * the delta minus that accumulator wrapped into range. */
float fn_8012A080(void *rngState) {
    RngState *state = (RngState *)rngState;
    int index0 = state->index0;
    int index1 = state->index1;
    float *value0 = &state->table[index0];
    float *value1 = &state->table[index1];
    float delta = *value0 - *value1;
    if (delta < 0.0f)
        delta = lbl_80561298 + delta;
    *value0 = delta;
    {
        int n = state->index0 - 1;
        state->index0 = n;
        if (n < 0) state->index0 = 96;
    }
    {
        int n = state->index1 - 1;
        state->index1 = n;
        if (n < 0) state->index1 = 96;
    }
    {
        float t = state->acc - state->lag;
        *(volatile float *)&state->acc = t;
        if (t < 0.0f) {
            t = t + state->wrap;
            *(float *)&state->acc = t;
        }
    }
    {
        float result = delta - state->acc;
        if (result < 0.0f)
            return lbl_80561298 + result;
        return result;
    }
}

