// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int fn_8002F53C(void *, void *, void *, int, int);
extern unsigned char lbl_8055F648;
extern char lbl_804A4380[];
extern char lbl_804A4370[];
extern void *fn_8027D494(void *);
extern void *fn_8027D280(void *, int);
extern void fn_8027D264(void);
#pragma push
#pragma scheduling invalid_target
void fn_8027D204(void) {
    fn_8000D838(&lbl_8055F648);
    fn_8002F53C(lbl_804A4380, fn_8027D494, fn_8027D280, 0x3B10, 4);
    __register_global_object(0, fn_8027D264, lbl_804A4370);
}
#pragma pop
