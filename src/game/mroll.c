// mroll.cpp — player-info/roll management ("mroll.cpp: get_player_info ...").
// Recovered TU window 0x8023FE20..0x80243460 (see docs/attribution_analysis.md).
// Static-init thunk fn_80243410 (+ .ctors slot 0x802ED418) remains in
// auto/text_80243410_.c pending a promotion pass.

typedef signed int s32;
typedef unsigned char u8;
extern int fn_80131234(void *);
extern void *fn_8027DB40(s32);
extern void *memset(void *, int, unsigned int);
extern int fn_801345D8(void *, int, void *, int);
extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
extern float lbl_80563750;
extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
extern s32 fn_8023512C(char *, s32, char *, s32);
extern s32 fn_80232578(char *, char *, s32);
extern char lbl_80498828[];
extern void *fn_80241098(void *);
extern void fn_802E317C(char *, ...);
typedef struct Fn241820VT { int pad[3]; int (*isActive)(void *); } Fn241820VT;
typedef struct Fn241820Obj { char pad[0xc]; Fn241820VT *vt; } Fn241820Obj;
void fn_8023FE20(void) {
    register int *p = (int *)lbl_80498828;
    *p++ = -1;
    p[3] = -1;
}

s32 fn_8023FE34(void) {
    register s32 *p = (s32 *)lbl_80498828;
    s32 result = 0;
    if (*p++ >= 0) result = 1;
    if (p[3] < 0) return result;
    return result + 1;
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
/* Looks up the nth active player-info slot and returns its id and stored fields; aborts on a bad index. */
void fn_8023FE60(s32 playerIndex, s32 *outField2, s32 *outField3, s32 *outId) {
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

s32 fn_8023FF1C(s32 arg0) {
    return arg0;
}

#pragma scheduling on
extern char lbl_80342618[];
s32 fn_802407B0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

s32 fn_802407F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
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

extern int fn_80128668(); /* free(): releases an allocation back to the primary/secondary buffer */
#pragma cplusplus on
/* Deleting destructor of a player's MRollRecordOption: installs this class's vtable,
   deletes the record collection owned at +0x24 and, when deleteFlag > 0, frees the
   object itself through the game's free(). */
extern "C" void *fn_80240830(MRollRecordOption *self, s32 deleteFlag) {
    class RecordCollection {
    public:
        virtual void destroy(s32 deleteFlag); /* slot 0x8: its deleting destructor */
    };
    void *records;
    if (self != 0) {
        records = self->records;
        self->vtable = lbl_80342618;
        if (records != 0) {
            ((RecordCollection *)records)->destroy(1);
        }
        if (deleteFlag > 0) {
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
void *fn_802408B0(void *arg0, s32 arg1) {
    s32 temp_r4;
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 0xC) = lbl_803426B0;
        *(void **)((char *)arg0 + 0x10) = lbl_803426B0 + 0x18;
        temp_r4 = lbl_8055F1F4;
        lbl_8055F1F4 = temp_r4 - 1;
        fn_80235380(*(s32 *)((char *)arg0 + 0x44), temp_r4);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern char lbl_80342734[];
extern s32 fn_802328D4(s32, s32);
void *fn_80240928(void *arg0, s32 arg1) {
    s32 zero = 0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg0 + 0x24) = zero;
        *(void **)arg0 = lbl_80342734;
        *(s32 *)((char *)arg0 + 0x20) = zero;
        fn_802328D4(*(s32 *)((char *)arg0 + 0x18), (s32)lbl_80342734);
        *(s32 *)((char *)arg0 + 0x18) = zero;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802409A4(void *arg0, signed char arg1) {
    *(signed char *)((char *)arg0 + 0x2E8) = arg1;
}

void fn_802409AC(void *arg0, s32 arg1) {
    void *item;
    s32 count = *(s32 *)((char *)arg0 + 0x2C);
    s32 i;
    s32 value;
    char *entry = (char *)arg0;
    s32 selected;
    *(s32 *)((char *)arg0 + 0x18 + count * 4) = arg1;
    *(s32 *)((char *)arg0 + 0x2C) = count + 1;
    for (i = 0; i < *(s32 *)((char *)arg0 + 0x2C);) {
        value = **(s32 **)((char *)arg0 + 0x34);
        selected = *(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30);
        item = *(void **)(entry + 0x18);
        entry += 4;
        i++;
        *(u8 *)item = selected;
        *(s32 *)((char *)item + 4) = value;
    }
}

#pragma scheduling invalid_target
void *fn_80240A1C(void *arg0, int *arg1, void *arg2) {
    extern unsigned char *fn_802E85B8(int);
    extern char lbl_80342650[];
    extern char lbl_8055BD60;
    struct Constructor {
        void *vtable;
        u8 pad4[0x10];
        int unk14;
        void *entries[4];
        void *object;
        int count;
        int selected;
        int *payload;
        u8 active;
        char name[0x20];
    };
    struct Constructor *self = (struct Constructor *)arg0;
    int i;

    /* Initialize a menu item: bind vtable/payload, copy the default or indexed name, publish the value, and refresh entry states. */
    self->vtable = lbl_80342650;
    {
        char *source;
        int length;
        char *dest = self->name;
        self->object = arg2;
        self->unk14 = 0;
        self->count = 0;
        self->selected = 0;
        self->payload = arg1;
        self->active = 1;
        length = 0x20;
        source = &lbl_8055BD60;
        while ((signed char)(*dest++ = *source++) != 0) {
            if (--length <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    *(int *)((unsigned char *)self->object + 0xD8) = *self->payload;
    if (*self->payload < 0) {
        char *source = &lbl_8055BD60;
        int length = 0x20;
        char *dest = self->name;
        while ((signed char)(*dest++ = *source++) != 0) {
            if (--length <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    } else {
        char *source = (char *)fn_802E85B8(*self->payload);
        int length = 0x20;
        char *dest = self->name;
        while ((signed char)(*dest++ = *source++) != 0) {
            if (--length <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    {
        void *item;
        int selected;
        int value;
        register void **entry = (void **)self;
        i = 0;
        while (i < self->count) {
            value = *self->payload;
            selected = self->active != 0 && i == self->selected;
            item = entry[6];
            entry++;
            i++;
            *(u8 *)item = selected;
            *(int *)((char *)item + 4) = value;
        }
    }
    return self;
}
#pragma scheduling on
#pragma cplusplus on
extern "C" void *fn_80240BA4(void *arg0, s32 arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    s32 index, result, i, n, wordA, wordB, count, j;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
    register void *self = arg0;
    void *desired = arg2;
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
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x20) + 0xDD) = (result == 0);

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
#pragma scheduling on
#pragma cplusplus reset

extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern void *memset(void *, int, unsigned int);
void fn_80241010(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *)((u8 *)arg0 + 0x24) = arg2;
    *(s32 *)((u8 *)arg0 + 0x1C) = arg1 + 1;
    *(s32 *)((u8 *)arg0 + 0x20) = arg3;
}

void *fn_80241024(void *arg0) {
    fn_8002F53C((u8 *)arg0 + 0x2C, fn_80241098, fn_80240928, 0x28, 5);
    memset(arg0, 0, 0x2C);
    *(u8 *)((u8 *)arg0 + 0xF4) = 0;
    *(u8 *)((u8 *)arg0 + 0x158) = 0;
    *(u8 *)((u8 *)arg0 + 0x1BC) = 0;
    *(u8 *)((u8 *)arg0 + 0x220) = 0;
    *(u8 *)((u8 *)arg0 + 0x284) = 0;
    return arg0;
}

void *fn_80241098(void *arg0) {
    s32 zero = 0;
    s32 minusOne = -1;
    *(void **)arg0 = lbl_80342734;
    *(s32 *)((u8 *)arg0 + 0x14) = zero;
    *(s32 *)((u8 *)arg0 + 0x1C) = minusOne;
    *(s32 *)((u8 *)arg0 + 0x24) = zero;
    *(s32 *)((u8 *)arg0 + 0x20) = zero;
    *(s32 *)((u8 *)arg0 + 0x18) = ((s32 (*)(char *))fn_80232578)(lbl_8034288C);
    return arg0;
}

/* Construct an object (vtable lbl_803426B0, secondary +0x18), copy *valuePtr, store id/arg3,
   assign next id from lbl_8055F1F4, load resource "caricona.art" via fn_8023512C, init floats to 0.0f. */
void *fn_802410F8(void *self, s32 id, s32 *valuePtr, s32 arg3) {
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

s32 fn_802411A4(s32 *arg0) {
    if (lbl_8055F1FC != 0) {
        *arg0 = lbl_8055F200;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
extern void fn_8023FE20(void);
void fn_802411C8(void) { fn_8023FE20(); }
#pragma dont_inline reset

#pragma dont_inline on
extern s32 fn_8023FE34(void);
void fn_802411CC(void) { fn_8023FE34(); }
#pragma dont_inline reset

extern void fn_8023FE60();
void fn_802411D0(void) { fn_8023FE60(); }

#pragma dont_inline fn_802411D4
s32 fn_802411D4(void) {
    s32 var_r31;
    var_r31 = 0;
    if ((fn_802E8504(0) != 0) && (fn_802E8504(1) != 0)) {
        var_r31 = 1;
    }
    return var_r31;
}

extern u8 lbl_8055F1FC;
extern s32 lbl_8055F200;
extern float lbl_80563758;
extern char lbl_803425A8[];
extern char lbl_8034288C[];
s32 fn_8023512C(char *, s32, char *, s32);
s32 fn_80232578(char *, char *, s32);
void fn_80241224(void) {}

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
void fn_8024122C(void *arg0) {
    char textBuf[0x1E];
    float posY, posX;
    int tier;
    float scale;
    int style;
    int textId;
    int *thresholdTable;
    volatile int *tagPtr;
    int tagValue;
    /* Formats and draws a UI car stat text label for a valid entry, selecting a
     * tier index from threshold table and adjusting style/scale by flag. */
    fn_80230C30(&posY, &posX, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    if (*(int *)((char *)arg0 + 0x1C) >= 0) {
        tagPtr = *(volatile int * volatile *)((char *)arg0 + 0x24);
        thresholdTable = lbl_802FA300;
        tagValue = *tagPtr;
        tier = 0;
        if (tagValue != 0 && tagValue >= thresholdTable[0])
            tier = 1;
        tagPtr = *(volatile int * volatile *)((char *)arg0 + 0x24);
        tagValue = *tagPtr;
        if (tagValue != 0 && tagValue >= thresholdTable[1])
            tier = 2;
        tagPtr = *(volatile int * volatile *)((char *)arg0 + 0x24);
        tagValue = *tagPtr;
        if (tagValue != 0 && tagValue >= thresholdTable[2])
            tier = 3;
        ((int (*)(void *, int, void *, ...))fn_801345D8)(textBuf, 0x1E, lbl_80342898, *(int *)((char *)arg0 + 0x1C), tier);
        scale = lbl_8056375C;
        style = 0xA;
        if (*(unsigned char *)*(void **)((char *)arg0 + 0x20)) {
            scale = lbl_80563760;
            style = 9;
        }
        textId = fn_80131234(textBuf);
        ((int (*)(int, int, int, int, float, float, float, float, float))fn_80232BA4)(textId, *(int *)((char *)arg0 + 0x18), -0x100, style, posY, posX, scale, lbl_80563758, lbl_80563764);
    }
}
#pragma processor reset
extern void fn_80216D28(void);
extern int fn_80214D50(int);
extern float fn_8023659C(int *);
extern float lbl_80563764, lbl_80563768, lbl_8056376C, lbl_80563770;
extern float lbl_80563774, lbl_80563778, lbl_8056377C;
#pragma optimize_for_size off
#pragma scheduling invalid_target
s32 fn_80241354(void *arg0, s32 arg1) {
    char *base = (char *)arg0;
    s32 direction = arg1;
    s32 active = 0;
    void *child;
    char c;
    int n;
    char *dst, *src;
    int count, index, frame, boundary;
    int *animation;
    float t, curve;
    float temp, diff, start, end;
    register void *vtable = *(void **)(base + 0x0C);
    register void *method = *(void **)((char *)vtable + 0x10);
    int result;
    result = ((int (*)(void *))method)(arg0);
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
        if (temp < lbl_80563764) t = lbl_80563764;
        else if (temp > lbl_80563758) t = lbl_80563758;
        else t = temp;
        curve = lbl_80563770;
        if (t >= lbl_80563770) {
            if (t > lbl_80563764) {
                curve = lbl_80563764;
            } else if (t > lbl_80563758) {
                curve = t * (lbl_80563774 * t * t) + lbl_80563778 * t * t;
            } else {
                curve = t * (lbl_80563774 * t * t) - lbl_80563778 * t * t;
            }
        }
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
        if (index >= 0 && index < *(int *)((char *)(char *)*(void **)(base + 0x28) + 0x98)) {
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
        if (temp < lbl_80563764) t = lbl_80563764;
        else if (temp > lbl_80563758) t = lbl_80563758;
        else t = temp;
        curve = lbl_80563770;
        if (t >= lbl_80563770) {
            if (t > lbl_80563764) {
                curve = lbl_80563764;
            } else if (t > lbl_80563758) {
                curve = t * (lbl_80563774 * t * t) + lbl_80563778 * t * t;
            } else {
                curve = t * (lbl_80563774 * t * t) - lbl_80563778 * t * t;
            }
        }
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
#pragma push
#pragma processor 750
void fn_80241820(void *arg0) {
    char *self = (char *)arg0;
    float sx, sy;
    if (*(int *)(self + 0x28) != 0 && ((Fn241820Obj *)self)->vt->isActive(self) != 0) {
        float w, h, cw, t, c, v;
        float base;
        int i;
        fn_80230C30(&sx, &sy, *(int *)(self + 0x14), *(int *)(self + 0x18));
        w = (float)*(int *)(self + 0x1c);
        cw = w / lbl_80563780;
        h = (float)*(int *)(self + 0x20);
        t = (float)((int)(lbl_80563768 * fn_8023659C()) - *(int *)(self + 0x48)) / lbl_8056376C;
        t = (lbl_80563764 < t) ? lbl_80563764 : t;
        t = (t > lbl_80563758) ? t : lbl_80563758;
        c = (t < lbl_80563770) ? lbl_80563770 : ((t > lbl_80563764) ? lbl_80563764 : ((t > lbl_80563758) ? (t * (lbl_80563774 * t * t) + lbl_80563778 * t * t) : (t * (lbl_80563774 * t * t) - lbl_80563778 * t * t)));
        base = ((sx + w * lbl_80563784) - cw * lbl_80563784) - cw * (*(float *)(self + 0x4c) + c * (*(float *)(self + 0x50) - *(float *)(self + 0x4c)));
        for (i = 0; i < *(int *)(*(char **)(self + 0x28) + 0x98); i++) {
            float x = base + (float)i * cw;
            if (x + cw > sx && x < sx + w) {
                unsigned col, white;
                int a;
                v = (x + cw * lbl_80563784) - sx;
                if (v > w * lbl_80563784) v = w - v;
                v = (v - lbl_80563758) / (w * lbl_80563784 - lbl_80563758);
                if (lbl_80563764 < v) v = lbl_80563764;
                v = (v > lbl_80563758) ? v : lbl_80563758;
                a = (int)(lbl_80563790 * (lbl_80563788 + v * lbl_8056378C));
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
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_80241DE8(void *arg0) {
    s32 *entry = (s32 *)arg0;
    s32 i;
    s32 value;

    for (i = 0; i < *(s32 *)((char *)arg0 + 0x2C); i++, entry++) {
        value = *(s32 *)(*(s32 **)((char *)arg0 + 0x34));
        *(u8 *)(*(s32 **)((char *)entry + 0x18)) =
            (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)(*(s32 **)((char *)entry + 0x18)) + 4) = value;
    }
}
#pragma pop
s32 fn_80241E40(void *arg0) {
    /* If active and synced with the current selection value, write selection/value to each output entry and return 1; otherwise return 0. */
    s32 i;
    s32 selected;
    void *outEntry;
    s32 currentValue;
    void *entryCursor;

    if (*(s32 *)*(s32 **)((char *)arg0 + 0x34) == fn_802E4A10()) {
        if (*(u8 *)((char *)arg0 + 0x38) != 0)
            goto do_loop;
    }
    return 0;

do_loop:
    entryCursor = arg0;
    i = 0;
    while (i < *(s32 *)((char *)arg0 + 0x2C)) {
        currentValue = *(s32 *)*(s32 **)((char *)arg0 + 0x34);
        selected = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30)) ? 1 : 0;
        outEntry = *(void **)((char *)entryCursor + 0x18);
        entryCursor = (char *)entryCursor + 4;
        ++i;
        *(u8 *)outEntry = selected;
        *(s32 *)((char *)outEntry + 4) = currentValue;
    }
    return 1;
}
#pragma scheduling on
s32 fn_80241EE8(s32 arg0) {
    return arg0 + 0x4C;
}

#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_80241EF0(void *arg0, s32 arg1) {
    s32 index, result, i, n, wordA, wordB;
    void *item, *record, *ctx, *info, *vtable, *infoDst;
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

    index = *(s32 *)((u8 *)arg0 + 0x28);
    *(s32 *)((u8 *)arg0 + 0x28) = index + 1;
    if (*(s32 *)((u8 *)arg0 + 0x28) >=
        ((Collection *)*(void **)((u8 *)arg0 + 0x24))->getCount()) {
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
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
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0xDD) = (result ? 0 : 1);

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
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma cplusplus reset

extern void *fn_8001668C(void *, s32);
extern void *fn_80016BC8(void *, s32);
extern void *fn_80018A8C(void *, s32, s32 *, s32);
extern s32 fn_80255918(void *, void *);
extern char lbl_8034287C[];
extern float lbl_80563750;
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
extern "C" s32 fn_802426C0(void *arg0) {
    struct Obj {
        virtual s32 f0() = 0;
        virtual s32 f1() = 0;
        virtual s32 f2() = 0;
        virtual s32 getCount() = 0;
        virtual s32 f4() = 0;
        virtual s32 getItem(s32) = 0;
    };
    s32 index = *(s32 *)((u8 *)arg0 + 0x28);
    Obj *object;
    if (index >= 0) {
        object = *(Obj **)((u8 *)arg0 + 0x24);
        if (index < object->getCount()) {
            object = *(Obj **)((u8 *)arg0 + 0x24);
            return object->getItem(index);
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
void fn_80242738(void *arg0, s32 arg1) {
    register unsigned refreshIndex;
    s32 outer;
    s32 i, n, selected, selectedValue, current, previous;
    s32 modeA, modeB, mode;
    u8 *base, *widget, *entry, *child, *list;
    signed char c;
    u8 *src, *dst;

    *(volatile u8 *)&lbl_8055F1FC = 0;
    base = (u8 *)arg0;
    outer = 0;
    do {
        widget = *(u8 **)(base + 0x18);
        **(s32 **)(widget + 0x34) = outer;
        *(s32 *)(*(u8 **)(widget + 0x28) + 0xD8) = **(s32 **)(widget + 0x34);
        selected = **(s32 **)(widget + 0x34);
#pragma optimize_for_size on
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
            c = *src++;
            *dst++ = (u8)c;
            if (c != 0) goto copy_check_loop0;
copy_done0:;
        } else {
            src = fn_802E85B8(selected);
            dst = widget + 0x39;
            n = 0x20;
            goto copy_check1;
copy_check_loop1:
            --n;
            if (n > 0) goto copy_check1;
            dst[-1] = 0;
            goto copy_done1;
copy_check1:
            c = *src++;
            *dst++ = (u8)c;
            if (c != 0) goto copy_check_loop1;
copy_done1:;
        }
#pragma optimize_for_size off
        entry = widget;
        i = 0;
        goto init_child_check;
init_child_body:
        selectedValue = **(s32 **)(widget + 0x34);
        n = (*(u8 *)(widget + 0x38) != 0 && i == *(s32 *)(widget + 0x30));
        child = *(u8 **)(entry + 0x18);
        *(u8 *)child = (u8)n;
        *(s32 *)(child + 4) = selectedValue;
        entry += 4;
        i += 1;
init_child_check:
        if (i < *(volatile s32 *)(widget + 0x2C)) goto init_child_body;
        *(s32 *)(base + 0x34) = 2;
        outer += 1;
        base += 0x20;
    } while (outer < 2);
    *(u8 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;
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
    base = (u8 *)arg0 + 0x18;
    for (refreshIndex = 0; refreshIndex < 2U; refreshIndex++, base += 0x20) {
        current = *(s32 *)(base + 0x1C);
        previous = *(s32 *)(base + 0x18);
        if (current != previous) {
            switch (current) {
            case 0:
                break;
            case 1:
                fn_80214AF0(*(s32 *)(base + 4));
                fn_80214A9C(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                break;
            case 2:
            case 3:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                fn_80214AF0(*(s32 *)(base + 0x14));
                if (refreshIndex != 0 && *(s32 *)(base + (s32)0x1C) == 2) {
                    fn_80214A9C(*(s32 *)(base + 0x10));
                } else {
                    fn_80214AF0(*(s32 *)(base + 0x10));
                }
                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 1;
                entry = list;
                i = 0;
                goto on_child_check;
on_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 && i == *(s32 *)(list + 0x30));
                child = *(u8 **)(entry + 0x18);
                *(u8 *)child = (u8)n;
                *(s32 *)(child + 4) = selectedValue;
                entry += 4;
                i++;
on_child_check:
                if (i < *(volatile s32 *)(list + 0x2C)) goto on_child_body;
                break;
            case 4:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214AF0(*(s32 *)(base + 0x0C));
                fn_80214A9C(*(s32 *)(base + 0x14));
                fn_80214AF0(*(s32 *)(base + 0x10));
                list = *(u8 **)base;
                *(u8 *)(list + 0x38) = 0;
                entry = list;
                i = 0;
                goto off_child_check;
off_child_body:
                selectedValue = **(s32 **)(list + 0x34);
                n = (*(u8 *)(list + 0x38) != 0 && i == *(s32 *)(list + 0x30));
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
            *(s32 *)(base + 0x18) = *(s32 *)(base + 0x1C);
        }
    }
    (mode != 0 ? fn_80214AF0 : fn_80214A9C)(0x1E);
    if (mode != 0) {
        for (i = 7; i <= 0xA; i++) {
            fn_80214A9C(i);
        }
    }
    *(u8 *)((u8 *)arg0 + 0x58) = (u8)mode;
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
    unsigned outer;
    s32 i, n, selected, selectedValue, current, previous;
    s32 modeA, modeB, mode;
    s32 tick, quotient;
    u8 *base, *widget, *slot, *entry, *child, *list;
    signed char c;
    u8 *src, *dst;

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
                    c = *src++;
                    *dst++ = (u8)c;
                    if (c != 0) goto copy_check_loop0;
copy_done0:;
                } else {
                    src = fn_802E85B8(selected);
                    dst = widget + 0x39;
                    n = 0x20;
                    goto copy_check1;
copy_check_loop1:
                    --n;
                    if (n > 0) goto copy_check1;
                    dst[-1] = 0;
                    goto copy_done1;
copy_check1:
                    c = *src++;
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

    base = (u8 *)arg0 + 0x18;
    for (refreshIndex = 0; refreshIndex < 2U; refreshIndex++, base += 0x20) {
        current = *(s32 *)(base + 0x1C);
        previous = *(s32 *)(base + 0x18);
        if (current != previous) {
            switch (current) {
            case 0:
                break;
            case 1:
                fn_80214AF0(*(s32 *)(base + 4));
                fn_80214A9C(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                break;
            case 2:
            case 3:
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214A9C(*(s32 *)(base + 0x0C));
                fn_80214AF0(*(s32 *)(base + 0x14));
                if (refreshIndex != 0 && *(s32 *)(base + (s32)0x1C) == 2) {
                    fn_80214A9C(*(s32 *)(base + 0x10));
                } else {
                    fn_80214AF0(*(s32 *)(base + 0x10));
                }
                list = *(u8 **)base;
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
                fn_80214A9C(*(s32 *)(base + 4));
                fn_80214AF0(*(s32 *)(base + 8));
                fn_80214AF0(*(s32 *)(base + 0x0C));
                fn_80214A9C(*(s32 *)(base + 0x14));
                fn_80214AF0(*(s32 *)(base + 0x10));
                list = *(u8 **)base;
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
            *(s32 *)(base + 0x18) = *(s32 *)(base + 0x1C);
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
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma optimize_for_size on
#pragma cplusplus reset
s32 fn_80242F68(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    s32 channel = fn_802E4A10();
    return channel;
}
