// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void fn_80009D70(void);
extern void __register_global_object(void *, void *, void *, void *, int, int);
extern int lbl_8034F3B0[];
extern int lbl_8055D360;
extern int lbl_8055D368;

#pragma push
#pragma scheduling invalid_target
void fn_80009CEC(void) {
    int *base = lbl_8034F3B0;
    int *sub;
    fn_8000D838(&lbl_8055D360);
    base[0] = 0;
    base[1] = 0x7B;
    base[2] = 0;
    base[3] = 0;
    base[4] = 0;
    lbl_8055D368 = 0x7F000000;
    sub = base + 8;
    sub[0] = (int)(sub + 3);
    sub[2] = 0x1C;
    sub[1] = 0;
    __register_global_object(sub, fn_80009D70, base + 5, sub + 3, 0x7F000000, 0);
}
#pragma pop
