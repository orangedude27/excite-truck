// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FB50;
extern int lbl_8034AFB8;
extern int lbl_8034AFC8;
extern int lbl_8055FB54;
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void fn_802C1C28(void) {}

void fn_802C1C2C(void) {}

void fn_802C2054(int arg0) { fn_802C1F80(arg0 - 4); }

void fn_802C205C(int arg0) { fn_802C1F84(arg0 - 4); }

void fn_802C2064(int arg0) { fn_802C1F88(arg0 - 4); }

void fn_802C206C(int arg0) { fn_802C1F8C(arg0 - 4); }

int fn_802C2074(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802C20DC(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

short fn_802C2120(int arg0) {
    return (short)(((arg0 << 8) / 1024) + 0x80);
}

void fn_802C217C(void) {
    fn_802C20DC((int *)&lbl_8055FB50);
    if (lbl_8055FB54 != 0) {
        fn_802B52B4();
        lbl_8055FB54 = 0;
    }
}

void* fn_802C21B8(void) {
    return lbl_8055FB50;
}
