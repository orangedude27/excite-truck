// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* This unit's static-destructor record, chained onto the global list at startup. */
extern char gThisUnitDtorRecord[4];
extern void fn_8000D838(void *record);
/* Startup (.ctors) thunk: register this unit's static-destructor record on the global chain. */
void fn_800126C4(void) {
    fn_8000D838(gThisUnitDtorRecord);
}
