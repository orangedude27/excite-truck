// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <revolution/MEM.h>
#include "revolution/KPAD/__KPAD.h"
#include "revolution/OS/OSInterrupt.h"

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
#pragma pop

MEMiHeapHead* MEMCreateExpHeapEx(void *start, u32 size, u16 opt) {
    u32 end = ((u32)size + (u32)start) & ~3;
    u32 base = ((u32)start + 3) & ~3;
    u32 diff;
    u32 block;
    u32 blockEnd;
    if (base <= end) {
        diff = end - base;
        if (diff >= 0x64U) {
            MEMiInitHeapHead((MEMiHeapHead *)base, 0x45585048, (void *)(base + 0x50), (void *)end, opt);
            *(u16 *)(base + 0x4C) = 0;
            *(u16 *)(base + 0x4E) = 0;
            block = *(u32 *)(base + 0x18);
            blockEnd = *(u32 *)(base + 0x1C);
            *(u16 *)(block + 2) = 0;
            *(u16 *)block = 0x4652;
            *(u32 *)(block + 4) = blockEnd - (block + 0x10);
            *(u32 *)(block + 8) = 0;
            *(u32 *)(block + 0xC) = 0;
            *(u32 *)(base + 0x3C) = block;
            *(u32 *)(base + 0x40) = block;
            *(u32 *)(base + 0x44) = 0;
            *(u32 *)(base + 0x48) = 0;
            return (MEMiHeapHead *)base;
        }
    }
    return 0;
}

MEMiHeapHead* MEMDestroyExpHeap(MEMiHeapHead* heap) {
    MEMiFinalizeHeap(heap);
    return heap;
}

MEMiHeapHead* MEMCreateFrmHeapEx(void *start, u32 size, u16 opt) {
    u32 end = ((u32)size + (u32)start) & ~3;
    u32 base = ((u32)start + 3) & ~3;
    u32 diff;
    if (base > end) return 0;
    diff = end - base;
    if (diff < 0x48U) return 0;
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

void MEMFreeToFrmHeap(MEMiHeapHead* heap, u32 flags) {
    MEMiFrmHeapHead *frm = (MEMiFrmHeapHead *)(heap + 1);
    LockHeap(heap);
    if (flags & MEM_FRM_HEAP_FREE_TO_HEAD) {
        frm->states = 0;
        frm->head = heap->start;
    }
    if (flags & MEM_FRM_HEAP_FREE_TO_TAIL) {
        MEMiFrmHeapState *state = frm->states;
        while (state != 0) {
            state->tail = heap->start;
            state = state->next;
        }
        frm->tail = heap->end;
    }
    UnlockHeap(heap);
}

u32 MEMGetAllocatableSizeForFrmHeapEx(MEMiHeapHead *heap, s32 align) {
    u32 size = align < 0 ? -align : align;
    u32 start;
    u32 end;
    u32 result;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    start = (u32)heap->start;
    end = (u32)heap->end;
    result = (size + start - 1) & ~(size - 1);
    if (result > end) result = 0;
    else result = end - result;
    OSRestoreInterrupts(enabled);
    return result;
}

BOOL MEMFreeByStateToFrmHeap(MEMiHeapHead* heap, u32 id) { return FALSE; }

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

