// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80272354(void);
extern void fn_8002F634(void *, void *, int, int);
extern char lbl_80347364[];
extern char lbl_8049A2C8[];
extern char lbl_8049F9D8[];
extern void fn_80273B08(void);
extern void fn_80273978(void);
void fn_80273A88(void) {
    fn_8002F634(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}

void fn_80273AA4(void *arg0) {
    *(int *)arg0 = 0;
    *(char **)((char *)arg0 + 0x18) = lbl_80347364;
}

int fn_80273ABC(int arg0) {
    fn_80272354();
    return arg0;
}

void fn_80273AEC(void) {
    fn_8002F634(lbl_8049A2C8, fn_80273B08, 0x60, 0xC8);
}

void fn_80273B48(void) {
}

