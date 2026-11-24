// nandsave — NAND saves/banner ("NANDWriteAsync", banner.bin).
// Recovered TU window 0x802E86D4..0x802E988C (see docs/attribution_analysis.md).
// Static-init thunk fn_802E988C (+ .ctors slot 0x802ED61C) remains in
// auto/text_802E988C_.c pending a promotion pass.
extern int fn_802E2C20(void);
__declspec(section ".data") extern int lbl_80507288;
extern int NANDCheck(unsigned int, unsigned int, unsigned int *);
extern char lbl_8034D9C0[];
// split_file divides it into the game's real files (file_status shows its range).
extern int fn_802E95E0(void *, void (*)(void), int);
extern void fn_802E9010(void);
extern int NANDInit(void);
extern void fn_802E317C(const char *, ...);
extern void fn_801282F4(void);
extern void fn_801282EC(int);
extern int fn_8012850C(int, const char *);
extern void fn_802E6B50(void);
extern void fn_80127C90(void *, void *);
extern void KERNEL_AddResetCallback(void *, void *);
extern int fn_802E8C6C(int);
extern char lbl_8034DED4[];
extern char lbl_8034DEF4[];
extern char lbl_8055D248;
extern char lbl_8055D250;
extern char lbl_8034DEC4[];
extern char lbl_8034DF00[];
extern int lbl_80560020;
extern void fn_802E6B94(void);
extern void fn_80127D58(void *);
extern void fn_80128670(int);

extern int lbl_8056002C;
extern char lbl_8034E108[];
extern void rmemcardWriteStep(void *);
extern unsigned int fn_802E91BC(int *);
extern int fn_802E91AC(int *);
extern void NandBeginWrite(void *, const char *, int, int);
extern void fn_802E9160(void *);
extern void fn_802E9118(void *);
extern char lbl_80560028;
extern int lbl_80560030;
extern void *lbl_80560024;
extern char lbl_80560034;
extern char lbl_8034DD78[];
extern char lbl_8034DE94[];
extern void fn_802E30C8(const char *, ...);
extern void rmemcardDeleteFile(const char *);
extern int fn_802E888C(int);
extern char lbl_8034DB28[];
extern void fn_802E86D4(void);
extern void fn_802E870C(void);
extern int fn_802E8744(void *);
extern void fn_80127464(void);
extern int NANDDelete(const char *);
extern char lbl_8034DE54[];
extern char lbl_8034DE6C[];

#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_802E86D4(void) {
    /* Start the NAND-save manager (virtual slot 0x8) and mark it initialized;
     * fn_802E870C is the matching shutdown that clears the flag. */
    struct NandSaveManager { virtual void start(); };
    ((NandSaveManager *)lbl_80560024)->start();
    lbl_80560028 = 1;
}
#pragma cplusplus on
extern "C" void fn_802E870C(void) {
#define gNandSaveInterface lbl_80560024
#define gNandSaveActive lbl_80560028
    /* Leave the NAND-save subsystem: call the interface's shutdown callback and clear its active flag. */
    struct NandSaveInterface {
        virtual void startup();
        virtual void shutdown();
    };
    ((NandSaveInterface *)gNandSaveInterface)->shutdown();
    gNandSaveActive = 0;
#undef gNandSaveActive
#undef gNandSaveInterface
}
#pragma cplusplus off
extern int fn_80131234(int, int, int, int, int, int, int, int);
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" int fn_802E8744(void *request) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual int f2(int *);
    };
    volatile int *p = (volatile int *)request;
    int v13, v12, v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    int normalizedRequest[14];
    int *dest;
    int wordIndex;

    /* Copy a NAND-save request entry, normalize selected fields via fn_80131234, then dispatch it. */
    v0 = p[0]; v1 = p[1]; v2 = p[2]; v3 = p[3];
    v4 = p[4]; v5 = p[5]; v6 = p[6]; v7 = p[7];
    v8 = p[8]; v9 = p[9]; v10 = p[10]; v11 = p[11];
    v12 = p[12]; v13 = p[13];
    normalizedRequest[0] = v0; normalizedRequest[1] = v1; normalizedRequest[2] = v2; normalizedRequest[3] = v3;
    normalizedRequest[4] = v4; normalizedRequest[5] = v5; normalizedRequest[6] = v6; normalizedRequest[7] = v7;
    normalizedRequest[8] = v8; normalizedRequest[9] = v9; normalizedRequest[10] = v10; normalizedRequest[11] = v11;
    normalizedRequest[12] = v12; normalizedRequest[13] = v13;
    normalizedRequest[1] = fn_80131234(v1, v12, v11, v10, v9, v8, v7, v6);
    dest = normalizedRequest;
    p = (volatile int *)request;
    for (wordIndex = 0; wordIndex < 4; wordIndex++) {
        int stringKey = p[6];
        if (stringKey != 0) dest[6] = ((int (*)(int))fn_80131234)(stringKey);
        p += 2;
        dest += 2;
    }
    return ((Dummy *)lbl_80560024)->f2(normalizedRequest);
}
#pragma cplusplus off
/* rmemcard yield callback (rmemcard_yield): the NAND async wait calls this to
 * keep the system responsive, forwarding to the periodic task pump that drains
 * home-button work and dispatches background tasks. */
void fn_802E8838(void) {
    fn_80127464();
}

#define nandSaveRefCount lbl_8056002C
#define nandSaveInit fn_802E86D4
/* Enters the NAND-save subsystem: lazily initializes it on first use (refcount 0), then increments the use count. */
void fn_802E883C(void) {
    if (nandSaveRefCount == 0) {
        nandSaveInit();
    }
    nandSaveRefCount += 1;
}
#undef nandSaveInit
#undef nandSaveRefCount

#define nandSaveRefCount lbl_8056002C
#define nandSaveShutdown fn_802E870C
/* Leaves the NAND-save subsystem: decrement the use count and shut it down when the last user exits (count reaches 0). */
void fn_802E8874(void) {
    nandSaveRefCount -= 1;
    if (nandSaveRefCount == 0) {
        nandSaveShutdown();
    }
}
#undef nandSaveShutdown
#undef nandSaveRefCount

/* Dispatches a NAND-save request table entry by index, bracketing it with the save subsystem refcount. */
int fn_802E888C(int requestIndex) {
    int result;
    ((void (*)(void))fn_802E883C)();
    result = fn_802E8744(lbl_8034DB28 + requestIndex * 0x38);
    ((void (*)(void))fn_802E8874)();
    return result;
}

#pragma scheduling invalid_target
int fn_802E88D8(void) {
#define nandDispatchRequest fn_802E888C
#define gNandSaveInvalid lbl_80560034
    /* Poll NAND request 0; if it completes, flag the save invalid and report failure. */
    if (nandDispatchRequest(0) != 0) {
        gNandSaveInvalid = 1;
        return 1;
    }
    return 0;
#undef nandDispatchRequest
#undef gNandSaveInvalid
}
#pragma scheduling on
/* Request a kernel reset into the Wii home menu (reset mode 1); used on fatal NAND errors. */
void fn_802E8918(void) {
    KERNEL_Reset(1);
}

#pragma scheduling invalid_target
void fn_802E8920(int requestedFreeBytes) {
    /* Recover free NAND space: see how far over its block/file limits the title is, print a
     * warning for each exceeded limit, then keep running recovery requests until the check
     * comes back clean; a fatal NANDCheck error is logged and reported instead. */
#define rmemcard_log_strings lbl_8034D9C0
#define nandLogPrintf        fn_802E30C8
#define nandDispatchRequest  fn_802E888C
#define rmemcardSpaceReady   fn_802E88D8
#define rmemcardResetHome    fn_802E8918
#define APP_BLOCKS_OVER 1 /* NAND_CHECK_TOO_MANY_APP_BLOCKS */
#define APP_FILES_OVER  2 /* NAND_CHECK_TOO_MANY_APP_FILES */
#define ANY_LIMIT_OVER  0xF
#define BLOCKS_OVER     5 /* app or user blocks are over their limit */
    unsigned int nandCheckFlags = 0;
    char *logStrings = rmemcard_log_strings;
    int nandCheckResult = NANDCheck((requestedFreeBytes + 0x3FFF) / 0x4000 + 4, 2, &nandCheckFlags);
    if (nandCheckResult == 0) {
        for (;;) {
        loop:
            if (nandCheckFlags & APP_BLOCKS_OVER) {
                nandLogPrintf(logStrings + 0x328);
            }
            if (nandCheckFlags & APP_FILES_OVER) {
                nandLogPrintf(logStrings + 0x35C);
            }
            if (nandCheckFlags & ANY_LIMIT_OVER) {
                int requestIndex = 3;
                if (nandCheckFlags & BLOCKS_OVER) {
                    requestIndex = 2;
                }
                if (nandDispatchRequest(requestIndex) != 0) {
                    rmemcardResetHome();
                    break;
                }
                if (rmemcardSpaceReady() == 0) goto loop;
                break;
            } else {
                if (nandDispatchRequest(7) != 0) {
                    break;
                }
                if (rmemcardSpaceReady() == 0) goto loop;
                break;
            }
        }
    } else {
        nandLogPrintf(logStrings + 0x398, nandCheckResult);
    }
#undef rmemcard_log_strings
#undef nandLogPrintf
#undef nandDispatchRequest
#undef rmemcardSpaceReady
#undef rmemcardResetHome
#undef APP_BLOCKS_OVER
#undef APP_FILES_OVER
#undef ANY_LIMIT_OVER
#undef BLOCKS_OVER
}

/* Check that the title's banner.bin exists and is exactly 0xF0A0 bytes. */ int fn_802E8A18(void) {
    char fileInfo[0x8C];
    unsigned int fileLength;
    int openResult;
    int bannerValid = 0;
    /* Check that the title's banner.bin exists and is exactly 0xF0A0 bytes. */
    openResult = NANDOpen(lbl_8034D9C0 + 0x3B8, fileInfo, 1);
    if (openResult == 0) {
        fileLength = 0;
        if (NANDGetLength(fileInfo, &fileLength) == 0) {
            if (fileLength == 0xF0A0) {
                fn_802E30C8(lbl_8034D9C0 + 0x3C4);
                bannerValid = 1;
            } else {
                fn_802E30C8(lbl_8034D9C0 + 0x3EC, fileLength, 0xF0A0);
            }
        } else {
            fn_802E30C8(lbl_8034D9C0 + 0x428);
        }
        NANDClose(fileInfo);
    } else {
        fn_802E30C8(lbl_8034D9C0 + 0x460, openResult);
    }
    return bannerValid;
}

#pragma scheduling on
int fn_802E8AE8(const char *path) {
    /* Return 1 if the NAND file at `path` can be opened for reading, else 0. */
    unsigned char fileInfo[0x88];
    int exists = 0;
    if (NANDOpen((void *)path, fileInfo, 1) == 0) {
        exists = 1;
        NANDClose(fileInfo);
    }
    return exists;
}

void rmemcardDeleteFile(const char *path) {
    /* Logs the NAND delete attempt and reports an error if NANDDelete fails. */
    fn_802E30C8(lbl_8034DE54, path);
    {
        int result = NANDDelete(path);
        if (result != 0) {
            fn_802E30C8(lbl_8034DE6C, result, path);
        }
    }
}

void fn_802E8B98(void) {
    /* Delete the currently selected NAND file, appending "banner.bin"; report if no file is selected. */
    if (lbl_80560030 != 0) {
        rmemcardDeleteFile((const char *)lbl_80560030);
        rmemcardDeleteFile(lbl_8034DD78);
    } else {
        fn_802E30C8(lbl_8034DE94);
    }
}

int rmemcardRecover(void) {
    /* Poll NAND request 1 until it completes; on success run cleanup and return 1, else 0. */
    for (;;) {
        if (((int (*)(int))fn_802E888C)(1) != 0) {
            fn_802E8B98();
            return 1;
        }
        if (fn_802E88D8() != 0)
            return 0;
    }
}

#pragma dont_inline reset

extern int fn_8012C4D8(int);
extern int fn_802E88D8(void);
void rmemcardCorruptReset(void) {
    /* After a corrupt NAND read: poll request 4 until it completes, then run fn_802E8918 (home-menu mode 1); return early if request 0 completes first. */
    for (;;) {
        if (((int (*)(int))fn_802E888C)(4) != 0) {
            ((void (*)(void))fn_802E8918)();
            return;
        }
        if (fn_802E88D8() != 0)
            return;
    }
}

int fn_802E8C6C(int request) {
#define KERNEL_RESET_NOTIFY 1
#define rmemcard_wait_async fn_802E95E0
#define rmemcard_pump_async fn_802E9010
#define rmemcard_reset_op_name lbl_8034DEC4
    /* Reset callback registered in fn_802E8CA8: when the reset is actually on,
     * block until the async NAND save machine goes idle, pumping it once per
     * pass; the "reset hander" tag is just the label it logs timeouts under. */
    if (request == KERNEL_RESET_NOTIFY) {
        ((int (*)(const char *, void (*)(void)))rmemcard_wait_async)(rmemcard_reset_op_name, rmemcard_pump_async);
    }
    return 0;
#undef KERNEL_RESET_NOTIFY
#undef rmemcard_wait_async
#undef rmemcard_pump_async
#undef rmemcard_reset_op_name
}

/* Initialize NAND/save subsystem: NAND init, allocator setup, async buffer, callbacks, and handlers. */
/* Initialize the NAND-save subsystem: bring up NAND (panic on failure), set up the allocator and async buffer, then register the save-pump and reset callbacks. */ void fn_802E8CA8(void) {
    int nandInitResult = NANDInit();
    if (nandInitResult != 0) {
        fn_802E317C(lbl_8034DED4, nandInitResult);
    }
    fn_801282F4();
    fn_801282EC(0x80);
    lbl_80560020 = fn_8012850C(0x55730, lbl_8034DEF4);
    fn_802E6B50();
    fn_80127C90((void *)fn_802E9010, &lbl_8055D248);
    KERNEL_AddResetCallback((void *)fn_802E8C6C, &lbl_8055D250);
}

/* Shut down NAND save: wait for async end, detach save pump, and free the async buffer. */
void fn_802E8D2C(void) {
#define sMemCardEndOpName lbl_8034DF00
#define sNandSaveAsyncBuffer lbl_80560020
    ((int (*)(void *, void (*)(void)))fn_802E95E0)(sMemCardEndOpName, fn_802E8838);
    fn_80127D58((void *)fn_802E9010);
    fn_802E6B94();
    fn_80128670(sNandSaveAsyncBuffer);
    sNandSaveAsyncBuffer = 0;
#undef sMemCardEndOpName
#undef sNandSaveAsyncBuffer
}

extern void *lbl_80560024;
/* Set the active NAND-save interface object pointer (gNandSaveInterface); 0 clears it. */
void fn_802E8D7C(void* saveInterface) {
    lbl_80560024 = saveInterface;
}

typedef unsigned int u32;
extern int fn_8012C4D8(int);
extern int fn_802E88D8(void);
extern int NANDDelete(const char *);
extern char lbl_8034DE54[];
extern char lbl_8034DE6C[];
  extern int NANDOpen(const char *, void *, int);
  extern int NANDGetLength(void *, unsigned int *);
  extern int NANDClose(void *);
extern char lbl_80560034;
extern int fn_802E95E0(void *, void (*)(void), int);
extern int fn_802E2C20(void);
extern char lbl_8034E024[];
__declspec(section ".data") extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern char lbl_8034E130[];
extern void fn_802E317C(const char *, ...);
extern void fn_802E6B94(void);
extern void fn_802E6B50(void);
extern void fn_80127D58(void *);
extern void fn_80128670(int);
extern void fn_801282F4(void);
extern void fn_801282EC(int);
extern int fn_8012850C(int, const char *);
extern void fn_80127C90(void *, void *);
extern void KERNEL_AddResetCallback(void *, void *);
extern int NANDInit(void);
extern void fn_802E8838(void);
extern void fn_802E9010(void);
extern int fn_802E8C6C(int);
extern char lbl_8034DF00[];
extern char lbl_8034DED4[];
extern char lbl_8034DEF4[];
extern int lbl_80560020;
extern char lbl_8055D248;
extern char lbl_8055D250;
extern char lbl_8034DEC4[];
extern unsigned char lbl_8055D255;
extern int NANDRead(void *, void *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_802E8A18(void);
extern int fn_802E8AE8(const char *);
extern int rmemcardRecover(void);
extern void rmemcardCorruptReset(void);
extern void fn_802E8920(int);
/* NAND device availability check: hardwired to 1 (device present) in this build, gating save/menu paths that call it. */
u32 fn_802E8D84(void) { return 1; }

/* Names for the state and helpers of this "rmemcard" NAND module (the debug
 * strings it logs are all prefixed "rmemcard: ").  The project cannot rename
 * the game's symbols yet, so these stand in for them; they are token-identical
 * to the symbols they name.
 *
 * rmemcard_current_path - path of the file the module is working on, NULL when
 *                         idle; the error handlers delete it when it is set.
 * rmemcard_out_of_space - flag set when a NAND operation ran out of free
 *                         blocks; the read below consumes (clears) it.
 * rmemcard_async_buffer - the shared staging buffer fn_802E8CA8 allocates
 *                         RMEMCARD_ASYNC_BUFFER_SIZE bytes of under the name
 *                         "mc_async", and fn_802E8D2C frees; NULL once freed.
 * rmemcard_log_strings  - this module's log strings (offsets into the block).
 * rmemcard_yield        - resumes the thread the NAND wait put to sleep, i.e.
 *                         gives the async machine a turn.
 * rmemcard_wait_async   - runs a pump callback until the async NAND machine
 *                         (fn_802E9010) leaves the busy states, giving up
 *                         after 0xFA0 ticks; 1 = idle, 0 = timed out.
 * rmemcard_test_banner_ok - 1 when the title's banner.bin exists and has the
 *                         size the game expects (0xF0A0 bytes).
 * rmemcard_file_exists  - 1 when NANDOpen can open the path at all.
 * rmemcard_recover_space - asks for len bytes of free NAND space and keeps
 *                         running the module's recovery requests until it has
 *                         them.
 * rmemcard_async_state - the async NAND machine's state word; >= 2 means it is
 *                         still busy, which is what rmemcard_wait_async pumps.
 * rmemcard_timeout_msg - "rmemcard: (%s) timeout while blocking (%d ms)", the
 *                         line rmemcard_wait_async logs when a pump exceeds the
 *                         0xFA0 ms budget.
 */
#define rmemcard_current_path   lbl_80560030
#define rmemcard_out_of_space   lbl_8055D255
#define rmemcard_async_buffer   lbl_80560020
#define rmemcard_log_strings    lbl_8034D9C0
#define rmemcard_yield          fn_802E8838
#define rmemcard_wait_async     fn_802E95E0
#define rmemcard_test_banner_ok fn_802E8A18
#define rmemcard_file_exists    fn_802E8AE8
#define rmemcard_recover_space  fn_802E8920
#define rmemcard_async_state    lbl_80507288
#define rmemcard_timeout_msg    lbl_8034E024
#define RMEMCARD_ASYNC_BUFFER_SIZE 0x55730

#pragma use_lmw_stmw off

/* rmemcardReadFile - read a whole NAND file into the caller's buffer.
 * Returns 1 when all len bytes are in buf, 0 on any failure.
 *
 * The path is published in rmemcard_current_path for the whole read so the
 * module's error handlers know which file was in use, and every exit clears
 * it again (the compiler turns the test on the local's address into the
 * frame-address test it emits before each clear).
 *
 * The game first waits for the async NAND machine to go idle, then insists
 * that the title's banner.bin is intact and that the file itself exists;
 * without both it treats the saved data as broken and hands the case to the
 * recovery handlers instead of reading it.  The read goes through the shared
 * staging buffer when one is allocated, and a short read closes the file and
 * runs the recovery handler for that error (-4 = NAND_RESULT_CORRUPT has its
 * own).  rmemcard_out_of_space is consumed here: only the first failure after
 * the module ran out of blocks asks for free space.
 */
/* Read a whole NAND file into buf: wait for the async machine to idle, require a valid banner and an existing file, read through the shared staging buffer when one is allocated, and run the module's recovery handlers on any failure. Returns 1 on success, 0 otherwise. */ int rmemcardReadFile(const char *path, void *buf, int len) {
    /* NANDFileInfo for the file (0x8C bytes, see revolution/NAND/nand.h);
     * the word in front of it is the one the exits test. */
    struct { int self; char info[0x8C]; } file;
    int banner_ok, was_out_of_space;
    char *logStrings;
    int bytes_read;
    int file_exists, result;

    logStrings = rmemcard_log_strings;
    rmemcard_current_path = (int)path;
    if (((int (*)(void *, void (*)(void)))rmemcard_wait_async)(logStrings + 0x550, rmemcard_yield) == 0) {
        if (&file.self != 0) rmemcard_current_path = 0; /* timed out waiting */
        return 0;
    }
    was_out_of_space = rmemcard_out_of_space;
    rmemcard_out_of_space = 0;
    banner_ok = rmemcard_test_banner_ok();
    file_exists = rmemcard_file_exists(path);
    if (banner_ok == 0 && file_exists == 0) {
        fn_802E30C8(logStrings + 0x560); /* no banner and no file to read */
        if (was_out_of_space != 0) rmemcard_recover_space(len);
        if (&file.self != 0) rmemcard_current_path = 0;
        return 0;
    }
    if (banner_ok == 0 || file_exists == 0) {
        fn_802E30C8(logStrings + 0x594); /* one of the two is missing */
        if (((int (*)(void))rmemcardRecover)() != 0) rmemcard_recover_space(len);
        if (&file.self != 0) rmemcard_current_path = 0;
        return 0;
    }
    result = NANDOpen(path, file.info, 1 /* NAND_ACCESS_READ */);
    if (result != 0) {
        fn_802E30C8(logStrings + 0x5CC, result);
        if (was_out_of_space != 0) rmemcard_recover_space(len);
        if (&file.self != 0) rmemcard_current_path = 0;
        return 0;
    }
    if (rmemcard_async_buffer != 0) {
        /* read into the shared staging buffer and copy out of it */
        if (len > RMEMCARD_ASYNC_BUFFER_SIZE) {
            fn_802E317C(logStrings + 0x5F0, len, RMEMCARD_ASYNC_BUFFER_SIZE);
        }
        bytes_read = NANDRead(file.info, (void *)rmemcard_async_buffer, len);
        if (bytes_read == len) {
            memcpy(buf, (void *)rmemcard_async_buffer, len);
        }
    } else {
        bytes_read = NANDRead(file.info, buf, len);
    }
    if (bytes_read != len) {
        fn_802E30C8(logStrings + 0x624, bytes_read);
        NANDClose(file.info);
        if (bytes_read == -4 /* NAND_RESULT_CORRUPT */) {
            ((void (*)(void))rmemcardCorruptReset)();
        } else if (((int (*)(void))rmemcardRecover)() != 0) {
            rmemcard_recover_space(len);
        }
        if (&file.self != 0) rmemcard_current_path = 0;
        return 0;
    }
    result = NANDClose(file.info);
    if (result != 0) {
        fn_802E30C8(logStrings + 0x644, result);
        if (&file.self != 0) rmemcard_current_path = 0;
        return 0;
    }
    if (&file.self != 0) rmemcard_current_path = 0;
    return 1;
}

#pragma push
#pragma optimization_level 3
void fn_802E9010(void) {
#define rmemcardSave    lbl_80507288
#define bannerPath      lbl_8034E108
#define beginWrite      NandBeginWrite
#define writeIdle       fn_802E91BC
#define writeDone       fn_802E91AC
#define finishSave      fn_802E9118
#define abortSave       fn_802E9160
    char *saveState;

    /* Pump the rmemcard save once per call: step the low-level async NAND
     * write, then advance the outer save state: 2 starts the banner.bin write,
     * 3 starts the main file write once the banner write goes idle, and 4
     * finishes (or aborts on error) once that write goes idle. */
    rmemcardWriteStep((char *)&rmemcardSave + 4);
    saveState = (char *)&rmemcardSave;
    switch (rmemcardSave) {
    case 2:
        beginWrite(saveState + 4, bannerPath, *(int *)(saveState + 0x260), *(int *)(saveState + 0x264));
        rmemcardSave = 3;
        break;
    case 3:
        if (writeIdle((int *)(saveState + 4)) != 0) {
            if (writeDone((int *)(saveState + 4)) == 0) {
                beginWrite(saveState + 4, saveState + 0x270, *(int *)(saveState + 0x268), *(int *)(saveState + 0x26C));
                rmemcardSave = 4;
            } else abortSave(saveState);
        }
        break;
    case 4:
        if (writeIdle((int *)(saveState + 4)) != 0) {
            if (writeDone((int *)(saveState + 4)) == 0) finishSave(saveState);
            else abortSave(saveState);
        }
        break;
    }
#undef abortSave
#undef finishSave
#undef writeDone
#undef writeIdle
#undef beginWrite
#undef bannerPath
#undef rmemcardSave
}
#pragma pop
void fn_802E9118(void *arg0) {
#define mHandle ((char *)arg0 + 0x260)
#define mField264 ((char *)arg0 + 0x264)
#define mField268 ((char *)arg0 + 0x268)
#define mField26C ((char *)arg0 + 0x26C)
#define mState ((int *)arg0)
#define ReleaseHandle fn_8012C4D8
    /* Release the stored handle and clear the associated fields/state. */
    ReleaseHandle(*(int *)mHandle);
    *(int *)mHandle = 0;
    *(int *)mField264 = 0;
    *(int *)mField268 = 0;
    *(int *)mField26C = 0;
    *mState = 0;
#undef mHandle
#undef mField264
#undef mField268
#undef mField26C
#undef mState
#undef ReleaseHandle
}

void fn_802E9160(void *arg0) {
    /* Abort/fail the async NAND save: release its buffer, clear state fields, and mark state 1. */
    fn_8012C4D8(*(int*)((char*)arg0+0x260));
    *(int*)((char*)arg0+0x260)=0;
    *(int*)((char*)arg0+0x264)=0;
    *(int*)((char*)arg0+0x268)=0;
    *(int*)((char*)arg0+0x26c)=0;
    *(int*)arg0=1;
}

/* True when the rmemcard async NAND write state word is IDLE (0), i.e. no write was started. */
int fn_802E91AC(int *state) { return *state == 0; }

#pragma push
#pragma opt_propagation off
/* True once the rmemcard async write machine whose context block is ctx has
 * stopped: its state word (RMEMCARD_WRITE_*) is below CREATE (2), i.e. IDLE (0)
 * or DONE (1).  False while it is still running (states 2..6). */
unsigned int fn_802E91BC(int *ctx) {
    return *ctx < 2;
}
#pragma pop
extern int fn_802E2C20(void);
extern char lbl_8034E024[];
extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern int fn_802E888C(int);
extern char lbl_8034E130[];
extern char lbl_8034E108[];

#define nandLogPrintf   fn_802E30C8
#define sWriteStartFmt  lbl_8034E130

#pragma scheduling invalid_target
/* Begin an async NAND write: store the source buffer and byte count in ctx, copy the path into its filename field, reset the callback context and completion flags, set the step to CREATE, and log the start. */ void NandBeginWrite(void *ctx, const char *path, int buffer, int length) {
    unsigned char c;
    const char *origPath;
    const char *pathPtr;
    int charsLeft;
    char *filenameDst;

    /* Prepare an async NAND write in ctx: record the source buffer address and
     * byte count, copy the NAND path into the context's filename field, point
     * the async callback context back at this block, clear its completion flags
     * and set the state to CREATE (2) before logging the start of the write. */
    origPath = path;
    *(int *)((char *)ctx + 8) = buffer;
    pathPtr = origPath;
    *(int *)((char *)ctx + 4) = length;
    filenameDst = (char *)ctx + 0xC;
    charsLeft = 0x100;
    goto copy;
decrement:
    charsLeft--;
    if (charsLeft > 0) goto copy;
    filenameDst[-1] = 0;
    goto done;
copy:
    c = *pathPtr++;
    *filenameDst++ = c;
    if ((signed char)c != 0) goto decrement;
done:
    *(void **)((char *)ctx + 0x198) = ctx;
    *(int *)((char *)ctx + 0x258) = 0;
    *(char *)((char *)ctx + 0x250) = 0;
    *(int *)((char *)ctx + 0x254) = 0;
    *(int *)ctx = 2;
    nandLogPrintf(sWriteStartFmt, length, origPath);
}
#pragma scheduling on
extern void fn_802E95CC(int, void **);
extern int NANDCreateAsync(const char *, unsigned char, unsigned char, void (*)(int, void **), void *);
extern int NANDOpenAsync(const char *, void *, unsigned char, void (*)(int, void **), void *);
extern int NANDWriteAsync(void *, const void *, unsigned int, void (*)(int, void **), void *);
extern int NANDCloseAsync(void *, void (*)(int, void **), void *);
extern char lbl_8034E114[];
extern char lbl_8034E158[];
extern char lbl_8034E168[];
extern char lbl_8034E184[];
extern char lbl_8034E194[];
extern char lbl_8034E1B4[];
extern char lbl_8034E1C4[];
extern char lbl_8034E1E8[];
extern char lbl_8034E1F8[];
extern char lbl_8034E218[];
#pragma scheduling invalid_target
extern char lbl_8034E114[], lbl_8034E158[], lbl_8034E168[], lbl_8034E184[];
extern char lbl_8034E194[], lbl_8034E1B4[], lbl_8034E1C4[], lbl_8034E1E8[];
extern char lbl_8034E1F8[], lbl_8034E218[], lbl_80560034;

/* Steps of the async NAND file-write machine in rmemcardWriteStep.  The context block
 * it walks (arg0) holds, at these offsets:
 *   0x000 state        - current step (values below)
 *   0x004 length       - byte count to write
 *   0x008 buffer       - source data
 *   0x00C filename     - NAND path (e.g. "banner.bin"), set by NandBeginWrite
 *   0x10C nand_info    - NANDInfo handle of the open file
 *   0x198 cb_ctx       - points back to this block; handed to the async calls
 *   0x250 async_done   - set to 1 by the completion callback fn_802E95CC
 *   0x254 async_result - result the callback left behind
 *   0x258 error        - result reported back to the caller
 */
enum {
    RMEMCARD_WRITE_IDLE     = 0,   /* stopped / failed */
    RMEMCARD_WRITE_DONE     = 1,   /* finished */
    RMEMCARD_WRITE_CREATE   = 2,   /* NANDCreateAsync */
    RMEMCARD_WRITE_OPEN     = 3,   /* NANDOpenAsync   */
    RMEMCARD_WRITE_WRITE    = 4,   /* NANDWriteAsync  */
    RMEMCARD_WRITE_CLOSE    = 5,   /* NANDCloseAsync  */
    RMEMCARD_WRITE_FINISHED = 6    /* report success  */
};

#pragma scheduling invalid_target
/* rmemcardWriteStep - one step of the removable-memory-card ("rmemcard") async
 * NAND file write.  Called repeatedly (from fn_802E9010); each call advances
 * the machine in ctx by one NAND operation.  The async calls all complete
 * through fn_802E95CC, which sets ctx's async_done flag (0x250) and stores the
 * operation's result in async_result (0x254); the machine polls that flag,
 * checks the result, and either moves to the next step or bails out to IDLE
 * recording the error in ctx+0x258.  Steps: create -> open -> write -> close.
 */
/* One step of the removable-memory-card async NAND file-write state machine: advances the create -> open -> write -> close -> finished sequence when the pending async operation completes, recording any error in the context. */ void rmemcardWriteStep(void *ctx) {
    char *ctxBytes = (char *)ctx;
    unsigned char *ctxFlags = (unsigned char *)ctx;
    int step = *(int *)ctxBytes;
    int opStatus = 0;
    int nandResult;

    switch (step) {
    case RMEMCARD_WRITE_CREATE:
        ctxFlags[0x250] = opStatus;
        *(int *)(ctxBytes + 0x254) = opStatus;
        nandResult = NANDCreateAsync(ctxBytes + 0xC, 0x30, 0, fn_802E95CC, ctxBytes + 0x198);
        if (nandResult != 0) {
            fn_802E30C8(lbl_8034E114, lbl_8034E218, nandResult); /* "rmemcard: %s failed (%d)", "NANDCreateAsync" */
            *(int *)ctxBytes = opStatus;
            *(int *)(ctxBytes + 0x258) = nandResult;
        } else *(int *)ctxBytes = RMEMCARD_WRITE_OPEN;
        break;
    case RMEMCARD_WRITE_OPEN:
        if (ctxFlags[0x250] != opStatus) {          /* create has finished */
            opStatus = *(int *)(ctxBytes + 0x254);
            if (opStatus == 0 || opStatus == -6) { /* created OK, or already existed */
                ctxFlags[0x250] = 0;
                *(int *)(ctxBytes + 0x254) = 0;
                nandResult = NANDOpenAsync(ctxBytes + 0xC, ctxBytes + 0x10C, 2, fn_802E95CC, ctxBytes + 0x198);
                if (nandResult != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E1F8, nandResult); /* "NANDOpenAsync" */
                    *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
                    *(int *)(ctxBytes + 0x258) = nandResult;
                } else *(int *)ctxBytes = RMEMCARD_WRITE_WRITE;
            } else {
                if (opStatus == -11) {           /* title not found: needs a create */
                    lbl_80560034 = 1;
                    fn_802E888C(5);
                }
                opStatus = *(int *)(ctxBytes + 0x254);
                fn_802E30C8(lbl_8034E114, lbl_8034E1E8, opStatus); /* "NANDCreateAsync" */
                *(int *)(ctxBytes + 0x258) = opStatus;
                *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
            }
        }
        break;
    case RMEMCARD_WRITE_WRITE:
        if (ctxFlags[0x250] != 0) {               /* open has finished */
            opStatus = *(int *)(ctxBytes + 0x254);
            if (opStatus == 0) {
                ctxFlags[0x250] = 0;
                *(int *)(ctxBytes + 0x254) = 0;
                nandResult = NANDWriteAsync(ctxBytes + 0x10C, (const void *)*(int *)(ctxBytes + 8),
                                        *(unsigned int *)(ctxBytes + 4), fn_802E95CC, ctxBytes + 0x198);
                if (nandResult != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E1C4, nandResult); /* "NANDWriteAsync" */
                    *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
                    *(int *)(ctxBytes + 0x258) = nandResult;
                    NANDClose(ctxBytes + 0x10C);
                } else *(int *)ctxBytes = RMEMCARD_WRITE_CLOSE;
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E1B4, opStatus); /* "NANDOpenAsync" */
                *(int *)(ctxBytes + 0x258) = opStatus;
                *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
            }
        }
        break;
    case RMEMCARD_WRITE_CLOSE:
        if (ctxFlags[0x250] != 0) {               /* write has finished */
            opStatus = *(int *)(ctxBytes + 0x254);
            if (opStatus == *(int *)(ctxBytes + 4)) { /* wrote the whole buffer */
                ctxFlags[0x250] = 0;
                *(int *)(ctxBytes + 0x254) = 0;
                nandResult = NANDCloseAsync(ctxBytes + 0x10C, fn_802E95CC, ctxBytes + 0x198);
                if (nandResult != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E194, nandResult); /* "NANDCloseAsync" */
                    *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
                    *(int *)(ctxBytes + 0x258) = nandResult;
                    NANDClose(ctxBytes + 0x10C);
                } else *(int *)ctxBytes = RMEMCARD_WRITE_FINISHED;
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E184, opStatus); /* "NANDWriteAsync" */
                *(int *)(ctxBytes + 0x258) = opStatus;
                *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
                NANDClose(ctxBytes + 0x10C);
            }
        }
        break;
    case RMEMCARD_WRITE_FINISHED:
        if (ctxFlags[0x250] != 0) {               /* close has finished */
            opStatus = *(int *)(ctxBytes + 0x254);
            if (opStatus == 0) {
                *(int *)ctxBytes = RMEMCARD_WRITE_DONE;
                fn_802E30C8(lbl_8034E168, *(int *)(ctxBytes + 4), ctxBytes + 0xC); /* "rmemcard: Wrote %db to %s" */
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E158, opStatus); /* "NANDCloseAsync" */
                *(int *)(ctxBytes + 0x258) = opStatus;
                *(int *)ctxBytes = RMEMCARD_WRITE_IDLE;
                NANDClose(ctxBytes + 0x10C);
            }
        }
        break;
    }
}
#pragma scheduling on
/* Async NAND-completion callback: stores the operation's result in the write
   context's async_result (+0x254) and raises its async_done flag (+0x250). */
void fn_802E95CC(int result, void **cb_ctx) {
    void *ctx = *cb_ctx;
    *(int *)((char *)ctx + 0x254) = result;
    *(char *)((char *)ctx + 0x250) = 1;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_802E95E0(void *opName, void (*pump)(void), int unused) {
    /* Wait for the NAND/memcard async machine to go idle (rmemcard_async_state < 2),
       pumping once per pass; log a timeout and return 0 past 4000 ms or on clock
       rollback, otherwise return 1. */
    int startMs;
    void *name;
    void (*pump_cb)(void);
    name = opName;
    pump_cb = pump;
    startMs = fn_802E2C20();
    goto check;
loop:
    {
        int nowMs = fn_802E2C20();
        if (nowMs < startMs || nowMs > startMs + 0xFA0) {
            fn_802E30C8(rmemcard_timeout_msg, name, nowMs - startMs);
            return 0;
        }
        pump_cb();
    }
check:
    if (rmemcard_async_state >= 2)
        goto loop;
    return 1;
}
#pragma scheduling on
extern int fn_8012C370(const char *, int, void *, void *, int, int);
extern void fn_8012E81C(const char *);
extern char lbl_8034D9C0[];
extern char lbl_8034E0E8[];
extern char lbl_8034E0F8[];
extern void *memcpy(void *, const void *, unsigned int);
/* fn_802E967C - begin an asynchronous NAND save of `size` bytes from `src` to
 * the file named `path`: wait for the async save machine to go idle, stage the
 * payload in the shared buffer, release the old banner resource and arm the
 * banner + data write, then copy the target name into the save context.
 * Returns 1 once armed, 0 on a timeout or if the save was flagged invalid. */
int fn_802E967C(char *path, void *src, int size) {
#define rmemcard_wait_async   fn_802E95E0
#define rmemcard_yield        fn_802E8838
#define rmemcard_log_strings  lbl_8034D9C0
#define nandLogPrintf         fn_802E30C8
#define gNandSaveInvalid      lbl_80560034
#define rmemcard_async_buffer lbl_80560020
#define rmemcard_async_state  lbl_80507288
#define BANNER_RES_TAG        0x5256424E
#define MAX_NAME_LEN          0x100
    char *ctx;
    int buffer;
    int charsLeft;
    char *nameDst;
    int dummy;

    if (((int (*)(void *, void (*)(void)))rmemcard_wait_async)(rmemcard_log_strings + 0x694, rmemcard_yield) == 0) {
        nandLogPrintf(rmemcard_log_strings + 0x6A8);
        return 0;
    }
    if ((unsigned char)gNandSaveInvalid != 0) {
        nandLogPrintf(rmemcard_log_strings + 0x6D8);
        return 0;
    }
    memcpy((void *)rmemcard_async_buffer, src, size);
    buffer = rmemcard_async_buffer;
    *(int *)&rmemcard_async_state = RMEMCARD_WRITE_CREATE;
    fn_8012E81C(lbl_8034E0F8);
    ctx = (char *)&rmemcard_async_state;
    *(int *)(ctx + 0x260) = fn_8012C370(lbl_8034E0E8, BANNER_RES_TAG, &dummy, ctx + 0x264, 0, 0);
    nameDst = ctx + 0x270;
    charsLeft = MAX_NAME_LEN;
    *(int *)(ctx + 0x268) = buffer;
    *(int *)(ctx + 0x26C) = size;
    while ((*nameDst++ = *path++) != 0) {
        if (--charsLeft <= 0) {
            nameDst[-1] = 0;
            break;
        }
    }
    return 1;
#undef MAX_NAME_LEN
#undef BANNER_RES_TAG
#undef rmemcard_async_state
#undef rmemcard_async_buffer
#undef gNandSaveInvalid
#undef nandLogPrintf
#undef rmemcard_log_strings
#undef rmemcard_yield
#undef rmemcard_wait_async
}

__declspec(section ".data") extern int lbl_80507288;
struct NandSaveState {
    int state;
    char pad[0x258];
    int field;
};
#pragma scheduling invalid_target
void fn_802E97B4(void) {
    struct SaveState { int status; char reserved[0x258]; int result; };
    if (lbl_80560035 == 0) {
        switch (fn_802ECC10()) {
        case 0: break;
        default: return;
        }
        lbl_80560035 = 1;
        if (((struct SaveState *)&lbl_80507288)->status == 1) {
            switch (((struct SaveState *)&lbl_80507288)->result) {
            case 0: break;
            case -9: fn_802E888C(6); break;
            case -11: fn_802E888C(5); break;
            default: fn_802E30C8(lbl_8034E0BC); break;
            }
        }
        ((struct SaveState *)&lbl_80507288)->result = 0;
        lbl_80560035 = 0;
    }
}
/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023E7A8), but this build discards it. */
void fn_802E986C(void) {}

/* No-op callback-registration hook: startup passes it a menu-handler function
 * pointer (fn_8023E5B4), but this build ignores the registration. */
void fn_802E9870(void) {}

/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023F0E8), but this build discards it. */
void fn_802E9874(void) {}

/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023F4B8), but this build discards it. */
void fn_802E9878(void) {}

/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023F694), but this build discards it. */
void fn_802E987C(void) {}

/* No-op callback-registration hook: startup passes it a menu-handler function
 * pointer (fn_8023F2C4), but this build ignores the registration. */
void fn_802E9880(void) {}

/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023EEF8), but this build discards it. */
void fn_802E9884(void) {}

/* No-op NAND-save hook: game-menu init passes this a callback pointer (fn_8023ED30), but this build discards it. */
void fn_802E9888(void) {}

