// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8013C7D0(void);

void fn_8013C800(void) {
    fn_8013C7D0();
}

void *fn_8013C770(void);
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
extern char lbl_80559D10[];
int stricmp(const char *, const char *);
int fn_8013C8E8(const char *arg0) {
    int i;
    int j;
    void *manager;
    void *items;
    void *entry;
    int name;
    int unused;

    for (i = 0; i < 5; i++) {
        manager = ((void *(*)())fn_8013C800)();
        items = *(void **)((char *)manager + 8);
        entry = (*(void ***)items)[0x5C / 4];
        items = ((void *(*)(void *, const char *))entry)(items, lbl_80559D10);
        for (j = 0; ; j++) {
            if (!((int (*)(void *, int, int *, int *))(*(void ***)items)[4])(items, j, &unused, &name)) break;
            if (stricmp((const char *)name, arg0) == 0) return *(int *)((char *)manager + 4);
        }
    }
    return 6;
}

int fn_8013C9A4(void) {
    return *(int *)((char *)fn_8013C770() + 4);
}

int fn_8013C9C8(void) {
    return *(int *)((int *(*)())fn_8013C800)();
}

void *fn_8013C770(void);
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
extern char lbl_80559D10[];
int stricmp(const char *, const char *);
