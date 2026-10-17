// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EA40;
extern void *lbl_8055EA3C;
extern char lbl_8055EA38;
void fn_801A47C8(void);
void fn_801A47FC(int);
void fn_8015F670(int *, int);
void fn_801E21B4(void* hi) {
    lbl_8055EA40 = hi;
}

void fn_801E222C(void) {
    lbl_8055EA38 = 0;
    if (lbl_8055EA3C != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA3C + 0x14)))();
        lbl_8055EA3C = 0;
    }
    if (lbl_8055EA40 != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA40 + 0x14)))();
        lbl_8055EA40 = 0;
    }
}

void fn_801E2294(void) {
    if (lbl_8055EA3C != 0)
        fn_801A47C8();
    if (lbl_8055EA40 != 0)
        fn_801A47C8();
}

