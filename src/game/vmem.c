// vmem — virtual memory ("VirtualMemory: %d K", vmem_buf).
// Recovered TU window 0x802E4C14..0x802E4D7C (see docs/attribution_analysis.md).
// Static-init thunk fn_802E4D7C (+ .ctors slot 0x802ED600) remains in
// auto/text_802E4D7C_.c pending a promotion pass.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801284F8(int, void *);  /* named-heap allocation */
extern int fn_8012850C(int, void *);    /* named-heap allocation of a byte buffer */
extern void fn_80128668(void *);       /* free */
extern void fn_80128670(int);          /* free a named-heap buffer */
extern void fn_802E30C8(const char *, ...); /* debug/log print */
extern int lbl_8055D1C8;               /* "vmem" heap tag */
extern char VirtualMemory_vtable[];            /* VirtualMemory vtable */
extern char lbl_8034D204[];            /* "vmem_buf" backing-buffer heap tag */
extern char lbl_8034D1F0[];            /* "VirtualMemory: %d K" */

/* No-op stub: called with a flag at the start of the per-tick system/physics
   update (fn_80176CC8); the argument is ignored and the body does nothing. */
void fn_802E4C14(void) {
}

/* No-op vmem hook: called with a flag at frame end (fn_802C2B48) and tick start
 * (fn_80176CC8); the argument is ignored and the body does nothing. */
void fn_802E4C18(void) {
}

#pragma dont_inline on
/* Construct a VirtualMemory object: allocate it, install the vtable VirtualMemory_vtable,
   create a "vmem_buf" backing buffer of size bytes (+4), record the size (+8),
   and log the allocation size in KiB. */
void *fn_802E4C1C(int size) {
    #pragma scheduling invalid_target
#define kVTable         VirtualMemory_vtable
#define kAllocTag       lbl_8055D1C8    /* "vmem" */
#define kBufferTag      lbl_8034D204    /* "vmem_buf" */
#define kSizeFormat     lbl_8034D1F0    /* "VirtualMemory: %d K" */
#define allocObject     fn_801284F8
#define createBuffer    fn_8012850C
#define logPrint        fn_802E30C8
    /* Construct a VirtualMemory object: allocate 0xC bytes, install the vtable,
       attach a "vmem_buf" backing buffer of size bytes, record the size, and
       log the allocation in KiB. */
    typedef struct {
        void *vtable;
        void *buffer;
        int size;
    } VirtualMemory;
    VirtualMemory *vmem;
    vmem = (VirtualMemory *)allocObject(0xC, &kAllocTag);
    if (vmem != 0) {
        vmem->vtable = kVTable;
        vmem->size = size;
        vmem->buffer = (void *)createBuffer(size, kBufferTag);
        logPrint(kSizeFormat, size / 1024);
    }
    return vmem;
#undef logPrint
#undef createBuffer
#undef allocObject
#undef kSizeFormat
#undef kBufferTag
#undef kAllocTag
#undef kVTable
}
#pragma scheduling on
#pragma dont_inline off

void *fn_802E4CA4(int size) {
    /* Tail-call wrapper: allocate a virtual-memory block of `size` bytes via fn_802E4C1C. */
    return fn_802E4C1C(size);
}

/* Bounded string copy: copy bytes from src into dst until a NUL is copied, but if maxLen bytes are copied first, overwrite the last byte with a NUL so the result is always terminated within maxLen bytes. */ void fn_802E4CA8(unsigned char *dst, const signed char *src, int maxLen) {
    /* Bounded string copy: copy bytes from src to dst until NUL, or NUL-terminate at maxLen on truncation. */
    unsigned char c;
    goto copy;
    for (;;) {
        if (--maxLen <= 0) {
            dst[-1] = 0;
            return;
        }
    copy:
        c = (unsigned char)*src;
        src++;
        *dst = c;
        dst++;
        if ((signed char)c == 0) return;
    }
}

/* No-op vmem hook: invoked from the debug menu after the cache-table actions
   (keys 0xB and 0x4); the body does nothing. */
void fn_802E4CDC(void) {
}

void *VirtualMemory_Destroy(void *arg0, int arg1) {
    /* Destroying destructor for VirtualMemory (vtable VirtualMemory_vtable): free the
       backing buffer at +4, clear buffer and size, and delete if arg1 > 0. */
    if (arg0 != 0) {
        *(char **)arg0 = VirtualMemory_vtable;
        fn_80128670(*(int *)((char *)arg0 + 4));
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma cplusplus on
extern "C" void VirtualMemory_forward(void *vmem) {
    /* VirtualMemory vtable slot +0xC (forward): re-dispatch to the
       getBufferOffset vmethod at +0x10 (fn_802E4D60) on the same object. */
    struct VirtualMemoryVtbl {
        virtual void destroy();
        virtual void forward();
        virtual void getBufferOffset();
    };
    ((VirtualMemoryVtbl *)vmem)->getBufferOffset();
}
#pragma cplusplus reset
#pragma pop
/* VirtualMemory vmethod (vtable slot 1): return the backing-buffer base at +4 advanced by offset. */
int fn_802E4D60(void *vmem, int offset) {
    return *(int *)((char *)vmem + 4) + offset;
}

/* Empty stub: vtable slot 0x14 of the VirtualMemory object (VirtualMemory_vtable),
   paired with the slot-0x18 stub fn_802E4D70. Does nothing. */
void fn_802E4D6C(void) {
}

/* Empty stub: vtable slot 0x18 of the VirtualMemory object (VirtualMemory_vtable),
   paired with the slot-0x14 stub fn_802E4D6C. */
void fn_802E4D70(void) {
}

int fn_802E4D74(void) {
    /* VirtualMemory vmethod (vtable slot 0x1C): a boolean query that always answers yes (true). */
    return 1;
}

