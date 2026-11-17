#include <types.h>
extern char lbl_8032A05C[];

#pragma cplusplus on
class Dummy80128EF0 {
public:
    virtual void d0(s32, void *, s32) {}
    virtual void d1(s32, void *, s32) {}
    virtual void d2(s32, void *, s32) {}
};
#pragma cplusplus off

extern char lbl_8055DF88;
/* lbl_802F8E40: the four allocation-source names, indexed by the source id stored at
   heap block header +0x30 -- 0 "new[]", 1 "MemAlloc", 2 "MemAllocPhys", 3 "new". */
__declspec(section ".data") extern u32 lbl_802F8E40;
/* lbl_80559968: the string "unknown", the name for an out-of-range source id. */
extern u32 lbl_80559968;
extern char lbl_8032A430[];
extern char lbl_8032A01C[];
extern u8 lbl_8055DF80;
extern s32 lbl_8055DF84;
extern s32 lbl_8055DF98;
extern char lbl_8041E140[];
extern s32 lbl_8041E140_s32[];
extern char lbl_8032A000[];
extern char lbl_8032A068[];
extern char lbl_8032A074[];
extern char lbl_8041E160[];
extern s32 lbl_8055DF8C;
extern s32 lbl_8055DF90;
extern s32 lbl_8055DF94;
extern char lbl_8055DF81;
extern char lbl_8032A448[];
void fn_801287D0(void *);

s32 fn_801281F4(s32, s32);
void fn_802E30C8(void *, void *, void *, ...);
s32 fn_802E317C(void *, void *);
void fn_8012834C(void *, void *, s32);
void fn_802E3DF8(s32, void *, void *);
void fn_80128714(void *, s32, s32);
extern void *memset(void *, int, unsigned long);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

u32 fn_801281A0(s32 allocSource) {
    /* Name of the routine a heap block was allocated through, looked up by the
     * source id stored at block header +0x30 (0 "new[]", 1 "MemAlloc",
     * 2 "MemAllocPhys", 3 "new"); "unknown" when the id is out of range.
     * The four pointers are copied off the table first, then indexed. */
    const char *names[4];
    const char **p = (const char **)&lbl_802F8E40;
    names[0] = *p++;
    names[1] = *p++;
    names[2] = *p++;
    names[3] = *p;
    if (allocSource >= 0 && (u32)allocSource < 4) return (u32)names[allocSource];
    return (u32)&lbl_80559968; /* "unknown" */
}
#pragma scheduling off
s32 fn_801281F4(s32 value, s32 alignment) {
    /* Round value up to the next multiple of alignment (alignment is a power of two). */
    return ((value + alignment) - 1) & ~(alignment - 1);
}
#pragma scheduling on
/* No-op heap-manager begin hook: the caller passes a memory-region tag string,
   but this stub ignores it and does nothing. */
void fn_80128208(char *heapTag) {

}

extern char lbl_8032A01C[];
extern u32 lbl_802F8E40;
extern u32 lbl_80559968;
extern char lbl_8032A430[];
#pragma scheduling invalid_target
int fn_8012820C(void) {
    #define memBeginTag       lbl_8032A01C
    #define heapReadyFlag     lbl_8055DF90
    #define heapPendingSize   lbl_8055DF8C
    #define heapRingPrimary   lbl_8041E140
    #define heapRingSecondary lbl_8041E160
    #define heapBufferHandle  lbl_8055DF94
    s32 mem1Base, mem2Base, mem1Size, mem2Size;
    /* Start the heap manager, mark it ready, and seed the MEM1/MEM2 ring buffers
       with their arena bounds, keeping the primary base as the buffer handle. */
    ((void (*)(char *))fn_80128208)(memBeginTag);
    heapReadyFlag = 1;
    heapPendingSize = 0;
    mem2Base = 0;
    mem2Size = 0;
    fn_802E3DF8(0, &mem1Base, &mem1Size);
    fn_802E3DF8(1, &mem2Base, &mem2Size);
    fn_80128714(&heapRingPrimary, mem1Base, mem1Size);
    fn_80128714(&heapRingSecondary, mem2Base, mem2Size);
    heapBufferHandle = mem1Base;
    return 1;
    #undef memBeginTag
    #undef heapReadyFlag
    #undef heapPendingSize
    #undef heapRingPrimary
    #undef heapRingSecondary
    #undef heapBufferHandle
}
#pragma scheduling on
extern void fn_80128710(void);
#pragma dont_inline on
/* Shut down heap ring buffers: report usage for both regions, invoke the
   release callback on the primary buffer handle, then clear buffer globals. */
void fn_801282A0(void) {
#define heapRingPrimary   lbl_8041E140
#define heapRingSecondary lbl_8041E160
#define heapBufferHandle  lbl_8055DF94
#define heapStateFlag     lbl_8055DF90
    fn_801287D0(&heapRingPrimary);
    fn_801287D0(&heapRingSecondary);
    ((void (*)(s32))fn_80128710)(heapBufferHandle);
    heapBufferHandle = 0;
    heapStateFlag = 0;
#undef heapRingPrimary
#undef heapRingSecondary
#undef heapBufferHandle
#undef heapStateFlag
}
#pragma dont_inline reset

/* No-op hook in the heap subsystem, invoked during per-scene initialization;
   intentionally does nothing. */
void fn_801282E8(void) {

}

void fn_801282EC(s32 size) {
    /* Set the pending heap allocation size, consumed by the next fn_8012834C alloc. */
    #define heapPendingSize lbl_8055DF8C
    heapPendingSize = size;
    #undef heapPendingSize
}

void fn_801282F4(void) {
    /* Select the secondary heap ring (lbl_8055DF81 = 1) when its size word is positive.
       The bit trick (-v & ~v) >> 31 is 1 exactly when v > 0. */
    s32 secondarySize = ((s32 *)lbl_8041E160)[2];
    lbl_8055DF81 = (u32)((-secondarySize) & ~secondarySize) >> 31;
}

#define heapRingPrimary   lbl_8041E140
#define heapRingSecondary lbl_8041E160
/* Bytes currently allocated from the primary (0) or secondary (1) heap ring, else 0. */
s32 fn_80128314(s32 ringIndex) {
    if (ringIndex == 0) return ((s32 *)lbl_8041E140)[1];
    if (ringIndex == 1) return ((s32 *)lbl_8041E160)[1];
    return 0;
}

extern char lbl_8032A034[];
s32 fn_80127964(void);
void *fn_801288AC(void *, s32, char *, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8012834C(void *arg0, void *arg1, s32 arg2) {
    struct Ring {
        virtual void d0();
        virtual void d1();
        virtual void *alloc(s32, void *, s32);
    };
    s32 size;
    s32 mask;
    s32 sum;
    s32 offset;
    void *queue;
    void *result;

    fn_80127964();
    if (lbl_8055DF80 == 0 && (u8)lbl_8055DF88 != 0) {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A034, arg0);
    }

    size = lbl_8055DF8C;
    if (size != 0) {
        if ((u8)lbl_8055DF81 == 0) {
            if (size > 0x40) {
                queue = lbl_8041E140;
                mask = size - 1;
                sum = *(s32 *)((u8 *)queue + 0xC) +
                      *(s32 *)((u8 *)queue + 4);
                if (((sum + 0x40) & mask) != 0) {
                    offset = mask & (size - ((sum + 0x80) & mask));
                    result = ((Ring *)queue)->alloc(offset, lbl_8032A05C, 3);
                    *(u8 *)((u8 *)result - 0x1C) = 0;
                }
            }
        } else if (size > 0x40) {
            queue = lbl_8041E160;
            mask = size - 1;
            sum = *(s32 *)((u8 *)queue + 0xC) +
                  *(s32 *)((u8 *)queue + 4);
            if (((sum + 0x40) & mask) != 0) {
                offset = mask & (size - ((sum + 0x80) & mask));
                result = ((Ring *)queue)->alloc(offset, lbl_8032A05C, 3);
                *(u8 *)((u8 *)result - 0x1C) = 0;
            }
        }
        lbl_8055DF8C = 0;
    }

    if ((u8)lbl_8055DF81 != 0) {
        ((void *(*)(void *, void *, void *, s32))fn_801288AC)(
            lbl_8041E160, arg1, arg0, arg2);
    } else {
        ((void *(*)(void *, void *, void *, s32))fn_801288AC)(
            lbl_8041E140, arg1, arg0, arg2);
    }
    lbl_8055DF81 = 0;
}
#pragma scheduling on
#pragma cplusplus off

/* Debug heap allocation wrapper: allocate `size` bytes tagged with `label`, using allocation source id 1 ("MemAlloc"). */
s32 fn_801284E8(void *label, void *size) {
    fn_8012834C(label, size, 1);
}

/* Debug heap allocation wrapper: allocate `size` bytes tagged with `label`, using allocation source id 2. */
void fn_801284F0(void *label, void *size) {
    fn_8012834C(label, size, 2);
}

/* Named heap allocation through C++ operator new (source id 3): allocates
   `size` bytes and records `label` as the allocation's source name. */
void fn_801284F8(void *size, void *label) {
    fn_8012834C(label, size, 3);
}

/* Debug allocator wrapper: allocate a size-byte heap block through the "new[]" source (id 0), tagged with name. */
void fn_8012850C(void *size, void *name) {
    fn_8012834C(name, size, 0);
}

#pragma opt_propagation off
s32 fn_80128520(s32 arg0) {
    if (lbl_8055DF80 == 0)
        goto do_log;
    switch ((s32)lbl_8055DF84) {
    case 0:
        return ((s32 (*)(void *, void *, s32))fn_8012834C)(lbl_8032A068, (void *)arg0, 3);
    default:
        goto do_log;
    }
do_log:
    ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A074, arg0);
    return lbl_8055DF98;
}
#pragma opt_propagation reset
extern char lbl_8032A0A0[];
void fn_80128AA4(void *, u8 *, s32, s32);
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80128584(s32 ptr, s32 arg1) {
    s32 inPrimaryBuffer;
    u32 bufferStart;
    u32 bufferEnd;

    /* Free a ring-buffer allocation from the primary or secondary heap, if enabled. */
    if (((s32)lbl_8055DF80 == 0) || (ptr != 0)) {
        fn_80127964();
        if (((s32)lbl_8055DF80 == 0) && ((u8)lbl_8055DF88 != 0))
            ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A0A0);

        inPrimaryBuffer = 0;
        bufferStart = *(u32 *)(lbl_8041E140 + 0xC);
        if ((u32)ptr >= bufferStart) {
            bufferEnd = bufferStart + *(u32 *)(lbl_8041E140 + 8);
            if ((u32)ptr < bufferEnd)
                inPrimaryBuffer = 1;
        }
        if (inPrimaryBuffer != 0) {
            ((void (*)(void *, u8 *, s32))fn_80128AA4)(lbl_8041E140, (u8 *)ptr, arg1);
            return;
        }
        ((void (*)(void *, u8 *, s32))fn_80128AA4)(lbl_8041E160, (u8 *)ptr, arg1);
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma scheduling on
/* Set the save-state flag at lbl_8055DF88 to 1 (counterpart of fn_80128684; read by fn_80128690). */
void fn_80128678(void) {
    lbl_8055DF88 = 1;
}

extern char lbl_8055DF88;
/* Clear the save-state flag at lbl_8055DF88 (counterpart of fn_80128678, read by fn_80128690). */
void fn_80128684(void) {
    lbl_8055DF88 = 0;
}

/* Return nonzero while the save-state flag at lbl_8055DF88 is clear. */
s32 fn_80128690(void) {
    u8 flag = lbl_8055DF88;
    return flag == 0;
}

/* No-op release callback for the primary heap buffer handle: heap shutdown
 * (fn_801282A0) invokes it with the buffer handle, but this build does nothing. */
void fn_80128710(void) {

}

/* AX "get studio name" accessor stub, dispatched indirectly through a
 * function-pointer table. Returns the studio-name string; this build keeps
 * the placeholder "<unknown>" in lbl_8032A068. */
const char* __AXGetStudio_80129164(void) {
    #define s_studioName lbl_8032A068
    return s_studioName;
    #undef s_studioName
}

s32 fn_80129170(void *region, u32 value) {
    /* 1 when value falls in the half-open range [region[1], region[1] + region[3])
     * held by this memory-region descriptor, 0 otherwise. */
    u32 start = ((u32 *)region)[1];
    s32 result = 0;
    if (value >= start && value < start + ((u32 *)region)[3]) {
        result = 1;
    }
    return result;
}

/* Return this memory descriptor's word-2 count field (offset 0x8), the "used" side of the capacity/used pair in fn_801291A4. */
s32 fn_8012919C(void *descriptor) { return ((s32 *)descriptor)[2]; }

/* Difference of this descriptor's two 32-bit count fields (word 3 minus word 2), e.g. capacity minus used. */
s32 fn_801291A4(void *region) { return ((s32 *)region)[3] - ((s32 *)region)[2]; }

/* Return this memory descriptor's word-3 count field (offset 0xC), the "capacity" side of the capacity/used pair in fn_801291A4. */
s32 fn_801291B4(void *region) { return ((s32 *)region)[3]; }

/* No-op placeholder hook; one of a run of adjacent empty stubs
 * (fn_801291BC, fn_801291C0, fn_801291C4, ...) that intentionally do nothing. */
void fn_801291BC(void) {

}

/* No-op placeholder hook; one of a run of adjacent empty stubs
 * (fn_801291BC, fn_801291C0, fn_801291C4, ...) that intentionally do nothing. */
void fn_801291C0(void) {

}

/* No-op placeholder hook; one of a run of adjacent empty stubs
 * (fn_801291BC, fn_801291C0, fn_801291C4, ...) that intentionally do nothing. */
void fn_801291C4(void) {

}

/* 1 when value points into this heap's ring buffer, held as the half-open range
 * [buffer[3], buffer[3] + buffer[2]); 0 otherwise. */
s32 fn_801291C8(void *buffer, u32 value) {
    u32 bufferStart = ((u32 *)buffer)[3];
    s32 result = 0;
    if (value >= bufferStart) {
        u32 bufferEnd = bufferStart + ((u32 *)buffer)[2];
        if (value < bufferEnd) result = 1;
    }
    return result;
}

s32 fn_801291F4(void *region) {
#define HEAP_BASE_INDEX 1
    /* Return this heap region's base field (offset 0x4), the lower bound used by fn_801291FC. */
    s32 baseAddr = ((s32 *)region)[HEAP_BASE_INDEX];
    return baseAddr;
}

s32 fn_801291FC(void *region) {
    /* Bytes currently used in this heap region: high-water mark (+0x08) minus base (+0x04). */
    return ((s32 *)region)[2] - ((s32 *)region)[1];
}

/* Return this heap region's high-water-mark field (offset 0x8), the upper bound used by fn_801291FC. */
s32 fn_8012920C(void *region) { return ((s32 *)region)[2]; }

/* No-op placeholder hook; one of a run of adjacent empty stubs
 * (fn_80129214, fn_80129218, ...) that intentionally do nothing. */
void fn_80129214(void) {

}

/* No-op placeholder hook; one of a run of adjacent empty stubs
 * (fn_80129214, fn_80129218, ...) that intentionally do nothing. */
void fn_80129218(void) {

}

#pragma cplusplus on
#pragma scheduling invalid_target
/* Pad a ring buffer's allocation so the next block starts 0x40-byte aligned:
 * if (used + 0x40) is not aligned to the buffer size, allocate a padding block
 * through the ring's alloc vfunc and clear the flag byte at offset -0x1C. */
extern "C" void fn_8012921C(void *arg0, s32 arg1) {
    struct Ring {
        virtual void d0();
        virtual void d1();
        virtual void *alloc(s32, void *, s32);
    };
    void *queue;
    void *result;
    s32 sum;
    s32 mask;
    s32 size;
    s32 offset;
    if (arg1 <= 0x40)
        return;
    queue = arg0;
    size = arg1;
    mask = size - 1;
    sum = *(s32 *)((u8 *)queue + 0xC) + *(s32 *)((u8 *)queue + 4);
    if (((sum + 0x40) & mask) != 0) {
        offset = mask & (size - ((sum + 0x80) & mask));
        result = ((Ring *)queue)->alloc(offset, lbl_8032A05C, 3);
        *(u8 *)((u8 *)result - 0x1C) = 0;
    }
}
#pragma scheduling on
#pragma cplusplus off
void fn_80128584(s32, s32);

void fn_80128658(s32 block) {
    /* Free a "MemAlloc" heap block (allocation source id 1) through the ring-buffer free routine. */
    fn_80128584(block, 1);
}

/* Free a block that was allocated through MemAllocPhys (allocator source id 2):
   hand it and its source id to fn_80128584, which routes it to the right heap. */
void fn_80128660(s32 block) { fn_80128584(block, 2); }

/* Frees an object using allocator mode 3. */
void fn_80128668(s32 object) {
    fn_80128584(object, 3);
}

/* Free a block that was allocated through new[]: the allocator source id 0
   ("new[]" in the fn_801281A0 name table) is passed on to fn_80128584, which
   frees it and reports any mismatch with the id recorded in the block header.
   The siblings pick the other sources: 1 MemAlloc, 2 MemAllocPhys, 3 new. */
void fn_80128670(s32 block) {
    fn_80128584(block, 0);
}

#pragma scheduling invalid_target
void fn_801286A0(void *block, s32 size) {
    /* Shrink a primary-heap block by a 64-byte-aligned amount and stamp a "STKA" marker at its new end. */
    s32 *header = (s32 *)block;
    s32 alignedSize = size & ~0x3F;
    s32 markerOffset;
    u32 magic;

    header[-6] -= alignedSize;
    header[-5] -= alignedSize;
    ((s32 *)lbl_8041E140)[1] -= alignedSize;
    markerOffset = ((s32 (*)(s32, s32))fn_801281F4)(header[-5], 4);
    magic = 0x53544B41;
    *(u32 *)((u8 *)header + markerOffset) = magic;
}
#pragma scheduling on
/* Initializes a memory-region descriptor; when a base address is provided logs its range, otherwise aborts if a nonzero size was requested. */
void fn_80128714(void *arg0, s32 arg1, s32 arg2) {
    s32 *region = (s32 *)arg0;
    char *strings = lbl_8032A000; /* MemAlloc string table */
    s32 zero = 0;
    region[2] = arg2;
    region[1] = zero;
    region[4] = zero;
    region[3] = arg1;
    if (arg1 != 0) {
        fn_802E30C8(strings + 0xE8, (void *)arg1, (void *)arg2);
        fn_802E30C8(strings + 0x10C, (void *)region[3], (void *)(region[3] + region[2]));
        region[7] = zero;
        region[5] = zero;
        region[6] = 0x02000000;
        return;
    }
    if (arg2 == 0) {
        region[7] = zero;
        region[5] = zero;
        return;
    }
    ((s32 (*)(const char *, ...))fn_802E317C)(strings + 0x130, (void *)(arg2 / 1024));
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801287D0(void *arg0) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void m14(s32);
    };
    struct S {
        void *vtable;
        s32 errorCode;
        s32 endOffset;
        s32 currentUsed;
        s32 f10;
        s32 startOffset;
        u32 highWaterMark;
        u32 capacity;
    };
    struct S *heap = (struct S *)arg0;

    /* Print ring-buffer usage stats and abort if an allocation error was recorded. */
    fn_802E30C8(lbl_8032A000 + 0x140, (void *)(heap->startOffset / 1024), (void *)heap->capacity, (void *)(heap->capacity >> 10));
    fn_802E30C8(lbl_8032A000 + 0x178, (void *)heap->highWaterMark, (void *)(heap->highWaterMark >> 10), (void *)((heap->capacity - heap->highWaterMark) >> 10));
    ((void (*)(void *, ...))fn_802E30C8)(lbl_8032A000 + 0x1AC, (void *)((heap->endOffset - heap->startOffset) / 1024));
    if (heap->errorCode != 0) {
        ((Obj *)arg0)->m14(1);
        ((s32 (*)(void *, ...))fn_802E317C)(lbl_8032A000 + 0x1C8, (void *)heap->errorCode);
    }
    heap->currentUsed = 0;
}
#pragma pop
/* No-op stub that always returns 0 (used as a dummy allocator callback that reports failure). */
s32 fn_801288A4(void) {
    return 0;
}

extern char lbl_8032A1F8[];
extern char lbl_8032A204[];
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_801288AC(void *arg0, s32 arg1, char *arg2, s32 arg3) {
    struct Ring {
        virtual void d0();
        virtual void d1();
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void flush(s32);
    };
    register char *name = arg2;
    register void *ctx = arg0;
    register s32 size = arg1;
    register s32 request = size;
    register s32 extra = arg3;
    void *found;
    void *record;
    u8 *start;
    u8 *p;
    s32 limit;
    s32 rounded;
    size = ((s32 (*)(s32, s32))fn_801281F4)(size, 0x40);
    found = ((void *(*)(void *, s32))fn_801288A4)(ctx, size);
    if (found != NULL) {
        sprintf((char *)found + 4, lbl_8032A1F8, name, size);
        *((u8 *)found + 0x24) = 1;
        return (u8 *)found + 0x40;
    }
    limit = size + *(s32 *)((u8 *)ctx + 4) + 64;
    if (limit >= *(s32 *)((u8 *)ctx + 8)) {
        ((Ring *)ctx)->flush(1);
        ((s32 (*)(void *, ...))fn_802E317C)(lbl_8032A204, name, size);
    }
    record = (u8 *)*(void **)((u8 *)ctx + 0xC) + *(s32 *)((u8 *)ctx + 4);
    memset(record, 0, 0x40);
    strcpy((char *)record + 4, name);
    *((u8 *)record + 0x24) = 1;
    *(s32 *)((u8 *)record + 0x30) = extra;
    *(s32 *)((u8 *)record + 0x28) = size;
    *(s32 *)((u8 *)record + 0x2C) = request;
    *(u32 *)record = 0x53544B41;
    *(void **)((u8 *)record + 0x34) = *(void **)((u8 *)ctx + 0x10);
    *(u32 *)((u8 *)record + 0x3C) = 0x53544B41;
    *(void **)((u8 *)ctx + 0x10) = record;
    start = (u8 *)record + 0x40;
    memset(start, 0xE3, size);
    p = start + *(s32 *)((u8 *)record + 0x2C);
    while (p < start + ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)((u8 *)record + 0x2C), 4))
        *p++ = 0xE3;
    limit = size + *(s32 *)((u8 *)ctx + 4) + 0x40;
    *(s32 *)((u8 *)ctx + 4) = limit;
    if (limit < *(s32 *)((u8 *)ctx + 8)) {
        rounded = ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)((u8 *)record + 0x2C), 4);
        *(u32 *)(start + rounded) = 0x53544B41;
    }
    if (*(s32 *)((u8 *)ctx + 0x14) < *(s32 *)((u8 *)ctx + 4))
        *(s32 *)((u8 *)ctx + 0x14) = *(s32 *)((u8 *)ctx + 4);
    if ((u8 *)record + size + 0x40 >= *(u8 **)((u8 *)ctx + 0x1C))
        *(u8 **)((u8 *)ctx + 0x1C) = (u8 *)record + size + 0x40;
    if ((u8 *)record + 0x40 < *(u8 **)((u8 *)ctx + 0x18))
        *(u8 **)((u8 *)ctx + 0x18) = (u8 *)record + 0x40;
    return start;
}
#pragma scheduling on
#pragma cplusplus off
#pragma use_lmw_stmw on
u32 fn_801281A0(s32);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80128AA4(void *heap, u8 *pBlock, s32 allocSource, s32 arg3) {
    /* Validate a ring-buffer allocation's 0x40-byte header and data region, report any
       corruption to the panic logger, then walk the heap's free list to recompute its
       used offset. pBlock points just past the header; arg3 is unused by callers. */
    #define STKA_SIGNATURE 0x53544B41
    #define HEAP_FILL_PATTERN 0xE3
    u8 *p;
    char *msgs;
    u8 *header;
    u32 signature;
    u8 *entry;
    header = pBlock - 0x40;
    msgs = lbl_8032A000;
    signature = *(u32 *)header;
    if (signature != STKA_SIGNATURE)
        ((s32 (*)(void *, ...))fn_802E317C)(msgs + 0x228, header);
    if (*(u32 *)(pBlock + ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)(pBlock - 0x14), 4)) != STKA_SIGNATURE)
        ((s32 (*)(void *, ...))fn_802E317C)(msgs + 0x244, header + 4);
    p = pBlock + *(s32 *)(header + 0x2C);
    while (p < pBlock + ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)(header + 0x2C), 4)) {
        if (*p != HEAP_FILL_PATTERN)
            ((s32 (*)(void *, ...))fn_802E317C)(
                msgs + 0x278, p, p - (pBlock + *(s32 *)(header + 0x2C)), header + 4, *p, HEAP_FILL_PATTERN);
        p++;
    }
    if (*(u32 *)(header + 0x3C) != STKA_SIGNATURE)
        ((s32 (*)(void *, ...))fn_802E317C)(msgs + 0x2C8, header + 4, *(u32 *)(header + 0x3C));
    if (header[0x24] == 0)
        ((s32 (*)(void *, ...))fn_802E317C)(msgs + 0x304, header + 4);
    if (*(s32 *)(header + 0x30) != allocSource) {
        u32 newname = ((u32 (*)(s32))fn_801281A0)(allocSource);
        u32 oldname = ((u32 (*)(s32))fn_801281A0)(*(s32 *)(header + 0x30));
        ((s32 (*)(void *, ...))fn_802E317C)(msgs + 0x31C, header + 4, oldname, newname);
    }
    header[0x24] = 0;
    goto check;
loop:
    if (*(u8 *)((u8 *)entry + 0x24) != 0)
        goto done;
    *(void **)((u8 *)heap + 0x10) = *(void **)((u8 *)entry + 0x34);
    *(void **)((u8 *)entry + 0x34) = 0;
check:
    entry = *(u8 **)((u8 *)heap + 0x10);
    if (entry != 0)
        goto loop;
done:
    if (entry != 0) {
        unsigned int offset = (unsigned int)entry - *(unsigned int *)((u8 *)heap + 0xC);
        unsigned int value = *(unsigned int *)(entry + 0x28);
        value += offset;
        *(unsigned int *)((u8 *)heap + 4) = value + 0x40;
    } else
        *(u32 *)((u8 *)heap + 4) = 0;
    #undef STKA_SIGNATURE
    #undef HEAP_FILL_PATTERN
}
extern int strcmp(const char *, const char *);
extern char lbl_80559970, lbl_80559974;
#pragma push
#pragma use_lmw_stmw off
void fn_80128C5C(register void *arg0, int arg1, int arg2) {
    register char *text = lbl_8032A000;
    int used;
    int count;
    int offset;
    int equal;
    int useAlt;
    void *message;
    if ((arg1 & 1) != 0) {
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x348);
        offset = 0;
        used = 0;
        count = 0;
        goto check;
    loop:
        {
            char *record = *(char **)((char *)arg0 + 0xC) + offset;
            if (*(unsigned int *)record != 0x53544B41)
                ((void (*)(void *, ...))fn_802E317C)(text + 0x380, record);
            equal = !strcmp(record + 4, text + 0x5C);
            useAlt = 0;
            if (*(unsigned char *)(record + 0x24) != 0) {
                if (equal == 0)
                    useAlt = 1;
            }
            message = useAlt ? (void *)&lbl_80559970 : (void *)&lbl_80559974;
            fn_802E30C8(text + 0x394, message,
                        record + 4, (void *)*(int *)(record + 0x28), record);
            if (*(unsigned char *)(record + 0x24) == 0)
                used += *(int *)(record + 0x28) + 0x40;
            count++;
            offset += *(int *)(record + 0x28) + 0x40;
            if ((offset & 0x1F) == 0)
                fn_802E2D74(1);
        }
    check:
        if (offset < *(int *)((char *)arg0 + 4))
            goto loop;
        fn_802E30C8(text + 0x3B4,
                    (void *)(*(int *)((char *)arg0 + 4) / 1024),
                    (void *)(*(int *)((char *)arg0 + 8) / 1024),
                    (void *)((*(int *)((char *)arg0 + 8) - *(int *)((char *)arg0 + 4)) / 1024),
                    (void *)(used / 1024));
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x3E8, (void *)count);
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x3F8);
    }
}
#pragma pop
void fn_80128DCC(void *heap) {
    /* Walk heap entries and report any whose signature is not 'STKA'. */
    register s32 *heapWords = (s32 *)heap;
    register s32 offset = 0;
    register s32 *entry;
    goto check;
loop:
    entry = (s32 *)(heapWords[3] + offset);
    if ((u32)entry[0] != 0x53544B41)
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A430, entry);
    offset = offset + entry[10] + 0x40;
check:
    if (offset < heapWords[1])
        goto loop;
}

s32 fn_80128E58(void *heap, s32 size) {
    /* Return an aligned allocation address from the end of heap space, or 0 if not enough room. */
    s32 alignedSize = ((s32 (*)(s32, s32))fn_801281F4)(size, 0x40);
    s32 used = *(s32 *)((u8 *)heap + 8);
    s32 result;
    if (*(s32 *)((u8 *)heap + 4) < used - alignedSize)
        result = *(s32 *)((u8 *)heap + 0xC) + used - alignedSize;
    else
        result = 0;
    return result;
}

#define STKA_SIGNATURE 0x53544B41
/* Return the name string stored in an STKA allocation's 0x40-byte header (at
 * header+4), or the "<unknown>" string when the header signature is invalid. */
void *fn_80128EB4(void *unused, void *pBlock) {
    if ((u32)*(s32 *)((u8 *)pBlock - 0x40) != STKA_SIGNATURE) {
        return &lbl_8032A068;
    }
    return (u8 *)pBlock - 0x3C;
}
#undef STKA_SIGNATURE

/* Initialize a stack allocator's bookkeeping words: base pointer, zeroed cursor, size counter, and zeroed peak counter. */
void fn_80128ED8(void *allocator, s32 base, s32 size) {
    s32 *p = (s32 *)allocator;
    p[1] = base;
    p[2] = 0;
    p[3] = size;
    p[4] = 0;
}

#pragma cplusplus on
extern "C" void fn_80128EF0(void *arg0, s32 arg1) {
    /* Advance the buffer cursor to the next aligned boundary, reserve space via the virtual callback, and write a block tag. */
    s32 basePtr;
    s32 cursor;
    u32 alignedOffset;

    cursor = *(s32 *)((u8 *)arg0 + 8);
    alignedOffset = arg1 - (cursor & (arg1 - 1));
    if (alignedOffset < 0x30U) {
        alignedOffset += arg1;
    }

    basePtr = *(s32 *)((u8 *)arg0 + 4);
    ((Dummy80128EF0 *)arg0)->d2(alignedOffset - 0x30, &lbl_8032A05C, 3);
    *(u32 *)(basePtr + cursor) = 0x06630216;
}
#pragma cplusplus off
/* Log the light stack allocator's peak usage ("Max alloc <max>K/<total>K"),
 * converting its byte counters at +0x10 and +0xC to KiB. */
void fn_80128F68(void *allocator) {
    fn_802E30C8(lbl_8032A448,
        (void *)(*(s32 *)((u8 *)allocator + 0x10) / 1024),
        (void *)(*(s32 *)((u8 *)allocator + 0xC) / 1024));
}

extern s32 fn_801281F4(s32, s32);
extern s32 fn_802E317C(void *, void *);
extern char lbl_8032A470[];
void *fn_80128F94(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    register u32 *header = (u32 *)arg0;
    register void *logArg = arg2;
    s32 total;
    s32 size;
    u32 used;
    u8 *start;
    u8 *base;
    u8 *result;
    u8 *tag;
    volatile u32 *vh;
    s32 h2;
    s32 h4;

    size = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x10);
    total = size + 0x20;
    if (total + header[2] > header[3]) {
        ((void (*)(void *, ...))fn_802E317C)(lbl_8032A470, logArg, size / 1024);
    }
    used = header[2];
    start = (u8 *)header[1];
    base = start + used;
    result = base + 0x10;
    *(u32 *)base = 0xAAAA5555;
    *(s32 *)(base + 4) = arg3;
    vh = header;
    tag = (u8 *)(vh[1] + vh[2]) + size;
    *(u32 *)(tag + 0x10) = 0xFEEDFACE;
    *(s32 *)(tag + 0x14) = size;
    header[2] = header[2] + total;
    memset(result, 0xE3, size);
    h2 = (s32)header[2];
    h4 = (s32)header[4];
    if (h2 > h4) header[4] = header[2];
    return result;
}

#pragma dont_inline on
/* RealName: Arena_TrimToLastAllocatedBlock (rewinds used offset past trailing free blocks until the last allocated block tag is found). */
void fn_80129088(void *arg0) {
#define ALLOC_BLOCK_TAG_MAGIC 0x5555U
#define ALLOC_BLOCK_TAG_BIAS  0x55560000U
    s32 *candidate;
    s32 base;
    void *end;
    while (*(volatile s32 *)((u8 *)arg0 + 8) > 0) {
        base = *(s32 *)((u8 *)arg0 + 4);
        end = (void *)(base + *(s32 *)((u8 *)arg0 + 8));
        candidate = (s32 *)((u8 *)end - 0x20 - *(s32 *)((u8 *)end - 0xC));
        if ((u32)*candidate + ALLOC_BLOCK_TAG_BIAS == ALLOC_BLOCK_TAG_MAGIC)
            return;
        *(s32 *)((u8 *)arg0 + 8) = (s32)((u8 *)candidate - (u8 *)base);
    }
#undef ALLOC_BLOCK_TAG_MAGIC
#undef ALLOC_BLOCK_TAG_BIAS
}
#pragma dont_inline reset

void fn_801290CC(void *arena, void *block) {
    /* Mark the block's header tag as free, then rewind the arena to the last allocated block. */
#define ALLOC_BLOCK_FREE_TAG 0x06630216
    *(s32 *)((u8 *)block - 0x10) = ALLOC_BLOCK_FREE_TAG;
    fn_80129088(arena);
#undef ALLOC_BLOCK_FREE_TAG
}

s32 fn_801290DC(void *region, s32 size) {
    /* Return an aligned address from the end of the region, or 0 if there is no room. */
    s32 alignedSize = ((s32 (*)(s32, s32))fn_801281F4)(size, 0x40);
    s32 end = *(s32 *)((u8 *)region + 0xC);
    s32 result;
    if (*(s32 *)((u8 *)region + 8) < end - alignedSize)
        result = *(s32 *)((u8 *)region + 4) + end - alignedSize;
    else
        result = 0;
    return result;
}

extern char lbl_8032A498[];
#pragma scheduling invalid_target
void fn_80129138(void *allocator) {
    /* Log the lite allocator's usage ("using <used>K/<total>K"), converting
     * its byte counters at +8 and +0xC to KiB. */
    fn_802E30C8(lbl_8032A498,
        (void *)(*(s32 *)((u8 *)allocator + 8) / 1024),
        (void *)(*(s32 *)((u8 *)allocator + 0xC) / 1024));
}
#pragma scheduling on
