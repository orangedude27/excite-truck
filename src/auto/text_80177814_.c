#include <types.h>
#include <string.h>
#pragma ppc_psq_save off
extern void *lbl_8055E430;
extern char lbl_8055E45D;
extern char lbl_8055E45F;
extern int lbl_8055E450;
extern int lbl_8055E8F8;
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern unsigned char lbl_8055E45E;
extern int lbl_80430870[];
extern int lbl_80430590[];
extern int lbl_804305A0[];
extern int lbl_80430830[];

extern long fn_80178C1C(long *);
extern float lbl_80561B60;
void fn_80179EE8(void*, unsigned int);
void fn_80128668(void*);
extern unsigned char lbl_8055E46C;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055A304;
void fn_801DCEC8(int arg0, float arg1);
void fn_801DCEDC(int arg0, float arg1);
extern float lbl_804305D4[];
extern float lbl_80430700[];
extern float lbl_80561B48;
void fn_802E8518(int arg0);
extern int lbl_8055E3C0;
extern unsigned char lbl_8055E3BD;
int fn_801CF064(void);
int fn_8018FD38(void);
extern void *lbl_804340C0[];
extern void **lbl_8055E434;
extern int lbl_8055E438;
extern int lbl_8055E468;
extern int lbl_8055E448;
extern unsigned char lbl_8055E44C;
__declspec(section ".data") extern long lbl_80331938;
__declspec(section ".data") extern long lbl_8033192C;
extern void fn_801AFD20(void *);
extern void fn_8017ACCC(void);
extern void fn_8018A180(void);
int KERNEL_GetTimeMs(void);
extern int lbl_8055E464;
void fn_80177814(int *arg0)
{
  *arg0 = (KERNEL_GetTimeMs() + (lbl_8055E464 & 0xFFFF)) % 30000;
  lbl_8055E464 = (unsigned short) ((*arg0) + (0x9947 & 0xFF));
  arg0[1] = (KERNEL_GetTimeMs() + (lbl_8055E464 & 0xFFFF)) % 30000;
  lbl_8055E464 = (unsigned short) (arg0[1] + 0x2F1CD);
}

#pragma dont_inline on
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801778C0(void) {
    /* Rebuild the compact array of active objects: scan the global object list,
       keeping an entry only when both of its virtual enable checks pass, and
       store survivors in lbl_804340C0 with their count in lbl_8055E468. */
    lbl_8055E468 = 0;
    struct Obj {
        virtual int v0();
        virtual int v1();
        virtual int v2();
        virtual int v3();
        virtual int v4();
        virtual int v5();
        virtual int v6();
        virtual int v7();
        virtual int v8();
        virtual int v9();
        virtual int v10();
        virtual int v11();
        virtual int v12();
        virtual int v13();
        virtual int v14();
        virtual int v15();
        virtual int v16();
        virtual int v17();
    };
    void **activeList = &lbl_804340C0[0];
    int slotOffset = 0;
    int listIndex = 0;
    Obj *obj;
    for (; listIndex < lbl_8055E438; slotOffset += 4, listIndex++) {
        obj = (Obj *)*(void **)((char *)lbl_8055E434 + slotOffset);
        if (obj->v15() != 0 && obj->v14() != 0) {
            activeList[lbl_8055E468++] = (void *)obj;
        }
    }
}
#pragma dont_inline off
#pragma cplusplus off
/* Constant "return false" predicate, paired with fn_80177988 (always true);
 * serves as a default boolean callback. */
long fn_80177980(void) {
    return 0;
}

/* Constant "return true" predicate, paired with fn_80177980 (always false);
 * serves as a default boolean callback. */
long fn_80177988(void) {
    return 1;
}

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
/* Zero-initialize the four parallel 75-entry weight tables: lbl_80430700 and
   lbl_804305D4 directly, terrainWeights / lbl_804425DC via the setters. */
void fn_80177990(void) {
    float zero = 0.0f;
    float *weightA = &lbl_80430700[0];
    float *weightB = &lbl_804305D4[0];
    int i;
    for (i = 0; i < 0x4b; i++) {
        *weightA = zero;
        *weightB = zero;
        fn_801DCEC8(i, zero);
        fn_801DCEDC(i, lbl_80561B48);
        weightA++;
        weightB++;
    }
}
#pragma pop

#pragma dont_inline on
void fn_80177A18(void) {
#define CenterSteering fn_802E8518
    int controller;

    /* Center the steering value of each of the four controllers. */
    controller = 0;
    do {
        CenterSteering(controller);
        controller += 1;
    } while (controller < 4);
#undef CenterSteering
}

/* Update sound/request state: clear pending state when conditions are met, run one-shot init on enter, and reset to idle. */
void fn_80177A54(void) {
    if (lbl_8055E3C0 == 2 && fn_801CF064() != 0 && fn_8018FD38() != 0) {
        lbl_8055E3C0 = 0;
    }
    switch (lbl_8055E3C0) {
    case 1:
        if (lbl_8055E3BD == 0) {
            fn_80177A18();
        }
        lbl_8055E3BD = 1;
        break;
    case 2:
        lbl_8055E3BD = 0;
        break;
    default:
        break;
    }
    lbl_8055E3C0 = 0;
}

void expireReplayHistory(int forceShift, int mode) {
    /* Drop the oldest record of the 8-slot timed replay history when it has
     * aged out, is timestamped in the future, or a forced shift is requested
     * while the last slot is still occupied. */
    typedef struct { unsigned char b[0x100]; } Bytes;
    typedef struct { Bytes data; float time; int value; } Entry;
    extern Entry lbl_80433880[8];
    extern float lbl_80561B4C;
    extern float lbl_8055E3C8;
    int slot;

    if ((signed char)lbl_80433880[0].data.b[0] == 0) return;
    if (lbl_8055E3C8 > lbl_80561B4C + lbl_80433880[0].time || lbl_8055E3C8 < lbl_80433880[0].time
        || (forceShift != 0 && (signed char)lbl_80433880[7].data.b[0] != 0)) {
        for (slot = 0; slot < 7; slot++) {
            lbl_80433880[slot].data = lbl_80433880[slot + 1].data;
            lbl_80433880[slot].time = lbl_80433880[slot + 1].time;
            lbl_80433880[slot].value = lbl_80433880[slot + 1].value;
        }
        memset(&lbl_80433880[7], 0, sizeof(Entry));
    }
}

#pragma dont_inline off

#pragma cplusplus on
extern "C" void fn_80177CEC(void) {
    /* Orthonormalize one object's basis vectors (forward/right/up) from the rotating list. */
    class RotationObject {
    public:
        virtual void f0();
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
        virtual void f12();
        virtual void f13();
        virtual int isValid();
    };
    int index = lbl_8055E43C;
    RotationObject *object;
    Vec right;
    Vec up;
    Vec forward;
    float a, b, c, d, e, f;
    if (index >= lbl_8055E438) { index = 0; lbl_8055E43C = 0; }
    object = (RotationObject *)lbl_8055E434[index];
    if (object != 0 && object->isValid() != 0) {
        c = *(float *)((char *)object + 0x44);
        b = *(float *)((char *)object + 0x40);
        a = *(float *)((char *)object + 0x3C);
        forward.x = a; forward.y = b; forward.z = c;
        f = *(float *)((char *)object + 0x5C);
        e = *(float *)((char *)object + 0x58);
        d = *(float *)((char *)object + 0x54);
        right.x = d; right.y = e; right.z = f;
        PSVECCrossProduct(&right, &forward, &up);
        PSVECNormalize(&forward, &forward);
        PSVECNormalize(&up, &up);
        PSVECCrossProduct(&forward, &up, &right);
        *(float *)((char *)object + 0x3C) = forward.x;
        *(float *)((char *)object + 0x40) = forward.y;
        *(float *)((char *)object + 0x44) = forward.z;
        *(float *)((char *)object + 0x48) = up.x;
        *(float *)((char *)object + 0x4C) = up.y;
        *(float *)((char *)object + 0x50) = up.z;
        *(float *)((char *)object + 0x54) = right.x;
        *(float *)((char *)object + 0x58) = right.y;
        *(float *)((char *)object + 0x5C) = right.z;
    }
    lbl_8055E43C++;
}

#pragma cplusplus on
extern "C" int fn_801B526C(void);
extern "C" void fn_801AD5F0(void);
extern "C" void fn_80186DE8(void);
extern "C" void fn_801D0F38(void);
extern "C" void fn_801B535C(void**, int);
extern "C" void fn_801B50B4(void**, int);
#pragma scheduling invalid_target
extern "C" void fn_80177E14(void) {
    /* Per-frame update of the active sound/effect list: in normal mode run setup helpers and each element's
       pre-audio hook, then process audio (fn_801B535C/Fn_801B50B4), then run each element's post-audio hook. */
    class SoundElement {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void preAudio(); virtual void postAudio();
    };
    int elementIndex;
    SoundElement **element;
    if (fn_801B526C() == 0) {
        fn_801AD5F0();
        fn_80186DE8();
        fn_801D0F38();
        element = (SoundElement **)lbl_804340C0;
        for (elementIndex = 0; elementIndex < lbl_8055E468; element++, elementIndex++) {
            (*element)->preAudio();
        }
        fn_801B535C(lbl_8055E434, lbl_8055E438);
    } else {
        fn_801B50B4(lbl_8055E434, lbl_8055E438);
    }
    element = (SoundElement **)lbl_804340C0;
    for (elementIndex = 0; elementIndex < lbl_8055E468; element++, elementIndex++) {
        (*element)->postAudio();
    }
}
#pragma scheduling on

#pragma cplusplus off
#pragma dont_inline on
/* If the pending player reset flag is set, run reset handling for each active player slot (0-7) and clear the flag. */
void fn_80177EE4(void) {
    int playerIndex;
    if (lbl_8055E44C != 0) {
        for (playerIndex = 0; playerIndex < 8; playerIndex++) {
            if (getRegisteredObject(playerIndex) != 0) {
                fn_8018A180();
            }
        }
        lbl_8055E44C = 0;
    }
}
#pragma dont_inline off

void fn_80176A6C(void);
void fn_80176A34(int);
void fn_8026C014(int);
void expireReplayHistory(int, int);
void fn_801777B4(void);
int isTileCaptureActive(void);
void fn_80265D84(void);
void fn_80265D88(void);
void fn_801B2364(void);
void fn_8026B6E4(void);
void fn_801CEDDC(void);
void reportSoeventSpawns(void);
void musicPreRaceUpdate(void);
void fn_801DEFE0(void);
void fn_801EA1F0(void);
int fn_801B526C(void);
void fn_801B8BF4(void);
int fn_801C5B60(void);
void fn_801B841C(void);
void fn_801C4CE8(void);
void fn_801D47F8(void);
void fn_80134A8C(void);
void fn_80134B50(void);
void fn_80177CEC(void);
void fn_80177EE4(void);
void fn_8017FF4C(float);
void fn_801778C0(void);
void fn_801E22D0(void *, int);
void fn_80177E14(void);
void fn_801E1E64(void);
void fn_801B24B8(void);
void fn_801279D0(void);
void fn_80178DBC(int, float);
double sin(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80177F40(void) {
    extern void *lbl_8055E458;
    extern unsigned char lbl_8055E45C;
    extern int lbl_8055A300;
    extern long lbl_8055E3C4;
    extern float lbl_8055E3C8;
    extern int lbl_8055E488;
    extern float lbl_80561B50, lbl_80561B54, lbl_80561B58, lbl_80561B5C;
    int other;
    unsigned char saved;
    char *base = (char *)lbl_80430590;
    unsigned active;
    unsigned char flag;
    float *dst;
    float *src;
    int i;

    fn_80176A6C();
    fn_80177A54();
    lbl_8055E458 = (void *)(((int)lbl_8055E458 + 1) & ~((int)(-(int)lbl_8055E3BD | lbl_8055E3BD) >> 31));
    fn_8026C014(1);
    lbl_8055E45D = lbl_8055E45C;
    lbl_8055E45F = lbl_8055E45E;
    expireReplayHistory(0, lbl_8055E45C);
    saved = lbl_8055E3BD;
    active = isTileCaptureActive();
    if (active != 0) lbl_8055E3BD = 1;
    flag = lbl_8055E3BD;
    *(int *)(base + 0x2E0) = 0;
    fn_80265D84();
    fn_801B2364();
    fn_8026B6E4();
    fn_801CEDDC();
    reportSoeventSpawns();
    musicPreRaceUpdate();
    fn_801DEFE0();
    if (flag) fn_801EA1F0();
    other = fn_801B526C();
    if (other != 0 || flag == 0) {
        int off, zero, cur;
        float scale = lbl_80561B50;
        dst = (float *)(base + 0x170);
        src = (float *)(base + 0x44);
        for (i = 0; i < 0x4B; i++) {
            fn_801DCEDC(i, scale * (*src - *dst));
            *dst = *src;
            dst++;
            src++;
        }
        cur = lbl_8055A300;
        if (cur >= 0 && cur < 0x4B) {
            float s = (float)sin(lbl_80561B54 * (lbl_8055E3C8 * lbl_80561B58));
            fn_80178DBC(cur, lbl_80561B5C + lbl_80561B5C * s);
        }
        fn_801B8BF4();
        if (fn_801C5B60() == 0) fn_801B841C();
        fn_801C4CE8();
        fn_801D47F8();
        fn_801EA1F0();
        if (other == 0) {
            if (fn_801C5B60() == 0) fn_80134A8C();
        } else {
            fn_80134B50();
        }
        fn_80177CEC();
        *(int *)(base + 0x22E8) = 0;
        fn_80177EE4();
        fn_8017FF4C(lbl_80561B60);
        fn_801778C0();
        if (!other) fn_801E22D0(base + 0x3B30, lbl_8055E468);
        fn_80177E14();
        off = 0;
        i = 0;
        zero = 0;
        while (lbl_8055E438 > i) {
            void **obj = *(void ***)((char *)lbl_8055E434 + off);
            char *r = ((char *(*)(void **))(*(char ***)obj)[0x3C / 4])(obj);
            if (r != 0) *(int *)(r + 0x1E4) = zero;
            off += 4;
            i++;
        }
        lbl_8055E488 = 0;
        fn_801E1E64();
    } else {
        fn_8017FF4C(lbl_80561B60);
    }
    fn_801B24B8();
    fn_80265D88();
    if (flag == 0) {
        fn_801777B4();
        fn_80176A34(lbl_8055E3C4 + 1);
    }
    fn_801279D0();
    if (active != 0) lbl_8055E3BD = saved;
}
#pragma pop
extern char jumptable_803318F8[];
#pragma dont_inline off
/* Constant getter in the game/mode code: always returns 0. */
long fn_801781B8(void) { return 0; }

#pragma scheduling invalid_target
int fn_801781C0(int modeId) {
    /* True when the game/mode id is one of the special modes 19, 21, 24, 26 or 31. */
    switch (modeId - 0x13) {
    case 0:
    case 2:
    case 5:
    case 7:
    case 12:
        return 1;
    default:
        return 0;
    }
}
#pragma scheduling on
unsigned char *fn_801781F4(long code) {
    /* Store a 32-bit four-character code in the static scratch buffer and
     * reverse its four bytes in place so it reads in order as a string. */
    volatile unsigned char *buf = &lbl_8055E46C;
    int b2, b0, b1, b3;
    *(volatile long *)buf = code;
    b0 = buf[0];
    b3 = buf[3];
    b1 = buf[1];
    b2 = buf[2];
    buf[0] = b3;
    buf[3] = b0;
    buf[1] = b2;
    buf[2] = b1;
    return (unsigned char *)buf;
}
#pragma dont_inline off

void fn_80178224(void) {
    /* Log a "NetCar" debug event (id 0x2780) via the ring buffer; if accepted, construct the NetCar task object. */
    if (fn_801284F8(0x2780, &lbl_8055A304) != 0)
        fn_801A6484();
}

#pragma scheduling on
/* Allocate the 0xD0-byte "PhobStatic" MemorySoundArchive and construct it.
   The freshly allocated object reaches the fn_8017ACCC constructor in r3. */
void fn_80178258(void) {
    if (fn_801284F8(0xD0, &lbl_8033192C) != 0) {
        fn_8017ACCC();
    }
}
#pragma scheduling on
/* Allocate the 0x1FC-byte "WheelPhob" DisposeCallbackManager and construct it
   through fn_801AFD20 (the new object stays in r3 for the constructor call). */
void fn_80178290(void) {
    void *manager = (void *)fn_801284F8(0x1FC, &lbl_80331938);
    if (manager != 0) {
        fn_801AFD20(manager);
    }
}
extern char lbl_80331944[];
extern char lbl_80338400[];
void *fn_8017B0B0(void *);
#pragma scheduling invalid_target
/* Creates a new MutablePhob (a movable physics object): asks the heap for its
 * 0x29C bytes under the tag "MutablePhob", runs the Phob constructor over the
 * storage and installs the MutablePhob vtable. Returns the new object, or 0 if
 * the allocation failed. */
void *fn_801782C8(void) {
    struct MutablePhob {
        void *vtable;
    };
#define heapAlloc       fn_801284F8
#define phobCtor        fn_8017B0B0
#define mutablePhobName lbl_80331944
#define mutablePhobVtbl lbl_80338400

    struct MutablePhob *object =
        (struct MutablePhob *)heapAlloc(0x29C, (void *)&mutablePhobName[0]);
    if (object != 0) {
        phobCtor((void *)object);
        object->vtable = &mutablePhobVtbl[0];
    }
#undef heapAlloc
#undef phobCtor
#undef mutablePhobName
#undef mutablePhobVtbl
    return (void *)object;
}
#pragma scheduling on

#pragma scheduling on
/* nw4hbm::snd::MemorySoundArchive scalar-deleting destructor: runs the base
 * destructor (fn_80179EE8 with shouldFree=0) and, if deleteFlags > 0, frees
 * the object storage (fn_80128668). Returns this. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017831C(long this_, long deleteFlags) {
    if (this_ != 0) {
        fn_80179EE8((void*)this_, 0);
        if (deleteFlags > 0) {
            fn_80128668((void*)this_);
        }
    }
    return this_;
}

extern char lbl_80331950[];
#pragma dont_inline on
/* Look up a provider by its four-character id in the table at lbl_80331950,
   an array of 0xC-byte records (id, reserved, create callback) terminated by a
   zero id.  Returns the matching record, or NULL when none matches. */
char *fn_80178374(long id) {
    char *entry = lbl_80331950;
    int entryId;

    while ((entryId = *(int *)entry) != 0) {
        if ((unsigned long)entryId == (unsigned long)id) {
            return entry;
        }
        entry += 0xC;
    }
    return NULL;
}

#pragma cplusplus on
extern "C" void *lbl_8055E454;
extern "C" void fn_80179D8C(void *, int);
extern "C" long Abend_Panic(const char *, long, ...);
#pragma cplusplus on
/* Create a stream-loaded game object from a serialized data block. Look up the provider registered for the four-character id at the head of the block, call its factory, record the block size on the new object and invoke its block-reading virtual method; panic with a formatted error if no provider or factory exists, or creation fails. */ extern "C" void **fn_801783A8(int *dataBlock, int blockSize) {
    struct Provider {
        int id;
        int reserved;
        void **(*create)(void);
    };
    struct Handler {
        virtual void run(int *);
    };
    struct Provider *provider;
    char *errorMessages;
    void **object;
    object = 0;
    errorMessages = jumptable_803318F8;
    lbl_8055E454 = dataBlock;
    provider = (struct Provider *)fn_80178374(*dataBlock);
    if (provider != 0) {
        if (provider->create != 0) {
            object = provider->create();
            if (object != 0) {
                fn_80179D8C(object, blockSize);
                ((struct Handler *)object)->run(dataBlock);
            } else {
                Abend_Panic(errorMessages + 0xF4, (long)fn_801781F4(*dataBlock));
            }
        } else {
            Abend_Panic(errorMessages + 0x110, (long)fn_801781F4(*dataBlock));
        }
    } else {
        Abend_Panic(errorMessages + 0x134, (long)fn_801781F4(*dataBlock));
    }
    lbl_8055E454 = 0;
    return object;
}
#pragma cplusplus off

#pragma dont_inline off

extern int fn_801E2640(void *, void *, void *, int, void *, void *, void *, int, int);
int fn_801784AC(void *start, void *end, void *outHit, int flags, void *outValue, void *outObject, int filter) {
    /* Collision raycast from start toward end against the global object list at
       lbl_804340C0 (count in lbl_8055E468); writes hit position/value/object to the out params. */
    return fn_801E2640(start, end, outHit, flags, outValue, outObject, &lbl_804340C0[0], lbl_8055E468, filter);
}

extern float lbl_80561B64;
#pragma scheduling invalid_target
s32 fn_801784DC(const Vec *position, f32 *outHeight, Vec *outNormal, s32 *outValue, s32 filter) {
    /* Cast a ray straight down from a world position to the ground 1000 units below;
       on a hit, return the ground height and optionally the surface normal and value. */
    Vec rayEnd;
    Vec hitPos;
    Vec hitNormal;
    s32 surfaceValue;
    s32 hitObject;
    f32 endY = position->y - 1000.0f;
    f32 endZ = position->z;
    rayEnd.z = endZ;
    rayEnd.x = position->x;
    rayEnd.y = endY;
    if (((s32 (*)(Vec *, Vec *, Vec *, Vec *, s32 *, s32 *, s32))fn_801784AC)((Vec *)position, &rayEnd, &hitPos, &hitNormal, &surfaceValue, &hitObject, filter)) {
        *outHeight = hitPos.y;
        if ((u32)outNormal != 0) {
            outNormal->x = hitNormal.x;
            outNormal->y = hitNormal.y;
            outNormal->z = hitNormal.z;
        }
        if (outValue != 0) {
            *outValue = surfaceValue;
        }
        return 1;
    }
    return 0;
}
#pragma push
#pragma cplusplus on
extern "C" void fn_801B5318(void *);
extern "C" void fn_801785A4(void *object) {
    /* Append the object to the global registered-object list (lbl_8055E434 / lbl_8055E438),
     * then, if its slot-0x40 isValid() virtual reports true, run its post-register hook. */
    struct RegisteredObject {
        virtual void f0();
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
        virtual void f12();
        virtual void f13();
        virtual int isValid();
    };
    lbl_8055E434[lbl_8055E438++] = object;
    if (((RegisteredObject *)object)->isValid() != 0) {
        fn_801B5318(object);
    }
}
#pragma pop
/* Classifies a sound archive/header buffer: returns 0 for known archive magics
 * (CAR, PCAR, ACAR, NCAR), 2 for an OBST header with field 0x50 == 0x14, else 1. */
int fn_80178604(void *header) {
    int isKnownArchive = 0;
    unsigned int magic = *(unsigned int *)header;
    if (magic == 0x43415220 || magic == 0x50434152 ||
        magic == 0x41434152 || magic == 0x4e434152) {
        isKnownArchive = 1;
    }
    if (isKnownArchive != 0) return 0;
    if (magic == 0x4f425354 && *(int *)((char *)header + 0x50) == 0x14) return 2;
    return 1;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
/* Load an object from a stream into *outObject when its header type matches expectedType. */
int fn_80178678(void *stream, void **outObject, int expectedType) {
    int dataSize;
    void *buffer;
    int savedPos;
    void *loadedObj;

    buffer = 0;
    fn_8012F500(stream, &dataSize);
    if (dataSize < 0) {
        return 0;
    }

    savedPos = fn_8012F450(stream);
    fn_8012F550(stream, &buffer, 8);
    fn_8012F448(stream, savedPos);
    fn_8012F550(stream, &buffer, ((int *)buffer)[1]);

    if (expectedType == fn_80178604(buffer)) {
        loadedObj = fn_801783A8(buffer, dataSize);
    } else {
        loadedObj = 0;
    }

    *outObject = loadedObj;
    return 1;
}
#pragma pop

long fn_8017873C(long *buffer, long tag, long data, long length, long arg4) {
    /* Append a tagged payload to a growable buffer if there is space. */
    if ((unsigned long)(length + *buffer + 1) < 0x1000) {
        long result;
        *(unsigned char *)((char *)buffer + *buffer + 4) = tag;
        memcpy((char *)buffer + *buffer + 5, (void *)data, length);
        result = length + *buffer;
        *buffer = result + 1;
        return result;
    }
    return (long)buffer;
}

#pragma push
#pragma processor 750
int fn_801787B4(void *arg0)
{
    extern int fn_80019B78(void);
    extern int fn_80278820(void);
    extern int fn_802787FC(void);
    extern int fn_80176A1C(void);
    extern float fn_80176A2C(void);
    extern void KERNEL_WaitMilliseconds(int);
    extern void fn_802E30C8(const char *, ...);
    extern int fn_80265D64(void);
    extern u64 KERNEL_GetTimeUs(void);
    extern s64 fn_80178BBC(s32 *);
    extern s32 lbl_8055E3C4;
    extern s32 lbl_8055D430;
    extern float lbl_80561B48;
    extern float lbl_80561B5C;
    extern float lbl_80561B68;
    extern float lbl_80561B6C;
    extern float lbl_8055E460;
    extern double lbl_80561B70;
    char *tbl = jumptable_803318F8;
    s32 result;
    s32 *p = (s32 *)arg0;
    s32 r28;
    float f31;
    s64 now;
    s32 delta;
    s32 w;
    float scale;
    float var;
    s32 vi;
    s32 ip;
    s32 flag;
    s32 state;
    s32 c;
    s64 t;
    if (fn_80019B78() != 0) {
        return 1;
    }
    if (fn_80278820() != 0) {
        return 10;
    }
    if (fn_802787FC() != 0) {
        return 1;
    }
    if (fn_80176A1C() == 2) {
        float limit;
        f31 = fn_80176A2C();
        now = KERNEL_GetTimeUs();
        delta = (s32)(now - *(s64 *)(p + 6));
        delta = delta > 0 ? delta : 0;
        w = delta < 0xC350 ? delta : 0xC350;
        scale = lbl_80561B68;
        limit = lbl_80561B48;
        scale *= f31;
        p[7] = (s32)now;
        p[6] = (s32)(now >> 32);
        if (scale < limit) {
            var = scale - lbl_80561B5C;
        } else {
            var = lbl_80561B5C + scale;
        }
        vi = (s32)var;
        if (lbl_8055E3BD == 0) {
            lbl_8055E460 += (float)w / (float)(vi < 1 ? 1 : vi);
        }
        ip = (s32)lbl_8055E460;
        lbl_8055E460 -= (float)ip;
        *((u8 *)p + 0x14) = 1;
        return lbl_8055E3BD ? 1 : ip;
    }
    lbl_8055E460 = lbl_80561B6C;
    flag = ((lbl_8055D430 & 1) != 0 && (lbl_8055D430 & 0x600) != 0) ? 1 : 0;
    if (flag != 0) {
        *((u8 *)p + 0x14) = 1;
        return 3;
    }
    result = 1;
    state = fn_80176A1C();
    r28 = 1;
    if (lbl_8055E3BD == 0 && state == 1) {
        r28 = 0;
    }
    if (state == 0) {
        result = 10;
        if ((u8)lbl_8055E3C4 < 0x80 && (u8)(lbl_8055E3C4 - 10) > 0x80) {
            KERNEL_WaitMilliseconds(0x14);
        }
    }
    if (r28 == 0) {
        if (*((u8 *)p + 0x14) != 0) {
            p[0] = lbl_8055E3C4;
            t = KERNEL_GetTimeUs();
            *((u8 *)p + 0x14) = 0;
            *(s64 *)(p + 2) = (t + 0x2000) & ~(s64)0x3FFF;
        } else {
            result = ((s32)fn_80178BBC(p) + 0x2095) / 16683;
            if (fn_801B526C() != 0) {
                if ((result < 0 ? -result : result) > 10) {
                    *((u8 *)p + 0x14) = 1;
                }
                c = result > 0 ? result : 0;
                result = c < 4 ? c : 4;
            } else if (fn_80265D64() != 0) {
                if (result > 12) {
                    result = 12;
                }
            } else {
                if (result > 8) {
                    *((u8 *)p + 0x14) = 1;
                }
                if (result < -8) {
                    if (result < -16) {
                        s64 t2;
                        s64 t3;
                        u32 diff;
                        s64 sum;
                        fn_802E30C8(tbl + 0x14C, result);
                        t2 = fn_80178BBC(p);
                        fn_802E30C8(tbl + 0x178, (s32)t2, (s32)(t2 >> 32), (s32)t2);
                        diff = lbl_8055E3C4 - p[0];
                        sum = (s64)(s32)diff * 0x412B + *(s64 *)(p + 2);
                        fn_802E30C8(tbl + 0x19C, (s32)diff * 0x412B, (s32)(sum >> 32), (s32)sum);
                        t3 = KERNEL_GetTimeUs();
                        fn_802E30C8(tbl + 0x1C0, (s32)t3, (s32)(t3 >> 32), (s32)t3);
                    }
                    *((u8 *)p + 0x14) = 1;
                }
                c = result > 0 ? result : 0;
                result = c < 8 ? c : 8;
            }
        }
    } else {
        *((u8 *)p + 0x14) = 1;
    }
    return result;
}
extern void DBPrintf_80179758(const char *fmt, ...);
extern s32 lbl_8055E3C4;
extern u64 KERNEL_GetTimeUs(void);
extern s64 __div2i(s64, s64);
extern u8 lbl_804305C0[];
#pragma dont_inline on
/* Compute remaining time (ticks/units) from an entry's base time and offset against the current timer. */
s64 fn_80178BBC(s32 *entry) {
    s32 delta = lbl_8055E3C4 - entry[0];
    s64 scaled = *(s64 *)&entry[2] + (s64)delta * 0x412b;
    return KERNEL_GetTimeUs() - scaled;
}
s32 fn_80178C1C(s32 *entry) {
    /* Convert an entry's remaining tick count into whole time units:
     * fn_80178BBC returns ticks, and 0x412b ticks make one unit. */
    s64 ticksRemaining = fn_80178BBC(entry);
    return (s32)__div2i(ticksRemaining, 0x412b);
}

s32 fn_80178C4C(void *entry) {
    /* Debug callback: print the entry's label string (+4) and return its u16 id (+0) plus four. */
    DBPrintf_80179758((char *)entry + 4);
    return *(u16 *)entry + 4;
}

#pragma dont_inline off
/* Empty stub. */
void fn_80178C88(void) {
}

/* Empty stub. */
void fn_80178C8C(void) {

}

/* Return a pointer to the static 20-byte audio replay-parameter scratch block
   (two ints followed by three floats) written by fn_801B5060 during sound replay. */
void *__AXGetStudio_80178C90(void) {
    return lbl_804305C0;
}

extern void *lbl_8055E414;
/* Return the session/scene Owner singleton pointer held in lbl_8055E414
 * (destroyed during global teardown). */
void* fn_80178C9C(void) {
    return lbl_8055E414;
}

extern void *lbl_8055E444;
/* Return the cached global count in lbl_8055E444, mirrored from lbl_8055E440
 * into field +0x394 of the session state (e.g. the relevant lobby/version count). */
void* fn_80178CA4(void) {
    return lbl_8055E444;
}

#pragma use_lmw_stmw off
void fn_80178CAC(void *carA, void *carB)
{
  /* Swap two cars: repoint any of the four camera subjects that track either car,
   * then exchange the two car data objects' fields at +0x1F0, +0x10 and +0x270C
   * and refresh each car's entry in the car manager. */
  int field10A;
  int field10B;
  int field270CA;
  int field270CB;
  int *cameraSubject;
  int cameraIndex;
  void *carAObj;
  void *carAData;
  void *carBObj;
  int field1F0A;
  int field1F0B;
  cameraSubject = lbl_80430590;
  for (cameraIndex = 0; cameraIndex < 4; cameraIndex++, cameraSubject++)
  {
    if (((int) carA) == (*cameraSubject))
    {
      *cameraSubject = (int) carB;
      fn_8026A248((int) carB, cameraIndex);
    }
    else
      if (((int) carB) == (*cameraSubject))
    {
      *cameraSubject = (int) carA;
      fn_8026A248((int) carA, cameraIndex);
    }
  }

  carAData = (void *) getRegisteredObject((int) carA);
  carAObj = carAData;
  carBObj = (void *) getRegisteredObject((int) carB);
  field1F0A = *((int *) (((char *) carAObj) + 0x1F0));
  field1F0B = *((int *) (((char *) carBObj) + 0x1F0));
  field10A = *((int *) (((char *) carAObj) + 0x10));
  field10B = *((int *) (((char *) carBObj) + 0x10));
  field270CB = *((int *) (((char *) carBObj) + 0x270C));
  field270CA = *((int *) (((char *) carAObj) + 0x270C));
  fn_801A5300(carAData, 0);
  fn_801A5300(carBObj, 0);
  fn_801A5300(carAObj, field270CB);
  fn_801A5300(carBObj, field270CA);
  *((int *) (((char *) carAObj) + 0x1F0)) = field1F0B;
  *((int *) (((char *) carBObj) + 0x1F0)) = field1F0A;
  *((int *) (((char *) carAData) + 0x10)) = field10B;
  *((int *) (((char *) carBObj) + 0x10)) = field10A;
  fn_801EAA94((int) carA, field1F0B);
  fn_801EAA94((int) carB, field1F0A);
}
/* Stores weight at index in both parallel tables: lbl_804305D4 here and
   terrainWeights through fn_801DCEC8. */
void fn_80178DBC(int index, float weight) {
    lbl_804305D4[index] = weight;
    fn_801DCEC8(index, weight);
}

#pragma dont_inline on
/* Tail-call wrapper for external callers of fn_80177990: zero the four parallel
 * 75-entry weight tables (lbl_80430700 / lbl_804305D4 and, through the setters,
 * terrainWeights / lbl_804425DC). */
void fn_80178DD0(void) {
    fn_80177990();
}

extern char jumptable_803318F8[];
extern int lbl_8055E3CC;
extern int lbl_8055E418;
extern int lbl_8055E420;
extern int lbl_8055E428;
extern int lbl_8055E440;
extern unsigned char lbl_8055E45C;
extern void __AXDSPInitCallback_801D0CF0(void);
extern void __AXDSPInitCallback_801D32D0(void);
extern void __AXFXGetLfoSinTable_801769CC(void);
extern int *fn_801769D8(void);
extern int fn_80127464(void);
extern int fn_801284E8(void *, int);
extern int fn_8012850C(int, void *);
extern void fn_80129C80(int, int, int);
extern int fn_8012F3CC(int);
extern void fn_8012F43C(void *);
extern void fn_8012F418(void *);
extern int fn_80135DC4(int, int, int);
extern int fn_80137C74(void);
extern int fn_80178678(void *, void **, int);
extern void fn_80179320(void);
extern void fn_8017D2CC(int);
extern void fn_80181FEC(void);
extern void fn_80181F30(void);
extern void fn_801A4E28(void);
extern void fn_801AD5EC(void);
extern void fn_801AE4C4(void);
extern void fn_801AFAC8(void);
extern void fn_801B06C8(void);
extern void fn_801B2024(void);
extern void fn_801B2320(void);
extern void fn_801B3448(void);
extern void fn_801B5274(void);
extern void fn_801B52CC(void);
extern void fn_801B5364(int, void *);
extern void fn_801B5FA0(void);
extern void fn_801B8318(void);
extern void fn_801B8B84(void);
extern void fn_801C1B9C(void);
extern void fn_801C4AD0(void);
extern void fn_801C4B10(void);
extern void fn_801CB2D8(void);
extern void fn_801CEC80(void);
extern void fn_801CEFAC(void);
extern void fn_801D0E0C(void);
extern void fn_801D21C0(void);
extern void fn_801D4734(void);
extern void fn_801D47F4(void);
extern void fn_801D9284(void);
extern void fn_801DA6EC(void);
extern void fn_801DE0A4(void);
extern void fn_801DEC18(void);
extern void fn_801DF6FC(void);
extern void fn_801E0710(void);
extern void fn_801E1D38(void *, int);
extern void fn_801E2188(void);
extern void fn_801E21BC(void);
extern void fn_801FA978(void);
extern void fn_8020C41C(void);
extern void Camera_Init(void);
extern void fn_8026B644(void);
 #pragma push
 #pragma use_lmw_stmw off
void fn_80178DD4(int arg0) {
    register char *table = jumptable_803318F8;
    register char *base = (char *)lbl_80430590;
    register int var_r28;
    register int var_r27;
    register int var_r26;
    register int var_r31;
    register int version;
    int value;
    int *field;
    void *object;

    __AXDSPInitCallback_801D0CF0();
    lbl_8055E8F8 = *fn_801769D8();
    fn_80181FEC(); fn_801DF6FC(); fn_801DA6EC(); fn_801D0E0C();
    fn_80127464(); fn_801CEFAC();
    fn_80177814(&lbl_8055E418); fn_80177814(&lbl_8055E420); fn_80177814(&lbl_8055E428);
    value = fn_801284F8(0x68, table + 0x220);
    if (value != 0) value = fn_80135DC4(value, 0, 0);
    lbl_8055E414 = (void *)value;
    memset(base + 0x32F0, 0, 0x840);
    field = (int *)&lbl_8055E418;
    fn_80129C80(4, lbl_8055E418, field[1]);
    field = (int *)&lbl_8055E420;
    fn_80129C80(3, lbl_8055E420, field[1]);
    field = (int *)&lbl_8055E428;
    fn_80129C80(5, lbl_8055E428, field[1]);

    var_r28 = (int)(base + 0);
    var_r27 = (int)(base + 0x10);
    var_r26 = 0;
    var_r31 = -1;
    do {
        *(int *)var_r28 = var_r31;
        memset((void *)var_r27, 0, 8);
        var_r26 += 1;
        var_r28 += 4;
        var_r27 += 8;
    } while (var_r26 < 4);

    lbl_8055E430 = (void *)fn_80137C74();
    var_r31 = 0;
    lbl_8055E43C = var_r31;
    fn_80127464(); fn_801B5274(); fn_801B5FA0(); fn_801B3448();
    fn_801A4E28(); fn_801AFAC8(); fn_801B06C8(); fn_801B8B84();
    fn_801CEC80(); fn_80181F30(); fn_801DE0A4();
    __AXFXGetLfoSinTable_801769CC(); fn_801B2024(); fn_80127464();
    fn_801C4AD0(); fn_8020C41C(); fn_8026B644(); fn_801C1B9C();
    fn_801D21C0(); __AXDSPInitCallback_801D32D0(); fn_801D9284();
    fn_801D4734(); fn_801CB2D8(); fn_801DEC18(); fn_80127464();
    fn_801E0710(); fn_801B8318(); fn_801FA978();

    lbl_8055E434 = (void **)fn_8012850C(0x800, table + 0x230);
    fn_801E2188();
    field = (int *)(base + 0x2A0);
    *field = var_r31;
    field[1] = var_r31; field[2] = var_r31; field[3] = var_r31;
    field[4] = var_r31; field[5] = var_r31; field[6] = var_r31; field[7] = var_r31;
    lbl_8055E45E = var_r31; lbl_8055E45F = var_r31; lbl_8055E45C = var_r31; lbl_8055E45D = var_r31;
    lbl_8055E438 = var_r31;
    *(int *)(base + 0x22E8) = var_r31;
    *(int *)(base + 0x2E0) = var_r31;
    *(int *)(base + 0x12E4) = var_r31;

    var_r26 = fn_8012F3CC(arg0);
    fn_801AE4C4(); fn_80127464();
    var_r27 = 0;
    do {
        fn_8012F43C((void *)var_r26);
        while (fn_80178678((void *)var_r26, &object, var_r27) != 0) {
            if (object != 0) fn_801785A4((void **)object);
        }
        var_r27 += 1;
    } while (var_r27 < 3);

    fn_80127464(); fn_8012F418((void *)var_r26); fn_801B52CC();
    fn_801E21BC(); fn_80127464(); fn_8017D2CC(0x200);
    lbl_8055E448 = var_r31;
    value = 1;
    version = (int)lbl_8055E430;
    if (version > 1) value = version;
    lbl_8055E440 = value; lbl_8055E444 = (void *)value;
    Camera_Init();
    lbl_8055E450 = fn_801284E8(table + 0x23C, lbl_8055E3CC + 0x2EE8);
    fn_801AD5EC(); fn_80127464(); fn_801B2320(); fn_801C4B10();
    field = (int *)(base + 0x2C0);
    field[4] = var_r31;
    *((unsigned char *)field + 0x14) = 1;
    field[7] = var_r31; field[6] = var_r31;
    fn_801E1D38(field, 1);
    fn_801D47F4(); fn_801B5364(9, (void *)fn_80178C4C);
    field = (int *)&lbl_8055E418;
    fn_80129C80(4, lbl_8055E418, field[1]);
    field = (int *)&lbl_8055E420;
    fn_80129C80(3, lbl_8055E420, field[1]);
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));
    fn_80127464(); fn_80179320();
}
#pragma pop
extern void fn_801B2C6C(void);
extern void fn_801B5354(void);
void fn_80179110(void) {
#define gStepCount lbl_8055E448
    /* Advance the audio subsystem one step: run the two update hooks, then
     * increment the global step counter. */
    fn_801B2C6C();
    fn_801B5354();
    gStepCount += 1;
#undef gStepCount
}
extern int fn_802E4C18(int);
extern int fn_801787B4(void *);
extern void fn_80177F40(void);
extern long lbl_80430850[];
#pragma cplusplus on
extern "C" void fn_80179140(void) {
    /* Dispatch the 4th virtual method for each object in the global object table. */
    class Element {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    s32 byteOffset = 0;
    s32 objectIndex = 0;
    Element *object;
    while (objectIndex < lbl_8055E438) {
        object = (Element *)*(void **)((char *)lbl_8055E434 + byteOffset);
        object->f3();
        byteOffset += 4;
        objectIndex += 1;
    }
}
#pragma cplusplus off

/* No-op hook of the scene/system manager, placed between the object-table
 * update fn_80179140 and the global shutdown fn_801791A8.  It compiles to a
 * bare blr and no caller has shown up in the decompiled code yet. */
void fn_801791A4(void) {

}

#pragma cplusplus on
extern "C" void fn_801B537C(long (*)(void *));
extern "C" void fn_801E1D9C(void);
extern "C" void fn_8026785C(void);
extern "C" void fn_8017D334(void);
extern "C" void fn_80128658(int);
extern "C" void fn_80128670(void *);
extern "C" void fn_801AE50C(void);
extern "C" void fn_801E222C(void);
extern "C" void fn_801E1520(void);
extern "C" void fn_801DEE3C(void);
extern "C" void fn_801CB518(void);
extern "C" void fn_801D483C(void);
extern "C" void fn_801D9828(void);
extern "C" void fn_801D32DC(void);
extern "C" void fn_801D2210(void);
extern "C" void fn_801C1BA0(void);
extern "C" void fn_8026B69C(void);
extern "C" void fn_801B228C(void);
extern "C" void fn_801AFBE8(void);
extern "C" void fn_801B06CC(void);
extern "C" void fn_801C4B74(void);
extern "C" void fn_8020C45C(void);
extern "C" void fn_801DE0E8(void);
extern "C" void fn_80181FC4(void);
extern "C" void fn_801CECB4(void);
extern "C" void fn_801B8BBC(void);
extern "C" void fn_801A4E54(void);
extern "C" void fn_801B3B28(void);
extern "C" void fn_801B60A8(void);
extern "C" void fn_801B531C(void);
extern "C" void fn_801CEFC4(void);
extern "C" void fn_80206550(int);
extern "C" void fn_801D0E70(void);
extern "C" void fn_801D0CFC(void);
#pragma cplusplus on
extern "C" void fn_801791A8(void) {
    class Element {
    public:
        virtual void f0();
        virtual void disable(int);
    };
    class Owner {
    public:
        virtual void destroy(int);
    };
    int elementOffset;
    int index;
    Element *element;
    /* Global shutdown/teardown: stops subsystems, frees arrays/objects, and clears related globals. */
    fn_80177A18();
    fn_801B537C(fn_80178C4C);
    fn_801E1D9C(); fn_8026785C(); fn_8017D334();
    fn_80128658(lbl_8055E450);
    lbl_8055E450 = 0;
    index = 0;
    elementOffset = 0;
    while (index < lbl_8055E438) {
        element = (Element *)*(void **)((char *)lbl_8055E434 + elementOffset);
        if (element != 0) element->disable(1);
        elementOffset += 4;
        index++;
    }
    fn_80128670(lbl_8055E434);
    lbl_8055E434 = 0;
    fn_801AE50C(); fn_801E222C(); fn_801E1520(); fn_801DEE3C(); fn_801CB518();
    fn_801D483C(); fn_801D9828(); fn_801D32DC(); fn_801D2210(); fn_801C1BA0();
    fn_8026B69C(); fn_801B228C(); fn_801AFBE8(); fn_801B06CC(); fn_801C4B74();
    fn_8020C45C(); fn_801DE0E8(); fn_80181FC4(); fn_801CECB4(); fn_801B8BBC();
    fn_801A4E54(); fn_801B3B28(); fn_801B60A8(); fn_801B531C();
    if (lbl_8055E414 != 0) ((Owner *)lbl_8055E414)->destroy(1);
    lbl_8055E414 = 0;
    fn_801CEFC4(); fn_80206550(1); fn_801D0E70();
    lbl_8055E8F8 = 0;
    fn_801D0CFC();
}
#pragma cplusplus off
/* Tail-call thunk for external callers of fn_801E21B4, which caches its
 * argument as the active secondary collision group (the primary one is cached
 * by fn_801E2188): the pointer passes straight through the branch. */
void fn_801792F4(void) {
    fn_801E21B4();
}

extern void *lbl_8055E454;
void* fn_801792F8(void) {
    /* lbl_8055E454 points at the current mode/request data object while it is
     * being set up (stored by fn_801783A8, then cleared); callers read its mode
     * id and flags at +0x50/+0xD8. */
    #define sCurrentModeObject lbl_8055E454
    return sCurrentModeObject;
    #undef sCurrentModeObject
}

extern void *lbl_8055E458;
void* fn_80179300(void) {
    /* lbl_8055E458 counts frames since the scene was reset (cleared by
     * fn_80179320, advanced each tick by fn_80177F40); callers gate a
     * 40-frame startup grace period on it. */
    #define sSceneFrameCount lbl_8055E458
    return sSceneFrameCount;
    #undef sSceneFrameCount
}

void fn_80179308(void) {
    #define gStepCount lbl_8055E448
    /* Advance the audio subsystem's global step counter by one. */
    gStepCount += 1;
    #undef gStepCount
}

void* fn_80179318(void) {
    /* lbl_8055E448 is the global step counter advanced by the audio update
     * hooks (fn_80179110 / fn_80179308); return its current value. */
    #define gStepCount lbl_8055E448
    return (void *)gStepCount;
    #undef gStepCount
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80179320(void) {
    extern float lbl_8055E460;
    float initial = 1.0f;
    register int offset;
    register char *base = (char *)lbl_80430590;
    register int i;
    void *object;
    int old;
    int *field;
    char *bytes;

    lbl_8055E43C = 0;
    lbl_8055E460 = initial;
    lbl_8055E44C = 0;
    lbl_8055E458 = 0;
    fn_80177990();
    if (fn_801CF050() != 0) {
        fn_80177814(&lbl_8055E418);
        fn_80177814(&lbl_8055E420);
        fn_80177814(&lbl_8055E428);
    }
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));
    fn_80176A34(0);
    fn_801D9A08();
    __AXDSPInitCallback_801B8BE8();
    fn_801DEF98();
    fn_801B83A8();
    fn_801B34A4();
    fn_8026B6D0();
    fn_802C1928();
    fn_80134998();
    fn_801B265C();
    fn_801AED74();
    fn_801E2294();

    i = 0;
    offset = 0;
    while (offset < lbl_8055E438) {
        object = *(void **)((char *)lbl_8055E434 + i);
        ((void (*)(void *))(*(void ***)object)[4])(object);
        i += 4;
        offset += 1;
    }

    fn_801B2910();
    fn_80267680();
    if (fn_801CF064() == 0) {
        i = (int)base;
        offset = 0;
        while (offset < (int)lbl_8055E430) {
            old = *(int *)i;
            fn_8026A248(old, offset);
            i += 4;
            offset += 1;
        }
    }

    i = (int)(base + 0x10);
    offset = 0;
    do {
        memset((void *)i, 0, 8);
        offset += 1;
        i += 8;
    } while (offset < 4);

    base[0x32F0] = 0;
    bytes = base + 0x32F0;
    bytes[0x108] = 0;
    bytes[0x210] = 0;
    bytes[0x318] = 0;
    bytes[0x420] = 0;
    bytes[0x528] = 0;
    bytes[0x630] = 0;
    bytes[0x738] = 0;
    fn_80265D60(bytes);
    fn_801CECE0();
    if (fn_80265D64() == 0) {
        field = (int *)(base + 0x2C0);
        field[4] = 0;
        *((char *)field + 0x14) = 1;
        field[7] = 0;
        field[6] = 0;
    }

    old = lbl_8055E448;
    lbl_8055E448 = old + 1;
    fn_801349C4(old);
    fn_801CB320();
    fn_801D481C();
    fn_801C4BAC();
    musicPreRaceInit();
    fn_801E1E30();
    fn_801D0ED4();
    fn_801777A8();
}
/* Enable a flag via fn_802E4C18, query iteration count for lbl_80430850 via fn_801787B4, then run fn_80177F40 that many times. */
void fn_8017952C(void) {
    long iterationCount;
    long i;

    fn_802E4C18(1);
    iterationCount = fn_801787B4(&lbl_80430850);
    i = 0;
    while (i < iterationCount) {
        fn_80177F40();
        i++;
    }
}

void fn_801CEFE8(void);
void fn_801AED5C(void);
void fn_801CB464(void);
void fn_80179588(void) {
#define StartReplayPlayback fn_801CEFE8
#define SetReplayFlag       fn_801AED5C
#define PauseStatManager    fn_801CB464
    /* Begin cutscene replay playback: post the start message, set the
     * replay-active flag and enter playback, then pause the stat manager. */
    StartReplayPlayback();
    SetReplayFlag();
    PauseStatManager();
#undef StartReplayPlayback
#undef SetReplayFlag
#undef PauseStatManager
}

void fn_801CF01C(void);
void fn_801CB4A0(void);
void fn_801AED68(void);
void fn_801795B0(void) {
#define EndReplayPlayback fn_801CF01C
#define ResumeStatManager fn_801CB4A0
#define ClearReplayFlag   fn_801AED68
    /* End cutscene replay playback: post the end message and clear the
     * in-playback flag, resume the stat manager, then clear the replay flag. */
    EndReplayPlayback();
    ResumeStatManager();
    ClearReplayFlag();
#undef EndReplayPlayback
#undef ResumeStatManager
#undef ClearReplayFlag
}

/* Register vehicle in the global object table at objIndex. Player/racer vehicles
 * (type 0x50 at +0x1F0) are also indexed by their player slot (+0x260 & 3) in
 * lbl_80430590 so they can be looked up by split-screen player. */
void fn_801795D8(void *vehicle, int objIndex) {
    ((void **)lbl_80430830)[objIndex] = vehicle;
    if (*(int *)((char *)vehicle + 0x1F0) == 0x50) {
        lbl_80430590[(*(unsigned char *)((char *)vehicle + 0x260) & 3)] = objIndex;
    }
}

/* Look up a registered vehicle/object by index in the 8-entry global object table
 * (lbl_80430830); returns NULL for an out-of-range index. */
int getRegisteredObject(int objIndex) {
    if (objIndex < 8) return lbl_80430830[objIndex];
    return 0;
}

/* Return the object-table index of the vehicle registered for a split-screen
 * player slot (lbl_80430590), treating a negative slot as slot 0. */
int fn_80179630(int playerSlot) {
    if (playerSlot < 0) playerSlot = 0;
    return lbl_80430590[playerSlot];
}

extern void *lbl_8055E430;
extern char *fn_80178374(long);
extern long Abend_Panic(const char *, long, ...);
extern const char lbl_80331B40[];
extern unsigned char *fn_801781F4(long);
/* Return the cached snapshot of the registered-record count (captured from fn_80137C74 at init), used as the race's record/player count. */
void* fn_80179650(void) {
    return lbl_8055E430;
}

/* Get the message data size for a message type; logs an error and returns -1 if unknown. */
s32 fn_80179658(long arg0) {
    char *entry;

    entry = fn_80178374(arg0);
    if (entry != 0) {
        return *(s32 *)(entry + 4);
    }
    Abend_Panic(lbl_80331B40, (long)fn_801781F4(arg0));
    return -1;
}

extern char lbl_8055E45D;
char fn_801796B4(void) {
    /* Return the cached global mode flag byte (a per-frame snapshot of lbl_8055E45C) used to switch controller update mode. */
    return lbl_8055E45D;
}

/* Set the "a menu holds the game" flag lbl_8055E45E.  The frame update
 * (fn_80177F40) copies it to lbl_8055E45F, whose previous-frame value
 * fn_801796C4 returns; vehicle/camera code reads it to snap positions instead
 * of following normally.  The challenge level-select menu sets it while it is
 * up (fn_80164F50) and clears it once the player confirms a choice. */
void fn_801796BC(unsigned char menuActive) {
    lbl_8055E45E = menuActive;
}

extern char lbl_8055E45F;
char fn_801796C4(void) {
    /* Return the second cached global mode flag byte (a per-frame snapshot of lbl_8055E45E), paired with fn_801796B4. */
    return lbl_8055E45F;
}

#pragma dont_inline on
long fn_801796CC(long eventType, long payload, long size) {
    /* Append a tagged EFX event record (type + payload) to this event-log buffer; returns the offset used. */
    #define AppendEvent fn_8017873C /* appends a tagged payload to a growable event buffer */
    #define sEventBuffer lbl_80430870 /* EFX event-log buffer */
    return AppendEvent((long*)&sEventBuffer, eventType, payload, size, eventType);
    #undef sEventBuffer
    #undef AppendEvent
}

extern int lbl_80431874[];
long fn_801796EC(long eventType, long payload, long size) {
    /* Append a tagged EFX event record (type + payload) to the primary event-log buffer; returns the offset used. */
    #define AppendEvent fn_8017873C /* appends a tagged payload to a growable event buffer */
    #define sEventBuffer lbl_80431874 /* primary EFX event-log buffer */
    return AppendEvent((long*)&sEventBuffer, eventType, payload, size, eventType);
    #undef sEventBuffer
    #undef AppendEvent
}

float fn_8017970C(void) {
    /* Return the global object's counter value scaled to a time-like float. */
#define sGlobalObject lbl_80430850
#define sCounterToTimeScale lbl_80561B60

    return sCounterToTimeScale * (float)fn_80178C1C((long *)sGlobalObject);

#undef sGlobalObject
#undef sCounterToTimeScale
}

#pragma dont_inline off
/* Debug printf stub (no-op). */
void DBPrintf_80179758(const char *format, ...) {
#pragma unused(format)
}

/* Debug printf stub (no-op). */
void DBPrintf_801797A8(const char *format, ...) {
#pragma unused(format)
}

extern int lbl_804305A0[];
extern int lbl_8055E450;
/* Record an event for a slot id: store the packed (event type << 16 | parameter) word, then return and bump that slot's queued-event count. */
int fn_801797F8(int slotId, int eventType, int param) {
    int (*table)[2];
    (table = (int (*)[2])lbl_804305A0)[slotId][0] = (eventType << 16) | (param & 0xFFFF);
    return table[slotId][1]++;
}

#pragma push
#pragma dont_inline on
void *fn_80179824(void) {
    extern int fn_8026A368();
    extern void fn_802678E8();
    extern void fn_801B2D28();
    extern void fn_801CEEC8();
    extern void fn_801B848C();
    extern void fn_801E1EA4();
    extern void fn_80176C0C();
    extern int lbl_8055E440;
    extern float lbl_8055E460;
    extern void *lbl_8055E444;
    extern float lbl_80561B6C;
    extern float lbl_8055E3C8;
    int *tbl = lbl_80430590;
    char *p = (char *)lbl_8055E450;
    char *arg;
    char *q;
    int *e;
    int k, i;
    *(int *)(p + 0x398) = lbl_8055E448;
    arg = p + 0x2ee8;
    *(int *)(p + 0x394) = lbl_8055E440;
    *(int *)(p + 0x384) = tbl[0];
    *(int *)(p + 0x388) = tbl[1];
    *(int *)(p + 0x38c) = tbl[2];
    *(int *)(p + 0x390) = tbl[3];
    if (fn_801CF050(&lbl_80430590[0]) == 0 || (int)fn_801781C0(fn_8026A368(0)) != 0 || fn_801B526C() != 0) {
        *(int *)(p + 0x394) = 1;
    }
    lbl_8055E444 = *(void **)(p + 0x394);
    q = p + 4;
    e = tbl + 4;
    for (i = 0; i < lbl_8055E440; i++, q += 0xe0) {
        fn_802678E8(q, i);
        *(int *)(q + 0x70) = e[0];
        *(int *)(q + 0x6c) = e[1];
        e += 2;
    }
    fn_80206550((int)lbl_8055E444);
    {
        float scale;
        float bottom;
        float top;
        float center;
        float diff;
        top = lbl_8055E460;
        bottom = lbl_80561B6C;
        scale = lbl_80561B60;
        center = lbl_8055E3C8;
        diff = top - bottom;
        *(float *)p = center + scale * diff;
    }
    for (k = 0; k < lbl_8055E438; k++) {
        void **o = ((void ***)lbl_8055E434)[k];
        ((void (*)(void *, void *))(((void **)*o)[10]))(o, arg);
    }
    fn_801B2D28(p);
    fn_801CEEC8(p);
    fn_801B848C(p);
    {
        int *t = tbl + 12;
        *(int *)(p + 0x57c) = t[0];
        *(int *)(p + 0x580) = t[1];
        *(float *)(p + 0x584) = ((float *)t)[2];
        *(float *)(p + 0x588) = ((float *)t)[3];
        *(float *)(p + 0x58c) = ((float *)t)[4];
        fn_801E1EA4(p, t);
    }
    {
        float *s = (float *)(tbl + 17);
        char *dst = p;
        int idx = 0;
        int n;
        for (n = 0; n < 3; n++) {
            idx += 0x18;
            *(float *)(dst + 0xdb4) = s[0];
            *(float *)(dst + 0xdb8) = s[1];
            *(float *)(dst + 0xdbc) = s[2];
            *(float *)(dst + 0xdc0) = s[3];
            *(float *)(dst + 0xdc4) = s[4];
            *(float *)(dst + 0xdc8) = s[5];
            *(float *)(dst + 0xdcc) = s[6];
            *(float *)(dst + 0xdd0) = s[7];
            *(float *)(dst + 0xdd4) = s[8];
            *(float *)(dst + 0xdd8) = s[9];
            *(float *)(dst + 0xddc) = s[10];
            *(float *)(dst + 0xde0) = s[11];
            *(float *)(dst + 0xde4) = s[12];
            *(float *)(dst + 0xde8) = s[13];
            *(float *)(dst + 0xdec) = s[14];
            *(float *)(dst + 0xdf0) = s[15];
            *(float *)(dst + 0xdf4) = s[16];
            *(float *)(dst + 0xdf8) = s[17];
            *(float *)(dst + 0xdfc) = s[18];
            *(float *)(dst + 0xe00) = s[19];
            *(float *)(dst + 0xe04) = s[20];
            *(float *)(dst + 0xe08) = s[21];
            *(float *)(dst + 0xe0c) = s[22];
            *(float *)(dst + 0xe10) = s[23];
            s += 0x18;
            dst += 0x60;
        }
        {
            int off = idx * 4;
            char *dp = p + off;
            char *sp = (char *)(tbl + 17) + off;
            *(float *)(dp + 0xdb4) = *(float *)sp;
            *(float *)(dp + 0xdb8) = *(float *)(sp + 4);
            *(float *)(dp + 0xdbc) = *(float *)(sp + 8);
        }
    }
    fn_80176C0C(p + 0xee0, tbl + 0xb8);
    fn_80176C0C(p + 0x1ee4, tbl + 0x4b9);
    tbl[0x4b9] = 0;
    return p;
}
#pragma pop
extern float lbl_80561B6C;
extern float lbl_8055E460;
extern char lbl_80558DC4[];
#pragma push
#pragma opt_common_subs off
void fn_80179AF4(void *arg0, int arg1) {
int __repair_constant = 6;

    struct WordPair { unsigned int a, b; };
    extern char lbl_80558DC4[];
    extern float lbl_8055E460;
    extern float lbl_80561B6C;
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float base = lbl_80561B6C;
    float top = lbl_8055E460;
    float delta = top - base;
    if ((float)__fabs((double)delta) <= *(float *)lbl_80558DC4) {
        struct WordPair *s = (struct WordPair *)(src + 0x70);
        struct WordPair *d = (struct WordPair *)dst;
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        ((unsigned int *)dst)[8] = ((unsigned int *)(src + 0x70))[8];
        ((struct WordPair *)(dst + 0x24))[0] = ((struct WordPair *)(src + 0x94))[0];
        ((unsigned int *)dst)[11] = ((unsigned int *)(src + 0x70))[11];
    } else {
        float temp[12];
        float *a, *b, *out;
        int i;
        out = temp;
        b = (float *)(src + 0xA0);
        a = (float *)(src + 0x70);
        for (i = 0; i < 2; i++) {
            float a0 = a[0], b0 = b[0];
            float a1 = a[1], b1 = b[1];
            float a2 = a[2], b2 = b[2];
            float a3 = a[3], b3 = b[3];
            float a4 = a[4], b4 = b[4];
            float a5 = a[5], b5 = b[5];
            out[0] = b0 + top * (a0 - b0);
            out[1] = b1 + top * (a1 - b1);
            out[2] = b2 + top * (a2 - b2);
            out[3] = b3 + top * (a3 - b3);
            out[4] = b4 + top * (a4 - b4);
            out[5] = b5 + top * (a5 - b5);
            a += __repair_constant; b += __repair_constant; out += __repair_constant;
        }
        {
            unsigned int *s = (unsigned int *)temp;
            unsigned int *d = (unsigned int *)dst;
            d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
            d[4] = s[4]; d[5] = s[5]; d[6] = s[6]; d[7] = s[7];
            d[8] = s[8]; d[9] = s[9]; d[10] = s[10]; d[11] = s[11];
        }
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
}
#pragma pop
/* Return a pointer to the per-racer state block at offset 0x2EE8 of the global race-state buffer
   (the same sub-block fn_80179824 passes to each racer's virtual method). */
int fn_80179CB0(void) {
#define gRaceBuffer lbl_8055E450
    return gRaceBuffer + 0x2EE8;
#undef gRaceBuffer
}

extern unsigned char lbl_8055E46C;
extern unsigned char lbl_8055A304;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055E45E;
extern long fn_8017873C(long *, long, long, long, long);
extern long lbl_80430850[];
extern long fn_80178C1C(long *);
extern float lbl_80561B60;
extern double lbl_80561B70;
extern char *fn_80178374(long);
extern long Abend_Panic(const char *, long, ...);
extern const char lbl_80331B40[];
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;
