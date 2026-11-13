// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
extern u32 __pformatter_800269DC(void *, void **, const char *, void *);
extern void __StringWrite(void);
/* Format a string into str with at most size bytes using va_list args, NUL-terminating when possible. */
int vsnprintf(char *str, u32 size, const char *format, void *args) {
    struct { char *buffer; s32 max; s32 count; } writeState;
    u32 charsWritten;
    writeState.buffer = str;
    writeState.max = size;
    writeState.count = 0;
    charsWritten = __pformatter_800269DC(__StringWrite, (void **)&writeState.buffer, format, args);
    if (str != 0) {
        if (charsWritten < size)
            str[charsWritten] = 0;
        else if (size != 0)
            *(str + size - 1) = 0;
    }
    return charsWritten;
}
