#include "ansi_fp.h"
#include <types.h>
#include <macros.h>

typedef struct {
    void (*function)(decimal*, const decimal*, const decimal*);
    unsigned int size;
    const unsigned long long *extab;
} ET_ExtabIndex;

#pragma section ".extab"
DECL_SECTION(".extab") const unsigned long long etb_80004570 = 0x1808000000000000ULL;
#pragma section ".extabindex"
DECL_SECTION(".extabindex") const ET_ExtabIndex eti_80004778 = {
    __timesdec, 0x288, &etb_80004570
};
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma opt_propagation off
/* MSL: multiply two decimals.  Each sig.text byte holds one decimal digit, most
 * significant first.  The operands' digits are convolved one output digit at a
 * time, the base-10 carry being kept between digits, into a scratch buffer that
 * is filled from the back; the SIGDIGLEN most significant digits are then copied
 * to the result and the next digit rounds them, ties going to even.  The
 * exponent is the sum of the operands' exponents, plus one for a carry out of
 * the convolution and plus one if the rounding carried through every digit.
 * The result's sign is simply cleared (both operands are unsigned here). */
void __timesdec(decimal *out, const decimal *a, const decimal *b)
{
    register unsigned int carry asm("r11") = 0; /* running base-10 carry */
    register int digit asm("r12");              /* output digit being built, counting down to 1 */
    register unsigned char *wp asm("r6");       /* write cursor, walks back through buf */
    register unsigned char *end asm("r0");      /* one past the last digit written */
    register int bi asm("r31"), count asm("r31");   /* index into b, then digits to add */
    register int ai asm("r30");                 /* index into a, then digits copied out */
    register const unsigned char *ap asm("r30"), *bp asm("r29");
    unsigned char buf[SIGDIGLEN * 2], *scan;
    register unsigned char *rp asm("r5");
    int avail;
    digit = a->sig.length + b->sig.length - 1;
    wp = buf + digit + 1;
    end = wp;
    out->sign = 0;
    while (digit > 0) {
        bi = b->sig.length - 1;
        ai = digit - bi - 1;
        if (ai < 0) { ai = 0; bi = digit - 1; }
        count = bi + 1;
        ap = a->sig.text + ai;
        bp = b->sig.text + bi;
        avail = a->sig.length - ai;
        if (count > avail) count = avail;
        while (count-- > 0) carry += *ap++ * *bp--;
        *--wp = carry % 10;
        carry /= 10;
        --digit;
    }
    out->exp = a->exp + b->exp;
    if (carry) { *--wp = carry; out->exp++; }
    ai = 0;
    while (ai < SIGDIGLEN && wp < end) {
        out->sig.text[ai] = *wp;
        ai++;
        wp++;
    }
    out->sig.length = ai;
    if (wp < end && *wp >= 5) {
        if (*wp == 5) {
            /* an exact tie: round up only if that makes the last digit odd */
            for (scan = wp + 1; scan < end; scan++) {
                if (*scan != 0) goto round;
            }
            if (!(wp[-1] & 1)) return;
        }
    round:
        {
            register int len asm("r4") = out->sig.length;
            unsigned char *base = out->sig.text;
            rp = base + len - 1;
            for (;;) {
                if (*rp < 9) { ++*rp; break; }
                if (rp == base) { *rp = 1; out->exp++; break; }
                *rp-- = 0;
            }
        }
    }
}
