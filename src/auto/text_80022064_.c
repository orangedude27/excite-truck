// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern const int lbl_802ED860[];
void fn_80022064(void *arg0, void *arg1, void **arg2, int index, void *arg4, unsigned int size) {
    unsigned char *node = (unsigned char *)arg0;
    unsigned int entry = lbl_802ED860[index];
    unsigned int step = entry + 4;
    unsigned int count = size / step;
    unsigned int i;
    unsigned char *current = (unsigned char *)arg4;
    unsigned char *next;

    *(void **)node = arg1;
    *(void **)(node + 4) = arg2;
    *(void **)((unsigned char *)arg1 + 4) = arg0;
    *arg2 = arg0;
    *(unsigned int *)(node + 8) = entry;
    for (i = 0; i < count - 1; i++) {
        next = current + step;
        *(void **)current = arg0;
        *(void **)(current + 4) = next;
        current = next;
    }
    *(void **)current = arg0;
    *(void **)(current + 4) = 0;
    *(void **)(node + 0xC) = arg4;
    *(int *)(node + 0x10) = 0;
}
