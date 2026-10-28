#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern void fn_802E317C(const char *, ...);
extern s32 fn_802DAC64(void);
extern void fn_802D61BC(void *);
extern const char lbl_8034C2F8[];
extern const char lbl_8034C334[];
typedef struct CacheEntry {
    u32 id;
    u8 key;
    u8 unk05[3];
    s32 start;
    s32 size;
} CacheEntry;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_804CA438[];
extern s32 lbl_8055FD1C;
extern u8 lbl_8055FDE4;
extern f32 lbl_8055FDE0;
extern s32 lbl_8055FDF0;
extern s32 lbl_8055FDF4;
extern s32 lbl_8055FDF8;
extern u8 lbl_8034C3DC;
extern void fn_801282EC(s32);
extern void *fn_8012850C(s32, void *);
extern void DCInvalidateRange(void *, u32);
extern void fn_802D6C68(void);
extern void GXSetArray(u32, void *, u32);
extern void GXLoadPosMtxImm(void *, u32);
extern void PSMTXRotTrig(void *, void *, f32, f32, f32);
extern f32 lbl_80565008;
extern u8 lbl_8055FD19;
extern u32 lbl_804C5650[];
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
void fn_802D3F30(void) {
}

void fn_802D3F34(void *arg0) {
    void *array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0xC);
    GXSetArray(0xB, *(void **)((char *)arg0 + 0x24), 2);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D3F98(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xB, *(void **)((char *)arg0 + 0x24), 4);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D3FFC(void *arg0) {
    void *array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0xC);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXSetArray(0xE, *(void **)((char *)arg0 + 0x24), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802D4060(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) return;
    {
        register f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            s32 offset1, offset2;
            f32 weight1, weight2;
            f32 *direction;
            f32 x, y, z;
            a = src[0xE];
            b = src[0xC];
            offset1 = b * 12;
            direction = (f32 *)((u8 *)directions + offset1);
            weight1 = factor * (f32)a;
            c = src[0xD];
            d = src[0xF];
            offset2 = c * 12;
            weight2 = factor * (f32)d;
            x = *(f32 *)((u8 *)src + 0x0) + direction[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + direction[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + direction[2] * weight1;
            out[2] = z;
            direction = (f32 *)((u8 *)directions + offset2);
            src += 0x10;
            out[0] = x + direction[0] * weight2;
            out[1] = y + direction[1] * weight2;
            out[2] = z + direction[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(13, *(void **)((u8 *)object + 0x28), 4);
    GXSetArray(14, *(void **)((u8 *)object + 0x24), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma scheduling on
#pragma pop
void fn_802D41C8(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D422C(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D4280(void *arg0) {
    void * volatile array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0x10);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802D42E4(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)(u32)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) {
        fn_802D4280(object);
        return;
    }
    {
        f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a, b, c, d;
            s32 offset1, offset2;
            f32 weight1, weight2;
            f32 *direction;
            f32 x, y, z;
            a = src[0xE];
            b = src[0xC];
            offset1 = b * 12;
            direction = (f32 *)((u8 *)directions + offset1);
            weight1 = factor * (f32)a;
            c = src[0xD];
            d = src[0xF];
            offset2 = c * 12;
            weight2 = factor * (f32)d;
            x = *(f32 *)((u8 *)src + 0x0) + direction[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + direction[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + direction[2] * weight1;
            out[2] = z;
            direction = (f32 *)((u8 *)directions + offset2);
            src += 0x10;
            out[0] = x + direction[0] * weight2;
            out[1] = y + direction[1] * weight2;
            out[2] = z + direction[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(0xA, *(void **)((u8 *)object + 0x24), 3);
    GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma dont_inline reset
#pragma scheduling on
#pragma pop

#pragma scheduling invalid_target
void fn_802D4458(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) return;
    {
        f32 factor = lbl_80564FF0;
        f32 *out = base;
        for (i = 0; i < count; i++) {
            u8 a = src[0xE];
            s32 offset1 = src[0xC] * 12;
            s32 offset2 = src[0xD] * 12;
            u8 d = src[0xF];
            f32 *first = (f32 *)((u8 *)lbl_804DB068 + offset1);
            f32 *second = (f32 *)((u8 *)lbl_804DB068 + offset2);
            f32 weight1 = factor * (f32)a;
            f32 weight2 = factor * (f32)d;
            f32 x, y, z;
            x = *(f32 *)((u8 *)src + 0x0) + first[0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + first[1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + first[2] * weight1;
            out[2] = z;
            src += 0x10;
            out[0] = x + second[0] * weight2;
            out[1] = y + second[1] * weight2;
            out[2] = z + second[2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(0xB, *(void **)((u8 *)object + 0x24), 2);
    GXSetArray(0xD, *(void **)((u8 *)object + 0x28), 4);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
void fn_802D4C44(void *arg0) {}

void fn_802D5270(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DAC48[];
    extern f32 lbl_80564FF0;
    s32 count = *(s32 *)((u8 *)arg0 + 0x1C);
    u8 *src = *(u8 **)((u8 *)arg0 + 0x20);
    f32 *dst = (f32 *)fn_802CFF64(count * 12);

    if (dst != 0) {
        f32 *out = dst;
        if (count > 0) {
            do {
                volatile f32 sp14[3];
                volatile f32 sp8[3];
                f32 f = lbl_80564FF0 * (f32)src[0xE];
                f32 *m1 = (f32 *)((u8 *)lbl_804DAC48 + ((s32)src[0xC] >> 2) * 0x30);
                f32 g = lbl_80564FF0 * (f32)src[0xF];
                f32 *m2 = (f32 *)((u8 *)lbl_804DAC48 + ((s32)src[0xD] >> 2) * 0x30);
                f32 sx, sy, sz;
                f32 ox, oy, oz;

                if ((u8 *)sp8 == src) {
                    sx = *(f32 *)(src + 0);
                    sy = *(f32 *)(src + 4);
                    sz = *(f32 *)(src + 8);
                    sp8[0] = sz * m1[6] + (sx * m1[0] + sy * m1[3]);
                    sp8[1] = sz * m1[7] + (sx * m1[1] + sy * m1[4]);
                    sp8[2] = sz * m1[8] + (sx * m1[2] + sy * m1[5]);
                } else {
                    sp8[0] = *(f32 *)(src + 8) * m1[6] + (*(f32 *)(src + 0) * m1[0] + *(f32 *)(src + 4) * m1[3]);
                    sp8[1] = *(f32 *)(src + 8) * m1[7] + (*(f32 *)(src + 0) * m1[1] + *(f32 *)(src + 4) * m1[4]);
                    sp8[2] = *(f32 *)(src + 8) * m1[8] + (*(f32 *)(src + 0) * m1[2] + *(f32 *)(src + 4) * m1[5]);
                }
                sp8[0] += m1[9];
                sp8[1] += m1[10];
                sp8[2] += m1[11];

                if ((u8 *)sp14 == src) {
                    sx = *(f32 *)(src + 0);
                    sy = *(f32 *)(src + 4);
                    sz = *(f32 *)(src + 8);
                    sp14[0] = sz * m2[6] + (sx * m2[0] + sy * m2[3]);
                    sp14[1] = sz * m2[7] + (sx * m2[1] + sy * m2[4]);
                    sp14[2] = sz * m2[8] + (sx * m2[2] + sy * m2[5]);
                } else {
                    sp14[0] = *(f32 *)(src + 8) * m2[6] + (*(f32 *)(src + 0) * m2[0] + *(f32 *)(src + 4) * m2[3]);
                    sp14[1] = *(f32 *)(src + 8) * m2[7] + (*(f32 *)(src + 0) * m2[1] + *(f32 *)(src + 4) * m2[4]);
                    sp14[2] = *(f32 *)(src + 8) * m2[8] + (*(f32 *)(src + 0) * m2[2] + *(f32 *)(src + 4) * m2[5]);
                }
                sp14[0] += m2[9];
                sp14[1] += m2[10];
                sp14[2] += m2[11];

                ox = sp8[0] * f;
                out[0] = ox;
                oy = sp8[1] * f;
                out[1] = oy;
                oz = sp8[2] * f;
                out[2] = oz;
                out[0] = ox + sp14[0] * g;
                out[1] = oy + sp14[1] * g;
                out[2] = oz + sp14[2] * g;
                src += 0x10;
                out += 3;
            } while (--count != 0);
        }
        GXSetArray(9, dst, 12);
        GXSetArray(10, *(void **)((u8 *)arg0 + 0x24), 3);
        GXSetArray(13, *(void **)((u8 *)arg0 + 0x28), 4);
        GXCallDisplayList(*(void **)((u8 *)arg0 + 0x30), *(u32 *)((u8 *)arg0 + 0x2C));
    }
}

#pragma dont_inline on
void fn_802D5680(void *arg0) {
    void * volatile array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0x10);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}
#pragma dont_inline reset

extern s32 fn_802CFF64(s32);
extern f32 lbl_804DB068[];
extern f32 lbl_80564FF0;
extern f64 lbl_80564FF8;
#pragma scheduling invalid_target
void fn_802D56D4(void *arg0) {
    extern s32 fn_802CFF64(s32);
    extern f32 lbl_804DB068[];
    extern f32 lbl_80564FF0;
    extern void fn_802D5680(void *);
    register void *object = arg0;
    register volatile u8 *src = *(u8 **)((u8 *)object + 0x20);
    register s32 count = *(s32 *)((u8 *)object + 0x1C);
    f32 *base = (f32 *)fn_802CFF64(count * 12);
    s32 i;
    if (base == 0) {
        fn_802D5680(object);
        return;
    }
    {
        f32 factor = lbl_80564FF0;
        register volatile f32 *out = base;
        f32 (*directions)[3] = (f32 (*)[3])lbl_804DB068;
        for (i = 0; i < count; i++) {
            u8 a = src[0xE];
            u8 b = src[0xC];
            u8 c = src[0xD];
            u8 d = src[0xF];
            f32 weight1 = factor * (f32)a;
            f32 weight2 = factor * (f32)d;
            f32 x, y, z;
            x = *(f32 *)((u8 *)src + 0x0) + directions[b][0] * weight1;
            out[0] = x;
            y = *(f32 *)((u8 *)src + 0x4) + directions[b][1] * weight1;
            out[1] = y;
            z = *(f32 *)((u8 *)src + 0x8) + directions[b][2] * weight1;
            out[2] = z;
            src += 0x10;
            out[0] = x + directions[c][0] * weight2;
            out[1] = y + directions[c][1] * weight2;
            out[2] = z + directions[c][2] * weight2;
            out += 3;
        }
    }
    GXSetArray(9, base, 12);
    GXSetArray(10, *(void **)((u8 *)object + 0x24), 3);
    GXCallDisplayList(*(void **)((u8 *)object + 0x30), *(u32 *)((u8 *)object + 0x2C));
}
#pragma scheduling on

extern f32 *fn_802D2D04(void);
extern f32 PSVECDotProduct(const f32 *, const f32 *);
extern void GXSetCullMode(u32);
extern void GXSetBlendMode(u32,u32,u32,u32);
extern f32 lbl_804C5690[9];
void fn_802D5838(void *arg0) {
 s32 count=*(s32*)((u8*)arg0+0x1C);
 f32 *src=*(f32**)((u8*)arg0+0x20), *norm=*(f32**)((u8*)arg0+0x24);
 f32 *dst=(f32*)fn_802CFF64(count*12), *base=dst;
 if(dst) {
  f32 *m=fn_802D2D04(); f32 v[3]; s32 i;
  if(m==v) { v[0]=m[0]*lbl_804C5690[0]+m[1]*lbl_804C5690[1]+m[2]*lbl_804C5690[2]; v[1]=m[0]*lbl_804C5690[3]+m[1]*lbl_804C5690[4]+m[2]*lbl_804C5690[5]; v[2]=m[0]*lbl_804C5690[6]+m[1]*lbl_804C5690[7]+m[2]*lbl_804C5690[8]; }
  else {v[0]=m[0]*lbl_804C5690[0]+m[1]*lbl_804C5690[1]+m[2]*lbl_804C5690[2];v[1]=m[0]*lbl_804C5690[3]+m[1]*lbl_804C5690[4]+m[2]*lbl_804C5690[5];v[2]=m[0]*lbl_804C5690[6]+m[1]*lbl_804C5690[7]+m[2]*lbl_804C5690[8];}
  for(i=0;i<count;i++){ if(PSVECDotProduct(norm,v)<lbl_80565008){dst[0]=src[0]+v[0]*lbl_8055FDE0;dst[1]=src[1]+v[1]*lbl_8055FDE0;dst[2]=src[2]+v[2]*lbl_8055FDE0;}else{dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];}src+=3;norm+=3;dst+=3;}
  GXSetArray(9,base,12);
  GXSetCullMode(lbl_8055FDE4?2:1);GXSetBlendMode(1,1,1,5);GXCallDisplayList(*(void**)((u8*)arg0+0x30),*(u32*)((u8*)arg0+0x2C));
  GXSetCullMode(lbl_8055FDE4?1:2);GXSetBlendMode(3,1,1,5);GXCallDisplayList(*(void**)((u8*)arg0+0x30),*(u32*)((u8*)arg0+0x2C));
 }
}

void fn_802D5ACC(void *arg0) {
    struct DrawData {
        u8 pad0[0x20];
        void *array0;
        void *array1;
        void *array2;
        u32 size;
        void *list;
        u32 pad34;
        f32 rot0;
        f32 rot1;
    };
    register struct DrawData *data = (struct DrawData *)arg0;
    register void *array = data->array0;
    f32 matrix[3][4];

    GXSetArray(9, array, 0xC);
    GXSetArray(0xB, data->array1, 2);
    GXSetArray(0xD, data->array2, 4);

    PSMTXRotTrig(lbl_804C5650, matrix, data->rot0, lbl_80565008, lbl_80565008);
    GXLoadPosMtxImm(matrix, 3);
    PSMTXRotTrig(lbl_804C5650, matrix, data->rot1, lbl_80565008, lbl_80565008);
    GXLoadPosMtxImm(matrix, 6);

    GXCallDisplayList(data->list, data->size);
    lbl_8055FD19 = 1;
}

void fn_802D5DE8(u32 flags) {
    int desc[54];
    int *p;
    memset(desc,0,0xD8);
    p=desc;
    if (flags & 1) { p[0]=0; p[1]=1; p+=2; }
    if (flags & 2) { p[0]=9; p[1]=2; p+=2; }
    else if (flags & 4) { p[0]=9; p[1]=3; p+=2; }
    if (flags & 8) { p[0]=10; p[1]=2; p+=2; }
    else if (flags & 0x10) { p[0]=10; p[1]=3; p+=2; }
    if (flags & 0x20) { p[0]=11; p[1]=2; p+=2; }
    else if (flags & 0x40) { p[0]=11; p[1]=3; p+=2; }
    if (flags & 0x80) { p[0]=13; p[1]=2; p+=2; }
    else if (flags & 0x100) { p[0]=13; p[1]=3; p+=2; }
    if (flags & 0x200) { p[0]=14; p[1]=2; p+=2; }
    else if (flags & 0x400) { p[0]=14; p[1]=3; p+=2; }
    p[0]=0xff; p[1]=0;
    GXClearVtxDesc();
    GXSetVtxDescv(desc);
}

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802D5F88(s32 arg0) {
    u8 *ptr = (u8 *)arg0;
    register u32 flags = *(u32 *)(ptr + 0xC);
    u32 normalized = flags & 0xFFCFFFFF;
    u8 mode = ptr[9];

    if (normalized != lbl_8055FDE8) {
        GXCallDisplayList(*(void **)(ptr + 0x10), (u32)ptr[0xB] << 5);
        lbl_8055FDE8 = normalized;
        lbl_8055FDEC = mode;
    }
}

void fn_802D61BC(void *arg0) {
    extern u8 lbl_804C5700[];
    extern s32 lbl_8055FD20;
    extern volatile s8 lbl_8055FD25;
    extern u32 lbl_8055FD28;
    extern u8 lbl_8055FDFC;
    extern void fn_802D2614(void);
    extern void fn_802D2B0C(void);
    u8 *object = (u8 *)arg0;
    u8 flags;
    u8 modeFlag;
    lbl_8055FD25 = (*(u8 *)(object + 0xA) >> 3) & 1;
    modeFlag = (*(u8 *)(object + 0xA) >> 4) & 1;
    *(volatile s32 *)(lbl_804C5700 + 4) = 6;
    lbl_804C5700[9] = modeFlag;
    switch (*(u8 *)(object + 8)) {
    case 16:
        *(s32 *)(lbl_804C5700 + 4) = 2;
        break;
    case 18:
        *(s32 *)(lbl_804C5700 + 4) = 1;
        break;
    default:
        flags = *(u8 *)(object + 0xA);
        if (flags & 1) {
            *(s32 *)(lbl_804C5700 + 4) = 3;
        } else if (flags & 2) {
            if (lbl_8055FDFC != 0)
                *(s32 *)(lbl_804C5700 + 4) = 5;
            else
                *(s32 *)(lbl_804C5700 + 4) = 4;
        } else {
            *(s32 *)(lbl_804C5700 + 4) = 0;
        }
        break;
    }
    if (*(u8 *)(object + 0xA) & 4) {
        if (lbl_8055FD28 != *(u32 *)(object + 0x14))
            lbl_8055FD20 |= 0x20;
        lbl_8055FD28 = *(u32 *)(object + 0x14);
    }
    fn_802D2614();
    fn_802D2B0C();
}

#pragma scheduling on
s32 fn_802D62E4(void *arg0) {
    if ((u32)(*(u32 *)arg0 + 0xB1BC0000) != 0x4C32U) {
        return 0;
    }
    return (s32)arg0;
}

#pragma scheduling invalid_target
void fn_802D62FC(void *arg0, s32 *arg1, s32 *arg2) {
    extern s32 lbl_8055FDF0;
    extern s32 lbl_8055FDF4;
    extern s32 lbl_8055FDF8;
    extern void GXBeginDisplayList(void *, u32);
    extern u32 GXEndDisplayList(void);
    extern void fn_802D5DE8(u32);
    register CacheEntry *scan = (CacheEntry *)lbl_804CA438;
    register u32 key = *(u8 *)((u8 *)arg0 + 9);
    register u32 id = *(volatile u32 *)((u8 *)arg0 + 0xC);
    s32 count = *(volatile s32 *)&lbl_8055FDF0;
    s32 i;
    CacheEntry *write;
    s32 size;

    for (i = 0; i < count; i++, scan++) {
        if (scan->id == id && scan->key == key) {
            *arg1 = scan->start;
            *arg2 = scan->size;
            return;
        }
    }

    count = lbl_8055FDF0;
    write = (CacheEntry *)lbl_804CA438 + count;
    write->id = id;
    lbl_8055FDF0 = count + 1;
    write->key = key;
    GXBeginDisplayList((void *)lbl_8055FDF8, lbl_8055FDF4 + 0x4000 - lbl_8055FDF8);
    fn_802D5DE8(id);
    size = GXEndDisplayList();
    write->start = lbl_8055FDF8;
    write->size = size;
    lbl_8055FDF8 += size;
    *arg1 = write->start;
    *arg2 = write->size;
}
#pragma scheduling on
void fn_802D657C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802D6594(void *arg0) {
    u8 *bytes = arg0;
    u8 t0, t1, t2, t3;
    register u8 *p;
    s32 i;

    t0 = bytes[0x34];
    p = bytes + 0x38;
    t1 = bytes[0x37];
    i = 0;
    t2 = bytes[0x35];
    t3 = bytes[0x36];
    bytes[0x34] = t1;
    bytes[0x37] = t0;
    bytes[0x35] = t3;
    bytes[0x36] = t2;

    while (i < *(s32 *)(bytes + 0x34)) {
        t0 = p[0];
        p[0] = p[3];
        p[3] = t0;
        t0 = p[1];
        p[1] = p[2];
        p[2] = t0;
        p += 4;
        i += 1;
    }
}

extern const char lbl_8034C3B4[];
extern f32 lbl_80565010;
extern f32 lbl_80565014;
void fn_802D65F8(s32 arg0, s32 arg1) {
    u8 *bytes = (u8 *)arg0;
    u8 a, b, c, d, e, f, g;
    s32 count = *(s32 *)(bytes + 0x1C);
    u8 *entries;

    extern void fn_802D63FC(void *, s32);
    fn_802D63FC((void *)arg0, arg1);
    a=bytes[0x2C]; b=bytes[0x2F]; c=bytes[0x2D]; d=bytes[0x2E];
    e=bytes[0x30]; f=bytes[0x33]; g=bytes[0x31];
    bytes[0x2C]=b; bytes[0x2F]=a; bytes[0x2D]=d; bytes[0x2E]=c;
    bytes[0x30]=f; bytes[0x33]=e; bytes[0x31]=bytes[0x32]; bytes[0x32]=g;
    fn_802D657C((s32 *)(bytes+0x30),arg1);
    if(bytes[8]==0x1A) fn_802D6594(bytes);
    count=*(s32 *)(bytes+0x1C);
    if(bytes[8]==0x13) {
        entries=*(u8 **)(bytes+0x20);
        if(count>0) {
            do {
                if((entries[0xC]!=0x4C && entries[0xC]!=0x4D) || entries[0xD]!=0) goto second;
                entries+=0x10;
            } while(--count!=0);
        }
        fn_802E317C(lbl_8034C3B4);
        count=*(s32 *)(bytes+0x1C);
        entries=*(u8 **)(bytes+0x20);
        bytes[8]=0x1A;
        while(count-->0) {
            f32 value=lbl_80565010*(f32)entries[0xE]/lbl_80565014;
            *(f32 *)(entries+0xC)=entries[0xC]==0x4C ? value : -value;
            entries+=0x10;
        }
    }
second:
    if(bytes[8]==0x19) {
        count=*(s32 *)(bytes+0x1C);
        entries=*(u8 **)(bytes+0x20);
        if(count>0) do {
            if((entries[0xC]!=0x4C && entries[0xC]!=0x4D) || entries[0xD]!=0) return;
            entries+=0x18;
        } while(--count!=0);
        count=*(s32 *)(bytes+0x1C);
        entries=*(u8 **)(bytes+0x20);
        bytes[8]=0x1B;
        while(count-->0) {
            f32 value=lbl_80565010*(f32)entries[0xE]/lbl_80565014;
            *(f32 *)(entries+0xC)=entries[0xC]==0x4C ? value : -value;
            entries+=0x18;
        }
    }
}

#pragma push
#pragma small_data off
void fn_802D6810(void) {
    void *buffer;

    lbl_8055FDF0 = 0;
    fn_801282EC(0x20);
    buffer = fn_8012850C(0x4000, &lbl_8034C3DC);
    lbl_8055FDF4 = (s32)buffer;
    lbl_8055FDF8 = (s32)buffer;
    DCInvalidateRange(buffer, 0x4000);
    fn_802D6C68();
}

extern void fn_802D0E48(int);
extern void fn_802D5FE4(void *);
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
#pragma scheduling invalid_target
void fn_802D6860(void) {
    s32 lastLength;
    fn_802E30C8(lbl_8034C3F4, lbl_8055FDF8 - lbl_8055FDF4, lbl_8055FDF0);
    fn_80128670(lbl_8055FDF4);
    lastLength = lbl_8055FE00;
    lbl_8055FDF4 = 0;
    lbl_8055FDF8 = 0;
    fn_802E30C8(lbl_8034C428, lastLength);
}
#pragma scheduling on
void fn_802D6B08(void *arg0) {
    fn_802D61BC(arg0);
    if (lbl_8055FD1C & 8) {
        fn_802D6170(arg0);
        return;
    }
    fn_802D5FE4(arg0);
}

#pragma pop
extern s32 fn_802D62E4(void *);
void fn_802D6B54(void *alarm) {
    fn_802D5F88(((s32 (*)(void *))fn_802D62E4)(alarm));
}


extern s32 lbl_8055FD1C;
void fn_802D6B78(void *arg0) {
    fn_802D5FE4(arg0);
}

void fn_802D6B7C(void *arg0) {
    fn_802D6170(arg0);
}

extern void fn_802D65F8(s32, s32);
extern void fn_802E317C(const char *, ...);
extern const char lbl_8034C440[];
#pragma scheduling invalid_target
void fn_802D6B80(u8 *arg0, s32 arg1, s32 arg2) {
    u8 d;
    u8 c;
    u8 b;
    u8 a;
    s32 result;

    a = arg0[0];
    b = arg0[3];
    c = arg0[1];
    d = arg0[2];
    arg0[0] = b;
    arg0[3] = a;
    arg0[1] = d;
    arg0[2] = c;
    result = fn_802D62E4(arg0);
    if (result != 0) {
        ((void (*)(s32, s32, s32))fn_802D65F8)(result, arg1, arg2);
    } else {
        s32 sp8 = *(s32 *)arg0;
        u8 *p = (u8 *)&sp8;
        u8 x = p[0];
        u8 zero = 0;
        p[0] = p[3];
        p[3] = x;
        x = p[1];
        p[1] = p[2];
        p[2] = x;
        p[4] = zero;
        fn_802E317C(lbl_8034C440, arg2, &sp8);
    }
}
#pragma scheduling on
void fn_802D6C44(void) {
}

void fn_802D6C48(void) {
}

void fn_802D6C4C(f32 arg0) {
    lbl_8055FDE0 = arg0;
}

extern float lbl_804CA308[];
void fn_802D6C54(int arg0, float arg1) {
    lbl_804CA308[arg0] = arg1;
}

void fn_802D6C68(void) {
    lbl_8055FDE8 = 0;
    lbl_8055FDEC = 0;
}

void fn_802D754C(u8 arg0) {
    lbl_8055FDE4 = arg0;
}

extern u8 lbl_8055FDFC;
void fn_802D7554(u8 arg0) {
    lbl_8055FDFC = arg0;
}
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802D5FE4(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
#pragma scheduling invalid_target
