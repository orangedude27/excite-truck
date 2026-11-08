// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055F640;
extern int lbl_804A433C[];
extern int lbl_804A4330[];
extern void fn_8027AA08(void);
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_8027AD04(void) {
    fn_8000D838(&lbl_8055F640);
    lbl_804A433C[12] = 0;
    __register_global_object((void *)lbl_804A433C, (void *)fn_8027AA08, (void *)&lbl_804A4330[0]);
}
#pragma opt_propagation reset
#pragma scheduling reset
