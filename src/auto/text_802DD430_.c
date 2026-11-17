// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, int, int);
extern int lbl_8055FE90;
extern short lbl_8055FE98;
extern short lbl_8055FE9A;
extern short lbl_8055FE9C;
extern int lbl_804DB480[];
extern int lbl_804DB474[];
extern void fn_802DD4A0(void);
#pragma push
#pragma scheduling invalid_target
void fn_802DD430(void) {
    fn_8000D838(&lbl_8055FE90);
    lbl_8055FE98 = 0x100;
    lbl_8055FE9A = 0x405;
    lbl_8055FE9C = 0x401;
    *(void **)&lbl_804DB480 = (char *)&lbl_804DB480 + 12;
    lbl_804DB480[2] = 0xA;
    lbl_804DB480[1] = 0;
    ((void (*)(void *, void *, void *))__register_global_object)(&lbl_804DB480, &fn_802DD4A0, &lbl_804DB474);
}
#pragma pop
