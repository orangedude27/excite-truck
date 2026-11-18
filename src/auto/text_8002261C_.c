// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8035BB58[];
extern unsigned char lbl_8055D678;
extern void *memset(void *, int, unsigned int);
extern void deallocate_from_fixed_pools(void ***, unsigned char *, unsigned int);
extern void Block_link(void *, void *);
extern void __sys_free(void *);
void free(void *arg0) {
    void ***pool;
    unsigned int size;
    unsigned int block;
    unsigned int flags;
    unsigned char *sb;
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
        sb = (unsigned char *)arg0 - 8;
        arg0 = (void *)(*(volatile unsigned int *)((unsigned char *)arg0 - 4) & ~1u);
        Block_link(arg0, sb);
        flags = *(unsigned int *)((unsigned char *)arg0 + 0x10);
        size = 0;
        if ((flags & 2) == 0 && ((flags & ~7u) == ((*(unsigned int *)((unsigned char *)arg0 + 0xC) & ~7u) - 0x18))) {
            size = 1;
        }
        if (size != 0) {
            unsigned char *prev;
            prev = *(unsigned char **)((unsigned char *)arg0 + 4);
            if (prev == (unsigned char *)arg0) {
                prev = 0;
            }
            if ((unsigned char *)*pool == (unsigned char *)arg0) {
                *pool = (void **)prev;
            }
            if (prev != 0) {
                next = *(unsigned char **)arg0;
                *(unsigned char **)prev = next;
                *(unsigned char **)(next + 4) = prev;
            }
            *(unsigned char **)((unsigned char *)arg0 + 4) = 0;
            *(unsigned char **)arg0 = 0;
            __sys_free(arg0);
        }
    }
}
