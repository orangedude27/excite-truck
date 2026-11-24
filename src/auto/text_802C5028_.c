// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055FBB0;
extern unsigned short lbl_8055FBB8, lbl_8055FBBA, lbl_8055FBBC;
extern int lbl_8055FBC0, lbl_8055FBC4, lbl_8055FBC8, lbl_8055FBCC;
extern int lbl_8055FBD0, lbl_8055FBD4, lbl_8055FBD8, lbl_8055FBDC;
extern int lbl_8055FBE0, lbl_8055FBE4, lbl_8055FBE8, lbl_8055FBEC;
extern int lbl_8055FBF0, lbl_8055FBF4, lbl_8055FBF8, lbl_8055FBFC;
#pragma use_lmw_stmw off
void fn_802C5028(void) {
    int cbcc, cbc8, cbd0;
    fn_8000D838(&lbl_8055FBB0);
    cbcc = 0x03EF01EF;
    cbc8 = 0x03E001E0;
    cbd0 = 0x78003C00;
    lbl_8055FBC4 = 0x001F001F;
    lbl_8055FBE4 = 0x001F001F;
    lbl_8055FBCC = cbcc;
    lbl_8055FBDC = 0x7BEF3DEF;
    lbl_8055FBC8 = cbc8;
    lbl_8055FBD0 = cbd0;
    lbl_8055FBFC = 0xFFFF7FFF;
    lbl_8055FBE0 = 0x42082108;
    lbl_8055FBB8 = 0x0100;
    lbl_8055FBD4 = 0x780F3C0F;
    lbl_8055FBD8 = 0x7BE03DE0;
    lbl_8055FBE8 = 0x07E003E0;
    lbl_8055FBBA = 0x0405;
    lbl_8055FBBC = 0x0401;
    lbl_8055FBC0 = 0;
    lbl_8055FBEC = 0x07FF03FF;
    lbl_8055FBF0 = 0xF8007C00;
    lbl_8055FBF4 = 0xF81F7C1F;
    lbl_8055FBF8 = 0xFFE07FE0;
}
#pragma use_lmw_stmw on
