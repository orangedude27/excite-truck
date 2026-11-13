// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __AXGetStackHead(int index) {
    extern int lbl_802ED82C[];
    return lbl_802ED82C[index];
}

int fn_8001D7EC(char *name) {
    extern char *lbl_802ED818[];
    char **table = lbl_802ED818;
    int i = 0;
    while (i < 5) {
        if (*table != 0 && strcmp(*table, name) == 0) {
            return i;
        }
        if (++i >= 5) break;
        table++;
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
    typedef char *(*GetName)(void *, char *, char *);
    typedef int (*GetValue)(void *, char *, int);
    struct Vtbl {
        void *f0, *f1, *f2, *f3, *f4, *f5;
        GetName get_name;
        void *f7;
        GetValue get_value;
    };
    struct Obj { struct Vtbl *vtable; };
    extern char *lbl_802ED818[];
    extern char lbl_802FDB44[];
    extern char lbl_802FDB54[];
    struct Obj *obj = (struct Obj *)arg1;
    char *name;
    int i;
    arg0[5] = -1;
    name = obj->vtable->get_name(arg1, lbl_802FDB44, lbl_802FDB54);
    i = 0;
    while (i < 5) {
        if (stricmp(lbl_802ED818[i], name) == 0)
            arg0[5] = i;
        i++;
    }
    if (arg0[5] == -1)
        arg0[5] = 2;
    i = 5;
    do {
        arg0[i] = obj->vtable->get_value(arg1, lbl_802ED818[i], -1);
    } while (--i >= 0);
    arg0[4] = 0;
}

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

int fn_8001DA48(int *arg0, int arg1) {
    return arg0[arg1];
}
typedef struct { int (*f0)(); int (*f1)(); int (*f2)(); int (*f3)(); int (*f4)(); int (*f5)(); int (*f6)(); int (*f7)(); int (*f8)(); } Vtbl;
typedef struct { Vtbl *vtable; } Obj;
