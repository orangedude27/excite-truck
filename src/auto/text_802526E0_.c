#include "types.h"
extern s8 lbl_8055F308;
extern u8 lbl_80498D00[];
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8, lbl_805639E8;
extern u8 lbl_8055F310;
extern const char lbl_803447A8[];
void fn_801BD808(void);
void fn_801BDA70(void *);
void fn_801BDA74(s32, void *);
void fn_80252B88(s32);
void fn_802526E0(void *);
void fn_801BE400(s32, void *, f32);
void fn_80252C90(void);
void fn_802E30C8(const char *, const char *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055EAA8, lbl_8055EAAC, lbl_8055F2F8;
void fn_801BD790(void);
void fn_80252B88(s32 arg0) {
    u8 sp8[0x28];
    fn_802526E0(sp8);
    fn_801BE400(arg0, sp8, lbl_805639E8);
}

void fn_80252BC8(void) {
    fn_801BD790();
    lbl_8055F2F8 = 0;
}

void fn_80252BF0(void) {
    u32 sp8[4];
    s32 index = lbl_8055F2F8;
    lbl_8055F2F8 = index + 1;
    fn_801BD808();
    fn_801BDA70(sp8);
    fn_801BDA74(index, sp8);
    memset(lbl_80498D00 + index * 0x78, 0, 0x78);
    fn_80252B88(index);
    lbl_80498D00[index * 0x78 + 0x30] = 1;
}

void fn_80252C78(void) {
    lbl_8055F308 = 1;
    lbl_8055F2F8 -= 1;
}

extern s8 lbl_8055F308;
extern void fn_801BD808(void);
extern void fn_801BDA70(void *);
extern void fn_801BDA74(s32, void *);
extern void fn_80252B88(s32);

extern u8 lbl_80498D00[];
extern void fn_802526E0(void *);
extern void fn_801BE400(s32, void *, f32);
extern f32 lbl_805639E8;
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8;
extern u8 lbl_8055F310;
extern void fn_80252C90(void);
extern void fn_802E30C8(const char *, const char *);
extern const char lbl_803447A8[];
void fn_80252F50(f32 arg0) {
    f32 threshold = lbl_805639CC;
    f32 step = lbl_805639F8;
    s32 count = 0;
    lbl_8055F30C += lbl_805639E0 * arg0;
    while (lbl_8055F30C > threshold) {
        fn_80252C90();
        count++;
        lbl_8055F30C -= step;
        if (count > 10) {
            if (!lbl_8055F310) {
                lbl_8055F310 = 1;
                fn_802E30C8((const char *)0x8055C120, lbl_803447A8);
            }
            lbl_8055F30C = lbl_805639CC;
            break;
        }
    }
}

void fn_80253004(s32 index, void *out) {
    u8 *src = lbl_80498D00 + index * 0x78;
    u8 *dst = out;
    u32 b, a;
    a = *(u32 *)(src + 0); b = *(u32 *)(src + 4); *(u32 *)(dst + 0) = a; *(u32 *)(dst + 4) = b;
    b = *(u32 *)(src + 8); a = *(u32 *)(src + 12); *(u32 *)(dst + 8) = b; *(u32 *)(dst + 12) = a;
    b = *(u32 *)(src + 16); a = *(u32 *)(src + 20); *(u32 *)(dst + 16) = b; *(u32 *)(dst + 20) = a;
    b = *(u32 *)(src + 24); a = *(u32 *)(src + 28); *(u32 *)(dst + 24) = b; *(u32 *)(dst + 28) = a;
    b = *(u32 *)(src + 32); a = *(u32 *)(src + 36); *(u32 *)(dst + 32) = b; *(u32 *)(dst + 36) = a;
    b = *(u32 *)(src + 40); a = *(u32 *)(src + 44); *(u32 *)(dst + 40) = b; *(u32 *)(dst + 44) = a;
    dst[48] = src[48];
    b = *(u32 *)(src + 52); a = *(u32 *)(src + 56); *(u32 *)(dst + 52) = b; *(u32 *)(dst + 56) = a;
    *(u32 *)(dst + 60) = *(u32 *)(src + 60);
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 64);
        volatile u32 *vdst = (volatile u32 *)(dst + 64);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    b = *(u32 *)(src + 72); a = *(u32 *)(src + 76); *(u32 *)(dst + 72) = b; *(u32 *)(dst + 76) = a;
    b = *(u32 *)(src + 80); a = *(u32 *)(src + 84); *(u32 *)(dst + 80) = b; *(u32 *)(dst + 84) = a;
    b = *(u32 *)(src + 88); a = *(u32 *)(src + 92); *(u32 *)(dst + 88) = b; *(u32 *)(dst + 92) = a;
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 96);
        volatile u32 *vdst = (volatile u32 *)(dst + 96);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    *(u32 *)(dst + 104) = *(u32 *)(src + 104);
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 108);
        volatile u32 *vdst = (volatile u32 *)(dst + 108);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    *(u32 *)(dst + 116) = *(u32 *)(src + 116);
}

extern s8 lbl_8055F308;
extern u8 lbl_80498D00[];
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8, lbl_805639E8;
extern u8 lbl_8055F310;
extern const char lbl_803447A8[];
void fn_801BD808(void);
void fn_801BDA70(void *);
void fn_801BDA74(s32, void *);
void fn_80252B88(s32);
void fn_802526E0(void *);
void fn_801BE400(s32, void *, f32);
void fn_80252C90(void);
void fn_802E30C8(const char *, const char *);
