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

void strncpy(unsigned char *dst, const unsigned char *src, int n) {
    unsigned char *p = dst - 1;
    const unsigned char *q = src - 1;
    int count = n + 1;
    while (--count != 0) {
        unsigned char c = *++q;
        *++p = c;
        if (c == 0) {
            while (--count != 0)
                *++p = 0;
            return;
        }
    }
}

void fn_80028E00(unsigned char *dst, const unsigned char *src) {
    unsigned char *p;
    const unsigned char *q;
    q = src - 1;
    p = dst - 1;
    while (*++p != 0) {
    }
    p--;
    do {
        *++p = *++q;
    } while (*p != 0);
}

void fn_80028E2C(unsigned char *dst, const unsigned char *src, int n) {
    unsigned char ch;

    src--;
    dst--;
    while (*++dst != 0) {
    }
    dst--;
    n = n + 1;
    goto test;
copy:
    ch = *++src;
    *++dst = ch;
    if (ch == 0) {
        dst--;
        goto done;
    }
test:
    n = n - 1;
    if (n != 0)
        goto copy;
done:
    *++dst = 0;
}

int strcmp(const unsigned char *p, const unsigned char *q) {
    int diff;
    unsigned int align;
    unsigned int a, b, x;
    unsigned char c;
    c = *p;
    diff = c - *q;
    if (diff) return diff;
    if (((unsigned int)q & 3) != (align = (unsigned int)p & 3)) goto byte_loop;
    if (align == 0) goto word_loop;
    if (c == 0) return 0;
    {
        int n = 3 - align;
        while (n-- != 0) {
            c = *++p;
            diff = c - *++q;
            if (diff) return diff;
            if (!c) return 0;
        }
    }
    p++; q++;
word_loop:
    a = *(const unsigned int *)p;
    b = *(const unsigned int *)q;
    x = a + 0xFEFEFEFFu;
    x &= ~a;
    if (x & 0x80808080u) goto compare_tail;
    while (a == b) {
        a = *(const unsigned int *)(p += 4);
        b = *(const unsigned int *)(q += 4);
        x = a + 0xFEFEFEFFu;
        x &= 0x80808080u;
        if (x) goto compare_tail;
    }
compare_tail:
    c = *p;
    diff = c - *q;
    if (diff) return diff;
byte_loop:
    if (!c) return 0;
    do {
        c = *++p;
        diff = c - *++q;
        if (diff) return diff;
        if (!c) return 0;
    } while (1);
}

int strncmp(const unsigned char *s1, const unsigned char *s2, int n) {
    const unsigned char *p = s1 - 1;
    const unsigned char *q = s2 - 1;
    int count = n + 1;
    while (--count != 0) {
        unsigned char a = *++p;
        unsigned char b = *++q;
        if (a != b)
            return a - b;
        if (a == 0)
            break;
    }
    return 0;
}

unsigned char *strchr(const unsigned char *s, int c) {
    const unsigned char *p = s - 1;
    unsigned char ch = (unsigned char)c;
    do {
        if (*++p == ch)
            return (unsigned char *)p;
    } while (*p != 0);
    if (ch == 0)
        return (unsigned char *)p;
    return 0;
}

unsigned char *fn_80029004(const unsigned char *s, int c) {
    const unsigned char *p = s - 1;
    unsigned char current;
    unsigned int ch = c & 0xFF;
    unsigned char *last = 0;
    goto next;
compare:
    if (current == ch)
        last = (unsigned char *)p;
next:
    current = *++p;
    if (current != 0)
        goto compare;
    if (last != 0)
        return last;
    if (ch != 0)
        return 0;
    return (unsigned char *)p;
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

