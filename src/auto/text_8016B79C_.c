#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8016CEFC(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

s32 fn_8016DE10(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

u32 fn_80170FD4(void) { return 1; }

void fn_80171208(void *arg0, s32 arg1) {
    fn_801B0C78((void *)arg1);
}
