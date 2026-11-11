#include <stdarg.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int vsprintf(char *str, const char *format, va_list ap);
extern void fn_802E317C(void *arg0, ...);
extern char lbl_8032BBC0[];
#pragma push
#pragma scheduling invalid_target
void fn_801345D8(char *buffer, int bufferSize, const char *fmt, ...) {
    va_list args;
    int writtenChars;
    /* Format into buffer and report fatal overflow if the result does not fit;
     * always force a terminator at the end of the destination buffer. */
    va_start(args, fmt);
    writtenChars = vsprintf(buffer, fmt, args);
    va_end(args);
    if (writtenChars >= bufferSize) {
        fn_802E317C(lbl_8032BBC0, writtenChars + 1, bufferSize);
    }
    buffer[bufferSize - 1] = 0;
}
#pragma pop
void fn_801346B4(char *dst, int len, const unsigned char *src) {
    char *out = dst;
    signed char c;
    int i = 0;
    while (i < len && (c = *src) != 0) {
        *out = c == ' ' ? '_' : c;
        ++i;
        ++src;
        ++out;
    }
    if (len - 1 < i)
        i = len - 1;
    dst[i] = 0;
}
