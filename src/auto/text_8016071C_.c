// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E2BC;
extern int lbl_8042FD60[5];
extern int fn_8027DED0(void);
extern int fn_8001D9B4(int *, int);
extern int fn_8001DA48(void *, int);
int fn_80160A74(void) {
    if (lbl_8055E2BC != 0) {
        return *(int *)((char *)lbl_8055E2BC + 0x14);
    }
    return 2;
}

void fn_80160A90(void* alarm) {
    fn_80160998(fn_80160AB4(alarm));
}

void fn_80160AE4(void) {
    fn_801607F8();
}
