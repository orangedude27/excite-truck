// file.cpp — engine file API (FileFindNext/FileFindClose, file_id handling).
// Recovered TU window 0x802E321C..0x802E3DF8 (see docs/attribution_analysis.md):
// assert strings "file: ...". Static-init thunk fn_802E3DF0 (+ .ctors slot
// 0x802ED5F0) remains in auto/text_802E3DF0_.c pending a promotion pass.
#include <stdarg.h>
#include <string.h>
typedef signed long s32;
extern void Abend_Panic(const char *, ...);
extern char lbl_8034CF40[];
extern char lbl_8034CF60[];
extern char gOpenFileTable[];
extern char sNandPathPrefix[];
extern s32 lbl_8055FF20;
extern s32 IsNandPath(const char *);
extern s32 IsSdPath(s32);
extern s32 getFileSystemForPath(s32);
extern s32 gDefaultFileSystem;
extern s32 gSecondaryFileSystem;

extern char kFileSourceName[];
extern char lbl_8034D000[];
extern s32 fn_802E33D8(s32, const char *, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 ConfigGetSDCardHandle(void);
#pragma small_data on
__declspec(section ".sdata") extern char sNandPathPrefix[];
__declspec(section ".sdata") extern char sSdPathPrefix[];
/* Return 1 when path starts with the "nand:" prefix (sNandPathPrefix), else 0. The prefix address is held as an integer so MWCC keeps it in one callee-saved register across the strlen/strncmp calls instead of reloading the small-data address. */
/* Returns 1 when path begins with the NAND prefix "nand:" (sNandPathPrefix), else 0; same equality trick as IsSdPath. */ s32 IsNandPath(const char *path) {
    s32 prefix = (s32)sNandPathPrefix;
    s32 prefixLen = strlen((char *)prefix);
    s32 result = strncmp(path, (char *)prefix, prefixLen);
    return (unsigned int)__cntlzw(result) >> 5;
}

/* Returns 1 when the path begins with the SD-card prefix "sd:"
   (sSdPathPrefix), 0 otherwise; getFileSystemForPath then hands out the SD-card file
   system handle lbl_8055FF24 for it.  Its sibling IsNandPath tests the
   "nand:" prefix (sNandPathPrefix). */
/* Returns 1 when path begins with the SD-card prefix "sd:" (sSdPathPrefix), else 0. */ s32 IsSdPath(s32 path) {
    /* Hold the prefix address as an integer so MWCC keeps its small-data
       address in one callee-saved register instead of rematerializing it. */
    s32 prefix = (s32)sSdPathPrefix;
    s32 prefixLen = strlen((char *)prefix);
    s32 result = strncmp((const char *)path, (char *)prefix, prefixLen);
    /* cntlzw is 32 only when result == 0, so >>5 yields the equality flag. */
    return (unsigned int)__cntlzw(result) >> 5;
}

#pragma dont_inline on
/* Returns the file system handle for the given path: NAND (lbl_8055FF20) for
   paths matching the "nand:" prefix, SD card (lbl_8055FF24) for paths matching
   the "sd:" prefix, or 0 if no matching file system is available. */
/* Return the NAND or SD-card file-system handle selected by the path prefix, or 0 when none matches. */ s32 getFileSystemForPath(s32 path) {
    if (path != 0 && IsNandPath((const char *)path) != 0 && lbl_8055FF20 != 0) {
        return lbl_8055FF20;
    }
    if (path != 0 && IsSdPath(path) != 0 && (s32)lbl_8055FF24 != 0) {
        return (s32)lbl_8055FF24;
    }
    return 0;
}
#pragma dont_inline reset
/* Return the file system picked by getFileSystemForPath, or the default file system
   (gDefaultFileSystem) when none is available. */
s32 *GetDefaultFileSystem(void) {
    s32 *fileSystem;
    fileSystem = (s32 *)((s32 (*)())getFileSystemForPath)();
    if (fileSystem != 0) {
        return fileSystem;
    }
    return (s32 *)gDefaultFileSystem;
}

/* Return the file system picked by getFileSystemForPath, or the secondary file system (gSecondaryFileSystem) when none is available. */
s32 *GetSecondaryFileSystem(void) {
    s32 *fileSystem;
    fileSystem = (s32 *)((s32 (*)())getFileSystemForPath)();
    if (fileSystem != 0) {
        return fileSystem;
    }
    return (s32 *)gSecondaryFileSystem;
}

#pragma cplusplus on
extern "C" void FileFind_GetSubsystem(void) {
    /* Return the file-find subsystem handle of the default file system: resolve it
     * through GetDefaultFileSystem(0), then dispatch vtable slot 7 (offset 0x24),
     * whose result is passed straight back in r3. */
    class FileSystem {
    public:
        virtual void reserved0();
        virtual void reserved1();
        virtual void reserved2();
        virtual void reserved3();
        virtual void reserved4();
        virtual void reserved5();
        virtual void reserved6();
        virtual void getSubsystem();
    };
    FileSystem *fileSystem = (FileSystem *)((s32 (*)(s32))GetDefaultFileSystem)(0);
    fileSystem->getSubsystem();
}
#pragma cplusplus off
/* No-op flush for the read-only FileCd vtable (slot 0x24); always reports success. */
s32 FileCd_flush(void) { return 0; }

#pragma scheduling invalid_target
/* Validate a file-handle id (panic if out of range or its table entry is marked unused) and return the address of that entry in the file table. */
s32 fn_802E33D8(s32 fileId, const char *name, s32 line) {
    s32 entryOffset;
    unsigned char *entry;
    if (fileId < 0 || fileId == -1 || fileId > 0x10) {
        Abend_Panic(lbl_8034CF40, fileId, name, line);
    }
    entryOffset = fileId * 0x28;
    entry = (unsigned char *)(gOpenFileTable + entryOffset);
    if (entry[0x20] == 0) {
        Abend_Panic(lbl_8034CF60, fileId, entry, name, line);
    }
    return (s32)gOpenFileTable + entryOffset;
}
#pragma scheduling on
/* Initialize the file subsystem: clear the open-file table and lazily create the default DVD file-system object. */ /* Initialize the file subsystem: clear the open-file table and lazily create the default DVD file-system object. */ void fn_802E3498(void) {
    /* RealName: File_InitSubsystem (clears the open-file table and lazily creates the default DVD file-system object). */
#define sOpenFileTable gOpenFileTable
#define sDefaultFileSystem gDefaultFileSystem
    memset((void *)((char *)sOpenFileTable + 0), 0, 0x280);
    if (sDefaultFileSystem == 0) {
        sDefaultFileSystem = fn_802E3F94();
    }
#undef sOpenFileTable
#undef sDefaultFileSystem
}

extern void File_checkOpenFiles(void);
#pragma cplusplus on
/* Shuts down the file subsystem: aborts on any open file, then destroys and clears the default and secondary file-system objects. */
extern "C" void File_ShutdownSubsystem(void) {
    class FileSystem {
    public:
        virtual void destroy(s32);
    };
    s32 fileSystem;
    File_checkOpenFiles();
    fileSystem = gDefaultFileSystem;
    if (fileSystem != 0) {
        ((FileSystem *)fileSystem)->destroy(1);
    }
    gDefaultFileSystem = 0;
    fileSystem = gSecondaryFileSystem;
    if (fileSystem != 0) {
        if (fileSystem != 0) {
            ((FileSystem *)fileSystem)->destroy(1);
        }
        gSecondaryFileSystem = 0;
    }
}
#pragma cplusplus off
extern char gFileStillInUseMsg[];
#pragma scheduling invalid_target
/* Panics if any of the 16 open-file table entries is still in use. */
void File_checkOpenFiles(void) {
    char *entry;
    s32 i;

    entry = gOpenFileTable;
    i = 0;
    do {
        if (((unsigned char *)entry)[0x20] != 0) {
            Abend_Panic(gFileStillInUseMsg, (s32)entry);
        }
        i++;
        entry += 0x28;
    } while (i < 16);
}
#pragma scheduling on
extern char lbl_8034CF98[];
/* AllocFileSlot: find a free slot in the open-file table, store the name and handle there, and return its index (or -1/panic if full). */ s32 AllocOpenFileSlot(const char *name, s32 fileHandle) {
    /* Allocate a free slot in the open-file table: copy the name, store the
     * associated handle, and return its index, or -1 if the table is full. */
    char *tableBase;
    s32 entryOffset;
    s32 slotIndex = 0;
    s32 handleValue = fileHandle;
    unsigned char *scan = (unsigned char *)gOpenFileTable;
    s32 slotsLeft;
    for (slotsLeft = 16; slotsLeft != 0; slotsLeft--) {
        if (scan[0x20] == 0) {
            entryOffset = slotIndex * 0x28;
            tableBase = gOpenFileTable;
            *(tableBase + entryOffset + 0x20) = 1;
            strncpy(tableBase + entryOffset, name, 0x20);
            *(s32 *)((u32)tableBase + entryOffset + 0x24) = handleValue;
            return slotIndex;
        }
        scan += 0x28;
        slotIndex++;
    }
    Abend_Panic(lbl_8034CF98, name);
    return -1;
}

#pragma dont_inline on
#pragma cplusplus on
/* Open/create the given path via the active file system and register the returned
   native handle in the open-file table, or return -1 if the open fails. */
extern "C" s32 File_Open(s32 path) {
    class FileSystem {
    public:
        virtual void v0();
        virtual s32 open(s32 path);
    };

    FileSystem *fileSystem = (FileSystem *)GetDefaultFileSystem();
    s32 nativeHandle = fileSystem->open(path);
    if (nativeHandle != 0)
        return AllocOpenFileSlot((const char *)path, nativeHandle);
    return -1;
}
#pragma cplusplus on
extern "C" s32 FileLookup(s32 path) {
    /* Look up a path through the default file system (vtable slot 0x10) and register
       the returned handle in the open-file table, or return -1 on failure. */
    class FileSystem {
    public:
        virtual void reserved0();
        virtual void reserved1();
        virtual s32 lookup(s32);
    };
    FileSystem *fileSystem = (FileSystem *)GetDefaultFileSystem();
    s32 handle = fileSystem->lookup(path);
    if (handle != 0)
        return AllocOpenFileSlot((const char *)path, handle);
    return -1;
}
#pragma cplusplus on
/* Close a file handle: validate it to get its file-table entry, ask the file object for its owner and destroy it through the owner's virtual destroy, then clear the entry's object and in-use fields and set the handle to -1. */ extern "C" void fn_802E3734(s32 *handlePtr) {
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
    s32 fileEntry = fn_802E33D8(*handlePtr, kFileSourceName, 0xE4);
    FileObject *fileObject = *(FileObject **)((unsigned char *)fileEntry + 0x24);
    ObjectOwner *owner = fileObject->getOwner();
    owner->destroy(fileObject);
    *(void **)((unsigned char *)fileEntry + 0x24) = 0;
    *((unsigned char *)fileEntry + 0x20) = 0;
    *handlePtr = -1;
}
/* File API (the caller's File_size): validate the handle, take the stream object
 * stored in its open-file-table entry and dispatch vtable slot +0x18 to return
 * the size of the open file. */
/* File API (the caller's File_size): validate the handle, take the stream object in its open-file-table entry and dispatch vtable slot +0x18 to return the open file's size. */ extern "C" void fn_802E37C4(s32 fileHandle) {
#define kFileSourceFile kFileSourceName
    class Obj {
    public:
        virtual void reserved0();
        virtual void reserved1();
        virtual void reserved2();
        virtual void reserved3();
        virtual void getSize();         /* vtable slot +0x18 */
    };

    s32 fileEntry = fn_802E33D8(fileHandle, kFileSourceFile, 0x125);
    s32 fileObject = *(s32 *)(fileEntry + 0x24);
    ((Obj *)fileObject)->getSize();
#undef kFileSourceFile
}

extern char lbl_8034CFC0[];

#pragma cplusplus on
extern "C" void fn_802E3898(s32, const char *, s32 *);
/* Read byteCount bytes from file handle fileId into buffer: validate the handle, read via fn_802E3898, and warn through Abend_Panic if the bytes read differ from the request. */ extern "C" void fn_802E3804(s32 fileId, const char *buffer, s32 byteCount) {
    /* Read arg2 bytes from file handle arg0 into arg1 (file.cpp:0x130 context), and warn via Abend_Panic if the bytes read differ. */
    s32 fileEntry = fn_802E33D8(fileId, kFileSourceName, 0x130);
    s32 bytesRead = byteCount;
    fn_802E3898(fileId, buffer, &bytesRead);
    if (bytesRead != byteCount) {
        Abend_Panic(lbl_8034CFC0, byteCount, fileEntry);
    }
}
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Read up to *countPtr bytes from the file handle's stream into buffer, looping until the request is filled or the stream ends; write the total bytes read (or a negative read error) back through countPtr. */ void fn_802E3898(s32 fileId, const char *buffer, s32 *countPtr) {
    /* Reads up to *arg2 bytes into arg1 from the file handle's stream, updating *arg2 with bytes read or a negative error. */
    class V {
    public:
        virtual s32 f0(const char *, s32);
    };
    s32 fileEntry;
    s32 bytesToRead;
    s32 bytesRead;
    s32 stream;
    s32 justRead;

    fileEntry = fn_802E33D8(fileId, kFileSourceName, 0x142);
    bytesToRead = *countPtr;
    bytesRead = 0;
    while (bytesToRead > 0) {
        stream = *(s32 *)(fileEntry + 0x24);
        justRead = ((V *)stream)->f0(buffer, bytesToRead - bytesRead);
        if (justRead < 0) {
            bytesRead = justRead;
            break;
        }
        if (justRead <= 0) {
            break;
        }
        bytesRead += justRead;
        buffer += justRead;
    }
    *countPtr = bytesRead;
}
#pragma use_lmw_stmw reset
extern "C" void File_read(s32 fileHandle, s32 buffer, s32 byteCount) {
    /* Read byteCount bytes from the file handle's stream into buffer via its vtable (file.cpp:0x15e). */
    class FileStream {
    public:
        virtual void v0();
        virtual void v1();
        virtual void read(int, int);
    };
    s32 fileEntry = fn_802E33D8(fileHandle, kFileSourceName, 0x15e);
    s32 stream = *(s32 *)(fileEntry + 0x24);
    ((FileStream *)stream)->read(buffer, byteCount);
}
#pragma cplusplus on
/* Look up the open-file entry for fileHandle and call the stream object's vtable method at +0x14 (slot 3), e.g. closing/flushing the stream. */ extern "C" void fn_802E3990(s32 fileHandle) {
    /* Look up the stream object for the file handle and invoke its no-argument
       vtable method at slot +0x14 (file.cpp:0x16c). */
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
    };
    s32 fileEntry = fn_802E33D8(fileHandle, kFileSourceName, 0x16c);
    s32 fileObject = *(s32 *)(fileEntry + 0x24);
    ((Obj *)fileObject)->v3();
}
#pragma cplusplus off
/* Read exactly count bytes from file handle fileId into buffer; return 1 only if the full request was satisfied. */
s32 fn_802E39D0(s32 fileId, s32 buffer, s32 count) {
    s32 bytesRead = count;
    fn_802E3898(fileId, (const char *)buffer, &bytesRead);
    return bytesRead == count;
}

#pragma cplusplus on
/* Seek an open file's stream to a byte offset: validate the handle, fetch its
   stream object and invoke the stream's virtual Seek method. */
extern "C" void fn_802E3A14(s32 fileHandle, s32 offset) {
#define kFileSourceFile kFileSourceName
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
    register int fileObject = fn_802E33D8(fileHandle, kFileSourceFile, 0x1ab);
    s32 stream = *(s32 *)(fileObject + 0x24);
    ((FileStream *)stream)->Seek(offset);
#undef kFileSourceFile
}
#pragma cplusplus on
/* Write exactly `size` bytes from `buffer` to the open file `fileHandle`; return 1 only when all bytes were written. */
extern "C" s32 File_writeExact(s32 fileHandle, s32 buffer, s32 size) {
    class FileStream {
    public:
        virtual void v0();
        virtual s32 write(s32, s32);
    };
    s32 fileEntry = fn_802E33D8(fileHandle, kFileSourceName, 0x1c3);
    s32 stream = *(s32 *)(fileEntry + 0x24);
    s32 bytesWritten = ((FileStream *)stream)->write(buffer, size);
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
        File_writeExact(arg0, (s32)buf, strlen(buf));
        return;
    }
    s32 *fileSystem = ((s32 *(*)(s32))GetDefaultFileSystem)(0);
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
        fileSystem = ((s32 *(*)(s32))GetDefaultFileSystem)(0);
        ((Obj *)fileSystem)->v6(buf);
    }
#undef FILESYSTEM_SINK
}
#pragma scheduling on
extern "C" s32 FileFindFirst(s32 path, s32 buffer, s32 bufferSize) {
    class FileFindSubsystem {
    public:
        virtual void reserved0();
        virtual void reserved1();
        virtual s32 findFirst(s32, s32, s32);
    };

    /* Start a directory search: ask the file-find subsystem for the first entry
       matching path into buffer (bufferSize bytes), returning its find handle or -1. */
    s32 subsystem = ((s32 (*)(void))FileFind_GetSubsystem)();
    s32 result;
    if (subsystem != 0) {
        result = ((FileFindSubsystem *)subsystem)->findFirst(path, buffer, bufferSize);
    } else {
        result = -1;
    }
    return result;
}

extern char lbl_8034CFE4[];
#pragma cplusplus on
/* FileFindNext: advance an open directory search through the file subsystem
   (vtable slot 5), returning the native result or 0 with a "not supported"
   log when no subsystem is available. */
extern "C" s32 fn_802E3C24(s32 findHandle, s32 pathBuffer, s32 bufferSize) {
    class FileSystem {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual s32 findNext(s32, s32, s32);
    };
    s32 fileSubsystem = ((s32 (*)(void))FileFind_GetSubsystem)();
    s32 result;

    if (fileSubsystem != 0) {
        result = ((FileSystem *)fileSubsystem)->findNext(findHandle, pathBuffer, bufferSize);
    } else {
        Abend_Panic(lbl_8034CFE4);
        result = 0;
    }
    return result;
}
#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
/* Close an open directory-search handle through the file-find subsystem's close
   method (vtable slot 4); panic with "not supported" if no subsystem is available. */
extern "C" void FileFind_Close(s32 findHandle) {
    class FileFindSubsystem {
    public:
        virtual void reserved0();
        virtual void reserved1();
        virtual void reserved2();
        virtual void reserved3();
        virtual void close(s32 findHandle);
    };

    s32 fileSubsystem = ((s32 (*)(void))FileFind_GetSubsystem)();
    if (fileSubsystem != 0) {
        ((FileFindSubsystem *)fileSubsystem)->close(findHandle);
    } else {
        Abend_Panic(lbl_8034D000);
    }
}
#pragma cplusplus off

#pragma cplusplus off
/* No-op engine file-API hook: called at track-resource load (fn_8000A8C4) and
 * world teardown; this build needs no action. */
void fn_802E3D00(void) {
}

#pragma cplusplus on
/* Open a file by name through the secondary file system: ask its vtable method at slot 0x10 for a native handle, register it in the open-file table, and return the new file handle index (or -1 on failure). */
extern "C" s32 FileLookupSecondary(s32 path) {
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual s32 c(s32);
    };
    V *fileSystem = (V *)GetSecondaryFileSystem();
    s32 handle;

    if (fileSystem == 0) goto fail;
    handle = fileSystem->c(path);
    if (handle == 0) goto fail;
    handle = AllocOpenFileSlot((const char *)path, handle);
    goto done;
fail:
    handle = -1;
done:
    return handle;
}
#pragma cplusplus on
extern "C" s32 FileOpenSecondary(s32 path) {
    class FileSystem {
    public:
        virtual void reserved0();
        virtual s32 open(s32 path);
    };
    FileSystem *fileSystem = (FileSystem *)GetSecondaryFileSystem();
    s32 handle;

    /* Open a path through the secondary file system and register the native
     * handle in the open-file table, returning its slot or -1 on failure. */
    if (fileSystem == 0) goto fail;
    handle = fileSystem->open(path);
    if (handle == 0) goto fail;
    handle = AllocOpenFileSlot((const char *)path, handle);
    goto done;
fail:
    handle = -1;
done:
    return handle;
}
#pragma cplusplus off
/* Initialize the SD-card file system handle (lbl_8055FF24) from the mount stub ConfigGetSDCardHandle, which returns 0 in this build. */
void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)ConfigGetSDCardHandle();
}

