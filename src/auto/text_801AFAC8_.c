// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E640;
extern int fn_80128670(int);
extern int fn_8002F37C(int, int, int, int);
extern int fn_8012850C(int, void *);
extern char lbl_803359E0[];

/* The global "tire_list" table is heap-allocated; the allocator returns a pointer
 * 0x10 past the block base, and fn_80128670 is the matching free routine. */
#define gTireListBuffer  lbl_8055E640
#define memFree          fn_80128670
#define ALLOC_HEADER_SIZE 0x10

void fn_801AFAC8(void) {
    register int off asm("r5") = 0;
    register int ctr asm("r0") = 2;
    register int zero asm("r4") = 0;
    fn_8012850C(0xC90, lbl_803359E0);
    lbl_8055E640 = fn_8002F37C(0, 0, 0x64, 0x20);
    while (ctr--) {
        *(int *)(lbl_8055E640 + off + 0x50) = zero;
        *(int *)(lbl_8055E640 + off + 0xB4) = zero;
        *(int *)(lbl_8055E640 + off + 0x118) = zero;
        *(int *)(lbl_8055E640 + off + 0x17C) = zero;
        *(int *)(lbl_8055E640 + off + 0x1E0) = zero;
        *(int *)(lbl_8055E640 + off + 0x244) = zero;
        *(int *)(lbl_8055E640 + off + 0x2A8) = zero;
        *(int *)(lbl_8055E640 + off + 0x30C) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x50) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0xB4) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x118) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x17C) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x1E0) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x244) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x2A8) = zero;
        *(int *)(lbl_8055E640 + off + 0x320 + 0x30C) = zero;
        off += 0x640;
    }
}

/* Release the heap-allocated "tire_list" table (undoing its 0x10 allocator header)
 * and clear the global pointer. */
void fn_801AFBE8(void) {
    if (gTireListBuffer != 0) {
        memFree(gTireListBuffer - ALLOC_HEADER_SIZE);
    }
    gTireListBuffer = 0;
}
