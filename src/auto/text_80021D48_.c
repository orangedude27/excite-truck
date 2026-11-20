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
    if (*list == 0) {
        *list = bp;
        bp->prev = bp;
        bp->next = bp;
    } else {
        bp->prev = (*list)->prev;
        bp->prev->next = bp;
        bp->next = *list;
        (*list)->prev = bp;
        *list = bp;
    }
    return bp;
}
static inline Block* Pool_expand(Block** list, unsigned int size) {
    unsigned int total = (size + 0x1f) & ~7;
    Block* b;
    char* sb;
    char* end;
    unsigned int flags, remain;
    if (total < 0x10000) total = 0x10000;
    b = (Block*)__sys_alloc(total);
    if (b == 0) return 0;
    flags = total | 3;
    b->size_flags = flags;
    *(unsigned int*)((char*)b + total - 8) = flags;
    b->sb_link = (unsigned int)b | 1;
    remain = total - 0x18;
    b->sb_size = remain;
    sb = (char*)b + 0x10;
    *(unsigned int*)(total + (unsigned int)sb - 0x1c) = remain;
    b->max_size = remain;
    end = (char*)b + (b->size_flags & ~7);
    *(unsigned int*)(end - 4) = 0;
    Block_link(b, sb);
    if (*list) {
        Block* head = *list;
        Block* first = head->prev;
        b->prev = first;
        first->next = b;
        b->next = *list;
        (*list)->prev = b;
        *list = b;
    } else {
        *list = b;
        b->prev = b;
        b->next = b;
    }
    return b;
}
extern int fn_8002194C(void*, unsigned int, int*);
int fn_80021D48(Block** arg0, int arg1, int* arg2) {
    Block* node;
    unsigned int size;
    int result;
    if (arg2) *arg2 = 0;
    size = (arg1 + 15) & ~7;
    if (size < 0x50) size = 0x50;
    node = *arg0;
    if (node == 0) node = Pool_expand(arg0, size);
    if (node == 0) return 0;
    for (;;) {
        if (size <= node->max_size) {
            result = fn_8002194C(node, size, arg2);
            if (result != 0) {
                *arg0 = node;
                break;
            }
        }
        node = node->next;
        if (node == *arg0) {
            node = Pool_expand(arg0, size);
            if (node == 0) return 0;
            result = fn_8002194C(node, size, arg2);
            break;
        }
    }
    return result + 8;
}
