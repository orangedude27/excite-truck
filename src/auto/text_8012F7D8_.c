// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E028[4];
extern void fn_8000D838(void *queue);
void fn_8012F7D8(void) {
#define RegisterStaticDtor fn_8000D838
#define s_dtorRecord lbl_8055E028
    /* C++ static initializer (a .ctors entry): chain this module's
     * static-destructor record onto the global list headed by lbl_8055D450. */
    RegisterStaticDtor(s_dtorRecord);
#undef s_dtorRecord
#undef RegisterStaticDtor
}
