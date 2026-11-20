// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
struct State { void *next; int size; int zero; };

extern int lbl_8055DF10;
extern struct State lbl_8041DEE0;
void fn_801279E0(void) {
    #pragma scheduling invalid_target
    fn_8000D838(&lbl_8055DF10);
    lbl_8041DEE0.next = (char *)&lbl_8041DEE0 + 0xC;
    lbl_8041DEE0.size = 0x10;
    lbl_8041DEE0.zero = 0;
}
