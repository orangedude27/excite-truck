#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 *lbl_8055F834;
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
void fn_802A0B54(void) {
    char sp48[0x120];
    short indices[0x80];
    int outer=0, offset=0;
    float size=lbl_805646D0, scale=lbl_805646D8, base=lbl_805646D4, add=lbl_805646DC;
    fn_802C8BD0(lbl_8055CB68);
    do {
        char *entry=(char *)lbl_8055F834+offset;
        int count=*(int *)(entry+8);
        if (count>1) {
            int first=*(int *)entry, j, ioff=0;
            float f3=size*(float)first;
            for (j=0;j<count;j++) {
                char *dst=sp48+ioff;
                float f=((float)j/scale)*(base+(float)(first*6));
                *(float *)(dst+0)=*(float *)(entry+12);
                *(float *)(dst+4)=*(float *)(entry+16);
                *(float *)(dst+8)=*(float *)(entry+20);
                *(float *)(dst+16)=f; *(float *)(dst+20)=f3;
                *(int *)(dst+12)=-1; *(int *)(dst+24)=*(int *)dst;
                *(float *)(dst+28)=*(float *)(dst+4);
                *(float *)(dst+32)=*(float *)(dst+8);
                *(int *)(dst+36)=-1; *(float *)(dst+40)=f;
                *(float *)(dst+28)+=add; *(float *)(dst+44)=size+f3;
                if (j>0) {
                    int n=j-1, at=(j-1)*6;
                    indices[at-3]=(short)(n*2); indices[at-2]=(short)(n*2+2);
                    indices[at-1]=(short)(n*2+1); indices[at]=(short)(n*2+1);
                    indices[at+1]=(short)(n*2+2); indices[at+2]=(short)(n*2+3);
                }
                ioff+=0x30; entry+=0xc;
            }
            fn_802C8DB8(sp48,count*2,indices,(count-1)*6);
        }
        outer++; offset+=0x54;
    } while (outer<0x40);
    fn_802C8D74();
}

