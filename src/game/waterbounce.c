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
    void *vtable;         // at 0x0, this class's vtable
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
#pragma push
#pragma processor 750
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

    initial = lbl_80563368;
    i = 0;
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
extern "C" void *fn_8020E288(CarSound *snd, s32 deleteMemory) {
    void *sound;
    u8 *p;
    u32 i;
    if (snd != 0) {
        sound = snd->backfire;
        snd->vtable = lbl_8033C8C4;
        if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
        p = (u8 *)snd;
        i = 0;
        do {                        // the two boost sounds
            sound = *(void **)(p + 0x10);
            if (sound != 0) { if (sound != 0) ((Sound *)sound)->release(1); }
            p += 4;
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
        if (deleteMemory > 0) fn_80128668(snd);
    }
    return snd;
}

extern "C" s32 fn_80009C84();
extern "C" void fn_80206750(s32, s32, s32);
extern "C" void fn_8020F15C(void *arg0) {
    /* Propagate a state value to up to three child handlers, choosing mode 2 or 0 based on fn_80009C84. */
    void *state = *(void **)((char *)arg0 + 4);
    int value = *(int *)((char *)state + 0x1EC);
    int mode;
    int flag = fn_80009C84();
    mode = 2;
    if (flag != 0)
        mode = 0;
    if (*(int *)((char *)arg0 + 0x48) != 0)
        fn_80206750(*(int *)((char *)arg0 + 0x48), value, mode);
    if (*(int *)((char *)arg0 + 0x4C) != 0)
        fn_80206750(*(int *)((char *)arg0 + 0x4C), value, mode);
    if (*(int *)((char *)arg0 + 0x50) != 0)
        fn_80206750(*(int *)((char *)arg0 + 0x50), value, mode);
}

#pragma scheduling on
#pragma scheduling off
#pragma cplusplus reset

void fn_8020F1F8(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x50);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

void fn_8020F21C(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x28);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

#pragma scheduling on
void fn_8020F240(void *arg0) {
    void *p;
    float value;
    p = *(void **)((char *)arg0 + 8);
    if (p != 0) {
        value = lbl_80563368;
        if (value != *(float *)((char *)p + 8)) {
            *(signed char *)((char *)p + 0x4D) = 1;
            *(float *)((char *)p + 8) = value;
        }
        p = *(void **)((char *)arg0 + 8);
        *(signed char *)((char *)p + 0x49) = 1;
        *(signed char *)((char *)p + 0x4B) = 0;
        *(signed char *)((char *)p + 0x4A) = 0;
    }
}
#pragma scheduling off
void fn_8020F284(void *arg0, float farg0) {
    float var_f2;
    float temp_f0;
    float temp_f1;
    float sub;
    float div;
    void *temp_r4;
    temp_r4 = *(void **)((char *)arg0 + 0x1C);
    if (temp_r4 != 0) {
        div = lbl_805633F4;
        sub = farg0 - lbl_805633DC;
        var_f2 = lbl_80563368;
        temp_f0 = sub / div;
        var_f2 = (var_f2 < temp_f0) ? var_f2 : temp_f0;
        var_f2 = (var_f2 > lbl_80563370) ? var_f2 : lbl_80563370;
        temp_f1 = lbl_805633F8 + var_f2 * lbl_805633FC;
        if (temp_f1 != *(float *)((char *)temp_r4 + 8)) {
            *(signed char *)((char *)temp_r4 + 0x4D) = 1;
            *(float *)((char *)temp_r4 + 8) = temp_f1;
        }
        temp_r4 = *(void **)((char *)arg0 + 0x1C);
        *(signed char *)((char *)temp_r4 + 0x49) = 1;
        *(signed char *)((char *)temp_r4 + 0x4B) = 0;
        *(signed char *)((char *)temp_r4 + 0x4A) = 0;
    }
}

void fn_8020F30C(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x24);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

void fn_8020F330(void *arg0) {
    void *temp_r3;

    temp_r3 = *(void **)((char *)arg0 + 0x20);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
#pragma scheduling off
void fn_8020F354(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x2C);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
void fn_8020F378(void *arg0) {
    void *temp_r3;

    temp_r3 = *(void **)((char *)arg0 + 0x44);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
void fn_8020F39C(void) {

}

void fn_8020F3A0(void *arg0) {
    *(signed char *)((char *)arg0 + 0x72) = 1;
}
extern float lbl_80563368;
extern float lbl_80563370;
extern float lbl_805633DC;
extern float lbl_805633F4;
extern float lbl_805633F8;
extern float lbl_805633FC;
