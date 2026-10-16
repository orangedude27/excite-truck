typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055BAC8;
s32 fn_80214D04(void);
void fn_80239A94(void) {
    lbl_8055BAC8 = (void*)fn_80214D04();
}
