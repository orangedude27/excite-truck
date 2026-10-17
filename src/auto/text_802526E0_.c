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

void fn_80252C78(void) {
    lbl_8055F308 = 1;
    lbl_8055F2F8 -= 1;
}

extern s8 lbl_8055F308;
extern void fn_801BD808(void);
extern void fn_801BDA70(void *);
extern void fn_801BDA74(s32, void *);
extern void fn_80252B88(s32);
extern void *memset(void *, int, unsigned int);
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
