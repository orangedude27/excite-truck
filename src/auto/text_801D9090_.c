// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern float lbl_80562B2C;
extern float lbl_80562B28;
extern float lbl_80562B30;
extern int lbl_8055E960;
extern void DrawModelInstance(int);
extern void fn_802C9900(float);
extern void fn_802C9904(void);
extern unsigned int lbl_8055AD90;
extern const char lbl_803391EC[];
extern int strcmp(const char *, const char *);
extern void *fn_801284F8(int, const char *);
extern int buildMorphRegions(void *, void *, const char *, int);

#define dtbNameKey lbl_8055AD90     /* "name": a DTB item's own name field */
#define morphRegionKey lbl_803391EC /* "morph_region": the sub-table buildMorphRegions reads */
#define dtbZeroWeight lbl_80562B2C   /* 0.0f: the weight every morph group starts at */
#define morphUnitWeight lbl_80562B28 /* 1.0f: the weight fn_801D9120 splits over the groups */
#define morphMinAlpha lbl_80562B30   /* 1/255: the smallest alpha a drawn variant gets */

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
    void *morphRegions;      // 0x24 head of the "morph_region" list buildMorphRegions builds
    void **children;         // 0x28 the oml_list nodes using this group; points at childrenInline
    int childCount;          // 0x2C
    int childLimit;          // 0x30 room in the inline array
    void *childrenInline[8]; // 0x34 the first 8 children, stored inside the node
    struct MorphGroup *next; // 0x54
};
// One "oml" item of the oml_lists sub-table of wlmodels.val, built by
// fn_801D9654 and linked into the list at lbl_8055E964; fn_801D91D8 fills in
// groups from the morph groups that name it. Its models are the 2^groupCount
// variants of the set, one per combination of its groups being active.
struct OmlModelSet {
    MorphGroup **groups;      // 0x00 the morph groups blended into this set; points at groupsInline
    int groupCount;           // 0x04
    int groupLimit;           // 0x08 room in the inline array
    void *groupsInline[2];    // 0x0C the first 2 groups, stored inside the node
    int *models;              // 0x14 mrmodel handles of the variants; points at modelsInline
    int modelCount;           // 0x18
    int modelLimit;           // 0x1C room in the inline array
    void *modelsInline[4];    // 0x20 the first 4 models, stored inside the node
    unsigned char active;     // 0x30 set when a group of this set has to be drawn again
    char pad31[3];
    struct OmlModelSet *next; // 0x34
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
/* Resets the three 32-bit fields of a container to zero and, when shouldFree
 * is positive, frees the container itself. */
void *fn_801D9090(void *object, s32 shouldFree) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

/* Callback wrapper: forward to fn_801D611C with the pointer backed up to its enclosing structure (userData - 4). */
void fn_801D90E8(s32 userData) {
    fn_801D611C(userData - 4);
}

/* Callback wrapper of the action-group operations (like fn_801D90E8 next door):
 * the callback is handed the group's +0x4 field, so back the pointer up to the
 * group's start before calling.  fn_801D77E8 is the operation of this family
 * that the game left empty (its body is a single blr). */
void fn_801D90F0(s32 userData) {
    fn_801D77E8(userData - 4);
}

/* Callback wrapper: forward to fn_801D77EC with the pointer backed up to its enclosing structure (userData - 4). */
void fn_801D90F8(s32 userData) {
    fn_801D77EC(userData - 4);
}

/* Callback wrapper of the action-group operations (like fn_801D90E8 next door):
 * the callback is handed the group's +0x4 field, so back the pointer up to the
 * group's start before calling fn_801D7874. */
void fn_801D9100(s32 userData) {
    fn_801D7874(userData - 4);
}

/* Callback wrapper of the action-group operations (like fn_801D90E8): back the
 * handed +0x4 pointer up to the group's start before calling.  fn_801D8938 is
 * one of the operations the game left empty (its body is a single blr). */
void fn_801D9108(s32 userData) { fn_801D8938(userData - 4); }

/* Callback wrapper of the action-group operations (like fn_801D90E8): back the
 * handed +0x4 pointer up to the group's start before calling fn_801D893C,
 * which removes the 12-byte entry with this id from the group's list. */
void fn_801D9110(s32 userData) { fn_801D893C(userData - 4); }

/* Callback wrapper of the action-group operations (like fn_801D90E8): the
 * callback is handed the group's +0x4 field, so back the pointer up to the
 * group's start before calling fn_801D89C0, which appends a record to the
 * group's list. */
void fn_801D9118(s32 userData) { fn_801D89C0(userData - 4); }

#pragma scheduling invalid_target
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801D9120(float *out, float *values, int count, float weight)
{
  volatile short pad;
  float *last = (values + count) - 1;
  float value = *((values + count) - 1);
  if ((count & 0xFFu) == (1 & 0xFFu))
  {
    float inv = lbl_80562B28 - value;
    if (lbl_80562B28 || count)
    {
      out[1] = weight * value;
      out[0] = weight * inv;
    }
    else
    {
      out[1] = weight * value;
      out[0] = weight * inv;
    }
  }
  else
  {
    fn_801D9120(out, values, (count & 0xFF) - 1, weight * (lbl_80562B28 - value));
    fn_801D9120(out + (1 << (count - 1)), values, count - 1, weight * value);
  }
}
#pragma pop
#pragma dont_inline off
#pragma scheduling default
void fn_801D91D8(void)
{
  extern void *lbl_8055E96C;
  extern void *lbl_8055E964;
  int count;
  int i;
  int off;
  void *node;
  void *item;
  for (node = lbl_8055E96C; node != 0; node = *((void **) (((char *) node) + 0x54)))
  {
    for (item = lbl_8055E964; item != 0; item = *((void **) (((char *) item) + 0x34)))
    {
      count = *((int *) (((char *) item) + 4));
      i = 0;
      off = 0;
      for (; i < count; i++)
      {
        if ((*((void **) (((char *) (*((void **) item))) + off))) == node)
        {
          node = *((void **) (((char *) node) + 0x54));
          goto have_it;
        }
        off += 4;
      }

      i = -1;
      have_it:
      if (i != (-1))
      {
        int used = *((int *) (((char *) node) + 0x2C));
        int base = *((int *) (((char *) node) + 0x28));
        *((int *) (((char *) node) + 0x2C)) = used + 1;
        *((void **) (((char *) base) + (used * 4))) = item;
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
void *fn_801D9260(int steps) {
    /* Walk `steps` links down the morph-group list; stop early at the end. */
    void *group = morphGroupList;
    while (group != 0 && --steps >= 0)
        group = *(void **)((char *)group + 0x54);
    return group;
}

#pragma cplusplus on
// Start up the terrain morph / "wl model" system: build the morph group list
// from mmorph.val's "morph_group" items (their regions resolved against
// mregion.val), the "oml" model-set list from wlmodels.val, link the two
// together (fn_801D91D8), and load the wlmap.mod model they drive.
extern "C" void fn_801D9284(void) {
    extern char lbl_80339108[];        // wlDataNames: the table/model names below
    extern void *lbl_8055AD60;         // the string "oml"; only its address is passed on
    extern void *fn_80131810(void *);  // open a DTB value table by name
    extern void releaseValueFile(void *);   // release a DTB value table again
    extern void fn_801D9394(void **head, void *table, const char *name, void *regionTable);
    extern void fn_801D9654(void *head, void *table, void *name, int);
    extern int fn_802C6FC0(void *name, int, int); // mrmodel: load a model
    register char *base = wlDataNames;
    void *regionTable; // "mregion.val": the morph region table
    void *morphTable;  // "mmorph.val": the morph group table
    void *modelTable;  // "wlmodels.val": the wl model table
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
                releaseValueFile(modelTable);
            }
            releaseValueFile(morphTable);
        }
        releaseValueFile(regionTable);
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
                buildMorphRegions(&group->morphRegions, item, morphRegionKey, regionTable);
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
extern void Abend_Panic(const char*, const char*, ...);

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
extern "C" int buildMorphRegions(void *head, void *list, const char *name, int object) {
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
                    Abend_Panic(lbl_803391B4, found);
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
    int i = 0;
    int slot;
    int result;
    int capacity;
    int limit;
    void *value;
    void **array;
    char valueName[0x20];
    char key[0x20];
    extern const char lbl_8055AD80;
    extern const char lbl_8055AD88;
    while ((item = (DtbItem *)manager->getAt(index)) != 0) {
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
                    array = node->children;
                    ++i;
                    node->childCount = slot + 1;
                    array[slot] = value;
                }
                capacity = 1 << node->childCount;
                limit = node->valueCapacity;
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
                node->active = 0;
            }
            node->next = *head;
            *head = node;
        }
        ++index;
    }
}
#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus reset

/* Tears down the terrain morph ("wl model") system: releases the wlmap model,
 * then frees the morph-group list and the oml model-set list. */
void fn_801D9828(void) {
    fn_802C6CF8(wlMapModel);
    fn_801D985C((int *)&morphGroupList);
    fn_801D9948((int *)&omlList);
}

extern void fn_801D98F0(void **);
int fn_801D985C(int *listHead) {
    register s32 zero = 0;
    register void *node = *(void **)listHead;
    register void *next;
    /* Tear down the morph-group list: for each node free its sub-list at +0x24,
     * clear the bookkeeping ints at +0x28/+0x2c/+0x30, free the node, then
     * clear the list head. */
    while (node != 0) {
        next = *(void **)((char *)node + 0x54);
        if (node != 0) {
            fn_801D98F0((void **)((char *)node + 0x24));
            if ((char *)node + 0x28 != 0) {
                if ((char *)node + 0x28 != 0) {
                    ((s32 *)node)[10] = zero;
                    ((s32 *)node)[11] = zero;
                    ((s32 *)node)[12] = zero;
                }
            }
            fn_80128668(node);
        }
        node = next;
    }
    *listHead = 0;
}

/* Frees every node in a singly-linked list (next pointer at offset 0xC) and clears the list head. */
void fn_801D98F0(void **listHead) {
    void *node = *listHead;
    while (node != 0) {
        void *next = *(void **)((char *)node + 0xC);
        fn_80128668(node);
        node = next;
    }
    *listHead = 0;
}

#pragma use_lmw_stmw off
int fn_801D9948(int *listHead) {
    register int *head = listHead;
    register int index;
    register int byteOffset;
    register struct OmlModelSet *modelSet = (struct OmlModelSet *)*head;
    register int zero = 0;
    /* For each oml model set: release every variant's mrmodel handle (fn_802C6CF8),
       zero the set's group/model bookkeeping, free the node (fn_80128668), then empty the list. */
    while (modelSet != 0) {
        register struct OmlModelSet *nextSet = modelSet->next;
        if (modelSet != 0) {
            index = 0;
            byteOffset = 0;
            while (index < modelSet->modelCount) {
                fn_802C6CF8(*(int *)((char *)modelSet->models + byteOffset));
                byteOffset += 4;
                index += 1;
            }
            if ((char *)modelSet + 0x14 != 0) {
                if ((char *)modelSet + 0x14 != 0) {
                    modelSet->models = (int *)zero;
                    modelSet->modelCount = zero;
                    modelSet->modelLimit = zero;
                }
            }
            if (modelSet != 0) {
                if (modelSet != 0) {
                    modelSet->groups = (struct MorphGroup **)zero;
                    modelSet->groupCount = zero;
                    modelSet->groupLimit = zero;
                }
            }
            fn_80128668(modelSet);
        }
        modelSet = nextSet;
    }
    *head = 0;
}
#pragma use_lmw_stmw on
// Reset every morph-group blend weight to the default (zero) value,
// then clear the frozen-update flag so morph weights can be updated again.
void fn_801D9A08(void) {
    void *node = morphGroupList;
    while (node != 0) {
        fn_801D9AB8(node, dtbZeroWeight);
        node = *(void **)((char *)node + 0x54);
    }
    morphUpdateFrozen = 0;
}

/* Finds the morph-group node in the lbl_8055E96C list whose name matches arg0. */
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
/* Applies the given blend weight to each morph region in the group, unless morph updates are frozen. */
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
/* Returns 1 if the morph group's morph-region list contains a node whose region id matches `regionId`. */
int fn_801D9B28(void *group, int regionId) {
    void *node = *(void **)((char *)group + 0x24);
    while (node != 0) {
        if (*(int *)((char *)node + 8) == regionId)
            return 1;
        node = *(void **)((char *)node + 0xC);
    }
    return 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Draw the terrain morph map ("wlmap.mod") and the model sets blended over it.
   A morph group whose weight is above zero switches on every model set that
   uses it; each set that is switched on then draws its 2^groupCount variants,
   giving each one the product of its groups' weights and 1-weight (fn_801D9120)
   as its alpha, never quite invisible thanks to morphMinAlpha. A set is drawn
   once and switched off again, so this only costs work while a morph group is
   actually fading in or out. */
void fn_801D9B58(void) {
    float blend[4];
    int childOffset;
    struct MorphGroup *group;
    float zeroWeight;
    float minAlpha;
    int count;
    void *child;
    float *variantWeight;
    int variantOffset;
    struct OmlModelSet *modelSet;
    int variantIndex;

    DrawModelInstance(wlMapModel);
    group = morphGroupList;
    zeroWeight = dtbZeroWeight;
    while (group != 0) {
        float weight = group->weight;
        if (weight > zeroWeight) {
            int childIndex = 0;
            childOffset = 0;
            while (childIndex < group->childCount) {
                ++childIndex;
                child = *(void **)((char *)group->children + childOffset);
                ((struct OmlModelSet *)child)->active = 1;
                childOffset += 4;
            }
        }
        group = group->next;
    }

    modelSet = omlList;
    minAlpha = morphMinAlpha;
    while (modelSet != 0) {
        if (modelSet->active != 0) {
            int groupOffset;
            float *weightDest;
            int groupIndex;
            weightDest = blend;
            groupIndex = 0;
            groupOffset = 0;
            while (groupIndex < (count = modelSet->groupCount)) {
                ++groupIndex;
                child = *(void **)((char *)modelSet->groups + groupOffset);
                groupOffset += 4;
                *weightDest++ = ((struct MorphGroup *)child)->weight;
            }

            fn_801D9120(blend + 2, blend, count, morphUnitWeight);
            {
                float firstAlpha = blend[2];
                if (minAlpha > firstAlpha)
                    firstAlpha = minAlpha;
                fn_802C9900(firstAlpha);
            }
            DrawModelInstance(*modelSet->models);
            variantWeight = blend + 3;
            variantIndex = 1;
            variantOffset = 4;
            while (variantIndex < (count = modelSet->modelCount)) {
                fn_802C9900(*variantWeight);
                DrawModelInstance(*(int *)((char *)modelSet->models + variantOffset));
                ++variantWeight;
                variantOffset += 4;
                ++variantIndex;
            }
            modelSet->active = 0;
        }
        modelSet = modelSet->next;
    }
    fn_802C9904();
}
#pragma pop
