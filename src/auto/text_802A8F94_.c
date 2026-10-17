#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F8F1;
extern void fn_80128668(void*);
void* fn_802A8F94(void* arg0, s32 arg1) {
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

void fn_802A95A8(void) {
    fn_802A9090();
}

void fn_802A95AC(u8 arg0) {
    lbl_8055F8F1 = arg0;
}
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern s32 lbl_804BD740;
extern s32 lbl_804BD790;
extern f32 lbl_80564978;
