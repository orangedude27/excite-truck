// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804A433C;
extern void fn_8027ACBC(void *, void *);
void fn_8027ABF8(void *node) {
    fn_8027ACBC((void *)lbl_804A433C, node);
}

int fn_8027AC08(void *arg0, int arg1) {
    int i;
    for (i = 0; i < *(int *)((char *)arg0 + 0x88); i++) {
        if (arg1 == *(int *)((char *)arg0 + 0x30 + i * 8)) {
            return *(int *)((char *)arg0 + 0x34 + i * 8);
        }
    }
    return 0;
}

int fn_8027AC50(void *arg0) {
    return *(int *)((char *)arg0 + 0xF0) != 0;
}

