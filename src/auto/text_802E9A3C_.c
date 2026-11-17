extern void *lbl_80560078;
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_80560060;
extern char lbl_8052E658[0x610];
extern int lbl_80560090;
extern char lbl_805600D0;
extern char lbl_805600D1;
extern float lbl_805651C4;
extern float lbl_8055D270;
extern int fn_802E622C(int, float);
extern int fn_802E61E4(int, float);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_805600C8;
extern void *lbl_80560080;
extern int fn_802EBD40(void);
extern long lbl_80507600[];
extern char lbl_8034E9C8[];
__declspec(section ".rodata") extern long lbl_8034E9B0;
extern long fn_800B7BDC(long);
/* The game's MP3 stream source, the one object at lbl_80507600.  It plays
 * either from a VF file (fn_802E9A6C installs vtable lbl_8034E9B0) or from a
 * block of memory (fn_802E9A3C installs lbl_8034E9C8); the four virtual slots
 * are close/destroy, seek, size and read(dst, size). */
typedef struct {
    long *vtable; /* 0x00 lbl_8034E9B0 (file) or lbl_8034E9C8 (memory) */
    long file;    /* 0x04 VFFile handle, or the buffer to play from */
    long size;    /* 0x08 file size; the buffer's read position */
    long length;  /* 0x0C the buffer's size */
} Mp3Stream;
#define mp3StreamFile_vtable lbl_8034E9B0 /* the file-backed stream's vtable */
#define mp3StreamOpen        lbl_80560060 /* 1 while a stream is set up */
#define gMp3AbortRequested   lbl_805600C8 /* 1 until the current track has aborted */
#define VFCloseFile          fn_800B7BDC  /* VF close; 0 on success */
extern char lbl_8055D278;
extern char lbl_8055D280;
__declspec(section ".rodata") extern long lbl_8034E260;
extern long jumptable_8034E2F8[];
extern int OSReport(const char *, ...);
extern char lbl_8034E370[];
extern char lbl_80560061;
extern int lbl_80560068;
extern int lbl_805600A0;
extern int lbl_805600A4;
extern int lbl_805600B8;
extern char lbl_80560062;
extern char lbl_80560063;
extern char lbl_8034E95C[];
extern char lbl_8034E980[];
extern int fn_802E2C20(void);
extern long fn_802E30C8(char *, long);
#pragma push
#pragma scheduling invalid_target
/* Install the memory-backed MP3 stream vtable and buffer, mark the stream open, and return it. */
long *fn_802E9A3C(long buffer, long length) {
    Mp3Stream *stream = (Mp3Stream *)lbl_80507600;
    mp3StreamOpen = 1;
    if (stream != 0) {
        stream->file = buffer;
        stream->vtable = (long *)&lbl_8034E9C8;
        stream->length = length;
    }
    return (long *)stream;
}
#pragma scheduling on
#pragma pop
extern char lbl_8055D258;
extern long fn_800B7C34(long, void *);
extern long fn_800B7C08(long, long *);
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
/* Open an MP3 stream handle by id/path, populate info, or log and clean up on failure. */
extern "C" long *fn_802E9A6C(long arg0) {
    extern long fn_802E30C8(char *, long);
    class Obj {
    public:
        virtual void f(int);
    };
    long info[8];
    register long *obj;

    obj = lbl_80507600;
    lbl_80560060 = 1;
    if (obj != 0) {
        obj[0] = (long)&lbl_8034E9B0;
        obj[1] = fn_800B7C34(arg0, &lbl_8055D258);
        obj[2] = 0;
        if (obj[1] != 0) {
            if (fn_800B7C08(obj[1], info) == 0) obj[2] = info[0];
            else {
                ((long (*)(char *, ...))fn_802E30C8)((char *)&lbl_8034E260, arg0);
                fn_800B7BDC(obj[1]);
                obj[1] = 0;
            }
        }
    }
    if (obj[1] != 0) return obj;
    if (obj != 0) ((Obj *)obj)->f(1);
    return 0;
}
#pragma cplusplus reset
#pragma pop
/* Deleting destructor of the file-backed MP3 stream -- slot 0x8 of vtable
 * lbl_8034E9B0, which fn_802E9BCC calls as destroy(1) when the stream is torn
 * down.  It installs the destructor's vtable, closes the VF file the stream
 * plays from, and clears the "stream open" flag when the delete flag is set;
 * the stream is the static object at lbl_80507600, so there is nothing to
 * free here. */
void *fn_802E9B54(Mp3Stream *stream, long deleteFlag) {
    long file;
    if (stream != 0) {
        file = stream->file;
        stream->vtable = &mp3StreamFile_vtable;
        if (file != 0) {
            VFCloseFile(file);
            stream->file = 0;
        }
        if (deleteFlag > 0) mp3StreamOpen = 0;
    }
    return stream;
}

#pragma push
#pragma cplusplus on
// Calls the deleting destructor (vtable slot 0x8, delete flag 1) on a polymorphic object, if non-null.
extern "C" void fn_802E9BCC(void *obj) {
    class Destroyable {
    public:
        virtual void destroy(int);
    };
    if (obj == 0) return;
    ((Destroyable *)obj)->destroy(1);
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma scheduling invalid_target
/* Returns the name of an MP3 decoder error code, for log messages
 * ("NO_ERR", "SYNC_ERR", ... or "???" for codes it doesn't know). */
void *fn_802E9BEC(long errorCode) {
#define mp3Strings   lbl_8034E260 /* the mp3 module's string block */
#define strNoError   lbl_8055D278 /* "NO_ERR" */
#define strUnknown   lbl_8055D280 /* "???" */
    char *strings = (char *)&mp3Strings;
    switch (errorCode) {
    case 0: return &strNoError;
    case 8: return strings + 0x2C;   /* "SYNC_ERR" */
    case 14: return strings + 0x38;  /* "LAYER_ERR" */
    case 15: return strings + 0x44;  /* "BITRATE_ERR" */
    case 16: return strings + 0x50;  /* "SFREQ_ERR" */
    case 17: return strings + 0x5C;  /* "BLOCKTYPE_ERR" */
    case 18: return strings + 0x6C;  /* "TABLE_SEL_ERR" */
    case 19: return strings + 0x7C;  /* "LENGTH_ERR" */
    case -10: return strings + 0x88; /* "BYTES_DISC_ERR" */
    default: return &strUnknown;
    }
#undef strUnknown
#undef strNoError
#undef mp3Strings
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_802E9C68(long slot) {
    /* SD card insert callback: log insertion and flag the card present. */
    #define kMp3SdInsertedFmt lbl_8034E370
    #define gSdCardPresent    lbl_80560061
    #define gSdInsertCount    lbl_80560068

    OSReport((const char *)&kMp3SdInsertedFmt, slot);
    *(volatile char *)&gSdCardPresent = 1;
    ++*(volatile int *)&gSdInsertCount;

    #undef kMp3SdInsertedFmt
    #undef gSdCardPresent
    #undef gSdInsertCount
}
#pragma scheduling on
#pragma pop
extern char lbl_8034E390[];
extern char lbl_8034E3E0[];
extern char lbl_8034E3F0[];
extern char lbl_805076B8[];
extern int lbl_8056007C;
extern void *lbl_8055D274;
extern char lbl_8055D2A4;
extern int fn_800B7E5C(signed char, int);
extern int fn_800B7B34(signed char);
extern int fn_802EA5D4(void *, int);
#pragma push
#pragma scheduling invalid_target
/* RealName: Mp3SdCardRemovedCallback_802E9CAC */
void fn_802E9CAC(int eventArg) {
    /* Log SD card removal, clear the ready flag, and bump the callback counter. */
    OSReport((const char *)&lbl_8034E390, eventArg);
    *(volatile char *)&lbl_80560061 = 0;
    ++*(volatile int *)&lbl_80560068;
}
#pragma scheduling on
#pragma pop
extern long fn_800B7CE8(long, void *, void *);
extern long fn_800B7DB0(long, void (*)(long), void (*)(int));
extern long fn_800B7968(long, long, long, void *);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma scheduling invalid_target
void fn_802E9CF0(void) {
    char *strings = (char *)&lbl_8034E260;
    char *base = (char *)lbl_80507600;
    char *config = base + 0xC4;
    char *state;
    *(void *volatile *)(base + 0xC4) = base + 0xD8;
    *(void *volatile *)(config + 4) = base + 0x218;
    state = base + 0xB8;
    *(volatile short *)(config + 8) = 4;
    *(volatile short *)(config + 10) = 4;
    *(volatile long *)(config + 12) = 1;
    *(void *volatile *)(state + 4) = config;
    if (fn_800B7CE8(0x20000, state, config) != 0)
        fn_802E317C(strings + 0x14C);
    if (fn_800B7DB0(0, fn_802E9C68, fn_802E9CAC) != 0)
        fn_802E317C(strings + 0x15C);
    if (fn_800B7968(0, 0, 0, base + 0xB8) != 0)
        fn_802E317C(strings + 0x170);
    {
        char *last = base + 0xB8;
        lbl_80560061 = ((volatile unsigned char *)last)[9] >> 4 & 1;
    }
}

#pragma dont_inline on
void fn_802E9DDC(void) {
    /* Report SD card unmount/detach failures for the active card slot. */
    #define sFAUnmountFailMsg lbl_8034E3E0
    #define sFADetachFailMsg lbl_8034E3F0
    #define gCardStatus lbl_805076B8
    #define CardCheckUnmountError fn_800B7E5C
    #define CardCheckDetachError fn_800B7B34
    #define AbendReport fn_802E30C8
    #define PanicAbort fn_802E317C
    if (CardCheckUnmountError((signed char)gCardStatus[8], 1) != 0) {
        ((long (*)(char *, ...))AbendReport)((char *)&sFAUnmountFailMsg);
    }
    if (CardCheckDetachError((signed char)*(gCardStatus + 8)) != 0) {
        PanicAbort((const char *)&sFADetachFailMsg);
    }
    #undef sFAUnmountFailMsg
    #undef sFADetachFailMsg
    #undef gCardStatus
    #undef CardCheckUnmountError
    #undef CardCheckDetachError
    #undef AbendReport
    #undef PanicAbort
}
#pragma dont_inline reset

#pragma pop
extern char lbl_80560061, lbl_8055D2A4;
#pragma push
#pragma scheduling invalid_target
void fn_802E9E54(unsigned char *dst, unsigned char *src, int count) {
    unsigned char next;
    goto check;
body:
    if (*src < 0x80) {
        unsigned char ch = *(volatile unsigned char *)src;
        count--;
        src++;
        *dst = ch;
        dst++;
        goto check;
    }
    src++;
    next = *(volatile unsigned char *)src;
    count--;
    *dst++ = 0x3F;
    switch ((signed char)next) {
    case 0: goto check;
    default: src++; break;
    }
check:
    if (count <= 1) goto done;
    if ((signed char)*src != 0) goto body;
done:
    *dst = 0;
}

void fn_802E9EB8(void) {
    extern int OSTryLockMutex(void *);
    extern void OSUnlockMutex(void *);
    extern int lbl_80560070;
    extern int lbl_80560074;
    extern int lbl_8056007C;
    extern int lbl_805600CC;
    extern char lbl_805600C9;
    extern float lbl_805651BC, lbl_805651C0, lbl_805651C8, lbl_805651CC, lbl_805651D0;
    extern void fn_802E620C(int, float);
    extern void fn_802E61BC(int);
    extern char lbl_805600D2;
    extern char lbl_805584A0;
    extern char lbl_80508818[];
    extern char lbl_805600D1;
    extern int lbl_8055D264;
    extern int lbl_8055D260;

    if (lbl_805600D2 != 0) {
        ((long (*)(char *, long))fn_802E30C8)((char *)&lbl_8034E260 + 0x1A0, 0);
        fn_802E61BC((&lbl_80560090)[0]);
        fn_802E61BC((&lbl_80560090)[1]);
        lbl_805600D2 = 0;
    }

    if (OSTryLockMutex(&lbl_805584A0) != 0) {
        int changed;
        if (lbl_80560070 != lbl_80560074) {
            lbl_80560074 = lbl_80560070;
            changed = 1;
        } else {
            changed = 0;
        }
        if (changed != 0) {
            int count = lbl_8056007C;
            *(int *)&lbl_80560080 = count;
            if (count > 0) {
                int i = 0;
                char *src = lbl_80508818;
                char *dst = lbl_8052E658;
                for (; i < count; i++) {
                    int j;
                    for (j = 0; j < 0x610; j++) dst[j] = src[j];
                    src += 0x610;
                    dst += 0x610;
                }
            }
            ((long (*)(char *, long))fn_802E30C8)((char *)&lbl_8034E260 + 0x1CC, 0);
            {
                int i;
                for (i = 0; i < *(int *)&lbl_80560080; i++) {
                    ((long (*)(char *, long, char *))fn_802E30C8)((char *)&lbl_8034E260 + 0x1DC, i, lbl_8052E658 + i * 0x610 + 0x408);
                }
            }
        }
        OSUnlockMutex(&lbl_805584A0);
    }

    if (lbl_805600D1 == 0 && lbl_8055D264 != lbl_8055D260) {
    }

    {
        float f30;
        if (lbl_805600C9 != 0) {
            int now = fn_802E2C20();
            int delta = now - lbl_805600CC;
            float t = (lbl_805651BC * (float)delta - lbl_805651C4) / lbl_805651C8;
            if (lbl_805651C0 >= t) ; else t = lbl_805651C0;
            if (t <= lbl_805651C4) t = lbl_805651C4;
            f30 = lbl_805651C0 + t * lbl_805651CC;
        } else {
            f30 = lbl_805651C0;
        }
        {
            int i;
            float vol;
            int en = 0;
            if (lbl_805600D0 != 0 && lbl_805600D1 == 0) en = 1;
            vol = en ? lbl_8055D270 * f30 : lbl_805651C4;
            for (i = 0; i < 2; i++) {
                fn_802E61E4((&lbl_80560090)[i], vol);
                fn_802E620C((&lbl_80560090)[i], lbl_805651D0);
            }
        }
    }
}

#pragma use_lmw_stmw off
// Scans a directory (and up to maxDepth-1 levels below it) for .mp3 files,
// appending each one to the song table lbl_80508818 -- 100 entries of 0x610:
// the directory it was found in (0x200), its file name (0x208) and that name
// with every non-ASCII byte replaced by '?' (0x208). lbl_8056007C counts them.
int fn_802EA5D4(void *dirPath, int maxDepth) {
    extern void fn_801345D8(char *, long, const char *, ...);
    extern int fn_800B7C90(char *, int, char *);
    extern int fn_800B7CBC(char *);
    extern char *fn_80029004(char *, int);
    extern int strcmp(const char *, const char *);
    extern int stricmp(const char *, const char *);
    extern unsigned long strlen(const char *);
    extern char *strncpy(char *, const char *, unsigned long);
    extern char lbl_8055D284, lbl_8055D28C, lbl_8055D290, lbl_8055D294, lbl_8055D29C;
    extern char lbl_80508818[];
    char pattern[0x100];
    char childPath[0x200];
    char findData[0x448];
    char *strings = (char *)&lbl_8034E260;
    char *baseName;
    char *entryName;
    char *ext;
    char *destEntry;
    int result;

    fn_801345D8(pattern, 0x100, &lbl_8055D284, (char *)dirPath);
    result = fn_800B7C90(pattern, 0x71, findData);
    if (result == 0) {
        baseName = findData + 0x22D;
        do {
            if (lbl_8056007C < 100) {
                entryName = findData + 0x22D;
                if (findData[0x23A] != 0) entryName = findData + 0x23A;
                if ((findData[0x22C] & 0x10) && maxDepth > 0) {
                    if (*entryName != 0 && strcmp(entryName, &lbl_8055D28C) != 0 && strcmp(entryName, &lbl_8055D290) != 0) {
                        if (strlen(baseName) + strlen((char *)dirPath) + 1 < 0x200) {
                            fn_801345D8(childPath, 0x200, &lbl_8055D294, (char *)dirPath, baseName);
                            fn_802EA5D4(childPath, maxDepth - 1);
                        } else {
                            ((long (*)(char *, ...))fn_802E30C8)(strings + 0x230);
                        }
                    }
                } else if ((ext = fn_80029004(entryName, 0x2E)) != 0 && stricmp(ext, &lbl_8055D29C) == 0) {
                    destEntry = lbl_80508818 + lbl_8056007C * 0x610;
                    if (strlen(findData + 0x22D) < 0x208 && strlen((char *)dirPath) < 0x200) {
                        strncpy(destEntry + 0x200, findData + 0x22D, 0x207);
                        destEntry[0x407] = 0;
                        fn_802E9E54((unsigned char *)(destEntry + 0x408), (unsigned char *)entryName, 0x208);
                        strncpy(destEntry, (char *)dirPath, 0x1FF);
                        destEntry[0x1FF] = 0;
                        lbl_8056007C++;
                    } else {
                        ((long (*)(char *, ...))fn_802E30C8)(strings + 0x250);
                    }
                }
            } else {
                return OSReport(strings + 0x268);
            }
        } while ((result = fn_800B7CBC(findData)) == 0);
    }
    return result;
}
/* Rebuild the list of playable songs: empty the song table's count and, while an
 * SD card is in, scan the directory the game was pointed at (no recursion).  If
 * that holds no .mp3 at all, search the default music folder 8 levels deep. */
void fn_802EA7E0(void) {
    #define songCount         lbl_8056007C /* songs in the table lbl_80508818 */
    #define sdCardPresent     lbl_80560061 /* set by the SD mount/attach callbacks */
    #define musicDirPath      lbl_8055D274 /* directory to look in first */
    #define defaultMusicDir   lbl_8055D2A4 /* 0x20-byte path, searched recursively */
    #define ScanSongDirectory fn_802EA5D4

    songCount = 0;
    if ((unsigned char)sdCardPresent != 0) {
        ScanSongDirectory(musicDirPath, 0);
        if (songCount == 0) ScanSongDirectory(&defaultMusicDir, 8);
    }

    #undef songCount
    #undef sdCardPresent
    #undef musicDirPath
    #undef defaultMusicDir
    #undef ScanSongDirectory
}

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma cplusplus on
extern "C" long *fn_802EA834(long arg0, long *arg1) {
    extern char lbl_8055D294;
    extern char lbl_8055D2A4;
    extern void fn_801345D8(char *, long, const char *, ...);
    extern void OSSleepTicks(unsigned long long);
    extern char *strncpy(char *, const char *, unsigned long);
    class Obj {
    public:
        virtual void d0();
        virtual void d1();
        virtual long callback();
    };
    char buffer[0x410];
    register long *result;
    register char *messageBase;
    register char *globalBase;
    long selector = arg0;
    long index;
    long *table;
    char *base;
    register char *copy;
    register char *destination;

    result = 0;
    globalBase = (char *)lbl_80507600;
    messageBase = (char *)&lbl_8034E260;
    if (selector <= -2) {
        index = -2 - selector;
        if ((index >= 0) && (index < 3)) {
            table = (long *)(globalBase + 0xA0);
            if (table[index * 2] != 0) {
                result = fn_802E9A3C(table[index * 2], table[index * 2 + 1]);
            }
        }
        if (result != 0) {
            destination = strncpy(globalBase + 0x40, &lbl_8055D2A4, 0x1F);
            destination[0x1F] = 0;
        }
    } else {
        arg0 *= 0x610;
        base = globalBase + 0x1218;
        base += arg0;
        copy = base + 0x200;
        fn_801345D8(buffer, 0x40A, &lbl_8055D294, base, copy);
        ((long (*)(char *, ...))fn_802E30C8)(messageBase + 0x280, buffer);
        result = fn_802E9A6C((long)buffer);
        ((long (*)(char *, ...))fn_802E30C8)(messageBase + 0x290, buffer, result);
        if (result != 0) {
            ((long (*)(char *, ...))fn_802E30C8)(messageBase + 0x2A0, buffer, ((Obj *)result)->callback());
            destination = strncpy(globalBase + 0x40, copy, 0x1F);
            destination[0x1F] = 0;
        } else {
            ((long (*)(char *, ...))fn_802E30C8)(messageBase + 0x2BC, buffer);
        }
    }
    if (result != 0) {
        *arg1 = ((Obj *)result)->callback();
    } else {
        ((long (*)(char *, ...))fn_802E30C8)(messageBase + 0x2D8, selector);
        if ((unsigned char)lbl_80560062 != 0) {
            ((void (*)(int, int))OSSleepTicks)(0,
                (((*(volatile unsigned int *)0x800000F8) >> 2) / 1000) * 1000);
        }
    }
    return result;
}
#pragma cplusplus reset
#pragma dont_inline reset
#pragma scheduling on
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_802EAA08(void) {
    if (lbl_805600B8 >= lbl_805600A4) {
        memcpy((void *)lbl_805600A0, (void *)(lbl_805600A0 + lbl_805600A4), (unsigned int)lbl_805600B8 - (unsigned int)lbl_805600A4);
        lbl_805600B8 -= lbl_805600A4;
    }
}
#pragma scheduling on
#pragma pop
int fn_802EAA58(int *arg0, int arg1) {
    int sizeOk;
    int channelOk;
    int channels;
    int valid;
    int rateOk;
    int result;
    int rate;
    int size;
    if (arg1 != 0) {
        switch (arg0[1]) {
        case 11025: case 22050: case 44100: break;
        default: return 0;
        }
    }
    channels = arg0[2];
    result = 0;
    valid = 0;
    channelOk = 1;
    if (channels != 1 && channels != 2) channelOk = 0;
    if (channelOk) {
        rate = arg0[1];
        rateOk = 0;
        if (rate >= 8000 && rate <= 60000) rateOk = 1;
        if (rateOk) valid = 1;
    }
    if (valid) {
        size = arg0[4];
        sizeOk = 0;
        if (size != 0 && (unsigned int)size <= 0x1200) sizeOk = 1;
        if (sizeOk) result = 1;
    }
    return result;
}

#pragma push
#pragma dont_inline on
void fn_802EAB28(void) {
    struct NodeVT { void *a, *b, *c; long (*seek)(void *, long); long (*size)(void *); long (*read)(void *, char *, long); };
    struct NodeObj { struct NodeVT *vt; };
    extern int OSReport(const char *, ...);
    extern void OSSleepTicks(unsigned long long);
    extern void OSLockMutex(void *);
    extern void OSUnlockMutex(void *);
    extern void fn_802EA7E0(void);
    extern int fn_802E2C20(void);
    extern void fn_802E9BCC(void *);
    extern void *fn_802E9BEC(long);
    extern void fn_802EAA08(void);
    extern int fn_802EAA58(int *, int);
    extern void fn_800C3D9C(long);
    extern long fn_802E30C8(char *, long);
    extern long *fn_802EA834(long, long *);
    extern long fn_800C3CDC(void *, long, long, long);
    extern void fn_800BEDE0(long, void *);
    extern long fn_800BDF4C(long, long, void *, long, long, long *, long);
    extern int strncmp(const char *, const char *, unsigned long);
    extern char *strncpy(char *, const char *, unsigned long);
    extern void *memset(void *, int, int);
    extern char lbl_80507640[];
    extern char lbl_805587E0[];
    extern char lbl_805584A0;
    extern char lbl_8055D2A8[], lbl_8055D2AC[], lbl_8055D2B0[], lbl_8055D2B4[], lbl_8055D2B8[], lbl_8055D2BC[], lbl_8055D2C4[], lbl_8055D2CC[];
    extern int lbl_8055D25C, lbl_8055D260, lbl_8055D264, lbl_8055D268, lbl_8055D26C;
    extern int lbl_80560070, lbl_80560098, lbl_8056009C, lbl_805600A8, lbl_805600AC, lbl_805600B0, lbl_805600BC, lbl_805600C0, lbl_805600CC;
    extern char lbl_805600C9;
    char *base;
    void *curNode;
    long consumed;
    char *msgBuf, *cmdBuf;
    long off, retries;
    unsigned int *tb;
    long zero;
    int *audioStatus;
    long sp8;
    int info[5];
    unsigned char flag;
    base = (char *)&lbl_8034E260;
    OSReport(base + 0x2f4);
    curNode = 0;
    consumed = 0;
    flag = 0;
    msgBuf = lbl_80507640;
    cmdBuf = lbl_805587E0;
    off = 0;
    retries = 0;
    tb = (unsigned int *)0x80000000;
    audioStatus = &lbl_805600C0;
    zero = 0;
    sp8 = 0;
    for (;;) {
        long taken, r15, r21, r22, r24, r25, r26, r27, r28;
        if (flag) {
            ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 + (((*tb >> 2) / 250) & 0x0FFFFFFC));
            flag = 0;
        } else {
            ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 * 50);
        }
        OSLockMutex(&lbl_805584A0);
        if (lbl_80560068 != *(int *)((char *)&lbl_80560068 + 4)) {
            *(int *)((char *)&lbl_80560068 + 4) = lbl_80560068;
            taken = 1;
        } else taken = 0;
        if (taken != 0) {
            if (lbl_80560098 != 0) { fn_800C3D9C(lbl_80560098); lbl_80560098 = zero; }
            if (curNode != 0) { fn_802E9BCC(curNode); curNode = 0; }
            fn_802EA7E0();
            lbl_80560070++;
            lbl_805600C9 = zero;
        }
        if (curNode == 0 && *(int *)&lbl_80560078 != -1 && *(int *)&lbl_80560078 < lbl_8056007C) {
            void *node;
            consumed = 0;
            node = fn_802EA834(0, &consumed);
            curNode = node;
            retries = 0;
            if (node != 0) {
                struct NodeObj *n = (struct NodeObj *)node;
                long sz = n->vt->size(n);
                if (n->vt->seek(n, sz - 0x80) != 0) {
                    if (n->vt->read(n, cmdBuf, 0x80) != 0) {
                        if (strncmp(cmdBuf, lbl_8055D2A8, 3) == 0) {
                            strncpy(msgBuf, cmdBuf + 3, 0x1e);
                            msgBuf[0x1e] = zero;
                            strncpy(msgBuf + 0x20, cmdBuf + 0x21, 0x1e);
                            msgBuf[0x3e] = zero;
                            strncpy(msgBuf + 0x40, cmdBuf + 0x3f, 0x1e);
                            msgBuf[0x5e] = zero;
                        }
                    }
                }
            }
            lbl_80560078 = (void *)-1;
        }
        if ((unsigned char)lbl_805600C8 != 0) {
            if ((unsigned char)lbl_805600C9 == 0) {
                lbl_805600CC = fn_802E2C20();
                lbl_805600C9 = 1;
            }
            if (curNode != 0) off = consumed;
            ((long (*)(char *, ...))fn_802E30C8)(base + 0x310);
            if (curNode == 0) {
                lbl_805600C8 = zero;
                ((long (*)(char *, ...))fn_802E30C8)(base + 0x330);
            }
        }
        if (curNode != 0) {
            unsigned char *buf = (unsigned char *)lbl_805600A8;
            long chunk = consumed - off;
            if (chunk < 0x780) ((long (*)(char *, ...))fn_802E30C8)(base + 0x360);
            r28 = lbl_805600AC;
            if (r28 > chunk) { } else r28 = chunk;
            r27 = 1;
            if (off >= consumed) {
                r27 = 1;
                ((long (*)(char *, ...))fn_802E30C8)(base + 0x384);
            } else {
                struct NodeObj *n = (struct NodeObj *)curNode;
                if (n->vt->seek(curNode, off) != 0) {
                    if (n->vt->read(curNode, (char *)buf, r28) != 0) {
                        r27 = 0;
                        r21 = 0;
                        r15 = 0;
                        if (lbl_80560098 == 0 && strncmp((char *)buf, lbl_8055D2AC, 3) == 0) {
                            unsigned short field;
                            r26 = (buf[8] << 7) + (buf[7] << 14) + buf[9] + (buf[6] << 21) + 0xa;
                            field = (buf[4] & ~0xFF00) | ((buf[3] << 8) & 0xFF00);
                            if (r26 < r28) {
                                r25 = 0xa;
                                if (field >= 0x200 && field <= 0x2ff) {
                                    for (;;) {
                                        unsigned char *fr;
                                        long len;
                                        if (r25 + 6 >= r28) break;
                                        if (buf[r25] == 0) break;
                                        fr = buf + r25;
                                        len = fr[5] + (fr[4] << 7) + (fr[3] << 14) + 6;
                                        if ((signed char)buf[r25] == 0x54) {
                                            char *v = (char *)fr + 7;
                                            if (strncmp((char *)fr, lbl_8055D2B0, 3) == 0) { strncpy(msgBuf, v, 0x1f); msgBuf[0x1f] = zero; }
                                            else if (strncmp((char *)fr, lbl_8055D2B4, 3) == 0) { strncpy(msgBuf + 0x20, v, 0x1f); msgBuf[0x3f] = zero; }
                                            else if (strncmp((char *)fr, lbl_8055D2B8, 3) == 0) { strncpy(msgBuf + 0x40, v, 0x1f); msgBuf[0x5f] = zero; }
                                        }
                                        r25 += len;
                                        if (len == 0) break;
                                    }
                                } else if (field >= 0x300 && field <= 0x3ff) {
                                    for (;;) {
                                        unsigned char *fr;
                                        long len, szf, max;
                                        if (r25 + 0xa >= r28) break;
                                        if (buf[r25] == 0) break;
                                        fr = buf + r25;
                                        szf = (fr[6] << 7) + (fr[5] << 14) + fr[7] + (fr[4] << 21);
                                        len = szf + 0xa;
                                        if ((signed char)fr[0] == 0x54 && szf - 1 > 0) {
                                            char *v = (char *)fr + 0xb;
                                            max = szf - 1;
                                            if (max >= 0x20) max = 0x1f;
                                            if (strncmp((char *)fr, lbl_8055D2BC, 4) == 0) { strncpy(msgBuf, v, max); msgBuf[max] = zero; }
                                            if (strncmp((char *)fr, lbl_8055D2C4, 4) == 0) { strncpy(msgBuf + 0x20, v, max); msgBuf[0x20 + max] = zero; }
                                            if (strncmp((char *)fr, lbl_8055D2CC, 4) == 0) { strncpy(msgBuf + 0x40, v, max); msgBuf[0x40 + max] = zero; }
                                        }
                                        r25 += len;
                                        if (len == 0) break;
                                    }
                                } else {
                                    ((long (*)(char *, ...))fn_802E30C8)(base + 0x398, (unsigned short)field);
                                }
                                r21 = r26;
                            } else {
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x3b4, (unsigned short)r26, r28);
                            }
                            off += r26;
                            r15 = 1;
                        }
                        if (r15 == 0) {
                            long found = 0, i = 0;
                            unsigned char *p = buf;
                            for (;;) {
                                long bound = r28 > 0x400 ? 0x400 : r28;
                                if (i >= bound) break;
                                if (p[0] == 0xff && (p[1] & 0xe0) == 0xe0) {
                                    if (i != 0) ((long (*)(char *, ...))fn_802E30C8)(base + 0x3e0, (unsigned short)i);
                                    r21 = i;
                                    off += i;
                                    found = 1;
                                    break;
                                }
                                i++;
                                p++;
                            }
                            if (found == 0) ((long (*)(char *, ...))fn_802E30C8)(base + 0x408);
                        }
                        if (lbl_80560098 == 0) {
                            if (r15 == 0) {
                                lbl_80560098 = fn_800C3CDC(buf + r21, r28 - r21, lbl_8056009C, 0xED80);
                                if (lbl_80560098 == 0) {
                                    ((long (*)(char *, ...))fn_802E30C8)(base + 0x420);
                                    r27 = 1;
                                }
                            }
                            if (lbl_80560098 != 0) {
                                memset(info, 0, 0x14);
                                fn_800BEDE0(lbl_80560098, info);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x438, info[0]);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x450, info[1]);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x460, info[2]);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x474, info[3]);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x484, info[4]);
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x494, 4);
                                if (fn_802EAA58(info, retries > 0) == 0) {
                                    fn_800C3D9C(lbl_80560098);
                                    retries++;
                                    lbl_80560098 = zero;
                                    if (retries > 0x10) {
                                        ((long (*)(char *, ...))fn_802E30C8)(base + 0x4a8);
                                        r27 = 1;
                                        ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 * 100);
                                    } else {
                                        ((long (*)(char *, ...))fn_802E30C8)(base + 0x4d0, retries);
                                        off += 0x780;
                                        ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 * 30);
                                    }
                                }
                            }
                        }
                        if (lbl_80560098 != 0) {
                            lbl_8055D25C = info[1];
                            lbl_8055D268 = info[2];
                            if (lbl_8055D25C != lbl_8055D260 || lbl_8055D268 != lbl_8055D26C || (unsigned char)lbl_805600C9 != 0) {
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x504);
                                while (*(audioStatus + 1) < 4 && (unsigned char)lbl_805600D1 == 0 && (unsigned char)lbl_805600D0 != 0) {
                                    ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 + (((*tb >> 2) / 250) & 0x0FFFFFFC));
                                }
                                lbl_8055D26C = lbl_8055D268;
                                lbl_8055D264 = lbl_8055D25C;
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x528);
                                while (lbl_8055D260 != lbl_8055D264 && (unsigned char)lbl_805600D1 == 0 && (unsigned char)lbl_805600D0 != 0) {
                                    ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 + (((*tb >> 2) / 250) & 0x0FFFFFFC));
                                }
                                ((long (*)(char *, ...))fn_802E30C8)(base + 0x54c);
                                ((void (*)(int, int))OSSleepTicks)(0, (*tb >> 2) / 1000 * 50);
                                lbl_805600C9 = zero;
                            }
                            sp8 = 0;
                            r22 = lbl_805600B0;
                            while (r21 + 1 <= r28) {
                                long avail, sync2, j;
                                if (lbl_805600B8 < r22) avail = r22 - lbl_805600B8;
                                else avail = lbl_805600A4 - (lbl_805600B8 - r22);
                                if (avail >= info[4] * 2) {
                                    sync2 = -1;
                                    j = 0;
                                    for (;;) {
                                        unsigned char *pp;
                                        long bound = r28 > 0x400 ? 0x400 : r28;
                                        if (j >= bound) break;
                                        pp = buf + r21 + j;
                                        if (pp[0] == 0xff && (pp[1] & 0xe0) == 0xe0) {
                                            if (j != 0) ((long (*)(char *, ...))fn_802E30C8)(base + 0x570, j, buf[r21], buf[r21 + 1], buf[r21 + 2], buf[r21 + 3]);
                                            sync2 = j;
                                            r21 += j;
                                            off += j;
                                            break;
                                        }
                                        j++;
                                    }
                                    if (sync2 < 0) ((long (*)(char *, ...))fn_802E30C8)(base + 0x408);
                                    if (sync2 <= 0) {
                                        long res = fn_800BDF4C(lbl_80560098, lbl_805600A0 + lbl_805600B8, buf + r21, 0x780, info[4], &sp8, 0);
                                        if (res == 0) {
                                            lbl_805600B8 += info[4];
                                            off += sp8;
                                            r21 += sp8;
                                            flag = 1;
                                            fn_802EAA08();
                                            continue;
                                        }
                                        retries++;
                                        ((long (*)(char *, ...))fn_802E30C8)(base + 0x5a0, res, fn_802E9BEC(res), sp8);
                                        if (sp8 == 0 || retries > 0x1e) {
                                            r27 = 1;
                                        } else {
                                            off += sp8;
                                            r21 += sp8;
                                            lbl_805600B8 += info[4];
                                            flag = 1;
                                            fn_802EAA08();
                                            continue;
                                        }
                                    } else {
                                        continue;
                                    }
                                }
                                break;
                            }
                            if (lbl_805600B8 <= r22) lbl_805600BC = lbl_805600A4 - (r22 - lbl_805600B8);
                            else lbl_805600BC = lbl_805600B8 - r22;
                        } else {
                            lbl_805600BC = zero;
                        }
                    }
                }
            }
            if (off >= consumed) {
                ((long (*)(char *, ...))fn_802E30C8)(base + 0x5f0);
                r27 = 1;
            }
            if (r27 != 0) {
                ((long (*)(char *, ...))fn_802E30C8)(base + 0x610);
                if (lbl_80560098 != 0) { fn_800C3D9C(lbl_80560098); lbl_80560098 = zero; }
                if (curNode != 0) {
                    fn_802E9BCC(curNode);
                    ((long (*)(char *, ...))fn_802E30C8)(base + 0x624);
                    curNode = 0;
                }
                memset(msgBuf, 0, 0x60);
            }
            if ((unsigned char)lbl_805600C8 != 0 && curNode == 0 && lbl_80560098 == 0) {
                ((long (*)(char *, ...))fn_802E30C8)(base + 0x634);
                lbl_805600C8 = zero;
            }
        }
        OSUnlockMutex(&lbl_805584A0);
        if ((unsigned char)lbl_80560062 == 0) break;
    }
    if (curNode != 0) fn_802E9BCC(curNode);
    lbl_80560063 = 1;
}
#pragma pop
extern int lbl_805600B0;
extern int lbl_805600C0;
extern int lbl_8055D26C;
extern void *memset(void *, int, int);
#pragma use_lmw_stmw off
int fn_802EB7D4(void *arg0, int arg1, int arg2) {
    int idx = arg2 * 4;
    int elem = lbl_8055D26C;
    if (*(volatile int *)((char *)&lbl_805600B0 + idx) == lbl_805600B8) {
        memset(arg0, 0, arg1);
        *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
        goto done;
    }
    if (*(volatile int *)((char *)&lbl_805600B0 + idx) < lbl_805600B8) {
        int bytes = arg1 * elem;
        int rem = lbl_805600B8 - *(volatile int *)((char *)&lbl_805600B0 + idx);
        int avail = bytes < rem ? bytes : rem;
        if (avail < bytes && *(int *)((char *)&lbl_805600C0 + idx) != 0) {
            memset(arg0, 0, arg1);
            *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
            goto done;
        }
        {
            int count = avail / (elem * 2);
            int i;
            unsigned short *dst = (unsigned short *)arg0;
            unsigned short *src;
            *(int *)((char *)&lbl_805600C0 + idx) = 0;
            src = (unsigned short *)(lbl_805600A0 + *(volatile int *)((char *)&lbl_805600B0 + idx));
            if (elem == 2) {
                for (i = 0; i < count; i++) dst[i] = src[i * 2 + arg2];
            } else {
                for (i = 0; i < count; i++) dst[i] = src[i];
            }
            *(volatile int *)((char *)&lbl_805600B0 + idx) = *(volatile int *)((char *)&lbl_805600B0 + idx) + avail;
            if (*(volatile int *)((char *)&lbl_805600B0 + idx) >= lbl_805600A4) *(volatile int *)((char *)&lbl_805600B0 + idx) = 0;
            goto done;
        }
    } else {
        int bytes = arg1 * elem;
        int rem = lbl_805600A4 - *(volatile int *)((char *)&lbl_805600B0 + idx);
        int avail = bytes < rem ? bytes : rem;
        if (avail < bytes && *(int *)((char *)&lbl_805600C0 + idx) != 0) {
            memset(arg0, 0, arg1);
            *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
            goto done;
        }
        {
            int count = avail / (elem * 2);
            int countBytes = avail / elem;
            int i;
            unsigned short *dst = (unsigned short *)arg0;
            unsigned short *src;
            *(int *)((char *)&lbl_805600C0 + idx) = 0;
            src = (unsigned short *)(lbl_805600A0 + *(volatile int *)((char *)&lbl_805600B0 + idx));
            if (elem == 2) {
                for (i = 0; i < count; i++) dst[i] = src[i * 2 + arg2];
            } else {
                for (i = 0; i < count; i++) dst[i] = src[i];
            }
            *(volatile int *)((char *)&lbl_805600B0 + idx) = *(volatile int *)((char *)&lbl_805600B0 + idx) + avail;
            if (*(volatile int *)((char *)&lbl_805600B0 + idx) >= lbl_805600A4) {
                *(volatile int *)((char *)&lbl_805600B0 + idx) = 0;
                if (arg1 > countBytes) {
                    fn_802EB7D4((char *)arg0 + countBytes, arg1 - countBytes, arg2);
                }
            }
            goto done;
        }
    }
done:
    return arg1;
}
int fn_802EBD40(void) {
    extern void OSSleepTicks(unsigned long long);
    register char *base;
    register unsigned int multiplier;
    register int elapsed;
    register unsigned int *tb;
    unsigned int clock;
    base = (char *)&lbl_8034E260;
    lbl_80560062 = 0;
    ((void (*)(char *, ...))fn_802E30C8)(base + 0x65C);
    multiplier = 0x10624DD3;
    elapsed = 0;
    tb = (unsigned int *)0x80000000;
    while ((unsigned char)lbl_80560063 == 0) {
        clock = tb[0x3E] >> 2;
        ((void (*)(int, int))OSSleepTicks)(0, (clock / 1000) + ((clock / 250) & 0x0FFFFFFC));
        elapsed += 5;
        if (elapsed > 0x3E8) {
            ((void (*)(char *, ...))fn_802E30C8)(base + 0x67C);
            break;
        }
    }
    ((void (*)(char *, ...))fn_802E30C8)(base + 0x6A8);
}
#pragma dont_inline reset
#pragma scheduling on

int fn_802EBE00(int request) {
#define KERNEL_RESET_NOTIFY 1
#define mp3WaitForAck fn_802EBD40
    /* Reset callback registered in fn_802EBE2C: when the reset is actually on,
     * run the MP3 routine that waits for the stream to acknowledge
     * (lbl_80560063), logging status and timing out after a few seconds. */
    if (request == KERNEL_RESET_NOTIFY) {
        mp3WaitForAck();
    }
    return 0;
#undef mp3WaitForAck
#undef KERNEL_RESET_NOTIFY
}

void fn_802EBE2C(void) {
    extern int lbl_8055D25C, lbl_8055D260, lbl_8055D264, lbl_80560088, lbl_8056009C, lbl_805600A8, lbl_805600AC, lbl_805600B0;
    extern char lbl_8055D2D8, lbl_8055D2E0, lbl_8055D2E8, lbl_805584A0, lbl_805584B8, lbl_805544A0;
    extern float lbl_805651C0, lbl_805651CC;
    extern void *fn_8012850C(int, void *);
    extern int fn_802E5DD8();
    extern int fn_802E6058();
    extern void fn_802E61EC(int, float);
    extern void fn_802E61BC(int);
    extern void OSInitMutex(void *);
    extern void fn_802E3DCC(void);
    extern int OSCreateThread();
    extern void fn_802E2E0C();
    extern void OSResumeThread(void *);
    extern void fn_80127C90();
    extern int fn_802EB7D4();
    extern void fn_802EAB28(void);
    extern void fn_802E9EB8(void);
    int i, off, h;
    float f;

    lbl_8055D260 = -1;
    lbl_8055D264 = 0xAC44;
    lbl_80560078 = (void *)-1;
    lbl_8055D25C = lbl_8055D264;
    lbl_8056009C = (int)fn_8012850C(0xED80, (char *)&lbl_8034E260 + 0x6BC);
    lbl_805600A4 = 0x47FC0;
    fn_802E30C8((char *)&lbl_8034E260 + 0x6C8, lbl_805600A4 / 1024);
    lbl_805600A0 = (int)fn_8012850C((lbl_805600A4 + 0x1200) * 2 - (lbl_805600A4 + 0x1200), &lbl_8055D2D8);
    lbl_805600AC = 0x1E000;
    lbl_805600A8 = (int)fn_8012850C(lbl_805600AC * 2 - lbl_805600AC, &lbl_8055D2E0);
    lbl_805600B8 = 0x2400;
    i = 0;
    off = 0;
    do {
        *(int *)((char *)&lbl_805600B0 + off) = 0;
        *(int *)((char *)&lbl_80560088 + off) = fn_802E5DD8(&lbl_8055D2E8, 0x7FF8, 0, fn_802EB7D4, i);
        *(int *)((char *)&lbl_80560090 + off) = fn_802E6058();
        if (i == 0) f = lbl_805651CC; else f = lbl_805651C0;
        fn_802E61EC(*(int *)((char *)&lbl_80560090 + off), f);
        i++;
        off += 4;
    } while (i < 2);
    i = 0;
    off = 0;
    do {
        fn_802E61E4(*(int *)((char *)&lbl_80560090 + off), lbl_805651C4);
        fn_802E622C(*(int *)((char *)&lbl_80560090 + off), lbl_805651C4);
        fn_802E61BC(*(int *)((char *)&lbl_80560090 + off));
        i++;
        off += 4;
    } while (i < 2);
    off = 0;
    lbl_805600D0 = 0;
    OSInitMutex(&lbl_805584A0);
    fn_802E9CF0();
    fn_802E3DCC();
    lbl_80560062 = 1;
    lbl_80560063 = off;
    if (OSCreateThread(&lbl_805584B8, fn_802EAB28, 0, &lbl_805544A0 + 0x3FE0, 0x3FE0, 14, 1) == 0) {
        fn_802E317C((char *)&lbl_8034E260 + 0x6E0);
    }
    fn_802E2E0C(fn_802EBE00, &lbl_8055D2E8);
    OSResumeThread(&lbl_805584B8);
    fn_80127C90(fn_802E9EB8, &lbl_8055D2E8);
}

extern int lbl_80560088, lbl_8056009C, lbl_805600A8;
extern void fn_802E61D8(int);
extern void fn_802E6138(int);
extern void fn_802E5FE4(int);
extern void fn_802E9EB8(void);
extern void fn_80127D58(void (*)(void));
extern void fn_802E9DDC(void);
extern void fn_80128670(int);
void fn_802EC038(void) {
    /* Shuts down two audio/SPU slots (releasing active handles and clearing slot pointers), then unregisters/tears down subsystems and frees global buffers. */
    int *slotHandle;
    int *slotState;
    int i;
    slotHandle = &lbl_80560090;
    slotState = &lbl_80560088;
    i = 0;
    do {
        if (*slotHandle != 0) {
            fn_802E61D8(*slotHandle);
            fn_802E6138(*slotHandle);
        }
        *slotHandle = 0;
        fn_802E5FE4(*slotState);
        i++;
        *slotState = 0;
        slotHandle++;
        slotState++;
    } while (i < 2);
    fn_80127D58(fn_802E9EB8);
    fn_802EBD40();
    fn_802E9DDC();
    fn_80128670(lbl_8056009C);
    lbl_8056009C = 0;
    fn_80128670(lbl_805600A0);
    lbl_805600A0 = 0;
    fn_80128670(lbl_805600A8);
    lbl_805600A8 = 0;
}

/* Get the number of music tracks found by the last music dash (lbl_80560080). */
void* fn_802EC0FC(void) {
    return lbl_80560080;
}

/* Returns the music-file path stored at +0x408 of scanned music entry
 * `index` (each entry of lbl_8052E658 is 0x610 bytes). */
char *fn_802EC104(int index) {
    return lbl_8052E658 + index * 0x610 + 0x408;
}

/* Request a track-music song: publish its index to the global the audio thread
 * picks up (lbl_80560078, -1 = no pending request). */
void fn_802EC11C(void *songIndex) {
    #define gPendingSong lbl_80560078
    gPendingSong = songIndex;
    #undef gPendingSong
}

extern void *lbl_80560078;
void* fn_802EC124(void) {
#define gPendingSong lbl_80560078
    /* Get the pending track-music song index the audio thread picks up (-1 = none). */
    return gPendingSong;
#undef gPendingSong
}

/* Clear the pending track-music song request: reset the song index the audio
 * thread picks up (lbl_80560078, -1 = no request) back to -1. */
void fn_802EC12C(void) {
#define gPendingSong lbl_80560078
    gPendingSong = (void*)-1;
#undef gPendingSong
}

#pragma dont_inline fn_802EC138
/* Mark the sound/music state as enabled (lbl_805600D0). On the first enable,
   while that flag was still clear, also set lbl_805600D1 — the pending-start
   flag the mixer uses to hold the volume at its default until it is cleared. */
void fn_802EC138(void) {
    if ((unsigned char)lbl_805600D0 == 0) {
        lbl_805600D1 = 1;
    }
    lbl_805600D0 = 1;
}

/* Clear the sound/music state flags and reset each of the two sound handles to
   the default volume. */
void fn_802EC158(void) {
    int *handle;
    int index;

    lbl_805600D0 = 0;
    lbl_805600D1 = 0;
    handle = &lbl_80560090;
    index = 0;
    do {
        fn_802E622C(*handle, lbl_805651C4);
        fn_802E61E4(*handle, lbl_805651C4);
        index++;
        handle++;
    } while (index < 2);
}

#pragma push
#pragma dont_inline on
void fn_802EC1C0(float volume) {
    /* Store the master sound volume in lbl_8055D270. If sound/music is already
       enabled (lbl_805600D0), re-run the enable helper so the new volume takes effect. */
    lbl_8055D270 = volume;
    if ((unsigned char)lbl_805600D0 != 0) {
        fn_802EC138();
    }
}
#pragma dont_inline reset
#pragma pop
/* Request an abort of the current MP3 track: set when the song changes, then
 * polled by fn_802EC1E4 until the stream thread clears it. */
void fn_802EC1D8(void) {
    gMp3AbortRequested = 1;
}

extern void OSSleepTicks(unsigned long long);
#pragma push
#pragma dont_inline on
void fn_802EC1E4(void) {
    register unsigned int *timebase;
    register int start;
    register unsigned int multiplier;
    register unsigned int clock;
    int current;
    fn_802EC1D8();
    ((long (*)(char *, ...))fn_802E30C8)((char *)&lbl_8034E95C);
    start = fn_802E2C20();
    multiplier = 0x10624DD3;
    timebase = (unsigned int *)0x80000000;
    while ((unsigned char)lbl_805600C8 != 0) {
        current = fn_802E2C20();
        if (current - start > 0xBB8) {
            ((long (*)(char *, ...))fn_802E30C8)((char *)&lbl_8034E980);
            break;
        }
        clock = *(volatile unsigned int *)((char *)timebase + 0xF8) >> 2;
        ((void (*)(int, int))OSSleepTicks)(0, (clock / 1000) + ((clock / 250) & 0x0FFFFFFC));
    }
}
#pragma pop
extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern char lbl_8034E990[];
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
#pragma push
#pragma scheduling invalid_target
/* Open MP3 resource by id and store handle in table slot. */
void fn_802EC294(int index, int resourceId) {
    register long zero;
    register int offset;
    long handle;
    long streamInfo;
    long result;
    long *base = lbl_805076A0;
    long *slot;

    zero = 0;
    offset = index << 3;
    slot = (long *)((char *)base + offset);
    handle = zero;
    streamInfo = zero;
    result = fn_8012C370(resourceId, 0x4D4D5033, &handle, &streamInfo, 0, 0);
    if (result != 0) {
        slot[0] = result;
        slot[1] = streamInfo;
    } else {
        ((long (*)(char *, ...))fn_802E30C8)(lbl_8034E990, resourceId);
    }
}
#pragma pop
void fn_802EC32C(long stream, long deleteFlag) {
    /* A stream's deleting-destructor tail: clear the "stream open" flag when a stream is present and the delete flag is set. */
    if (stream != 0 && deleteFlag > 0) {
        mp3StreamOpen = 0;
    }
}

/* Set the stream's current position (+8) to pos when it lies in [0, size) (size at +C);
 * return 1 on success, 0 when out of range. */
long fn_802EC348(void *stream, long pos) {
    if (pos < 0)
        goto fail;
    if (pos >= *(long *)((char *)stream + 0xC))
        goto fail;
    *(long *)((char *)stream + 8) = pos;
    return 1;
fail:
    return 0;
}

long fn_802EC370(void *arg0) {
    return ((long *)arg0)[3];
}

/* Reads count bytes from the stream's buffer at its current position (+8) into
   dst and advances the position, if the read fits within the buffer limit (+C). */
int fn_802EC378(void *stream, void *dst, int count) {
    int pos = *(int *)((char *)stream + 8);
    if (pos >= 0 && pos + count <= *(int *)((char *)stream + 0xC)) {
        memcpy(dst, (char *)*(char **)((char *)stream + 4) + pos, count);
        *(int *)((char *)stream + 8) = *(int *)((char *)stream + 8) + count;
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#define Mp3FileStream_Read fn_802EC3F0 /* file-backed MP3 stream vtable read(dst, size) */
long fn_802EC3F0(void *arg0, long dst, long size) {
    /* File-backed MP3 stream's read(): read `size` bytes into `dst` from its VF file. */
    long handle = ((Mp3Stream *)arg0)->file;
    return fn_800B7C60(dst, size, 1, handle) == 1;
}
#pragma scheduling on
#pragma pop
/* File-backed MP3 stream vtable method (slot +0xC): passes the stream's VFFile
   handle (offset 4) to fn_800B7C64 and returns whether it succeeded (result == 0). */
long fn_802EC42C(void *stream) {
    long unused;
    return ((long (*)(long, long, long))fn_800B7C64)(((long *)stream)[1], unused, 0) == 0;
}

/* Virtual size() of the file-backed MP3 stream: return its file size (offset +8). */
long fn_802EC45C(Mp3Stream *stream) { return stream->size; }

typedef signed long s32;
extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
extern char lbl_80560060;
