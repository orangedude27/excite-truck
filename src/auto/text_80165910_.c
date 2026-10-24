// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055E2D0;
extern int lbl_8055E2D8;
extern int lbl_8042FDEC[];
extern int lbl_8042FDE0[];
extern void fn_80165970(void);
#pragma push
#pragma scheduling invalid_target
void fn_80165910(void) {
    fn_8000D838(&lbl_8055E2D0);
    lbl_8055E2D8 = 0x7F000000;
    *(void **)&lbl_8042FDEC = (char *)&lbl_8042FDEC + 12;
    *(int *)((char *)&lbl_8042FDEC + 8) = 0x10;
    *(int *)((char *)&lbl_8042FDEC + 4) = 0;
    __register_global_object(&lbl_8042FDEC, &fn_80165970, &lbl_8042FDE0);
}
#pragma pop
