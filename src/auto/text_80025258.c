// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stdarg.h>

__declspec(section ".data") extern int lbl_802FE850;

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

    long_double_argument,
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

/* MSL <cctype>: the C locale table reached through the global locale object. */
static inline int msl_isdigit(int c) {
    int locale = *(int *)((char *)&lbl_802FE850 + 0x38);
    return (c < 0 || c >= 0x100) ? 0
                                 : (*(unsigned short *)(*(int *)(locale + 8) + c * 2) & 8);
}
