// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char* file, s32 line,
                                             const char* fmt, ...);

#pragma push
#pragma small_data off
extern u8 lbl_803204F8[];
extern u8 lbl_803204BC[];
extern u8 lbl_803204B0[];
extern u8 lbl_80320474[];
extern u8 lbl_80320320[];
extern u8 lbl_803203D8[];
#pragma pop

extern u32 lbl_8055DE00;

struct Color {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
};

extern "C" u32* fn_800DCDFC(void) {
    return &lbl_8055DE00;
}
