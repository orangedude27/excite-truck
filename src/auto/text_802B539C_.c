// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9E8;
extern int stricmp(const char *, const char *);
extern const char lbl_8034A510[];
int fn_8012C33C(void);
int fn_802CAC28(int, int);
extern struct TplLike lbl_804BE4AC;
extern struct TplLike lbl_804BE454;
extern void fn_80131818(int);
extern void fn_802C6CF8(void);
int fn_802B539C(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802B5404(int *arg0) { int temp = *arg0; if (temp != -2) { fn_802CAC54(temp); *arg0 = -2; } }

__declspec(section ".sdata") extern const char lbl_8055CE10[];
#pragma push
#pragma cplusplus on
extern "C" int fn_802B5448(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&lbl_8055CE10, ((Obj *)arg0)->getName()) == 0;
}
#pragma cplusplus on
extern "C" int fn_802B5488(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp(lbl_8034A510, ((Obj *)arg0)->getName()) == 0;
}
extern const char lbl_8034A524[];
extern "C" int fn_802B54CC(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp(lbl_8034A524, ((Obj *)arg0)->getName()) == 0;
}
#pragma cplusplus off

#pragma scheduling invalid_target
void fn_802B561C(void (*fn)(void *), void *arg0) {
    fn(arg0);
}
#pragma scheduling reset
void* fn_802B59CC(void) {
    return lbl_8055F9E8;
}
extern int stricmp(const char *, const char *);
extern const char lbl_8034A510[];
extern int fn_8012E96C(const char *);
extern int fn_802B5510(const char *);
extern int fn_8013184C(void);
extern const char lbl_8034A588[];
struct TplLike { void *entries; unsigned int count; };
extern struct TplLike lbl_804BE4AC;
extern struct TplLike lbl_804BE454;
extern struct TplLike lbl_804BE4AC;
