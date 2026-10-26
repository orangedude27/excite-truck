// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9E8;
extern int fn_8012E96C(const char *);
extern int fn_802B5510(const char *);
extern int fn_8013184C(void);
extern const char lbl_8034A588[];
extern int stricmp(const char *, const char *);
extern const char lbl_8034A510[];
int fn_8012C33C(void);
int fn_802CAC28(int, int);
extern void fn_80131818(int);
extern void fn_802C6CF8(void);
struct TplLike { void *entries; unsigned int count; };
__declspec(section ".data") extern struct TplLike lbl_804BE4AC;
__declspec(section ".data") extern struct TplLike lbl_804BE454;
void* fn_802B59A4(unsigned int);

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

void fn_802B57B8(void) {
    const char *name = lbl_8034A588;
    int r = fn_8012E96C(name);
    fn_802B5510(name);
    if (lbl_8055F9E8 == 0) {
        lbl_8055F9E8 = (void *)fn_8013184C();
    }
}

#pragma cplusplus on
extern "C" void fn_802B562C(void *, void *, void *);
#pragma cplusplus on
#pragma dont_inline on
#pragma small_data off
extern "C" void fn_802B58E0(void) {
    class Obj {
    public:
        virtual void f0();
        virtual void *getItem(int);
    };
    int i;
    int offset;
    int itemIndex;
    struct TplLike *list = &lbl_804BE454;
    struct TplLike *pool = &lbl_804BE4AC;
    void *obj;
    void *item;
    unsigned int count;
    void *entries;

    i = 0;
    offset = 0;
    goto outer_test;
outer_body:
    obj = *(void **)((char *)list->entries + offset);
    itemIndex = 0;
    goto item_fetch;
item_body:
    if (fn_802B54CC(item) != 0) {
        count = pool->count;
        entries = pool->entries;
        pool->count = count + 1;
        fn_802B562C((char *)entries + count * 0x30, item, entries);
    }
    itemIndex++;
item_fetch:
    item = ((Obj *)obj)->getItem(itemIndex);
    if (item != 0)
        goto item_body;
    offset += 4;
    i++;
outer_test:
    if (i < (int)list->count)
        goto outer_body;
}
#pragma small_data reset
#pragma dont_inline off
#pragma cplusplus off

void* fn_802B59A4(unsigned int index) {
    unsigned int count = lbl_804BE4AC.count;
    char* entries = lbl_804BE4AC.entries;
    return entries + (index % count) * 0x30;
}

#pragma scheduling reset
void* fn_802B59CC(void) {
    return lbl_8055F9E8;
}

