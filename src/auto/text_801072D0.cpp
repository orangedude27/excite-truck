// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
typedef unsigned long u32;
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" void* lbl_8055DEA8;
extern "C" char lbl_803285B8[];
extern "C" char lbl_803285EC[];
extern "C" char lbl_80328614[];

extern "C" u32 Seek__Q36nw4hbm2ut10FileStreamFlUl_80107580(void* this_,
                                                            s32 off,
                                                            u32 origin) {
    u32 result = ((u32 (*)(void*, s32, u32))((*(void***)this_)[0x30 / 4]))(
        this_, off, origin);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x52,
                                     (const char*)lbl_80328614);
    }
    return result;
}

extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801075D0(void* this_) {
    u32 result = ((u32 (*)(void*))((*(void***)this_)[0x30 / 4]))(this_);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x66,
                                     (const char*)lbl_80328614);
    }
    result = ((u32 (*)(void*))((*(void***)this_)[0x28 / 4]))(this_);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x67,
                                     (const char*)lbl_803285EC);
    }
    return 0;
}

extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl_80107668(void* this_,
                                                          void* buf,
                                                          u32 size) {
    u32 result = ((u32 (*)(void*, void*, u32))((*(void***)this_)[0x28 / 4]))(
        this_, buf, size);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_803285B8, 0x8E,
                                     (const char*)lbl_803285EC);
    }
    return result;
}

extern "C" u32* fn_801076BC(void) {
    return (u32*)&lbl_8055DEA8;
}

