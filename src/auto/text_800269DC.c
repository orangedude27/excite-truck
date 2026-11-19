// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "stdarg.h"
#include "string.h"
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

struct Fmt { char f0; char f1; char f2; char f3; char lenCode; char conv; char f6; char f7; int width; int prec; };
extern char *parse_format_80025258();
extern char *longlong2str_80025A7C();
extern char *long2str_80025854();
extern char *float2str_8002620C();
extern char *double2hex_80025D1C();
extern int wcstombs(char *, void *, int);
typedef int (*outfunc)(void *, const char *, int);

int __pformatter_800269DC(outfunc func, void *arg, char *fmt, va_list ap) {
    char fill;
    struct Fmt c1, c2, c3, c4, c5, c6;
    struct Fmt fmtStruct;
    char buf[512];
    int total;
    char *p;
    char *pct;
    char *str;
    int len;
    int r;
    char *result;
    unsigned int uval;
    long long llval;
    double dval;
    total = 0;
    fill = 32;
    p = fmt;
    for (;;) {
        if (*p == 0) return total;
        pct = strchr(p, '%');
        if (pct == 0) {
            len = strlen(p);
            total += len;
            if (len == 0) return total;
            r = func(arg, p, len);
            if (r != 0) return total;
            return -1;
        }
        total += pct - p;
        if (pct - p != 0) {
            r = func(arg, p, pct - p);
            if (r == 0) return -1;
        }
        p = parse_format_80025258(pct, ap, &fmtStruct);
        str = buf;
        result = (char *)1;
        if (fmtStruct.conv == 'n') {
            int *ptr = *(int **)__va_arg(ap, 1);
            *(int *)ptr = total;
            return total;
        } else if (fmtStruct.conv == 'c') {
            buf[0] = (char)va_arg(ap, int);
        } else if (fmtStruct.conv == '%') {
            buf[0] = '%';
        } else if (fmtStruct.conv == 's') {
            str = va_arg(ap, char *);
            len = strlen(str);
            result = (char *)len;
        } else if (fmtStruct.conv == 'A' || fmtStruct.conv == 'a') {
            dval = va_arg(ap, double);
            c6 = fmtStruct;
            str = double2hex_80025D1C(buf + 512, &c6, dval);
            if (str == 0) goto out;
            result = (char *)((buf + 511) - str);
        } else if (fmtStruct.conv == 'E' || fmtStruct.conv == 'e') {
            dval = va_arg(ap, double);
            c5 = fmtStruct;
            str = float2str_8002620C(buf + 512, &c5, dval);
            if (str == 0) goto out;
            result = (char *)((buf + 511) - str);
        } else if (fmtStruct.conv == 'd' || fmtStruct.conv == 'i') {
            if (fmtStruct.lenCode == 4 || fmtStruct.lenCode == 6) {
                llval = va_arg(ap, long long);
                c1 = fmtStruct;
                str = longlong2str_80025A7C(llval >> 32, llval, buf + 512, &c1);
            } else {
                uval = va_arg(ap, unsigned int);
                c2 = fmtStruct;
                str = long2str_80025854(uval, buf + 512, &c2);
            }
            if (str == 0) goto out;
            result = (char *)((buf + 511) - str);
        } else {
            goto out;
        }
        r = func(arg, str, (int)result);
        if (r == 0) return -1;
        total += (int)result;
        continue;
    out:
        len = strlen(str);
        total += len;
        return total;
    }
}
