// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

unsigned char *strcpy(unsigned char *dst, const unsigned char *src) {
    unsigned char *p = dst;
    const unsigned char *q = src;
    unsigned int align;
    unsigned int a;
    unsigned int x;
    int n;

    /* Copy string from src to dst; uses word-at-a-time fast path when alignments match. */
    if (((unsigned int)p & 3) != (align = (unsigned int)q & 3)) {
        goto byte_tail;
    }
    if (align == 0) {
        goto word_loop;
    }
    if ((*p = *q) == 0) {
        return dst;
    }
    n = 3 - align;
    while (n-- != 0) {
        if ((*++p = *++q) == 0) {
            return dst;
        }
    }
    p++;
    q++;

word_loop:
    a = *(const unsigned int *)q;
    x = a - 0x01010101;
    x &= ~a;
    if (x & 0x80808080) {
        goto byte_tail;
    }
    p -= 4;
    do {
        *(unsigned int *)(p += 4) = a;
        a = *(const unsigned int *)(q += 4);
        x = a - 0x01010101;
        x &= ~a;
    } while (!(x & 0x80808080));
    p += 4;

byte_tail:
    if ((*p = *q) == 0) {
        return dst;
    }
    while ((*++p = *++q) != 0) {
    }
    return dst;
}

/* Copy at most n bytes from src to dst, padding with null bytes if src is shorter than n. */
unsigned char *strncpy(unsigned char *dst, const unsigned char *src, int n) {
    const unsigned char *srcPtr = src - 1;
    unsigned char *dstPtr = dst - 1;
    int count = n + 1;
    while (--count != 0) {
        unsigned char c = *++srcPtr;
        *++dstPtr = c;
        if (c == 0) {
            while (--count != 0)
                *++dstPtr = 0;
            return dst;
        }
    }
    return dst;
}

/* Append src to dst (strcat): find the end of dst, copy src over it including
 * its terminating NUL, and return dst. */
unsigned char *fn_80028E00(unsigned char *dst, const unsigned char *src) {
    const unsigned char *srcPtr = src - 1;
    unsigned char *dstEnd = dst - 1;
    while (*++dstEnd != 0) {
    }
    dstEnd--;
    do {
        *++dstEnd = *++srcPtr;
    } while (*dstEnd != 0);
    return dst;
}

/* fn_80028E2C: bounded string concatenation (strncat). Finds the end of dst,
   appends at most n bytes from src, and always writes a terminating NUL. */
unsigned char *fn_80028E2C(unsigned char *dst, const unsigned char *src, int n) {
    const unsigned char *srcPtr = src - 1;
    unsigned char *dstEnd = dst - 1;
    unsigned char ch;

    while (*++dstEnd != 0) {
    }
    dstEnd--;
    n++;
    while (--n != 0) {
        ch = *++srcPtr;
        *++dstEnd = ch;
        if (ch == 0) {
            dstEnd--;
            goto done;
        }
    }
done:
    *++dstEnd = 0;
    return dst;
}

/* Compare two null-terminated byte strings lexicographically.
   Fast path compares a word at a time when both pointers share alignment,
   using 0xFEFEFEFF/0x80808080 to detect a zero byte within a word. */
int strcmp(const unsigned char *left, const unsigned char *right) {
    int diff;
    unsigned int alignment;
    unsigned int wordLeft, wordRight, zeroCheck;
    unsigned char ch;
    ch = *left;
    diff = ch - *right;
    if (diff) return diff;
    if (((unsigned int)right & 3) != (alignment = (unsigned int)left & 3)) goto byte_loop;
    if (alignment == 0) goto word_loop;
    if (ch == 0) return 0;
    {
        int remaining = 3 - alignment;
        while (remaining-- != 0) {
            ch = *++left;
            diff = ch - *++right;
            if (diff) return diff;
            if (!ch) return 0;
        }
    }
    left++; right++;
word_loop:
    wordLeft = *(const unsigned int *)left;
    wordRight = *(const unsigned int *)right;
    zeroCheck = wordLeft + 0xFEFEFEFFu;
    zeroCheck &= ~wordLeft;
    if (zeroCheck & 0x80808080u) goto compare_tail;
    while (wordLeft == wordRight) {
        wordLeft = *(const unsigned int *)(left += 4);
        wordRight = *(const unsigned int *)(right += 4);
        zeroCheck = wordLeft + 0xFEFEFEFFu;
        zeroCheck &= 0x80808080u;
        if (zeroCheck) goto compare_tail;
    }
compare_tail:
    ch = *left;
    diff = ch - *right;
    if (diff) return diff;
byte_loop:
    if (!ch) return 0;
    do {
        ch = *++left;
        diff = ch - *++right;
        if (diff) return diff;
        if (!ch) return 0;
    } while (1);
}

/* Compares up to n bytes of two strings, stopping at the first difference or a NUL terminator; returns the difference of the differing bytes. */
int strncmp(const unsigned char *s1, const unsigned char *s2, int n) {
    const unsigned char *p = s1 - 1;
    const unsigned char *q = s2 - 1;
    unsigned char a, b;
    n++;
    while (--n != 0) {
        a = *++p;
        b = *++q;
        if (a != b)
            return a - b;
        if (a == 0)
            break;
    }
    return 0;
}

/* Returns a pointer to the first occurrence of (unsigned char)chr in str, or 0
   if not found; a zero chr matches the terminating NUL. */
char *strchr(const char *str, int chr) {
    const unsigned char *p = (const unsigned char *)str - 1;
    unsigned long want = (chr & 0xff);
    unsigned long cur;

    while (cur = *++p) {
        if (cur == want) {
            return ((char *)p);
        }
    }

    return (want ? 0 : (char *)p);
}

unsigned char *fn_80029004(const unsigned char *s, int c) {
    /* Return a pointer to the last occurrence of (unsigned char)c in s, or 0 if not found (like strrchr). */
    const unsigned char *p = s - 1;
    unsigned long ch = (c & 0xff);
    unsigned long cur;
    unsigned char *last = 0;

    while (cur = *++p) {
        if (cur == ch) {
            last = (unsigned char *)p;
        }
    }
    if (last != 0)
        return last;
    return (ch ? 0 : (unsigned char *)p);
}

unsigned char *strstr(const unsigned char *haystack, const unsigned char *needle) {
    /* Find the first occurrence of needle in haystack, returning a pointer within haystack or NULL. */
    const unsigned char *scan = haystack - 1;
    unsigned int firstChar;
    unsigned char current;

    if (needle == 0) return (unsigned char *)haystack;
    firstChar = *needle;
    if (firstChar == 0) return (unsigned char *)haystack;
    while ((current = *++scan) != 0) {
        if (current == firstChar) {
            unsigned int haystackChar;
            unsigned int needleChar;
            const unsigned char *haystackPos = scan - 1;
            const unsigned char *needlePos = needle - 1;
            do {
                haystackChar = *++haystackPos;
                needleChar = *++needlePos;
            } while (haystackChar == needleChar && haystackChar != 0);
            if (needleChar == 0) return (unsigned char *)scan;
        }
    }
    return 0;
}

