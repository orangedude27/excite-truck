// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
static inline s32 F2I_80159708(f32 f) { return (s32)f; }
extern "C" void fn_8014AEC8(void*);
extern "C" s32 fn_80141F7C(f32);
extern "C" s32 fn_80158D04(void*);
extern "C" void fn_80158D0C(void*);
extern "C" f32 fn_80158D60(void*, void*);
extern "C" void fn_80158E74(void*);
extern "C" f32 fn_80158E80(void*);
extern f32 lbl_802F9478[];
extern "C" f32 fn_801429D0(f32, f32);
extern "C" f64 lbl_80561780;
extern "C" char lbl_8032F39C[];
extern "C" f32 lbl_8042FD08[];
extern "C" f32 lbl_80558DC4[];
extern "C" f32 PSVECDotProduct(const void *, const void *);
extern "C" f32 lbl_80561750, lbl_80561754, lbl_8056177C, lbl_80561788, lbl_8056178C, lbl_80561790, lbl_80561794, lbl_80561798;
class Fn8015B404Obj {
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
extern "C" f32 lbl_80561760;
extern "C" s32 lbl_8055A058[1];
extern "C" f32 lbl_8056179C;
extern "C" f32 lbl_805617C4;
extern "C" f32 fn_801E7E24(void);
extern "C" f32 fn_80204CFC(const char*);
extern "C" void* fn_8023139C(void*,s32,u32);
extern "C" void* fn_8017960C(s32);
struct Item38 { u8 pad[0x14]; s32 val; u8 pad2[0x20]; };
struct Word4 { s32 v; };

struct Fn80157CF0Obj {
    void* vtable;
    s32 unk4;
    u8* entries;
    s32 unkC;
    s32 count;
    u8 entriesData[0x230];
    s32 unk244;
    s32 unk248;
    f32 unk24C;
    f32 value250;
    f32 unk254;
    s32 unk258;
    s32 unk25C;
    s32 unk260;
    s32 unk264;
    s32 unk268;
};

// Frame-driven player over a list of 0x38-byte records (mRecords / mCount).
// fn_80158B0C and fn_80159728 advance the progress counters by
// (speed * lbl_8056177C) each frame, lbl_8056177C being one 60 Hz frame
// (0.0166834 s); fn_80158D60, fn_80159AB4 and fn_8015B23C
// emit the current record's value and reset the counters.
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
 virtual void v36(); virtual s32 v37(); virtual void v38(f32); virtual s32 v39();

  s32 m4;
  u8* mRecords;      // 0x08: mCount records, 0x38 bytes each
  s32 mCount;        // 0x0C: number of records
  u8 mPad10[0x23C];
  f32 mLevel24C;     // progress the counters have to pass
  f32 mGain250;      // scales the value read for the current record
  f32 m254;
  f32 mTime258;      // seconds since the last reset (one frame per update)
  f32 mProgress25C;  // main progress counter
  f32 mProgress260;  // progress of the instance held at 0x268
  f32 mProgress264;  // second progress counter
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
extern "C" char lbl_8032F2BC[];
extern "C" char lbl_8032EBF8[];
extern "C" char lbl_8032EE68[];
extern "C" f32 lbl_8056175C;
extern "C" void* memset(void*, s32, u32);
class Item8015E338 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual f32 v3(void*);
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
    virtual s32 v34();
};

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
    virtual void v1(s32 arg = 0);
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
    f32 m25c;
    s32 m260;
    s32 m264;
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
      virtual void v7(s32);
      virtual void v8(s32);
      virtual void v9(s32);
      virtual void v10(s32);
      virtual void v11(s32);
      virtual void v6(s32);
  };
  
  class Unk8015E9A4Base {
  public:
      virtual void b0(s32);
      virtual void b1(s32);
      virtual void b2(s32);
      virtual void b3(s32);
      virtual void b4(s32);
      virtual void b5(s32);
      virtual void b6(s32);
      virtual void b7(s32);
      virtual void b8(s32);
      virtual void b9(s32);
      virtual void b10(s32);
      virtual void b11(s32);
      virtual void b12(s32);
      virtual void b13(s32);
      virtual void b14(s32);
      virtual void b15(s32);
      virtual void b16(s32);
      virtual void b17(s32);
      virtual void b18(s32);
      virtual void b19(s32);
      virtual void b20(s32);
      virtual void b21(s32);
      virtual void b22(s32);
      virtual void b23(s32);
      virtual void b24(s32);
      virtual void b25(s32);
      virtual void b26(s32);
      virtual void b27(s32);
      virtual void b28(s32);
      virtual void b29(s32);
      virtual void b30(s32);
      virtual void b31(s32);
      virtual void b32(s32);
      virtual void b33(s32);
      virtual void b34(s32);
      virtual void b35(s32);
      virtual void b36(s32);
      virtual void b37(s32);
      virtual void b38(s32);
      virtual void b39(s32);
      virtual void b40(s32);
  };
  class Unk8015E9A4V : public Unk8015E9A4Base {
  public:
      virtual void v15(s32);
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
extern "C" void *fn_802076A0(void *, s32, s32, s32);
extern "C" f32 lbl_80561768;
#pragma push
#pragma small_data off
extern char lbl_8032F2BC[];
extern "C" char lbl_8032EAFC[];
extern char lbl_8032EFA8[];
#pragma pop
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
extern "C" void *fn_801284F8(u32, void *);

extern "C" s32 lbl_8032E540[];
extern "C" s32 fn_80157278(s32 arg0) {
    s32* item = (s32*)lbl_804348E8[arg0];
    s32 value = item[4];
    return value == 0x41434152;
}

struct VObj;
extern "C" void fn_80157560(VObj*);
extern "C" s32 fn_80157558(void*);
extern "C" s32 fn_8015782C(s32*, s32);
extern "C" void* fn_8015783C(void*, s32, s32);
extern "C" void* fn_801579F4(void*, s32, s32);
extern "C" void* fn_80157B00(void*, s32, s32);
extern "C" void* fn_80157CF0(void*, s32, s32);
extern "C" void* fn_80157DA0(void*, s32, s32);
extern "C" void* fn_80157F98(void*, s32, s32);
extern "C" void* fn_80158054(void*, s32, s32, void*);
extern "C" void* fn_8015812C(void*, s32, s32, void*);
extern "C" void* fn_801582A4(void*, s32, s32, void*);
extern "C" void* fn_80158280(void*, s32*);
extern "C" void* fn_80158374(void*, s32, s32, s32);
extern "C" void fn_801584A4(void*);
extern "C" void fn_801584A8(void*);
extern "C" void fn_801584C4(void**);
extern "C" void* fn_801284F8(u32, void*);
extern "C" char lbl_8032EB0C[];
extern "C" void* fn_801572A4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sa;
    lbl_8042FD08[arg1] = lbl_80561750;
    void* obj = fn_801284F8(0x5C, (void*)(lbl_8032E4E0 + 0x53C));
    if (obj != 0) {
        sa = arg2;
        char* base = lbl_8032E4E0;
        fn_801584C4((void**)obj);
        *(void**)obj = (void*)lbl_8032EB0C;
        fn_801584A8((u8*)obj + 4);
        fn_801584A4(&sa);
        void* h = fn_801284F8(0x10, (void*)(base + 0x54C));
        if (h != 0) {
            h = fn_80158374(h, (s32)(base + 0x558), (s32)(base + 0x564), arg1);
        }
        *(void**)((u8*)obj + 0x50) = h;
        void *t9, *t8, *t7, *t6, *t5, *t4, *t3, *t2, *t1;
        void* a;
        a = fn_801284F8(0x27C, (void*)(base + 0x570));
        if (a != 0) {
            a = fn_801582A4(a, arg0, arg1, *(void**)((u8*)obj + 0x50));
        }
        t1 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t1);
        a = fn_801284F8(0x27C, (void*)(base + 0x57C));
        if (a != 0) {
            a = fn_8015812C(a, arg0, arg1, *(void**)((u8*)obj + 0x50));
        }
        t2 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t2);
        a = fn_801284F8(0x2DC, (void*)(base + 0x58C));
        if (a != 0) {
            a = fn_80158054(a, arg0, arg1, *(void**)((u8*)obj + 0x50));
        }
        t3 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t3);
        a = fn_801284F8(0x280, (void*)(base + 0x59C));
        if (a != 0) {
            a = fn_80157F98(a, arg0, arg1);
        }
        t4 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t4);
        a = fn_801284F8(0x2F4, (void*)(base + 0x5A8));
        if (a != 0) {
            a = fn_80157DA0(a, arg0, arg1);
        }
        t5 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t5);
        a = fn_801284F8(0x27C, (void*)(base + 0x5B8));
        if (a != 0) {
            a = fn_80157CF0(a, arg0, arg1);
        }
        t6 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t6);
        a = fn_801284F8(0x29C, (void*)(base + 0x5C8));
        if (a != 0) {
            a = fn_80157B00(a, arg0, arg1);
        }
        t7 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t7);
        a = fn_801284F8(0x254, (void*)(base + 0x5D8));
        if (a != 0) {
            a = fn_801579F4(a, arg0, arg1);
        }
        t8 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t8);
        a = fn_801284F8(0x27C, (void*)(base + 0x5E8));
        if (a != 0) {
            a = fn_8015783C(a, arg0, arg1);
        }
        t9 = a;
        fn_80158280((void*)((u8*)obj + 4), (s32*)&t9);
        s32 i = 0;
        while (i < fn_80157558((void*)((u8*)obj + 4))) {
            fn_80157560(*(VObj**)(u32)fn_8015782C((s32*)((u8*)obj + 4), i));
            i++;
        }
        *(u8*)((u8*)obj + 0x54) = 1;
        *(s32*)((u8*)obj + 0x58) = arg1;
        (void)arg2;
    }
    return obj;
}

extern "C" s32 fn_80157558(void* arg0) {
    return *(s32*)((u8*)arg0 + 4);
}

extern "C" void* fn_80131810(void*);
extern "C" void* fn_80131808(void*);
extern "C" void fn_80131818(void*);
extern "C" void fn_801345D8(void*, s32, void*, ...);
struct VObj {
    virtual VObj* vslot2(const void*);
    virtual void vslot3();
    virtual s32 vslot4(const void*);
    virtual void vslot5();
    virtual s32 vslot6(const char*, const char*);
    virtual s32 vslot7(const char*);
    virtual s32 vslot8(const char*, s32);
    virtual f32 vslot9(const char*);
    virtual f32 vslot10(const char*, f32);
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual VObj* vslot24(s32);
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual const void* vslot28();
};
extern "C" char lbl_8032EAD4[];
extern "C" char lbl_8032EAE0[];
extern "C" char lbl_8055A030;
extern "C" char lbl_8055A038;
extern "C" char lbl_8055A040;
extern "C" char lbl_8055A044;
extern "C" char lbl_8055A048;
extern "C" char lbl_8055A050;
extern "C" char lbl_8055A054;
#define lbl_8055A030 (&lbl_8055A030)
#define lbl_8055A038 (&lbl_8055A038)
#define lbl_8055A040 (&lbl_8055A040)
#define lbl_8055A044 (&lbl_8055A044)
#define lbl_8055A048 (&lbl_8055A048)
#define lbl_8055A050 (&lbl_8055A050)
#define lbl_8055A054 (&lbl_8055A054)
struct Rec157560 {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
    f32 e;
    s32 f;
    char name[32];
};
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80157560(VObj *arg0) {
    VObj *a = (VObj *)fn_80131810(lbl_8032EAD4);
    VObj *b0 = (VObj *)fn_80131808(lbl_8032EAE0);
    VObj *b1;
    if (a == 0) {
        a = b0;
    }
    const void *p = arg0->vslot28();
    if (a->vslot4(p) != 0) {
        b1 = a->vslot2(p);
    } else if (b0->vslot4(p) != 0) {
        b1 = b0->vslot2(p);
    } else {
        b1 = b0->vslot2(lbl_8055A030);
    }
    if (b1 != 0) {
        VObj *iter = b1->vslot24(0);
        f32 best = lbl_80561754;
        s32 idx = 0;
        while (iter != 0) {
            s32 s28 = iter->vslot7(lbl_8055A038);
            s32 s22 = iter->vslot6(lbl_8055A040, lbl_8055A044);
            s32 s29 = iter->vslot8(lbl_8055A048, 0);
            f32 f1v = iter->vslot10(lbl_8055A050, lbl_80561754);
            if (f1v < best) {
                f1v = b0->vslot2(lbl_8055A030)->vslot24(idx)->vslot9(lbl_8055A050);
            }
            s32 n = *(s32 *)((char *)arg0 + 0xC);
            char *base = *(char **)((char *)arg0 + 8);
            *(s32 *)((char *)arg0 + 0xC) = n + 1;
            *(s32 *)(base + s28 * 0x38) = 0;
            char *rec = base + s28 * 0x38;
            *(s32 *)(rec + 4) = 0;
            *(s32 *)(rec + 8) = 0;
            *(f32 *)(rec + 12) = best;
            *(f32 *)(rec + 16) = f1v;
            *(s32 *)(rec + 20) = s29;
            fn_801345D8(rec + 24, 0x20, lbl_8055A054, s22);
            idx++;
            iter = b1->vslot24(idx);
        }
    }
    if (a != b0) {
        fn_80131818(a);
    }
    fn_80131818(b0);
}
#pragma pop

extern "C" s32 fn_801577F0(Unk801577F0* arg0) {
    return lbl_8032E540[arg0->GetType()];
}

extern "C" s32 fn_8015782C(s32* arg0, s32 arg1) {
    return *arg0 + arg1 * 4;
}

#pragma auto_inline off
#pragma dont_inline on
extern "C" char lbl_8032EB58[];
extern "C" char lbl_8032EAF0[];
extern "C" void* fn_802076A0(void*, s32, s32, s32);
extern "C" s32 fn_80157278(s32);
#pragma auto_inline off
#pragma dont_inline on
#pragma small_data off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void* fn_8015783C(void* arg0, s32 arg1, s32 arg2) {
    struct Tail {
        u8 pad[0x244];
        s32 field26C;
        unsigned field248;
        f32 field24C;
        f32 field250;
        f32 field254;
        s32 field258;
        long field25C;
        long field260;
        s32 field244;
        s32 field268;
        s32 field264;
        s32 field270;
        s32 field274;
        void* field278;
    };
    extern f32 lbl_80561758;
    register u8* ptr = (u8*)arg0 + 0x14;
    *(void**)((u8*)arg0 + 8) = ptr;
    *(void**)arg0 = &lbl_8032F2BC;
    *(s32*)((u8*)arg0 + 0x10) = 10;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < (u8*)arg0 + 0x244);

    f32 val = lbl_80561758;
    u32 zero = 0;
    *(s32*)((u8*)arg0 + 0xC) = zero;
    *(s32*)((u8*)arg0 + 4) = (unsigned short)arg2;
    ((Tail*)arg0)->field244 = arg1;
    ((Tail*)arg0)->field258 = zero;
    ((Tail*)arg0)->field250 = val;
    ((Tail*)arg0)->field268 = zero;
    ((Tail*)arg0)->field248 = zero;
    *(void**)arg0 = &lbl_8032EB58;
    ((Tail*)arg0)->field274 = arg2;

    bool ok = !fn_80157278(arg2);
    if (ok) {
        ((Tail*)arg0)->field278 = fn_802076A0(lbl_8032EAF0, 1, arg2, 2);
    } else {
        ((Tail*)arg0)->field278 = (void*)zero;
    }
    return arg0;
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma small_data reset
#pragma dont_inline reset
#pragma auto_inline reset
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

#pragma small_data off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void* fn_801579F4(void* arg0, s32 arg1, s32 arg2) {
    /* Constructor-like initializer: set up base/vtable/state (lbl_8032F2BC), clear 10
     * 0x38-byte entries, store arg fields at +4/+0x244/+0x24C, then finalize vtable to
     * lbl_8032EBF8. */
    // Note: a typed final field retains the target's base plus 0x244 store form.
    struct Tail {
        u8 pad[0x244];
        s32 arg1;
        s32 zero;
        s32 arg2;
    };
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
    ((Tail*)arg0)->arg1 = arg1;
    ((Tail*)arg0)->zero = 0;
    ((Tail*)arg0)->arg2 = arg2;
    *(void**)arg0 = &lbl_8032EBF8;
    return arg0;
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma small_data reset
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

#pragma push
#pragma small_data off
extern "C" void* fn_80157B00(void* arg0, s32 arg1, s32 arg2) {
    extern void* lbl_8032EDD4;
    u8* ptr=(u8*)arg0+0x14;
    *(void**)((u8*)arg0+8)=ptr; *(void**)arg0=&lbl_8032F2BC;
    *(s32*)((u8*)arg0+0x10)=10; *(s32*)((u8*)arg0+0xC)=0;
    do { memset(ptr,0,4); ptr+=0x38; } while(ptr<(u8*)arg0+0x244);
    *(s32*)((u8*)arg0+4)=arg2; *(s32*)((u8*)arg0+0xC)=0;
    *(void**)arg0=&lbl_8032EDD4;
    *(s32*)((u8*)arg0+0x244)=arg1; *(s32*)((u8*)arg0+0x248)=0;
    *(f32*)((u8*)arg0+0x24C)=lbl_80561754;
    f32* p=(f32*)((u8*)arg0+0x254); f32* end=(f32*)((u8*)arg0+0x28C);
    while(p<end){*p=0.0f;p+=2;}
    *(f32*)((u8*)arg0+0x28C)=0.0f; *(f32*)((u8*)arg0+0x290)=0.0f;
    *(u8*)((u8*)arg0+0x294)=0; *(s32*)((u8*)arg0+0x298)=arg2;
    *(f32*)((u8*)arg0+0x24C)=lbl_80561754;
    return arg0;
}
#pragma small_data off
#pragma scheduling invalid_target
extern "C" void* fn_80157CF0(void* arg0, s32 arg1, s32 arg2) {
    u8* ptr = (u8*)arg0 + 0x14;
    *(void**)((u8*)arg0 + 8) = ptr;
    *(void**)arg0 = lbl_8032F2BC;
    *(s32*)((u8*)arg0 + 0x10) = 10;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < (u8*)arg0 + 0x244);
    f32 value = lbl_8056175C;
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 0xC) = 0;
    ((Fn80157CF0Obj*)arg0)->unk244 = arg1;
    *(s32*)((u8*)arg0 + 0x258) = 0;
    *(f32*)((u8*)arg0 + 0x250) = value;
    *(s32*)((u8*)arg0 + 0x268) = 0;
    *(s32*)((u8*)arg0 + 0x248) = 0;
    *(void**)arg0 = lbl_8032EE68;
    return arg0;
}
#pragma scheduling on
#pragma small_data reset
extern "C" void *fn_80157DA0(void *self, s32 arg1, s32 arg2) {
    extern void *lbl_8032EF08;
    extern float lbl_80561760;
    unsigned char *p;
    int *q;
    void *vt = &lbl_8032EF08;
    *(void **)((char *)self + 8) = (char *)self + 0x14;
    *(void **)self = &lbl_8032F2BC;
    *(int *)((char *)self + 0x10) = 10;
    *(int *)((char *)self + 0xC) = 0;
    p = (unsigned char *)self + 0x14;
    do {
        memset(p, 0, 4);
        p += 0x38;
    } while (p < (unsigned char *)self + 0x244);
    *(s32 *)((char *)self + 4) = arg2;
    *(int *)((char *)self + 0xC) = 0;
    *(s32 *)((char *)self + 0x244) = arg1;
    *(int *)((char *)self + 0x258) = 0;
    *(float *)((char *)self + 0x250) = lbl_80561760;
    *(int *)((char *)self + 0x268) = 0;
    *(int *)((char *)self + 0x248) = 0;
    *(void **)self = vt;
    *(int *)((char *)self + 0x270) = 0;
    *(int *)((char *)self + 0x274) = 0;
    q = (int *)((char *)self + 0x280);
    while (q < (int *)((char *)self + 0x2F0)) {
        q[0] = 0;
        q[1] = 0;
        q += 4;
    }
    *(int *)((char *)self + 0x2F0) = 0;
    *(int *)((char *)self + 0x2F4) = 0;
    *(int *)((char *)self + 0x26C) = 0;
    *(unsigned char *)((char *)self + 0x2F0) = 0;
    return self;
}

extern "C" f32 lbl_80561750;
extern "C" f32 lbl_80561758;
extern "C" void* __AXFXGetLfoSinTable_801769CC(void);
extern "C" f32 lbl_80561764;
extern "C" char lbl_8032EC98[];
#pragma small_data off
#pragma scheduling invalid_target
extern "C" void* fn_80157F98(void* self, s32 arg1, s32 arg2) {
    u8* ptr = (u8*)self + 0x14;
    *(void**)((u8*)self + 8) = ptr;
    *(void**)self = lbl_8032F2BC;
    *(s32*)((u8*)self + 0x10) = 10;
    *(s32*)((u8*)self + 0xC) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < (u8*)self + 0x244);
    f32 f0 = lbl_80561754;
    s32 zero = 0;
    void* vtable = lbl_8032EC98;
    f32 f1 = lbl_80561764;
    *(s32*)((u8*)self + 0xC) = zero;
    *(s32*)((u8*)self + 4) = arg2;
    ((Fn80157CF0Obj*)self)->unk244 = arg1;
    *(s32*)((u8*)self + 0x258) = zero;
    *(f32*)((u8*)self + 0x250) = f1;
    *(s32*)((u8*)self + 0x268) = zero;
    *(s32*)((u8*)self + 0x248) = zero;
    *(void**)self = vtable;
    *(s32*)((u8*)self + 0x270) = arg2;
    *(f32*)((u8*)self + 0x27C) = f0;
    return self;
}
#pragma small_data off
extern "C" void *fn_80158054(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    u8 *ptr = (u8 *)arg0 + 0x14;
    u8 *end = (u8 *)arg0 + 0x244;
    s32 zero = 0;
    *(void **)arg0 = lbl_8032F2BC;
    *(void **)((u8 *)arg0 + 8) = ptr;
    *(s32 *)((u8 *)arg0 + 0x10) = 10;
    *(s32 *)((u8 *)arg0 + 0x0C) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < end);
    f32 f0 = lbl_80561768;
    *(s32 *)((u8 *)arg0 + 4) = arg2;
    *(s32 *)((u8 *)arg0 + 0x0C) = zero;
    *(s32 *)((u8 *)arg0 + 0x244) = arg1;
    *(s32 *)((u8 *)arg0 + 0x258) = 0x41206;
    *(f32 *)((u8 *)arg0 + 0x250) = f0;
    *(s32 *)((u8 *)arg0 + 0x268) = zero;
    *(s32 *)((u8 *)arg0 + 0x248) = zero;
    *(void **)arg0 = lbl_8032EFA8;
    *(void **)((u8 *)arg0 + 0x2D8) = fn_802076A0(&lbl_8032EAFC, 1, arg2, 0);
    *(s32 *)((u8 *)arg0 + 0x2CC) = zero;
    return arg0;
}
#pragma small_data on
extern "C" f32 lbl_8056176C;
#pragma small_data off
extern "C" void* fn_8015812C(void* arg0, s32 arg1, s32 arg2, void* arg3) {
    extern f32 lbl_80561770;
    struct Tail {
        u8 pad244[0x244];
        s32 field244;
        s32 field248;
        f32 field24C;
        f32 field250;
        f32 field254;
        s32 field258;
        s32 field25C;
        s32 field260;
        s32 field264;
        s32 field268;
        s32 field26C;
        u8 pad270[8];
        s32 field278;
    };
    u8 *end = (u8 *)arg0 + 0x244;
    u8 *ptr = (u8 *)arg0 + 0x14;
    s32 zero = 0;
    *(void **)((u8 *)arg0 + 8) = ptr;
    *(void **)arg0 = &lbl_8032F2BC;
    *(s32 *)((u8 *)arg0 + 0x10) = 10;
    *(s32 *)((u8 *)arg0 + 0x0C) = 0;
    do {
        memset(ptr, 0, 4);
        ptr += 0x38;
    } while (ptr < end);
    f32 f0 = lbl_80561770;
    f32 f1 = lbl_80561750;
    f32 f2 = lbl_8056176C;
    ((Tail *)arg0)->field248 = zero;
    *(s32 *)((u8 *)arg0 + 0x0C) = zero;
    *(s32 *)((u8 *)arg0 + 4) = arg2;
    ((Tail *)arg0)->field244 = arg1;
    ((Tail *)arg0)->field268 = 0x40902;
    ((Tail *)arg0)->field24C = f2;
    ((Tail *)arg0)->field250 = f1;
    ((Tail *)arg0)->field254 = f0;
    ((Tail *)arg0)->field248 = zero;
    ((Tail *)arg0)->field26C = zero;
    *(void **)arg0 = &lbl_8032F0E8;
    ((Tail *)arg0)->field278 = zero;
    if (ptr != end) {
        u8 *zeroPtr = (u8 *)zero;
        zeroPtr[0x4D] = 1;
        *(f32 *)(zeroPtr + 8) = f0;
        ((Tail *)arg0)->field26C = 0;
    }
    return arg0;
}
#pragma small_data on
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

extern "C" void *fn_80158280(void *arg0, s32 *arg1) {
    s32 val = *arg1;
    s32 idx = ((s32 *)arg0)[1];
    s32 *base = *(s32 **)arg0;
    ((s32 *)arg0)[1] = idx + 1;
    base[idx] = val;
    return &base[idx];
}

extern "C" char lbl_8032F184[];
extern "C" f32 lbl_80561774;
extern "C" f32 lbl_80561770;
extern "C" void* fn_801582A4(void* self, s32 arg1, s32 arg2, void* arg3) {
    u8* p = (u8*)self + 0x14;
    *(void**)((u8*)self + 8) = p;
    *(void**)self = &lbl_8032F2BC;
    *(s32*)((u8*)self + 0x10) = 10;
    *(s32*)((u8*)self + 0xC) = 0;
    do {
        memset(p, 0, 4);
        p += 0x38;
    } while (p < (u8*)self + 0x244);
    *(s32*)((u8*)self + 0x248) = 0;
    *(s32*)((u8*)self + 0xC) = 0;
    *(s32*)((u8*)self + 4) = arg2;
    *(s32*)((u8*)self + 0x244) = arg1;
    *(s32*)((u8*)self + 0x268) = 0x40901;
    *(f32*)((u8*)self + 0x24C) = 30.5f;
    *(f32*)((u8*)self + 0x250) = 1.0f;
    *(f32*)((u8*)self + 0x254) = 305.0f;
    *(s32*)((u8*)self + 0x248) = 0;
    *(s32*)((u8*)self + 0x26C) = 0;
    *(void**)self = &lbl_8032F184;
    *(s32*)((u8*)self + 0x278) = arg2;
    return self;
}

extern "C" void *fn_802076A0(void *, s32, s32, s32);
extern "C" f32 lbl_80561778;
extern "C" void *fn_80158374(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* Initializes a two-slot object holder at arg0: if the slot type (arg3) is not the special "ACAR" case, allocates two objects and sets their default scale/speed fields (1.2f at +4, 1.0f at +8) with dirty flags (+0x4E/+0x4D) when changed; then marks the holder active (+8 = 1). */
    s32 should_allocate = (fn_80157278(arg3) == 0);
    void *firstObj;
    void *secondObj;

    *(void **)((u8 *)arg0 + 4) = 0;
    *(void **)arg0 = 0;
    if (should_allocate) {
        firstObj = fn_802076A0((void *)(u32)arg1, 1, arg3, 0);
        *(void **)arg0 = firstObj;
        if (firstObj != 0) {
            f32 value = lbl_80561778;
            if (value != *(f32 *)((u8 *)firstObj + 4)) {
                *((u8 *)firstObj + 0x4e) = 1;
                *(f32 *)((u8 *)firstObj + 4) = value;
            }
            firstObj = *(void **)arg0;
            value = lbl_80561750;
            if (value != *(f32 *)((u8 *)firstObj + 8)) {
                *((u8 *)firstObj + 0x4d) = 1;
                *(f32 *)((u8 *)firstObj + 8) = value;
            }
        }
        secondObj = fn_802076A0((void *)(u32)arg2, 1, arg3, 0);
        *(void **)((u8 *)arg0 + 4) = secondObj;
        if (secondObj != 0) {
            f32 value = lbl_80561778;
            if (value != *(f32 *)((u8 *)secondObj + 4)) {
                *((u8 *)secondObj + 0x4e) = 1;
                *(f32 *)((u8 *)secondObj + 4) = value;
            }
            secondObj = *(void **)((u8 *)arg0 + 4);
            value = lbl_80561750;
            if (value != *(f32 *)((u8 *)secondObj + 8)) {
                *((u8 *)secondObj + 0x4d) = 1;
                *(f32 *)((u8 *)secondObj + 8) = value;
            }
        }
    }
    *(s32 *)((u8 *)arg0 + 8) = 1;
    return arg0;
}

extern "C" void fn_801584A4(void* arg0) {
}

extern "C" void fn_801584A8(void* arg0) {
    *(u32*)((u8*)arg0 + 0) = (u32)arg0 + 0xC;
    *(u32*)((u8*)arg0 + 8) = 0x10;
    *(u32*)((u8*)arg0 + 4) = 0;
}

extern void lbl_8032F350(void);
extern "C" void fn_801584C4(void **arg0) {
    *arg0 = (void *)&lbl_8032F350;
}

#pragma use_lmw_stmw off
/* Notify every registered listener in lbl_8042FD34 by calling vtable slot 0 (+0x8). */
extern "C" void fn_801584D4(s32 arg0, s32 arg1, s32 arg2) {
    struct Dummy {
        virtual void f0(s32, s32, s32);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < ((UnkFD34*)lbl_8042FD34)->count) {
        void *obj = *(void **)((char *)((UnkFD34*)lbl_8042FD34)->items + offset);
        ((Dummy *)obj)->f0(arg0, arg1, arg2);
        offset += 4;
        i++;
    }
}
#pragma use_lmw_stmw reset
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
    if (count <= 0)
        goto notfound;
    do {
        if ((u32)*items == arg0)
            goto found;
        items++;
        index++;
    } while (--count > 0);
notfound:
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
    u32 i = 0;
    for (;;) {
        if (stricmp(*item, arg0) == 0) return i;
        item++;
        i += 1;
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
    for (; i < arg0->mCount; i++) {
        *(s32*)(arg0->mData + offset) = value;
        *(s32*)(arg0->mData + offset + 4) = value;
        *(s32*)(arg0->mData + offset + 8) = value;
        *(f32*)(arg0->mData + offset + 0xC) = zero;
        offset += 0x38;
    }
    f32 zero2 = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25C) = zero2;
    *(f32*)((u8*)arg0 + 0x260) = zero2;
    *(f32*)((u8*)arg0 + 0x258) = zero2;
    *(f32*)((u8*)arg0 + 0x264) = zero2;
    arg0->v31();
}

extern "C" f32 lbl_8056177C;
extern "C" s32 fn_80141F7C(f32);
extern "C" void fn_8015889C(void* arg0) {
    /* If this frame player has progress, emit the current record's scaled value and reset its counters. */
    Fn8015889C* self = (Fn8015889C*)arg0;
    if (self->mProgress25C > 0.0f) {
        f32 value = 0.0f;
        if (self->mProgress25C > self->mLevel24C) {
            if (self->v23() > 0) {
                value = self->mGain250 * self->v20(self->v23());
                self->v35(&value); self->v33();
            }
        }
        if (fn_80141F7C(value) == 0) self->v38(self->mProgress25C);
        f32 frameTime;
        f32 elapsed;
        f32 zero;
        elapsed = self->mTime258;
        frameTime = lbl_8056177C;
        zero = lbl_80561754;
        self->mProgress25C = zero;
        self->mProgress264 = zero;
        self->mTime258 = elapsed + frameTime;
    }
}

#pragma push
#pragma processor 750
extern "C" f32 fn_801589A8(Unk801577F0* self, s32 index) {
    /* Returns the record value for index, scaled by a 1x/2x factor when the
       AXFX LFO state flag 0x200000 and this object's enable flags (0x271/0x270)
       are set; returns 0 when the index is out of range or the flags are off. */
    struct V { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void q(); virtual s32 count(s32); };
    f32 value;
    f32 scale;
    if (index >= ((V*)self)->count(index)) value = *(f32*)(*(u8**)((u8*)self + 8) + index * 0x38 + 0x10);
    else value = lbl_80561754; /* 0.0f */
    if ((*((u32*)__AXFXGetLfoSinTable_801769CC() + 1) & 0x200000) != 0) {
        if (*((u8*)self + 0x271) != 0) {
            if (*((u8*)self + 0x270) != 0) scale = lbl_80561758; /* 2.0f */
            else scale = lbl_80561750; /* 1.0f */
            return value * scale;
        }
        return lbl_80561754; /* 0.0f */
    }
    return value;
}
#pragma pop
extern "C" s32 fn_80158A5C(void *arg0, s32 *arg1) { return *(s32 *)((u8 *)arg1 + 0x2620) == 0; }

extern "C" s32 fn_80158A6C(void) { return 0; }

extern "C" void fn_80158A74(void *arg0, f32 farg0) {
    *(f32 *)((u8 *)arg0 + 0x274) = farg0;
    *((u8 *)arg0 + 0x272) = 1;
}

extern "C" f32 lbl_80561754;
#pragma scheduling on
extern "C" void fn_80158A84(Unk801577F0 *arg0) {
    s32 value = 0;
    f32 zero;
    s32 i;
    s32 offset;
    *((u8 *)arg0 + 0x273) = (u8)value;
    i = 0;
    zero = lbl_80561754;
    offset = 0;
    *((u8 *)arg0 + 0x270) = (u8)value;
    *((u8 *)arg0 + 0x271) = (u8)value;
    *((u8 *)arg0 + 0x272) = (u8)value;
    for (; i < arg0->mCount; i++) {
        *(s32 *)(arg0->mData + offset) = value;
        *(s32 *)(arg0->mData + offset + 4) = value;
        *(s32 *)(arg0->mData + offset + 8) = value;
        *(f32 *)(arg0->mData + offset + 0xC) = zero;
        offset += 0x38;
    }
    f32 zero2 = lbl_80561754;
    *(f32 *)((u8 *)arg0 + 0x25C) = zero2;
    *(f32 *)((u8 *)arg0 + 0x260) = zero2;
    *(f32 *)((u8 *)arg0 + 0x258) = zero2;
    *(f32 *)((u8 *)arg0 + 0x264) = zero2;
    arg0->v31();
}

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
extern "C" f32 fn_80158B0C(void* arg0, void* arg1) {
    class Iface {
    public:
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual s32 m23();
        virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
        virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
        virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
        virtual void m36(); virtual s32 m37(void*);
    };
    f32 result = lbl_80561754;
    Iface* self = (Iface*)arg0;
    *((u8*)arg0 + 0x272) = 0;
    fn_8014AEC8(arg1);
    if (((s32 (*)(void))fn_80141F7C)() != 0 && self->m37(arg1) != 0) {
        if (*(f32*)((u8*)arg0 + 0x25C) > *(f32*)((u8*)arg0 + 0x24C)) self->m32();
        f32 speed = fn_80158E80(arg1);
        f32 scale = lbl_8056177C;
        f32 delta = scale * speed;
        f32 x = *(f32*)((u8*)arg0 + 0x25C) + delta;
        f32 y = *(f32*)((u8*)arg0 + 0x260) + delta;
        f32 z = *(f32*)((u8*)arg0 + 0x264) + delta;
        *(f32*)((u8*)arg0 + 0x25C) = x;
        *(f32*)((u8*)arg0 + 0x260) = y;
        *(f32*)((u8*)arg0 + 0x264) = z;
        self->m34();
        if (*(f32*)((u8*)arg0 + 0x25C) > *(f32*)((u8*)arg0 + 0x24C) && self->m23() > 0) {
            *(f32*)((u8*)arg0 + 0x258) = lbl_80561754;
            void* object = *(void**)((u8*)arg0 + 0x26C);
            if (object != 0) fn_80158E74(object);
        }
        result = lbl_80561754;
    } else if (((s32 (*)(f32))fn_80141F7C)(*(f32*)((u8*)arg0 + 0x258)) != 0) {
        result = fn_80158D60(arg0, arg1);
    } else {
        self->m33();
        f32 old = *(f32*)((u8*)arg0 + 0x258);
        *(f32*)((u8*)arg0 + 0x258) = old + lbl_8056177C;
        fn_80158D0C(arg0);
    }
    if (self->m23() == fn_80158D04(arg0) - 1) {
        result = fn_80158D60(arg0, arg1);
    }
    *((u8*)arg0 + 0x273) = (*((u8*)arg0 + 0x272) != 0 && *((u8*)arg0 + 0x271) != 0);
    *((u8*)arg0 + 0x270) = 0;
    *((u8*)arg0 + 0x271) = 0;
    return result;
}
#pragma pop
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
    /* Emit the current record's scaled value for this frame player and reset its
     * progress/time counters, returning the emitted value (or 0 when nothing is emitted). */
    Fn8015889C* self = (Fn8015889C*)arg0;
    f32 value = 0.0f;
    if (*(f32*)((u8*)arg0 + 0x25c) > *(f32*)((u8*)arg0 + 0x24c) && self->v23() > 0) {
        value = *(f32*)((u8*)arg0 + 0x250) * self->v20(self->v23());
        self->v35(&value);
        self->v33();
    }
    if (!((f32)__fabs(value) <= lbl_80558DC4[0]))
        self->v38(*(f32*)((u8*)arg0 + 0x25c));
    f32 time = *(f32*)((u8*)arg0 + 0x258) + lbl_8056177C;
    f32 zero = lbl_80561754;
    *(f32*)((u8*)arg0 + 0x25c) = zero;
    *(f32*)((u8*)arg0 + 0x264) = zero;
    *(f32*)((u8*)arg0 + 0x258) = time;
    return value;
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
/* Run a per-frame update for this object: apply a pre-hook, emit its current value when active,
 * and trigger an event for the selected entry under specific game-state conditions. */
extern "C" void fn_80158E88(void* self, void* context) {
    void* savedContext = context;
    s32 selectedValue;
    fn_80158F34(&savedContext);
    if (*(f32*)((u8*)self + 0x25C) > lbl_80561754) {
        fn_80158D60(self, savedContext);
    }
    selectedValue = *(s32*)((u8*)(*(u32*)((u8*)self + 8) +
        (*(s32*)((u8*)self + 0xC) - 1) * 0x38) + 4);
    if (selectedValue > 0 && fn_80179650() == 1 &&
        *(s32*)((u8*)context + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(3, selectedValue);
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

#pragma push
#pragma processor 750
extern "C" s32 fn_80158F98(void *arg0, f32 *arg1) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26();
        virtual s32 getA();
        virtual s32 getB();
    };
    extern f32 lbl_80561750;
    extern f32 lbl_80561754;
    if (*(u8 *)((u8 *)arg0 + 0x273) != 0) {
        if (arg1 != 0) {
            f32 field = *(f32 *)((u8 *)arg0 + 0x274);
            f32 value0 = (f32)((Dummy *)arg0)->getB();
            f32 value1 = (f32)((Dummy *)arg0)->getA();
            f32 ratio = (field - value1) / (value0 - value1);
            ratio = (lbl_80561750 > ratio) ? lbl_80561750 : ratio;
            ratio = (ratio > lbl_80561754) ? lbl_80561754 : ratio;
            *arg1 = lbl_80561754 + ratio * lbl_80561750;
        }
        return 1;
    }
    return 0;
}
#pragma pop
extern "C" void fn_801590A8(void* arg0) {
    f32 f0;
    f32 f1;
    ((Unk801577F0*)arg0)->v31();
    *(f32*)((char*)arg0 + 0x25c) = lbl_80561754;
    if (*(f32*)((char*)arg0 + 0x260) > *(f32*)((char*)arg0 + 0x24c)) {
        s32 object = *(s32*)((char*)arg0 + 0x268);
        if (object != 0) {
            fn_801CB750(object, *(s32*)((char*)arg0 + 4));
        }
        *(f32*)((char*)arg0 + 0x260) = lbl_80561754;
    }
    f1 = lbl_80561754;
    f0 = lbl_8056177C;
    *(f32*)((char*)arg0 + 0x264) = f1;
    *(f32*)((char*)arg0 + 0x258) = f0;
}

#pragma push
#pragma processor 750
extern "C" u8 fn_80159124(void* arg0, void* arg1) {
    u8* self = (u8*)arg0;
    u8* other = (u8*)arg1;
    if (*(s32*)(other + 0x2620) == 0) {
        *(f32*)(self + 0x270) = *(f32*)(self + 0x270) + lbl_8056177C;
    } else {
        *(f32*)(self + 0x270) = lbl_80561754;
    }
    f32 result = lbl_80561754;
    u8 prev = *(u8*)(self + 0x274);
    f32 limit = *(f32*)(other + 0x25D4);
    u8 flag;
    if ((f32)__fabs(*(f32*)(other + 0x2690)) <= lbl_80558DC4[0] && limit > lbl_80561788 && *(f32*)(self + 0x270) < lbl_80561760) {
        f32 d = (f32)__fabs(PSVECDotProduct(other + 0x118, other + 0x3C));
        f32 k = prev != 0 ? lbl_8056178C : lbl_80561790;
        flag = d > limit * k;
    } else {
        flag = 0;
    }
    *(u8*)(self + 0x274) = flag;
    if (flag != 0) {
        f32 lim2 = *(f32*)(other + 0x25D4);
        f32 d = (f32)__fabs(PSVECDotProduct(other + 0x118, other + 0x3C));
        f32 k = prev != 0 ? lbl_8056178C : lbl_80561790;
        f32 a = lbl_80561750 - lbl_80561794 * *(f32*)(self + 0x270);
        if (a <= lbl_80561754) {
            a = lbl_80561754;
        }
        f32 b = lbl_80561750;
        f32 t = lbl_80561788 * (d / (lim2 * k) - b);
        if (b >= t) {
            b = t;
        }
        if (b <= lbl_80561754) {
            b = lbl_80561754;
        }
        result = b * a;
    }
    u8* w = *(u8**)(self + 0x278);
    if (w != 0) {
        if ((f32)__fabs(result) <= lbl_80558DC4[0]) {
            w[0x4A] = 1;
            w[0x4C] = 0;
        } else {
            f32 v = lbl_80561798 * result;
            if (v != *(f32*)(w + 8)) {
                w[0x4D] = 1;
                *(f32*)(w + 8) = v;
            }
            w = *(u8**)(self + 0x278);
            w[0x4A] = 0;
            w[0x4B] = 1;
            w[0x49] = 1;
        }
    }
    return *(u8*)(self + 0x274);
}
#pragma pop
extern "C" void fn_80159724(void) {
}

#pragma push
#pragma processor 750
extern "C" f32 fn_80159728(void* arg0, void* arg1) {
 Fn8015889C* self = (Fn8015889C*)arg0;
 u8* p = (u8*)arg0;
 f32 result;
 result = lbl_80561754;
 if ((f32)__fabs(*(f32*)((u8*)arg1+0x2690)) <= lbl_80558DC4[0] && self->v37()) {
  if (*(f32*)(p+0x25c) > *(f32*)(p+0x24c)) self->v32();
  f32 input = *(f32*)((u8*)arg1+0x25d4);
  f32 step = lbl_8056177C * input;
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
 s32 current = self->v23();
 if (current == total-1) {
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
// One frame of the record-list player while it runs on its own: while the main
// progress counter has passed the level, hand the current record's value to
// v35 and let v33 emit it, notify v38 when that value is not zero, then clear
// the progress counters and advance the elapsed time by one 60 Hz frame.
extern "C" void fn_80159AB4(void* arg0) {
    Fn8015889C* self = (Fn8015889C*)arg0;
    volatile f32 value = 0.0f;
    if (self->mProgress25C > self->mLevel24C) {
        if (self->v23() > 0) {
            value = self->mGain250 * self->v20(self->v23());
            self->v35((f32*)&value); self->v33();
        }
    }
    if (fn_80141F7C(value) == 0) self->v38(self->mProgress25C);
    f32 frameTime;
    f32 elapsed;
    f32 zero;
    elapsed = self->mTime258;
    frameTime = lbl_8056177C;
    zero = lbl_80561754;
    self->mProgress25C = zero;
    self->mProgress264 = zero;
    self->mTime258 = elapsed + frameTime;
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
    f32 a = lbl_80561754;
    f = lbl_80561750;
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = a;
    arg0->m25c = f;
    arg0->v31();
}

extern f32 lbl_8056179C;
#pragma push
#pragma processor 750
extern "C" f32 fn_80159C34(Fn80159C34Obj* arg0, void* arg1) {
 s32 n; f32 value = arg0->m254 - lbl_8056177C, result = lbl_80561754; s32 done; s32 tmp2620;
 value = (result > value) ? result : value;
 tmp2620 = *(s32*)((u8*)arg1 + 0x2620);
 arg0->m254 = value;
 if (tmp2620 == 0 && ((Unk801577F0*)arg0)->v35() == 0) {
  f32 v2 = arg0->m254;
  v2 = (v2 > lbl_8056179C) ? lbl_8056179C : v2;
  arg0->m254 = v2;
  value = v2;
 }
 result = lbl_80561754; done = 0;
 if (arg0->v37() != 0) { n = *(s32*)((u8*)arg0 + 0xc); s32 cur = arg0->v21(); if (cur == n - 1) done = 1; }
 if ((f32)__fabs(arg0->m254) <= lbl_80558DC4[0] || done) {
  if (arg0->m264 > 0) { f32 temp = arg0->m25c * arg0->v18(arg0->v21()); arg0->v33(&temp); arg0->v31(); f32 full = lbl_80561750; arg0->m264 = 0; arg0->m25c = full; result = temp; }
  if (!done && arg0->m260 > 0) { if (arg0->m258 != 0) fn_801CB6E4((void*)arg0->m258, *(s32*)((u8*)arg0 + 4)); arg0->m260 = 0; }
 } else if (arg0->m264 > 0) arg0->v32();
 return result;
}
#pragma pop
extern "C" void fn_80159E2C(Unk8015A368C* arg0) {
    fn_80131234(lbl_8032E668[arg0->GetType()]);
}

extern "C" s32 fn_80159E6C(void) {
    return 4;
}

extern "C" void* fn_80159E74(void* arg0, s32 arg1) {
    /* Destructor-like cleanup: installs vtable lbl_8032EFA8, optionally destroys the
     * owned subobject at +0x2D8, clears the embedded subobject at +8, and frees when
     * arg1 > 0. */
    if (arg0 != 0) {
        void* owned = *(void**)((char*)arg0 + 0x2D8);
        *(void**)arg0 = lbl_8032EFA8;
        if (owned != 0) {
            if (owned != 0) {
                struct VTable {
                    virtual void destroy(s32);
                };
                ((VTable*)owned)->destroy(1);
            }
        }
        if (arg0 != 0) {
            if (arg0 != 0) {
                if ((u32)arg0 + 8 != 0) {
                    if ((u32)arg0 + 8 != 0) {
                        if ((u32)arg0 + 8 != 0) {
                            *(u32*)((char*)arg0 + 8) = 0;
                            *(u32*)((char*)arg0 + 0xC) = 0;
                            *(u32*)((char*)arg0 + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" u8 fn_80159F24(void* arg0) {
    return ((u8*)arg0)[0x2D1];
}

extern "C" f32 lbl_8055E3C8;
extern "C" void fn_8015A318(Unk8015A368C*);
extern "C" f32 fn_8015A368(void*);
extern "C" s32 fn_8015A404(void*);
extern "C" f32 lbl_805617A0, lbl_805617A4, lbl_805617A8;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" f32 fn_80159F2C(void* a, void* arg1, void* arg2) {
    u8* player = (u8*)arg1;
    u8* p = (u8*)a;
    s32 end, last;
    f32 full, value, delay, now;
    now = lbl_8055E3C8;
    if (p[0x2d1]) {
        f32 limit = lbl_805617A0;
        f32 elapsed = now - *(f32*)(p+0x2d4);
        if (!(elapsed > limit)) {
            bool fast = *(f32*)(player+0x25bc) > lbl_80558DC4[0];
            if (fast) goto skip_reset;
        }
        p[0x2d1] = 0;
    }
skip_reset:
    if (*(s32*)(p+0x264) == 0) {
        f32 threshold, speed;
        speed = *(f32*)(player+0x258c);
        threshold = lbl_8056175C;
        s32 flag = 1;
        *(s32*)(p+0x2cc) = 0;
        p[0x2d0] = 1;
        bool running = speed > threshold;
        if (!running) { if (!player[0x259c]) flag = 0; }
        if (flag || *(s32*)(player+0x2620) == 0) *(s32*)(p+0x2cc) |= 2;
        else *(s32*)(p+0x2cc) &= ~2;
    } else if (*(s32*)(player+0x2620) > 0) {
        u8* q = player;
        for (s32 j = 0; j < 4; j++, q += 0x74) {
            if (*(s32*)(q+0x2410) == 0) {
                p[0x2d0] = 0;
                break;
            }
        }
    }
    value = lbl_805617A8;
    full = lbl_80561750;
    delay = lbl_805617A4;
    u8* slot = p+0x26c;
    s32 count = 0;
    s32 handled = 0;
    for (s32 i = 0; i < 8; i++, slot += 0xc) {
        if (!slot[8] && now - *(f32*)(slot+4) > delay) {
            slot[8] = 1;
            if (!handled) {
                u8* obj = *(u8**)(p+0x2d8);
                if (obj) {
                    if (value != *(f32*)(obj+8)) {
                        obj[0x4d] = 1;
                        *(f32*)(obj+8) = value;
                    }
                    obj = *(u8**)(p+0x2d8);
                    obj[0x49] = 1;
                    obj[0x4b] = 0;
                    obj[0x4a] = 0;
                }
                ++*(s32*)(p+0x264);
                ++*(s32*)(p+0x260);
                *(f32*)(p+0x254) = *(f32*)(p+0x250);
                *(f32*)(p+0x25c) = full;
                ((Fn8015889C*)a)->v32();
                if (*(s32*)(p+0x248) && *(void**)(p+0x268))
                    *(s32*)((u8*)*(void**)(p+0x268)+8) = 0;
            }
            handled = 1;
            count++;
        }
    }
    if (count > 0) {
        s32 flag = 1;
        bool running = *(f32*)(player+0x258c) > lbl_8056175C;
        if (!running) { if (!player[0x259c]) flag = 0; }
        if (!flag && *(s32*)(player+0x2620) > 0) *(s32*)(p+0x2cc) &= ~2;
    }
    if (*(s32*)(p+0x264) > 0 && ((Fn8015889C*)a)->v23() > 0)
        *(s32*)(p+0x2cc) |= 1;
    *(f32*)(p+0x254) = fn_801429D0(lbl_80561754, *(f32*)(p+0x254)-lbl_8056177C);
    if (!fn_8015A404(arg1) && !((Fn8015889C*)a)->v37())
        *(f32*)(p+0x254) = fn_801429D0(*(f32*)(p+0x254), lbl_8056179C);
    f32 result = lbl_80561754;
    end = 0;
    if (((Fn8015889C*)a)->v39()) {
        last = fn_80158D04(a)-1;
        s32 current = ((Fn8015889C*)a)->v23();
        if (current == last) end = 1;
    }
    if (fn_80141F7C(*(f32*)(p+0x254)) || end) {
        if (*(s32*)(p+0x264) > 0) result = ((f32 (*)(void*, void*))fn_8015A368)(a,arg1);
        if (!end) fn_8015A318((Unk8015A368C*)a);
    } else if (*(s32*)(p+0x264) > 0) {
        ((Fn8015889C*)a)->v34();
    }
    last = *(s32*)(p+0xc);
    s32 current = ((Fn8015889C*)a)->v23();
    if (current == last-1) *(s32*)(p+0x2cc) = 0;
    return result;
}
#pragma pop

extern "C" void fn_8015A318(Unk8015A368C* arg0) {
    register s32 count = arg0->m260;
    if (count <= 0) {
        return;
    }
    register s32 buffer = arg0->m258;
    if (buffer) {
        void fn_801CB6E4(void*, s32);
        fn_801CB6E4((void*)buffer, *(s32*)&arg0->m4);
    }
    arg0->m260 = 0;
}

#pragma dont_inline on
extern "C" f32 fn_8015A368(void* arg0) {
    /* Finalize and return the bonus accumulator: compute (m25c * v18(v21())),
     * apply it via v33/v31, clear the pending count, and reset m25c to 1.0f. */
    f32 bonusValue;
    Unk8015A368C* bonus = (Unk8015A368C*)arg0;
    s32 currentIndex = bonus->v21();
    bonusValue = bonus->m25c * bonus->v18(currentIndex);
    bonus->v33(&bonusValue);
    bonus->v31();
    f32 one = lbl_80561750;
    bonus->m264 = 0;
    bonus->m25c = one;
    return bonusValue;
}
#pragma dont_inline off

extern "C" s32 fn_8015A404(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x2620);
}

#pragma scheduling invalid_target
extern "C" void fn_8015A40C(void *arg0) {
 extern f32 lbl_80561750, lbl_80561754, lbl_805617AC, lbl_805617B0;
 struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual f32 v18(s32); virtual f32 v19(s32); virtual void v20(); virtual s32 v21(); virtual void v22(); virtual s32 v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual s32 v29(); virtual void v30(); virtual s32 v31(); };
 f32 z;
 int count=0, offset=0;
 int zero=0;
 z=lbl_80561754;
 goto check;
loop:
 count++;
 *(int *)(*(volatile char **)((char *)arg0+8)+offset)=zero;
 *(int *)(*(volatile char **)((char *)arg0+8)+offset+4)=zero;
 *(int *)(*(volatile char **)((char *)arg0+8)+offset+8)=zero;
 *(f32 *)(*(volatile char **)((char *)arg0+8)+offset+0xc)=z;
 offset+=0x38;
check:
 if(count<*(int *)((char *)arg0+0xc)) goto loop;
 f32 val, one;
 one=lbl_80561754;
 val=lbl_80561750;
 *(int *)((char *)arg0+0x264)=zero; *(int *)((char *)arg0+0x260)=zero;
 *(f32 *)((char *)arg0+0x254)=one; *(f32 *)((char *)arg0+0x25c)=val;
 ((V *)arg0)->v31();
 f32 end, init;
 init=lbl_805617AC;
 end=lbl_805617B0;
 *(int *)((char *)arg0+0x26c)=zero;
 *(f32 *)((char *)arg0+0x270)=init; *(char *)((char *)arg0+0x274)=1;
 *(int *)((char *)arg0+0x278)=zero; *(f32 *)((char *)arg0+0x27c)=init; *(char *)((char *)arg0+0x280)=1;
 *(int *)((char *)arg0+0x284)=zero; *(f32 *)((char *)arg0+0x288)=init; *(char *)((char *)arg0+0x28c)=1;
 *(int *)((char *)arg0+0x290)=zero; *(f32 *)((char *)arg0+0x294)=init; *(char *)((char *)arg0+0x298)=1;
 *(int *)((char *)arg0+0x29c)=zero; *(f32 *)((char *)arg0+0x2a0)=init; *(char *)((char *)arg0+0x2a4)=1;
 *(int *)((char *)arg0+0x2a8)=zero; *(f32 *)((char *)arg0+0x2ac)=init; *(char *)((char *)arg0+0x2b0)=1;
 *(int *)((char *)arg0+0x2b4)=zero; *(f32 *)((char *)arg0+0x2b8)=init; *(char *)((char *)arg0+0x2bc)=1;
 *(int *)((char *)arg0+0x2c0)=zero; *(f32 *)((char *)arg0+0x2c4)=init; *(char *)((char *)arg0+0x2c8)=1;
 *(int *)((char *)arg0+0x2cc)=zero; *(char *)((char *)arg0+0x2d1)=0; *(f32 *)((char *)arg0+0x2d4)=end;
}
#pragma scheduling on
// End of this tree-run bonus tracker, called with the tracker and the player
// whose bonus ended. It runs the pre-hook, and if the tracker has an active
// banked count (tracker + 0x264 > 0) hands the hooked context to fn_80158F34b;
// then banks the last record's scored count in the "tree_run" lifetime counter
// -- only for a single player run (fn_80179650() == 1) in the ordinary truck
// (player + 0x1F0 == 0x50) that is not a replay playback (fn_801CF064()).
extern "C" void fn_8015A538(void* tracker, void* player) {
    void* hookedPlayer = player;
    fn_80158F34(&hookedPlayer);
    if (*(s32*)((char*)tracker + 0x264) > 0) {
        fn_80158F34b((void*)tracker, *(void**)((char*)&hookedPlayer));
    }
    void* records = *(void**)((char*)tracker + 8);
    void* lastRecord = (void*)((s32)records + (*(s32*)((char*)tracker + 0xC) - 1) * 0x38);
    s32 scoredCount = *(s32*)((char*)lastRecord + 4);
    if (scoredCount > 0 && fn_80179650() == 1 && *(s32*)((char*)player + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(4, scoredCount);
    }
}

extern f32 lbl_8055A02C;
extern f32 lbl_80561788;
extern f32 lbl_805617B4;
extern "C" void fn_8015A5E0(void *arg0, void *arg1, s32 arg2, u32 arg3) {
    u8 *base;
    u8 *p;
    u8 *q;
    s32 found;
    s32 i;
    f32 now;
    f32 tol;
    f32 lim;
    if (!(*(f32 *)((u8 *)arg1 + 0x25d4) > lbl_805617B4 * lbl_8055A02C) || arg2 != 0x3eb || *((u8 *)arg0 + 0x2d1)) {
        return;
    }
    now = lbl_8055E3C8;
    tol = lbl_80558DC4[0];
    lim = lbl_80561788;
    base = (u8 *)arg0 + 0x26c;
    found = 0;
    p = base;
    for (i = 0; i < 2; i++) {
        if ((f32)__fabs(*(f32 *)(p + 0x4) - now) <= tol) {
            found = 1;
        }
        if (*(u32 *)p == arg3 && now - *(f32 *)(p + 0x4) < lim) {
            return;
        }
        if ((f32)__fabs(*(f32 *)(p + 0x10) - now) <= tol) {
            found = 1;
        }
        if (*(u32 *)(p + 0xc) == arg3 && now - *(f32 *)(p + 0x10) < lim) {
            return;
        }
        if ((f32)__fabs(*(f32 *)(p + 0x1c) - now) <= tol) {
            found = 1;
        }
        if (*(u32 *)(p + 0x18) == arg3 && now - *(f32 *)(p + 0x1c) < lim) {
            return;
        }
        if ((f32)__fabs(*(f32 *)(p + 0x28) - now) <= tol) {
            found = 1;
        }
        if (*(u32 *)(p + 0x24) == arg3 && now - *(f32 *)(p + 0x28) < lim) {
            return;
        }
        p += 0x30;
    }
    p = 0;
    q = base;
    for (i = 0; i < 2; i++) {
        if (p == 0 || *(f32 *)(q + 0x4) < *(f32 *)(p + 0x4)) {
            p = q;
        }
        if (p == 0 || *(f32 *)(q + 0x10) < *(f32 *)(p + 0x4)) {
            p = q + 0xc;
        }
        if (p == 0 || *(f32 *)(q + 0x1c) < *(f32 *)(p + 0x4)) {
            p = q + 0x18;
        }
        if (p == 0 || *(f32 *)(q + 0x28) < *(f32 *)(p + 0x4)) {
            p = q + 0x24;
        }
        q += 0x30;
    }
    *(f32 *)(p + 0x4) = now;
    p[8] = found;
    *(u32 *)p = arg3;
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

#pragma scheduling invalid_target
extern "C" void fn_8015A81C(Unk801577F0* arg0) {
    f32 f = lbl_80561754;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 r5 = 0;
    s32 z = 0;
    for (; r6 < arg0->mCount; r6++) {
        *(s32*)(arg0->mData + r7) = r5;
        *(s32*)(arg0->mData + r7 + 4) = r5;
        *(s32*)(arg0->mData + r7 + 8) = r5;
        *(f32*)(arg0->mData + r7 + 0xC) = f;
        r7 += 0x38;
    }
    f32 a = lbl_80561754;
    f = lbl_80561750;
    arg0->m264 = z;
    arg0->m260 = z;
    arg0->m254 = a;
    arg0->m25c = f;
    arg0->v31();
    *(s32*)((u8*)arg0 + 0x26c) = z;
    *(u8*)((u8*)arg0 + 0x2f0) = (u8)z;
}

extern "C" s32 fn_801D48FC(s32);
extern "C" s32 fn_801D4908(s32, void*, s32);
extern "C" s32 fn_801DDA84(void*, void*, s32, f32, f32, f32);
extern "C" f32 fn_801DDC8C(void*, f32, f32);
extern "C" void fn_801E9DC4(void*);
extern "C" void fn_80198EA0(s32);
extern "C" f32 lbl_805617B4, lbl_805617B8, lbl_805617BC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" f32 fn_8015A8D8(void* a, void* arg1) {
    u8* p = (u8*)a;
    s32 end;
    if (p[0x2f0]) {
        s32 active = fn_801D48FC(*(s32*)(p+0x26c));
        p[0x2f0] = active;
        f32 zero = lbl_80561754, step = lbl_8056177C, full = lbl_80561750;
        f32 margin = lbl_805617B4, minimum = lbl_805617B8;
        register s32 owner;
        register u8* slot = p;
        register s32 i = 0;
        for (; i < 8; i++, slot += 0x10) {
            owner = *(s32*)(p+0x26c);
            s32 enabled;
            *(s32*)(slot+0x274) = *(s32*)(slot+0x270);
            if (!*(s32*)(slot+0x270)) { enabled = 0; } else {
                u8* car = (u8*)fn_8017960C(*(s32*)(slot+0x278));
                if (!car) { enabled = 0; } else {
                    s32 running = *(s32*)(car+0x2620) > 0;
                    switch (*(s32*)(slot+0x270)) {
                    case 1:
                        if (car) { s32 next = 2; if (running) next = 3; *(s32*)(slot+0x270) = next; }
                        else *(s32*)(slot+0x270) = 0;
                        break;
                    case 2:
                        if (running) *(s32*)(slot+0x270) = 3;
                        break;
                    case 3:
                        if (!running) {
                            *(s32*)(slot+0x270) = 2;
                            u8 query[8];
                            u8 points[40];
                            fn_801E9DC4(query);
                            f32 dist = fn_801DDC8C(query, *(f32*)(car+0x60), *(f32*)(car+0x68));
                            if (dist > minimum && *(f32*)(car+0x11c) - dist > margin) {
                                fn_801E9DC4(query);
                                s32 n = fn_801DDA84(query, points, 10, *(f32*)(car+0x60), *(f32*)(car+0x68), lbl_805617BC);
                                if (fn_801D4908(owner, points, n)) {
                                    *(s32*)(slot+0x270) = 4;
                                    *(f32*)(slot+0x27c) = full;
                                }
                            }
                        }
                        break;
                    case 5:
                        break;
                    case 4:
                        *(f32*)(slot+0x27c) -= step;
                        if (*(f32*)(slot+0x27c) < zero) *(s32*)(slot+0x270) = 5;
                        else if (running) *(s32*)(slot+0x270) = 3;
                        break;
                    }
                    enabled = (active || *(s32*)(slot+0x270) == 4);
                }
            }
            p[0x2f0] = (p[0x2f0] | enabled) != 0;
            s32 changed = 0;
            if (*(s32*)(slot+0x270) == 5 && *(s32*)(slot+0x274) != 5) changed = 1;
            if (changed) {
                ++*(s32*)(p+0x264);
                ++*(s32*)(p+0x260);
                *(f32*)(p+0x254) = *(f32*)(p+0x250);
                *(f32*)(p+0x25c) = full;
                ((Fn8015889C*)a)->v32();
                if (*(s32*)(p+0x248) && *(void**)(p+0x268))
                    *(s32*)((u8*)*(void**)(p+0x268)+8) = 0;
                fn_80198EA0(i);
            }
        }
        if (!p[0x2f0]) *(s32*)(p+0x26c) = 0;
    }
    *(f32*)(p+0x254) = fn_801429D0(lbl_80561754, *(f32*)(p+0x254)-lbl_8056177C);
    if (!fn_8015A404(arg1) && !((Fn8015889C*)a)->v37())
        *(f32*)(p+0x254) = fn_801429D0(*(f32*)(p+0x254), lbl_8056179C);
    f32 result = lbl_80561754;
    end = 0;
    if (((Fn8015889C*)a)->v39()) {
        s32 last = fn_80158D04(a)-1;
        s32 current = ((Fn8015889C*)a)->v23();
        if (current == last) end = 1;
    }
    if (fn_80141F7C(*(f32*)(p+0x254)) || end) {
        if (*(s32*)(p+0x264) > 0) result = ((f32 (*)(void*, void*))fn_8015A368)(a,arg1);
        if (!end) fn_8015A318((Unk8015A368C*)a);
    } else if (*(s32*)(p+0x264) > 0) {
        ((Fn8015889C*)a)->v34();
    }
    return result;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void fn_8015ACB0(void *arg0, void *arg1, s32 arg2, f32 arg3) {
    /* Initialize 8 UI slots (two 4-slot blocks) when mode==3: mark object enabled,
     * store arg3, then for each slot set {state,id} to disabled {-1,0,0} if the
     * slot index equals arg1+0x1EC count, else {index,1,1}. */
    if (arg2 != 3) return;
    volatile f32 savedValue = arg3;
    register s32 one = 1;
    s32 slotCount;
    u8 *obj = (u8 *)arg0;
    s32 slotIndex = 0;
    *(u8 *)(obj + 0x2F0) = one;
    *(u32 *)(obj + 0x26C) = *(volatile u32 *)&savedValue;
    for (s32 block = 0; block < 2; block++) {
#define SET_SLOT(off) \
        slotCount = *(s32 *)((u8 *)arg1 + 0x1EC); \
        if (slotIndex == slotCount) { \
            *(s32 *)(obj + (off) + 8) = -1; \
            *(s32 *)(obj + (off)) = 0; \
            *(s32 *)(obj + (off) + 4) = 0; \
        } else { \
            *(s32 *)(obj + (off) + 8) = slotIndex; \
            *(s32 *)(obj + (off)) = one; \
            *(s32 *)(obj + (off) + 4) = one; \
        }
        SET_SLOT(0x270)
        slotIndex++;
        SET_SLOT(0x280)
        slotIndex++;
        SET_SLOT(0x290)
        slotIndex++;
        SET_SLOT(0x2A0)
        obj += 0x40;
        slotIndex++;
    }
#undef SET_SLOT
}
#pragma pop
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

extern f32 lbl_805617A8;
#pragma push
#pragma processor 750
extern "C" f32 fn_8015AE18(void *a, void *arg1) {
    s32 reward = *(s32 *)((u8 *)arg1 + 0x2620);
    u8 *p = (u8 *)a;
    Fn8015889C *self = (Fn8015889C *)a;
    f32 result;
    s32 nlast;
    s32 end;
    s32 cnt;
    s32 cur;
    s32 zero = 0;
    s32 i;
    f32 t0;
    if (reward > 0) {
        *(f32 *)(p + 0x270) = *(f32 *)(p + 0x270) + lbl_8056177C;
    } else {
        *(f32 *)(p + 0x270) = lbl_80561754;
    }
    if (*(u8 *)(p + 0x26c) != 0) {
        f32 f = lbl_80561750;
        *(s32 *)(p + 0x274) = *(s32 *)(p + 0x274) + 1;
        *(s32 *)(p + 0x278) = *(s32 *)(p + 0x278) + 1;
        *(u8 *)(p + 0x26c) = zero;
        for (i = 0; i < *(s32 *)(p + 0x274); i++) {
            *(s32 *)(p + 0x264) = *(s32 *)(p + 0x264) + 1;
            *(s32 *)(p + 0x260) = *(s32 *)(p + 0x260) + 1;
            *(f32 *)(p + 0x254) = *(f32 *)(p + 0x250);
            *(f32 *)(p + 0x25c) = f;
            self->v32();
            if (*(s32 *)(p + 0x248) != 0 && *(void **)(p + 0x268) != 0) {
                *(s32 *)(*(u8 **)(p + 0x268) + 8) = zero;
            }
        }
    }
    cnt = *(s32 *)(p + 0xc);
    cur = self->v23();
    if (cur == cnt - 1) {
        *(s32 *)(p + 0x274) = 1;
    }
    if (*(f32 *)(p + 0x270) > lbl_805617A8) {
        *(s32 *)(p + 0x274) = zero;
        s32 n = *(s32 *)(p + 0x278);
        if (n > 0) {
            fn_801CB6E4((void *)0x50204, *(s32 *)(p + 4));
            *(s32 *)(p + 0x278) = zero;
        }
    }
    *(u8 *)(p + 0x26c) = 0;
    t0 = *(f32 *)(p + 0x254);
    *(f32 *)(p + 0x254) = fn_801429D0(lbl_80561754, t0 - lbl_8056177C);
    if (fn_8015A404(arg1) == 0 && self->v37() == 0) {
        *(f32 *)(p + 0x254) = fn_801429D0(*(f32 *)(p + 0x254), lbl_8056179C);
    }
    result = lbl_80561754;
    end = 0;
    if (self->v39()) {
        nlast = fn_80158D04(a) - 1;
        cur = self->v23();
        if (cur == nlast) end = 1;
    }
    if (fn_80141F7C(*(f32 *)(p + 0x254)) || end) {
        if (*(s32 *)(p + 0x264) > 0) result = ((f32 (*)(void *, void *))fn_8015A368)(a, arg1);
        if (!end) fn_8015A318((Unk8015A368C *)a);
    } else if (*(s32 *)(p + 0x264) > 0) {
        self->v34();
    }
    return result;
}
#pragma pop
extern "C" void fn_8015B0A4(Unk801577F0 *arg0) {
    f32 f;
    s32 count = arg0->m260;
    arg0->m264 = 0;
    if (count > 0) {
        void* ptr = (void*)(u32)arg0->m258;
        if (ptr != 0) {
            fn_801CB6E4(ptr, arg0->m4);
        }
        arg0->m260 = 0;
        f32 a = lbl_80561754;
        Unk801577F0* self = arg0;
        f = lbl_80561750;
        self->m254 = a;
        self->m25c = f;
        self->v31();
    }
    s32 zero = 0;
    count = *(s32*)((u8*)arg0 + 0x278);
    f = lbl_80561754;
    *(u8*)((u8*)arg0 + 0x26C) = zero;
    *(f32*)((u8*)arg0 + 0x270) = f;
    *(s32*)((u8*)arg0 + 0x274) = zero;
    if (count > 0) {
        fn_801CB6E4((void*)0x50204, arg0->m4);
        *(s32*)((u8*)arg0 + 0x278) = zero;
    }
}
#pragma scheduling on
/* Resets per-entry state for this object and clears its aggregate/tail fields. */
extern "C" void fn_8015B15C(Unk801577F0* arg0) {
    f32 zero = 0.0f;
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
    f32 b;
    f32 a;
    a = 0.0f;
    b = 1.0f;
    *(s32*)((u8*)arg0 + 0x264) = 0;
    *(s32*)((u8*)arg0 + 0x260) = 0;
    *(f32*)((u8*)arg0 + 0x254) = a;
    *(f32*)((u8*)arg0 + 0x25C) = b;
    arg0->v31();
    f32 tail = 0.0f;
    *(u8*)((u8*)arg0 + 0x26C) = 1;
    *(f32*)((u8*)arg0 + 0x270) = tail;
    *(s32*)((u8*)arg0 + 0x274) = 0;
    *(s32*)((u8*)arg0 + 0x278) = 0;
}
extern "C" void fn_8015B228(void* arg0, s32 arg1, s32 arg2) {
    if (arg2 == 6) *(u8*)((char*)arg0 + 0x26C) = 1;
}

extern "C" void fn_8015B23C(Unk8015A368C* object) {
    /* If this object has a pending update (+0x264 > 0), apply scale factor
     * (+0x25C) times v18(v21()) via v33, run v31, then clear the pending
     * count and reset the scale to 1.0 (lbl_80561750). */
    if (*(s32*)((u8*)object + 0x264) > 0) {
        f32 value;
        s32 result = object->v21();
        value = *(f32*)((u8*)object + 0x25C) * object->v18(result);
        object->v33(&value);
        object->v31();
        f32 zero = lbl_80561750;
        *(s32*)((u8*)object + 0x264) = 0;
        *(f32*)((u8*)object + 0x25C) = zero;
    }
}

#pragma scheduling on
extern "C" s32 fn_8015B2E0(void* arg0) {
    if (*(unsigned char*)((unsigned char*)arg0 + 0x294)) return 0x7FFFFFFF;
    float value = *(float*)((unsigned char*)arg0 + 0x290);
    if (value > lbl_80558DC4[0]) return (s32)value;
    return (s32)*(float*)((unsigned char*)arg0 + 0x28C);
}
#pragma scheduling reset
extern "C" s32 fn_8015B338(void) { return 0xC; }

extern "C" void fn_8015B340(Unk801577F0* self) {
    f32 entryZero = lbl_80561754;
    s32 i = 0;
    s32 offset = 0;
    s32 value = 0;
    for (; i < self->mCount; i++) {
        *(s32*)(self->mData + offset) = value;
        *(s32*)(self->mData + offset + 4) = value;
        *(s32*)(self->mData + offset + 8) = value;
        *(f32*)(self->mData + offset + 0xC) = entryZero;
        offset += 0x38;
    }
    self->v31();
    f32 tailZero = lbl_80561754;
    *(u8*)((u8*)self + 0x294) = 0;
    *(f32*)((u8*)self + 0x290) = tailZero;
    *(f32*)((u8*)self + 0x28C) = tailZero;
    *(f32*)((u8*)self + 0x24C) = tailZero;
    *(f32*)((u8*)self + 0x254) = tailZero;
    *(f32*)((u8*)self + 0x25C) = tailZero;
    *(f32*)((u8*)self + 0x264) = tailZero;
    *(f32*)((u8*)self + 0x26C) = tailZero;
    *(f32*)((u8*)self + 0x274) = tailZero;
    *(f32*)((u8*)self + 0x27C) = tailZero;
    *(f32*)((u8*)self + 0x284) = tailZero;
}

#pragma push
#pragma processor 750
extern "C" f32 fn_8015B404(void* arg0) {
    Fn8015B404Obj* self = (Fn8015B404Obj*)arg0;
    u8* base = (u8*)arg0;
    f32 one = lbl_8056177C;
    f32 zero = lbl_80561754;
    u8* p = base;
    s32 i = 0;
    *(u8*)(base + 0x294) = 0;
    *(f32*)(base + 0x290) = zero;
    *(f32*)(base + 0x28C) = zero;
    do {
        s32 active = *(f32*)(p + 0x24C) > lbl_80558DC4[0];
        if (active) {
            f32 a = *(f32*)(p + 0x250);
            f32 b = *(f32*)(base + 0x28C);
            b = (b > a) ? b : a;
            *(f32*)(base + 0x28C) = b;
            s32 still = *(f32*)(p + 0x24C) > lbl_80558DC4[0];
            if (still) {
                f32 t = *(f32*)(p + 0x24C);
                *(f32*)(p + 0x24C) = t - one;
            }
            u8* o = (u8*)fn_8017960C(i);
            s32 more;
            s32 flag;
            if (o != 0) {
                flag = !((f32)__fabs(*(f32*)(o + 0x2690)) <= lbl_80558DC4[0]);
            } else {
                flag = 0;
            }
            if (flag != 0 || (more = *(f32*)(p + 0x24C) > lbl_80558DC4[0]) == 0) {
                *(f32*)(p + 0x24C) = zero;
                *(u8*)(base + 0x294) = flag;
                f32 d = *(f32*)(p + 0x250);
                f32 c = *(f32*)(base + 0x290);
                c = (c > d) ? c : d;
                *(f32*)(base + 0x290) = c;
            }
        }
        i++;
        p += 8;
    } while (i < 8);
    f32 result = lbl_80561754;
    if (*(f32*)(base + 0x28C) > lbl_80558DC4[0]) {
        self->v30();
        self->v32();
        if (*(f32*)(base + 0x290) > lbl_80558DC4[0]) {
            f32 sp8 = self->v18(self->v21());
            self->v33(&sp8);
            self->v31();
            result = sp8;
        }
    }
    return result;
}
#pragma pop
extern "C" void fn_8015B618(void *arg0, void *context) {
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
    f32 selectedValue;
    s32 selectedIndex;
    s32 itemId;

    /* If the active timer/value at 0x28C is above threshold, refresh selection via vtable hooks. */
    if (*(f32*)((u8*)arg0 + 0x28C) > lbl_80558DC4[0]) {
        selectedIndex = ((LocalVtable*)arg0)->v21();
        selectedValue = ((LocalVtable*)arg0)->v18(selectedIndex);
        ((LocalVtable*)arg0)->v33(&selectedValue);
        ((LocalVtable*)arg0)->v31();
    }
    itemId = *(s32*)(*(u8**)((u8*)arg0 + 8) +
                     (*(s32*)((u8*)arg0 + 0xC) - 1) * 0x38 + 4);
    if (itemId > 0 && fn_80179650() == 1 &&
        *(s32*)((u8*)context + 0x1F0) == 0x50 &&
        fn_801CF064() == 0) {
        fn_8001EF5C(7, itemId);
    }
}

extern "C" void fn_8015B708(Unk801577F0* self) {
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
    s32 index = self->v21();

    /* Fetch the selected index/value and apply it via v33/v31. */
    value = self->v18(index);
    ((LocalVtable*)self)->v33(&value);
    ((LocalVtable*)self)->v31();
}

extern "C" void* fn_8017960C(s32);
extern "C" f32 lbl_805617C0;
#pragma push
#pragma processor 750
/* Updates a per-slot timer/value pair for arg1, tracking the max value while the source object remains valid. */
extern "C" void fn_8015B788(void* arg0, s32 arg1, f32 farg0) {
    void* obj = fn_8017960C(arg1);
    BOOL invalid;

    if (obj != 0) {
        invalid = !((f32)__fabs(*(f32*)((u8*)obj + 0x2690)) <= lbl_80558DC4[0]);
    } else {
        invalid = FALSE;
    }
    if (invalid) {
        return;
    }

    u8* p = (u8*)arg0 + arg1 * 8;
    if ((f32)__fabs(*(f32*)(p + 0x24C)) <= lbl_80558DC4[0]) {
        *(f32*)(p + 0x250) = farg0;
    } else {
        f32 cur = *(f32*)(p + 0x250);
        *(f32*)(p + 0x250) = (farg0 > cur) ? farg0 : cur;
    }
    *(f32*)(p + 0x24C) = lbl_805617C0;
}
#pragma pop
extern "C" void fn_8015B864(void *arg0) {
    struct Obj {
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
        virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
        virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14();
        virtual void p15(); virtual void p16(); virtual s32 lower();
        virtual void p18(); virtual void p19(); virtual void p20(); virtual s32 upper();
        virtual void noop(); virtual s32 progress();
        virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28();
        virtual s32 type();
    };
    struct Adaptor {
        virtual void a0();
        virtual void a1();
        virtual void format(int, ...);
        virtual void a3();
        virtual void clear();
        virtual void a5();
        virtual void setProgress(s32);
        virtual void a7();
        virtual void setState(s32);
    };
    Obj *obj = (Obj *)arg0;
    s32 limit, current;
    /* Updates the attached UI adaptor with progress/type and marks complete when upper >= lower. */
    if (*(void **)((char *)arg0 + 0x248) != 0) {
        (*(Adaptor **)((char *)arg0 + 0x248))->format((int)&lbl_8055A058[0], obj->progress());
        (*(Adaptor **)((char *)arg0 + 0x248))->setProgress(obj->type());
        obj->noop();
        (*(Adaptor **)((char *)arg0 + 0x248))->clear();
        limit = obj->lower();
        current = obj->upper();
        if (current >= limit) {
            (*(Adaptor **)((char *)arg0 + 0x248))->setState(1);
        }
    }
    if (*(void **)((char *)arg0 + 0x248) != 0) {
        (*(Adaptor **)((char *)arg0 + 0x248))->format((int)&lbl_8055A058[0], obj->progress());
    }
}

// ---------------------------------------------------------------------------
// Bonus (trick) scoring.  One tracker object exists per bonus category; the
// category names ("air", "nice_landing", "offroad", "drift", "close_call",
// "turbo_close_call", "high_speed", "360", "roll", "car_throw", "jump_combo",
// "car_hit_car", "crash", "ring") are in the table at lbl_8032E540, indexed by
// the tracker's GetType().  A tracker owns mCount (tracker+0xC) records of
// 0x38 bytes at tracker+0x8, filled in by fn_801572A4 from the bonus config
// ("rank", "adj", "thresh" and a value):
//
//     s32 count;        // 0x00 times a value was scored here
//     s32 scoredCount;  // 0x04 ... with a value that was not zero
//     s32 sameCount;    // 0x08 ... with the value expected at +0x10
//     f32 total;        // 0x0C sum of the scored values
//     f32 expected;     // 0x10 the value the config table asked for
//     s32 thresh;       // 0x14 the config table's "thresh"
//     char name[0x20];  // 0x18 label built from the config key
//
// The layout is documented here only: the matched code below keeps the raw
// byte offsets, which is what the original compiler emitted.
struct BonusRecord {
    s32 count;
    s32 scoredCount;
    s32 sameCount;
    f32 total;
    f32 expected;
    s32 thresh;
    char name[0x20];
};

// The tracker's virtual interface, as far as this file's methods use it.
// GetType() is Unk801577F0::GetType(), the index into the category names.
// These game vtables start with two destructor slots, so v0 is the slot at 0x8.
struct BonusTracker {
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
    virtual void v10(s32);   // 0x30 what the group forwards (fn_8015E80C); the trackers seen here leave it empty (fn_8015E0FC)
    virtual void v11();
    virtual void v12();
    virtual void v13(s32);   // 0x3C what the group forwards (fn_8015E5F4); the air tracker flushes its progress here
    virtual void v14();
    virtual void v15();
    virtual void drawToDisplay(void* display);  // 0x48 write this tracker's line into the bonus popup (fn_8015DD9C)
    virtual s32 getRecordCount();  // 0x4C records this tracker holds
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual s32 getIndex();        // 0x5C record being scored
    virtual void refresh();        // 0x60 hook while the popup is being filled
    virtual s32 getCount();        // 0x64 shown by BonusDisplay::printCount
    virtual s32 getExtra();        // 0x68 shown by BonusDisplay::printExtra
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual s32 GetType();         // 0x7C bonus category
    // Past the category getters, the trackers that run on a timer (fn_8015CFFC,
    // fn_8015C264 and fn_80159F2C) use these:
    virtual void scoreEvent();      // 0x80 score one queued event
    virtual void v30();             // 0x84
    virtual void refreshDisplay();  // 0x88 redraw the popup with what has been scored
    virtual void v32();             // 0x8C
    virtual void v33();             // 0x90
    virtual s32 mayTimeOut();       // 0x94 non-zero lets the bonus timer reach zero
    virtual void v35();             // 0x98
    virtual s32 hasRecords();       // 0x9C non-zero while the record table can end the bonus
};

// The bonus popup a tracker drives (tracker+0x248; NULL while none is up).
// Each print* takes a printf-style format ("%s") plus the value to show;
// update() commits what was printed.
struct BonusDisplay {
    virtual void v0();
    virtual void printExtra(s32 fmt, ...);  // 0x0C
    virtual void printCount(s32 fmt, ...);  // 0x10
    virtual void printScore(s32 fmt, ...);  // 0x14
    virtual void update();                  // 0x18
    virtual void setScore(s32 score);       // 0x1C
    virtual void setProgress(s32 type);     // 0x20
    virtual void v7();                      // 0x24
    virtual void setState(s32 state);       // 0x28
};

// The per-course group of bonus trackers (allocation tag "arraytracker", built by
// fn_801572A4 and kept at contest-entry+0x9F4).  It owns one tracker per bonus
// category -- "air", "drift", "ccall", "360", "throw", "jmpcmb", "carhit",
// "crash" and "ring" -- and implements the tracker interface itself by handing
// every call to the trackers in its array (fn_8015E2C8, fn_8015E4CC, fn_8015E568,
// fn_8015E5F4, fn_8015E674, fn_8015E778, fn_8015E80C, fn_8015EA24, fn_8015EB28).
struct ArrayTracker {
    void* mVtable;                        // 0x00 vtable of the group (lbl_8032EB0C variant)
    BonusTracker** mTrackers;             // 0x04 array; == &mInlineTrackers while it fits
    s32 mCount;                           // 0x08 trackers held
    s32 mCapacity;                        // 0x0C 16 slots
    BonusTracker* mInlineTrackers[0x10];  // 0x10 storage the array starts in
    void* mCounterSound;                  // 0x50 "cntsound" holder: the counter.sfx / fcount.sfx sounds
    u8 mActive;                           // 0x54 non-zero while the group takes part in scoring
    s32 mCourse;                          // 0x58 course index, the row of BONUS_TYPE_SCALE it resets
};

// Globals the bonus trackers share.
#define CFG_SCORE_SCALE  lbl_8032F39C  // .data: "score_scale", config key of the global score multiplier
#define BONUS_TYPE_SCALE lbl_8042FD08  // .bss: score multiplier per bonus category, indexed by tracker+0x4
#define BONUS_EPSILON    lbl_80558DC4  // .sdata: 2^-23; |value| <= this means nothing was scored
#define BONUS_TEXT_FMT   lbl_8055A058  // .sdata: "%s", format of the popup's print* setters
#define BONUS_TEXT2_FMT  lbl_8055A05C  // .sdata: "%s %d", the same line with a second value after it
#define BONUS_QUEUED_STEP 0x168        // 360, taken per event queued since the last frame
                                       // (tracker+0x26C) and shown after count/extra

#pragma push
#pragma processor 750
extern "C" void fn_8015B9B0(Unk801577F0* arg0, f32* arg1) {
    // Scores one bonus value for this tracker's category: scale it by the
    // "score_scale" config value and by this category's multiplier, show it on
    // the bonus popup while one is up, add it to the record being filled and
    // tell the bonus listeners.  fn_8015C820 is the same scoring pass for
    // another category; this one refreshes the popup's count only once.
    char text[16];
    f32 scale = fn_80204CFC(CFG_SCORE_SCALE);
    BonusTracker* tracker = (BonusTracker*)arg0;
    *arg1 *= scale;
    *arg1 *= BONUS_TYPE_SCALE[arg0->m4];
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0])) {
        // the popup shows "<score>" (fn_8023139C writes the digits with thousands
        // separators), the category as a progress bar, the raw score, the count
        // and the extra value, all through the "%s" format.
        (*(BonusDisplay**)((u8*)arg0+0x248))->printScore((s32)BONUS_TEXT_FMT, fn_8023139C(text,16,(u32)*arg1));
        (*(BonusDisplay**)((u8*)arg0+0x248))->setProgress(tracker->GetType());
        (*(BonusDisplay**)((u8*)arg0+0x248))->setScore((s32)*arg1);
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
        (*(BonusDisplay**)((u8*)arg0+0x248))->printExtra((s32)BONUS_TEXT_FMT,tracker->getExtra());
        tracker->refresh();
        (*(BonusDisplay**)((u8*)arg0+0x248))->update();
        s32 recordCount=tracker->getRecordCount();
        if(tracker->getIndex()>=recordCount) (*(BonusDisplay**)((u8*)arg0+0x248))->setState(1);
    }
    f32 value=*arg1;
    s32 offset=tracker->getIndex()*0x38;
    ++*(s32*)(arg0->mData+offset);                                  // record.count
    if (!((f32)__fabs(value)<=BONUS_EPSILON[0])) {
        ++*(s32*)(arg0->mData+offset+4);                            // record.scoredCount
        if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=BONUS_EPSILON[0])
            ++*(s32*)(arg0->mData+offset+8);                        // record.sameCount
    }
    *(f32*)(arg0->mData+offset+12)+=value;                          // record.total
    s32 index=tracker->getIndex();
    ((void(*)(s32,s32,s32))fn_801584D4)(tracker->GetType(),arg0->m4,index);  // (category, type, record) to each listener
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0]))
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
}
#pragma pop
extern "C" s32 fn_8015BCEC(void) { return 7; }

extern "C" s32 lbl_8055A05C[];
extern "C" s32 lbl_8055A05C[1];
#pragma push
#pragma processor 750
extern "C" void fn_8015BCF4(Unk801577F0* arg0, f32* arg1) {
    // Scores one bonus value for this tracker's category: scale it by the
    // "score_scale" config value and by this category's multiplier, show it on
    // the bonus popup while one is up, add it to the record being filled and
    // tell the bonus listeners.  fn_8015B9B0 and fn_8015C820 are the same
    // scoring pass; this one ends by re-showing count and extra through the
    // "%s %d" format, with 0x168 per event queued since the last frame after
    // them.
    char text[16];
    f32 scale = fn_80204CFC(CFG_SCORE_SCALE);
    BonusTracker* tracker = (BonusTracker*)arg0;
    f32 value;
    *arg1 *= scale;
    *arg1 *= BONUS_TYPE_SCALE[arg0->m4];
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0])) {
        // the popup shows "<score>" (fn_8023139C writes the digits with thousands
        // separators), the category as a progress bar, the raw score, the count
        // and the extra value, all through the "%s" format.
        (*(BonusDisplay**)((u8*)arg0+0x248))->printScore((s32)BONUS_TEXT_FMT, fn_8023139C(text,16,(u32)*arg1));
        (*(BonusDisplay**)((u8*)arg0+0x248))->setProgress(tracker->GetType());
        (*(BonusDisplay**)((u8*)arg0+0x248))->setScore((s32)*arg1);
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
        (*(BonusDisplay**)((u8*)arg0+0x248))->printExtra((s32)BONUS_TEXT_FMT,tracker->getExtra());
        tracker->refresh();
        (*(BonusDisplay**)((u8*)arg0+0x248))->update();
        s32 recordCount=tracker->getRecordCount();
        if(tracker->getIndex()>=recordCount) (*(BonusDisplay**)((u8*)arg0+0x248))->setState(1);
    }
    value=*arg1;
    s32 offset=tracker->getIndex()*0x38;
    ++*(s32*)(arg0->mData+offset);                                  // record.count
    if (!((f32)__fabs(value)<=BONUS_EPSILON[0])) {
        ++*(s32*)(arg0->mData+offset+4);                            // record.scoredCount
        if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=BONUS_EPSILON[0])
            ++*(s32*)(arg0->mData+offset+8);                        // record.sameCount
    }
    *(f32*)(arg0->mData+offset+12)+=value;                          // record.total
    s32 index=tracker->getIndex();
    ((void(*)(s32,s32,s32))fn_801584D4)(tracker->GetType(),arg0->m4,index);  // (category, type, record) to each listener
    s32 queued=*(s32*)((u8*)arg0+0x26c)*BONUS_QUEUED_STEP;          // events queued since the last frame
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0])) {
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT2_FMT,tracker->getCount(),queued);
        (*(BonusDisplay**)((u8*)arg0+0x248))->printExtra((s32)BONUS_TEXT2_FMT,tracker->getExtra(),queued);
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

#pragma scheduling on
/* Reset all entry records in this object's data buffer and clear its playback/aggregate state. */
extern "C" void fn_8015C0E8(Unk801577F0* arg0) {
    f32 entryValue = 0.0f;
    s32 entryIndex = 0;
    s32 entryOffset = 0;
    s32 zeroWord = 0;
    for (; entryIndex < arg0->mCount; entryIndex++) {
        *(s32*)(arg0->mData + entryOffset) = zeroWord;
        *(s32*)(arg0->mData + entryOffset + 4) = zeroWord;
        *(s32*)(arg0->mData + entryOffset + 8) = zeroWord;
        *(f32*)(arg0->mData + entryOffset + 0xC) = entryValue;
        entryOffset += 0x38;
    }
    f32 resetValue = 0.0f;
    entryValue = 1.0f;
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = resetValue;
    arg0->m25c = entryValue;
    arg0->v31();
    f32 tail = 0.0f;
    arg0->m26c = 0;
    *(s32*)((u8*)arg0 + 0x274) = 0;
    arg0->m278 = tail;
    arg0->m27c = tail;
}
extern "C" void fn_8015C1B0(Unk801577F0* arg0) {
    // Note: v31 selects slot 0x84; direct field stores retain the target's float literals.
    s32 active = arg0->m260;
    s32 zero = 0;
    arg0->m264 = zero;
    if (active > 0) {
        void* resource = *(void**)((u8*)arg0 + 0x258);
        if (resource != 0) {
            fn_801CB6E4(resource, *(s32*)((u8*)arg0 + 4));
        }
        arg0->m260 = 0;
        arg0->m254 = lbl_80561754;
        arg0->m25c = lbl_80561750;
        arg0->v31();
    }
    s32 pending = *(s32*)((u8*)arg0 + 0x26c);
    if (pending > 0) {
        fn_801CB6E4((void*)0x48203, *(s32*)((u8*)arg0 + 4));
        *(s32*)((u8*)arg0 + 0x26c) = 0;
    }
    f32 tail = lbl_80561754;
    *(s32*)((u8*)arg0 + 0x274) = zero;
    *(f32*)((u8*)arg0 + 0x278) = tail;
    *(f32*)((u8*)arg0 + 0x27c) = tail;
}

#pragma push
#pragma processor 750
extern "C" f32 fn_8015C264(void *arg0, void *arg1) {
    f32 actual = *(f32*)((char*)arg0 + 0x278);
    f32 var_f31 = lbl_80561754;
    s32 var_r28 = 0;
    s32 temp_r0;
    s32 temp_r0_2;
    struct V13 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(void*); };
    if (!((f32)__fabs(actual)<=lbl_80558DC4[0])) {
        f32 lim = lbl_80561754;
        s32 v4 = *(s32*)((char*)arg0 + 0x26c);
        s32 v274 = *(s32*)((char*)arg0 + 0x274);
        *(s32*)((char*)arg0 + 0x26c) = v4 + v274;
        f32 f0 = (actual < lim) ? actual - lbl_80561760 : lbl_80561760 + actual;
        if ((s32)f0 > 0) {
            s32 var_r4;
            if (*(s32*)((char*)arg0 + 0x274) != 0) {
                var_r4 = 0;
            } else {
                f32 t1 = *(f32*)((char*)arg0 + 0x278);
                f32 f0_2 = (t1 < lbl_80561754) ? t1 - lbl_80561760 : lbl_80561760 + t1;
                var_r4 = (s32)f0_2;
            }
            temp_r0 = *(s32*)((char*)arg0 + 0x26c) + var_r4;
            f32 f50;
            f32 f250;
            f250 = *(f32*)((char*)arg0 + 0x250);
            f50 = lbl_80561750;
            *(s32*)((char*)arg0 + 0x264) = temp_r0;
            *(s32*)((char*)arg0 + 0x260) = temp_r0;
            *(f32*)((char*)arg0 + 0x254) = f250;
            *(f32*)((char*)arg0 + 0x25c) = f50;
            ((Fn8015889C*)arg0)->v32();
            if (*(s32*)((char*)arg0 + 0x248) != 0) {
                void* q = *(void**)((char*)arg0 + 0x268);
                if (q != 0) {
                    *(s32*)((char*)q + 8) = 0;
                }
            }
        }
    }
    *(f32*)((char*)arg0 + 0x254) = fn_801429D0(lbl_80561754, *(f32*)((char*)arg0 + 0x254) - lbl_8056177C);
    if ((fn_8015A404(arg1) == 0) && (((Fn8015889C*)arg0)->v37() == 0)) {
        *(f32*)((char*)arg0 + 0x254) = fn_801429D0(*(f32*)((char*)arg0 + 0x254), lbl_8056179C);
    }
    var_f31 = lbl_80561754;
    var_r28 = 0;
    if (((Fn8015889C*)arg0)->v39() != 0) {
        temp_r0 = fn_80158D04(arg0) - 1;
        if (temp_r0 == ((Fn8015889C*)arg0)->v23()) {
            var_r28 = 1;
        }
    }
    if ((fn_80141F7C(*(f32*)((char*)arg0 + 0x254)) != 0) || (var_r28 != 0)) {
        if (*(s32*)((char*)arg0 + 0x264) > 0) {
            var_f31 = ((f32 (*)(void*, void*))fn_8015A368)(arg0, arg1);
        }
        if (var_r28 == 0) {
            fn_8015A318((Unk8015A368C*)arg0);
        }
    } else if (*(s32*)((char*)arg0 + 0x264) > 0) {
        ((Fn8015889C*)arg0)->v34();
    }
    if (*(s32*)((char*)arg0 + 0x274) > 0) {
        ((V13*)arg0)->v13(arg1);
    }
    if ((*(s32*)((char*)arg0 + 0x274) > 0) || ((temp_r0_2 = *(s32*)((char*)arg1 + 0x2620), temp_r0_2 > 0)!=0)) {
        f32 newt = *(f32*)((char*)arg0 + 0x27c) + fn_801E7E24();
        *(f32*)((char*)arg0 + 0x27c) = newt;
        if ((*(s32*)((char*)arg0 + 0x274) > 0) || (newt > lbl_805617C4)) {
            if (*(s32*)((char*)arg0 + 0x26c) > 0) {
                fn_801CB6E4((void*)0x48203, *(s32*)((char*)arg0 + 4));
                *(s32*)((char*)arg0 + 0x26c) = 0;
            }
            *(f32*)((char*)arg0 + 0x278) = lbl_80561754;
        }
    } else if (temp_r0_2 == 0) {
        *(f32*)((char*)arg0 + 0x27c) = lbl_80561754;
    }
    *(s32*)((char*)arg0 + 0x274) = 0;
    return var_f31;
}
#pragma pop

#pragma scheduling on
extern f32 lbl_80561760;
extern "C" void fn_8015C564(void* arg0, void* arg1, s32 arg2, f32 arg3) {
    if (*(s32*)((u8*)arg0 + 0x270) == *(s32*)((u8*)arg1 + 0x1ec)) {
        if (arg2 == 7 || arg2 == 9) {
            *(f32*)((u8*)arg0 + 0x278) = arg3;
            if (arg2 == 7) {
                f64 d = arg3;
                f32 value = (f32)d;
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

#pragma scheduling on
extern "C" void fn_8015C5E4(void* arg0) {
    f32 offset = (*(f32*)((u8*)arg0 + 0x278) < lbl_80561754) ?
        *(f32*)((u8*)arg0 + 0x278) - lbl_80561760 :
        lbl_80561760 + *(f32*)((u8*)arg0 + 0x278);
    s32 count;
    *(s32*)((u8*)arg0 + 0x26c) = (s32)offset;
    ((Unk801577F0*)arg0)->v13();
    count = *(s32*)((u8*)arg0 + 0x26c);
    if (count > 0) {
        if (count > 0) {
            ((void (*)(void*, s32, s32))fn_801CB6E4)((void*)0x48203, *(s32*)((u8*)arg0 + 4), count);
        }
        *(s32*)((u8*)arg0 + 0x26c) = 0;
        *(f32*)((u8*)arg0 + 0x278) = lbl_80561754;
    }
}
extern "C" s32 fn_8015C684(void) {
    return 4;
}

extern "C" s32 fn_8015C68C(void) { return 0xD; }

#pragma cplusplus on
extern "C" void fn_8015C694(void *objPtr) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual int v17(); virtual void v18(); virtual int v19();
        virtual void v20(); virtual int v21(); virtual void v22(); virtual int v23();
        virtual int v24(); virtual int v25(); virtual int v26(); virtual void v27();
        virtual void v28(); virtual int v29(); virtual void v30(); virtual int v31();
    };
    struct Adaptor {
        virtual void v0(); virtual void v1(int, ...); virtual void v2(int, ...);
        virtual void v3(int, ...); virtual void v4(); virtual void v5(int);
        virtual void v6(int); virtual void v7(); virtual void v8(int); virtual void v9();
    };
    Obj *obj = (Obj *)objPtr;
    int limit, current;
    /* Updates the attached adaptor at +0x248 with the object's current state/limits when present. */
    if (*(void **)((char *)objPtr + 0x248) != 0) {
        (*(Adaptor **)((char *)objPtr + 0x248))->v2((int)&lbl_8055A058[0], obj->v23());
        (*(Adaptor **)((char *)objPtr + 0x248))->v6(obj->v29());
        obj->v22();
        (*(Adaptor **)((char *)objPtr + 0x248))->v4();
        limit = obj->v17();
        current = obj->v21();
        if (current >= limit) (*(Adaptor **)((char *)objPtr + 0x248))->v8(1);
    }
    if (*(void **)((char *)objPtr + 0x248) != 0)
        (*(Adaptor **)((char *)objPtr + 0x248))->v2((int)&lbl_8055A058[0], obj->v23());
    if (*(void **)((char *)objPtr + 0x248) != 0)
        (*(Adaptor **)((char *)objPtr + 0x248))->v2((int)&lbl_8055A058[0], obj->v23());
}
#pragma cplusplus reset

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8015C820(Unk801577F0* arg0, f32* arg1) {
    // Scores one bonus value: scale it by the "score_scale" config value and by
    // this category's multiplier, show the result on the bonus popup when one is
    // up, add it to the current record and tell the bonus listeners about it.
    char text[16];
    f32 scale = fn_80204CFC(CFG_SCORE_SCALE);
    BonusTracker* tracker = (BonusTracker*)arg0;
    *arg1 *= scale;
    *arg1 *= BONUS_TYPE_SCALE[arg0->m4];
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0])) {
        (*(BonusDisplay**)((u8*)arg0+0x248))->printScore((s32)BONUS_TEXT_FMT, fn_8023139C(text,16,(u32)*arg1));
        (*(BonusDisplay**)((u8*)arg0+0x248))->setProgress(tracker->GetType());
        (*(BonusDisplay**)((u8*)arg0+0x248))->setScore((s32)*arg1);
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
        (*(BonusDisplay**)((u8*)arg0+0x248))->printExtra((s32)BONUS_TEXT_FMT,tracker->getExtra());
        tracker->refresh();
        (*(BonusDisplay**)((u8*)arg0+0x248))->update();
        s32 recordCount=tracker->getRecordCount();
        if(tracker->getIndex()>=recordCount) (*(BonusDisplay**)((u8*)arg0+0x248))->setState(1);
    }
    f32 value=*arg1;
    s32 offset=tracker->getIndex()*0x38;
    ++*(s32*)(arg0->mData+offset);                                  // record.count
    if (!((f32)__fabs(value)<=BONUS_EPSILON[0])) {
        ++*(s32*)(arg0->mData+offset+4);                            // record.scoredCount
        if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=BONUS_EPSILON[0])
            ++*(s32*)(arg0->mData+offset+8);                        // record.sameCount
    }
    *(f32*)(arg0->mData+offset+12)+=value;                          // record.total
    s32 index=tracker->getIndex();
    ((void(*)(s32,s32,s32))fn_801584D4)(tracker->GetType(),arg0->m4,index);
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0]))
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0]))
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
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

#pragma push
#pragma processor 750
extern "C" s32 fn_8015CC30(void* arg0) {
    register f32 x = *(f32*)((char*)arg0 + 0x250);
    register f32 r;
    if (x < lbl_80561754) r = x - lbl_80561760;
    else r = lbl_80561760 + x;
    return (s32)r;
}
#pragma pop
extern "C" void fn_8015CC6C(void* arg0, f32 farg0) {
    *(f32*)((char*)arg0 + 0x250) = farg0;
}

extern "C" void fn_8015CC74(Unk801577F0* arg0) {
    f32 zero;
    register s32 i;
    register s32 offset;
    register s32 value;
    zero = lbl_80561754;
    i = 0;
    offset = 0;
    value = 0;
    for (; i < arg0->mCount; i++) {
        *(s32*)(arg0->mData + offset) = value;
        *(s32*)(arg0->mData + offset + 4) = value;
        *(s32*)(arg0->mData + offset + 8) = value;
        *(f32*)(arg0->mData + offset + 0xC) = zero;
        offset += 0x38;
    }
    arg0->v31();
    *(f32*)((u8*)arg0 + 0x250) = lbl_805617C8;
}

extern "C" void fn_8015CD0C(void) {

}

extern "C" f32 lbl_805617C8;
#pragma scheduling on
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

#pragma scheduling invalid_target
extern "C" void fn_8015CDDC(Unk801577F0 *arg0, void *arg1, s32 arg2, f32 farg0) {
    if (*(s32 *)((u8 *)arg0 + 0x24C) == *(s32 *)((u8 *)arg1 + 0x1EC) && arg2 == arg0->v35()) {
        arg0->m250 = farg0;
    }
}
#pragma scheduling on
extern "C" s32 fn_8015CE48(void) {
    return 0xE;
}

extern "C" s32 fn_80009C84(void);
extern "C" void fn_80206750(void*, s32, s32);
extern "C" void fn_8015CF00(Unk801577F0* arg0) {
    f32 entryValue = 0.0f;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 r5 = 0;
    for (; r6 < arg0->mCount; r6++) {
        *(s32*)(arg0->mData + r7) = r5;
        *(s32*)(arg0->mData + r7 + 4) = r5;
        *(s32*)(arg0->mData + r7 + 8) = r5;
        *(f32*)(arg0->mData + r7 + 0xC) = entryValue;
        r7 += 0x38;
    }
    f32 resetValue = 0.0f;
    entryValue = 1.0f;
    arg0->m264 = 0;
    arg0->m260 = 0;
    arg0->m254 = resetValue;
    arg0->m25c = entryValue;
    arg0->v31();
    void* target = *(void**)((u8*)arg0 + 0x278);
    arg0->m26c = 0;
    *(s32*)((u8*)arg0 + 0x270) = 0;
    if (target != 0) {
        *(u8*)((u8*)target + 0x4A) = 1;
        *(u8*)((u8*)target + 0x4C) = 0;
        s32 mode = 2;
        if (fn_80009C84() != 0)
            mode = 0;
        if (*(void**)((u8*)arg0 + 0x278) != 0)
            fn_80206750(*(void**)((u8*)arg0 + 0x278), *(s32*)((u8*)arg0 + 0x274), mode);
    }
}

// The dash bonus tracker.  Like the other bonus trackers it owns a table of
// mCount records of 0x38 bytes at +8 (see BonusRecord) and scores one of them
// per event, but it also drives the "SoundDash" sound fn_802076A0() makes and
// runs on a timer:
//
//   +0x248 BonusDisplay*  the bonus popup, while one is up
//   +0x250 f32            the bonus time one event buys
//   +0x254 f32            bonus time left; the bonus ends when it reaches zero
//   +0x258 void*          the record buffer the scoring fills (fn_8015A318 frees it)
//   +0x25C f32            multiplier of the event being scored
//   +0x260 s32            events scored since the last reset
//   +0x264 s32            events scored since the bonus started
//   +0x268 void*          bonus listener; its +8 is cleared with every event
//   +0x26C s32            events queued since the last frame
//   +0x270 s32            events the dash sound has been told about
//   +0x278 SoundDash*     the dash sound: +4 is the scale written for it (+0x4E
//                         marks it dirty), +0x19 is set while it is being kept
//                         going and +0x49/+0x4A/+0x4B are its stop requests
//
// Globals this tracker shares with the other bonus trackers.
#define DASH_SCALE       lbl_802F9478  // .rodata: {0.7932, 0.8904, 0.9433, 0.9994, 1.0},
                                       // the scale written to the dash sound, by the
                                       // number of events scored
#define DASH_SCALE_LAST  4             // last index of DASH_SCALE
#define BONUS_FULL       lbl_80561750  // .sdata2: 1.0f, the multiplier an event starts at
#define BONUS_NONE       lbl_80561754  // .sdata2: 0.0f
#define BONUS_FRAME      lbl_8056177C  // .sdata2: 1/59.94 s, taken off the timer per frame
#define BONUS_MIN_TIME   lbl_8056179C  // .sdata2: two frames, the least time left at rest

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" f32 fn_8015CFFC(void *tracker, void *truck) {
    // One frame of the dash bonus tracker: scores every event queued since the
    // last frame (each one restarts the bonus timer and sets the dash sound's
    // scale), counts this frame off the timer and returns the score banked when
    // the timer runs out or the tracker's last record is reached - 0.0f while
    // the bonus is still running.
    s32 lastRecord;
    s32 atLastRecord;
    u8 *p = (u8 *)tracker;
    s32 scaleSet = 0;
    f32 score;
    if (*(void **)(p + 0x278)) {
        s32 told = *(s32 *)(p + 0x270) + *(s32 *)(p + 0x26c);
        *(s32 *)(p + 0x270) = told;
        if (told > 0) {
            // the dash sound plays louder the more events this bonus scored
            s32 scored = *(s32 *)(p + 0x264);
            s32 positive = scored & ((-scored & ~scored) >> 31);  // max(scored, 0)
            s32 ix = (positive < DASH_SCALE_LAST) ? positive : DASH_SCALE_LAST;
            u8 *dash = (u8 *)*(void **)(p + 0x278);
            f32 scale = DASH_SCALE[ix];
            if (scale != *(f32 *)(dash + 4)) { dash[0x4e] = 1; *(f32 *)(dash + 4) = scale; }
            scaleSet = 1;
        }
    }
    score = BONUS_FULL;
    s32 i = 0;
    s32 zero = 0;
    while (i < *(s32 *)(p + 0x26c)) {          // one scoring pass per queued event
        ++*(s32 *)(p + 0x264);
        ++*(s32 *)(p + 0x260);
        *(f32 *)(p + 0x254) = *(f32 *)(p + 0x250);   // the event restarts the timer
        *(f32 *)(p + 0x25c) = score;                 // ... at the full multiplier
        ((BonusTracker *)tracker)->scoreEvent();
        if (*(s32 *)(p + 0x248) && *(void **)(p + 0x268))
            *(s32 *)(*(u8 **)(p + 0x268) + 8) = zero;  // the listener has nothing pending
        i++;
    }
    *(s32 *)(p + 0x26c) = 0;
    if (scaleSet && *((u8 *)*(void **)(p + 0x278) + 0x19) == 0) {
        // the sound is not playing: hand it back the event it was told about
        // and ask it to stop.
        (*(s32 *)(p + 0x270))--;
        u8 *dash = (u8 *)*(void **)(p + 0x278);
        dash[0x49] = 1; dash[0x4b] = 0; dash[0x4a] = 0;
    }
    *(f32 *)(p + 0x254) = fn_801429D0(BONUS_NONE, *(f32 *)(p + 0x254) - BONUS_FRAME);
    if (fn_8015A404(truck) == 0 && ((BonusTracker *)tracker)->mayTimeOut() == 0)
        *(f32 *)(p + 0x254) = fn_801429D0(*(f32 *)(p + 0x254), BONUS_MIN_TIME);
    score = BONUS_NONE;
    atLastRecord = 0;
    if (((BonusTracker *)tracker)->hasRecords()) {
        lastRecord = fn_80158D04(tracker) - 1;
        s32 current = ((BonusTracker *)tracker)->getIndex();
        if (current == lastRecord) atLastRecord = 1;
    }
    if (fn_80141F7C(*(f32 *)(p + 0x254)) || atLastRecord) {
        if (*(s32 *)(p + 0x264) > 0) score = ((f32 (*)(void *, void *))fn_8015A368)(tracker, truck);
        if (!atLastRecord) fn_8015A318((Unk8015A368C *)tracker);
    } else if (*(s32 *)(p + 0x264) > 0) ((BonusTracker *)tracker)->refreshDisplay();
    return score;
}
#pragma pop
/* If +0x264 is set, updates via fn_8015A368 with the adjusted param; then if the
   last entry's id is valid and state/mode checks pass, triggers event 6. */
extern "C" void fn_8015D270(void* self, void* param) {
    void* paramCopy = param;
    fn_80158F34(&paramCopy);
    if (*(s32*)((u8*)self + 0x264) > 0) {
        ((f32 (*)(void*, void*))fn_8015A368)(self, paramCopy);
    }
    void* entries = *(void**)((u8*)self + 8);
    void* lastEntry = (void*)((s32)entries + (*(s32*)((u8*)self + 0xC) - 1) * 0x38);
    s32 entryId = *(s32*)((u8*)lastEntry + 4);
    if (entryId > 0 && fn_80179650() == 1 && *(s32*)((u8*)param + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(6, entryId);
    }
}

extern "C" void fn_8015D318(Unk801577F0* arg0, f32 arg1, s32 unused, s32 arg2) {
    if (arg2 == 5) {
        f32 value;
        if (arg1 < lbl_80561754) value = arg1 - lbl_80561760;
        else value = lbl_80561760 + arg1;
        s32 conv = (s32)value;
        *(volatile s32*)&arg0->m26c += conv;
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
    int count = *(int*)((char*)arg0 + 0x260);
    *(int*)((char*)arg0 + 0x264) = 0;
    if (count > 0) {
        if (*(int*)((char*)arg0 + 0x258) != 0) fn_801CB6E4(*(void**)((char*)arg0 + 0x258), *(int*)((char*)arg0 + 4));
        *(int*)((char*)arg0 + 0x260) = 0;
        *(float*)((char*)arg0 + 0x254) = lbl_80561754;
        *(float*)((char*)arg0 + 0x25c) = lbl_80561750;
        arg0->v31();
    }
}

/* Finalize and apply the accumulated adjustment (m25c * v18(v21())) via v33/v31, clear the pending count, and reset m25c. */
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
    f32 adjustedValue;
    s32 index = arg0->v21();
    adjustedValue = arg0->m25c * arg0->v18(index);
    ((LocalVtable*)arg0)->v33(&adjustedValue);
    ((LocalVtable*)arg0)->v31();
    f32 resetValue = lbl_80561750;
    arg0->m264 = 0;
    arg0->m25c = resetValue;
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

#pragma push
#pragma peephole off
extern "C" s32 fn_8015D504(Unk801577F0* arg0, s32 arg1) {
    s32 count = arg0->mCount;
    s32 i;
    s32 offset;
    i = 0;
    offset = 0;
    for (; i < count; i++) {
        s32 value = *(s32*)((u8*)arg0->mData + offset + 0x14);
        if (arg1 < value) goto out;
        if (value >= 0) goto cont;
        else goto out;
    cont:
        offset += 0x38;
    }
    i = 0;
out:
    return i;
}
#pragma pop
extern "C" void fn_8015D554(void *arg0) {
    class Local {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18();
        virtual void v19(void *);
        virtual void *v20();
    };
    Local *obj = (Local *)arg0;
    void *value = obj->v20();
    obj->v19(value);
}

#pragma push
#pragma processor 750
/* Returns the current timeline index plus progress toward the next key (time at +0x14, stride 0x38). */
extern "C" f32 fn_8015D5A4(void *arg0) {
    struct V {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual int cur(); virtual int index();
    };
    int idx = ((V *)arg0)->index();
    int count = *(int *)((char *)arg0 + 0xC);
    f32 fraction = lbl_80561754;
    int previous;
    if (idx < count - 1) {
        if (idx > 0)
            previous = *(int *)(*(char **)((char *)arg0 + 8) + (idx - 1) * 0x38 + 0x14);
        else
            previous = 0;
        int now = ((V *)arg0)->cur();
        int current = *(int *)(*(char **)((char *)arg0 + 8) + idx * 0x38 + 0x14);
        f32 num = (f32)(now - previous);
        f32 den = (f32)(current - previous);
        if (den > lbl_80561754)
            fraction = num / den;
    }
    return (f32)idx + fraction;
}
#pragma pop
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
    s32 count = *(s32*)((unsigned char*)arg0 + 0xC);
    unsigned char* base;
    s32 i = 0;
    s32 offset = 0;
    for (; count > 0; count--) {
        base = *(unsigned char**)((unsigned char*)arg0 + 8);
        if (*(s32*)(base + offset + 0x14) >= 0)
            return *(s32*)(base + i * 0x38 + 0x14);
        offset += 0x38;
        i++;
    }
    return 0;
}

extern "C" s32 fn_8015D7CC(void* arg0) {
    s32 count = *(s32*)((u8*)arg0 + 0xC);
    while (count-- > 0) {
        Item38* base = *(Item38**)((u8*)arg0 + 8);
        if (base[count].val >= 0)
            return base[count].val;
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
extern "C" void fn_8015D8B0(void *arg0) {
    struct Obj {
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
        virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
        virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14();
        virtual void p15(); virtual void p16(); virtual s32 lower();
        virtual void p18(); virtual void p19(); virtual void p20(); virtual s32 upper();
        virtual void noop(); virtual s32 progress();
        virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28();
        virtual s32 type();
    };
    struct Adaptor {
        virtual void a0();
        virtual void a1();
        virtual void format(int, ...);
        virtual void a3();
        virtual void clear();
        virtual void a5();
        virtual void setProgress(s32);
        virtual void a7();
        virtual void setState(s32);
    };
    Obj *obj = (Obj *)arg0;
    s32 limit, current;
    /* Updates the attached UI adaptor with progress/type and marks complete when upper >= lower. */
    if (*(void **)((char *)arg0 + 0x248) != 0) {
        (*(Adaptor **)((char *)arg0 + 0x248))->format((int)&lbl_8055A058[0], obj->progress());
        (*(Adaptor **)((char *)arg0 + 0x248))->setProgress(obj->type());
        obj->noop();
        (*(Adaptor **)((char *)arg0 + 0x248))->clear();
        limit = obj->lower();
        current = obj->upper();
        if (current >= limit) {
            (*(Adaptor **)((char *)arg0 + 0x248))->setState(1);
        }
    }
}

extern "C" f32 fn_80204CFC(const char*);
extern "C" void* fn_8023139C(void*,s32,u32);
extern "C" char lbl_8032F39C[];
extern "C" f32 lbl_8042FD08[];
#pragma push
#pragma processor 750
extern "C" void fn_8015D9BC(Unk801577F0* arg0, f32* arg1) {
    // Scores one bonus value for this tracker's category: scale it by the
    // "score_scale" config value and by this category's multiplier, show it on
    // the bonus popup while one is up, add it to the record being filled and
    // tell the bonus listeners.  fn_8015B9B0 and fn_8015C820 are the same
    // scoring pass; this one never refreshes the popup's count afterwards.
    char text[16];
    f32 scale = fn_80204CFC(CFG_SCORE_SCALE);
    BonusTracker* tracker = (BonusTracker*)arg0;
    *arg1 *= scale;
    *arg1 *= BONUS_TYPE_SCALE[arg0->m4];
    if (*(BonusDisplay**)((u8*)arg0+0x248) && !((f32)__fabs(*arg1)<=BONUS_EPSILON[0])) {
        // the popup shows "<score>" (fn_8023139C writes the digits with thousands
        // separators), the category as a progress bar, the raw score, the count
        // and the extra value, all through the "%s" format.
        (*(BonusDisplay**)((u8*)arg0+0x248))->printScore((s32)BONUS_TEXT_FMT, fn_8023139C(text,16,(u32)*arg1));
        (*(BonusDisplay**)((u8*)arg0+0x248))->setProgress(tracker->GetType());
        (*(BonusDisplay**)((u8*)arg0+0x248))->setScore((s32)*arg1);
        (*(BonusDisplay**)((u8*)arg0+0x248))->printCount((s32)BONUS_TEXT_FMT,tracker->getCount());
        (*(BonusDisplay**)((u8*)arg0+0x248))->printExtra((s32)BONUS_TEXT_FMT,tracker->getExtra());
        tracker->refresh();
        (*(BonusDisplay**)((u8*)arg0+0x248))->update();
        s32 recordCount=tracker->getRecordCount();
        if(tracker->getIndex()>=recordCount) (*(BonusDisplay**)((u8*)arg0+0x248))->setState(1);
    }
    f32 value=*arg1;
    s32 offset=tracker->getIndex()*0x38;
    ++*(s32*)(arg0->mData+offset);                                  // record.count
    if (!((f32)__fabs(value)<=BONUS_EPSILON[0])) {
        ++*(s32*)(arg0->mData+offset+4);                            // record.scoredCount
        if ((f32)__fabs(value-*(f32*)(arg0->mData+offset+16))<=BONUS_EPSILON[0])
            ++*(s32*)(arg0->mData+offset+8);                        // record.sameCount
    }
    *(f32*)(arg0->mData+offset+12)+=value;                          // record.total
    s32 index=tracker->getIndex();
    ((void(*)(s32,s32,s32))fn_801584D4)(tracker->GetType(),arg0->m4,index);  // (category, type, record) to each listener
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
extern "C" void fn_8015DC98(Unk801577F0* arg0) {
    /* Debug-print a header (v23 name) and a table of items with per-item fields/times, then totals. */
    struct Dispatch { virtual const char *v0(); virtual const char *v1(); virtual const char *v2(); virtual const char *v3(); virtual const char *v4(); virtual const char *v5(); virtual const char *v6(); virtual const char *v7(); virtual const char *v8(); virtual const char *v9(); virtual const char *v10(); virtual const char *v11(); virtual const char *v12(); virtual const char *v13(); virtual const char *v14(); virtual const char *v15(); virtual const char *v16(); virtual const char *v17(); virtual const char *v18(); virtual const char *v19(); virtual const char *v20(); virtual const char *v21(); virtual const char *v22(); virtual const char *v23(); };
    struct Item { s32 a; s32 b; s32 c; f32 value; u8 pad[0x28]; };
    const char *base = lbl_8032E4E0;

    fn_802E30C8((const char *)&lbl_8055A064, ((Dispatch *)arg0)->v23());
    fn_802E30C8(base + 0xEC8);
    fn_802E30C8(base + 0xEFC);

    f32 totalTime = lbl_80561754;
    s32 count;
    s32 sumB;
    s32 sumA;
    Item *itemPtr;
    s32 offset;
    sumA = 0;
    sumB = 0;
    count = 0;
    offset = 0;
    while (count < arg0->mCount) {
        itemPtr = (Item *)((u8 *)arg0->mData + offset);
        fn_802E30C8(base + 0xF30, count, ((s32 *)itemPtr) + 6, itemPtr->a,
                    itemPtr->a - itemPtr->b, itemPtr->c, itemPtr->value);
        offset += 0x38;
        count += 1;
        totalTime += itemPtr->value;
        sumA += itemPtr->a;
        sumB += itemPtr->b;
    }
    fn_802E30C8(base + 0xF60, sumA, sumA - sumB, totalTime);
}
#pragma pop
extern "C" s32 lbl_8055A06C[1];
static inline f32 fn8015DD9CSumFloat(Unk801577F0* arg0) {
 f32 total=lbl_80561754;
 for(s32 i=0;i<arg0->mCount;i++) total+=*(f32*)(arg0->mData+i*0x38+12);
 return total;
}
static inline s32 fn8015DD9CSumInt(Unk801577F0* arg0) {
 s32 i=0;
 s32 sum=0;
 for(;i<arg0->mCount;i++) sum+=*(s32*)(arg0->mData+i*0x38+4);
 return sum;
}
#pragma processor 750
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
 s32 sum=fn8015DD9CSumInt(arg0);
 Adaptor* a=((Provider*)arg1)->v1();
 Obj* obj=(Obj*)arg0;
 if(a) {
 a->v1((s32)lbl_8055A058,obj->v25());
 a->v2((s32)lbl_8055A06C,sum);
 a->v6(obj->v29());
 s32 value=(s32)fn8015DD9CSumFloat(arg0);
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
extern "C" void fn_8015E0FC(void) {
}

extern "C" s32 fn_8015E100(void) {
    return 0;
}

extern "C" s32 fn_8015E108(void) {
    return 0;
}

extern "C" void *fn_8015E110(void *arg0, s32 arg1) {
    /* Destructor: destroy items in the owned list, destroy/free subobject at +0x50, clear fields, optionally free self. */
    struct Item { virtual void destroy(s32); };
    extern char lbl_8032EB0C[];
    void *obj = arg0;
    Item *offset;
    s32 count;
    if (obj != 0) {
        *(void **)obj = lbl_8032EB0C;
        count = 0;
        offset = (Item *)0;
        goto loop_test;
loop_body:
        {
            Item **list = *(Item ***)((char *)obj + 4);
            Item *item = *(Item **)((char *)list + (u32)offset);
            if (item != 0) item->destroy(1);
        }
        offset = (Item *)((u8 *)offset + 4);
        count += 1;
loop_test:
        if (count < *(s32 *)((char *)obj + 8)) goto loop_body;
        offset = *(Item **)((char *)obj + 0x50);
        if (offset != 0) {
            Item *second = *(Item **)((char *)offset + 4);
            if (second != 0) { if (second != 0) second->destroy(1); }
            {
                Item *first = *(Item **)offset;
                if (first != 0) { if (first != 0) first->destroy(1); }
            }
            fn_80128668(offset);
        }
        if ((u32)obj + 4 != 0) {
            if ((u32)obj + 4 != 0) {
                *(u32 *)((char *)obj + 4) = 0;
                *(u32 *)((char *)obj + 8) = 0;
                *(u32 *)((char *)obj + 0xC) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(obj);
    }
    return obj;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_8015E238(Unk801577F0V* arg0) {
    struct Dummy {
        virtual void v0();
        virtual void Call();
    };
    s32 offset = 0;
    s32 i = 0;
    u8* self = (u8*)arg0;
    s32 valueIndex = *(s32*)(self + 0x58);
    *(u8*)(self + 0x54) = 1;
    lbl_8042FD08[valueIndex] = lbl_80561750;
    while (i < *(s32*)(self + 8)) {
        void* item = *(void**)((u8*)*(void**)(self + 4) + offset);
        ((Dummy*)item)->Call();
        offset += 4;
        i++;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset
extern "C" void fn_8015E2C8(void *arg0) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
    };
    int i;
    for (i = 0; i < *(int *)((char *)arg0 + 0x8); i++) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)arg0 + 0x4) + i * 0x4);
        entry->v2();
    }
}

extern "C" s32 fn_801B2F2C(s32);
extern "C" s32 fn_801B8570(s32);
extern "C" s32 fn_80161BB8(void);
extern "C" s32 fn_80161C4C(void);
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
extern "C" f32 fn_8015E338(void* arg0, void* arg1) {
    f32 sum = lbl_80561754;
    s32 off = 0;
    s32 i = 0;
    if (*(u8*)((u8*)arg0 + 0x54) != 0 && fn_801B2F2C(*(s32*)((u8*)arg1 + 0x1EC)) == 0 && fn_801B8570(*(s32*)((u8*)arg1 + 0x1EC)) != 0 && fn_80161BB8() == 0 && fn_80161C4C() != 0) {
        for (i = 0, off = 0; i < *(s32*)((u8*)arg0 + 8); off += 4, i++) {
            if ((f32)__fabs((f64)*(f32*)((u8*)arg1 + 0x2690)) <= lbl_80558DC4[0] ||
                (*(Item8015E338**)(*(s32*)((u8*)arg0 + 4) + off))->v34() != 0) {
                Item8015E338* it2 = *(Item8015E338**)(*(s32*)((u8*)arg0 + 4) + off);
                sum += it2->v3(arg1);
            }
        }
    }
    void* p = *(void**)((u8*)arg0 + 0x50);
    void* q = *(void**)p;
    if (q != 0) {
        if (*(s32*)((u8*)p + 8) == 0) {
            *(u8*)((u8*)q + 0x4A) = 0;
            *(u8*)((u8*)q + 0x4B) = 1;
            *(u8*)((u8*)q + 0x49) = 1;
        } else {
            void* r = *(void**)((u8*)p + 4);
            if (r != 0 && *(s32*)((u8*)p + 0xC) == 0) {
                *(u8*)((u8*)r + 0x49) = 1;
                *(u8*)((u8*)r + 0x4B) = 0;
                *(u8*)((u8*)r + 0x4A) = 0;
            }
            q = *(void**)p;
            *(u8*)((u8*)q + 0x4A) = 1;
            *(u8*)((u8*)q + 0x4C) = 0;
        }
    }
    *(s32*)((u8*)p + 0xC) = *(s32*)((u8*)p + 8);
    *(s32*)((u8*)p + 8) = 1;
    return sum;
}
#pragma pop
extern "C" void fn_8015E4C4(Unk801577F0V* arg0, s8 arg1) {
    arg0->m54 = arg1;
}

extern "C" void fn_8015E4CC(Unk801577F0V* container, s32 param, f32 value) {
    /* Dispatches a (s32, f32) virtual call to each child entry when this container is active. */
    // Note: six leading virtual entries place Call at the target's 0x20 slot.
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void Call(s32, f32);
    };
    if (container->m54 != 0) {
        s32 byteOffset;
        s32 index;
        index = 0;
        byteOffset = 0;
        while (index < *(s32*)((u8*)container + 8)) {
            void* entry = *(void**)((u8*)*(void**)((u8*)container + 4) + byteOffset);
            ((Entry*)entry)->Call(param, value);
            byteOffset += 4;
            index++;
        }
    }
}

#pragma use_lmw_stmw off
/* Dispatch a three-argument event to each child entry in this container when it is active. */
extern "C" void fn_8015E568(Unk801577F0V* container, s32 arg1, s32 arg2, s32 arg3) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void Call(s32, s32, s32);
    };
    if (container->m54 != 0) {
        s32 offset;
        s32 i;
        i = 0;
        offset = 0;
        while (i < *(s32*)((u8*)container + 8)) {
            void* item = *(void**)((u8*)*(void**)((u8*)container + 4) + offset);
            ((Dummy*)item)->Call(arg1, arg2, arg3);
            offset += 4;
            i++;
        }
    }
}
#pragma use_lmw_stmw reset
/* Hands the value to every bonus tracker this group owns: virtual slot 0x3C of the
 * "arraytracker" group forwards it to slot 0x3C of each tracker in its array (the
 * air tracker flushes the progress it built up there; most trackers ignore it). */
extern "C" void fn_8015E5F4(ArrayTracker* group, s32 value) {
    s32 off = 0;
    s32 i = 0;
    while (i < group->mCount) {
        BonusTracker* tracker = *(BonusTracker**)((u8*)group->mTrackers + off);
        tracker->v13(value);
        off += 4;
        i += 1;
    }
}
extern "C" void fn_8015E674(void *arg0, int arg1) {
 struct A { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void call(int); };
 int i = 0; int off = 0; void **arr; void *st; void *ob2;
 goto check;
loop:
 arr=*(void ***)((char *)arg0+4);
 ((A *)arr[off/4])->call(arg1);
 off+=4; i++;
check:
 if(i<*(int *)((char *)arg0+8)) goto loop;
 st=*(void **)((char *)arg0+0x50); ob2=*(void **)st;
 if(!ob2) goto done;
 if(*(int *)((char *)st+8)==0) {
  *(char *)((char *)ob2+0x4a)=0; *(char *)((char *)ob2+0x4b)=1; *(char *)((char *)ob2+0x49)=1;
 } else {
  ob2=*(void **)((char *)st+4);
  if(ob2 && *(int *)((char *)st+0xc)==0) {
   *(char *)((char *)ob2+0x49)=1; *(char *)((char *)ob2+0x4b)=0; *(char *)((char *)ob2+0x4a)=0;
  }
  ob2=*(void **)st; *(char *)((char *)ob2+0x4a)=1; *(char *)((char *)ob2+0x4c)=0;
 }
 *(int *)((char *)st+0xc)=*(int *)((char *)st+8);
 *(int *)((char *)st+8)=1;
done:;
}

#pragma use_lmw_stmw off
/* Broadcast a 3-argument (s32, s32, f32) call to each active child entry when this container is enabled. */
extern "C" void fn_8015E778(Unk801577F0V* container, s32 param1, s32 param2, f32 param3) {
    // Note: use_lmw_stmw off selects the target's save helpers; this interface selects slot 0x2c.
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void Call(s32, s32, f32);
    };
    if (container->m54 != 0) {
        s32 byteOffset;
        s32 index;
        index = 0;
        byteOffset = 0;
        while (index < *(s32*)((u8*)container + 8)) {
            void* child = *(void**)((u8*)*(void**)((u8*)container + 4) + byteOffset);
            ((Entry*)child)->Call(param1, param2, param3);
            byteOffset += 4;
            index++;
        }
    }
}
#pragma use_lmw_stmw reset
/* Hands the value to every bonus tracker this group owns: virtual slot 0x30 of the
 * "arraytracker" group forwards it to slot 0x30 of each tracker in its array (the
 * trackers seen here implement that slot as the empty fn_8015E0FC). */
extern "C" void fn_8015E80C(ArrayTracker* group, s32 value) {
    s32 off = 0;
    s32 i = 0;
    while (i < group->mCount) {
        BonusTracker* tracker = *(BonusTracker**)((u8*)group->mTrackers + off);
        tracker->v10(value);
        off += 4;
        i += 1;
    }
}

#pragma scheduling invalid_target
extern "C" s32 fn_8015E88C(void *container) {
    /* Return 1 if any entry in the container reports true via vtable slot 0x44. */
    struct Entry {
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
        virtual s32 v15();
    };
    s32 offset = 0;
    s32 index = 0;
    while (index < *(s32 *)((char *)container + 8)) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)container + 4) + offset);
        if (entry->v15() != 0) {
            return 1;
        }
        offset += 4;
        index += 1;
    }
    return 0;
}
#pragma scheduling on

#pragma scheduling on
extern "C" s32 fn_8015E910(void *arg0, s32 arg1) {
    /* Return 1 if any object in the container's array handles arg1 via slot v14 (vtable +0x40). */
    // Note: v14 selects the target's virtual slot at vtable offset 0x40.
    struct Entry {
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
        virtual s32 v14(s32);
    };
    s32 byteOffset = 0;
    s32 index = 0;

    while (index < *(s32 *)((char *)arg0 + 8)) {
        Entry *obj = *(Entry **)((char *)*(void **)((char *)arg0 + 4) + byteOffset);
        if (obj->v14(arg1) != 0) {
            return 1;
        }
        byteOffset += 4;
        index += 1;
    }
    return 0;
}

#pragma scheduling invalid_target
/* Hands the bonus display to every tracker this group owns: virtual slot 0x48 of
 * the "arraytracker" group calls slot 0x48 of each tracker in its array, which
 * writes that tracker's line into the popup the display hands out (fn_8015DD9C). */
extern "C" void fn_8015E9A4(ArrayTracker* group, void* display) {
    s32 off = 0;
    s32 i = 0;
    while (i < group->mCount) {
        BonusTracker* tracker = *(BonusTracker**)((u8*)group->mTrackers + off);
        tracker->drawToDisplay(display);
        off += 4;
        i += 1;
    }
}
extern "C" void fn_8015EA24(void *container, s32 arg) {
    s32 offset = 0;
    s32 index = 0;
    /* Dispatch virtual slot v6 to each entry in the container's array (+4 array ptr, +8 count). */
    while (index < *(s32 *)((char *)container + 8)) {
        Unk8015EA24V *entry = *(Unk8015EA24V **)((char *)*(void **)((char *)container + 4) + offset);
        entry->v6(arg);
        offset += 4;
        index += 1;
    }
}

#pragma scheduling invalid_target
extern "C" s32 fn_8015EAA4(void *container) {
    /* Return 1 if any entry in the container reports true via vtable slot 0x38. */
    struct Entry {
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
        virtual s32 v12();
    };
    s32 offset = 0;
    s32 index = 0;
    while (index < *(s32 *)((char *)container + 8)) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)container + 4) + offset);
        if (entry->v12() != 0) {
            return 1;
        }
        offset += 4;
        index += 1;
    }
    return 0;
}
#pragma scheduling on

#pragma scheduling on
extern "C" void fn_8015EB28(void *arg0) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void dispatch();
    };
    int i;
    for (i = 0; i < *(int *)((char *)arg0 + 0x8); i++) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)arg0 + 0x4) + i * 0x4);
        entry->dispatch();
    }
}

#pragma scheduling on
extern "C" s32 fn_80159338(void) {
    return 3;
}

extern "C" void *fn_80159340(void *object, s32 deleting) {
    /* Destructor: reset vtable, destroy owned child at +0x278, clear embedded list (+8/+C/+10), and optionally free. */
    struct Child { virtual void destroy(s32); };
    if (object) {
        Child *child = *(Child **)((u8 *)object + 0x278);
        *(void **)object = lbl_8032F0E8;
        if (child) {
            if (child) child->destroy(1);
        }
        if (object) {
            if (object) {
                if ((u32)object + 8 != 0) {
                    if ((u32)object + 8 != 0) {
                        if ((u32)object + 8 != 0) {
                            *(u32 *)((u8 *)object + 8) = 0;
                            *(u32 *)((u8 *)object + 0xC) = 0;
                            *(u32 *)((u8 *)object + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (deleting > 0) fn_80128668(object);
    }
    return object;
}

/* Reset this object's state and notify/reset its linked object if present. */
extern "C" void fn_801593F0(Unk801577F0* self) {
    f32 b;
    f32 a;
    self->v31();
    *(f32*)((u8*)self + 0x25c) = lbl_80561754;
    if (*(f32*)((u8*)self + 0x260) > *(f32*)((u8*)self + 0x24c)) {
        s32 r3 = *(s32*)((u8*)self + 0x268);
        if (r3 != 0) {
            fn_801CB750(r3, self->m4);
        }
        *(f32*)((u8*)self + 0x260) = lbl_80561754;
    }
    Unk801577F0* object = *(Unk801577F0**)((u8*)self + 0x278);
    a = lbl_80561754;
    b = lbl_8056177C;
    *(f32*)((u8*)self + 0x264) = a;
    *(f32*)((u8*)self + 0x258) = b;
    if (object != 0) {
        *(u8*)((u8*)object + 0x4A) = 1;
        *(u8*)((u8*)object + 0x4C) = 0;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_80159488(Unk801577F0* object) {
    f32 zero = 0.0f;
    s32 index = 0;
    s32 byteOffset = 0;
    s32 zeroInt = 0;
    /* Reset per-entry data/state fields, invoke v31, and activate the child if present. */
    for (; index < object->mCount; ++index) {
        u8* base = (u8*)object->mData;
        *(s32*)(base + byteOffset) = zeroInt;
        s32* p = (s32*)object->mData;
        *(s32*)((u8*)p + byteOffset + 4) = zeroInt;
        p = (s32*)object->mData;
        *(s32*)((u8*)p + byteOffset + 8) = zeroInt;
        p = (s32*)object->mData;
        *(f32*)((u8*)p + byteOffset + 0xC) = zero;
        byteOffset += 0x38;
    }
    zero = 0.0f;
    *(f32*)((u8*)object + 0x25C) = zero;
    *(f32*)((u8*)object + 0x260) = zero;
    *(f32*)((u8*)object + 0x258) = zero;
    *(f32*)((u8*)object + 0x264) = zero;
    object->v31();
    void* child = *(void**)((u8*)object + 0x278);
    s32 one = 1;
    f32 finalZero = 0.0f;
    bool hasChild = child != 0;
    *(volatile u8*)((u8*)object + 0x274) = one;
    *(volatile f32*)((u8*)object + 0x270) = finalZero;
    if (hasChild) {
        *(u8*)((u8*)child + 0x4A) = 1;
        *(u8*)((u8*)child + 0x4C) = 0;
    }
}
// The lifetime counters fn_8001EF5C(id, amount) adds to, by the key each one
// is looked up by in the table at lbl_802FDF30.  The bonus trackers bank their
// record's count here when their bonus ends: air, tree_run, drift, rings and
// crash are the categories fn_80158E88, fn_8015A538, fn_80159554, fn_8015D270
// and fn_8015B618 belong to.
#define ACH_COUNTER_SCORE    0  // "score"
#define ACH_COUNTER_WIN      1  // "win"
#define ACH_COUNTER_AAA      2  // "AAA"
#define ACH_COUNTER_AIR      3  // "air"
#define ACH_COUNTER_TREE_RUN 4  // "tree_run"
#define ACH_COUNTER_DRIFT    5  // "drift"
#define ACH_COUNTER_RINGS    6  // "rings"
#define ACH_COUNTER_CRASH    7  // "crash"

// End of this drift bonus tracker's bonus, called with the tracker and the
// player whose bonus ended.  It hands the value built up so far to fn_80158D60,
// which scores it into the record being filled and resets the progress
// counters; banks the last record's count of scored values in the "drift"
// lifetime counter -- only for a single player run (fn_80179650() == 1) in the
// ordinary truck (player + 0x1F0 == 0x50) that is not a replay playback
// (fn_801CF064()); and asks the tracker's drift sound to stop, the way
// fn_80159624 does once the truck stops sliding.
extern "C" void fn_80159554(void *tracker, void *player) {
    void *playerArg = player;
    s32 scoredCount;
    fn_80158F34(&playerArg);
    if (*(f32 *)((u8 *)tracker + 0x25C) > 0.0f) {
        fn_80158D60(tracker, playerArg);
    }
    scoredCount = ((BonusRecord *)*(u32 *)((u8 *)tracker + 8))[(s32)(*(s32 *)((u8 *)tracker + 0xC) - 1)].scoredCount;
    if (scoredCount > 0 && fn_80179650() == 1 && *(s32 *)((u8 *)player + 0x1F0) == 0x50 && fn_801CF064() == 0) {
        fn_8001EF5C(ACH_COUNTER_DRIFT, scoredCount);
    }
    u8 *sound = *(u8 **)((u8 *)tracker + 0x278);
    if (sound != 0) {
        *(u8 *)(sound + 0x4A) = 1;
        *(u8 *)(sound + 0x4C) = 0;
    }
}

extern "C" f32 fabs(f32);
extern "C" f32 PSVECDotProduct(const void *, const void *);
extern "C" f32 lbl_80561760;
extern "C" f32 lbl_80561788;
extern "C" f32 lbl_8056178C;
extern "C" f32 lbl_80561790;

// The drift tracker, one of the bonus trackers above.  Besides the record
// table and the counters they all share it keeps, on the tracker:
//
//   +0x270 f32    seconds the truck has spent in its current ground state
//                 (fn_80159124 adds one frame to it, or clears it)
//   +0x274 u8     set while the truck is sliding sideways (fn_80159124)
//   +0x278 void*  the drift sound; 1 at its +0x4A is the stop request the
//                 trackers write, +0x4C is cleared with it
//
// and reads, on the truck:
//
//   +0x003C Vec   the sideways axis of the truck's body
//   +0x0118 Vec   its velocity
//   +0x25D4 f32   the speed, |velocity|
//   +0x2690 f32   its spin, which has to be still for a drift to count
//
// The globals the drift test compares those against.
#define DRIFT_EPSILON    lbl_80558DC4[0]  // .sdata: 2^-23, the "is zero" tolerance
#define DRIFT_MIN_SPEED  lbl_80561788     // .sdata2: 5.0f, the least speed a drift counts at
#define DRIFT_MAX_TIME   lbl_80561760     // .sdata2: 0.5f, the most the ground timer may read
#define DRIFT_KEEP_SLIP  lbl_8056178C     // .sdata2: 0.15f, sideways share of the speed that
                                          // keeps a drift going ...
#define DRIFT_START_SLIP lbl_80561790     // .sdata2: 0.35f, ... and the share that starts one

#pragma push
#pragma processor 750
extern "C" void fn_80159624(void *tracker, void *truck) {
    // One frame of the drift tracker's sound switch: while the truck is still
    // sliding sideways at speed its drift sound keeps playing, and as soon as
    // it is not, the tracker asks that sound to stop.  A drift counts when the
    // truck is neither spinning nor crawling, has been in its current ground
    // state under half a second, and enough of its velocity runs along the
    // sideways axis -- more to start a drift (0.35 of the speed) than to keep
    // one going (0.15), which is what the previous frame's flag selects.
    if (*(void **)((u8 *)tracker + 0x278) != 0) {
        u32 drifting;
        f32 spin = (f32)__fabs((f64)*(f32 *)((u8 *)truck + 0x2690));
        u8 wasDrifting = *(u8 *)((u8 *)tracker + 0x274);
        f32 speed = *(f32 *)((u8 *)truck + 0x25D4);
        if (spin <= DRIFT_EPSILON && speed > DRIFT_MIN_SPEED && *(f32 *)((u8 *)tracker + 0x270) < DRIFT_MAX_TIME) {
            f64 dtmp = __fabs((f64)PSVECDotProduct((const void *)((u8 *)truck + 0x118), (const void *)((u8 *)truck + 0x3C)));
            f32 sideways = (f32)dtmp;
            f32 slip = wasDrifting != 0 ? DRIFT_KEEP_SLIP : DRIFT_START_SLIP;
            drifting = sideways > speed * slip;
        } else {
            drifting = 0;
        }
        if (drifting != 0)
            return;
        u8 *sound = *(u8 **)((u8 *)tracker + 0x278);
        sound[0x4A] = 1;
        sound[0x4C] = 0;
    }
}
#pragma push
#pragma scheduling off
extern "C" int fn_80159708(void *arg0) {
    return (int)(*(float *)((char *)arg0 + 0x25C));
}
#pragma pop
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

/* Destroy the owned +0x278 child, clear the embedded list and optionally free. */
#pragma push
#pragma scheduling on
extern "C" void *fn_8015CE50(void *object, s32 deleting) {
    /* Destructor: reset vtable, destroy owned child at +0x278, clear embedded list (+8/+C/+10), and optionally free. */
    struct Child { virtual void destroy(s32); };
    if (object) {
        Child *child = *(Child **)((u8 *)object + 0x278);
        *(void **)object = lbl_8032EB58;
        if (child) {
            if (child) child->destroy(1);
        }
        if (object) {
            if (object) {
                if ((u32)object + 8 != 0) {
                    if ((u32)object + 8 != 0) {
                        if ((u32)object + 8 != 0) {
                            *(u32 *)((u8 *)object + 8) = 0;
                            *(u32 *)((u8 *)object + 0xC) = 0;
                            *(u32 *)((u8 *)object + 0x10) = 0;
                        }
                    }
                }
            }
        }
        if (deleting > 0) fn_80128668(object);
    }
    return object;
}
#pragma pop
