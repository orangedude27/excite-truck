// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_80559900;

extern "C" u32 fn_800FEB9C(void);

u32 fn_800FEB9C(void) {
    u32 val = lbl_80559900 * 0x19660D;
    val += 0x3C6F0000;
    u32 out = val;
    out -= 0x0CA1;
    lbl_80559900 = out;
    return out >> 16;
}
