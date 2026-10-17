// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern int fn_8024683C(void);
extern int fn_80244550(int);
extern int lbl_8055F1E0;
#pragma scheduling off
int fn_8023FA50(int *arg0) {
    int result;
    if (fn_80244550(lbl_8055F1E0) == 0) goto done;
    *arg0 = -2;
    result = 1;
    goto out;
done:
    result = 0;
out:
    return result;
}
#pragma scheduling on
void fn_8023FA9C(void) {
    fn_80214A9C(0xC);
    fn_8024683C();
    fn_80214A9C(0x1F);
    fn_80214AF0(0xC);
}

extern char *fn_8000DC70(int);
extern void fn_8000DC28(char *, int);
extern int fn_8023FAD4(char *, int);
extern char *strcpy(char *, const char *);
extern char *strstr(const char *, const char *);
extern int strcmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055BD3C[];
__declspec(section ".sdata") extern char lbl_8055BD48[];
__declspec(section ".sdata") extern char lbl_8055BD50[];
__declspec(section ".sdata") extern char lbl_8055BD58[];
void fn_8023FCFC(int arg0) {
    char path[0x20];

    strcpy(path, fn_8000DC70(arg0));
    if (strstr(path, lbl_8055BD48) != 0 ||
        strstr(path, lbl_8055BD50) != 0 ||
        strstr(path, lbl_8055BD58) != 0) {
        strcpy(path, lbl_8055BD3C);
    }
    if (fn_8023FAD4(path, 0x13) != 0 &&
        strcmp(fn_8000DC70(arg0), path) != 0 &&
        strcmp(path, lbl_8055BD3C) != 0) {
        fn_8000DC28(path, arg0);
    }
}

