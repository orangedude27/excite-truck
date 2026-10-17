// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *memchr(const unsigned char *arg0, int arg1, unsigned int arg2) {
    const unsigned char *p = arg0 - 1;
    unsigned int n = arg2 + 1;
    if ((unsigned char)arg1 == *++p) return (void *)p;
    while (--n != 0) {
        if ((unsigned char)arg1 == *++p) return (void *)p;
    }
    return 0;
}

void *__memrchr(const unsigned char *arg0, int arg1, unsigned int arg2) {
    const unsigned char *p = arg0 + arg2;
    unsigned int n = arg2 + 1;
    if (*--p == (unsigned char)arg1) return (void *)p;
    do {
        if (--n == 0) break;
        if (*--p == (unsigned char)arg1) return (void *)p;
    } while (1);
    return 0;
}

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
    unsigned int align = (-(unsigned int)dst) & 3;
    const unsigned char *s = src - 1;
    unsigned char *d = dst - 1;
    unsigned int blocks, words, tail;
    if (align) {
        n -= align;
        do { *++d = *++s; } while (--align);
    }
    blocks = n >> 5; s -= 3; d -= 3;
    if (blocks) {
        const unsigned int *sw = (const unsigned int *)s;
        unsigned int *dw = (unsigned int *)d;
        do {
            dw[1]=sw[1]; dw[2]=sw[2]; dw[3]=sw[3]; dw[4]=sw[4];
            dw[5]=sw[5]; dw[6]=sw[6]; dw[7]=sw[7]; dw[8]=sw[8];
            sw += 8; dw += 8;
        } while (--blocks);
        s = (const unsigned char *)sw; d = (unsigned char *)dw;
    }
    words = (n >> 2) & 7;
    if (words) {
        do { *(unsigned int *)(d+4)=*(const unsigned int *)(s+4); s+=4; d+=4; } while (--words);
    }
    tail=n&3; s+=3; d+=3;
    if(tail) do { *++d=*++s; } while(--tail);
}

void __copy_longs_rev_aligned(unsigned char *dst, const unsigned char *src, unsigned int n) {
    unsigned char *d=dst+n; const unsigned char *s=src+n;
    unsigned int align=(unsigned int)d&3, blocks, words;
    if(align) { n-=align; do { *--d=*--s; } while(--align); }
    blocks=n>>5;
    if(blocks) {
        const unsigned int *sw=(const unsigned int *)s; unsigned int *dw=(unsigned int *)d;
        do {
            dw[-1]=sw[-1]; dw[-2]=sw[-2]; dw[-3]=sw[-3]; dw[-4]=sw[-4];
            dw[-5]=sw[-5]; dw[-6]=sw[-6]; dw[-7]=sw[-7]; dw[-8]=sw[-8];
            sw-=8; dw-=8;
        } while(--blocks);
        s=(const unsigned char *)sw; d=(unsigned char *)dw;
    }
    words=(n>>2)&7;
    if(words) do { *(unsigned int *)(d-4)=*(const unsigned int *)(s-4); s-=4; d-=4; } while(--words);
    n &= 3;
    if(n) do { *--d=*--s; } while(--n);
}

