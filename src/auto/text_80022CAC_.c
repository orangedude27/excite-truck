#include "MSL/ansi_fp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* __two_exp()'s lookup table: the exact decimal digits of every power of two
 * it can produce, packed as NUL-terminated strings.  Each __str2dec() call
 * below passes an offset into it plus that string's power-of-ten exponent:
 *
 *   0   "542101086242752217003726400434970855712890625" e-20   2^-64
 *  46   "11102230246251565404236316680908203125"         e-16   2^-53
 *  85   "23283064365386962890625"                        e-10   2^-32
 * 109   "152587890625"                                   e-5    2^-16
 * 122   "390625"                                         e-3    2^-8
 * 129   "78125"                                          e-3    2^-7
 * 135   "15625"                                          e-2    2^-6
 * 141   "3125"                                           e-2    2^-5
 * 146   "625"                                            e-2    2^-4
 * 150   "125"                                            e-1    2^-3
 * 154   "25"                                             e-1    2^-2
 * 157   "5"                                              e-1    2^-1
 * 159   "1"                                              e0     2^0
 * 161   "2"                                              e0     2^1
 * 163   "4"                                              e0     2^2
 * 165   "8"                                              e0     2^3
 * 167   "16"                                             e1     2^4
 * 170   "32"                                             e1     2^5
 * 173   "64"                                             e1     2^6
 * 176   "128"                                            e2     2^7
 * 180   "256"                                            e2     2^8
 *
 * The game's .rodata carries no name for it, so alias the label. */
#define pow2_digit_strings lbl_802ED878
extern const char pow2_digit_strings[];

/* out = 2^exponent as an exact decimal.  Exponents the table covers are read
 * straight out of it; any other one is halved (truncating), turned into a
 * square, and multiplied by one more 2 - or by 0.5 - to make up the remainder.
 */
void __two_exp(decimal *out, long exponent) {
    decimal power, squared;

    switch (exponent) {
    case -64: __str2dec(out, pow2_digit_strings + 0,   -20); break; /* 2^-64 */
    case -53: __str2dec(out, pow2_digit_strings + 46,  -16); break; /* 2^-53 */
    case -32: __str2dec(out, pow2_digit_strings + 85,  -10); break; /* 2^-32 */
    case -16: __str2dec(out, pow2_digit_strings + 109,  -5); break; /* 2^-16 */
    case -8:  __str2dec(out, pow2_digit_strings + 122,  -3); break; /* 2^-8  */
    case -7:  __str2dec(out, pow2_digit_strings + 129,  -3); break; /* 2^-7  */
    case -6:  __str2dec(out, pow2_digit_strings + 135,  -2); break; /* 2^-6  */
    case -5:  __str2dec(out, pow2_digit_strings + 141,  -2); break; /* 2^-5  */
    case -4:  __str2dec(out, pow2_digit_strings + 146,  -2); break; /* 2^-4  */
    case -3:  __str2dec(out, pow2_digit_strings + 150,  -1); break; /* 2^-3  */
    case -2:  __str2dec(out, pow2_digit_strings + 154,  -1); break; /* 2^-2  */
    case -1:  __str2dec(out, pow2_digit_strings + 157,  -1); break; /* 2^-1  */
    case 0:   __str2dec(out, pow2_digit_strings + 159,   0); break; /* 2^0   */
    case 1:   __str2dec(out, pow2_digit_strings + 161,   0); break; /* 2^1   */
    case 2:   __str2dec(out, pow2_digit_strings + 163,   0); break; /* 2^2   */
    case 3:   __str2dec(out, pow2_digit_strings + 165,   0); break; /* 2^3   */
    case 4:   __str2dec(out, pow2_digit_strings + 167,   1); break; /* 2^4   */
    case 5:   __str2dec(out, pow2_digit_strings + 170,   1); break; /* 2^5   */
    case 6:   __str2dec(out, pow2_digit_strings + 173,   1); break; /* 2^6   */
    case 7:   __str2dec(out, pow2_digit_strings + 176,   2); break; /* 2^7   */
    case 8:   __str2dec(out, pow2_digit_strings + 180,   2); break; /* 2^8   */
    default:
        __two_exp(&power, exponent / 2);
        __timesdec(out, &power, &power);
        if (exponent & 1) {
            squared = *out; /* the odd exponent still wants one factor of 2 */
            if (exponent > 0) __str2dec(&power, pow2_digit_strings + 161, 0);  /* 2   */
            else              __str2dec(&power, pow2_digit_strings + 157, -1); /* 0.5 */
            __timesdec(out, &squared, &power);
        }
        break;
    }
}

#undef pow2_digit_strings
