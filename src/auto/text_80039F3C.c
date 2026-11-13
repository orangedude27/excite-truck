// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8037B8A0[32];
extern unsigned int lbl_8055D8F0;
extern unsigned char lbl_8055D8E0;
extern unsigned int lbl_8055D8E4, lbl_8055D8E8;
extern unsigned char *lbl_8055D8FC;
extern unsigned int lbl_80558E18;
extern unsigned char lbl_8037B820[];
extern int IOS_IoctlAsync(int, int, void *, int, void *, int, void (*)(int, void *), void *);
extern unsigned char lbl_8055D8E1;
extern unsigned char lbl_8055D900;
extern int lbl_8055D8F4;
extern unsigned char lbl_8037B8C0[];
extern const char lbl_80302848[];
extern unsigned char lbl_8055D8ED;
extern unsigned char lbl_8055D8EC;
extern char *lbl_8055D8F8;
extern const char lbl_80558E20[8];
extern int IPCCltInit(void);
extern void *IPCGetBufferLo(void);
extern void *IPCGetBufferHi(void);
extern void IPCSetBufferLo(void *);
extern int IOS_Open(const char *, int);
extern char *strncpy(char *, const char *, unsigned int);
void OSReport(const char *, ...);
extern void (*FatalFunc_8055D8D8)(void);
extern unsigned char lbl_80560B08, lbl_80560B09, lbl_80560B0A, lbl_80560B0B;
extern const char *lbl_802EE878[];
extern char __ErrorInfo[];
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern unsigned char SCGetLanguage(void);
extern unsigned short OSSetFontEncode(unsigned short);
extern void OSFatal(void *, void *, const char *);
extern unsigned long long OSGetTime(void);
extern unsigned long long __div2i(unsigned long long, unsigned long long);
extern char lbl_80302384[];
extern void fn_8003A10C(int);
extern char lbl_8037B6D0[];
extern int NANDPrivateCreateDirAsync(const char *, int, int, void (*)(int), void *);
extern void (*lbl_8055D8D0)(int, int);
extern int NANDCloseAsync(void *, void *, void *);
extern int NANDWriteAsync(void *, void *, int, void *, void *);
extern int NANDPrivateOpenAsync(const char *, void *, int, void *, void *);
extern char lbl_8037B640[], lbl_80302368[];
extern void fn_80039F3C(int);
extern void fn_80039F68(int);
extern void fn_80039FC4(int);

#define sNandDvderrorCmdBlock lbl_8037B6D0
#define sNandErrorReportCallback lbl_8055D8D0
#define sNandDvderrorFileInfo lbl_8037B640
#define sDvderrorPath lbl_80302368
void fn_80039F3C(int arg0) { if (lbl_8055D8D0 != 0) { lbl_8055D8D0(arg0 == 0 ? 1 : 2, 0); } }

void fn_80039F68(int arg0) { if (NANDCloseAsync(lbl_8037B640, fn_80039F3C, lbl_8037B6D0) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2, 0); }

void fn_80039FC4(int arg0) {
 char *base = lbl_8037B640;
 if (arg0 == 0) {
  if (NANDWriteAsync(base, base+0x160, 0x80, fn_80039F68, base+0x90) != 0 &&
      NANDCloseAsync(base, fn_80039F3C, base+0x90) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
 } else if (lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
}

void fn_8003A074(int arg0) {
 if (arg0 == 0 || arg0 == -6) {
  if (NANDPrivateOpenAsync(lbl_80302368,lbl_8037B640,2,fn_80039FC4,lbl_8037B6D0) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
 } else if (lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
}

extern int NANDPrivateCreateAsync(const char *, int, void *, void *, void *);
extern char lbl_80302368[];
extern void fn_8003A074(int);
void fn_8003A10C(int arg0) {
    if (arg0 == 0 || arg0 == -6) {
        if (NANDPrivateCreateAsync(lbl_80302368, 0x3F, 0, fn_8003A074, lbl_8037B6D0) != 0 &&
            lbl_8055D8D0 != 0) {
            lbl_8055D8D0(2, 0);
        }
    } else if (lbl_8055D8D0 != 0) {
        lbl_8055D8D0(2, 0);
    }
}

/* Start async creation of the NAND error-report directory, storing the error ID/timestamp and reporting failure via callback. */
void fn_8003A1A0(int errorId, void (*completionCallback)(int, int)) {
    long long timeTicks;
    long long busClockDivisor;
    long long timeQuotient;
    unsigned int busClockRaw;
    *(int*)(__ErrorInfo + 8) = errorId;
    timeTicks = (long long)OSGetTime();
    busClockRaw = *(unsigned int*)0x800000F8;
    busClockDivisor = (long long)(busClockRaw >> 2);
    timeQuotient = timeTicks / busClockDivisor;
    *(unsigned int*)(__ErrorInfo + 0xC) = (unsigned int)timeQuotient;
    lbl_8055D8D0 = completionCallback;
    if (NANDPrivateCreateDirAsync(lbl_80302384, 0x3F, 0, fn_8003A10C, lbl_8037B6D0) != 0 &&
        lbl_8055D8D0 != 0) {
        lbl_8055D8D0(2, 0);
    }
}

typedef struct DVDDiskID {
    char game[4];
    char company[2];
    unsigned char disk;
    unsigned char version;
} DVDDiskID;

int DVDCompareDiskID(const DVDDiskID *id1, const DVDDiskID *id2) {
    /* Compare two DVD disk IDs; empty game/company and 0xFF disk/version fields act as wildcards. */
    if (id1->game[0] != '\0' && id2->game[0] != '\0' &&
        strncmp(id1->game, id2->game, 4) != 0) {
        return 0;
    }

    if (id1->company[0] == '\0' || id2->company[0] == '\0' ||
        strncmp(id1->company, id2->company, 2) != 0) {
        return 0;
    }

    if (id1->disk != 0xFF && id2->disk != 0xFF && id1->disk != id2->disk) {
        return 0;
    }

    if (id1->version != 0xFF && id2->version != 0xFF &&
        id1->version != id2->version) {
        return 0;
    }

    return 1;
}
#pragma scheduling invalid_target
void __DVDShowFatalMessage(void) {
    unsigned char color[4];
    int zero = 0;
    int foreground;
    int background;
    const char *message;

    color[0] = lbl_80560B08;
    color[1] = lbl_80560B09;
    color[2] = lbl_80560B0A;
    color[3] = lbl_80560B0B;
    background = zero;
    if (SCGetLanguage() == 0) {
        OSSetFontEncode(1);
    } else {
        OSSetFontEncode(0);
    }
    if (SCGetLanguage() > 6) {
        message = lbl_802EE878[1];
    } else {
        message = lbl_802EE878[SCGetLanguage()];
    }
    foreground = *(int *)color;
    OSFatal(&foreground, &background, message);
}
#pragma scheduling on
extern void __DVDShowFatalMessage(void);
extern void (*lbl_8055D8D0)(int, int);
int DVDSetAutoFatalMessaging(int enable) {
 int old; OSDisableInterrupts(); old=FatalFunc_8055D8D8 != 0;
 if(enable) FatalFunc_8055D8D8=__DVDShowFatalMessage; else FatalFunc_8055D8D8=0;
 OSRestoreInterrupts(); return old;
}

void __DVDPrintFatalMessage(void) {
    if (FatalFunc_8055D8D8 != 0) {
        FatalFunc_8055D8D8();
    }
}

int doTransactionCallback(int arg0, void *arg1) {
    int result = arg0;
    int (*callback)(int);

    if (((unsigned int)*(unsigned int *)((char *)arg1 + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(lbl_80302848);
        *(unsigned int *)((char *)arg1 + 0xC) = 0xFEEBDAED;
    } else {
        lbl_8055D8E0 = 0;
        callback = *(int (**)(int))arg1;
        if (callback != 0) {
            lbl_8055D8E1 = 1;
            if (lbl_8055D900 == 1) {
                lbl_8055D900 = 0;
                result |= 8;
            }
            if (result & 1) {
                lbl_8055D8F4 = 0;
                callback(result);
            }
            lbl_8055D8E1 = 0;
        }
    }
    *(unsigned char *)((char *)arg1 + 8) = 0;
    return 0;
}

int doPrepareCoverRegisterCallback(int arg0, void *arg1) {
    int result = arg0;
    int (*callback)(int);

    lbl_8055D8E0 = 0;
    ((unsigned int *)lbl_8037B8A0)[1] = *(unsigned int *)&lbl_8037B8C0;
    if (((unsigned int)*(unsigned int *)((char *)arg1 + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(lbl_80302848);
        *(unsigned int *)((char *)arg1 + 0xC) = 0xFEEBDAED;
    } else {
        callback = *(int (**)(int))arg1;
        if (callback != 0) {
            lbl_8055D8E1 = 1;
            if (lbl_8055D900 == 1) {
                lbl_8055D900 = 0;
                result |= 8;
            }
            callback(result);
            lbl_8055D8E1 = 0;
        }
    }
    *(unsigned char *)((char *)arg1 + 8) = 0;
    return 0;
}

typedef struct DVDLowContext {
    void *callback;
    unsigned int WORD_0x4;
    unsigned char inUse;
    unsigned char pad[3];
    unsigned int magic;
    unsigned int id;
    unsigned char pad2[12];
} DVDLowContext;

typedef struct DVDLowDICommand {
    unsigned char command;
    unsigned int arg1;
    unsigned int arg2;
    unsigned int arg3;
    unsigned int arg4;
    unsigned int arg5;
    unsigned int arg6;
    unsigned int arg7;
} DVDLowDICommand;

typedef struct IPCIOVector {
    void *base;
    unsigned int length;
} IPCIOVector;

static inline void nextCommandBuf(void) {
    if ((int)++lbl_8055D8E4 >= 4) {
        lbl_8055D8E4 = 0;
    }
}

static inline DVDLowContext *newContext(void *callback, unsigned int arg2, const char *msg) {
    int id;
    unsigned int flag;

    flag = ((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].inUse;
    if (((-flag | flag) >> 31) == 1U) {
        OSReport(msg + 0x218, (int)lbl_8055D8E8);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].magic != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }

    ((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].callback = callback;
    ((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].WORD_0x4 = arg2;
    ((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].inUse = 1;

    id = lbl_8055D8E8;
    if ((int)++lbl_8055D8E8 >= 4) {
        lbl_8055D8E8 = 0;
    }

    return &((DVDLowContext *)lbl_8037B820)[id];
}

#pragma scheduling 750
static inline void *ddrAllocAligned32(unsigned int size, const char *msg) {
    unsigned char *lo = (unsigned char *)IPCGetBufferLo();
    unsigned char *hi = (unsigned char *)IPCGetBufferHi();

    if ((unsigned int)lo % 32 != 0) {
        lo = (unsigned char *)(((unsigned int)lo + 31) & 31);
    }

    if (lo + size > hi) {
        OSReport(msg + 0x80, size);
    }

    IPCSetBufferLo(lo + size);
    return lo;
}

static inline int allocateStructures(const char *msg) {
    lbl_8055D8FC = (unsigned char *)ddrAllocAligned32(128, msg);
    if (lbl_8055D8FC == (void *)0) {
        OSReport(msg + 0xBC);
        return 0;
    }

    lbl_8055D8F8 = (char *)ddrAllocAligned32(32, msg);
    if (lbl_8055D8F8 == (void *)0) {
        OSReport(msg + 0xE4);
        return 0;
    }

    return 1;
}

#pragma scheduling reset
static inline void initDvdContexts(void) {
    DVDLowContext *base = (DVDLowContext *)lbl_8037B820;
    base[0].callback = (void *)0;
    base[0].WORD_0x4 = 0;
    base[0].inUse = 0;
    base[0].magic = 0xFEEBDAED;
    base[0].id = 0;
    base[1].callback = (void *)0;
    base[1].WORD_0x4 = 0;
    base[1].inUse = 0;
    base[1].magic = 0xFEEBDAED;
    base[1].id = 1;
    base[2].callback = (void *)0;
    base[2].WORD_0x4 = 0;
    base[2].inUse = 0;
    base[2].magic = 0xFEEBDAED;
    base[2].id = 2;
    base[3].callback = (void *)0;
    base[3].WORD_0x4 = 0;
    base[3].inUse = 0;
    base[3].magic = 0xFEEBDAED;
    base[3].id = 3;
    lbl_8055D8E8 = 0;
    lbl_8055D8EC = 1;
}
#pragma scheduling 750

int DVDLowInit(void) {
    const char *msg = lbl_80302848;
    int result;

    if (!lbl_8055D8ED) {
        lbl_8055D8ED = 1;

        result = IPCCltInit();
        if (result != 0) {
            OSReport(msg + 0x60, result);
            return 0;
        }

        if (!allocateStructures(msg)) {
            return 0;
        }

        if (!lbl_8055D8EC) {
            initDvdContexts();
        }
    }

    strncpy(lbl_8055D8F8, lbl_80558E20, 32);
    result = IOS_Open(lbl_8055D8F8, 0);
    lbl_80558E18 = result;

    if (result >= 0) {
        return 1;
    }

    switch (result) {
    case -6:
        OSReport(msg + 0x104);
        return 0;
    case -1:
        OSReport(msg + 0x150);
        return 0;
    case -5:
        OSReport(msg + 0x198);
        return 0;
    default:
        OSReport(msg + 0x1E4, result);
        return 0;
    }
}

#pragma scheduling invalid_target
int fn_8003A834(void *arg0, void *arg1) {
    unsigned char *base = lbl_8037B820;
    unsigned int one = 1;
    const char *msg = lbl_80302848;
    void *request = arg0;
    int slot = lbl_8055D8E8;
    int offset = slot * 0x20;
    unsigned char *entry = base + offset;
    unsigned int flag = entry[8];
    int index;
    unsigned char *context;
    int result;

    lbl_8055D8E0 = one;
    if (((-flag | flag) >> 31) == 1U) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {
        }
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {
        }
    }

    ((unsigned int *)base)[slot * 8] = (unsigned int)arg1;
    index = slot + 1;
    *(unsigned int *)(entry + 4) = one;
    entry[8] = one;
    lbl_8055D8E8 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E8 = 0;
    }

    context = base + slot * 0x20;
    if (request == 0) {
        OSReport(msg + 0x2C0);
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }

    *(unsigned char *)(lbl_8055D8FC + index * 0x20) = 0x70;
    result = IOS_IoctlAsync(lbl_80558E18, 0x70,
                            lbl_8055D8FC + lbl_8055D8E4 * 0x20,
                            0x20, request, 0x20,
                            (void (*)(int, void *))doTransactionCallback, context);
    if (result != 0) {
        OSReport(msg + 0x2FC, result);
        context[8] = 0;
        return 0;
    }
    return 1;
}
extern int IOS_IoctlvAsync(int, int, int, int, void *, void *, void *);
extern int doTransactionCallback(int, void *);
#pragma scheduling 750
int DVDLowOpenPartition(unsigned int offset, const void *ticket, unsigned int certsSize,
                        const void *certs, void *tmd,
                        void *callback) {
    const char *msg = lbl_80302848;
    unsigned char *base = lbl_8037B820;
    unsigned int one = 1;
    DVDLowContext *ctx;
    IPCIOVector *ioVec;
    int result;

    if (ticket != (void *)0 && ((unsigned int)ticket % 32 != 0)) {
        OSReport(msg + 0x338);
        return 0;
    }

    if (certs != (void *)0 && ((unsigned int)certs % 32 != 0)) {
        OSReport(msg + 0x370);
        return 0;
    }

    if (tmd != (void *)0 && ((unsigned int)tmd % 32 != 0)) {
        OSReport(msg + 0x370);
        return 0;
    }

    lbl_8055D8E0 = one;
    ctx = newContext(callback, one, msg);

    nextCommandBuf();
    *(unsigned char *)(lbl_8055D8FC + lbl_8055D8E4 * 32) = 0x8B;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 32 + 4) = offset;

    ioVec = (IPCIOVector *)(base + 0xC0);
    ioVec[0].length = 32;
    ioVec[0].base = lbl_8055D8FC + lbl_8055D8E4 * 32;
    ioVec[1].base = (void *)ticket;
    if (ticket == (void *)0) {
        ioVec[1].length = 0;
    } else {
        ioVec[1].length = 0x2A4;
    }
    ioVec[2].base = (void *)certs;
    if (certs == (void *)0) {
        ioVec[2].length = 0;
    } else {
        ioVec[2].length = certsSize;
    }
    ioVec[3].base = tmd;
    ioVec[3].length = 0x49E4;
    ioVec[4].base = base + 0x100;
    ioVec[4].length = 32;

    result = IOS_IoctlvAsync(lbl_80558E18, 0x8B, 3, 2, ioVec,
                             (void *)doTransactionCallback, ctx);

    if (result != 0) {
        OSReport(msg + 0x3A8, result);
        ctx->inUse = 0;
        return 0;
    }

    return 1;
}

extern unsigned int lbl_8055D8E4, lbl_8055D8E8;
extern unsigned char *lbl_8055D8FC;
extern unsigned int lbl_80558E18;
extern unsigned char lbl_8037B820[];
extern int IOS_IoctlAsync(int, int, void *, int, void *, int, void (*)(int, void *), void *);
#pragma scheduling invalid_target
int fn_8003AC24(void *arg0) {
    const char *msg = lbl_80302848;
    unsigned int one3 = 1;
    int index = lbl_8055D8E4 + 1;
    int slot;
    unsigned char *base;
    unsigned char *entry;
    unsigned char *buf;
    int result;
    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x8C;
    lbl_8055D8E0 = one3;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    entry = base + slot * 0x20;
    if ((((unsigned int)entry[8] | (0U - (unsigned int)entry[8])) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    buf = base + slot * 0x20;
    ((unsigned int *)buf)[0] = (unsigned int)arg0;
    slot = slot + 1;
    *(unsigned int *)(entry + 4) = one3;
    entry[8] = one3;
    lbl_8055D8E8 = slot;
    if (slot >= 4) {
        slot = 0;
        lbl_8055D8E8 = 0;
    }
    result = IOS_IoctlAsync(lbl_80558E18, 0x8C, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, buf);
    if (result != 0) {
        OSReport(msg + 0x3E8, result);
        buf[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling on

int fn_8003AD88(void *arg0, int arg1, int arg2, unsigned int arg3) {
    const char *msg = lbl_80302848;
    int slot = lbl_8055D8E8;
    int offset = slot * 0x20;
    unsigned char *entry = lbl_8037B820 + offset;
    int index;
    int result;

    lbl_8055D8E0 = 1;
    if (entry[8]) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((unsigned int)*(unsigned int *)(entry + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)lbl_8037B820)[slot * 8] = arg3;
    index = slot + 1;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    lbl_8055D8E8 = index;
    if (index >= 4) lbl_8055D8E8 = 0;
    index = lbl_8055D8E4 + 1;
    lbl_8055D8F4 = arg1;
    lbl_8055D8E4 = index;
    entry = lbl_8037B820 + offset;
    if (index >= 4) lbl_8055D8E4 = 0;
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0x8D;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = arg1;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = arg2;
    result = IOS_IoctlAsync(lbl_80558E18, 0x8D, lbl_8055D8FC + lbl_8055D8E4 * 0x20,
                            0x20, arg0, arg1, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x428, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003AF1C(int arg0, int arg1, int arg2) {
    const char *msg = lbl_80302848;
    unsigned int one = 1;
    unsigned char *base = lbl_8037B820;
    int slot = lbl_8055D8E8;
    int offset = slot * 0x20;
    unsigned char *entry = base + offset;
    unsigned int flag = entry[8];
    int index;
    int result;

    lbl_8055D8E0 = one;
    if (((-flag | flag) >> 31) == 1U) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = arg2;
    index = slot + 1;
    *(unsigned int *)(entry + 4) = one;
    entry[8] = one;
    lbl_8055D8E8 = index;
    if (index >= 4) lbl_8055D8E8 = 0;
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    entry = (unsigned char *)(base + offset);
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xE3;
    *(int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = arg0;
    *(int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = arg1;
    result = IOS_IoctlAsync(lbl_80558E18, 0xE3,
                            lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20,
                            lbl_8037B8A0, 0x20,
                            (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x468, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003B0B0(void *arg0, void *arg1) {
    const char *msg = lbl_80302848;
    unsigned char *base;
    int slot;
    unsigned char *entry;
    unsigned char *callbackEntry;
    unsigned char busy;
    int next;
    int index;
    int result;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    lbl_8055D8E0 = 1;
    entry = base + slot * 0x20;
    busy = entry[8];
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg1;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = base + slot * 0x20;
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x12;
    result = IOS_IoctlAsync(lbl_80558E18, 0x12, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, arg0, 0x20, (void (*)(int, void *))doTransactionCallback, callbackEntry);
    if (result != 0) {
        OSReport(msg + 0x4E8, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}

#pragma scheduling invalid_target
int fn_8003B218(void *arg0) {
    const char *msg = lbl_80302848;
    unsigned char *base = lbl_8037B820;
    int slot = lbl_8055D8E8;
    unsigned char flag;
    unsigned char *p;
    unsigned char *entry;
    int index;
    int result;
    unsigned int one = 1;
    lbl_8055D8E0 = one;
    p = base + slot * 0x20;
    flag = p[8];
    if (((flag | (0U - flag)) >> 31) == 1U) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(p + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((void **)base)[slot * 8] = arg0;
    index = slot + 1;
    *(unsigned int *)(p + 4) = one;
    p[8] = one;
    lbl_8055D8E8 = index;
    if (index >= 4) {
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    entry = base + slot * 0x20;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xE0;
    result = IOS_IoctlAsync(lbl_80558E18, 0xE0, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, lbl_8037B8A0, 0x20, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x520, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling on
int fn_8003B380(int value) {
    lbl_8055D8F0 = value;
    return 1;
}

#pragma scheduling invalid_target
int fn_8003B38C(void *arg0) {
    unsigned int slot = lbl_8055D8E8;
    unsigned char *base = lbl_8037B820;
    const char *msg = lbl_80302848;
    unsigned int offset = slot << 5;
    unsigned int busy;
    unsigned char *p = base + offset;
    unsigned char *entry;
    unsigned int one = 1;
    int next;
    int index;
    int result;

    lbl_8055D8E0 = one;
    busy = p[8];
    if (((busy | (0U - busy)) >> 31) == 1U) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(p + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    next = slot + 1;
    *(unsigned int *)(p + 4) = one;
    p[8] = one;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    entry = base + offset;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x8A;
    *(unsigned int *)(lbl_8055D8FC + (*(volatile unsigned int *)&lbl_8055D8E4) * 0x20 + 4) = lbl_8055D8F0;
    result = IOS_IoctlAsync(lbl_80558E18, 0x8A,
        lbl_8055D8FC + (*(volatile unsigned int *)&lbl_8055D8E4) * 0x20, 0x20, 0, 0,
        (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x5E0, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling invalid_target
int fn_8003B508(int arg0, int arg1, int arg2) {
    const char *msg = lbl_80302848;
    unsigned char *base = lbl_8037B820;
    int slot = lbl_8055D8E8;
    int offset = slot * 0x20;
    unsigned char *entry = base + offset;
    unsigned int flag = entry[8];
    int index;
    int result;
    unsigned int one = 1;

    lbl_8055D8E0 = one;
    if (((-flag | flag) >> 31) == 1U) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = arg2;
    index = slot + 1;
    *(unsigned int *)(entry + 4) = one;
    entry[8] = one;
    lbl_8055D8E8 = index;
    if (index >= 4) {
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    entry = (unsigned char *)(base + offset);
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xE4;
    *(int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = arg0;
    *(int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = arg1;
    result = IOS_IoctlAsync(lbl_80558E18, 0xE4,
                            lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20,
                            lbl_8037B8A0, 0x20,
                            (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x618, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling on

int fn_8003B69C(int arg0, void *arg1) {
    const char *msg = lbl_80302848;
    unsigned char *base = lbl_8037B820;
    int slot = lbl_8055D8E8;
    unsigned char *entry;
    unsigned char *callbackEntry;
    unsigned int busy;
    int next;
    int index;
    int result;
    lbl_8055D8E0 = 1;
    entry = base + slot * 0x20;
    busy = entry[8];
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg1;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    callbackEntry = base + slot * 0x20;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xDD;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = (unsigned int)((arg0 >> 16) & 3);
    result = IOS_IoctlAsync(lbl_80558E18, 0xDD, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, callbackEntry);
    if (result != 0) {
        OSReport(msg + 0x9CC, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}

#pragma scheduling invalid_target
int fn_8003B81C(void *arg0, int arg1, int arg2, void (*arg3)(int, void *)) {
    DVDLowContext *base;
    int slot;
    DVDLowContext *p;
    unsigned int flag;
    unsigned int one;
    DVDLowContext *entry;
    int next;
    int index;
    int result;
    const char *msg = lbl_80302848;

    if (((unsigned int)arg0 & 0x1F) != 0) {
        OSReport(msg + 0xA0C);
        return 0;
    }

    slot = (int)lbl_8055D8E8;
    base = (DVDLowContext *)lbl_8037B820;
    one = 1;
    p = base + slot;
    *(volatile unsigned char *)&lbl_8055D8E0 = one;
    flag = p->inUse;
    if (((flag | -flag) >> 31) == 1U) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (p->magic + 0x01150000U != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }

    base[slot].callback = (void *)arg3;
    next = slot + 1;
    p->WORD_0x4 = one;
    p->inUse = one;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        lbl_8055D8E8 = 0;
    }

    index = (int)lbl_8055D8E4 + 1;
    lbl_8055D8F4 = arg1;
    lbl_8055D8E4 = index;
    entry = ((DVDLowContext *)lbl_8037B820) + slot;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }

    lbl_8055D8FC[index * 0x20] = 0x71;
    *(int *)(lbl_8055D8FC + (*(volatile unsigned int *)&lbl_8055D8E4) * 0x20 + 4) = arg1;
    *(int *)(lbl_8055D8FC + (*(volatile unsigned int *)&lbl_8055D8E4) * 0x20 + 8) = arg2;
    result = IOS_IoctlAsync(lbl_80558E18, 0x71,
        lbl_8055D8FC + (*(volatile unsigned int *)&lbl_8055D8E4) * 0x20,
        0x20, arg0, arg1, arg3, entry);
    if (result != 0) {
        OSReport(msg + 0xA4C, result);
        entry->inUse = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling reset

#pragma scheduling invalid_target
int fn_8003B9CC(void *arg0, void *arg1) {
    const char *msg = lbl_80302848;
    DVDLowContext *ctx;
    int result;
    lbl_8055D8E0 = 1;
    ctx = newContext(arg1, 1, msg);
    nextCommandBuf();
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0xAB;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = (unsigned int)arg0;
    result = IOS_IoctlAsync(lbl_80558E18, 0xAB, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, ctx);
    if (result != 0) {
        OSReport(msg + 0xA80, result);
        ctx->inUse = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling reset
int fn_8003BB48(void) {
    return ((int *)lbl_8037B8A0)[1];
}

int fn_8003BB58(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    unsigned char *base;
    int slot;
    unsigned char *entry;
    unsigned char *callbackEntry;
    unsigned int busy;
    int next;
    int result;
    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x7A;
    lbl_8055D8E0 = 1;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    entry = base + slot * 0x20;
    busy = entry[8];
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = base + (slot << 5);
    result = IOS_IoctlAsync(lbl_80558E18, 0x7A,
        lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20,
        &lbl_8037B8C0, 0x20,
        (void (*)(int, void *))doPrepareCoverRegisterCallback,
        callbackEntry);
    if (result != 0) {
        OSReport(msg + 0xB30, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}

void *fn_8003BCC0(void) { return *(void **)&lbl_8037B8A0; }

unsigned int DVDLowUnmaskStatusInterrupts(void) { return 1; }

unsigned int DVDLowMaskCoverInterrupt(void) { return 1; }

#pragma scheduling invalid_target
int fn_8003BCDC(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    unsigned char *base;
    int slot;
    unsigned char *entry;
    unsigned char *callbackEntry;
    unsigned int busy;
    int next;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x86;
    lbl_8055D8E0 = 1;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    entry = base + slot * 0x20;
    busy = entry[8];
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = base + slot * 0x20;
    result = IOS_IoctlAsync(lbl_80558E18, 0x86, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, callbackEntry);
    if (result != 0) {
        OSReport(msg + 0xB74, result);
        result = 0;
        callbackEntry[8] = result;
        return result;
    }
    return 1;
}
#pragma scheduling reset
int fn_8003BE40(void) { return 0; }

