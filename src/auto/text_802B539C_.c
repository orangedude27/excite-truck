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
/* UMat ("unified material") resource lists: an array of `count` entries.
 * lbl_804BE454 holds the archives fn_802B5510 opened (umat.val and the
 * "include" archives it pulls in); lbl_804BE4AC holds the
 * "unified_material_set" items fn_802B58E0 collected out of them. */
struct UMatList { void *entries; unsigned int count; };
#define TplLike UMatList /* old placeholder name, still used below */
#define UMatArchives   lbl_804BE454 /* struct UMatList of archive managers */
#define UMatSetList    lbl_804BE4AC /* struct UMatList of material sets */
#define sGlobalParameters lbl_8055F9E8 /* the archive's "global_parameters" item */

/* One "unified_material_set" item, filled in by fn_802B562C. */
struct UMatSet {
    const char *name;   /* 0x00: the set's own "name" */
    void *texList;      /* 0x04: texture list of that name */
    int w08;            /* 0x08: id of that name */
    struct {            /* 0x0C: "ground_tex_params", then "road_tex1".."road_tex3" */
        void *item;     /*       the texture item taken from the archive */
        int load;       /*       its texture load handle, -2 when there is none */
    } tex[4];
    int modelId;        /* 0x2C: model built from those textures, -1 when none */
};                      /* 0x30 bytes */

__declspec(section ".data") extern struct UMatList lbl_804BE4AC;
__declspec(section ".data") extern struct UMatList lbl_804BE454;
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
__declspec(section ".sdata") extern const char lbl_8055CE18[];
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" int fn_802B5510(const char *resourcePath) {
    /* Load a resource manager/list for the given path, register it, and recursively process/load referenced entries. */
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
    struct UMatList *list;
    void **entries;
    unsigned int count;
    void *item;
    int index;

    manager = (Manager *)((void *(*)(void (*)(void *), void *))fn_802B561C)(
        (void (*)(void *))fn_80131810, (void *)resourcePath);
    if (manager == 0)
        goto report_error;
    list = &lbl_804BE454;
    entries = (void **)lbl_804BE454.entries;
    count = list->count++;
    index = 0;
    entries[count] = manager;
    goto fetch_item;

process_item:
    if (fn_802B5448(item) != 0) {
        fn_802B5510(((Item *)item)->process(lbl_8055CE18));
    } else if (fn_802B5488(item) != 0 && lbl_8055F9E8 == 0) {
        lbl_8055F9E8 = item;
    }
    index++;

fetch_item:
    item = manager->get(index);
    if (item != 0)
        goto process_item;
    return;

report_error:
    fn_802E317C(lbl_8034A53C, resourcePath);
}

#pragma scheduling invalid_target
void fn_802B561C(void (*fn)(void *), void *arg0) {
    fn(arg0);
}

extern "C" void fn_802B0B20(void *, void *);
extern "C" void fn_802B224C(void *);
extern "C" void *fn_802B1138(const char *);
extern "C" int fn_802B2C98(char *);
extern "C" void fn_801345D8(char *, int, const char *, ...);
extern "C" int fn_802B110C(int (*)(int), int);
extern "C" int fn_802B2C34(void *, void *);
extern "C" int fn_802C6DC4(void *, int, int, int);
extern "C" int fn_802B539C(int);
extern "C" void *fn_802C6B44(void *);
extern const char lbl_8055CE20[];
__declspec(section ".sdata") extern const char lbl_8055CE20[];
extern "C" void fn_802B562C(void *arg0, void *arg1, void *arg2) {
    class Manager {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void *getName(const char *);
        virtual void *getNamed(const char *, void *);
        virtual void *f5();
        virtual void *f6();
        virtual void *f7();
        virtual void *f8();
        virtual void *f9();
        virtual void *f10();
        virtual void *f11();
        virtual void *f12();
        virtual void *f13();
        virtual void *f14();
        virtual void *f15();
        virtual void *f16();
        virtual void *f17();
        virtual void *f18();
        virtual void *f19();
        virtual void *f20();
        virtual void *getLarge(const char *);
    };
    char nameBuffer[0x20];
    register const char *labels;
    register char *entry;
    register void *name;
    register int i;
    register Manager *manager;
    register void *loopItem;
    register int result;

    manager = (Manager *)arg1;
    labels = lbl_8034A510;
    *(void **)arg0 = manager->getName(lbl_8055CE18);
    loopItem = manager->getLarge(labels + 0x40);
    fn_802B0B20(manager, loopItem);
    fn_802B224C(manager);
    *(void **)((char *)arg0 + 4) = fn_802B1138(*(const char **)arg0);
    *(int *)((char *)arg0 + 8) = fn_802B2C98(*(char **)arg0);
    name = manager->getNamed(labels + 0x54, (void *)lbl_8055CE20);

    entry = (char *)arg0;
    i = 0;
    do {
        fn_801345D8(nameBuffer, 0x20, labels + 0x60, i + 1);
        loopItem = manager->getNamed(nameBuffer, name);
        *(void **)(entry + 0xC) = loopItem;
        result = fn_802B110C((int (*)(int))fn_802B539C, (int)loopItem);
        *(int *)(entry + 0x10) = result;
        i++;
        entry += 8;
    } while (i < 4);

    i = (int)manager->getNamed(labels + 0x6C, 0);
    if (i != 0) {
        result = fn_802B2C34(fn_802C6B44, (void *)i);
    } else {
        result = 0;
    }
    if (result != 0) {
        *(int *)((char *)arg0 + 0x2C) = fn_802C6DC4((void *)i, result, 0, 0);
    } else {
        *(int *)((char *)arg0 + 0x2C) = -1;
    }
}

extern "C" void fn_802B57B8(void) {
    int name;
    name = (int)lbl_8034A588;
    fn_8012E96C((const char *)name);
    fn_802B5510((const char *)name);
    if (lbl_8055F9E8 == 0) {
        lbl_8055F9E8 = (void *)fn_8013184C();
    }
}

#pragma cplusplus on
#pragma dont_inline on
#pragma use_lmw_stmw off
/* fn_802B5808 - UMat shutdown: hands back everything the module loaded.
 * Every material set gets its four ground/road texture loads released (each
 * marked -2 so nothing frees them twice) and its model freed; then every
 * archive fn_802B5510 opened is deleted and the two lists and the
 * "global_parameters" item are cleared ready for the next load. */
extern "C" void fn_802B5808(int arg0) {
    register int set;
    register int offset;
    register int texSlot;
    register int setIndex;
    register int texIndex;
    register int archiveIndex;
    register int modelId;

    setIndex = 0;
    offset = 0;
    goto set_loop;
set_loop_body:
    texIndex = 0;
    set = (int)UMatSetList.entries + offset;
    texSlot = set + 0x10; /* &((struct UMatSet *)set)->tex[0].load */
    do {
        fn_802B5404((int *)texSlot);
        texIndex += 1;
        texSlot += 8;
    } while (texIndex < 4);
    modelId = ((struct UMatSet *)set)->modelId;
    if (modelId != -1) {
        ((void (*)(int))fn_802C6CF8)(modelId);
    }
    offset += 0x30;
    setIndex += 1;
set_loop:
    if (setIndex < (int)UMatSetList.count) {
        goto set_loop_body;
    }

    archiveIndex = 0;
    offset = 0;
    goto archive_loop;
archive_loop_body:
    fn_80131818(*(int *)((char *)UMatArchives.entries + offset));
    offset += 4;
    archiveIndex += 1;
archive_loop:
    if (archiveIndex < (int)UMatArchives.count) {
        goto archive_loop_body;
    }
    UMatArchives.count = 0;
    UMatSetList.count = 0;
    sGlobalParameters = 0;
}
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
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma use_lmw_stmw off
