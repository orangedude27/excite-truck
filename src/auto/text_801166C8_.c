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
    u32 entryAddr = (u32)handle->FSTStart + entrynum * 0xC;
    
    if (entrynum < 0 || !(*(u32*)entryAddr & 0xFF000000)) {
        return FALSE;
    }
    
    handle->currDir = entrynum;
    return TRUE;
}

BOOL ARCOpenDir(ARCHandle* handle, const char* path, ARCDir* dir) {
    s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    void* fst = handle->FSTStart;
    
    if (entrynum < 0 || !(*(u32*)((u8*)fst + entrynum * 0xC) & 0xFF000000)) {
        return FALSE;
    }
    
    dir->handle = handle;
    dir->entryNum = entrynum;
    dir->location = entrynum + 1;
    dir->next = *(u32*)((u8*)fst + entrynum * 0xC + 8);
    return TRUE;
}

BOOL ARCReadDir(ARCDir* dir, ARCDirEntry* entry) {
    ARCHandle* handle = dir->handle;
    u32 location = dir->location;
    u32 entryNum = dir->entryNum;
    u32 next = dir->next;
    u32 entryAddr;
    u32 entryData;
    u8 highByte;
    s8 signedByte;
    u32 nameOffset;
    char* name;
    
    while (1) {
        if (location >= entryNum || next <= location) {
            return FALSE;
        }
        
        entry->handle = handle;
        entry->entryNum = location;
        
        entryAddr = (u32)handle->FSTStart + location * 0xC;
        entryData = *(u32*)entryAddr;
        
        highByte = entryData >> 24;
        signedByte = (s8)highByte;
        entry->isDir = (signedByte < 0);
        
        nameOffset = entryData >> 8;
        name = handle->FSTStringStart + nameOffset;
        
        if (!(name[0] == '.' && name[1] == '\0')) {
            dir->location = location + 1;
            return TRUE;
        }
        
        location++;
        entryNum = dir->entryNum;
        next = dir->next;
    }
}

u32 fn_80116BCC(void) {
    return 1;
}

void fn_80116CC4(s32* arg0, s16 arg1, u32 arg2) {
    s32* r3;
    u32 r6;
    s32 r7;
    s32 val;
    s32* p;
    u32 count;
    
    r3 = arg0;
    r6 = arg2 >> 1;
    r7 = arg1;
    
    val = (s32)(arg1 & 0xFFFF);
    val = val | (val << 16);
    
    if (r6 != 0) {
        count = r6 >> 3;
        if (count != 0) {
            p = r3;
            do {
                p[0] = val;
                p[1] = val;
                p[2] = val;
                p[3] = val;
                p[4] = val;
                p[5] = val;
                p[6] = val;
                p[7] = val;
                p += 8;
                count--;
            } while (count != 0);
            r6 &= 7;
        }
        if (r6 != 0) {
            do {
                *r3 = val;
                r3++;
                r6--;
            } while (r6 != 0);
        }
    }
    
    if (arg2 & 1) {
        *(s16*)r3 = arg1;
    }
}

void fn_80116D30(void) {
    // This is a complex time conversion function
    // Need to check what OSGetTime returns and the globals
}

extern void* fn_8011FF24(void);
extern void fn_8011FF2C(s32);
void fn_80116DDC(void* arg0, s32 arg1) {
    void* result = fn_8011FF24();
    s32* ptr = (s32*)arg0;
    s32 current = ptr[0x290 / 4];
    s32 new_val = arg1 + (s32)result + current;
    ptr[0x290 / 4] = new_val;
    fn_8011FF2C(arg1);
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

