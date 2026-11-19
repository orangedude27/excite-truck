// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055F214;
extern int lbl_8055F208;
extern int lbl_8055F210;
extern int lbl_80498848[];
#pragma scheduling invalid_target
void fn_802445A4(void) {
    int *p;
    fn_8000D838(&lbl_8055F208);
    p = lbl_80498848;
    p[0] = 0;
    p[1] = 0x7b;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_8055F214 = 0xffff0000u;
    lbl_8055F210 = 0x7f000000u;
}
#pragma scheduling on
