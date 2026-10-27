// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9E8;
extern int fn_8012E96C(const char *);
extern int fn_802B5510(const char *);
extern int fn_8013184C(void);
extern const char lbl_8034A588[];
extern int stricmp(const char *, const char *);
#pragma cplusplus on
extern "C" void fn_80131810(int);
extern "C" void fn_802E317C(const char *, ...);
#pragma cplusplus off
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
#pragma dont_inline on
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

extern "C" void fn_802B561C(void (*)(void *), void *);
extern "C" int fn_802B5448(void *);
extern "C" int fn_802B5488(void *);
extern void fn_80131810(int);
extern const char lbl_8055CE18[];
extern const char lbl_8034A53C[];
extern void fn_802E317C(const char *, ...);
extern "C" void fn_80131810(int);
extern "C" void fn_802E317C(const char *, ...);
extern "C" int fn_802B5510(const char *arg0) {
    class Manager {
    public:
        virtual void f0();
        virtual void *get(int);
    };
    class Item {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual const char *process(const char *);
    };
    Manager *manager;
    void **entries;
    unsigned int count;
    int index;
    void *item;

    manager = (Manager *)((void *(*)(void (*)(void *), void *))fn_802B561C)(
        (void (*)(void *))fn_80131810, (void *)arg0);
    if (manager != 0) {
        count = lbl_804BE454.count;
        entries = (void **)lbl_804BE454.entries;
        lbl_804BE454.count = count + 1;
        entries[count] = manager;
        index = 0;
        goto fetch_item;
    }
    fn_802E317C(lbl_8034A53C, arg0);
    return 0;

process_item:
    if (fn_802B5448(item) != 0) {
        fn_802B5510(((Item *)item)->process(lbl_8055CE18));
    } else if (fn_802B5488(item) != 0 && lbl_8055F9E8 == 0) {
        lbl_8055F9E8 = item;
    }
    index++;

fetch_item:
    item = manager->get(index);
    if (item != 0) {
        goto process_item;
    }
    return 0;
}
#pragma dont_inline off
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
#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" void fn_802B5808(int arg0) {
    register int var_r28;
    register int var_r29;
    register int var_r27;
    register int var_r26;
    register int var_r25;
    register int var_r25_2;
    register int status;

    var_r26 = 0;
    var_r29 = 0;
    goto loop_6;
loop_6_body:
    var_r25 = 0;
    var_r28 = (int)lbl_804BE4AC.entries + var_r29;
    var_r27 = var_r28 + 0x10;
    do {
        fn_802B5404((int *)var_r27);
        var_r25 += 1;
        var_r27 += 8;
    } while (var_r25 < 4);
    status = *(int *)(var_r28 + 0x2C);
    if (status != -1) {
        ((void (*)(int))fn_802C6CF8)(status);
    }
    var_r29 += 0x30;
    var_r26 += 1;
loop_6:
    if (var_r26 < (int)lbl_804BE4AC.count) {
        goto loop_6_body;
    }

    var_r25_2 = 0;
    var_r29 = 0;
    goto loop_9;
loop_9_body:
    fn_80131818(*(int *)((char *)lbl_804BE454.entries + var_r29));
    var_r29 += 4;
    var_r25_2 += 1;
loop_9:
    if (var_r25_2 < (int)lbl_804BE454.count) {
        goto loop_9_body;
    }
    lbl_804BE454.count = 0;
    lbl_804BE4AC.count = 0;
    lbl_8055F9E8 = 0;
}
#pragma dont_inline off
#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_802B562C(void *, void *, void *);
#pragma cplusplus on
#pragma dont_inline on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_802B58E0(void) {
    class Obj {
    public:
        virtual void f0();
        virtual void *getItem(int);
    };
    int offset;
    int i;
    void *obj;
    void *item;
    int itemIndex;
    unsigned int count;
    void *entries;

    i = 0;
    offset = 0;
    goto outer_test;
outer_body:
    obj = *(void **)((char *)lbl_804BE454.entries + offset);
    itemIndex = 0;
    goto item_fetch;
item_body:
    if (fn_802B54CC(item) != 0) {
        count = lbl_804BE4AC.count;
        entries = lbl_804BE4AC.entries;
        lbl_804BE4AC.count = count + 1;
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
    if (i < (int)lbl_804BE454.count)
        goto outer_body;
}
#pragma pop
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
#pragma cplusplus on
#pragma dont_inline on
#pragma use_lmw_stmw off
