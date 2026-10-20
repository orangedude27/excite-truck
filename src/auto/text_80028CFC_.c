// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void strcpy(unsigned char *dst, const unsigned char *src) {
    while ((*dst++ = *src++) != 0)
        ;
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
    src--;
    dst--;
    while (*++dst != 0)
        ;
    dst--;
    n++;
    if (n != 0) {
        do {
            *++dst = *++src;
            if (*dst == 0)
                break;
        } while (--n != 0);
    }
    *dst = 0;
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
    unsigned char ch = (unsigned char)c;
    unsigned char *last = 0;
    do {
        if (*++p == ch)
            last = (unsigned char *)p;
    } while (*p != 0);
    if (last != 0)
        return last;
    if (ch == 0)
        return (unsigned char *)p;
    return 0;
}

unsigned char *strstr(const unsigned char *s, const unsigned char *find) {
    const unsigned char *p = s - 1;
    unsigned char ch;
    if (find == 0) return (unsigned char *)s;
    ch = *find;
    if (ch == 0) return (unsigned char *)s;
    while (*++p != 0) {
        if (*p == ch) {
            const unsigned char *a = p - 1;
            const unsigned char *b = find - 1;
            while (*++a == *++b) {
                if (*a == 0) break;
            }
            if (*b == 0) return (unsigned char *)p;
        }
    }
    return 0;
}

