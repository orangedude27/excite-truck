// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <macros.h>

void fn_8000D838(void *arg0);
extern char lbl_8055EF60[4];
extern int lbl_804908B0[];
extern u32 lbl_8055EF68;
extern u32 lbl_8055EF6C;

#pragma scheduling invalid_target
void fn_80216CBC(void) {
    int zero = 0;
    int *p;
    fn_8000D838(lbl_8055EF60);
    p = lbl_804908B0;
    lbl_804908B0[0] = zero;
    p[1] = 0x7B;
    lbl_8055EF68 = 0xFFFF0000;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    lbl_8055EF6C = 0x7F000000;
}
#pragma scheduling on
