// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

enum justification_options { left_justification, right_justification, zero_fill };
enum sign_options { only_minus, sign_always, space_holder };
enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    wchar_argument,
    intmax_argument,
    size_t_argument,
    ptrdiff_argument,
    long_double_argument
};

typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

/**
 * @brief MSL printf's 32-bit integer conversion: format @p num at the end of the
 *        caller's 512-byte scratch buffer, writing backwards, and return a
 *        pointer to the resulting NUL-terminated string (0 if it won't fit).
 *
 * This is the static long2str() of MSL's printf (see src/MSL/printf.c), which
 * the game links out of the metrowerks library.  @p pBuf is one past the *end*
 * of the buffer (__pformatter passes buf + 512), so every character is
 * prepended with --p and the string ends up right-aligned in it.  Only the
 * fields parse_format() fills in are used: conversion_char, precision,
 * field_width, alternate_form, justification_options and sign_options.
 */
char* long2str_80025854(signed long num, char* pBuf, print_format fmt) {
    unsigned long unsigned_num, base;
    char* p;
    int n, digits;
    int minus = 0;
    unsigned_num = num;
    minus = 0;

    /* Start with the terminator; an empty conversion returns just it. */
    p = pBuf;
    *--p = 0;
    digits = 0;

    if (!num && !fmt.precision && !(fmt.alternate_form && fmt.conversion_char == 'o')) {
        return p;
    }

    /* Radix from the conversion character; only %d/%i carry a sign. */
    switch (fmt.conversion_char) {
    case 'd':
    case 'i':
        base = 10;

        if (num < 0) {
            /* negating LONG_MIN gives LONG_MIN back, so leave it as is */
            if (num != 0x80000000L)
                unsigned_num = -unsigned_num;

            minus = 1;
        }
        break;

    case 'o':
        base = 8;
        fmt.sign_options = only_minus;
        break;

    case 'u':
        base = 10;
        fmt.sign_options = only_minus;
        break;

    case 'x':
    case 'X':
        base = 16;
        fmt.sign_options = only_minus;
        break;
    }

    /* Least significant digit first, so the string grows down towards the
     * start of the buffer: n is the remainder, turned into its digit. */
    do {
        n = unsigned_num % base;
        unsigned_num /= base;

        if (n < 10) {
            n += '0';
        } else {
            n -= 10;

            if (fmt.conversion_char == 'x') {
                n += 'a';
            } else {
                n += 'A';
            }
        }

        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    /* %#o prefixes a 0 unless the value already starts with one. */
    if (base == 8 && fmt.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    /* Zero padding: the field width takes the precision's place, less what the
     * sign and a 0x prefix will use. */
    if (fmt.justification_options == zero_fill) {
        fmt.precision = fmt.field_width;

        if (minus || fmt.sign_options != only_minus)
            --fmt.precision;

        if (base == 16 && fmt.alternate_form)
            fmt.precision -= 2;
    }

    /* 509 = the 512-byte buffer less the terminator and the caller's room. */
    if (pBuf - p + fmt.precision > 509)
        return (0);

    while (digits < fmt.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && fmt.alternate_form) {
        *--p = fmt.conversion_char;
        *--p = '0';
    }

    if (minus) {
        *--p = '-';
    } else if (fmt.sign_options == sign_always) {
        *--p = '+';
    } else if (fmt.sign_options == space_holder) {
        *--p = ' ';
    }

    return p;
}
