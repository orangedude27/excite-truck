// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FC08[4];
extern int fn_8000D838(void*);
extern unsigned int lbl_8055FC10;
/* Static initializer: registers a static-destructor record, then sets its associated word. */
void fn_802C5364(void)
{
#define s_initRecord lbl_8055FC08
#define s_value      lbl_8055FC10
    fn_8000D838(&s_initRecord);
    s_value = 0x7f000000;
#undef s_value
#undef s_initRecord
}
