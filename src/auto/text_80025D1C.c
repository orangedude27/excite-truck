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

  #define LDBL_MANT_DIG 53
  #define TARGET_FLOAT_BITS 64
  #define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)
  #define TARGET_FLOAT_IMPLICIT_J_BIT 1
  #define TARGET_FLOAT_MANT_BITS (LDBL_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
  #define TARGET_FLOAT_EXP_BITS (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

char* long2str_80025854(signed long num, char* buff, print_format format);

static char* double2hex_80025D1C(long double num, char* buff, print_format format) {
    int offset, what_nibble = 0;
    char* wrk_byte_ptr;
    char *p, *q;
    char working_byte;
    long double ld;
    signed short* sptr;
    signed short snum;
    signed long exp;
    print_format exp_format;
    int hex_precision;
    decform form;
    decimal dec;
    extern double lbl_805605C0;

    p = buff;
    ld = num;
    sptr = (signed short*)&ld;

    if (format.precision > 509) {
        return 0;
    }

    form.style = (char)0;
    form.digits = 0x20;
    __num2dec(&form, num, &dec);

    if (*dec.sig.text == 'I') {
        if (*sptr & 0x8000) {
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
        if (*(char*)&num & 0x80) {
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

    snum = (*sptr & 0x7ff0) >> 4;

    exp = snum - 0x3FF;

    p = long2str_80025854(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';

    q = (char*)&num;

    for (hex_precision = format.precision; hex_precision >= 1; hex_precision--) {
        working_byte = *(q + (hex_precision / 2) + 1);
        if (hex_precision % 2)
            working_byte = working_byte & 0x0f;
        else
            working_byte = (working_byte >> 4) & 0x0f;

        if (working_byte < 10) {
            working_byte += '0';
        } else {
            working_byte -= 10;

            if (format.conversion_char == 'a') {
                working_byte += 'a';
            } else {
                working_byte += 'A';
            }
        }

        *--p = working_byte;
    }

    if (format.precision || format.alternate_form) {
        *--p = '.';
    }

    *--p = '1';

    if (format.conversion_char == 'a') {
        *--p = 'x';
    } else {
        *--p = 'X';
    }

    *--p = '0';

    if (*sptr & 0x8000) {
        *--p = '-';
    } else if (format.sign_options == sign_always) {
        *--p = '+';
    } else if (format.sign_options == space_holder) {
        *--p = ' ';
    }

    return p;
}
