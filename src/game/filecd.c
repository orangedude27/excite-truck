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
    virtual int readAsync(void *dst, int len);    // 0x10 FileDisk_readAsync
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
// The DVD file system itself: the one 8-byte "fds" object this TU hands out and
// file.c keeps as its disc file layer.  It starts the Nintendo DVD services and
// hands out FileDisk nodes; anything that would write to the disc is refused.
// Same ABI note as FileDisk: the first declared method is slot 0x8.
#pragma push
#pragma cplusplus on
class FileCd {
public:
    virtual void release(int destroyFlag);              // 0x08 fn_802E4030
    virtual int create(void *owner, char *path);        // 0x0C fn_802E4070: "create not supported"
    virtual void *open(void *owner, char *path);        // 0x10 fn_802E40A0
    virtual int openWritable(void *owner, char *path);  // 0x14 fn_802E4250: "open writable not supported"
    virtual int openAtEnd(void *owner, char *path);     // 0x18 fn_802E4280: opens, then seeks to the end
    virtual void close(void *file);                     // 0x1C fn_802E4408: releases the node
    virtual void report(void);                          // 0x20 fn_802E442C: OSReport("%s") with no argument
    virtual int flush(void);                            // 0x24 fn_802E33D0: nothing to flush on a disc
    unsigned char started; // 0x04 set once DVDInit() has started the DVD services
};
#pragma cplusplus reset
#pragma pop
typedef struct VObj { struct VObjVt { int pad[8]; void (*fn)(struct VObj *, int); } *vt; char pad[0x84]; int off; } VObj;
typedef struct VtObj88 { struct VtObj88Vt { int pad[8]; void (*fn)(struct VtObj88 *, int); } *vt; char pad[0x84]; int off; } VtObj88;
extern unsigned int lbl_8055FF38;
extern unsigned int lbl_8055D1B0;
extern char lbl_8034D074[];
extern char lbl_8034D098[];
#define fileCdPoolName lbl_8055D1B0      /* "fds": the tag on this TU's one FileCd object */
#define fileCdMsgDvdStarted lbl_8034D074 /* "filecd: started DVD services" */
#define FileCdVTable lbl_8034D098        /* FileCd's vtable */
extern void DVDInit(void);
extern void OSReport(const char *, ...);
extern unsigned char fdoPool[0x10 * 0x91];
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
extern char fileCdMsgNodeNotFound[];
extern unsigned int lbl_8055FF40;
extern void fn_802E317C(void *, ...);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034D198[];
#define fileCdMsgWriteNotSupported lbl_8034D198 /* "filecd: write not supported (%s)" */
// The "fds" allocator: always hand out this TU's one static FileCd block,
// whatever size/tag the caller asks for; returning that block is its whole job.
unsigned int *fn_802E3EB0(void) {
#define fileCdBlock lbl_8055FF38
    return &fileCdBlock;
#undef fileCdBlock
}

/* FileCd_free: no-op deallocator for the one static FileCd block handed out by
 * FileCd_alloc (fn_802E3EB0); the block is static and never actually returned. */
void fn_802E3EB8(void) {}

#define FileCd_alloc fn_802E3EB0 /* the one static FileCd block */
#define FileCd_free fn_802E3EB8  /* which is never returned to it */

#pragma processor 750
#pragma scheduling invalid_target
void *fn_802E3EBC(void)
{
  unsigned char *p;
  int i;
  p = fdoPool;
  for (i = 0; i < 0x10; i++)
  {
    if (!(*p))
    {
      p = &fdoPool[i * 0x91];
      *p = 1;
      return p + 1;
    }
    p += 0x91;
  }

  fn_802E317C(lbl_8034D038);
  return (void *) lbl_8055FF40;
}
#pragma scheduling on

#pragma scheduling invalid_target
/* Release a DVD file node back to the 16-slot "fdo" pool (fn_802E3EBC hands
 * them out).  The node is the slot base plus one; if it isn't one of our
 * slots, panic with the owner pointer. */
/* Return a FileDisk node to the fdo pool by clearing its slot's used flag; panic if the pointer is not one of our 16 nodes. */ void FileDisk_freeNode(void *node) {
    unsigned char *slotBase;
    int slotIndex;
    slotBase = fdoPool;
    for (slotIndex = 0; slotIndex < 0x10; slotIndex++) {
        if (node == slotBase + 1) {
            fdoPool[slotIndex * 0x91] = 0;
            return;
        }
        slotBase += 0x91;
    }
    fn_802E317C(fileCdMsgNodeNotFound, node);
}
#pragma cplusplus on
// Start the filecd DVD file system: take this TU's one static FileCd object,
// bring up the Nintendo DVD services on it and hand it back for file.c to keep
// as its disc file layer.  Returns 0 when the object did not come up.
/* Create the singleton FileCd, start the DVD services on it, and return it as the disc file layer; release it and return null if startup failed. */ extern "C" void *fn_802E3F94(void) {
    FileCd *cd;
    cd = (FileCd *)((void *(*)(int, void *))FileCd_alloc)(sizeof(FileCd), &fileCdPoolName);
    if (cd != 0) {
        *(void **)cd = &FileCdVTable;
        DVDInit();
        cd->started = 1;
        OSReport(fileCdMsgDvdStarted);
    }
    if (cd->started != 0) {
        return cd;
    }
    if (cd != 0) {
        cd->release(1);
    }
    return 0;
}
#pragma cplusplus reset
int fn_802E4030(int object, int destroyFlag) {
    void (*freeFn)(void);
    /* FileCd::release: free the object through its no-op deallocator when destroying, then return it. */
    if (object != 0 && destroyFlag > 0) {
        freeFn = fn_802E3EB8;
        freeFn();
    }
    return object;
}

extern const char lbl_8034D0C0[];
#define fileCdMsgCreateNotSupported lbl_8034D0C0 /* "filecd: create not supported (%s)" */
#pragma scheduling invalid_target
/* FileCd::create (vtable slot 0x0C): the disc file layer cannot create files,
 * so it only reports the attempt and fails.  The message's %s is never filled in. */
int fn_802E4070(void) {
    fn_802E30C8(fileCdMsgCreateNotSupported);
    return 0;
}

#pragma push
#pragma cplusplus on
/* Open a file by path: allocate a FileDisk node from the fdo pool, resolve its DVD info and return it with its cursor at the start, or 0 on failure. */ extern "C" void *fn_802E40A0(void *owner, char *path) {
    // filecd "open": carve a FileDisk node out of this TU's "fdo" pool, point it
    // at "path" on the DVD and hand it back with its read cursor at the start of
    // the file.  Returns 0 when the pool is full or the file is not on the disc.
    char pathBuf[0x100];
    FileDisk *file;
    char *pathName;
    int dvdResult;
    pathName = path;
    file = (FileDisk *)((void *(*)(int, void *))fn_802E3EBC)(sizeof(FileDisk), &fdoPoolName);
    if (file != 0) {
        *(void **)file = &FileDiskVTable;
        file->owner = owner;
        if (strncmp(pathName, (char *)&dotSlashPrefix, 2) == 0) pathName += 2;
        if (*pathName == '\\') pathName++;
        strcpy(file->pathText, pathName);
        memset(file->info, 0, sizeof(file->info));
        file->cursor = 0;
        file->length = 0;
        strcpy(pathBuf, file->pathText);
        dvdResult = DVDGetCurrentDir((char **)&pathBuf, file->info);
        file->valid = (unsigned int)(-dvdResult | dvdResult) >> 31;
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
#define fileCdMsgDvdReadFails lbl_8034D180 /* "filecd: DVDRead fails!" */
extern void DVDInit(void);
extern int DVDClose(void *);
extern void FileDisk_freeNode(void *);
#pragma small_data off
extern char lbl_8034D0E4[];
extern char lbl_8034D130[];
#pragma small_data on
/* Deleting destructor for a FileDisk DVD file node: reset its vtable, close the
 * embedded DVD handle when valid (logging failures), and release the node back
 * to the pool when shouldFree > 0. */
void *fn_802E41C4(void *dvdFile, int shouldFree) {
    void (*releaseNode)(void *);
    if (dvdFile != 0) {
        if (*((unsigned char *)dvdFile + 0x80) != 0) {
            *(void **)dvdFile = &lbl_8034D130;
        } else {
            *(void **)dvdFile = &lbl_8034D130;
        }
        if (*((unsigned char *)dvdFile + 0x80) != 0 && DVDClose((char *)dvdFile + 4) == 0) {
            fn_802E30C8((const char *)&lbl_8034D0E4, (char *)dvdFile + 0x40);
        }
        if (shouldFree > 0) {
            releaseNode = FileDisk_freeNode;
            releaseNode(dvdFile);
        }
    }
    return dvdFile;
}

extern const char lbl_8034D104[];
#define fileCdMsgOpenWritableNotSupported lbl_8034D104 /* "filecd: open writable not supported (%s)" */
#pragma scheduling invalid_target
/* FileCd::openWritable (vtable slot 0x14): the disc file layer has nothing to
 * write to, so it only reports the attempt and fails.  The message's %s is
 * never filled in -- the path is not passed down. */
int fn_802E4250(void) {
    fn_802E30C8(fileCdMsgOpenWritableNotSupported);
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
// Open "path" from the DVD as a FileDisk node taken from the fdo pool, seed its
// vtable/owner, strip a leading ".\\" or "\", fetch its info block, then seek to
// end of file. Invalid nodes are released again; always returns 0.
extern "C" int fn_802E4280(void *owner, char *path) {
    char pathBuf[0x100];
    FileDisk *disk;
    char *pathStart;
    int dvdResult;
    pathStart = path;
    disk = (FileDisk *)((void *(*)(int, void *))fn_802E3EBC)(sizeof(FileDisk), &fdoPoolName);
    if (disk != 0) {
        *(void **)disk = &FileDiskVTable;
        disk->owner = owner;
        if (strncmp(pathStart, (char *)&dotSlashPrefix, 2) == 0) pathStart += 2;
        if (*pathStart == '\\') pathStart++;
        strcpy(disk->pathText, pathStart);
        memset(disk->info, 0, sizeof(disk->info));
        disk->cursor = 0;
        disk->length = 0;
        strcpy(pathBuf, disk->pathText);
        dvdResult = DVDGetCurrentDir((char **)&pathBuf, disk->info);
        disk->valid = (unsigned int)(-dvdResult | dvdResult) >> 31;
        if (disk->valid != 0) disk->length = *(int *)(disk->info + 0x34);
    }
    switch (disk->valid) {
    case 0:
        if (disk != 0) disk->release(1);
        disk = 0;
        break;
    default:
        break;
    }
    if (disk != 0) {
        int fileLength = disk->getLength();
        disk->seek(fileLength);
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop
/* Seek a DVD file node: set its cursor (0x88) to pos when 0 <= pos <= length (0x84); return 1 on success, 0 if out of range. */
int fn_802E43D8(void *file, int pos) {
    if (pos >= 0 && pos <= *(int *)((char *)file + 0x84)) {
        *(int *)((char *)file + 0x88) = pos;
        return 1;
    }
    return 0;
}

/* Return the cached file length stored at offset 0x84 of the DVD file node (FileDisk::length). */
int fn_802E4400(void *file) {
    return *(int *)((char *)file + 0x84);
}

#pragma push
#pragma cplusplus on
extern "C" int fn_802E4408(int unused, void *arg0) {
    /* FileCd::close: release the given DVD file node, freeing its pool slot. */
    if (arg0 == 0) return;
    ((FileDisk *)arg0)->release(1);
}
#pragma cplusplus reset
#pragma pop
/* FileCd::report (vtable slot 0x20): OSReport the "%s" format with no argument. */
void fn_802E442C(void) {
    OSReport((const char *)&lbl_8055D1BC);
}
/* FileDisk::getOwner (vtable slot 0x2C): return the owner pointer (FileDisk.owner at +0x8C) stored on the node when it was opened. */
int fn_802E4438(void *file) {
    return *(int *)((char *)file + 0x8C);
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
    struct DVDFile { char pad[4]; char info[1]; int cursor[0x21]; } *file;
    int pos, aligned, offset, size;
    int result, count, st, n, status;
    if (arg2 == 0) return 0;
    file = (struct DVDFile *)arg0;
    pos = *(int *)((char *)arg0 + 0x88);
    aligned = pos & ~3;
    offset = pos - aligned;
    size = (arg2 + offset + 0x1F) & ~0x1F;
    if (size > 0x20000) size = 0x20000;
    count = 0;
    for (;;) {
        if (count != 0) {
            result = DVDReadPrio(file->info, lbl_804DBAA0, size, aligned, 2);
        } else {
            result = DVDReadAsyncPrio(file->info, lbl_804DBAA0, size, aligned, 0, 2);
            if (result > 0) {
                for (;;) {
                    st = DVDGetCommandBlockStatus(file->info);
                    if (st == 0) break;
                    fn_80127464();
                }
                result = size;
            }
        }
        if (result >= 0) break;
        status = DVDGetDriveStatus();
        count = status;
        if (status == 0) break;
        OSReport(lbl_8034D164, status);
        VIFlush();
        VIWaitForRetrace();
    }
    n = result - offset;
    if (n > arg2) n = arg2;
    if (n > 0) {
        memcpy(arg1, lbl_804DBAA0 + offset, n);
        *(int *)((char *)arg0 + 0x88) += n;
        return n;
    }
    switch (n) {
    default:
        return -1;
    case 0:
        return 0;
    }
}
#pragma pop
/* FileDisk::readAsync (vtable slot 0x10): start an async DVD read from the file's
 * cursor into dst for len bytes at priority 2.  A non-positive return from
 * DVDReadAsyncPrio is fatal; otherwise advance the cursor by len and return 1. */
int FileDisk_readAsync(void *file, void *dst, int len) {
    int result;
    result = DVDReadAsyncPrio((char *)file + 4, dst, len, *(int *)((char *)file + 0x88), 0, 2);
    if (result <= 0) {
        fn_802E317C((void *)&fileCdMsgDvdReadFails);
    }
    *(int *)((char *)file + 0x88) += len;
    return 1;
}
#pragma scheduling on
int fn_802E461C(void *file) {
    /* FileDisk::isReadDone — true when the DVD command block is idle (status 0). */
    return DVDGetCommandBlockStatus((char *)file + 4) == 0;
}

#pragma scheduling invalid_target
int fn_802E4648(void *file) {
    /* FileDisk::write — DVD files are read-only, so panic with the file's path. */
    fn_802E317C(fileCdMsgWriteNotSupported, (char *)file + 0x40);
    return -1;
}
#pragma scheduling on
/* Return the current read position (FileDisk::cursor at offset 0x88) of the DVD file node. */
int fn_802E4680(void *file) {
    return *(int *)((char *)file + 0x88);
}

#pragma cplusplus on
/* FileDisk::seekRelative - seek to the file's cursor (+0x88) plus delta via virtual seek (slot +0x20). */
extern "C" void fn_802E4688(void *file, int delta) {
    int offset = *(int *)((char *)file + 0x88);
    ((Dummy_802E4688 *)file)->m6(offset + delta);
}
#pragma cplusplus off
/* FileDisk::flush (vtable slot 0x28) - a DVD file node is read-only and buffered
 * by the DVD services, so there is nothing for it to flush. */
void fn_802E46A0(void) {
}

