// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern "C" s32 lbl_804348E8[];
extern "C" void* lbl_8032F2BC;
extern "C" void* lbl_8032EBF8;
extern "C" void* lbl_8032EE68;
extern "C" f32 lbl_8056175C;
extern "C" void* memset(void*, s32, u32);

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
    virtual f32 v18(s32);
    virtual f32 v19(s32);
    virtual void v20();
    virtual s32 v21();
    virtual void v22();
    virtual s32 v23();
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

class Unk8015A368C {
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
    virtual f32 v18(s32);
    virtual void v19();
    virtual void v20();
    virtual s32 v21();
    virtual void v22();
    virtual s32 v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual s32 GetType();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33(f32*);
    s32 m4;
    u8 pad_4[0x250];
    s32 m258;
    u8 pad_25c[4];
    s32 m260;
};

class UnkVt33 {
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
};

extern "C" s32 fn_80128668(void*);
extern "C" void fn_801CB750(s32, s32);
extern "C" s32 fn_80179650();
extern "C" s32 fn_801CF064();
extern "C" void fn_8001EF5C(s32, s32);
extern "C" void fn_80131234(void*);
extern "C" void fn_801CB6E4(void*, s32);
extern void* lbl_8032E668[];
extern void* lbl_8032EFA8;
extern void* lbl_8032F0E8;
extern f32 lbl_80561750;
extern f32 lbl_80561754;
extern f32 lbl_8056177C;
extern f32 lbl_80558DC4[];
extern f32 lbl_8055E3C8;

extern "C" s32 lbl_8032E540[];
extern "C" s32 fn_80157278(s32 arg0) {
    s32* item = (s32*)lbl_804348E8[arg0];
    s32 value = item[4];
    return value == 0x41434152;
}

extern "C" s32 fn_80157558(void* arg0) {
    return *(s32*)((u8*)arg0 + 4);
}

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

extern "C" s32 lbl_804348E8[];
extern "C" void* lbl_8032F2BC;
extern "C" void* lbl_8032EBF8;
extern "C" void* lbl_8032EE68;
extern "C" f32 lbl_8056175C;
extern "C" void* memset(void*, s32, u32);
extern "C" void* fn_801579F4(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* ptr = (u8*)arg0 + 0x14;
    *(void**)((u8*)arg0 + 8) = ptr;
    *(void**)arg0 = &lbl_8032F2BC;
    *(s32*)((u8*)arg0 + 0x10) = 10;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < (u8*)arg0 + 0x244);
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    *(s32*)((u8*)arg0 + 0x244) = arg1;
    *(s32*)((u8*)arg0 + 0x248) = 0;
    *(s32*)((u8*)arg0 + 0x24C) = arg2;
    *(void**)arg0 = &lbl_8032EBF8;
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

extern "C" void* fn_80157CF0(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* ptr = (u8*)arg0 + 0x14;
    *(void**)((u8*)arg0 + 8) = ptr;
    *(void**)arg0 = &lbl_8032F2BC;
    *(s32*)((u8*)arg0 + 0x10) = 10;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < (u8*)arg0 + 0x244);
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    *(s32*)((u8*)arg0 + 0x244) = arg1;
    *(s32*)((u8*)arg0 + 0x258) = 0;
    *(f32*)((u8*)arg0 + 0x250) = lbl_8056175C;
    *(s32*)((u8*)arg0 + 0x268) = 0;
    *(s32*)((u8*)arg0 + 0x248) = 0;
    *(void**)arg0 = &lbl_8032EE68;
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

extern "C" s32 fn_80158A5C(void *arg0, s32 *arg1) { return *(s32 *)((u8 *)arg1 + 0x2620) == 0; }

extern "C" s32 fn_80158A6C(void) { return 0; }

extern "C" void fn_80158A74(void *arg0, f32 farg0) {
    *(f32 *)((u8 *)arg0 + 0x274) = farg0;
    *((u8 *)arg0 + 0x272) = 1;
}

extern "C" f32 lbl_80561754;
extern "C" void fn_80158A84(Unk801577F0 *arg0) {
    f32 zero = lbl_80561754;
    s32 i, offset;
    *((u8 *)arg0 + 0x273) = 0;
    *((u8 *)arg0 + 0x270) = 0;
    *((u8 *)arg0 + 0x271) = 0;
    *((u8 *)arg0 + 0x272) = 0;
    for (i = 0, offset = 0; i < arg0->mCount; i++, offset += 0x38) {
        *(s32 *)(arg0->mData + offset) = 0;
        *(s32 *)(arg0->mData + offset + 4) = 0;
        *(s32 *)(arg0->mData + offset + 8) = 0;
        *(f32 *)(arg0->mData + offset + 0xC) = zero;
    }
    *(f32 *)((u8 *)arg0 + 0x25C) = zero;
    *(f32 *)((u8 *)arg0 + 0x260) = zero;
    *(f32 *)((u8 *)arg0 + 0x258) = zero;
    *(f32 *)((u8 *)arg0 + 0x264) = zero;
    arg0->v31();
}

extern "C" void fn_80158D0C(void* arg0) {
    if (*(f32*)((char*)arg0 + 0x260) > *(f32*)((char*)arg0 + 0x24c)) {
        if (*(s32*)((char*)arg0 + 0x268) != 0) {
            fn_801CB750(*(s32*)((char*)arg0 + 0x268), *(s32*)((char*)arg0 + 4));
        }
        *(f32*)((char*)arg0 + 0x260) = lbl_80561754;
    }
}

extern "C" void fn_80158F34(void**);
extern "C" void fn_80158D60(void*, void*);
extern "C" void fn_80158E88(void* arg0, void* arg1) {
    void* sp8 = arg1;
    s32 temp_r31;
    fn_80158F34(&sp8);
    if (*(f32*)((u8*)arg0 + 0x25C) > lbl_80561754) {
        fn_80158D60(arg0, sp8);
    }
    temp_r31 = *(s32*)((u8*)(*(u32*)((u8*)arg0 + 8) +
        (*(s32*)((u8*)arg0 + 0xC) - 1) * 0x38) + 4);
    if (temp_r31 > 0 && fn_80179650() == 1 &&
        *(s32*)((u8*)arg1 + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(3, temp_r31);
    }
}

#pragma dont_inline on
void fn_80158F34(void** arg0) {

}
void fn_80158F34b(void* arg0, void* arg1) {
}
#pragma dont_inline off

extern "C" s32 fn_80158F60(Unk8015A368C* arg0) {
    return arg0->v21() > 0;
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
            fn_801CB750(r3, *(s32*)((char*)arg0 + 4));
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

extern "C" void fn_80159BB4(Unk801577F0* arg0) {
    f32 f = lbl_80561754;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 r5 = 0;
    for (; r6 < arg0->mCount; r6++) {
        *(s32*)(arg0->mData + r7) = r5;
        *(s32*)(arg0->mData + r7 + 4) = r5;
        *(s32*)(arg0->mData + r7 + 8) = r5;
        *(f32*)(arg0->mData + r7 + 0xC) = f;
        r7 += 0x38;
    }
    f32 b = lbl_80561750;
    f32 a = lbl_80561754;
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = a;
    arg0->m25c = b;
    arg0->v31();
}

extern "C" void fn_80159E2C(Unk8015A368C* arg0) {
    fn_80131234(lbl_8032E668[arg0->GetType()]);
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

extern "C" void fn_8015A318(Unk8015A368C* arg0) {
    s32 r5;
    if ((r5 = arg0->m260) > 0) {
        s32 r3 = arg0->m258;
        if (r3 != 0) {
            fn_801CB6E4((void*)r3, *(s32*)&arg0->m4);
        }
        arg0->m260 = 0;
    }
}

extern "C" f32 fn_8015A368(void* arg0) {
    f32 sp8;
    Unk8015A368C* obj = (Unk8015A368C*)arg0;
    s32 v21ret = obj->v21();
    sp8 = *(f32*)((u8*)arg0 + 0x25C) * obj->v18(v21ret);
    obj->v33(&sp8);
    obj->v31();
    f32 f = lbl_80561750;
    *(s32*)((u8*)arg0 + 0x264) = 0;
    *(f32*)((u8*)arg0 + 0x25C) = f;
    return sp8;
}

extern "C" s32 fn_8015A404(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x2620);
}

extern "C" void fn_8015A538(void* arg0, void* arg1) {
    void* sp8 = arg1;
    fn_80158F34(&sp8);
    if (*(s32*)((char*)arg0 + 0x264) > 0) {
        fn_80158F34b((void*)arg0, *(void**)((char*)&sp8));
    }
    void* r4 = *(void**)((char*)arg0 + 8);
    void* r3 = (void*)((s32)r4 + (*(s32*)((char*)arg0 + 0xC) - 1) * 0x38);
    s32 r31 = *(s32*)((char*)r3 + 4);
    if (r31 > 0 && fn_80179650() == 1 && *(s32*)((char*)arg1 + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(4, r31);
    }
}

extern "C" void fn_8015A7D8(void* arg0, void* arg1) {
    s32 flag;
    if (((u8*)arg0)[0x2D1] != 0) {
        return;
    }
    flag = (*(f32*)((u8*)arg1 + 0x25BC) > lbl_80558DC4[0]);
    if (flag) {
        ((u8*)arg0)[0x2D1] = 1;
        *(f32*)((u8*)arg0 + 0x2D4) = lbl_8055E3C8;
    }
}

extern "C" s32 fn_8015A814(void) {
    return 9;
}

extern "C" s32 fn_8015C684(void) {
    return 4;
}

extern "C" u32 fn_8015CC28(void) { return 1; }

extern "C" void fn_8015CD0C(void) {

}

extern "C" void fn_8015CDD8(void) {
}

extern "C" u32 fn_8015D364(void) { return 1; }

extern "C" u32 fn_8015D37C(void) { return 1; }

extern "C" u32 fn_8015D498(void) { return 1; }

extern "C" void fn_8015D6BC(Unk8015A368C* arg0) {
    fn_80131234(lbl_8032E668[arg0->GetType()]);
}

extern void* lbl_8032E7F8[];
extern "C" void fn_8015D6FC(Unk8015A368C* arg0) {
    fn_80131234(lbl_8032E7F8[arg0->GetType()]);
}

extern void* lbl_8032E9E0[];
extern "C" void fn_8015D73C(Unk8015A368C* arg0) {
    fn_80131234(lbl_8032E9E0[arg0->GetType()]);
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

extern "C" void fn_801593F0(Unk801577F0* arg0) {
    s32 r3;
    f32 b;
    f32 a;
    arg0->v31();
    *(f32*)((u8*)arg0 + 0x25c) = lbl_80561754;
    if (*(f32*)((u8*)arg0 + 0x260) > *(f32*)((u8*)arg0 + 0x24c)) {
        r3 = *(s32*)((u8*)arg0 + 0x268);
        if (r3 != 0) {
            fn_801CB750(r3, arg0->m4);
        }
        *(f32*)((u8*)arg0 + 0x260) = lbl_80561754;
    }
    r3 = *(s32*)((u8*)arg0 + 0x278);
    b = lbl_8056177C;
    a = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x264) = a;
    *(f32*)((u8*)arg0 + 0x258) = b;
    if (r3 != 0) {
        *(u8*)((u8*)r3 + 0x4A) = 1;
        *(u8*)((u8*)r3 + 0x4C) = 0;
    }
}

extern "C" s32 fn_80159708(void* arg0) {
    f32 f0 = *(f32*)((char*)arg0 + 0x25c);
    return (s32)f0;
}

