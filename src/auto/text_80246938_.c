typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
char fn_80247624(void) {
    return lbl_8055F260;
}

extern void* lbl_8055BEAC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void* lbl_8055BEB0;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

