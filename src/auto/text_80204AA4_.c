// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_802F9D68[];
extern int lbl_8033BBA0;
extern int *lbl_8055ED5C;
extern int lbl_8055B468;
extern int lbl_8055B470;
extern int lbl_8055B478;
extern signed char lbl_8055ED58;
extern int stricmp(const char *, const char *);
extern void fn_802E317C(const char *, const char *);
extern void *fn_8001285C(void);
extern void fn_80131818(int);
extern void fn_80128668(void *);
#pragma dont_inline fn_80204B2C
int fn_80204B2C();
int *fn_80204AA4(void) {
    int value = *(int *)((char *)fn_8001285C() + 8);
    switch (value) {
    case 0x180302: return &lbl_8055B468;
    case 0x180201: return &lbl_8055B470;
    case 0x180303: return &lbl_8055B478;
    default: return 0;
    }
}

void *fn_80204B18(int arg0) {
    return lbl_802F9D68 + arg0 * 0xC;
}

void fn_80204BB4(void) {
    fn_80204B2C();
}

extern int *lbl_8055ED5C;
int fn_80204CF0(void) {
    return *lbl_8055ED5C;
}

extern double atof(const char *);
extern const char lbl_8055B4AC[];
extern const char lbl_8033BBF4[];
float fn_80204CFC(const char *arg0) {
    char buf[0x64];
    int result = 0;
    int value;
    int r;
    void *temp;
    void *obj;
    void **vt;
    int (*method)(void *);
    int (*method2)(void *, void *);
    int (*method3)(void *, const char *);

    temp = lbl_8055ED5C;
    if (*(int *)((char *)temp + 0x10) != 0) {
        fn_801345D8(buf, 0x64, &lbl_8055B4AC, arg0);
        obj = *(void **)((char *)temp + 0xC);
        if (obj != 0 && (*(int (**)(void *))(*(void ***)obj + 3))(buf) != 0) {
            obj = *(void **)((char *)temp + 0xC);
            result = (*(int (**)(void *, void *))(*(void ***)obj + 5))(obj, buf);
        } else {
            obj = *(void **)((char *)temp + 8);
            if ((*(int (**)(void *))(*(void ***)obj + 3))(buf) != 0) {
                result = (*(int (**)(void *, void *))(*(void ***)obj + 5))(obj, buf);
            } else result = 0;
        }
    }
    if (result == 0) {
        obj = *(void **)((char *)temp + 0xC);
        if (obj != 0 && (*(int (**)(const char *))(*(void ***)obj + 3))(arg0) != 0) {
            result = (*(int (**)(void *, const char *))(*(void ***)obj + 5))(obj, arg0);
        } else {
            obj = *(void **)((char *)temp + 8);
            if ((*(int (**)(void *, const char *))(*(void ***)obj + 3))(obj, arg0) != 0) {
                result = (*(int (**)(void *, const char *))(*(void ***)obj + 5))(obj, arg0);
            } else result = 0;
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    return (float)atof((const char *)value);
}

int fn_80204EA0(const char *arg0) {
    char buf[0x64];
    int *p;
    int result = 0;
    void **vt;
    int (*method)(void *, const char *);

    p = lbl_8055ED5C;
    if (p[4] != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (p[3] != 0) {
            vt = *(void ***)p[3];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], buf) != 0) {
                vt = *(void ***)p[3];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[3], buf);
            }
        } else {
            vt = *(void ***)p[2];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[2], buf) != 0) {
                vt = *(void ***)p[2];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[2], buf);
            } else result = 0;
        }
    }
    if (result == 0) {
        if (p[3] != 0) {
            vt = *(void ***)p[3];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], arg0) != 0) {
                vt = *(void ***)p[3];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[3], arg0);
            } else result = 0;
        } else {
            vt = *(void ***)p[2];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[2], arg0) != 0) {
                vt = *(void ***)p[2];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[2], arg0);
            } else result = 0;
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    return result;
}

extern int fn_801345D8(void *, int, const char *, const char *);
extern const char lbl_8055B4B4[];
extern const char lbl_8055B4B8[];
int fn_8020503C(const char *arg0) {
    char buf[0x64];
    int *p;
    int result = 0;
    int value;
    void **vt;
    int (*method)(void *, const char *);
    p = lbl_8055ED5C;
    if (p[4] != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (p[3] != 0) {
            vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], buf) != 0) { vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[3], buf); }
            else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], buf) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], buf); } else result = 0; }
        } else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], buf) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], buf); } else result = 0; }
    }
    if (result == 0) {
        if (p[3] != 0) {
            vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], arg0) != 0) { vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[3], arg0); }
            else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], arg0) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], arg0); } else result = 0; }
        } else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], arg0) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], arg0); } else result = 0; }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    return stricmp((const char *)value, lbl_8055B4B4) == 0 || stricmp((const char *)value, lbl_8055B4B8) == 0;
}

void fn_80205208(void) {
    int *p = lbl_8055ED5C;
    lbl_8055ED58 = 0;
    if (p != 0) {
        p[4] = 0;
        p[2] = 0;
        p[3] = 0;
        fn_80131818(p[1]);
        p[1] = 0;
        fn_80128668(p);
    }
}

extern const char lbl_8033BBE4[];
extern void *fn_80131808(const char *);
extern int fn_80012854(void);
int fn_80205268(const char *arg0, int arg1, int arg2) {
    char buf[0x64];
    void *manager;
    void *entry;
    void *current;
    int result;
    int *value;
    int valid;
    void *(*getStage)(int);
    manager = fn_80131808(lbl_8033BBE4);
    entry = fn_80204B18(arg1);
    current = (*(void *(*)(void *, int))(*(void ***)manager + 2))(manager, *(int *)((char *)entry + 8));
    valid = arg2 >= 0 && arg2 < fn_80012854();
    result = 0;
    if (valid) {
        void *candidate;
        int check;
        getStage = (void *(*)(int))fn_8001285C;
        candidate = *(void **)((char *)getStage(arg2) + 0x20);
        check = (*(int (*)(void *, int))(*(void ***)candidate + 0x5C))(candidate, *(int *)((char *)entry + 8));
        if (check != 0) value = (int *)(*(int (*)(void *, int))(*(void ***)candidate + 0x5C))(candidate, *(int *)((char *)entry + 8));
        else value = 0;
        value = ((int *(*)(int))fn_80204AA4)(arg2);
    } else value = 0;
    if (value != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (value != 0 && (*(int (**)(void *, const char *))(*(void ***)value + 3))(value, buf)) {
            result = (*(int (**)(void *, const char *))(*(void ***)value + 5))(value, buf);
        } else if ((*(int (**)(void *, const char *))(*(void ***)current + 3))(current, buf)) {
            result = (*(int (**)(void *, const char *))(*(void ***)current + 5))(current, buf);
        }
    }
    if (result == 0) {
        if (value != 0 && (*(int (**)(void *, const char *))(*(void ***)value + 3))(value, arg0)) result = (*(int (**)(void *, const char *))(*(void ***)value + 5))(value, arg0);
        else if ((*(int (**)(void *, const char *))(*(void ***)current + 3))(current, arg0)) result = (*(int (**)(void *, const char *))(*(void ***)current + 5))(current, arg0);
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    fn_80131818((int)manager);
    return result;
}

int fn_802054EC(const char *arg0, int arg1, int arg2) {
    char buf[0x64];
    void *manager;
    void *entry;
    void *sp10;
    void *sp14 = 0;
    int *sp18 = 0;
    int result = 0;
    void *(*getStage)(int);
    manager = fn_80131808(lbl_8033BBE4);
    entry = fn_80204B18(arg1);
    sp10 = (*(void *(*)(void *, int))(*(void ***)manager + 2))(manager, *(int *)((char *)entry + 8));
    if (arg2 >= 0 && arg2 < fn_80012854()) {
        void *stage;
        int check;
        getStage = (void *(*)(int))fn_8001285C;
        stage = *(void **)((char *)getStage(arg2) + 0x20);
        check = (*(int (*)(void *, int))(*(void ***)stage + 0x5C))(stage, *(int *)((char *)entry + 8));
        if ((-check | check) < 0) sp14 = (void *)(*(int (*)(void *, int))(*(void ***)stage + 0x5C))(stage, *(int *)((char *)entry + 8));
        sp18 = ((int *(*)(int))fn_80204AA4)(arg2);
    }
    if (sp18 != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (sp14 != 0 && (*(int (**)(void *, const char *))(*(void ***)sp14 + 3))(sp14, buf)) result = (*(int (**)(void *, const char *))(*(void ***)sp14 + 5))(sp14, buf);
        else if ((*(int (**)(void *, const char *))(*(void ***)sp10 + 3))(sp10, buf)) result = (*(int (**)(void *, const char *))(*(void ***)sp10 + 5))(sp10, buf);
    }
    if (result == 0) {
        if (sp14 != 0 && (*(int (**)(void *, const char *))(*(void ***)sp14 + 3))(sp14, arg0)) result = (*(int (**)(void *, const char *))(*(void ***)sp14 + 5))(sp14, arg0);
        else if ((*(int (**)(void *, const char *))(*(void ***)sp10 + 3))(sp10, arg0)) result = (*(int (**)(void *, const char *))(*(void ***)sp10 + 5))(sp10, arg0);
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    result = stricmp((const char *)result, lbl_8055B4B4) == 0 || stricmp((const char *)result, lbl_8055B4B8) == 0;
    fn_80131818(*(int *)manager);
    return result;
}

