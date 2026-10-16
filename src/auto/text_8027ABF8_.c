// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804A433C;
extern void *fn_8027ACBC(void *, void *);
#pragma push
#pragma small_data off
void fn_8027ABF8(void *node) { fn_8027ACBC(&lbl_804A433C, node); }
int fn_8027AC08(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 0x88);
    void *entry = arg0;
    int i = 0;
    for (; i < count; i++, entry = (char *)entry + 8) {
        if (arg1 == *(int *)((char *)entry + 0x30))
            return *(int *)((char *)arg0 + 0x34 + i * 8);
    }
    return 0;
}
int fn_8027AC50(void *arg0) {
    return *(int *)((char *)arg0 + 0xF0) != 0;
}

int fn_8027AC64(void *arg0) {
    if (*(int *)((char *)arg0 + 0xF0) == 0) {
        return -1;
    }
    return *(int *)((char *)arg0 + 0xF8);
}

