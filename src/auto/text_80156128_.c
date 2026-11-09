// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E228;
extern int lbl_8055E230;
extern int lbl_8055E234;
extern int lbl_8055E254;
extern int lbl_8042FC70[];
extern void fn_8000D838(void *);
#pragma scheduling invalid_target
void fn_80156128(void) {
    int v;
    int *p;
    fn_8000D838(&lbl_8055E228);
    p = lbl_8042FC70 + 1;
    lbl_8055E230 = 0xFFFF0000;
    lbl_8042FC70[0] = 0;
    v = 0x7B;
    lbl_8042FC70[1] = v;
    lbl_8042FC70[2] = 0;
    lbl_8042FC70[3] = 0;
    lbl_8042FC70[4] = 0;
    lbl_8055E254 = -1;
    lbl_8055E234 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling reset
