// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E030[4];
extern void fn_8000D838(void *queue);
void fn_8012FAB0(void) {
#define sStaticDtorRecord lbl_8055E030
    /* Static constructor (.ctors entry): register this unit's static-destructor record for shutdown. */
    fn_8000D838(sStaticDtorRecord);
#undef sStaticDtorRecord
}
