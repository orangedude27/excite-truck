// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B38;

void fn_801D9F24(void) {
    fn_8012C4D8();
}

void fn_801D9F28(void *arg0) {
    *(float *)((char *)arg0 + 0xC) = lbl_80562B38;
    *(int *)((char *)arg0) = 0;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
}

extern int fn_80128668(void);
extern float lbl_80562B38;
extern int strcmp(const char *, const char *);
int fn_801D9F44(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801D9F84(void *arg0, int *arg1) {
    *(float *)((char *)arg0 + 0xC) = lbl_80562B38;
    *(int *)((char *)arg0 + 8) = 0;
    *(int **)((char *)arg0) = arg1;
    if (arg1 != 0 && *arg1 > 0) {
        *(int *)((char *)arg0 + 4) = (int)(arg1 + 1);
    } else {
        *(int *)((char *)arg0 + 4) = 0;
    }
}

int fn_801D9FC4(char **arg0, const char *arg1) {
    char *base = *arg0;
    int count = *(int *)base;
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(base + i * 0x18 + 4, arg1) == 0) {
            return 1;
        }
    }
    return 0;
}

void *fn_801DA03C(int **arg0, int arg1) {
    int *base = *arg0;
    if (arg1 < *base) {
        return (char *)base + arg1 * 0x18 + 4;
    }
    return 0;
}

