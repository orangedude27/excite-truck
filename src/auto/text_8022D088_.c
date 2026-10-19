// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern void *lbl_8055EFC0;
extern s32 lbl_8055EFC8;
extern s32 lbl_80490950[];

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8022D088(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055EFC0);
    p = lbl_80490950 + 1;
    lbl_80490950[0] = 0;
    v = 0x7B;
    lbl_80490950[1] = v;
    lbl_80490950[2] = 0;
    lbl_80490950[3] = 0;
    lbl_80490950[4] = 0;
    lbl_8055EFC8 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
