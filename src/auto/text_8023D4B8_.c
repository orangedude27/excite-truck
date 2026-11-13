  // Code of main that had no source file yet: decomp.wtf gave it this one.
  // split_file divides it into the game's real files (file_status shows its range).
  
  typedef signed int s32;
extern void fn_8013358C(int, int, void *);
extern void fn_801A7974(const char *, int, int);
extern int lbl_8055BC08;
extern char lbl_802FA218[];
extern char lbl_80341B8C[];
extern void fn_8023E33C(void *);
extern void *lbl_8055F190;
extern int lbl_8055F194;
extern void fn_8023E16C(void *, int);
extern void fn_8023E0DC(void *, int, int);
extern void *lbl_8055F19C;
extern void *lbl_8055F190;
extern void fn_8023DA64(void *, int, int);
extern void fn_8023E1FC(void *);
  extern void *lbl_8055F18C;
  extern s32 fn_8023DD4C(void);
  extern char lbl_802FA190[];
  extern s32 stricmp(const char *, const char *);
  extern char lbl_802FA0A8[];
  extern char lbl_80341B9C[];
  extern s32 fn_802E317C(const char *, ...);
  extern char *lbl_8055BBA0;
  extern void fn_801A7E54(void *, s32, void *);
extern void fn_8022D76C();
extern void fn_8017EBE0(void);
extern void fn_8017EC30(void);
extern void fn_8022D7C4(void *, int);
extern int fn_802E85B8(int, void *, int, int, void *, int, void *, int);
extern int fn_8000DA10(void);
extern int fn_8000DB34(void);
extern int lbl_8055BC58;
extern int lbl_8055BC60;
extern int lbl_802FA258[];
extern char lbl_803419EC[];
extern char lbl_80341A00[];
typedef struct Rec_8023D4B8 {
    void *name;
    int type;
    void *arg;
    int x;
    int id;
} Rec_8023D4B8;
extern int fn_8023DD80(void);
extern int fn_8023DFB0(void);
extern int fn_8023DFD4(void);
extern int fn_8023E028(void);
extern void *fn_8023E078(void *, int);
extern void *lbl_8055F198;
extern int lbl_804987B8[];
extern int lbl_8055B860;
extern int fn_8018108C(void);
extern int fn_80137C98(int);
extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern void fn_8023DB68(void);
extern void fn_8023DBCC(void);
extern void fn_8022D894(void *, int, int, long, int);
#pragma use_lmw_stmw off
void fn_8023D4B8(int arg0) {
    int ctx[14];
    Rec_8023D4B8 recs[10];
    int tbl[5];
    int i;
    int r7;
    lbl_8055F19C = (void *)arg0;
    fn_8023DB68();
    fn_80137C78(1);
    fn_80137C84(arg0, 0);
    fn_8017EBE0();
    fn_80137C98(arg0);
    lbl_8055F198 = (void *)fn_8018108C();
    fn_8023E078(ctx, arg0);
    lbl_8055F190 = ctx;
    recs[0].name = &lbl_8055BC58; recs[0].type = 0xD; recs[0].arg = ctx; recs[0].x = 0; recs[0].id = 0;
    recs[1].name = &lbl_8055BC60; recs[1].type = 0xD; recs[1].arg = ctx; recs[1].x = 1; recs[1].id = 0;
    recs[2].name = &lbl_8055B860; recs[2].type = 6; recs[2].arg = (void *)fn_8023E028; recs[2].x = 0; recs[2].id = 0x128;
    recs[3].name = &lbl_8055B860; recs[3].type = 6; recs[3].arg = (void *)fn_8023DFD4; recs[3].x = 0; recs[3].id = 0x126;
    recs[4].name = &lbl_8055B860; recs[4].type = 6; recs[4].arg = (void *)fn_8023DD80; recs[4].x = 0; recs[4].id = 0xD;
    recs[5].name = &lbl_8055B860; recs[5].type = 6; recs[5].arg = 0; recs[5].x = -1; recs[5].id = 0x1B;
    recs[6].name = &lbl_8055B860; recs[6].type = 6; recs[6].arg = (void *)fn_8023DFB0; recs[6].x = 0; recs[6].id = 0x6F;
    r7 = fn_802E85B8(arg0, (void *)fn_8023DFB0, 0x1B, -1, (void *)fn_8023DD80, 0x126, (void *)fn_8023DFD4, 0x128);
    recs[7].name = lbl_803419EC; recs[7].type = 3; recs[7].arg = (void *)r7; recs[7].x = 0; recs[7].id = 0;
    fn_8000DA10();
    recs[8].name = lbl_80341A00; recs[8].type = 3; recs[8].arg = (void *)fn_8000DB34(); recs[8].x = 0; recs[8].id = 0;
    recs[9] = *(Rec_8023D4B8 *)lbl_804987B8;
    tbl[0] = lbl_802FA258[0];
    tbl[1] = lbl_802FA258[1];
    tbl[2] = lbl_802FA258[2];
    tbl[3] = lbl_802FA258[3];
    tbl[4] = lbl_802FA258[4];
    tbl[1] = (int)recs;
    lbl_8055F194 = 0;
    ((void (*)(void *, int, int, int, int, int, int, int))fn_8023E0DC)(lbl_8055F190, 0, tbl[4], tbl[3], tbl[2], tbl[0], lbl_804987B8[4], lbl_804987B8[3]);
    ((int (*)(int *, int, int, int))fn_802146BC)(tbl, -0x3E7, -0x3E7, 1);
    fn_8017EC30();
    fn_8023DBCC();
    fn_8022D7C4(ctx, 0);
}
void* fn_8023D6FC(void) {
    return lbl_8055F18C;
}

extern void fn_801333E8(long, void *, char *);
extern void fn_80133460(void);
extern long fn_80137C74(void);
extern unsigned long __AXGetStackHead_80137CFC(long);
extern char lbl_803416A8[0x400];
extern long lbl_8055BC54;
extern long lbl_804987D0[];
void fn_8023D704(long arg0) {
    lbl_8055F18C = (void *)arg0;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8023D70C(void) {
    /* Initialize five menu option byte fields (offsets 0x368,0x378,0x38C,0x3A0,0x3B0) to defaults over five entries. */
    register long valueSize;
    register char *optionBase = lbl_803416A8;
    register long index = 0;
    char value368;
    char value378;
    char value38C;
    char value3A0;
    char value3B0;

    do {
        valueSize = 0x10;
        if (index < 4)
            valueSize = index + 0xC;
        value368 = 1;
        value378 = 1;
        value38C = 0;
        value3A0 = 0;
        value3B0 = 1;
        fn_801333E8(valueSize, optionBase + 0x368, &value368);
        fn_801333E8(valueSize, optionBase + 0x378, &value378);
        fn_801333E8(valueSize, optionBase + 0x38C, &value38C);
        fn_801333E8(valueSize, optionBase + 0x3A0, &value3A0);
        fn_801333E8(valueSize, optionBase + 0x3B0, &value3B0);
        index++;
    } while (index < 5);
}
#pragma scheduling on
#pragma use_lmw_stmw on
#pragma dont_inline on
void fn_8023DA2C(long arg0, void *arg1, char arg2, long arg3) {
    char sp8;
    sp8 = arg2;
    if (arg3 != 0) {
        fn_80133460();
        return;
    }
    fn_801333E8(arg0, arg1, &sp8);
}

extern char *fn_8023DCCC(char *);
#pragma use_lmw_stmw off
void fn_8023DA64(void *context, int skipLookup, int flag) {
    /* Applies name/value entries from two tables into a target object, then finalizes a field. */
    typedef struct { int unk0; char *name; } Entry;
    struct StackLocals { int sp8; int spC; char pad[4]; char sp14; };
    volatile struct StackLocals locals;
    register int zero = 0;
    Entry *entry;
    char *targetBase;
    int index;
    int secondIndex;
    void *foundEntry;

    locals.spC = (int)context;
    locals.sp14 = (char)zero;
    targetBase = (char *)context + 8;
    entry = (Entry *)lbl_802FA0A8;
    index = 0;
    do {
        foundEntry = fn_8023DCCC(entry->name);
        if (foundEntry != 0) {
            locals.sp8 = zero;
            if (skipLookup == 0)
                fn_801A7974((const char *)&locals.sp8, (int)entry->name, (int)targetBase);
            if (locals.sp8 == 0)
                fn_8013358C((int)targetBase, (int)entry->name, *(void **)((char *)foundEntry + 4));
        } else {
            fn_8013358C((int)targetBase, (int)entry->name, (void *)&lbl_8055BC08);
        }
        index++;
        entry++;
    } while (index < 0x1D);

    entry = (Entry *)lbl_802FA218;
    secondIndex = 0;
    do {
        fn_8013358C((int)targetBase, entry->unk0, (void *)entry->name);
        secondIndex++;
        entry++;
    } while (secondIndex < 8);

    fn_8023DA2C((long)targetBase, lbl_80341B8C, 1, flag);
}
#pragma use_lmw_stmw on

void fn_8023DB68(void) {
    long *dst;
    long i;

    lbl_8055BC54 = fn_80137C74();
    dst = &lbl_804987D0[0];
    i = 0;
    while (i < lbl_8055BC54) {
        *dst = __AXGetStackHead_80137CFC(i);
        dst++;
        i++;
    }
}

#pragma scheduling invalid_target
void fn_8023DBCC(void) {
    long *dst;
    long i;

    fn_80137C78(lbl_8055BC54);
    dst = &lbl_804987D0[0];
    i = 0;
    goto check;
loop:
    fn_80137C84(*dst, i);
    dst++;
    i++;
check:
    if (i < lbl_8055BC54)
        goto loop;
    lbl_8055BC54 = -1;
}
#pragma scheduling on
char *fn_8023DC38(char *controlName) {
    /* Look up a control-info entry by name and return a pointer to it, or panic if not found. */
    char **entry;
    s32 index;

    entry = (char **)&lbl_802FA0A8;
    index = 0;
    while (index < 0x1D) {
        if (stricmp(*(char **)(entry + 1), controlName) == 0) {
            return (char *)&lbl_802FA0A8 + (index * 8);
        }
        entry += 2;
        index += 1;
    }
    fn_802E317C(lbl_80341B9C, controlName);
    return 0;
}

#pragma scheduling invalid_target
char *fn_8023DCCC(char *arg0) {
    char **var_r31;
    s32 var_r30;
    s32 repeat;
    var_r31 = (char **)&lbl_802FA190;
    var_r30 = 0;
loop_1:
    if (stricmp(*var_r31, arg0) == 0) {
        return (char *)&lbl_802FA190 + (var_r30 * 8);
    }
    var_r30 += 1;
    repeat = var_r30 < 0x11;
    var_r31 += 2;
    if (repeat) {
        goto loop_1;
    }
    return 0;
}

int fn_8023DD4C() {
    fn_8023DA64(lbl_8055F19C, 1, 1);
    fn_8023E1FC(lbl_8055F190);
}

extern void *lbl_8055F198;
extern int lbl_802FA26C[];
extern int lbl_804987B8[];
extern int lbl_8055BC88;
extern int lbl_8055BC90;
extern int lbl_8055B860;
extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern long fn_8022D850(void *, int, int, int *);
extern void fn_801A7A08(const char *, int, int);
extern void fn_801808DC(void);
extern void *fn_8023E440(void *, void *);
extern void fn_8023E504(void *, int *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_8023DD80(void) {
    struct Interface {
        virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
        virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
        virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
        virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
        virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
        virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
        virtual void slot24(); virtual void slot25(); virtual void *query();
    };
    volatile int local[0x33];
    register char *config;
    register char **table;
    register int zero = 0;
    int state;
    int query;
    int index;
    int arg0;
    int arg2;
    int arg3;
    int option4;
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int result;
    volatile int *options;
    volatile int *defaults;
    Interface *object;
    if (lbl_8055F194 >= 0x11) {
        fn_8023DD4C();
        return 0;
    }
    state = (int)lbl_8055F19C;
    *(volatile char *)((char *)local + 0x1C) = zero;
    *(volatile int *)((char *)local + 0x14) = state;
    object = (Interface *)lbl_8055F198;
    query = (int)object->query();
    index = lbl_8055F194;
    table = (char **)lbl_802FA190;
    fn_801A7974((char *)local + 0x10, (int)table[index * 2], query);
    fn_8023E440((char *)local + 0x38, (char *)local + 0x10);
    config = (char *)local + 0x38;
    *(volatile int *)((char *)local + 0x68) =
        (int)fn_8022D850(lbl_8055F190, lbl_8055F194, 0, 0);
    options = (volatile int *)lbl_802FA26C;
    arg0 = *options++;
    defaults = (volatile int *)lbl_804987B8;
    value0 = defaults[0];
    value1 = defaults[1];
    value2 = defaults[2];
    value3 = defaults[3];
    value4 = defaults[4];
    arg2 = options[1];
    arg3 = options[2];
    option4 = options[3];
    *(volatile int *)((char *)local + 0x60) = (int)&lbl_8055BC88;
    *(volatile int *)((char *)local + 0x64) = 3;
    *(volatile int *)((char *)local + 0x6C) = zero;
    *(volatile int *)((char *)local + 0x70) = zero;
    *(volatile int *)((char *)local + 0x74) = (int)&lbl_8055BC90;
    *(volatile int *)((char *)local + 0x78) = 0x10;
    *(volatile int *)((char *)local + 0x7C) = zero;
    *(volatile int *)((char *)local + 0x80) = (int)config;
    *(volatile int *)((char *)local + 0x84) = zero;
    *(volatile int *)((char *)local + 0x88) = (int)&lbl_8055B860;
    *(volatile int *)((char *)local + 0x8C) = 6;
    *(volatile int *)((char *)local + 0x90) = zero;
    *(volatile int *)((char *)local + 0x94) = -1;
    *(volatile int *)((char *)local + 0x98) = 0x1B;
    *(volatile int *)((char *)local + 0x9C) = (int)&lbl_8055B860;
    *(volatile int *)((char *)local + 0xA0) = 6;
    *(volatile int *)((char *)local + 0xA4) = zero;
    *(volatile int *)((char *)local + 0xA8) = -2;
    *(volatile int *)((char *)local + 0xAC) = 0xD;
    *(volatile int *)((char *)local + 0xB0) = value0;
    *(volatile int *)((char *)local + 0xB4) = value1;
    *(volatile int *)((char *)local + 0xB8) = value2;
    *(volatile int *)((char *)local + 0xBC) = value3;
    *(volatile int *)((char *)local + 0xC0) = value4;
    *(volatile int *)((char *)local + 0x20) = arg0;
    *(volatile int *)((char *)local + 0x24) = (int)((char *)local + 0x60);
    *(volatile int *)((char *)local + 0x28) = arg2;
    *(volatile int *)((char *)local + 0x2C) = arg3;
    *(volatile int *)((char *)local + 0x30) = option4;
    result = fn_802146BC((int *)((char *)local + 0x20), -0x3E7, -0x3E7, 1,
        option4, arg3, arg2, arg0);
    if (result != -1) {
        *(volatile char *)((char *)local + 0x0C) = zero;
        *(volatile int *)((char *)local + 0x04) = (int)lbl_8055F19C;
        fn_8023E504(config, (int *)local);
        object = (Interface *)lbl_8055F198;
        fn_801A7A08((char *)local, (int)table[lbl_8055F194 * 2],
            (int)object->query());
        fn_8023E1FC(lbl_8055F190);
        fn_801808DC();
    }
    return 0;
}
#pragma cplusplus reset
#pragma scheduling on
#pragma use_lmw_stmw on
int fn_8023DF70(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8023DFB0(void) {
    fn_8023DD4C();
    return 0;
}

int fn_8023DFD4(void) {
    extern int lbl_8055F194;
    extern void fn_8023E16C(void *, int);
    extern void fn_8023E0DC(void *, int, int);
    int capacity;
    int index;

    fn_8023E16C(lbl_8055F190, lbl_8055F194);
    capacity = *(int *)((char *)lbl_8055F190 + 8);
    index = (capacity + lbl_8055F194 - 1) % capacity;
    lbl_8055F194 = index;
    fn_8023E0DC(lbl_8055F190, index, capacity);
    return 0;
}

int fn_8023E028(void) {
    int temp_r4;
    int temp_r5;

    fn_8023E16C(lbl_8055F190, lbl_8055F194);
    temp_r5 = lbl_8055F194 + 1;
    temp_r4 = temp_r5 % *(int *)((char *)lbl_8055F190 + 8);
    lbl_8055F194 = temp_r4;
    fn_8023E0DC(lbl_8055F190, temp_r4, temp_r5);
    return 0;
}

extern int fn_80128668(void);
extern void fn_8023DA64(void *, int, int);
extern char lbl_8055BBB8[];
extern char lbl_8055BBC0[];
extern char lbl_8055BBD0[];
extern char lbl_8055BC18[];
extern char lbl_8055BC68[];
extern char lbl_8055BC70[];
extern char lbl_8055BC78[];
extern char lbl_8055BC80[];
extern void fn_80137D10(void);

extern void fn_802E30C8(void *);
extern void fn_802E8664(int);
extern void *lbl_8055F19C;
extern void *lbl_8055F190;
extern int lbl_8055F194;
extern void fn_8023E16C(void *, int);
extern void fn_8023E0DC(void *, int, int);
extern int lbl_80563748;
extern void *fn_8022D458(void *, int, int, int *);
extern int fn_80137C98(int);
extern int fn_8018108C(void);
extern void fn_8023E1FC(void *);
void *fn_8023E078(void *arg0, int arg1) {
    fn_8022D458(arg0, 0x12, 2, &lbl_80563748);
    *(int *)((char *)arg0 + 0x30) = arg1;
    fn_80137C98(arg1);
    *(int *)((char *)arg0 + 0x34) = fn_8018108C();
    fn_8023E1FC(arg0);
    return arg0;
}

void fn_8023E0DC(void *table, int row, int arg2) {
    /* Set all entries in a table row by writing a 1 flag/value to each column slot. */
    int col;
    if (row < 0)
        return;
    if (row >= *(int *)((char *)table + 8))
        return;
    col = *(int *)((char *)table + 4);
    while (col-- > 0) {
        fn_8022D894(table, row, col, fn_8022D850(table, row, col, 0), 1);
    }
}

void fn_8023E16C(void *arg0, int arg1) {
    /* Clear all entries in a table row by writing a 0 flag/value to each column slot. */
    int var_r31;
    if (arg1 < 0) {
        return;
    }
    if (arg1 >= *(int *)((char *)arg0 + 8)) {
        return;
    }
    var_r31 = *(int *)((char *)arg0 + 4);
    while (var_r31-- > 0) {
        fn_8022D894(arg0, arg1, var_r31, fn_8022D850(arg0, arg1, var_r31, 0), 0);
    }
}

extern char lbl_80341BE0[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8023E1FC(void *arg0) {
    struct Interface {
        virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
        virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
        virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
        virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
        virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
        virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
        virtual void slot24(); virtual void slot25(); virtual void *query();
    };
    struct Frame {
        int result;
        volatile int state;
        char pad0[4];
        volatile char zero;
        char pad1[3];
        char string[0x14];
    } frame;
    register char *entry;
    register int zero = 0;
    int i;
    Interface *object;

    fn_8022D76C();
    frame.state = *(int *)((char *)arg0 + 0x30);
    entry = lbl_802FA190;
    frame.zero = zero;
    for (i = 0; i < 0x11; i++, entry += 8) {
        fn_8022D894(arg0, i, 0, (long)*(char **)fn_8023DC38(*(char **)entry), 0);
        object = *(Interface **)((char *)arg0 + 0x34);
        fn_801A7974((const char *)&frame.result, (int)*(char **)entry, (int)object->query());
        if (frame.result == 0) {
            char c;
            char *src = lbl_8055BBA0;
            int count = 0x14;
            char *dst = frame.string;
            goto read;
            do {
                count--;
                if (count <= 0) {
                    dst[-1] = zero;
                    break;
                }
            read:
                c = *src++;
                *dst++ = c;
            } while ((signed char)c != 0);
        } else {
            fn_801A7E54(frame.string, 0x14, &frame.result);
        }
        fn_8022D894(arg0, i, 1, (long)frame.string, 0);
    }
    fn_8022D894(arg0, 0x11, 0, (long)lbl_80341BE0, 0);
}
#pragma cplusplus reset
#pragma pop

void fn_8023E33C(void *arg0) {
    /* Fill the object's 0x14-byte name buffer at +0x14 from its name index at +0x10, or copy a default empty string when the index is -1. */
    struct NameInfo {
        int unk0;
        int unk4;
        char unk8[4];
        char unkC;
    } nameInfo;
    unsigned char *src;
    unsigned char c;
    int remaining;
    unsigned char *dst;

    if (*(int *)((char *)arg0 + 0x10) == -1) {
        src = (unsigned char *)lbl_8055BBA0;
        remaining = 0x14;
        dst = (unsigned char *)arg0 + 0x14;
        goto copy;
    check_count:
        remaining--;
        if (remaining > 0)
            goto copy;
        dst[-1] = 0;
        return;
    copy:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto check_count;
        return;
    }

    nameInfo.unk4 = 0;
    nameInfo.unkC = 0;
    fn_801A9050(&nameInfo, *(int *)((char *)arg0 + 0x10));
    fn_801A7E54((char *)arg0 + 0x14, 0x14, &nameInfo);
}

int fn_8023E3D8(int arg0, int arg1) {
    s32 max = fn_801A902C();
    s32 *p = (s32 *)arg0;
    s32 old = p[4];
    s32 tmp;
    max += 1;
    tmp = max + arg1;
    old += 1;
    p[4] = (old + tmp) % max - 1;
    fn_8023E33C(p);
}

/* Initialize a component record and resolve its entry index by matching descriptor fields. */
void *fn_8023E440(void *self, void *desc) {
    extern int fn_801A902C(void);
    extern int fn_801A9050(void *, int);
    extern void fn_8023E33C(void *);
    extern char lbl_80341C50[];
    struct Out { int first; int pad; unsigned int second; char tail[4]; } entry;
    int zero = 0;
    int index;
    *(char *)self = zero;
    *(s32 *)((char *)self + 4) = -1;
    *((char *)self + 8) = zero;
    *(char **)((char *)self + 0xC) = lbl_80341C50;
    *(s32 *)((char *)self + 0x10) = -1;
    index = fn_801A902C();
    goto test;
loop:
    entry.pad = zero;
    entry.tail[0] = zero;
    fn_801A9050(&entry, index);
    if (entry.first == *(s32 *)desc && entry.second == *(unsigned int *)((char *)desc + 8))
        *(s32 *)((char *)self + 0x10) = index;
test:
    if (index-- > 0)
        goto loop;
    fn_8023E33C(self);
    return self;
}

void fn_8023E504(void *arg0, int *arg1) {
    int value = *(int *)((char *)arg0 + 0x10);
    if (value == -1) {
        *arg1 = 0;
        return;
    }
    fn_801A9050(arg1, value);
}

extern int lbl_80341C40[];
extern int fn_801A902C(void);
extern void fn_8023E33C();
int fn_8023E52C(int arg0) {
    return lbl_80341C40[arg0];
}

  extern s32 lbl_80341C40[];
extern s32 fn_801A902C(void);
        extern void fn_8023E33C(void *);
s32 fn_8023E540(s32 arg0) {
    return arg0 + 0x14;
}

void fn_8023E548(s32 arg0) {
    fn_8023E3D8(arg0, 1);
}

int fn_8023E3D8(int, int);
void fn_8023E550(int arg0) {
    fn_8023E3D8(arg0, -1);
}

  extern s32 fn_8023DD4C(void);
  extern char lbl_802FA190[];
  extern s32 stricmp(const char *, const char *);
  extern char lbl_802FA0A8[];
  extern char lbl_80341B9C[];
  extern s32 fn_802E317C(const char *, ...);
  #pragma cplusplus on
struct Dummy8023E1FC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void *v14();
};
#pragma cplusplus reset
