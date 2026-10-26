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
    unsigned int end;

    va_start(args, format);
    max = 0xFFFFFFFF;
    state.buffer = str;
    state.max = max;
    state.count = 0;
    end = __pformatter_800269DC(__StringWrite, (void **)&state.buffer, format, args);
    if (str) {
        if (end < max)
            str[end] = 0;
        else
            str[-2] = 0;
    }
    return end;
}
