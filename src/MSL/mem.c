#include <MSL/internal/mem.h>
#include "mem_funcs.h"

void* memmove(void* dst, const void* src, size_t n) {
    const char* csrc;
    char* cdst;
    int reverse = (unsigned int)src < (unsigned int)dst;

    if (n >= 32) {
        if (((unsigned int)dst ^ (unsigned int)src) & 3) {
            if (!reverse)
                __copy_longs_unaligned(dst, src, n);
            else
                __copy_longs_rev_unaligned(dst, src, n);
        } else {
            if (!reverse)
                __copy_longs_aligned(dst, src, n);
            else
                __copy_longs_rev_aligned(dst, src, n);
        }
        return dst;
    }

    if (!reverse) {
        for (csrc = (const char*)src - 1, cdst = (char*)dst - 1, n++; --n;)
            *++cdst = *++csrc;
    } else {
        for (csrc = (const char*)src + n, cdst = (char*)dst + n, n++; --n;)
            *--cdst = *--csrc;
    }

    return dst;
}

/* Review-source carve for auto_03_80024DD8_text. */
void* memchr(const void* source, int value, size_t length) {
    const unsigned char* current;
    unsigned long byte = value & 0xFF;

    for (current = (const unsigned char*)source - 1, length++; --length;) {
        if (*++current == byte) {
            return (void*)current;
        }
    }

    return NULL;
}

int memcmp(const void* lhs, const void* rhs, size_t count) {
    const unsigned char* p1;
    const unsigned char* p2;

    for (p1 = (const unsigned char*)lhs - 1, p2 = (const unsigned char*)rhs - 1, count++; --count;) {
        if (*++p1 != *++p2) {
            return (*p1 < *p2) ? -1 : 1;
        }
    }

    return 0;
}

void* __memrchr(const void* source, int value, size_t length) {
    const unsigned char* current;
    unsigned long byte = value & 0xFF;

    for (current = (const unsigned char*)source + length, length++; --length;) {
        if (*--current == byte) {
            return (void*)current;
        }
    }

    return NULL;
}
