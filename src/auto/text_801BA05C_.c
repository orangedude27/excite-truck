// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E768;
extern int lbl_8055E770;
void fn_8000D838(void *);
/* Register the static-destructor record at lbl_8055E768, then mark its next link with the end-of-list sentinel. */
void fn_801BA05C(void) {
#define STATIC_DTOR_LIST_END 0xFFFF0000
    fn_8000D838(&lbl_8055E768);
    lbl_8055E770 = STATIC_DTOR_LIST_END;
#undef STATIC_DTOR_LIST_END
}
