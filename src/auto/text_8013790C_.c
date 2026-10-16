// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055E0C8;
extern int lbl_802EE7E0[3];
extern int lbl_8042F778[3];
void fn_8013790C(void) {
    int *src;
    int *dst;
    fn_8000D838(&lbl_8055E0C8);
    src = lbl_802EE7E0;
    dst = lbl_8042F778;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
}
