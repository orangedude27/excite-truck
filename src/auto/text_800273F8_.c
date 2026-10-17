// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
extern u32 __pformatter_800269DC(void *, void **, const char *, void *);
extern void __StringWrite(void);
int vsprintf(char *str, const char *format, void *args) {
    struct { char *buffer; s32 max; s32 count; } state;
    register s32 max = -1;
    u32 written;
    state.buffer = str;
    state.max = max;
    state.count = 0;
    written = __pformatter_800269DC(__StringWrite, (void **)&state.buffer, format, args);
    if (str != 0) {
        if (written < (u32)max)
            str[written] = 0;
        else
            str[-2] = 0;
    }
    return written;
}
