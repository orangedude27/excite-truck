// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <math.h>
#include <scanf.h>
extern long double __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* overflow);
extern __declspec(section ".sdata") int lbl_8055D680;

double atof(const char *str) {
    int overflow;
    int count;
    __InStrCtrl isc;
    double value;
    double abs_value;
    isc.NextChar = (char *)str;
    isc.NullCharDetected = 0;
    value = (double)__strtold(0x7FFFFFFF, __StringRead, (void *)&isc, &count, &overflow);
    abs_value = fabs(value);
    if (overflow || (value != 0.0 && (abs_value < 2.2250738585072014e-308 || abs_value > 1.7976931348623157e308))) {
        lbl_8055D680 = 0x22;
    }
    return value;
}
