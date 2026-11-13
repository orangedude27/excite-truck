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
extern void fn_802C8D74(void);
extern void fn_802DBF00(void);
extern void fn_802DBF30(void);
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
extern void fn_802E317C(char *, ...);
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
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802B0690(int *arg0) {
    int value = *arg0;
    if (value != -2) {
        fn_802CAC54(value);
        *arg0 = -2;
    }
}

void fn_802B06D4(void) {
    void *obj = fn_802B59CC();
    void **vt = *(void ***)obj;
    ((void (*)(void *, void *, int))vt[12])(obj, lbl_8034A078, 0);
}

extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void (*)(void *), void *(*)(void *, int), int, int);
extern void fn_802B0860(void *);
extern char lbl_8034A0A8[];
extern char lbl_8034A27C[];
extern int lbl_8055CD88;
void fn_802B0710(void) {
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
            entry = (int *)((char *)((int *)obj)[1] + ((int *)obj)[2] * 0x10);
            ((int *)obj)[2] = ((int *)obj)[2] + 1;
            *entry = (int)((char *)((int *)obj)[0] + offset);
            offset += 0x400;
            entry[2] = 0x200;
            entry[1] = 0;
            i++;
        }
        ((int *)obj)[2] = 0;
    }
    lbl_8055F9A0 = obj;
}

void *fn_802B0808(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            ((int *)arg0)[0] = 0;
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B0860(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B0874(void) {
    fn_802B087C(&lbl_8055F9A0);
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
void fn_802B0904(void) {
    ((int *)lbl_8055F9A0)[2] = 0;
}

#pragma scheduling invalid_target
void fn_802B0914(void) {
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
    extern void fn_8002F634(void *, void *, int, int);
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
                fn_8002F634((char *)entry + 0x18, fn_802B0AC0, 0x80, 6);
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
void *fn_802B0AC0(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 4 != 0) {
            if ((char *)arg0 + 4 != 0) {
                ((int *)arg0)[1] = 0;
                ((int *)arg0)[2] = 0;
                ((int *)arg0)[3] = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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
                    fn_802E317C(sbase + 0x178, buf);
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
                                fn_802E317C(sbase + 0xB4, tex);
                            else if (t == 1 && fn_802CAF8C() != 0 && ((int (*)(void))fn_802B06D4)() == 0)
                                fn_802E317C(sbase + 0xD8, tex);
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
                fn_802E317C(sbase + 0x158, *(void **)(obj + 0xA3C));
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
void fn_802B110C(void (*fn)(void *), void *arg) {
    fn(arg);
}
#pragma scheduling invalid_target
void fn_802B111C(void *arg0) {
    ((int *)arg0)[1] = (int)((char *)arg0 + 0x10);
    ((int *)arg0)[3] = 6;
    ((int *)arg0)[2] = 0;
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

#pragma use_lmw_stmw off
#pragma opt_loop_invariants off
void fn_802B14B4(void *arg0) {
    int i;
    int obj;
    int cache;
    int saved;
    int c;
    int *node;
    int flag;
    unsigned idx;
    unsigned mask;
    int j;
    int k;
    int cacheCount;
    int *slot;

    fn_802B1BEC();
    if (fn_802B1BE4((char *)arg0 + 0x318) > 0) {
        fn_802B1B60(arg0);
        saved = fn_802C2C00(0);
        if (lbl_8055FA59 != 0) {
            fn_802C8BD0(*(int *)((char *)arg0 + 4));
        } else {
            fn_802C8BD0();
            fn_802C28C0();
        }
        fn_802B05EC();
        fn_802DBF00();
        for (i = 0; i < fn_802B1AF0((char *)arg0 + 0xC); i++) {
            obj = fn_802B1B50((int *)((char *)arg0 + 0xC), i) + 4;
            if (lbl_8055FA59 != 0) {
                fn_802CADD0(*(int *)(fn_802B1B50((int *)((char *)arg0 + 0xC), i) + 0x7C), 1);
                fn_802CADD0(__AXGetStackHead_802BC30C(i), 2);
            } else {
                for (j = 0; j < fn_802B1B38((void *)obj); j++) {
                    fn_802CADD0(*(int *)fn_802B1B40((int *)obj, j), j + 1);
                }
                fn_802CADD0(__AXGetStackHead_802BC30C(i), 3);
            }
            cache = fn_802B1B28((int *)((char *)arg0 + 0x318), 0);
            cacheCount = fn_802B1BE4((char *)arg0 + 0x318);
            mask = 1 << i;
            idx = mask;
            slot = (int *)((char *)arg0 + mask * 4 + 0x934);
            for (; idx < 0x41; slot++, idx++) {
                if ((idx & mask) && fn_802B1B18(slot) == 0) {
                    flag = (((mask - 1) & idx) == 0);
                    for (node = (int *)fn_802B1B10(slot); node != 0; node = (int *)node[3]) {
                        c = fn_802B1B08(node);
                        if (c > 0) {
                            fn_802DC078(cache, cacheCount, fn_802B1AF8(node, 0), c, flag, i);
                        }
                    }
                }
            }
            if (lbl_8055FA59 != 0) {
                fn_802CADD0(-1, 1);
                fn_802CADD0(-1, 2);
            } else {
                for (k = 0; k < fn_802B1B38((void *)obj); k++) {
                    fn_802CADD0(-1, k + 1);
                }
                fn_802CADD0(-1, 3);
            }
        }
        fn_802DBF30();
        fn_802C8D74();
        fn_802C2C00(saved);
        saved = fn_802B1BE4((char *)arg0 + 0x318);
        fn_802BB0FC(fn_802B1B28((int *)((char *)arg0 + 0x318), 0), saved);
        fn_802B1758(arg0);
        saved = fn_802B1BE4((char *)arg0 + 0x318);
        fn_802BB3B8(fn_802B1B28((int *)((char *)arg0 + 0x318), 0), saved);
    }
}
extern float lbl_80564BB8, lbl_80564BD0, lbl_80564BD4, lbl_80564BD8;
extern float lbl_80564BDC, lbl_80564BE0, lbl_80564BE4, lbl_80564BE8;
extern double lbl_80564BF0;
extern float lbl_804BE190[];
extern unsigned short lbl_802FAAB0[];
extern void fn_802C28C0(void);
extern void fn_802C8BD0();
extern void fn_802C8D74(void);
extern void fn_802DC3C0(int);
extern void fn_802DC440(void);
extern void fn_802DC464();
extern float fn_801DCF48(int, float, float);
#pragma push
#pragma processor 750
void fn_802B1758(void *arg0) {
    float setupA[3];
    float setupB[3];
    void *node;
    int cacheCount;
    void *cache;
    int state;
    int i;
    unsigned offset;
    int sign;
    register float radius;
    float *point;
    register float z;
    float y;
    register float x;
    unsigned short values[14];

    node = *(void **)((char *)arg0 + 0x934);
    if (node != 0 && *(int *)((char *)arg0 + 4) != -2) {
        state = *(int *)((char *)arg0 + 4);
        setupA[2] = lbl_80564BD0;
        setupA[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
        setupA[1] = lbl_80564BD8;
        fn_802DA704(1, setupA, 1);
        fn_802DAA18();
        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC3C0(state);

        cache = *(void **)((char *)arg0 + 0x318);
        cacheCount = *(int *)((char *)arg0 + 0x31C);
        node = *(void **)((char *)arg0 + 0x934);
        while (node) {
            fn_802DC464(cache, cacheCount, *(void **)node, *(int *)((char *)node + 4));
            node = *(void **)((char *)node + 0xC);
        }
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)arg0 + 0x328)) {
            register char *entry = (char *)*(void **)((char *)arg0 + 0x324) + offset;
            setupA[2] = *(float *)(entry + 4);
            fn_802DA704(1, setupA, 1);
            fn_802DAA18();
            node = *(void **)entry;
            fn_802DC464(cache, cacheCount, node, *(unsigned short *)node + 1);
            offset += 8;
            i++;
        }
        fn_802DC440();
        fn_802C8D74();
    }

    if (*(unsigned char *)arg0 != 0) {
        state = *(int *)((char *)arg0 + 8);
        if (state != -2) {
            if (state == *(int *)((char *)arg0 + 4))
                setupB[0] = lbl_80564BD0 / (lbl_80564BD4 * lbl_80564BB8);
            else
                setupB[0] = lbl_80564BDC / (lbl_80564BD4 * lbl_80564BB8);
            setupB[1] = lbl_80564BD8;
            setupB[2] = lbl_80564BD0;
            fn_802DA704(1, setupB, 1);
            fn_802DAA18();
            fn_802C28C0();
            fn_802C8BD0();
            fn_802DC3C0(state);

            {
                float t = lbl_80564BD4 * lbl_80564BB8;
                radius = t * lbl_80564BE4;
                radius = lbl_80564BE0 + radius;
            }
            point = lbl_804BE190;
            for (i = 0; i < 4; i++) {
                sign = (i & 1) ? -1 : 1;
                x = (float)sign * radius;
                sign = (i & 2) ? -1 : 1;
                z = (float)sign * radius;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            radius = lbl_80564BE8 * lbl_80564BB8;
            point = (float *)((char *)lbl_804BE190 + 0x30);
            for (i = 4; i < 8; i++) {
                sign = (i & 1) ? -1 : 1;
                x = radius * (float)sign;
                sign = (i & 2) ? -1 : 1;
                z = radius * (float)sign;
                y = fn_801DCF48(0, x, z);
                point[0] = x;
                point[1] = y;
                point[2] = z;
                point += 3;
            }

            values[1] = lbl_802FAAB0[1];
            values[0] = lbl_802FAAB0[0];
            values[2] = lbl_802FAAB0[2];
            values[3] = lbl_802FAAB0[3];
            values[4] = lbl_802FAAB0[4];
            values[5] = lbl_802FAAB0[5];
            values[6] = lbl_802FAAB0[6];
            values[7] = lbl_802FAAB0[7];
            values[8] = lbl_802FAAB0[8];
            values[9] = lbl_802FAAB0[9];
            values[10] = lbl_802FAAB0[10];
            values[11] = lbl_802FAAB0[11];
            values[12] = lbl_802FAAB0[12];
            values[13] = lbl_802FAAB0[13];
            fn_802DC464(lbl_804BE190, 8, values, 0xE);
            fn_802DC440();
            fn_802C8D74();
        }
    }
    *(int *)((char *)arg0 + 0x328) = 0;
}
#pragma pop
int fn_802B1AF0(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802B1AF8(int *arg0, int arg1) { return *arg0 + arg1 * 2; }

int fn_802B1B08(void *arg0) { return ((int *)arg0)[1]; }

int fn_802B1B10(int *arg0) { return *arg0; }

int fn_802B1B18(int *arg0) { return *arg0 == 0; }

int fn_802B1B28(int *arg0, int arg1) {
    return *arg0 + (arg1 * 0xC);
}

int fn_802B1B38(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_802B1B40(int *arg0, int arg1) {
    return *arg0 + (arg1 * 0x10);
}

int fn_802B1B50(int *arg0, int arg1) {
    return *arg0 + (arg1 << 7);
}


extern float lbl_80564BF8;
extern int fn_802DA704(int, void *, int);
extern void fn_802DAA18(void);
void fn_802B1B60(void *arg0) {
    float sp8[3];
    float val = lbl_80564BF8;
    char *list = *(char **)((char *)arg0 + 0xC);
    float *out = sp8;
    int count = 0;
    int offset = 0;
    while (count < *(int *)(list + 8)) {
        char *base = *(char **)(list + 4);
        *out = *(float *)(base + offset + 4);
        out[1] = *(float *)(*(char **)(list + 4) + offset + 8);
        out[2] = val;
        count++;
        offset += 0x10;
        out += 3;
    }
    fn_802DA704(1, sp8, 2);
    fn_802DAA18();
}

int fn_802B1BE4(void *arg0) {
    return ((int *)arg0)[1];
}

void fn_802B1BEC(void) {
}

void fn_802B1BF0(void *arg0, void *arg1, int arg2) {
    float *src = (float *)((char *)((int *)arg0)[0x318 / 4] + arg2 * 0xc);
    float *dst = (float *)arg1;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

int fn_802B1C14(void *arg0) {
    return ((int *)arg0)[4];
}

extern char lbl_8034A270[];
void *fn_802B1C1C(void *arg0, int arg1) {
    if (arg1 >= 0 && arg1 < ((int *)arg0)[4]) {
        return *(void **)((char *)((int *)arg0)[3] + arg1 * 0x80 + 0x70);
    }
    return &lbl_8034A270;
}

int fn_802B1C50(void *arg0, int arg1, int arg2) {
    if (arg1 >= 0 && arg1 < *(int *)((char *)arg0 + 0x10)) {
        unsigned int base = *(unsigned int *)((char *)arg0 + 0xC);
        unsigned int addr = base + (unsigned int)(arg1 << 7);
        addr += (unsigned int)(arg2 << 2);
        return *(int *)(addr + 0x74);
    }
    return 0;
}
