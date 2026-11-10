// config — system config ("config: SCCheckStatus returns error!").
// Recovered TU window 0x802E98C8..0x802E9A34 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E9A34 (+ .ctors slot 0x802ED620) remains in
// auto/text_802E9A34_.c pending a promotion pass.
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

#pragma scheduling invalid_target
extern void SCInit(void);
extern u32 SCCheckStatus(void);
extern void fn_802E317C(const char*, ...);
extern void fn_802E99AC(void);
extern char lbl_8034E238[];
extern char lbl_80560040;
#pragma scheduling invalid_target
void fn_802E98D0(void) {
    u32 status;
    s32 aspect;
    s32 soundMode;
    u8 prog;
    SCInit();
    do {
        status = SCCheckStatus();
    } while (status == 1);
    if (status == 2) {
        fn_802E317C(lbl_8034E238);
    }
    aspect = SCGetAspectRatio();
    if (aspect == 1) goto aspect_one;
    *(volatile s32*)&lbl_80560044 = 0;
    goto aspect_done;
aspect_one:
    *(volatile s32*)&lbl_80560044 = 1;
aspect_done:
    soundMode = SCGetSoundMode();
    if (soundMode == 1) goto sound_one;
    if (soundMode >= 1) goto sound_three;
    if (soundMode < 0) goto sound_one;
    goto sound_zero;
sound_three:
    if (soundMode < 3) goto sound_two;
    goto sound_one;
sound_zero:
    *(volatile s32*)&lbl_80560048 = 0;
    goto sound_done;
sound_one:
    *(volatile s32*)&lbl_80560048 = 1;
    goto sound_done;
sound_two:
    *(volatile s32*)&lbl_80560048 = 2;
sound_done:
    prog = SCGetProgressiveMode();
    *(volatile char*)&lbl_8056004C = (prog - 1) == 0;
    *(volatile char*)&lbl_80560040 = 1;
    fn_802E99AC();
}
#pragma scheduling on

void fn_802E99A8(void) {
}

void fn_802E99AC(void) {
    lbl_8056004D = (SCGetWpadMotorMode() == 1);
    lbl_80560050 = (f32)(u32)SCGetWpadSpeakerVolume() / 127.0f;
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

