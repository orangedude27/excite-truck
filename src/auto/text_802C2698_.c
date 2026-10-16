// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_80128668(void *);
extern s32 fn_8012C33C(void *);
extern s32 fn_802CAC28(void *, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern void fn_802CB228(void);
extern void fn_802CAC54(void);
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

