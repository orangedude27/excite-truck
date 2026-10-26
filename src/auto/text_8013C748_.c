// Code of main that had no source file yet: decomp.wtf gave it this one.
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

void fn_8013C800(void) {
    fn_8013C7D0();
}

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

void *fn_8013C770(void);
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
extern char lbl_80559D10[];
int stricmp(const char *, const char *);
