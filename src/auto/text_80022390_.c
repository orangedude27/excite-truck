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
#pragma section ".extab"
#pragma section ".extabindex"
/* Returns a suballocation to its fixed-size pool and, when its block becomes empty, unlinks and frees the backing heap block if it is now a standalone free region. */
void deallocate_from_fixed_pools(void ***heapList, unsigned char *ptr, unsigned int size) {
    register unsigned int *sizes = sFixedPoolSizes;
    register unsigned int i = 0;
    ET_FixSubBlock *subBlock;
    ET_FixBlock *fixBlock;
    unsigned char *poolList;
    unsigned int flags;
    unsigned char *heapBlock;
    unsigned int *canFree;
    unsigned char *next;

    while (size > *sizes) {
        sizes++;
        i++;
    }
    subBlock = (ET_FixSubBlock *)(ptr - 4);
    fixBlock = subBlock->block_;
    poolList = (unsigned char *)heapList + i * 8;
    if (fixBlock->start_ == 0) {
        ET_FixBlock *head = *(ET_FixBlock **)(poolList + 8);
        if (head != fixBlock) {
            if (*(ET_FixBlock **)(poolList + 4) == fixBlock) {
                *(ET_FixBlock **)(poolList + 8) = head->prev_;
                head = *(ET_FixBlock **)(poolList + 4);
                *(ET_FixBlock **)(poolList + 4) = head->prev_;
            } else {
                fixBlock->prev_->next_ = fixBlock->next_;
                fixBlock->next_->prev_ = fixBlock->prev_;
                head = *(ET_FixBlock **)(poolList + 8);
                fixBlock->next_ = head;
                fixBlock->prev_ = head->prev_;
                fixBlock->prev_->next_ = fixBlock;
                fixBlock->next_->prev_ = fixBlock;
                *(ET_FixBlock **)(poolList + 8) = fixBlock;
            }
        }
    }
    subBlock->next_ = fixBlock->start_;
    fixBlock->start_ = subBlock;
    if (--fixBlock->n_allocated_ == 0) {
        if (*(ET_FixBlock **)(poolList + 8) == fixBlock)
            *(ET_FixBlock **)(poolList + 8) = fixBlock->next_;
        if (*(ET_FixBlock **)(poolList + 4) == fixBlock)
            *(ET_FixBlock **)(poolList + 4) = fixBlock->prev_;
        fixBlock->prev_->next_ = fixBlock->next_;
        fixBlock->next_->prev_ = fixBlock->prev_;
        if (*(ET_FixBlock **)(poolList + 8) == fixBlock)
            *(ET_FixBlock **)(poolList + 8) = 0;
        if (*(ET_FixBlock **)(poolList + 4) == fixBlock)
            *(ET_FixBlock **)(poolList + 4) = 0;
        heapBlock = (unsigned char *)fixBlock - 8;
        heapBlock = (unsigned char *)(*(unsigned int *)(heapBlock + 4) & ~1u);
        Block_link(heapBlock, (unsigned char *)fixBlock - 8);
        flags = *(unsigned int *)(heapBlock + 0x10);
        canFree = (unsigned int *)0;
        if (!(flags & 2) &&
            ((flags & ~7u) == ((*(unsigned int *)(heapBlock + 0xC) & ~7u) - 0x18)))
            canFree = (unsigned int *)1;
        if (canFree != 0) {
            unsigned char *prev = *(unsigned char **)(heapBlock + 4);
            if (prev == (unsigned char *)heapBlock)
                prev = 0;
            if ((unsigned char *)*heapList == heapBlock)
                *heapList = (void **)prev;
            if (prev != 0) {
                next = *(unsigned char **)heapBlock;
                *(unsigned char **)prev = next;
                *(unsigned char **)(next + 4) = prev;
            }
            *(unsigned char **)(heapBlock + 4) = 0;
            *(unsigned char **)heapBlock = 0;
            __sys_free(heapBlock);
        }
    }
}
