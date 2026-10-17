// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
extern float lbl_8042F8A8[];
extern int lbl_8055E174;
extern float lbl_80561474;
void fn_8013B950(void);
void fn_8013BC54(void) {
    lbl_8055E174++;
    if ((lbl_8055E174 & 7) == 0) {
        fn_8013B950();
    }
}

u8 fn_8013BC70(float *arg0) {
    *arg0 = lbl_8042F8A8[0];
    return *((u8 *)lbl_8042F8A8 + 4);
}
