// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <revolution/MEM.h>

static void* AllocatorAllocForExpHeap_(MEMAllocator* allocator, u32 size) {
    return MEMAllocFromExpHeapEx(allocator->heap, size, allocator->heapParam1);
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

void MEMInitList(MEMList* list, u16 offset) {
    list->offset = offset;
    list->head = 0;
    list->tail = 0;
    list->length = 0;
}

void MEMAppendListObject(MEMList* list, void* object) {
    MEMLink* link = (MEMLink*)((u8*)object + list->offset);
    if (list->head == 0) {
        link->prev = 0;
        link->next = 0;
        list->head = object;
        list->tail = object;
    } else {
        MEMLink* tailLink = (MEMLink*)((u8*)list->tail + list->offset);
        link->prev = list->tail;
        link->next = 0;
        tailLink->next = object;
        list->tail = object;
    }
    list->length++;
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

