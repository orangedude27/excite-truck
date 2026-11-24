#include "types.h"
#include <string.h>

#pragma ppc_psq_save off

/* One 0x20-byte group entry of the pickup manager behind lbl_8055E354
 * (0x1E15C bytes, allocated by fn_801679F0, freed by fn_80167EEC).  The manager keeps a pool of
 * 0x18-byte object records (pool pointer at +0x00, count at +0x04, capacity
 * 0x1388 records at +0x08) and an array of these group entries (array pointer
 * at +0x1D4CC, count at +0x1D4D0, capacity 0x64 entries at +0x1D4D4); each
 * group covers the records [recordStart, recordStart + recordCount) of the
 * pool.  fn_80168104 skips a group while `active` is clear. */
struct GroupEntry {
    s32 id;          /* +0x00: group id, matched by fn_801688B4 / fn_801688FC */
    u8 active;       /* +0x04: group takes part in the update */
    u8 pad_05[3];
    f32 x;           /* +0x08: group centre, used for the distance test */
    f32 z;           /* +0x0C */
    f32 radius;      /* +0x10 */
    s32 recordStart; /* +0x14: first record of the group in the manager's pool */
    s32 recordCount; /* +0x18: number of records in the group */
    u8 hasRadius;    /* +0x1C: radius above is set (fn_80168104) */
    u8 flag_1D;      /* +0x1D: per-frame flag, cleared by fn_80168020 */
    u8 pad_1E[2];
};

/* One entry of the static pickup-type table at lbl_80330020: the five types
 * 0..4 followed by a terminator whose type is 6.  fn_80167874 looks a type up
 * in it, fn_801679F0 loads every type's model and measures it, and the
 * placement code counts the pickups it spawns of each type in placedCount. */
struct PickupTypeInfo {
    s32 type;          /* +0x00: pickup type id; 6 ends the table */
    const char *model; /* +0x04: model file name, e.g. "growcoin.mod" */
    u8 settings[8];    /* +0x08: per-type byte settings (+0x0C is 0x5f) */
    s32 modelHandle;   /* +0x10: model instance from fn_802C6FC0, -1 when none */
    f32 modelRadius;   /* +0x14: widest model extent, scaled */
    f32 modelHeight;   /* +0x18: model bottom negated; the lift given to a pickup */
    s32 placedCount;   /* +0x1C: pickups of this type placed in the track */
};

#pragma cplusplus on

struct DummyVec2 {
    f32 x;
    f32 y;
};

class DummyItem {
public:
    virtual void v0();
    virtual s32 v1(const char *name);
    virtual void v2();
    virtual void v3(const char *name);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 getHit(const char *name);
    virtual f32 v8(const char *name, f32 value);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual DummyVec2 getLoc(const char *name);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void *getObject(const char *name, s32 x, s32 y, void *arg);
};

class DummyArg1 {
public:
    virtual const char *getName();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual DummyItem *getItem(s32 index);
};

struct DummyRecordObj {
    u8 pad[0x18];
    f32 f18;
};

struct DummyRecord {
    DummyRecordObj *obj;
    f32 x;
    f32 y;
    f32 z;
    f32 hit;
    u8 flag;
    u8 pad[3];
};

struct DummyEntry {
    s32 id;
    u8 active;
    u8 pad5[3];
    f32 f8;
    f32 fC;
    f32 f10;
    s32 recordStart;
    s32 recordCount;
    u8 byte1C;
    u8 byte1D;
    u8 pad1E[2];
};

struct DummyManager {
    DummyRecord *records;   /* +0x00: pickup records, the 0x18-byte pool inlined at +0x0C */
    s32 recordCount;        /* +0x04: records in use */
    s32 recordCapacity;     /* +0x08: pool size, 0x1388 records */
    u8 pad0C[0x1D4CC - 0xC];
    DummyEntry *entries;    /* +0x1D4CC: the pickup groups */
    s32 entryCount;         /* +0x1D4D0: groups in use */
    s32 entryCapacity;      /* +0x1D4D4: group array size, 0x64 groups */
    u8 pad1D4D8[0x1E158 - 0x1D4D8];
    u8 flag1E158;           /* +0x1E158: keep adding records to the last group */
};

/* One entry of the 16-entry spin-matrix table at lbl_8042FF60 (48 bytes each).
   fn_801678D8 fills rot[] with a Y-axis rotation; the consumer (fn_80168020)
   picks an entry by (record/12)&0xF and writes translate[] per object. */
struct SpinMatrix {
    f32 rot[9];      /* 3x3 rotation about the Y axis */
    f32 translate[3]; /* object position, filled in by the consumer */
};

extern "C" {
extern char lbl_8055A1C0[8];
extern char lbl_8055A1C8[4];
extern char lbl_8055A1CC[4];
extern f32 lbl_80561924;
extern f32 lbl_80561938;
extern f32 lbl_80561950;
extern double lbl_80561930;
extern char lbl_80330000[];
extern s32 *fn_801399FC(DummyArg1 *);
extern s32 fn_80128658(s32 *);
extern void fn_802E30C8(const char *, ...);
extern int stricmp(const char *, const char *);
extern unsigned long long fn_80139C5C(s32 *);
extern s32 fn_801698B8(s32, s32, s32, s32);
extern s32 fn_80169928(s32, s32, s32, s32);
extern double fn_8002F234(f32);

int sscanf(const char *, const char *, ...);
void fn_801E9E30(void *, f32 *);
void fn_801EA1E0(f32 *, s32, f32, f32);
}

#pragma cplusplus reset

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
extern s32 lbl_8055E354;
extern s32 lbl_80430260[];
extern s32 fn_80128668(void);
extern char lbl_80330020[];
extern char lbl_803300E0[];
extern void Abend_Panic(const char *, ...);
#pragma optimization_level 2
#pragma scheduling invalid_target
#pragma dont_inline on
/* Look up the pickup type info entry for the given type id and return it.
   Logs an error and returns the first entry if the type is not found. */
s32 *fn_80167874(s32 type) {
    s32 *entry;
    s32 entryType;
    for (entry = (s32 *)lbl_80330020; (entryType = *entry) != 6; entry += 8) {
        if (entryType == type)
            return entry;
    }
    Abend_Panic(lbl_803300E0, type);
    return (s32 *)lbl_80330020;
}
#pragma scheduling on
#pragma optimization_level reset
#pragma dont_inline reset
extern double cos(float);
extern double sin(float);
extern int lbl_8055E3C4;
extern float lbl_8055E460;
extern float lbl_80561918, lbl_8056191C, lbl_80561920, lbl_80561924, lbl_80561928;
extern double lbl_80561930;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma optimize_for_size off
/* Rebuilds the 16-entry spin-matrix table at lbl_8042FF60. Entry i holds a
   Y-axis rotation by 2*pi*(phase + i/16) -- 22.5 degrees apart -- where phase
   advances with the frame timer (lbl_8055E3C4 + lbl_8055E460). The trailing
   translate[] of each entry is left for fn_80168020 to fill per object. */
void fn_801678D8(void) {
    extern unsigned char lbl_8042FF60[];
    struct SpinMatrix *mtx;
    float s;
    float c;
    float phase;
    float one;
    float zero;
    float twoPi;
    float step;
    float whole;
    float frac;
    int i;
    mtx = (struct SpinMatrix *)lbl_8042FF60;
    i = 0;
    frac = lbl_8055E460;
    whole = (float)lbl_8055E3C4;
    step = lbl_80561920;
    twoPi = lbl_8056191C;
    zero = lbl_80561924;
    one = lbl_80561928;
    phase = lbl_80561918 * (whole + frac);
    do {
        c = (float)cos(twoPi * (phase + ((float)i * step)));
        s = (float)sin(twoPi * (phase + ((float)i * step)));
        mtx->rot[0] = c;
        i += 1;
        mtx->rot[1] = zero;
        mtx->rot[2] = -s;
        mtx->rot[3] = zero;
        mtx->rot[4] = one;
        mtx->rot[5] = zero;
        mtx->rot[6] = s;
        mtx->rot[7] = zero;
        mtx->rot[8] = c;
        mtx += 1;
    } while (i < 0x10);
}
#pragma pop
extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(s32);
extern void *fn_801284F8(s32, void *, void *, void *);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void fn_802C77F0();
extern void *fn_80131810(void);
extern void fn_80131818(void *);
extern void fn_80168020(void);
extern void fn_80167EE0(s32 *);
extern int *fn_80167E98(int *, int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801679F0(void) {
    class DummyShortItem {
    public:
        virtual s32 v1(const char *name);
        virtual void v0();
        virtual void v2();
        virtual void v3(const char *name);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual f32 v7(const char *name);
        virtual f32 v8(const char *name, f32 value);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual DummyVec2 v13(const char *name);
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void *getObject(const char *name);
    };
    class DummyContainerLocal {
    public:
        virtual void v0();
        virtual DummyArg1 *getItem(s32 index);
    };
    class DummyParamLocal {
    public:
        virtual void v0();
        virtual s32 check(s32 value);
        virtual void apply(DummyArg1 *item, void *manager, s32 *coords);
    };
    extern char lbl_80330000[];
    extern char lbl_80330234[], lbl_80330248[], lbl_8033025C[], lbl_80330270[];
    extern f32 lbl_802F9514[3];
    extern s32 lbl_8055E354;
    extern f32 lbl_80561938;
    struct Local {
        DummyParamLocal *sp8;
        DummyParamLocal *spC;
        DummyParamLocal *sp14;
        DummyParamLocal *sp10;
        s32 sp18[3];
        s32 pad24;
        f32 sp28[6];
        DummyParamLocal **sp40[5];
    } local;
    register u8 *base;
    register void *manager;
    register s32 zero;
    s32 i;
    u8 *entry;
    DummyItem *object;
    DummyArg1 *item;
    DummyContainerLocal *container;
    void *child;
    DummyParamLocal ***slot;
    s32 value;
    s32 result;
    f32 f2;
    f32 f3;
    f32 f0;
    f32 f1;
    f32 scale;

    base = (u8 *)lbl_80330000;
    object = (DummyItem *)*(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    local.sp10 = (DummyParamLocal *)lbl_8033025C;
    local.sp14 = (DummyParamLocal *)lbl_80330270;
    local.sp40[0] = &local.sp8;
    local.spC = (DummyParamLocal *)lbl_80330248;
    local.sp8 = (DummyParamLocal *)lbl_80330234;
    zero = 0;
    local.sp40[4] = (DummyParamLocal **)zero;
    local.sp40[1] = &local.sp14;
    local.sp40[2] = &local.sp10;
    local.sp40[3] = &local.spC;

    manager = fn_801284F8(0x1E15C, base + 0x1D8, &local.sp10, &local.sp14);
    if (manager) {
        *(void **)manager = (u8 *)manager + 0xC;
        *(s32 *)((u8 *)manager + 8) = 0x1388;
        *(s32 *)((u8 *)manager + 4) = zero;
        fn_8002F53C((u8 *)manager + 0xC, fn_80167EE0, fn_80167E98, 0x18, 0x1388);
        scale = lbl_80561938;
        *(u8 **)((u8 *)manager + 0x1D4CC) = (u8 *)manager + 0x1D4D8;
        *(s32 *)((u8 *)manager + 0x1D4D4) = 0x64;
        *(s32 *)((u8 *)manager + 0x1D4D0) = zero;
        entry = base + 0x20;
        i = zero;
        do {
            value = fn_802C6FC0(*(s32 *)(entry + 4), zero, zero);
            *(s32 *)(entry + 0x10) = value;
            *(s32 *)(entry + 0x1C) = zero;
            if (value != -1) {
                fn_802C77F0((void *)value, local.sp28);
                f2 = local.sp28[5] - local.sp28[4];
                f3 = local.sp28[3] - local.sp28[2];
                if (f3 > f2) {
                    f3 = f3;
                } else {
                    f3 = f2;
                }
                f0 = local.sp28[1] - local.sp28[0];
                if (f0 > f3) {
                    f0 = f0;
                } else {
                    f0 = f3;
                }
                *(f32 *)(entry + 0x14) = scale * f0;
                *(f32 *)(entry + 0x18) = -local.sp28[2];
            }
            i++;
            entry += 0x20;
        } while (5 > i);
        *((u8 *)manager + 0x1E158) = zero;
    }
    lbl_8055E354 = (s32)manager;
    if (object->v1((const char *)base + 0x1E8) != 0) {
        local.sp18[0] = ((s32 *)lbl_802F9514)[0];
        local.sp18[1] = ((s32 *)lbl_802F9514)[1];
        local.sp18[2] = ((s32 *)lbl_802F9514)[2];
        result = (s32)object->getObject((const char *)base + 0x1F4, local.sp18[1], local.sp18[0], lbl_802F9514);
        if (((u32)(-result | result) >> 31) != 0) {
            child = ((DummyShortItem *)object)->getObject((const char *)base + 0x1F4);
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x200, *(f32 *)&local.sp18[0]);
            *(f32 *)&local.sp18[0] = f1;
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x210, *(f32 *)&local.sp18[1]);
            *(f32 *)&local.sp18[1] = f1;
            f1 = ((DummyItem *)child)->v8((const char *)base + 0x220, *(f32 *)&local.sp18[2]);
            *(f32 *)&local.sp18[2] = f1;
        }
        ((void (*)(void *, void *))(*(void ***)object)[5])(object, base + 0x1E8);
        container = (DummyContainerLocal *)fn_80131810();
        if (container) {
            i = 0;
            goto item_check;
        item_body:
            for (slot = local.sp40; *slot != 0; slot++) {
                register value = (s32)((DummyArg1 *)item)->getName();
                if (((DummyParamLocal *)*slot)->check(value) != 0) {
                    ((DummyParamLocal *)*slot)->apply(
                        item, (void *)lbl_8055E354, local.sp18);
                    break;
                }
            }
            i += 1;
        item_check:
            item = container->getItem(i);
            if (item)
                goto item_body;
            fn_80131818(container);
        }
    }
    fn_80168020();
}
#pragma cplusplus reset
#pragma pop

s32 fn_80167D58(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80167D98(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80167DD8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80167E18(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree
     * when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80167E58(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* fn_80167E98: scalar deleting-destructor style helper — clears the object's
 * first field, optionally deletes it, and returns the object pointer. */
int *fn_80167E98(int *obj, int shouldDelete) {
    if (obj != 0) {
        *obj = 0;
        if (shouldDelete > 0)
            fn_80128668();
    }
    return obj;
}

/* Array-element constructor (passed to fn_8002F53C): zero a newly constructed record's first field. */
void fn_80167EE0(s32 *record) {
    *record = 0;
}

extern void __array_delete(void *, void *, s32, s32);
extern void fn_802C6CF8(s32);
#pragma cplusplus on
void __array_delete(void *, void *, s32, s32);
void fn_802C6CF8(s32);
extern "C" void fn_80167EEC(void) {
    /* Tear down the pickup manager (lbl_8055E354, the block fn_801679F0 made):
     * forget every placed pickup, reset the placed count of the five pickup
     * types (lbl_80330020), release their models, destroy the record array the
     * manager holds inline at +0xC and free the manager itself. */
    PickupTypeInfo *entry;
    PickupTypeInfo *types;
    s32 i;
    DummyManager *manager = (DummyManager *)(u32)lbl_8055E354;
    if (manager != 0) {
        types = (PickupTypeInfo *)lbl_80330020;
        types[0].placedCount = 0;
        types[1].placedCount = 0;
        types[2].placedCount = 0;
        types[3].placedCount = 0;
        types[4].placedCount = 0;
        i = manager->recordCount;
        while (i-- > 0) {
            manager->records[i].obj = 0;
        }
        manager->recordCount = 0;
        manager->entryCount = 0;
        manager->flag1E158 = 0;
        entry = (PickupTypeInfo *)lbl_80330020;
        i = 0;
        for (; i < 5; i++, entry++) {
            if (entry->modelHandle != -1) {
                fn_802C6CF8(entry->modelHandle);
                entry->modelHandle = -1;
            }
        }
        if (&manager->entries != 0 && &manager->entries != 0) {
            manager->entries = 0;
            manager->entryCount = 0;
            manager->entryCapacity = 0;
        }
        if (manager != 0) {
            __array_delete((u8 *)manager + 0xC, (void *)fn_80167E98, 0x18, 0x1388);
            if (manager != 0) {
                manager->records = 0;
                manager->recordCount = 0;
                manager->recordCapacity = 0;
            }
        }
        ((s32 (*)(void *))fn_80128668)(manager);
    }
}
#pragma cplusplus reset
void fn_80168020(void) {
    /* Per-frame pickup refresh: lift each placed pickup by its model height and
       record hit offset then clear its per-frame flag, clear each group's flag,
       and reset the spin-matrix translation sentinels to -1. */
    register u8 *manager;
    register s32 recordIndex;
    register u8 *pickup;
    register s32 recordOffset;
    register s32 zero;

    manager = (u8 *)(u32)lbl_8055E354;
    recordIndex = 0;
    recordOffset = 0;
    zero = 0;
    goto record_check;
record_body:
    {
        register u8 *object;
        register f32 y;
        register f32 sum;

        pickup = (u8 *)(u32)*(u32 *)manager + recordOffset;
        fn_801E9E30(0, (f32 *)(pickup + 4));
        object = (u8 *)(u32)*(u32 *)pickup;
        recordIndex += 1;
        y = *(f32 *)(pickup + 8);
        recordOffset += 0x18;
        sum = y + *(f32 *)(object + 0x18);
        *(f32 *)(pickup + 8) = sum + *(volatile f32 *)(pickup + 0x10);
        *(u8 *)(pickup + 0x14) = zero;
    }
record_check:
    if (recordIndex < *(s32 *)(manager + 4))
        goto record_body;

    {
        register s32 groupCount = 0;
        register s32 groupOffset = 0;
        register s32 clearByte = 0;
        goto group_check;
group_body:
        {
            register u8 *group = (u8 *)(u32)*(u32 *)(manager + 0x1D4CC) + groupOffset;
            groupCount += 1;
            *(u8 *)(group + 0x1D) = clearByte;
            groupOffset += 0x20;
        }
group_check:
        if (groupCount < *(s32 *)(manager + 0x1D4D0))
            goto group_body;
    }

    {
        register s32 sentinel = -1;
        register s32 *spinTable = lbl_80430260 + 1;
        *--spinTable = sentinel;
        spinTable[4] = sentinel;
        spinTable[8] = sentinel;
        spinTable[12] = sentinel;
        spinTable[16] = sentinel;
        spinTable[20] = sentinel;
        spinTable[24] = sentinel;
        spinTable[28] = sentinel;
    }
}

#pragma processor 750
#pragma use_lmw_stmw off
#pragma push
#pragma opt_common_subs off
#pragma scheduling invalid_target
void fn_80168104(void) {
    extern void *fn_802C86DC(void);
    extern double fn_8002F234(float);
    extern unsigned int fn_802C9994(unsigned int);
    extern unsigned int fn_802C9950(unsigned int);
    extern void fn_802C9900(float);
    extern void fn_802C9904(void);
    extern void fn_802C744C(void *, void *);
    extern unsigned char lbl_8042FF60[];
    extern float lbl_8056193C;
    extern float lbl_80561940;
    extern double lbl_80561948;
    struct { float x, y; } pos, d;
    unsigned char *data = (unsigned char *)fn_802C86DC();
    int i, offset;
    float scale = lbl_80561940;
    float limit = lbl_8056193C;
    pos.x = *(float *)(data + 0x24);
    pos.y = *(float *)(data + 0x2C);
    offset = 0;
    for (i = 0; i < *(int *)((unsigned char *)lbl_8055E354 + 0x1D4D0); i++, offset += 0x20) {
        unsigned char *entry = *(unsigned char **)((unsigned char *)lbl_8055E354 + 0x1D4CC) + offset;
        int j;
        if (entry[4] == 0) continue;
        if (entry[0x1C] == 0 || (d.y = pos.y - *(float *)(entry + 0xC), d.x = pos.x - *(float *)(entry + 8), (float)fn_8002F234(d.x * d.x + d.y * d.y) - *(float *)(entry + 0x10) < limit)) {
            for (j = 0; j < *(int *)(*(unsigned char **)((unsigned char *)lbl_8055E354 + 0x1D4CC) + offset + 0x18); j++) {
                unsigned char *record = *(unsigned char **)lbl_8055E354 + (*(int *)(*(unsigned char **)((unsigned char *)lbl_8055E354 + 0x1D4CC) + offset + 0x14) + j) * 0x18;
                unsigned char *obj = *(unsigned char **)record;
                if (obj != 0 && *(int *)(obj + 0x10) != 0 && record[0x14] == 0) {
                    unsigned int token = obj ? *(unsigned int *)(obj + 8) : (unsigned int)-1;
                    unsigned int a = fn_802C9994(token);
                    unsigned int b = fn_802C9950((((token >> 25) & 0x7F) << 24) | (((token >> 17) & 0x7F) << 16) | (((token >> 9) & 0x7F) << 8) | ((token >> 1) & 0x7F));
                    fn_802C9900((float)(token >> 24) / scale);
                    {
                        unsigned char *out = lbl_8042FF60 + ((*(int *)record / 12) & 0xF) * 0x30;
                        *(float *)(out + 0x24) = *(float *)(record + 4);
                        *(float *)(out + 0x28) = *(float *)(record + 8);
                        *(float *)(out + 0x2C) = *(float *)(record + 0xC);
                        fn_802C744C(*(void **)(*(unsigned int *)record + 0x10), out);
                    }
                    fn_802C9994(a);
                    fn_802C9950(b);
                    fn_802C9904();
                }
            }
        }
    }
}
#pragma pop
void fn_80168328(void)
{
  extern s32 lbl_8055E354;
  extern void fn_801678D8(void);
  s32 *root;
  s32 flag;
  s32 *base;
  s32 one = 1;
  s32 **table;
  s32 j;
  s32 i;
  u8 *entry;
  s32 offset;
  s32 count;
  s32 *slot;
  root = (s32 *) lbl_8055E354;
  fn_801678D8();
  table = (s32 **)((u8 *)root + 0x1D4CC);
  i = 0;
  offset = 0;
  while (i < *((s32 *)((u8 *)table + 4)))
  {
    entry = (u8 *)*table + offset;
    if (entry[0x1D] == 0)
    {
      entry[0x1D] = one;
      count = *((s32 *) (entry + 0x18));
      for (j = 0; j < count; j++)
      {
        flag = 0;
        base = *(s32 **)root;
        slot = (s32 *) ((u8 *)base + (((*((s32 *) (entry + 0x14))) + j) * 0x18));
        if (((*slot) != 0) && ((*(((u8 *) slot) + 0x14)) == 0))
        {
          flag = 1;
        }
        if (flag != 0)
        {
          entry[0x1D] = 0;
          break;
        }
      }
    }
    offset += 0x20;
    i++;
  }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801683F4(void *arg0, s32 arg1) {
    extern s32 lbl_80430260[];
    extern s32 lbl_8055E354;
    extern f32 lbl_80561924;
    extern f32 lbl_80561950;
    extern void *fn_8017960C(s32);
    extern f64 fn_8002F234(f32);
    s32 num;
    s32 i;
    s32 j;
    s32 offset;
    s32 index;
    s32 tableIndex;
    void *object;
    void *bounds;
    void *resource;
    void *entry;
    void *record;
    void *recordObject;
    volatile f32 x;
    volatile f32 z;
    volatile f32 minX;
    volatile f32 maxX;
    volatile f32 minZ;
    volatile f32 maxZ;
    volatile f32 ty;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 tx;
    f32 tz;
    f32 radius;
    s32 counts[7];
    memset(counts, 0, 0x18);
    object = fn_8017960C(arg1);
    tableIndex = arg1 * 4;
    if (lbl_80430260[tableIndex] == lbl_8055E3C4 - 1) {
        num = 0;
        x = *(f32 *)((u8 *)object + 0x60);
        z = *(f32 *)((u8 *)object + 0x68);
        minX = lbl_80561924;
        maxX = lbl_80561924;
        minZ = lbl_80561924;
        maxZ = lbl_80561924;
        ty = lbl_80561924;
        radius = lbl_80561924;
        bounds = *(s32 *)((u8 *)object + 0x24) > 0 ? *(void **)((u8 *)object + 0x14) : 0;
        if (bounds != 0) {
            dx = *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 4) - x;
            dy = *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 8) - *(f32 *)((u8 *)object + 0x64);
            dz = *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 0xC) - z;
            tx = dz * *(f32 *)((u8 *)object + 0x44)
               + (dx * *(f32 *)((u8 *)object + 0x3C)
               + dy * *(f32 *)((u8 *)object + 0x40));
            tz = dz * *(f32 *)((u8 *)object + 0x5C)
               + (dx * *(f32 *)((u8 *)object + 0x54)
               + dy * *(f32 *)((u8 *)object + 0x58));
            ty = dz * *(f32 *)((u8 *)object + 0x50)
               + (dx * *(f32 *)((u8 *)object + 0x48)
               + dy * *(f32 *)((u8 *)object + 0x4C));
            resource = *(void **)((u8 *)bounds + 0x17C);
            minX = tx < lbl_80561924 ? lbl_80561924 : tx;
            minX -= lbl_80561950 * *(f32 *)((u8 *)resource + 0x24);
            minZ = tz < lbl_80561924 ? lbl_80561924 : tz;
            minZ -= lbl_80561950 * *(f32 *)((u8 *)resource + 0x2C);
            maxX = tx > lbl_80561924 ? lbl_80561924 : tx;
            maxX += lbl_80561950 * *(f32 *)((u8 *)resource + 0x24);
            maxZ = tz > lbl_80561924 ? lbl_80561924 : tz;
            maxZ += lbl_80561950 * *(f32 *)((u8 *)resource + 0x2C);
            radius = (f32)fn_8002F234(
                *(f32 *)((u8 *)resource + 0x24) * *(f32 *)((u8 *)resource + 0x24)
              + *(f32 *)((u8 *)resource + 0x2C) * *(f32 *)((u8 *)resource + 0x2C));
        }
        i = 0;
        offset = 0;
        while (i < *(s32 *)((u8 *)(u32)lbl_8055E354 + 0x1D4D0)) {
            entry = (u8 *)*(void **)((u8 *)(u32)lbl_8055E354 + 0x1D4CC) + offset;
            if (*(u8 *)((u8 *)entry + 0x1D) != 0) {
                num++;
            } else if (*(u8 *)((u8 *)entry + 4) != 0 &&
                (*(u8 *)((u8 *)entry + 0x1C) == 0 ||
                 (f32)fn_8002F234(
                    (z - *(f32 *)((u8 *)entry + 0xC)) * (z - *(f32 *)((u8 *)entry + 0xC))
                  + (x - *(f32 *)((u8 *)entry + 8)) * (x - *(f32 *)((u8 *)entry + 8))
                 ) < radius + *(f32 *)((u8 *)entry + 0x10))) {
                j = 0;
                while (j < *(s32 *)((u8 *)entry + 0x18)) {
                    record = (u8 *)(void *)*(void **)(u32)lbl_8055E354 +
                        (*(s32 *)((u8 *)entry + 0x14) + j) * 0x18;
                    recordObject = *(void **)record;
                    if (recordObject != 0 &&
                        *(s32 *)((u8 *)recordObject + 0x10) != 0 &&
                        *(u8 *)((u8 *)record + 0x14) == 0) {
                        dx = *(f32 *)((u8 *)record + 4) - x;
                        dy = *(f32 *)((u8 *)record + 8) - *(f32 *)((u8 *)object + 0x64);
                        dz = *(f32 *)((u8 *)record + 0xC) - z;
                        tx = dz * *(f32 *)((u8 *)object + 0x44)
                           + (dx * *(f32 *)((u8 *)object + 0x3C)
                           + dy * *(f32 *)((u8 *)object + 0x40));
                        tz = dz * *(f32 *)((u8 *)object + 0x5C)
                           + (dx * *(f32 *)((u8 *)object + 0x54)
                           + dy * *(f32 *)((u8 *)object + 0x58));
                        ty = dz * *(f32 *)((u8 *)object + 0x50)
                           + (dx * *(f32 *)((u8 *)object + 0x48)
                           + dy * *(f32 *)((u8 *)object + 0x4C));
                        radius = *(f32 *)((u8 *)recordObject + 0x14);
                        if (tx + radius > minX && tx - radius < maxX &&
                            tz + radius > minZ && tz - radius < maxZ) {
                            *(u8 *)((u8 *)record + 0x14) = 1;
                            index = *(s32 *)recordObject;
                            counts[index]++;
                        }
                    }
                    j++;
                }
            }
            offset += 0x20;
            i++;
        }
    }
    *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 4) = *(f32 *)((u8 *)object + 0x60);
    *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 8) = *(f32 *)((u8 *)object + 0x64);
    *(f32 *)((u8 *)lbl_80430260 + tableIndex * 4 + 0xC) = *(f32 *)((u8 *)object + 0x68);
    lbl_80430260[tableIndex] = lbl_8055E3C4;
    ((s32 *)arg0)[0] = counts[0];
    ((s32 *)arg0)[1] = counts[1];
    ((s32 *)arg0)[2] = counts[2];
    ((s32 *)arg0)[3] = counts[3];
    ((s32 *)arg0)[4] = counts[4];
    ((s32 *)arg0)[5] = num;
}
#pragma use_lmw_stmw reset
#pragma processor reset
#pragma pop
extern s32 fn_8002B1D8(s32, s32 *, s32);
extern char lbl_803301B8[];
extern s32 lbl_8055E354;
extern s32 lbl_80430260[];
void fn_801688B4(s32 groupId) {
    /* Switch on every group of the scene object manager (lbl_8055E354) whose
     * id matches groupId: set the active byte (+4) of each matching 0x20-byte
     * GroupEntry, which lets fn_80168104 update its records again.
     * fn_801688FC(1) is the counterpart that switches them off. */
    u8 *base = (u8 *)lbl_8055E354 + 0x20000; /* manager + 0x20000 */
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(base - 0x2B30)) { /* manager group count, +0x1D4D0 */
        struct GroupEntry *entry =
            (struct GroupEntry *)(*(s32 *)(base - 0x2B34) + offset); /* +0x1D4CC */
        if (groupId == entry->id) {
            entry->active = 1;
        }
        offset += 0x20;
        i++;
    }
}

void fn_801688FC(s32 arg0) {
    /* Clear the active flag (byte at +4) on all 0x20-byte records whose id matches arg0. */
    u8 *base = (u8 *)lbl_8055E354 + 0x20000;
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(base - 0x2B30)) {
        s32 *record = (s32 *)(*(s32 *)(base - 0x2B34) + offset);
        if (arg0 == *record) {
            *((u8 *)record + 4) = 0;
        }
        offset += 0x20;
        i++;
    }
}

s32 fn_80168944(s32 unused, s32 name) {
    /* Returns nonzero if the given name starts with the "coin_strip" prefix. */
    s32 prefix = (s32)lbl_803301B8;
    s32 len = strlen((char *)prefix);
    s32 cmp = fn_8002B1D8(name, (s32 *)prefix, len);
    return (u32)__cntlzw(cmp) >> 5;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Name patterns for path objects: name prefix, sscanf format for lane count/id, object type (6 ends the table). */
struct DummyPattern {
    const char *prefix;
    const char *fmt;
    s32 type;
};
struct DummyPatternTable {
    DummyPattern p[6];
};
/* Per-lane object types used for the 5 lanes of a road path. */
struct DummyLaneTypes {
    s32 t[5];
};
extern DummyPatternTable lbl_802F94B8;
extern DummyLaneTypes lbl_802F9500;
extern "C" f32 lbl_80561928;
extern "C" s32 fn_8016899C(void *arg0, DummyArg1 *arg1, DummyManager *arg2, f32 *arg3) {
    class DummyCheck {
    public:
        virtual void v0();
        virtual s32 check(const char *name);
    };
    register char *strBase = lbl_80330000;
    const char *prefix;
    s32 plen;
    DummyPatternTable pats;
    DummyLaneTypes laneTypes;
    DummyVec2 dir;
    DummyVec2 normal;
    DummyVec2 base;
    DummyVec2 p;
    DummyVec2 d0;
    union { unsigned long long u; f32 f[2]; } center;
    DummyVec2 d;
    DummyVec2 d1;
    DummyVec2 dc;
    register s32 *values;
    register s32 isRoad;
    s32 laneCount;
    s32 laneId;
    register s32 type;
    register DummyPattern *pat;
    DummyVec2 *pts;
    register f32 total;
    s32 i;
    s32 n;
    s32 segCount;
    register f32 step;
    register s32 id;
    register DummyEntry *entry;
    register f32 zero;
    register f32 half;
    register f32 one;
    register f32 pos;
    s32 seg;
    s32 last;
    register f32 t;
    f32 len;
    s32 j;
    s32 sel;

    if (((DummyCheck *)arg0)->check(arg1->getName()) == 0) {
        fn_802E30C8(strBase + 0x298, arg1->getName());
        return 0;
    }
    values = fn_801399FC(arg1);
    if (*values < 2) {
        fn_802E30C8(strBase + 0x2D0, arg1->getName());
        fn_80128658(values);
        return 0;
    }
    isRoad = stricmp(arg1->getName(), strBase + 0x314) == 0;
    laneCount = 1;
    laneId = -1;
    type = 6;
    if (isRoad) {
        laneCount = 5;
    } else {
        pats = lbl_802F94B8;
        pat = pats.p;
        while (pat->type != 6) {
            prefix = pat->prefix;
            plen = strlen(prefix);
            if (fn_8002B1D8((s32)arg1->getName(), (s32 *)prefix, plen) == 0)
                break;
            pat++;
        }
        if (pat == 0) {
            fn_802E30C8(strBase + 0x328, arg1->getName());
            type = 1;
        } else {
            sscanf(arg1->getName(), pat->fmt, &laneCount, &laneId);
            type = pat->type;
        }
    }

    total = lbl_80561924;
    pts = (DummyVec2 *)(values + 2);
    n = *values;
    for (i = 1; i < n; i++) {
        d0.y = pts[1].y - pts[0].y;
        d0.x = pts[1].x - pts[0].x;
        total += (f32)fn_8002F234(d0.x * d0.x + d0.y * d0.y);
        pts++;
    }
    segCount = 1;
    {
        s32 tmp = (s32)(total / arg3[1]);
        if (tmp > 1)
            segCount = tmp;
    }
    id = laneId;
    step = total / (f32)segCount;

    entry = &arg2->entries[arg2->entryCount++];
    if (values != 0) {
        s32 k;
        f32 *cur;
        f32 z1;
        entry->byte1C = 1;
        center.u = fn_80139C5C(values);
        z1 = lbl_80561924;
        entry->f8 = center.f[0];
        entry->fC = center.f[1];
        entry->f10 = z1;
        cur = (f32 *)values;
        for (k = 0; k < *values; k++) {
            f32 d2;
            dc.y = entry->fC - cur[3];
            dc.x = entry->f8 - cur[2];
            d2 = dc.x * dc.x + dc.y * dc.y;
            entry->f10 = entry->f10 > d2 ? entry->f10 : d2;
            cur += 2;
        }
        entry->f10 = lbl_80561950 * (f32)fn_8002F234(entry->f10);
    } else {
        f32 z0;
        entry->byte1C = 0;
        z0 = lbl_80561924;
        entry->f8 = z0;
        entry->fC = z0;
        entry->f10 = z0;
    }
    entry->recordStart = arg2->recordCount;
    entry->recordCount = 0;
    pos = lbl_80561924;
    zero = pos;
    half = lbl_80561938;
    one = lbl_80561928;
    entry->byte1D = 0;
    entry->id = id;
    entry->active = 1;
    arg2->flag1E158 = 1;

    laneTypes = lbl_802F9500;
    seg = 1;
    pts = (DummyVec2 *)(values + 2);
    for (i = 0; i <= segCount; i++) {
        last = *values - 1;
        while (seg < last && (d.y = pts[1].y - pts[0].y, d.x = pts[1].x - pts[0].x,
                              len = (f32)fn_8002F234(d.x * d.x + d.y * d.y), len < pos)) {
            pos -= len;
            pts++;
            seg++;
        }
        d1.y = pts[1].y - pts[0].y;
        d1.x = pts[1].x - pts[0].x;
        t = pos / (f32)fn_8002F234(d1.x * d1.x + d1.y * d1.y);
        if (one < t)
            t = one;
        dir.x = pts[1].x - pts[0].x;
        dir.y = pts[1].y - pts[0].y;
        *(f64 *)&normal = *(f64 *)&dir;
        {
            f64 tmp = normal.x;
            f32 inv;
            normal.x = normal.y;
            normal.y = -tmp;
            inv = one / (f32)fn_8002F234(normal.x * normal.x + normal.y * normal.y);
            normal.x *= inv;
            normal.y *= inv;
        }
        base.x = pts[0].x + dir.x * t;
        base.y = pts[0].y + dir.y * t;
        for (j = 0; j < laneCount; j++) {
            DummyRecord *rec;
            f32 off = arg3[2] * (half + ((f32)j - half * (f32)laneCount));
            p.x = base.x + normal.x * off;
            p.y = base.y + normal.y * off;
            if (isRoad)
                sel = laneTypes.t[j];
            else
                sel = type;
            rec = &arg2->records[arg2->recordCount++];
            rec->obj = 0;
            rec->obj = (DummyRecordObj *)fn_80167874(sel);
            rec->x = p.x;
            rec->y = zero;
            rec->z = p.y;
            rec->hit = zero;
            fn_801E9E30(0, &rec->x);
            {
                f32 tmp = rec->y + rec->obj->f18;
                rec->y = tmp + rec->hit;
            }
            rec->flag = 0;
            fn_801EA1E0(&rec->y, 1, rec->x, rec->z);
            (*(s32 *)((u8 *)fn_80167874(sel) + 0x1C))++;
            if (arg2->flag1E158 != 0) {
                entry = &arg2->entries[arg2->entryCount - 1];
                entry->recordCount += 1;
            } else {
                if (arg2->entryCount == 0 || (entry = &arg2->entries[arg2->entryCount - 1], entry->byte1C != 0)) {
                    entry = &arg2->entries[arg2->entryCount++];
                    entry->byte1C = 0;
                    entry->recordStart = arg2->recordCount - 1;
                    entry->recordCount = 0;
                    entry->byte1D = 0;
                }
                entry = &arg2->entries[arg2->entryCount - 1];
                entry->recordCount += 1;
            }
        }
        pos += step;
    }
    arg2->flag1E158 = 0;
    fn_80128658(values);
    return 1;
}
#pragma cplusplus reset
#pragma pop

extern char lbl_80330364[];
/* Returns nonzero if name starts with "coin_box" (lbl_80330364). */
s32 fn_80169108(s32 unused, s32 name) {
    s32 prefix = (s32)lbl_80330364;
    s32 len = strlen((char *)prefix);
    s32 cmp = fn_8002B1D8(name, (s32 *)prefix, len);
    return (u32)__cntlzw(cmp) >> 5;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_80169160(void *arg0, DummyArg1 *arg1, DummyManager *arg2, f32 *arg3) {
    class DummyCheck {
    public:
        virtual void v0();
        virtual s32 check(const char *name);
    };
    register char *strBase = lbl_80330000;
    s32 *values;
    DummyEntry *entry;
    f32 *cursor;
    f32 diffs[16];
    f32 dist[4];
    s32 off;
    f32 total;
    s32 outerCount;
    s32 (*selector)(s32, s32, s32, s32);
    f32 outerRem;
    f32 outerStart;
    DummyVec2 a;
    DummyVec2 b;
    DummyVec2 p;
    s32 i;
    s32 j;
    if (((DummyCheck *)arg0)->check(arg1->getName()) == 0) {
        fn_802E30C8(strBase + 0x370, arg1->getName());
        return 0;
    }
    values = fn_801399FC(arg1);
    if (*values < 4 || *values > 4) {
        fn_802E30C8(strBase + 0x3A4, arg1->getName(), *values);
        fn_80128658(values);
        return 0;
    }
    cursor = (f32 *)values;
    diffs[1] = cursor[3] - cursor[5];
    diffs[0] = cursor[2] - cursor[4];
    dist[0] = (f32)fn_8002F234(diffs[0] * diffs[0] + diffs[1] * diffs[1]);
    diffs[3] = cursor[7] - cursor[5];
    diffs[2] = cursor[6] - cursor[4];
    dist[1] = (f32)fn_8002F234(diffs[2] * diffs[2] + diffs[3] * diffs[3]);
    diffs[5] = cursor[7] - cursor[9];
    diffs[4] = cursor[6] - cursor[8];
    dist[2] = (f32)fn_8002F234(diffs[4] * diffs[4] + diffs[5] * diffs[5]);
    diffs[7] = cursor[3] - cursor[9];
    diffs[6] = cursor[2] - cursor[8];
    dist[3] = (f32)fn_8002F234(diffs[6] * diffs[6] + diffs[7] * diffs[7]);
    off = (dist[0] + dist[2] <= dist[1] + dist[3]);
    total = 0.5f * (dist[off] + dist[(off + 2) % 4]);
    outerCount = 1;
    {
        s32 tmp = (s32)(total / *arg3);
        if (tmp > 1)
            outerCount = tmp;
    }
    outerRem = total - (f32)outerCount * *arg3;
    selector = fn_80169928;
    if (stricmp(arg1->getName(), strBase + 0x3E0) == 0)
        selector = fn_801698B8;
    entry = &arg2->entries[arg2->entryCount++];
    entry->byte1C = 1;
    if (values != 0) {
        union { unsigned long long u; f32 f[2]; } center;
        center.u = fn_80139C5C(values);
        entry->f8 = center.f[0];
        entry->fC = center.f[1];
        entry->f10 = 0.0f;
        {
            u8 *cur = (u8 *)values;
            s32 k = 0;
            do {
                f32 dx = entry->f8 - *(f32 *)(cur + 8);
                f32 dy = entry->fC - *(f32 *)(cur + 12);
                f32 d2 = dx * dx + dy * dy;
                if (entry->f10 < d2)
                    entry->f10 = d2;
                cur += 8;
                k++;
            } while (k < *values);
        }
        entry->f10 = 1.1f * (f32)fn_8002F234(entry->f10);
    } else {
        entry->byte1C = 0;
        entry->f8 = 0.0f;
        entry->fC = 0.0f;
        entry->f10 = 0.0f;
    }
    entry->recordStart = arg2->recordCount;
    entry->recordCount = 0;
    entry->byte1D = 0;
    entry->id = -1;
    entry->active = 1;
    arg2->flag1E158 = 1;
    outerStart = 0.5f * outerRem;
    {
        f32 *pA0 = (f32 *)((u8 *)values + off * 8);
        f32 *pA1 = (f32 *)((u8 *)values + ((off + 1) % 4) * 8);
        f32 *pB0 = (f32 *)((u8 *)values + ((off + 3) % 4) * 8);
        f32 *pB1 = (f32 *)((u8 *)values + ((off + 2) % 4) * 8);
        for (i = 0; i <= outerCount; i++) {
            f32 u = (outerStart + (f32)i * *arg3) / total;
            a.x = pA0[2] + u * (pA1[2] - pA0[2]);
            a.y = pA0[3] + u * (pA1[3] - pA0[3]);
            b.x = pB0[2] + u * (pB1[2] - pB0[2]);
            b.y = pB0[3] + u * (pB1[3] - pB0[3]);
            f32 segLen = (f32)fn_8002F234((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
            s32 innerCount = 1;
            {
                s32 tmp = (s32)(segLen / *arg3);
                if (tmp > 1)
                    innerCount = tmp;
            }
            f32 innerStart = 0.5f * (segLen - (f32)innerCount * *arg3);
            for (j = 0; j <= innerCount; j++) {
                f32 v = (innerStart + (f32)j * *arg3) / segLen;
                p.x = a.x + v * (b.x - a.x);
                p.y = a.y + v * (b.y - a.y);
                s32 selVal = selector(j, i, innerCount, outerCount);
                DummyRecord *rec = &arg2->records[arg2->recordCount++];
                rec->obj = 0;
                rec->obj = (DummyRecordObj *)fn_80167874(selVal);
                rec->x = p.x;
                rec->y = 0.0f;
                rec->z = p.y;
                rec->hit = 0.0f;
                fn_801E9E30(0, &rec->x);
                rec->y = rec->y + rec->obj->f18 + rec->hit;
                rec->flag = 0;
                fn_801EA1E0(&rec->y, 1, rec->x, rec->z);
                (*(s32 *)((u8 *)fn_80167874(selVal) + 0x1C))++;
                if (arg2->flag1E158 != 0) {
                    arg2->entries[arg2->entryCount - 1].recordCount++;
                } else {
                    if (arg2->entryCount == 0 || arg2->entries[arg2->entryCount - 1].byte1C != 0) {
                        DummyEntry *newEntry = &arg2->entries[arg2->entryCount++];
                        newEntry->byte1C = 0;
                        newEntry->recordStart = arg2->recordCount - 1;
                        newEntry->recordCount = 0;
                        newEntry->byte1D = 0;
                    }
                    arg2->entries[arg2->entryCount - 1].recordCount++;
                }
            }
        }
    }
    arg2->flag1E158 = 0;
    fn_80128658(values);
    return 1;
}
#pragma cplusplus reset
#pragma pop

/* Returns a placement tier for a grid cell based on its distance from the grid edges:
 * 3 near the edge or corner, 2 for a middle ring, 1 for the interior. */
s32 fn_801698B8(s32 xIndex, s32 yIndex, s32 xCount, s32 yCount) {
    s32 xDist, yDist, minDist;
    s32 edgeScore;
    s32 tier;
    xDist = xIndex;
    yDist = yIndex;
    if (xDist > xCount - xDist)
        xDist = xCount - xDist;
    if (yDist > yCount - yDist)
        yDist = yCount - yDist;
    minDist = xDist;
    if (yDist < xDist)
        minDist = yDist;
    if (yDist > xDist)
        xDist = yDist;
    edgeScore = xDist + minDist / 2;
    if (edgeScore < 3) return 3;
    tier = 1;
    if (edgeScore < 5) tier = 2;
    return tier;
}

/* Returns a tier (1-3) based on the nearest distance of (x, y) to the edges
 * of an xSize by ySize area: 3 if within 2, 2 if exactly 2, otherwise 1. */
s32 fn_80169928(s32 x, s32 y, s32 xSize, s32 ySize) {
    s32 tier;

    if (y > ySize - y)
        y = ySize - y;
    if (x > xSize - x)
        x = xSize - x;
    if (y < x)
        x = y;
    if (x > 2)
        return 3;
    tier = 1;
    if (x > 1)
        tier = 2;
    return tier;
}

extern s32 lbl_8055A198;
extern s32 lbl_8055A1A0;
/* Returns 1 if the given name matches "star" or "coin", 0 otherwise. */
s32 fn_80169978(s32 unused, s32 name) {
    s32 matches = 0;
    if (fn_8002B1D8(name, &lbl_8055A198, 4) == 0 || fn_8002B1D8(name, &lbl_8055A1A0, 4) == 0) {
        matches = 1;
    }
    return matches;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 *fn_801399FC(DummyArg1 *);
extern "C" s32 fn_80128658(s32 *);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" char lbl_8055A1A8, lbl_8055A1B0;
extern "C" char lbl_803303EC[], lbl_80330420[];
/* Read a SinglesPickupMaker table ("coin%d"/"star%d") and add its pickups to
   the manager: one group entry for the table plus one record per placement. */
extern "C" s32 fn_801699E4(void *checker, DummyArg1 *table, DummyManager *manager) {
    class NameChecker {
    public:
        virtual void v0();
        virtual s32 matchesName(const char *name);
    };

    f32 *placement;
    s32 pickupType;
    s32 *placements;
    s32 placementIndex;
    s32 tableIndex;
    s32 groupId;
    f32 zero;
    DummyEntry *group;

    if (((NameChecker *)checker)->matchesName(table->getName()) == 0) {
        fn_802E30C8(lbl_803303EC, table->getName());
        return 0;
    }

    if (fn_8002B1D8((s32)&lbl_8055A198, (s32 *)table->getName(), 4) == 0) {
        pickupType = 4;
    } else if (fn_8002B1D8((s32)&lbl_8055A1A0, (s32 *)table->getName(), 4) == 0) {
        pickupType = 1;
    } else {
        fn_802E30C8(lbl_80330420, table->getName());
        return 0;
    }

    tableIndex = -1;
    if (pickupType == 1) {
        sscanf(table->getName(), (const char *)&lbl_8055A1A8, &tableIndex);
    } else if (pickupType == 4) {
        sscanf(table->getName(), (const char *)&lbl_8055A1B0, &tableIndex);
    }

    placements = fn_801399FC(table);
    groupId = tableIndex;
    group = &manager->entries[manager->entryCount++];
    zero = 0.0f;
    group->byte1C = 0;
    group->f8 = zero;
    group->fC = zero;
    group->f10 = zero;
    group->recordStart = manager->recordCount;
    group->recordCount = 0;
    group->byte1D = 0;
    group->id = groupId;
    group->active = 1;
    manager->flag1E158 = 1;

    placement = (f32 *)placements;
    placementIndex = 0;
    for (; placementIndex < *placements; placementIndex++) {
        register DummyRecord *pickup = &manager->records[manager->recordCount++];
        pickup->obj = 0;
        pickup->obj = (DummyRecordObj *)fn_80167874(pickupType);
        pickup->x = placement[2];
        pickup->y = zero;
        pickup->z = placement[3];
        pickup->hit = zero;
        fn_801E9E30(0, &pickup->x);
        {
            f32 liftedY = pickup->y + pickup->obj->f18;
            pickup->y = liftedY + pickup->hit;
        }
        pickup->flag = 0;
        fn_801EA1E0(&pickup->y, 1, pickup->x, pickup->z);
        (*(s32 *)((u8 *)fn_80167874(pickupType) + 0x1C))++;

        if (manager->flag1E158 != 0) {
            group = &manager->entries[manager->entryCount - 1];
            group->recordCount += 1;
        } else {
            s32 count = manager->entryCount;
            if (count == 0) {
                goto mkEntry;
            } else {
                s32 lastIndex = count - 1;
                volatile u8 *lastFlag = (u8 *)manager->entries + lastIndex * 0x20 + 0x1C;
                if (*lastFlag == 0) {
                    goto incEntry;
                }
            }
mkEntry:;
            {
                DummyEntry *newGroup = &manager->entries[manager->entryCount++];
                newGroup->byte1C = 0;
                newGroup->recordStart = manager->recordCount - 1;
                newGroup->recordCount = 0;
                newGroup->byte1D = 0;
            }
incEntry:;
            {
                s32 lastGroupIndex = manager->entryCount - 1;
                u8 *groupsBase = (u8 *)manager->entries;
                u8 *lastGroup = groupsBase + lastGroupIndex * 0x20;
                (*(s32 *)(lastGroup + 0x18))++;
            }
            group = &manager->entries[manager->entryCount - 1];
        }
        placement += 2;
    }

    manager->flag1E158 = 0;
    fn_80128658(placements);
    return 1;
}
#pragma cplusplus reset
#pragma pop

extern char lbl_8055A1B8;
s32 fn_80169D64(s32 unused, s32 name) {
    /* Returns nonzero if the given object name starts with the "poop" prefix,
     * the names of the "poop_%d" objects fn_80169DB8 places. */
    s32 prefix = (s32)&lbl_8055A1B8; /* "poop" */
    s32 len = strlen((char *)prefix);
    s32 cmp = fn_8002B1D8(name, (s32 *)prefix, len); /* strncmp */
    return (u32)__cntlzw(cmp) >> 5;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Place one "poop_<id>" object group: the table's own name carries the group id,
 * and every item it holds is a scene object with a "loc" position and a "hit"
 * radius.  Each item becomes a coin-type (1) pickup record standing on the
 * ground at its position, lifted by the pickup type's height offset and by its
 * own hit radius; the whole group shares one entry in the manager's group list.
 * fn_80169D64() is the name check that picks this handler for a table. */
extern "C" s32 fn_80169DB8(void *unused, DummyArg1 *table, DummyManager *manager) {
    s32 parsedId = -1;
    DummyItem *item = 0;
    s32 groupId = 0;
    s32 i;
    f32 zero;

    /* "poop_<id>" - the number in the table's name is the group's id */
    sscanf(table->getName(), lbl_8055A1C0, &parsedId);
    groupId = parsedId;
    {
        /* One group entry up front; flag1E158 keeps every item below in it */
        DummyEntry *entry = &manager->entries[manager->entryCount++];
        entry->byte1C = 0;
        zero = 0.0f;
        entry->f8 = zero;
        entry->fC = zero;
        entry->f10 = zero;
        entry->recordStart = manager->recordCount;
        entry->recordCount = 0;
        entry->byte1D = 0;
        entry->id = groupId;
        entry->active = 1;
        manager->flag1E158 = 1;
    }

    for (i = 0; (item = table->getItem(i)) != 0; i++) {
        f32 hit = item->getHit(lbl_8055A1C8);   /* "hit" */
        DummyVec2 loc = item->getLoc(lbl_8055A1CC); /* "loc" */
        DummyRecord *pickup = &manager->records[manager->recordCount++];
        f32 sum;
        pickup->obj = 0;
        pickup->obj = (DummyRecordObj *)fn_80167874(1); /* the coin pickup type */
        pickup->x = loc.x;
        pickup->y = zero;
        pickup->z = loc.y;
        pickup->hit = hit;
        fn_801E9E30(0, &pickup->x);  /* drop y onto the ground under (x, z) */
        sum = pickup->y + pickup->obj->f18; /* the type's standing height */
        pickup->y = sum + pickup->hit;      /* plus this item's own lift */
        pickup->flag = 0;
        fn_801EA1E0(&pickup->y, 1, pickup->x, pickup->z);
        /* count the placed pickup on the type info */
        *(s32 *)((u8 *)fn_80167874(1) + 0x1C) += 1;

        if (manager->flag1E158 != 0) {
            /* still the group opened above: one more record in it */
            s32 lastGroupIndex = manager->entryCount - 1;
            u8 *groupsBase = (u8 *)manager->entries;
            u8 *lastGroup = groupsBase + lastGroupIndex * 0x20;
            (*(s32 *)(lastGroup + 0x18))++;
        } else {
            s32 count = manager->entryCount;
            if (count == 0) {
                goto mkEntry;
            } else {
                s32 lastIndex = count - 1;
                volatile u8 *lastFlag = (u8 *)manager->entries + lastIndex * 0x20 + 0x1C;
                if (*lastFlag == 0) {
                    goto incEntry;
                }
            }
        mkEntry:;
            {
                /* the last group is closed, so open one for this record */
                DummyEntry *newGroup = &manager->entries[manager->entryCount++];
                newGroup->byte1C = 0;
                newGroup->recordStart = manager->recordCount - 1;
                newGroup->recordCount = 0;
                newGroup->byte1D = 0;
            }
        incEntry:;
            {
                s32 lastAddedIndex = manager->entryCount - 1;
                u8 *addedBase = (u8 *)manager->entries;
                u8 *addedGroup = addedBase + lastAddedIndex * 0x20;
                (*(s32 *)(addedGroup + 0x18))++;
            }
        }
    }

    manager->flag1E158 = 0;
    return 1;
}
#pragma pop

