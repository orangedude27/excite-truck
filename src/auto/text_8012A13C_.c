// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef struct { int pad[4]; char *base; int stride; int count; int head; } PoolList_8012A218;
extern char lbl_8032A5FC[];
extern char lbl_8032A620[];
extern int lbl_8055E174;
extern float lbl_80561474;
int fn_802E317C(int *, ...);
int fn_80128658(int);
int fn_80128668(void *);
void fn_8013B950(void);
void *fn_8012A13C(void *arg0, int arg1, int arg2, int arg3) {
    *(int **)arg0 = (int *)lbl_8032A620;
    fn_8012A17C(arg0, arg1, arg2, arg3, 0);
    return arg0;
}

extern s32 fn_801284E8(s32, s32);
extern void fn_8012A218(void *);
extern char lbl_8032A5D8[];
s32 fn_8012A17C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *base = (char *)arg0;
    s32 tmp;
    int flag = (arg4 != 0);
    *(char *)(base + 4) = 1;
    *(s32 *)(base + 0x14) = arg3;
    *(s32 *)(base + 0x18) = arg2;
    *(char *)(base + 5) = (char)flag;
    *(s32 *)(base + 8) = arg1;
    if (arg4 == 0) {
        *(s32 *)(base + 0xC) = fn_801284E8(arg1, arg2 * arg3);
    } else {
        *(s32 *)(base + 0xC) = arg4;
    }
    tmp = *(s32 *)(base + 0xC);
    if (tmp != 0) {
        *(s32 *)(base + 0x10) = tmp;
        fn_8012A218(base);
        return;
    }
    fn_802E317C((int *)&lbl_8032A5D8);
}

#pragma push
#pragma scheduling invalid_target
void fn_8012A218(void *arg0) {
    PoolList_8012A218 *l = (PoolList_8012A218 *)arg0;
    char *p;
    char *end = (char *)((l->count - 1) * l->stride + (int)l->base);
    for (p = l->base; p < end; p += l->stride) {
        int *q = (int *)p;
        *q = (int)p + l->stride;
    }
    *(int *)end = 0;
    l->head = 0;
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
#define poolVtable lbl_8032A620 /* this class's vtable */
#define freeBuffer fn_80128658  /* MemFree(ptr, 1) */
#define freePool fn_80128668    /* MemFree(ptr, 3) */

    if (this_ != 0) {
        struct Pool *pool = (struct Pool *)this_;
        pool->vtable = (void **)poolVtable;
        if (pool->userBuffer == 0) {
            freeBuffer((s32)pool->buffer);
        }
        pool->buffer = 0;
        if (flag > 0) freePool(this_);
    }

#undef poolVtable
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
            fn_802E317C((int *)&lbl_8032A5FC, *(int *)((char *)arg0 + 8));
        } else {
            return 0;
        }
    }
    temp_r3 = *(int **)((char *)arg0 + 0x10);
    if (temp_r3 != 0) *(int **)((char *)arg0 + 0x10) = (int *)*temp_r3;
    *(int *)((char *)arg0 + 0x1c) += 1;
    return temp_r31;
}

void fn_8012A364(void *arg0, int *arg1) {
    *arg1 = *(int *)((char *)arg0 + 0x10);
    *(int *)((char *)arg0 + 0x10) = (int)arg1;
    *(int *)((char *)arg0 + 0x1c) -= 1;
}
