// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct decform {
    char style;
    char pad;
    short digits;
} decform;

typedef struct decimal {
    char sign;
    char unk;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[36];
    } sig;
} decimal;

typedef struct print_format {
    unsigned char flags;
    unsigned char sign_options;
    unsigned char pad2;
    unsigned char alternate_form;
    unsigned char pad4;
    unsigned char conversion_char;
    unsigned char pad6[6];
    int precision;
} print_format;

typedef struct CtypeTable {
    char pad[8];
    unsigned short *map;
} CtypeTable;

typedef struct LocaleData {
    char pad[0x38];
    CtypeTable *ctype;
} LocaleData;

extern char *lbl_802FE6A0;
extern LocaleData lbl_802FE850;

#define MY_ISUPPER(c) (((c) < 0 || (c) >= 256) ? 0 : (lbl_802FE850.ctype->map[(c)] & 0x200))

void __num2dec(const decform *, double, decimal *);
void round_decimal(decimal *, int);

char *float2str_8002620C(char *buff, print_format *format, double num)
{
    decimal dec;
    decform form;
    char *p;
    char dp = *(*(char ***)&lbl_802FE6A0)[0];
    int n, i;

    if (format->precision > 509) return 0;
    form.style = 0;
    form.digits = 32;
    __num2dec(&form, num, &dec);
    p = (char *)&dec.sig.text[dec.sig.length];
    while (dec.sig.length > 1 && *--p == '0') {
        dec.sig.length--;
        dec.exp++;
    }
    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
    default:
        p = buff;
        dec.exp = dec.exp + dec.sig.length - 1;
        *--p = 0;
        switch (format->conversion_char) {
        case 'g':
        case 'G':
            if (dec.sig.length > format->precision) round_decimal(&dec, format->precision);
            if (dec.exp < -4 || dec.exp >= format->precision) {
                if (format->alternate_form) format->precision--;
                else format->precision = dec.sig.length - 1;
                if (format->conversion_char == 'g') format->conversion_char = 'e';
                else format->conversion_char = 'E';
        case 'e':
        case 'E': {
                char sign = '+';
                int e;
                int cnt = 0;
                if (dec.sig.length > format->precision + 1) round_decimal(&dec, format->precision + 1);
                e = dec.exp;
                if (e < 0) { e = -e; sign = '-'; }
                do {
                    *--p = (e % 10) + '0';
                    e /= 10;
                    cnt++;
                } while (e != 0 || cnt < 2);
                *--p = sign;
                *--p = format->conversion_char;
                if (format->precision + (buff - p) > 509) return 0;
                if (dec.sig.length < format->precision + 1) {
                    for (i = format->precision + 2 - dec.sig.length; --i; ) *--p = '0';
                }
                {
                    int k = dec.sig.length;
                    unsigned char *s = &dec.sig.text[k];
                    while (--k) *--p = *--s;
                }
                if (format->precision != 0 || format->alternate_form) *--p = dp;
                *--p = dec.sig.text[0];
                if (dec.sign) *--p = '-';
                else if (format->sign_options == 1) *--p = '+';
                else if (format->sign_options == 2) *--p = ' ';
                break;
            }
            if (format->alternate_form) format->precision = format->precision - (dec.exp + 1);
            else {
                format->precision = dec.sig.length - (dec.exp + 1);
                if (format->precision < 0) format->precision = 0;
            }
        }
        case 'f':
        case 'F': {
            int frac_digits = dec.sig.length - dec.exp - 1;
            int int_digits;
            unsigned char *s;
            if (frac_digits < 0) frac_digits = 0;
            if (frac_digits > format->precision) {
                round_decimal(&dec, dec.sig.length - (frac_digits - format->precision));
                frac_digits = dec.sig.length - dec.exp - 1;
                if (frac_digits < 0) frac_digits = 0;
            }
            int_digits = dec.exp + 1;
            if (int_digits < 0) int_digits = 0;
            if (int_digits + frac_digits > 509) return 0;
            s = &dec.sig.text[dec.sig.length];
            for (i = 0; i < format->precision - frac_digits; i++) *--p = '0';
            for (n = 0; n < frac_digits && n < dec.sig.length; n++) *--p = *--s;
            for (; n < frac_digits; n++) *--p = '0';
            if (format->precision != 0 || format->alternate_form) *--p = dp;
            if (int_digits != 0) {
                for (i = 0; i < int_digits - dec.sig.length; i++) *--p = '0';
                for (n = i; n < int_digits; n++) *--p = *--s;
            } else {
                *--p = '0';
            }
            if (dec.sign) *--p = '-';
            else if (format->sign_options == 1) *--p = '+';
            else if (format->sign_options == 2) *--p = ' ';
            break;
        }
        }
        return p;
    case 'I':
        if (num < 0) {
            p = buff - 5;
            strcpy(p, MY_ISUPPER(format->conversion_char) ? "-INF" : "-inf");
        } else {
            p = buff - 4;
            strcpy(p, MY_ISUPPER(format->conversion_char) ? "INF" : "inf");
        }
        return p;
    case 'N':
        if (dec.sign) {
            p = buff - 5;
            strcpy(p, MY_ISUPPER(format->conversion_char) ? "-NAN" : "-nan");
        } else {
            p = buff - 4;
            strcpy(p, MY_ISUPPER(format->conversion_char) ? "NAN" : "nan");
        }
        return p;
    }
}
