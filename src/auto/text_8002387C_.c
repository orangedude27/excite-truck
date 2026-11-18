// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <ansi_fp.h>

/* Round the digits __num2dec_internal wrote into `dec` for `num` down to the
   number of significant digits the format asked for, then make the record
   ready to print.

   The digit just past the last one kept decides: over 5 rounds up, under 5
   rounds down, and an exact 5 -- nothing non-zero after it -- rounds the
   last kept digit up only when that digit is odd, the round-half-to-even
   rule.  Rounding up carries through the run of 9s before it, and a carry
   out of the first digit leaves a 1 there and bumps the exponent.  The digit
   count becomes the requested one, so the number is padded out to it with
   zero digits; the exponent, which counts from the last digit, is moved to
   count from the first, and every digit is turned into its ASCII code.  A
   NaN or an infinity, which the internal routine marks in the first digit
   instead of a value, is left as it is. */
void __num2dec(const decform *form, double num, decimal *dec) {
    register short precision = form->digits;
    int round;
    int i;
    register unsigned char *digit;
    register unsigned char *digits;
    register unsigned char *scan;
    register unsigned char *end;
    unsigned char *p;
    unsigned char len;
    short exponent;
    __num2dec_internal(dec, num);
    if (dec->sig.text[0] > 9) return;
    if (precision > SIGDIGLEN) precision = SIGDIGLEN;
    if (precision <= 0) goto extend;
    if (precision >= dec->sig.length) goto extend;
    digits = dec->sig.text;
    digit = digits + precision;
    if (*digit > 5) {
        round = 1;
        goto apply_round;
    }
    if (*digit < 5) {
        round = -1;
        goto apply_round;
    }
    end = digits + *(volatile unsigned char *)&dec->sig.length;
    scan = digit + 1;
    while (scan < end) {
        if (*scan != 0) {
            round = 1;
            goto apply_round;
        }
        scan++;
    }
    round = -1;
    if (dec->sig.text[precision - 1] & 1) round = 1;
apply_round:
    dec->sig.length = (unsigned char)precision;
    if (round < 0) goto extend;
    digits = dec->sig.text;
    p = digits + precision;
    p--;
round_carry:
    if (*p < 9) {
        *p = *p + 1;
        goto extend;
    }
    if (p == digits) {
        *p = 1;
        exponent = dec->exp;
        dec->exp = (short)(exponent + 1);
        goto extend;
    }
    *p = 0;
    p--;
    goto round_carry;
extend:
    while (dec->sig.length < precision) {
        dec->sig.text[dec->sig.length++] = 0;
    }
    len = dec->sig.length;
    exponent = dec->exp;
    dec->exp = (short)(exponent - (len - 1));
    for (i = 0; i < dec->sig.length; i++) {
        dec->sig.text[i] += '0';
    }
}
