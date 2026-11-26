#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80207848(int, int);
extern float lbl_8055C4F8;
extern void fn_8026B260(void);
extern void LoadFloatOption(int, void *, float *);
extern void fn_8026B11C(void **, void *);
extern unsigned char lbl_80346988[];
/* JumpCam config table at lbl_80346988: a = UI/format strings; b = "effects_volume" key; c = "heart.sfx" key; d = "whosh.sfx" key. */
typedef struct { unsigned char a[0xA0]; unsigned char b[0x10]; unsigned char c[0xC]; unsigned char d[1]; } T8026B644;
extern int lbl_8055F4D0, lbl_8055F4CC, lbl_8055F4C8;
extern float lbl_80563D68;
extern float lbl_80563D6C, lbl_80563D70, lbl_80563D74, lbl_8055E3C8;
extern unsigned char lbl_8049A0E8[];
extern void *getRegisteredObject(void);
extern int fn_80178CA4(void);
extern void fn_8020C900(int);
extern void fn_80206444(void);
extern void fn_80206454(void);
extern void fn_802C2C68(int, int);
extern void fn_80176A00(int);
extern float QueryGroundHeightAtXZ(void *, float, float);
extern int lbl_8055C4FC, lbl_8055C500;
extern unsigned char lbl_8049A028[];
extern void fn_8026A1F0(int, int, int);
/* No-op per-entry constructor callback for the fixed-size object pool built by fn_8026B0D4. */
void fn_8026B118(void) {}

extern int lbl_8055F4D0, lbl_8055F4CC;
#pragma dont_inline on
/* Get a sound object by id (via fn_80207848) into *outObj and, if found, set
 * its float at +0x8 to lbl_8055C4F8 (marking +0x4D when it changes). */
void fn_8026B11C(void **outObj, void *soundId) {
    void *obj = fn_80207848((int)soundId, 0);
    float value;
    *outObj = obj;
    if (obj != 0) {
        value = lbl_8055C4F8;
        if (value != *(float *)((unsigned char *)obj + 8)) {
            *((unsigned char *)obj + 0x4D) = 1;
            *(float *)((unsigned char *)obj + 8) = value;
        }
    }
}
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
/* System::deleteThreads helper: deletes the owned thread object stored in the given slot (virtual destroy with deleting flag 1) and clears the slot. (rename_symbol unavailable for mangled symbol) */
extern "C" void deleteThreads__6SystemFv_8026B178(void *threadSlot) {
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *thread = *(ThreadObject **)threadSlot;
    if (thread) {
        if (thread)
            thread->destroy(1);
        *(ThreadObject **)threadSlot = 0;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus on
#pragma scheduling invalid_target
/* Copy a 2-float pair and one float from obj's virtual getters into the current output slot. */
extern "C" void fn_8026B1D0(void *obj_) {
    class Object {
    public:
        virtual void v00();
        virtual void v04();
        virtual void v08();
        virtual void v0C();
        virtual void v10();
        virtual void v14();
        virtual void v18();
        virtual void v1C();
        virtual float fn28(unsigned int, float);
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual void v38();
        virtual unsigned long long fn3C(unsigned int);
    };
    union Pair {
        unsigned long long bits;
        float values[2];
    } pair;
    float *dst = (float *)(lbl_8049A028 + lbl_8055F4C8 * 0xC);
    Object *obj = (Object *)obj_;

    pair.bits = obj->fn3C((unsigned int)&lbl_8055C4FC);
    dst[0] = pair.values[0];
    dst[1] = pair.values[1];
    dst[2] = obj->fn28((unsigned int)&lbl_8055C500, lbl_80563D68);
}
#pragma scheduling on
#pragma cplusplus reset
extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void *fn_80028E00(char *, const char *);
extern int fn_8012C33C(char *);
extern void *fn_80131808(char *);
extern void fn_80131818(void *);
extern int fn_802E30C8(const char *, ...);
extern char *strchr(const char *, int);
extern char *strncpy(char *, const char *, unsigned int);
extern int stricmp(const char *, const char *);
extern char lbl_8055C504, lbl_8055C50C;
#pragma push
#pragma cplusplus on
extern "C" void fn_8026B260(void) {
    class FileName {
    public:
        virtual void v00();
        virtual void v04();
        virtual void v08();
        virtual void v0C();
        virtual char *getFileName(const char *, int);
    };
    class Iterator {
    public:
        virtual void v00();
        virtual void *next(int);
    };
    class Entry {
    public:
        virtual const char *getName();
    };
    char name[12];
    char *base = (char *)lbl_80346988;
    register int iteratorOrZero = 0;
    void *obj;
    FileName *nameObj;
    register Iterator *it;
    register int index;
    register Entry *entry;
    char *dot;
    lbl_8055F4C8 = iteratorOrZero;
    obj = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    nameObj = *(FileName **)((char *)obj + 0x20);
    dot = nameObj->getFileName(base, 0);
    if (dot != 0) {
        strncpy(name, dot, 11);
        dot = strchr(name, '.');
        if (dot) *dot = iteratorOrZero;
        fn_80028E00(name, (const char *)&lbl_8055C504);
        if (!fn_8012C33C(name)) {
            fn_802E30C8(base + 0xC, name);
            return;
        }
        iteratorOrZero = (int)fn_80131808(name);
        it = (Iterator *)iteratorOrZero;
        index = 0;
        do {
            entry = (Entry *)it->next(index++);
            if (entry && stricmp(entry->getName(), (const char *)&lbl_8055C50C) == 0) {
                fn_8026B1D0(entry);
                lbl_8055F4C8++;
            }
        } while (entry);
        fn_80131818(it);
        fn_802E30C8(base + 0x34, lbl_8055F4C8, name);
        return;
    }
    fn_802E30C8(base + 0x5C);
}

#pragma cplusplus reset
#pragma processor 750
#pragma push
#pragma opt_common_subs off
/* Update one JumpCam slot: toggle or refresh it from the shared per-player table when JumpCam mode is active, otherwise detect the player's circle and enable the slot when close enough to the centre. */ void updateJumpCamSlot(int arg0) {
    /* JumpCam per-slot update.  When the JumpCam mode is active (fn_80178CA4()==1)
     * and the local player is in JumpCam state (truck +0x1F0 == 0x50), refresh
     * this slot's state from the shared per-player table lbl_8049A0E8 (eight
     * 16-byte entries).  If the slot is already on, either turn it off when the
     * truck has changed state enough or the slot's timer has expired, or refresh
     * its sound/visual state; if it is off, look up the player's current position
     * in the circle table lbl_8049A028 to record which circle they are in, and
     * turn the slot on when the player is in a valid circle and close enough to
     * the centre to trigger the "whosh" sound. */
    struct Ent { unsigned char on; unsigned char pad[3]; float t; float v; int idx; };
    float t = lbl_8055E3C8;
    unsigned char *p = (unsigned char *)getRegisteredObject();
    if (fn_80178CA4() == 1 && *(int *)(p + 0x1F0) == 0x50) {
        int off = arg0 << 4;
        struct Ent *e = (struct Ent *)((char *)lbl_8049A0E8 + off);
        if (e->on != 0) {
            if ((*(int *)(p + 0x2620) >= 2 && t - e->t > lbl_80563D68) ||
                t - ((struct Ent *)((char *)lbl_8049A0E8 + off))->t > lbl_80563D6C) {
                unsigned char *o;
                e->on = 0;
                o = (unsigned char *)lbl_8055F4D0;
                if (o != 0) {
                    o[0x4A] = 1;
                    o[0x4C] = 0;
                }
            } else {
                unsigned char *o;
                fn_8020C900(1);
                fn_80206444();
                o = (unsigned char *)lbl_8055F4D0;
                if (o != 0) {
                    o[0x4A] = 0;
                    o[0x4B] = 1;
                    o[0x49] = 1;
                }
                fn_802C2C68(0, 1);
                fn_80176A00(2);
                ((struct Ent *)((char *)lbl_8049A0E8 + off))->v = lbl_80563D70;
            }
        } else {
            float pos[2];
            float d[2];
            float *tab = (float *)lbl_8049A028;
            int found = 0;
            int j = 0;
            pos[0] = *(float *)(p + 0x60);
            pos[1] = *(float *)(p + 0x68);
            while (j < lbl_8055F4C8 && found == 0) {
                float dx;
                float dz;
                float r;
                float r2;
                dz = pos[1] - tab[1];
                r = tab[2];
                dx = pos[0] - tab[0];
                d[0] = dx;
                d[1] = dz;
                r2 = r * r;
                if (d[0] * d[0] + d[1] * d[1] < r2) {
                    e->idx = j;
                    found = 1;
                    e->t = t;
                }
                tab += 3;
                j++;
            }
            if (t - ((struct Ent *)((char *)lbl_8049A0E8 + off))->t < lbl_80563D68 && *(int *)(p + 0x2620) == 0) {
                if (*(float *)(p + 0x64) - QueryGroundHeightAtXZ(p + 0x6C, *(float *)(p + 0x60), *(float *)(p + 0x68)) > lbl_80563D68) {
                    unsigned char *o;
                    e->on = 1;
                    o = (unsigned char *)lbl_8055F4CC;
                    if (o != 0) {
                        o[0x49] = 1;
                        o[0x4B] = 0;
                        o[0x4A] = 0;
                    }
                }
            } else {
                fn_802C2C68(-1, 0);
                fn_80206454();
                fn_80176A00(1);
                fn_8020C900(0);
                ((struct Ent *)((char *)lbl_8049A0E8 + off))->v = lbl_80563D74;
            }
        }
    }
}
#pragma pop

#pragma cplusplus reset
#pragma pop

void fn_8026B644(void) {
#define effectsVolume lbl_8055C4F8
#define heartSfx lbl_8055F4D0
#define whoshSfx lbl_8055F4CC
    /* JumpCam startup: load the jump file, read the effects-volume option and load the two feedback SFX. */
    T8026B644 *cfg = (T8026B644 *)lbl_80346988;
    fn_8026B260();
    LoadFloatOption(4, cfg->b, &effectsVolume);
    fn_8026B11C((void **)&heartSfx, cfg->c);
    fn_8026B11C((void **)&whoshSfx, cfg->d);
#undef effectsVolume
#undef heartSfx
#undef whoshSfx
}
void fn_8026B69C(void) {
    /* Tear down the thread lists: reset the active slot count and delete both thread groups. */
    lbl_8055F4C8 = 0;
    deleteThreads__6SystemFv_8026B178(&lbl_8055F4CC);
    deleteThreads__6SystemFv_8026B178(&lbl_8055F4D0);
}

extern unsigned char lbl_8049A0E8[];
extern int lbl_8055F4C8;
extern int lbl_8055F4CC, lbl_8055F4D0;
extern void *memset(void *, int, unsigned int);
extern int getDeitySlotCount(void);
extern void updateJumpCamSlot(int);
extern void deleteThreads__6SystemFv_8026B178(void *);
#pragma scheduling invalid_target
void fn_8026B6D0(void) {
    /* Clear the per-player state table (lbl_8049A0E8): eight 16-byte entries. */
    void *stateTable = lbl_8049A0E8;
    memset(stateTable, 0, 0x80);
}
#pragma scheduling on
/* For each player/slot, refresh its per-frame state when this subsystem is active.
 * RealName: unknown (rename_symbol disabled). lbl_8055F4C8 = active slot/player count (or >0 flag), getDeitySlotCount() = player count, updateJumpCamSlot(i) = update slot i. */
void fn_8026B6E4(void) {
#define activeCount lbl_8055F4C8
#define getPlayerCount getDeitySlotCount
#define updateSlot updateJumpCamSlot
    int i;
    if (activeCount > 0) {
        for (i = 0; i < getPlayerCount(); i++) {
            updateSlot(i);
        }
    }
#undef activeCount
#undef getPlayerCount
#undef updateSlot
}

/* If slot slotIndex is active (its 'on' byte set), copy that slot's float value
 * (Ent.v at +8) into *outValue and return 1; otherwise return 0. */
int fn_8026B734(int slotIndex, float *outValue) {
    int offset = slotIndex << 4;
    volatile unsigned char *table = lbl_8049A0E8;
    if (table[offset] != 0) {
        *outValue = *(float *)(table + offset + 8);
        return 1;
    }
    return 0;
}

/* If the given slot is active, apply action 0xB to the specified object and return 1. */
int fn_8026B768(int slotIndex, int objectIndex) {
    if (lbl_8049A0E8[slotIndex * 0x10] != 0) {
        fn_8026A1F0(0xB, objectIndex, 0);
        return 1;
    }
    return 0;
}

unsigned char fn_8026B7B4(int slotIndex) {
    // Nonzero if this slot's per-frame state record has its 'on' (active) flag set.
    return lbl_8049A0E8[slotIndex * 0x10];
}

