#include <runtime/global_destructor_chain.h>

typedef void (*DtorFunction)(void* obj, s16 method);

typedef struct DtorLink {
    struct DtorLink* next; // at 0x0
    DtorFunction dtor;     // at 0x4
    void* object;          // at 0x8
} DtorLink;

DtorLink* __global_destructor_chain = NULL;

/* Register a global object by pushing its destructor entry onto the front of the global chain. */
void __register_global_object(void* object, DtorFunction dtor, DtorLink* link) {
    link->next = __global_destructor_chain;
    link->dtor = dtor;
    link->object = object;
    __global_destructor_chain = link;
}

void __destroy_global_chain(void) {
    /* Run and unlink all registered global/static object destructors in chain order. */
    DtorLink* link;

    while ((link = __global_destructor_chain)) {
        /* Pop destructor entry. */
        __global_destructor_chain = link->next;
        /* Destroy object (-1 requests complete destruction of all bases). */
        link->dtor(link->object, -1);
    }
}

#pragma section ".dtors$10"
DECL_SECTION(".dtors$10")
DECL_WEAK funcptr_t __destroy_global_chain_reference = __destroy_global_chain;
