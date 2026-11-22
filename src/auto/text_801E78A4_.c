#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(int *);
extern int lbl_8055EAE0;
extern int lbl_8055EAE8;
extern int lbl_8055EAEC;
#pragma scheduling on
void fn_801E78A4(void) {
    fn_8000D838(&lbl_8055EAE0);
    ((int *)&lbl_8055EAE8)[1] = 0x7F000000;
    lbl_8055EAE8 = 0xFFFF0000;
}
