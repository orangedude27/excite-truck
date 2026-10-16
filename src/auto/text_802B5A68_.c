typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FA31;
void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

extern void* lbl_8055FA44;
s32 fn_802B5D94(void);
void fn_802B5EC4(void) {
    lbl_8055FA44 = (void*)fn_802B5D94();
}

void fn_802B8C98(void) {
    lbl_8055FA31 = 0;
}
