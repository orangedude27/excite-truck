// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801308F4(void) {
    fn_8013072C();
}

void fn_80131264(void) {
    fn_801302E0();
}

void fn_80131268(void) {
    fn_80131234();
}

extern int lbl_8055E044;
void fn_80131308(void) { lbl_8055E044 += 1; }

void fn_801312EC(int *arg0, int arg1) {
    arg0[0] = arg1;
    arg0[1] = 0;
    arg0[2] = ~lbl_8055E044;
}

void fn_80131318(int *arg0) {
    int temp_r3;
    temp_r3 = fn_801302E0(arg0[0]);
    arg0[1] = temp_r3;
    if (temp_r3 == 0) {
        arg0[1] = arg0[0];
        return;
    }
    arg0[2] = lbl_8055E044;
}
extern int lbl_8055E044;
extern char lbl_8032B328[];
int fn_802E317C(const char *, ...);

char *fn_8013126C(char *arg0, const char *arg1) {
    int count;
    char *dst;
    const char *src;
    dst = arg0;
    src = arg1;
    fn_802E317C(lbl_8032B328);
    count = 0x12c;
    do {
        *dst++ = *src++;
    } while (*src != 0 && --count > 0);
    return arg0;
}
