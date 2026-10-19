// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern "C" char lbl_8032F39C[];
extern "C" f32 lbl_8042FD08[];
extern "C" f32 lbl_80558DC4[];
extern "C" s32 lbl_8055A058[1];
extern "C" f32 fn_80204CFC(const char*);
extern "C" void* fn_8023139C(void*,s32,u32);
extern "C" void* fn_8017960C(s32);

class Fn8015889C {
public:
 virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual f32 v20(s32); virtual void v21(); virtual void v22(); virtual s32 v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(f32*);
 virtual void v36(); virtual s32 v37(); virtual void v38(f32);
};


typedef void (*vfn0_t)(void*);
class JStudio_JAudio {
public:
    class TAdaptor_sound {
    public:
        void endSound_fadeOut_(u32 arg0);
    };
};
namespace JStudio {
class JAudio {
public:
    class TAdaptor_sound {
    public:
        void endSound_fadeOut_(u32 arg0);
    };
};
}

extern "C" s32 lbl_804348E8[];
extern "C" void* lbl_8032F2BC;
extern "C" void* lbl_8032EBF8;
extern "C" void* lbl_8032EE68;
extern "C" f32 lbl_8056175C;
extern "C" void* memset(void*, s32, u32);

class Fn80159C34Obj {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
 virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17();
 virtual f32 v18(s32); virtual void a19(); virtual void a20(); virtual s32 v21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29(); virtual void a30(); virtual void v31(); virtual void v32(); virtual void v33(f32*); virtual void a34(); virtual void a35(); virtual void a36(); virtual s32 v37();
 s32 m4; u8 pad[0x24c]; f32 m254; s32 m258; f32 m25c; s32 m260; s32 m264;
};
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
          virtual s32 v35();
      s32 m4;
      u8* mData;
      s32 mCount;
      u8 m54;
      u8 pad_55[0x23C];
      f32 m250;
      f32 m254;
    s32 m258;
    f32 m25c;
          s32 m260;
      s32 m264;
      s32 m268;
      s32 m26c;
      s32 m270;
            f32 m274;
      f32 m278;
      f32 m27c;
      virtual void v36();
      virtual s32 v37();
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

class Unk8015E910V {
public:
    virtual void v0(s32);
    virtual void v1(s32);
    virtual void v2(s32);
    virtual void v3(s32);
    virtual void v4(s32);
    virtual void v5(s32);
    virtual void v6(s32);
    virtual void v7(s32);
    virtual s32 v8(s32);
};

class Unk8015EA24V {
public:
    virtual void v0(s32);
    virtual void v1(s32);
    virtual void v2(s32);
    virtual void v3(s32);
    virtual void v4(s32);
    virtual void v5(s32);
    virtual void v6(s32);
};

class Unk801584D4 {
public:
    virtual void v0();
    virtual void call(s32, s32, s32);
};

extern "C" s32 lbl_8042FD34[];

struct UnkFD34 {
    s32* items;
    s32 count;
};

class UnkVt34 {
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
    virtual s32 v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(s32, s32, s32);
    virtual void v17();
    virtual void v18(s32);
    virtual void v19();
    virtual void v20(s32, f32);
};

class Unk801577F0V {
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
    virtual void v33();
    virtual void v34();
    virtual void v35(f32*);
    s32 m4;
    u8* mData;
    s32 mCount;
    u8 pad_10[0x40];
          s32 m50;
      u8 m54;
      u8 pad_55[0x1F3];
      s32 m248;
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
extern "C" s32 stricmp(const char *, const char *);
extern "C" void fn_801CB750(s32, s32);
extern "C" s32 fn_80179650();
extern "C" s32 fn_801CF064();
extern "C" void fn_8001EF5C(s32, s32);
extern "C" void fn_80131234(void*);
extern "C" void fn_801CB6E4(void*, s32);
extern void* lbl_8032E668[];
extern void* lbl_8032EFA8;
extern char lbl_8032F0E8[];
extern f32 lbl_80561750;
extern f32 lbl_80561754;
extern f32 lbl_8056177C;
extern f32 lbl_805617C8;
extern f32 lbl_80558DC4[];
extern f32 lbl_8055E3C8;
extern "C" void fn_802E30C8(const char *, ...);
extern "C" __declspec(section ".data") char lbl_8032E4E0[];
extern "C" void *lbl_8055A064;

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

extern "C" f32 lbl_80561750;
extern "C" f32 lbl_80561758;
extern "C" void* __AXFXGetLfoSinTable_801769CC(void);
extern "C" f32 lbl_80561764;
extern "C" void* lbl_8032EC98;
extern "C" void fn_80157F98(Unk801577F0* self, s32 arg1, s32 arg2) {
    u8* p = (u8*)self + 0x14;
    self->mData = p;
    *(void**)self = &lbl_8032F2BC;
    self->mCount = 10;
    self->m54 = 0;
    for (; p < (u8*)self + 0x244; p += 0x38) {
        memset(p, 0, 4);
    }
    self->m54 = 0;
    *(s32*)((u8*)self + 4) = arg2;
    *(s32*)((u8*)self + 0x244) = arg1;
    self->m258 = 0;
    self->m254 = lbl_80561764;
    self->m268 = 0;
    self->m260 = 0;
    *(void**)self = &lbl_8032EC98;
    *(s32*)((u8*)self + 0x270) = arg2;
    *(f32*)((u8*)self + 0x27c) = lbl_80561754;
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

extern "C" void *fn_802076A0(void *, s32, s32, s32);
extern "C" f32 lbl_80561778;
void *fn_80158374(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 ok;
    void *first;
    void *second;
    ok = fn_80157278(arg3);
    *(void **)((u8 *)arg0 + 4) = 0;
    *(void **)arg0 = 0;
    if (ok == 0) {
        first = fn_802076A0(arg1, 1, arg3, 0);
        *(void **)arg0 = first;
        if (first == 0)
            goto done;
        if (lbl_80561778 != *(f32 *)((u8 *)first + 4)) {
            *((u8 *)first + 0x4e) = 1;
            *(f32 *)((u8 *)first + 4) = lbl_80561778;
        }
        first = *(void **)arg0;
        if (lbl_80561750 != *(f32 *)((u8 *)first + 8)) {
            *((u8 *)first + 0x4d) = 1;
            *(f32 *)((u8 *)first + 8) = lbl_80561750;
        }
        second = fn_802076A0(arg2, 1, arg3, 0);
        *(void **)((u8 *)arg0 + 4) = second;
        if (second == 0)
            goto done;
        if (lbl_80561778 != *(f32 *)((u8 *)second + 4)) {
            *((u8 *)second + 0x4e) = 1;
            *(f32 *)((u8 *)second + 4) = lbl_80561778;
        }
        second = *(void **)((u8 *)arg0 + 4);
        if (lbl_80561750 != *(f32 *)((u8 *)second + 8)) {
            *((u8 *)second + 0x4d) = 1;
            *(f32 *)((u8 *)second + 8) = lbl_80561750;
        }
    }
done:
    *(s32 *)((u8 *)arg0 + 8) = 1;
    return arg0;
}

extern "C" void fn_801584A8(void* arg0) {
    *(u32*)((u8*)arg0) = (u32)((u8*)arg0 + 0xC);
    *(u32*)((u8*)arg0 + 8) = 0x10;
    *(u32*)((u8*)arg0 + 4) = 0;
}

extern void lbl_8032F350(void);
extern "C" void fn_801584C4(void **arg0) {
    *arg0 = (void *)&lbl_8032F350;
}

extern "C" void fn_801584D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32* state = (s32*)&lbl_8042FD34;
    s32 i;
    Unk801584D4** entries = (Unk801584D4**)state[0];
    for (i = 0; i < state[1]; i++)
        entries[i]->call(arg0, arg1, arg2);
}

#pragma scheduling invalid_target
extern "C" void fn_80158558(s32 arg0) {
    s32* state = lbl_8042FD34;
    s32* items = (s32*)state[0];
    s32 count = state[1]++;
    items[count] = arg0;
}
extern "C" void fn_8015857C(u32 arg0) {
    UnkFD34* list = (UnkFD34*)lbl_8042FD34;
    s32 index;
    s32* items = (s32*)list->items;
    s32 count = list->count;
    if (count > 0) {
        for (index = 0; index < count; index++) {
            if ((u32)*items == arg0)
                goto found;
            items++;
        }
    }
    index = -1;
found:
    if (index == -1)
        return;
    if (index < 0 || index >= ((UnkFD34*)lbl_8042FD34)->count)
        return;
    if (index != ((UnkFD34*)lbl_8042FD34)->count - 1) {
        items = ((UnkFD34*)lbl_8042FD34)->items;
        items[index] = items[((UnkFD34*)lbl_8042FD34)->count - 1];
    }
    ((UnkFD34*)lbl_8042FD34)->count = ((UnkFD34*)lbl_8042FD34)->count - 1;
}

extern "C" s32 fn_80158618(const char* arg0) {
    const char** item = (const char**)lbl_8032E540;
    s32 i = 0;
    for (;;) {
        if (stricmp(*item, arg0) == 0) return i;
        ++i;
        ++item;
        if (i >= 0xF) return -1;
    }
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

extern "C" s32 stricmp(const char *, const char *);
extern "C" void* fn_801586F4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((u8*)arg0 + 8) = 0;
                            *(u32*)((u8*)arg0 + 0xC) = 0;
                            *(u32*)((u8*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* fn_80158760(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((u8*)arg0 + 8) = 0;
                            *(u32*)((u8*)arg0 + 0xC) = 0;
                            *(u32*)((u8*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801587CC(void* arg0) {
    f32 zero = lbl_80561754;
    s32 i = 0;
    s32 offset = 0;
    s32 value = 0;
    for (; i < *(s32*)((u8*)arg0 + 0xC); ++i) {
        u8* base = (u8*)*(u32*)((u8*)arg0 + 8);
        *(s32*)(base + offset) = value;
        s32* p = (s32*)*(u32*)((u8*)arg0 + 8);
        *(s32*)((u8*)p + offset + 4) = value;
        p = (s32*)*(u32*)((u8*)arg0 + 8);
        *(s32*)((u8*)p + offset + 8) = value;
        p = (s32*)*(u32*)((u8*)arg0 + 8);
        *(f32*)((u8*)p + offset + 0xC) = zero;
        offset += 0x38;
    }
}

extern "C" void fn_80158824(Unk801577F0* arg0) {
    f32 zero = lbl_80561754;
    s32 i = 0;
    s32 offset = 0;
    s32 value = 0;
    do {
        *(s32*)(arg0->mData + offset) = value;
        *(s32*)(arg0->mData + offset + 4) = value;
        *(s32*)(arg0->mData + offset + 8) = value;
        *(f32*)(arg0->mData + offset + 0xC) = zero;
        offset += 0x38;
        i++;
    } while (i < arg0->mCount);
    zero = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25C) = zero;
    *(f32*)((u8*)arg0 + 0x260) = zero;
    *(f32*)((u8*)arg0 + 0x258) = zero;
    *(f32*)((u8*)arg0 + 0x264) = zero;
    arg0->v31();
}

extern "C" f32 lbl_8056177C;
extern "C" s32 fn_80141F7C(f32);
void fn_8015889C(void* arg0) {
    Fn8015889C* self = (Fn8015889C*)arg0;
    f32 sp8;
    if (*(f32*)((u8*)arg0 + 0x25c) > lbl_80561754) {
        sp8 = lbl_80561754;
        if (*(f32*)((u8*)arg0 + 0x25c) > *(f32*)((u8*)arg0 + 0x24c)) {
            if (self->v23() > 0) {
                sp8 = *(f32*)((u8*)arg0 + 0x250) * self->v20(self->v23());
                self->v35(&sp8);
                self->v33();
            }
        }
        if (fn_80141F7C(sp8) == 0)
            self->v38(*(f32*)((u8*)arg0 + 0x25c));
        *(f32*)((u8*)arg0 + 0x25c) = lbl_80561754;
        *(f32*)((u8*)arg0 + 0x264) = lbl_80561754;
        *(f32*)((u8*)arg0 + 0x258) += lbl_8056177C;
    }
}

#pragma dont_inline on
extern "C" f32 fn_801589A8(Unk801577F0* self, s32 index) {
    struct V { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void q(); virtual s32 count(s32); };
    f32 value;
    if (index >= ((V*)self)->count(index)) value = lbl_80561754;
    else value = *(f32*)(*(u8**)((u8*)self + 8) + index * 0x38 + 0x10);
    if (*((u32*)__AXFXGetLfoSinTable_801769CC() + 1) & 0x200000) {
        if (!*((u8*)self + 0x271)) return lbl_80561754;
        if (!*((u8*)self + 0x270)) return value * lbl_80561750;
        return value * lbl_80561758;
    }
    return value;
}
#pragma dont_inline reset
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

extern "C" s32 fn_80158D04(void* arg0) {
    return *(s32*)((u8*)arg0 + 0xC);
}

extern "C" void fn_80158D0C(void* arg0) {
    if (*(f32*)((char*)arg0 + 0x260) > *(f32*)((char*)arg0 + 0x24c)) {
        if (*(s32*)((char*)arg0 + 0x268) != 0) {
            fn_801CB750(*(s32*)((char*)arg0 + 0x268), *(s32*)((char*)arg0 + 4));
        }
        *(f32*)((char*)arg0 + 0x260) = lbl_80561754;
    }
}

#pragma push
#pragma processor gekko
#pragma dont_inline on
extern "C" f32 fn_80158D60(void* arg0, void*) {
    Fn8015889C* self = (Fn8015889C*)arg0;
    f32 sp8 = lbl_80561754;
    if (*(f32*)((u8*)arg0 + 0x25c) > *(f32*)((u8*)arg0 + 0x24c) && self->v23() > 0) {
        sp8 = *(f32*)((u8*)arg0 + 0x250) * self->v20(self->v23());
        self->v35(&sp8);
        self->v33();
    }
    if (!((f32)__fabs(sp8) <= lbl_80558DC4[0]))
        self->v38(*(f32*)((u8*)arg0 + 0x25c));
    f32 x = *(f32*)((u8*)arg0 + 0x258) + lbl_8056177C;
    f32 z = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25c) = z;
    *(f32*)((u8*)arg0 + 0x264) = z;
    *(f32*)((u8*)arg0 + 0x258) = x;
    return sp8;
}
#pragma pop

extern "C" void fn_80158E74(void* arg0) {
    *(s32*)((u8*)arg0 + 8) = 0;
}

extern "C" f32 fn_80158E80(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x25D4);
}

extern "C" void fn_80158F34(void**);
extern "C" f32 fn_80158D60(void*, void*);
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

extern "C" void fn_80158F38(void* self, s32 unused, s32 arg2) {
    if (arg2 == 1) {
        *((u8*)self + 0x270) = 1;
    } else if (arg2 == 0) {
        *((u8*)self + 0x271) = 1;
    }
}

void fn_80158F34b(void* arg0, void* arg1) {
}
#pragma dont_inline off

extern "C" s32 fn_80158F60(Unk8015A368C* arg0) {
    return arg0->v21() > 0;
}

extern "C" void fn_801590A8(void* arg0) {
    ((Unk801577F0*)arg0)->v31();
    volatile f32* p260 = (volatile f32*)((u8*)arg0 + 0x260);
    volatile f32* p24c = (volatile f32*)((u8*)arg0 + 0x24c);
    f32 f2 = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25c) = f2;
    if (*p260 > *p24c) {
        s32 object = *(s32*)((u8*)arg0 + 0x268);
        if (object != 0) fn_801CB750(object, *(s32*)((u8*)arg0 + 4));
        *p260 = lbl_80561754;
    }
    f32 f1 = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x264) = f1;
    *(f32*)((u8*)arg0 + 0x258) = lbl_8056177C;
}

extern "C" void fn_80159724(void) {
}

#pragma push
#pragma processor 7400
extern "C" f32 fn_80159728(void* arg0, void* arg1) {
 Fn8015889C* self = (Fn8015889C*)arg0;
 u8* p = (u8*)arg0;
 f32 result = lbl_80561754;
 if ((f32)__fabs(*(f32*)((u8*)arg1+0x2690)) <= lbl_80558DC4[0] && self->v37()) {
  if (*(f32*)(p+0x25c) > *(f32*)(p+0x24c)) self->v32();
  f32 step = *(f32*)((u8*)arg1+0x25d4) * lbl_8056177C;
  *(f32*)(p+0x25c) += step;
  *(f32*)(p+0x260) += step;
  *(f32*)(p+0x264) += step;
  self->v34();
  if (*(f32*)(p+0x25c) > *(f32*)(p+0x24c) && self->v23()>0) {
   *(f32*)(p+0x258) = lbl_80561754;
   if (*(u8**)(p+0x26c)) *(s32*)(*(u8**)(p+0x26c)+8)=0;
  }
  result = lbl_80561754;
 } else if ((f32)__fabs(*(f32*)(p+0x258)) <= lbl_80558DC4[0]) {
  f32 value = lbl_80561754;
  if (*(f32*)(p+0x25c) > *(f32*)(p+0x24c) && self->v23()>0) {
   value = *(f32*)(p+0x250) * self->v20(self->v23());
   self->v35(&value);
   self->v33();
  }
  if (!fn_80141F7C(value)) self->v38(*(f32*)(p+0x25c));
  f32 x=*(f32*)(p+0x258)+lbl_8056177C, z=lbl_80561754;
  *(f32*)(p+0x25c)=z; *(f32*)(p+0x264)=z; *(f32*)(p+0x258)=x;
  result=value;
 } else {
  self->v33();
  *(f32*)(p+0x258) += lbl_8056177C;
  if (*(f32*)(p+0x260) > *(f32*)(p+0x24c)) {
   if (*(s32*)(p+0x268)) fn_801CB750(*(s32*)(p+0x268),*(s32*)(p+4));
   *(f32*)(p+0x260)=lbl_80561754;
  }
 }
 s32 total = *(s32*)(p+0xc);
 if (total-1 == self->v23()) {
  f32 value = lbl_80561754;
  if (*(f32*)(p+0x25c) > *(f32*)(p+0x24c) && self->v23()>0) {
   value = *(f32*)(p+0x250)*self->v20(self->v23());
   self->v35(&value); self->v33();
  }
  if (!fn_80141F7C(value)) self->v38(*(f32*)(p+0x25c));
  f32 x=*(f32*)(p+0x258)+lbl_8056177C, z=lbl_80561754;
  *(f32*)(p+0x25c)=z; *(f32*)(p+0x264)=z; *(f32*)(p+0x258)=x;
  result=value;
 }
 return result;
}
#pragma pop
extern "C" void fn_80159AB4(void* arg0) {
    class V {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
        virtual f32 v20(s32); virtual void v21(); virtual void v22(); virtual s32 v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(f32*); virtual void v36(); virtual void v37(); virtual void v38(f32);
    };
    V* self = (V*)arg0;
    volatile f32 sp8 = lbl_80561754;
    if (*(f32*)((u8*)arg0 + 0x25c) > *(f32*)((u8*)arg0 + 0x24c)) {
        if (self->v23() > 0) {
            sp8 = *(f32*)((u8*)arg0 + 0x250) * self->v20(self->v23());
            self->v35((f32*)&sp8); self->v33();
        }
    }
    if (fn_80141F7C(sp8) == 0) self->v38(*(f32*)((u8*)arg0 + 0x25c));
    f32 x = *(f32*)((u8*)arg0 + 0x258);
    f32 y = lbl_8056177C;
    f32 z = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25c) = z;
    *(f32*)((u8*)arg0 + 0x264) = z;
    *(f32*)((u8*)arg0 + 0x258) = y + x;
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

extern f32 lbl_8056179C;
extern "C" f32 fn_80159C34(Fn80159C34Obj* arg0, void* arg1) {
 f32 value=arg0->m254-lbl_8056177C, result=lbl_80561754; s32 done=0;
 if(result>value)value=result; arg0->m254=value;
 if(*(s32*)((u8*)arg1+0x2620)==0 && ((Unk801577F0*)arg0)->v35()==0) { value=arg0->m254; if(value>lbl_8056179C)value=lbl_8056179C; arg0->m254=value; }
 result=lbl_80561754;
 if(arg0->v37()!=0 && arg0->v21()==*(s32*)((u8*)arg0+0xc)-1)done=1;
 if(__fabsf(arg0->m254)<=lbl_80558DC4[0] || done) {
  if(done || arg0->m264>0) {
   if(arg0->m264>0){ f32 temp=arg0->m25c*arg0->v18(arg0->v21()); arg0->v33(&temp); arg0->v31(); arg0->m264=0; arg0->m25c=lbl_80561750; result=temp; }
   if(!done && arg0->m260>0){if(arg0->m258!=0)fn_801CB6E4((void*)arg0->m258,*(s32*)((u8*)arg0+4)); arg0->m260=0;}
  }
 } else if(arg0->m264>0)arg0->v32();
 return result;
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

extern "C" f32 lbl_8055E3C8;
extern "C" f32 fn_80159F2C(void* arg0, void* arg1, void* arg2) {
    return lbl_80561754;
}

extern "C" void fn_8015A318(Unk8015A368C* arg0) {
    if (arg0->m260 <= 0)
        return;
    s32 value = arg0->m258;
    if (value != 0) {
        void fn_801CB6E4(void*, s32);
        fn_801CB6E4((void*)value, *(s32*)&arg0->m4);
    }
    arg0->m260 = 0;
}

#pragma dont_inline on
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
#pragma dont_inline off

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

extern f32 lbl_8055A02C;
extern f32 lbl_80561788;
extern f32 lbl_805617B4;
void fn_8015A5E0(void *arg0, void *arg1, s32 arg2, u32 arg3) {
 if (*(f32*)((u8*)arg1+0x25d4) <= lbl_805617B4*lbl_8055A02C || arg2 != 0x3eb || *((u8*)arg0+0x2d1)) return;
 u8 *base=(u8*)arg0+0x26c, *p=base;
 s32 found=0;
 for(s32 i=0;i<8;i++,p+=0xc) {
   f32 x=*(f32*)(p+4);
   if (__fabsf(x-lbl_8055E3C8) <= lbl_80558DC4[0]) found=1;
   if (*(u32*)p==arg3 && lbl_8055E3C8-x >= lbl_80561788) return;
 }
 p=0;
 for(s32 i=0;i<8;i++,base+=0xc) if(p==0 || *(f32*)(base+4)<*(f32*)(p+4)) p=base;
 *(f32*)(p+4)=lbl_8055E3C8;
 p[8]=found;
 *(u32*)p=arg3;
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

extern "C" void fn_8015A81C(Unk801577F0 *arg0) {
    s32 i;
    s32 offset = 0;
    for (i = 0; i < arg0->mCount; i++) {
        u8 *entry = arg0->mData + offset;
        *(s32 *)(entry + 0) = 0;
        *(s32 *)(entry + 4) = 0;
        *(s32 *)(entry + 8) = 0;
        *(f32 *)(entry + 0xc) = lbl_80561754;
        offset += 0x38;
    }
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = lbl_80561754;
    arg0->m25c = lbl_80561750;
    arg0->v31();
}

extern "C" s32 fn_8015ADA4(void) {
    return 10;
}

extern "C" void* fn_8015ADAC(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((u8*)arg0 + 8) = 0;
                            *(u32*)((u8*)arg0 + 0xC) = 0;
                            *(u32*)((u8*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8015B0A4(Unk801577F0 *arg0) {
    arg0->m264 = 0;
    if (arg0->m260 > 0) {
        if (arg0->m258 != 0)
            fn_801CB6E4((void *)arg0, *(s32 *)((u8 *)arg0 + 4));
        arg0->m260 = 0;
        arg0->m254 = lbl_80561754;
        arg0->m25c = lbl_80561750;
        arg0->v31();
    }
    if (*(s32 *)((u8 *)arg0 + 0x278) > 0) {
        fn_801CB6E4((void *)0x50204, *(s32 *)((u8 *)arg0 + 4));
        *(s32 *)((u8 *)arg0 + 0x278) = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x26c) = 0;
    *(f32 *)((u8 *)arg0 + 0x270) = lbl_80561754;
    *(s32 *)((u8 *)arg0 + 0x274) = 0;
}

extern "C" void fn_8015B15C(Unk801577F0* arg0) {
      f32 zero = lbl_80561754;
      s32 i = 0;
      s32 offset = 0;
      s32 value = 0;
      for (; i < arg0->mCount; ++i) {
          u8* base = (u8*)arg0->mData;
          *(s32*)(base + offset) = value;
          s32* p = (s32*)arg0->mData;
          *(s32*)((u8*)p + offset + 4) = value;
          p = (s32*)arg0->mData;
          *(s32*)((u8*)p + offset + 8) = value;
          p = (s32*)arg0->mData;
          *(f32*)((u8*)p + offset + 0xC) = zero;
          offset += 0x38;
      }
      f32 a = lbl_80561754;
      f32 b = lbl_80561750;
      *(s32*)((u8*)arg0 + 0x264) = 0;
      *(s32*)((u8*)arg0 + 0x260) = 0;
      *(f32*)((u8*)arg0 + 0x254) = a;
      *(f32*)((u8*)arg0 + 0x25C) = b;
      arg0->v31();
      *(u8*)((u8*)arg0 + 0x26C) = 1;
      *(f32*)((u8*)arg0 + 0x270) = lbl_80561754;
      *(s32*)((u8*)arg0 + 0x274) = 0;
      *(s32*)((u8*)arg0 + 0x278) = 0;
  }

extern "C" void fn_8015B228(void* arg0, s32 arg1, s32 arg2) {
    if (arg2 == 6) *(u8*)((char*)arg0 + 0x26C) = 1;
}

extern "C" void fn_8015B23C(Unk8015A368C* arg0) {
    if (*(s32*)((u8*)arg0 + 0x264) > 0) {
        f32 value;
        s32 result = arg0->v21();
        value = *(f32*)((u8*)arg0 + 0x25C) * arg0->v18(result);
        arg0->v33(&value);
        arg0->v31();
        f32 zero = lbl_80561750;
        *(s32*)((u8*)arg0 + 0x264) = 0;
        *(f32*)((u8*)arg0 + 0x25C) = zero;
    }
}

extern "C" s32 fn_8015B2E0(void* arg0) {
    u8 flag = *(u8*)((char*)arg0 + 0x294);
    s32 result;
    if (flag) result = 0x7fffffff;
    else {
        f32 value = *(f32*)((char*)arg0 + 0x290);
        result = value > lbl_80558DC4[0] ? (s32)value : (s32)*(f32*)((char*)arg0 + 0x28c);
    }
    return result;
}

extern "C" s32 fn_8015B338(void) { return 0xC; }

void fn_8015B340(void* arg0) {
    s32 i;
    s32 offset;
    i = 0;
    offset = 0;
    if (i < *(s32*)((u8*)arg0 + 0xC)) {
        do {
            i++;
            *(s32*)(*(u8**)((u8*)arg0 + 8) + offset) = 0;
            *(s32*)(*(u8**)((u8*)arg0 + 8) + offset + 4) = 0;
            *(s32*)(*(u8**)((u8*)arg0 + 8) + offset + 8) = 0;
            *(f32*)(*(u8**)((u8*)arg0 + 8) + offset + 0xC) = lbl_80561754;
            offset += 0x38;
        } while (i < *(s32*)((u8*)arg0 + 0xC));
    }
    ((void (*)(void*))(*(void**)(*(u32**)arg0 + 0x84)))(arg0);
    *(u8*)((u8*)arg0 + 0x294) = 0;
    *(f32*)((u8*)arg0 + 0x290) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x28C) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x24C) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x254) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25C) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x264) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x26C) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x274) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x27C) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x284) = lbl_80561754;
}

extern "C" void fn_8015B618(void* arg0, void* arg1) {
    class LocalVtable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual f32 v18(s32); virtual void v19();
        virtual void v20(); virtual s32 v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(f32*);
    };
    f32 value;
    s32 index;
    s32 item;
    if (*(f32*)((u8*)arg0 + 0x28C) > lbl_80558DC4[0]) {
        index = ((LocalVtable*)arg0)->v21();
        value = ((LocalVtable*)arg0)->v18(index);
        ((LocalVtable*)arg0)->v33(&value);
        ((LocalVtable*)arg0)->v31();
    }
    item = *(s32*)(*(u8**)((u8*)arg0 + 8) +
                   (*(s32*)((u8*)arg0 + 0xC) - 1) * 0x38 + 4);
    if (item > 0 && fn_80179650() == 1 &&
        *(s32*)((u8*)arg1 + 0x1F0) == 0x50 &&
        fn_801CF064() == 0) {
        fn_8001EF5C(7, item);
    }
}

extern "C" void fn_8015B708(Unk801577F0* arg0) {
    class LocalVtable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(f32*);
    };
    f32 value;
    s32 result = arg0->v21();
    value = arg0->v18(result);
    ((LocalVtable*)arg0)->v33(&value);
    ((LocalVtable*)arg0)->v31();
}

extern "C" void* fn_8017960C(s32);
extern "C" f32 lbl_805617C0;
extern "C" void fn_8015B788(void* arg0, s32 arg1, f32 farg0) {
    f32 value = farg0;
    void* obj = fn_8017960C(arg1);
    if (obj != 0 && (f32)__fabs((f64)*(f32*)((u8*)obj + 0x2690)) <= *(volatile f32*)0x80558DC4) {
        f32* p = (f32*)((u8*)arg0 + arg1 * 8);
        if ((f32)__fabs((f64)p[0]) <= *(volatile f32*)0x80558DC4) {
            p[1] = value;
        } else if (value > p[1]) {
            p[1] = value;
        }
        p[0] = lbl_805617C0;
    }
}

extern "C" s32 fn_8015BCEC(void) { return 7; }

extern "C" s32 lbl_8055A05C[];
extern "C" s32 lbl_8055A05C[1];
#pragma push
#pragma processor 7400
extern "C" void fn_8015BCF4(Unk801577F0* arg0, f32* arg1) {
 struct Obj {
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
virtual s32 v17();
virtual void v18();
virtual s32 v19();
virtual void v20();
virtual s32 v21();
virtual void v22();
virtual s32 v23();
virtual s32 v24();
virtual s32 v25();
virtual s32 v26();
virtual void v27();
virtual void v28();
virtual s32 v29(); virtual void v30(); virtual s32 v31();
 };
 struct Adaptor {
 virtual void v0(); virtual void v1(s32,...); virtual void v2(s32,...);
 virtual void v3(s32,...); virtual void v4(); virtual void v5(s32);
 virtual void v6(s32); virtual void v7(); virtual void v8(s32);
 };
 char buf[16];
 Obj* obj=(Obj*)arg0;
 *arg1 *= fn_80204CFC(lbl_8032F39C);
 *arg1 *= lbl_8042FD08[arg0->m4];
 if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
  (*(Adaptor**)((u8*)arg0+0x248))->v3((s32)lbl_8055A058, fn_8023139C(buf,16,(u32)*arg1));
  (*(Adaptor**)((u8*)arg0+0x248))->v6(obj->v29());
  (*(Adaptor**)((u8*)arg0+0x248))->v5((s32)*arg1);
  (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A058,obj->v23());
  (*(Adaptor**)((u8*)arg0+0x248))->v1((s32)lbl_8055A058,obj->v24());
  obj->v22();
  (*(Adaptor**)((u8*)arg0+0x248))->v4();
  s32 limit=obj->v17();
  if(obj->v21()>=limit) (*(Adaptor**)((u8*)arg0+0x248))->v8(1);
 }
 f32 value=*arg1;
 s32 offset=obj->v21()*0x38;
 ++*(s32*)(arg0->mData+offset);
 if (!((f32)__fabs(value)<=lbl_80558DC4[0])) {
 ++*(s32*)(arg0->mData+offset+4);
 if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=lbl_80558DC4[0])
 ++*(s32*)(arg0->mData+offset+8);
 }
 *(f32*)(arg0->mData+offset+12)+=value;
 s32 index=obj->v21();
 ((void(*)(s32,s32,s32))fn_801584D4)(obj->v29(),arg0->m4,index);
 s32 shift=*(s32*)((u8*)arg0+0x26c)*0x168;
 if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
  (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A05C,obj->v23(),shift);
  (*(Adaptor**)((u8*)arg0+0x248))->v1((s32)lbl_8055A05C,obj->v24(),shift);
 }
}
#pragma pop

extern "C" s32 fn_8015C074(void) { return 0; }

extern "C" void* fn_8015C07C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((u8*)arg0 + 8) = 0;
                            *(u32*)((u8*)arg0 + 0xC) = 0;
                            *(u32*)((u8*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8015C0E8(Unk801577F0* arg0) {
    s32 i = 0;
    s32 offset = 0;
    while (i < arg0->mCount) {
        ++i;
        *(s32*)(arg0->mData + offset) = 0;
        *(s32*)(arg0->mData + offset + 4) = 0;
        *(s32*)(arg0->mData + offset + 8) = 0;
        *(f32*)(arg0->mData + offset + 12) = lbl_80561754;
        offset += 0x38;
    }
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = lbl_80561754;
    arg0->m25c = lbl_80561750;
    arg0->v31();
    arg0->m26c = 0;
    *(s32*)((u8*)arg0 + 0x274) = 0;
    arg0->m278 = lbl_80561754;
    arg0->m27c = lbl_80561754;
}

extern "C" void fn_8015C1B0(Unk801577F0* arg0) {
    arg0->m264 = 0;
    if (arg0->m260 > 0) {
        if (arg0->m258 != 0) {
            fn_801CB6E4((void*)arg0, *(s32*)((u8*)arg0 + 4));
        }
        arg0->m260 = 0;
        arg0->m254 = lbl_80561754;
        arg0->m25c = lbl_80561750;
        arg0->v33();
    }
    if (*(s32*)((u8*)arg0 + 0x26c) > 0) {
        fn_801CB6E4((void*)0x48203, *(s32*)((u8*)arg0 + 4));
        *(s32*)((u8*)arg0 + 0x26c) = 0;
    }
    *(s32*)((u8*)arg0 + 0x274) = 0;
    *(f32*)((u8*)arg0 + 0x278) = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x27c) = lbl_80561754;
}

extern f32 lbl_80561760;
extern "C" void fn_8015C564(void* arg0, void* arg1, s32 arg2, f64 arg3) {
    if (*(s32*)((u8*)arg0 + 0x270) == *(s32*)((u8*)arg1 + 0x1ec)) {
        if (arg2 == 7 || arg2 == 9) {
            *(f32*)((u8*)arg0 + 0x278) = (f32)arg3;
            if (arg2 == 7) {
                f32 value = (f32)arg3;
                f32 offset;
                if (value < lbl_80561754) offset = value - lbl_80561760;
                else offset = lbl_80561760 + value;
                *(s32*)((u8*)arg0 + 0x274) = (s32)offset;
            }
        }
    }
}

extern "C" void fn_8015C5D0(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x26c) > 0)
        fn_8015A368(arg0);
}

extern "C" void fn_8015C5E4(void* arg0) {
    f32 offset;
    if (*(f32*)((u8*)arg0 + 0x278) < lbl_80561754) {
        offset = *(f32*)((u8*)arg0 + 0x278) - lbl_80561760;
    } else {
        offset = lbl_80561760 + *(f32*)((u8*)arg0 + 0x278);
    }
    *(s32*)((u8*)arg0 + 0x26c) = (s32)offset;
    ((Unk801577F0*)arg0)->v13();
    if (*(s32*)((u8*)arg0 + 0x26c) > 0) {
        if (*(s32*)((u8*)arg0 + 0x26c) > 0) {
            fn_801CB6E4((void*)0x4F8203, *(s32*)((u8*)arg0 + 4));
        }
        *(s32*)((u8*)arg0 + 0x26c) = 0;
        *(f32*)((u8*)arg0 + 0x278) = lbl_80561754;
    }
}

extern "C" s32 fn_8015C684(void) {
    return 4;
}

extern "C" s32 fn_8015C68C(void) { return 0xD; }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8015C820(Unk801577F0* arg0, f32* arg1) {
  struct Obj {
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
  virtual s32 v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual s32 v21();
  virtual void v22();
  virtual s32 v23();
  virtual s32 v24();
  virtual s32 v25();
  virtual s32 v26();
  virtual void v27();
  virtual void v28();
  virtual s32 v29();
  };
  struct Adaptor {
  virtual void v0(); virtual void v1(s32,...); virtual void v2(s32,...);
  virtual void v3(s32,...); virtual void v4(); virtual void v5(s32);
  virtual void v6(s32); virtual void v7(); virtual void v8(s32);
  };
  char buf[16];
  Obj* obj=(Obj*)arg0;
  const char* name=lbl_8032F39C;
  *arg1 *= fn_80204CFC(name);
  *arg1 *= lbl_8042FD08[arg0->m4];
  if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
   (*(Adaptor**)((u8*)arg0+0x248))->v3((s32)lbl_8055A058, fn_8023139C(buf,16,(u32)*arg1));
   (*(Adaptor**)((u8*)arg0+0x248))->v6(obj->v29());
   (*(Adaptor**)((u8*)arg0+0x248))->v5((s32)*arg1);
   (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A058,obj->v23());
   (*(Adaptor**)((u8*)arg0+0x248))->v1((s32)lbl_8055A058,obj->v24());
   obj->v22();
   (*(Adaptor**)((u8*)arg0+0x248))->v4();
   s32 limit=obj->v17();
   if(obj->v21()>=limit) (*(Adaptor**)((u8*)arg0+0x248))->v8(1);
  }
  f32 value=*arg1;
  s32 offset=obj->v21()*0x38;
  ++*(s32*)(arg0->mData+offset);
  if (!((f32)__fabs(value)<=lbl_80558DC4[0])) {
  ++*(s32*)(arg0->mData+offset+4);
  if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=lbl_80558DC4[0])
  ++*(s32*)(arg0->mData+offset+8);
  }
  *(f32*)(arg0->mData+offset+12)+=value;
  s32 index=obj->v21();
  ((void(*)(s32,s32,s32))fn_801584D4)(obj->v29(),arg0->m4,index);
  if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
   (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A058,obj->v23());
  }
  if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
   (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A058,obj->v23());
  }
}
#pragma pop
extern "C" void* fn_8015CBBC(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((u8*)arg0 + 8) = 0;
                            *(u32*)((u8*)arg0 + 0xC) = 0;
                            *(u32*)((u8*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" u32 fn_8015CC28(void) { return 1; }

extern "C" s32 fn_8015CC30(void* arg0) {
    f32 x = *(f32*)((char*)arg0 + 0x250);
    if (x < lbl_80561754) return (s32)(x - lbl_80561760);
    return (s32)(lbl_80561760 + x);
}

extern "C" void fn_8015CC6C(void* arg0, f32 farg0) {
    *(f32*)((char*)arg0 + 0x250) = farg0;
}

extern "C" void fn_8015CC74(Unk801577F0* arg0) {
    f32 zero = lbl_80561754;
    s32 i = 0;
    s32 offset = 0;
    s32 value = 0;
    for (; i < arg0->mCount; ++i) {
        u8* base = arg0->mData;
        *(s32*)(base + offset) = value;
        s32* p = (s32*)arg0->mData;
        *(s32*)((u8*)p + offset + 4) = value;
        p = (s32*)arg0->mData;
        *(s32*)((u8*)p + offset + 8) = value;
        p = (s32*)arg0->mData;
        *(f32*)((u8*)p + offset + 0xC) = zero;
        offset += 0x38;
    }
    arg0->v32();
    *(f32*)((u8*)arg0 + 0x250) = lbl_805617C8;
}

extern "C" void fn_8015CD0C(void) {

}

extern "C" f32 lbl_805617C8;
#pragma scheduling off
extern "C" f32 fn_8015CD10(Unk801577F0* arg0) {
    class LocalVtable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual f32 v17(s32); virtual f32 v18(s32);
        virtual s32 v19(); virtual s32 v20(); virtual s32 v21(); virtual void v22();
        virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual s32 v31(); virtual void v32();
        virtual void v33(f32*);
    };
    f32 value = lbl_80561754;
    if (*(f32*)((u8*)arg0 + 0x250) > lbl_80561754) {
        ((LocalVtable*)arg0)->v30();
        ((LocalVtable*)arg0)->v32();
        s32 idx = ((LocalVtable*)arg0)->v21();
        value = ((LocalVtable*)arg0)->v18(idx);
        ((LocalVtable*)arg0)->v33(&value);
        ((LocalVtable*)arg0)->v31();
    }
    *(f32*)((u8*)arg0 + 0x250) = lbl_805617C8;
    return value;
}
#pragma scheduling reset
extern "C" void fn_8015CDD8(void) {
}

extern "C" void fn_8015CDDC(Unk801577F0* arg0, void* arg1, s32 arg2, f32 farg0) {
    if (*(s32*)((u8*)arg0 + 0x24C) == *(s32*)((u8*)arg1 + 0x1EC) && arg2 == arg0->v35()) {
        arg0->m250 = farg0;
    }
}

extern "C" s32 fn_8015CE48(void) {
    return 0xE;
}

extern "C" void fn_8015D270(void* arg0, void* arg1) {
    void* sp8;
    s32 temp;
    sp8 = arg1;
    fn_80158F34(&sp8);
    if (*(s32*)((u8*)arg0 + 0x264) > 0) fn_8015A368(arg0);
    temp = *(s32*)((u8*)arg0 + 0xC);
    temp = *(s32*)((u8*)arg0 + 8) + (temp - 1) * 0x38;
    temp = *(s32*)((u8*)temp + 4);
    if (temp > 0 && fn_80179650() == 1 && *(s32*)((u8*)arg1 + 0x1F0) == 0x50 && fn_801CF064() == 0)
        fn_8001EF5C(6, temp);
}

extern "C" void fn_8015D318(Unk801577F0* arg0, f32 arg1, s32 unused, s32 arg2) {
    if (unused == 5) {
        f32 value;
        s32 old;
        if (arg1 < lbl_80561754) value = arg1 - lbl_80561760;
        else value = lbl_80561760 + arg1;
        old = arg0->m26c;
        arg0->m26c = old + (s32)value;
    }
}

extern "C" u32 fn_8015D364(void) { return 1; }

extern "C" s32 fn_8015D36C(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x264);
}

extern "C" s32 fn_8015D374(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x264);
}

extern "C" u32 fn_8015D37C(void) { return 1; }

extern "C" void fn_8015D384(Unk801577F0* arg0) {
    s32 count = arg0->m260;
    arg0->m264 = 0;
    if (count > 0) {
        if (arg0->m258 != 0) fn_801CB6E4((void*)arg0->m258, arg0->m4);
        arg0->m260 = 0;
        arg0->m254 = lbl_80561754;
        arg0->m25c = lbl_80561750;
        arg0->v31();
    }
}

extern "C" void fn_8015D400(Unk801577F0* arg0) {
    class LocalVtable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(f32*);
    };
    f32 value;
    s32 result = arg0->v21();
    value = arg0->m25c * arg0->v18(result);
    ((LocalVtable*)arg0)->v33(&value);
    ((LocalVtable*)arg0)->v31();
    f32 zero = lbl_80561750;
    arg0->m264 = 0;
    arg0->m25c = zero;
}

extern "C" u32 fn_8015D498(void) { return 1; }

extern "C" f32 fn_8015D4A0(Unk801577F0* arg0, s32 arg1) {
    class LocalVtable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual s32 v17();
    };
    if (arg1 >= ((LocalVtable*)arg0)->v17()) {
        return *(f32*)((u8*)arg0->mData + arg1 * 0x38 + 0x10);
    }
    return lbl_80561754;
}

extern "C" s32 fn_8015D504(Unk801577F0* arg0, s32 arg1) {
    s32 count = arg0->mCount;
    s32 i = 0;
    s32 offset = 0;
    if (count > 0) {
        while (i < count) {
            s32 value = *(s32*)((u8*)arg0->mData + offset + 0x14);
            if (arg1 < value) break;
            if (value >= 0) {
                offset += 0x38;
                i++;
                continue;
            }
            break;
        }
    }
    return i;
}

void fn_8015D554(void* arg0) {
    class Local {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20();
        virtual void v21(void*);
        virtual void* v22();
    };
    Local* obj = (Local*)arg0;
    void* value = obj->v22();
    obj->v21(value);
}

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

extern "C" s32 fn_8015D77C(void* arg0) {
    s32 count = *(s32*)((u8*)arg0 + 0xC);
    s32 i = 0;
    s32 offset = 0;
    u8* base = (u8*)arg0 + 8;
    for (; count > 0; count--) {
        if (*(s32*)(base + offset + 0x14) >= 0)
            return *(s32*)(base + i * 0x38 + 0x14);
        offset += 0x38;
        i++;
    }
    return 0;
}

extern "C" s32 fn_8015D7CC(void* arg0) {
    s32 count = *(s32*)((u8*)arg0 + 0xC);
    s32 offset = count * 0x38;
    u8* base = (u8*)arg0 + 8;
    while (count > 0) {
        if (*(s32*)(base + offset + 0x14) >= 0)
            return *(s32*)(base + (count - 1) * 0x38 + 0x14);
        count--;
        offset -= 0x38;
    }
    return 0;
}

extern "C" void fn_8015D814(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x248) == 0) {
        struct Obj {
            virtual s32 dummy();
            virtual s32 get();
        };
        Obj* obj = *(Obj**)((u8*)arg0 + 0x244);
        *(s32*)((u8*)arg0 + 0x248) = obj->get();
    }
}

void JStudio_JAudio::TAdaptor_sound::endSound_fadeOut_(u32 arg0) {
    Unk801577F0V* self = (Unk801577F0V*)this;
    Unk801577F0V* target = (Unk801577F0V*)self->m248;
    if (target != 0) {
        target->v7();
        self->m248 = 0;
    }
}

extern "C" s32 lbl_8055A058[1];
void fn_8015D8B0(void* arg0) {
 struct Obj {
  virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
  virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7();
  virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11();
  virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15();
  virtual s32 v16(); virtual s32 v17(); virtual s32 v18(); virtual s32 v19();
  virtual s32 v20(); virtual s32 v21(); virtual s32 v22(); virtual s32 v23();
  virtual s32 v24(); virtual s32 v25(); virtual s32 v26(); virtual s32 v27();
  virtual s32 v28(); virtual s32 v29(); virtual s32 v30(); virtual s32 v31();
  u8 pad[0x244]; void* adaptor;
 };
 struct Adaptor {
  virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
  virtual s32 v4(s32,s32); virtual s32 v5(); virtual s32 v6();
  virtual s32 v7(); virtual s32 v8(s32); virtual s32 v9();
  virtual s32 v10(s32);
 };
 Obj* obj=(Obj*)arg0; Adaptor* adaptor=(Adaptor*)obj->adaptor;
 if(obj->adaptor) {
  s32 x=obj->v25();
  adaptor->v4((s32)&lbl_8055A058[0],x);
  adaptor->v8(obj->v31());
  obj->v24();
  adaptor->v6();
  x=obj->v19();
  obj->v23();
  if(obj->v23()>=x) adaptor->v10(1);
 }
}

extern "C" f32 fn_80204CFC(const char*);
extern "C" void* fn_8023139C(void*,s32,u32);
extern "C" char lbl_8032F39C[];
extern "C" f32 lbl_8042FD08[];
#pragma push
#pragma processor 750
extern "C" void fn_8015D9BC(Unk801577F0* arg0, f32* arg1) {
 struct Obj {
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
virtual s32 v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual s32 v21();
virtual void v22();
virtual s32 v23();
virtual s32 v24();
virtual s32 v25();
virtual s32 v26();
virtual void v27();
virtual void v28();
virtual s32 v29();
 };
 struct Adaptor {
 virtual void v0(); virtual void v1(s32,...); virtual void v2(s32,...);
 virtual void v3(s32,...); virtual void v4(); virtual void v5(s32);
 virtual void v6(s32); virtual void v7(); virtual void v8(s32);
 };
 char buf[16];
 Obj* obj=(Obj*)arg0;
 *arg1 *= fn_80204CFC(lbl_8032F39C);
 *arg1 *= lbl_8042FD08[arg0->m4];
 if (*(Adaptor**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=lbl_80558DC4[0])) {
  (*(Adaptor**)((u8*)arg0+0x248))->v3((s32)lbl_8055A058, fn_8023139C(buf,16,(u32)*arg1));
  (*(Adaptor**)((u8*)arg0+0x248))->v6(obj->v29());
  (*(Adaptor**)((u8*)arg0+0x248))->v5((s32)*arg1);
  (*(Adaptor**)((u8*)arg0+0x248))->v2((s32)lbl_8055A058,obj->v23());
  (*(Adaptor**)((u8*)arg0+0x248))->v1((s32)lbl_8055A058,obj->v24());
  obj->v22();
  (*(Adaptor**)((u8*)arg0+0x248))->v4();
  s32 limit=obj->v17();
  if(obj->v21()>=limit) (*(Adaptor**)((u8*)arg0+0x248))->v8(1);
 }
 f32 value=*arg1;
 s32 offset=obj->v21()*0x38;
 ++*(s32*)(arg0->mData+offset);
 if (!((f32)__fabs(value)<=lbl_80558DC4[0])) {
 ++*(s32*)(arg0->mData+offset+4);
 if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=lbl_80558DC4[0])
 ++*(s32*)(arg0->mData+offset+8);
 }
 *(f32*)(arg0->mData+offset+12)+=value;
 s32 index=obj->v21();
 ((void(*)(s32,s32,s32))fn_801584D4)(obj->v29(),arg0->m4,index);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8015DC98(Unk801577F0* arg0) {
    void (*vt)(void*) = (void (*)(void*))(*(void***)arg0)[0x19];
    vt(arg0);
    fn_802E30C8((const char*)lbl_8055A064);
    fn_802E30C8((const char*)lbl_8032E4E0 + 0xEC8);
    fn_802E30C8((const char*)lbl_8032E4E0 + 0xEFC);
    f32 sumF = lbl_80561754;
    s32 sum0 = 0;
    s32 sum4 = 0;
    s32 count = 0;
    s32 off = 0;
    while (count < arg0->mCount) {
        s32* items = (s32*)arg0->mData;
        s32* item = items + off / 4;
        s32 a = item[0];
        fn_802E30C8((const char*)lbl_8032E4E0 + 0xF30, count, item + 6, a, a - item[1], item[2], *(f32*)(item + 3));
        off += 0x38;
        count += 1;
        sumF += *(f32*)(item + 3);
        sum0 += item[0];
        sum4 += item[1];
    }
    fn_802E30C8((const char*)lbl_8032E4E0 + 0xF60, sum0, sum4 - sum0, sumF);
}

extern "C" s32 lbl_8055A06C[];
#pragma push
#pragma use_lmw_stmw off
#pragma processor 7400
extern "C" void fn_8015DD9C(Unk801577F0* arg0, void* arg1) {
 struct Obj {
 virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3(); virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7(); virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11(); virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15(); virtual s32 v16(); virtual s32 v17(); virtual s32 v18(); virtual s32 v19(); virtual s32 v20(); virtual s32 v21(); virtual s32 v22(); virtual s32 v23(); virtual s32 v24(); virtual s32 v25(); virtual s32 v26(); virtual s32 v27(); virtual s32 v28(); virtual s32 v29();
 };
 struct Adaptor {
 virtual void v0(); virtual void v1(s32,...); virtual void v2(s32,...);
 virtual void v3(s32,...); virtual void v4(); virtual void v5(s32);
 virtual void v6(s32); virtual void v7(); virtual void v8(s32);
 };
 struct Provider { virtual void v0(); virtual Adaptor* v1(); };
 struct Item { s32 a,b,c; f32 d; u8 pad[0x28]; };
 s32 sum=0;
 for(s32 i=0;i<arg0->mCount;i++) sum+=((Item*)arg0->mData)[i].b;
 Adaptor* a=((Provider*)arg1)->v1();
 Obj* obj=(Obj*)arg0;
 if(a) {
 a->v1((s32)lbl_8055A058,obj->v25());
 a->v2((s32)lbl_8055A06C,sum);
 a->v6(obj->v29());
 f32 total=lbl_80561754;
 for(s32 i=0;i<arg0->mCount;i++) total+=((Item*)arg0->mData)[i].d;
 s32 value=(s32)total;
 char buf[16];
 a->v3((s32)lbl_8055A058,fn_8023139C(buf,16,value));
 a->v5(value);
 obj->v22();
 a->v4();
 s32 limit=obj->v17();
 if(obj->v21()>=limit) a->v8(1);
 }
}
#pragma pop

#pragma pop
extern "C" void fn_8015E0FC(void) {
}

extern "C" s32 fn_8015E100(void) {
    return 0;
}

extern "C" s32 fn_8015E108(void) {
    return 0;
}

extern "C" void fn_8015E238(Unk801577F0V* arg0) {
    f32 zero = lbl_80561750;
    s32 i = 0;
    s32 off = 0;
    arg0->m54 = 1;
    *(f32*)((u8*)arg0->mData + arg0->m50 * 4) = zero;
    UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
    s32 count = arg0->mCount;
    for (s32 j = 0; j < count; j++) {
        entries[j]->v13();
    }
}

extern "C" void fn_8015E2C8(Unk801577F0V* arg0) {
    UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
    s32 count = arg0->mCount;
    for (s32 j = 0; j < count; j++) {
        entries[j]->v15();
    }
}

extern "C" void fn_8015E4C4(Unk801577F0V* arg0, s8 arg1) {
    arg0->m54 = arg1;
}

extern "C" void fn_8015E4CC(Unk801577F0V* arg0, s32 arg1, f32 arg2) {
    if (arg0->m54 != 0) {
        UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
        s32 count = arg0->mCount;
        for (s32 j = 0; j < count; j++) {
            entries[j]->v20(arg1, arg2);
        }
    }
}

extern "C" void fn_8015E568(Unk801577F0V* arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0->m54 != 0) {
        UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
        s32 count = arg0->mCount;
        for (s32 j = 0; j < count; j++) {
            entries[j]->v16(arg1, arg2, arg3);
        }
    }
}

extern "C" void fn_8015E5F4(Unk801577F0V* arg0, s32 arg1) {
    UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
    s32 count = arg0->mCount;
    for (s32 j = 0; j < count; j++) {
        entries[j]->v18(arg1);
    }
}

extern "C" void fn_8015E778(Unk801577F0V* arg0, s32 arg1, s32 arg2, f32 farg0) {
    if (arg0->m54 != 0) {
        UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
        s32 count = arg0->mCount;
        for (s32 j = 0; j < count; j++) {
            entries[j]->v16(arg1, arg2, farg0);
        }
    }
}
#pragma scheduling off
extern "C" void fn_8015E80C(Unk801577F0V* arg0, s32 arg1) {
    UnkVt34** entries = *(UnkVt34***)((u8*)arg0 + 4);
    s32 count = arg0->mCount;
    for (s32 j = 0; j < count; j++) {
        entries[j]->v18(arg1);
    }
}

extern "C" s32 fn_8015E910(void *arg0, s32 arg1) {
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    while (var_r30 < *(s32 *)((char *)arg0 + 8)) {
        Unk8015E910V *obj = *(Unk8015E910V **)((char *)*(void **)((char *)arg0 + 4) + var_r31);
        if (obj->v8(arg1) != 0) return 1;
        var_r31 += 4;
        var_r30 += 1;
    }
    return 0;
}

extern "C" void fn_8015E9A4(void *arg0, s32 arg1) {
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    while (var_r30 < *(s32 *)((char *)arg0 + 8)) {
        Unk801577F0 *obj = *(Unk801577F0 **)((char *)*(void **)((char *)arg0 + 4) + var_r31);
        obj->v18(arg1);
        var_r31 += 4;
        var_r30 += 1;
    }
}

extern "C" void fn_8015EA24(void *arg0, s32 arg1) {
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    while (var_r30 < *(s32 *)((char *)arg0 + 8)) {
        Unk8015EA24V *obj = *(Unk8015EA24V **)((char *)*(void **)((char *)arg0 + 4) + var_r31);
        obj->v6(arg1);
        var_r31 += 4;
        var_r30 += 1;
    }
}

#pragma scheduling on
extern "C" s32 fn_80159338(void) {
    return 3;
}

extern "C" void* fn_80159340(void* arg0, s32 arg1) {
    void* child;
    if (arg0) {
        child = *(void**)((char*)arg0 + 0x278);
        *(void**)arg0 = lbl_8032F0E8;
        if (child) {
            if (child) {
                ((Unk8015A368C*)child)->v1();
            }
        }
        if (arg0) {
            if (arg0) {
                if ((u32)arg0 + 8) {
                    if (arg0) {
                        if (arg0) {
                            *(u32*)((char*)arg0 + 8) = 0;
                            *(u32*)((char*)arg0 + 0xC) = 0;
                            *(u32*)((char*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801593F0(Unk801577F0* arg0) {
    f32 b;
    f32 a;
    arg0->v31();
    *(f32*)((u8*)arg0 + 0x25c) = lbl_80561754;
    if (*(f32*)((u8*)arg0 + 0x260) > *(f32*)((u8*)arg0 + 0x24c)) {
        s32 r3 = *(s32*)((u8*)arg0 + 0x268);
        if (r3 != 0) {
            fn_801CB750(r3, arg0->m4);
        }
        *(f32*)((u8*)arg0 + 0x260) = lbl_80561754;
    }
    Unk801577F0* object = *(Unk801577F0**)((u8*)arg0 + 0x278);
    a = lbl_80561754;
    b = lbl_8056177C;
    *(f32*)((u8*)arg0 + 0x264) = a;
    *(f32*)((u8*)arg0 + 0x258) = b;
    if (object != 0) {
        *(u8*)((u8*)object + 0x4A) = 1;
        *(u8*)((u8*)object + 0x4C) = 0;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_80159488(Unk801577F0* arg0) {
      f32 zero = lbl_80561754;
      s32 i = 0;
      s32 offset = 0;
      s32 value = 0;
      for (; i < arg0->mCount; ++i) {
          u8* base = (u8*)arg0->mData;
          *(s32*)(base + offset) = value;
          s32* p = (s32*)arg0->mData;
          *(s32*)((u8*)p + offset + 4) = value;
          p = (s32*)arg0->mData;
          *(s32*)((u8*)p + offset + 8) = value;
          p = (s32*)arg0->mData;
          *(f32*)((u8*)p + offset + 0xC) = zero;
          offset += 0x38;
      }
      zero = lbl_80561754;
      *(f32*)((u8*)arg0 + 0x25C) = zero;
      *(f32*)((u8*)arg0 + 0x260) = zero;
      *(f32*)((u8*)arg0 + 0x258) = zero;
      *(f32*)((u8*)arg0 + 0x264) = zero;
      arg0->v31();
      void* child = *(void**)((u8*)arg0 + 0x278);
      *(f32*)((u8*)arg0 + 0x270) = lbl_80561754;
      *(u8*)((u8*)arg0 + 0x274) = 1;
      if (child != 0) {
          *(u8*)((u8*)child + 0x4A) = 1;
          *(u8*)((u8*)child + 0x4C) = 0;
      }
  }
extern "C" void fn_80159554(void *arg0, void *arg1) {
    void *sp8 = arg1;
    s32 temp_r31;

    fn_80158F34(&sp8);
    if (*(f32 *)((u8 *)arg0 + 0x25C) > lbl_80561754) {
        fn_80158D60(arg0, sp8);
    }
    temp_r31 = *(s32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 8) +
        (*(s32 *)((u8 *)arg0 + 0xC) - 1) * 0x38) + 4);
    if (temp_r31 > 0 && fn_80179650() == 1 &&
        *(s32 *)((u8 *)arg1 + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(5, temp_r31);
    }
    if (*(void **)((u8 *)arg0 + 0x278) != 0) {
        *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + 0x4A) = 1;
        *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + 0x4C) = 0;
    }
}

extern "C" f32 fabs(f32);
extern "C" f32 PSVECDotProduct(const void *, const void *);
extern "C" f32 lbl_80561760;
extern "C" f32 lbl_80561788;
extern "C" f32 lbl_8056178C;
extern "C" f32 lbl_80561790;
extern "C" void fn_80159624(void *arg0, void *arg1) {
    void *obj = *(void **)((u8 *)arg0 + 0x278);
    if (obj != 0) {
        s32 flag = 0;
        f32 value = *(f32 *)((u8 *)arg1 + 0x25D4);
        f32 abs_diff = fabs(*(f32 *)((u8 *)arg1 + 0x2690));
        if (abs_diff == lbl_80558DC4[0] && value > lbl_80561788 && *(f32 *)((u8 *)arg0 + 0x270) < lbl_80561760) {
            f32 dot = fabs(PSVECDotProduct((const void *)((u8 *)arg1 + 0x118), (const void *)((u8 *)arg1 + 0x3C)));
            f32 scale = *(s32 *)((u8 *)arg0 + 0x274) != 0 ? lbl_8056178C : lbl_80561790;
            if (!(dot > value * scale)) {
                flag = 0;
            }
        }
        *(u8 *)((u8 *)obj + 0x4A) = 1;
        *(u8 *)((u8 *)obj + 0x4C) = flag;
    }
}

extern "C" s32 fn_80159708(void* arg0) {
    f32 f0 = *(f32*)((char*)arg0 + 0x25c);
    return (s32)f0;
}
class Fn8015E338Item {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual f32 v3(void*);
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual s32 v35();
};
