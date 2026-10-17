// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E160;
extern int lbl_802F9350[3];
extern char lbl_8042F858[];
extern int fn_80028E00(char *, int);
extern int fn_8013A6D4(int);
extern int fn_802E317C(char *, ...);
extern char lbl_8032C1A0[];
typedef struct { int pad[3]; int (*m_fn)(void); } unkVtable;
void fn_8013A660(unkVtable **arg0, char *arg1, char *arg2) {
    int result;
    result = (*arg0)->m_fn();
    if (result == 0) {
        fn_802E317C(lbl_8032C1A0, arg2, arg1);
    }
}

int fn_8013A6C4(void *arg0, void *arg1) {
    return *(int *)((char *)arg0 + 8) - *(int *)((char *)arg1 + 8);
}

int fn_8013A6D4(int arg0) {
    int values[3];
    int *p = lbl_802F9350;
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[arg0];
}

char *fn_8013A708(char *arg0, int arg1, int arg2) {
    strcpy(arg0, (char *)fn_8013A6D4(arg1));
    fn_80028E00(arg0, arg2);
    return arg0;
}

void DBPrintf_8013B490(const char *fmt, ...) {
#pragma unused(fmt)
}

void fn_8013B56C(void) {
    lbl_8055E160 = 0;
}
