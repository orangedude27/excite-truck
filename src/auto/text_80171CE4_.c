// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
extern void *lbl_8055E380;
extern s32 lbl_8055E388;
void fn_8000D838(void *);
/* Register the static-destructor record at lbl_8055E380, then mark its next link with the end-of-list sentinel. */
void fn_80171CE4(void) {
#define STATIC_DTOR_LIST_END 0xFFFF0000
    fn_8000D838(&lbl_8055E380);
    lbl_8055E388 = STATIC_DTOR_LIST_END;
#undef STATIC_DTOR_LIST_END
}
