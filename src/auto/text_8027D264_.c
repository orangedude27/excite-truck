// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055C790;
extern void fn_8001D9B4(void *);
extern void *fn_8001285C(int);
extern void fn_80007FF0(int);
extern char lbl_80347DE8[];
extern int fn_80007F90(int);
extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_8000DBC8(void *);
extern char lbl_804B2FD8[];
extern void fn_8027D96C(int);
extern void fn_8027D9A4(int, int);
extern int fn_80128668(void);
extern int fn_8002F53C(void*, void*, void*, int, int);
extern void *__dt__Q34nw4r2ef6EffectFv_8027D434(void*, int);
extern void *fn_8027D674(void*);
extern void *fn_8027D504(void*);
extern void *fn_8027D304(void*, int);
extern void *fn_8027D39C(void *, int);
extern void fn_8027AF94(void*);
extern void fn_8001D868(int*);
extern char lbl_80347CA8[];
extern char lbl_80347CC0[];
extern char lbl_80347CF8[];
extern char lbl_804A4380[];
extern void *fn_8027B60C(void *);
extern void __array_delete(void *, void *, int, int);
extern void *fn_8027D280(void *, int);
extern int fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(int);
extern void fn_8027E0C8(void *, int);
extern unsigned char lbl_8055F66C;
extern void fn_8027B834(void);

/* Game modes: ids of the entries in the mode-info table at lbl_802FC638
 * (looked up by fn_800126CC; loaded by fn_80012790, unloaded by fn_80012794). */
#define MODE_ARCADE    0x12F
#define MODE_CAREER    0x130
#define MODE_MULTI     0x131
#define MODE_DEMO      0x132
#define MODE_CHALLENGE 0x133
#define MODE_NONE      0x134 /* no mode loaded; set by fn_80012794 (unload) */
#define gModeSwitchBusy lbl_8055F66C /* set while a task runs under a switched mode */
typedef struct Ent_8027DB40 { const char *name; int id; int val; } Ent_8027DB40;
typedef struct VTbl_8027DB40 { void *s[3]; void (*add)(void *, int, int, int); } VTbl_8027DB40;
typedef struct Obj_8027DB40 { VTbl_8027DB40 *vt; } Obj_8027DB40;
extern int fn_80019714(void);
extern int fn_80018FB4(void);
extern Ent_8027DB40 *fn_80019054(int);
extern int fn_80019088(void);
extern int fn_80016604(int);
extern int *fn_8001668C(int, int);
extern int fn_80018FA8(int);
extern int fn_80019144(int);
extern int fn_800194CC(void);
extern int fn_80019534(void);
extern int fn_80019604(void);
extern int fn_80019664(void);
extern int stricmp(const char *, const char *);
extern char lbl_8055C794[8];
void fn_8027DE68(void);
extern void *fn_8025007C(int);
extern void fn_8027B94C(void);
#pragma scheduling invalid_target
void fn_8027D264(void) {
    /* Tear down the array at lbl_804A4380: 4 player blocks of 0x3B10 bytes each, run through the per-block deleting destructor fn_8027D280 (MSL runtime array_delete). */
    __array_delete(lbl_804A4380, fn_8027D280, 0x3B10, 4);
}
#pragma scheduling on
/* Destroys two embedded element arrays (offset 0x2370, count 2, and base, count 3) and optionally frees the block. */
void *fn_8027D280(void *arg0, int arg1) {
    if (arg0 != 0) {
        __array_delete((char *)arg0 + 0x2370, fn_8027D304, 0xBD0, 2);
        __array_delete(arg0, fn_8027D304, 0xBD0, 3);
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma scheduling on
void *fn_8027D304(void *arg0, int arg1) {
    /* Destructor-like cleanup: set vtable, run base cleanup, destroy embedded subarray and list, optionally free. */
    struct Local {
        void *vtable;
        int field_04;
        int field_08;
        int field_0C;
        int field_10;
        int field_14;
    };
    struct Local *object = (struct Local *)arg0;
    if (arg0 != 0) {
        object->vtable = lbl_80347CA8;
        fn_8027B60C(object);
        if (&object->field_08 != 0) {
            __array_delete((char *)object + 0x14, fn_8027D39C, 0x1F4, 6);
            if (&object->field_08 != 0) {
                object->field_08 = 0;
                object->field_0C = 0;
                object->field_10 = 0;
            }
        }
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(object);
    }
    return object;
}

void fn_8027B288(void *);
/* Destructor-like: set vtable, tear down base/effects array at +0x18/+0x24, optionally delete, and return this. */
void *fn_8027D39C(void *thisPtr, int deleteFlags) {
    struct Local {
        void *vtable;
        char pad[0x14];
        int field_18;
        int field_1C;
        int field_20;
    };
    struct Local *obj = (struct Local *)thisPtr;
    if (thisPtr != 0) {
        obj->vtable = lbl_80347CC0;
        fn_8027B288(obj);
        if (&obj->field_18 != 0) {
            __array_delete((char *)obj + 0x24, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
            if (&obj->field_18 != 0) {
                obj->field_18 = 0;
                obj->field_1C = 0;
                obj->field_20 = 0;
            }
        }
        if (deleteFlags > 0) {
            ((void (*)(void *))fn_80128668)(obj);
        }
    }
    return obj;
}

/* Destroys this nw4r::ef::Effect instance and optionally frees its storage. */
void *__dt__Q34nw4r2ef6EffectFv_8027D434(void *this, int deleteFlag) {
    if (this) {
        *(void **)this = lbl_80347CF8;
        fn_8027AF94(this);
        if (deleteFlag > 0) ((void (*)(void *))fn_80128668)(this);
    }
    return this;
}

void *fn_8027D494(void *playerBlock) {
    /* Constructor of one player's 0x3B10-byte block in the global list array
     * lbl_804A4380 (4 blocks; the selected player's is at
     * lbl_804A4380 + fn_8000DA10() * 0x3B10): builds the block's 3 main lists at
     * +0 and its 2 secondary lists at +0x2370 -- five 0xBD0-byte lists in all.
     * Each list is built by fn_8027D504 (a header plus 6 inline 0x1F4-byte
     * entries, each holding 6 items) and destroyed by fn_8027D304.  The static
     * initializer fn_8027D204 runs this over the 4 blocks through fn_8002F53C,
     * the runtime's "construct an array of objects" helper; fn_8027D280 is this
     * block's matching destructor. */
#define ConstructArray fn_8002F53C /* runtime/array.s: ctor(elem, 1) per element */
#define ListCtor fn_8027D504
#define ListDtor fn_8027D304
#define LIST_SIZE 0xBD0 /* one list: header + 6 entries of 0x1F4 + tail */
    ConstructArray(playerBlock, ListCtor, ListDtor, LIST_SIZE, 3);
    ConstructArray((char *)playerBlock + 0x2370 /* past the 3 main lists */,
                   ListCtor, ListDtor, LIST_SIZE, 2);
#undef ConstructArray
#undef ListCtor
#undef ListDtor
#undef LIST_SIZE
    return playerBlock;
}

void *fn_8027D5B8(void *);
/* Construct an object with vtable lbl_80347CA8 and a 6-element inline array of
 * 0x1F4-byte entries at offset 0x14 (constructed with fn_8027D5B8, destroyed
 * with fn_8027D39C). */
void *fn_8027D504(void *arg0) {
    struct Object {
        void *vtable;
        int count;
        void *arrayBase;
        int arrayUsed;
        int arrayCapacity;
    };
    struct Object *obj = (struct Object *)arg0;
    obj->vtable = lbl_80347CA8;
    obj->count = 0;
    obj->arrayUsed = 0;
    obj->arrayBase = (char *)arg0 + (unsigned short)0x14;
    obj->arrayCapacity = 6;
    fn_8002F53C((char *)arg0 + 0x14, fn_8027D5B8, fn_8027D39C, 0x1F4, 6);
    return arg0;
}

int fn_8027D578(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma scheduling invalid_target
/* Default constructor for a 0x1F4-byte container entry (vtable lbl_80347CC0):
   initializes its 6-slot embedded array of 0x3C-byte elements at +0x24 and
   clears its active flag at +0x04. */
void *fn_8027D5B8(void *thisPtr) {
    int *elements;
    *(void **)thisPtr = lbl_80347CC0;
    elements = (int *)((char *)thisPtr + 0x24);
    *(int **)((char *)thisPtr + 0x18) = elements;
    *(int *)((char *)thisPtr + 0x20) = 6;
    *(int *)((char *)thisPtr + 0x1C) = 0;
    fn_8002F53C(elements, fn_8027D674, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
    *(char *)((char *)thisPtr + 4) = 0;
    return thisPtr;
}
#pragma scheduling on
int fn_8027D634(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Constructs an nw4r::ef::Effect object (vtable variant at lbl_80347CF8):
 * installs the vtable, clears the active flag at +0x04, and initializes the
 * embedded 5-entry data block at +0x14. */
void *fn_8027D674(void *effect)
{
    char *bytes = (char *)effect;
    *(void **)bytes = lbl_80347CF8;
    bytes[4] = 0;
    fn_8001D868((int *)(bytes + 0x14));
    return effect;
}

int fn_8027D6BC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma cplusplus on
extern "C" void fn_8027D6FC(void *__restrict arg0) {
#define getEntry fn_8001285C
#define getRecord fn_80012820
#define localize fn_80008188
#define kTrackFlagKey lbl_8055C77C
#define kTrackValueKey lbl_8055C774
    /* Choose the localized track/record name for a selection entry: ask the entry's
       property object (at +0x20) whether the "track" key exists; if so localize that
       key's value, otherwise localize the +8 field of the record named by entry+4. */
    class PropertyBag {
    public:
        virtual void unused0();
        virtual int hasKey(int key);
        virtual void unused2();
        virtual int getKey(int key);
    };
    struct SelectArgs { unsigned char pad[0xC]; int id; };
    int id = ((struct SelectArgs *)arg0)->id;
    void *entry = getEntry(id);
    void *props = *(void **)((char *)entry + 0x20);
    if (((PropertyBag *)props)->hasKey((int)&kTrackFlagKey) != 0) {
        props = *(void **)((char *)entry + 0x20);
        localize(((PropertyBag *)props)->getKey((int)&kTrackValueKey));
    } else {
        localize(getRecord(*(int *)((char *)entry + 4)) + 8);
    }
#undef kTrackValueKey
#undef kTrackFlagKey
#undef localize
#undef getRecord
#undef getEntry
}

#pragma cplusplus on
#pragma scheduling on
extern "C" void fn_8027D77C(void *__restrict arg0) {
    struct InArgs { unsigned char pad[0xC]; int id; };
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(int);
    };
    /* Look up the 0x28-byte state-table entry for the id carried in arg0, then
     * call the virtual handler stored at entry+0x20 with the "name" key. */
    int id = ((struct InArgs *)arg0)->id;
    void *entry = fn_8001285C(id);
    void *handler = *(void **)((char *)entry + 0x20);
    ((Obj *)handler)->v3((int)&lbl_8055C784);
}
#pragma scheduling invalid_target
extern "C" void fn_8027D7B8(const void *selection) {
    /* UI callback: read the contest id from selection+0xC, look up its 0x28-byte
     * contest entry, and pass the entry's event id (entry+8) to the event-name lookup. */
    int contestId = *(const int *)((const char *)selection + 0xC);
    fn_80007F90(*(int *)((char *)fn_8001285C(contestId) + 8));
}

#pragma push
#pragma processor 750
extern "C" void fn_8027D7E4(const void *arg0) {
    #define GetStateEntry fn_8001285C
    #define LookupEventTypeName fn_80007FF0
    /* Validate the event-type id stored at +8 of the per-slot state entry
     * selected by the id at arg0+0xC, by asking for its display name (logs if
     * unknown). */
    int entryId = *(const int *)((const char *)arg0 + 0xC);
    LookupEventTypeName(*(int *)((char *)GetStateEntry(entryId) + 8));
    #undef LookupEventTypeName
    #undef GetStateEntry
}
#pragma pop
extern "C" void fn_8027D810(void *__restrict arg0) {
    struct InArgs { unsigned char pad[0xC]; int id; };
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(int);
    };
    /* Look up the 0x28-byte state-table entry for the id carried in arg0, then
     * call the virtual handler stored at entry+0x20 with the "friendly_name"
     * string key (lbl_80347DE8). */
    int id = ((struct InArgs *)arg0)->id;
    void *entry = fn_8001285C(id);
    void *handler = *(void **)((char *)entry + 0x20);
    ((Obj *)handler)->v3((int)lbl_80347DE8);
}
#pragma cplusplus off
#pragma scheduling on
/* Getter, vtable slot 8 of the effect vtable lbl_80347CF8: the int at +0x34, the
 * value fn_8027D858 matches against the effect's five thresholds at +0x14 when
 * the valid flag at +0x38 is set. */
int fn_8027D850(void *effect) {
    return *(int *)((char *)effect + 0x34);
}
typedef int (*Fn8027D858)(void *, int);
#pragma cplusplus on
/* If obj's id-valid flag (byte at 0x38) is set, call the vtable's slot-0x30 method
 * with the id at 0x34 and return its result; otherwise return -1. */
extern "C" int fn_8027D858(void *obj) {
    class EffectObj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual int v10(int);
    };
    if (*(unsigned char *)((char *)obj + 0x38) != 0) {
        return ((EffectObj *)obj)->v10(*(int *)((char *)obj + 0x34));
    }
    return -1;
}
#pragma cplusplus off
/* Effect method: forward the embedded bounds array at +0x14 to fn_8001D9B4 (which resolves the first slot whose value is within the limit passed through in r4). */
void fn_8027D880(void *effect) {
    fn_8001D9B4((char *)effect + 0x14);
}

extern void fn_8001DA48(void *);
/* Effect method: index the embedded int array at +0x14 via fn_8001DA48
   (the index argument passes through unchanged in r4). */
void fn_8027D888(void *effect) {
    fn_8001DA48((char *)effect + 0x14);
}

/* Return the int field at offset 0xC of the nw4r::ef effect object. */
int fn_8027D890(void *effect) {
    return ((int *)effect)[3];
}

/* Return the int field at offset 0x30 of the nw4r::ef effect object. */
int fn_8027D898(void *effect) { return *(int *)((char *)effect + 0x30); }

/* Return the int field at offset 0x28 of the nw4r::ef effect object. */
int fn_8027D8A0(void *effect) {
    return *(int *)((char *)effect + 0x28);
}

#pragma cplusplus on
extern "C" void fn_8027D8A8(void *arg0) {
    /* Forward v12() result to fn_8001DA48 on the embedded object at +0x14. */
    class Obj {
    public:
        virtual void v0();
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
        virtual int v12();
    };
    int value = ((Obj *)arg0)->v12();
    ((int (*)(void *, int))fn_8001DA48)((char *)arg0 + 0x14, value);
}
#pragma cplusplus off
/* Return the int field at offset 0x2C of the nw4r::ef effect object. */
int fn_8027D8EC(void *effect) { return *(int *)((char *)effect + 0x2C); }

/* Return the int field at offset 0xC of the nw4r::ef effect object. */
int fn_8027D8F4(void *effect) {
    return ((int *)effect)[3];
}

/* Return the int field at offset 0x10 of the nw4r::ef effect object. */
int fn_8027D8FC(void *effect) {
    return ((int *)effect)[4];
}

/* Return the int field at offset 0x14 of the nw4r::ef effect object. */
int fn_8027D904(void *effect) {
    return ((int *)effect)[5];
}

/* Return the int field at offset 0x1C of the nw4r::ef effect object. */
int fn_8027D90C(void *effect) { return *(int *)((char *)effect + 0x1C); }

int fn_8027D914(void *container, int index) {
    // Return the address of the index-th 0x3C-byte effect element in the container's embedded array (base at +0x18).
    return ((int *)container)[6] + index * 0x3C;
}

/* Return the first byte of the 4-byte field at offset 0x1F0 of the entry. */
unsigned char fn_8027D924(void *entry) {
    return ((unsigned char *)entry)[0x1F0];
}

/* Return the second byte of the 4-byte field at offset 0x1F0 of the entry. */
unsigned char fn_8027D92C(void *entry) { return ((unsigned char *)entry)[0x1F1]; }

/* Return the third byte of the 4-byte field at offset 0x1F0 of the entry. */
unsigned char fn_8027D934(void *entry) { return ((unsigned char *)entry)[0x1F2]; }

/* Return the fourth byte of the 4-byte field at offset 0x1F0 of the entry. */
unsigned char fn_8027D93C(void *entry) {
    return ((unsigned char *)entry)[0x1F3];
}

/* Return the address of the embedded field at offset 0x18C of base. */
int fn_8027D944(int base) {
    return base + 0x18C;
}

/* Return the int field at offset 0xC of the nw4r::ef effect object. */
int fn_8027D94C(void *effect) {
    return ((int *)effect)[3];
}

/* Address of the index-th 0x1F4-byte element in the container's table (base pointer at +0x8). */
int fn_8027D954(void *container, int index) {
    return ((int *)container)[2] + index * 0x1F4;
}

/* Getter: return the byte flag at offset 0xBCC of the object. */
unsigned char fn_8027D964(void *object) { return ((unsigned char *)object)[0xBCC]; }

void fn_8027D96C(int event) {
    /* Career-result save-block callback: on events 0 or 2, clear the whole 4-player score block. */
    #define gCareerResults lbl_804B2FD8
    if (event == 1) {
        return;
    }
    if (event < 1) {
        if (event < 0) {
            return;
        }
    } else if (event >= 3) {
        return;
    }
    memset(gCareerResults, 0, 0x20);
    #undef gCareerResults
}

  extern char lbl_804B2FD8[];
  extern int memset(void *, int, unsigned int);
  extern char lbl_80347DF8[];
  extern void fn_802E30C8(char *, ...);
/* Handles a per-slot career/path event; for event 0 logs the cleared slot and zeroes its 8-byte state entry. */
void fn_8027D9A4(int slotIndex, int event) {
    switch (event) {
    case 0:
        fn_802E30C8(lbl_80347DF8, slotIndex);
        memset(lbl_804B2FD8 + slotIndex * 8, 0, 8);
        break;
    default:
        break;
    }
}

__declspec(section ".data") extern char lbl_804B2FD8[];
void fn_8027DA08(void) {
    /* Update the current player's 8-byte score entry in lbl_804B2FD8. */
    int outA, unusedA, outB, outWeight;
    int *playerEntry;
    int score;
    int i;
    int total;
    int weight;
    int j;
    int playerIndex;
    int clampedScore;
    playerIndex = fn_8000DA10() << 3;
    playerEntry = (int *)((char *)&lbl_804B2FD8 + playerIndex);
    playerEntry[0] = 0;
    i = 0;
    do {
        fn_8027BCC0(i, &outA, &unusedA);
        playerEntry[0] += outA;
        i++;
    } while (i < 3);
    total = 0;
    weight = 0;
    j = 0;
    do {
        fn_8027BCC8(j, &outB, &outWeight);
        j++;
        total += outB;
        weight += outWeight;
    } while (j < 3);
    score = total * 100 / weight;
    score &= (-score & ~score) >> 31;
    clampedScore = score >= 100 ? 100 : score;
    playerEntry[1] = clampedScore;
}

extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_802E6BD8(int, int, void *, int, void *);
extern void fn_8000DBC8(void *);
extern void fn_8027D96C(int);
extern void fn_8027D9A4(int, int);
/* Register the career-result save block (ID 'PCBR') and its load/slot-clear callback. */
void fn_8027DAF4(void) {
    fn_802E6BD8(0x50435252, 1, &lbl_804B2FD8, 0x20, fn_8027D96C);
    fn_8000DBC8(fn_8027D9A4);
}

#pragma use_lmw_stmw off
void *fn_8027DB40(int arg0) {
    int flagA, bit1, bit2;
    int i;
    int cnt;
    int limit;
    int filtered;
    int bit1Zero;
    Ent_8027DB40 *e;
    int *info;
    Obj_8027DB40 *obj;
    int b, c;

    flagA = arg0 & 1;
    bit1 = (arg0 >> 1) & 1;
    bit2 = (arg0 >> 2) & 1;
    if (fn_80019714() != 0) {
        flagA = 1;
    }
    limit = fn_80018FB4();
    filtered = 0;
    if (flagA == 0 && ((int (*)(int))fn_8027DE68)(0) == 0) {
        filtered = 1;
    }
    cnt = 0;
    for (i = 0; i < fn_80019088(); i++) {
        e = fn_80019054(i);
        if ((filtered == 0 || e->val <= limit) && e != 0 && stricmp(e->name, lbl_8055C794) == 0
            && fn_80016604(e->id) > 0) {
            cnt++;
        }
    }
    if (fn_800194CC() != 0) {
        cnt++;
    }
    if (fn_80019604() != 0) {
        cnt++;
    }
    obj = (Obj_8027DB40 *)fn_8025007C(cnt);
    bit1Zero = (!bit1);
    for (i = 0; i < fn_80019088(); i++) {
        e = fn_80019054(i);
        if ((filtered == 0 || e->val <= limit) && e != 0 && stricmp(e->name, lbl_8055C794) == 0
            && fn_80016604(e->id) > 0) {
            info = fn_8001668C(e->id, 0);
            bit1 = 1;
            if (flagA == 0 && fn_80018FA8(e->id) == 0) {
                bit1 = 0;
            }
            b = 0;
            if (!(info[0xA0 / 4] & 2) && info[8 / 4] != info[4 / 4]) {
                b = 1;
            }
            if (bit1 == 0 && bit2 != 0) {
                continue;
            }
            c = 0;
            if (b != 0 && (flagA != 0 || (bit1Zero != 0 && fn_80019144(e->id) != 0))) {
                c = 1;
            }
            obj->vt->add(obj, e->id, bit1, c);
        }
    }
    if (fn_800194CC() != 0) {
        obj->vt->add(obj, fn_80019534(), 1, 0);
    }
    if (fn_80019604() != 0) {
        obj->vt->add(obj, fn_80019664(), 1, 0);
    }
    return obj;
}
/* Runs fn_8027E0C8's task under "career" mode: switches the current game mode
 * to career (loading it if a different one is active), invokes the task with
 * fn_8027B834 as its data-block callback for the given screen, then restores
 * the mode that was active on entry if the task left a different one. */
void fn_8027DDCC(int screenIndex) {
    int prevMode;
    int currentMode;

    gModeSwitchBusy = 1;
    prevMode = fn_80012810();
    if (prevMode != MODE_CAREER) {
        if (prevMode != MODE_NONE) fn_80012794();
        fn_80012790(MODE_CAREER);
    }
    fn_8027E0C8(fn_8027B834, screenIndex);
    gModeSwitchBusy = 0;
    currentMode = fn_80012810();
    if (prevMode != currentMode) {
        if (currentMode != MODE_NONE) fn_80012794();
        if (prevMode != MODE_NONE) fn_80012790(prevMode);
    }
}

void fn_8027DE68(void) {
    /* Alias that forwards to fn_8027B94C: validates every entry of the current
     * player's primary group list (the group index is passed through in r3). */
    fn_8027B94C();
}

void fn_8027DE6C(void) {
    /* Reset the effect and score state: release cached effect references, rebuild
       the effects for mode 0x130, and refresh the current player's score entry. */
    fn_8027B77C();
    fn_8027BF38();
    fn_8027B690();
    fn_8027DA08();
}

#pragma dont_inline on
int fn_8027DE98(int playerIndex) {
    return *(int *)((char *)&lbl_804B2FD8 + playerIndex * 8);
}
#pragma dont_inline reset

/* OS alarm callback: refresh the value tied to the currently selected ident.
   Reads the active index with fn_8000DA10 and reads that entry's first word
   from the 8-byte-record table at lbl_804B2FD8 via fn_8027DE98. The alarm
   itself is unused. */
void fn_8027DEAC(void *alarm) {
    fn_8027DE98(fn_8000DA10(alarm));
}

void* fn_8027DED0(void) {
#define rankOverride lbl_8055C790
    /* Get the temporary rank override set during scene setup (-1 = none). */
    return rankOverride;
#undef rankOverride
}

/* Empty stub: callers pass (arg0, object, value) — fn_801B86BC does so right
   after scaling the object's float at +0x50 — but all arguments are ignored
   and nothing is done; compiles to a bare 'blr'. */
void fn_8027DED8(int arg0, void *arg1, float arg2) {
}

extern void *fn_8027DB40(int);
extern void *fn_8025007C(int);
extern int fn_8024DAE0(int, int, int, void *, int);
extern char lbl_80347E30[];
extern char lbl_80347E40[];
#pragma cplusplus on
/* Look up the "vehicle_map"/"default_vehicle" entry for the given record and pass it to fn_8024DAE0:
 * if present wrap the found vehicle id in a handle (fn_8025007C), otherwise build a default list (fn_8027DB40). */
extern "C" int fn_8027DEDC(int arg0, int arg1, int arg2, int arg3, int arg4) {
    extern void fn_800167FC(int);
    extern int fn_80012820(int);

    class Result {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual int vfunc_18(const char *key, int flag);
    };
    class Inner {
    public:
        virtual void v0();
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
        virtual Result *vfunc_5c(const char *key);
    };
    class Handle {
    public:
        virtual void release(int flag);
        virtual void vfunc_0c(int found, int a, int b);
    };
    struct Obj {
        unsigned char pad[0x80];
        Inner *inner;
    };

    fn_800167FC(1);
    void *manager = (void *)fn_80012820(arg2);
    int found = 0;
    if (manager != 0) {
        Inner *inner = ((Obj *)manager)->inner;
        if (inner != 0) {
            int check = (int)inner->vfunc_5c(lbl_80347E30);
            if (((unsigned int)(-check | check) >> 31) != 0) {
                inner = ((Obj *)manager)->inner;
                Result *r = inner->vfunc_5c(lbl_80347E30);
                found = r->vfunc_18(lbl_80347E40, 0);
            }
        }
    }
    if (found == 0) {
        manager = fn_8027DB40(0);
    } else {
        manager = fn_8025007C(1);
        ((Handle *)manager)->vfunc_0c(found, 1, 0);
    }
    int result = fn_8024DAE0(arg0, arg1, 0, manager, arg3);
    if (manager != 0) {
        ((Handle *)manager)->release(1);
    }
    return result;
}
#pragma cplusplus off
void *fn_80012870(int, int);
void fn_8023BF4C(void *);
void fn_8027E024(int arg0, int arg1, int arg2) {
    /* Resolve arg1 through the global table/list context, scan for a matching key in
     * that list to fill a found index (or -1), then forward the packed args to fn_8023BF4C. */
    struct Args {
        int list;
        int found;
        int arg2;
        int arg0;
    } args;
    int index;
    int key = arg1;
    void *result;

    result = fn_8001285C(arg1);
    args.list = *(int *)((char *)result + 4);
    args.found = -1;
    index = *(int *)((char *)((void *(*)(int))fn_80012820)(args.list) + 0x70);
    goto test;
loop:
    if (key != *(int *)fn_80012870(args.list, index)) {
        goto test;
    }
    args.found = index;
test:
    if (index-- > 0) {
        goto loop;
    }
    args.arg2 = arg2;
    args.arg0 = arg0;
    fn_8023BF4C(&args);
}

extern void *fn_80016464(int arg0);
extern void *fn_80016510(void *arg0);
extern void *fn_80016544(int arg0);
extern void fn_80016970(int arg0, int arg1, int arg2, int arg3);
extern int fn_8000DA10(void);
extern void fn_8000DB34(void);
extern void fn_800169F8(int arg0);
extern void fn_802E4A10(void);
extern void fn_80137C84(int arg0);
extern void fn_8001FD4C(int arg0);
extern void fn_80016A44(int arg0);
extern void fn_802840F4(void);
extern void fn_802840F8(void);
extern int fn_802840FC(int *arg0, void *arg1, unsigned char *arg2);
extern int fn_8027BAB8(void *arg0);
extern int fn_80019098(void *arg0);
extern int fn_8001931C(void *arg0);
extern int fn_800194C8(void);
extern int fn_800195C0(void);
extern void fn_8001EFB0(int *arg0);
extern void buildAndPlaySequenceBuffer(int arg0, int arg1, void *arg2, int *arg3);
extern void fn_8025A204(void);
extern void fn_8001EFBC(void);
extern void fn_802E7128(void);
#pragma dont_inline on
void fn_8027E0C8(void *arg0, int arg1) {
    int chain28b;
    int chain20;
    int chain48;
    int chain40;
    int info;
    int idx16;
    int i17;
    int bab1;
    void *list;
    int v22;
    int v21;
    int v20;
    int v19;
    int flag18;
    int a194CC;
    void *item;
    int idx14;
    int spE8;
    unsigned char buf[0xB0];
    unsigned char frame[0x14];
    int z[3];
    int key;
    int sp10;
    int spC;
    void *cb;
    int sel;
    int a19604;
    void *sub;
    int flag29;
    int cnt30;
    void *obj29;
    int diff;
    int a19604new;
    void *t0;
    void *t1;
    int chain28_1;
    int chain28_2;
    int flagCheck;
    int a19604old;
    int tmpFlag;
    int tmp20;
    int flagSecond;
    int j16;

    cb = arg0;
    key = -1;
    spE8 = *(int *)((char *)fn_80016464(0) + 4);
    sp10 = *(int *)((char *)fn_80016510(*(void **)((char *)fn_80016464(0) + 0x4C)) + 4);
    spC = *(int *)((char *)fn_80016464(0) + 0x50);
    list = ((void *(*)(int))cb)(arg1);
    fn_802840F4();
    memset(frame, 0, 0x14);
    while (fn_802840FC(&key, list, frame) != 0) {
        memset(frame, 0, 0x14);
        if (((int (*)(int *, int *, int, int))fn_8027DEDC)(&sp10, &spC, *(int *)((char *)fn_8001285C(key) + 4), arg1) != 0) {
            idx14 = -1;
            idx16 = -1;
            v22 = 0;
            v21 = 0;
            v20 = 0;
            v19 = 0;
            flag18 = 1;
            for (i17 = 0; i17 < ((int (*)(void *))*(void **)((char *)*(void **)list + 0xC))(list); i17++) {
                item = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, i17);
                bab1 = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x20))(item);
                flag18 = (flag18 != 0 && bab1 != 0) ? 1 : 0;
                for (a19604 = 0; a19604 < ((int (*)(void *))*(void **)((char *)*(void **)item + 0x18))(item); a19604++) {
                    sub = ((void *(*)(void *, int))*(void **)((char *)*(void **)item + 0x1C))(item, a19604);
                    if (key == ((int (*)(void *))*(void **)((char *)*(void **)sub + 0x20))(sub)) {
                        idx14 = i17;
                        idx16 = a19604;
                        v22 = ((int (*)(void *))*(void **)((char *)*(void **)sub + 0x40))(sub);
                        v21 = ((int (*)(void *))*(void **)((char *)*(void **)sub + 0x48))(sub);
                        v20 = bab1;
                        v19 = ((int (*)(void *))*(void **)((char *)*(void **)item + 0x28))(item);
                    }
                }
            }
            t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
            t1 = ((void *(*)(void *, int))*(void **)((char *)*(void **)t0 + 0x1C))(t0, idx16);
            chain28_1 = ((int (*)(void *))*(void **)((char *)*(void **)t1 + 0x28))(t1);
            bab1 = fn_8027BAB8(list);
            info = (int)fn_80016544(sp10);
            flag29 = 0;
            flagCheck = !(*(int *)((char *)info + 0xA0) & 2);
            if (flagCheck != 0 && fn_80019144(info + 0x2C) != 0) {
                flag29 = 1;
            }
            a194CC = fn_800194CC();
            a19604old = fn_80019604();
            fn_802840F8();
            fn_80016970(0, spE8, sp10, spC);
            fn_8000DA10();
            ((void (*)(int, int))fn_800169F8)(((int (*)(void))fn_8000DB34)(), 0);
            ((void (*)(int, int))fn_80137C84)(((int (*)(void))fn_802E4A10)(), 0);
            fn_8001FD4C(((int (*)(int))fn_8027DE68)(0) == 0);
            t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
            if (((int (*)(void *))*(void **)((char *)*(void **)t0 + 0x20))(t0) != 0) {
                sel = 0;
            } else {
                t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                t1 = ((void *(*)(void *, int))*(void **)((char *)*(void **)t0 + 0x1C))(t0, idx16);
                sel = ((int (*)(void *))*(void **)((char *)*(void **)t1 + 0x38))(t1);
            }
            lbl_8055C790 = (void *)sel;
            memset(buf, 0, 0xB0);
            fn_8027E024((int)buf, key, arg1);
            lbl_8055C790 = (void *)-1;
            fn_80016A44(0);
            fn_8001FD4C(0);
            list = ((void *(*)(int))cb)(arg1);
            fn_802840F4();
            if (((int *)buf)[2] > 0) {
                fn_8027DA08();
                t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                t1 = ((void *(*)(void *, int))*(void **)((char *)*(void **)t0 + 0x1C))(t0, idx16);
                chain28_2 = ((int (*)(void *))*(void **)((char *)*(void **)t1 + 0x28))(t1);
                cnt30 = 0;
                if (flagCheck != 0 && fn_80019144(info + 0x2C) != 0) {
                    cnt30 = 1;
                }
                z[0] = 0;
                z[1] = 0;
                z[2] = 0;
                fn_8001EFB0(z);
                obj29 = fn_8025007C(2);
                if (flag29 == 0 && cnt30 != 0) {
                    ((void (*)(void *, int, int, int))*(void **)((char *)*(void **)obj29 + 0xC))(obj29, fn_80019098((char *)info + 0x2C), 1, 0);
                    info = fn_8001931C((char *)info + 0x2C);
                    ((void (*)(void *, int, int))*(void **)((char *)*(void **)obj29 + 0x10))(obj29, ((int (*)(void *))*(void **)((char *)*(void **)obj29 + 0x14))(obj29) - 1, info);
                }
                if (a194CC == 0 && fn_800194C8() != 0) {
                    ((void (*)(void *, int, int, int))*(void **)((char *)*(void **)obj29 + 0xC))(obj29, fn_80019534(), 1, 0);
                    a194CC = fn_800195C0();
                    ((void (*)(void *, int, int))*(void **)((char *)*(void **)obj29 + 0x10))(obj29, ((int (*)(void *))*(void **)((char *)*(void **)obj29 + 0x14))(obj29) - 1, a194CC);
                }
                buildAndPlaySequenceBuffer(z[1], z[2], obj29, &spC);
                if (obj29 != 0) {
                    ((void (*)(void *, int))*(void **)((char *)*(void **)obj29 + 8))(obj29, 1);
                }
                fn_8025A204();
                fn_8001EFBC();
                if (((int (*)(void *))*(void **)((char *)*(void **)list + 0x14))(list) != 0) {
                    t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                    t1 = ((void *(*)(void *, int))*(void **)((char *)*(void **)t0 + 0x1C))(t0, idx16);
                    chain40 = ((int (*)(void *))*(void **)((char *)*(void **)t1 + 0x40))(t1);
                    t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                    t1 = ((void *(*)(void *, int))*(void **)((char *)*(void **)t0 + 0x1C))(t0, idx16);
                    chain48 = ((int (*)(void *))*(void **)((char *)*(void **)t1 + 0x48))(t1);
                    t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                    chain20 = ((int (*)(void *))*(void **)((char *)*(void **)t0 + 0x20))(t0);
                    t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, idx14);
                    chain28b = ((int (*)(void *))*(void **)((char *)*(void **)t0 + 0x28))(t0);
                    idx14 = fn_8027BAB8(list);
                    flagSecond = 1;
                    for (j16 = 0; j16 < ((int (*)(void *))*(void **)((char *)*(void **)list + 0xC))(list); j16++) {
                        tmpFlag = flagSecond;
                        flagSecond = 0;
                        if (tmpFlag) {
                            t0 = ((void *(*)(void *, int))*(void **)((char *)*(void **)list + 0x10))(list, j16);
                            tmp20 = ((int (*)(void *))*(void **)((char *)*(void **)t0 + 0x20))(t0);
                            if (tmp20 != 0) {
                                flagSecond = 1;
                            }
                        }
                    }
                    a19604new = fn_80019604();
                    diff = chain28_2 - chain28_1;
                    *(int *)(frame + 4) = diff;
                    *(int *)(frame + 8) = key;
                    frame[0] = (diff > 0) ? 1 : 0;
                    frame[0xC] = (v22 == 0 && chain40 != 0) ? 1 : 0;
                    frame[0xD] = (v21 == 0 && chain48 != 0) ? 1 : 0;
                    frame[0xE] = (v20 == 0 && chain20 != 0) ? 1 : 0;
                    frame[0xF] = (v19 == 0 && chain28b != 0) ? 1 : 0;
                    frame[0x10] = (flag18 == 0 && flagSecond != 0) ? 1 : 0;
                    frame[0x11] = (bab1 == 0 && idx14 != 0) ? 1 : 0;
                    frame[0x12] = (a19604old == 0 && a19604new != 0) ? 1 : 0;
                }
            }
            fn_802E7128();
        }
    }
    fn_802840F8();
}
