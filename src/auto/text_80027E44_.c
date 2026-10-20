// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stdarg.h>
#include <MSL/scanf.h>
#include <MSL/ctype.h>

typedef long long intmax_t;

enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    intmax_argument,
    size_t_argument,
    ptrdiff_argument,
    long_long_argument,
    double_argument,
    long_double_argument,
    wchar_argument
};

typedef unsigned char char_map[32];

typedef struct {
    unsigned char suppress_assignment;
    unsigned char field_width_specified;
    unsigned char argument_options;
    unsigned char conversion_char;
    int           field_width;
    char_map char_set;
} scan_format;

#define set_char_map(map, ch) map[(unsigned char)ch >> 3] |= (1 << (ch & 7))
#define tst_char_map(map, ch) (map[(unsigned char)ch >> 3] &  (1 << (ch & 7)))

extern __Locale lbl_802FE850;
#define __ctype_test(c, mask) (((c) < 0 || (c) >= 256) ? 0 : ((*(const unsigned short**)((char*)lbl_802FE850.cmap + 8))[(c)] & (mask)))
#define isspace(c) __ctype_test(c, 0x100)

extern int lbl_80558DB0[];
#define NAN (*(float*)&lbl_80558DB0)

extern const char* parse_format_80109DEC(const char* format_string, scan_format *format);
extern unsigned long __strtoul(int base, int max_width, int (*ReadProc)(void*, int, int),
                               void* ReadProcArg, int* chars_scanned, int* negative, int* overflow);
extern unsigned long long __strtoull(int base, int max_width, int (*ReadProc)(void*, int, int),
                                     void* ReadProcArg, int* chars_scanned, int* negative, int* overflow);
extern long double __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg,
                             int* chars_scanned, int* overflow);
extern int fn_80024BD4(wchar_t *pwc, const char *s, size_t n);
#define mbtowc fn_80024BD4

