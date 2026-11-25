// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { unsigned int lo, hi; } U32Pair;

extern char lbl_8055E0E8[8];
extern int fn_8000D838(void*);
extern unsigned int lbl_8055E0F0;
extern unsigned int lbl_8055E0F4;
#pragma scheduling invalid_target
unsigned int fn_80138BB0(void) {
    fn_8000D838(lbl_8055E0E8);
    lbl_8055E0F4 = 0x7F000000;
    lbl_8055E0F0 = 0xFFFF0000;
    return 0xFFFF0000;
}
