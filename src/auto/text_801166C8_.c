// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/ARC/arc.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>

extern void* fn_802ECC74(void*);
extern void fn_80127F70(void*);
extern void fn_80127F94(void*);
extern void fn_80127440(void);
extern void fn_80127398(s32);
extern void fn_802E300C(s32);
extern void* lbl_8041D728[];
extern u8 lbl_802F6A40[];

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
    u32 entryAddr = (u32)handle->FSTStart + location * 0xC;
    u32 entryData = *(u32*)entryAddr;
    u8 highByte = entryData >> 24;
    
    if (location >= dir->entryNum || dir->next <= location) {
        return FALSE;
    }
    
    entry->handle = handle;
    entry->entryNum = location;
    entry->isDir = (s8)highByte < 0;
    
    return TRUE;
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

extern s64 OSGetTime(void);
extern s32 lbl_8055DEC0;
extern u32 lbl_8055DEC4;
s32 fn_80116D30(void) {
    s64 time = OSGetTime();
    u32 time_high;
    s32 time_low;
    s32 saved_low;
    u32 saved_high;
    s64 delta;
    
    time_high = (u32)(time >> 32);
    time_low = (s32)time;
    
    saved_low = lbl_8055DEC0;
    saved_high = lbl_8055DEC4;
    
    if (saved_low == 0 && saved_high == 0) {
        lbl_8055DEC4 = time_high;
        lbl_8055DEC0 = time_low;
        saved_high = time_high;
        saved_low = time_low;
    }
    
    delta = time - ((s32)saved_high << 32 | saved_low);
    
    return (s32)(delta * 70811LL / 2317483787LL);
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

extern void *lbl_8055DEF0;
void* fn_8011FF24(void) {
    return lbl_8055DEF0;
}

void fn_80125098(void *arg0) {
    f32 r3, r1, r2, r0;
    r3 = ((f32 *)arg0)[0];
    r1 = ((f32 *)arg0)[2];
    r2 = ((f32 *)arg0)[1];
    r0 = ((f32 *)arg0)[3];
    ((f32 *)arg0)[2] = r3 - r1;
    ((f32 *)arg0)[0] = r3 + r1;
    ((f32 *)arg0)[1] = r2 - r0;
    ((f32 *)arg0)[3] = r2 + r0;
}

extern void fn_80125664(u8 *, s32);
void fn_80125CA0(void *arg0, void *arg1, void *arg2, s32 arg3) {
    fn_80125664((u8 *)&lbl_802F6A40 + (arg3 << 8), arg3);
}

extern char lbl_8055DF08;
char fn_8012742C(void) {
    return lbl_8055DF08;
}

void fn_80127434(void) {
    lbl_8055DF08 = 0;
}

void fn_80127464(void) {
    fn_80127440();
}

void fn_80127468(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_80127F70(fn_802ECC74(alarm));
}

void fn_8012748C(s32 arg0) {
    fn_80127398(arg0);
    fn_802E300C(arg0);
}

