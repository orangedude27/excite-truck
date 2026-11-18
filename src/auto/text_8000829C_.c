// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8000D838(void *);
void fn_801312EC(void *, void *);
extern unsigned char lbl_802FB6E0[];
extern unsigned char lbl_8034EF20[];
extern unsigned int lbl_8055D358;
struct Hdr {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char pad[0x1F0];
};
void fn_8000829C(void) {
    register int *src = (int *)lbl_802FB6E0;
    register int *dst = (int *)lbl_8034EF20;

    fn_8000D838(&lbl_8055D358);
    dst[1] = 0x7B;
    dst[0] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    fn_801312EC(dst + 0x80, src + 0x44);
    fn_801312EC(dst + 0x83, src + 0x49);
    fn_801312EC(dst + 0x86, src + 0x4E);
    fn_801312EC(dst + 0x89, src + 0x53);
    fn_801312EC(dst + 0x8C, src + 0x58);
    fn_801312EC(dst + 0x8F, src + 0x5E);
    fn_801312EC(dst + 0x92, src + 0x63);
    fn_801312EC(dst + 0x95, src + 0x69);
    fn_801312EC(dst + 0x98, src + 0x6F);
    fn_801312EC(dst + 0x9B, src + 0x75);
    fn_801312EC(dst + 0x9E, src + 0x7A);
    fn_801312EC(dst + 0xA1, src + 0x7F);
}
