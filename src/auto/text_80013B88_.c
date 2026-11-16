// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D4F8[4];
extern int lbl_80351828[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
/* RealName: unknown (rename_symbol unavailable). Initializes a small state block:
 * chains the static record at lbl_8055D4F8 onto the list headed by lbl_8055D450,
 * then clears lbl_80351828[0..4] and sets lbl_80351828[1] to 123. */
void fn_80013B88(void) {
#define s_initRecord lbl_8055D4F8
#define s_stateWords lbl_80351828
    int initialValue;
    fn_8000D838(&s_initRecord);
    s_stateWords[0] = 0;
    initialValue = 123;
    s_stateWords[1] = initialValue;
    s_stateWords[2] = 0;
    s_stateWords[3] = 0;
    s_stateWords[4] = 0;
#undef s_initRecord
#undef s_stateWords
}
#pragma opt_propagation reset
#pragma scheduling on
