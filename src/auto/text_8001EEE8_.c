// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055D5E8;
extern s32 lbl_8055D5F0;
extern s32 lbl_80358668[];
void fn_8000D838(void *);

static void Init5(s32 *p) {
    p[0] = 0;
    p[1] = 0x7B;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

static void Init5z(s32 z, s32 *p) {
    p[0] = z;
    p[1] = 0x7B;
    p[2] = z;
    p[3] = z;
    p[4] = z;
}

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8001EEE8(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055D5E8);
    p = lbl_80358668 + 1;
    lbl_80358668[0] = 0;
    v = 0x7B;
    lbl_80358668[1] = v;
    lbl_80358668[2] = 0;
    lbl_80358668[3] = 0;
    lbl_80358668[4] = 0;
    lbl_8055D5F0 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
