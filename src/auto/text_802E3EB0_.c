// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055FF38;
extern unsigned char lbl_804FBAA0[0x10 * 0x91];
extern unsigned int lbl_8055D1B4;
extern unsigned int lbl_8055D1B8;
#pragma small_data off
extern unsigned int lbl_8034D130;
#pragma small_data on
extern int strncmp(const char *, const char *, unsigned int);
extern char *strcpy(char *, const char *);
extern void *memset(void *, int, unsigned int);
extern int DVDGetCurrentDir(char **, char *);
extern unsigned int lbl_8034D038;
extern char lbl_8034D054[];
extern unsigned int lbl_8055FF40;
extern void fn_802E317C(void *, ...);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034D198[];
unsigned int *fn_802E3EB0(void) { return &lbl_8055FF38; }

void fn_802E3EB8(void) {}

void *fn_802E3EBC(void) {
    int i;
    for (i = 0; i < 0x10; i++) {
        if (lbl_804FBAA0[i * 0x91] == 0) {
            lbl_804FBAA0[i * 0x91] = 1;
            return &lbl_804FBAA0[i * 0x91 + 1];
        }
    }
    fn_802E317C(&lbl_8034D038);
    return (void *)lbl_8055FF40;
}

#pragma scheduling invalid_target
void fn_802E3F38(void *arg0) {
    unsigned char *p;
    int i;
    p = lbl_804FBAA0;
    for (i = 0; i < 0x10; i++) {
        if (arg0 == p + 1) {
            lbl_804FBAA0[i * 0x91] = 0;
            return;
        }
        p += 0x91;
    }
    fn_802E317C(lbl_8034D054, arg0);
}
#pragma scheduling on
int fn_802E4030(int arg0, int arg1) {
    void (*reset)(void);
    if (arg0 != 0 && arg1 > 0) {
        reset = fn_802E3EB8;
        reset();
    }
    return arg0;
}

extern const char lbl_8034D0C0[];
#pragma scheduling invalid_target
int fn_802E4070(void) {
    fn_802E30C8(lbl_8034D0C0);
    return 0;
}

void *fn_802E40A0(void *arg0, char *arg1) {
    char cwd[0x100];
    register char *path = arg1;
    register void *obj;
    int status;
    obj = ((void *(*)(int, void *))fn_802E3EBC)(0x90, &lbl_8055D1B4);
    if (obj != 0) {
        *(void **)obj = &lbl_8034D130;
        *(void **)((char *)obj + 0x8C) = arg0;
        if (strncmp(path, (char *)&lbl_8055D1B8, 2) == 0) path += 2;
        if (*path == '\\') path++;
        strcpy((char *)obj + 0x40, path);
        memset((char *)obj + 4, 0, 0x3C);
        *(int *)((char *)obj + 0x88) = 0;
        *(int *)((char *)obj + 0x84) = 0;
        strcpy(cwd, (char *)obj + 0x40);
        status = DVDGetCurrentDir((char **)&cwd, (char *)obj + 4);
        *((unsigned char *)obj + 0x80) = (status != 0);
        if (status != 0) *(int *)((char *)obj + 0x84) = *(int *)((char *)obj + 0x38);
    }
    if (obj == 0 || *(unsigned char *)((char *)obj + 0x80) == 0) {
        if (obj != 0) ((void (*)(void *, int))(*(void ***)obj)[12])(obj, 1);
        obj = 0;
    }
    return obj;
}

extern unsigned int lbl_8055D1B0;
extern unsigned int lbl_8034D074;
extern unsigned int lbl_8034D098;
extern void DVDInit(void);
extern void OSReport(const char *, ...);
extern unsigned int lbl_8034D098;
extern int DVDReadAsyncPrio(void *, void *, int, int, int, int);
extern int DVDGetCommandBlockStatus(void *);
extern unsigned int lbl_8055D1BC;
extern char lbl_8034D180[];
extern void DVDInit(void);
extern int DVDClose(void *);
extern void fn_802E3F38(void *);
#pragma small_data off
extern unsigned int lbl_8034D0E4;
extern unsigned int lbl_8034D130;
#pragma small_data on
void *fn_802E41C4(void *arg0, int arg1) {
    void (*release)(void *);
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 0x80) != 0) *(void **)arg0 = &lbl_8034D130;
        else *(void **)arg0 = &lbl_8034D130;
        if (*((unsigned char *)arg0 + 0x80) != 0 && DVDClose((char *)arg0 + 4) == 0) {
            fn_802E30C8((const char *)&lbl_8034D0E4, (char *)arg0 + 0x40);
        }
        if (arg1 > 0) {
            release = fn_802E3F38;
            release(arg0);
        }
    }
    return arg0;
}

extern const char lbl_8034D104[];
#pragma scheduling invalid_target
int fn_802E4250(void) {
    fn_802E30C8(lbl_8034D104);
    return 0;
}
extern unsigned int lbl_8055D1B4;
extern unsigned int lbl_8055D1B8;
extern int strncmp(const char *, const char *, unsigned int);
extern char *strcpy(char *, const char *);
extern void *memset(void *, int, unsigned int);
extern int DVDGetCurrentDir(char **, char *);
int fn_802E4280(void *arg0, char *arg1) {
    char cwd[0x110];
    void *obj;
    char *path;
    int status;
    path = arg1;
    obj = ((void *(*)(int, void *))fn_802E3EBC)(0x90, &lbl_8055D1B4);
    if (obj != 0) {
        *(void **)obj = &lbl_8034D130;
        *(void **)((char *)obj + 0x8C) = arg0;
        if (strncmp(path, (char *)&lbl_8055D1B8, 2) == 0) path += 2;
        if (*path == '\\') path++;
        strcpy((char *)obj + 0x40, path);
        memset((char *)obj + 4, 0, 0x3C);
        *(int *)((char *)obj + 0x88) = 0;
        *(int *)((char *)obj + 0x84) = 0;
        strcpy(cwd, (char *)obj + 0x40);
        status = DVDGetCurrentDir((char **)&cwd, (char *)obj + 4);
        *((unsigned char *)obj + 0x80) = (status != 0);
        if (status != 0) *(int *)((char *)obj + 0x84) = *(int *)((char *)obj + 0x38);
    }
    if (obj == 0 || *(unsigned char *)((char *)obj + 0x80) == 0) {
        if (obj != 0) ((void (*)(void *, int))(*(void ***)obj)[12])(obj, 1);
        obj = 0;
    }
    if (obj != 0) {
        int val = ((int (*)(void *))(*(void ***)obj)[6])(obj);
        ((void (*)(void *, int))(*(void ***)obj)[8])(obj, val);
    }
    return 0;
}

int fn_802E43D8(void *arg0, int arg1) {
    if (arg1 >= 0 && arg1 <= *(int *)((char *)arg0 + 0x84)) {
        *(int *)((char *)arg0 + 0x88) = arg1;
        return 1;
    }
    return 0;
}

int fn_802E4400(void *arg0) {
    return *(int *)((char *)arg0 + 0x84);
}

#pragma push
#pragma cplusplus on
extern "C" int fn_802E4408(int unused, void *arg0) {
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10(int);
    };
    if (arg0 == 0) return;
    ((Obj *)arg0)->f10(1);
}
#pragma cplusplus reset
#pragma pop
void fn_802E442C(void) {
    OSReport((const char *)&lbl_8055D1BC);
}
int fn_802E4438(void *arg0) {
    return *(int *)((char *)arg0 + 0x8C);
}

extern unsigned char lbl_804DBAA0[];
extern char lbl_8034D164[];
extern int DVDReadPrio(void*, void*, int, int, int);
extern int DVDReadAsyncPrio(void*, void*, int, int, int, int);
extern int DVDGetCommandBlockStatus(void*);
extern int DVDGetDriveStatus(void);
extern void VIFlush(void);
extern void VIWaitForRetrace(void);
extern void fn_80127464(void);
extern void* memcpy(void*, const void*, unsigned int);
#pragma scheduling off
int fn_802E4440(void *arg0, void *arg1, int arg2) {
    int pos, aligned, offset, size;
    int result, count;
    if (arg2 == 0) return 0;
    pos = *(int *)((char *)arg0 + 0x88);
    aligned = pos & ~3;
    offset = pos - aligned;
    size = (arg2 + offset + 0x1F) & ~0x1F;
    if (size > 0x20000) size = 0x20000;
    for (;;) {
        result = DVDReadAsyncPrio((char *)arg0 + 4, lbl_804DBAA0, size, aligned, 0, 2);
        if (result > 0) {
            while (DVDGetCommandBlockStatus((char *)arg0 + 4) != 0)
                fn_80127464();
            result = size;
        }
        if (result >= 0) break;
        count = DVDGetDriveStatus();
        if (count == 0) break;
        OSReport(lbl_8034D164, count);
        VIFlush();
        VIWaitForRetrace();
    }
    count = result - offset;
    if (count > arg2) count = arg2;
    if (count > 0) {
        memcpy(arg1, lbl_804DBAA0 + offset, count);
        *(int *)((char *)arg0 + 0x88) += count;
        return count;
    }
    if (count == 0) return 0;
    return -1;
}
#pragma scheduling on
int fn_802E45AC(void *arg0, void *arg1, int arg2) {
    int result;
    result = DVDReadAsyncPrio((char *)arg0 + 4, arg1, arg2, *(int *)((char *)arg0 + 0x88), 0, 2);
    if (result <= 0) {
        fn_802E317C((void *)&lbl_8034D180);
    }
    *(int *)((char *)arg0 + 0x88) += arg2;
    return 1;
}
#pragma scheduling on
int fn_802E461C(void *arg0) {
    return DVDGetCommandBlockStatus((char *)arg0 + 4) == 0;
}

#pragma scheduling invalid_target
int fn_802E4648(void *arg0) {
    fn_802E317C(lbl_8034D198, (char *)arg0 + 0x40);
    return -1;
}
#pragma scheduling on
int fn_802E4680(void *arg0) {
    return *(int *)((char *)arg0 + 0x88);
}

#pragma scheduling off
void fn_802E4688(void *arg0, int arg1) {
    ((void (*)(void *, int))(*(void ***)arg0)[8])(arg0, *(int *)((char *)arg0 + 0x88) + arg1);
}
#pragma scheduling on
void fn_802E46A0(void) {
}

