// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D568[4];
extern void fn_8000D838(void *record);

/* Static constructor (.ctors entry D_802ED0AC): register this module's static-destructor
 * record by pushing it onto the global destructor chain so it runs at exit. */
void fn_80018B68(void) {
#define RegisterStaticDtor fn_8000D838
#define StaticDtorRecord   lbl_8055D568
    RegisterStaticDtor(StaticDtorRecord);
#undef StaticDtorRecord
#undef RegisterStaticDtor
}
