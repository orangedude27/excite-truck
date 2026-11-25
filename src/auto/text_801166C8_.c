// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
typedef struct { f32 x, y; } V2_80121848;
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
typedef struct { s32 first, second; } Pair8011A168;
extern void TRKGetFreeBuffer(void *);
extern void fn_80117074(void*);
/* Pointer to the stream entry at byte offset `off` in the manager's entry table
 * (base+0x2F0, stride 0x17C). Each entry holds callbacks at +0/+4/+8, a circular
 * source buffer (+0x2C start, +0x30 end, +0x38 cursor), a byte counter (+0x40),
 * a 16->8-bit sample flag (+0x44) and thresholds (+0x48/+0x54/+0x58). */
#define STREAM_AT(m, off) ((u8 *)((off) + *(s32 *)((m) + 0x2F0)))
extern s32 lbl_8055DED4;
extern u32 fn_8011C1E0(s32, void *);
extern void *memcpy(void *, const void *, u32);

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
#include <ctype.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSContext.h>
#include <revolution/DVD/dvd.h>
#include "revolution/OS/OSCache.h"
void fn_8011C120();
extern s32 fn_80119300(void *, s32, s32);
void fn_8011C274(s32, void *);
void fn_8011C2EC(s32, void *);
void fn_801195D8();
#define M2C_FIELD(base, type, offset) (*(type)((u8 *)(base) + (offset)))

extern void* HomeMenu_drainHandover(void*);
extern void *fn_8011FFC4(s32);
extern f32 lbl_80329D48[];
extern const f64 lbl_805611D8;
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
extern void KERNEL_PlatExitProcess(s32);
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
/* The archive image ARCInitHandle sets a handle on: a header that points at
 * the node table (the "FST") and at the file data behind it.  A node is a
 * file's offset and size, or a folder's parent and next sibling; the top byte
 * of its first word says which and the low 24 bits are the offset of its name
 * in the string table that follows the last node. */
#define ARC_FILE_MAGIC 0x55AA382D  /* every archive image starts with this */

typedef struct ARCNode {
    union {
        struct {
            u32 is_folder : 8;
            u32 name : 24;
        };
        u32 packed_type_name;
    }; // at 0x0

    union {
        struct {
            u32 offset;
            u32 size;
        } file;

        struct {
            u32 parent;
            u32 sibling_next;
        } folder;
    }; // at 0x4
} ARCNode;

typedef struct ARCHeader {
    u32 magic; // at 0x0

    struct {
        s32 offset; // at 0x4
        s32 size;   // at 0x8
    } nodes;

    struct {
        s32 offset; // at 0xC
    } files;

    char UNK_0x10[0x10];
} ARCHeader;

/* Sets handle up for the archive image at bin: checks its magic, then records
 * where the image, its node table, its file data and its string table are, and
 * starts it at the root directory.  Only a bad magic can make it fail. */
BOOL ARCInitHandle(void *bin, ARCHandle *handle) {
    ARCHeader *header = (ARCHeader *)bin;
    u8 *base = (u8 *)bin;
    u32 entries;
    ARCNode *nodes;

    if (header->magic != ARC_FILE_MAGIC) {
        /* OS_ASSERT in arc.c, line 0x47: "ARCInitHandle: bad archive format" */
        OSPanic((const char *)&lbl_80559930, 0x47, lbl_80329B28);
    }
    handle->archiveStartAddr = header;
    nodes = (ARCNode *)(base + header->nodes.offset);
    handle->FSTStart = nodes;
    handle->fileStart = base + header->files.offset;
    /* The right bound of the root node is the number of nodes */
    entries = nodes[0].folder.sibling_next;
    handle->entryNum = entries;
    /* Strings exist directly after the last node. */
    handle->FSTStringStart = (char *)(nodes + entries);
    handle->FSTLength = header->nodes.size;
    handle->currDir = 0;
    return TRUE;
}

BOOL ARCFastOpen(ARCHandle *handle, s32 entrynum, ARCFileInfo *info) {
    /* Open an ARC file by FST entry number and fill its file info. */
    u32 *fstNodes = (u32 *)handle->FSTStart;
    s32 nodeOffset;

    if (entrynum < 0 || (u32)entrynum >= handle->entryNum || (fstNodes[entrynum * 3] & 0xFF000000) != 0) {
        return FALSE;
    }

    info->handle = handle;
    nodeOffset = (entrynum * 0xC) + (s32)fstNodes;
    info->startOffset = *(u32 *)(nodeOffset + 4);
    info->length = *(u32 *)(nodeOffset + 8);
    return TRUE;
}

extern u8 lbl_802FE850[];

/* ARC path comparison helper */
static inline BOOL isSame(const char *lhs, const char *rhs, u8 *locale) {
    while (rhs[0] != '\0') {
        int c = *rhs++;
        int lc = (c < 0 || c >= 256) ? c : (*(u8 **)(locale + 0x10))[c];
        int d = *lhs++;
        int rd = (d < 0 || d >= 256) ? d : (*(u8 **)(locale + 0x10))[d];
        if (rd != lc) return FALSE;
    }
    if (lhs[0] == '/' || lhs[0] == '\0') return TRUE;
    return FALSE;
}

/* Resolve an archive path to a file-system entry number: handle '/', '.' and '..' components relative to handle->currDir, then walk the FST sibling chain for each name using locale-aware comparison. Returns -1 if any component is not found. */ /* Resolve an archive path to a file-system entry number: handle '/', '.' and '..' components relative to handle->currDir, then walk the FST sibling chain for each name using locale-aware comparison. Returns -1 if any component is not found. */ s32 ARCConvertPathToEntrynum(ARCHandle *handle, const char *path) {
    u8 *locale = *(u8 **)(lbl_802FE850 + 0x38);
    const char *name_end;
    BOOL name_delimited_by_slash;
    s32 name_length;
    u32 dirEntry;
    u32 entrynum = handle->currDir;
    ARCNode *nodes = handle->FSTStart;

    while (TRUE) {
        if (path[0] == '\0') return entrynum;
        if (path[0] == '/') { entrynum = 0; ++path; continue; }
        if (path[0] == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    entrynum = nodes[entrynum].folder.parent;
                    path += 3;
                    continue;
                }
                if (path[2] == '\0') return nodes[entrynum].folder.parent;
                goto compare;
            }
            if (path[1] == '/') { path += 2; continue; }
            if (path[1] == '\0') return entrynum;
        }
    compare:
        name_end = path;
        while (name_end[0] != '\0' && name_end[0] != '/') ++name_end;
        name_delimited_by_slash = (name_end[0] != '\0') ? 1 : 0;
        name_length = name_end - path;
        dirEntry = entrynum;
        ++entrynum;
        while (entrynum < nodes[dirEntry].folder.sibling_next) {
            while (TRUE) {
                if ((nodes[entrynum].packed_type_name & 0xFF000000) ||
                    name_delimited_by_slash != TRUE) {
                    char *name_of_it = ((char *)handle->FSTStringStart) +
                        (nodes[entrynum].packed_type_name & 0x00FFFFFF);
                    if (name_of_it[0] == '.' && name_of_it[1] == '\0') {
                        ++entrynum;
                        continue;
                    }
                    if (isSame(path, name_of_it, locale) == TRUE) goto descend;
                }
                if (nodes[entrynum].packed_type_name & 0xFF000000) {
                    entrynum = nodes[entrynum].folder.sibling_next;
                    break;
                }
                ++entrynum;
                break;
            }
        }
        return -1;
    descend:
        if (!name_delimited_by_slash) return entrynum;
        path += name_length + 1;
    }
}

/* Returns the in-memory address of a file's data: the archive's base address plus the file's start offset. */
void* ARCGetStartAddrInMem(ARCFileInfo* info) {
    return (void*)((s32)info->handle->archiveStartAddr + info->startOffset);
}

/* Returns the byte length of the file described by the ARCFileInfo, from its header field at +8. */
s32 fn_80116A30(ARCFileInfo *info) {
    return info->length;
}

/* Always reports success (nonzero); callers ignore the return value. */
s32 fn_80116A38(void) {
    return 1;
}

/* Changes the handle's current directory to the given path if it resolves to a directory entry. */
BOOL ARCChangeDir(ARCHandle *handle, const char *path) {
    s32 entryNum = ARCConvertPathToEntrynum(handle, path);
    u32 *fst = (u32 *)handle->FSTStart;
    if (entryNum < 0 || !(fst[entryNum * 3] & 0xFF000000)) {
        return FALSE;
    }
    handle->currDir = entryNum;
    return TRUE;
}

/* Opens the directory `path` inside the archive `handle` was initialised for:
 * resolves the path to a node of the FST, refuses it unless that node is a
 * folder, and records in `dir` the run of nodes ARCReadDir will walk. */
BOOL ARCOpenDir(ARCHandle *handle, const char *path, ARCDir *dir) {
    register s32 entrynum = ARCConvertPathToEntrynum(handle, path);
    ARCNode *fst = (ARCNode *)handle->FSTStart;

    if (entrynum < 0 ||
        !(((ARCNode *)((u8 *)fst + entrynum * 0xC))->packed_type_name & 0xFF000000)) {
        return FALSE;
    }

    dir->handle = handle;
    dir->location = entrynum + 1;
    dir->entryNum = entrynum;
    dir->next = ((ARCNode *)((u8 *)fst + entrynum * (unsigned)0xC))->folder.sibling_next;
    return TRUE;
}

BOOL ARCReadDir(ARCDir *dir, ARCDirEntry *entry) {
    u32 it;
    ARCNode *nodes;
    ARCHandle *handle = dir->handle;
    u32 next;

    nodes = (ARCNode *)handle->FSTStart;
    it = dir->location;
    while (1) {
        /* Iterate entries in this directory's range, filling entry and
           advancing location past it (or to a folder's sibling). Returns FALSE
           when no more entries remain; "." entries are skipped. */
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
    /* Stub that always reports success (TRUE); checked after ARC directory iteration. */
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

/* Fill `count` 16-bit samples at `dst` with `value`: two samples are written per word
 * (the pattern replicated into both halves), and an odd last sample with a halfword store.
 * The band decoder calls it to repeat one decoded sample (fn_8011DC5C). */
void fn_80116CC4(s32 *dst, u16 value, u32 count) {
    u32 words;
    u32 fill;
    words = count >> 1;
    fill = (value << 16) | value;
    while (words != 0) {
        *dst = fill;
        dst++;
        words--;
    }
    if (count & 1) {
        *(u16 *)dst = value;
    }
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
    u64 quotient;
    u64 remainder;
    if (((s64)lbl_8055DEC0 * 0x100000000LL + (u32)lbl_8055DEC4) == 0) {
        lbl_8055DEC4 = (u32)time;
        lbl_8055DEC0 = (s32)(time >> 32);
    }
    saved_low = *(volatile u32 *)&lbl_8055DEC4;
    saved_high = *(volatile u32 *)&lbl_8055DEC0;
    delta = time - (((u64)saved_high << 32) | saved_low);
    quotient = (u32)(delta >> 32) * 70699U;
    remainder = delta - (quotient * 60750ULL);
    return (s32)(quotient + (u32)((remainder * 0x8A15866BULL) >> 47));
}

extern void* fn_8011FF24(void);
extern void *fn_8011FF2C(s32);
/* Add (size + current pending allocation base) to the state's pending-size field and commit a block of `size`. */
void fn_80116DDC(void* state, s32 size) {
    void* pendingBase = fn_8011FF24();
    s32* stateWords = (s32*)state;
    s32 pendingTotal = stateWords[0x290 / 4];
    s32 newPendingTotal = size + (s32)pendingBase + pendingTotal;
    stateWords[0x290 / 4] = newPendingTotal;
    fn_8011FF2C(size);
}

// Copies a null-terminated error message into the global last-error buffer.
void fn_80116E2C(const u8 *message) {
    const u8 *src = message;
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
#define sVideoInitCallback lbl_8055DEC8 /* active init callback */
#define sVideoInitResult lbl_8055DECC   /* last non-zero result from init callback */
#define sVideoInitLockCount lbl_8055DED0 /* blocks callback replacement when non-zero */
extern s32 (*lbl_8055DEC8)(s32);
extern s32 lbl_8055DECC;
extern s32 lbl_8055DED0;
/* Video/init callback registration: set/replace the active init callback and invoke it once. */
s32 fn_80116E54(s32 (*callback)(s32), s32 arg) {
    s32 (*current)(s32);
    s32 result;
    if (callback == 0)
        return 0;
    current = lbl_8055DEC8;
    if (current == 0) {
        current = callback;
        lbl_8055DEC8 = callback;
    }
    if ((u32)current != (u32)callback) {
        if (lbl_8055DED0 == 0) {
            lbl_8055DEC8 = callback;
        } else {
            return 0;
        }
    }
    result = lbl_8055DEC8(arg);
    if (result != 0)
        lbl_8055DECC = result;
    return lbl_8055DECC != 0;
}

/* Convert 16-bit PCM samples to 8-bit by keeping each sample's high byte.
 * `byteCount` is the source size in bytes (two per sample); returns the
 * advanced destination pointer. */
s8 *fn_80116EE4(s8 *out, s16 *in, u32 byteCount) {
    s32 i;
    u32 n = byteCount >> 1U;
    s16 *src = in;
    s8 *dst = out;
    for (i = n; i != 0; i--) {
        *dst = (s8)(*src >> 8);
        src++;
        dst++;
    }
    return dst;
}

#pragma push
#pragma use_lmw_stmw off
extern void memset(void *, int, unsigned int);
#pragma push
#pragma use_lmw_stmw off
u32 fn_80116F8C(void *arg0)
{
  s32 temp_r30;
  u32 temp_r29;
  s32 temp_r28;
  u32 temp_r0;
  u32 temp_r4;
  u32 temp_r6;
  u32 temp_r9;
  u32 *data = (u32 *) arg0;
  temp_r4 = data[0x4C / 4];
  temp_r0 = data[0x40 / 4];
  if (temp_r0 < temp_r4)
  {
    temp_r30 = temp_r4 - temp_r0;
    temp_r29 = (((u32) (temp_r30 * 0x3E8)) & 0xFFFF) / ((u32) ((data[0x78 / 4] * (data[0x70 / 4] * data[0x74 / 4])) >> 3));
    temp_r6 = data[0x38 / 4] - temp_r30;
    temp_r9 = data[0x2C / 4];
    data[0x38 / 4] = temp_r6;
    if (temp_r6 < temp_r9)
    {
      temp_r28 = temp_r9 - temp_r6;
      data[0x38 / 4] = temp_r6 + data[0x28 / 4];
      memset((void *) temp_r9, 0, temp_r30 - temp_r28);
      memset((void *) data[0x38 / 4], 0, temp_r28);
    }
    else
    {
      memset((void *) temp_r6, 0, temp_r30);
    }
    data[0x40 / 4] = data[0x40 / 4] + temp_r30;
    return temp_r29;
  }
  return 0;
}
#pragma pop
// Refills the output buffer of every active stream in the manager. Runs only
// when the stream table is initialized (last entry has a handler) and the
// manager lock (+0x340) can be acquired. For each stream it asks the stream
// (callback at +4) for a destination pointer and a transfer size, then copies
// that many bytes out of the stream's circular source buffer, wrapping at its
// end; when the stream's format flag (+0x44) is set the 16-bit source samples
// are narrowed to 8-bit with fn_80116EE4, otherwise they are copied verbatim.
void fn_80117074(void *mgr) {
    u8 *base = (u8 *)mgr;
    s32 entryOff;
    u32 i;
    s32 dstPtr;
    u32 size;
    if (*(s32 *)(*(u8 **)(base + 0x2F0) + (*(u32 *)(base + 0x2E8) - 1) * 0x17C) != 0 &&
        fn_8011C1E0(lbl_8055DED4, base + 0x340) != 0) {
        for (i = 0, entryOff = 0; i < *(u32 *)(base + 0x2E8); entryOff += 0x17C, i++) {
            while (((s32 (*)(void *))*(u32 *)(*(u8 **)(base + 0x2F0) + entryOff))(*(u8 **)(base + 0x2F0) + entryOff) != 0 &&
                   (*(u32 *)(STREAM_AT(base, entryOff) + 0x40) > *(u32 *)(STREAM_AT(base, entryOff) + 0x54) ||
                    (*(s32 *)(base + 0xC) > *(s32 *)(STREAM_AT(base, entryOff) + 0x48) && *(s32 *)(STREAM_AT(base, entryOff) + 0x40) != 0))) {
                u32 rem;
                if (((s32 (*)(void *, s32 *, u32 *))*(u32 *)(STREAM_AT(base, entryOff) + 4))(STREAM_AT(base, entryOff), &dstPtr, &size) == 0)
                    break;
                if (*(s32 *)(STREAM_AT(base, entryOff) + 0x44) != 0)
                    size *= 2;
                if (size > *(u32 *)(STREAM_AT(base, entryOff) + 0x40))
                    size = *(u32 *)(STREAM_AT(base, entryOff) + 0x40);
                if (*(s32 *)(base + 0xC) <= *(s32 *)(STREAM_AT(base, entryOff) + 0x48))
                    size &= *(s32 *)(STREAM_AT(base, entryOff) + 0x58) << *(s32 *)(STREAM_AT(base, entryOff) + 0x44);
                *(u32 *)(STREAM_AT(base, entryOff) + 0x40) -= size;
                rem = *(u32 *)(STREAM_AT(base, entryOff) + 0x30) - *(u32 *)(STREAM_AT(base, entryOff) + 0x38);
                if (rem < size) {
                    if (rem != 0) {
                        if (*(s32 *)(STREAM_AT(base, entryOff) + 0x44) != 0) {
                            dstPtr = (s32)fn_80116EE4((s8 *)dstPtr, *(s16 **)(STREAM_AT(base, entryOff) + 0x38), rem);
                        } else {
                            memcpy((void *)dstPtr, *(void **)(STREAM_AT(base, entryOff) + 0x38), rem);
                            dstPtr += rem;
                        }
                    }
                    if (*(s32 *)(STREAM_AT(base, entryOff) + 0x44) != 0)
                        fn_80116EE4((s8 *)dstPtr, *(s16 **)(STREAM_AT(base, entryOff) + 0x2C), size - rem);
                    else
                        memcpy((void *)dstPtr, *(void **)(STREAM_AT(base, entryOff) + 0x2C), size - rem);
                    *(u32 *)(STREAM_AT(base, entryOff) + 0x38) = *(u32 *)(STREAM_AT(base, entryOff) + 0x2C) + (size - rem);
                } else {
                    if (*(s32 *)(STREAM_AT(base, entryOff) + 0x44) != 0)
                        fn_80116EE4((s8 *)dstPtr, *(s16 **)(STREAM_AT(base, entryOff) + 0x38), size);
                    else
                        memcpy((void *)dstPtr, *(void **)(STREAM_AT(base, entryOff) + 0x38), size);
                    *(u32 *)(STREAM_AT(base, entryOff) + 0x38) += size;
                }
                if (*(s32 *)(STREAM_AT(base, entryOff) + 0x44) != 0)
                    size >>= 1;
                ((void (*)(void *, u32))*(u32 *)(STREAM_AT(base, entryOff) + 8))(*(u8 **)(base + 0x2F0) + entryOff, size);
            }
        }
        fn_8011C2EC(lbl_8055DED4, base + 0x340);
    }
}

#pragma pop
extern s32 fn_80116D30(void);
/* Initialize decode timing for the current block if it has not been started yet. */
void fn_80117330(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x268) == 0) {
        s32 startTick = fn_80116D30();
        s32 blockCount = *(s32 *)((u8 *)arg0 + 0x258);
        *(s32 *)((u8 *)arg0 + 0x268) = startTick;
        *(s32 *)((u8 *)arg0 + 0x26C) = blockCount - 1;
        *(s32 *)((u8 *)arg0 + 0x330) = 0;
    }
}

void fn_80117380(void *arg0, s32 arg1) {
    s32 index;
    s32 now;
    s32 *entryOffsets;
    s32 baseOffset;
    u32 startOffsetField;
    u32 endOffsetField;
    s32 startOffset;
    s32 endOffset;
    s32 (*seekCallback)(void *, s32, s32, s32, s32);

    /* Seek to the requested block: update the current offset, refresh stream state, and run timeout checks. */
    index = arg1;
    if (arg1 != 0) index = arg1 - 1;

    *(s32 *)((u8 *)arg0 + 0x2F8) = 0;
    if (*(s32 *)((u8 *)arg0 + 0x2E8) != 0) fn_80117074(arg0);

    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 0xC);

    if (index == 0) {
        now = fn_80116D30();
        if (*(s32 *)((u8 *)arg0 + 0x2D8) == 0) *(s32 *)((u8 *)arg0 + 0x2D8) = now;
        if ((u32)(now - *(u32 *)((u8 *)arg0 + 0x2D8)) > 0x493E0U) {
            *(s32 *)((u8 *)arg0 + 0x2D8) = now;
            *(s32 *)((u8 *)arg0 + 0x2DC) = 1;
        }
    }

    baseOffset = *(s32 *)((u8 *)arg0 + 0xE8);
    if (baseOffset != 0) {
        entryOffsets = *(s32 **)((u8 *)arg0 + 0xEC);
        *(s32 *)((u8 *)arg0 + 0xE4) = baseOffset + ((entryOffsets[index] & ~1) - (entryOffsets[0] & ~1));
    } else {
        entryOffsets = *(s32 **)((u8 *)arg0 + 0xEC);
        startOffsetField = index << 2;
        endOffsetField = (index + 1) << 2;
        startOffset = *(s32 *)((u8 *)entryOffsets + startOffsetField) & ~1;
        endOffset = *(s32 *)((u8 *)entryOffsets + endOffsetField) & ~1;
        seekCallback = *(s32 (**)(void *, s32, s32, s32, s32))((u8 *)arg0 + 0xF4);
        seekCallback((u8 *)arg0 + 0xF0, index, startOffset, *(s32 *)((u8 *)arg0 + 0xE4), endOffset - startOffset);
    }

    if (*(s32 *)((u8 *)arg0 + 0x2E8) != 0) fn_80117074(arg0);
    *(s32 *)((u8 *)arg0 + 0xC) = index + 1;
}

u32 fn_80116BD4(s32, s32, s32);
/* Pick the block size out of a table of stream positions.  The table holds
 * count + 1 values; every value is compared with the one `offset` places after
 * it, and the largest difference - together with where it starts - is the
 * answer: an evenly spaced table has no such difference, and then the average
 * spacing, (values[count] - values[0]) * offset / count, is returned instead.
 * *outFlag reports whether every one of the count values is odd, which is how
 * the caller tells a table of packed entries from one of plain positions. */
u32 fn_801174B0(s32 count, u32 *values, s32 offset, s32 *outIndex, s32 *outFlag) {
    u32 *from;          /* values[i] */
    u32 *to;            /* values[offset + i] */
    s32 remaining;
    s32 byteOffset;
    s32 i;
    u32 diff;
    u32 maxDiff;
    s32 index;
    s32 allOdd;

    maxDiff = 0;
    index = 0;
    allOdd = 1;
    from = values;
    to = values + offset;
    remaining = count - offset;
    byteOffset = 0;
    /* The largest jump between two values `offset` apart. */
    for (i = 0; i < remaining; i++) {
        diff = to[byteOffset / 4] - *from;
        if (diff > maxDiff) {
            maxDiff = diff;
            index = i;
        }
        from++;
        byteOffset += 4;
    }
    if (maxDiff == 0) {
        /* Nothing stands out: the average distance between two values. */
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

#pragma opt_propagation off
/* Check callback for the audio stream manager (paired with fn_801175C4): recover the
 * manager base from the node pointer (mgr = node - 0x340), read the last tick stored at
 * mgr+0x33C, and return ~lastTick when it differs from the current tick, else 0. The
 * offset/base temporaries keep the compiler's addi/subf/subf base-recovery idiom. */
s32 fn_80117598(s32 node, s32 tickCount) {
    register s32 offset;
    register s32 mgr;
    s32 lastTick;
    s32 inverted;
    s32 diffMask;
    s32 difference;
    offset = node + 0x340;
    offset -= node;
    mgr = node - offset;
    lastTick = *(s32*)(mgr + 0x33C);
    difference = (lastTick - tickCount) | (tickCount - lastTick);
    diffMask = difference >> 31;
    inverted = -1 - lastTick;
    return inverted & diffMask;
}
#pragma opt_propagation reset
/* Tick-list "finish" callback for the audio stream manager, registered by
 * fn_8011BEC8 at the manager's node (mgr+0x340) alongside the check callback
 * fn_80117598. The periodic tick driver (fn_8011BD20) calls it once per alarm
 * with the running tick count. Recovers the manager base from the node pointer
 * (mgr = node - 0x340), refills the active output streams via fn_80117074 when
 * any are open (mgr+0x2E8 entry count), then records the tick count at mgr+0x33C.
 * The offset/mgr temporaries reproduce the compiler's addi/subf/subf idiom for
 * the base recovery; folding them into one subtraction would not match. */
void fn_801175C4(s32 node, s32 tickCount) {
    register s32 offset;
    register s32 mgr;
    offset = node + 0x340;
    offset -= node;
    mgr = node - offset;
    if (*(s32 *)(mgr + 0x2E8) != 0) {
        fn_80117074((void *)mgr);
    }
    *(s32 *)(mgr + 0x33C) = tickCount;
}

/* Compute render/texture buffer layout parameters (sizes, strides, and flags) from
 * a video/source object into the output descriptor. Stores base mode 1 if the
 * source has a non-zero flag at +0x380, otherwise fills the extended layout and
 * sets mode 2. */
void fn_80117618(void *arg0, void *arg1) {
    volatile s32 *layout = (volatile s32 *)arg1;
    s32 temp_r5;
    u32 halfDim;

    layout[5] = 0;
    layout[1] = (*(s32 *)((u8 *)arg0 + 0x23C) + 7) & ~7;
    layout[2] = (*(s32 *)((u8 *)arg0 + 0x240) + 7) & ~7;
    halfDim = (u32)(*(s32 *)((u8 *)arg0 + 0x23C) + 1);
    layout[3] = ((halfDim >> 1) + 7) & ~7;
    halfDim = (u32)(*(s32 *)((u8 *)arg0 + 0x240) + 1);
    layout[6] = 1;
    temp_r5 = ((halfDim >> 1) + 7) & ~7;
    layout[9] = 1;
    layout[4] = temp_r5;
    layout[12] = 1;
    temp_r5 = (*(u32 *)((u8 *)arg0 + 0x20) >> 20) & 1;
    layout[7] = 0;
    layout[15] = temp_r5;
    layout[10] = 0;
    layout[13] = 0;
    layout[16] = 0;
    layout[8] = 0;
    layout[11] = 0;
    layout[14] = 0;
    layout[17] = 0;
    if (*(s32 *)((u8 *)arg0 + 0x380) != 0) { layout[0] = 1; return; }
    layout[18] = 1; layout[0] = 2;
    layout[19] = 0; layout[20] = 0; layout[21] = 1; layout[22] = 0;
    layout[23] = 0; layout[24] = 1; layout[25] = 0; layout[26] = 0;
    layout[27] = temp_r5; layout[28] = 0; layout[29] = 0;
}

/* Record the address of the video's layout descriptor in the Bink handle, if it is open. */
void fn_801176FC(void* bink, s32 layout){if(bink)*(s32*)((u8*)bink+0xb8)=layout;}

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

extern signed long fn_801190B0(void*, signed long);
extern signed long fn_80116D30(void);
extern unsigned long fn_80116BD4(signed long, signed long, signed long);
extern void fn_80117330(void*);
extern void fn_8011B94C(void*, signed long*, signed long*, signed long, signed long*, signed long, unsigned long*, unsigned long, float, signed long);
extern unsigned long fn_8011FC2C(void*, signed long, signed long, signed long*, signed long, signed long, signed long, signed long);
extern void fn_8011C274(signed long, void*);
extern void fn_8011C2EC(signed long, void*);
extern signed long OSDisableInterrupts(void);
extern void OSRestoreInterrupts(signed long);
extern void* memcpy(void*, const void*, unsigned long);
extern void memset(void*, int, unsigned int);
extern signed long lbl_8055DED4;
#pragma use_lmw_stmw on
signed long fn_801186B8(void* arg0) {
    signed long streamOff;
    signed long n;
    unsigned char* list;
    signed long needClose;
    signed long first;
    signed long amount;
    unsigned char* m;
    signed long tmp;
    signed long tmp2;
    signed long curTick;
    m = (unsigned char*)arg0;
    needClose = 0;
    if (m == 0) return 0;
    if (*(unsigned long*)(m + 0x2D4) == *(unsigned long*)(m + 0xC)) return 0;
    if (*(signed long*)(m + 0x2DC) != 0) {
        *(signed long*)(m + 0x2DC) = 0;
        if (*(signed long*)(m + 0x288) != 0) {
            fn_801190B0(m, 0);
            fn_801190B0(m, 1);
        }
        *(signed long*)(m + 0x268) = 0;
        *(signed long*)(m + 0x330) = 0;
        *(signed long*)(m + 0x328) = 0;
    }
    if (*(signed long*)(m + 0xDC) != 0) {
        *(signed long*)(m + 0x268) = 0;
        *(signed long*)(m + 0x330) = 0;
        *(signed long*)(m + 0x328) = 0;
    }
    *(signed long*)(m + 0x2F8) = 0;
    *(signed long*)(m + 0x11C) = 1;
    {
        curTick = fn_80116D30();
        n = *(signed long*)(m + 0x2B0);
        *(signed long*)(m + 0x260) = curTick;
        tmp = n - 1;
        *(signed long*)(m + 0x2B0) = tmp;
        if (tmp < 0) *(signed long*)(m + 0x2B0) = *(signed long*)(m + 0x2AC) - 1;
        *(signed long*)(*(signed long*)(m + 0x2B4) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x260);
        *(signed long*)(*(signed long*)(m + 0x2BC) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x294);
        *(signed long*)(*(signed long*)(m + 0x2B8) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x298);
        *(signed long*)(*(signed long*)(m + 0x2C0) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x29C);
        *(signed long*)(*(signed long*)(m + 0x2C4) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x124);
        *(signed long*)(*(signed long*)(m + 0x2C8) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x128);
        *(signed long*)(*(signed long*)(m + 0x2CC) + *(signed long*)(m + 0x2B0) * 4) = *(signed long*)(m + 0x12C);
        if (*(signed long*)(m + 0x25C) == 0) {
            signed long d = fn_80116BD4(0x3E8, *(signed long*)(m + 0x2A8), *(signed long*)(m + 0x2A4));
            *(signed long*)(*(signed long*)(m + 0x2B4) + n * 4) = *(signed long*)(m + 0x260) - d;
            *(signed long*)(m + 0x12C) = 0;
            *(signed long*)(m + 0x25C) = *(signed long*)(m + 0x260);
            *(signed long*)(m + 0x128) = 0;
        } else if (*(signed long*)(m + 0x2E8) != 0) {
            fn_80117074(m);
        }
        *(signed long*)(m + 0x274) = *(signed long*)(m + 0x260);
        if (*(signed long*)(m + 0x110) != 0) *(signed long*)(m + 0x1C) = 1;
        if (*(signed long*)(m + 0x1C) != 0) return 1;
        {
            list = *(unsigned char**)(m + 0xE4);
            for (n = 0; n < *(signed long*)(m + 0xD0); n++) {
                signed long found = -1;
                signed long j;
                signed long c = *(signed long*)(m + 0x2E8);
                signed long w = 0;
                unsigned char* p = list + 4;
                first = *(signed long*)list;
                for (j = 0; j < c; j++) {
                    signed long vv = *(signed long*)(*(signed long*)(m + 0x244) + w);
                    if (vv == n) break;
                    w += 4;
                }
                if (j < c) found = j;
                else found = -1;
                if (found != -1 && first != 0) {
                    void* dst = p + 4;
                    streamOff = found * 0x17C;
                    amount = *(signed long*)p;
                    if (needClose == 0) { needClose = 1; fn_8011C274(lbl_8055DED4, m + 0x340); }
                    while (amount != 0) {
                        signed long spC;
                        signed long sp8;
                        signed long irq;
                        signed long space = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x28) - *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40);
                        signed long size;
                        signed long over;
                        signed long rem;
                        ((void (*)(void*, signed long*, signed long*, signed long, signed long*, signed long))fn_8011B94C)((void*)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x3C), &spC, &sp8, (signed long)dst, (signed long*)&dst, *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40));
                        size = sp8;
                        if ((unsigned long)size > (unsigned long)amount) { size = amount; sp8 = amount; }
                        amount -= size;
                        if ((unsigned long)size > (unsigned long)space) {
                            over = size - space;
                            *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x38) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x38) + over;
                            irq = OSDisableInterrupts();
                            *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40) - over;
                            OSRestoreInterrupts(irq);
                            if ((unsigned long)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x38) >= (unsigned long)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x30))
                                *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x38) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x38) - *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x28);
                        }
                        irq = OSDisableInterrupts();
                        *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x40) + sp8;
                        OSRestoreInterrupts(irq);
                        rem = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x30) - *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34);
                        if ((unsigned long)rem < (unsigned long)sp8) {
                            if (rem != 0) {
                                memcpy((void*)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34), (void*)spC, rem);
                                sp8 -= rem;
                                spC += rem;
                            }
                            memcpy((void*)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x2C), (void*)spC, sp8);
                            *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x2C) + sp8;
                        } else {
                            memcpy((void*)*(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34), (void*)spC, sp8);
                            *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34) = *(signed long*)(*(signed long*)(m + 0x2F0) + streamOff + 0x34) + sp8;
                        }
                    }
                }
                list = list + 4 + first;
            }
            if (needClose != 0) fn_8011C2EC(lbl_8055DED4, m + 0x340);
        }
        {
            signed long t;
            t = fn_80116D30();
            if (*(signed long*)(m + 0x28C) != 0 && *(signed long*)(m + 0xB8) != 0) {
                if (*(signed long*)(m + 0x2F4) == 0) memset((void*)(*(signed long*)(m + 0xBC)), 0, *(unsigned long*)(m + 0xC4));
                if (*(signed long*)(m + 0xE8) == 0 && *(signed long*)(m + 0x114) == 0) {
                    unsigned long a = *(unsigned long*)(m + 0xD4);
                    unsigned long use = (a < *(unsigned long*)(m + 0x138)) ? a : *(unsigned long*)(m + 0x138);
                    if (*(unsigned long*)(m + 0x13C) < (unsigned long)(((use * 4) - use) >> 2)) {
                        ((void (*)(void*))*(void**)(m + 0x100))(m + 0xF0);
                    }
                }
                *(signed long*)(m + 0x2E0) = fn_8011FC2C((void*)(*(signed long*)(m + 0xB8)), *(signed long*)(m + 0xBC), *(signed long*)(m + 0xC0), (signed long*)list, *(signed long*)(*(signed long*)(m + 0xEC) + (*(signed long*)(m + 0xC) - 1) * 4) & 1, (signed long)(m + 0x300), *(signed long*)(m + 0x20), *(signed long*)(m + 0x24));
            }
            if (*(signed long*)(m + 0x2E8) != 0) fn_80117074(m);
            tmp2 = *(signed long*)(m + 0x258);
            *(signed long*)(m + 0xB4) = -1;
            *(signed long*)(m + 0x258) = tmp2 + 1;
            fn_80117330(m);
            {
                signed long t2;
                signed long c;
                t2 = fn_80116D30();
                c = *(signed long*)(m + 0xC);
                *(signed long*)(m + 0x264) = t2;
                *(signed long*)(m + 0x298) = *(signed long*)(m + 0x298) + (t - *(signed long*)(m + 0x260));
                *(signed long*)(m + 0x294) = *(signed long*)(m + 0x294) + (t2 - t);
                *(signed long*)(m + 0x2D4) = c;
                *(signed long*)(m + 0x10) = c;
                *(signed long*)(m + 0x11C) = 0;
            }
        }
    }
    return 0;
}
#pragma use_lmw_stmw on
#undef lbl_8041D608

/* Accumulate an elapsed-time interval for an object: when a start tick at +0x264
 * is set, add (endTick - startTick) to the running total at +0x29c and clear the start. */
void fn_80118C1C(void *object, s32 endTick) {
    s32 startTick = *(s32 *)((u8 *)object + 0x264);
    if (startTick != 0) {
        s32 accumulated = *(s32 *)((u8 *)object + 0x29c);
        *(s32 *)((u8 *)object + 0x29c) = accumulated + (endTick - startTick);
        *(s32 *)((u8 *)object + 0x264) = 0;
    }
}

extern s32 fn_801190B0(void*, s32);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
/* Advance a Bink movie by one frame, on the player's 20 ms tick.
 *
 * Each sound stream that asked to be flushed (stream +0x5C) is cleared, and one
 * whose start frame (stream +0x48) the movie has already passed forces a
 * resync: the movie's streams are paused, the decoder is pumped through the
 * file interface's fill hook until its buffered frames (bink +0x13C) reach
 * 29/32ths of a full buffer (bink +0x138), the decode timing is cleared and the
 * streams are unpaused again - all with the shared Bink tick locked so the
 * tick's own callback cannot run.  The sound buffers are then refilled, this
 * frame's decode time is folded into the running total and the movie is sent to
 * its next frame, wrapping back to the first at the end.  bink +0x11C is the
 * guard that keeps the tick callback out while this runs. */
void fn_80118C44(void* bink) {
    s32 value;
    s32 var_r4;
    s32 entryOff;
    u32 bufferedFrames;
    u32 frameOrTarget;
    s32 resync;
    u32 index;
    void* stream;
    volatile s32 *inCallback;
    volatile u32 *streamCount;

    inCallback = (volatile s32 *)((u8*)bink + 0x11C);
    streamCount = (volatile u32 *)((u8*)bink + 0x2E8);
    resync = 0;
    if (bink != 0) {
        *inCallback = 1;
        value = 0;
        *(s32*)((u8*)bink + 0x2F8) = value;
        *inCallback = value;
        index = 0;
        entryOff = 0;
        while (index < *streamCount) {
            stream = (u8*)*(void**)((u8*)bink + 0x2F0) + entryOff;
            if (*(s32*)((u8*)stream + 0x5C) != 0) {   /* the stream wants a flush */
                *(s32*)((u8*)stream + 0x5C) = 0;
                frameOrTarget = *(u32*)((u8*)bink + 0x0C);   /* the movie's frame */
                if (frameOrTarget > 1) {
                    stream = (u8*)*(void**)((u8*)bink + 0x2F0) + entryOff;
                    if ((s32)frameOrTarget <= *(s32*)((u8*)stream + 0x48))
                        resync = 1;                      /* it starts at/after us */
                }
            }
            entryOff += 0x17C;
            index += 1;
        }
        if (resync != 0) {
            value = *(s32*)((u8*)bink + 0x2EC);
            *(s32*)((u8*)bink + 0x2EC) = value + 1;    /* resyncs done so far */
            fn_8011C274(lbl_8055DED4, (u8*)bink + 0x340);   /* lock the Bink tick */
            fn_801190B0(bink, 0);                          /* pause its streams */
            for (;;) {
                frameOrTarget = *(u32*)((u8*)bink + 0x138);
                bufferedFrames = *(u32*)((u8*)bink + 0x13C);
                frameOrTarget = (frameOrTarget * 0x1D) >> 5; /* 29/32ths of a buffer */
                if (bufferedFrames < frameOrTarget) {
                    /* not enough decoded yet: ask the file interface for more */
                    bufferedFrames = ((s32 (*)(void*))(*(void**)((u8*)bink + 0x100)))((u8*)bink + 0xF0);
                    if (bufferedFrames != 0) continue;
                }
                *(s32*)((u8*)bink + 0x268) = 0;        /* decode timing, restarts */
                *(s32*)((u8*)bink + 0x328) = 0;
                *(s32*)((u8*)bink + 0x330) = 0;
                fn_801190B0(bink, 1);                      /* streams running again */
                fn_8011C2EC(lbl_8055DED4, (u8*)bink + 0x340);
                break;
            }
        }
        *inCallback = 1;
        if (*(s32*)((u8*)bink + 0x2E8) != 0)
            fn_80117074(bink);              /* refill every stream's output buffer */
        fn_80118C1C(bink, fn_80116D30());   /* fold this frame's time into the total */
        bufferedFrames = *(u32*)((u8*)bink + 0x0C);
        fn_80117380(bink, (bufferedFrames < *(u32*)((u8*)bink + 0x08)) ? (s32)(bufferedFrames + 1) : 1);
        *inCallback = 0;
    }
}
#pragma pop
/* --- RAD Bink movie player (this unit is the Bink library itself) -------- */

/* The file interface a movie reads through; fn_8011770C (BinkOpen) installs
 * the hooks and every slot is then called through a cast. */
typedef struct BinkFile {
    /* +0x00 */ void *hooks[5];
} BinkFile;

/* A listener on the shared Bink tick: fn_8011BEC8 links it into the tick's
 * list at tick+0x30, fn_8011BF4C unlinks it. */
typedef struct BinkTickNode {
    /* +0x00 */ struct BinkTickNode *next;
    /* +0x04 */ u8 pad04[0x8];
    /* +0x0C */ s32 registered;
    /* +0x10 */ s32 unknown_10;
    /* +0x14 */ s32 (*Check)(s32 node, s32 time);
    /* +0x18 */ void (*Tick)(s32 node, s32 time);
} BinkTickNode;

/* One frame of a movie in Bink.frames[]; 0x17C bytes each. */
typedef struct BinkFrame {
    /* +0x00 */ u8 pad00[0x14];
    /* +0x14 */ void (*SetPaused)(struct BinkFrame *frame, s32 paused);
    /* +0x18 */ u8 pad18[0x4];
    /* +0x1C */ void (*Close)(struct BinkFrame *frame);
    /* +0x20 */ u8 pad20[0x8];
    /* +0x28 */ s32 dataSize;
    /* +0x2C */ void *data;
    /* +0x30 */ u8 pad30[0xC];
    /* +0x3C */ void *texture;
} BinkFrame;

/* The movie object fn_8011770C (BinkOpen) returns; 0x388 bytes. */
typedef struct Bink {
    /* +0x00 */ u8 pad00[0x20];
    /* +0x20 */ u32 flags;
    /* +0x24 */ u8 pad24[0xC4];
    /* +0xE8 */ void *fileBuffer;
    /* +0xEC */ u8 padEC[0x4];
    /* +0xF0 */ BinkFile file;
    /* +0x104 */ s32 (*fileClose)(void *file);
    /* +0x108 */ u8 pad108[0xEC];
    /* +0x1F4 */ BinkTickNode localNode;
    /* +0x210 */ u8 pad210[0x24];
    /* +0x234 */ void *fileData;
    /* +0x238 */ u8 pad238[0xB0];
    /* +0x2E8 */ u32 frameCount;
    /* +0x2EC */ u8 pad2EC[0x4];
    /* +0x2F0 */ BinkFrame *frames;
    /* +0x2F4 */ u8 pad2F4[0x4C];
    /* +0x340 */ BinkTickNode tickNode;
    /* +0x35C */ u8 pad35C[0x28];
    /* +0x384 */ void *textureLayout;
} Bink;

extern s32 fn_80118F78(void*, s32);
extern s32 fn_8011BFFC(s32, s32, s32, s32, s32);
extern void fn_8011BC48();
void fn_80118DC0(Bink *bink) {
    s32 offset;
    s32 i;
    s32 tick;
    s32 status;
    register s32 zero = 0;
    s32 localNode;

    /* BinkClose: shut a movie down. */
    if (bink == 0) return;
    fn_80118F78(bink, 1); /* BinkChangePause(bink, TRUE) */
    localNode = (s32)&bink->localNode;
    if (bink->frameCount != zero)
        tick = *(s32*)&lbl_8055DED4; /* the shared Bink tick object */
    else
        tick = 0;
    /* Unlink both tick nodes; bit 1 is set when the shared tick, having no
     * listener left, cancelled its alarm and freed itself. */
    status = fn_8011BFFC(zero, localNode, tick, (s32)&bink->tickNode, 1);
    switch (status) {
    case 2:
        goto status2;
    case 3:
        goto status3;
    default:
        break;
    }
    goto status_done;
status2:
    lbl_8055DED4 = 0;
    goto status_done;
status3:
    lbl_8055DED4 = 0;
status_done:
    i = 0;
    offset = 0;
    while ((u32)i < bink->frameCount) {
        BinkFrame *frame = (BinkFrame *)((u8 *)bink->frames + offset);
        frame->Close(frame);
        /* the calls above may move the frame list: walk it from the top again */
        fn_8011BC48(((BinkFrame *)((u8 *)bink->frames + offset))->texture);
        {
            void *data = ((BinkFrame *)((u8 *)bink->frames + offset))->data;
            if (data != 0) fn_80120084(data);
        }
        offset += 0x17C;
        i += 1;
    }
    {
        void *fileBuffer = bink->fileBuffer;
        if (fileBuffer != 0) {
            if ((bink->flags & 0x04000000) == 0) /* not opened from memory */
                fn_80120084(fileBuffer);
        } else {
            bink->fileClose(&bink->file);
            fn_80120084(bink->fileData);
        }
    }
    {
        void *textureLayout = bink->textureLayout;
        if (textureLayout != 0) fn_80120084(textureLayout);
    }
    memset(bink, zero, sizeof(Bink));
    fn_80120084(bink);
}

/* Updates recorded interval durations for an object: when a start tick at +0x274 is set, computes (endTick - startTick), clears the start, and promotes it into the longest (+0x278/+0x27C tag from +0xC) or second-longest (+0x280/+0x284) slot as needed. */
void fn_80118F1C(void *object, s32 endTick) {
    s32 startTick = *(s32*)((u8*)object + 0x274);
    if (startTick != 0) {
        u32 longestDuration = *(u32*)((u8*)object + 0x278);
        u32 duration = endTick - startTick;
        *(s32*)((u8*)object + 0x274) = 0;
        if (duration > longestDuration) {
            *(u32*)((u8*)object + 0x280) = longestDuration;
            *(s32*)((u8*)object + 0x284) = *(s32*)((u8*)object + 0x27C);
            *(u32*)((u8*)object + 0x278) = duration;
            *(s32*)((u8*)object + 0x27C) = *(s32*)((u8*)object + 0xC);
        } else if (duration > *(u32*)((u8*)object + 0x280)) {
            *(u32*)((u8*)object + 0x280) = duration;
            *(s32*)((u8*)object + 0x284) = *(s32*)((u8*)object + 0xC);
        }
    }
}

s32 fn_80118F78(void *bink, s32 paused) {
    /* BinkChangePause: set a movie's paused state, recording elapsed play time
       on pause/resume and forwarding the flag to every frame's SetPaused. */
    struct S {
        char pad0[0xDC];
        s32 paused;
        char pad1[0x268 - 0xE0];
        s32 timeBase;
        char pad2[0x2E8 - 0x26C];
        s32 frameCount;
        char pad3[0x2F0 - 0x2EC];
        void *frames;
        char pad4[0x330 - 0x2F4];
        s32 savedElapsed;
        char pad5[0x340 - 0x334];
        char tickNode[1];
    } *s = (struct S *)bink;
    s32 tick;
    s32 now;
    s32 frameOff;
    u32 frameIndex;
    s32 resuming;

    resuming = 0;
    if (bink == 0) {
        return 0;
    }

    now = fn_80116D30();
    fn_80118C1C(bink, now);
    fn_80118F1C(bink, now);

    if (paused == 0) {
        if (s->paused != 0) {
            resuming = 1;
        }
    } else if (s->paused == 0) {
        tick = s->timeBase;
        if (tick != 0) {
            s->savedElapsed = now - tick;
        } else {
            s->savedElapsed = 0;
        }
    }

    s->paused = paused;
    fn_8011C274(lbl_8055DED4, s->tickNode);

    frameIndex = 0;
    frameOff = 0;
    while (frameIndex < (u32)s->frameCount) {
        void *frame = (u8 *)s->frames + frameOff;
        (*(void (**)(void *, s32))((u8 *)frame + 0x14))(frame, paused);
        frameOff += 0x17C;
        frameIndex++;
    }

    fn_8011C2EC(lbl_8055DED4, s->tickNode);
    if (*(s32 *)((u8 *)bink + 0x258) != 0 &&
        s->frameCount != 0) {
        fn_80117074(bink);
    }

    if (resuming != 0) {
        tick = fn_80116D30();
        s->timeBase = tick - s->savedElapsed;
    }

    return s->paused;
}

#pragma push
#pragma opt_loop_invariants off
/* Start (start != 0) or stop every StreamPlayer of a movie and report whether
 * any of them ended up playing.  Each player's setPlay callback (+0x18 of the
 * 0x17C-byte entry in the movie's player table, fn_80119C0C) takes the flag
 * and returns the player's new `playing` state.  The movie keeps a "a stream
 * is playing" flag: when a stream stops while that flag is up its source ring
 * is rewound to its start (cursor +0x34 and read cursor +0x38 back to +0x2C,
 * free-byte counter +0x40 cleared) and drained by fn_80116F8C -- skipped on
 * the movie's first frame when the last tick did not end there -- and when one
 * starts while the flag is down the movie's timing is restarted (timeBase,
 * +0x328 and savedElapsed).  The pass runs under the shared Bink tick lock,
 * taken on the first player that has a callback and released at the end. */
s32 fn_801190B0(void *mgr, s32 start) {
    /* The movie object's fields this touches (see Bink). */
    #define MOVIE_FRAME        (*(u32 *)((u8 *)mgr + 0x0C))  /* frame being shown */
    #define MOVIE_TIME_BASE    (*(s32 *)((u8 *)mgr + 0x268)) /* tick play started on */
    #define MOVIE_STREAMS_ON   (*(s32 *)((u8 *)mgr + 0x288)) /* a stream is playing */
    #define MOVIE_TICK_FRAME   (*(u32 *)((u8 *)mgr + 0x2D4)) /* frame at the last tick */
    #define MOVIE_PLAYER_COUNT (*(u32 *)((u8 *)mgr + 0x2E8))
    #define MOVIE_PLAYERS      (*(u8 **)((u8 *)mgr + 0x2F0)) /* 0x17C-byte StreamPlayers */
    #define MOVIE_TIMING_328   (*(s32 *)((u8 *)mgr + 0x328))
    #define MOVIE_SAVED_MS     (*(s32 *)((u8 *)mgr + 0x330)) /* elapsed before a pause */
    #define PLAYER_AT(i)       (MOVIE_PLAYERS + (i))         /* player at byte i */
    #define PLAYER_SETPLAY(i)  (*(s32 *)(PLAYER_AT(i) + 0x18)) /* fn_80119C0C */

    s32 entryOff;
    s32 anyPlaying;
    s32 locked;
    u32 frame;
    s32 playing;
    u32 index;
    s32 zero;
    s32 one;

    anyPlaying = 0;
    if (mgr != 0) {
        locked = 0;
        index = 0;
        entryOff = 0;
        zero = 0;
        one = 1;
        goto loop_check;
    loop_body:
        if (PLAYER_SETPLAY(entryOff) != 0) {
            if (locked == 0) {
                locked = 1;
                fn_8011C274(lbl_8055DED4,
                    (void *)((s32)mgr + 0x340));
            }
            playing = (*(s32 (**)(void *, s32))(
                PLAYER_AT(entryOff) + 0x18))(
                    PLAYER_AT(entryOff),
                    start ? 1 : 0);
            if (playing) {
                anyPlaying = 1;
            }
            if (playing == 0 && MOVIE_STREAMS_ON != 0) {
                /* the stream went idle: rewind its source ring */
                *(s32 *)(PLAYER_AT(entryOff) + 0x34) =
                    *(s32 *)(PLAYER_AT(entryOff) + 0x2C);
                *(s32 *)(PLAYER_AT(entryOff) + 0x38) =
                    *(s32 *)(PLAYER_AT(entryOff) + 0x2C);
                *(s32 *)(PLAYER_AT(entryOff) + 0x40) =
                    zero;
                frame = MOVIE_FRAME;
                if (frame == 1 &&
                    MOVIE_TICK_FRAME != frame) {
                    /* first frame of a seeked movie: nothing to drain */
                } else {
                    fn_80116F8C(PLAYER_AT(entryOff));
                }
                MOVIE_STREAMS_ON = zero;
            } else if (playing != 0 &&
                       MOVIE_STREAMS_ON == 0) {
                /* the first stream to start: restart the movie's timing */
                MOVIE_STREAMS_ON = one;
                MOVIE_TIME_BASE = zero;
                MOVIE_TIMING_328 = zero;
                MOVIE_SAVED_MS = zero;
            }
        }
        entryOff += 0x17C;
        index++;
    loop_check:
        if (index < MOVIE_PLAYER_COUNT) {
            goto loop_body;
        }
        if (locked != 0) {
            fn_8011C2EC(lbl_8055DED4, (u8 *)mgr + 0x340);
        }
    }
    return anyPlaying;
    #undef MOVIE_FRAME
    #undef MOVIE_TIME_BASE
    #undef MOVIE_STREAMS_ON
    #undef MOVIE_TICK_FRAME
    #undef MOVIE_PLAYER_COUNT
    #undef MOVIE_PLAYERS
    #undef MOVIE_TIMING_328
    #undef MOVIE_SAVED_MS
    #undef PLAYER_AT
    #undef PLAYER_SETPLAY
}
#pragma pop
void fn_80119214(void) {
    /* Tail-call thunk: install the AXFX memory alloc/free hooks passed by the caller. */
    AXFXSetHooks_8011FFB8();
}

/* Initializes the object's 0x30-byte parameter/state block at +0x14C: clears it,
 * stores arg2/arg3 as 16-bit values at +0x14C/+0x150, sets +0x1AC/+0x1AE and
 * mode/state at +0x144 to 3, and sets flags 0x212 in the bitfield at +0x1C. */
void fn_80119218(void *object, s16 arg1, s16 arg2, s16 arg3) {
    void *stateBlock = (u8*)object + 0x14C;
    memset(stateBlock, 0, 0x30);
    *(s16*)stateBlock = arg2;
    *(s16*)((u8*)stateBlock + 4) = arg3;
    *(s16*)((u8*)object + 0x1AC) = arg1;
    *(s16*)((u8*)object + 0x1AE) = 0;
    *(s32*)((u8*)object + 0x144) = 3;
    *(s32*)((u8*)object + 0x1C) |= 0x212;
}

#pragma push
#pragma scheduling invalid_target
void fn_80119288(void *arg0, f32 arg1) {
    /* Apply configured output parameters to the primary and secondary sub-objects, if present. */
    void *object = arg0;
    void *subObject = *(void **)((u8 *)object + 0x7C);

    if (subObject != 0) {
        s32 mode = *(s32 *)((u8 *)object + 0x78);
        ((void (*)(void *, s32, s32, s32))fn_80119218)(
            subObject,
            *(s32 *)((u8 *)object + 0xA4),
            *(s32 *)((u8 *)object + 0xA8),
            (mode == 1) ? *(s32 *)((u8 *)object + 0xAC) : 0);
    }

    subObject = *(void **)((u8 *)object + 0x80);
    if (subObject != 0) {
        ((void (*)(void *, s32, s32, s32))fn_80119218)(
            subObject,
            *(s32 *)((u8 *)object + 0xA4),
            0,
            *(s32 *)((u8 *)object + 0xAC));
    }
}
#pragma pop
/* Clear `count` bytes starting at `offset` in a ring buffer, flushing the data
 * cache after each memset.  If +4 is set the buffer is split into two channel
 * halves (+8, +0xC), so offsets and sizes are halved; a range that runs past
 * the buffer size (+0x18) is clamped and the remainder is cleared from 0. */
s32 fn_80119300(void *buffer, s32 offset, s32 count) {
    s32 clearLen;
    s32 halfLen;
    u32 bufSize;
    clearLen = count;
    bufSize = *(u32 *)((u8 *)buffer + 0x18);
    if ((u32)(count + offset) > bufSize) clearLen = (s32)(bufSize - (u32)offset);
    if (*(s32 *)((u8 *)buffer + 4) != 0) {
        offset = (s32)((u32)offset >> 1);
        halfLen = (s32)((u32)clearLen >> 1);
        memset((u8 *)*(void **)((u8 *)buffer + 8) + offset, 0, (u32)halfLen);
        DCFlushRange((u8 *)*(void **)((u8 *)buffer + 8) + offset, (u32)halfLen);
        memset((u8 *)*(void **)((u8 *)buffer + 0xC) + offset, 0, (u32)halfLen);
        DCFlushRange((u8 *)*(void **)((u8 *)buffer + 0xC) + offset, (u32)halfLen);
        if ((u32)clearLen < (u32)count) {
            clearLen = (s32)((u32)(count - clearLen) >> 1);
            memset(*(void **)((u8 *)buffer + 8), 0, (u32)clearLen);
            DCFlushRange(*(void **)((u8 *)buffer + 8), (u32)clearLen);
            memset(*(void **)((u8 *)buffer + 0xC), 0, (u32)clearLen);
            DCFlushRange(*(void **)((u8 *)buffer + 0xC), (u32)clearLen);
        }
    } else {
        memset((u8 *)*(void **)((u8 *)buffer + 8) + offset, 0, (u32)clearLen);
        DCFlushRange((u8 *)*(void **)((u8 *)buffer + 8) + offset, (u32)clearLen);
        if ((u32)clearLen < (u32)count) {
            clearLen = count - clearLen;
            memset(*(void **)((u8 *)buffer + 8), 0, (u32)clearLen);
            DCFlushRange(*(void **)((u8 *)buffer + 8), (u32)clearLen);
        }
    }
}
extern void AXSetVoiceState(void *, s32);
void fn_8011943C(void *voices, s32 state) {
    /* SetVoicePairState: apply an AX voice state to both handles in a StreamPlayer's
     * voice pair (voices+0 and voices+4), skipping any null handle. */
    s32 voice0;
    s32 voice1;
    voice0 = *(s32 *)voices;
    if (voice0 != 0) {
        ((void (*)())AXSetVoiceState)(voice0, state);
    }
    if ((voice1 = *(s32 *)((u8 *)voices + 4)) != 0) {
        ((void (*)())AXSetVoiceState)(voice1, state);
    }
}

void fn_80119498(void *voices) {
#define SetVoicePairState fn_8011943C
    /* Start the voice pair: set both AX voices to state 1 (running) and clear
     * the owning StreamPlayer's paused flag (+0x38 into the voice block). */
    SetVoicePairState(voices, 1);
    *(s32 *)((u8 *)voices + 0x38) = 0;
#undef SetVoicePairState
}

/* Combines the voice's split 16-bit read position (+0x1BC high, +0x1BE low)
   into one 32-bit sample offset. */
s32 fn_801194D0(void *voice) {
    return *(u16 *)((u8 *)voice + 0x1BE) + (*(u16 *)((u8 *)voice + 0x1BC) << 16);
}

s32 fn_801194E4(void *voiceState) {
    /* Sample the voice read position until two samples are within 0x400, then derive the adjusted byte offset. */
    s32 first;
    s32 current;
    s32 result;
    do {
        first = fn_801194D0(*(void **)voiceState);
        fn_801194D0(*(void **)voiceState);
        result = fn_801194D0(*(void **)voiceState);
    } while ((u32)(result - first) >= 0x400);
    current = result * 2 - *(s32 *)((u8 *)voiceState + 0x10);
    if (*(s32 *)((u8 *)voiceState + 4) != 0)
        current *= 2;
    return current;
}

/* Start the voice pair and record the initial read position/time in its owning
 * StreamPlayer (voices is &StreamPlayer.voices; +0x34/+0x38/+0x48/+0x50 alias
 * the player's looping, paused, readPos and readPosTime). */
void fn_80119558(void *voices) {
    *(s32 *)((u8 *)voices + 0x34) = 1;
    fn_80119498(voices);
    *(s32 *)((u8 *)voices + 0x48) = fn_801194E4(voices);
    *(s32 *)((u8 *)voices + 0x50) = fn_80116D30();
}

void fn_801195A0(void *voices) {
#define SetVoicePairState fn_8011943C
    /* Stop the voice pair: set both AX voices to state 0 (stopped) and set the
     * owning StreamPlayer's paused flag (+0x38 into the voice block). */
    SetVoicePairState(voices, 0);
    *(s32 *)((u8 *)voices + 0x38) = 1;
#undef SetVoicePairState
}

void fn_801195D8(void *arg0) {
    /* Feed the stream voices: while the ring has more than the fill threshold
     * free, copy the remaining decoded source bytes into the ring (deinterleave
     * stereo 16-bit samples into the two channel buffers, or plain bytes for
     * mono), flush the caches and advance the source cursor, ring position and
     * counters under interrupts; restart the voices once the stream drains. */
    #define SRC_BEGIN  (*(u8 **)(player + 0x2C))          /* decoded-source wrap pointer */
    #define SRC_END    (*(u8 **)(player + 0x30))          /* decoded-source end */
    #define SRC_CURSOR (*(u8 **)(player + 0x38))          /* decoded-source read cursor */
    #define BYTES_FREE (*(u32 *)(player + 0x40))          /* free bytes in the voice ring */
    #define LOW_WATER  (*(u32 *)(player + 0x54))          /* stop feeding at/below this */
    #define CHANNELS   (*(s32 *)(player + 0x78))          /* 1 = mono, 2 = stereo */
    #define LEFT_BUF   (*(u8 **)(player + 0x84))          /* left / mono ring buffer */
    #define RIGHT_BUF  (*(u8 **)(player + 0x88))          /* right ring buffer */
    #define RING_BYTES (*(u32 *)(player + 0x94))          /* ring capacity in bytes */
    #define LOOPING    (*(s32 *)(player + 0xB0))
    #define PAUSED     (*(s32 *)(player + 0xB4))
    #define WRITE_POS       (*(u32 *)(player + 0xB8))
    #define WRITE_POS_RELOAD (*(volatile u32 *)(player + 0xB8))
    #define TO_PLAY    (*(u32 *)(player + 0xBC))          /* bytes still to be played */

    u8 *player = (u8 *)arg0;
    u32 freeBytes = BYTES_FREE;
    u8 *src;
    u32 count, pos, ringBytes, irq;

    if (freeBytes > LOW_WATER) {
        count = TO_PLAY;
        if (count > freeBytes) count = freeBytes;
        pos = WRITE_POS;
        ringBytes = RING_BYTES;
        if (count + pos > ringBytes) count = ringBytes - pos;
        src = SRC_CURSOR;
        if (src + count > SRC_END) count = SRC_END - src;
        if (CHANNELS != 1) {
            u32 p = WRITE_POS_RELOAD;
            u16 *left = (u16 *)(LEFT_BUF + (p >> 1));
            u16 *r, *right;
            u16 *l = left;
            u32 i;
            right = (u16 *)(RIGHT_BUF + (p >> 1));
            r = right;
            for (i = count >> 2; i != 0; --i) {
                *l++ = *(u16 *)src; src += 2;
                *r++ = *(u16 *)src; src += 2;
            }
            DCFlushRange(left, (l - left) * 2);
            DCFlushRange(right, (r - right) * 2);
        } else {
            u8 *dst = LEFT_BUF + pos;
            memcpy(dst, src, count);
            DCFlushRange(dst, count);
            src += count & ~1;
        }
        irq = OSDisableInterrupts();
        BYTES_FREE -= count;
        OSRestoreInterrupts(irq);
        if (src >= SRC_END) src = SRC_BEGIN;
        SRC_CURSOR = src;
        pos = WRITE_POS + count;
        ringBytes = RING_BYTES;
        WRITE_POS = pos;
        if (pos >= ringBytes) WRITE_POS = pos - ringBytes;
        count = TO_PLAY - count;
        TO_PLAY = count;
        if (LOOPING == 0 && count == 0 && PAUSED == 0)
            fn_80119558(player + 0x7c);
    }
    #undef SRC_BEGIN
    #undef SRC_END
    #undef SRC_CURSOR
    #undef BYTES_FREE
    #undef LOW_WATER
    #undef CHANNELS
    #undef LEFT_BUF
    #undef RIGHT_BUF
    #undef RING_BYTES
    #undef LOOPING
    #undef PAUSED
    #undef WRITE_POS
    #undef WRITE_POS_RELOAD
    #undef TO_PLAY
}

/* The pair of AX voices a stream is played through, plus the PCM ring buffers
   they read. fn_8011943C sets both voices' AX state, fn_80119300 clears a range
   of the buffers and fn_801199A4 re-applies their sample-range parameters.
   The start/stop helpers (fn_80119498, fn_80119558, fn_801195A0) reach further
   into this block, to +0x34, +0x38, +0x48 and +0x50: those are the owning
   StreamPlayer's looping, paused, readPos and readPosTime, which the player
   fields below alias. */
typedef struct VoicePair {
    s32 voice0;   /* 0x00 AX voice handle, left or mono */
    s32 voice1;   /* 0x04 AX voice handle, right */
    void *buf0;   /* 0x08 PCM buffer the voices read, left or mono */
    void *buf1;   /* 0x0C PCM buffer, right */
    char pad_10[8];
    s32 length;   /* 0x18 ring size in bytes */
} VoicePair;

/* Streaming PCM player: fn_80119DD0 opens it and installs the callbacks below,
   fn_801195D8 copies decoded samples into the voice buffers as a ring of
   voices.length bytes, and bytesToPlay counts what is left to hand over. */
typedef struct StreamPlayer {
    void *tick;         /* 0x00 fn_80119824, called every frame while playing */
    void *field_04;     /* 0x04 */
    void *field_08;     /* 0x08 */
    void *setVolume;    /* 0x0C fn_80119AB0 */
    void *setPan;       /* 0x10 fn_80119B38 */
    void *setPause;     /* 0x14 fn_80119CB0 */
    void *setPlay;      /* 0x18 fn_80119C0C */
    void *release;      /* 0x1C fn_80119D40 */
    /* 0x20..0x5B: decoded-source ring (start 0x2C, end 0x30, read cursor 0x38),
     * free-byte counter at 0x40, 16->8-bit sample flag at 0x44 and fill
     * thresholds at 0x48/0x54/0x58 (see STREAM_AT above).  fn_801195D8 feeds
     * the voice ring from this source ring while free bytes exceed 0x54. */
    char pad_20[0x3C];
    s32 resynced;       /* 0x5C the ring ran dry and was skipped over with silence */
    char pad_60[4];
    s32 playing;        /* 0x64 */
    char pad_68[8];
    s32 sampleRate;     /* 0x70 */
    s32 field_74;       /* 0x74 */
    s32 channels;       /* 0x78 1 = mono, 2 = stereo */
    VoicePair voices;   /* 0x7C */
    s32 channelBytes;   /* 0x98 one channel's share of the ring */
    s32 blockBytes;     /* 0x9C 50 ms of audio, rounded up to 256 bytes */
    s32 field_A0;       /* 0xA0 sample rate again */
    s32 volume;         /* 0xA4 */
    s32 pan0;           /* 0xA8 */
    s32 pan1;           /* 0xAC */
    s32 looping;        /* 0xB0 keep the voices running when the buffer runs dry */
    s32 paused;         /* 0xB4 */
    s32 writePos;       /* 0xB8 where the next decoded byte goes in the ring */
    s32 bytesToPlay;    /* 0xBC bytes still to play before the stream ends */
    s32 preFill;        /* 0xC0 bytesToPlay to arm the ring with on start */
    s32 readPos;        /* 0xC4 voices' read position, as last sampled */
    s32 resyncLimit;    /* 0xC8 90% of the ring: this much free skips ahead */
    s32 readPosTime;    /* 0xCC ms at which readPos was last sampled */
    s32 resyncInterval; /* 0xD0 ms between two silence-filling resyncs */
} StreamPlayer;

/* Keep the stream's PCM ring ahead of the AX voices: re-sample how far they
 * have read, and while the ring has room either hand them the next block of
 * decoded samples (fn_801195D8) or, once they are so far ahead that the
 * decoder can never catch up, skip writePos forward over silence and mark the
 * player as resynced.  Always returns 0. */
s32 fn_80119824(void *arg0) {
    StreamPlayer *player = (StreamPlayer *)arg0;
    s32 now;
    s32 sinceSample;
    u32 readPos, writePos, ringSize, freeBytes, block;
    if (player->paused != 0 || player->playing == 0) {
        return 0;
    }
    if (player->looping == 0) {
        ((void (*)(void))fn_801195D8)();
        return 0;
    }
    readPos = player->readPos;
    if ((u32)(fn_80116D30() - player->readPosTime) > 0xC) {
    resample:
        readPos = fn_801194E4(&player->voices);
        now = fn_80116D30();
        sinceSample = now - player->readPosTime;
        player->readPos = readPos;
        if ((u32)sinceSample < (u32)player->resyncInterval) {
            goto stamp;
        }
        player->readPosTime = now;
        goto skipAhead;
    stamp:
        player->readPosTime = now;
    }
    writePos = player->writePos;
    if (readPos < writePos) {
        freeBytes = readPos + player->voices.length - writePos;
    } else {
        freeBytes = readPos - writePos;
    }
    /* what fits before the read position, keeping a 1 kB safety margin */
    block = (freeBytes < 0x400) ? 0 : ((freeBytes - 0x400) & 0xFFFFFFFC);
    if (block >= (u32)player->blockBytes) {
        goto enough;
    }
    if (player->bytesToPlay == 0) {
        goto done;
    }
    if (block == 0) {
        goto done;
    }
enough:
    if (block < (u32)player->resyncLimit) {
        goto handOver;
    }
skipAhead:
    player->resynced = 1;
    fn_80119300(&player->voices, player->writePos, player->blockBytes * 2);
    ringSize = player->voices.length;
    writePos = player->writePos + player->blockBytes * 2;
    player->writePos = writePos;
    if (writePos >= ringSize) {
        player->writePos = writePos - ringSize;
    }
    goto resample;
handOver:
    player->bytesToPlay = block;
    fn_801195D8(player);
done:
    return 0;
}

extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_801199A4(void *, s32);

/* Default no-op callback in the stream-player dispatch table: reports 0. */
s32 fn_80119994(void) { return 0; }

/* Default no-op callback in the stream-player dispatch table: reports 0. */
s32 fn_8011999C(void) { return 0; }

/* Configures a rect parameter block and applies it to the primary target (and optional secondary target) via fn_8003381C. When useMidpointLimit is non-zero, each axis limit is set to its midpoint; otherwise it is read from the target object at +0x1BC. */
s32 fn_801199A4(void *obj, s32 useMidpointLimit) {
    extern void fn_8003381C(void *, s16 *);
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
    width = *(u32 *)((u8 *)obj + 0x10);
    x0 = width >> 1;
    x1 = ((width + *(u32 *)((u8 *)obj + 0x1C)) >> 1) - 1;
    if (useMidpointLimit != 0)
        limit = x0;
    else
        limit = *(u32 *)(*(u32 *)obj + 0x1BC);
    rect[2] = x0 >> 16;
    rect[3] = x0;
    rect[4] = x1 >> 16;
    rect[5] = x1;
    rect[6] = limit >> 16;
    rect[7] = limit;
    fn_8003381C(*(void **)obj, rect);
    if (*(void **)((u8 *)obj + 4) != 0) {
        height = *(u32 *)((u8 *)obj + 0x14);
        y0 = height >> 1;
        y1 = ((height + *(u32 *)((u8 *)obj + 0x1C)) >> 1) - 1;
        if (useMidpointLimit != 0)
            limit = y0;
        else
            limit = *(u32 *)(*(u32 *)((u8 *)obj + 4) + 0x1BC);
        rect[2] = y0 >> 16;
        rect[3] = y0;
        rect[4] = y1 >> 16;
        rect[5] = y1;
        rect[6] = limit >> 16;
        rect[7] = limit;
        fn_8003381C(*(void **)((u8 *)obj + 4), rect);
    }
}

/* Converts a volume value in 0..0x7FFF to the voice parameter scale and applies it. */
void fn_80119AB0(void *arg0, s32 arg1) {
    s32 value = arg1;
    f32 scaled;
    if (value < 0) value = 0;
    if (value > 0x7fff) value = 0x7fff;
    scaled = (f32) fn_8002EFBC((f32)value, lbl_80561198);
    *(s32 *)((u8 *)arg0 + 0xa4) = (s32)(lbl_805611A0 * scaled);
    fn_80119288(arg0, scaled);
}

extern f32 lbl_805611B0;
extern f32 lbl_805611B4;
extern f64 lbl_805611B8;
extern f32 lbl_805611C0;
void fn_80119B38(void *obj, s32 input) {
    /* Clamp input to [0, 0x10000], compute complementary 0.3-power weights, store results, and apply. */
    s32 value = input;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f1;

    if (value < 0) value = 0;
    if (value > 0x10000) value = 0x10000;

    temp_f31 = (f32)value / lbl_805611B0;
    temp_f3 = (f32)fn_8002EFBC(lbl_805611B4 - temp_f31, (double)0.3f);
    *(s32*)((u8*)obj + 0xa8) = (s32)(lbl_805611C0 * temp_f3);

    temp_f1 = (f32)fn_8002EFBC(temp_f31, (double)0.3f);
    *(s32*)((u8*)obj + 0xac) = (s32)(lbl_805611C0 * temp_f1);

    fn_80119288(obj, temp_f1);
}

extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_801199A4(void *, s32);

/* The pair of AX voices a stream is played through, plus the PCM ring buffers
   they read. fn_8011943C sets both voices' AX state, fn_80119300 clears a range
   of the buffers and fn_801199A4 re-applies their sample-range parameters.
   The start/stop helpers (fn_80119498, fn_80119558, fn_801195A0) reach further
   into this block, to +0x34, +0x38, +0x48 and +0x50: those are the owning
   StreamPlayer's looping, paused, readPos and readPosTime, which the player
   fields below alias. */
/* The pair of AX voices and the StreamPlayer are described above fn_80119824. */

#pragma optimization_level 4
/* Start (start != 0) or stop the stream player and return the new playing flag.
   Starting re-arms the ring with its pre-fill and drops the loop flag; stopping
   parks both AX voices, re-applies their centred range parameters and zeroes the
   whole output buffer. */
s32 fn_80119C0C(StreamPlayer *arg0, s32 start) {
    StreamPlayer *self = arg0;
    if (start != 0) {
        if (arg0->playing == 0) {
            arg0->looping = 0;
            arg0->playing = 1;
            arg0->writePos = 0;
            arg0->bytesToPlay = arg0->preFill;
            goto exit;
        }
    }
    if (start == 0 && arg0->playing != 0) {
        VoicePair *voices = &arg0->voices;
        fn_8011943C(voices, 0);
        fn_801199A4(&self->voices, 1);
        fn_80119300(&self->voices, 0, self->voices.length);
        self->playing = 0;
    }
exit:
    return self->playing;
}
/* Pause (pause != 0) or resume the stream, and return the new paused flag.
   Only a ring that is free-running on its own (looping) has its AX voices
   stopped and restarted; resuming a stream whose data has all been handed to
   the ring re-arms the voices at their current read position instead. */
s32 fn_80119CB0(StreamPlayer *player, s32 pause) {
    s32 *paused;
    if (pause != 0) {
        if (player->looping != 0) {
            fn_801195A0(&player->voices);
        }
        paused = &player->paused;
        player->paused = 1;
    } else {
        if (player->looping == 0) {
            if (player->bytesToPlay == 0) {
                fn_80119558(&player->voices);
            }
        } else {
            fn_80119498(&player->voices);
        }
        paused = &player->paused;
        player->paused = 0;
    }
    return *paused;
}

void fn_80119D40(void *arg0) {
    /* Release stream player voice handles/buffers, invoke allocator release callback, and mark inactive. */
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
    struct Context *player = (struct Context *)arg0;
    struct CallbackTable *callbackTable;
    void (*releaseCallback)(s32, struct CallbackTable *);

    if (player->buffer0 != 0) {
        player->flag = 1;
        fn_8011943C(&player->buffer0, 0);
        if (player->buffer0 != 0)
            TRKGetFreeBuffer((void *)player->buffer0);
        if (player->buffer1 != 0)
            TRKGetFreeBuffer((void *)player->buffer1);
        callbackTable = (struct CallbackTable *)&lbl_8055DEE0;
        releaseCallback = callbackTable->callback;
        releaseCallback(player->buffer2, callbackTable);
        lbl_8055DEE8 -= 1;
        player->buffer0 = 0;
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
    register u32 sampleRate = arg1;
    u32 count, rate, frames, i, loopSample, loopBuffer;
    u32 *buffer;
    struct { s16 config[7]; u8 pad[2]; u8 work[0x28]; volatile u8 reserve[8]; } scratch;

    if (!lbl_8055DEE0) return 0;
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
    *(u32 *)(ctx + 0xC8) = (frames * 0x5A) / 100;
    *(u32 *)(ctx + 0x9C) = ((count * 0x32) / 1000 + 0xFF) & ~0xFF;
    if (*(u32 *)((u8 *)arg5 + 0x14) != 0 && *(u32 *)((u8 *)arg5 + 0x18) != 0) {
        int divisor = *(u32 *)((u8 *)arg5 + 0x14);
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
    *(u32 *)(ctx + 0x90) = *(u32 *)(ctx + (unsigned)0x8C) + *buffer;
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
        ++buffer;
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
    ++lbl_8055DEE8;
    return 1;
}

extern s32 lbl_8055DEE0;
extern s32 lbl_8055DEE4;
extern s32 lbl_8055DEE8;
extern s32 fn_80119DD0(void *, u32, s32, s32, s32, void *);
extern void fn_8011A6A0(void *);
extern void TRKGetFreeBuffer(void *);
/* Install the streaming-player callback table (or clear it when table is NULL), then return the PCM player's open routine. */
void *fn_8011A168(void *table) {
    if (table == 0) {
        lbl_8055DEE0 = 0;
        *((s32 *)&lbl_8055DEE0 + 1) = 0;
    } else {
        *(Pair8011A168 *)&lbl_8055DEE0 = *(Pair8011A168 *)table;
    }
    return &fn_80119DD0;
}

void fn_8011A1A0(u32 *data, u32 size) {
    #pragma scheduling off
    union { u32 *p; u32 i; } u;
    u32 count;
    u32 groups;
    u.p = data;
    count = (size + 3) >> 2;
    if (count == 0) return;
    groups = count >> 3;
    while (groups--) {
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
    }
    count %= 8;
    while (count--) {
        *(u32 *)u.i = __lwbrx(0, u.i); u.i += 4;
    }
}
#pragma scheduling on
u32 fn_8011A240(void *dvdFile, u32 startOffset, s32 dstAddr, u32 byteCount) {
    /* Synchronously read byteCount bytes from the DVD file at startOffset into
       dstAddr through an aligned stack buffer; returns bytes read, 0 on drive error. */
    u8 buffer[0x41F];
    register void *block = dvdFile;
    register u32 bufferAddr;
    register u32 bufCapacity;
    register s32 totalRead = 0;
    register u32 chunkSize;
    register s32 bytesLeft = (s32)byteCount;
    register s32 dstPtr = dstAddr;
    register s32 readOffset = (s32)startOffset;

    bufferAddr = (u32)(buffer + 0x1F) & 0xFFFFFFE0;
    bufCapacity = ((u32)(buffer + 0x41F) - bufferAddr) & 0xFFFFFFE0;
    while (bytesLeft != 0) {
        chunkSize = ((u32)bytesLeft + 0x1F) & 0xFFFFFFE0;
        if ((u32)bytesLeft >= bufCapacity) chunkSize = bufCapacity;
        DVDReadAsyncPrio(block, (void *)bufferAddr, chunkSize, readOffset, 0, 0);
poll_drive:
        switch (DVDGetDriveStatus()) {
        case 0:
            break;
        case -1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            return 0;
        default:
            goto poll_drive;
        }
        if (chunkSize > (u32)bytesLeft) chunkSize = (u32)bytesLeft;
        memcpy((void *)dstPtr, (void *)bufferAddr, chunkSize);
        dstPtr += chunkSize;
        totalRead += chunkSize;
        bytesLeft -= chunkSize;
        readOffset += chunkSize;
    }
    return totalRead;
}

/* Ring-buffered DVD file stream.  fn_8011ACC4 opens the file (or takes the caller's
   already-open DVDFileInfo, which it copies in at +0x54), fn_8011AC10 hands it the
   ring buffer to fill, fn_8011A6A0 keeps queueing 32 KiB async reads into the ring
   and fn_8011A8FC drains it.  A read is padded backwards to a 32-byte boundary, so
   its data lands padSize bytes past the write pointer and the read callback (
   fn_8011A4F8) slides it into place. */
typedef struct DvdStream {
    void *readAt;          /* 0x00 fn_8011A388: read at an absolute file offset */
    void *read;            /* 0x04 fn_8011A8FC: read the next bytes of the stream */
    void *roundSize;       /* 0x08 fn_8011AC04: round a read size up to a 32 KiB block */
    void *setBuffer;       /* 0x0C fn_8011AC10: give the stream its ring buffer */
    void *poll;            /* 0x10 fn_8011A7CC: pump the drive and report the stream state */
    void *close;           /* 0x14 fn_8011AC84 */
    void *setPause;        /* 0x18 fn_8011A870 */
    char pad_1C[4];
    s32 error;             /* 0x20 set when a read came up short */
    s32 reading;           /* 0x24 an async read is in flight */
    s32 totalRead;         /* 0x28 bytes the drive has moved into the ring */
    s32 timeMode;          /* 0x2C which of the two read-time counters a read counts into */
    s32 readTime;          /* 0x30 time spent waiting on reads */
    s32 totalTime;         /* 0x34 time spent inside the read calls */
    s32 readTimeSync;      /* 0x38 readTime with timeMode 0 */
    s32 readTimeStream;    /* 0x3C readTime with timeMode set */
    u32 capacity;          /* 0x40 ring size in bytes */
    volatile u32 peakFill; /* 0x44 most data the ring has ever held */
    u32 available;         /* 0x48 bytes a reader can take without waiting */
    volatile u32 fill;     /* 0x4C data the ring holds right now */
    s32 paused;            /* 0x50 stop queueing reads */
    DVDFileInfo fileInfo;  /* 0x54 the file being streamed */
    s32 readOffset;        /* 0x90 file offset the next read starts at */
    s32 padSize;           /* 0x94 bytes read before readOffset to reach a 32-byte boundary */
    u32 consumerOffset;    /* 0x98 file offset of the next byte the reader wants */
    u32 consumerPtr;       /* 0x9C where that byte sits in the ring */
    u32 freeSpace;         /* 0xA0 room left in the ring */
    u32 bufferStart;       /* 0xA4 */
    u32 bufferEnd;         /* 0xA8 */
    u32 writePtr;          /* 0xAC where the next read's data goes */
    s32 keepOpen;          /* 0xB0 the caller's file info: close() must not DVDClose it */
    u32 discOffset;        /* 0xB4 base offset the reads are relative to */
    s32 endOffset;         /* 0xB8 offset the stream ends at */
    s32 rate;              /* 0xBC bytes/second to pace the reads at, 0 = no pacing */
    s32 waitTicks;         /* 0xC0 pacing debt still to sleep off (fn_8011A45C) */
    s32 cancelling;        /* 0xC4 a DVDCancel is in progress */
    s32 timeModeUsed;      /* 0xC8 timeMode as it was when the current read was queued */
    s32 readStart;         /* 0xCC tick the current read was queued at, then its duration */
    struct DvdStream *self; /* 0xD0 the stream itself, so the read callback, which only
                                gets the +0x54 file info, can find its owner */
} DvdStream;

#pragma scheduling on
#pragma dont_inline on
void fn_8011A330(void *dvdStream) {
    /* DvdStream_Cancel: abort a stream's in-flight DVD read.  Flag the read callback to
       ignore the result, DVDCancel the transfer, wait out the BUSY/WAITING drive states,
       then clear the cancelling and reading flags. */
    DvdStream *stream = (DvdStream *)dvdStream;
    s32 driveState;
    *(volatile s32 *)&stream->cancelling = 1;
    DVDCancel((DVDCommandBlock *)&stream->fileInfo);
    do {
        driveState = DVDGetDriveStatus();
    } while (driveState == DVD_STATE_WAITING || driveState == DVD_STATE_BUSY);
    *(volatile s32 *)&stream->cancelling = 0;
    *(volatile s32 *)&stream->reading = 0;
}
#pragma dont_inline reset

u32 fn_8011A388(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    extern u32 fn_8011A240(void *, u32, s32, u32);
    extern void fn_8011A330(void *);
    volatile u32 *offset = (volatile u32 *)((u8 *)arg0 + 0x90);
    volatile u32 *base = (volatile u32 *)((u8 *)arg0 + 0xB4);
    volatile u32 *capacityPtr = (volatile u32 *)((u8 *)arg0 + 0x40);
    u32 result = arg3;
    u32 current;
    u32 end;
    u32 newPosition;
    u32 capacity;
    u32 remaining;
    if (arg1 != -1 && *offset != (u32)arg1) {
        *offset = (u32)arg1;
        current = *offset;
        result = fn_8011A240((u8 *)arg0 + 0x54, current + *base, arg2, arg3);
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
        if (capacity <= remaining) {
            *(u32 *)((u8 *)arg0 + 0x48) = *capacityPtr;
        }
        fn_8011A1A0((u32 *)arg2, result);
    }
    return result;
}

#pragma unroll reset
void fn_8011A45C(void *arg0, s32 arg1, s32 arg2) {
    /* Accumulate pacing debt from the requested work and sleep until the elapsed time catches up. */
    s32 temp_r0;
    s32 scaledTicks;
    s32 now;
    s32 now2;
    s32 elapsed;
    s32 lastTime;
    volatile s32 *waitTicks = (volatile s32 *)((u8 *)arg0 + 0xC0);

    scaledTicks = fn_80116BD4(arg1, 0x3E8, *(s32 *)((u8 *)arg0 + 0xBC));
    now = fn_80116D30();
    lastTime = now;
    *waitTicks = *waitTicks + (scaledTicks - (now - arg2));
    while (*waitTicks > 0) {
        do {
            now2 = fn_80116D30();
            temp_r0 = *waitTicks;
            elapsed = now2 - lastTime;
        } while (elapsed < temp_r0);
        lastTime = now2;
        *waitTicks = temp_r0 - elapsed;
    }
}

/* DvdStreamReadCallback: completion callback of the 32 KiB read fn_8011A6A0 queued
   for a stream.  transferSize bytes landed at the write pointer, padSize of them
   ahead of the wanted data, so slide the chunk into the ring, update the stream's
   counters, wait off the pacing rate and queue the next read unless the stream is
   paused.  @p fileInfo is the +0x54 file info the read was started with. */
void fn_8011A4F8(s32 transferSize, DVDFileInfo *fileInfo) {
    s32 padMoved, elapsed, padSize;
    u32 writePos, newWritePos, size;
    DvdStream *stream;
    s32 remaining;

    size = transferSize;
    stream = *(DvdStream **)((u8 *)fileInfo + 0x7C); /* stream->self, see fn_8011AC10 */
    if (stream->cancelling == 0) {
        if (transferSize != 0x8000) {
            remaining = stream->endOffset - stream->readOffset;
            if (transferSize != (u32)(remaining + stream->padSize)) {
                stream->reading = 0;
                stream->error = 1;
                return;
            }
        }
        padSize = stream->padSize;
        if (padSize != 0) {
            writePos = stream->writePtr;
            memmove((void *)writePos, (void *)(writePos + padSize), stream->endOffset - stream->readOffset);
            padMoved = stream->padSize;
            stream->padSize = 0;
            size -= padMoved;
        }
        stream->totalRead += size;
        stream->readOffset += size;
        newWritePos = stream->writePtr + size;
        stream->writePtr = newWritePos;
        if (newWritePos >= stream->bufferEnd)
            stream->writePtr = stream->bufferStart;
        stream->freeSpace -= size;
        stream->fill += size;
        if (stream->fill > stream->peakFill)
            stream->peakFill = stream->fill;
        if (stream->rate != 0)
            fn_8011A45C(stream, size, stream->readStart);
        elapsed = fn_80116D30() - stream->readStart;
        stream->readStart = elapsed;
        stream->readTime += elapsed;
        if (stream->timeModeUsed != 0 || stream->timeMode != 0)
            stream->readTimeStream += stream->readStart;
        else
            stream->readTimeSync += stream->readStart;
        stream->reading = 0;
        if (stream->paused == 0)
            fn_8011A6A0(stream);
    }
}

void fn_8011A6A0(void* arg0) {
    /* Pump DVD streaming reads: check drive status, flag errors/cancel, and queue the next async read chunk when ready. */
    s32 driveStatus = DVDGetDriveStatus();
    s32 bytesRemaining = *(s32*)((u8*)arg0 + 0xB8) - *(s32*)((u8*)arg0 + 0x90);
    if (driveStatus == 10)
        goto check_read;
    if (driveStatus >= 10)
        goto status_high;
    if (driveStatus == -1)
        goto set_flag;
    if (driveStatus < -1)
        goto check_read;
    if (driveStatus < 3)
        goto check_read;
    goto set_flag;
status_high:
    if (driveStatus >= 12)
        goto check_read;
set_flag:
    *(s32*)((u8*)arg0 + 0x20) = 1;
    goto done;
check_read:
    if (*(s32*)((u8*)arg0 + 0xC4) != 0)
        goto done;
    if (driveStatus == 0)
        goto read_valid;
    if (driveStatus == 10)
        goto read_valid;
    goto done;
done:
    return;
read_valid:
    if (*(u32*)((u8*)arg0 + 0xA0) >= 0x8000 && bytesRemaining != 0) {
        *(s32*)((u8*)arg0 + 0xC8) = *(s32*)((u8*)arg0 + 0x2C);
        *(s32*)((u8*)arg0 + 0xCC) = fn_80116D30();
        *(s32*)((u8*)arg0 + 0x24) = 1;
        if ((u32)bytesRemaining > 0x8000)
            bytesRemaining = 0x8000;
        else if (bytesRemaining & 0x1F) {
            s32 pad = (-bytesRemaining) & 0x1F;
            *(s32*)((u8*)arg0 + 0x94) = pad;
            bytesRemaining += pad;
        }
        DVDReadAsyncPrio((u8*)arg0 + 0x54, *(s32*)((u8*)arg0 + 0xAC), bytesRemaining,
            *(s32*)((u8*)arg0 + 0xB4) + (*(s32*)((u8*)arg0 + 0x90) - *(s32*)((u8*)arg0 + 0x94)),
            fn_8011A4F8, 0);
        goto done;
    }
    *(s32*)((u8*)arg0 + 0x48) = *(s32*)((u8*)arg0 + 0x4C);
    goto done;
}

s32 fn_8011A7CC(DVDFileInfo *fileInfo) {
    /* Check DVD drive state for this file: return 0 if an operation/error is
     * already flagged (+0x20/+0x50), on status 0 invoke fn_8011A6A0, on certain
     * error statuses set the error flag at +0x20, and return the value at +0x24. */
    s32 *file = (s32 *)fileInfo;
    s32 status;

    if (file[0x20 / 4] != 0) return 0;
    if (file[0x50 / 4] != 0) return 0;
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
    fn_8011A6A0(fileInfo);
    goto done;
set_error:
    file[0x20 / 4] = 1;
done:
    return file[0x24 / 4];
}

#pragma push
#pragma dont_inline on
/* Set or clear the stream pause state, optionally waiting for or pumping pending reads. */
s32 fn_8011A870(void *stream, s32 flags) {
    register volatile s32 *p = (volatile s32 *)stream;
    register volatile s32 *reading = (volatile s32 *)((u8 *)stream + 0x24);
    register s32 result;
    if (flags & 1) {
        if (p[0x50 / 4] == 0)
            p[0x50 / 4] = 1;
        if (flags & 0x80000000) {
            do {
            } while (*reading != 0);
        }
    } else if (flags & 2) {
        if ((u32)p[0x50 / 4] == 1U)
            p[0x50 / 4] = 0;
        if (flags & 0x80000000)
            fn_8011A7CC(stream);
    }
    result = p[0x50 / 4];
    return result;
}
#pragma pop
extern u32 fn_8011A240(void *, u32, s32, u32);
extern void fn_8011A45C(void *, s32, s32);
extern void fn_8011A1A0(u32 *, u32);
u32 fn_8011A8FC(void *arg0, s32 arg1, s32 arg2, void *arg3, u32 arg4) {
    DvdStream *stream = (DvdStream *)arg0;
    u32 seek = (u32)arg2;
    u32 work;
    volatile u32 *rd;
    u32 total = 0;
    u8 *buf0 = (u8 *)arg3;
    u32 t0;
    u32 first;
    if (stream->error != 0)
        return 0;
    t0 = fn_80116D30();
    if ((s32)seek != -1 && stream->consumerOffset != (u32)seek) {
        if ((u32)seek > stream->consumerOffset && (u32)seek <= (u32)stream->readOffset) {
            BOOL en = OSDisableInterrupts();
            volatile DvdStream *locked = stream;
            u32 offset = locked->consumerOffset;
            u32 freeSpace = locked->freeSpace;
            u32 d = seek - offset;
            u32 p = locked->consumerPtr + d;
            u32 end = locked->bufferEnd;
            locked->freeSpace = freeSpace + d;
            stream->consumerOffset = (u32)seek;
            stream->fill -= d;
            stream->consumerPtr = p;
            if (p > end)
                stream->consumerPtr = p - stream->capacity;
            OSRestoreInterrupts(en);
        } else {
            BOOL en;
            fn_8011A330(arg0);
            en = OSDisableInterrupts();
            {
                volatile DvdStream *locked = stream;
                u32 start = locked->bufferStart;
                u32 capacity;
                locked->readOffset = seek;
                capacity = locked->capacity;
                locked->consumerOffset = seek;
                locked->freeSpace = capacity;
                locked->fill = 0;
                locked->consumerPtr = start;
                locked->writePtr = start;
            }
            OSRestoreInterrupts(en);
        }
    }
    if (stream->bufferStart == 0) {
        work = fn_80116D30();
        total = fn_8011A240(&stream->fileInfo, (u32)stream->readOffset, (s32)arg3, arg4);
        if (total < arg4) {
            stream->error = 1;
            fn_8011A330(arg0);
        }
        rd = &stream->consumerOffset;
        {
            volatile DvdStream *direct = stream;
            u32 read = direct->readOffset + total;
            u32 offset = direct->consumerOffset + total;
            u32 rate = direct->rate;
            direct->readOffset = read;
            {
                u32 bytesRead = direct->totalRead;
                direct->consumerOffset = offset;
                direct->totalRead = bytesRead + total;
            }
            if (rate != 0)
                fn_8011A45C(arg0, total, work);
        }
        {
            u32 now = fn_80116D30();
            volatile DvdStream *timing = stream;
            timing->readTime += now - work;
            timing->totalTime += now - t0;
        }
    } else {
        rd = &stream->consumerOffset;
        while (arg4 != 0 && stream->error == 0) {
            fn_8011A6A0(arg0);
            work = stream->fill;
            if (work != 0) {
                if ((u32)work > arg4)
                    work = arg4;
                arg4 -= work;
                total += work;
                first = stream->bufferEnd - stream->consumerPtr;
                *rd += work;
                if (first <= (u32)work) {
                    memcpy(arg3, (void *)stream->consumerPtr, first);
                    arg3 = (u8 *)arg3 + first;
                    work = (u32)work - first;
                    stream->consumerPtr = stream->bufferStart;
                    {
                        BOOL en = OSDisableInterrupts();
                        ((volatile DvdStream *)stream)->fill -= first;
                        ((volatile DvdStream *)stream)->freeSpace += first;
                        OSRestoreInterrupts(en);
                    }
                }
                if (work != 0) {
                    memcpy(arg3, (void *)stream->consumerPtr, work);
                    arg3 = (u8 *)arg3 + work;
                    stream->consumerPtr += work;
                    {
                        BOOL en = OSDisableInterrupts();
                        ((volatile DvdStream *)stream)->fill -= work;
                        ((volatile DvdStream *)stream)->freeSpace += work;
                        OSRestoreInterrupts(en);
                    }
                }
            }
        }
        stream->totalTime += fn_80116D30() - t0;
    }
    {
        u32 rem = (u32)stream->endOffset - *rd;
        rem = rem < stream->capacity ? rem : ((volatile DvdStream *)stream)->capacity;
        ((volatile DvdStream *)stream)->available = rem;
    }
    if (stream->fill + 0x8000 > ((volatile DvdStream *)stream)->available)
        stream->available = stream->fill;
    fn_8011A1A0((u32 *)buf0, total);
    return total;
}

#pragma dont_inline reset
/* DVD stream callback: round the requested read size up to a 32 KiB block
 * boundary (the stream argument is unused). */
s32 fn_8011AC04(s32 stream, s32 size) {
#define DVD_BLOCK_ROUND 0x7FFF     /* added before masking to round up */
#define DVD_BLOCK_MASK 0xFFFF8000  /* keeps only 32 KiB-aligned bits */
    return (size + DVD_BLOCK_ROUND) & DVD_BLOCK_MASK;
#undef DVD_BLOCK_MASK
#undef DVD_BLOCK_ROUND
}

/* Configure a DVD stream with its ring buffer, end offset, and read pacing rate. */
void fn_8011AC10(void *arg0, s32 bufferStart, s32 bufferSize, s32 endOffset, s32 rate) {
    s32 interruptState = OSDisableInterrupts();
    s32 bufferEnd;
    DvdStream *stream = (DvdStream *)arg0;
    bufferSize &= 0xFFFF8000;
    bufferEnd = bufferStart + bufferSize;
    stream->freeSpace = (u32)bufferSize;
    stream->capacity = (u32)bufferSize;
    stream->bufferStart = (u32)bufferStart;
    stream->consumerPtr = (u32)bufferStart;
    stream->writePtr = (u32)bufferStart;
    stream->bufferEnd = (u32)bufferEnd;
    stream->fill = 0;
    stream->endOffset = endOffset;
    stream->rate = rate;
    stream->self = (struct DvdStream *)stream;
    OSRestoreInterrupts(interruptState);
}

extern f32 lbl_80329D48[];
extern void fn_8011A330(void *);
/* Close a DVD stream: cancel any in-flight read, then DVDClose the file unless the caller supplied it (keepOpen). */
void fn_8011AC84(void *arg0) {
    DvdStream *stream = (DvdStream *)arg0;
    fn_8011A330(stream);
    if (stream->keepOpen == 0) {
        DVDClose(&stream->fileInfo);
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
    s32 entry;
    memset(arg0, 0, 0x144);
    if (arg2 & 0x800000) {
        u32 v13 = *(u32*)((u8*)arg1 + 0x34);
        u32 v12 = *(u32*)((u8*)arg1 + 0x30);
        u32 size = *(u32*)((u8*)arg1 + 0x2C);
        u32 v10 = *(u32*)((u8*)arg1 + 0x28);
        u32 v9 = *(u32*)((u8*)arg1 + 0x24);
        u32 v8 = *(u32*)((u8*)arg1 + 0x20);
        u32 v7 = *(u32*)((u8*)arg1 + 0x1C);
        u32 v6 = *(u32*)((u8*)arg1 + 0x18);
        u32 v5 = *(u32*)((u8*)arg1 + 0x14);
        u32 v4 = *(u32*)((u8*)arg1 + 0x10);
        u32 v3 = *(u32*)((u8*)arg1 + 0x0C);
        u32 v2 = *(u32*)((u8*)arg1 + 0x08);
        u32 v1 = *(u32*)((u8*)arg1 + 0x04);
        u32 v0 = *(u32*)((u8*)arg1 + 0x00);
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
        entry = DVDConvertPathToEntrynum(arg1);
        if (entry == -1) return 0;
        if (DVDFastOpen(entry, (u8*)arg0 + 0x54) == 0) return 0;
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

f32 fn_8011AE18(s32 packedValue) {
    /* Decode a packed magnitude/sign/index value into a scaled float coefficient. */
#define scaleTable lbl_80329D48
    s32 magnitude;
    f32 result;
    magnitude = (s32)(((u32)packedValue & ~0x10000000) >> 5);
    result = (f32)magnitude * scaleTable[(u32)packedValue & 0x1F];
    if (packedValue & 0x10000000) {
        result = -result;
    }
    return result;
#undef scaleTable
}

void fn_8011AE68(s32 out, f32 *in, u32 count, f32 scale) {
    u16 *dest = (u16 *)(out - 2);
    while (count != 0) {
        s32 value = (s32)(*in * scale);
        value = (value < -0x8000) ? -0x8000 : value;
        value = (value > 0x7FFF) ? 0x7FFF : value;
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
    s32 i;
    for (i = 0; i < (s32)count; i++) {
        s32 left = (s32)(in[i] * scale);
        s32 right = (s32)(scale * second[i]);
        left = left < -0x8000 ? -0x8000 : left;
        left = left > 0x7FFF ? 0x7FFF : left;
        right = right < -0x8000 ? -0x8000 : right;
        right = right > 0x7FFF ? 0x7FFF : right;
        dest[1] = (s16)left;
        dest[2] = (s16)right;
        dest += 2;
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
    s32 var_r5_3;
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
    f32 temp_f31;
    u32 temp_r10;
    u32 temp_r5;
    u32 temp_r5_2;
    u32 temp_r9;
    u32 var_r0;
    u32 var_r24_2;
    u32 var_r4_3;
    u32 var_r3;

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

    if (!var_r0_3) {
        register s32 temp_r18 = var_r29 - var_r3;
        memset(var_r27, 0, temp_r18 * 4);
        var_r4_2 = arg3 + var_r28;
        var_r3 = var_r29;
        var_r27 += temp_r18;
        var_r5_2 = (u32 *)arg4 + var_r28;
        while (var_r29 > (u32)(*var_r5_2 * 2)) {
            var_f29 = *var_r4_2;
            var_r5_2++;
            var_r4_2++;
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
                    temp_r6_2 = var_r25 | (temp_r10 << var_r24);
                    var_r26++;
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
            factors[j] = lbl_80329BC8[index];
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
        temp_f4_2 = temp_f4 * lbl_805611E8;
        temp_f3_2 = temp_f4 * temp_f4;
        temp_f4_3 = temp_f3_2 * temp_f3;
        temp_f4_4 = lbl_805611F0 - temp_f4_3;
        temp_f4_2 = temp_f4_2 * temp_f4_4;
        temp_f3 = (f64) (f32) temp_r29;
        temp_f3_2 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = temp_f4_2 * lbl_805611E8;
        temp_f4_4 = temp_f3 * temp_f3_2;
        temp_f3 = lbl_805611F0 - temp_f4_4;
        temp_f4_2 = temp_f4_3 * temp_f3;
        temp_f4 = (f64) (f32) temp_r29;
        temp_f3 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = temp_f4_2 * lbl_805611E8;
        temp_f4_4 = temp_f3 * temp_f4;
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
        temp_f4_2 = temp_f4 * lbl_805611E8;
        temp_f3_2 = temp_f4 * temp_f4;
        temp_f4_3 = temp_f3_2 * temp_f3;
        temp_f4_4 = lbl_805611F0 - temp_f4_3;
        temp_f4_2 = temp_f4_2 * temp_f4_4;
        temp_f3 = (f64) (f32) var_r30;
        temp_f3_2 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = temp_f4_2 * lbl_805611E8;
        temp_f4_4 = temp_f3 * temp_f3_2;
        temp_f3 = lbl_805611F0 - temp_f4_4;
        temp_f4_2 = temp_f4_3 * temp_f3;
        temp_f4 = (f64) (f32) var_r30;
        temp_f3 = temp_f4_2 * temp_f4_2;
        temp_f4_3 = temp_f4_2 * lbl_805611E8;
        temp_f4_4 = temp_f3 * temp_f4;
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

#pragma push
#pragma scheduling 750
void fn_8011B94C(void *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 *arg4, s32 arg5, u32 *arg6, u32 arg7, f32 arg8, s32 arg9) {
    u8 *p = (u8 *)arg0;
    u32 i, count;
    s32 result = fn_8011B2AC(*(s32 *)p, *(u32 *)(p + 0x10), *(s32 *)(p + 0x30), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28), *(s32 *)(p + 0x14), (u32 *)arg3, *(u32 *)(p + 0x1C), *(f32 *)(p + 4), *(u32 *)(p + 0x20));
    if (*(s32 *)(p + 0x18)) *(s32 *)(p + 0x18) = 0;
    else {
        i = 0;
        count = *(u32 *)(p + 0xC) >> 1;
        for (; i < count; i++) {
            s16 *a = *(s16 **)(p + 0x14);
            s16 *b = *(s16 **)(p + 0x2C);
            a[i] = (s16)(((u32)i * a[i] + b[i] * (u32)(count - i)) / count);
        }
    }
    memcpy(*(void **)(p + 0x2C), (u8 *)*(void **)(p + 0x14) + (*(u32 *)(p + 8) - *(u32 *)(p + 0xC)), *(u32 *)(p + 0xC));
    if (arg2) *arg2 = *(u32 *)(p + 8) - *(u32 *)(p + 0xC);
    if (arg1) *arg1 = (s32)*(void **)(p + 0x14);
    if (arg4) *arg4 = arg3 + result;
}
#pragma pop
/* Free one memory block: forwards to the shared deallocator fn_80120084, which
 * calls the registered free hook for mode-3 blocks and free() otherwise.
 * BinkClose uses it to release each frame's texture. */
void fn_8011BC48(void *block) {
    fn_80120084(block);
}

s32 fn_8011BC4C(void *list, void *node) {
    /* Remove a node from a singly-linked list rooted at offset 0x30; return 1 if removed. */
    void *current;
    void *next;

    if (list == NULL) return 0;

    current = *(void **)((u8 *)list + 0x30);
    if (current == node) {
        *(void **)((u8 *)list + 0x30) = *(void **)current;
        return 1;
    }

    while ((next = *(void **)current) != NULL) {
        if (next == node) {
            *(void **)current = *(void **)node;
            return 1;
        }
        current = next;
    }

    return 0;
}

/* Inserts `node` into a singly-linked list at *head sorted by descending key at offset 8 (next pointer at offset 4). */
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

/* Periodic tick driver for the work-manager object: bump the tick counter at
 * +0x34, and while the manager's state at +0x0 is 1, run every enabled listener
 * in the +0x30 list.  Listeners that return nonzero are collected into a pending
 * list sorted by their result, and their finish callbacks are then invoked in
 * that order with the new tick count.  A mid-pass state change aborts the run. */
void fn_8011BD20(s32 manager) {
    struct TickListener {
        struct TickListener *next;
        struct TickListener *orderedNext;
        s32 result;
        s32 enabled;
        s32 unk_0x10;
        s32 (*run)(struct TickListener *, s32);
        void (*finish)(struct TickListener *, s32);
    };
    struct TickListener *listener;
    struct TickListener *pending;
    volatile s32 *tickCount;
    volatile s32 *state;
    s32 nextTickCount;
    s32 stateValue;

    tickCount = (volatile s32 *)(manager + 0x34);
    state = (volatile s32 *)manager;
    nextTickCount = *tickCount;
    stateValue = *state;
    nextTickCount = nextTickCount + 1;
    *tickCount = nextTickCount;
    if (stateValue == 1) {
        listener = *(struct TickListener **)(manager + 0x30);
        pending = 0;
        while (listener != 0) {
            if (*(s32 *)manager != 1) {
                return;
            }
            if (listener->enabled == 1) {
                listener->result = listener->run(listener, *tickCount);
                if (listener->result != 0) {
                    fn_8011BCAC((void **)&pending, listener);
                }
            }
            listener = listener->next;
        }
        listener = pending;
        while (listener != 0) {
            listener->finish(listener, *tickCount);
            listener = listener->orderedNext;
        }
    }
}

/* OS alarm handler: recovers the owner object (alarm at +8), and if it has an
 * active work flag at +0x30, runs fn_8011BD20 on it with interrupts disabled. */
void fn_8011BDF0(s32 alarmPtr) {
    s32 owner;
    s32 savedInterrupts;
    owner = alarmPtr - 8;
    if (owner != 0 && *(s32 *)(owner + 0x30) != 0) {
        savedInterrupts = OSEnableInterrupts();
        fn_8011BD20(owner);
        OSRestoreInterrupts(savedInterrupts);
    }
}

void *fn_8011BE48(s32 arg0) {
    void *ptr;

    ptr = fn_8011FFC4(0x40);
    if (ptr != NULL) {
        memset(ptr, 0, 0x40);
        *(s32 *)((u8 *)ptr + 0x00) = 0;
        *(s32 *)((u8 *)ptr + 0x04) = 1;
        *(s32 *)((u8 *)ptr + 0x30) = 0;
        *(s32 *)((u8 *)ptr + 0x34) = 1;
        *(s32 *)((u8 *)ptr + 0x38) = 0;
        *(s32 *)((u8 *)ptr + 0x3C) = (arg0 < 0) ? -arg0 : arg0;
    }
    return ptr;
}

/* Register a tick-listener node on a Bink tick object, linking it at the head
 * and storing its check/callback handlers. Runs with interrupts disabled. */
void fn_8011BEC8(void *tick, void *node, s32 checkFn, s32 tickFn) {
    s32 interruptState = OSDisableInterrupts();
    s32 one = 1;
    s32 old;
    *(s32 *)((u8 *)node + 0xC) = one;
    *(s32 *)((u8 *)node + 0x14) = checkFn;
    *(s32 *)((u8 *)node + 0x18) = tickFn;
    *(s32 *)((u8 *)node + 0x10) = 0;
    *(void **)node = *(void **)((u8 *)tick + 0x30);
    old = *(s32 *)((u8 *)tick + 0x38);
    *(void **)((u8 *)tick + 0x30) = node;
    *(s32 *)((u8 *)tick + 0x38) = old + 1;
    OSRestoreInterrupts(interruptState);
}

void fn_8011C364(s32);
#pragma opt_propagation on
s32 fn_8011BF4C(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = 0;
    s32 save;
    if (arg0 != 0 && arg1 != 0 && *(s32 *)(arg1 + 0x18) != 0 && *(s32 *)(arg1 + 0x14) != 0) {
        save = OSDisableInterrupts();
        if (fn_8011BC4C((void *)arg0, (void *)arg1) != 0) {
            *(s32 *)(arg0 + 0x38) -= 1;
            if ((arg2 & 1) != 0 && *(s32 *)(arg0 + 0x30) == 0) {
                fn_8011C364(arg0);
                ret = 1;
            }
        }
        OSRestoreInterrupts(save);
    }
    return ret;
}
s32 fn_8011BFFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    /* Combines two fn_8011BF4C results into a 2-bit status: bit 0 from
       (arg0, arg1, arg4) and bit 1 from (arg2, arg3, arg4). */
    s32 temp = fn_8011BF4C(arg2, arg3, arg4) << 1;
    s32 result = fn_8011BF4C(arg0, arg1, arg4);
    return result | temp;
}

/* Increments a refcounted object's use count under disabled interrupts.
 * If state is 1 (idle), transitions it to 2 (in-use). Returns 1 when state is 1, else 0.
 * Returns 1 for a NULL object. */
u32 fn_8011C06C(void *obj) {
    s32 oldInterrupts;
    s32 state;
    if (obj != NULL) {
        oldInterrupts = OSDisableInterrupts();
        if (*(s32 *)obj == 1)
            *(s32 *)obj = 2;
        state = *(s32 *)((char *)obj + 4);
        *(s32 *)((char *)obj + 4) = state + 1;
        OSRestoreInterrupts(oldInterrupts);
        state = *(s32 *)obj;
        return (u32)((1 - state) | (state - 1)) >> 31;
    }
    return 1;
}

s32 fn_8011C0E0(s32 syncObj) {
    /* Yield the thread until the refcounted state object at syncObj can be acquired (fn_8011C06C succeeds). */
    goto check;
yield:
    OSYieldThread();
check:
    if (fn_8011C06C((void*)syncObj) == 0)
        goto yield;
}

void fn_8011C120(void *alarm) {
    /* Release a reference to a periodic alarm: decrement its use count, and
     * when it reaches zero while the alarm is not yet armed, arm a periodic
     * alarm (frequency at +0x3C) and mark it armed. Interrupts stay disabled
     * across the update. */
    if (alarm != 0) {
        BOOL interruptState = OSDisableInterrupts();
        s32 refCount = *(volatile s32 *)((u8 *)alarm + 4);
        *(volatile s32 *)((u8 *)alarm + 4) = refCount - 1;
        if (*(volatile s32 *)((u8 *)alarm + 4) == 0) {
            if (*(volatile s32 *)alarm == 0) {
                u64 startTime = (u64)OSGetTime();
                u32 alarmPeriod = (0x3E8U / *(u32 *)((u8 *)alarm + 0x3C)) *
                                  (*(volatile u32 *)0x800000F8 / 4U / 1000U);
                ((void (*)(void *, u64, u64, void (*)(s32)))OSSetPeriodicAlarm)(
                    (u8 *)alarm + 8, startTime, (u64)alarmPeriod, fn_8011BDF0);
            }
            *(s32 *)alarm = 1;
        }
        OSRestoreInterrupts(interruptState);
    }
}

#pragma dont_inline on
/* Try to acquire a lock/state object: if valid and unlocked (state==1), set busy, increment the use count, and return whether it is now active. */
/* Try to acquire the manager lock: when the tick and lock object are valid and its guards (+0x14/+0x18) are set, mark it busy (state +0xC: 1->2) and bump its ref count (+0x10) under disabled interrupts; return whether it is now locked. */ u32 fn_8011C1E0(s32 lockTick, void *lockObj) {
    BOOL enabled;
    s32 refCount;
    s32 state;

    if (lockTick != 0 && lockObj != 0 &&
        *(s32 *)((u8 *)lockObj + 0x18) != 0 &&
        *(s32 *)((u8 *)lockObj + 0x14) != 0) {
        enabled = OSDisableInterrupts();
        if (*(s32 *)((u8 *)lockObj + 0xC) == 1)
            *(s32 *)((u8 *)lockObj + 0xC) = 2;
        refCount = *(s32 *)((u8 *)lockObj + 0x10);
        *(s32 *)((u8 *)lockObj + 0x10) = refCount + 1;
        OSRestoreInterrupts(enabled);
        state = *(s32 *)((u8 *)lockObj + 0xC);
        return (u32)((1 - state) | (state - 1)) >> 31;
    }
    return 1;
}
#pragma dont_inline reset

/* Spins until the lock at lockObj (+0xC state, +0x10 count, +0x14/+0x18 guards)
   can be acquired via fn_8011C1E0, yielding the thread between attempts. */
void fn_8011C274(s32 lockTick, void *lockObj) {
    if (lockTick != 0 && lockObj != 0 &&
        *(s32 *)((u8 *)lockObj + 0x18) != 0 &&
        *(s32 *)((u8 *)lockObj + 0x14) != 0) {
        while (fn_8011C1E0(lockTick, lockObj) == 0) {
            OSYieldThread();
        }
    }
}

void fn_8011C2EC(s32 lockTick, void *lockObj) {
    /* Release the manager lock at lockObj: decrement its ref count (+0x10) and
       clear the busy state (+0x0C -> 1/unlocked) when the count reaches zero. */
    if (lockTick != 0 && lockObj != 0 &&
        *(s32 *)((u8 *)lockObj + 0x18) != 0 &&
        *(s32 *)((u8 *)lockObj + 0x14) != 0) {
        BOOL enabled;
        volatile s32 *refCount = (volatile s32 *)((u8 *)lockObj + 0x10);
        enabled = OSDisableInterrupts();
        *refCount = *refCount - 1;
        if (*refCount == 0)
            *(s32 *)((u8 *)lockObj + 0xC) = 1;
        OSRestoreInterrupts(enabled);
    }
}

extern s32 fn_8011C0E0();
/* Cancels the OSAlarm embedded at +8 of the given object, then frees the object. */
void fn_8011C364(s32 obj) {
    if (obj != 0) {
        fn_8011C0E0();
        OSCancelAlarm((OSAlarm *)(obj + 8));
        fn_80120084(obj);
    }
}

/* Initialize a compressed-stream band/state: store the buffer, clear the
 * cursor/count, set the element bit-width and optional initial mask, and
 * compute the index bit-width from the band size (arg3>>3)*arg5 elements. */
void fn_8011C3A8(s32 buffer, void *state, s32 baseCount, u32 width, s32 elemBits, s32 scale, s32 useMask) {
    *(s32 *)((u8 *)state + 0x28) = 0x20 - __cntlzw((u16)(baseCount + ((width >> 3) * scale) - 1));
    *(s32 *)((u8 *)state + 0) = 0;
    *(s32 *)((u8 *)state + 4) = 0;
    *(s32 *)((u8 *)state + 8) = elemBits;
    if (useMask)
        *(s32 *)((u8 *)state + 0xC) = 1 << (elemBits - 1);
    else
        *(s32 *)((u8 *)state + 0xC) = 0;
    *(s32 *)((u8 *)state + 0x2C) = buffer;
}

/* Merge the two halves of a permutation chunk into the output.
 *
 * run0 and run1 hold the same number of bytes; the next output byte comes
 * from run1 while the low bit of mask is set and from run0 when it is clear,
 * the mask shifting along with every byte written.  Once one run is used up
 * the choice no longer matters, so the rest of the other run is copied
 * without reading the mask at all - which is why the number of mask bits the
 * merge needed is returned: fn_8011C4A0 only has to skip that many bits of
 * the stream it is decoding, not one per output byte. */
s32 fn_8011C400(u32 mask, u8 *dst, u8 *run0, u8 *run1, s32 count) {
    s32 left0;
    s32 left1;
    s32 bitsUsed;
    u32 bits;
    u8 *out;
    u8 *src0;
    u8 *src1;
    u8 from1;
    u8 from0;
    u8 rest0;
    u8 rest1;

    bits = mask;
    out = dst;
    src0 = run0;
    src1 = run1;
    left0 = count;
    left1 = left0;
    bitsUsed = 0;
merge:
    bitsUsed += 1;
    if (bits & 1) {
        from1 = *src1;
        left1 -= 1;
        src1 += 1;
        *out = from1;
        out += 1;
    } else {
        from0 = *src0;
        left0 -= 1;
        src0 += 1;
        *out = from0;
        out += 1;
    }
    bits = bits >> 1U;
    if ((left0 != 0) && (left1 != 0)) {
        goto merge;
    }
    if (left0 != 0) {
        do {
            rest0 = *src0;
            left0 -= 1;
            src0 += 1;
            *out = rest0;
            out += 1;
        } while (left0 != 0);
    } else if (left1 != 0) {
        do {
            rest1 = *src1;
            left1 -= 1;
            src1 += 1;
            *out = rest1;
            out += 1;
        } while (left1 != 0);
    }
    return bitsUsed;
}

#pragma push
#pragma scheduling on
/* Huffman decoder over a BitReader8011 stream. Reads a 4-bit selector code, writes the two
   table values lbl_80329DA8[code] / lbl_802F6990[code] to *arg1 / *arg2, then decodes a
   16-byte permutation into arg3 (using fn_8011C400 to merge run pairs). arg0 is the reader,
   whose next/value/count are updated on exit. */
void fn_8011C4A0(s32 arg0_raw, s32 arg1_raw, s32 arg2_raw, s32 arg3_raw) {
    u8 buffers[0x20];
    const u8 *var_r31;
    u32 var_r30;
    u32 var_r29;
    u32 var_r28;
    s32 temp_r0;
    s32 temp_r5_14;
    s32 temp_r5_15;
    s32 var_ctr;
    s32 var_ctr_2;
    u32 var_ctr_3;
    u32 var_r8;
    u8 *var_r3;
    s32 temp_r4_2;
    s32 temp_r4_3;
    u32 var_r0_6;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    u32 temp_r7;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r4;
    u32 temp_r5;
    u32 var_r0;
    u32 var_r7;
    u32 mask;
    u32 var_r8_inner;
    u32 temp_r9;

    void *arg0 = (void *)arg0_raw;
    s32 *arg1 = (s32 *)arg1_raw;
    s32 *arg2 = (s32 *)arg2_raw;
    u8 *arg3 = (u8 *)arg3_raw;

    var_r29 = ((BitReader8011 *)arg0)->count;
    var_r31 = (const u8 *)((BitReader8011 *)arg0)->next;
    var_r30 = ((BitReader8011 *)arg0)->value;
    if (var_r29 < 4U) {
        var_r0 = (*(u32 *)var_r31);
        temp_r7 = 4 - var_r29;
        var_r31 += 4;
        temp_r3 = var_r0 << var_r29;
        var_r29 += 0x1C;
        temp_r3_2 = var_r30 | temp_r3;
        var_r30 = var_r0 >> temp_r7;
        var_r8 = temp_r3_2 & 0xF;
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
            var_r29 = 0x1F;
            var_r31 += 4;
            var_r30 = var_r0 >> 1U;
        } else {
            var_r0 = var_r30;
            var_r30 = var_r30 >> 1U;
            var_r29 = var_r29 - 1;
        }
        if (!(var_r0 & 1)) {
            if (var_r29 < 2U) {
                temp_r4 = (*(u32 *)var_r31);
                var_r31 += 4;
                var_r28 = (var_r30 | (temp_r4 << var_r29)) & 3;
                var_r30 = temp_r4 >> (2 - var_r29);
                var_r29 = var_r29 + 0x1E;
            } else {
                var_r28 = var_r30 & 3;
                var_r30 = var_r30 >> 2U;
                var_r29 = var_r29 - 2;
            }
            if (var_r28 == 0) {
                var_r4 = 0;
                for (var_ctr = 0; var_ctr < 4; var_ctr++) {
                    if (var_r29 == 0) {
                        var_r0 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0 >> 1U;
                    } else {
                        var_r0 = var_r30;
                        var_r30 = var_r30 >> 1U;
                        var_r29 = var_r29 - 1;
                    }
                    if (var_r0 & 1) {
                        *(arg3 + var_r4) = var_r4 + 1;
                        (*(s8 *)((s8 *)((arg3 + var_r4)) + (1))) = var_r4;
                    } else {
                        *(arg3 + var_r4) = var_r4;
                        (*(s8 *)((s8 *)((arg3 + var_r4)) + (1))) = (s8) (var_r4 + 1);
                    }
                    temp_r4_2 = var_r4 + 2;
                    if (var_r29 == 0) {
                        var_r0 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0 >> 1U;
                    } else {
                        var_r0 = var_r30;
                        var_r30 = var_r30 >> 1U;
                        var_r29 = var_r29 - 1;
                    }
                    if (var_r0 & 1) {
                        *(arg3 + temp_r4_2) = temp_r4_2 + 1;
                        (*(s8 *)((s8 *)((arg3 + temp_r4_2)) + (1))) = temp_r4_2;
                    } else {
                        *(arg3 + temp_r4_2) = temp_r4_2;
                        (*(s8 *)((s8 *)((arg3 + temp_r4_2)) + (1))) = (s8) (temp_r4_2 + 1);
                    }
                    var_r4 = temp_r4_2 + 2;
                }
            } else {
                var_r3 = (u8 *)buffers;
                var_r4_2 = 0;
                for (var_ctr_2 = 0; var_ctr_2 < 4; var_ctr_2++) {
                    if (var_r29 == 0) {
                        var_r0 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0 >> 1U;
                    } else {
                        var_r0 = var_r30;
                        var_r30 = var_r30 >> 1U;
                        var_r29 = var_r29 - 1;
                    }
                    if (var_r0 & 1) {
                        (*(s8 *)((s8 *)(var_r3) + (0))) = var_r4_2 + 1;
                        (*(s8 *)((s8 *)(var_r3) + (1))) = var_r4_2;
                    } else {
                        (*(s8 *)((s8 *)(var_r3) + (0))) = var_r4_2;
                        (*(s8 *)((s8 *)(var_r3) + (1))) = (s8) (var_r4_2 + 1);
                    }
                    temp_r4_3 = var_r4_2 + 2;
                    if (var_r29 == 0) {
                        var_r0 = (*(u32 *)var_r31);
                        var_r29 = 0x1F;
                        var_r31 += 4;
                        var_r30 = var_r0 >> 1U;
                    } else {
                        var_r0 = var_r30;
                        var_r30 = var_r30 >> 1U;
                        var_r29 = var_r29 - 1;
                    }
                    if (var_r0 & 1) {
                        (*(s8 *)((s8 *)(var_r3) + (2))) = (s8) (temp_r4_3 + 1);
                        (*(s8 *)((s8 *)(var_r3) + (3))) = temp_r4_3;
                    } else {
                        (*(s8 *)((s8 *)(var_r3) + (2))) = temp_r4_3;
                        (*(s8 *)((s8 *)(var_r3) + (3))) = (s8) (temp_r4_3 + 1);
                    }
                    var_r3 += 4;
                    var_r4_2 = temp_r4_3 + 2;
                }
                if (var_r28 == 1U) {
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3), (u8 *)(buffers + 0), (u8 *)(buffers + 2), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3 + 4), (u8 *)(buffers + 4), (u8 *)(buffers + 6), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3 + 8), (u8 *)(buffers + 8), (u8 *)(buffers + 10), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3 + 0xC), (u8 *)(buffers + 12), (u8 *)(buffers + 14), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                } else {
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 16), (u8 *)(buffers + 0), (u8 *)(buffers + 2), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 20), (u8 *)(buffers + 4), (u8 *)(buffers + 6), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 24), (u8 *)(buffers + 8), (u8 *)(buffers + 10), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r29 < 3U) {
                        temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 7;
                    } else {
                        temp_r3 = var_r30 & 7;
                    }
                    temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 28), (u8 *)(buffers + 12), (u8 *)(buffers + 14), 2);
                    if (var_r29 < temp_r3) {
                        temp_r5 = (*(u32 *)var_r31);
                        var_r31 += 4;
                        var_r30 = temp_r5 >> (temp_r3 - var_r29);
                        var_r29 = (var_r29 + 0x20) - temp_r3;
                    } else {
                        var_r30 = var_r30 >> temp_r3;
                        var_r29 = var_r29 - temp_r3;
                    }
                    if (var_r28 == 2U) {
                        if (var_r29 < 7U) {
                            temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 0x7F;
                        } else {
                            temp_r3 = var_r30 & 0x7F;
                        }
                        temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3), (u8 *)(buffers + 16), (u8 *)(buffers + 20), 4);
                        if (var_r29 < temp_r3) {
                            temp_r5 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5 >> (temp_r3 - var_r29);
                            var_r29 = (var_r29 + 0x20) - temp_r3;
                        } else {
                            var_r30 = var_r30 >> temp_r3;
                            var_r29 = var_r29 - temp_r3;
                        }
                        if (var_r29 < 7U) {
                            temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 0x7F;
                        } else {
                            temp_r3 = var_r30 & 0x7F;
                        }
                        temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3 + 8), (u8 *)(buffers + 24), (u8 *)(buffers + 28), 4);
                        if (var_r29 < temp_r3) {
                            temp_r5 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5 >> (temp_r3 - var_r29);
                            var_r29 = (var_r29 + 0x20) - temp_r3;
                        } else {
                            var_r30 = var_r30 >> temp_r3;
                            var_r29 = var_r29 - temp_r3;
                        }
                    } else {
                        if (var_r29 < 7U) {
                            temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 0x7F;
                        } else {
                            temp_r3 = var_r30 & 0x7F;
                        }
                        temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 0), (u8 *)(buffers + 16), (u8 *)(buffers + 20), 4);
                        if (var_r29 < temp_r3) {
                            temp_r5 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5 >> (temp_r3 - var_r29);
                            var_r29 = (var_r29 + 0x20) - temp_r3;
                        } else {
                            var_r30 = var_r30 >> temp_r3;
                            var_r29 = var_r29 - temp_r3;
                        }
                        if (var_r29 < 7U) {
                            temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 0x7F;
                        } else {
                            temp_r3 = var_r30 & 0x7F;
                        }
                        temp_r3 = fn_8011C400(temp_r3, (u8 *)(buffers + 8), (u8 *)(buffers + 24), (u8 *)(buffers + 28), 4);
                        if (var_r29 < temp_r3) {
                            temp_r5 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5 >> (temp_r3 - var_r29);
                            var_r29 = (var_r29 + 0x20) - temp_r3;
                        } else {
                            var_r30 = var_r30 >> temp_r3;
                            var_r29 = var_r29 - temp_r3;
                        }
                        if (var_r29 < 0xFU) {
                            temp_r3 = (var_r30 | ((*(u32 *)var_r31) << var_r29)) & 0x7FFF;
                        } else {
                            temp_r3 = var_r30 & 0x7FFF;
                        }
                        temp_r3 = fn_8011C400(temp_r3, (u8 *)(arg3), (u8 *)(buffers + 0), (u8 *)(buffers + 8), 8);
                        if (var_r29 < temp_r3) {
                            temp_r5 = (*(u32 *)var_r31);
                            var_r31 += 4;
                            var_r30 = temp_r5 >> (temp_r3 - var_r29);
                            var_r29 = (var_r29 + 0x20) - temp_r3;
                        } else {
                            var_r30 = var_r30 >> temp_r3;
                            var_r29 = var_r29 - temp_r3;
                        }
                    }
                }
            }
        } else {
            if (var_r29 < 3U) {
                temp_r4 = (*(u32 *)var_r31);
                var_r31 += 4;
                var_r8_inner = (var_r30 | (temp_r4 << var_r29)) & 7;
                var_r30 = temp_r4 >> (3 - var_r29);
                var_r29 = var_r29 + 0x1D;
            } else {
                var_r8_inner = var_r30 & 7;
                var_r30 = var_r30 >> 3U;
                var_r29 = var_r29 - 3;
            }
            mask = 0xFFFF;
            for (var_ctr_3 = 0; var_ctr_3 <= var_r8_inner; var_ctr_3++) {
                if (var_r29 < 4U) {
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
                arg3[var_ctr_3] = var_r0_6;
                mask &= ~(1 << var_r0_6);
            }
            var_r3 = arg3 + var_r8_inner;
            var_r4_3 = 0;
            do {
                if (mask & 1) {
                    *++var_r3 = var_r4_3;
                }
                mask >>= 1;
                var_r4_3++;
            } while (mask != 0);
        }
    }
    ((BitReader8011 *)arg0)->next = (u32 *)var_r31;
    ((BitReader8011 *)arg0)->value = var_r30;
    ((BitReader8011 *)arg0)->count = (u32)var_r29;
}
void fn_8011CD78(void* table, void* bits) {
    /* Decode one pattern from the shared bitstream into this table: pattern pointer
     * at +0x24, extra bit count at +0x20, 16-byte permutation at +0x10. */
    fn_8011C4A0((s32)bits, (s32)((u8*)table + 0x24), (s32)((u8*)table + 0x20), (s32)((u8*)table + 0x10));
}

#pragma pop
/* Decodes 16 entries into workBuffer slices via fn_8011C4A0, decodes one final entry into objectBase fields, and clears the work-buffer flag at +0x180. */
void fn_8011CD90(s32 objectBase, s32 bitReader, s32 workBuffer) {
    s32 outputPtr = workBuffer;
    register s32 secondTablePtr = workBuffer + 0x100;
    s32 firstTablePtr = workBuffer + 0x140;
    u32 i;
    for (i = 0; i < 0x10; i++) {
        fn_8011C4A0(bitReader, firstTablePtr, secondTablePtr, outputPtr);
        outputPtr += 0x10;
        secondTablePtr += 4;
        firstTablePtr += 4;
    }
    fn_8011C4A0(bitReader, objectBase + 0x24, objectBase + 0x20, objectBase + 0x10);
    *(s32 *)(workBuffer + 0x180) = 0;
}

const u8 lbl_80561208[] = {0x04, 0x08, 0x0C, 0x20};
void fn_8011CE18(void *arg0, void *arg1) {
    u32 *bits;
    u32 value, bitCount, available, count, code, len, s, w;
    u32 indexBits;
    struct { u32 value; } maskStorage;
    u8 *dst;
    u32 fill;
    u8 *lookup;
    u8 *table;
    u32 sym;
    u8 run;
    u32 fw;
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
            dst = *(u8 **)((u8 *)arg0 + 0x2C);
            table = (u8 *)arg0 + 0x10;
            lookup = *(u8 **)((u8 *)arg0 + 0x24);
            indexBits = *(u32 *)((u8 *)arg0 + 0x20);
            fill = 0;
            maskStorage.value = 0xFFFFFFFFU >> (32 - indexBits);
            while (count != 0) {
                if (bitCount >= indexBits) {
                    code = value & maskStorage.value;
                    s = lookup[code];
                    len = s >> 4;
                    code = s & 15;
                    sym = table[code];
                    value >>= len;
                    bitCount -= len;
                } else {
                    u32 next = *bits;
                    code = (value | (next << bitCount)) & maskStorage.value;
                    s = lookup[code];
                    len = s >> 4;
                    code = s & 15;
                    sym = table[code];
                    if (bitCount >= len) { value >>= len; bitCount -= len; }
                    else { value = next >> (len - bitCount); bits++; bitCount = bitCount + 32 - len; }
                }
                if (sym >= 12) {
                    run = lbl_80561208[sym - 12];
                    count -= run;
                    fw = fill | (fill << 8);
                    fw |= fw << 16;
                    if ((u32)dst & 3) {
                        do {
                            *dst++ = fill;
                            run--;
                        } while (run != 0);
                    }
                    while (run >= 4) {
                        *(u32 *)dst = fw;
                        dst += 4;
                        run -= 4;
                    }
                    while (run != 0) {
                        *dst++ = fill;
                        run--;
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
 register u32 *ent;
 u32 *p;
 u32 bits, n, width, tree, rem, sign, mask, code;
 s32 out;
 u32 w2;
 u8 *dst, *table, *lut;
 u32 v, c;
 if((*(u32*)((char *)(arg0) + 0))!=(*(u32*)((char *)(arg0) + 4))) return;
 n=(*(u32*)((char *)(arg1) + 8)); width=(*(u32*)((char *)(arg0) + 0x28)); p=(*(u32**)((char *)(arg1) + 4)); bits=(*(u32*)((char *)(arg1) + 0));
 if(n<width){u32 x=*p++; out=(bits|(x<<n))&(-1U>>(32-width)); bits=x>>(width-n); n=n+32-width;} else {out=bits&(-1U>>(32-width)); bits>>=width; n-=width;}
 if(out){
  dst=(*(u8**)((char *)(arg0) + 0x2C)); (*(u8**)((char *)(arg0) + 0))=dst; (*(u8**)((char *)(arg0) + 4))=dst+out;
  w2=(*(u32*)((char *)(arg0) + 0x20)); table=(*(u8**)((char *)(arg0) + 0x24)); lut=(u8*)arg0+0x10;
  tree=(*(u32*)((char *)(arg2) + 0x180));
  if(n==0){sign=*p++; bits=sign>>1; n=31;} else {sign=bits; bits>>=1; n--;}
  if(sign&1) out=-20-out;
  mask=-1U>>(32-w2);
  do {
   u32 w;
   ent=(u32*)((u8*)arg2+tree*4);
   w=ent[0x40];
   out--;
   if(n>=w){
    code=((u8*)ent[0x50])[bits&(-1U>>(32-w))];
    tree=((u8 (*)[16])arg2)[tree][code&15]; rem=code>>4; bits>>=rem; n-=rem;
   } else {
    u32 x=*p;
    code=((u8*)ent[0x50])[(bits|(x<<n))&(-1U>>(32-w))];
    tree=((u8 (*)[16])arg2)[tree][code&15]; rem=code>>4;
    if(n>=rem){bits>>=rem;n-=rem;} else {p++; bits=x>>(rem-n); n=n+32-rem;}
   }
   if(n>=w2){
    c=table[bits&mask]; v=lut[c&15]; rem=c>>4; bits>>=rem; n-=rem;
   } else {
    u32 x=*p;
    c=table[(bits|(x<<n))&mask]; v=lut[c&15]; rem=c>>4;
    if(n>=rem){bits>>=rem;n-=rem;} else {p++; bits=x>>(rem-n); n=n+32-rem;}
   }
   c=v|(tree<<4); v=c&127; if(c&128)v=(u8)(-v); *dst++=v+128;
  } while(out>0);
  if(out < -22) memset((*(u8**)((char *)(arg0) + 0x2C)),*(u8*)(*(u8**)((char *)(arg0) + 0x2C)),-(out+21));
  (*(u32*)((char *)(arg2) + 0x180))=tree;
 } else {dst=(*(u8**)((char *)(arg0) + 0x2C));(*(u8**)((char *)(arg0) + 4))=dst;(*(u8**)((char *)(arg0) + 0))=dst+4;}
 (*(u32**)((char *)(arg1) + 4))=p;(*(u32*)((char *)(arg1) + 0))=bits;(*(u32*)((char *)(arg1) + 8))=n;
}

#pragma opt_propagation off
void fn_8011D378(void *arg0, void *arg1, void *arg2)
{
  u32 *src;
  u32 remain;
  u32 index;
  u32 value;
  u32 node;
  u32 bit;
  u32 mask;
  s32 count;
  u32 width;
  u8 *out;
  u8 *lookup;
  u8 *table;
  if ((*((u32 *) arg0)) != (*((u32 *) (((u8 *) arg0) + 4))))
  {
    return;
  }
  remain = *((u32 *) (((u8 *) arg1) + 8));
  index = *((u32 *) (((u8 *) arg0) + 0x28));
  src = *((u32 **) (((u8 *) arg1) + 4));
  value = *((u32 *) arg1);
  if (remain < index)
  {
    u32 next = *(src++);
    count = (value | (next << remain)) & (0xffffffffU >> (32 - index));
    value = next >> (index - remain);
    remain = (remain + 32) - index;
  }
  else
  {
    count = value & (0xffffffffU >> (32 - index));
    value >>= index;
    remain -= index;
  }
  if (count != 0)
  {
    out = *((u8 **) (((u8 *) arg0) + 0x2c));
    width = *((u32 *) (((u8 *) arg0) + 0x20));
    table = ((u8 *) arg0) + 0x10;
    lookup = *((u8 **) (((u8 *) arg0) + 0x24));
    *((u8 **) arg0) = out;
    *((u8 **) (((u8 *) arg0) + 4)) = out + count;
    node = *((u32 *) (((u8 *) arg2) + 0x180));
    if (remain == 0)
    {
      bit = *(src++);
      value = bit >> 1;
      remain = 31;
    }
    else
    {
      bit = value;
      value >>= 1;
      remain--;
    }
    if (bit & 1)
    {
      count = (-20) - count;
    }
    mask = 0xffffffffU >> (32 - width);
    do
    {
      u32 n = *((u32 *) ((((u8 *) arg2) + (node * 4)) + 0x100));
      u32 tmp;
      count--;
      if (remain >= n)
      {
        u32 entry = (*((u8 **) ((((u8 *) arg2) + (node * 4)) + 0x140)))[value & (0xffffffffU >> (32 - n))];
        node = *((((u8 *) arg2) + (node * 16)) + (entry & 15));
        entry >>= 4;
        value >>= entry;
        remain -= entry;
      }
      else
      {
        u32 next = *src;
        u32 entry = (*((u8 **) ((((u8 *) arg2) + (node * 4)) + 0x140)))[(value | (next << remain)) & (0xffffffffU >> (32 - n))];
        node = *((((u8 *) arg2) + (node * 16)) + (entry & 15));
        entry >>= 4;
        if (remain >= entry)
        {
          value >>= entry;
          remain -= entry;
        }
        else
        {
          value = next >> (entry - remain);
          src++;
          remain = (remain + 32) - entry;
        }
      }
      if (remain >= width)
      {
        u32 entry = lookup[value & mask];
        tmp = table[entry & 15];
        entry >>= 4;
        value >>= entry;
        remain -= entry;
      }
      else
      {
        u32 next = *src;
        u32 entry = lookup[(value | (next << remain)) & mask];
        tmp = table[entry & 15];
        entry >>= 4;
        if (remain >= entry)
        {
          value >>= entry;
          remain -= entry;
        }
        else
        {
          value = next >> (entry - remain);
          src++;
          remain = (remain + 32) - entry;
        }
      }
      *(out++) = tmp | (node << 4);
    }
    while (count > 0);
    if (count < (-22))
    {
      memset(*((u8 **) (((u8 *) arg0) + 0x2c)), *(*((u8 **) (((u8 *) arg0) + 0x2c))), -(count + 21));
    }
    *((u32 *) (((u8 *) arg2) + 0x180)) = node;
  }
  else
  {
    out = *((u8 **) (((u8 *) arg0) + 0x2c));
    *((u8 **) (((u8 *) arg0) + 4)) = out;
    *((u8 **) arg0) = out + 4;
  }
  *((u32 **) (((u8 *) arg1) + 4)) = src;
  *((u32 *) arg1) = value;
  *((u32 *) (((u8 *) arg1) + 8)) = remain;
}
#pragma opt_propagation reset
/* Decodes one block of a band of the compressed stream fn_8011C3A8 sets up, the
 * variant whose values come out of a Huffman lookup table.  Nothing is done
 * while the block of the previous call is still published ([start, end)).  The
 * block opens with its value count (countBits wide); a count of zero only marks
 * the band as empty.  The bit behind it picks the coding: cleared, count values
 * are decoded one by one through lookup, whose entries hold the value in their
 * low nibble and the number of bits they cost in their high one; set, the 4-bit
 * value behind it is repeated count times over the block. */
void fn_8011D5F0(void* arg0, BitReader8011 *reader) {
    /* One band of the stream; see the BandState8011 layout above fn_8011DC5C. */
    struct Band {
        u8 *start;      /* 0x00 first value of the published block */
        u8 *end;        /* 0x04 one past its last value */
        u32 valueBits;  /* 0x08 */
        u32 signMask;   /* 0x0C */
        u8 symbol[16];  /* 0x10 value of each 4-bit symbol */
        u32 indexBits;  /* 0x20 bits of a lookup index */
        u8 *lookup;     /* 0x24 index -> coded entry */
        u32 countBits;  /* 0x28 bits of a block's value count */
        u8 *output;     /* 0x2C where the next block is decoded to */
    };
    struct Band *band = (struct Band *)arg0;
    u32 *in;
    u32 value;
    u32 bitCount;
    u32 countBits;
    u32 count;
    if (band->start == band->end) {
        bitCount = reader->count;
        countBits = band->countBits;
        in = reader->next;
        value = reader->value;
        /* How many values this block holds. */
        if (bitCount < countBits) {
            u32 next = *in;
            count = (0xFFFFFFFFU >> (0x20 - countBits)) & (value | (next << bitCount));
            value = next >> (countBits - bitCount);
            bitCount = bitCount + 0x20 - countBits;
            in++;
        } else {
            bitCount = bitCount - countBits;
            count = value & (0xFFFFFFFFU >> (0x20 - countBits));
            value = value >> countBits;
        }
        if (count != 0) {
            u32 runFlag;
            band->start = band->output;
            band->end = band->output + count;
            /* The coding bit, refilling the buffer when it ran dry. */
            if (bitCount == 0) {
                runFlag = *in;
                bitCount = 0x1F;
                in++;
                value = runFlag >> 1;
            } else {
                runFlag = value;
                value = value >> 1;
                bitCount--;
            }
            if ((runFlag & 1) == 0) {
                struct { u32 value; } maskStorage;
                u32 indexBits = band->indexBits;
                u8 *out = band->output;
                u8 *lookup = band->lookup;
                u8 *symbol = band->symbol;
                maskStorage.value = 0xFFFFFFFFU >> (0x20 - indexBits);
                do {
                    u32 entry;
                    count--;
                    if (bitCount >= indexBits) {
                        entry = lookup[value & maskStorage.value];
                        *out = symbol[entry & 0xF];
                        entry >>= 4;
                        out++;
                        value = value >> entry;
                        bitCount -= entry;
                    } else {
                        u32 next = *in;
                        entry = lookup[maskStorage.value & (value | (next << bitCount))];
                        *out = symbol[entry & 0xF];
                        entry >>= 4;
                        out++;
                        if (bitCount >= entry) {
                            value = value >> entry;
                            bitCount -= entry;
                        } else {
                            value = next >> (entry - bitCount);
                            in++;
                            bitCount = bitCount + 0x20 - entry;
                        }
                    }
                } while (count != 0);
            } else {
                u32 sample;
                /* A 4-bit value, repeated over the whole block. */
                if (bitCount < 4) {
                    u32 next = *in;
                    in++;
                    sample = (value | (next << bitCount)) & 0xF;
                    value = next >> (4 - bitCount);
                    bitCount += 0x1C;
                } else {
                    sample = value & 0xF;
                    value = value >> 4;
                    bitCount -= 4;
                }
                memset(band->output, sample, count);
            }
        } else {
            u8 *out = band->output;
            band->end = out;
            band->start = out + 4;
        }
        reader->next = in;
        reader->value = value;
        reader->count = bitCount;
    }
}

/* Decodes one block of a band of the compressed stream from the bit reader.  As
 * in the sibling band decoders, nothing is done while the previous block is still
 * published ([start, end)).  The block opens with its pair count (countBits wide);
 * a count of zero only marks the band as empty.  Every value is then decoded from
 * TWO back-to-back Huffman codes: each code indexes the band's lookup table, whose
 * entry's low nibble picks a slot of its 16-slot symbol table and whose high nibble
 * is the code width; the two 4-bit results are packed into one byte (first in the
 * low nibble, second in the high). */
void fn_8011D7F8(void *arg0, void *arg1)
{
  u32 mask;
  u32 bits;
  u32 *in;
  u32 sh;
  u32 cnt;
  u32 width;
  s8 *out;
  u32 idx;
  u32 lo;
  u32 e;
  u32 sym;
  u32 e1;
  void *tab;
  void *ntab;
  u32 next;
  u32 next2;
  if ((*((s8 **) (((u8 *) arg0) + 0))) == (*((s8 **) (((u8 *) arg0) + 4))))
  {
    cnt = *((u32 *) (((u8 *) arg1) + 8));
    sh = *((u32 *) (((u8 *) arg0) + 0x28));
    in = *((u32 **) (((u8 *) arg1) + 4));
    bits = *((u32 *) (((u8 *) arg1) + 0));
    if (cnt < sh)
    {
      u32 first = *in;
      mask = ((-1U) >> (0x20 - sh)) & (bits | (first << cnt));
      in++;
      bits = first >> (sh - cnt);
      cnt = (cnt + 0x20) - sh;
    }
    else
    {
      cnt = cnt - sh;
      mask = bits & ((-1U) >> (0x20 - sh));
      bits = bits >> sh;
    }
    if (mask != 0)
    {
      out = *((s8 **) (((u8 *) arg0) + 0x2C));
      *((s8 **) (((u8 *) arg0) + 0)) = out;
      *((s8 **) (((u8 *) arg0) + 4)) = (s8 *) (out + mask);
      tab = *((void **) (((u8 *) arg0) + 0x24));
      ntab = ((u8 *) arg0) + 0x10;
      width = *((u32 *) (((u8 *) arg0) + 0x20));
      sh = (-1U) >> (0x20 - width);
      do
      {
        mask -= 1;
        if (cnt >= width)
        {
          e1 = *((u8 *) (((u8 *) tab) + (bits & sh)));
          idx = e1 & 0xF;
          e1 >>= 4U;
          lo = *((u8 *) (((u8 *) ntab) + idx));
          bits = bits >> e1;
          cnt = cnt - e1;
        }
        else
        {
          next = *in;
          e = *((u8 *) (((u8 *) tab) + (sh & (bits | (next << cnt)))));
          idx = e & 0xF;
          e >>= 4U;
          lo = *((u8 *) (((u8 *) ntab) + idx));
          if (cnt >= e)
          {
            bits = bits >> e;
            cnt = cnt - e;
          }
          else
          {
            bits = next >> (e - cnt);
            in++;
            cnt = (cnt + 0x20) - e;
          }
        }
        if (cnt >= width)
        {
          e = *((u8 *) (((u8 *) tab) + (bits & sh)));
          idx = e & 0xF;
          e >>= 4U;
          sym = *((u8 *) (((u8 *) ntab) + idx));
          bits = bits >> e;
          cnt = cnt - e;
        }
        else
        {
          next2 = *in;
          e = *((u8 *) (((u8 *) tab) + (sh & (bits | (next2 << cnt)))));
          idx = e & 0xF;
          e >>= 4U;
          sym = *((u8 *) (((u8 *) ntab) + idx));
          if (cnt >= e)
          {
            bits = bits >> e;
            cnt = cnt - e;
          }
          else
          {
            bits = next2 >> (e - cnt);
            in++;
            cnt = (cnt + 0x20) - e;
          }
        }
        *out = lo | (sym * 0x10);
        out += 1;
      }
      while (mask != 0);
    }
    else
    {
      out = *((s8 **) (((u8 *) arg0) + 0x2C));
      *((s8 **) (((u8 *) arg0) + 4)) = out;
      *((s8 **) (((u8 *) arg0) + 0)) = out + 4;
    }
    *((u32 **) (((u8 *) arg1) + 4)) = in;
    *((u32 *) (((u8 *) arg1) + 0)) = bits;
    *((u32 *) (((u8 *) arg1) + 8)) = cnt;
  }
}

/* Decodes one block of signed 8-bit values of a band from the bit stream.  As
 * in the other band decoders, nothing is done while the block of the previous
 * call is still published ([start, end)).  The block opens with its value count
 * (countBits wide); a count of zero only marks the band as empty.  One bit then
 * says how the values are stored: cleared, each value is a lookup-table index
 * whose low nibble selects the band's symbol table and whose high nibble is the
 * index' width, and every non-zero symbol is followed by its sign bit; set, a
 * single 4-bit value (again signed) is repeated over the whole block. */
void fn_8011D9E4(void *arg0, BitReader8011 *reader) {
    /* One band of the stream; see the BandState8011 layout above fn_8011DC5C. */
    struct Band {
        u8 *start;      /* 0x00 first value of the published block */
        u8 *end;        /* 0x04 one past its last value */
        u32 valueBits;  /* 0x08 */
        u32 signMask;   /* 0x0C */
        u8 symbol[16];  /* 0x10 magnitude of each 4-bit symbol */
        u32 indexBits;  /* 0x20 bits of a lookup index */
        u8 *lookup;     /* 0x24 index -> coded entry */
        u32 countBits;  /* 0x28 bits of a block's value count */
        u8 *output;     /* 0x2C where the next block is decoded to */
    };
    struct Band *band = (struct Band *)arg0;
    u32 *in;
    u32 value, bitCount, fieldBits, count, code, entry = 0, bit;
    u8 *lookup, *table, *dst;
    s32 symbol;
    if (band->start != band->end) return;
    bitCount = reader->count;
    fieldBits = band->countBits;
    in = reader->next;
    value = reader->value;
    /* How many values this block holds. */
    if (bitCount < fieldBits) {
        u32 next = *in++;
        count = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - fieldBits));
        value = next >> (fieldBits - bitCount);
        bitCount = bitCount + 32 - fieldBits;
    } else {
        count = value & (0xFFFFFFFFU >> (32 - fieldBits));
        value >>= fieldBits;
        bitCount -= fieldBits;
    }
    if (count != 0) {
        dst = band->output;
        band->start = dst;
        band->end = dst + count;
        /* The coding bit, refilling the buffer when it ran dry. */
        if (bitCount == 0) { bit = *in++; value = bit >> 1; bitCount = 31; }
        else { bit = value; bitCount--; value >>= 1; }
        if ((bit & 1) == 0) {
            /* One value at a time, straight out of the band's symbol table. */
            dst = *(u8 * volatile *)&band->output;
            table = band->symbol;
            lookup = band->lookup;
            fieldBits = band->indexBits;
            do {
                count--;
                if (bitCount >= fieldBits) {
                    code = value & (0xFFFFFFFFU >> (32 - fieldBits)); code = lookup[code]; entry = code >> 4; symbol = code;
                    symbol = table[symbol & 15]; value >>= entry; bitCount -= entry;
                } else {
                    u32 next = *in;
                    code = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - fieldBits));
                    entry = lookup[code];
                    symbol = table[entry & 15];
                    entry >>= 4;
                    if (bitCount >= entry) { value >>= entry; bitCount -= entry; }
                    else { value = next >> (entry - bitCount); in++; bitCount = bitCount + 32 - entry; }
                }
                /* A non-zero magnitude is followed by its sign bit. */
                if (symbol != 0) {
                    if (bitCount == 0) { bit = *in++; value = bit >> 1; bitCount = 31; }
                    else { bit = value; bitCount--; value >>= 1; }
                    if (bit & 1) symbol = -symbol;
                }
                *dst++ = symbol;
            } while (count != 0);
        } else {
            /* A 4-bit value, signed, repeated over the whole block. */
            if (bitCount < 4) {
                u32 next = *in++;
                code = (value | (next << bitCount)) & 15;
                value = next >> (4 - bitCount); bitCount += 28;
            } else { code = value & 15; value >>= 4; bitCount -= 4; }
            if (code != 0) {
                if (bitCount == 0) { bit = *in++; value = bit >> 1; bitCount = 31; }
                else { bit = value; bitCount--; value >>= 1; }
                if (bit & 1) code = -code;
            }
            memset(band->output, code, count);
        }
    } else {
        /* An empty block: publish nothing, but leave the band out of step so
         * the next call knows there is nothing to keep. */
        dst = band->output;
        band->end = dst; band->start = dst + 4;
    }
    reader->next = in;
    reader->value = value; reader->count = bitCount;
}

/* One band of the compressed stream that fn_8011C3A8 sets up (see the table of
   bands fn_8011E0B4 builds): [start, end) is the range of samples the last call
   published, output is where the next block is decoded to, and the tables at
   0x10..0x27 turn coded symbols back into values.  0x30 bytes. */
typedef struct {
    /* 0x00 */ s16 *start;         /* first sample of the decoded block */
             s16 *end;             /* one past its last sample */
             u32 sampleBits;       /* 0x08: bits of one sample */
             u32 signMask;         /* 0x0C: 1 << (sampleBits - 1) when the samples carry a sign bit, else 0 */
    /* 0x10 */ u8 symbol[16];      /* value of each 4-bit symbol */
             u32 indexBits;        /* 0x20: bits of a table index */
             u8 *lookup;           /* 0x24: index -> symbol table entry */
             u32 countBits;        /* 0x28: bits of a block's sample count */
    /* 0x2C */ s16 *output;        /* where the next block is decoded to */
} BandState8011;

/* Decodes one block of 16-bit samples of a band from the bit stream.  Nothing is
   done while the block of the previous call is still published ([start, end)).
   The block opens with its sample count (countBits wide); a count of zero only
   marks the band as empty.  The first sample is absolute: sampleBits bits, or
   one bit less plus a sign bit for the signed bands.  The rest comes in groups
   of up to eight samples, each group preceded by its 4-bit delta width: deltas
   of that many bits (again with a sign bit when non-zero) accumulate into the
   previous sample, while a width of zero repeats the current sample for the
   whole group. */
void fn_8011DC5C(BandState8011 *band, BitReader8011 *reader) {
    s32 group;
    u32 count;
    u32 *in;
    u32 value;
    u32 bitCount;
    s16 *out;
    s32 val;
    u32 width, mask, code, deltaBits, sign, signOfCode;
    s32 run;

    if (band->start != band->end) return;
    bitCount = reader->count;
    width = band->countBits;
    in = reader->next;
    value = reader->value;
    /* How many samples this block holds. */
    if (bitCount < width) {
        u32 next = *in++;
        count = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
        value = next >> (width - bitCount);
        bitCount = bitCount + 32 - width;
    } else {
        count = value & (0xFFFFFFFFU >> (32 - width));
        value >>= width;
        bitCount -= width;
    }
    if (count != 0) {
        out = band->output;
        /* The first sample, absolute; signed bands store its magnitude one bit
           narrower and follow it with the sign. */
        if (band->signMask != 0) {
            width = band->sampleBits - 1;
            if (bitCount < width) {
                u32 next = *in++;
                val = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
                value = next >> (width - bitCount);
                bitCount = bitCount + 32 - width;
            } else {
                val = value & (0xFFFFFFFFU >> (32 - width));
                value >>= width;
                bitCount -= width;
            }
            if (val != 0) {
                if (bitCount == 0) { sign = *in++; bitCount = 31; value = sign >> 1; }
                else { sign = value; value >>= 1; bitCount--; }
                if (sign & 1) val = -val;
            }
        } else {
            width = band->sampleBits;
            if (bitCount < width) {
                u32 next = *in++;
                val = (value | (next << bitCount)) & (0xFFFFFFFFU >> (32 - width));
                value = next >> (width - bitCount);
                bitCount = bitCount + 32 - width;
            } else {
                val = value & (0xFFFFFFFFU >> (32 - width));
                value >>= width;
                bitCount -= width;
            }
        }
        *out = val;
        band->start = band->output;
        band->end = band->output + count;
        count--;
        out++;
        /* The remaining samples, in groups of at most eight. */
        while (count != 0) {
            group = 8;
            if (count <= 8) group = (s32)count;
            /* Bits per delta in this group; zero means "repeat this sample". */
            if (bitCount < 4) {
                u32 next = *in++;
                deltaBits = (value | (next << bitCount)) & 15;
                value = next >> (4 - bitCount);
                bitCount = bitCount + 32 - 4;
            } else {
                deltaBits = value & 15;
                value >>= 4;
                bitCount -= 4;
            }
            if (deltaBits != 0) {
                mask = 0xFFFFFFFFU >> (32 - deltaBits);
                run = group;
                while (run != 0) {
                    run--;
                    if (bitCount < deltaBits) {
                        u32 next = *in++;
                        code = (value | (next << bitCount)) & mask;
                        value = next >> (deltaBits - bitCount);
                        bitCount = bitCount + 32 - deltaBits;
                    } else {
                        code = value & mask;
                        value >>= deltaBits;
                        bitCount -= deltaBits;
                    }
                    /* A non-zero delta carries its sign in the next bit. */
                    if (code != 0) {
                        if (bitCount == 0) { u32 w = *in++; bitCount = 31; value = w >> 1; signOfCode = w; }
                        else { signOfCode = value; value >>= 1; bitCount--; }
                        if (signOfCode & 1) code = -code;
                    }
                    val += code;
                    *out = val;
                    out++;
                }
            } else {
                /* n samples of the unchanged value. */
                fn_80116CC4((s32 *)out, (u16)val, (group + group));
                out = (s16 *)((u8 *)out + (group << 1));
            }
            count -= group;
        }
    } else {
        /* Empty block: nothing for the consumer to take. */
        out = band->output;
        band->end = out;
        band->start = out + 2;
    }
    reader->next = in;
    reader->value = value;
    reader->count = bitCount;
}

s32 fn_8011DF68(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    /* Compute an aligned byte size from width/count/bit-depth-like parameters. */
    u32 var_r5 = arg2;
    u32 temp;
    if (var_r5 <= 8U) var_r5 = 8;
    else if (var_r5 < 0x10U) var_r5 = 0x10;
    temp = var_r5 * arg3;
    return (((u32)(arg0 * var_r5) >> 3) + ((temp * (arg1 >> 3)) >> 3) + 3) & 0xFFFFFFFC;
}

void fn_8011DFAC(void* output, u32 count) {
    /* Compute and store nine size values derived from count using fn_8011DF68. */
    s32* values = (s32*)output;
    values[0] = fn_8011DF68(0x200, count, 4, 1);
    values[1] = fn_8011DF68(0x200, count >> 1, 4, 1);
    values[2] = fn_8011DF68(0x200, count, 8, 0x40);
    values[3] = fn_8011DF68(0x200, count, 8, 8);
    values[4] = fn_8011DF68(0x200, count, 5, 1);
    values[5] = fn_8011DF68(0x200, count, 5, 1);
    values[6] = fn_8011DF68(0x200, count, 0xB, 1);
    values[7] = fn_8011DF68(0x200, count, 0xB, 1);
    values[8] = fn_8011DF68(0x200, count, 4, 0x30);
}

extern void fn_8011CD78(void *, void *);
extern void fn_8011D0E8(void *, void *, void *);
extern void fn_8011D378(void *, void *, void *);
s32 *fn_8011E0B4(s32 arg0, s32 arg1, s32 width, s32 height, s32 format, s32 *buffers, s32 offset, s32 flags) {
    u8 work[0x450];
    u8 *base = work + 8;
    void (*decode)(void *, void *, void *);
    s32 rowBytes = (format << 3) - width;
    s32 zero = 0;
    ((s32 *)base)[-2] = width;
    ((s32 *)base)[-1] = height;
    *(s32 *)(base + 4) = offset;
    *(s32 *)(base + 0) = zero;
    *(s32 *)(base + 8) = zero;
    *(s32 *)(base + 0x414) = rowBytes;
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
typedef struct { u32 old; u32 cur; } Idx8011FC2C;
/* Decode the next block of every band group of one frame of the compressed
   sample stream.  `bands` is the decoder's band table: a header holding the
   width and height of the two sample groups (+4/+8 and +0xC/+0x10) and the
   index of the set being filled (+0x14), followed by two 0x30-byte sets.  Each
   set holds, per group, the block that group was last decoded to and that
   block's format: +0x1C/+0x20 for the group written to `blocks`, +0x28/+0x2C
   and +0x34/+0x38 for the two groups of the second size and +0x40/+0x44 for the
   optional group at the head of `blocks`.  The set moves to the other one as
   soon as that one has a block of its own, so fn_8011E0B4 always sees the
   current and the previous value of a group.
   Every block is prefixed by its size in bytes, which is how `block` steps from
   one group to the next; `streams` is the array of nine bit streams a group is
   decoded from.  0x8000 in `flags` keeps the main group's block published
   instead of moving on to the next one, 0x20000 skips the two groups of the
   second size and 0x100000 set in both `flags` and `flags2` adds the optional
   group.  Returns what the last group decoded reported: the main group's byte
   count in words when the two extra groups are skipped. */
u32 fn_8011FC2C(void *bands, s32 arg1, s32 arg2, s32 *blocks, s32 arg4, s32 streams, s32 flags, s32 flags2) {
    extern s32 *fn_8011E0B4();
    u32 result;
    Idx8011FC2C idx;
    u32 next;
    s32 *block;
    s32 *out;
    u32 (*ents)[12] = (u32 (*)[12])bands;
    idx.old = ents[0][5];
    next = idx.old ^ 1;
    if ((s32)ents[next][7] != 0) {
        ents[0][5] = next;
    }
    idx.cur = ents[0][5];
    result = 0;
    block = blocks;
    if ((flags2 & 0x100000) != 0) {
        if ((flags & 0x100000) != 0) {
            fn_8011E0B4((s32)ents[idx.cur][16], (s32)ents[idx.old][16],
                        (s32)ents[0][1], (s32)ents[0][2],
                        (s32)ents[idx.old][17],
                        blocks + 1, arg4, arg1, arg2, 1, streams, flags, &result);
        }
        block = (s32 *)((u8 *)block + *block);
    }
    result = 0;
    if ((flags & 0x8000) == 0) block++;
    out = fn_8011E0B4((s32)ents[idx.cur][7], (s32)ents[idx.old][7],
                      (s32)ents[0][1], (s32)ents[0][2],
                      (s32)ents[idx.old][8],
                      block, arg4, arg1, arg2, 1, streams, flags, &result);
    if ((flags & 0x8000) == 0) {
        out = (s32 *)((u8 *)block + *(volatile s32 *)((u8 *)block - 4) - 4);
    }
    result >>= 2;
    if ((flags & 0x20000) == 0) {
        out = fn_8011E0B4((s32)ents[idx.cur][10], (s32)ents[idx.old][10],
                          (s32)ents[0][3], (s32)ents[0][4],
                          (s32)ents[idx.old][11],
                          out, arg4, arg1, arg2, 2, streams, flags, &result);
        result = 0;
        fn_8011E0B4((s32)ents[idx.cur][13], (s32)ents[idx.old][13],
                    (s32)ents[0][3], (s32)ents[0][4],
                    (s32)ents[idx.old][14],
                    out, arg4, arg1, arg2, 2, streams, flags, &result);
    }
    return result;
}

void fn_8011FE20(u32 **arg0, u32 arg1) {
    void *newBuffer;
    void *newSizes;
    u32 base;
    u32 rounded;
    u32 extra;
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
    rounded = arg1 + 0x1F;
    extra = (((base >> 5) & 0x1F) + 0x21 - ((rounded >> 5) & 0x1F)) & 0x1F;
    arg1 = rounded & ~0x1F;
    arg1 += extra << 5;
    lbl_8055DEF0 = (void *)(base + arg1);
    lbl_8055994C[lbl_8055DEF4] = arg1;
    lbl_80559948[lbl_8055DEF4++] = arg0;
}

extern void *lbl_8055DEF0;
extern void *lbl_8055DEF8;
extern void *lbl_8055DEFC;
extern u32 lbl_8055DEF4;
extern void **lbl_80559948;
extern u32 *lbl_8055994C;
extern void *fn_8011FFC4(s32);
void* fn_8011FF24(void) {
    /* Return the current pending allocation base (global lbl_8055DEF0): the
     * running byte offset into the next 32-byte-aligned sub-allocation block. */
    return lbl_8055DEF0;
}

void *fn_8011FF2C(s32 baseSize) {
    /* Allocate a 32-byte-aligned block and assign sub-allocations into registered pointers. */
    u32 alignedSize = (baseSize + 0x1F) & ~0x1F;
    void *block = fn_8011FFC4((s32)lbl_8055DEF0 + alignedSize);
    lbl_8055DEF0 = 0;
    if (block != NULL) {
        u32 i;
        u8 *ptr = (u8*)block + alignedSize;
        for (i = 0; i < lbl_8055DEF4; i++) {
            *(void**)lbl_80559948[i] = ptr;
            ptr += lbl_8055994C[i];
        }
    }
    lbl_8055DEF4 = 0;
    return block;
}

/* Install the custom allocator and free hooks used by the 32-byte-aligned
   AXFX allocator (fn_8011FFC4) and deallocator (fn_80120084). */
void AXFXSetHooks_8011FFB8(void *allocHook, void *freeHook) {
    lbl_8055DEF8 = allocHook;
    lbl_8055DEFC = freeHook;
}

extern void *malloc(u32);
extern void free(void *);
void *fn_8011FFC4(s32 arg0) {
    s32 base;
    u8 offset;
    u32 mode;
    s32 result;

    /* Allocate arg0+0x40 bytes via custom allocator hook (mode 3) or malloc (mode 0),
       return a 32-byte-aligned pointer with metadata stored before it. */
    if (arg0 == 0 || (u32)(arg0 + 0x10000) == 0xFFFF) return 0;
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

/* Free hook installed by AXFXSetHooks_8011FFB8 alongside the alloc hook
   lbl_8055DEF8; fn_8011FFC4 records it in the header of every block it takes
   from that hook so it can still be released after the hook is replaced. */
typedef void (*FreeHook)(void *block);

/* Release a block handed out by the 32-byte aligned allocator fn_8011FFC4.
 * That allocator leaves a small header just below the pointer it returns:
 *   -1 : bytes it added to the raw block to reach the alignment
 *   -2 : allocation mode -- 3 = custom allocator hook lbl_8055DEF8, 0 = malloc
 *   -8 : the free hook (lbl_8055DEFC) that was installed when the block was
 *        allocated, stored there only for mode 3
 * Subtracting the first of those gets back to the raw block, which goes back to
 * whichever allocator owns it. */
void fn_80120084(void *block) {
    u8 *ptr = block;
    if (ptr == 0) return;
    if (ptr[-2] == 3) {
        ((FreeHook)*(void **)(ptr - 8))(ptr - ptr[-1]);
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
void fn_801200BC(s32 length, s32 direction, f32 *data, s32 table, s32 work) {
    /* Dispatch FFT-like forward/inverse passes: ensure twiddle/work sizes, run stage routines by length/direction, and apply final 2-point combine. */
    s32 size1;
    s32 size2;
    f32 temp_f1;
    f32 temp_f2;

    size1 = *(s32 *)table;
    if (length > size1 * 4) {
        size1 = length >> 2;
        fn_80120834(size1, (s32 *)table, (f32 *)work);
    }
    size2 = *(s32 *)(table + 4);
    if (length > size2 * 4) {
        size2 = length >> 2;
        fn_80120B6C(size2, (s32 *)table, (f32 *)((u8 *)work + size1 * 4));
    }
    if (direction >= 0) {
        if (length > 4) {
            fn_80120CA4(length, data, table + 8, size1, (void *)work);
            fn_801250CC(length, (s32)data, size2, (s32)((u8 *)work + size1 * 4));
        } else if (length == 4) {
            fn_80120CA4(length, data, table + 8, size1, (void *)work);
        }
        {
            f32 second;
            f32 first;
            f32 difference;
            first = data[0];
            second = data[1];
            difference = first - second;
            data[1] = difference;
            data[0] = first + second;
        }
        return;
    }
    temp_f2 = data[0];
    temp_f1 = lbl_80561210 * (temp_f2 - data[1]);
    data[1] = temp_f1;
    data[0] = temp_f2 - temp_f1;
    if (length > 4) {
        fn_801252D8(length, data, size2, (f32 *)((u8 *)work + size1 * 4));
        fn_80120E14(length, data, table + 8, size1, (void *)work);
    } else if (length == 4) {
        fn_80120E14(length, data, table + 8, size1, (void *)work);
    }
}

void fn_801254E4(s32, f32 *, s32, f32 *);
/* Ooura's ddct: in-place DCT of n floats in a (forward when isgn >= 0,
   inverse when isgn < 0).  ip holds the twiddle/cosine table sizes and a
   bit-reversal map; w holds the twiddle and cosine tables.  fn_80120834 and
   fn_80120B6C build those tables, fn_80120CA4/fn_80120E14 are the forward/
   inverse complex-FFT stages, and fn_801250CC/fn_801252D8/fn_801254E4 are the
   real-FFT folds; the surrounding two-point passes apply the DCT symmetry. */
void fn_8012023C(s32 n, s32 isgn, f32 *a, s32 ip, s32 w) {
    s32 twiddleLen;
    s32 cosLen;
    s32 i;
    f32 endValue;
    f32 first;

    twiddleLen = *(s32 *)ip;
    if (n > twiddleLen * 4) {
        twiddleLen = n >> 2;
        fn_80120834(twiddleLen, (s32 *)ip, (f32 *)w);
    }
    cosLen = *(s32 *)(ip + 4);
    if (n > cosLen) {
        cosLen = n;
        fn_80120B6C(n, (s32 *)ip, (f32 *)w + twiddleLen);
    }
    if (isgn < 0) {
        endValue = *(f32 *)((u8 *)a + (n - 1) * 4);
        for (i = n - 2; i >= 2; i -= 2) {
            a[i + 1] = a[i] - a[i - 1];
            a[i] = a[i] + a[i - 1];
        }
        first = a[0];
        a[1] = first - endValue;
        a[0] = first + endValue;
        if (n > 4) {
            fn_801252D8(n, a, cosLen, (f32 *)w + twiddleLen);
            fn_80120E14(n, a, ip + 8, twiddleLen, (void *)w);
        } else if (n == 4) {
            fn_80120E14(n, a, ip + 8, twiddleLen, (void *)w);
        }
    }
    fn_801254E4(n, a, cosLen, (f32 *)w + twiddleLen);
    if (isgn >= 0) {
        if (n > 4) {
            fn_80120CA4(n, a, ip + 8, twiddleLen, (void *)w);
            fn_801250CC(n, (s32)a, cosLen, (s32)((f32 *)w + twiddleLen));
        } else if (n == 4) {
            fn_80120CA4(n, a, ip + 8, twiddleLen, (void *)w);
        }
        endValue = a[0] - a[1];
        a[0] = a[0] + a[1];
        for (i = 2; i < n; i += 2) {
            a[i - 1] = a[i] - a[i + 1];
            a[i] = a[i] + a[i + 1];
        }
        *(f32 *)((u8 *)a + (n - 1) * 4) = endValue;
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
    /* Builds a trig lookup table for length arg0: stores cos(π/2*i/half)*0.5
       in arg2[i] and sin(π/2*i/half)*0.5 in arg2[arg0-i] for i in [1,half). */
    s32 i;
    s32 half;
    f32 scale;
    f32 angleStep;
    f32 cosHalf;

    arg1[1] = arg0;
    if (arg0 <= 1) return;
    half = arg0 >> 1;
    angleStep = lbl_80561214 / (f32)half;
    cosHalf = (f32)cos((f64)(angleStep * (f32)half));
    scale = lbl_80561210;
    arg2[0] = cosHalf;
    arg2[half] = scale * cosHalf;
    for (i = 1; i < half; i++) {
        arg2[i] = scale * (f32)cos((f64)(angleStep * (f32)i));
        arg2[arg0 - i] = scale * (f32)sin((f64)(angleStep * (f32)i));
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
    /* Dispatches to size-specific transform/copy helpers based on element count:
     * for large counts (>0x20) computes a quarter-size, prepares data, runs one
     * of several bulk paths, then finalizes; for medium/small counts uses the
     * corresponding fixed-size helpers. */
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

/* fn_80121400(n, s32 *map, f32 *data) reads its 3rd argument from r4 only:
 * the slot above it (sp+0x10) is never loaded, so callers may pass any type
 * there -- fn_80120E14 hands it the int `mode` and still matches. */
extern void fn_80121400(s32, s32 *, f32 *);
extern void fn_801219B4(void *);
extern void fn_80121BF4(void *);
extern void fn_80125014(void *);
extern void fn_80122518(s32, u8 *, void *);
void fn_80120E14(register s32 n, register void *a, register s32 ip, register s32 nw, register void *w) {
    /* Inverse-direction half of the recursive radix-4 complex FFT (Ooura-style)
     * that ddct/dcdft run on n floats in `a`, i.e. n/2 re/im samples.  `w` is the
     * twiddle table, `nw` its length in floats, `ip` the caller's bit-reversal
     * scratch table (ip + 2 of the caller's int array).  fn_80120CA4 is the
     * forward twin; each helper used here has the forward-sign partner that one
     * calls instead.
     *
     * n > 32: one twiddled butterfly stage over the whole array (fn_80122518,
     * taking its twiddles from w + nw - n/4), then the four quarters of n/4
     * floats transformed -- recursively through fn_80122E08/fn_80122ED8 while
     * n > 512, by the flat loops fn_80122FA4 once n/4 > 32 and fn_80123CEC below
     * that -- and last the bit-reversal permutation with conjugation
     * (fn_80121400, bitrv2conj), which puts the decimation-in-frequency result
     * back in natural order.
     * n == 32 and n == 16: their fixed butterfly (fn_80123E98, fn_80124AD8)
     * followed by the fixed permutation that orders it.
     * n == 8 and n == 4: a single stage of four (fn_80125014) or two
     * (fn_80125098) samples. */
    register s32 m;
    if (n > 0x20) {
        m = n >> 2;
        fn_80122518(n, (u8 *)a, (u8 *)w + (nw - m) * 4);
        if (n > 0x200) {
            fn_80122E08(m, a, nw, w);
            fn_80122ED8(m, (u8 *)a + m * 4, nw, w);
            fn_80122E08(m, (u8 *)a + m * 8, nw, w);
            fn_80122E08(m, (u8 *)a + ((m * 3) << 2), nw, w);
        } else if (m > 0x20) {
            fn_80122FA4(n, a, nw, w);
        } else {
            fn_80123CEC(n, a, nw, w);
        }
        fn_80121400(n, (s32 *)ip, (f32 *)a);
    } else if (n > 8) {
        if (n == 0x20) {
            fn_80123E98(a, (u8 *)w + (nw - 8) * 4);
            fn_801219B4(a);
        } else {
            fn_80124AD8(a, w);
            fn_80121BF4(a);
        }
    } else {
        if (n == 8) {
            fn_80125014(a);
        } else if (n == 4) {
            fn_80125098(a);
        }
    }
}

/*
 * fft_bit_reverse - put the complex samples of a in bit-reversed order, the
 * in-place reordering the radix-4/split-radix FFT stages around it expect.
 *
 * `n` is the number of floats in `a` (so n/2 complex samples, stored as
 * re/im pairs), and `ip` is the caller's scratch table of at least n/2
 * entries: this fills it with the bit-reversal offsets (ip[0] = 0, then each
 * level copies the level above with the current half-width added) and then
 * swaps a[j] with a[bitrev(j)] through it.  The two loops are the two shapes
 * of n: n == 4^k leaves four blocks of samples per index, so a swap at index j
 * has three partners (j + m2, j + 2*m2, j + 3*m2), while n == 2 * 4^k leaves
 * only two blocks and one partner.  Samples at 2*k and 2*k+m2 are swapped with
 * their own partner and need no ip lookup.
 */
void fn_80120F84(s32 n, s32 ip_arg, void *a_arg) {
    s32 *ip = (s32 *)ip_arg; /* bit-reversal offsets, one per complex sample */
    float *a = (float *)a_arg; /* the samples, as re/im pairs */
    int j, j1, k, k1, l, m, m2;
    float xr, xi, yr, yi; /* the sample at j1 and the one at k1 */

    /* Bit-reversal table: level m holds the offsets of the samples whose
       reversed index has log2(m) bits, each level adding the next half width. */
    ip[0] = 0;
    l = n;
    m = 1;
    while ((m << 3) < l) {
        l >>= 1;
        for (j = 0; j < m; j++) {
            ip[m + j] = ip[j] + l;
        }
        m <<= 1;
    }
    m2 = 2 * m; /* stride between the blocks of samples, in floats */
    if ((m << 3) == l) {
        /* n is a power of four: four blocks of samples per index. */
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += 2 * m2;
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 -= m2;
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += 2 * m2;
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
            }
            /* The diagonal sample and the one a block over are each other's. */
            j1 = 2 * k + m2 + ip[k];
            k1 = j1 + m2;
            xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
            a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
        }
    } else {
        /* n is twice a power of four: two blocks of samples per index. */
        for (k = 1; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += m2;
                xr = a[j1]; xi = a[j1 + 1]; yr = a[k1]; yi = a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
            }
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_80121400(s32 n, s32 *map, f32 *data) {
    s32 *ip = map;
    f32 *a = data;
    int j, j1, j2, j3, k, k1, l, m, m2;
    float xr, xi, yr, yi;
    ip[0] = 0;
    l = n;
    m = 1;
    while ((m << 3) < l) {
        l >>= 1;
        for (j = 0; j < m; j++) {
            ip[m + j] = ip[j] + l;
        }
        m <<= 1;
    }
    m2 = 2 * m;
    if ((m << 3) == l) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += 2 * m2;
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 -= m2;
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += 2 * m2;
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
            }
            j1 = 2 * k + ip[k];
            j2 = j1 + m2;
            j3 = j2 + m2;
            j3 += m2;
            a[j1 + 1] = -a[j1 + 1];
            xr = a[j2]; xi = -a[j2 + 1];
            yr = a[j3 - m2]; yi = -a[j3 - m2 + 1];
            a[j2] = yr; a[j2 + 1] = yi;
            a[j3 - m2] = xr; a[j3 - m2 + 1] = xi;
            a[j3 + 1] = -a[j3 + 1];
        }
    } else {
        a[1] = -a[1];
        a[m2 + 1] = -a[m2 + 1];
        for (k = 1; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
                j1 += m2;
                k1 += m2;
                xr = a[j1]; xi = -a[j1 + 1];
                yr = a[k1]; yi = -a[k1 + 1];
                a[j1] = yr; a[j1 + 1] = yi; a[k1] = xr; a[k1 + 1] = xi;
            }
            j1 = 2 * k + ip[k];
            a[j1 + 1] = -a[j1 + 1];
            a[j1 + m2 + 1] = -a[j1 + m2 + 1];
        }
    }
}
#pragma pop
void fn_80121848(void *values) {
    /* In-place bit-reversal of the 16 complex values in a 32-point FFT buffer;
     * each value is a real/imaginary float pair. */
    f32 *p = (f32 *)values;
    f32 c1re = p[2], c1im = p[3], c2re = p[4], c2im = p[5];
    f32 c3re = p[6], c3im = p[7], c4re = p[8], c4im = p[9];
    f32 c5re = p[10], c5im = p[11], c7re = p[14], c7im = p[15];
    f32 c8re = p[16], c8im = p[17], c10re = p[20], c10im = p[21];
    f32 c11re = p[22], c11im = p[23], c12re = p[24], c12im = p[25];
    f32 c13re = p[26], c13im = p[27], c14re = p[28], c14im = p[29];
    p[2] = c8re; p[3] = c8im;
    p[4] = c4re; p[5] = c4im;
    p[6] = c12re; p[7] = c12im;
    p[8] = c2re; p[9] = c2im;
    p[10] = c10re; p[11] = c10im;
    p[14] = c14re; p[15] = c14im;
    p[16] = c1re; p[17] = c1im;
    p[20] = c5re; p[21] = c5im;
    p[22] = c13re; p[23] = c13im;
    p[24] = c3re; p[25] = c3im;
    p[26] = c11re; p[27] = c11im;
    p[28] = c7re; p[29] = c7im;
}

// Fixed output-ordering permutation for the n == 32 inverse-FFT butterfly
// (fn_80123E98).  `a` holds 16 complex samples as re/im float pairs; the
// butterfly leaves them in an internal order, so this shuffles the 15 samples
// after sample 0 (offsets 0x08..0x7C) into natural order.  Sample 0 (offsets
// 0x00/0x04) is already correct and is left alone.  Each aXX temporary holds
// the value read from a + 0xXX so the in-place move can be done from registers.
void fn_801219B4(void *a) {
    f32 a08, a0C, a10, a14, a18, a1C, a20, a24, a28, a2C;
    f32 a30, a34, a38, a3C, a40, a44, a48, a4C, a50, a54;
    f32 a58, a5C, a60, a64, a68, a6C, a70, a74, a78, a7C;
    a08 = *(f32 *)((unsigned char *)a + 8);
    a40 = *(f32 *)((unsigned char *)a + 0x40);
    a78 = *(f32 *)((unsigned char *)a + 0x78);
    a0C = *(f32 *)((unsigned char *)a + 0xC);
    a44 = *(f32 *)((unsigned char *)a + 0x44);
    a7C = *(f32 *)((unsigned char *)a + 0x7C);
    a10 = *(f32 *)((unsigned char *)a + 0x10);
    a38 = *(f32 *)((unsigned char *)a + 0x38);
    a48 = *(f32 *)((unsigned char *)a + 0x48);
    a60 = *(f32 *)((unsigned char *)a + 0x60);
    a68 = *(f32 *)((unsigned char *)a + 0x68);
    a28 = *(f32 *)((unsigned char *)a + 0x28);
    a30 = *(f32 *)((unsigned char *)a + 0x30);
    a50 = *(f32 *)((unsigned char *)a + 0x50);
    a58 = *(f32 *)((unsigned char *)a + 0x58);
    a18 = *(f32 *)((unsigned char *)a + 0x18);
    a20 = *(f32 *)((unsigned char *)a + 0x20);
    a70 = *(f32 *)((unsigned char *)a + 0x70);
    a14 = *(f32 *)((unsigned char *)a + 0x14);
    a3C = *(f32 *)((unsigned char *)a + 0x3C);
    a4C = *(f32 *)((unsigned char *)a + 0x4C);
    a64 = *(f32 *)((unsigned char *)a + 0x64);
    a6C = *(f32 *)((unsigned char *)a + 0x6C);
    a2C = *(f32 *)((unsigned char *)a + 0x2C);
    a34 = *(f32 *)((unsigned char *)a + 0x34);
    a54 = *(f32 *)((unsigned char *)a + 0x54);
    a5C = *(f32 *)((unsigned char *)a + 0x5C);
    a1C = *(f32 *)((unsigned char *)a + 0x1C);
    a24 = *(f32 *)((unsigned char *)a + 0x24);
    a74 = *(f32 *)((unsigned char *)a + 0x74);
    *(f32 *)((unsigned char *)a + 8) = a78;
    *(f32 *)((unsigned char *)a + 0xC) = a7C;
    *(f32 *)((unsigned char *)a + 0x10) = a38;
    *(f32 *)((unsigned char *)a + 0x14) = a3C;
    *(f32 *)((unsigned char *)a + 0x18) = a58;
    *(f32 *)((unsigned char *)a + 0x1C) = a5C;
    *(f32 *)((unsigned char *)a + 0x20) = a18;
    *(f32 *)((unsigned char *)a + 0x24) = a1C;
    *(f32 *)((unsigned char *)a + 0x28) = a68;
    *(f32 *)((unsigned char *)a + 0x2C) = a6C;
    *(f32 *)((unsigned char *)a + 0x30) = a28;
    *(f32 *)((unsigned char *)a + 0x34) = a2C;
    *(f32 *)((unsigned char *)a + 0x38) = a48;
    *(f32 *)((unsigned char *)a + 0x3C) = a4C;
    *(f32 *)((unsigned char *)a + 0x40) = a08;
    *(f32 *)((unsigned char *)a + 0x44) = a0C;
    *(f32 *)((unsigned char *)a + 0x48) = a70;
    *(f32 *)((unsigned char *)a + 0x4C) = a74;
    *(f32 *)((unsigned char *)a + 0x50) = a30;
    *(f32 *)((unsigned char *)a + 0x54) = a34;
    *(f32 *)((unsigned char *)a + 0x58) = a50;
    *(f32 *)((unsigned char *)a + 0x5C) = a54;
    *(f32 *)((unsigned char *)a + 0x60) = a10;
    *(f32 *)((unsigned char *)a + 0x64) = a14;
    *(f32 *)((unsigned char *)a + 0x68) = a60;
    *(f32 *)((unsigned char *)a + 0x6C) = a64;
    *(f32 *)((unsigned char *)a + 0x70) = a20;
    *(f32 *)((unsigned char *)a + 0x74) = a24;
    *(f32 *)((unsigned char *)a + 0x78) = a40;
    *(f32 *)((unsigned char *)a + 0x7C) = a44;
}

void fn_80121BB0(void *arg0) {
    /* Swap pairs of floats within a 16-float block (indices 2,3<->8,9 and 6,7<->12,13). */
    f32 *p = (f32 *)arg0;
    f32 a, c, e, g, b, d, f, h;
    a = p[2]; c = p[3]; e = p[6]; g = p[7];
    b = p[8]; d = p[9]; f = p[12]; h = p[13];
    p[2] = b; p[3] = d; p[6] = f; p[7] = h;
    p[8] = a; p[9] = c; p[12] = e; p[13] = g;
}

/* Reorder 16 floats at arg0+0x08..0x3C: permute the 8 (re,im) pairs by index 6,2,4,0,5,1,3. */
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

extern float lbl_80561218;
extern float lbl_80561230;
void fn_80121C68(s32 arg0, void *arg1, void *arg2) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f10;
    f32 temp_f10_10;
    f32 temp_f10_11;
    f32 temp_f10_12;
    f32 temp_f10_13;
    f32 temp_f10_14;
    f32 temp_f10_2;
    f32 temp_f10_3;
    f32 temp_f10_4;
    f32 temp_f10_5;
    f32 temp_f10_6;
    f32 temp_f10_7;
    f32 temp_f10_8;
    f32 temp_f10_9;
    f32 temp_f11;
    f32 temp_f11_2;
    f32 temp_f11_3;
    f32 temp_f11_4;
    f32 temp_f11_5;
    f32 temp_f11_6;
    f32 temp_f11_7;
    f32 temp_f11_8;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f13_3;
    f32 temp_f13_4;
    f32 temp_f13_5;
    f32 temp_f13_6;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f14_4;
    f32 temp_f14_5;
    f32 temp_f14_6;
    f32 temp_f14_7;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f15_3;
    f32 temp_f15_4;
    f32 temp_f15_5;
    f32 temp_f15_6;
    f32 temp_f15_7;
    f32 temp_f15_8;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f16_4;
    f32 temp_f16_5;
    f32 temp_f16_6;
    f32 temp_f17;
    f32 temp_f17_2;
    f32 temp_f17_3;
    f32 temp_f17_4;
    f32 temp_f17_5;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f18_3;
    f32 temp_f18_4;
    f32 temp_f19;
    f32 temp_f19_2;
    f32 temp_f19_3;
    f32 temp_f19_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f25_3;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f28_3;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f4_6;
    f32 temp_f4_7;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f5_5;
    f32 temp_f5_6;
    f32 temp_f5_7;
    f32 temp_f5_8;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f6_5;
    f32 temp_f6_6;
    f32 temp_f7;
    f32 temp_f7_10;
    f32 temp_f7_11;
    f32 temp_f7_12;
    f32 temp_f7_13;
    f32 temp_f7_14;
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
    f32 temp_f8_12;
    f32 temp_f8_13;
    f32 temp_f8_14;
    f32 temp_f8_15;
    f32 temp_f8_16;
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
    f32 var_f6;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r10_3;
    s32 temp_r10_5;
    s32 temp_r10_6;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r11_3;
    s32 temp_r11_5;
    s32 temp_r11_6;
    s32 temp_r12;
    s32 temp_r12_2;
    s32 temp_r12_4;
    s32 temp_r12_5;
    s32 temp_r25;
    s32 temp_r25_3;
    s32 temp_r25_4;
    s32 temp_r26;
    s32 temp_r26_2;
    s32 temp_r26_4;
    s32 temp_r27;
    s32 temp_r27_2;
    s32 temp_r28;
    s32 temp_r28_2;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_3;
    s32 temp_r6_4;
    s32 temp_r6_6;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r7_3;
    s32 temp_r8;
    s32 temp_r8_2;
    s32 temp_r8_3;
    s32 temp_r9;
    s32 var_r3;
    u32 var_ctr;
    void *temp_r10_4;
    void *temp_r11_4;
    void *temp_r12_3;
    void *temp_r25_2;
    void *temp_r26_3;
    void *temp_r6_2;
    void *temp_r6_5;
    u8 *var_r27;
    u8 *var_r5;
    var_r5 = arg2;
    temp_r9 = arg0 >> 3;
    temp_r26 = (arg0 * 2) & 0xFFFFFFF0;
    temp_r8 = temp_r9 * 2;
    temp_r11 = arg0 & 0xFFFFFFF8;
    temp_r7 = temp_r9 - 2;
    temp_r12 = temp_r9 * 6;
    temp_r25 = ((temp_r9 * 4) + 1) * 4;
    temp_r12_2 = temp_r12 * 4;
    temp_r6 = (temp_r8 + 1) * 4;
    temp_f2 = M2C_FIELD(arg1, f32 *, 0);
    temp_f1 = M2C_FIELD(arg1, f32 *, temp_r26);
    temp_r10 = (temp_r12 + 1) * 4;
    temp_f5 = M2C_FIELD(arg1, f32 *, 4);
    temp_f0 = M2C_FIELD(arg1, f32 *, temp_r25);
    temp_f6 = temp_f2 + temp_f1;
    temp_f8 = temp_f2 - temp_f1;
    temp_f4 = M2C_FIELD(arg1, f32 *, temp_r11);
    temp_f3 = M2C_FIELD(arg1, f32 *, temp_r12_2);
    temp_f7 = temp_f5 + temp_f0;
    temp_f5_2 = temp_f5 - temp_f0;
    temp_f2_2 = M2C_FIELD(arg1, f32 *, temp_r6);
    temp_f9 = temp_f4 + temp_f3;
    temp_f1_2 = M2C_FIELD(arg1, f32 *, temp_r10);
    temp_f11 = temp_f4 - temp_f3;
    sp10 = lbl_80561218;
    temp_f12 = temp_f2_2 - temp_f1_2;
    var_r27 = (u8 *)arg1 + 8;
    temp_f10 = temp_f2_2 + temp_f1_2;
    spC = lbl_80561230;
    var_r3 = 2;
    M2C_FIELD(arg1, f32 *, 0) = (f32) (temp_f6 + temp_f9);
    var_f6 = spC;
    M2C_FIELD(arg1, f32 *, 4) = (f32) (temp_f7 + temp_f10);
    M2C_FIELD(arg1, f32 *, temp_r11) = temp_f6 - temp_f9;
    M2C_FIELD(arg1, f32 *, temp_r6) = temp_f7 - temp_f10;
    M2C_FIELD(arg1, f32 *, temp_r26) = temp_f8 - temp_f12;
    M2C_FIELD(arg1, f32 *, temp_r25) = temp_f5_2 + temp_f11;
    M2C_FIELD(arg1, f32 *, temp_r12_2) = temp_f8 + temp_f12;
    M2C_FIELD(arg1, f32 *, temp_r10) = temp_f5_2 - temp_f11;
    sp8 = lbl_80561218;
    temp_f1_3 = M2C_FIELD(var_r5, f32 *, 0xC);
    sp14 = M2C_FIELD(var_r5, f32 *, 4);
    temp_f0_2 = M2C_FIELD(var_r5, f32 *, 8);
    var_ctr = (u32) (temp_r7 + 1) >> 2U;
    if (temp_r7 > 2) {
        do {
            temp_r11_2 = var_r3 + temp_r8;
            temp_f5_3 = M2C_FIELD(var_r27, f32 *, 0);
            temp_r0 = temp_r11_2 + temp_r8;
            temp_f24 = M2C_FIELD(var_r5, f32 *, 0x18);
            temp_f26 = M2C_FIELD(var_r5, f32 *, 0x1C);
            temp_r12_3 = (u8 *)arg1 + (temp_r0 * 4);
            temp_r0_2 = temp_r11_2 * 4;
            temp_r25_2 = (u8 *)arg1 + ((temp_r0 + temp_r8) * 4);
            temp_f4_2 = M2C_FIELD(temp_r12_3, f32 *, 0);
            temp_f12_2 = M2C_FIELD(arg1, f32 *, temp_r0_2);
            temp_r6_2 = (u8 *)arg1 + temp_r0_2;
            temp_f11_2 = M2C_FIELD(temp_r25_2, f32 *, 0);
            temp_f9_2 = temp_f5_3 + temp_f4_2;
            temp_f21 = temp_f5_3 - temp_f4_2;
            temp_f10_2 = temp_f12_2 + temp_f11_2;
            temp_f29 = M2C_FIELD(var_r27, f32 *, 8);
            temp_f25 = sp8 + temp_f24;
            temp_f30 = M2C_FIELD(temp_r12_3, f32 *, 8);
            temp_f10_3 = M2C_FIELD(temp_r6_2, f32 *, 8);
            temp_f9_3 = M2C_FIELD(temp_r25_2, f32 *, 8);
            sp20 = (f64) (temp_f9_2 - temp_f10_2);
            temp_f27 = M2C_FIELD(var_r27, f32 *, 4);
            temp_f6_2 = temp_f29 + temp_f30;
            temp_f28 = M2C_FIELD(temp_r12_3, f32 *, 4);
            temp_f18 = temp_f10_3 + temp_f9_3;
            temp_f8_2 = M2C_FIELD(temp_r6_2, f32 *, 4);
            temp_f5_4 = temp_f1_3 * (var_f6 - temp_f26);
            temp_f7_2 = M2C_FIELD(temp_r25_2, f32 *, 4);
            temp_f22 = M2C_FIELD(var_r5, f32 *, 0x10);
            temp_f23 = M2C_FIELD(var_r5, f32 *, 0x14);
            temp_f15 = temp_f27 + temp_f28;
            temp_f14 = temp_f8_2 + temp_f7_2;
            temp_f31 = M2C_FIELD(var_r27, f32 *, 0xC);
            temp_f20 = temp_f8_2 - temp_f7_2;
            temp_f13 = M2C_FIELD(temp_r12_3, f32 *, 0xC);
            temp_f8_3 = M2C_FIELD(temp_r6_2, f32 *, 0xC);
            temp_f7_3 = M2C_FIELD(temp_r25_2, f32 *, 0xC);
            temp_f19 = temp_f31 + temp_f13;
            M2C_FIELD(var_r27, f32 *, 0) = (f32) (temp_f9_2 + temp_f10_2);
            sp18 = (f64) (temp_f6_2 + temp_f18);
            temp_f17 = temp_f8_3 + temp_f7_3;
            M2C_FIELD(var_r27, f32 *, 4) = (f32) (temp_f15 + temp_f14);
            temp_f2_3 = sp10 + temp_f22;
            sp10 = temp_f22;
            M2C_FIELD(var_r27, f32 *, 8) = (f32) sp18;
            temp_f2_4 = temp_f0_2 * temp_f2_3;
            M2C_FIELD(var_r27, f32 *, 0xC) = (f32) (temp_f19 + temp_f17);
            temp_f3_2 = temp_f0_2 * (spC + temp_f23);
            temp_f15_2 = temp_f27 - temp_f28;
            var_r5 += 0x10;
            M2C_FIELD(arg1, f32 *, temp_r0_2) = (f32) sp20;
            temp_f14_2 = temp_f29 - temp_f30;
            temp_f13_2 = temp_f31 - temp_f13;
            M2C_FIELD(temp_r6_2, f32 *, 4) = (f32) (temp_f15 - temp_f14);
            temp_f4_3 = temp_f1_3 * temp_f25;
            M2C_FIELD(temp_r6_2, f32 *, 8) = (f32) (temp_f6_2 - temp_f18);
            temp_f25_2 = temp_f8_3 - temp_f7_3;
            var_f6 = -temp_f26;
            temp_f11_3 = temp_f12_2 - temp_f11_2;
            spC = temp_f23;
            temp_f19_2 = temp_f10_3 - temp_f9_3;
            temp_f7_4 = temp_f21 - temp_f20;
            sp8 = temp_f24;
            M2C_FIELD(temp_r6_2, f32 *, 0xC) = (f32) (temp_f19 - temp_f17);
            temp_f8_4 = temp_f15_2 + temp_f11_3;
            temp_r10_2 = temp_r8 - var_r3;
            temp_r26_2 = temp_r10_2 + temp_r8;
            temp_f15_3 = temp_f15_2 - temp_f11_3;
            temp_r6_3 = temp_r26_2 + temp_r8;
            temp_r11_3 = temp_r6_3 * 4;
            temp_r6_4 = (temp_r6_3 + temp_r8) * 4;
            temp_f17_2 = temp_f14_2 - temp_f25_2;
            temp_r0_3 = temp_r26_2 * 4;
            temp_f7_5 = temp_f14_2 + temp_f25_2;
            temp_r10_3 = temp_r10_2 * 4;
            temp_r26_3 = (u8 *)arg1 + temp_r0_3;
            temp_f18_2 = temp_f13_2 + temp_f19_2;
            temp_f8_5 = temp_f13_2 - temp_f19_2;
            M2C_FIELD(temp_r12_3, f32 *, 0) = (f32) ((temp_f2_4 * temp_f7_4) - (temp_f3_2 * temp_f8_4));
            temp_f16 = temp_f21 + temp_f20;
            M2C_FIELD(temp_r12_3, f32 *, 4) = (f32) ((temp_f2_4 * temp_f8_4) + (temp_f3_2 * temp_f7_4));
            M2C_FIELD(temp_r12_3, f32 *, 8) = (f32) ((temp_f22 * temp_f17_2) - (temp_f23 * temp_f18_2));
            M2C_FIELD(temp_r12_3, f32 *, 0xC) = (f32) ((temp_f22 * temp_f18_2) + (temp_f23 * temp_f17_2));
            M2C_FIELD(temp_r25_2, f32 *, 0) = (f32) ((temp_f4_3 * temp_f16) + (temp_f5_4 * temp_f15_3));
            M2C_FIELD(temp_r25_2, f32 *, 4) = (f32) ((temp_f4_3 * temp_f15_3) - (temp_f5_4 * temp_f16));
            M2C_FIELD(temp_r25_2, f32 *, 8) = (f32) ((temp_f24 * temp_f7_5) + (var_f6 * temp_f8_5));
            M2C_FIELD(temp_r25_2, f32 *, 0xC) = (f32) ((temp_f24 * temp_f8_5) - (var_f6 * temp_f7_5));
            temp_f10_4 = M2C_FIELD(arg1, f32 *, temp_r10_3);
            temp_r10_4 = (u8 *)arg1 + temp_r10_3;
            temp_f9_4 = M2C_FIELD(arg1, f32 *, temp_r11_3);
            temp_r11_4 = (u8 *)arg1 + temp_r11_3;
            temp_f11_4 = M2C_FIELD(arg1, f32 *, temp_r6_4);
            temp_r6_5 = (u8 *)arg1 + temp_r6_4;
            temp_f16_2 = temp_f10_4 + temp_f9_4;
            temp_f8_6 = M2C_FIELD(temp_r10_4, f32 *, 4);
            temp_f7_6 = M2C_FIELD(temp_r11_4, f32 *, 4);
            temp_f9_5 = temp_f10_4 - temp_f9_4;
            temp_f19_3 = M2C_FIELD(temp_r10_4, f32 *, -8);
            temp_f18_3 = M2C_FIELD(temp_r11_4, f32 *, -8);
            temp_f17_3 = temp_f8_6 + temp_f7_6;
            temp_f15_4 = M2C_FIELD(temp_r10_4, f32 *, -4);
            temp_f14_3 = M2C_FIELD(temp_r11_4, f32 *, -4);
            temp_f10_5 = temp_f8_6 - temp_f7_6;
            temp_f12_3 = M2C_FIELD(arg1, f32 *, temp_r0_3);
            temp_f13_3 = temp_f19_3 + temp_f18_3;
            temp_f8_7 = M2C_FIELD(temp_r26_3, f32 *, 4);
            temp_f20_2 = temp_f15_4 + temp_f14_3;
            temp_f25_3 = temp_f15_4 - temp_f14_3;
            temp_f7_7 = M2C_FIELD(temp_r6_5, f32 *, 4);
            temp_f15_5 = temp_f12_3 + temp_f11_4;
            temp_f31_2 = M2C_FIELD(temp_r26_3, f32 *, -8);
            temp_f28_2 = M2C_FIELD(temp_r6_5, f32 *, -8);
            temp_f11_5 = temp_f12_3 - temp_f11_4;
            temp_f21_2 = temp_f19_3 - temp_f18_3;
            temp_f14_4 = temp_f8_7 + temp_f7_7;
            temp_f12_4 = temp_f8_7 - temp_f7_7;
            temp_f26_2 = temp_f31_2 + temp_f28_2;
            temp_f30_2 = M2C_FIELD(temp_r26_3, f32 *, -4);
            temp_f29_2 = M2C_FIELD(temp_r6_5, f32 *, -4);
            temp_f7_8 = temp_f9_5 - temp_f12_4;
            var_r27 += 0x10;
            M2C_FIELD(temp_r10_4, f32 *, 0) = (f32) (temp_f16_2 + temp_f15_5);
            temp_f27_2 = temp_f30_2 + temp_f29_2;
            var_r3 += 4;
            M2C_FIELD(temp_r10_4, f32 *, 4) = (f32) (temp_f17_3 + temp_f14_4);
            temp_f8_8 = temp_f10_5 + temp_f11_5;
            M2C_FIELD(temp_r10_4, f32 *, -8) = (f32) (temp_f13_3 + temp_f26_2);
            M2C_FIELD(temp_r10_4, f32 *, -4) = (f32) (temp_f20_2 + temp_f27_2);
            temp_f28_3 = temp_f31_2 - temp_f28_2;
            M2C_FIELD(temp_r26_3, f32 *, 0) = (f32) (temp_f16_2 - temp_f15_5);
            temp_f14_5 = temp_f30_2 - temp_f29_2;
            M2C_FIELD(temp_r26_3, f32 *, 4) = (f32) (temp_f17_3 - temp_f14_4);
            temp_f10_6 = temp_f10_5 - temp_f11_5;
            M2C_FIELD(temp_r26_3, f32 *, -8) = (f32) (temp_f13_3 - temp_f26_2);
            temp_f9_6 = temp_f9_5 + temp_f12_4;
            temp_f16_3 = temp_f25_3 + temp_f28_3;
            M2C_FIELD(temp_r26_3, f32 *, -4) = (f32) (temp_f20_2 - temp_f27_2);
            temp_f13_4 = temp_f21_2 - temp_f14_5;
            temp_f3_3 = temp_f21_2 + temp_f14_5;
            M2C_FIELD(temp_r11_4, f32 *, 0) = (f32) ((temp_f3_2 * temp_f7_8) - (temp_f2_4 * temp_f8_8));
            M2C_FIELD(temp_r11_4, f32 *, 4) = (f32) ((temp_f3_2 * temp_f8_8) + (temp_f2_4 * temp_f7_8));
            M2C_FIELD(temp_r11_4, f32 *, -8) = (f32) ((temp_f23 * temp_f13_4) - (temp_f22 * temp_f16_3));
            M2C_FIELD(temp_r11_4, f32 *, -4) = (f32) ((temp_f23 * temp_f16_3) + (temp_f22 * temp_f13_4));
            temp_f8_9 = temp_f25_3 - temp_f28_3;
            M2C_FIELD(temp_r6_5, f32 *, 0) = (f32) ((temp_f5_4 * temp_f9_6) + (temp_f4_3 * temp_f10_6));
            M2C_FIELD(temp_r6_5, f32 *, 4) = (f32) ((temp_f5_4 * temp_f10_6) - (temp_f4_3 * temp_f9_6));
            M2C_FIELD(temp_r6_5, f32 *, -8) = (f32) ((var_f6 * temp_f3_3) + (temp_f24 * temp_f8_9));
            M2C_FIELD(temp_r6_5, f32 *, -4) = (f32) ((var_f6 * temp_f8_9) - (temp_f24 * temp_f3_3));
            var_ctr -= 1;
        } while (var_ctr != 0);
    }
    temp_r6_6 = temp_r9 * 3;
    temp_r25_3 = temp_r7 * 4;
    temp_r7_2 = temp_r9 * 5;
    temp_r8_2 = temp_r9 * 7;
    temp_r12_4 = (temp_r6_6 - 2) * 4;
    temp_r30 = (temp_r7_2 - 2) * 4;
    temp_r27 = (temp_r8_2 - 2) * 4;
    temp_r28 = (temp_r9 - 1) * 4;
    temp_f10_7 = M2C_FIELD(arg1, f32 *, temp_r25_3);
    temp_r10_5 = (temp_r6_6 - 1) * 4;
    temp_f9_7 = M2C_FIELD(arg1, f32 *, temp_r30);
    temp_r29 = (temp_r7_2 - 1) * 4;
    temp_r11_5 = (temp_r8_2 - 1) * 4;
    temp_f15_6 = temp_f10_7 + temp_f9_7;
    temp_f7_9 = M2C_FIELD(arg1, f32 *, temp_r12_4);
    temp_f5_5 = M2C_FIELD(arg1, f32 *, temp_r27);
    temp_f8_10 = M2C_FIELD(arg1, f32 *, temp_r28);
    temp_f9_8 = temp_f10_7 - temp_f9_7;
    temp_f6_3 = M2C_FIELD(arg1, f32 *, temp_r29);
    temp_f17_4 = temp_f7_9 + temp_f5_5;
    temp_f4_4 = M2C_FIELD(arg1, f32 *, temp_r10_5);
    temp_f3_4 = M2C_FIELD(arg1, f32 *, temp_r11_5);
    temp_f16_4 = temp_f8_10 + temp_f6_3;
    temp_f10_8 = temp_f8_10 - temp_f6_3;
    temp_f18_4 = temp_f4_4 + temp_f3_4;
    temp_r5 = temp_r9 * 0x14;
    temp_f20_3 = temp_f4_4 - temp_f3_4;
    temp_r3 = (temp_r7_2 + 1) * 4;
    M2C_FIELD(arg1, f32 *, temp_r25_3) = temp_f15_6 + temp_f17_4;
    temp_f19_4 = temp_f7_9 - temp_f5_5;
    temp_r25_4 = temp_r9 * 4;
    temp_f7_10 = temp_f9_8 - temp_f20_3;
    temp_r26_4 = (temp_r9 + 1) * 4;
    temp_f8_11 = temp_f10_8 + temp_f19_4;
    M2C_FIELD(arg1, f32 *, temp_r28) = temp_f16_4 + temp_f18_4;
    temp_f2_5 = temp_f0_2 * (sp10 + sp14);
    temp_f0_3 = temp_f0_2 * (spC + sp14);
    M2C_FIELD(arg1, f32 *, temp_r12_4) = temp_f15_6 - temp_f17_4;
    temp_f3_5 = temp_f1_3 * (sp8 - sp14);
    M2C_FIELD(arg1, f32 *, temp_r10_5) = temp_f16_4 - temp_f18_4;
    temp_f9_9 = temp_f9_8 + temp_f20_3;
    temp_f1_4 = temp_f1_3 * (var_f6 - sp14);
    temp_f10_9 = temp_f10_8 - temp_f19_4;
    M2C_FIELD(arg1, f32 *, temp_r30) = (temp_f2_5 * temp_f7_10) - (temp_f0_3 * temp_f8_11);
    M2C_FIELD(arg1, f32 *, temp_r29) = (temp_f2_5 * temp_f8_11) + (temp_f0_3 * temp_f7_10);
    M2C_FIELD(arg1, f32 *, temp_r27) = (temp_f3_5 * temp_f9_9) + (temp_f1_4 * temp_f10_9);
    M2C_FIELD(arg1, f32 *, temp_r11_5) = (temp_f3_5 * temp_f10_9) - (temp_f1_4 * temp_f9_9);
    temp_f11_6 = M2C_FIELD(arg1, f32 *, temp_r25_4);
    temp_f10_10 = M2C_FIELD(arg1, f32 *, temp_r5);
    temp_f9_10 = M2C_FIELD(arg1, f32 *, temp_r26_4);
    temp_f8_12 = M2C_FIELD(arg1, f32 *, temp_r3);
    temp_f12_5 = temp_f11_6 + temp_f10_10;
    temp_f13_5 = temp_f9_10 + temp_f8_12;
    temp_r0_4 = temp_r9 * 0x1C;
    temp_r27_2 = temp_r9 * 0xC;
    temp_f7_11 = M2C_FIELD(arg1, f32 *, temp_r27_2);
    temp_f6_4 = M2C_FIELD(arg1, f32 *, temp_r0_4);
    temp_r28_2 = (temp_r8_2 + 1) * 4;
    temp_f10_11 = temp_f11_6 - temp_f10_10;
    temp_r29_2 = (temp_r6_6 + 1) * 4;
    temp_f14_6 = temp_f7_11 + temp_f6_4;
    temp_f5_6 = M2C_FIELD(arg1, f32 *, temp_r29_2);
    temp_f16_5 = temp_f7_11 - temp_f6_4;
    temp_f4_5 = M2C_FIELD(arg1, f32 *, temp_r28_2);
    temp_f11_7 = temp_f9_10 - temp_f8_12;
    temp_f17_5 = temp_f5_6 - temp_f4_5;
    temp_f15_7 = temp_f5_6 + temp_f4_5;
    temp_f7_12 = temp_f10_11 - temp_f17_5;
    M2C_FIELD(arg1, f32 *, temp_r25_4) = temp_f12_5 + temp_f14_6;
    temp_f8_13 = temp_f11_7 + temp_f16_5;
    temp_f9_11 = temp_f10_11 + temp_f17_5;
    temp_r30_2 = (temp_r7_2 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r26_4) = temp_f13_5 + temp_f15_7;
    M2C_FIELD(arg1, f32 *, temp_r27_2) = temp_f12_5 - temp_f14_6;
    temp_f10_12 = temp_f11_7 - temp_f16_5;
    temp_r31 = (temp_r9 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r29_2) = temp_f13_5 - temp_f15_7;
    temp_r12_5 = (temp_r7_2 + 3) * 4;
    temp_r11_6 = (temp_r9 + 3) * 4;
    temp_r10_6 = (temp_r8_2 + 2) * 4;
    temp_f6_5 = -sp14;
    temp_r8_3 = (temp_r6_6 + 2) * 4;
    temp_r7_3 = (temp_r8_2 + 3) * 4;
    M2C_FIELD(arg1, f32 *, temp_r5) = sp14 * (temp_f7_12 - temp_f8_13);
    temp_r5_2 = (temp_r6_6 + 3) * 4;
    M2C_FIELD(arg1, f32 *, temp_r3) = sp14 * (temp_f8_13 + temp_f7_12);
    M2C_FIELD(arg1, f32 *, temp_r0_4) = temp_f6_5 * (temp_f9_11 + temp_f10_12);
    M2C_FIELD(arg1, f32 *, temp_r28_2) = temp_f6_5 * (temp_f10_12 - temp_f9_11);
    temp_f5_7 = M2C_FIELD(arg1, f32 *, temp_r31);
    temp_f4_6 = M2C_FIELD(arg1, f32 *, temp_r30_2);
    temp_f9_12 = M2C_FIELD(arg1, f32 *, temp_r11_6);
    temp_f8_14 = M2C_FIELD(arg1, f32 *, temp_r12_5);
    temp_f10_13 = temp_f5_7 + temp_f4_6;
    temp_f13_6 = temp_f5_7 - temp_f4_6;
    temp_f7_13 = M2C_FIELD(arg1, f32 *, temp_r8_3);
    temp_f6_6 = M2C_FIELD(arg1, f32 *, temp_r10_6);
    temp_f12_6 = temp_f9_12 + temp_f8_14;
    temp_f14_7 = temp_f9_12 - temp_f8_14;
    temp_f8_15 = temp_f7_13 + temp_f6_6;
    temp_f5_8 = M2C_FIELD(arg1, f32 *, temp_r5_2);
    temp_f7_14 = temp_f7_13 - temp_f6_6;
    temp_f4_7 = M2C_FIELD(arg1, f32 *, temp_r7_3);
    temp_f15_8 = temp_f5_8 + temp_f4_7;
    temp_f16_6 = temp_f5_8 - temp_f4_7;
    temp_f9_13 = temp_f13_6 - temp_f16_6;
    temp_f11_8 = temp_f14_7 + temp_f7_14;
    M2C_FIELD(arg1, f32 *, temp_r31) = temp_f10_13 + temp_f8_15;
    M2C_FIELD(arg1, f32 *, temp_r11_6) = temp_f12_6 + temp_f15_8;
    temp_f10_14 = temp_f14_7 - temp_f7_14;
    M2C_FIELD(arg1, f32 *, temp_r8_3) = temp_f10_13 - temp_f8_15;
    temp_f8_16 = temp_f13_6 + temp_f16_6;
    M2C_FIELD(arg1, f32 *, temp_r5_2) = temp_f12_6 - temp_f15_8;
    M2C_FIELD(arg1, f32 *, temp_r30_2) = (temp_f0_3 * temp_f9_13) - (temp_f2_5 * temp_f11_8);
    M2C_FIELD(arg1, f32 *, temp_r12_5) = (temp_f0_3 * temp_f11_8) + (temp_f2_5 * temp_f9_13);
    M2C_FIELD(arg1, f32 *, temp_r10_6) = (temp_f1_4 * temp_f8_16) + (temp_f3_5 * temp_f10_14);
    M2C_FIELD(arg1, f32 *, temp_r7_3) = (temp_f1_4 * temp_f10_14) - (temp_f3_5 * temp_f8_16);
}

extern f32 lbl_80561218;
extern f32 lbl_80561230;
void fn_80122518(s32 arg0, u8 *arg1, void *arg2) {
    f64 sp38; f64 sp30; f64 sp28; f64 sp20; f64 sp18;
    f32 sp14, sp10, spC, sp8;
    f32 temp_f0,temp_f0_2,temp_f0_3,temp_f0_4,temp_f0_5,temp_f0_6,temp_f0_7,temp_f0_8,temp_f0_9;
    f32 temp_f1,temp_f1_2,temp_f1_3,temp_f1_4,temp_f1_5,temp_f1_6,temp_f1_7,temp_f1_8;
    f32 temp_f2,temp_f2_2,temp_f2_3,temp_f2_4,temp_f2_5,temp_f2_6,temp_f2_7;
    f32 temp_f3,temp_f3_2,temp_f3_3,temp_f3_4,temp_f3_5,temp_f3_6,temp_f3_7,temp_f3_8,temp_f3_9;
    f32 temp_f4,temp_f4_2,temp_f4_3,temp_f4_4,temp_f4_5;
    f32 temp_f5,temp_f5_2,temp_f5_3,temp_f5_4,temp_f5_5,temp_f5_6,temp_f5_7,temp_f5_8,temp_f5_9,temp_f5_10;
    f32 temp_f6,temp_f6_2,temp_f6_3,temp_f6_4,temp_f6_5,temp_f6_6,temp_f6_7,temp_f6_8,temp_f6_9,temp_f6_10,temp_f6_11;
    f32 temp_f7,temp_f7_2,temp_f7_3,temp_f7_4,temp_f7_5,temp_f7_6,temp_f7_7,temp_f7_8,temp_f7_9,temp_f7_10,temp_f7_11,temp_f7_12;
    f32 temp_f8,temp_f8_2,temp_f8_3,temp_f8_4,temp_f8_5,temp_f8_6,temp_f8_7,temp_f8_8,temp_f8_9,temp_f8_10,temp_f8_11;
    f32 temp_f9,temp_f9_2,temp_f9_3,temp_f9_4,temp_f9_5,temp_f9_6,temp_f9_7,temp_f9_8,temp_f9_9,temp_f9_10,temp_f9_11,temp_f9_12,temp_f9_13;
    f32 temp_f10,temp_f10_2,temp_f10_3,temp_f10_4,temp_f10_5,temp_f10_6,temp_f10_7,temp_f10_8,temp_f10_9,temp_f10_10;
    f32 temp_f11,temp_f11_2,temp_f11_3,temp_f11_4,temp_f11_5,temp_f11_6,temp_f11_7,temp_f11_8,temp_f11_9,temp_f11_10,temp_f11_11,temp_f11_12;
    f32 temp_f12,temp_f12_2,temp_f12_3,temp_f12_4,temp_f12_5,temp_f12_6,temp_f12_7,temp_f12_8;
    f32 temp_f13,temp_f13_2,temp_f13_3,temp_f13_4,temp_f13_5,temp_f13_6,temp_f13_7;
    f32 temp_f14,temp_f14_2,temp_f14_3,temp_f15,temp_f15_2,temp_f15_3;
    f32 temp_f16,temp_f16_2,temp_f16_3,temp_f16_4;
    f32 temp_f17,temp_f17_2,temp_f17_3,temp_f18,temp_f18_2;
    f32 temp_f19,temp_f19_2,temp_f19_3,temp_f19_4;
    f32 temp_f20,temp_f20_2,temp_f21,temp_f21_2,temp_f21_3,temp_f22;
    f32 temp_f23,temp_f23_2,temp_f23_3,temp_f24;
    f32 temp_f25,temp_f25_2,temp_f26,temp_f26_2,temp_f26_3;
    f32 temp_f27,temp_f27_2,temp_f28,temp_f28_2,temp_f29,temp_f29_2;
    f32 temp_f30,temp_f30_2,temp_f31,temp_f31_2;
    f32 var_f24;
    s32 temp_r0,temp_r0_2,temp_r0_3,temp_r0_4,temp_r0_5;
    s32 temp_r3,temp_r3_2,temp_r3_3,temp_r5,temp_r6,temp_r6_2,temp_r6_3,temp_r7,temp_r8,temp_r8_2;
    s32 temp_r9,temp_r9_2,temp_r9_3,temp_r9_5,temp_r9_7,temp_r9_8,temp_r9_9;
    s32 temp_r10,temp_r10_3,temp_r10_4,temp_r10_5;
    s32 temp_r11,temp_r11_2,temp_r11_4,temp_r11_5,temp_r11_6;
    s32 temp_r12,temp_r12_3,temp_r12_4;
    s32 temp_r26,temp_r26_3,temp_r27,temp_r28,temp_r28_3,temp_r29,temp_r29_2,temp_r30,temp_r30_2,temp_r31,temp_r31_2;
    s32 var_r3; u32 var_ctr;
    void *temp_r9_4,*temp_r9_6,*temp_r10_2,*temp_r11_3,*temp_r12_2,*temp_r26_2,*temp_r28_2;
    u8 *var_r27,*var_r5;
    var_r5 = arg2;
    temp_r7 = arg0 >> 3; temp_r6 = temp_r7 * 2;
    temp_r10 = arg0 & 0xFFFFFFF8; temp_r26 = (arg0 * 2) & 0xFFFFFFF0;
    temp_r9 = (temp_r7 << 2) + temp_r6;
    temp_f6 = -M2C_FIELD(arg1, f32 *, 4);
    temp_r12 = ((temp_r7 * 4) + 1) * 4;
    temp_r11 = temp_r9 * 4; temp_r3 = (temp_r6 + 1) * 4;
    temp_r9_2 = (temp_r9 + 1) * 4;
    temp_f5 = M2C_FIELD(arg1, f32 *, temp_r12);
    temp_r8 = temp_r7 - 2;
    temp_f7 = M2C_FIELD(arg1, f32 *, 0);
    temp_f0 = M2C_FIELD(arg1, f32 *, temp_r26);
    temp_f9 = temp_f6 - temp_f5;
    temp_f4 = M2C_FIELD(arg1, f32 *, temp_r10);
    temp_f3 = M2C_FIELD(arg1, f32 *, temp_r11);
    temp_f8 = temp_f7 + temp_f0; temp_f7_2 = temp_f7 - temp_f0;
    temp_f10 = temp_f4 + temp_f3;
    temp_f2 = M2C_FIELD(arg1, f32 *, temp_r3);
    temp_f3_2 = temp_f4 - temp_f3;
    temp_f1 = M2C_FIELD(arg1, f32 *, temp_r9_2);
    sp10 = lbl_80561218;
    temp_f11 = temp_f2 + temp_f1; temp_f12 = temp_f2 - temp_f1;
    var_r27 = arg1 + 8; spC = lbl_80561230;
    M2C_FIELD(arg1, f32 *, 0) = (f32)(temp_f8 + temp_f10);
    var_f24 = spC;
    M2C_FIELD(arg1, f32 *, 4) = (f32)(temp_f9 - temp_f11);
    temp_f2_2 = temp_f6 + temp_f5;
    M2C_FIELD(arg1, f32 *, temp_r10) = temp_f8 - temp_f10;
    M2C_FIELD(arg1, f32 *, temp_r3) = temp_f9 + temp_f11;
    var_r3 = 2;
    M2C_FIELD(arg1, f32 *, temp_r26) = temp_f7_2 + temp_f12;
    M2C_FIELD(arg1, f32 *, temp_r12) = temp_f2_2 + temp_f3_2;
    M2C_FIELD(arg1, f32 *, temp_r11) = temp_f7_2 - temp_f12;
    M2C_FIELD(arg1, f32 *, temp_r9_2) = temp_f2_2 - temp_f3_2;
    sp8 = lbl_80561218;
    temp_f15 = M2C_FIELD(var_r5, f32 *, 8);
    sp14 = M2C_FIELD(var_r5, f32 *, 4);
    temp_f14 = M2C_FIELD(var_r5, f32 *, 0xC);
    var_ctr = (u32)(temp_r8 + 1) >> 2U;
    if (temp_r8 > 2) {
      do {
        temp_r0 = var_r3 + temp_r6; temp_r9_3 = temp_r0 + temp_r6;
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
        temp_f11_2 = M2C_FIELD(arg1, f32 *, temp_r0_2);
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
        sp30 = (f64)(temp_f2_3 - temp_f3_3);
        temp_f9_3 = temp_f10_2 - temp_f9_2;
        temp_f8_2 = M2C_FIELD(temp_r9_4, f32 *, 8);
        temp_f0_2 = temp_f29 + temp_f30;
        temp_f7_3 = M2C_FIELD(temp_r26_2, f32 *, 8);
        var_r5 += 0x10;
        temp_f6_2 = M2C_FIELD(temp_r9_4, f32 *, 0xC);
        temp_f5_2 = M2C_FIELD(temp_r26_2, f32 *, 0xC);
        temp_f2_4 = temp_f8_2 + temp_f7_3;
        sp18 = (f64)temp_f3_4;
        temp_f3_5 = temp_f6_2 + temp_f5_2;
        M2C_FIELD(var_r27, f32 *, 0) = (f32)(temp_f2_3 + temp_f3_3);
        temp_f4_2 = temp_f17 - temp_f16;
        sp10 = temp_f18; sp38 = (f64)temp_f4_2;
        spC = temp_f20; sp20 = (f64)(temp_f0_2 + temp_f2_4);
        sp28 = (f64)(temp_f1_2 - temp_f3_5); sp8 = temp_f22;
        M2C_FIELD(var_r27, f32 *, 4) = temp_f4_2;
        M2C_FIELD(var_r27, f32 *, 8) = (f32)sp20;
        temp_f17_2 = temp_f14 * (f32)sp18;
        M2C_FIELD(var_r27, f32 *, 0xC) = (f32)sp28;
        temp_f2_5 = temp_f15 * temp_f19;
        temp_f19_2 = temp_f25 - temp_f26;
        M2C_FIELD(temp_r9_4, f32 *, 0) = (f32)sp30;
        temp_f16_2 = temp_f15 * temp_f21;
        temp_f21_2 = temp_f29 - temp_f30;
        M2C_FIELD(temp_r9_4, f32 *, 4) = (f32)(temp_f17 + temp_f16);
        temp_f4_3 = temp_f14 * temp_f24;
        var_f24 = -temp_f23;
        M2C_FIELD(temp_r9_4, f32 *, 8) = (f32)(temp_f0_2 - temp_f2_4);
        temp_f0_3 = temp_f27 + temp_f28;
        temp_f23_2 = temp_f8_2 - temp_f7_3;
        temp_f25_2 = temp_f6_2 - temp_f5_2;
        temp_f6_3 = temp_f19_2 + temp_f9_3;
        temp_r0_3 = temp_r6 - var_r3;
        temp_f7_4 = temp_f0_3 + temp_f11_3;
        temp_r28 = temp_r0_3 + temp_r6;
        temp_r11_2 = temp_r28 + temp_r6;
        M2C_FIELD(temp_r9_4, f32 *, 0xC) = (f32)(temp_f1_2 + temp_f3_5);
        temp_f8_3 = temp_f21_2 + temp_f25_2;
        temp_r9_5 = (temp_r11_2 + temp_r6) * 4;
        temp_f12_3 = temp_f13_2 + temp_f23_2;
        temp_r0_4 = temp_r28 * 4;
        temp_f11_4 = temp_f0_3 - temp_f11_3;
        temp_r28_2 = arg1 + (temp_r0_3 * 4);
        M2C_FIELD(temp_r12_2, f32 *, 0) = (f32)((temp_f2_5 * temp_f6_3) - (temp_f16_2 * temp_f7_4));
        temp_f10_3 = temp_f19_2 - temp_f9_3;
        temp_r10_2 = arg1 + (temp_r11_2 * 4);
        temp_r11_3 = arg1 + temp_r0_4;
        M2C_FIELD(temp_r12_2, f32 *, 4) = (f32)((temp_f2_5 * temp_f7_4) + (temp_f16_2 * temp_f6_3));
        M2C_FIELD(temp_r12_2, f32 *, 8) = (f32)((temp_f18 * temp_f8_3) - (temp_f20 * temp_f12_3));
        temp_f0_4 = temp_f21_2 - temp_f25_2;
        temp_f1_3 = temp_f13_2 - temp_f23_2;
        M2C_FIELD(temp_r12_2, f32 *, 0xC) = (f32)((temp_f18 * temp_f12_3) + (temp_f20 * temp_f8_3));
        M2C_FIELD(temp_r26_2, f32 *, 0) = (f32)((temp_f17_2 * temp_f10_3) + (temp_f4_3 * temp_f11_4));
        M2C_FIELD(temp_r26_2, f32 *, 4) = (f32)((temp_f17_2 * temp_f11_4) - (temp_f4_3 * temp_f10_3));
        M2C_FIELD(temp_r26_2, f32 *, 8) = (f32)((temp_f22 * temp_f0_4) + (var_f24 * temp_f1_3));
        M2C_FIELD(temp_r26_2, f32 *, 0xC) = (f32)((temp_f22 * temp_f1_3) - (var_f24 * temp_f0_4));
        temp_f9_4 = -M2C_FIELD(temp_r28_2, f32 *, 4);
        temp_f5_3 = M2C_FIELD(temp_r10_2, f32 *, 4);
        temp_f12_4 = -M2C_FIELD(temp_r28_2, f32 *, -4);
        temp_f6_4 = M2C_FIELD(temp_r10_2, f32 *, -4);
        temp_f1_4 = M2C_FIELD(temp_r28_2, f32 *, 0);
        temp_f0_5 = M2C_FIELD(temp_r10_2, f32 *, 0);
        temp_f30_2 = temp_f9_4 - temp_f5_3;
        temp_f7_5 = M2C_FIELD(arg1, f32 *, temp_r9_5);
        temp_r9_6 = temp_r9_5 + arg1;
        temp_f8_4 = M2C_FIELD(arg1, f32 *, temp_r0_4);
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
        M2C_FIELD(temp_r28_2, f32 *, 0) = (f32)(temp_f23_3 + temp_f31_2);
        var_r3 += 4;
        M2C_FIELD(temp_r28_2, f32 *, 4) = (f32)(temp_f30_2 - temp_f6_5);
        M2C_FIELD(temp_r28_2, f32 *, -8) = (f32)(temp_f9_5 + temp_f13_4);
        temp_f6_6 = temp_f29_2 - temp_f28_2;
        M2C_FIELD(temp_r28_2, f32 *, -4) = (f32)(temp_f10_4 - temp_f19_3);
        temp_f26_3 = temp_f27_2 - temp_f26_2;
        M2C_FIELD(temp_r11_3, f32 *, 0) = (f32)(temp_f23_3 - temp_f31_2);
        temp_f3_7 = temp_f3_6 - temp_f8_5;
        M2C_FIELD(temp_r11_3, f32 *, 4) = (f32)(temp_f30_2 + temp_f6_5);
        temp_f7_7 = temp_f5_4 - temp_f7_6;
        M2C_FIELD(temp_r11_3, f32 *, -8) = (f32)(temp_f9_5 - temp_f13_4);
        M2C_FIELD(temp_r11_3, f32 *, -4) = (f32)(temp_f10_4 + temp_f19_3);
        temp_f9_6 = temp_f11_6 + temp_f26_3;
        temp_f1_7 = temp_f11_6 - temp_f26_3;
        M2C_FIELD(temp_r10_2, f32 *, 0) = (f32)((temp_f16_2 * temp_f0_7) - (temp_f2_5 * temp_f1_6));
        temp_f13_5 = temp_f12_5 + temp_f6_6;
        temp_f5_5 = temp_f12_5 - temp_f6_6;
        M2C_FIELD(temp_r10_2, f32 *, 4) = (f32)((temp_f16_2 * temp_f1_6) + (temp_f2_5 * temp_f0_7));
        M2C_FIELD(temp_r10_2, f32 *, -8) = (f32)((temp_f20 * temp_f9_6) - (temp_f18 * temp_f13_5));
        M2C_FIELD(temp_r10_2, f32 *, -4) = (f32)((temp_f20 * temp_f13_5) + (temp_f18 * temp_f9_6));
        M2C_FIELD(temp_r9_6, f32 *, 0) = (f32)((temp_f4_3 * temp_f3_7) + (temp_f17_2 * temp_f7_7));
        M2C_FIELD(temp_r9_6, f32 *, 4) = (f32)((temp_f4_3 * temp_f7_7) - (temp_f17_2 * temp_f3_7));
        M2C_FIELD(temp_r9_6, f32 *, -8) = (f32)((var_f24 * temp_f1_7) + (temp_f22 * temp_f5_5));
        M2C_FIELD(temp_r9_6, f32 *, -4) = (f32)((var_f24 * temp_f5_5) - (temp_f22 * temp_f1_7));
        var_ctr -= 1;
      } while (var_ctr != 0);
    }
    temp_r3_2 = temp_r7 * 3; temp_r5 = temp_r7 * 5;
    temp_r11_4 = temp_r8 * 4; temp_r6_2 = temp_r7 * 7;
    temp_r10_3 = (temp_r7 - 1) * 4;
    temp_r26_3 = (temp_r5 - 2) * 4;
    temp_r29 = (temp_r3_2 - 2) * 4;
    temp_r30 = (temp_r6_2 - 2) * 4;
    temp_r31 = (temp_r5 - 1) * 4;
    temp_r12_3 = (temp_r6_2 - 1) * 4;
    temp_r9_7 = (temp_r3_2 - 1) * 4;
    temp_f7_8 = -M2C_FIELD(arg1, f32 *, temp_r10_3);
    temp_f6_7 = M2C_FIELD(arg1, f32 *, temp_r31);
    temp_f9_7 = M2C_FIELD(arg1, f32 *, temp_r11_4);
    temp_f8_6 = M2C_FIELD(arg1, f32 *, temp_r26_3);
    temp_f5_6 = M2C_FIELD(arg1, f32 *, temp_r29);
    temp_f17_3 = temp_f7_8 - temp_f6_7;
    temp_f4_4 = M2C_FIELD(arg1, f32 *, temp_r30);
    temp_f16_3 = temp_f9_7 + temp_f8_6;
    temp_f3_8 = M2C_FIELD(arg1, f32 *, temp_r9_7);
    temp_f2_6 = M2C_FIELD(arg1, f32 *, temp_r12_3);
    temp_f19_4 = temp_f5_6 + temp_f4_4;
    temp_f20_2 = temp_f5_6 - temp_f4_4;
    temp_f0_8 = temp_f3_8 + temp_f2_6;
    temp_r27 = temp_r7 * 0x14;
    temp_f21_3 = temp_f3_8 - temp_f2_6;
    temp_f8_7 = temp_f9_7 - temp_f8_6;
    temp_f18_2 = temp_f7_8 + temp_f6_7;
    temp_r28_3 = (temp_r5 + 1) * 4;
    M2C_FIELD(arg1, f32 *, temp_r11_4) = temp_f16_3 + temp_f19_4;
    temp_f2_7 = temp_f15 * (spC + sp14);
    temp_r11_5 = temp_r7 * 4;
    temp_f12_6 = temp_f18_2 + temp_f20_2;
    M2C_FIELD(arg1, f32 *, temp_r10_3) = temp_f17_3 - temp_f0_8;
    temp_f3_9 = temp_f14 * (sp8 - sp14);
    temp_f4_5 = temp_f14 * (var_f24 - sp14);
    temp_r10_4 = (temp_r7 + 1) * 4;
    temp_f1_8 = temp_f15 * (sp10 + sp14);
    M2C_FIELD(arg1, f32 *, temp_r29) = temp_f16_3 - temp_f19_4;
    temp_f9_8 = temp_f8_7 + temp_f21_3;
    temp_f11_7 = temp_f8_7 - temp_f21_3;
    M2C_FIELD(arg1, f32 *, temp_r9_7) = temp_f17_3 + temp_f0_8;
    temp_f10_5 = temp_f18_2 - temp_f20_2;
    M2C_FIELD(arg1, f32 *, temp_r26_3) = (temp_f1_8 * temp_f9_8) - (temp_f2_7 * temp_f12_6);
    M2C_FIELD(arg1, f32 *, temp_r31) = (temp_f1_8 * temp_f12_6) + (temp_f2_7 * temp_f9_8);
    M2C_FIELD(arg1, f32 *, temp_r30) = (temp_f3_9 * temp_f11_7) + (temp_f4_5 * temp_f10_5);
    M2C_FIELD(arg1, f32 *, temp_r12_3) = (temp_f3_9 * temp_f10_5) - (temp_f4_5 * temp_f11_7);
    temp_f11_8 = M2C_FIELD(arg1, f32 *, temp_r11_5);
    temp_f5_7 = M2C_FIELD(arg1, f32 *, temp_r27);
    temp_f12_7 = temp_f11_8 + temp_f5_7;
    temp_r29_2 = temp_r7 * 0x1C; temp_r30_2 = temp_r7 * 0xC;
    temp_f8_8 = M2C_FIELD(arg1, f32 *, temp_r30_2);
    temp_f7_9 = M2C_FIELD(arg1, f32 *, temp_r29_2);
    temp_r9_8 = (temp_r3_2 + 1) * 4;
    temp_r31_2 = (temp_r6_2 + 1) * 4;
    temp_f13_6 = temp_f11_8 - temp_f5_7;
    temp_f10_6 = -M2C_FIELD(arg1, f32 *, temp_r10_4);
    temp_f9_9 = M2C_FIELD(arg1, f32 *, temp_r28_3);
    temp_f14_2 = temp_f8_8 + temp_f7_9;
    temp_f6_8 = M2C_FIELD(arg1, f32 *, temp_r9_8);
    temp_f5_8 = M2C_FIELD(arg1, f32 *, temp_r31_2);
    temp_f11_9 = temp_f10_6 - temp_f9_9;
    temp_f16_4 = temp_f6_8 - temp_f5_8;
    temp_f5_9 = temp_f6_8 + temp_f5_8;
    M2C_FIELD(arg1, f32 *, temp_r11_5) = temp_f12_7 + temp_f14_2;
    temp_f10_7 = temp_f10_6 + temp_f9_9;
    temp_f15_2 = temp_f8_8 - temp_f7_9;
    temp_f8_9 = temp_f10_7 + temp_f15_2;
    temp_r12_4 = (temp_r5 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r10_4) = temp_f11_9 - temp_f5_9;
    temp_f7_10 = temp_f13_6 + temp_f16_4;
    M2C_FIELD(arg1, f32 *, temp_r30_2) = temp_f12_7 - temp_f14_2;
    temp_f9_10 = temp_f13_6 - temp_f16_4;
    temp_r11_6 = (temp_r7 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r9_8) = temp_f11_9 + temp_f5_9;
    temp_f10_8 = temp_f10_7 - temp_f15_2;
    temp_r9_9 = (temp_r7 + 3) * 4;
    temp_f6_9 = -sp14;
    temp_r10_5 = (temp_r5 + 3) * 4;
    temp_r8_2 = (temp_r6_2 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r27) = sp14 * (temp_f7_10 - temp_f8_9);
    temp_r6_3 = (temp_r3_2 + 2) * 4;
    M2C_FIELD(arg1, f32 *, temp_r28_3) = sp14 * (temp_f8_9 + temp_f7_10);
    temp_r3_3 = (temp_r6_2 + 3) * 4;
    temp_r0_5 = (temp_r3_2 + 3) * 4;
    M2C_FIELD(arg1, f32 *, temp_r29_2) = temp_f6_9 * (temp_f9_10 + temp_f10_8);
    M2C_FIELD(arg1, f32 *, temp_r31_2) = temp_f6_9 * (temp_f10_8 - temp_f9_10);
    temp_f11_10 = M2C_FIELD(arg1, f32 *, temp_r11_6);
    temp_f9_11 = -M2C_FIELD(arg1, f32 *, temp_r9_9);
    temp_f10_9 = M2C_FIELD(arg1, f32 *, temp_r12_4);
    temp_f8_10 = M2C_FIELD(arg1, f32 *, temp_r10_5);
    temp_f12_8 = temp_f11_10 + temp_f10_9;
    temp_f7_11 = M2C_FIELD(arg1, f32 *, temp_r6_3);
    temp_f13_7 = temp_f9_11 - temp_f8_10;
    temp_f6_10 = M2C_FIELD(arg1, f32 *, temp_r8_2);
    temp_f8_11 = temp_f9_11 + temp_f8_10;
    temp_f5_10 = M2C_FIELD(arg1, f32 *, temp_r0_5);
    temp_f0_9 = M2C_FIELD(arg1, f32 *, temp_r3_3);
    temp_f11_11 = temp_f11_10 - temp_f10_9;
    temp_f9_12 = temp_f7_11 + temp_f6_10;
    temp_f14_3 = temp_f5_10 + temp_f0_9;
    temp_f15_3 = temp_f5_10 - temp_f0_9;
    temp_f7_12 = temp_f7_11 - temp_f6_10;
    temp_f10_10 = temp_f11_11 + temp_f15_3;
    temp_f6_11 = temp_f8_11 + temp_f7_12;
    M2C_FIELD(arg1, f32 *, temp_r11_6) = temp_f12_8 + temp_f9_12;
    temp_f9_13 = temp_f11_11 - temp_f15_3;
    temp_f11_12 = temp_f8_11 - temp_f7_12;
    M2C_FIELD(arg1, f32 *, temp_r9_9) = temp_f13_7 - temp_f14_3;
    M2C_FIELD(arg1, f32 *, temp_r6_3) = temp_f12_8 - temp_f9_12;
    M2C_FIELD(arg1, f32 *, temp_r0_5) = temp_f13_7 + temp_f14_3;
    M2C_FIELD(arg1, f32 *, temp_r12_4) = (temp_f2_7 * temp_f10_10) - (temp_f1_8 * temp_f6_11);
    M2C_FIELD(arg1, f32 *, temp_r10_5) = (temp_f2_7 * temp_f6_11) + (temp_f1_8 * temp_f10_10);
    M2C_FIELD(arg1, f32 *, temp_r8_2) = (temp_f4_5 * temp_f9_13) + (temp_f3_9 * temp_f11_12);
    M2C_FIELD(arg1, f32 *, temp_r3_3) = (temp_f4_5 * temp_f11_12) - (temp_f3_9 * temp_f9_13);
}

extern void fn_801233F8(s32, volatile f32 *, f32 *);
void fn_80122E08(s32 length, void *data, s32 twiddleOffset, void *twiddleBase) {
    s32 halfLength;
    s32 quarterLength = length >> 2;
    /* Recursively split a complex FFT block into four quarters, applying the
       stage twiddles and falling back to the leaf transform for small blocks. */
    halfLength = quarterLength * 2;
    fn_801233F8(length, (volatile f32 *)data, (f32 *)((u8 *)twiddleBase + (twiddleOffset - halfLength) * 4));
    if (length > 0x200) {
        fn_80122E08(quarterLength, data, twiddleOffset, twiddleBase);
        fn_80122ED8(quarterLength, (u8 *)data + quarterLength * 4, twiddleOffset, twiddleBase);
        fn_80122E08(quarterLength, (u8 *)data + (halfLength * 4), twiddleOffset, twiddleBase);
        fn_80122E08(quarterLength, (u8 *)data + ((quarterLength * 3) << 2), twiddleOffset, twiddleBase);
        return;
    }
    fn_80122FA4(length, data, twiddleOffset, twiddleBase);
}

#pragma scheduling invalid_target
extern void fn_801237C4(s32, void *, void *);
extern void fn_801231B8(s32, void *, s32, void *);
extern void fn_80123DC0(s32, void *, s32, void *);
#pragma scheduling 604
void fn_80122ED8(s32 length, void *data, s32 twiddleOffset, void *twiddleBase) {
    s32 quarterLength = length >> 2;
    /* Mirror of fn_80122E08: recursively split a complex FFT block into four
       quarters with stage twiddles, falling back to the leaf transform when small. */
    fn_801237C4(length, data, (u8 *)twiddleBase + (twiddleOffset - length) * 4);
    if (length > 0x200) {
        fn_80122E08(quarterLength, data, twiddleOffset, twiddleBase);
        fn_80122ED8(quarterLength, (u8 *)data + quarterLength * 4, twiddleOffset, twiddleBase);
        fn_80122E08(quarterLength, (u8 *)data + quarterLength * 8, twiddleOffset, twiddleBase);
        fn_80122ED8(quarterLength, (u8 *)data + ((quarterLength * 3) << 2), twiddleOffset, twiddleBase);
        return;
    }
    fn_801231B8(length, data, twiddleOffset, twiddleBase);
}
#pragma scheduling reset
void fn_80122FA4(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    s32 n = arg0 >> 2;
    f32 *a = (f32 *)arg1;
    f32 *w = (f32 *)arg3;
    s32 k, m;
    f32 *pa;
    s32 step;
    while (n > 0x80) {
        f32 *pb;
        m = n;
        pa = w + (arg2 - (n >> 1));
        pb = w + (arg2 - n);
        for (; m < arg0; m *= 4) {
            step = m * 4;
            for (k = m - n; k < arg0; k += step) {
                fn_801233F8(n, (volatile f32 *)(a + k), pa);
                fn_801237C4(n, a + (m + k), pb);
                fn_801233F8(n, (volatile f32 *)(a + (k + m * 2)), pa);
            }
        }
        fn_801233F8(n, (volatile f32 *)(a + (arg0 - n)), pa);
        n >>= 2;
    }
    {
        f32 *pb;
        m = n;
        pa = w + (arg2 - (n >> 1));
        pb = w + (arg2 - n);
        for (; m < arg0; m *= 4) {
            step = m * 4;
            for (k = m - n; k < arg0; k += step) {
                f32 *q;
                fn_801233F8(n, (volatile f32 *)(a + k), pa);
                fn_80123CEC(n, a + k, arg2, w);
                q = a + (m + k);
                fn_801237C4(n, q, pb);
                fn_80123DC0(n, q, arg2, w);
                q = a + (k + m * 2);
                fn_801233F8(n, (volatile f32 *)q, pa);
                fn_80123CEC(n, q, arg2, w);
            }
        }
        {
            f32 *q = a + (arg0 - n);
            fn_801233F8(n, (volatile f32 *)q, pa);
            fn_80123CEC(n, q, arg2, w);
        }
    }
}

void fn_801231B8(s32 n, void *data, s32 index, void *table) {
    s32 size, half;
    s32 step, i, di, step8;
    f32 *p;
    half = n >> 1;
    size = n >> 2;
    while (size > 0x80) {
        for (step = size; step < half; step *= 4) {
            di = step * 2;
            step8 = step * 8;
            for (i = step - size, p = (f32 *)((u8 *)data + i * 4); i < half; i += di, p = (f32 *)((u8 *)p + step8)) {
                fn_801233F8(size, p, (f32 *)((u8 *)table + (index - (size >> 1)) * 4));
                fn_801233F8(size, (f32 *)((u8 *)data + (half + i) * 4), (f32 *)((u8 *)table + (index - (size >> 1)) * 4));
            }
            for (i = di - size, p = (f32 *)((u8 *)data + i * 4); i < half; i += di * 2, p = (f32 *)((u8 *)p + step * 16)) {
                fn_801237C4(size, p, (f32 *)((u8 *)table + (index - size) * 4));
                fn_801237C4(size, (f32 *)((u8 *)data + (half + i) * 4), (f32 *)((u8 *)table + (index - size) * 4));
            }
        }
        size >>= 2;
    }
    for (step = size; step < half; step *= 4) {
        di = step * 2;
        step8 = step * 8;
        for (i = step - size, p = (f32 *)((u8 *)data + i * 4); i < half; i += di, p = (f32 *)((u8 *)p + step8)) {
            fn_801233F8(size, p, (f32 *)((u8 *)table + (index - (size >> 1)) * 4));
            fn_80123CEC(size, p, index, table);
            fn_801233F8(size, (f32 *)((u8 *)data + (half + i) * 4), (f32 *)((u8 *)table + (index - (size >> 1)) * 4));
            fn_80123CEC(size, (f32 *)((u8 *)data + (half + i) * 4), index, table);
        }
        for (i = di - size, p = (f32 *)((u8 *)data + i * 4); i < half; i += di * 2, p = (f32 *)((u8 *)p + step * 16)) {
            fn_801237C4(size, p, (f32 *)((u8 *)table + (index - size) * 4));
            fn_80123DC0(size, p, index, table);
            fn_801237C4(size, (f32 *)((u8 *)data + (half + i) * 4), (f32 *)((u8 *)table + (index - size) * 4));
            fn_80123DC0(size, (f32 *)((u8 *)data + (half + i) * 4), index, table);
        }
    }
}

#pragma scheduling off
void fn_801233F8(s32 arg0, volatile f32 *input, f32 *arg2) {
    f32 *arg1 = (f32 *)input;
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
    s32 temp_r0, temp_r0_2, temp_r0_3, temp_r3, temp_r4, temp_r5, temp_r6, temp_r6_2, temp_r7, temp_r7_2;
    s32 temp_r8, temp_r8_2, temp_r8_3, temp_r8_5, temp_r9, temp_r9_2, temp_r9_4;
    s32 temp_r10, temp_r10_2, temp_r10_3, temp_r10_5, temp_r11, temp_r11_2, temp_r12, temp_r28, temp_r29, temp_r31;
    register s32 var_r3;
    register u32 var_ctr;
    u8 *var_r30, *var_r5;
    f32 *p9, *p10, *p8;
    s32 temp_r8_4, temp_r9_3, temp_r10_4, temp_r11_3, temp_r12_2, temp_r29_2;
    s32 temp_r31_2;
    s32 temp_r0_4, temp_r11f, temp_r3f, temp_r12f, temp_r7p;

    temp_r7 = arg0 >> 3;
    temp_r0_4 = temp_r7 - 1;
    temp_r10 = arg0 & 0xFFFFFFF8;
    temp_r6 = temp_r7 * 2;
    temp_r4 = temp_r7 * 4;
    temp_r31 = (arg0 * 2) & 0xFFFFFFF0;
    temp_r11 = temp_r4 + temp_r6;
    temp_r9 = temp_r11 + 1;
    temp_r8 = temp_r4 + 1;
    temp_r3 = temp_r6 + 1;
    temp_r12 = temp_r8 * 4;
    temp_r11_2 = temp_r11 * 4;
    temp_r8 = temp_r3 * 4;
    temp_r9 = temp_r9 * 4;
    var_ctr = (u32)temp_r0_4 >> 1;
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
            p9 = (f32 *)((u8 *)arg1 + temp_r9_2);
            temp_f9_3 = p9[0];
            temp_r9_3 = temp_r9_2;
            p10 = (f32 *)((u8 *)arg1 + temp_r10_3);
            temp_f5_5 = p10[0];
            temp_r10_4 = temp_r10_3;
            temp_f8_4 = p9[1];
            temp_f7_2 = p10[1];
            temp_f10_3 = temp_f9_3 + temp_f5_5;
            temp_f9_4 = temp_f9_3 - temp_f5_5;
            temp_f6_5 = *(f32 *)((u8 *)arg1 + temp_r0_3);
            p8 = (f32 *)((u8 *)arg1 + temp_r8_3);
            temp_f5_6 = p8[0];
            temp_r8_4 = temp_r8_3;
            temp_f12_3 = temp_f8_4 + temp_f7_2;
            temp_f13_2 = temp_f8_4 - temp_f7_2;
            temp_f7_3 = temp_f6_5 + temp_f5_6;
            temp_f30_2 = temp_f6_5 - temp_f5_6;
            temp_f8_5 = *(f32 *)((u8 *)arg1 + temp_r29_2 + 4);
            temp_f6_6 = p8[1];
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
        } while (--var_ctr != 0);
    }

    temp_r11f = temp_r7 + temp_r6;
    temp_r9_4 = temp_r7 * 4;
    temp_r3f = temp_r11f + temp_r6;
    temp_r7p = temp_r7 + 1;
    temp_r12f = temp_r3f + temp_r6;
    temp_r5 = temp_r11f * 4;
    temp_r10_5 = temp_r3f * 4;
    temp_r8_5 = (temp_r3f + 1) * 4;
    temp_r6_2 = temp_r12f * 4;
    temp_r3 = (temp_r12f + 1) * 4;
    temp_r0_3 = (temp_r11f + 1) * 4;
    temp_r7_2 = temp_r7p * 4;
    temp_f3_5 = *(f32 *)((u8 *)arg1 + temp_r9_4);
    temp_f1_6 = *(f32 *)((u8 *)arg1 + temp_r10_5);
    temp_f6_6 = *(f32 *)((u8 *)arg1 + temp_r5);
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

void fn_801237C4(s32 arg0, void *arg1, void *arg2) {
    #pragma opt_lifetimes off
    f32 a0,a0_2,a0_3,a0_4,a0_5,a0_6,a10,a10_2,a10_3,a10_4,a10_5,a10_6,a11,a11_2,a11_3,a11_4,a11_5,a11_6,a11_7,a12,a12_2,a12_3,a12_4,a12_5,a12_6,a12_7,a12_8,a13,a13_2,a13_3,a13_4,a13_5,a13_6,a13_7,a1,a1_2,a1_3,a1_4,a1_5,a1_6,a1_7,a1_8,a23,a24,a24_2,a24_3,a24_4,a24_5,a25,a25_2,a25_3,a25_4,a25_5,a26,a26_2,a26_3,a27,a27_2,a27_3,a28,a28_2,a29,a2,a2_2,a2_3,a2_4,a2_5,a2_6,a30,a31,a3,a3_2,a3_3,a3_4,a3_5,a3_6,a3_7,a4,a4_2,a4_3,a4_4,a4_5,a4_6,a4_7,a4_8,a5,a5_2,a5_3,a5_4,a5_5,a5_6,a5_7,a5_8,a6,a6_2,a6_3,a6_4,a6_5,a7,a7_2,a7_3,a7_4,a7_5,a7_6,a8,a8_2,a8_3,a8_4,a9,a9_2,a9_3;
    s32 r0,r10,r10_2,r10_3,r10_4,r10_6,r11,r11_3,r12,r12_3,r24,r24_2,r25,r26,r31,r31_3,r3,r6,r7,r7_2,r8,r8_2,r9,r9_2,r9_3,r9_4,r9_6,v6; u32 ctr;
    void *p105,*p112,*p122,*p262,*p27,*p312,*p95,*p28,*p29,*p30;
    r8 = arg0 >> 3;
    r12 = (arg0 * 2) & 0xFFFFFFF0; r0 = arg0 & 0xFFFFFFF8;
    r7 = r8 * 2; r24 = r8 * 6;
    a3 = *(f32 *)((u8 *)arg1 + r0);
    r10 = r24 * 4; r11 = (r24 + 1) * 4; r3 = (r7 + 1) * 4;
    a2 = *(f32 *)((u8 *)arg1 + r11);
    r31 = ((r8 * 4) + 1) * 4;
    a1 = *(f32 *)((u8 *)arg1 + r3);
    a0 = *(f32 *)((u8 *)arg1 + r10);
    a4 = a3 - a2; a10 = a3 + a2;
    a9 = *(f32 *)((u8 *)arg2 + 4);
    a2_2 = a1 + a0; a8 = *(f32 *)arg1; a1_2 = a1 - a0;
    a7 = *(f32 *)((u8 *)arg1 + r31); a6 = *(f32 *)((u8 *)arg1 + 4);
    a5 = *(f32 *)((u8 *)arg1 + r12);
    p30 = arg2; p29 = (void *)((u8 *)arg2 + r12); p28 = (void *)((u8 *)arg1 + 8);
    a10_2 = a8 - a7; a3_2 = a9 * (a4 - a2_2);
    v6 = 2; a11 = a6 + a5; a12 = a9 * (a2_2 + a4); a8_2 = a8 + a7;
    *(f32 *)arg1 = a10_2 + a3_2;
    a7_2 = a9 * (a1_2 + a10); a4_2 = a9 * (a10 - a1_2);
    *(f32 *)((u8 *)arg1 + 4) = a11 + a12;
    a5_2 = a6 - a5;
    *(f32 *)((u8 *)arg1 + r0) = a10_2 - a3_2;
    *(f32 *)((u8 *)arg1 + r3) = a11 - a12;
    *(f32 *)((u8 *)arg1 + r12) = a8_2 - a7_2;
    *(f32 *)((u8 *)arg1 + r31) = a5_2 + a4_2;
    *(f32 *)((u8 *)arg1 + r10) = a8_2 + a7_2;
    *(f32 *)((u8 *)arg1 + r11) = a5_2 - a4_2;
    ctr = (u32) (r8 - 1) >> 1U;
    if (r8 > 2) {
        do {
            r9 = v6 + r7; r26 = r7 - v6; r10_2 = r9 + r7;
            a13 = *(f32 *)((u8 *)p28 + 4);
            p312 = (void *)((u8 *)arg1 + (r9 * 4));
            r10_3 = r10_2 * 4; r9_2 = (r10_2 + r7) * 4;
            a12_2 = *(f32 *)((u8 *)arg1 + r10_3);
            p112 = (void *)((u8 *)arg1 + r10_3);
            a5_3 = *(f32 *)p28;
            p122 = (void *)((u8 *)arg1 + r9_2);
            a0_2 = *(f32 *)((u8 *)p112 + 4);
            a10_3 = *(f32 *)((u8 *)arg1 + r9_2);
            a6_2 = a13 + a12_2; a11_2 = *(f32 *)((u8 *)p312 + 4);
            a4_3 = a5_3 - a0_2; a2_3 = *(f32 *)((u8 *)p30 + 0x10);
            r25 = r26 + r7; a3_3 = *(f32 *)((u8 *)p30 + 0x14);
            a8_3 = *(f32 *)p312; a24 = a11_2 + a10_3;
            a1_3 = *(f32 *)((u8 *)p122 + 4); a25 = a8_3 - a1_3;
            a0_3 = a5_3 + a0_2; a7_3 = *(f32 *)((u8 *)p29 - 0x10);
            a5_4 = -*(f32 *)((u8 *)p30 + 0x1C); a26 = a13 - a12_2;
            a6_3 = *(f32 *)((u8 *)p29 - 0xC); a1_4 = a8_3 + a1_3;
            a9_2 = *(f32 *)((u8 *)p29 - 8); a8_4 = -*(f32 *)((u8 *)p29 - 4);
            a27 = a11_2 - a10_3; r24_2 = r25 + r7;
            a4_4 = *(f32 *)((u8 *)p30 + 0x18);
            r10_4 = r24_2 * 4; r9_3 = r26 * 4;
            a24_2 = (a2_3 * a4_3) - (a3_3 * a6_2);
            a13_2 = (a6_3 * a25) - (a7_3 * a24);
            p27 = (void *)((u8 *)arg1 + r10_4);
            a25_2 = (a2_3 * a6_2) + (a3_3 * a4_3);
            a23 = (a6_3 * a24) + (a7_3 * a25);
            p262 = (void *)((u8 *)arg1 + r9_3);
            a11_3 = a24_2 + a13_2; a28 = a24_2 - a13_2;
            p30 = (void *)((u8 *)p30 + 0x10);
            *(f32 *)p28 = a11_3; *(f32 *)((u8 *)p28 + 4) = a25_2 + a23;
            a12_3 = a8_4 * a1_4; p29 = (void *)((u8 *)p29 - 0x10);
            *(f32 *)p312 = a28;
            a12_4 = a12_3 + (a9_2 * a27);
            *(f32 *)((u8 *)p312 + 4) = a25_2 - a23;
            a24_3 = (a4_4 * a0_3) + (a5_4 * a26);
            a11_4 = (a4_4 * a26) - (a5_4 * a0_3);
            a13_3 = (a8_4 * a27) - (a9_2 * a1_4);
            *(f32 *)p112 = a24_3 + a12_4; *(f32 *)((u8 *)p112 + 4) = a11_4 + a13_3;
            *(f32 *)p122 = a24_3 - a12_4; *(f32 *)((u8 *)p122 + 4) = a11_4 - a13_3;
            a11_5 = *(f32 *)((u8 *)arg1 + r9_3);
            a0_4 = *(f32 *)((u8 *)p27 + 4); a10_4 = *(f32 *)((u8 *)p262 + 4);
            a1_5 = *(f32 *)((u8 *)arg1 + r10_4);
            a26_2 = a11_5 - a0_4; a27_2 = a10_4 + a1_5;
            a28_2 = a10_4 - a1_5; a0_5 = a11_5 + a0_4;
            p105 = (void *)((u8 *)arg1 + ((r24_2 + r7) * 4));
            r9_4 = r25 * 4; a29 = *(f32 *)((u8 *)arg1 + r9_4);
            p95 = (void *)((u8 *)arg1 + r9_4);
            a30 = *(f32 *)((u8 *)p105 + 4);
            a12_5 = a6_3 * a27_2; a11_6 = a7_3 * a27_2;
            a31 = *(f32 *)((u8 *)p95 + 4); a1_6 = *(f32 *)p105;
            a27_3 = a29 - a30; a13_4 = a7_3 * a26_2;
            a10_5 = a6_3 * a26_2; a25_3 = a31 + a1_6;
            p28 = (void *)((u8 *)p28 + 8);
            a7_4 = a3_3 * a27_3; v6 += 2;
            a26_3 = a31 - a1_6; a12_6 = a13_4 - a12_5;
            a13_5 = a11_6 + a10_5; a6_4 = a7_4 - (a2_3 * a25_3);
            a25_4 = (a3_3 * a25_3) + (a2_3 * a27_3); a24_4 = a29 + a30;
            *(f32 *)p262 = a12_6 + a6_4; *(f32 *)((u8 *)p262 + 4) = a13_5 + a25_4;
            *(f32 *)p95 = a12_6 - a6_4;
            a2_4 = (a5_4 * a24_4) + (a4_4 * a26_3);
            *(f32 *)((u8 *)p95 + 4) = a13_5 - a25_4;
            a5_5 = (a9_2 * a0_5) + (a8_4 * a28_2);
            a4_5 = (a5_4 * a26_3) - (a4_4 * a24_4);
            a3_4 = (a9_2 * a28_2) - (a8_4 * a0_5);
            *(f32 *)p27 = a5_5 + a2_4; *(f32 *)((u8 *)p27 + 4) = a3_4 + a4_5;
            *(f32 *)p105 = a5_5 - a2_4; *(f32 *)((u8 *)p105 + 4) = a3_4 - a4_5;
            ctr -= 1;
        } while (ctr != 0);
    }
    r12_3 = r8 * 4; r31_3 = ((r8 * 5) + 1) * 4; r11_3 = r8 * 0x14;
    r10_6 = (r8 + 1) * 4; r8_2 = r8 * 0xC; r9_6 = ((r8 * 7) + 1) * 4;
    a4_6 = *(f32 *)((u8 *)arg1 + r12_3); a1_7 = *(f32 *)((u8 *)arg1 + r31_3);
    r7_2 = r8 * 0x1C; a3_5 = *(f32 *)((u8 *)arg1 + r10_6);
    r6 = ((r8 * 3) + 1) * 4; a2_5 = *(f32 *)((u8 *)arg1 + r11_3);
    a6_5 = a4_6 - a1_7; a10_6 = a4_6 + a1_7;
    a0_6 = *(f32 *)((u8 *)arg2 + r0); a7_5 = a3_5 + a2_5;
    a1_8 = *(f32 *)((u8 *)arg2 + r3); a11_7 = a3_5 - a2_5;
    a5_6 = *(f32 *)((u8 *)arg1 + r8_2); a4_7 = *(f32 *)((u8 *)arg1 + r9_6);
    a3_6 = *(f32 *)((u8 *)arg1 + r6); a2_6 = *(f32 *)((u8 *)arg1 + r7_2);
    a9_3 = (a0_6 * a6_5) - (a1_8 * a7_5); a12_7 = a5_6 - a4_7;
    a24_5 = a5_6 + a4_7; a13_6 = a3_6 + a2_6; a25_5 = a3_6 - a2_6;
    a12_8 = (a0_6 * a7_5) + (a1_8 * a6_5);
    a5_7 = (a1_8 * a12_7) - (a0_6 * a13_6);
    a13_7 = (a1_8 * a13_6) + (a0_6 * a12_7);
    *(f32 *)((u8 *)arg1 + r12_3) = a9_3 + a5_7;
    *(f32 *)((u8 *)arg1 + r10_6) = a12_8 + a13_7;
    *(f32 *)((u8 *)arg1 + r8_2) = a9_3 - a5_7;
    a4_8 = (a0_6 * a24_5) - (a1_8 * a25_5);
    a3_7 = (a1_8 * a11_7) + (a0_6 * a10_6);
    a5_8 = (a0_6 * a25_5) + (a1_8 * a24_5);
    a7_6 = (a1_8 * a10_6) - (a0_6 * a11_7);
    *(f32 *)((u8 *)arg1 + r6) = a12_8 - a13_7;
    *(f32 *)((u8 *)arg1 + r11_3) = a7_6 - a4_8;
    *(f32 *)((u8 *)arg1 + r31_3) = a3_7 - a5_8;
    *(f32 *)((u8 *)arg1 + r7_2) = a7_6 + a4_8;
    *(f32 *)((u8 *)arg1 + r9_6) = a3_7 + a5_8;
}

#pragma scheduling reset
void fn_80123CEC(s32 count, void *dst, s32 srcIndex, void *src) {
    /* Forward FFT core: run the four quarter-size butterfly kernels over dst (count 0x40 or 0x80), taking twiddle factors from src at indices derived from srcIndex. */
    void *twiddleTable = src;
    void *twiddlesA;
    void *twiddlesB;
    if (count == 0x80) {
        twiddlesA = (u8 *)twiddleTable + ((srcIndex - 8) * 4);
        fn_80123E98(dst, twiddlesA);
        twiddlesB = (u8 *)twiddleTable + ((srcIndex - 0x20) * 4);
        fn_8012440C((u8 *)dst + 0x80, twiddlesB);
        fn_80123E98((u8 *)dst + 0x100, twiddlesA);
        fn_80123E98((u8 *)dst + 0x180, twiddlesA);
        return;
    } else {
        void *twiddles = (u8 *)twiddleTable + ((srcIndex - 0x10) * 4);
        fn_80124AD8(dst, twiddles);
        fn_80124CE8((u8 *)dst + 0x40, twiddles);
        fn_80124AD8((u8 *)dst + 0x80, twiddles);
        fn_80124AD8((u8 *)dst + 0xC0, twiddles);
    }
}
extern void fn_8012440C(void *, void *);
extern void fn_80124CE8(void *, void *);
void fn_80123DC0(s32 count, void *dst, s32 srcIndex, void *src) {
    /* Apply one of two DCT/transform kernels to dst based on count, using src at the given index offsets. */
    void *srcBase = src;
    void *coeffPtr1;
    void *coeffPtr2;
    if (count == 0x80) {
        coeffPtr1 = (u8 *)srcBase + ((srcIndex - 8) * 4);
        fn_80123E98(dst, coeffPtr1);
        coeffPtr2 = (u8 *)srcBase + ((srcIndex - 0x20) * 4);
        fn_8012440C((u8 *)dst + 0x80, coeffPtr2);
        fn_80123E98((u8 *)dst + 0x100, coeffPtr1);
        fn_8012440C((u8 *)dst + 0x180, coeffPtr2);
        return;
    } else {
        void *coeffPtr = (u8 *)srcBase + ((srcIndex - 0x10) * 4);
        fn_80124AD8(dst, coeffPtr);
        fn_80124CE8((u8 *)dst + 0x40, coeffPtr);
        fn_80124AD8((u8 *)dst + 0x80, coeffPtr);
        fn_80124CE8((u8 *)dst + 0xC0, coeffPtr);
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

void fn_8012440C(void *arg0, void *arg1) {
    f64 spB8, spB0, spA8, spA0, sp98, sp90, sp88, sp80, sp78, sp70, sp68, sp60, sp58, sp50, sp48, sp40, sp38, sp30, sp28;
    f32 sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f0_5, temp_f0_6;
    f32 temp_f10, temp_f10_10, temp_f10_11, temp_f10_12, temp_f10_13;
    f32 temp_f10_2, temp_f10_3, temp_f10_4, temp_f10_5, temp_f10_6, temp_f10_7, temp_f10_8, temp_f10_9;
    f32 temp_f11, temp_f11_10, temp_f11_11, temp_f11_12, temp_f11_13, temp_f11_14;
    f32 temp_f11_2, temp_f11_3, temp_f11_4, temp_f11_5, temp_f11_6, temp_f11_7, temp_f11_8, temp_f11_9;
    f32 temp_f12, temp_f12_2, temp_f12_3, temp_f12_4, temp_f12_5, temp_f12_6, temp_f12_7, temp_f12_8, temp_f12_9;
    f32 temp_f13, temp_f13_2, temp_f13_3, temp_f13_4;
    f32 temp_f14, temp_f14_2, temp_f14_3, temp_f14_4, temp_f14_5, temp_f14_6;
    f32 temp_f15, temp_f15_2, temp_f15_3, temp_f15_4, temp_f15_5, temp_f15_6;
    f32 temp_f16, temp_f16_2, temp_f17, temp_f18, temp_f18_2, temp_f18_3, temp_f18_4;
    f32 temp_f19, temp_f19_2, temp_f19_3, temp_f19_4;
    f32 temp_f1, temp_f1_2, temp_f1_3, temp_f1_4, temp_f1_5;
    f32 temp_f20, temp_f20_2, temp_f20_3, temp_f20_4, temp_f20_5;
    f32 temp_f21, temp_f21_2, temp_f21_3, temp_f21_4;
    f32 temp_f22, temp_f22_2, temp_f22_3, temp_f22_4, temp_f22_5, temp_f22_6;
    f32 temp_f23, temp_f23_2, temp_f23_3;
    f32 temp_f24, temp_f24_2, temp_f24_3, temp_f24_4;
    f32 temp_f25, temp_f25_2, temp_f25_3, temp_f25_4, temp_f25_5;
    f32 temp_f26, temp_f26_2, temp_f26_3, temp_f26_4, temp_f26_5;
    f32 temp_f27, temp_f27_2, temp_f27_3, temp_f27_4, temp_f27_5;
    f32 temp_f28, temp_f28_2, temp_f28_3, temp_f28_4;
    f32 temp_f29, temp_f29_2, temp_f29_3, temp_f29_4, temp_f29_5, temp_f29_6;
    f32 temp_f2, temp_f2_2, temp_f2_3, temp_f2_4, temp_f2_5, temp_f2_6, temp_f2_7;
    f32 temp_f30, temp_f30_2, temp_f30_3, temp_f31;
    f32 temp_f3, temp_f3_2, temp_f3_3, temp_f3_4, temp_f3_5, temp_f3_6, temp_f3_7, temp_f3_8;
    f32 temp_f4, temp_f4_2, temp_f4_3, temp_f4_4, temp_f4_5;
    f32 temp_f5, temp_f5_2, temp_f5_3, temp_f5_4, temp_f5_5;
    f32 temp_f6, temp_f6_2, temp_f6_3, temp_f7, temp_f7_2, temp_f7_3;
    f32 temp_f8, temp_f8_2, temp_f8_3, temp_f9, temp_f9_2, temp_f9_3, temp_f9_4, temp_f9_5;

    temp_f3 = M2C_FIELD(arg0, f32 *, 0x20);
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x64);
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x24);
    temp_f4 = temp_f3 - temp_f2;
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x60);
    temp_f2_2 = temp_f3 + temp_f2;
    temp_f18 = M2C_FIELD(arg0, f32 *, 8);
    temp_f3_2 = temp_f1 + temp_f0;
    temp_f14 = M2C_FIELD(arg0, f32 *, 0x4C);
    temp_f0_2 = temp_f1 - temp_f0;
    temp_f13 = M2C_FIELD(arg0, f32 *, 0xC);
    temp_f12 = M2C_FIELD(arg0, f32 *, 0x48);
    temp_f20 = temp_f18 - temp_f14;
    temp_f16 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f21 = temp_f13 + temp_f12;
    temp_f15 = M2C_FIELD(arg1, f32 *, 0x14);
    temp_f19 = temp_f13 - temp_f12;
    temp_f11 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_f17 = M2C_FIELD(arg1, f32 *, 4);
    temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x6C);
    temp_f10 = M2C_FIELD(arg0, f32 *, 0x2C);
    temp_f9 = M2C_FIELD(arg0, f32 *, 0x68);
    temp_f3_3 = temp_f11 + temp_f1_2;
    temp_f4_2 = temp_f10 - temp_f9;
    temp_f0_3 = M2C_FIELD(arg1, f32 *, 0x18);
    temp_f11_2 = temp_f11 - temp_f1_2;
    temp_f1_3 = M2C_FIELD(arg1, f32 *, 0x1C);
    temp_f9_2 = temp_f10 + temp_f9;
    temp_f30 = M2C_FIELD(arg0, f32 *, 0);
    temp_f18_2 = temp_f18 + temp_f14;
    temp_f26 = M2C_FIELD(arg0, f32 *, 0x44);
    temp_f14_2 = temp_f17 * (temp_f3_2 + temp_f4);
    temp_f29 = M2C_FIELD(arg0, f32 *, 4);
    temp_f28 = M2C_FIELD(arg0, f32 *, 0x40);
    temp_f6 = temp_f17 * (temp_f0_2 + temp_f2_2);
    temp_f12_2 = M2C_FIELD(arg1, f32 *, 0x20);
    temp_f13_2 = M2C_FIELD(arg1, f32 *, 0x24);
    temp_f11_3 = temp_f17 * (temp_f4 - temp_f3_2);
    temp_f27 = (temp_f16 * temp_f21) + (temp_f15 * temp_f20);
    temp_f25 = (temp_f16 * temp_f20) - (temp_f15 * temp_f21);
    temp_f5 = (temp_f1_3 * temp_f11_2) - (temp_f0_3 * temp_f9_2);
    temp_f8 = (temp_f1_3 * temp_f9_2) + (temp_f0_3 * temp_f11_2);
    temp_f9_3 = temp_f30 - temp_f26;
    temp_f10_2 = temp_f29 + temp_f28;
    temp_f26_2 = temp_f30 + temp_f26;
    temp_f2_3 = temp_f29 - temp_f28;
    sp24 = temp_f9_3 + temp_f11_3;
    temp_f3_4 = temp_f10_2 + temp_f14_2;
    temp_f7 = temp_f17 * (temp_f2_2 - temp_f0_2);
    temp_f18_3 = (temp_f16 * temp_f4_2) - (temp_f15 * temp_f3_3);
    sp20 = temp_f3_4;
    temp_f9_4 = (temp_f0_3 * temp_f19) + (temp_f1_3 * temp_f18_2);
    sp14 = temp_f9_3 - temp_f11_3;
    temp_f10_3 = (temp_f16 * temp_f3_3) + (temp_f15 * temp_f4_2);
    sp10 = temp_f10_2 - temp_f14_2;
    temp_f6_2 = temp_f26_2 + temp_f6;
    spC = temp_f26_2 - temp_f6;
    temp_f7_2 = temp_f2_3 - temp_f7;
    sp8 = temp_f2_3 + temp_f7;
    temp_f3_5 = temp_f27 - temp_f8;
    sp1C = temp_f25 + temp_f5;
    temp_f8_2 = (temp_f0_3 * temp_f18_2) - (temp_f1_3 * temp_f19);
    sp18 = temp_f27 + temp_f8;
    temp_f2_4 = temp_f25 - temp_f5;
    temp_f4_3 = temp_f8_2 - temp_f10_3;
    temp_f14_3 = M2C_FIELD(arg0, f32 *, 0x10);
    temp_f11_4 = M2C_FIELD(arg0, f32 *, 0x54);
    temp_f8_3 = temp_f8_2 + temp_f10_3;
    temp_f22 = M2C_FIELD(arg0, f32 *, 0x14);
    temp_f5_2 = temp_f9_4 - temp_f18_3;
    temp_f10_4 = M2C_FIELD(arg0, f32 *, 0x50);
    temp_f23 = temp_f14_3 - temp_f11_4;
    temp_f21_2 = temp_f14_3 + temp_f11_4;
    temp_f24 = M2C_FIELD(arg0, f32 *, 0x30);
    temp_f20_2 = M2C_FIELD(arg0, f32 *, 0x74);
    temp_f29_2 = temp_f22 + temp_f10_4;
    temp_f27_2 = temp_f22 - temp_f10_4;
    temp_f19_2 = temp_f24 - temp_f20_2;
    temp_f20_3 = temp_f24 + temp_f20_2;
    temp_f14_4 = M2C_FIELD(arg0, f32 *, 0x34);
    temp_f9_5 = temp_f9_4 + temp_f18_3;
    temp_f11_5 = M2C_FIELD(arg0, f32 *, 0x70);
    temp_f22_2 = M2C_FIELD(arg0, f32 *, 0x18);
    temp_f10_5 = M2C_FIELD(arg0, f32 *, 0x5C);
    temp_f28_2 = temp_f14_4 + temp_f11_5;
    temp_f24_2 = temp_f14_4 - temp_f11_5;
    temp_f25_2 = M2C_FIELD(arg0, f32 *, 0x1C);
    temp_f14_5 = temp_f22_2 - temp_f10_5;
    temp_f11_6 = M2C_FIELD(arg0, f32 *, 0x58);
    temp_f10_6 = temp_f22_2 + temp_f10_5;
    temp_f22_3 = M2C_FIELD(arg0, f32 *, 0x7C);
    temp_f26_3 = temp_f25_2 + temp_f11_6;
    spB0 = (f64) M2C_FIELD(arg0, f32 *, 0x78);
    temp_f11_7 = temp_f25_2 - temp_f11_6;
    temp_f31 = M2C_FIELD(arg0, f32 *, 0x38);
    spB8 = (f64) temp_f22_3;
    spA8 = (f64) M2C_FIELD(arg0, f32 *, 0x3C);
    temp_f22_4 = temp_f31 - temp_f22_3;
    temp_f25_3 = (f32) spA8 + (f32) spB0;
    sp28 = (f64) (temp_f12_2 * temp_f23);
    temp_f30_2 = temp_f13_2 * temp_f29_2;
    temp_f29_3 = temp_f12_2 * temp_f29_2;
    sp40 = (f64) (temp_f13_2 * temp_f23);
    sp38 = (f64) temp_f29_3;
    sp48 = (f64) (temp_f13_2 * temp_f19_2);
    sp30 = (f64) temp_f30_2;
    sp50 = (f64) (temp_f12_2 * temp_f28_2);
    sp58 = (f64) (temp_f13_2 * temp_f28_2);
    sp60 = (f64) (temp_f13_2 * temp_f21_2);
    sp78 = (f64) (temp_f12_2 * temp_f21_2);
    sp68 = (f64) (temp_f12_2 * temp_f27_2);
    sp80 = (f64) (temp_f13_2 * temp_f24_2);
    sp70 = (f64) (temp_f13_2 * temp_f27_2);
    sp88 = (f64) (temp_f12_2 * temp_f24_2);
    sp90 = (f64) (temp_f1_3 * temp_f26_3);
    sp98 = (f64) (temp_f0_3 * temp_f26_3);
    spA0 = (f64) (temp_f1_3 * temp_f14_5);
    temp_f28_3 = (f32) sp28 - temp_f30_2;
    temp_f22_5 = (f32) sp48 - (f32) sp50;
    temp_f25_4 = temp_f29_3 + (f32) sp40;
    temp_f19_3 = (f32) sp58 + (temp_f12_2 * temp_f19_2);
    temp_f29_4 = (f32) sp60 - (f32) sp68;
    temp_f23_2 = (temp_f12_2 * temp_f20_3) - (f32) sp80;
    temp_f26_4 = (f32) sp70 + (f32) sp78;
    temp_f20_4 = (f32) sp88 + (temp_f13_2 * temp_f20_3);
    temp_f30_3 = (temp_f0_3 * temp_f14_5) - (f32) sp90;
    temp_f24_3 = (temp_f15 * temp_f22_4) - (temp_f16 * temp_f25_3);
    temp_f27_3 = (f32) sp98 + (f32) spA0;
    temp_f21_3 = (temp_f15 * temp_f25_3) + (temp_f16 * temp_f22_4);
    temp_f15_2 = temp_f28_3 + temp_f22_5;
    temp_f16_2 = temp_f25_4 + temp_f19_3;
    temp_f10_7 = (temp_f15 * temp_f11_7) - (temp_f16 * temp_f10_6);
    temp_f22_6 = temp_f28_3 - temp_f22_5;
    temp_f25_5 = temp_f25_4 - temp_f19_3;
    temp_f28_4 = temp_f29_4 - temp_f23_2;
    temp_f14_6 = temp_f26_4 - temp_f20_4;
    temp_f18_4 = temp_f30_3 + temp_f24_3;
    temp_f19_4 = temp_f27_3 + temp_f21_3;
    temp_f21_4 = temp_f27_3 - temp_f21_3;
    temp_f23_3 = temp_f29_4 + temp_f23_2;
    temp_f20_5 = temp_f26_4 + temp_f20_4;
    temp_f24_4 = temp_f30_3 - temp_f24_3;
    temp_f12_3 = (temp_f15 * temp_f10_6) + (temp_f16 * temp_f11_7);
    temp_f27_4 = temp_f31 + (f32) spB8;
    temp_f29_5 = (f32) spA8 - (f32) spB0;
    temp_f0_4 = temp_f2_4 - temp_f21_4;
    temp_f13_3 = (temp_f1_3 * temp_f27_4) - (temp_f0_3 * temp_f29_5);
    temp_f1_4 = (temp_f1_3 * temp_f29_5) + (temp_f0_3 * temp_f27_4);
    temp_f11_8 = temp_f3_5 + temp_f24_4;
    temp_f27_5 = temp_f12_3 - temp_f13_3;
    temp_f29_6 = temp_f10_7 - temp_f1_4;
    temp_f26_5 = temp_f10_7 + temp_f1_4;
    temp_f10_8 = temp_f2_4 + temp_f21_4;
    temp_f11_9 = temp_f3_5 - temp_f24_4;
    temp_f2_5 = temp_f8_3 + temp_f29_6;
    temp_f3_6 = temp_f9_5 - temp_f27_5;
    temp_f11_10 = sp20 + temp_f16_2;
    temp_f13_4 = temp_f12_3 + temp_f13_3;
    temp_f2_6 = sp24 + temp_f15_2;
    temp_f3_7 = sp1C + temp_f18_4;
    temp_f12_4 = sp18 + temp_f19_4;
    M2C_FIELD(arg0, f32 *, 0) = (f32) (temp_f2_6 + temp_f3_7);
    temp_f10_9 = sp24 - temp_f15_2;
    M2C_FIELD(arg0, f32 *, 4) = (f32) (temp_f11_10 + temp_f12_4);
    temp_f12_5 = sp18 - temp_f19_4;
    M2C_FIELD(arg0, f32 *, 8) = (f32) (temp_f2_6 - temp_f3_7);
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (temp_f11_10 - temp_f12_4);
    temp_f12_6 = temp_f17 * (temp_f0_4 - temp_f11_8);
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) (temp_f10_9 - temp_f12_5);
    temp_f3_8 = temp_f3_4 - temp_f16_2;
    temp_f15_3 = sp1C - temp_f18_4;
    temp_f2_7 = sp14 - temp_f25_5;
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (temp_f10_9 + temp_f12_5);
    temp_f15_4 = temp_f17 * (temp_f11_8 + temp_f0_4);
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) (temp_f3_8 + temp_f15_3);
    temp_f11_11 = sp10 + temp_f22_6;
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) (temp_f3_8 - temp_f15_3);
    temp_f12_7 = temp_f17 * (temp_f10_8 - temp_f11_9);
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) (temp_f2_7 + temp_f12_6);
    temp_f15_5 = temp_f17 * (temp_f11_9 + temp_f10_8);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (temp_f11_11 + temp_f15_4);
    temp_f10_10 = sp14 + temp_f25_5;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (temp_f2_7 - temp_f12_6);
    temp_f11_12 = sp10 - temp_f22_6;
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (temp_f11_11 - temp_f15_4);
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) (temp_f10_10 - temp_f15_5);
    temp_f12_8 = temp_f4_3 - temp_f13_4;
    temp_f15_6 = temp_f5_2 - temp_f26_5;
    temp_f10_11 = spC + temp_f28_4;
    temp_f5_3 = temp_f5_2 + temp_f26_5;
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (temp_f10_10 + temp_f15_5);
    temp_f4_4 = temp_f4_3 + temp_f13_4;
    temp_f11_13 = sp8 + temp_f14_6;
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) (temp_f11_12 + temp_f12_7);
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (temp_f11_12 - temp_f12_7);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (temp_f10_11 + temp_f12_8);
    temp_f11_14 = temp_f17 * (temp_f2_5 - temp_f3_6);
    temp_f12_9 = temp_f17 * (temp_f3_6 + temp_f2_5);
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) (temp_f11_13 + temp_f15_6);
    temp_f10_12 = spC - temp_f28_4;
    M2C_FIELD(arg0, f32 *, 0x48) = (f32) (temp_f10_11 - temp_f12_8);
    temp_f0_5 = sp8 - temp_f14_6;
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) (temp_f11_13 - temp_f15_6);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) (temp_f10_12 - temp_f5_3);
    temp_f4_5 = temp_f6_2 - temp_f20_5;
    temp_f10_13 = temp_f7_2 + temp_f23_3;
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) (temp_f0_5 + temp_f4_4);
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) (temp_f10_12 + temp_f5_3);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (temp_f0_5 - temp_f4_4);
    temp_f0_6 = temp_f8_3 - temp_f29_6;
    temp_f5_4 = temp_f9_5 + temp_f27_5;
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) (temp_f4_5 + temp_f11_14);
    temp_f5_5 = temp_f6_2 + temp_f20_5;
    temp_f6_3 = temp_f7_2 - temp_f23_3;
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (temp_f10_13 + temp_f12_9);
    temp_f7_3 = temp_f17 * (temp_f0_6 - temp_f5_4);
    temp_f1_5 = temp_f17 * (temp_f5_4 + temp_f0_6);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (temp_f4_5 - temp_f11_14);
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) (temp_f10_13 - temp_f12_9);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f5_5 - temp_f1_5);
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) (temp_f6_3 + temp_f7_3);
    M2C_FIELD(arg0, f32 *, 0x78) = (f32) (temp_f5_5 + temp_f1_5);
    M2C_FIELD(arg0, f32 *, 0x7C) = (f32) (temp_f6_3 - temp_f7_3);
}

void fn_80124AD8(void *arg0, void *arg1) {
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f10, temp_f10_2;
    f32 temp_f11, temp_f11_2, temp_f11_3, temp_f12, temp_f12_2, temp_f12_3, temp_f13;
    f32 temp_f1, temp_f1_2, temp_f1_3, temp_f22, temp_f22_2, temp_f22_3;
    f32 temp_f23, temp_f23_2, temp_f24, temp_f24_2, temp_f25, temp_f25_2;
    f32 temp_f26, temp_f27, temp_f28, temp_f29, temp_f2, temp_f2_2, temp_f2_3;
    f32 temp_f30, temp_f31, temp_f3, temp_f3_2, temp_f3_3, temp_f4, temp_f4_2, temp_f4_3;
    f32 temp_f5, temp_f5_2, temp_f5_3, temp_f6, temp_f6_2, temp_f6_3, temp_f6_4;
    f32 temp_f7, temp_f7_2, temp_f7_3, temp_f7_4, temp_f8, temp_f8_2, temp_f9, temp_f9_2;

    temp_f1 = ((f32 *)arg0)[2];
    temp_f0 = ((f32 *)arg0)[10];
    temp_f31 = ((f32 *)arg0)[3];
    temp_f13 = ((f32 *)arg0)[11];
    temp_f3 = temp_f1 - temp_f0;
    temp_f0_2 = temp_f1 + temp_f0;
    temp_f2 = ((f32 *)arg0)[6];
    temp_f1_2 = ((f32 *)arg0)[14];
    temp_f4 = temp_f31 - temp_f13;
    temp_f12 = ((f32 *)arg0)[7];
    temp_f6 = temp_f2 - temp_f1_2;
    temp_f11 = ((f32 *)arg0)[15];
    temp_f1_3 = temp_f2 + temp_f1_2;
    temp_f10 = ((f32 *)arg0)[0];
    temp_f2_2 = temp_f12 - temp_f11;
    temp_f5 = ((f32 *)arg0)[8];
    temp_f29 = temp_f4 + temp_f6;
    temp_f23 = ((f32 *)arg0)[1];
    temp_f22 = temp_f4 - temp_f6;
    temp_f24 = ((f32 *)arg0)[9];
    temp_f28 = temp_f3 - temp_f2_2;
    temp_f25 = ((f32 *)arg0)[4];
    temp_f30 = temp_f3 + temp_f2_2;
    temp_f26 = ((f32 *)arg0)[12];
    temp_f3_2 = temp_f10 + temp_f5;
    temp_f9 = ((f32 *)arg0)[5];
    temp_f6_2 = ((f32 *)arg0)[13];
    temp_f2_3 = ((f32 *)arg1)[1];
    temp_f27 = temp_f28 - temp_f29;
    temp_f28 = temp_f28 + temp_f29;
    temp_f5_2 = temp_f10 - temp_f5;
    temp_f22_2 = temp_f12 + temp_f11;
    temp_f7 = temp_f25 + temp_f26;
    temp_f12_2 = temp_f0_2 + temp_f1_3;
    temp_f4_2 = temp_f23 + temp_f24;
    temp_f11_2 = temp_f3_2 + temp_f7;
    temp_f8 = temp_f9 + temp_f6_2;
    temp_f10_2 = temp_f9 - temp_f6_2;
    temp_f6_3 = temp_f23 - temp_f24;
    temp_f23_2 = temp_f31 + temp_f13;
    temp_f9_2 = temp_f25 - temp_f26;
    temp_f25_2 = temp_f23_2 + temp_f22_2;
    temp_f24_2 = temp_f4_2 + temp_f8;
    ((f32 *)arg0)[0] = (f32) (temp_f11_2 + temp_f12_2);
    temp_f3_3 = temp_f3_2 - temp_f7;
    temp_f7_2 = temp_f4_2 - temp_f8;
    ((f32 *)arg0)[2] = (f32) (temp_f11_2 - temp_f12_2);
    temp_f22_3 = temp_f23_2 - temp_f22_2;
    temp_f0_3 = temp_f0_2 - temp_f1_3;
    ((f32 *)arg0)[3] = (f32) (temp_f24_2 - temp_f25_2);
    ((f32 *)arg0)[1] = (f32) (temp_f24_2 + temp_f25_2);
    temp_f7_3 = temp_f5_2 - temp_f10_2;
    ((f32 *)arg0)[4] = (f32) (temp_f3_3 - temp_f22_3);
    temp_f11_3 = temp_f2_3 * temp_f27;
    ((f32 *)arg0)[6] = (f32) (temp_f3_3 + temp_f22_3);
    temp_f8_2 = temp_f6_3 + temp_f9_2;
    temp_f12_3 = temp_f2_3 * temp_f28;
    ((f32 *)arg0)[5] = (f32) (temp_f7_2 + temp_f0_3);
    ((f32 *)arg0)[7] = (f32) (temp_f7_2 - temp_f0_3);
    ((f32 *)arg0)[8] = (f32) (temp_f7_3 + temp_f11_3);
    temp_f4_3 = temp_f5_2 + temp_f10_2;
    temp_f5_3 = temp_f6_3 - temp_f9_2;
    temp_f7_4 = temp_f2_3 * (temp_f30 + temp_f22);
    ((f32 *)arg0)[9] = (f32) (temp_f8_2 + temp_f12_3);
    temp_f6_4 = temp_f2_3 * (temp_f30 - temp_f22);
    ((f32 *)arg0)[10] = (f32) (temp_f7_3 - temp_f11_3);
    ((f32 *)arg0)[11] = (f32) (temp_f8_2 - temp_f12_3);
    ((f32 *)arg0)[12] = (f32) (temp_f4_3 - temp_f7_4);
    ((f32 *)arg0)[13] = (f32) (temp_f5_3 + temp_f6_4);
    ((f32 *)arg0)[14] = (f32) (temp_f4_3 + temp_f7_4);
    ((f32 *)arg0)[15] = (f32) (temp_f5_3 - temp_f6_4);
}

void fn_80124CE8(void *arg0, void *arg1) {
    f32 v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v31, v30, v29, v28, v27, v26, v25, v24, v23, v22, v21, v20, v19;
    v1 = ((f32 *)arg0)[4];
    v0 = ((f32 *)arg0)[13];
    v5 = ((f32 *)arg0)[5];
    v4 = ((f32 *)arg0)[12];
    v9 = v1 - v0;
    v7 = v1 + v0;
    v10 = v5 + v4;
    v8 = v5 - v4;
    v3 = ((f32 *)arg0)[2];
    v2 = ((f32 *)arg0)[11];
    v6 = v3 - v2;
    v28 = ((f32 *)arg1)[4];
    v2 = v3 + v2;
    v1 = ((f32 *)arg0)[3];
    v22 = v9 - v10;
    v0 = ((f32 *)arg0)[10];
    v21 = v10 + v9;
    v5 = ((f32 *)arg0)[6];
    v4 = ((f32 *)arg0)[15];
    v9 = v7 - v8;
    v29 = ((f32 *)arg1)[1];
    v8 = v8 + v7;
    v25 = v1 + v0;
    v27 = ((f32 *)arg1)[5];
    v3 = v1 - v0;
    v1 = ((f32 *)arg0)[7];
    v0 = ((f32 *)arg0)[14];
    v20 = v28 * v6;
    v23 = v5 - v4;
    v13 = ((f32 *)arg0)[0];
    v31 = v5 + v4;
    v12 = ((f32 *)arg0)[9];
    v24 = v1 + v0;
    v11 = ((f32 *)arg0)[1];
    v30 = v1 - v0;
    v10 = ((f32 *)arg0)[8];
    v26 = v13 - v12;
    v19 = v27 * v25;
    v7 = v28 * v25;
    v25 = v11 + v10;
    v6 = v27 * v6;
    v5 = v27 * v23;
    v0 = v28 * v24;
    v4 = v27 * v24;
    v1 = v28 * v23;
    v24 = v29 * v22;
    v23 = v29 * v21;
    v21 = v7 + v6;
    v1 = v4 + v1;
    v22 = v20 - v19;
    v0 = v5 - v0;
    v20 = v21 + v1;
    v10 = v11 - v10;
    v7 = v22 + v0;
    v4 = v26 + v24;
    v6 = v25 + v23;
    v12 = v13 + v12;
    v5 = v4 + v7;
    v19 = v4 - v7;
    v4 = v6 + v20;
    v20 = v6 - v20;
    ((f32 *)arg0)[0] = v5;
    v7 = v27 * v2;
    v6 = v28 * v3;
    ((f32 *)arg0)[1] = v4;
    v5 = v27 * v3;
    v4 = v28 * v2;
    ((f32 *)arg0)[2] = v19;
    v3 = v28 * v31;
    v2 = v27 * v30;
    ((f32 *)arg0)[3] = v20;
    v20 = v28 * v30;
    v19 = v27 * v31;
    v2 = v3 - v2;
    v9 = v29 * v9;
    v3 = v20 + v19;
    v8 = v29 * v8;
    v6 = v7 - v6;
    v4 = v5 + v4;
    v11 = v26 - v24;
    v20 = v25 - v23;
    v22 = v22 - v0;
    v1 = v21 - v1;
    v7 = v12 - v8;
    v21 = v6 - v2;
    v0 = v11 - v1;
    v13 = v11 + v1;
    v1 = v7 + v21;
    v5 = v20 + v22;
    ((f32 *)arg0)[4] = v0;
    v8 = v12 + v8;
    v11 = v20 - v22;
    ((f32 *)arg0)[8] = v1;
    v12 = v4 + v3;
    v23 = v4 - v3;
    ((f32 *)arg0)[5] = v5;
    v19 = v10 + v9;
    v7 = v7 - v21;
    ((f32 *)arg0)[6] = v13;
    v3 = v8 - v12;
    v0 = v19 + v23;
    ((f32 *)arg0)[7] = v11;
    v5 = v19 - v23;
    v1 = v8 + v12;
    ((f32 *)arg0)[10] = v7;
    v4 = v10 - v9;
    v6 = v6 + v2;
    ((f32 *)arg0)[9] = v0;
    ((f32 *)arg0)[11] = v5;
    v2 = v4 + v6;
    v0 = v4 - v6;
    ((f32 *)arg0)[12] = v3;
    ((f32 *)arg0)[13] = v2;
    ((f32 *)arg0)[14] = v1;
    ((f32 *)arg0)[15] = v0;
}

#pragma opt_propagation off
/* Final butterfly stage of the 8-point Ooura real FFT (forward direction): combine
 * the four pairs 0x10 apart into sums/differences, then fold those across 0x08 with
 * a sign swap on the second half to write the four complex outputs back in place.
 * Locals are reused to preserve the compiler's float-register mapping. */
void fn_80124F90(void *data) {
    f32 evenHi;
    f32 evenLo;
    f32 quadHi;
    f32 quadLo;
    f32 pairHi;
    f32 pairLo;
    f32 sum0;
    f32 sum1;
    f32 diff0;
    f32 diff1;
    f32 sum2;
    f32 diff2;
    f32 diff3;

    evenLo = *(f32 *)((u8 *)data + 0);
    evenHi = *(f32 *)((u8 *)data + 0x10);
    pairLo = *(f32 *)((u8 *)data + 4);
    pairHi = *(f32 *)((u8 *)data + 0x14);
    sum0 = evenLo + evenHi;
    diff0 = evenLo - evenHi;
    quadLo = *(f32 *)((u8 *)data + 8);
    quadHi = *(f32 *)((u8 *)data + 0x18);
    sum1 = pairLo + pairHi;
    evenLo = *(f32 *)((u8 *)data + 0xC);
    evenHi = *(f32 *)((u8 *)data + 0x1C);
    diff1 = pairLo - pairHi;
    diff3 = evenLo - evenHi;
    pairHi = evenLo + evenHi;
    sum2 = quadLo + quadHi;
    diff2 = quadLo - quadHi;
    *(f32 *)((u8 *)data + 0) = sum0 + sum2;
    *(f32 *)((u8 *)data + 4) = sum1 + pairHi;
    *(f32 *)((u8 *)data + 0x10) = sum0 - sum2;
    *(f32 *)((u8 *)data + 0x14) = sum1 - pairHi;
    *(f32 *)((u8 *)data + 8) = diff0 - diff3;
    *(f32 *)((u8 *)data + 0xC) = diff1 + diff2;
    *(f32 *)((u8 *)data + 0x18) = diff0 + diff3;
    *(f32 *)((u8 *)data + 0x1C) = diff1 - diff2;
}
#pragma opt_propagation reset
/* Radix-2 DIF FFT butterfly (the n==8 base case of the inverse transform): four complex samples (re/im float pairs) in `data` are replaced in place by the two-stage butterfly result. */
/* Radix-2 DIF FFT butterfly, n==8 base case of the inverse transform: replaces four complex samples in place with the two-stage butterfly result. */ /* Radix-2 DIF FFT butterfly (n==8 base case of the inverse transform): four complex samples (re/im float pairs) are replaced in place by the two-stage butterfly result. */ /* Radix-2 DIF FFT butterfly (n==8 base case of the inverse transform): four complex samples (re/im float pairs) in arg0 are replaced in place by the two-stage butterfly result. */ /* Radix-2 DIF FFT butterfly (n==8 base case of the inverse transform): four complex samples (re/im float pairs) in arg0 are replaced in place by the two-stage butterfly result. */ void fn_80125014(void *data) {
    f32 t0;
    f32 t1;
    f32 re3;
    f32 re1;
    f32 t4;
    f32 im0;
    f32 sumRe02;
    f32 sumIm02;
    f32 diffRe02;
    f32 diffIm02;
    f32 sumRe13;
    f32 diffRe13;
    f32 diffIm13;

    t1 = *(f32 *)((u8 *)data + 0);
    t0 = *(f32 *)((u8 *)data + 0x10);
    im0 = *(f32 *)((u8 *)data + 4);
    t4 = *(f32 *)((u8 *)data + 0x14);
    sumRe02 = t1 + t0;
    diffRe02 = t1 - t0;
    re1 = *(f32 *)((u8 *)data + 8);
    re3 = *(f32 *)((u8 *)data + 0x18);
    sumIm02 = im0 + t4;
    t1 = *(f32 *)((u8 *)data + 0xC);
    t0 = *(f32 *)((u8 *)data + 0x1C);
    diffIm02 = im0 - t4;
    diffIm13 = t1 - t0;
    t4 = t1 + t0;
    sumRe13 = re1 + re3;
    diffRe13 = re1 - re3;
    *(f32 *)((u8 *)data + 0) = sumRe02 + sumRe13;
    *(f32 *)((u8 *)data + 4) = sumIm02 + t4;
    *(f32 *)((u8 *)data + 0x10) = sumRe02 - sumRe13;
    *(f32 *)((u8 *)data + 0x14) = sumIm02 - t4;
    *(f32 *)((u8 *)data + 8) = diffRe02 + diffIm13;
    *(f32 *)((u8 *)data + 0xC) = diffIm02 - diffRe13;
    *(f32 *)((u8 *)data + 0x18) = diffRe02 - diffIm13;
    *(f32 *)((u8 *)data + 0x1C) = diffIm02 + diffRe13;
}

/* Radix-2 DIF FFT butterfly (the n==4 base case): `data` holds two complex
 * samples as re/im float pairs; replace them in place with their sum (first
 * pair) and difference (second pair). */
void fn_80125098(void *data) {
    f32 im1, re1, im0, re0;
    f32 reDiff, reSum, imDiff, imSum;
    re0 = *(f32 *)((u8 *)data + 0);
    re1 = *(f32 *)((u8 *)data + 8);
    im0 = *(f32 *)((u8 *)data + 4);
    im1 = *(f32 *)((u8 *)data + 12);
    reDiff = re0 - re1;
    reSum = re0 + re1;
    imDiff = im0 - im1;
    imSum = im0 + im1;
    *(f32 *)((u8 *)data + 8) = reDiff;
    *(f32 *)((u8 *)data + 0) = reSum;
    *(f32 *)((u8 *)data + 4) = imSum;
    *(f32 *)((u8 *)data + 12) = imDiff;
}

#pragma push
#pragma use_lmw_stmw off
void fn_801250CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 half = arg0 >> 1;
    u32 n = (u32)(half - 1) >> 1;
    register s32 j = 2;
    register s32 i = 0;
    register s32 step = (arg2 * 2) / half;
    char *b = (char *)arg1;
    f32 *w = (f32 *)arg3;
    f32 *p = (f32 *)(b + 8);
    f32 *q = w;
    f32 one = 0.5f;
    if (half > 2) {
        u32 k = n >> 1;
        while (k--) {
            f32 x, y, t, v, z, c, re, im;
            s32 off;
            i += step;
            off = (arg0 - j) * 4;
            x = p[0];
            y = w[arg2 - i];
            t = x - *(f32 *)(b + off);
            z = one - y;
            v = p[1] + *(f32 *)(b + off + 4);
            q += step; c = *q;
            re = z*t-c*v; im = c*t+z*v;
            p[0] = x-re; p[1] -= im;
            *(f32 *)(b + off) = *(f32 *)(b + off) + re;
            *(f32 *)(b + off + 4) -= im;
            j += 2; i += step;
            off = (arg0 - j) * 4;
            x = p[2];
            y = w[arg2 - i];
            t = x - *(f32 *)(b + off);
            z = one - y;
            v = p[3] + *(f32 *)(b + off + 4);
            q += step; c = *q;
            re = z*t-c*v; im = c*t+z*v;
            p[2]=x-re; p[3]-=im;
            *(f32 *)(b + off) = *(f32 *)(b + off) + re;
            *(f32 *)(b + off + 4) -= im;
            j+=2; p+=4;
        }
        n &= 1;
        if (n) {
            do {
                f32 x, y, t, v, z, c, re, im;
                s32 off;
                i += step;
                off = (arg0 - j) * 4;
                x = p[0];
                y = w[arg2 - i];
                t = x - *(f32 *)(b + off);
                z = one - y;
                v = p[1] + *(f32 *)(b + off + 4);
                q += step; c = *q;
                re=z*t-c*v; im=c*t+z*v;
                p[0]=x-re; p[1]-=im;
                *(f32 *)(b + off) = *(f32 *)(b + off) + re;
                *(f32 *)(b + off + 4) -= im;
                j+=2; p+=2;
            } while (--n);
        }
    }
}
#pragma pop
void fn_801252D8(s32 n, f32 *a, s32 m, f32 *w) {
    s32 half = n >> 1;
    u32 count = ((u32)(half - 1)) >> 1;
    register s32 j = 2;
    register s32 i = 0;
    register s32 step = (m * 2) / half;
    char *b = (char *)a;
    f32 *p = a + 2;
    f32 *q = w;
    f32 one = 0.5f;
    if (half > 2) {
        u32 k = count >> 1;
        while (k--) {
            f32 x, y, t, v, z, c, re, im;
            s32 off;
            i += step;
            off = (n - j) * 4;
            x = p[0];
            y = w[m - i];
            z = one - y;
            t = x - *(f32 *)(b + off);
            v = p[1] + *(f32 *)(b + off + 4);
            q += step; c = *q;
            re = z * t + c * v; im = z * v - c * t;
            p[0] = x - re; p[1] -= im;
            *(f32 *)(b + off) = *(f32 *)(b + off) + re;
            *(f32 *)(b + off + 4) -= im;
            j += 2; i += step;
            off = (n - j) * 4;
            x = p[2];
            y = w[m - i];
            z = one - y;
            t = x - *(f32 *)(b + off);
            v = p[3] + *(f32 *)(b + off + 4);
            q += step; c = *q;
            re = z * t + c * v; im = z * v - c * t;
            p[2] = x - re; p[3] -= im;
            *(f32 *)(b + off) = *(f32 *)(b + off) + re;
            *(f32 *)(b + off + 4) -= im;
            j += 2; p += 4;
        }
        k = count & 1;
        while (k--) {
            f32 x, y, t, v, z, c, re, im;
            s32 off;
            i += step;
            off = (n - j) * 4;
            x = p[0];
            y = w[m - i];
            z = one - y;
            t = x - *(f32 *)(b + off);
            v = p[1] + *(f32 *)(b + off + 4);
            q += step; c = *q;
            re = z * t + c * v; im = z * v - c * t;
            p[0] = x - re; p[1] -= im;
            *(f32 *)(b + off) = *(f32 *)(b + off) + re;
            *(f32 *)(b + off + 4) -= im;
            j += 2; p += 2;
        }
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
    for (; pairs != 0; pairs--) {
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

void fn_80125664(void *outp, void *stridep, void *inp, void *quantp) {
    u8 *out = outp;
    s32 stride = (s32)stridep;
    s16 *in = inp;
    s32 *quant = quantp;
    s32 tmp[64];
    s32 *t;
    s32 i;
    t = tmp;
    for (i = 0; i < 8; i++) {
        if ((in[56] | (in[48] | (in[24] | in[8])) | (in[40] | (in[32] | in[16]))) == 0) {
            s32 dc = (in[0] * quant[0]) >> 11;
            in++;
            quant++;
            t[0] = dc;
            t[8] = dc;
            t[16] = dc;
            t[24] = dc;
            t[32] = dc;
            t[40] = dc;
            t[48] = dc;
            t[56] = dc;
            t++;
        } else {
            s32 s25, s26, s26b, s7, s0, s23, s24, s12, s7b, s0b, s7c, s25b, s9, s10, s11, s23b, s9b, s8, s10b, s25c, s23c, s11b, s9c, s7d;
            s32 v24 = (in[0] * quant[0]) >> 11;
            s25 = (in[16] * quant[16]) >> 11;
            s26 = (in[32] * quant[32]) >> 11;
            s0 = (in[48] * quant[48]) >> 11;
            s25b = (in[8] * quant[8]) >> 11;
            s9 = (in[24] * quant[24]) >> 11;
            s10 = (in[40] * quant[40]) >> 11;
            s9b = (in[56] * quant[56]) >> 11;
            in++;
            quant++;
            s7 = v24 + s26;
            s26b = v24 - s26;
            s23 = s25 + s0;
            s24 = s7 + s23;
            s12 = s7 - s23;
            s7b = (((s25 - s0) * 0xB50) >> 11) - s23;
            s0b = s26b + s7b;
            s7c = s26b - s7b;
            s11 = s10 - s9;
            s23b = s10 + s9;
            s8 = s25b - s9b;
            s10b = s25b + s9b;
            s25c = s10b + s23b;
            t[0] = s24 + s25c;
            s23c = ((s11 + s8) * 0xEC8) >> 11;
            t[56] = s24 - s25c;
            s11b = (s23c + ((s11 * -0x14E8) >> 11)) - s25c;
            t[8] = s0b + s11b;
            t[48] = s0b - s11b;
            s9c = (((s10b - s23b) * 0xB50) >> 11) - s11b;
            t[16] = s7c + s9c;
            t[40] = s7c - s9c;
            s7d = (((s8 * 0x8A9) >> 11) - s23c) + s9c;
            t[32] = s12 + s7d;
            t[24] = s12 - s7d;
            t++;
        }
    }
    t = tmp;
    for (i = 0; i < 8; i++) {
        s32 r27 = t[2] + t[6];
        s32 r26 = t[0] + t[4];
        s32 r25 = t[5] + t[3];
        s32 r24 = t[1] + t[7];
        s32 r30 = t[5] - t[3];
        s32 r6 = t[1] - t[7];
        s32 r25b = t[0] - t[4];
        s32 r29 = r24 + r25;
        s32 r11 = r26 + r27;
        s32 r28 = (((t[2] - t[6]) * 0xB50) >> 11) - r27;
        s32 r7 = ((r30 + r6) * 0xEC8) >> 11;
        s32 r24b = r25b + r28;
        s32 r9 = (r7 + ((r30 * -0x14E8) >> 11)) - r29;
        s32 r0 = r26 - r27;
        s32 r25c = r25b - r28;
        s32 r26b = (((r24 - r25) * 0xB50) >> 11) - r9;
        s32 r24c = (((r6 * 0x8A9) >> 11) - r7) + r26b;
        out[0] = (r11 + r29 + 0x7F) >> 8;
        out[7] = ((r11 - r29) + 0x7F) >> 8;
        out[1] = (r24b + r9 + 0x7F) >> 8;
        out[6] = ((r24b - r9) + 0x7F) >> 8;
        out[2] = (r25c + r26b + 0x7F) >> 8;
        t += 8;
        out[5] = ((r25c - r26b) + 0x7F) >> 8;
        out[4] = (r0 + r24c + 0x7F) >> 8;
        out[3] = ((r0 - r24c) + 0x7F) >> 8;
        out += stride;
    }
}

void fn_80125960(void *arg0, s32 arg1, void *arg2, void *arg3) {
    s32 sp8[64];
    s32 *var_r12;
    s32 *var_r4;
    s16 temp_r0, temp_r10, temp_r23, temp_r25, temp_r4, temp_r4_2, temp_r7, temp_r8, temp_r9;
    s32 temp_r0_2, temp_r0_3, temp_r0_4, temp_r0_5, temp_r0_6, temp_r0_7;
    s32 temp_r10_2, temp_r10_3, temp_r10_4, temp_r10_5, temp_r10_6;
    s32 temp_r11;
    s32 temp_r11_2, temp_r11_3, temp_r11_4, temp_r11_5;
    s32 temp_r12, temp_r12_2, temp_r12_3, temp_r12_4, temp_r12_5;
    s32 temp_r23_2, temp_r23_3, temp_r23_4, temp_r23_5, temp_r23_6, temp_r23_7, temp_r23_8, temp_r23_9, temp_r23_10, temp_r23_11;
    s32 temp_r24, temp_r24_2, temp_r24_3, temp_r24_4, temp_r24_5, temp_r24_6, temp_r24_7, temp_r24_8;
    s32 temp_r25_2, temp_r25_3, temp_r25_4, temp_r25_5, temp_r25_6;
    s32 temp_r26, temp_r26_2, temp_r26_3, temp_r27, temp_r28, temp_r29, temp_r30;
    s32 temp_r4_3, temp_r4_4, temp_r5, temp_r5_2, temp_r6;
    s32 temp_r7_2, temp_r7_3, temp_r7_4, temp_r7_5;
    s32 temp_r8_2, temp_r8_3, temp_r8_4, temp_r8_5;
    s32 temp_r9_2, temp_r9_3, temp_r9_4, temp_r9_5, temp_r9_6, temp_r9_7, temp_r9_8;
    s32 var_ctr, var_ctr_2;
    u32 temp_r11_6;
    u8 *var_r31;
    u8 *var_r3;
    s16 *var_r5;
    s32 *var_r6;
    var_r3 = (u8 *)arg0;
    var_r5 = (s16 *)arg2;
    var_r6 = (s32 *)arg3;
    var_r31 = var_r3 + arg1;
    temp_r30 = arg1 * 2;
    var_r12 = sp8;
    for (var_ctr = 0; var_ctr < 8; var_ctr++) {
        temp_r7 = var_r5[8];
        temp_r8 = var_r5[24];
        temp_r23 = var_r5[16];
        temp_r0 = var_r5[32];
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
    for (var_ctr_2 = 0; var_ctr_2 < 8; var_ctr_2++) {
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
        temp_r12_4 = ((u8)((temp_r12_3 + temp_r10_4 + 0x7F) >> 8) & ~0xFF0000) | (((temp_r8_4 >> 8) << 16) & 0xFF0000);
        temp_r12_5 = temp_r12_4 | (temp_r12_4 << 8);
        temp_r23_10 = ((((temp_r12_3 - temp_r10_4) + 0x7F) << 8) & 0xFF0000 & ~0xFF) | ((temp_r11_6 >> 8) & 0xFF);
        temp_r9_7 = ((u8)((temp_r23_9 - temp_r8_5 + 0x7F) >> 8) & ~0xFF0000) | ((((temp_r0_7 + temp_r24_8 + 0x7F) >> 8) << 16) & 0xFF0000);
        M2C_FIELD(var_r3, s32 *, 0) = temp_r12_5;
        temp_r9_8 = temp_r9_7 | (temp_r9_7 << 8);
        temp_r10_5 = (((temp_r23_9 + temp_r8_5 + 0x7F) << 8) & 0xFF0000 & ~0xFF) | (((temp_r0_7 - temp_r24_8 + 0x7F) >> 8) & 0xFF);
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
/* Run the inverse DCT (fn_80125664) on the coefficients into dst, selecting a
 * 256-byte quantization table from lbl_802F6A40 by index. */
void fn_80125CA0(void *dst, void *stride, void *coeffs, s32 quantTable) {
    fn_80125664(dst, stride, coeffs, (u8 *)&lbl_802F6A40 + (quantTable << 8));
}

extern void fn_80125960(void *p0, s32 p1, void *p2, void *p3);
/* IDCT block decode: dequantize the 8x8 coefficients in `coeffs` with the
   quantization table indexed by `quantTable` (each 0x100-byte slice of
   lbl_802F6A40 is one table) and write rows `stride` bytes apart to `dst`. */
void fn_80125CB4(void *dst, void *stride, void *coeffs, s32 quantTable) {
    fn_80125960(dst, (s32)stride, coeffs, (u8 *)&lbl_802F6A40 + (quantTable << 8));
}

extern u8 lbl_802F7A40[];
void fn_80125CC8(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, s32 arg5) {
    s32 sp8[64];
    register u8 *var_r6;
    register u8 *var_r6_2;
    s16 temp_r0, temp_r10, temp_r11, temp_r12, temp_r22, temp_r26, temp_r30, temp_r31;
    s32 temp_r0_10, temp_r0_2, temp_r0_3, temp_r0_4, temp_r0_5, temp_r0_6, temp_r0_7, temp_r0_8, temp_r0_9;
    s32 temp_r10_10, temp_r10_2, temp_r10_3, temp_r10_4, temp_r10_5, temp_r10_6, temp_r10_7, temp_r10_8, temp_r10_9;
    s32 temp_r11_2, temp_r11_3, temp_r11_4, temp_r12_2, temp_r12_3;
    s32 temp_r20, temp_r20_2, temp_r20_3, temp_r20_4, temp_r20_5, temp_r20_6;
    s32 temp_r21, temp_r21_2, temp_r22_2, temp_r22_3, temp_r23, temp_r23_2, temp_r23_3;
    s32 temp_r24, temp_r24_2, temp_r24_3, temp_r25, temp_r25_2, temp_r25_3, temp_r25_4;
    s32 temp_r26_2, temp_r26_3, temp_r26_4, temp_r26_5, temp_r27, temp_r27_2, temp_r28, temp_r28_2, temp_r28_3;
    s32 temp_r29, temp_r29_2, temp_r29_3, temp_r30_2, temp_r30_3, temp_r31_2, temp_r31_3, temp_r31_4;
    s32 temp_r5, temp_r5_2, temp_r9, temp_r9_2, var_ctr, var_ctr_2;
    u8 temp_r5_3;
    s32 t0, t40;
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
        temp_r31 = *(s16 *)(var_r5 + 0x60);
        temp_r12 = *(s16 *)(var_r5 + 0x50);
        temp_r11 = *(s16 *)(var_r5 + 0x40);
        temp_r10 = *(s16 *)(var_r5 + 0x30);
        temp_r30 = *(s16 *)(var_r5 + 0x70);
        temp_r0 = *(s16 *)(var_r5 + 0x10);
        temp_r26 = *(s16 *)(var_r5 + 0x20);
        if ((temp_r30 | (temp_r31 | temp_r12) | (temp_r11 | temp_r10 | (temp_r0 | temp_r26))) == 0) {
            temp_r10_2 = *(s16 *)var_r5;
            var_r5 += 2;
            temp_r0_2 = *(s32 *)var_r9;
            var_r9 += 4;
            temp_r0_3 = (s32)(temp_r10_2 * temp_r0_2) >> 0xB;
            *(s32 *)(var_r6 + 0) = temp_r0_3;
            *(s32 *)(var_r6 + 0x20) = temp_r0_3;
            *(s32 *)(var_r6 + 0x40) = temp_r0_3;
            *(s32 *)(var_r6 + 0x60) = temp_r0_3;
            *(s32 *)(var_r6 + 0x80) = temp_r0_3;
            *(s32 *)(var_r6 + 0xA0) = temp_r0_3;
            *(s32 *)(var_r6 + 0xC0) = temp_r0_3;
            *(s32 *)(var_r6 + 0xE0) = temp_r0_3;
            var_r6 += 4;
        } else {
            temp_r22 = *(s16 *)var_r5;
            var_r5 += 2;
            t0 = *(s32 *)(var_r9 + 0);
            t40 = *(s32 *)(var_r9 + 0x40);
            temp_r25 = *(s32 *)(var_r9 + 0x80);
            temp_r24 = *(s32 *)(var_r9 + 0xC0);
            temp_r20 = *(s32 *)(var_r9 + 0x20);
            temp_r23 = *(s32 *)(var_r9 + 0x60);
            temp_r22_2 = *(s32 *)(var_r9 + 0xA0);
            temp_r21 = *(s32 *)(var_r9 + 0xE0);
            temp_r26_2 = temp_r26 * t40;
            temp_r29 = (s32)(temp_r22 * t0) >> 0xB;
            var_r9 += 4;
            temp_r11_2 = temp_r26_2 >> 0xB;
            temp_r28 = (s32)(temp_r11 * temp_r25) >> 0xB;
            temp_r27 = temp_r29 + temp_r28;
            temp_r26_3 = temp_r29 - temp_r28;
            temp_r31_2 = (s32)(temp_r31 * temp_r24) >> 0xB;
            temp_r24_2 = temp_r11_2 + temp_r31_2;
            temp_r29_2 = temp_r27 + temp_r24_2;
            temp_r31_3 = temp_r27 - temp_r24_2;
            temp_r25_2 = ((s32)((temp_r11_2 - temp_r31_2) * 0xB50) >> 0xB) - temp_r24_2;
            temp_r11_3 = temp_r26_3 + temp_r25_2;
            temp_r28_2 = temp_r26_3 - temp_r25_2;
            temp_r0_4 = (s32)(temp_r0 * temp_r20) >> 0xB;
            temp_r10_3 = (s32)(temp_r10 * temp_r23) >> 0xB;
            temp_r20_2 = (s32)(temp_r12 * temp_r22_2) >> 0xB;
            temp_r12_2 = temp_r20_2 - temp_r10_3;
            temp_r23_2 = temp_r20_2 + temp_r10_3;
            temp_r10_4 = (s32)(temp_r30 * temp_r21) >> 0xB;
            temp_r30_2 = temp_r0_4 - temp_r10_4;
            temp_r0_5 = temp_r0_4 + temp_r10_4;
            temp_r10_5 = temp_r0_5 + temp_r23_2;
            *(s32 *)(var_r6 + 0) = temp_r29_2 + temp_r10_5;
            *(s32 *)(var_r6 + 0xE0) = temp_r29_2 - temp_r10_5;
            temp_r20_3 = (s32)((temp_r12_2 + temp_r30_2) * 0xEC8) >> 0xB;
            temp_r20_4 = (temp_r20_3 + ((s32)(temp_r12_2 * -0x14E8) >> 0xB)) - temp_r10_5;
            temp_r10_6 = ((s32)((temp_r0_5 - temp_r23_2) * 0xB50) >> 0xB) - temp_r20_4;
            *(s32 *)(var_r6 + 0x20) = temp_r11_3 + temp_r20_4;
            *(s32 *)(var_r6 + 0xC0) = temp_r11_3 - temp_r20_4;
            temp_r0_6 = (((s32)(temp_r30_2 * 0x8A9) >> 0xB) - temp_r20_3) + temp_r10_6;
            *(s32 *)(var_r6 + 0x40) = temp_r28_2 + temp_r10_6;
            *(s32 *)(var_r6 + 0xA0) = temp_r28_2 - temp_r10_6;
            *(s32 *)(var_r6 + 0x80) = temp_r31_3 + temp_r0_6;
            *(s32 *)(var_r6 + 0x60) = temp_r31_3 - temp_r0_6;
            var_r6 += 4;
        }
    }
    var_r6_2 = (u8 *)&sp8;
    for (var_ctr_2 = 0; var_ctr_2 < 8; var_ctr_2++) {
        temp_r22_3 = *(s32 *)(var_r6_2 + 8);
        temp_r21_2 = *(s32 *)(var_r6_2 + 0x18);
        temp_r10_7 = *(s32 *)(var_r6_2 + 0x14);
        temp_r0_7 = *(s32 *)(var_r6_2 + 0xC);
        temp_r9 = *(s32 *)(var_r6_2 + 4);
        temp_r5 = *(s32 *)(var_r6_2 + 0x1C);
        temp_r12_3 = temp_r10_7 - temp_r0_7;
        temp_r23_3 = temp_r10_7 + temp_r0_7;
        temp_r25_3 = *(s32 *)(var_r6_2 + 0);
        temp_r10_8 = *(s32 *)(var_r6_2 + 0x10);
        temp_r30_3 = temp_r9 - temp_r5;
        temp_r0_8 = temp_r9 + temp_r5;
        temp_r24_3 = temp_r22_3 + temp_r21_2;
        temp_r27_2 = temp_r25_3 + temp_r10_8;
        temp_r26_4 = temp_r25_3 - temp_r10_8;
        temp_r25_4 = ((s32)((temp_r22_3 - temp_r21_2) * 0xB50) >> 0xB) - temp_r24_3;
        temp_r10_9 = temp_r0_8 + temp_r23_3;
        temp_r29_3 = temp_r27_2 + temp_r24_3;
        temp_r11_4 = temp_r26_4 + temp_r25_4;
        temp_r28_3 = temp_r26_4 - temp_r25_4;
        temp_r0_9 = (temp_r29_3 - temp_r10_9) + 0x7F;
        temp_r26_5 = (s32)((temp_r0_8 - temp_r23_3) * 0xB50) >> 0xB;
        temp_r31_4 = temp_r27_2 - temp_r24_3;
        temp_r5_2 = temp_r30_3 * 0x8A9;
        temp_r20_5 = (s32)((temp_r12_3 + temp_r30_3) * 0xEC8) >> 0xB;
        temp_r9_2 = temp_r29_3 + temp_r10_9 + 0x7F;
        var_r6_2 += 0x20;
        *(s8 *)(var_r3 + 0) = (s8)(*(u8 *)(var_r7 + 0) + (temp_r9_2 >> 8));
        temp_r20_6 = (temp_r20_5 + ((s32)(temp_r12_3 * -0x14E8) >> 0xB)) - temp_r10_9;
        temp_r10_10 = temp_r26_5 - temp_r20_6;
        *(s8 *)(var_r3 + 7) = (s8)(*(u8 *)(var_r7 + 7) + (temp_r0_9 >> 8));
        temp_r0_10 = ((temp_r5_2 >> 0xB) - temp_r20_5) + temp_r10_10;
        *(s8 *)(var_r3 + 1) = (s8)(*(u8 *)(var_r7 + 1) + ((s32)(temp_r11_4 + temp_r20_6 + 0x7F) >> 8));
        *(s8 *)(var_r3 + 6) = (s8)(*(u8 *)(var_r7 + 6) + ((s32)((temp_r11_4 - temp_r20_6) + 0x7F) >> 8));
        *(s8 *)(var_r3 + 2) = (s8)(*(u8 *)(var_r7 + 2) + ((s32)(temp_r28_3 + temp_r10_10 + 0x7F) >> 8));
        *(s8 *)(var_r3 + 5) = (s8)(*(u8 *)(var_r7 + 5) + ((s32)((temp_r28_3 - temp_r10_10) + 0x7F) >> 8));
        *(s8 *)(var_r3 + 3) = (s8)(*(u8 *)(var_r7 + 3) + ((s32)((temp_r31_4 - temp_r0_10) + 0x7F) >> 8));
        temp_r5_3 = *(u8 *)(var_r7 + 4);
        var_r7 += arg5;
        *(s8 *)(var_r3 + 4) = (s8)(temp_r5_3 + ((s32)(temp_r31_4 + temp_r0_10 + 0x7F) >> 8));
        var_r3 += arg1;
    }
}

void fn_80126018(void *arg0, BitReader8011 *arg1) {
    s16 coef[64] = {0};
    u8 pad[0x44];
    u8 huff[6];
    u32 count = arg1->count;
    u32 *next = arg1->next;
    u32 value = arg1->value;
    s32 bits, lv, n;
    u32 bit, top, mask, hmask;
    u8 *outp = huff, *p, *end;
    u32 sym, w, r22, sg, cv, bb;

#define RDBIT(b) do { if (count == 0) { b = *next++; count = 31; value = b >> 1; } else { b = value; value >>= 1; count--; } } while (0)
#define RDCOEF(off) do { \
    if (count == 0) { \
        w = *next++; \
        if (!(w & 1)) { sg = 0; r22 = w >> 1; count = 0x1F - n; value = w >> (n + 1); } \
        else { sg = 1; value = w >> 1; count = 0x1F; } \
    } else { \
        if (!(value & 1)) { \
            count--; \
            if (count < (u32)n) { w = *next++; r22 = (value >> 1) | (w << count); value = w >> (n - count); count = (count + 0x20) - n; } \
            else { r22 = value >> 1; value = value >> (n + 1); count -= n; } \
            sg = 0; \
        } else { value >>= 1; sg = 1; } \
    } \
    if (sg) { *--outp = (u8)(((sym + (off)) * 4) + 3); } \
    else { cv = bit | (r22 & mask); if (r22 & top) cv = (u32)-(s32)cv; coef[sym + (off)] = (s16)cv; } \
} while (0)
#define RDSIGN(off) do { \
    RDBIT(bb); \
    if (bb & 1) { *--outp = (u8)(((sym + (off)) * 4) + 3); } \
    else { RDBIT(bb); coef[sym + (off)] = (s16)(-(bb & 1) | 1); } \
} while (0)

    if (count < 4) {
        w = *next++;
        bits = (s32)((value | (w << count)) & 0xF);
        value = w >> (4 - count);
        count += 28;
    } else {
        bits = (s32)(value & 0xF);
        value >>= 4;
        count -= 4;
    }

    outp[0] = 0x10; outp[1] = 0x60; outp[2] = 0xB0;
    outp[3] = 0x07; outp[4] = 0x0B; outp[5] = 0x0F;

    end = outp + 6;
    lv = bits - 1;
    n = bits;
    bit = 1U << lv;

    if (bits > 1) {
      do {
        top = 1U << (n - 1);
        mask = top - 1;
        hmask = 0xFFFFFFFFU >> (32 - n);
        p = outp;
        while (p < end) {
          u32 h = *p;
          if (h == 0) { p++; continue; }
          RDBIT(bb);
          if (!(bb & 1)) { p++; continue; }
          switch (h & 3) {
          case 0:
            sym = h >> 2;
            *p = (u8)(((sym + 4) * 4) + 1);
            RDCOEF(0); RDCOEF(1); RDCOEF(2); RDCOEF(3);
            p++;
            break;
          case 1:
            sym = h >> 2;
            *p = (u8)((sym * 4) + 2);
            end[0] = (u8)(((sym + 4) * 4) + 2);
            end[1] = (u8)(((sym + 8) * 4) + 2);
            end[2] = (u8)(((sym + 0xC) * 4) + 2);
            end += 3;
            p++;
            break;
          case 2:
            *p = 0;
            sym = h >> 2;
            p++;
            RDCOEF(0); RDCOEF(1); RDCOEF(2); RDCOEF(3);
            break;
          case 3:
            sym = h >> 2;
            if (count < (u32)n) {
                w = *next++;
                r22 = hmask & (value | (w << count));
                value = w >> (n - count);
                count = (count + 0x20) - n;
            } else {
                r22 = hmask & value;
                value >>= n;
                count -= n;
            }
            cv = bit | (r22 & mask);
            if (r22 & top) cv = (u32)-(s32)cv;
            *p = 0;
            coef[(sym >> 1) & 0x7FFFFFFE] = (s16)cv;
            p++;
            break;
          }
        }
        bit >>= 1;
        n--;
        lv--;
      } while (lv != 0);
    }

    if (bits != 0) {
        p = outp;
        while (p < end) {
          u32 h = *p;
          if (h == 0) { p++; continue; }
          RDBIT(bb);
          if (!(bb & 1)) { p++; continue; }
          switch (h & 3) {
          case 0:
            sym = h >> 2;
            *p = (u8)(((sym + 4) * 4) + 1);
            RDSIGN(0); RDSIGN(1); RDSIGN(2); RDSIGN(3);
            p++;
            break;
          case 1:
            sym = h >> 2;
            *p = (u8)((sym * 4) + 2);
            end[0] = (u8)(((sym + 4) * 4) + 2);
            end[1] = (u8)(((sym + 8) * 4) + 2);
            end[2] = (u8)(((sym + 0xC) * 4) + 2);
            end += 3;
            p++;
            break;
          case 2:
            *p = 0;
            sym = h >> 2;
            p++;
            RDSIGN(0); RDSIGN(1); RDSIGN(2); RDSIGN(3);
            break;
          case 3:
            sym = h >> 2;
            RDBIT(bb);
            *p = 0;
            coef[(sym >> 1) & 0x7FFFFFFE] = (s16)(-(bb & 1) | 1);
            p++;
            break;
          }
        }
    }

    arg1->next = next;
    arg1->value = value;
    arg1->count = count;
    *(s16 *)((u8 *)arg0 + 0x2) = coef[1];
    *(s32 *)((u8 *)arg0 + 0x4) = *(s32 *)&coef[4];
    *(s32 *)((u8 *)arg0 + 0x8) = *(s32 *)&coef[8];
    *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)&coef[12];
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)&coef[2];
    *(s32 *)((u8 *)arg0 + 0x14) = *(s32 *)&coef[6];
    *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)&coef[10];
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)&coef[14];
    *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)&coef[24];
    *(s32 *)((u8 *)arg0 + 0x24) = *(s32 *)&coef[44];
    *(s32 *)((u8 *)arg0 + 0x28) = *(s32 *)&coef[16];
    *(s32 *)((u8 *)arg0 + 0x2C) = *(s32 *)&coef[20];
    *(s32 *)((u8 *)arg0 + 0x30) = *(s32 *)&coef[26];
    *(s32 *)((u8 *)arg0 + 0x34) = *(s32 *)&coef[46];
    *(s32 *)((u8 *)arg0 + 0x38) = *(s32 *)&coef[18];
    *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)&coef[22];
    *(s32 *)((u8 *)arg0 + 0x40) = *(s32 *)&coef[28];
    *(s32 *)((u8 *)arg0 + 0x44) = *(s32 *)&coef[32];
    *(s32 *)((u8 *)arg0 + 0x48) = *(s32 *)&coef[48];
    *(s32 *)((u8 *)arg0 + 0x4C) = *(s32 *)&coef[52];
    *(s32 *)((u8 *)arg0 + 0x50) = *(s32 *)&coef[30];
    *(s32 *)((u8 *)arg0 + 0x54) = *(s32 *)&coef[34];
    *(s32 *)((u8 *)arg0 + 0x58) = *(s32 *)&coef[50];
    *(s32 *)((u8 *)arg0 + 0x5C) = *(s32 *)&coef[54];
    *(s32 *)((u8 *)arg0 + 0x60) = *(s32 *)&coef[36];
    *(s32 *)((u8 *)arg0 + 0x64) = *(s32 *)&coef[40];
    *(s32 *)((u8 *)arg0 + 0x68) = *(s32 *)&coef[56];
    *(s32 *)((u8 *)arg0 + 0x6C) = *(s32 *)&coef[60];
    *(s32 *)((u8 *)arg0 + 0x70) = *(s32 *)&coef[38];
    *(s32 *)((u8 *)arg0 + 0x74) = *(s32 *)&coef[42];
    *(s32 *)((u8 *)arg0 + 0x78) = *(s32 *)&coef[58];
    *(s32 *)((u8 *)arg0 + 0x7C) = *(s32 *)&coef[62];
}

#define RB8011(out) do { \
    if (var_r27 == 0) { \
        (out) = *(const u32 *)var_r29; \
        var_r27 = 0x1F; \
        var_r29 += 4; \
        var_r28 = (out) >> 1U; \
    } else { \
        (out) = var_r28; \
        var_r28 = var_r28 >> 1U; \
        var_r27 = var_r27 - 1; \
    } \
} while (0)
#pragma push
#pragma scheduling on
void fn_80126A10(s8 *arg0, void *arg1, u32 arg2) {
    u8 buf[0xC0];
    u32 var_r31;
    u32 var_r30;
    const u8 *var_r29;
    u32 var_r28;
    u32 var_r27;
    u8 *var_r26;
    u32 var_r24;
    s32 var_r25;
    s32 var_r12;
    s32 var_r8;
    u8 *var_r9;
    u8 *var_r10;
    u32 var_r11;
    u8 temp_r25;
    u32 temp_r7, temp_shift;
    u32 temp_r26, temp_r26_2, temp_r26_3, var_r26_2;
    s32 temp_r7_2;
    s32 var_ctr;

    var_r30 = 0;
    var_r27 = ((BitReader8011 *)arg1)->count;
    var_r29 = (const u8 *)((BitReader8011 *)arg1)->next;
    var_r28 = ((BitReader8011 *)arg1)->value;
    if (var_r27 < 3U) {
        temp_r7 = *(const u32 *)var_r29;
        temp_shift = 3 - var_r27;
        var_r29 += 4;
        var_r24 = (var_r28 | (temp_r7 << var_r27)) & 7;
        var_r28 = temp_r7 >> temp_shift;
        var_r27 += 0x1D;
    } else {
        var_r24 = var_r28 & 7;
        var_r28 = var_r28 >> 3U;
        var_r27 = var_r27 - 3;
    }
    var_r9 = &buf[0x84];
    buf[0x84] = 0x10;
    var_r12 = 1 << var_r24;
    var_r10 = var_r9 + 4;
    var_r8 = var_r24 + 1;
    buf[0x85] = 0x60;
    var_r31 = 0;
    buf[0x86] = 0xb0;
    buf[0x87] = 2;
    while (var_r8 != 0) {
        u8 *var_r11_2;
        temp_r7_2 = -var_r12;
        var_r26 = buf;
        for (var_ctr = var_r31; var_ctr != 0; var_ctr--) {
            RB8011(var_r11);
            if (var_r11 & 1) {
                temp_r25 = *var_r26;
                var_r25 = var_r12;
                if ((s8)*(arg0 + temp_r25) < 0) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *(arg0 + temp_r25) = *(arg0 + temp_r25) + var_r25;
            }
            var_r26 += 1;
        }
        var_r11_2 = var_r9;
    loop_82:
        if (var_r11_2 >= var_r10) goto loop_done;
        temp_r26 = *var_r11_2;
        if ((s32)temp_r26 == 0) goto block_81;
        RB8011(var_r24);
        if (var_r24 & 1) {
            switch (temp_r26 & 3) {
            case 0:
                var_r26_2 = temp_r26 >> 2U;
                *var_r11_2 = ((var_r26_2 + 4) * 4) + 1;
            block_29:
                RB8011(var_r24);
                if (var_r24 & 1) {
                    var_r9--;
                    *var_r9 = (s8)((var_r26_2 * 4) + 3);
                    goto block_40;
                }
                buf[var_r31] = (u8)var_r26_2;
                var_r31 += 1;
                RB8011(var_r24);
                var_r25 = var_r12;
                if (var_r24 & 1) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *(arg0 + var_r26_2) = var_r25;
            block_40:
                RB8011(var_r24);
                if (var_r24 & 1) {
                    var_r9--;
                    *var_r9 = (s8)(((var_r26_2 + 1) * 4) + 3);
                    goto block_51;
                }
                buf[var_r31] = (u8)(var_r26_2 + 1);
                var_r31 += 1;
                RB8011(var_r24);
                var_r25 = var_r12;
                if (var_r24 & 1) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *((s8 *)arg0 + var_r26_2 + 1) = (s8)var_r25;
            block_51:
                RB8011(var_r24);
                if (var_r24 & 1) {
                    var_r9--;
                    *var_r9 = (s8)(((var_r26_2 + 2) * 4) + 3);
                    goto block_62;
                }
                buf[var_r31] = (u8)(var_r26_2 + 2);
                var_r31 += 1;
                RB8011(var_r24);
                var_r25 = var_r12;
                if (var_r24 & 1) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *((s8 *)arg0 + var_r26_2 + 2) = (s8)var_r25;
            block_62:
                RB8011(var_r24);
                if (var_r24 & 1) {
                    var_r9--;
                    *var_r9 = (s8)(((var_r26_2 + 3) * 4) + 3);
                    goto loop_82;
                }
                buf[var_r31] = (u8)(var_r26_2 + 3);
                var_r31 += 1;
                RB8011(var_r24);
                var_r25 = var_r12;
                if (var_r24 & 1) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *((s8 *)arg0 + var_r26_2 + 3) = (s8)var_r25;
                goto loop_82;
            case 1:
                temp_r26_2 = temp_r26 >> 2U;
                *var_r11_2 = (temp_r26_2 * 4) + 2;
                *(var_r10 + 0) = ((temp_r26_2 + 4) * 4) + 2;
                *(var_r10 + 1) = (s8)(((temp_r26_2 + 8) * 4) + 2);
                *(var_r10 + 2) = (s8)(((temp_r26_2 + 0xC) * 4) + 2);
                var_r10 += 3;
                goto loop_82;
            case 2:
                *var_r11_2 = 0;
                var_r26_2 = temp_r26 >> 2U;
                var_r11_2 += 1;
                goto block_29;
            case 3:
                temp_r26_3 = temp_r26 >> 2U;
                buf[var_r31] = (u8)temp_r26_3;
                var_r31 += 1;
                RB8011(var_r24);
                var_r25 = var_r12;
                if (var_r24 & 1) var_r25 = temp_r7_2;
                if (var_r30 == arg2) goto done;
                var_r30 += 1;
                *(arg0 + temp_r26_3) = var_r25;
                *var_r11_2 = 0;
                break;
            }
        } else {
            goto block_81;
        }
    block_81:
        var_r11_2 += 1;
        goto loop_82;
    loop_done:
        var_r12 = var_r12 >> 1;
        var_r8 -= 1;
    }
done:
    ((BitReader8011 *)arg1)->next = (u32 *)var_r29;
    ((BitReader8011 *)arg1)->value = var_r28;
    ((BitReader8011 *)arg1)->count = var_r27;
}
#pragma pop
extern void fn_80126A10(s8 *, void *, u32);
void fn_80126EF0(u8 *dstBlock, s32 dstPitch, s32 reader, s32 maxCoeffs, u8 *srcBlock, s32 srcPitch) {
    // Decodes one 8x8 block of signed 8-bit residuals from the bit stream at
    // `reader` (fn_80126A10, at most `maxCoeffs` coefficients) into `coeffs`,
    // then adds them to the 8x8 block at `srcBlock` and writes the result to
    // `dstBlock`; both blocks are 8 bytes per row with the given pitch.
    // The decoder fills the coefficient buffer four bytes at a time, and each
    // 4-byte run becomes a 2x2 block of the output, so the rows below read the
    // buffer back in that interleaved order.
    u32 coeffs[16] = {0};
    u8 *dst = dstBlock;
    u8 *src = srcBlock;

    fn_80126A10((s8 *)coeffs, (void *)reader, (u32)maxCoeffs);
    // output rows 0-1 <- coefficient runs 0, 1, 2, 3
    dst[0] = ((u8 *)coeffs)[0] + src[0];
    dst[1] = ((u8 *)coeffs)[1] + src[1];
    dst[2] = ((u8 *)coeffs)[4] + src[2];
    dst[3] = ((u8 *)coeffs)[5] + src[3];
    dst[4] = ((u8 *)coeffs)[8] + src[4];
    dst[5] = ((u8 *)coeffs)[9] + src[5];
    dst[6] = ((u8 *)coeffs)[12] + src[6];
    dst[7] = ((u8 *)coeffs)[13] + src[7];
    dst += dstPitch;
    src += srcPitch;
    dst[0] = ((u8 *)coeffs)[2] + src[0];
    dst[1] = ((u8 *)coeffs)[3] + src[1];
    dst[2] = ((u8 *)coeffs)[6] + src[2];
    dst[3] = ((u8 *)coeffs)[7] + src[3];
    dst[4] = ((u8 *)coeffs)[10] + src[4];
    dst[5] = ((u8 *)coeffs)[11] + src[5];
    dst[6] = ((u8 *)coeffs)[14] + src[6];
    dst[7] = ((u8 *)coeffs)[15] + src[7];
    dst += dstPitch;
    src += srcPitch;
    // output rows 2-3 <- coefficient runs 6, 11, 4, 5
    dst[0] = ((u8 *)coeffs)[24] + src[0];
    dst[1] = ((u8 *)coeffs)[25] + src[1];
    dst[2] = ((u8 *)coeffs)[44] + src[2];
    dst[3] = ((u8 *)coeffs)[45] + src[3];
    dst[4] = ((u8 *)coeffs)[16] + src[4];
    dst[5] = ((u8 *)coeffs)[17] + src[5];
    dst[6] = ((u8 *)coeffs)[20] + src[6];
    dst[7] = ((u8 *)coeffs)[21] + src[7];
    dst += dstPitch;
    src += srcPitch;
    dst[0] = ((u8 *)coeffs)[26] + src[0];
    dst[1] = ((u8 *)coeffs)[27] + src[1];
    dst[2] = ((u8 *)coeffs)[46] + src[2];
    dst[3] = ((u8 *)coeffs)[47] + src[3];
    dst[4] = ((u8 *)coeffs)[18] + src[4];
    dst[5] = ((u8 *)coeffs)[19] + src[5];
    dst[6] = ((u8 *)coeffs)[22] + src[6];
    dst[7] = ((u8 *)coeffs)[23] + src[7];
    dst += dstPitch;
    src += srcPitch;
    // output rows 4-5 <- coefficient runs 7, 8, 12, 13
    dst[0] = ((u8 *)coeffs)[28] + src[0];
    dst[1] = ((u8 *)coeffs)[29] + src[1];
    dst[2] = ((u8 *)coeffs)[32] + src[2];
    dst[3] = ((u8 *)coeffs)[33] + src[3];
    dst[4] = ((u8 *)coeffs)[48] + src[4];
    dst[5] = ((u8 *)coeffs)[49] + src[5];
    dst[6] = ((u8 *)coeffs)[52] + src[6];
    dst[7] = ((u8 *)coeffs)[53] + src[7];
    dst += dstPitch;
    src += srcPitch;
    dst[0] = ((u8 *)coeffs)[30] + src[0];
    dst[1] = ((u8 *)coeffs)[31] + src[1];
    dst[2] = ((u8 *)coeffs)[34] + src[2];
    dst[3] = ((u8 *)coeffs)[35] + src[3];
    dst[4] = ((u8 *)coeffs)[50] + src[4];
    dst[5] = ((u8 *)coeffs)[51] + src[5];
    dst[6] = ((u8 *)coeffs)[54] + src[6];
    dst[7] = ((u8 *)coeffs)[55] + src[7];
    dst += dstPitch;
    src += srcPitch;
    // output rows 6-7 <- coefficient runs 9, 10, 14, 15
    dst[0] = ((u8 *)coeffs)[36] + src[0];
    dst[1] = ((u8 *)coeffs)[37] + src[1];
    dst[2] = ((u8 *)coeffs)[40] + src[2];
    dst[3] = ((u8 *)coeffs)[41] + src[3];
    dst[4] = ((u8 *)coeffs)[56] + src[4];
    dst[5] = ((u8 *)coeffs)[57] + src[5];
    dst[6] = ((u8 *)coeffs)[60] + src[6];
    dst[7] = ((u8 *)coeffs)[61] + src[7];
    dst += dstPitch;
    src += srcPitch;
    dst[0] = ((u8 *)coeffs)[38] + src[0];
    dst[1] = ((u8 *)coeffs)[39] + src[1];
    dst[2] = ((u8 *)coeffs)[42] + src[2];
    dst[3] = ((u8 *)coeffs)[43] + src[3];
    dst[4] = ((u8 *)coeffs)[58] + src[4];
    dst[5] = ((u8 *)coeffs)[59] + src[5];
    dst[6] = ((u8 *)coeffs)[62] + src[6];
    dst[7] = ((u8 *)coeffs)[63] + src[7];
}

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80127398(s32 groupIndex) {
    /* Invoke all callbacks in the selected callback group, if the group index is valid. */
    void *group;
    void *entry;
    s32 i;

    if (groupIndex >= -1 && groupIndex < 4) {
        group = (u8 *)lbl_8041D728 + groupIndex * 0x14 + 0x14;
    } else {
        group = 0;
    }
    if (group != 0) {
        entry = group;
        for (i = 0; i < *(s32 *)group; i++) {
            ((void (*)(void))*(void **) ((u8 *)entry + 4))();
            entry = (void *)((u32)entry + 4);
        }
    }
}
#pragma opt_propagation on
#pragma scheduling on
extern char lbl_8055DF08;
/* Returns the mode-exit request flag polled by mode loops to break out and tear down. */
char fn_8012742C(void) {
    return lbl_8055DF08;
}

void fn_80127434(void) {
    /* Clear the global mode-exit request flag read by fn_8012742C; mode loops poll
       it to break out and tear down, so this resets it before starting a new mode. */
    lbl_8055DF08 = 0;
}

#pragma dont_inline on
void fn_80127440(void* alarm) {
    /* Periodic alarm callback: drain home-button work (HomeMenu_drainHandover), then dispatch pending background tasks (fn_80127F94). */
    fn_80127F94(HomeMenu_drainHandover(alarm));
}
#pragma dont_inline reset

void fn_80127464(void *alarm) {
    /* Tail-call thunk: forward the alarm to the periodic callback that drains home-button work and dispatches background tasks. */
    fn_80127440(alarm);
}

void fn_80127468(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    /* Alarm callback: drain pending home-button work via HomeMenu_drainHandover, then hand off to fn_80127F70. */
    fn_80127F70(HomeMenu_drainHandover(alarm));
}

/* Platform exit hook: run the registered exit callbacks for this group, then
 * log "PlatExitProcess(%d)" with the same value. */
void fn_8012748C(s32 exitCode) {
    fn_80127398(exitCode);
    KERNEL_PlatExitProcess(exitCode);
}
extern f64 lbl_80561198;
extern f64 lbl_805611A8;
extern f32 lbl_805611A0;
extern f64 fn_8002EFBC(f32, f64);
extern void fn_80119288(void *, f32);
extern s32 fn_80119300(void *, s32, s32);
extern s32 fn_801199A4(void *, s32);
extern void fn_8011C4A0(s32, s32, s32, s32);
