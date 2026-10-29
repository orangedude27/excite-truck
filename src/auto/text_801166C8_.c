// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_8012440C(void *, void *);
extern void fn_80124CE8(void *, void *);
extern f64 cos(f64);
extern f64 sin(f64);
extern f32 lbl_80561210;
extern f32 lbl_80561214;
extern f32 lbl_80561218;
extern f32 lbl_8056121C;
extern f32 lbl_80561220;
extern f32 lbl_80561224;
extern f64 lbl_80561228;
extern f32 lbl_80329BC8[];
extern s32 lbl_8055DEE0;
extern s32 lbl_8055DEE8;
extern void TRKGetFreeBuffer(void *);

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
void fn_8011C120();
extern s32 fn_80119300(void *, s32, s32);
void fn_8011C274(s32, void *);
void fn_8011C2EC(s32, void *);
void fn_801195D8();
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
extern u32 lbl_80559950;
extern void *lbl_8055DEF0;
extern u32 lbl_8055DEF4;
extern void **lbl_80559948;
extern u32 *lbl_8055994C;
extern u32 lbl_80329DA8[];
extern u8 lbl_802F6990[];

extern char lbl_80559930;
extern char lbl_80329B28[];
extern void OSPanic(const char *, s32, const char *, ...);
BOOL ARCInitHandle(void *bin, ARCHandle *handle) {
    u32 magic = *(u32 *)bin;
    u8 *base = (u8 *)bin;
    u32 entries;
    u8 *fst;

    if (magic != 0x55AA382D) {
        OSPanic((const char *)&lbl_80559930, 0x47, lbl_80329B28);
    }
    handle->archiveStartAddr = bin;
    fst = base + *(u32 *)(base + 4);
    handle->FSTStart = fst;
    handle->fileStart = base + *(u32 *)(base + 0xC);
    entries = *(u32 *)(fst + 8);
    handle->entryNum = entries;
    handle->FSTStringStart = (char *)(fst + entries * 0xC);
    handle->FSTLength = *(u32 *)(base + 8);
    handle->currDir = 0;
    return TRUE;
}

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

extern u8 lbl_802FE850[];
s32 ARCConvertPathToEntrynum(ARCHandle *handle, const char *path) {
    u32 *fst = (u32 *)handle->FSTStart;
    u32 entry = handle->currDir;
    u32 parent;
    u32 node;
    const char *name;
    const char *p;
    char *entryName;
    u8 *arc = *(u8 **)(lbl_802FE850 + 0x38);
    u8 *caseTable = *(u8 **)(arc + 0x10);
    while (*path != 0) {
        if (*path == '/') { entry = 0; path++; continue; }
        if (*path == '.' && path[1] == '.' && path[2] == '/') {
            path += 3; entry = fst[entry * 3 + 1]; continue;
        }
        if (*path == '.' && path[1] == '/') { path += 2; continue; }
        name = path;
        while (*path != 0 && *path != '/') path++;
        parent = entry;
        entry = parent + 1;
        while (entry < fst[parent * 3 + 2]) {
            node = fst[entry * 3];
            if ((node & 0xFF000000) == 0) { entry = fst[entry * 3 + 2]; continue; }
            entryName = handle->FSTStringStart + (node & 0xFFFFFF);
            p = name;
            while (*entryName != 0) {
                u8 a = *entryName++;
                u8 b = *p++;
                if (a >= 0x80 || b >= 0x80) { if (a != b) break; }
                else if (caseTable[a] != caseTable[b]) break;
            }
            if (*entryName == 0 && (*p == '/' || *p == 0)) break;
            entry++;
        }
        if (entry >= fst[parent * 3 + 2]) return -1;
        if (*path == 0) return entry;
        path++;
    }
    return entry;
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

BOOL ARCChangeDir(ARCHandle *handle, const char *path) {
    s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    u32 *fst = (u32 *)handle->FSTStart;
    if (entrynum < 0 || !(fst[entrynum * 3] & 0xFF000000)) {
        return FALSE;
    }
    handle->currDir = entrynum;
    return TRUE;
}

BOOL ARCOpenDir(ARCHandle* handle, const char* path, ARCDir* dir) {
    register s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    void* fst = handle->FSTStart;
    
    if (entrynum < 0 || !(*(u32*)((u8*)fst + entrynum * 0xC) & 0xFF000000)) {
        return FALSE;
    }
    
    dir->handle = handle;
    dir->location = entrynum + 1;
    dir->entryNum = entrynum;
    dir->next = *(u32*)((u8*)fst + entrynum * (unsigned)0xC + 8);
    return TRUE;
}

BOOL ARCReadDir(ARCDir *dir, ARCDirEntry *entry) {
    typedef struct ARCNode {
        union {
            struct {
                u32 is_folder : 8;
                u32 name : 24;
            };
            u32 packed_type_name;
        };
        union {
            struct {
                u32 offset;
                u32 size;
            } file;
            struct {
                u32 parent;
                u32 sibling_next;
            } folder;
        };
    } ARCNode;
    u32 it;
    ARCNode *nodes;
    ARCHandle *handle = dir->handle;
    u32 next;

    nodes = (ARCNode *)handle->FSTStart;
    it = dir->location;
    while (1) {
        if (it <= dir->entryNum || dir->next <= it) {
            return FALSE;
        }
        entry->handle = handle;
        entry->entryNum = it;
        entry->isDir = (nodes[it].packed_type_name & 0xFF000000) ? TRUE : FALSE;
        entry->name = handle->FSTStringStart + (nodes[it].packed_type_name & 0x00FFFFFF);
        if (entry->name[0] == '.' && entry->name[1] == '\0') {
            ++it;
            continue;
        }
        if (nodes[it].packed_type_name & 0xFF000000) {
            next = nodes[it].folder.sibling_next;
        } else {
            next = it + 1;
        }
        dir->location = next;
        return TRUE;
    }
}

u32 fn_80116BCC(void) {
    return 1;
}

u32 fn_80116BD4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r8;
    u32 temp_r10;
    u32 temp_r9_2;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r5;
    u32 temp_r5_2;
    u32 temp_r6;
    u32 temp_r7;
    u32 temp_r8_2;
    u32 temp_r8_3;
    u32 temp_r9;
    u32 var_r3;
    u32 var_r4;
    u32 var_r7;

    temp_r8 = (s32)(((u64)(u32)arg0 * (u32)arg1) >> 32);
    temp_r9 = (u32)arg0 * (u32)arg1;
    if ((((u32)arg2 & ((u32)arg2 - 1)) == 0)) {
        temp_r4 = __cntlzw((u32)arg2);
        return ((u32)temp_r8 << (temp_r4 + 1)) | (temp_r9 >> (0x1F - temp_r4));
    }
    if (temp_r8 == 0) {
        return temp_r9 / (u32)arg2;
    }
    temp_r4_2 = __cntlzw((u32)arg2);
    temp_r10 = (u32)arg2 << temp_r4_2;
    temp_r3 = temp_r8 << temp_r4_2;
    temp_r0 = temp_r9 >> (0x20 - temp_r4_2);
    temp_r9_2 = temp_r9 << temp_r4_2;
    temp_r8 = temp_r3 + temp_r0;
    temp_r5 = temp_r10 >> 16;
    temp_r6 = temp_r10 & 0xFFFF;
    var_r4 = (u32)temp_r8 / temp_r5;
    temp_r0_2 = var_r4 * temp_r5;
    var_r7 = ((temp_r9_2 >> 16) & 0xFFFF) | ((((u32)temp_r8 - temp_r0_2) & 0xFFFF) << 16);
    temp_r0 = var_r4 * temp_r6;
    if (var_r7 < temp_r0) {
        var_r7 += temp_r10;
        var_r4 -= 1;
        if ((var_r7 >= temp_r10) && (var_r7 < temp_r0)) {
            var_r7 += temp_r10;
            var_r4 -= 1;
        }
    }
    temp_r7 = var_r7 - temp_r0;
    var_r3 = temp_r7 / temp_r5;
    temp_r8_2 = temp_r7 - var_r3 * temp_r5;
    temp_r5_2 = var_r3 * temp_r6;
    temp_r8_3 = (temp_r9_2 & 0xFFFF) | ((temp_r8_2 & 0xFFFF) << 16);
    if (temp_r8_3 < temp_r5_2) {
        temp_r8_3 += temp_r10;
        var_r3 -= 1;
        if ((temp_r8_3 >= temp_r10) && (temp_r8_3 < temp_r5_2)) {
            var_r3 -= 1;
        }
    }
    return (var_r4 << 16) | var_r3;
}

void fn_80116CC4(s32* arg0, u16 arg1, u32 arg2) {
    s32* ptr;
    s32 fill;
    u32 blocks;
    u32 count;
    u32 words;
    ptr = arg0;
    words = arg2 >> 1;
    fill = (arg1 & ~0xFFFF0000) | (arg1 << 16);
    if (words != 0) {
        blocks = words >> 3;
        count = blocks;
        if (blocks != 0) {
            do {
                ptr[0] = fill;
                ptr[1] = fill;
                ptr[2] = fill;
                ptr[3] = fill;
                ptr[4] = fill;
                ptr[5] = fill;
                ptr[6] = fill;
                ptr[7] = fill;
                ptr += 8;
                count -= 1;
            } while (count != 0);
            words &= 7;
            if (words != 0)
                goto tail;
        } else {
tail:
            count = words;
            do {
                *ptr = fill;
                ptr += 1;
                count -= 1;
            } while (count != 0);
        }
    }
    if (arg2 & 1)
        *(s16*)ptr = arg1;
}

extern s64 OSGetTime(void);
extern s32 lbl_8055DEC0;
extern u32 lbl_8055DEC4;
#pragma dont_inline on
s32 fn_80116D30(void) {
    u64 time = (u64)OSGetTime();
    u32 saved_low;
    u32 saved_high;
    u64 delta;
    u32 quotient;
    u64 remainder;

    if (lbl_8055DEC0 | lbl_8055DEC4) {
    } else {
        lbl_8055DEC4 = (u32)time;
        lbl_8055DEC0 = (u32)(time >> 32);
    }
    saved_low = *(volatile u32 *)&lbl_8055DEC4;
    saved_high = *(volatile u32 *)&lbl_8055DEC0;
    delta = time - (((u64)saved_high << 32) | saved_low);
    quotient = (u32)(delta >> 32) * 70699U;
    remainder = delta - ((u64)quotient * 60750U);
    return (s32)(quotient + (u32)((remainder * 0x8A15866BULL) >> 47));
}

extern void* fn_8011FF24(void);
extern void *fn_8011FF2C(s32);
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

void fn_80117380(void *arg0, s32 arg1) {
    s32 var_r31;
    s32 temp_r3;
    s32 *p;
    s32 temp_r5;
    u32 offset0;
    u32 offset1;
    s32 a;
    s32 b;
    s32 (*fn)(void *, s32, s32, s32, s32);
    var_r31 = arg1;
    if (arg1 != 0) var_r31 = arg1 - 1;
    *(s32 *)((u8 *)arg0 + 0x2F8) = 0;
    if (*(s32 *)((u8 *)arg0 + 0x2E8) != 0) fn_80117074(arg0);
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 0xC);
    if (var_r31 == 0) {
        temp_r3 = fn_80116D30();
        if (*(s32 *)((u8 *)arg0 + 0x2D8) == 0) *(s32 *)((u8 *)arg0 + 0x2D8) = temp_r3;
        if ((u32)(temp_r3 - *(u32 *)((u8 *)arg0 + 0x2D8)) > 0x493E0U) {
            *(s32 *)((u8 *)arg0 + 0x2D8) = temp_r3;
            *(s32 *)((u8 *)arg0 + 0x2DC) = 1;
        }
    }
    temp_r5 = *(s32 *)((u8 *)arg0 + 0xE8);
    if (temp_r5 != 0) {
        p = *(s32 **)((u8 *)arg0 + 0xEC);
        *(s32 *)((u8 *)arg0 + 0xE4) = temp_r5 + ((p[var_r31] & ~1) - (p[0] & ~1));
    } else {
        p = *(s32 **)((u8 *)arg0 + 0xEC);
        offset0 = var_r31 << 2;
        offset1 = (var_r31 + 1) << 2;
        a = *(s32 *)((u8 *)p + offset0) & ~1;
        b = *(s32 *)((u8 *)p + offset1) & ~1;
        fn = *(s32 (**)(void *, s32, s32, s32, s32))((u8 *)arg0 + 0xF4);
        fn((u8 *)arg0 + 0xF0, var_r31, a, *(s32 *)((u8 *)arg0 + 0xE4), b - a);
    }
    if (*(s32 *)((u8 *)arg0 + 0x2E8) != 0) fn_80117074(arg0);
    *(s32 *)((u8 *)arg0 + 0xC) = var_r31 + 1;
}

u32 fn_80116BD4(s32, s32, s32);
u32 fn_801174B0(s32 count, u32 *values, s32 offset, s32 *outIndex, s32 *outFlag) {
    s32 byteOffset;
    u32 *base;
    s32 i;
    u32 *value;
    u32 diff;
    u32 maxDiff;
    s32 index;
    s32 allOdd;

    maxDiff = 0;
    index = 0;
    allOdd = 1;
    value = values;
    base = values + offset;
    byteOffset = 0;
    for (i = 0; i < count - offset; i++) {
        diff = base[byteOffset / 4] - *value;
        if (diff > maxDiff) {
            maxDiff = diff;
            index = i;
        }
        value++;
        byteOffset += 4;
    }
    if (maxDiff == 0) {
        maxDiff = fn_80116BD4(values[count] - values[0], offset, count);
    }
    for (i = 0; i < count; i++) {
        if ((values[i] & 1) == 0) {
            allOdd = 0;
            break;
        }
    }
    *outFlag = allOdd;
    *outIndex = index;
    return maxDiff;
}

s32 fn_80117598(s32 arg0, s32 arg1) {
    u8* base;
    u8* end;
    s32 offset;
    s32 value;
    s32 difference;
    s32 sign;
    base = (u8*)arg0;
    end = base + 0x340;
    offset = (s32)end - (s32)base;
    base = (u8*)((s32)base - offset);
    value = *(s32*)(base + 0x33C);
    difference = (value - arg1) | (arg1 - value);
    sign = difference >> 31;
    return (-1 - value) & sign;
}

void fn_801175C4(s32 arg0, s32 arg1) {
    register s32 off;
    register s32 base;
    off = arg0 + 0x340;
    off -= arg0;
    base = arg0 - off;
    if (*(s32 *)(base + 0x2E8) != 0) {
        fn_80117074((void *)base);
    }
    *(s32 *)(base + 0x33C) = arg1;
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

extern u32 lbl_80559944;
extern u32 lbl_8041D608[0x100];
#define lbl_8041D608 lbl_8041D608[0]
extern u32 lbl_8055DED8;
extern u8 lbl_802F6528[];
extern void fn_8011FE20(u32 **, u32);
extern void fn_8011DFAC(void *, u32);
extern void memset(void *, int, unsigned int);
extern s32 fn_8011ACC4(void *, void *, s32);
extern s32 lbl_80559938;
extern s32 lbl_8055993C;
extern s32 lbl_80559940;
extern u32 lbl_8055DEDC;
extern s32 lbl_8055DED4;
extern void *fn_8011B584(u32, s32, s32, s32);
extern void *fn_8011BE48(s32);
extern void fn_8011BEC8(void *, void *, s32, s32);
s32 *fn_8011770C(void *arg0, s32 arg1) {
    struct {
        u8 header[0x2C];
        u8 headPad[4];
        u8 metadata[0x78];
        u8 state[0x388];
    } local;
    u32 magic;
    u32 mode;
    u32 width;
    u32 height;
    u32 count;
    u32 roundedHeight;
    u32 blockBytes;
    register void *allocated;
    u32 activeFlags;
    u32 format;
    s32 *result;
    register s32 (*openStream)(void *, void *, s32) = fn_8011ACC4;
    if (!(arg1 & 0x4000)) {
        lbl_80559944 = 1;
        *(volatile u32 *)&lbl_8041D608 = 0;
        memset(local.state, 0, 0x388);
        *(s32 *)(local.state + 0x2A0) = fn_80116D30();
    }
    lbl_8041D508[0] = 0;
    if (arg1 & 0x04000000) {
        memcpy(local.header, arg0, 0x2C);
    } else {
        if ((arg1 & 0x02000000) && lbl_8055DED8 != 0)
            openStream = (s32 (*)(void *, void *, s32))lbl_8055DED8;
        lbl_8055DED8 = 0;
        if (openStream(local.state + 0xF0, arg0, arg1) == 0) {
            if ((s8)lbl_8041D508[0] == 0)
                fn_80116E2C(lbl_802F6528);
            return 0;
        }
        ((s32 (*)(void *, s32, void *, s32))*(void **)(local.state + 0xF0))(
            local.state + 0xF0, 0, local.header, 0x2C);
    }
    magic = *(u32 *)local.header;
    if (magic == 0x664B4942 || magic == 0x674B4942 || magic == 0x684B4942 || magic == 0x694B4942) {
        if (*(s32 *)(local.state + 0x110) != 0) {
            fn_80116E2C((const u8 *)(lbl_802F6528 + 0x14));
            if ((arg1 & 0x04000000) == 0) {
                s32 (*close)(void *) = *(s32 (**)(void *))(local.state + 0x104);
                if (close != 0) close(local.state + 0xF0);
            }
            return 0;
        }
    } else if (*(s32 *)(local.header + 8) == 0) {
        fn_80116E2C((const u8 *)(lbl_802F6528 + 0x25));
    }
    width = *(u32 *)(local.header + 0x14);
    height = *(u32 *)(local.header + 0x18);
    format = *(u32 *)(local.header + 0x24);
    *(volatile u32 *)(local.state + 0) = width;
    *(volatile u32 *)(local.state + 4) = height;
    *(volatile u32 *)(local.state + 0x23C) = width;
    *(volatile u32 *)(local.state + 0x240) = height;
    *(volatile u32 *)(local.state + 0x24) = format;
    *(volatile u32 *)(local.state + 0xC0) = (width + 15) >> 4;
    *(volatile u32 *)(local.state + 0x20) = (arg1 & 0x8FFFFFFF) | (format & 0x20000);
    if ((format & 0x100000) == 0)
        *(volatile u32 *)(local.state + 0x20) &= ~0x100000;
    mode = arg1 & 0x70000000;
    if (mode != 0x70000000) {
        if (mode == 0)
            *(volatile u32 *)(local.state + 0x20) |= format & 0x70000000;
        else
            *(volatile u32 *)(local.state + 0x20) |= mode;
    }
    switch (mode) {
    case 0x30000000:
        *(volatile u32 *)(local.state + 0) <<= 1;
        break;
    case 0x20000000:
    case 0x10000000:
        *(volatile u32 *)(local.state + 4) <<= 1;
        break;
    case 0x50000000:
    case 0x40000000:
        *(volatile u32 *)(local.state + 0) <<= 1;
        *(volatile u32 *)(local.state + 4) <<= 1;
        break;
    }
    if (magic == 0x674B4942) *(volatile u32 *)(local.state + 0x20) |= 0x18000;
    else if (magic == 0x684B4942) *(volatile u32 *)(local.state + 0x20) |= 0x8000;
    *(volatile u32 *)(local.state + 0x8) = 0;
        *(volatile u32 *)(local.state + 0xCC) = *(u32 *)(local.header + 0x10);
    if ((arg1 & 0x1000) && (s32)lbl_80559938 != -1) {
        *(volatile u32 *)(local.state + 0x14) = lbl_80559938;
        *(volatile u32 *)(local.state + 0x18) = lbl_8055DEDC;
        lbl_80559938 = -1;
    } else {
        *(volatile u32 *)(local.state + 0x14) = *(u32 *)(local.header + 0x1C);
        *(volatile u32 *)(local.state + 0x18) = *(u32 *)(local.header + 0x20);
    }


    count = (*(u32 *)(local.header + 0x1C) +
              (*(u32 *)(local.header + 0x20) >> 1)) /
             *(u32 *)(local.header + 0x20);
        roundedHeight = (*(volatile u32 *)(local.state + 4) + 15) >> 4;
    blockBytes = *(volatile u32 *)(local.state + 0xC0) * roundedHeight;
    *(volatile u32 *)(local.state + 0x2A4) = *(u32 *)(local.header + 0x1C);
    *(volatile u32 *)(local.state + 0x2A8) = *(u32 *)(local.header + 0x20);
    *(volatile u32 *)(local.state + 0x28) = *(u32 *)(local.header + 4);
    *(volatile u32 *)(local.state + 0xD0) = *(u32 *)(local.header + 0x28);
    *(volatile u32 *)(local.state + 0xC8) = *(u32 *)(local.header + 0xC);
    *(volatile u32 *)(local.state + 0xC4) = blockBytes;
    *(volatile u32 *)(local.state + 0x2E4) = blockBytes >> 2;
    *(volatile u32 *)(local.state + 0x2AC) = count;
    if (!count) *(volatile u32 *)(local.state + 0x2AC) = 1;
    fn_8011FE20((u32 **)(local.state + 0xBC), *(volatile u32 *)(local.state + 0xC4) + 0x10);
    fn_8011FE20((u32 **)(local.state + 0x2B4), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2B8), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2BC), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2C0), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2C4), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2C8), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    fn_8011FE20((u32 **)(local.state + 0x2CC), (*(volatile u32 *)(local.state + 0x2AC)) * 4);
    count = lbl_80559944;
    if (count == 0) count = 1;
    fn_8011FE20((u32 **)(local.state + 0x2F0), count * 0x17C);
    fn_8011FE20((u32 **)(local.state + 0x244), lbl_80559944 * 4);
    fn_8011DFAC(local.state + 0x300, (*(volatile u32 *)(local.state + 0) + 15) & ~15);
    fn_8011FE20((u32 **)(local.state + 0x300), *(volatile u32 *)(local.state + 0x300));
    fn_8011FE20((u32 **)(local.state + 0x304), *(volatile u32 *)(local.state + 0x304));
    fn_8011FE20((u32 **)(local.state + 0x308), *(volatile u32 *)(local.state + 0x308));
    fn_8011FE20((u32 **)(local.state + 0x30C), *(volatile u32 *)(local.state + 0x30C));
    fn_8011FE20((u32 **)(local.state + 0x310), *(volatile u32 *)(local.state + 0x310));
    fn_8011FE20((u32 **)(local.state + 0x314), *(volatile u32 *)(local.state + 0x314));
    fn_8011FE20((u32 **)(local.state + 0x318), *(volatile u32 *)(local.state + 0x318));
    fn_8011FE20((u32 **)(local.state + 0x31C), *(volatile u32 *)(local.state + 0x31C));
    fn_8011FE20((u32 **)(local.state + 0x320), *(volatile u32 *)(local.state + 0x320));
    if ((arg1 & 0x04000000) == 0) {
        fn_8011FE20((u32 **)(local.state + 0xEC), (*(volatile u32 *)(local.state + 0xCC) + 1) * 4);
        fn_8011FE20((u32 **)(local.state + 0x248), *(volatile u32 *)(local.state + 0xD0) * 4);
        fn_8011FE20((u32 **)(local.state + 0x24C), *(volatile u32 *)(local.state + 0xD0) * 4);
        fn_8011FE20((u32 **)(local.state + 0x250), *(volatile u32 *)(local.state + 0xD0) * 4);
    }
    {
        allocated = ((void *(*)(void *, s32))fn_80116DDC)(local.state, 0x388);
        if (allocated == 0) {
            fn_80116E2C((const u8 *)(lbl_802F6528 + 0x59));
            return 0;
        }
        memcpy(allocated, local.state, 0x388);
        *(void **)((u8 *)allocated + 0x10C) = allocated;
        **(u32 **)((u8 *)allocated + 0x2B8) = 0;
        **(u32 **)((u8 *)allocated + 0x2BC) = 0;
        **(u32 **)((u8 *)allocated + 0x2C0) = 0;
        **(u32 **)((u8 *)allocated + 0x2C4) = 0;
        **(u32 **)((u8 *)allocated + 0x2C8) = 0;
        **(u32 **)((u8 *)allocated + 0x2CC) = 0;
        activeFlags = *(u32 *)((u8 *)allocated + 0xD0);
        if (arg1 & 0x04000000) {
            *(u32 **)((u8 *)allocated + 0x248) = (u32 *)((u8 *)arg0 + 0x2C);
            *(u32 **)((u8 *)allocated + 0x24C) = (u32 *)((u8 *)arg0 + (activeFlags << 2) + 0x2C);
            *(u32 **)((u8 *)allocated + 0x250) = (u32 *)((u8 *)arg0 + (activeFlags << 3) + 0x2C);
            *(u32 **)((u8 *)allocated + 0xEC) = (u32 *)((u8 *)arg0 + (activeFlags * 12) + 0x2C);
        } else {
            do {
                ((void (*)(void *, s32, void *, s32))*(void **)((u8 *)allocated + 0xF0))(
                    (u8 *)allocated + 0xF0, -1,
                    *(void **)((u8 *)allocated + 0x248), activeFlags << 2);
                ((void (*)(void *, s32, void *, s32))*(void **)((u8 *)allocated + 0xF0))(
                    (u8 *)allocated + 0xF0, -1,
                    *(void **)((u8 *)allocated + 0x24C), activeFlags << 2);
                ((void (*)(void *, s32, void *, s32))*(void **)((u8 *)allocated + 0xF0))(
                    (u8 *)allocated + 0xF0, -1,
                    *(void **)((u8 *)allocated + 0x250), activeFlags << 2);
                ((void (*)(void *, s32, void *, s32))*(void **)((u8 *)allocated + 0xF0))(
                    (u8 *)allocated + 0xF0, -1,
                    *(void **)((u8 *)allocated + 0xEC),
                    (*(u32 *)((u8 *)allocated + 0xCC) + 1) << 2);
            } while (*(s32 *)((u8 *)allocated + 0x110) == 0);
            fn_80116E2C((const u8 *)(lbl_802F6528 + 0x68));
            return 0;
        }
        *(u32 *)((u8 *)allocated + 0xD4) = fn_801174B0(
            *(s32 *)((u8 *)allocated + 8),
            *(u32 **)((u8 *)allocated + 0xEC),
            *(s32 *)((u8 *)allocated + 0x2AC),
            (s32 *)((u8 *)allocated + 0xD8),
            (s32 *)((u8 *)allocated + 0x380));
        if ((arg1 & 0x400) == 0) {
            u8 *record, *records, *outA, *outB, *outC, *outD;
            void *copiedMetadata;
            u32 metadataIndex, alignedRows;
            s32 needsCopy;
            fn_80117618(allocated, local.metadata);
            records = local.metadata;
            outA = local.metadata + 0x1C;
            outB = local.metadata + 0x28;
            outC = local.metadata + 0x34;
            outD = local.metadata + 0x40;
            needsCopy = 0;
            for (metadataIndex = 0; metadataIndex < *(volatile u32 *)local.metadata; metadataIndex++) {
                alignedRows = (*(u32 *)(local.metadata + 0x44) + 15) & ~15;
                record = records + metadataIndex * 0x30;
                if (*(u32 *)(record + 0x18) != 0) {
                    fn_8011FE20((u32 **)outA, *(u32 *)(local.metadata + 0x3C) *
                                                *(u32 *)(local.metadata + 0x40));
                    *(u32 *)(record + 0x20) = *(u32 *)(local.metadata + 0x3C);
                    needsCopy = 1;
                }
                if (*(u32 *)(record + 0x24) != 0) {
                    fn_8011FE20((u32 **)outB, alignedRows * *(u32 *)(local.metadata + 0x48));
                    *(u32 *)(record + 0x2C) = alignedRows;
                    needsCopy = 1;
                }
                if (*(u32 *)(record + 0x30) != 0) {
                    fn_8011FE20((u32 **)outC, alignedRows * *(u32 *)(local.metadata + 0x48));
                    *(u32 *)(record + 0x38) = alignedRows;
                    needsCopy = 1;
                }
                if (*(u32 *)(record + 0x3C) != 0) {
                    fn_8011FE20((u32 **)outD, *(u32 *)(local.metadata + 0x3C) *
                                                *(u32 *)(local.metadata + 0x40));
                    *(u32 *)(record + 0x44) = *(u32 *)(local.metadata + 0x3C);
                    needsCopy = 1;
                }
                outA += 0x30;
                outB += 0x30;
                outC += 0x30;
                outD += 0x30;
            }
            for (; metadataIndex < 2; metadataIndex++) {
                record = records + metadataIndex * 0x30;
                *(u32 *)(record + 0x28) = 0;
                *(u32 *)(record + 0x34) = 0;
                *(u32 *)(record + 0x1C) = 0;
            }
            if (needsCopy) {
                copiedMetadata = ((void *(*)(void *, s32))fn_80116DDC)(allocated, 0x78);
                *(void **)((u8 *)allocated + 0x384) = copiedMetadata;
                if (copiedMetadata == 0) {
                    ((void (*)(void *))fn_80120084)(allocated);
                    fn_80116E2C((const u8 *)(lbl_802F6528 + 0x59));
                    return 0;
                }
                *(void **)((u8 *)allocated + 0xB8) = copiedMetadata;
                memcpy(copiedMetadata, local.metadata, 0x78);
            }
        }
        {
            u8 *entry;
            void *buffer, *oldBuffer, *texture;
            u32 filePosition, begin, i, j, kept, dstOffset, tableOffset;
            u32 scanIndex, listCount, entryIndex, flags2, size, inputFlags, n;
            u32 *input, *inputA, *table, *indices;
            u32 id;
            s32 room, textureMode;
            u32 lastFlag;
            u32 stride;
            s32 (*getPosition)(void *, s32);
        if ((arg1 & 0x01000000) && (s32)lbl_8055993C != -1) {
            *(u32 *)((u8 *)allocated + 0x238) = lbl_8055993C;
            lbl_8055993C = -1;
        } else {
            *(u32 *)((u8 *)allocated + 0x238) = *(u32 *)((u8 *)allocated + 0xD4);
        }
        activeFlags = 0;
        if ((arg1 & 0x00400000) && (s32)lbl_80559940 != -1) {
            activeFlags = lbl_80559940;
            lbl_80559940 = -1;
        }
        if (arg1 & 0x04000000) {
            *(u32 **)((u8 *)allocated + 0xE8) =
                (u32 *)((u8 *)arg0 + (*(u32 *)(*(u32 **)((u8 *)allocated + 0xEC)) & ~1));
        } else {
            getPosition = *(s32 (**)(void *, s32))((u8 *)allocated + 0xF8);
            filePosition = (u32)getPosition((u8 *)allocated + 0xF0,
                                             *(s32 *)((u8 *)allocated + 0x238));
            *(u32 *)((u8 *)allocated + 0x238) = filePosition;
            if (filePosition >= ((*(u32 *)((u8 *)allocated + 0x28) * 9) / 10)) {
                arg1 |= 0x2000;
                *(u32 *)((u8 *)allocated + 0x20) |= 0x2000;
            }
            if (arg1 & 0x2000) {
                input = *(u32 **)((u8 *)allocated + 0xEC);
                begin = (*(u32 *)((u8 *)allocated + 0x28) + 8) - (input[0] & ~1);
                buffer = ((void *(*)(void *, s32, ...))fn_80116DDC)(
                    allocated, begin, input[0]);
                *(void **)((u8 *)allocated + 0xE8) = buffer;
                if (buffer == 0) {
                    oldBuffer = *(void **)((u8 *)allocated + 0xB8);
                    if (oldBuffer != 0)
                        ((void (*)(void *))fn_80120084)(oldBuffer);
                    ((void (*)(void *))fn_80120084)(allocated);
                    fn_80116E2C((const u8 *)(lbl_802F6528 + 0x59));
                    return 0;
                }
                ((void (*)(void *, void *, s32, s32, s32))*(void **)((u8 *)allocated + 0xFC))(
                    (u8 *)allocated + 0xF0, 0, 0,
                    *(s32 *)((u8 *)allocated + 0x28) + 8, activeFlags);
                ((void (*)(void *, s32, u32, void *, s32))*(void **)((u8 *)allocated + 0xF4))(
                    (u8 *)allocated + 0xF0, 0, input[0] & ~1, buffer, begin);
                ((void (*)(void *))*(void **)((u8 *)allocated + 0x104))((u8 *)allocated + 0xF0);
                *(u32 *)((u8 *)allocated + 0x124) = 0;
            } else {
                fn_8011FE20((u32 **)((u8 *)allocated + 0xE4),
                            *(u32 *)((u8 *)allocated + 0xC8));
                buffer = ((void *(*)(void *, s32))fn_80116DDC)(
                    allocated, *(s32 *)((u8 *)allocated + 0x238));
                *(void **)((u8 *)allocated + 0x234) = buffer;
                if (buffer == 0)
                    *(u32 *)((u8 *)allocated + 0x238) = 0;
                ((void (*)(void *, void *, s32, s32, s32))*(void **)((u8 *)allocated + 0xFC))(
                    (u8 *)allocated + 0xF0, buffer,
                    *(s32 *)((u8 *)allocated + 0x238),
                    *(s32 *)((u8 *)allocated + 0x28) + 8, activeFlags);
            }
        }
        **(u32 **)((u8 *)allocated + 0xBC) = 0;
        *(s32 *)((u8 *)allocated + 0x0C) = -1;
        if (*(s32 *)((u8 *)allocated + 0x14) != 0) {
            *(s32 *)((u8 *)allocated + 0x270) =
                fn_80116BD4(0x7D0, *(s32 *)((u8 *)allocated + 0x18), 0);
        } else {
            *(s32 *)((u8 *)allocated + 0x270) = 0x7D0;
        }
        *(s32 *)((u8 *)allocated + 0x28C) = 1;
        fn_80117380(allocated, 1);
        *(s32 *)((u8 *)allocated + 0x2A0) =
            fn_80116D30() - *(s32 *)((u8 *)allocated + 0x2A0);
        *(u32 *)(*(u32 **)((u8 *)allocated + 0x2F0) + 0x6C / 4) = 0x10000;
        *(u32 *)((u8 *)allocated + 0x2E8) = 0;
        if (*(s32 *)((u8 *)allocated + 0xD0) != 0 && lbl_80559944 != 0) {
            for (i = 0; i < lbl_80559944; i++) {
                table = *(u32 **)((u8 *)allocated + 0x250);
                for (j = 0; j < (u32)*(s32 *)((u8 *)allocated + 0xD0); j++) {
                    if (table[j] == ((u32 *)&lbl_8041D608)[i]) {
                        n = *(u32 *)((u8 *)allocated + 0x2E8);
                        ((u32 *)*(u32 **)((u8 *)allocated + 0x244))[n] = j;
                        *(u32 *)((u8 *)allocated + 0x2E8) = n + 1;
                        break;
                    }
                }
            }
        }
        lbl_80559944 = 1;
        *(volatile u32 *)&lbl_8041D608 = 0;
        dstOffset = 0;
        tableOffset = 0;
        scanIndex = 0;
        kept = 0;
        while (scanIndex < *(u32 *)((u8 *)allocated + 0x2E8)) {
            *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) = 0;
            entryIndex = *(u32 *)((u8 *)*(u32 **)((u8 *)allocated + 0x244) + tableOffset);
            flags2 = ((u32 *)*(u32 **)((u8 *)allocated + 0x24C))[entryIndex];
            if (((flags2 >> 31) || ((flags2 >> 28) & 1)) && lbl_8055DECC != 0) {
                id = flags2 & 0xFFFF;
                if (*(u32 *)((u8 *)allocated + 0x14) != 0 &&
                    *(u32 *)((u8 *)allocated + 0x18) != 0) {
                    id = (u16)((f64)*(u32 *)(local.state + 0x2A8) *
                        ((f64)(u32)id * (f64)*(u32 *)((u8 *)allocated + 0x14)) /
                        ((f64)*(u32 *)((u8 *)allocated + 0x18) *
                         (f64)*(u32 *)(local.state + 0x2A4)));
                }
                if (((s32 (*)(void *, s32, s32, s32, s32, void *))lbl_8055DECC)(
                    (*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset), id, ((flags2 >> 27) & 8) + 8,
                    ((flags2 >> 29) & 1) + 1,
                    *(s32 *)((u8 *)allocated + 0x20), allocated) != 0) {
                    if (*(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x58) == 0)
                        *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x58) = -1;
                    inputA = *(u32 **)((u8 *)allocated + 0x248);
                    size = (*(u32 **)((u8 *)allocated + 0x248))[
                        *(u32 *)((u8 *)*(u32 **)((u8 *)allocated + 0x244) + tableOffset)];
                    *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x28) = (size + 0xFF) & ~0xFF;
                    *(void **)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) =
                        ((void *(*)(void *, s32, ...))fn_80116DDC)(
                            allocated, *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x28), size, inputA);
                    if (*(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) == 0) {
                        ((void (*)(void *))*(void **)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x1C))((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset));
                    } else {
                        room = 0x2EE - *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x68);
                        if (room < 0) room = 0;
                        inputFlags = (*(u32 **)((u8 *)allocated + 0x24C))[
                            *(u32 *)((u8 *)*(u32 **)((u8 *)allocated + 0x244) + tableOffset)];
                        *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x44) = ((u32)__cntlzw((inputFlags << 5) & 8) >> 5);
                        *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x30) =
                            *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) + *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x28);
                        *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x34) = *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C);
                        *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x38) = *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C);
                        inputFlags = (*(u32 **)((u8 *)allocated + 0x24C))[
                            *(u32 *)((u8 *)*(u32 **)((u8 *)allocated + 0x244) + tableOffset)];
                        *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x4C) =
                            fn_80116BD4((id * (((inputFlags >> 29) & 1) + 1)) * 2,
                                        room, 0x3E8) & ~3;
                        if (*(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x4C) > *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x28))
                            *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x4C) = *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x28);
                        lastFlag = (*(u32 **)((u8 *)allocated + 0x24C))[
                            *(u32 *)((u8 *)*(u32 **)((u8 *)allocated + 0x244) + tableOffset)];
                        texture = 0;
                        if ((lastFlag >> 31) || ((lastFlag >> 28) & 1)) {
                            textureMode = (lastFlag >> 28) & 1;
                            texture = fn_8011B584((u16)lastFlag,
                                                  ((lastFlag >> 29) & 1) + 1,
                                                  textureMode, 0);
                        }
                        *(void **)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x3C) = texture;
                        if (*(volatile u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x3C) == 0) {
                            ((void (*)(void *))*(void **)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x1C))((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset));
                            *(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) = 0;
                        }
                        lbl_8055DED0 += 1;
                        stride = *(s32 *)((u8 *)allocated + 0x2A4);
                        *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x48) =
                            *(s32 *)((u8 *)allocated + 8) -
                            ((stride * 3) / (*(s32 *)((u8 *)allocated + 0x2A8) * 4));
                        *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x40) = 0;
                    }
                }
            }
            if (*(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x6C) == 0)
                *(s32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x6C) = 0x10000;
            if (*(u32 *)((*(u8 **)((u8 *)allocated + 0x2F0) + dstOffset) + 0x2C) == 0) {
                n = *(u32 *)((u8 *)allocated + 0x2E8) - 1;
                *(u32 *)((u8 *)allocated + 0x2E8) = n;
                indices = *(u32 **)((u8 *)allocated + 0x244);
                memcpy((u8 *)indices + tableOffset,
                       &indices[scanIndex + 1], (n - scanIndex) * 4);
            } else {
                dstOffset += 0x17C;
                tableOffset += 4;
                scanIndex++;
            }
            kept = scanIndex;
        }
        if (*(s32 *)((u8 *)allocated + 0x2E8) != 0) {
            *(s32 *)((u8 *)allocated + 0x288) = 1;
            if (*(s32 *)(*(u8 **)((u8 *)allocated + 0x2F0) + 0x60) == 0) {
                if (lbl_8055DED4 == 0) {
                    lbl_8055DED4 = (s32)fn_8011BE48(-0xD);
                    if (lbl_8055DED4 != 0)
                        fn_8011C120();
                }
                if (lbl_8055DED4 != 0)
                    fn_8011BEC8((void *)(u32)lbl_8055DED4, (u8 *)allocated + 0x340,
                                (s32)fn_80117598, (s32)fn_801175C4);
            }
        }
        if (*(void **)((u8 *)allocated + 0xE8) == 0 && !(arg1 & 0x200000)) {
            while (((s32 (*)(void *))*(void **)((u8 *)allocated + 0x100))(
                       (u8 *)allocated + 0xF0) != 0) {
            }
        }
        }
        
    }
    return (s32 *)allocated;
}
#undef lbl_8041D608

void fn_80118C1C(void *arg0, s32 arg1) {
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 0x264);
    if (temp_r0 != 0) {
        s32 temp_r5 = *(s32 *)((u8 *)arg0 + 0x29c);
        *(s32 *)((u8 *)arg0 + 0x29c) = temp_r5 + (arg1 - temp_r0);
        *(s32 *)((u8 *)arg0 + 0x264) = 0;
    }
}

extern s32 fn_801190B0(void*, s32);
void fn_80118C44(void* arg0) {
    s32 temp_r5;
    s32 var_r4;
    s32 var_r6;
    u32 temp_r5_2;
    u32 temp_r7;
    s32 var_r8;
    u32 var_r9;
    void* temp_r4;
    volatile s32 *flag;
    volatile u32 *iterations;

    flag = (volatile s32 *)((u8*)arg0 + 0x11C);
    iterations = (volatile u32 *)((u8*)arg0 + 0x2E8);
    var_r8 = 0;
    if (arg0 != 0) {
        temp_r5 = 0;
        *flag = 1;
        var_r9 = 0;
        var_r6 = 0;
        *(s32*)((u8*)arg0 + 0x2F8) = temp_r5;
        *flag = temp_r5;
        while (var_r9 < *iterations) {
            temp_r4 = (u8*)*(void**)((u8*)arg0 + 0x2F0) + var_r6;
            if (*(s32*)((u8*)temp_r4 + 0x5C) != 0) {
                *(s32*)((u8*)temp_r4 + 0x5C) = 0;
                temp_r7 = *(u32*)((u8*)arg0 + 0x0C);
                if (temp_r7 > 1) {
                    temp_r4 = (u8*)*(void**)((u8*)arg0 + 0x2F0) + var_r6;
                    if ((s32)temp_r7 <= *(s32*)((u8*)temp_r4 + 0x48))
                        var_r8 = 1;
                }
            }
            var_r6 += 0x17C;
            var_r9 += 1;
        }
        if (var_r8 != 0) {
            temp_r5 = *(s32*)((u8*)arg0 + 0x2EC);
            *(s32*)((u8*)arg0 + 0x2EC) = temp_r5 + 1;
            fn_8011C274(lbl_8055DED4, (u8*)arg0 + 0x340);
            fn_801190B0(arg0, 0);
            for (;;) {
                temp_r7 = *(u32*)((u8*)arg0 + 0x138);
                temp_r5_2 = *(u32*)((u8*)arg0 + 0x13C);
                temp_r7 = (temp_r7 * 0x1D) >> 5;
                if (temp_r5_2 >= temp_r7) break;
                if (((s32 (*)(void*))(*(void**)((u8*)arg0 + 0x100)))((u8*)arg0 + 0xF0) == 0) {
                    *(s32*)((u8*)arg0 + 0x268) = 0;
                    *(s32*)((u8*)arg0 + 0x328) = 0;
                    *(s32*)((u8*)arg0 + 0x330) = 0;
                    fn_801190B0(arg0, 1);
                    fn_8011C2EC(lbl_8055DED4, (u8*)arg0 + 0x340);
                }
            }
        }
        *flag = 1;
        if (*(s32*)((u8*)arg0 + 0x2E8) != 0)
            fn_80117074(arg0);
        fn_80118C1C(arg0, fn_80116D30());
        temp_r5 = *(s32*)((u8*)arg0 + 0x0C);
        var_r4 = 1;
        if ((u32)temp_r5 < *(u32*)((u8*)arg0 + 0x08))
            var_r4 = temp_r5 + 1;
        fn_80117380(arg0, var_r4);
        *flag = 0;
    }
}

extern s32 fn_80118F78(void*, s32);
extern s32 fn_8011BFFC(s32, s32, s32, s32, s32);
extern void fn_8011BC48();
void fn_80118DC0(void* arg0) {
#pragma scheduling off
    s32 offset;
    s32 i;
    s32 status;
    s32 fileInfo;

    if (arg0 == 0) return;
    fn_80118F78(arg0, 1);
    fileInfo = (s32)((u8*)arg0 + 0x1F4);
    status = fn_8011BFFC(
        0,
        fileInfo,
        *(s32*)((u8*)arg0 + 0x2E8) != 0
            ? *(volatile s32*)&lbl_8055DED4
            : 0,
        (s32)((u8*)arg0 + 0x340),
        1
    );
    switch (status) {
    case 3:
        goto status3;
    case 2:
        goto status2;
    default:
        break;
    }
    goto status_done;
status3:
    lbl_8055DED4 = 0;
    goto status_done;
status2:
    lbl_8055DED4 = 0;
status_done:
    i = 0;
    offset = 0;
    while ((u32)i < *(u32*)((u8*)arg0 + 0x2E8)) {
        void* item = *(void**)((u8*)arg0 + 0x2F0);
        item = (u8*)item + offset;
        ((void (*)(void*))(*(void**)((u8*)item + 0x1C)))(item);
        fn_8011BC48(*(s32*)((u8*)*(void**)((u8*)arg0 + 0x2F0) + offset + 0x3C));
        {
            void* handle = *(void**)((u8*)*(void**)((u8*)arg0 + 0x2F0) + offset + 0x2C);
            if (handle != 0) fn_80120084(handle);
        }
        offset += 0x17C;
        i += 1;
    }
    {
        void* field = *(void**)((u8*)arg0 + 0xE8);
        if (field != 0) {
            if ((*(u32*)((u8*)arg0 + 0x20) & 0x04000000) == 0)
                fn_80120084(field);
        } else {
            ((void (*)(void*))(*(void**)((u8*)arg0 + 0x104)))((u8*)arg0 + 0xF0);
            fn_80120084(*(void**)((u8*)arg0 + 0x234));
        }
    }
    {
        void* field = *(void**)((u8*)arg0 + 0x384);
        if (field != 0) fn_80120084(field);
    }
    memset(arg0, 0, 0x388);
    fn_80120084(arg0);
#pragma scheduling reset
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

s32 fn_80118F78(void *arg0, s32 arg1) {
    s32 result;
    s32 elapsed;
    s32 reset;
    s32 offset;
    u32 index;

    reset = 0;
    if (arg0 == 0) {
        return 0;
    }

    elapsed = fn_80116D30();
    fn_80118C1C(arg0, elapsed);
    fn_80118F1C(arg0, elapsed);

    if (arg1 == 0) {
        if (*(s32 *)((u8 *)arg0 + 0xDC) != 0) {
            reset = 1;
        }
    } else if (*(s32 *)((u8 *)arg0 + 0xDC) == 0) {
        result = *(s32 *)((u8 *)arg0 + 0x268);
        if (result != 0) {
            *(s32 *)((u8 *)arg0 + 0x330) = elapsed - result;
        } else {
            *(s32 *)((u8 *)arg0 + 0x330) = 0;
        }
    }

    *(s32 *)((u8 *)arg0 + 0xDC) = arg1;
    fn_8011C274(lbl_8055DED4, (u8 *)arg0 + 0x340);

    index = 0;
    offset = 0;
    while (index < *(u32 *)((u8 *)arg0 + 0x2E8)) {
        void *object = *(u8 **)((u8 *)arg0 + 0x2F0) + offset;
        (*(void (**)(void *, s32))((u8 *)object + 0x14))(object, arg1);
        offset += 0x17C;
        index++;
    }

    fn_8011C2EC(lbl_8055DED4, (u8 *)arg0 + 0x340);
    if (*(s32 *)((u8 *)arg0 + 0x258) != 0 &&
        *(s32 *)((u8 *)arg0 + 0x2E8) != 0) {
        fn_80117074(arg0);
    }

    if (reset != 0) {
        result = fn_80116D30();
        *(s32 *)((u8 *)arg0 + 0x268) =
            result - *(s32 *)((u8 *)arg0 + 0x330);
    }

    return *(s32 *)((u8 *)arg0 + 0xDC);
}

s32 fn_801190B0(void *arg0, s32 arg1) {
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;
    s32 temp_r3_2;
    u32 temp_r3_5;
    u32 var_r28;
    s32 zero;
    s32 one;

    var_r30 = 0;
    if (arg0 != 0) {
        var_r29 = 0;
        var_r28 = 0;
        var_r31 = 0;
        zero = 0;
        one = 1;
        goto loop_check;
    loop_body:
        if (*(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x18) != 0) {
            if (var_r29 == 0) {
                var_r29 = 1;
                fn_8011C274(lbl_8055DED4,
                    (void *)((s32)arg0 + 0x340));
            }
            temp_r3_2 = (*(s32 (**)(void *, s32))(
                *(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x18))(
                    *(u8 **)((u8 *)arg0 + 0x2F0) + var_r31,
                    arg1 != 0);
            if (temp_r3_2 != 0) {
                var_r30 = 1;
            }
            if (temp_r3_2 == 0 && *(s32 *)((u8 *)arg0 + 0x288) != 0) {
                *(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x34) =
                    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x2C);
                *(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x38) =
                    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x2C);
                *(s32 *)(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31 + 0x40) =
                    zero;
                temp_r3_5 = *(u32 *)((u8 *)arg0 + 0xC);
                if (temp_r3_5 == 1 &&
                    *(u32 *)((u8 *)arg0 + 0x2D4) != temp_r3_5) {
                } else {
                    fn_80116F8C(*(u8 **)((u8 *)arg0 + 0x2F0) + var_r31);
                }
                *(s32 *)((u8 *)arg0 + 0x288) = zero;
            } else if (temp_r3_2 != 0 &&
                       *(s32 *)((u8 *)arg0 + 0x288) == 0) {
                *(s32 *)((u8 *)arg0 + 0x288) = one;
                *(s32 *)((u8 *)arg0 + 0x268) = zero;
                *(s32 *)((u8 *)arg0 + 0x328) = zero;
                *(s32 *)((u8 *)arg0 + 0x330) = zero;
            }
        }
        var_r31 += 0x17C;
        var_r28++;
    loop_check:
        if (var_r28 < *(u32 *)((u8 *)arg0 + 0x2E8)) {
            goto loop_body;
        }
        if (var_r29 != 0) {
            fn_8011C2EC(lbl_8055DED4, (u8 *)arg0 + 0x340);
        }
    }
    return var_r30;
}

void fn_80119214(void) {
    AXFXSetHooks_8011FFB8();
}

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

#pragma push
#pragma scheduling invalid_target
void fn_80119288(void* arg0, f32 arg1) {
    void* saved = arg0;
    void* first;
    s32 mode;
    s32 out1;
    s32 out2;
    s32 out3;
    first = *(void**)((u8*)saved + 0x7C);
    if (first != 0) {
        arg0 = first;
        mode = *(s32*)((u8*)saved + 0x78);
        out1 = *(s32*)((u8*)saved + 0xA4);
        out2 = *(s32*)((u8*)saved + 0xA8);
        out3 = mode == 1 ? *(s32*)((u8*)saved + 0xAC) : 0;
        ((void (*)(void*, s32, s32, s32))fn_80119218)(arg0, out1, out2, out3);
    }
    first = *(void**)((u8*)saved + 0x80);
    if (first != 0)
        ((void (*)(void*, s32, s32, s32))fn_80119218)(first, *(s32*)((u8*)saved + 0xA4), 0, *(s32*)((u8*)saved + 0xAC));
}
#pragma pop
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

void fn_801195A0(void *arg0) {
    fn_8011943C(arg0, 0);
    *(s32 *)((u8 *)arg0 + 0x38) = 1;
}

s32 fn_80119824(void *arg0) {
    s32 temp_r3;
    s32 temp_r4;
    u32 var_r4;
    u32 temp_r0;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r4_3;
    u32 var_r30;

    if (*(s32 *)((u8 *)arg0 + 0xB4) == 0) {
        if (*(s32 *)((u8 *)arg0 + 0x64) != 0) {
        } else {
            return 0;
        }
    } else {
    }
    if (*(s32 *)((u8 *)arg0 + 0xB0) == 0) {
        fn_801195D8();
        return 0;
    }
    var_r30 = *(u32 *)((u8 *)arg0 + 0xC4);
    if ((u32)(fn_80116D30() - *(s32 *)((u8 *)arg0 + 0xCC)) > 0xC) {
    block_6:
        var_r30 = fn_801194E4((u8 *)arg0 + 0x7C);
        temp_r3 = fn_80116D30();
        temp_r4 = temp_r3 - *(s32 *)((u8 *)arg0 + 0xCC);
        *(u32 *)((u8 *)arg0 + 0xC4) = var_r30;
        if ((u32)temp_r4 < *(u32 *)((u8 *)arg0 + 0xD0)) {
            goto block_8;
        }
        *(s32 *)((u8 *)arg0 + 0xCC) = temp_r3;
        goto block_16;
    block_8:
        *(s32 *)((u8 *)arg0 + 0xCC) = temp_r3;
    }
    temp_r3_2 = *(u32 *)((u8 *)arg0 + 0xB8);
    if (var_r30 < temp_r3_2) {
        var_r4 = var_r30 + *(u32 *)((u8 *)arg0 + 0x94) - temp_r3_2;
    } else {
        var_r4 = var_r30 - temp_r3_2;
    }
    temp_r3_3 = (var_r4 < 0x400)
        ? 0
        : ((var_r4 - 0x400) & 0xFFFFFFFC);
    if (temp_r3_3 >= *(u32 *)((u8 *)arg0 + 0x9C)) goto block_15;
    if (*(s32 *)((u8 *)arg0 + 0xBC) == 0) goto return_zero;
    if (temp_r3_3 == 0) goto return_zero;
block_15:
    if (temp_r3_3 < *(u32 *)((u8 *)arg0 + 0xC8)) goto block_18;
block_16:
    *(s32 *)((u8 *)arg0 + 0x5C) = 1;
    fn_80119300((u8 *)arg0 + 0x7C,
                *(s32 *)((u8 *)arg0 + 0xB8),
                *(s32 *)((u8 *)arg0 + 0x9C) * 2);
    temp_r4_3 = *(u32 *)((u8 *)arg0 + 0x94);
    temp_r0 = *(u32 *)((u8 *)arg0 + 0xB8) +
              *(u32 *)((u8 *)arg0 + 0x9C) * 2;
    *(u32 *)((u8 *)arg0 + 0xB8) = temp_r0;
    if (temp_r0 >= temp_r4_3) {
        *(u32 *)((u8 *)arg0 + 0xB8) = temp_r0 - temp_r4_3;
    }
    goto block_6;
block_18:
    *(u32 *)((u8 *)arg0 + 0xBC) = temp_r3_3;
    fn_801195D8(arg0);
return_zero:
    return 0;
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

s32 fn_801199A4(void* arg0, s32 arg1) {
    extern void fn_8003381C(void*, s16*);
    s16 rect[8];
    u32 limit;
    u32 x0;
    u32 x1;
    u32 width;
    u32 height;
    u32 y0;
    u32 y1;
    rect[0] = 1;
    rect[1] = 10;
    width = *(u32*)((u8*)arg0 + 0x10);
    x0 = width >> 1;
    x1 = ((width + *(u32*)((u8*)arg0 + 0x1C)) >> 1) - 1;
    if (arg1 != 0)
        limit = x0;
    else
        limit = *(u32*)(*(u32*)arg0 + 0x1BC);
    rect[2] = x0 >> 16;
    rect[3] = x0;
    rect[4] = x1 >> 16;
    rect[5] = x1;
    rect[6] = limit >> 16;
    rect[7] = limit;
    fn_8003381C(*(void**)arg0, rect);
    if (*(void**)((u8*)arg0 + 4) != 0) {
        height = *(u32*)((u8*)arg0 + 0x14);
        y0 = height >> 1;
        y1 = ((height + *(u32*)((u8*)arg0 + 0x1C)) >> 1) - 1;
        if (arg1 != 0)
            limit = y0;
        else
            limit = *(u32*)(*(u32*)((u8*)arg0 + 4) + 0x1BC);
        rect[2] = y0 >> 16;
        rect[3] = y0;
        rect[4] = y1 >> 16;
        rect[5] = y1;
        rect[6] = limit >> 16;
        rect[7] = limit;
        fn_8003381C(*(void**)((u8*)arg0 + 4), rect);
    }
}

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
#pragma optimization_level 4
s32 fn_80119C0C(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    if (arg1 != 0) {
        if (*(s32 *)((u8 *)arg0 + 0x64) == 0) {
            *(s32 *)((u8 *)arg0 + 0xb0) = 0;
            *(s32 *)((u8 *)arg0 + 0x64) = 1;
            *(s32 *)((u8 *)arg0 + 0xb8) = 0;
            *(s32 *)((u8 *)arg0 + 0xbc) = *(s32 *)((u8 *)arg0 + 0xc0);
            goto exit;
        }
    }
    if (arg1 == 0 && *(s32 *)((u8 *)arg0 + 0x64) != 0) {
        arg0 = (u8 *)arg0 + 0x7c;
        fn_8011943C(arg0, 0);
        fn_801199A4(base + 0x7c, 1);
        fn_80119300(base + 0x7c, 0, *(s32 *)(base + 0x94));
        *(s32 *)(base + 0x64) = 0;
    }
exit:
    return *(s32 *)(base + 0x64);
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

void fn_80119D40(void *arg0) {
    struct CallbackTable {
        s32 first;
        void (*callback)(s32, struct CallbackTable *);
    };
    struct Context {
        u8 pad[0x7C];
        s32 buffer0;
        s32 buffer1;
        s32 buffer2;
        s32 buffer3;
        u8 pad2[0x28];
        s32 flag;
    };
    struct Context *ctx = (struct Context *)arg0;
    struct CallbackTable *table;
    void (*callback)(s32, struct CallbackTable *);
    if (ctx->buffer0 != 0) {
        ctx->flag = 1;
        fn_8011943C(&ctx->buffer0, 0);
        if (ctx->buffer0 != 0)
            TRKGetFreeBuffer((void *)ctx->buffer0);
        if (ctx->buffer1 != 0)
            TRKGetFreeBuffer((void *)ctx->buffer1);
        table = (struct CallbackTable *)&lbl_8055DEE0;
        callback = table->callback;
        callback(ctx->buffer2, table);
        lbl_8055DEE8 -= 1;
        ctx->buffer0 = 0;
    }
}

extern s32 TRKInitializeMessageBuffers(s32, s32, s32);
extern void fn_80033408(s32, s32);
extern void fn_800339B0(s32, void *);
extern void fn_80033A34(s32, f32);
extern void fn_80033918(s32, void *);
extern const f64 lbl_805611C8;
extern const f64 lbl_805611D0;
s32 fn_80119DD0(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    extern s32 lbl_8055DEE0;
    extern s32 lbl_8055DEE8;
    extern void TRKGetFreeBuffer(void *);
    extern s32 fn_80119824(void *);
    extern void fn_80119D40();
     u8 *ctx = (u8 *)arg0;
    u32 sampleRate = arg1;
    u32 count, rate, frames, i, loopSample, loopBuffer;
    register u32 *buffer;
    struct { s16 config[7]; u8 pad[2]; u8 work[0x28]; volatile u8 reserve[8]; } scratch;

    if (lbl_8055DEE0 == 0) return 0;
    memset(arg0, 0, 0x17C);
    *(u32 *)(ctx + 0x5C) = 0;
    *(u32 *)(ctx + 0x70) = sampleRate;
    *(u32 *)(ctx + 0x74) = 0x10;
    *(s32 *)(ctx + 0x78) = arg3;
    *(u32 *)(ctx + 0x7C) = TRKInitializeMessageBuffers(0x1F, 0, 0);
    if (*(u32 *)(ctx + 0x7C) == 0) return 0;
    if (*(s32 *)(ctx + 0x78) != 1) {
        *(u32 *)(ctx + 0x80) = TRKInitializeMessageBuffers(0x1F, 0, 0);
        if (*(u32 *)(ctx + 0x80) == 0) {
            TRKGetFreeBuffer((void *)*(u32 *)(ctx + 0x7C));
            return 0;
        }
    }
    *(volatile u32 *)(ctx + 0xD0) = 0x21C;
    count = *(u32 *)(ctx + 0x78) * (*(u32 *)(ctx + 0x70) * 2);
    *(volatile u32 *)(ctx + 0xA0) = sampleRate;
    *(volatile u32 *)(ctx + 0x68) = 0;
    frames = ((count * 0x258) / 1000 + 0x3FF) & ~0x3FF;
    *(u32 *)(ctx + 0x94) = frames;
    *(u32 *)(ctx + 0x9C) = ((count * 0x32) / 1000 + 0xFF) & ~0xFF;
    *(u32 *)(ctx + 0xC8) = (frames * 0x5A) / 100;
    if (*(u32 *)((u8 *)arg5 + 0x14) != 0 && *(u32 *)((u8 *)arg5 + 0x18) != 0) {
        u32 divisor = *(u32 *)((u8 *)arg5 + 0x14);
        u64 numerator = (u64)count * *(u32 *)((u8 *)arg5 + 0x18) * *(u32 *)((u8 *)arg5 + 8);
        rate = (u32)(numerator / divisor);
    } else {
        rate = *(u32 *)(ctx + 0x9C);
    }
    if (arg3 != 1) {
        *(u32 *)(ctx + 0x98) = *(u32 *)(ctx + 0x94) >> 1;
        buffer = (u32 *)(ctx + 0x98);
    } else {
        *(u32 *)(ctx + 0x98) = *(u32 *)(ctx + 0x94);
        buffer = (u32 *)(ctx + 0x98);
    }
    *(u32 *)(ctx + 0x84) = ((u32 (*)(u32))lbl_8055DEE0)(*(u32 *)(ctx + 0x94));
    *(u32 *)(ctx + 0x88) = *(u32 *)(ctx + 0x84) + *buffer;
    *(u32 *)(ctx + 0x8C) = *(u32 *)(ctx + 0x84) + 0x80000000;
    *(u32 *)(ctx + 0x90) = *(u32 *)(ctx + 0x8C) + *buffer;
    *(u32 *)(ctx + 0x54) = *(u32 *)(ctx + 0x9C);
    *(u32 *)(ctx + 0xA4) = 0x7FFF;
    *(u32 *)(ctx + 0xA8) = 0x67F8;
    *(u32 *)(ctx + 0xAC) = 0x67F8;
    ((void (*)(void *))fn_80119288)(arg0);
    fn_801199A4(ctx + 0x7C, 1);
    buffer = (u32 *)(ctx + 0x7C);
    for (i = 0; i < *(u32 *)(ctx + 0x78); i++) {
        memset(scratch.work, 0, 0x28);
        *(u16 *)(scratch.work + 0x20) = 0x800;
        scratch.config[0] = 1;
        scratch.config[1] = 0;
        scratch.config[2] = 0;
        scratch.config[3] = 0;
        scratch.config[4] = 0;
        scratch.config[5] = 0;
        scratch.config[6] = 0;
        fn_80033408(*buffer, 1);
        fn_800339B0(*buffer, scratch.config);
        loopSample = *(u32 *)(ctx + 0x70);
        *(volatile u32 *)(scratch.work + 0x28) = 0x43300000;
        loopBuffer = *buffer;
        *(volatile u32 *)(scratch.work + 0x2C) = loopSample;
        fn_80033A34(loopBuffer, (f32)((*(volatile f64 *)(scratch.work + 0x28) - lbl_805611D0) / lbl_805611C8));
        fn_80033918(*buffer, scratch.work);
        buffer++;
    }
    fn_80119300(ctx + 0x7C, 0, *(u32 *)(ctx + 0x94));
    *(u32 *)(ctx + 0xB8) = 0;
    frames = *(u32 *)(ctx + 0x94);
    *(u32 *)(ctx + 0xB0) = 0;
    if (rate < frames) frames = rate;
    *(u32 *)(ctx + 0xC0) = frames;
    *(u32 *)(ctx + 0xBC) = frames;
    *(u32 *)(ctx + 0xB4) = 0;
    *(u32 *)(ctx + 0x64) = 1;
    *(void **)(ctx + 0x00) = fn_80119824;
    *(void **)(ctx + 0x04) = fn_80119994;
    *(void **)(ctx + 0x08) = fn_8011999C;
    *(void **)(ctx + 0x0C) = fn_80119AB0;
    *(void **)(ctx + 0x10) = fn_80119B38;
    *(void **)(ctx + 0x14) = fn_80119CB0;
    *(void **)(ctx + 0x18) = fn_80119C0C;
    *(void **)(ctx + 0x1C) = fn_80119D40;
    lbl_8055DEE8++;
    return 1;
}

extern s32 lbl_8055DEE0;
extern s32 lbl_8055DEE4;
extern s32 lbl_8055DEE8;
extern s32 fn_80119DD0(void *, u32, s32, s32, s32, void *);
extern void fn_8011A6A0(void *);
extern void TRKGetFreeBuffer(void *);
void *fn_8011A168(void *arg0) {
    s32 *src = (s32 *)arg0;
    s32 second;
    s32 first;
    if (arg0 == NULL) {
        lbl_8055DEE0 = 0;
        *((s32 *)&lbl_8055DEE0 + 1) = 0;
    } else {
        second = src[1];
        first = src[0];
        lbl_8055DEE0 = first;
        lbl_8055DEE4 = second;
    }
    return &fn_80119DD0;
}

#pragma unroll on
void fn_8011A1A0(u32 *data, u32 size) {
    u32 count = (size + 3) >> 2;
    u32 groups;
    if (count) {
        groups = count >> 3;
        if (groups) {
            do {
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
                *data = __lwbrx(data, 0); data++;
            } while (--groups);
            count &= 7;
        }
        if (count) {
            do {
                *data = __lwbrx(data, 0); data++;
            } while (--count);
        }
    }
}

u32 fn_8011A240(void *arg0, u32 arg1, s32 arg2, u32 arg3) {
    u8 buffer[0x41F];
    register void *block = arg0;
    register u32 bufferAddr;
    register u32 available;
    register s32 total = 0;
    register u32 amount;
    register s32 remaining = (s32)arg3;
    register s32 dst = arg2;
    register s32 offset = (s32)arg1;
    s32 status;

    bufferAddr = (u32)(buffer + 0x1F) & 0xFFFFFFE0;
    available = ((u32)(buffer + 0x41F) - bufferAddr) & 0xFFFFFFE0;
    while (remaining != 0) {
        amount = ((u32)remaining + 0x1F) & 0xFFFFFFE0;
        if ((u32)remaining >= available) amount = available;
        DVDReadAsyncPrio(block, (void *)bufferAddr, amount, offset, 0, 0);
poll_drive:
        status = DVDGetDriveStatus();
        if (status == 0) goto read_done;
        if (status >= 0) goto status_nonnegative;
        if (status < -1) goto poll_drive;
        goto read_failed;
status_nonnegative:
        if (status >= 0xC) goto poll_drive;
        if (status >= 3) goto read_failed;
        goto poll_drive;
read_failed:
        return 0;
read_done:
        if (amount > (u32)remaining) amount = (u32)remaining;
        memcpy((void *)dst, (void *)bufferAddr, amount);
        dst += amount;
        total += amount;
        remaining -= amount;
        offset += amount;
    }
    return total;
}

#pragma push
#pragma scheduling on
#pragma dont_inline on
void fn_8011A330(void* arg0) {
    s32 status;
    *(s32*)((u8*)arg0 + 0xC4) = 1;
    DVDCancel((DVDCommandBlock*)((u8*)arg0 + 0x54));
    do {
        status = DVDGetDriveStatus();
    } while (status == 2 || status == 1);
    *(s32*)((u8*)arg0 + 0xC4) = 0;
    *(s32*)((u8*)arg0 + 0x24) = 0;
}
#pragma dont_inline reset
#pragma pop

u32 fn_8011A388(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    extern u32 fn_8011A240(void *, u32, s32, u32);
    extern void fn_8011A330(void *);
    volatile u32 *offset = (volatile u32 *)((u8 *)arg0 + 0x90);
    volatile u32 *base = (volatile u32 *)((u8 *)arg0 + 0xB4);
    volatile u32 *capacityPtr = (volatile u32 *)((u8 *)arg0 + 0x40);
    u32 result;
    u32 current;
    u32 end;
    u32 newPosition;
    u32 capacity;
    u32 remaining;

    if (arg1 == -1) goto return_arg3;
    if (*offset == (u32)arg1) goto return_arg3;
    *offset = (u32)arg1;
    current = *offset;
    result = fn_8011A240((u8 *)arg0 + 0x54,
                         current + *base, arg2, arg3);
    if (result != arg3) {
        *(s32 *)((u8 *)arg0 + 0x20) = 1;
        fn_8011A330(arg0);
    }
    current = *offset;
    end = *(u32 *)((u8 *)arg0 + 0xB8);
    newPosition = current + result;
    *offset = newPosition;
    current = *offset;
    capacity = *capacityPtr;
    remaining = end - current;
    *(u32 *)((u8 *)arg0 + 0x98) = current;
    if (remaining >= capacity) {
        *(u32 *)((u8 *)arg0 + 0x48) = *capacityPtr;
    }
    fn_8011A1A0((u32 *)arg2, result);
    return result;
return_arg3:
    return arg3;
}

#pragma unroll reset
void fn_8011A45C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 var_r31;
    volatile s32 *counter = (volatile s32 *)((u8 *)arg0 + 0xC0);

    temp_r31 = fn_80116BD4(arg1, 0x3E8, *(s32 *)((u8 *)arg0 + 0xBC));
    temp_r3 = fn_80116D30();
    var_r31 = temp_r3;
    *counter = *counter + (temp_r31 - (temp_r3 - arg2));
    do {
        do {
            temp_r3_2 = fn_80116D30();
            temp_r0 = *counter;
            temp_r4 = temp_r3_2 - var_r31;
        } while (temp_r4 < temp_r0);
        var_r31 = temp_r3_2;
        *counter = temp_r0 - temp_r4;
    } while (*counter > 0);
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

void fn_8011A6A0(void* arg0) {
    s32 status = DVDGetDriveStatus();
    s32 remaining = *(s32*)((u8*)arg0 + 0xB8) - *(s32*)((u8*)arg0 + 0x90);
    if (status == 10)
        goto check_read;
    if (status >= 10)
        goto status_high;
    if (status == -1)
        goto set_flag;
    if (status < -1)
        goto check_read;
    if (status < 3)
        goto check_read;
    goto set_flag;
status_high:
    if (status >= 12)
        goto check_read;
set_flag:
    *(s32*)((u8*)arg0 + 0x20) = 1;
    goto done;
check_read:
    if (*(s32*)((u8*)arg0 + 0xC4) != 0)
        goto done;
    if (status == 0)
        goto read_valid;
    if (status == 10)
        goto read_valid;
    goto done;
done:
    return;
read_valid:
    if (*(u32*)((u8*)arg0 + 0xA0) >= 0x8000 && remaining != 0) {
        *(s32*)((u8*)arg0 + 0xC8) = *(s32*)((u8*)arg0 + 0x2C);
        *(s32*)((u8*)arg0 + 0xCC) = fn_80116D30();
        *(s32*)((u8*)arg0 + 0x24) = 1;
        if ((u32)remaining > 0x8000)
            remaining = 0x8000;
        else if (remaining & 0x1F) {
            s32 pad = (-remaining) & 0x1F;
            *(s32*)((u8*)arg0 + 0x94) = pad;
            remaining += pad;
        }
        DVDReadAsyncPrio((u8*)arg0 + 0x54, *(s32*)((u8*)arg0 + 0xAC), remaining,
            *(s32*)((u8*)arg0 + 0xB4) + (*(s32*)((u8*)arg0 + 0x90) - *(s32*)((u8*)arg0 + 0x94)),
            fn_8011A4F8, 0);
        goto done;
    }
    *(s32*)((u8*)arg0 + 0x48) = *(s32*)((u8*)arg0 + 0x4C);
    goto done;
}

s32 fn_8011A7CC(DVDFileInfo *info) {
    s32 *p = (s32 *)info;
    s32 status;

    if (p[0x20 / 4] != 0) return 0;
    if (p[0x50 / 4] != 0) return 0;
    status = DVDGetDriveStatus();
    if (status < 3) {
        if (status == 0) goto call_callback;
        if (status >= 0) goto done;
        if (status < -1) goto done;
        goto set_error;
    }
    if (status == 11) goto set_error;
    if (status >= 11) goto done;
    if (status < 10) goto set_error;
    goto done;

call_callback:
    fn_8011A6A0(info);
    goto done;
set_error:
    p[0x20 / 4] = 1;
done:
    return p[0x24 / 4];
}

#pragma push
#pragma dont_inline on
s32 fn_8011A870(void *arg0, s32 arg1) {
    register volatile s32 *p = (volatile s32 *)arg0;
    register volatile s32 *wait = (volatile s32 *)((u8 *)arg0 + 0x24);
    register s32 result;
    if (arg1 & 1) {
        if (p[0x50 / 4] == 0)
            p[0x50 / 4] = 1;
        if (arg1 & 0x80000000) {
            do {
            } while (*wait != 0);
        }
    } else if (arg1 & 2) {
        if ((u32)p[0x50 / 4] == 1U)
            p[0x50 / 4] = 0;
        if (arg1 & 0x80000000)
            fn_8011A7CC(arg0);
    }
    result = p[0x50 / 4];
    return result;
}
#pragma pop
extern u32 fn_8011A240(void *, u32, s32, u32);
extern void fn_8011A45C(void *, s32, s32);
extern void fn_8011A1A0(u32 *, u32);
u32 fn_8011A8FC(void *arg0, s32 arg1, s32 arg2, void *arg3, u32 arg4) {
              register s32 var_r29 = arg2;
              register u32 var_r26 = arg4;
              s32 var_r25 = (s32)arg3;
              register u32 var_r28 = 0;
              s32 temp_r27 = var_r25;
                register s32 var_r31;
              register volatile u32 *var_r30;
              u32 temp_r0;
       u32 temp_r3;
        u32 temp_r6;
              u32 temp_r4;
              u32 temp_r5;
              register u32 temp_r23;
          
              if (*(s32 *)((u8 *)arg0 + 0x20) != 0)
                  return 0;
              var_r31 = fn_80116D30();
              if (var_r29 != -1) {
                  temp_r4 = *(u32 *)((u8 *)arg0 + 0x98);
                  if (temp_r4 != (u32)var_r29) {
                      if ((u32)var_r29 > temp_r4) {
                          if ((u32)var_r29 <= *(u32 *)((u8 *)arg0 + 0x90)) {
                              BOOL interrupts = OSDisableInterrupts();
                              temp_r6 = (u32)var_r29 - *(u32 *)((u8 *)arg0 + 0x98);
                              *(u32 *)((u8 *)arg0 + 0xA0) += temp_r6;
                              temp_r4 = *(u32 *)((u8 *)arg0 + 0x9C) + temp_r6;
                              *(u32 *)((u8 *)arg0 + 0x98) = (u32)var_r29;
                              *(u32 *)((u8 *)arg0 + 0x4C) -= temp_r6;
                              *(u32 *)((u8 *)arg0 + 0x9C) = temp_r4;
                              if (temp_r4 > *(u32 *)((u8 *)arg0 + 0xA8))
                                  *(u32 *)((u8 *)arg0 + 0x9C) =
                                      temp_r4 - *(u32 *)((u8 *)arg0 + 0x40);
                              OSRestoreInterrupts(interrupts);
                          } else {
                              goto reset_seek;
                          }
                      } else {
                          goto reset_seek;
                      }
                  }
              }
              goto seek_done;
          reset_seek:
              fn_8011A330(arg0);
              {
                  BOOL interrupts = OSDisableInterrupts();
               temp_r0 = *(u32 *)((u8 *)arg0 + 0xA4);
               temp_r4 = 0;
               *(u32 *)((u8 *)arg0 + 0x90) = (u32)var_r29;
               temp_r5 = *(u32 *)((u8 *)arg0 + 0x40);
               *(u32 *)((u8 *)arg0 + 0x98) = (u32)var_r29;
               *(u32 *)((u8 *)arg0 + 0xA0) = temp_r5;
               *(u32 *)((u8 *)arg0 + 0x4C) = temp_r4;
               *(u32 *)((u8 *)arg0 + 0x9C) = temp_r0;
               *(u32 *)((u8 *)arg0 + 0xAC) = temp_r0;
                  OSRestoreInterrupts(interrupts);
              }
          seek_done:
              if (*(u32 *)((u8 *)arg0 + 0xA4) == 0) {
                  var_r29 = fn_80116D30();
                  var_r28 = fn_8011A240((u8 *)arg0 + 0x54,
                                        *(u32 *)((u8 *)arg0 + 0x90),
                                        (s32)var_r25, var_r26);
                  if (var_r28 < var_r26) {
                      *(s32 *)((u8 *)arg0 + 0x20) = 1;
                      fn_8011A330(arg0);
                  }
                  var_r30 = (u32 *)((u8 *)arg0 + 0x98);
                  *(u32 *)((u8 *)arg0 + 0x90) += var_r28;
                  *var_r30 += var_r28;
                  *(u32 *)((u8 *)arg0 + 0x28) += var_r28;
                  if (*(s32 *)((u8 *)arg0 + 0xBC) != 0)
                      fn_8011A45C(arg0, var_r28, var_r29);
                  temp_r3 = fn_80116D30();
          temp_r5 = *(u32 *)((u8 *)arg0 + 0x30);
          temp_r4 = temp_r3 - var_r29;
          temp_r0 = temp_r3 - var_r31;
          temp_r3 = temp_r5 + temp_r4;
          *(u32 *)((u8 *)arg0 + 0x30) = temp_r3;
          temp_r3 = *(u32 *)((u8 *)arg0 + 0x34);
          temp_r0 = temp_r3 + temp_r0;
          *(u32 *)((u8 *)arg0 + 0x34) = temp_r0;
              } else {
                  var_r30 = (u32 *)((u8 *)arg0 + 0x98);
                  goto loop_check;
              loop_body:
                  fn_8011A6A0(arg0);
                  var_r29 = *(s32 *)((u8 *)arg0 + 0x4C);
                  if (var_r29 != 0) {
                      if ((u32)var_r29 > var_r26)
                          var_r29 = (s32)var_r26;
                      var_r26 -= var_r29;
                      var_r28 += var_r29;
                      temp_r4 = *(u32 *)((u8 *)arg0 + 0x9C);
                      temp_r23 = *(u32 *)((u8 *)arg0 + 0xA8) - temp_r4;
                      *var_r30 += var_r29;
                      if (temp_r23 <= (u32)var_r29) {
                          memcpy((void *)var_r25, (void *)temp_r4, temp_r23);
                          var_r25 += temp_r23;
                          var_r29 -= temp_r23;
                          *(u32 *)((u8 *)arg0 + 0x9C) = *(u32 *)((u8 *)arg0 + 0xA4);
                          {
                              BOOL interrupts = OSDisableInterrupts();
                              *(u32 *)((u8 *)arg0 + 0x4C) -= temp_r23;
                              *(u32 *)((u8 *)arg0 + 0xA0) += temp_r23;
                              OSRestoreInterrupts(interrupts);
                          }
                      }
                      if (var_r29 != 0) {
                          memcpy(var_r25, (void *)*(u32 *)((u8 *)arg0 + 0x9C), var_r29);
                          var_r25 += var_r29;
                          * (u32 *)((u8 *)arg0 + 0x9C) += var_r29;
                          {
                              BOOL interrupts = OSDisableInterrupts();
                              *(u32 *)((u8 *)arg0 + 0x4C) -= var_r29;
                              *(u32 *)((u8 *)arg0 + 0xA0) += var_r29;
                              OSRestoreInterrupts(interrupts);
                          }
                      }
                  }
              loop_check:
                  if (var_r26 != 0 && *(s32 *)((u8 *)arg0 + 0x20) == 0)
                      goto loop_body;
                  *(s32 *)((u8 *)arg0 + 0x34) += fn_80116D30() - var_r31;
              }
          
              temp_r4 = *(u32 *)((u8 *)arg0 + 0xB8) - *var_r30;
             if (temp_r4 < *(u32 *)((u8 *)arg0 + 0x40)) {
                 *(u32 *)((u8 *)arg0 + 0x48) = temp_r4;
             } else {
                 *(u32 *)((u8 *)arg0 + 0x48) =
                     *(u32 *)((u8 *)arg0 + 0x40);
             }
              if (*(volatile u32 *)((u8 *)arg0 + 0x4C) + 0x8000 >
                   *(volatile u32 *)((u8 *)arg0 + 0x48))
                   *(u32 *)((u8 *)arg0 + 0x48) =
                       *(volatile u32 *)((u8 *)arg0 + 0x4C);
              fn_8011A1A0((u32 *)temp_r27, var_r28);
              return var_r28;
         }

#pragma dont_inline reset
s32 fn_8011AC04(s32 arg0, s32 arg1) {
    return (arg1 + 0x7FFF) & 0xFFFF8000;
}

void fn_8011AC10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 interruptState = OSDisableInterrupts();
    s32 sum;
    s32 *p = (s32 *)arg0;
    arg2 &= 0xFFFF8000;
    sum = arg1 + arg2;
    p[0xA0 / 4] = arg2;
    p[0x40 / 4] = arg2;
    p[0xA4 / 4] = arg1;
    p[0x9C / 4] = arg1;
    p[0xAC / 4] = arg1;
    p[0xA8 / 4] = sum;
    p[0x4C / 4] = 0;
    p[0xB8 / 4] = arg3;
    p[0xBC / 4] = arg4;
    p[0xD0 / 4] = (s32)arg0;
    OSRestoreInterrupts(interruptState);
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

extern u32 fn_8011A388(void*, s32, s32, u32);
extern u32 fn_8011A8FC(void *, s32, s32, void *, u32);
extern s32 fn_8011AC04(s32, s32);
extern void fn_8011AC10(void*, s32, s32, s32, s32);
extern s32 fn_8011A7CC(DVDFileInfo*);
extern void fn_8011AC84(void*);
extern s32 fn_8011A870(void*, s32);
s32 fn_8011ACC4(void* arg0, void* arg1, s32 arg2) {
    memset(arg0, 0, 0x144);
    if (arg2 & 0x800000) {
        u32 v0 = *(u32*)((u8*)arg1 + 0x00);
        u32 v1 = *(u32*)((u8*)arg1 + 0x04);
        u32 v2 = *(u32*)((u8*)arg1 + 0x08);
        u32 v3 = *(u32*)((u8*)arg1 + 0x0C);
        u32 v4 = *(u32*)((u8*)arg1 + 0x10);
        u32 v5 = *(u32*)((u8*)arg1 + 0x14);
        u32 v6 = *(u32*)((u8*)arg1 + 0x18);
        u32 v7 = *(u32*)((u8*)arg1 + 0x1C);
        u32 v8 = *(u32*)((u8*)arg1 + 0x20);
        u32 v9 = *(u32*)((u8*)arg1 + 0x24);
        u32 v10 = *(u32*)((u8*)arg1 + 0x28);
        u32 size = *(u32*)((u8*)arg1 + 0x2C);
        u32 v12 = *(u32*)((u8*)arg1 + 0x30);
        u32 v13 = *(u32*)((u8*)arg1 + 0x34);
        u32 v14 = *(u32*)((u8*)arg1 + 0x38);
        *(u32*)((u8*)arg0 + 0x54) = v0;
        *(u32*)((u8*)arg0 + 0x58) = v1;
        *(u32*)((u8*)arg0 + 0x5C) = v2;
        *(u32*)((u8*)arg0 + 0x60) = v3;
        *(u32*)((u8*)arg0 + 0x64) = v4;
        *(u32*)((u8*)arg0 + 0x68) = v5;
        *(u32*)((u8*)arg0 + 0x6C) = v6;
        *(u32*)((u8*)arg0 + 0x70) = v7;
        *(u32*)((u8*)arg0 + 0x74) = v8;
        *(u32*)((u8*)arg0 + 0x78) = v9;
        *(u32*)((u8*)arg0 + 0x7C) = v10;
        *(u32*)((u8*)arg0 + 0x80) = size;
        *(u32*)((u8*)arg0 + 0x84) = v12;
        *(u32*)((u8*)arg0 + 0x88) = v13;
        *(u32*)((u8*)arg0 + 0x8C) = v14;
        *(u32*)((u8*)arg0 + 0xB0) = 1;
        *(u32*)((u8*)arg0 + 0xB4) = size;
    } else {
        if (DVDConvertPathToEntrynum(arg1) == -1) return 0;
        if (DVDFastOpen((u8*)arg0 + 0x54) == 0) return 0;
    }
    ((void**)arg0)[0] = fn_8011A388;
    ((void**)arg0)[1] = fn_8011A8FC;
    ((void**)arg0)[2] = fn_8011AC04;
    ((void**)arg0)[3] = fn_8011AC10;
    ((void**)arg0)[4] = fn_8011A7CC;
    ((void**)arg0)[5] = fn_8011AC84;
    ((void**)arg0)[6] = fn_8011A870;
    return 1;
}

f32 fn_8011AE18(s32 arg0) {
    s32 magnitude;
    f32 temp;
    magnitude = (s32)(((u32)arg0 & ~0x10000000) >> 5);
    temp = (f32)magnitude * lbl_80329D48[(u32)arg0 & 0x1F];
    if (arg0 & 0x10000000) {
        temp = -temp;
    }
    return temp;
}

void fn_8011AE68(s32 out, f32 *in, u32 count, f32 scale) {
    u16 *dest = (u16 *)(out - 2);
    while (count != 0) {
        s32 value = (s32)(*in * scale);
        if (value < -0x8000) value = -0x8000;
        if (value > 0x7FFF) value = 0x7FFF;
        *++dest = (u16)(value + 0x7FFF);
        in++;
        count--;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_8011AED8(s32 outArg, f32 *in, u32 count, f32 scale) {
    s16 *dest = (s16 *)(outArg - 2);
    f32 *second = in + count;

    if (count != 0) {
        do {
            s32 left = (s32)(in[0] * scale);
            s32 right = (s32)(second[0] * scale);
            left = left < -0x8000 ? -0x8000 : left;
            left = left > 0x7FFF ? 0x7FFF : left;
            right = right < -0x8000 ? -0x8000 : right;
            right = right > 0x7FFF ? 0x7FFF : right;
            dest[1] = (s16)left;
            dest[2] = (s16)right;
            dest += 2;
            in++;
            second++;
        } while (--count);
    }
}
#pragma pop
extern u8 lbl_80329B50[];
extern f32 lbl_805611E0;
void fn_8011AF94(f32 *arg0, s32 arg1, void *arg2, f32 *arg3, s32 arg4) {
    u32 var_r29;
    s32 var_r28;
    f32 *var_r27;
    u32 *var_r26;
    u32 var_r25;
    u32 var_r24;
    f32 *var_r4;
    f32 *var_r4_2;
    f32 *var_r8;
    f32 temp_f31;
    f32 var_f1;
    f32 var_f29;
    f32 var_f28;
    u32 *var_r5;
    u32 *var_r5_2;
    u32 *var_r7;
    s32 temp_r0;
    s32 temp_r18;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r5_3;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_ctr;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r5_3;
    u32 temp_r10;
    u32 temp_r5;
    u32 temp_r5_2;
    u32 temp_r9;
    u32 var_r0;
    u32 var_r24_2;
    u32 var_r3;
    u32 var_r4_3;

    var_f28 = lbl_805611E0;
    var_f29 = var_f28;
    var_r26 = ((BitReader8011 *)arg2)->next;
    var_r25 = ((BitReader8011 *)arg2)->value;
    var_r24 = ((BitReader8011 *)arg2)->count;
    var_r4 = arg3;
    var_r5 = (u32 *)arg4;
    var_r28 = 0;
    goto init_test;
init_body:
    var_f29 = *var_r4;
    var_r4++;
    var_r5++;
    var_r28++;
    var_f28 = -var_f29;
init_test:
    var_r0 = (u32)*var_r5 << 1;
    if (var_r0 < 2U) goto init_body;

    temp_f31 = lbl_805611E0;
    var_r27 = (f32 *)((u8 *)arg0 + 8);
    var_r3 = 2U;
    goto outer_test;

decode:
    if (var_r24 == 0) {
        var_r0 = *var_r26;
        var_r24 = 0x1F;
        var_r26++;
        var_r25 = var_r0 >> 1U;
    } else {
        var_r0 = var_r25;
        var_r25 = var_r25 >> 1U;
        var_r24--;
    }
    if (var_r0 & 1) {
        if (var_r24 < 4U) {
            temp_r5 = *var_r26;
            temp_r0 = 4 - var_r24;
            var_r26++;
            temp_r4 = temp_r5 << var_r24;
            var_r24 += 0x1C;
            temp_r4_2 = var_r25 | temp_r4;
            var_r25 = temp_r5 >> temp_r0;
            var_r0_2 = temp_r4_2 & 0xF;
        } else {
            var_r0_2 = var_r25 & 0xF;
            var_r25 = var_r25 >> 4U;
            var_r24 -= 4;
        }
        var_r29 = var_r3 + (lbl_80329B50[var_r0_2] * 8U);
    } else {
        var_r29 = var_r3 + 8U;
    }
    if (var_r29 > (u32)arg1) var_r29 = arg1;

    if (var_r24 < 4U) {
        temp_r5_2 = *var_r26;
        temp_r0 = 4 - var_r24;
        var_r26++;
        temp_r4 = temp_r5_2 << var_r24;
        var_r24 += 0x1C;
        temp_r4_2 = var_r25 | temp_r4;
        var_r25 = temp_r5_2 >> temp_r0;
        var_r0_3 = temp_r4_2 & 0xF;
    } else {
        var_r0_3 = var_r25 & 0xF;
        var_r25 = var_r25 >> 4U;
        var_r24 -= 4;
    }

    if (var_r0_3 == 0) {
        temp_r18 = var_r29 - var_r3;
        memset(var_r27, 0, temp_r18 * 4);
        var_r4_2 = arg3 + var_r28;
        var_r3 = var_r29;
        var_r27 += temp_r18;
        var_r5_2 = (u32 *)arg4 + var_r28;
        while (var_r29 > (u32)(*var_r5_2 * 2)) {
            var_f29 = *var_r4_2;
            var_r4_2++;
            var_r5_2++;
            var_r28++;
            var_f28 = -var_f29;
        }
    } else {
        temp_r6 = var_r28 * 4;
        var_r7 = (u32 *)arg4 + var_r28;
        var_r8 = arg3 + var_r28;
        temp_r9 = -1U >> (0x20 - var_r0_3);
        temp_r18 = var_r29 - var_r3;
        if (var_r3 < var_r29) {
            for (var_ctr = 0; var_ctr < temp_r18; var_ctr++) {
                if (var_r3 == (u32)(*var_r7 * 2)) {
                    var_f29 = *var_r8;
                    var_r7++;
                    var_r8++;
                    var_r28++;
                    var_f28 = -var_f29;
                }
                if ((u32)var_r24 < var_r0_3) {
                    temp_r10 = *var_r26;
                    var_r26++;
                    temp_r6_2 = var_r25 | (temp_r10 << var_r24);
                    var_r25 = temp_r10 >> (var_r0_3 - var_r24);
                    var_r5_3 = temp_r9 & temp_r6_2;
                    var_r24 = var_r24 + 0x20 - var_r0_3;
                } else {
                    var_r5_3 = var_r25 & temp_r9;
                    var_r25 = var_r25 >> var_r0_3;
                    var_r24 -= var_r0_3;
                }
                if (var_r5_3 != 0) {
                    if (var_r24 == 0) {
                        var_r4_3 = *var_r26;
                        var_r24 = 0x1F;
                        var_r26++;
                        var_r25 = var_r4_3 >> 1U;
                    } else {
                        var_r4_3 = var_r25;
                        var_r25 = var_r25 >> 1U;
                        var_r24--;
                    }
                    if (var_r4_3 & 1) var_f1 = var_f28;
                    else var_f1 = var_f29;
                    *var_r27 = (f32)var_r5_3 * var_f1;
                    var_r27++;
                } else {
                    *var_r27 = temp_f31;
                    var_r27++;
                }
                var_r3++;
            }
        }
    }
    goto outer_test;

outer_test:
    if (var_r3 < (u32)arg1) goto decode;
    ((BitReader8011 *)arg2)->next = var_r26;
    ((BitReader8011 *)arg2)->value = var_r25;
    ((BitReader8011 *)arg2)->count = var_r24;
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

extern u32 lbl_80329B60[25];
extern f64 lbl_805611E8;
extern f64 lbl_805611F0;
extern f32 lbl_805611F8;
extern f64 lbl_80561200;
void *fn_8011B584(u32 arg0, s32 arg1, s32 arg2, s32 arg_sp0) {
    u32 *sp18;
    u32 *sp14;
    u32 *sp10;
    u32 *spC;
    u32 *sp8;
    f32 var_f0;
    f32 var_f1;
    f64 temp_f4;
    f64 temp_f4_2;
    f64 temp_f4_3;
    f64 temp_f4_4;
    f64 temp_f3;
    f64 temp_f3_2;
    u32 var_r31;
    u32 var_r30;
    u32 temp_r29;
    u32 temp_r28;
    u32 temp_r27;
    s32 temp_r26;
    u32 *var_r5;
    s32 var_r6;
    s32 var_r7;
    u32 *var_r4;
    s32 var_r24;
    u32 var_r3;
    u32 *temp_r4;
    void *temp_r3;
    s32 var_ctr;
    u32 var_ctr_2;

    var_r3 = arg0;
    var_r24 = arg1;
    if (var_r3 >= 0xAC44U) {
        var_r30 = 0x800;
    } else {
        var_r30 = 0x200;
        if (var_r3 >= 0x5622U) {
            var_r30 = 0x400;
        }
    }
    temp_r26 = arg2 & 1;
    temp_r28 = var_r30 * arg1 * 2;
    if (temp_r26 == 0) {
        var_r3 *= arg1;
        var_r24 = 1;
        var_r30 *= arg1;
    }
    temp_r29 = var_r30 >> 1U;
    temp_r27 = (u32) (var_r3 + 1) >> 1U;
    var_r4 = lbl_80329B60;
    var_r31 = 0U;
    for (var_ctr = 0; var_ctr < 5; var_ctr++) {
        if (var_r4[0] >= temp_r27) break;
        var_r31++;
        if (var_r4[1] >= temp_r27) break;
        var_r31++;
        if (var_r4[2] >= temp_r27) break;
        var_r31++;
        if (var_r4[3] >= temp_r27) break;
        var_r31++;
        if (var_r4[4] >= temp_r27) break;
        var_r4 += 5;
        var_r31++;
    }
    fn_8011FE20(&sp18, (var_r31 + 1) * 4);
    if ((f32) temp_r29 > lbl_805611E0) {
        temp_f4 = __frsqrte((f32) temp_r29);
        temp_f3 = (f64) (f32) temp_r29;
        temp_f3_2 = temp_f4 * temp_f4;
        temp_f4_2 = lbl_805611E8 * temp_f4;
        temp_f4_3 = temp_f3 * temp_f3_2;
        temp_f4_4 = lbl_805611F0 - temp_f4_3;
        temp_f4_2 = temp_f4_2 * temp_f4_4;
        temp_f3 = (f64) (f32) temp_r29;
        temp_f3_2 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = lbl_805611E8 * temp_f4_2;
        temp_f4_4 = temp_f3 * temp_f3_2;
        temp_f3 = lbl_805611F0 - temp_f4_4;
        temp_f4_2 = temp_f4_3 * temp_f3;
        temp_f4 = (f64) (f32) temp_r29;
        temp_f3 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = lbl_805611E8 * temp_f4_2;
        temp_f4_4 = temp_f4 * temp_f3;
        temp_f4 = lbl_805611F0 - temp_f4_4;
        temp_f3 = temp_f4_3 * temp_f4;
        var_f0 = (f32) (temp_f3 * (f64) (f32) temp_r29);
    } else {
        var_f0 = (f32) temp_r29;
    }
    fn_8011FE20(&sp14, ((s32) var_f0 + 2) * 4);
    if (temp_r26 != 0) {
        fn_8011FE20(&sp10, (u32) (var_r30 * 0x14) >> 2U);
    } else {
        fn_8011FE20(&sp10, (temp_r29 * 4) - 1);
    }
    fn_8011FE20(&spC, temp_r28 >> 1U);
    fn_8011FE20(&sp8, temp_r28);
    temp_r3 = fn_8011FF2C(0x34);
    if (temp_r3 == NULL) {
        return NULL;
    }
    memset(temp_r3, 0, 0x34);
    M2C_FIELD(temp_r3, u32 **, 0x20) = sp18;
    M2C_FIELD(temp_r3, u32 **, 0x24) = sp14;
    M2C_FIELD(temp_r3, u32 **, 0x28) = sp10;
    M2C_FIELD(temp_r3, u32 **, 0x2C) = spC;
    M2C_FIELD(temp_r3, u32 **, 0x14) = sp8;
    M2C_FIELD(temp_r3, s32 *, 0x30) = arg2;
    M2C_FIELD(temp_r3, s32 *, 0x10) = var_r24;
    M2C_FIELD(temp_r3, u32 *, 0x1C) = var_r31;
    M2C_FIELD(temp_r3, u32 *, 0) = var_r30;
    M2C_FIELD(temp_r3, u32 *, 8) = temp_r28;
    M2C_FIELD(temp_r3, u32 *, 0xC) = (u32) (temp_r28 >> 4U);
    if ((f32) var_r30 > lbl_805611E0) {
        temp_f4 = __frsqrte((f32) var_r30);
        temp_f3 = (f64) (f32) var_r30;
        temp_f3_2 = temp_f4 * temp_f4;
        temp_f4_2 = lbl_805611E8 * temp_f4;
        temp_f4_3 = temp_f3 * temp_f3_2;
        temp_f4_4 = lbl_805611F0 - temp_f4_3;
        temp_f4_2 = temp_f4_2 * temp_f4_4;
        temp_f3 = (f64) (f32) var_r30;
        temp_f3_2 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = lbl_805611E8 * temp_f4_2;
        temp_f4_4 = temp_f3 * temp_f3_2;
        temp_f3 = lbl_805611F0 - temp_f4_4;
        temp_f4_2 = temp_f4_3 * temp_f3;
        temp_f4 = (f64) (f32) var_r30;
        temp_f3 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = lbl_805611E8 * temp_f4_2;
        temp_f4_4 = temp_f4 * temp_f3;
        temp_f4 = lbl_805611F0 - temp_f4_4;
        temp_f3 = temp_f4_3 * temp_f4;
        var_f1 = (f32) (temp_f3 * (f64) (f32) var_r30);
    } else {
        var_f1 = (f32) var_r30;
    }
    var_r5 = lbl_80329B60;
    var_r7 = 0;
    var_r6 = 0;
    M2C_FIELD(temp_r3, f32 *, 4) = (f32) (lbl_805611F8 / var_f1);
    for (var_ctr_2 = 0; var_ctr_2 < var_r31; var_ctr_2++) {
        *(u32 *)((u8 *)M2C_FIELD(temp_r3, u32 **, 0x20) + var_r6) = (u32) (temp_r29 * *var_r5) / temp_r27;
        temp_r4 = M2C_FIELD(temp_r3, u32 **, 0x20);
        if (*(u32 *)((u8 *)temp_r4 + var_r6) == 0) {
            *(u32 *)((u8 *)temp_r4 + var_r6) = 1;
        }
        var_r5++;
        var_r6 += 4;
        var_r7++;
    }
    M2C_FIELD(temp_r3, u32 **, 0x20)[var_r7] = temp_r29;
    *M2C_FIELD(temp_r3, u32 **, 0x24) = 0;
    M2C_FIELD(temp_r3, s32 *, 0x18) = 1;
    return temp_r3;
}

void fn_8011B94C(void *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 *arg4, s32 arg5, u32 *arg6, u32 arg7, f32 arg8, s32 arg9) {
    u8 *p = (u8 *)arg0;
    u32 count = *(u32 *)(p + 0xC) >> 1;
    u32 i;
    s32 result = fn_8011B2AC(*(s32 *)p, *(u32 *)(p + 0x10), *(s32 *)(p + 0x30), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28), *(s32 *)(p + 0x14), arg6, *(u32 *)(p + 0x1C), *(f32 *)(p + 4), *(u32 *)(p + 0x20));
    if (*(s32 *)(p + 0x18)) *(s32 *)(p + 0x18) = 0;
    else for (i = 0; i < count; i++) {
        s16 *a = *(s16 **)(p + 0x14);
        s16 *b = *(s16 **)(p + 0x2C);
        a[i] = (s16)(((u32)i * a[i] + (u32)(count - i) * b[i]) / count);
    }
    memcpy(*(void **)(p + 0x2C), (u8 *)*(void **)(p + 0x14) + (*(u32 *)(p + 8) - *(u32 *)(p + 0xC)), *(u32 *)(p + 0xC));
    if (arg2) *arg2 = *(u32 *)(p + 8) - *(u32 *)(p + 0xC);
    if (arg1) *arg1 = (s32)*(void **)(p + 0x14);
    if (arg4) *arg4 = arg6[0] + result;
}

void fn_8011BC48(void) {
    fn_80120084();
}

s32 fn_8011BC4C(void *arg0, void *arg1) {
    void *next;
    void *prev;
    if (arg0 == NULL) return 0;
    prev = *(void **)((u8 *)arg0 + 0x30);
    if (prev == arg1) {
        *(void **)((u8 *)arg0 + 0x30) = *(void **)prev;
        return 1;
    }
    next = *(void **)prev;
    do {
        if (next == arg1) {
            *(void **)prev = *(void **)arg1;
            return 1;
        }
        prev = next;
        next = *(void **)prev;
    } while (next != NULL);
    return 0;
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

void fn_8011BD20(s32 arg0) {
    struct Node {
        struct Node *next;
        struct Node *orderedNext;
        s32 result;
        s32 enabled;
        s32 unk_0x10;
        s32 (*run)(struct Node *, s32);
        void (*finish)(struct Node *, s32);
    };
    struct Node *node;
    struct Node *pending;
    volatile s32 *count;
    volatile s32 *state;
    s32 newCount;
    s32 stateValue;

    count = (volatile s32 *)(arg0 + 0x34);
    state = (volatile s32 *)arg0;
    newCount = *count;
    stateValue = *state;
    newCount = newCount + 1;
    *count = newCount;
    if (stateValue == 1) {
        node = *(struct Node **)(arg0 + 0x30);
        pending = 0;
        while (node != 0) {
            if (*(s32 *)arg0 != 1) {
                return;
            }
            if (node->enabled == 1) {
                node->result = node->run(node, *count);
                if (node->result != 0) {
                    fn_8011BCAC((void **)&pending, node);
                }
            }
            node = node->next;
        }
        node = pending;
        while (node != 0) {
            node->finish(node, *count);
            node = node->orderedNext;
        }
    }
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
    register s32 zero;
    register s32 sign;
    register s32 one;
    ptr = fn_8011FFC4(0x40);
    if (ptr != NULL) {
        memset(ptr, 0, 0x40);
        zero = 0;
        sign = arg0 >> 31;
        one = 1;
        *(s32 *)((u8 *)ptr + 0x00) = zero;
        *(s32 *)((u8 *)ptr + 0x04) = one;
        arg0 = (sign ^ arg0) - sign;
        *(s32 *)((u8 *)ptr + 0x30) = zero;
        *(s32 *)((u8 *)ptr + 0x34) = one;
        *(s32 *)((u8 *)ptr + 0x38) = zero;
        *(s32 *)((u8 *)ptr + 0x3C) = arg0;
    }
    return ptr;
}

void fn_8011BEC8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 interruptState = OSDisableInterrupts();
    s32 one = 1;
    s32 old;
    *(s32 *)((u8 *)arg1 + 0xC) = one;
    *(s32 *)((u8 *)arg1 + 0x14) = arg2;
    *(s32 *)((u8 *)arg1 + 0x18) = arg3;
    *(s32 *)((u8 *)arg1 + 0x10) = 0;
    *(void **)arg1 = *(void **)((u8 *)arg0 + 0x30);
    old = *(s32 *)((u8 *)arg0 + 0x38);
    *(void **)((u8 *)arg0 + 0x30) = arg1;
    *(s32 *)((u8 *)arg0 + 0x38) = old + 1;
    OSRestoreInterrupts(interruptState);
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

s32 fn_8011C0E0(s32 arg0) {
    goto check;
yield:
    OSYieldThread();
check:
    if (fn_8011C06C((void*)arg0) == 0)
        goto yield;
}

void fn_8011C120(void *arg0) {
    if (arg0 != 0) {
        BOOL enabled = OSDisableInterrupts();
        s32 count = *(volatile s32 *)((u8 *)arg0 + 4);
        *(volatile s32 *)((u8 *)arg0 + 4) = count - 1;
        if (*(volatile s32 *)((u8 *)arg0 + 4) == 0) {
            if (*(volatile s32 *)arg0 == 0) {
                u64 time = (u64)OSGetTime();
                u32 time_word = (u32)time;
                u32 period = (0x3E8U / *(u32 *)((u8 *)arg0 + 0x3C)) *
                             (*(volatile u32 *)0x800000F8 / 4U / 1000U);
                ((void (*)(void *, u32, u32, u32, u32, u32, void (*)(s32)))OSSetPeriodicAlarm)(
                    (u8 *)arg0 + 8, time_word, (u32)(time >> 32),
                    time_word, 0, period, fn_8011BDF0);
            }
            *(s32 *)arg0 = 1;
        }
        OSRestoreInterrupts(enabled);
    }
}

#pragma dont_inline on
u32 fn_8011C1E0(s32 arg0, void *arg1) {
    BOOL enabled;
    s32 temp_r4;
    s32 temp_r4_2;

    if (arg0 != 0 && arg1 != 0 &&
        *(s32 *)((u8 *)arg1 + 0x18) != 0 &&
        *(s32 *)((u8 *)arg1 + 0x14) != 0) {
        enabled = OSDisableInterrupts();
        if (*(s32 *)((u8 *)arg1 + 0xC) == 1)
            *(s32 *)((u8 *)arg1 + 0xC) = 2;
        temp_r4 = *(s32 *)((u8 *)arg1 + 0x10);
        *(s32 *)((u8 *)arg1 + 0x10) = temp_r4 + 1;
        OSRestoreInterrupts(enabled);
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
        BOOL enabled;
        volatile s32 *p = (volatile s32 *)((u8 *)arg1 + 0x10);
        enabled = OSDisableInterrupts();
        *p = *p - 1;
        if (*p == 0)
            *(s32 *)((u8 *)arg1 + 0xC) = 1;
        OSRestoreInterrupts(enabled);
    }
}

extern s32 fn_8011C0E0();
void fn_8011C364(s32 arg0) {
    if (arg0 != 0) {
        fn_8011C0E0();
        OSCancelAlarm((OSAlarm *)(arg0 + 8));
        fn_80120084(arg0);
    }
}

void fn_8011C3A8(s32 arg0, void *arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    *(s32 *)((u8 *)arg1 + 0x28) = 0x20 - __cntlzw((u16)(arg2 + ((arg3 >> 3) * arg5) - 1));
    *(s32 *)((u8 *)arg1 + 0) = 0;
    *(s32 *)((u8 *)arg1 + 4) = 0;
    *(s32 *)((u8 *)arg1 + 8) = arg4;
    if (arg6)
        *(s32 *)((u8 *)arg1 + 0xC) = 1 << (arg4 - 1);
    else
        *(s32 *)((u8 *)arg1 + 0xC) = 0;
    *(s32 *)((u8 *)arg1 + 0x2C) = arg0;
}

s32 fn_8011C400(u32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    s32 var_r7;
    s32 var_r8;
    s32 var_r9;
    u32 var_r3;
    u8 *var_r4;
    u8 *var_r5;
    u8 *var_r6;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;

    var_r3 = arg0;
    var_r4 = arg1;
    var_r5 = arg2;
    var_r6 = arg3;
    var_r7 = arg4;
    var_r8 = var_r7;
    var_r9 = 0;
loop_1:
    var_r9 += 1;
    if (var_r3 & 1) {
        temp_r0 = *var_r6;
        var_r8 -= 1;
        var_r6 += 1;
        *var_r4 = temp_r0;
        var_r4 += 1;
    } else {
        temp_r0_2 = *var_r5;
        var_r7 -= 1;
        var_r5 += 1;
        *var_r4 = temp_r0_2;
        var_r4 += 1;
    }
    var_r3 = var_r3 >> 1U;
    if ((var_r7 != 0) && (var_r8 != 0)) {
        goto loop_1;
    }
    if (var_r7 != 0) {
        do {
            temp_r0_3 = *var_r5;
            var_r7 -= 1;
            var_r5 += 1;
            *var_r4 = temp_r0_3;
            var_r4 += 1;
        } while (var_r7 != 0);
    } else if (var_r8 != 0) {
        do {
            temp_r0_4 = *var_r6;
            var_r8 -= 1;
            var_r6 += 1;
            *var_r4 = temp_r0_4;
            var_r4 += 1;
        } while (var_r8 != 0);
    }
    return var_r9;
}

#pragma push
#pragma scheduling on
void fn_8011C4A0(s32 arg0_raw, s32 arg1_raw, s32 arg2_raw, s32 arg3_raw) {
    u8 buffers[0x20];
    register const u8 *var_r31;
    register u32 var_r29;
    register u32 var_r30;
    s32 temp_r0;
    s32 temp_r5_14;
    s32 temp_r5_15;
    s32 var_ctr;
    s32 var_ctr_2;
    s32 var_ctr_3;
    s32 var_r28;
    s32 var_r29_3;
    s32 var_r29_4;
    s32 var_r3_10;
    s32 var_r3_11;
    s32 var_r3_12;
    s32 var_r3_13;
    s32 var_r3_14;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r3_9;
    s32 var_r8;
    register s8 *var_r3;
    register u8 *var_r3_15;
    register u8 *var_r3_16;
    s32 temp_r4_2;
    s32 temp_r4_3;
    u32 var_r0_6;
    s32 var_r4;
    s32 var_r4_2;
    register s32 var_r4_3;
    u32 temp_r29;
    u32 temp_r30;
    u32 temp_r3;
    u32 temp_r3_10;
    u32 temp_r3_11;
    u32 temp_r3_12;
    u32 temp_r3_13;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 temp_r3_6;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u32 temp_r3_9;
    u32 temp_r4;
    u32 temp_r4_4;
    u32 temp_r5;
    u32 temp_r5_10;
    u32 temp_r5_11;
    u32 temp_r5_12;
    u32 temp_r5_13;
    u32 temp_r5_2;
    u32 temp_r5_3;
    u32 temp_r5_4;
    u32 temp_r5_5;
    u32 temp_r5_6;
    u32 temp_r5_7;
    u32 temp_r5_8;
    u32 temp_r5_9;
    u32 temp_r7;
    u32 temp_r9;
    u32 var_r0;
    u32 var_r0_2;
    u32 var_r0_3;
    u32 var_r0_4;
    u32 var_r0_5;
    u32 var_r29_10;
    u32 var_r29_11;
    u32 var_r29_12;
    u32 var_r29_13;
    u32 var_r29_14;
    u32 var_r29_2;
    u32 var_r29_5;
    u32 var_r29_6;
    u32 var_r29_7;
    u32 var_r29_8;
    u32 var_r29_9;
    u32 var_r30_10;
    u32 var_r30_11;
    u32 var_r30_12;
    u32 var_r30_13;
    u32 var_r30_14;
    u32 var_r30_2;
    u32 var_r30_3;
    u32 var_r30_4;
    u32 var_r30_5;
    u32 var_r30_6;
    u32 var_r30_7;
    u32 var_r30_8;
    u32 var_r30_9;
    register u32 var_r7;
    s32 var_r8_2;

    void *arg0 = (void *)arg0_raw;
    s32 *arg1 = (s32 *)arg1_raw;
    s32 *arg2 = (s32 *)arg2_raw;
    u8 *arg3 = (u8 *)arg3_raw;

    var_r29 = ((BitReader8011 *)arg0)->count;
    var_r31 = (const u8 *)((BitReader8011 *)arg0)->next;
    var_r30 = ((BitReader8011 *)arg0)->value;
    if (var_r29 < 4U) {
        temp_r7 = (*(u32 *)var_r31);
        var_r0 = 4 - var_r29;
        var_r31 += 4;
        temp_r3 = temp_r7 << var_r29;
        var_r29 += 0x1C;
        temp_r3 |= var_r30;
        var_r30 = temp_r7 >> var_r0;
        var_r8 = temp_r3 & 0xF;
    } else {
        var_r8 = var_r30 & 0xF;
        var_r30 = var_r30 >> 4U;
        var_r29 -= 4;
    }
    var_r7 = ((volatile u32 *)lbl_80329DA8)[var_r8];
    temp_r0 = ((volatile u8 *)lbl_802F6990)[var_r8];
    *(volatile s32 *)arg1 = var_r7;
    *(volatile s32 *)arg2 = temp_r0;
    if (var_r8 == 0) {
        for (var_ctr = 0; var_ctr < 16; var_ctr++)
            arg3[var_ctr] = (s8)var_ctr;
    } else {
        if (var_r29 == 0) {
            var_r0 = (*(u32 *)var_r31);
            var_r29_2 = 0x1F;
            var_r31 += 4;
            var_r30_2 = var_r0 >> 1U;
        } else {
            var_r0 = var_r30;
            var_r30_2 = var_r30 >> 1U;
            var_r29_2 = var_r29 - 1;
        }
        if (!(var_r0 & 1)) {
            if (var_r29_2 < 2U) {
                temp_r4 = (*(u32 *)var_r31);
                var_r31 += 4;
                var_r29 = var_r29_2 + 0x1E;
                var_r30 = temp_r4 >> (2 - var_r29_2);
                var_r28 = (var_r30_2 | (temp_r4 << var_r29_2)) & 3;
            } else {
                var_r28 = var_r30_2 & 3;
                var_r30 = var_r30_2 >> 2U;
                var_r29 = var_r29_2 - 2;
            }
            if (var_r28 == 0) {
                var_r4 = 0;
                for (var_ctr = 0; var_ctr < 4; var_ctr++) {
                    if (var_r29 == 0) {
                        var_r0_2 = (*(u32 *)var_r31);
                        var_r29_3 = 0x1F;
                        var_r31 += 4;
                        var_r30_3 = var_r0_2 >> 1U;
                    } else {
                        var_r0_2 = var_r30;
                        var_r30_3 = var_r30 >> 1U;
                        var_r29_3 = var_r29 - 1;
                    }
                    if (var_r0_2 & 1) {
                        *(arg3 + var_r4) = var_r4 + 1;
                        (*(s8 *)((s8 *)((arg3 + var_r4)) + (1))) = var_r4;
                    } else {
                        *(arg3 + var_r4) = var_r4;
                        (*(s8 *)((s8 *)((arg3 + var_r4)) + (1))) = (s8) (var_r4 + 1);
                    }
                    temp_r4_2 = var_r4 + 2;
                    if (var_r29_3 == 0) {
                        var_r0_3 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0_3 >> 1U;
                    } else {
                        var_r0_3 = var_r30_3;
                        var_r30 = var_r30_3 >> 1U;
                        var_r29 = var_r29_3 - 1;
                    }
                    if (var_r0_3 & 1) {
                        *(arg3 + temp_r4_2) = temp_r4_2 + 1;
                        (*(s8 *)((s8 *)((arg3 + temp_r4_2)) + (1))) = temp_r4_2;
                    } else {
                        *(arg3 + temp_r4_2) = temp_r4_2;
                        (*(s8 *)((s8 *)((arg3 + temp_r4_2)) + (1))) = (s8) (temp_r4_2 + 1);
                    }
                    var_r4 = temp_r4_2 + 2;
                }
            } else {
                var_r3 = (s8 *)buffers;
                var_r4_2 = 0;
                for (var_ctr_2 = 0; var_ctr_2 < 4; var_ctr_2++) {
                    if (var_r29 == 0) {
                        var_r0_4 = (*(u32 *)var_r31);
                        var_r29_4 = 0x1F;
                        var_r31 += 4;
                        var_r30_4 = var_r0_4 >> 1U;
                    } else {
                        var_r0_4 = var_r30;
                        var_r30_4 = var_r30 >> 1U;
                        var_r29_4 = var_r29 - 1;
                    }
                    if (var_r0_4 & 1) {
                        (*(s8 *)((s8 *)(var_r3) + (0))) = var_r4_2 + 1;
                        (*(s8 *)((s8 *)(var_r3) + (1))) = var_r4_2;
                    } else {
                        (*(s8 *)((s8 *)(var_r3) + (0))) = var_r4_2;
                        (*(s8 *)((s8 *)(var_r3) + (1))) = (s8) (var_r4_2 + 1);
                    }
                    temp_r4_3 = var_r4_2 + 2;
                    if (var_r29_4 == 0) {
                        var_r0_5 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0_5 >> 1U;
                    } else {
                        var_r0_5 = var_r30_4;
                        var_r30 = var_r30_4 >> 1U;
                        var_r29 = var_r29_4 - 1;
                    }
                    if (var_r0_5 & 1) {
                        (*(s8 *)((s8 *)(var_r3) + (2))) = (s8) (temp_r4_3 + 1);
                        (*(s8 *)((s8 *)(var_r3) + (3))) = temp_r4_3;
                    } else {
                        (*(s8 *)((s8 *)(var_r3) + (2))) = temp_r4_3;
                        (*(s8 *)((s8 *)(var_r3) + (3))) = (s8) (temp_r4_3 + 1);
                    }
                    var_r3 += 4;
                    var_r4_2 = temp_r4_3 + 2;
                }
                if ((u32) var_r28 == 1U) {
                    if ((u32) var_r29 < 3U) {
                        var_r3_2 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        var_r3_2 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(var_r3_2, (u8 *)(arg3), (u8 *)(buffers + 0), (u8 *)(buffers + 2), 2);
                    if ((u32) var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_5 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29_5 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30_5 = var_r30 >> temp_r3;
                        var_r29_5 = var_r29 - temp_r3;
                    }
                    if (var_r29_5 < 3U) {
                        var_r3_3 = (var_r30_5 | ((*(u32 *)var_r31) << var_r29_5)) & 7;
                    } else {
                        var_r3_3 = var_r30_5 & 7;
                    }
                    temp_r3_2 = fn_8011C400(var_r3_3, (u8 *)(arg3 + 4), (u8 *)(buffers + 4), (u8 *)(buffers + 6), 2);
                    if (var_r29_5 < temp_r3_2) {
                        temp_r5_2 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_6 = temp_r5_2 >> (temp_r3_2 - var_r29_5);
                        var_r29_6 = (var_r29_5 + 0x20) - temp_r3_2;
                    } else {
                        var_r30_6 = var_r30_5 >> temp_r3_2;
                        var_r29_6 = var_r29_5 - temp_r3_2;
                    }
                    if (var_r29_6 < 3U) {
                        var_r3_4 = (var_r30_6 | ((*(u32 *)var_r31) << var_r29_6)) & 7;
                    } else {
                        var_r3_4 = var_r30_6 & 7;
                    }
                    temp_r3_3 = fn_8011C400(var_r3_4, (u8 *)(arg3 + 8), (u8 *)(buffers + 8), (u8 *)(buffers + 10), 2);
                    if (var_r29_6 < temp_r3_3) {
                        temp_r5_3 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_7 = temp_r5_3 >> (temp_r3_3 - var_r29_6);
                        var_r29_7 = (var_r29_6 + 0x20) - temp_r3_3;
                    } else {
                        var_r30_7 = var_r30_6 >> temp_r3_3;
                        var_r29_7 = var_r29_6 - temp_r3_3;
                    }
                    if (var_r29_7 < 3U) {
                        var_r3_5 = (var_r30_7 | ((*(u32 *)var_r31) << var_r29_7)) & 7;
                    } else {
                        var_r3_5 = var_r30_7 & 7;
                    }
                    temp_r3_4 = fn_8011C400(var_r3_5, (u8 *)(arg3 + 0xC), (u8 *)(buffers + 12), (u8 *)(buffers + 14), 2);
                    if (var_r29_7 < temp_r3_4) {
                        temp_r5_4 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5_4 >> (temp_r3_4 - var_r29_7);
                        var_r29 = (var_r29_7 + 0x20) - temp_r3_4;
                    } else {
                        var_r30 = var_r30_7 >> temp_r3_4;
                        var_r29 = var_r29_7 - temp_r3_4;
                    }
                } else {
                    if ((u32) var_r29 < 3U) {
                        var_r3_6 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        var_r3_6 = var_r30 & 7;
                    }
                    temp_r3_5 = fn_8011C400(var_r3_6, (u8 *)(buffers + 16), (u8 *)(buffers + 0), (u8 *)(buffers + 2), 2);
                    if ((u32) var_r29 < temp_r3_5) {
                        temp_r5_5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_8 = temp_r5_5 >> (temp_r3_5 - var_r29);
                        var_r29_8 = (var_r29 + 0x20) - temp_r3_5;
                    } else {
                        var_r30_8 = var_r30 >> temp_r3_5;
                        var_r29_8 = var_r29 - temp_r3_5;
                    }
                    if (var_r29_8 < 3U) {
                        var_r3_7 = (var_r30_8 | ((*(u32 *)var_r31) << var_r29_8)) & 7;
                    } else {
                        var_r3_7 = var_r30_8 & 7;
                    }
                    temp_r3_6 = fn_8011C400(var_r3_7, (u8 *)(buffers + 20), (u8 *)(buffers + 4), (u8 *)(buffers + 6), 2);
                    if (var_r29_8 < temp_r3_6) {
                        temp_r5_6 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_9 = temp_r5_6 >> (temp_r3_6 - var_r29_8);
                        var_r29_9 = (var_r29_8 + 0x20) - temp_r3_6;
                    } else {
                        var_r30_9 = var_r30_8 >> temp_r3_6;
                        var_r29_9 = var_r29_8 - temp_r3_6;
                    }
                    if (var_r29_9 < 3U) {
                        var_r3_8 = (var_r30_9 | ((*(u32 *)var_r31) << var_r29_9)) & 7;
                    } else {
                        var_r3_8 = var_r30_9 & 7;
                    }
                    temp_r3_7 = fn_8011C400(var_r3_8, (u8 *)(buffers + 24), (u8 *)(buffers + 8), (u8 *)(buffers + 10), 2);
                    if (var_r29_9 < temp_r3_7) {
                        temp_r5_7 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_10 = temp_r5_7 >> (temp_r3_7 - var_r29_9);
                        var_r29_10 = (var_r29_9 + 0x20) - temp_r3_7;
                    } else {
                        var_r30_10 = var_r30_9 >> temp_r3_7;
                        var_r29_10 = var_r29_9 - temp_r3_7;
                    }
                    if (var_r29_10 < 3U) {
                        var_r3_9 = (var_r30_10 | ((*(u32 *)var_r31) << var_r29_10)) & 7;
                    } else {
                        var_r3_9 = var_r30_10 & 7;
                    }
                    temp_r3_8 = fn_8011C400(var_r3_9, (u8 *)(buffers + 28), (u8 *)(buffers + 12), (u8 *)(buffers + 14), 2);
                    if (var_r29_10 < temp_r3_8) {
                        temp_r5_8 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30_11 = temp_r5_8 >> (temp_r3_8 - var_r29_10);
                        var_r29_11 = (var_r29_10 + 0x20) - temp_r3_8;
                    } else {
                        var_r30_11 = var_r30_10 >> temp_r3_8;
                        var_r29_11 = var_r29_10 - temp_r3_8;
                    }
                    if ((u32) var_r28 == 2U) {
                        if (var_r29_11 < 7U) {
                            var_r3_10 = (var_r30_11 | ((*(u32 *)var_r31) << var_r29_11)) & 0x7F;
                        } else {
                            var_r3_10 = var_r30_11 & 0x7F;
                        }
                        temp_r3_9 = fn_8011C400(var_r3_10, (u8 *)(arg3), (u8 *)(buffers + 16), (u8 *)(buffers + 20), 4);
                        if (var_r29_11 < temp_r3_9) {
                            temp_r5_9 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30_12 = temp_r5_9 >> (temp_r3_9 - var_r29_11);
                            var_r29_12 = (var_r29_11 + 0x20) - temp_r3_9;
                        } else {
                            var_r30_12 = var_r30_11 >> temp_r3_9;
                            var_r29_12 = var_r29_11 - temp_r3_9;
                        }
                        if (var_r29_12 < 7U) {
                            var_r3_11 = (var_r30_12 | ((*(u32 *)var_r31) << var_r29_12)) & 0x7F;
                        } else {
                            var_r3_11 = var_r30_12 & 0x7F;
                        }
                        temp_r3_10 = fn_8011C400(var_r3_11, (u8 *)(arg3 + 8), (u8 *)(buffers + 24), (u8 *)(buffers + 28), 4);
                        if (var_r29_12 < temp_r3_10) {
                            temp_r5_10 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5_10 >> (temp_r3_10 - var_r29_12);
                            var_r29 = (var_r29_12 + 0x20) - temp_r3_10;
                        } else {
                            var_r30 = var_r30_12 >> temp_r3_10;
                            var_r29 = var_r29_12 - temp_r3_10;
                        }
                    } else {
                        if (var_r29_11 < 7U) {
                            var_r3_12 = (var_r30_11 | ((*(u32 *)var_r31) << var_r29_11)) & 0x7F;
                        } else {
                            var_r3_12 = var_r30_11 & 0x7F;
                        }
                        temp_r3_11 = fn_8011C400(var_r3_12, (u8 *)(buffers + 0), (u8 *)(buffers + 16), (u8 *)(buffers + 20), 4);
                        if (var_r29_11 < temp_r3_11) {
                            temp_r5_11 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30_13 = temp_r5_11 >> (temp_r3_11 - var_r29_11);
                            var_r29_13 = (var_r29_11 + 0x20) - temp_r3_11;
                        } else {
                            var_r30_13 = var_r30_11 >> temp_r3_11;
                            var_r29_13 = var_r29_11 - temp_r3_11;
                        }
                        if (var_r29_13 < 7U) {
                            var_r3_13 = (var_r30_13 | ((*(u32 *)var_r31) << var_r29_13)) & 0x7F;
                        } else {
                            var_r3_13 = var_r30_13 & 0x7F;
                        }
                        temp_r3_12 = fn_8011C400(var_r3_13, (u8 *)(buffers + 8), (u8 *)(buffers + 24), (u8 *)(buffers + 28), 4);
                        if (var_r29_13 < temp_r3_12) {
                            temp_r5_12 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30_14 = temp_r5_12 >> (temp_r3_12 - var_r29_13);
                            var_r29_14 = (var_r29_13 + 0x20) - temp_r3_12;
                        } else {
                            var_r30_14 = var_r30_13 >> temp_r3_12;
                            var_r29_14 = var_r29_13 - temp_r3_12;
                        }
                        if (var_r29_14 < 0xFU) {
                            var_r3_14 = (var_r30_14 | ((*(u32 *)var_r31) << var_r29_14)) & 0x7FFF;
                        } else {
                            var_r3_14 = var_r30_14 & 0x7FFF;
                        }
                        temp_r3_13 = fn_8011C400(var_r3_14, (u8 *)(arg3), (u8 *)(buffers + 0), (u8 *)(buffers + 8), 8);
                        if (var_r29_14 < temp_r3_13) {
                            temp_r5_13 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5_13 >> (temp_r3_13 - var_r29_14);
                            var_r29 = (var_r29_14 + 0x20) - temp_r3_13;
                        } else {
                            var_r30 = var_r30_14 >> temp_r3_13;
                            var_r29 = var_r29_14 - temp_r3_13;
                        }
                    }
                }
            }
        } else {
            if (var_r29_2 < 3U) {
                temp_r4_4 = (*(u32 *)var_r31);
                var_r31 += 4;
                var_r29 = var_r29_2 + 0x1D;
                var_r30 = temp_r4_4 >> (3 - var_r29_2);
                var_r8_2 = (var_r30_2 | (temp_r4_4 << var_r29_2)) & 7;
            } else {
                var_r8_2 = var_r30_2 & 7;
                var_r30 = var_r30_2 >> 3U;
                var_r29 = var_r29_2 - 3;
            }
            var_r3_15 = arg3;
            var_r7 = 0xFFFF;
            for (var_ctr_3 = 0; var_ctr_3 <= (s32)var_r8_2; var_ctr_3++) {
                    if ((u32) var_r29 < 4U) {
                        temp_r9 = (*(u32 *)var_r31);
                        temp_r0 = 4 - var_r29;
                        var_r31 += 4;
                        temp_r5_14 = temp_r9 << var_r29;
                        var_r29 += 0x1C;
                        temp_r5_15 = var_r30 | temp_r5_14;
                        var_r30 = temp_r9 >> temp_r0;
                        var_r0_6 = temp_r5_15 & 0xF;
                    } else {
                        var_r0_6 = var_r30 & 0xF;
                        var_r30 = var_r30 >> 4U;
                        var_r29 -= 4;
                    }
                    *var_r3_15 = var_r0_6;
                    var_r7 &= ~(1 << var_r0_6);
                    var_r3_15 += 1;
                }
            var_r3_16 = &arg3[var_r8_2];
            var_r4_3 = 0;
            do {
                if (var_r7 & 1) {
                    (*(s8 *)((s8 *)(var_r3_16) + (1))) = var_r4_3;
                    var_r3_16 += 1;
                }
                var_r7 = var_r7 >> 1U;
                var_r4_3 += 1;
            } while (var_r7 != 0);
        }
    }
    ((BitReader8011 *)arg0)->next = (u32 *)var_r31;
    ((BitReader8011 *)arg0)->value = var_r30;
    ((BitReader8011 *)arg0)->count = (u32)var_r29;
}

void fn_8011CD78(void* arg0, void* arg1) {
    fn_8011C4A0((s32)arg1, (s32)((u8*)arg0 + 0x24), (s32)((u8*)arg0 + 0x20), (s32)((u8*)arg0 + 0x10));
}

#pragma pop
void fn_8011CD90(s32 arg0, s32 arg1, s32 arg2) {
    s32 a = arg2;
    register s32 b = arg2 + 0x100;
    s32 c = arg2 + 0x140;
    u32 i;
    for (i = 0; i < 0x10; i++) {
        fn_8011C4A0(arg1, c, b, a);
        a += 0x10;
        b += 4;
        c += 4;
    }
    fn_8011C4A0(arg1, arg0 + 0x24, arg0 + 0x20, arg0 + 0x10);
    *(s32 *)(arg2 + 0x180) = 0;
}

extern u8 lbl_80561208[];
void fn_8011CE18(void *arg0, void *arg1) {
    u32 *bits;
    u32 value, bitCount, available, mask, count, code, len, s, w;
    u8 fill;
    u8 *dst, *table, *lookup;
    u32 sym, runlen, j;
    if (*(u32 *)arg0 != *(u32 *)((u8 *)arg0 + 4)) return;
    bitCount = *(u32 *)((u8 *)arg1 + 8);
    available = *(u32 *)((u8 *)arg0 + 0x28);
    bits = *(u32 **)((u8 *)arg1 + 4);
    value = *(u32 *)arg1;
    if (bitCount < available) {
        u32 next = *bits++;
        count = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - available));
        value = next >> (available - bitCount);
        bitCount = bitCount + 32 - available;
    } else {
        count = value & (0xFFFFFFFFU >> (32 - available));
        value >>= available;
        bitCount -= available;
    }
    if (count != 0) {
        dst = *(u8 **)((u8 *)arg0 + 0x2C);
        *(u8 **)arg0 = dst;
        *(u8 **)((u8 *)arg0 + 4) = dst + count;
        if (bitCount == 0) { w = *bits++; bitCount = 31; value = w >> 1; }
        else { w = value; value >>= 1; bitCount--; }
        if ((w & 1) == 0) {
            fill = 0;
            table = (u8 *)arg0 + 0x10;
            lookup = *(u8 **)((u8 *)arg0 + 0x24);
            available = *(u32 *)((u8 *)arg0 + 0x20);
            mask = 0xFFFFFFFFU >> (32 - available);
            while (count != 0) {
                if (bitCount >= available) {
                    code = value & mask;
                    s = lookup[code];
                    code = s & 15;
                    len = s >> 4;
                    sym = table[code];
                    value >>= len;
                    bitCount -= len;
                } else {
                    u32 next = *bits;
                    code = (value | (next << bitCount)) & mask;
                    s = lookup[code];
                    code = s & 15;
                    len = s >> 4;
                    sym = table[code];
                    if (bitCount >= len) { value >>= len; bitCount -= len; }
                    else { value = next >> (len - bitCount); bits++; bitCount = bitCount + 32 - len; }
                }
                if (sym >= 12) {
                    runlen = lbl_80561208[sym - 12];
                    count -= runlen;
                    for (j = 0; j < runlen; j++) {
                        *dst++ = fill;
                    }
                } else {
                    *dst++ = sym;
                    fill = sym;
                    count--;
                }
            }
        } else {
            if (bitCount < 4) {
                u32 next = *bits++;
                code = (value | (next << bitCount)) & 15;
                value = next >> (4 - bitCount);
                bitCount += 28;
            } else {
                code = value & 15; value >>= 4; bitCount -= 4;
            }
            memset(*(void **)((u8 *)arg0 + 0x2C), code, count);
        }
    } else {
        dst = *(u8 **)((u8 *)arg0 + 0x2C);
        *(u8 **)((u8 *)arg0 + 4) = dst; *(u8 **)arg0 = dst + 4;
    }
    *(u32 **)((u8 *)arg1 + 4) = bits;
    *(u32 *)arg1 = value; *(u32 *)((u8 *)arg1 + 8) = bitCount;
}

void fn_8011D0E8(void *arg0, void *arg1, void *arg2) {
 u32 *p=(u32*)M2C_FIELD(arg1,u32*,4), bits=M2C_FIELD(arg1,u32*,0), n=M2C_FIELD(arg1,u32*,8), width=M2C_FIELD(arg0,u32*,0x28), out;
 s32 left, tree=M2C_FIELD(arg2,s32*,0x180);
 u32 code, mask, value;
 u8 *dst;
 if(M2C_FIELD(arg0,u8**,0)!=M2C_FIELD(arg0,u8**,4)) return;
 if(n<width){u32 x=*p++; out=(-1U>>(32-width))&(bits|(x<<n)); bits=x>>(width-n); n=n+32-width;} else {out=bits&(-1U>>(32-width)); bits>>=width; n-=width;}
 if(out){
  dst=M2C_FIELD(arg0,u8**,0x2C); M2C_FIELD(arg0,u8**,0)=dst; M2C_FIELD(arg0,u8**,4)=dst+out;
  if(n==0){bits=*p++>>1;n=31;} else {bits>>=1;n--;}
  if(bits&1) out=-20-out;
  mask=-1U>>(32-M2C_FIELD(arg0,u32*,0x20));
  do {
   s32 rem;
   out--;
   {u8 *tab=(u8*)M2C_FIELD(arg2,u32*,tree*4+0x140); u32 w=M2C_FIELD(arg2,u32*,tree*4+0x100);
    if(n>=w){code=tab[bits&(-1U>>(32-w))];}
    else {u32 x=*p, idx=(bits|(x<<n))&(-1U>>(32-w)); code=tab[idx];}
    tree=*(u8*)((u8*)arg2+tree*16+(code&15)); rem=code>>4;
    if(n<rem){u32 x=*p++; bits=x>>(rem-n); n=n+32-rem;} else {bits>>=rem;n-=rem;}
   }
   {u8 *table=(u8*)M2C_FIELD(arg0,u8**,0x24); u32 ix;
    if(n>=M2C_FIELD(arg0,u32*,0x20)){u8 c=table[bits&mask]; value=*(u8*)((u8*)arg0+0x10+(c&15)); rem=c>>4;}
    else {u32 x=*p, ix2=(bits|(x<<n))&mask; u8 c=table[ix2]; value=*(u8*)((u8*)arg0+0x10+(c&15)); rem=c>>4;}
    if(n<rem){u32 x=*p++;bits=x>>(rem-n);n=n+32-rem;}else{bits>>=rem;n-=rem;}
   }
   {u32 c=value|(tree<<4); u32 v=c&127; if(c&128)v=(u8)(-v); *dst++=v+128;}
  } while(out>0);
  if(out < -22) memset(M2C_FIELD(arg0,u8**,0x2C),*(u8*)M2C_FIELD(arg0,u8**,0x2C),-(out+21));
  M2C_FIELD(arg2,s32*,0x180)=tree;
 } else {dst=M2C_FIELD(arg0,u8**,0x2C);M2C_FIELD(arg0,u8**,4)=dst;M2C_FIELD(arg0,u8**,0)=dst+4;}
 M2C_FIELD(arg1,u32**,4)=p;M2C_FIELD(arg1,u32*,0)=bits;M2C_FIELD(arg1,u32*,8)=n;
}

void fn_8011D378(void *arg0, void *arg1, void *arg2) {
u32 *src; u32 bits, index, remain, node, tmp; u8 *out; u32 endbits, mask;
if (*(u32*)arg0 != *(u32*)((u8*)arg0+4)) return;
remain=*(u32*)((u8*)arg1+8); index=*(u32*)((u8*)arg0+0x28); src=*(u32**)((u8*)arg1+4); bits=*(u32*)arg1;
if(remain<index){tmp=*src++; bits=(bits|(tmp<<remain))&(0xFFFFFFFFU>>(32-index)); remain=remain+32-index; bits=tmp>>(index-*(u32*)((u8*)arg1+8));}else{remain-=index;bits&=0xFFFFFFFFU>>(32-index);bits>>= index;}
if(bits){out=*(u8**)((u8*)arg0+0x2c);endbits=*(u32*)((u8*)arg0+0x20);*(u8**)arg0=out;*(u8**)((u8*)arg0+4)=out+bits;node=*(u32*)((u8*)arg2+0x180);
if(remain==0){tmp=*src++;remain=31;bits=tmp>>1;}else{tmp=bits;bits>>=1;remain--;}
if(tmp&1)bits=-20-bits; mask=0xFFFFFFFFU>>(32-endbits);
do{bits--;{u32 n=*(u32*)((u8*)arg2+node*4+0x100);u8 v;if(remain>=n){v=*(*(u8**)((u8*)arg2+node*4+0x140)+(bits&(0xFFFFFFFFU>>(32-n))));node=*((u8*)arg2+node*16+(v&15));tmp=v>>4;bits>>=tmp;remain-=tmp;}else{u32 w=*src;v=*(*(u8**)((u8*)arg2+node*4+0x140)+((bits|(w<<remain))&(0xFFFFFFFFU>>(32-n))));node=*((u8*)arg2+node*16+(v&15));tmp=v>>4;if(remain>=tmp){bits>>=tmp;remain-=tmp;}else{bits=w>>(tmp-remain);src++;remain=remain+32-tmp;}}}
{u8 v;if(remain>=endbits){v=*((u8*)arg0+0x24+(bits&mask));tmp=*(u8*)((u8*)arg0+0x10+(v&15));bits>>=v>>4;remain-=v>>4;}else{u32 w=*src;v=*((u8*)arg0+0x24+((bits|(w<<remain))&mask));tmp=*(u8*)((u8*)arg0+0x10+(v&15));if(remain>=v>>4){bits>>=v>>4;remain-=v>>4;}else{bits=w>>((v>>4)-remain);src++;remain=remain+32-(v>>4);}}}
*out++=(u8)(tmp|(node<<4));
}while(bits>0);
if(bits < -22) memset(*(u8**)((u8*)arg0+0x2c), **(u8**)((u8*)arg0+0x2c), -bits-21);
*(u32*)((u8*)arg2+0x180)=node;
}else{out=*(u8**)((u8*)arg0+0x2c);*(u8**)((u8*)arg0+4)=out;*(u8**)arg0=out+4;}
*(u32*)((u8*)arg1+4)=(u32)src;*(u32*)arg1=bits;*(u32*)((u8*)arg1+8)=remain;
}

void fn_8011D9E4(void *arg0, void *arg1) {
    u32 *bits;
    u32 value, bitCount, available, mask, count, i, code, len;
    u8 *dst, *table, *lookup;
    s32 symbol;
    if (*(u32 *)arg0 != *(u32 *)((u8 *)arg0 + 4)) return;
    bitCount = *(u32 *)((u8 *)arg1 + 8);
    available = *(u32 *)((u8 *)arg0 + 0x28);
    bits = *(u32 **)((u8 *)arg1 + 4);
    value = *(u32 *)arg1;
    if (bitCount < available) {
        u32 next = *bits++;
        count = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - available));
        value = next >> (available - bitCount);
        bitCount = bitCount + 32 - available;
    } else {
        count = value & (0xFFFFFFFFU >> (32 - available));
        value >>= available;
        bitCount -= available;
    }
    if (count != 0) {
        dst = *(u8 **)((u8 *)arg0 + 0x2C);
        *(u8 **)arg0 = dst;
        *(u8 **)((u8 *)arg0 + 4) = dst + count;
        if (bitCount == 0) { value = *bits++ >> 1; bitCount = 31; }
        else { bitCount--; value >>= 1; }
        if ((value & 1) == 0) {
            table = (u8 *)arg0 + 0x10;
            lookup = *(u8 **)((u8 *)arg0 + 0x24);
            available = *(u32 *)((u8 *)arg0 + 0x20);
            mask = 0xFFFFFFFFU >> (32 - available);
            for (i = 0; i < count; i++) {
                if (bitCount >= available) {
                    code = value & mask; symbol = lookup[code]; len = symbol >> 4;
                    symbol = table[symbol & 15]; value >>= len; bitCount -= len;
                } else {
                    u32 next = *bits;
                    code = (value | (next << bitCount)) & mask;
                    symbol = lookup[code]; len = symbol >> 4; symbol = table[symbol & 15];
                    if (bitCount >= len) { value >>= len; bitCount -= len; }
                    else { value = next >> (len - bitCount); bits++; bitCount = bitCount + 32 - len; }
                }
                if (symbol != 0) {
                    if (bitCount == 0) { value = *bits++ >> 1; bitCount = 31; }
                    else { bitCount--; value >>= 1; }
                    if (value & 1) symbol = -symbol;
                }
                *dst++ = symbol;
            }
        } else {
            if (bitCount < 4) {
                u32 next = *bits++;
                code = (value | (next << bitCount)) & 15;
                value = next >> (4 - bitCount); bitCount += 28;
            } else { code = value & 15; value >>= 4; bitCount -= 4; }
            if (code != 0) {
                if (bitCount == 0) { value = *bits++ >> 1; bitCount = 31; }
                else { bitCount--; value >>= 1; }
                if (value & 1) code = -code;
            }
            memset(*(void **)((u8 *)arg0 + 0x2C), code, count);
        }
    } else {
        dst = *(u8 **)((u8 *)arg0 + 0x2C);
        *(u8 **)((u8 *)arg0 + 4) = dst; *(u8 **)arg0 = dst + 4;
    }
    *(u32 **)((u8 *)arg1 + 4) = bits;
    *(u32 *)arg1 = value; *(u32 *)((u8 *)arg1 + 8) = bitCount;
}

void fn_8011DC5C(void *arg0, void *arg1) {
    s32 n;
    u32 count;
    u32 *bits;
    u32 value;
    u32 bitCount;
    s16 *dst;
    s32 val;
    u32 width, mask, code, order, tmp, tmp2;
    s32 run;

    if (*(u32 *)arg0 != *(u32 *)((u8 *)arg0 + 4)) return;
    bitCount = *(u32 *)((u8 *)arg1 + 8);
    width = *(u32 *)((u8 *)arg0 + 0x28);
    bits = *(u32 **)((u8 *)arg1 + 4);
    value = *(u32 *)arg1;
    if (bitCount < width) {
        u32 next = *bits++;
        count = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
        value = next >> (width - bitCount);
        bitCount = bitCount + 32 - width;
    } else {
        count = value & (0xFFFFFFFFU >> (32 - width));
        value >>= width;
        bitCount -= width;
    }
    if (count != 0) {
        dst = *(s16 **)((u8 *)arg0 + 0x2C);
        if (*(s32 *)((u8 *)arg0 + 0xC) != 0) {
            width = *(u32 *)((u8 *)arg0 + 8) - 1;
            if (bitCount < width) {
                u32 next = *bits++;
                val = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
                value = next >> (width - bitCount);
                bitCount = bitCount + 32 - width;
            } else {
                val = value & (0xFFFFFFFFU >> (32 - width));
                value >>= width;
                bitCount -= width;
            }
            if (val != 0) {
                if (bitCount == 0) { tmp = *bits++; bitCount = 31; value = tmp >> 1; }
                else { tmp = value; value >>= 1; bitCount--; }
                if (tmp & 1) val = -val;
            }
        } else {
            width = *(u32 *)((u8 *)arg0 + 8);
            if (bitCount < width) {
                u32 next = *bits++;
                val = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
                value = next >> (width - bitCount);
                bitCount = bitCount + 32 - width;
            } else {
                val = value & (0xFFFFFFFFU >> (32 - width));
                value >>= width;
                bitCount -= width;
            }
        }
        *dst = val;
        *(s16 **)arg0 = *(s16 **)((u8 *)arg0 + 0x2C);
        *(s16 **)((u8 *)arg0 + 4) = *(s16 **)((u8 *)arg0 + 0x2C) + count;
        count--;
        dst++;
        while (count != 0) {
            n = 8;
            if (count <= 8) n = (s32)count;
            if (bitCount < 4) {
                u32 next = *bits++;
                order = (value | (next << bitCount)) & 15;
                value = next >> (4 - bitCount);
                bitCount = bitCount + 32 - 4;
            } else {
                order = value & 15;
                value >>= 4;
                bitCount -= 4;
            }
            if (order != 0) {
                mask = 0xFFFFFFFFU >> (32 - order);
                run = n;
                while (run != 0) {
                    run--;
                    if (bitCount < order) {
                        u32 next = *bits++;
                        code = (value | (next << bitCount)) & mask;
                        value = next >> (order - bitCount);
                        bitCount = bitCount + 32 - order;
                    } else {
                        code = value & mask;
                        value >>= order;
                        bitCount -= order;
                    }
                    if (code != 0) {
                        if (bitCount == 0) { u32 w = *bits++; bitCount = 31; value = w >> 1; tmp2 = w; }
                        else { tmp2 = value; value >>= 1; bitCount--; }
                        if (tmp2 & 1) code = -code;
                    }
                    val += code;
                    *dst = val;
                    dst++;
                }
            } else {
                fn_80116CC4((s32 *)dst, (u16)val, (n + n));
                dst = (s16 *)((u8 *)dst + (n << 1));
            }
            count -= n;
        }
    } else {
        dst = *(s16 **)((u8 *)arg0 + 0x2C);
        *(s16 **)((u8 *)arg0 + 4) = dst;
        *(s16 **)((u8 *)arg0) = dst + 2;
    }
    *(u32 **)((u8 *)arg1 + 4) = bits;
    *(u32 *)arg1 = value;
    *(u32 *)((u8 *)arg1 + 8) = bitCount;
}

s32 fn_8011DF68(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 var_r5 = arg2;
    u32 temp;
    if (var_r5 <= 8U) var_r5 = 8;
    else if (var_r5 < 0x10U) var_r5 = 0x10;
    temp = var_r5 * arg3;
    return (((u32)(arg0 * var_r5) >> 3) + ((temp * (arg1 >> 3)) >> 3) + 3) & 0xFFFFFFFC;
}

void fn_8011DFAC(void* arg0, u32 arg1) {
    s32* out = (s32*)arg0;
    out[0] = fn_8011DF68(0x200, arg1, 4, 1);
    out[1] = fn_8011DF68(0x200, arg1 >> 1, 4, 1);
    out[2] = fn_8011DF68(0x200, arg1, 8, 0x40);
    out[3] = fn_8011DF68(0x200, arg1, 8, 8);
    out[4] = fn_8011DF68(0x200, arg1, 5, 1);
    out[5] = fn_8011DF68(0x200, arg1, 5, 1);
    out[6] = fn_8011DF68(0x200, arg1, 0xB, 1);
    out[7] = fn_8011DF68(0x200, arg1, 0xB, 1);
    out[8] = fn_8011DF68(0x200, arg1, 4, 0x30);
}

extern void fn_8011CD78(void *, void *);
extern void fn_8011D0E8(void *, void *, void *);
extern void fn_8011D378(void *, void *, void *);
s32 *fn_8011E0B4(s32 arg0, s32 arg1, s32 width, s32 height, s32 format, s32 *buffers, s32 offset, s32 flags) {
    s32 rowBytes = (format << 3) - width;
    u8 work[0x450];
    u8 *base = work + 8;
    void (*decode)(void *, void *, void *);
    s32 zero = 0;
    ((s32 *)base)[-2] = width;
    ((s32 *)base)[-1] = height;
    *(s32 *)(base + 4) = offset;
    *(s32 *)(base + 0) = zero;
    *(s32 *)(base + 8) = zero;
    
    *(s32 *)(base + 0x404) = rowBytes;
    decode = (format & 0x8000) ? fn_8011D0E8 : fn_8011D378;
    *(void **)(base + 0x408) = (void *)decode;
    fn_8011C3A8(buffers[0], base + 0x1D0, 0x200, width, 4, 1, 0);
    fn_8011C3A8(buffers[1], base + 0x1A0, 0x200, (u32)width >> 1, 4, 1, 0);
    fn_8011C3A8(buffers[2], base + 0x170, 0x200, width, 8, 0x40, 0);
    fn_8011C3A8(buffers[3], base + 0x140, 0x200, width, 8, 8, 0);
    fn_8011C3A8(buffers[4], base + 0x110, 0x200, width, 5, 1, 1);
    fn_8011C3A8(buffers[5], base + 0xE0, 0x200, width, 5, 1, 1);
    fn_8011C3A8(buffers[6], base + 0xB0, 0x200, width, 0xB, 1, 0);
    fn_8011C3A8(buffers[7], base + 0x80, 0x200, width, 0xB, 1, 1);
    fn_8011C3A8(buffers[8], base + 0x50, 0x200, width, 4, 0x30, 0);
    fn_8011CD78(base + 0x1D0, base);
    fn_8011CD78(base + 0x1A0, base);
    fn_8011CD90((s32)(base + 0x170), (s32)base, (s32)(base + 0x280));
    fn_8011CD78(base + 0x140, base);
    fn_8011CD78(base + 0x110, base);
    fn_8011CD78(base + 0xE0, base);
    fn_8011CD78(base + 0x50, base);
    decode(base + 0x180, base + 0x10, base + 0x290);
    return buffers;
}

extern s32* fn_8011E0B4(s32, s32, s32, s32, s32, s32*, s32, s32);
u32 fn_8011FC2C(void* arg0, s32 arg1, s32 arg2, s32* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u32 result = 0;
    s32* ptr = arg3;
    s32 old = *(s32*)((u8*)arg0 + 0x14);
    s32 next = old ^ 1;
    s32 cur;
    s32 flag;
    s32* ret;
    s32 tmp;
    if (*(s32*)((u8*)arg0 + next * 0x30 + 0x1C))
        *(s32*)((u8*)arg0 + 0x14) = next;
    cur = *(s32*)((u8*)arg0 + 0x14);
    if ((arg7 & 0x100000) && (arg6 & 0x100000)) {
        tmp = 1;
        fn_8011E0B4(*(s32*)((u8*)arg0 + cur * 0x30 + 0x40), *(s32*)((u8*)arg0 + old * 0x30 + 0x40),
            *(s32*)((u8*)arg0 + 4), *(s32*)((u8*)arg0 + 8), *(s32*)((u8*)arg0 + old * 0x30 + 0x44),
            ptr + 1, arg4, arg1);
        ptr = (s32*)((u8*)ptr + *ptr);
    }
    flag = arg6 & 0x8000;
    result = 0;
    if (flag == 0) ptr++;
    ret = fn_8011E0B4(*(s32*)((u8*)arg0 + cur * 0x30 + 0x1C), *(s32*)((u8*)arg0 + old * 0x30 + 0x1C),
        *(s32*)((u8*)arg0 + 4), *(s32*)((u8*)arg0 + 8), *(s32*)((u8*)arg0 + old * 0x30 + 0x20),
        ptr, arg4, arg1);
    if (flag == 0) ret = (s32*)((u8*)ptr + *(s32*)((u8*)ptr - 4) - 4);
    result >>= 2;
    if (!(arg6 & 0x20000)) {
        tmp = 2;
        ret = fn_8011E0B4(*(s32*)((u8*)arg0 + cur * 0x30 + 0x28), *(s32*)((u8*)arg0 + old * 0x30 + 0x28),
            *(s32*)((u8*)arg0 + 0xC), *(s32*)((u8*)arg0 + 0x10), *(s32*)((u8*)arg0 + old * 0x30 + 0x2C),
            ret, arg4, arg1);
        result = 0;
        fn_8011E0B4(*(s32*)((u8*)arg0 + cur * 0x30 + 0x34), *(s32*)((u8*)arg0 + old * 0x30 + 0x34),
            *(s32*)((u8*)arg0 + 0xC), *(s32*)((u8*)arg0 + 0x10), *(s32*)((u8*)arg0 + old * 0x30 + 0x38),
            ret, arg4, arg1);
    }
    return result;
}

void fn_8011FE20(u32 **arg0, u32 arg1) {
    register u32 size = arg1;
    register u32 **slot = arg0;
    void *newBuffer;
    void *newSizes;
    u32 base;
    u32 rounded;
    u32 extra;
    u32 total;
    if (lbl_80559950 == lbl_8055DEF4) {
        newBuffer = fn_8011FFC4(lbl_80559950 << 4);
        newSizes = (u8 *)newBuffer + (lbl_80559950 << 3);
        memcpy(newBuffer, lbl_80559948, lbl_80559950 << 2);
        memcpy(newSizes, lbl_8055994C, lbl_80559950 << 2);
        lbl_80559950 <<= 1;
        if (lbl_80559950 != 0x40) {
            fn_80120084(lbl_80559948);
        }
        lbl_80559948 = (void **)newBuffer;
        lbl_8055994C = (u32 *)newSizes;
    }
    base = (u32)lbl_8055DEF0;
    rounded = size + 0x1F;
    extra = (((base >> 5) & 0x1F) + 0x21 - ((rounded >> 5) & 0x1F)) & 0x1F;
    total = (rounded & ~0x1F) + (extra << 5);
    lbl_8055DEF0 = (void *)(base + total);
    lbl_8055994C[lbl_8055DEF4] = total;
    lbl_80559948[lbl_8055DEF4] = slot;
    lbl_8055DEF4++;
}

extern void *lbl_8055DEF0;
extern void *lbl_8055DEF8;
extern void *lbl_8055DEFC;
extern u32 lbl_8055DEF4;
extern void **lbl_80559948;
extern u32 *lbl_8055994C;
extern void *fn_8011FFC4(s32);
void* fn_8011FF24(void) {
    return lbl_8055DEF0;
}

void *fn_8011FF2C(s32 arg0) {
    u32 aligned = (arg0 + 0x1F) & ~0x1F;
    void *res = fn_8011FFC4((s32)lbl_8055DEF0 + aligned);
    lbl_8055DEF0 = 0;
    if (res != NULL) {
        u32 i;
        u8 *ptr = (u8*)res + aligned;
        for (i = 0; i < lbl_8055DEF4; i++) {
            *(void**)lbl_80559948[i] = ptr;
            ptr += lbl_8055994C[i];
        }
    }
    lbl_8055DEF4 = 0;
    return res;
}

void AXFXSetHooks_8011FFB8(void *arg0, void *arg1) {
    lbl_8055DEF8 = arg0;
    lbl_8055DEFC = arg1;
}

extern void *malloc(u32);
extern void free(void *);
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
    if (ptr == 0) return;
    if (ptr[-2] == 3) {
        ((void (*)(void *))*(void **)(ptr - 8))(ptr - ptr[-1]);
    } else {
        free(ptr - ptr[-1]);
    }
}

void fn_80120834(s32, s32 *, f32 *);
void fn_80120B6C(s32, s32 *, f32 *);
void fn_80120CA4(s32, void *, s32, s32, void *);
void fn_80120E14(s32, void *, s32, s32, void *);
void fn_801250CC(s32, s32, s32, s32);
void fn_801252D8(s32, f32 *, s32, f32 *);
void fn_801200BC(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, s32 arg4) {
    s32 var_r31;
    s32 var_r30;
    f32 temp_f1;
    f32 temp_f2;

    var_r31 = *(s32 *)arg3;
    if (arg0 > var_r31 * 4) {
        var_r31 = arg0 >> 2;
        fn_80120834(var_r31, (s32 *)arg3, (f32 *)arg4);
    }
    var_r30 = *(s32 *)(arg3 + 4);
    if (arg0 > var_r30 * 4) {
        var_r30 = arg0 >> 2;
        fn_80120B6C(var_r30, (s32 *)arg3, (f32 *)((u8 *)arg4 + var_r31 * 4));
    }
    if (arg1 >= 0) {
        if (arg0 > 4) {
            fn_80120CA4(arg0, arg2, arg3 + 8, var_r31, (void *)arg4);
            fn_801250CC(arg0, (s32)arg2, var_r30, (s32)((u8 *)arg4 + var_r31 * 4));
        } else if (arg0 == 4) {
            fn_80120CA4(arg0, arg2, arg3 + 8, var_r31, (void *)arg4);
        }
        {
            f32 second;
            f32 first;
            f32 difference;
            first = arg2[0];
            second = arg2[1];
            difference = first - second;
            arg2[1] = difference;
            arg2[0] = first + second;
        }
        return;
    }
    temp_f2 = arg2[0];
    temp_f1 = lbl_80561210 * (temp_f2 - arg2[1]);
    arg2[1] = temp_f1;
    arg2[0] = temp_f2 - temp_f1;
    if (arg0 > 4) {
        fn_801252D8(arg0, arg2, var_r30, (f32 *)((u8 *)arg4 + var_r31 * 4));
        fn_80120E14(arg0, arg2, arg3 + 8, var_r31, (void *)arg4);
    } else if (arg0 == 4) {
        fn_80120E14(arg0, arg2, arg3 + 8, var_r31, (void *)arg4);
    }
}

void fn_80120834(s32 n, s32 *info, f32 *table) {
    register s32 i;
    register s32 stage;
    s32 half;
    s32 j;
    f32 endpoint;
    f32 angle;
    f32 angle2;
    f32 stage_scale;
    f32 stage_zero;

    info[0] = n;
    info[1] = 1;
    if (n <= 2)
        return;

    half = n >> 1;
    angle = lbl_80561214 / (f32)half;
    endpoint = (f32)cos((f64)(angle * (f32)half));
    table[0] = lbl_80561218;
    table[1] = endpoint;

    if (half >= 4) {
        f32 first = (f32)cos((f64)(lbl_8056121C * angle));
        f32 second_angle = lbl_80561220 * angle;
        table[2] = lbl_80561210 / first;
        table[3] = lbl_80561210 / (f32)cos((f64)second_angle);
    }

    angle2 = lbl_80561224 * angle;
    for (i = 4; i < half; i += 4) {
        table[i + 0] = (f32)cos((f64)(angle * (f32)i));
        table[i + 1] = (f32)sin((f64)(angle * (f32)i));
        table[i + 2] = (f32)cos((f64)(angle2 * (f32)i));
        table[i + 3] = (f32)sin((f64)(angle2 * (f32)i));
    }

    stage_scale = lbl_80561210;
    stage_zero = lbl_80561218;
    i = 0;
    while (half > 2) {
        f32 *stagep;
        stage = i + half;
        half >>= 1;
        stagep = table + stage;
        stagep[0] = stage_zero;
        stagep[1] = endpoint;
        if (half >= 4) {
            f32 source_a = table[i + 4];
            f32 source_b = table[i + 6];
            stagep[2] = stage_scale / source_a;
            stagep[3] = stage_scale / source_b;
        }
        if (half > 4) {
            u8 *src = (u8 *)(table + i);
            u8 *dst = (u8 *)(stagep + 4);
            s32 offset = 0x20;
            for (j = 0; j < ((half - 1) >> 2); j++) {
                f32 t0 = *(f32 *)(src + offset);
                f32 t1 = *(f32 *)(src + offset + 4);
                f32 t2 = *(f32 *)(src + offset + 8);
                f32 t3 = *(f32 *)(src + offset + 12);
                *(f32 *)(dst + 0) = t0;
                *(f32 *)(dst + 4) = t1;
                *(f32 *)(dst + 8) = t2;
                *(f32 *)(dst + 12) = t3;
                offset += 0x20;
                dst += 0x10;
            }
        }
        i = stage;
    }
}

extern f64 cos(f64);
extern f64 sin(f64);
extern f32 lbl_80561210;
extern f32 lbl_80561214;
extern f64 lbl_80561228;
void fn_80120B6C(s32 arg0, s32 *arg1, f32 *arg2) {
    s32 i;
    s32 half;
    f32 scale;
    f32 angle;
    f32 result;

    arg1[1] = arg0;
    if (arg0 <= 1) return;
    half = arg0 >> 1;
    angle = lbl_80561214 / (f32)half;
    result = (f32)cos((f64)(angle * (f32)half));
    scale = lbl_80561210;
    arg2[0] = result;
    arg2[half] = scale * result;
    for (i = 1; i < half; i++) {
        arg2[i] = scale * (f32)cos((f64)(angle * (f32)i));
        arg2[arg0 - i] = scale * (f32)sin((f64)(angle * (f32)i));
    }
}

extern void fn_80121C68(s32, void *, void *);
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
void fn_80120CA4(register s32 count, register void *dst, register s32 mode, register s32 srcIndex, register void *src) {
    register s32 n;
    if (count > 0x20) {
        n = count >> 2;
        fn_80121C68(count, dst, (u8 *)src + (srcIndex - n) * 4);
        if (count > 0x200) {
            fn_80122E08(n, dst, srcIndex, src);
            fn_80122ED8(n, (u8 *)dst + n * 4, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + n * 8, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + ((n * 3) << 2), srcIndex, src);
        } else if (n > 0x20) {
            fn_80122FA4(count, dst, srcIndex, src);
        } else {
            fn_80123CEC(count, dst, srcIndex, src);
        }
        fn_80120F84(count, mode, dst);
    } else if (count > 8) {
        if (count == 0x20) {
            fn_80123E98(dst, (u8 *)src + (srcIndex - 8) * 4);
            fn_80121848(dst);
        } else {
            fn_80124AD8(dst, src);
            fn_80121BB0(dst);
        }
    } else {
        if (count == 8) {
            fn_80124F90(dst);
        } else if (count == 4) {
            fn_80125098(dst);
        }
    }
}

extern void fn_80121400(s32, s32 *, f32 *, s32);
extern void fn_801219B4(void *);
extern void fn_80121BF4(void *);
extern void fn_80125014(void *);
extern void fn_80122518(s32, u8 *, void *);
void fn_80120E14(register s32 count, register void *dst, register s32 mode, register s32 srcIndex, register void *src) {
    register s32 n;
    if (count > 0x20) {
        n = count >> 2;
        fn_80122518(count, (u8 *)dst, (u8 *)src + (srcIndex - n) * 4);
        if (count > 0x200) {
            fn_80122E08(n, dst, srcIndex, src);
            fn_80122ED8(n, (u8 *)dst + n * 4, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + n * 8, srcIndex, src);
            fn_80122E08(n, (u8 *)dst + ((n * 3) << 2), srcIndex, src);
        } else if (n > 0x20) {
            fn_80122FA4(count, dst, srcIndex, src);
        } else {
            fn_80123CEC(count, dst, srcIndex, src);
        }
        fn_80121400(count, (s32 *)mode, (f32 *)dst, srcIndex);
    } else if (count > 8) {
        if (count == 0x20) {
            fn_80123E98(dst, (u8 *)src + (srcIndex - 8) * 4);
            fn_801219B4(dst);
        } else {
            fn_80124AD8(dst, src);
            fn_80121BF4(dst);
        }
    } else {
        if (count == 8) {
            fn_80125014(dst);
        } else if (count == 4) {
            fn_80125098(dst);
        }
    }
}

void fn_80121400(s32 n, s32 *map, f32 *data, s32 unused) {
    s32 size = 1;
    s32 i, j, k, half, span;
    *map = 0;
    while ((size << 3) < n) {
        n >>= 1;
        for (i = 0; i < size; i++) map[size + i] = n + map[i];
        size <<= 1;
    }
    half = size;
    if ((size << 3) == n) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < i; j++) {
                s32 a = map[i] + j * 2;
                s32 b = map[j] + i * 2;
                f32 t0=data[b*2], t1=data[b*2+1];
                data[b*2]=data[a*2]; data[b*2+1]=-data[a*2+1];
                data[a*2]=t0; data[a*2+1]=-t1;
            }
            data[(map[i]+i*2)*2+1] = -data[(map[i]+i*2)*2+1];
        }
        return;
    }
    data[1] = -data[1];
    data[(half*2+1)*2] = -data[(half*2+1)*2];
    for (i=1; i<size; i++) {
        for (j=0; j<i; j++) {
            s32 a=2+map[j]+i*2, b=map[i+1]+j*2;
            f32 t0=data[b*2], t1=data[b*2+1];
            data[b*2]=data[a*2]; data[b*2+1]=-data[a*2+1];
            data[a*2]=t0; data[a*2+1]=-t1;
        }
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

extern void fn_801233F8(s32, volatile f32 *, f32 *);
void fn_80122E08(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    s32 n2;
    s32 n = arg0 >> 2;
    n2 = n * 2;
    fn_801233F8(arg0, (volatile f32 *)arg1, (f32 *)((u8 *)arg3 + (arg2 - n2) * 4));
    if (arg0 > 0x200) {
        fn_80122E08(n, arg1, arg2, arg3);
        fn_80122ED8(n, (u8 *)arg1 + n * 4, arg2, arg3);
        fn_80122E08(n, (u8 *)arg1 + (n2 * 4), arg2, arg3);
        fn_80122E08(n, (u8 *)arg1 + ((n * 3) << 2), arg2, arg3);
        return;
    }
    fn_80122FA4(arg0, arg1, arg2, arg3);
}

#pragma scheduling invalid_target
extern void fn_801237C4(s32, void *, void *);
void fn_80122ED8(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    s32 n = arg0 >> 2;
    fn_801237C4(arg0, arg1, (u8 *)arg3 + (arg2 - arg0) * 4);
    if (arg0 > 0x200) {
        fn_80122E08(n, arg1, arg2, arg3);
        fn_80122ED8(n, (u8 *)arg1 + n * 4, arg2, arg3);
        fn_80122E08(n, (u8 *)arg1 + n * 8, arg2, arg3);
        fn_80122ED8(n, (u8 *)arg1 + n * 12, arg2, arg3);
        return;
    }
    fn_801231B8(arg0, arg1, arg2, arg3);
}
#pragma scheduling on
void fn_801233F8(s32 arg0, volatile f32 *arg1, f32 *arg2) {
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f1, temp_f1_2, temp_f1_3;
    f32 temp_f1_4, temp_f1_5, temp_f1_6, temp_f2, temp_f2_2, temp_f2_3;
    f32 temp_f2_4, temp_f3, temp_f3_2, temp_f3_3, temp_f3_4, temp_f3_5, temp_f3_6;
    f32 temp_f4, temp_f4_2, temp_f4_3, temp_f4_4, temp_f4_5, temp_f4_6;
    f32 temp_f5, temp_f5_2, temp_f5_3, temp_f5_4, temp_f5_5, temp_f5_6, temp_f5_7, temp_f5_8;
    f32 temp_f6, temp_f6_2, temp_f6_3, temp_f6_4, temp_f6_5, temp_f6_6, temp_f6_7, temp_f6_8;
    f32 temp_f7, temp_f7_2, temp_f7_3, temp_f7_4, temp_f7_5;
    f32 temp_f8, temp_f8_2, temp_f8_3, temp_f8_4, temp_f8_5, temp_f8_6, temp_f8_7, temp_f8_8;
    f32 temp_f9, temp_f9_2, temp_f9_3, temp_f9_4, temp_f9_5, temp_f9_6;
    f32 temp_f10, temp_f10_2, temp_f10_3, temp_f10_4, temp_f10_5, temp_f10_6;
    f32 temp_f11, temp_f11_2, temp_f11_3, temp_f11_4, temp_f11_5;
    f32 temp_f12, temp_f12_2, temp_f12_3, temp_f12_4;
    f32 temp_f13, temp_f13_2, temp_f13_3, temp_f30, temp_f30_2, temp_f30_3, temp_f31, temp_f31_2;
    s32 temp_r0, temp_r0_2, temp_r0_3, temp_r3, temp_r5, temp_r6, temp_r6_2, temp_r7, temp_r7_2;
    s32 temp_r8, temp_r8_2, temp_r8_3, temp_r8_5, temp_r9, temp_r9_2, temp_r9_4;
    s32 temp_r10, temp_r10_2, temp_r10_3, temp_r10_5, temp_r11, temp_r11_2, temp_r12, temp_r28, temp_r29, temp_r31;
    register s32 var_r3;
    register u32 var_ctr;
    u8 *var_r30, *var_r5;
    s32 temp_r8_4, temp_r9_3, temp_r10_4, temp_r11_3, temp_r12_2, temp_r29_2;
    s32 temp_r31_2;
    s32 temp_r0_4;

    temp_r7 = arg0 >> 3;
    temp_r10 = arg0 & 0xFFFFFFF8;
    temp_r6 = temp_r7 * 2;
    temp_r31 = (arg0 * 2) & 0xFFFFFFF0;
    temp_r11 = temp_r7 * 6;
    temp_r12 = ((temp_r7 * 4) + 1) * 4;
    temp_r11_2 = temp_r11 * 4;
    temp_r8 = (temp_r6 + 1) * 4;
    temp_r9 = (temp_r11 + 1) * 4;
    temp_f1 = arg1[0];
    var_r30 = (u8 *)arg1 + 8;
    temp_f0 = *(f32 *)((u8 *)arg1 + temp_r31);
    var_r3 = 2;
    temp_f5 = arg1[1];
    temp_f4 = *(f32 *)((u8 *)arg1 + temp_r12);
    temp_f6 = temp_f1 + temp_f0;
    temp_f8 = temp_f1 - temp_f0;
    temp_f3 = *(f32 *)((u8 *)arg1 + temp_r10);
    temp_f2 = *(f32 *)((u8 *)arg1 + temp_r11_2);
    temp_f7 = temp_f5 + temp_f4;
    temp_f1_2 = *(f32 *)((u8 *)arg1 + temp_r8);
    temp_f0_2 = *(f32 *)((u8 *)arg1 + temp_r9);
    temp_f5_2 = temp_f5 - temp_f4;
    temp_f9 = temp_f3 + temp_f2;
    temp_f10 = temp_f3 - temp_f2;
    temp_f11 = temp_f1_2 - temp_f0_2;
    temp_f4_2 = temp_f1_2 + temp_f0_2;
    temp_f2_2 = temp_f6 + temp_f9;
    temp_f0_3 = temp_f6 - temp_f9;
    temp_f1_3 = temp_f7 + temp_f4_2;
    arg1[0] = temp_f2_2;
    temp_f4_3 = temp_f7 - temp_f4_2;
    temp_f3_2 = temp_f8 - temp_f11;
    arg1[1] = temp_f1_3;
    temp_f2_3 = temp_f5_2 + temp_f10;
    temp_f1_4 = temp_f8 + temp_f11;
    *(f32 *)((u8 *)arg1 + temp_r10) = temp_f0_3;
    temp_f0_2 = temp_f5_2 - temp_f10;
    *(f32 *)((u8 *)arg1 + temp_r8) = temp_f4_3;
    *(f32 *)((u8 *)arg1 + temp_r31) = temp_f3_2;
    *(f32 *)((u8 *)arg1 + temp_r12) = temp_f2_3;
    *(f32 *)((u8 *)arg1 + temp_r11_2) = temp_f1_4;
    *(f32 *)((u8 *)arg1 + temp_r9) = temp_f0_2;

    temp_f0 = arg2[1];
    var_r5 = (u8 *)arg2;
    var_ctr = (u32)(temp_r7 - 1) >> 1;
    if (temp_r7 > 2) {
        do {
            temp_r10_2 = var_r3 + temp_r6;
            temp_r28 = temp_r6 - var_r3;
            temp_r0 = temp_r10_2 + temp_r6;
            temp_f3_2 = *(f32 *)var_r30;
            temp_f6_2 = *(f32 *)(var_r30 + 4);
            temp_r11_3 = temp_r0 * 4;
            temp_r31_2 = temp_r10_2 * 4;
            temp_r12_2 = (temp_r0 + temp_r6) * 4;
            temp_f1_5 = *(f32 *)((u8 *)arg1 + temp_r11_3);
            temp_f5_3 = *(f32 *)((u8 *)arg1 + temp_r31_2);
            temp_r29 = temp_r28 + temp_r6;
            temp_f2_2 = *(f32 *)((u8 *)arg1 + temp_r12_2);
            temp_f8_2 = temp_f3_2 + temp_f1_5;
            temp_f11_2 = temp_f3_2 - temp_f1_5;
            temp_f1_6 = *(f32 *)((u8 *)arg1 + temp_r11_3 + 4);
            temp_f31 = temp_f5_3 + temp_f2_2;
            temp_f4_4 = *(f32 *)((u8 *)arg1 + temp_r31_2 + 4);
            temp_f12 = temp_f5_3 - temp_f2_2;
            temp_f3_3 = *(f32 *)((u8 *)arg1 + temp_r12_2 + 4);
            temp_f9_2 = temp_f6_2 + temp_f1_6;
            temp_f2_3 = *(f32 *)(var_r5 + 0x14);
            temp_f6_3 = temp_f6_2 - temp_f1_6;
            temp_f1_3 = *(f32 *)(var_r5 + 0x10);
            temp_f30 = temp_f4_4 + temp_f3_3;
            temp_r8_2 = temp_r29 + temp_r6;
            temp_f4_5 = temp_f4_4 - temp_f3_3;
            temp_f3_4 = *(f32 *)(var_r5 + 0x18);
            temp_f5_4 = temp_f8_2 + temp_f31;
            temp_r0_2 = temp_r8_2 + temp_r6;
            temp_f13 = temp_f6_3 + temp_f12;
            temp_r10_3 = temp_r8_2 * 4;
            temp_f10_2 = temp_f11_2 - temp_f4_5;
            *(f32 *)var_r30 = temp_f5_4;
            temp_f12_2 = temp_f6_3 - temp_f12;
            temp_r8_3 = temp_r0_2 * 4;
            temp_r0_3 = temp_r29 * 4;
            temp_r9_2 = temp_r28 * 4;
            temp_f6_4 = temp_f9_2 + temp_f30;
            *(f32 *)(var_r30 + 4) = temp_f6_4;
            temp_f11_3 = temp_f11_2 + temp_f4_5;
            temp_f4_6 = -*(f32 *)(var_r5 + 0x1C);
            temp_r29_2 = temp_r0_3;
            *(f32 *)((u8 *)arg1 + temp_r31_2) = temp_f8_2 - temp_f31;
            temp_f8_3 = temp_f1_3 * temp_f10_2;
            var_r5 += 0x10;
            *(f32 *)((u8 *)arg1 + temp_r31_2 + 4) = temp_f9_2 - temp_f30;
            *(f32 *)((u8 *)arg1 + temp_r11_3) = temp_f8_3 - (temp_f2_3 * temp_f13);
            *(f32 *)((u8 *)arg1 + temp_r11_3 + 4) = (temp_f1_3 * temp_f13) + (temp_f2_3 * temp_f10_2);
            *(f32 *)((u8 *)arg1 + temp_r12_2) = (temp_f3_4 * temp_f11_3) + (temp_f4_6 * temp_f12_2);
            *(f32 *)((u8 *)arg1 + temp_r12_2 + 4) = (temp_f3_4 * temp_f12_2) - (temp_f4_6 * temp_f11_3);
            temp_f9_3 = *(f32 *)((u8 *)arg1 + temp_r9_2);
            temp_r9_3 = temp_r9_2;
            temp_f5_5 = *(f32 *)((u8 *)arg1 + temp_r10_3);
            temp_r10_4 = temp_r10_3;
            temp_f8_4 = *(f32 *)((u8 *)arg1 + temp_r9_3 + 4);
            temp_f7_2 = *(f32 *)((u8 *)arg1 + temp_r10_4 + 4);
            temp_f10_3 = temp_f9_3 + temp_f5_5;
            temp_f9_4 = temp_f9_3 - temp_f5_5;
            temp_f6_5 = *(f32 *)((u8 *)arg1 + temp_r0_3);
            temp_f5_6 = *(f32 *)((u8 *)arg1 + temp_r8_3);
            temp_r8_4 = temp_r8_3;
            temp_f12_3 = temp_f8_4 + temp_f7_2;
            temp_f13_2 = temp_f8_4 - temp_f7_2;
            temp_f7_3 = temp_f6_5 + temp_f5_6;
            temp_f30_2 = temp_f6_5 - temp_f5_6;
            temp_f8_5 = *(f32 *)((u8 *)arg1 + temp_r29_2 + 4);
            temp_f6_6 = *(f32 *)((u8 *)arg1 + temp_r8_4 + 4);
            var_r30 += 8;
            temp_f31_2 = temp_f8_5 + temp_f6_6;
            *(f32 *)((u8 *)arg1 + temp_r9_3) = temp_f10_3 + temp_f7_3;
            temp_f10_4 = temp_f8_5 - temp_f6_6;
            var_r3 += 2;
            temp_f11_4 = temp_f13_2 + temp_f30_2;
            temp_f8_6 = temp_f9_4 - temp_f10_4;
            *(f32 *)((u8 *)arg1 + temp_r9_3 + 4) = temp_f12_3 + temp_f31_2;
            temp_f9_5 = temp_f9_4 + temp_f10_4;
            *(f32 *)((u8 *)arg1 + temp_r29_2) = temp_f10_3 - temp_f7_3;
            temp_f10_5 = temp_f13_2 - temp_f30_2;
            *(f32 *)((u8 *)arg1 + temp_r29_2 + 4) = temp_f12_3 - temp_f31_2;
            *(f32 *)((u8 *)arg1 + temp_r10_4) = (temp_f2_3 * temp_f8_6) - (temp_f1_3 * temp_f11_4);
            *(f32 *)((u8 *)arg1 + temp_r10_4 + 4) = (temp_f2_3 * temp_f11_4) + (temp_f1_3 * temp_f8_6);
            *(f32 *)((u8 *)arg1 + temp_r8_4) = (temp_f4_6 * temp_f9_5) + (temp_f3_4 * temp_f10_5);
            *(f32 *)((u8 *)arg1 + temp_r8_4 + 4) = (temp_f4_6 * temp_f10_5) - (temp_f3_4 * temp_f9_5);
            var_ctr -= 1;
        } while (var_ctr != 0);
    }

    temp_r9_4 = temp_r7 * 4;
    temp_r5 = temp_r7 * 0xC;
    temp_r10_5 = temp_r7 * 0x14;
    temp_r6_2 = temp_r7 * 0x1C;
    temp_r8_5 = ((temp_r7 * 5) + 1) * 4;
    temp_r7_2 = (temp_r7 + 1) * 4;
    temp_f3_5 = *(f32 *)((u8 *)arg1 + temp_r9_4);
    temp_f1_6 = *(f32 *)((u8 *)arg1 + temp_r10_5);
    temp_r0_3 = ((temp_r7 * 3) + 1) * 4;
    temp_f6_6 = *(f32 *)((u8 *)arg1 + temp_r5);
    temp_r3 = ((temp_r7 * 7) + 1) * 4;
    temp_f5_6 = *(f32 *)((u8 *)arg1 + temp_r6_2);
    temp_f9_6 = temp_f3_5 + temp_f1_6;
    temp_f11_5 = temp_f3_5 - temp_f1_6;
    temp_f8_7 = *(f32 *)((u8 *)arg1 + temp_r7_2);
    temp_f12_4 = temp_f6_6 + temp_f5_6;
    temp_f7_4 = *(f32 *)((u8 *)arg1 + temp_r8_5);
    temp_f4_6 = *(f32 *)((u8 *)arg1 + temp_r0_3);
    temp_f3_6 = *(f32 *)((u8 *)arg1 + temp_r3);
    temp_f10_6 = temp_f8_7 + temp_f7_4;
    temp_f7_5 = temp_f8_7 - temp_f7_4;
    temp_f8_8 = temp_f6_6 - temp_f5_6;
    temp_f30_3 = temp_f4_6 - temp_f3_6;
    *(f32 *)((u8 *)arg1 + temp_r9_4) = temp_f9_6 + temp_f12_4;
    temp_f13_3 = temp_f4_6 + temp_f3_6;
    temp_f6_7 = temp_f7_5 + temp_f8_8;
    temp_f5_7 = temp_f11_5 - temp_f30_3;
    *(f32 *)((u8 *)arg1 + temp_r7_2) = temp_f10_6 + temp_f13_3;
    temp_f2_4 = -temp_f0;
    *(f32 *)((u8 *)arg1 + temp_r5) = temp_f9_6 - temp_f12_4;
    temp_f5_8 = temp_f11_5 + temp_f30_3;
    *(f32 *)((u8 *)arg1 + temp_r0_3) = temp_f10_6 - temp_f13_3;
    temp_f6_8 = temp_f7_5 - temp_f8_8;
    *(f32 *)((u8 *)arg1 + temp_r10_5) = temp_f0 * (temp_f5_7 - temp_f6_7);
    *(f32 *)((u8 *)arg1 + temp_r8_5) = temp_f0 * (temp_f6_7 + temp_f5_7);
    *(f32 *)((u8 *)arg1 + temp_r6_2) = temp_f2_4 * (temp_f5_8 + temp_f6_8);
    *(f32 *)((u8 *)arg1 + temp_r3) = temp_f2_4 * (temp_f6_8 - temp_f5_8);
}

void fn_80123CEC(s32 count, void *dst, s32 srcIndex, void *src) {
    void *srcBase = src;
    void *temp_r31;
    if (count == 0x80) {
        temp_r31 = (u8 *)srcBase + ((srcIndex - 8) * 4);
        fn_80123E98(dst, temp_r31);
        {
            void *dst80 = (u8 *)dst + 0x80;
            fn_8012440C(dst80, (u8 *)srcBase + ((srcIndex - 0x20) * 4));
        }
        fn_80123E98((u8 *)dst + 0x100, temp_r31);
        fn_80123E98((u8 *)dst + 0x180, temp_r31);
        return;
    } else {
        void *tempElse;
        void *dst0 = dst;
        tempElse = (u8 *)srcBase + ((srcIndex - 0x10) * 4);
        fn_80124AD8(dst0, tempElse);
        fn_80124CE8((u8 *)dst + 0x40, tempElse);
        fn_80124AD8((u8 *)dst + 0x80, tempElse);
        fn_80124AD8((u8 *)dst + 0xC0, tempElse);
    }
}

#pragma scheduling reset
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

#pragma push
#pragma processor 750
void fn_80124F90(void *arg0) {
    register f32 r4_f12, r4_f11, r4_f10, r4_f9, r4_f0b, r4_f1b;
    register f32 r4_f7, r4_f2, r4_f3, r4_f8, r4_f6, r4_f4, r4_f5, r4_f0, r4_f1;

    r4_f1 = *(f32 *)((u8 *)arg0 + 0x0);
    r4_f0 = *(f32 *)((u8 *)arg0 + 0x10);
    r4_f5 = *(f32 *)((u8 *)arg0 + 0x4);
    r4_f4 = *(f32 *)((u8 *)arg0 + 0x14);
    r4_f6 = r4_f1 + r4_f0;
    r4_f8 = r4_f1 - r4_f0;
    r4_f3 = *(f32 *)((u8 *)arg0 + 0x8);
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
#pragma pop
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
    *(f32 *)((u8 *)arg0 + 4) = f2 - f0;
    *(f32 *)((u8 *)arg0 + 8) = f3 - f1;
    *(f32 *)((u8 *)arg0 + 0) = f3 + f1;
    *(f32 *)((u8 *)arg0 + 12) = f2 + f0;
}

void fn_801250CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 *a = (f32 *)arg1;
    f32 *w = (f32 *)arg3;
    s32 half = arg0 >> 1;
    s32 step = (arg2 * 2) / half;
    s32 stride = step * 4;
    s32 i = 0;
    s32 j = 2;
    f32 *p = a + 2;
    f32 *q = w;
    s32 n = (half - 1) >> 1;
    if (half > 2) {
        s32 k = n >> 1;
        while (k != 0) {
            i += step;
            {
                f32 x = p[0], y = w[arg2 - i], u = a[arg0 - j], v = p[1] + a[arg0 - j + 1];
                f32 z = lbl_80561210 - y;
                f32 t = x - u;
                f32 c = *q;
                f32 re = z * t - c * v;
                f32 im = z * v + c * t;
                p[0] = x - re; p[1] -= im;
                a[arg0-j] += re; a[arg0-j+1] -= im;
                i += step; j += 2;
            }
            {
                f32 x = p[2], y = w[arg2 - i], u = a[arg0 - j], v = p[3] + a[arg0-j+1];
                f32 z = lbl_80561210 - y;
                f32 t = x-u;
                f32 c = q[stride/4];
                f32 re = z*t-c*v;
                f32 im = z*v+c*t;
                p[2] = x-re; p[3] -= im;
                a[arg0-j] += re; a[arg0-j+1] -= im;
            }
            j += 2; p += 4; q += stride/4; k--;
        }
        n &= 1;
        if (n) {
            do {
                i += step;
                {
                    f32 x=p[0], y=w[arg2-i], u=a[arg0-j], v=p[1]+a[arg0-j+1];
                    f32 z=lbl_80561210-y, t=x-u, c=*q;
                    f32 re=z*t-c*v, im=z*v+c*t;
                    p[0]=x-re; p[1]-=im; a[arg0-j]+=re; a[arg0-j+1]-=im;
                }
                j+=2; p+=2; q+=stride/4;
            } while (--n);
        }
    }
}

void fn_801252D8(s32 n, f32 *a, s32 m, f32 *w) {
    s32 half, step, i, j, count, k, x, off;
    f32 *p, *q, *r;
    f32 t, u, c, d, e, z, h, l, v, y, re, im;
    half = n >> 1; step = (m * 2) / half; i = 0; j = 2;
    p = a + 2; q = w; count = (half - 1) >> 1;
    if (half <= 2) return;
    if ((count >> 1) != 0) {
        k = count >> 1;
        do {
            x = i + step; t = *p; u = w[m - x]; r = a + n - j;
            i = x + step; c = lbl_80561210 - u; d = t - r[0]; j += 2;
            e = p[1] + r[1]; z = *q; q += step; h = c * d; l = z * d;
            v = z * e; off = (n - j) * 4; y = c * e; j += 2;
            re = h + v; im = y - l; p[0] = t - re; p[1] -= im;
            r[0] += re; r[1] -= im; r = (f32 *)((u8 *)a + off);
            t = p[2]; c = lbl_80561210 - w[m - i]; d = t - r[0]; z = *q;
            q += step; e = p[3] + r[1]; h = c * d; v = z * e; l = z * d;
            y = c * e; re = h + v; im = y - l; p[2] = t - re; p[3] -= im;
            p += 4; r[0] += re; r[1] -= im;
        } while (--k != 0);
        count &= 1;
    }
    if (count != 0) {
        do {
            i += step; t = *p; off = (n - j) * 4; r = (f32 *)((u8 *)a + off);
            d = t - r[0]; j += 2; c = lbl_80561210 - w[m - i]; z = *q;
            q += step; e = p[1] + r[1]; h = c * d; l = z * d; v = z * e;
            y = c * e; re = h + v; im = y - l; p[0] = t - re; p[1] -= im;
            p += 2; r[0] += re; r[1] -= im;
        } while (--count != 0);
    }
}

void fn_801254E4(s32 arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    f32 *tw;
    f32 *out;
    s32 i;
    s32 j;
    s32 step;
    s32 half;
    u32 count;
    u32 pairs;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;

    tw = arg3;
    out = arg1 + 1;
    i = 1;
    j = 0;
    step = arg2 / arg0;
    half = arg0 >> 1;
    count = (u32)(half - 1);
    if (half <= 1) goto finish;
    pairs = count >> 1;
    while (pairs != 0) {
        j += step;
        a = arg3[arg2 - j];
        b = *(tw += step);
        e = b - a;
        f = b + a;
        c = out[0];
        d = arg1[arg0 - i];
        out[0] = e * c + f * d;
        arg1[arg0 - i] = f * c - e * d;
        i++;

        j += step;
        a = arg3[arg2 - j];
        b = *(tw += step);
        e = b - a;
        f = b + a;
        c = out[1];
        d = arg1[arg0 - i];
        out[1] = e * c + f * d;
        arg1[arg0 - i] = f * c - e * d;
        i++;
        out += 2;
        pairs--;
    }
    if (count & 1) {
        j += step;
        a = arg3[arg2 - j];
        b = *(tw += step);
        e = b - a;
        f = b + a;
        c = *out;
        d = arg1[arg0 - i];
        *out = e * c + f * d;
        arg1[arg0 - i] = f * c - e * d;
        out++;
        i++;
    }
finish:
    arg1[half] *= *arg3;
}

void fn_80125960(void *arg0, s32 arg1, void *arg2, void *arg3) {
    s32 sp8[64];
    register s32 *var_r12;
    register s32 *var_r4;
    s16 temp_r0, temp_r10, temp_r25, temp_r4, temp_r4_2, temp_r7, temp_r8, temp_r9;
    register s16 temp_r23;
    s32 temp_r0_2, temp_r0_3, temp_r0_4, temp_r0_5, temp_r0_6, temp_r0_7;
    s32 temp_r10_2, temp_r10_3, temp_r10_4, temp_r10_5, temp_r10_6;
    register s32 temp_r11;
    s32 temp_r11_2, temp_r11_3, temp_r11_4, temp_r11_5;
    s32 temp_r12, temp_r12_2, temp_r12_3, temp_r12_4, temp_r12_5;
    s32 temp_r23_2, temp_r23_3, temp_r23_4, temp_r23_5, temp_r23_6, temp_r23_7, temp_r23_8, temp_r23_9, temp_r23_10, temp_r23_11;
    register s32 temp_r24;
    s32 temp_r24_2, temp_r24_3, temp_r24_4, temp_r24_5, temp_r24_6, temp_r24_7, temp_r24_8;
    s32 temp_r25_2, temp_r25_3, temp_r25_4, temp_r25_5, temp_r25_6;
    s32 temp_r26, temp_r26_2, temp_r26_3, temp_r27, temp_r28, temp_r29; register s32 temp_r30;
    s32 temp_r4_3, temp_r4_4, temp_r5, temp_r5_2, temp_r6;
    s32 temp_r7_2, temp_r7_3, temp_r7_4, temp_r7_5;
    s32 temp_r8_2, temp_r8_3, temp_r8_4, temp_r8_5;
    s32 temp_r9_2, temp_r9_3, temp_r9_4, temp_r9_5, temp_r9_6, temp_r9_7, temp_r9_8;
    s32 var_ctr, var_ctr_2;
    u32 temp_r11_6;
    register u8 *var_r31;
    register u8 *var_r3;
    register s16 *var_r5;
    register s32 *var_r6;
    var_r3 = (u8 *)arg0;
    var_r5 = (s16 *)arg2;
    var_r6 = (s32 *)arg3;
    var_r31 = var_r3 + arg1;
    temp_r30 = arg1 * 2;
    var_r12 = sp8;
    for (var_ctr = 8; var_ctr != 0; var_ctr--) {
        temp_r7 = var_r5[8];
        temp_r8 = var_r5[24];
        temp_r23 = var_r5[16];
        temp_r0 = var_r5[32];
        temp_r4 = var_r5[48];
        temp_r9 = var_r5[40];
        temp_r24 = temp_r8 | temp_r7;
        temp_r4 = var_r5[48];
        temp_r9 = var_r5[40];
        temp_r11 = temp_r0 | temp_r23;
        temp_r10 = var_r5[56];
        temp_r24 = temp_r4 | temp_r24;
        temp_r11 = temp_r9 | temp_r11;
        temp_r24 = temp_r10 | temp_r24;
        if ((temp_r24 | temp_r11) == 0) {
            temp_r4_2 = var_r5[0];
            var_r5++;
            temp_r0_2 = var_r6[0];
            var_r6++;
            temp_r0_3 = (s32)(temp_r4_2 * temp_r0_2) >> 11;
            var_r12[0] = temp_r0_3;
            var_r12[8] = temp_r0_3;
            var_r12[16] = temp_r0_3;
            var_r12[24] = temp_r0_3;
            var_r12[32] = temp_r0_3;
            var_r12[40] = temp_r0_3;
            var_r12[48] = temp_r0_3;
            var_r12[56] = temp_r0_3;
            var_r12++;
        } else {
            temp_r25 = var_r5[0];
            var_r5++;
            temp_r25_2 = var_r6[32];
            temp_r26 = var_r6[8];
            temp_r27 = var_r6[24];
            temp_r11 = var_r6[48];
            temp_r28 = var_r6[40];
            temp_r24 = temp_r23 * var_r6[16];
            temp_r23_2 = temp_r25 * var_r6[0] >> 11;
            temp_r29 = var_r6[56];
            var_r6++;
            temp_r24_2 = temp_r24 >> 11;
            temp_r25_3 = temp_r0 * temp_r25_2 >> 11;
            temp_r11_2 = temp_r23_2 + temp_r25_3;
            temp_r23_3 = temp_r23_2 - temp_r25_3;
            temp_r0_4 = temp_r4 * temp_r11 >> 11;
            temp_r25_4 = temp_r24_2 + temp_r0_4;
            temp_r0_5 = temp_r11_2 + temp_r25_4;
            temp_r11_3 = temp_r11_2 - temp_r25_4;
            temp_r24_3 = ((temp_r24_2 - temp_r0_4) * 0xB50 >> 11) - temp_r25_4;
            temp_r4_3 = temp_r23_3 + temp_r24_3;
            temp_r7_2 = temp_r23_3 - temp_r24_3;
            temp_r23_4 = temp_r7 * temp_r26 >> 11;
            temp_r9_2 = temp_r8 * temp_r27 >> 11;
            temp_r24_4 = temp_r9 * temp_r28 >> 11;
            temp_r25_5 = temp_r24_4 - temp_r9_2;
            temp_r24_5 = temp_r24_4 + temp_r9_2;
            temp_r9_3 = temp_r10 * temp_r29 >> 11;
            temp_r8_2 = temp_r23_4 - temp_r9_3;
            temp_r10_2 = temp_r23_4 + temp_r9_3;
            temp_r23_5 = temp_r10_2 + temp_r24_5;
            var_r12[0] = temp_r0_5 + temp_r23_5;
            temp_r24_6 = (temp_r25_5 + temp_r8_2) * 0xEC8 >> 11;
            var_r12[56] = temp_r0_5 - temp_r23_5;
            temp_r23_6 = temp_r24_6 + (temp_r25_5 * -0x14E8 >> 11) - temp_r23_5;
            var_r12[8] = temp_r4_3 + temp_r23_6;
            var_r12[48] = temp_r4_3 - temp_r23_6;
            temp_r9_4 = ((temp_r10_2 - temp_r24_5) * 0xB50 >> 11) - temp_r23_6;
            var_r12[16] = temp_r7_2 + temp_r9_4;
            var_r12[40] = temp_r7_2 - temp_r9_4;
            temp_r4_4 = ((temp_r8_2 * 0x8A9) >> 11) - temp_r24_6;
            temp_r4_4 += temp_r9_4;
            var_r12[32] = temp_r11_3 + temp_r4_4;
            var_r12[24] = temp_r11_3 - temp_r4_4;
            var_r12++;
        }
    }
    var_r4 = sp8;
    for (var_ctr_2 = 8; var_ctr_2 != 0; var_ctr_2--) {
        temp_r9_5 = M2C_FIELD(var_r4, s32 *, 0x18);
        temp_r11_4 = M2C_FIELD(var_r4, s32 *, 8);
        temp_r5 = M2C_FIELD(var_r4, s32 *, 0xC);
        temp_r7_3 = M2C_FIELD(var_r4, s32 *, 0x14);
        temp_r12 = M2C_FIELD(var_r4, s32 *, 0x1C);
        temp_r23_7 = M2C_FIELD(var_r4, s32 *, 4);
        temp_r0_6 = temp_r7_3 - temp_r5;
        temp_r26_2 = temp_r7_3 + temp_r5;
        temp_r8_3 = M2C_FIELD(var_r4, s32 *, 0x10);
        temp_r5_2 = temp_r23_7 - temp_r12;
        temp_r10_3 = M2C_FIELD(var_r4, s32 *, 0);
        temp_r24_7 = temp_r11_4 + temp_r9_5;
        temp_r12_2 = temp_r23_7 + temp_r12;
        temp_r23_8 = temp_r10_3 + temp_r8_3;
        temp_r11_5 = temp_r10_3 - temp_r8_3;
        temp_r25_6 = ((temp_r11_4 - temp_r9_5) * 0xB50 >> 11) - temp_r24_7;
        temp_r7_4 = temp_r23_8 + temp_r24_7;
        temp_r26_3 = temp_r12_2 + temp_r26_2;
        temp_r6 = (temp_r0_6 + temp_r5_2) * 0xEC8 >> 11;
        temp_r12_3 = temp_r11_5 + temp_r25_6;
        temp_r0_7 = temp_r11_5 - temp_r25_6;
        temp_r8_4 = temp_r7_4 + temp_r26_3 + 0x7F;
        temp_r11_6 = (temp_r7_4 - temp_r26_3) + 0x7F;
        temp_r7_5 = (temp_r12_2 - temp_r26_2) * 0xB50;
        temp_r23_9 = temp_r23_8 - temp_r24_7;
        temp_r9_6 = temp_r6 + (temp_r0_6 * -0x14E8 >> 11);
        var_r4 += 8;
        temp_r10_4 = temp_r9_6 - temp_r26_3;
        temp_r24_8 = (temp_r7_5 >> 11) - temp_r10_4;
        temp_r8_5 = ((temp_r5_2 * 0x8A9 >> 11) - temp_r6) + temp_r24_8;
        temp_r12_4 = ((u8)((u32)(temp_r12_3 + temp_r10_4 + 0x7F) >> 8) & ~0xFF0000) | (((temp_r8_4 >> 8) << 16) & 0xFF0000);
        temp_r12_5 = temp_r12_4 | (temp_r12_4 << 8);
        temp_r23_10 = ((((temp_r12_3 - temp_r10_4) + 0x7F) << 8) & 0xFF0000 & ~0xFF) | ((temp_r11_6 >> 8) & 0xFF);
        temp_r9_7 = ((u8)((u32)((temp_r23_9 - temp_r8_5) + 0x7F) >> 8) & ~0xFF0000) | ((((s32)(temp_r0_7 + temp_r24_8 + 0x7F) >> 8) << 16) & 0xFF0000);
        M2C_FIELD(var_r3, s32 *, 0) = temp_r12_5;
        temp_r9_8 = temp_r9_7 | (temp_r9_7 << 8);
        temp_r10_5 = (((temp_r23_9 + temp_r8_5 + 0x7F) << 8) & 0xFF0000 & ~0xFF) | (((u32)(temp_r0_7 - temp_r24_8 + 0x7F) >> 8) & 0xFF);
        M2C_FIELD(var_r3, s32 *, 4) = temp_r9_8;
        temp_r23_11 = temp_r23_10 | (temp_r23_10 << 8);
        temp_r10_6 = temp_r10_5 | (temp_r10_5 << 8);
        M2C_FIELD(var_r3, s32 *, 8) = temp_r10_6;
        M2C_FIELD(var_r3, s32 *, 0xC) = temp_r23_11;
        var_r3 += temp_r30;
        M2C_FIELD(var_r31, s32 *, 0) = temp_r12_5;
        M2C_FIELD(var_r31, s32 *, 4) = temp_r9_8;
        M2C_FIELD(var_r31, s32 *, 8) = temp_r10_6;
        M2C_FIELD(var_r31, s32 *, 0xC) = temp_r23_11;
        var_r31 += temp_r30;
    }
}

extern void fn_80125664(void *p0, void *p1, void *p2, void *p3);
void fn_80125CA0(void *arg0, void *arg1, void *arg2, s32 arg3) {
    fn_80125664(arg0, arg1, arg2, (u8 *)&lbl_802F6A40 + (arg3 << 8));
}

extern void fn_80125960(void *p0, s32 p1, void *p2, void *p3);
void fn_80125CB4(void *arg0, void *arg1, void *arg2, s32 arg3) {
    fn_80125960(arg0, (s32)arg1, arg2, (u8 *)&lbl_802F6A40 + (arg3 << 8));
}

extern u8 lbl_802F7A40[];
void fn_80125CC8(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, s32 arg5) {
    s32 sp8[64];
    register u8 *var_r6;
    register u8 *var_r6_2;
    s16 temp_r0;
    s16 temp_r10;
    s16 temp_r10_2;
    s16 temp_r11;
    s16 temp_r12;
    s16 temp_r22;
    s16 temp_r26;
    s16 temp_r30;
    s16 temp_r31;
    s32 temp_r0_10;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 temp_r10_10;
    s32 temp_r10_3;
    s32 temp_r10_4;
    s32 temp_r10_5;
    s32 temp_r10_6;
    s32 temp_r10_7;
    s32 temp_r10_8;
    s32 temp_r10_9;
    s32 temp_r11_2;
    s32 temp_r11_3;
    s32 temp_r11_4;
    s32 temp_r12_2;
    s32 temp_r12_3;
    s32 temp_r20;
    s32 temp_r20_2;
    s32 temp_r20_3;
    s32 temp_r20_4;
    s32 temp_r20_5;
    s32 temp_r20_6;
    s32 temp_r21;
    s32 temp_r21_2;
    s32 temp_r22_2;
    s32 temp_r22_3;
    s32 temp_r23;
    s32 temp_r23_2;
    s32 temp_r23_3;
    s32 temp_r24;
    s32 temp_r24_2;
    s32 temp_r24_3;
    s32 temp_r25;
    s32 temp_r25_2;
    s32 temp_r25_3;
    s32 temp_r25_4;
    s32 temp_r26_2;
    s32 temp_r26_3;
    s32 temp_r26_4;
    s32 temp_r26_5;
    s32 temp_r27;
    s32 temp_r27_2;
    s32 temp_r28;
    s32 temp_r28_2;
    s32 temp_r28_3;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r29_3;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r31_2;
    s32 temp_r31_3;
    s32 temp_r31_4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 var_ctr;
    s32 var_ctr_2;
    u8 temp_r5_3;
    register u8 *var_r3;
    register u8 *var_r5;
    register u8 *var_r7;
    register u8 *var_r9;

    var_r3 = arg0;
    var_r5 = arg2;
    var_r7 = arg4;
    var_r9 = lbl_802F7A40 + (arg3 << 8);
    var_r6 = (u8 *)&sp8;
    for (var_ctr = 0; var_ctr < 8; var_ctr++) {
        temp_r31 = M2C_FIELD(var_r5, s16 *, 0x60);
        temp_r12 = M2C_FIELD(var_r5, s16 *, 0x50);
        temp_r11 = M2C_FIELD(var_r5, s16 *, 0x40);
        temp_r10 = M2C_FIELD(var_r5, s16 *, 0x30);
        temp_r30 = M2C_FIELD(var_r5, s16 *, 0x70);
        temp_r0 = M2C_FIELD(var_r5, s16 *, 0x10);
        temp_r26 = M2C_FIELD(var_r5, s16 *, 0x20);
        if ((temp_r30 | (temp_r31 | temp_r12) | (temp_r11 | temp_r10 | (temp_r0 | temp_r26))) == 0) {
            temp_r10_2 = M2C_FIELD(var_r5, s16 *, 0);
            var_r5 += 2;
            temp_r0_2 = M2C_FIELD(var_r9, s32 *, 0);
            var_r9 += 4;
            temp_r0_3 = (s32) (temp_r10_2 * temp_r0_2) >> 0xB;
            M2C_FIELD(var_r6, s32 *, 0) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0x20) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0x40) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0x60) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0x80) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0xA0) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0xC0) = temp_r0_3;
            M2C_FIELD(var_r6, s32 *, 0xE0) = temp_r0_3;
            var_r6 += 4;
        } else {
            temp_r22 = M2C_FIELD(var_r5, s16 *, 0);
            var_r5 += 2;
            temp_r25 = M2C_FIELD(var_r9, s32 *, 0x80);
            temp_r24 = M2C_FIELD(var_r9, s32 *, 0xC0);
            temp_r20 = M2C_FIELD(var_r9, s32 *, 0x20);
            temp_r23 = M2C_FIELD(var_r9, s32 *, 0x60);
            temp_r22_2 = M2C_FIELD(var_r9, s32 *, 0xA0);
            temp_r26_2 = temp_r26 * M2C_FIELD(var_r9, s32 *, 0x40);
            temp_r29 = (s32) (temp_r22 * M2C_FIELD(var_r9, s32 *, 0)) >> 0xB;
            temp_r21 = M2C_FIELD(var_r9, s32 *, 0xE0);
            var_r9 += 4;
            temp_r11_2 = temp_r26_2 >> 0xB;
            temp_r28 = (s32) (temp_r11 * temp_r25) >> 0xB;
            temp_r27 = temp_r29 + temp_r28;
            temp_r26_3 = temp_r29 - temp_r28;
            temp_r31_2 = (s32) (temp_r31 * temp_r24) >> 0xB;
            temp_r24_2 = temp_r11_2 + temp_r31_2;
            temp_r29_2 = temp_r27 + temp_r24_2;
            temp_r31_3 = temp_r27 - temp_r24_2;
            temp_r25_2 = ((s32) ((temp_r11_2 - temp_r31_2) * 0xB50) >> 0xB) - temp_r24_2;
            temp_r11_3 = temp_r26_3 + temp_r25_2;
            temp_r28_2 = temp_r26_3 - temp_r25_2;
            temp_r0_4 = (s32) (temp_r0 * temp_r20) >> 0xB;
            temp_r10_3 = (s32) (temp_r10 * temp_r23) >> 0xB;
            temp_r20_2 = (s32) (temp_r12 * temp_r22_2) >> 0xB;
            temp_r12_2 = temp_r20_2 - temp_r10_3;
            temp_r23_2 = temp_r20_2 + temp_r10_3;
            temp_r10_4 = (s32) (temp_r30 * temp_r21) >> 0xB;
            temp_r30_2 = temp_r0_4 - temp_r10_4;
            temp_r0_5 = temp_r0_4 + temp_r10_4;
            temp_r10_5 = temp_r0_5 + temp_r23_2;
            M2C_FIELD(var_r6, s32 *, 0) = (s32) (temp_r29_2 + temp_r10_5);
            M2C_FIELD(var_r6, s32 *, 0xE0) = (s32) (temp_r29_2 - temp_r10_5);
            temp_r20_3 = (s32) ((temp_r12_2 + temp_r30_2) * 0xEC8) >> 0xB;
            temp_r20_4 = (temp_r20_3 + ((s32) (temp_r12_2 * -0x14E8) >> 0xB)) - temp_r10_5;
            temp_r10_6 = ((s32) ((temp_r0_5 - temp_r23_2) * 0xB50) >> 0xB) - temp_r20_4;
            M2C_FIELD(var_r6, s32 *, 0x20) = (s32) (temp_r11_3 + temp_r20_4);
            M2C_FIELD(var_r6, s32 *, 0xC0) = (s32) (temp_r11_3 - temp_r20_4);
            temp_r0_6 = (((s32) (temp_r30_2 * 0x8A9) >> 0xB) - temp_r20_3) + temp_r10_6;
            M2C_FIELD(var_r6, s32 *, 0x40) = (s32) (temp_r28_2 + temp_r10_6);
            M2C_FIELD(var_r6, s32 *, 0xA0) = (s32) (temp_r28_2 - temp_r10_6);
            M2C_FIELD(var_r6, s32 *, 0x80) = (s32) (temp_r31_3 + temp_r0_6);
            M2C_FIELD(var_r6, s32 *, 0x60) = (s32) (temp_r31_3 - temp_r0_6);
            var_r6 += 4;
        }
    }
    var_r6_2 = (u8 *)&sp8;
    for (var_ctr_2 = 0; var_ctr_2 < 8; var_ctr_2++) {
        temp_r22_3 = M2C_FIELD(var_r6_2, s32 *, 8);
        temp_r21_2 = M2C_FIELD(var_r6_2, s32 *, 0x18);
        temp_r10_7 = M2C_FIELD(var_r6_2, s32 *, 0x14);
        temp_r0_7 = M2C_FIELD(var_r6_2, s32 *, 0xC);
        temp_r9 = M2C_FIELD(var_r6_2, s32 *, 4);
        temp_r5 = M2C_FIELD(var_r6_2, s32 *, 0x1C);
        temp_r12_3 = temp_r10_7 - temp_r0_7;
        temp_r23_3 = temp_r10_7 + temp_r0_7;
        temp_r25_3 = M2C_FIELD(var_r6_2, s32 *, 0);
        temp_r10_8 = M2C_FIELD(var_r6_2, s32 *, 0x10);
        temp_r30_3 = temp_r9 - temp_r5;
        temp_r0_8 = temp_r9 + temp_r5;
        temp_r24_3 = temp_r22_3 + temp_r21_2;
        temp_r27_2 = temp_r25_3 + temp_r10_8;
        temp_r26_4 = temp_r25_3 - temp_r10_8;
        temp_r25_4 = ((s32) ((temp_r22_3 - temp_r21_2) * 0xB50) >> 0xB) - temp_r24_3;
        temp_r10_9 = temp_r0_8 + temp_r23_3;
        temp_r29_3 = temp_r27_2 + temp_r24_3;
        temp_r11_4 = temp_r26_4 + temp_r25_4;
        temp_r28_3 = temp_r26_4 - temp_r25_4;
        temp_r0_9 = (temp_r29_3 - temp_r10_9) + 0x7F;
        temp_r26_5 = (s32) ((temp_r0_8 - temp_r23_3) * 0xB50) >> 0xB;
        temp_r31_4 = temp_r27_2 - temp_r24_3;
        temp_r5_2 = temp_r30_3 * 0x8A9;
        temp_r20_5 = (s32) ((temp_r12_3 + temp_r30_3) * 0xEC8) >> 0xB;
        temp_r9_2 = temp_r29_3 + temp_r10_9 + 0x7F;
        var_r6_2 += 0x20;
        M2C_FIELD(var_r3, s8 *, 0) = (s8) (M2C_FIELD(var_r7, u8 *, 0) + (temp_r9_2 >> 8));
        temp_r20_6 = (temp_r20_5 + ((s32) (temp_r12_3 * -0x14E8) >> 0xB)) - temp_r10_9;
        temp_r10_10 = temp_r26_5 - temp_r20_6;
        M2C_FIELD(var_r3, s8 *, 7) = (s8) (M2C_FIELD(var_r7, u8 *, 7) + (temp_r0_9 >> 8));
        temp_r0_10 = ((temp_r5_2 >> 0xB) - temp_r20_5) + temp_r10_10;
        M2C_FIELD(var_r3, s8 *, 1) = (s8) (M2C_FIELD(var_r7, u8 *, 1) + ((s32) (temp_r11_4 + temp_r20_6 + 0x7F) >> 8));
        M2C_FIELD(var_r3, s8 *, 6) = (s8) (M2C_FIELD(var_r7, u8 *, 6) + ((s32) ((temp_r11_4 - temp_r20_6) + 0x7F) >> 8));
        M2C_FIELD(var_r3, s8 *, 2) = (s8) (M2C_FIELD(var_r7, u8 *, 2) + ((s32) (temp_r28_3 + temp_r10_10 + 0x7F) >> 8));
        M2C_FIELD(var_r3, s8 *, 5) = (s8) (M2C_FIELD(var_r7, u8 *, 5) + ((s32) ((temp_r28_3 - temp_r10_10) + 0x7F) >> 8));
        M2C_FIELD(var_r3, s8 *, 3) = (s8) (M2C_FIELD(var_r7, u8 *, 3) + ((s32) ((temp_r31_4 - temp_r0_10) + 0x7F) >> 8));
        temp_r5_3 = M2C_FIELD(var_r7, u8 *, 4);
        var_r7 += arg5;
        M2C_FIELD(var_r3, s8 *, 4) = (s8) (temp_r5_3 + ((s32) (temp_r31_4 + temp_r0_10 + 0x7F) >> 8));
        var_r3 += arg1;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80126A10(s8 *arg0, void *arg1, u32 arg2) {
    struct Layout {
        u32 scratch[16];
        u8 gap[0x44];
        u8 table[4];
        u8 pad[0x30];
    } layout;
    u8 *bytes;
    s32 temp_cr0_eq;
    s32 temp_cr0_eq_2;
    s32 temp_cr0_eq_3;
    s32 temp_cr0_eq_4;
    s32 temp_cr0_eq_5;
    s32 temp_cr0_eq_6;
    s32 temp_r24;
    s32 var_ctr;
    s32 var_r24;
    u32 var_r27;
    s32 var_r31;
    s32 var_r8;
    s8 temp_r7_2;
    s8 var_r12;
    s8 var_r24_13;
    s8 var_r24_2;
    s8 var_r24_6;
    s8 var_r25;
    s8 var_r25_2;
    s8 var_r25_3;
    u32 *var_r29;
    u32 temp_r26_2;
    u32 temp_r26_3;
    u32 temp_r27;
    u32 temp_r28;
    u32 temp_r7;
    u32 var_r11;
    u32 var_r24_10;
    u32 var_r24_11;
    u32 var_r24_12;
    u32 var_r24_14;
    u32 var_r24_3;
    u32 var_r24_4;
    u32 var_r24_5;
    u32 var_r24_7;
    u32 var_r24_8;
    u32 var_r24_9;
    u32 var_r26_2;
    u32 var_r28;
    u32 var_r30;
    u8 *var_r10;
    u8 *var_r11_2;
    u8 *var_r26;
    u8 *var_r9;
    u8 temp_r25;
    u8 temp_r26;
    var_r30 = 0U;
    temp_r27 = M2C_FIELD(arg1, u32 *, 8);
    var_r29 = M2C_FIELD(arg1, u32 **, 4);
    temp_r28 = M2C_FIELD(arg1, u32 *, 0);
    if (temp_r27 < 3U) {
        temp_r7 = *var_r29;
        var_r29 += 1;
        var_r27 = temp_r27 + 0x1D;
        var_r28 = temp_r7 >> (3 - temp_r27);
        var_r24 = (temp_r28 | (temp_r7 << temp_r27)) & 7;
    } else {
        var_r24 = temp_r28 & 7;
        var_r28 = temp_r28 >> 3U;
        var_r27 = temp_r27 - 3;
    }
    var_r9 = layout.table;
    layout.table[0] = 0x10;
    var_r12 = 1 << var_r24;
    var_r10 = var_r9 + 4;
    var_r8 = var_r24 + 1;
    layout.table[1] = 0x60;
    var_r31 = 0;
    layout.table[2] = 0xB0;
    layout.table[3] = 2;
    bytes = (u8 *)layout.scratch;
loop_84:
    if (var_r8 != 0) {
        temp_r7_2 = -var_r12;
        var_r26 = bytes;
        var_ctr = var_r31;
        if (var_r31 > 0) {
loop_5:
            if (var_r27 == 0) {
                var_r11 = *var_r29;
                var_r27 = 0x1F;
                var_r29 += 1;
                var_r28 = var_r11 >> 1U;
            } else {
                var_r11 = var_r28;
                var_r28 = var_r28 >> 1U;
                var_r27 -= 1;
            }
            if (var_r11 & 1) {
                temp_r25 = *var_r26;
                var_r24_2 = var_r12;
                if ((s8) *(arg0 + temp_r25) < 0) {
                    var_r24_2 = temp_r7_2;
                }
                temp_cr0_eq = var_r30 == arg2;
                var_r30 += 1;
                *(arg0 + temp_r25) = *(arg0 + temp_r25) + var_r24_2;
                if (temp_cr0_eq == 0) {
                    goto block_12;
                }
            } else {
block_12:
                var_r26 += 1;
                var_ctr -= 1;
                if (var_ctr == 0) {
                    goto block_13;
                }
                goto loop_5;
            }
        } else {
block_13:
            var_r11_2 = var_r9;
loop_82:
            if (var_r11_2 >= var_r10) {
                var_r12 = (s8) (var_r12 >> 1);
                var_r8 -= 1;
                goto loop_84;
            }
            temp_r26 = *var_r11_2;
            if ((s32) temp_r26 != 0) {
                if (var_r27 == 0) {
                    var_r24_3 = *var_r29;
                    var_r27 = 0x1F;
                    var_r29 += 1;
                    var_r28 = var_r24_3 >> 1U;
                } else {
                    var_r24_3 = var_r28;
                    var_r28 = var_r28 >> 1U;
                    var_r27 -= 1;
                }
                if (var_r24_3 & 1) {
                    temp_r24 = temp_r26 & 3;
                    switch (temp_r24) {             /* irregular */
                    case 0:
                        var_r26_2 = temp_r26 >> 2U;
                        *var_r11_2 = ((var_r26_2 + 4) * 4) + 1;
block_29:
                        if (var_r27 == 0) {
                            var_r24_4 = *var_r29;
                            var_r27 = 0x1F;
                            var_r29 += 1;
                            var_r28 = var_r24_4 >> 1U;
                        } else {
                            var_r24_4 = var_r28;
                            var_r28 = var_r28 >> 1U;
                            var_r27 -= 1;
                        }
                        if (var_r24_4 & 1) {
                            var_r9 -= 1;
                            M2C_FIELD(var_r9, s8 *, -1) = (s8) ((var_r26_2 * 4) + 3);
                            goto block_40;
                        }
                        bytes[var_r31] = (u8) var_r26_2;
                        var_r31 += 1;
                        if (var_r27 == 0) {
                            var_r24_5 = *var_r29;
                            var_r27 = 0x1F;
                            var_r29 += 1;
                            var_r28 = var_r24_5 >> 1U;
                        } else {
                            var_r24_5 = var_r28;
                            var_r28 = var_r28 >> 1U;
                            var_r27 -= 1;
                        }
                        var_r24_6 = var_r12;
                        if (var_r24_5 & 1) {
                            var_r24_6 = temp_r7_2;
                        }
                        temp_cr0_eq_2 = var_r30 == arg2;
                        *(arg0 + var_r26_2) = var_r24_6;
                        var_r30 += 1;
                        if (temp_cr0_eq_2 == 0) {
block_40:
                            if (var_r27 == 0) {
                                var_r24_7 = *var_r29;
                                var_r27 = 0x1F;
                                var_r29 += 1;
                                var_r28 = var_r24_7 >> 1U;
                            } else {
                                var_r24_7 = var_r28;
                                var_r28 = var_r28 >> 1U;
                                var_r27 -= 1;
                            }
                            if (var_r24_7 & 1) {
                                var_r9 -= 1;
                                M2C_FIELD(var_r9, s8 *, -1) = (s8) (((var_r26_2 + 1) * 4) + 3);
                                goto block_51;
                            }
                            bytes[var_r31] = var_r26_2 + 1;
                            var_r31 += 1;
                            if (var_r27 == 0) {
                                var_r24_8 = *var_r29;
                                var_r27 = 0x1F;
                                var_r29 += 1;
                                var_r28 = var_r24_8 >> 1U;
                            } else {
                                var_r24_8 = var_r28;
                                var_r28 = var_r28 >> 1U;
                                var_r27 -= 1;
                            }
                            var_r25 = var_r12;
                            if (var_r24_8 & 1) {
                                var_r25 = temp_r7_2;
                            }
                            temp_cr0_eq_3 = var_r30 == arg2;
                            M2C_FIELD((arg0 + var_r26_2), s8 *, 1) = var_r25;
                            var_r30 += 1;
                            if (temp_cr0_eq_3 == 0) {
block_51:
                                if (var_r27 == 0) {
                                    var_r24_9 = *var_r29;
                                    var_r27 = 0x1F;
                                    var_r29 += 1;
                                    var_r28 = var_r24_9 >> 1U;
                                } else {
                                    var_r24_9 = var_r28;
                                    var_r28 = var_r28 >> 1U;
                                    var_r27 -= 1;
                                }
                                if (var_r24_9 & 1) {
                                    var_r9 -= 1;
                                    M2C_FIELD(var_r9, s8 *, -1) = (s8) (((var_r26_2 + 2) * 4) + 3);
                                    goto block_62;
                                }
                                bytes[var_r31] = var_r26_2 + 2;
                                var_r31 += 1;
                                if (var_r27 == 0) {
                                    var_r24_10 = *var_r29;
                                    var_r27 = 0x1F;
                                    var_r29 += 1;
                                    var_r28 = var_r24_10 >> 1U;
                                } else {
                                    var_r24_10 = var_r28;
                                    var_r28 = var_r28 >> 1U;
                                    var_r27 -= 1;
                                }
                                var_r25_2 = var_r12;
                                if (var_r24_10 & 1) {
                                    var_r25_2 = temp_r7_2;
                                }
                                temp_cr0_eq_4 = var_r30 == arg2;
                                M2C_FIELD((arg0 + var_r26_2), s8 *, 2) = var_r25_2;
                                var_r30 += 1;
                                if (temp_cr0_eq_4 == 0) {
block_62:
                                    if (var_r27 == 0) {
                                        var_r24_11 = *var_r29;
                                        var_r27 = 0x1F;
                                        var_r29 += 1;
                                        var_r28 = var_r24_11 >> 1U;
                                    } else {
                                        var_r24_11 = var_r28;
                                        var_r28 = var_r28 >> 1U;
                                        var_r27 -= 1;
                                    }
                                    if (var_r24_11 & 1) {
                                        var_r9 -= 1;
                                        M2C_FIELD(var_r9, s8 *, -1) = (s8) (((var_r26_2 + 3) * 4) + 3);
                                        goto loop_82;
                                    }
                                    bytes[var_r31] = var_r26_2 + 3;
                                    var_r31 += 1;
                                    if (var_r27 == 0) {
                                        var_r24_12 = *var_r29;
                                        var_r27 = 0x1F;
                                        var_r29 += 1;
                                        var_r28 = var_r24_12 >> 1U;
                                    } else {
                                        var_r24_12 = var_r28;
                                        var_r28 = var_r28 >> 1U;
                                        var_r27 -= 1;
                                    }
                                    var_r24_13 = var_r12;
                                    if (var_r24_12 & 1) {
                                        var_r24_13 = temp_r7_2;
                                    }
                                    temp_cr0_eq_5 = var_r30 == arg2;
                                    M2C_FIELD((arg0 + var_r26_2), s8 *, 3) = var_r24_13;
                                    var_r30 += 1;
                                    if (temp_cr0_eq_5 == 0) {
                                        goto loop_82;
                                    }
                                }
                            }
                        }
                        break;
                    case 1:
                        temp_r26_2 = temp_r26 >> 2U;
                        *var_r11_2 = (temp_r26_2 * 4) + 2;
                        M2C_FIELD(var_r10, u8 *, 0) = ((temp_r26_2 + 4) * 4) + 2;
                        M2C_FIELD(var_r10, s8 *, 1) = (s8) (((temp_r26_2 + 8) * 4) + 2);
                        M2C_FIELD(var_r10, s8 *, 2) = (s8) (((temp_r26_2 + 0xC) * 4) + 2);
                        var_r10 += 3;
                        goto loop_82;
                    case 2:
                        *var_r11_2 = 0;
                        var_r26_2 = temp_r26 >> 2U;
                        var_r11_2 += 1;
                        goto block_29;
                    case 3:
                        temp_r26_3 = temp_r26 >> 2U;
                        bytes[var_r31] = (u8) temp_r26_3;
                        var_r31 += 1;
                        if (var_r27 == 0) {
                            var_r24_14 = *var_r29;
                            var_r27 = 0x1F;
                            var_r29 += 1;
                            var_r28 = var_r24_14 >> 1U;
                        } else {
                            var_r24_14 = var_r28;
                            var_r28 = var_r28 >> 1U;
                            var_r27 -= 1;
                        }
                        var_r25_3 = var_r12;
                        if (var_r24_14 & 1) {
                            var_r25_3 = temp_r7_2;
                        }
                        temp_cr0_eq_6 = var_r30 == arg2;
                        *(arg0 + temp_r26_3) = var_r25_3;
                        var_r30 += 1;
                        if (temp_cr0_eq_6 == 0) {
                            *var_r11_2 = 0;
                            goto block_81;
                        }
                        break;
                    }
                } else {
                    goto block_81;
                }
            } else {
block_81:
                var_r11_2 += 1;
                goto loop_82;
            }
        }
    }
    M2C_FIELD(arg1, u32 **, 4) = var_r29;
    M2C_FIELD(arg1, u32 *, 0) = var_r28;
    M2C_FIELD(arg1, u32 *, 8) = (u32) var_r27;
}
#pragma pop
extern void fn_80126A10(s8 *, void *, u32);
void fn_80126EF0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5) {
    u32 temp[16] = {0};
    u8 *dst = arg0;
    u8 *src = arg4;
    fn_80126A10((s8 *)temp, (void *)arg2, (u32)arg3);
    dst[0] = ((u8 *)temp)[0] + src[0];
    dst[1] = ((u8 *)temp)[1] + src[1];
    dst[2] = ((u8 *)temp)[4] + src[2];
    dst[3] = ((u8 *)temp)[5] + src[3];
    dst[4] = ((u8 *)temp)[8] + src[4];
    dst[5] = ((u8 *)temp)[9] + src[5];
    dst[6] = ((u8 *)temp)[12] + src[6];
    dst[7] = ((u8 *)temp)[13] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[2] + src[0];
    dst[1] = ((u8 *)temp)[3] + src[1];
    dst[2] = ((u8 *)temp)[6] + src[2];
    dst[3] = ((u8 *)temp)[7] + src[3];
    dst[4] = ((u8 *)temp)[10] + src[4];
    dst[5] = ((u8 *)temp)[11] + src[5];
    dst[6] = ((u8 *)temp)[14] + src[6];
    dst[7] = ((u8 *)temp)[15] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[24] + src[0];
    dst[1] = ((u8 *)temp)[25] + src[1];
    dst[2] = ((u8 *)temp)[44] + src[2];
    dst[3] = ((u8 *)temp)[45] + src[3];
    dst[4] = ((u8 *)temp)[16] + src[4];
    dst[5] = ((u8 *)temp)[17] + src[5];
    dst[6] = ((u8 *)temp)[20] + src[6];
    dst[7] = ((u8 *)temp)[21] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[26] + src[0];
    dst[1] = ((u8 *)temp)[27] + src[1];
    dst[2] = ((u8 *)temp)[46] + src[2];
    dst[3] = ((u8 *)temp)[47] + src[3];
    dst[4] = ((u8 *)temp)[18] + src[4];
    dst[5] = ((u8 *)temp)[19] + src[5];
    dst[6] = ((u8 *)temp)[22] + src[6];
    dst[7] = ((u8 *)temp)[23] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[28] + src[0];
    dst[1] = ((u8 *)temp)[29] + src[1];
    dst[2] = ((u8 *)temp)[32] + src[2];
    dst[3] = ((u8 *)temp)[33] + src[3];
    dst[4] = ((u8 *)temp)[48] + src[4];
    dst[5] = ((u8 *)temp)[49] + src[5];
    dst[6] = ((u8 *)temp)[52] + src[6];
    dst[7] = ((u8 *)temp)[53] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[30] + src[0];
    dst[1] = ((u8 *)temp)[31] + src[1];
    dst[2] = ((u8 *)temp)[34] + src[2];
    dst[3] = ((u8 *)temp)[35] + src[3];
    dst[4] = ((u8 *)temp)[50] + src[4];
    dst[5] = ((u8 *)temp)[51] + src[5];
    dst[6] = ((u8 *)temp)[54] + src[6];
    dst[7] = ((u8 *)temp)[55] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[36] + src[0];
    dst[1] = ((u8 *)temp)[37] + src[1];
    dst[2] = ((u8 *)temp)[40] + src[2];
    dst[3] = ((u8 *)temp)[41] + src[3];
    dst[4] = ((u8 *)temp)[56] + src[4];
    dst[5] = ((u8 *)temp)[57] + src[5];
    dst[6] = ((u8 *)temp)[60] + src[6];
    dst[7] = ((u8 *)temp)[61] + src[7];
    dst += arg1;
    src += arg5;
    dst[0] = ((u8 *)temp)[38] + src[0];
    dst[1] = ((u8 *)temp)[39] + src[1];
    dst[2] = ((u8 *)temp)[42] + src[2];
    dst[3] = ((u8 *)temp)[43] + src[3];
    dst[4] = ((u8 *)temp)[58] + src[4];
    dst[5] = ((u8 *)temp)[59] + src[5];
    dst[6] = ((u8 *)temp)[62] + src[6];
    dst[7] = ((u8 *)temp)[63] + src[7];
}

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80127398(s32 arg0) {
    void *var_r31;
    void *var_r30;
    s32 var_r29;

    if (arg0 >= -1 && arg0 < 4) {
        var_r31 = (u8 *)lbl_8041D728 + arg0 * 0x14 + 0x14;
    } else {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        var_r30 = var_r31;
        for (var_r29 = 0; var_r29 < *(s32 *)var_r31; var_r29++) {
            ((void (*)(void))*(void **) ((u8 *)var_r30 + 4))();
            var_r30 = (void *)((u32)var_r30 + 4);
        }
    }
}
#pragma opt_propagation on
#pragma scheduling on
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
extern void fn_8011C4A0(s32, s32, s32, s32);
