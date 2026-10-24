// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055E310;
extern int lbl_8042FEB0[3];
extern int lbl_8042FEA4[];
extern void *fn_801677DC(void *, int);
#pragma scheduling invalid_target
void fn_80167784(void) {
    fn_8000D838(&lbl_8055E310);
    lbl_8042FEB0[0] = (int)((char *)lbl_8042FEB0 + 12);
    lbl_8042FEB0[2] = 8;
    lbl_8042FEB0[1] = 0;
    __register_global_object((void *)lbl_8042FEB0, (void *)fn_801677DC, (void *)&lbl_8042FEA4[0]);
}
#pragma scheduling on
