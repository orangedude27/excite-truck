// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_80128668(void *);
extern s32 fn_8012C33C(void *);
extern s32 fn_802CAC28(void *, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern void fn_802CB228(void);
extern void fn_802CAC54(void);
extern s32 lbl_8034AFF8;
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
