/*
 * NANDCore recovered source.
 *
 * Function semantics are largely reconstructed, but full promotion is deferred:
 * remaining issues are pooled data/source-shape and linker placement rather than
 * missing behavior. Keep changes source-focused unless a dedicated promotion pass
 * maps all data providers and checks the final DOL hash.
 */

#include <revolution/ESP.h>
#include <revolution/NAND.h>
#include <revolution/OS.h>

#include <internal/printf.h>
#include <string.h>
#include <wchar.h>

#define NAND_BANNER_MAGIC 'WIBN'

typedef enum {
    NAND_LIB_UNINITIALIZED,
    NAND_LIB_INITIALIZING,
    NAND_LIB_INITIALIZED
} NANDLibState;

static void nandGetTypeCallback(s32 result, void* arg);
static s32 nandOnShutdown(const char* path, NANDCommandBlock* block, BOOL async, BOOL priv);
static void nandReadDirCallback(s32 result, void* arg);
static s32 _ES_InitLib(s32* fd);
static s32 _ES_GetDataDir(s32* fd, u64 tid, char* dirOut) DECOMP_DONT_INLINE;
static s32 _ES_GetTitleId(s32* fd, u64* tidOut);
static s32 _ES_CloseLib(s32* fd);

const char* __NANDVersion =
    "<< RVL_SDK - NAND \trelease build: Sep 22 2006 02:01:36 (0x4200_60422) >>";

static NANDLibState s_libState = NAND_LIB_UNINITIALIZED;
static char s_currentDir[64] ALIGN(32) = "/";

static char s_homeDir[64] ALIGN(32);

void nandRemoveTailToken(char* newp, const char* oldp) {
    int i;

    if (oldp[0] == '/' && oldp[1] == '\0') {
        newp[0] = '/';
        newp[1] = '\0';
    } else {
        for (i = strlen(oldp) - 1; i >= 0; i--) {
            if (oldp[i] == '/') {
                if (i != 0) {
                    strncpy(newp, oldp, i);
                    newp[i] = '\0';
                    break;
                } else {
                    newp[0] = '/';
                    newp[1] = '\0';
                    break;
                }
            }
        }
    }
}

void nandGetHeadToken(char* head, char* rest, const char* path) {
    int i;

    for (i = 0; i <= strlen(path); i++) {
        if (path[i] == '/') {
            strncpy(head, path, i);
            head[i] = '\0';

            if (path[i + 1] == '\0') {
                *rest = '\0';
            } else {
                strcpy(rest, path + i + 1);
            }
            break;
        } else if (path[i] == '\0') {
            strncpy(head, path, i);
            head[i] = '\0';
            *rest = '\0';
            break;
        }
    }
}

void nandConvertPath(char* abs, const char* dir, const char* rel) {
    char head[128];
    char rest[128];
    char notail[128];
    char newdir[128];

    if (strlen(rel) == 0) {
        strcpy(abs, dir);
        return;
    }

    nandGetHeadToken(head, rest, rel);

    if (strcmp(head, ".") == 0) {
        nandConvertPath(abs, dir, rest);
    } else if (strcmp(head, "..") == 0) {
        nandRemoveTailToken(notail, dir);
        nandConvertPath(abs, notail, rest);
    } else if (head[0] != '\0') {
        if (strcmp(dir, "/") == 0) {
            sprintf(newdir, "/%s", head);
        } else {
            sprintf(newdir, "%s/%s", dir, head);
        }
        nandConvertPath(abs, newdir, rest);
    } else {
        strcpy(abs, dir);
    }
}

static BOOL nandIsRelativePath(const char* path) {
    return *path == '/' ? FALSE : TRUE;
}

BOOL nandIsPrivatePath(const char* path) {
    size_t len = sizeof("/shared2") - 1;
    return strncmp(path, "/shared2", len) == 0;
}

BOOL nandIsUnderPrivatePath(const char* path) {
    size_t len = sizeof("/shared2/") - 1;

    if (strncmp(path, "/shared2/", len) == 0 && path[len] != '\0') {
        return TRUE;
    }

    return FALSE;
}

BOOL nandIsInitialized(void) {
    return s_libState == NAND_LIB_INITIALIZED ? TRUE : FALSE;
}

// Stubbed for release
void nandReportErrorCode(s32 result) {
#pragma unused(result)
}

s32 nandConvertErrorCode(s32 result) {
    int i;

    // clang-format off
    const s32 errorMap[] = {IPC_RESULT_OK,                    NAND_RESULT_OK,
                            IPC_RESULT_ACCESS,                NAND_RESULT_ACCESS,
                            IPC_RESULT_CORRUPT,               NAND_RESULT_CORRUPT,
                            IPC_RESULT_ECC_CRIT,              NAND_RESULT_ECC_CRIT,
                            IPC_RESULT_EXISTS,                NAND_RESULT_EXISTS,
                            -116,                             NAND_RESULT_AUTHENTICATION,
                            IPC_RESULT_INVALID,               NAND_RESULT_INVALID,
                            IPC_RESULT_MAXBLOCKS,             NAND_RESULT_MAXBLOCKS,
                            IPC_RESULT_MAXFD,                 NAND_RESULT_MAXFD,
                            IPC_RESULT_MAXFILES,              NAND_RESULT_MAXFILES,
                            IPC_RESULT_NOEXISTS,              NAND_RESULT_NOEXISTS,
                            IPC_RESULT_NOTEMPTY,              NAND_RESULT_NOTEMPTY,
                            -104,                             NAND_RESULT_UNKNOWN,
                            IPC_RESULT_OPENFD,                NAND_RESULT_OPENFD,
                            -117,                             NAND_RESULT_UNKNOWN,
                            IPC_RESULT_BUSY,                  NAND_RESULT_BUSY,
                            IPC_RESULT_ACCESS_INTERNAL,       NAND_RESULT_ACCESS,
                            IPC_RESULT_EXISTS_INTERNAL,       NAND_RESULT_EXISTS,
                            -3,                               NAND_RESULT_UNKNOWN,
                            IPC_RESULT_INVALID_INTERNAL,      NAND_RESULT_INVALID,
                            -5,                               NAND_RESULT_UNKNOWN,
                            IPC_RESULT_NOEXISTS_INTERNAL,     NAND_RESULT_NOEXISTS,
                            -7,                               NAND_RESULT_UNKNOWN,
                            IPC_RESULT_BUSY_INTERNAL,         NAND_RESULT_BUSY,
                            -9,                               NAND_RESULT_UNKNOWN,
                            -10,                              NAND_RESULT_UNKNOWN,
                            -11,                              NAND_RESULT_UNKNOWN,
                            IPC_RESULT_ECC_CRIT_INTERNAL,     NAND_RESULT_ECC_CRIT,
                            -13,                              NAND_RESULT_UNKNOWN,
                            -14,                              NAND_RESULT_UNKNOWN,
                            -15,                              NAND_RESULT_UNKNOWN,
                            -16,                              NAND_RESULT_UNKNOWN,
                            -17,                              NAND_RESULT_UNKNOWN,
                            -18,                              NAND_RESULT_UNKNOWN,
                            -19,                              NAND_RESULT_UNKNOWN,
                            -20,                              NAND_RESULT_UNKNOWN,
                            -21,                              NAND_RESULT_UNKNOWN,
                            IPC_RESULT_ALLOC_FAILED,          NAND_RESULT_ALLOC_FAILED,
                            -23,                              NAND_RESULT_UNKNOWN};
    // clang-format on

    i = 0;

    if (result >= 0) {
        return result;
    }

    for (; i < ARRAY_SIZE(errorMap); i += 2) {
        if (result == errorMap[i]) {
            nandReportErrorCode(result);
            return errorMap[i + 1];
        }
    }

    OSReport("CAUTION!  Unexpected error code [%d] was found.\n", result);
    nandReportErrorCode(result);
    return NAND_RESULT_UNKNOWN;
}

void nandGenerateAbsPath(char* abs, const char* rel) {
    s32 len;

    if (strlen(rel) == 0) {
        strcpy(abs, "");
    } else if (nandIsRelativePath(rel)) {
        nandConvertPath(abs, s_currentDir, rel);
    } else {
        strcpy(abs, rel);
        len = strlen(abs);
        if (len != 0 && abs[len - 1] == '/' && len - 1 != 0) {
            abs[len - 1] = '\0';
        }
    }
}

static void nandGetParentDirectory(char* dir, const char* path) {
    int i;

    for (i = strlen(path); i >= 0; i--) {
        if (path[i] == '/') {
            break;
        }
    }

    if (i == 0) {
        strcpy(dir, "/");
    } else {
        strncpy(dir, path, i);
        dir[i] = '\0';
    }
}

/**
 * Bring up the NAND library: open the ISFS (the low-level NAND file system) and
 * ask the ES module for this title's own directory on NAND, which becomes the
 * library's current directory - the base every relative NAND path is resolved
 * against (nandGenerateAbsPath()).
 *
 * The library state is checked and set under interrupt disable, so a second
 * caller while the first is still working gets NAND_RESULT_BUSY and an already
 * initialized library simply returns NAND_RESULT_OK. Only failing to open ISFS
 * is reported back (converted by nandConvertErrorCode()); if the ES queries
 * fail the library still comes up, reporting the problem and leaving "/" - the
 * built-in default - as the current directory.
 */
s32 NANDInit(void) {
    s32 result;
    u64 titleId;
    s32 esFd;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (s_libState == NAND_LIB_INITIALIZING) {
        OSRestoreInterrupts(enabled);
        return NAND_RESULT_BUSY;
    } else if (s_libState == NAND_LIB_INITIALIZED) {
        OSRestoreInterrupts(enabled);
        return NAND_RESULT_OK;
    }

    // Claim the initialization before letting interrupts back on.
    s_libState = NAND_LIB_INITIALIZING;
    OSRestoreInterrupts(enabled);

    result = ISFS_OpenLib();
    if (result == IPC_RESULT_OK) {

        // This title's data directory on NAND, e.g. "/title/00000001/xxxxxxxx/data".
        result = _ES_InitLib(&esFd);

        if (result == IPC_RESULT_OK) {
            result = _ES_GetTitleId(&esFd, &titleId);
        }

        if (result == IPC_RESULT_OK) {
            result = _ES_GetDataDir(&esFd, titleId, s_homeDir);
        }

        if (result == IPC_RESULT_OK) {
            strcpy(s_currentDir, s_homeDir);
        }

        _ES_CloseLib(&esFd);

        if (result != IPC_RESULT_OK) {
            OSReport("Failed to set home directory.\n");
        }

        enabled = OSDisableInterrupts();
        s_libState = NAND_LIB_INITIALIZED;
        OSRestoreInterrupts(enabled);
        OSRegisterVersion(__NANDVersion);
        return NAND_RESULT_OK;
    } else {
        enabled = OSDisableInterrupts();
        s_libState = NAND_LIB_UNINITIALIZED;
        OSRestoreInterrupts(enabled);
        return nandConvertErrorCode(result);
    }
}

/**
 * Make @p path the library's current directory. This is the RVL SDK's
 * nandChangeDir() helper; the name this project carries for it is a leftover
 * from an early pass, as is the name of its caller below.
 *
 * ISFS_ReadDir() is what does the work: it succeeds on a directory and fails
 * on anything else, so once it returns IPC_RESULT_OK the absolute path is
 * stored as the current directory - nandReadDirCallback() does the same for
 * the asynchronous request. Interrupts keep the two writers of s_currentDir
 * (and of NANDGetCurrentDir()) from interleaving.
 *
 * @param async  TRUE: build the request in @p block and hand it to
 *               ISFS_ReadDirAsync(); FALSE: do it here with local storage.
 * @param priv   TRUE skips the check that rejects the private "/shared2"
 *               tree, for the NANDPrivate* entry points.
 * @return an IPC_RESULT_* code that the caller passes to nandConvertErrorCode().
 */
static s32 nandOnShutdown(const char* path, NANDCommandBlock* block, BOOL async,
                          BOOL priv) {
    if (async) {
        nandGenerateAbsPath(block->path, path);

        if (!priv) {
            BOOL isPriv;
            if (strncmp(block->path, "/shared2", sizeof("/shared2") - 1) == 0) {
                isPriv = TRUE;
            } else {
                isPriv = FALSE;
            }
            if (isPriv) {
                return IPC_RESULT_ACCESS;
            }
        }

        return ISFS_ReadDirAsync(block->path, NULL, &block->dirFileCount,
                                 nandReadDirCallback, block);
    } else {
        char absPath[FS_MAX_PATH];
        u32 numFiles = 0;
        s32 result;

        MEMCLR(&absPath);
        nandGenerateAbsPath(absPath, path);

        if (!priv) {
            BOOL isPriv;
            if (strncmp(absPath, "/shared2", sizeof("/shared2") - 1) == 0) {
                isPriv = TRUE;
            } else {
                isPriv = FALSE;
            }
            if (isPriv) {
                return IPC_RESULT_ACCESS;
            }
        }

        result = ISFS_ReadDir(absPath, NULL, &numFiles);
        if (result == IPC_RESULT_OK) {
            BOOL enabled = OSDisableInterrupts();
            strcpy(s_currentDir, absPath);
            OSRestoreInterrupts(enabled);
        }
        return result;
    }
}

/* This is the SDK's NANDChangeDir(const char* path): it hands its one
 * argument to the change-dir helper above and converts the IPC code back -
 * the NANDGetType name, and the unused type parameter, are leftovers. */
s32 NANDGetType(const char* path, u8* type) {
    if (!nandIsInitialized()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    return nandConvertErrorCode(nandOnShutdown(path, NULL, FALSE, FALSE));
}

static void nandReadDirCallback(s32 result, void* arg) {
    NANDCommandBlock* block = (NANDCommandBlock*)arg;

    if (result == IPC_RESULT_OK) {
        BOOL enabled = OSDisableInterrupts();
        strcpy(s_currentDir, block->path);
        OSRestoreInterrupts(enabled);
    }

    block->callback(nandConvertErrorCode(result), block);
}

s32 NANDGetCurrentDir(char* out) {
    BOOL enabled;

    if (!nandIsInitialized()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    enabled = OSDisableInterrupts();
    strcpy(out, s_currentDir);
    OSRestoreInterrupts(enabled);
    return NAND_RESULT_OK;
}

static s32 NANDGetHomeDir(char* out) {
    if (!nandIsInitialized()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    strcpy(out, s_homeDir);
    return NAND_RESULT_OK;
}

void nandCallback(s32 result, void* arg) {
    NANDCommandBlock* block = (NANDCommandBlock*)arg;
    block->callback(nandConvertErrorCode(result), block);
}

/**
 * Work out whether @p path names a file or a directory and store a
 * NAND_FILE_TYPE_* in @p type (or, asynchronously, in the caller's block for
 * nandGetTypeCallback() to store).
 *
 * The trick is ISFS_ReadDir(): it succeeds on directories and returns
 * IPC_RESULT_INVALID on anything else, so a readable directory (or one we are
 * denied access to) is a directory and an invalid path is a file. Any other
 * error is passed straight back.
 *
 * @param async  TRUE: build the request in @p block and hand it to
 *               ISFS_ReadDirAsync(); FALSE: do it here with local storage.
 * @param priv   TRUE skips the check that rejects paths under another title's
 *               private "/shared2/" tree, for the NANDPrivate* entry points.
 * @return an IPC_RESULT_* code that callers pass to nandConvertErrorCode().
 */
static s32 nandGetType(const char* path, u8* type, NANDCommandBlock* block,
                       BOOL async, BOOL priv) {
    char absPath[FS_MAX_PATH];
    u32 numFiles;
    s32 result;

    if (strlen(path) == 0) {
        return IPC_RESULT_INVALID;
    }

    if (async) {
        nandGenerateAbsPath(block->path, path);

        if (!priv && nandIsUnderPrivatePath(block->path)) {
            return IPC_RESULT_ACCESS;
        }

        block->type = type;
        return ISFS_ReadDirAsync(block->path, NULL, &block->dirFileCount,
                                 nandGetTypeCallback, block);
    } else {
        MEMCLR(&absPath);
        nandGenerateAbsPath(absPath, path);

        if (!priv && nandIsUnderPrivatePath(absPath)) {
            return IPC_RESULT_ACCESS;
        }

        numFiles = 0;
        result = ISFS_ReadDir(absPath, NULL, &numFiles);
        if (result == IPC_RESULT_OK || result == IPC_RESULT_ACCESS) {
            *type = NAND_FILE_TYPE_DIR;
            return IPC_RESULT_OK;
        } else if (result == IPC_RESULT_INVALID) {
            *type = NAND_FILE_TYPE_FILE;
            return IPC_RESULT_OK;
        }

        return result;
    }
}

s32 NANDPrivateGetTypeAsync(const char* path, u8* type,
                            NANDAsyncCallback callback,
                            NANDCommandBlock* block) {
    if (!nandIsInitialized()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    block->callback = callback;
    return nandConvertErrorCode(nandGetType(path, type, block, TRUE, TRUE));
}

static void nandGetTypeCallback(s32 result, void* arg) {
    NANDCommandBlock* block = (NANDCommandBlock*)arg;

    if (result == IPC_RESULT_OK || result == IPC_RESULT_ACCESS) {
        *block->type = NAND_FILE_TYPE_DIR;
        result = IPC_RESULT_OK;
    } else if (result == IPC_RESULT_INVALID) {
        *block->type = NAND_FILE_TYPE_FILE;
        result = IPC_RESULT_OK;
    }

    block->callback(nandConvertErrorCode(result), block);
}

const char* nandGetHomeDir(void) {
    return s_homeDir;
}

/**
 * These were actually re(?)implemented in NANDCore/OSExec according to BBA
 */

static s32 _ES_InitLib(s32* fd) {
    s32 result;

    *fd = -1;
    result = IPC_RESULT_OK;

    *fd = IOS_Open("/dev/es", IPC_OPEN_NONE);
    if (*fd < 0) {
        result = *fd;
    }

    return result;
}

static s32 _ES_GetDataDir(s32* fd, u64 tid, char* dirOut) {
    // TODO: Hacky solution
    u8 tidWork[256] ALIGN(32);
    u8 vectorWork[32] ALIGN(32);
    IPCIOVector* pVectors = (IPCIOVector*)vectorWork;
    u64* pTid = (u64*)tidWork;

    // Cast is necessary
    if (*fd < 0 || dirOut == ((void*)NULL)) {
        return -0x3F9;
    }

    if ((u32)dirOut % 32 != 0) {
        return -0x3F9;
    }

    *pTid = tid;

    pVectors[0].base = pTid;
    pVectors[0].length = sizeof(u64);
    pVectors[1].base = dirOut;
    pVectors[1].length = 30;

    return IOS_Ioctlv(*fd, ES_IOCTLV_GET_DATA_DIR, 1, 1, pVectors);
}

static s32 _ES_GetTitleId(s32* fd, u64* tidOut) {
    s32 result;
    u64* pTid;
    // TODO: Hacky solution
    u8 tidWork[256] ALIGN(32);
    u8 vectorWork[32] ALIGN(32);
    IPCIOVector* pVectors = (IPCIOVector*)vectorWork;

    // Cast is necessary
    if (*fd < 0 || tidOut == ((void*)NULL)) {
        return -0x3F9;
    }

    pTid = (u64*)tidWork;
    pVectors[0].base = pTid;
    pVectors[0].length = sizeof(u64);

    result = IOS_Ioctlv(*fd, ES_IOCTLV_GET_TITLE_ID, 0, 1, pVectors);
    if (result == IPC_RESULT_OK) {
        *tidOut = *pTid;
    }

    return result;
}

static s32 _ES_CloseLib(s32* fd) {
    s32 result = IPC_RESULT_OK;

    if (*fd >= 0 && (result = IOS_Close(*fd)) == IPC_RESULT_OK) {
        *fd = -1;
    }

    return result;
}


void NANDInitBanner(s32 result, void* arg) {
    NANDCommandBlock* block = (NANDCommandBlock*)arg;

    if (result == IPC_RESULT_OK) {
        BOOL enabled = OSDisableInterrupts();
        strcpy(s_currentDir, block->path);
        OSRestoreInterrupts(enabled);
    }

    block->callback(nandConvertErrorCode(result), block);
}
