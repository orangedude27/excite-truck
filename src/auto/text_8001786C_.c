typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

/* A driver/vehicle pairing list, 0x48 bytes: up to 8 driver numbers at +0x4 and
 * the number of the vehicle each of them drives at +0x28, each half carrying a
 * count of its own. */
typedef struct EntryPairList {
    s32 driverCount;
    s32 driverNums[8];
    s32 vehicleCount;
    s32 vehicleNums[8];
} EntryPairList;

/* One driver record (stride 0x5C): the fixed base table lbl_803577F0 followed
 * by the ones read from the DAV data (lbl_8055D540).  Only the fields this file
 * touches are named; see src/auto/text_80016354_.c for the rest. */
typedef struct DriverInfo {
    /* 0x00 */ s32 unk_0x00;
    /* 0x04 */ s32 number;         /* unique driver number */
    /* 0x08 */ char name[0x40];
    /* 0x48 */ s32 unk_0x48;
    /* 0x4C */ s32 vehicleIndex;   /* index of the VehicleInfo this driver drives */
    /* 0x50 */ s32 vehicleOverride;
    /* 0x54 */ s32 unk_0x54[2];
} DriverInfo;

/* One vehicle record (stride 0xA8): the fixed base table lbl_80357960 followed
 * by the ones read from the DAV data (lbl_8055D544). */
typedef struct VehicleInfo {
    /* 0x00 */ s32 unk_0x00;
    /* 0x04 */ s32 number;         /* unique vehicle number */
    /* 0x08 */ s32 linkedNumber;   /* number of the vehicle this one is tied to */
    /* 0x0C */ s32 unk_0x0C[8];
    /* 0x2C */ char name[0x24];
    /* 0x50 */ s32 unk_0x50[5];
    /* 0x64 */ s32 altVehicles[12]; /* alternate vehicle numbers it can be given */
    /* 0x94 */ s32 altIndex;       /* which alternate is in use, -1 for none */
    /* 0x98 */ s32 altCount;
    /* 0x9C */ s32 carClass;       /* car class of the name at +0x2C */
    /* 0xA0 */ s32 flags;
    /* 0xA4 */ s32 classMask;
} VehicleInfo;

#define VEHICLE_CLASS_UNCLASSIFIED 6 /* fn_8013C8E8's answer for an unknown name */

/* Driver/vehicle record accessors (src/auto/text_80016354_.c) and the pairing
 * list helpers defined below in this file. */
#define GetBaseEntryCount         fn_800167F4 /* records in the fixed base tables */
#define GetBaseDriver             fn_800167B8 /* DriverInfo *by index in lbl_803577F0 */
#define GetVehicleByIndex         fn_80016510 /* VehicleInfo *by index */
#define GetVehicleByNumber        fn_80016544 /* VehicleInfo *by number */
#define SetDriverVehicleOverride  fn_800168B0 /* driver number, vehicle number */
#define GetCarClass               fn_8013C8E8 /* car class of a vehicle name */
#define debug_printf              fn_802E30C8 /* debug console print */
#define STR_UNCLASSIFIED_CAR      lbl_802FD088 /* "DAVMap: WARNING! Player is driving the %s, an unclassified car!" */
#define AddDriverVehiclePair      fn_800178BC /* append one driver/vehicle number pair */
#define WarnIfUnclassifiedVehicle fn_8001786C /* warn when a vehicle has no car class */
#define VehicleOverrideEnabled    fn_800178F0 /* whether to re-apply the alternate vehicle */
#define SetDriverVehicleFromTable fn_800178F8 /* driver number, vehicle number */

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* fn_80016544(s32);
extern void fn_802E30C8(const char*, ...);
extern s32 fn_8013C8E8(s32);
extern const char lbl_802FD088[];
extern s32 fn_800168B0(s32, s32);
extern s32 fn_800167F4(void);
extern void* fn_800167B8(s32);
extern void* fn_80016510(s32);
extern void fn_8001786C(s32);
extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
#pragma scheduling invalid_target
/* Warn on the debug console when a vehicle's name belongs to no car class. */
void fn_8001786C(s32 vehicleNum) {
    void *vehicleName;
    vehicleName = (void *)((char *)GetVehicleByNumber(vehicleNum) + 0x2C);
    if (GetCarClass((s32)vehicleName) == VEHICLE_CLASS_UNCLASSIFIED) {
        debug_printf(STR_UNCLASSIFIED_CAR, vehicleName);
    }
}

/* Append one driver/vehicle number pair to the EntryPairList: store the driver
   number in the next slot of the driver half (+4), the vehicle number in the next
   slot of the vehicle half (+0x28), and advance each half's count. */
void fn_800178BC(void* list, s32 driverNum, s32 vehicleNum) {
    s32 driverIndex;
    s32 vehicleIndex;
    driverIndex = *(s32*)list;
    *(s32*)((char*)list + (driverIndex << 2) + 4) = driverNum;
    vehicleIndex = *(s32*)((char*)list + 0x24);
    *(s32*)list = driverIndex + 1;
    *(s32*)((char*)list + (vehicleIndex << 2) + 0x28) = vehicleNum;
    *(s32*)((char*)list + 0x24) = vehicleIndex + 1;
}
#pragma scheduling on
/* VehicleOverrideEnabled: whether a driver takes his vehicle from the vehicle record's alternate list instead of the one picked for him; always off in this build. */
s32 fn_800178F0(void) { return 0; }

/* Apply the currently selected alternate vehicle for a vehicle number to the given driver. */
void fn_800178F8(s32 driverNum, s32 vehicleNum) {
    void *vehicleInfo = GetVehicleByNumber(vehicleNum);
    volatile s32 *pAltIndex = (volatile s32 *)((char *)vehicleInfo + 0x94);
    s32 altIndex = *pAltIndex;
    SetDriverVehicleOverride(driverNum, *(s32 *)((char *)vehicleInfo + altIndex * 4 + 0x64));
}

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Fill a driver/vehicle pairing list from the game's fixed roster: every base
 * driver record contributes its number and the number of the vehicle record it
 * is assigned to, each vehicle is checked for having a car class, and the
 * driver's alternate vehicle is re-applied when that override is switched on. */
void fn_80017944(EntryPairList *list) {
    register s32 driverCount;
    register s32 i;
    register s32 driverNum;
    register s32 vehicleNum;
    DriverInfo *driver;
    VehicleInfo *vehicle;

    driverCount = GetBaseEntryCount();
    list->vehicleCount = 0;
    i = 0;
    list->driverCount = 0;
    for (; i < driverCount; i++) {
        driver = (DriverInfo *)GetBaseDriver(i);
        driverNum = driver->number;
        vehicle = (VehicleInfo *)GetVehicleByIndex(driver->vehicleIndex);
        vehicleNum = vehicle->number;
        AddDriverVehiclePair(list, driverNum, vehicleNum);
        WarnIfUnclassifiedVehicle(vehicleNum);
        if (VehicleOverrideEnabled() != 0) {
            SetDriverVehicleFromTable(driverNum, vehicleNum);
        }
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset

#pragma dont_inline on
s32 fn_800179E4(void *key, s32 values, s32 count) {
    s32 i;
    /* Linear membership test: true when key matches one of the count words. */
    for (i = 0; i < count; i++) {
        if ((s32)key == *(s32 *)(values + i * 4)) return 1;
    }
    return 0;
}

s32 fn_80017A14(s32 objectId, s32 exclusions) {
    /* True when objectId appears in the exclusion list (count at +0x24, values from +0x28). */
    return fn_800179E4((void *)objectId, exclusions + 0x28, *(s32 *)(exclusions + 0x24));
}

#pragma dont_inline off

extern s32 fn_800179E4(void *, s32, s32);
/* Membership test: true when `key` is one of the words in the counted array
 * pointed to by `countAndValues` (count at [0], values starting at [1]). */
s32 fn_80017A20(void *key, s32 *countAndValues) {
    return fn_800179E4(key, (s32)(countAndValues + 1), countAndValues[0]);
}

extern void *fn_80016464(s32);
extern s32 fn_80016508(void);
extern void fn_80017AC8(void *);
#pragma scheduling invalid_target
#pragma dont_inline on
/* Build a shuffled list of every driver number that is not in the exclusion set:
 * walk the whole driver table, append each non-excluded driver's number to the
 * counted list (items pointer at +0, count at +4), then shuffle the result. */
void fn_80017A2C(void *outList, s32 excludedDrivers) {
    s32 driverIndex = 0;
    while (driverIndex < fn_80016508()) {
        DriverInfo *driver = (DriverInfo *)fn_80016464(driverIndex);
        s32 driverNumber = driver->number;
        if (fn_80017A20((void *)driverNumber, (s32 *)excludedDrivers) == 0) {
            s32 itemCount = *(s32 *)((char *)outList + 4);
            void *values = *(void **)outList;
            *(s32 *)((char *)outList + 4) = itemCount + 1;
            ((s32 *)values)[itemCount] = driverNumber;
        }
        driverIndex++;
    }
    fn_80017AC8(outList);
}
// Shuffles an int list (items pointer at +0, count at +4): walk each position
// and swap its value with one chosen at random in [0, count) from RNG slot 1.
void fn_80017AC8(void* list) {
    extern s32 fn_80129D18(s32);
    register s32* header = (s32*)list;
    register s32 byteOffset = 0;
    register s32 shuffled = 0;
    register s32 temp;
    register s32* values;
    goto check;
loop:
    {
        s32 swapIndex = ((s32 (*)(s32, s32))fn_80129D18)(1, header[1]);
        values = (s32*)header[0];
        temp = *(s32*)((char*)values + byteOffset);
        shuffled++;
        *(s32*)((char*)values + byteOffset) = values[swapIndex];
        byteOffset += 4;
        values[swapIndex] = temp;
    }
check:
    temp = header[1];
    if (shuffled < temp) goto loop;
}

extern s32 fn_800165D4(void);
extern s32 fn_80017A14(s32, s32);
extern void fn_80017AC8(void*);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80017B40(void *arg0, s32 arg1) {
    /* Collect object IDs whose flags allow selection and whose endpoint IDs are absent from the exclusion set, then shuffle the collected list. */
    register s32 i;
    register s32 objectIdA;
    register s32 objectIdB;
    register s32 skip;
    register unsigned long flags;
    register s32 bit2;
    register s32 bit3;
    register s32 count;
    register void **items;
    void *obj;

    i = 0;
    while (i < fn_800165D4()) {
        obj = fn_80016510(i);
        flags = *(unsigned long *)((char *)obj + 0xA0);
        skip = 0;
        objectIdA = *(s32 *)((char *)obj + 4);
        objectIdB = *(s32 *)((char *)obj + 8);
        bit2 = (flags >> 2) & 1;
        bit3 = (flags >> 3) & 1;
        if ((flags & 2) || bit2 || bit3) skip = 1;
        if (!skip && fn_80017A14(objectIdA, arg1) == 0 && fn_80017A14(objectIdB, arg1) == 0) {
            count = *(s32 *)((char *)arg0 + 4);
            items = *(void ***)arg0;
            *(s32 *)((char *)arg0 + 4) = count + 1;
            items[count] = (void *)objectIdA;
        }
        i++;
    }
    fn_80017AC8(arg0);
}
extern void *fn_80016510(s32);
extern void *fn_80016474(s32);
extern void fn_80017D5C(void *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80017C18(void *arg0, s32 *arg1) {
    register s32 *entry;
    register s32 *items;
    register void *cursor;
    register s32 i;
    register s32 n;
    register void *object;
    register s32 k;
    s32 j;
    s32 offset;
    unsigned long target;

    entry = arg1;
    object = fn_80016510(0);
    cursor = object;
    i = 0;
    while (i < *(s32 *)((char *)object + 0x98)) {
        n = *(s32 *)((char *)arg0 + 4);
        i++;
        items = *(s32 **)arg0;
        *(s32 *)((char *)arg0 + 4) = n + 1;
        items[n] = *(s32 *)((char *)cursor + 0x64);
        cursor = (char *)cursor + 4;
    }

    k = 0;
    while (k < arg1[0]) {
        object = fn_80016474(entry[1]);
        n = *(s32 *)((char *)arg0 + 4);
        j = 0;
        offset = 0;
        target = *(unsigned long *)((char *)object + 0x50);
        while (j < n) {
            if (*(unsigned long *)((char *)*(s32 **)arg0 + offset) != target) {
                offset += 4;
                j++;
            } else {
                goto found;
            }
        }
        j = -1;
found:
        if (j == -1) {
        } else if (j < 0) {
        } else if (j < *(s32 *)((char *)arg0 + 4)) {
            if (j != *(s32 *)((char *)arg0 + 4) - 1) {
                items = *(s32 **)arg0;
                items[j] = items[*(s32 *)((char *)arg0 + 4) - 1];
            }
            *(s32 *)((char *)arg0 + 4) = *(s32 *)((char *)arg0 + 4) - 1;
        }
        entry++;
        k++;
    }
    fn_80017D5C(arg0);
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma scheduling on
extern void fn_80017A2C(void *, s32);
extern void fn_800178BC(void *, s32, s32);
extern void fn_80016928(s32, s32);
#pragma scheduling invalid_target
/* Populate pairList with numPairs driver/vehicle pairs, picking each entry
 * round-robin from shuffled lists of eligible drivers, vehicles and alternate
 * vehicles; exclusions filters the candidates used by those builders. */
void BuildEntryPairs(s32 *pairList, s32 numPairs, s32 *exclusions) {
    struct { s32 *items; s32 count; s32 capacity; s32 buf[50]; } drivers, vehicles, altVehicles;
    s32 pairIndex;
    s32 driverNumber;
    s32 vehicleNumber;
    s32 altVehicleNumber;
    *(s32 *)((char *)pairList + 0x24) = 0;
    *pairList = 0;
    if (numPairs > 0) {
        drivers.items = drivers.buf; drivers.count = 0; drivers.capacity = 50;
        fn_80017A2C(&drivers, (s32)exclusions);
        vehicles.capacity = 50; vehicles.items = vehicles.buf; vehicles.count = 0;
        fn_80017B40(&vehicles, (s32)exclusions);
        altVehicles.capacity = 50; altVehicles.items = altVehicles.buf; altVehicles.count = 0;
        fn_80017C18(&altVehicles, exclusions);
        for (pairIndex = 0; pairIndex < numPairs; pairIndex++) {
            driverNumber = drivers.items[pairIndex % drivers.count];
            vehicleNumber = vehicles.items[pairIndex % vehicles.count];
            altVehicleNumber = altVehicles.items[pairIndex % altVehicles.count];
            AddDriverVehiclePair(pairList, driverNumber, vehicleNumber);
            if (VehicleOverrideEnabled()) SetDriverVehicleFromTable(driverNumber, vehicleNumber);
            else fn_80016928(driverNumber, altVehicleNumber);
        }
        altVehicles.items = 0; altVehicles.count = 0; altVehicles.capacity = 0;
        vehicles.items = 0; vehicles.count = 0; vehicles.capacity = 0;
        drivers.items = 0; drivers.count = 0; drivers.capacity = 0;
    }
}
#pragma scheduling reset
/* Whether the fixed roster holds exactly one driver/vehicle entry. */
s32 fn_80017F40(void) {
    return GetBaseEntryCount() == 1;
}

extern void* fn_80012820(s32);
extern void* fn_80012870(s32, s32);
extern s32 fn_80017F40(void);
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_80017F6C(s32 arg0) {
    /* Return the max value: forced cap, global max, or max entry field across arg0's list. */
    s32 value, best, index;
    void *list;
    if ((s32)lbl_8055D560 != 0) {
        value = fn_800167F4();
        best = (s32)lbl_8055D560;
        if (value > best) best = value;
        return best;
    }
    if (fn_80017F40() == 0) return fn_800167F4();
    best = 0;
    list = fn_80012820(arg0);
    index = 0;
    while (index < *(s32*)((char*)list + 0x70)) {
        value = *(s32*)((char*)fn_80012870(arg0, index) + 0x10);
        if (value > best) best = value;
        index++;
    }
    return best;
}
#pragma dont_inline off
#pragma scheduling on
extern void* fn_8001668C(void*, s32);
extern const char lbl_802FD0C8[];
extern const char lbl_802FD0D8[];
extern const char lbl_80357DC0[];
#pragma cplusplus on
/* Read "force_chassis" from a DAV map interface and fill each entry slot
 * (+0x28) with the matching resource ID for that name. */
extern "C" void fn_80018030(void *arg0, s32 arg1) {
    struct V {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *m4(const char *, const char *);
    };
    struct H {
        char pad[0x80];
        V *iface;
    };
    char *str;
    s32 i;
    H *obj = (H *)fn_80012820(arg1);
    str = obj->iface->m4(lbl_802FD0C8, lbl_80357DC0);
    if (str != 0 && (signed char)*str != 0) {
        fn_802E30C8(lbl_802FD0D8, str);
        for (i = 0; i < *(s32 *)((char *)arg0 + 0x24); i++) {
            *(s32 *)((char *)arg0 + i * 4 + 0x28) = *(s32 *)((char *)fn_8001668C(str, 0) + 4);
        }
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
/* Patch each entry's linked id from a per-entry car name resolved through the DAV map data interface. */ extern "C" void applyCarNameOverrides(void *arg0, s32 arg1) {
    /* Resolve per-entry car name overrides from a DAV map data interface and patch each entry's linked id. */
    struct DavMapInterface {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20();
        virtual void *get(const char *);
    };
    struct DavMapNameInterface {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual char *get(const char *, void *);
    };
    struct DavMapHolder { char pad[0x80]; DavMapInterface *iface; };
    extern char lbl_80558C18;
    extern char lbl_80558C1C;
    extern void fn_801345D8(void *, s32, const char *, ...);
    extern int stricmp(const char *, const char *);
    register const char *strings;
    register s32 *entry;
    register DavMapNameInterface *nameIface;
    register char *carTypeName;
    register char *mappedName;
    register s32 i;
    register s32 found;
    register s32 j;
    strings = lbl_802FD088;
    nameIface = (DavMapNameInterface *)((DavMapHolder *)fn_80012820(arg1))->iface->get(strings + 0x74);
    if (nameIface == 0) return;
    fn_802E30C8(strings + 0x80);
    carTypeName = nameIface->get(strings + 0xB0, 0);
    mappedName = nameIface->get(strings + 0xC0, 0);
    entry = (s32 *)arg0;
    for (i = 0; i < *(s32 *)((char *)arg0 + 0x24); entry++, i++) {
        found = 0;
        for (j = 0; j < fn_800167F4(); j++) {
            if (*(s32 *)((char *)fn_800167B8(j) + 4) == entry[1]) {
                found = 1;
                break;
            }
        }
        if (mappedName != 0 && found != 0) {
            if (stricmp(mappedName, &lbl_80558C18) != 0) {
                entry[10] = *(s32 *)((char *)fn_8001668C(mappedName, 0) + 4);
            }
        } else {
            char carKey[0x20];
            char *resultName;
            fn_801345D8(carKey, 0x20, &lbl_80558C1C, i + 1);
            resultName = nameIface->get(carKey, carTypeName);
            if (stricmp(resultName, &lbl_80558C18) != 0) {
                entry[10] = *(s32 *)((char *)fn_8001668C(resultName, 0) + 4);
            }
        }
    }
}
#pragma scheduling on
#pragma cplusplus reset

#pragma cplusplus reset
/* Append all driver and vehicle number pairs from src into dst, growing each
 * half's count as entries are added. */
void fn_800182A0(void* dst, void* srcList) {
    s32 dstIndex;
    s32 value;
    s32* src;
    s32 i;
    s32 dstIndex2;
    s32 value2;
    s32* src2;
    s32 i2;
    src = (s32*)srcList;
    for (i = 0; i < *(s32*)srcList; i++) {
        dstIndex = *(s32*)dst;
        value = *(s32*)((char*)src + 4);
        src++;
        *(s32*)((char*)dst + dstIndex * 4 + 4) = value;
        *(s32*)dst = dstIndex + 1;
    }
    src2 = (s32*)srcList;
    for (i2 = 0; i2 < *(s32*)((char*)srcList + 0x24); i2++) {
        dstIndex2 = *(s32*)((char*)dst + 0x24);
        value2 = *(s32*)((char*)src2 + 0x28);
        src2++;
        *(s32*)((char*)dst + dstIndex2 * 4 + 0x28) = value2;
        *(s32*)((char*)dst + 0x24) = dstIndex2 + 1;
    }
}

#pragma push
#pragma dont_inline on
void fn_80018318(void* outList, s32 contextId) {
    /* Build a 0x48-byte output list: load car class data, collect the base
       entries, append a clamped extra selection, merge both lists, apply ID
       patches for the given context, then unload the data. */
    EntryPairList baseList;
    EntryPairList selectedList;
    s32 extraCount;
    extern void fn_80013C804(void);
    extern s32 fn_80017F6C(s32);
    extern void BuildEntryPairs(s32*, s32, s32*);
    extern void fn_80018030(void*, s32);
    extern void applyCarNameOverrides(void*, s32);
    extern void fn_8013C8B8(void);
    fn_8013C804();
    fn_80017944(&baseList);
    extraCount = fn_80017F6C(contextId) - baseList.driverCount;
    BuildEntryPairs((s32 *)&selectedList, extraCount & ~(extraCount >> 31), (s32 *)&baseList);
    memset(outList, 0, 0x48);
    fn_800182A0(outList, &selectedList);
    fn_800182A0(outList, &baseList);
    fn_80018030(outList, contextId);
    applyCarNameOverrides(outList, contextId);
    fn_8013C8B8();
}
#pragma push
#pragma dont_inline on
/* Return the number of entries to use: lbl_8055D560 forces a fixed minimum (capped
 * below by the base entry count), otherwise, when only the single base entry
 * exists, the larger of the base entry count and the value at +0x10 of the given
 * entry; with more than one base entry, just the base entry count. */
s32 fn_800183C0(void *entry) {
    s32 value;
    s32 best;

    if (lbl_8055D560 != 0) {
        value = fn_800167F4();
        best = (s32)lbl_8055D560;
        if (value > best) best = value;
        return best;
    }
    if (fn_80017F40() != 0) {
        value = fn_800167F4();
        best = *(s32 *)((char *)entry + 0x10);
        if (value > best) best = value;
    } else {
        best = fn_800167F4();
    }
    return best;
}
#pragma pop
extern void *fn_8001285C(s32);
#pragma use_lmw_stmw off
/* Build a reversed copy of a driver/vehicle pairing list: clear the destination,
 * then copy up to `count` pairs from the end of the source list towards its front
 * (last driver/vehicle first). The entry count comes from the per-slot state via
 * fn_800183C0. */
/* Build a reversed copy of a driver/vehicle pairing list: clear the destination, then copy up to the active entry count of pairs from the source list's end toward its front. */ void buildReversedEntryPairs(EntryPairList *dst, s32 slotIndex, const EntryPairList *src)
{
  s32 count;
  s32 i;
  s32 srcDriverCount;
  s32 listSize;
  count = fn_800183C0(fn_8001285C(slotIndex));
  listSize = 0x48;
  memset(dst, 0, listSize);
  for (i = 0; i < count; i++)
  {
    srcDriverCount = src->driverCount;
    dst->driverNums[i] = src->driverNums[(srcDriverCount - 1) - i];
    dst->driverCount++;
    dst->vehicleNums[i] = src->vehicleNums[(src->vehicleCount - 1) - i];
    dst->vehicleCount++;
  }
}

/* Set the forced entry-count override (lbl_8055D560) to atoi()'s result. */
void fn_80018794(void) {
#define gForcedEntryCount lbl_8055D560
    gForcedEntryCount = (void*)atoi();
#undef gForcedEntryCount
}

void fn_800187B8(const char* source) {
    /* Copy the "force_chassis" default string into the 64-byte DAV default buffer, forcing a NUL if it fills. */
    int remaining = 0x40;
    volatile char* destination = (volatile char*)lbl_80357DC0;
    while ((*destination++ = *source++) != '\0') {
        if (--remaining > 0) {
            continue;
        }
        destination[-1] = '\0';
        return;
    }
}

/* Enable the DAV force option by setting its flag byte (lbl_8055D564) to 1. */
void fn_800187F8(void) {
#define gForceEnabled lbl_8055D564
    gForceEnabled = 1;
#undef gForceEnabled
}

/* Shuffle the indexed word array. Reload its base after the random call. */
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80017D5C(void* list) {
    extern s32 fn_80129D18(s32);
    register s32* fields = (s32*)list;
    register s32 byteOffset = 0;
    register s32 i = 0;
    register s32 scratch;
    register s32* items;
    /* Fisher-Yates shuffle: swap each word of the list with one at a random index. */
    goto check;
loop:
    {
        s32 randIndex = ((s32 (*)(s32, s32))fn_80129D18)(1, fields[1]);
        items = (s32*)fields[0];
        scratch = *(s32*)((char*)items + byteOffset);
        i++;
        *(s32*)((char*)items + byteOffset) = items[randIndex];
        byteOffset += 4;
        items[randIndex] = scratch;
    }
check:
    scratch = fields[1];
    if (i < scratch) goto loop;
}
#pragma pop
