// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "strtold.h"
#include "ansi_fp.h"
#include "locale.h"
#include "scanf.h"
#include "float.h"
#include "limits.h"
#include "ctype.h"
#include "string.h"
#include "errno.h"
#ifndef ERANGE
#define ERANGE 34
#endif
extern struct lconv __lconv;
extern unsigned long __double_huge[];

extern double nan(const char*);
extern double __dec2num(const decimal* d);
#define HUGE_VALF (*(float*)__float_huge)
#define HUGE_VAL (*(double*)__double_huge)

#define TARGET_FLOAT_BITS 64
#define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)
#define TARGET_FLOAT_MAX_EXP LDBL_MAX_EXP
#define TARGET_FLOAT_MANT_DIG LDBL_MANT_DIG
#define TARGET_FLOAT_IMPLICIT_J_BIT 1
#define TARGET_FLOAT_MANT_BITS (TARGET_FLOAT_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
#define TARGET_FLOAT_EXP_BITS (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

enum scan_states {
    start = 0x0001,
    sig_start = 0x0002,
    leading_sig_zeroes = 0x0004,
    int_digit_loop = 0x0008,
    frac_start = 0x0010,
    frac_digit_loop = 0x0020,
    sig_end = 0x0040,
    exp_start = 0x0080,
    leading_exp_digit = 0x0100,
    leading_exp_zeroes = 0x0200,
    exp_digit_loop = 0x0400,
    finished = 0x0800,
    failure = 0x1000,
    nan_state = 0x2000,
    infin_state = 0x4000,
    hex_state = 0x8000
};

enum hex_scan_states {
    not_hex = 0x0000,
    hex_start = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop = 0x0004,
    hex_frac_digit_loop = 0x0008,
    hex_sig_end = 0x0010,
    hex_exp_start = 0x0020,
    hex_leading_exp_digit = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop = 0x0100
};

#define final_state(scan_state) (scan_state & (finished | failure))
#define success(scan_state) \
    (scan_state &           \
     (leading_sig_zeroes | int_digit_loop | frac_digit_loop | leading_exp_zeroes | exp_digit_loop | finished))
#define hex_success(count, scan_state)                                                                  \
    (count - 1 > 2 && scan_state & (hex_leading_sig_zeroes | hex_int_digit_loop | hex_frac_digit_loop | \
                                    hex_leading_exp_zeroes | hex_exp_digit_loop))

#define fetch() (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, __UngetAChar)
