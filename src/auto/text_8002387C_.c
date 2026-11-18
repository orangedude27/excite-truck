// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void __num2dec_internal(void *);
extern void __num2dec_internal(void *);
void __num2dec(const void *arg0, double x, void *arg1) {
    register short precision = *(const short *)((const char *)arg0 + 2);
    unsigned char *dec = (unsigned char *)arg1;
    int round;
    int i;
    register unsigned char *digit;
    register unsigned char *digits;
    register unsigned char *scan;
    register unsigned char *end;
    unsigned char *p;
    unsigned char len;
    short exponent;
    ((void (*)(void *, double))__num2dec_internal)(dec, x);
    if (dec[5] > 9) return;
    if (precision > 0x24) precision = 0x24;
    if (precision <= 0) goto extend;
    if (precision >= dec[4]) goto extend;
    digits = dec + 5;
    digit = digits + precision;
    if (*digit > 5) {
        round = 1;
        goto apply_round;
    }
    if (*digit < 5) {
        round = -1;
        goto apply_round;
    }
    end = digits + *(volatile unsigned char *)(dec + 4);
    scan = digit + 1;
    while (scan < end) {
        if (*scan != 0) {
            round = 1;
            goto apply_round;
        }
        scan++;
    }
    round = -1;
    if (dec[precision + 4] & 1) round = 1;
apply_round:
    dec[4] = (unsigned char)precision;
    if (round < 0) goto extend;
    digits = dec + 5;
    p = digits + precision;
    p--;
round_carry:
    if (*p < 9) {
        *p = *p + 1;
        goto extend;
    }
    if (p == digits) {
        *p = 1;
        exponent = *(short *)(dec + 2);
        *(short *)(dec + 2) = (short)(exponent + 1);
        goto extend;
    }
    *p = 0;
    p--;
    goto round_carry;
extend:
    while (dec[4] < precision) {
        dec[5 + dec[4]++] = 0;
    }
    len = dec[4];
    exponent = *(short *)(dec + 2);
    *(short *)(dec + 2) = (short)(exponent - (len - 1));
    for (i = 0; i < dec[4]; i++) {
        dec[5 + i] += 0x30;
    }
}
