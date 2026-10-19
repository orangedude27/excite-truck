// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern f32 lbl_80329BC8[];
extern void fn_8011AF94(f32 *, s32, void *, f32 *, s32);
extern void fn_801200BC(s32, s32, f32 *, s32, s32);
extern void fn_8012023C(s32, s32, f32 *, s32, s32);
typedef struct {
    u32 value;
    u32 *next;
    u32 count;
    u32 *start;
} BitReader8011;

#include <revolution/ARC/arc.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>
#include <revolution/DVD/dvd.h>
#define M2C_FIELD(base, type, offset) (*(type)((u8 *)(base) + (offset)))

extern void* fn_802ECC74(void*);
extern void *fn_8011FFC4(s32);
extern f32 lbl_80329D48[];
extern f64 lbl_805611D8;
extern void fn_8011A330(void *);
void AXFXSetHooks_8011FFB8();
void fn_80120084();
extern void *lbl_8055DEF8;
extern void *lbl_8055DEFC;
extern void *lbl_80559948[];
extern u32 lbl_8055994C[];
extern void fn_80127F70(void*);
extern void fn_80127F94(void*);
extern s32 fn_8011A7CC(DVDFileInfo *);
extern s32 OSDisableInterrupts(void);
void fn_80127440(void*);
extern void fn_80127398(s32);
extern void fn_802E300C(s32);
extern void* lbl_8041D728[];
extern u8 lbl_802F6A40[];
extern u8 lbl_8041D508[];

BOOL ARCFastOpen(ARCHandle *handle, s32 entrynum, ARCFileInfo *info) {
    u32 *nodes = (u32 *)handle->FSTStart;
    s32 offset;
    if (entrynum < 0 || (u32)entrynum >= handle->entryNum || (nodes[entrynum * 3] & 0xFF000000) != 0) return FALSE;
    info->handle = handle;
    offset = (entrynum * 0xC) + (s32)nodes;
    info->startOffset = *(u32 *)(offset + 4);
    info->length = *(u32 *)(offset + 8);
    return TRUE;
}

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
#pragma dont_inline on
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

void fn_80116E2C(const u8 *arg0) {
    const u8 *src = arg0;
    u8 *dst = lbl_8041D508;
    u8 c;
    do {
        c = *src;
        *dst = c;
        if ((s8)c == 0)
            return;
        dst++;
        src++;
    } while (1);
}

extern u8 lbl_8041D508[];
extern s32 (*lbl_8055DEC8)(s32);
extern s32 lbl_8055DECC;
extern s32 lbl_8055DED0;
s32 fn_80116E54(s32 (*arg0)(s32), s32 arg1) {
    s32 (*func)(s32);
    s32 result;
    if (arg0 == 0)
        return 0;
    func = lbl_8055DEC8;
    if (func == 0) {
        func = arg0;
        lbl_8055DEC8 = arg0;
    }
    if ((u32)func != (u32)arg0) {
        if (lbl_8055DED0 == 0) {
            lbl_8055DEC8 = arg0;
        } else {
            return 0;
        }
    }
    result = lbl_8055DEC8(arg1);
    if (result != 0)
        lbl_8055DECC = result;
    return lbl_8055DECC != 0;
}

void fn_80116EE4(s8 *arg0, s16 *arg1, u32 arg2) {
    s16 *var_r4 = arg1;
    s8 *var_r3 = arg0;
    u32 var_r5 = arg2 >> 1U;
    u32 temp_r0;
    u32 var_ctr;
    u32 var_ctr_2;
    s16 temp_r0_2;
    s16 temp_r0_3;
    if (var_r5 != 0) {
        temp_r0 = var_r5 >> 3U;
        var_ctr = temp_r0;
        if (temp_r0 != 0) {
            do {
                var_r3[0] = (s8)(var_r4[0] >> 8);
                var_r3[1] = (s8)(var_r4[1] >> 8);
                var_r3[2] = (s8)(var_r4[2] >> 8);
                var_r3[3] = (s8)(var_r4[3] >> 8);
                var_r3[4] = (s8)(var_r4[4] >> 8);
                var_r3[5] = (s8)(var_r4[5] >> 8);
                var_r3[6] = (s8)(var_r4[6] >> 8);
                temp_r0_2 = var_r4[7];
                var_r4 += 8;
                var_r3[7] = (s8)(temp_r0_2 >> 8);
                var_r3 += 8;
                var_ctr -= 1;
            } while (var_ctr != 0);
            var_r5 &= 7;
            if (var_r5 != 0) goto tail;
        } else {
tail:
            var_ctr_2 = var_r5;
            do {
                temp_r0_3 = *var_r4;
                var_r4 += 1;
                *var_r3 = (s8)(temp_r0_3 >> 8);
                var_r3 += 1;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
u32 fn_80116F8C(void *arg0) {
    s32 temp_r28;
    s32 temp_r30;
    u32 temp_r0;
    u32 temp_r29;
    u32 temp_r4;
    u32 temp_r6;
    u32 temp_r9;
    u32 *data = (u32 *)arg0;

    temp_r4 = data[0x4C / 4];
    temp_r0 = data[0x40 / 4];
    if (temp_r0 < temp_r4) {
        temp_r30 = temp_r4 - temp_r0;
        temp_r6 = data[0x38 / 4] - temp_r30;
        temp_r9 = data[0x2C / 4];
        data[0x38 / 4] = temp_r6;
        temp_r29 = (temp_r30 * 0x3E8) / ((data[0x78 / 4] * (data[0x70 / 4] * data[0x74 / 4])) >> 3);
        if (temp_r6 < temp_r9) {
            temp_r28 = temp_r9 - temp_r6;
            data[0x38 / 4] = temp_r6 + data[0x28 / 4];
            __memclr((void *)temp_r9, temp_r30 - temp_r28);
            __memclr((void *)data[0x38 / 4], temp_r28);
        } else {
            __memclr((void *)temp_r6, temp_r30);
        }
        data[0x40 / 4] += temp_r30;
        return temp_r29;
    }
    return 0;
}
#pragma pop
extern s32 fn_80117074(void*);
extern s32 fn_80116D30(void);
void fn_80117330(void* arg0) {
 if(*(s32*)((u8*)arg0+0x268)==0) {
  s32 value=fn_80116D30();
  s32 count=*(s32*)((u8*)arg0+0x258);
  *(s32*)((u8*)arg0+0x268)=value;
  *(s32*)((u8*)arg0+0x26c)=count-1;
  *(s32*)((u8*)arg0+0x330)=0;
 }
}

s32 fn_80117598(s32 arg0,s32 arg1){
 s32 off=((arg0+0x340)-arg0);
 s32* p=(s32*)(arg0-off);
 s32 v=p[0x33c/4];
 return (~v) & ((v-arg1 | arg1-v)>>31);
}

void fn_801175C4(s32 arg0,s32 arg1){
 s32 off=((arg0+0x340)-arg0);
 s32* p=(s32*)(arg0-off);
 if(p[0x2e8/4]) fn_80117074(p);
 p[0x33c/4]=arg1;
}

void fn_80117618(void *arg0, void *arg1) {
    volatile s32 *out = (volatile s32 *)arg1;
    s32 temp_r5;
    u32 half;

    out[5] = 0;
    out[1] = (*(s32 *)((u8 *)arg0 + 0x23C) + 7) & ~7;
    out[2] = (*(s32 *)((u8 *)arg0 + 0x240) + 7) & ~7;
    half = (u32)(*(s32 *)((u8 *)arg0 + 0x23C) + 1);
    out[3] = ((half >> 1) + 7) & ~7;
    half = (u32)(*(s32 *)((u8 *)arg0 + 0x240) + 1);
    out[6] = 1;
    temp_r5 = ((half >> 1) + 7) & ~7;
    out[9] = 1;
    out[4] = temp_r5;
    out[12] = 1;
    temp_r5 = (*(u32 *)((u8 *)arg0 + 0x20) >> 20) & 1;
    out[7] = 0;
    out[15] = temp_r5;
    out[10] = 0;
    out[13] = 0;
    out[16] = 0;
    out[8] = 0;
    out[11] = 0;
    out[14] = 0;
    out[17] = 0;
    if (*(s32 *)((u8 *)arg0 + 0x380) != 0) { out[0] = 1; return; }
    out[18] = 1; out[0] = 2;
    out[19] = 0; out[20] = 0; out[21] = 1; out[22] = 0;
    out[23] = 0; out[24] = 1; out[25] = 0; out[26] = 0;
    out[27] = temp_r5; out[28] = 0; out[29] = 0;
}

void fn_801176FC(void* arg0,s32 arg1){if(arg0)*(s32*)((u8*)arg0+0xb8)=arg1;}

void fn_80118C1C(void *arg0, s32 arg1) {
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 0x264);
    if (temp_r0 != 0) {
        s32 temp_r5 = *(s32 *)((u8 *)arg0 + 0x29c);
        *(s32 *)((u8 *)arg0 + 0x29c) = temp_r5 + (arg1 - temp_r0);
        *(s32 *)((u8 *)arg0 + 0x264) = 0;
    }
}

void fn_80118F1C(void *arg0, s32 arg1) {
    s32 temp_r0 = *(s32*)((u8*)arg0 + 0x274);
    if (temp_r0 != 0) {
        u32 temp_r5 = *(u32*)((u8*)arg0 + 0x278);
        u32 temp_r6 = arg1 - temp_r0;
        *(s32*)((u8*)arg0 + 0x274) = 0;
        if (temp_r6 > temp_r5) {
            *(u32*)((u8*)arg0 + 0x280) = temp_r5;
            *(s32*)((u8*)arg0 + 0x284) = *(s32*)((u8*)arg0 + 0x27C);
            *(u32*)((u8*)arg0 + 0x278) = temp_r6;
            *(s32*)((u8*)arg0 + 0x27C) = *(s32*)((u8*)arg0 + 0xC);
        } else if (temp_r6 > *(u32*)((u8*)arg0 + 0x280)) {
            *(u32*)((u8*)arg0 + 0x280) = temp_r6;
            *(s32*)((u8*)arg0 + 0x284) = *(s32*)((u8*)arg0 + 0xC);
        }
    }
}

void fn_80119214(void) {
    AXFXSetHooks_8011FFB8();
}

extern void memset(void *, int, unsigned int);
void fn_80119218(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    void *temp_r31 = (u8*)arg0 + 0x14C;
    memset(temp_r31, 0, 0x30);
    *(s16*)temp_r31 = arg2;
    *(s16*)((u8*)temp_r31 + 4) = arg3;
    *(s16*)((u8*)arg0 + 0x1AC) = arg1;
    *(s16*)((u8*)arg0 + 0x1AE) = 0;
    *(s32*)((u8*)arg0 + 0x144) = 3;
    *(s32*)((u8*)arg0 + 0x1C) |= 0x212;
}

extern void AXSetVoiceState(s32);
s32 fn_8011943C(void *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r3;
    temp_r0 = *(s32 *)arg0;
    if (temp_r0 != 0) {
        ((void (*)())AXSetVoiceState)(temp_r0, arg1);
    }
    if ((temp_r3 = *(s32 *)((u8 *)arg0 + 4)) != 0) {
        ((void (*)())AXSetVoiceState)(temp_r3, arg1);
    }
}

void fn_80119498(void *arg0) {
    fn_8011943C(arg0, 1);
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
}

s32 fn_801194D0(void* arg0) {
 return *(u16*)((u8*)arg0+0x1be) + (*(u16*)((u8*)arg0+0x1bc)<<16);
}

s32 fn_801194E4(void *arg0) {
    s32 first;
    s32 current;
    s32 result;
    do {
        first = fn_801194D0(*(void **)arg0);
        fn_801194D0(*(void **)arg0);
        result = fn_801194D0(*(void **)arg0);
    } while ((u32)(result - first) >= 0x400);
    current = result * 2 - *(s32 *)((u8 *)arg0 + 0x10);
    if (*(s32 *)((u8 *)arg0 + 4) != 0)
        current *= 2;
    return current;
}

void fn_80119558(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x34) = 1;
    fn_80119498(arg0);
    *(s32 *)((u8 *)arg0 + 0x48) = fn_801194E4(arg0);
    *(s32 *)((u8 *)arg0 + 0x50) = fn_80116D30();
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

extern f32 lbl_805611B0;
extern f32 lbl_805611B4;
extern f64 lbl_805611B8;
extern f32 lbl_805611C0;
void fn_80119B38(void *arg0, s32 arg1) {
    s32 value = arg1;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f1;
    if (value < 0) value = 0;
    if (value > 0x10000) value = 0x10000;
    temp_f31 = (f32)value / lbl_805611B0;
    temp_f3 = (f32)fn_8002EFBC(lbl_805611B4 - temp_f31, lbl_805611B8);
    *(s32*)((u8*)arg0 + 0xa8) = (s32)(lbl_805611C0 * temp_f3);
    temp_f1 = (f32)fn_8002EFBC(temp_f31, lbl_805611B8);
    *(s32*)((u8*)arg0 + 0xac) = (s32)(lbl_805611C0 * temp_f1);
    fn_80119288(arg0, temp_f1);
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

s32 fn_80119CB0(void *arg0, s32 arg1) {
    s32 *var_r3;
    if (arg1 != 0) {
        if (*(s32 *)((u8 *)arg0 + 0xb0) != 0) {
            fn_801195A0((u8 *)arg0 + 0x7c);
        }
        var_r3 = (s32 *)((u8 *)arg0 + 0xb4);
        *(s32 *)((u8 *)arg0 + 0xb4) = 1;
    } else {
        if (*(s32 *)((u8 *)arg0 + 0xb0) == 0) {
            if (*(s32 *)((u8 *)arg0 + 0xbc) == 0) {
                fn_80119558((u8 *)arg0 + 0x7c);
            }
        } else {
            fn_80119498((u8 *)arg0 + 0x7c);
        }
        var_r3 = (s32 *)((u8 *)arg0 + 0xb4);
        *(s32 *)((u8 *)arg0 + 0xb4) = 0;
    }
    return *var_r3;
}

extern s32 lbl_8055DEE0[];
extern s32 lbl_8055DEE4;
extern s32 lbl_8055DEE8;
extern void fn_80119DD0(void);
extern void fn_8011A6A0(void *);
extern void TRKGetFreeBuffer(void *);
void *fn_8011A168(void *arg0) {
    s32 *src = (s32 *)arg0;
    if (arg0 == NULL) {
        lbl_8055DEE0[0] = 0;
        lbl_8055DEE0[1] = 0;
    } else {
        lbl_8055DEE0[0] = src[0];
        lbl_8055DEE4 = src[1];
    }
    return &fn_80119DD0;
}

void fn_8011A45C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0, temp_r31, temp_r3, temp_r3_2, temp_r4, var_r31;
    volatile s32 *counter = (volatile s32 *)((u8 *)arg0 + 0xC0);
    temp_r31 = fn_80116BD4(arg1, 0x3E8, *(s32 *)((u8 *)arg0 + 0xBC));
    temp_r3 = fn_80116D30();
    var_r31 = temp_r3;
    *counter = *counter + (temp_r31 - (temp_r3 - arg2));
    goto loop;
loop:
    temp_r3_2 = fn_80116D30();
    temp_r0 = *counter;
    temp_r4 = temp_r3_2 - var_r31;
    if (temp_r4 < temp_r0) goto loop;
    var_r31 = temp_r3_2;
    *counter = temp_r0 - temp_r4;
    if (*counter > 0) goto loop;
}

void fn_8011A4F8(u32 arg0, void *arg1) {
#define FIELD(p, o) (*(s32 *)((u8 *)(p) + (o)))
    s32 temp_r3_2, temp_r3_4, temp_r4;
    u32 temp_r3, temp_r3_3, var_r30;
    void *temp_r31;
    var_r30 = arg0;
    temp_r31 = *(void **)((u8 *)arg1 + 0x7C);
    if (FIELD(temp_r31, 0xC4) == 0) {
        if ((arg0 != 0x8000) && (arg0 != (u32)((FIELD(temp_r31, 0xB8) - FIELD(temp_r31, 0x90)) + FIELD(temp_r31, 0x94)))) {
            FIELD(temp_r31, 0x24) = 0; FIELD(temp_r31, 0x20) = 1; return;
        }
        temp_r4 = FIELD(temp_r31, 0x94);
        if (temp_r4 != 0) {
            temp_r3 = *(u32 *)((u8 *)temp_r31 + 0xAC);
            memmove((void *)temp_r3, (void *)(temp_r3 + temp_r4), FIELD(temp_r31, 0xB8) - FIELD(temp_r31, 0x90));
            temp_r3_2 = FIELD(temp_r31, 0x94); FIELD(temp_r31, 0x94) = 0; var_r30 -= temp_r3_2;
        }
        FIELD(temp_r31, 0x28) += var_r30; FIELD(temp_r31, 0x90) += var_r30;
        temp_r3_3 = *(u32 *)((u8 *)temp_r31 + 0xAC) + var_r30;
        *(u32 *)((u8 *)temp_r31 + 0xAC) = temp_r3_3;
        if (temp_r3_3 >= *(u32 *)((u8 *)temp_r31 + 0xA8)) *(u32 *)((u8 *)temp_r31 + 0xAC) = *(u32 *)((u8 *)temp_r31 + 0xA4);
        FIELD(temp_r31, 0xA0) -= var_r30;
        *(u32 *)((u8 *)temp_r31 + 0x4C) += var_r30;
        if (*(u32 *)((u8 *)temp_r31 + 0x4C) > *(u32 *)((u8 *)temp_r31 + 0x44)) *(u32 *)((u8 *)temp_r31 + 0x44) = *(u32 *)((u8 *)temp_r31 + 0x4C);
        if (FIELD(temp_r31, 0xBC) != 0) fn_8011A45C(temp_r31, var_r30, FIELD(temp_r31, 0xCC));
        temp_r3_4 = fn_80116D30() - FIELD(temp_r31, 0xCC);
        FIELD(temp_r31, 0xCC) = temp_r3_4; FIELD(temp_r31, 0x30) += temp_r3_4;
        if (FIELD(temp_r31, 0xC8) != 0 || FIELD(temp_r31, 0x2C) != 0) FIELD(temp_r31, 0x3C) += FIELD(temp_r31, 0xCC);
        else FIELD(temp_r31, 0x38) += FIELD(temp_r31, 0xCC);
        FIELD(temp_r31, 0x24) = 0;
        if (FIELD(temp_r31, 0x50) == 0) fn_8011A6A0(temp_r31);
    }
#undef FIELD
}

s32 fn_8011A7CC(DVDFileInfo *info) {
    s32 *p = (s32 *)info;
    s32 status;
    if (p[0x20 / 4] != 0) return 0;
    if (p[0x50 / 4] != 0) return 0;
    status = DVDGetDriveStatus();
    if (status == 0) {
        fn_8011A6A0(info);
    } else if (status == 0xB) {
        p[0x20 / 4] = 1;
    }
    return p[0x24 / 4];
}

#pragma dont_inline on
s32 fn_8011A870(void *arg0, s32 arg1) {
    if (arg1 & 1) {
        if (*(s32 *)((char *)arg0 + 0x50) == 0)
            *(s32 *)((char *)arg0 + 0x50) = 1;
        if (arg1 & 0x80000000) {
            do {
            } while (*(s32 *)((char *)arg0 + 0x24) != 0);
        }
    } else if (arg1 & 2) {
        if ((u32)*(s32 *)((char *)arg0 + 0x50) == 1U)
            *(s32 *)((char *)arg0 + 0x50) = 0;
        if (arg1 & 0x80000000)
            fn_8011A7CC(arg0);
    }
    return *(s32 *)((char *)arg0 + 0x50);
}
#pragma dont_inline reset
s32 fn_8011AC04(s32 arg0, s32 arg1) {
    return (arg1 + 0x7FFF) & 0xFFFF8000;
}

void fn_8011AC10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r4;
    s32* p = (s32*)arg0;
    OSDisableInterrupts();
    arg2 &= 0xFFFF8000;
    temp_r4 = arg1 + arg2;
    p[0xA0/4] = arg2;
    p[0x40/4] = arg2;
    p[0xA4/4] = arg1;
    p[0x9C/4] = arg1;
    p[0xAC/4] = arg1;
    p[0xA8/4] = temp_r4;
    p[0x4C/4] = 0;
    p[0xB8/4] = arg3;
    p[0xBC/4] = arg4;
    p[0xD0/4] = (s32)arg0;
    OSRestoreInterrupts(temp_r4);
}

extern f32 lbl_80329D48[];
extern f64 lbl_805611D8;
extern void fn_8011A330(void *);
void fn_8011AC84(void *arg0) {
    fn_8011A330(arg0);
    if (*(s32 *)((u8 *)arg0 + 0xB0) == 0) {
        DVDClose((u8 *)arg0 + 0x54);
    }
}

f32 fn_8011AE18(s32 arg0) {
    f32 temp;
    temp = (f32)(((u32)arg0 >> 5) & 0x1FFFFFF) * lbl_80329D48[((u32)arg0 * 4) & 0x7C];
    if (arg0 & 0x10000000) {
        temp = (f32)(-((f64)temp));
    }
    return temp;
}

void fn_8011AE68(s32 arg0, f32 *arg1, u32 arg2, f32 farg0) {
    s32 *out = (s32 *)arg0;
    f32 *in = arg1;
    u32 i;
    for (i = 0; i < arg2; i++) {
        f32 v = *in * farg0;
        *(s16 *)((u8 *)out + 2) = (s16)(v * 32767.0f + 0.5f);
        in++;
        out++;
    }
}

void fn_8011AED8(s32 arg0, f32 *arg1, u32 arg2, f32 farg0) {
    s32 *out = (s32 *)arg0;
    f32 *in = arg1;
    u32 i;
    for (i = 0; i < arg2; i++) {
        f32 v1 = in[0] * farg0;
        f32 v2 = in[1] * farg0;
        *(s16 *)((u8 *)out + 2) = (s16)(v1 * 32767.0f + 0.5f);
        *(s16 *)((u8 *)out + 4) = (s16)(v2 * 32767.0f + 0.5f);
        in += 2;
        out += 2;
    }
}

s32 fn_8011B2AC(s32 size, u32 channels, s32 flags, s32 arg3, s32 arg4, s32 output, u32 *input, u32 bands, f32 gain, s32 arg8) {
    f32 buffer[4096];
    f32 factors[26];
    BitReader8011 bits;
    s32 mode;
    u32 i, j, index;
    f32 *p;
    f32 *q;
    mode = flags & 1;
    bits.start = input;
    bits.next = input;
    bits.count = 0;
    bits.value = 0;
    if (mode) {
        if (bits.count < 2) {
            bits.value = *bits.next >> (2 - bits.count);
            bits.count += 30;
            bits.next++;
        } else {
            bits.value >>= 2;
            bits.count -= 2;
        }
    }
    p = buffer;
    for (i = 0; i < channels; i++) {
        {
            u32 value;
            if (bits.count < 29) {
                u32 word = *bits.next;
                value = bits.value | (word << bits.count);
                bits.value = word >> (29 - bits.count);
                index = value & 0x1fffffff;
                bits.count += 3;
                bits.next++;
            } else {
                bits.count -= 29;
                value = bits.value;
                index = value & 0x1fffffff;
                bits.value >>= 29;
            }
        }
        p[0] = fn_8011AE18(index);
        {
            u32 value;
            if (bits.count < 29) {
                u32 word = *bits.next;
                value = bits.value | (word << bits.count);
                bits.value = word >> (29 - bits.count);
                index = value & 0x1fffffff;
                bits.count += 3;
                bits.next++;
            } else {
                bits.count -= 29;
                value = bits.value;
                index = value & 0x1fffffff;
                bits.value >>= 29;
            }
        }
        p[1] = fn_8011AE18(index);
        q = factors;
        for (j = 0; j < bands; j++) {
            {
            u32 value;
            if (bits.count < 8) {
                u32 word = *bits.next;
                value = bits.value | (word << bits.count);
                bits.value = word >> (8 - bits.count);
                index = value & 0xff;
                bits.count += 24;
                bits.next++;
            } else {
                bits.count -= 8;
                value = bits.value;
                index = value & 0xff;
                bits.value >>= 8;
            }
        }
            if (index > 95) index = 95;
            *q++ = lbl_80329BC8[index];
        }
        fn_8011AF94(p, size, &bits, factors, arg8);
        if (mode) fn_8012023C(size, 1, p, arg3, arg4);
        else fn_801200BC(size, -1, p, arg3, arg4);
        p += size;
    }
    if (channels == 1) fn_8011AE68(output, buffer, size, gain);
    else fn_8011AED8(output, buffer, size, gain);
    bits.count = 0;
    return ((u32)bits.next - (u32)bits.start) & 0x1fffffff;
}

void fn_8011BC48(void) {
    fn_80120084();
}

s32 fn_8011BC4C(void *arg0, void *arg1) {
    void *var_r5;
    void *temp_r0;
    if (arg0 == NULL) return 0;
    var_r5 = *(void **)((u8 *)arg0 + 0x30);
    if (var_r5 == arg1) {
        *(void **)((u8 *)arg0 + 0x30) = *(void **)var_r5;
        return 1;
    }
    temp_r0 = *(void **)var_r5;
loop:
    if (temp_r0 == arg1) {
        *(void **)var_r5 = *(void **)arg1;
        return 1;
    }
    var_r5 = temp_r0;
    temp_r0 = *(void **)var_r5;
    if (temp_r0 == NULL) return 0;
    goto loop;
}

void fn_8011BCAC(void **head, void *node) {
    u32 key;
    void *cur = *head;
    if (cur == 0) {
        *(void **)((u8 *)node + 4) = 0;
        *head = node;
        return;
    }
    key = *(u32 *)((u8 *)node + 8);
    if (key >= *(u32 *)((u8 *)cur + 8)) {
        *(void **)((u8 *)node + 4) = cur;
        *head = node;
        return;
    }
    while (*(void **)((u8 *)cur + 4) != 0) {
        void *next = *(void **)((u8 *)cur + 4);
        if (key >= *(u32 *)((u8 *)next + 8)) {
            *(void **)((u8 *)node + 4) = next;
            *(void **)((u8 *)cur + 4) = node;
            return;
        }
        cur = next;
    }
    *(void **)((u8 *)node + 4) = 0;
    *(void **)((u8 *)cur + 4) = node;
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

void *fn_8011BE48(s32 arg0) {
    void *ptr;
    s32 sign;
    s32 value;
    ptr = fn_8011FFC4(0x40);
    if (ptr != NULL) {
        memset(ptr, 0, 0x40);
        sign = arg0 >> 31;
        *(s32 *)((u8 *)ptr + 0x00) = 0;
        value = (sign ^ arg0) - sign;
        *(s32 *)((u8 *)ptr + 0x04) = 1;
        *(s32 *)((u8 *)ptr + 0x30) = 0;
        *(s32 *)((u8 *)ptr + 0x34) = 1;
        *(s32 *)((u8 *)ptr + 0x38) = 0;
        *(s32 *)((u8 *)ptr + 0x3C) = value;
    }
    return ptr;
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
    *(s32 *)((u8 *)arg0 + 0x38) = old + 1;
    OSRestoreInterrupts(old);
}

s32 fn_8011BFFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = fn_8011BF4C(arg2, arg3, arg4) << 1;
    s32 result = fn_8011BF4C(arg0, arg1, arg4);
    return result | temp;
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

#pragma dont_inline on
u32 fn_8011C1E0(s32 arg0, void *arg1) {
    register s32 temp_r4;
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
#pragma dont_inline reset

void fn_8011C274(s32 arg0, void *arg1) {
    if (arg0 == 0) goto done;
    if (arg1 == 0) goto done;
    if (*(s32 *)((u8 *)arg1 + 0x18) == 0) goto done;
    if (*(s32 *)((u8 *)arg1 + 0x14) == 0) goto done;
    goto retry;
retry:
    OSYieldThread();
    if (fn_8011C1E0(arg0, arg1) == 0) goto retry;
done:
    return;
}

void fn_8011C2EC(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg1 != 0 &&
        *(s32 *)((u8 *)arg1 + 0x18) != 0 &&
        *(s32 *)((u8 *)arg1 + 0x14) != 0) {
        s32 value;
        OSDisableInterrupts();
        value = *(volatile s32 *)((u8 *)arg1 + 0x10);
        *(volatile s32 *)((u8 *)arg1 + 0x10) = value - 1;
        if (*(volatile s32 *)((u8 *)arg1 + 0x10) == 0)
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
    register s32 zero;
    register s32 end;
    zero = 0;
    end = arg2 + ((arg3 >> 3) * arg5);
    *(s32 *)((u8 *)arg1 + 0) = zero;
    *(s32 *)((u8 *)arg1 + 4) = zero;
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
    u8 offset;
    u32 mode;
    s32 result;
    if (arg0 == 0 || (u32)(arg0 + 0x10000) == 0xFFFFFFFF) return 0;
    if (lbl_8055DEF8 != 0) {
        result = ((s32 (*)(s32))lbl_8055DEF8)(arg0 + 0x40);
        if (result != 0) {
            if (result == -1) return 0;
            mode = 3;
            goto got_memory;
        }
    }
    result = (s32)malloc(arg0 + 0x40);
    if (result == 0) return 0;
    mode = 0;
got_memory:
    base = result;
    offset = 0x40 - (base & 0x1F);
    result += offset;
    *((u8 *)result - 1) = offset;
    *((u8 *)result - 2) = mode;
    if (mode == 3) *(void **)(result - 8) = lbl_8055DEFC;
    return (void *)result;
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

void fn_80121848(void *arg0) {
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f1;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f8;
    f32 temp_f9;
    temp_f0 = *(f32 *)((s8 *)arg0 + 8);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0xC);
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x10);
    temp_f3 = *(f32 *)((s8 *)arg0 + 0x14);
    temp_f4 = *(f32 *)((s8 *)arg0 + 0x18);
    temp_f5 = *(f32 *)((s8 *)arg0 + 0x1C);
    temp_f8 = *(f32 *)((s8 *)arg0 + 0x28);
    temp_f9 = *(f32 *)((s8 *)arg0 + 0x2C);
    temp_f10 = *(f32 *)((s8 *)arg0 + 0x38);
    temp_f11 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_f29 = *(f32 *)((s8 *)arg0 + 0x58);
    temp_f28 = *(f32 *)((s8 *)arg0 + 0x5C);
    *(f32 *)((s8 *)arg0 + 8) = *(f32 *)((s8 *)arg0 + 0x40);
    *(f32 *)((s8 *)arg0 + 0xC) = *(f32 *)((s8 *)arg0 + 0x44);
    *(f32 *)((s8 *)arg0 + 0x10) = *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x14) = *(f32 *)((s8 *)arg0 + 0x24);
    *(f32 *)((s8 *)arg0 + 0x18) = *(f32 *)((s8 *)arg0 + 0x60);
    *(f32 *)((s8 *)arg0 + 0x1C) = *(f32 *)((s8 *)arg0 + 0x64);
    *(f32 *)((s8 *)arg0 + 0x20) = temp_f2;
    *(f32 *)((s8 *)arg0 + 0x24) = temp_f3;
    *(f32 *)((s8 *)arg0 + 0x28) = *(f32 *)((s8 *)arg0 + 0x50);
    *(f32 *)((s8 *)arg0 + 0x2C) = *(f32 *)((s8 *)arg0 + 0x54);
    *(f32 *)((s8 *)arg0 + 0x38) = *(f32 *)((s8 *)arg0 + 0x70);
    *(f32 *)((s8 *)arg0 + 0x3C) = *(f32 *)((s8 *)arg0 + 0x74);
    *(f32 *)((s8 *)arg0 + 0x40) = temp_f0;
    *(f32 *)((s8 *)arg0 + 0x44) = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x50) = temp_f8;
    *(f32 *)((s8 *)arg0 + 0x54) = temp_f9;
    *(f32 *)((s8 *)arg0 + 0x58) = *(f32 *)((s8 *)arg0 + 0x68);
    *(f32 *)((s8 *)arg0 + 0x5C) = *(f32 *)((s8 *)arg0 + 0x6C);
    *(f32 *)((s8 *)arg0 + 0x60) = temp_f4;
    *(f32 *)((s8 *)arg0 + 0x64) = temp_f5;
    *(f32 *)((s8 *)arg0 + 0x68) = temp_f29;
    *(f32 *)((s8 *)arg0 + 0x6C) = temp_f28;
    *(f32 *)((s8 *)arg0 + 0x70) = temp_f10;
    *(f32 *)((s8 *)arg0 + 0x74) = temp_f11;
}

void fn_801219B4(void *arg0) {
    f32 a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t;
    a=*(f32*)((char*)arg0+8);
    b=*(f32*)((char*)arg0+0x40);
    c=*(f32*)((char*)arg0+0x78);
    d=*(f32*)((char*)arg0+0xC);
    e=*(f32*)((char*)arg0+0x44);
    f=*(f32*)((char*)arg0+0x7C);
    g=*(f32*)((char*)arg0+0x10);
    h=*(f32*)((char*)arg0+0x38);
    i=*(f32*)((char*)arg0+0x48);
    j=*(f32*)((char*)arg0+0x60);
    k=*(f32*)((char*)arg0+0x68);
    l=*(f32*)((char*)arg0+0x28);
    m=*(f32*)((char*)arg0+0x30);
    n=*(f32*)((char*)arg0+0x50);
    o=*(f32*)((char*)arg0+0x58);
    p=*(f32*)((char*)arg0+0x18);
    q=*(f32*)((char*)arg0+0x20);
    r=*(f32*)((char*)arg0+0x70);
    s=*(f32*)((char*)arg0+0x14);
    t=*(f32*)((char*)arg0+0x3C);
    *(f32*)((char*)arg0+8)=c; *(f32*)((char*)arg0+0xC)=f;
    *(f32*)((char*)arg0+0x10)=h; *(f32*)((char*)arg0+0x14)=t;
    *(f32*)((char*)arg0+0x18)=o; *(f32*)((char*)arg0+0x1C)=*(f32*)((char*)arg0+0x5C);
    *(f32*)((char*)arg0+0x20)=p; *(f32*)((char*)arg0+0x24)=*(f32*)((char*)arg0+0x1C);
    *(f32*)((char*)arg0+0x28)=*(f32*)((char*)arg0+0x68); *(f32*)((char*)arg0+0x2C)=*(f32*)((char*)arg0+0x6C);
    *(f32*)((char*)arg0+0x30)=l; *(f32*)((char*)arg0+0x34)=*(f32*)((char*)arg0+0x2C);
    *(f32*)((char*)arg0+0x38)=i; *(f32*)((char*)arg0+0x3C)=*(f32*)((char*)arg0+0x4C);
    *(f32*)((char*)arg0+0x40)=a; *(f32*)((char*)arg0+0x44)=d;
    *(f32*)((char*)arg0+0x48)=r; *(f32*)((char*)arg0+0x4C)=*(f32*)((char*)arg0+0x74);
    *(f32*)((char*)arg0+0x50)=m; *(f32*)((char*)arg0+0x54)=*(f32*)((char*)arg0+0x34);
    *(f32*)((char*)arg0+0x58)=n; *(f32*)((char*)arg0+0x5C)=*(f32*)((char*)arg0+0x54);
    *(f32*)((char*)arg0+0x60)=g; *(f32*)((char*)arg0+0x64)=s;
    *(f32*)((char*)arg0+0x68)=j; *(f32*)((char*)arg0+0x6C)=*(f32*)((char*)arg0+0x64);
    *(f32*)((char*)arg0+0x70)=q; *(f32*)((char*)arg0+0x74)=*(f32*)((char*)arg0+0x24);
    *(f32*)((char*)arg0+0x78)=b; *(f32*)((char*)arg0+0x7C)=e;
}

void fn_80121BB0(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 a, c, e, g, b, d, f, h;
    a = p[2]; c = p[3]; e = p[6]; g = p[7];
    b = p[8]; d = p[9]; f = p[12]; h = p[13];
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

extern f32 lbl_80561218;
extern f32 lbl_80561230;
void fn_80122518(s32 arg0, u8 *arg1, void *arg2) {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f10;
    f32 temp_f10_10;
    f32 temp_f10_2;
    f32 temp_f10_3;
    f32 temp_f10_4;
    f32 temp_f10_5;
    f32 temp_f10_6;
    f32 temp_f10_7;
    f32 temp_f10_8;
    f32 temp_f10_9;
    f32 temp_f11;
    f32 temp_f11_10;
    f32 temp_f11_11;
    f32 temp_f11_12;
    f32 temp_f11_2;
    f32 temp_f11_3;
    f32 temp_f11_4;
    f32 temp_f11_5;
    f32 temp_f11_6;
    f32 temp_f11_7;
    f32 temp_f11_8;
    f32 temp_f11_9;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f12_7;
    f32 temp_f12_8;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f13_3;
    f32 temp_f13_4;
    f32 temp_f13_5;
    f32 temp_f13_6;
    f32 temp_f13_7;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f15_3;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f16_4;
    f32 temp_f17;
    f32 temp_f17_2;
    f32 temp_f17_3;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f19;
    f32 temp_f19_2;
    f32 temp_f19_3;
    f32 temp_f19_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    f32 temp_f3_7;
    f32 temp_f3_8;
    f32 temp_f3_9;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f5;
    f32 temp_f5_10;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f5_5;
    f32 temp_f5_6;
    f32 temp_f5_7;
    f32 temp_f5_8;
    f32 temp_f5_9;
    f32 temp_f6;
    f32 temp_f6_10;
    f32 temp_f6_11;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f6_5;
    f32 temp_f6_6;
    f32 temp_f6_7;
    f32 temp_f6_8;
    f32 temp_f6_9;
    f32 temp_f7;
    f32 temp_f7_10;
    f32 temp_f7_11;
    f32 temp_f7_12;
    f32 temp_f7_2;
    f32 temp_f7_3;
    f32 temp_f7_4;
    f32 temp_f7_5;
    f32 temp_f7_6;
    f32 temp_f7_7;
    f32 temp_f7_8;
    f32 temp_f7_9;
    f32 temp_f8;
    f32 temp_f8_10;
    f32 temp_f8_11;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 temp_f8_4;
    f32 temp_f8_5;
    f32 temp_f8_6;
    f32 temp_f8_7;
    f32 temp_f8_8;
    f32 temp_f8_9;
    f32 temp_f9;
    f32 temp_f9_10;
    f32 temp_f9_11;
    f32 temp_f9_12;
    f32 temp_f9_13;
    f32 temp_f9_2;
    f32 temp_f9_3;
    f32 temp_f9_4;
    f32 temp_f9_5;
    f32 temp_f9_6;
    f32 temp_f9_7;
    f32 temp_f9_8;
    f32 temp_f9_9;
    f32 var_f24;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r10;
    s32 temp_r10_3;
    s32 temp_r10_4;
    s32 temp_r10_5;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r11_4;
    s32 temp_r11_5;
    s32 temp_r11_6;
    s32 temp_r12;
    s32 temp_r12_3;
    s32 temp_r12_4;
    s32 temp_r26;
    s32 temp_r26_3;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r28_3;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    s32 temp_r31_2;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r8_2;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;
    s32 temp_r9_5;
    s32 temp_r9_7;
    s32 temp_r9_8;
    s32 temp_r9_9;
    s32 var_r3;
    u32 var_ctr;
    void *temp_r10_2;
    void *temp_r11_3;
    void *temp_r12_2;
    void *temp_r26_2;
    void *temp_r28_2;
    void *temp_r9_4;
    void *temp_r9_6;
    u8 *var_r27;
    u8 *var_r5;

    var_r5 = arg2;
    temp_r7 = arg0 >> 3;
    temp_r6 = temp_r7 * 2;
    temp_r10 = arg0 & 0xFFFFFFF8;
    temp_r26 = (arg0 * 2) & 0xFFFFFFF0;
    temp_r9 = temp_r7 * 6;
    temp_f6 = -M2C_FIELD(arg1, f32 *, 4);
    temp_r12 = ((temp_r7 * 4) + 1) * 4;
    temp_r11 = temp_r9 * 4;
    temp_r3 = (temp_r6 + 1) * 4;
    temp_r9_2 = (temp_r9 + 1) * 4;
    temp_f5 = *(arg1 + temp_r12);
    temp_r8 = temp_r7 - 2;
    temp_f7 = M2C_FIELD(arg1, f32 *, 0);
    temp_f0 = *(arg1 + temp_r26);
    temp_f9 = temp_f6 - temp_f5;
    temp_f4 = *(arg1 + temp_r10);
    temp_f3 = *(arg1 + temp_r11);
    temp_f8 = temp_f7 + temp_f0;
    temp_f7_2 = temp_f7 - temp_f0;
    temp_f10 = temp_f4 + temp_f3;
    temp_f2 = *(arg1 + temp_r3);
    temp_f3_2 = temp_f4 - temp_f3;
    temp_f1 = *(arg1 + temp_r9_2);
    sp10 = lbl_80561218;
    temp_f11 = temp_f2 + temp_f1;
    temp_f12 = temp_f2 - temp_f1;
    var_r27 = arg1 + 8;
    spC = lbl_80561230;
    M2C_FIELD(arg1, f32 *, 0) = (f32) (temp_f8 + temp_f10);
    var_f24 = spC;
    M2C_FIELD(arg1, f32 *, 4) = (f32) (temp_f9 - temp_f11);
    temp_f2_2 = temp_f6 + temp_f5;
    *(arg1 + temp_r10) = temp_f8 - temp_f10;
    *(arg1 + temp_r3) = temp_f9 + temp_f11;
    var_r3 = 2;
    *(arg1 + temp_r26) = temp_f7_2 + temp_f12;
    *(arg1 + temp_r12) = temp_f2_2 + temp_f3_2;
    *(arg1 + temp_r11) = temp_f7_2 - temp_f12;
    *(arg1 + temp_r9_2) = temp_f2_2 - temp_f3_2;
    sp8 = lbl_80561218;
    temp_f15 = M2C_FIELD(var_r5, f32 *, 8);
    sp14 = M2C_FIELD(var_r5, f32 *, 4);
    temp_f14 = M2C_FIELD(var_r5, f32 *, 0xC);
    var_ctr = (u32) (temp_r8 + 1) >> 2U;
    if (temp_r8 > 2) {
        do {
            temp_r0 = var_r3 + temp_r6;
            temp_r9_3 = temp_r0 + temp_r6;
            temp_f27 = -M2C_FIELD(var_r27, f32 *, 4);
            temp_r12_2 = arg1 + (temp_r9_3 * 4);
            temp_f25 = M2C_FIELD(var_r27, f32 *, 0);
            temp_r9_4 = arg1 + (temp_r0 * 4);
            temp_r0_2 = (temp_r9_3 + temp_r6) * 4;
            temp_r26_2 = arg1 + temp_r0_2;
            temp_f26 = M2C_FIELD(temp_r12_2, f32 *, 0);
            temp_f31 = -M2C_FIELD(var_r27, f32 *, 0xC);
            temp_f28 = M2C_FIELD(temp_r12_2, f32 *, 4);
            temp_f12_2 = M2C_FIELD(temp_r9_4, f32 *, 0);
            temp_f2_3 = temp_f25 + temp_f26;
            temp_f11_2 = *(arg1 + temp_r0_2);
            temp_f17 = temp_f27 - temp_f28;
            temp_f23 = M2C_FIELD(var_r5, f32 *, 0x1C);
            temp_f3_3 = temp_f12_2 + temp_f11_2;
            temp_f13 = M2C_FIELD(temp_r12_2, f32 *, 0xC);
            temp_f18 = M2C_FIELD(var_r5, f32 *, 0x10);
            temp_f24 = var_f24 - temp_f23;
            temp_f1_2 = temp_f31 - temp_f13;
            temp_f19 = sp10 + temp_f18;
            temp_f20 = M2C_FIELD(var_r5, f32 *, 0x14);
            temp_f22 = M2C_FIELD(var_r5, f32 *, 0x18);
            temp_f13_2 = temp_f31 + temp_f13;
            temp_f21 = spC + temp_f20;
            temp_f10_2 = M2C_FIELD(temp_r9_4, f32 *, 4);
            temp_f9_2 = M2C_FIELD(temp_r26_2, f32 *, 4);
            temp_f11_3 = temp_f12_2 - temp_f11_2;
            temp_f16 = temp_f10_2 + temp_f9_2;
            temp_f29 = M2C_FIELD(var_r27, f32 *, 8);
            temp_f3_4 = sp8 + temp_f22;
            temp_f30 = M2C_FIELD(temp_r12_2, f32 *, 8);
            sp30 = (f64) (temp_f2_3 - temp_f3_3);
            temp_f9_3 = temp_f10_2 - temp_f9_2;
            temp_f8_2 = M2C_FIELD(temp_r9_4, f32 *, 8);
            temp_f0_2 = temp_f29 + temp_f30;
            temp_f7_3 = M2C_FIELD(temp_r26_2, f32 *, 8);
            var_r5 += 0x10;
            temp_f6_2 = M2C_FIELD(temp_r9_4, f32 *, 0xC);
            temp_f5_2 = M2C_FIELD(temp_r26_2, f32 *, 0xC);
            temp_f2_4 = temp_f8_2 + temp_f7_3;
            sp18 = (f64) temp_f3_4;
            temp_f3_5 = temp_f6_2 + temp_f5_2;
            M2C_FIELD(var_r27, f32 *, 0) = (f32) (temp_f2_3 + temp_f3_3);
            temp_f4_2 = temp_f17 - temp_f16;
            sp10 = temp_f18;
            sp38 = (f64) temp_f4_2;
            spC = temp_f20;
            sp20 = (f64) (temp_f0_2 + temp_f2_4);
            sp28 = (f64) (temp_f1_2 - temp_f3_5);
            sp8 = temp_f22;
            M2C_FIELD(var_r27, f32 *, 4) = temp_f4_2;
            M2C_FIELD(var_r27, f32 *, 8) = (f32) sp20;
            temp_f17_2 = temp_f14 * (f32) sp18;
            M2C_FIELD(var_r27, f32 *, 0xC) = (f32) sp28;
            temp_f2_5 = temp_f15 * temp_f19;
            temp_f19_2 = temp_f25 - temp_f26;
            M2C_FIELD(temp_r9_4, f32 *, 0) = (f32) sp30;
            temp_f16_2 = temp_f15 * temp_f21;
            temp_f21_2 = temp_f29 - temp_f30;
            M2C_FIELD(temp_r9_4, f32 *, 4) = (f32) (temp_f17 + temp_f16);
            temp_f4_3 = temp_f14 * temp_f24;
            var_f24 = -temp_f23;
            M2C_FIELD(temp_r9_4, f32 *, 8) = (f32) (temp_f0_2 - temp_f2_4);
            temp_f0_3 = temp_f27 + temp_f28;
            temp_f23_2 = temp_f8_2 - temp_f7_3;
            temp_f25_2 = temp_f6_2 - temp_f5_2;
            temp_f6_3 = temp_f19_2 + temp_f9_3;
            temp_r0_3 = temp_r6 - var_r3;
            temp_f7_4 = temp_f0_3 + temp_f11_3;
            temp_r28 = temp_r0_3 + temp_r6;
            temp_r11_2 = temp_r28 + temp_r6;
            M2C_FIELD(temp_r9_4, f32 *, 0xC) = (f32) (temp_f1_2 + temp_f3_5);
            temp_f8_3 = temp_f21_2 + temp_f25_2;
            temp_r9_5 = (temp_r11_2 + temp_r6) * 4;
            temp_f12_3 = temp_f13_2 + temp_f23_2;
            temp_r0_4 = temp_r28 * 4;
            temp_f11_4 = temp_f0_3 - temp_f11_3;
            temp_r28_2 = arg1 + (temp_r0_3 * 4);
            M2C_FIELD(temp_r12_2, f32 *, 0) = (f32) ((temp_f2_5 * temp_f6_3) - (temp_f16_2 * temp_f7_4));
            temp_f10_3 = temp_f19_2 - temp_f9_3;
            temp_r10_2 = arg1 + (temp_r11_2 * 4);
            temp_r11_3 = arg1 + temp_r0_4;
            M2C_FIELD(temp_r12_2, f32 *, 4) = (f32) ((temp_f2_5 * temp_f7_4) + (temp_f16_2 * temp_f6_3));
            M2C_FIELD(temp_r12_2, f32 *, 8) = (f32) ((temp_f18 * temp_f8_3) - (temp_f20 * temp_f12_3));
            temp_f0_4 = temp_f21_2 - temp_f25_2;
            temp_f1_3 = temp_f13_2 - temp_f23_2;
            M2C_FIELD(temp_r12_2, f32 *, 0xC) = (f32) ((temp_f18 * temp_f12_3) + (temp_f20 * temp_f8_3));
            M2C_FIELD(temp_r26_2, f32 *, 0) = (f32) ((temp_f17_2 * temp_f10_3) + (temp_f4_3 * temp_f11_4));
            M2C_FIELD(temp_r26_2, f32 *, 4) = (f32) ((temp_f17_2 * temp_f11_4) - (temp_f4_3 * temp_f10_3));
            M2C_FIELD(temp_r26_2, f32 *, 8) = (f32) ((temp_f22 * temp_f0_4) + (var_f24 * temp_f1_3));
            M2C_FIELD(temp_r26_2, f32 *, 0xC) = (f32) ((temp_f22 * temp_f1_3) - (var_f24 * temp_f0_4));
            temp_f9_4 = -M2C_FIELD(temp_r28_2, f32 *, 4);
            temp_f5_3 = M2C_FIELD(temp_r10_2, f32 *, 4);
            temp_f12_4 = -M2C_FIELD(temp_r28_2, f32 *, -4);
            temp_f6_4 = M2C_FIELD(temp_r10_2, f32 *, -4);
            temp_f1_4 = M2C_FIELD(temp_r28_2, f32 *, 0);
            temp_f0_5 = M2C_FIELD(temp_r10_2, f32 *, 0);
            temp_f30_2 = temp_f9_4 - temp_f5_3;
            temp_f7_5 = *(temp_r9_5 + arg1);
            temp_r9_6 = temp_r9_5 + arg1;
            temp_f8_4 = *(arg1 + temp_r0_4);
            temp_f10_4 = temp_f12_4 - temp_f6_4;
            temp_f13_3 = M2C_FIELD(temp_r28_2, f32 *, -8);
            temp_f23_3 = temp_f1_4 + temp_f0_5;
            temp_f3_6 = temp_f1_4 - temp_f0_5;
            temp_f11_5 = M2C_FIELD(temp_r10_2, f32 *, -8);
            temp_f5_4 = temp_f9_4 + temp_f5_3;
            temp_f1_5 = M2C_FIELD(temp_r11_3, f32 *, 4);
            temp_f9_5 = temp_f13_3 + temp_f11_5;
            temp_f0_6 = M2C_FIELD(temp_r9_6, f32 *, 4);
            temp_f12_5 = temp_f12_4 + temp_f6_4;
            temp_f31_2 = temp_f8_4 + temp_f7_5;
            temp_f7_6 = temp_f8_4 - temp_f7_5;
            temp_f11_6 = temp_f13_3 - temp_f11_5;
            temp_f6_5 = temp_f1_5 + temp_f0_6;
            temp_f8_5 = temp_f1_5 - temp_f0_6;
            temp_f29_2 = M2C_FIELD(temp_r11_3, f32 *, -8);
            temp_f28_2 = M2C_FIELD(temp_r9_6, f32 *, -8);
            temp_f0_7 = temp_f3_6 + temp_f8_5;
            temp_f27_2 = M2C_FIELD(temp_r11_3, f32 *, -4);
            temp_f1_6 = temp_f5_4 + temp_f7_6;
            temp_f26_2 = M2C_FIELD(temp_r9_6, f32 *, -4);
            temp_f13_4 = temp_f29_2 + temp_f28_2;
            var_r27 += 0x10;
            temp_f19_3 = temp_f27_2 + temp_f26_2;
            M2C_FIELD(temp_r28_2, f32 *, 0) = (f32) (temp_f23_3 + temp_f31_2);
            var_r3 += 4;
            M2C_FIELD(temp_r28_2, f32 *, 4) = (f32) (temp_f30_2 - temp_f6_5);
            M2C_FIELD(temp_r28_2, f32 *, -8) = (f32) (temp_f9_5 + temp_f13_4);
            temp_f6_6 = temp_f29_2 - temp_f28_2;
            M2C_FIELD(temp_r28_2, f32 *, -4) = (f32) (temp_f10_4 - temp_f19_3);
            temp_f26_3 = temp_f27_2 - temp_f26_2;
            M2C_FIELD(temp_r11_3, f32 *, 0) = (f32) (temp_f23_3 - temp_f31_2);
            temp_f3_7 = temp_f3_6 - temp_f8_5;
            M2C_FIELD(temp_r11_3, f32 *, 4) = (f32) (temp_f30_2 + temp_f6_5);
            temp_f7_7 = temp_f5_4 - temp_f7_6;
            M2C_FIELD(temp_r11_3, f32 *, -8) = (f32) (temp_f9_5 - temp_f13_4);
            M2C_FIELD(temp_r11_3, f32 *, -4) = (f32) (temp_f10_4 + temp_f19_3);
            temp_f9_6 = temp_f11_6 + temp_f26_3;
            temp_f1_7 = temp_f11_6 - temp_f26_3;
            M2C_FIELD(temp_r10_2, f32 *, 0) = (f32) ((temp_f16_2 * temp_f0_7) - (temp_f2_5 * temp_f1_6));
            temp_f13_5 = temp_f12_5 + temp_f6_6;
            temp_f5_5 = temp_f12_5 - temp_f6_6;
            M2C_FIELD(temp_r10_2, f32 *, 4) = (f32) ((temp_f16_2 * temp_f1_6) + (temp_f2_5 * temp_f0_7));
            M2C_FIELD(temp_r10_2, f32 *, -8) = (f32) ((temp_f20 * temp_f9_6) - (temp_f18 * temp_f13_5));
            M2C_FIELD(temp_r10_2, f32 *, -4) = (f32) ((temp_f20 * temp_f13_5) + (temp_f18 * temp_f9_6));
            M2C_FIELD(temp_r9_6, f32 *, 0) = (f32) ((temp_f4_3 * temp_f3_7) + (temp_f17_2 * temp_f7_7));
            M2C_FIELD(temp_r9_6, f32 *, 4) = (f32) ((temp_f4_3 * temp_f7_7) - (temp_f17_2 * temp_f3_7));
            M2C_FIELD(temp_r9_6, f32 *, -8) = (f32) ((var_f24 * temp_f1_7) + (temp_f22 * temp_f5_5));
            M2C_FIELD(temp_r9_6, f32 *, -4) = (f32) ((var_f24 * temp_f5_5) - (temp_f22 * temp_f1_7));
            var_ctr -= 1;
        } while (var_ctr != 0);
    }
    temp_r3_2 = temp_r7 * 3;
    temp_r5 = temp_r7 * 5;
    temp_r11_4 = temp_r8 * 4;
    temp_r6_2 = temp_r7 * 7;
    temp_r10_3 = (temp_r7 - 1) * 4;
    temp_r26_3 = (temp_r5 - 2) * 4;
    temp_r29 = (temp_r3_2 - 2) * 4;
    temp_r30 = (temp_r6_2 - 2) * 4;
    temp_r31 = (temp_r5 - 1) * 4;
    temp_r12_3 = (temp_r6_2 - 1) * 4;
    temp_r9_7 = (temp_r3_2 - 1) * 4;
    temp_f7_8 = -*(arg1 + temp_r10_3);
    temp_f6_7 = *(arg1 + temp_r31);
    temp_f9_7 = *(arg1 + temp_r11_4);
    temp_f8_6 = *(arg1 + temp_r26_3);
    temp_f5_6 = *(arg1 + temp_r29);
    temp_f17_3 = temp_f7_8 - temp_f6_7;
    temp_f4_4 = *(arg1 + temp_r30);
    temp_f16_3 = temp_f9_7 + temp_f8_6;
    temp_f3_8 = *(arg1 + temp_r9_7);
    temp_f2_6 = *(arg1 + temp_r12_3);
    temp_f19_4 = temp_f5_6 + temp_f4_4;
    temp_f20_2 = temp_f5_6 - temp_f4_4;
    temp_f0_8 = temp_f3_8 + temp_f2_6;
    temp_r27 = temp_r7 * 0x14;
    temp_f21_3 = temp_f3_8 - temp_f2_6;
    temp_f8_7 = temp_f9_7 - temp_f8_6;
    temp_f18_2 = temp_f7_8 + temp_f6_7;
    temp_r28_3 = (temp_r5 + 1) * 4;
    *(arg1 + temp_r11_4) = temp_f16_3 + temp_f19_4;
    temp_f2_7 = temp_f15 * (spC + sp14);
    temp_r11_5 = temp_r7 * 4;
    temp_f12_6 = temp_f18_2 + temp_f20_2;
    *(arg1 + temp_r10_3) = temp_f17_3 - temp_f0_8;
    temp_f3_9 = temp_f14 * (sp8 - sp14);
    temp_f4_5 = temp_f14 * (var_f24 - sp14);
    temp_r10_4 = (temp_r7 + 1) * 4;
    temp_f1_8 = temp_f15 * (sp10 + sp14);
    *(arg1 + temp_r29) = temp_f16_3 - temp_f19_4;
    temp_f9_8 = temp_f8_7 + temp_f21_3;
    temp_f11_7 = temp_f8_7 - temp_f21_3;
    *(arg1 + temp_r9_7) = temp_f17_3 + temp_f0_8;
    temp_f10_5 = temp_f18_2 - temp_f20_2;
    *(arg1 + temp_r26_3) = (temp_f1_8 * temp_f9_8) - (temp_f2_7 * temp_f12_6);
    *(arg1 + temp_r31) = (temp_f1_8 * temp_f12_6) + (temp_f2_7 * temp_f9_8);
    *(arg1 + temp_r30) = (temp_f3_9 * temp_f11_7) + (temp_f4_5 * temp_f10_5);
    *(arg1 + temp_r12_3) = (temp_f3_9 * temp_f10_5) - (temp_f4_5 * temp_f11_7);
    temp_f11_8 = *(arg1 + temp_r11_5);
    temp_f5_7 = *(arg1 + temp_r27);
    temp_f12_7 = temp_f11_8 + temp_f5_7;
    temp_r29_2 = temp_r7 * 0x1C;
    temp_r30_2 = temp_r7 * 0xC;
    temp_f8_8 = *(arg1 + temp_r30_2);
    temp_f7_9 = *(arg1 + temp_r29_2);
    temp_r9_8 = (temp_r3_2 + 1) * 4;
    temp_r31_2 = (temp_r6_2 + 1) * 4;
    temp_f13_6 = temp_f11_8 - temp_f5_7;
    temp_f10_6 = -*(arg1 + temp_r10_4);
    temp_f9_9 = *(arg1 + temp_r28_3);
    temp_f14_2 = temp_f8_8 + temp_f7_9;
    temp_f6_8 = *(arg1 + temp_r9_8);
    temp_f5_8 = *(arg1 + temp_r31_2);
    temp_f11_9 = temp_f10_6 - temp_f9_9;
    temp_f16_4 = temp_f6_8 - temp_f5_8;
    temp_f5_9 = temp_f6_8 + temp_f5_8;
    *(arg1 + temp_r11_5) = temp_f12_7 + temp_f14_2;
    temp_f10_7 = temp_f10_6 + temp_f9_9;
    temp_f15_2 = temp_f8_8 - temp_f7_9;
    temp_f8_9 = temp_f10_7 + temp_f15_2;
    temp_r12_4 = (temp_r5 + 2) * 4;
    *(arg1 + temp_r10_4) = temp_f11_9 - temp_f5_9;
    temp_f7_10 = temp_f13_6 + temp_f16_4;
    *(arg1 + temp_r30_2) = temp_f12_7 - temp_f14_2;
    temp_f9_10 = temp_f13_6 - temp_f16_4;
    temp_r11_6 = (temp_r7 + 2) * 4;
    *(arg1 + temp_r9_8) = temp_f11_9 + temp_f5_9;
    temp_f10_8 = temp_f10_7 - temp_f15_2;
    temp_r9_9 = (temp_r7 + 3) * 4;
    temp_f6_9 = -sp14;
    temp_r10_5 = (temp_r5 + 3) * 4;
    temp_r8_2 = (temp_r6_2 + 2) * 4;
    *(arg1 + temp_r27) = sp14 * (temp_f7_10 - temp_f8_9);
    temp_r6_3 = (temp_r3_2 + 2) * 4;
    *(arg1 + temp_r28_3) = sp14 * (temp_f8_9 + temp_f7_10);
    temp_r3_3 = (temp_r6_2 + 3) * 4;
    temp_r0_5 = (temp_r3_2 + 3) * 4;
    *(arg1 + temp_r29_2) = temp_f6_9 * (temp_f9_10 + temp_f10_8);
    *(arg1 + temp_r31_2) = temp_f6_9 * (temp_f10_8 - temp_f9_10);
    temp_f11_10 = *(arg1 + temp_r11_6);
    temp_f9_11 = -*(arg1 + temp_r9_9);
    temp_f10_9 = *(arg1 + temp_r12_4);
    temp_f8_10 = *(arg1 + temp_r10_5);
    temp_f12_8 = temp_f11_10 + temp_f10_9;
    temp_f7_11 = *(arg1 + temp_r6_3);
    temp_f13_7 = temp_f9_11 - temp_f8_10;
    temp_f6_10 = *(arg1 + temp_r8_2);
    temp_f8_11 = temp_f9_11 + temp_f8_10;
    temp_f5_10 = *(arg1 + temp_r0_5);
    temp_f0_9 = *(arg1 + temp_r3_3);
    temp_f11_11 = temp_f11_10 - temp_f10_9;
    temp_f9_12 = temp_f7_11 + temp_f6_10;
    temp_f14_3 = temp_f5_10 + temp_f0_9;
    temp_f15_3 = temp_f5_10 - temp_f0_9;
    temp_f7_12 = temp_f7_11 - temp_f6_10;
    temp_f10_10 = temp_f11_11 + temp_f15_3;
    temp_f6_11 = temp_f8_11 + temp_f7_12;
    *(arg1 + temp_r11_6) = temp_f12_8 + temp_f9_12;
    temp_f9_13 = temp_f11_11 - temp_f15_3;
    temp_f11_12 = temp_f8_11 - temp_f7_12;
    *(arg1 + temp_r9_9) = temp_f13_7 - temp_f14_3;
    *(arg1 + temp_r6_3) = temp_f12_8 - temp_f9_12;
    *(arg1 + temp_r0_5) = temp_f13_7 + temp_f14_3;
    *(arg1 + temp_r12_4) = (temp_f2_7 * temp_f10_10) - (temp_f1_8 * temp_f6_11);
    *(arg1 + temp_r10_5) = (temp_f2_7 * temp_f6_11) + (temp_f1_8 * temp_f10_10);
    *(arg1 + temp_r8_2) = (temp_f4_5 * temp_f9_13) + (temp_f3_9 * temp_f11_12);
    *(arg1 + temp_r3_3) = (temp_f4_5 * temp_f11_12) - (temp_f3_9 * temp_f9_13);
}

extern void fn_8012440C(void *, void *);
extern void fn_80124CE8(void *, void *);
void fn_80123DC0(s32 count, void *dst, s32 srcIndex, void *src) {
    void *srcBase = src;
    void *temp_r31;
    void *temp_r30;
    if (count == 0x80) {
        temp_r31 = (u8 *)srcBase + ((srcIndex - 8) * 4);
        fn_80123E98(dst, temp_r31);
        temp_r30 = (u8 *)srcBase + ((srcIndex - 0x20) * 4);
        fn_8012440C((u8 *)dst + 0x80, temp_r30);
        fn_80123E98((u8 *)dst + 0x100, temp_r31);
        fn_8012440C((u8 *)dst + 0x180, temp_r30);
        return;
    } else {
        void *tempElse = (u8 *)srcBase + ((srcIndex - 0x10) * 4);
        fn_80124AD8(dst, tempElse);
        fn_80124CE8((u8 *)dst + 0x40, tempElse);
        fn_80124AD8((u8 *)dst + 0x80, tempElse);
        fn_80124CE8((u8 *)dst + 0xC0, tempElse);
    }
}

void fn_80123E98(void *arg0, void *arg1) {
    f32 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f10_3;
    f32 temp_f10_4;
    f32 temp_f10_5;
    f32 temp_f10_6;
    f32 temp_f11;
    f32 temp_f11_2;
    f32 temp_f11_3;
    f32 temp_f11_4;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f13_3;
    f32 temp_f13_4;
    f32 temp_f13_5;
    f32 temp_f13_6;
    f32 temp_f13_7;
    f32 temp_f13_8;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f15_3;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f16_4;
    f32 temp_f17;
    f32 temp_f17_2;
    f32 temp_f17_3;
    f32 temp_f17_4;
    f32 temp_f17_5;
    f32 temp_f17_6;
    f32 temp_f18;
    f32 temp_f19;
    f32 temp_f19_2;
    f32 temp_f19_3;
    f32 temp_f19_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f21_4;
    f32 temp_f21_5;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f23_4;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f25_3;
    f32 temp_f25_4;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f26_4;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f28_3;
    f32 temp_f28_4;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f29_3;
    f32 temp_f29_4;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f30_3;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f5_5;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f6_5;
    f32 temp_f6_6;
    f32 temp_f6_7;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 temp_f7_3;
    f32 temp_f7_4;
    f32 temp_f8;
    f32 temp_f8_10;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 temp_f8_4;
    f32 temp_f8_5;
    f32 temp_f8_6;
    f32 temp_f8_7;
    f32 temp_f8_8;
    f32 temp_f8_9;
    f32 temp_f9;
    f32 temp_f9_2;
    f32 temp_f9_3;
    f32 temp_f9_4;
    f32 temp_f9_5;
    f32 temp_f9_6;
    f32 temp_f9_7;
    f32 temp_f9_8;

    temp_f18 = (*(f32 *)((s8 *)arg1 + 4));
    temp_f1 = (*(f32 *)((s8 *)arg1 + 8));
    temp_f3 = (*(f32 *)((s8 *)arg0 + 8));
    temp_f16 = temp_f18 * temp_f1;
    temp_f0 = (*(f32 *)((s8 *)arg0 + 0x48));
    temp_f21 = (*(f32 *)((s8 *)arg0 + 0xC));
    temp_f10 = (*(f32 *)((s8 *)arg0 + 0x4C));
    temp_f4 = temp_f3 - temp_f0;
    temp_f17 = temp_f16 + temp_f1;
    temp_f5 = temp_f21 - temp_f10;
    temp_f2 = (*(f32 *)((s8 *)arg0 + 0x28));
    temp_f1_2 = (*(f32 *)((s8 *)arg0 + 0x68));
    temp_f22 = temp_f3 + temp_f0;
    temp_f19 = (*(f32 *)((s8 *)arg0 + 0x2C));
    temp_f6 = temp_f2 - temp_f1_2;
    temp_f9 = (*(f32 *)((s8 *)arg0 + 0x6C));
    temp_f21_2 = temp_f21 + temp_f10;
    temp_f14 = (*(f32 *)((s8 *)arg0 + 0));
    temp_f20 = temp_f2 + temp_f1_2;
    temp_f0_2 = temp_f19 - temp_f9;
    temp_f8 = temp_f5 + temp_f6;
    temp_f13 = (*(f32 *)((s8 *)arg0 + 0x40));
    temp_f29 = temp_f5 - temp_f6;
    temp_f23 = (*(f32 *)((s8 *)arg0 + 4));
    temp_f7 = temp_f4 - temp_f0_2;
    temp_f0_3 = temp_f4 + temp_f0_2;
    temp_f15 = (*(f32 *)((s8 *)arg0 + 0x44));
    temp_f1_3 = temp_f14 + temp_f13;
    temp_f14_2 = temp_f14 - temp_f13;
    temp_f12 = (*(f32 *)((s8 *)arg0 + 0x20));
    temp_f11 = (*(f32 *)((s8 *)arg0 + 0x60));
    temp_f19_2 = temp_f19 + temp_f9;
    temp_f6_2 = (*(f32 *)((s8 *)arg0 + 0x24));
    temp_f5_2 = (*(f32 *)((s8 *)arg0 + 0x64));
    temp_f31 = (*(f32 *)((s8 *)arg0 + 0x10));
    temp_f2_2 = temp_f6_2 + temp_f5_2;
    temp_f5_3 = temp_f6_2 - temp_f5_2;
    temp_f13_2 = (*(f32 *)((s8 *)arg0 + 0x50));
    temp_f3_2 = temp_f23 + temp_f15;
    temp_f6_3 = temp_f23 - temp_f15;
    temp_f10_2 = (*(f32 *)((s8 *)arg0 + 0x30));
    temp_f4_2 = temp_f12 + temp_f11;
    temp_f15_2 = temp_f12 - temp_f11;
    temp_f12_2 = (*(f32 *)((s8 *)arg0 + 0x14));
    temp_f11_2 = (*(f32 *)((s8 *)arg0 + 0x54));
    temp_f9_2 = (*(f32 *)((s8 *)arg0 + 0x70));
    temp_f8_2 = (*(f32 *)((s8 *)arg0 + 0x34));
    temp_f1_4 = temp_f1_3 - temp_f4_2;
    temp_f7_2 = (*(f32 *)((s8 *)arg0 + 0x74));
    temp_f4_3 = temp_f6_3 + temp_f15_2;
    temp_f6_4 = temp_f6_3 - temp_f15_2;
    sp8 = temp_f1_3 + temp_f4_2;
    temp_f15_3 = temp_f22 + temp_f20;
    temp_f20_2 = temp_f22 - temp_f20;
    temp_f22_2 = (temp_f17 * temp_f8) + (temp_f16 * temp_f7);
    temp_f0_4 = temp_f3_2 + temp_f2_2;
    temp_f2_3 = temp_f3_2 - temp_f2_2;
    sp10 = temp_f31 + temp_f13_2;
    temp_f3_3 = temp_f14_2 - temp_f5_3;
    temp_f5_4 = temp_f14_2 + temp_f5_3;
    temp_f14_3 = temp_f21_2 + temp_f19_2;
    spC = temp_f12_2 + temp_f11_2;
    temp_f25 = temp_f12_2 - temp_f11_2;
    temp_f19_3 = temp_f21_2 - temp_f19_2;
    temp_f21_3 = (temp_f17 * temp_f7) - (temp_f16 * temp_f8);
    temp_f23_2 = (temp_f16 * temp_f0_3) - (temp_f17 * temp_f29);
    temp_f13_3 = temp_f31 - temp_f13_2;
    temp_f24 = (temp_f16 * temp_f29) + (temp_f17 * temp_f0_3);
    temp_f11_3 = temp_f10_2 + temp_f9_2;
    temp_f12_3 = temp_f8_2 + temp_f7_2;
    temp_f30 = temp_f8_2 - temp_f7_2;
    temp_f8_3 = (*(f32 *)((s8 *)arg0 + 0x5C));
    temp_f9_3 = temp_f10_2 - temp_f9_2;
    temp_f26 = (*(f32 *)((s8 *)arg0 + 0x18));
    sp20 = (f64) (*(f32 *)((s8 *)arg0 + 0x58));
    sp30 = (f64) temp_f8_3;
    sp28 = (f64) (*(f32 *)((s8 *)arg0 + 0x1C));
    sp38 = (f64) (*(f32 *)((s8 *)arg0 + 0x38));
    temp_f7_3 = sp10 + temp_f11_3;
    sp18 = (f64) temp_f26;
    temp_f26_2 = temp_f26 - (f32) sp20;
    temp_f8_4 = (*(f32 *)((s8 *)arg0 + 0x78));
    sp40 = (f64) temp_f8_4;
    temp_f28 = (f32) sp28 - temp_f8_3;
    sp48 = (f64) (*(f32 *)((s8 *)arg0 + 0x3C));
    temp_f13_4 = temp_f13_3 + temp_f30;
    temp_f30_2 = temp_f25 - temp_f9_3;
    sp58 = temp_f13_3 - temp_f30;
    temp_f8_5 = (*(f32 *)((s8 *)arg0 + 0x7C));
    sp50 = (f64) temp_f8_5;
    temp_f29_2 = (f32) sp38 - temp_f8_4;
    temp_f31_2 = (f32) sp48 - temp_f8_5;
    temp_f8_6 = temp_f25 + temp_f9_3;
    temp_f10_3 = temp_f28 + temp_f29_2;
    temp_f28_2 = temp_f28 - temp_f29_2;
    sp14 = temp_f26_2 - temp_f31_2;
    temp_f27 = temp_f26_2 + temp_f31_2;
    temp_f25_2 = temp_f18 * (temp_f13_4 + temp_f30_2);
    temp_f8_7 = temp_f18 * (sp58 - temp_f8_6);
    temp_f9_4 = temp_f18 * (temp_f8_6 + sp58);
    temp_f26_3 = temp_f18 * (temp_f30_2 - temp_f13_4);
    temp_f10_4 = (temp_f16 * sp14) - (temp_f17 * temp_f10_3);
    temp_f13_5 = (temp_f16 * temp_f10_3) + (temp_f17 * sp14);
    temp_f16_2 = temp_f5_4 - temp_f25_2;
    temp_f30_3 = (temp_f17 * temp_f27) - (temp_f16 * temp_f28_2);
    temp_f31_3 = (temp_f17 * temp_f28_2) + (temp_f16 * temp_f27);
    temp_f28_3 = temp_f6_4 - temp_f26_3;
    temp_f17_2 = temp_f23_2 - temp_f30_3;
    temp_f29_3 = temp_f24 - temp_f31_3;
    temp_f25_3 = temp_f5_4 + temp_f25_2;
    temp_f24_2 = temp_f24 + temp_f31_3;
    (*(f32 *)((s8 *)arg0 + 0x60)) = (f32) (temp_f16_2 + temp_f17_2);
    (*(f32 *)((s8 *)arg0 + 0x64)) = (f32) (temp_f28_3 + temp_f29_3);
    temp_f17_3 = temp_f6_4 + temp_f26_3;
    (*(f32 *)((s8 *)arg0 + 0x68)) = (f32) (temp_f16_2 - temp_f17_2);
    temp_f23_3 = temp_f23_2 + temp_f30_3;
    (*(f32 *)((s8 *)arg0 + 0x6C)) = (f32) (temp_f28_3 - temp_f29_3);
    temp_f25_4 = temp_f22_2 + temp_f13_5;
    (*(f32 *)((s8 *)arg0 + 0x70)) = (f32) (temp_f25_3 - temp_f24_2);
    temp_f5_5 = temp_f3_3 + temp_f8_7;
    (*(f32 *)((s8 *)arg0 + 0x78)) = (f32) (temp_f25_3 + temp_f24_2);
    temp_f23_4 = temp_f21_3 + temp_f10_4;
    (*(f32 *)((s8 *)arg0 + 0x74)) = (f32) (temp_f17_3 + temp_f23_3);
    temp_f16_3 = temp_f4_3 + temp_f9_4;
    (*(f32 *)((s8 *)arg0 + 0x7C)) = (f32) (temp_f17_3 - temp_f23_3);
    temp_f6_5 = (f32) sp18 + (f32) sp20;
    temp_f24_3 = (f32) sp38 + (f32) sp40;
    (*(f32 *)((s8 *)arg0 + 0x40)) = (f32) (temp_f5_5 + temp_f23_4);
    temp_f3_4 = temp_f3_3 - temp_f8_7;
    (*(f32 *)((s8 *)arg0 + 0x44)) = (f32) (temp_f16_3 + temp_f25_4);
    temp_f17_4 = (f32) sp28 + (f32) sp30;
    temp_f4_4 = temp_f4_3 - temp_f9_4;
    temp_f26_4 = (f32) sp48 + (f32) sp50;
    temp_f28_4 = sp10 - temp_f11_3;
    temp_f27_2 = spC + temp_f12_3;
    temp_f29_4 = spC - temp_f12_3;
    temp_f11_4 = temp_f6_5 + temp_f24_3;
    temp_f12_4 = temp_f17_4 + temp_f26_4;
    temp_f6_6 = temp_f6_5 - temp_f24_3;
    temp_f17_5 = temp_f17_4 - temp_f26_4;
    temp_f8_8 = temp_f21_3 - temp_f10_4;
    temp_f9_5 = temp_f22_2 - temp_f13_5;
    temp_f21_4 = temp_f19_3 + temp_f6_6;
    temp_f13_6 = temp_f20_2 - temp_f17_5;
    temp_f10_5 = temp_f20_2 + temp_f17_5;
    temp_f19_4 = temp_f19_3 - temp_f6_6;
    temp_f21_5 = temp_f18 * (temp_f13_6 - temp_f21_4);
    (*(f32 *)((s8 *)arg0 + 0x4C)) = (f32) (temp_f16_3 - temp_f25_4);
    (*(f32 *)((s8 *)arg0 + 0x48)) = (f32) (temp_f5_5 - temp_f23_4);
    temp_f20_3 = temp_f1_4 - temp_f29_4;
    (*(f32 *)((s8 *)arg0 + 0x50)) = (f32) (temp_f3_4 - temp_f9_5);
    temp_f17_6 = temp_f18 * (temp_f21_4 + temp_f13_6);
    (*(f32 *)((s8 *)arg0 + 0x54)) = (f32) (temp_f4_4 + temp_f8_8);
    temp_f9_6 = temp_f2_3 + temp_f28_4;
    temp_f16_4 = temp_f18 * (temp_f10_5 - temp_f19_4);
    temp_f13_7 = temp_f2_3 - temp_f28_4;
    (*(f32 *)((s8 *)arg0 + 0x58)) = (f32) (temp_f3_4 + temp_f9_5);
    (*(f32 *)((s8 *)arg0 + 0x5C)) = (f32) (temp_f4_4 - temp_f8_8);
    (*(f32 *)((s8 *)arg0 + 0x20)) = (f32) (temp_f20_3 + temp_f21_5);
    temp_f13_8 = temp_f18 * (temp_f19_4 + temp_f10_5);
    (*(f32 *)((s8 *)arg0 + 0x24)) = (f32) (temp_f9_6 + temp_f17_6);
    temp_f9_7 = temp_f1_4 + temp_f29_4;
    temp_f10_6 = temp_f15_3 + temp_f11_4;
    temp_f8_9 = sp8 + temp_f7_3;
    (*(f32 *)((s8 *)arg0 + 0x2C)) = (f32) (temp_f9_6 - temp_f17_6);
    (*(f32 *)((s8 *)arg0 + 0x28)) = (f32) (temp_f20_3 - temp_f21_5);
    (*(f32 *)((s8 *)arg0 + 0x30)) = (f32) (temp_f9_7 - temp_f13_8);
    temp_f8_10 = temp_f0_4 + temp_f27_2;
    (*(f32 *)((s8 *)arg0 + 0)) = (f32) (temp_f8_9 + temp_f10_6);
    temp_f1_5 = sp8 - temp_f7_3;
    temp_f9_8 = temp_f14_3 + temp_f12_4;
    (*(f32 *)((s8 *)arg0 + 0x34)) = (f32) (temp_f13_7 + temp_f16_4);
    temp_f7_4 = temp_f14_3 - temp_f12_4;
    (*(f32 *)((s8 *)arg0 + 0x38)) = (f32) (temp_f9_7 + temp_f13_8);
    temp_f0_5 = temp_f0_4 - temp_f27_2;
    (*(f32 *)((s8 *)arg0 + 0x3C)) = (f32) (temp_f13_7 - temp_f16_4);
    (*(f32 *)((s8 *)arg0 + 8)) = (f32) (temp_f8_9 - temp_f10_6);
    temp_f6_7 = temp_f15_3 - temp_f11_4;
    (*(f32 *)((s8 *)arg0 + 4)) = (f32) (temp_f8_10 + temp_f9_8);
    (*(f32 *)((s8 *)arg0 + 0xC)) = (f32) (temp_f8_10 - temp_f9_8);
    (*(f32 *)((s8 *)arg0 + 0x10)) = (f32) (temp_f1_5 - temp_f7_4);
    (*(f32 *)((s8 *)arg0 + 0x14)) = (f32) (temp_f0_5 + temp_f6_7);
    (*(f32 *)((s8 *)arg0 + 0x18)) = (f32) (temp_f1_5 + temp_f7_4);
    (*(f32 *)((s8 *)arg0 + 0x1C)) = (f32) (temp_f0_5 - temp_f6_7);
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

#pragma dont_inline on
void fn_80127440(void* alarm) {
    fn_80127F94(fn_802ECC74(alarm));
}
#pragma dont_inline reset

void fn_80127464(void *alarm) {
    fn_80127440(alarm);
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
