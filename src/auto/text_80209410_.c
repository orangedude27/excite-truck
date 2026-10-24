// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_801312EC(void *, void *);
extern int lbl_8055EDA0;
extern char lbl_8048929C[];
extern char lbl_8033C1B0[];
void fn_80209410(void) {
    fn_8000D838(&lbl_8055EDA0);
    fn_801312EC(&lbl_8048929C, &lbl_8033C1B0);
}
