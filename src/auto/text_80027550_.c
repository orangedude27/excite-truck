#include <stdarg.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int __pformatter_800269DC(void *, void **, const char *, void *);
extern void __StringWrite(void);
int sprintf(char *s, const char *format, ...) {
    va_list args;
    struct {
        char *buffer;
        unsigned int max;
        unsigned int count;
    } state;
    register char *str asm("r27") = s;
    register unsigned int max asm("r30");
    unsigned int written;

    /* Format into an unbounded string buffer via __pformatter_800269DC and
       NUL-terminate; on the no-space sentinel (written >= max) writes the
       terminator at str[-2] to match the original implementation. */
    va_start(args, format);
    max = 0xFFFFFFFF;
    state.buffer = str;
    state.max = max;
    state.count = 0;
    written = __pformatter_800269DC(__StringWrite, (void **)&state.buffer, format, args);
    if (str) {
        if (written < max)
            str[written] = 0;
        else
            str[-2] = 0;
    }
    return written;
}
