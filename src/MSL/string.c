#include <string.h>
#include <wchar.h>

/* Review-source carve for the REXE01 MSL string auto-unit
 * (strcpy@80028CFC, strncpy@80028DBC, strncmp@80028F94,
 * strchr@80028FD4, strstr@8002904C).
 *
 * strcpy uses the MSL word-copy fast path: it aligns source and destination
 * together, scans words for a zero byte, then finishes byte-by-byte. */
char* strcpy(char* dst, const char* src) {
    char* result = dst;
    unsigned long dst_addr = (unsigned long)dst;
    unsigned long src_addr = (unsigned long)src;

    if ((dst_addr & 3) == (src_addr & 3)) {
        if (src_addr & 3) {
            unsigned long count = 3 - (src_addr & 3);

            do {
                unsigned char c = *src++;
                *dst++ = c;
                if (c == '\0') {
                    return result;
                }
            } while (--count);
        }

        while (1) {
            unsigned long word = *(const unsigned long*)src;
            unsigned long test = (word - 0x01010101) & ~word & 0x80808080;

            if (test != 0) {
                break;
            }
            *(unsigned long*)dst = word;
            src += 4;
            dst += 4;
        }
    }

    while ((*dst++ = *src++) != '\0') {
    }

    return result;
}

int strcmp(const char* str1, const char* str2) {
    const unsigned char* p1 = (const unsigned char*)str1;
    const unsigned char* p2 = (const unsigned char*)str2;
    unsigned long addr1 = (unsigned long)p1;
    unsigned long addr2 = (unsigned long)p2;
    unsigned char c1 = *p1;
    unsigned char c2 = *p2;

    if (c1 != c2) {
        return c1 - c2;
    }
    if (c1 == '\0') {
        return 0;
    }

    if ((addr1 & 3) == (addr2 & 3)) {
        unsigned long count = 3 - (addr1 & 3);

        while ((addr1 & 3) != 0 && count--) {
            c1 = *++p1;
            c2 = *++p2;
            if (c1 != c2) {
                return c1 - c2;
            }
            if (c1 == '\0') {
                return 0;
            }
        }

        while (1) {
            unsigned long word1 = *(const unsigned long*)p1;
            unsigned long word2 = *(const unsigned long*)p2;
            unsigned long zero = (word1 - 0x01010101) & ~word1 & 0x80808080;

            if (zero != 0 || word1 != word2) {
                break;
            }
            p1 += 4;
            p2 += 4;
        }
    }

    while (1) {
        c1 = *p1++;
        c2 = *p2++;
        if (c1 != c2) {
            return c1 - c2;
        }
        if (c1 == '\0') {
            return 0;
        }
    }
}

char* strncpy(char* dst, const char* src, size_t n) {
    const unsigned char* p = (const unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;
    n++;

    while (--n) {
        if (!(*++q = *++p)) {
            while (--n) {
                *++q = 0;
            }
            break;
        }
    }

    return dst;
}

int strncmp(const char* str1, const char* str2, size_t n) {
    const unsigned char* p1 = (const unsigned char*)str1 - 1;
    const unsigned char* p2 = (const unsigned char*)str2 - 1;
    unsigned long c1, c2;

    n++;

    while (--n) {
        if ((c1 = *++p1) != (c2 = *++p2)) {
            return (c1 - c2);
        } else if (!c1) {
            break;
        }
    }

    return 0;
}

char* strchr(const char* str, int chr) {
    const unsigned char* p = (const unsigned char*)str - 1;
    unsigned long c = (chr & 0xff);
    unsigned long ch;

    while (ch = *++p) {
        if (ch == c) {
            return ((char*)p);
        }
    }

    return (c ? 0 : (char*)p);
}

char* strstr(const char* str, const char* pat) {
    unsigned char* s1 = (unsigned char*)str - 1;
    unsigned char* p1 = (unsigned char*)pat - 1;
    unsigned long firstc, c1, c2;

    if ((pat == 0) || (!(firstc = *++p1))) {
        return ((char*)str);
    }

    while (c1 = *++s1) {
        if (c1 == firstc) {
            const unsigned char* s2 = s1 - 1;
            const unsigned char* p2 = p1 - 1;

            while ((c1 = *++s2) == (c2 = *++p2) && c1) {
            }

            if (!c2) {
                return ((char*)s1);
            }
        }
    }

    return 0;
}