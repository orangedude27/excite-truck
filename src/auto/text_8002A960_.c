// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct CtypeCompat {
    int unk0;
    int unk4;
    const unsigned short *ctype_map_ptr;
    const unsigned char *upper_map_ptr;
    const unsigned char *lower_map_ptr;
} CtypeCompat;

typedef struct LocaleCompat {
    char pad[0x38];
    CtypeCompat *ctype_cmpt_ptr;
} LocaleCompat;

extern LocaleCompat lbl_802FE850;

#define strtoull_isspace(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x100))
#define strtoull_isdigit(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x8))
#define strtoull_isalpha(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x1))
#define strtoull_toupper(c) ((c) < 0 || (c) >= 0x100 ? (c) : lbl_802FE850.ctype_cmpt_ptr->upper_map_ptr[(c)])
enum scan_states { start = 0x01, check_for_zero = 0x02, leading_zero = 0x04, need_digit = 0x08, digit_loop = 0x10, finished = 0x20, failure = 0x40 };

unsigned long long __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow) {
    int state = 1;
    int count = 0;
    int spaces = 0;
    unsigned long long acc = 0;
    unsigned long long limit = 0;
    unsigned long long ullmax = 0xFFFFFFFFFFFFFFFFULL;
    int c;
    *overflow = 0;
    *negative = 0;
    if (base < 0 || base == 1 || base > 36 || max_width < 1) {
        state = 0x40;
    } else {
        c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
    }
    if (base != 0) {
        limit = ullmax / base;
    }
    while (count <= max_width && c != -1 && !(state & 0x60)) {
        switch (state) {
        case 1:
            if (strtoull_isspace(c)) {
                c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
            } else if (c == '-') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
                *negative = 1;
            }
            state = 2;
            break;
        case 2:
            if ((base == 0 || base == 16) && c == '0') {
                state = 4;
                c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
            } else {
                state = 8;
            }
            break;
        case 4:
            if (c == 'X' || c == 'x') {
                base = 16;
                state = 8;
                c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
            } else {
                if (base == 0) {
                    base = 8;
                }
                state = 0x10;
            }
            break;
        case 8:
        case 0x10:
            if (base == 0) {
                base = 10;
            }
            if (!limit) {
                limit = ullmax / base;
            }
            if (strtoull_isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (state == 0x10) {
                        state = 0x20;
                    } else {
                        state = 0x40;
                    }
                    c += '0';
                    break;
                }
            } else if (!strtoull_isalpha(c) || (strtoull_toupper(c) - 0x37 >= base)) {
                if (state == 0x10) {
                    state = 0x20;
                } else {
                    state = 0x40;
                }
                break;
            } else {
                c = strtoull_toupper(c) - 0x37;
            }
            if (acc > limit) {
                *overflow = 1;
            }
            acc *= base;
            if ((unsigned long long)c > ullmax - acc) {
                *overflow = 1;
            }
            acc += c;
            state = 0x10;
            c = (count++, (*ReadProc)(ReadProcArg, 0, 0));
            break;
        }
    }
    if (!(state & 0x34)) {
        acc = 0;
        *chars_scanned = 0;
    } else {
        *chars_scanned = count + spaces - 1;
    }
    (*ReadProc)(ReadProcArg, c, 1);
    return acc;
}
