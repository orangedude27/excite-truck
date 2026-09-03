#include <string.h>

/* Review-source carve for the REXE01 MSL string auto-unit
 * (strncpy@80028DBC, strncmp@80028F94, strchr@80028FD4,
 * strstr@8002904C). */
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