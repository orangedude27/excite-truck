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
/**
 * @brief MSL printf's format-specifier parser: consume the conversion
 *        specifier at the head of a format string and fill in the print_format.
 */
const char* parse_format_80025258(const char* format_string, va_list* arg, print_format* format) {
    print_format fmt;
    const char* s = format_string;
    int c;
    int flag_found;

    fmt.justification_options = right_justification;
    fmt.sign_options = only_minus;
    fmt.precision_specified = 0;
    fmt.alternate_form = 0;
    fmt.argument_options = normal_argument;
    fmt.field_width = 0;
    fmt.precision = 0;

    if ((c = *++s) == '%') {
        fmt.conversion_char = c;
        *format = fmt;
        return s + 1;
    }

    for (;;) {
        flag_found = 1;

        switch (c) {
        case '-':
            fmt.justification_options = left_justification;
            break;
        case '+':
            fmt.sign_options = sign_always;
            break;
        case ' ':
            if (fmt.sign_options != sign_always) {
                fmt.sign_options = space_holder;
            }
            break;
        case '#':
            fmt.alternate_form = 1;
            break;
        case '0':
            if (fmt.justification_options != left_justification) {
                fmt.justification_options = zero_fill;
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
        if ((fmt.field_width = va_arg(*arg, int)) < 0) {
            fmt.justification_options = left_justification;
            fmt.field_width = -fmt.field_width;
        }

        c = *++s;
    } else {
        while (msl_isdigit(c)) {
            fmt.field_width = fmt.field_width * 10 + c - '0';
            c = *++s;
        }
    }

    if (fmt.field_width > 509) {
        fmt.conversion_char = 0xFF;
        *format = fmt;
        return s + 1;
    }

    if (c == '.') {
        fmt.precision_specified = 1;

        if ((c = *++s) == '*') {
            if ((fmt.precision = va_arg(*arg, int)) < 0) {
                fmt.precision_specified = 0;
            }

            c = *++s;
        } else {
            while (msl_isdigit(c)) {
                fmt.precision = fmt.precision * 10 + c - '0';
                c = *++s;
            }
        }
    }

    flag_found = 1;

    switch (c) {
    case 'h':
        fmt.argument_options = short_argument;

        if (s[1] == 'h') {
            fmt.argument_options = char_argument;
            c = *++s;
        }

        break;
    case 'l':
        fmt.argument_options = long_argument;

        if (s[1] == 'l') {
            fmt.argument_options = long_long_argument;
            c = *++s;
        }

        break;
    case 'L':
        fmt.argument_options = long_double_argument;
        break;
    case 'j':
        fmt.argument_options = intmax_argument;
        break;
    case 't':
        fmt.argument_options = ptrdiff_argument;
        break;
    case 'z':
        fmt.argument_options = size_t_argument;
        break;
    default:
        flag_found = 0;
        break;
    }

    if (flag_found) {
        c = *++s;
    }

    fmt.conversion_char = c;

    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (fmt.argument_options == long_double_argument) {
            fmt.conversion_char = 0xFF;
            break;
        }

        if (!fmt.precision_specified) {
            fmt.precision = 1;
        } else if (fmt.justification_options == zero_fill) {
            fmt.justification_options = right_justification;
        }

        break;

    case 'f':
    case 'F':
        if (fmt.argument_options == short_argument || fmt.argument_options == intmax_argument ||
            fmt.argument_options == size_t_argument || fmt.argument_options == ptrdiff_argument ||
            fmt.argument_options == long_long_argument) {
            fmt.conversion_char = 0xFF;
            break;
        }

        if (!fmt.precision_specified) {
            fmt.precision = 6;
        }

        break;

    case 'a':
    case 'A':
        if (!fmt.precision_specified) {
            fmt.precision = 0xD;
        }

        if (fmt.argument_options == short_argument || fmt.argument_options == intmax_argument ||
            fmt.argument_options == size_t_argument || fmt.argument_options == ptrdiff_argument ||
            fmt.argument_options == long_long_argument || fmt.argument_options == char_argument) {
            fmt.conversion_char = 0xFF;
        }

        break;

    case 'g':
    case 'G':
        if (!fmt.precision) {
            fmt.precision = 1;
        }

    case 'e':
    case 'E':
        if (fmt.argument_options == short_argument || fmt.argument_options == intmax_argument ||
            fmt.argument_options == size_t_argument || fmt.argument_options == ptrdiff_argument ||
            fmt.argument_options == long_long_argument || fmt.argument_options == char_argument) {
            fmt.conversion_char = 0xFF;
            break;
        }

        if (!fmt.precision_specified) {
            fmt.precision = 6;
        }

        break;

    case 'p':
        fmt.conversion_char = 'x';
        fmt.alternate_form = 1;
        fmt.argument_options = long_argument;
        fmt.precision = 8;
        break;

    case 'c':
        if (fmt.argument_options == long_argument) {
            fmt.argument_options = wchar_argument;
        } else {
            if (fmt.precision_specified || fmt.argument_options != normal_argument) {
                fmt.conversion_char = 0xFF;
            }
        }

        break;

    case 's':
        if (fmt.argument_options == long_argument) {
            fmt.argument_options = wchar_argument;
        } else {
            if (fmt.argument_options != normal_argument) {
                fmt.conversion_char = 0xFF;
            }
        }

        break;

    case 'n':
        if (fmt.argument_options == long_double_argument) {
            fmt.conversion_char = 0xFF;
        }

        break;

    default:
        fmt.conversion_char = 0xFF;
        break;
    }

    *format = fmt;
    return s + 1;
}
#pragma pop
