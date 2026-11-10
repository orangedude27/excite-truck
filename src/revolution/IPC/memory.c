#include <revolution/IPC.h>
#include <revolution/OS.h>

#define IPC_HEAP_MAX 8

typedef enum {
    IPC_HEAP_CHUNK_FREE = 0xBABE0000,
    IPC_HEAP_CHUNK_USED = 0xBABE0001,
    IPC_HEAP_CHUNK_FORALIGN = 0xBABE0002
};

typedef struct IPCHeapChunk {
    u32 magic;                 // at 0x0
    u32 size;                  // at 0x4
    struct IPCHeapChunk* prev; // at 0x8
    struct IPCHeapChunk* next; // at 0xC
} IPCHeapChunk;

typedef struct IPCHeapDesc {
    void* start;        // at 0x0
    u32 WORD_0x4;       // at 0x4
    u32 size;           // at 0x8
    IPCHeapChunk* head; // at 0xC
} IPCHeapDesc;

static IPCHeapDesc __heaps[IPC_HEAP_MAX];

static void __iosCoalesceChunk(IPCHeapChunk* chunk) {
    IPCHeapChunk* next;

    if (chunk == NULL) {
        return;
    }

    if ((u8*)chunk->next != (u8*)chunk + chunk->size + sizeof(IPCHeapChunk)) {
        return;
    }

    next = chunk->next;

    chunk->next = next->next;
    if (chunk->next != NULL) {
        chunk->next->prev = chunk;
    }

    chunk->size += next->size + sizeof(IPCHeapChunk);
}

s32 iosCreateHeap(void* base, u32 size) {
    /* Creates an IOS IPC heap in a 32-byte-aligned region by initializing its first free chunk in __heaps; returns the heap index or an internal error code. */
    s32 ret = IPC_RESULT_INVALID_INTERNAL;
    BOOL enabled = OSDisableInterrupts();
    IPCHeapDesc* desc;
    s32 i;

    if ((u32)base % 32 != 0) {
        goto _exit;
    }

    for (i = 0; i < IPC_HEAP_MAX; i++) {
        if (__heaps[i].start == NULL) {
            break;
        }
    }

    if (i == IPC_HEAP_MAX) {
        ret = IPC_RESULT_CONN_MAX_INTERNAL;
        goto _exit;
    }

    desc = &__heaps[i];
    desc->start = base;
    desc->size = size;
    desc->head = (IPCHeapChunk*)base;

    desc->head->magic = IPC_HEAP_CHUNK_FREE;
    desc->head->size = size - sizeof(IPCHeapChunk);
    desc->head->prev = NULL;
    desc->head->next = NULL;

    ret = i;

_exit:
    OSRestoreInterrupts(enabled);
    return ret;
}

// Allocates a block from an IOS/IPC heap: finds the best-fit free chunk, optionally
// splits it, marks it used (inserting an alignment marker when needed), and returns
// the aligned usable pointer, or NULL on failure.
void* __iosAlloc(s32 handle, u32 size, u32 align) {
    BOOL interruptsEnabled;
    IPCHeapDesc* heapDesc;
    u8* allocatedBlock;
    IPCHeapChunk* chunk;
    IPCHeapChunk* bestChunk;
    u8* bestUsablePtr;
    u32 bestAlignPadding;

    allocatedBlock = NULL;
    interruptsEnabled = OSDisableInterrupts();

    if (size == 0 || align == 0) {
        goto _exit;
    }

    if (align & (align - 1)) {
        goto _exit;
    }

    if (align < 32) {
        align = 32;
    }

    size = ROUND_UP(size, 32);

    if (handle < 0 || handle >= IPC_HEAP_MAX || __heaps[handle].start == NULL) {
        allocatedBlock = NULL;
        goto _exit;
    }

    heapDesc = &__heaps[handle];
    bestChunk = NULL;

    // Find chunk best fit for specified size
    for (chunk = heapDesc->head; chunk != NULL; chunk = chunk->next) {
        u8* chunkMem = (u8*)chunk + sizeof(IPCHeapChunk);
        u32 chunkUnalign =
            (align - 1) & (align - ((u32)chunkMem & (align - 1)));

        if (chunk->size == size && chunkUnalign == 0) {
            bestChunk = chunk;
            break;
        }

        if (chunk->size < size + chunkUnalign) {
            continue;
        }

        if (bestChunk == NULL || chunk->size < bestChunk->size) {
            bestChunk = chunk;
        }
    }

    if (bestChunk == NULL) {
        goto _exit;
    }

    bestUsablePtr = (u8*)bestChunk + sizeof(IPCHeapChunk);
    bestAlignPadding = (align - 1) & (align - ((u32)bestUsablePtr & (align - 1)));

    // Split off extra size that won't be used by this allocation
    if (bestChunk->size > size + bestAlignPadding + sizeof(IPCHeapChunk)) {
        IPCHeapChunk* restChunk = (IPCHeapChunk*)((u8*)bestChunk + size + bestAlignPadding +
                                             sizeof(IPCHeapChunk));

        restChunk->magic = IPC_HEAP_CHUNK_FREE;
        restChunk->size = bestChunk->size - size - bestAlignPadding - sizeof(IPCHeapChunk);
        restChunk->next = bestChunk->next;

        if (restChunk->next != NULL) {
            restChunk->next->prev = restChunk;
        }

        bestChunk->next = restChunk;
        bestChunk->size = size + bestAlignPadding;
    }

    bestChunk->magic = IPC_HEAP_CHUNK_USED;

    // Remove chunk from list
    if (bestChunk->prev != NULL) {
        bestChunk->prev->next = bestChunk->next;
    } else {
        heapDesc->head = bestChunk->next;
    }

    if (bestChunk->next != NULL) {
        bestChunk->next->prev = bestChunk->prev;
    }

    bestChunk->next = NULL;
    bestChunk->prev = NULL;

    // For unaligned chunks, create a header where one would normally be.
    // To find the real chunk, you take the FORALIGN one and jump back one.
    allocatedBlock = (u8*)bestChunk + bestAlignPadding + sizeof(IPCHeapChunk);
    if (bestAlignPadding != 0) {
        IPCHeapChunk* alignedChunk = (IPCHeapChunk*)(allocatedBlock - sizeof(IPCHeapChunk));
        alignedChunk->magic = IPC_HEAP_CHUNK_FORALIGN;
        alignedChunk->prev = bestChunk;
    }

_exit:
    OSRestoreInterrupts(interruptsEnabled);
    return allocatedBlock;
}

void* iosAlloc(s32 handle, u32 size) {
    return __iosAlloc(handle, size, 32);
}

void* iosAllocAligned(s32 handle, u32 size, u32 align) {
    return __iosAlloc(handle, size, align);
}

// Frees a block from an IPC heap: validates the handle and pointer, returns the
// block's chunk to the free list in address order, and coalesces it with adjacent
// free chunks.
s32 iosFree(s32 handle, void* block) {
    IPCHeapChunk* chunk;
    IPCHeapChunk* it;
    IPCHeapDesc* desc;
    BOOL enabled;
    s32 ret;

    ret = IPC_RESULT_INVALID_INTERNAL;
    enabled = OSDisableInterrupts();

    if (block == NULL) {
        goto _exit;
    }

    if (handle < 0 || handle >= IPC_HEAP_MAX || __heaps[handle].start == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
        goto _exit;
    }

    desc = &__heaps[handle];

    if ((u8*)block < (u8*)desc->start + sizeof(IPCHeapChunk)) {
        goto _exit;
    }

    if ((u8*)block > (u8*)desc->start + desc->size) {
        goto _exit;
    }

    chunk = (IPCHeapChunk*)((u8*)block - sizeof(IPCHeapChunk));

    // Find *real* chunk from alignment helper
    if (chunk->magic == IPC_HEAP_CHUNK_FORALIGN) {
        chunk = chunk->prev;
    }

    if (chunk->magic != IPC_HEAP_CHUNK_USED) {
        goto _exit;
    }

    chunk->magic = IPC_HEAP_CHUNK_FREE;

    // Next chunk after freed
    for (it = desc->head; it != NULL; it = it->next) {
        if (it->next == NULL || it->next > chunk) {
            break;
        }
    }

    // Place chunk back in list
    if (it != NULL && chunk > it) {
        chunk->prev = it;
        chunk->next = it->next;
        it->next = chunk;

        if (chunk->next != NULL) {
            chunk->next->prev = chunk;
        }
    } else {
        chunk->next = desc->head;
        desc->head = chunk;
        chunk->prev = NULL;

        if (chunk->next != NULL) {
            chunk->next->prev = chunk;
        }
    }

    __iosCoalesceChunk(chunk);
    __iosCoalesceChunk(chunk->prev);
    ret = IPC_RESULT_OK;

_exit:
    OSRestoreInterrupts(enabled);
    return ret;
}
