// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "MSL/ansi_files.h"
#include "MSL/stdarg.h"

extern int __FileWrite(void *file, const char *buffer, size_t char_num);
extern int fwide(FILE *stream, int mode);
extern int __pformatter_800269DC(void *writeProc, void *file, const char *format, va_list args);

/* MSL vprintf: run the library's format engine over stdout, pulling the
 * arguments off `args` and writing the text through __FileWrite. A
 * wide-oriented stdout is refused with -1, as C99 vprintf requires. */
int vprintf(const char *format, va_list args) {
    FILE *base = (FILE *)&__files; /* stdout is the second FILE of the three */
    if (fwide(base + 1, -1) >= 0)
        return -1;
    return __pformatter_800269DC(__FileWrite, base + 1, format, args);
}

