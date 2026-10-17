// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/ARC/arc.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>

extern void* fn_802ECC74(void*);
void AXFXSetHooks_8011FFB8();
void fn_80120084();
extern void *lbl_8055DEF8;
extern void *lbl_8055DEFC;
extern void *lbl_80559948[];
extern u32 lbl_8055994C[];
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
    s32 state = *(s32 *)((u8 *)arg0 + 0x64);
    if (arg1 != 0) {
        if (state == 0) {
            *(s32 *)((u8 *)arg0 + 0xb0) = 0;
            *(s32 *)((u8 *)arg0 + 0x64) = 1;
            *(s32 *)((u8 *)arg0 + 0xb8) = 0;
            *(s32 *)((u8 *)arg0 + 0xbc) = *(s32 *)((u8 *)arg0 + 0xc0);
        }
    } else if (state != 0) {
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

void fn_8011BDF0(s32 arg0) {
    s32 temp;
    s32 old;
    temp = arg0 - 8;
    if (temp != 0 && *(s32 *)(temp + 0x30) != 0) {
        old = OSEnableInterrupts();
        fn_8011BD20(temp);
        OSRestoreInterrupts(old);
    }
}

void fn_8011BEC8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 one = 1;
    s32 old;

    OSDisableInterrupts();
    *(s32 *)((u8 *)arg1 + 0xC) = one;
    *(s32 *)((u8 *)arg1 + 0x14) = arg2;
    *(s32 *)((u8 *)arg1 + 0x18) = arg3;
    *(s32 *)((u8 *)arg1 + 0x10) = 0;
    *(void **)arg1 = *(void **)((u8 *)arg0 + 0x30);
    old = *(s32 *)((u8 *)arg0 + 0x38);
    *(void **)((u8 *)arg0 + 0x30) = arg1;
    *(s32 *)((u8 *)arg0 + 0x38) = old + one;
    OSRestoreInterrupts(old);
}

s32 fn_8011BFFC(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4) {
    s32 temp = fn_8011BF4C(arg2, arg3, arg4) * 2;
    return temp | fn_8011BF4C(arg0, arg1, arg4);
}

u32 fn_8011C06C(void *arg0) {
    s32 oldInterrupts;
    s32 value;
    if (arg0 != NULL) {
        oldInterrupts = OSDisableInterrupts();
        if (*(s32 *)arg0 == 1)
            *(s32 *)arg0 = 2;
        value = *(s32 *)((char *)arg0 + 4);
        *(s32 *)((char *)arg0 + 4) = value + 1;
        OSRestoreInterrupts(oldInterrupts);
        value = *(s32 *)arg0;
        return (u32)((1 - value) | (value - 1)) >> 31;
    }
    return 1;
}

u32 fn_8011C1E0(s32 arg0, void *arg1) {
    s32 temp_r4;
    s32 temp_r4_2;
    if (arg0 != 0 && arg1 != 0 &&
        *(s32 *)((u8 *)arg1 + 0x18) != 0 &&
        *(s32 *)((u8 *)arg1 + 0x14) != 0) {
        OSDisableInterrupts();
        if (*(s32 *)((u8 *)arg1 + 0xC) == 1)
            *(s32 *)((u8 *)arg1 + 0xC) = 2;
        temp_r4 = *(s32 *)((u8 *)arg1 + 0x10);
        *(s32 *)((u8 *)arg1 + 0x10) = temp_r4 + 1;
        OSRestoreInterrupts(temp_r4);
        temp_r4_2 = *(s32 *)((u8 *)arg1 + 0xC);
        return (u32)((1 - temp_r4_2) | (temp_r4_2 - 1)) >> 31;
    }
    return 1;
}

void fn_8011C274(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg1 != 0 &&
        *(s32 *)((u8 *)arg1 + 0x18) != 0 &&
        *(s32 *)((u8 *)arg1 + 0x14) != 0) {
        do {
            OSYieldThread();
        } while (fn_8011C1E0(arg0, arg1) == 0);
    }
}

void fn_8011C2EC(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg1 != 0 &&
        *(s32 *)((u8 *)arg1 + 0x18) != 0 &&
        *(s32 *)((u8 *)arg1 + 0x14) != 0) {
        OSDisableInterrupts();
        *(s32 *)((u8 *)arg1 + 0x10) = *(s32 *)((u8 *)arg1 + 0x10) - 1;
        if (*(s32 *)((u8 *)arg1 + 0x10) == 0)
            *(s32 *)((u8 *)arg1 + 0xC) = 1;
        OSRestoreInterrupts();
    }
}

void fn_8011C364(s32 arg0) {
    if (arg0 != 0) {
        fn_8011C0E0();
        OSCancelAlarm((OSAlarm *)(arg0 + 8));
        fn_80120084(arg0);
    }
}

void fn_8011C3A8(s32 arg0, void *arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 zero = 0;
    s32 end;
    *(s32 *)((u8 *)arg1) = zero;
    *(s32 *)((u8 *)arg1 + 4) = zero;
    end = arg2 + ((arg3 >> 3) * arg5);
    *(s32 *)((u8 *)arg1 + 8) = arg4;
    *(s32 *)((u8 *)arg1 + 0x28) = 0x20 - __cntlzw((u16)(end - 1));
    if (arg6 != 0)
        *(s32 *)((u8 *)arg1 + 0xC) = 1 << (arg4 - 1);
    else
        *(s32 *)((u8 *)arg1 + 0xC) = zero;
    *(s32 *)((u8 *)arg1 + 0x2C) = arg0;
}

s32 fn_8011C400(u32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    s32 var_r7 = arg4;
    s32 var_r8 = arg4;
    s32 var_r9 = 0;
    u8 *out = arg1;
    u8 *left = arg2;
    u8 *right = arg3;
    u8 temp;
    do {
        var_r9++;
        if (arg0 & 1) {
            temp = *right;
            var_r8--;
            right++;
        } else {
            temp = *left;
            var_r7--;
            left++;
        }
        *out = temp;
        out++;
        arg0 >>= 1;
        if (var_r7 == 0 || var_r8 == 0) break;
    } while (1);
    if (var_r7 != 0) {
        do { temp = *left; var_r7--; left++; *out = temp; out++; } while (var_r7 != 0);
    } else if (var_r8 != 0) {
        do { temp = *right; var_r8--; right++; *out = temp; out++; } while (var_r8 != 0);
    }
    return var_r9;
}

extern void fn_8011C4A0(s32, s32, s32, s32);
void fn_8011CD90(s32 arg0, s32 arg1, s32 arg2) {
    s32 a = arg2;
    s32 b = arg2 + 0x100;
    s32 c = arg2 + 0x140;
    u32 i;
    for (i = 0; i < 0x10; i++) {
        fn_8011C4A0(arg1, c, b, a);
        b += 4;
        a += 0x10;
        c += 4;
    }
    fn_8011C4A0(arg1, arg0 + 0x24, arg0 + 0x20, arg0 + 0x10);
    *(s32 *)(arg2 + 0x180) = 0;
}

s32 fn_8011DF68(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 var_r5 = arg2;
    u32 temp;
    if (var_r5 <= 8U) var_r5 = 8;
    else if (var_r5 < 0x10U) var_r5 = 0x10;
    temp = var_r5 * arg3;
    return (((u32)(arg0 * var_r5) >> 3) + ((temp * (arg1 >> 3)) >> 3) + 3) & 0xFFFFFFFC;
}

extern void *lbl_8055DEF0;
void* fn_8011FF24(void) {
    return lbl_8055DEF0;
}

void AXFXSetHooks_8011FFB8(void *arg0, void *arg1) {
    lbl_8055DEF8 = arg0;
    lbl_8055DEFC = arg1;
}

extern void *lbl_8055DEF8;
extern void *lbl_8055DEFC;
extern u32 lbl_8055DEF4;
extern void *lbl_80559948[];
extern u32 lbl_8055994C[];
extern void *malloc(u32);
extern void free(void *);
extern void *fn_8011FFC4(s32);
void *fn_8011FFC4(s32 arg0) {
    s32 base;
    u8 mode;
    u8 offset;
    void *result;
    if (arg0 == 0 || (u32)(arg0 + 0x10000) == 0xFFFFFFFF) return 0;
    if (lbl_8055DEF8 != 0) {
        result = ((void *(*)(s32))lbl_8055DEF8)(arg0 + 0x40);
        if (result != 0) {
            if (result == (void *)-1) return 0;
            mode = 3;
            goto got_memory;
        }
    }
    result = malloc(arg0 + 0x40);
    if (result == 0) return 0;
    mode = 0;
got_memory:
    base = (s32)result;
    offset = 0x40 - (base & 0x1F);
    result = (void *)(base + offset);
    *((u8 *)result - 1) = offset;
    *((u8 *)result - 2) = mode;
    if (mode == 3) *(void **)((u8 *)result - 8) = lbl_8055DEFC;
    return result;
}

void fn_80120084(void *arg0) {
    u8 *ptr = arg0;
    u8 *base;
    if (ptr == 0) return;
    base = ptr - ptr[-1];
    if (ptr[-2] == 3) ((void (*)(void *))*(void **)(ptr - 8))(base);
    else free(base);
}

extern void fn_80121C68(void *);
extern void fn_80122E08(s32, void *, s32, void *);
extern void fn_80122ED8(s32, void *, s32, void *);
extern void fn_80122FA4(s32, void *, s32, void *);
extern void fn_80123CEC(s32, void *, s32, void *);
extern void fn_80120F84(s32, s32, void *);
extern void fn_80123E98(void *, void *);
extern void fn_80121848(void *);
extern void fn_80124AD8(void *, void *);
extern void fn_80121BB0(void *);
extern void fn_80124F90(void *);
extern void fn_80125098(void *);
void fn_80120CA4(s32 count, void *dst, s32 mode, s32 srcIndex, void *src) {
    s32 n;
    if (count > 0x20) {
        n = count >> 2;
        fn_80121C68((u8 *)src + (srcIndex - n) * 4);
        if (count > 0x200) {
            fn_80122E08(n, dst, srcIndex, src);
            fn_80122ED8(n, (u8 *)dst + n * 4, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + n * 8, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + ((n * 4 - n) * 4), srcIndex, src);
        } else if (n > 0x20) {
            fn_80122FA4(count, dst, srcIndex, src);
        } else {
            fn_80123CEC(count, dst, srcIndex, src);
        }
        fn_80120F84(count, mode, dst);
    } else if (count > 8) {
        if (count == 8) {
            fn_80123E98(dst, (u8 *)src + (srcIndex - 8) * 4);
            fn_80121848(dst);
        } else {
            fn_80124AD8(dst, src);
            fn_80121BB0(dst);
        }
    } else if (count != 8) {
        if (count == 4)
            fn_80125098(dst);
        else
            fn_80124F90(dst);
    }
}

void fn_80121BB0(void *arg0) {
    float *p = (float *)arg0;
    float a = p[2];
    float b = p[8];
    float c = p[3];
    float d = p[9];
    float e = p[6];
    float f = p[12];
    float g = p[7];
    float h = p[13];
    p[2] = b; p[3] = d; p[6] = f; p[7] = h;
    p[8] = a; p[9] = c; p[12] = e; p[13] = g;
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
