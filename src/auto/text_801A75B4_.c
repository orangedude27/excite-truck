// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
struct Entry_801A75B4 { const char *name; char pad[20]; };
extern float fn_801A7F98(void);
extern float lbl_80562470;
extern int fn_801A8E38(void);

extern char lbl_8055E5C8;
void fn_801A7F8C(void) {
    lbl_8055E5C8 = 0;
}

int fn_801A8E38(void) {
    fn_801A7F98();
    return (fn_801A7F98(), 0);
}

int fn_801A8E68(void *arg0) {
    int state = *(int *)arg0;
    int result = 0;
    if (state >= 7)
        return 0;
    if (state < 1)
        return 0;
    if (fn_801A8E38()) {
        if (*(unsigned char *)((char *)arg0 + 0xC) == 0) {
            *(unsigned char *)((char *)arg0 + 0xC) = 1;
            result = 1;
        }
    } else {
        *(unsigned char *)((char *)arg0 + 0xC) = 0;
    }
    return result;
}

int fn_801A8EE4(unsigned int *arg0) {
    unsigned int value = *arg0 - 1;
    if (value > 5)
        return 0;
    if (((1U << value) & 0x2D) != 0)
        return 1;
    return 0;
}

extern void fn_801A7628(void);
extern void fn_801A9110(void *, const char *);
extern void *fn_801A9234(const char *);
extern void fn_801A91B0(void *, const void *);
extern int stricmp(const char *, const char *);
extern const char *lbl_802F9588[];
extern const char *lbl_8055E5CC[];
extern int lbl_8055E5D0;
extern char *strncpy(char *, const char *, unsigned int);
int fn_801A902C(void) {
    fn_801A7628();
    return 0x15;
}

void fn_801A9050(void *arg0, int arg1) {
    int zero[8] = {0};
    fn_801A9110(arg0, lbl_802F9588[arg1]);
}

void fn_801A90A4(char *arg0, int arg1, const char *arg2) {
    const char **entry = (const char **)fn_801A9234(arg2);
    if (entry != 0)
        strncpy(arg0, *entry, arg1);
    else
        arg0[0] = 0;
    arg0[arg1 - 1] = 0;
}

void fn_801A9110(void *arg0, const char *arg1) {
    int i;
    const char **table;
    fn_801A7628();
    table = lbl_8055E5CC;
    for (i = 0; i < lbl_8055E5D0; i++) {
        if (stricmp(table[i * 3], arg1) == 0) {
            fn_801A91B0(arg0, &table[i * 3]);
            return;
        }
    }
    *(int *)arg0 = 0;
}

