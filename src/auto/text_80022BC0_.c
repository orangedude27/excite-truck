// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range.

#include "MSL/ansi_fp.h"

/* Convert a decimal digit string to a `decimal`, rounding at SIGDIGLEN digits. */
void __str2dec(decimal *d, const char *str, short exponent) {
    unsigned char *src;
    unsigned char *trailing;
    unsigned char *lastDigit;
    unsigned char *firstDigit;
    int count;
    int ch;

    src = (unsigned char *)str;
    d->exp = exponent;
    d->sign = 0;
    for (count = 0; count < SIGDIGLEN && (signed char)*src != 0;) {
        *((volatile unsigned char *)&d->sig.text[count++]) =
            (unsigned char)(*src++ - '0');
    }

    d->sig.length = (unsigned char)count;
    ch = *src;
    if ((signed char)ch == 0)
        return;
    if ((signed char)ch < 5)
        return;
    if ((signed char)ch > 5)
        goto round_up;

    trailing = src + 1;
    goto load_trailing;
check_zero:
    if ((signed char)ch != '0')
        goto round_up;
    trailing++;
load_trailing:
    ch = *trailing;
    if ((signed char)ch != 0)
        goto check_zero;
    if ((d->sig.text[count - 1] & 1) == 0)
        return;

round_up:
    firstDigit = d->sig.text;
    lastDigit = firstDigit + d->sig.length - 1;
carry:
    if (*lastDigit < 9) {
        *lastDigit = *lastDigit + 1;
        return;
    }
    if (lastDigit == firstDigit) {
        *lastDigit = 1;
        d->exp = d->exp + 1;
        return;
    }
    *lastDigit = 0;
    lastDigit--;
    goto carry;
}
