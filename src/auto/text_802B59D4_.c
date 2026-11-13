// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct InitArrayB59D4 {
    void **data;
    int count, capacity;
    void *storage[16];
} InitArrayB59D4;
extern unsigned char lbl_804BE448[];
__declspec(section ".sdata") extern unsigned char lbl_8055F9E0[];
extern void fn_8000D838(void *);
extern void fn_802B5AC0(void *, int);
extern void fn_802B5A68(void *, int);
extern void __register_global_object(void *, void (*)(void *, int), void *);
static inline InitArrayB59D4 *initArrayB59D4(InitArrayB59D4 *a) {
    a->data = a->storage;
    a->capacity = 16;
    a->count = 0;
    return a;
}
/* Construct and register the two embedded arrays without defining their data. */
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma cplusplus on
extern "C" void fn_802B59D4(void) {
    unsigned char *base = lbl_804BE448;
    InitArrayB59D4 *first;
    InitArrayB59D4 *second;
    fn_8000D838(lbl_8055F9E0);
    first = (InitArrayB59D4 *)(base + 0xC);
    first->data = first->storage;
    first->capacity = 16;
    first->count = 0;
    __register_global_object(first, fn_802B5AC0, base);
    second = (InitArrayB59D4 *)(base + 0x64);
    second->data = second->storage;
    second->capacity = 16;
    second->count = 0;
    __register_global_object(second, fn_802B5A68, base + 0x58);
}
#pragma pop

#pragma cplusplus reset
