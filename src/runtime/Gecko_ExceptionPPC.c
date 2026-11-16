#include <revolution/OS.h>
#include <runtime/Gecko_ExceptionPPC.h>

// Number of code fragments the C++ exception handler can track.  The game is a
// single executable with no downloadable fragments, so just one slot exists.
#define NUM_FRAGMENT 1

// One loaded code fragment, as tracked for exception handling (an ETI is the
// "exception table index" chain describing the fragment's .extab/.ctab entries).
typedef struct FragmentInfo {
    const ExtabIndexInfo* eti; // at 0x0: fragment's exception table index
    void* toc;                 // at 0x4: fragment's TOC (r2), for its ctab
    BOOL regist;               // at 0x8: slot in use
} FragmentInfo;

// __register_fragment/__unregister_fragment state; the id a fragment is given
// is its index here, and the runtime's exception handler walks it to find the
// .extab/.ctab pair covering a faulting PC.
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

/* Releases the fragment-table slot with the given id, clearing its exception-table
 * index, TOC and in-use flag so a later __register_fragment can reuse it.  Invalid
 * ids are ignored.  Called from __fini_cpp_exceptions() with the id returned by
 * __register_fragment(). */
void __unregister_fragment(int fragmentId) {
    FragmentInfo* frag;

    if (fragmentId < 0) {
        return;
    }

    if (fragmentId >= NUM_FRAGMENT) {
        return;
    }

    frag = &fragmentInfo[fragmentId];
    frag->eti = NULL;
    frag->toc = NULL;
    frag->regist = FALSE;
}
