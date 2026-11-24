// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */

extern u8 lbl_80438958[];
extern s32 lbl_8055E930;
extern s32 fn_801D2BF4(s32 *, s32 *);
extern void fn_802C6CF8(s32);
extern s32 fn_800241DC(s32 *, u8 *, s32, s32, s32 (*)(s32 *, s32 *));
extern void qsort(void *, s32, s32, void *);
extern void *fn_80131810(void);
extern void fn_80131818(void *);
extern void fn_801D25BC(void *, void *);
extern void fn_801D26C8(void *, void *);
extern void fn_801D2A24(void *);
extern s32 strncmp(char *, char *, s32);
extern s32 lbl_8055AC28;
extern u8 lbl_80338300[];
extern u32 lbl_8055ABE0;
extern u32 lbl_8055AC18;
extern u32 lbl_8055AC20;
extern f32 lbl_80562A90;
extern f32 lbl_80562A94;
extern u8 lbl_803382A8[];
__declspec(section ".sdata") extern u8 lbl_8055ABE8[];
__declspec(section ".sdata") extern u8 lbl_8055ABF8[];
__declspec(section ".sdata") extern u8 lbl_8055AC00[];
__declspec(section ".sdata") extern u8 lbl_8055AC08[];
__declspec(section ".sdata") extern u8 lbl_8055AC10[];
__declspec(section ".sdata") extern u8 lbl_8055ABF0[];
extern void fn_801D334C(void *, void *);
extern void fn_801D3610(void *, void *);
extern s32 fn_802C6FC0(void *, s32, s32);
extern s32 parseHexString(void *);

typedef struct UnkObj UnkObj;
typedef struct {
    char pad0[8];
    char *(*fn8)(void *);
    void *(*child)(void *, s32);
    char pad2[0x0C];
    s32 (*fn1C)(void *, u32);
    char pad3[8];
    f32 (*fn28)(void *, void *, f32);
    char pad4[0x30];
    void *(*fn5C)(void *, u32);
} Vt801D;
struct UnkObj { const Vt801D *vt; };
typedef struct { void *pad[0x12]; void (*fn48)(void *, f32 *, void *, s32, s32); } Vt801E;

#pragma dont_inline on
void fn_801D2B94(void) {
    /* Finalize each soevent class: release its loaded resource handle if one was acquired. */
    u8 *entry = lbl_80438958;
    s32 index = 0;
    s32 resourceHandle;
    while (index < lbl_8055E930) {
        resourceHandle = *(s32 *)(entry + 0x6C);
        if (resourceHandle != -1) {
            fn_802C6CF8(resourceHandle);
        }
        entry += 0x4C4;
        index += 1;
    }
}
#pragma dont_inline off

/* qsort/bsearch comparator: order soevent class entries by their id field. */
s32 fn_801D2BF4(s32 *lhsId, s32 *rhsId) {
    return *lhsId - *rhsId;
}

#pragma scheduling invalid_target
void fn_801D2C04(void) {
    /* Sort the soevent class table by id so id lookups can binary-search it. */
#define sSoeventClassTable lbl_80438958
#define sSoeventClassCount lbl_8055E930
#define SoeventClassCompare fn_801D2BF4
    qsort(sSoeventClassTable, sSoeventClassCount, 0x4C4, SoeventClassCompare);
#undef sSoeventClassTable
#undef sSoeventClassCount
#undef SoeventClassCompare
}
#pragma dont_inline on
s32 fn_801D2C20(s32 arg0) {
    /* Look up a soevent class entry by id in the sorted class table; returns 0 if the id is non-positive or not found. */
#define sSoeventClassTable lbl_80438958
#define sSoeventClassCount lbl_8055E930
#define SoeventClassCompare fn_801D2BF4
    s32 sp8;
    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    return fn_800241DC(&sp8, sSoeventClassTable, sSoeventClassCount, 0x4C4, SoeventClassCompare);
#undef sSoeventClassTable
#undef sSoeventClassCount
#undef SoeventClassCompare
}
#pragma dont_inline off

extern u8 lbl_80438898[];
extern f32 lbl_8055E3C8;
extern void fn_801796CC(s32, f32 *, s32);
#pragma scheduling invalid_target
void fn_801D2C70(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    struct Temp {
        f32 position[3];
        f32 velocity[3];
        s16 type;
        s16 pad;
        s32 id;
    } temp;
    register u8 *entry = (u8 *)arg0;
    register f32 *vec = (f32 *)arg1;
    register s32 i = 0;
    register u8 *object = (u8 *)arg2;
    register s32 id = arg3;
    register s32 active;
    register s32 index;
    register f32 z, y, x;
    f32 p2, p1, p0;
    p0 = vec[0];
    p1 = vec[1];
    p2 = vec[2];
    temp.position[0] = p0;
    temp.position[1] = p1;
    temp.position[2] = p2;
    temp.velocity[0] = *(f32 *)(object + 0x118);
    temp.velocity[1] = *(f32 *)(object + 0x11C);
    temp.velocity[2] = *(f32 *)(object + 0x120);
    temp.type = *(s16 *)(object + 0x6C);
    active = 1;
    for (; i < *(s32 *)((u8 *)arg0 + 0x28); entry += 8, i++) {
        if (*(s32 *)(entry + 8) < 0) {
            temp.id = id;
            fn_801796CC(10, (f32 *)&temp, 0x20);
            {
                s32 isType = 0;
                u32 type = *(u32 *)(object + 0x10);
                if (type == 0x43415220) goto valid_type;
                if (type == 0x50434152) goto valid_type;
                if (type == 0x41434152) goto valid_type;
                if (type == 0x4E434152) goto valid_type;
                goto done_type;
            valid_type:
                isType = 1;
            done_type:
                if (isType != 0) {
                    u8 *record;
                    f32 f8val;
                    index = *(s32 *)(object + 0x1EC) * 0x18;
                    f8val = *(f32 *)(entry + 0xC) + lbl_8055E3C8;
                    record = (u8 *)(lbl_80438898 + index);
                    *record++ = (u8)active;
                    *(s32 *)(record + 3) = temp.id;
                    *(f32 *)(lbl_80438898 + index + 8) = f8val;
                    {
                        f32 vx = vec[0];
                        f32 vy = vec[1];
                        f32 vz = vec[2];
                        x = vx - *(f32 *)(object + 0x60);
                        *(f32 *)(record + 0xB) = x;
                        y = vy - *(f32 *)(object + 0x64);
                        *(f32 *)(record + 0xF) = y;
                        z = vz - *(f32 *)(object + 0x68);
                        *(f32 *)(record + 0x13) = z;
                    }
                    {
                        f32 m40 = *(f32 *)(object + 0x40);
                        f32 m3c = *(f32 *)(object + 0x3C);
                        f32 m48 = *(f32 *)(object + 0x48);
                        f32 m44 = *(f32 *)(object + 0x44);
                        f32 m4c = *(f32 *)(object + 0x4C);
                        f32 m50 = *(f32 *)(object + 0x50);
                        f32 m54 = *(f32 *)(object + 0x54);
                        f32 m58 = *(f32 *)(object + 0x58);
                        f32 m5c = *(f32 *)(object + 0x5C);
                        *(f32 *)(record + 0xB) = z * m44 + (x * m3c + y * m40);
                        *(f32 *)(record + 0xF) = z * m50 + (x * m48 + y * m4c);
                        *(f32 *)(record + 0x13) = z * m5c + (x * m54 + y * m58);
                    }
                }
            }
        }
    }
}

extern f32 lbl_80562A98;
extern f32 lbl_80562A9C;
extern f32 lbl_80558DC4[];
extern f32 fn_80129DC4(s32, f32, f32);
extern void *fn_801D32E0(s32, s32, f32 *, f32 *, void *, void *);
extern f32 PSVECDotProduct(f32 *, f32 *);
extern void PSVECNormalize(f32 *, f32 *);
extern f32 fabs(f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float __fabsf(float);
void fn_801D2E38(void *a0, void *a1, s32 a2, void *a3, f32 scale) {
    struct Tail { s32 w[9]; f32 v[3]; } tail;
    register u8 *arg0 = a0;
    register f32 *arg1 = a1;
    register s32 *arg2 = (s32 *)a2;
    register f32 *arg3 = a3;
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp14[3];
    s32 sp8[3];
    f32 inv, a, b, c, d;
    f32 c9C;
    register f32 c98;
    u8 *e;
    void *r7;
    s32 r24;
    u8 *obj;
    f32 g1, g2, g3;
    s32 *src = (s32 *)arg1;
    s32 i;
    #define sp38 tail.w
    #define sp5C tail.v
    c9C = lbl_80562A9C;
    c98 = lbl_80562A98;
    sp38[0] = src[1];
    sp38[1] = src[2];
    inv = scale / c98;
    sp38[2] = src[3];
    sp2C[0] = arg3[0]; sp2C[1] = arg3[1]; sp2C[2] = arg3[2];
    sp2C[0] = arg3[0] * inv; sp2C[1] = arg3[1] * inv; sp2C[2] = arg3[2] * inv;
    sp38[3] = src[4]; sp38[4] = src[5]; sp38[5] = src[6];
    sp38[6] = src[7]; sp38[7] = src[8]; sp38[8] = src[9];
    i = 0;
    if (*(s32 *)(arg0 + 0x490) > 0) {
        e = arg0 + 0x40;
        for (; i < *(s32 *)(arg0 + 0x490); i++, e += 0x5C) {
            sp20[0] = *(f32 *)(e + 0x38) * c9C;
            sp20[1] = *(f32 *)(e + 0x3C) * c9C;
            sp20[2] = *(f32 *)(e + 0x40) * c9C;
            if (sp5C == (f32 *)(e + 0x38)) {
                a = *(f32 *)(e + 0x38); b = *(f32 *)(e + 0x3C); c = *(f32 *)(e + 0x40);
                sp5C[0] = a * arg1[1] + b * arg1[4] + c * arg1[7];
                sp5C[1] = a * arg1[2] + b * arg1[5] + c * arg1[8];
                sp5C[2] = a * arg1[3] + b * arg1[6] + c * arg1[9];
            } else {
                sp5C[0] = *(f32 *)(e + 0x38) * arg1[1] + *(f32 *)(e + 0x3C) * arg1[4] + *(f32 *)(e + 0x40) * arg1[7];
                sp5C[1] = *(f32 *)(e + 0x38) * arg1[2] + *(f32 *)(e + 0x3C) * arg1[5] + *(f32 *)(e + 0x40) * arg1[8];
                sp5C[2] = *(f32 *)(e + 0x38) * arg1[3] + *(f32 *)(e + 0x3C) * arg1[6] + *(f32 *)(e + 0x40) * arg1[9];
            }
            sp5C[0] += arg1[10];
            sp5C[1] += arg1[11];
            sp5C[2] += arg1[12];
            if (*e != 0) { r7 = e + 4; } else { r7 = arg0 + 8; }
            if (*e != 0) { r24 = *(s32 *)(e + 0x20); } else { r24 = *(s32 *)(arg0 + 0x24); }
            obj = fn_801D32E0(*(s32 *)(arg0 + 0x3C), *(s32 *)(e + 0x58), (f32 *)sp38, sp20, r7, arg1);
            d = *(f32 *)(e + 0x50);
            sp14[0] = sp2C[0] * d; sp14[1] = sp2C[1] * d; sp14[2] = sp2C[2] * d;
            sp8[0] = arg2[0]; sp8[1] = arg2[1]; sp8[2] = arg2[2];
            (*(Vt801E **)obj)->fn48(obj, sp14, (f32 *)sp8, r24, 0);
            d = *(f32 *)(obj + 0xD4) / c98;
            sp14[0] = *(f32 *)(e + 0x44) * d;
            sp14[1] = *(f32 *)(e + 0x48) * d;
            sp14[2] = *(f32 *)(e + 0x4C) * d;
            (*(Vt801E **)obj)->fn48(obj, sp14, sp5C, r24, 0);
            g3 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            g2 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            g1 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            sp14[0] = g1; sp14[1] = g2; sp14[2] = g3;
            if (!((f32)__fabsf(PSVECDotProduct(sp14, sp14)) <= lbl_80558DC4[0])) {
                PSVECNormalize(sp14, sp14);
                d = fn_80129DC4(4, lbl_80562A90, *(f32 *)(e + 0x54));
                sp14[0] *= d; sp14[1] *= d; sp14[2] *= d;
                (*(Vt801E **)obj)->fn48(obj, sp14, sp5C, r24, 0);
            }
        }
    }
    #undef sp38
    #undef sp5C
}
#pragma pop

#pragma dont_inline on
extern void fn_801D2AD4(void *);
extern void fn_801D2C04(void);
/* The three static buffers initialized here live back to back in one block. */
typedef struct { u8 first[0x14]; u8 second[0x10]; u8 third[4]; } Blk801D21C0;
#pragma push
#pragma dont_inline on
#pragma opt_propagation off
void fn_801D21C0(void) {
    register u8 (*base)[0x14] = (u8 (*)[0x14])lbl_803382A8;
    lbl_8055E930 = 0;
    fn_801D2AD4(base[0]);
    fn_801D2AD4((u8 *)base + 0x14);
    fn_801D2AD4((u8 *)base + 0x24);
    fn_801D2C04();
}
#pragma pop
/* Finalize the soevent system. */
void fn_801D2210(void) {
    fn_801D2B94();
}

/* Scene object tags (object+0x10) of the vehicles that carry soevents. */
#define FOURCC_CAR  0x43415220 /* 'CAR ' */
#define FOURCC_PCAR 0x50434152 /* 'PCAR' player truck */
#define FOURCC_ACAR 0x41434152 /* 'ACAR' AI truck */
#define FOURCC_NCAR 0x4E434152 /* 'NCAR' */

/* A scene object as the soevent code sees it. */
typedef struct VehicleObject {
    /* 0x00 */ void *vt;
    /* 0x04 */ u8 pad04[0x0C];
    /* 0x10 */ u32 fourcc;      /* FOURCC_* above */
    /* 0x14 */ u8 pad14[0x28];
    /* 0x3C */ f32 rotation[9]; /* object space -> world */
    /* 0x60 */ Vec position;
    /* 0x6C */ s16 type;
    /* 0x6E */ u8 pad6E[0x66];
    /* 0xD4 */ f32 scale;       /* size of the body, scales what the event emits */
    /* 0xD8 */ u8 padD8[0x40];
    /* 0x118 */ Vec velocity;
    /* 0x124 */ u8 pad124[0xC8];
    /* 0x1EC */ s32 recordIndex; /* its slot in the per-object table lbl_80438898 */
} VehicleObject;

/* One armed soevent spawn: slot N of the 8-record table lbl_80438898, which
 * runs beside the car table lbl_804348E8 (the vehicle it follows).  fn_801D2C70
 * arms a record when a class' spawn group fires; fn_801D2214 reports it every
 * frame until the game clock passes its due time. */
typedef struct SoeventRecord {
    /* 0x00 */ u8 active;    /* record in use */
    /* 0x01 */ u8 pad01[3];
    /* 0x04 */ s32 classId;  /* SoeventClass this spawn is for */
    /* 0x08 */ f32 dueTime;  /* game time the record stops reporting at */
    /* 0x0C */ Vec position; /* spawn point, relative to the vehicle */
} SoeventRecord; /* size 0x18 */

/* Payload of event 10 (fn_801796CC): a soevent spawn in world space. */
typedef struct SoeventSpawnInfo {
    /* 0x00 */ Vec position; /* where to spawn */
    /* 0x0C */ Vec velocity; /* the vehicle's velocity */
    /* 0x18 */ s16 type;     /* vehicle type field (object+0x6C) */
    /* 0x1A */ s16 pad1A;
    /* 0x1C */ s32 classId;  /* SoeventClass being spawned */
} SoeventSpawnInfo; /* size 0x20, which is what the event carries */

extern s32 fn_801B2F24(void);
extern void *lbl_804348E8[];
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
void fn_801D2214(void) {
#define sSoeventRecords lbl_80438898 /* the 8 spawn records, one per car slot */
#define sCarTable lbl_804348E8 /* this race's vehicles; fn_801B2F24() of them */
#define sGameTime lbl_8055E3C8 /* current game time, in seconds */
    SoeventSpawnInfo event;
    f32 now;
    s32 carCount;
    SoeventRecord *record;
    void **carSlot;
    s32 i;
    s32 zero;
    /* Once the clock passes a record's due time it is done; until then the
     * spawn is reported again every frame, tracking the vehicle it follows. */
    carCount = fn_801B2F24();
    now = sGameTime;
    record = (SoeventRecord *)sSoeventRecords;
    carSlot = sCarTable;
    i = 0;
    zero = 0;
    for (; i < carCount; record++, carSlot++, i++) {
        if (record->active != 0) {
            if (now > record->dueTime) {
                record->active = (u8)zero;
            } else {
                VehicleObject *vehicle = (VehicleObject *)*carSlot;
                if (&event.position == &record->position) {
                    /* In place: every product of a row has to be formed from
                     * the saved vector before that row is written back. */
                    const f32 *rotation = vehicle->rotation;
                    f32 x, y, z;
                    f32 m00, m10, m20, m01, m11, m21, m02, m12, m22;
                    m10 = rotation[3]; m11 = rotation[4]; m12 = rotation[5];
                    m00 = rotation[0]; m01 = rotation[1]; m02 = rotation[2];
                    m20 = rotation[6]; m21 = rotation[7]; m22 = rotation[8];
                    x = record->position.x; y = record->position.y; z = record->position.z;
                    event.position.x = z * m20 + (x * m00 + y * m10);
                    event.position.y = z * m21 + (x * m01 + y * m11);
                    event.position.z = z * m22 + (x * m02 + y * m12);
                } else {
                    /* Vehicle space -> world: v * rotation, row by row.  The
                     * volatile reads are what keeps the loads in this order. */
                    const volatile f32 *rotation = (const volatile f32 *)vehicle->rotation;
                    f32 m10, x, m00, y, m20, z, m11, m01, m21, m12, m02, m22;
                    m10 = rotation[3];
                    y = *(volatile f32 *)&record->position.y;
                    m00 = rotation[0];
                    x = *(volatile f32 *)&record->position.x;
                    m20 = rotation[6];
                    z = *(volatile f32 *)&record->position.z;
                    event.position.x = x * m00 + y * m10 + z * m20;
                    m11 = rotation[4];
                    m01 = rotation[1];
                    m21 = rotation[7];
                    event.position.y = x * m01 + y * m11 + z * m21;
                    m12 = rotation[5];
                    m02 = rotation[2];
                    m22 = rotation[8];
                    event.position.z = x * m02 + y * m12 + z * m22;
                }
                event.position.x += vehicle->position.x;
                event.position.y += vehicle->position.y;
                event.position.z += vehicle->position.z;
                event.velocity.x = vehicle->velocity.x;
                event.velocity.y = vehicle->velocity.y;
                event.velocity.z = vehicle->velocity.z;
                event.type = vehicle->type;
                event.classId = record->classId;
                fn_801796CC(10, (f32 *)&event, 0x20); /* EFX: spawn this soevent */
            }
        }
    }
#undef sSoeventRecords
#undef sCarTable
#undef sGameTime
}
#pragma pop
extern f32 PSVECMag(void*);
extern void fn_801A4868(void*, int);
extern void fn_801D2C70(void*, s32, void*, s32);
extern void fn_801D2E38(void*, void*, s32, void*, f32);
extern void fn_802E317C(const char*, ...);
extern const char lbl_803382DC[];

/* A live soevent instance; fn_801A4A8C builds one from a class id and a matrix. */
typedef struct SoeventInstance {
    /* 0x00 */ void *vt;
    /* 0x04 */ f32 matrix[12];  /* instance space -> world */
    /* 0x34 */ s32 classId;     /* SoeventClass to run, -1 when unbound */
    /* 0x38 */ s32 instanceId;  /* reported when the state below changes */
    /* 0x3C */ void *owner;
    /* 0x40 */ u8 active;       /* fn_801A4868 clears it and posts the change */
    /* 0x41 */ u8 pad41[7];
    /* 0x48 */ s32 extra;       /* second handler, run by fn_801D0738 */
} SoeventInstance;

/* One spawn slot of a class' first group (fn_801D2C70 takes a free one). */
typedef struct SoeventSpawn {
    /* 0x00 */ s32 itemId;      /* item class index, -1 while free */
    /* 0x04 */ f32 bonus;       /* added to the time the spawn is due */
} SoeventSpawn;

/* One record of the soevent class table lbl_80438958 (lbl_8055E930 of them,
 * sorted by id; fn_801D2A24 fills one from a 'soevent' scene object). */
typedef struct SoeventClass {
    /* 0x00 */ s32 id;
    /* 0x04 */ u8 spawnActive;    /* first group armed */
    /* 0x08 */ f32 spawnMinSpeed; /* vehicle speed it needs */
    /* 0x0C */ SoeventSpawn spawns[4];
    /* 0x2C */ s32 spawnCount;
    /* 0x30 */ u8 emitActive;     /* particle group armed */
    /* 0x34 */ f32 emitMinSpeed;
    /* 0x38 */ u8 pad38[0x34];
    /* 0x6C */ s32 resHandle;     /* archive holding the emitted models */
    /* 0x70 */ u8 emitters[0x450]; /* 0x5C-byte emitters, fn_801D2E38 runs them */
    /* 0x4C0 */ s32 emitCount;
} SoeventClass; /* size 0x4C4 */

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Run one vehicle's soevent instance against its class record: once the truck's
 * speed passes a group's threshold, take a free spawn slot for it (fn_801D2C70)
 * or run the class' particle emitters around the vehicle and switch the instance
 * off (fn_801A4868). A class id with no record is fatal. */
void fn_801D2414(SoeventInstance *instance, Vec *position, VehicleObject *object) {
    u32 fourcc = object->fourcc;
    s32 isCar = 0; /* reused below as the class id of the error message */
    SoeventClass *entry;

    if (fourcc == FOURCC_CAR || fourcc == FOURCC_PCAR ||
        fourcc == FOURCC_ACAR || fourcc == FOURCC_NCAR) {
        isCar = 1;
    }
    if (isCar != 0) {
        entry = (SoeventClass *)fn_801D2C20(instance->classId);
        if (entry != 0) {
            register f32 speed = PSVECMag(&object->velocity);
            if (entry->spawnActive != 0 &&
                speed > entry->spawnMinSpeed) {
                fn_801D2C70(&entry->spawnActive, (s32)position, object,
                            instance->classId);
            }
            if (entry->emitActive != 0) {
                if (speed > entry->emitMinSpeed) {
                    fn_801D2E38(&entry->emitActive, instance, (s32)position,
                                &object->velocity, object->scale);
                    fn_801A4868(instance, 0);
                }
            }
        } else {
            isCar = instance->classId;
            if (isCar > 0) {
                fn_802E317C(lbl_803382DC, isCar); /* soevent: no such event class */
            }
        }
    }
}
#pragma pop

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" u8 fn_801D2550(void *arg0, void *arg1) {
    struct Dummy {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual f32 fn28(void *, f32);
    };
    f32 value = lbl_80562A90;
    if (arg1 != NULL) {
        *(u8 *)arg0 = 1;
        *(f32 *)((u8 *)arg0 + 4) = ((Dummy *)arg1)->fn28(lbl_80338300, value);
    } else {
        *(u8 *)arg0 = 0;
    }
    return *(u8 *)arg0;
}
#pragma scheduling on
#pragma cplusplus reset
extern void fn_801345D8(char*, int, const char*, ...);
extern const char lbl_8033830C[];
extern u32 lbl_8055ABE4;
#pragma dont_inline on
#pragma cplusplus on
void fn_801D25BC(void *arg0, void *arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual s32 fn1C(u32);
        virtual void f4();
        virtual void f6();
        virtual void f7();
        virtual f32 fn28(void *, f32);
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void *fn5C(u32);
    };
    char name[0x20];
    Dummy *item;
    long index;
    f32 value;
    s32 i;
    if (((s32 (*)(void))fn_801D2550)() != 0) {
        *(s32 *)((char *)arg0 + 8) = -1;
        i = 0;
        *(s32 *)((char *)arg0 + 0x28) = i + 1;
        while (*(s32 *)((char *)arg0 + 0x28) < 4) {
            fn_801345D8(name, 0x20, lbl_8033830C);
            item = (Dummy *)((Dummy *)arg1)->fn5C((u32)name);
            if (item == 0) {
                break;
            }
            index = item->fn1C((u32)&lbl_8055ABE0);
            value = lbl_80562A90;
            *(s32 *)((char *)arg0 + *(s32 *)((char *)arg0 + 0x28) * 8 + 8) = index;
            value = item->fn28((void *)&lbl_8055ABE4, value);
            *(f32 *)((char *)arg0 + *(s32 *)((char *)arg0 + 0x28) * 8 + 0xC) = value;
            *(s32 *)((char *)arg0 + 0x28) = *(s32 *)((char *)arg0 + 0x28) + 1;
        }
    }
}

#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void fn_801D26C8(void *arg0, void *arg1) {
    class Scn {
    public:
        virtual void v0();
        virtual s32 v1(const char *);
        virtual void v2();
        virtual void *v3(const char *);
        virtual void v4();
        virtual void v5();
        virtual s32 v6(const char *, s32);
        virtual void v7();
        virtual f32 v8(const char *, f32);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12(Vec *, const char *, Vec *);
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void *v21(const char *);
    };
    char name[32];
    Vec ret1;
    Vec def1;
    Vec init1;
    Vec ret2;
    Vec def2;
    Vec init2;
    unsigned char *base = lbl_803382A8;
    Vec *pDef1;
    Vec *pDef2;
    float zero;
    Scn *obj = (Scn *)arg1;
    unsigned char *self = (unsigned char *)arg0;
    Scn *child;
    unsigned char *entry;
    if (((s32 (*)(void *, void *))fn_801D2550)(arg0, arg1)) {
        if (obj->v1((const char *)(base + 0x70)))
            fn_801D3610(self + 8, obj->v3((const char *)(base + 0x70)));
        else
            fn_801D334C(self + 8, arg1);
        *(int *)(self + 0x2C) = obj->v6((const char *)(base + 0x7C), -1);
        *(int *)(self + 0x3C) = fn_802C6FC0(obj->v3((const char *)lbl_8055ABE8), 0, 0);
        zero = lbl_80562A90;
        pDef1 = &def1;
        pDef2 = &def2;
        *(int *)(self + 0x490) = 0;
        while (*(int *)(self + 0x490) < 12) {
            fn_801345D8(name, 32, (const char *)lbl_8055ABF0, *(int *)(self + 0x490) + 1);
            if (!obj->v21(name))
                break;
            child = (Scn *)obj->v21(name);
            entry = self + *(int *)(self + 0x490) * 0x5C;
            init1.x = init1.y = init1.z = zero;
            def1 = init1;
            child->v12(&ret1, (const char *)lbl_8055ABF8, pDef1);
            *(float *)(entry + 0x78) = ret1.x;
            *(float *)(entry + 0x7C) = ret1.y;
            *(float *)(entry + 0x80) = ret1.z;
            init2.x = init2.y = init2.z = zero;
            def2 = init2;
            child->v12(&ret2, (const char *)lbl_8055AC00, pDef2);
            *(float *)(entry + 0x84) = ret2.x;
            *(float *)(entry + 0x88) = ret2.y;
            *(float *)(entry + 0x8C) = ret2.z;
            if (child->v1((const char *)lbl_8055AC08))
                *(int *)(entry + 0x98) = parseHexString(child->v3((const char *)lbl_8055AC08));
            else
                *(int *)(entry + 0x98) = -1;
            if ((unsigned char)child->v21((const char *)(base + 0x70)) != 0) {
                fn_801D334C(entry + 0x44, child->v21((const char *)(base + 0x70)));
                entry[0x40] = 1;
            } else
                entry[0x40] = 0;
            *(float *)(entry + 0x90) = child->v8((const char *)lbl_8055AC10, lbl_80562A94);
            *(float *)(entry + 0x94) = child->v8((const char *)(base + 0x88), lbl_80562A90);
            ++*(int *)(self + 0x490);
        }
        if (*(int *)(self + 0x490) < 1) {
            *(int *)(self + 0x98) = -1;
            *(float *)(self + 0x78) = lbl_80562A90;
            *(float *)(self + 0x7C) = lbl_80562A90;
            *(float *)(self + 0x80) = lbl_80562A90;
            *(int *)(self + 0x490) = 1;
        }
    } else {
        *(int *)(self + 0x3C) = -1;
        *(int *)(self + 0x490) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus reset
/* Initializes the next event entry (stride 0x4C4 in lbl_80438958, indexed by lbl_8055E930) from a scene object: id, effect sub-object, and spawn sub-object. */
extern "C" void fn_801D2A24(void *sceneObj_) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual s32 fn1C(u32);
        virtual void v20();
        virtual void v24();
        virtual void v28();
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual void v38();
        virtual void v3C();
        virtual void v40();
        virtual void v44();
        virtual void v48();
        virtual void v4C();
        virtual void v50();
        virtual void v54();
        virtual void v58();
        virtual void *fn5C(u32);
    };
    s32 *eventEntry = (s32 *)(lbl_80438958 + lbl_8055E930 * 0x4C4);
    Dummy *sceneObj = (Dummy *)sceneObj_;
    eventEntry[0] = sceneObj->fn1C((u32)&lbl_8055ABE0); /* "id" */
    fn_801D25BC(&eventEntry[1], sceneObj->fn5C((u32)&lbl_8055AC18)); /* "effect" */
    fn_801D26C8(&eventEntry[12], sceneObj->fn5C((u32)&lbl_8055AC20)); /* "spawn" */
    lbl_8055E930 += 1;
}
#pragma scheduling on
#pragma cplusplus reset

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801D2AD4(void *arg0) {
    /* Scan a global object list and apply event-object setup to each child whose name starts with "soevent". */
    struct Dummy {
        virtual char *fn8();
        virtual Dummy *child(s32);
    };
    Dummy *list = (Dummy *)fn_80131810();
    s32 index;

    if (list == NULL) {
        return;
    }
    index = 0;
    while (list->child(index) != NULL) {
        Dummy *child = list->child(index);
        if (strncmp(child->fn8(), (char *)&lbl_8055AC28, 7) == 0) {
            fn_801D2A24(child);
        }
        index++;
    }
    fn_80131818(list);
}
#pragma scheduling on
#pragma cplusplus reset

