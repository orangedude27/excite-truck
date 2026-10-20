// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "ansi_files.h"
#include "buffer_io.h"

int fn_80024A0C(void *);
int fflush(void *arg0) {
    int var_r30;
    unsigned int temp_r4, temp_r4_2, temp_r4_3;
    struct { unsigned int mode:3; unsigned int low:29; } *state;
    if (arg0 == 0) return __flush_all();
    if (*((unsigned char *)arg0 + 0xA) != 0 || ((*(unsigned int *)((char *)arg0 + 4) >> 22) & 7) == 0) return -1;
    temp_r4 = *(unsigned int *)((char *)arg0 + 4);
    if (((temp_r4 >> 27) & 7) == 1) return 0;
    temp_r4_2 = *(unsigned int *)((char *)arg0 + 8);
    if ((temp_r4_2 >> 29) >= 3) {
        state = (void *)((char *)arg0 + 8);
        state->mode = 2;
    }
    if ((*(unsigned int *)((char *)arg0 + 8) >> 29) == 2) *(int *)((char *)arg0 + 0x28) = 0;
    temp_r4_3 = *(unsigned int *)((char *)arg0 + 8);
    if ((temp_r4_3 >> 29) != 1) {
        *(unsigned int *)((char *)arg0 + 8) = temp_r4_3 & 0x1FFFFFFF;
        return 0;
    }
    if (((*(unsigned int *)((char *)arg0 + 4) >> 22) & 7) != 1) var_r30 = 0;
    else var_r30 = fn_80024A0C(arg0);
    if (__flush_buffer(arg0, 0) != 0) {
        *((unsigned char *)arg0 + 0xA) = 1;
        *(int *)((char *)arg0 + 0x28) = 0;
        return -1;
    }
    *(unsigned int *)((char *)arg0 + 8) &= 0x1FFFFFFF;
    *(int *)((char *)arg0 + 0x18) = var_r30;
    *(int *)((char *)arg0 + 0x28) = 0;
    return 0;
}
