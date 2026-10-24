// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055F950;
extern int lbl_804BD8CC[3];
extern int lbl_804BD8C0[];
extern void *fn_802AE588(void *, int);
#pragma scheduling invalid_target
void fn_802AE530(void) {
    fn_8000D838(&lbl_8055F950);
    lbl_804BD8CC[0] = (int)((char *)lbl_804BD8CC + 12);
    lbl_804BD8CC[2] = 4;
    lbl_804BD8CC[1] = 0;
    __register_global_object((void *)lbl_804BD8CC, (void *)fn_802AE588, (void *)&lbl_804BD8C0[0]);
}
#pragma scheduling on
