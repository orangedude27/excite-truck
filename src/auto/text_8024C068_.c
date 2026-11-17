// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F2A0[4];
extern void fn_8000D838(void *queue);
void fn_8024C068(void) {
#define gStaticObject lbl_8055F2A0
    /* Static initializer: register this unit's tagged global object with the runtime's static-destructor list. */
    fn_8000D838(gStaticObject);
#undef gStaticObject
}
