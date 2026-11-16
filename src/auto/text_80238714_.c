// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F0A8;
extern int lbl_80498650[5];
extern void fn_8000D838(int *);
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize this module's state and global init flag (constructor). */
void fn_80238714(void) {
#define moduleInitFlag lbl_8055F0A8
#define moduleState    lbl_80498650

    int initialValue;
    fn_8000D838(&moduleInitFlag);
    moduleState[0] = 0;
    initialValue = 123;
    moduleState[1] = initialValue;
    moduleState[2] = 0;
    moduleState[3] = 0;
    moduleState[4] = 0;

#undef moduleInitFlag
#undef moduleState
}
#pragma opt_propagation reset
#pragma scheduling on
