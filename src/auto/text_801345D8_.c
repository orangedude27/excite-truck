#include <stdarg.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801346B4(char *dst, int len, const char *src) {
    int i = 0;
    char *out = dst;
    signed char c;
    while (i < len && (c = *src) != 0) {
        *out = c == ' ' ? '_' : c;
        ++i;
        ++src;
        ++out;
    }
    if (i > len - 1) i = len - 1;
    dst[i] = 0;
}
