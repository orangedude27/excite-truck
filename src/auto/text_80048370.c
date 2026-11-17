// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <math.h>
#define MEMRecordStateForFrmHeap MEMRecordStateForFrmHeap_SDK
#include <revolution/MEM.h>
#undef MEMRecordStateForFrmHeap
#include "revolution/KPAD/__KPAD.h"
#include "revolution/OS/OSInterrupt.h"
#include "revolution/MTX/mtx.h"
#include "revolution/MTX/mtxtypes.h"

extern f32 lbl_80560C48;
extern f32 lbl_80560C4C;
extern int lbl_8055D9B8;
extern char lbl_8037D808[];
extern char lbl_8037D818[];

static inline void KPADNotifySampling(s32 chan) {
    KPADInsideStatus *status = &inside_kpads[chan];
    BOOL interrupts = OSDisableInterrupts();
    if (status->sampling_pending != 0) {
        status->sampling_pending = 0;
        if (status->dpd_ctrl_callback != 0) {
            status->dpd_ctrl_callback(chan, 1);
        }
    }
    OSRestoreInterrupts(interrupts);
}

#pragma push
#pragma use_lmw_stmw off
void KPADiControlDpdCallback(s32 chan, u32 type) {
    /* Handle WPAD DPD control notifications: select the data format/sample mode for the reported device type, reconfigure auto-sampling, and update sampling state. */
    extern s32 fn_800624A4(s32, s32, void*);
    extern void WPADiSamplingCallback(s32, s32);
    KPADInsideStatus* kp;
    s32 format;
    BOOL irq;
    s32 result;

    if (type == 253) {
        return;
    }
    kp = &inside_kpads[chan];
    WPADSetAutoSamplingBuf(chan, NULL, 0);
    switch ((s32)type) {
    case WPAD_DEV_CORE:
    case 251:
    case 252:
    case 255:
        format = 2;
        type = 3;
        break;
    case WPAD_DEV_FREESTYLE:
        format = 5;
        type = 1;
        break;
    case WPAD_DEV_CLASSIC:
        format = 8;
        type = 1;
        break;
    default:
        return;
    }
    result = WPADSetDataFormat(chan, format);
    kp->data_format_failed = (result != 0);
    irq = OSDisableInterrupts();
    if (!kp->sampling_pending && WPADProbe(chan, NULL) != -1) {
        kp->sampling_pending = TRUE;
        if (kp->dpd_ctrl_callback != NULL) {
            kp->dpd_ctrl_callback(chan, FALSE);
        }
    }
    OSRestoreInterrupts(irq);
    kp->sampling_restart = TRUE;
    if (fn_800624A4(chan, type, (void*)WPADiSamplingCallback) != 0) {
        kp->data_format_failed = TRUE;
    }
    WPADSetAutoSamplingBuf(chan, (u8*)kp + 0x118, 12);
}

/* Disable pointer recalibration for a WPAD channel and stop DPD sampling if enabled. */
void WPADiDisableRecalibration(s32 chan) {
    BOOL inner;
    BOOL interrupts;
    BOOL enabled;
    KPADInsideStatus *status = &inside_kpads[chan];
    interrupts = OSDisableInterrupts();
    enabled = status->is_dpd_enabled;
    status->is_dpd_enabled = 0;
    if (enabled) {
        inner = OSDisableInterrupts();
        if (status->sampling_pending == 0 && WPADProbe(chan, 0) != -1) {
            status->sampling_pending = 1;
            if (status->dpd_ctrl_callback != 0) {
                status->dpd_ctrl_callback(chan, 0);
            }
        }
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts(interrupts);
}

#pragma push
#pragma use_lmw_stmw off
/* Enable DPD sampling for a WPAD channel and trigger a sampling probe if not already enabled. */
void WPADiClearQueue(s32 chan) {
    BOOL inner;
    BOOL interrupts;
    BOOL enabled;
    KPADInsideStatus *status = &inside_kpads[chan];
    interrupts = OSDisableInterrupts();
    enabled = status->is_dpd_enabled;
    status->is_dpd_enabled = 1;
    if (enabled != 1) {
        inner = OSDisableInterrupts();
        if (status->sampling_pending == 0 && WPADProbe(chan, 0) != -1) {
            status->sampling_pending = 1;
            if (status->dpd_ctrl_callback != 0) {
                status->dpd_ctrl_callback(chan, 0);
            }
        }
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts(interrupts);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
/* WPAD sampling-complete callback: clear the sampling-restart flag, mark a data
 * format failure on error, or when the DPD enabled state matches and there is no
 * format failure, notify KPAD that sampling is ready for this channel. */
void WPADiSamplingCallback(s32 chan, s32 result) {
    extern u32 fn_80062460(s32);
    s32 dpdEnabled;
    KPADInsideStatus *status = &inside_kpads[chan];
    status->sampling_restart = 0;
    if (result != 0) {
        status->data_format_failed = 1;
    } else {
        dpdEnabled = fn_80062460(chan);
        if (dpdEnabled == status->is_dpd_enabled && status->data_format_failed == 0) {
            KPADNotifySampling(chan);
        }
    }
}

#pragma push
#pragma scheduling reset
/* Find the innermost heap in `list` whose [start, end) range contains `addr`.
   Walks three nested list levels and recurses into the deepest match, falling
   back to the shallowest enclosing heap; returns 0 if none contains the address. */
void *FindContainHeap_(MEMList *list, u32 addr) {
    MEMiHeapHead *childHeap;
    MEMiHeapHead *blockHeap;
    MEMiHeapHead *rootHeap;
    MEMiHeapHead *container;

    rootHeap = 0;
    while ((rootHeap = (MEMiHeapHead *)MEMGetNextListObject(list, rootHeap)) != 0) {
        if ((u32)rootHeap->start <= addr && addr < (u32)rootHeap->end) {
            childHeap = 0;
            while ((childHeap = (MEMiHeapHead *)MEMGetNextListObject(&rootHeap->list, childHeap)) != 0) {
                if ((u32)childHeap->start <= addr && addr < (u32)childHeap->end) {
                    blockHeap = 0;
                    while ((blockHeap = (MEMiHeapHead *)MEMGetNextListObject(&childHeap->list, blockHeap)) != 0) {
                        if ((u32)blockHeap->start <= addr && addr < (u32)blockHeap->end) {
                            container = (MEMiHeapHead *)FindContainHeap_(&blockHeap->list, addr);
                            switch ((u32)container) { case 0: container = blockHeap; break; default: break; }
                            goto found_inner;
                        }
                    }
                    container = 0;
                found_inner:
                    switch ((u32)container) { case 0: container = childHeap; break; default: break; }
                    goto found_middle;
                }
            }
            container = 0;
        found_middle:
            switch ((u32)container) { case 0: container = rootHeap; break; default: break; }
            goto found_outer;
        }
    }
    container = 0;
found_outer:
    return container;
}

#pragma push
#pragma processor 750
void MEMiInitHeapHead(MEMiHeapHead *heap, u32 magic, void *start, void *end, u16 opt) {
    MEMiHeapHead *child;
    MEMiHeapHead *outer;
    MEMiHeapHead *block;
    MEMiHeapHead *res;
    MEMList *list;
    heap->magic = magic;
    heap->start = start;
    heap->end = end;
    heap->attribute = 0;
    SetOptForHeap(heap, opt);
    MEMInitList(&heap->list, 4);
    if (lbl_8055D9B8 == 0) {
        MEMInitList((MEMList *)lbl_8037D808, 4);
        OSInitMutex((OSMutex *)lbl_8037D818);
        lbl_8055D9B8 = 1;
    }
    OSInitMutex(&heap->mutex);
    OSLockMutex((OSMutex *)lbl_8037D818);
    list = (MEMList *)lbl_8037D808;
    outer = 0;
    while ((outer = (MEMiHeapHead *)MEMGetNextListObject((MEMList *)lbl_8037D808, outer)) != 0) {
        if ((u32)outer->start <= (u32)heap && (u32)heap < (u32)outer->end) {
            child = 0;
            while ((child = (MEMiHeapHead *)MEMGetNextListObject(&outer->list, child)) != 0) {
                if ((u32)child->start <= (u32)heap && (u32)heap < (u32)child->end) {
                    block = 0;
                    while ((block = (MEMiHeapHead *)MEMGetNextListObject(&child->list, block)) != 0) {
                        if ((u32)block->start <= (u32)heap && (u32)heap < (u32)block->end) {
                            res = (MEMiHeapHead *)FindContainHeap_(&block->list, (u32)heap);
                            switch ((u32)res) { case 0: res = block; break; default: break; }
                            goto found_inner;
                        }
                    }
                    res = 0;
                found_inner:
                    switch ((u32)res) { case 0: res = child; break; default: break; }
                    goto found_middle;
                }
            }
            res = 0;
        found_middle:
            switch ((u32)res) { case 0: res = outer; break; default: break; }
            goto found_outer;
        }
    }
    res = 0;
found_outer:
    if (res != 0)
        list = &res->list;
    MEMAppendListObject(list, heap);
    OSUnlockMutex((OSMutex *)lbl_8037D818);
}
#pragma pop
extern char lbl_8037D808[];
extern char lbl_8037D818[];
#pragma push
#pragma scheduling reset
void MEMiFinalizeHeap(MEMiHeapHead *heap) {
    /* Unlink a heap from the deepest heap list whose range contains it (the
       root list's three nested levels plus a recursive search), then invalidate
       its magic so the heap can no longer be used. */
    MEMiHeapHead *childHeap;
    MEMiHeapHead *rootHeap;
    MEMiHeapHead *blockHeap;
    MEMiHeapHead *container;
    MEMList *parentList;
    OSLockMutex((OSMutex *)lbl_8037D818);
    parentList = (MEMList *)lbl_8037D808;
    rootHeap = 0;
    while ((rootHeap = (MEMiHeapHead *)MEMGetNextListObject((MEMList *)lbl_8037D808, rootHeap)) != 0) {
        if ((u32)rootHeap->start <= (u32)heap && (u32)heap < (u32)rootHeap->end) {
            childHeap = 0;
            while ((childHeap = (MEMiHeapHead *)MEMGetNextListObject(&rootHeap->list, childHeap)) != 0) {
                if ((u32)childHeap->start <= (u32)heap && (u32)heap < (u32)childHeap->end) {
                    blockHeap = 0;
                    while ((blockHeap = (MEMiHeapHead *)MEMGetNextListObject(&childHeap->list, blockHeap)) != 0) {
                        if ((u32)blockHeap->start <= (u32)heap && (u32)heap < (u32)blockHeap->end) {
                            container = (MEMiHeapHead *)FindContainHeap_(&blockHeap->list, (u32)heap);
                            switch ((u32)container) { case 0: container = blockHeap; break; default: break; }
                            goto found_inner;
                        }
                    }
                    container = 0;
                found_inner:
                    switch ((u32)container) { case 0: container = childHeap; break; default: break; }
                    goto found_middle;
                }
            }
            container = 0;
        found_middle:
            switch ((u32)container) { case 0: container = rootHeap; break; default: break; }
            goto found_outer;
        }
    }
    container = 0;
found_outer:
    if (container != 0)
        parentList = &container->list;
    MEMRemoveListObject(parentList, heap);
    OSUnlockMutex((OSMutex *)lbl_8037D818);
    heap->magic = 0;
}
#pragma pop

#pragma pop

static inline MEMiExpHeapMBlock *InsertAfterMBlock_(MEMiExpHeapMBlockList *list, MEMiExpHeapMBlock *prev, MEMiExpHeapMBlock *mblock) {
    MEMiExpHeapMBlock *next;
    mblock->prev = prev;
    if (prev != 0) {
        next = prev->next;
        prev->next = mblock;
    } else {
        next = list->head;
        list->head = mblock;
    }
    mblock->next = next;
    if (next != 0) {
        next->prev = mblock;
    } else {
        list->tail = mblock;
    }
    return mblock;
}

void *AllocUsedBlockFromFreeBlock_(MEMiExpHeapHead *exp, MEMiExpHeapMBlock *blk, void *mem, u32 size, u16 direction) {
    MEMiExpHeapMBlock *usedStart;
    u8 *after = (u8 *)mem + size;
    MEMiExpHeapMBlock *newBlk = (MEMiExpHeapMBlock *)((u8 *)mem - sizeof(MEMiExpHeapMBlock));
    MEMiExpHeapMBlock *prev = blk->prev;
    u8 *start = (u8 *)blk - blk->align;
    MEMiExpHeapMBlock *next = blk->next;
    u8 *end = (u8 *)blk + blk->size + sizeof(MEMiExpHeapMBlock);
    MEMiExpHeapMBlock *fb;

    usedStart = newBlk;
    if (prev != 0) {
        prev->next = next;
    } else {
        exp->freeMBlocks.head = next;
    }
    if (next != 0) {
        next->prev = prev;
    } else {
        exp->freeMBlocks.tail = prev;
    }

    if ((u32)newBlk - (u32)start < 0x14) {
        usedStart = (MEMiExpHeapMBlock *)start;
    } else {
        fb = (MEMiExpHeapMBlock *)start;
        fb->state = 0x4652;
        fb->settings = 0;
        fb->size = (u32)newBlk - ((u32)start + sizeof(MEMiExpHeapMBlock));
        fb->next = 0;
        prev = InsertAfterMBlock_(&exp->freeMBlocks, prev, fb);
    }

    if ((u32)end - (u32)after < 0x14) {
        after = end;
    } else {
        fb = (MEMiExpHeapMBlock *)after;
        fb->state = 0x4652;
        fb->settings = 0;
        fb->size = (u32)end - ((u32)after + sizeof(MEMiExpHeapMBlock));
        fb->next = 0;
        prev = InsertAfterMBlock_(&exp->freeMBlocks, prev, fb);
    }

    if (((MEMiHeapHead *)exp)[-1].attribute & 1) {
        memset(usedStart, 0, after - (u8 *)usedStart);
    }

    newBlk->state = 0x5544;
    newBlk->size = after - (u8 *)mem;
    newBlk->prev = 0;
    newBlk->next = 0;
    newBlk->settings = 0;
    newBlk->allocDir = direction;
    newBlk->align = (u8 *)newBlk - (u8 *)usedStart;
    newBlk->group = exp->group;
    InsertAfterMBlock_(&exp->usedMBlocks, exp->usedMBlocks.tail, newBlk);
    return mem;
}
#pragma opt_propagation reset
static inline void* RoundUpPtr_(void* ptr, s32 align) {
    return (void*)(((u32)ptr + (align - 1)) & ~(align - 1));
}

static inline void* AddU32ToPtr_(void* ptr, u32 val) {
    return (void*)((u32)ptr + val);
}

static inline u32 GetOffsetFromPtr_(void* start, void* end) {
    return (u32)end - (u32)start;
}

void* AllocFromHead_(MEMiHeapHead* heap, u32 size, int align) {
    extern void* AllocUsedBlockFromFreeBlock_(MEMiExpHeapHead*, MEMiExpHeapMBlock*, void*, u32, u16);
    MEMiExpHeapHead* exp = (MEMiExpHeapHead*)(heap + 1);
    BOOL isFastAlloc = exp->allocMode == MEM_EXP_HEAP_ALLOC_FAST;
    MEMiExpHeapMBlock* it = 0;
    MEMiExpHeapMBlock* bestBlk = 0;
    unsigned int bestBlkSize = 0xFFFFFFFF;
    void* bestBlkMemPtr = 0;
    for (it = exp->freeMBlocks.head; it != 0; it = it->next) {
        void* const start = it + 1;
        void* const end = (void*)(((unsigned int)start + (align - 1)) & ~(align - 1));
        const unsigned int offset = (unsigned int)end - (unsigned int)start;
        if (it->size >= size + offset && bestBlkSize > it->size) {
            bestBlk = it;
            bestBlkSize = it->size;
            bestBlkMemPtr = end;
            if (isFastAlloc || bestBlkSize == size) break;
        }
    }
    return bestBlk != 0 ? AllocUsedBlockFromFreeBlock_(exp, bestBlk, bestBlkMemPtr, size, 0) : 0;
}

#pragma pop

void* AllocUsedBlockFromFreeBlock_(MEMiExpHeapHead*, MEMiExpHeapMBlock*, void*, u32, u16);
/* Allocate a block from the tail of an expanded heap, choosing the best-fit free block. */
void* AllocFromTail_(MEMiHeapHead* heap, u32 size, s32 align) {
    BOOL isFastAlloc;
    MEMiExpHeapMBlock* it;
    MEMiExpHeapHead* exp;
    MEMiExpHeapMBlock* bestBlk;
    u32 bestBlkSize;
    void* bestBlkMemPtr;
    exp = (MEMiExpHeapHead*)(heap + 1);
    isFastAlloc = exp->allocMode == MEM_EXP_HEAP_ALLOC_FAST;
    bestBlk = 0;
    bestBlkSize = 0xFFFFFFFF;
    bestBlkMemPtr = 0;
    for (it = exp->freeMBlocks.tail; it != 0; it = it->prev) {
        void* start = it + 1;
        void* end = (void*)((it->size + (u32)start - size) & ~(align - 1));
        if ((s32)((u32)end - (u32)start) >= 0 && bestBlkSize > it->size) {
            bestBlk = it;
            bestBlkSize = it->size;
            bestBlkMemPtr = end;
            if (isFastAlloc || bestBlkSize == size) break;
        }
    }
    return bestBlk != 0 ? AllocUsedBlockFromFreeBlock_(exp, bestBlk, bestBlkMemPtr, size, 1) : 0;
}

static inline MEMiExpHeapMBlock* RemoveMBlock_(MEMiExpHeapMBlockList* list, MEMiExpHeapMBlock* mblock) {
    MEMiExpHeapMBlock* prev = mblock->prev;
    MEMiExpHeapMBlock* next = mblock->next;

    if (prev != 0) {
        prev->next = next;
    } else {
        list->head = next;
    }

    if (next != 0) {
        next->prev = prev;
    } else {
        list->tail = prev;
    }

    return prev;
}

static inline MEMiExpHeapMBlock* InitMBlock_(void** region, u16 state) {
    MEMiExpHeapMBlock* mblock = (MEMiExpHeapMBlock*)region[0];
    mblock->state = state;
    mblock->settings = 0;
    mblock->size = (u32)region[1] - ((u32)mblock + sizeof(MEMiExpHeapMBlock));
    mblock->prev = 0;
    mblock->next = 0;
    return mblock;
}

static inline MEMiExpHeapMBlock* InitFreeMBlock_(void** region) {
    return InitMBlock_(region, 0x4652);
}

/* Coalesces a recycled region with adjacent free blocks in an MEMiExpHeap and inserts it into the free list; returns 1 if a free block was created, 0 if too small. */
s32 RecycleRegion_(MEMiExpHeapHead *exp, void **region) {
    void *reg[2];
    void **p;
    MEMiExpHeapMBlock *it;
    MEMiExpHeapMBlock *prev;
    MEMiExpHeapMBlock *mblock;
    void *start;
    void *end;

    p = reg;
    prev = 0;
    p[0] = region[0];
    p[1] = region[1];

    for (it = exp->freeMBlocks.head; it != 0; it = it->next) {
        if ((u32)it < (u32)region[0]) {
            prev = it;
        } else {
            if ((u32)it == (u32)region[1]) {
                p[1] = (void *)((u32)it + it->size + sizeof(MEMiExpHeapMBlock));
                RemoveMBlock_(&exp->freeMBlocks, it);
            }
            break;
        }
    }

    if (prev != 0 && (void *)((u32)prev + prev->size + sizeof(MEMiExpHeapMBlock)) == region[0]) {
        p[0] = prev;
        prev = RemoveMBlock_(&exp->freeMBlocks, prev);
    }

    end = p[1];
    start = p[0];
    if ((u32)end - (u32)start < sizeof(MEMiExpHeapMBlock)) {
        return 0;
    }

    mblock = (MEMiExpHeapMBlock *)start;
    mblock->state = 0x4652;
    mblock->settings = 0;
    mblock->size = (u32)end - ((u32)start + sizeof(MEMiExpHeapMBlock));
    mblock->next = 0;
    mblock->prev = prev;

    {
        MEMiExpHeapMBlock *next;
        if (prev != 0) {
            next = prev->next;
            prev->next = mblock;
        } else {
            next = exp->freeMBlocks.head;
            exp->freeMBlocks.head = mblock;
        }
        mblock->next = next;
        if (next != 0) {
            next->prev = mblock;
        } else {
            exp->freeMBlocks.tail = mblock;
        }
    }

    return 1;
}

#pragma pop

MEMiHeapHead* MEMCreateExpHeapEx(void *start, u32 size, u16 opt) {
    u32 end = ((u32)size + (u32)start) & ~3;
    u32 base = ((u32)start + 3) & ~3;
    u32 diff;
    u32 block;
    u32 blockEnd;

    /* Create an expanded heap in [start, start+size): align bounds, init heap head ('EXPH'), and seed one free block ('FR'). */
    if (base > end || end - base < 0x64U)
        return 0;
    diff = end - base;
    MEMiInitHeapHead((MEMiHeapHead *)base, 0x45585048, (void *)(base + 0x50), (void *)end, opt);
    *(u16 *)(base + 0x4C) = 0;
    *(u16 *)(base + 0x4E) = 0;
    block = *(u32 *)(base + 0x18);
    blockEnd = *(u32 *)(base + 0x1C);
    *(u16 *)block = 0x4652;
    *(u16 *)(block + 2) = 0;
    *(u32 *)(block + 4) = blockEnd - (block + 0x10);
    *(u32 *)(block + 8) = 0;
    *(u32 *)(block + 0xC) = 0;
    *(u32 *)(base + 0x3C) = block;
    *(u32 *)(base + 0x40) = block;
    *(u32 *)(base + 0x44) = 0;
    *(u32 *)(base + 0x48) = 0;
    return (MEMiHeapHead *)base;
}

MEMiHeapHead* MEMDestroyExpHeap(MEMiHeapHead* heap) {
    /* Finalize an expanded heap (unlink it from the heap list and clear its magic), then return the handle. */
    MEMiFinalizeHeap(heap);
    return heap;
}

#pragma dont_inline on
/* Allocate a block from an expanded heap, optionally locking; align >= 0 allocates
 * from the head, align < 0 allocates from the tail using its magnitude. */
void* MEMAllocFromExpHeapEx(MEMiHeapHead* heap, u32 size, s32 align) {
    void* block;
    register u32 roundedSize;

    if (size == 0) {
        size = 1;
    }
    roundedSize = size + 3;
    size = roundedSize & 0xFFFFFFFC;

    if ((*(u32 *)((u8 *)heap + 0x38) & 4) != 0) {
        OSLockMutex((OSMutex *)((u8 *)heap + 0x20));
    }

    if (align >= 0) {
        block = AllocFromHead_(heap, size, align);
    } else {
        block = AllocFromTail_(heap, size, -align);
    }

    if ((*(u32 *)((u8 *)heap + 0x38) & 4) != 0) {
        OSUnlockMutex((OSMutex *)((u8 *)heap + 0x20));
    }

    return block;
}
#pragma dont_inline reset

/* Free a block from an expanded heap: unlink its used block and recycle the region. */
void MEMFreeToExpHeap(MEMiHeapHead* heap, void* memBlock) {
    MEMiExpHeapHead* exp;
    MEMiExpHeapMBlock* mblock;
    MEMiExpHeapMBlock* next;
    MEMiExpHeapMBlock* prev;
    void* region[2];

    if (memBlock == 0) {
        return;
    }

    exp = (MEMiExpHeapHead*)(heap + 1);
    mblock = (MEMiExpHeapMBlock*)((u8*)memBlock - 0x10);

    LockHeap(heap);

    region[0] = (void*)((u8*)mblock - mblock->align);
    region[1] = (void*)((u8*)mblock + 0x10 + mblock->size);

    next = mblock->next;
    prev = mblock->prev;
    if (prev != 0) {
        prev->next = next;
    } else {
        exp->usedMBlocks.head = next;
    }
    if (next != 0) {
        next->prev = prev;
    } else {
        exp->usedMBlocks.tail = prev;
    }

    RecycleRegion_(exp, region);

    UnlockHeap(heap);
}

/* Create a frame heap in [start, start + size), or NULL if the range is too small. */
MEMiHeapHead* MEMCreateFrmHeapEx(void *start, u32 size, u16 opt) {
    u32 end = ((u32)size + (u32)start) & ~3;
    u32 base = ((u32)start + 3) & ~3;
    u32 diff;
    if (base > end)
        goto fail;
    diff = end - base;
    if (diff >= 0x48U)
        goto init;
fail:
    return 0;
init:
    MEMiInitHeapHead((MEMiHeapHead *)base, 0x46524D48, (void *)(base + 0x48), (void *)end, opt);
    *(u32 *)(base + 0x3C) = *(u32 *)(base + 0x18);
    *(u32 *)(base + 0x40) = *(u32 *)(base + 0x1C);
    *(u32 *)(base + 0x44) = 0;
    return (MEMiHeapHead *)base;
}

/* Destroy a frame heap: unlink it from the heap registry and clear its magic, then return the heap pointer. */
MEMiHeapHead* MEMDestroyFrmHeap(MEMiHeapHead* heap) {
    MEMiFinalizeHeap(heap);
    return heap;
}

#pragma push
#pragma use_lmw_stmw off
void* MEMAllocFromFrmHeapEx(MEMiHeapHead* heap, u32 size, s32 align) {
    // Frame heap state sits right behind the base heap head.
    MEMiFrmHeapHead* frm = (MEMiFrmHeapHead*)(heap + 1);
    u32 head;     // first free byte, growing up from the heap's start
    u32 tail;     // byte past the last free byte, growing down from the end
    u32 blockEnd; // byte past the block being taken
    u32 mask;     // alignment mask
    u32 memBlock; // block to return, NULL when the heap is full

    // A zero request still costs a word; everything is word aligned.
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;

    LockHeap(heap);

    if (align >= 0) {
        // Positive alignment: allocate from the head towards the tail.
        head = (u32)frm->head;
        mask = ~(align - 1);
        memBlock = (align + head - 1) & mask;
        blockEnd = size + memBlock;
        tail = (u32)frm->tail;
        if (blockEnd > tail) {
            memBlock = 0;
        } else {
            u32 clearSize = blockEnd - head;
            FillAllocMemory(heap, (void*)head, clearSize);
            frm->head = (u8*)blockEnd;
        }
    } else {
        // Negative alignment: allocate from the tail towards the head.
        tail = (u32)frm->tail;
        mask = ~(-align - 1);
        memBlock = (tail - size) & mask;
        head = (u32)frm->head;
        if (memBlock < head) {
            memBlock = 0;
        } else {
            u32 clearSize = tail - memBlock;
            FillAllocMemory(heap, (void*)memBlock, clearSize);
            frm->tail = (u8*)memBlock;
        }
    }

    UnlockHeap(heap);
    return (void*)memBlock;
}
#pragma pop

// Frees memory from a frame heap back to its head and/or tail, as chosen by
// flags (MEM_FRM_HEAP_FREE_TO_HEAD / MEM_FRM_HEAP_FREE_TO_TAIL). Freeing to the
// head resets the allocation cursor and drops all recorded states; freeing to
// the tail rewinds it and pushes every state's tail back to the end of the heap.
void MEMFreeToFrmHeap(MEMiHeapHead* heap, u32 flags) {
    MEMiFrmHeapHead *frm = (MEMiFrmHeapHead *)(heap + 1);
    LockHeap(heap);
    if (flags & MEM_FRM_HEAP_FREE_TO_HEAD) {
        frm->head = heap->start;
        frm->states = NULL;
    }
    if (flags & MEM_FRM_HEAP_FREE_TO_TAIL) {
        MEMiFrmHeapState *state = frm->states;
        while (state != NULL) {
            state->tail = heap->end;
            state = state->next;
        }
        frm->tail = heap->end;
    }
    UnlockHeap(heap);
}

u32 MEMGetAllocatableSizeForFrmHeapEx(MEMiHeapHead *heap, s32 align) {
    /* Largest block the frame heap can still hand out at this alignment: round
     * the current head up to 'align', then measure the free bytes to the tail (0
     * once the head has passed it). Interrupts are off while head and tail are
     * read so they cannot change mid-computation. */
    MEMiFrmHeapHead *frm = (MEMiFrmHeapHead *)(heap + 1);
    BOOL irq;
    u32 allocatable;
    void *alignedHead;
    align = __abs(align);
    irq = OSDisableInterrupts();
    alignedHead = (void *)((u32)frm->head + (align - 1) & ~(align - 1));
    if ((u32)alignedHead > (u32)frm->tail) {
        allocatable = 0;
    } else {
        allocatable = (u32)frm->tail - (u32)alignedHead;
    }
    OSRestoreInterrupts(irq);
    return allocatable;
}

#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
MEMiHeapHead *MEMRecordStateForFrmHeap(void *start, u32 size, u32 unitSize, u32 align, u16 opt) {
    void *startAddr = (void *)(((u32)start + 3) & ~3);
    void *heapEnd = (void *)((size + (u32)start) & ~3);
    if ((s32)((u32)startAddr - (u32)heapEnd) > 0) {
        return 0;
    }
    {
        u32 *untHead;
        void *mblk;
        u32 elementNum;
        u32 mask = ~((align - 1) | (align - 1));
        untHead = (u32 *)((u8 *)startAddr + 0x3C);
        unitSize = mask & (align + unitSize - 1);
        mblk = (void *)(mask & ((u32)untHead + align + 7));
        if ((s32)((u32)mblk - (u32)heapEnd) > 0) {
            return 0;
        }
        elementNum = ((u32)heapEnd - (u32)mblk) / unitSize;
        if (elementNum == 0) {
            return 0;
        }
        heapEnd = (void *)((s32)(elementNum * unitSize) + (s32)mblk);
        MEMiInitHeapHead((MEMiHeapHead *)startAddr, 0x554E5448, mblk, heapEnd, opt);
        untHead[0] = (u32)mblk;
        untHead[1] = unitSize;
        {
            u32 *blk = (u32 *)untHead[0];
            u32 i;
            for (i = 0; i < elementNum - 1; ++i, blk = (u32 *)*blk) {
                *blk = unitSize + (u32)blk;
            }
            *blk = 0;
        }
        return (MEMiHeapHead *)startAddr;
    }
}
#pragma pop
BOOL MEMFreeByStateToFrmHeap(MEMiHeapHead* heap, u32 id) {
    /* Free the frame heap back to the most recently recorded state: pop the
     * saved state under the heap lock (flag 0x4), then if present zero the
     * freed tail region when the heap clear-on-free flag (0x1) is set. */
    MEMiFrmHeapState *state;
    u32 size;
    #pragma unused(id)
    if (*(u32 *)((u8 *)heap + 0x38) & 4) {
        OSLockMutex((OSMutex *)((u8 *)heap + 0x20));
    }
    state = *(MEMiFrmHeapState **)((u8 *)heap + 0x3C);
    if (state != 0) {
        *(void **)((u8 *)heap + 0x3C) = *(void **)state;
    }
    if (*(u32 *)((u8 *)heap + 0x38) & 4) {
        OSUnlockMutex((OSMutex *)((u8 *)heap + 0x20));
    }
    if (state != 0) {
        size = *(u32 *)((u8 *)heap + 0x40);
        if (*(u32 *)((u8 *)heap + 0x38) & 1) {
            memset((void *)state, 0, size);
        }
    }
    return (BOOL)state;
}

/* Record a free-to point in the frame heap head so later frees can restore to it. */
void *MEMAdjustFrmHeap(MEMiHeapHead *heap, void *state) {
    MEMiFrmHeapHead *frm;

    if (state != 0) {
        LockHeap(heap);
        frm = (MEMiFrmHeapHead *)(heap + 1);
        *(void **)state = frm->head;
        frm->head = (u8 *)state;
        UnlockHeap(heap);
    }
}

/* Counts the free blocks of a unit heap: with the heap locked, walks the chain of
   same-sized free blocks that starts just past the base heap head and returns how
   many there are.
   NOTE: the symbol map lists 0x80049850 as MEMResizeForMBlockFrmHeap, but this is
   really MEMCountFreeBlockForUnitHeap - its only caller (src/auto/text_800FDE28.cpp:128)
   panics with the NW4HBM string "Failed assertion MEMCountFreeBlockForUnitHeap(
   mHeapHandle, ... )". The frame-heap routine of the map's name, in
   src/revolution/MEM/mem_frameHeap.c:243, is a different function entirely. */
u32 MEMResizeForMBlockFrmHeap(MEMiHeapHead *heap, void *memBlock, u32 size) {
    MEMUnitHeapFreeBlock *freeBlock;
    u32 count = 0;
    #pragma unused(memBlock)
    #pragma unused(size)
    LockHeap(heap);
    freeBlock = ((MEMiUnitHeapHead *)(heap + 1))->freeBlock;
    while (freeBlock != 0) {
        freeBlock = freeBlock->next;
        count++;
    }
    UnlockHeap(heap);
    return count;
}
#pragma dont_inline MEMAllocFromExpHeapEx
/* Allocator alloc callback: allocate `size` bytes from the allocator's expanded heap using its stored alignment (heapParam1). */
static void* AllocatorAllocForExpHeap_(MEMAllocator* allocator, u32 size) {
    return MEMAllocFromExpHeapEx(allocator->heap, size, allocator->heapParam1);
}

/* Allocator free callback: return `block` to the allocator's expanded heap. */
static void AllocatorFreeForExpHeap_(MEMAllocator* allocator, void* block) {
    MEMFreeToExpHeap(allocator->heap, block);
}

/* Allocator alloc callback: allocate `size` bytes from the allocator's frame heap using its stored alignment (heapParam1). */
static void* AllocatorAllocForFrmHeap_(MEMAllocator* allocator, u32 size) {
    return MEMAllocFromFrmHeapEx(allocator->heap, size, allocator->heapParam1);
}

static void AllocatorFreeForFrmHeap_(MEMAllocator* allocator, void* block) {
#pragma unused(allocator)
#pragma unused(block)
}

/* Allocate `size` bytes through the allocator's virtual alloc function. */
void* MEMAllocFromAllocator(MEMAllocator* allocator, u32 size) {
    return allocator->funcs->allocFunc(allocator, size);
}

// Free block by dispatching through the allocator's virtual freeFunc.
void MEMFreeToAllocator(MEMAllocator* allocator, void* block) {
    allocator->funcs->freeFunc(allocator, block);
}

#define sExpHeapAllocatorFuncs lbl_80560C38

/* Sets up allocator to hand out blocks from expanded heap with the given alignment. */
void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, MEMiHeapHead* heap, s32 align) {
    extern const MEMAllocatorFuncs sExpHeapAllocatorFuncs;
    allocator->funcs = &sExpHeapAllocatorFuncs;
    allocator->heap = heap;
    allocator->heapParam1 = align;
    allocator->heapParam2 = 0;
}

/* Set up an allocator to serve allocations from a frame heap with the given alignment. */
void MEMInitAllocatorForFrmHeap(MEMAllocator* allocator, MEMiHeapHead* heap, s32 align) {
    extern const MEMAllocatorFuncs lbl_80560C40;
    allocator->funcs = &lbl_80560C40;
    allocator->heap = heap;
    allocator->heapParam1 = align;
    allocator->heapParam2 = 0;
}

/* Initialise an empty MEMList whose objects carry their MEMLink at linkOffset. */
void MEMInitList(MEMList* list, u16 linkOffset) {
    list->offset = linkOffset;
    list->head = 0;
    list->tail = 0;
    list->length = 0;
}

/* Appends an object to a MEMList, updating the embedded link at the list's link offset. */
void MEMAppendListObject(MEMList* list, void* object) {
    if (list->head == 0) {
        MEMLink* link = (MEMLink*)((u8*)object + list->offset);
        link->next = 0;
        link->prev = 0;
        list->head = object;
        list->tail = object;
        list->length++;
    } else {
        register void** link = (void**)((u8*)object + list->offset);
        *link++ = list->tail;
        *link = 0;
        *(void**)((u8*)list->tail + list->offset + 4) = object;
        list->tail = object;
        list->length++;
    }
}

/* Remove an object from an intrusive doubly-linked list, updating head/tail and list length. */
void MEMRemoveListObject(MEMList* list, void* object) {
    MEMLink* link = (MEMLink*)((u8*)object + list->offset);
    if (link->prev == 0) {
        list->head = link->next;
    } else {
        ((MEMLink*)((u8*)link->prev + list->offset))->next = link->next;
    }
    if (link->next == 0) {
        list->tail = link->prev;
    } else {
        ((MEMLink*)((u8*)link->next + list->offset))->prev = link->prev;
    }
    link->prev = 0;
    link->next = 0;
    list->length--;
}

void *MEMGetNextListObject(MEMList *list, void *object) {
    if (object == 0) {
        return list->head;
    }
    return *(void **)((u8 *)object + list->offset + 4);
}

#pragma push
#pragma paired on
#pragma paired_single on
void PSMTXConcat(const Mtx a, const Mtx b, Mtx out) {
#pragma paired on
#pragma paired_single on
    int i;
    for (i = 0; i < 3; i++) {
        out[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0] + a[i][2] * b[2][0];
        out[i][1] = a[i][0] * b[0][1] + a[i][1] * b[1][1] + a[i][2] * b[2][1];
        out[i][2] = a[i][0] * b[0][2] + a[i][1] * b[1][2] + a[i][2] * b[2][2];
        out[i][3] = a[i][0] * b[0][3] + a[i][1] * b[1][3] + a[i][2] * b[2][3] + a[i][3];
    }
}

void PSMTXConcatArray(const float a[3][4], const float b[3][4], float c[3][4], unsigned long n) {
    unsigned long i;
    for (i = 0; i < n; ++i) {
        c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0];
        c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1];
        c[0][2] = a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2];
        c[0][3] = a[0][0]*b[0][3] + a[0][1]*b[1][3] + a[0][2]*b[2][3] + a[0][3];
        c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0];
        c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1];
        c[1][2] = a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2];
        c[1][3] = a[1][0]*b[0][3] + a[1][1]*b[1][3] + a[1][2]*b[2][3] + a[1][3];
        c[2][0] = a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0];
        c[2][1] = a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1];
        c[2][2] = a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2];
        c[2][3] = a[2][0]*b[0][3] + a[2][1]*b[1][3] + a[2][2]*b[2][3] + a[2][3];
    }
}

#pragma push
#pragma paired on
#pragma paired_single on
u32 PSMTXTranspose(const Mtx src, Mtx dst) {
    f32 c00 = src[1][1] * src[2][2] - src[1][2] * src[2][1];
    f32 c01 = src[1][2] * src[2][0] - src[1][0] * src[2][2];
    f32 c02 = src[1][0] * src[2][1] - src[1][1] * src[2][0];
    f32 det = src[0][0] * c00 + src[0][1] * c01 + src[0][2] * c02;
    if (det == 0.0f) {
        return 0;
    }
    {
        f32 estimate = __fres(det);
        f32 invDet = (estimate + estimate) - det * (estimate * estimate);
        f32 c10 = src[0][2] * src[2][1] - src[0][1] * src[2][2];
        f32 c11 = src[0][0] * src[2][2] - src[0][2] * src[2][0];
        f32 c12 = src[0][1] * src[2][0] - src[0][0] * src[2][1];
        f32 c20 = src[0][1] * src[1][2] - src[0][2] * src[1][1];
        f32 c21 = src[0][2] * src[1][0] - src[0][0] * src[1][2];
        f32 c22 = src[0][0] * src[1][1] - src[0][1] * src[1][0];
        dst[0][0] = c00 * invDet;
        dst[0][1] = c10 * invDet;
        dst[0][2] = c20 * invDet;
        dst[0][3] = 0.0f;
        dst[1][0] = c01 * invDet;
        dst[1][1] = c11 * invDet;
        dst[1][2] = c21 * invDet;
        dst[1][3] = 0.0f;
        dst[2][0] = c02 * invDet;
        dst[2][1] = c12 * invDet;
        dst[2][2] = c22 * invDet;
        dst[2][3] = 0.0f;
        return 1;
    }
}
#pragma pop
/* Builds a rotation matrix about one coordinate axis: axis is 'X', 'Y' or 'Z' (either
 * case) and rad the angle in radians.  The sine and cosine are taken here;
 * PSMTXInvXpose fills the matrix from them. */
u32 PSMTXInverse(Mtx mtx, char axis, f32 rad) {
    f32 sinA = sinf(rad);
    f32 cosA = cosf(rad);
    return PSMTXInvXpose(mtx, axis, sinA, cosA);
}
#pragma push
#pragma paired on
#pragma paired_single on
u32 PSMTXInvXpose(Mtx m, s32 axis, f64 sinArg, f64 cosArg) {
    register f32 sinA = (f32)sinArg;
    register f32 cosA = (f32)cosArg;
    register f32 negSin = -sinA;
    register f32 zero = lbl_80560C4C;
    register f32 one = lbl_80560C48;
    u32 mode = (u32)axis | 0x20;

    if (mode == 0x78) goto x_axis;
    if (mode == 0x79) goto y_axis;
    if (mode == 0x7A) goto z_axis;
    return (u32)m;

x_axis:
    m[0][0] = one;
    *(double *)&m[0][1] = (double)zero;
    *(double *)&m[0][3] = (double)zero;
    *(double *)&m[1][3] = (double)zero;
    m[2][3] = zero;
    m[2][1] = sinA; m[2][2] = cosA;
    m[1][1] = cosA; m[1][2] = negSin;
    return (u32)m;
y_axis:
    m[0][0] = cosA; m[0][1] = zero; m[0][2] = sinA; m[0][3] = zero;
    m[1][0] = zero; m[1][1] = one;
    *(double *)&m[1][2] = (double)zero;
    m[2][0] = negSin; m[2][1] = zero; m[2][2] = cosA; m[2][3] = zero;
    return (u32)m;
z_axis:
    m[0][0] = cosA; m[0][1] = negSin;
    *(double *)&m[0][2] = (double)zero;
    m[1][0] = sinA; m[1][1] = cosA;
    *(double *)&m[1][2] = (double)zero;
    *(double *)&m[2][0] = (double)zero;
    m[2][2] = one; m[2][3] = zero;
    return (u32)m;
}
#pragma pop

#pragma pop
extern f32 lbl_80560C48;
extern f32 lbl_80560C4C;
#pragma paired_single on
void PSMTXRotRad(Mtx m, f32 x, f32 y, f32 z) {
    register f32 zero = lbl_80560C4C;
    register f32 one = lbl_80560C48;
    m[0][3] = x;
    m[1][3] = y;
    *(double *)&m[0][1] = zero;
    *(double *)&m[2][0] = zero;
    m[1][0] = zero;
    m[1][1] = one;
    m[1][2] = zero;
    m[2][2] = one;
    m[2][3] = z;
    m[0][0] = one;
}
void PSMTXRotTrig(register Mtx m, register Mtx r, register f32 sx, register f32 sy, register f32 sz) {
    register f32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    a0 = *(f32 *)&m[0][0];
    a1 = *(f32 *)&m[0][1];
    a2 = *(f32 *)&m[0][2];
    a3 = *(f32 *)&m[0][3];
    a4 = *(f32 *)&m[1][0];
    a5 = *(f32 *)&m[1][1];
    a6 = *(f32 *)&m[1][2];
    a7 = *(f32 *)&m[1][3];
    a8 = *(f32 *)&m[2][0];
    a9 = *(f32 *)&m[2][1];
    *(f32 *)&r[0][0] = a0;
    *(f32 *)&r[0][1] = a1;
    *(f32 *)&r[0][2] = a2;
    *(f32 *)&r[0][3] = a3;
    *(f32 *)&r[1][0] = a4;
    *(f32 *)&r[1][1] = a5;
    *(f32 *)&r[1][2] = a6;
    *(f32 *)&r[1][3] = a7;
    *(f32 *)&r[2][0] = a8;
    *(f32 *)&r[2][1] = a9;
}

#pragma paired on
#pragma paired_single on
void PSMTXIdentity(float m[3][4]) {
    float zero = 0.0f;
    float one = 1.0f;
    m[0][0] = one;
    m[0][1] = zero;
    m[0][2] = zero;
    m[0][3] = zero;
    m[1][0] = zero;
    m[1][1] = one;
    m[1][2] = zero;
    m[1][3] = zero;
    m[2][0] = zero;
    m[2][1] = zero;
    m[2][2] = one;
    m[2][3] = zero;
}

void PSMTXCopy(const Mtx src, Mtx dst) { int i, j; for (i=0;i<3;i++) for (j=0;j<4;j++) dst[i][j]=src[i][j]; }

