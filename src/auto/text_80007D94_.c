// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
// Symbol guide (the project cannot rename game symbols yet): loadRaceEvents
// (loadRaceEventTable), freeRaceEventConfig (fn_80007F04), initRaceEvents (fn_80007F40),
// shutdownRaceEvents (fn_80007F68), getEventName (fn_80007F90), getEventTypeName
// (fn_80007FF0), getEventId (fn_80008050), getRaceEventCount (fn_800080D8),
// findRaceEventIndex (fn_800080E8), getRaceEventName (fn_80008158),
// getRaceEventDisplayString (getEventDisplayName), getRaceEventEnviron (getEventEnvironName),
// clearContestRef (fn_8000822C), initContestRef (fn_8000824C).
#include <types.h>
#include <macros.h>

/* Parsed "excite_beta_race" config: 0xC-byte records, the entry count at +0x1E0
   and the owning config object at +0x1E4. */
typedef struct {
    u8 entries[0x1E0];
    u32 count;
    void *config;
} RaceEventTable;

/* One row of the static event-id table: id, internal name, display name. */
typedef struct {
    u32 eventId;
    const char *name;
    const char *displayName;
} EventNameEntry;

extern RaceEventTable lbl_8034EF38;   /* global race-event table */
extern EventNameEntry lbl_802FB70C[]; /* event-id/name table */
extern const char lbl_802FB77C[];
extern const char lbl_80558998[1];
extern const char lbl_805589A0[1];
extern const char lbl_805589A8[1];
void fn_80279464(void);
void fn_80012778(void);
void releaseValueFile(void*);
void Abend_Panic(const char*, ...);

int stricmp(const char*, const char*);
extern void qsort(void *, u32, u32, int (*)(const void *, const void *));
const char* fn_80008158(s32);
void fn_80012794(void);
void fn_80279488(void);
void fn_802E30C8(const char*, ...);
extern const char lbl_802FB7A4[];
/* qsort comparator for race-event names: compares the two name pointers case-insensitively. */
void compareRaceEventNames(const char** lhs, const char** rhs) {
    stricmp(*lhs, *rhs);
}

extern void *getValueFile(void *);
extern char lbl_802FB6E0[];
DECL_SECTION(".sdata") extern const char lbl_80558978[];
DECL_SECTION(".sdata") extern const char lbl_80558980[];
DECL_SECTION(".sdata") extern const char lbl_80558988[];
DECL_SECTION(".sdata") extern const char lbl_80558990[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void loadRaceEventTable(void) {
    struct Config {
        virtual void unused();
        virtual void *getEntry(u32);
    };
    struct Item {
        virtual const char *getName();
        virtual void unused1();
        virtual void unused2();
        virtual const char *getValue(const char *);
        virtual void *getString(const char *, const char *);
    };
    volatile u32 *global;
    char *base;
    void *initialConfig;
    u32 index;

    /* Load track entries from the "excite_beta_race" config (base+0x68) into
       gRaceEventTable (lbl_8034EF38): for each "track" item store {name,
       display string (base+0x74 key, default ""), environ (default "")} in
       0xC-byte slots (max 0x28, overflows -> abend base+0x84), then qsort by
       name with compareRaceEventNames. global[0x78]=count, global[0x79]=config ptr. */
    base = lbl_802FB6E0;
    initialConfig = getValueFile(base + 0x68);
    global = (volatile u32 *)&lbl_8034EF38;
    global[0x79] = (u32)initialConfig;
    index = 0;
    global[0x78] = 0;

loop:
    {
        void *config;
        Item *entry;
        void *value;
        u32 count;
        u32 entryIndex;

        config = (void *)global[0x79];
        entryIndex = index;
        index++;
        entry = (Item *)((Config *)config)->getEntry(entryIndex);
        if (entry == 0) {
            goto done;
        }
        if (stricmp(entry->getName(), lbl_80558978) != 0) {
            goto loop;
        }

        value = (void *)entry->getValue(lbl_80558980);
        *(void **)((u8 *)global + global[0x78] * 0xC) = value;

        value = entry->getString(base + 0x74, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 4) = value;

        value = entry->getString(lbl_80558990, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 8) = value;

        count = global[0x78] + 1;
        global[0x78] = count;
        if (count < 0x28) {
            goto loop;
        }
        Abend_Panic(base + 0x84);
    }

done:
    qsort(&lbl_8034EF38, *(volatile u32 *)((u8 *)&lbl_8034EF38 + 0x1E0), 0xC, (int (*)(const void *, const void *))compareRaceEventNames);
}
#pragma scheduling on
#pragma cplusplus reset

#pragma dont_inline on
/* Tear down the parsed "excite_beta_race" config: release the config object
 * held at offset 0x1E4 of the global race-event table and clear the pointer. */
void fn_80007F04(void) {
    RaceEventTable *raceTable = &lbl_8034EF38;
    releaseValueFile(raceTable->config);
    raceTable->config = 0;
}
#pragma dont_inline reset

/* Bootstrap the race-event subsystem: parse the config, then reset controllers. */
void fn_80007F40(void) {
    loadRaceEventTable();
    fn_80279464();
    fn_80012778();
}

#pragma dont_inline fn_80007F04
void fn_80007F04(void);
#pragma dont_inline fn_80007F04
void fn_80007F68(void) {
    /* Tear down the race-event subsystem: release the per-controller model
       list, resume the pending alarm thread, then free the parsed config. */
    fn_80012794();
    fn_80279488();
    fn_80007F04();
}
#pragma scheduling invalid_target
const char* fn_80007F90(u32 eventId) {
    /* Look up the name string for an event ID in the event table, or return "?" if not found. */
    EventNameEntry *entry = lbl_802FB70C;
    while (entry->eventId) {
        if (entry->eventId == eventId) return entry->name;
        entry++;
    }
    Abend_Panic(lbl_802FB77C, eventId);
    return lbl_80558998;
}
#pragma scheduling on
const char* fn_80007FF0(u32 eventType) {
    /* Look up the display name for an event type ID in the event type table, or return "unknown" if not found. */
    EventNameEntry *entry;
    u32 id;
    for (entry = lbl_802FB70C; (id = entry->eventId) != 0; ++entry) {
        if (id == eventType) return entry->displayName;
    }
    Abend_Panic(lbl_802FB77C, eventType);
    return lbl_805589A0;
}

#pragma scheduling invalid_target
/* Find the event id for an identifier string, scanning the event-name table. */
u32 fn_80008050(const char* eventName) {
    register u32 eventId;
    register EventNameEntry *entry;
    for (entry = lbl_802FB70C; (eventId = entry->eventId) != 0; ++entry) {
        if (strcmp(entry->name, eventName) == 0) return eventId;
    }
    fn_802E30C8(lbl_802FB7A4, eventName);
    return 0;
}
#pragma scheduling on
/* Returns the number of populated race-event entries in the global event table. */
u32 fn_800080D8(void) {
    return lbl_8034EF38.count;
}

#pragma dont_inline on
/* Returns the index of the named entry in the lbl_8034EF38 table, or -1 if not found. */
s32 fn_800080E8(arg0)
const char* arg0;
{
    s32 i = 0;
    goto compare;
body:
    if (stricmp(arg0, fn_80008158(i)) == 0) {
        return i;
    }
    i++;
compare:
    if (i < (s32)fn_800080D8()) {
        goto body;
    }
    return -1;
}
#pragma dont_inline reset

/* Return the name string of the race-event table entry at index (0xC-byte records,
 * count at offset 0x1E0), or "invalid" if the index is out of range. */
const char* fn_80008158(s32 index) {
    if (index < 0) {
        goto done;
    }
    if (index >= *(s32 *)((u8 *)&lbl_8034EF38 + 0x1E0)) {
        goto done;
    }
    return *(const char **)((u8 *)&lbl_8034EF38 + index * 0xC);

done:
    return lbl_805589A8;
}

/* Returns the display-string field (offset 4) of the race-event table entry selected by the caller's name lookup. */
const char* getEventDisplayName(void) {
    return *(const char**)((u8*)&lbl_8034EF38 + fn_800080E8() * 0xC + 4);
}

/* Returns the "environ" field (offset 8) of the race-event table entry whose name
 * matches; the caller's name argument is forwarded in r3 to the lookup fn_800080E8. */
s32 getEventEnvironName(void) {
    return *(s32 *)((u8 *)&lbl_8034EF38 + fn_800080E8() * 0xC + 8);
}

s32 fn_800081F0(void *arg0) {
    /* Return the lap count of the contest this reference record points at; a set first flag yields 200. */
    typedef struct { s32 contestIndex; u8 pad04[0x0C]; u32 flags; } ContestRef;
    typedef struct { s32 pad00[3]; s32 laps; } ContestLaps;
    s32 laps;
    if (((ContestRef *)arg0)->flags & 1) goto done;
    laps = ((ContestLaps *)fn_8001285C(((ContestRef *)arg0)->contestIndex))->laps;
    return laps;
done:
    return 0xC8;
}

#pragma dont_inline on
/* Reset a 0x14-byte contest reference record to its empty state: index -1 at offset 0, all other fields 0. */
void fn_8000822C(void *record) {
    *(s32 *)((u8 *)record + 0) = -1;
    *(u32 *)((u8 *)record + 4) = 0;
    *(u32 *)((u8 *)record + 0x10) = 0;
    *(u32 *)((u8 *)record + 0xC) = 0;
    *(u32 *)((u8 *)record + 8) = 0;
}
#pragma dont_inline reset

#pragma dont_inline fn_8000822C
/* Initialize a record from a looked-up source: reset the destination, then copy
 * its first field and the field at offset 8 from the looked-up object. */
void fn_8000824C(void *dest, s32 index) {
    void *source;

    fn_8000822C(dest);
    source = (void *)fn_8001285C(index);
    *(u32 *)((u8 *)dest) = *(u32 *)((u8 *)source);
    *(u32 *)((u8 *)dest + 4) = *(u32 *)((u8 *)source + 8);
}
