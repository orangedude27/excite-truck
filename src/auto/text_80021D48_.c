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
static inline void SubBlock_construct(SubBlock* ths, unsigned int size, Block* bp, int prev_alloc, int this_alloc) {
    ths->bp = (Block*)((unsigned int)bp | 1);
    ths->size = size;
    if (prev_alloc) ths->size |= 2;
    if (this_alloc) ths->size |= 1;
    else *((unsigned int*)((char*)ths + size) - 1) = size;
}
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
extern int fn_8002194C(void*, unsigned int, int*);
int fn_80021D48(Block** arg0, int arg1, int* arg2) {
    Block* bp;
    int ptr;
    if (arg2) *arg2 = 0;
    arg1 = (arg1 + 15) & ~7;
    if ((unsigned int)arg1 < 0x50) arg1 = 0x50;
    bp = *arg0 != 0 ? *arg0 : link_new_block(arg0, arg1);
    if (bp == 0) return 0;
    do {
        if ((unsigned int)arg1 <= bp->max_size) {
            ptr = fn_8002194C(bp, arg1, arg2);
            if (ptr != 0) {
                *arg0 = bp;
                break;
            }
        }
        bp = bp->next;
        if (bp == *arg0) {
            bp = link_new_block(arg0, arg1);
            if (bp == 0) return 0;
            ptr = fn_8002194C(bp, arg1, arg2);
            break;
        }
    } while (1);
    return ptr + 8;
}
