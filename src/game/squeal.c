// squeal — tire squeal sfx ("squeal.sfx").
// Recovered TU window 0x80209D4C..0x80209FF4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_80209FF4 (+ .ctors slot 0x802ED388) remains in
// auto/text_80209FF4_.c pending a promotion pass.
extern char lbl_8033C258[];
extern char lbl_8033C268[];
extern int lbl_8055B548;
extern void *fn_801284F8(unsigned int, void *);
extern void *fn_802077A4(void *, int, void *, void *);
extern void *RoadSnd_createContainer(void *);
extern float lbl_80563278, lbl_8056327C, lbl_80563280, lbl_80563284, lbl_80563288;

// 0x74-byte record: value at 0x68, enable byte at 0x6c.
typedef struct {
    /* 0x00 */ char pad_00[0x68];
    /* 0x68 */ float value;
    /* 0x6c */ signed char enabled;
    /* 0x6d */ char pad_6D[7];
} Record;

#pragma scheduling invalid_target
/* Construct the tire-squeal sound object: store vtable and owning sound source, create the SFX handle, copy the source's 0x1ec field into it, and attach a road-sound container. Returns 0 if allocation fails. */ void *SquealSound_create(void *soundSource) {
#define kVtable         lbl_8033C258
#define kSfxName        lbl_8033C268    /* "squeal.sfx" */
#define kAllocTag       lbl_8055B548    /* "tiresnd" */
#define allocObject     fn_801284F8
#define createSfx       fn_802077A4
#define createRoadSound RoadSnd_createContainer
    /* Construct the four-word squeal sound object: record the owning source and
       its vtable, attach an SFX handle driven by the source, and a road-sound container. */
    typedef struct {
        void *vtable;
        void *soundSource;
        void *sfxHandle;
        void *roadSound;
    } SquealSound;
    SquealSound *squealObj;
    void *sfxHandle;
    squealObj = (SquealSound *)allocObject(0x10, &kAllocTag);
    if (squealObj != 0) {
        squealObj->vtable = kVtable;
        squealObj->soundSource = soundSource;
        sfxHandle = createSfx(kSfxName, 4, (char *)soundSource + 0x118, (char *)soundSource + 0x60);
        squealObj->sfxHandle = sfxHandle;
        if (sfxHandle != 0) *(int *)((char *)sfxHandle + 0x10) = *(int *)((char *)squealObj->soundSource + 0x1ec);
        squealObj->roadSound = (void *)createRoadSound(soundSource);
    }
    return squealObj;
#undef createRoadSound
#undef createSfx
#undef allocObject
#undef kAllocTag
#undef kSfxName
#undef kVtable
}

extern void fn_80128668(void *);
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
/* Squeal-object destructor: restore its vtable, release the owned SFX and road-sound objects, and free the object itself when requested. */ extern "C" void *SquealSound_destroy(void *self, int shouldDelete) {
#define kVtable    lbl_8033C258
#define freeObject fn_80128668
    /* Destroy the squeal object, releasing its owned child objects and optionally freeing it. */
    struct RefCounted { virtual void release(int); };
    void *sfxHandle;
    void *roadSound;
    if (self != 0) {
        sfxHandle = *(void **)((char *)self + 8);
        *(void **)self = (void *)kVtable;
        if (sfxHandle != 0) {
            if (sfxHandle != 0) {
                ((struct RefCounted *)sfxHandle)->release(1);
            }
            *(void **)((char *)self + 8) = 0;
        }
        roadSound = *(void **)((char *)self + 0xC);
        if (roadSound != 0) {
            if (roadSound != 0) {
                ((struct RefCounted *)roadSound)->release(1);
            }
        }
        if (shouldDelete > 0) {
            freeObject(self);
        }
    }
    return self;
#undef freeObject
#undef kVtable
}
#pragma pop

#pragma scheduling on
#pragma push
#pragma cplusplus on
/* Update the squeal state from the four input records: accumulate clamped (value - 0.8f) contributions, publish the total and active flags into the state object, then notify the listener. */ extern "C" void fn_80209E94(void *self) {
    struct Notifier {
        virtual void v0();
        virtual void v1();
    };
    /* Accumulate input/trigger contribution from 4 Records at (arg0+4)->+0x23AC:
       for each enabled==0 record, add clamp(value - 0.8f, 0, 0.25f) to total.
       Write into state object at *(arg0+8): set flag +0x4e and force field +4
       to 1.0f if changed, set flag +0x4d and store total at +8 if changed; if
       total > 0.001f set flags (+0x49,+0x4b)=1, +0x4a=0 else set +0x4a=1,
       +0x4c=0. Then call notifier v1() on *(arg0+0xc) if present. */
    Record *squealRecords = (Record *)(*(char **)((char *)self + 4) + 0x23AC);
    float value;
    float total = 0.0f;
    char *state;
    int recordIndex;
    Notifier *notifier;

    for (recordIndex = 0; recordIndex < 4; recordIndex++) {
        value = squealRecords[recordIndex].value - 0.8f;
        if (squealRecords[recordIndex].enabled == 0 && value > 0.0f) {
            if (0.25f < value) {
                value = 0.25f;
            }
            total += value;
        }
    }

    state = *(char **)((char *)self + 8);
    if (1.0f != *(float *)(state + 4)) {
        *(signed char *)(state + 0x4e) = 1;
        *(float *)(state + 4) = 1.0f;
    }
    state = *(char **)((char *)self + 8);
    if (total != *(float *)(state + 8)) {
        *(signed char *)(state + 0x4d) = 1;
        *(float *)(state + 8) = total;
    }
    if (total > 0.001f) {
        state = *(char **)((char *)self + 8);
        *(signed char *)(state + 0x4a) = 0;
        *(signed char *)(state + 0x4b) = 1;
        *(signed char *)(state + 0x49) = 1;
    } else {
        state = *(char **)((char *)self + 8);
        *(signed char *)(state + 0x4a) = 1;
        *(signed char *)(state + 0x4c) = 0;
    }
    notifier = *(Notifier **)((char *)self + 0xc);
    if (notifier != 0) {
        notifier->v1();
    }
}
#pragma cplusplus reset
#pragma pop
#pragma scheduling on

#pragma scheduling on


