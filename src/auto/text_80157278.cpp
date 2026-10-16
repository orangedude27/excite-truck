// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

class Unk801577F0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual f32 v19(s32);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual s32 GetType();
    virtual void v30();
    virtual s32 v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(f32*);
    s32 m4;
    u8 pad_8[4];
    u8* mData;
    s32 mCount;
    u8 pad_10[0x244];
    f32 m254;
    s32 m258;
    f32 m25c;
    s32 m260;
    s32 m264;
    s32 m268;
};

class Unk80159BB4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual f32 v20(s32);
    virtual void v21();
    virtual void v22();
    virtual s32 v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual s32 v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(f32*);
};

extern "C" s32 fn_80128668(void*);
extern "C" void fn_801CB750(s32);
extern "C" void fn_80131234(void*);
extern "C" void fn_801CB6E4(void*);
extern void* lbl_8032E668;
extern void* lbl_8032EFA8;
extern void* lbl_8032F0E8;
extern f32 lbl_80561750;
extern f32 lbl_80561754;
extern f32 lbl_8056177C;

extern "C" s32 lbl_8032E540[];
extern "C" s32 fn_801577F0(Unk801577F0* arg0) {
    return lbl_8032E540[arg0->GetType()];
}

extern "C" s32 fn_8015782C(s32* arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

extern "C" void* fn_80157928(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 if (arg0 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 *(u32*)((char*)arg0 + 8) = 0;
 *(u32*)((char*)arg0 + 0xC) = 0;
 *(u32*)((char*)arg0 + 0x10) = 0;
 }}}
 }
 if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

extern "C" void* fn_80157990(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 *(u32*)((char*)arg0 + 8) = 0;
 *(u32*)((char*)arg0 + 0xC) = 0;
 *(u32*)((char*)arg0 + 0x10) = 0;
 }}}
 
 if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

extern "C" void* fn_80157A98(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 if (arg0 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 *(u32*)((char*)arg0 + 8) = 0;
 *(u32*)((char*)arg0 + 0xC) = 0;
 *(u32*)((char*)arg0 + 0x10) = 0;
 }}}
 }
 if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

extern "C" void* fn_80158218(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 if (arg0 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 *(u32*)((char*)arg0 + 8) = 0;
 *(u32*)((char*)arg0 + 0xC) = 0;
 *(u32*)((char*)arg0 + 0x10) = 0;
 }}}
 }
 if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

extern "C" void* fn_8015868C(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 if (arg0 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 if ((u32)arg0 + 8 != 0) {
 *(u32*)((char*)arg0 + 8) = 0;
 *(u32*)((char*)arg0 + 0xC) = 0;
 *(u32*)((char*)arg0 + 0x10) = 0;
 }}}
 }
 if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

extern "C" void fn_80158D0C(void* arg0) {
    if (*(f32*)((char*)arg0 + 0x260) > *(f32*)((char*)arg0 + 0x24c)) {
        if (*(s32*)((char*)arg0 + 0x268) != 0) {
            fn_801CB750(*(s32*)((char*)arg0 + 4));
        }
        *(f32*)((char*)arg0 + 0x260) = lbl_80561754;
    }
}

void fn_80158F34(void) {

}

extern "C" void fn_801590A8(void* arg0) {
    void* vtable = *(void**)arg0;
    ((void (*)())((u8**)vtable)[0x21])();
    f32 f0 = *(f32*)((char*)arg0 + 0x24c);
    f32 f1 = *(f32*)((char*)arg0 + 0x260);
    f32 f2 = lbl_80561754;
    *(f32*)((char*)arg0 + 0x25c) = f2;
    if (f1 > f0) {
        s32 r3 = *(s32*)((char*)arg0 + 0x268);
        if (r3 != 0) {
            fn_801CB750(*(s32*)((char*)arg0 + 4));
        }
        f2 = lbl_80561754;
        *(f32*)((char*)arg0 + 0x260) = f2;
    }
    f1 = lbl_80561754;
    f0 = lbl_8056177C;
    *(f32*)((char*)arg0 + 0x264) = f1;
    *(f32*)((char*)arg0 + 0x258) = f0;
}

extern "C" void fn_80159724(void) {
}

extern "C" void fn_80159BB4(void* arg0) {
    f32 f = lbl_80561754;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 r5 = 0;
    for (; r6 < *(s32*)((u8*)arg0 + 0xC); r6++) {
        u8* r4 = *(u8**)((u8*)arg0 + 8) + r7;
        *(s32*)(r4) = r5;
        *(s32*)(r4 + 4) = r5;
        *(s32*)(r4 + 8) = r5;
        *(f32*)(r4 + 0xC) = f;
        r7 += 0x38;
    }
    *(s32*)((u8*)arg0 + 0x264) = 0;
    *(s32*)((u8*)arg0 + 0x260) = 0;
    *(f32*)((u8*)arg0 + 0x254) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25C) = lbl_80561750;
    (*(void (**)(void*))(*(u8**)*(void**)arg0 + 0x84))(arg0);
}

extern "C" void fn_80159E2C(Unk801577F0* arg0) {
    arg0->v31();
    fn_80131234(*(void**)((u8*)lbl_8032E668 + arg0->GetType() * 4));
}

extern "C" s32 fn_80159E6C(void) {
    return 4;
}

extern "C" void* fn_80159E74(void* arg0, s32 arg1) {
    if (arg0 == 0) {
        return arg0;
    }
    void* r0 = *(void**)((char*)arg0 + 0x2D8);
    *(void**)((char*)arg0 + 0) = lbl_8032EFA8;
    if (r0 != 0) {
        void* r4 = *(void**)r0;
        void (*method)(void*, s32) = *(void (**)(void*, s32))((u8**)r4 + 0x8);
        method(r0, 1);
    }
    if (arg0 != 0 && (char*)arg0 + 8 != 0) {
        *(u32*)((char*)arg0 + 8) = 0;
        *(u32*)((char*)arg0 + 0xC) = 0;
        *(u32*)((char*)arg0 + 0x10) = 0;
    }
    if (arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" u8 fn_80159F24(void* arg0) {
    return ((u8*)arg0)[0x2D1];
}

extern "C" void fn_8015A318(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x260) > 0) {
        if (*(s32*)((u8*)arg0 + 0x258) != 0) {
            fn_801CB6E4(*(void**)((u8*)arg0 + 4));
        }
        *(s32*)((u8*)arg0 + 0x260) = 0;
    }
}

extern "C" f32 fn_8015A368(void* arg0) {
    f32 sp8;
    ((Unk801577F0*)arg0)->v22();
    s32 v22ret = ((Unk801577F0*)arg0)->v19(0);
    sp8 = *(f32*)((u8*)arg0 + 0x25C) * (f32)v22ret;
    ((Unk801577F0*)arg0)->v35(&sp8);
    ((Unk801577F0*)arg0)->v33();
    *(s32*)((u8*)arg0 + 0x264) = 0;
    *(f32*)((u8*)arg0 + 0x25C) = lbl_80561750;
    return sp8;
}

extern "C" s32 fn_8015C684(void) {
    return 4;
}

extern "C" void fn_8015CD0C(void) {

}

extern "C" void fn_8015CDD8(void) {
}

extern "C" void fn_8015E0FC(void) {
}

extern "C" s32 fn_80159338(void) {
    return 3;
}

extern "C" void* fn_80159340(void* arg0, s32 arg1) {
    if (arg0 == 0) {
        return arg0;
    }
    void* r0 = *(void**)((char*)arg0 + 0x278);
    *(void**)((char*)arg0 + 0) = lbl_8032F0E8;
    if (r0 != 0) {
        void* r4 = *(void**)r0;
        void (*method)(void*, s32) = *(void (**)(void*, s32))((u8**)r4 + 2);
        method(r0, 1);
    }
    *(u32*)((char*)arg0 + 8) = 0;
    *(u32*)((char*)arg0 + 0xC) = 0;
    *(u32*)((char*)arg0 + 0x10) = 0;
    if (arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801593F0(void* arg0) {
    void* vtable = *(void**)arg0;
    ((void (*)())((u8**)vtable)[0x21])();
    *(f32*)((char*)arg0 + 0x25c) = lbl_80561754;
    if (*(f32*)((char*)arg0 + 0x260) > *(f32*)((char*)arg0 + 0x24c)) {
        if (*(s32*)((char*)arg0 + 0x268) != 0) {
            fn_801CB750(*(s32*)((char*)arg0 + 4));
        }
        *(f32*)((char*)arg0 + 0x260) = lbl_80561754;
    }
    *(f32*)((char*)arg0 + 0x264) = lbl_80561754;
    *(f32*)((char*)arg0 + 0x258) = lbl_8056177C;
    void* r3 = *(void**)((char*)arg0 + 0x278);
    if (r3 != 0) {
        *(u8*)((char*)r3 + 0x4A) = 1;
        *(u8*)((char*)r3 + 0x4C) = 0;
    }
}

extern "C" s32 fn_80159708(void* arg0) {
    f32 f0 = *(f32*)((char*)arg0 + 0x25c);
    return (s32)f0;
}

