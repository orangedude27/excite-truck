// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef long s32;
typedef unsigned long u32;
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" void* lbl_8055DEA8;
extern "C" char lbl_80328540[];
extern "C" char lbl_803285B8[];
extern "C" char lbl_803285C8[];
extern "C" char lbl_803285EC[];
extern "C" char lbl_80328614[];

namespace nw4hbm {
namespace ut {
enum FontEncoding { FontEncodingDefault };
class Font { public: void InitReaderFunc(int); void InitReaderFunc(FontEncoding); };
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

void nw4hbm::ut::Font::InitReaderFunc(int encoding) {
    unsigned long fmt=(unsigned long)this, high;
    int a=1,b=1,c=1,d=1,e=1,f=1;
    high=fmt&0xFF000000;
    if ((unsigned long)(high+0x80000000)!=0 && (unsigned long)((fmt&0xFF800000)+0x7F000000)!=0) f=0;
    if (f==0 && (unsigned long)((fmt&0xF8000000)+0x70000000)!=0) e=0;
    if (e==0 && (unsigned long)(high+0x40000000)!=0) d=0;
    if (d==0 && (unsigned long)((fmt&0xFF800000)+0x3F000000)!=0) c=0;
    if (c==0 && (unsigned long)((fmt&0xF8000000)+0x30000000)!=0) b=0;
    if (b==0 && (unsigned long)((fmt&0xFFFFC000)+0x20000000)!=0) a=0;
    if (a==0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80328540+0x30,0x2b,lbl_80328540+0x3c,(long)this);
    unsigned long *table=(unsigned long *)lbl_80328540, *dst=(unsigned long *)((char *)this+4);
    unsigned long offset=encoding==0?0:encoding==1?3:encoding==2?6:9;
    dst[0]=table[offset]; dst[1]=table[offset+1]; dst[2]=table[offset+2];
}

extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl(nw4hbm::ut::IOStreamAsync* this_,
                                                  void* buf,
                                                  u32 size) {
    if (this_->Read(buf, size) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803285B8, 0x29, lbl_803285C8);
    }
    return 0;
}

extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801074E8(nw4hbm::ut::FileStream2* this_) {
    const char *file = (const char *)lbl_803285B8;
    if (this_->Wait() == 0) {
        const char *name = file;
        Panic__Q26nw4hbm2dbFPCciPCce(name, 0x3E, name + 0x10);
    }
    if (this_->Cancel() == 0) {
        const char *name = file;
        Panic__Q26nw4hbm2dbFPCciPCce(name, 0x3F, name + 0x34);
    }
    return 0;
}

extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl_80107580(nw4hbm::ut::FileStream* this_,
                                                          s32 off,
                                                          u32 origin) {
    if (this_->Seek(off, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803285B8, 0x52, lbl_80328614);
    }
}

typedef s32 (*VFun1)(void*);
typedef u32 (*ReadFn)(void*, void*, u32);
extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801075D0(nw4hbm::ut::FileStream3* this_) {
    const char *file = lbl_803285B8;
    if (this_->Wait() == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(&lbl_803285B8[0], 0x66, file + 0x5C);
    }
    if (this_->Cancel() == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char *)file, 0x67, file + 0x34);
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

