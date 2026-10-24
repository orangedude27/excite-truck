// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>
#pragma small_data off
extern void fn_8000D838(void*);
extern int lbl_80507288[3];
extern int lbl_80560018;
#pragma scheduling invalid_target
void fn_802E988C(void) {
    fn_8000D838(&lbl_80560018);
    lbl_80507288[0] = 0;
    lbl_80507288[1] = 1;
}
#pragma scheduling on
