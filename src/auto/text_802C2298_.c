// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_804C109C[];
extern void fn_802C6CF8(void *);
void fn_802C2410(void) {
    int i = 0;
    while (i < *(int *)((char *)lbl_804C109C + 4)) {
        fn_802C6CF8(*(void **)((char *)lbl_804C109C[0] + i * 0x14));
        i++;
    }
    *(int *)((char *)lbl_804C109C + 4) = 0;
}
