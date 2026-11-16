// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D4E0[4];
extern int fn_8000D838(void*);
extern unsigned int lbl_8055D4E8;
/* Register the static-destructor record at lbl_8055D4E0, then mark its next link with the end-of-list sentinel. */
void fn_80012688(void)
{
#define STATIC_DTOR_LIST_END 0x7f000000
    fn_8000D838(&lbl_8055D4E0);
    lbl_8055D4E8 = STATIC_DTOR_LIST_END;
#undef STATIC_DTOR_LIST_END
}
