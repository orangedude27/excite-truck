// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_80559C00;
extern void *lbl_8042F788[4];
extern int lbl_8042F798[4];
extern int fn_800167F4(void);
void fn_80137C84(int, int);
extern unsigned char lbl_8055E0E0;
extern void fn_80128668(void*);
extern void fn_802E317C(const char*, ...);
extern char lbl_8032BEE4[];
extern char lbl_8032BEC0[];
extern char lbl_8032BECC[];
extern int lbl_80559C04;
extern int lbl_80559C08;
extern int lbl_80559C10;
char *fn_80137950(int arg0) {
    char *s;
    switch (arg0) {
        case 3:
            return (char *)&lbl_80559C04;
        case 1:
            return lbl_8032BEC0;
        case 2:
            return (char *)&lbl_80559C08;
        case 0:
            return (char *)&lbl_80559C10;
        default:
            s = lbl_8032BECC;
            fn_802E317C(s, arg0);
            return (char *)0;
    }
}

#pragma push
#pragma scheduling invalid_target
int fn_801379CC(void) {
    if ((int)lbl_80559C00 == -1) {
        fn_802E317C(lbl_8032BEE4);
    }
    return (int)lbl_8042F788[(int)lbl_80559C00];
}
#pragma pop
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int sprintf(char *, const char *, ...);
extern int stricmp(const char *, const char *);
extern char lbl_80559C18, lbl_80559C20, lbl_80559C28, lbl_80559C30;
#pragma inline_depth(0)
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80137A18(void) {
    struct ListDummy { virtual void v0(); virtual void *get(int); };
    struct ItemDummy {
        virtual const char *getName();
        virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6();
        virtual float getF(const char *);
    };
    char name[0x100];
    char *result = (char *)fn_801379CC();
    void *list;
    int index;
    void *item;
    const char *item_name;
    sprintf(name, (const char *)(void *)&lbl_80559C18, result + 8);
    list = fn_80131808(name);
    index = 0;
    for (;;) {
        item = ((ListDummy *)list)->get(index++);
        if (item == 0)
            break;
        item_name = ((ItemDummy *)item)->getName();
        if (stricmp(item_name, (const char *)(void *)&lbl_80559C20) == 0) {
            *(float *)result = ((ItemDummy *)item)->getF((const char *)(void *)&lbl_80559C28);
            *(float *)(result + 4) = ((ItemDummy *)item)->getF((const char *)(void *)&lbl_80559C30);
        }
    }
    fn_80131818(list);
}
#pragma cplusplus reset
#pragma scheduling on
void fn_80137B0C(void* hi) {
    lbl_80559C00 = hi;
}

void fn_80137B14(void) {
    lbl_80559C00 = (void*)-1;
}

__declspec(section ".sdata") extern char lbl_80559C38[];
extern void *fn_801284F8(int, const char *);
extern char *fn_80137950(int);
extern void fn_80137B0C(void *);
extern int fn_801379CC(void);
extern void fn_80137A18(void);
extern void fn_80137B14(void);
extern void *memset(void *, int, unsigned long);
extern char *strcpy(char *, const char *);
#pragma use_lmw_stmw off
void fn_80137B20(void) {
    int *q = lbl_8042F798;
    int four = 4;
    void **pp = lbl_8042F788;
    int i = 0;
    lbl_8055E0E0 = 1;
    lbl_80559C00 = (void *)-1;
    do {
        *pp = fn_801284F8(0x28, lbl_80559C38);
        memset(*pp, 0, 0x28);
        strcpy((char *)*pp + 8, fn_80137950(i));
        fn_80137B0C((void *)i);
        fn_801379CC();
        lbl_8042F798[0] = four;
        q[1] = four;
        q[2] = four;
        q[3] = four;
        fn_80137A18();
        fn_80137B14();
        i++;
        pp++;
    } while (i < 4);
    fn_80137B0C((void *)0);
}
void fn_80137BE4(void) {
    void **p = lbl_8042F788;
    int i = 0;
    do {
        fn_80128668(*p);
        i++;
        *p = 0;
        p++;
    } while (i < 4);
    lbl_8055E0E0 = 0;
}

void* fn_80137C4C(void) {
    return lbl_80559C00;
}

void* fn_80137C54(int index) {
    if (index == -1) {
        index = (int)lbl_80559C00;
    }
    return lbl_8042F788[index];
}

void fn_80137C74(void) {
    fn_800167F4();
}

void fn_80137C78(void) {
    fn_800167FC();
}

void fn_80137C7C(void) {
    fn_8001683C();
}

void fn_80137C80(void) {
    fn_80016A44();
}

void fn_80137C84(int arg0, int arg1) {
    lbl_8042F798[arg1] = arg1;
}

int fn_80137C98(int value) {
    int count = fn_800167F4();
    int i;
    for (i = 0; i < count; i++) {
        if (value == lbl_8042F798[i])
            return i;
    }
    return -1;
}

int __AXGetStackHead_80137CFC(int index) { return lbl_8042F798[index]; }

#pragma dont_inline fn_80137C84
void fn_80137D10(void) {
    int i = 0;
    do {
        fn_80137C84(i, i);
        i++;
    } while (i < 4);
}

