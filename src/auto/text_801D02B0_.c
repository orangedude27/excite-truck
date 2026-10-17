// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E8C0;
extern char lbl_80338098;
extern char lbl_802F9940;
extern char lbl_8033819C;
extern int stricmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
typedef struct { const char *name; int value; } Entry;
void fn_801D049C(void) {
    lbl_8055E8C0 = 0;
}

extern char lbl_80338098;
extern char lbl_802F9940;
extern char lbl_8033819C;
extern int stricmp(const char *, const char *);
extern int fn_802E317C(const char *, ...);
int fn_801D04D0(const char *arg0) {
    const char *names[13];
    int values[13];
    int i;
    for (i = 0; i < 13; i++) {
        names[i] = *(const char **)((char *)&lbl_802F9940 + i * 8);
        values[i] = *(int *)((char *)&lbl_802F9940 + i * 8 + 4);
    }
    for (i = 0; i < 13; i++) {
        if (stricmp(arg0, names[i]) == 0)
            return values[i];
    }
    fn_802E317C(&lbl_8033819C, arg0);
    return 100;
}

