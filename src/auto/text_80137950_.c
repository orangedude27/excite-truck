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
int fn_801379CC(void) {
    if ((int)lbl_80559C00 == -1) {
        fn_802E317C("x");
    }
    return (int)lbl_8042F788[(int)lbl_80559C00];
}

void fn_80137B0C(void* hi) {
    lbl_80559C00 = hi;
}

void fn_80137B14(void) {
    lbl_80559C00 = (void*)-1;
}

extern char lbl_80559C38[];
extern void *fn_801284F8(int, const char *);
extern char *fn_80137950(int);
extern void fn_80137B0C(void *);
extern int fn_801379CC(void);
extern void fn_80137A18(void);
extern void fn_80137B14(void);
extern void *memset(void *, int, unsigned long);
extern char *strcpy(char *, const char *);
void fn_80137B20(void) {
    int i = 0;
    lbl_8055E0E0 = 1;
    lbl_80559C00 = (void *)-1;
    do {
        lbl_8042F788[i] = fn_801284F8(0x28, lbl_80559C38);
        memset(lbl_8042F788[i], 0, 0x28);
        strcpy((char *)lbl_8042F788[i] + 8, fn_80137950(i));
        fn_80137B0C((void *)i);
        fn_801379CC();
        lbl_8042F798[0] = 4;
        lbl_8042F798[1] = 4;
        lbl_8042F798[2] = 4;
        lbl_8042F798[3] = 4;
        fn_80137A18();
        fn_80137B14();
        i++;
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

int fn_80137C98(int value) {
    int count = fn_800167F4();
    int i = 0;
    if (count > 0) {
        do {
            if (value == lbl_8042F798[i])
                return i;
            i++;
        } while (--count != 0);
    }
    return -1;
}

int __AXGetStackHead_80137CFC(int index) { return lbl_8042F798[index]; }

void fn_80137D10(void) {
    int i = 0;
    do {
        fn_80137C84(i, i);
        i++;
    } while (i < 4);
}

