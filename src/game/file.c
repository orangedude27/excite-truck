// file.cpp — engine file API (FileFindNext/FileFindClose, file_id handling).
// Recovered TU window 0x802E321C..0x802E3DF8 (see docs/attribution_analysis.md):
// assert strings "file: ...". Static-init thunk fn_802E3DF0 (+ .ctors slot
// 0x802ED5F0) remains in auto/text_802E3DF0_.c pending a promotion pass.
#include <stdarg.h>
#include <string.h>
typedef signed long s32;
extern void fn_802E317C(const char *, ...);
extern char lbl_8034CF40[];
extern char lbl_8034CF60[];
extern char lbl_804DB810[];
extern char lbl_8055D1A0[];
extern s32 lbl_8055FF20;
extern s32 fn_802E321C(const char *);
extern s32 fn_802E3270(s32);
extern s32 fn_802E32C4(s32);
extern s32 lbl_8055FF18;
extern s32 lbl_8055FF1C;

extern char lbl_8034CFB4[];
extern char lbl_8034D000[];
extern s32 fn_802E33D8(s32, const char *, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 fn_802E98C8(void);
#pragma small_data on
__declspec(section ".sdata") extern char lbl_8055D1A0[];
__declspec(section ".sdata") extern char lbl_8055D1A8[];
/* Returns 1 when the path begins with the NAND prefix "nand:" (lbl_8055D1A0),
   0 otherwise; fn_802E32C4 then hands out the NAND file system handle
   lbl_8055FF20 for it.  Its sibling fn_802E3270 tests the "sd:" prefix. */
s32 fn_802E321C(const char *path) {
    /* the prefix address is held as an integer so the compiler keeps it in one
       callee-saved register instead of re-materializing the small-data address */
    s32 prefix = (s32)lbl_8055D1A0;
    s32 prefixLen = strlen((char *)prefix);
    s32 result = strncmp(path, (char *)prefix, prefixLen);
    return (unsigned int)__cntlzw(result) >> 5;
}

/* Returns 1 when the path begins with the SD-card prefix "sd:"
   (lbl_8055D1A8), 0 otherwise; fn_802E32C4 then hands out the SD-card file
   system handle lbl_8055FF24 for it.  Its sibling fn_802E321C tests the
   "nand:" prefix (lbl_8055D1A0). */
s32 fn_802E3270(s32 path) {
    /* the prefix address is held as an integer so the compiler keeps it in one
       callee-saved register instead of re-materializing the small-data address */
    s32 prefix = (s32)lbl_8055D1A8; /* "sd:" */
    s32 prefixLen = strlen((char *)prefix);
    s32 result = strncmp((const char *)path, (char *)prefix, prefixLen);
    return (unsigned int)__cntlzw(result) >> 5;
}

#pragma dont_inline on
/* Returns the file system handle for the given path: NAND (lbl_8055FF20) for
   paths matching the "nand:" prefix, SD card (lbl_8055FF24) for paths matching
   the "sd:" prefix, or 0 if no matching file system is available. */
s32 fn_802E32C4(s32 path) {
    if (path != 0 && fn_802E321C((const char *)path) != 0 && lbl_8055FF20 != 0) {
        return lbl_8055FF20;
    }
    if (path != 0 && fn_802E3270(path) != 0 && (s32)lbl_8055FF24 != 0) {
        return (s32)lbl_8055FF24;
    }
    return 0;
}
#pragma dont_inline reset
/* Return the file system picked by fn_802E32C4, or the default file system
   (lbl_8055FF18) when none is available. */
s32 *fn_802E333C(void) {
    s32 *fileSystem;
    fileSystem = (s32 *)((s32 (*)())fn_802E32C4)();
    if (fileSystem != 0) {
        return fileSystem;
    }
    return (s32 *)lbl_8055FF18;
}

/* Return the file system picked by fn_802E32C4, or the secondary file system (lbl_8055FF1C) when none is available. */
s32 *fn_802E336C(void) {
    s32 *fileSystem;
    fileSystem = (s32 *)((s32 (*)())fn_802E32C4)();
    if (fileSystem != 0) {
        return fileSystem;
    }
    return (s32 *)lbl_8055FF1C;
}

#pragma cplusplus on
extern "C" void fn_802E339C(void) {
    /* Resolve the default file-system object via fn_802E333C(0) and call its
       vtable method at offset 0x24 (slot 7), with no arguments. */
    class FileSystem {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
    };
    FileSystem *fileSystem = (FileSystem *)((s32 (*)(s32))fn_802E333C)(0);
    fileSystem->a7();
}
#pragma cplusplus off
/* FileCd vtable slot 0x24 (flush): a disc is read-only, so there is nothing to flush; report success. */
s32 fn_802E33D0(void) { return 0; }

#pragma scheduling invalid_target
/* Validate a file handle index and return the address of its entry in the file table, logging on invalid/unused cases. */
s32 fn_802E33D8(s32 fileId, const char *name, s32 line) {
    s32 offset;
    unsigned char *entry;
    if (fileId < 0 || fileId == -1 || fileId > 0x10) {
        fn_802E317C(lbl_8034CF40, fileId, name, line);
    }
    offset = fileId * 0x28;
    entry = (unsigned char *)(lbl_804DB810 + offset);
    if (entry[0x20] == 0) {
        fn_802E317C(lbl_8034CF60, fileId, entry, name, line);
    }
    return (s32)lbl_804DB810 + offset;
}
#pragma scheduling on
void fn_802E3498(void) {
    /* RealName: File_InitSubsystem (clears the open-file table and lazily creates the default DVD file-system object). */
#define sOpenFileTable lbl_804DB810
#define sDefaultFileSystem lbl_8055FF18
    memset((void *)((char *)sOpenFileTable + 0), 0, 0x280);
    if (sDefaultFileSystem == 0) {
        sDefaultFileSystem = fn_802E3F94();
    }
#undef sOpenFileTable
#undef sDefaultFileSystem
}

extern void fn_802E3550(void);
#pragma cplusplus on
/* Shut down file subsystems: close remaining open files, then destroy the
   primary (lbl_8055FF18) and secondary (lbl_8055FF1C) file-system objects. */
extern "C" void fn_802E34DC(void) {
    class FileSystem {
    public:
        virtual void destroy(s32);
    };
    s32 fileSystem;
    fn_802E3550();
    fileSystem = lbl_8055FF18;
    if (fileSystem != 0) {
        ((FileSystem *)fileSystem)->destroy(1);
    }
    lbl_8055FF18 = 0;
    fileSystem = lbl_8055FF1C;
    if (fileSystem != 0) {
        if (fileSystem != 0) {
            ((FileSystem *)fileSystem)->destroy(1);
        }
        lbl_8055FF1C = 0;
    }
}
#pragma cplusplus off
extern char lbl_8034CF80[];
#pragma scheduling invalid_target
void fn_802E3550(void) {
#define sOpenFileTable lbl_804DB810
#define sFileStillInUseMsg lbl_8034CF80
#define FilePanic fn_802E317C
    /* Scan the fixed 16-entry open-file table and report any entries still marked in use. */
    char *entry;
    s32 i;

    entry = sOpenFileTable;
    i = 0;
    do {
        if (((unsigned char *)entry)[0x20] != 0) {
            FilePanic(sFileStillInUseMsg, (s32)entry);
        }
        i++;
        entry += 0x28;
    } while (i < 16);
#undef sOpenFileTable
#undef sFileStillInUseMsg
#undef FilePanic
}
#pragma scheduling on
extern char lbl_8034CF98[];
s32 fn_802E35C0(const char *arg0, s32 arg1) {
    /* Allocate a free slot in the open-file table: copy the name, store the
     * associated handle, and return its index, or -1 if the table is full. */
    char *base;
    s32 offset;
    s32 index = 0;
    s32 handle = arg1;
    unsigned char *entry = (unsigned char *)lbl_804DB810;
    s32 remaining;
    for (remaining = 16; remaining != 0; remaining--) {
        if (entry[0x20] == 0) {
            offset = index * 0x28;
            base = lbl_804DB810;
            *(base + offset + 0x20) = 1;
            strncpy(base + offset, arg0, 0x20);
            *(s32 *)((u32)base + offset + 0x24) = handle;
            return index;
        }
        entry += 0x28;
        index++;
    }
    fn_802E317C(lbl_8034CF98, arg0);
    return -1;
}

#pragma dont_inline on
#pragma cplusplus on
extern "C" s32 fn_802E367C(s32 path) {
    /* Open/create the given path via the active file system and register the returned
       native handle in the open-file table, or return -1 if the open fails. */
    class FileSystem {
    public:
        virtual void v0();
        virtual s32 open(s32 path);
    };

    FileSystem *fileSystem = (FileSystem *)fn_802E333C();
    s32 nativeHandle = fileSystem->open(path);
    if (nativeHandle != 0)
        return fn_802E35C0((const char *)path, nativeHandle);
    return -1;
}
#pragma cplusplus on
extern "C" s32 fn_802E36D8(s32 pathOrName)
{
    /* Resolve path/name via the file manager's vtable method at slot 0x10 (3rd virtual),
     * then if it yields a handle/name token, pass it to fn_802E35C0; otherwise return -1. */
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual s32 c(s32);
    };
    V *fileManager = (V *)fn_802E333C();
    s32 lookupResult = fileManager->c(pathOrName);
    if (lookupResult != 0)
        return fn_802E35C0((const char *)pathOrName, lookupResult);
    return -1;
}
#pragma cplusplus on
extern "C" void fn_802E3734(s32 *handlePtr) {
    /* Close a file handle: look up its entry, destroy the associated object, clear state, and invalidate the handle. */
    class ObjectOwner {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void destroy(void *);
    };
    class FileObject {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
        virtual void a8();
        virtual ObjectOwner *getOwner();
    };
    s32 fileEntry = fn_802E33D8(*handlePtr, lbl_8034CFB4, 0xE4);
    FileObject *fileObject = *(FileObject **)((unsigned char *)fileEntry + 0x24);
    ObjectOwner *owner = fileObject->getOwner();
    owner->destroy(fileObject);
    *(void **)((unsigned char *)fileEntry + 0x24) = 0;
    *((unsigned char *)fileEntry + 0x20) = 0;
    *handlePtr = -1;
}
/* Look up the file object for the handle and invoke its vtable slot-4 method (no arguments) on the underlying stream. */
extern "C" void fn_802E37C4(s32 fileHandle) {
#define kFileSourceFile lbl_8034CFB4
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();              /* vtable slot +0x18 */
    };

    s32 fileEntry = fn_802E33D8(fileHandle, kFileSourceFile, 0x125);
    s32 fileObject = *(s32 *)(fileEntry + 0x24);
    ((Obj *)fileObject)->v4();
#undef kFileSourceFile
}

extern char lbl_8034CFC0[];

#pragma cplusplus on
extern "C" void fn_802E3898(s32, const char *, s32 *);
extern "C" void fn_802E3804(s32 arg0, const char *arg1, s32 arg2) {
    /* Read arg2 bytes from file handle arg0 into arg1 (file.cpp:0x130 context), and warn via fn_802E317C if the bytes read differ. */
    s32 fileEntry = fn_802E33D8(arg0, lbl_8034CFB4, 0x130);
    s32 bytesRead = arg2;
    fn_802E3898(arg0, arg1, &bytesRead);
    if (bytesRead != arg2) {
        fn_802E317C(lbl_8034CFC0, arg2, fileEntry);
    }
}
#pragma use_lmw_stmw off
#pragma cplusplus on
void fn_802E3898(s32 arg0, const char *arg1, s32 *arg2) {
    /* Reads up to *arg2 bytes into arg1 from the file handle's stream, updating *arg2 with bytes read or a negative error. */
    class V {
    public:
        virtual s32 f0(const char *, s32);
    };
    s32 obj;
    s32 total;
    s32 result;
    s32 entry;
    s32 count;

    obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x142);
    total = *arg2;
    result = 0;
    while (total > 0) {
        entry = *(s32 *)(obj + 0x24);
        count = ((V *)entry)->f0(arg1, total - result);
        if (count < 0) {
            result = count;
            break;
        }
        if (count <= 0) {
            break;
        }
        result += count;
        arg1 += count;
    }
    *arg2 = result;
}
#pragma use_lmw_stmw reset
extern "C" void fn_802E3930(s32 fileHandle, s32 offset, s32 whence) {
    /* Seek the stream for fileHandle to offset/whence via its vtable (file.cpp:0x15e). */
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2(int, int);
    };
    s32 fileObject = fn_802E33D8(fileHandle, lbl_8034CFB4, 0x15e);
    s32 stream = *(s32 *)(fileObject + 0x24);
    ((Obj *)stream)->v2(offset, whence);
}
#pragma cplusplus on
extern "C" void fn_802E3990(s32 fileHandle) {
    /* Look up the stream object for the file handle and invoke its no-argument
       vtable method at slot +0x14 (file.cpp:0x16c). */
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
    };
    s32 fileEntry = fn_802E33D8(fileHandle, lbl_8034CFB4, 0x16c);
    s32 fileObject = *(s32 *)(fileEntry + 0x24);
    ((Obj *)fileObject)->v3();
}
#pragma cplusplus off
/* Reads exactly `count` bytes from file `fileId` into `buffer`; returns nonzero on success. */
s32 fn_802E39D0(s32 fileId, s32 buffer, s32 count) {
    s32 bytesRead = count;
    fn_802E3898(fileId, (const char *)buffer, &bytesRead);
    return bytesRead == count;
}

#pragma cplusplus on
/* RealName: FileObject_SeekTo? (invokes file stream vtable method 8 with an offset). */
extern "C" void fn_802E3A14(s32 fileHandle, s32 offset) {
#define kFileSourceFile lbl_8034CFB4
    class FileStream {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v5();
        virtual void v4();
        virtual void Seek(s32 offset);
        virtual void v7();
        virtual void v6();
    };
    register int fileEntry = fn_802E33D8(fileHandle, kFileSourceFile, 0x1ab);
    s32 stream = *(s32 *)(fileEntry + 0x24);
    ((FileStream *)stream)->Seek(offset);
#undef kFileSourceFile
}
#pragma cplusplus on
/* Write `size` bytes from `buffer` via the file object's vtable method; return 1 if all bytes were written. */
extern "C" s32 fn_802E3A64(s32 fileHandle, s32 buffer, s32 size) {
    class Obj {
    public:
        virtual void v0();
        virtual s32 v1(s32, s32);
    };
    s32 fileObject = fn_802E33D8(fileHandle, lbl_8034CFB4, 0x1c3);
    s32 entry = *(s32 *)(fileObject + 0x24);
    s32 bytesWritten = ((Obj *)entry)->v1(buffer, size);
    return size == bytesWritten;
}
extern "C" int vsprintf(char *, const char *, va_list);
#pragma scheduling invalid_target
extern "C" void fn_802E3AD0(s32 arg0, const char *fmt, ...) {
#define FILESYSTEM_SINK (-0x29A)  /* route output to the default filesystem's v6 print instead of a file handle */
    /* Format `fmt` into a 0x400-byte buffer; write it to file handle `arg0`, or,
       for FILESYSTEM_SINK, to the default filesystem's v6(buf). */
    char buf[0x400];
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    if (arg0 != FILESYSTEM_SINK) {
        fn_802E3A64(arg0, (s32)buf, strlen(buf));
        return;
    }
    s32 *fileSystem = ((s32 *(*)(s32))fn_802E333C)(0);
    if (fileSystem != 0) {
        class Obj {
        public:
            virtual void v0();
            virtual void v1();
            virtual void v2();
            virtual void v3();
            virtual void v4();
            virtual void v5();
            virtual void v6(char *);
        };
        fileSystem = ((s32 *(*)(s32))fn_802E333C)(0);
        ((Obj *)fileSystem)->v6(buf);
    }
#undef FILESYSTEM_SINK
}
#pragma scheduling on
extern "C" s32 fn_802E3BB4(s32 arg0, s32 arg1, s32 arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual s32 v2(s32, s32, s32);
    };

    /* Call file-subsystem vtable slot 2 with (arg0, arg1, arg2); return -1 if unavailable. */
    s32 obj = ((s32 (*)(void))fn_802E339C)();
    s32 result;
    if (obj != 0) {
        result = ((Obj *)obj)->v2(arg0, arg1, arg2);
    } else {
        result = -1;
    }
    return result;
}

extern char lbl_8034CFE4[];
#pragma cplusplus on
/* Find the next file in an open directory iteration (vtable slot 5). Logs a
   "not supported" message and returns 0 if the file subsystem is unavailable. */
extern "C" s32 fn_802E3C24(s32 findHandle, s32 pathBuffer, s32 bufferSize) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual s32 v3(s32, s32, s32);
    };
    s32 fileSubsystem = ((s32 (*)(void))fn_802E339C)();
    s32 result;

    if (fileSubsystem != 0) {
        result = ((Obj *)fileSubsystem)->v3(findHandle, pathBuffer, bufferSize);
    } else {
        fn_802E317C(lbl_8034CFE4);
        result = 0;
    }
    return result;
}
#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
/* Close a file-find handle via the file subsystem (vtable slot 4); log if unsupported. */
extern "C" void fn_802E3CA4(s32 findHandle) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4(s32);
    };

    s32 fileSubsystem = ((s32 (*)(void))fn_802E339C)();
    if (fileSubsystem != 0) {
        ((Obj *)fileSubsystem)->v4(findHandle);
    } else {
        fn_802E317C(lbl_8034D000);
    }
}
#pragma cplusplus off

#pragma cplusplus off
/* No-op engine file-API hook: called at track-resource load (fn_8000A8C4) and
 * world teardown; this build needs no action. */
void fn_802E3D00(void) {
}

#pragma cplusplus on
extern "C" s32 fn_802E3D04(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual s32 c(s32);
    };
    V *obj = (V *)fn_802E336C();
    s32 result;

    /* Opens/looks up arg0 through the vtable method at slot +0x10 of the
     * object returned by fn_802E336C, registers the result via fn_802E35C0,
     * and returns that handle (or -1 on failure). */
    if (obj == 0) goto fail;
    result = obj->c(arg0);
    if (result == 0) goto fail;
    result = fn_802E35C0((const char *)arg0, result);
    goto done;
fail:
    result = -1;
done:
    return result;
}
#pragma cplusplus on
extern "C" s32 fn_802E3D68(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual s32 b(s32);
    };
    V *fileSystem = (V *)fn_802E336C();
    s32 handle;

    /* Opens/looks up arg0 through the vtable method at slot +0x0C of the
     * secondary file-system object returned by fn_802E336C, registers the
     * result via fn_802E35C0, and returns that handle (or -1 on failure). */
    if (fileSystem == 0) goto fail;
    handle = fileSystem->b(arg0);
    if (handle == 0) goto fail;
    handle = fn_802E35C0((const char *)arg0, handle);
    goto done;
fail:
    handle = -1;
done:
    return handle;
}
#pragma cplusplus off
/* Initialize the SD-card file system handle (lbl_8055FF24) from the mount stub fn_802E98C8, which returns 0 in this build. */
void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}

