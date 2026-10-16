// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FFB5;
extern void *lbl_8055FF8C;
extern float lbl_804FC680[];
extern int lbl_8055D1EC;
extern int lbl_8055D1F0;
extern void fn_802E7770(void);
extern int fn_802E7774(void (*arg0)(void));
extern void fn_802E2E0C(void *arg0, void *arg1);
void fn_802E6240(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void fn_802E6248(int arg0, float arg1) {
    lbl_804FC680[arg0] = arg1;
}

void fn_802E625C(void* hi) {
    lbl_8055FF8C = hi;
}

int* fn_802E6ABC(void) {
    return &lbl_8055D1EC;
}

void fn_802E6AC4(void) {
    lbl_8055FFB5 = 1;
}

void fn_802E6B38(void* arg0, signed char* arg1) {
    *arg1 = 0;
}

