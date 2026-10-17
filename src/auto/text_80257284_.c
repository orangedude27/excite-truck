// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80257A8C(void);
void fn_8022D458(int, int, int *);
void fn_8022D7C4(int, int);
int fn_80128668(int);
extern int lbl_80563AB8;
int fn_802574E0(int arg0, int arg1) { int temp_r3; if (arg0 != 0) { temp_r3 = arg0 + 0x18C; if (temp_r3 != 0) fn_8022D7C4(temp_r3, 0); fn_8022D7C4(arg0 + 0x54, -1); fn_8022D7C4(arg0 + 0x1C, -1); if (arg1 > 0) fn_80128668(arg0); } return arg0; }

void fn_80257A6C(int *arg0, int arg1, int arg2) { *arg0 = (*arg0 + (arg2 + arg1)) % arg2; }

int fn_80257B7C(int arg0) { fn_8022D458(7, 2, &lbl_80563AB8); return arg0; }

void fn_80257BB8(void *arg0, int arg1) { *(int *)((char *)arg0 + 0x30) = arg1; fn_80257A8C(); }
