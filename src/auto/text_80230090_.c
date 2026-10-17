#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055B998;
extern f32 lbl_8055F02C;
extern f32 lbl_8055F030;
extern f32 lbl_80563610;
extern f32 lbl_80563614;
extern f32 lbl_8056365C;
extern f32 lbl_80563660;
f64 fn_8002EFB4();
void fn_80230B38(void* alarm) {
    fn_802C2B48(fn_802C855C(alarm));
}

void fn_80230DA0(void) {}

void fn_80230DA4(float a, float b) {
    float value;
    lbl_8055F030 = a;
    value = (float)fn_8002EFB4();
    if (value < lbl_80563614) value += b;
    lbl_8055F02C = b - value;
}

float fn_80230DF4(float a, float b) {
    float value = (float)fn_8002EFB4(a + lbl_8055F02C);
    if (value < lbl_80563614) value += b;
    value /= b;
    if (value < lbl_8056365C) value = lbl_80563610 - value;
    return value;
}

void fn_80230E54(float a, float b) {}

void fn_8023108C(u8 arg0) {
    lbl_8055B998 = arg0;
}
