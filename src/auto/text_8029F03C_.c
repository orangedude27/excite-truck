// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804B5070[];
extern int lbl_8055F81C;
extern unsigned char lbl_804B6E70[];
extern int fn_800241DC(int *, void *, int, int, void *);
extern int stricmp(const char *, const char *);
extern int fn_8029FDF0(int *, int *);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
int fn_8029FDF0(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

int fn_8029FE6C(const char *arg0) {
    int i;
    unsigned char *entry = lbl_804B6E70;
    for (i = 0; i < lbl_8055F81C; i++, entry += 0x24) {
        if (stricmp((const char *)entry, arg0) == 0)
            return *(int *)(entry + 0x20);
    }
    return -1;
}
