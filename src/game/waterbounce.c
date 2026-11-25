// waterbounce — water bounce sfx ("waterbounce.sfx").
// Recovered TU window 0x8020DE74..0x8020F3AC+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020F3AC (+ .ctors slot 0x802ED3A4) remains in
// auto/text_8020F3AC_.c pending a promotion pass.
#include "types.h"

// One truck's sound effects. fn_8020DE74() creates the sounds named below --
// fn_802077A4() makes the 3D ones, fn_802076A0() the dashboard ones -- and
// its destructor releases them again. The race-only sounds stay null in
// the other modes.
typedef struct CarSound {
    void *vtable;         // at 0x0, this class's vtable, lbl_8033C8C4:
                          // +0x8 destructor CarSound_destroy, +0xC per-frame update
                          // fn_8020E598, then one handler per sound -- +0x10..+0x30
                          // and +0x30 re-arm or set the volume of a sound, +0x34
                          // fn_8020F39C is empty and +0x38 CarSound_RequestInvulnerable raises flag72
    void *owner;          // at 0x4, the object this sound set was made for
    void *backfire;       // at 0x8, "backfire.sfx"
    void *lastBoost;      // at 0xC, the boost sound created last
    void *boosts[2];      // at 0x10, "boost1.sfx" and "boost2.sfx"
    void *boostManual;    // at 0x18, "boost_manual.sfx"
    void *carGnd1;        // at 0x1C, "car_gnd1.sfx"
    void *badland;        // at 0x20, "badland.sfx"
    void *niceLand;       // at 0x24, "niceland.sfx"
    void *waterBounce;    // at 0x28, "waterbounce.sfx"
    void *boostTurboTap;  // at 0x2C, "boost_turbotap.sfx"
    void *airtime;        // at 0x30, "airtime.sfx"
    void *waterDrive;     // at 0x34, "waterdrive.sfx"
    void *waterIn;        // at 0x38, "water_in.sfx"
    void *waterOut;       // at 0x3C, "water_out.sfx"
    void *dirtSkid;       // at 0x40, "dirtskid.sfx"
    void *waterSink;      // at 0x44, "watersink.sfx"
    void *heatBeep;       // at 0x48, "heatbeep.sfx"
    void *overheat;       // at 0x4C, "overheat.sfx"
    void *overheatStart;  // at 0x50, "overheat_start.sfx"
    void *invulnerable;   // at 0x54, "invulnerable.sfx"
    u8 flags58;
    u8 pad59[3];
    u32 boostCount;       // at 0x5C, how many of boosts[] were created
    float value60;
    float value64;
    float value68;
    float value6c;
    u8 flag70;
    u8 flag71;
    u8 flag72;
    u8 pad73;
} CarSound;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80563368;
extern float lbl_80563370;
extern float lbl_805633DC;
extern float lbl_805633F4;
extern float lbl_805633F8;
extern float lbl_805633FC;

#pragma scheduling invalid_target
#pragma cplusplus on
// A sound the car owns: fn_802077A4() makes the "Sound3D" ones and
// fn_802076A0() the "SoundDash" ones. Their first virtual -- the destructor
// slot of the vtable -- tears the sound down, and a flag of one frees it.
struct Sound {
    virtual void release(s32 deleteSound);
    virtual void v1();
    virtual void v2();
};
extern void *lbl_8033C8C4[];
extern "C" void fn_80128668(void *);
extern "C" void *fn_801284F8(int, const char *);
extern "C" void *fn_802077A4(const char *, int, void *, void *);
extern "C" void *fn_802076A0(const char *, int, void *, int);
extern "C" int fn_801345D8(char *, int, const char *, ...);
extern "C" void *fn_80016544(s32);
extern "C" void *memset(void *, int, unsigned int);
extern const char lbl_8033C7A0[];
extern const char lbl_8055B648;
extern float lbl_8056336C;
extern "C" void *fn_8020DE74(void *arg0);
#pragma push
#pragma processor 750
#pragma cplusplus reset
#pragma use_lmw_stmw off
#pragma optimize_for_size on
void *fn_8020DE74(void *arg0) {
    char name[0x20];
    register const char *labels __asm("r31") = lbl_8033C7A0;
    register CarSound *obj __asm("r30");
    register void *right __asm("r29");
    register s32 is_race __asm("r28");
    register void *left __asm("r27");
    register void *group __asm("r26");
    register u32 one __asm("r24") = 1;
    register u32 i __asm("r23");
    register u32 offset __asm("r22");
    register void **slot __asm("r21");
    void *child;
    register float initial asm("f31");
    u32 bit;

    obj = (CarSound *)fn_801284F8(0x74, (const char *)&lbl_8055B648);
    if (obj != 0) {
    obj->vtable = lbl_8033C8C4;
    obj->owner = arg0;
    left = (u8 *)arg0 + 0x118;
    right = (u8 *)arg0 + 0x60;
    group = *(void **)((u8 *)arg0 + 0x1ec);
    is_race = *(u32 *)((u8 *)arg0 + 0x10) == 0x50434152;

    if (is_race != 0) {
        obj->waterBounce = fn_802077A4(labels, 5, left, right);
        obj->airtime = fn_802077A4(labels + 0x10, 8, left, right);
    } else {
        obj->waterBounce = 0;
        obj->airtime = 0;
    }
    obj->backfire = fn_802077A4(labels + 0x1c, 5, left, right);
    obj->boostCount = 0;
    memset(obj->boosts, 0, 8);
    obj->lastBoost = 0;

    i = 0;
    initial = lbl_80563368;
    offset = 0;
    do {
        fn_801345D8(name, 0x20, labels + 0x2c, i + 1);
        slot = (void **)((u8 *)obj + offset);
        child = fn_802077A4(name, 5, left, right);
        slot[4] = child;
        if (child == 0) break;
        *(void **)((u8 *)child + 0x10) = group;
        child = slot[4];
        if (initial != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = one;
            *(float *)((u8 *)child + 4) = initial;
        }
        i++;
        obj->lastBoost = slot[4];
        offset += 4;
        obj->boostCount += 1;
    } while (i < 2);

    if (is_race != 0) obj->boostManual = fn_802077A4(labels + 0x38, 5, left, right);
    else obj->boostManual = 0;
    child = *(void * volatile *)((u8 *)obj + 8);
    if (child != 0) {
        *(void **)((u8 *)child + 0x10) = group;
        {
            float desired = lbl_8056336C;
            child = *(void * volatile *)((u8 *)obj + 8);
            if (desired != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = 1;
            *(float *)((u8 *)child + 4) = desired;
            }
        }
    }
    child = obj->waterBounce;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->airtime;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) obj->carGnd1 = fn_802077A4(labels + 0x4c, 5, left, right);
    else obj->carGnd1 = 0;
    obj->badland = fn_802077A4(labels + 0x5c, 5, left, right);
    obj->waterDrive = fn_802077A4(labels + 0x68, 5, left, right);
    if (is_race != 0) {
        obj->waterIn = fn_802077A4(labels + 0x78, 5, left, right);
        obj->waterOut = fn_802077A4(labels + 0x88, 5, left, right);
    } else {
        obj->waterIn = 0;
        obj->waterOut = 0;
    }
    child = obj->waterDrive;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->waterIn;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->waterOut;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = fn_802077A4(labels + 0x98, 5, left, right);
    obj->dirtSkid = child;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) {
        obj->niceLand = fn_802077A4(labels + 0xa8, 5, left, right);
        obj->boostTurboTap = fn_802077A4(labels + 0xb8, 5, left, right);
        obj->heatBeep = fn_802076A0(labels + 0xcc, 1, group, 2);
        obj->overheat = fn_802076A0(labels + 0xdc, 1, group, 2);
        obj->overheatStart = fn_802076A0(labels + 0xec, 1, group, 2);
        obj->waterSink = fn_802076A0(labels + 0x100, 1, group, 0);
        obj->invulnerable = fn_802076A0(labels + 0x110, 1, group, 0);
    } else {
        obj->niceLand = 0;
        obj->boostTurboTap = 0;
        obj->heatBeep = 0;
        obj->overheat = 0;
        obj->overheatStart = 0;
        obj->waterSink = 0;
        obj->invulnerable = 0;
    }
    {
        float reset = lbl_80563370;
        obj->value60 = reset;
        obj->flag70 = 0;
        obj->value64 = reset;
        obj->value68 = reset;
        obj->value6c = reset;
    }
    obj->flags58 = 0;
    obj->flag72 = 0;
    child = fn_80016544(*(s32 *)((u8 *)arg0 + 0x25c));
    bit = (*(u32 *)((u8 *)child + 0xa0) >> 2) & 1;
    obj->flag71 = bit;
    }
    return obj;
}
#pragma pop
// The "carsnd" object's deleting destructor: releases every sound
// fn_8020DE74() created for the truck and, when deleteMemory is positive,
// frees the object itself. The vtable goes back first, so a sound torn down
// from here sees the object as dead.
/* Deleting destructor: install the vtable, release all sounds created by fn_8020DE74, then free the object when deleteMemory > 0. */ extern "C" void *CarSound_destroy(CarSound *snd, s32 deleteFlag) {
    void *sound;
    u8 *boostSlot;
    u32 i;
    if (snd != 0) {
        sound = snd->backfire;
        snd->vtable = lbl_8033C8C4;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        boostSlot = (u8 *)snd;
        i = 0;
        do {                        // the two boost sounds
            sound = *(void **)(boostSlot + 0x10);
            if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
            boostSlot += 4;
            i++;
        } while (i < 2);
        sound = snd->boostManual;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->waterBounce;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->airtime;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->carGnd1;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->badland;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->niceLand;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->boostTurboTap;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->heatBeep;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->overheat;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->overheatStart;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->waterSink;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->waterDrive;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->waterIn;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->waterOut;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->dirtSkid;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        sound = snd->invulnerable;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        if (deleteFlag > 0) fn_80128668(snd);
    }
    return snd;
}

extern float lbl_80558DC4;
extern float lbl_8055E3C8;
extern float lbl_80563374;
extern float lbl_80563378;
extern float lbl_8056337C;
extern float lbl_80563380;
extern float lbl_80563384;
extern float lbl_80563388;
extern float lbl_8056338C;
extern float lbl_80563390;
extern float lbl_80563394;
extern float lbl_80563398;
extern float lbl_8056339C;
extern float lbl_805633A0;
extern float lbl_805633A4;
extern float lbl_805633A8;
extern float lbl_805633AC;
extern float lbl_805633B0;
extern float lbl_805633B4;
extern float lbl_805633B8;
extern float lbl_805633BC;
extern float lbl_805633C0;
extern float lbl_805633C4;
extern float lbl_805633C8;
extern float lbl_805633CC;
extern float lbl_805633D0;
extern float lbl_805633D4;
extern float lbl_805633D8;
extern float lbl_805633E0;
extern float lbl_805633E4;
extern float lbl_805633E8;
extern float lbl_805633EC;
extern float lbl_805633F0;
extern int fn_80129D18(int);
extern float QueryGroundHeightAtXZ(void *, float, float);
extern int fn_80178CA4(void);
extern int fn_801796C4(void);
extern int hasSelectedTrackMusicSong(void);
extern int hasNoSelectedTrackMusicSong(void);
extern void fn_8020C910(float);
extern int fn_802BF4F0(void);
extern float fn_802BF590(float, float);
extern float PSVECMag(void *);
extern float PSVECDotProduct(void *, void *);
extern double fabs(double);
#pragma push
#pragma small_data off
extern "C" float lbl_80558DC4;
#pragma pop
extern "C" float lbl_8055E3C8;
extern "C" float lbl_80563368;
extern "C" float lbl_80563370;
extern "C" float lbl_80563374;
extern "C" float lbl_80563378;
extern "C" float lbl_8056337C;
extern "C" float lbl_80563380;
extern "C" float lbl_80563384;
extern "C" float lbl_80563388;
extern "C" float lbl_8056338C;
extern "C" float lbl_80563390;
extern "C" float lbl_80563394;
extern "C" float lbl_80563398;
extern "C" float lbl_8056339C;
extern "C" float lbl_805633A0;
extern "C" float lbl_805633A4;
extern "C" float lbl_805633A8;
extern "C" float lbl_805633AC;
extern "C" float lbl_805633B0;
extern "C" float lbl_805633B4;
extern "C" float lbl_805633B8;
extern "C" float lbl_805633BC;
extern "C" float lbl_805633C0;
extern "C" float lbl_805633C4;
extern "C" float lbl_805633C8;
extern "C" float lbl_805633CC;
extern "C" float lbl_805633D0;
extern "C" float lbl_805633D4;
extern "C" float lbl_805633D8;
extern "C" float lbl_805633DC;
extern "C" float lbl_805633E0;
extern "C" float lbl_805633E4;
extern "C" float lbl_805633E8;
extern "C" float lbl_805633EC;
extern "C" float lbl_805633F0;
extern "C" int fn_80129D18(int);
extern "C" float QueryGroundHeightAtXZ(void *, float, float);
extern "C" int fn_80178CA4(void);
extern "C" int fn_801796C4(void);
extern "C" int hasSelectedTrackMusicSong(void);
extern "C" int hasNoSelectedTrackMusicSong(void);
extern "C" void fn_8020C910(float);
extern "C" int fn_802BF4F0(void);
extern "C" float fn_802BF590(float, float);
extern "C" float PSVECMag(void *);
extern "C" float PSVECDotProduct(void *, void *);
extern "C" double fabs(double);
#pragma processor 750
extern "C" void fn_8020E598(void *arg0) {
char *__repair_addr;

    void *truck;
    void *s54;
    void *s48;
    void *s0c;
    void *s18;
    void *s30;
    void *s4c;
    void *s34;
    void *s38;
    void *s3c;
    void *s40;
    float f31;
    float f30;
    float v;
    float t;
    float t2;
    float nvx, nvy, nvz, mag, inv;
    float outx, outy, outz;
    int eq;
    int r28flag;
    int want;
    int i;
    char *p;
    truck = *(void **)((char *)arg0 + 4);
    s54 = *(void **)((char *)arg0 + 0x54);
    if (s54 != 0) {
        int isSet = 0;
        if (*(unsigned char *)((char *)arg0 + 0x71) == 0 && *(unsigned char *)((char *)arg0 + 0x72) != 0)
            isSet = 1;
        if (isSet != 0) {
            if (*(unsigned char *)((char *)arg0 + 0x58) != 0) {
                *(unsigned char *)((char *)s54 + 0x4A) = 1;
                *(unsigned char *)((char *)s54 + 0x4C) = 0;
                *(unsigned char *)((char *)arg0 + 0x58) = 0;
            } else {
                *(unsigned char *)((char *)s54 + 0x49) = 1;
                *(unsigned char *)((char *)s54 + 0x4B) = 0;
                *(unsigned char *)((char *)s54 + 0x4A) = 0;
                *(unsigned char *)((char *)arg0 + 0x58) = 1;
                *(unsigned char *)((char *)arg0 + 0x72) = 0;
            }
        } else {
            int eq0 = (*(float *)((char *)truck + 0x25BC) > lbl_80558DC4);
            if (eq0 == 0) {
                s54 = *(void **)((char *)arg0 + 0x54);
                *(unsigned char *)((char *)arg0 + 0x58) = 0;
                *(unsigned char *)((char *)s54 + 0x4A) = 1;
                *(unsigned char *)((char *)s54 + 0x4C) = 0;
            }
        }
    }
    s48 = *(void **)((char *)arg0 + 0x48);
    if (s48 != 0) {
        float base;
        if (*(unsigned char *)((char *)truck + 0x259C) == 0)
            base = lbl_80563374;
        else
            base = lbl_80563378;
        v = lbl_80563368;
__repair_addr = (char *)((char *)truck + 0x25A0);

        t = (*(float *)(__repair_addr) - base) / ((lbl_8056337C + base) - base);
        v = (v < t) ? v : t;
        v = (v > lbl_80563370) ? v : lbl_80563370;
        t2 = lbl_80563380;
        t = (lbl_80563370 + (v * lbl_80563368)) - *(float *)((char *)arg0 + 0x6C);
        t2 = (t2 < t) ? t2 : t;
        t2 = (t2 > lbl_80563384) ? t2 : lbl_80563384;
        t = *(float *)((char *)arg0 + 0x6C) + t2;
        *(float *)((char *)arg0 + 0x6C) = t;
        if (t > lbl_80563388) {
            if (t != *(float *)((char *)s48 + 8)) {
                *(unsigned char *)((char *)s48 + 0x4D) = 1;
                *(float *)((char *)s48 + 8) = t;
            }
            s48 = *(void **)((char *)arg0 + 0x48);
            *(unsigned char *)((char *)s48 + 0x4A) = 0;
            *(unsigned char *)((char *)s48 + 0x4B) = 1;
            *(unsigned char *)((char *)s48 + 0x49) = 1;
        } else {
            s48 = *(void **)((char *)arg0 + 0x48);
            *(unsigned char *)((char *)s48 + 0x4A) = 1;
            *(unsigned char *)((char *)s48 + 0x4C) = 0;
        }
    }
    s0c = *(void **)((char *)arg0 + 0x0C);
    if (s0c != 0) {
        eq = (*(float *)((char *)truck + 0x258C) == lbl_8056338C);
        if (eq != 0) {
            *(float *)((char *)arg0 + 0x64) = lbl_80563368;
        } else {
            v = lbl_80563370;
            t = *(float *)((char *)arg0 + 0x64) - lbl_80563390;
            v = (v > t) ? v : t;
            *(float *)((char *)arg0 + 0x64) = v;
        }
        if ((eq != 0) || (*(float *)((char *)arg0 + 0x64) > lbl_8056338C)) {
            if (*(unsigned char *)((char *)s0c + 0x19) == 0) {
                char *rr = (char *)arg0;
                int jj = 0;
                void *tt;
                while (jj < *(int *)((char *)arg0 + 0x5C)) {
                    tt = *(void **)(rr + 0x10);
                    rr += 4;
                    jj++;
                    *(unsigned char *)((char *)tt + 0x4A) = 1;
                    *(unsigned char *)((char *)tt + 0x4C) = 0;
                }
                *(void **)((char *)arg0 + 0x0C) = *(void **)((char *)arg0 + (fn_80129D18(6) * 4) + 0x10);
            }
            s0c = *(void **)((char *)arg0 + 0x0C);
            t = *(float *)((char *)arg0 + 0x64);
            if (t != *(float *)((char *)s0c + 8)) {
                *(unsigned char *)((char *)s0c + 0x4D) = 1;
                *(float *)((char *)s0c + 8) = t;
            }
            if (lbl_80563368 != *(float *)((char *)s0c + 4)) {
                *(unsigned char *)((char *)s0c + 0x4E) = 1;
                *(float *)((char *)s0c + 4) = lbl_80563368;
            }
            s0c = *(void **)((char *)arg0 + 0x0C);
            *(unsigned char *)((char *)s0c + 0x4A) = 0;
            *(unsigned char *)((char *)s0c + 0x4B) = 1;
            *(unsigned char *)((char *)s0c + 0x49) = 1;
        } else {
            s0c = *(void **)((char *)arg0 + 0x0C);
            *(unsigned char *)((char *)s0c + 0x4A) = 1;
            *(unsigned char *)((char *)s0c + 0x4C) = 0;
        }
    }
    s18 = *(void **)((char *)arg0 + 0x18);
    if (s18 != 0) {
        truck = *(void **)((char *)arg0 + 4);
        *(float *)((char *)arg0 + 0x68) = lbl_80563368;
        if (*(unsigned char *)((char *)truck + 0x259C) != 0) {
            float sq = *(float *)((char *)truck + 0x25A0);
            *(unsigned char *)((char *)s18 + 0x4A) = 0;
            *(unsigned char *)((char *)s18 + 0x4B) = 1;
            *(unsigned char *)((char *)s18 + 0x49) = 1;
            s18 = *(void **)((char *)arg0 + 0x18);
            t = lbl_80563374 + (lbl_80563374 * (sq * sq));
            v = *(float *)((char *)arg0 + 0x68);
            if (v != *(float *)((char *)s18 + 8)) {
                *(unsigned char *)((char *)s18 + 0x4D) = 1;
                *(float *)((char *)s18 + 8) = v;
            }
            s18 = *(void **)((char *)arg0 + 0x18);
            if (t != *(float *)((char *)s18 + 4)) {
                *(unsigned char *)((char *)s18 + 0x4E) = 1;
                *(float *)((char *)s18 + 4) = t;
            }
        } else {
            *(unsigned char *)((char *)s18 + 0x4A) = 1;
            *(unsigned char *)((char *)s18 + 0x4C) = 0;
        }
    }
    s30 = *(void **)((char *)arg0 + 0x30);
    truck = *(void **)((char *)arg0 + 4);
    if (s30 != 0) {
        f31 = *(float *)((char *)truck + 0x2618);
        if (f31 > lbl_80563394) {
            float a, b;
            v = lbl_80563368;
            t = (*(float *)((char *)truck + 0x25D4) - lbl_80563398) / lbl_8056339C;
            v = (v < t) ? v : t;
            v = (v > lbl_80563370) ? v : lbl_80563370;
            a = lbl_80563368;
            t = (f31 - lbl_80563394) / lbl_805633A0;
            b = lbl_80563370 + (v * a);
            a = (a < t) ? a : t;
            a = (a > lbl_80563370) ? a : lbl_80563370;
            t = (lbl_80563370 + (a * lbl_80563368)) * b;
            if (t != *(float *)((char *)s30 + 8)) {
                *(unsigned char *)((char *)s30 + 0x4D) = 1;
                *(float *)((char *)s30 + 8) = t;
            }
            s30 = *(void **)((char *)arg0 + 0x30);
            *(unsigned char *)((char *)s30 + 0x4A) = 0;
            *(unsigned char *)((char *)s30 + 0x4B) = 1;
            *(unsigned char *)((char *)s30 + 0x49) = 1;
        } else {
            *(unsigned char *)((char *)s30 + 0x4A) = 1;
            *(unsigned char *)((char *)s30 + 0x4C) = 0;
        }
        f30 = QueryGroundHeightAtXZ((void *)((char *)truck + 0x6C), *(float *)((char *)truck + 0x60), *(float *)((char *)truck + 0x68));
        {
            float tmp[3];
            float *vp = (float *)((char *)truck + 0x118);
            tmp[0] = vp[0]; tmp[1] = vp[1]; tmp[2] = vp[2];
            mag = PSVECMag((void *)tmp);
            if (mag <= lbl_80563388)
                mag = lbl_80563388;
            inv = lbl_80563368 / mag;
            nvx = tmp[0] * inv;
            nvy = tmp[1] * inv;
            nvz = tmp[2] * inv;
            tmp[0] = nvx; tmp[1] = nvy; tmp[2] = nvz;
            r28flag = (fn_80178CA4() == 1);
            want = 0;
            if ((fn_801796C4() == 0) && (r28flag != 0) && ((*(float *)((char *)truck + 0x64) - f30) > lbl_805633A4) && (f31 > lbl_805633A8) && (nvy > lbl_805633AC)) {
                if (hasSelectedTrackMusicSong() == 0)
                    want = 1;
                else if (hasNoSelectedTrackMusicSong() != 0)
                    want = 1;
            }
            if (want != 0) {
                v = lbl_80563368;
                t = (f31 - lbl_805633B0) / lbl_805633B4;
                v = (v < t) ? v : t;
                v = (v > lbl_80563370) ? v : lbl_80563370;
                fn_8020C910(lbl_80563368 + (v * lbl_805633B8));
            } else if (f31 < lbl_80563394) {
                fn_8020C910(lbl_80563368);
            }
        }
    }
    s4c = *(void **)((char *)arg0 + 0x4C);
    if (s4c != 0) {
        truck = *(void **)((char *)arg0 + 4);
        eq = (*(float *)((char *)truck + 0x2588) == lbl_80563370);
        if (eq == 0) {
            t = *(float *)((char *)truck + 0x2588);
            if (t > lbl_805633BC) {
                if (lbl_80563368 != *(float *)((char *)s4c + 8)) {
                    *(unsigned char *)((char *)s4c + 0x4D) = 1;
                    *(float *)((char *)s4c + 8) = lbl_80563368;
                }
            } else {
                v = lbl_80563368;
                t = (t - lbl_805633BC) / lbl_805633C0;
                v = (v < t) ? v : t;
                v = (v > lbl_80563370) ? v : lbl_80563370;
                t = lbl_80563368 + (v * lbl_805633C4);
                if (t != *(float *)((char *)s4c + 8)) {
                    *(unsigned char *)((char *)s4c + 0x4D) = 1;
                    *(float *)((char *)s4c + 8) = t;
                }
            }
            s4c = *(void **)((char *)arg0 + 0x4C);
            *(unsigned char *)((char *)s4c + 0x4A) = 0;
            *(unsigned char *)((char *)s4c + 0x4B) = 1;
            *(unsigned char *)((char *)s4c + 0x49) = 1;
        } else {
            *(unsigned char *)((char *)s4c + 0x4A) = 1;
            *(unsigned char *)((char *)s4c + 0x4C) = 0;
        }
    }
    {
        float sp8, spC, sp10;
        int isHit = 0;
        float *fin;
        p = (char *)truck + 0x23AC;
        i = 0;
        do {
            fin = (float *)(p + 0x30);
            truck = *(void **)((char *)arg0 + 4);
            outx = (fin[2] * *(float *)((char *)truck + 0x54)) + ((*(float *)p * *(float *)((char *)truck + 0x3C)) + (fin[1] * *(float *)((char *)truck + 0x48)));
            outy = (fin[2] * *(float *)((char *)truck + 0x58)) + ((*(float *)p * *(float *)((char *)truck + 0x40)) + (fin[1] * *(float *)((char *)truck + 0x4C)));
            outz = (fin[2] * *(float *)((char *)truck + 0x5C)) + ((*(float *)p * *(float *)((char *)truck + 0x44)) + (fin[1] * *(float *)((char *)truck + 0x50)));
            sp8 = outx;
            spC = outy;
            sp10 = outz;
            sp8 += *(float *)((char *)truck + 0x60);
            spC += *(float *)((char *)truck + 0x64);
            sp10 += *(float *)((char *)truck + 0x68);
            if (spC < fn_802BF590(sp10, spC)) {
                isHit = 1;
                break;
            }
            i++;
            p += 0x74;
        } while (i < 4);
        s34 = *(void **)((char *)arg0 + 0x34);
        if (s34 != 0 && fn_802BF4F0() != 0) {
            if (isHit != 0) {
                truck = *(void **)((char *)arg0 + 4);
                t = lbl_805633C8 * *(float *)((char *)truck + 0x25D4);
                v = lbl_80563368;
                t2 = (t - lbl_80563370) / lbl_805633CC;
                v = (v < t2) ? v : t2;
                v = (v > lbl_80563370) ? v : lbl_80563370;
                t2 = lbl_80563370 + (v * lbl_805633D0);
                if (t2 != *(float *)((char *)s34 + 8)) {
                    *(unsigned char *)((char *)s34 + 0x4D) = 1;
                    *(float *)((char *)s34 + 8) = t2;
                }
                v = lbl_80563368;
                t2 = (t - lbl_80563370) / lbl_805633D4;
                v = (v < t2) ? v : t2;
                v = (v > lbl_80563370) ? v : lbl_80563370;
                t2 = lbl_80563368 + (v * lbl_805633D8);
                if (t2 != *(float *)((char *)s34 + 4)) {
                    *(unsigned char *)((char *)s34 + 0x4E) = 1;
                    *(float *)((char *)s34 + 4) = t2;
                }
                s34 = *(void **)((char *)arg0 + 0x34);
                *(unsigned char *)((char *)s34 + 0x4A) = 0;
                *(unsigned char *)((char *)s34 + 0x4B) = 1;
                *(unsigned char *)((char *)s34 + 0x49) = 1;
            } else {
                *(unsigned char *)((char *)s34 + 0x4A) = 1;
                *(unsigned char *)((char *)s34 + 0x4C) = 0;
            }
        }
        s38 = *(void **)((char *)arg0 + 0x38);
        if (s38 != 0 && fn_802BF4F0() != 0 && isHit != 0 && *(unsigned char *)((char *)arg0 + 0x70) == 0) {
            *(unsigned char *)((char *)s38 + 0x49) = 1;
            *(unsigned char *)((char *)s38 + 0x4B) = 0;
            *(unsigned char *)((char *)s38 + 0x4A) = 0;
        }
        s3c = *(void **)((char *)arg0 + 0x3C);
        if (s3c != 0 && fn_802BF4F0() != 0 && *(unsigned char *)((char *)arg0 + 0x70) != 0 && isHit == 0 && lbl_8055E3C8 > lbl_80563380) {
            *(unsigned char *)((char *)s3c + 0x49) = 1;
            *(unsigned char *)((char *)s3c + 0x4B) = 0;
            *(unsigned char *)((char *)s3c + 0x4A) = 0;
        }
        *(unsigned char *)((char *)arg0 + 0x70) = (unsigned char)isHit;
        s40 = *(void **)((char *)arg0 + 0x40);
        if (s40 != 0) {
            int ok = 0;
            float speed;
            truck = *(void **)((char *)arg0 + 4);
            speed = *(float *)((char *)truck + 0x25D4);
            if ((float)fabs(*(float *)((char *)truck + 0x2690)) == lbl_80558DC4 && speed > lbl_805633DC && *(int *)((char *)truck + 0x2620) > 1 && isHit == 0) {
                float dot = (float)fabs(PSVECDotProduct((void *)((char *)truck + 0x118), (void *)((char *)truck + 0x3C)));
                float base;
                if ((float)fabs(*(float *)((char *)arg0 + 0x60)) == lbl_80558DC4)
                    base = lbl_805633E0;
                else
                    base = lbl_805633E4;
                ok = (dot == speed * base);
                if (ok != 0) {
                    float cl, vv;
                    cl = lbl_80563368;
                    t = lbl_805633DC * ((dot / (speed * base)) - cl);
                    cl = (cl < t) ? cl : t;
                    cl = (cl > lbl_80563370) ? cl : lbl_80563370;
                    vv = lbl_805633E8 * *(float *)((char *)arg0 + 0x60);
                    if (vv >= lbl_80563368)
                        vv = lbl_80563368;
                    t = lbl_805633EC * (cl * vv);
                    if (t != *(float *)((char *)s40 + 8)) {
                        *(unsigned char *)((char *)s40 + 0x4D) = 1;
                        *(float *)((char *)s40 + 8) = t;
                    }
                    s40 = *(void **)((char *)arg0 + 0x40);
                    *(unsigned char *)((char *)s40 + 0x4A) = 0;
                    *(unsigned char *)((char *)s40 + 0x4B) = 1;
                    *(unsigned char *)((char *)s40 + 0x49) = 1;
                    *(float *)((char *)arg0 + 0x60) += lbl_805633F0;
                }
            }
            if (ok == 0) {
                s40 = *(void **)((char *)arg0 + 0x40);
                *(unsigned char *)((char *)s40 + 0x4A) = 1;
                *(unsigned char *)((char *)s40 + 0x4C) = 0;
                *(float *)((char *)arg0 + 0x60) = lbl_80563370;
            }
        }
    }
}
extern "C" s32 fn_80009C84();
extern "C" void fn_80206750(s32, s32, s32);
/* Forward a scene-state value to up to three child sound handlers, using aux mode 0 while a scene runs and 2 during teardown. */ extern "C" void fn_8020F15C(void *sound) {
    /* Propagate a state value to up to three child handlers, choosing mode 2 or 0 based on fn_80009C84. */
    void *sceneState = *(void **)((char *)sound + 4);
    int auxIndex = *(int *)((char *)sceneState + 0x1EC);
    int auxMode;
    int sceneActive = fn_80009C84();
    auxMode = 2;
    if (sceneActive != 0)
        auxMode = 0;
    if (*(int *)((char *)sound + 0x48) != 0)
        fn_80206750(*(int *)((char *)sound + 0x48), auxIndex, auxMode);
    if (*(int *)((char *)sound + 0x4C) != 0)
        fn_80206750(*(int *)((char *)sound + 0x4C), auxIndex, auxMode);
    if (*(int *)((char *)sound + 0x50) != 0)
        fn_80206750(*(int *)((char *)sound + 0x50), auxIndex, auxMode);
}

#pragma scheduling on
#pragma scheduling off
#pragma cplusplus reset

/* CarSound vtable slot +0x14: re-arm the overheat_start.sfx held at +0x50 of
 * the car's sound set if present, setting its +0x49 flag and clearing +0x4A/+0x4B. */
void CarSound_ResetOverheatStart(void *carSound) {
    void *sound;
    sound = *(void **)((char *)carSound + 0x50);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}

/* Reset the state flags (+0x49 set, +0x4A/+0x4B clear) of the water-bounce
 * sound stored at +0x28 of the car's sound set. */
/* CarSound vtable slot: re-arm the water-bounce sound at +0x28 by setting its +0x49 flag and clearing +0x4A/+0x4B, if that sound exists. */ void CarSound_ResetWaterBounce(void *carSound) {
    void *sound;
    sound = *(void **)((char *)carSound + 0x28);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}

#pragma scheduling on
/* CarSound vtable slot +0x1C: re-arm the backfire sound held at +0x8. If its +0x8 value differs from 1.0, raise the +0x4D update flag and set it to 1.0, then set +0x49 and clear +0x4A/+0x4B. */ void CarSound_ResetBackfire(void *carSound) {
    void *backfire = *(void **)((char *)carSound + 8);
    f32 one;

    if (backfire != 0) {
        one = lbl_80563368;
        if (one != *(f32 *)((char *)backfire + 8)) {
            *(signed char *)((char *)backfire + 0x4D) = 1;
            *(f32 *)((char *)backfire + 8) = one;
        }

        backfire = *(void **)((char *)carSound + 8);
        *(signed char *)((char *)backfire + 0x49) = 1;
        *(signed char *)((char *)backfire + 0x4B) = 0;
        *(signed char *)((char *)backfire + 0x4A) = 0;
    }
}
#pragma scheduling off
void fn_8020F284(void *carSound, float inputValue) {
#pragma scheduling invalid_target
    /* CarSound vtable handler: map the impact value from [5,20] to [0,1], scale it to [0.2,0.8], and set it as the car_gnd1.sfx volume at +8, raising +0x4D on a change, then re-arm the sound's +0x49/+0x4A/+0x4B flags. */
    float normalized;
    float scaled;
    float value;
    void *gndSound;
    gndSound = *(void **)((char *)carSound + 0x1C);
    if (gndSound != 0) {
        normalized = lbl_80563368;
        scaled = (inputValue - lbl_805633DC) / lbl_805633F4;
        normalized = (normalized < scaled) ? normalized : scaled;
        normalized = (normalized > lbl_80563370) ? normalized : lbl_80563370;
        value = lbl_805633F8 + normalized * lbl_805633FC;
        if (value != *(float *)((char *)gndSound + 8)) {
            *(signed char *)((char *)gndSound + 0x4D) = 1;
            *(float *)((char *)gndSound + 8) = value;
        }
        gndSound = *(void **)((char *)carSound + 0x1C);
        *(signed char *)((char *)gndSound + 0x49) = 1;
        *(signed char *)((char *)gndSound + 0x4B) = 0;
        *(signed char *)((char *)gndSound + 0x4A) = 0;
    }
}

/* CarSound vtable slot +0x20: re-arm the niceland.sfx handle stored at +0x24
 * by setting its +0x49 flag and clearing its +0x4A/+0x4B requests. */
void CarSound_ResetNiceLand(void *carSound) {
    void *sound;
    sound = *(void **)((char *)carSound + 0x24);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}

/* CarSound vtable slot: re-arm the badland.sfx sound at +0x20 by setting its +0x49 flag and clearing +0x4A/+0x4B, if that sound exists. */ void CarSound_ResetBadland(void *carSound) {
    /* Reset the state flags (+0x49 set, +0x4A/+0x4B clear) of the badland
     * sound stored at +0x20 of the car's sound set. */
    void *sound;
    sound = *(void **)((char *)carSound + 0x20);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}
#pragma scheduling off
/* CarSound vtable slot: re-arm the boost-turbo-tap sound at +0x2C by setting its +0x49 flag and clearing +0x4A/+0x4B, if present. */ void CarSound_ResetBoostTurboTap(void *carSound) {
    /* Reset the state flags (+0x49 set, +0x4A/+0x4B clear) of the boostTurboTap
     * sound stored at +0x2C of the car's sound set. */
    void *sound;
    sound = *(void **)((char *)carSound + 0x2C);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}
/* CarSound vtable slot: re-arm the watersink.sfx sound at +0x44 by setting its +0x49 flag and clearing +0x4A/+0x4B, if that sound exists. */ void CarSound_ResetWaterSink(void *carSound) {
    /* Reset the state flags (+0x49 set, +0x4A/+0x4B clear) of the waterSink
     * sound stored at +0x44 of the car's sound set. */
    void *sound;
    sound = *(void **)((char *)carSound + 0x44);
    if (sound != 0) {
        *(signed char *)((char *)sound + 0x49) = 1;
        *(signed char *)((char *)sound + 0x4B) = 0;
        *(signed char *)((char *)sound + 0x4A) = 0;
    }
}
/* CarSound vtable slot 0x34 (vtable lbl_8033C8C4): does nothing.  Its siblings in
 * that table -- CarSound_ResetOverheatStart, CarSound_ResetWaterBounce, CarSound_ResetNiceLand, CarSound_ResetBadland, CarSound_ResetBoostTurboTap
 * and CarSound_ResetWaterSink -- each re-arm one of the car's sounds by raising the sound's
 * +0x49 update flag and clearing its +0x4A/+0x4B stop/play requests; the sound
 * behind this slot is driven entirely by the per-frame update fn_8020E598 and
 * has nothing to re-arm, so its handler is empty. */
void fn_8020F39C(void) {

}

void CarSound_RequestInvulnerable(void *carSound) {
    /* Raise the +0x72 flag (CarSound.flag72): request the invulnerable sfx after a hit. */
    *(signed char *)((char *)carSound + 0x72) = 1;
}
extern float lbl_80563368;
extern float lbl_80563370;
extern float lbl_805633DC;
extern float lbl_805633F4;
extern float lbl_805633F8;
extern float lbl_805633FC;
