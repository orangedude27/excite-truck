// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E090[4];
extern void fn_8000D838(void *);

void fn_80134714(void) {
#define gStaticObject lbl_8055E090
    /* Static initializer: register this unit's tagged global object (lbl_8055E090) with the runtime's static-destructor list. */
    fn_8000D838(gStaticObject);
#undef gStaticObject
}
