  // Code of main that had no source file yet: decomp.wtf gave it this one.
  // split_file divides it into the game's real files (file_status shows its range).
  
  typedef signed int s32;
  extern void *lbl_8055F18C;
  extern s32 fn_8023DD4C(void);
  extern char lbl_802FA190[];
  extern s32 stricmp(const char *, const char *);
  extern char lbl_802FA0A8[];
  extern char lbl_80341B9C[];
  extern s32 fn_802E317C(const char *, ...);
  extern char lbl_8055BBA0[];
  extern void fn_801A7E54(void *, s32, s32);
void* fn_8023D6FC(void) {
    return lbl_8055F18C;
}

extern void fn_801333E8(long, void *, char *);
extern void fn_80133460(void);
extern long fn_80137C74(void);
extern unsigned long __AXGetStackHead_80137CFC(long);
extern long lbl_803416A8;
extern long lbl_8055BC54;
extern long lbl_804987D0;
void fn_8023D704(long arg0) {
    lbl_8055F18C = (void *)arg0;
}

void fn_8023D70C(void) {
    char sp8;
    char sp9;
    char spA;
    char spB;
    char spC;
    long i = 0;
    long len;

    do {
        len = 0x10;
        if (i < 4) {
            len = i + 0xC;
        }
        spC = 1;
        spB = 1;
        spA = 0;
        sp9 = 0;
        sp8 = 1;
        fn_801333E8(len, &lbl_803416A8 + 0x368, &spC);
        fn_801333E8(len, &lbl_803416A8 + 0x378, &spB);
        fn_801333E8(len, &lbl_803416A8 + 0x38C, &spA);
        fn_801333E8(len, &lbl_803416A8 + 0x3A0, &sp9);
        fn_801333E8(len, &lbl_803416A8 + 0x3B0, &sp8);
        i++;
    } while (i < 5);
}

void fn_8023DA2C(long arg2, long arg3) {
    char sp8;

    sp8 = arg2;
    if (arg3 != 0) {
        fn_80133460();
        return;
    }
    fn_801333E8(0, 0, &sp8);
}

void fn_8023DB68(void) {
    long i = 0;
    long *dst = &lbl_804987D0;

    lbl_8055BC54 = fn_80137C74();
    while (i < lbl_8055BC54) {
        *dst = __AXGetStackHead_80137CFC(i);
        dst++;
        i++;
    }
}

char *fn_8023DC38(char *arg0) {
    char **var_r31;
    s32 var_r30;

    var_r31 = (char **)&lbl_802FA0A8;
    var_r30 = 0;
loop_1:
    if (stricmp(*(char **)(var_r31 + 1), arg0) == 0) {
        return (char *)&lbl_802FA0A8 + (var_r30 * 8);
    }
    var_r30 += 1;
    var_r31 += 1;
    if (var_r30 >= 0x1D) {
        fn_802E317C(lbl_80341B9C, arg0);
        return 0;
    }
    goto loop_1;
}

char *fn_8023DCCC(char *arg0) {
    char **var_r31;
    s32 var_r30;

    var_r31 = (char **)&lbl_802FA190;
    var_r30 = 0;
loop_1:
    if (stricmp(*var_r31, arg0) == 0) {
        return (char *)var_r31;
    }
    var_r30 += 1;
    var_r31 += 1;
    if (var_r30 >= 0x11) {
        return 0;
    }
    goto loop_1;
}

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

extern int fn_80128668(void);
extern void fn_8023DA64(void *, int, int);
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

extern int lbl_80341C40[];
extern int fn_801A902C(void);
extern void fn_801A9050(void *, int);
extern void fn_8023E33C();
int fn_8023E52C(int arg0) {
    return lbl_80341C40[arg0];
}

  extern s32 lbl_80341C40[];
  extern s32 fn_801A902C(void);
  extern void fn_801A9050(void *, s32);
  extern void fn_8023E33C(void *, s32, s32);
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
  extern char lbl_8055BBA0[];

