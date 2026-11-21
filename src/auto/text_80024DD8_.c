// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Scan the first count bytes of src for byte ch; return a pointer to the first
 * match, or NULL if none is found. */
void *memchr(const void *src, int ch, unsigned int count) {
    unsigned int byte = (unsigned char)ch;
    const unsigned char *ptr;
    ptr = (const unsigned char *)src - 1;
    count++;
    while (--count) {
        if (*++ptr == byte) return (void *)ptr;
    }
    return 0;
}

/* Reverse memchr: scan the last count bytes of src backwards for val and return a pointer to the last match, or NULL. */
void *__memrchr(const unsigned char *src, int val, unsigned int count) {
    const unsigned char *p = src + count;
    unsigned char c = (unsigned char)val;
    unsigned int n = count + 1;
    while (--n != 0) {
        if (*--p == c) return (void *)p;
    }
    return 0;
}

/* Compare two byte buffers lexicographically; returns 0, <0, or >0. */
int memcmp(const unsigned char *arg0, const unsigned char *arg1, unsigned int arg2) {
    const unsigned char *p = arg0 - 1;
    const unsigned char *q = arg1 - 1;
    unsigned int n = arg2 + 1;
    while (--n != 0) {
        if (*++p != *++q) {
            if (*p < *q) return -1;
            return 1;
        }
    }
    return 0;
}

void __copy_longs_aligned(unsigned char *dst, const unsigned char *src, unsigned int n) {
    unsigned int *dw;
    unsigned int align = (-(unsigned int)dst) & 3;
    unsigned int blocks, words;
    const unsigned int *sw;
    unsigned char *tailDst;
    const unsigned char *tailSrc;
    src--;
    dst--;
    if (align) {
        n -= align;
        do { *++dst = *++src; } while (--align);
    }
    blocks = n >> 5; src -= 3; dst -= 3;
    sw = (const unsigned int *)src;
    dw = (unsigned int *)dst;
    if (blocks) {
        do {
            dw[1]=sw[1]; dw[2]=sw[2]; dw[3]=sw[3]; dw[4]=sw[4];
            dw[5]=sw[5]; dw[6]=sw[6]; dw[7]=sw[7]; dw[8]=sw[8];
            sw += 8; dw += 8;
        } while (--blocks);
    }
    words = (n >> 2) & 7;
    if (words) {
        do { dw[1] = sw[1]; sw++; dw++; } while (--words);
    }
    n &= 3;
    tailSrc = (const unsigned char *)sw + 3;
    tailDst = (unsigned char *)dw + 3;
    if (n) do { *++tailDst = *++tailSrc; } while (--n);
}

/* Copies n bytes backward from aligned end pointers, using byte alignment, 32-byte blocks, 4-byte words, then tail bytes. */
void __copy_longs_rev_aligned(unsigned char *dst, const unsigned char *src, unsigned int n) {
    unsigned char *dstEnd = dst + n;
    const unsigned char *srcEnd = src + n;
    unsigned int alignBytes = (unsigned int)dstEnd & 3, blockCount, wordCount;
    if (alignBytes) { n -= alignBytes; do { *--dstEnd = *--srcEnd; } while (--alignBytes); }
    blockCount = n >> 5;
    if (blockCount) {
        const unsigned int *srcWords = (const unsigned int *)srcEnd; unsigned int *dstWords = (unsigned int *)dstEnd;
        do {
            dstWords[-1] = srcWords[-1]; dstWords[-2] = srcWords[-2]; dstWords[-3] = srcWords[-3]; dstWords[-4] = srcWords[-4];
            dstWords[-5] = srcWords[-5]; dstWords[-6] = srcWords[-6]; dstWords[-7] = srcWords[-7]; dstWords[-8] = srcWords[-8];
            srcWords -= 8; dstWords -= 8;
        } while (--blockCount);
        srcEnd = (const unsigned char *)srcWords; dstEnd = (unsigned char *)dstWords;
    }
    wordCount = (n >> 2) & 7;
    if (wordCount) do { *(unsigned int *)(dstEnd - 4) = *(const unsigned int *)(srcEnd - 4); srcEnd -= 4; dstEnd -= 4; } while (--wordCount);
    n &= 3;
    if (n) do { *--dstEnd = *--srcEnd; } while (--n);
}

void __copy_longs_unaligned(unsigned char *dst, const unsigned char *src, unsigned int n) {
    unsigned int align = (-(unsigned int)dst) & 3;
    unsigned char *wordDst;
    unsigned int wordPairs;
    const unsigned char *s = src - 1;
    unsigned int srcOffset, shift, rightShift;
    unsigned int prevWord, curWord;
    unsigned char *tailDst;
    const unsigned char *tailSrc;
    /* Copy n bytes from src to dst when dst is not word-aligned, shifting
     * misaligned source words into aligned destination word stores. */
    dst--;
    if (align) {
        n -= align;
        do { *++dst = *++s; } while (--align);
    }
    srcOffset = (unsigned int)(s + 1) & 3;
    wordDst = dst - 3;
    wordPairs = n >> 3;
    s -= srcOffset;
    shift = srcOffset << 3;
    rightShift = 32 - shift;
    prevWord = *(const unsigned int *)(s += 1);
    do {
        curWord = *(const unsigned int *)(s + 4);
        --wordPairs;
        *(unsigned int *)(wordDst + 4) = (prevWord << shift) | (curWord >> rightShift);
        prevWord = *(const unsigned int *)(s += 8);
        *(unsigned int *)(wordDst += 8) = (curWord << shift) | (prevWord >> rightShift);
    } while (wordPairs);
    if (n & 4) {
        curWord = *(const unsigned int *)(s += 4);
        *(unsigned int *)(wordDst += 4) = (prevWord << shift) | (curWord >> rightShift);
    }
    n &= 3;
    tailSrc = s + 3;
    tailDst = wordDst + 3;
    if (n) {
        tailSrc -= 4 - srcOffset;
        do { *++tailDst = *++tailSrc; } while (--n);
    }
}

/* memmove's backward block copy (n >= 32, src and dst differently word-aligned):
   bytes down to an aligned destination, then whole 8-byte pairs rebuilt from two
   overlapping source words (the volatile word accesses keep mwcc from folding
   those overlapping loads), then the odd word and the leftover bytes. */
void __copy_longs_rev_unaligned(unsigned char *dst, const unsigned char *src, unsigned int n) {
    unsigned int wordPairs, srcOffset, leftShift, rightShift;
    unsigned int prev, cur;
    const unsigned char *srcEnd = src + n;
    unsigned char *dstEnd = dst + n;
    unsigned int alignBytes = (unsigned int)dstEnd & 3;
    if (alignBytes) {
        n -= alignBytes;
        do { *--dstEnd = *--srcEnd; } while (--alignBytes);
    }
    srcOffset = (unsigned int)srcEnd & 3;
    leftShift = srcOffset << 3;
    rightShift = 32 - leftShift;
    wordPairs = n >> 3;
    srcEnd += 4 - srcOffset;
    prev = *(const volatile unsigned int *)(srcEnd -= 4);
    do {
        cur = *(const volatile unsigned int *)(srcEnd - 4);
        --wordPairs;
        *(volatile unsigned int *)(dstEnd - 4) = (cur << leftShift) | (prev >> rightShift);
        prev = *(const volatile unsigned int *)(srcEnd -= 8);
        *(volatile unsigned int *)(dstEnd -= 8) = (prev << leftShift) | (cur >> rightShift);
    } while (wordPairs);
    if (n & 4) {
        cur = *(const volatile unsigned int *)(srcEnd -= 4);
        *(volatile unsigned int *)(dstEnd -= 4) = (cur << leftShift) | (prev >> rightShift);
    }
    n &= 3;
    if (n) {
        srcEnd += srcOffset;
        do { *--dstEnd = *--srcEnd; } while (--n);
    }
}

