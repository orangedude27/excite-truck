// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

__declspec(section ".data") extern int lbl_802FE850;

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

/* MSL <cctype>: the C locale table reached through the global locale object. */
static inline int msl_isdigit(int c) {
    int locale = *(int *)((char *)&lbl_802FE850 + 0x38);
    return (c < 0 || c >= 0x100) ? 0
                                 : (*(unsigned short *)(*(int *)(locale + 8) + c * 2) & 8);
}
