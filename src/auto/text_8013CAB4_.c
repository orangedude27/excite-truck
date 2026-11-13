// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern u8 lbl_8055E190[8];
struct Unk8042FB10 { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; };
extern struct Unk8042FB10 lbl_8042FB10;
extern s32 lbl_8055E198;
extern s32 lbl_8055E19C;
extern s32 lbl_8055E1A0;
void fn_8013CAB4(void) {
    fn_8000D838(lbl_8055E190);
    lbl_8042FB10.f0 = 0;
    lbl_8042FB10.f4 = 0x7B;
    lbl_8042FB10.f8 = 0;
    lbl_8042FB10.fC = 0;
    lbl_8042FB10.f10 = 0;
    lbl_8055E19C = 0x7F000000;
    lbl_8055E198 = 0xFFFF0000;
    lbl_8055E1A0 = 0xFFFF0000;
}
