// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void SubBlock_merge_next(unsigned int *arg0, void **arg1) {
    unsigned int size;
    unsigned int next;
    unsigned int offset;
    unsigned int *block;
    unsigned int combined;
    unsigned int flags;
    size = *arg0;
    offset = size & ~7u;
    block = (unsigned int *)((unsigned char *)arg0 + offset);
    next = *block;
    if (next & 2)
        return;
    combined = offset + (next & ~7u);
    flags = (combined & ~7u) | (size & 7u);
    *arg0 = flags;
    if (!(flags & 2))
        *(unsigned int *)((unsigned char *)arg0 + combined - 4) = combined;
    if (!(*arg0 & 2))
        *(unsigned int *)((unsigned char *)arg0 + combined) &= ~4;
    else
        *(unsigned int *)((unsigned char *)arg0 + combined) |= 4;
    if (*arg1 == block)
        *arg1 = *(void **)((unsigned char *)*arg1 + 12);
    if (*arg1 == block)
        *arg1 = 0;
    *(void **)((unsigned char *)*(void **)((unsigned char *)block + 12) + 8) = *(void **)((unsigned char *)block + 8);
    *(void **)((unsigned char *)*(void **)((unsigned char *)block + 8) + 12) = *(void **)((unsigned char *)block + 12);
}
