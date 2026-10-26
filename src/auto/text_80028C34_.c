// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <stdarg.h>
#include <MSL/scanf.h>

extern int __sformatter(int (*ReadProc)(void *, int, int), void *ReadProcArg, const char *format_str, va_list arg, int is_secure);

int sscanf(const char *s, const char *pFormat, ...) {
    __InStrCtrl isc;
    va_list args;

    va_start(args, pFormat);
    isc.NextChar = (char *)s;
    if ((s == 0) || (*isc.NextChar == '\0'))
        return -1;
    isc.NullCharDetected = 0;
    return __sformatter(&__StringRead, (void *)&isc, pFormat, args, 0);
}
