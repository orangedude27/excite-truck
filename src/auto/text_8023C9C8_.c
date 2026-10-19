// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern int lbl_8055F138;
extern int lbl_80498788[];
extern int lbl_8055F140;
extern void fn_8000D838(void *);
void fn_8023C9C8(void) {
    int zero = 0;
    int *p = lbl_80498788;
    fn_8000D838(&lbl_8055F138);
    *p = zero;
    p[1] = 0x7b;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    lbl_8055F140 = 0x7f000000;
}
