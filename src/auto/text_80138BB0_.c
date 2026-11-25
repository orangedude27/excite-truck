// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { unsigned int lo, hi; } U32Pair;

extern char lbl_8055E0E8[8];
extern int fn_8000D838(void*);
extern unsigned int lbl_8055E0F0;
extern unsigned int lbl_8055E0F4;
unsigned int fn_80138BB0(void) {
    unsigned int *p = &lbl_8055E0F0;
    fn_8000D838(lbl_8055E0E8);
    p[1] = 0x7F000000;
    p[0] = 0xFFFF0000;
    return 0xFFFF0000;
}
#pragma scheduling on
