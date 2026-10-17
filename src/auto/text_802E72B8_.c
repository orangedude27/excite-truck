// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E3990(void);
extern int fn_802E3734(int *);
extern int fn_802E72C8(void);
extern int fn_802E36D8(void *);
extern void fn_802E3A14(int);
extern void fn_802E3930(int, void *, int);
extern unsigned char lbl_804FC978[];
extern int lbl_8055FFD8;
extern int lbl_8055FFDC;
extern signed char lbl_8055FFE0;
extern int lbl_8034D7D8;
extern int fn_802E30C8(int *, int, int, int);
int fn_802E72B8(int arg0) {
    return (arg0 + 0x7ff) / 2048;
}

void fn_802E7318(void) {
    lbl_8055FFDC = 0;
    lbl_8055FFD8 = 0;
    lbl_8055FFE0 = 1;
}

void fn_802E746C(int arg0, int *arg1, int *arg2) {
    unsigned char *entry = lbl_804FC978 + arg0 * 0x90;
    *arg1 = *(int *)entry;
    *arg2 = *(int *)(entry + 8);
}

int fn_802E748C(int arg0, void *arg1, int arg2, int arg3) {
    int temp_r29;
    int temp_r3;
    int temp_r3_2;
    int var_r5;
    unsigned char *temp_r31;
    temp_r3_2 = fn_802E72C8();
    if (temp_r3_2 < 0) return -1;
    temp_r31 = lbl_804FC978 + temp_r3_2 * 0x90;
    temp_r3 = fn_802E36D8(temp_r31 + 0x10);
    if (temp_r3 == -1) return -1;
    temp_r29 = (arg0 - *(int *)temp_r31) << 11;
    ((void (*)(int, int))fn_802E3A14)(temp_r3, temp_r29);
    var_r5 = (*(int *)(temp_r31 + 8) - temp_r29 + 0x1f) & ~0x1f;
    if (var_r5 > arg2) var_r5 = arg2;
    fn_802E3930(temp_r3, arg1, var_r5);
    return temp_r3;
}

void fn_802E7544(void) { fn_802E3990(); }

void fn_802E7548(int arg0) { fn_802E3734(&arg0); }

