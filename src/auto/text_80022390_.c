// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_802ED860[];
extern void Block_link(void*, void*);
extern void __sys_free(void*);

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
    register unsigned char *pool;
    register unsigned char *node;
    register unsigned char *list;
    unsigned int n;
    register unsigned char *p;
    unsigned char *q;
    unsigned char *block;
    unsigned int flags;
    unsigned int *var;
    unsigned char *next;

    while (arg2 > *sizes) {
        sizes++;
        i++;
    }
    pool = arg1 - 4;
    node = *(unsigned char **)(arg1 - 4);
    list = (unsigned char *)arg0 + i * 8;
    if (*(void **)(node + 0xC) == 0) {
        p = *(unsigned char **)(list + 8);
        if (p != node) {
            if (*(unsigned char **)(list + 4) == node) {
                *(unsigned char **)(list + 8) = *(unsigned char **)p;
                p = *(unsigned char **)(list + 4);
                *(unsigned char **)(list + 4) = *(unsigned char **)p;
            } else {
                *(unsigned char **)(*(unsigned char **)node + 4) = *(unsigned char **)(node + 4);
                *(unsigned char **)(*(unsigned char **)(node + 4)) = *(unsigned char **)node;
                p = *(unsigned char **)(list + 8);
                *(unsigned char **)(node + 4) = p;
                q = *(unsigned char **)p;
                *(unsigned char **)node = q;
                *(unsigned char **)(q + 4) = node;
                *(unsigned char **)(*(unsigned char **)(node + 4)) = node;
                *(unsigned char **)(list + 8) = node;
            }
        }
    }
    *(unsigned char **)(pool + 4) = *(unsigned char **)(node + 0xC);
    *(unsigned char **)(node + 0xC) = pool;
    n = *(unsigned int *)(node + 0x10) - 1;
    *(unsigned int *)(node + 0x10) = n;
    if (n == 0) {
        if (*(unsigned char **)(list + 8) == node)
            *(unsigned char **)(list + 8) = *(unsigned char **)(node + 4);
        if (*(unsigned char **)(list + 4) == node)
            *(unsigned char **)(list + 4) = *(unsigned char **)node;
        *(unsigned char **)(*(unsigned char **)node + 4) = *(unsigned char **)(node + 4);
        *(unsigned char **)(*(unsigned char **)(node + 4)) = *(unsigned char **)node;
        if (*(unsigned char **)(list + 8) == node)
            *(unsigned char **)(list + 8) = 0;
        if (*(unsigned char **)(list + 4) == node)
            *(unsigned char **)(list + 4) = 0;
        block = node - 8;
        block = (unsigned char *)(*(unsigned int *)(block + 4) & ~1u);
        Block_link(block, node - 8);
        flags = *(unsigned int *)(block + 0x10);
        var = (unsigned int *)0;
        if (!(flags & 2) &&
            ((flags & ~7u) == ((*(unsigned int *)(block + 0xC) & ~7u) - 0x18)))
            var = (unsigned int *)1;
        if (var != 0) {
            unsigned char *prev = *(unsigned char **)(block + 4);
            if (prev == block)
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
