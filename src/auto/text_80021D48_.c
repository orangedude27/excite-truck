// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* __sys_alloc(unsigned int);
typedef struct Block {
    struct Block* prev;
    struct Block* next;
    unsigned int max_size;
    unsigned int size_flags;
    unsigned int sb_size;
    unsigned int sb_link;
} Block;
extern void Block_link(void*, void*);
typedef struct SubBlock {
    unsigned int size;
    Block* bp;
} SubBlock;
/* Initialize a subblock header: size/flags plus the owning block's pointer tagged in
   its low bit; when this subblock is free, write its size as the trailing boundary tag. */
/* Initialize a subblock header: size/flags plus the owning block's pointer tagged in
   its low bit; when this subblock is free, write its size as the trailing boundary tag. */
static inline void SubBlock_construct(SubBlock* ths, unsigned int size, Block* bp, int prev_alloc, int this_alloc) {
    ths->bp = (Block*)((unsigned int)bp | 1);
    ths->size = size;
    if (prev_alloc) ths->size |= 2;
    if (this_alloc) ths->size |= 1;
    else *((unsigned int*)((char*)ths + size) - 1) = size;
}
/* Initialize a fresh Block: boundary tags, one free subblock covering the payload,
   and a link into the free list. */
static inline void Block_construct(Block* ib, unsigned int size) {
    SubBlock* sb;
    ib->size_flags = size | 3;
    *(unsigned int*)((char*)ib + size - 8) = ib->size_flags;
    sb = (SubBlock*)((char*)ib + 0x10);
    SubBlock_construct(sb, size - 0x18, ib, 0, 0);
    ib->max_size = size - 0x18;
    *(unsigned int*)((char*)ib + (ib->size_flags & ~7) - 4) = 0;
    Block_link(ib, sb);
}
/* Allocate a new Block (rounding size up, with a 0x10000 minimum) and insert it at
   the head of the circular list; returns 0 if the system allocator fails. */
static inline Block* link_new_block(Block** list, unsigned int size) {
    Block* bp;
    size = (size + 0x1f) & ~7;
    if (size < 0x10000) size = 0x10000;
    bp = (Block*)__sys_alloc(size);
    if (bp == 0) return 0;
    Block_construct(bp, size);
    if (*list != 0) {
        bp->prev = (*list)->prev;
        bp->prev->next = bp;
        bp->next = *list;
        (*list)->prev = bp;
        *list = bp;
    } else {
        *list = bp;
        bp->prev = bp;
        bp->next = bp;
    }
    return bp;
}
extern int Block_subBlock(void*, unsigned int, int*);
// mem_alloc: allocate `size` bytes from the circular list of Blocks in *list.
// Rounds the size up to 8 (minimum 0x50), walks the list for a block with enough
// free space (Block_alloc), and links in a fresh block if none fits.
// Returns the data pointer (8 bytes past the subblock header), or 0 on failure;
// *outMax receives the largest size the chosen block could serve.
int memAlloc(Block** list, int size, int* outMax) {
    Block* block;
    int ptr;
    if (outMax) *outMax = 0;
    size = (size + 15) & ~7;
    if ((unsigned int)size < 0x50) size = 0x50;
    block = *list != 0 ? *list : link_new_block(list, size);
    if (block == 0) return 0;
    do {
        if ((unsigned int)size <= block->max_size) {
            ptr = Block_subBlock(block, size, outMax);
            if (ptr != 0) {
                *list = block;
                break;
            }
        }
        block = block->next;
        if (block == *list) {
            block = link_new_block(list, size);
            if (block == 0) return 0;
            ptr = Block_subBlock(block, size, outMax);
            break;
        }
    } while (1);
    return ptr + 8;
}
