typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
void fn_80018794(void) {
    lbl_8055D560 = (void*)atoi();
}

void fn_800187F8(void) {
    lbl_8055D564 = 1;
}
