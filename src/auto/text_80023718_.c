#include "ansi_fp.h"
#include "math.h"
#include <ansi_fp.h>
#include <math.h>
extern int fn_800251B0(void);
extern double lbl_80560570;
extern int __cntlzw(unsigned int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_800251B0(void);
extern double lbl_80560570;
extern int __cntlzw(unsigned int);
void __num2dec_internal(decimal *out, double value) {
    int exponent;
    int shift;
    int sign;
    double fraction;
    decimal power;
    decimal integer;

    sign = fn_800251B0() != 0;
    if (value == lbl_80560570) {
        out->sign = sign;
        out->exp = 0;
        out->sig.length = 1;
        out->sig.text[0] = 0;
        return;
    }
    if (__fpclassifyd(value) <= 2) {
        out->sign = sign;
        out->exp = 0;
        out->sig.length = 1;
        out->sig.text[0] = __fpclassifyd(value) == 1 ? 0x4E : 0x49;
        return;
    }
    if (sign) {
        value = -value;
    }
    fraction = frexp(value, &exponent);
    shift = 32 - __cntlzw(((unsigned int)exponent - 1) & ~((unsigned int)exponent));
    if (shift == 0) {
        unsigned int bits = (*(unsigned int *)&fraction) | 0x100000;
        shift = 32 - __cntlzw((bits - 1) & ~bits) + 32;
    }
    shift = 0x35 - shift;
    __two_exp(&power, exponent - shift);
    __ull2dec(&integer, (unsigned long long)ldexp(fraction, shift));
    __timesdec(out, &integer, &power);
    out->sign = sign;
}
