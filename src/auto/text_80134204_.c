// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on
extern char lbl_8055E070[4];
extern int fn_8000D838(void*);

/* Compiler-generated .ctors entry: register this file's static-destructor
 * record with fn_8000D838 so its object is destroyed at exit. */
void fn_80134204(void) {
    fn_8000D838(lbl_8055E070);
}
