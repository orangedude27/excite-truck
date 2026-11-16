// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F130[4];
extern int lbl_80498770[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8023C26C(void) {
    /* InitializeModuleState: initialize state block and reset runtime fields (index 1 = 123). */
#define moduleInitState lbl_8055F130
#define moduleState     lbl_80498770
    int initialValue;
    fn_8000D838(&moduleInitState);
    moduleState[0] = 0;
    initialValue = 123;
    moduleState[1] = initialValue;
    moduleState[2] = 0;
    moduleState[3] = 0;
    moduleState[4] = 0;
#undef moduleInitState
#undef moduleState
}
#pragma opt_propagation reset
#pragma scheduling on
