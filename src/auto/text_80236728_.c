// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F0C4;
void fn_80236774(void) {
    lbl_8055F0C4 = 0;
}

extern char lbl_8055F0C5;
void fn_802368E0(void) {
    lbl_8055F0C5 = 1;
}

extern int fn_80215264(void);
extern void fn_80236A5C(void*, int);
extern void fn_80237AA0(void);
extern void fn_80236960(void);
extern char *lbl_8055F0C0;
void fn_80236900(void) {
    lbl_8055F0C0[0x21] = 0;
}

void fn_80236910(void) {
    fn_80236960();
}

void fn_80236914(void) {
    fn_80237AA0();
}

void fn_80236918(void* alarm) {
    fn_80236A5C(alarm, fn_80215264());
}

extern void fn_80237AA0(void);
extern void fn_80236960(void);
