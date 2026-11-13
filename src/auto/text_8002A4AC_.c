// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <math.h>
#include <scanf.h>
extern long double __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* overflow);
extern __declspec(section ".sdata") int lbl_8055D680;

double atof(const char *str) {
    /* Parses a floating-point value from a string and sets errno (lbl_8055D680) to 0x22 on overflow/range error. */
    int overflow;
    int charsScanned;
    __InStrCtrl inputCtrl;
    double value;
    double absValue;
    inputCtrl.NextChar = (char *)str;
    inputCtrl.NullCharDetected = 0;
    value = (double)__strtold(0x7FFFFFFF, __StringRead, (void *)&inputCtrl, &charsScanned, &overflow);
    absValue = fabs(value);
    if (overflow || (value != 0.0 && (absValue < 2.2250738585072014e-308 || absValue > 1.7976931348623157e308))) {
        lbl_8055D680 = 0x22;
    }
    return value;
}
