#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055FDE4;
extern f32 lbl_8055FDE0;
void fn_802D6B54(void* alarm) {
    fn_802D5F88(fn_802D62E4(alarm));
}

void fn_802D6C4C(f32 arg0) {
    lbl_8055FDE0 = arg0;
}

extern float lbl_804CA308[];
void fn_802D6C54(int arg0, float arg1) {
    lbl_804CA308[arg0] = arg1;
}

void fn_802D754C(u8 arg0) {
    lbl_8055FDE4 = arg0;
}

extern u8 lbl_8055FDFC;
void fn_802D7554(u8 arg0) {
    lbl_8055FDFC = arg0;
}

