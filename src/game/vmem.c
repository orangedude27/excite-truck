// vmem — virtual memory ("VirtualMemory: %d K", vmem_buf).
// Recovered TU window 0x802E4C14..0x802E4D7C (see docs/attribution_analysis.md).
// Static-init thunk fn_802E4D7C (+ .ctors slot 0x802ED600) remains in
// auto/text_802E4D7C_.c pending a promotion pass.
extern void *fn_801284F8(int, void *);
extern int fn_8012850C(int, void *);
extern void fn_802E30C8(const char *, ...);
extern int lbl_8055D1C8;
extern char lbl_8034D1D0[];
extern char lbl_8034D204[];
extern char lbl_8034D1F0[];
// split_file divides it into the game's real files (file_status shows its range).

void fn_802E4C14(void) {
}

void fn_802E4C18(void) {
}

#pragma dont_inline on
/* Construct a VirtualMemory object: allocate it, install the vtable lbl_8034D1D0,
   create a "vmem_buf" backing buffer of size bytes (+4), record the size (+8),
   and log the allocation size in KiB. */
void *fn_802E4C1C(int size) {
    #pragma scheduling invalid_target
    char *vmem = fn_801284F8(0xC, &lbl_8055D1C8);
    if (vmem != 0) {
        *(char **)vmem = lbl_8034D1D0;
        *(int *)(vmem + 8) = size;
        *(int *)(vmem + 4) = fn_8012850C(size, lbl_8034D204);
        fn_802E30C8(lbl_8034D1F0, size / 1024);
    }
    return vmem;
}
#pragma scheduling on
#pragma dont_inline off

void *fn_802E4CA4(int arg0) {
    return fn_802E4C1C(arg0);
}

void fn_802E4CA8(unsigned char *dst, const signed char *src, int maxLen) {
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

void fn_802E4CDC(void) {
}

extern void fn_80128668(void *);
extern void fn_80128670(int);
void *fn_802E4CE0(void *arg0, int arg1) {
    /* Destroying destructor for VirtualMemory (vtable lbl_8034D1D0): free the
       backing buffer at +4, clear buffer and size, and delete if arg1 > 0. */
    if (arg0 != 0) {
        *(char **)arg0 = lbl_8034D1D0;
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
extern "C" void fn_802E4D50(void *vmem) {
    /* Virtual dispatch on a VirtualMemory object: jump to the vtable entry at
       offset 0x10 (fn_802E4D60). This is slot 1 of vtable lbl_8034D1D0. */
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

void fn_802E4D6C(void) {
}

void fn_802E4D70(void) {
}

int fn_802E4D74(void) {
    /* VirtualMemory vmethod (vtable slot 0x1C): a boolean query that always answers yes (true). */
    return 1;
}

