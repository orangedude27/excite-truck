// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
extern void fn_8000D838(void *);
extern s32 lbl_804986E0[];
extern s32 lbl_8055F0F0;
extern s32 lbl_8055F0F8;

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8023995C(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055F0F0);
    p = lbl_804986E0 + 1;
    lbl_804986E0[0] = 0;
    v = 0x7B;
    lbl_804986E0[1] = v;
    lbl_804986E0[2] = 0;
    lbl_804986E0[3] = 0;
    lbl_804986E0[4] = 0;
    lbl_8055F0F8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
