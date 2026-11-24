// musprerace — pre-race music (mus_prerace.sng, goalline.sfx).
// Recovered TU window 0x8020C140..0x8020CA28+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020CA28 (+ .ctors slot 0x802ED398) remains in
// auto/text_8020CA28_.c pending a promotion pass.
#include <types.h>
#pragma paired_single off

__declspec(section ".data") extern s32 sPreRaceTrackTable;
__declspec(section ".data") extern s32 sPreRaceSongName;
extern s32 *lbl_8055B5D0;
extern s32 *lbl_8055B5D4;
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
extern f32 lbl_805632DC;
extern void fn_8012E81C(s32 *);
extern s32 fn_8012E938(s32 *);
extern s32 fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern void fn_802064D0(s32 *);

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef double f64;

extern f32 fn_8020A5F0(void);
extern void stopTrackMusic(void);
extern void fn_8020C140(void);

extern s32 lbl_8055EE3C;
extern s8 lbl_8055EE40;
extern s8 lbl_8055EE44;
extern s8 lbl_8055EE45;
extern s8 lbl_8055EE46;
extern f32 lbl_8055EE48;
extern f32 lbl_8055EE4C;
extern f32 lbl_8055EE50;
extern f32 lbl_8055EE54;
extern f32 lbl_805632F0;
extern s8 lbl_8055EE58;
extern f32 lbl_805632D8;
extern f32 lbl_805632E0;
extern f64 lbl_805632E8;
extern void fn_80210510(f32);
extern s32 fn_801E8838(void);

extern void fn_8021037C(void);
extern s32 fn_80207848(const char *, s32);
extern const char lbl_8033C5FC[];
extern s32 lbl_8055EE38;
#pragma scheduling invalid_target
#pragma push
#pragma processor 750
void fn_8020C140(void) {
#pragma unroll 1
    f32 factor;
    f32 v1;
    f32 v2;
    f32 v31;
    f32 dc;
    s32 *base;
    s32 ctr;
    void *obj;
    int k;
    v1 = lbl_8055EE48 * lbl_8055EE4C;
    if ((u8)lbl_8055EE58 != 0) {
        if ((u8)lbl_8055EE40 != 0)
            v1 = lbl_805632D8 * v1;
        fn_80210510(v1);
        dc = lbl_805632DC;
        for (k = 0; k < 3; k++) {
            obj = *(void **)((char *)&sPreRaceTrackTable + 0x20 + k * 0x24);
            if (obj != 0 && dc != *(f32 *)((char *)obj + 8)) {
                *(char *)((char *)obj + 0x4D) = 1;
                *(f32 *)((char *)obj + 8) = dc;
            }
        }
    } else {
        v31 = v1 * lbl_8055EE54;
        if ((u8)lbl_8055EE46 != 0)
            v31 *= (f32)(0xFF - fn_801E8838()) / lbl_805632E0;
        fn_80210510(lbl_805632DC);
        factor = lbl_805632D8;
        ctr = 3;
        base = &sPreRaceTrackTable;
        do {
            void * __restrict o = *(void **)((char *)base + 0x20);
            if (o != 0) {
                if ((u8)lbl_8055EE40 != 0)
                    v2 = factor * v31;
                else
                    v2 = v31;
                if (v2 != *(f32 *)((char *)o + 8)) {
                    *(char *)((char *)o + 0x4D) = 1;
                    *(f32 *)((char *)o + 8) = v2;
                }
            }
            base += 9;
        } while (--ctr != 0);
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8020C2AC(void) {
    s32 *sel;
    s32 *base;
    s32 idx;
    u8 *flag;
    f32 f31val;
    s32 tmp;
    void *o1;
    void *o2;
    s32 one;

    lbl_8055EE40 = 0;
    lbl_8055EE48 = fn_8020A5F0();
    base = (s32 *)&sPreRaceTrackTable;
    f31val = lbl_805632DC;
    lbl_8055EE4C = lbl_805632F0;
    idx = 0, one = 1;
    lbl_8055EE50 = lbl_805632F0;
    lbl_8055EE54 = lbl_805632F0;
    do {
        sel = 0;
        flag = 0;
        switch (idx) {
        case 0:
            sel = (s32 *)&sPreRaceSongName;
            flag = (u8 *)&lbl_8055EE41;
            break;
        case 1:
            sel = lbl_8055B5D0;
            flag = (u8 *)&lbl_8055EE42;
            break;
        case 2:
            sel = lbl_8055B5D4;
            flag = (u8 *)&lbl_8055EE43;
            break;
        }
        if (*flag == 0 && fn_8012E938(sel) != 0) {
            fn_8012E81C(sel);
            tmp = fn_80128690();
            if ((u8)tmp == 0) {
                fn_80128684();
            }
            fn_802064D0((s32 *)&sPreRaceSongName);
            if (*(s8 *)base != 0) {
                *(void **)((char *)base + 0x20) = (void *)fn_80207848((const char *)base, 0);
            }
            o1 = *(void **)((char *)base + 0x20);
            if (o1 != 0) {
                if (f31val != *(f32 *)((char *)o1 + 0x64)) {
                    *(s8 *)((char *)o1 + 0x6C) = one;
                    *(f32 *)((char *)o1 + 0x64) = f31val;
                }
                o2 = *(void **)((char *)base + 0x20);
                if (f31val != *(f32 *)((char *)o2 + 0x68)) {
                    *(s8 *)((char *)o2 + 0x6D) = one;
                    *(f32 *)((char *)o2 + 0x68) = f31val;
                }
            }
            *flag = one;
            if ((u8)tmp == 0) {
                fn_80128678();
            }
        }
        idx++;
        base = (s32 *)((char *)base + 0x24);
    } while (idx < 3);
    fn_8020C140();
}
#pragma pop
void fn_8020C41C(void) {
#define InitTrackMusic fn_8021037C
#define CreateSound fn_80207848
#define kGoallineSfx lbl_8033C5FC
#define gGoallineSound lbl_8055EE38
#define gTrackSelection lbl_8055EE45
#define gTrackSelectionLocked lbl_8055EE46
    /* Initializes pre-race music: sets up the track sounds and creates the goalline SFX, then resets track-selection state. */
    InitTrackMusic();
    gGoallineSound = CreateSound(kGoallineSfx, 1);
    gTrackSelection = 0;
    gTrackSelectionLocked = 0;
#undef gTrackSelectionLocked
#undef gTrackSelection
#undef gGoallineSound
#undef kGoallineSfx
#undef CreateSound
#undef InitTrackMusic
}
#pragma scheduling on
extern s32 fn_8012E498(s32 *);
extern s32 fn_802103BC(void);
__declspec(section ".data") extern s32 sPreRaceTrackTable;
__declspec(section ".data") extern s32 sPreRaceSongName;
extern s32 *lbl_8055B5D0;
extern s32 *lbl_8055B5D4;
__declspec(section ".data") extern s32 sPreRaceTrackTable;
__declspec(section ".data") extern s32 sPreRaceSongName;
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
extern f32 lbl_805632DC;
extern void fn_8012E81C(s32 *);
extern s32 fn_8012E938(s32 *);
extern s32 fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern void fn_802064D0(s32 *);
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
#pragma push
#pragma cplusplus on
/* Pre-race music shutdown: release the goalline SFX and each of the three track sounds, then clear their selectors and setup flags. */ extern "C" void fn_8020C45C(void) {
    /* Pre-race music shutdown: release the goalline SFX and the three track
       sounds, then clear their selector state and setup flags. */
    class Releasable {
    public:
        virtual void release(s32);
    };
    Releasable *sound;
    Releasable *trackSound;
    sound = (Releasable *)lbl_8055EE38;
    if (sound != 0 && sound != 0) {
        sound->release(1);
    }
    lbl_8055EE38 = 0;
    fn_802103BC();
    {
        s32 *track = &sPreRaceTrackTable;
        s32 trackIndex = 0;
        do {
            sound = *(Releasable **)((char *)track + 0x20);
            if (sound != 0) {
                *(char *)((char *)sound + 0x4A) = 1;
                *(char *)((char *)sound + 0x4C) = 0;
                trackSound = *(Releasable **)((char *)track + 0x20);
                if (trackSound != 0) {
                    trackSound->release(1);
                }
                *(Releasable **)((char *)track + 0x20) = 0;
            }
            trackIndex += 1;
            track += 9;
        } while (trackIndex < 3);
    }
    fn_8012E498(&sPreRaceSongName);
    fn_8012E498(lbl_8055B5D4);
    fn_8012E498(lbl_8055B5D0);
    lbl_8055EE43 = 0;
    lbl_8055EE42 = 0;
    lbl_8055EE41 = 0;
}
#pragma pop
/* Reset pre-race music: stop track music, restore full fade and race-start
   volume, reload the master volume from the Music setting and clear all
   track-selection and timing state. */
/* Reset pre-race music: stop track music, restore full fade and race-start volume, reload the master volume from the Music setting, and clear all track-selection and timing state. */ void musicPreRaceInit(void) {
    #define kFullVolume lbl_805632F0
    #define gMasterFade lbl_8055EE4C
    #define gFadeTarget lbl_8055EE50
    #define gStartVolume lbl_8055EE54
    #define gMusicVolume lbl_8055EE48
    #define gAudioActive lbl_8055EE40
    #define gFeaturedTrackActive lbl_8055EE44
    #define gTrackStartFrame lbl_8055EE3C
    #define gTrackSelection lbl_8055EE45
    #define gTrackSelectionLocked lbl_8055EE46
    stopTrackMusic();
    gMasterFade = kFullVolume;
    gFadeTarget = kFullVolume;
    gStartVolume = kFullVolume;
    gMusicVolume = fn_8020A5F0();
    gAudioActive = 0;
    gFeaturedTrackActive = 0;
    gTrackStartFrame = 0;
    gTrackSelection = 0;
    gTrackSelectionLocked = 0;
    #undef gTrackSelectionLocked
    #undef gTrackSelection
    #undef gTrackStartFrame
    #undef gFeaturedTrackActive
    #undef gAudioActive
    #undef gMusicVolume
    #undef gStartVolume
    #undef gFadeTarget
    #undef gMasterFade
    #undef kFullVolume
}

extern void fn_8020C2AC(void);
extern s8 fn_802104B8(void);
extern s8 fn_8000D75C(void);
extern s32 fn_800216D0(void);
extern s32 fn_80009C84(void);
extern s32 fn_801B85CC(void);
extern s32 fn_800216FC(void);
extern s32 KERNEL_GetTimeMs(void);
extern void trackMusicUpdate(s32);
extern s8 lbl_8055EE58;
extern f32 lbl_805632D8;
extern f64 lbl_805632E8;
extern f32 lbl_805632F4;
extern f32 lbl_805632F8;
extern f32 lbl_805632FC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Per-frame pre-race music update: pick which of the three music tracks is
 * featured (start countdown/race state), advance the master fade toward its
 * target volume, and tell every track object whether to keep playing. */
void musicPreRaceUpdate(void) {
           register f64 fullVolume;
           f32 temp_f0, temp_f1, temp_f2, temp_f4;
           s32 featuredTrack, selection, active, cached, i, skip;
    s32 elapsed, now, track;
           void *musicObj;
           /* The three track tables start at lbl_8055EE41 and must be set up. */
           if ((u8)lbl_8055EE41 == 0 || (u8)lbl_8055EE43 == 0 || (u8)lbl_8055EE42 == 0) fn_8020C2AC();
           lbl_8055EE58 = fn_802104B8();
           lbl_8055EE40 = fn_8000D75C();
           active = 0;
           if (fn_800216D0() != 0 && fn_80009C84() == 0) active = 1;
           selection = active;
           cached = 1;
           if (fn_801B85CC() == 0 && fn_80009C84() == 0) cached = 0;
           if ((u8)lbl_8055EE45 == 0) lbl_8055EE45 = active;
           else { lbl_8055EE46 = 1; selection = (u8)lbl_8055EE45; }
           featuredTrack = 0;
           if (selection != 0) featuredTrack = 1;
           else if (cached != 0) featuredTrack = 2;
           if (active != 0 && fn_800216FC() != 0) featuredTrack = -1;
           lbl_8055EE54 = lbl_805632F0;
           if (cached != 0 && (u8)lbl_8055EE44 == 0) {
               active = 1;
               lbl_8055EE44 = active;
               if (fn_80009C84() == 0) {
                   /* Remember when the featured track started; fade it in. */
                   lbl_8055EE3C = KERNEL_GetTimeMs();
                   musicObj = (void *)lbl_8055EE38;
                   if (musicObj != 0) {
                       *(u8 *)((u8 *)musicObj + 0x49) = active;
                       *(u8 *)((u8 *)musicObj + 0x4B) = 0;
                       *(u8 *)((u8 *)musicObj + 0x4A) = 0;
                   }
               }
           } else if (cached == 0) {
               now = lbl_8055EE38;
               if (now != 0) {
                   /* No music wanted: fade the current track out. */
                   *(u8 *)(now + 0x4A) = 1;
                   *(u8 *)(now + 0x4C) = 0;
               }
           } else if (fn_80009C84() == 0) {
               now = KERNEL_GetTimeMs();
               if (now >= lbl_8055EE3C && now < lbl_8055EE3C + 0xFA0) {
                   /* Race starts 0xFA0 frames after the track: ramp the
                    * "start" volume from 0 to 1 over 1000 frames. */
                   elapsed = now - lbl_8055EE3C;
                   temp_f0 = ((f32)elapsed - lbl_805632DC) / lbl_805632F4;
                   featuredTrack = 0;
                   temp_f4 = lbl_805632F0;
                   temp_f4 = temp_f4 < temp_f0 ? temp_f4 : temp_f0;
                   temp_f4 = temp_f4 > lbl_805632DC ? temp_f4 : lbl_805632DC;
                   lbl_8055EE54 = lbl_805632F0 + temp_f4 * lbl_805632F8;
               }
           }
           /* Move the master fade toward lbl_8055EE50 by at most 0.2/frame,
            * clamped to 0..1. */
           temp_f2 = lbl_805632D8;
           temp_f0 = lbl_8055EE50 - lbl_8055EE4C;
           temp_f2 = temp_f2 < temp_f0 ? temp_f2 : temp_f0;
           temp_f2 = temp_f2 > lbl_805632FC ? temp_f2 : lbl_805632FC;
           temp_f1 = lbl_805632F0;
           temp_f0 = lbl_8055EE4C + temp_f2;
           temp_f1 = temp_f1 < temp_f0 ? temp_f1 : temp_f0;
           temp_f1 = temp_f1 > lbl_805632DC ? temp_f1 : lbl_805632DC;
           lbl_8055EE4C = temp_f1;
           fn_8020C140();
           fullVolume = lbl_805632F0;
           selection = (s32)&sPreRaceTrackTable;
           i = 0;
           active = 1;
           cached = 0;
           do {
               if (i == featuredTrack) {
                   skip = 0;
                   /* While the race-start ramp runs, keep the third featured
                    * track silent so the ramp track is the one heard. */
                   if ((u8)lbl_8055EE44 != 0 && featuredTrack == 2 && fn_80009C84() == 0) {
                       now = KERNEL_GetTimeMs();
                       if (now >= lbl_8055EE3C && now < lbl_8055EE3C + 0xFA0) skip = 1;
                   }
                   track = *(s32 *)((u8 *)selection + 0x20);
                   if (track != 0 && skip == 0) {
                       *(u8 *)(track + 0x4A) = cached;
                       *(u8 *)(track + 0x4B) = active;
                       *(u8 *)(track + 0x49) = active;
                       track = *(s32 *)((u8 *)selection + 0x20);
                       if (fullVolume != *(f32 *)(track + 4)) {
                           *(u8 *)(track + 0x4E) = active;
                           *(f32 *)(track + 4) = fullVolume;
                       }
                   }
               } else {
                   /* Tracks that are not featured only fade out. */
                   track = *(s32 *)((u8 *)selection + 0x20);
                   if (track != 0) {
                       *(u8 *)(track + 0x4A) = active;
                       *(u8 *)(track + 0x4C) = cached;
                   }
               }
               i += 1;
               selection += 0x24;
           } while (i < 3);
           trackMusicUpdate(0);
       }
#pragma pop
/* Pre-race music module entry point, empty in this build.  The debug action
 * timeline's "sound" command (fn_801C4CE8) calls it when the record names one
 * sound (rec+0xC != -1) and its sibling fn_8020C8F8 when the record names all
 * of them (-1), so this is the "act on the named pre-race track" hook; the
 * retail timeline leaves it a no-op, like fn_8020C8F8, fn_8020C8FC,
 * fn_8020C918 and fn_8020C91C.  The module's live entry points are
 * fn_8020C900 (audio-active flag), fn_8020C908 (master volume) and
 * fn_8020C910 (fade target). */
void fn_8020C8F4(void) {

}

/* Pre-race music module entry point, empty in this build.  The debug action
 * timeline's "sound" command (fn_801C4CE8) calls it when the record's sound id
 * (rec+0xC) is -1, i.e. aimed at every pre-race track at once, where
 * fn_8020C8F4 handles a single named track.  Both hooks do nothing here, like
 * fn_8020C8FC, fn_8020C918 and fn_8020C91C; the module's live entry points are
 * fn_8020C900 (audio-active flag), fn_8020C908 (master volume) and
 * fn_8020C910 (fade target). */
void fn_8020C8F8(void) {

}

/* Pre-race music module entry point, empty in this build.  The debug action
 * timeline's "sound" command (fn_801C4CE8) calls it before fn_8020C8F8 /
 * fn_8020C8F4 when the record's second flag byte (rec+0x15) is set; the flag
 * also picks whether the timeline marks itself waiting for the music
 * (lbl_8055E7E9, cleared again by fn_801C4BAC).  Like fn_8020C8F4,
 * fn_8020C8F8, fn_8020C918 and fn_8020C91C it does nothing in this build; the
 * module's live entry points are fn_8020C900 (audio-active flag),
 * fn_8020C908 (master volume) and fn_8020C910 (fade target). */
void fn_8020C8FC(void) {

}

void fn_8020C900(s8 audioActive) {
#define gAudioActive lbl_8055EE40
    /* Set the cached audio-active flag used to scale pre-race music volume. */
    gAudioActive = audioActive;
#undef gAudioActive
}

void fn_8020C908(f32 musicVolume) {
    /* Set the music mixer's master volume (lbl_8055EE48) and reapply it to the sound objects. */
    lbl_8055EE48 = musicVolume;
    fn_8020C140();
}

void fn_8020C910(f32 fadeTarget) {
    /* Set the master fade target that lbl_8055EE4C lerps toward each frame (clamped to 0..1). */
    lbl_8055EE50 = fadeTarget;
}

/* Pre-race music module entry point, empty in this build.  The only call in
 * the recovered game is the secret key-code handler fn_802485FC: after it has
 * silenced the music with fn_80246CAC(0.0f) (which scales the saved demo
 * volume into fn_8020A5F8) it asks this module to mute its own tracks too by
 * calling it with 1; the retail build ignores the request, like the debug
 * timeline hooks fn_8020C8F4, fn_8020C8F8 and fn_8020C8FC.  The module's live
 * entry points are fn_8020C900 (audio-active flag), fn_8020C908 (master
 * volume), fn_8020C910 (fade target) and fn_8020C91C (song id picked by the
 * kiosk/demo selection). */
void fn_8020C918(s32 muteRequested) {

}

/* Pre-race music module entry point, empty in this build.  The kiosk/demo
 * selection fn_80247210 calls it with the "song_id" resource index of the
 * demo it picked (found through the demo node's find(), see lbl_8055BE98),
 * just before stopping the global music with fn_8020A634 and entering that
 * demo, and again with the -1 "no song" sentinel once the demo is running.
 * The retail module ignores both calls, like fn_8020C8F4, fn_8020C8F8,
 * fn_8020C8FC and fn_8020C918; its live entry points are fn_8020C900
 * (audio-active flag), fn_8020C908 (master volume) and fn_8020C910 (fade
 * target). */
void fn_8020C91C(s32 songId) {

}

extern void fn_8012DDA8(s32 *);
extern void fn_801345D8(char *, s32, const char *, ...);
extern const char sPreRaceMusicStrings[];
extern s32 sPreRaceTrackTable;
extern s32 sPreRaceSongName;
extern s32 lbl_8055B5D8;
extern s32 lbl_8055B5DC;
#pragma push
#pragma use_lmw_stmw off
#pragma opt_propagation off
/* Pre-race music setup: format the pre-race song resource name from songId, queue its TOC plus the two fixed selector TOCs for loading, then fill the three per-track name buffers in sPreRaceTrackTable. */ void musicPreRaceSetup(s32 songId) {
    const char *base = sPreRaceMusicStrings;
    char *dst;
    register s32 songIdCopy;
    register s32 i;
    register s32 variant;
    songIdCopy = songId;
    fn_801345D8((char *)&sPreRaceSongName, 0x20, base + 0x34, songId);
    fn_8012DDA8(&sPreRaceSongName);
    fn_8012DDA8(lbl_8055B5D0);
    fn_8012DDA8(lbl_8055B5D4);
    dst = (char *)&sPreRaceTrackTable;
    i = 0;
    variant = 0;
    do {
        switch (i) {
        case 0:
            fn_801345D8(dst, 0x20, base + 0x40, songIdCopy, variant == 1 ? &lbl_8055B5D8 : &lbl_8055B5DC);
            break;
        case 1:
            fn_801345D8(dst, 0x20, base + 0x50);
            break;
        case 2:
            fn_801345D8(dst, 0x20, base + 0x60);
            break;
        default:
            break;
        }
        i++;
        dst += 0x24;
    } while (i < 3);
}
#pragma pop
