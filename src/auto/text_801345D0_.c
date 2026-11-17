// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E088[4];
extern void fn_8000D838(void *queue);
void fn_801345D0(void) {
#define sStaticDtorRecord lbl_8055E088
    /* Register the static object at sStaticDtorRecord so its destructor runs at program exit. */
    fn_8000D838(sStaticDtorRecord);
#undef sStaticDtorRecord
}
