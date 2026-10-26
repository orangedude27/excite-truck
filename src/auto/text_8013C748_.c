// Code of main that had no source file yet: decomp.wtf gave it this one.

#pragma cplusplus on
class SearchObject {
public:
    virtual const char *name();
};
class SearchManager {
public:
    virtual void v0();
    virtual SearchObject *get(int);
};
#pragma cplusplus off
// split_file divides it into the game's real files (file_status shows its range).

void fn_8013C7D0(void);

extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);

extern char lbl_8032C478[];
void fn_8013C748(void) {
    int *p = (int *)&lbl_8032C478;
    while (*p) {
        *(int *)(p + 2) = 0;
        p += 3;
    }
}

#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_8013C770(const char *arg0) {
    int *var_r31;

    var_r31 = (int *)&lbl_8032C478;
    goto loop_test;
loop_body:
    if (stricmp(arg0, (const char *)*var_r31) != 0) {
        goto loop_next;
    }
    goto done;
loop_next:
    var_r31 += 3;
loop_test:
    if (*var_r31 != 0) {
        goto loop_body;
    }
done:
    return var_r31;
}
#pragma scheduling on
#pragma dont_inline off

void fn_8013C800(void) {
    fn_8013C7D0();
}

extern int fn_80131808(int);
extern void fn_802E317C(int, ...);
extern char lbl_8032C4C0[];
extern char lbl_8032C4D0[];
#pragma cplusplus on
extern "C" int fn_80131808(int);
extern "C" void fn_802E317C(int, ...);
extern "C" void fn_8013C748(void);
extern "C" void *fn_8013C770(const char *);
extern "C" char lbl_8032C4C0[];
extern "C" char lbl_8032C4D0[];
extern "C" int lbl_8055E188;
#pragma dont_inline on
extern "C" void fn_8013C804(void) {
    SearchObject *object;
    const char *name;
    void *entry;
    int index;

    fn_8013C748();
    lbl_8055E188 = fn_80131808((int)lbl_8032C4C0);
    if (lbl_8055E188 != 0) {
        index = 0;
        goto get_object;
    }
    goto report_error;
loop_body:
    name = object->name();
    entry = fn_8013C770(name);
    if (*(int *)((char *)entry + 4) != 6) {
        *(void **)((char *)entry + 8) = object;
    }
    index += 1;
get_object:
    object = ((SearchManager *)lbl_8055E188)->get(index);
    if (object != 0) {
        goto loop_body;
    }
    return;
report_error:
    fn_802E317C((int)lbl_8032C4D0);
}
#pragma dont_inline off
#pragma cplusplus off

#pragma inline off
void fn_8013C8B8(void) {
    fn_8013C748();
    fn_80131818(lbl_8055E188);
    lbl_8055E188 = 0;
}
#pragma inline auto
void *fn_8013C770();
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
__declspec(section ".sdata") extern char lbl_80559D10[];
int stricmp(const char *, const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_8013C8E8(const char *arg0) {
    class SearchResult {
    public:
        virtual void v0();
        virtual void v1();
        virtual int query(int, int *, const char **) volatile;
    };
    class SearchHead {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual SearchResult *get(const char *);
    };
    int i;
    SearchResult *result;
    int j;
    int unused;
    const char *name;
    void *manager;

    i = 0;
    do {
        manager = ((void *(*)(int))fn_8013C800)(i);
        result = ((SearchHead *)*(void **)((char *)manager + 8))->get(lbl_80559D10);
        j = 0;
        do {
            if (stricmp(name, arg0) == 0)
                return *(int *)((char *)manager + 4);
        } while (result->query(++j, &unused, &name) != 0);
        i++;
    } while (i < 5);
    return 6;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
int fn_8013C9A4(void) {
    return *(int *)((char *)fn_8013C770() + 4);
}

int fn_8013C9C8(void) {
    return *(int *)((int *(*)())fn_8013C800)();
}

void *fn_8013C770();
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
extern char lbl_80559D10[];
int stricmp(const char *, const char *);
