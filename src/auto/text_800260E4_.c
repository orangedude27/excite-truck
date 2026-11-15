// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "MSL/ansi_fp.h"

/* MSL printf/float2str helper: round a `decimal`'s significant digit string
   down to `new_length` digits.  A dropped digit rounds the one before it up
   when it is above 5, and when it is exactly 5 a tie is broken to even (up
   only if the last kept digit is odd or a non-zero digit follows the 5).  The
   zeros the rounding uncovers at the end are trimmed off, so the length can
   come back smaller than asked for; a carry out of the most significant digit
   leaves the value "1" with the exponent bumped, and digits rounded all the
   way away leave a plain "0". */
void round_decimal(decimal* dec, int new_length) {
    char digit;
    char* digitPos;
    int carry;

    if (new_length < 0) {
    return_zero:
        dec->exp = 0;
        dec->sig.length = 1;
        *dec->sig.text = '0';
        return;
    }

    if (new_length >= dec->sig.length) {
        return;
    }

    digitPos = (char*)dec->sig.text + new_length + 1;
    digit = *--digitPos - '0';

    if (digit == 5) {
        char* lastNonZero = &((char*)dec->sig.text)[dec->sig.length];

        while (--lastNonZero > digitPos && *lastNonZero == '0')
            ;
        carry = (lastNonZero == digitPos) ? digitPos[-1] & 1 : 1;
    } else {
        carry = (digit > 5);
    }

    while (new_length != 0) {
        digit = *--digitPos - '0' + carry;

        if ((carry = (digit > 9)) != 0 || digit == 0) {
            --new_length;
        } else {
            *digitPos = digit + '0';
            break;
        }
    }

    if (carry != 0) {
        dec->exp += 1;
        dec->sig.length = 1;
        *dec->sig.text = '1';
        return;
    } else if (new_length == 0) {
        goto return_zero;
    }

    dec->sig.length = new_length;
}
