// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stdarg.h>

__declspec(section ".data") extern int lbl_802FE850;
extern int jumptable_802FE978[];
extern int jumptable_802FE898[];

static inline int is_digit_char(int c) {
    int table = *(int *)(lbl_802FE850 + 0x38);
    return (c < 0 || c >= 0x100) ? 0 :
        (*(unsigned short *)(*(int *)(table + 8) + c * 2) & 8);
}
