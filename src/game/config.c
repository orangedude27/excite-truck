// config — system config ("config: SCCheckStatus returns error!").
// Recovered TU window 0x802E98C8..0x802E9A34 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E9A34 (+ .ctors slot 0x802ED620) remains in
// auto/text_802E9A34_.c pending a promotion pass.
#include "revolution/SC/scapi.h"
#include "revolution/SC/scsystem.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The console's system config, read once by the init below and handed out
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
extern s32 lbl_80560044;
extern s32 lbl_80560048;
extern f32 lbl_80560050;
/* SD-card mount stub: returns a null file-system handle (0 in this build). */
s32 ConfigGetSDCardHandle(void) {
    return 0;
}

/* SCInit/SCCheckStatus and the SC enums come from the two SDK headers above. */
extern void fn_802E317C(const char*, ...); /* panic(): "PANIC: <msg>", then ABEND */
extern void ConfigCacheWpadSettings(void);             /* ConfigCacheWpadSettings(), below */
extern char lbl_8034E238[];                /* "config: SCCheckStatus returns error!" */
extern char lbl_80560040;                  /* sConfigReady */
#pragma scheduling invalid_target
/**
 * @brief Read the console's system config into this module's cache.
 *
 * Starts the SDK's asynchronous config read (SCInit) and spins until the block
 * has arrived, panicking with "config: SCCheckStatus returns error!" if the
 * read failed.  Aspect ratio, sound mode and progressive scan are then cached
 * for the getters at the end of this file - an unknown sound mode falls back
 * to stereo - and ConfigCacheWpadSettings() adds the two WPAD settings.  sConfigReady
 * marks the cache valid; the start-up calls this before anything reads it.
 */
void ConfigReadSystemSettings(void) {
    u32 scStatus;      /* SCCheckStatus()'s SCStatus */
    s32 aspectRatio; /* an SCAspectRatio */
    s32 soundMode;   /* an SCSoundMode */

    SCInit();
    do {
        scStatus = SCCheckStatus();
    } while (scStatus == SC_STATUS_BUSY);
    if (scStatus == SC_STATUS_FATAL) {
        fn_802E317C(sScCheckStatusError);
    }

    aspectRatio = SCGetAspectRatio();
    switch (aspectRatio) {
    default: /* SC_ASPECT_STD, and anything else the config block holds */
        sConfigAspectRatio = SC_ASPECT_STD;
        break;
    case SC_ASPECT_WIDE:
        sConfigAspectRatio = SC_ASPECT_WIDE;
        break;
    }

    soundMode = SCGetSoundMode();
    switch (soundMode) {
    case SC_SND_MONO:
        sConfigSoundMode = SC_SND_MONO;
        break;
    case SC_SND_STEREO: /* anything the config block holds besides mono and */
    default:            /* surround starts the game in stereo */
        sConfigSoundMode = SC_SND_STEREO;
        break;
    case SC_SND_SURROUND:
        sConfigSoundMode = SC_SND_SURROUND;
        break;
    }

    sConfigProgressive = SCGetProgressiveMode() == SC_PROGRESSIVE;
    sConfigReady = 1;
    ConfigCacheWpadSettings();
}
#pragma scheduling on

/* Config subsystem shutdown hook: a no-op, since the config module holds no
 * resources to release (called from the kernel teardown sequence KERNEL_Shutdown). */
void ConfigShutdown(void) {}

/**
 * @brief Cache the two Bluetooth-WPAD settings of the system config.
 *
 * The motor mode becomes a 0/1 and the speaker volume, which the config block
 * stores as 0..SC_MAX_SPEAKER_VOLUME (127), is scaled to 0.0 .. 1.0.
 */
void ConfigCacheWpadSettings(void) {
    sConfigWpadMotor = (SCGetWpadMotorMode() == SC_MOTOR_ON);
    sConfigWpadSpeakerVolume = (f32)(u32)SCGetWpadSpeakerVolume() / (f32)SC_MAX_SPEAKER_VOLUME;
}

/** @brief Get the console's aspect ratio, as set in the system menu (SCAspectRatio). */
/* Return the cached aspect ratio from the system menu (4:3 or 16:9). */ s32 ConfigGetAspectRatio(void) {
    return sConfigAspectRatio;
}

/** @brief Get the sound mode the game should start in (SCSoundMode). */
s32 ConfigGetSCSoundMode(void) {
    return sConfigSoundMode;
}

/** @brief Returns the cached display config flag: 1 for progressive (non-interlaced) output. */
char ConfigGetProgressiveMode(void) {
    return sConfigProgressive;
}

/** @brief Returns the cached WPAD rumble-motor setting: 1 when the rumble motor is enabled. */
char ConfigGetWpadMotorMode(void) {
    return sConfigWpadMotor;
}

/** @brief Get the cached WPAD speaker volume, scaled to 0.0 .. 1.0. */
f32 ConfigGetWpadSpeakerVolume(void) {
    return sConfigWpadSpeakerVolume;
}

