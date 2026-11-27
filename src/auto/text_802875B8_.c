// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_80287D70(void *, int, int);
extern int fn_8012C33C(const char *);
extern int getValueFile(const char *);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80348A20[];
extern const char lbl_80348A30[];
extern const char lbl_80348A40[];
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80288868(void *);
extern signed char lbl_8055F6BC;
extern unsigned int fn_80288870(void);
extern void fn_802AB504(void);
extern void fn_8029F0D0(void);
extern void fn_802A7C24(void);
extern void fn_802921F4(void);
extern void fn_802A4B90(void);
extern void fn_802A14F8(void);
extern void fn_802A0AFC(void);
extern void fn_80292618(void);
extern void fn_8029EFBC(void);
extern void fn_8029C22C(void);
extern void fn_80296064(void);
extern void fn_80297FA4(void);
extern void fn_80294C68(void);
extern void fn_8028CF18(void);
extern void fn_8028A784(void);
extern void fn_802A1660(void);
extern void fn_80288988(void);
extern void fn_802A85C8(void);
extern void fn_802881D4(void);
extern void fn_802882A0(void);
extern void fn_802A86A4(void);
extern void fn_8028E138(void);
extern void fn_802980A0(void);
extern void fn_8028A89C(void);
extern void fn_8028CF50(void);
extern void fn_8029222C(void);
extern void fn_80294CC0(void);
extern void fn_80296060(void);
extern void fn_8029F124(void);
extern void fn_80292628(void);
extern void fn_802A172C(void);
extern void fn_802A4C20(void);
extern void fn_802A7C64(void);
extern void fn_802AB5B8(void);
extern void fn_802A9574(void);
extern void CarSnapshotPool_rebuild(void);
extern void *lbl_8055F6C8;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned char u8;
typedef float f32;
extern void fn_802885C0(void);
extern void fn_802885F0(void);
extern void fn_802887EC(void);
extern f32 lbl_80564268;
extern f32 lbl_80564248;
extern f32 lbl_80564250;
#define RNG_SCALE lbl_80564250 /* 0x1FFFF: normalises a 17-bit RNG sample to [0,1] */
#define RNG_SCALE lbl_80564250 /* 0x1FFFF: normalises a 17-bit RNG sample to [0,1] */
extern double lbl_80564258;
extern u8 lbl_804B3150[12];
extern s32 lbl_804B31E0[];
extern s32 lbl_8055F6C0;
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
extern s32 lbl_8055F6C4;
extern s32 lbl_80488648[];
extern s32 fn_801EE0C8(s32);
extern s32 fn_801E2CCC(s32, s32);
extern s32 fn_8002F6AC(s32, void *(*)(void *, s32));
extern void *fn_80287C80(void *, s32);
extern void Abend_Panic(const char *, ...);
extern const char lbl_80348A4C[];
#pragma cplusplus on
struct Vec3i_80287F90 {
    s32 x, y, z;
    Vec3i_80287F90() {}
};
#pragma cplusplus reset
extern s32 fn_801E7DF0(s32);
extern void fn_8028777C(void);
extern void fn_80288218(s32);
extern void fn_802880F4(void);
extern void fn_802A81F0(void);
extern void fn_802888D8(void);
extern void fn_802A1590(void);
extern void fn_8028A664(void);
extern void fn_8028CED8(void);
extern void fn_80294970(void);
extern void fn_80297ED8(void);
extern void fn_8029C1C4(void);
extern void fn_8029EF70(void);
extern void fn_802924F4(void);
extern void fn_802A09B0(void);
extern void fn_802A1290(void);
extern void fn_802A4ADC(void);
extern void fn_80292114(void);
extern void fn_802A7BE8(void);
extern void fn_8029F03C(void);
extern void fn_802AB21C(void);
extern void fn_8028DFB0(void);
typedef struct Obj { void **vtable; } Obj;
void* fn_802875B8(void* object, s32 shouldDelete) {
    /* Clears a 3-word object header and frees it when requested (global destructor). */
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Resets the three 32-bit fields of a container to zero and, when shouldFree
 * is positive, frees the container itself. */
void *fn_80287610(void *object, s32 shouldFree) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

s32 fn_80287668(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

void fn_802876A8(void *obj) {
    /* Store the current timer/progress value at +0x18, clear the byte flag at +0x1C, and hide UI group 0x1D. */
    *(f32 *)((u8 *)obj + 0x18) = fn_8023659C();
    *((u8 *)obj + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

void fn_802876E8(void *arg0) {
#define startTime field_18
#define expired field_1C
    /* Mark this timer expired once the elapsed time exceeds the 1.5s threshold, then stop the associated sound. */
    typedef struct {
        u8 _pad[0x18];
        f32 field_18;
        u8 field_1C;
    } TimerObj;
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = ((TimerObj *)arg0)->startTime;
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80564248)) {
        ((TimerObj *)arg0)->expired = 1;
    }
    if (((TimerObj *)arg0)->expired != 0) {
        fn_80214AF0(0x1D);
    }
#undef startTime
#undef expired
}

s32 fn_8028774C(void *arg0) {
#define expired field_1C
    /* Returns nonzero while this timer's expired flag at +0x1C is clear (timer still running). */
    typedef struct {
        u8 _pad[0x18];
        f32 field_18;
        u8 field_1C;
    } TimerObj;
    return ((TimerObj *)arg0)->expired == 0;
#undef expired
}

/* Callback wrapper: forward to fn_802869CC with the pointer backed up to its enclosing structure (userData - 4). */
void fn_8028775C(int userData) { fn_802869CC(userData - 4); }

/* Callback wrapper: forward to fn_80286A34 with the pointer backed up to its enclosing structure (userData - 4). */
void fn_80287764(int userData) { fn_80286A34(userData - 4); }

/* Callback wrapper: forward to fn_80287238 with the pointer backed up to its enclosing structure (userData - 4). */
void fn_8028776C(int userData) { fn_80287238(userData - 4); }

/* Callback wrapper: forward to fn_80283938 with the pointer backed up to its enclosing structure (userData - 4). */
void fn_80287774(int userData) { fn_80283938(userData - 4); }

void fn_8028777C(void) {
    /* Empty placeholder invoked first in the main subsystem init sequence (fn_80287800); no work to do. */
}

/* Initializes this subsystem state by clearing its flag and running setup steps. */
void fn_80287780(s32 state) {
    lbl_8055F6C0 = 0;
    fn_802AE374();
    fn_8028DF58();
    fn_802924E8();
    fn_802978B8(state);
    fn_80297ED4();
    fn_8029605C();
    fn_802AC458();
}

/* Clears the transient per-world state of the effect, shadow, render and object-list
 * subsystems (counterpart to the setup in fn_80287780); called during teardown. */
void fn_802877D0(void) {
    fn_802AC49C();
    fn_802978E4();
    fn_8029261C();
    fn_8028E0F0();
    fn_802AE394();
}

#pragma push
#pragma scheduling invalid_target
void fn_80287800(s32 initOptions) {
#pragma scheduling invalid_target
#define gMultiplayerMode lbl_8055F6BC
    /* Bring up every game subsystem in order, cache whether this is a
     * multiplayer session (more than one player slot), then finish setup. */
    s32 slotState;
    ((void (*)(void))fn_8028777C)();
    fn_80288218(initOptions);
    fn_802880F4();
    fn_802A81F0();
    fn_802888D8();
    fn_802A1590();
    fn_8028A664();
    fn_8028CED8();
    fn_80294970();
    fn_80297ED8();
    fn_8029C1C4();
    fn_8029EF70();
    fn_802924F4();
    fn_802A09B0();
    fn_802A1290();
    fn_802A4ADC();
    fn_80292114();
    fn_802A7BE8();
    fn_8029F03C();
    fn_802AB21C();
    fn_8028DFB0();
    slotState = fn_801E7DF0(0);
    gMultiplayerMode = (slotState > 1);
    fn_80288868(0);
#undef gMultiplayerMode
}
#pragma pop
void fn_802878A8(void) {
    /* Shut down all game subsystems in order during teardown (counterpart to the init sequences
       in fn_80287914/fn_8028797C). */
    fn_802AB504();
    fn_8029F0D0();
    fn_802A7C24();
    fn_802921F4();
    fn_802A4B90();
    fn_802A14F8();
    fn_802A0AFC();
    fn_80292618();
    fn_8029EFBC();
    fn_8029C22C();
    fn_80296064();
    fn_80297FA4();
    fn_80294C68();
    fn_8028CF18();
    fn_8028A784();
    fn_802A1660();
    fn_80288988();
    fn_802A85C8();
    fn_802881D4();
    fn_802882A0();
}

// Initializes game subsystems in sequence (counterpart to shutdown in fn_802878A8),
// then passes 0 to fn_80288868.
void fn_80287914(void) {
    fn_802A86A4();
    fn_8028E138();
    fn_802980A0();
    fn_8028A89C();
    fn_8028CF50();
    fn_8029222C();
    fn_80294CC0();
    fn_80296060();
    fn_8029F124();
    fn_80292628();
    fn_802A172C();
    fn_802A4C20();
    fn_802A7C64();
    fn_802AB5B8();
    fn_802A9574();
    fn_80288868(0);
}

extern s32 fn_801E7DF0(s32);
extern void fn_8028777C(void);
extern void fn_80288218(s32);
extern void fn_802880F4(void);
extern void fn_802A81F0(void);
extern void fn_802888D8(void);
extern void fn_802A1590(void);
extern void fn_8028A664(void);
extern void fn_8028CED8(void);
extern void fn_80294970(void);
extern void fn_80297ED8(void);
extern void fn_8029C1C4(void);
extern void fn_8029EF70(void);
extern void fn_802924F4(void);
extern void fn_802A09B0(void);
extern void fn_802A1290(void);
extern void fn_802A4ADC(void);
extern void fn_80292114(void);
extern void fn_802A7BE8(void);
extern void fn_8029F03C(void);
extern void fn_802AB21C(void);
extern void fn_8028DFB0(void);
extern void fn_80288868(void *);
extern signed char lbl_8055F6BC;
extern void fn_802AB504(void);
extern void fn_8029F0D0(void);
extern void fn_802A7C24(void);
extern void fn_802921F4(void);
extern void fn_802A4B90(void);
extern void fn_802A14F8(void);
extern void fn_802A0AFC(void);
extern void fn_80292618(void);
extern void fn_8029EFBC(void);
extern void fn_8029C22C(void);
extern void fn_80296064(void);
extern void fn_80297FA4(void);
extern void fn_80294C68(void);
extern void fn_8028CF18(void);
extern void fn_8028A784(void);
extern void fn_802A1660(void);
extern void fn_80288988(void);
extern void fn_802A85C8(void);
extern void fn_802881D4(void);
extern void fn_802882A0(void);
extern void fn_802A86A4(void);
extern void fn_8028E138(void);
extern void fn_802980A0(void);
extern void fn_8028A89C(void);
extern void fn_8028CF50(void);
extern void fn_8029222C(void);
extern void fn_80294CC0(void);
extern void fn_80296060(void);
extern void fn_8029F124(void);
extern void fn_80292628(void);
extern void fn_802A172C(void);
extern void fn_802A4C20(void);
extern void fn_802A7C64(void);
extern void fn_802AB5B8(void);
extern void fn_802A9574(void);
extern void fn_80288868(void *);
extern void fn_8028E1A4(void);
void fn_80287974(void) {
#define beginParticlePass fn_8028E1A4
    /* Begin a particle update pass: snapshot this frame's time and re-enable particle adds. */
    beginParticlePass();
#undef beginParticlePass
}

void fn_80287978(void) {
#define endParticlePass fn_8028E1D0
    /* End a particle update pass: advance every emitter by the frame time and disallow further adds. */
    endParticlePass();
#undef endParticlePass
}

/* Initializes game subsystems in order (counterpart to the shutdown sequence in fn_802878A8). */
void fn_8028797C(void) {
    CarSnapshotPool_rebuild(); fn_802A8978(); fn_80298160(); fn_80288A20(); fn_802A1794();
    fn_8028A92C(); fn_8028CF64(); fn_80297980(); fn_80294CC4(); WaterPool_StepAll();
    updateEffectRecords(); fn_80292698(); fn_802A0B50(); fn_802A4C60(); fn_801E7E24();
    fn_802AB628(); fn_802885F0(); fn_802887EC(); fn_802885C0();
}

/* Runs shutdown/cleanup steps for this subsystem; mode 1 only does a conditional part. */
void fn_802879E4(s32 mode) {
    if (mode == 1) {
        if ((u8)lbl_8055F6BC != 0) fn_8028CFB0();
    } else {
        fn_8028CFB0(); fn_802A0B54(); fn_801B8820(); fn_80161AEC(); fn_802A8DE8(); fn_802AB6D0();
    }
}

#pragma cplusplus on
extern "C" void fn_80287A34(void) {
    /* Reset gameplay subsystems after a race: refresh the boost manager's color
       lists, clear the decal draw list, then ping the arena master (+0x48 slot). */
    struct ArenaMaster {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void postRaceReset();
    };
    extern void fn_801E12A4(void);
    extern void fn_802A1548(void);
    extern void *fn_801B83A0(void);
    fn_801E12A4();
    fn_802A1548();
    ((ArenaMaster *)fn_801B83A0())->postRaceReset();
}
#pragma cplusplus off
void fn_80287A6C(s32 mode) {
    /* Dispatch a per-mode update/reset across subsystems; mode 1 is gated by lbl_8055F6BC. */
    if (mode == 1 && (u8)lbl_8055F6BC == 0) return;
    fn_80294CC8(mode); fn_801B8834(); fn_802A1584(); fn_8029C2D4();
    fn_8028A9BC(mode); fn_8028E240(mode); fn_80288A1C(mode); fn_802A17FC(mode);
    fn_80298124(mode); fn_8029F300(); fn_802A7C68(); fn_802AB6D4();
}

/* Runs the virtual method 3 update pass over both global object collections:
   fn_80292864 walks the main object list, fn_8028A9F4 handles the effect object
   and the 8-slot table. The forwarded argument is unused by both callees. */
void fn_80287AF0(void* unused) {
    fn_8028A9F4(fn_80292864(unused));
}

s32 fn_80287B14(void) {
    /* Return the active object count from the global object-pool descriptor (the word at +0x04). */
    #define sObjectPool lbl_804B3150
    return ((s32 *)sObjectPool)[1];
    #undef sObjectPool
}

#pragma dont_inline on
s32 fn_80287B24(s32 objectIndex) {
    // Address of the object at objectIndex in the global pool of 0x160-byte records (base at lbl_804B3150).
    return ((s32*)lbl_804B3150)[0] + objectIndex * 0x160;
}
#pragma dont_inline reset

#define gCallbackCount lbl_8055F6C0 /* number of registered per-car callbacks */
#define gCallbackList  lbl_804B31E0 /* array of registered callback pointers */
/* Register a per-car callback: append its pointer to the global callback list. */
void fn_80287B38(s32 callback) {
    s32 index = gCallbackCount;
    ((s32 *)gCallbackList)[index] = callback;
    gCallbackCount = index + 1;
}

extern u8 lbl_804B3150[12];
extern s32 lbl_8055F6C0;
extern s32 lbl_804B31E0[];
/* Void-signature thunk that tail-calls the module's RNG step (fn_80288870).
 * The generated value stays in r3, so callers cast this to an unsigned-int
 * function pointer to read the random number despite the void signature. */
void fn_80287B58(void) {
    fn_80288870();
}

#pragma dont_inline on
s32 fn_80287B5C(s32 range) {
    /* Returns a pseudo-random integer in [0, range) from the game's global LCG. */
    unsigned int value = ((unsigned int (*)(void))fn_80287B58)();
    return value % (unsigned int)range;
}
#pragma dont_inline reset

s32 fn_80287B94(s32 min, s32 max) {
    /* Return a pseudo-random integer in [min, max). */
    return min + fn_80287B5C(max - min);
}

#pragma push
#pragma processor 750
#pragma scheduling 603
f32 fn_80287BC8(f32 min, f32 max) {
    /* Return a pseudo-random float in [min, max]: take a 17-bit sample of the
     * global RNG, scale it to [0,1] with lbl_80564250 (131071.0f), and
     * interpolate between the two bounds. */
    unsigned int random;
    f32 span;
    f32 fraction;
    random = ((unsigned int (*)(void))fn_80288870)() & 0x1FFFF;
    span = max - min;
    fraction = (f32)random / lbl_80564250;
    return min + span * fraction;
}
#pragma pop
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
/* Construct a per-car effect-table entry: zero its 0x28-byte record and return it. */
void *fn_80287C30(void *arg0) {
    typedef struct { s32 handle; u8 values[0x20]; s32 tail; } EffectEntry;
    EffectEntry *entry = (EffectEntry *)arg0;
    entry->handle = 0;
    memset(entry->values, 0, sizeof(entry->values));
    entry->tail = 0;
    return arg0;
}
/* If the object is non-null, release its owned resource handle at offset 0, clear it, and optionally free the object when arg1 > 0. */
void *fn_80287C80(void *object, s32 shouldFree) {
    if (object != 0) {
        if (*(s32 *)object != 0) {
            releaseValueFile(*(s32 *)object);
            *(s32 *)object = 0;
        }
        if (shouldFree > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

#pragma dont_inline on
void fn_80287CE8(int effectSlot, void *carName, int effectId, int flags) {
    char path[0x40];
    /* Load a car's "<name>.car/efx.val" effect file into its table slot, then parse it. */
    sprintf(path, lbl_80348A20, carName);
    if (fn_8012C33C(path) != 0) {
        *(void **)effectSlot = (void *)getValueFile(path);
    }
    fn_80287D70((void *)effectSlot, effectId, flags);
}
#pragma dont_inline reset
  
  #pragma scheduling invalid_target
void fn_80287D70(void *arg0, int arg1, int arg2) {
    char name[0x20];
    s32 mask = arg2 & 0x100000;
    const char *format = mask ? lbl_80348A30 : lbl_80348A40;

    if (mask) {
        *(volatile int *)((char *)arg0 + 0x24) = 0;
        return;
    }

    do {
        sprintf(name, format, arg2 + 1);
        if (((int (*)(int, char *, int *))fn_801E2CCC)(
                arg1, name,
                (int *)((char *)arg0 +
                        (*(volatile int *)((char *)arg0 + 0x24) << 2) + 4)) == 0) {
            return;
        }
        ++*(volatile int *)((char *)arg0 + 0x24);
        arg2 = *(volatile int *)((char *)arg0 + 0x24);
    } while (arg2 < 8);
}
#pragma scheduling on

#pragma scheduling on
extern void fn_801346B4(void *, s32, s32);
extern s32 fn_8012C33C(const char *);
extern s32 getValueFile(const char *);
extern void fn_80287D70(void *, s32, s32);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80348A40[];
extern const char lbl_80348A30[];
extern const char lbl_80348A20[];
#pragma push
#pragma cplusplus on
extern "C" void fn_80287E80(void **objectPtr, s32 nameSource) {
    /* Build a sanitized 64-byte name and pass it to the object's first virtual method. */
    class Obj {
    public:
        virtual void f(void *);
    };
    char nameBuffer[0x40];
    Obj *obj;
    fn_801346B4(nameBuffer, 0x40, nameSource);
    obj = (Obj *)*objectPtr;
    obj->f(nameBuffer);
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus on
extern "C" Vec3i_80287F90 fn_80287ED0(void **__restrict objectPtr, s32 featureId, const char *name) {
    struct ModelInterface {
        virtual void *getFeature(s32);
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual Vec3i_80287F90 getNamedVector(const char *);
    };
#define kUnsupportedModel lbl_80348A4C /* "efx: this model doesn't support '%s'" */
    /* RealName: GetModelEffectVector. Fetch the requested feature of a model
       interface and return that feature's named vector; panic if the model
       does not support the feature. */
    ModelInterface *model = *(ModelInterface **)objectPtr;
    if (model == 0 || model->getFeature(featureId) == 0) {
        Abend_Panic(kUnsupportedModel, featureId);
    }
    model = *(ModelInterface **)objectPtr;
    return ((ModelInterface *)model->getFeature(featureId))->getNamedVector(name);
#undef kUnsupportedModel
}
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" Vec3i_80287F90 fn_80287F90(void **arg1, s32 arg2, s32 arg3, s32 *src) {
    struct Ifc {
        virtual void *f0(s32);
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    struct Ifc2 {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual Vec3i_80287F90 f12(s32, s32 *);
    };
    s32 sp8[3];
    s32 a;
    s32 b;
    s32 c;
    Ifc *obj = *(Ifc **)arg1;
    if (obj == 0 || obj->f0(arg2) == 0) {
        Abend_Panic(lbl_80348A4C, arg2);
    }
    c = src[2];
    b = src[1];
    a = src[0];
    sp8[0] = a;
    obj = *(Ifc **)arg1;
    sp8[1] = b;
    sp8[2] = c;
    return ((Ifc2 *)obj->f0(arg2))->f12(arg3, sp8);
}
#pragma cplusplus off
#pragma use_lmw_stmw reset
s32 fn_80288060(s32 table, s32 index) {
    /* Return element `index` from the 4-byte-entry table whose data starts at table+4. */
    return *(s32 *)(table + (index << 2) + 4);
}

/* Looks up the per-car effect entry for the given instance pointer and forwards the request. */
void fn_80288070(s32 instancePtr, s32 arg1, s32 arg2) {
    s32 index = (instancePtr - lbl_8055F6C4) / 40;
    s32 effectId;
    if ((unsigned int)index < 8U)
        effectId = lbl_80488648[index];
    else
        effectId = 0;
    effectId = fn_801EE0C8(effectId);
    ((s32 (*)(s32, s32, s32))fn_801E2CCC)(effectId, arg1, arg2);
}

void fn_802880F4(void) {
    /* Initializes the per-car effect table from the active car entries. */
    extern int fn_801EA994(void);
    extern int fn_8012850C(int, const char *, int);
    extern int fn_8002F37C(int, void *, void *, int, int);
    extern int fn_801EA9A0(int);
    extern int fn_801EE0C8(int);
    extern int lbl_80488648[];
    extern int lbl_8055F6C4;
    extern char lbl_80348A74[];
    int entryCount = fn_801EA994();
    int tableBuffer = fn_8012850C(entryCount * 0x28 + 0x10, lbl_80348A74, entryCount * 0x28);
    lbl_8055F6C4 = fn_8002F37C(tableBuffer, fn_80287C30, fn_80287C80, 0x28, entryCount);
    {
        int *idCursor = lbl_80488648;
        int entryOffset;
        int index;
        index = 0;
        entryOffset = 0;
        goto test;
    loop:
        {
            int carEntry = fn_801EA9A0(index);
            int tableId;
            int effectId;
            if ((unsigned)index < 8)
                tableId = *idCursor;
            else
                tableId = 0;
            effectId = fn_801EE0C8(tableId);
            fn_80287CE8(lbl_8055F6C4 + entryOffset,
                        (void *)(carEntry + 0x88), effectId,
                        *(int *)(carEntry + 0xB8));
        }
        idCursor++;
        entryOffset += 0x28;
        index++;
    test:
        entryCount = fn_801EA994();
        if (index < entryCount)
            goto loop;
    }
}

void fn_802881D4(void) {
    /* Tear down the global per-car effect table: run the entry destructor
       (fn_80287C80) over every element and free the array, then clear it. */
    fn_8002F6AC(lbl_8055F6C4, fn_80287C80);
    lbl_8055F6C4 = 0;
}

s32 fn_80288208(s32 index) {
    /* Return the address of the 0x28-byte per-car effect table entry at index. */
    return lbl_8055F6C0+index*0x28;
}

extern char lbl_80348A80[];
extern void fn_8028829C(void);
extern void fn_80288218(int);
/* Allocates and initializes the global object pool at lbl_804B3150 for fn_801EA994() entries of 0x160 bytes each, constructing elements with fn_8028829C and zeroing the storage. */
void fn_80288218(int arg0) {
    int count = fn_801EA994();
    int size = count * 0x160;
    int memory = fn_8012850C(size + 0x10, lbl_80348A80, size);
    *(void **)lbl_804B3150 = (void *)fn_8002F37C(memory, fn_8028829C, 0, 0x160, count);
    count = fn_801EA994();
    *(int *)(lbl_804B3150 + 4) = count;
    lbl_804B3150[8] = 0;
    memset(*(void **)lbl_804B3150, 0, count * 0x160);
}

/* No-op element-constructor callback for fn_8002F37C: fn_80288218 passes it
 * when allocating the 0x160-byte car snapshot records at lbl_804B3150, which
 * are zeroed by memset afterwards and need no per-element initialization. */
void fn_8028829C(void) {}

void fn_802882A0(void) {
    /* Free the object pool at lbl_804B3150 (storage at pool-0x10) and clear
       its pointer, count, and flag fields. */
    if (*(s32 *)lbl_804B3150)
        fn_80128670(*(s32 *)lbl_804B3150 - 0x10);
    *(s32 *)lbl_804B3150 = 0;
    *(s32 *)(lbl_804B3150 + 4) = 0;
    lbl_804B3150[8] = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Rebuild the global per-car snapshot pool: copy each car's physics state, normalized velocity, flags and four wheel records into its 0x160-byte snapshot slot. */ void CarSnapshotPool_rebuild(void) {
    extern u8 *fn_801EA9CC(s32);
    extern f32 PSVECDotProduct(void *, void *);
    extern double fn_8002F234(double); /* sqrt */
    extern f32 fn_801EE0D0(void *, s32);
    extern f32 lbl_80564264, lbl_80564260;
    extern f32 lbl_80558DC4[];
    /* Rebuilds the global pool of per-car snapshot records (gCarSnapshotPool:
     * record base at +0, record count at +4, update flag at +8, 0x160-byte
     * records).  For every CarMgr car it takes the car's live physics state
     * (CarMgrEntry+8) and its render object (gCarRenderObjects, by slot) and
     * writes one record:
     *   0x00  the render object's 9-word identity block (its +0x04)
     *   0x24  the render object's world position (its +0x28), as three words
     *   0x30  a flag short of the physics state (+0x30)
     *   0x34  velocity (state +0x70), and its normalized copy at 0x40 - zero
     *         when the squared length is under the float epsilon
     *   0x4C  physics scalars: state +0x2D4, +0x64, +0x38, +0x28C, +0x298,
     *         +0x29C and +0x2D8
     *   0x68  flags: 1 car in play, 2 all four wheels in contact, 4 and 8 from
     *         bits 6 and 5 of the state's flag word at +0x6E
     *   0x6C  a word of the render object (+0x3EC)
     *   0x70  four 0x3C-byte wheel records: the wheel's 3x3 orientation and
     *         position, its contact byte and word, and the elevation of the
     *         ground object the render object keeps for that wheel (+0x4D4)
     * The pool's update flag is cleared while the records are rewritten. */
    #define ZERO_F        lbl_80564264 /* 0.0f */
    #define ONE_F         lbl_80564260 /* 1.0f */
    #define FLOAT_EPSILON lbl_80558DC4[0] /* "too small to divide by" */
    #define gCarSnapshotPool  lbl_804B3150
    #define gCarRenderObjects lbl_80488648
    typedef struct { s32 words[9]; } IdentityBlock; /* render object +0x04 */
    typedef struct { s32 words[3]; } PositionBlock; /* render object +0x28 */
    u8 **renderObjectSlot;
    u8 *wheelSrc;
    u8 *wheelDst;
    u8 *snapshot;
    s32 carIndex;
    u8 *physics;
    u8 *renderObject;
    s32 allWheelsGrounded, wheel;
    f32 one;
    f32 zero;
    zero = ZERO_F;
    snapshot = *(u8 **)gCarSnapshotPool;
    one = ONE_F;
    gCarSnapshotPool[8] = 0;
    renderObjectSlot = (u8 **)gCarRenderObjects;
    carIndex = 0;
    while (carIndex < *(s32 *)(gCarSnapshotPool + 4)) {
        u8 *carRecord = fn_801EA9CC(carIndex);
        s32 flags;
        physics = *(u8 **)(carRecord + 8);
        if ((unsigned)carIndex < 8) renderObject = *renderObjectSlot;
        else renderObject = 0;
        *(IdentityBlock *)snapshot = *(IdentityBlock *)(renderObject + 4);
        *(PositionBlock *)(snapshot + 0x24) = *(PositionBlock *)(renderObject + 0x28);
        *(short *)(snapshot + 0x30) = *(short *)(physics + 0x30);
        *(f32 *)(snapshot + 0x34) = *(f32 *)(physics + 0x70);
        *(f32 *)(snapshot + 0x38) = *(f32 *)(physics + 0x74);
        *(f32 *)(snapshot + 0x3C) = *(f32 *)(physics + 0x78);
        if (!((f32)__fabs(PSVECDotProduct(physics + 0x70, physics + 0x70)) <= FLOAT_EPSILON)) {
            f32 invLength = one / (f32)fn_8002F234(PSVECDotProduct(physics + 0x70, physics + 0x70));
            *(f32 *)(snapshot + 0x40) = *(f32 *)(physics + 0x70) * invLength;
            *(f32 *)(snapshot + 0x44) = *(f32 *)(physics + 0x74) * invLength;
            *(f32 *)(snapshot + 0x48) = *(f32 *)(physics + 0x78) * invLength;
        } else {
            *(f32 *)(snapshot + 0x40) = zero;
            *(f32 *)(snapshot + 0x44) = zero;
            *(f32 *)(snapshot + 0x48) = zero;
        }
        *(f32 *)(snapshot + 0x4C) = *(f32 *)(physics + 0x2D4);
        *(f32 *)(snapshot + 0x50) = *(f32 *)(physics + 0x64);
        *(f32 *)(snapshot + 0x54) = *(f32 *)(physics + 0x38);
        *(f32 *)(snapshot + 0x58) = *(f32 *)(physics + 0x28C);
        *(s32 *)(snapshot + 0x5C) = *(s32 *)(physics + 0x298);
        *(s32 *)(snapshot + 0x60) = *(s32 *)(physics + 0x29C);
        *(s32 *)(snapshot + 0x64) = *(s32 *)(physics + 0x2D8);
        *(s32 *)(snapshot + 0x6C) = *(s32 *)(renderObject + 0x3EC);
        flags = carRecord[0] != 0;
        wheelSrc = physics; wheelDst = snapshot; allWheelsGrounded = 1; wheel = 0;
        do {
            *(f32 *)(wheelDst + 0x70) = *(f32 *)(wheelSrc + 0x7C);
            *(f32 *)(wheelDst + 0x74) = *(f32 *)(wheelSrc + 0x80);
            *(f32 *)(wheelDst + 0x78) = *(f32 *)(wheelSrc + 0x84);
            *(f32 *)(wheelDst + 0x7C) = *(f32 *)(wheelSrc + 0x88);
            *(f32 *)(wheelDst + 0x80) = *(f32 *)(wheelSrc + 0x8C);
            *(f32 *)(wheelDst + 0x84) = *(f32 *)(wheelSrc + 0x90);
            *(f32 *)(wheelDst + 0x88) = *(f32 *)(wheelSrc + 0x94);
            *(f32 *)(wheelDst + 0x8C) = *(f32 *)(wheelSrc + 0x98);
            *(f32 *)(wheelDst + 0x90) = *(f32 *)(wheelSrc + 0x9C);
            *(f32 *)(wheelDst + 0x94) = *(f32 *)(wheelSrc + 0xAC);
            *(f32 *)(wheelDst + 0x98) = *(f32 *)(wheelSrc + 0xB4);
            *(s32 *)(wheelDst + 0x9C) = *(s32 *)(wheelSrc + 0xDC);
            *(u8 *)(wheelDst + 0xA0) = *(u8 *)(wheelSrc + 0xE0);
            *(s32 *)(wheelDst + 0xA8) = *(s32 *)(wheelSrc + 0xE4);
            *(f32 *)(wheelDst + 0xA4) = fn_801EE0D0(renderObject, wheel);
            allWheelsGrounded = allWheelsGrounded && wheelSrc[0xE0];
            wheel++; wheelSrc += 0x6c; wheelDst += 0x3c;
        } while (wheel < 4);
        if (allWheelsGrounded) flags |= 2;
        { unsigned short stateBits = *(unsigned short *)(physics + 0x6e);
          if (stateBits & 0x40) flags |= 4;
          if (stateBits & 0x20) flags |= 8;
        }
        *(s32 *)(snapshot + 0x68) = flags;
        snapshot += 0x160; renderObjectSlot++; carIndex++;
    }
    #undef gCarRenderObjects
    #undef gCarSnapshotPool
    #undef FLOAT_EPSILON
    #undef ONE_F
    #undef ZERO_F
}
#pragma pop

/* No-op subsystem initializer: called last in the global init sequence
 * (fn_8028797C); this build leaves it empty. */
void fn_802885C0(void) {}

#pragma push
#pragma scheduling off
s32 fn_802885C4(void *arg0, void *arg1) {
    return (s32)(lbl_80564268 * (*(f32 *)((u8 *)arg0 + 8) - *(f32 *)((u8 *)arg1 + 8)));
}

extern s32 fn_801E85A4(void);
extern void *fn_801E8718(s32);
extern s32 fn_801E866C(s32);
extern f32 fn_801E88F0(s32);
extern s32 fn_801E8954(s32);
extern f32 PSVECSquareDistance(void *, void *);
extern u8 lbl_804B3160[];
extern s32 fn_802885C4(void *, void *);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma scheduling invalid_target
void fn_802885F0(void)
{
  struct Pair
  {
    s32 a;
    s32 b;
  };
  struct Entry
  {
    struct Pair first[4];
    s32 word8;
    struct Pair vecpair;
    s32 last;
  } local[4];
  s32 j;
  s32 flag;
  u8 *currentVector;
  s32 i;
  struct Entry *entry;
  s32 *id;
  u8 *result;
  s32 count;
  u8 *current;
  struct Entry *source;
  struct Entry *other;
  s32 ids[4];
  s32 *otherId;
  f32 scale;
  f32 scaleSquared;
  f32 best;
  f32 distance;
  f32 candidate;
  count = fn_801E85A4();
  entry = local;
  id = ids;
  for (i = 0; i < count; i++)
  {
    source = (struct Entry *) fn_801E8718(i);
    entry->first[0] = source->first[0];
    entry->first[1] = source->first[1];
    entry->first[2] = source->first[2];
    entry->first[3] = source->first[3];
    entry->word8 = source->word8;
    entry->vecpair = source->vecpair;
    entry->last = source->last;
    *id = fn_801E866C(i);
    entry++;
    id++;
  }

  result = lbl_804B3160;
  for (i = 0; i < (*((s32 *) (lbl_804B3150 + 4))); i++)
  {
    current = (u8 *) fn_80287B24(i);
    currentVector = current + 0x24;
    scale = fn_801E88F0(0);
    scaleSquared = scale * scale;
    distance = PSVECSquareDistance(currentVector, &local[0].vecpair);
    best = distance * scaleSquared;
    flag = 0;
    if ((i == ids[0]) && (fn_801E8954(0) != 0))
    {
      flag = 1;
      other = &local[1];
      otherId = ids + 1;
      j = 1;
      while ((flag != 0) && (j < count))
      {
        scale = fn_801E88F0(j);
        scaleSquared = scale * scale;
        distance = PSVECSquareDistance(currentVector, &other->vecpair);
        candidate = distance * scaleSquared;
        best = (best < candidate) ? (best) : (candidate);
        flag = 0;
        if ((i == (*otherId)) && (fn_801E8954(j) != 0))
        {
          flag = 1;
        }
        other++;
        otherId++;
        j++;
      }

    }
    if (flag != 0)
    {
      *((s32 *) result) = (s32) current;
      *(result + 4) = i;
      *((f32 *) (result + 8)) = best;
      result[0xC] = flag;
      result += 0x10;
    }
  }

  if (source->first || count)
  {
    qsort(lbl_804B3160, *((s32 *) (lbl_804B3150 + 4)), 0x10, (int (*)(const void *, const void *)) fn_802885C4);
  }
  else
  {
    qsort(lbl_804B3160, *((s32 *) (lbl_804B3150 + 4)), 0x10, (int (*)(const void *, const void *)) fn_802885C4);
  }
}
#pragma scheduling on
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma ppc_psq_save on
#pragma pop
void fn_802887EC(void) {
    u8 *base = lbl_804B3150;
    void (**callback)(void *, s32) = (void (**)(void *, s32))(base + 0x90);
    s32 *data = (s32 *)((u8 *)callback - 0x90);
    s32 i;
    for (i = 0; i < lbl_8055F6C0; i++)
        (callback[i])(base + 0x10, data[1]);
}
#pragma scheduling on
/* Set the seed of the module's 31-bit LCG random generator (state lbl_8055F6C8, advanced by fn_80288870). */
void fn_80288868(void* seed) {
    lbl_8055F6C8 = seed;
}

/* Constants of the module's random generator: a 31-bit linear congruential
 * generator whose state is lbl_8055F6C8. */
#define RNG_MULTIPLIER 0x12B9B0A1u
#define RNG_INCREMENT 0x1CCE8AC1u
#define RNG_MASK 0x7FFFFFFFu

/* One step of the module's random generator: advance the 31-bit linear
 * congruential state (lbl_8055F6C8) by state * RNG_MULTIPLIER + RNG_INCREMENT,
 * keep the low 31 bits as the new state and return it; callers mask the bits
 * they need (e.g. & 0x1FFFF for a random fraction). */
unsigned int fn_80288870(void) {
    unsigned int next = (unsigned int)lbl_8055F6C8 * RNG_MULTIPLIER + RNG_INCREMENT;
    unsigned int value = next & RNG_MASK;
    lbl_8055F6C8 = (void *)value;
    return value;
}

#pragma push
#pragma cplusplus on
extern "C" s32 fn_80287E20(void ***arg0, s32 arg1) {
    /* Look up the stored object and, if present, invoke its virtual method at
     * vtable slot 2 with a 0x40-byte name buffer copied from arg1 (via
     * fn_801346B4). Returns the method's result, or 0 if no object is stored. */
    class Obj {
    public:
        virtual void f0(void *);
        virtual void f1(void *);
        virtual s32 f2(void *);
    };
    char name[0x40];
    Obj *obj;

    fn_801346B4(name, 0x40, arg1);
    obj = (Obj *)*arg0;
    if (obj != 0) return obj->f2(name);
    return 0;
}
#pragma cplusplus reset
#pragma pop
