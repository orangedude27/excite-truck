// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055F990;
extern int lbl_804BE104[];
extern int lbl_804BE0F8[];
extern void fn_802B1CE0(void);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802B1C88(void) {
    fn_8000D838(&lbl_8055F990);
    lbl_804BE104[0] = (int)((char *)lbl_804BE104 + 12);
    lbl_804BE104[2] = 0x20;
    lbl_804BE104[1] = 0;
    __register_global_object((void *)lbl_804BE104, (void *)fn_802B1CE0, (void *)&lbl_804BE0F8[0]);
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling reset
