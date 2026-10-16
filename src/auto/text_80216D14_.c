// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EFAC;
void fn_80216D28(void) {
    lbl_8055EFAC = 1;
}

void fn_80216D34(void) {
    lbl_8055EFAC = 0;
}

void fn_80217478(void) {

}

void fn_802180B0(void) { fn_80217EC0(0, 1, 0); }

void fn_802180BC(void) { fn_80217EC0(0, 1, 1); }

extern int fn_80217EC0(void *, int, int);
void fn_802180C8(void *arg0) { fn_80217EC0(arg0, 0, 0); }

void fn_802180D4(void) { fn_80217EC0(0, 0, 1); }

