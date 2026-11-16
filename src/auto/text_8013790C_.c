// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055E0C8;
extern int lbl_802EE7E0[3];
extern int lbl_8042F778[3];
void fn_8013790C(void) {
    /* Initializes lbl_8055E0C8 and copies 3 words from lbl_802EE7E0 to lbl_8042F778. */
    int *source;
    int *destination;

    fn_8000D838(&lbl_8055E0C8);
    source = lbl_802EE7E0;
    destination = lbl_8042F778;
    *destination++ = *source++;
    *destination++ = *source++;
    *destination = *source;
}
