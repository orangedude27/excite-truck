// mroll.cpp — player-info/roll management ("mroll.cpp: get_player_info ...").
// Recovered TU window 0x8023FE20..0x80243460 (see docs/attribution_analysis.md).
// Static-init thunk fn_80243410 (+ .ctors slot 0x802ED418) remains in
// auto/text_80243410_.c pending a promotion pass.

typedef signed int s32;
typedef unsigned char u8;
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define MROLL_OFF(base, off) ((char *)(base) + (off))
extern int fn_80131234(void *);
extern void *fn_8027DB40(s32);
extern void *memset(void *, int, unsigned int);
extern int fn_801345D8(void *, int, void *, int);
extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
extern double lbl_80563750;
extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
extern s32 fn_8023512C(char *, s32, char *, s32);
extern s32 fn_80232578(char *, char *, s32);
extern char lbl_80498828[];
extern void *MRollStatLabel_init(void *);
extern void fn_802E317C(char *, ...);
typedef struct Fn241820VT { int pad[3]; int (*isActive)(void *); } Fn241820VT;
typedef struct Fn241820Obj { char pad[0xc]; Fn241820VT *vt; } Fn241820Obj;
typedef int (*Fn241820IsActive)(void *);
/* Clear the player-info table (lbl_80498828): set the id word of each of its
 * two 0x10-byte slots to -1, marking both slots empty. */
void fn_8023FE20(void) {
    register int *slots = (int *)lbl_80498828;
    *slots++ = -1;
    slots[3] = -1;
}

s32 fn_8023FE34(void) {
    /* Count the active (id >= 0) player slots in g_MRollPlayerSlots (lbl_80498828). */
    register s32 *cursor = (s32 *)lbl_80498828;
    s32 activeCount = 0;
    if (*cursor++ >= 0) activeCount = 1;
    if (cursor[3] < 0) return activeCount;
    return activeCount + 1;
}

extern char lbl_803422C0[]; /* "mroll.cpp: get_player_info got bad index %d (there are only %d p..." */

/* g_MRollPlayerSlots (lbl_80498828): two 0x10-byte player-info slots; slot[0] < 0 means empty. */
typedef struct MRollPlayerSlot {
    s32 id;      /* +0x00 */
    s32 pad1;    /* +0x04 */
    s32 field2;  /* +0x08 */
    s32 field3;  /* +0x0C */
} MRollPlayerSlot;

#pragma scheduling invalid_target
/* Looks up the nth active player-info slot in g_MRollPlayerSlots and returns
 * its stored fields (and id); aborts on a bad index. */
/* Looks up the nth active player-info slot in g_MRollPlayerSlots and returns its stored fields (and id); aborts on a bad index. */ void fn_8023FE60(s32 playerIndex, s32 *outField2, s32 *outField3, s32 *outId) {
    register s32 *cursor = (s32 *)lbl_80498828; /* g_MRollPlayerSlots */
    register s32 activeCount = 0;
    register s32 slotIndex = 0;
    for (; slotIndex < 2; cursor += 4, slotIndex++) {
        if (cursor[0] < 0) continue;
        if (activeCount == playerIndex) {
            if (outField2 != 0) {
                register s32 *table = (s32 *)lbl_80498828;
                table += slotIndex * 4;
                *outField2 = table[2];
            }
            if (outField3 != 0) {
                register s32 *table = (s32 *)lbl_80498828;
                table += slotIndex * 4;
                *outField3 = table[3];
            }
            if (outId != 0)
                *outId = *(s32 *)((char *)lbl_80498828 + slotIndex * 16);
            return;
        }
        activeCount++;
    }
    fn_802E317C(lbl_803422C0, playerIndex, activeCount); /* bad index abort */
}

#pragma push
#pragma scheduling on
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" {
void fn_8001880C(void);
void fn_8013C804(void);
void fn_802556BC(void *, s32);
void *fn_802410F8(void *, s32, s32 *, s32);
void *MRollContainer_init(void *);
void *fn_80240BA4(void *, s32, void *, void *, void *, void *);
void *fn_80240A1C(void *, int *, void *);
void MRollMenuItem_addEntry(void *, s32);
void fn_802409A4(void *, s32);
void fn_80129AEC(s32);
s32 fn_802146BC(void *, s32, s32, s32);
s32 fn_802E4A10(void);
void fn_8023D4B8(void);
void fn_8013C8B8(void);
void fn_80018B24(void);
void __array_delete(void *, void *, s32, s32);
void *MRollStatLabel_deletingDestructor(void *, s32);
s32 fn_80235380(s32, s32);
void *fn_80255758(void *, s32);
extern char lbl_803425B8[];
extern s32 lbl_80498810[];
extern s32 lbl_802FA30C[];
extern u8 lbl_8055FC8C;
extern char lbl_80342618[];
extern char lbl_803426B0[];
extern s32 lbl_8055F1F4;
}

struct MRollRecordCol {
    virtual void destroy(s32);
};
struct MRollBaseObj {
    u8 data[0xFC];
    void *sub;
    u8 tail[0x24];
    MRollBaseObj() {
        fn_802556BC(this, 0);
    }
    ~MRollBaseObj() {
        fn_80255758(this, -1);
    }
};
struct MRollCarIconCpp {
    u8 base[0xC];
    void *vtable;
    void *secondaryVtable;
    u8 pad14[0x30];
    s32 carIconResource;
    u8 pad48[0x54];
    ~MRollCarIconCpp() {
        s32 lastId;
        vtable = lbl_803426B0;
        secondaryVtable = lbl_803426B0 + 0x18;
        lastId = lbl_8055F1F4;
        lbl_8055F1F4 = lastId - 1;
        fn_80235380(carIconResource, lastId);
    }
};
struct MRollContainer {
    s32 header;
    struct { s32 a, b; } pairs[5];
    u8 widgets[5][0x28];
    char texts[5][0x64];
    u8 tail[4];
    ~MRollContainer() {
        __array_delete(widgets, (void *)MRollStatLabel_deletingDestructor, 0x28, 5);
    }
};
struct MRollRecordOpt {
    u8 base[0xC];
    void *vtable;
    u8 pad10[0x14];
    void *records;
    s32 index;
    char name[0x20];
    char recordName[0x20];
    s32 result;
    ~MRollRecordOpt() {
        vtable = lbl_80342618;
        if (records != 0) {
            ((MRollRecordCol *)records)->destroy(1);
        }
    }
};
struct MRollMenuItem {
    u8 pad00[0x34];
    s32 *payload;
    u8 flag;
    char name[0x20];
};
struct MRollPlayerData {
    MRollBaseObj base;
    MRollCarIconCpp carIcon;
    MRollContainer container;
    MRollRecordOpt recordOpt;
    MRollMenuItem menuItem;
    s32 value;
    MRollPlayerData() {}
    MRollPlayerData(char *slot, s32 arg0) {
        fn_802410F8(&carIcon, (s32)(slot + 0xC), &value, (s32)this);
        MRollContainer_init(&container);
        fn_80240BA4(&recordOpt, (s32)(slot + 4), slot + 8, &carIcon, &container, this);
        fn_80240A1C(&menuItem, (int *)slot, this);
        MRollMenuItem_addEntry(&menuItem, (s32)&recordOpt);
        MRollMenuItem_addEntry(&menuItem, (s32)&carIcon);
        fn_802409A4(&container, arg0);
    }
    void init(char *slot, s32 arg0) {
        fn_802410F8(&carIcon, (s32)(slot + 0xC), &value, (s32)this);
        MRollContainer_init(&container);
        fn_80240BA4(&recordOpt, (s32)(slot + 4), slot + 8, &carIcon, &container, this);
        fn_80240A1C(&menuItem, (int *)slot, this);
        MRollMenuItem_addEntry(&menuItem, (s32)&recordOpt);
        MRollMenuItem_addEntry(&menuItem, (s32)&carIcon);
        fn_802409A4(&container, arg0);
    }
    inline void setup(char *slot, s32 arg0) {
        fn_802556BC(&base, 0);
        fn_802410F8(&carIcon, (s32)(slot + 0xC), &value, (s32)this);
        MRollContainer_init(&container);
        fn_80240BA4(&recordOpt, (s32)(slot + 4), slot + 8, &carIcon, &container, this);
        fn_80240A1C(&menuItem, (int *)slot, this);
        MRollMenuItem_addEntry(&menuItem, (s32)&recordOpt);
        MRollMenuItem_addEntry(&menuItem, (s32)&carIcon);
        fn_802409A4(&container, arg0);
    }
};
struct MRollTwoPlayers {
    MRollPlayerData p0;
    MRollPlayerData p1;
    MRollTwoPlayers() {}
    MRollTwoPlayers(s32 arg0)
        : p0(lbl_80498828, arg0), p1(lbl_80498828 + 0x10, arg0) {}
};
struct MRollFocusEntry {
    void *target;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
};
struct MRollJoinLeaveWidget {
    void *vtable;
    u8 pad04[0x10];
    s32 unk14;
    MRollFocusEntry focii[2];
    u8 mode;
    void addFocus(MRollMenuItem *target, s32 a, s32 b, s32 c, s32 d, s32 e) {
        MRollFocusEntry *entry = focii;
        s32 i;
        for (i = 0; i < 2; i++, entry++) {
            if (entry->target == 0) {
                entry->target = target;
                entry->b = b;
                entry->a = a;
                entry->c = c;
                entry->d = d;
                entry->e = e;
                entry->f = 0;
                if (*target->payload < 0) {
                    entry->g = 1;
                    return;
                }
                entry->g = 2;
                return;
            }
        }
        fn_802E317C(lbl_803422C0 + 0x50, 2);
    }
};
struct MRollMenuEntry {
    s32 label;
    s32 type;
    void *value;
    s32 flags;
    s32 id;
    MRollMenuEntry() {}
    MRollMenuEntry(s32 l, s32 t, void *v, s32 f = 0, s32 i = 0) {
        label = l;
        type = t;
        value = v;
        flags = f;
        id = i;
    }
};
struct MRollDialogCfg {
    s32 w[5];
};

extern "C" s32 fn_8023FF1C(s32 arg0) {
    MRollJoinLeaveWidget widget;
    register char *strings = lbl_803422C0;
    MRollFocusEntry *focii;
    MRollFocusEntry *entry;
    s32 i;
    s32 ret;
    s32 running;

    fn_8001880C();
    fn_8013C804();
    MRollTwoPlayers players(arg0);

    widget.vtable = lbl_803425B8;
    widget.unk14 = 0;
    memset(widget.focii, 0, sizeof(widget.focii));

    focii = widget.focii;
    entry = focii;
    for (i = 0; i < 2; i++, entry++) {
        if (entry->target == 0) {
            entry->target = &players.p0.menuItem;
            entry->b = 1;
            entry->a = 3;
            entry->c = 5;
            entry->d = 7;
            entry->e = 9;
            entry->f = 0;
            if (*players.p0.menuItem.payload < 0) {
                entry->g = 1;
                goto focus0_done;
            }
            entry->g = 2;
            goto focus0_done;
        }
    }
    fn_802E317C(strings + 0x50, 2);
focus0_done:

    entry = focii;
    for (i = 0; i < 2; i++, entry++) {
        if (entry->target == 0) {
            entry->target = &players.p1.menuItem;
            entry->b = 2;
            entry->a = 4;
            entry->c = 6;
            entry->d = 8;
            entry->e = 10;
            entry->f = 0;
            if (*players.p1.menuItem.payload < 0) {
                entry->g = 1;
                goto focus1_done;
            }
            entry->g = 2;
            goto focus1_done;
        }
    }
    fn_802E317C(strings + 0x50, 2);
focus1_done:
    {
        const MRollMenuEntry endEntry = *(const MRollMenuEntry *)lbl_80498810;
        MRollMenuEntry entries[38] = {
            MRollMenuEntry(0, 5, &widget),
            MRollMenuEntry(0, 5, &players.p0.menuItem),
            MRollMenuEntry((s32)(strings + 0x90), 0x13, &players.p0),
            MRollMenuEntry((s32)(strings + 0x90), 3, players.p0.recordOpt.name),
            MRollMenuEntry((s32)(strings + 0x9C), 0x10, 0, (s32)&players.p0.recordOpt),
            MRollMenuEntry((s32)(strings + 0xA8), 5, &players.p0.carIcon.secondaryVtable),
            MRollMenuEntry((s32)(strings + 0xB4), 2, &players.p0.recordOpt.result),
            MRollMenuEntry((s32)(strings + 0xC0), 3, players.p0.menuItem.name),
            MRollMenuEntry((s32)(strings + 0xD0), 5, &players.p0.base.sub),
            MRollMenuEntry((s32)(strings + 0xE0), 3, players.p0.container.texts[0]),
            MRollMenuEntry((s32)(strings + 0xF0), 2, &players.p0.container.pairs[0].b),
            MRollMenuEntry((s32)(strings + 0x100), 3, players.p0.container.texts[1]),
            MRollMenuEntry((s32)(strings + 0x110), 2, &players.p0.container.pairs[1].b),
            MRollMenuEntry((s32)(strings + 0x120), 3, players.p0.container.texts[2]),
            MRollMenuEntry((s32)(strings + 0x130), 2, &players.p0.container.pairs[2].b),
            MRollMenuEntry((s32)(strings + 0x140), 3, players.p0.container.texts[3]),
            MRollMenuEntry((s32)(strings + 0x150), 5, players.p0.container.widgets[3]),
            MRollMenuEntry((s32)(strings + 0x168), 3, players.p0.container.texts[4]),
            MRollMenuEntry((s32)(strings + 0x178), 2, &players.p0.container.pairs[4].b),
            MRollMenuEntry(0, 5, &players.p1.menuItem),
            MRollMenuEntry((s32)(strings + 0x188), 0x13, &players.p1),
            MRollMenuEntry((s32)(strings + 0x188), 3, players.p1.recordOpt.name),
            MRollMenuEntry((s32)(strings + 0x194), 0x10, 0, (s32)&players.p1.recordOpt),
            MRollMenuEntry((s32)(strings + 0x1A0), 5, &players.p1.carIcon.secondaryVtable),
            MRollMenuEntry((s32)(strings + 0x1AC), 2, &players.p1.recordOpt.result),
            MRollMenuEntry((s32)(strings + 0x1B8), 3, players.p1.menuItem.name),
            MRollMenuEntry((s32)(strings + 0x1C8), 5, &players.p1.base.sub),
            MRollMenuEntry((s32)(strings + 0x1D8), 3, players.p1.container.texts[0]),
            MRollMenuEntry((s32)(strings + 0x1E8), 2, &players.p1.container.pairs[0].b),
            MRollMenuEntry((s32)(strings + 0x1F8), 3, players.p1.container.texts[1]),
            MRollMenuEntry((s32)(strings + 0x208), 2, &players.p1.container.pairs[1].b),
            MRollMenuEntry((s32)(strings + 0x218), 3, players.p1.container.texts[2]),
            MRollMenuEntry((s32)(strings + 0x228), 2, &players.p1.container.pairs[2].b),
            MRollMenuEntry((s32)(strings + 0x238), 3, players.p1.container.texts[3]),
            MRollMenuEntry((s32)(strings + 0x248), 5, players.p1.container.widgets[3]),
            MRollMenuEntry((s32)(strings + 0x260), 3, players.p1.container.texts[4]),
            MRollMenuEntry((s32)(strings + 0x270), 2, &players.p1.container.pairs[4].b),
            endEntry
        };
        MRollDialogCfg dialog;

        char *title = strings + 0x290;
        if (lbl_8055FC8C != 0) {
            title = strings + 0x280;
        }
        dialog = *(const MRollDialogCfg *)lbl_802FA30C;
        dialog.w[0] = (s32)title;
        ret = 1;
        dialog.w[1] = (s32)entries;
        fn_80129AEC(-1);
        running = 1;
        while (running) {
            s32 res = fn_802146BC(&dialog, -0x3E7, -0x3E7, 1);
            switch (res) {
            case 0:
                ret = 1;
                running = 0;
                break;
            case 1:
                fn_802E4A10();
                fn_8023D4B8();
                break;
            case 2:
                ret = 0;
                running = 0;
                break;
            default:
                fn_802E317C(strings + 0x2A0, res);
                break;
            }
        }
        fn_80129AEC(0);
        fn_8013C8B8();
        fn_80018B24();
        return ret;
    }
}
#pragma pop
extern char lbl_80342618[];
s32 fn_802407B0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_802407F0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

/* One player's record (truck) choice, built by fn_80240BA4 and destroyed by fn_80240830.
   Vtable lbl_80342618 sits at +0xC (the shared base covers +0x00..+0x0B: u8 flag,
   s32 id = -1, u8 active).  fn_8023FF1C places two of them, one per player slot
   in g_MRollPlayerSlots (lbl_80498828). */
typedef struct MRollRecordOption {
    u8 base[0xC];        /* +0x00: shared non-virtual base */
    void *vtable;        /* +0x0C: lbl_80342618 */
    void *valueSink;     /* +0x10: written with the record's +0x9C field */
    s32 *desiredId;      /* +0x14: id to select, matched against record+0x4 */
    void *ctx;           /* +0x18: selection context (record, index, name) */
    void *playerInfo;    /* +0x1C: 0x2E8-byte player info block filled from the record */
    void *field20;       /* +0x20: block whose +0xDD is cleared when the result is 0 */
    void *records;       /* +0x24: record collection from fn_8027DB40(6); owned, deleted here */
    s32 index;           /* +0x28: index of the selected record */
    char name[0x20];     /* +0x2C: item name */
    char recordName[0x20]; /* +0x4C: record's own name (record+0xC) */
    s32 result;          /* +0x6C: collection getResult(index) */
} MRollRecordOption;

/* One player's car icon on the roll (player-select) screen: built by fn_802410F8
   and destroyed by MRollCarIcon_deletingDestructor.  Like MRollRecordOption it sits behind the
   0xC-byte non-virtual base, so its own vtable is at +0xC and the secondary
   base subobject's at +0x10 (both inside the class's vtable lbl_803426B0;
   fn_80243470 is that secondary's deleting destructor). */
typedef struct MRollCarIcon {
    u8 base[0xC];          /* +0x00: shared non-virtual base (u8 flag, s32 id = -1, u8 active) */
    void *vtable;          /* +0x0C: lbl_803426B0 */
    void *secondaryVtable; /* +0x10: lbl_803426B0 + 0x18 */
    s32 field14;           /* +0x14 */
    s32 field18;           /* +0x18 */
    s32 field1C;           /* +0x1C */
    s32 field20;           /* +0x20 */
    s32 field24;           /* +0x24 */
    s32 field28;           /* +0x28 */
    s32 value;             /* +0x2C: copy of *valuePtr taken by fn_802410F8 */
    s32 *valuePtr;         /* +0x30: the value this icon follows */
    s32 id;                /* +0x34: id the icon was built with */
    s32 field38;           /* +0x38 */
    s32 instanceId;        /* +0x3C: id taken from the next-id counter lbl_8055F1F4 */
    s32 field40;           /* +0x40 */
    s32 carIconResource;   /* +0x44: "caricona.art" handle loaded by fn_8023512C */
} MRollCarIcon;

extern int fn_80128668(); /* free(): releases an allocation back to the primary/secondary buffer */
#pragma cplusplus on
/* Deleting destructor: reinstall this option's vtable, destroy the record
 * collection it owns, and free the object itself when shouldFree is set. */
extern "C" void *fn_80240830(MRollRecordOption *self, s32 shouldFree) {
    class RecordCollection {
    public:
        virtual void destroy(s32 deleteFlag); /* slot 0x8: its deleting destructor */
    };
    void *ownedRecords;
    if (self != 0) {
        ownedRecords = self->records;
        self->vtable = lbl_80342618;
        if (ownedRecords != 0) {
            ((RecordCollection *)ownedRecords)->destroy(1);
        }
        if (shouldFree > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}
#pragma cplusplus reset
extern char lbl_80342618[];
extern char lbl_803426B0[];
extern s32 lbl_8055F1F4;
extern s32 fn_80235380(s32, s32);
/* Deleting destructor of a player's MRollCarIcon (the "caricona.art" car icon of
   the roll screen): installs this class's two vtables, hands the id it was given
   back to the next-id counter, releases the car-icon resource owned at +0x44
   and, when deleteFlag > 0, frees the object itself through the game's free(). */
/* Deleting destructor for a player's roll-screen car icon: restore vtables, recycle its id and release the art resource, freeing the object when deleteFlag > 0. */ void *MRollCarIcon_deletingDestructor(MRollCarIcon *self, s32 deleteFlag) {
#define CarIcon_vtable lbl_803426B0 /* this class's vtable; the secondary base's is at +0x18 */
#define sNextCarIconId lbl_8055F1F4 /* next id handed out by fn_802410F8 */
#define Resource_release fn_80235380 /* drops one reference on a loaded resource */
    s32 lastId;
    if (self != 0) {
        self->vtable = CarIcon_vtable;
        self->secondaryVtable = CarIcon_vtable + 0x18;
        lastId = sNextCarIconId;
        sNextCarIconId = lastId - 1;
        Resource_release(self->carIconResource, lastId);
        if (deleteFlag > 0) fn_80128668(self); /* free() */
    }
    return self;
#undef CarIcon_vtable
#undef sNextCarIconId
#undef Resource_release
}

extern char lbl_80342734[];
extern s32 fn_802328D4(s32, s32);
#define sMRollStatLabelVtable lbl_80342734
#define Font_release fn_802328D4
#define Memory_free fn_80128668

enum {
    MROLL_STAT_FONT_OFFSET      = 0x18,
    MROLL_STAT_FLAG_OFFSET      = 0x20,
    MROLL_STAT_VALUE_PTR_OFFSET = 0x24
};
/* Deleting destructor for a UI car stat label: reinstalls its vtable, clears its value pointer/flag, releases its font, and frees the object when requested. */
void *MRollStatLabel_deletingDestructor(void *thisLabel, s32 shouldFree) {
    s32 zeroValue = 0;
    if (thisLabel != 0) {
        *(s32 *)((char *)thisLabel + MROLL_STAT_VALUE_PTR_OFFSET) = zeroValue;
        *(void **)thisLabel = sMRollStatLabelVtable;
        *(s32 *)((char *)thisLabel + MROLL_STAT_FLAG_OFFSET) = zeroValue;
        Font_release(*(s32 *)((char *)thisLabel + MROLL_STAT_FONT_OFFSET), (s32)sMRollStatLabelVtable);
        *(s32 *)((char *)thisLabel + MROLL_STAT_FONT_OFFSET) = zeroValue;
        if (shouldFree > 0) Memory_free(thisLabel);
    }
    return thisLabel;
}

void fn_802409A4(void *object, s32 value) {
    /* Set the signed 8-bit field at offset 0x2E8 of a menu/UI object. */
    *(signed char *)((char *)object + 0x2E8) = (signed char)value;
}

/* Append a menu entry id and refresh each item's selected flag and displayed value from the shared payload. */
void MRollMenuItem_addEntry(void *menu, s32 entryId) {
    void *item;
    s32 count = *(s32 *)((char *)menu + 0x2C);
    s32 index;
    s32 value;
    char *entryCursor = (char *)menu;
    s32 isSelected;
    *(s32 *)((char *)menu + 0x18 + count * 4) = entryId;
    *(s32 *)((char *)menu + 0x2C) = count + 1;
    for (index = 0; index < *(s32 *)((char *)menu + 0x2C);) {
        value = **(s32 **)((char *)menu + 0x34);
        isSelected = *(u8 *)((char *)menu + 0x38) != 0 && index == *(s32 *)((char *)menu + 0x30);
        item = *(void **)(entryCursor + 0x18);
        entryCursor += 4;
        index++;
        *(u8 *)item = isSelected;
        *(s32 *)((char *)item + 4) = value;
    }
}

#pragma scheduling invalid_target
void *fn_80240A1C(void *menuItemOut, int *valuePtr, void *ownerObj) {
    extern unsigned char *fn_802E85B8(int);
    extern char lbl_80342650[];
    extern char lbl_8055BD60;
#define gMRollMenuItemVtable lbl_80342650
#define gMRollEmptyName      lbl_8055BD60
    struct Constructor {
        void *vtable;
        u8 pad4[0x10];
        int field14;
        void *entries[4];
        void *owner;
        int count;
        int selected;
        int *payload;
        u8 active;
        char name[0x20];
    };
    struct Constructor *item = (struct Constructor *)menuItemOut;
    int index;

    /* Constructs a menu item: binds its vtable, owner and value pointer, copies the default or value-indexed name, and refreshes each entry's selected flag and displayed value. */
    item->vtable = gMRollMenuItemVtable;
    {
        char *nameSource;
        int remaining;
        char *nameDest = item->name;
        item->owner = ownerObj;
        item->field14 = 0;
        item->count = 0;
        item->selected = 0;
        item->payload = valuePtr;
        item->active = 1;
        remaining = 0x20;
        nameSource = &gMRollEmptyName;
        while ((signed char)(*nameDest++ = *nameSource++) != 0) {
            if (--remaining <= 0) {
                nameDest[-1] = 0;
                break;
            }
        }
    }
    *(int *)((unsigned char *)item->owner + 0xD8) = *item->payload;
    if (*item->payload < 0) {
        char *nameSource = &gMRollEmptyName;
        int remaining = 0x20;
        char *nameDest = item->name;
        while ((signed char)(*nameDest++ = *nameSource++) != 0) {
            if (--remaining <= 0) {
                nameDest[-1] = 0;
                break;
            }
        }
    } else {
        char *nameSource = (char *)fn_802E85B8(*item->payload);
        int remaining = 0x20;
        char *nameDest = item->name;
        while ((signed char)(*nameDest++ = *nameSource++) != 0) {
            if (--remaining <= 0) {
                nameDest[-1] = 0;
                break;
            }
        }
    }
    {
        void *entryItem;
        int isSelected;
        int currentValue;
        register void **entryCursor = (void **)item;
        index = 0;
        while (index < item->count) {
            currentValue = *item->payload;
            isSelected = item->active != 0 && index == item->selected;
            entryItem = entryCursor[6];
            entryCursor++;
            index++;
            *(u8 *)entryItem = isSelected;
            *(int *)((char *)entryItem + 4) = currentValue;
        }
    }
    return item;
#undef gMRollEmptyName
#undef gMRollMenuItemVtable
}
#pragma cplusplus on
extern "C" void *fn_80240BA4(void *arg0, s32 arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    s32 index, result, i, n, wordA, wordB, count, j;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
    register void *self = arg0;
    register void *desired = arg2;
    char *src, *dst, *entries, *output, *zeroBase, *textItem, *object;
    char c;
    struct Collection {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual void *getItem(s32) = 0;
        virtual s32 getResult(s32) = 0;
        virtual void f8() = 0;
        virtual void f9() = 0;
        virtual void f10() = 0;
        virtual void f11() = 0;
        virtual void f12() = 0;
        virtual void f13() = 0;
        virtual void f14() = 0;
        virtual void f15() = 0;
        virtual void f16() = 0;
        virtual void f17() = 0;
        virtual void f18() = 0;
        virtual void f19() = 0;
        virtual void f20() = 0;
        virtual void f21() = 0;
        virtual void f22() = 0;
        virtual void f23() = 0;
        virtual void draw(s32, void *, void *) = 0;
    };

    *(s32 *)((u8 *)self + 0x10) = arg1;
    *(u8 *)((u8 *)self + 0x0) = 0;
    *(s32 *)((u8 *)self + 0x4) = -1;
    *(u8 *)((u8 *)self + 0x8) = 0;
    *(void **)((u8 *)self + 0x0C) = lbl_80342618;
    *(void **)((u8 *)self + 0x14) = desired;
    *(void **)((u8 *)self + 0x18) = arg3;
    *(void **)((u8 *)self + 0x1C) = arg4;
    *(void **)((u8 *)self + 0x20) = arg5;
    *(void **)((u8 *)self + 0x24) = fn_8027DB40(6);
    *(u8 *)((u8 *)self + 0x8) = 1;
    *(s32 *)((u8 *)self + 0x28) = 0;

    j = 0;
    count = ((Collection *)*(void **)((u8 *)self + 0x24))->getCount();
    while (j < count) {
        item = ((Collection *)*(void **)((u8 *)self + 0x24))->getItem(j);
        record = fn_8001668C(item, 0);
        if (*(s32 *)((u8 *)record + 4) == *(s32 *)desired) {
            *(s32 *)((u8 *)self + 0x28) = j;
            break;
        }
        j++;
    }

    index = *(s32 *)((u8 *)self + 0x28);
    if (index < 0) goto done;
    if (index >= ((Collection *)*(void **)((u8 *)self + 0x24))->getCount()) goto done;

    item = ((Collection *)*(void **)((u8 *)self + 0x24))->getItem(index);
    record = fn_8001668C(item, 0);
    *(s32 *)(*(void **)((u8 *)self + 0x14)) = *(s32 *)((u8 *)record + 4);
    *(s32 *)(*(void **)((u8 *)self + 0x10)) = *(s32 *)((u8 *)record + 0x9C);

    dst = (char *)arg0 + 0x2C;
    src = (char *)item;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    src = (char *)record + 0xC;
    dst = (char *)arg0 + 0x4C;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    result = ((Collection *)*(void **)((u8 *)self + 0x24))->getResult(*(s32 *)((u8 *)self + 0x28));
    *(s32 *)((u8 *)self + 0x6C) = result;
    *(signed char *)((u8 *)*(void **)((u8 *)self + 0x20) + 0xDD) = (result == 0);

    ctx = *(void **)((u8 *)self + 0x18);
    if (*(void **)((u8 *)ctx + 0x28) != 0) {
        index = *(s32 *)((u8 *)ctx + 0x2C);
        item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
        *(s32 *)((u8 *)item + 4) = index;
    }
    *(void **)((u8 *)ctx + 0x28) = record;
    index = *(s32 *)((u8 *)ctx + 0x2C);
    if (*(s32 *)((u8 *)record + 0x98) - 1 < index) {
        index = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    *(s32 *)((u8 *)ctx + 0x2C) = index;

    item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
    index = *(s32 *)((u8 *)item + 4);
    *(s32 *)((u8 *)ctx + 0x2C) = index;
    *(u8 *)((u8 *)ctx + 0x5C) = 0;
    if (index >= 0 && index < *(s32 *)(*(u8 **)((u8 *)ctx + 0x28) + 0x98)) {
        item = *(void **)((u8 *)*(void **)((u8 *)ctx + 0x28) + 0x64 + index * 4);
        *(void **)(*(void **)((u8 *)ctx + 0x34)) = item;
        fn_80255918(*(void **)((u8 *)ctx + 0x38), item);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            (u8 *)ctx + 0x5C, 0x40, lbl_8034287C,
            *(s32 *)((u8 *)ctx + 0x2C) + 1);
        src = (char *)fn_80131234((u8 *)ctx + 0x5C);
        dst = (char *)ctx + 0x5C;
        n = 0x40;
        do {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
        } while (c != 0);
    }

    *(s32 *)(*(void **)((u8 *)ctx + 0x30)) = *(s32 *)((u8 *)ctx + 0x2C);
    *(s32 *)((u8 *)ctx + 0x48) = -0xFA;
    *(float *)((u8 *)ctx + 0x4C) = (float)*(s32 *)((u8 *)ctx + 0x2C);
    *(float *)((u8 *)ctx + 0x50) = (float)*(s32 *)((u8 *)ctx + 0x2C);

    infoDst = *(void **)((u8 *)self + 0x1C);
    info = ((void *(*)(void *))fn_80018A8C)((u8 *)self + 0x2C);
    if (info != 0) {
        ((s32 *)infoDst)[0] = ((s32 *)info)[0];
        wordA = ((s32 *)info)[2];
        wordB = ((s32 *)info)[1];
        ((s32 *)infoDst)[1] = wordB;
        ((s32 *)infoDst)[2] = wordA;
        wordA = ((s32 *)info)[4];
        wordB = ((s32 *)info)[3];
        ((s32 *)infoDst)[3] = wordB;
        ((s32 *)infoDst)[4] = wordA;
        wordA = ((s32 *)info)[6];
        wordB = ((s32 *)info)[5];
        ((s32 *)infoDst)[5] = wordB;
        ((s32 *)infoDst)[6] = wordA;
        wordA = ((s32 *)info)[8];
        wordB = ((s32 *)info)[7];
        ((s32 *)infoDst)[7] = wordB;
        ((s32 *)infoDst)[8] = wordA;
        wordA = ((s32 *)info)[10];
        wordB = ((s32 *)info)[9];
        ((s32 *)infoDst)[9] = wordB;
        ((s32 *)infoDst)[10] = wordA;

        entries = (char *)infoDst;
        zeroBase = (char *)infoDst;
        output = (char *)infoDst + 0xF4;
        textItem = (char *)infoDst + 8;
        object = (char *)infoDst + 0x2C;
        i = 0;
        do {
            src = *(char **)(entries + 4);
            if (src != 0) {
                dst = output;
                n = 0x64;
                do {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                    c = *src++;
                    *dst++ = c;
                } while (c != 0);
            } else {
                *(u8 *)(zeroBase + 0xF4) = 0;
            }
            ((Collection *)object)->draw(i, textItem, (u8 *)infoDst + 0x2E8);
            entries += 8;
            zeroBase += 0x64;
            output += 0x64;
            textItem += 8;
            object += 0x28;
            i++;
        } while (i < 5);
    } else {
        memset(infoDst, 0, 0x2C);
        *(u8 *)((u8 *)infoDst + 0xF4) = 0;
        *(u8 *)((u8 *)infoDst + 0x158) = 0;
        *(u8 *)((u8 *)infoDst + 0x1BC) = 0;
        *(u8 *)((u8 *)infoDst + 0x220) = 0;
        *(u8 *)((u8 *)infoDst + 0x284) = 0;
    }
done:
    return arg0;
}
#pragma cplusplus reset

extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern void *memset(void *, int, unsigned int);
/* Set an MRoll stat label's one-based display rank (+0x1C), value pointer (+0x24)
 * and flag block (+0x20), used later when the label is drawn. */
void fn_80241010(void *label, s32 rankIndex, s32 valuePtr, s32 flag) {
    *(s32 *)((u8 *)label + MROLL_STAT_VALUE_PTR_OFFSET) = valuePtr;
    *(s32 *)((u8 *)label + 0x1C) = rankIndex + 1;
    *(s32 *)((u8 *)label + MROLL_STAT_FLAG_OFFSET) = flag;
}

/* Constructs an MRollContainer's five stat-label widgets (0x28 bytes each at +0x2C), zeroes the 0x2C-byte header/pair block, and clears the leading flag byte of each of the five 0x64-byte text blocks. */
void *MRollContainer_init(void *container) {
    fn_8002F53C((u8 *)container + 0x2C, MRollStatLabel_init, MRollStatLabel_deletingDestructor, 0x28, 5);
    memset(container, 0, 0x2C);
    *(u8 *)((u8 *)container + 0xF4) = 0;
    *(u8 *)((u8 *)container + 0x158) = 0;
    *(u8 *)((u8 *)container + 0x1BC) = 0;
    *(u8 *)((u8 *)container + 0x220) = 0;
    *(u8 *)((u8 *)container + 0x284) = 0;
    return container;
}

/* Initializes an MRoll stat label with its vtable, default fields, and the uifnt_o.gtx font resource. */
void *MRollStatLabel_init(void *statLabel) {
    s32 zero = 0;
    s32 minusOne = -1;
    *(void **)statLabel = lbl_80342734;
    *(s32 *)((u8 *)statLabel + 0x14) = zero;
    *(s32 *)((u8 *)statLabel + 0x1C) = minusOne;
    *(s32 *)((u8 *)statLabel + 0x24) = zero;
    *(s32 *)((u8 *)statLabel + 0x20) = zero;
    *(s32 *)((u8 *)statLabel + 0x18) = ((s32 (*)(char *))fn_80232578)(lbl_8034288C);
    return statLabel;
}

/* Construct an object (vtable lbl_803426B0, secondary +0x18), copy *valuePtr, store id/arg3,
   assign next id from lbl_8055F1F4, load resource "caricona.art" via fn_8023512C, init floats to 0.0f. */
/* Construct a roll/player-info object: set its two vtables and fields, copy the supplied value, assign and bump the global id counter, load the car-icon art set, and zero its float fields. */ void *fn_802410F8(void *self, s32 id, s32 *valuePtr, s32 arg3) {
    s32 nextId;
    s32 resource;
    float zero;

    *(void **)((u8 *)self + 0xC) = lbl_803426B0;
    *(s32 *)((u8 *)self + 4) = -1;
    *(u8 *)self = 0;
    *((u8 *)self + 8) = 1;
    *(s32 *)((u8 *)self + 0x24) = 0;
    *(void **)((u8 *)self + 0x10) = lbl_803426B0 + 0x18;
    *(s32 *)((u8 *)self + 0x28) = 0;
    *(s32 *)((u8 *)self + 0x2C) = *valuePtr;
    *(s32 **)((u8 *)self + 0x30) = valuePtr;
    *(s32 *)((u8 *)self + 0x34) = id;
    *(s32 *)((u8 *)self + 0x38) = arg3;

    nextId = lbl_8055F1F4;
    *(s32 *)((u8 *)self + 0x3C) = nextId;
    lbl_8055F1F4 = nextId + 1;

    resource = ((s32 (*)(char *))fn_8023512C)(lbl_803425A8);
    zero = lbl_80563758;
    *(s32 *)((u8 *)self + 0x44) = resource;
    *(float *)((u8 *)self + 0x58) = zero;
    *(float *)((u8 *)self + 0x54) = zero;
    *(u8 *)((u8 *)self + 0x5C) = 0;

    return self;
}

/* If a pending result flag is set, copy its value to outResult and return 1; otherwise return 0. */
s32 fn_802411A4(s32 *outResult) {
    if (lbl_8055F1FC != 0) {
        *outResult = lbl_8055F200;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
extern void fn_8023FE20(void);
/* MRoll_Reset: non-inlined wrapper that tail-calls fn_8023FE20 to reset the
 * mroll player slots (lbl_80498828) to -1 before truck selection. */
void fn_802411C8(void) { fn_8023FE20(); }
#pragma dont_inline reset

#pragma dont_inline on
extern s32 fn_8023FE34(void);
/* MRoll: non-inlined wrapper that tail-calls the active-driver-slot counter
 * (fn_8023FE34); the returned count drives the caller's per-driver refresh loop. */
s32 fn_802411CC(void) { fn_8023FE34(); }
#pragma dont_inline reset

extern void fn_8023FE60();
/* Wrapper for fn_8023FE60: looks up the active mroll player slot for a driver
 * index and writes that slot's vehicle/track params through the out pointers. */
void fn_802411D0(void) { fn_8023FE60(); }

#pragma dont_inline fn_802411D4
/* Returns non-zero when player/controller slots 0 and 1 are both ready. */
s32 fn_802411D4(void) {
    s32 bothReady;
    bothReady = 0;
    if ((fn_802E8504(0) != 0) && (fn_802E8504(1) != 0)) {
        bothReady = 1;
    }
    return bothReady;
}

extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
s32 fn_8023512C(char *, s32, char *, s32);
s32 fn_80232578(char *, char *, s32);
/* Unused no-op stub in the mroll (player-info/roll) module; this build leaves it empty. */
void fn_80241224(void) {
}

/* Unused no-op stub in the mroll (player-info/roll) module; this build leaves it empty. */
void fn_80241228(void) {
}

extern int fn_80230C30(float *, float *, int, int);
extern int fn_801345D8(void *, int, void *, int);
extern int fn_80131234(void *);
extern int fn_80232BA4(int, int, int, float, float, float, float, float);
extern int lbl_802FA300[3];
extern char lbl_80342898[];
extern float lbl_8056375C, lbl_80563760, lbl_80563764;
#pragma processor 750
/* Draw an MRoll car-stat label: derive a 0..3 tier from the stat value at
 * +0x24 against the thresholds, format the localized message key
 * "UICar:STAT_%i_TEXT_%i" from the label's rank and tier, pick the flag-driven
 * style and scale, then draw the localized text at the label's screen position.
 * Labels with a negative rank (+0x1C) are skipped. */
void fn_8024122C(void *statLabel) {
    char msgKey[0x1E];
    float centeredX, centeredY;
    int tier;
    float textScale;
    int style;
    int localizedText;
    int *tierThresholds;
    volatile int *valuePtr;
    int statValue;

    fn_80230C30(&centeredX, &centeredY, *(int *)((char *)statLabel + 4), *(int *)((char *)statLabel + 8));
    if (*(int *)((char *)statLabel + 0x1C) >= 0) {
        valuePtr = *(volatile int * volatile *)((char *)statLabel + MROLL_STAT_VALUE_PTR_OFFSET);
        tierThresholds = lbl_802FA300;
        statValue = *valuePtr;
        tier = 0;
        if (statValue != 0 && statValue >= tierThresholds[0])
            tier = 1;
        valuePtr = *(volatile int * volatile *)((char *)statLabel + MROLL_STAT_VALUE_PTR_OFFSET);
        statValue = *valuePtr;
        if (statValue != 0 && statValue >= tierThresholds[1])
            tier = 2;
        valuePtr = *(volatile int * volatile *)((char *)statLabel + MROLL_STAT_VALUE_PTR_OFFSET);
        statValue = *valuePtr;
        if (statValue != 0 && statValue >= tierThresholds[2])
            tier = 3;
        ((int (*)(void *, int, void *, ...))fn_801345D8)(msgKey, 0x1E, lbl_80342898, *(int *)((char *)statLabel + 0x1C), tier);
        textScale = lbl_8056375C;
        style = 0xA;
        if (*(unsigned char *)*(void **)((char *)statLabel + MROLL_STAT_FLAG_OFFSET)) {
            textScale = lbl_80563760;
            style = 9;
        }
        localizedText = fn_80131234(msgKey);
        ((int (*)(int, int, int, int, float, float, float, float, float))fn_80232BA4)(localizedText, *(int *)((char *)statLabel + MROLL_STAT_FONT_OFFSET), -0x100, style, centeredX, centeredY, textScale, lbl_80563758, lbl_80563764);
    }
}
#pragma processor reset
extern void fn_80216D28(void);
extern int fn_80214D50(int);
extern float fn_8023659C(int *);
extern float lbl_80563764, lbl_80563768, lbl_8056376C, lbl_80563770;
extern float lbl_80563774, lbl_80563778, lbl_8056377C;
#pragma scheduling on
s32 fn_80241354(void *__restrict arg0, s32 arg1) {
    char *base = (char *)arg0;
    s32 direction = arg1;
    s32 active = 0;
    void *child;
    char c;
    int n;
    char *dst, *src;
    int count, index, frame, boundary;
    int *animation;
    float temp, diff, start, end;
    float t, curve;
    register void *vtable = *(void **)(base + 0x0C);
    register void *method = *(void **)((char *)vtable + 0x10);
    int result = ((int (*)(void *))method)(arg0);
    if (result != 0) {
        active = 1;
        switch (direction) {
        case 0x127:
        index = *(int *)(base + 0x2C) + 1;
        *(int *)(base + 0x2C) = index;
        count = *(int *)((char *)*(void **)(base + 0x28) + 0x98);
        boundary = 0;
        if (index >= count) {
            *(int *)(base + 0x2C) = count - 1;
            boundary = 1;
        }
        if (boundary != 0) {
            fn_80216D28();
            fn_80214D50(1);
            goto done;
        }
        if (*(void **)(base + 0x28) != 0) {
            index = *(volatile int *)(base + 0x2C);
            child = fn_80016BC8(*(void **)(base + 0x28), *(int *)(base + 0x3C));
            *(int *)((char *)child + 4) = index;
        }
        index = *(int *)(base + 0x2C);
        *(signed char *)(base + 0x5C) = 0;
        if (index >= 0 && index < *(int *)((char *)*(void **)(base + 0x28) + 0x98)) {
            child = *(void **)((char *)*(void **)(base + 0x28) + 0x64 + index * 4);
            **(void ***)(base + 0x34) = child;
            fn_80255918(*(void **)(base + 0x38), child);
            ((int (*)(void *, int, char *, ...))fn_801345D8)(base + 0x5C, 0x40, lbl_8034287C, *(int *)(base + 0x2C) + 1);
            src = (char *)fn_80131234(base + 0x5C);
            dst = base + 0x5C;
            n = 0x40;
            goto copy_body_forward;
copy_check_forward:
            if (--n <= 0) {
                dst[-1] = 0;
                goto copy_done_forward;
            }
copy_body_forward:
            c = *src++;
            *dst++ = c;
            if ((signed char)c != 0) goto copy_check_forward;
copy_done_forward:
            ;
        }
        animation = *(int **)(base + 0x30);
        *animation = *(int *)(base + 0x2C);
        frame = (int)(fn_8023659C(animation) * lbl_80563768);
        temp = (float)(frame - *(int *)(base + 0x48)) / lbl_8056376C;
        t = (lbl_80563764 < temp) ? lbl_80563764 : temp;
        t = (t > lbl_80563758) ? t : lbl_80563758;
        curve = (t < lbl_80563770) ? lbl_80563770 : ((t > lbl_80563764) ? lbl_80563764 : ((t > lbl_80563758) ? (t * ((lbl_80563774 * t) * t) + (lbl_80563778 * t) * t) : (t * ((lbl_80563774 * t) * t) - (lbl_80563778 * t) * t)));
        start = *(float *)(base + 0x4C);
        end = *(float *)(base + 0x50);
        diff = end - start;
        *(int *)(base + 0x48) = frame;
        *(float *)(base + 0x58) = lbl_8056377C;
        *(float *)(base + 0x4C) = start + curve * diff;
        *(float *)(base + 0x50) = (float)*(int *)(base + 0x2C);
        break;
        case 0x125:
        index = *(int *)(base + 0x2C) - 1;
        *(int *)(base + 0x2C) = index;
        boundary = 0;
        if (index < 0) {
            *(int *)(base + 0x2C) = 0;
            boundary = 1;
        }
        if (boundary != 0) {
            fn_80216D28();
            fn_80214D50(1);
            goto done;
        }
        if (*(void **)(base + 0x28) != 0) {
            index = *(volatile int *)(base + 0x2C);
            child = fn_80016BC8(*(void **)(base + 0x28), *(int *)(base + 0x3C));
            *(int *)((char *)child + 4) = index;
        }
        index = *(int *)(base + 0x2C);
        *(signed char *)(base + 0x5C) = 0;
        if (index >= 0 && index < *(int *)((char *)*(void **)(base + 0x28) + 0x98)) {
            child = *(void **)((char *)*(void **)(base + 0x28) + 0x64 + index * 4);
            **(void ***)(base + 0x34) = child;
            fn_80255918(*(void **)(base + 0x38), child);
            ((int (*)(void *, int, char *, ...))fn_801345D8)(base + 0x5C, 0x40, lbl_8034287C, *(int *)(base + 0x2C) + 1);
            src = (char *)fn_80131234(base + 0x5C);
            dst = base + 0x5C;
            n = 0x40;
            goto copy_body_backward;
copy_check_backward:
            if (--n <= 0) {
                dst[-1] = 0;
                goto copy_done_backward;
            }
copy_body_backward:
            c = *src++;
            *dst++ = c;
            if ((signed char)c != 0) goto copy_check_backward;
copy_done_backward:
            ;
        }
        animation = *(int **)(base + 0x30);
        *animation = *(int *)(base + 0x2C);
        frame = (int)(fn_8023659C(animation) * lbl_80563768);
        temp = (float)(frame - *(int *)(base + 0x48)) / lbl_8056376C;
        t = (lbl_80563764 < temp) ? lbl_80563764 : temp;
        t = (t > lbl_80563758) ? t : lbl_80563758;
        curve = (t < lbl_80563770) ? lbl_80563770 : ((t > lbl_80563764) ? lbl_80563764 : ((t > lbl_80563758) ? (t * ((lbl_80563774 * t) * t) + (lbl_80563778 * t) * t) : (t * ((lbl_80563774 * t) * t) - (lbl_80563778 * t) * t)));
        start = *(float *)(base + 0x4C);
        end = *(float *)(base + 0x50);
        diff = end - start;
        *(int *)(base + 0x48) = frame;
        *(float *)(base + 0x54) = lbl_8056377C;
        *(float *)(base + 0x4C) = start + curve * diff;
        *(float *)(base + 0x50) = (float)*(int *)(base + 0x2C);
        break;
        default:
        case 0x126:
            active = 0;
            break;
        }
    }
done:
    return active;
}
extern float lbl_80563780, lbl_80563784, lbl_80563788, lbl_8056378C, lbl_80563790, lbl_80563794;
extern float fn_8023659C();
extern void fn_802354A0(int, int, unsigned, float, float, float, float, float);
extern void fn_80235758(int, int, unsigned, float, float, float, float, float, float, float, float);
extern s32 fn_80211660(s32);
extern float fn_80235F64(s32, s32);
extern float fn_80235EF0(s32, s32);
extern void fn_802353F4(s32, s32, float, float, float);
extern void fn_8022BD40(int, void *, int, int, float, float, float, float, float, float, float, float);
#pragma scheduling invalid_target
void fn_80241820(void *arg0) {
    char *self = (char *)arg0;
    float sx, sy;
    if (*(int *)(self + 0x28) != 0 && ((Fn241820Obj *)self)->vt->isActive(self) != 0) {
        float k255, k03, k07, zero, one, half, w, h, cw, base;
        float t, c, f4c;
        int i;
        fn_80230C30(&sx, &sy, *(int *)(self + 0x14), *(int *)(self + 0x18));
        w = (float)*(int *)(self + 0x1c);
        h = (float)*(int *)(self + 0x20);
        cw = w / lbl_80563780;
        t = (float)((int)(lbl_80563768 * fn_8023659C()) - *(int *)(self + 0x48)) / lbl_8056376C;
        t = (lbl_80563764 < t) ? lbl_80563764 : t;
        t = (t > lbl_80563758) ? t : lbl_80563758;
        c = (t < lbl_80563770) ? lbl_80563770 : ((t > lbl_80563764) ? lbl_80563764 : ((t > lbl_80563758) ? (t * ((lbl_80563774 * t) * t) + (lbl_80563778 * t) * t) : (t * ((lbl_80563774 * t) * t) - (lbl_80563778 * t) * t)));
        f4c = *(float *)(self + 0x4c);
        half = lbl_80563784;
        zero = lbl_80563758;
        one = lbl_80563764;
        k07 = lbl_8056378C;
        k03 = lbl_80563788;
        k255 = lbl_80563790;
        base = ((sx + w * half) - cw * half) - cw * (f4c + c * (*(float *)(self + 0x50) - f4c));
        for (i = 0; i < *(int *)(*(char **)(self + 0x28) + 0x98); i++) {
            float x = base + (float)i * cw;
            if (x + cw > sx && x < sx + w) {
                unsigned col, white;
                int a;
                float v;
                v = (x + cw * half) - sx;
                if (v > w * half) v = w - v;
                v = (v - zero) / (w * half - zero);
                if (one < v) v = one;
                v = (v > zero) ? v : zero;
                a = (int)(k255 * (k03 + v * k07));
                col = *(unsigned *)(*(char **)(self + 0x28) + i * 4 + 0x64);
                white = (a << 24) | 0xFFFFFF;
                col = (col & 0xFFFFFF) | (a << 24);
                if (x > sx && x + cw < sx + w) {
                    fn_802354A0(*(int *)(self + 0x44), 3, col, x, sy, lbl_80563758, cw, h);
                    fn_802354A0(*(int *)(self + 0x44), 6, white, x, sy, lbl_80563758, cw, h);
                } else if (x > sx) {
                    float p = cw - ((x + cw) - (sx + w));
                    float q = p / cw;
                    fn_80235758(*(int *)(self + 0x44), 3, col, x, sy, p, h, lbl_80563758, lbl_80563758, q, lbl_80563764);
                    fn_80235758(*(int *)(self + 0x44), 6, white, x, sy, p, h, lbl_80563758, lbl_80563758, q, lbl_80563764);
                } else {
                    float p = cw - (sx - x);
                    float q = (cw - p) / cw;
                    fn_80235758(*(int *)(self + 0x44), 3, col, sx, sy, p, h, q, lbl_80563758, lbl_80563764, lbl_80563764);
                    fn_80235758(*(int *)(self + 0x44), 6, white, sx, sy, p, h, q, lbl_80563758, lbl_80563764, lbl_80563764);
                }
            }
        }
        if (((Fn241820Obj *)self)->vt->isActive(self) != 0) {
            if (*(int *)(self + 0x2c) > 0) {
                s32 o = fn_80211660(0);
                float k = (h - fn_80235F64(o, 1)) * lbl_80563784;
                float m = lbl_80563794 + *(float *)(self + 0x54);
                fn_802353F4(o, 1, (sx - fn_80235EF0(o, 1)) - m, sy - k, lbl_80563758);
            }
            if (*(int *)(self + 0x2c) < *(int *)(*(char **)self + 0x28) + 0x98 == 0) {}
            if (*(int *)(self + 0x2c) < *(int *)(*(char **)(self + 0x28) + 0x98) - 1) {
                s32 o = fn_80211660(1);
                float k = (h - fn_80235F64(o, 1)) * lbl_80563784;
                fn_802353F4(o, 1, (lbl_80563794 + *(float *)(self + 0x58)) + (sx + w), sy - k, lbl_80563758);
            }
            {
                float a = *(float *)(self + 0x54) - lbl_80563764;
                float b;
                *(float *)(self + 0x54) = (lbl_80563758 > a) ? lbl_80563758 : a;
                b = *(float *)(self + 0x58) - lbl_80563764;
                *(float *)(self + 0x58) = (lbl_80563758 > b) ? lbl_80563758 : b;
            }
        }
    } else {
        float x = (float)*(int *)(self + 0x14);
        float y = (float)*(int *)(self + 0x18);
        float w = (float)*(int *)(self + 0x1c);
        float h = (float)*(int *)(self + 0x20);
        fn_8022BD40(0xCC, self + 0x5C, 0, 0, x + lbl_80563784 * w, y + lbl_80563784 * h, lbl_80563758, w, h, lbl_80563764, x, y);
    }
}

#pragma push
#pragma scheduling invalid_target
/* Refresh every entry of a selection menu: for each of the count (+0x2C) item
 * pointers in the array at +0x18, store whether that row is the selected one
 * (menu enabled at +0x38 and this index == the selected index at +0x30) into the
 * item's flag byte at +0, and the value the menu follows (*+0x34) into its word
 * at +4. Same refresh as MRollMenuItem_addEntry, without appending an entry first. */
void fn_80241DE8(void *menu) {
    void *item;
    s32 index;
    s32 value;
    char *entryCursor = (char *)menu;
    s32 isSelected;

    for (index = 0; index < *(s32 *)((char *)menu + 0x2C);) {
        value = **(s32 **)((char *)menu + 0x34);
        isSelected = *(u8 *)((char *)menu + 0x38) != 0 && index == *(s32 *)((char *)menu + 0x30);
        item = *(void **)(entryCursor + 0x18);
        entryCursor += 4;
        index++;
        *(u8 *)item = isSelected;
        *(s32 *)((char *)item + 4) = value;
    }
}
#pragma pop
/* If the menu is enabled and its followed value (*+0x34) matches the current input nibble, refresh every entry as fn_80241DE8 does and return 1; otherwise return 0. */ s32 fn_80241E40(void *arg0) {
    /* If active and synced with the current selection value, write selection/value to each output entry and return 1; otherwise return 0. */
    s32 index;
    s32 isSelected;
    void *item;
    s32 value;
    void *entryCursor;

    if (*(s32 *)*(s32 **)((char *)arg0 + 0x34) == fn_802E4A10()) {
        if (*(u8 *)((char *)arg0 + 0x38) != 0)
            goto do_loop;
    }
    return 0;

do_loop:
    entryCursor = arg0;
    index = 0;
    while (index < *(s32 *)((char *)arg0 + 0x2C)) {
        value = *(s32 *)*(s32 **)((char *)arg0 + 0x34);
        isSelected = (*(u8 *)((char *)arg0 + 0x38) != 0 && index == *(s32 *)((char *)arg0 + 0x30)) ? 1 : 0;
        item = *(void **)((char *)entryCursor + 0x18);
        entryCursor = (char *)entryCursor + 4;
        ++index;
        *(u8 *)item = isSelected;
        *(s32 *)((char *)item + 4) = value;
    }
    return 1;
}
#pragma scheduling on
s32 fn_80241EE8(s32 base) {
#define RECORD_NAME_FIELD_OFFSET 0x4C
    /* Field accessor: offset a UI entry base to its record-name field (record+0xC is copied here). */
    return base + RECORD_NAME_FIELD_OFFSET;
}

#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
struct Pair8_80241EF0 {
    s32 a, b;
};
struct Info2C_80241EF0 {
    s32 header;
    Pair8_80241EF0 pairs[5];
};
struct Collection_80241EF0 {
    virtual s32 f0() = 0;
    virtual s32 f1() = 0;
    virtual s32 f2() = 0;
    virtual s32 getCount() = 0;
    virtual void *getItem(s32) = 0;
    virtual s32 getResult(s32) = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void draw(s32, void *, void *) = 0;
};
struct CtxObj_80241EF0 {
    u8 pad00[0x28];
    void *record;
    s32 idx;
    s32 *field30;
    void **field34;
    void *field38;
    s32 field3C;
    u8 pad40[8];
    s32 field48;
    float field4C;
    float field50;
    u8 pad54[8];
    char name5C[0x40];
};
struct InfoDstObj_80241EF0 {
    Info2C_80241EF0 info;
    u8 widgets[5][0x28];
    char texts[5][0x64];
    u8 tail2E8[4];
};
extern "C" void *fn_8001668C(void *, s32);
extern "C" void *fn_80016BC8(void *, s32);
extern "C" void *fn_80018A8C(void *, s32, s32 *, s32);
extern "C" s32 fn_80255918(void *, void *);
extern "C" char lbl_8034287C[];
static inline void updateCtx_80241EF0(CtxObj_80241EF0 *ctx, void *record) {
    if (ctx->record != 0) {
        s32 savedIdx = ctx->idx;
        void *sub = fn_80016BC8(ctx->record, ctx->field3C);
        *(s32 *)((u8 *)sub + 4) = savedIdx;
    }
    ctx->record = record;
    s32 curIdx = ctx->idx;
    if (*(s32 *)((u8 *)record + 0x98) - 1 < curIdx) {
        curIdx = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    ctx->idx = curIdx;

    s32 idx = *(s32 *)((u8 *)fn_80016BC8(ctx->record, ctx->field3C) + 4);
    ctx->idx = idx;
    ctx->name5C[0] = 0;
    if (idx >= 0 && idx < *(s32 *)((u8 *)ctx->record + 0x98)) {
        void *val = *(void **)((u8 *)ctx->record + 0x64 + idx * 4);
        *ctx->field34 = val;
        fn_80255918(ctx->field38, val);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            ctx->name5C, 0x40, lbl_8034287C,
            ctx->idx + 1);
        {
            char *src = (char *)fn_80131234((s32 *)ctx->name5C);
            char *dst = ctx->name5C;
            s32 n = 0x40;
            while ((*dst++ = *src++) != 0) {
                if (--n <= 0) {
                    dst[-1] = 0;
                    break;
                }
            }
        }
    }

    *ctx->field30 = ctx->idx;
    ctx->field48 = -0xFA;
    ctx->field4C = (float)ctx->idx;
    ctx->field50 = (float)ctx->idx;
}
static inline void updateInfoDst_80241EF0(InfoDstObj_80241EF0 *infoDst, char *name2C) {
    void *info = ((void *(*)(void *))fn_80018A8C)(name2C);
    if (info != 0) {
        infoDst->info = *(Info2C_80241EF0 *)info;

        for (s32 i = 0; i < 5; i++) {
            char *src = (char *)infoDst->info.pairs[i].a;
            if (src != 0) {
                char *dst = infoDst->texts[i];
                s32 n = 0x64;
                while ((*dst++ = *src++) != 0) {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                }
            } else {
                infoDst->texts[i][0] = 0;
            }
            ((Collection_80241EF0 *)infoDst->widgets[i])->draw(i, &infoDst->info.pairs[i].b, infoDst->tail2E8);
        }
    } else {
        memset(infoDst, 0, 0x2C);
        infoDst->texts[0][0] = 0;
        infoDst->texts[1][0] = 0;
        infoDst->texts[2][0] = 0;
        infoDst->texts[3][0] = 0;
        infoDst->texts[4][0] = 0;
    }
}
extern "C" void fn_80241EF0(void *arg0, s32 arg1) {
    struct SelfObj {
        u8 pad00[0x10];
        s32 *field10;
        s32 *field14;
        CtxObj_80241EF0 *ctx;
        InfoDstObj_80241EF0 *infoDst;
        u8 *field20;
        Collection_80241EF0 *col;
        s32 index;
        char name2C[0x20];
        char name4C[0x20];
        s32 result;
    };
    SelfObj *self = (SelfObj *)arg0;

    self->index++;
    if (self->index >= self->col->getCount()) {
        self->index = 0;
    }
    if (self->index < 0) return;
    if (self->index >= self->col->getCount()) return;
    struct PtrHolder { void *p; } ih;
    ih.p = self->col->getItem(self->index);
    void *item = ih.p;
    void *record = fn_8001668C(item, 0);
    *self->field14 = *(s32 *)((u8 *)record + 4);
    *self->field10 = *(s32 *)((u8 *)record + 0x9C);

    {
        s32 n = 0x20;
        char *dst = self->name2C;
        char *src = (char *)item;
        while ((*dst++ = *src++) != 0) {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    }

    {
        char *src = (char *)record + 0xC;
        s32 n = 0x20;
        char *dst = self->name4C;
        while ((*dst++ = *src++) != 0) {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    }

    self->result = self->col->getResult(self->index);
    *(bool *)(self->field20 + 0xDD) = (self->result == 0);

    updateCtx_80241EF0(self->ctx, record);
    updateInfoDst_80241EF0(self->infoDst, self->name2C);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma cplusplus reset

extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_802422DC(void *arg0, s32 arg1) {
    s32 index, result, i, n, wordA, wordB;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
    register char *src, *dst;
    char *entries, *output, *zeroBase, *textItem, *object;
    char c;
    struct Collection {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual void *getItem(s32) = 0;
        virtual s32 getResult(s32) = 0;
        virtual void f8() = 0;
        virtual void f9() = 0;
        virtual void f10() = 0;
        virtual void f11() = 0;
        virtual void f12() = 0;
        virtual void f13() = 0;
        virtual void f14() = 0;
        virtual void f15() = 0;
        virtual void f16() = 0;
        virtual void f17() = 0;
        virtual void f18() = 0;
        virtual void f19() = 0;
        virtual void f20() = 0;
        virtual void f21() = 0;
        virtual void f22() = 0;
        virtual void f23() = 0;
        virtual void draw(s32, void *, void *) = 0;
    };

    index = *(s32 *)((u8 *)arg0 + 0x28) - 1;
    *(s32 *)((u8 *)arg0 + 0x28) = index;
    if (index < 0) {
        index = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount() - 1;
        *(s32 *)((u8 *)arg0 + 0x28) = index;
    }
    index = *(s32 *)((u8 *)arg0 + 0x28);
    if (index < 0) return;
    if (index >= ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount()) return;
    item = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getItem(index);
    record = fn_8001668C(item, 0);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x14)) = *(s32 *)((u8 *)record + 4);
    *(s32 *)(*(void **)((u8 *)arg0 + 0x10)) = *(s32 *)((u8 *)record + 0x9C);

    dst = (char *)arg0 + 0x2C;
    src = (char *)item;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    src = (char *)record + 0xC;
    dst = (char *)arg0 + 0x4C;
    n = 0x20;
    do {
        if (--n <= 0) {
            dst[-1] = 0;
            break;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);

    result = ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getResult(*(s32 *)((u8 *)arg0 + 0x28));
    *(s32 *)((u8 *)arg0 + 0x6C) = result;
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0xDD) = (result == 0);

    ctx = *(void **)((u8 *)arg0 + 0x18);
    if (*(void **)((u8 *)ctx + 0x28) != 0) {
        index = *(s32 *)((u8 *)ctx + 0x2C);
        item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
        *(s32 *)((u8 *)item + 4) = index;
    }
    *(void **)((u8 *)ctx + 0x28) = record;
    index = *(s32 *)((u8 *)ctx + 0x2C);
    if (*(s32 *)((u8 *)record + 0x98) - 1 < index) {
        index = *(s32 *)((u8 *)record + 0x98) - 1;
    }
    *(s32 *)((u8 *)ctx + 0x2C) = index;

    item = fn_80016BC8(*(void **)((u8 *)ctx + 0x28), *(s32 *)((u8 *)ctx + 0x3C));
    index = *(s32 *)((u8 *)item + 4);
    *(s32 *)((u8 *)ctx + 0x2C) = index;
    *(u8 *)((u8 *)ctx + 0x5C) = 0;
    if (index >= 0 && index < *(s32 *)((u8 *)*(void **)((u8 *)ctx + 0x28) + 0x98)) {
        item = *(void **)((u8 *)record + 0x64 + index * 4);
        *(void **)(*(void **)((u8 *)ctx + 0x34)) = item;
        fn_80255918(*(void **)((u8 *)ctx + 0x38), item);
        ((int (*)(void *, int, void *, ...))fn_801345D8)(
            (u8 *)ctx + 0x5C, 0x40, lbl_8034287C,
            *(s32 *)((u8 *)ctx + 0x2C) + 1);
        src = (char *)fn_80131234((u8 *)ctx + 0x5C);
        dst = (char *)ctx + 0x5C;
        n = 0x40;
        do {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
        } while (c != 0);
    }

    *(s32 *)(*(void **)((u8 *)ctx + 0x30)) = *(s32 *)((u8 *)ctx + 0x2C);
    *(s32 *)((u8 *)ctx + 0x48) = -0xFA;
    *(float *)((u8 *)ctx + 0x4C) = (float)*(s32 *)((u8 *)ctx + 0x2C);
    *(float *)((u8 *)ctx + 0x50) = (float)*(s32 *)((u8 *)ctx + 0x2C);

    infoDst = *(void **)((u8 *)arg0 + 0x1C);
    info = fn_80018A8C((u8 *)arg0 + 0x2C, *(s32 *)((u8 *)ctx + 0x2C),
                       (s32 *)*(void **)((u8 *)ctx + 0x30),
                       *(s32 *)((u8 *)ctx + 0x2C));
    if (info != 0) {
        ((s32 *)infoDst)[0] = ((s32 *)info)[0];
        wordA = ((s32 *)info)[2];
        wordB = ((s32 *)info)[1];
        ((s32 *)infoDst)[1] = wordB;
        ((s32 *)infoDst)[2] = wordA;
        wordA = ((s32 *)info)[4];
        wordB = ((s32 *)info)[3];
        ((s32 *)infoDst)[3] = wordB;
        ((s32 *)infoDst)[4] = wordA;
        wordA = ((s32 *)info)[6];
        wordB = ((s32 *)info)[5];
        ((s32 *)infoDst)[5] = wordB;
        ((s32 *)infoDst)[6] = wordA;
        wordA = ((s32 *)info)[8];
        wordB = ((s32 *)info)[7];
        ((s32 *)infoDst)[7] = wordB;
        ((s32 *)infoDst)[8] = wordA;
        wordA = ((s32 *)info)[10];
        wordB = ((s32 *)info)[9];
        ((s32 *)infoDst)[9] = wordB;
        ((s32 *)infoDst)[10] = wordA;

        entries = (char *)infoDst;
        zeroBase = (char *)infoDst;
        output = (char *)infoDst + 0xF4;
        textItem = (char *)infoDst + 8;
        object = (char *)infoDst + 0x2C;
        i = 0;
        do {
            src = *(char **)(entries + 4);
            if (src != 0) {
                dst = output;
                n = 0x64;
                do {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                    c = *src++;
                    *dst++ = c;
                } while (c != 0);
            } else {
                *(u8 *)(zeroBase + 0xF4) = 0;
            }
            ((Collection *)object)->draw(i, textItem, (u8 *)infoDst + 0x2E8);
            entries += 8;
            zeroBase += 0x64;
            output += 0x64;
            textItem += 8;
            object += 0x28;
            i++;
        } while (i < 5);
    } else {
        memset(infoDst, 0, 0x2C);
        *(u8 *)((u8 *)infoDst + 0xF4) = 0;
        *(u8 *)((u8 *)infoDst + 0x158) = 0;
        *(u8 *)((u8 *)infoDst + 0x1BC) = 0;
        *(u8 *)((u8 *)infoDst + 0x220) = 0;
        *(u8 *)((u8 *)infoDst + 0x284) = 0;
    }
}
#pragma cplusplus on
/* Returns the item at the object's current index (+0x28) from the collection at
   +0x24, or 0 if the index is negative or out of range. */
extern "C" s32 getCurrentCollectionItem(void *self) {
    /* Return the item at the object's current index in its collection, or 0 when out of range. */
    struct Collection {
        virtual s32 reserved0() = 0;
        virtual s32 reserved1() = 0;
        virtual s32 reserved2() = 0;
        virtual s32 getCount() = 0;
        virtual s32 reserved4() = 0;
        virtual s32 getItem(s32) = 0;
    };
    s32 index = *(s32 *)((u8 *)self + 0x28);
    Collection *collection;
    if (index >= 0) {
        collection = *(Collection **)((u8 *)self + 0x24);
        if (index < collection->getCount()) {
            collection = *(Collection **)((u8 *)self + 0x24);
            return collection->getItem(index);
        }
    }
    return 0;
}
#pragma cplusplus off
extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_802E317C(char *, ...);
extern u8 *fn_802E85B8(s32);
extern char lbl_80342840[];
extern char lbl_8055BD60;
#pragma push
#pragma use_lmw_stmw off
void fn_80242738(void *arg0, s32 arg1)
{
  unsigned refreshIndex;
  s32 outer;
  s32 i;
  s32 n;
  s32 selected;
  s32 selectedValue;
  s32 current;
  s32 previous;
  s32 modeA;
  s32 modeB;
  s32 mode;
  u8 *base;
  u8 *widget;
  u8 *entry;
  u8 *child;
  u8 *list;
  signed char c;
  u8 *src;
  u8 *dst;
  *((volatile u8 *) (&lbl_8055F1FC)) = 0;
  base = (u8 *) arg0;
  outer = 0;
  do
  {
    widget = *((u8 **) (base + 0x18));
    *(*((s32 **) (widget + 0x34))) = outer;
    *((s32 *) ((*((u8 **) (widget + 0x28))) + 0xD8)) = *(*((s32 **) (widget + 0x34)));
    selected = *(*((s32 **) (widget + 0x34)));
    if (0 > selected)
    {
      src = (u8 *) (&lbl_8055BD60);
      dst = widget + 0x39;
      n = 0x20;
      goto copy_check0;
      copy_check_loop0:
      --n;

      if (n > 0)
      {
        goto copy_check0;
      }
      dst[-1] = 0;
      goto copy_done0;
      copy_check0:
      c = *(src++);

      *(dst++) = (u8) c;
      if (c != 0)
      {
        goto copy_check_loop0;
      }
      copy_done0:
      ;

      ;
      child = *((u8 **) (entry + 0x18));
    }
    else
    {
      src = fn_802E85B8(selected);
      dst = widget + 0x39;
      n = 0x20;
      goto copy_check1;
      copy_check_loop1:
      --n;

      if (n > 0)
      {
        goto copy_check1;
      }
      dst[-1] = 0;
      goto copy_done1;
      copy_check1:
      c = *(src++);

      *(dst++) = (u8) c;
      if (c != 0)
      {
        goto copy_check_loop1;
      }
      copy_done1:
      ;

      ;
    }
    entry = widget;
    i = 0;
    goto init_child_check;
    init_child_body:
    selectedValue = *(*((s32 **) (widget + 0x34)));

    n = ((*((u8 *) (widget + 0x38))) != 0) && (i == (*((s32 *) (widget + 0x30))));
    child = *((u8 **) (entry + 0x18));
    *((u8 *) child) = (u8) n;
    *((s32 *) (child + 4)) = selectedValue;
    entry += 4;
    i += 1;
    init_child_check:
    if (i < (*((volatile s32 *) (widget + 0x2C))))
    {
      goto init_child_body;
    }

    *((s32 *) (base + 0x34)) = 2;
    outer += 1;
    base += 0x20;
  }
  while (outer < 2);
  *((u8 *) (((u8 *) arg0) + 0x58)) = 0;
  child = (u8 *) arg0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (child + 0x50)) = 0;
  modeA = *((s32 *) (((u8 *) arg0) + 0x34));
  selected = 0;
  mode = 0;
  if (modeA <= 1)
  {
    goto mode_a_ok;
  }
  if (modeA == 4)
  {
    goto mode_a_ok;
  }
  mode = 0;
  goto mode_done;
  mode_a_ok:
  if (modeA == 4)
  {
    selected = 1;
  }

  modeB = *((s32 *) (((u8 *) arg0) + 0x54));
  if (modeB <= 1)
  {
    goto mode_b_ok;
  }
  if (modeB == 4)
  {
    goto mode_b_ok;
  }
  mode = 0;
  goto mode_done;
  mode_b_ok:
  if (modeB == 4)
  {
    selected++;
  }

  mode = selected >= 2;
  mode_done:
  if ((*((u8 *) (((u8 *) arg0) + 0x58))) != ((unsigned) mode))
  {
    *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
    *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  }

  base = ((u8 *) arg0) + 0x18;
  for (refreshIndex = 0; refreshIndex < 2U; refreshIndex++, base += 0x20)
  {
    current = *((s32 *) (base + 0x1C));
    previous = *((s32 *) (base + 0x18));
    if (current != previous)
    {
      switch (current)
      {
        case 0:
          break;

        case 1:
          fn_80214AF0(*((s32 *) (base + 4)));
          fn_80214A9C(*((s32 *) (base + 8)));
          fn_80214A9C(*((s32 *) (base + 0x0C)));
          break;

        case 2:

        case 3:
          fn_80214A9C(*((s32 *) (base + 4)));
          fn_80214AF0(*((s32 *) (base + 8)));
          fn_80214A9C(*((s32 *) (base + 0x0C)));
          fn_80214AF0(*((s32 *) (base + 0x14)));
          if ((refreshIndex != 0) && ((*((s32 *) (base + ((s32) 0x1C)))) == 2))
        {
          fn_80214A9C(*((s32 *) (base + 0x10)));
        }
        else
        {
          fn_80214AF0(*((s32 *) (base + 0x10)));
        }
          list = *((u8 **) base);
          *((u8 *) (list + 0x38)) = 1;
          entry = list;
          i = 0;
          goto on_child_check;
          on_child_body:
        selectedValue = *(*((s32 **) (list + 0x34)));

          n = ((*((u8 *) (list + 0x38))) != 0) && (i == (*((s32 *) (list + 0x30))));
          child = *((u8 **) (entry + 0x18));
          *((u8 *) child) = (u8) n;
          *((s32 *) (child + 4)) = selectedValue;
          entry += 4;
          i++;
          on_child_check:
        if (i < (*((volatile s32 *) (list + 0x2C))))
        {
          goto on_child_body;
        }

          break;

        case 4:
          fn_80214A9C(*((s32 *) (base + 4)));
          fn_80214AF0(*((s32 *) (base + 8)));
          fn_80214AF0(*((s32 *) (base + 0x0C)));
          fn_80214A9C(*((s32 *) (base + 0x14)));
          fn_80214AF0(*((s32 *) (base + 0x10)));
          list = *((u8 **) base);
          *((u8 *) (list + 0x38)) = 0;
          entry = list;
          i = 0;
          goto off_child_check;
          off_child_body:
        selectedValue = *(*((s32 **) (list + 0x34)));

          n = ((*((u8 *) (list + 0x38))) != 0) && (i == (*((s32 *) (list + 0x30))));
          child = *((u8 **) (entry + 0x18));
          *((u8 *) child) = (u8) n;
          *((s32 *) (child + 4)) = selectedValue;
          entry += 4;
          i++;
          off_child_check:
        if (i < (*((volatile s32 *) (list + 0x2C))))
        {
          goto off_child_body;
        }

          break;

        default:
          fn_802E317C(lbl_80342840, 0, refreshIndex);
          break;

      }

      *((s32 *) (base + 0x18)) = *((s32 *) (base + 0x1C));
    }
  }

  ((mode != 0) ? (fn_80214AF0) : (fn_80214A9C))(0x1E);
  if (mode != 0)
  {
    for (i = 7; i <= 0xA; i++)
    {
      fn_80214A9C(i);
    }

  }
  *((u8 *) (((u8 *) arg0) + 0x58)) = (u8) mode;
}
#pragma pop
extern s32 lbl_8055F1F8;
extern s32 fn_802E8504(s32);
#pragma cplusplus on
extern "C" s32 lbl_8055F1F8;
extern "C" s32 fn_802E8504(s32);
extern "C" u8 *fn_802E85B8(s32);
extern "C" void fn_80214A9C(s32);
extern "C" void fn_80214AF0(s32);
extern "C" void fn_802E317C(char *, ...);
#pragma optimize_for_size off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80242B1C(void *arg0) {
    register unsigned refreshIndex;
    s32 mode;
    s32 i, selected, selectedValue, current, previous;
    s32 modeA, modeB;
    s32 tick, quotient;
    u8 *loopBase, *base, *slot, *widget, *entry, *child, *list;
    unsigned outer;
    int c;
    u8 *src;
    s32 n;
    u8 *dst;

    tick = lbl_8055F1F8 + 1;
    lbl_8055F1F8 = tick;
    if (tick - (tick / 10) * 10 == 0) {
        base = (u8 *)arg0;
        slot = base + 0x18;
        outer = 0;
        do {
            if (*(s32 *)(base + 0x34) > 1 &&
                fn_802E8504(**(s32 **)(*(u8 **)(base + 0x18) + 0x34)) == 0) {
                widget = *(u8 **)slot;
                **(s32 **)(widget + 0x34) = -1;
                *(s32 *)(*(u8 **)(widget + 0x28) + 0xD8) =
                    **(s32 **)(widget + 0x34);

#pragma optimize_for_size on
                selected = **(s32 **)(widget + 0x34);
                if (0 > selected) {
                    src = (u8 *)&lbl_8055BD60;
                    dst = widget + 0x39;
                    n = 0x20;
                    goto copy_check0;
copy_check_loop0:
                    --n;
                    if (n > 0) goto copy_check0;
                    dst[-1] = 0;
                    goto copy_done0;
copy_check0:
                    c = (signed char)*src++;
                    *dst++ = (u8)c;
                    if (c != 0) goto copy_check_loop0;
copy_done0:;
                } else {
                    src = fn_802E85B8(selected);
                    n = 0x20;
                    dst = widget + 0x39;
                    goto copy_check1;
copy_check_loop1:
                    --n;
                    if (n > 0) goto copy_check1;
                    dst[-1] = 0;
                    goto copy_done1;
copy_check1:
                    c = (signed char)*src++;
                    *dst++ = (u8)c;
                    if (c != 0) goto copy_check_loop1;
copy_done1:;
                }

#pragma optimize_for_size off
                entry = widget;
                i = 0;
                goto init_child_check;
init_child_body:
                register selectedValue = **(s32 **)(widget + 0x34);
                n = (*(u8 *)(widget + 0x38) != 0 &&
                     i == *(s32 *)(widget + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i += 1;
init_child_check:
                if (i < *(volatile s32 *)(widget + 0x2C)) goto init_child_body;
                *(s32 *)(slot + (int)0x1C) = 1;
            }
            outer += 1;
            base += 0x20;
            slot += 0x20;
        } while (outer < 2U);
    }

#pragma optimize_for_size on
    modeA = *(s32 *)((u8 *)arg0 + 0x34);
    selected = 0;
    mode = 0;
    if (modeA <= 1) goto mode_a_ok;
    if (modeA == 4) goto mode_a_ok;
    mode = 0;
    goto mode_done;
mode_a_ok:
    if (modeA == 4) selected = 1;
    modeB = *(s32 *)((u8 *)arg0 + 0x54);
    if (modeB <= 1) goto mode_b_ok;
    if (modeB == 4) goto mode_b_ok;
    mode = 0;
    goto mode_done;
mode_b_ok:
    if (modeB == 4) selected++;
    mode = selected >= 2;
mode_done:
#pragma optimize_for_size off
    if (*(u8 *)((u8 *)arg0 + 0x58) != (unsigned)mode) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0;
        *(s32 *)((u8 *)arg0 + 0x50) = 0;
    }

    loopBase = (u8 *)arg0 + 0x18;
    for (refreshIndex = 0; refreshIndex < 2U; refreshIndex++, loopBase += 0x20) {
        current = *(s32 *)(loopBase + 0x1C);
        previous = *(s32 *)(loopBase + 0x18);
        if (current != previous) {
            switch (current) {
            case 0:
                break;
            case 1:
                fn_80214AF0(*(s32 *)(loopBase + 4));
                fn_80214A9C(*(s32 *)(loopBase + 8));
                fn_80214A9C(*(s32 *)(loopBase + 0x0C));
                break;
            case 2:
            case 3:
                fn_80214A9C(*(s32 *)(loopBase + 4));
                fn_80214AF0(*(s32 *)(loopBase + 8));
                fn_80214A9C(*(s32 *)(loopBase + 0x0C));
                fn_80214AF0(*(s32 *)(loopBase + 0x14));
                if (refreshIndex != 0 && *(s32 *)(loopBase + (s32)0x1C) == 2) {
                    fn_80214A9C(*(s32 *)(loopBase + 0x10));
                } else {
                    fn_80214AF0(*(s32 *)(loopBase + 0x10));
                }
                list = *(u8 **)loopBase;
                *(u8 *)(list + 0x38) = 1;
                entry = list;
                i = 0;
                goto on_child_check;
on_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 &&
                     i == *(s32 *)(list + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
on_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto on_child_body;
                break;
            case 4:
                fn_80214A9C(*(s32 *)(loopBase + 4));
                fn_80214AF0(*(s32 *)(loopBase + 8));
                fn_80214AF0(*(s32 *)(loopBase + 0x0C));
                fn_80214A9C(*(s32 *)(loopBase + 0x14));
                fn_80214AF0(*(s32 *)(loopBase + 0x10));
                list = *(u8 **)loopBase;
                *(u8 *)(list + 0x38) = 0;
                entry = list;
                i = 0;
                goto off_child_check;
off_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 &&
                     i == *(s32 *)(list + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
off_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto off_child_body;
                break;
            default:
                fn_802E317C(lbl_80342840, 0, refreshIndex);
                break;
            }
            *(s32 *)(loopBase + 0x18) = *(s32 *)(loopBase + 0x1C);
        }
    }

    (mode != 0 ? fn_80214AF0 : fn_80214A9C)(0x1E);
    if (mode != 0) {
        for (i = 7; i <= 0xA; i++) {
            fn_80214A9C(i);
        }
    }
    *(u8 *)((u8 *)arg0 + 0x58) = (u8)mode;
    if (fn_802411D4() == 0) {
        lbl_8055F1FC = 1;
        lbl_8055F200 = 0;
    }
}
#pragma cplusplus reset
#pragma use_lmw_stmw off
s32 fn_80242F68(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    s32 channel = fn_802E4A10();
    s32 active, selected, i, state0, pp, eq, cond;
    s32 modeB, mode, cntSel, ret;
    u8 *slot;
    if (channel >= 2) return 0;
    slot = base + channel * 0x20;
    state0 = *(s32 *)(slot + 0x34);
    pp = **(s32 **)(*(u8 **)(slot + 0x18) + 0x34);
    eq = (channel == pp);
    cond = 0;
    if (state0 > 1 && eq != 0) cond = 1;
    active = (cond != 0 ? channel : -1);
    selected = (*(s32 *)(slot + 0x34) == 1 ? channel : -1);
    switch (arg1) {
    case 0x1B:
        if (active >= 0) {
            slot = base + active * 0x20;
            *(s32 *)(slot + 0x34) -= 1;
            if (*(s32 *)(slot + 0x34) == 1) {
                if (active == 0) { lbl_8055F1FC = 1; lbl_8055F200 = 0; }
                else { fn_80216D28(); fn_80214D50(1); }
                *(s32 *)(slot + 0x34) = 2;
            }
            {
                u8 *obj = *(u8 **)(slot + 0x18);
                u8 *cur = obj;
                *(s32 *)(obj + 0x30) = (*(s32 *)(slot + 0x34) != 2);
                i = 0;
                goto upd_check0;
upd_body0:
                {
                    s32 v = **(s32 **)(obj + 0x34);
                    s32 sel = (*(u8 *)(obj + 0x38) != 0 && i == *(s32 *)(obj + 0x30)) ? 1 : 0;
                    void *e = *(void **)(cur + 0x18);
                    cur += 4; i++;
                    *(u8 *)e = (u8)sel;
                    *(s32 *)((u8 *)e + 4) = v;
                }
upd_check0:
                if (i < *(s32 *)(obj + 0x2C)) goto upd_body0;
            }
        } else { lbl_8055F1FC = 1; lbl_8055F200 = 0; }
        ret = 1; goto finish;
    case 0xD:
        {
            s32 v0 = *(s32 *)((u8 *)arg0 + 0x34);
            cntSel = 0; mode = 0;
            if (v0 <= 1) goto mode_a_ok;
            if (v0 == 4) goto mode_a_ok;
            mode = 0; goto mode_done;
mode_a_ok:
            if (v0 == 4) cntSel = 1;
            modeB = *(s32 *)((u8 *)arg0 + 0x54);
            if (modeB <= 1) goto mode_b_ok;
            if (modeB == 4) goto mode_b_ok;
            mode = 0; goto mode_done;
mode_b_ok:
            if (modeB == 4) cntSel++;
            mode = cntSel >= 2;
mode_done:;
            if (mode != 0) {
                if (channel == 0) { lbl_8055F1FC = 1; lbl_8055F200 = 2; }
                else { fn_80216D28(); fn_80214D50(1); }
                ret = 1; goto finish;
            }
        }
        if (active >= 0) {
            s32 cnt2 = 0;
            slot = base + active * 0x20;
            if (*(s32 *)(slot + 0x34) > 1 && *(s32 *)(slot + 0x34) != 4) cnt2++;
            if (*(s32 *)(slot + 0x34) > 1 && *(s32 *)(slot + 0x34) != 4) cnt2++;
            if (cnt2 <= 0) { ret = 0; goto finish; }
            if (*(s32 *)(slot + 0x34) > 1) {
                u8 *obj = *(u8 **)(slot + 0x18);
                if (*(u8 *)(obj + 0x38)) {
                    u8 *cur2 = obj; s32 idx = 0, done = 0;
                    while (idx < *(s32 *)(obj + 0x2C)) {
                        u8 *ee = *(u8 **)(cur2 + 0x18);
                        s32 (*fn)(void *) = ((s32 (**)(void *))(*(void **)((u8 *)ee + 0xC)))[5];
                        if (fn((void *)ee) == 0) { done = *(u8 *)(obj + 0x38); goto scan_done; }
                        cur2 += 4; idx++;
                    }
                    done = *(u8 *)(obj + 0x38);
scan_done:
                    if (done != 0) {
                        s32 ns = *(s32 *)(slot + 0x34) + 1;
                        u8 *cur3 = obj;
                        *(s32 *)(slot + 0x34) = ns;
                        *(s32 *)(obj + 0x30) = (ns != 2);
                        i = 0;
                        goto upd_check1;
upd_body1:
                        {
                            s32 v = **(s32 **)(obj + 0x34);
                            s32 sel = (*(u8 *)(obj + 0x38) != 0 && i == *(s32 *)(obj + 0x30)) ? 1 : 0;
                            void *e = *(void **)(cur3 + 0x18);
                            cur3 += 4; i++;
                            *(u8 *)e = (u8)sel;
                            *(s32 *)((u8 *)e + 4) = v;
                        }
upd_check1:
                        if (i < *(s32 *)(obj + 0x2C)) goto upd_body1;
                    }
                }
            }
        } else if (selected >= 0) {
            s32 off = selected << 5;
            u8 *obj = *(u8 **)((u8 *)arg0 + off + 0x18);
            u8 *dst, *src; s32 n; signed char c;
            **(s32 **)(obj + 0x34) = channel;
            *(s32 *)(*(u8 **)(obj + 0x28) + 0xD8) = **(s32 **)(obj + 0x34);
            if (**(s32 **)(obj + 0x34) < 0) {
                src = (u8 *)&lbl_8055BD60; dst = obj + 0x39; n = 0x20;
                goto copy_check0;
copy_loop0:
                --n; if (n > 0) goto copy_check0;
                dst[-1] = 0; goto copy_done0;
copy_check0:
                c = *src++; *dst++ = (u8)c;
                if (c != 0) goto copy_loop0;
copy_done0:;
            } else {
                src = fn_802E85B8(**(s32 **)(obj + 0x34)); dst = obj + 0x39; n = 0x20;
                goto copy_check1;
copy_loop1:
                --n; if (n > 0) goto copy_check1;
                dst[-1] = 0; goto copy_done1;
copy_check1:
                c = *src++; *dst++ = (u8)c;
                if (c != 0) goto copy_loop1;
copy_done1:;
            }
            {
                u8 *cur4 = obj; i = 0;
                goto upd_check2;
upd_body2:
                {
                    s32 v = **(s32 **)(obj + 0x34);
                    s32 sel = (*(u8 *)(obj + 0x38) != 0 && i == *(s32 *)(obj + 0x30)) ? 1 : 0;
                    void *e = *(void **)(cur4 + 0x18);
                    cur4 += 4; i++;
                    *(u8 *)e = (u8)sel;
                    *(s32 *)((u8 *)e + 4) = v;
                }
upd_check2:
                if (i < *(s32 *)(obj + 0x2C)) goto upd_body2;
            }
            *(s32 *)((u8 *)arg0 + off + 0x34) = 2;
        }
        ret = 1; goto finish;
    case 0x6F: ret = 1; goto finish;
    default: ret = 0; goto finish;
    }
finish:
    return ret;
}
