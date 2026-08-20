#include <revolution/NAND.h>

// The directory-name string literals and this pointer pool were merged into
// another data translation unit in the original build (lbl_8031AF70 =
// .data:0x8031AF70); NANDCheck.c itself only emits .text.
extern const char* lbl_8031AF70[];

static s32 nandCalcUsage(s32* blockCountOut, s32* fileCountOut,
                         const char** dirList) {
    s32 result = -117;

    *blockCountOut = 0;
    *fileCountOut = 0;

    for (; *dirList != NULL; dirList++) {
        s32 blockCount = 0;
        s32 fileCount = 0;

        result = ISFS_GetUsage(*dirList, &blockCount, &fileCount);
        if (result == IPC_RESULT_OK) {
            *blockCountOut += blockCount;
            *fileCountOut += fileCount;
        } else if (result == IPC_RESULT_NOEXISTS) {
            result = IPC_RESULT_OK;
        } else {
            break;
        }
    }

    return result;
}

static s32 nandCalcUserUsage(s32* blockCountOut, s32* fileCountOut) {
    return nandCalcUsage(blockCountOut, fileCountOut, lbl_8031AF70);
}

static u32 nandCheck(u32 neededBlocks, u32 neededFiles, u32 homeDirBlocks,
                     u32 homeDirFiles, u32 userBlocks, u32 userFiles) {
    u32 answer = 0;

    if (homeDirBlocks + neededBlocks > 0x400) {
        answer |= NAND_CHECK_TOO_MANY_APP_BLOCKS;
    }

    if (homeDirFiles + neededFiles > 0x21) {
        answer |= NAND_CHECK_TOO_MANY_APP_FILES;
    }

    if (userBlocks + neededBlocks > 0x4400) {
        answer |= NAND_CHECK_TOO_MANY_USER_BLOCKS;
    }

    if (userFiles + neededFiles > 0xFA0) {
        answer |= NAND_CHECK_TOO_MANY_USER_FILES;
    }

    return answer;
}

// In the original SDK build, nandCalcUserUsage() and nandCheck() were inlined
// by the compiler into NANDCheck(); neither exists as an out-of-line function.

s32 NANDCheck(u32 neededBlocks, u32 neededFiles, u32* answer) {
    s32 result;

    s32 homeDirBlocks = -1;
    s32 homeDirFiles = -1;
    s32 userBlocks = -1;
    s32 userFiles = -1;

    if (!nandIsInitialized()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    result = ISFS_GetUsage(nandGetHomeDir(), &homeDirBlocks, &homeDirFiles);
    if (result != IPC_RESULT_OK) {
        return nandConvertErrorCode(result);
    }

    result = nandCalcUserUsage(&userBlocks, &userFiles);
    if (result != IPC_RESULT_OK) {
        return nandConvertErrorCode(result);
    }

    *answer = nandCheck(neededBlocks, neededFiles, homeDirBlocks, homeDirFiles,
                        userBlocks, userFiles);

    return NAND_RESULT_OK;
}
