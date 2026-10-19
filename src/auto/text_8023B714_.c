// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern void fn_8000D838(void *);
extern unsigned char lbl_8055F120;
extern u32 lbl_80498758[];
extern u32 lbl_8055F128;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8023B714(void) {
    u32 v;
    u32 *p;
    fn_8000D838(&lbl_8055F120);
    p = lbl_80498758 + 1;
    lbl_80498758[0] = 0;
    v = 0x7B;
    lbl_80498758[1] = v;
    lbl_80498758[2] = 0;
    lbl_80498758[3] = 0;
    lbl_80498758[4] = 0;
    lbl_8055F128 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
