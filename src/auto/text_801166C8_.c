// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/ARC/arc.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>

extern void* fn_802ECC74(void*);
extern void fn_80127F70(void*);
extern void fn_80127F94(void*);
void fn_80127440(void);
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

extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_8011943C(void *, s32);
extern s32 fn_801199A4(void *, s32);

s32 fn_80119994(void) { return 0; }

s32 fn_8011999C(void) { return 0; }

void fn_80119AB0(void *arg0, s32 arg1) {
    s32 value = arg1;
    f32 temp;
    if (value < 0) value = 0;
    if (value > 0x7fff) value = 0x7fff;
    temp = (f32) fn_8002EFBC((f32)value, lbl_80561198);
    *(s32 *)((u8 *)arg0 + 0xa4) = (s32)(lbl_805611A0 * temp);
    fn_80119288(arg0, temp);
}

extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_8011943C(void *, s32);
extern s32 fn_801199A4(void *, s32);
s32 fn_80119C0C(void *arg0, s32 arg1) {
    if (arg1 != 0 && *(s32 *)((u8 *)arg0 + 0x64) == 0) {
        *(s32 *)((u8 *)arg0 + 0xb0) = 0;
        *(s32 *)((u8 *)arg0 + 0x64) = 1;
        *(s32 *)((u8 *)arg0 + 0xb8) = 0;
        *(s32 *)((u8 *)arg0 + 0xbc) = *(s32 *)((u8 *)arg0 + 0xc0);
    }
    if (arg1 == 0 && *(s32 *)((u8 *)arg0 + 0x64) != 0) {
        fn_8011943C((u8 *)arg0 + 0x7c, 0);
        fn_801199A4((u8 *)arg0 + 0x7c, 1);
        fn_80119300((u8 *)arg0 + 0x7c, 0, *(s32 *)((u8 *)arg0 + 0x94));
        *(s32 *)((u8 *)arg0 + 0x64) = 0;
    }
    return *(s32 *)((u8 *)arg0 + 0x64);
}

void fn_8011BC48(void) {
    fn_80120084();
}

extern void *lbl_8055DEF0;
void* fn_8011FF24(void) {
    return lbl_8055DEF0;
}

void fn_80121BF4(void *arg0) {
    f32 temp_8, temp_C, temp_10, temp_14, temp_18, temp_1C;
    f32 temp_20, temp_24, temp_28, temp_2C, temp_30, temp_34;
    f32 temp_38, temp_3C;
    
    temp_8 = *(f32 *)((u8 *)arg0 + 8);
    temp_C = *(f32 *)((u8 *)arg0 + 0xc);
    temp_10 = *(f32 *)((u8 *)arg0 + 0x10);
    temp_14 = *(f32 *)((u8 *)arg0 + 0x14);
    temp_18 = *(f32 *)((u8 *)arg0 + 0x18);
    temp_1C = *(f32 *)((u8 *)arg0 + 0x1c);
    temp_20 = *(f32 *)((u8 *)arg0 + 0x20);
    temp_24 = *(f32 *)((u8 *)arg0 + 0x24);
    temp_28 = *(f32 *)((u8 *)arg0 + 0x28);
    temp_2C = *(f32 *)((u8 *)arg0 + 0x2c);
    temp_30 = *(f32 *)((u8 *)arg0 + 0x30);
    temp_34 = *(f32 *)((u8 *)arg0 + 0x34);
    temp_38 = *(f32 *)((u8 *)arg0 + 0x38);
    temp_3C = *(f32 *)((u8 *)arg0 + 0x3c);
    
    *(f32 *)((u8 *)arg0 + 8) = temp_38;
    *(f32 *)((u8 *)arg0 + 0xc) = temp_3C;
    *(f32 *)((u8 *)arg0 + 0x10) = temp_18;
    *(f32 *)((u8 *)arg0 + 0x14) = temp_1C;
    *(f32 *)((u8 *)arg0 + 0x18) = temp_28;
    *(f32 *)((u8 *)arg0 + 0x1c) = temp_2C;
    *(f32 *)((u8 *)arg0 + 0x20) = temp_8;
    *(f32 *)((u8 *)arg0 + 0x24) = temp_C;
    *(f32 *)((u8 *)arg0 + 0x28) = temp_30;
    *(f32 *)((u8 *)arg0 + 0x2c) = temp_34;
    *(f32 *)((u8 *)arg0 + 0x30) = temp_10;
    *(f32 *)((u8 *)arg0 + 0x34) = temp_14;
    *(f32 *)((u8 *)arg0 + 0x38) = temp_20;
    *(f32 *)((u8 *)arg0 + 0x3c) = temp_24;
}

void fn_80124F90(void *arg0) {
    f32 r4_f1, r4_f0, r4_f5, r4_f4, r4_f6, r4_f8;
    f32 r4_f3, r4_f2, r4_f7, r4_f1b, r4_f0b;
    f32 r4_f9, r4_f10, r4_f11, r4_f12;

    r4_f1 = *(f32 *)((u8 *)arg0 + 0);
    r4_f0 = *(f32 *)((u8 *)arg0 + 0x10);
    r4_f5 = *(f32 *)((u8 *)arg0 + 4);
    r4_f4 = *(f32 *)((u8 *)arg0 + 0x14);
    r4_f6 = r4_f1 + r4_f0;
    r4_f8 = r4_f1 - r4_f0;
    r4_f3 = *(f32 *)((u8 *)arg0 + 8);
    r4_f2 = *(f32 *)((u8 *)arg0 + 0x18);
    r4_f7 = r4_f5 + r4_f4;
    r4_f1b = *(f32 *)((u8 *)arg0 + 0xC);
    r4_f0b = *(f32 *)((u8 *)arg0 + 0x1C);
    r4_f9 = r4_f5 - r4_f4;
    r4_f10 = r4_f3 + r4_f2;
    r4_f11 = r4_f3 - r4_f2;
    r4_f12 = r4_f1b - r4_f0b;
    r4_f4 = r4_f1b + r4_f0b;
    *(f32 *)((u8 *)arg0 + 0) = r4_f6 + r4_f10;
    *(f32 *)((u8 *)arg0 + 4) = r4_f7 + r4_f4;
    *(f32 *)((u8 *)arg0 + 0x10) = r4_f6 - r4_f10;
    *(f32 *)((u8 *)arg0 + 0x14) = r4_f7 - r4_f4;
    *(f32 *)((u8 *)arg0 + 8) = r4_f8 - r4_f12;
    *(f32 *)((u8 *)arg0 + 0xC) = r4_f9 + r4_f11;
    *(f32 *)((u8 *)arg0 + 0x18) = r4_f8 + r4_f12;
    *(f32 *)((u8 *)arg0 + 0x1C) = r4_f9 - r4_f11;
}

void fn_80125014(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;

    temp_f1 = *(f32 *)((u8 *)arg0 + 0);
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x10);
    temp_f5 = *(f32 *)((u8 *)arg0 + 4);
    temp_f4 = *(f32 *)((u8 *)arg0 + 0x14);
    temp_f6 = temp_f1 + temp_f0;
    temp_f8 = temp_f1 - temp_f0;
    temp_f3 = *(f32 *)((u8 *)arg0 + 8);
    temp_f2 = *(f32 *)((u8 *)arg0 + 0x18);
    temp_f7 = temp_f5 + temp_f4;
    temp_f1 = *(f32 *)((u8 *)arg0 + 0xC);
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x1C);
    temp_f9 = temp_f5 - temp_f4;
    temp_f10 = temp_f3 + temp_f2;
    temp_f11 = temp_f3 - temp_f2;
    temp_f12 = temp_f1 - temp_f0;
    temp_f4 = temp_f1 + temp_f0;
    *(f32 *)((u8 *)arg0 + 0) = temp_f6 + temp_f10;
    *(f32 *)((u8 *)arg0 + 4) = temp_f7 + temp_f4;
    *(f32 *)((u8 *)arg0 + 0x10) = temp_f6 - temp_f10;
    *(f32 *)((u8 *)arg0 + 0x14) = temp_f7 - temp_f4;
    *(f32 *)((u8 *)arg0 + 8) = temp_f8 + temp_f12;
    *(f32 *)((u8 *)arg0 + 0xC) = temp_f9 - temp_f11;
    *(f32 *)((u8 *)arg0 + 0x18) = temp_f8 - temp_f12;
    *(f32 *)((u8 *)arg0 + 0x1C) = temp_f9 + temp_f11;
}

void fn_80125098(void *arg0) {
    f32 f0, f1, f2, f3;
    f3 = *(f32 *)((u8 *)arg0 + 0);
    f1 = *(f32 *)((u8 *)arg0 + 8);
    f2 = *(f32 *)((u8 *)arg0 + 4);
    f0 = *(f32 *)((u8 *)arg0 + 12);
    *(f32 *)((u8 *)arg0 + 8) = f3 - f1;
    *(f32 *)((u8 *)arg0 + 0) = f3 + f1;
    *(f32 *)((u8 *)arg0 + 4) = f2 - f0;
    *(f32 *)((u8 *)arg0 + 12) = f2 + f0;
}

extern void fn_80125664(void *p0, void *p1, void *p2, void *p3);
void fn_80125CA0(void *arg0, void *arg1, void *arg2, s32 arg3) {
    fn_80125664(arg0, arg1, arg2, (u8 *)&lbl_802F6A40 + (arg3 << 8));
}

extern void fn_80125960(void *p0, void *p1, void *p2, void *p3);
void fn_80125CB4(void *arg0, void *arg1, void *arg2, s32 arg3) {
    fn_80125960(arg0, arg1, arg2, (u8 *)&lbl_802F6A40 + (arg3 << 8));
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
extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_8011943C(void *, s32);
extern s32 fn_801199A4(void *, s32);
