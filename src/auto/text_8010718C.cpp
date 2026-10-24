// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" u8 lbl_80328458[];
extern "C" u8 lbl_8032846C[];
extern "C" u8 lbl_80328490[];
namespace nw4hbm {
namespace ut {
class IOStream54 {
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
    virtual void vf9();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE();
    virtual void vfF();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual u32 Seek(s32 off, u32 origin);  // vtable 0x54
};
class FileStream54 : public IOStream54 {};
} // namespace ut
} // namespace nw4hbm
extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl(void* this_, s32 off,
                                                   u32 origin) {
    void** vtable = *(void***)this_;
    u32 result = ((u32(*)(void*, s32, u32))(vtable[0x14]))(this_, off, origin);
    if (result == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328458, 0x2C,
                                     (const char*)lbl_8032846C);
    }
}

extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl_801071DC(nw4hbm::ut::FileStream54* this_,
                                                            s32 off,
                                                            u32 origin) {
    if (this_->Seek(off, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328458, 0x3C,
                                     (const char*)lbl_80328490);
    }
}

