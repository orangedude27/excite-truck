// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_802DAA18(void);
extern unsigned char lbl_8055FA59;
extern int fn_802B1AF0(void *);
extern int fn_802B1AF8(int *, int);
extern int fn_802B1B08(void *);
extern int fn_802B1B10(int *);
extern int fn_802B1B18(int *);
extern int fn_802B1B28(int *, int);
extern int fn_802B1B38(void *);
extern int fn_802B1B40(int *, int);
extern int fn_802B1B50(int *, int);
extern void fn_802B1B60(void *);
extern int fn_802B1BE4(void *);
extern void fn_802B1BEC(void);
extern void fn_802B1758(void *);
extern int fn_802C2C00(int);
extern void fn_802CADD0(int, int);
extern int __AXGetStackHead_802BC30C(int);
extern void fn_802C28C0(void);
extern void fn_802C8BD0();
extern void DrawList_RestoreNormalMode(void);
extern void fn_802DBF00(void);
extern void CpuLight_ResetFrameState(void);
extern void fn_802DC078(int, int, int, int, int, int);
extern void fn_802BB0FC(int, int);
extern void fn_802BB3B8(int, int);

extern void *lbl_8055F9A0;
void fn_802B087C(void **arg0);
void fn_802AE64C(void *);
void fn_8002F6AC(int, void (*)(void));
void *fn_802B0808(void *, int);
void fn_80128668(void *);
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void **fn_802B59CC(void);
extern char lbl_8034A078[];
extern char lbl_8034A0B4[], lbl_8034A0C4[];
extern int lbl_8055F998, lbl_8055F99C;
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801345D8(char *, int, char *, ...);
extern void Abend_Panic(char *, ...);
extern int fn_802CAF8C(void);
extern void *memset(void *, int, int);
extern char lbl_8055CDA8[];
extern char lbl_8055CD90[];
extern char lbl_8055CD98[];
extern char lbl_8055CDA0[];
extern char lbl_8055CDB0[];
extern float lbl_80564BC0;
extern float lbl_80564BC4;
extern float lbl_80564BC8;
extern float lbl_80564BCC;
void fn_802B111C(void *);
void fn_802B110C(void (*)(void *), void *);
extern char fn_802B05E4(void);
void fn_802B8AE0(void *, void *);
void fn_802B0710(void);
int fn_802B0628(int arg0) {
    /* If arg0 is non-null and fn_8012C33C() is active, load via fn_802CAC28(arg0, 0);
       otherwise return -2. */
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

/* Releases a texture handle slot: if it holds a valid handle, decrements/frees
 * the texture via fn_802CAC54 and resets the slot to the invalid handle (-2). */
void fn_802B0690(int *handleSlot) {
    int handle = *handleSlot;
    if (handle != -2) {
        fn_802CAC54(handle);
        *handleSlot = -2;
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_802B06D4(void) {
    class ETConfigAccess {
    public:
        virtual void unused00();
        virtual void unused04();
        virtual void unused08();
        virtual void unused0C();
        virtual void unused10();
        virtual void unused14();
        virtual void *lookup(void *, int);
        virtual void unused24();
        virtual void unused28();
        virtual void unused2C();
        virtual void status(void *, int);
    };
    /* Ask the game's config access object for the "crystal_mode" flag (default 0). */
    ((ETConfigAccess *)fn_802B59CC())->status(lbl_8034A078, 0);
}
#pragma scheduling on
#pragma cplusplus off
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void (*)(void *), void *(*)(void *, int), int, int);
extern void fn_802B0860(void *);
extern char lbl_8034A0A8[];
extern char lbl_8034A27C[];
extern int lbl_8055CD88;
#pragma push
#pragma scheduling 750
void fn_802B0710(void) {
int __repair_literal;

    void *obj;
    int *fields;
    int n = 0x54;
    register int i;
    register int offset;
    int *entry;
    obj = fn_801284F8(0x14, lbl_8034A0A8);
    if (obj != 0) {
        fields = (int *)fn_8002F37C(fn_8012850C(0x550, &lbl_8055CD88),
            fn_802B0860, fn_802B0808, 0x10, n);
        ((int **)obj)[1] = fields;
        ((int *)obj)[3] = n;
        ((int *)obj)[2] = 0;
        ((int **)obj)[4] = fields;
        ((void **)obj)[0] = fn_8012850C(((int *)obj)[3] << 10, lbl_8034A27C);
        i = 0;
        offset = 0;
        while (i < ((int *)obj)[3]) {
            int idx = ((int *)obj)[2];
            char *base = (char *)((void **)obj)[0];
            int *flds = (int *)((void **)obj)[1];
__repair_literal = 4;

            entry = flds + idx * __repair_literal;
            ((int *)obj)[2] = idx + 1;
            flds[idx * 4] = (int)(base + offset);
            offset += 0x400;
            entry[2] = 0x200;
            entry[1] = 0;
            i++;
        }
        ((int *)obj)[2] = 0;
    }
    lbl_8055F9A0 = obj;
}
#pragma pop
/* Reset the object's three 32-bit fields to 0, then free it when
 * shouldDelete > 0 (deleting-destructor style helper). */
void *fn_802B0808(void *object, int shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            ((int *)object)[0] = 0;
            ((int *)object)[1] = 0;
            ((int *)object)[2] = 0;
        }
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}

/* Zero the three 32-bit fields of a record; used as the element initializer
 * callback passed to fn_8002F37C (paired with the fn_802B0808 destructor). */
void fn_802B0860(void *record) {
    ((int *)record)[0] = 0;
    ((int *)record)[2] = 0;
    ((int *)record)[1] = 0;
}

/* Destroy the global block-pool manager singleton, freeing all of its storage. */
void fn_802B0874(void) {
    #define gBlockPoolManager lbl_8055F9A0
    fn_802B087C(&gBlockPoolManager);
    #undef gBlockPoolManager
}

#pragma push
#pragma opt_common_subs off
void fn_802B087C(void **objectPtr) {
    /* Destructor for the pool-manager singleton (lbl_8055F9A0): free its data buffer
     * (field[0], via fn_802AE64C), run __vec_delete over the entry array (field[4])
     * using element destructor fn_802B0808, clear the bookkeeping fields [1..3],
     * delete the object itself (__delete), and null the caller's pointer. */
    void *obj = *objectPtr;
    if (obj != 0) {
        if (obj != 0) {
            fn_802AE64C(obj);
            if ((char *)obj + 4 != 0) {
                fn_8002F6AC(((int *)obj)[4], (void (*)(void))fn_802B0808);
                if ((char *)obj + 4 != 0) {
                    ((int *)obj)[1] = 0;
                    ((int *)obj)[2] = 0;
                    ((int *)obj)[3] = 0;
                }
            }
            fn_80128668(obj);
        }
        *objectPtr = 0;
    }
}
#pragma pop
/* Reset the global block pool's used-count to 0, freeing all currently allocated blocks at once. */
void fn_802B0904(void) {
    typedef struct {
        void *bufferBase;
        void *entries;
        volatile int usedCount;
        int capacity;
    } BlockPool;
    ((BlockPool *)lbl_8055F9A0)->usedCount = 0;
}

#pragma scheduling invalid_target
void fn_802B0914(void) {
    /* Register the "last-gmat-tris" and "last-wmap-tris" entries, then build the pool manager. */
    fn_802B8AE0(lbl_8034A0B4, &lbl_8055F998);
    fn_802B8AE0(lbl_8034A0C4, &lbl_8055F99C);
    fn_802B0710();
}
#pragma scheduling on
extern void *fn_802B0AC0(void *, int);
__declspec(section ".data") extern void *lbl_804BE104;
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_common_subs off
void fn_802B0954(void) {
    /* Clears the global pool and destroys all entries in lbl_804BE104, releasing nested handles/rows and freeing each object. */
    extern void __array_delete(void *, void *, int, int);
    extern void fn_802B0690(int *);
    extern void fn_802B0874(void);
    extern void fn_80128668(void *);
    void *entry;
    int entryOffset;
    int entryIndex;
    void *table;
    int rowIndex;
    int itemIndex;
    char *row;
    int rowOffset;
    int itemOffset;

    fn_802B0874();
    table = &lbl_804BE104;
    entryIndex = 0;
    entryOffset = 0;
    for (; entryIndex < *(int *)((char *)table + 4); entryOffset += 4, entryIndex++) {
        entry = *(void **)(*(char **)&lbl_804BE104 + entryOffset);
        if (entry != 0) {
            for (rowIndex = 0, rowOffset = 0; rowIndex < *(int *)((char *)entry + 0x10); rowOffset += 0x80, rowIndex++) {
                row = *(char **)((char *)entry + 0xc) + rowOffset;
                fn_802B0690((int *)(row + 0x7c));
                for (itemIndex = 0, itemOffset = 0; itemIndex < *(int *)(row + 8); itemOffset += 0x10, itemIndex++) {
                    fn_802B0690((int *)(*(char **)(row + 4) + itemOffset));
                }
                *(int *)(row + 8) = 0;
            }
            *(int *)((char *)entry + 0x10) = 0;
            if (*(int *)((char *)entry + 8) == *(int *)((char *)entry + 4)) {
                *(int *)((char *)entry + 8) = -2;
            }
            fn_802B0690((int *)((char *)entry + 4));
            fn_802B0690((int *)((char *)entry + 8));
            if ((char *)entry + 0x324 != 0) {
                if ((char *)entry + 0x324 != 0) {
                    *(int *)((char *)entry + 0x324) = 0;
                    *(int *)((char *)entry + 0x328) = 0;
                    *(int *)((char *)entry + 0x32c) = 0;
                }
            }
            if ((char *)entry + 0x318 != 0) {
                if ((char *)entry + 0x318 != 0) {
                    *(int *)((char *)entry + 0x318) = 0;
                    *(int *)((char *)entry + 0x31c) = 0;
                    *(int *)((char *)entry + 0x320) = 0;
                }
            }
            if ((char *)entry + 0xc != 0) {
                __array_delete((char *)entry + 0x18, fn_802B0AC0, 0x80, 6);
                if ((char *)entry + 0xc != 0) {
                    *(int *)((char *)entry + 0xc) = 0;
                    *(int *)((char *)entry + 0x10) = 0;
                    *(int *)((char *)entry + 0x14) = 0;
                }
            }
            fn_80128668(entry);
        }
    }
    *(int *)((char *)table + 4) = 0;
}
#pragma dont_inline reset

#pragma opt_common_subs off
void *fn_802B0AC0(void *object, int shouldDelete) {
    /* Destructor helper: clear embedded fields at offsets +4, +8, +C, then optionally free the object. */
    if (object != 0) {
        if ((char *)object + 4 != 0) {
            if ((char *)object + 4 != 0) {
                ((int *)object)[1] = 0;
                ((int *)object)[2] = 0;
                ((int *)object)[3] = 0;
            }
        }
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}

void fn_802B0B20(void *arg0, void *arg1) {
    char *sbase = lbl_8034A078;
    int *tbl = (int *)&lbl_804BE104;
    if (tbl[1] + 1 <= tbl[2]) {
        char *obj = (char *)fn_801284F8(0xA40, sbase + 0x5C);
        if (obj != 0) {
            int idx;
            char buf[0x10];
            *(char **)(obj + 0xC) = obj + 0x18;
            *(int *)(obj + 0x14) = 6;
            *(int *)(obj + 0x10) = 0;
            fn_8002F53C(obj + 0x18, (void *)fn_802B111C, (void *)fn_802B0AC0, 0x80, 6);
            *(int *)(obj + 0x318) = 0;
            *(int *)(obj + 0x320) = 0;
            *(int *)(obj + 0x31C) = 0;
            *(char **)(obj + 0x324) = obj + 0x330;
            *(int *)(obj + 0x32C) = 0xC0;
            *(int *)(obj + 0x328) = 0;
            *(int *)(obj + 0x934) = 0;
            {
                int *p = (int *)(obj + 0x938);
                int *end = (int *)(obj + 0xA38);
                while (p < end) *p++ = 0;
            }
            *obj = (fn_802B05E4() == 0 && ((int (*)(void))fn_802B06D4)() == 0);
            idx = 1;
            while (1) {
                void *mat;
                void *gr;
                void *mat2;
                int id;
                char *row;
                float f0, f1, f2, f3;
                fn_801345D8(buf, 0x10, lbl_8055CDA8, idx);
                if (((void *(*)(void *, char *))((void **)*(void ***)arg0)[23])(arg0, buf) == 0)
                    break;
                mat = ((void *(*)(void *, char *))((void **)*(void ***)arg0)[23])(arg0, buf);
                if (((void *(*)(void *, char *))((void **)*(void ***)mat)[23])(mat, lbl_8055CDA0) == 0) {
                    Abend_Panic(sbase + 0x178, buf);
                    idx++;
                    continue;
                }
                mat2 = ((void *(*)(void *, char *))((void **)*(void ***)arg0)[23])(arg0, buf);
                gr = ((void *(*)(void *, char *))((void **)*(void ***)mat)[23])(mat, lbl_8055CD98);
                id = ((int (*)(void *))((void **)*(void ***)mat2)[2])(mat2);
                row = *(char **)(obj + 0xC) + (*(int *)(obj + 0x10) * 0x80);
                (*(int *)(obj + 0x10))++;
                f0 = lbl_80564BC0; f1 = lbl_80564BC4; f2 = lbl_80564BC8; f3 = lbl_80564BCC;
                if (arg1 != 0) {
                    f0 = ((float (*)(void *, char *))((void **)*(void ***)arg1)[9])(arg1, sbase + 0x6C);
                    f1 = ((float (*)(void *, char *))((void **)*(void ***)arg1)[9])(arg1, sbase + 0x78);
                    f2 = ((float (*)(void *, char *))((void **)*(void ***)arg1)[9])(arg1, sbase + 0x84);
                    f3 = ((float (*)(void *, char *))((void **)*(void ***)arg1)[9])(arg1, sbase + 0x90);
                }
                ((void (*)(void *, char *, char *))((void **)*(void ***)gr)[6])(gr, sbase + 0x9C, sbase + 0xA8);
                *(int *)(row + 0x7C) = ((int (*)(void))fn_802B0628)();
                {
                    int t = 1;
                    char tbuf[0x10];
                    float *pa = &f1;
                    float *pb = &f3;
                    while (1) {
                        fn_801345D8(tbuf, 0x10, lbl_8055CD90, t);
                        if (((int (*)(void *, char *))((void **)*(void ***)gr)[3])(gr, tbuf) == 0)
                            break;
                        {
                            void *tex = ((void *(*)(void *, char *))((void **)*(void ***)gr)[5])(gr, tbuf);
                            int n = *(int *)(row + 8);
                            char *base = *(char **)(row + 4);
                            char *item = base + n * 0x10;
                            int v;
                            (*(int *)(row + 8)) = n + 1;
                            *(float *)(item + 4) = *(pa - 1);
                            *(float *)(item + 8) = *(pb - 1);
                            *(int *)(item + 0xC) = t - 1;
                            v = ((int (*)(void *, void *))fn_802B110C)((void *)fn_802B0628, tex);
                            *(int *)item = v;
                            if (v == -2)
                                Abend_Panic(sbase + 0xB4, tex);
                            else if (t == 1 && fn_802CAF8C() != 0 && ((int (*)(void))fn_802B06D4)() == 0)
                                Abend_Panic(sbase + 0xD8, tex);
                            pa++; pb++; t++;
                        }
                    }
                }
                *(int *)(row + 0x70) = id;
                memset(row + 0x74, 0, 8);
                *(int *)(row + 0x78) = ((int (*)(void *, char *, int))((void **)*(void ***)gr)[8])(gr, sbase + 0x118, 2);
                *(int *)(row + 0x74) = ((int (*)(void *, char *, int))((void **)*(void ***)gr)[8])(gr, sbase + 0x130, 0);
                idx++;
            }
            if (*(int *)(obj + 0x10) == 0)
                Abend_Panic(sbase + 0x158, *(void **)(obj + 0xA3C));
            *(void **)(obj + 0xA3C) = ((void *(*)(void *, char *))((void **)*(void ***)arg0)[5])(arg0, lbl_8055CDB0);
            ((void (*)(void *, char *, void *))((void **)*(void ***)arg0)[6])(arg0, sbase + 0x1CC, 0);
            *(int *)(obj + 4) = ((int (*)(void))fn_802B0628)();
            ((void (*)(void *, char *, char *))((void **)*(void ***)arg0)[6])(arg0, sbase + 0x1C0, sbase + 0x1B0);
            {
                int v = ((int (*)(void))fn_802B0628)();
                *(int *)(obj + 8) = v;
                if (v == -2)
                    *(int *)(obj + 8) = *(int *)(obj + 4);
            }
        }
        {
            int c = tbl[1];
            tbl[1] = c + 1;
            ((void **)tbl[0])[c] = obj;
        }
    }
}

extern void *lbl_804BE104;
extern char lbl_8055F980;
char fn_802B05E4(void);
char fn_802B05EC(void);
void fn_802B0904(void);
void fn_802BAFA0(void);
int fn_802CFFA0(void);
int stricmp(const char *, const char *);
extern float lbl_80564BD0;
void fn_802BAFF8(int, void *);
typedef struct { float x, y, z; } Vec3_802B;
#pragma push
#pragma scheduling invalid_target
/* Generic indirect-call trampoline: invoke the callback with one opaque argument. */
void fn_802B110C(void (*callback)(void *), void *arg) {
    callback(arg);
}
#pragma scheduling invalid_target
void fn_802B111C(void *object) {
    /* Initialize a collection object: point its items field (+0x4) at the inline
     * storage at +0x10, set the element count (+0x8) to 0 and capacity (+0xC) to 6. */
    ((int *)object)[1] = (int)((char *)object + 0x10);
    ((int *)object)[3] = 6;
    ((int *)object)[2] = 0;
}
#pragma scheduling on
__declspec(section ".data") extern void *lbl_804BE104;
#pragma use_lmw_stmw off
/* Find an entry in lbl_804BE104 by case-insensitively matching name against its field at 0xa3c. */
void *fn_802B1138(const char *name) {
    int entryOffset;
    void *foundEntry;
    int index;
    foundEntry = 0;
    index = 0;
    entryOffset = 0;
    while (index < *(int *)((char *)&lbl_804BE104 + 4)) {
        void **entries = *(void ***)&lbl_804BE104;
        void *entry = *(void **)((char *)entries + entryOffset);
        if (stricmp(name, *(const char **)((char *)entry + 0xa3c)) == 0) {
            foundEntry = entry;
            break;
        }
        entryOffset += 4;
        index += 1;
    }
    return foundEntry;
}
#pragma optimize_for_size on
#pragma dont_inline on
void fn_802B11BC(void *arg0) {
    int *p;
    int i;
    int found;

    /* Initialize global state and object fields, clear a 13-entry table, and set a flag based on id/conditions. */
    lbl_8055F99C = 0;
    lbl_8055F998 = 0;
    ((int *)arg0)[0x318 / 4] = ((int (*)(int))fn_802CFFA0)(0x24000);
    ((int *)arg0)[0x320 / 4] = 0x3000;
    ((int *)arg0)[0x31c / 4] = 0;
    fn_802BAFA0();
    fn_802B0904();

    p = (int *)arg0;
    for (i = 0; i < 13; i++) {
        ((int *)((char *)p + 0x934))[0] = 0;
        ((int *)((char *)p + 0x934))[1] = 0;
        ((int *)((char *)p + 0x934))[2] = 0;
        ((int *)((char *)p + 0x934))[3] = 0;
        ((int *)((char *)p + 0x934))[4] = 0;
        p = (int *)((char *)p + 0x14);
    }

    found = 0;
    ((int *)arg0)[0xa38 / 4] = 0;
    ((int *)arg0)[0x328 / 4] = 0;
    if (((int *)arg0)[1] == -2 || ((int (*)(void))fn_802B05E4)() != 0 || ((int (*)(void))fn_802B05EC)() != 0) {
        found = 1;
    }
    ((char *)arg0)[1] = (char)found;
}
#pragma dont_inline reset
#pragma optimize_for_size off
int fn_802B127C(void *arg0, Vec3_802B *src) {
    volatile int *self = (volatile int *)arg0;
    int next;
    int i;
    int increment;
    float z, y, x;
    float *base, *dst;
    if (self == 0) return 0;
    next = self[0x31C / 4] + 1;
    if (next <= self[0x320 / 4]) {
        i = self[0x31C / 4];
        x = src->x;
        y = src->y;
        z = src->z;
        base = (float *)self[0x318 / 4];
        increment = i + 1;
        self[0x31C / 4] = increment;
        dst = (float *)((char *)base + i * 12);
        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    }
    return (unsigned short)(self[0x31C / 4] - 1);
}

/* Allocates/reserves 0x18 bytes from a per-index chain of pool nodes (selected from arg0's 0x934 table by arg2[2]&0x3F, or index 0 for the special case), creating a new pool entry from lbl_8055F9A0 when the current node is missing or full; stores the resulting buffer and size 0x18 into *outDesc, records the chain slot at arg0+0xA38 on success, and returns 1 on success, 0 on failure. */
int fn_802B12E0(void *owner, void *outDesc, void *selector, int mode) {
    typedef struct BlockNode {
        void *data;
        volatile int usedSize;
        int capacity;
        struct BlockNode *next;
    } BlockNode;

    typedef struct BlockPool {
        void *bufferBase;
        BlockNode *entries;
        volatile int usedCount;
        int capacity;
    } BlockPool;

    int chainIndex;
    BlockNode *node;
    BlockPool *pool;
    void *allocResult;
    int success;
    int currentUsed;
    void *nodeData;

    if (owner == 0) return 0;

    if ((4 >= mode) || (((unsigned char *)owner)[1] != 0)) {
        chainIndex = ((int *)selector)[2] & 0x3f;
    } else {
        chainIndex = 0;
    }

    pool = (BlockPool *)lbl_8055F9A0;
    selector = (char *)owner + chainIndex * 4;
    node = *(BlockNode **)(selector = (char *)selector + 0x934);
    allocResult = 0;

    if (node == 0 || node->usedSize + 0x18 > node->capacity) {
        node = 0;
        if (pool->usedCount + 1 <= pool->capacity) {
            node = &pool->entries[pool->usedCount++];
            node->usedSize = 0;
            node->next = 0;
        }
        if (node != 0) {
            node->next = *(BlockNode **)selector;
            *(BlockNode **)selector = node;
            currentUsed = node->usedSize;
            nodeData = node->data;
            allocResult = (char *)nodeData + currentUsed * 2;
            node->usedSize = currentUsed + 0x18;
        }
    } else {
        currentUsed = node->usedSize;
        nodeData = node->data;
        allocResult = (char *)nodeData + currentUsed * 2;
        node->usedSize = currentUsed + 0x18;
    }

    if (allocResult != 0) {
        *(void **)outDesc = allocResult;
        *(short *)((char *)outDesc + 6) = 0x18;
    }

    success = (allocResult == 0) ? 0 : 1;
    if (success) {
        *(void **)((char *)owner + 0xA38) = selector;
    }
    return success;
}

#pragma scheduling invalid_target
void fn_802B13F8(void *arg0, int arg1, void *arg2, int arg3, float farg0) {
    typedef struct Node_802B {
        void *data;
        volatile int size;
        int capacity;
        struct Node_802B *next;
    } Node_802B;

    typedef struct Entry_802B {
        int id;
        float time;
    } Entry_802B;

    typedef struct Self_802B {
        char pad[0x324];
        Entry_802B *entries;
        volatile int used;
        int capacity;
    } Self_802B;

    Self_802B *self = (Self_802B *)arg0;
    Node_802B **nodeSlotPtr;
    Node_802B *blockNode;
    int recordId;
    int shouldQueue;
    unsigned short recordSize;
    Entry_802B *entry;
    float remainingTime;

    /* Finalizes a pending record: shrinks the active block at +0xA38 by (0x18 - desc.size), clears it, queues (id, 1.0-time) when type==4 and time<1.0, then notifies fn_802BAFF8. */
    if (self == 0) return;

    recordId = *(int *)arg2;
    nodeSlotPtr = *(Node_802B ***)((char *)self + 0xa38);
    recordSize = *(unsigned short *)((char *)arg2 + 4);
    blockNode = *nodeSlotPtr;
    blockNode->size -= 0x18 - recordSize;
    *(void **)((char *)self + 0xa38) = 0;

    shouldQueue = (arg3 == 4 && farg0 < lbl_80564BD0);
    if (shouldQueue) {
        if (self->used + 1 <= self->capacity) {
            remainingTime = lbl_80564BD0 - farg0;
            entry = &self->entries[self->used++];
            entry->time = remainingTime;
            entry->id = recordId;
        }
    }

    fn_802BAFF8(arg1, &recordId);
}

#pragma push
#pragma cplusplus off
#pragma opt_loop_invariants off
#pragma use_lmw_stmw off
#pragma opt_lifetimes off
/* Render/dispatch pass for this manager's cached entries: set up the active
 * path (single or alternate based on lbl_8055FA59), walk each slot group and
 * submit non-empty node records to fn_802DC078, then tear down and run the
 * post-pass callbacks. */
void fn_802B14B4(void *arg0) {
    int recordCount;
    int *node;
    int isFirstInGroup;
    unsigned slotIndex;
    unsigned groupMask;
    int cacheCount;
    int objEntryIndex;
    int *slot;
    int cacheBase;
    int objEntry;
    int slotGroupIndex;
    int savedState;

    fn_802B1BEC();
    if (fn_802B1BE4((char *)arg0 + 0x318) > 0) {
        fn_802B1B60(arg0);
        savedState = fn_802C2C00(0);
        if (lbl_8055FA59 != 0) {
            fn_802C8BD0(*(int *)((char *)arg0 + 4));
        } else {
            fn_802C8BD0();
            fn_802C28C0();
        }
        fn_802B05EC();
        fn_802DBF00();
        for (slotGroupIndex = 0; slotGroupIndex < fn_802B1AF0((char *)arg0 + 0xC); slotGroupIndex++) {
            objEntry = fn_802B1B50((int *)((char *)arg0 + 0xC), slotGroupIndex) + 4;
            if (lbl_8055FA59 != 0) {
                fn_802CADD0(*(int *)(fn_802B1B50((int *)((char *)arg0 + 0xC), slotGroupIndex) + 0x7C), 1);
                fn_802CADD0(__AXGetStackHead_802BC30C(slotGroupIndex), 2);
            } else {
                for (objEntryIndex = 0; objEntryIndex < fn_802B1B38((void *)objEntry); objEntryIndex++) {
                    fn_802CADD0(*(int *)fn_802B1B40((int *)objEntry, objEntryIndex), objEntryIndex + 1);
                }
                fn_802CADD0(__AXGetStackHead_802BC30C(slotGroupIndex), 3);
            }
            cacheBase = fn_802B1B28((int *)((char *)arg0 + 0x318), 0);
            cacheCount = fn_802B1BE4((char *)arg0 + 0x318);
            groupMask = 1 << slotGroupIndex;
            slotIndex = groupMask;
            slot = (int *)((unsigned)arg0 + (groupMask << 2) + 0x934);
            for (; slotIndex < 0x41; slot++, slotIndex++) {
                if ((slotIndex & groupMask) && fn_802B1B18(slot) == 0) {
                    isFirstInGroup = (((groupMask - 1) & slotIndex) == 0);
                    for (node = (int *)fn_802B1B10(slot); node != 0; node = (int *)node[3]) {
                        recordCount = fn_802B1B08(node);
                        if (recordCount > 0) {
                            fn_802DC078(cacheBase, cacheCount, fn_802B1AF8(node, 0), recordCount, isFirstInGroup, slotGroupIndex);
                        }
                    }
                }
            }
            if (lbl_8055FA59 != 0) {
                fn_802CADD0(-1, 1);
                fn_802CADD0(-1, 2);
            } else {
                for (cacheBase = 0; cacheBase < fn_802B1B38((void *)objEntry); cacheBase++) {
                    fn_802CADD0(-1, cacheBase + 1);
                }
                fn_802CADD0(-1, 3);
            }
        }
        CpuLight_ResetFrameState();
        DrawList_RestoreNormalMode();
        fn_802C2C00(savedState);
        savedState = fn_802B1BE4((char *)arg0 + 0x318);
        fn_802BB0FC(fn_802B1B28((int *)((char *)arg0 + 0x318), 0), savedState);
        fn_802B1758(arg0);
        savedState = fn_802B1BE4((char *)arg0 + 0x318);
        fn_802BB3B8(fn_802B1B28((int *)((char *)arg0 + 0x318), 0), savedState);
    }
}
#pragma pop
extern float lbl_80564BB8, lbl_80564BD0, lbl_80564BD4, lbl_80564BD8;
extern float lbl_80564BDC, lbl_80564BE0, lbl_80564BE4, lbl_80564BE8;
extern double lbl_80564BF0;
extern float lbl_804BE190[];
extern unsigned short lbl_802FAAB0[];
extern void fn_802C28C0(void);
extern void fn_802C8BD0();
extern void DrawList_RestoreNormalMode(void);
extern void fn_802DC3C0(int);
extern void fn_802DC440(void);
extern void fn_802DC464();
extern float fn_801DCF48(int, float, float);
#pragma push
#pragma processor 750
void fn_802B1758(void *arg0) {
    register union { void *node; int state; int i; } v;
    register int cacheCount;
    register void *cache;
    register char *entry;
    register unsigned offset;
    float setupA[3];
    float setupB[3];
    int sign;
    float radius;
    float *point;
    float z;
    float y;
    float x;
    unsigned short values[14];

    v.node = *(void **)((char *)arg0 + 0x934);
    if (v.node != 0 && *(int *)((char *)arg0 + 4) != -2) {
        v.state = *(int *)((char *)arg0 + 4);
        setupA[2] = lbl_80564BD0;
        setupA[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
        setupA[1] = lbl_80564BD8;
        fn_802DA704(1, setupA, 1);
        fn_802DAA18();
        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC3C0(v.state);

        cache = *(void **)((char *)arg0 + 0x318);
        cacheCount = *(int *)((char *)arg0 + 0x31C);
        v.node = *(void **)((char *)arg0 + 0x934);
        while (v.node) {
            fn_802DC464(cache, cacheCount, *(void **)v.node, *(int *)((char *)v.node + 4));
            v.node = *(void **)((char *)v.node + 0xC);
        }
        v.i = 0;
        offset = 0;
        while (v.i < *(int *)((char *)arg0 + 0x328)) {
            entry = (char *)*(void **)((char *)arg0 + 0x324) + offset;
            setupA[2] = *(float *)(entry + 4);
            fn_802DA704(1, setupA, 1);
            fn_802DAA18();
            fn_802DC464(cache, cacheCount, *(void **)entry, *(unsigned short *)*(void **)entry + 1);
            offset += 8;
            v.i++;
        }
        fn_802DC440();
        DrawList_RestoreNormalMode();
    }

    if (*(unsigned char *)arg0 != 0) {
        v.state = *(int *)((char *)arg0 + 8);
        if (v.state != -2) {
            if (v.state == *(int *)((char *)arg0 + 4))
                setupB[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
            else
                setupB[0] = lbl_80564BDC / (lbl_80564BD4 * lbl_80564BB8);
            setupB[1] = lbl_80564BD8;
            setupB[2] = lbl_80564BD0;
            fn_802DA704(1, setupB, 1);
            fn_802DAA18();
            fn_802C28C0();
            fn_802C8BD0();
            fn_802DC3C0(v.state);

            {
                float t = lbl_80564BD4 * lbl_80564BB8;
                radius = t * lbl_80564BE4;
                radius = lbl_80564BE0 + radius;
            }
            point = lbl_804BE190;
            for (v.i = 0; v.i < 4; v.i++) {
                sign = (v.i & 1) ? -1 : 1;
                x = (float)sign * radius;
                sign = (v.i & 2) ? -1 : 1;
                z = (float)sign * radius;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            radius = lbl_80564BE8 * lbl_80564BB8;
            point = (float *)((char *)lbl_804BE190 + 0x30);
            for (v.i = 4; v.i < 8; v.i++) {
                sign = (v.i & 1) ? -1 : 1;
                x = radius * (float)sign;
                sign = (v.i & 2) ? -1 : 1;
                z = radius * (float)sign;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            {
                unsigned short *p = (unsigned short *)lbl_802FAAB0;
                values[0] = *p++;
                values[1] = *p++;
                values[2] = *p++;
                values[3] = *p++;
                values[4] = *p++;
                values[5] = *p++;
                values[6] = *p++;
                values[7] = *p++;
                values[8] = *p++;
                values[9] = *p++;
                values[10] = *p++;
                values[11] = *p++;
                values[12] = *p++;
                values[13] = *p++;
            }
            fn_802DC464(lbl_804BE190, 8, values, 0xE);
            fn_802DC440();
            DrawList_RestoreNormalMode();
        }
    }
    *(int *)((char *)arg0 + 0x328) = 0;
}
#pragma pop
/* Return the element count kept in the second word of this container header. */
int fn_802B1AF0(void *container) {
    return ((int *)container)[1];
}

/* Indexed accessor: returns the stored base value advanced by two per step (stride of a two-word record). */
int fn_802B1AF8(int *base, int step) { return *base + step * 2; }

/* Return the record count held in the word at +4 of a record-list node. */
int fn_802B1B08(void *node) { return ((int *)node)[1]; }

/* Return the first node of a slot's linked list (slot[0]); 0 means the slot is empty. */
int fn_802B1B10(int *slot) { return *slot; }

/* Return non-zero when the slot's stored handle is zero (the slot is empty). */
int fn_802B1B18(int *slot) { return *slot == 0; }

/* Address of the 3-component (12-byte) point at `index` in the table whose base
   pointer is stored at `basePtr`. */
int fn_802B1B28(int *basePtr, int index) {
    return *basePtr + (index * 0xC);
}

/* Return the element count held in the second word (+4) of this object-record table header. */
int fn_802B1B38(void *header) {
    return ((int *)header)[1];
}

/* Address of the 16-byte object record at `index` in the table whose base pointer is stored at `basePtr`. */
int fn_802B1B40(int *basePtr, int index) {
    return *basePtr + (index * 0x10);
}

/* Indexed accessor: returns the stored base advanced by 128 per step (slot-group stride). */
int fn_802B1B50(int *base, int step) {
    return *base + (step << 7);
}


extern float lbl_80564BF8;
extern int fn_802DA704(int, void *, int);
extern void fn_802DAA18(void);
/* Queues a pair of 3D points built from the source list at offset 0xC of this
 * object into the stack allocator, then flushes the pending record. Each entry
 * contributes its values at +4 and +8 as X/Y with Z fixed to 1/2048. */
void fn_802B1B60(void *arg0) {
    float points[3];
    register char *sourceList;
    register int entryOffset;
    register float *dst;
    register int index;

    sourceList = *(char **)((char *)arg0 + 0xC);
    dst = points;
    index = 0;
    entryOffset = 0;
    while (index < *(int *)(sourceList + 8)) {
        char *entries = *(char **)(sourceList + 4);
        *dst = *(float *)(entries + entryOffset + 4);
        dst[1] = *(float *)(*(char **)(sourceList + 4) + entryOffset + 8);
        dst[2] = 0.00048828125f;
        dst += 3;
        entryOffset += 0x10;
        index++;
    }
    fn_802DA704(1, points, 2);
    fn_802DAA18();
}

/* Return the element count at +4 of a cache table (whose base pointer is at +0). */
int fn_802B1BE4(void *table) {
    return ((int *)table)[1];
}

/* No-op subsystem hook called at the start of the manager's render/dispatch
 * pass (fn_802B14B4); this build leaves it empty. */
void fn_802B1BEC(void) {
}

void fn_802B1BF0(void *pointBuffer, void *outPoint, int index) {
    /* Copy the 3-component point at `index` from pointBuffer's +0x318 vector table into *outPoint. */
    float *source = (float *)((char *)((int *)pointBuffer)[0x318 / 4] + index * 0xc);
    float *dest = (float *)outPoint;
    dest[0] = source[0];
    dest[1] = source[1];
    dest[2] = source[2];
}

int fn_802B1C14(void *layerSet) {
    // Return the number of water layers in a layer set (paired with fn_802B1C1C).
    return ((int *)layerSet)[4];
}

extern char lbl_8034A270[];
void *fn_802B1C1C(void *layerSet, int layerIndex) {
    /* Return the name string of a water layer in the set, or "<unknown>" when the index is out of range. */
    if (layerIndex >= 0 && layerIndex < ((int *)layerSet)[4]) {
        return *(void **)((char *)((int *)layerSet)[3] + layerIndex * 0x80 + 0x70);
    }
    return &lbl_8034A270;
}

int fn_802B1C50(void *table, int rowIndex, int variant) {
    /* Fetch one of the two ids stored at +0x74 / +0x78 of a 0x80-byte surface
       row, chosen by variant (0 or 1); return 0 when the row is out of range. */
    if (rowIndex >= 0 && rowIndex < *(int *)((char *)table + 0x10)) {
        unsigned int rows = *(unsigned int *)((char *)table + 0xC);
        unsigned int addr = rows + (unsigned int)(rowIndex << 7);
        addr += (unsigned int)(variant << 2);
        return *(int *)(addr + 0x74);
    }
    return 0;
}
