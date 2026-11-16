// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Record fn_8000D838 chains onto the global static-destructor list. */
typedef struct {
    unsigned char tag;  /* 0x31, written by fn_8000D838 */
    void *next;         /* 0x4 previous head of the list (lbl_8055D450) */
} StaticDtorRecord;

extern StaticDtorRecord lbl_8055E5F8; /* this module's record, in .sbss */
extern int lbl_8055E600;              /* state word right behind it */
void fn_8000D838(void *);
void fn_801AE570(void) {
    fn_8000D838(&lbl_8055E5F8);
    lbl_8055E600 = 0xFFFF0000;
}
