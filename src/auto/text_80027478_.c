#include "MSL/stdarg.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern u32 __pformatter_800269DC(void *, void **, const char *, void *);
extern void __StringWrite(void);
int snprintf(char *s, u32 size, const char *format, ...) {
    va_list args;
    struct {
        char *buffer;
        u32 max;
        u32 count;
    } state;
    register char *str = s;
    register u32 max = size;
    u32 end;

    va_start(args, format);
    state.buffer = str;
    state.max = max;
    state.count = 0;
    end = __pformatter_800269DC(__StringWrite, (void **)&state.buffer, format, args);
    if (str) {
        if (end < max)
            str[end] = 0;
        else if (max != 0)
            *(str + max - 1) = 0;
    }
    return end;
}
