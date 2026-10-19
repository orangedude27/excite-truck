// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055F1A0;
extern int lbl_8055F1A8;
extern int lbl_804987E0[5];
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8023FA00(void) {
    int v;
    fn_8000D838(&lbl_8055F1A0);
    *(volatile int *)&lbl_8055F1A8 = 0x7F000000;
    ((volatile int *)lbl_804987E0)[0] = 0;
    v = 0x7B;
    ((volatile int *)lbl_804987E0)[1] = v;
    ((volatile int *)lbl_804987E0)[2] = 0;
    ((volatile int *)lbl_804987E0)[3] = 0;
    ((volatile int *)lbl_804987E0)[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on
