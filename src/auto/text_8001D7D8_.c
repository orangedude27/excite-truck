// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __AXGetStackHead(int index) {
    extern int lbl_802ED82C[];
    return lbl_802ED82C[index];
}

int fn_8001D7EC(char *name) {
    extern char *lbl_802ED818[];
    int i;
    for (i = 0; i < 5; i++) {
        if (lbl_802ED818[i] != 0 && strcmp(lbl_802ED818[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void fn_8001D868(int *values) {
    values[0] = -1;
    values[1] = -1;
    values[2] = -1;
    values[3] = -1;
    values[4] = -1;
}

int fn_8001D884(int arg0) {
    extern void fn_8001D8B4();
    fn_8001D8B4(arg0);
    return arg0;
}

int stricmp(const char *, const char *);
void fn_8001D8B4(int *arg0, void *arg1, int arg2) {
    extern char *lbl_802ED818[];
    extern char lbl_802FDB44[];
    extern char lbl_802FDB54[];
    int i;
    void **vtable;
    char *name;
    int (*get_name)(void *, char *, char *);
    int (*get_value)(void *, int, int);

    arg0[5] = -1;
    vtable = *(void ***)arg1;
    get_name = (int (*)(void *, char *, char *))vtable[6];
    name = (char *)get_name(arg1, lbl_802FDB44, lbl_802FDB54);
    for (i = 0; i < 5; i++) {
        if (stricmp(lbl_802ED818[i], name) == 0) {
            arg0[5] = i;
        }
    }
    if (arg0[5] == -1) {
        arg0[5] = 2;
    }
    get_value = (int (*)(void *, int, int))vtable[8];
    for (i = 5; i >= 0; i--) {
        arg0[i + 4] = get_value(arg1, (int)lbl_802ED818[i], -1);
    }
    arg0[4] = 0;
}

int fn_8001D9B4(int *arg0, int arg1) {
    int value;

    value = arg0[0];
    if (value >= 0 && value <= arg1) {
        return 0;
    }
    value = arg0[1];
    if (value >= 0 && value <= arg1) {
        return 1;
    }
    value = arg0[2];
    if (value >= 0 && value <= arg1) {
        return 2;
    }
    value = arg0[3];
    if (value >= 0 && value <= arg1) {
        return 3;
    }
    value = arg0[4];
    if (value >= 0 && value <= arg1) {
        return 4;
    }
    return -1;
}

int fn_8001DA48(int *arg0, int arg1) {
    return arg0[arg1];
}
typedef struct { int (*f0)(); int (*f1)(); int (*f2)(); int (*f3)(); int (*f4)(); int (*f5)(); int (*f6)(); int (*f7)(); int (*f8)(); } Vtbl;
typedef struct { Vtbl *vtable; } Obj;
