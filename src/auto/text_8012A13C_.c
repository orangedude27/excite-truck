/* Fixed-size block pool ("Joint Pool"): construct/initialize, rebuild the free
 * list, pop/push elements and destroy the pool. */

typedef signed int s32;
typedef unsigned char u8;
extern char lbl_8032A5FC[]; /* "Panic: out of memory in pool(%s)" */
#define sPanicPoolEmpty lbl_8032A5FC
extern char lbl_8032A5D8[]; /* "Unable to allocate memory for pool" */
#define sPanicPoolAlloc lbl_8032A5D8
extern char lbl_8032A620[]; /* this class's vtable */
#define sPoolVtable     lbl_8032A620
int Abend_Panic(int *, ...);
int fn_80128658(int);
int fn_80128668(void *);
#pragma scheduling invalid_target
/* Construct a fixed-size block pool: install its vtable and initialize it with no caller-supplied buffer. */
void *fn_8012A13C(void *self, int name, int count, int blockSize) {
    *(int **)self = (int *)sPoolVtable;
    fn_8012A17C(self, name, count, blockSize, 0);
    return self;
}
extern s32 fn_801284E8(s32, s32);
extern void fn_8012A218(void *);
s32 fn_8012A17C(void *thisPool, s32 name, s32 count, s32 blockSize, s32 userBuffer) {
    #pragma scheduling invalid_target
    u8 *base = (u8 *)thisPool;
    s32 buffer;
    /* Initialize a fixed-size block pool: set its empty-panic/user-buffer flags, name, block size and count;
     * allocate the backing storage (or use a caller-supplied one), seed the free list, and panic if none. */
    *(u8 *)(base + 5) = (u8)(userBuffer != 0);
    *(u8 *)(base + 4) = 1;
    *(s32 *)(base + 0x14) = blockSize;
    *(s32 *)(base + 0x18) = count;
    *(s32 *)(base + 8) = name;
    if (userBuffer == 0) {
        *(s32 *)(base + 0xC) = fn_801284E8(name, count * blockSize);
    } else {
        *(s32 *)(base + 0xC) = userBuffer;
    }
    buffer = *(s32 *)(base + 0xC);
    if (buffer != 0) {
        *(s32 *)(base + 0x10) = buffer;
        fn_8012A218(base);
        return;
    }
    Abend_Panic((int *)&sPanicPoolAlloc);
}

#pragma push
#pragma scheduling invalid_target
/* Rebuild the free list of a fixed-size block pool: thread every block to the
 * next one, terminate the last with a null pointer, and reset the used count. */
void fn_8012A218(void *pool) {
    char *firstBlock = (char *)*(int *)((char *)pool + 0x10);
    char *lastBlock = firstBlock + (*(int *)((char *)pool + 0x18) - 1) * *(volatile int *)((char *)pool + 0x14);
    char *block;
    for (block = firstBlock; block < lastBlock; block += *(volatile int *)((char *)pool + 0x14)) {
        *(char **)block = block + *(volatile int *)((char *)pool + 0x14);
    }
    *(int *)lastBlock = 0;
    *(int *)((char *)pool + 0x1c) = 0;
}
#pragma pop
/* Destructor of the fixed-size block pool (built by fn_8012A13C/fn_8012A17C, which
 * allocate `count` blocks of `blockSize` bytes and thread them into a free list;
 * one instance is the "Joint Pool").  Restores this class's vtable, releases the
 * block buffer unless the caller supplied it, clears the pointer and, when `flag`
 * is set, releases the pool object itself. */
void *fn_8012A260(void *this_, s32 flag) {
    struct Pool {
        void **vtable;      /* +0x00 */
        u8 panicWhenEmpty;  /* +0x04: panic instead of returning 0 when exhausted */
        u8 userBuffer;      /* +0x05: buffer came from the caller, so don't free it */
        const char *name;   /* +0x08 */
        void *buffer;       /* +0x0C: storage for the blocks */
        void *freeList;     /* +0x10: next free block */
        s32 blockSize;      /* +0x14 */
        s32 count;          /* +0x18 */
        s32 usedCount;      /* +0x1C */
    };
#define freeBuffer fn_80128658  /* MemFree(ptr, 1) */
#define freePool fn_80128668    /* MemFree(ptr, 3) */

    if (this_ != 0) {
        struct Pool *pool = (struct Pool *)this_;
        pool->vtable = (void **)sPoolVtable;
        if (pool->userBuffer == 0) {
            freeBuffer((s32)pool->buffer);
        }
        pool->buffer = 0;
        if (flag > 0) freePool(this_);
    }

#undef freeBuffer
#undef freePool
    return this_;
}
/* Pop and return the next free element from a fixed-size object pool, panicking if the pool is empty when it requires elements. */
int *fn_8012A2D8(void *arg0) {
    int *temp_r31 = *(int **)((char *)arg0 + 0x10);
    int *temp_r3;
    if (temp_r31 == 0) {
        if (*((u8 *)arg0 + 4) != 0) {
            Abend_Panic((int *)&sPanicPoolEmpty, *(int *)((char *)arg0 + 8));
        } else {
            return 0;
        }
    }
    temp_r3 = *(int **)((char *)arg0 + 0x10);
    if (temp_r3 != 0) *(int **)((char *)arg0 + 0x10) = (int *)*temp_r3;
    *(int *)((char *)arg0 + 0x1c) += 1;
    return temp_r31;
}

void fn_8012A364(void *pool, int *element) {
    /* Push element onto the ObjectPool free list (head at +0x10) and decrement the live count (+0x1C). */
    *element = *(int *)((char *)pool + 0x10);
    *(int *)((char *)pool + 0x10) = (int)element;
    *(int *)((char *)pool + 0x1c) -= 1;
}
