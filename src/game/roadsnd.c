// roadsnd — road surface sound (roadsnd.val, "roadsnd: can't find %s").
// Recovered TU window 0x8020CA30..0x8020CF60+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020CF60 (+ .ctors slot 0x802ED39C) remains in
// auto/text_8020CF60_.c pending a promotion pass.
// Roadsnd data: lbl_8033C650 is the container vtable {destroy, update};
// lbl_8033C660 "roadsnd.val" names the parameter file, lbl_8033C66C "surftype" the
// surface-type key and lbl_8033C678 "roadsnd: can't find %s" the missing-sound warning.
// lbl_8055B5E0 "roadsnd" is the allocator tag; lbl_8055B5E8/lbl_8055B628 "sound" name
// the item type and sound-id key; lbl_8055B5F0/B5F8/B600/B608/B610/B618/B620 are the
// pitch3/pitch1/vol3/vol2/speed3/speed2/speed1 keys; lbl_80563300 is a ~4/9 speed scale.
extern char lbl_8033C650[];
typedef float f32;
extern f32 lbl_80563304;
extern f32 lbl_80563308;
extern f32 lbl_8056330C;
extern void* fn_801D04A8(int);
extern char lbl_8033C660[];
extern char lbl_8033C66C[];
extern char lbl_8033C678[];
extern const char lbl_8055B5E0[4];
extern const char lbl_8055B5E8[4];
extern const char lbl_8055B5F0[4];
extern const char lbl_8055B5F8[4];
extern const char lbl_8055B600[4];
extern const char lbl_8055B608[4];
extern const char lbl_8055B610[4];
extern const char lbl_8055B618[4];
extern const char lbl_8055B620[4];
extern const char lbl_8055B628[4];
extern f32 lbl_80563300;
extern void* fn_801284F8(int, const char*);
extern void* getValueFile(const char*);
  extern void fn_80131818(void*);
  extern void fn_80128668(void*);
extern void* fn_802077A4(int, int, void*, void*);
extern int fn_802E30C8(const char*, ...);
extern int strcmp(const char*, const char*);
#pragma cplusplus on
// One "sound" entry from the roadsnd.val parameter file: typed accessors for
// the sound id and the per-surface speed / volume / pitch parameters.
struct RoadSndParamItem {
    virtual const char* getName();  // item type name ("sound")
    virtual void slot1();
    virtual void slot2();
    virtual int getA(const char*);  // sound id for a named key
    virtual void slot4();
    virtual int getB(const char*);  // integer value for a named key (e.g. "surftype")
    virtual void slot6();
    virtual f32 getF(const char*);  // float value for a named key
};
// Directory of parameter items opened from "roadsnd.val".
struct RoadSndParamDir {
    virtual void slot0();
    virtual RoadSndParamItem* getAt(int);
};
typedef struct RoadSndParamItem Item_8020CA3C;
typedef struct RoadSndParamDir Dir_8020CA3C;
#pragma cplusplus reset

/* Road-sound module start-up hook, empty in this build.  The bootstrap init
 * fn_80004B5C calls it once among the other subsystem starts (just after
 * fn_802789A8), and its teardown fn_80004CB4 calls the matching empty
 * shutdown hook fn_8020CA34; the third empty hook fn_8020CA38 is called by
 * fn_8000AA38 when it releases the sound/UI state.  Nothing to do here: the
 * road-sound container is built per owner by RoadSnd_createContainer and released by
 * fn_8020CC78, so the module keeps no global state to start up. */
void fn_8020CA30(void) {

}

/* Road-sound module shutdown hook, empty in this build.  It is the twin of
 * the start-up hook fn_8020CA30: the bootstrap teardown fn_80004CB4 calls it
 * among the other subsystem stops (between fn_800218F8 and fn_802789B0).
 * Nothing to release here -- every road-sound container is destroyed by
 * fn_8020CC78 through its own vtable, so the module holds no global state. */
void fn_8020CA34(void) {

}

/* Road-sound module release hook, empty in this build.  The third of this TU's
 * lifecycle stubs after the start-up hook fn_8020CA30 and the shutdown hook
 * fn_8020CA34: fn_8000AA38 calls it while tearing the sound/UI state down
 * (after releasing the sound block through fn_80129324 and resetting the
 * mixer through fn_80206518).  Nothing to give back: each road-sound
 * container is destroyed by fn_8020CC78 through its own vtable, so the
 * module holds no global state to release. */
void fn_8020CA38(void) {

}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma scheduling invalid_target
/* Build the per-owner road-sound container from roadsnd.val: one 0x24-byte entry per "sound" item holds its Sound3D handle, surface type, and surface-scaled speed/volume/pitch values. */ extern "C" void* RoadSnd_createContainer(void* ownerCtx) {
    /* Builds a road-sound container from "roadsnd.val": one 0x24-byte entry per
     * "sound" param item holds its Sound3D handle, surface type and scaled
     * speed/volume/pitch values; the owner context is stored at +4. */
    char* entry;
    char* container;
    int itemIndex;
    RoadSndParamItem* item;
    RoadSndParamDir* paramDir;
    char* owner;
    f32 speedScale;
    int soundId;
    void* sound3d;
    int count;

    container = (char*)fn_801284F8(0x12C, lbl_8055B5E0);
    if (container != 0) {
        *(char**)container = lbl_8033C650;
        *(void**)(container + 4) = ownerCtx;
        *(int*)(container + 8) = 0;
        paramDir = (RoadSndParamDir*)getValueFile(lbl_8033C660);
        speedScale = lbl_80563300;
        itemIndex = 0;
        while ((item = paramDir->getAt(itemIndex)) != 0) {
            if (strcmp(item->getName(), lbl_8055B5E8) == 0) {
                count = *(int*)(container + 8);
                owner = *(char**)(container + 4);
                *(int*)(container + 8) = count + 1;
                entry = container + count * 0x24;
                soundId = item->getA(lbl_8055B628);
                sound3d = fn_802077A4(soundId, 4, owner + 0x118, owner + 0x60);
                *(void**)(entry + 0xC) = sound3d;
                if (sound3d == 0 && *(int*)(owner + 0x1EC) == 0) {
                    fn_802E30C8(lbl_8033C678, soundId);
                }
                *(int*)(entry + 0x10) = item->getB(lbl_8033C66C);
                *(f32*)(entry + 0x14) = speedScale * item->getF(lbl_8055B620);
                *(f32*)(entry + 0x18) = speedScale * item->getF(lbl_8055B618);
                *(f32*)(entry + 0x1C) = speedScale * item->getF(lbl_8055B610);
                *(f32*)(entry + 0x20) = item->getF(lbl_8055B608);
                *(f32*)(entry + 0x24) = item->getF(lbl_8055B600);
                *(f32*)(entry + 0x28) = item->getF(lbl_8055B5F8);
                *(f32*)(entry + 0x2C) = item->getF(lbl_8055B5F0);
            }
            itemIndex++;
        }
        fn_80131818(paramDir);
    }
    return container;
}
#pragma pop

#pragma cplusplus on
struct CC78_Item { virtual void s0(int); };
static inline void CC78_call(void *p, int v) { ((CC78_Item *)p)->s0(v); }
#pragma cplusplus reset
#pragma scheduling invalid_target
/* Destroys a road-sound container: installs its vtable, calls slot 0(v=1) on each active 0x24-byte entry's object, and optionally frees the container. */
/* Road-sound container destructor: install its vtable, release the object held by each active 0x24-byte entry, and optionally free the container. */ void *fn_8020CC78(void *container, int shouldFree) {
    void *entry;
    int entryIndex;
    if (container != 0) {
        *(void **)container = lbl_8033C650;
        entry = container;
        entryIndex = 0;
        while (entryIndex < *(int *)((char *)container + 8)) {
            void *soundObject = *(void **)((char *)entry + 0xC);
            if (soundObject == 0) {
                goto next;
            }
            if (soundObject == 0) {
                goto next;
            }
            CC78_call(soundObject, 1);
        next:
            entry = (char *)entry + 0x24;
            entryIndex++;
        }
        if (shouldFree > 0) {
            fn_80128668(container);
        }
    }
    return container;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8020CD28(char *arg0) {
    char *ctx = *(char **)(arg0 + 4);
    char *e;
    int max = 0;
    int i;
    int v;
    f32 hi, cur, scale, lo;

    v = *(int *)(ctx + 0x2410);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x2484);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x24F8);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x256C);
    if (v > max) max = v;

    e = arg0;
    hi = lbl_80563308;
    lo = lbl_8056330C;
    cur = *(f32 *)(ctx + 0x25D4);
    scale = lbl_80563304 * (f32)*(int *)(ctx + 0x2620);
    for (i = 0; i < *(int *)(arg0 + 8); i++, e += 0x24) {
        if (*(int *)((char *)fn_801D04A8(max) + 0x10) == *(int *)(e + 0x10)) {
            char *obj = *(char **)(e + 0xC);
            if (obj != 0) {
                f32 a, b, t, t2;
                f32 s = *(f32 *)(e + 0x18);
                if (cur < s) {
                    f32 base = *(f32 *)(e + 0x14);
                    f32 d = *(f32 *)(e + 0x20);
                    t = (cur - base) / (s - base);
                    t = (hi < t) ? hi : t;
                    t = (t > lo) ? t : lo;
                    a = lo + t * (d - lo);
                } else {
                    f32 base2 = *(f32 *)(e + 0x18);
                    f32 d2 = *(f32 *)(e + 0x20);
                    t = (cur - base2) / (*(f32 *)(e + 0x1C) - base2);
                    t = (hi < t) ? hi : t;
                    t = (t > lo) ? t : lo;
                    a = d2 + t * (*(f32 *)(e + 0x24) - d2);
                }
                {
                    f32 base3 = *(f32 *)(e + 0x14);
                    f32 d3 = *(f32 *)(e + 0x28);
                    t2 = (cur - base3) / (*(f32 *)(e + 0x1C) - base3);
                    t2 = (hi < t2) ? hi : t2;
                    t2 = (t2 > lo) ? t2 : lo;
                    b = d3 + t2 * (*(f32 *)(e + 0x2C) - d3);
                }
                *(char *)(obj + 0x4A) = 0;
                *(char *)(obj + 0x4B) = 1;
                *(char *)(obj + 0x49) = 1;
                {
                    f32 x = scale * a;
                    obj = *(char **)(e + 0xC);
                    if (x != *(f32 *)(obj + 8)) {
                        *(char *)(obj + 0x4D) = 1;
                        *(f32 *)(obj + 8) = x;
                    }
                    obj = *(char **)(e + 0xC);
                    if (b != *(f32 *)(obj + 4)) {
                        *(char *)(obj + 0x4E) = 1;
                        *(f32 *)(obj + 4) = b;
                    }
                }
            }
        } else {
            char *obj = *(char **)(e + 0xC);
            if (obj != 0) {
                *(char *)(obj + 0x4A) = 1;
                *(char *)(obj + 0x4C) = 0;
            }
        }
    }
}
#pragma pop


