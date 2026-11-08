// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include <ansi_fp.h>
#include <locale.h>
#include <string.h>
#include <math.h>

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

  extern struct lconv lbl_802FE6A0;
  #define __lconv lbl_802FE6A0

  extern double lbl_805605C0;
  #define dbl_zero lbl_805605C0 // the double 0.0, pooled by the compiler in .sdata2

  #define MAX_HEX_PRECISION 509 // most %a digits the printf float buffer can hold

  // MSL printf.c's picture of this target's floating point: on Gekko a long
  // double is an ordinary IEEE 754 double, so 64 bits, 52 stored mantissa bits
  // behind the implicit 1, and an 11 bit biased exponent.
  #define LDBL_MANT_DIG 53
  #define TARGET_FLOAT_BITS 64
  #define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)
  #define TARGET_FLOAT_IMPLICIT_J_BIT 1
  #define TARGET_FLOAT_MANT_BITS (LDBL_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
  #define TARGET_FLOAT_EXP_BITS (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

char* long2str_80025854(signed long num, char* buff, print_format format);

static char* double2hex_80025D1C(long double num, char* buff, print_format format) {
    char* p;
    unsigned char* q;
    unsigned char working_byte;
    int expbits, expmask;
    unsigned snum;
    long exp;
    print_format exp_format;
    int hex_precision;
    int mantissa_bit;
    decform form;
    decimal dec;
    int radix_marker;
    double tempF;
    extern double lbl_805605C0;

    radix_marker = *(unsigned char*)__lconv.decimal_point;

    if (format.precision > 509) {
        return 0;
    }

    form.style = (char)0;
    form.digits = 0x20;
    __num2dec(&form, num, &dec);

    tempF = fabs(num);
    if (lbl_805605C0 == tempF) {
        p = buff - 6;
        strcpy(p, "0x0p0");
        return p;
    }

    if (*dec.sig.text == 'I') {
        if (dec.sign) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                strcpy(p, "-INF");
            else
                strcpy(p, "-inf");
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                strcpy(p, "INF");
            else
                strcpy(p, "inf");
        }

        return p;
    } else if (*dec.sig.text == 'N') {
        if (dec.sign) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                strcpy(p, "-NAN");
            else
                strcpy(p, "-nan");
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                strcpy(p, "NAN");
            else
                strcpy(p, "nan");
        }

        return p;
    }

    exp_format.justification_options = right_justification;
    exp_format.sign_options = sign_always;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = normal_argument;
    exp_format.field_width = 0;
    exp_format.precision = 1;
    exp_format.conversion_char = 'd';

    expbits = 11;
    expmask = 0x7FF;

    snum = ((unsigned char*)&num)[0] << 25;
    snum |= ((unsigned char*)&num)[1] << 17;

    snum = (snum >> (32 - expbits)) & expmask;

    exp = snum - 0x3FF;

    p = long2str_80025854(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';
    q = (unsigned char*)&num;

    mantissa_bit = (1 + expbits + format.precision * 4) - 1;

    for (hex_precision = format.precision; hex_precision >= 1; hex_precision--) {
        if (mantissa_bit < 64) {
            int mantissa_byte;

            mantissa_byte = mantissa_bit >> 3;
            working_byte = (*(q + mantissa_byte)) >> (7 - (mantissa_bit & 7));

            if ((mantissa_bit & ~7) != ((mantissa_bit - 4) & ~7)) {
                working_byte |= ((*(q + (mantissa_byte - 1))) << 8) >> (7 - ((mantissa_bit) & 7));
            }

            if ((working_byte &= 0xF) < 10) {
                working_byte += '0';
            } else {
                if (format.conversion_char == 'a') {
                    working_byte += 'a' - 10;
                } else {
                    working_byte += 'A' - 10;
                }
            }
        } else {
            working_byte = '0';
        }

        *--p = working_byte;
        mantissa_bit -= 4;
    }

    if (format.precision || format.alternate_form) {
        *--p = radix_marker;
    }

    *--p = '1';

    if (format.conversion_char == 'a') {
        *--p = 'x';
    } else {
        *--p = 'X';
    }

    *--p = '0';

    if (dec.sign) {
        *--p = '-';
    } else if (format.sign_options == sign_always) {
        *--p = '+';
    } else if (format.sign_options == space_holder) {
        *--p = ' ';
    }

    return p;
}
