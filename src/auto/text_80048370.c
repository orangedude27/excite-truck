// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <math.h>
#include <revolution/MEM.h>
#include "revolution/KPAD/__KPAD.h"
#include "revolution/OS/OSInterrupt.h"
#include "revolution/MTX/mtxtypes.h"

extern f32 lbl_80560C48;
extern f32 lbl_80560C4C;

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
void WPADiSamplingCallback(s32 chan, s32 result) {
    extern u32 fn_80062460(s32);
    s32 enabled;
    KPADInsideStatus *status = &inside_kpads[chan];
    status->sampling_restart = 0;
    if (result != 0) {
        status->data_format_failed = 1;
    } else {
        enabled = fn_80062460(chan);
        if (enabled == status->is_dpd_enabled && status->data_format_failed == 0) {
            KPADNotifySampling(chan);
        }
    }
}

void *FindContainHeap_(MEMList *list, u32 addr) {
    void *heap;
    void *child;
    void *block;
    void *found;

    for (heap = MEMGetNextListObject(list, 0); heap != 0;
         heap = MEMGetNextListObject(list, heap)) {
        if (*(u32 *)((u8 *)heap + 0x18) <= addr &&
            addr < *(u32 *)((u8 *)heap + 0x1C)) {
            for (child = MEMGetNextListObject((MEMList *)((u8 *)heap + 0xC), 0);
                 child != 0;
                 child = MEMGetNextListObject((MEMList *)((u8 *)heap + 0xC), child)) {
                if (*(u32 *)((u8 *)child + 0x18) <= addr &&
                    addr < *(u32 *)((u8 *)child + 0x1C)) {
                    for (block = MEMGetNextListObject((MEMList *)((u8 *)child + 0xC), 0);
                         block != 0;
                         block = MEMGetNextListObject((MEMList *)((u8 *)child + 0xC), block)) {
                        if (*(u32 *)((u8 *)block + 0x18) <= addr &&
                            addr < *(u32 *)((u8 *)block + 0x1C)) {
                            found = FindContainHeap_((MEMList *)((u8 *)block + 0xC), addr);
                            if (found != 0) return found;
                            return block;
                        }
                    }
                    return child;
                }
            }
            return heap;
        }
    }
    return 0;
}

void *AllocUsedBlockFromFreeBlock_(MEMiExpHeapHead *exp, MEMiExpHeapMBlock *blk, void *mem, u32 size, u16 align) {
MEMiExpHeapMBlock *prev=blk->prev,*next=blk->next,*first,*last,*p; u32 alloc=(u32)mem,before=alloc-(align&0x7F),end=(u32)blk+blk->size+0x10,after=alloc+size;
if(prev)prev->next=next;else exp->freeMBlocks.head=next;if(next)next->prev=prev;else exp->freeMBlocks.tail=prev;
first=(MEMiExpHeapMBlock *)(alloc-0x10);
if(alloc-before>=0x14){first=(MEMiExpHeapMBlock *)before;first->state=0x4652;first->settings=0;first->size=alloc-before-0x10;first->prev=0;first->next=0;p=exp->freeMBlocks.tail;if(p)p->next=first;else exp->freeMBlocks.head=first;first->prev=p;exp->freeMBlocks.tail=first;}
last=(MEMiExpHeapMBlock *)after;
if(end-after>=0x14){last->state=0x4652;last->settings=0;last->size=end-after-0x10;last->prev=0;last->next=0;p=exp->freeMBlocks.tail;if(p)p->next=last;else exp->freeMBlocks.head=last;last->prev=p;exp->freeMBlocks.tail=last;}
first=(MEMiExpHeapMBlock *)(alloc-0x10);first->state=0x5544;first->size=size;first->settings=(align&0x8000)|(((alloc-before)<<8)&0x7F00)|(exp->group&0xFF);
p=exp->usedMBlocks.tail;if(p)p->next=first;else exp->usedMBlocks.head=first;first->prev=p;first->next=0;exp->usedMBlocks.tail=first;return mem;
}

void* AllocFromHead_(MEMiHeapHead* heap, u32 size, s32 align) {
    extern void* AllocUsedBlockFromFreeBlock_(MEMiExpHeapHead*, MEMiExpHeapMBlock*, void*, u32, u16);
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
    for (it = exp->freeMBlocks.head; it != 0; it = it->next) {
        void* start = it + 1;
        void* end = (void*)((align + (u32)start - 1) & ~(align - 1));
        if (it->size >= size + ((u32)end - (u32)start) && bestBlkSize > it->size) {
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

s32 RecycleRegion_(void *arg0, void *arg1) {
    void *spC;
    void *sp8;
    void *r4;
    void *r5;
    void *r6;
    void *r7;
    void *r8;
    r8 = 0;
    sp8 = *(void **)arg1;
    r6 = *(void **)arg0;
    spC = *(void **)((u8 *)arg1 + 4);
loop:
    if (r6 != 0) {
        if ((u32)r6 < (u32)*(void **)arg1) {
            r8 = r6;
            r6 = *(void **)((u8 *)r6 + 0xC);
            goto loop;
        }
        if (r6 == *(void **)((u8 *)arg1 + 4)) {
            r7 = *(void **)((u8 *)r6 + 8);
            r6 = *(void **)((u8 *)r6 + 0xC);
            spC = (void *)((u32)r6 + 0x10);
            if (r7 != 0) *(void **)((u8 *)r7 + 0xC) = r6;
            else *(void **)arg0 = r6;
            if (r6 != 0) *(void **)((u8 *)r6 + 8) = r7;
            else *(void **)((u8 *)arg0 + 4) = r7;
        }
    }
    if (r8 != 0 && (void *)((u32)r8 + *(u32 *)((u8 *)r8 + 4) + 0x10) == *(void **)arg1) {
        r5 = *(void **)((u8 *)r8 + 8);
        sp8 = r8;
        r4 = *(void **)((u8 *)r8 + 0xC);
        if (r5 != 0) *(void **)((u8 *)r5 + 0xC) = r4;
        else *(void **)arg0 = r4;
        if (r4 != 0) *(void **)((u8 *)r4 + 8) = r5;
        else *(void **)((u8 *)arg0 + 4) = r5;
        r8 = r5;
    }
    r6 = (void *)((u32)spC - (u32)sp8);
    if ((u32)r6 < 0x10) return 0;
    r5 = sp8;
    *(u16 *)r5 = 0x4652;
    *(u16 *)((u8 *)r5 + 2) = 0;
    *(u32 *)((u8 *)r5 + 4) = (u32)spC - ((u32)r5 + 0x10);
    *(void **)((u8 *)r5 + 0xC) = 0;
    *(void **)((u8 *)r5 + 8) = r8;
    if (r8 != 0) {
        r4 = *(void **)((u8 *)r8 + 0xC);
        *(void **)((u8 *)r8 + 0xC) = r5;
    } else {
        r4 = *(void **)arg0;
        *(void **)arg0 = r5;
    }
    *(void **)((u8 *)r5 + 0xC) = r4;
    if (r4 != 0) *(void **)((u8 *)r4 + 8) = r5;
    else *(void **)((u8 *)arg0 + 4) = r5;
    return 1;
}

#pragma pop

MEMiHeapHead* MEMCreateExpHeapEx(void *start, u32 size, u16 opt) {
    u32 end = ((u32)size + (u32)start) & ~3;
    u32 base = ((u32)start + 3) & ~3;
    u32 diff;
    u32 block;
    u32 blockEnd;
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
    MEMiFinalizeHeap(heap);
    return heap;
}

#pragma dont_inline on
void* MEMAllocFromExpHeapEx(MEMiHeapHead* heap, u32 size, s32 align) {
    void* memBlock;
    register u32 rounded;

    if (size == 0) {
        size = 1;
    }
    rounded = size + 3;
    size = rounded & 0xFFFFFFFC;

    if ((*(u32 *)((u8 *)heap + 0x38) & 4) != 0) {
        OSLockMutex((OSMutex *)((u8 *)heap + 0x20));
    }

    if (align >= 0) {
        memBlock = AllocFromHead_(heap, size, align);
    } else {
        memBlock = AllocFromTail_(heap, size, -align);
    }

    if ((*(u32 *)((u8 *)heap + 0x38) & 4) != 0) {
        OSUnlockMutex((OSMutex *)((u8 *)heap + 0x20));
    }

    return memBlock;
}
#pragma dont_inline reset

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

MEMiHeapHead* MEMDestroyFrmHeap(MEMiHeapHead* heap) {
    MEMiFinalizeHeap(heap);
    return heap;
}

#pragma push
#pragma use_lmw_stmw off
void *MEMAllocFromFrmHeapEx(MEMiHeapHead *heap, u32 size, s32 align) {
    u32 start;
    u32 end;
    u32 alloc;
    u32 mask;
    u32 result;

    if (size == 0)
        size = 1;
    size = (size + 3) & ~3;
    if (*(u32 *)((u8 *)heap + 0x38) & 4)
        OSLockMutex((OSMutex *)((u8 *)heap + 0x20));
    if (align >= 0) {
        start = *(u32 *)((u8 *)heap + 0x3C);
        mask = ~(align - 1);
        result = (align + start - 1) & mask;
        alloc = size + result;
        end = *(u32 *)((u8 *)heap + 0x40);
        if (alloc > end) {
            result = 0;
        } else {
            u32 clearSize = alloc - start;
            if (*(u32 *)((u8 *)heap + 0x38) & 1)
                memset((void *)start, 0, clearSize);
            *(u32 *)((u8 *)heap + 0x3C) = alloc;
        }
    } else {
        end = *(u32 *)((u8 *)heap + 0x40);
        mask = ~(-align - 1);
        result = (end - size) & mask;
        start = *(u32 *)((u8 *)heap + 0x3C);
        if (result < start) {
            result = 0;
        } else {
            u32 clearSize = end - result;
            if (*(u32 *)((u8 *)heap + 0x38) & 1)
                memset((void *)result, 0, clearSize);
            *(u32 *)((u8 *)heap + 0x40) = result;
        }
    }
    if (*(u32 *)((u8 *)heap + 0x38) & 4)
        OSUnlockMutex((OSMutex *)((u8 *)heap + 0x20));
    return (void *)result;
}
#pragma pop

void MEMFreeToFrmHeap(MEMiHeapHead* heap, u32 flags) {
    MEMiFrmHeapHead *frm = (MEMiFrmHeapHead *)(heap + 1);
    LockHeap(heap);
    if (flags & MEM_FRM_HEAP_FREE_TO_HEAD) {
        frm->head = heap->start;
        frm->states = 0;
    }
    if (flags & MEM_FRM_HEAP_FREE_TO_TAIL) {
        MEMiFrmHeapState *state = frm->states;
        while (state != 0) {
            state->tail = heap->end;
            state = state->next;
        }
        frm->tail = heap->end;
    }
    UnlockHeap(heap);
}

u32 MEMGetAllocatableSizeForFrmHeapEx(MEMiHeapHead *heap, s32 align) {
    u32 size = (align < 0) ? (0 - align) : align;
    u32 start;
    u32 end;
    u32 result;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    start = *(u32 *)((u8 *)heap + 0x3C);
    end = *(u32 *)((u8 *)heap + 0x40);
    result = (size + start - 1) & (size - 1);
    if (result <= end) {
        result = end - result;
    } else {
        result = 0;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

BOOL MEMFreeByStateToFrmHeap(MEMiHeapHead* heap, u32 id) {
    u8 *base = (u8 *)heap;
    u32 size;
    MEMiFrmHeapState *state;
    #pragma unused(id)
    size = *(u32 *)(base + 0x40);
    LockHeap(heap);
    state = *(MEMiFrmHeapState **)(base + 0x3C);
    if (state != 0) {
        *(void **)(base + 0x3C) = *(void **)(state);
    }
    UnlockHeap(heap);
    if (state != 0 && (GetOptForHeap(heap) & MEM_HEAP_OPT_CLEAR_ALLOC)) {
        memset((void *)state, 0, size);
    }
    return (BOOL)state;
}

u32 MEMAdjustFrmHeap(MEMiHeapHead *heap) {
    MEMiFrmHeapHead *frm = (MEMiFrmHeapHead *)(heap + 1);
    MEMiFrmHeapState *state;
    u32 result = 0;
    LockHeap(heap);
    state = frm->states;
    if (state != 0) {
        result = (u32)state->head;
        frm->head = state->head;
    }
    UnlockHeap(heap);
    return result;
}

u32 MEMResizeForMBlockFrmHeap(MEMiHeapHead *heap, void *memBlock, u32 size) {
    void *state;
    u32 count = 0;
    #pragma unused(memBlock)
    #pragma unused(size)
    LockHeap(heap);
    state = *(void **)((u8 *)heap + 0x3C);
    while (state != 0) {
        state = *(void **)state;
        count++;
    }
    UnlockHeap(heap);
    return count;
}

#pragma dont_inline MEMAllocFromExpHeapEx
static void* AllocatorAllocForExpHeap_(MEMAllocator* allocator, u32 size) {
    return MEMAllocFromExpHeapEx(allocator->heap, size, allocator->heapParam1);
}

static void AllocatorFreeForExpHeap_(MEMAllocator* allocator, void* block) {
    MEMFreeToExpHeap(allocator->heap, block);
}

static void* AllocatorAllocForFrmHeap_(MEMAllocator* allocator, u32 size) {
    return MEMAllocFromFrmHeapEx(allocator->heap, size, allocator->heapParam1);
}

static void AllocatorFreeForFrmHeap_(MEMAllocator* allocator, void* block) {
#pragma unused(allocator)
#pragma unused(block)
}

void* MEMAllocFromAllocator(MEMAllocator* allocator, u32 size) {
    return allocator->funcs->allocFunc(allocator, size);
}

void MEMFreeToAllocator(MEMAllocator* allocator, void* block) {
    allocator->funcs->freeFunc(allocator, block);
}

void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, MEMiHeapHead* heap, s32 align) {
    extern const MEMAllocatorFuncs lbl_80560C38;
    allocator->funcs = &lbl_80560C38;
    allocator->heap = heap;
    allocator->heapParam1 = align;
    allocator->heapParam2 = 0;
}

void MEMInitAllocatorForFrmHeap(MEMAllocator* allocator, MEMiHeapHead* heap, s32 align) {
    extern const MEMAllocatorFuncs lbl_80560C40;
    allocator->funcs = &lbl_80560C40;
    allocator->heap = heap;
    allocator->heapParam1 = align;
    allocator->heapParam2 = 0;
}

void MEMInitList(MEMList* list, u16 offset) {
    list->offset = offset;
    list->head = 0;
    list->tail = 0;
    list->length = 0;
}

void MEMAppendListObject(MEMList* list, void* object) {
    if (list->head == 0) {
        MEMLink* link = (MEMLink*)((u8*)object + list->offset);
        link->next = 0;
        link->prev = 0;
        list->head = object;
        list->tail = object;
        list->length++;
    } else {
        u16 offset = list->offset;
        *(void**)((u8*)object + offset) = list->tail;
        *(void**)((u8*)object + offset + 4) = 0;
        *(void**)((u8*)list->tail + offset + 4) = object;
        list->tail = object;
        list->length++;
    }
}

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
void PSMTXConcat(register const Mtx a, register const Mtx b, register Mtx out) {
    register int i;
    for (i = 0; i < 3; i++) {
        out[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0] + a[i][2] * b[2][0];
        out[i][1] = a[i][0] * b[0][1] + a[i][1] * b[1][1] + a[i][2] * b[2][1];
        out[i][2] = a[i][0] * b[0][2] + a[i][1] * b[1][2] + a[i][2] * b[2][2];
        out[i][3] = a[i][0] * b[0][3] + a[i][1] * b[1][3] + a[i][2] * b[2][3] + a[i][3];
    }
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
    *(double *)&m[1][2] = (double)zero;
    m[0][0] = cosA; m[0][1] = zero;
    m[2][2] = cosA; m[2][3] = zero;
    m[1][0] = zero; m[1][1] = one;
    m[0][2] = sinA; m[0][3] = zero;
    m[2][0] = negSin; m[2][1] = zero;
    return (u32)m;
z_axis:
    *(double *)&m[0][2] = (double)zero;
    *(double *)&m[1][2] = (double)zero;
    *(double *)&m[2][0] = (double)zero;
    m[1][0] = sinA; m[1][1] = cosA;
    m[0][0] = cosA; m[0][1] = negSin;
    m[2][2] = one; m[2][3] = zero;
    return (u32)m;
}
#pragma pop

#pragma pop
extern f32 lbl_80560C48;
extern f32 lbl_80560C4C;
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

