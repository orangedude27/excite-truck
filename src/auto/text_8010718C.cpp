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
    virtual u32 Seek(s32 off, u32 origin);  // vtable 0x54
};
class FileStream54 : public IOStream54 {};
class IOStream50 {
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
    virtual u32 Seek(s32 off, u32 origin);  // vtable 0x50
};
class FileStream50 : public IOStream50 {};
} // namespace ut
} // namespace nw4hbm
extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl(nw4hbm::ut::FileStream50* this_,
                                                   s32 offset,
                                                   u32 origin) {
    #define FILE_STREAM_SOURCE_FILE lbl_80328458
    #define SEEK_ASSERT_MESSAGE lbl_8032846C

    /* Seek within the file stream and panic if the seek operation fails. */
    if (this_->Seek(offset, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)FILE_STREAM_SOURCE_FILE, 0x2C,
                                     (const char*)SEEK_ASSERT_MESSAGE);
    }

    #undef FILE_STREAM_SOURCE_FILE
    #undef SEEK_ASSERT_MESSAGE
}

extern "C" void Seek__Q36nw4hbm2ut10FileStreamFlUl_801071DC(nw4hbm::ut::FileStream54* stream,
                                                            s32 offset,
                                                            u32 origin) {
    /* Seek the stream and panic if the seek is not supported. */
    if (stream->Seek(offset, origin) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce((const char*)lbl_80328458, 0x3C,
                                     (const char*)lbl_80328490);
    }
}

namespace nw4hbm {
namespace ut {
class IOStream {};
class FileStream {
public:
    typedef void (*CancelCallback)(long, IOStream*, void*);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual s32 v21(CancelCallback callback, void* user);
    s32 CancelAsync(CancelCallback callback, void* user);
typedef struct { char file[0x38]; char cancel[0x28]; char async[0x28]; } Msgs8010718C;
};
}
}

#pragma push
#pragma opt_propagation off
s32 nw4hbm::ut::FileStream::CancelAsync(CancelCallback callback, void* userArg) {
    /* Ask the stream to cancel a pending async read (virtual slot 0x54, v21) and
     * confirm it supports async operations (slot 0x28, v10), panicking if either
     * is unavailable. */
    static char sFile[0x38] = "ut_FileStream.cpp";
    static char sCancel[0x28] = "Stream don't support CANCEL function\n";
    static char sAsync[0x28] = "Stream don't support ASYNC function\n";
    if (v21(callback, userArg) == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(sFile, 0x4E, sCancel);
    }
    if (v10() == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(sFile, 0x4F, sAsync);
    }
    return 1;
}
#pragma pop
