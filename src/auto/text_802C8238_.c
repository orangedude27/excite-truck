// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
__declspec(section ".sdata") extern unsigned char lbl_8055FC18;
extern char lbl_804C1338[];
void fn_802C8238(void) {
    unsigned int *base = (unsigned int *)lbl_804C1338;
    unsigned int *p1 = &base[0x58 >> 2];
    unsigned int *p2 = &base[0x64 >> 2];
    unsigned int *p3 = &base[0x70 >> 2];
    unsigned int *p4 = &base[0x7C >> 2];
    fn_8000D838(&lbl_8055FC18);
    base[0x00 >> 2] = 0;
    base[0x08 >> 2] = 0;
    base[0x04 >> 2] = 0;
    p1[2] = 0;
    p1[1] = 0;
    p1[0] = 0;
    p2[2] = 0;
    p2[1] = 0;
    p2[0] = 0;
    p3[2] = 0;
    p3[1] = 0;
    p3[0] = 0;
    p4[2] = 0;
    p4[1] = 0;
    p4[0] = 0;
}
#pragma opt_common_subs reset
