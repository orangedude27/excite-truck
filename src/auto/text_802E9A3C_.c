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
long *fn_802E9A3C(long arg0, long arg1) {
    long *p = lbl_80507600;
    lbl_80560060 = 1;
    if (p != 0) {
        p[1] = arg0;
        p[0] = (long)&lbl_8034E9C8;
        p[3] = arg1;
    }
    return p;
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
void *fn_802E9B54(void *arg0, long arg1) {
    long *p = (long *)arg0;
    long value;
    if (p != 0) {
        value = p[1];
        p[0] = (long)&lbl_8034E9B0;
        if (value != 0) {
            fn_800B7BDC(value);
            p[1] = 0;
        }
        if (arg1 > 0) lbl_80560060 = 0;
    }
    return arg0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_802E9BCC(void *arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    if (arg0 == 0) return;
    ((Obj *)arg0)->f(1);
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
void fn_802E9C68(long arg0) {
    OSReport((const char *)&lbl_8034E370, arg0);
    *(volatile char *)&lbl_80560061 = 1;
    ++*(volatile int *)&lbl_80560068;
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
void fn_802E9CAC(int arg0) {
    OSReport((const char *)&lbl_8034E390, arg0);
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
    lbl_80560061 = ((unsigned char *)(base + 0xB8))[9] >> 4 & 1;
}

#pragma dont_inline on
void fn_802E9DDC(void) {
    if (fn_800B7E5C((signed char)lbl_805076B8[8], 1) != 0) {
        ((long (*)(char *, ...))fn_802E30C8)((char *)&lbl_8034E3E0);
    }
    if (fn_800B7B34((signed char)*(lbl_805076B8 + 8)) != 0) {
        fn_802E317C((const char *)&lbl_8034E3F0);
    }
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
    if ((signed char)next == 0) goto check;
    src++;
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
// Recursively scans a directory for .brf files (up to maxDepth), recording matching paths/names into lbl_80508818 entries.
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
void fn_802EA7E0(void) {
    lbl_8056007C = 0;
    if ((unsigned char)lbl_80560061 != 0) {
        fn_802EA5D4(lbl_8055D274, 0);
        if (lbl_8056007C == 0) fn_802EA5D4(&lbl_8055D2A4, 8);
    }
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
        memcpy((void *)lbl_805600A0, (void *)(lbl_805600A0 + lbl_805600A4), lbl_805600B8 - lbl_805600A4);
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

void fn_802EAB28(void) {
    extern long lbl_8034E260;
    extern int OSReport(const char *, ...);
    OSReport((char *)&lbl_8034E260 + 0x2F4);
}

#pragma push
#pragma use_lmw_stmw off
extern int lbl_805600B0;
extern int lbl_805600C0;
extern int lbl_8055D26C;
extern void *memset(void *, int, int);
#pragma use_lmw_stmw off
int fn_802EB7D4(void *arg0, int arg1, int arg2, int arg_sp0) {
    int idx = arg2 * 4;
    int elem = lbl_8055D26C;
    if (*(int *)((char *)&lbl_805600B0 + idx) == lbl_805600B8) {
        memset(arg0, 0, arg1);
        *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
        return arg1;
    }
    if (*(int *)((char *)&lbl_805600B0 + idx) < lbl_805600B8) {
        int bytes = arg1 * elem;
        int rem = lbl_805600B8 - *(int *)((char *)&lbl_805600B0 + idx);
        int avail = bytes < rem ? bytes : rem;
        if (avail < bytes && *(int *)((char *)&lbl_805600C0 + idx) != 0) {
            memset(arg0, 0, arg1);
            *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
            return arg1;
        }
        {
            int count = avail / (elem * 2);
            int i;
            unsigned short *src = (unsigned short *)(lbl_805600A0 + *(int *)((char *)&lbl_805600B0 + idx));
            unsigned short *dst = (unsigned short *)arg0;
            *(int *)((char *)&lbl_805600C0 + idx) = 0;
            if (elem == 2) {
                for (i = 0; i < count; i++) dst[i] = src[i * 2 + arg2];
            } else {
                for (i = 0; i < count; i++) dst[i] = src[i];
            }
            *(int *)((char *)&lbl_805600B0 + idx) = *(int *)((char *)&lbl_805600B0 + idx) + avail;
            if (*(int *)((char *)&lbl_805600B0 + idx) >= lbl_805600A4) *(int *)((char *)&lbl_805600B0 + idx) = 0;
            return arg1;
        }
    } else {
        int bytes = arg1 * elem;
        int rem = lbl_805600A4 - *(int *)((char *)&lbl_805600B0 + idx);
        int avail = bytes < rem ? bytes : rem;
        if (avail < bytes && *(int *)((char *)&lbl_805600C0 + idx) != 0) {
            memset(arg0, 0, arg1);
            *(int *)((char *)&lbl_805600C0 + idx) = *(int *)((char *)&lbl_805600C0 + idx) + 1;
            return arg1;
        }
        {
            int count = avail / (elem * 2);
            int countBytes = avail / elem;
            int i;
            unsigned short *src = (unsigned short *)(lbl_805600A0 + *(int *)((char *)&lbl_805600B0 + idx));
            unsigned short *dst = (unsigned short *)arg0;
            *(int *)((char *)&lbl_805600C0 + idx) = 0;
            if (elem == 2) {
                for (i = 0; i < count; i++) dst[i] = src[i * 2 + arg2];
            } else {
                for (i = 0; i < count; i++) dst[i] = src[i];
            }
            *(int *)((char *)&lbl_805600B0 + idx) = *(int *)((char *)&lbl_805600B0 + idx) + avail;
            if (*(int *)((char *)&lbl_805600B0 + idx) >= lbl_805600A4) {
                *(int *)((char *)&lbl_805600B0 + idx) = 0;
                if (arg1 > countBytes) {
                    fn_802EB7D4((char *)arg0 + countBytes, arg1 - countBytes, arg2, arg_sp0);
                }
            }
            return arg1;
        }
    }
}

#pragma scheduling invalid_target
#pragma dont_inline on
int fn_802EBD40(void) {
    extern void OSSleepTicks(unsigned long long);
    char *base = (char *)&lbl_8034E260;
    unsigned int *tb;
    int elapsed;
    unsigned int clock;
    lbl_80560062 = 0;
    ((void (*)(char *, ...))fn_802E30C8)(base + 0x65C);
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

int fn_802EBE00(int arg0) {
    if (arg0 == 1) fn_802EBD40();
    return 0;
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
    extern int fn_802EB7D4(void *, int, int, int);
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

void* fn_802EC0FC(void) {
    return lbl_80560080;
}

char *fn_802EC104(int arg0) {
    return lbl_8052E658 + arg0 * 0x610 + 0x408;
}

void fn_802EC11C(void *arg0) {
    lbl_80560078 = arg0;
}

extern void *lbl_80560078;
void* fn_802EC124(void) {
    return lbl_80560078;
}

void fn_802EC12C(void) {
    lbl_80560078 = (void*)-1;
}

#pragma dont_inline fn_802EC138
void fn_802EC138(void) {
    if ((unsigned char)lbl_805600D0 == 0) {
        lbl_805600D1 = 1;
    }
    lbl_805600D0 = 1;
}

void fn_802EC158(void) {
    int *ptr;
    int i;

    lbl_805600D0 = 0;
    lbl_805600D1 = 0;
    ptr = &lbl_80560090;
    i = 0;
    do {
        fn_802E622C(*ptr, lbl_805651C4);
        fn_802E61E4(*ptr, lbl_805651C4);
        i++;
        ptr++;
    } while (i < 2);
}

#pragma push
#pragma dont_inline on
void fn_802EC1C0(float arg0) {
    lbl_8055D270 = arg0;
    if ((unsigned char)lbl_805600D0 != 0) {
        fn_802EC138();
    }
}
#pragma dont_inline reset
#pragma pop
void fn_802EC1D8(void) {
    lbl_805600C8 = 1;
}

extern void OSSleepTicks(unsigned long long);
#pragma push
#pragma dont_inline on
void fn_802EC1E4(void) {
    register unsigned int *timebase;
    register int start;
    register unsigned int multiplier;
    unsigned int clock;
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
void fn_802EC32C(long arg0, long arg1) {
    if (arg0 != 0 && arg1 > 0) {
        lbl_80560060 = 0;
    }
}

long fn_802EC348(void *arg0, long arg1) {
    if (arg1 < 0)
        goto fail;
    if (arg1 >= *(long *)((char *)arg0 + 0xC))
        goto fail;
    *(long *)((char *)arg0 + 8) = arg1;
    return 1;
fail:
    return 0;
}

long fn_802EC370(void *arg0) {
    return ((long *)arg0)[3];
}

int fn_802EC378(void *arg0, void *arg1, int arg2) {
    int pos = *(int *)((char *)arg0 + 8);
    if (pos >= 0 && pos + arg2 <= *(int *)((char *)arg0 + 0xC)) {
        memcpy(arg1, (char *)*(char **)((char *)arg0 + 4) + pos, arg2);
        *(int *)((char *)arg0 + 8) = *(int *)((char *)arg0 + 8) + arg2;
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
long fn_802EC3F0(void *arg0, long arg1, long arg2) {
    long value = ((long *)arg0)[1];
    return fn_800B7C60(arg1, arg2, 1, value) == 1;
}
#pragma scheduling on
#pragma pop
long fn_802EC42C(void *arg0) {
    long unused;
    return ((long (*)(long, long, long))fn_800B7C64)(((long *)arg0)[1], unused, 0) == 0;
}

long fn_802EC45C(void *arg0) { return ((long *)arg0)[2]; }

typedef signed long s32;
extern long fn_800B7C64(long, long);
extern long fn_800B7C60(long, long, long, long);
extern long lbl_805076A0[];
extern long fn_8012C370(long, long, long *, long *, long, long);
extern long fn_802E30C8(char *, long);
extern char lbl_80560060;
