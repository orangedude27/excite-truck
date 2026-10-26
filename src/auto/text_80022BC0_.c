// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range.

#include "MSL/ansi_fp.h"

void __str2dec(decimal *arg0, const char *arg1, short arg2) {
    unsigned char *p;
    unsigned char *q;
    unsigned char *last;
    unsigned char *first;
    int count;
    int ch;

    p = (unsigned char *)arg1;
    *(short *)((char *)arg0 + 2) = arg2;
    *(unsigned char *)arg0 = 0;
    for (count = 0; count < 0x24 && (signed char)*p != 0;) {
        *((volatile unsigned char *)((unsigned int)arg0 + count++ + 5)) =
            (unsigned char)(*p++ - 0x30);
    }

    *(volatile unsigned char *)((char *)arg0 + 4) = (unsigned char)count;
    ch = *p;
    if ((signed char)ch == 0)
        return;
    if ((signed char)ch < 5)
        return;
    if ((signed char)ch > 5)
        goto round_up;

    q = p + 1;
    goto load_trailing;
check_zero:
    if ((signed char)ch != 0x30)
        goto round_up;
    q++;
load_trailing:
    ch = *q;
    if ((signed char)ch != 0)
        goto check_zero;
    if ((*(unsigned char *)(count + (int)arg0 + 4) & 1) == 0)
        return;

round_up:
    first = (unsigned char *)arg0 + 5;
    last = first + *(unsigned char *)((char *)arg0 + 4) - 1;
carry:
    if (*last < 9) {
        *last = *last + 1;
        return;
    }
    if (last == first) {
        *last = 1;
        *(short *)((char *)arg0 + 2) = *(short *)((char *)arg0 + 2) + 1;
        return;
    }
    *last = 0;
    last--;
    goto carry;
}
