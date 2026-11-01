// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80342278[];
extern unsigned int lbl_802FA2E8[];
extern unsigned int lbl_804987F8[];
__declspec(section ".sdata") extern char lbl_8055BD38[];
__declspec(section ".sdata") extern char lbl_8055BD40[];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
__declspec(section ".sdata") extern char lbl_8055B860[];
__declspec(section ".sdata") extern char lbl_8055BD3C[];
extern void fn_80028E00(void *);
extern void *fn_801284F8(int, void *);
extern void *fn_802439E8(void *, char *, int);
extern void fn_8022D228(void *, int, int);
extern void fn_8022D350(void *, void *, int);
extern void fn_8022D2BC(void *, int);
extern int fn_802146BC(void *, int, int, int);
extern void fn_8023FA9C(void);
extern void fn_80236914(void);
extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern int fn_8024683C(void);
extern int fn_80244550(int);
extern int lbl_8055F1E0;
#pragma scheduling invalid_target
int fn_8023FA50(int *arg0) {
    if (fn_80244550(lbl_8055F1E0) != 0) {
        *arg0 = -2;
        return 1;
    }
    return 0;
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
extern char lbl_80342278[];
extern unsigned int lbl_802FA2E8[];
extern unsigned int lbl_804987F8[];
__declspec(section ".sdata") extern char lbl_8055BD38[];
__declspec(section ".sdata") extern char lbl_8055BD40[];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
__declspec(section ".sdata") extern char lbl_8055B860[];
extern void fn_80028E00(void *);
extern void *fn_801284F8(int, void *);
extern void *fn_802439E8(void *, char *, int);
extern void fn_8022D228(void *, int, int);
extern void fn_8022D350(void *, void *, int);
extern void fn_8022D2BC(void *, int);
extern int fn_802146BC(void *, int, int, int);
extern void fn_8023FA9C(void);
extern void fn_80236914(void);
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

