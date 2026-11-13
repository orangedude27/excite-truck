// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern u8 lbl_8055E190[8];
extern void fn_8000D838(void *);
extern u8 lbl_8055E190[8];
extern s32 lbl_8042FB10[];
extern s32 lbl_8055E198;
extern s32 lbl_8055E19C;
extern s32 lbl_8055E1A0;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8013CAB4(void) {
    s32 v;
    s32 *p;
    s32 w;
    fn_8000D838(lbl_8055E190);
    p = lbl_8042FB10 + 1;
    lbl_8042FB10[0] = 0;
    v = 0x7B;
    lbl_8042FB10[1] = v;
    w = 0xFFFF0000;
    lbl_8042FB10[2] = 0;
    lbl_8042FB10[3] = 0;
    lbl_8042FB10[4] = 0;
    lbl_8055E19C = 0x7F000000;
    lbl_8055E198 = w;
    lbl_8055E1A0 = w;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
