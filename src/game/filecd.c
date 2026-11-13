// filecd — DVD file layer ("filecd: DVDRead fails!").
// Recovered TU window 0x802E3EB0..0x802E46A4 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E46A4 (+ .ctors slot 0x802ED5F8) remains in
// auto/text_802E46A4_.c pending a promotion pass.
#pragma cplusplus on
class Dummy_802E4688 {
public:
    virtual void d0(int);
    virtual void d1(int);
    virtual void d2(int);
    virtual void d3(int);
    virtual void d4(int);
    virtual void d5(int);
    virtual void m6(int);
};
#pragma cplusplus off
// A DVD file node.  One of the 16 slots of the "fdo" pool (fn_802E3EBC) is
// carved into this; the vtable is lbl_8034D130.  This ABI puts the first
// declared method in slot 0x8 (two leading destructor slots), which is how the
// offsets below line up with the functions that make up the table.
#pragma push
#pragma cplusplus on
class FileDisk {
public:
    virtual int read(void *dst, int len);         // 0x08 fn_802E4440
    virtual int write(const void *src, int len);  // 0x0C fn_802E4648: "write not supported"
    virtual int readAsync(void *dst, int len);    // 0x10 fn_802E45AC
    virtual int isReadDone(void);                 // 0x14 fn_802E461C
    virtual int getLength(void);                  // 0x18 fn_802E4400
    virtual int tell(void);                       // 0x1C fn_802E4680
    virtual int seek(int pos);                    // 0x20 fn_802E43D8
    virtual void seekRelative(int delta);         // 0x24 fn_802E4688
    virtual void flush(void);                     // 0x28 fn_802E46A0
    virtual void *getOwner(void);                 // 0x2C fn_802E4438
    virtual void release(int freeSlot);           // 0x30 fn_802E41C4
    char info[0x3C];     // 0x04 DVD info block: +0x30 file address, +0x34 length, +0x38 position
    char pathText[0x40]; // 0x40 the path it was opened with, prefix stripped
    unsigned char valid; // 0x80 set once the DVD info block was filled in
    unsigned char pad_81[3];
    int length;   // 0x84 file length, from the DVD info block
    int cursor;   // 0x88 next read position
    void *owner;  // 0x8C whoever opened the node
};
#pragma cplusplus reset
#pragma pop
typedef struct VObj { struct VObjVt { int pad[8]; void (*fn)(struct VObj *, int); } *vt; char pad[0x84]; int off; } VObj;
typedef struct VtObj88 { struct VtObj88Vt { int pad[8]; void (*fn)(struct VtObj88 *, int); } *vt; char pad[0x84]; int off; } VtObj88;
extern unsigned int lbl_8055FF38;
extern unsigned int lbl_8055D1B0;
extern char lbl_8034D074[];
extern char lbl_8034D098[];
extern void DVDInit(void);
extern void OSReport(const char *, ...);
extern unsigned char lbl_804FBAA0[0x10 * 0x91];
extern unsigned int lbl_8055D1B4;
extern unsigned int lbl_8055D1B8;
#define fdoPoolName lbl_8055D1B4    /* "fdo": the node pool fn_802E3EBC hands out */
#define dotSlashPrefix lbl_8055D1B8 /* ".\\": path prefix the file layer strips */
#pragma small_data off
extern char lbl_8034D130[];
#define FileDiskVTable lbl_8034D130 /* FileDisk's vtable */
#pragma small_data on
extern int strncmp(const char *, const char *, unsigned int);
extern char *strcpy(char *, const char *);
extern void *memset(void *, int, unsigned int);
extern int DVDGetCurrentDir(char **, char *);
extern char lbl_8034D038[];
extern char lbl_8034D054[];
extern unsigned int lbl_8055FF40;
extern void fn_802E317C(void *, ...);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034D198[];
unsigned int *fn_802E3EB0(void) { return &lbl_8055FF38; }

void fn_802E3EB8(void) {}

#pragma scheduling invalid_target
void *fn_802E3EBC(void) {
    unsigned char *p;
    register int i;
    p = lbl_804FBAA0;
    for (i = 0; i < 0x10; i++) {
        if (*p == 0) {
            p = &lbl_804FBAA0[i * 0x91];
            *p = 1;
            return p + 1;
        }
        p += 0x91;
    }
    fn_802E317C(lbl_8034D038);
    return (void *)lbl_8055FF40;
}
#pragma scheduling on

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

#pragma cplusplus on
extern "C" void *fn_802E3F94(void) {
    void *obj;
    obj = ((void *(*)(int, void *))fn_802E3EB0)(8, &lbl_8055D1B0);
    if (obj != 0) {
        *(void **)obj = &lbl_8034D098;
        DVDInit();
        *((unsigned char *)obj + 4) = 1;
        OSReport((const char *)&lbl_8034D074);
    }
    if (*((unsigned char *)obj + 4) != 0) {
        return obj;
    }
    if (obj != 0) {
        ((Dummy_802E4688 *)obj)->d0(1);
    }
    return 0;
}
#pragma cplusplus reset
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

#pragma push
#pragma cplusplus on
extern "C" void *fn_802E40A0(void *owner, char *path) {
    // filecd "open": carve a FileDisk node out of this TU's "fdo" pool, point it
    // at "path" on the DVD and hand it back with its read cursor at the start of
    // the file.  Returns 0 when the pool is full or the file is not on the disc.
    char pathBuf[0x100];
    FileDisk *file;
    char *name;
    int status;
    name = path;
    file = (FileDisk *)((void *(*)(int, void *))fn_802E3EBC)(sizeof(FileDisk), &fdoPoolName);
    if (file != 0) {
        *(void **)file = &FileDiskVTable;
        file->owner = owner;
        if (strncmp(name, (char *)&dotSlashPrefix, 2) == 0) name += 2;
        if (*name == '\\') name++;
        strcpy(file->pathText, name);
        memset(file->info, 0, sizeof(file->info));
        file->cursor = 0;
        file->length = 0;
        strcpy(pathBuf, file->pathText);
        status = DVDGetCurrentDir((char **)&pathBuf, file->info);
        file->valid = (unsigned int)(-status | status) >> 31;
        if (file->valid != 0) file->length = *(int *)(file->info + 0x34);
    }
    switch (file->valid) {
    case 0:
        if (file != 0) file->release(1);
        file = 0;
        break;
    default:
        break;
    }
    return file;
}
#pragma cplusplus reset
#pragma pop
extern unsigned int lbl_8055D1B0;
extern char lbl_8034D074[];
extern char lbl_8034D098[];
extern void DVDInit(void);
extern void OSReport(const char *, ...);
extern char lbl_8034D098[];
extern int DVDReadAsyncPrio(void *, void *, int, int, int, int);
extern int DVDGetCommandBlockStatus(void *);
extern unsigned int lbl_8055D1BC;
extern char lbl_8034D180[];
extern void DVDInit(void);
extern int DVDClose(void *);
extern void fn_802E3F38(void *);
#pragma small_data off
extern char lbl_8034D0E4[];
extern char lbl_8034D130[];
#pragma small_data on
void *fn_802E41C4(void *file, int destroyFlag) {
    /* Destructor for a DVD file object: close the open DVD handle if valid, report close failure, and optionally free the object. */
    void (*releaseFn)(void *);
    if (file != 0) {
        if (*((unsigned char *)file + 0x80) != 0) {
            *(void **)file = &lbl_8034D130;
        } else {
            *(void **)file = &lbl_8034D130;
        }
        if (*((unsigned char *)file + 0x80) != 0 && DVDClose((char *)file + 4) == 0) {
            fn_802E30C8((const char *)&lbl_8034D0E4, (char *)file + 0x40);
        }
        if (destroyFlag > 0) {
            releaseFn = fn_802E3F38;
            releaseFn(file);
        }
    }
    return file;
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
#pragma push
#pragma cplusplus on
// Open "path" on the DVD as a FileDisk node taken from this TU's "fdo" pool and
// leave its read cursor at the end of the file.  Always returns 0; a node whose
// file could not be opened is released again.
extern "C" int fn_802E4280(void *owner, char *path) {
    char pathBuf[0x100];
    FileDisk *file;
    char *name;
    int status;
    name = path;
    file = (FileDisk *)((void *(*)(int, void *))fn_802E3EBC)(sizeof(FileDisk), &fdoPoolName);
    if (file != 0) {
        *(void **)file = &FileDiskVTable;
        file->owner = owner;
        if (strncmp(name, (char *)&dotSlashPrefix, 2) == 0) name += 2;
        if (*name == '\\') name++;
        strcpy(file->pathText, name);
        memset(file->info, 0, sizeof(file->info));
        file->cursor = 0;
        file->length = 0;
        strcpy(pathBuf, file->pathText);
        status = DVDGetCurrentDir((char **)&pathBuf, file->info);
        file->valid = (unsigned int)(-status | status) >> 31;
        if (file->valid != 0) file->length = *(int *)(file->info + 0x34);
    }
    switch (file->valid) {
    case 0:
        if (file != 0) file->release(1);
        file = 0;
        break;
    default:
        break;
    }
    if (file != 0) {
        int length = file->getLength();
        file->seek(length);
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop
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
#pragma push
#pragma use_lmw_stmw off
int fn_802E4440(void *arg0, void *arg1, int arg2) {
    int pos, aligned, offset, size;
    int result, count;
    if (arg2 == 0) return 0;
    pos = *(int *)((char *)arg0 + 0x88);
    aligned = pos & ~3;
    offset = pos - aligned;
    size = (arg2 + offset + 0x1F) & ~0x1F;
    if (size > 0x20000) size = 0x20000;
    count = 0;
    for (;;) {
        if (count != 0) {
            result = DVDReadPrio((char *)arg0 + 4, lbl_804DBAA0, size, aligned, 2);
        } else {
            result = DVDReadAsyncPrio((char *)arg0 + 4, lbl_804DBAA0, size, aligned, 0, 2);
            if (result > 0) {
                while (DVDGetCommandBlockStatus((char *)arg0 + 4) != 0)
                    fn_80127464();
                result = size;
            }
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
    if (count != 0) return -1;
    return 0;
}
#pragma pop
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

#pragma cplusplus on
extern "C" void fn_802E4688(void *arg0, int arg1) {
    int offset = *(int *)((char *)arg0 + 0x88);
    ((Dummy_802E4688 *)arg0)->m6(offset + arg1);
}
#pragma cplusplus off
void fn_802E46A0(void) {
}

