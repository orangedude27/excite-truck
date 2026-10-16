// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
void fn_802C2C00(s32);
void *fn_801E1F44(void);
void fn_802C2C00(s32);
s32 fn_802C990C(s32);
s32 fn_802C2B78(f32, f32, f32);
f32 fn_802A4A50(void);
s32 fn_802A6A7C(void);
s32 fn_802A5CA4(void);
s32 fn_802A5A38(void);
extern s32 lbl_8055F888;
extern s32 lbl_8055F88C;
extern f32 lbl_8055F8A0;
s32 fn_802A6A44(void);
s32 fn_802A5C1C(void);
s32 fn_802A59E0(void);
extern s32 lbl_8055F894, lbl_8055F898, lbl_8055F89C;
extern u8 lbl_80349BF0[], lbl_8055CBC8;
s32 fn_802C6CF8(void);
s32 fn_802CAC54(s32);
s32 fn_802A597C(void);
s32 fn_8028E398(void);
s32 fn_802A5B8C(s32);
s32 fn_802A69D8(s32);
s32 fn_800167F4(void);
s32 fn_802A5384(s32);
s32 fn_802A53B0(void);
s32 fn_80287B38(void *);
s32 fn_802A5878(void);
s32 fn_802CAC28(void *, s32);
void *fn_802AE414(void *);
s32 fn_802C6FC0(void *, s32, s32);
void fn_802A4C20(void) {
    s32 flag;
    flag = lbl_8055F88C;
    if (flag != 0) fn_802A6A44();
    flag = lbl_8055F888;
    if (flag != 0) fn_802A5C1C();
    fn_802A59E0();
}

void fn_802A4C60(void) {
    lbl_8055F8A0 = fn_802A4A50();
    if (lbl_8055F88C != 0) fn_802A6A7C();
    if (lbl_8055F888 != 0) fn_802A5CA4();
    fn_802A5A38();
}

void fn_802A4CA8(void) {
    u8 *p = (u8 *)fn_801E1F44();
    if (p[0x18] != 0) {
        fn_802C2C00(1);
        fn_802C990C(*(s32 *)(p + 8));
        fn_802C2B78(*(f32 *)(p + 0xC), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    }
}

void fn_802A4D00(void) { fn_802C2C00(0); }

