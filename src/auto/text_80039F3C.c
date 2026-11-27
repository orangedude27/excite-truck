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
#define FatalFunc FatalFunc_8055D8D8 /* automatic DVD fatal-message callback */
extern unsigned char lbl_80560B08, lbl_80560B09, lbl_80560B0A, lbl_80560B0B;
extern const char *lbl_802EE878[];
extern char __ErrorInfo[];
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts();
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
/* NAND close callback: report success (1) or failure (2) through the registered error-report callback, if any. */
void fn_80039F3C(int result) { if (sNandErrorReportCallback != 0) { sNandErrorReportCallback(result == 0 ? 1 : 2, 0); } }

/* NAND async step after writing dvderror.dat: close the file and report failure. */
void fn_80039F68(int result) {
    if (NANDCloseAsync(sNandDvderrorFileInfo, fn_80039F3C, sNandDvderrorCmdBlock) != 0 &&
        sNandErrorReportCallback != 0) {
        sNandErrorReportCallback(2, 0);
    }
}

void fn_80039FC4(int arg0) {
    struct NandErrorData {
        char info[0x90];
        char cmd[0xD0];
        char data[0x80];
    };
    struct NandErrorData *base = (struct NandErrorData *)lbl_8037B640;
    if (arg0 == 0) {
        if (NANDWriteAsync(&base->info[0], &base->data[0], 0x80, fn_80039F68, &base->cmd[0]) != 0 &&
            NANDCloseAsync(&base->info[0], fn_80039F3C, &base->cmd[0]) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
    } else if (lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
}

/* NAND async step: open/create /shared2/test/dvderror.dat, or report failure via the registered callback. */
void fn_8003A074(int result) {
    if (result == 0 || result == -6) {
        if (NANDPrivateOpenAsync(sDvderrorPath, sNandDvderrorFileInfo, 2, fn_80039FC4, sNandDvderrorCmdBlock) != 0 &&
            sNandErrorReportCallback != 0) {
            sNandErrorReportCallback(2, 0);
        }
    } else if (sNandErrorReportCallback != 0) {
        sNandErrorReportCallback(2, 0);
    }
}

extern int NANDPrivateCreateAsync(const char *, int, void *, void *, void *);
extern char lbl_80302368[];
extern void fn_8003A074(int);
/* NAND async step after creating the error-report directory: create /shared2/test/dvderror.dat
 * or report failure via the registered callback. */
void fn_8003A10C(int result) {
    if (result == 0 || result == -6) {
        if (NANDPrivateCreateAsync(sDvderrorPath, 0x3F, 0, fn_8003A074, sNandDvderrorCmdBlock) != 0 &&
            sNandErrorReportCallback != 0) {
            sNandErrorReportCallback(2, 0);
        }
    } else if (sNandErrorReportCallback != 0) {
        sNandErrorReportCallback(2, 0);
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
#pragma opt_propagation off
void __DVDShowFatalMessage(void) {
#define sFatalMessages    lbl_802EE878
#define kJapaneseLanguage 0
#define kMaxLanguage      6
#define kFallbackLanguage 1
    /* Display the localized DVD fatal message: select the font encoding for
       Japanese, pick the message for the system language (falling back to
       English), and show it in white on black via OSFatal. */
    unsigned char color[4];
    unsigned int zero;
    int foreground;
    int background;
    const char *message;

    zero = 0;
    color[0] = lbl_80560B08;
    color[1] = lbl_80560B09;
    color[2] = lbl_80560B0A;
    color[3] = lbl_80560B0B;
    if (SCGetLanguage() == kJapaneseLanguage) {
        OSSetFontEncode(1);
    } else {
        OSSetFontEncode(0);
    }
    if (SCGetLanguage() > kMaxLanguage) {
        message = sFatalMessages[kFallbackLanguage];
    } else {
        message = sFatalMessages[SCGetLanguage()];
    }
    foreground = *(int *)color;
    background = zero;
    OSFatal(&foreground, &background, message);
#undef sFatalMessages
#undef kJapaneseLanguage
#undef kMaxLanguage
#undef kFallbackLanguage
}
#pragma opt_propagation reset
extern void __DVDShowFatalMessage(void);
extern void (*lbl_8055D8D0)(int, int);
int DVDSetAutoFatalMessaging(int enable) {
    /* Enable or disable the automatic DVD fatal-error message handler, returning whether
     * it was previously enabled. The callback swap is protected by disabled interrupts. */
    int old;
    unsigned int level = OSDisableInterrupts();
    old = FatalFunc != 0;
    if (enable) FatalFunc = __DVDShowFatalMessage;
    else FatalFunc = 0;
    OSRestoreInterrupts(level);
    return old;
}

void __DVDPrintFatalMessage(void) {
    /* Invoke the installed DVD fatal-message printing callback, if one is set. */
    if (FatalFunc_8055D8D8 != 0) {
        FatalFunc_8055D8D8();
    }
}

#pragma scheduling 750
int doTransactionCallback(int intType, void *context) {
#define requestInProgress  lbl_8055D8E0
#define callbackInProgress lbl_8055D8E1
#define breakRequested     lbl_8055D900
#define readLength         lbl_8055D8F4
#define DVD_LOW_CTX_MAGIC  0xFEEBDAED
#define kMangledContextMsg lbl_80302848
    /* DVD low-level transaction-completion callback: validate the context's
       magic, clear the request flag, apply break / transfer-complete flags,
       call the context's callback and mark the context free. */
    struct DvdLowContext {
        int (*callback)(int);
        unsigned int WORD_0x4;
        unsigned char inUse;
        unsigned char pad[3];
        unsigned int magic;
    };
    struct DvdLowContext *ctx = context;
    int result = intType;
    if (ctx->magic != DVD_LOW_CTX_MAGIC) {
        OSReport(kMangledContextMsg);
        ctx->magic = DVD_LOW_CTX_MAGIC;
    } else {
        requestInProgress = 0;
        if (ctx->callback != 0) {
            callbackInProgress = 1;
            if (breakRequested == 1) {
                breakRequested = 0;
                result |= 8;
            }
            if (result & 1) {
                readLength = 0;
            }
            ctx->callback(result);
            callbackInProgress = 0;
        }
    }
    ctx->inUse = 0;
    return 0;
#undef requestInProgress
#undef callbackInProgress
#undef breakRequested
#undef readLength
#undef DVD_LOW_CTX_MAGIC
#undef kMangledContextMsg
}
/* DVD low-level cover-register callback: validates the context, updates flags, and invokes the registered callback. */
int doPrepareCoverRegisterCallback(int result, void *context) {
    int status = result;

    lbl_8055D8E0 = 0;
    ((unsigned int *)lbl_8037B8A0)[1] = *(unsigned int *)&lbl_8037B8C0;
    if (*(unsigned int *)((char *)context + 0xC) != 0xFEEBDAED) {
        OSReport(lbl_80302848);
        *(unsigned int *)((char *)context + 0xC) = 0xFEEBDAED;
    } else {
        if (*(unsigned int *)context != 0) {
            lbl_8055D8E1 = 1;
            if (lbl_8055D900 == 1) {
                lbl_8055D900 = 0;
                status |= 8;
            }
            ((int (*)(int))*(unsigned int *)context)(status);
            lbl_8055D8E1 = 0;
        }
    }
    *(unsigned char *)((char *)context + 8) = 0;
    return 0;
}
#pragma scheduling reset
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
    int offset = lbl_8055D8E8 * 0x20;
    unsigned char *base = lbl_8037B820;
    int id;
    unsigned int flag;

    flag = *(unsigned char *)(base + offset + 8);
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
    ((DVDLowContext *)lbl_8037B820)[lbl_8055D8E8].inUse = arg2;

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

#pragma push
#pragma scheduling 750
#pragma opt_common_subs off
int DVDLowInit(void) {
    #pragma scheduling on
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
            unsigned int zero = 0;
            DVDLowContext *base = (DVDLowContext *)lbl_8037B820;
            unsigned int magic = 0xFEEBDAED;
            unsigned int one = 1;
            unsigned int id = 2;
            base[0].callback = (void *)zero;
            base[0].WORD_0x4 = zero;
            base[0].inUse = zero;
            base[0].magic = magic;
            base[0].id = zero;
            base[1].callback = (void *)zero;
            base[1].WORD_0x4 = zero;
            base[1].inUse = zero;
            base[1].magic = magic;
            base[1].id = one;
            base[2].callback = (void *)zero;
            base[2].WORD_0x4 = zero;
            base[2].inUse = zero;
            base[2].magic = magic;
            base[2].id = id;
            id = 3;
            base[3].callback = (void *)zero;
            base[3].WORD_0x4 = zero;
            base[3].inUse = zero;
            base[3].magic = magic;
            base[3].id = id;
            lbl_8055D8E8 = zero;
            lbl_8055D8EC = one;
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
#pragma pop
/* DVDLow ioctl 0x70: issue an async low-level DVD command whose 0x20-byte
 * result goes to the caller's buffer. Claims the next context slot (fatally
 * reporting a taken/magic-corrupt slot) and warns on a null buffer, then
 * submits the ioctl through doTransactionCallback; frees the claimed slot if
 * submission fails. Returns 0 on failure, else 1. */
int DVDLowAsyncIoctl(void *buffer, void *callback) {
    #pragma opt_propagation off
    const char *msgBase = lbl_80302848;
    unsigned char *ctx;
    unsigned char *contextTable = lbl_8037B820;
    int offsetBytes;
    int slotIndex = lbl_8055D8E8;
    unsigned char *callbackCtx;
    unsigned int one = 1;
    unsigned int inUse;
    int nextIndex;
    int result;

    offsetBytes = slotIndex * 0x20;
    ctx = contextTable + offsetBytes;
    inUse = ctx[8];
    lbl_8055D8E0 = one;
    if (((-inUse) | inUse) >> 31 == 1U)
    {
        OSReport(msgBase + 0x218, slotIndex);
        OSReport(msgBase + 0x250);
        for (;;)
        {
        }
    }
    if (((*((unsigned int *)(ctx + 0xC))) + 0x01150000U) != 0xDAEDU)
    {
        OSReport(msgBase + 0x280);
        for (;;)
        {
        }
    }
    ((unsigned int *)contextTable)[slotIndex * 8] = (unsigned int)callback;
    *((unsigned int *)((contextTable + offsetBytes) + 4)) = one;
    (contextTable + offsetBytes)[8] = one;
    nextIndex = slotIndex + 1;
    lbl_8055D8E8 = nextIndex;
    if (nextIndex >= 4)
    {
        lbl_8055D8E8 = 0;
    }
    callbackCtx = (unsigned char *)&((DVDLowContext *)lbl_8037B820)[slotIndex];
    if (buffer == 0)
    {
        OSReport(msgBase + 0x2C0);
    }
    nextCommandBuf();
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0x70;
    result = IOS_IoctlAsync(lbl_80558E18, 0x70, lbl_8055D8FC + (lbl_8055D8E4 * 0x20), 0x20, buffer, 0x20, (void (*)(int, void *))doTransactionCallback, callbackCtx);
    if (result != 0)
    {
        OSReport(msgBase + 0x2FC, result);
        callbackCtx[8] = 0;
        return 0;
    }
    return 1;
}
extern int IOS_IoctlvAsync(int, int, int, int, void *, void *, void *);
extern int doTransactionCallback(int, void *);
#pragma scheduling 750
#pragma opt_propagation off
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
#pragma opt_propagation reset
extern unsigned int lbl_8055D8E4, lbl_8055D8E8;
extern unsigned char *lbl_8055D8FC;
extern unsigned int lbl_80558E18;
extern unsigned char lbl_8037B820[];
extern int IOS_IoctlAsync(int, int, void *, int, void *, int, void (*)(int, void *), void *);
#pragma scheduling on
int fn_8003AC24(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    DVDLowContext *ctx;
    DVDLowContext *base;
    unsigned int busy;
    int slot;
    unsigned char *callbackEntry;
    unsigned int one;
    int next;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x8C;
    one = 1;
    lbl_8055D8E0 = one;
    base = (DVDLowContext *)lbl_8037B820;
    slot = lbl_8055D8E8;
    ctx = &base[slot];
    busy = ctx->inUse;
    if ((((0U - busy) | busy) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    busy = ctx->magic;
    if ((busy + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    ctx->WORD_0x4 = one;
    ctx->inUse = one;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = (unsigned char *)lbl_8037B820 + slot * 0x20;
    result = IOS_IoctlAsync(lbl_80558E18, 0x8C, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, callbackEntry);
    if (result != 0) {
        OSReport(msg + 0x3E8, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling reset

/* DVDLow async raw-DI command 0x8D: build a 0x20-byte command block (command byte,
 * length and input) in the next command-buffer slot and submit it through
 * IOS_IoctlAsync using buffer/length as the transfer. Frees the claimed context
 * if dispatch fails; returns 0 on failure, else 1. */
/* Queue an asynchronous DVD low-level unencrypted read (ioctl 0x8D): build the command block in the next buffer slot with the transfer length and disc offset, submit it with buffer/length as the data transfer, and release the claimed context slot if dispatch fails. Returns 0 on failure, 1 on success. */ int DVDLowUnencryptedReadAsync(void *buffer, int length, int offset, void *callback) {
    const char *msgBase = lbl_80302848;
    unsigned int one = 1;
    unsigned char *callbackContext;
    int ioResult;

    lbl_8055D8E0 = one;
    callbackContext = (unsigned char *)newContext(callback, one, msgBase);
    lbl_8055D8F4 = length;
    nextCommandBuf();
    *(unsigned char *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20) = 0x8D;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = length;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = offset;
    if ((ioResult = IOS_IoctlAsync(lbl_80558E18, 0x8D, lbl_8055D8FC + lbl_8055D8E4 * 0x20,
                              0x20, buffer, length, (void (*)(int, void *))doTransactionCallback, callbackContext)) != 0) {
        OSReport(msgBase + 0x428, ioResult);
        callbackContext[8] = 0;
        return 0;
    }
    return 1;
}

#pragma opt_propagation off
/* DVDLow async raw-DI read: queue command 0xE3 in the next command-buffer slot and
 * dispatch it through IOS_IoctlAsync, reporting the IOS error if the dispatch fails. */
/* Queues an async raw DI read of command 0xE3 with the given offset and length, dispatching it through IOS and reporting an error if dispatch fails. */ int DVDLowRawReadAsync(int offset, int length, int callback) {
    const char *msg = lbl_80302848;
    unsigned int one = 1;
    unsigned char *context;
    int result;

    lbl_8055D8E0 = one;
    context = (unsigned char *)newContext((void *)callback, one, msg);
    nextCommandBuf();
    *(unsigned char *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20) = 0xE3;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = offset;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = length;
    result = IOS_IoctlAsync(lbl_80558E18, 0xE3, lbl_8055D8FC + lbl_8055D8E4 * 0x20,
                            0x20, lbl_8037B8A0, 0x20,
                            (void (*)(int, void *))doTransactionCallback, context);
    if (result != 0) {
        OSReport(msg + 0x468, result);
        context[8] = 0;
        return 0;
    }
    return 1;
}
#pragma opt_propagation off
/* DVDLow ioctl 0x12 (disk-ID area read): issue an async low-level DVD command
 * whose 0x20-byte result goes to the caller's buffer.  Claims the next context
 * slot (fatally reporting a taken/magic-corrupt slot), then submits the ioctl
 * through doTransactionCallback; returns 0 if submission failed, else 1. */
int fn_8003B0B0(void *buffer, void *callback) {
    const char *msgBase = lbl_80302848;
    unsigned char *contexts = lbl_8037B820;
    int offsetBytes;
    int ctxIndex = lbl_8055D8E8;
    unsigned char *context;
    unsigned char *callbackContext;
    unsigned int one = 1;
    unsigned int inUse;
    int nextSlot;
    int ioResult;
    offsetBytes = ctxIndex * 0x20;
    context = contexts + offsetBytes;
    inUse = context[8];
    lbl_8055D8E0 = one;
    if (((-inUse) | inUse) >> 31 == 1U)
    {
        OSReport(msgBase + 0x218, ctxIndex);
        OSReport(msgBase + 0x250);
        for (;;)
        {
        }
    }
    if (((*((unsigned int *)(context + 0xC))) + 0x01150000U) != 0xDAEDU)
    {
        OSReport(msgBase + 0x280);
        for (;;)
        {
        }
    }
    ((unsigned int *)contexts)[ctxIndex * 8] = (unsigned int)callback;
    *((unsigned int *)((contexts + offsetBytes) + 4)) = one;
    (contexts + offsetBytes)[8] = one;
    nextSlot = ctxIndex + 1;
    lbl_8055D8E8 = nextSlot;
    if (nextSlot >= 4)
    {
        lbl_8055D8E8 = 0;
    }
    callbackContext = (unsigned char *)&((DVDLowContext *)lbl_8037B820)[ctxIndex];
    nextCommandBuf();
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0x12;
    ioResult = IOS_IoctlAsync(lbl_80558E18, 0x12, lbl_8055D8FC + (lbl_8055D8E4 * 0x20), 0x20, buffer, 0x20, (void (*)(int, void *))doTransactionCallback, callbackContext);
    if (ioResult != 0)
    {
        OSReport(msgBase + 0x4E8, ioResult);
        callbackContext[8] = 0;
        return 0;
    }
    return 1;
}
#pragma opt_propagation reset
int fn_8003B218(void *arg0) {
    unsigned char *p;
    unsigned char *base = lbl_8037B820;
    const char *msg = lbl_80302848;
    int offset;
    unsigned int flag;
    int slot = lbl_8055D8E8;
    unsigned int one = 1;
    unsigned char *entry;
    int index;
    int result;
    offset = slot << 5;
    lbl_8055D8E0 = one;
    p = base + offset;
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
    entry = lbl_8037B820 + slot * 0x20;
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
    /* Store the parameter copied into the next low-level ioctl request, then report success. */
    lbl_8055D8F0 = value;
    return 1;
}

#pragma scheduling on
#pragma opt_propagation off
int fn_8003B38C(void *arg0) {
    unsigned char *p;
    unsigned char *base = lbl_8037B820;
    const char *msg = lbl_80302848;
    int offset;
    unsigned int flag;
    int slot = lbl_8055D8E8;
    unsigned int one = 1;
    unsigned char *entry;
    int index;
    int result;

    offset = slot << 5;
    lbl_8055D8E0 = one;
    p = base + offset;
    flag = p[8];
    if ((((0U - flag) | flag) >> 31) == 1U) {
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
    entry = lbl_8037B820 + slot * 0x20;
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
int fn_8003B508(int arg0, int arg1, int arg2)
{
  const char *msg = lbl_80302848;
  unsigned char *base = lbl_8037B820;
  int slot = lbl_8055D8E8;
  unsigned char *entry;
  unsigned char *callbackEntry;
  unsigned int one = 1;
  unsigned int flag;
  int index;
  int result;
  {
    int offset = slot * 0x20;
    flag = (base + offset)[8];
    lbl_8055D8E0 = one;
    if ((((-flag) | flag) >> 31) == 1U)
    {
      OSReport(msg + 0x218, slot);
      OSReport(msg + 0x250);
      for (;;)
      {
      }

    }
    if (((*((unsigned int *) ((base + offset) + 0xC))) + 0x01150000U) != 0xDAEDU)
    {
      OSReport(msg + 0x280);
      for (;;)
      {
      }

    }
    ((unsigned int *) base)[slot * 8] = arg2;
    index = slot + 1;
    *((unsigned int *) ((base + offset) + 4)) = one;
    (base + offset)[8] = one;
  }
  lbl_8055D8E8 = index;
  if (index >= 4)
  {
    lbl_8055D8E8 = 0;
  }
  callbackEntry = ((unsigned char *) lbl_8037B820) + (slot * 0x20);
  index = lbl_8055D8E4 + 1;
  lbl_8055D8E4 = index;
  if (index >= 4)
  {
    index = 0;
    lbl_8055D8E4 = 0;
  }
  lbl_8055D8FC[index * 0x20] = 0xE4;
  *((int *) ((lbl_8055D8FC + ((*((volatile unsigned int *) (&lbl_8055D8E4))) * 0x20)) + 4)) = arg0;
  *((int *) ((lbl_8055D8FC + ((*((volatile unsigned int *) (&lbl_8055D8E4))) * 0x20)) + 8)) = arg1;
  result = IOS_IoctlAsync(lbl_80558E18, 0xE4, lbl_8055D8FC + ((*((volatile unsigned int *) (&lbl_8055D8E4))) * 0x20), 0x20, lbl_8037B8A0, 0x20, (void (*)(int, void *)) doTransactionCallback, callbackEntry);
  if (result != 0)
  {
    OSReport(msg + 0x618, result);
    callbackEntry[8] = 0;
    return 0;
  }
  return 1;
}
#pragma scheduling 750
int fn_8003B69C(int arg0, void *arg1)
{
  const char *new_var;
  unsigned char **new_var2;
  const char *msg = lbl_80302848;
  unsigned char *base = lbl_8037B820;
  unsigned int slot = lbl_8055D8E8;
  int offset = slot * 0x20;
  unsigned char *entry = base + offset;
  unsigned char *callbackEntry;
  unsigned int one = 1;
  unsigned int flag = entry[8];
  int next;
  int index;
  int result;
  lbl_8055D8E0 = one;
  if ((((-flag) | flag) >> 31) == 1U)
  {
    OSReport(msg + 0x218, slot);
    OSReport(msg + 0x250);
    for (;;)
    {
    }

  }
  if (((*((unsigned int *) (entry + 0xC))) + 0x01150000U) != 0xDAEDU)
  {
    OSReport(msg + 0x280);
    for (;;)
    {
      if (1)
      {
      }
    }

  }
  ((unsigned int *) base)[slot * 8] = (unsigned int) arg1;
  new_var2 = &entry;
  *((unsigned int *) ((*new_var2) + 4)) = one;
  entry[8] = one;
  next = slot + 1;
  lbl_8055D8E8 = next;
  if (next >= 4)
  {
    lbl_8055D8E8 = 0;
    if (1)
    {
    }
  }
  callbackEntry = ((unsigned char *) lbl_8037B820) + (slot * 0x20);
  index = lbl_8055D8E4 + 1;
  lbl_8055D8E4 = index;
  if (index >= 4)
  {
    index = 0;
    lbl_8055D8E4 = 0;
  }
  lbl_8055D8FC[index * 0x20] = 0xDD;
  *((unsigned int *) ((lbl_8055D8FC + (lbl_8055D8E4 * 0x20)) + 4)) = (unsigned int) ((arg0 >> 16) & 3);
  result = IOS_IoctlAsync(lbl_80558E18, 0xDD, lbl_8055D8FC + (lbl_8055D8E4 * 0x20), 0x20, 0, slot * 0, (void (*)(int, void *)) doTransactionCallback, callbackEntry);
  if (result != 0)
  {
    OSReport(new_var = msg + 0x9CC, result);
    callbackEntry[8] = 0;
    return 0;
  }
  return 1;
}
#pragma scheduling on
/* Queue an async DVD low-level read (command 0x71) of `size` bytes at disc `offset` into `dst`, claiming a context slot and calling `callback` when it completes; returns 0 for a misaligned buffer or IOS error, 1 when queued. */
/* Queue an async DVD low-level read into a free context slot and invoke the callback on completion. */ int DVDLowReadAsync(void *dst, int size, int offset, void (*callback)(int, void *)) {
    const char *msgs = lbl_80302848;
    unsigned char *contexts;
    int byteOffset;
    int slot;
    unsigned char *entry;
    unsigned char *callbackCtx;
    unsigned int one;
    unsigned int inUse;
    int next;
    int result;

    if (((unsigned int)dst & 0x1F) != 0) {
        OSReport(msgs + 0xA0C);
        return 0;
    }

    slot = lbl_8055D8E8;
    one = 1;
    byteOffset = slot * 0x20;
    contexts = lbl_8037B820;
    entry = contexts + byteOffset;
    lbl_8055D8E0 = one;
    inUse = entry[8];
    if ((((-inUse) | inUse) >> 31) == 1U) {
        OSReport(msgs + 0x218, slot);
        OSReport(msgs + 0x250);
        for (;;) {}
    }
    if (((*(unsigned int *)(entry + 0xC)) + 0x01150000U) != 0xDAEDU) {
        OSReport(msgs + 0x280);
        for (;;) {}
    }
    ((unsigned int *)contexts)[slot * 8] = (unsigned int)callback;
    *((unsigned int *)((contexts + byteOffset) + 4)) = one;
    (contexts + byteOffset)[8] = one;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) lbl_8055D8E8 = 0;

    callbackCtx = (unsigned char *)&((DVDLowContext *)lbl_8037B820)[slot];
    lbl_8055D8F4 = size;
    nextCommandBuf();
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0x71;
    *((unsigned int *)((lbl_8055D8FC + (lbl_8055D8E4 * 0x20)) + 4)) = (unsigned int)size;
    *((unsigned int *)((lbl_8055D8FC + (lbl_8055D8E4 * 0x20)) + 8)) = (unsigned int)offset;
    result = IOS_IoctlAsync(lbl_80558E18, 0x71, lbl_8055D8FC + (lbl_8055D8E4 * 0x20),
        0x20, dst, size, (void (*)(int, void *))doTransactionCallback, callbackCtx);
    if (result != 0) {
        OSReport(msgs + 0xA4C, result);
        callbackCtx[8] = 0;
        return 0;
    }
    return 1;
}
/* DVDLowSeek: issue an async DVD low-level seek to the given byte offset.
 * Claims the next context slot (fatally reporting a taken/magic-corrupt slot),
 * stores the seek offset in the command buffer, and submits ioctl 0xAB through
 * doTransactionCallback; returns 0 if the submission failed, else 1. */
int fn_8003B9CC(void *offset, void *callback)
{
  const char *msgBase = lbl_80302848;
  unsigned char *contexts = lbl_8037B820;
  int offsetBytes;
  int ctxIndex = lbl_8055D8E8;
  unsigned char *context;
  unsigned char *callbackContext;
  unsigned int one = 1;
  unsigned int inUse;
  int nextSlot;
  int ioResult;
  offsetBytes = ctxIndex * 0x20;
  context = contexts + offsetBytes;
  inUse = context[8];
  lbl_8055D8E0 = one;
  if ((((-inUse) | inUse) >> 31) == 1U)
  {
    OSReport(msgBase + 0x218, ctxIndex);
    OSReport(msgBase + 0x250);
    for (;;)
    {
    }
  }
  if (((*((unsigned int *) (context + 0xC))) + 0x01150000U) != 0xDAEDU)
  {
    OSReport(msgBase + 0x280);
    for (;;)
    {
    }
  }
  ((unsigned int *) contexts)[ctxIndex * 8] = (unsigned int) callback;
  *((unsigned int *) ((contexts + offsetBytes) + 4)) = one;
  (contexts + offsetBytes)[8] = one;
  nextSlot = ctxIndex + 1;
  lbl_8055D8E8 = nextSlot;
  if (nextSlot >= 4)
  {
    lbl_8055D8E8 = 0;
  }
  callbackContext = (unsigned char *)&((DVDLowContext *)lbl_8037B820)[ctxIndex];
  nextCommandBuf();
  lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0xAB;
  *((unsigned int *) ((lbl_8055D8FC + (lbl_8055D8E4 * 0x20)) + 4)) = (unsigned int) offset;
  ioResult = IOS_IoctlAsync(lbl_80558E18, 0xAB, lbl_8055D8FC + (lbl_8055D8E4 * 0x20), 0x20, 0, 0, (void (*)(int, void *)) doTransactionCallback, callbackContext);
  if (ioResult != 0)
  {
    OSReport(msgBase + 0xA80, ioResult);
    callbackContext[8] = 0;
    return 0;
  }
  return 1;
}
int fn_8003BB48(void) {
    #define sDriveStatusBuffer lbl_8037B8A0 /* 32-byte IOS cover-register ioctl result buffer */
    /* Return the DVD drive/cover status word (buffer +4) from the last
       cover-register read; callers test bit 0 for cover-open and bit 2. */
    return ((int *)sDriveStatusBuffer)[1];
    #undef sDriveStatusBuffer
}

#pragma scheduling reset
#pragma opt_lifetimes off
int fn_8003BB58(void *arg0)
{
  const char *msg = lbl_80302848;
  int index = lbl_8055D8E4 + 1;
  DVDLowContext *ctx;
  DVDLowContext *base;
  unsigned int busy;
  int slot;
  unsigned char *callbackEntry;
  unsigned int one;
  int next;
  int result;
  lbl_8055D8E4 = index;
  if (index >= 4)
  {
    index = 0;
    lbl_8055D8E4 = 0;
  }
  lbl_8055D8FC[index * 0x20] = 0x7A;
  one = 1;
  lbl_8055D8E0 = one;
  base = (DVDLowContext *) lbl_8037B820;
  slot = lbl_8055D8E8;
  ctx = &base[slot];
  busy = ctx->inUse;
  if ((((next = busy) | (0U - busy)) >> 31) == 1)
  {
    OSReport(msg + 0x218);
    OSReport(msg + 0x250);
    for (;;)
    {
    }

  }
  if ((ctx->magic + 0x01150000U) != 0xDAEDU)
  {
    OSReport(msg + 0x280);
    for (;;)
    {
    }

  }
  ((unsigned int *) base)[slot * 8] = (unsigned int) arg0;
  ctx->WORD_0x4 = one;
  ctx->inUse = one;
  next = slot + 1;
  lbl_8055D8E8 = next;
  if (next >= 4)
  {
    next = 0;
    lbl_8055D8E8 = 0;
  }
  callbackEntry = ((unsigned char *) lbl_8037B820) + (slot * 0x20);
  result = IOS_IoctlAsync(lbl_80558E18, 0x7A, lbl_8055D8FC + (lbl_8055D8E4 * 0x20), 0x20, &lbl_8037B8C0, 0x20, (void (*)(int, void *)) doPrepareCoverRegisterCallback, callbackEntry);
  if (result != 0)
  {
    OSReport(msg + 0xB30, result);
    callbackEntry[8] = 0;
    return 0;
  }
  return 1;
}
#pragma opt_lifetimes reset
/* Return the first word of the 32-byte DVD low-level ioctl result buffer (lbl_8037B8A0): the drive's current task-type/error status word. */
void *fn_8003BCC0(void) { return *(void **)&lbl_8037B8A0; }

/* DVD low-level: unmask status interrupts. On Broadway this is a no-op stub that always reports success (TRUE). */
unsigned int DVDLowUnmaskStatusInterrupts(void) { return 1; }

/* DVD low-level: mask the cover interrupt. On Broadway this is a no-op stub that always reports success (TRUE). */
unsigned int DVDLowMaskCoverInterrupt(void) { return 1; }

#pragma scheduling on
int fn_8003BCDC(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    DVDLowContext *ctx;
    DVDLowContext *base;
    unsigned int busy;
    int slot;
    unsigned char *callbackEntry;
    unsigned int one;
    int next;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x86;
    one = 1;
    lbl_8055D8E0 = one;
    base = (DVDLowContext *)lbl_8037B820;
    slot = lbl_8055D8E8;
    ctx = &base[slot];
    busy = ctx->inUse;
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((ctx->magic + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    ctx->WORD_0x4 = one;
    ctx->inUse = one;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = (unsigned char *)lbl_8037B820 + slot * 0x20;
    result = IOS_IoctlAsync(lbl_80558E18, 0x86, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, callbackEntry);
    if (result != 0) {
        OSReport(msg + 0xB74, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling reset
// Default alarm-test predicate: always answers "false" (0).  __DVDTestAlarm
// uses it as the fallback for alarms other than the DVD timeout alarm.
int fn_8003BE40(void) { return 0; }

