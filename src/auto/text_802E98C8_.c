#include "revolution/SC/scapi.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8056004C;
extern char lbl_8056004D;
extern void *lbl_80560044;
extern void *lbl_80560048;
extern f32 lbl_80560050;
s32 fn_802E98C8(void) {
    return 0;
}

void fn_802E99A8(void) {
}

void fn_802E99AC(void) {
    f32 vol;
    lbl_8056004D = (SCGetWpadMotorMode() == 1);
    vol = (f32)(u32)SCGetWpadSpeakerVolume();
    lbl_80560050 = vol / 127.0f;
}

void* fn_802E9A0C(void) {
    return lbl_80560044;
}

extern void *lbl_80560048;
void* fn_802E9A14(void) {
    return lbl_80560048;
}

char fn_802E9A1C(void) {
    return lbl_8056004C;
}

char fn_802E9A24(void) {
    return lbl_8056004D;
}

f32 fn_802E9A2C(void) { return lbl_80560050; }

