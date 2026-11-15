// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_80498E68[];
extern int lbl_8055F360;
__declspec(section ".sdata") extern int lbl_8055F370;
extern void fn_8000D838(void *);
extern int lbl_8055F360;
extern int lbl_80498E68[];
__declspec(section ".sdata") extern int lbl_8055F370;
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802582FC(void) {
    /* Initialize this module's BSS state and small-data sentinel pair. */
    int *state;
    int *sentinels;
    fn_8000D838(&lbl_8055F360);
    state = lbl_80498E68;
    lbl_80498E68[0] = 0;
    state[1] = 0x7B;
    state[2] = 0;
    state[3] = 0;
    state[4] = 0;
    lbl_8055F370 = -1;
    sentinels = &lbl_8055F370;
    sentinels[1] = -1;
}
