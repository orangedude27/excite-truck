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
    register long len;
    register char *base = lbl_803416A8;
    register long i = 0;
    char spC;
    char spB;
    char spA;
    char sp9;
    char sp8;

    do {
        len = 0x10;
        if (i < 4)
            len = i + 0xC;
        spC = 1;
        spB = 1;
        spA = 0;
        sp9 = 0;
        sp8 = 1;
        fn_801333E8(len, base + 0x368, &spC);
        fn_801333E8(len, base + 0x378, &spB);
        fn_801333E8(len, base + 0x38C, &spA);
        fn_801333E8(len, base + 0x3A0, &sp9);
        fn_801333E8(len, base + 0x3B0, &sp8);
        i++;
    } while (i < 5);
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
void fn_8023DA64(void *arg0, int arg1, int arg2) {
    typedef struct { int unk0; char *name; } Entry;
    register int zero = 0;
    volatile char sp14;
    int sp8;
    char *base = (char *)arg0 + 8;
    Entry *entry = (Entry *)lbl_802FA0A8;
    int i = 0;
    void *found;

    sp14 = zero;
    do {
        found = fn_8023DCCC(entry->name);
        if (found != 0) {
            sp8 = zero;
            if (arg1 == 0)
                fn_801A7974((const char *)&sp8, (int)entry->name, (int)base);
            if (sp8 == 0)
                fn_8013358C((int)base, (int)entry->name, *(void **)((char *)found + 4));
        } else {
            fn_8013358C((int)base, (int)entry->name, (void *)&lbl_8055BC08);
        }
        i++;
        entry++;
    } while (i < 0x1D);

    entry = (Entry *)lbl_802FA218;
    i = 0;
    do {
        fn_8013358C((int)base, entry->unk0, (void *)entry->name);
        i++;
        entry++;
    } while (i < 8);

    fn_8023DA2C((long)base, lbl_80341B8C, 1, arg2);
}

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
char *fn_8023DC38(char *arg0) {
    char **var_r31;
    s32 var_r30;

    var_r31 = (char **)&lbl_802FA0A8;
    var_r30 = 0;
    while (var_r30 < 0x1D) {
        if (stricmp(*(char **)(var_r31 + 1), arg0) == 0) {
            return (char *)&lbl_802FA0A8 + (var_r30 * 8);
        }
        var_r31 += 2;
        var_r30 += 1;
    }
    fn_802E317C(lbl_80341B9C, arg0);
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
#pragma scheduling on
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
extern int fn_8022D458(int, int, int *);
extern int fn_80137C98(int);
extern int fn_8018108C(void);
extern void fn_8023E1FC(void *);
void *fn_8023E078(void *arg0, int arg1) {
    fn_8022D458(0x12, 2, &lbl_80563748);
    *(int *)((char *)arg0 + 0x30) = arg1;
    fn_80137C98(arg1);
    *(int *)((char *)arg0 + 0x34) = fn_8018108C();
    fn_8023E1FC(arg0);
    return arg0;
}

void fn_8023E0DC(void *arg0, int arg1, int arg2) {
    int var_r31;
    if (arg1 < 0 || arg1 >= *(int *)((char *)arg0 + 8)) {
        return;
    }
    var_r31 = *(int *)((char *)arg0 + 4);
    do {
        fn_8022D894(arg0, arg1, var_r31, fn_8022D850(arg0, arg1, var_r31, 0), 1);
        var_r31--;
    } while (var_r31 > 0);
}

void fn_8023E16C(void *arg0, int arg1) {
    int var_r31;
    if (arg1 < 0 || arg1 >= *(int *)((char *)arg0 + 8)) {
        return;
    }
    var_r31 = *(int *)((char *)arg0 + 4);
    do {
        fn_8022D894(arg0, arg1, var_r31, fn_8022D850(arg0, arg1, var_r31, 0), 0);
        var_r31--;
    } while (var_r31 > 0);
}

extern char lbl_80341BE0[];
void fn_8023E1FC(void *arg0) {
    int i, sp8;
    char sp18[0x14];
    char *p;
    fn_8022D76C();
    for (i = 0; i < 0x11; i++) {
        char *entry = lbl_802FA190 + i * 8;
        fn_8022D894(arg0, i, 0, *(char **)fn_8023DC38(*(char **)entry), 0);
        fn_801A7974((const char *)&sp8, (int)*(char **)entry, (int)*(void **)((char *)*(void ***)((char *)arg0 + 0x34) + 0x70));
        if (sp8 == 0) {
            p = lbl_8055BBA0;
            {
                int n = 0x14;
                char *q = sp18;
                do {
                    char c = *p++;
                    *q++ = c;
                    if ((signed char)c == 0) break;
                    n--;
                    if (n <= 0) { q[-1] = 0; break; }
                } while (1);
            }
        } else {
            fn_801A7E54(sp18, 0x14, (void *)sp8);
        }
        fn_8022D894(arg0, i, 1, sp18, 0);
    }
    fn_8022D894(arg0, 0x11, 0, lbl_80341BE0, 0);
}

void fn_8023E33C(void *arg0) {
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

void *fn_8023E440(void *arg0, void *arg1) {
    extern int fn_801A902C(void);
    extern int fn_801A9050(void *, int);
    extern void fn_8023E33C(void *);
    extern char lbl_80341C50[];
    struct Out { int first; int pad; unsigned int second; char tail[4]; } out;
    int zero = 0;
    int i;
    *(char *)arg0 = zero;
    *(s32 *)((char *)arg0 + 4) = -1;
    *((char *)arg0 + 8) = zero;
    *(char **)((char *)arg0 + 0xC) = lbl_80341C50;
    *(s32 *)((char *)arg0 + 0x10) = -1;
    i = fn_801A902C();
    goto test;
loop:
    out.pad = zero;
    out.tail[0] = zero;
    fn_801A9050(&out, i);
    if (out.first == *(s32 *)arg1 && out.second == *(unsigned int *)((char *)arg1 + 8))
        *(s32 *)((char *)arg0 + 0x10) = i;
test:
    if (i-- > 0)
        goto loop;
    fn_8023E33C(arg0);
    return arg0;
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
