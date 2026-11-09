#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 *lbl_8055F834;
typedef struct Rec54 { u32 w[21]; } Rec54;
extern int lbl_8055CB68;
extern int fn_80128670(int);
extern long fn_801EF024(long (*)(void *));
extern void fn_802CAC54(int);
extern void fn_80128668(void*);
void* fn_802A08E8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802A0940(void) {
}

s32 fn_802A0944(void *arg0) {
    s32 index;
    u32 *src;
    u32 *dst;
    u32 *record;
    index = *(s32 *)arg0;
    if (index == 1)
        index = 0x3F - *((s32 *)arg0 + 1);
    else
        index = *((s32 *)arg0 + 1);
    record = (u32 *)(lbl_8055F834 + index * 0x54);
    *record = *(u32 *)arg0;
    record[1] = *((u32 *)arg0 + 1);
    record[2] = *((u32 *)arg0 + 2);
    src = (u32 *)((u8 *)arg0 + 0xC);
    dst = record + 3;
    do {
        *dst++ = *src++;
        *dst++ = *src++;
    } while (src < (u32 *)((u8 *)arg0 + 0x54));
    return 0x54;
}

extern void fn_8012850C(void *, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern int fn_802CAC28(void *, int);
extern void fn_801EEFDC(int, unsigned int);
extern void fn_802A0AF8(void);
extern char lbl_803498E0[];
extern char lbl_803498EC[];
void fn_802A09B0(void) {
    s32 counter;
    s32 offset;
    s32 zero;
    u8 *base;
    counter = 4;
    lbl_8055F834 = (u8 *)((void *(*)(void *, void (*)(void), int, int, int))fn_8002F37C)(
        (void *)((s32 (*)(void *, void *))fn_8012850C)((void *)0x1510, lbl_803498E0),
        fn_802A0AF8, 0, 0x54, 0x40);
    offset = 0;
    zero = 0;
    for (; counter != 0; counter--) {
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 8) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x5C) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0xB0) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x104) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x158) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x1AC) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x200) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x254) = zero;
        offset += 0x2A0;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 8) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x5C) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0xB0) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x104) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x158) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x1AC) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x200) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x254) = zero;
        offset += 0x2A0;
    }
    lbl_8055CB68 = fn_802CAC28(lbl_803498EC, 0);
    fn_801EEFDC((int)fn_802A0944, 6);
}

void fn_802A0AF8(void) {
}

void fn_802A0AFC(void) {
    fn_801EF024(fn_802A0944);
    fn_802CAC54(lbl_8055CB68);
    {
        int value = (int)lbl_8055F834;
        lbl_8055CB68 = -2;
        if (value != 0) fn_80128670(value - 0x10);
        lbl_8055F834 = 0;
    }
}

void fn_802A0B50(void) {
}

extern float lbl_805646D0, lbl_805646D4, lbl_805646D8, lbl_805646DC;
extern double lbl_805646E0;
extern void fn_802C8BD0(int);
extern void fn_802C8D74(void);
extern void fn_802C8DB8(void *, int, short *, int);
typedef struct {
    float f0;
    float f4;
    float f8;
    int unk0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    int unk24;
    float f28;
    float f2C;
} Fn802A0B54Vertex;

typedef union {
    double value;
    struct {
        u32 high;
        u32 low;
    } words;
} Fn802A0B54FloatConv;

typedef struct {
    short indices[0x20];
    Fn802A0B54Vertex vertices[6];
    Fn802A0B54FloatConv firstConv;
    Fn802A0B54FloatConv secondConv;
} Fn802A0B54Work;
#pragma ppc_psq_save off
void fn_802A0B54(void) {
    Fn802A0B54Work work;
    int outer;
    int offset;
    int minusOne;
    int magic;
    int count;
    int first;
    int j;
    double bias;
    float scale;
    float add;
    float size;
    float base;
    float firstFloat;
    float extentFloat;
    float f3;
    float f0;
    float f4;
    u8 *record;

    /* Fix note: place indices, vertices, and float conversion words at their target stack offsets. */
    fn_802C8BD0(lbl_8055CB68);
    bias = lbl_805646E0;
    scale = lbl_805646D8;
    add = lbl_805646DC;
    size = lbl_805646D0;
    base = lbl_805646D4;
    outer = 0;
    offset = 0;
    minusOne = -1;
    magic = 0x43300000;
    do {
        record = lbl_8055F834 + offset;
        count = *(int *)(record + 8);
        if (count > 1) {
            first = *(int *)record;
            work.firstConv.words.high = magic;
            work.firstConv.words.low = (u32)first ^ 0x80000000;
            firstFloat = (float)(work.firstConv.value - bias);
            work.secondConv.words.high = magic;
            work.secondConv.words.low = (u32)(first * 6) ^ 0x80000000;
            extentFloat = (float)(work.secondConv.value - bias);
            f3 = size * firstFloat;
            f0 = size + f3;
            f4 = base + extentFloat;
            for (j = 0; j < count; j++) {
                float jFloat;
                float f;
                work.secondConv.words.high = magic;
                work.secondConv.words.low = (u32)j ^ 0x80000000;
                jFloat = (float)(work.secondConv.value - bias);
                f = (jFloat / scale) * f4;
                work.vertices[j].f0 = *(float *)(record + 0xC);
                work.vertices[j].f4 = *(float *)(record + 0x10);
                work.vertices[j].f8 = *(float *)(record + 0x14);
                work.vertices[j].f10 = f;
                work.vertices[j].f14 = f3;
                work.vertices[j].unk0C = minusOne;
                work.vertices[j].f18 = work.vertices[j].f0;
                work.vertices[j].f1C = work.vertices[j].f4 + add;
                work.vertices[j].f20 = work.vertices[j].f8;
                work.vertices[j].unk24 = minusOne;
                work.vertices[j].f28 = f;
                work.vertices[j].f2C = f0;
                if (j > 0) {
                    int n = j - 1;
                    int at = n * 6;
                    int index = n * 2;
                    work.indices[at + 0] = (short)index;
                    work.indices[at + 1] = (short)(index + 2);
                    work.indices[at + 2] = (short)(index + 1);
                    work.indices[at + 3] = (short)(index + 1);
                    work.indices[at + 4] = (short)(index + 2);
                    work.indices[at + 5] = (short)(index + 3);
                }
                record += 0xC;
            }
            fn_802C8DB8(work.vertices, count * 2, work.indices, (count - 1) * 6);
        }
        outer++;
        offset += 0x54;
    } while (outer < 0x40);
    fn_802C8D74();
}
#pragma ppc_psq_save reset
