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

#pragma push
#pragma processor 750
const char* parse_format_80025258(const char* format_string, va_list* arg, print_format* format) {
    print_format f;
    const char* s = format_string;
    int c;
    int flag_found;

    f.justification_options = right_justification;
    f.sign_options = only_minus;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = normal_argument;
    f.field_width = 0;
    f.precision = 0;

    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return s + 1;
    }

    for (;;) {
        flag_found = 1;

        switch (c) {
        case '-':
            f.justification_options = left_justification;
            break;
        case '+':
            f.sign_options = sign_always;
            break;
        case ' ':
            if (f.sign_options != sign_always) {
                f.sign_options = space_holder;
            }
            break;
        case '#':
            f.alternate_form = 1;
            break;
        case '0':
            if (f.justification_options != left_justification) {
                f.justification_options = zero_fill;
            }
            break;
        default:
            flag_found = 0;
            break;
        }

        if (flag_found) {
            c = *++s;
        } else {
            break;
        }
    }

    if (c == '*') {
        if ((f.field_width = va_arg(*arg, int)) < 0) {
            f.justification_options = left_justification;
            f.field_width = -f.field_width;
        }

        c = *++s;
    } else {
        while (msl_isdigit(c)) {
            f.field_width = f.field_width * 10 + c - '0';
            c = *++s;
        }
    }

    if (f.field_width > 509) {
        f.conversion_char = 0xFF;
        *format = f;
        return s + 1;
    }

    if (c == '.') {
        f.precision_specified = 1;

        if ((c = *++s) == '*') {
            if ((f.precision = va_arg(*arg, int)) < 0) {
                f.precision_specified = 0;
            }

            c = *++s;
        } else {
            while (msl_isdigit(c)) {
                f.precision = f.precision * 10 + c - '0';
                c = *++s;
            }
        }
    }

    flag_found = 1;

    switch (c) {
    case 'h':
        f.argument_options = short_argument;

        if (s[1] == 'h') {
            f.argument_options = char_argument;
            c = *++s;
        }

        break;
    case 'l':
        f.argument_options = long_argument;

        if (s[1] == 'l') {
            f.argument_options = long_long_argument;
            c = *++s;
        }

        break;
    case 'L':
        f.argument_options = long_double_argument;
        break;
    case 'j':
        f.argument_options = intmax_argument;
        break;
    case 't':
        f.argument_options = ptrdiff_argument;
        break;
    case 'z':
        f.argument_options = size_t_argument;
        break;
    default:
        flag_found = 0;
        break;
    }

    if (flag_found) {
        c = *++s;
    }

    f.conversion_char = c;

    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 1;
        } else if (f.justification_options == zero_fill) {
            f.justification_options = right_justification;
        }

        break;

    case 'f':
    case 'F':
        if (f.argument_options == short_argument || f.argument_options == intmax_argument ||
            f.argument_options == size_t_argument || f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument) {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 6;
        }

        break;

    case 'a':
    case 'A':
        if (!f.precision_specified) {
            f.precision = 0xD;
        }

        if (f.argument_options == short_argument || f.argument_options == intmax_argument ||
            f.argument_options == size_t_argument || f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument || f.argument_options == char_argument) {
            f.conversion_char = 0xFF;
        }

        break;

    case 'g':
    case 'G':
        if (!f.precision) {
            f.precision = 1;
        }

    case 'e':
    case 'E':
        if (f.argument_options == short_argument || f.argument_options == intmax_argument ||
            f.argument_options == size_t_argument || f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument || f.argument_options == char_argument) {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 6;
        }

        break;

    case 'p':
        f.conversion_char = 'x';
        f.alternate_form = 1;
        f.argument_options = long_argument;
        f.precision = 8;
        break;

    case 'c':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.precision_specified || f.argument_options != normal_argument) {
                f.conversion_char = 0xFF;
            }
        }

        break;

    case 's':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.argument_options != normal_argument) {
                f.conversion_char = 0xFF;
            }
        }

        break;

    case 'n':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
        }

        break;

    default:
        f.conversion_char = 0xFF;
        break;
    }

    *format = f;
    return s + 1;
}
#pragma pop
