// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D07D;
char fn_802CA7D4(void) { return 1; }

char fn_802CA7DC(const char *arg0) { return (signed char)*arg0 == 0x2A; }

int fn_802CA7F4(const char *arg0) { return strchr(arg0, 0x2F) != 0; }

int fn_802DB2C0(int);
int fn_802CA57C(int, int, int);
int fn_802CA4E0(int, int, int, int, int);
void fn_802D8FB4(void);
extern int lbl_8055D058;
extern int lbl_8055D078;
void fn_802CB38C(int arg0, int arg1, int arg2) {
    fn_802CA57C(lbl_8055D078, 0, arg2);
    fn_802CA4E0(arg0, lbl_8055D058, 0, arg1, arg2);
}

void fn_802CB3F4(void) {
    fn_802D8FB4();
}

void fn_802CB3F8(void) {
}

extern char lbl_8055FCBC[];
extern char lbl_8055FCB0[];
extern float lbl_80564F40;
extern float lbl_80564F44;
extern float lbl_8055FCC4;
void fn_802CC550(int, float, float);
void fn_802CC73C(char arg0) {
    lbl_8055D07D = arg0;
}

char fn_802CC744(void) {
    return lbl_8055D07D;
}

int fn_802CC74C(void) {
    char *p = *(char **)lbl_8055FCBC;
    if (p == 0)
        return 0;
    if (*(int *)(p + 4) == 0)
        return 0;
    return 1;
}

extern void fn_802E317C(const char *, ...);
extern char lbl_8034B7D0[];
extern char fn_802CA7DC(const char *);
