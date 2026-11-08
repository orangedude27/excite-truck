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

// MSL printf's "%a"/"%A" conversion: write num as a hexadecimal float,
//   [-]0x1.<precision hex digits>p<exponent>
// into the buffer that ends at buff.  The number is built backwards, so the
// return value is the first character written (0 when the precision is too
// large for the buffer).  long2str writes the exponent; everything else is
// stored one character at a time.
static char* double2hex_80025D1C(long double num, char* buff, print_format format) {
    char* out;                  // write cursor, walks down from buff
    const unsigned char* num_bytes;
    unsigned char working_byte; // one hex digit, as the character for it
    int expbits, expmask;
    unsigned exp_field;         // biased exponent, as read out of the double
    long exponent;              // ... with the bias removed
    print_format exp_format;    // how the exponent itself is printed: "%+d"
    int hex_precision;          // hex digits still to write
    int mantissa_bit;           // bit of the double the next digit starts at
    decform form;
    decimal dec;
    int radix_marker;           // the locale's decimal point
    double magnitude;
    extern double lbl_805605C0;

    radix_marker = *(unsigned char*)__lconv.decimal_point;

    if (format.precision > MAX_HEX_PRECISION) {
        return 0;
    }

    // Ask MSL's float->decimal conversion about the value; it names the
    // specials for us, its significand text starting with 'I' or 'N'.
    form.style = (char)decform_style_normal;
    form.digits = 0x20; // 32 significant digits
    __num2dec(&form, num, &dec);

    magnitude = fabs(num);
    if (dbl_zero == magnitude) { // +-0 has no mantissa bits to walk over
        out = buff - 6;
        strcpy(out, "0x0p0");
        return out;
    }

    if (*dec.sig.text == 'I') {
        if (dec.sign) {
            out = buff - 5;
            if (format.conversion_char == 'A')
                strcpy(out, "-INF");
            else
                strcpy(out, "-inf");
        } else {
            out = buff - 4;
            if (format.conversion_char == 'A')
                strcpy(out, "INF");
            else
                strcpy(out, "inf");
        }

        return out;
    } else if (*dec.sig.text == 'N') {
        if (dec.sign) {
            out = buff - 5;
            if (format.conversion_char == 'A')
                strcpy(out, "-NAN");
            else
                strcpy(out, "-nan");
        } else {
            out = buff - 4;
            if (format.conversion_char == 'A')
                strcpy(out, "NAN");
            else
                strcpy(out, "nan");
        }

        return out;
    }

    exp_format.justification_options = right_justification;
    exp_format.sign_options = sign_always;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = normal_argument;
    exp_format.field_width = 0;
    exp_format.precision = 1;
    exp_format.conversion_char = 'd';

    // Big endian IEEE 754: the exponent is the 11 bits under the sign bit,
    // gathered into the top of a word and shifted back down.
    expbits = TARGET_FLOAT_EXP_BITS;
    expmask = (1 << TARGET_FLOAT_EXP_BITS) - 1;

    exp_field = ((unsigned char*)&num)[0] << 25;
    exp_field |= ((unsigned char*)&num)[1] << 17;

    exp_field = (exp_field >> (32 - expbits)) & expmask;

    exponent = exp_field - 0x3FF;

    out = long2str_80025854(exponent, buff, exp_format);
    if (format.conversion_char == 'a')
        *--out = 'p';
    else
        *--out = 'P';
    num_bytes = (const unsigned char*)&num;

    // The last digit asked for ends this far down from the sign bit; the
    // mantissa itself starts at bit 1 + expbits, behind the implicit 1.
    mantissa_bit = (1 + expbits + format.precision * 4) - 1;

    for (hex_precision = format.precision; hex_precision >= 1; hex_precision--) {
        if (mantissa_bit < TARGET_FLOAT_BITS) {
            int mantissa_byte;

            mantissa_byte = mantissa_bit >> 3;
            working_byte = (*(num_bytes + mantissa_byte)) >> (7 - (mantissa_bit & 7));

            if ((mantissa_bit & ~7) != ((mantissa_bit - 4) & ~7)) {
                // the four bits run over into the byte before this one
                working_byte |= ((*(num_bytes + (mantissa_byte - 1))) << 8) >> (7 - ((mantissa_bit) & 7));
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
            // past the bottom of the stored mantissa: the digits are zeros
            working_byte = '0';
        }

        *--out = working_byte;
        mantissa_bit -= 4;
    }

    if (format.precision || format.alternate_form) {
        *--out = radix_marker;
    }

    *--out = '1'; // the implicit leading bit of a normalised double

    if (format.conversion_char == 'a') {
        *--out = 'x';
    } else {
        *--out = 'X';
    }

    *--out = '0';

    if (dec.sign) {
        *--out = '-';
    } else if (format.sign_options == sign_always) {
        *--out = '+';
    } else if (format.sign_options == space_holder) {
        *--out = ' ';
    }

    return out;
}
