// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct decimal {
    char sign;
    char unk;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[36];
    } sig;
} decimal;

void round_decimal(void *arg0, int arg1) {
    unsigned char *base;
    unsigned char n;
    unsigned char *p;
    int t, i;
    unsigned int carry;
    signed char x;

    if (arg1 >= 0) goto normal;
reset:
    *(short *)((char *)arg0 + 2) = 0;
    *((unsigned char *)arg0 + 4) = 1;
    *((char *)arg0 + 5) = 0x30;
    return;

normal:
    n = *((unsigned char *)arg0 + 4);
    if (arg1 >= n) return;

    base = (unsigned char *)arg0 + arg1;
    p = base + 5;
    x = base[5] - 0x30;
    if (x == 5) {
        signed char *q = (signed char *)arg0 + n + 5;
        do {
            q--;
        } while (q > (signed char *)p && *q == 0x30);
        if (q == (signed char *)p)
            carry = p[-1] & 1;
        else
            carry = 1;
    } else {
        t = x ^ 5;
        carry = t >> 1;
        t = t & x;
        carry = (carry - t) >> 31;
    }

    for (i = arg1; arg1 != 0; i--) {
        x = *--p + carry - 0x30;
        t = x ^ 9;
        carry = t >> 1;
        t = t & x;
        carry = (carry - t) >> 31;
        if (carry != 0 || x == 0)
            arg1--;
        else {
            *p = x + 0x30;
            break;
        }
    }

    if (carry != 0) {
        *((unsigned char *)arg0 + 4) = 1;
        *(short *)((char *)arg0 + 2) += 1;
        *((char *)arg0 + 5) = 0x31;
        return;
    }
    if (arg1 != 0) {
        *((unsigned char *)arg0 + 4) = arg1;
        return;
    }
    goto reset;
}
