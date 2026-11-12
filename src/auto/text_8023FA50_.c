// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80342278[];
typedef struct { unsigned int w[5]; } W5;
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

int fn_8023FAD4(char *arg0, int arg1) {
    unsigned int l[35];
    char buf[0x14];
    W5 h;
    void *obj;
    int r;
    int i;
    char *s = lbl_80342278;

    fn_80028E00(lbl_8055BD38);
    obj = fn_801284F8(0x38, s + 0x10);
    if (obj != 0) {
        obj = fn_802439E8(obj, arg0, arg1);
    }
    *(void **)&lbl_8055F1E0 = obj;
    fn_8022D228(buf, 10, 0x20);
    for (i = 0; i < 10; i++) {
        fn_8022D350(buf, s + 0x20, 0);
    }
    l[0] = (unsigned int)lbl_8055BAC0;
    l[1] = 8;
    l[2] = (unsigned int)fn_8023FA9C;
    l[3] = 0;
    l[4] = 0;
    l[5] = (unsigned int)lbl_8055BD40;
    l[6] = 3;
    l[7] = (unsigned int)lbl_8055BD3C;
    l[8] = 4;
    l[9] = 0;
    l[10] = (unsigned int)(s + 0x2c);
    l[11] = 5;
    l[12] = *(unsigned int *)&lbl_8055F1E0;
    l[13] = 0;
    l[14] = 0;
    l[15] = (unsigned int)(s + 0x38);
    l[16] = 10;
    l[17] = (unsigned int)buf;
    l[18] = 0;
    l[19] = 0;
    l[20] = (unsigned int)lbl_8055BAB8;
    l[21] = 8;
    l[22] = (unsigned int)fn_80236914;
    l[23] = 2;
    l[24] = 0;
    l[25] = (unsigned int)lbl_8055B860;
    l[26] = 6;
    l[27] = 0;
    l[28] = -1;
    l[29] = 0x1b;
    *(W5 *)&l[30] = *(W5 *)lbl_804987F8;
    h = *(W5 *)lbl_802FA2E8;
    h.w[1] = (unsigned int)l;
    r = fn_802146BC(&h, -999, -999, 1) != -1;
    if (*(void **)&lbl_8055F1E0 != 0) {
        void *o = *(void **)&lbl_8055F1E0;
        (*(void (**)(void *, int))(*(char **)o + 8))(o, 1);
    }
    *(void **)&lbl_8055F1E0 = 0;
    fn_8022D2BC(buf, -1);
    return r;
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
/* Sanitize a player/driver name for the given slot: copy the current name
 * (fn_8000DC70), replace it with an empty string (lbl_8055BD3C) if it contains
 * "Player-", "Guest", or "Driver-" (lbl_8055BD48/50/58), then if validation
 * (fn_8023FAD4, 0x13) passes and the name changed to a non-empty value, apply it
 * back with fn_8000DC28. */
void fn_8023FCFC(int slot) {
    char path[0x20];

    strcpy(path, fn_8000DC70(slot));
    if (strstr(path, lbl_8055BD48) != 0 ||
        strstr(path, lbl_8055BD50) != 0 ||
        strstr(path, lbl_8055BD58) != 0) {
        strcpy(path, lbl_8055BD3C);
    }
    if (fn_8023FAD4(path, 0x13) != 0 &&
        strcmp(fn_8000DC70(slot), path) != 0 &&
        strcmp(path, lbl_8055BD3C) != 0) {
        fn_8000DC28(path, slot);
    }
}

