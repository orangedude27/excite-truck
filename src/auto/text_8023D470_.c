// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_8000D838(void *);
extern char lbl_8055F158;
extern int lbl_804987A0[];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8023D470(void) {
    int v;
    fn_8000D838(&lbl_8055F158);
    lbl_804987A0[0] = 0;
    v = 123;
    lbl_804987A0[1] = v;
    lbl_804987A0[2] = 0;
    lbl_804987A0[3] = 0;
    lbl_804987A0[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
