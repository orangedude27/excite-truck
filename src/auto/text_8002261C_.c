// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8035BB58[];
extern unsigned char lbl_8055D678;
extern void *memset(void *, int, unsigned int);
extern void deallocate_from_fixed_pools(void *, void *);
extern void Block_link(unsigned int, void *);
extern void __sys_free(unsigned int);
void free(void *arg0) {
    unsigned int size, block, flags;
    unsigned int *p;
    void **pool;
    void *prev;
    if (lbl_8055D678 == 0) {
        memset(lbl_8035BB58, 0, 0x34);
        lbl_8055D678 = 1;
    }
    pool = (void **)lbl_8035BB58;
    if (arg0 != 0) {
        block = *(unsigned int *)((char *)arg0 - 4);
        if ((block & 1) == 0) {
            size = *(unsigned int *)(block + 8);
        } else {
            size = (*(unsigned int *)((char *)arg0 - 8) & 0xFFFFFFF8) - 8;
        }
        if (size <= 0x44) {
            deallocate_from_fixed_pools(pool, arg0);
            return;
        }
        block &= 0xFFFFFFFE;
        Block_link(block, (char *)arg0 - 8);
        p = (unsigned int *)block;
        flags = p[4];
        size = 0;
        if ((flags & 2) == 0 && (flags & 0xFFFFFFF8) == ((p[3] & 0xFFFFFFF8) - 0x18)) size = 1;
        if (size != 0) {
            prev = (void *)p[1];
            if (prev == p) prev = 0;
            if (pool[0] == p) pool[0] = prev;
            if (prev != 0) {
                *(void **)prev = *(void **)p;
                *((void **)prev + 1) = (void *)p;
            }
            p[1] = 0;
            p[0] = 0;
            __sys_free(block);
        }
    }
}
