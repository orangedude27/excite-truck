// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __AXGetStackHead(int index) {
    /* Return the AX stack-head pointer registered at the given context index (a 5-entry table filled at runtime). */
    extern int lbl_802ED82C[];
    return lbl_802ED82C[index];
}

int strcmp(const char *, const char *);
int fn_8001D7EC(char *name) {
    extern char *lbl_802ED818[];
    char **table = lbl_802ED818;
    int i = 0;
    do {
        if ((*table != 0) && (strcmp(*table, name) == 0)) return i;
        ++i;
        ++table;
    } while (i < 5);
    return -1;
}
void fn_8001D868(int *effectData) {
    /* Initialize the effect's 5-entry data block to -1 (no-entry sentinel). */
    effectData[0] = -1;
    effectData[1] = -1;
    effectData[2] = -1;
    effectData[3] = -1;
    effectData[4] = -1;
}

/* Fill an info array from a handle via fn_8001D8B4 and return the array pointer. */
int *fn_8001D884(int *values, void *handle) {
    extern void fn_8001D8B4();
    fn_8001D8B4(values, handle);
    return values;
}

int stricmp(const char *, const char *);
#pragma opt_unroll_loops off
void fn_8001D8B4(int *arg0, void *arg1, int arg2) {
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
    struct Obj { void **vtable; };
    extern char *lbl_802ED818[];
    extern char lbl_802FDB44[];
    extern char lbl_802FDB54[];
    struct Obj *obj = (struct Obj *)arg1;
    register int i;
    char *name;

    arg0[5] = -1;
    name = ((char *(*)(void *, char *, char *))obj->vtable[6])(
        arg1, lbl_802FDB44, lbl_802FDB54);
    for (i = 0; i < 5; i++) {
        if (stricmp(lbl_802ED818[i], name) == 0)
            arg0[5] = i;
    }
    if (arg0[5] == -1)
        arg0[5] = 2;
    {
        int j = 6;
        int *dst = &arg0[5];
        char **src = &lbl_802ED818[5];
        while (j-- > 0) {
            *dst = ((int (*)(void *, char *, int))obj->vtable[8])(
                arg1, *src, -1);
            dst--;
            src--;
        }
    }
    arg0[4] = 0;
}
#pragma opt_unroll_loops reset
/* Return index of first element in 5-value array within [0, maxValue], or -1 if none. */
int fn_8001D9B4(int *values, int maxValue) {
    int value;

    value = values[0];
    if (value >= 0 && value <= maxValue) {
        return 0;
    }
    value = values[1];
    if (value >= 0 && value <= maxValue) {
        return 1;
    }
    value = values[2];
    if (value >= 0 && value <= maxValue) {
        return 2;
    }
    value = values[3];
    if (value >= 0 && value <= maxValue) {
        return 3;
    }
    value = values[4];
    if (value >= 0 && value <= maxValue) {
        return 4;
    }
    return -1;
}

int fn_8001DA48(int *values, int index) {
    /* Return the element at index of an int array (e.g. the 5-entry effect data block). */
    return values[index];
}
typedef struct { int (*f0)(); int (*f1)(); int (*f2)(); int (*f3)(); int (*f4)(); int (*f5)(); int (*f6)(); int (*f7)(); int (*f8)(); } Vtbl;
typedef struct { Vtbl *vtable; } Obj;
