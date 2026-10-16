// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_80559C00;
extern void *lbl_8042F788[4];
extern unsigned char lbl_8055E0E0;
extern void fn_80128668(void*);
void fn_80137B0C(void* hi) {
    lbl_80559C00 = hi;
}

void fn_80137B14(void) {
    lbl_80559C00 = (void*)-1;
}

void fn_80137BE4(void) {
    void **p = lbl_8042F788;
    int i = 0;
    do {
        fn_80128668(*p);
        i++;
        *p = 0;
        p++;
    } while (i < 4);
    lbl_8055E0E0 = 0;
}

void* fn_80137C4C(void) {
    return lbl_80559C00;
}

void* fn_80137C54(int index) {
    if (index == -1) {
        index = (int)lbl_80559C00;
    }
    return lbl_8042F788[index];
}

void fn_80137C74(void) {
    fn_800167F4();
}

void fn_80137C78(void) {
    fn_800167FC();
}

void fn_80137C7C(void) {
    fn_8001683C();
}

void fn_80137C80(void) {
    fn_80016A44();
}

