// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void __copy_longs_unaligned(void *, const void *, unsigned long);
extern void __copy_longs_rev_unaligned(void *, const void *, unsigned long);
extern void __copy_longs_aligned(void *, const void *, unsigned long);
extern void __copy_longs_rev_aligned(void *, const void *, unsigned long);
/* Copy n bytes from src to dst, handling overlap by choosing forward or reverse copy. */
void *memmove(void *dst, const void *src, unsigned long n) {
    unsigned long addr_diff = (unsigned long)dst ^ (unsigned long)src;
    int copy_reverse = (unsigned long)dst > (unsigned long)src;
    if (n >= 32) {
        if (addr_diff & 3) {
            if (copy_reverse == 0) {
                __copy_longs_unaligned(dst, src, n);
            } else {
                __copy_longs_rev_unaligned(dst, src, n);
            }
        } else {
            if (copy_reverse == 0) {
                __copy_longs_aligned(dst, src, n);
            } else {
                __copy_longs_rev_aligned(dst, src, n);
            }
        }
        return dst;
    }
    if (!copy_reverse) {
        const unsigned char *s = (const unsigned char *)src - 1;
        unsigned char *d = (unsigned char *)dst - 1;
        n++;
        while (--n) *++d = *++s;
    } else {
        const unsigned char *s = (const unsigned char *)src + n;
        unsigned char *d = (unsigned char *)dst + n;
        n++;
        while (--n) *--d = *--s;
    }
    return dst;
}
