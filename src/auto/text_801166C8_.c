// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/ARC/arc.h>

void* ARCGetStartAddrInMem(ARCFileInfo* info) {
    return (void*)((s32)info->handle->archiveStartAddr + info->startOffset);
}

s32 fn_80116A30(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

s32 fn_80116A38(void) {
    return 1;
}

BOOL ARCChangeDir(ARCHandle* handle, const char* path) {
    s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    
    if (entrynum < 0 || !(handle->entryNum + entrynum * 0xC & 0xFF000000)) {
        return FALSE;
    }
    
    handle->currDir = entrynum;
    return TRUE;
}

BOOL ARCOpenDir(ARCHandle* handle, const char* path, ARCDir* dir) {
    s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    
    if (entrynum < 0 || !(handle->entryNum + entrynum * 0xC & 0xFF000000)) {
        return FALSE;
    }
    
    dir->handle = handle;
    dir->entryNum = entrynum;
    dir->location = entrynum + 1;
    dir->next = *(u32*)((u8*)handle->FSTStart + entrynum * 0xC + 8);
    return TRUE;
}

u32 fn_80116BCC(void) {
    return 1;
}

void fn_80119214(void) {
    AXFXSetHooks_8011FFB8();
}

void fn_8011BC48(void) {
    fn_80120084();
}

void fn_80127464(void) {
    fn_80127440();
}

