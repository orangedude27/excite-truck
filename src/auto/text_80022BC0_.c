// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range.

#include "MSL/ansi_fp.h"

void __str2dec(decimal *arg0, const char *arg1, short arg2) {
    unsigned char *p;
    unsigned char *q;
    unsigned char *first;
    unsigned char *last;
    int count;
    int ch;

    p = (unsigned char *)arg1;
    *(short *)((char *)arg0 + 2) = arg2;
    *(unsigned char *)arg0 = 0;
    for (count = 0; count < 0x24 && (signed char)*p != 0; count++, p++) {
        ch = *p;
        *((volatile unsigned char *)((unsigned int)arg0 + count + 5)) = (unsigned char)(ch - 0x30);
    }

    ch = *p;
    *(volatile unsigned char *)((char *)arg0 + 4) = (unsigned char)count;
    if ((signed char)ch == 0)
        return;
    if ((signed char)ch < 5)
        return;
    if ((signed char)ch > 5)
        goto round_up;

    q = p + 1;
    while ((signed char)*q == 0x30)
        q++;
    if ((signed char)*q == 0)
        return;
    if ((*(unsigned char *)((char *)arg0 + count + 4) & 1) == 0)
        return;

round_up:
    first = (unsigned char *)arg0 + 5;
    last = first + count - 1;
    while (*last >= 9) {
        if (last == first) {
            *last = 1;
            *(short *)((char *)arg0 + 2) = *(short *)((char *)arg0 + 2) + 1;
            return;
        }
        *last = 0;
        last--;
    }
    *last = *last + 1;
}
