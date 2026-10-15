// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_80559900;

extern "C" u32 fn_800FEB9C(void);

u32 fn_800FEB9C(void) {
    u32 temp_r0;
    temp_r0 = lbl_80559900 * 0x19660D + 0x3C6EF35F;
    lbl_80559900 = temp_r0;
    return temp_r0 >> 16;
}
