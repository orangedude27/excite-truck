// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E2B0;
extern int lbl_8055E2B8;
void fn_8000D838(void *);
/* Registers this module's static-destructor record and sets its 32-bit aRGB
 * value to 0xFFFF0000 (opaque red). */
void fn_80160AE8(void) {
#define sDtorRecord lbl_8055E2B0 /* static-destructor record for this module */
#define sColor lbl_8055E2B8      /* 32-bit aRGB value */
    fn_8000D838(&sDtorRecord);
    sColor = 0xFFFF0000;
#undef sColor
#undef sDtorRecord
}
