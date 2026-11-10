// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

extern unsigned int lbl_802ED860[];
extern void Block_link(void*, void*);
extern void __sys_free(void*);

#define sFixedPoolSizes lbl_802ED860

#define sFixedPoolSizes lbl_802ED860
void deallocate_from_fixed_pools(void ***, unsigned char *, unsigned int);

typedef struct {
    void (*function)(void ***, unsigned char *, unsigned int);
    unsigned int size;
    const unsigned long long *extab;
} ET_ExtabIndex;

#pragma section ".extab"
DECL_SECTION(".extab") const unsigned long long etb_80004540 = 0x1008000000000000ULL;
#pragma section ".extabindex"
DECL_SECTION(".extabindex") const ET_ExtabIndex eti_80004730 = {
    deallocate_from_fixed_pools, 0x1EC, &etb_80004540
};

typedef struct ET_FixBlock ET_FixBlock;
typedef struct ET_FixSubBlock {
    ET_FixBlock *block_;
    struct ET_FixSubBlock *next_;
} ET_FixSubBlock;
struct ET_FixBlock {
    ET_FixBlock *prev_;
    ET_FixBlock *next_;
    unsigned int client_size_;
    ET_FixSubBlock *start_;
    unsigned int n_allocated_;
};
/* Frees a block allocated from the fixed-size pool list and returns its backing block to the system allocator when empty. */
void deallocate_from_fixed_pools(void ***poolList, unsigned char *ptr, unsigned int size) {
    register unsigned int *poolSize = sFixedPoolSizes;
    register unsigned int poolIndex = 0;
    ET_FixSubBlock *subBlock;
    ET_FixBlock *block;
    unsigned char *poolEntry;
    unsigned int flags;
    unsigned char *heapBlock;
    unsigned int *isFreeable;
    unsigned char *nextNode;

    while (size > *poolSize) {
        poolSize++;
        poolIndex++;
    }
    subBlock = (ET_FixSubBlock *)(ptr - 4);
    block = subBlock->block_;
    poolEntry = (unsigned char *)poolList + poolIndex * 8;
    if (block->start_ == 0) {
        ET_FixBlock *head = *(ET_FixBlock **)(poolEntry + 8);
        if (head != block) {
            if (*(ET_FixBlock **)(poolEntry + 4) == block) {
                *(ET_FixBlock **)(poolEntry + 8) = head->prev_;
                head = *(ET_FixBlock **)(poolEntry + 4);
                *(ET_FixBlock **)(poolEntry + 4) = head->prev_;
            } else {
                block->prev_->next_ = block->next_;
                block->next_->prev_ = block->prev_;
                head = *(ET_FixBlock **)(poolEntry + 8);
                block->next_ = head;
                block->prev_ = head->prev_;
                block->prev_->next_ = block;
                block->next_->prev_ = block;
                *(ET_FixBlock **)(poolEntry + 8) = block;
            }
        }
    }
    subBlock->next_ = block->start_;
    block->start_ = subBlock;
    if (--block->n_allocated_ == 0) {
        if (*(ET_FixBlock **)(poolEntry + 8) == block)
            *(ET_FixBlock **)(poolEntry + 8) = block->next_;
        if (*(ET_FixBlock **)(poolEntry + 4) == block)
            *(ET_FixBlock **)(poolEntry + 4) = block->prev_;
        block->prev_->next_ = block->next_;
        block->next_->prev_ = block->prev_;
        if (*(ET_FixBlock **)(poolEntry + 8) == block)
            *(ET_FixBlock **)(poolEntry + 8) = 0;
        if (*(ET_FixBlock **)(poolEntry + 4) == block)
            *(ET_FixBlock **)(poolEntry + 4) = 0;
        heapBlock = (unsigned char *)block - 8;
        heapBlock = (unsigned char *)(*(unsigned int *)(heapBlock + 4) & ~1u);
        Block_link(heapBlock, (unsigned char *)block - 8);
        flags = *(unsigned int *)(heapBlock + 0x10);
        isFreeable = (unsigned int *)0;
        if (!(flags & 2) &&
            ((flags & ~7u) == ((*(unsigned int *)(heapBlock + 0xC) & ~7u) - 0x18)))
            isFreeable = (unsigned int *)1;
        if (isFreeable != 0) {
            unsigned char *prevNode = *(unsigned char **)(heapBlock + 4);
            if (prevNode == heapBlock)
                prevNode = 0;
            if ((unsigned char *)*poolList == heapBlock)
                *poolList = (void **)prevNode;
            if (prevNode != 0) {
                nextNode = *(unsigned char **)heapBlock;
                *(unsigned char **)prevNode = nextNode;
                *(unsigned char **)(nextNode + 4) = prevNode;
            }
            *(unsigned char **)(heapBlock + 4) = 0;
            *(unsigned char **)heapBlock = 0;
            __sys_free(heapBlock);
        }
    }
}
