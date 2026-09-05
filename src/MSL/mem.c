#include <MSL/internal/mem.h>

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
