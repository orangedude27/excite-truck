#include "types.h"
#include "string.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8012F43C(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

void fn_8012F448(void *arg0, s32 arg1) {
    ((s32 *)arg0)[1] = arg1;
}

s32 fn_8012F450(void *arg0) {
    return ((s32 *)arg0)[1];
}

void fn_8012F458(void *arg0, s32 arg1) {
    s32 value = arg1;
    memcpy(**(u8 ***)arg0 + ((s32 *)arg0)[1], &value, 4);
    ((s32 *)arg0)[1] += 4;
}

