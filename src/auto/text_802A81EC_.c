#include "types.h"
extern f32 PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
extern f32 lbl_80558DC4, lbl_80564928, lbl_8056494C;
extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern f32 fn_80287BC8(f32, f32);
extern f32 lbl_80564944, lbl_80564948, lbl_80564950;


extern f32 lbl_8055E3C8;

extern s32 lbl_804BD6C4[];
extern f32 lbl_8055F8D4;
extern f32 lbl_8055F8D8;
extern f32 lbl_80564954;

s32 fn_802A8A34(void* ptr);
s32 fn_802A8A3C(s32 *arg0, s32 arg1);
void fn_802A8978(void);
void fn_802A81EC(void);

void fn_802A81EC(void) {

}

extern void fn_80128668(void *);
extern void fn_802C6CF8(s32);
void fn_802A85C8(void) {
    s32 i;
    s32 offset;
    s32 j;
    s32 suboffset;
    void *entry;
    i = 0;
    offset = 0;
    while (i < lbl_804BD6C4[1]) {
        entry = *(void **)((u32)lbl_804BD6C4[0] + offset);
        if (entry != 0) {
            j = 0;
            suboffset = 0;
            while (j < *(s32 *)((u8 *)entry + 0x2c)) {
                fn_802C6CF8(*(s32 *)((u32)*(u32 *)((u8 *)entry + 0x28) + suboffset));
                suboffset += 4;
                j++;
            }
            *(s32 *)((u8 *)entry + 0x2c) = 0;
            *(s32 *)((u8 *)entry + 0x70) = 0;
            if ((u32)entry + 0x6c != 0) {
                *(s32 *)((u8 *)entry + 0x6c) = 0;
                *(s32 *)((u8 *)entry + 0x70) = 0;
                *(s32 *)((u8 *)entry + 0x74) = 0;
            }
            if ((u32)entry + 0x28 != 0) {
                *(s32 *)((u8 *)entry + 0x28) = 0;
                *(s32 *)((u8 *)entry + 0x2c) = 0;
                *(s32 *)((u8 *)entry + 0x30) = 0;
            }
            fn_80128668(entry);
        }
        offset += 4;
        i++;
    }
    lbl_804BD6C4[1] = 0;
}

void fn_802A8978(void) {
    s32* base;
    u8* entry;
    s32 j;
    s32 offset;
    s32 i;
    f32 temp;

    temp = lbl_8055E3C8;
    lbl_8055F8D4 = temp - lbl_8055F8D8;
    if (temp < lbl_8055F8D8) {
        lbl_8055F8D4 = lbl_80564954;
    }
    lbl_8055F8D8 = temp;
    base = (s32*)&lbl_804BD6C4;
    i = 0;
    offset = 0;
    while (i < base[1]) {
        entry = *(u8**)((u32)lbl_804BD6C4[0] + offset);
        fn_802A8A4C((s32)entry, (s32)(entry + 0x60));
        j = 0;
        while (j < fn_802A8A34((void*)(entry + 0x6c))) {
            fn_802A8A3C((s32 *)(entry + 0x6c), j);
            fn_802A8A4C((s32)(entry + 0x6c), (s32)entry);
            j++;
        }
        offset += 4;
        i++;
    }
}

s32 fn_802A8A34(void* ptr) {
    return ((s32*)ptr)[1];
}

s32 fn_802A8A3C(s32 *arg0, s32 arg1) {
    return *arg0 + arg1 * 0x28;
}

extern f32 PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
extern void PSVECCrossProduct(const void *, const void *, void *);
extern void fn_802C744C(s32 arg0, void *arg1);
extern f32 lbl_80558DC4;
extern f32 lbl_80564928;
extern f32 lbl_8056494C;
void fn_802A8DE8(void) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14b;
    s32 i;
    s32 j;
    s32 offset;
    void *entry;
    f32 *vec;
    f32 fx, fy, fz;

    fx = lbl_80564928;
    fy = lbl_8056494C;
    i = 0;
    offset = 0;
    while (i < lbl_804BD6C4[1]) {
        entry = *(void **)((u32)lbl_804BD6C4[0] + offset);
        j = 0;
        vec = (f32 *)0;
        while (j < *(s32 *)((u8 *)entry + 0x70)) {
            s32 *vp = (s32 *)((u8 *)entry + 0x6C);
            f32 *v = (f32 *)(*(u32 *)vp + (u32)vec);
            sp2C = v[0];
            sp30 = v[1];
            sp34 = v[2];
            sp20 = v[3];
            sp24 = v[4];
            sp28 = v[5];
            if (__fabsf(PSVECDotProduct((void *)&sp20, (void *)&sp20)) == lbl_80558DC4) {
                sp20 = fx;
                sp24 = fx;
                sp28 = fy;
            }
            PSVECNormalize((void *)&sp20, (void *)&sp20);
            sp14 = fx;
            sp18 = fy;
            sp1C = fx;
            PSVECCrossProduct((void *)&sp14, (void *)&sp20, (void *)&sp8);
            fn_802C744C(*(s32 *)((u8 *)entry + 0x28 + ((j % *(s32 *)((u8 *)entry + 0x2C)) * 4)), &sp8);
            vec = (f32 *)((u32)vec + 0x28);
            j++;
        }
        offset += 4;
        i++;
    }
}

