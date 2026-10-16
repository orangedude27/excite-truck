// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D54C;
void* fn_80016508(void) {
    return lbl_8055D54C;
}

extern void *lbl_8055D550;
void* fn_800165D4(void) {
    return lbl_8055D550;
}

extern void *lbl_8055D554;
extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
void* fn_800167F4(void) {
    return lbl_8055D554;
}

void fn_800167FC(void *arg0) {
    lbl_8055D554 = arg0;
}

int fn_80016804(int arg0, int arg1) {
    if (arg1 < (int)lbl_8055D554 &&
        arg0 == *(int *)(lbl_803577F0 + arg1 * 0x5C + 4)) {
        return 1;
    }
    return 0;
}

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
void fn_8001683C(void *arg0, int arg1) {
    void *temp = fn_80016474();
    *(void **)(lbl_803577F0 + arg1 * 0x5C + 4) = arg0;
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x4C) = *(int *)((char *)temp + 0x4C);
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x50) = *(int *)((char *)temp + 0x50);
    *(int *)(lbl_80357960 + arg1 * 0xA8 + 4) = -1000;
}

void fn_80016A44(void) {
    fn_8001766C();
}
