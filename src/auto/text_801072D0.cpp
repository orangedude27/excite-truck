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
// nw4hbm::ut::IOStream: the abstract stream interface.  Only the virtuals this unit's
// wrappers call are named; the offset each one is reached through is on its line.
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
// The same nw4hbm::ut::IOStream seen by this unit's other wrappers: it mangles to the
// very same name (both are IOStream::Read(void*, u32)) but its virtual read sits one
// slot later, at vtable 0x2C.
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

void nw4hbm::ut::Font::InitReaderFunc(nw4hbm::ut::FontEncoding encoding) {
    struct Row { u32 a, b, c; };
    char *format = lbl_80328540;
    u32 v = (u32)this;
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
    u32 t = v & 0xFF000000U;
    if (t != 0x80000000U && (v & 0xFF800000U) != 0x81000000U) f = 0;
    if (f == 0 && (v & 0xF8000000U) != 0x90000000U) e = 0;
    if (e == 0 && t != 0xC0000000U) d = 0;
    if (d == 0 && (v & 0xFF800000U) != 0xC1000000U) c = 0;
    if (c == 0 && (v & 0xF8000000U) != 0xD0000000U) b = 0;
    if (b == 0 && (v & 0xFFFFC000U) != 0xE0000000U) a = 0;
    if (a == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(format + 0x30, 0x2B, format + 0x3C, (long)this);
    }
    Row *dst = (Row *)((char *)this + 4);
    switch (encoding) {
    case 0: {
        Row *row = (Row *)(format + 0x00);
        dst->a = *(u32 *)(format + 0x00);
        dst->b = row->b;
        dst->c = row->c;
        break;
    }
    case 1: {
        Row *row = (Row *)(format + 0x0C);
        dst->a = *(u32 *)(format + 0x0C);
        dst->b = row->b;
        dst->c = row->c;
        break;
    }
    case 2: {
        Row *row = (Row *)(format + 0x18);
        dst->a = *(u32 *)(format + 0x18);
        dst->b = row->b;
        dst->c = row->c;
        break;
    }
    default: {
        Row *row = (Row *)(format + 0x24);
        dst->a = *(u32 *)(format + 0x24);
        dst->b = row->b;
        dst->c = row->c;
        break;
    }
    }
}

/* nw4hbm::ut::IOStream::Read(void*, u32) -- ut_IOStream.cpp line 41.
   Reads `size` bytes into `buf` through the stream's virtual read (vtable 0x2C);
   a stream that reports failure does not support reading, which is fatal. */
extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl(nw4hbm::ut::IOStreamAsync* stream,
                                                 void* buf,
                                                 u32 size) {
#define sFileUtIOStream lbl_803285B8 /* __FILE__: "ut_IOStream.cpp" */
#define sMsgNoReadSupport lbl_803285C8 /* "Stream don't support READ function\n" */
    if (stream->Read(buf, size) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(sFileUtIOStream, 0x29, sMsgNoReadSupport);
    }
#undef sFileUtIOStream
#undef sMsgNoReadSupport
    return 0;
}

extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801074E8(nw4hbm::ut::FileStream2* this_) {
    struct Helper {
        static void panic(const char *b, int l, int o) {
            Panic__Q26nw4hbm2dbFPCciPCce(b + 0, l, b + o);
        }
    };
    const char *file = lbl_803285B8;
    if (this_->Wait() == 0) {
        Helper::panic(file, 0x3E, 0x10);
    }
    if (this_->Cancel() == 0) {
        Helper::panic(file, 0x3F, 0x34);
    }
    return 0;
}

extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl_80107580(nw4hbm::ut::FileStream* stream,
                                                          s32 offset,
                                                          u32 origin) {
    /* Seek the stream and panic if the seek fails. */
    if (stream->Seek(offset, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_803285B8, 0x52, lbl_80328614);
    }
}

typedef s32 (*VFun1)(void*);
typedef u32 (*ReadFn)(void*, void*, u32);
#pragma push
#pragma opt_propagation off
extern "C" s32 CancelAsync__Q36nw4hbm2ut10FileStreamFPFlPQ36nw4hbm2ut8IOStreamPv_vPv_801075D0(nw4hbm::ut::FileStream3* this_) {
    register const char *file = lbl_803285B8;
    if (this_->Wait() == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x66, file + 0x5C);
    }
    if (this_->Cancel() == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(file, 0x67, file + 0x34);
    }
    return 0;
}
#pragma pop
/* nw4hbm::ut::IOStream::Read(void*, u32) -- ut_IOStream.cpp line 142.
   Reads `size` bytes into `buf` through the stream's virtual read (vtable 0x28);
   a stream whose read reports failure has no async read at all, which is fatal. */
extern "C" u32 Read__Q36nw4hbm2ut8IOStreamFPvUl_80107668(nw4hbm::ut::IOStream* stream,
                                                         void* buf,
                                                         u32 size) {
#define sFileUtIOStream lbl_803285B8 /* __FILE__: "ut_IOStream.cpp" */
#define sMsgNoAsyncSupport lbl_803285EC /* "Stream don't support ASYNC function\n" */
    if (stream->Read(buf, size) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(sFileUtIOStream, 0x8E, sMsgNoAsyncSupport);
    }
#undef sFileUtIOStream
#undef sMsgNoAsyncSupport
    return 0;
}

/* Address of the leaf (end) of the registered-object pointer chain
 * (lbl_8055DE98 -> lbl_8055DEA0 -> this global): the unit's static initializer
 * fn_801072C4 points the chain node lbl_8055DEA0 at it and fn_801076C4 clears
 * it back to null, so callers take its address to link or unlink the last
 * entry. */
extern "C" u32 *fn_801076BC(void) {
#define sChainLeaf lbl_8055DEA8
    return (u32 *)&sChainLeaf;
#undef sChainLeaf
}

