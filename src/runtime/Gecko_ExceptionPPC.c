#include <revolution/OS.h>
#include <runtime/Gecko_ExceptionPPC.h>

#define NUM_FRAGMENT 1

typedef struct FragmentInfo {
    const ExtabIndexInfo* eti; // at 0x0
    void* toc;                 // at 0x4
    BOOL regist;               // at 0x8
} FragmentInfo;

static FragmentInfo fragmentInfo[NUM_FRAGMENT];

/* Claims the first free entry of the fragment table for a loaded code fragment,
 * recording its exception-table index chain (eti) and its TOC, and returns that
 * entry's id (__unregister_fragment releases it again).  Returns -1 when no
 * entry is free; with NUM_FRAGMENT == 1 only the game itself can be registered.
 * Called from __init_cpp_exceptions() with &_eti_init_info and GetTOC(). */
int __register_fragment(const ExtabIndexInfo* eti, void* toc) {
    int i;
    FragmentInfo* frag;

    for (i = 0; i < NUM_FRAGMENT; i++) {
        frag = &fragmentInfo[i];

        if (!frag->regist) {
            frag->eti = eti;
            frag->toc = toc;
            frag->regist = TRUE;
            return 0;
        }
    }

    return -1;
}

void __unregister_fragment(int i) {
    FragmentInfo* frag;

    if (i < 0) {
        return;
    }

    if (i >= NUM_FRAGMENT) {
        return;
    }

    frag = &fragmentInfo[i];
    frag->eti = NULL;
    frag->toc = NULL;
    frag->regist = FALSE;
}
