#include "MSL/ctype.h"
extern void fn_8001766C();
extern void *lbl_8055D550;
extern void *lbl_8055D554;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_803577F0[];
#define sBaseDrivers  lbl_803577F0 /* fixed DriverInfo table */
#define DRIVER_SIZE   0x5C
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
extern int stricmp(const char *, const char *);
extern int fn_80016510(int);
extern void *lbl_8055D548;
extern char lbl_802FCEA8[];
extern void *lbl_8055D538;
extern int fn_80131808(void *);
extern int fn_8012850C(int, void *);
extern void fn_80016C1C(void);
extern void fn_8000D884(int, int, void *, int, void *);
extern void fn_800177B8(void);
extern void *fn_80016BC8(void *, int);

extern void *lbl_8055D54C;
extern void fn_80128670(void *);
extern void fn_80131818(void);
#pragma scheduling invalid_target
void fn_80016354(void) {
    int i;
    lbl_8055D538 = (void *)fn_80131808(&lbl_802FCEA8[0xC]);
    lbl_8055D540 = (void *)fn_8012850C(0x11F8, &lbl_802FCEA8[0x18]);
    lbl_8055D544 = (void *)fn_8012850C(0x20D0, &lbl_802FCEA8[0x28]);
    fn_80016C1C();
    lbl_8055D554 = 0;
    i = 0;
    do {
        fn_8001766C(i);
        i++;
    } while (i < 4);
    fn_8000D884(0x44727672, 1, &lbl_8055D548, 0x960, fn_800177B8);
}
#pragma scheduling reset
/* Resets/tears down the global object state used by this subsystem: clears
 * counters/handles, frees the primary buffers (lbl_8055D544, lbl_8055D540),
 * and destroys the two auxiliary objects (lbl_8055D538, lbl_8055D53C) if set. */
void fn_800163F0(void) {
    extern void *lbl_8055D538;
    extern void *lbl_8055D53C;
    lbl_8055D550 = 0;
    fn_80128670(lbl_8055D544);
    lbl_8055D544 = 0;
    lbl_8055D54C = 0;
    fn_80128670(lbl_8055D540);
    lbl_8055D540 = 0;
    if (lbl_8055D538) {
        ((void (*)(void *))fn_80131818)(lbl_8055D538);
        lbl_8055D538 = 0;
    }
    if (lbl_8055D53C) {
        ((void (*)(void *))fn_80131818)(lbl_8055D53C);
        lbl_8055D53C = 0;
    }
}

/* Return the DriverInfo at `index` in the DAV-loaded driver table. */
void *fn_80016464(int index) {
    return lbl_8055D540 + index * DRIVER_SIZE;
}

#pragma scheduling invalid_target
void *fn_80016474(int id) {
    /* Find 0x5C-byte entry by id at +0x04 in primary table, then fallback table; default to primary base. */
    unsigned char *entry;
    int i;
    for (i = 0, entry = lbl_803577F0; i < (int)lbl_8055D554; entry += 0x5C, i++) {
        if (id == *(int *)(entry + 4)) {
            return lbl_803577F0 + i * 0x5C;
        }
    }
    {
        unsigned char *fallbackEntry;
        unsigned char *fallbackBase;
        int k = 0;
        fallbackEntry = fallbackBase = lbl_8055D540;
        for (k = 0; k < (int)lbl_8055D54C; fallbackEntry += 0x5C, k++) {
            if (id == *(int *)(fallbackEntry + 4)) {
                return fallbackBase + k * 0x5C;
            }
        }
        return lbl_803577F0;
    }
}

void* fn_80016508(void) {
    /* Return the number of registered car definitions (sCarDefCount /
     * lbl_8055D54C), i.e. the entry count of the lbl_8055D540 car-def table. */
    return lbl_8055D54C;
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Return the address of 0xA8-byte entry `index`: the first lbl_8055D550 entries live in
   the dynamic table (lbl_8055D544), the rest in the static table (lbl_80357960). */
int fn_80016510(int index) {
    extern void *lbl_8055D550;
    if (index < (int)lbl_8055D550)
        return (int)(lbl_8055D544 + index * 0xA8);
    return (int)(lbl_80357960 + (index - (int)lbl_8055D550) * 0xA8);
}

#pragma scheduling invalid_target
void *fn_80016544(int id) {
    /* Find 0xA8-byte entry by id at +0x04 in primary table, then fallback table; default to fallback base. */
    unsigned char *entry;
    unsigned char *base;
    int i;
    int j;
    for (i = 0, entry = lbl_80357960; i < (int)lbl_8055D554; entry += 0xA8, i++) {
        if (id == *(int *)(entry + 4)) {
            return lbl_80357960 + i * 0xA8;
        }
    }
    {
        unsigned char *fallbackEntry;
        unsigned char *fallbackBase;
        int k = 0;
        fallbackEntry = fallbackBase = lbl_8055D544;
        for (k = 0; k < (int)lbl_8055D550; fallbackEntry += 0xA8, k++) {
            if (id == *(int *)(fallbackEntry + 4)) {
                return fallbackBase + k * 0xA8;
            }
        }
        return fallbackBase;
    }
}
#pragma scheduling on

#pragma scheduling on
#pragma dont_inline reset

extern void *lbl_8055D550;
/* Return the number of dynamically registered 0xA8-byte entries held in
 * lbl_8055D550 (the count of records in the dynamic table lbl_8055D544). */
void* fn_800165D4(void) {
    return lbl_8055D550;
}

/* The 0x5C-byte record whose id matches `id` (fn_80016474) holds, at +0x4C, the
 * index of a 0xA8-byte entry; return that entry's address (fn_80016510 hands
 * out entries: the first lbl_8055D550 of them live in the dynamic table
 * lbl_8055D544, the rest in the static table lbl_80357960). */
void *fn_800165DC(int id) {
    return (void *)fn_80016510(*(int *)((char *)fn_80016474(id) + 0x4C));
}

int fn_80016604(const char *name) {
    /* Count entries in lbl_8055D544 (0xA8-byte stride) whose name at +0x2C matches (case-insensitive). */
    int offset = 0, count = 0, i = 0;
    while (i < (int)lbl_8055D550) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), name) == 0)
            count++;
        offset += 0xA8;
        i++;
    }
    return count;
}

#pragma push
#pragma use_lmw_stmw off
void *fn_8001668C(const char *name, int matchIndex) {
    /* Find the Nth 0xA8-byte entry whose name at +0x2C matches (case-insensitive); returns base on miss. */
    int offset;
    int matchCount;
    int index;
    matchCount = 0;
    index = 0;
    offset = 0;
    while (index < (int)lbl_8055D550) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), name) == 0) {
            if (matchCount == matchIndex)
                return lbl_8055D544 + index * 0xA8;
            matchCount++;
        }
        offset += 0xA8;
        index++;
    }
    return lbl_8055D544;
}
#pragma dont_inline on
/* Look up the 0xA8-byte entry whose +0x2C name matches `name`; if its flags at
 * +0xA0 mark it as an alias (bit 1), follow the target id at +0x8 to the real
 * entry. Return the resolved entry's name field (+0x2C). */
void *fn_80016720(const char *name) {
    void *entry = fn_8001668C(name, 0);
    if (*(int *)((char *)entry + 0xA0) & 2) {
        entry = (void *)fn_80016544(*(int *)((char *)entry + 8));
    }
    return (char *)entry + 0x2C;
}

#pragma scheduling invalid_target
/* Finds the nth table entry (0xA8 bytes each) whose flags at offset 0xA0 contain all bits set in mask, or returns the table base if not found. */
void *fn_8001675C(unsigned int mask, int matchIndex) {
    unsigned char *entry;
    unsigned char *base;
    int found = 0;
    int i = 0;
    entry = base = lbl_8055D544;
    for (i = 0; i < (int)lbl_8055D550; entry += 0xA8, i++) {
        if (mask == (mask & *(unsigned int *)(entry + 0xA0))) {
            if (found == matchIndex)
                return base + i * 0xA8;
            found++;
        }
    }
    return base;
}
#pragma scheduling on
/* Return the DriverInfo at `index` in the fixed base-driver table. */
void *fn_800167B8(int index) { return sBaseDrivers + index * DRIVER_SIZE; }

/* The vehicle driven by the base driver at `index`: that DriverInfo (0x5C stride, fixed
 * table lbl_803577F0) keeps the index of its VehicleInfo at +0x4C, and fn_80016510
 * turns such an index into the record (dynamic table first, then the fixed one). */
void *fn_800167CC(int index) {
#define GetDriverByIndex  fn_800167B8 /* DriverInfo *by index in the fixed table */
#define GetVehicleByIndex fn_80016510 /* VehicleInfo *by index */
    return (void *)GetVehicleByIndex(*(int *)((char *)GetDriverByIndex(index) + 0x4C));
#undef GetVehicleByIndex
#undef GetDriverByIndex
}

extern void *lbl_8055D554;
extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
/* Return the number of registered 0x5C-byte record entries held in lbl_8055D554
 * (the count used for the record table lbl_803577F0 and its companion tables). */
void* fn_800167F4(void) {
    return lbl_8055D554;
}

/* Set the registered record-entry count (lbl_8055D554) that sizes the record tables. */
void fn_800167FC(void *count) {
    lbl_8055D554 = count;
}

int fn_80016804(int id, int index) {
#define RecordCount lbl_8055D554
#define PrimaryRecords lbl_803577F0
    /* Return 1 if the primary-table record at index has id, else 0. */
    if (index < (int)RecordCount &&
        id == *(int *)(PrimaryRecords + index * 0x5C + 4)) {
        return 1;
    }
    return 0;
#undef RecordCount
#undef PrimaryRecords
}

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
void fn_8001683C(void *arg0, int arg1) {
    /* Copy two fields (0x4C, 0x50) from the entry found for arg0 into slot arg1 of lbl_803577F0 and reset its paired lbl_80357960 state. */
    void *entry = fn_80016474((int)arg0);
    *(void **)(lbl_803577F0 + arg1 * 0x5C + 4) = arg0;
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x4C) = *(int *)((char *)entry + 0x4C);
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x50) = *(int *)((char *)entry + 0x50);
    *(int *)(lbl_80357960 + arg1 * 0xA8 + 4) = -1000;
}
#pragma pop
extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
/* Set the vehicle override for all base driver entries with the given driver number, then the first matching dynamic entry. */
void fn_800168B0(int driverNumber, int vehicleOverride) {
    int i;
    unsigned char *p;
    for (i = 0, p = lbl_803577F0; i < (int)lbl_8055D554; i++, p += 0x5C) {
        if (driverNumber == *(int *)(p + 4))
            *(int *)(p + 0x50) = vehicleOverride;
    }
    {
        unsigned char *entry;
        unsigned char *base;
        int j = 0;
        entry = base = lbl_8055D540;
        for (j = 0; j < (int)lbl_8055D54C; entry += 0x5C, j++) {
            if (driverNumber == *(int *)(entry + 4)) {
                *(int *)(base + j * 0x5C + 0x50) = vehicleOverride;
                return;
            }
        }
    }
}

#pragma push
#pragma scheduling invalid_target
/* Set field 0x50 of the car definition entry matching `carDefId`. */
void fn_80016928(int carDefId, int value) {
#define sCarDefList  lbl_8055D540
#define sCarDefCount lbl_8055D54C

    unsigned char *entry;
    unsigned char *base;
    int i = 0;
    entry = base = sCarDefList;
    for (i = 0; i < (int)sCarDefCount; entry += 0x5C, i++) {
        if (carDefId == *(int *)(entry + 4)) {
            *(int *)(base + i * 0x5C + 0x50) = value;
            return;
        }
    }

#undef sCarDefList
#undef sCarDefCount
}
#pragma push
#pragma scheduling invalid_target
void fn_80016970(int arg0, int arg1, int arg2, int arg3) {
    struct E { char pad[0x4]; int id; char pad2[0x44]; int f4C; int f50; char rest[0x8]; };
    register int idx = arg0;
    struct E *b = (struct E *)lbl_803577F0;
    b[idx].id = arg1;
    b[idx].f4C = *(int *)fn_80016544(arg2);
    b[idx].f50 = arg3;
    *(int *)(lbl_80357960 + arg0 * 0xA8 + 4) = -1000;
}
#pragma pop
/* Copy a string into the name field (+0x08) of entry `entryIndex` in lbl_803577F0, truncating to 0x40 bytes. */
void fn_800169F8(const char *source, int entryIndex) {
    int remaining = 0x40;
    char *dest = (char *)(lbl_803577F0 + entryIndex * 0x5C + 8);
    while ((*dest++ = *source++) != 0) {
        if (--remaining <= 0) {
            dest[-1] = 0;
            return;
        }
    }
}

/* Tail-call wrapper for external callers: branches to fn_8001766C, which
 * (re)initializes the DriverInfo record for the driver index left in r3 --
 * the argument passes straight through the branch. */
void fn_80016A44(void) {
    fn_8001766C();
}

#pragma dont_inline fn_800167B8
void fn_80016A48(void *out, int id) {
    extern unsigned char lbl_80357C20[];
    extern void *fn_8027953C(void *);
    int found;
    int index;

    /* Find a matching active record in the 0x68-byte table lbl_80357C20 by id; copy its fields to out, or fall back to fn_8027953C. */
    found = -1;
    for (index = 0; index < *(int *)&lbl_8055D554 && found == -1; index++) {
        if (id == *(int *)((unsigned char *)fn_80016510(*(int *)((unsigned char *)fn_800167B8(index) + 0x4C)) + 4))
            found = index;
    }
    if (found != -1) {
        unsigned char *base = lbl_80357C20;
        int offset = found * 0x68;
        if (base[offset] != 0) {
            unsigned char *record = base + offset;
            *(unsigned char *)out = record[4];
            *(float *)((unsigned char *)out + 4) = *(float *)(record + 8);
            *(float *)((unsigned char *)out + 8) = *(float *)(record + 0xC);
            *(float *)((unsigned char *)out + 0xC) = *(float *)(record + 0x10);
            *(float *)((unsigned char *)out + 0x10) = *(float *)(record + 0x14);
            *(float *)((unsigned char *)out + 0x14) = *(float *)(record + 0x18);
            *(float *)((unsigned char *)out + 0x18) = *(float *)(record + 0x1C);
            *(float *)((unsigned char *)out + 0x1C) = *(float *)(record + 0x20);
            *(float *)((unsigned char *)out + 0x20) = *(float *)(record + 0x24);
            *(float *)((unsigned char *)out + 0x24) = *(float *)(record + 0x28);
            *(float *)((unsigned char *)out + 0x28) = *(float *)(record + 0x2C);
            *(float *)((unsigned char *)out + 0x2C) = *(float *)(record + 0x30);
            *(float *)((unsigned char *)out + 0x30) = *(float *)(record + 0x34);
            *(float *)((unsigned char *)out + 0x34) = *(float *)(record + 0x38);
            *(float *)((unsigned char *)out + 0x38) = *(float *)(record + 0x3C);
            *(float *)((unsigned char *)out + 0x3C) = *(float *)(record + 0x40);
            *(float *)((unsigned char *)out + 0x40) = *(float *)(record + 0x44);
            *(float *)((unsigned char *)out + 0x44) = *(float *)(record + 0x48);
            *(float *)((unsigned char *)out + 0x48) = *(float *)(record + 0x4C);
            *(float *)((unsigned char *)out + 0x4C) = *(float *)(record + 0x50);
            *(float *)((unsigned char *)out + 0x50) = *(float *)(record + 0x54);
            *(float *)((unsigned char *)out + 0x54) = *(float *)(record + 0x58);
            *(float *)((unsigned char *)out + 0x58) = *(float *)(record + 0x5C);
            *(float *)((unsigned char *)out + 0x5C) = *(float *)(record + 0x60);
            *(float *)((unsigned char *)out + 0x60) = *(float *)(record + 0x64);
            return;
        }
    }
    fn_8027953C(out);
}
/* Address of the 12-byte record the 'Drvr' resource (fn_800177B8) keeps for the
 * vehicle `entry` in slot group `slot` (0..3).  A vehicle that borrows another
 * one's data (+0xA0 flag bit 2) answers with the record of the vehicle whose
 * number is at +8. */
void *fn_80016BC8(void *arg0, int slot) {
    /* A vehicle as the driver tables keep it (0xA8 bytes, built by
     * fn_80016ED4); only the fields this look-up reads are named. */
    struct VehicleInfo {
        int index;        /* +0x00 its place in the vehicle table */
        int number;       /* +0x04 the number the game hands out */
        int borrowNumber; /* +0x08 vehicle borrowed while the flag is set */
        char pad[0x94];
        int flags;        /* +0xA0 */
    };
    /* One of the four per-vehicle records fn_80017708 fills in. */
    struct VehicleSlot {
        int colorIndex;     /* +0x00 colour index into VehicleInfo +0x64 */
        int colorIndex2;    /* +0x04 starts the same; callers keep them apart */
        unsigned char flag; /* +0x08 cleared with the record */
    };
    #define VEHICLE_BORROWS     2       /* flags bit: use borrowNumber's records */
    #define VEHICLES_PER_SLOT   50      /* vehicles in one slot group */
    #define sVehicleSlotTable   lbl_8055D548 /* VehicleSlot[4][50], 'Drvr' resource */
    #define FindVehicleByNumber fn_80016544  /* vehicle entry with a given number */

    struct VehicleInfo *entry;
    struct VehicleSlot *record;

    entry = (struct VehicleInfo *)arg0;
    if (entry->flags & VEHICLE_BORROWS) {
        entry = (struct VehicleInfo *)FindVehicleByNumber(entry->borrowNumber);
    }
    record = (struct VehicleSlot *)((char *)sVehicleSlotTable +
                                    ((entry->index + (slot * VEHICLES_PER_SLOT)) *
                                     sizeof(struct VehicleSlot)));
#undef VEHICLE_BORROWS
#undef VEHICLES_PER_SLOT
#undef sVehicleSlotTable
#undef FindVehicleByNumber
    return record;
}

extern void *lbl_8055D538;
extern void *lbl_8055D53C;
extern char lbl_802FCEEC[];
extern void fn_8013C804(void);
extern void fn_8013C8B8(void);
extern void fn_80017558(void);
extern void fn_80016D14(void **);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma processor 750
/* Rebuilds vehicle-related lookup data: resets counts, loads driver/vehicle tables if present, resolves each entry's vehicle index, then finalizes initialization. */
void fn_80016C1C(void) {
    int entryOffset;
    unsigned char *vehiclePtr;
    int entryIndex;
    unsigned char *entryPtr;
    int foundMatch, vehicleIndex;
    int vehicleCount;

    fn_8013C804();
    lbl_8055D54C = 0;
    lbl_8055D550 = 0;
    if (lbl_8055D538 != 0) fn_80016D14(lbl_8055D538);
    if (lbl_8055D53C != 0) fn_80016D14(lbl_8055D53C);
    if (lbl_8055D550 == 0) fn_802E317C(lbl_802FCEEC);
    for (entryIndex = 0, entryOffset = 0; entryIndex < (int)lbl_8055D54C; entryOffset += 0x5C, entryIndex++) {
        vehicleCount = (int)lbl_8055D550;
        foundMatch = 0;
        entryPtr = lbl_8055D540 + entryOffset;
        vehiclePtr = lbl_8055D544;
        for (vehicleIndex = 0; vehicleIndex < vehicleCount; vehiclePtr += 0xA8, vehicleIndex++) {
            if (*(int *)(vehiclePtr + 4) == *(int *)(entryPtr + 0x4C)) {
                *(int *)(entryPtr + 0x4C) = vehicleIndex;
                foundMatch = 1;
                break;
            }
        }
        if (!foundMatch) *(int *)(entryPtr + 0x4C) = entryIndex % (int)lbl_8055D550;
    }
    fn_80017558();
    fn_8013C8B8();
}
__declspec(section ".sdata") extern char lbl_80558BD4[];
__declspec(section ".sdata") extern char lbl_80558BE0[];
extern void fn_80016ED4(void *);
extern void fn_80017010(void *);
#pragma cplusplus on
extern "C" void fn_80016D14(void **arg0) {
    /* Iterate child nodes and dispatch "driver"/"vehicle" entries to their handlers. */
    struct Node {
        virtual const char *name();
    };
    struct List {
        virtual void m0();
        virtual void *get(int);
    };
    void *child;
    int i;
    i = 0;
    for (; (child = ((List *)arg0)->get(i)) != 0; i++) {
        if (stricmp(((Node *)child)->name(), lbl_80558BD4) == 0) {
            fn_80016ED4(child);
        } else if (stricmp(((Node *)child)->name(), lbl_80558BE0) == 0) {
            fn_80017010(child);
        }
    }
}
#pragma cplusplus reset
extern __Locale lbl_802FE850;
extern char lbl_802FCF04[];
__declspec(section ".sdata") extern char lbl_80558BE8[];
extern int sscanf(const char *, const char *, ...);
#pragma push
#pragma processor gekko
#pragma dont_inline fn_80016DD8
int fn_80016DD8(const char *arg0) {
    unsigned int hex, blue, green, red;
    int c;
    int first = *(const unsigned char *)arg0;
    int result = 0xFF008040;
    if (first == '0') {
        c = arg0[1];
        c = (c < 0 || c >= 256) ? c : lbl_802FE850.cmap->to_lower_table[c];
        if (c == 'x') {
            const char *p = arg0 + 2;
            if (sscanf(p, lbl_80558BE8, &hex) == 1) result = hex;
            goto done;
        }
    }
    if ((signed char)first >= '0' && (signed char)first <= '9' &&
        sscanf(arg0, lbl_802FCF04, &red, &green, &blue) == 3) {
        result = ((red & 255) << 16) | ((green & 255) << 8) | (blue & 255) | 0xFF000000;
    }
done:
    return result;
}

extern char lbl_80558BEC, lbl_80558BF4, lbl_80558BFC;
extern char lbl_802FCF10[];
extern void fn_801345D8(char *, int, const char *, ...);
#pragma cplusplus on
/* Registers a car definition from an interface object into the car definition table (lbl_8055D540) at the current count (lbl_8055D54C). */
extern "C" void fn_80016ED4(void *carDefObj) {
    struct CarDefInterface {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *GetString(const char *key, int defaultValue);
        virtual void m5();
        virtual int GetInt(const char *key, int defaultValue);
    };
    struct CarDefEntry {
        int id;
        int value;
        char name[0x40];
        int rank;
        int unk4C;
        int unk50;
        int unk54;
        void *obj;
    };
    CarDefEntry *entry;
    int value;
    char *name;
    int n;
    char *dst;

    entry = (CarDefEntry *)(lbl_8055D540 + (int)lbl_8055D54C * 0x5C);
    entry->obj = carDefObj;
    entry->id = (int)lbl_8055D54C;
    value = ((CarDefInterface *)carDefObj)->GetInt(&lbl_80558BEC, (int)lbl_8055D54C);
    name = ((CarDefInterface *)carDefObj)->GetString(&lbl_80558BF4, 0);
    if (name != 0) {
        n = 0x40;
        dst = entry->name;
        while (*dst++ = *name++) {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    } else {
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(entry->name, 0x40, lbl_802FCF10, entry->id);
    }
    entry->value = value;
    entry->unk54 = -1;
    entry->rank = ((CarDefInterface *)carDefObj)->GetInt(&lbl_80558BFC, value);
    entry->unk4C = -1;
    entry->unk50 = 0xFF008040;
    lbl_8055D54C = (void *)((int)lbl_8055D54C + 1);
}

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
extern char lbl_802FCEA8[];
__declspec(section ".sdata") extern char lbl_80558C08[];
__declspec(section ".sdata") extern char lbl_80558C10[];
__declspec(section ".sdata") extern char lbl_80558BD0[];
extern char *fn_80029004(char *, int);
extern "C" char *fn_80131234(char *);
extern int fn_80016DD8(const char *);
extern int fn_8013C8E8(char *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" void fn_801345D8(char *, int, const char *, ...);
extern "C" void fn_80017010(void *arg0) {
#pragma dont_inline on
    struct Interface {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual char *m3(const char *, int);
        virtual char *m4(const char *, void *);
        virtual void m5();
        virtual int m6(const char *, int);
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual int m10(const char *, int);
    };
    int v31, v30, v29;
    char *base;
    char *entry;
    char *r26;
    int off, eidx;
    int flag;
    int c;
    int count;
    count = (int)lbl_8055D550;
    base = lbl_802FCEA8;
    entry = (char *)lbl_8055D544 + count * 0xA8;
    *(int *)entry = count;
    *(int *)(entry + 4) = (int)lbl_8055D550 | 0x40000000;
    {
        char *s = ((Interface *)arg0)->m3(lbl_80558C08, count);
        int n = 0x20;
        char *dst = entry + 0x2C;
        while (*dst++ = *s++) {
            if (--n <= 0) { dst[-1] = 0; break; }
        }
    }
    c = (signed char)*(unsigned char *)(entry + 0x2C);
    flag = 0;
    if (c < 0 || c >= 0x100) {
        flag = 1;
    }
    switch (flag) {
    case 0:
        {
            unsigned char *tbl = *(unsigned char **)((char *)lbl_802FE850.cmap + 0xC);
            c = tbl[c];
            *(unsigned char *)(entry + 0x2C) = c;
        }
        break;
    default:
        break;
    }
    v29 = ((Interface *)arg0)->m10(base + 0x74, 0);
    v30 = ((Interface *)arg0)->m10(base + 0x84, 0);
    v31 = ((Interface *)arg0)->m10(lbl_80558C10, 0);
    r26 = (char *)0;
    if (v29 != 0) {
        *(int *)(entry + 8) = 0;
        {
            char sp88[64];
            char *s = entry + 0x2C;
            int n = 0x40;
            char *dst = sp88;
            while (*dst++ = *s++) {
                if (--n <= 0) { dst[-1] = 0; break; }
            }
            {
                char *found = fn_80029004(sp88, 0x5F);
                if (found != (char *)0) {
                    *found = 0;
                    eidx = 0;
                    off = 0;
                    while (eidx < (int)lbl_8055D550) {
                        if (stricmp(sp88, (char *)lbl_8055D544 + off + 0x2C) == 0) {
                            *(int *)(entry + 8) = *(int *)((char *)lbl_8055D544 + eidx * 0xA8 + 4);
                            *(int *)((char *)lbl_8055D544 + eidx * 0xA8 + 8) = *(int *)(entry + 4);
                            r26 = (char *)lbl_8055D544 + eidx * 0xA8 + 0x2C;
                            break;
                        }
                        off += 0xA8;
                        eidx++;
                    }
                    if (*(int *)(entry + 8) == 0) fn_802E317C(base + 0x94, entry + 0x2C);
                } else {
                    fn_802E317C(base + 0xC4, entry + 0x2C);
                }
            }
        }
    } else {
        *(int *)(entry + 8) = *(int *)(entry + 4);
    }
    {
        char *s = ((Interface *)arg0)->m4(base + 0xFC, r26 ? r26 : entry + 0x2C);
        int n = 0x20;
        char *dst = entry + 0xC;
        while (*dst++ = *s++) {
            if (--n <= 0) { dst[-1] = 0; break; }
        }
    }
    {
        char *s = base + 0x10C;
        int n = 0x10;
        char *dst = entry + 0x4C;
        while (*dst++ = *s++) {
            if (--n <= 0) { dst[-1] = 0; break; }
        }
    }
    {
        char sp48[64];
        char *s;
        fn_801345D8(sp48, 0x40, base + 0x118, (int)(entry + 0xC));
        s = fn_80131234(sp48);
        {
            int n = 0x20;
            char *dst = entry + 0xC;
            while (*dst++ = *s++) {
                if (--n <= 0) { dst[-1] = 0; break; }
            }
        }
    }
    *(int *)(entry + 0x98) = 0;
    while (*(int *)(entry + 0x98) < 0xC) {
        char sp28[32];
        char *s;
        fn_801345D8(sp28, 0x20, base + 0x124, *(int *)(entry + 0x98) + 1);
        s = ((Interface *)arg0)->m4(sp28, 0);
        if (s != (char *)0) {
            *(int *)(entry + 0x64 + *(int *)(entry + 0x98) * 4) = fn_80016DD8(s);
        } else {
            if (*(int *)(entry + 0x98) != 0) break;
            *(int *)(entry + 0x64 + *(int *)(entry + 0x98) * 4) = 0xFF008040;
            *(int *)(entry + 0x98) = *(int *)(entry + 0x98) + 1;
            break;
        }
        *(int *)(entry + 0x98) = *(int *)(entry + 0x98) + 1;
    }
    *(int *)(entry + 0x94) = ((Interface *)arg0)->m6(base + 0x134, 0) - 1;
    *(int *)(entry + 0x9C) = fn_8013C8E8(entry + 0x2C);
    *(int *)(entry + 0xA0) = 0;
    if (((Interface *)arg0)->m10(base + 0x14C, 0) != 0) *(int *)(entry + 0xA0) |= 1;
    if (v29 != 0) *(int *)(entry + 0xA0) |= 2;
    if (v30 != 0) *(int *)(entry + 0xA0) |= 4;
    if (v31 != 0) *(int *)(entry + 0xA0) |= 8;
    *(int *)(entry + 0xA4) = 0x0FF807FF;
    eidx = 0;
    while (1) {
        char sp8[32];
        int count2;
        fn_801345D8(sp8, 0x20, base + 0x158, eidx + 1);
        count2 = ((Interface *)arg0)->m6(sp8, 0);
        if (count2 == 0) break;
        if (count2 >= 0) *(int *)(entry + 0xA4) |= (1 << count2);
        else *(int *)(entry + 0xA4) &= ~(1 << -count2);
        eidx++;
    }
    fn_801345D8(entry + 0x5C, 8, lbl_80558BD0, *(int *)(entry + 4) & 0xBFFFFFFF);
    lbl_8055D550 = (void *)((int)lbl_8055D550 + 1);
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus reset
extern char lbl_802FD00C[];
extern char lbl_802FD040[];
/* The two lists fn_80016ED4 and fn_80017010 build up, both allocated under the
 * names in lbl_802FCEA8 and holding at most 50 entries:
 *   DriverInfo  { int id; int number; char name[0x40]; ... }  0x5C bytes
 *   VehicleInfo { int id; int number; ... char name[]; ... }  0xA8 bytes
 * The number at +4 is what the game hands out to a driver / vehicle and has to
 * be unique, which is what fn_80017558 checks. */
#define sDriverList          lbl_8055D540 /* DriverInfo[50], "DriverInfoList" */
#define sDriverCount         lbl_8055D54C /* entries in sDriverList */
#define sVehicleList         lbl_8055D544 /* VehicleInfo[50], "VehicleInfoList" */
#define sVehicleCount        lbl_8055D550 /* entries in sVehicleList */
#define STR_DUP_DRIVER_NUM   lbl_802FD00C /* "driver: Drivers %s and %s have the same number (%d)" */
#define STR_DUP_VEHICLE_NUM  lbl_802FD040 /* "driver: two vehicles (%s and %s) have the same number (%d)" */
#define debug_print          fn_802E317C  /* debug console print */
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
/* Report every pair of drivers, and every pair of vehicles, that were given the
 * same number: both lists are walked as an O(n^2) triangle and each clash is
 * printed to the debug console with the two names and the number. */
void fn_80017558(void) {
    {
        register int nextOffset;
        register int offset;
        register int i;
        register int j;
        register int nextNumber;
        register int number;

        for (i = 0, offset = 0; i < (int)sDriverCount; offset += 0x5C, i++) {
            for (j = i + 1, nextOffset = j * 0x5C; j < (int)sDriverCount; nextOffset += 0x5C, j++) {
                nextNumber = *(int *)(sDriverList + nextOffset + 4);
                number = *(int *)((u32)offset + (u32)sDriverList + 4);
                if (number == nextNumber) {
                    debug_print(STR_DUP_DRIVER_NUM, (void *)((u32)offset + (u32)sDriverList + 8), sDriverList + nextOffset + 8, nextNumber);
                }
            }
        }
    }

    {
        register int j;
        register int i;
        register int nextOffset;
        register int offset;
        register int number;
        register int nextNumber;

        for (i = 0, offset = 0; i < (int)sVehicleCount; offset += 0xA8, i++) {
            for (j = i + 1, nextOffset = j * 0xA8; j < (int)sVehicleCount; nextOffset += 0xA8, j++) {
                number = *(int *)((u32)offset + (u32)sVehicleList + 4);
                nextNumber = *(int *)(sVehicleList + nextOffset + 4);
                if (number == nextNumber) {
                    debug_print(STR_DUP_VEHICLE_NUM, (void *)((u32)offset + (u32)sVehicleList + 0x2C), sVehicleList + nextOffset + 0x2C, number);
                }
            }
        }
    }
}
#pragma pop
extern unsigned char lbl_802FD07C[];
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_8001766C(int arg0) {
    unsigned char *base = lbl_803577F0;
    int idx = arg0;
    int off68 = idx * 0x68;
    int off8 = idx * 8;
    unsigned char *entry = base + idx * 0x5C;
    memset(entry, 0, 0x5C);
    *(int *)(entry + 4) = -1000;
    ((void (*)(char *, int, const char *, ...))fn_801345D8)((char *)(entry + 8), 0x40, (const char *)lbl_802FD07C, idx + 1);
    *(int *)(entry + 0x48) = 1000;
    base[0x410 + off8] = 0;
    base[0x430 + off68] = 0;
}
#pragma scheduling on
void fn_80017708(void *arg0, int arg1, void *arg2) {
    int temp_r0;
    int temp_r0_2;
    int temp_r4;
    int temp_r4_2;
    memset(arg2, 0, 0xC);
    temp_r4 = *(int *)((char *)arg0 + 0x94);
    *(signed char *)((char *)arg2 + 8) = 0;
    if (temp_r4 >= 0) {
        temp_r0 = (temp_r4 + arg1) % *(int *)((char *)arg0 + 0x98);
        *(int *)arg2 = temp_r0;
        *(int *)((char *)arg2 + 4) = temp_r0;
        return;
    }
    temp_r4_2 = *(int *)((char *)arg0 + 0x98);
    temp_r0_2 = (*(int *)((char *)arg0 + 4) + ((arg1 * temp_r4_2) / 4)) % temp_r4_2;
    *(int *)arg2 = temp_r0_2;
    *(int *)((char *)arg2 + 4) = temp_r0_2;
}
#pragma dont_inline on
/* Clear the 0x960-byte output buffer and, for each active vehicle entry (stride 0xA8, count lbl_8055D550) not flagged +0xA0 bit 2, fill 4 slots via fn_80017708/fn_80016BC8. */
void fn_800177B8(void) {
    int entryOffset;
    int entryIndex;
    void *entry;
    int slotIndex;

    memset(lbl_8055D548, 0, 0x960);
    entryIndex = 0;
    entryOffset = 0;
    goto loop_test;
loop_body:
    entry = lbl_8055D544 + entryOffset;
    if ((*(int *)((char *)entry + 0xA0) & 2) == 0) {
        slotIndex = 0;
        do {
            fn_80017708(entry, slotIndex, fn_80016BC8(entry, slotIndex));
            slotIndex++;
        } while (slotIndex < 4);
    }
    entryOffset += 0xA8;
    entryIndex++;
loop_test:
    if (entryIndex < (int)lbl_8055D550) {
        goto loop_body;
    }
}
#pragma dont_inline reset
