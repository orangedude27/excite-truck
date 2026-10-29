// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern unsigned char lbl_8041E098[];
extern unsigned char lbl_8055DF68[];
void fn_80127FC8(void) {
    unsigned char *p;
    unsigned char *end;
    int i;
    fn_8000D838(&lbl_8055DF68);
    *(int *)(lbl_8041E098 + 0x10) = 0;
    *(int *)(lbl_8041E098 + 8) = 0;
    *(int *)(lbl_8041E098 + 0xC) = 0;
    lbl_8041E098[0x14] = 0;
    p = lbl_8041E098 + 0x18;
    end = lbl_8041E098 + 0xA8;
    while (p < end) {
        *(int *)(p + 8) = 0;
        *(int *)(p + 0) = 0;
        *(int *)(p + 4) = 0;
        p[0xC] = 0;
        p += 0x10;
    }
    lbl_8041E098[0] = 0;
    *(int *)(lbl_8041E098 + 4) = 0;
}
