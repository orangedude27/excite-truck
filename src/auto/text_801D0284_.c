// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E8A8;
extern int lbl_8055E8B0;
void fn_8000D838(void *);
/* Static initializer: registers a static-destructor record, then sets its associated word. */
void fn_801D0284(void) {
#define s_initRecord lbl_8055E8A8
#define s_value      lbl_8055E8B0
    fn_8000D838(&s_initRecord);
    s_value = 0xFFFF0000;
#undef s_value
#undef s_initRecord
}
