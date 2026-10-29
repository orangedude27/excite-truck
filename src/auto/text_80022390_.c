// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

extern unsigned int lbl_802ED860[];
extern void Block_link(void*, void*);
extern void __sys_free(void*);
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
void deallocate_from_fixed_pools(void ***arg0, unsigned char *arg1, unsigned int arg2) {
    register unsigned int *sizes = lbl_802ED860;
    register unsigned int i = 0;
    ET_FixSubBlock *sb;
    ET_FixBlock *b;
    unsigned char *list;
    unsigned int flags;
    unsigned char *block;
    unsigned int *var;
    unsigned char *next;

    while (arg2 > *sizes) {
        sizes++;
        i++;
    }
    sb = (ET_FixSubBlock *)(arg1 - 4);
    b = sb->block_;
    list = (unsigned char *)arg0 + i * 8;
    if (b->start_ == 0) {
        ET_FixBlock *head = *(ET_FixBlock **)(list + 8);
        if (head != b) {
            if (*(ET_FixBlock **)(list + 4) == b) {
                *(ET_FixBlock **)(list + 8) = head->prev_;
                head = *(ET_FixBlock **)(list + 4);
                *(ET_FixBlock **)(list + 4) = head->prev_;
            } else {
                b->prev_->next_ = b->next_;
                b->next_->prev_ = b->prev_;
                head = *(ET_FixBlock **)(list + 8);
                b->next_ = head;
                b->prev_ = head->prev_;
                b->prev_->next_ = b;
                b->next_->prev_ = b;
                *(ET_FixBlock **)(list + 8) = b;
            }
        }
    }
    sb->next_ = b->start_;
    b->start_ = sb;
    if (--b->n_allocated_ == 0) {
        if (*(ET_FixBlock **)(list + 8) == b)
            *(ET_FixBlock **)(list + 8) = b->next_;
        if (*(ET_FixBlock **)(list + 4) == b)
            *(ET_FixBlock **)(list + 4) = b->prev_;
        b->prev_->next_ = b->next_;
        b->next_->prev_ = b->prev_;
        if (*(ET_FixBlock **)(list + 8) == b)
            *(ET_FixBlock **)(list + 8) = 0;
        if (*(ET_FixBlock **)(list + 4) == b)
            *(ET_FixBlock **)(list + 4) = 0;
        block = (unsigned char *)b - 8;
        block = (unsigned char *)(*(unsigned int *)(block + 4) & ~1u);
        Block_link(block, (unsigned char *)b - 8);
        flags = *(unsigned int *)(block + 0x10);
        var = (unsigned int *)0;
        if (!(flags & 2) &&
            ((flags & ~7u) == ((*(unsigned int *)(block + 0xC) & ~7u) - 0x18)))
            var = (unsigned int *)1;
        if (var != 0) {
            unsigned char *prev = *(unsigned char **)(block + 4);
            if (prev == (unsigned char *)block)
                prev = 0;
            if ((unsigned char *)*arg0 == block)
                *arg0 = (void **)prev;
            if (prev != 0) {
                next = *(unsigned char **)block;
                *(unsigned char **)prev = next;
                *(unsigned char **)(next + 4) = prev;
            }
            *(unsigned char **)(block + 4) = 0;
            *(unsigned char **)block = 0;
            __sys_free(block);
        }
    }
}
