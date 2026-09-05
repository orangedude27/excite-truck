/* REXE01 MSL allocation helpers recovered from the former runtime clone
 * staging file. The game-region pool ABI remains authoritative. */
#include <types.h>

/* ---------- Block / SubBlock (Block_link + SubBlock_merge_next) ---------- */
typedef struct SubBlock SubBlock;
typedef struct Block Block;

struct Block {
    struct Block* prev;
    struct Block* next;
    unsigned long max_size;
    unsigned long size;
};

struct SubBlock {
    unsigned long size;
    Block* block;
    struct SubBlock* prev;
    struct SubBlock* next;
};

extern void* my_pool_alloc(void* pool, unsigned long size);
extern void my_pool_free(void* pool, void* ptr);
extern void* memset(void*, int, unsigned long);

#define SubBlock_size(ths) ((ths)->size & 0xFFFFFFF8)
#define Block_size(ths) ((ths)->size & 0xFFFFFFF8)
#define Block_start(ths) (*(SubBlock**)((char*)(ths) + Block_size((ths)) - sizeof(unsigned long)))

void Block_link(Block* ths, SubBlock* sb) {
    SubBlock** st;
    *(unsigned long*)((char*)sb + SubBlock_size(sb)) &= ~0x4;
    st = &Block_start(ths);

    if (*st != NULL) {
        sb->prev = (*st)->prev;
        sb->prev->next = sb;
        sb->next = *st;
        (*st)->prev = sb;
        *st = sb;
    } else {
        *st = sb;
        sb->prev = sb;
        sb->next = sb;
    }
    if (ths->max_size < SubBlock_size(*st))
        ths->max_size = SubBlock_size(*st);
}

void SubBlock_merge_next(SubBlock *pBlock, SubBlock **pStart) {
    SubBlock* next_sub_block;
    unsigned long this_cur_size;

    next_sub_block = (SubBlock*)((char*)pBlock + (pBlock->size & 0xFFFFFFF8));
    if (!(next_sub_block->size & 2)) {
        this_cur_size = (pBlock->size & 0xFFFFFFF8) + (next_sub_block->size & 0xFFFFFFF8);
        pBlock->size = (pBlock->size & 0x4) | this_cur_size;
        *(unsigned long*)((char*)pBlock + this_cur_size) |= 0x4;
        pBlock->size |= 0x2;
        if (*pStart == next_sub_block) *pStart = next_sub_block->next;
        next_sub_block->next->prev = next_sub_block->prev;
        next_sub_block->prev->next = next_sub_block->next;
    }
}

/* ---------- malloc / free (game-region clones) ---------- */
extern unsigned char lbl_8055D678;   /* s_initialized */
extern unsigned char lbl_8035BB58[]; /* static pool (0x34 bytes) */

void* malloc(unsigned long size) {
    /* Petari's malloc_pool_obj + get_malloc_pool() + my_pool_alloc.
     * The game-region clone does inline initialization: if s_initialized == 0,
     * memset(&static_pool, 0, 0x34); s_initialized = 1; then call my_pool_alloc. */
    extern void* memset(void*, int, unsigned long);

    if (size == 0) return NULL;

    if (lbl_8055D678 == 0) {
        memset(lbl_8035BB58, 0, 0x34);
        lbl_8055D678 = 1;
    }

    if (size > (unsigned long)0xFFFFFFCF) return NULL;
    /* The rest is the inline my_pool_alloc body; we author it as a call to
     * an external my_pool_alloc helper to keep this file readable. */
    return my_pool_alloc(lbl_8035BB58, size);
}

void free(void* ptr) {
    my_pool_free(lbl_8035BB58, ptr);
}

