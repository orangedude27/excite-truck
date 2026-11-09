// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_80128668(void *);
extern s32 fn_8012C33C(void *);
extern s32 fn_802CAC28(void *, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern void fn_802CB228();
extern void fn_802CAC54();
extern char lbl_8034AFF8[16];
extern s32 lbl_8055FB6C;
extern s32 lbl_8055FB70;

void *fn_802C2698(void *arg0, s32 arg1) {
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

void fn_802C26F0(void) {
    char *ptr = lbl_8034AFF8;
    s32 result;
    s32 result2;

    if (fn_8012C33C(ptr) != 0)
        result = fn_802CAC28(ptr, 0);
    else
        result = -2;
    lbl_8055FB70 = result;
    if (result == -2)
        result2 = fn_802CB128(0x200, 0x200, 0, 1);
    else
        result2 = -2;
    lbl_8055FB6C = result2;
}

extern s32 fn_801D9B58(void);
extern s32 fn_802C2C00(s32);
extern s32 fn_802C8638(f32 *, f32, f32, f32, f32);
extern s32 fn_802C86E8(s32);
extern s32 fn_802C87B4(s32, s32, s32, s32);
extern s32 fn_802C88BC(s32);
extern s32 fn_802C9294(s32, s32);
extern s32 fn_802C974C(f32, f32, f32);
extern s32 fn_802CB274(s32);
extern f32 lbl_8055FB74, lbl_80564EB4, lbl_80564EB8, lbl_80564EBC, lbl_80564EC0, lbl_80564EC4, lbl_80564EC8, lbl_80564ECC, lbl_80564ED0;
void fn_802C276C(void) {
    f32 sp[12];
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_r31;

    if (lbl_8055FB70 == -2) {
        fn_802CB274(lbl_8055FB6C);
        fn_802C9294(lbl_8055FB6C, 0);
        temp_f3 = lbl_8055FB74 * lbl_80564EB4;
        temp_f3 = lbl_80564EBC * temp_f3;
        temp_f2 = temp_f3 * lbl_80564EC0;
        sp[9] = lbl_80564EB8;
        sp[11] = lbl_80564EB8;
        sp[10] = temp_f2;
        sp[0] = lbl_80564EC4;
        sp[1] = lbl_80564EB8;
        sp[2] = lbl_80564EB8;
        sp[3] = lbl_80564EB8;
        sp[4] = lbl_80564EB8;
        sp[5] = lbl_80564EC8;
        sp[6] = lbl_80564EB8;
        sp[7] = lbl_80564EC8;
        sp[8] = lbl_80564EB8;
        fn_802C8638(sp, sp[0], sp[10], temp_f3, lbl_80564EB8);
        fn_802C87B4(0, 0, 0x200, 0x200);
        fn_802C974C(lbl_80564EC4, lbl_80564ECC + sp[10], lbl_80564ED0);
        fn_802C86E8(0xFF00FF00);
        fn_802C88BC(-1);
        temp_r31 = fn_802C2C00(0);
        fn_801D9B58();
        fn_802C2C00(temp_r31);
        fn_802C9294(-1, 0);
    }
}

void fn_802C2874(void) {
    if (lbl_8055FB6C != -2) {
        fn_802CB228();
        lbl_8055FB6C = -2;
    }
    if (lbl_8055FB70 != -2) {
        fn_802CAC54();
        lbl_8055FB70 = -2;
    }
}

s32 fn_802C28C0(void) {
    if (lbl_8055FB70 != -2)
        return lbl_8055FB70;
    return lbl_8055FB6C;
}

