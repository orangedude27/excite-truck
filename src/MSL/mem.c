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
