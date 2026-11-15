// config — system config ("config: SCCheckStatus returns error!").
// Recovered TU window 0x802E98C8..0x802E9A34 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E9A34 (+ .ctors slot 0x802ED620) remains in
// auto/text_802E9A34_.c pending a promotion pass.
#include "revolution/SC/scapi.h"
#include "revolution/SC/scsystem.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The console's system config, read once by ConfigInit() below and handed out
 * by the getters at the end of this file.  Named here because the symbols are
 * the project's placeholders (projects can't rename the game's data yet). */
#define sConfigReady lbl_80560040             /* set once the cache is filled in */
#define sConfigAspectRatio lbl_80560044       /* SCAspectRatio: 4:3 or 16:9 */
#define sConfigSoundMode lbl_80560048         /* SCSoundMode: mono/stereo/surround */
#define sConfigProgressive lbl_8056004C       /* 1 when the display is progressive */
#define sConfigWpadMotor lbl_8056004D         /* 1 when the WPAD rumble is enabled */
#define sConfigWpadSpeakerVolume lbl_80560050 /* WPAD speaker volume, 0.0 .. 1.0 */
#define sScCheckStatusError lbl_8034E238      /* "config: SCCheckStatus returns error!" */

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
extern void fn_802E317C(const char*, ...); /* panic(): "PANIC: <msg>", then ABEND */
extern void fn_802E99AC(void);            /* ConfigReadWpadSettings(), below */
#pragma scheduling invalid_target
#pragma scheduling invalid_target
void fn_802E98D0(void) {
    u32 status;
    s32 aspectRatio;
    s32 soundMode;
    SCInit();
    do {
        status = SCCheckStatus();
    } while (status == SC_STATUS_BUSY);
    if (status == SC_STATUS_FATAL) {
        fn_802E317C(sScCheckStatusError);
    }
    aspectRatio = SCGetAspectRatio();
    if (aspectRatio == SC_ASPECT_WIDE) goto aspect_wide;
    *(volatile s32*)&sConfigAspectRatio = SC_ASPECT_STD;
    goto aspect_done;
aspect_wide:
    *(volatile s32*)&sConfigAspectRatio = SC_ASPECT_WIDE;
aspect_done:
    /* switch (soundMode) the compiler turned into a branch tree: the three
     * known modes keep their value, everything else lands on stereo. */
    soundMode = SCGetSoundMode();
    if (soundMode == SC_SND_STEREO) goto sound_stereo;
    if (soundMode >= SC_SND_STEREO) goto sound_over;
    if (soundMode < SC_SND_MONO) goto sound_stereo;
    goto sound_mono;
sound_over:
    if (soundMode < 3 /* SC_SND_SURROUND + 1 */) goto sound_surround;
    goto sound_stereo;
sound_mono:
    *(volatile s32*)&sConfigSoundMode = SC_SND_MONO;
    goto sound_done;
sound_stereo:
    *(volatile s32*)&sConfigSoundMode = SC_SND_STEREO;
    goto sound_done;
sound_surround:
    *(volatile s32*)&sConfigSoundMode = SC_SND_SURROUND;
sound_done:
    sConfigProgressive = SCGetProgressiveMode() == SC_PROGRESSIVE;
    sConfigReady = 1;
    fn_802E99AC();
}
#pragma scheduling on

void fn_802E99A8(void) {
}

void fn_802E99AC(void) {
    /* Cache WPAD motor enable (SC motor mode == 1) and speaker volume (0..1 from 0..127). */
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

