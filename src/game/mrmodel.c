// mrmodel — model resource (mrModelLoad/Unload/End, ModelInfo).
// Recovered TU window 0x802C5390..0x802C8238+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802C8238 (+ .ctors slot 0x802ED5A4) remains in
// auto/text_802C8238_.c pending a promotion pass.
#include "types.h"
extern void fn_802CC550(int, void *, float, float);
extern void *fn_8012C370(int, int, u32 *, int *, u8 *, u8 *);
extern void Abend_Panic(const char *, ...);
extern void DCStoreRangeNoSync(const void *, u32);
extern void fn_802C61BC(void *, int);
extern const char lbl_8034B2E8[];
extern const char lbl_8034B314[];
#pragma push
#pragma small_data off
extern void fn_802D6C48(void);
extern void fn_802D6C44(void);
extern void fn_802D6C4C(float);
#pragma pop
void VisitGroupIds(void *, void *);
extern int lbl_8055D008;
void* MRModel_GetInstance(int);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);

extern int lbl_8055D00C;
extern void fn_802DB2B4(void);
extern int lbl_804C1338[];
extern unsigned char gModelDetailLevelTable[];
struct Entry16 {
    char data[16];
};
extern int gModelInstances[];
extern int lbl_804C13A8[];
extern int lbl_804C13B4[];
extern const char lbl_8034B1D8[];
extern s8 lbl_8055FC20;
extern s8 gModelDisplayDirty;
extern void fn_802C8B98(int, void *);
extern int fn_802D0514(void *);
char *getTextureSlotName(char *);
int stricmp(const char *, const char *);
extern const char lbl_8034B3DC[];
extern const char lbl_8034B34C[];
int fn_802C6C20(int);
int fn_802C90E0(void);
int fn_802E30C8(const char *, int);
int fn_802C6B44(int);
int fn_802C6DC4(int, int, int, int);
void fn_802C6C38(int);
extern float *fn_802C9A40(void);
extern float lbl_80564EF4;
extern int fn_802C9638(void *, unsigned char *, float);

/* The model manager's tables, as the dispatch code below walks them.
 *
 * gModelInstances is the {count, capacity, base} of the model instances and
 * MRModel_GetInstance(id) returns base + id * 0x10, one ModelInstance.  Its groups are
 * the GroupEntry records listed by the {count, items} header at +0x04; the
 * instance's own 4x3 world matrix and view tolerance follow that header at
 * +0x1C and +0x20 (fn_802C70AC transforms a caller's matrix into them).  Each
 * group holds the ModelElements of the model that belong to it, and an element
 * keeps one display-node pointer per instance from +0x14.  fn_802C53C4 links a
 * display entry into a node's list and fn_802C5720 sorts those entries and
 * submits them; lbl_8055FC20 says whether the caller is batching the submits
 * (fn_802C7A44 sets it, submitModelBatch clears it), and lbl_8055D008 is the mask of
 * group bits the caller wants drawn (fn_802C70AC and fn_802C7458 set it per
 * call). */
struct GroupList;
struct ElementList;
struct ModelInstance {
    void *field_0;            /* +0x00 */
    struct GroupList *groups; /* +0x04 the groups drawn for this instance */
    int nodeSlot;             /* +0x08 which of an element's node slots to link */
    char *groupPositions;     /* +0x0C per-group {position, tolerance}, or 0 */
};
struct GroupList {
    int count;                /* +0x00 */
    char *items;              /* +0x04 count GroupEntry records, 0x10 each */
};
struct GroupEntry {
    int bitIndex;             /* +0x00 this group's bit in the group mask lbl_8055D008 */
    int flags;                /* +0x04 bit 0: keep the caller's id in the entry */
    struct ElementList *elements; /* +0x08 the group's elements */
    int id;                   /* +0x0C stored in every entry made for the group */
};
struct ElementList {
    int count;                /* +0x00 */
    char *items;              /* +0x04 pointers to the group's ModelElements */
};
struct ModelElement {
    unsigned int type;        /* +0x00; the instance's node slots follow at +0x14 */
};

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma scheduling off
/* Return the 0x10-byte ModelInstance record with the given id from the model manager's instance table. */ void *MRModel_GetInstance(int instanceId) {
    /* Return the 0x10-byte ModelInstance record at instanceId. */
    u32 instances = *(u32 *)((char *)gModelInstances + 8);
    return (void *)(instances + (instanceId << 4));
}
#pragma scheduling off
/* Return the group list (+0x4) of a model instance by id from the instance table's 0x10-byte records. */ /* Return the group list (ModelInstance.groups, +0x04) of the model instance with the given id. */ int MRModel_GetInstanceGroupList(instanceId)
int instanceId;
{
    /* Return the group list (+0x4) of a model instance by id, from the instance table's 0x10-byte records. */
    int *instances = *(int * volatile *)((char *)gModelInstances + 8);
    return *(int *)((char *)instances + (instanceId << 4) + 4);
}
#pragma scheduling invalid_target
void fn_802C53C4(void *a, void *b, int x, int y, unsigned char z) {
    register int count = lbl_804C1338[0];
    register int limit = lbl_804C1338[1];
    register int base;
    register int offset;
    register unsigned char *entry;
    if (count < limit) {
        base = lbl_804C1338[2];
        offset = count * 0x14;
        lbl_804C1338[0] = count + 1;
        entry = (unsigned char *)(base + offset);
    } else {
        entry = 0;
    }
    if (entry == 0)
        return;
    *(int *)(entry + 0) = *(int *)((char *)a + 12);
    *(signed char *)(entry + 4) = z;
    *(int *)(entry + 8) = x;
    if ((*(unsigned int *)((char *)a + 4) & 1) != 0)
        *(int *)(entry + 12) = y;
    else
        *(int *)(entry + 12) = -1;
    *(void **)(entry + 16) = *(void **)((char *)b + 8);
    *(void **)((char *)b + 8) = entry;
}
void fn_802C543C(void) {
    /* Reset the used-count at +0 of the display entry pool lbl_804C1338, emptying it. */
    lbl_804C1338[0] = 0;
}
#pragma dont_inline off

#pragma scheduling on
/* qsort comparator for model display entries: sort by detail level (short at +6), breaking ties by case-insensitive texture name. */
int fn_802C544C(void **leftEntryPtr, void **__restrict rightEntryPtr) {
    void *rightEntry = *rightEntryPtr;
    void *leftEntry = *leftEntryPtr;
    short rightDetail = *(short *)((char *)rightEntry + 6);
    short leftDetail = *(short *)((char *)leftEntry + 6);
    if (leftDetail != rightDetail) return leftDetail - rightDetail;
    return stricmp(getTextureSlotName(*(char **)leftEntry), getTextureSlotName(*(char **)rightEntry));
}
/* Return the 8-byte {items, count} display record for 1-based detail level (1..9) in gModelDetailLevelTable. */
void *MRModel_GetDetailLevelRecord(int level) { return (void *)(gModelDetailLevelTable + (level - 1) * 8); }

/* Return bits 8-15 (the second byte) of the given value as an unsigned byte. */
unsigned char fn_802C54CC(unsigned int value) { return (unsigned char)(value >> 8); }

#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802C54D4(void) {
    extern int lbl_804C1390[];
    extern int lbl_804C13A8[];
    extern s8 gModelDisplayDirty;
    extern void qsort(void *, unsigned int, unsigned int, int (*)(void *, void *));
    int level;
    unsigned int sourceOffset;
    int sourceIndex;
    int itemIndex;
    int count;
    int itemOffset;
    void *table;
    int *list;

    if (*(volatile unsigned char *)&gModelDisplayDirty == 0)
        return;
    lbl_804C1390[0] = 0;
    for (sourceIndex = 0, sourceOffset = 0;
         sourceIndex < *(volatile int *)lbl_804C13A8;
         sourceOffset += 0x10, sourceIndex++) {
        void *entry = (char *)(void *)(unsigned long)*(volatile int *)((char *)lbl_804C13A8 + 8) + sourceOffset;
        if (*(unsigned short *)((char *)entry + 4) != 0) {
            void **slot;
            if (lbl_804C1390[0] < lbl_804C1390[1]) {
                slot = (void **)(void *)lbl_804C1390[2] + lbl_804C1390[0]++;
            } else {
                slot = 0;
            }
            if (slot)
                *slot = entry;
        }
    }

    list = lbl_804C1390;
    count = lbl_804C1390[0];
    qsort((void *)list[2], count, 4, (int (*)(void *, void *))fn_802C544C);
    level = 1;
    table = MRModel_GetDetailLevelRecord(level);
    *(void **)table = (void *)list[2];
    for (itemIndex = 0, itemOffset = 0;
         itemIndex < lbl_804C1390[0];
         itemOffset += 4, itemIndex++) {
        void *entry = *(void **)((char *)(void *)list[2] + itemOffset);
        while (level < ((int (*)(unsigned int))fn_802C54CC)(*(short *)((char *)entry + 6)) && level <= 9) {
            level++;
            count = (int)((char *)(void *)list[2] + itemOffset -
                          (char *)*(void **)table) / 4;
            *(int *)((char *)table + 4) = count;
            table = MRModel_GetDetailLevelRecord(level);
            *(void **)table = (char *)(void *)list[2] + itemOffset;
        }
    }
    count = (int)((char *)(void *)lbl_804C1390[2] +
                  lbl_804C1390[0] * 4 - (char *)*(void **)table) / 4;
    *(int *)((char *)table + 4) = count;
    while (++level <= 9) {
        table = MRModel_GetDetailLevelRecord(level);
        *(int *)((char *)table + 4) = 0;
    }
    *(volatile unsigned char *)&gModelDisplayDirty = 0;
}
#pragma use_lmw_stmw on
#pragma dont_inline reset
#pragma scheduling on

extern void DrawList_setupMode2(int);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802D0610(int);
extern void fn_802D6B08(int);
extern void fn_802DAA18(void);
extern void fn_802DB2BC(unsigned char);
extern int gModelInstances[];
/* Tear down this model/resource list: release its handle, destroy each node's resources, then clear the head. */
/* Tear down a model/resource list: release its handle, walk the node chain at +8 (next at +0x10) releasing each node's resources, restore render state, then clear the list head. */ void fn_802C5690(void *modelList) {
    void *resNode;
    if (*(int *)((char *)modelList + 8) != 0) {
        DrawList_setupMode2(*(int *)modelList);
        resNode = *(void **)((char *)modelList + 8);
        while (resNode != 0) {
            fn_802D0610(*(int *)((char *)resNode + 8));
            if ((unsigned int)(*(int *)((char *)resNode + 12) + 0x10000) != 0xFFFF) {
                fn_802DAA18();
            }
            fn_802DB2BC(*(unsigned char *)((char *)resNode + 4));
            fn_802D6B08(*(int *)resNode);
            resNode = *(void **)((char *)resNode + 16);
        }
        DrawList_RestoreNormalMode();
        *(int *)((char *)modelList + 8) = 0;
    }
}

extern void fn_802C54D4(void);
extern int lbl_804C1390[];
#pragma dont_inline on
#pragma dont_inline on
/* Refreshes model entries for a specific group (>0) or all groups, then notifies DB. */
/* Refresh model entries for one detail level (>0) or all levels, then notify the status hook. */ void fn_802C5720(int level) {
    int itemCount;
    void **entries;
    int index;
    fn_802C54D4();
    if (level > 0) {
        void *entry = MRModel_GetDetailLevelRecord(level);
        entries = *(void ***)entry;
        itemCount = *(int *)((char *)entry + 4);
    } else {
        itemCount = lbl_804C1390[0];
        entries = *(void ***)(lbl_804C1390 + 2);
    }
    for (index = 0; index < itemCount; index++) {
        fn_802C5690(entries[index]);
    }
    fn_802DB2BC(1);
}
#pragma dont_inline reset

/* No-op default lookup hook for model-element display data, called through a
 * (void *(*)(void *)) cast with a group entry's id at the fn_802C57B4 /
 * fn_802C58FC submit paths. It returns without touching any register, so the id
 * passes straight through as the data pointer handed to fn_802CC550. */
void fn_802C57B0(void) { }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
/* Submits one model instance for drawing.  For every group of the instance
 * whose bit is set in the group mask lbl_8055D008 -- and, when the instance has
 * per-group positions, whose position fn_802C9638 still finds inside the view
 * volume (which may replace the status byte the caller measured) -- this links
 * a display entry for each element the model draws here into that element's
 * display node for this instance, and hands the node's id to fn_802CC550 with
 * the caller's distance.  Unless the caller is batching submits
 * (lbl_8055FC20), the entry list is emptied first and sorted and submitted
 * afterwards.  Elements of type 4, 6, 9 and 11, and every type from 13 up, are
 * left to the other passes (fn_802C729C and fn_802C74D8 pick those up). */
void fn_802C57B4(int instanceId, int transformId, int entryId, unsigned char status, float distance) {
    extern int lbl_8055D008;
    extern s8 lbl_8055FC20;
    extern void fn_802C543C(void);
    extern void fn_802C5720(int);
    extern void fn_802C57B0(void);
    extern void fn_802CC550(int, void *, float, float);
    extern int fn_802C9638(void *, unsigned char *, float);

    struct ModelInstance *instance;
    unsigned char entryStatus;
    int j;
    struct ElementList *elementList;
    int groupOffset;
    int nodeSlotOffset;
    int elementOffset;
    struct GroupList *groups;
    int i;
    struct GroupEntry *entry;

    instance = (struct ModelInstance *)MRModel_GetInstance(instanceId);
    groups = instance->groups;
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C543C();
    }
    nodeSlotOffset = instance->nodeSlot << 2;
    for (i = 0, groupOffset = 0; i < groups->count; groupOffset += 0x10, i++) {
        int bitIndex;
        entry = (struct GroupEntry *)(groups->items + groupOffset);
        bitIndex = entry->bitIndex;
        if (lbl_8055D008 & (1 << bitIndex)) {
            unsigned char groupStatus = status;
            char *positions = instance->groupPositions;
            if (positions == 0 || fn_802C9638(positions + groupOffset, &groupStatus, *(float *)(positions + groupOffset + 12)) != 0) {
                entryStatus = groupStatus;
                elementList = entry->elements;
                for (j = 0, elementOffset = 0; j < elementList->count; elementOffset += 4, j++) {
                    int draw = 0;
                    struct ModelElement *modelElem = (struct ModelElement *)*(void **)(elementList->items + elementOffset);
                    unsigned int type = modelElem->type;
                    if (type < 13) {
                        int otherPass;
                        draw = 1;
                        switch (type) {
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            otherPass = 1;
                            break;
                        default:
                            otherPass = 0;
                            break;
                        }
                        if (otherPass) draw = 0;
                    }
                    if (draw) {
                        void *displayNode = *(void **)(nodeSlotOffset + (int)modelElem + 0x14);
                        void *lookupData;
                        fn_802C53C4(entry, displayNode, transformId, entryId, entryStatus);
                        lookupData = ((void *(*)(void *))fn_802C57B0)((void *)entry->id);
                        fn_802CC550(*(int *)displayNode, lookupData, distance, *(float *)((char *)lookupData + 0x18));
                    }
                }
            }
        }
    }
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C5720(-1);
    }
}
#pragma push
#pragma use_lmw_stmw off
/* Resolve a resource name through the model name-override table lbl_804C13B4, bounded-copying the matching replacement (or the original lookupName) into outName. */ void fn_802C595C(char *outName, int maxLen, const char *lookupName, int id) {
    /* Resolve a resource name through the (name,id) override table, bounded-copying
       the replacement into outName, or the original name when there is no override. */
    int entryOffset;
    int entryIndex;
    char *overrideEntry;
    register const unsigned char *copySrc;
    unsigned char ch;
    entryIndex = 0;
    entryOffset = 0;
    goto table_check;
table_loop:
    overrideEntry = (char *)(unsigned long)lbl_804C13B4[2] + entryOffset;
    if (stricmp(lookupName, overrideEntry) == 0) {
        if (id == *(int *)(overrideEntry + 0x10)) {
            copySrc = (const unsigned char *)(overrideEntry + 0x14);
            goto copy_body;
copy_check:
            if (--maxLen <= 0) {
                outName[-1] = 0;
                goto done;
            }
copy_body:
            ch = *copySrc++;
            *outName++ = ch;
            if ((signed char)ch == 0) goto done;
            goto copy_check;
        }
    }
table_next:
    entryOffset += 0x2C;
    entryIndex++;
table_check:
    if (entryIndex < lbl_804C13B4[0]) goto table_loop;
    else goto fallback_copy;
fallback_copy:
    goto fallback_body;
fallback_check:
    if (--maxLen <= 0) {
        outName[-1] = 0;
        goto done;
    }
fallback_body:
    ch = *lookupName++;
    *outName++ = ch;
    if ((signed char)ch == 0) goto done;
    goto fallback_check;
done:
    return;
}
#pragma pop
/* Combine two byte values into a 16-bit key: high in the upper byte, low in the lower. */
u16 packU16Key(int high, int low) {
    return (u16)((high << 8) | low);
}

#pragma scheduling invalid_target
void *fn_802C5A60(int arg0, int arg1, u16 arg2) {
    struct Entry {
        s32 key0;
        u16 refs;
        s16 key2;
        s32 reserved;
        s32 key1;
    };
    struct Entry *entry;
    register s32 savedArg0 = arg0;
    s32 count = lbl_804C13A8[0];
    struct Entry *match = 0;
    struct Entry *freeEntry = 0;
    int one = 1;
    int zero = 0;
    struct Entry *base;
    s32 next;
    s32 i;

    entry = (struct Entry *)(unsigned long)lbl_804C13A8[2];
    for (i = count; i > 0; i--, entry++) {
        if (entry->refs != 0) {
            if (entry->key1 == arg1 && entry->key2 == arg2 && entry->key0 == arg0) {
                match = entry;
                break;
            }
        } else {
            freeEntry = entry;
        }
    }

    if (match == 0) {
        if (freeEntry == 0) {
            if (count < lbl_804C13A8[1]) {
                next = *(volatile int *)&lbl_804C13A8[0];
                base = *(struct Entry * volatile *)&lbl_804C13A8[2];
                lbl_804C13A8[0] = next + 1;
                freeEntry = base + next;
            } else {
                freeEntry = 0;
            }
            if (freeEntry == 0) {
                Abend_Panic(lbl_8034B1D8);
            }
            freeEntry->key0 = savedArg0;
        }
        freeEntry->refs = zero;
        match = freeEntry;
        freeEntry->key2 = arg2;
        freeEntry->reserved = zero;
        freeEntry->key1 = arg1;
        gModelDisplayDirty = one;
    }

    match->refs++;
    return match;
}
/* One model display-node entry from the pool at lbl_804C13A8: key0 is the
 * texture slot whose reference the node holds, refs counts its users and key2
 * is the detail level; the level-sorted display lists are rebuilt when refs
 * drops to zero. */
struct ModelDisplayNode {
    s32 key0;     /* +0x00 texture slot id, released through fn_802CAC54 */
    u16 refs;     /* +0x04 reference count */
    s16 key2;     /* +0x06 detail level */
    s32 reserved; /* +0x08 */
    s32 key1;     /* +0x0C */
};
extern void fn_802CAC54(int);
extern s8 gModelDisplayDirty;
/* Release one reference to a model display node: drop its texture slot and
 * decrement its refcount, marking the level-sorted display lists dirty when
 * the count reaches zero. */
void ModelDisplayNode_release(int *displayNode) {
    u16 refCount;
    fn_802CAC54(((struct ModelDisplayNode *)displayNode)->key0);
    refCount = ((struct ModelDisplayNode *)displayNode)->refs;
    refCount--;
    ((struct ModelDisplayNode *)displayNode)->refs = refCount;
    if (refCount == 0) {
        gModelDisplayDirty = 1;
    }
}

#pragma scheduling invalid_target
/* Build the 16-bit texture-cache sub-key: the fixed (5, 0x64) tag from the u16
 * packer, plus the doubled base id and the difference flag's low 16 bits. */
/* Build the 16-bit texture-cache sub-key used to distinguish texture variants: the fixed 0x0564 tag, the doubled base id, and the low 16 bits of the difference flag. */ u16 buildTextureSubKey(int baseId, int diffFlag) {
    return (((int (*)(int, int))packU16Key)(5, 0x64) - -((baseId * 2) & 0xFFFE)) + (diffFlag & 0xFFFF);
}
#pragma scheduling on
extern int fn_802CAC28(void *, int);
extern void *fn_802C5A60(int, int, u16);
#pragma push
#pragma small_data off
extern int lbl_8034B1F0[];
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
/* Resolve a texture-only element's "zonly.tex" reference into a model texture node handle and store it in the element's node slot. */
void fn_802C5C40(int *element, int slot, int sourceItems) {
    int baseId = *element;
    int textureHandle = fn_802CAC28(lbl_8034B1F0, 0);
    int *sourceTexNode = *(int **)((char *)sourceItems + slot * 4 + 0x14);
    s16 texRef = *(s16 *)((char *)sourceTexNode + 6);
    u16 nodeKey = texRef - 1;
    *(int *)((char *)element + slot * 4 + 0x14) =
        (int)fn_802C5A60(textureHandle, baseId, nodeKey);
}
#pragma pop
extern int fn_8012C33C(char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern int fn_802CAC44(char *, int);
extern int fn_802CAF8C(void);
extern int TextureSlot_getWrapMode(void);
extern int getTextureSlotFilter(int);
__declspec(section ".sdata") extern const char lbl_8055D010[];
/* Resolve an item's resource name (with an optional numbered suffix), register its texture, and store the resulting handle in the item's per-slot handle array. */ void fn_802C5CC4(void *item, int slot, int subKeyKind, int suffix) {
    char resName[0x100];
    char suffixedName[0x100];
    int secondKey;
    int baseId;
    int textureIndex;
    u16 subKey;

    /* Resolve a resource name (optionally with a numbered suffix) to an object handle and store it at arg0 + arg1*4 + 0x14. */
    fn_802C595C(resName, 0x100, (char *)item + 4, slot);
    if (suffix != 0) {
        fn_801345D8(suffixedName, 0x100, lbl_8055D010, suffix, resName);
        if (fn_8012C33C(suffixedName) != 0) {
            char *src = suffixedName;
            int count = 0x100;
            char *dst = resName;
            while (*dst++ = *src++) {
                if (--count <= 0) {
                    dst[-1] = '\0';
                    break;
                }
            }
        }
    }
    baseId = *(int *)item;
    textureIndex = fn_802CAC44(resName, baseId);
    if (subKeyKind != 0) {
        subKey = buildTextureSubKey(baseId, fn_802CAF8C());
    } else {
        secondKey = TextureSlot_getWrapMode();
        subKey = packU16Key(getTextureSlotFilter(textureIndex), secondKey);
    }
    *(int *)((char *)item + slot * 4 + 0x14) = (int)fn_802C5A60(textureIndex, baseId, subKey);
}

/* Iterate over all 0x10-byte GroupEntry records in a model's GroupList and
 * invoke callback with each group's id (+0x0C). */
/* Visit every GroupEntry in a model's GroupList, calling groupHook with each group's id (+0x0C). */ void VisitGroupIds(void *groupList, void *groupHook) {
    int offset = 0;
    int index = 0;
    while (index < ((struct GroupList *)groupList)->count) {
        void *entries = ((struct GroupList *)groupList)->items;
        int groupId = ((struct GroupEntry *)((char *)entries + offset))->id;
        ((void (*)(int))groupHook)(groupId);
        offset += sizeof(struct GroupEntry);
        index += 1;
    }
}

void fn_802C5E6C(void *unused, void *groupList) {
    /* Resource callback: visit every group in groupList through VisitGroupIds,
       passing the no-op per-group hook fn_802D6C44. arg0 is unused. */
    void *callback = fn_802D6C44;
    ((void (*)(void *, void *))VisitGroupIds)(groupList, callback);
}

#pragma pop
s32 FindTaggedResourceChunk(void *, u32);

#define SPHL_CHUNK_TAG 0x5350484C /* 'SPHL' tagged chunk of a model resource */

/* Return a pointer to a model resource's 'SPHL' chunk data (the chunk entry
 * plus 8 bytes), or 0 when the chunk is absent. */
s32 fn_802C5E7C(void *resource) {
    char *chunk = (char *)FindTaggedResourceChunk(resource, SPHL_CHUNK_TAG);
    if (chunk != 0) {
        return (s32)(chunk + 8);
    }
    return 0;
}

#pragma scheduling invalid_target
/* Find the first chunk in a resource's tagged list (count at +0x10, chunk-pointer array at +0x14) whose leading tag word matches tag; return the chunk pointer or 0. */ /* Find the first chunk in a resource's tagged list (count at +0x10, chunk-pointer array at +0x14) whose leading tag word matches tag; return the chunk pointer or 0. */ s32 FindTaggedResourceChunk(void *resource, u32 tag) {
    /* Searches the resource's tagged chunk list for an entry whose first field matches tag and returns it, or 0 if not found. */
    s32 count = *(s32 *)((char *)resource + 0x10);
    u32 *result = NULL;
    s32 i;
    for (i = 0; count > i; i++) {
        u32 *entry = *(u32 **)(*(char **)((char *)resource + 0x14) + i * 4);
        if (*entry == tag) {
            result = entry;
            break;
        }
    }
    return (s32)result;
}
void *fn_802C5EFC(int textureSlotId) {
    /* Find the active model display node (refs != 0) whose texture-slot key0 matches textureSlotId; return the node or NULL. */
    int count = lbl_804C13A8[0];
    struct ModelDisplayNode *node = (struct ModelDisplayNode *)(unsigned long)lbl_804C13A8[2];
    int i;
    for (i = 0; i < count; i++, node++) {
        if (node->refs != 0 && node->key0 == textureSlotId) {
            return node;
        }
    }
    return 0;
}

extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, void *, int, int);
extern char jumptable_8034B1B8[];
extern void fn_802C6068(void *);
extern void fn_802C6074(s32 *);
void fn_802C5F48(void) {
    struct SubList {
        int count;
        int capacity;
        void *buf;
    };
    register struct SubList *e64;
    register struct SubList *e70;
    register struct SubList *e58;
    register struct SubList *e7c;
    register char *base = (char *)lbl_804C1338;
    register char *jumpTable = jumptable_8034B1B8;
    int zero = 0;
    void *memory;

    e64 = (struct SubList *)(base + 0x64);
    e70 = (struct SubList *)(base + 0x70);
    e58 = (struct SubList *)(base + 0x58);
    e7c = (struct SubList *)(base + 0x7C);

    e64->capacity = 0x280;
    memory = fn_8012850C(0x2810, jumpTable + 0x44);
    e64->buf = fn_8002F37C(memory, (void (*)(void *))fn_802C6074, 0, 0x10, 0x280);
    e64->count = zero;

    *(int *)(base + 4) = 0x800;
    *(int *)base = zero;
    *(void **)(base + 8) = fn_8012850C(0xA000, jumpTable + 0x58);

    e70->capacity = 0x400;
    memory = fn_8012850C(0x4010, jumpTable + 0x70);
    e70->buf = fn_8002F37C(memory, (void (*)(void *))fn_802C6068, 0, 0x10, 0x400);
    e70->count = zero;

    e58->capacity = 0x400;
    e58->buf = fn_8012850C(0x1000, jumpTable + 0x80);
    e58->count = zero;

    e7c->capacity = 0x80;
    e7c->buf = fn_8012850C(0x1600, jumpTable + 0x90);
    e7c->count = zero;
    *(int *)(base + 0x88) = -1;
    lbl_8055D00C = 1;
}

#pragma scheduling on
/* Pool element init callback: clear the 16-bit active flag at +0x04 of an entry. */
void fn_802C6068(void *entry) {
    *(s16 *)((char *)entry + 4) = 0;
}

/* Pool element init callback: clear the first 32-bit word of an entry. */
void fn_802C6074(s32 *entry) {
    *entry = 0;
}

extern void fn_80128670(void *);
extern void MRModel_GetResourceName(void *);
extern const char lbl_8034B258[];
extern const char lbl_8034B294[];
extern int (*fn_802E30C8_varargs)(const char *, ...);

struct SubList {
    int count;
    int capacity;
    void *buf;
};

struct MasterList {
    struct SubList list0;
    char pad0[0x58 - 0xC];
    struct SubList list58;
    struct SubList list64;
    struct SubList list70;
    struct SubList list7C;
    int unk88;
};

#define fn_802C6080_free1(list) do { \
    fn_80128670((list)->buf); \
    (list)->buf = 0; \
    (list)->capacity = 0; \
    (list)->count = 0; \
} while (0)

#define fn_802C6080_free2(list) do { \
    void *buf = (list)->buf; \
    if (buf != 0) { \
        fn_80128670((char *)buf - 0x10); \
    } \
    (list)->count = 0; \
    (list)->buf = 0; \
    (list)->capacity = 0; \
} while (0)
#pragma opt_propagation off
void fn_802C6080(void) {
    struct SubList {
        int count;
        int capacity;
        void *buf;
    };
    register struct SubList *e;
    register struct SubList *e58;
    register struct SubList *e7c;
    register char *base;
    register int offset;
    register int i;
    int zero;
    void *ptr;

    base = (char *)lbl_804C1338;
    e = (struct SubList *)(base + 0x64);
    for (i = 0, offset = 0; i < *(int *)(base + 0x64); i++, offset += 0x10) {
        if (*(int *)((char *)e->buf + offset) > 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B258, i);
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B294, ((int (*)(int))MRModel_GetResourceName)(i));
        }
    }

    e7c = (struct SubList *)(base + 0x7C);
    fn_80128670(e7c->buf);
    ptr = *(void **)(base + 0x70 + 8);
    e7c->buf = 0;
    e7c->capacity = 0;
    *(int *)(base + 0x7C) = 0;
    if (ptr != 0) {
        fn_80128670((char *)ptr - 0x10);
    }

    e58 = (struct SubList *)(base + 0x58);
    zero = 0;
    ptr = e58->buf;
    *(int *)(base + 0x70) = zero;
    *(void **)(base + 0x70 + 8) = (void *)zero;
    *(int *)(base + 0x70 + 4) = zero;
    fn_80128670(ptr);

    e = (struct SubList *)base;
    e58->buf = (void *)zero;
    ptr = e->buf;
    e58->capacity = zero;
    *(int *)(base + 0x58) = zero;
    fn_80128670(ptr);

    e->buf = (void *)zero;
    ptr = *(void **)(base + 0x64 + 8);
    e->capacity = zero;
    *(int *)base = zero;
    if (ptr != 0) {
        fn_80128670((char *)ptr - 0x10);
    }

    *(int *)(base + 0x64) = 0;
    *(void **)(base + 0x64 + 8) = 0;
    *(int *)(base + 0x64 + 4) = 0;
}
extern void mrRelocatePointer(s32 *value, s32 delta);
extern void fn_802C6A9C(s32 *value, s32 delta);
extern void fn_802C6AFC(s32 *value, s32 delta);
extern void fn_802D6B80(unsigned char *arg0, s32 arg1, s32 arg2);
static inline void mr_swap4(unsigned char *q) {
    unsigned char t = q[0]; q[0] = q[3]; q[3] = t;
    t = q[1]; q[1] = q[2]; q[2] = t;
}
#define SW4(p, o) do { \
    unsigned char t = (p)[o]; (p)[o] = (p)[(o)+3]; (p)[(o)+3] = t; \
    t = (p)[(o)+1]; (p)[(o)+1] = (p)[(o)+2]; (p)[(o)+2] = t; \
} while (0)
extern char lbl_8034B2BC[];
extern void fn_802C6AB4(s32 *, s32);
extern void fn_802C6ACC(s32 *, s32);
extern void fn_802C6AE4(s32 *, s32);
extern void fn_802C6B14(s32 *, s32);
extern void fn_802C6B2C(s32 *, s32);
#pragma opt_lifetimes off
void fn_802C61BC(void *arg0, int arg1) {
    unsigned char *p = (unsigned char *)arg0;
    unsigned char *base;
    unsigned char t0, t2, t3, t5, t6, t8, t9, t10, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28;
    unsigned char s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21;
    int i, j, k, tag, ctr;
    int sp10, sp8, spC;
    (void)arg1;
    if (*(unsigned int *)p >= 0x3E80) return;
    if (*(unsigned int *)(p + 0x10) < 0x3E80) return;
    t0 = p[0xE]; t16 = p[0xD]; sp10 = t0;
    t2 = p[0x1B]; t22 = p[0x18]; sp8 = t2;
    t3 = p[0x1A]; t15 = p[0x19]; spC = t3;
    t28 = p[0];
    p[0xD] = t0;
    t21 = p[1];
    p[0x18] = t2;
    t27 = p[4]; t20 = p[5]; t10 = p[6];
    t26 = p[0x10]; t9 = p[0x13]; t19 = p[0x11]; t8 = p[0x12];
    t25 = p[0x14]; t18 = p[0x15];
    t24 = p[8]; t17 = p[9]; t23 = p[0xC]; t14 = p[0xF];
    p[0] = p[3]; p[3] = t28;
    p[1] = p[2]; p[2] = t21;
    p[4] = p[7]; p[7] = t27;
    p[5] = t10; p[6] = t20;
    p[0x10] = t9; p[0x13] = t26; p[0x11] = t8; p[0x12] = t19;
    p[0x14] = p[0x17]; p[0x17] = t25; p[0x15] = p[0x16]; p[0x16] = t18;
    p[8] = p[0xB]; p[0xB] = t24; p[9] = p[0xA]; p[0xA] = t17;
    p[0xC] = p[0xF]; p[0xF] = t23; p[0xE] = t16;
    p[0x1B] = t22; p[0x19] = t3; p[0x1A] = t15;
    s1 = p[0x1C]; p[0x1C] = p[0x1F]; p[0x1F] = s1;
    s2 = p[0x1D]; p[0x1D] = p[0x1E]; p[0x1E] = s2;
    s3 = p[0x20]; p[0x20] = p[0x23]; p[0x23] = s3;
    s4 = p[0x21]; p[0x21] = p[0x22]; p[0x22] = s4;
    s5 = p[0x24]; p[0x24] = p[0x27]; p[0x27] = s5;
    s6 = p[0x25]; p[0x25] = p[0x26]; p[0x26] = s6;
    s7 = p[0x28]; p[0x28] = p[0x2B]; p[0x2B] = s7;
    s8 = p[0x29]; p[0x29] = p[0x2A]; p[0x2A] = s8;
    s9 = p[0x2C]; p[0x2C] = p[0x2F]; p[0x2F] = s9;
    s10 = p[0x2D]; p[0x2D] = p[0x2E]; p[0x2E] = s10;
    s11 = p[0x30]; p[0x30] = p[0x33]; p[0x33] = s11;
    s12 = p[0x31]; p[0x31] = p[0x32]; p[0x32] = s12;
    s13 = p[0x34]; p[0x34] = p[0x37]; p[0x37] = s13;
    s14 = p[0x35]; p[0x35] = p[0x36]; p[0x36] = s14;
    s15 = p[0x38]; p[0x38] = p[0x3B]; p[0x3B] = s15;
    s16 = p[0x39]; p[0x39] = p[0x3A]; p[0x3A] = s16;
    s17 = p[0x3C]; p[0x3C] = p[0x3F]; p[0x3F] = s17;
    s18 = p[0x3D]; p[0x3D] = p[0x3E]; p[0x3E] = s18;
    s19 = p[0x40]; p[0x40] = p[0x43]; p[0x43] = s19;
    s20 = p[0x41]; p[0x41] = p[0x42]; p[0x42] = s20;
    s21 = p[0x44]; p[0x44] = p[0x47]; p[0x47] = s21;
    p[0x45] = p[0x46];
    mrRelocatePointer((s32 *)(p + 4), (s32)arg0);
    base = *(unsigned char **)(p + 4);
    for (i = 0; i < *(int *)p; i++) {
        unsigned char *e = base + i * 0x10;
        SW4(e, 0); SW4(e, 4); SW4(e, 8); SW4(e, 0xC);
        fn_802C6A9C((s32 *)(e + 0xC), (s32)arg0);
        fn_802D6B80(*(unsigned char **)(e + 0xC), (s32)arg0, arg1);
        fn_802C6AFC((s32 *)(e + 8), (s32)arg0);
    }
    fn_802C6AB4((s32 *)(p + 0x14), (s32)arg0);
    for (j = 0; j < *(int *)(p + 0x10); j++) {
        unsigned char *r = (unsigned char *)(*(u32 *)(p + 0x14) + j * 4);
        unsigned char *q;
        SW4(r, 0);
        fn_802C6ACC((s32 *)r, (s32)arg0);
        q = *(unsigned char **)r;
        SW4(q, 0); SW4(q, 4);
        switch (*(s32 *)q) {
        case 0x4D524A54: {
            unsigned char *s;
            SW4(q, 8);
            s = q + 0x2C;
            for (k = 0; k < *(int *)(q + 8); k++) {
                ctr = 2;
                do {
                    SW4(s, 0); SW4(s, 4); SW4(s, 8);
                    SW4(s, 0xC); SW4(s, 0x10); SW4(s, 0x14);
                    s += 0x18;
                } while (--ctr != 0);
                s += 0x50;
            }
            break;
        }
        case 0x4D52424E: {
            unsigned char *s;
            SW4(q, 8);
            s = q + 0x10;
            for (k = 0; k < *(int *)(q + 8); k++) {
                ctr = 2;
                do {
                    SW4(s, 0); SW4(s, 4); SW4(s, 8);
                    SW4(s, 0xC); SW4(s, 0x10); SW4(s, 0x14);
                    s += 0x18;
                } while (--ctr != 0);
                SW4(s, 0x18); SW4(s, 0x1C); SW4(s, 0x20); SW4(s, 0x24);
                s += 0x38;
            }
            break;
        }
        case 0x5350484C: {
            unsigned char *s = q + 8;
            for (k = 0; k < *(int *)p; k++) {
                SW4(s, 0); SW4(s, 4); SW4(s, 8); SW4(s, 0xC);
                s += 0x10;
            }
            break;
        }
        default:
            Abend_Panic(lbl_8034B2BC, (s32)arg0, arg1);
            break;
        }
    }
    fn_802C6AE4((s32 *)(p + 0xC), (s32)arg0);
    for (j = 0; j < *(int *)(p + 8); j++) {
        unsigned char *r = (unsigned char *)(*(u32 *)(p + 0xC) + j * 4);
        unsigned char *q;
        SW4(r, 0);
        fn_802C6AFC((s32 *)r, (s32)arg0);
        q = *(unsigned char **)r;
        SW4(q, 0); SW4(q, 4);
        fn_802C6B14((s32 *)(q + 4), (s32)arg0);
        for (k = 0; k < *(int *)q; k++) {
            unsigned char *r2 = (unsigned char *)(*(u32 *)(q + 4) + k * 4);
            unsigned char *q2;
            SW4(r2, 0);
            fn_802C6B2C((s32 *)r2, (s32)arg0);
            q2 = *(unsigned char **)r2;
            SW4(q2, 0);
        }
    }
}
/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */
/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */ void mrRelocatePointer(s32 *value, s32 delta) {
    s32 ptr = *value;
    if (ptr != 0) {
        *value = ptr + delta;
    }
}

void fn_802C6A9C(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802C6AB4(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */ void fn_802C6ACC(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 ptr = *value;
    if (ptr != 0) {
        *value = ptr + delta;
    }
}

/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */ void fn_802C6AE4(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 ptr = *value;
    if (ptr != 0) {
        *value = ptr + delta;
    }
}

/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */ void fn_802C6AFC(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 ptr = *value;
    if (ptr != 0) {
        *value = ptr + delta;
    }
}

/* Relocate an embedded pointer while fn_802C61BC converts a model: add delta, but leave a zero (null) field untouched. */ void fn_802C6B14(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 ptr = *value;
    if (ptr != 0) {
        *value = ptr + delta;
    }
}

void fn_802C6B2C(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

/* Load a MODL model resource by path; on a swapped-endian load verify version
 * 12, flush the cache and byte-fix the data, and on a first reference walk its
 * group list. */
int fn_802C6B44(int modelPath) {
#define modlTag         0x4D4F444C
#define expectedVersion 0xC
#define fixupResource   fn_802C61BC
#define forEachGroup    VisitGroupIds
#define groupHook       fn_802D6C48
    void *modelData;
    int dataSize;
    u32 version;
    u8 swapEndian;
    u8 isNew;

    modelData = fn_8012C370(modelPath, modlTag, &version, &dataSize, &isNew, &swapEndian);
    if (modelData != 0) {
        if (swapEndian != 0) {
            if (version != expectedVersion) {
                Abend_Panic(lbl_8034B2E8, version, expectedVersion, modelPath);
            }
            DCStoreRangeNoSync(modelData, dataSize);
            fixupResource(modelData, modelPath);
        }
        if (isNew != 0) {
            forEachGroup(modelData, groupHook);
        }
        return (int)modelData;
    }
    Abend_Panic(lbl_8034B314, modelPath);
    return 0;
#undef modlTag
#undef expectedVersion
#undef fixupResource
#undef forEachGroup
#undef groupHook
}

#pragma dont_inline on
/* Release a model resource, with fn_802C5E6C called when its reference count reaches zero. */
int fn_802C6C20(int resource) {
    return fn_8012C4E4((void *)resource, (void *)fn_802C5E6C, resource);
}
#pragma dont_inline reset

/* Empty model-system hook, invoked once from the world/race init sequence
 * (fn_801E7984) alongside the other subsystem resets. This build needs no model
 * state set up here, so it does nothing. */
void fn_802C6C30(void) { }

/* Public accessor used across the game: hand an instance id to MRModel_GetInstanceGroupList and
 * return the model instance's group list (the +0x4 field of its 0x10-byte record)
 * as an opaque pointer. */
void *fn_802C6C34(int instanceId) { return (void *)MRModel_GetInstanceGroupList(instanceId); }

#pragma scheduling invalid_target
void fn_802C6C38(int modelId) {
    u8 *instance = (u8 *)MRModel_GetInstance(modelId);
    s32 groupOff, elementOff, groupIndex;
    u8 *group;
    s32 elementIndex;
    u8 *groupList, *groupTable, *elementTable, *element;
    u8 *displayNode;

    /* Release a model instance: decrement its refcount and, when it hits zero,
     * walk the instance's group/element tables to drop each display-node
     * reference, then clear its group and link pointers. */
    if (--*(s32 *)instance <= 0) {
        groupIndex = 0;
        groupOff = 0;
        goto outer_check;

    outer_setup:
        groupList = *(u8 **)(instance + 4);
        groupTable = *(u8 **)(groupList + 0xC);
        group = *(u8 **)(groupTable + groupOff);
        elementIndex = 0;
        elementOff = 0;
        goto inner_check;

    inner_body:
        elementTable = *(u8 **)(group + 4);
        element = *(u8 **)(elementTable + elementOff);
        displayNode = *(u8 **)(element + (*(s32 *)(instance + 8) << 2) + 0x14);
        *(u8 **)(element + (*(s32 *)(instance + 8) << 2) + 0x14) = 0;
        ModelDisplayNode_release((int *)displayNode);
        elementOff += 4;
        elementIndex++;

    inner_check:
        if (elementIndex < *(s32 *)group) goto inner_body;
        groupOff += 4;
        groupIndex++;

    outer_check:
        groupList = *(u8 **)(instance + 4);
        if (groupIndex < *(s32 *)(groupList + 8)) goto outer_setup;

        *(void **)(instance + 4) = 0;
        *(void **)(instance + 0xC) = 0;
    }
}
/* Release a loaded model instance: if the handle is MODEL_INVALID (-1), log a warning; otherwise fetch its group list, drop the instance reference, then release the group-list resource. */
void fn_802C6CF8(int modelHandle) {
    int groupList;
    if (modelHandle == -1) {
        ((int (*)(const char *, ...))fn_802E30C8)(lbl_8034B34C);
        return;
    }
    groupList = MRModel_GetInstanceGroupList();
    fn_802C6C38(modelHandle);
    fn_802C6C20(groupList);
}

/* Return 1 when any element in the model's group/element tables has a nonzero base id, else 0. */
s32 mrModelNeedsSubKeys(void *model) {
    s32 groupOff;
    s32 groupCount;
    s32 elementOff;
    s32 groupIndex;
    char *group;
    s32 elementCount;
    s32 elementIndex;
    groupCount = *(s32 *)((char *)model + 8);
    groupIndex = 0;
    groupOff = 0;
    while (groupIndex < groupCount) {
        group = *(char **)(*(char **)((char *)model + 0xC) + groupOff);
        elementCount = *(s32 *)group;
        for (elementIndex = 0, elementOff = 0; elementIndex < elementCount; elementIndex++, elementOff += 4) {
            char *element = *(char **)(*(char **)(group + 4) + elementOff);
            if (*(s32 *)element != 0) {
                return 1;
            }
        }
        groupOff += 4;
        groupIndex++;
    }
    return 0;
}

extern const char lbl_8034B378[];
extern const char lbl_8034B3A4[];
int fn_802C6DC4(int arg0, int arg1, int arg2, int arg3) {
    int count = gModelInstances[0];
    char *scan = (char *)(unsigned long)gModelInstances[2];
    char *found = 0;
    int i;
    char *empty = 0;

    for (i = 0; i < count; i++) {
        if (*(int *)scan > 0) {
            if (*(int *)(scan + 8) == arg2) {
                if ((u32)*(int *)(scan + 4) == (u32)arg1) {
                    found = scan;
                    break;
                }
            }
        } else {
            empty = scan;
        }
        scan += 0x10;
    }

    if (found == 0) {
        if (empty == 0) {
            int *context = gModelInstances;
            if (count < context[1]) {
                int next = gModelInstances[0];
                char *base = (char *)(unsigned long)context[2];
                gModelInstances[0] = next + 1;
                empty = base + next * 0x10;
            } else {
                empty = 0;
            }
            if (empty == 0) {
                Abend_Panic(lbl_8034B378);
            }
        }

        *(int *)empty = 0;
        *(int *)(empty + 4) = arg1;
        *(int *)(empty + 8) = arg2;
        *(int *)(empty + 0xC) = fn_802C5E7C((void *)(unsigned long)arg1);
        {
            int limit = *(int *)((char *)(unsigned long)arg1 + 0x18);
            if (arg2 >= limit) {
                Abend_Panic(lbl_8034B3A4, arg2, limit, arg0);
            }
        }

        {
            register int temp = mrModelNeedsSubKeys((void *)(unsigned long)arg1);
            register int outer = 0;
            arg0 = 0;
            for (; outer < *(int *)((char *)(unsigned long)arg1 + 8); arg0 += 4, outer++) {
                void **list = *(void ***)((char *)(unsigned long)arg1 + 0xC);
                char *sub = *(char **)((char *)list + arg0);
                register int inner = 0;
                arg2 = 0;
                for (; inner < *(int *)sub; arg2 += 4, inner++) {
                    void **items = *(void ***)(sub + 4);
                    void *item = *(void **)((char *)items + arg2);
                    if (*(u32 *)item == 7) {
                        fn_802C5C40((int *)item, *(int *)(empty + 8), *(int *)items);
                    } else {
                        fn_802C5CC4(item, *(int *)(empty + 8), temp, arg3);
                    }
                }
            }
        }
        found = empty;
    }

    (*(int *)found)++;
    return (int)(found - (char *)(unsigned long)gModelInstances[2]) / 0x10;
}

#pragma push
#pragma small_data off
#pragma pop
/* Registers a model's textures (mrModelRegisterTextures): visits every group in
 * groupList through VisitGroupIds with the per-group hook fn_802D6C48. */
void fn_802C6FA8(void *groupList) {
    ((void (*)(void *, void *))VisitGroupIds)(groupList, fn_802D6C48);
}

extern void fn_802D6C44(void);
void fn_802C6FB4(void *groupList) {
    /* Visit every group in groupList with the no-op per-group hook fn_802D6C44. */
    ((void (*)(void *, void *))VisitGroupIds)(groupList, fn_802D6C44);
}

#define DrawList_isOutsideScene fn_802C90E0
#define Abend_warn(fmt, arg) ((int (*)(const char *, ...))fn_802E30C8)(fmt, arg)
#define sModelLoadInSceneFmt lbl_8034B3DC
#define mrModelLoadResource fn_802C6B44
#define mrModelCreateInstance fn_802C6DC4

/* Loads a MODL model resource by path and creates a model instance, warning when called during an active scene render pass. */
void fn_802C6FC0(void *modelPath, int variantIdx, int createFlags) {
    if (DrawList_isOutsideScene() == 0) {
        Abend_warn(sModelLoadInSceneFmt, modelPath);
    }
    mrModelCreateInstance((int)modelPath, mrModelLoadResource((int)modelPath), variantIdx, createFlags);
}

/* Thunk: release the model instance with the given id by forwarding to
 * fn_802C6C38, which drops its refcount and frees its display nodes at zero. */
void fn_802C703C(int modelId) {
    fn_802C6C38(modelId);
}

int fn_802C90E0(void);
int fn_802E30C8(const char*, int);
extern const char lbl_8034B34C[];
int MRModel_GetInstanceGroupList();
int fn_802C6C20(int);
int fn_802C6B44(int);
extern const char lbl_8034B3DC[];
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);
void DrawModelInstance(int instanceId) {
    /* Draw one model instance if its stored world position passes the view-volume test. */
    float depth;
    unsigned char status;
    void *instanceHeader;

    if (instanceId != -1) {
        instanceHeader = *(void **)((char *)MRModel_GetInstance(instanceId) + 4);
        if (fn_802C94A0((char *)instanceHeader + 0x20, &status, &depth, *(float *)((char *)instanceHeader + 0x1C))) {
            fn_802C57B4(instanceId, 0, -1, status, depth);
        }
    }
}

#pragma opt_propagation reset
void fn_802C70AC(int arg0, void *arg1, int arg2, int arg3) {
    extern int fn_802D0514(void *);
    struct LocalResult {
        unsigned char status;
        unsigned char padding[3];
        float scalar;
        float vector[3];
    } local;
    const float *rot;
    float *out;
    const float *input;
    void *manager;
    void *groupHeader;
    int previousMask;
    int ok;

    if (arg0 == -1)
        return;
    previousMask = lbl_8055D008;
    lbl_8055D008 = arg3;
    manager = MRModel_GetInstance(arg0);
    groupHeader = *(void **)((char *)manager + 4);
    rot = (const float *)((char *)groupHeader + 0x20);
    out = local.vector;
    input = (const float *)arg1;
    if (out == rot) {
        float x, y, z;
        float m0, m3, m6, m1, m4, m7, m2, m5, m8;
        m3 = input[3];
        m4 = input[4];
        m5 = input[5];
        m0 = input[0];
        m1 = input[1];
        m2 = input[2];
        m6 = input[6];
        m7 = input[7];
        m8 = input[8];
        x = rot[0];
        y = rot[1];
        z = rot[2];
        out[0] = z * m6 + (x * m0 + y * m3);
        out[1] = z * m7 + (x * m1 + y * m4);
        out[2] = z * m8 + (x * m2 + y * m5);
    } else {
        float m10, m20, m00, m11, m01, m21, m12, m02, m22;
        float y;
        m10 = input[3];
        m00 = input[0];
        m20 = input[6];
        m11 = input[4];
        m01 = input[1];
        m21 = input[7];
        m12 = input[5];
        m02 = input[2];
        m22 = input[8];
        out[0] = rot[2] * m20 + (rot[0] * m00 + rot[1] * m10);
        y = rot[1];
        out[1] = rot[2] * m21 + (rot[0] * m01 + y * m11);
        y = rot[1];
        out[2] = rot[2] * m22 + (rot[0] * m02 + y * m12);
    }
    {
        float tx = out[0] + input[9];
        float ty = out[1] + input[10];
        float tz = out[2] + input[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
    ok = fn_802C94A0(out, &local.status, &local.scalar, *(float *)((char *)groupHeader + 0x1C));
    if (ok != 0)
        fn_802C57B4(arg0, fn_802D0514(arg1), arg2, local.status, local.scalar);
    lbl_8055D008 = previousMask;
}
extern unsigned char lbl_804C13C0[];
extern float lbl_80564EF0;
extern float PSVECSquareDistance(const float *, const float *);
/* For each type-2 group of the model, cull it by SPHL sphere distance and submit
 * its eligible elements through fn_802C53C4 / fn_802CC550 using the global context. */
/* Submit eligible elements of the model's type-2 groups for display, culling groups by SPHL sphere distance first. */ void fn_802C729C(int instanceId, float viewDistance) {
    char *groupEntry;
    int transformId;
    int j;
    int *elementList;
    int groupOffset;
    void *distanceVector;
    void *heightVector;
    int elementOffset;
    int *groupList;
    void *modelVectors;
    int groupIndex;
    float squareDistance;
    float baseRadius;

    if ((unsigned int)(*(unsigned int *)lbl_804C13C0 + 0x10000U) == 0xFFFFU)
        return;
    if (instanceId == -1)
        return;

    groupList = (int *)MRModel_GetInstanceGroupList(instanceId);
    if (*groupList <= 0)
        return;

    baseRadius = lbl_80564EF0;
    modelVectors = (void *)fn_802C5E7C(groupList);
    distanceVector = modelVectors;
    heightVector = modelVectors;

    for (groupIndex = 0, groupOffset = 0;
         groupIndex < *groupList;
         groupOffset += 0x10,
         distanceVector = (char *)distanceVector + 0x10,
         heightVector = (char *)heightVector + 0x10,
         groupIndex++) {
        if (*(int *)((char *)*(int **)((char *)groupList + 4) + groupOffset) != 2)
            continue;
        if (modelVectors != 0) {
            squareDistance = PSVECSquareDistance((float *)(lbl_804C13C0 + 4),
                                                 (float *)distanceVector);
            if (!(squareDistance < (viewDistance + *(float *)((char *)heightVector + 0xC)) *
                                    (viewDistance + *(float *)((char *)heightVector + 0xC))))
                continue;
        }

        j = 0;
        transformId = *(int *)lbl_804C13C0;
        elementOffset = 0;
        groupEntry = (char *)*(int **)((char *)groupList + 4) + groupOffset;
        elementList = *(int **)(groupEntry + 8);

        for (; j < *elementList;
             elementOffset += 4, j++) {
            int valid = 0;
            void **innerEntries = *(void ***)((char *)elementList + 4);
            void *element = *(void **)((char *)innerEntries + elementOffset);
            unsigned int type = *(unsigned int *)element;

            if (type < 13) {
                int skip;
                valid = 1;
                switch (type) {
                case 4:
                case 6:
                case 9:
                case 11:
                    skip = 1;
                    break;
                default:
                    skip = 0;
                    break;
                }
                if (skip)
                    valid = 0;
            }
            if (valid) {
                void *node = *(void **)((char *)element + 0x14);
                void *r4;
                fn_802C53C4(groupEntry, node, transformId, -1, 0);
                r4 = ((void *(*)(void *))fn_802C57B0)(
                    *(void **)(groupEntry + 0xC));
                fn_802CC550(*(int *)node, r4, baseRadius,
                            *(float *)((char *)r4 + 0x18));
            }
        }
    }
}

/* Set a model instance's world transform from a caller-supplied 3x4 matrix,
   using the default draw entry id (-1) and the all-groups mask (-1). */
void fn_802C744C(int instanceId, void *transform) {
    fn_802C70AC(instanceId, transform, -1, -1);
}

/* Draw a model instance with a temporary group mask: test its stored transform
   against the view and submit it for drawing if visible, then restore the mask. */
/* Draw one model instance under a temporary group mask: set the mask, view-cull the instance, submit it if visible, then restore the previous mask. */ void fn_802C7458(int instanceId, int groupMask) {
    float distance;
    unsigned char visibilityStatus;
    int savedGroupMask;
    void *groupHeader;

    if (instanceId != -1) {
        savedGroupMask = lbl_8055D008;
        lbl_8055D008 = groupMask;
        groupHeader = *(void **)((char *)MRModel_GetInstance(instanceId) + 4);
        if (fn_802C94A0((char *)groupHeader + 0x20, &visibilityStatus, &distance, *(float *)((char *)groupHeader + 0x1C))) {
            fn_802C57B4(instanceId, 0, -1, visibilityStatus, distance);
        }
        lbl_8055D008 = savedGroupMask;
    }
}

#pragma scheduling on
void fn_802C74D8(int arg0, void *arg1, int arg2) {
#pragma scheduling invalid_target
    int i;
    struct LocalResult {
        unsigned char status;
        unsigned char padding[3];
        float scalar;
        float vector[3];
    } local;
    void *entry;
    void *node;
    float *rot;
    float *out;
    float *input;
    int a2 = arg2;
    void *a1 = arg1;
    void *inst = MRModel_GetInstance(arg0);
    rot = (float *)((char *)*(void **)((char *)inst + 4) + 0x20);
    entry = *(void **)((char *)inst + 4);
    out = local.vector;
    input = (float *)a1;
    if (local.vector == rot) {
        float y0 = input[3];
        float y1 = input[4];
        float y2 = input[5];
        float x0 = input[0];
        float x1 = input[1];
        float x2 = input[2];
        float z0 = input[6];
        float z1 = input[7];
        float z2 = input[8];

        float my0 = rot[1] * y0;
        float my1 = rot[1] * y1;
        float mx0 = rot[0] * x0;
        float mx1 = rot[0] * x1;
        float mx2 = rot[0] * x2;
        float my2 = rot[1] * y2;
        float mz0 = rot[2] * z0;
        float mz1 = rot[2] * z1;
        float mz2 = rot[2] * z2;

        out[0] = mz0 + (mx0 + my0);
        out[1] = mz1 + (mx1 + my1);
        out[2] = mz2 + (mx2 + my2);
    } else {
        out[0] = rot[2] * input[6] + (rot[0] * input[0] + rot[1] * input[3]);
        out[1] = rot[2] * input[7] + (rot[1] * input[4] + rot[0] * input[1]);
        out[2] = rot[2] * input[8] + (rot[1] * input[5] + rot[0] * input[2]);
    }
    {
        float tx = out[0] + input[9];
        float ty = out[1] + input[10];
        float tz = out[2] + input[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
    if (fn_802C94A0(out, &local.status, &local.scalar, rot[-1])) {
        if ((u8)lbl_8055FC20 != 0) {
            node = fn_802C5EFC(a2);
            a1 = (void *)fn_802D0514(a1);
            for (i = 0; i < *(int *)entry; i++) {
                char *item = *(char **)((char *)entry + 4) + i * 0x10;
                fn_802C53C4(item, node, (int)a1, -1, local.status);
            }
        } else {
            fn_802C8B98(a2, a1);
            fn_802DB2BC(local.status);
            for (i = 0; i < *(int *)entry; i++) {
                char *item = *(char **)((char *)entry + 4) + i * 0x10;
                fn_802D6B08(*(int *)(item + 0xC));
            }
            DrawList_RestoreNormalMode();
        }
    }
}
 extern void fn_802DABA4(const float *);
/* Forward the caller's six-float model transform to fn_802DABA4, which
 * scales it into a 12-float array and queues it as a draw record.  It is a
 * tail call, so the transform pointer simply stays in r3. */
void fn_802C7730(const float *transform) { fn_802DABA4(transform); }

/* Queue the caller's 12-float model transform as a draw record, then select it
 * as the current GX state: fn_802D0514 returns the new record's handle and
 * fn_802D0610 applies that record. */
/* Queue the caller's 12-float model transform as a draw record, then select it as the current GX state. */ void MRModelSetTransform(void *transform) {
    fn_802D0610(fn_802D0514(transform));
}

void fn_802C7758(void);
#pragma dont_inline fn_802C7758
/* Select the default GX material/vertex state (null record handle) instead of a transform record. */
void fn_802C7758(void) {
    fn_802D0610(0);
}

/* Copies six float fields (offsets 0x2C-0x40) from a model entry to output parameters. */
/* Read the six bounding-box floats at +0x2C..+0x40 of the model instance's data into the six output pointers. */ void fn_802C7760(void *modelId, f32 *bound0, f32 *bound1, f32 *bound2, f32 *bound3, f32 *bound4, f32 *bound5) {
    void *entry = MRModel_GetInstance((int)modelId);
    *bound0 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x2C);
    *bound1 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x30);
    *bound2 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x34);
    *bound3 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x38);
    *bound4 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x3C);
    *bound5 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x40);
}

#pragma dont_inline fn_802C7760
void fn_802C77F0(void *model, f32 *out) {
    /* Read the model's six bounding-box values (min/max per axis) into out[0..5]. */
    fn_802C7760(model, out, out + 1, out + 2, out + 3, out + 4, out + 5);
}

/* Return the model instance's view tolerance (+0x1C of its group list) - the
 * threshold passed to the visibility/culling test in fn_802C94A0. */
float getModelInstanceTolerance(int instanceId) {
    struct ModelInstance *instance = (struct ModelInstance *)MRModel_GetInstance(instanceId);
    return *(float *)((char *)instance->groups + 0x1C);
}

/* Parse a NUL-terminated hexadecimal string (0-9 and uppercase A-F) into an
 * integer: shift the result left four bits per character and OR in its digit. */
/* Parse a NUL-terminated hexadecimal string (0-9 and uppercase A-F) into an integer: shift the result left four bits per character, then OR in that character's digit value. */ s32 parseHexString(char *hexString) {
    s32 result = 0;
    s32 digit;
    s32 isDigit;
    u8 ch;
    while (*hexString != 0) {
        result <<= 4;
        ch = *hexString;
        isDigit = 0;
        if ((s8)ch >= '0' && (s8)ch <= '9')
            isDigit = 1;
        digit = (s8)ch - '7';
        if (isDigit != 0)
            digit = (s8)ch - '0';
        result |= digit;
        hexString++;
    }
    return result;
}

#pragma scheduling on
/* Register `recordCount` 0x2C-byte model resource name-override records from `records` into the name-override table lbl_804C13B4 ({used count, capacity, base} of 0x2C-byte entries). Each record holds a 16-byte lookup name at +0, an id at +0x10, a 16-byte replacement name at +0x14, and a back-reference pointer at +0x28 that is cleared to -1 on copy. The next free entry is taken for each record; bytes are moved individually so the copy is safe even if the source overlaps the table. */ void fn_802C7888(void *records, s32 recordCount)
{
  /* Copy `count` 0x2C-byte model records from `src` into the model-entry pool
   * lbl_804C13B4 (used-count at +0, capacity at +4, base at +8), taking the next
   * free entry for each record.  Each record's +0x28 word is a back-pointer key
   * that is reset to -1 on copy.  The bytes are moved one at a time so that the
   * copy is safe even when the source overlaps the pool. */
  for (; recordCount > 0; recordCount--)
  {
    volatile u8 *recordBytes = (volatile u8 *) records;
    volatile u8 *entryBytes;
    s32 entryIndex;
    s32 *backRef = *((s32 **) (((u8 *) records) + 0x28));
    u8 a;
    u8 b;
    u32 idWord;
    u32 word24;
    u32 keyWord;
    if (backRef != 0)
    {
      *backRef = -1;
    }
    entryIndex = lbl_804C13B4[0];
    if (entryIndex < lbl_804C13B4[1])
    {
      s32 offset = entryIndex * 0x2C;
      unsigned char *base = (unsigned char *) ((unsigned long) lbl_804C13B4[2]);
      lbl_804C13B4[0] = entryIndex + 1;
      entryBytes = (volatile u8 *) (base + offset);
    }
    else
    {
      entryBytes = 0;
    }
    a = recordBytes[0];
    b = recordBytes[1];
    entryBytes[0] = a;
    a = recordBytes[2];
    entryBytes[1] = b;
    b = recordBytes[3];
    entryBytes[2] = a;
    a = recordBytes[4];
    entryBytes[3] = b;
    b = recordBytes[5];
    entryBytes[4] = a;
    a = recordBytes[6];
    entryBytes[5] = b;
    b = recordBytes[7];
    entryBytes[6] = a;
    a = recordBytes[8];
    entryBytes[7] = b;
    b = recordBytes[9];
    entryBytes[8] = a;
    a = recordBytes[10];
    entryBytes[9] = b;
    b = recordBytes[11];
    entryBytes[10] = a;
    a = recordBytes[12];
    entryBytes[11] = b;
    b = recordBytes[13];
    entryBytes[12] = a;
    a = recordBytes[14];
    entryBytes[13] = b;
    b = recordBytes[15];
    entryBytes[14] = a;
    *(u32 *)&idWord = *(volatile u32 *)(recordBytes + 0x10);
    entryBytes[15] = b;
    b = recordBytes[0x14];
    *((volatile u32 *) (entryBytes + 0x10)) = *(u32 *)&idWord;
    a = recordBytes[0x15];
    entryBytes[0x14] = b;
    b = recordBytes[0x16];
    entryBytes[0x15] = a;
    a = recordBytes[0x17];
    entryBytes[0x16] = b;
    b = recordBytes[0x18];
    entryBytes[0x17] = a;
    a = recordBytes[0x19];
    entryBytes[0x18] = b;
    b = recordBytes[0x1A];
    entryBytes[0x19] = a;
    a = recordBytes[0x1B];
    entryBytes[0x1A] = b;
    b = recordBytes[0x1C];
    entryBytes[0x1B] = a;
    a = recordBytes[0x1D];
    entryBytes[0x1C] = b;
    b = recordBytes[0x1E];
    entryBytes[0x1D] = a;
    a = recordBytes[0x1F];
    entryBytes[0x1E] = b;
    b = recordBytes[0x20];
    entryBytes[0x1F] = a;
    a = recordBytes[0x21];
    entryBytes[0x20] = b;
    b = recordBytes[0x22];
    entryBytes[0x21] = a;
    a = recordBytes[0x23];
    entryBytes[0x22] = b;
    word24 = *((volatile u32 *) (recordBytes + 0x24));
    entryBytes[0x23] = a;
    keyWord = *((volatile u32 *) (recordBytes + 0x28));
    records = ((u8 *) records) + 0x2C;
    *((volatile u32 *) (entryBytes + 0x24)) = word24;
    *((volatile u32 *) (entryBytes + 0x28)) = keyWord;
  }

}
extern int lbl_804C13B4[];
extern void fn_802C7A00(void);
void fn_802C7A00(void) {
    /* Reset the used-count at +0 of the model entry pool lbl_804C13B4, emptying it. */
    lbl_804C13B4[0] = 0;
}

/* Diagnostic helper: returns the resource name of the model at the given index
   (carried in the pointer-typed argument) for use in debug printf calls. */
/* Diagnostic helper: return the resource name of the model instance at instanceId (via its group node) for debug printf calls. */ /* Diagnostic helper: return the resource name of the model instance at the given index (via its group node) for debug printf calls. */ void MRModel_GetResourceName(void* instanceId) {
    fn_8012C58C(MRModel_GetInstanceGroupList(instanceId));
}

/* Tail-call thunk: branches to fn_802DA704, the stack-allocator helper that
 * queues a kind-7 record with 12 bytes (a vec3) per element in the
 * BoneHandleAlloc arena; the caller's arguments pass straight through. */
void fn_802C7A34(void) { fn_802DA704(); }

extern void fn_802DA80C(void);
/* Tail-call thunk: forward to fn_802DA80C, the model stack-record allocator
   (records of 0x30 bytes per element, tagged kind 7). */
void fn_802C7A38(void) { fn_802DA80C(); }

extern void fn_802DA918(void);
/* Tail-call thunk: branches to the stack-allocator helper fn_802DA918, which
 * queues a three-float record {x, y, 1/(z*z)} in the BoneHandleAlloc arena.
 * The float arguments (f1-f3) pass straight through the branch; callers use
 * this as void *(*)(float, float, float). */
void fn_802C7A3C(void) { fn_802DA918(); }

extern void fn_802DA80C(void);
extern void fn_802DA918(void);
extern void fn_802DA550(void);
/* Tail-call thunk: branches straight to fn_802DA550, the stack-allocator helper
 * callers know as NewPartKey, which allocates a part-name key record. All six
 * arguments pass through unchanged; callers declare this with the same signature. */
void fn_802C7A40(void) { fn_802DA550(); }

extern s8 lbl_8055FC20;
extern void fn_802C543C(void);
/* Begin a model-draw batch: mark submits as batched and empty the display
 * entry pool (fn_802C543C) — paired with submitModelBatch, which submits and clears. */
void fn_802C7A44(void) {
#define s_modelBatchActive lbl_8055FC20
    s_modelBatchActive = 1;
#undef s_modelBatchActive
    fn_802C543C();
}

/* End a model draw batch: refresh all nine sort groups (level 0 means all) and clear the batch-active flag set by fn_802C7A44. */ /* End a model draw batch: refresh all nine sort groups (level 0 means all) and clear the batch-active flag set by fn_802C7A44. */ void submitModelBatch(void) {
#define s_modelBatchActive lbl_8055FC20
    /* Submit all nine model sort groups and clear the batch flag. */
    int groupId = 0;

    do {
        fn_802C5720(groupId);
        groupId++;
    } while (groupId < 9);
    s_modelBatchActive = 0;
#undef s_modelBatchActive
}

/* Restore the default GX material state, then release the model display entries for the given sort group; for the extra group 9 also empty the display-entry pool. */
void fn_802C7A94(int groupId) {
    fn_802C7758();
    fn_802C5720(groupId);
    if (groupId == 9) {
        fn_802C543C();
    }
}

#pragma dont_inline on
/* End a run of model draws: reset sort group 9, the extra group that is not
 * part of submitModelBatch's nine, which also empties the display entry pool
 * (fn_802C543C).  Callers pair it with fn_802C7A44, which starts a batch. */
void fn_802C7AD4(void) {
    fn_802C7A94(9);
}
#pragma dont_inline reset
void fn_802D754C(void);
/* Tail-call alias: forwards the game-mode flag bit (in r3) to fn_802D754C, which stores it to a global. */
void fn_802C7ADC(void) { fn_802D754C(); }

#pragma opt_propagation off
void fn_802C7AE0(int arg0, void *arg1, int arg2, float farg0) {
    int i;
    struct {
        unsigned char status;
        float vector[3];
    } local;
    void *manager;
    void *entry;
    float *rot;
    float *input;

    manager = MRModel_GetInstance(arg0);
    local.status = 1;
    rot = (float *)((char *)*(void **)((char *)manager + 4) + 0x20);
    input = (float *)arg1;
    if (local.vector == rot) {
        float x, y, z;
        float m0, m3, m6, m1, m4, m7, m2, m5, m8;
        m3 = input[3];
        m4 = input[4];
        m5 = input[5];
        m0 = input[0];
        m1 = input[1];
        m2 = input[2];
        m6 = input[6];
        m7 = input[7];
        m8 = input[8];
        x = rot[0];
        y = rot[1];
        z = rot[2];
        local.vector[0] = z * m6 + (x * m0 + y * m3);
        local.vector[1] = z * m7 + (x * m1 + y * m4);
        local.vector[2] = z * m8 + (x * m2 + y * m5);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        float y;
        m10 = input[3];
        m00 = input[0];
        m20 = input[6];
        m11 = input[4];
        m01 = input[1];
        m21 = input[7];
        m12 = input[5];
        m02 = input[2];
        m22 = input[8];
        local.vector[0] = rot[2] * m20 + (rot[0] * m00 + rot[1] * m10);
        y = rot[1];
        local.vector[1] = rot[2] * m21 + (rot[0] * m01 + y * m11);
        y = rot[1];
        local.vector[2] = rot[2] * m22 + (rot[0] * m02 + y * m12);
    }
    {
        float tx = local.vector[0] + input[9];
        float ty = local.vector[1] + input[10];
        float tz = input[11] + local.vector[2];
        local.vector[0] = tx;
        local.vector[1] = ty;
        local.vector[2] = tz + 0.0f;
    }
    {
        float *vec = fn_802C9A40();
        float scale = lbl_80564EF4 * farg0;
        local.vector[0] += vec[0] * scale;
        local.vector[1] += vec[1] * scale;
        local.vector[2] += vec[2] * scale;
        if (fn_802C9638(local.vector, &local.status, scale + *(float *)((char *)*(void **)((char *)manager + 4) + 0x1C)) != 0) {
            fn_802D6C4C(farg0);
            fn_802DB2BC(local.status);
            MRModelSetTransform(arg1);
            entry = fn_802C6C34(arg0);
            for (i = 0; i < *(int *)entry; i++) {
                char *item = *(char **)((char *)entry + 4) + i * 0x10;
                if (arg2 & (1 << *(int *)item)) {
                    fn_802D6B08(*(int *)(item + 0xC));
                }
            }
        }
    }
}
#pragma opt_propagation reset
extern signed char lbl_8055FC20;
extern int fn_802C9C58(int);
extern void *fn_802C86DC(void);
extern float PSQUATMultiply(void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
void fn_802C7D54(int arg0, const float *arg1, int arg2, float fa, float fb, float fc) {
    struct ModelInstance *instance;
    unsigned char entryStatus;
    int j;
    struct ElementList *inner_info;
    int offset;
    int nodeSlotOffset;
    int inner_offset;
    struct GroupList *groups;
    int i;
    struct GroupEntry *entry;
    struct {
        unsigned char status;
        unsigned char pad[3];
        float scalar;
        float vec2[3];
        float vec1[3];
    } local;
    void *instance2;
    void *r21;
    int r20;
    const float *rot;
    float *out;
    const float *input;
    float savedScalar;
    int savedCull;
    int savedMask;
    float *groupOut;
    r21 = ((void *(*)(float, float, float))fn_802C7A3C)(fa, fb, fc);
    savedCull = fn_802C9C58(arg2);
    savedMask = lbl_8055D008;
    lbl_8055D008 = 8;
    instance2 = MRModel_GetInstance(arg0);
    instance = (struct ModelInstance *)instance2;
    rot = (const float *)((char *)*(void **)((char *)instance2 + 4) + 0x20);
    out = local.vec1;
    input = arg1;
    if (out == rot) {
        float y0 = input[3] * rot[1];
        float y1 = input[4] * rot[1];
        float x0 = input[0] * rot[0];
        float x1 = input[1] * rot[0];
        float x2 = input[2] * rot[0];
        float y2 = input[5] * rot[1];
        float z0 = input[6] * rot[2];
        float z1 = input[7] * rot[2];
        float z2 = input[8] * rot[2];
        out[0] = (x0 + y0) + z0;
        out[1] = (x1 + y1) + z1;
        out[2] = (x2 + y2) + z2;
    } else {
        out[0] = (input[3] * rot[1] + input[0] * rot[0]) + input[6] * rot[2];
        out[1] = (input[4] * rot[1] + input[1] * rot[0]) + input[7] * rot[2];
        out[2] = (input[5] * rot[1] + input[2] * rot[0]) + input[8] * rot[2];
    }
    {
        float tx = out[0] + input[9];
        float ty = out[1] + input[10];
        float tz = out[2] + input[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
    if (fn_802C94A0(out, &local.status, &local.scalar, rot[-1]) != 0) {
        r20 = fn_802D0514((void *)arg1);
        if ((unsigned char)lbl_8055FC20 == 0) {
            fn_802C543C();
        }
        groups = instance->groups;
        nodeSlotOffset = instance->nodeSlot << 2;
        groupOut = local.vec2;
        for (i = 0, offset = 0; i < groups->count; offset += 0x10, i++) {
            int bitIndex;
            int ok;
            char *posBase;
            entry = (struct GroupEntry *)(groups->items + offset);
            bitIndex = entry->bitIndex;
            if (lbl_8055D008 & (1 << bitIndex)) {
                entryStatus = local.status;
                posBase = instance->groupPositions;
                if (posBase == 0) {
                    ok = 1;
                } else {
                    const float *grot = (const float *)(posBase + offset);
                    if (groupOut == grot) {
                        float y0 = input[3] * grot[1];
                        float y1 = input[4] * grot[1];
                        float x0 = input[0] * grot[0];
                        float x1 = input[1] * grot[0];
                        float x2 = input[2] * grot[0];
                        float y2 = input[5] * grot[1];
                        float z0 = input[6] * grot[2];
                        float z1 = input[7] * grot[2];
                        float z2 = input[8] * grot[2];
                        groupOut[0] = (x0 + y0) + z0;
                        groupOut[1] = (x1 + y1) + z1;
                        groupOut[2] = (x2 + y2) + z2;
                    } else {
                        groupOut[0] = (input[3] * grot[1] + input[0] * grot[0]) + input[6] * grot[2];
                        groupOut[1] = (input[4] * grot[1] + input[1] * grot[0]) + input[7] * grot[2];
                        groupOut[2] = (input[5] * grot[1] + input[2] * grot[0]) + input[8] * grot[2];
                    }
                    {
                        float tx = groupOut[0] + input[9];
                        float ty = groupOut[1] + input[10];
                        float tz = groupOut[2] + input[11];
                        groupOut[0] = tx;
                        groupOut[1] = ty;
                        groupOut[2] = tz;
                    }
                    {
                        float dist = PSQUATMultiply(groupOut, (char *)fn_802C86DC() + 0x24);
                        float tol = *(const float *)(posBase + offset + 12);
                        ok = (dist - tol) < fc;
                    }
                }
                if (ok == 0)
                    continue;
                savedScalar = local.scalar;
                inner_info = entry->elements;
                for (j = 0, inner_offset = 0; j < inner_info->count; inner_offset += 4, j++) {
                    int valid = 0;
                    struct ModelElement *elem = (struct ModelElement *)*(void **)(inner_info->items + inner_offset);
                    unsigned int type = elem->type;
                    if (type < 13) {
                        int skip;
                        valid = 1;
                        switch (type) {
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            skip = 1;
                            break;
                        default:
                            skip = 0;
                            break;
                        }
                        if (skip) valid = 0;
                    }
                    if (valid) {
                        void *node = *(void **)(nodeSlotOffset + (int)elem + 0x14);
                        void *r4;
                        fn_802C53C4(entry, node, r20, (int)r21, entryStatus);
                        r4 = ((void *(*)(void *))fn_802C57B0)((void *)entry->id);
                        fn_802CC550(*(int *)node, r4, savedScalar, *(float *)((char *)r4 + 0x18));
                    }
                }
            }
        }
        if ((unsigned char)lbl_8055FC20 == 0) {
            fn_802C5720(-1);
        }
    }
    lbl_8055D008 = savedMask;
    fn_802C9C58(savedCull);
}
#pragma pop
/* Sets lbl_8055D00C, the model manager's mode selector: 1 normally, 2 when
 * the caller requests the alternate mode (non-zero flag). */
void fn_802C8218(s32 useAltMode) {
    s32 mode;

    mode = 1;
    if (useAltMode != 0) {
        mode = 2;
    }
    lbl_8055D00C = mode;
}

/* mrmodel: forward to the model-manager hook (fn_802DB2B4), a no-op in this build. */
void fn_802C8230(void) {
    fn_802DB2B4();
}

extern void fn_802DB2B8(void);
/* mrmodel: forward the water-amplitude config value to the model-config setter
 * (fn_802DB2B8, a no-op in this build). */
void fn_802C8234(float amplitude) { fn_802DB2B8(); }

extern int lbl_8055D008;
extern int fn_8012C4E4(void *, void *, int);

