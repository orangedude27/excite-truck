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

#pragma opt_strength_reduction off
void fn_801AFAC8(void) {
    lbl_8055E640 = ((int (*)(int, int, int, int, int))fn_8002F37C)(fn_8012850C(0xC90, lbl_803359E0), 0, 0, 0x64, 0x20);
    {
        int off = 0;
        int i;
        for (i = 0; i < 2; i++) {
            *(int *)(lbl_8055E640 + off + 0x50) = 0;
            *(int *)(lbl_8055E640 + off + 0xB4) = 0;
            *(int *)(lbl_8055E640 + off + 0x118) = 0;
            *(int *)(lbl_8055E640 + off + 0x17C) = 0;
            *(int *)(lbl_8055E640 + off + 0x1E0) = 0;
            *(int *)(lbl_8055E640 + off + 0x244) = 0;
            *(int *)(lbl_8055E640 + off + 0x2A8) = 0;
            *(int *)(lbl_8055E640 + off + 0x30C) = 0;
            off += 0x320;
            *(int *)(lbl_8055E640 + off + 0x50) = 0;
            *(int *)(lbl_8055E640 + off + 0xB4) = 0;
            *(int *)(lbl_8055E640 + off + 0x118) = 0;
            *(int *)(lbl_8055E640 + off + 0x17C) = 0;
            *(int *)(lbl_8055E640 + off + 0x1E0) = 0;
            *(int *)(lbl_8055E640 + off + 0x244) = 0;
            *(int *)(lbl_8055E640 + off + 0x2A8) = 0;
            *(int *)(lbl_8055E640 + off + 0x30C) = 0;
            off += 0x320;
        }
    }
}
#pragma opt_strength_reduction reset
/* Release the heap-allocated "tire_list" table (undoing its 0x10 allocator header)
 * and clear the global pointer. */
void fn_801AFBE8(void) {
    if (gTireListBuffer != 0) {
        memFree(gTireListBuffer - ALLOC_HEADER_SIZE);
    }
    gTireListBuffer = 0;
}
