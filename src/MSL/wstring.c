#include <stddef.h>

size_t wcslen(const wchar_t* str) {
    size_t len = (size_t)-1;
    const wchar_t* p = str - 1;

    do {
        len++;
    } while (*++p);

    return len;
}
