// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void __register_global_object(void* p, void* dtor, void* allocator);
extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FD9C8(void*, int);
extern unsigned char lbl_80415060[];
extern unsigned char lbl_8041506C[];
void fn_800FD990(void) {
    void* sentinel = &lbl_8041506C[4];
    /* Construct the global player list: clear its size, self-link the sentinel, and register the archive destructor. */
    *(void**)&lbl_8041506C[4] = 0;
    *(void**)&lbl_8041506C[8] = 0;
    *(void**)&lbl_8041506C[0] = 0;
    *(void**)&lbl_8041506C[4] = sentinel;
    *(void**)&lbl_8041506C[8] = sentinel;
    __register_global_object(&lbl_8041506C,
                             (void*)&__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800FD9C8,
                             &lbl_80415060);
}
