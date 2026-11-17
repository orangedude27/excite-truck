// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* No-op default constructor registered by fn_800218FC for the 8-element array of 0x70-byte records at lbl_8035B758; leaves each element untouched. */
void fn_80021948(void) {

}

void *fn_8002194C(void *arg0, unsigned int size, unsigned int *outMax) {
    unsigned int *heap = (unsigned int *)arg0;
    unsigned int *blk;
    unsigned int *newb;
    unsigned int *head;
    unsigned int cur, maxSize;
    unsigned int w0, t, rem;
    int hasNext, nextBit;
    unsigned char *end;

    head = *(unsigned int **)((unsigned char *)heap + (heap[3] & ~7) - 4);
    if (head == 0) {
        heap[2] = 0;
        return 0;
    }
    blk = head;
    cur = blk[0] & ~7;
    maxSize = cur;
    while (cur < size) {
        blk = (unsigned int *)blk[3];
        cur = blk[0] & ~7;
        if (maxSize < cur) maxSize = cur;
        if (blk == head) {
            heap[2] = maxSize;
            if (outMax != 0) *outMax = maxSize - 8;
            return 0;
        }
    }
    if (cur - size >= 0x50) {
        newb = (unsigned int *)((unsigned char *)blk + size);
        w0 = blk[0];
        t = (blk[1] & ~1) | 1;
        rem = w0 & ~7;
        blk[1] = t;
        hasNext = !(w0 & 2);
        blk[0] = size;
        if (w0 & 4) blk[0] |= 4;
        nextBit = !hasNext;
        if (nextBit) {
            blk[0] |= 2;
            newb[0] |= 4;
        } else {
            newb[-1] = size;
        }
        newb[1] = t;
        rem = rem - size;
        newb[0] = rem;
        if (nextBit) newb[0] |= 4;
        if (nextBit) {
            newb[0] |= 2;
            *(unsigned int *)((unsigned char *)newb + rem) |= 4;
        } else {
            *(unsigned int *)((unsigned char *)newb + rem - 4) = rem;
        }
        if (hasNext) {
            unsigned int *n = (unsigned int *)blk[3];
            newb[3] = (unsigned int)n;
            n[2] = (unsigned int)newb;
            newb[2] = (unsigned int)blk;
            blk[3] = (unsigned int)newb;
        }
    }
    *(unsigned int **)((unsigned char *)heap + (heap[3] & ~7) - 4) = (unsigned int *)blk[3];
    w0 = blk[0];
    blk[0] = w0 | 2;
    *(unsigned int *)((unsigned char *)blk + (w0 & ~7)) |= 4;
    end = (unsigned char *)heap + (heap[3] & ~7);
    if (*(unsigned int **)(end - 4) == blk) *(unsigned int **)(end - 4) = (unsigned int *)blk[3];
    if (*(unsigned int **)(end - 4) == blk) {
        *(unsigned int *)(end - 4) = 0;
        heap[2] = 0;
    } else {
        ((unsigned int *)blk[3])[2] = blk[2];
        ((unsigned int *)blk[2])[3] = blk[3];
    }
    if (outMax != 0) *outMax = (blk[0] & ~7) - 8;
    return blk;
}

