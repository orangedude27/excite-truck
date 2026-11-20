// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E0E8[8];
extern int fn_8000D838(void*);
extern unsigned int lbl_8055E0F0;
extern unsigned int lbl_8055E0F4;
static inline void fn_80138BB0_set_hi(unsigned int v) { lbl_8055E0F0 = v; }
void fn_80138BB0(void) {
    unsigned int *p = &lbl_8055E0F0;
    fn_8000D838(&lbl_8055E0E8);
    p[1] = 0x7F000000;
    p[0] = fn_80138BB0_hi();
}
