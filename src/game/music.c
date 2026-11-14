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
    lbl_8055EDDC = 0;
}
#pragma dont_inline off

char fn_8020A640(void) {
    return lbl_8055EDDC;
}

extern void *lbl_8055EDE0;
void* fn_8020A69C(void) {
    return lbl_8055EDE0;
}

#include "types.h"

extern f32 lbl_8055EDD8;
void fn_8020A5F8(f32 arg0) {
    lbl_8055EDD8 = arg0;
}

#pragma scheduling invalid_target
void fn_8020A600(void) {
    fn_802E30C8(lbl_8033C308);
    lbl_8055EDDC = 1;
}
#pragma scheduling on

s32 fn_802E2C20(void);
extern const char lbl_8033C318[];
extern s32 lbl_8055EDE4;
extern s32 lbl_8055EDE8;

#pragma scheduling invalid_target
void fn_8020A648(s32 arg0) {
    if (arg0 != lbl_8055EDE4) {
        fn_802E30C8(lbl_8033C318, arg0);
        lbl_8055EDE4 = arg0;
        lbl_8055EDE8 = fn_802E2C20();
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

void fn_8020A550(void) {
    /* Unregister the music callback, release two music slots, reload their paths, and clear related flags. */
    char pathBuffer[64];
    s32 zeroValue;
    s32 *slotPtr;
    s32 *namePtr;
    s8 *flagPtr;
    s32 index;

    fn_80127D58(fn_8020A100);
    zeroValue = 0;
    lbl_8055EDD0 = zeroValue;
    slotPtr = lbl_804892C0;
    index = 0;
    namePtr = &lbl_8055B560;
    flagPtr = &lbl_8055EDD4;
    do {
        if (*slotPtr != 0) {
            fn_80207924((void *)*slotPtr);
            *slotPtr = zeroValue;
        }
        sprintf(pathBuffer, (char *)&lbl_8055B568, *namePtr);
        fn_8012E498(pathBuffer);
        index += 1;
        *flagPtr = zeroValue;
        slotPtr = (s32 *)((s32)slotPtr + 8);
        namePtr = (s32 *)((s32)namePtr + 4);
        flagPtr = (s8 *)((s32)flagPtr + 1);
    } while (index < 2);
}

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
    f32 value;

    value = fn_8020A5F0();
    fn_801331C4(4, (void *)lbl_8033C278, &value);
    fn_8020A5F8(value);
}

#pragma push
#pragma processor 750
#pragma opt_propagation off
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
        diff = fn_802E2C20() - lbl_8055EDE8;
        if ((s32)lbl_8055EDE0 != lbl_8055EDE4) {
            if (diff >= 0x190 || diff < 0 || (s32)lbl_8055EDE0 == -1) {
                lbl_8055EDE0 = (void *)(s32)*(volatile s32 *)&lbl_8055EDE4;
            } else {
                t = lbl_80563294 < ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290 ? lbl_80563294 : ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290;
                t = t > lbl_8056329C ? t : lbl_8056329C;
                scale = lbl_80563294 + t * lbl_805632A0;
            }
        }
        slot = lbl_804892C0;
        one = lbl_8056329C;
        i = 0;
        flag = (u8 *)&lbl_8055EDD4;
        name = &lbl_8055B560;
        zero = 0;
        do {
            if (*flag == 0) {
                sprintf(buf, &lbl_8055B568, *name);
                if (fn_8012E938(buf) != 0) {
                    fn_8012E81C(buf);
                    sprintf(buf, lbl_8033C2A8, *name, 1 == zero ? &lbl_8055B570 : &lbl_8055B574);
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
#pragma opt_propagation reset
#pragma pop
void fn_8020A368(void) {
    /* Initialize two music buffer slots, reset music volume state, register the music manager, and set the music update callback. */
    s32 *musicSlot;
    s32 slotIndex;
    f32 defaultVolume;
    void *volumeCallback;
    musicSlot = lbl_804892C0;
    slotIndex = 0;
    do {
        musicSlot[1] = fn_8012850C(0x70, (void *)&lbl_8055B578);
        slotIndex += 1;
        musicSlot = (s32 *)((s32)musicSlot + 8);
    } while (slotIndex < 2);
    defaultVolume = lbl_80563290;
    lbl_8055EDDC = 0;
    lbl_8055EDD8 = defaultVolume;
    fn_8013323C(4, (void *)lbl_8033C278, defaultVolume);
    volumeCallback = (void *)fn_80209FFC;
    lbl_8055B550 = fn_8013365C((void *)&lbl_8055B580, volumeCallback);
    fn_8000DBC8((void *)fn_8020A03C);
}

/* Shut the music system down: clear the "music: play!" flag, unregister the
 * "Music" volume callback and free both "mus_buf" stream buffers, leaving the
 * slots empty for fn_8020A368 to fill again. */
void fn_8020A400(void) {
    MusicSlot* musicSlot;
    s32 slotIndex;

    fn_8020A634();
    fn_801336E0(lbl_8055B550, fn_80209FFC);
    lbl_8055B550 = -1;
    musicSlot = (MusicSlot*)lbl_804892C0;
    slotIndex = 0;
    do {
        fn_80128670(musicSlot->buffer);
        slotIndex += 1;
        musicSlot->buffer = 0;
        musicSlot = (MusicSlot*)((s32)musicSlot + 8);
    } while (slotIndex < 2);
}

extern int sprintf(char*, const char*, ...);
extern void fn_8012DDA8(void*);
extern void fn_8012E81C(void*);
extern void fn_80127C90(void*, const char*);
extern const char lbl_8033C2DC[];
extern const char lbl_8033C2F0[];
extern const char lbl_8055B588;
void fn_8020A47C(void) {
    /* Initialize UI music playback: reset state, preload two song tracks, register the music callback, and start the first track. */
    struct {
        char songNameBuf[8];
        char pad[0x38];
        char songPathBuf[0x38];
    } local;
    s32 *trackId;
    s8 *loadedFlag;
    s32 i;
    s32 zero;

    fn_802E30C8(lbl_8033C2DC);
    zero = 0;
    lbl_8055EDE0 = (void *)zero;
    i = zero;
    lbl_8055EDD0 = 1;
    trackId = &lbl_8055B560;
    loadedFlag = &lbl_8055EDD4;
    lbl_8055EDE4 = zero;
    lbl_8055EDE8 = zero;
    do {
        sprintf(local.songPathBuf, &lbl_8055B568, *trackId);
        *loadedFlag = zero;
        fn_802E30C8(lbl_8033C2F0, local.songPathBuf);
        fn_8012DDA8(local.songPathBuf);
        i += 1;
        trackId++;
        loadedFlag++;
    } while (i < 2);
    fn_80127C90(fn_8020A100, &lbl_8055B588);
    sprintf(local.songNameBuf, &lbl_8055B568, lbl_8055B560);
    fn_8012E81C(local.songNameBuf);
}


extern const char lbl_8033C288[];
/* Music event 3 exports the local volume, 1/2 import it, and 0 applies default. */
#pragma cplusplus on
extern "C" void fn_8020A03C(s32 object, s32 event) {
    register f32 volume = lbl_80563290;
    switch (event) {
    case 3:
        fn_801331C4(object + 0xC, (void *)lbl_8033C288, &volume);
        fn_8013323C(4, (void *)lbl_8033C278, volume);
        fn_8020A5F8(volume);
        break;
    case 1:
    case 2:
        fn_801331C4(4, (void *)lbl_8033C278, &volume);
        fn_8013323C(object + 0xC, (void *)lbl_8033C288, volume);
        break;
    case 0:
        fn_8013323C(4, (void *)lbl_8033C278, volume);
        fn_8020A5F8(volume);
        break;
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
