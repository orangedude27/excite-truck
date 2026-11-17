// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D458[4];
extern void fn_8000D838(void *queue);
void fn_8000DFA0(void) {
#define sThisUnitDtorRecord lbl_8055D458
    /* Startup (.ctors) thunk: register this unit's static-destructor record on the global chain. */
    fn_8000D838(sThisUnitDtorRecord);
#undef sThisUnitDtorRecord
}
