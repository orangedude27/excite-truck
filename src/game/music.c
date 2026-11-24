// music — music playback ("music: play!", player_music_vol).
// Recovered TU window 0x80209FFC..0x8020A6A4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020A6A4 (+ .ctors slot 0x802ED38C) remains in
// auto/text_8020A6A4_.c pending a promotion pass.
#pragma use_lmw_stmw off

extern char lbl_8055EDDC;
extern const char lbl_8033C308[];
extern void fn_802E30C8(const char*, ...);
#pragma dont_inline on
void fn_8020A634(void) {
    /* Clear the global music-play flag (set by fn_8020A600 with "music: play!"), stopping playback. */
    lbl_8055EDDC = 0;
}
#pragma dont_inline off

/* Return the global music-play enabled flag (set by fn_8020A600, cleared by fn_8020A634). */
char fn_8020A640(void) {
    return lbl_8055EDDC;
}

extern void *lbl_8055EDE0;
/* Return lbl_8055EDE0, the index of the currently active music track (compared against the requested track gRequestedSongIdx). */
void* fn_8020A69C(void) {
    return lbl_8055EDE0;
}

#include "types.h"

extern f32 lbl_8055EDD8;
/* Set the global music playback volume (the "Music" setting), read back by fn_8020A5F0. */
void fn_8020A5F8(f32 volume) {
    lbl_8055EDD8 = volume;
}

#pragma scheduling invalid_target
/* Music-playback enable: log "music: play!" and set the music-enabled flag. */
void fn_8020A600(void) {
    fn_802E30C8(lbl_8033C308);
    lbl_8055EDDC = 1;
}
#pragma scheduling on

s32 fn_802E2C20(void);            /* milliseconds since boot */
extern const char gSetSongIdxFmt[]; /* "music: setting song idx to %d" */
extern s32 gRequestedSongIdx;          /* song index last requested (-1 = no music) */
extern s32 gSongChangeTimeMs;          /* ms stamp of that request; fn_8020A100 ramps the crossfade from it */

#pragma scheduling invalid_target
/* Requests a song change. When the index differs from the one already pending,
 * log it, make it the pending index (-1 stops the music) and stamp the moment of
 * the switch; fn_8020A100 crossfades the two music slots over the time elapsed
 * since that stamp. */
/* Request a song change: if the new index differs from the pending one, log it, set the pending song index (-1 stops music), and stamp the change time for the crossfade. */ void musicRequestSong(s32 songIdx) {
    if (songIdx != gRequestedSongIdx) {
        fn_802E30C8(gSetSongIdxFmt, songIdx);
        gRequestedSongIdx = songIdx;
        gSongChangeTimeMs = fn_802E2C20();
    }
}
#pragma scheduling on
s32 fn_80127D58(void*);
s32 fn_8012E498(void*);
void fn_80207924();
int sprintf(char*, const char*, ...);
void fn_8020A100(void);
extern void fn_8012E81C(void*);
extern void *fn_802078CC(char*, s32, s32, s32);
extern s32 fn_8012E938(char*);
extern char lbl_8055B570;
extern char lbl_8055B574;
extern const char lbl_8033C2A8[];
extern const char lbl_8033C2B4[];
extern f32 lbl_80563294;
extern f32 lbl_80563298;
extern f32 lbl_8056329C;
extern f32 lbl_805632A0;
extern f32 lbl_80563290;
extern u8 lbl_8055EDD0;
extern s8 lbl_8055EDD4;
extern s32 lbl_804892C0[];
extern s32 lbl_8055B560;
extern char lbl_8055B568;

/* Music shutdown: unregister the crossfade callback, release both music slots, reload their audio paths and clear slot flags. */ void fn_8020A550(void) {
    /* Unregister the music callback, release two music slots, reload their paths, and clear related flags. */
    char pathBuffer[64];
    s32 zero;
    s32 *slot;
    s32 *name;
    s8 *flag;
    s32 i;

    fn_80127D58(fn_8020A100);
    zero = 0;
    lbl_8055EDD0 = zero;
    slot = lbl_804892C0;
    i = 0;
    name = &lbl_8055B560;
    flag = &lbl_8055EDD4;
    do {
        if (*slot != 0) {
            fn_80207924((void *)*slot);
            *slot = zero;
        }
        sprintf(pathBuffer, (char *)&lbl_8055B568, *name);
        fn_8012E498(pathBuffer);
        i += 1;
        *flag = zero;
        slot = (s32 *)((s32)slot + 8);
        name = (s32 *)((s32)name + 4);
        flag = (s8 *)((s32)flag + 1);
    } while (i < 2);
}

/* Return the global music playback volume (the "Music" setting), set by fn_8020A5F8 and used as the level music plays at. */
f32 fn_8020A5F0(void) {
    return lbl_8055EDD8;
}

s32 fn_80128670(s32);               /* free an allocation made by fn_8012850C */
s32 fn_801336E0(s32, void*);        /* unregister callback arg1 under handle arg0 */
void fn_8020A634(void);             /* clear the "music: play!" flag */
void fn_80209FFC(void);             /* "Music" volume callback */
extern s32 lbl_8055B550;            /* handle of the volume callback, -1 when none */

/* One of the two music channels of lbl_804892C0: the Sound object playing
 * from buffer, a 0x70-byte allocation tagged "mus_buf". */
typedef struct MusicSlot {
    s32 sound;   /* +0x00 Sound object, 0 while nothing is loaded */
    s32 buffer;  /* +0x04 stream buffer the sound plays from */
} MusicSlot;

extern char lbl_8055B578;
extern char lbl_8055B580;
extern const char lbl_8033C278[];
extern f32 lbl_80563290;
s32 fn_8012850C(s32, void*);
s32 fn_8013323C(s32, void*, f32);
s32 fn_8013365C(void*, void*);
s32 fn_8000DBC8(void*);
extern void fn_8020A03C(s32, s32);
extern void fn_801331C4(int, void *, f32 *);
#pragma dont_inline on
void fn_80209FFC(void) {
    f32 volume;

    /* Load the saved "music_volume" setting (current volume as default) and apply it. */
    volume = fn_8020A5F0();
    fn_801331C4(4, (void *)lbl_8033C278, &volume);
    fn_8020A5F8(volume);
}

#pragma push
#pragma processor 750
#pragma opt_propagation off
#pragma scheduling on
void fn_8020A100(void) {
    char buf[0x40];
    s32 *slot;
    u8 *flag;
    s32 *name;
    s32 i;
    s32 diff;
    u8 *obj;
    f32 one;
    f32 scale;
    f32 t;
    s32 zero;
    if (lbl_8055EDD0 != 0) {
        scale = lbl_80563294;
        diff = fn_802E2C20() - gSongChangeTimeMs;
        if ((s32)lbl_8055EDE0 != gRequestedSongIdx) {
            if (diff >= 0x190 || diff < 0 || (s32)lbl_8055EDE0 == -1) {
                lbl_8055EDE0 = (void *)(s32)*(volatile s32 *)&gRequestedSongIdx;
            } else {
                t = lbl_80563294 < ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290 ? lbl_80563294 : ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290;
                t = t > lbl_8056329C ? t : lbl_8056329C;
                scale = lbl_80563294 + t * lbl_805632A0;
            }
        }
        one = lbl_8056329C;
        slot = lbl_804892C0;
        i = 0;
        flag = (u8 *)&lbl_8055EDD4;
        name = &lbl_8055B560;
        zero = 0;
        do {
            if (*flag == 0) {
                sprintf(buf, &lbl_8055B568, *name);
                if (fn_8012E938(buf) != 0) {
                    fn_8012E81C(buf);
                    sprintf(buf, lbl_8033C2A8, *name, zero == 1 ? &lbl_8055B570 : &lbl_8055B574);
                    slot[0] = (s32)fn_802078CC(buf, 0, slot[1], 0x70);
                    fn_802E30C8(lbl_8033C2B4, i, 0, buf, slot[0]);
                    *flag = 1;
                }
            }
            obj = (u8 *)slot[0];
            if (obj != 0) {
                f32 v = lbl_8055EDD8 * scale;
                if (v != *(f32 *)(obj + 8)) {
                    obj[0x4D] = 1;
                    *(f32 *)(obj + 8) = v;
                }
                if (one != *(f32 *)(obj + 0x64)) {
                    obj[0x6C] = 1;
                    *(f32 *)(obj + 0x64) = one;
                }
                if (one != *(f32 *)(obj + 0x68)) {
                    obj[0x6D] = 1;
                    *(f32 *)(obj + 0x68) = one;
                }
                if (i == (s32)lbl_8055EDE0 && (u8)lbl_8055EDDC != 0) {
                    obj[0x4A] = 0;
                    obj[0x4B] = 1;
                    obj[0x49] = 1;
                } else {
                    obj[0x4A] = 1;
                    obj[0x4C] = 0;
                }
            }
            i++;
            slot += 2;
            flag++;
            name++;
        } while (i < 2);
    }
}
#pragma pop
void fn_8020A368(void) {
    /* Initialize the music system: allocate the two "mus_buf" stream buffers,
       clear the play flag and set the default 0.7 music volume, register the
       "music_volume" setting and the "Music" volume callback, then hook the
       music volume event handler. */
#define MUSIC_SLOTS      lbl_804892C0  /* two channels: {sound, buffer} */
#define MUS_BUF_TAG      lbl_8055B578  /* "mus_buf" */
#define DEFAULT_VOLUME   lbl_80563290  /* 0.7f */
#define PLAY_FLAG        lbl_8055EDDC
#define MUSIC_VOLUME     lbl_8055EDD8
#define VOLUME_KEY       lbl_8033C278  /* "music_volume" */
#define MUSIC_CB_NAME    lbl_8055B580  /* "Music" */
#define MUSIC_CB_HANDLE  lbl_8055B550
    s32 *musicSlot;
    s32 slotIndex;
    f32 defaultVolume;
    void *volumeCallback;
    musicSlot = MUSIC_SLOTS;
    slotIndex = 0;
    do {
        musicSlot[1] = fn_8012850C(0x70, (void *)&MUS_BUF_TAG);
        slotIndex += 1;
        musicSlot = (s32 *)((s32)musicSlot + 8);
    } while (slotIndex < 2);
    defaultVolume = DEFAULT_VOLUME;
    PLAY_FLAG = 0;
    MUSIC_VOLUME = defaultVolume;
    fn_8013323C(4, (void *)VOLUME_KEY, defaultVolume);
    volumeCallback = (void *)fn_80209FFC;
    MUSIC_CB_HANDLE = fn_8013365C((void *)&MUSIC_CB_NAME, volumeCallback);
    fn_8000DBC8((void *)fn_8020A03C);
#undef MUSIC_CB_HANDLE
#undef MUSIC_CB_NAME
#undef VOLUME_KEY
#undef MUSIC_VOLUME
#undef PLAY_FLAG
#undef DEFAULT_VOLUME
#undef MUS_BUF_TAG
#undef MUSIC_SLOTS
}

/* Shut the music system down: clear the "music: play!" flag, unregister the
 * "Music" volume callback and free both "mus_buf" stream buffers, leaving the
 * slots empty for fn_8020A368 to fill again. */
void fn_8020A400(void) {
#define MUSIC_CB_HANDLE  lbl_8055B550
#define MUSIC_SLOTS      lbl_804892C0
    MusicSlot* musicSlot;
    s32 slotIndex;

    fn_8020A634();
    fn_801336E0(MUSIC_CB_HANDLE, fn_80209FFC);
    MUSIC_CB_HANDLE = -1;
    musicSlot = (MusicSlot*)MUSIC_SLOTS;
    slotIndex = 0;
    do {
        fn_80128670(musicSlot->buffer);
        slotIndex += 1;
        musicSlot->buffer = 0;
        musicSlot = (MusicSlot*)((s32)musicSlot + 8);
    } while (slotIndex < 2);
#undef MUSIC_SLOTS
#undef MUSIC_CB_HANDLE
}

extern int sprintf(char*, const char*, ...);
extern void fn_8012DDA8(void*);
extern void fn_8012E81C(void*);
extern void fn_80127C90(void*, const char*);
extern const char lbl_8033C2DC[];
extern const char lbl_8033C2F0[];
extern const char lbl_8055B588;
/* Begin UI music playback: reset the active-track and song-request state, preload both .sng tracks, register the crossfade callback under the "music" name, then start the first track. */ void fn_8020A47C(void) {
    /* Initialize UI music playback: reset state, preload two song tracks, register the music callback, and start the first track. */
    struct {
        char songNameBuf[8];
        char pad[0x38];
        char songPathBuf[0x38];
    } local;
    s32 *trackIdPtr;
    s8 *loadedFlagPtr;
    s32 trackIdx;
    s32 zero;

    fn_802E30C8(lbl_8033C2DC);
    zero = 0;
    lbl_8055EDE0 = (void *)zero;
    trackIdx = zero;
    lbl_8055EDD0 = 1;
    trackIdPtr = &lbl_8055B560;
    loadedFlagPtr = &lbl_8055EDD4;
    gRequestedSongIdx = zero;
    gSongChangeTimeMs = zero;
    do {
        sprintf(local.songPathBuf, &lbl_8055B568, *trackIdPtr);
        *loadedFlagPtr = zero;
        fn_802E30C8(lbl_8033C2F0, local.songPathBuf);
        fn_8012DDA8(local.songPathBuf);
        trackIdx += 1;
        trackIdPtr++;
        loadedFlagPtr++;
    } while (trackIdx < 2);
    fn_80127C90(fn_8020A100, &lbl_8055B588);
    sprintf(local.songNameBuf, &lbl_8055B568, lbl_8055B560);
    fn_8012E81C(local.songNameBuf);
}


extern const char lbl_8033C288[];
/* Music event 3 exports the local volume, 1/2 import it, and 0 applies default. */
#pragma cplusplus on
/* Handles music volume events by syncing the global and per-player music volume settings. */
extern "C" void fn_8020A03C(s32 musicObj, s32 event) {
#define CONFIG_KEY_MUSIC_VOLUME     lbl_8033C278
#define CONFIG_KEY_PLAYER_MUSIC_VOL lbl_8033C288
#define OPTIONS_SECTION_SOUND       4
    f32 volume = 0.7f;
    switch (event) {
    case 3:
        fn_801331C4(musicObj + 0xC, (void *)CONFIG_KEY_PLAYER_MUSIC_VOL, &volume);
        fn_8013323C(OPTIONS_SECTION_SOUND, (void *)CONFIG_KEY_MUSIC_VOLUME, volume);
        fn_8020A5F8(volume);
        break;
    case 1:
    case 2:
        fn_801331C4(OPTIONS_SECTION_SOUND, (void *)CONFIG_KEY_MUSIC_VOLUME, &volume);
        fn_8013323C(musicObj + 0xC, (void *)CONFIG_KEY_PLAYER_MUSIC_VOL, volume);
        break;
    case 0:
        fn_8013323C(OPTIONS_SECTION_SOUND, (void *)CONFIG_KEY_MUSIC_VOLUME, volume);
        fn_8020A5F8(volume);
        break;
    }
#undef CONFIG_KEY_MUSIC_VOLUME
#undef CONFIG_KEY_PLAYER_MUSIC_VOL
#undef OPTIONS_SECTION_SOUND
}
#pragma cplusplus reset

#pragma cplusplus reset
