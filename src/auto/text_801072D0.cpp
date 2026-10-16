// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
typedef unsigned long u32;
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" void* lbl_8055DEA8;
extern "C" char lbl_803285B8[];
extern "C" char lbl_803285C8[];
extern "C" char lbl_803285EC[];
extern "C" char lbl_80328614[];

namespace nw4hbm {
namespace ut {
class IOStream {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 Read(void* buf, u32 size);   // vtable 0x28
    virtual void vfB();
    virtual u32 Seek(s32 off, u32 origin);   // vtable 0x30
};
class FileStream : public IOStream {};
class IOStreamAsync {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 Read(void* buf, u32 size);  // vtable 0x2C
};
class FileStream2 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 Cancel();  // vtable 0x28
    virtual u32 Wait();   // vtable 0x2C
};
class FileStream3 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 Cancel();  // vtable 0x28
    virtual void vfA();    // vtable 0x2C
    virtual u32 Wait();    // vtable 0x30
};
} // namespace ut
} // namespace nw4hbm

extern "C" u32 Seek__Q36nw4hbm2ut10FileStreamFlUl_80107580(nw4hbm::ut::FileStream* this_,
                                                            s32 off,
                                                            u32 origin) {
    if (this_->Seek(off, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803285B8, 0x52, lbl_80328614);
    }
    return 0;
}

typedef s32 (*VFun1)(void*);
typedef u32 (*ReadFn)(void*, void*, u32);
extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801075D0(void* this_) {
    s32 file = (s32)lbl_803285B8;
    if (((VFun1*)(*(void***)this_))[0x30 / 4](this_) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x66, (const char*)(file + 0x5C));
    }
    if (((VFun1*)(*(void***)this_))[0x28 / 4](this_) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)file, 0x67, (const char*)(file + 0x34));
    }
    return 0;
}

extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl_80107668(nw4hbm::ut::IOStream* this_,
                                                          void* buf,
                                                          u32 size) {
    if (this_->Read(buf, size) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803285B8, 0x8E, lbl_803285EC);
    }
    return 0;
}

extern "C" u32* fn_801076BC(void) {
    return (u32*)&lbl_8055DEA8;
}

