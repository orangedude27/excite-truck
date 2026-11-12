// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void SubBlock_merge_next(unsigned int *subBlock, void **freeListHead) {
    /* Merge subBlock with the following subblock when it is free, updating the
       combined size/flags, boundary tags, and removing the next subblock from
       the free list if needed. */
    unsigned int size;
    unsigned int next;
    unsigned int offset;
    unsigned int *nextBlock;
    unsigned int combined;
    unsigned int flags;
    size = *subBlock;
    offset = size & ~7u;
    nextBlock = (unsigned int *)((unsigned char *)subBlock + offset);
    next = *nextBlock;
    if (next & 2)
        return;
    combined = offset + (next & ~7u);
    flags = (combined & ~7u) | (size & 7u);
    *subBlock = flags;
    if (!(flags & 2))
        *(unsigned int *)((unsigned char *)subBlock + combined - 4) = combined;
    if (!(*subBlock & 2))
        *(unsigned int *)((unsigned char *)subBlock + combined) &= ~4;
    else
        *(unsigned int *)((unsigned char *)subBlock + combined) |= 4;
    if (*freeListHead == nextBlock)
        *freeListHead = *(void **)((unsigned char *)*freeListHead + 12);
    if (*freeListHead == nextBlock)
        *freeListHead = 0;
    *(void **)((unsigned char *)*(void **)((unsigned char *)nextBlock + 12) + 8) = *(void **)((unsigned char *)nextBlock + 8);
    *(void **)((unsigned char *)*(void **)((unsigned char *)nextBlock + 8) + 12) = *(void **)((unsigned char *)nextBlock + 12);
}
