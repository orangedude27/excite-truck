// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055D678;
extern unsigned char lbl_8035BB58[];
extern void *memset(void *, int, unsigned int);
extern void *fn_80022188(unsigned int, int);
extern void *fn_80021D48(unsigned int, int);
/* Allocates from the game's heap, lazily initializing the global pool on first use. */
void *malloc(unsigned int size) {
    void *heapPool;
    void *result;
    if (size != 0) {
        if (lbl_8055D678 == 0) {
            memset(lbl_8035BB58, 0, 0x34);
            lbl_8055D678 = 1;
        }
        heapPool = lbl_8035BB58;
        if (size > (unsigned int)-0x31) {
            result = 0;
        } else if (size <= 0x44) {
            result = ((void *(*)(void *, unsigned int, int))fn_80022188)(heapPool, size, 0);
        } else {
            result = ((void *(*)(void *, unsigned int, int))fn_80021D48)(heapPool, size, 0);
        }
        return result;
    }
    return 0;
}
