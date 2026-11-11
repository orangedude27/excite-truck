// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8035BB58[];
extern unsigned char lbl_8055D678;
extern void *memset(void *, int, unsigned int);
extern void deallocate_from_fixed_pools(void ***, unsigned char *, unsigned int);
extern void Block_link(void *, void *);
extern void __sys_free(void *);
void free(void *arg0) {
    unsigned int size;
    unsigned int block;
    void ***pool;
    unsigned char *heapBlock;
    unsigned int flags;
    unsigned int *canFree;
    unsigned char *prev;
    unsigned char *next;
    if (lbl_8055D678 == 0) {
        memset(lbl_8035BB58, 0, 0x34);
        lbl_8055D678 = 1;
    }
    pool = (void ***)lbl_8035BB58;
    if (arg0 != 0) {
        block = *(unsigned int *)((unsigned char *)arg0 - 4);
        if ((block & 1) == 0) {
            size = *(unsigned int *)(block + 8);
        } else {
            size = (*(unsigned int *)((unsigned char *)arg0 - 8) & ~7u) - 8;
        }
        if (size <= 68) {
            deallocate_from_fixed_pools(pool, (unsigned char *)arg0, size);
            return;
        }
        heapBlock = (unsigned char *)(*(unsigned int *)((unsigned char *)arg0 - 4) & ~1u);
        Block_link(heapBlock, (unsigned char *)arg0 - 8);
        flags = *(unsigned int *)(heapBlock + 0x10);
        canFree = (unsigned int *)0;
        if ((flags & 2) == 0 && ((flags & ~7u) == ((*(unsigned int *)(heapBlock + 0xC) & ~7u) - 0x18))) {
            canFree = (unsigned int *)1;
        }
        if (canFree != 0) {
            prev = *(unsigned char **)(heapBlock + 4);
            if (prev == heapBlock) {
                prev = 0;
            }
            if ((unsigned char *)*pool == heapBlock) {
                *pool = (void **)prev;
            }
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
