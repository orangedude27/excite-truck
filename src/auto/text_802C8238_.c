// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
__declspec(section ".sdata") extern unsigned char lbl_8055FC18;
extern char lbl_804C1338[];
void fn_802C8238(void) {
    unsigned char *base = (unsigned char *)lbl_804C1338;
    unsigned int *p0 = (unsigned int *)(base + 0x00);
    unsigned int *p1 = (unsigned int *)(base + 0x58);
    unsigned int *p2 = (unsigned int *)(base + 0x64);
    unsigned int *p3 = (unsigned int *)(base + 0x70);
    unsigned int *p4 = (unsigned int *)(base + 0x7C);
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
