#include "ansi_fp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

// Returns nonzero if two decimal representations hold the same numeric value.
int __equals_dec(const decimal *lhs, const decimal *rhs) {
    const decimal *x = lhs;
    const decimal *y = rhs;
    unsigned char c;
    int lhs_len;
    int rhs_len;
    int i;
    int min_len;

    c = x->sig.text[0];
    if (c == 0) return y->sig.text[0] == 0;
    if (y->sig.text[0] == 0) return c == 0;
    if (x->exp == y->exp) {
        lhs_len = x->sig.length;
        rhs_len = y->sig.length;
        min_len = lhs_len;
        if (lhs_len > rhs_len) min_len = rhs_len;
        for (i = 0; i < min_len; i++) {
            if (x->sig.text[i] != y->sig.text[i]) return 0;
        }
        if (min_len == lhs_len) x = y;
        for (; i < x->sig.length; i++) {
            if (x->sig.text[i] != 0) return 0;
        }
        return 1;
    }
    return 0;
}

/* Returns 1 if the decimal value in lhs is less than rhs, 0 otherwise. */
int __less_dec(const decimal *lhs, const decimal *rhs) {
    int lhs_len;
    int rhs_len;
    int i;
    int min_len;
    const unsigned char *rhs_len_ptr;
    if (lhs->sig.text[0] == 0) {
        return rhs->sig.text[0] != 0;
    }
    if (rhs->sig.text[0] == 0) {
        return 0;
    }
    if (lhs->exp == rhs->exp) {
        lhs_len = lhs->sig.length;
        rhs_len = rhs->sig.length;
        rhs_len_ptr = &rhs->sig.length;
        min_len = lhs_len;
        if (lhs_len > rhs_len) {
            min_len = rhs_len;
        }
        for (i = 0; i < min_len; i++) {
            if (lhs->sig.text[i] < rhs->sig.text[i]) {
                return 1;
            }
            if (rhs->sig.text[i] < lhs->sig.text[i]) {
                return 0;
            }
        }
        if (min_len == lhs_len) {
            for (; i < *rhs_len_ptr; i++) {
                if (rhs->sig.text[i] != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return lhs->exp < rhs->exp;
}

