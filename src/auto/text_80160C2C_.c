// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E2C0;
extern int lbl_8055E2C8;
extern int lbl_8042FD78[];
extern int lbl_8042FD84[];
extern void fn_80160C8C(void);
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, int);
#pragma scheduling invalid_target
void fn_80160C2C(void) {
    fn_8000D838(&lbl_8055E2C0);
    lbl_8055E2C8 = 0xFFFF0000;
    *(void **)&lbl_8042FD84 = (char *)&lbl_8042FD84 + 12;
    *(int *)((char *)&lbl_8042FD84 + 8) = 0x14;
    *(int *)((char *)&lbl_8042FD84 + 4) = 0;
    __register_global_object(&lbl_8042FD84, &fn_80160C8C, &lbl_8042FD78, 0x14);
}
