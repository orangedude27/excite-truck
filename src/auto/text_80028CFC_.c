// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

unsigned char *strcpy(unsigned char *dst, const unsigned char *src) {
    unsigned char *p = dst;
    const unsigned char *q = src;
    unsigned int align;
    unsigned int a;
    unsigned int x;
    int n;

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

unsigned char *strncpy(unsigned char *dst, const unsigned char *src, int n) {
    const unsigned char *q = src - 1;
    unsigned char *p = dst - 1;
    int count = n + 1;
    while (--count != 0) {
        unsigned char c = *++q;
        *++p = c;
        if (c == 0) {
            while (--count != 0)
                *++p = 0;
            return dst;
        }
    }
    return dst;
}

unsigned char *fn_80028E00(unsigned char *dst, const unsigned char *src) {
    const unsigned char *q = src - 1;
    unsigned char *p = dst - 1;
    while (*++p != 0) {
    }
    p--;
    do {
        *++p = *++q;
    } while (*p != 0);
    return dst;
}

unsigned char *fn_80028E2C(unsigned char *dst, const unsigned char *src, int n) {
    const unsigned char *q = src - 1;
    unsigned char *p = dst - 1;
    unsigned char ch;

    while (*++p != 0) {
    }
    p--;
    n++;
    while (--n != 0) {
        ch = *++q;
        *++p = ch;
        if (ch == 0) {
            p--;
            goto done;
        }
    }
done:
    *++p = 0;
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

char *strchr(const char *str, int chr) {
    const unsigned char *p = (const unsigned char *)str - 1;
    unsigned long c = (chr & 0xff);
    unsigned long ch;

    while (ch = *++p) {
        if (ch == c) {
            return ((char *)p);
        }
    }

    return (c ? 0 : (char *)p);
}

unsigned char *fn_80029004(const unsigned char *s, int c) {
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

unsigned char *strstr(const unsigned char *s, const unsigned char *find) {
    const unsigned char *p = s - 1;
    unsigned int first;
    unsigned char current;

    if (find == 0) return (unsigned char *)s;
    first = *find;
    if (first == 0) return (unsigned char *)s;
    while ((current = *++p) != 0) {
        if (current == first) {
            unsigned int x;
            unsigned int y;
            const unsigned char *a = p - 1;
            const unsigned char *b = find - 1;
            do {
                x = *++a;
                y = *++b;
            } while (x == y && x != 0);
            if (y == 0) return (unsigned char *)p;
        }
    }
    return 0;
}

