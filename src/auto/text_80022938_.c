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
void __timesdec(decimal *out, const decimal *a, const decimal *b)
{
    register unsigned int carry asm("r11") = 0;
    register int k asm("r12");
    register unsigned char *p asm("r6");
    register unsigned char *end asm("r0");
    register int j asm("r31"), count asm("r31");
    register int i asm("r30");
    register const unsigned char *pa asm("r30"), *pb asm("r29");
    unsigned char buf[72], *q;
    register unsigned char *dst asm("r5");
    int n;
    k = a->sig.length + b->sig.length - 1;
    p = buf + k + 1;
    end = p;
    out->sign = 0;
    while (k > 0) {
        j = b->sig.length - 1;
        i = k - j - 1;
        if (i < 0) { i = 0; j = k - 1; }
        count = j + 1;
        pa = a->sig.text + i;
        pb = b->sig.text + j;
        n = a->sig.length - i;
        if (count > n) count = n;
        while (count-- > 0) carry += *pa++ * *pb--;
        *--p = carry % 10;
        carry /= 10;
        --k;
    }
    out->exp = a->exp + b->exp;
    if (carry) { *--p = carry; out->exp++; }
    i = 0;
    while (i < 36 && p < end) {
        out->sig.text[i] = *p;
        i++;
        p++;
    }
    out->sig.length = i;
    if (p < end && *p >= 5) {
        if (*p == 5) {
            for (q = p + 1; q < end; q++) {
                if (*q != 0) goto round;
            }
            if (!(p[-1] & 1)) return;
        }
    round:
        {
            register int len asm("r4") = out->sig.length;
            unsigned char *base = out->sig.text;
            dst = base + len - 1;
            for (;;) {
                if (*dst < 9) { ++*dst; break; }
                if (dst == base) { *dst = 1; out->exp++; break; }
                *dst-- = 0;
            }
        }
    }
}
#pragma opt_propagation reset
