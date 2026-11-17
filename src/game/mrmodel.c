// mrmodel — model resource (mrModelLoad/Unload/End, ModelInfo).
// Recovered TU window 0x802C5390..0x802C8238+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802C8238 (+ .ctors slot 0x802ED5A4) remains in
// auto/text_802C8238_.c pending a promotion pass.
#include "types.h"
extern void fn_802CC550(int, void *, float, float);
extern void *fn_8012C370(int, int, u32 *, int *, u8 *, u8 *);
extern void fn_802E317C(const char *, ...);
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
void fn_802C5DF0(void *, void *);
extern int lbl_8055D008;
void* fn_802C5390(int);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);

extern int lbl_8055D00C;
extern void fn_802DB2B4(void);
extern int lbl_804C1338[];
extern unsigned char lbl_804C1348[];
struct Entry16 {
    char data[16];
};
extern int lbl_804C139C[];
extern int lbl_804C13A8[];
extern int lbl_804C13B4[];
extern const char lbl_8034B1D8[];
extern s8 lbl_8055FC20;
extern s8 lbl_8055FC21;
extern void fn_802C8B98(int, void *);
extern int fn_802D0514(void *);
char *fn_802CAE34(char *);
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
 * lbl_804C139C is the {count, capacity, base} of the model instances and
 * fn_802C5390(id) returns base + id * 0x10, one ModelInstance.  Its groups are
 * the GroupEntry records listed by the {count, items} header at +0x04; the
 * instance's own 4x3 world matrix and view tolerance follow that header at
 * +0x1C and +0x20 (fn_802C70AC transforms a caller's matrix into them).  Each
 * group holds the ModelElements of the model that belong to it, and an element
 * keeps one display-node pointer per instance from +0x14.  fn_802C53C4 links a
 * display entry into a node's list and fn_802C5720 sorts those entries and
 * submits them; lbl_8055FC20 says whether the caller is batching the submits
 * (fn_802C7A44 sets it, fn_802C7A50 clears it), and lbl_8055D008 is the mask of
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
void *fn_802C5390(int instanceId) {
    /* Return the 0x10-byte ModelInstance record at instanceId. */
    u32 instances = *(u32 *)((char *)lbl_804C139C + 8);
    return (void *)(instances + (instanceId << 4));
}
#pragma scheduling off
int fn_802C53A8(instanceId)
int instanceId;
{
    /* Return the group list (+0x4) of a model instance by id, from the instance table's 0x10-byte records. */
    int *instances = *(int * volatile *)((char *)lbl_804C139C + 8);
    return *(int *)((char *)instances + (instanceId << 4) + 4);
}
#pragma scheduling invalid_target
void fn_802C53C4(void *a, void *b, int x, int y, unsigned char z) {
    register int count = lbl_804C1338[0];
    register int limit = lbl_804C1338[1];
    register unsigned char *entry;
    if (count < limit) {
        register unsigned char *base = (unsigned char *)(unsigned long)lbl_804C1338[2];
        register int offset = count * 0x14;
        lbl_804C1338[0] = count + 1;
        entry = base + offset;
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
int fn_802C544C(void **a, void **b) {
    void *right = *b;
    void *left = *a;
    short x = *(short *)((char *)right + 6);
    short y = *(short *)((char *)left + 6);
    if (y != x) return y - x;
    return stricmp(fn_802CAE34(*(char **)left), fn_802CAE34(*(char **)right));
}
/* Return the 8-byte {items, count} record for a 1-based detail level in the
 * level table at lbl_804C1348 (levels 1..9). */
void *fn_802C54B4(int level) { return (void *)(lbl_804C1348 + (level - 1) * 8); }

/* Return bits 8-15 (the second byte) of the given value as an unsigned byte. */
unsigned char fn_802C54CC(unsigned int value) { return (unsigned char)(value >> 8); }

#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802C54D4(void) {
    extern int lbl_804C1390[];
    extern int lbl_804C13A8[];
    extern s8 lbl_8055FC21;
    extern void qsort(void *, unsigned int, unsigned int, int (*)(void *, void *));
    int level;
    int sourceOffset;
    int sourceIndex;
    int itemIndex;
    int count;
    int oldCount;
    int itemOffset;
    register void **items;
    void *table;

    if (*(volatile unsigned char *)&lbl_8055FC21 == 0)
        return;
    {
        int *listData = lbl_804C1390;
        int *sourceData = lbl_804C13A8;
        void **slot;
        lbl_804C1390[0] = 0;
        for (sourceIndex = 0, sourceOffset = 0;
             sourceIndex < *(volatile int *)sourceData;
             sourceOffset += 0x10, sourceIndex++) {
            void *base = (void *)(unsigned long)*(volatile u32 *)((char *)sourceData + 8);
            void *entry = (char *)base + sourceOffset;
            if (*(unsigned short *)((char *)entry + 4) != 0) {
                register oldCount = lbl_804C1390[0];
                if (oldCount < lbl_804C1390[1]) {
                    count = oldCount + 1;
                    lbl_804C1390[0] = count;
                    slot = (void **)((char *)(void *)lbl_804C1390[2] + (oldCount << 2));
                } else {
                    slot = 0;
                }
                if (slot)
                    *slot = entry;
            }
        }
    }

    count = lbl_804C1390[0];
    items = (void **)*(void **)((char *)lbl_804C1390 + 8);
    qsort(items, count, 4, (int (*)(void *, void *))fn_802C544C);
    level = 1;
    table = fn_802C54B4(level);
    *(void **)table = *(void **)((char *)lbl_804C1390 + 8);
    for (itemIndex = 0, itemOffset = 0;
         itemIndex < lbl_804C1390[0];
         itemIndex++, itemOffset += 4) {
        void *entry = *(void **)((char *)*(void ***)((char *)lbl_804C1390 + 8) + itemOffset);
        goto inner_check;
inner_loop:
        level++;
        count = (int)((char *)*(void ***)((char *)lbl_804C1390 + 8) + itemOffset -
                      (char *)*(void **)table) / 4;
        *(int *)((char *)table + 4) = count;
        table = fn_802C54B4(level);
        *(void **)table = (char *)*(void ***)((char *)lbl_804C1390 + 8) + itemOffset;
inner_check:
        if (level < ((int (*)(unsigned int))fn_802C54CC)(
                        *(short *)((char *)entry + 6))) {
            if (level <= 9)
                goto inner_loop;
        }
    }
    count = (int)((char *)*(void ***)((char *)lbl_804C1390 + 8) +
                  lbl_804C1390[0] * 4 - (char *)*(void **)table) / 4;
    *(int *)((char *)table + 4) = count;
    while (++level <= 9) {
        table = fn_802C54B4(level);
        *(int *)((char *)table + 4) = 0;
    }
    *(volatile unsigned char *)&lbl_8055FC21 = 0;
}
#pragma use_lmw_stmw on
#pragma dont_inline reset
#pragma scheduling on

extern void fn_802C8B70(int);
extern void fn_802C8D74(void);
extern void fn_802D0610(int);
extern void fn_802D6B08(int);
extern void fn_802DAA18(void);
extern void fn_802DB2BC(unsigned char);
extern int lbl_804C139C[];
/* Tear down this model/resource list: release its handle, destroy each node's resources, then clear the head. */
void fn_802C5690(void *obj) {
    void *node;
    if (*(int *)((char *)obj + 8) != 0) {
        fn_802C8B70(*(int *)obj);
        node = *(void **)((char *)obj + 8);
        while (node != 0) {
            fn_802D0610(*(int *)((char *)node + 8));
            if ((unsigned int)(*(int *)((char *)node + 12) + 0x10000) != 0xFFFF) {
                fn_802DAA18();
            }
            fn_802DB2BC(*(unsigned char *)((char *)node + 4));
            fn_802D6B08(*(int *)node);
            node = *(void **)((char *)node + 16);
        }
        fn_802C8D74();
        *(int *)((char *)obj + 8) = 0;
    }
}

extern void fn_802C54D4(void);
extern int lbl_804C1390[];
#pragma dont_inline on
#pragma dont_inline on
/* Refreshes model entries for a specific group (>0) or all groups, then notifies DB. */
void fn_802C5720(int groupId) {
    int count;
    void **items;
    int i;
    fn_802C54D4();
    if (groupId > 0) {
        void *entry = fn_802C54B4(groupId);
        items = *(void ***)entry;
        count = *(int *)((char *)entry + 4);
    } else {
        count = lbl_804C1390[0];
        items = *(void ***)(lbl_804C1390 + 2);
    }
    for (i = 0; i < count; i++) {
        fn_802C5690(items[i]);
    }
    fn_802DB2BC(1);
}
#pragma dont_inline reset

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
    struct ElementList *inner_info;
    int offset;
    int nodeSlotOffset;
    int inner_offset;
    struct GroupList *groups;
    int i;
    struct GroupEntry *entry;

    instance = (struct ModelInstance *)fn_802C5390(instanceId);
    groups = instance->groups;
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C543C();
    }
    nodeSlotOffset = instance->nodeSlot << 2;
    for (i = 0, offset = 0; i < groups->count; offset += 0x10, i++) {
        int bitIndex;
        entry = (struct GroupEntry *)(groups->items + offset);
        bitIndex = entry->bitIndex;
        if (lbl_8055D008 & (1 << bitIndex)) {
            unsigned char localStatus = status;
            char *positions = instance->groupPositions;
            if (positions == 0 || fn_802C9638(positions + offset, &localStatus, *(float *)(positions + offset + 12)) != 0) {
                entryStatus = localStatus;
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
                        fn_802C53C4(entry, node, transformId, entryId, entryStatus);
                        r4 = ((void *(*)(void *))fn_802C57B0)((void *)entry->id);
                        fn_802CC550(*(int *)node, r4, distance, *(float *)((char *)r4 + 0x18));
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
void fn_802C595C(char *outName, int maxLen, const char *lookupName, int id) {
    /* Resolve a resource name through the (name,id) override table, bounded-copying
       the replacement into outName, or the original name when there is no override. */
    int entryOffset;
    int entryIndex;
    char *entry;
    register const unsigned char *copySrc;
    unsigned char ch;
    entryIndex = 0;
    entryOffset = 0;
    goto table_check;
table_loop:
    entry = (char *)(unsigned long)lbl_804C13B4[2] + entryOffset;
    if (stricmp(lookupName, entry) == 0) {
        if (id == *(int *)(entry + 0x10)) {
            copySrc = (const unsigned char *)(entry + 0x14);
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
u16 fn_802C5A50(int high, int low) {
    return (u16)((high << 8) | low);
}

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
    struct Entry *freeEntry = 0;
    struct Entry *match = 0;
    int one = 1;
    int zero = 0;
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
                int next = *(volatile int *)&lbl_804C13A8[0];
                void *base = *(void * volatile *)&lbl_804C13A8[2];
                lbl_804C13A8[0] = next + 1;
                freeEntry = (struct Entry *)((char *)base + next * 0x10);
            } else {
                freeEntry = 0;
            }
            if (freeEntry == 0) {
                fn_802E317C(lbl_8034B1D8);
            }
            freeEntry->key0 = savedArg0;
        }
        freeEntry->refs = zero;
        match = freeEntry;
        freeEntry->key2 = arg2;
        freeEntry->reserved = zero;
        freeEntry->key1 = arg1;
        lbl_8055FC21 = one;
    }

    match->refs++;
    return match;
}

extern void fn_802CAC54(int);
extern s8 lbl_8055FC21;
/* Release a reference to a model texture entry: decrement its refcount and mark the model cache dirty when it reaches zero. */
void fn_802C5BA0(int *entry) {
    u16 refCount;
    fn_802CAC54(*entry);
    refCount = *(u16 *)((char *)entry + 4);
    refCount--;
    *(u16 *)((char *)entry + 4) = refCount;
    if (refCount == 0) {
        lbl_8055FC21 = 1;
    }
}

#pragma scheduling invalid_target
/* Build the 16-bit texture-cache sub-key: the fixed (5, 0x64) tag from the u16
 * packer, plus the doubled base id and the difference flag's low 16 bits. */
u16 fn_802C5BEC(int baseId, int differs) {
    return (((int (*)(int, int))fn_802C5A50)(5, 0x64) - -((baseId * 2) & 0xFFFE)) + (differs & 0xFFFF);
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
/* Resolves a texture reference from the "zonly.tex" resource and stores the
 * looked-up entry into the destination slot for the given index. */
void fn_802C5C40(int *dest, int index, int source) {
    int baseId = *dest;
    int texture = fn_802CAC28(lbl_8034B1F0, 0);
    int *entry = *(int **)((char *)source + index * 4 + 0x14);
    s16 refId = *(s16 *)((char *)entry + 6);
    u16 adjusted = refId - 1;
    *(int *)((char *)dest + index * 4 + 0x14) =
        (int)fn_802C5A60(texture, baseId, adjusted);
}
#pragma pop
extern int fn_8012C33C(char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern int fn_802CAC44(char *, int);
extern int fn_802CAF8C(void);
extern int fn_802CAFF0(void);
extern int fn_802CAFC8(int);
__declspec(section ".sdata") extern const char lbl_8055D010[];
void fn_802C5CC4(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x100];
    char temp[0x100];
    int other;
    int value;
    int index;
    u16 result;

    /* Resolve a resource name (optionally with a numbered suffix) to an object handle and store it at arg0 + arg1*4 + 0x14. */
    fn_802C595C(name, 0x100, (char *)arg0 + 4, arg1);
    if (arg3 != 0) {
        fn_801345D8(temp, 0x100, lbl_8055D010, arg3, name);
        if (fn_8012C33C(temp) != 0) {
            char *src = temp;
            int count = 0x100;
            char *dst = name;
            while (*dst++ = *src++) {
                if (--count <= 0) {
                    dst[-1] = '\0';
                    break;
                }
            }
        }
    }
    value = *(int *)arg0;
    index = fn_802CAC44(name, value);
    if (arg2 != 0) {
        result = fn_802C5BEC(value, fn_802CAF8C());
    } else {
        other = fn_802CAFF0();
        result = fn_802C5A50(fn_802CAFC8(index), other);
    }
    *(int *)((char *)arg0 + arg1 * 4 + 0x14) = (int)fn_802C5A60(index, value, result);
}

/* Iterate over all 0x10-byte GroupEntry records in a model's GroupList and
 * invoke callback with each group's id (+0x0C). */
void fn_802C5DF0(void *groupList, void *callback) {
    int offset = 0;
    int index = 0;
    while (index < ((struct GroupList *)groupList)->count) {
        void *items = ((struct GroupList *)groupList)->items;
        int groupId = ((struct GroupEntry *)((char *)items + offset))->id;
        ((void (*)(int))callback)(groupId);
        offset += sizeof(struct GroupEntry);
        index += 1;
    }
}

void fn_802C5E6C(void *unused, void *groupList) {
    /* Resource callback: visit every group in groupList through fn_802C5DF0,
       passing the no-op per-group hook fn_802D6C44. arg0 is unused. */
    void *callback = fn_802D6C44;
    ((void (*)(void *, void *))fn_802C5DF0)(groupList, callback);
}

#pragma pop
s32 fn_802C5EB8(void *, u32);

#define SPHL_CHUNK_TAG 0x5350484C /* 'SPHL' tagged chunk of a model resource */

/* Find the model resource's 'SPHL' tagged chunk and return a pointer to its
 * data (the chunk entry plus 8 bytes), or 0 when the chunk is absent.
 * Readable name: getModelSphlVectors. */
s32 fn_802C5E7C(void *resource) {
    char *chunk = (char *)fn_802C5EB8(resource, SPHL_CHUNK_TAG);
    if (chunk != 0) {
        return (s32)(chunk + 8);
    }
    return 0;
}

#pragma scheduling invalid_target
s32 fn_802C5EB8(void *resource, u32 tag) {
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
void *fn_802C5EFC(int id) {
    /* Find an active 0x10-byte entry in lbl_804C13A8's table whose id matches:
       returns the entry pointer, or NULL if not found. */
    int count = lbl_804C13A8[0];
    void *entry = (void *)(unsigned long)lbl_804C13A8[2];
    int i;
    for (i = 0; i < count; i++, entry = (void *)((char *)entry + 0x10)) {
        if (*(u16 *)((char *)entry + 4) != 0 && *(int *)entry == id) {
            return entry;
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
    char *base = (char *)lbl_804C1338;
    char *jumpTable = jumptable_8034B1B8;
    char *entry;
    void *memory;
    int zero = 0;

    entry = base + 0x64;
    *(int *)(entry + 4) = 0x280;
    memory = fn_8012850C(0x2810, jumpTable + 0x44);
    *(void **)(entry + 8) = fn_8002F37C(memory, (void (*)(void *))fn_802C6074, 0, 0x10, 0x280);
    *(int *)(entry + 0) = zero;

    entry = base;
    *(int *)(entry + 4) = 0x800;
    *(void **)(entry + 8) = fn_8012850C(0xA000, jumpTable + 0x58);

    entry = base + 0x70;
    *(int *)(entry + 4) = 0x400;
    memory = fn_8012850C(0x4010, jumpTable + 0x70);
    *(void **)(entry + 8) = fn_8002F37C(memory, (void (*)(void *))fn_802C6068, 0, 0x10, 0x400);
    *(int *)(entry + 0) = zero;

    entry = base + 0x58;
    *(int *)(entry + 4) = 0x400;
    *(void **)(entry + 8) = fn_8012850C(0x1000, jumpTable + 0x80);
    *(int *)(entry + 0) = zero;

    entry = base + 0x7C;
    *(int *)(entry + 4) = 0x80;
    *(void **)(entry + 8) = fn_8012850C(0x1600, jumpTable + 0x90);
    *(int *)(entry + 0) = zero;
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
extern void fn_802C7A10(void *);
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
#pragma scheduling on
void fn_802C6080(void) {
    register struct SubList *e;
    register struct SubList *e58;
    register struct SubList *e7c;
    register char *base;
    register int offset;
    register int i;
    register int zero;
    void *ptr;

    zero = 0;
    base = (char *)lbl_804C1338;
    e = (struct SubList *)(base + 0x64);
    for (i = 0, offset = 0; i < *(int *)(base + 0x64); i++, offset += 0x10) {
        if (*(int *)((char *)e->buf + offset) > 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B258, i);
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B294, ((int (*)(int))fn_802C7A10)(i));
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

void fn_802C61BC(void *arg0, int arg1) {
    unsigned char *p = (unsigned char *)arg0;
    (void)arg1;
    if (p == 0) return;
    if (*(unsigned short *)p >= 0x3E80) return;
    if (*(unsigned short *)(p + 0x10) < 0x3E80) return;
    {
        unsigned char a = p[0xE];
        unsigned char b = p[0xD];
        p[0xD] = a;
        p[0xE] = b;
    }
}

void fn_802C6A84(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
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

void fn_802C6ACC(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802C6AE4(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802C6AFC(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802C6B14(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802C6B2C(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

/* Loads a MODL resource, validates its version, and optionally prepares it for use. */
int fn_802C6B44(int arg0) {
    void *result;
    int sp10;
    u32 spC;
    u8 sp9;
    u8 sp8;

    result = fn_8012C370(arg0, 0x4D4F444C, &spC, &sp10, &sp8, &sp9);
    if (result != 0) {
        if (sp9 != 0) {
            if (spC != 0xC) {
                fn_802E317C(lbl_8034B2E8, spC, 0xC, arg0);
            }
            DCStoreRangeNoSync(result, sp10);
            fn_802C61BC(result, arg0);
        }
        if (sp8 != 0) {
            fn_802C5DF0(result, fn_802D6C48);
        }
        return (int)result;
    }
    fn_802E317C(lbl_8034B314, arg0);
    return 0;
}

#pragma dont_inline on
/* Release a model resource, with fn_802C5E6C called when its reference count reaches zero. */
int fn_802C6C20(int resource) {
    return fn_8012C4E4((void *)resource, (void *)fn_802C5E6C, resource);
}
#pragma dont_inline reset

void fn_802C6C30(void) {}

void *fn_802C6C34(int arg0) { return (void *)fn_802C53A8(arg0); }

#pragma scheduling invalid_target
void fn_802C6C38(int arg0) {
    u8 *manager = (u8 *)fn_802C5390(arg0);
    s32 outerOff, innerOff, i;
    u8 *innerInfo;
    s32 j;
    u8 *outerInfo, *outerTable, *innerTable, *item;
    u8 *node;

    if (--*(s32 *)manager > 0) {
        i = 0;
        outerOff = 0;
        goto outer_check;

    outer_setup:
        outerInfo = *(u8 **)(manager + 4);
        outerTable = *(u8 **)(outerInfo + 0xC);
        innerInfo = *(u8 **)(outerTable + outerOff);
        j = 0;
        innerOff = 0;
        goto inner_check;

    inner_body:
        innerTable = *(u8 **)(innerInfo + 4);
        item = *(u8 **)(innerTable + innerOff);
        node = *(u8 **)(item + (*(s32 *)(manager + 8) << 2) + 0x14);
        *(u8 **)(item + (*(s32 *)(manager + 8) << 2) + 0x14) = 0;
        fn_802C5BA0((int *)node);
        innerOff += 4;
        j++;

    inner_check:
        if (j < *(s32 *)innerInfo) goto inner_body;
        outerOff += 4;
        i++;

    outer_check:
        outerInfo = *(u8 **)(manager + 4);
        if (i < *(s32 *)(outerInfo + 8)) goto outer_setup;

        *(void **)(manager + 4) = 0;
        *(void **)(manager + 0xC) = 0;
    }
}
/* mrModelUnload: release a model instance handle, or warn if MODEL_INVALID (-1). */
void fn_802C6CF8(int modelHandle) {
    int resource;
    if (modelHandle == -1) {
        ((int (*)(const char *, ...))fn_802E30C8)(lbl_8034B34C);
        return;
    }
    resource = fn_802C53A8();
    fn_802C6C38(modelHandle);
    fn_802C6C20(resource);
}

s32 fn_802C6D5C(void *container) {
    /* Returns 1 if any nested item in the two-level container has a non-zero first field, else 0. */
    s32 outerOffset;
    s32 outerCount;
    s32 innerOffset;
    s32 outerIndex;
    char *outerEntry;
    s32 innerCount;
    s32 innerIndex;
    outerCount = *(s32 *)((char *)container + 8);
    outerIndex = 0;
    outerOffset = 0;
    while (outerIndex < outerCount) {
        outerEntry = *(char **)(*(char **)((char *)container + 0xC) + outerOffset);
        innerCount = *(s32 *)outerEntry;
        for (innerIndex = 0, innerOffset = 0; innerIndex < innerCount; innerIndex++, innerOffset += 4) {
            char *innerItem = *(char **)(*(char **)(outerEntry + 4) + innerOffset);
            if (*(s32 *)innerItem != 0) {
                return 1;
            }
        }
        outerOffset += 4;
        outerIndex++;
    }
    return 0;
}

extern const char lbl_8034B378[];
extern const char lbl_8034B3A4[];
int fn_802C6DC4(int arg0, int arg1, int arg2, int arg3) {
    int count = lbl_804C139C[0];
    char *scan = (char *)(unsigned long)lbl_804C139C[2];
    char *found = 0;
    char *empty = 0;
    int i;

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
            int *context = lbl_804C139C;
            if (count < context[1]) {
                int next = lbl_804C139C[0];
                char *base = (char *)(unsigned long)context[2];
                lbl_804C139C[0] = next + 1;
                empty = base + next * 0x10;
            } else {
                empty = 0;
            }
            if (empty == 0) {
                fn_802E317C(lbl_8034B378);
            }
        }

        *(int *)empty = 0;
        *(int *)(empty + 4) = arg1;
        *(int *)(empty + 8) = arg2;
        *(int *)(empty + 0xC) = fn_802C5E7C((void *)(unsigned long)arg1);
        {
            int limit = *(int *)((char *)(unsigned long)arg1 + 0x18);
            if (arg2 >= limit) {
                fn_802E317C(lbl_8034B3A4, arg2, limit, arg0);
            }
        }

        {
            register int temp = fn_802C6D5C((void *)(unsigned long)arg1);
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
    return (int)(found - (char *)(unsigned long)lbl_804C139C[2]) / 0x10;
}

#pragma push
#pragma small_data off
#pragma pop
/* Registers a model's textures (mrModelRegisterTextures): visits every group in
 * groupList through fn_802C5DF0 with the per-group hook fn_802D6C48. */
void fn_802C6FA8(void *groupList) {
    ((void (*)(void *, void *))fn_802C5DF0)(groupList, fn_802D6C48);
}

extern void fn_802D6C44(void);
void fn_802C6FB4(void *groupList) {
    /* Visit every group in groupList with the no-op per-group hook fn_802D6C44. */
    ((void (*)(void *, void *))fn_802C5DF0)(groupList, fn_802D6C44);
}

#define DrawList_isOutsideScene fn_802C90E0
#define Abend_warn(fmt, arg) ((int (*)(const char *, ...))fn_802E30C8)(fmt, arg)
#define sModelLoadInSceneFmt lbl_8034B3DC
#define mrModelLoadResource fn_802C6B44
#define mrModelCreateInstance fn_802C6DC4

/* mrModelLoad: load a MODL resource by path (warning if called during an active scene render pass) and create its model instance. */
void fn_802C6FC0(void *modelPath, int variantIdx, int flags) {
    if (DrawList_isOutsideScene() == 0) {
        Abend_warn(sModelLoadInSceneFmt, modelPath);
    }
    mrModelCreateInstance((int)modelPath, mrModelLoadResource((int)modelPath), variantIdx, flags);
}

void fn_802C703C(int arg0) {
    fn_802C6C38(arg0);
}

int fn_802C90E0(void);
int fn_802E30C8(const char*, int);
extern const char lbl_8034B34C[];
int fn_802C53A8();
int fn_802C6C20(int);
int fn_802C6B44(int);
extern const char lbl_8034B3DC[];
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);
void fn_802C7040(int instanceId) {
    float distance;
    unsigned char visibility;
    void *groupHeader;

    if (instanceId != -1) {
        groupHeader = *(void **)((char *)fn_802C5390(instanceId) + 4);
        if (fn_802C94A0((char *)groupHeader + 0x20, &visibility, &distance, *(float *)((char *)groupHeader + 0x1C))) {
            fn_802C57B4(instanceId, 0, -1, visibility, distance);
        }
    }
}

#pragma scheduling invalid_target
void fn_802C70AC(int arg0, void *arg1, int arg2, int arg3) {
    extern int fn_802D0514(void *);
    struct LocalResult {
        unsigned char status;
        unsigned char padding[3];
        float scalar;
        float vector[3];
    } local;
    float *rot;
    float *out;
    float *input;
    int previousMask;
    int ok;

    if (arg0 == -1)
        return;
    previousMask = lbl_8055D008;
    lbl_8055D008 = arg3;
    rot = (float *)((char *)*(void **)((char *)fn_802C5390(arg0) + 4) + 0x20);
    out = local.vector;
    input = (float *)arg1;
    if (out == rot) {
        float y = input[3];
        float y0 = y * rot[1];
        float y1 = input[4] * rot[1];
        float y2 = input[5] * rot[1];
        float x = input[0];
        float x0 = x * rot[0];
        float x1 = input[1] * rot[0];
        float x2 = input[2] * rot[0];
        float z = input[6];
        float z0 = z * rot[2];
        float z1 = input[7] * rot[2];
        float z2 = input[8] * rot[2];

        out[0] = (x0 + y0) + z0;
        out[1] = (x1 + y1) + z1;
        out[2] = (x2 + y2) + z2;
    } else {
        out[0] = (rot[1] * input[3] + rot[0] * input[0]) +
                 rot[2] * input[6];
        out[1] = (rot[1] * input[4] + rot[0] * input[1]) +
                 rot[2] * input[7];
        out[2] = (rot[1] * input[5] + rot[0] * input[2]) +
                 rot[2] * input[8];
    }
    {
        float tx = out[0] + input[9];
        float ty = out[1] + input[10];
        float tz = out[2] + input[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
    ok = fn_802C94A0(out, &local.status, &local.scalar, rot[-1]);
    if (ok != 0)
        fn_802C57B4(arg0, fn_802D0514(arg1), arg2, local.status, local.scalar);
    lbl_8055D008 = previousMask;
}
extern unsigned char lbl_804C13C0[];
extern float lbl_80564EF0;
extern float PSVECSquareDistance(const float *, const float *);
/* For each outer entry of type 2 within range, dispatches eligible inner elements via fn_802C53C4/fn_802CC550 using the global context. */
void fn_802C729C(int arg0, float arg1) {
    char *outerEntry;
    int globalValue;
    int innerIndex;
    int *innerInfo;
    int outerOffset;
    void *vectorDistance;
    void *vectorHeight;
    int innerOffset;
    int *outerInfo;
    void *vectors;
    int outerIndex;
    float distance;
    float radius;

    if ((unsigned int)(*(unsigned int *)lbl_804C13C0 + 0x10000U) == 0xFFFFU)
        return;
    if (arg0 == -1)
        return;

    outerInfo = (int *)fn_802C53A8(arg0);
    if (*outerInfo <= 0)
        return;

    radius = lbl_80564EF0;
    vectors = (void *)fn_802C5E7C(outerInfo);
    vectorDistance = vectors;
    vectorHeight = vectors;

    for (outerIndex = 0, outerOffset = 0;
         outerIndex < *outerInfo;
         outerOffset += 0x10,
         vectorDistance = (char *)vectorDistance + 0x10,
         vectorHeight = (char *)vectorHeight + 0x10,
         outerIndex++) {
        if (*(int *)((char *)*(int **)((char *)outerInfo + 4) + outerOffset) != 2)
            continue;
        if (vectors != 0) {
            distance = PSVECSquareDistance((float *)(lbl_804C13C0 + 4),
                                           (float *)vectorDistance);
            if (!(distance < (arg1 + *(float *)((char *)vectorHeight + 0xC)) *
                             (arg1 + *(float *)((char *)vectorHeight + 0xC))))
                continue;
        }

        innerIndex = 0;
        globalValue = *(int *)lbl_804C13C0;
        innerOffset = 0;
        outerEntry = (char *)*(int **)((char *)outerInfo + 4) + outerOffset;
        innerInfo = *(int **)(outerEntry + 8);

        for (; innerIndex < *innerInfo;
             innerOffset += 4, innerIndex++) {
            int valid = 0;
            void **innerEntries = *(void ***)((char *)innerInfo + 4);
            void *element = *(void **)((char *)innerEntries + innerOffset);
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
                fn_802C53C4(outerEntry, node, globalValue, -1, 0);
                r4 = ((void *(*)(void *))fn_802C57B0)(
                    *(void **)(outerEntry + 0xC));
                fn_802CC550(*(int *)node, r4, radius,
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
void fn_802C7458(int instanceId, int groupMask) {
    float distance;
    unsigned char visibilityStatus;
    int savedGroupMask;
    void *groupHeader;

    if (instanceId != -1) {
        savedGroupMask = lbl_8055D008;
        lbl_8055D008 = groupMask;
        groupHeader = *(void **)((char *)fn_802C5390(instanceId) + 4);
        if (fn_802C94A0((char *)groupHeader + 0x20, &visibilityStatus, &distance, *(float *)((char *)groupHeader + 0x1C))) {
            fn_802C57B4(instanceId, 0, -1, visibilityStatus, distance);
        }
        lbl_8055D008 = savedGroupMask;
    }
}

#pragma scheduling on
void fn_802C74D8(int arg0, void *arg1, int arg2) {
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
    void *inst = fn_802C5390(arg0);
    rot = (float *)((char *)*(void **)((char *)inst + 4) + 0x20);
    entry = *(void **)((char *)inst + 4);
    out = local.vector;
    input = (float *)arg1;
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
            node = fn_802C5EFC(arg2);
            arg1 = (void *)fn_802D0514(arg1);
            for (i = 0; i < *(int *)entry; i++) {
                char *item = *(char **)((char *)entry + 4) + i * 0x10;
                fn_802C53C4(item, node, (int)arg1, -1, local.status);
            }
        } else {
            fn_802C8B98(arg2, arg1);
            fn_802DB2BC(local.status);
            for (i = 0; i < *(int *)entry; i++) {
                char *item = *(char **)((char *)entry + 4) + i * 0x10;
                fn_802D6B08(*(int *)(item + 0xC));
            }
            fn_802C8D74();
        }
    }
}
void fn_802C7730(void) { fn_802DABA4(); }

/* Queue the caller's 12-float model transform as a draw record, then apply it
 * as the current GX state: fn_802D0514 returns the new record's handle and
 * fn_802D0610 selects that record. */
void fn_802C7734(void *transform) {
    fn_802D0610(fn_802D0514(transform));
}

void fn_802C7758(void);
#pragma dont_inline fn_802C7758
/* Select the default GX material/vertex state (null record handle) instead of a transform record. */
void fn_802C7758(void) {
    fn_802D0610(0);
}

/* Copies six float fields (offsets 0x2C-0x40) from a model entry to output parameters. */
void fn_802C7760(void *arg0, f32 *out1, f32 *out2, f32 *out3, f32 *out4, f32 *out5, f32 *out6) {
    void *entry = fn_802C5390((int)arg0);
    *out1 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x2C);
    *out2 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x30);
    *out3 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x34);
    *out4 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x38);
    *out5 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x3C);
    *out6 = *(f32 *)((u8 *)*(void **)((u8 *)entry + 4) + 0x40);
}

#pragma dont_inline fn_802C7760
void fn_802C77F0(void *model, f32 *out) {
    /* Read the model's six bounding-box values (min/max per axis) into out[0..5]. */
    fn_802C7760(model, out, out + 1, out + 2, out + 3, out + 4, out + 5);
}

/* Return the model instance's view tolerance (+0x1C of its group list) - the
 * threshold passed to the visibility/culling test in fn_802C94A0. */
float fn_802C7808(int instanceId) {
    return *(float *)((char *)(*(void **)((char *)fn_802C5390(instanceId) + 4)) + 0x1C);
}

/* Parse a NUL-terminated hexadecimal string (0-9 and uppercase A-F) into an
 * integer: shift the result left four bits per character and OR in its digit. */
s32 fn_802C7830(char *hexStr) {
    s32 result = 0;
    s32 digit;
    s32 isDigit;
    u8 c;
    while (*hexStr != 0) {
        result <<= 4;
        c = *hexStr;
        isDigit = 0;
        if ((s8)c >= '0' && (s8)c <= '9')
            isDigit = 1;
        digit = (s8)c - '7';
        if (isDigit != 0)
            digit = (s8)c - '0';
        result |= digit;
        hexStr++;
    }
    return result;
}

#pragma scheduling on
void fn_802C7888(void *src, s32 count)
{
  for (; count > 0; count--)
  {
    volatile u8 *source = (volatile u8 *) src;
    volatile u8 *dest;
    s32 index;
    s32 *key = *((s32 **) (((u8 *) src) + 0x28));
    u8 a;
    u8 b;
    u32 word;
    u32 word2;
    u32 word3;
    if (key != 0)
    {
      *key = -1;
    }
    index = lbl_804C13B4[0];
    if (index < lbl_804C13B4[1])
    {
      s32 offset = index * 0x2C;
      unsigned char *base = (unsigned char *) ((unsigned long) lbl_804C13B4[2]);
      lbl_804C13B4[0] = index + 1;
      dest = (volatile u8 *) (base + offset);
    }
    else
    {
      dest = 0;
    }
    a = source[0];
    b = source[1];
    dest[0] = a;
    a = source[2];
    dest[1] = b;
    b = source[3];
    dest[2] = a;
    a = source[4];
    dest[3] = b;
    b = source[5];
    dest[4] = a;
    a = source[6];
    dest[5] = b;
    b = source[7];
    dest[6] = a;
    a = source[8];
    dest[7] = b;
    b = source[9];
    dest[8] = a;
    a = source[10];
    dest[9] = b;
    b = source[11];
    dest[10] = a;
    a = source[12];
    dest[11] = b;
    b = source[13];
    dest[12] = a;
    a = source[14];
    dest[13] = b;
    b = source[15];
    dest[14] = a;
    word = (*(source + 0x10)) & 0xFFu;
    dest[15] = b;
    b = source[0x14];
    *((volatile u32 *) (dest + 0x10)) = word;
    a = source[0x15];
    dest[0x14] = b;
    b = source[0x16];
    dest[0x15] = a;
    a = source[0x17];
    dest[0x16] = b;
    b = source[0x18];
    dest[0x17] = a;
    a = source[0x19];
    dest[0x18] = b;
    b = source[0x1A];
    dest[0x19] = a;
    a = source[0x1B];
    dest[0x1A] = b;
    b = source[0x1C];
    dest[0x1B] = a;
    a = source[0x1D];
    dest[0x1C] = b;
    b = source[0x1E];
    dest[0x1D] = a;
    a = source[0x1F];
    dest[0x1E] = b;
    b = source[0x20];
    dest[0x1F] = a;
    a = source[0x21];
    dest[0x20] = b;
    b = source[0x22];
    dest[0x21] = a;
    a = source[0x23];
    dest[0x22] = b;
    word2 = *((volatile u32 *) (source + 0x24));
    dest[0x23] = a;
    word3 = *((volatile u32 *) (source + 0x28));
    src = ((u8 *) src) + 0x2C;
    *((volatile u32 *) (dest + 0x24)) = word2;
    *((volatile u32 *) (dest + 0x28)) = word3;
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
void fn_802C7A10(void* modelIndex) {
    fn_8012C58C(fn_802C53A8(modelIndex));
}

void fn_802C7A34(void) { fn_802DA704(); }

extern void fn_802DA80C(void);
void fn_802C7A38(void) { fn_802DA80C(); }

extern void fn_802DA918(void);
void fn_802C7A3C(void) { fn_802DA918(); }

extern void fn_802DA80C(void);
extern void fn_802DA918(void);
extern void fn_802DA550(void);
void fn_802C7A40(void) { fn_802DA550(); }

extern s8 lbl_8055FC20;
extern void fn_802C543C(void);
/* Begin a model-draw batch: mark submits as batched and empty the display
 * entry pool (fn_802C543C) — paired with fn_802C7A50, which submits and clears. */
void fn_802C7A44(void) {
#define s_modelBatchActive lbl_8055FC20
    s_modelBatchActive = 1;
#undef s_modelBatchActive
    fn_802C543C();
}

void fn_802C7A50(void) {
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

void fn_802C7A94(int groupId) {
    /* Reset a model sort group: clear shared state, release the group's entries, and for the special group 9 clear its active model flag. */
    fn_802C7758();
    fn_802C5720(groupId);
    if (groupId == 9) {
        fn_802C543C();
    }
}

#pragma dont_inline on
/* End a run of model draws: reset sort group 9, the extra group that is not
 * part of fn_802C7A50's nine, which also empties the display entry pool
 * (fn_802C543C).  Callers pair it with fn_802C7A44, which starts a batch. */
void fn_802C7AD4(void) {
    fn_802C7A94(9);
}
#pragma dont_inline reset
void fn_802D754C(void);
void fn_802C7ADC(void) { fn_802D754C(); }

#pragma scheduling invalid_target
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

    manager = fn_802C5390(arg0);
    local.status = 1;
    rot = (float *)((char *)*(void **)((char *)manager + 4) + 0x20);
    input = (float *)arg1;
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

        local.vector[0] = mx0 + my0 + mz0;
        local.vector[1] = mx1 + my1 + mz1;
        local.vector[2] = mx2 + my2 + mz2;
    } else {
        float y0 = input[3];
        float x0 = input[0];
        float z0 = input[6];
        float y1 = input[4];
        float x1 = input[1];
        float z1 = input[7];
        float y2 = input[5];
        float x2 = input[2];
        float z2 = input[8];

        local.vector[0] = rot[2] * z0 + (rot[0] * x0 + rot[1] * y0);
        local.vector[1] = rot[2] * z1 + (rot[1] * y1 + rot[0] * x1);
        local.vector[2] = rot[2] * z2 + (rot[1] * y2 + rot[0] * x2);
    }
    {
        float tx = local.vector[0] + input[9];
        float ty = local.vector[1] + input[10];
        float tz = input[11] + local.vector[2];
        local.vector[0] = tx;
        local.vector[1] = ty;
        local.vector[2] = tz;
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
            fn_802C7734(arg1);
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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
extern signed char lbl_8055FC20;
extern int fn_802C9C58(int);
extern void *fn_802C86DC(void);
extern float PSQUATMultiply(void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
void fn_802C7D54(int arg0, float *arg1, int arg2, float fa, float fb, float fc) {
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
    float *rot;
    float *out;
    float *input;
    float savedScalar;
    int savedCull;
    int savedMask;
    float *groupOut;
    r21 = ((void *(*)(float, float, float))fn_802C7A3C)(fa, fb, fc);
    savedCull = fn_802C9C58(arg2);
    savedMask = lbl_8055D008;
    lbl_8055D008 = 8;
    instance2 = fn_802C5390(arg0);
    instance = (struct ModelInstance *)instance2;
    rot = (float *)((char *)*(void **)((char *)instance2 + 4) + 0x20);
    out = local.vec1;
    input = (float *)arg1;
    groupOut = local.vec2;
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
    if (fn_802C94A0(out, &local.status, &local.scalar, rot[-1]) == 0) {
        lbl_8055D008 = savedMask;
        fn_802C9C58(savedCull);
        return;
    }
    r20 = fn_802D0514(arg1);
    if ((unsigned char)lbl_8055FC20 == 0) {
        fn_802C543C();
    }
    groups = instance->groups;
    nodeSlotOffset = instance->nodeSlot << 2;
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
                float *grot = (float *)(posBase + offset);
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
                    float tol = *(float *)(posBase + offset + 12);
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

void fn_802C8230(void) {
    fn_802DB2B4();
}

extern void fn_802DB2B8(void);
void fn_802C8234(void) { fn_802DB2B8(); }

extern int lbl_8055D008;
extern int fn_8012C4E4(void *, void *, int);

