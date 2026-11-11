// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern float lbl_80562B2C;
extern float lbl_80562B28;
extern float lbl_80562B30;
extern int lbl_8055E960;
extern void fn_802C7040(int);
extern void fn_802C9900(float);
extern void fn_802C9904(void);
extern unsigned int lbl_8055AD90;
extern const char lbl_803391EC[];
extern int strcmp(const char *, const char *);
extern void *fn_801284F8(int, const char *);
extern int fn_801D94DC(void *, void *, const char *, int);

#define dtbNameKey lbl_8055AD90     /* "name": a DTB item's own name field */
#define morphRegionKey lbl_803391EC /* "morph_region": the sub-table fn_801D94DC reads */
#define dtbZeroWeight lbl_80562B2C  /* 0.0f: the weight every morph group starts at */

// State of the terrain morph / "wl model" system. fn_801D9284 builds all of it
// at startup and fn_801D9828 releases it again.
#define morphGroupList lbl_8055E96C    /* MorphGroup * list, one node per "morph_group" item */
#define omlList lbl_8055E964           /* fn_801D9654's list of "oml" model sets */
#define wlMapModel lbl_8055E960        /* model handle of "wlmap.mod" (mrmodel) */
#define morphUpdateFrozen lbl_8055E968 /* non-zero: fn_801D9AB8 skips weight changes */

// The DTB/model names fn_801D9284 reads are one run of strings in .data
// (lbl_80339108, whose first bytes are the "mgroups are ..." debug strings);
// the code walks them as offsets from its start.
#define wlDataNames lbl_80339108
#define nameRegionVal 0x44   /* "mregion.val": the morph region table */
#define nameMorphVal 0x50    /* "mmorph.val": the morph group table */
#define nameMorphGroups 0x5C /* "morph_groups": its group sub-table */
#define nameMorphGroup 0x6C  /* "morph_group": the item type to collect */
#define nameModelsVal 0x78   /* "wlmodels.val": the wl model table */
#define nameOmlLists 0x88    /* "oml_lists": its model-set sub-table */
#define nameWlMapMod 0x94    /* "wlmap.mod": the model to load */

#pragma cplusplus on
// One "morph_group" item of the mmorph.val DTB, built by fn_801D9394 and linked
// into the list at lbl_8055E96C; fn_801D9B58 walks the same nodes.
struct MorphGroup {
    char name[0x20];         // 0x00 the item's "name", copied in when the node is built
    float weight;            // 0x20 blend weight; fn_801D9AB8 applies it to the morph regions
    void *morphRegions;      // 0x24 head of the "morph_region" list fn_801D94DC builds
    void **children;         // 0x28 the oml_list nodes using this group; points at childrenInline
    int childCount;          // 0x2C
    int childLimit;          // 0x30 room in the inline array
    void *childrenInline[8]; // 0x34 the first 8 children, stored inside the node
    struct MorphGroup *next; // 0x54
};
struct DtbManager801D9394 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void *getAt(int);
};
struct DtbItem801D9394 {
    virtual const char *getName();
    virtual void f1();
    virtual void f2();
    virtual const char *getString(const char *);
};
// A DTB value table as opened by fn_80131810: get() returns the named
// sub-table inside it (fn_801D9394 walks the same objects item by item).
struct DtbTable {
    virtual void *get(const char *);
};
struct Getter801D9284 {
    virtual void *get(const char *);
};
#pragma cplusplus reset
extern unsigned char lbl_8055E968;
extern void *lbl_8055E96C;
extern float lbl_80562B2C;
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
extern void fn_801D611C(s32);
extern void fn_801D77E8(s32);
extern void fn_801D77EC(s32);
extern void fn_801D7874(s32);

extern void fn_80128668(void*);
void* fn_801D9090(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D90E8(s32 arg0) {
    fn_801D611C(arg0 - 4);
}

void fn_801D90F0(s32 arg0) {
    fn_801D77E8(arg0 - 4);
}

void fn_801D90F8(s32 arg0) {
    fn_801D77EC(arg0 - 4);
}

void fn_801D9100(s32 arg0) {
    fn_801D7874(arg0 - 4);
}

void fn_801D9108(int arg0) { fn_801D8938(arg0 - 4); }

void fn_801D9110(int arg0) { fn_801D893C(arg0 - 4); }

void fn_801D9118(int arg0) { fn_801D89C0(arg0 - 4); }

#pragma scheduling invalid_target
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling on
void fn_801D9120(float *out, float *values, int count, float weight) {
    float value = values[count - 1];
    if (count == 1) {
        float inv = lbl_80562B28 - value;
        out[1] = weight * value;
        out[0] = weight * inv;
    } else {
        fn_801D9120(out, values, count - 1, weight * (lbl_80562B28 - value));
        fn_801D9120(out + (1 << (count - 1)), values, count - 1, weight * value);
    }
}
#pragma pop
#pragma dont_inline off
#pragma scheduling default
void fn_801D91D8(void) {
    extern void *lbl_8055E96C;
    extern void *lbl_8055E964;
    void *node;
    void *item;
    int count;
    int i;
    void **entries;
    for (node = lbl_8055E96C; node != 0; node = *(void **)((char *)node + 0x54)) {
        for (item = lbl_8055E964; item != 0; item = *(void **)((char *)item + 0x34)) {
            entries = *(void ***)item;
            count = *(int *)((char *)item + 4);
            i = 0;
            for (; i < count; i++) {
                if (entries[i] == node)
                    goto have_it;
            }
            i = -1;
        have_it:
            if (i != -1) {
                int used = *(int *)((char *)node + 0x2C);
                int base = *(int *)((char *)node + 0x28);
                *(int *)((char *)node + 0x2C) = used + 1;
                *(void **)((char *)base + (used << 2)) = item;
            }
        }
    }
}

extern void *lbl_8055E96C;
extern void *lbl_8055E964;
extern int lbl_8055E960;
extern float lbl_80562B28;
extern int fn_802C6CF8(int);
extern int fn_801D985C(int *);
extern int fn_801D9948(int *);
extern void fn_801D9120(float *, float *, int, float);
#pragma dont_inline on
void *fn_801D9260(int count) {
    void *node = lbl_8055E96C;
    while (node != 0 && --count >= 0)
        node = *(void **)((char *)node + 0x54);
    return node;
}

#pragma cplusplus on
// Start up the terrain morph / "wl model" system: build the morph group list
// from mmorph.val's "morph_group" items (their regions resolved against
// mregion.val), the "oml" model-set list from wlmodels.val, link the two
// together, and load the wlmap.mod model they drive.
extern "C" void fn_801D9284(void) {
    extern char lbl_80339108[];        // wlDataNames: the table/model names
    extern void *lbl_8055AD60;         // holds the start of "oml", the item type fn_801D9654 collects
    extern void *fn_80131810(void *);  // open a DTB value table by name
    extern void fn_80131818(void *);   // release a DTB value table again
    extern void fn_801D9394(void **head, void *table, const char *name, void *regionTable);
    extern void fn_801D9654(void *head, void *table, void *name, int);
    extern int fn_802C6FC0(void *name, int, int); // mrmodel: load a model
    register char *base = wlDataNames;
    void *regionTable; // "mregion.val"
    void *morphTable;  // "mmorph.val"
    void *modelTable;  // "wlmodels.val"
    void *subTable;    // the "morph_groups" / "oml_lists" sub-table of each

    morphGroupList = 0;
    regionTable = fn_80131810(base + nameRegionVal);
    if (regionTable != 0) {
        morphTable = fn_80131810(base + nameMorphVal);
        if (morphTable != 0) {
            subTable = ((struct DtbTable *)morphTable)->get(base + nameMorphGroups);
            fn_801D9394((void **)&morphGroupList, subTable, base + nameMorphGroup, regionTable);
            modelTable = fn_80131810(base + nameModelsVal);
            if (modelTable != 0) {
                subTable = ((struct DtbTable *)modelTable)->get(base + nameOmlLists);
                fn_801D9654(&omlList, subTable, &lbl_8055AD60, 0);
                fn_801D91D8();
                fn_80131818(modelTable);
            }
            fn_80131818(morphTable);
        }
        fn_80131818(regionTable);
    }
    wlMapModel = fn_802C6FC0(base + nameWlMapMod, 0, 0);
    morphUpdateFrozen = 0;
}
#pragma cplusplus reset

#pragma dont_inline off

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801D9394(void **head, DtbManager801D9394 *table, const char *name, int regionTable) {
    // Build the morph group list: for every item of the DTB `table` whose type is
    // `name` ("morph_group" of mmorph.val), allocate a MorphGroup, copy the item's
    // own "name" into it, hang its "morph_region" sub-list off it and push it on
    // the list headed by *head (the morph group list, lbl_8055E96C).
    float zeroWeight = dtbZeroWeight;
    MorphGroup *group;
    DtbItem801D9394 *item;
    int index = 0;
    const char *source;
    int remaining;
    char *dest;
    while ((item = (DtbItem801D9394 *)table->getAt(index)) != 0) {
        if (strcmp(item->getName(), name) == 0) {
            group = (MorphGroup *)fn_801284F8(sizeof(MorphGroup), name);
            if (group != 0) {
                group->children = group->childrenInline;
                group->childLimit = 8;
                group->childCount = 0;
                source = item->getString((const char *)&dtbNameKey);
                dest = (char *)group;
                remaining = 0x20;
                goto copy_check;
copy_loop:
                if (--remaining > 0)
                    goto copy_check;
                dest[-1] = 0;
                goto copy_done;
copy_check:
                {
                    unsigned char ch = *source++;
                    *dest++ = ch;
                    if ((signed char)ch != 0)
                        goto copy_loop;
                }
copy_done:
                group->morphRegions = 0;
                fn_801D94DC(&group->morphRegions, item, morphRegionKey, regionTable);
                group->next = 0;
                group->weight = zeroWeight;
            }
            group->next = (MorphGroup *)*head;
            *head = group;
        }
        ++index;
    }
}
#pragma pop
extern const char lbl_803391A8[];
extern const char lbl_803391B4[];
extern float lbl_8055AD68;
extern float lbl_8055AD70;
extern int lbl_8055AD78;
extern void fn_802E317C(const char*, const char*, ...);

#pragma cplusplus on
struct DtbItem801D94DC {
    virtual const char *getName();
    virtual void f1();
    virtual void f2();
    virtual void *find(const char *);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float getFloat(const float *);
};

struct DtbObj2_801D94DC {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int getInt(const int *);
};

struct DtbObject801D94DC {
    virtual DtbObj2_801D94DC *get(void *);
    virtual void f1();
    virtual int check(void *);
};

struct Node1D94DC {
    float field0;
    float field4;
    int field8;
    Node1D94DC *next;
};
#pragma use_lmw_stmw off
extern "C" int fn_801D94DC(void *head, void *list, const char *name, int object) {
    /* Build a linked list of morph entries matching name from the DTB list, resolving each terr_region against the region database. */
    Node1D94DC *node;
    DtbItem801D94DC *item;
    int index = 0;
    const char *found;
    while ((item = (DtbItem801D94DC *)((DtbManager801D9394 *)list)->getAt(index)) != 0) {
        if (strcmp(item->getName(), name) == 0) {
            node = (Node1D94DC *)fn_801284F8(0x10, name);
            if (node != 0) {
                node->field0 = item->getFloat(&lbl_8055AD68);
                node->field4 = item->getFloat(&lbl_8055AD70);
                found = (const char *)item->find(lbl_803391A8);
                if (((DtbObject801D94DC *)object)->check((void *)found) == 0) {
                    fn_802E317C(lbl_803391B4, found);
                }
                node->field8 = ((DtbObject801D94DC *)object)->get((void *)found)->getInt(&lbl_8055AD78);
                node->next = 0;
            }
            node->next = *(Node1D94DC **)head;
            *(Node1D94DC **)head = node;
        }
        index++;
    }
}

#pragma cplusplus on
extern "C" void fn_801345D8(char *, int, const char *, ...);
extern "C" int fn_802C6FC0(int, int, int);
extern "C" void fn_801D9654(void **head, DtbManager801D9394 *manager, const char *name) {
    struct DtbItem {
        virtual const char *getName();
        virtual void f1();
        virtual void f2();
        virtual const char *getString(const char *);
        virtual void f4();
        virtual void f5();
        virtual int parse(const char *, int);
    };
    struct Node {
        void **children;
        int childCount;
        int childLimit;
        char pad0C[8];
        void **values;
        int valueCount;
        int valueCapacity;
        char pad20[0x10];
        unsigned char active;
        char pad31[3];
        void *next;
    };
    int index = 0;
    DtbItem *item;
    Node *node;
    int i, slot, result, capacity;
    void *value;
    void **array;
    void **vtable;
    char valueName[0x20];
    char key[0x20];
    extern const char lbl_8055AD80;
    extern const char lbl_8055AD88;

    item = 0;
    goto next_item;
    do {
        if (strcmp(item->getName(), name) == 0) {
            node = (Node *)fn_801284F8(0x38, name);
            if (node != 0) {
                node->children = (void **)((char *)node + 0xC);
                node->childLimit = 2;
                node->childCount = 0;
                node->values = (void **)((char *)node + 0x20);
                node->valueCapacity = 4;
                node->valueCount = 0;
                i = 0;
                while (i < node->childLimit) {
                    fn_801345D8(key, 0x20, &lbl_8055AD80, i);
                    result = item->parse(key, -1);
                    if (result < 0)
                        break;
                    value = fn_801D9260(result);
                    slot = node->childCount;
                    ++i;
                    array = node->children;
                    node->childCount = slot + 1;
                    array[slot] = value;
                }
                capacity = 1 << node->childCount;
                {
                    int limit = node->valueCapacity;
                    if (capacity < limit)
                        limit = capacity;
                    i = 0;
                    while (i < limit) {
                        fn_801345D8(valueName, 0x20, &lbl_8055AD88, i);
                        result = (int)item->getString(valueName);
                        value = (void *)fn_802C6FC0(result, 0, 0);
                        slot = node->valueCount;
                        ++i;
                        array = node->values;
                        node->valueCount = slot + 1;
                        array[slot] = value;
                    }
                }
                node->active = 0;
            }
            node->next = *head;
            *head = node;
        }
    next_item:
        ++index;
        vtable = *(void ***)manager;
        item = ((DtbItem *(*)(DtbManager801D9394 *, int))vtable[24])(manager, index);
    } while (item != 0);
}
#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus reset

void fn_801D9828(void) {
    fn_802C6CF8(lbl_8055E960);
    fn_801D985C((int *)&lbl_8055E96C);
    fn_801D9948((int *)&lbl_8055E964);
}

extern void fn_801D98F0(void **);
int fn_801D985C(int *arg0) {
    register s32 zero = 0;
    register void *node = *(void **)arg0;
    register void *next;
    goto check;
loop:
    next = *(void **)((char *)node + 0x54);
    fn_801D98F0((void **)((char *)node + 0x24));
    if ((char *)node + 0x28 != 0) {
        if ((char *)node + 0x28 != 0) {
            ((s32 *)node)[10] = zero;
            ((s32 *)node)[11] = zero;
            ((s32 *)node)[12] = zero;
        }
    }
    fn_80128668(node);
    node = next;
check:
    if (node != 0) goto loop;
    *arg0 = 0;
}

void fn_801D98F0(void **arg0) {
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 0xC);
        fn_80128668(node);
        node = next;
    }
    *arg0 = 0;
}

#pragma use_lmw_stmw off
int fn_801D9948(int *arg0) {
    struct Node {
        int field0, field4, field8, fieldC, field10;
        int *items;
        int count;
        int field1C, field20, field24, field28, field2C, field30;
        struct Node *next;
    };
    register int *head = arg0;
    register int i;
    register int offset;
    register struct Node *node = (struct Node *)*head;
    register int zero = 0;
    while (node != 0) {
        register struct Node *next = node->next;
        if (node == 0) break;
        i = 0;
        offset = 0;
        while (i < node->count) {
            fn_802C6CF8(*(int *)((char *)node->items + offset));
            offset += 4;
            i += 1;
        }
        if ((char *)node + 0x14 != 0) {
            if ((char *)node + 0x14 != 0) {
                node->items = (int *)zero;
                node->count = zero;
                node->field1C = zero;
            }
        }
        if (node != 0) {
            if (node != 0) {
                node->field0 = zero;
                node->field4 = zero;
                node->field8 = zero;
            }
        }
        fn_80128668(node);
        node = next;
    }
    *head = zero;
}
#pragma use_lmw_stmw on
void fn_801D9A08(void) {
    void *node = lbl_8055E96C;
    while (node != 0) {
        fn_801D9AB8(node, lbl_80562B2C);
        node = *(void **)((char *)node + 0x54);
    }
    lbl_8055E968 = 0;
}

void *fn_801D9A54(const char *arg0) {
    void *node = lbl_8055E96C;
    while (node != 0) {
        if (strcmp(arg0, (const char *)node) == 0)
            return node;
        node = *(void **)((char *)node + 0x54);
    }
    return 0;
}

#pragma push
#pragma processor 750
void fn_801D9AB8(void *arg0, float weight) {
    void *node;
    float start;
    float end;
    if (lbl_8055E968 != 0)
        return;
    *(float *)((char *)arg0 + 0x20) = weight;
    node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        end = *(float *)((char *)node + 4);
        start = *(float *)node;
        fn_80178DBC(*(int *)((char *)node + 8), start + weight * (end - start));
        node = *(void **)((char *)node + 0xC);
    }
}
#pragma pop
extern unsigned char lbl_8055E968;
extern float lbl_80562B2C;
extern int strcmp(const char *, const char *);
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
int fn_801D9B28(void *arg0, int arg1) {
    void *node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(int *)((char *)node + 8) == arg1)
            return 1;
        node = *(void **)((char *)node + 0xC);
    }
    return 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801D9B58(void) {
    float workspace[4];
    int markOffset;
    struct MarkNode {
        char pad00[0x20];
        float value;
        char pad24[4];
        void **children;
        int childCount;
        char pad30[0x24];
        struct MarkNode *next;
    };
    struct ProcessNode {
        void **samples;
        int sampleCount;
        char pad08[0x0C];
        int *effects;
        int playCount;
        char pad1C[0x14];
        unsigned char active;
        char pad31[3];
        struct ProcessNode *next;
    };
    struct MarkNode *markNode;
    float markThreshold;
    float threshold;
    int count;
    float *sampleDest;
    void *child;
    float *playWeight;
    int playOffset;
    struct ProcessNode *node;
    int playIndex;

    fn_802C7040(lbl_8055E960);
    markNode = lbl_8055E96C;
    markThreshold = lbl_80562B2C;
    while (markNode != 0) {
        float v = markNode->value;
        if (markThreshold < v) {
            int markIndex = 0;
            markOffset = 0;
            while (markIndex < markNode->childCount) {
                ++markIndex;
                child = *(void **)((char *)markNode->children + markOffset);
                *(unsigned char *)((char *)child + 0x30) = 1;
                markOffset += 4;
            }
        }
        markNode = markNode->next;
    }

    node = lbl_8055E964;
    threshold = lbl_80562B30;
    while (node != 0) {
        if (node->active != 0) {
            int sampleOffset;
            float *sampleDest2;
            int sampleIndex;
            sampleDest2 = workspace;
            sampleIndex = 0;
            sampleOffset = 0;
            while (sampleIndex < (count = node->sampleCount)) {
                ++sampleIndex;
                child = *(void **)((char *)node->samples + sampleOffset);
                sampleOffset += 4;
                *sampleDest2++ = *(float *)((char *)child + 0x20);
            }

            fn_801D9120(workspace + 2, workspace, count, lbl_80562B28);
            {
                float maximum = workspace[2];
                if (threshold > maximum)
                    maximum = threshold;
                fn_802C9900(maximum);
            }
            fn_802C7040(*node->effects);
            playWeight = workspace + 3;
            playIndex = 1;
            playOffset = 4;
            while (playIndex < (count = node->playCount)) {
                fn_802C9900(*playWeight);
                fn_802C7040(*(int *)((char *)node->effects + playOffset));
                ++playWeight;
                playOffset += 4;
                ++playIndex;
            }
            node->active = 0;
        }
        node = node->next;
    }
    fn_802C9904();
}
#pragma pop
