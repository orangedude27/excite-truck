// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
__declspec(section ".sdata") extern unsigned char lbl_8055FC18;
extern char lbl_804C1338[];
#pragma push
#pragma scheduling invalid_target
void fn_802C8238(void) {
    unsigned char *base = (unsigned char *)lbl_804C1338;
    int *p0 = (int *)(base + 0x00);
    int *p1 = (int *)(base + 0x58);
    int *p2 = (int *)(base + 0x64);
    int *p3 = (int *)(base + 0x70);
    int *p4 = (int *)(base + 0x7C);
    fn_8000D838(&lbl_8055FC18);
    p0[0] = 0;
    p0[2] = 0;
    p0[1] = 0;
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
#pragma pop
