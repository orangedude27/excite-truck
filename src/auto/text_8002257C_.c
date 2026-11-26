// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Set on first use, after the static pool below has been cleared. */
extern unsigned char lbl_8055D678;
#define sPoolInitialized lbl_8055D678

/* 0x34-byte static pool backing the allocator's small-block lists. */
extern unsigned char lbl_8035BB58[];
#define sHeapPool lbl_8035BB58

extern void *memset(void *, int, unsigned int);

/* Allocates from the size-class pools (sizes up to 0x44 bytes). */
extern void *fn_80022188(unsigned int, int);
#define allocSmallBlock fn_80022188

/* Allocates a large block from the system heap. */
extern void *memAlloc(unsigned int, int);
#define allocLargeBlock memAlloc

/* Allocate size bytes from the game's heap, lazily initializing the static pool. */
void *malloc(unsigned int size) {
    void *heapPool;
    void *result;
    if (size != 0) {
        if (sPoolInitialized == 0) {
            memset(sHeapPool, 0, 0x34);
            sPoolInitialized = 1;
        }
        heapPool = sHeapPool;
        if (size > (unsigned int)-0x31) {
            result = 0;
        } else if (size <= 0x44) {
            result = ((void *(*)(void *, unsigned int, int))allocSmallBlock)(heapPool, size, 0);
        } else {
            result = ((void *(*)(void *, unsigned int, int))allocLargeBlock)(heapPool, size, 0);
        }
        return result;
    }
    return 0;
}
