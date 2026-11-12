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
extern u8 lbl_8055ABE8[];
extern u8 lbl_8055ABF8[];
extern u8 lbl_8055AC00[];
extern u8 lbl_8055AC08[];
extern u8 lbl_8055AC10[];
extern u8 lbl_8055ABF0[];
extern void fn_801D334C(void *, void *);
extern void fn_801D3610(void *, void *);
extern s32 fn_802C6FC0(void *, s32, s32);
extern s32 fn_802C7830(void *);

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
    u8 *var_r31;
    s32 var_r30;
    s32 temp;
    var_r31 = lbl_80438958;
    var_r30 = 0;
    while (var_r30 < lbl_8055E930) {
        temp = *(s32 *)(var_r31 + 0x6C);
        if (temp != -1) {
            fn_802C6CF8(temp);
        }
        var_r31 += 0x4C4;
        var_r30 += 1;
    }
}
#pragma dont_inline off

s32 fn_801D2BF4(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

#pragma scheduling invalid_target
void fn_801D2C04(void) {
    qsort(lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}
#pragma scheduling on
#pragma dont_inline on
s32 fn_801D2C20(s32 arg0) {
    s32 sp8;
    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    return fn_800241DC(&sp8, lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
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
    register f32 *vec = (f32 *)arg1;
    register volatile f32 *vecRead = (volatile f32 *)arg1;
    register u8 *object = (u8 *)arg2;
    register u8 *entry = (u8 *)arg0;
    register s32 i = 0;
    register s32 active;
    register s32 index;
    register f32 x, y, z;
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
            temp.id = arg3;
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
                    s32 rawIndex;
                    f32 bonus = lbl_8055E3C8;
                    f32 v0, v1, v2;
                    rawIndex = *(s32 *)(object + 0x1EC);
                    index = rawIndex * 0x18;
                    record = (u8 *)(lbl_80438898 + index);
                    *record++ = (u8)active;
                    *(s32 *)(record + 3) = temp.id;
                    *(f32 *)(lbl_80438898 + index + 8) =
                        *(f32 *)(entry + 0xC) + bonus;
                    v0 = vecRead[0];
                    v1 = vecRead[1];
                    v2 = vecRead[2];
                    x = v0 - *(f32 *)(object + 0x60);
                    y = v1 - *(f32 *)(object + 0x64);
                    z = v2 - *(f32 *)(object + 0x68);
                    *(f32 *)(record + 0xB) = x;
                    *(f32 *)(record + 0xF) = y;
                    *(f32 *)(record + 0x13) = z;
                    *(f32 *)(record + 0xB) =
                        x * *(f32 *)(object + 0x3C) +
                        y * *(f32 *)(object + 0x40) +
                        z * *(f32 *)(object + 0x44);
                    *(f32 *)(record + 0xF) =
                        x * *(f32 *)(object + 0x48) +
                        y * *(f32 *)(object + 0x4C) +
                        z * *(f32 *)(object + 0x50);
                    *(f32 *)(record + 0x13) =
                        x * *(f32 *)(object + 0x54) +
                        y * *(f32 *)(object + 0x58) +
                        z * *(f32 *)(object + 0x5C);
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
void fn_801D2E38(void *a0, void *a1, s32 a2, void *a3, f32 scale) {
    u8 *arg0 = a0;
    f32 *arg1 = a1;
    f32 *arg2 = (f32 *)a2;
    f32 *arg3 = a3;
    f32 sp8[3];
    f32 sp14[3];
    f32 sp20[3];
    f32 sp2C[3];
    s32 sp38[9];
    f32 sp5C[3];
    f32 inv, a, b, c, d;
    s32 i;
    u8 *e;
    void *r7;
    s32 r24;
    u8 *obj;
    f32 g1, g2, g3;
    s32 *src = (s32 *)arg1;

    inv = scale / lbl_80562A98;
    sp38[0] = src[1]; sp38[1] = src[2];
    sp2C[0] = arg3[0]; sp2C[1] = arg3[1]; sp2C[2] = arg3[2];
    sp38[2] = src[3];
    sp2C[0] = arg3[0] * inv; sp2C[1] = arg3[1] * inv; sp2C[2] = arg3[2] * inv;
    sp38[3] = src[4]; sp38[4] = src[5]; sp38[5] = src[6];
    sp38[6] = src[7]; sp38[7] = src[8]; sp38[8] = src[9];
    i = 0;
    if (*(s32 *)(arg0 + 0x490) > 0) {
        e = arg0 + 0x40;
        for (; i < *(s32 *)(arg0 + 0x490); i++, e += 0x5C) {
            sp20[0] = *(f32 *)(e + 0x38) * lbl_80562A9C;
            sp20[1] = *(f32 *)(e + 0x3C) * lbl_80562A9C;
            sp20[2] = *(f32 *)(e + 0x40) * lbl_80562A9C;
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
            (*(Vt801E **)obj)->fn48(obj, sp14, sp8, r24, 0);
            d = *(f32 *)(obj + 0xD4) / lbl_80562A98;
            sp14[0] = *(f32 *)(e + 0x44) * d;
            sp14[1] = *(f32 *)(e + 0x48) * d;
            sp14[2] = *(f32 *)(e + 0x4C) * d;
            (*(Vt801E **)obj)->fn48(obj, sp14, sp5C, r24, 0);
            g3 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            g2 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            g1 = fn_80129DC4(4, lbl_80562A90, lbl_80562A94);
            sp14[0] = g1; sp14[1] = g2; sp14[2] = g3;
            if (fabs(PSVECDotProduct(sp14, sp14)) > lbl_80558DC4[0]) {
                PSVECNormalize(sp14, sp14);
                d = fn_80129DC4(4, lbl_80562A90, *(f32 *)(e + 0x54));
                sp14[0] *= d; sp14[1] *= d; sp14[2] *= d;
                (*(Vt801E **)obj)->fn48(obj, sp14, sp5C, r24, 0);
            }
        }
    }
}
#pragma pop

#pragma dont_inline on
extern void fn_801D2AD4(void *);
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801D21C0(void) {
    lbl_8055E930 = 0;
    fn_801D2AD4(lbl_803382A8);
    fn_801D2AD4(lbl_803382A8 + 0x14);
    fn_801D2AD4(lbl_803382A8 + 0x24);
    fn_801D2C04();
}
void fn_801D2210(void) {
    fn_801D2B94();
}

extern s32 fn_801B2F24(void);
extern void *lbl_804348E8[];
#pragma scheduling invalid_target
#pragma paired reset
#pragma paired_single reset
void fn_801D2214(void) {
    struct Record { u8 active; u8 pad[3]; s32 id; f32 time; f32 position[3]; };
    struct Temp { f32 position[3]; f32 velocity[3]; s16 type; s16 pad; s32 id; } temp;
    f32 threshold;
    s32 count;
    struct Record *record;
    void **objects;
    s32 i;
    s32 zero;
    count = fn_801B2F24();
    threshold = lbl_8055E3C8;
    record = (struct Record *)lbl_80438898;
    objects = lbl_804348E8;
    i = 0;
    zero = 0;
    for (; i < count; record++, objects++, i++) {
        if (record->active != 0) {
            if (threshold > record->time) record->active = (u8)zero;
            else {
                u8 *object = (u8 *)*objects;
                if (&temp.position[0] == &record->position[0]) {
                    volatile f32 *matrix = (volatile f32 *)object;
                    f32 x = record->position[0];
                    f32 y = record->position[1];
                    f32 z = record->position[2];
                    f32 out0 = y * matrix[0x48 / 4] +
                               z * matrix[0x54 / 4] +
                               x * matrix[0x3C / 4];
                    f32 out1 = y * matrix[0x4C / 4] +
                               z * matrix[0x58 / 4] +
                               x * matrix[0x40 / 4];
                    f32 out2 = y * matrix[0x50 / 4] +
                               z * matrix[0x5C / 4] +
                               x * matrix[0x44 / 4];
                    temp.position[0] = out0;
                    temp.position[1] = out1;
                    temp.position[2] = out2;
                } else {
                    volatile f32 *matrix = (volatile f32 *)object;
                    f32 m48, x, m3c, y, m54, z, m4c, m40, m58, m50, m44, m5c;
                    m48 = matrix[0x48 / 4];
                    y = *(volatile f32 *)&record->position[1];
                    m3c = matrix[0x3C / 4];
                    x = *(volatile f32 *)&record->position[0];
                    m54 = matrix[0x54 / 4];
                    z = *(volatile f32 *)&record->position[2];
                    temp.position[0] = x * m3c + y * m48 + z * m54;
                    m4c = matrix[0x4C / 4];
                    m40 = matrix[0x40 / 4];
                    m58 = matrix[0x58 / 4];
                    temp.position[1] = x * m40 + y * m4c + z * m58;
                    m50 = matrix[0x50 / 4];
                    m44 = matrix[0x44 / 4];
                    m5c = matrix[0x5C / 4];
                    temp.position[2] = x * m44 + y * m50 + z * m5c;
                }
                temp.position[0] += *(f32 *)(object + 0x60);
                temp.position[1] += *(f32 *)(object + 0x64);
                temp.position[2] += *(f32 *)(object + 0x68);
                temp.velocity[0] = *(f32 *)(object + 0x118);
                temp.velocity[1] = *(f32 *)(object + 0x11C);
                temp.velocity[2] = *(f32 *)(object + 0x120);
                temp.type = *(s16 *)(object + 0x6C);
                temp.id = record->id;
                fn_801796CC(10, (f32 *)&temp, 0x20);
            }
        }
    }
}
extern f32 PSVECMag(void*);
extern void fn_801A4868(void*, int);
extern void fn_801D2C70(void*, s32, void*, s32);
extern void fn_801D2E38(void*, void*, s32, void*, f32);
extern void fn_802E317C(const char*, ...);
extern const char lbl_803382DC[];

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
    if (arg1 != NULL) {
        u8 flag = 1;
        f32 value = lbl_80562A90;
        *(u8 *)arg0 = flag;
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
        virtual void f4();
        virtual s32 fn1C(u32);
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
    s32 index;
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
#pragma cplusplus reset
#pragma cplusplus on
#pragma scheduling invalid_target
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

