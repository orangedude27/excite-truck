// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern "C" f64 lbl_805634B8;
extern "C" char lbl_8033DAD8[];
extern "C" s32 fn_80129D90(s32, s32, s32);
extern "C" s32 fn_80131234(void *);
extern "C" void fn_80224DDC(void *, f32, f32, f32);
extern f32 lbl_805634E0;
extern "C" s32 lbl_80490920[];
extern "C" s32 lbl_802F9EE0[];
extern "C" char lbl_8033D9A4[];
#pragma push
#pragma small_data on
extern "C" char lbl_8055B890;
extern "C" char lbl_8055B898;
extern "C" char lbl_8055B8A0;
extern "C" char lbl_8055B860;
#pragma pop
extern "C" double fabs(double);
extern "C" f32 fabsf(f32);
#define FN8021C18C_ABS(x) __fabs(x)
extern "C" char lbl_8055B884;
extern "C" void fn_802C4F58(s32, s32, const char *, s32);

extern "C" s32 fn_802CAC28(void *, s32);
extern "C" char lbl_8033DC20[];
extern f32 lbl_805634C8;

extern "C" s32 fn_8022AB18(s32, s32, s32);
extern "C" f32 fn_8022AAA8(void *, char *);
extern "C" s32 fn_8022AA84(s32);
extern "C" s32 fn_80211660(s32);
extern "C" f32 lbl_80563508;
extern "C" f32 lbl_8056350C;
extern "C" void *lbl_8055E050;

extern "C" void fn_8022375C(void);

extern "C" u8 lbl_8033DA84[];
extern "C" char lbl_8033E4DC[];
extern "C" f32 lbl_8056352C;
extern "C" f32 lbl_80563530;

extern "C" void *lbl_8033DD20[];
extern "C" void *memset(void *, int, unsigned long);
extern "C" char lbl_8033DCE8[];
extern "C" s32 fn_8012C33C(void *);
extern "C" s32 fn_802C6FC0(void *, s32, s32);

extern "C" void fn_8021C6D0(void *);
extern "C" s32 fn_8021165C(s32, s32);
extern "C" s32 fn_8022B498(s32, s32);
extern "C" char lbl_8033EE50[];

extern "C" u8 lbl_8033E7F4[];
extern "C" char lbl_8033D9BC[];

struct DummyTextBoxV { virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual s32 g28(); };
struct Dummy2455C { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(int, int); };
#define TB(o, T) (*(T *)((u8 *)this_ + (o)))
static s32 abs_val(s32 x) {
    s32 sign = x >> 31;
    return (x ^ sign) - sign;
}

extern "C" void fn_8021C12C(void *);
extern "C" void fn_8021E7D4(void *);

extern "C" s32 fn_8021E620(void *, s32);
extern "C" void fn_8021E684(void *arg0);
extern "C" void fn_8021E6D4(void *arg0);
extern "C" void fn_8021E724(void *arg0);
extern "C" void fn_8021E774(void *arg0);
extern "C" void fn_8021E7C4(void *arg0);
extern "C" s32 fn_8022B620(s32, const char *);
extern "C" void *lbl_8033EA90[];
#pragma push
#pragma small_data on
extern "C" char lbl_8055B880;
#pragma pop
extern "C" void *lbl_8033E3D4[];
extern "C" void *lbl_8033DF30[];
extern "C" void fn_802E30C8(const char *, ...);
extern "C" s32 fn_8022D1B4(const char *);
extern "C" const char lbl_8033D940[];

extern "C" s32 stricmp(const char *, const char *);
// Font helpers (src/auto/text_801E4A2C_.c): fn_801E4A6C adds up the s16 glyph
// widths the font keeps at +0x204 for every byte of the string, so it measures
// the string in pixels; fn_801E4BA8 is the font's full line height.
extern "C" s32 fn_801E4A6C(s32 font, s32 str);
extern "C" s32 fn_801E4BA8(s32 font);
extern "C" void fn_802328D4(void *);
extern "C" f32 fn_80214D48(void);
extern "C" void fn_80228AEC(s32, f32);
extern "C" void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern "C" void fn_80230150(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_802304EC(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80230650(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_802307AC(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern "C" double fn_8002EFB4(double, double);
extern "C" double sin(double);
extern "C" f32 lbl_805634C0;
extern "C" f64 lbl_805634D0;
extern "C" f32 lbl_805634DC;

extern "C" u8 lbl_8033E140[];
extern "C" void fn_8022EE98(void *);
extern "C" void fn_8022A8E4(s32);
extern "C" void *lbl_8033E1C4[];
#pragma push
#pragma small_data on
extern "C" char lbl_8055B88C;
#pragma pop


extern "C" void *fn_8022EE9C(void);

extern "C" char lbl_8033F880[];
extern "C" char lbl_8033DAAC[];
extern "C" char lbl_8033DABC[];

extern "C" void fn_80130568(char *);

extern "C" void fn_80130568(char *);

#pragma push
#pragma small_data off
extern "C" char lbl_8033DC4C[];
extern "C" char lbl_8033DC58[];
extern "C" void *lbl_8033DEAC[];
#pragma pop

extern "C" void fn_80227880(s32, f32, f32, f32, f32);
extern "C" void fn_80230924(s32, s32, f32, f32, f32, f32, f32);
extern "C" f32 lbl_80563514;
extern "C" { __declspec(section ".data") extern char lbl_8033E038; }
extern "C" u8 lbl_8055EFBC;
extern "C" char lbl_8055B8A4[4];
extern "C" s32 fn_80235FD8(s32);
extern "C" void fn_80227044(void *, f32, f32, f32);

extern "C" s32 fn_8022F638(s32, s32, s32, s32, f32);
extern f32 lbl_805634E4;

extern "C" void *fn_8021525C(void);
extern "C" void fn_80218FEC(void *, s32, s32, s32, s32, s32);

extern "C" s32 fn_8022F8CC(s32);
extern "C" s32 fn_8022FFE8(s32);

class Fn80229AE4Dispatch {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Call(s32, s32, s32, s32);
};

class Fn80229A94Dispatch {
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
    virtual void Call(s32, s32);
};

class Fn80229DE8Dispatch {
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
    virtual void Call(s32);
};

class Fn80229DE8Dispatch2 {
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
    virtual void Call(s32, s32);
};

struct Fn8021C9D8Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void First();
    virtual void Second();
};

struct Fn80219264VTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Call(s32, s32);
};

struct Fn80229900VTable {
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
    virtual void Call(s32, s32);
};

struct Fn8021E8DCVTable {
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
    virtual s32 Get();
};

struct Fn8021C4D4VTable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual s32 At1C();
    virtual s32 At20();
};
#pragma push
#pragma small_data off
extern "C" u8 lbl_8033F180[];
#pragma pop
extern f32 lbl_805634F0;
extern f32 lbl_805634F4;
extern f32 lbl_805634F8;
extern "C" void *fn_8022EDE4(f32);
extern "C" s32 strlen(const char *);
extern "C" f32 lbl_805634D8;
extern "C" f32 lbl_80563528;
#pragma push
#pragma small_data on
extern "C" char lbl_8055B8A8[];
#pragma pop
extern "C" void fn_80015A20(void *, f32 *, s32, f32, f32, f32);
extern "C" void fn_80015B20(void *, void *, void *);
extern "C" s32 fn_8022D3F8(s32, s32, s32 *, s32, s32);
extern "C" void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
extern "C" s32 fn_802ECF08(s32, s32);
extern "C" s32 fn_802ED040(void);
extern "C" s32 fn_802ECF90(s32);
extern f64 lbl_805634B8;
extern s32 lbl_8055CFF0;
extern s32 lbl_8055CFF4;
extern f32 lbl_8056357C;
extern f32 lbl_80563580;
extern "C" int lbl_8033F998[];
extern "C" int lbl_8033E350[];
extern "C" s32 fn_802ECFF4(s32);
extern "C" void fn_802ECFEC(void);
extern "C" s32 fn_802C5130(s32, void *);
extern "C" s32 fn_802C51C0(s32);
extern "C" s32 fn_802C5220(s32);
extern "C" void *lbl_8033E878[];
extern "C" void *lbl_8033DCF8[];
extern "C" void fn_802192AC(void *);
extern "C" f32 fn_80214D48(void);
extern "C" f32 lbl_80563504;
extern "C" f32 lbl_80563510;
extern "C" void fn_80219AB4(void *, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8021D61C(void *);
extern "C" u8 lbl_8033EB14[];
extern "C" char lbl_8055B87C;
extern "C" int sprintf(char *, const char *, ...);
extern "C" void fn_801E4BEC(s32, s32, s32, s32, s32, s32);
extern "C" u8 lbl_8033F0FC[];
extern "C" void fn_8021BE48(void *);
extern "C" void fn_802223C4(void *arg0, s32 arg1);
extern f32 lbl_805634C4;
#pragma push
#pragma small_data off
extern "C" void *lbl_8033EC2C[];
#pragma pop
extern "C" f32 fn_8023659C(void);
extern "C" s32 fn_80228F40(s32, s32);
extern "C" s32 fn_80216D28();
extern "C" s32 fn_80217C4C(s32);
extern "C" s32 fn_80217D84(s32);
extern "C" s32 fn_8022EDC4(void);
extern "C" void fn_8022EEF8(void *, s32, s32);
extern "C" void fn_8022ED00(void *);
extern "C" void fn_8022EDB8(void);
extern "C" void fn_80231220(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);

#pragma always_inline on
static inline void Rot3Vec(f32 *m, f32 *src, f32 *dst) {
    if (dst == src) {
        f32 x = src[0] * m[0] + src[1] * m[3] + src[2] * m[6];
        f32 y = src[0] * m[1] + src[1] * m[4] + src[2] * m[7];
        f32 z = src[0] * m[2] + src[1] * m[5] + src[2] * m[8];
        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    } else {
        dst[0] = src[0] * m[0] + src[1] * m[3] + src[2] * m[6];
        dst[1] = src[0] * m[1] + src[1] * m[4] + src[2] * m[7];
        dst[2] = src[0] * m[2] + src[1] * m[5] + src[2] * m[8];
    }
}
struct RotV3 { f32 x, y, z; };
static inline void Rot3Vec(f32 *m, RotV3 *src, RotV3 *dst) {
    if (dst == src) {
        f32 x = src->x * m[0] + src->y * m[3] + src->z * m[6];
        f32 y = src->x * m[1] + src->y * m[4] + src->z * m[7];
        f32 z = src->x * m[2] + src->y * m[5] + src->z * m[8];
        dst->x = x;
        dst->y = y;
        dst->z = z;
    } else {
        dst->x = src->x * m[0] + src->y * m[3] + src->z * m[6];
        dst->y = src->x * m[1] + src->y * m[4] + src->z * m[7];
        dst->z = src->x * m[2] + src->y * m[5] + src->z * m[8];
    }
}
#pragma always_inline reset

class ObjBF { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual s32 i(); virtual s32 j(); };

class TruckIface {
public:
    virtual ~TruckIface();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

class Dispatch19718 { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void set(s32, s32); };
class Dispatch19718_1C { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void set(s32, s32); };

class Vf78 { public:
virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
virtual void a25(); virtual void a26(); virtual void a27(); virtual s32 get();
};

class Vf78x { public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
 virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
 virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
 virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
 virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
 virtual void a25(); virtual void a26(); virtual void a27(); virtual s32 get(); };

class V24x { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual f32 get(); };
class V20x { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual f32 get(); };
class V14x { public: virtual void a(); virtual void b(); virtual void c(); virtual f32 get(); };
class V18x { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual f32 get(); };

class VfObjCall {
public:
    virtual void vf2(s32);
};

class VfObj {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual s32 vf28();
    virtual s32 vf29();
    virtual s32 vf30();
    virtual s32 vf31();    // vtable 0x84
          virtual s32 vf32();    // vtable 0x88
  };

struct S_80229DC8 {
    u8 pad_0x260[4];
    u8 field_268;
};

class Vf14Apply {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void apply(s32, s32, s32, f32);
};

extern "C" void fn_8023976C(s32);
extern "C" void fn_802168BC(void *);
extern "C" void *fn_8022D97C(s32);
extern "C" void *lbl_8033F90C[];
extern "C" int lbl_8033FA28[];
extern "C" void fn_802CAC54(void);
extern "C" char lbl_8033DFB4[];
extern "C" s32 fn_80128668(void *);
extern "C" void fn_80219440(void *, s32, void *, s32);
extern "C" void fn_80128670(s32);
extern "C" int lbl_8033F4B8[];
extern "C" int lbl_8033FB38[];
extern "C" void *fn_80222340(void *, s32, s32, s32, s32, s32, s32);
extern "C" void *fn_80218F80(void *, void *);
extern "C" char lbl_8033E560[];
extern "C" char lbl_8033DA60[];
extern "C" s32 fn_80232578(s32);
extern "C" void fn_802E317C(const char *, ...);
extern f32 lbl_8056351C;
extern f64 lbl_80563520;
extern "C" void fn_8023986C(s32);
extern "C" void fn_8023967C(s32, s32);
extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_801284F8(s32, const char *);
extern "C" s32 fn_8023964C(void);
extern "C" void fn_80239784(s32, void *);
extern char lbl_8033DDA4[];
extern char lbl_8033DE28[];
extern char lbl_8033DCDC[];


extern "C" void fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern "C" s32 fn_8012850C(void *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern "C" char *strcpy(char *, const char *);
extern "C" void *fn_80219568(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80219718(void *);
extern "C" u8 lbl_8033F3B0[];
extern "C" u8 lbl_8033F434[];
extern "C" void fn_80219440(void *, s32, void *, s32);
extern f32 lbl_805634A4;
extern "C" f32 lbl_805634A8;
extern "C" void fn_802C5280(void *, s32, s32, s32, s32, void *);
extern char lbl_8033D878[];
extern "C" void *lbl_8033E770[];
extern char lbl_8033F768[];
extern "C" u32 *fn_80216708(void);
extern "C" s32 fn_80218F34(void *, s32, s32, s32, s32, s32);
extern "C" void fn_8022B91C(s32, s32, s32, s32, s32);
extern "C" s32 fn_802C51AC(s32);
extern "C" s32 fn_802C5310(s32, s32, f32, f32, f32);
extern "C" void fn_80230C30(f32 *, f32 *, s32, s32);
extern "C" void fn_802353F4(s32, s32, f32, f32, f32);
extern "C" f32 fn_80235EF0(s32, s32);
extern "C" f32 fn_80235F64(s32, s32);
extern "C" void fn_802C5320(s32, s32, f32, f32, f32, f32, f32);
extern "C" s32 fn_802C51C0(s32);
extern "C" s32 fn_802C5220(s32);
extern "C" s32 fn_802C3034(s32);
extern f32 lbl_805634A8;
extern f32 lbl_805634E8;
extern int lbl_8033F6E0[];
extern "C" char lbl_8033EBA0[];
extern "C" char lbl_8033F658[];
extern "C" s32 lbl_8055FBC0;

extern "C" void fn_80219044(void *);
#pragma push
#pragma small_data off
extern "C" char lbl_8033F548[];
#pragma pop
extern "C" void fn_802C519C(void *);
extern "C" s32 fn_80128668(void *);
extern "C" void *lbl_8033EDC8[];
extern "C" void *lbl_8033ED44[];

extern f32 lbl_805634A0;
extern f32 lbl_805634AC;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;
extern s32 lbl_8055FB9C;
extern s32 lbl_8055FBA0;
extern "C" s32 lbl_8055FBDC;
extern f32 lbl_80563500;

extern "C" void fn_80218E98(void *arg0, void *arg1) {
    s32 fourth, third, second, first;
    volatile s32 *src = (volatile s32 *)((u8 *)arg0 + 0x14);
    s32 *dst = (s32 *)arg1;
    first = src[0];
    second = src[1];
    third = src[2];
    fourth = src[3];
    dst[0] = first;
    dst[1] = second;
    dst[2] = third;
    dst[3] = fourth;
}

extern "C" void fn_80218EBC(void *arg0, void *arg1) {
    s32 fourth, third, second, first;
    volatile s32 *src = (volatile s32 *)arg1;
    s32 *dst = (s32 *)((u8 *)arg0 + 0x14);
    first = src[0];
    second = src[1];
    third = src[2];
    fourth = src[3];
    dst[0] = first;
    dst[1] = second;
    dst[2] = third;
    dst[3] = fourth;
}

extern "C" void fn_80218EE0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 var_r4 = arg1;
    s32 var_r5 = arg2;
    s32 var_r6 = arg3;
    s32 var_r7 = arg4;

    temp_r0 = *(s32 *)((u8 *)arg0 + 0x14);
    if (temp_r0 > var_r4)
        var_r4 = temp_r0;
    temp_r0_2 = *(s32 *)((u8 *)arg0 + 0x18);
    *(s32 *)((u8 *)arg0 + 0x14) = var_r4;
    if (temp_r0_2 > var_r5)
        var_r5 = temp_r0_2;
    temp_r0_3 = *(s32 *)((u8 *)arg0 + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x18) = var_r5;
    if (temp_r0_3 < var_r6)
        var_r6 = temp_r0_3;
    temp_r0_4 = *(s32 *)((u8 *)arg0 + 0x20);
    *(s32 *)((u8 *)arg0 + 0x1C) = var_r6;
    if (temp_r0_4 < var_r7)
        var_r7 = temp_r0_4;
    *(s32 *)((u8 *)arg0 + 0x20) = var_r7;
}

#pragma dont_inline on
extern "C" s32 fn_80218F34(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    *(void **)arg0 = lbl_8033FB38;
    fn_80218FEC(arg0, arg1, arg2, arg3, arg4, arg5);
    *(void **)((u8 *)arg0 + 0x23C) = fn_8021525C();
    *(s32 *)((u8 *)arg0 + 0x240) = 0;
    return (s32)arg0;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_80218F80(void *arg0, void *arg1) {
    *(void **)arg0 = lbl_8033FB38;
    register void *temp_r7 = arg1;
    s32 temp_r5 = *(s32 *)((u8 *)arg1 + 0xC);
    s32 temp_r4 = *(s32 *)((u8 *)arg1 + 8);
    fn_80218FEC(arg0, temp_r4, temp_r5,
                temp_r4 + *(s32 *)((u8 *)temp_r7 + 0x14),
                temp_r5 + *(s32 *)((u8 *)temp_r7 + 0x18),
                *(s32 *)((u8 *)temp_r7 + 0x10));
    *(void **)((u8 *)arg0 + 0x23C) = fn_8021525C();
    *(s32 *)((u8 *)arg0 + 0x240) = 0;
    return arg0;
}
#pragma pop
#define fn_80218F80() ((void (*)(void))fn_80218F80)()

extern "C" void fn_80218FEC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    *(u8 *)((u8 *)arg0 + 0x1A) = 1;
    *(u8 *)((u8 *)arg0 + 0x1B) = 1;
    *(f32 *)((u8 *)arg0 + 0x1C) = -1.0f;
    *(f32 *)((u8 *)arg0 + 0x20) = -1.0f;
    *(f32 *)((u8 *)arg0 + 0x24) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x28) = 1.0f;
    *(u8 *)((u8 *)arg0 + 0x234) = 1;
    *(s32 *)((u8 *)arg0 + 0x238) = 0;
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x230) = 0;
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = arg3;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = arg4;
    *(s32 *)((u8 *)arg0 + 0x14) = arg5;
    *(u8 *)((u8 *)arg0 + 0x19) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = 0;
}

/* Updates fade timers at +0x1C/+0x20 based on state flag +0x1A, decaying by dt * rate until threshold and setting dirty flag +0x234 on transitions. */
extern "C" void fn_80219044(void *obj) {
    u8 *p = (u8 *)obj;
    u8 state;
    f32 expireThreshold;
    f32 decayRate;
    f32 timer;
    f32 decrement;
    f32 dt;
    f32 remaining;
    f32 expireThreshold2;
    f32 decayRate2;
    f32 timer2;
    f32 decrement2;
    f32 dt2;
    f32 remaining2;
    if (*(u8 *)(p + 0x1A) != 0) {
        if (*(f32 *)(p + 0x1C) >= lbl_805634A8) {
            dt = fn_80214D48();
            decayRate = *(f32 *)(p + 0x24);
            timer = *(f32 *)(p + 0x1C);
            decrement = decayRate * dt;
            expireThreshold = lbl_805634AC;
            remaining = timer - decrement;
            *(f32 *)(p + 0x1C) = remaining;
            if (remaining <= expireThreshold) {
                state = *(u8 *)(p + 0x1A);
                if ((unsigned)state != 0) {
                    if (state != 0) {
                        *(u8 *)(p + 0x234) = 1;
                    }
                    *(u8 *)(p + 0x1A) = 0;
                }
                *(f32 *)(p + 0x1C) = lbl_805634A0;
            }
        }
    } else {
        *(f32 *)(p + 0x1C) = lbl_805634A0;
    }
    if (*(u8 *)(p + 0x1A) == 0) {
        if (*(f32 *)(p + 0x20) >= lbl_805634A8) {
            dt2 = fn_80214D48();
            decayRate2 = *(f32 *)(p + 0x28);
            timer2 = *(f32 *)(p + 0x20);
            decrement2 = decayRate2 * dt2;
            expireThreshold2 = lbl_805634AC;
            remaining2 = timer2 - decrement2;
            *(f32 *)(p + 0x20) = remaining2;
            if (remaining2 <= expireThreshold2) {
                state = *(u8 *)(p + 0x1A);
                if (!state) {
                    *(u8 *)(p + 0x1A) = 1;
                    *(u8 *)(p + 0x234) = 1;
                }
                *(f32 *)(p + 0x20) = lbl_805634A0;
            }
        }
    } else {
        *(f32 *)(p + 0x20) = lbl_805634A0;
    }
}

#pragma dont_inline on
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_8021915C(void *arg0, u32 arg1) {
    u8 *entry;
    s32 i;

    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033FB38;
        entry = (u8 *)arg0;
        i = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x230)) {
            fn_80128670(*(s32 *)(entry + 0x3C));
            entry += 0x10;
            i++;
        }
        if ((s32)arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma pop
#pragma dont_inline off

extern "C" void fn_802191F0(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r3;
    temp_r3 = arg1 + ((VfObj *)arg0)->vf28();
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    temp_r0 = arg2 + (*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
    *(s32 *)((u8 *)arg0 + 0xC) = temp_r3;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = temp_r0;
}

#pragma scheduling invalid_target
extern "C" void fn_80219264(void *arg0, s32 arg1, s32 arg2) {
    ((Fn80219264VTable *)arg0)->Call(
        *(s32 *)((u8 *)arg0 + 4) + arg1,
        *(s32 *)((u8 *)arg0 + 8) + arg2);
}
#pragma scheduling on
extern "C" void fn_80219284(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)arg0 + 4) + arg1;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) + arg2;
}

extern "C" void fn_802192A0(void) {

}

#pragma dont_inline on
extern "C" s32 fn_802192A4(void *, s32) { return 0; }

extern "C" int memcmp(const void *, const void *, size_t);
extern "C" void *memcpy(void *, const void *, size_t);
#pragma use_lmw_stmw off
/* For each tracked slot, copy changed source data to destination and
 * invoke the slot callback; then update this object's internal timers/state. */
extern "C" void fn_802192AC(void *arg0) {
    char *slot = (char *)arg0;
    size_t size;
    void *src;
    void *dst;
    s32 index;

    for (index = 0; index < *(s32 *)((u8 *)arg0 + 0x230); slot += 0x10, index++) {
        size = *(size_t *)(slot + 0x38);
        dst = *(void **)(slot + 0x3C);
        src = *(void **)(slot + 0x30);
        if (memcmp(src, dst, size) != 0) {
            memcpy(dst, src, size);
            ((Fn80229900VTable *)arg0)->Call(*(s32 *)(slot + 0x34), *(s32 *)(slot + 0x30));
        }
    }
    ((void (*)(void *))fn_80219044)(arg0);
}
#pragma use_lmw_stmw reset
extern "C" void fn_8021889C(s32, s32, f32);
extern "C" void fn_80218968(s32, s32, f32);

extern "C" void fn_80219354(void) { ((void (*)(void))fn_80219044)(); }

extern f32 lbl_805634A0;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80219358(void *arg0, f32 value) {
    register f32 threshold = lbl_805634B0;
    if (value < threshold) {
        if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
            return;
        *(u8 *)((u8 *)arg0 + 0x1A) = 1;
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
        return;
    }
    if (*(u8 *)((u8 *)arg0 + 0x1A) == 0) {
        if (*(f32 *)((u8 *)arg0 + 0x20) < lbl_805634B4) {
            f32 divisor;
            *(f32 *)((u8 *)arg0 + 0x20) = lbl_805634A4;
            if (value > threshold)
                divisor = value;
            else
                divisor = threshold;
            *(f32 *)((u8 *)arg0 + 0x28) = lbl_805634A4 / divisor;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_805634A0;
}
#pragma scheduling on
#pragma pop
extern "C" void fn_802193C8(void *arg0, f32 value) {
    const f32 threshold = 0.1f;
    if (value < threshold) {
        u8 enabled = *(u8 *)((u8 *)arg0 + 0x1A);
        if (enabled == 0)
            return;
        if (enabled != 0)
            *(u8 *)((u8 *)arg0 + 0x234) = 1;
        *(u8 *)((u8 *)arg0 + 0x1A) = 0;
        return;
    }
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
        if (*(f32 *)((u8 *)arg0 + 0x1C) < lbl_805634B4) {
            *(f32 *)((u8 *)arg0 + 0x1C) = lbl_805634A4;
            *(f32 *)((u8 *)arg0 + 0x24) = lbl_805634A4 / MAX(value, threshold);
        }
    }
    *(f32 *)((u8 *)arg0 + 0x20) = lbl_805634A0;
}

#pragma dont_inline on
/* Store a copy of widget notification data in the object's old-data list. */
extern "C" void fn_80219440(void *self, s32 tag, void *data, s32 size) {
    void *copy = (void *)fn_8012850C((void *)size, lbl_8033D878);
    *(s32 *)((u8 *)self + ((*(s32 *)((u8 *)self + 0x230)) << 4) + 0x34) = tag;
    *(s32 *)((u8 *)self + ((*(s32 *)((u8 *)self + 0x230)) << 4) + 0x30) = (s32)data;
    *(s32 *)((u8 *)self + ((*(s32 *)((u8 *)self + 0x230)) << 4) + 0x38) = size;
    *(void **)((u8 *)self + ((*(s32 *)((u8 *)self + 0x230)) << 4) + 0x3C) = copy;
    memcpy(copy, data, (unsigned long)size);
    *(s32 *)((u8 *)self + 0x230) = *(s32 *)((u8 *)self + 0x230) + 1;
}
#pragma dont_inline reset

extern "C" void fn_802179A0(s32);
extern void fn_80218198(s32, s32);
#pragma dont_inline on
extern "C" void fn_802194F4(void* arg0) {
    fn_802179A0(*(s32*)((u8*)arg0 + 0x2C));
}
#pragma dont_inline reset

extern "C" void fn_802194FC(void* arg0) {
    fn_80218198(*(s32*)((u8*)arg0 + 0x2C), 0);
}

extern "C" void fn_80217AC0(s32);
#pragma dont_inline on
extern "C" void fn_80219508(void* arg0) {
    fn_80217AC0(*(s32*)((u8*)arg0 + 0x2C));
}
#pragma dont_inline reset

extern "C" void fn_80219510(void *arg0, s32 arg1, s32 arg2) {
    s32 first = -arg1;
    s32 second = -arg2;
    *(s32 *)((u8 *)arg0 + 0x244) = first;
    *(u8 *)((u8 *)arg0 + 0x24C) = 1;
    *(s32 *)((u8 *)arg0 + 0x248) = second;
}

extern "C" void fn_8021952C(void* arg0, s32 arg1, s32 arg2) {
    void* p = *(void**)((u8*)arg0 + 0x2C);
    if (*(u8*)((u8*)arg0 + 0x24C) != 0) {
        s32 dx = *(s32*)((u8*)arg0 + 0x244) + arg1;
        s32 old1 = *(s32*)((u8*)p + 0x454);
        s32 dy = *(s32*)((u8*)arg0 + 0x248) + arg2;
        s32 old2 = *(s32*)((u8*)p + 0x458);
        *(s32*)((u8*)p + 0x454) = old1 + dx;
        *(s32*)((u8*)p + 0x458) = old2 + dy;
    }
}

extern "C" void *fn_80219568(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    fn_80218F34(arg0, arg1, arg2, arg1 + arg5, arg2 + arg6, arg3);
    *(s32 *)((u8 *)arg0 + 0x244) = 0;
    *(void **)arg0 = lbl_8033FA28;
    *(s32 *)((u8 *)arg0 + 0x248) = 0;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg3;
    *(s32 *)((u8 *)arg0 + 0x250) = arg4;
    return arg0;
}

extern "C" void fn_802195DC(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    VfObj *obj = (VfObj *)arg0;
    s32 a = obj->vf31();
    s32 b = obj->vf32();
    fn_8022B91C(*(s32 *)((u8 *)arg0 + 0x250), *(s32 *)((u8 *)arg0 + 0x244), *(s32 *)((u8 *)arg0 + 0x248), b, a);
}

extern "C" s32 fn_80219658(void) { return 0; }

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80219660(void *arg0) {
    struct Dispatch {
        virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
        virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7();
        virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11();
        virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15();
        virtual s32 v16(); virtual s32 v17(); virtual s32 v18(); virtual s32 v19();
        virtual s32 v20(); virtual s32 v21(); virtual s32 v22(); virtual s32 v23();
        virtual s32 v24(); virtual s32 v25(); virtual s32 v26(); virtual s32 v27();
        virtual s32 At78();
        virtual s32 v29(); virtual s32 v30();
        virtual s32 At84();
        virtual s32 At88();
    };
    register void *self = arg0;
    register s32 y;
    register s32 x;
    register s32 diff;
    register s32 b;
    register s32 a;
    a = *(s32 *)((u8 *)self + 8);
    b = *(s32 *)((u8 *)self + 4);
    diff = *(s32 *)((u8 *)self + 0x10) - a;
    x = ((Dispatch *)self)->At84();
    y = ((Dispatch *)self)->At88();
    register s32 z = ((Dispatch *)self)->At78();
    s32 zero = 0;
    f32 scale = lbl_805634A4;
    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32))fn_8022BAD0)(*(s32 *)((u8 *)self + 0x250), *(s32 *)((u8 *)self + 0x244) + b, *(s32 *)((u8 *)self + 0x248) + a, *(s32 *)((u8 *)self + 0x24C), z, diff, y, x, scale, zero);
}
#pragma scheduling on
#pragma pop

extern "C" void fn_8022AC1C(s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *);
extern "C" void fn_80219718(void *arg0) {
    s32 sp14, sp10, spC, sp8;
    s32 temp_r30;
    s32 var_r0, var_r0_2, var_r0_3, var_r0_4;
    fn_8022AC1C(*(s32 *)((u8 *)arg0 + 0x250), ((VfObj *)arg0)->vf32(),
        *(s32 *)((u8 *)arg0 + 0x244) + *(s32 *)((u8 *)arg0 + 4),
        *(s32 *)((u8 *)arg0 + 0x248) + *(s32 *)((u8 *)arg0 + 8),
        &sp14, &sp10, &spC, &sp8);
    var_r0 = sp14;
    if (var_r0 > *(s32 *)((u8 *)arg0 + 4)) var_r0 = *(s32 *)((u8 *)arg0 + 4);
    sp14 = var_r0;
    temp_r30 = *(s32 *)((u8 *)arg0 + 4);
    var_r0_2 = temp_r30 + ((VfObj *)arg0)->vf28();
    if (var_r0_2 > spC) var_r0_2 = spC;
    spC = var_r0_2;
    var_r0_3 = sp10;
    if (var_r0_3 > *(s32 *)((u8 *)arg0 + 8)) var_r0_3 = *(s32 *)((u8 *)arg0 + 8);
    sp10 = var_r0_3;
    var_r0_4 = sp8;
    if (var_r0_4 < *(s32 *)((u8 *)arg0 + 0x10)) var_r0_4 = *(s32 *)((u8 *)arg0 + 0x10);
    sp8 = var_r0_4;
    *(s32 *)((u8 *)arg0 + 0x244) += *(s32 *)((u8 *)arg0 + 4) - sp14;
    *(s32 *)((u8 *)arg0 + 0x248) += *(s32 *)((u8 *)arg0 + 8) - sp10;
    ((Dispatch19718_1C *)arg0)->set(sp14, sp10);
    fn_80219284(arg0, spC - sp14, sp8 - sp10);
}

extern "C" void *fn_80219870(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32, s32))fn_80219568)(arg0, arg1, arg2, 0, arg5, 0, 0, arg7);
    *(void **)arg0 = lbl_8033F768;
    strcpy((char *)arg0 + 0x258, arg3);
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    fn_80219440(arg0, 0, (void *)arg4, 1);
    fn_80219718(arg0);
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80219900(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
extern "C" s32 fn_80219958(void *arg0, s32 arg1) {
    return fn_802192A4(arg0, arg1);
}
#pragma dont_inline reset
extern "C" void *fn_8021995C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_80222340(arg0, arg1, arg2, arg3, 0, 0, arg4);
    *(s32 *)((u8 *)arg0 + 0x254) = arg5;
    *(void **)arg0 = lbl_8033F4B8;
    if (arg5 != 0) {
        fn_80219440(arg0, 0, (void *)arg5, 4);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802199D0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802223C4(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_80219A28(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    fn_80218F80();
    *(void **)arg0 = lbl_8033F434;
    fn_80219AB4(arg0, *(s32 *)((u8 *)arg1 + 4), arg2,
        *(s32 *)((u8 *)arg1 + 0x9C), arg3,
        *(s32 *)((u8 *)arg1 + 0xA0),
        *(s32 *)((u8 *)arg1 + 0xA4) != 0);
    return arg0;
}

extern "C" s32 fn_80232B70(s32);
extern "C" f32 fn_8023293C(s32, s32, f32);
extern "C" s32 fn_8023512C(s32);
extern "C" void fn_80235380(void *);
extern char lbl_8033D8B8[];
#pragma push
#pragma processor 750
extern "C" void fn_80219AB4(void *arg0, s32 type, s32 name, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *obj = (u8 *)arg0;
    *(s32 *)(obj + 0x24C) = arg4;
    const char *src = (const char *)name;
    char *dst = (char *)obj + 0x25C;
    s32 count = 32;
    *(s32 *)(obj + 0x258) = name;
    *(s32 *)(obj + 0x254) = arg5;
    *(s32 *)(obj + 0x250) = arg3;
    *(s32 *)(obj + 0x244) = type;
    while ((*dst++ = *src++) != 0) {
        if (--count <= 0) { dst[-1] = 0; break; }
    }
    f32 zero = lbl_805634A4;
    *(u8 *)(obj + 0x280) = arg6;
    *(s32 *)(obj + 0x248) = 0;
    s32 resource = 0;
    *(f32 *)(obj + 0x27C) = zero;
    if (type != 6 && type != 3) resource = arg4;
    switch (type) {
    case 4:
        if (resource) {
            *(s32 *)(obj+0x248) = fn_80232578(resource);
            s32 n = fn_80232B70(*(s32 *)(obj+0x248));
            s32 m = n < 1 ? 1 : n;
            f32 a = (f32)((VfObj *)obj)->vf28() / (f32)m;
            f32 b = fn_8023293C(*(s32 *)(obj+0x248),name,lbl_805634A4);
            b = b > lbl_805634A4 ? b : lbl_805634A4;
            f32 c = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / b;
            *(f32 *)(obj+0x27C) = a < c ? a : c;
        }
        break;
    case 2:
        if (resource) {
            *(s32 *)(obj+0x248) = fn_80232578(resource);
            s32 n = fn_80232B70(*(s32 *)(obj+0x248));
            f32 a = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / (f32)(n < 1 ? 1 : n);
            f32 b = fn_8023293C(*(s32 *)(obj+0x248),name,lbl_805634A4);
            b = b > lbl_805634A4 ? b : lbl_805634A4;
            f32 c = (f32)((VfObj *)obj)->vf28() / b;
            *(f32 *)(obj+0x27C) = a < c ? a : c;
        }
        break;
    case 9:
        *(s32 *)(obj+0x248) = fn_8023512C(name);
        break;
    case 3: case 6: case 8:
        *(s32 *)(obj+0x248) = fn_8023512C(name);
        if(arg4) fn_80219440(obj,0,(void *)arg4,4);
        break;
    case 5:
        if (resource) {
            *(s32 *)(obj+0x248) = fn_80232578(resource);
            s32 n = fn_80232B70(*(s32 *)(obj+0x248));
            f32 a = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / (f32)(n < 1 ? 1 : n);
            f32 b = fn_8023293C(*(s32 *)(obj+0x248),name,lbl_805634A4);
            b = b > lbl_805634A4 ? b : lbl_805634A4;
            f32 c = (f32)((VfObj *)obj)->vf28() / b;
            *(f32 *)(obj+0x27C) = a < c ? a : c;
        }
        break;
    default: fn_802E317C(lbl_8033D8B8); break;
    }
}

extern "C" void *fn_80219E44(void *obj, s32 shouldDelete) {
    if (obj != 0) {
        /* Destroys a text/UI object: restore base vtable, release owned resource by kind, run base destructor, optionally delete storage. */
        *(void **)obj = lbl_8033F434;
        switch (*(s32 *)((u8 *)obj + 0x244)) {
        case 3:
        case 6:
        case 8:
        case 9:
            if (*(void **)((u8 *)obj + 0x248) != 0)
                fn_80235380(*(void **)((u8 *)obj + 0x248));
            break;
        case 2:
        case 4:
        case 5:
            if (*(void **)((u8 *)obj + 0x248) != 0)
                fn_802328D4(*(void **)((u8 *)obj + 0x248));
            break;
        }
        *(void **)((u8 *)obj + 0x248) = 0;
        fn_8021915C(obj, 0);
        if (shouldDelete > 0)
            fn_80128668(obj);
    }
    return obj;
}

extern "C" void fn_8002B1D8(void);
extern "C" void fn_80219F14(void *arg0) {
    struct Object {
        u8 pad[0x244];
        s32 state;
        s32 old;
        u8 pad24C[12];
        char *source;
        char text[0x20];
    };
    Object *object = (Object *)arg0;

    /* Refresh watched fields, then update cached source text/handle for active states. */
    fn_802192AC(arg0);
    switch (object->state) {
    case 3:
    case 6:
    case 8:
    case 9:
        break;
    default:
        return;
    }

    if (((s32 (*)(char *, char *, s32))fn_8002B1D8)(
            object->text, object->source, 0x1F) == 0)
        return;
    if (object->old != 0)
        fn_80235380((void *)object->old);
    object->old = fn_8023512C((s32)object->source);
    {
        u8 c;
        char *source = object->source;
        s32 count = 0x20;
        char *destination = object->text;
        goto copy_loop;
    count_loop:
        count--;
        if (count > 0) goto copy_loop;
        destination[-1] = 0;
        return;
    copy_loop:
        c = *source++;
        *destination++ = c;
        if ((s8)c != 0) goto count_loop;
    }
}

extern "C" void fn_80219FE0(void *arg0) {
    u8 *self = (u8 *)arg0;
    f32 time = fn_8023659C();
    f32 zero = lbl_805634A8;
    f32 x = zero;
    f32 y = zero;
    fn_80230C30(&x, &y, *(s32 *)(self + 4), *(s32 *)(self + 8));
    switch (*(u32 *)(self + 0x244)) {
    case 0:
    case 1: {
        s32 flag = 2;
        if (*(s32 *)(self + 0x244) == 0)
            flag = 1;
        s32 h = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
        f32 wf = (f32)((VfObj *)self)->vf28();
        fn_80230150(*(s32 *)(self + 0x254), flag | 8, x, y - (f32)h, zero, wf, (f32)h,
                    (f32)*(s32 *)(self + 0x250), time, lbl_805634C0);
        break;
    }
    case 9: {
        s32 obj = *(s32 *)(self + 0x248);
        if (obj != 0) {
            s32 w = ((VfObj *)self)->vf28();
            f32 base = *(f32 *)((u8 *)lbl_8055E050 + 0x70) + (f32)w;
            x = x - base * lbl_805634C4;
            f32 hf = (f32)(*(s32 *)(self + 0x10) - *(s32 *)(self + 8));
            fn_802354A0(obj, 0, -1, x, y, zero, base, hf);
            s32 n = fn_80235FD8(obj);
            if (n >= 2) {
                f32 g = fn_80235EF0(obj, 1);
                fn_802354A0(obj, 1, -1, x - g, y, zero, g, hf);
            }
            if (n >= 3) {
                f32 g2 = fn_80235EF0(obj, 2);
                fn_802354A0(obj, 2, -1, x + base, y, zero, g2, hf);
            }
        }
        break;
    }
    case 8: {
        s32 obj = *(s32 *)(self + 0x248);
        if (obj != 0) {
            s32 sel;
            if (*(s32 **)(self + 0x24C) != 0)
                sel = **(s32 **)(self + 0x24C);
            else
                sel = *(s32 *)(self + 0x250);
            if (sel % 2 == 0) {
                f32 size = lbl_805634C8;
                f32 t = (f32)fn_8002EFB4(fn_8023659C(), lbl_805634D0);
                f32 s = (f32)sin(lbl_805634D8 * t);
                f32 amp = size * (lbl_805634C4 + lbl_805634C4 * s) - size * lbl_805634C4;
                s32 w = ((VfObj *)self)->vf28();
                s32 h = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
                fn_802354A0(obj, sel, -1, x - lbl_805634C4 * amp, y + lbl_805634C4 * amp, lbl_805634A8, amp + (f32)w, amp + (f32)h);
            } else {
                s32 w = ((VfObj *)self)->vf28();
                s32 h = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
                fn_802354A0(obj, sel, -1, x, y, lbl_805634A8, (f32)w, (f32)h);
            }
        }
        break;
    }
    case 3:
    case 6: {
        s32 obj = *(s32 *)(self + 0x248);
        if (obj != 0) {
            s32 sel;
            if (*(s32 **)(self + 0x24C) != 0)
                sel = **(s32 **)(self + 0x24C);
            else
                sel = *(s32 *)(self + 0x250);
            if (self[0x280] != 0) {
                f32 hh = fn_80235F64(obj, sel);
                f32 ww = fn_80235EF0(obj, sel);
                fn_802354A0(obj, sel, -1, x, y, lbl_805634A8, ww, hh);
            } else {
                s32 w = ((VfObj *)self)->vf28();
                s32 h = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
                fn_802354A0(obj, sel, -1, x, y, lbl_805634A8, (f32)w, (f32)h);
            }
        }
        break;
    }
    case 2:
        if (*(s32 *)(self + 0x248) != 0)
            fn_802304EC(*(s32 *)(self + 0x258), *(s32 *)(self + 0x248), *(s32 *)(self + 0x254), 9, x, y,
                        zero, *(f32 *)(self + 0x27C), (f32)*(s32 *)(self + 0x250), time, lbl_805634C0);
        break;
    case 4:
        if (*(s32 *)(self + 0x248) != 0)
            fn_80230650(*(s32 *)(self + 0x258), *(s32 *)(self + 0x248), *(s32 *)(self + 0x254), 0x41, x, y,
                        zero, *(f32 *)(self + 0x27C), (f32)*(s32 *)(self + 0x250), time, lbl_805634DC);
        break;
    case 5:
        if (*(s32 *)(self + 0x248) != 0)
            fn_802307AC(*(s32 *)(self + 0x258), *(s32 *)(self + 0x248), *(s32 *)(self + 0x254), 9, x, y,
                        zero, *(f32 *)(self + 0x27C), (f32)*(s32 *)(self + 0x250), time, lbl_805634E0);
        break;
    case 7: {
        s32 w = ((VfObj *)self)->vf28();
        s32 h = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
        ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(*(s32 *)(self + 0x254), x, y, x + (f32)w, y - (f32)h, zero);
        break;
    }
    }
}

#pragma pop
extern "C" void fn_80219AB4(void *, s32, s32, s32, s32, s32, s32);
extern "C" u8 lbl_8033F3B0[];
extern "C" u8 lbl_8033F434[];
extern "C" void *fn_8021A5B8(void *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, f32 arg5) {
    fn_80218F34(arg0, 0, 0, 0, 0, (s32)arg5);
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(void **)arg0 = lbl_8033F3B0;
    *(f32 *)((u8 *)arg0 + 0x24C) = arg5;
    *(u8 *)((u8 *)arg0 + 0x250) = arg2;
    *(u8 *)((u8 *)arg0 + 0x251) = arg3;
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    *(s32 *)((u8 *)arg0 + 0x244) = 0;
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021A650(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8021A6A8(void *arg0) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((u8 *)arg0 + 0x244);
    if (temp_r0 != 0) {
        fn_8022FFE8(temp_r0);
        fn_8022F8CC(*(s32 *)((u8 *)arg0 + 0x244));
    }
}

extern "C" void fn_8021A6EC(void *arg0) {
    u8 *p = (u8 *)arg0;
    *(u8 *)(p + 0x250) = 1;
    *(u8 *)(p + 0x251) = 1;
    *(f32 *)(p + 0x24C) = 30.0f;
    *(s32 *)(p + 0x254) = 1;
    *(s32 *)(p + 0x244) = fn_8022F638(*(s32 *)(p + 0x248), 1, 1, 1, 30.0f);
}

extern "C" void fn_8022F824(s32);
extern "C" void fn_8021A744(void *arg0) {
    fn_8022F824(*(s32 *)((u8 *)arg0 + 0x244));
    *(s32 *)((u8 *)arg0 + 0x244) = 0;
}

extern "C" int lbl_8033F324[];
extern "C" void *fn_8021A77C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_80222340(arg0, arg1, arg2, 0, 0, 0, arg5);
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    *(void **)arg0 = lbl_8033F324;
    *(s32 *)((u8 *)arg0 + 0x258) = arg3;
    if (arg4 != 0) {
        fn_80219440(arg0, 0, (void *)arg4, 4);
    }
    return arg0;
}

extern "C" s32 fn_8022F638(s32, s32, s32, s32, f32);
extern "C" s32 fn_8022F8CC(s32);
extern "C" s32 fn_8022FFE8(s32);
extern f32 lbl_805634E4;
#pragma dont_inline on
extern "C" s32 fn_8021A804(void *arg0, s32 arg1) {
    return fn_802192A4(arg0, arg1);
}

/* Cursor-bound icon widget (0x25C bytes), built by fn_8021A808 (vtable
 * lbl_8033F298, UI layout node types 16 and 27 in fn_80211690) and by the plain
 * fn_8021A77C (vtable lbl_8033F324), which watches only the cursor.  The base
 * widget (fn_80222340) keeps its box at +0x04/+0x08, the values it watches at
 * +0x30 (stride 0x10, count +0x230, added by fn_80219440), the drawer that
 * names the graphic to draw at +0x244 and where to draw it at
 * +0x248/+0x24C/+0x250.  This class adds the binding: +0x254 points at the
 * selection the menu cursor writes and +0x258 is the entry this widget stands
 * for, so fn_8021AA18 draws it full size only while *cursor == cursorId, and
 * dims it while the UI mode byte behind fn_80216708() is clear. */
struct CursorIconWidget {
    void *vtable;        /* 0x00 */
    u8 _04[0x254 - 0x04];
    s32 *cursor;         /* 0x254: selection the menu cursor writes; NULL when unbound */
    s32 cursorId;        /* 0x258: the entry this widget stands for */
};

extern "C" int lbl_8033F298[];
extern "C" void *fn_8021A808(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_80222340(arg0, arg1, arg2, 0, 0, 0, arg5);
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    *(void **)arg0 = lbl_8033F298;
    *(s32 *)((u8 *)arg0 + 0x258) = arg3;
    if (arg4 != 0) {
        fn_80219440(arg0, 0, (void *)arg4, 4);
    }
    fn_80219440(arg0, 1, fn_80216708(), 1);
    return arg0;
}

#pragma dont_inline reset
extern "C" void *fn_8021D044(void *, s32, s32, s32, const char *, s32, s32, s32, s32);
extern "C" s32 fn_8022A86C(void *);
extern "C" void fn_8021818C(s32);
extern "C" void fn_80218198(s32, void *);
extern "C" void fn_8021A8A8(void *arg0) {
    struct Dispatch {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
        virtual void d24(); virtual void d25(); virtual void d26();
        virtual void call(s32, s32);
    };
    ((Dispatch *)arg0)->call(2, 0);
    fn_8021818C(*(s32 *)((u8 *)arg0 + 0x2C));
    if (*(s32 *)*(s32 **)((u8 *)arg0 + 0x254) == *(s32 *)((u8 *)arg0 + 0x258))
        fn_80218198(*(s32 *)((u8 *)arg0 + 0x2C), arg0);
}

extern "C" void fn_8021A910(void *arg0, s32 arg1) {
    s32 temp_r6 = *(s32 *)((u8 *)arg0 + 0x258);
    if (*(s32 *)*(s32 **)((u8 *)arg0 + 0x254) == temp_r6) {
        fn_80218968(*(s32 *)((u8 *)arg0 + 0x2C), temp_r6,
                    arg1 == 2 ? lbl_805634A8 : lbl_805634E8);
    } else {
        fn_8021889C(*(s32 *)((u8 *)arg0 + 0x2C), temp_r6,
                    arg1 == 2 ? lbl_805634A8 : lbl_805634E8);
    }
    ((VfObj *)arg0)->vf31();
}

#pragma scheduling invalid_target
extern "C" s32 fn_8021A9A4(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned int flag = *(unsigned char *)fn_80216708();
    s32 second, first = 0;
    s32 *p;
    if (flag != 0)
        first = 2;
    p = *(s32 **)(base + 0x254);
    second = 0;
    if (p != 0 && *p == *(s32 *)(base + 0x258))
        second = 1;
    return (s32)(((unsigned int)((-second) | second)) >> 31) | first;
}
#pragma scheduling on
extern "C" void fn_8021AA18(void *arg0) {
    struct State { u32 a[12]; f32 x, y, z; } state;
    u32 *src = (u32 *)fn_8022EDC4();
    s32 selected = 0;
    u32 t0; u32 t1;
    t1 = src[0];
    t0 = src[1];
    state.a[0] = t1;
    state.a[1] = t0;
    t0 = src[2]; t1 = src[3];
    state.a[2] = t0;
    state.a[3] = t1;
    t0 = src[4]; t1 = src[5];
    state.a[4] = t0;
    state.a[5] = t1;
    t0 = src[6]; t1 = src[7];
    state.a[6] = t0;
    state.a[7] = t1;
    state.a[8] = src[8];
    t0 = src[9]; t1 = src[10];
    state.a[9] = t0;
    state.a[10] = t1;
    state.a[11] = src[11];
    state.x = ((f32 *)src)[12];
    state.y = ((f32 *)src)[13];
    state.z = ((f32 *)src)[14];
    struct Callback { virtual void first(); virtual void call(s32, s32, s32, s32, s32, s32); };
    u8 *p = (u8 *)arg0;
    s32 *cursor = *(s32 **)(p + 0x254);
    if (cursor && *cursor == *(s32 *)(p + 0x258)) selected = 1;
    if (((u8 *)fn_80216708())[0] == 0 && selected == 0) state.x *= lbl_805634E8;
    fn_8022ED00((s32 *)&state);
    s32 h;
    s32 delta;
    s32 w;
    delta = *(s32 *)(p + 0x10) - *(s32 *)(p + 8);
    h = ((VfObj *)arg0)->vf32();
    w = ((VfObj *)arg0)->vf28();
    ((Callback *)*(void **)(p + 0x244))->call(
        *(s32 *)(p + 0x248), *(s32 *)(p + 0x24C), *(s32 *)(p + 0x250), w, delta, h);
    fn_8022EDB8();
}

extern "C" s32 fn_8021AB88(void) { return 0; }

#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_8021AB90(void *arg0, s32 arg1) {
    if (*(u8 *)fn_80216708() == 0)
        goto fallback;
    if (arg1 == 0x127)
        goto fallback;
    if (arg1 >= 0x127)
        goto checkUpper;
    if (arg1 < 0x126)
        goto fallback;
    goto callLower;
checkUpper:
    if (arg1 < 0x129)
        goto callUpper;
    goto fallback;
callLower:
    fn_80217AC0(*(s32 *)((u8 *)arg0 + 0x2C));
    return 1;
callUpper:
    fn_802179A0(*(s32 *)((u8 *)arg0 + 0x2C));
    return 1;
fallback:
    return fn_802192A4(arg0, arg1);
}
#pragma scheduling on
#pragma pop
extern "C" void *fn_8021AC24(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base = (u8 *)arg0;
    s32 a = fn_802C5220(arg3);
    s32 b = fn_802C51C0(arg3);
    fn_80218F34(arg0, arg1, arg2, arg1 + b, arg2 + a, 0);
    f32 fb = lbl_805634E8;
    f32 fa = lbl_805634A8;
    *(void **)base = lbl_8033F6E0;
    *(s32 *)(base + 0x250) = arg3;
    *(u8 *)(base + 0x244) = 0;
    *(f32 *)(base + 0x248) = fa;
    *(f32 *)(base + 0x24C) = fb;
    return arg0;
}

extern "C" void fn_8021ACC0(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250));
    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250)) > 0)
        fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250));
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021AD10(void *arg0) {
    s32 value;
    s32 screenX;
    s32 screenY;

    if (*(u8 *)((u8 *)arg0 + 0x18) != 0) {
        value = (*(u8 *)((u8 *)arg0 + 0x244) != 0) + 2;
    } else {
        value = 0;
    }

    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250)) == 3 && value == 3) {
        value = 1;
    }

    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250)) > 0) {
        value %= fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250));
    }

    screenX = *(s32 *)((u8 *)arg0 + 4) -
        ((s32)(lbl_8055FB9C + ((u32)lbl_8055FB9C >> 31)) >> 1);
    screenY = ((s32)(lbl_8055FBA0 + ((u32)lbl_8055FBA0 >> 31)) >> 1) -
        *(s32 *)((u8 *)arg0 + 8);

    fn_802C5310(*(s32 *)((u8 *)arg0 + 0x250), value,
        (f32)screenX, (f32)screenY, lbl_805634A8);
}
#pragma scheduling on
#pragma pop
extern "C" f32 lbl_805634EC;

// View of the animated widget class fn_8021AE18 belongs to: +0x248 counts down
// to the next update and +0x24C is how long one update step lasts (the
// constructor fn_8021AC24 starts them at 0.0 and 0.3).
struct AnimClock_8021AE18 {
    void *vtable;                 // 0x00
    u8 pad_0x04[0x18 - 0x04];
    u8 visible;                   // 0x18 drawn this frame
    u8 pad_0x19[0x244 - 0x19];
    u8 animating;                 // 0x244 clock running
    u8 pad_0x245[0x248 - 0x245];
    f32 time;                     // 0x248 time left before the next update
    f32 step;                     // 0x24C length of one update step
};

// Advances the widget's animation clock by the frame time and calls its
// virtual Update (vtable slot 0x84) once per elapsed step, at most 11 catch-up
// steps; every step run shortens itself to 1 / (2 + 1 / step), so a widget
// that fell behind eases back onto the frame rate. A stopped or hidden clock
// just restarts at 0.0 / 0.3.
#pragma push
#pragma processor 750
extern "C" void fn_8021AE18(AnimClock_8021AE18 *clock) {
    struct Dispatch {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30();
        virtual void Update(f32);
    };
    register f32 two;
    register f32 one;
    register f32 zero;
    if (clock->animating != 0 && clock->visible != 0) {
        f32 frameTime = fn_80214D48();
        f32 time = clock->time;
        zero = *(volatile f32 *)&lbl_805634A8;
        time -= frameTime;
        clock->time = time;
        if (time < zero) {
            one = lbl_805634A4;
            two = lbl_805634EC;
            s32 catchUps = 10;
            goto loop_test;
        loop_body:
            register f32 updateAt = clock->time;
            clock->time = updateAt + clock->step;
            ((Dispatch *)clock)->Update(updateAt);
            clock->step = one / (two + one / clock->step);
            catchUps--;
            if (catchUps < 0)
                goto done;
        loop_test:
            if (clock->time < zero)
                goto loop_body;
        done:
            clock->time = clock->step;
        }
    } else {
        f32 initialStep;
        f32 initialTime;
        initialTime = lbl_805634A8;
        initialStep = lbl_805634E8;
        clock->time = initialTime;
        clock->step = initialStep;
    }
}
#pragma pop
extern "C" void *fn_8021AF0C(void *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 x, f32 y) {
    fn_8021AC24(arg0, a1, a2, a6, a4);
    *(s32 *)((u8 *)arg0 + 0x254) = a3;
    *(void **)arg0 = lbl_8033F658;
    *(f32 *)((u8 *)arg0 + 0x258) = x;
    *(f32 *)((u8 *)arg0 + 0x25C) = y;
    *(s32 *)((u8 *)arg0 + 0x260) = a4;
    *(s32 *)((u8 *)arg0 + 0x264) = a5;
    return arg0;
}
#pragma dont_inline reset
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021AF9C(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern double lbl_805634B8;
extern float lbl_805634C4;
#pragma scheduling invalid_target
extern "C" void fn_8021AFF4(void *arg0) {
    f32 step = (*(f32 *)((u8 *)arg0 + 0x25C) - *(f32 *)((u8 *)arg0 + 0x258)) / (f32)(*(s32 *)((u8 *)arg0 + 0x260) - 1);
    *(f32 *)*(void **)((u8 *)arg0 + 0x254) += (f32)*(s32 *)((u8 *)arg0 + 0x264) * step;
    *(f32 *)*(void **)((u8 *)arg0 + 0x254) = step * (f32)(s32)((*(f32 *)*(void **)((u8 *)arg0 + 0x254) / step) + lbl_805634C4);
    if (*(f32 *)*(void **)((u8 *)arg0 + 0x254) < *(f32 *)((u8 *)arg0 + 0x258)) {
        *(f32 *)*(void **)((u8 *)arg0 + 0x254) = *(f32 *)((u8 *)arg0 + 0x258);
    }
    if (*(f32 *)*(void **)((u8 *)arg0 + 0x254) > *(f32 *)((u8 *)arg0 + 0x25C)) {
        *(f32 *)*(void **)((u8 *)arg0 + 0x254) = *(f32 *)((u8 *)arg0 + 0x25C);
    }
}
#pragma scheduling on
extern "C" char lbl_8033F5D0[];
#pragma dont_inline on
extern "C" void *fn_8021B0CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    fn_8021AC24(arg0, arg1, arg2, arg7, arg4);
    *(void **)arg0 = lbl_8033F5D0;
    *(s32 *)((u8 *)arg0 + 0x254) = arg3;
    *(s32 *)((u8 *)arg0 + 0x258) = arg4;
    *(s32 *)((u8 *)arg0 + 0x25C) = arg5;
    *(s32 *)((u8 *)arg0 + 0x260) = arg6;
    return arg0;
}
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021B134(void *arg0) {
    register s32 *p = *(s32 **)((u8 *)arg0 + 0x254);
    s32 increment = *(s32 *)((u8 *)arg0 + 0x260);
    s32 value = *p;
    s32 end;
    s32 start;
    start = *(s32 *)((u8 *)arg0 + 0x258);
    end = *(s32 *)((u8 *)arg0 + 0x25C);
    *p = value + increment;
    s32 *check = *(s32 **)((u8 *)arg0 + 0x254);
    int flag = end - start - 2 == 0;
    if (*check >= *(s32 *)((u8 *)arg0 + 0x25C)) {
        if (flag)
            *check = *(s32 *)((u8 *)arg0 + 0x258);
        else
            *check = *(s32 *)((u8 *)arg0 + 0x25C) - 1;
    }
    if (*(*(s32 **)((u8 *)arg0 + 0x254)) < *(s32 *)((u8 *)arg0 + 0x258)) {
        if (flag)
            *(*(s32 **)((u8 *)arg0 + (u32)0x254)) = *(s32 *)((u8 *)arg0 + 0x25C) - 1;
        else
            *(*(s32 **)((u8 *)arg0 + 0x254)) = *(s32 *)((u8 *)arg0 + 0x258);
    }
}
#pragma scheduling on
#pragma pop
extern "C" void *fn_8021B1C4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *vtable;

    fn_8021AC24(arg0, arg1, arg2, arg5, arg4);
    vtable = lbl_8033F548;
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    *(void **)arg0 = vtable;
    *(s32 *)((u8 *)arg0 + 0x258) = arg3;
    return arg0;
}
#pragma dont_inline reset

extern "C" char lbl_8033F20C[];
extern "C" void fn_8021B224(void *arg0) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r0_2;
    s32 temp_r4_2;
    void *temp_r5;
    void *temp_r5_2;
    if (*(s32 *)((u8 *)arg0 + 0x254) == 1) {
        temp_r5 = *(void **)((u8 *)arg0 + 0x258);
        temp_r4 = *(s32 *)((u8 *)temp_r5 + 8) + 1;
        *(s32 *)((u8 *)temp_r5 + 8) = temp_r4;
        temp_r0 = *(s32 *)temp_r5 - *(s32 *)((u8 *)temp_r5 + 4);
        if (temp_r4 > temp_r0)
            *(s32 *)((u8 *)temp_r5 + 8) = temp_r0;
        if (*(s32 *)((u8 *)temp_r5 + 8) < 0)
            *(s32 *)((u8 *)temp_r5 + 8) = 0;
    } else {
        temp_r5_2 = *(void **)((u8 *)arg0 + 0x258);
        temp_r4_2 = *(s32 *)((u8 *)temp_r5_2 + 8) - 1;
        *(s32 *)((u8 *)temp_r5_2 + 8) = temp_r4_2;
        temp_r0_2 = *(s32 *)temp_r5_2 - *(s32 *)((u8 *)temp_r5_2 + 4);
        if (temp_r4_2 > temp_r0_2)
            *(s32 *)((u8 *)temp_r5_2 + 8) = temp_r0_2;
        if (*(s32 *)((u8 *)temp_r5_2 + 8) < 0)
            *(s32 *)((u8 *)temp_r5_2 + 8) = 0;
    }
}

#pragma dont_inline fn_80219568
extern "C" void *fn_8021B2B0(void *arg0, s32 arg1, s32 arg2, const char *arg3, s32 arg4, s32 arg5, s32 arg6) {
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))fn_80219568)(arg0, arg1, arg2, arg6, arg4, 0, 0);
    *(s32 *)((u8 *)arg0 + 0x254) = (s32)arg3;
    *(void **)arg0 = lbl_8033F20C;
    strcpy((char *)arg0 + 0x268, arg3);
    *(s32 *)((u8 *)arg0 + 0x264) = arg5;
    fn_80219718(arg0);
    return arg0;
}
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_8021B32C(void *arg0) {
    s32 temp_r31;
    fn_802192AC(arg0);
    temp_r31 = *(s32 *)((u8 *)arg0 + 0x254);
    if (strcmp((char *)temp_r31, (char *)arg0 + 0x268) != 0) {
        strcpy((char *)arg0 + 0x268, (char *)temp_r31);
        fn_80219718(arg0);
        if (*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
            *(u8 *)((u8 *)arg0 + 0x234) = 1;
        }
    }
}

#pragma dont_inline reset

extern "C" s32 fn_8021B3A0(void *arg0) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x264);
    if (p != 0) return *p;
    return 0;
}

extern "C" s32 fn_802C3424(s32, s32, s32, s32, s32);
extern "C" void fn_8021B3BC(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    fn_802C3424(*(s32 *)((u8 *)arg0 + 0x244), *(s32 *)((u8 *)arg0 + 0x248), *(s32 *)((u8 *)arg0 + 0x24C), *(s32 *)((u8 *)arg0 + 0x250), *(s32 *)((u8 *)arg0 + 0x254));
}

extern "C" s32 fn_80128668(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8021B404(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma dont_inline on
extern "C" void *fn_8021B460(void *arg0, void *arg1, s32 arg2, s32 arg3) {
union Scratch { volatile u32 zeros[22]; u8 bytes[0x58]; } scratch;
u8 *parms = scratch.bytes;
volatile u32 *zp = (volatile u32 *)(scratch.bytes - 4);
f32 matrix[12];
f32 matrix2[9];
volatile f32 vector[3];
f32 rot[3];
volatile f32 pad[3];
f32 transformed[3];
f32 vector2[3];
volatile f32 *input;
f32 *output;
s32 i, made;
fn_8021B2B0(arg0, *(s32 *)((u8 *)arg1 + 8), *(s32 *)((u8 *)arg1 + 0xC),
(const char *)arg2, 8, arg3, *(s32 *)((u8 *)arg1 + 0x10));
*(void **)arg0 = (void *)&lbl_8033F180;
for (i = 11; i--; ) { zp[1] = 0; *(zp += 2) = 0; }
*(u8 *)((u8 *)arg0 + 0x36C) = (u8)((u32)*(s32 *)((u8 *)arg1 + 4) >> 31);
*(void **)(parms + 0) = (u8 *)arg1 + 0x20;
*(f32 *)(parms + 4) = *(f32 *)((u8 *)arg1 + 0x1C);
*(s32 *)(parms + 8) = *(s32 *)((u8 *)arg1 + 4);
*(s32 *)(parms + 0xC) = *(s32 *)((u8 *)arg1 + 0x90);
*(s32 *)(parms + 0x10) = *(s32 *)((u8 *)arg1 + 0x90);
*(s32 *)(parms + 0x1C) = *(s32 *)((u8 *)arg1 + 0x84);
*(s32 *)(parms + 0x28) = *(s32 *)((u8 *)arg1 + 0x94);
*(s32 *)(parms + 0x2C) = *(s32 *)((u8 *)arg1 + 0x94);
*(s32 *)(parms + 0x38) = *(s32 *)((u8 *)arg1 + 0x84);
made = fn_8022A86C(parms);
*(s32 *)((u8 *)arg0 + 0x368) = made;
*(s32 *)((u8 *)arg0 + 0x250) = made;
fn_80219718(arg0);
matrix[0]=lbl_805634A4; matrix[1]=lbl_805634A8; matrix[2]=lbl_805634A8; matrix[3]=lbl_805634A8;
matrix[4]=lbl_805634A4; matrix[5]=lbl_805634A8; matrix[6]=lbl_805634A8; matrix[7]=lbl_805634A8;
matrix[8]=lbl_805634A4; matrix[9]=lbl_805634A8; matrix[10]=lbl_805634A8; matrix[11]=lbl_805634A8;
vector[0]=(f32)*(s32 *)((u8 *)arg1+8)-lbl_805634F0;
vector[1]=lbl_805634F4-(f32)*(s32 *)((u8 *)arg1+0xC);
vector[2]=0.0f;
pad[0]=0.0f; pad[1]=0.0f; pad[2]=0.0f;
input=vector; output=transformed;
if (output == input) {
output[0]=input[2]*lbl_805634A8 + (input[0]*lbl_805634A4 + input[1]*lbl_805634A8);
output[1]=input[2]*lbl_805634A8 + (input[0]*lbl_805634A8 + input[1]*lbl_805634A4);
output[2]=input[2]*lbl_805634A4 + (input[0]*lbl_805634A8 + input[1]*lbl_805634A8);
} else {
output[0]=input[2]*lbl_805634A8 + (input[0]*lbl_805634A4 + input[1]*lbl_805634A8);
output[1]=input[2]*lbl_805634A8 + (input[0]*lbl_805634A8 + input[1]*lbl_805634A4);
output[2]=input[2]*lbl_805634A4 + (input[0]*lbl_805634A8 + input[1]*lbl_805634A8);
}
matrix[9]=matrix[9]+transformed[0]; matrix[10]=matrix[10]+transformed[1]; matrix[11]=matrix[11]+transformed[2];
memcpy(vector2+2,(u8 *)arg1+0xA4,4);
memcpy(vector2+1,(u8 *)arg1+0xA8,4);
memcpy(vector2,(u8 *)arg1+0xAC,4);
if(lbl_805634A8==vector2[2] && lbl_805634A8==vector2[1] && lbl_805634A8==vector2[0]) {
*(s32 *)((u8 *)arg0+0x370)=0;
} else {
rot[0]=lbl_805634F8*vector2[2];
rot[1]=lbl_805634F8*vector2[1];
rot[2]=lbl_805634F8*vector2[0];
((void (*)(void *,f32 *))fn_80015A20)((void *)matrix2,rot);
fn_80015B20(matrix,(void *)matrix2,matrix);
vector[0]=-vector[0]; vector[1]=-vector[1];
transformed[0]=matrix[0]*vector[0]+matrix[3]*vector[1]+matrix[6]*vector[2];
transformed[1]=matrix[1]*vector[0]+matrix[4]*vector[1]+matrix[7]*vector[2];
transformed[2]=matrix[2]*vector[0]+matrix[5]*vector[1]+matrix[8]*vector[2];
matrix[9]+=transformed[0]; matrix[10]+=transformed[1]; matrix[11]+=transformed[2];
*(s32 *)((u8 *)arg0+0x370)=((s32 (*)(f32 *,f32))fn_8022EDE4)(matrix,lbl_805634A4);
}
return arg0;
}

extern "C" void *fn_8021B8AC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        void *ptr = *(void **)((u8 *)arg0 + 0x370);
        *(void **)arg0 = lbl_8033F180;
        if (ptr != 0) {
            fn_8022EE98(ptr);
            *(void **)((u8 *)arg0 + 0x370) = 0;
        }
        fn_8022A8E4(*(s32 *)((u8 *)arg0 + 0x368));
        if (arg0 != 0) {
            if (arg0 != 0) {
                fn_8021915C(arg0, 0);
            }
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma dont_inline reset
extern "C" void fn_8021B944(void *arg0) {
    u8 sp8[0x40];
    if (*(void **)((u8 *)arg0 + 0x370) != 0) {
        fn_8022EEF8(sp8, (s32)*(void **)((u8 *)arg0 + 0x370), fn_8022EDC4());
        fn_8022ED00(sp8);
    }
    fn_80219660(arg0);
    if (*(void **)((u8 *)arg0 + 0x370) != 0) {
        fn_8022EDB8();
    }
}

extern "C" void fn_8021BA64(void *, s32, s32, s32, s32, void *, s32, s32, s32, s32, s32, s32, s32);

#pragma push
#pragma small_data off
extern "C" void *fn_8021B9AC(void *self, void *desc, s32 arg2, s32 arg3) {
    /* Construct an object from descriptor fields, set vtable lbl_8033F0FC, and initialize via fn_8021BA64. */
    fn_80218F80();
    *(u32 *)self = (u32)(void *)&lbl_8033F0FC;
    fn_8021BA64(
        self,
        *(s32 *)((u8 *)desc + 0x14),
        *(s32 *)((u8 *)desc + 0x18),
        arg2,
        arg3,
        (u8 *)desc + 0x20,
        *(s32 *)((u8 *)desc + 4),
        *(s32 *)((u8 *)desc + 0x90),
        *(s32 *)((u8 *)desc + 0xA4),
        *(s32 *)((u8 *)desc + 0x94),
        *(s32 *)((u8 *)desc + 0x98),
        (s32)*(f32 *)((u8 *)desc + 0x1C),
        *(s32 *)((u8 *)desc + 0x84));
    return self;
}

extern "C" char lbl_8055B878;
extern "C" void fn_8022D924(void *, s32);
/* Initializes a render/texture setup record (arg0) with stride/sizing derived from format flags and calls setup helpers. */
extern "C" void fn_8021BA64(void *setup, s32 width, s32 arg2, s32 buffer, s32 arg4, void *data,
                              s32 formatFlags, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 height, s32 arg12) {
    s32 halfWidth = 0;
    s32 halfHeight = 0;
    s32 stride;

    *(s32 *)((u8 *)setup + 0x25C) = arg4;
    *(s32 *)((u8 *)setup + 0x254) = buffer;
    *(s32 *)((u8 *)setup + 0x250) = height;
    *(s32 *)((u8 *)setup + 0x258) = 0;

    if (formatFlags & 4)
        halfWidth = width / 2;
    else if (formatFlags & 2)
        halfWidth = width;

    if (formatFlags & 0x60)
        halfHeight = height;
    else if (formatFlags & 0x10)
        halfHeight = height / 2;

    s32 params[22] = {0};
    params[0] = (s32)data;
    params[2] = formatFlags;
    params[3] = arg7;
    params[4] = arg10;
    params[5] = arg12;
    params[6] = halfWidth;
    params[7] = halfHeight;
    params[10] = arg9;
    params[11] = arg10;
    params[12] = arg12;
    params[13] = halfWidth;
    params[14] = halfHeight;

    stride = fn_8022A86C(params);
    *(s32 *)((u8 *)setup + 0x244) = stride;
    stride = fn_8022B620(stride, &lbl_8055B878) - 0x17;
    *(s32 *)((u8 *)setup + 0x260) = stride / 2;
    fn_80219440(setup, 0, (u8 *)buffer + 0x24, 4);
    fn_8022D924((void *)buffer, arg2 / height);
}

#pragma pop
extern "C" void fn_8022A8E4(s32);
extern "C" void fn_8021BA64(void *, s32, s32, s32, s32, void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8022EDC4(void);
extern "C" void fn_8022EEF8(void *, s32, s32);
extern "C" void fn_8022ED00(void *);
extern "C" void fn_8022EDB8(void);
#pragma push
#pragma small_data off
extern "C" void *fn_8021BBA0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033F0FC;
        fn_8022A8E4(*(s32 *)((u8 *)arg0 + 0x244));
        {
            void *ptr = *(void **)((u8 *)arg0 + 0x258);
            if (ptr != 0) {
                fn_802C519C(ptr);
            }
        }
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma pop
extern "C" s32 fn_8022D850(void *, s32, s32, s32 *);
extern f32 lbl_805634FC;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021BC20(void *arg0, void *arg1) {
    s32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    void *temp_r4_2;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r28;
    s32 var_r27;
    s32 var_r26;
    s32 temp_r25;
    s32 var_r29;
    s32 temp_r30;

    temp_r4_2 = *(void **)((u8 *)arg0 + 0x254);
    temp_r28 = *(s32 *)((u8 *)arg0 + 4);
    temp_r5 = *(s32 *)((u8 *)temp_r4_2 + 0x10);
    temp_r30 = *(s32 *)((u8 *)temp_r4_2 + 0x20);
    temp_r4 = *(s32 *)((u8 *)temp_r4_2 + 8);
    var_r26 = temp_r30 * temp_r5;
    var_r27 = *(s32 *)((u8 *)arg0 + 8);
    var_r29 = var_r26 + temp_r5;
    if (temp_r4 >= var_r29) {
        return;
    }
    var_r29 = temp_r4;
    temp_r30 = 0;

    for (; var_r26 < var_r29;
         var_r26++, var_r27 += *(s32 *)((u8 *)arg0 + 0x250)) {
        sp18 = temp_r30;
        temp_r25 = fn_8022D850(*(void **)((u8 *)arg0 + 0x254),
            var_r26, *(s32 *)((u8 *)arg0 + 0x25C), &sp18);
        if (sp18 > 2) {
            sp18 -= 3;
            fn_80230C30(&sp14, &sp10, temp_r28 - 0x1C,
                var_r27 + *(s32 *)((u8 *)arg0 + 0x260));
            if (*(s32 *)((u8 *)arg0 + 0x258) != 0) {
                fn_802C5320(*(s32 *)((u8 *)arg0 + 0x258),
                    sp18 % fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x258)),
                    sp14, sp10, lbl_805634A8, lbl_805634FC, lbl_805634FC);
            }
        }
        sp8 = temp_r30;
        ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32, f32))fn_8022BAD0)(
            *(s32 *)((u8 *)arg0 + 0x244), temp_r28, var_r27,
            0, 0, 0, temp_r25, sp18, sp8, lbl_805634A4);
    }
}
#pragma scheduling on
#pragma pop
extern "C" void fn_8021BD48(void *arg0, s32 arg1) {
 fn_802C3034(arg1);
 ((void (*)(s32, ...))fn_801E4BEC)(*(s32 *)((u8 *)arg0+0x348),0,9,*(s32 *)((u8 *)arg0+4),*(s32 *)((u8 *)arg0+8),*(s32 *)((u8 *)arg0+0x244));
}

/* Text readout widget (0x2B4 bytes), built by fn_8021CEEC (vtable lbl_8033ECB8,
 * UI layout node type 7, alloc tag lbl_8033CAE8 + 0x44C) and by fn_8021BD98
 * (vtable lbl_8033EF68).  The base widget (fn_80218F34 / fn_80219568) keeps its box
 * at +0x04/+0x08 (left/top) and +0x10, the values it watches at +0x30 (stride 0x10,
 * count +0x230, added by fn_80219440), a text scroll offset at +0x244/+0x248, a draw
 * style at +0x250 and a redraw request at +0x234.  This class adds the readout
 * itself: the value to show, the sprintf format to print it with, the scale/offset
 * that turn the value into the shown number, and the text.  fn_8021CEEC's class
 * reads the watched value as an s32 and prints it rounded to the nearest whole,
 * fn_8021BD98's reads it as an f32 and prints the raw value beside it. */
struct TextReadoutWidget {
    void *vtable;        /* 0x00 */
    u8 _04[0x1A - 0x04];
    u8 live;             /* 0x1A: bound to a live value, so ask for a redraw */
    u8 _1B[0x234 - 0x1B];
    u8 redraw;           /* 0x234: set to ask the screen to redraw this widget */
    u8 _235[0x244 - 0x235];
    s32 scrollX;         /* 0x244: how far the text is scrolled out to the left */
    s32 scrollY;         /* 0x248: ... and out to the top */
    s32 _24C;            /* 0x24C: base widget field (fn_80219568 sets it) */
    s32 style;           /* 0x250: text style/handle fn_8022AC1C draws with */
    f32 scale;           /* 0x254: multiplies the watched value */
    f32 offset;          /* 0x258: added to the scaled value */
    void *value;         /* 0x25C: the watched value this readout shows */
    const char *format;  /* 0x260: sprintf format, from the layout node */
    char text[4];        /* 0x264: the printed text (sprintf destination) */
};

#pragma push
#pragma small_data off
extern "C" __declspec(align(32)) char lbl_8033EF68[];
#pragma scheduling invalid_target
/* Builds a floating-point text readout: after the base widget's box it installs this
   class' vtable and the readout itself - the f32 to watch, the sprintf format to
   print it with and the scale/offset that turn it into the shown number - starts
   watching the value through fn_80219440 and prints it once. */
extern "C" void *fn_8021BD98(void *object, s32 x, s32 y, void *value, const char *format,
                             s32 style, f32 scale, f32 offset) {
    TextReadoutWidget *widget = (TextReadoutWidget *)object;

    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))fn_80219568)(object, x, y, 0, style, 0, 0);
    widget->value = value;
    *(void **)object = lbl_8033EF68;
    widget->scale = scale;
    widget->offset = offset;
    widget->format = format;
    widget->text[0] = 0;
    fn_80219440(object, 0, value, 4);
    fn_8021BE48(object);
    return object;
}

#pragma dont_inline on
extern "C" void fn_8021BE48(void *arg0) {
    f32 value = *(f32 *)*(void **)((u8 *)arg0 + 0x25C);
    volatile char *buf = (char *)arg0 + 0x264;
    sprintf((char *)buf,
            *(const char **)((u8 *)arg0 + 0x260),
            *(f32 *)((u8 *)arg0 + 0x258) +
                value * *(f32 *)((u8 *)arg0 + 0x254),
            value);
    fn_80130568((char *)arg0 + 0x264);
    fn_80219718(arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}
#pragma dont_inline reset

#pragma scheduling on
extern "C" void fn_8021BEBC(void *arg0) {
    fn_8021BE48(arg0);
}

extern "C" char lbl_8033EEDC[];
extern "C" void *fn_8021BEC0(void *object, s32 x, s32 y, void *callback, s32 param4, s32 param5, s32 param6, s32 param7) {
    /* Initialize a UI/widget object, attach callback-provided data, and cache its computed id. */
    struct Callback {
        virtual void v0();
        virtual void GetData(s32 *outData, s32 *outSize);
    };
    s32 data;
    s32 size;

    fn_80219568(object, x, y, 0, param4, 0, 0, param7);
    *(void **)((u8 *)object + 0x2A4) = callback;
    *(void **)object = lbl_8033EEDC;
    *(s32 *)((u8 *)object + 0x2B0) = param5;
    *(s32 *)((u8 *)object + 0x2B4) = param6;
    *(s32 *)((u8 *)object + 0x2B8) = param7;
    ((Callback *)callback)->GetData(&data, &size);
    if (size > 0)
        fn_80219440(object, 0, (void *)data, size);
    fn_8021C12C(object);
    *(s32 *)((u8 *)object + 0x2A8) = 0;
    *(s32 *)((u8 *)object + 0x2AC) = fn_80228F40(x, y);
    return object;
}

extern "C" s32 fn_80129BC4(void);
extern "C" void *fn_80217BD8(s32, s32, void *);
extern "C" void fn_8021BE48(void *);
extern "C" void fn_8021C12C(void *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void fn_80130568(char *);
extern "C" void fn_8021BF90(void *arg0) {
    void *value;
    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C),
                            *(s32 *)((u8 *)arg0 + 0x2AC), arg0);
        *(void **)((u8 *)arg0 + 0x2A8) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 1, value, 4);
    }
}

extern "C" s32 fn_8021165C(s32, s32);
extern "C" s32 fn_802C5310(s32, s32, f32, f32, f32);
#pragma push
#pragma processor 750
/* Updates this widget and draws its two value indicators when their bounds differ (checks virtual slots 6/5 on the widget at +0x2A4). */
extern "C" void fn_8021BFEC(void *arg0) {
    struct Vf {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual s32 second();
        virtual s32 first();
    };
    f32 posX;
    f32 posY;
    s32 isActive;
    s32 *statePtr;
    s32 handleA;
    s32 handleB;
    f32 scale;

    fn_80219660(arg0);
    if (*(s32 *)((u8 *)arg0 + 0x2B0) != *(s32 *)((u8 *)arg0 + 0x2B4)) {
        statePtr = *(s32 **)((u8 *)arg0 + 0x2A8);
        isActive = 0;
        if ((statePtr != 0) && (*(s32 *)((u8 *)arg0 + 0x2AC) == *statePtr)) {
            isActive = 1;
        }
        handleA = fn_8021165C(0, 2);
        handleB = fn_8021165C(1, 2);
        scale = lbl_805634A8;
        posX = scale;
        posY = scale;
        fn_80230C30(&posX, &posY, *(s32 *)((u8 *)arg0 + 0x2B0), *(s32 *)((u8 *)arg0 + 0x2B8));
        if (((Vf *)*(void **)((u8 *)arg0 + 0x2A4))->first() != 0) {
            fn_802C5310(handleA, isActive, posX, posY, scale);
        }
        fn_80230C30(&posX, &posY, *(s32 *)((u8 *)arg0 + 0x2B4), *(s32 *)((u8 *)arg0 + 0x2B8));
        if (((Vf *)*(void **)((u8 *)arg0 + 0x2A4))->second() != 0) {
            fn_802C5310(handleB, isActive, posX, posY, scale);
        }
    }
}
#pragma pop
extern "C" void fn_8021C128(void) {
    ((void (*)())fn_8021C12C)();
}

extern "C" void fn_8021C12C(void *arg0) {
    class Local {
    public:
        virtual void a0();
        virtual void a1();
        virtual void apply(void *, s32);
    };
    void *obj;
    obj = *(void **)((u8 *)arg0 + 0x2A4);
    ((Local *)obj)->apply((u8 *)arg0 + 0x254, 0x50);
    fn_80219718(arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" char lbl_80558DC4[];
#pragma push
#pragma processor 750
/* Key handler of a widget that steps through a selector: the widget's cached
 * selection state (+0x2A8, whose value must still match the id at +0x2AC) is
 * still current, so step the selector object (+0x2A4) forward on 0x127 and back
 * on 0x125 -- when its position does not change the ends were reached and the UI
 * key sound is suppressed -- or, on 0x126/0x128, ask the screen (+0x2C) for the
 * previous/next page of its list when it holds more than one.  Returns 1 when
 * the message was handled. */
extern "C" s32 fn_8021C18C(void *widget, s32 msg) {
    /* the selector at widget+0x2A4: value() is where it stands now, moveNext()
       and movePrev() step it; two destructor slots lead its vtable, so the
       methods below sit at the offsets in the comments */
    struct Selector {
        virtual void slot08();
        virtual void slot0C();
        virtual void slot10();
        virtual f32 moveNext(); /* +0x14 */
        virtual f32 movePrev(); /* +0x18 */
        virtual void slot1C();
        virtual void slot20();
        virtual f32 value();    /* +0x24 */
    };
    f32 before;
    s32 *selection = *(s32 **)((u8 *)widget + 0x2A8);
    if (selection == 0)
        return 0;
    if (*(s32 *)((u8 *)widget + 0x2AC) != *selection)
        return 0;
    before = ((Selector *)*(void **)((u8 *)widget + 0x2A4))->value();
    switch (msg) {
    case 0x127:
        ((Selector *)*(void **)((u8 *)widget + 0x2A4))->moveNext();
        /* lbl_80558DC4 is an epsilon (0x34 read as a float, about 7e-43), so this
           is "the position did not change": fn_80216D28 mutes the UI key sound */
        if ((f32)FN8021C18C_ABS((double)(before - ((Selector *)*(void **)((u8 *)widget + 0x2A4))->value())) <= *(f32 *)&lbl_80558DC4)
            fn_80216D28();
        return 1;
    case 0x125:
        ((Selector *)*(void **)((u8 *)widget + 0x2A4))->movePrev();
        if ((f32)FN8021C18C_ABS((double)(before - ((Selector *)*(void **)((u8 *)widget + 0x2A4))->value())) <= *(f32 *)&lbl_80558DC4)
            fn_80216D28();
        return 1;
    case 0x126:
        if (*(s32 *)((u8 *)*(void **)((u8 *)widget + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)widget + 0x2C)); /* the list's previous page */
            return 1;
        }
        goto done;
    case 0x128:
        if (*(s32 *)((u8 *)*(void **)((u8 *)widget + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)widget + 0x2C)); /* and its next page */
            return 1;
        }
    }
done:
    return 0;
}
#pragma pop
extern "C" s32 fn_8021C318(void *arg0) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x2A8);
    if (p == 0) return 0;
    return *p == *(s32 *)((u8 *)arg0 + 0x2AC);
}

extern "C" void *fn_8021C344(void *self, s32 x, s32 y, void *callbackObj, s32 param4, s32 lineHeight, s32 textY, s32 flags, s32 textId, s32 mode) {
    struct Callback {
        virtual void v0();
        virtual void Call(s32 *, s32 *);
    };
    s32 textPtr;
    s32 textLen;
    s32 lineBottom;

    /* Initialize a scrollable text/list widget: configure layout and callback, fetch initial text via callback, and cache its placement. */
    fn_80219568(self, x, y, 0, param4, 0, 0, flags);
    *(void **)((u8 *)self + 0x2A4) = callbackObj;
    *(void **)self = lbl_8033EE50;
    *(s32 *)((u8 *)self + 0x2B0) = lineHeight;
    *(s32 *)((u8 *)self + 0x2B4) = textY;
    *(s32 *)((u8 *)self + 0x2B8) = flags;
    *(s32 *)((u8 *)self + 0x2C8) = textId;
    if (mode == 1) {
        *(s32 *)((u8 *)self + 0x2CC) = 0;
    } else {
        *(s32 *)((u8 *)self + 0x2CC) = 1;
    }
    *(s32 *)((u8 *)self + 0x2BC) = lineHeight;
    *(s32 *)((u8 *)self + 0x2C4) = 8;
    lineBottom = textY + fn_802C51C0(fn_8021165C(1, 2));
    *(s32 *)((u8 *)self + 0x2C0) =
        lineBottom - fn_8022B498(*(s32 *)((u8 *)self + 0x2C4), textId);
    *(u8 *)((u8 *)self + 0x2D0) = 0;
    ((Callback *)callbackObj)->Call(&textPtr, &textLen);
    if (textLen > 0) {
        fn_80219440(self, 0, (void *)textPtr, textLen);
    }
    fn_8021C6D0(self);
    *(s32 *)((u8 *)self + 0x2A8) = 0;
    *(s32 *)((u8 *)self + 0x2AC) = fn_80228F40(x, y);
    return self;
}

extern "C" void fn_8021C478(void *arg0) {
    void *value;
    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C),
                            *(s32 *)((u8 *)arg0 + 0x2AC), arg0);
        *(void **)((u8 *)arg0 + 0x2A8) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 1, value, 4);
    }
}

extern "C" void fn_8021C4D4(void *arg0) {
    register u8 *self = (u8 *)arg0;
    s32 *statusPtr;
    s32 state;
    s32 valid;
    s32 temp;
    s32 first;
    s32 second;
    f32 sp14;
    f32 sp10;
    fn_80219660((void *)self);
    statusPtr = *(s32 **)(self + 0x2A8);
    valid = 0;
    if (statusPtr != 0) {
        if (*statusPtr == *(s32 *)(self + 0x2AC))
            valid = 1;
    }
    state = *(s32 *)(self + 0x2CC);
    valid = (s32)(((u32)((-valid) | valid)) >> 31);
    if (state == 0) {
        if (*(s32 *)(self + 0x2C8) != 0) {
            ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32))fn_8022BAD0)(
                *(s32 *)(self + 0x2C4), *(s32 *)(self + 0x2BC),
                *(s32 *)(self + 0x2B8) - 3, 0, 0, 0,
                *(s32 *)(self + 0x2C8), valid, 0.0f, 1);
        }
        goto after_modes;
    }
    if (state == 1 && *(s32 *)(self + 0x2C8) != 0) {
        ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32))fn_8022BAD0)(
            *(s32 *)(self + 0x2C4), *(s32 *)(self + 0x2C0),
            *(s32 *)(self + 0x2B8) - 3, 0, 0, 0,
            *(s32 *)(self + 0x2C8), valid, 0.0f, 1);
    }
after_modes:
    if (*(s32 *)(self + 0x2B0) != *(s32 *)(self + 0x2B4) &&
        *(u8 *)(self + 0x2D0) != 0) {
        temp = 0;
        statusPtr = *(s32 **)(self + 0x2A8);
        if (statusPtr != 0 &&
            *(s32 *)(self + 0x2AC) == *statusPtr)
            temp = 1;
        first = fn_8021165C(0, 2);
        second = fn_8021165C(1, 2);
        sp14 = lbl_805634A8;
        sp10 = lbl_805634A8;
        fn_80230C30(&sp14, &sp10, *(s32 *)(self + 0x2B0), *(s32 *)(self + 0x2B8));
        if (((Fn8021C4D4VTable *)*(void **)(self + 0x2A4))->At20() != 0)
            fn_802C5310(first, temp, sp14, sp10, lbl_805634A8);
        fn_80230C30(&sp14, &sp10, *(s32 *)(self + 0x2B4), *(s32 *)(self + 0x2B8));
        if (((Fn8021C4D4VTable *)*(void **)(self + 0x2A4))->At1C() != 0)
            fn_802C5310(second, temp, sp14, sp10, lbl_805634A8);
    }
}

extern "C" void fn_8021C6D0(void *);
extern "C" void fn_8022EE98(void *);
extern "C" void *lbl_8033E248[];
extern "C" u8 lbl_8033E0BC[];
extern "C" void fn_8021C6CC(void) { ((void (*)())fn_8021C6D0)(); }

extern "C" void fn_8021C6D0(void *arg0) {
    class Local {
    public:
        virtual void a0();
        virtual void a1();
        virtual void apply(void *, s32);
    };
    void *obj;
    obj = *(void **)((u8 *)arg0 + 0x2A4);
    ((Local *)obj)->apply((u8 *)arg0 + 0x254, 0x50);
    fn_80219718(arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

/* The screen a menu item belongs to.  Its items are kept in a sorted list of
   {key, item} pairs -- the count at 0x494, the keys at 0x4A0 and the items at
   0x4A4, eight bytes per entry -- and 0x498 holds the key of the selected one. */
typedef struct MenuScreen {
    char pad000[0x494];
    s32 entryCount; /* 0x494 number of items in the list */
} MenuScreen;

/* The value a menu item shows and steps.  Two leading destructor slots, so the
   first declared method sits at 0x8. */
struct ValueWidget {
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void increment(); /* 0x14 the right arrow raises the value */
    virtual void decrement(); /* 0x18 the left arrow lowers it */
    virtual void f1C();
    virtual void f20();
    virtual f32 get(); /* 0x24 the value as it now stands */
};

/* A menu item that shows a value; while it is being edited the left/right
   arrows step that value instead of moving the selection. */
typedef struct MenuValueItem {
    char pad000[0x2C];
    MenuScreen *screen;  /* 0x2C the screen holding this item */
    char pad030[0x2A4 - 0x30];
    ValueWidget *value;  /* 0x2A4 the value the arrows step */
    s32 *selectedKey;    /* 0x2A8 -> the key the screen has selected */
    s32 key;             /* 0x2AC this item's key in the screen's list */
    char pad2B0[0x2D0 - 0x2B0];
    u8 editing;          /* 0x2D0 the arrows step the value, not the selection */
} MenuValueItem;

/* Keys a menu item's handler sees.  The arrows are the Windows virtual-key
   codes with a 0x100 base (see the TEXT_KEY_* enum further down this file);
   Return and Escape keep their plain codes. */
enum {
    MENU_KEY_RETURN = 0xD,
    MENU_KEY_ESCAPE = 0x1B,
    MENU_KEY_LEFT = 0x125,
    MENU_KEY_UP = 0x126,
    MENU_KEY_RIGHT = 0x127,
    MENU_KEY_DOWN = 0x128
};

/* The screen's "move the selection to the neighbouring item" helpers:
   fn_80217EC0(screen, axis, direction) for each of the four arrows. */
#define MoveSelectionLeft fn_802180B0
#define MoveSelectionRight fn_802180BC
#define MoveSelectionUp fn_802180C8
#define MoveSelectionDown fn_802180D4

extern "C" void fn_802180B0();
extern "C" void fn_802180BC();
extern "C" void fn_802180C8();
extern "C" void fn_802180D4();
extern "C" f32 fabsf(f32);
#pragma push
#pragma processor 750
/* Key handler of a menu item that shows a steppable value.  It only reacts
   while the screen's selection is on this item: Return starts editing and
   Escape leaves it; while editing the left/right arrows step the value and
   up/down do nothing, otherwise all four arrows move the selection to the
   neighbouring item.  A step that leaves the value where it was (it is already
   at its limit) asks for the screen's key sound to be skipped.  Returns
   whether the key was used. */
extern "C" s32 fn_8021C730(MenuValueItem *item, s32 keyCode) {
    s32 *selectedKey = item->selectedKey;
    if (!selectedKey) return 0;
    if (item->key != *selectedKey) return 0;
    f32 valueBefore = item->value->get();
    switch (keyCode) {
    case MENU_KEY_RIGHT:
        if (item->editing) {
            item->value->increment();
            if ((f32)__fabs((double)(valueBefore - item->value->get())) <= *(f32 *)&lbl_80558DC4) fn_80216D28();
            return 1;
        }
        if (item->screen->entryCount > 1) { ((void (*)(MenuScreen *))MoveSelectionRight)(item->screen); return 1; }
        break;
    case MENU_KEY_LEFT:
        if (item->editing) {
            item->value->decrement();
            if ((f32)__fabs((double)(valueBefore - item->value->get())) <= *(f32 *)&lbl_80558DC4) fn_80216D28();
            return 1;
        }
        if (item->screen->entryCount > 1) { ((void (*)(MenuScreen *))MoveSelectionLeft)(item->screen); return 1; }
        break;
    case MENU_KEY_UP:
        if (!item->editing && item->screen->entryCount > 1) { ((void (*)(MenuScreen *))MoveSelectionUp)(item->screen); return 1; }
        break;
    case MENU_KEY_DOWN:
        if (!item->editing && item->screen->entryCount > 1) { ((void (*)(MenuScreen *))MoveSelectionDown)(item->screen); return 1; }
        break;
    case MENU_KEY_RETURN:
        *(s8 *)&item->editing = !item->editing;
        return 1;
    case MENU_KEY_ESCAPE:
        if (item->editing) { item->editing = 0; return 1; }
        return 0;
    }
    return 0;
}
#pragma pop
extern "C" s32 fn_8021C974(void) { return 0; }

extern "C" void *fn_8021C97C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_8021AC24(arg0, arg1, arg2, arg3, arg4);
    *(s32 *)((u8 *)arg0 + 0x258) = arg4;
    *(void **)arg0 = lbl_8033EDC8;
    *(s32 *)((u8 *)arg0 + 0x254) = arg5;
    return (void *)((char *)arg0 + 0);
}

extern "C" void fn_8021C9D8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x258) > 0) {
        (*(Fn8021C9D8Object **)((u8 *)arg0 + 0x254))->First();
    } else {
        (*(Fn8021C9D8Object **)((u8 *)arg0 + 0x254))->Second();
    }
}

extern "C" int lbl_8033D924[];
extern "C" int lbl_8033D934[];
/* Initialize a slider/tab UI object with bounds, resource, images, and default state. */
extern "C" void *fn_8021CA0C(void *obj, s32 x, s32 y, s32 w, s32 h, void *resource) {
    s32 dim0;
    s32 dim1;
    struct Arg5Type {
        virtual void v0();
        virtual void get_dims(s32 *, s32 *);
    };

    fn_80218F34(obj, x, y, x + w, y + h, 0);
    *(void **)((u8 *)obj + 0x248) = resource;
    *(void **)obj = lbl_8033ED44;
    *(u8 *)((u8 *)obj + 0x244) = 0;
    ((Arg5Type *)resource)->get_dims(&dim0, &dim1);
    if (dim1 > 0)
        fn_80219440(obj, 0, (void *)dim0, dim1);
    *(s32 *)((u8 *)obj + 0x24C) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D924);
    *(s32 *)((u8 *)obj + 0x250) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D934);
    s32 res = ((s32 (*)(void))fn_802C51C0)();
    f32 f = lbl_805634A0;
    *(s32 *)((u8 *)obj + 0x254) = res;
    *(f32 *)((u8 *)obj + 0x258) = f;
    return obj;
}

extern "C" void fn_802C519C(void *);
extern "C" s32 fn_80128668(void *);
extern "C" void *fn_8021CAD4(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033ED44;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x24C));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x250));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling on
extern "C" void fn_8021CB4C(void *arg0, s32 arg1) {
    struct First {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void call();
    };
    struct Second {
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
        virtual s32 get();
    };
    volatile s32 spC;
    volatile s32 sp8;
    register s32 result;
    register s32 start;
    First *first;
    fn_802C3034(arg1);
    first = *(First **)((unsigned char *)arg0 + 0x248);
    first->call();
    result = ((Second *)arg0)->get();
    sp8 = 0x43300000;
    start = *(s32 *)((unsigned char *)arg0 + 0x254);
    spC = (result - start) ^ 0x80000000;
}
extern "C" void fn_8021CBBC(void *arg0) {
    register s32 x;
    register s32 y;
    f32 a;
    f32 b;
    register f32 rate;
    x = *(s32 *)((u8 *)arg0 + 4) - lbl_8055FB9C / 2;
    a = (f32)x;
    y = lbl_8055FBA0 / 2 - *(s32 *)((u8 *)arg0 + 8);
    b = (f32)y;
    fn_802C5310(*(s32 *)((u8 *)arg0 + 0x24C), 0,
                a, b - lbl_80563500, lbl_805634A8);
    rate = (*(V24x **)((u8 *)arg0 + 0x248))->get();
    x = ((VfObj *)arg0)->vf28();
    y = *(s32 *)((u8 *)arg0 + 0x254);
    x = (s32)(rate * (f32)(x - y));
    fn_80230C30(&a, &b,
                x + *(s32 *)((u8 *)arg0 + 4),
                3 + *(s32 *)((u8 *)arg0 + 8));
    fn_802C5310(*(s32 *)((u8 *)arg0 + 0x250), 0, a, b, lbl_805634A8);
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021CD04(void *arg0, s32 arg1, s32 arg2) {
    class CacheSource {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual f32 Get();
    };
    class BoundsSource {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual s32 GetWidth();
    };
    class CacheTarget {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void Set(f32);
    };
    u8 *self = (u8 *)arg0;
    if (self[0x244] == 0) {
        self[0x244] = 1;
        CacheSource *source = *(CacheSource **)(self + 0x248);
        *(f32 *)(self + 0x258) = source->Get();
    }
    s32 left = *(s32 *)(self + 4);
    if (arg1 < left - 0x20 || arg2 < *(s32 *)(self + 8) - 0x20 || arg1 > left + ((BoundsSource *)arg0)->GetWidth() + 0x20 || arg2 > *(s32 *)(self + 0x10) + 0x20) {
        CacheTarget *target = *(CacheTarget **)(self + 0x248);
        target->Set(*(f32 *)(self + 0x258));
        return;
    }
    left = *(s32 *)(self + 4);
    s32 size = *(s32 *)(self + 0x254);
    s32 width = ((BoundsSource *)arg0)->GetWidth();
    s32 denom = width - size;
    s32 numer = arg1 - left - size / 2;
    f32 fden = (f32)denom;
    f32 fnum = (f32)numer;
    register f32 amount = fnum / fden;
    register f32 value = lbl_805634A4;
    value = (value < amount) ? amount : value;
    value = (value > lbl_805634A8) ? lbl_805634A8 : value;
    CacheTarget *target = *(CacheTarget **)(self + 0x248);
    target->Set(value);
}
#pragma pop
extern "C" void fn_8021CE8C(void *arg0) {
    struct Local {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void call();
    };
    if (*(u8 *)((u8 *)arg0 + 0x244) != 0)
        ((Local *)arg0)->call();
}

extern "C" void fn_8021CEAC(void *arg0) {
    struct Dispatch {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16();
        virtual void dispatch();
    };
    ((Dispatch *)arg0)->dispatch();
    *(u8 *)((u8 *)arg0 + 0x244) = 0;
}

extern char lbl_8033ECB8[];
extern "C" void fn_8021CF9C(void *);
// Initialize a UI text/value object: run base setup, install vtable/fields, store source data, then refresh display.
extern "C" void *fn_8021CEEC(void *object, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 x, f32 y) {
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))fn_80219568)(object, arg1, arg2, 0, arg5, 0, 0);
    *(s32 *)((u8 *)object + 0x25C) = arg3;
    *(void **)object = lbl_8033ECB8;
    *(f32 *)((u8 *)object + 0x254) = x;
    *(f32 *)((u8 *)object + 0x258) = y;
    *(s32 *)((u8 *)object + 0x260) = arg4;
    *(u8 *)((u8 *)object + 0x264) = 0;
    fn_80219440(object, 0, (void *)arg3, 4);
    fn_8021CF9C(object);
    return object;
}

/* lbl_805634C4 is the 0.5f that rounds the scaled value to the nearest whole. */
#define WIDGET_ROUND_HALF lbl_805634C4

#pragma push
#pragma scheduling invalid_target
/* Refreshes this numeric readout: prints the watched integer as
 * offset + value * scale rounded to the nearest whole number, swaps the '.' of
 * the result for the current locale's decimal separator, re-fits the text to
 * the widget's box and asks for a redraw when the widget is live. */
extern "C" void fn_8021CF9C(void *arg0) {
    TextReadoutWidget *widget = (TextReadoutWidget *)arg0;
    f32 value = (f32)*(s32 *)widget->value;
    volatile char *buf = widget->text;
    sprintf((char *)buf, widget->format, (s32)(widget->offset + value * widget->scale + WIDGET_ROUND_HALF));
    fn_80130568(widget->text);
    fn_80219718(arg0);
    if (widget->live != 0)
        widget->redraw = 1;
}
#pragma scheduling on
#pragma pop
void fn_8021CF9C(void);
void fn_8021AC24(void *, int, int, int);
extern "C" void fn_8021CF9C(void);
extern "C" void fn_8021D040(void) { fn_8021CF9C(); }

/* Initializes a multi-choice list UI object: sets base fields/vtable, copies the packed
 * string options into an allocated table, selects the initial string, and computes an id. */
extern "C" void *fn_8021D044(void *obj, s32 x, s32 y, s32 selectedIndexPtr, const char *stringList,
                             s32 width, s32 height, s32 param7, s32 param8) {
    fn_80219568(obj, x, y, 0, width, 0, 0, param7);
    *(s32 *)((u8 *)obj + 0x25C) = height;
    *(void **)obj = lbl_8033EBA0;
    *(s32 *)((u8 *)obj + 0x260) = param7;
    *(s32 *)((u8 *)obj + 0x264) = param8;
    *(s32 *)((u8 *)obj + 0x254) = selectedIndexPtr;
    *(s32 *)((u8 *)obj + 0x258) = 0;
    *(s32 *)((u8 *)obj + 0x2B8) =
        fn_8012850C((void *)(fn_8022D1B4(stringList) * 4), lbl_8033D940);

    char *text;
    for (text = (char *)stringList; *text != 0; text += strlen(text) + 1) {
        void **table = *(void ***)((u8 *)obj + 0x2B8);
        table[(*(u32 *)((u8 *)obj + 0x258))++] = text;
    }

    fn_80219440(obj, 0, (void *)selectedIndexPtr, 4);
    fn_8021D61C(obj);
    *(s32 *)((u8 *)obj + 0x2BC) = 0;
    *(s32 *)((u8 *)obj + 0x2C0) = fn_80228F40(x, y);
    return obj;
}

extern "C" void fn_8021D154(void *arg0) {
    void *value;

    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C),
                            *(s32 *)((u8 *)arg0 + 0x2C0), arg0);
        *(void **)((u8 *)arg0 + 0x2BC) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 1, value, 4);
    }
}

extern "C" s32 fn_8021D1B0(void *arg0) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x2BC);
    if (p == 0)
        return 0;
    if (*(u8 *)((u8 *)arg0 + 0x1B) != 0)
        return *p == *(s32 *)((u8 *)arg0 + 0x2C0);
    return 4;
}

/* Handles input/navigation for a UI selection list: validates the active list state and updates the selected index or switches tabs. */
extern "C" s32 fn_8021D1F0(void *arg0, s32 arg1) {
    s32 *temp_r6 = *(s32 **)((u8 *)arg0 + 0x2BC);
    if (temp_r6 == 0)
        return 0;
    if (*(s32 *)((u8 *)arg0 + 0x2C0) != *temp_r6)
        return 0;
    switch (arg1) {
    case 0x127:
        if (*(*(s32 **)((u8 *)arg0 + 0x254)) < *(s32 *)((u8 *)arg0 + 0x258) - 1)
            ++*(*(s32 **)((u8 *)arg0 + 0x254));
        else
            *(*(s32 **)((u8 *)arg0 + 0x254)) = 0;
        return 1;
    case 0x125:
        if (*(*(s32 **)((u8 *)arg0 + 0x254)) > 0)
            --*(*(s32 **)((u8 *)arg0 + 0x254));
        else
            *(*(s32 **)((u8 *)arg0 + 0x254)) = *(s32 *)((u8 *)arg0 + 0x258) - 1;
        return 1;
    case 0x126:
        if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C));
            return 1;
        }
        goto done;
    case 0x128:
        if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C));
            return 1;
        }
    done:
    default:
        return 0;
    }
}

extern "C" void *fn_8021D300(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033EBA0;
        fn_80128670(*(s32 *)((u8 *)arg0 + 0x2B8));
        if (arg0 != 0)
            fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

/* The option widget built by fn_8021D044 (vtable lbl_8033EBA0): a base widget
 * (its box at +0x04/+0x08) holding the option strings and the index of the one
 * in use, plus the screen positions of the two "blinker" arrows that flank it.
 * fn_8021D154 links the widget to the screen with fn_80217BD8, which returns
 * the slot holding the id the screen currently selects; the widget's own id is
 * fn_80228F40(x, y), so the two are equal while this is the widget being
 * changed. */
struct OptionWidget {
    void *vtable;    /* 0x00 */
    u8 _04[0x254 - 0x04];
    s32 *index;      /* 0x254: index of the option in use */
    s32 count;       /* 0x258: how many options there are */
    s32 leftX;       /* 0x25C: screen x of the left arrow */
    s32 rightX;      /* 0x260: screen x of the right arrow */
    s32 arrowY;      /* 0x264: their screen y */
    u8 _268[0x2B8 - 0x268];
    char **options;  /* 0x2B8: the option strings (fn_8021D61C copies the current one) */
    s32 *selectedId; /* 0x2BC: id the screen selects now; 0 while unlinked */
    s32 id;          /* 0x2C0: this widget's own id */
};

/* The screen's indicator graphics (lbl_80490528), four sides to a set, picked
 * with fn_8021165C(side, set): set 0 is the slider art (a_lslide, a_rslide,
 * a_uscroll, ...), set 2 the blinker arrows flanking a changeable option
 * (blinkerlt, blinkerrt, blinkerup, blinkerdn). */
enum IndicatorSide { INDICATOR_LEFT = 0, INDICATOR_RIGHT = 1, INDICATOR_UP = 2, INDICATOR_DOWN = 3 };
#define INDICATOR_SET_BLINKER 2

#pragma push
#pragma processor 750
/* Draws the option widget's two blinker arrows after the widget's own frame:
 * the left one at leftX and the right one at rightX, both at arrowY, and
 * nothing at all while the widget has no room for them (both x equal).  Each
 * arrow is the blinker art (fn_8021165C) drawn at its natural width and
 * stretched to the current UI scale (the +0x34 of fn_8022EDC4()'s screen) from
 * its bottom edge, and is taken from the art's second frame - the lit one -
 * while this widget is the option the screen currently selects.
 *
 * fn_80230C30 turns a screen position into the screen-centred one the art is
 * drawn in, fn_802C5320(art, frame, x, y, z, width, height) draws the art and
 * fn_802C5220 / fn_802C51C0 are its height and width. */
extern "C" void fn_8021D378(void *object, s32 device) {
    OptionWidget *widget = (OptionWidget *)object;
    f32 scale, zero, leftHeight, rightHeight;
    f32 x, y;
    s32 frame;
    s32 *selectedId;
    s32 leftArt, rightArt;

    fn_80219660(object);
    if (widget->leftX == widget->rightX)
        return;
    selectedId = widget->selectedId;
    frame = 0;
    if (selectedId == 0)
        goto checked;
    if (widget->id != *selectedId)
        goto checked;
    frame = 1;
checked:
    leftArt = fn_8021165C(INDICATOR_LEFT, INDICATOR_SET_BLINKER);
    rightArt = fn_8021165C(INDICATOR_RIGHT, INDICATOR_SET_BLINKER);
    scale = *(f32 *)((u8 *)fn_8022EDC4() + 0x34);
    zero = lbl_805634A8;
    x = zero;
    y = zero;
    fn_80230C30(&x, &y, widget->leftX, widget->arrowY);
    leftHeight = scale * (f32)fn_802C5220(leftArt);
    fn_802C5320(leftArt, frame, x, y - ((f32)fn_802C5220(leftArt) - leftHeight), zero,
                (f32)fn_802C51C0(leftArt), leftHeight);
    fn_80230C30(&x, &y, widget->rightX, widget->arrowY);
    rightHeight = scale * (f32)fn_802C5220(rightArt);
    fn_802C5320(rightArt, frame, x, y - ((f32)fn_802C5220(rightArt) - rightHeight), zero,
                (f32)fn_802C51C0(rightArt), rightHeight);
}
#pragma pop

#pragma dont_inline on
extern "C" void fn_8021D568(void *arg0, s32 arg1) {
    /* Set the active gx canvas, then if this object's linked selection id
       (+0x2BC) matches the expected id (+0x2C0), draw the object's horizontal
       span via fn_802C3424 using vf28() as width and global lbl_8055FBC0
       (sbss, purpose unclear). Finally forward to fn_802195DC. */
    fn_802C3034(arg1);
    s32 *selectionIdPtr = *(s32 **)((u8 *)arg0 + 0x2BC);
    if (selectionIdPtr != 0 && *(s32 *)((u8 *)arg0 + 0x2C0) == *selectionIdPtr) {
        s32 left = *(s32 *)((u8 *)arg0 + 4);
        s32 top = *(s32 *)((u8 *)arg0 + 8);
        s32 width = ((VfObj *)arg0)->vf28();
        fn_802C3424(left, top, left + width, *(s32 *)((u8 *)arg0 + 0x10), lbl_8055FBC0);
    }
    fn_802195DC(arg0, arg1);
}
#pragma dont_inline reset
extern "C" void fn_8021D614(void) {
}

extern "C" void fn_8021D618(void) {
    ((void (*)(void))fn_8021D61C)();
}

extern "C" void fn_8021D61C(void *arg0) {
    s32 index = *(s32 *)*(s32 **)((u8 *)arg0 + 0x254);
    if (index >= 0 && index < *(s32 *)((u8 *)arg0 + 0x258)) {
        strcpy((char *)arg0 + 0x268,
               *(char **)(*(s32 *)((u8 *)arg0 + 0x2B8) + index * 4));
    } else {
        strcpy((char *)arg0 + 0x268, (char *)&lbl_8055B87C);
    }
    fn_80219718(arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void *fn_8021D6A0(void *self, s32 arg1, s32 arg2, s32 arg3, u8 *arg4,
                             s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    /* Initialize a MemoryCard::Resource object, configure it, and return it. */
    s32 zero = 0;
    s32 handle;

    ((void *(*)(void *, s32, s32, s32, u8 *, s32, s32, s32, s32))fn_8021D044)(
        self, arg1, arg2, arg3, arg4, 8, 0, 0, zero);
    *(void **)self = lbl_8033EB14;
    {
        s32 config[22] = {};
        config[0] = arg5;
        config[2] = arg6;
        config[3] = arg7;
        config[4] = arg7;
        config[5] = arg8;
        config[10] = arg7;
        config[11] = arg7;
        config[12] = arg8;
        handle = fn_8022A86C(config);
    }
    *(s32 *)((u8 *)self + 0x2C4) = handle;
    *(s32 *)((u8 *)self + 0x250) = handle;
    fn_80219718(self);
    return self;
}

extern "C" void *__dt__Q34Game10MemoryCard8ResourceFv(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033EB14;
        fn_8022A8E4(*(s32 *)((u8 *)arg0 + 0x2C4));
        fn_8021D300(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *fn_8021D7C8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 value;
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))fn_80219568)(arg0, arg1, arg2, 0, arg5, arg3, arg4);
    *(void **)arg0 = lbl_8033EC2C;
    value = fn_8023659C() - lbl_805634E8;
    *(s32 *)((u8 *)arg0 + 0x268) = arg5;
    *(s32 *)((u8 *)arg0 + 0x254) = arg6;
    *(f32 *)((u8 *)arg0 + 0x264) = value;
    *(f32 *)((u8 *)arg0 + 0x260) = value;
    *(s32 *)((u8 *)arg0 + 0x258) = 0;
    *(s32 *)((u8 *)arg0 + 0x25C) = fn_80228F40(arg1, arg2);
    return arg0;
}

extern "C" void fn_8021D864(void *arg0) {
    struct BaseA {
        int a, b, c;
    };
    struct ClassB : public BaseA {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    ClassB *obj = *(ClassB **)((u8 *)arg0 + 0x254);
    obj->v5();
}

extern "C" void fn_8021D878(void *arg0) {
    void *result;
    if(fn_80129BC4()!=0){ result=fn_80217BD8(*(s32*)((u8*)arg0+0x2C),*(s32*)((u8*)arg0+0x25C),arg0); *(void**)((u8*)arg0+0x258)=result; ((void(*)(void*,s32,void*,s32))fn_80219440)(arg0,1,result,4); }
}

extern "C" s32 fn_8021D8D4(void *self) {
    /* Return object state: 0 if pointer at +0x258 is null; 4 if flag at +0x1B
       is clear; otherwise if virtual v0() of object at +0x254 is nonzero returns
       normalized v1(), else returns normalized comparison *(*+0x258) == *(+0x25C). */
    struct BaseA {
        int a, b, c;
    };
    struct ClassB : public BaseA {
        virtual s32 v0();
        virtual s32 v1();
    };

    if (*(void **)((u8 *)self + 0x258) == 0) {
        return 0;
    }
    if (*(u8 *)((u8 *)self + 0x1B) != 0) {
        s32 result;
        ClassB *obj = *(ClassB **)((u8 *)self + 0x254);
        if (obj->v0() != 0) {
            result = (*(ClassB **)((u8 *)self + 0x254))->v1();
        } else {
            result = **(s32 **)((u8 *)self + 0x258) == *(s32 *)((u8 *)self + 0x25C);
        }
        return result != 0;
    }
    return 4;
}

extern "C" s32 fn_80216D28();
extern "C" s32 fn_80230E90(s32);
extern "C" f32 fn_8023659C();
extern "C" s32 fn_8021D97C(void *arg0, s32 arg1) {
    {
        void *o = *(void **)((u8 *)arg0 + 0x254);
        void *vt = *(void **)((u8 *)o + 0xC);
        s32 (*fn)(void *) = *(s32 (**)(void *))((u8 *)vt + 8);
        if (fn(o) != 0) {
            void *o2 = *(void **)((u8 *)arg0 + 0x254);
            void *vt2 = *(void **)((u8 *)o2 + 0xC);
            s32 (*fn2)(void *) = *(s32 (**)(void *))((u8 *)vt2 + 0x10);
            if (fn2(o2) == 0)
                return 0;
        } else {
            s32 *p = *(s32 **)((u8 *)arg0 + 0x258);
            if (p == 0)
                return 0;
            if (*(s32 *)((u8 *)arg0 + 0x25C) != *p)
                return 0;
        }
    }
    switch (arg1) {
    case 0x127: {
        void *o = *(void **)((u8 *)arg0 + 0x254);
        void *vt = *(void **)((u8 *)o + 0xC);
        s32 (*fn)(void *) = *(s32 (**)(void *))((u8 *)vt + 0x2C);
        if (fn(o) != 0) {
            void *o2 = *(void **)((u8 *)arg0 + 0x254);
            void *vt2 = *(void **)((u8 *)o2 + 0xC);
            void (*f)(void *) = *(void (**)(void *))((u8 *)vt2 + 0x24);
            f(o2);
            *(f32 *)((u8 *)arg0 + 0x264) = fn_8023659C();
        } else {
            fn_80216D28();
        }
        return 1;
    }
    case 0x125: {
        void *o = *(void **)((u8 *)arg0 + 0x254);
        void *vt = *(void **)((u8 *)o + 0xC);
        s32 (*fn)(void *) = *(s32 (**)(void *))((u8 *)vt + 0x28);
        if (fn(o) != 0) {
            void *o2 = *(void **)((u8 *)arg0 + 0x254);
            void *vt2 = *(void **)((u8 *)o2 + 0xC);
            void (*f)(void *) = *(void (**)(void *))((u8 *)vt2 + 0x20);
            f(o2);
            *(f32 *)((u8 *)arg0 + 0x260) = fn_8023659C();
        } else {
            fn_80216D28();
        }
        return 1;
    }
    case 0x126: {
        void *o = *(void **)((u8 *)arg0 + 0x254);
        void *vt = *(void **)((u8 *)o + 0xC);
        s32 (*fn)(void *) = *(s32 (**)(void *))((u8 *)vt + 8);
        if (fn(o) == 0 && *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
            return 1;
        }
        break;
    }
    case 0x128: {
        void *o = *(void **)((u8 *)arg0 + 0x254);
        void *vt = *(void **)((u8 *)o + 0xC);
        s32 (*fn)(void *) = *(s32 (**)(void *))((u8 *)vt + 8);
        if (fn(o) == 0 && *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
            return 1;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}

#pragma push
#pragma optimization_level 2
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8021DB58(u8 *self) {
    /* Draws the two value rows of a memory card entry: each row asks its
       ValueSource for a formatted string and texture, positions a sprite panel
       over the screen-centred rect, and fades/slides the row in over its
       0.3 s lifetime. */
    struct ValueSource {
        int a, b, c;
        virtual s32 isActive();
        virtual s32 getSelection();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual char *getText(f32);
        virtual void v6();
        virtual void v7();
        virtual s32 isRow0Hidden();
        virtual s32 isRow1Hidden();
    };
    s32 isSelected;
    s32 state1;
    f32 slide0;
    f32 slide1;
    f32 rowHeight;
    f32 x0;
    f32 x1;

    ValueSource *source = *(ValueSource **)(self + 0x254);
    if (source->isActive() != 0) {
        isSelected = (*(ValueSource **)(self + 0x254))->getSelection();
    } else {
        isSelected = 0;
        s32 *selection = *(s32 **)(self + 0x258);
        if (selection != 0 && *(s32 *)(self + 0x25C) == *selection)
            isSelected = 1;
    }
    f32 originX = lbl_805634A8;
    f32 originY = lbl_805634A8;
    fn_80230C30(&originX, &originY, *(s32 *)(self + 4), *(s32 *)(self + 8));
    f32 frameIndex = (f32)((VfObj *)self)->vf28();
    rowHeight = *(f32 *)((u8 *)lbl_8055E050 + 0x70) + frameIndex;
    f32 rectHeight = (f32)(*(s32 *)(self + 0x10) - *(s32 *)(self + 8));
    fn_80219660(self);
    s32 state0;
    if (isSelected != 0) {
        if (lbl_805634E8 + *(f32 *)(self + 0x260) >= fn_8023659C())
            state0 = 2;
        else
            state0 = 1;
    } else {
        state0 = 0;
    }
    if (isSelected != 0) {
        if (lbl_805634E8 + *(f32 *)(self + 0x264) >= fn_8023659C())
            state1 = 2;
        else
            state1 = 1;
    } else {
        state1 = 0;
    }
    s32 id0 = fn_80211660(0);
    s32 id1 = fn_80211660(1);
    f32 now0 = fn_8023659C();
    f32 fade0 = lbl_805634A4;
    f32 raw0 = ((lbl_805634E8 + *(f32 *)(self + 0x260)) - now0 - lbl_805634A8) / lbl_805634E8;
    fade0 = (fade0 < raw0) ? fade0 : raw0;
    fade0 = (fade0 > lbl_805634A8) ? fade0 : lbl_805634A8;
    slide0 = lbl_805634A8 + fade0 * lbl_805634C8;
    f32 now1 = fn_8023659C();
    f32 fade1 = lbl_805634A4;
    f32 raw1 = ((lbl_805634E8 + *(f32 *)(self + 0x264)) - now1 - lbl_805634A8) / lbl_805634E8;
    fade1 = (fade1 < raw1) ? fade1 : raw1;
    fade1 = (fade1 > lbl_805634A8) ? fade1 : lbl_805634A8;
    slide1 = lbl_805634A8 + fade1 * lbl_805634C8;
    s32 textWidth = fn_8022AB18(*(s32 *)(self + 0x268), 0, 3);
    f32 textWidthF = (f32)textWidth;
    x1 = originX + textWidthF;
    fn_8022AAA8(*(void **)(self + 0x268), (*(ValueSource **)(self + 0x254))->getText(textWidthF));
    textWidth = fn_8022AB18(*(s32 *)(self + 0x268), 1, 3);
    originY = originY - (f32)textWidth;
    x0 = (x1 - fn_80235EF0(id0, state0)) - slide0;
    x1 += slide1;
    s32 alignFlags = fn_8022AA84(*(s32 *)(self + 0x268));
    if (alignFlags & 4) {
        f32 halfHeight = rowHeight * lbl_805634C4;
        x0 -= halfHeight;
        x1 += halfHeight;
    } else {
        s32 downward = alignFlags & 2;
        if (downward)
            x0 -= rowHeight;
        if (!downward)
            x1 += rowHeight;
    }
    s32 color0 = -1;
    s32 color1 = -1;
    ValueSource *source0 = *(ValueSource **)(self + 0x254);
    if (source0 == 0 || source0->isRow0Hidden() == 0) {
        f32 nowC = fn_8023659C();
        f32 fade = lbl_805634A4;
        f32 raw = ((nowC - *(f32 *)(self + 0x260)) - lbl_805634A8) / lbl_80563504;
        fade = (fade < raw) ? fade : raw;
        fade = (fade > lbl_805634A8) ? fade : lbl_805634A8;
        color0 = ((s32)(lbl_80563508 + fade * lbl_8056350C) << 24) | 0xFFFFFF;
    }
    ValueSource *source1 = *(ValueSource **)(self + 0x254);
    if (source1 == 0 || source1->isRow1Hidden() == 0) {
        f32 nowC = fn_8023659C();
        f32 fade = lbl_805634A4;
        f32 raw = ((nowC - *(f32 *)(self + 0x264)) - lbl_805634A8) / lbl_80563504;
        fade = (fade < raw) ? fade : raw;
        fade = (fade > lbl_805634A8) ? fade : lbl_805634A8;
        color1 = ((s32)(lbl_80563508 + fade * lbl_8056350C) << 24) | 0xFFFFFF;
    }
    if ((*(ValueSource **)(self + 0x254) == 0 || (*(ValueSource **)(self + 0x254))->isRow0Hidden() != 0 || (f32)__fabs((double)slide0) > *(f32 *)&lbl_80558DC4) && id0 != 0) {
        f32 glyphWidth = fn_80235EF0(id0, state0);
        f32 glyphHeight = fn_80235F64(id0, state0);
        fn_802354A0(id0, state0, color0, x0, originY + glyphHeight * lbl_805634C4, lbl_805634A8, glyphWidth, glyphHeight);
    }
    if ((*(ValueSource **)(self + 0x254) == 0 || (*(ValueSource **)(self + 0x254))->isRow1Hidden() != 0 || (f32)__fabs((double)slide1) > *(f32 *)&lbl_80558DC4) && id1 != 0) {
        f32 glyphWidth = fn_80235EF0(id1, state1);
        f32 glyphHeight = fn_80235F64(id1, state1);
        fn_802354A0(id1, state1, color1, x1, originY + glyphHeight * lbl_805634C4, lbl_805634A8, glyphWidth, glyphHeight);
    }
}
#pragma pop

#pragma push
#pragma scheduling on
#pragma small_data on
extern "C" void *fn_8021E0C0(void *obj, s32 x, s32 y, s32 width, s32 height, void *table, void *indexPtr, void *valuePtr, s32 arg8) {
    // Initialize a text/option list object and register its widgets.
    fn_80218F34(obj, x, y, x + width, y + height, 0);
    f32 alpha = lbl_805634A8;
    void *vtable = lbl_8033EA90;
    *(u8 *)((u8 *)obj + 0x268) = 0;
    *(void **)obj = vtable;
    *(s32 *)((u8 *)obj + 0x260) = 0;
    *(f32 *)((u8 *)obj + 0x264) = alpha;
    s32 stride = fn_8022B620(7, (const char *)&lbl_8055B880) + 2;
    *(void **)((u8 *)obj + 0x244) = table;
    *(s32 *)((u8 *)obj + 0x258) = stride;
    *(void **)((u8 *)obj + 0x25C) = indexPtr;
    *(void **)((u8 *)obj + 0x248) = valuePtr;
    *(s32 *)((u8 *)obj + 0x250) = width / 8;
    *(s32 *)((u8 *)obj + 0x254) = height / stride;
    if (valuePtr) {
        *(u32 *)valuePtr = *(u32 *)((u8 *)table + 8);
        *(s32 *)((u8 *)valuePtr + 4) = *(s32 *)((u8 *)obj + 0x254);
        fn_80219440(obj, 0, valuePtr, 0xC);
        fn_8021E7D4(obj);
    }
    fn_80219440(obj, 0, (u8 *)indexPtr, 4);
    fn_80219440(obj, 0, (u8 *)table + 0xC, 4);
    return obj;
}
#pragma pop

extern "C" s32 fn_8021E1C8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_4;
    s32 var_r5;
    void *temp_r6;
    s32 var_r7;
    s32 *temp_r4_3;
    *(s32 *)((u8 *)arg0 + 0x260) = 0;
    if (*(u8 *)((u8 *)arg0 + 0x268) != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
            *(u8 *)((u8 *)arg0 + 0x234) = 1;
        temp_r6 = *(void **)((u8 *)arg0 + 0x248);
        var_r7 = 0;
        if (temp_r6 != 0)
            var_r7 = *(s32 *)((u8 *)temp_r6 + 8);
        var_r5 = var_r7 + ((arg2 - *(s32 *)((u8 *)arg0 + 8) - 2) / *(s32 *)((u8 *)arg0 + 0x258));
        if (var_r5 < 0)
            var_r5 = 0;
        temp_r4 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x244) + 8);
        if (var_r5 >= temp_r4)
            var_r5 = temp_r4 - 1;
        if (temp_r6 != 0) {
            temp_r4_2 = *(s32 *)((u8 *)temp_r6 + 8);
            if (var_r5 < temp_r4_2) {
                *(s32 *)((u8 *)arg0 + 0x260) = -1;
                var_r5 = temp_r4_2;
            }
            temp_r4_3 = *(s32 **)((u8 *)arg0 + 0x248);
            temp_r4_4 = temp_r4_3[1] + temp_r4_3[2];
            if (var_r5 >= temp_r4_4) {
                *(s32 *)((u8 *)arg0 + 0x260) = 1;
                var_r5 = temp_r4_4 - 1;
            }
        }
        if (var_r5 >= 0 && var_r5 < *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x244) + 8)) {
            arg0 = *(void **)((u8 *)arg0 + 0x25C);
            *(s32 *)arg0 = var_r5;
        }
    }
}

/* Update a timed scroll/step state: accumulates delta into a timer, and when it
   leaves [0, 0.15) advances a bounded counter by a signed step and writes the
   resulting index (or end index for positive step) through an output pointer. */
extern "C" void fn_8021E2A0(void *self) {
    f32 zero, previousTime, delta, time, upperBound, currentTime, clampedTime, overflow;
    fn_802192AC(self);
    if (*(void **)((u8 *)self + 0x248) == 0) goto reset;
    if (*(s32 *)((u8 *)self + 0x260) == 0) goto reset;
    delta = fn_80214D48();
    previousTime = *(f32 *)((u8 *)self + 0x264);
    zero = lbl_805634A8;
    time = previousTime + delta;
    *(f32 *)((u8 *)self + 0x264) = time;
    if (time < zero) goto adjust;
    if (time >= lbl_80563504) goto adjust;
    goto done;
adjust:
    currentTime = *(f32 *)((u8 *)self + 0x264);
    upperBound = lbl_80563504;
    clampedTime = lbl_80563510;
    overflow = currentTime - upperBound;
    clampedTime = (clampedTime > overflow) ? clampedTime : overflow;
    *(f32 *)((u8 *)self + 0x264) = clampedTime;
    s32 stepped;
    s32 maxValue;
    s32 *range;
    range = *(s32 **)((u8 *)self + 0x248);
    stepped = range[2] + *(s32 *)((u8 *)self + 0x260);
    range[2] = stepped;
    maxValue = range[0] - range[1];
    if (stepped > maxValue) range[2] = maxValue;
    if (range[2] < 0) range[2] = 0;
    if (*(s32 *)((u8 *)self + 0x260) < 0) {
        range = *(s32 **)((u8 *)self + 0x248);
        *(s32 *)*(s32 **)((u8 *)self + 0x25C) = range[2];
        goto done;
    }
    range = *(s32 **)((u8 *)self + 0x248);
    *(s32 *)*(s32 **)((u8 *)self + 0x25C) = range[2] + range[1] - 1;
    goto done;
reset:
    *(f32 *)((u8 *)self + 0x264) = lbl_805634A8;
done:
    ;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021E3BC(void *arg0, s32 arg1) {
    s32 scratch;
    register s32 color;
    register s32 item;
    register s32 base;
    register s32 index;
    register s32 selected;
    register s32 yBase;
    register s32 xBase;
    register s32 result;
    register s32 status;

    void *entries = *(void **)((u8 *)arg0 + 0x248);
    base = 0;
    if (entries != 0)
        base = *(s32 *)((u8 *)entries + 8);
    ((void (*)(void *, s32))fn_802192A0)(arg0, arg1);
    fn_802C3034(arg1);

    /* Draw visible list items: highlight the selected row and draw each item's label/text with selection/scratch flags. */
    color = lbl_8055FBDC;
    scratch = 0;
    index = 0;
    goto check;

body:
    selected = **(s32 **)((u8 *)arg0 + 0x25C) == item;
    if (selected) {
        yBase = *(s32 *)((u8 *)arg0 + 4);
        xBase = *(s32 *)((u8 *)arg0 + 8);
        result = yBase + ((VfObj *)arg0)->vf28();
        fn_802C3424(yBase + 2,
                    xBase + index * *(s32 *)((u8 *)arg0 + 0x258) + 2,
                    result - 2,
                    xBase + (index + 1) * *(s32 *)((u8 *)arg0 + 0x258) + 2,
                    color);
    }

    {
        s32 tmpSel = -selected | selected;
        yBase = *(s32 *)((u8 *)arg0 + 8);
        s32 tmpScr = -scratch | scratch;
        xBase = *(s32 *)((u8 *)arg0 + 4);
        status = (tmpScr >> 31) & 2;
        selected = (u32)tmpSel >> 31;
    }
    result = ((s32 (*)(s32, s32, s32 *))fn_8022D3F8)(
        *(s32 *)((u8 *)arg0 + 0x244), item, 0);
    fn_8022B91C(7, xBase + 2,
                yBase + index * *(s32 *)((u8 *)arg0 + 0x258) + 2,
                result, selected | status);
    ++index;

check:
    if (index < *(s32 *)((u8 *)arg0 + 0x254)) {
        item = index + base;
        if (((s32 (*)(s32, s32, s32 *))fn_8022D3F8)(
                *(s32 *)((u8 *)arg0 + 0x244), item, &scratch) != 0)
            goto body;
    }
}
#pragma scheduling on
#pragma pop
extern "C" s32 fn_8022D3F8(s32, s32, s32 *, s32, s32);
extern "C" void fn_8021E51C(void *self, s32 arg1) {
    struct Local {
        s32 sp8;
        s32 pad;
        s32 sp10;
    } local;
    s32 base = 0;
    s32 i;
    s32 item;
    s32 selected;
    s32 difference;
    s32 flagMask;
    s32 equal;
    s32 combined;
    s32 result;
    s32 yBase;
    s32 xBase;
    void *entries = *(void **)((u8 *)self + 0x248);

    if (entries != 0) {
        base = *(s32 *)((u8 *)entries + 8);
    }
    local.sp10 = 0;
    i = 0;
    goto probe;

body:
    selected = **(s32 **)((u8 *)self + 0x25C);
    yBase = *(s32 *)((u8 *)self + 8);
    xBase = *(s32 *)((u8 *)self + 4);
    difference = item - selected;
    equal = (difference == 0);
    flagMask = (-local.sp10 | local.sp10) >> 31;
    result = fn_8022D3F8(*(s32 *)((u8 *)self + 0x244),
                         item, 0, flagMask, equal);
    local.sp8 = 0;
    combined = equal | ((flagMask & 2) >> 1);
    fn_8022BAD0(7, xBase + 2,
                yBase + i * *(s32 *)((u8 *)self + 0x258) + 2,
                0, 0, 0, result, combined, lbl_805634A4);

    ++i;
    if (i >= *(s32 *)((u8 *)self + 0x254)) {
        return;
    }

probe:
    item = i + base;
    if (((s32 (*)(s32, s32, s32 *))fn_8022D3F8)(
            *(s32 *)((u8 *)self + 0x244), item, &local.sp10) != 0) {
        goto body;
    }
}

extern "C" void fn_8021E7D4(void *);
// Manual jump table dispatch to match target
#pragma push
#pragma optimization_level 4
// Match jump table dispatch structure from target
extern "C" s32 fn_8021E620(void *arg0, s32 arg1) {
    switch (arg1) {
    case 0x121: {
        s32 v = *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C);
        if (v > 0)
            *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) = v - 1;
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x122: {
        s32 v = *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) + 1;
        if (v < *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x244) + 8))
            *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) = v;
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x123: {
        s32 *limitPtr = *(s32 **)((u8 *)arg0 + 0x244);
        s32 *rangePtr = *(s32 **)((u8 *)arg0 + 0x248);
        s32 *statePtr = *(s32 **)((u8 *)arg0 + 0x25C);
        s32 lim = limitPtr[2] - 1;
        s32 rg1 = rangePtr[1];
        s32 st = *statePtr;
        s32 sum = st + rg1;
        if (lim < sum)
            *statePtr = (s32)(s8)lim;
        {
            s32 *range = *(s32 **)((u8 *)arg0 + 0x248);
            s32 nv = range[2] + range[1];
            range[2] = nv;
            if (nv > range[0] - range[1])
                range[2] = range[0] - range[1];
            if (range[2] < 0)
                range[2] = 0;
        }
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x124: {
        s32 st = *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C);
        s32 rg1 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x248) + 4);
        s32 v = st - rg1;
        *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) = v & ~(v >> 31);
        {
            s32 *range = *(s32 **)((u8 *)arg0 + 0x248);
            s32 nv = range[2] - range[1];
            range[2] = nv;
            if (nv > range[0] - range[1])
                range[2] = range[0] - range[1];
            if (range[2] < 0)
                range[2] = 0;
        }
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x125:
        *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) = 0;
        fn_8021E7D4(arg0);
        return 1;
    case 0x126: {
        s32 lim = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x244) + 8) - 1;
        *(s32 *)*(s32 **)((u8 *)arg0 + 0x25C) = lim;
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x127:
    case 0x128:
    default:
        return 0;
    }
}
#pragma pop

/* Clamp the visible range at widget+0x248 so it stays within bounds and includes the current index at widget+0x25C. */
extern "C" void fn_8021E7D4(void *widget) {
    s32 maxVisible;
    s32 maxVisible2;
    s32 rangeBase;
    s32 clampedCount;
    void *rangeReload;
    s32 currentIndex2;
    s32 currentIndex;
    void *range;

    range = *(void **)((u8 *)widget + 0x248);
    if (range != 0) {
        rangeBase = *(s32 *)((u8 *)range + 4);
        currentIndex = **(s32 **)((u8 *)widget + 0x25C);
        if (currentIndex > (rangeBase + *(s32 *)((u8 *)range + 8)) - 1) {
            clampedCount = (currentIndex - rangeBase) + 1;
            *(s32 *)((u8 *)range + 8) = clampedCount;
            maxVisible = *(s32 *)range - *(s32 *)((u8 *)range + 4);
            if (clampedCount > maxVisible) *(s32 *)((u8 *)range + 8) = maxVisible;
            if (*(s32 *)((u8 *)range + 8) < 0) *(s32 *)((u8 *)range + 8) = 0;
        }
        rangeReload = *(void **)((u8 *)widget + 0x248);
        currentIndex2 = **(s32 **)((u8 *)widget + 0x25C);
        if (currentIndex2 < *(s32 *)((u8 *)rangeReload + 8)) {
            *(s32 *)((u8 *)rangeReload + 8) = currentIndex2;
            maxVisible2 = *(s32 *)rangeReload - *(s32 *)((u8 *)rangeReload + 4);
            if (currentIndex2 > maxVisible2) *(s32 *)((u8 *)rangeReload + 8) = maxVisible2;
            if (*(s32 *)((u8 *)rangeReload + 8) < 0) *(s32 *)((u8 *)rangeReload + 8) = 0;
        }
    }
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021E884(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8021E8DC(void *widget, s32 drawContext) {
    /* Draws a labeled UI widget: optionally performs inner layout/content passes
       when enabled, then draws the frame and renders "width label" text. */
    char labelBuffer[0x58];
    s32 rightBound;
    s32 layoutWidth;
    s32 x;
    s32 y;
    s32 savedLeft;
    s32 innerWidth;
    register char *labelText;

    if (*(u8 *)((u8 *)widget + 0x268) != 0) {
        ((Fn80219264VTable *)widget)->Call(
            *(s32 *)((u8 *)widget + 4), *(s32 *)((u8 *)widget + 0x10) + 3);
        rightBound = *(s32 *)((u8 *)widget + 8);
        layoutWidth = *(s32 *)((u8 *)widget + 0x10) - rightBound;
        savedLeft = ((Fn8021E8DCVTable *)widget)->Get();
        fn_80219284(widget, *(s32 *)((u8 *)widget + 0x26C),
                    *(s32 *)((u8 *)widget + 0x270));
        fn_8021E3BC(widget, drawContext);
        fn_80219284(widget, savedLeft, layoutWidth);
        rightBound = *(s32 *)((u8 *)widget + 8);
        ((Fn80219264VTable *)widget)->Call(
            *(s32 *)((u8 *)widget + 4),
            rightBound * 2 - 3 - *(s32 *)((u8 *)widget + 0x10));
    }

    fn_802C3034(drawContext);
    ((void (*)(void *, s32))fn_802192A0)(widget, drawContext);
    x = *(s32 *)((u8 *)widget + 4);
    y = *(s32 *)((u8 *)widget + 8);
    rightBound = ((Fn8021E8DCVTable *)widget)->Get();
    innerWidth = x + rightBound;
    fn_802C3424(x, y, innerWidth, *(s32 *)((u8 *)widget + 0x10), lbl_8055FBDC);
    labelText = ((char *(*)(s32, s32, s32))fn_8022D3F8)(
        *(s32 *)((u8 *)widget + 0x244),
        **(s32 **)((u8 *)widget + 0x25C), 0);
    sprintf(labelBuffer, (const char *)&lbl_8055B884, *(s32 *)((u8 *)widget + 0x250),
            labelText != 0 ? labelText : (char *)&lbl_8055B88C);
    fn_802C4F58(*(s32 *)((u8 *)widget + 4) + 1,
                *(s32 *)((u8 *)widget + 8) + 1, labelBuffer, lbl_8055FBC0);
}

#pragma scheduling invalid_target
extern "C" void *fn_8021EA64(void *self, s32 x, s32 y, s32 width, s32 height, char *textBuffer, s32 columns, s32 rows, s32 unkA8, u8 clearText) {
    extern char lbl_8033E988[];
    extern char lbl_8033D96C[];
    extern char lbl_8033D978[];
    s32 *words = (s32 *)self;

    /* Initialize a text edit control: set bounds and vtable, optionally clear the buffer, load slider/caret images, and seed its text content. */
    fn_80218F34(self, x, y, x + width, y + height + 3, 0);
    *(void **)self = lbl_8033E988;
    if (clearText != 0)
        *textBuffer = 0;
    *(char **)((u8 *)self + 0xA54) = textBuffer;
    *(s32 *)((u8 *)self + 0xA58) = unkA8;
    words[0x248 / 4] = ((columns >> 31) ^ columns) - (columns >> 31);
    words[0x24C / 4] = rows;
    if (rows == 1 && columns > 0)
        words[0xA60 / 4] = ((s32 (*)(void *))fn_802C5130)(lbl_8033D96C);
    else
        words[0xA60 / 4] = 0;
    words[0x244 / 4] = 0;
    words[0xA5C / 4] = ((s32 (*)(void *))fn_802C5130)(lbl_8033D978);
    words[0x250 / 4] = strlen(textBuffer);
    fn_80219440(self, 0, textBuffer, words[0x248 / 4] * words[0x24C / 4]);
    if (words[0xA60 / 4] != 0) {
        s32 count = fn_802C5220(words[0xA60 / 4]);
        fn_80219284(self, ((Vf78 *)self)->get(), count);
    }
    return self;
}
#pragma scheduling on
extern "C" void fn_8022B2D4(void *, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_8033E988[];
extern "C" void *fn_8021EB9C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E988;
        fn_802C519C(*(void **)((u8 *)arg0 + 0xA5C));
        if (*(void **)((u8 *)arg0 + 0xA60) != 0)
            fn_802C519C(*(void **)((u8 *)arg0 + 0xA60));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_802C2FC8(s32, s32, s32, s32, s32);
extern "C" void fn_80228DC4(s32, s32, s32, s32, s32, s32);
extern "C" void fn_8022B390(s32, s32, s32, s32*, s32*);
extern "C" void fn_802C47B8(s32, s32, s32, s32, s32, s32);
extern "C" void fn_802C3014(s32);
extern "C" s32 lbl_8055FBF8;
extern "C" void fn_8021EC1C(void* arg0, s32 arg1) {
    class LocalVt { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual s32 get(); };
    s32 spC,sp8,r28,r29,r0,r7,r6,r3;
    fn_802C3034(arg1); r28=*(s32*)((u8*)arg0+4); r29=*(s32*)((u8*)arg0+8); r0=((LocalVt*)arg0)->get(); r7=*(s32*)((u8*)arg0+0x10); r6=r28+r0;
    fn_802C2FC8(arg1,r28,r29,r6,r7); ((void(*)(void*,s32))fn_802192A0)(arg0,arg1);
    if (*(s32*)((u8*)arg0+0xA60)) { r29=*(s32*)((u8*)arg0+8); r0=((LocalVt*)arg0)->get(); r28=*(s32*)((u8*)arg0+4); fn_80228DC4(arg1,*(s32*)((u8*)arg0+0xA60),r28,r29,r0,0); }
    r28=*(s32*)((u8*)arg0+4); r0=((LocalVt*)arg0)->get(); r29=*(s32*)((u8*)arg0+8); r7=*(s32*)((u8*)arg0+0x10); r6=r28+r0;
    fn_802C2FC8(arg1,r28,r29,r6,r7);
    fn_8022B91C(*(s32*)((u8*)arg0+0xA58),*(s32*)((u8*)arg0+4),*(s32*)((u8*)arg0+8),*(s32*)((u8*)arg0+0xA54),(*(u8*)((u8*)arg0+0x19)!=0));
    if (*(u8*)((u8*)arg0+0x19)) { fn_8022B390(*(s32*)((u8*)arg0+0xA58),*(s32*)((u8*)arg0+0xA54),*(s32*)((u8*)arg0+0x250),&spC,&sp8); r0=sp8+*(s32*)((u8*)arg0+8); r3=spC+*(s32*)((u8*)arg0+4); ((void(*)(s32,s32,s32,s32,s32))fn_802C47B8)(r3,r0+2,r3,r0+0xC,lbl_8055FBF8); }
    fn_802C3014(arg1);
}

#pragma push
#pragma processor 750
extern "C" void fn_8021EDA4(void *self) {
    u8 *p = (u8 *)self;
    char text[256];
    if (*(s32 *)(p + 0xA60)) {
        f32 height, x, y;
        x = (f32)(*(s32 *)(p + 4) - lbl_8055FB9C / 2);
        y = (f32)(lbl_8055FBA0 / 2 - *(s32 *)(p + 8));
        height = (f32)fn_802C5220(*(s32 *)(p + 0xA60));
        f32 width = (f32)((Vf78 *)self)->get();
        fn_802C5320(*(s32 *)(p + 0xA60), 0, x, y, lbl_805634A8, width, height);
    }
    s32 zero = 0;
    ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,f32,s32))fn_8022BAD0)(*(s32 *)(p + 0xA58), *(s32 *)(p + 4), *(s32 *)(p + 8), zero, zero, zero, *(s32 *)(p + 0xA54), *(u8 *)(p + 0x19) != 0, lbl_805634A4, zero);
    if (*(u8 *)(p + 0x19)) {
        f32 x = (f32)(*(s32 *)(p + 4) - lbl_8055FB9C / 2);
        f32 y = (f32)(lbl_8055FBA0 / 2 - *(s32 *)(p + 8));
        strcpy(text, *(char **)(p + 0xA54));
        if (*(s32 *)(p + 0x250) >= 0) text[*(s32 *)(p + 0x250)] = zero;
        x += (f32)fn_8022B498(*(s32 *)(p + 0xA58), (s32)text);
        f32 height = (f32)fn_8022B620(*(s32 *)(p + 0xA58), text);
        ((void (*)(s32,f32,f32,f32,f32,f32))fn_80230924)(-0x100, x, y - lbl_80563514, lbl_805634A4 + x, lbl_80563514 + (y - height), lbl_805634A8);
    }
}
#pragma pop

extern "C" void fn_8021EFE0(void *arg0, s32 arg1, s32 arg2) {
    s32 dx = arg1 - *(s32 *)((u8 *)arg0 + 4);
    s32 dy = arg2 - *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x250) = ((s32 (*)(s32, s32, s32, s32))fn_8022B2D4)(*(s32 *)((u8 *)arg0 + 0xA58), *(s32 *)((u8 *)arg0 + 0xA54), dx, dy);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_8021F044(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
    class Dispatch {
    public:
        virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03(); virtual void f04();
        virtual void f05(); virtual void f06(); virtual void f07(); virtual void f08(); virtual void f09();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22();
        virtual void DispatchCall(s32);
    };
    ((Dispatch *)arg0)->DispatchCall(0);
}

/* The text-edit widget this unit's key handlers work on (its members sit in
   the object's own tail; the widget base class ends around 0x234).  Only the
   fields the key handler touches are named. */
typedef struct TextField {
    char pad000[0x019];
    u8 editing;   /* 0x19 caret shown, the field takes keys only when set */
    u8 active;    /* 0x1A a change marks the widget dirty when set */
    char pad01B[0x234 - 0x01B];
    u8 dirty;     /* 0x234 redraw needed */
    char pad235[0x248 - 0x235];
    s32 columns;  /* 0x248 width in characters */
    s32 rows;     /* 0x24C number of lines; columns * rows is the capacity */
    s32 cursor;   /* 0x250 caret position in text */
    char pad254[0xA54 - 0x254];
    char *text;   /* 0xA54 the editable string (0xA58 font, 0xA5C ibeam.img) */
} TextField;

/* Virtual key codes the text field handles.  The ten codes from 0x160 on are
   the digit keys and stand for '0'..'9'; the rest are the UI's navigation
   keys, which each kind of widget interprets for itself. */
enum {
    TEXT_KEY_BACKSPACE = 0x8,
    TEXT_KEY_TAB = 0x9,
    TEXT_KEY_END = 0x123,
    TEXT_KEY_HOME = 0x124,
    TEXT_KEY_LEFT = 0x125,
    TEXT_KEY_RIGHT = 0x127,
    TEXT_KEY_DELETE = 0x12E,
    TEXT_KEY_DIGIT_0 = 0x160,
    TEXT_KEY_DIGIT_9 = 0x169,
    TEXT_KEY_DIGIT_BASE = 0x130 /* digit key - this = its ASCII code */
};

extern "C" s32 strlen(const char *);
extern "C" s32 fn_802E4A1C(s32);
/* Key handler of a text-edit field: moves the caret (home/end/left/right),
   erases with backspace/delete, inserts a typed character at the caret and
   hands tab to the widget group to move the focus.  Returns whether the key
   was used. */
extern "C" s32 fn_8021F06C(void *widget, s32 keyCode) {
    s32 insertCursor;
    char *text;
    s32 capacity;
    TextField *field;
    s32 key;
    key=keyCode; field=(TextField *)widget;
    text=field->text;
    if(field->cursor>strlen(text))field->cursor=strlen(text);
    capacity=field->columns * field->rows;
    if(field->editing==0)return 0;
    if(field->active!=0)field->dirty=1;
    /* the digit keys stand for their ASCII code: key + 0xFED0 == key - 0x130 */
    if((u32)key>=TEXT_KEY_DIGIT_0&&(u32)key<=TEXT_KEY_DIGIT_9)key=(key+0xFED0)&0xFFFF;
    switch(key) {
    case TEXT_KEY_HOME: field->cursor=0;if(field->active!=0)field->dirty=1;goto handled;
    case TEXT_KEY_END: field->cursor=strlen(field->text);if(field->active!=0)field->dirty=1;goto handled;
    case TEXT_KEY_LEFT: { s32 cursor=field->cursor;if(cursor>0){cursor--;field->cursor=cursor;if(field->active!=0)field->dirty=1;}goto handled; }
    case TEXT_KEY_RIGHT: { s32 length=strlen(field->text);s32 cursor=field->cursor;if((u32)cursor<(u32)length){cursor++;field->cursor=cursor;if(field->active!=0)field->dirty=1;}goto handled; }
    case TEXT_KEY_DELETE: { s32 index;char *base;char *current;char next;char *deleteText=field->text;if(strlen(deleteText)!=0){index=field->cursor;if((u32)index<(u32)strlen(deleteText)){goto delete_check;delete_copy:next=current[1];index++;*current=next;delete_check:base=field->text;current=base+index;if((s8)base[index]!=0)goto delete_copy;}}if(field->active!=0)field->dirty=1;goto handled; }
    case TEXT_KEY_BACKSPACE: { s32 index;char *base;char *current;char next;if(strlen(field->text)!=0){index=field->cursor;if(index>0){index--;field->cursor=index;goto backspace_check;backspace_copy:next=current[1];index++;*current=next;backspace_check:base=field->text;current=base+index;if((s8)base[index]!=0)goto backspace_copy;}}if(field->active!=0)field->dirty=1;goto handled; }
    case TEXT_KEY_TAB: if(fn_802E4A1C(0xFD)==0)fn_802194F4(widget);else fn_80219508(widget);goto handled;
    default:
        if(((u32)key&0x100)==0&&(u32)key>0x1F){
            text=field->text;
            if((u32)strlen(text)<(u32)(capacity-1)){
                char previous;
                char *slot;
                s32 insertIndex=strlen(text)+1;
                goto insert_check;
insert_copy:
                slot=field->text+insertIndex;
                previous=slot[-1];
                insertIndex--;
                *slot=previous;
insert_check:
                insertCursor=field->cursor;
                if(insertIndex>insertCursor)goto insert_copy;
                text=field->text;
                text[insertCursor]=key;
                insertCursor++;
                field->cursor=insertCursor;
            }
            if(field->active!=0)field->dirty=1;
            goto handled;
        }
        return fn_802192A4(widget,key);
    }
handled:
#pragma scheduling off
    return 1;
#pragma scheduling on
}

#pragma push
#pragma small_data off
extern "C" void *lbl_8033E8FC[];
#pragma pop
extern "C" char lbl_80490934[];
extern "C" void fn_801A7844(s32);
extern "C" s32 fn_801A7C8C(s32);
extern "C" void fn_801A7E54(void *, s32, s32);
extern "C" void fn_802E47E8(void);
#pragma push
#pragma small_data off
extern "C" void *fn_8021F394(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))fn_80219568)(arg0, arg1, arg2, 0, arg5, 0, 0);
    *(s32 *)((u8 *)arg0 + 0x26C) = arg3;
    *(void **)arg0 = lbl_8033E8FC;
    *(s32 *)((u8 *)arg0 + 0x270) = arg4;
    fn_801A7E54((u8 *)arg0 + 0x254, 0x18, arg4);
    fn_80219440(arg0, 0, (void *)arg4, 0x10);
    fn_80219718(arg0);
    return arg0;
}
#pragma pop
extern "C" void fn_8021F42C(void *arg0) {
    fn_801A7E54((u8 *)arg0 + 0x254, 0x18, *(s32 *)((u8 *)arg0 + 0x270));
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

#pragma push
#pragma small_data off
extern "C" s32 fn_8021F478(s32 *arg0) {
    char *base;

    fn_801A7844(1);
    base = lbl_80490934;
    if (fn_801A7C8C(*(s32 *)(base + 0x18)) != 0) {
        fn_801A7E54(base, 0x18, *(s32 *)(base + 0x18));
        fn_802E47E8();
        *arg0 = -2;
        return 1;
    }
    return 0;
}
#pragma pop
extern "C" void fn_801A7A5C(void);
extern "C" s32 fn_802146BC(void *, s32, s32, s32, void *, s32, s32, s32);
extern "C" void fn_802194FC(void *);
extern "C" void fn_8021F4F0(void *arg0, void *) {
    s32 args[30];

    fn_801A7A5C();
    strcpy((char *)lbl_80490934, (char *)arg0 + 0x254);
    *(s32 *)((char *)lbl_80490934 + 0x18) = *(s32 *)((char *)arg0 + 0x270);

    ((volatile s32 *)args)[1] = *((volatile s32 *)&lbl_802F9EE0[1]);
    args[0] = lbl_802F9EE0[0];
    args[2] = lbl_802F9EE0[2];
    args[3] = lbl_802F9EE0[3];
    args[4] = lbl_802F9EE0[4];
    args[5] = (s32)&lbl_8055B890;
    args[6] = 3;
    args[7] = (s32)lbl_8033D9A4;
    args[8] = 0x80;
    args[9] = 0;
    args[10] = (s32)&lbl_8055B898;
    args[11] = 3;
    args[12] = *(s32 *)((char *)arg0 + 0x26c);
    args[13] = 0x80;
    args[14] = 0;
    args[15] = (s32)&lbl_8055B8A0;
    args[16] = 0;
    args[17] = 0;
    args[18] = -1;
    args[19] = 0;
    args[20] = (s32)&lbl_8055B860;
    args[21] = 6;
    args[22] = 0;
    args[23] = -1;
    args[24] = 0x1b;
    args[25] = lbl_80490920[0];
    args[26] = lbl_80490920[1];
    args[27] = lbl_80490920[2];
    args[28] = lbl_80490920[3];
    args[29] = lbl_80490920[4];
    args[1] = (s32)&args[5];

    if (fn_802146BC(args, -999, -999, 1,
                    (void *)lbl_802F9EE0[4],
                    lbl_802F9EE0[3], lbl_802F9EE0[2], lbl_802F9EE0[0]) == -2) {
        strcpy((char *)arg0 + 0x254, (char *)lbl_80490934);
        fn_80219718(arg0);
    }
    fn_802194FC(arg0);
    if (*((u8 *)arg0 + 0x1a) != 0)
        *((u8 *)arg0 + 0x234) = 1;
}

extern "C" char lbl_8033D9B0[];
extern "C" char lbl_8033D9BC[];
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_8021F678(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg0, f32 farg1) {
    s32 size;
    s32 end;
    s32 count;
    s32 len;
    fn_80218F34(arg0, arg1, arg2, arg1 + arg3, arg2 + arg4, 0);
    *(s32 *)((u8 *)arg0 + 0x250) = arg5;
    s32 sign = arg6 >> 31;
    void *vt = lbl_8033E878;
    size = (sign ^ arg6) - sign;
    *(f32 *)((u8 *)arg0 + 0x248) = farg0;
    *(f32 *)((u8 *)arg0 + 0x24C) = farg1;
    *(void **)arg0 = vt;
    *(u8 *)((u8 *)arg0 + 0x244) = 0;
    *(s32 *)((u8 *)arg0 + 0x254) = size;
    *(u8 *)((u8 *)arg0 + 0x258) = (u32)arg6 >> 31;
    *(s32 *)((u8 *)arg0 + 0x25C) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9B0);
    *(s32 *)((u8 *)arg0 + 0x260) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9BC);
    *(s32 *)((u8 *)arg0 + 0x264) = *(s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 0x268) = *(s32 *)((u8 *)arg0 + 8);
    *(s32 *)((u8 *)arg0 + 0x26C) = ((Vf78 *)arg0)->get();
    len = *(s32 *)((u8 *)arg0 + 8);
    end = *(s32 *)((u8 *)arg0 + 0x10);
    *(s32 *)((u8 *)arg0 + 0x270) = end - len;
    count = ((s32 (*)(s32))fn_802C5220)(*(s32 *)((u8 *)arg0 + 0x25C));
    len = *(s32 *)((u8 *)arg0 + 8);
    end = *(s32 *)((u8 *)arg0 + 0x10);
    if (end - len > count) count = end - len;
    ((void (*)(void *, s32, s32))fn_80219284)(arg0, ((Vf78 *)arg0)->get() - 1, count);
    ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 0, (void *)arg5, 4);
    *(s32 *)((u8 *)arg0 + 0x274) = 0;
    *(s32 *)((u8 *)arg0 + 0x278) = fn_80228F40(arg1, arg2);
    return arg0;
}
#pragma pop

extern "C" void fn_8021F7EC(void *arg0) {
    void *value;

    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C),
                            *(s32 *)((u8 *)arg0 + 0x278), arg0);
        *(void **)((u8 *)arg0 + 0x274) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 1, value, 4);
    }
}

extern "C" f32 lbl_80563518;
#pragma push
#pragma opt_common_subs off
extern "C" s32 fn_8021F848(void *arg0, s32 arg1) {
    s32 *idx = *(s32 **)((u8 *)arg0 + 0x274);
    if (idx == 0) return 0;
    if (*(s32 *)((u8 *)arg0 + 0x278) != *idx) return 0;
    f32 *value = *(f32 **)((u8 *)arg0 + 0x250);
    f32 old = *value;
    switch (arg1) {
    case 0x127: {
        f32 min = *(f32 *)((u8 *)arg0 + 0x248);
        f32 max = *(f32 *)((u8 *)arg0 + 0x24c);
        s32 n = *(s32 *)((u8 *)arg0 + 0x254) - 1;
        f32 span = max - min;
        f32 delta = old - min;
        s32 step = (s32)(lbl_80563518 + (f32)n * delta / span) + 1;
        f32 t = min + (f32)step * span / (f32)n;
        if (t < min) t = min;
        if (t > *(f32 *)((u8 *)arg0 + 0x24c)) t = *(f32 *)((u8 *)arg0 + 0x24c);
        *value = t;
        if ((f32)__fabs((double)(**(f32 **)((u8 *)arg0 + 0x250) - old)) <= *(f32 *)&lbl_80558DC4) fn_80216D28();
        return 1;
    }
    case 0x125: {
        f32 min = *(f32 *)((u8 *)arg0 + 0x248);
        f32 max = *(f32 *)((u8 *)arg0 + 0x24c);
        s32 n = *(s32 *)((u8 *)arg0 + 0x254) - 1;
        f32 span = max - min;
        f32 delta = old - min;
        s32 step = (s32)(lbl_80563518 + (f32)n * delta / span) - 1;
        f32 t = min + (f32)step * span / (f32)n;
        if (t < min) t = min;
        if (t > *(f32 *)((u8 *)arg0 + 0x24c)) t = *(f32 *)((u8 *)arg0 + 0x24c);
        *value = t;
        if ((f32)__fabs((double)(**(f32 **)((u8 *)arg0 + 0x250) - old)) <= *(f32 *)&lbl_80558DC4) fn_80216D28();
        return 1;
    }
    case 0x126: {
        void *obj = *(void **)((u8 *)arg0 + 0x2C);
        if (*(s32 *)((u8 *)obj + 0x494) > 1) { fn_80217D84((s32)obj); return 1; }
        break;
    }
    case 0x128: {
        void *obj = *(void **)((u8 *)arg0 + 0x2C);
        if (*(s32 *)((u8 *)obj + 0x494) > 1) { fn_80217C4C((s32)obj); return 1; }
        break;
    }
    }
    return 0;
}
#pragma pop
extern "C" s32 fn_8021FBC4(void *, s32, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021FA98(void *arg0, s32 arg1, s32 arg2) {
    register s32 temp_r3;
    register s32 temp_r4;
    register s32 temp_r5;
    register s32 temp_r6;
    register f32 high;
    register f32 low;
    f32 range;
    f32 dist;
    f32 fraction;
    f32 result;
    s32 span;
    s32 step;
    if (*(u8 *)((u8 *)arg0 + 0x244) == 0) {
        return;
    }
    if (fn_8021FBC4(arg0, arg1, arg2) == 0) {
        return;
    }
    temp_r5 = *(s32 *)((u8 *)arg0 + 0x254);
    temp_r4 = *(s32 *)((u8 *)arg0 + 0x26C);
    temp_r3 = *(s32 *)((u8 *)arg0 + 0x264);
    temp_r6 = temp_r5 - 1;
    high = *(f32 *)((u8 *)arg0 + 0x24C);
    low = *(f32 *)((u8 *)arg0 + 0x248);
    range = high - low;
    span = temp_r4 - temp_r4 / temp_r5;
    temp_r3 = arg1 - temp_r3;
    dist = ((f32)temp_r3 * range) / (f32)span;
    fraction = ((f32)temp_r6 * (low + dist - low)) / range;
    step = (s32)(lbl_80563518 + fraction);
    result = low + (((f32)step * range) / (f32)temp_r6);
    if (result < low) {
        result = low;
    }
    if (result > *(f32 *)((u8 *)arg0 + 0x24C)) {
        result = *(f32 *)((u8 *)arg0 + 0x24C);
    }
    **(f32 **)((u8 *)arg0 + 0x250) = result;
}
#pragma scheduling on
#pragma pop
extern "C" s32 fn_8021FBC4(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r6;
    s32 var_r7 = 0;
    s32 var_r8 = 0;
    s32 var_r9 = 0;
    temp_r6 = *(s32 *)((u8 *)arg0 + 0x264);
    if ((arg1 >= temp_r6 - 0x14) && (arg1 < temp_r6 + *(s32 *)((u8 *)arg0 + 0x26C) + 0x14)) {
        var_r9 = 1;
    }
    if ((var_r9 != 0) && (arg2 >= *(s32 *)((u8 *)arg0 + 0x268) - 0x14)) {
        var_r8 = 1;
    }
    if ((var_r8 != 0) && (arg2 < *(s32 *)((u8 *)arg0 + 0x268) + *(s32 *)((u8 *)arg0 + 0x270) + 0x14)) {
        var_r7 = 1;
    }
    return var_r7;
}

extern "C" void fn_8021FC40(void *arg0, s32 arg1) {
    s32 *temp_r5;
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;
    register s32 var_r28;
    fn_802C3034(arg1);
    ((void (*)(void *, s32))fn_802192A0)(arg0, arg1);
    temp_r29 = (s32)(((f32)(((VfObj *)arg0)->vf28() - 11) * (**(f32 **)((u8 *)arg0 + 0x250) - *(f32 *)((u8 *)arg0 + 0x248))) / (*(f32 *)((u8 *)arg0 + 0x24C) - *(f32 *)((u8 *)arg0 + 0x248)));
    var_r28 = 0;
    temp_r5 = *(s32 **)((u8 *)arg0 + 0x274);
    if (temp_r5 != 0) {
        if (*temp_r5 == *(s32 *)((u8 *)arg0 + 0x278)) {
            var_r28 = 1;
            temp_r31 = *(s32 *)((u8 *)arg0 + 8);
            temp_r30 = *(s32 *)((u8 *)arg0 + 4);
            fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x25C), temp_r30, temp_r31, ((VfObj *)arg0)->vf28(), var_r28);
        }
    }
    fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x260), *(s32 *)((u8 *)arg0 + 4) + 5, *(s32 *)((u8 *)arg0 + 8) + 5, temp_r29, var_r28);
}

extern "C" s32 fn_802C5334(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
extern "C" void fn_8021FD68(void *arg0, s32 arg1) {
    VfObj *obj = (VfObj *)arg0;
    s32 step = obj->vf28() - 11;
    s32 progress;
    s32 active = 0;
    s32 *mode = *(s32 **)((u8 *)arg0 + 0x274);
    progress = (s32)(((f32)step * (**(f32 **)((u8 *)arg0 + 0x250) - *(f32 *)((u8 *)arg0 + 0x248))) / (*(f32 *)((u8 *)arg0 + 0x24C) - *(f32 *)((u8 *)arg0 + 0x248)));
    if (mode != 0 && *mode == *(s32 *)((u8 *)arg0 + 0x278)) {
        s32 range = obj->vf28();
        s32 centerX = ((s32)(lbl_8055FB9C + ((u32)lbl_8055FB9C >> 31)) >> 1);
        s32 centerY = ((s32)(lbl_8055FBA0 + ((u32)lbl_8055FBA0 >> 31)) >> 1);
        f32 x = (f32)(*(s32 *)((u8 *)arg0 + 4) - centerX);
        f32 y = (f32)(centerY - *(s32 *)((u8 *)arg0 + 8));
        f32 z = (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
        f32 fRange = (f32)range;
        active = 1;
        fn_802C5320(*(s32 *)((u8 *)arg0 + 0x25C), active, x, y, lbl_805634A8, fRange, z);
        ((s32 (*)(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32))fn_802C5334)(*(s32 *)((u8 *)arg0 + 0x260), active, x, y, lbl_805634A8, (f32)progress, z, lbl_805634A8, lbl_805634A8, (f32)progress / fRange, lbl_805634A4);
    }
}
#pragma pop

#pragma paired_single off
extern "C" void *fn_8021FF34(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_r4;
    s32 temp_r8;
    temp_r8 = *(s32 *)((u8 *)arg1 + 0xC);
    temp_r4 = *(s32 *)((u8 *)arg1 + 8);
    fn_80218F34(arg0, temp_r4, temp_r8,
                temp_r4 + *(s32 *)((u8 *)arg1 + 0x14),
                temp_r8 + *(s32 *)((u8 *)arg1 + 0x18), 0);
    temp_f2 = farg1 - farg0;
    *(void **)arg0 = lbl_8033E7F4;
    *(s32 *)((u8 *)arg0 + 0x244) = arg2;
    *(f32 *)((u8 *)arg0 + 0x248) = farg0;
    *(f32 *)((u8 *)arg0 + 0x24C) = farg1;
    *(f32 *)((u8 *)arg0 + 0x250) = temp_f2 / (f32)arg3;
    *(s32 *)((u8 *)arg0 + 0x254) =
        ((s32 (*)(void *, void *))fn_802C5130)(lbl_8033D9BC, lbl_8033E7F4);
    *(s32 *)((u8 *)arg0 + 0x258) = 0;
    *(s32 *)((u8 *)arg0 + 0x25C) =
        fn_80228F40(*(s32 *)((u8 *)arg1 + 8),
                    *(s32 *)((u8 *)arg1 + 0xC));
    temp_f0 = fn_8023659C() - lbl_805634E8;
    *(f32 *)((u8 *)arg0 + 0x264) = temp_f0;
    *(f32 *)((u8 *)arg0 + 0x260) = temp_f0;
    return arg0;
}
extern "C" u8 lbl_8033E7F4[];
extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv_8022003C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_8033E7F4;
        fn_802C519C(*(void**)((u8*)arg0 + 0x254));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" s32 fn_80211660(s32);
extern "C" f32 lbl_80563508;
extern "C" f32 lbl_8056350C;
#pragma push
#pragma processor 750
extern "C" void fn_802200AC(void *arg0) {
    f32 *value = *(f32 **)((u8 *)arg0 + 0x244);
    f32 scale;
    if (value != 0) {
        scale = (*value - *(f32 *)((u8 *)arg0 + 0x248)) / (*(f32 *)((u8 *)arg0 + 0x24C) - *(f32 *)((u8 *)arg0 + 0x248));
    } else {
        scale = lbl_805634A4;
    }
    f32 sp14 = lbl_805634A8;
    f32 sp10 = lbl_805634A8;
    f32 sp8 = lbl_805634A4;
    fn_80230C30(&sp14, &sp10, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    f32 step = (f32)((VfObj *)arg0)->vf28();
    f32 range = (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
    f32 progress = scale * (f32)fn_802C51C0(*(s32 *)((u8 *)arg0 + 0x254));
    f32 height = (f32)fn_802C5220(*(s32 *)((u8 *)arg0 + 0x254));
    s32 enabled = 0;
    s32 *mode = *(s32 **)((u8 *)arg0 + 0x258);
    if (mode != 0 && *mode == *(s32 *)((u8 *)arg0 + 0x25C))
        enabled = 1;
    f32 adj = step - (f32)fn_802C51C0(*(s32 *)((u8 *)arg0 + 0x254));
    f32 t = lbl_805634C4 * adj;
    s32 stateB;
    s32 a;
    s32 b;
    s32 colorA;
    s32 colorB;
    ((s32 (*)(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32))fn_802C5334)(
        *(s32 *)((u8 *)arg0 + 0x254), enabled, sp14 + t, sp10 + (height - range) * lbl_805634C4, lbl_805634A8, progress, height, lbl_805634A8, lbl_805634A8, scale, sp14, t);
    a = fn_80211660(0);
    b = fn_80211660(1);
    s32 check = 0;
    s32 *mode2 = *(s32 **)((u8 *)arg0 + 0x258);
    if (mode2 != 0 && *mode2 == *(s32 *)((u8 *)arg0 + 0x25C))
        check = 1;
    if (check != 0) {
        if (lbl_805634E8 + *(f32 *)((u8 *)arg0 + 0x260) > fn_8023659C())
            enabled = 2;
        else
            enabled = 1;
    } else {
        enabled = 0;
    }
    s32 check2 = 0;
    s32 *mode3 = *(s32 **)((u8 *)arg0 + 0x258);
    if (mode3 != 0 && *mode3 == *(s32 *)((u8 *)arg0 + 0x25C))
        check2 = 1;
    if (check2 != 0) {
        if (lbl_805634E8 + *(f32 *)((u8 *)arg0 + 0x264) > fn_8023659C())
            stateB = 2;
        else
            stateB = 1;
    } else {
        stateB = 0;
    }
    f32 timeA = fn_8023659C();
    f32 cA = lbl_805634A4;
    f32 tA = ((lbl_805634E8 + *(f32 *)((u8 *)arg0 + 0x260)) - timeA - lbl_805634A8) / lbl_805634E8;
    cA = (cA < tA) ? cA : tA;
    cA = (cA > lbl_805634A8) ? cA : lbl_805634A8;
    height = lbl_805634A8 + cA * lbl_805634C8;
    f32 timeB = fn_8023659C();
    f32 cB = lbl_805634A4;
    f32 tB = ((lbl_805634E8 + *(f32 *)((u8 *)arg0 + 0x264)) - timeB - lbl_805634A8) / lbl_805634E8;
    cB = (cB < tB) ? cB : tB;
    cB = (cB > lbl_805634A8) ? cB : lbl_805634A8;
    progress = lbl_805634A8 + cB * lbl_805634C8;
    height = (sp14 - fn_80235EF0(a, enabled)) - height;
    step = progress + (sp14 + step);
    colorA = -1;
    colorB = -1;
    if (scale <= *(f32 *)&lbl_80558DC4) {
        f32 timeC = fn_8023659C();
        f32 c = lbl_805634A4;
        f32 t2 = ((timeC - *(f32 *)((u8 *)arg0 + 0x260)) - lbl_805634A8) / lbl_80563504;
        c = (c < t2) ? c : t2;
        c = (c > lbl_805634A8) ? c : lbl_805634A8;
        colorA = ((s32)(lbl_80563508 + c * lbl_8056350C) << 24) | 0xFFFFFF;
    }
    if (scale >= lbl_805634A4 - *(f32 *)&lbl_80558DC4) {
        f32 timeD = fn_8023659C();
        f32 c = lbl_805634A4;
        f32 t2 = ((timeD - *(f32 *)((u8 *)arg0 + 0x264)) - lbl_805634A8) / lbl_80563504;
        c = (c < t2) ? c : t2;
        c = (c > lbl_805634A8) ? c : lbl_805634A8;
        colorB = ((s32)(lbl_80563508 + c * lbl_8056350C) << 24) | 0xFFFFFF;
    }
    if (a != 0) {
        f32 e = fn_80235EF0(a, enabled);
        f32 h = fn_80235F64(a, enabled);
        fn_802354A0(a, enabled, colorA, height, sp10 + lbl_805634C4 * (h - range), lbl_805634A8, e, h);
    }
    if (b != 0) {
        f32 e = fn_80235EF0(b, stateB);
        f32 h = fn_80235F64(b, stateB);
        fn_802354A0(b, stateB, colorB, step, sp10 + lbl_805634C4 * (h - range), lbl_805634A8, e, h);
    }
}
#pragma pop
extern "C" s32 fn_802205AC(void *arg0, s32 arg1) {
    s32 *p;
    f32 *value;
    f32 step;
    f32 bound;
    f32 result;
    s32 temp;
    p = *(s32 **)((u8 *)arg0 + 0x258);
    if (p != 0 && *p != *(s32 *)((u8 *)arg0 + 0x25C))
        return 0;
    temp = 1;
    switch (arg1) {
    case 0x127:
        value = *(f32 **)((u8 *)arg0 + 0x244);
        if (value != 0 && *value != *(f32 *)((u8 *)arg0 + 0x24C)) {
            *(f32 *)((u8 *)arg0 + 0x264) = fn_8023659C();
            value = *(f32 **)((u8 *)arg0 + 0x244);
            step = *(f32 *)((u8 *)arg0 + 0x250);
            bound = *(f32 *)((u8 *)arg0 + 0x24C);
            result = step + *value;
            result = result >= bound ? bound : result;
            *value = result;
        }
        break;
    case 0x125:
        value = *(f32 **)((u8 *)arg0 + 0x244);
        if (value != 0 && *value != *(f32 *)((u8 *)arg0 + 0x248)) {
            *(f32 *)((u8 *)arg0 + 0x260) = fn_8023659C();
            value = *(f32 **)((u8 *)arg0 + 0x244);
            step = *(f32 *)((u8 *)arg0 + 0x250);
            bound = *(f32 *)((u8 *)arg0 + 0x248);
            result = *value - step;
            result = result <= bound ? bound : result;
            *value = result;
        }
        break;
    case 0x126:
        if (*(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
        } else {
            return 0;
        }
        break;
    case 0x128:
        if (*(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
        } else {
            return 0;
        }
        break;
    default:
        return 0;
    }
    return temp;
}

extern "C" void fn_8022071C(void *arg0) {
    void *result;
    if (fn_80129BC4() != 0) {
        result=fn_80217BD8(*(s32 *)((u8 *)arg0+0x2C),*(s32 *)((u8 *)arg0+0x25C),arg0);
        *(void **)((u8 *)arg0+0x258)=result;
        ((void (*)(void *,s32,void *,s32))fn_80219440)(arg0,1,result,4);
    }
}

extern "C" void *fn_80220778(void *self, s32 x, s32 y, s32 width, s32 height, s32 param244, s32 param250, s32 param254) {
    extern void *lbl_8033E668[];
    /* Initializes a slider-like UI object: sets bounds, vtable, image resources, and an initial value. */
    fn_80218F34(self, x, y, x + width, y + height, 0);
    *(s32 *)((u8 *)self + 0x244) = param244;
    *(void **)self = lbl_8033E668;
    *(s32 *)((u8 *)self + 0x250) = param250;
    *(s32 *)((u8 *)self + 0x254) = param254;
    fn_80219440(self, 0, (void *)param244, 4);
    *(s32 *)((u8 *)self + 0x248) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9B0);
    *(s32 *)((u8 *)self + 0x24C) = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9BC);
    if (*(s32 *)((u8 *)self + 0x248) != 0) {
        s32 count = fn_802C5220(*(s32 *)((u8 *)self + 0x248));
        fn_80219284(self, ((Vf78 *)self)->get(), count);
    }
    *(u8 *)((u8 *)self + 0x258) = 0;
    *(s32 *)((u8 *)self + 0x25C) = 0;
    *(s32 *)((u8 *)self + 0x260) = fn_80228F40(x, y);
    return self;
}

extern "C" void *lbl_8033E668[];
extern "C" void *fn_80220874(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E668;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x248));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x24C));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802208EC(void *arg0) {
    void *value;
    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C),
                            *(s32 *)((u8 *)arg0 + 0x260), arg0);
        *(void **)((u8 *)arg0 + 0x25C) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 1, value, 4);
    }
}

extern "C" s32 fn_80220948(void *menu, s32 msg) {
    // Validate cached selection state pointer before handling menu navigation.
    s32 *selection = *(s32 **)((u8 *)menu + 0x25C);
    if (selection == 0)
        return 0;
    if (*(s32 *)((u8 *)menu + 0x260) != *selection)
        return 0;
    switch (msg) {
    case 0x127: {
        s32 *index = *(s32 **)((u8 *)menu + 0x244);
        if (*index < *(s32 *)((u8 *)menu + 0x254) - 1)
            *index = *index + 1;
        else
            fn_80216D28();
        return 1;
    }
    case 0x125: {
        s32 *index = *(s32 **)((u8 *)menu + 0x244);
        if (*index > *(s32 *)((u8 *)menu + 0x250))
            *index = *index - 1;
        else
            fn_80216D28();
        return 1;
    }
    case 0x126:
        if (*(s32 *)((u8 *)*(void **)((u8 *)menu + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)menu + 0x2C));
            return 1;
        }
        goto done;
    case 0x128:
        if (*(s32 *)((u8 *)*(void **)((u8 *)menu + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)menu + 0x2C));
            return 1;
        }
    done:
    default:
        return 0;
    }
}

extern "C" void fn_80220A50(void *arg0, s32 arg1) {
    struct Dispatch {
        virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
        virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7();
        virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11();
        virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15();
        virtual s32 v16(); virtual s32 v17(); virtual s32 v18(); virtual s32 v19();
        virtual s32 v20(); virtual s32 v21(); virtual s32 v22(); virtual s32 v23();
        virtual s32 v24(); virtual s32 v25(); virtual s32 v26(); virtual s32 v27();
        virtual s32 get();
    };
    *(u8 *)((u8 *)arg0 + 0x258) = 1;
    register s32 frame = arg1;
    register s32 field4 = *(s32 *)((u8 *)arg0 + 4);
    register s32 field250 = *(s32 *)((u8 *)arg0 + 0x250);
    s32 duration = ((Dispatch *)arg0)->get();
    register s32 range = *(volatile s32 *)((u8 *)arg0 + 0x254);
    register s32 time = frame - field4;
    time -= 5;
    register s32 distance = range - field250;
    register s32 adjusted = distance * time;
    duration -= 10;
    adjusted /= duration;
    register s32 result = field250;
    result = result + adjusted;
    result = result < field250 ? field250 : result;
    register s32 max = *(volatile s32 *)((u8 *)arg0 + 0x254);
    max -= 1;
    result = result >= max ? max : result;
    *(s32 *)*(void **)((u8 *)arg0 + 0x244) = result;
}

extern "C" void fn_80220AFC(void *arg0) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void call();
    };
    ((Dispatch *)arg0)->call();
    *(u8 *)((u8 *)arg0 + 0x258) = 0;
}

extern "C" void fn_80220B3C(void *arg0) {
    struct Local {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void call();
    };
    if (*(u8 *)((u8 *)arg0 + 0x258) != 0)
        ((Local *)arg0)->call();
}

extern "C" void fn_80220B5C(void *arg0, s32 arg1) {
    s32 v0;
    s32 *entries;
    s32 *p;
    s32 flag;
    u32 cur;
    s32 f8b;
    s32 f4b;
    s32 div;
    s32 v1;
    fn_802C3034(arg1);
    v0 = ((VfObj *)arg0)->vf28();
    entries = *(s32 **)((u8 *)arg0 + 0x244);
    p = *(s32 **)((u8 *)arg0 + 0x25C);
    flag = 0;
    cur = *(u32 *)((u8 *)arg0 + 0x250);
    div = ((*entries - (s32)cur) * (v0 - 11)) / ((s32)*(s32 *)((u8 *)arg0 + 0x254) - (s32)cur - 1);
    if (p != 0 && *p == *(s32 *)((u8 *)arg0 + 0x260)) {
        flag = 1;
    }
    f8b = *(s32 *)((u8 *)arg0 + 8);
    f4b = *(s32 *)((u8 *)arg0 + 4);
    v1 = ((VfObj *)arg0)->vf28();
    fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x248), f4b, f8b, v1, flag);
    fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x24C), *(s32 *)((u8 *)arg0 + 4) + 5, *(s32 *)((u8 *)arg0 + 8) + 5, div, flag);
}

#pragma push
#pragma processor 750
extern "C" void fn_80220C54(void *arg0) {
    register void *self = arg0;
    register s32 size;
    s32 *entries;
    s32 current;
    s32 *check;
    s32 target;
    register s32 enabled;
    s32 e0;
    s32 h = ((Vf78 *)self)->get() - 0xB;
    entries = *(s32 **)((u8 *)self + 0x244);
    check = *(s32 **)((u8 *)self + 0x25C);
    enabled = 0;
    current = *(s32 *)((u8 *)self + 0x250);
    e0 = *entries;
    target = *(s32 *)((u8 *)self + 0x254);
    size = h * (e0 - current) / (target - current - 1);
    if (check != 0 && *check == *(s32 *)((u8 *)self + 0x260))
        enabled = 1;
    s32 centerX = ((s32)(lbl_8055FB9C + ((u32)lbl_8055FB9C >> 31)) >> 1);
    s32 centerY = ((s32)(lbl_8055FBA0 + ((u32)lbl_8055FBA0 >> 31)) >> 1);
    f32 x = (f32)(*(s32 *)((u8 *)self + 4) - centerX);
    f32 y = (f32)(centerY - *(s32 *)((u8 *)self + 8));
    f32 previous = (f32)fn_802C5220(*(s32 *)((u8 *)self + 0x248));
    f32 value = (f32)((Vf78 *)self)->get();
    fn_802C5320(*(s32 *)((u8 *)self + 0x248), enabled, x, y,
                lbl_805634A8, value, previous);
    f32 following = (f32)fn_802C5220(*(s32 *)((u8 *)self + 0x24C));
    fn_802C5320(*(s32 *)((u8 *)self + 0x24C), enabled,
                lbl_805634E0 + x, y - lbl_805634E0,
                lbl_805634A8, (f32)size, following);
}
#pragma pop

extern "C" void fn_802C40B8(s32, s32, s32);
extern "C" void fn_80220E08(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    fn_802C40B8(*(s32 *)((u8 *)arg0 + 0x244), *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
}

/* Initializes a UI panel with textures based on mode. */
extern "C" void *fn_80220E48(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct Dispatch {
        virtual void method0();
        virtual void method1();
        virtual void method2();
        virtual void method3();
        virtual void method4();
        virtual void set(s32 x, s32 y);
    };
    u8 *p = (u8 *)arg0;
    char *strBase = lbl_8033D878;
    s32 value = arg5;
    s32 mode = arg6;
    fn_80218F34(arg0, arg1, arg2, arg1 + arg3, arg2 + arg4, 0);
    *(void **)p = lbl_8033E770;
    if (mode == 0) {
        *(s32 *)(p + 0x248) = ((s32 (*)(void *))fn_802C5130)(strBase + 0x150);
        *(s32 *)(p + 0x24C) = ((s32 (*)(void *))fn_802C5130)(strBase + 0x15C);
    } else {
        *(s32 *)(p + 0x248) = ((s32 (*)(void *))fn_802C5130)(strBase + 0x168);
        *(s32 *)(p + 0x24C) = ((s32 (*)(void *))fn_802C5130)(strBase + 0x174);
    }
    ((Dispatch *)arg0)->set(*(s32 *)(p + 4), *(s32 *)(p + 8));
    if (mode == 0) {
        fn_80219284(arg0, fn_802C51C0(*(s32 *)(p + 0x248)),
                    *(s32 *)(p + 0x10) - *(s32 *)(p + 8));
    } else {
        s32 width = fn_802C5220(*(s32 *)(p + 0x248));
        s32 height = ((Vf78 *)arg0)->get();
        fn_80219284(arg0, height, width);
    }
    *(s32 *)(p + 0x244) = value;
    *(s32 *)(p + 0x254) = mode;
    fn_80219440(arg0, 0, (void *)value, 0xC);
    *(u8 *)(p + 0x250) = 0;
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80220F90(void *arg0, s32 arg1, s32 arg2) {
    class Vf78Arg {
    public:
        virtual void a0() = 0; virtual void a1() = 0; virtual void a2() = 0; virtual void a3() = 0;
        virtual void a4() = 0; virtual void a5() = 0; virtual void a6() = 0; virtual void a7() = 0;
        virtual void a8() = 0; virtual void a9() = 0; virtual void a10() = 0; virtual void a11() = 0;
        virtual void a12() = 0; virtual void a13() = 0; virtual void a14() = 0; virtual void a15() = 0;
        virtual void a16() = 0; virtual void a17() = 0; virtual void a18() = 0; virtual void a19() = 0;
        virtual void a20() = 0; virtual void a21() = 0; virtual void a22() = 0; virtual void a23() = 0;
        virtual void a24() = 0; virtual void a25() = 0; virtual void a26() = 0; virtual void a27() = 0;
        virtual s32 get(void *) = 0;
    };
    f32 scale;
    f32 scale2;
    f32 factor;
    f32 distance;
    f32 adjusted;
    s32 width;
    s32 end;
    s32 end2;
    s32 end3;
    s32 end4;
    s32 end5;
    s32 end6;
    s32 begin;
    s32 begin2;
    s32 begin3;
    s32 begin4;
    s32 size;
    s32 size2;
    s32 childBase;
    s32 childEnd;
    void *child;
    void *child2;

    *(s8 *)((u8 *)arg0 + 0x250) = 1;
    if (*(s32 *)((u8 *)arg0 + 0x254) == 0) {
        child = *(void **)((u8 *)arg0 + 0x244);
        scale = (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8)) / (f32)*(s32 *)child;
        begin = *(s32 *)((u8 *)arg0 + 8) + (s32)(scale * (f32)(*(s32 *)((u8 *)child + 8))) + 5;
        end = *(s32 *)((u8 *)arg0 + 8) + (s32)(scale * (f32)((*(s32 *)((u8 *)child + 8)) + *(s32 *)((u8 *)child + 4))) - 5;
        if (arg2 >= begin && arg2 <= end) {
            *(s32 *)((u8 *)arg0 + 0x25C) = (s32)(scale * (f32)(*(s32 *)((u8 *)child + 8))) - arg2;
            return;
        }
        if (arg2 < begin) {
            size2 = (s32)((f32)(*(s32 *)((u8 *)child + 8)) - ((lbl_805634A4 / scale) * (f32)((end - begin) + 5)));
            *(s32 *)((u8 *)child + 8) = size2;
            end2 = *(s32 *)child - *(s32 *)((u8 *)child + 4);
            if (size2 > end2) {
                *(s32 *)((u8 *)child + 8) = end2;
            }
            if (*(s32 *)((u8 *)child + 8) < 0) {
                *(s32 *)((u8 *)child + 8) = 0;
            }
        } else {
            factor = lbl_805634A4 / scale;
            distance = (f32)((end - begin) + 5);
            adjusted = distance * factor;
            size2 = (s32)(adjusted + (f32)(*(s32 *)((u8 *)child + 8)));
            *(s32 *)((u8 *)child + 8) = size2;
            end2 = *(s32 *)child - *(s32 *)((u8 *)child + 4);
            if (size2 > end2) {
                *(s32 *)((u8 *)child + 8) = end2;
            }
            if (*(s32 *)((u8 *)child + 8) < 0) {
                *(s32 *)((u8 *)child + 8) = 0;
            }
        }
        *(s8 *)((u8 *)arg0 + 0x250) = 0;
        return;
    }

    child2 = *(void **)((u8 *)arg0 + 0x244);
    childBase = *(s32 *)child2;
    scale2 = (f32)((Vf78Arg *)arg0)->get(child2) / (f32)childBase;
    child = *(void * volatile *)((u8 *)arg0 + 0x244);
    begin2 = *(s32 *)((u8 *)arg0 + 4) + (s32)(scale2 * (f32)*(s32 *)((u8 *)child + 8)) + 5;
    end3 = *(s32 *)((u8 *)arg0 + 4) + (s32)(scale2 * (f32)(*(s32 *)((u8 *)child + 8) + *(s32 *)((u8 *)child + 4))) - 5;
    if (arg1 >= begin2 && arg1 <= end3) {
        *(s32 *)((u8 *)arg0 + 0x258) = (s32)(scale2 * (f32)*(s32 *)((u8 *)child + 8)) - arg1;
        return;
    }
    if (arg1 < begin2) {
        size2 = (s32)((f32)*(s32 *)((u8 *)child + 8) - ((lbl_805634A4 / scale2) * (f32)((end3 - begin2) + 5)));
        *(s32 *)((u8 *)child + 8) = size2;
        end4 = *(s32 *)child - *(s32 *)((u8 *)child + 4);
        if (size2 > end4) {
            *(s32 *)((u8 *)child + 8) = end4;
        }
        if (*(s32 *)((u8 *)child + 8) < 0) {
            *(s32 *)((u8 *)child + 8) = 0;
        }
    } else {
        factor = lbl_805634A4 / scale2;
        distance = (f32)((end3 - begin2) + 5);
        adjusted = distance * factor;
        size2 = (s32)(adjusted + (f32)*(s32 *)((u8 *)child + 8));
        *(s32 *)((u8 *)child + 8) = size2;
        end5 = *(s32 *)child - *(s32 *)((u8 *)child + 4);
        if (size2 > end5) {
            *(s32 *)((u8 *)child + 8) = end5;
        }
        if (*(s32 *)((u8 *)child + 8) < 0) {
            *(s32 *)((u8 *)child + 8) = 0;
        }
    }
    *(s8 *)((u8 *)arg0 + 0x250) = 0;
}
#pragma pop
extern "C" void fn_802213A4(void *arg0, s32 arg1, s32 arg2) {
    void *state;
    s32 value;
    if (*(u8 *)((u8 *)arg0 + 0x250) == 0) return;
    if (*(s32 *)((u8 *)arg0 + 0x254) == 0) {
        state = *(void **)((u8 *)arg0 + 0x244);
        value = (s32)(((f32)*(s32 *)state / (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8))) * (f32)(arg2 + *(s32 *)((u8 *)arg0 + 0x25C)));
        *(s32 *)((u8 *)state + 8) = value;
        if (value > *(s32 *)state - *(s32 *)((u8 *)state + 4)) *(s32 *)((u8 *)state + 8) = *(s32 *)state - *(s32 *)((u8 *)state + 4);
        if (*(s32 *)((u8 *)state + 8) < 0) *(s32 *)((u8 *)state + 8) = 0;
    } else {
        s32 den;
        s32 num = *(s32 *)(*(void **)((u8 *)arg0 + 0x244));
        den = ((Vf78 *)arg0)->get();
        value = (s32)(((f32)num / (f32)den) * (f32)(arg1 + *(s32 *)((u8 *)arg0 + 0x258)));
        state = *(void **)((u8 *)arg0 + 0x244);
        *(s32 *)((u8 *)state + 8) = value;
        if (value > *(s32 *)state - *(s32 *)((u8 *)state + 4)) *(s32 *)((u8 *)state + 8) = *(s32 *)state - *(s32 *)((u8 *)state + 4);
        if (*(s32 *)((u8 *)state + 8) < 0) *(s32 *)((u8 *)state + 8) = 0;
    }
}

extern "C" void fn_80221538(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x250) = 0;
}

extern "C" void fn_80228E80(s32, s32, s32, s32, s32, s32);
extern "C" s32 lbl_8055FBE0;
extern "C" s32 lbl_8055FBFC;
#pragma push
#pragma processor 750
extern "C" void fn_80221544(void *arg0, s32 arg1) {
    struct Child { s32 base; s32 length; s32 offset; };
    struct Object {
        u8 pad0[4]; s32 x; s32 y; u8 padC[4]; s32 end;
        u8 pad14[0x230]; Child *child; s32 texture; s32 overlay; s32 state; s32 flag;
    };
    Object *self = (Object *)arg0;
    Child *child;
    s32 childBase;
    fn_802C3034(arg1);
    if (self->flag == 0) {
        fn_80228E80(arg1, self->texture, self->x, self->y,
                    self->end - self->y, 0);
    } else {
        s32 top = self->y;
        s32 result = ((Vf78 *)arg0)->get();
        s32 left = self->x;
        fn_80228DC4(arg1, self->texture, left, top, result, 0);
    }
    child = self->child;
    childBase = child->base;
    if (child->length < childBase) {
        if (self->flag == 0) {
            s32 left = self->x + 1;
            s32 top = self->y;
            f32 scale = (f32)(self->end - top) / (f32)childBase;
            s32 scroll = ((Vf78 *)arg0)->get();
            s32 right = self->x + scroll - 1;
            child = self->child;
            s32 y0 = top + (s32)(scale * (f32)child->offset) + 5;
            s32 y1 = top + (s32)(scale * (f32)(child->offset + child->length)) - 5;
            if (y1 - 1 > y0 + 1 && right - 1 > left + 1) {
                s32 overlay = self->overlay;
                if (overlay != 0) {
                    s32 diff = fn_802C51C0(self->texture) - fn_802C51C0(overlay);
                    fn_80228E80(arg1, overlay, left + ((diff + (diff < 0)) >> 1),
                                y0, y1 - y0, 0);
                } else {
                    fn_802C3424(left, y0, right, y1, lbl_8055FBDC);
                    s32 color = lbl_8055FBE0;
                    fn_802C3424(left, y1 - 1, right, y1, color);
                    fn_802C3424(right - 1, y0, right, y1, color);
                    color = lbl_8055FBFC;
                    fn_802C3424(left, y0, right, y0 + 1, color);
                    fn_802C3424(left, y0, left + 1, y1, color);
                }
            }
        } else {
            s32 scroll = ((Vf78 *)arg0)->get();
            child = self->child;
            f32 scale = (f32)scroll / (f32)childBase;
            s32 left = self->x + (s32)(scale * (f32)child->offset) + 5;
            s32 right = self->x + (s32)(scale * (f32)(child->offset + child->length)) - 5;
            s32 top = self->y + 1;
            s32 bottom = self->end - 1;
            if (right - 1 > left + 1 && bottom - 1 > top + 1) {
                s32 overlay = self->overlay;
                if (overlay != 0) {
                    s32 diff = fn_802C5220(self->texture) - fn_802C5220(overlay);
                    fn_80228DC4(arg1, overlay, left, top + ((diff + (diff < 0)) >> 1),
                                right - left, 0);
                } else {
                    fn_802C3424(left, top, right, bottom, lbl_8055FBDC);
                    s32 color = lbl_8055FBE0;
                    fn_802C3424(left, bottom - 1, right, bottom, color);
                    fn_802C3424(right - 1, top, right, bottom, color);
                    color = lbl_8055FBFC;
                    fn_802C3424(left, top, right, top + 1, color);
                    fn_802C3424(left, top, left + 1, bottom, color);
                }
            }
        }
    }
}

extern "C" char lbl_8033D9F8[];
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
extern "C" void fn_80221970(void *arg0) {
    struct Child { s32 base; s32 length; s32 offset; };
    struct Object {
        u8 pad0[4]; s32 x; s32 y; u8 padC[4]; s32 end;
        u8 pad14[0x230]; Child *child; s32 texture; s32 overlay; s32 state; s32 flag;
    };
    Object *self = (Object *)arg0;
    Child *child;
    s32 base;
    s32 x;
    s32 left;
    s32 right;
    s32 y0;
    s32 y1;
    s32 diff;
    s32 color2;
    s32 color3;
    s32 scroll;
    s32 bottom;
    s32 top;
    f32 scale;
    f32 spC;
    f32 sp8;

    spC = (f32)(self->x - lbl_8055FB9C / 2);
    sp8 = (f32)(lbl_8055FBA0 / 2 - self->y);
    fn_802C5320(self->texture, 0, spC, sp8, lbl_805634A8,
                (f32)((Vf78 *)arg0)->get(), (f32)(self->end - self->y));
    child = self->child;
    base = child->base;
    if (child->length < base) {
        if (self->flag == 0) {
            x = self->x;
            left = x + 1;
            scale = (f32)(self->end - self->y) / (f32)base;
            scroll = ((Vf78 *)arg0)->get();
            right = x + scroll - 1;
            child = self->child;
            y0 = self->y + (s32)(scale * (f32)child->offset) + 5;
            y1 = self->y + (s32)(scale * (f32)(child->offset + child->length)) - 5;
            if (y1 - 1 > y0 + 1 && right - 1 > left + 1) {
                if (self->overlay != 0) {
                    diff = fn_802C51C0(self->texture) - fn_802C51C0(self->overlay);
                    fn_80230C30(&spC, &sp8, left + diff / 2, y0);
                    fn_802C5320(self->overlay, 0, spC, sp8, lbl_805634A8,
                                (f32)fn_802C51C0(self->overlay), (f32)(y1 - y0));
                } else {
                    fn_802E30C8(lbl_8033D9F8);
                    fn_802C3424(left, y0, right, y1, lbl_8055FBDC);
                    color2 = lbl_8055FBE0;
                    fn_802C3424(left, y1 - 1, right, y1, color2);
                    fn_802C3424(right - 1, y0, right, y1, color2);
                    color3 = lbl_8055FBFC;
                    fn_802C3424(left, y0, right, y0 + 1, color3);
                    fn_802C3424(left, y0, left + 1, y1, color3);
                }
            }
        } else {
            scroll = ((Vf78 *)arg0)->get();
            child = self->child;
            scale = (f32)scroll / (f32)base;
            top = self->y + 1;
            bottom = self->end - 1;
            left = self->x + (s32)(scale * (f32)child->offset) + 5;
            right = self->x + (s32)(scale * (f32)(child->offset + child->length)) - 5;
            if (right - 1 > left + 1 && bottom - 1 > top + 1) {
                if (self->overlay != 0) {
                    diff = fn_802C5220(self->texture) - fn_802C5220(self->overlay);
                    fn_80230C30(&spC, &sp8, left, top + diff / 2);
                    fn_802C5320(self->overlay, 0, spC, sp8, lbl_805634A8,
                                (f32)(right - left), (f32)fn_802C5220(self->overlay));
                } else {
                    fn_802E30C8(lbl_8033D9F8);
                    fn_802C3424(left, top, right, bottom, lbl_8055FBDC);
                    color2 = lbl_8055FBE0;
                    fn_802C3424(left, bottom - 1, right, bottom, color2);
                    fn_802C3424(right - 1, top, right, bottom, color2);
                    color3 = lbl_8055FBFC;
                    fn_802C3424(left, top, right, top + 1, color3);
                    fn_802C3424(left, top, left + 1, bottom, color3);
                }
            }
        }
    }
}
#pragma pop

#pragma pop
extern "C" void fn_80221E7C(void *arg0) {
    void *temp = *(void **)((u8 *)arg0 + 0x14);
    if (temp != 0 && *(u8 *)((u8 *)temp + 0x1A) != 0)
        *(u8 *)((u8 *)temp + 0x234) = 1;
}

#pragma dont_inline on
extern "C" void fn_80221EA0(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    fn_80219440(*(void **)((u8 *)arg0 + 0x14), arg1, arg2, arg3);
}
#pragma dont_inline reset
extern "C" s32 fn_80221EA8(void *arg0) {
    extern char lbl_8033DA2C[];
    void *tmp = *(void **)((u8 *)arg0 + 0x14);
    u32 value = *(u32 *)((u8 *)tmp + 0x238);
    for (s32 i = 0; i < 32; i++) {
        if (value == (1u << i)) {
            return i;
        }
    }
    fn_802E317C(lbl_8033DA2C);
    return 0;
}

extern "C" void fn_80221F94(void *arg0, s32 arg1) {
    fn_802168BC((void *)arg1);
}

extern "C" s32 lbl_8055FBE4;
extern "C" void fn_802C4F58(s32, s32, const char *, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80221F9C(void *arg0, s32 arg1) {
    s32 temp_r18;
    s32 temp_r20;
    s32 temp_r23;
    s32 temp_r28;
    s32 temp_r29;
    s32 temp_r30;
    s32 var_r18;
    s32 var_r20;
    s32 var_r22;
    s32 var_r24;
    s32 var_r25;
    s32 var_r26;
    s32 var_r27;
    s32 var_r31;
    void *temp_r21;
    s32 *items;
    fn_802C3034(arg1);
    temp_r18 = *(s32 *)((u8 *)arg0 + 4);
    temp_r20 = *(s32 *)((u8 *)arg0 + 8);
    var_r18 = ((VfObj *)arg0)->vf28();
    fn_802C3424(temp_r18, temp_r20, temp_r18 + var_r18, temp_r20 + 0xA, lbl_8055FBE4);
    var_r24 = *(s32 *)((u8 *)arg0 + 4);
    var_r22 = 0;
    temp_r23 = *(s32 *)((u8 *)arg0 + 8);
    var_r31 = 0;
    temp_r30 = lbl_8055FBC0;
    temp_r29 = lbl_8055FBFC;
    temp_r28 = lbl_8055FBF8;
    goto outer_check;
outer_body:
    temp_r21 = *(void **)((u8 *)items + var_r31);
    fn_802C4F58(var_r24 + 2, temp_r23 + 2, (const char *)((u8 *)items + var_r31 + 4), temp_r30);
    if (var_r22 == *(s32 *)((u8 *)arg0 + 0x24C)) {
        temp_r20 = *(s32 *)((u8 *)temp_r21 + 8);
        fn_802C3424(var_r24, temp_r23 + 0xA, var_r24 + 0x32, temp_r23 + (temp_r20 + 1) * 0xA, temp_r29);
        var_r26 = temp_r23 + 0xB;
        var_r25 = temp_r23 + 0xC;
        var_r20 = 0;
        var_r27 = 0;
        do {
            if (var_r20 == *(s32 *)((u8 *)arg0 + 0x250))
                fn_802C3424(var_r24 + 1, var_r26, var_r24 + 0x31, temp_r23 + var_r27 + 0x13, temp_r30);
            temp_r18 = temp_r30;
            if (var_r20 == *(s32 *)((u8 *)arg0 + 0x250))
                temp_r18 = temp_r28;
            fn_802C4F58(var_r24 + 2, var_r25, (const char *)((s32 (*)(s32 *, s32))fn_8022D97C)((s32 *)temp_r21, var_r20), temp_r18);
            var_r27 += 0xA;
            var_r26 += 0xA;
            var_r25 += 0xA;
            var_r20 += 1;
        } while (var_r20 < *(s32 *)((u8 *)temp_r21 + 8));
    }
    var_r24 += 0x32;
    var_r31 += 0x24;
    var_r22 += 1;
outer_check:
    items = *(s32 **)((u8 *)arg0 + 0x244);
    if (var_r22 < items[0x120 / 4])
        goto outer_body;
}
#pragma scheduling on
#pragma pop
extern "C" void fn_80222120(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x248) = 1;
    ((VfObj *)arg0)->vf17();
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_80222178(void *arg0) {
    s32 secondaryIndex;
    s32 primaryIndex;
    void *entry;
    s32 (*callback)(void *);
    /* Confirms the pending selection (indices at +0x24C/+0x250): looks up the entry, invokes its callback with its target (+0x20) and, if accepted (or no callback), triggers fn_802168BC; then clears the selection and marks dirty if +0x1A is set. */
    ((VfObj *)arg0)->vf17();
    primaryIndex = *(s32 *)((u8 *)arg0 + 0x24C);
    *(u8 *)((u8 *)arg0 + 0x248) = 0;
    if (primaryIndex < 0)
        goto done;
    secondaryIndex = *(s32 *)((u8 *)arg0 + 0x250);
    if (secondaryIndex < 0)
        goto done;
    entry = ((void *(*)(void *, s32))fn_8022D97C)(*(void **)(*(s32 *)((u8 *)arg0 + 0x244) + primaryIndex * 0x24), secondaryIndex);
    callback = *(s32 (**)(void *))((u8 *)entry + 0x24);
    if (callback == 0 || callback(*(void **)((u8 *)entry + 0x20)) != 0)
        fn_802168BC(*(void **)((u8 *)entry + 0x20));
done:
    *(s32 *)((u8 *)arg0 + 0x24C) = -1;
    *(s32 *)((u8 *)arg0 + 0x250) = -1;
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_80222234(void *obj, s32 x, s32 y) {
    s32 left, current, top, count, row, col;
    s32 *state = (s32 *)obj;
    s32 *items;
    s32 *entry;
    if (*((u8 *)obj + 0x248) == 0) return;
    items = *(s32 **)((u8 *)obj + 0x244);
    current = state[0x24C / 4];
    count = items[0x120 / 4];
    if (current >= count) state[0x24C / 4] = -1;
    top = state[2];
    if (y < top + 10) {
        left = state[1];
        col = (x - left) / 50;
        if (col < 0) return;
        items = *(s32 **)((u8 *)obj + 0x244);
        if (col >= items[0x120 / 4]) return;
        state[0x24C / 4] = col;
        state[0x250 / 4] = -1;
        return;
    }
    current = state[0x24C / 4];
    if (current < 0) return;
    left = state[1];
    if (x < current * 50 + left) goto fail_x;
    if (x > (current + 1) * 50 + left) goto fail_x;
    y = y - top;
    items = *(s32 **)((u8 *)obj + 0x244);
    row = (y - 10) / 10;
    entry = *(s32 **)((u8 *)items + current * 0x24);
    if (row < 0) goto fail_row;
    if (row >= entry[2]) goto fail_row;
    state[0x250 / 4] = row;
    return;
fail_x:
    state[0x250 / 4] = -1;
    return;
fail_row:
    state[0x250 / 4] = -1;
}

#pragma diag_default 1735
extern "C" void fn_80219440(void *arg0, s32 arg1, void *arg2, s32 arg3);
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_80222340(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct Dummy {
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
        virtual void Init();
    };
    fn_80218F34(arg0, arg1, arg2, arg1 + arg4, arg2 + arg5, arg3);
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(void **)arg0 = lbl_8033F90C;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg2;
    *(s32 *)((u8 *)arg0 + 0x250) = arg3;
    *(s32 *)((u8 *)arg0 + 0x244) = arg6;
    ((Dummy *)arg0)->Init();
    return arg0;
}
#pragma pop

#pragma dont_inline on
extern "C" void fn_802223C4(void *arg0, s32 arg1) {
    s32 value;
    if (!arg0)
        return;
    value = *(s32 *)((u8 *)arg0 + 0x244);
    *(void **)arg0 = lbl_8033F90C;
    if (value != 0) {
        struct Dispatch { virtual void call(s32); };
        ((Dispatch *)value)->call(1);
    }
    fn_8021915C(arg0, 0);
    if (arg1 > 0) {
        fn_80128668(arg0);
        return;
    }
}

extern "C" void fn_80222450(void *arg0) {
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80222468(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void))fn_802191F0)();
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg2;
}

extern "C" void *fn_802224B4(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                                   s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                                   u8 arg8, u8 arg9) {
    fn_80222340(arg0, arg2, arg3, 0, arg4, arg5, arg6);
    *(void **)arg0 = lbl_8033F880;
    *(s32 *)((u8 *)arg0 + 0x25C) = arg1;
    *(s32 *)((u8 *)arg0 + 0x258) = arg7;
    *(u8 *)((u8 *)arg0 + 0x256) = arg8;
    *(u8 *)((u8 *)arg0 + 0x257) = arg9;
    *(u8 *)((u8 *)arg0 + 0x255) = 0;
    *(u8 *)((u8 *)arg0 + 0x254) = 0;
    return arg0;
}

extern "C" void fn_802328D4(void*);
extern "C" s32 lbl_8033F9E0[];
extern "C" s32 fn_80232578(s32);
#pragma scheduling invalid_target
extern "C" void *fn_80222530(void *arg0, s32 arg1, s32 arg2) {
    *(void **)arg0 = &lbl_8033F9E0;
    *(s32 *)((u8 *)arg0 + 4) = fn_80232578(arg1);
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    return arg0;
}
extern "C" void* __dt__14CollisionSpaceFv_80222584(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033F9E0;
        fn_802328D4(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802336AC(s32, s32, s32, const char *, f32, f32, f32, ...);
extern "C" char lbl_8055B8A4[4];
extern "C" void fn_802225E8(void *arg0, s32 arg1, s32 arg2) {
    f32 spC;
    f32 sp8;

    fn_80230C30(&spC, &sp8, arg1, arg2);
    f32 f = lbl_805634A8;
    fn_802336AC(*(s32 *)((u8 *)arg0 + 4), -1, 9, lbl_8055B8A4, spC, sp8, f,
                *(s32 *)((u8 *)arg0 + 8));
}

extern "C" void fn_8022264C(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    f32 scale = lbl_805634A4;
    *arg3 = arg1;
    *arg4 = arg2;
    s32 value = (s32)fn_8023293C(*(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8), scale);
    *arg5 = arg1 + value;
    *arg6 = arg1 + fn_80232B70(*(s32 *)((u8 *)arg0 + 4));
}
#pragma scheduling on
extern "C" void *fn_802226D4(void *arg0, s32 arg1) {
    extern char lbl_8033F9BC[];
    extern s32 fn_8023512C(s32);
    *(volatile char **)arg0 = lbl_8033F9BC;
    *(s32 *)((u8 *)arg0 + 4) = fn_8023512C(arg1);
    return arg0;
}

void fn_80235380(int);
extern "C" char lbl_8033F9BC[];
extern "C" void *fn_80222718(void *arg0, s32 arg1) {
    s32 old;
    if (arg0 != 0) {
        old = *(s32 *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8033F9BC;
        if (old != 0) fn_80235380(old);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

#pragma push
#pragma processor 750
extern "C" void fn_80222788(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 spC;
    f32 sp8;
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        f32 temp_f31 = lbl_805634A8;
        fn_80230C30(&spC, &sp8, arg1, arg2);
        fn_802353F4(*(s32 *)((u8 *)arg0 + 4), arg4, spC, sp8, temp_f31);
    }
}
#pragma pop
extern "C" void fn_80222800(void *resource, s32 x, s32 y, s32 *outX, s32 *outY, s32 *outRight, s32 *outBottom) {
    /* Compute bounds for a resource: returns (x,y) and (x+width, x+height); uses 10x10 when the handle is null. */
    *outX = x;
    *outY = y;
    s32 handle = *(s32 *)((u8 *)resource + 4);
    if (handle == 0) {
        *outRight = x + 10;
        *outBottom = y + 10;
    } else {
        *outRight = x + (s32)fn_80235EF0(handle, 0);
        *outBottom = x + (s32)fn_80235F64(*(s32 *)((u8 *)resource + 4), 0);
    }
}
#pragma pop
/* Initializes an object with vtable lbl_8033F998 and an image/resource handle; uses given size or queries it. */
extern "C" void *fn_802228B0(void *obj, s32 name, s32 width, s32 height) {
    typedef s32 (*CreateFn)(s32);
    *(void **)obj = lbl_8033F998;
    *(s32 *)((u8 *)obj + 4) = ((CreateFn)fn_802C5130)(name);
    if (width > 0 && height > 0) {
        *(f32 *)((u8 *)obj + 8) = (f32)width;
        *(f32 *)((u8 *)obj + 0xC) = (f32)height;
    } else {
        *(f32 *)((u8 *)obj + 8) = (f32)fn_802C51C0(*(s32 *)((u8 *)obj + 4));
        *(f32 *)((u8 *)obj + 0xC) = (f32)fn_802C5220(*(s32 *)((u8 *)obj + 4));
    }
    return obj;
}

extern "C" int lbl_8033F998[];
extern "C" void* __dt__14CollisionSpaceFv_80222998(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033F998;
        fn_802C519C(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802229FC(void *arg0) {
    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 4)) != 0) {
        fn_802C51AC(*(s32 *)((u8 *)arg0 + 4));
    }
}

#pragma push
#pragma processor 750
extern "C" void fn_80222A3C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 spC;
    f32 sp8;
    register f32 value;

    /* If object has a valid image/resource, compute screen coords and draw frame arg4 (when not -1). */
    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 4)) != 0) {
        value = lbl_805634A8;
        spC = value;
        sp8 = value;
        fn_80230C30(&spC, &sp8, arg1, arg2);
        if ((u32)(arg4 + 0x10000) != 0xFFFFU) {
            fn_802C5320(*(s32 *)((u8 *)arg0 + 4),
                        arg4 % fn_802C51AC(*(s32 *)((u8 *)arg0 + 4)),
                        spC, sp8, value,
                        *(f32 *)((u8 *)arg0 + 8),
                        *(f32 *)((u8 *)arg0 + 0xC));
        }
    }
}
#pragma pop
extern "C" void fn_80222AFC(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    *arg3 = arg1;
    *arg4 = arg2;
    *arg5 = *arg3 + (s32) *(f32 *)((u8 *)arg0 + 8);
    *arg6 = *arg4 + (s32) *(f32 *)((u8 *)arg0 + 0xC);
}

extern "C" s32 fn_80222B48(void *arg0, s32 unused1, s32 unused2, s32 arg1, s32 arg2) {
    struct V {
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void Call(s32, s32, s32*, s32*, s32*, s32*);
    };
    s32 sp14, sp10, spC, sp8, result;

    // Forward unused inputs and pass bounds in low-to-high order for the target registers.
    ((V*)arg0)->Call(unused1, unused2, &sp8, &spC, &sp10, &sp14);
    result = 0;
    if (arg1 >= sp8 && arg1 < sp10 && arg2 >= spC && arg2 < sp14) {
        result = 1;
    }
    return result;
}

extern "C" s32 fn_80222BD4(void *arg0) {
    return fn_802C51AC(*(s32*)((u8*)arg0 + 4));
}

extern "C" char lbl_8033E560[];
extern "C" char lbl_8033DA60[];
extern "C" void fn_802E317C(const char *, ...);
extern f32 lbl_8056351C;
extern f64 lbl_80563520;
extern "C" void *fn_80222BDC(void *arg0, void *arg1, s32 arg2) {
    ((void *(*)(void *, void *))fn_80218F80)(arg0, arg1);
    *(s32 *)((u8 *)arg0 + 0x244) = arg2;
    *(void **)arg0 = lbl_8033E560;
    s32 res = fn_80232578((s32)arg1 + 0x40);
    *(s32 *)((u8 *)arg0 + 0x248) = res;
    if (res == 0) {
        fn_802E317C(lbl_8033DA60, (char *)arg1 + 0x40);
    }
    *(s32 *)((u8 *)arg0 + 0x24C) = *(s32 *)((u8 *)arg1 + 0xA0);
    f32 val = *(u32 *)((u8 *)arg1 + 0x9C);
    *(f32 *)((u8 *)arg0 + 0x254) = lbl_8056351C;
    *(f32 *)((u8 *)arg0 + 0x250) = val;
    return arg0;
}

extern "C" void * __dt__Q34Game10MemoryCard8ResourceFv_80222C8C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E560;
        fn_802328D4((void *)*(s32 *)((u8 *)arg0 + 0x248));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80222CFC(void *arg0, s32 arg1) {
    struct Matrix { f32 m[12]; };
    struct TransformArgs { s32 x, y; f32 z; };
    Matrix sp38;
    struct Scratch {
        char sp8[4];
        f32 spC, sp10, sp14, sp18, sp1C;
        TransformArgs sp20;
        f32 sp2C, sp30, sp34;
    } stack;
    register f32 temp_f31;
    register f32 temp_f30;
    register f32 temp_f29;
    register f32 temp_f28;
    register f32 var_f28_2;
    register f32 temp_f1;
    register f32 temp_f0;
    register f32 temp_f1_2;
    register f32 temp_f2;
    register f32 temp_f3;
    register s32 temp_r31;
    register s32 var_r26;
    register s32 var_r30;
    register void *temp_r25;
    register void *temp_r29;
    register void *temp_r28;
    register void *temp_r27;
    register char *temp_r24;
    register void *temp_r3;
    u32 *copyDst;
    u32 *copySrc;
    s32 callWidth;
    s32 callHeight;
    f32 callScale;
    f32 *var_r22;
    f32 *var_r23;

    (void)arg1;
    temp_r25 = arg0;
    temp_r3 = *(void **)((u8 *)arg0 + 0x244);
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 8);
    temp_f1 = ((f32 (*)(void *))fn_8023659C)(arg0);
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x254);
    temp_f0 = -temp_f0;
    temp_f31 = temp_f0 * temp_f1;
    if (temp_r31 <= 0) return;

    temp_f28 = lbl_805634A8;
    var_r30 = 0;
    goto loop3_test;
loop3_body:
    temp_r3 = ((char *(*)(s32, s32, s32))fn_8022D3F8)(
        *(s32 *)((u8 *)temp_r25 + 0x244), var_r30, 0);
    temp_f28 += fn_8023293C(*(s32 *)((u8 *)temp_r25 + 0x248),
        (s32)temp_r3, lbl_805634A4);
    var_r30++;
loop3_test:
    if (var_r30 < temp_r31) goto loop3_body;

    temp_f3 = lbl_805634D8 * *(f32 *)((u8 *)temp_r25 + 0x250);
    temp_f3 -= temp_f28;
    temp_f30 = temp_f3 / (f32)temp_r31;
    temp_f1 = temp_f30 * (f32)temp_r31;
    temp_f1 += temp_f28;
    temp_f29 = lbl_80563528 / temp_f1;
    ((void (*)(f32 *, f32 *, s32, s32, f32, f32))fn_80230C30)(
        &stack.sp10, &stack.spC, *(s32 *)((u8 *)temp_r25 + 4),
        *(s32 *)((u8 *)temp_r25 + 8), temp_f1, temp_f3);
    temp_r29 = (void *)fn_8022EDC4();
    temp_r28 = fn_8022EDE4(*(f32 *)((u8 *)temp_r29 + 0x30));
    var_r22 = &stack.sp14;
    var_r23 = &stack.sp2C;

    var_f28_2 = lbl_805634A8;
    var_r30 = 0;
    goto outer_test;
outer_body:
    temp_r3 = ((char *(*)(s32, s32, s32))fn_8022D3F8)(
        *(s32 *)((u8 *)temp_r25 + 0x244), var_r30, 0);
    temp_r27 = temp_r3;
    temp_r24 = (char *)temp_r3;
    var_r26 = 0;
    goto inner_test;
inner_body:
    sprintf(stack.sp8, lbl_8055B8A8, (s32)(s8)*temp_r24);
    copyDst = (u32 *)temp_r28;
    copySrc = (u32 *)temp_r29;
    {
        u32 a = copySrc[0], b = copySrc[1];
        copyDst[0] = a; copyDst[1] = b;
        a = copySrc[2]; b = copySrc[3];
        copyDst[2] = a; copyDst[3] = b;
        a = copySrc[4]; b = copySrc[5];
        copyDst[4] = a; copyDst[5] = b;
        a = copySrc[6]; b = copySrc[7];
        copyDst[6] = a; copyDst[7] = b;
        a = copySrc[8]; b = copySrc[9];
        copyDst[8] = a; copyDst[9] = b;
        a = copySrc[10]; b = copySrc[11];
        copyDst[10] = a; copyDst[11] = b;
    }
    *(volatile u32 *)&stack.sp2C = 0;
    *(volatile u32 *)&stack.sp30 = 0;
    *(volatile u32 *)&stack.sp34 = 0;
    *(volatile f32 *)&stack.sp2C = stack.sp10;
    *(volatile f32 *)&stack.sp30 = stack.spC;

    if (var_r23 == var_r22) {
        stack.sp14 = (*(volatile f32 *)&stack.sp34) * ((Matrix *)temp_r28)->m[6] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[0] +
             stack.spC * ((Matrix *)temp_r28)->m[3]);
        stack.sp18 = stack.sp34 * ((Matrix *)temp_r28)->m[7] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[1] +
             stack.spC * ((Matrix *)temp_r28)->m[4]);
        stack.sp1C = stack.sp34 * ((Matrix *)temp_r28)->m[8] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[2] +
             stack.spC * ((Matrix *)temp_r28)->m[5]);
    } else {
        stack.sp14 = stack.sp34 * ((Matrix *)temp_r28)->m[6] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[0] +
             stack.spC * ((Matrix *)temp_r28)->m[3]) +
            ((Matrix *)temp_r28)->m[9];
        stack.sp18 = stack.sp34 * ((Matrix *)temp_r28)->m[7] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[1] +
             stack.spC * ((Matrix *)temp_r28)->m[4]) +
            ((Matrix *)temp_r28)->m[10];
        stack.sp1C = stack.sp34 * ((Matrix *)temp_r28)->m[8] +
            (stack.sp10 * ((Matrix *)temp_r28)->m[2] +
             stack.spC * ((Matrix *)temp_r28)->m[5]) +
            ((Matrix *)temp_r28)->m[11];
    }

    ((Matrix *)temp_r28)->m[9] += stack.sp14;
    ((Matrix *)temp_r28)->m[10] += stack.sp18;
    temp_f2 = ((Matrix *)temp_r28)->m[11];
    temp_f1_2 = temp_f2 + stack.sp1C;
    ((Matrix *)temp_r28)->m[11] = temp_f1_2;

    stack.sp20.z = 0.0f;
    stack.sp20.x = 0;
    stack.sp20.y = 0;
    stack.sp20.z = temp_f29 * var_f28_2 + temp_f31;
    ((void (*)(void *, void *, f32, f32))fn_80015A20)(
        &sp38, &stack.sp20, temp_f1_2, temp_f2);
    fn_80015B20(temp_r28, &sp38, temp_r28);
    fn_8022ED00(temp_r28);

    callWidth = *(s32 *)((u8 *)temp_r25 + 0x248);
    callScale = *(f32 *)((u8 *)temp_r25 + 0x250);
    callHeight = *(s32 *)((u8 *)temp_r25 + 0x24C);
    fn_80232BA4(stack.sp8, callWidth, callHeight, 9,
        lbl_805634A8, callScale, lbl_805634A4, lbl_805634A8, lbl_805634A4);
    fn_8022EDB8();
    var_f28_2 += fn_8023293C(*(s32 *)((u8 *)temp_r25 + 0x248),
        (s32)stack.sp8, lbl_805634A4);
    var_r26++;
    temp_r24++;
inner_test:
    if (var_r26 < strlen((char *)temp_r27)) goto inner_body;

    var_f28_2 += temp_f30;
    var_r30++;
outer_test:
    if (var_r30 < temp_r31) goto outer_body;
    fn_8022EE98(temp_r28);
}

#pragma push
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma scheduling invalid_target
extern "C" void *fn_802230A4(void *self, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    register s32 obj = (s32)self;
    register u8 *input = (u8 *)arg3;
    register s32 data = arg4;
    register s32 i;
    register s32 offset;
    register s32 zero;
    register s32 one;
    register s32 minusOne;
    s32 scratch;
    s32 count;
    s32 texture;
    register f32 defaultValue;
    f32 scale;
    f32 baseValue;
    f32 resetValue;
    f32 lastValue;

    fn_80218F34((void *)obj, arg1, arg2, 0, 0, 0);
    count = *(s32 *)(input + 8);
    *(s32 *)(obj + 0x2CC) = data;
    *(void **)obj = lbl_8033E4DC;
    *(s32 *)(obj + 0x2C8) = count;
    texture = ((s32 (*)(const char *, const char *))fn_80232578)(
        (const char *)lbl_8033DA84, lbl_8033E4DC);
    scale = lbl_8056352C;
    i = 0;
    baseValue = lbl_805634A4;
    offset = 0;
    *(s32 *)(obj + 0x3FC) = texture;
    defaultValue = lbl_805634A8;
    zero = 0;
    *(f32 *)(obj + 0x400) = scale;
    one = 1;
    minusOne = -1;
    *(f32 *)(obj + 0x404) = baseValue;

loop:
    *(u8 *)(obj + i + 0x2D0) = zero;
    if (i >= *(s32 *)(obj + 0x2C8)) goto empty;
    scratch = 0;
    data = ((s32 (*)(void *, s32, s32 *))fn_8022D3F8)(input, i, &scratch);
    if ((scratch & 3) != 1)
        *(u8 *)(obj + i + 0x2D0) = one;
    {
        u8 *row = (u8 *)(obj + offset);
        *(s32 *)(row + 0x378) = (scratch >> 2) & 0x3F;
        {
            f32 width = fn_8023293C(
                *(s32 *)(obj + 0x3FC), data, lbl_805634A4);
            *(f32 *)(row + 0x2F4) = *(f32 *)(obj + 0x404) * width;
        }
        *(s32 *)(row + 0x244) = data;
    }
    goto next;
empty:
    {
        u8 *row = (u8 *)(obj + offset);
        *(s32 *)(row + 0x244) = zero;
        *(f32 *)(row + 0x2F4) = defaultValue;
        *(s32 *)(row + 0x378) = minusOne;
    }
next:
    ++i;
    offset += 4;
    if (i < 0x21) goto loop;

    resetValue = lbl_805634A8;
    lastValue = lbl_80563530;
    *(f32 *)(obj + 0x414) = resetValue;
    *(f32 *)(obj + 0x410) = resetValue;
    *(f32 *)(obj + 0x40C) = resetValue;
    *(f32 *)(obj + 0x408) = lastValue;
    *(u8 *)(obj + 0x41C) = zero;
    ((void (*)(void *))fn_8022375C)((void *)obj);
    return (void *)obj;
}

extern "C" void *fn_80223208(void *arg0, unsigned int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E4DC;
        fn_802328D4(*(void **)((u8 *)arg0 + 0x3FC));
        *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
        fn_8021915C(arg0, 0);
        if ((s32)arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma pop
extern "C" void fn_80230924(s32, s32, f32, f32, f32, f32, f32);

extern "C" s32 fn_802236C8(void *, s32);
extern "C" void fn_8022375C(void);
extern "C" void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
extern "C" f32 lbl_805634F4;
extern "C" f32 lbl_80563534;
#pragma push
#pragma processor 750
extern "C" void fn_80223280(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 var_r28;
    s32 temp_r28;
    s32 temp_r29;
    s32 temp_r4_2;
    char *temp_r30_2;
    register f32 temp_f31;
    register f32 temp_f30;
    register f32 temp_f29;
    register f32 temp_f28;
    register f32 temp_f27;
    register f32 temp_f2;
    register f32 temp_f1;
    register f32 temp_f30_2;
    register f32 temp_f6;
    register f32 temp_f28_2;
    register f32 temp_f27_2;
    f32 unusedW, unusedH;

    temp_f30 = *(f32 *)((u8 *)arg0 + 0x408);
    temp_f29 = temp_f30;
    var_r28 = 0;
    temp_f27 = lbl_805634EC;
    temp_f28 = lbl_805634C4;
    temp_f31 = lbl_805634F4 - (f32)*(s32 *)((u8 *)arg0 + 8);
    goto loop_test;
loop_body:
        if (var_r28 == **(s32 **)((u8 *)arg0 + 0x2CC)) {
            temp_f29 = temp_f30;
            temp_f30 += *(f32 *)((u8 *)arg0 + 0x400) +
                (*(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F4) * temp_f28);
            if (var_r28 + 1 < temp_r4) {
                temp_f30 += *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F8) * temp_f28;
            }
        } else {
            fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + var_r28 * 4 + 0x244),
                *(s32 *)((u8 *)arg0 + 0x3FC), 0xFF000000, 0xC,
                temp_f27 + temp_f30, temp_f31 - temp_f27,
                *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
            fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + var_r28 * 4 + 0x244),
                *(s32 *)((u8 *)arg0 + 0x3FC),
                fn_802236C8(arg0, var_r28), 0xC,
                temp_f30, temp_f31, *(f32 *)((u8 *)arg0 + 0x404),
                lbl_805634A8, lbl_805634A4);
            temp_f30 += *(f32 *)((u8 *)arg0 + 0x400) +
                (*(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F4) * temp_f28);
            if (var_r28 + 1 < *(s32 *)((u8 *)arg0 + 0x2C8)) {
                temp_f30 += *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F8) * temp_f28;
            }
        }
        var_r28++;
loop_test:
    temp_r4 = *(s32 *)((u8 *)arg0 + 0x2C8);
    if (var_r28 < temp_r4) goto loop_body;

    temp_r4_2 = *(s32 *)((u8 *)arg0 + 0x2CC);
    temp_r28 = *(s32 *)temp_r4_2;
    temp_r29 = temp_r28 * 4;
    unusedW = (f32)lbl_8055FB9C;
    temp_r30_2 = (char *)arg0 + temp_r29;
    unusedH = (f32)lbl_8055FBA0;
    temp_f2 = temp_f29 - (*(f32 *)(temp_r30_2 + 0x2F4) * lbl_805634C4);
    temp_f1 = temp_f2 - (*(f32 *)((u8 *)arg0 + 0x400) * lbl_805634C4);
    temp_f30_2 = lbl_80563534 + temp_f1;
    temp_f6 = *(f32 *)((u8 *)arg0 + 0x404) * (f32)fn_80232B70(*(s32 *)((u8 *)arg0 + 0x3FC));
    temp_f28_2 = *(f32 *)((u8 *)arg0 + 0x400) + *(f32 *)(temp_r30_2 + 0x2F4);
    temp_f27_2 = lbl_805634EC + temp_f6;

    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x966464, temp_f30_2, temp_f31 - lbl_805634EC,
        temp_f30_2 + temp_f28_2,
        temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x962828, temp_f30_2, temp_f31 - lbl_805634EC,
        lbl_805634EC + temp_f30_2,
        temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x962828, temp_f30_2, temp_f31 - lbl_805634EC,
        temp_f30_2 + temp_f28_2,
        temp_f31 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x96AAAAAA, temp_f30_2,
        (temp_f31 - temp_f27_2) - lbl_805634EC,
        temp_f30_2 + temp_f28_2,
        (temp_f31 - temp_f27_2) - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x96AAAAAA, temp_f30_2 + temp_f28_2 - lbl_805634EC,
        temp_f31 - lbl_805634EC, temp_f30_2 + temp_f28_2,
        temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);

    fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + temp_r29 + 0x244),
        *(s32 *)((u8 *)arg0 + 0x3FC), 0xFF000000, 0xC,
        lbl_80563534 + temp_f29, temp_f31 - lbl_80563534,
        *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
    fn_80232BA4((char *)*(s32 *)(temp_r30_2 + 0x244),
        *(s32 *)((u8 *)arg0 + 0x3FC), fn_802236C8(arg0, temp_r28), 0xC,
        lbl_805634EC + temp_f29, temp_f31 - lbl_805634EC,
        *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
}
#pragma pop
extern "C" void fn_802235B4(void *arg0) {
    s32 *pIndex = *(s32 **)((u8 *)arg0 + 0x2CC);
    s32 next;
    s32 count = *(s32 *)((u8 *)arg0 + 0x2C8);
    s32 cur = *pIndex;
    u32 baseAddr = (u32)arg0 + cur;
    s32 i;
    for (i = 1, next = cur + 1; next < count; i++, next++) {
        if (*(u8 *)(i + baseAddr + 0x2D0) != 0) {
            *pIndex += i;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
    for (i = cur; i > 0; i--) {
        if (((u8 *)arg0)[cur - i + 0x2D0] != 0) {
            *pIndex -= i;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
}

#pragma scheduling invalid_target
extern "C" void fn_80223644(void *arg0) {
    s32 i = 1;
    s32 *pIndex = *(s32 **)((u8 *)arg0 + 0x2CC);
    s32 cur = *pIndex;
    goto loop_cond;
loop_body:
    {
        u8 *p = (u8 *)arg0 + (cur - i);
        if (p[0x2D0] != 0) {
            *pIndex -= i;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
    i++;
loop_cond:
    if (cur - i >= 0) goto loop_body;
    s32 count = *(s32 *)((u8 *)arg0 + 0x2C8);
    u8 *base = (u8 *)arg0 + cur;
    s32 diff = count - cur;
    for (s32 j = diff - 1; j > 0; j--) {
        u8 *p = j + base;
        if (p[0x2D0]) {
            *pIndex += j;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
}
#pragma scheduling on
extern "C" void fn_8022375C(void);
extern "C" void fn_802235B4(void *);
extern "C" void fn_80223644(void *);
extern "C" s32 fn_802236C8(void *arg0, s32 arg1) {
    if (*(u8 *)((u8 *)arg0 + 0x41C) != 0)
        return (s32)0xE6969696;
    u8 *p = (u8 *)arg0 + arg1;
    u8 flag = p[0x2D0];
    s32 result = (s32)0xFF9F9F9F;
    if (flag != 0)
        result = -1;
    if (arg1 == *(s32 *)*(s32 **)((u8 *)arg0 + 0x2CC) &&
        lbl_805634A4 == *(f32 *)((u8 *)arg0 + 0x414))
        result = -0x2FC1;
    return result;
}

extern "C" void fn_80223728(void *arg0) {
    fn_802192AC(arg0);
    *(f32 *)((u8 *)arg0 + 0x414) = lbl_805634A4;
}

extern "C" void fn_8022375C(void) {
}

extern "C" s32 fn_80223760(void *arg0, s32 arg1) {
    if (*(u8 *)((u8 *)arg0 + 0x41C) != 0)
        return 0;
    switch (arg1) {
    case 0x125:
        fn_80223644(arg0);
        return 1;
    case 0x127:
        fn_802235B4(arg0);
        return 1;
    default:
        return 0;
    }
}

extern "C" void fn_802237D0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x41C) = 1;
}

extern "C" void fn_802237DC(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x41C) = 0;
}

extern "C" s32 fn_802237E8(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x2C8);
}

extern "C" s32 fn_802237F0(s32 arg0, s32 arg1) {
    return *(s32 *)(arg0 + (arg1 << 2) + 0x378);
}


extern "C" int lbl_8033E458[];
extern "C" void *fn_80223800(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    ((void (*)(void))fn_802230A4)();
    *(void **)((u8 *)arg0 + 0x420) = arg4;
    *(void **)arg0 = lbl_8033E458;
    if (arg4 != 0) {
        fn_80219440(arg0, 0, arg4, 4);
    }
    fn_80219440(arg0, 1, fn_80216708(), 1);
    return arg0;
}

extern "C" void fn_802237DC(void *);
extern "C" void fn_80223880(void *arg0) {
    class CallIface { public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26();
        virtual void call(s32, s32);
    };
    ((CallIface *)arg0)->call(2, 0);
    fn_802237DC(arg0);
    fn_8021818C(*(s32 *)((u8 *)arg0 + 0x2C));
}

// View of the sound-list class fn_802238D0 belongs to: a menu whose rows each
// carry a sound id (fn_80223280 draws the same rows as text).
struct MenuSoundList {
    void *vtable;                // 0x00
    u8 pad_0x04[0x1A - 0x04];
    u8 active;                   // 0x1A set while the list is running
    u8 pad_0x1B[0x2C - 0x1B];
    s32 soundMgr;                // 0x2C sound manager: fn_8021889C mutes / fn_80218968 unmutes one sound id
    u8 pad_0x30[0x234 - 0x30];
    u8 dirty;                    // 0x234 set to ask the list for an update
    u8 pad_0x235[0x2C8 - 0x235];
    s32 rowCount;                // 0x2C8 rows in the list (fn_802237E8)
    u8 pad_0x2CC[0x378 - 0x2CC];
    s32 soundIds[1];             // 0x378 sound id of each row (fn_802237F0)
    u8 pad_0x37C[0x420 - 0x37C];
    s32 *selected;               // 0x420 -> row the cursor is on
};

// Unmutes the sound of the row the cursor is on and mutes every other row's.
// lbl_805634A8 is 0.0 and lbl_805634E8 is 0.3: mode 2 switches the sounds at
// once, any other mode fades them over 0.3 (see fn_80219358 / fn_802193C8).
#pragma push
#pragma processor 750
extern "C" void fn_802238D0(MenuSoundList *list, s32 mode) {
    register f32 level;
    s32 soundMgr;
    s32 row = 0;
    while (row < fn_802237E8(list)) {
        if (row == *list->selected) {
            if (mode == 2) level = lbl_805634A8;
            else level = lbl_805634E8;
            soundMgr = list->soundMgr;
            fn_80218968(soundMgr, fn_802237F0((s32)list, row), level);
        } else {
            if (mode == 2) level = lbl_805634A8;
            else level = lbl_805634E8;
            soundMgr = list->soundMgr;
            fn_8021889C(soundMgr, fn_802237F0((s32)list, row), level);
        }
        row++;
    }
    if (list->active)
        list->dirty = 1;
}
#pragma pop
extern "C" s32 fn_802239C8(void *arg0, s32 arg1) {
    if (*(u8 *)fn_80216708() == 0)
        goto fallback;
    if (arg1 == 0x126)
        goto fallback;
    if (arg1 < 0x126) {
        if (arg1 < 0x125)
            goto fallback;
        goto lower;
    }
    if (arg1 >= 0x128)
        goto fallback;
    ((void (*)(void *))fn_802235B4)(arg0);
    return 1;
lower:
    ((void (*)(void *))fn_80223644)(arg0);
    return 1;
fallback:
    return fn_802192A4(arg0, arg1);
}

extern "C" void fn_80223A58(void *arg0) {
    if (*(u8 *)fn_80216708() != 0) {
        fn_802237DC(arg0);
    } else {
        fn_802237D0(arg0);
    }
    ((void (*)(void *))fn_80223280)(arg0);
}

extern "C" u32 fn_80223AAC(void) { return 1; }

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_80223AB4(void *arg0, void *arg1, s32 arg2) {
    fn_80218F80();
    *(void **)arg0 = lbl_8033E3D4;
    fn_80230C30((f32 *)((u8 *)arg0 + 0x244),
                (f32 *)((u8 *)arg0 + 0x248),
                *(s32 *)((u8 *)arg1 + 8),
                *(s32 *)((u8 *)arg1 + 0xC));
    *(s32 *)((u8 *)arg0 + 0x24C) = *(s32 *)((u8 *)arg1 + 0x9C);
    if ((u8 *)arg1 + 0x40 != 0) {
        *(s32 *)((u8 *)arg0 + 0x250) = ((s32 (*)(void *))fn_802C5130)((u8 *)arg1 + 0x40);
    } else {
        *(s32 *)((u8 *)arg0 + 0x250) = 0;
    }
    *(f32 *)((u8 *)arg0 + 0x254) = (f32)*(s32 *)((u8 *)arg1 + 0x14);
    *(f32 *)((u8 *)arg0 + 0x25C) = lbl_805634A4;
    *(f32 *)((u8 *)arg0 + 0x258) = (f32)*(s32 *)((u8 *)arg1 + 0x14);
    *(s32 *)((u8 *)arg0 + 0x260) = (s32)fn_8022EE9C();
    *(s32 *)((u8 *)arg0 + 0x264) = arg2;
    return arg0;
}
#pragma pop
extern "C" void *lbl_8033E3D4[];
extern "C" void *fn_80223B94(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        void *ptr = *(void **)((u8 *)arg0 + 0x250);
        *(void **)arg0 = lbl_8033E3D4;
        if (ptr != 0)
            fn_802C519C(ptr);
        *(void **)((u8 *)arg0 + 0x250) = 0;
        fn_8022EE98(*(void **)((u8 *)arg0 + 0x260));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma processor 750
extern "C" void fn_80223C20(void *arg0) {
    float temp_f31 = lbl_805634A8;
    unsigned char sp8[0x40];
    *(float *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x260) + 0x30) = lbl_805634A4 - *(float *)((unsigned char *)arg0 + 0x25C);
    if (*(float *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x260) + 0x30) > temp_f31 && *(int *)((unsigned char *)arg0 + 0x250) != 0) {
        fn_8022EEF8(sp8, (int)*(void **)((unsigned char *)arg0 + 0x260), fn_8022EDC4());
        fn_8022ED00(sp8);
        fn_802C5320(*(int *)((unsigned char *)arg0 + 0x250), 0, *(float *)((unsigned char *)arg0 + 0x244), *(float *)((unsigned char *)arg0 + 0x248), temp_f31, *(float *)((unsigned char *)arg0 + 0x254), *(float *)((unsigned char *)arg0 + 0x258));
        fn_8022EDB8();
    }
}
#pragma processor pop
extern "C" void fn_80223CC4(void *arg0) {
    void *obj = *(void **)((u8 *)arg0 + 0x264);
    s32 a = *(s32 *)((u8 *)arg0 + 0x24C);
    s32 b = *(s32 *)((u8 *)obj + 0xC);
    if (a == b)
        *(f32 *)((u8 *)arg0 + 0x25C) = lbl_805634A8;
    else
        *(f32 *)((u8 *)arg0 + 0x25C) = lbl_805634A4;
    fn_802192AC(arg0);
}

extern "C" s32 fn_802C9A58(s32, void *);
extern "C" f32 lbl_80563538;
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_80223CF0(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    register s32 temp_r28;
    register s32 temp_r27;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r3;
    s32 temp_r0;

    fn_80218F80();
    *(s32 *)((u8 *)arg0 + 0x258) = 0;
    *(void **)arg0 = lbl_8033E350;
    *(u8 *)((u8 *)arg0 + 0x25C) = (u8)0;
    *(s32 *)((u8 *)arg0 + 0x264) = -2;
    *(s32 *)((u8 *)arg0 + 0x260) = 0;
    if (fn_802C9A58(0, lbl_8033E350) == 0) {
        if (((VfObj *)arg0)->vf28() > 0x258) {
            temp_r5 = *(s32 *)((u8 *)arg0 + 8);
            if (*(s32 *)((u8 *)arg0 + 0x10) - temp_r5 > 0x1CC) {
                temp_r4 = (lbl_8055CFF0 / 2);
                temp_f1 = lbl_80563538 * (f32)(*(s32 *)((u8 *)arg0 + 4) - temp_r4);
                if (temp_f1 < lbl_805634A8) {
                    var_f0 = temp_f1 - lbl_805634C4;
                } else {
                    var_f0 = lbl_805634C4 + temp_f1;
                }
                temp_r6 = (lbl_8055CFF4 / 2);
                temp_r28 = temp_r4 + (s32)var_f0;
                temp_f1_2 = (f32)(temp_r5 - temp_r6);
                if (temp_f1_2 < lbl_805634A8) {
                    var_f0_2 = temp_f1_2 - lbl_805634C4;
                } else {
                    var_f0_2 = lbl_805634C4 + temp_f1_2;
                }
                temp_r27 = temp_r6 + (s32)var_f0_2;
                temp_f1_3 = lbl_80563538 * (f32)((VfObj *)arg0)->vf28();
                var_f0_3 = (temp_f1_3 < lbl_805634A8) ? temp_f1_3 - lbl_805634C4 : lbl_805634C4 + temp_f1_3;
                temp_r3 = temp_r28 + (s32)var_f0_3;
                temp_f1_4 = (f32)(*(s32 *)((u8 *)arg0 + 0x10) -
                                  *(s32 *)((u8 *)arg0 + 8));
                var_f0_4 = (temp_f1_4 < lbl_805634A8) ? temp_f1_4 - lbl_805634C4 : lbl_805634C4 + temp_f1_4;
                *(s32 *)((u8 *)arg0 + 4) = temp_r28;
                *(s32 *)((u8 *)arg0 + 8) = temp_r27;
                *(s32 *)((u8 *)arg0 + 0xC) = temp_r3;
                *(s32 *)((u8 *)arg0 + 0x10) = temp_r27 + (s32)var_f0_4;
            }
        }
    }
    fn_80230C30((f32 *)((u8 *)arg0 + 0x244),
                (f32 *)((u8 *)arg0 + 0x248),
                *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    *(f32 *)((u8 *)arg0 + 0x24C) = (f32)((VfObj *)arg0)->vf28();
    *(f32 *)((u8 *)arg0 + 0x250) =
        (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
    if (arg2 != 0) {
        *(s32 *)((u8 *)arg0 + 0x258) = arg2;
    } else {
        *(s32 *)((u8 *)arg0 + 0x258) = (s32)((u8 *)arg1 + 0x40);
    }
    temp_r0 = *(s32 *)((u8 *)arg1 + 0xA4);
    temp_r5 = temp_r0;
    temp_r4 = -temp_r5;
    *(s32 *)((u8 *)arg0 + 0x254) = 0;
    temp_r4 |= temp_r5;
    *(u8 *)((u8 *)arg0 + 0x25C) = (u8)((u32)temp_r4 >> 31);
    return arg0;
}
#pragma pop
extern "C" void* fn_80223FAC(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 temp = *(s32*)((u8*)arg0 + 0x254);
        *(void**)arg0 = lbl_8033E350;
        if (temp != 0) fn_802ECFF4(temp);
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" const char lbl_8033DA90[];
extern "C" void fn_80224028(void *arg0) {
    void *state;
    s32 (*callback)(s32);

    fn_802192AC(arg0);
    if (*(void **)((u8 *)arg0 + 0x254) != 0) {
        goto active;
    }
    if (*(s32 *)((u8 *)arg0 + 0x258) == 0) {
        goto done;
    }
    state = (void *)fn_802ECF08(*(s32 *)((u8 *)arg0 + 0x258),
        *(u8 *)((u8 *)arg0 + 0x25C) == 0);
    *(void **)((u8 *)arg0 + 0x254) = state;
    if (state != 0) {
        goto done;
    }
    if (*(u8 *)((u8 *)arg0 + 0x25C) == 0) {
        goto done;
    }
    callback = *(s32 (**)(s32))((u8 *)arg0 + 0x260);
    if ((callback == 0) || (callback(*(s32 *)((u8 *)arg0 + 0x264)) != 0)) {
        fn_802168BC(*(void **)((u8 *)arg0 + 0x264));
    }
    goto done;

active:
    if (*(u8 *)((u8 *)arg0 + 0x25C) != 0) {
        if (fn_802ED040() != 0) {
            callback = *(s32 (**)(s32))((u8 *)arg0 + 0x260);
            if ((callback == 0) || (callback(*(s32 *)((u8 *)arg0 + 0x264)) != 0)) {
                fn_802168BC(*(void **)((u8 *)arg0 + 0x264));
            }
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x258) != 0 &&
        ((s32 (*)(s32, s32))fn_802ECF90)(*(s32 *)((u8 *)arg0 + 0x254), *(s32 *)((u8 *)arg0 + 0x258)) == 0) {
        fn_802ECFF4(*(s32 *)((u8 *)arg0 + 0x254));
        fn_802E30C8(lbl_8033DA90, *(s32 *)((u8 *)arg0 + 0x258));
        *(void **)((u8 *)arg0 + 0x254) = (void *)fn_802ECF08(
            *(s32 *)((u8 *)arg0 + 0x258),
            *(u8 *)((u8 *)arg0 + 0x25C) == 0);
    }

done:
    if (*(void **)((u8 *)arg0 + 0x254) != 0) {
        ((void (*)(s32))fn_802ECFEC)(*(s32 *)((u8 *)arg0 + 0x254));
    }
}

extern "C" void fn_80224160(void *arg0) {
    s32 handle;
    fn_80219354();
    handle = *(s32 *)((u8 *)arg0 + 0x254);
    if (handle != 0) {
        ((void (*)(s32))fn_802ECFEC)(handle);
    }
}

extern "C" void fn_802ED038(s32, f32, f32, f32, f32);
extern "C" void fn_802ECFEC(void);
extern "C" void *lbl_8033E2CC[];
extern "C" void fn_8022419C(void *arg0) {
 s32 ptr=*(s32 *)((u8 *)arg0+0x254); if(ptr) fn_802ED038(ptr,*(f32 *)((u8 *)arg0+0x244),*(f32 *)((u8 *)arg0+0x248),*(f32 *)((u8 *)arg0+0x24C),*(f32 *)((u8 *)arg0+0x250));
}

/* Initializes a UI image object from a descriptor and loads its image resource. */
extern "C" void *fn_802241C8(void *object, void *descriptor) {
    char pathBuffer[256];

    fn_80218F80();
    *(void **)object = lbl_8033E2CC;

    fn_80230C30((f32 *)((u8 *)object + 0x244), (f32 *)((u8 *)object + 0x248),
                *(s32 *)((u8 *)descriptor + 8), *(s32 *)((u8 *)descriptor + 0xC));
    *(f32 *)((u8 *)object + 0x24C) = *(s32 *)((u8 *)descriptor + 0x14);
    *(f32 *)((u8 *)object + 0x250) = *(s32 *)((u8 *)descriptor + 0x18);

    sprintf(pathBuffer, lbl_8033DAAC, (char *)descriptor + 0x40);
    s32 imageRes = ((s32 (*)(void *))fn_802C5130)(pathBuffer);
    *(s32 *)((u8 *)object + 0x254) = imageRes;
    if (imageRes == 0) {
        fn_802E30C8(lbl_8033DABC, pathBuffer);
    }

    return object;
}

extern "C" void *fn_802242A4(void *arg0,s32 arg1) {
 s32 ptr; if(arg0){ ptr=*(s32 *)((u8 *)arg0+0x254); *(void ***)arg0=lbl_8033E2CC; if(ptr) fn_802C519C((void *)ptr); *(s32 *)((u8 *)arg0+0x254)=0; fn_8021915C(arg0,0); if(arg1>0) fn_80128668(arg0); } return arg0;
}

extern "C" void fn_80224328(void *arg0) {
 s32 ptr=*(s32 *)((u8 *)arg0+0x254); if(ptr) fn_802C5320(ptr,0,*(f32 *)((u8 *)arg0+0x244),*(f32 *)((u8 *)arg0+0x248),lbl_805634A8,*(f32 *)((u8 *)arg0+0x24C),*(f32 *)((u8 *)arg0+0x250));
}

#pragma push
#pragma fp_contract on
extern "C" void *fn_8022435C(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 *arg4, void *unused) {
    register u8 *resource = (u8 *)arg2;
    register u8 *self = (u8 *)arg0;
    register s32 initial = arg1;
    register s32 length = arg3;
    register s32 *link = arg4;
    register s32 zero = 0;
    char name[0x100];

    ((void *(*)(void *, void *))fn_80218F80)(self, resource);
    *(void **)self = lbl_8033E248;
    fn_80230C30((f32 *)(self + 0x270), (f32 *)(self + 0x274),
                *(s32 *)(resource + 8), *(s32 *)(resource + 0xc));

    *(f32 *)(self + 0x278) = (f32)*(s32 *)(resource + 0x14);
    *(u8 *)(self + 0x260) = 0;
    *(f32 *)(self + 0x27c) = (f32)*(s32 *)(resource + 0x18);
    *(u8 *)(self + 0x261) = 0;

    u32 top = *(u32 *)(resource + 0x9c) >> 31;
    *(u32 *)(self + 0x248) = top;
    f32 color;
    if (top == 0) {
        color = lbl_805634A8;
    } else {
        color = lbl_805634B0;
    }
    *(f32 *)(self + 0x26c) = color;
    *(f32 *)(self + 0x268) = color;

    *(s32 *)(self + 0x254) =
        fn_80228F40(*(s32 *)(self + 4), *(s32 *)(self + 8));
    *(s32 *)(self + 0x258) = zero;
    *(s32 *)(self + 0x25c) = length;
    *(s32 *)(self + 0x250) = initial;
    s32 flags = *(s32 *)(resource + 0x9c);
    s32 sign = flags >> 31;
    *(s32 *)(self + 0x264) = (flags ^ sign) - sign;

    *(void **)(self + 0x284) = fn_8022EE9C();
    *(void **)(self + 0x288) = fn_8022EE9C();
    *(f32 *)(self + 0x24c) = lbl_805634A8;

    if (link != 0) {
        *(s32 *)(self + 0x244) = *link;
        strcpy(name, (char *)(resource + 0x40));
        s32 handle = ((s32 (*)(void *))fn_802C5130)(name);
        *(s32 *)(self + 0x280) = handle;
        if (handle == 0)
            fn_802E30C8(lbl_8033DABC, name);
    }
    return self;
}
#pragma pop
extern "C" void *fn_802244C8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        void *ptr = *(void **)((u8 *)arg0 + 0x280);
        *(void **)arg0 = lbl_8033E248;
        if (ptr != 0)
            fn_802C519C(ptr);
        *(void **)((u8 *)arg0 + 0x280) = 0;
        fn_8022EE98(*(void **)((u8 *)arg0 + 0x288));
        fn_8022EE98(*(void **)((u8 *)arg0 + 0x284));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8022455C(void *arg0) {
    void *result = (void *)fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C), *(s32 *)((u8 *)arg0 + 0x254), arg0);
    *(void **)((u8 *)arg0 + 0x258) = result;
    fn_80219440(arg0, 0, result, 4);
    ((Dummy2455C *)arg0)->d27(0, 0);
}

extern "C" double sin(double);

/* --- Intensity fade ----------------------------------------------------
 * fn_8022435C builds one of these (vtable lbl_8033E248) from a resource whose
 * +0x9C word gives the fade rate, its sign picking the mode.  fn_80224864
 * starts a fade when the effect starts or stops playing, fn_802245C8 runs it
 * every frame and fn_802248FC hands the value to the effect slot at +0x284,
 * whose +0x30 float scales what is drawn through it.  Only the fields the fade
 * uses are named; the ones around them belong to the functions here.
 */
typedef struct IntensityFade {
    u8 header[0x248];  /* the object this is part of, see fn_8022435C */
    s32 mode;          /* 0x248: 0 fades in/out of 0.0, 1 of 0.1 */
    f32 startTime;     /* 0x24C: fn_8023659C() time the current fade began at */
    u8 pad_250[0x10];
    u8 fadingIn;       /* 0x260: rising towards the wave */
    u8 fadingOut;      /* 0x261: falling towards the resting level */
    u8 pad_262[2];
    s32 speed;         /* 0x264: ramp rate and wave frequency */
    f32 value;         /* 0x268: the intensity the fade drives */
    f32 startValue;    /* 0x26C: value a fall-off started from */
} IntensityFade;

extern f32 lbl_8056353C, lbl_80563540;
#define FADE_OFF     lbl_805634A8  /* 0.0f: where mode 0 rests */
#define FADE_IDLE    lbl_805634B0  /* 0.1f: where mode 1 rests */
#define FADE_HALF    lbl_805634C4  /* 0.5f: mode 0 wave centre and swing */
#define FADE_DONE_0  lbl_80563518  /* 0.005f: mode 0 is done fading out below this */
#define FADE_SWING_1 lbl_8056353C  /* 0.45f: mode 1 wave swing */
#define FADE_DONE_1  lbl_80563540  /* 0.105f: mode 1 is done fading out below this */

#pragma push
#pragma processor 750
/* Runs one frame of the intensity fade.  Coming in, the value climbs linearly
 * with the time since the fade started but never above a sine of the same rate
 * (so it pulses its way up); going out, it falls from the value it had when the
 * fade started at that same rate down to the mode's resting level, and clears
 * the flag once it is within a hair of it.  fn_802192AC then refreshes the
 * links this object drives. */
extern "C" void fn_802245C8(IntensityFade *fade) {
    if (fn_8023659C() < fade->startTime)
        fade->startTime = fn_8023659C();
    switch (fade->mode) {
    case 0:
        if (fade->fadingIn) {
            f32 wave = FADE_HALF + FADE_HALF * (f32)sin((f32)(fade->speed+1)*(fn_8023659C()-fade->startTime));
            f32 ramp = (f32)(fade->speed+1)*(fn_8023659C()-fade->startTime);
            fade->value = ramp < wave ? ramp : wave;
        } else if (fade->fadingOut) {
            if (fade->value < FADE_DONE_0) {
                f32 end = FADE_OFF;
                fade->fadingOut=0;
                fade->value=end;
            } else {
                f32 ramp = fade->startValue-(f32)(fade->speed+1)*(fn_8023659C()-fade->startTime);
                fade->value=ramp > FADE_OFF ? ramp : FADE_OFF;
            }
        }
        break;
    case 1:
        if (fade->fadingIn) {
            f32 wave = FADE_SWING_1 + (FADE_IDLE + FADE_SWING_1*(f32)sin((f32)-fade->speed*(fn_8023659C()-fade->startTime)));
            f32 ramp = FADE_IDLE + (f32)fade->speed*(fn_8023659C()-fade->startTime);
            fade->value=ramp < wave ? ramp : wave;
        } else if (fade->fadingOut) {
            if (fade->value < FADE_DONE_1) {
                f32 end = FADE_IDLE;
                fade->fadingOut=0;
                fade->value=end;
            } else {
                f32 ramp = fade->startValue-(f32)fade->speed*(fn_8023659C()-fade->startTime);
                fade->value=ramp > FADE_IDLE ? ramp : FADE_IDLE;
            }
        }
        break;
    }
    fn_802192AC(fade);
}
#pragma pop
extern "C" void fn_80224864(void *arg0) {
    u8 temp_r6 = *(u8 *)((u8 *)arg0 + 0x260);

    if (temp_r6 == 0) {
        if (*(s32 *)((u8 *)arg0 + 0x254) ==
            *(volatile s32 *)*(volatile s32 **)((u8 *)arg0 + 0x258)) {
            *(u8 *)((u8 *)arg0 + 0x261) = 0;
            *(u8 *)((u8 *)arg0 + 0x260) = 1;
            goto after_conditions;
        }
    }
    if (temp_r6 != 0) {
        if (*(s32 *)((u8 *)arg0 + 0x254) !=
            *(volatile s32 *)*(volatile s32 **)((u8 *)arg0 + 0x258)) {
            *(u8 *)((u8 *)arg0 + 0x260) = 0;
            *(u8 *)((u8 *)arg0 + 0x261) = 1;
        }
    }
after_conditions:
    *(f32 *)((u8 *)arg0 + 0x24C) = fn_8023659C();
    *(f32 *)((u8 *)arg0 + 0x26C) = *(f32 *)((u8 *)arg0 + 0x268);
}

#pragma push
#pragma ppc_psq_save off
#pragma scheduling invalid_target
extern "C" void fn_802248FC(void *arg0) {
    /* Render the intensity-fade effect: set the effect slot's scale, combine it
     * with the current draw context, and submit the image for this frame. */
    u8 *self = (u8 *)arg0;
    if (*(s32 *)(self + 0x280) == 0) return;
    if (self[0x1B] == 0)
        *(f32 *)(*(u8 **)(self + 0x284) + 0x30) = lbl_805634C4;
    else if (self[0x260] != 0)
        *(f32 *)(*(u8 **)(self + 0x284) + 0x30) = *(f32 *)(self + 0x268);
    else
        *(f32 *)(*(u8 **)(self + 0x284) + 0x30) = (*(s32 *)(self + 0x248) == 1) ? lbl_805634A4 : lbl_805634A8;
    fn_8022EEF8(*(void **)(self + 0x288), fn_8022EDC4(), (s32)*(u32 *)(self + 0x284));
    fn_8022ED00(*(void **)(self + 0x288));
    s32 delta;
    s32 rem;
    rem = *(s32 *)(self + 0x10) - *(s32 *)(self + 8);
    s32 divisor = fn_802C51AC(*(s32 *)(self + 0x280));
    s32 value = *(s32 *)(self + 0x244);
    delta = value % divisor;
    s32 got = ((Vf78x *)arg0)->get();
    f32 gotFloat = (f32)got;
    f32 remFloat = (f32)rem;
    fn_802C5320(*(s32 *)(self + 0x280), delta, *(f32 *)(self + 0x270),
        *(f32 *)(self + 0x274), lbl_805634A8, gotFloat, remFloat);
    fn_8022EDB8();
}
#pragma scheduling on
#pragma pop
// ---------------------------------------------------------------------------
// One handler of the menu widget that tracks an entry of the list its owner
// holds at +0x2C (fn_80217BD8 makes the tracking object for an id and
// fn_80219440 links it in; fn_8022455C is what stores it here).  Of the
// fields this handler touches:
//
//   +0x250 s32          the value handed to the confirm callback
//   +0x254 s32          the id this widget tracks
//   +0x258 void*        the tracking object for that id; its first word is
//                       the id it is still valid for, so the handler does
//                       nothing once that has moved on
//   +0x25C s32 (*)(s32) confirm callback, called with +0x250; returning 0
//                       swallows the confirm
//
// fn_802168BC hands the value to the dialog loop waiting in fn_802168F0, and
// fn_80217D84 / fn_80217C4C step the list at +0x2C back / forward one entry.
// The same three actions, on another widget, are fn_802267C4.
#define ACTION_CONFIRM 0xD    // the confirm action
#define ACTION_PREV    0x126  // step to the previous entry of the list
#define ACTION_NEXT    0x128  // step to the next entry of the list

extern "C" s32 fn_80224A38(void *widget, s32 action) {
    // One action of the widget, only while the tracking object it was given
    // still carries the id it tracks: confirm answers the dialog with the
    // widget's value, unless the confirm callback refuses it, and the two step
    // actions move the tracked entry of the list back or forward one.
    s32 *tracking = *(s32 **)((u8 *)widget + 0x258);
    s32 (*confirm)(s32);
    if (tracking == 0) {
        return 0;
    }
    if (*(s32 *)((u8 *)widget + 0x254) != *tracking) {
        return 0;
    }
    switch (action) {
    case ACTION_CONFIRM:
        confirm = *(s32 (**)(s32))((u8 *)widget + 0x25C);
        if (confirm != 0 && confirm(*(s32 *)((u8 *)widget + 0x250)) == 0) {
            return 1;
        }
        fn_802168BC((void *)*(s32 *)((u8 *)widget + 0x250));
        return 1;
    case ACTION_PREV:
        fn_80217D84(*(s32 *)((u8 *)widget + 0x2C));
        return 1;
    case ACTION_NEXT:
        fn_80217C4C(*(s32 *)((u8 *)widget + 0x2C));
        return 1;
    default:
        return 0;
    }
}

extern "C" s32 fn_80224B0C(void *arg0, s32 arg1) {
    void *p = *(void **)((u8 *)arg0 + 0x258);
    if (p != 0 && *(s32 *)((u8 *)arg0 + 0x254) != *(s32 *)p)
        return 0;
    return arg1 == 0xD || (u32)arg1 == 0x126 || (u32)arg1 == 0x128;
}

extern "C" void *fn_80224B54(void *arg0, void *arg1, void *arg2) {
    volatile u8 *self = (volatile u8 *)arg0;
    register s32 first;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ((void *(*)(void *, void *))fn_80218F80)((void *)self, arg2);
    *(void *volatile *)self = lbl_8033E1C4;
    strcpy((char *)(self + 0x259), &lbl_8055B88C);
    self[0x258] = 0;
    switch (*(s32 *)((u8 *)arg2 + 0xA0)) {
    case 0:
        self[0x258] = 1;
        strcpy((char *)(self + 0x259), &lbl_8055B88C);
        break;
    case 1:
        first = fn_80129D90(1, 1, 8);
        sprintf((char *)(self + 0x259), lbl_8033DAD8, fn_80129D90(1, 0x42, 0x45), first);
        break;
    }
    if (arg1 != 0) {
        *(s32 *)(self + 0x244) = (s32)arg1;
    } else {
        *(s32 *)(self + 0x244) = fn_80131234((u8 *)arg2 + 0x20);
    }
    *(s32 *)(self + 0x248) = fn_80232578((s32)((u8 *)arg2 + 0x40));
    *(s32 *)(self + 0x24C) = *(s32 *)((u8 *)arg2 + 0x90);
    *(s32 *)(self + 0x250) = *(s32 *)((u8 *)arg2 + 4);
    {
        s32 ticks = ((s32 (*)(void))fn_80232B70)();
        *(u8 *)(self + 0x299) = 0;
        *(s32 *)(self + 0x29C) = 0;
        *(f32 *)(self + 0x254) = *(f32 *)((u8 *)arg2 + 0x1C) / (f32)ticks;
    }
    memcpy(&sp10, (u8 *)arg2 + 0xA4, 4);
    memcpy(&spC, (u8 *)arg2 + 0xA8, 4);
    memcpy(&sp8, (u8 *)arg2 + 0xAC, 4);
    if ((f32)FN8021C18C_ABS((double)sp10) > *(f32 *)&lbl_80558DC4 ||
        (f32)FN8021C18C_ABS((double)spC) > *(f32 *)&lbl_80558DC4 ||
        (f32)FN8021C18C_ABS((double)sp8) > *(f32 *)&lbl_80558DC4) {
        fn_80224DDC((void *)self, sp10, spC, sp8);
    }
    return (void *)self;
}

#pragma push
#pragma small_data on
extern "C" void *fn_80224D40(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        u8 enabled = *(u8 *)((u8 *)arg0 + 0x299);
        *(void **)arg0 = lbl_8033E1C4;
        if (enabled != 0) {
            fn_8022EE98(*(void **)((u8 *)arg0 + 0x29C));
        }
        fn_802328D4(*(void **)((u8 *)arg0 + 0x248));
        *(s32 *)((u8 *)arg0 + 0x248) = 0;
        char *dst = (char *)arg0 + 0x259;
        char *src = (char *)&lbl_8055B88C;
        *(s32 *)((u8 *)arg0 + 0x244) = 0;
        strcpy(dst, src);
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma processor 750
extern "C" void fn_80224DDC(void *arg0, f32 x, f32 y, f32 z) {
    f32 result[11];
    f32 scaled[3];
    *(u8 *)((u8 *)arg0 + 0x299) = 1;
    void *tmp = fn_8022EE9C();
    f32 c = lbl_805634F8;
    f32 *ps = scaled;
    *(void **)((u8 *)arg0 + 0x29C) = tmp;
    f32 *pr = result;
    f32 sx = c * x;
    f32 sy = c * y;
    f32 sz = c * z;
    ps[0] = sx;
    ps[1] = sy;
    ps[2] = sz;
    void *handle = *(void **)((u8 *)arg0 + 0x29C);
    ((void (*)(void *, void *, f32, f32))fn_80015A20)(pr, ps, sx, sy);
    fn_80015B20(handle, pr, handle);
}
#pragma pop
extern "C" f32 lbl_80563544;
extern "C" void fn_80232C50(char *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
extern "C" void fn_80224E74(void *this_) {
    char buf1[0x200];
    char buf2[0x200];
    u8 tmp[0x40];
    if (TB(0x299, u8) != 0) {
        fn_8022EEF8(tmp, TB(0x29C, s32), fn_8022EDC4());
        fn_8022ED00(tmp);
    }
    s32 h = ((DummyTextBoxV *)this_)->g28();
    s32 x0 = TB(8, s32);
    char *p = TB(0x244, char *);
    f32 hh = (f32)h;
    f32 hf = (f32)(TB(0x10, s32) - x0);
    strlen(p);
    f32 xx = (f32)TB(4, s32);
    f32 yy = (f32)x0;
    if (TB(0x250, u32) & 0x10) {
        s32 n = 0;
        while (*p != 0) {
            char *start = p;
            char *dst;
            n++;
            memset(buf1, 0, 0x200);
            dst = buf1;
            do {
                u8 c = *p;
                char *e = ((c & 0xF0) == 0xE0) ? p + 3 : ((c & 0xE0) == 0xC0) ? p + 2 : p + 1;
                s32 len = e - p;
                for (s32 i = 0; i < len; i++) *dst++ = *p++;
                if (!(TB(0x254, f32) * fn_8023293C(TB(0x248, s32), (s32)buf1, lbl_805634A4) < hh)) break;
            } while (*p != 0 && *p != 10);
            char *save = p;
            if (*p != 0) {
                while (*p != 0x20 && *p != 10 && p > start) p--;
            }
            if (p <= start) p = save;
            if (*p == 0x20 || *p == 10) p++;
        }
        f32 lh = (f32)(TB(0x10, s32) - TB(8, s32));
        yy += lbl_805634C4 * lh;
        yy -= lbl_805634C4 * (f32)(n - 1) * TB(0x254, f32) * (f32)fn_80232B70(TB(0x248, s32));
    }
    f64 f31 = yy;
    p = TB(0x244, char *);
    f32 wdiv = lbl_80563544;
    f32 half = lbl_805634C4;
    s32 row = 0;
    while (*p != 0) {
        char *start = p;
        s32 n;
        s32 fits;
        memset(buf2, 0, 0x200);
        n = 0;
        do {
            u8 c = *p;
            char *e = ((c & 0xF0) == 0xE0) ? p + 3 : ((c & 0xE0) == 0xC0) ? p + 2 : p + 1;
            s32 len = e - p;
            for (s32 i = 0; i < len; i++) buf2[n++] = *p++;
            fits = TB(0x254, f32) * fn_8023293C(TB(0x248, s32), (s32)buf2, lbl_805634A4) < hh;
        } while (fits && *p != 0 && *p != 10);
        char *save = p;
        s32 saven = n;
        if (*p != 0) {
            while (*p != 0x20 && p != start && *p != 10) {
                p--;
                n--;
            }
        }
        if (p == start) {
            p = save;
            n = saven;
        }
        buf2[n] = 0;
        if (*p == 0x20 || *p == 10) p++;
        for (s32 i = 0; i < n; i++) {
            if (buf2[i] == 0x5E) buf2[i] = 0x20;
        }
        s32 W = lbl_8055FB9C;
        s32 H = lbl_8055FBA0;
        f32 x = (f32)W / wdiv + xx;
        f32 f3 = TB(0x254, f32);
        f32 y = (f32)H * half - ((f32)f31 + (f32)row * (f3 * (f32)fn_80232B70(TB(0x248, s32))));
        row++;
        if (TB(0x258, u8) == 0 && y < (f32)H * half - (hf + (f32)TB(8, s32))) {
            fn_80232BA4((char *)this_ + 0x259, TB(0x248, s32), TB(0x24C, s32), 10, x + hh, y, f3 - lbl_805634B0, lbl_805634A8, lbl_805634A4);
            break;
        }
        u32 flags = TB(0x250, u32);
        if (flags & 4) x += hh * half;
        if (flags & 2) {
            fn_80232C50(buf2, TB(0x248, s32), TB(0x24C, s32), 9, x, y, TB(0x254, f32), hh, lbl_805634A8, lbl_805634A4);
        } else {
            fn_80232BA4(buf2, TB(0x248, s32), TB(0x24C, s32), 0, x, y, TB(0x254, f32), lbl_805634A8, lbl_805634A4);
        }
    }
    if (TB(0x299, u8) != 0) fn_8022EDB8();
}
#pragma pop
extern "C" u8 lbl_8033DA84[];
extern "C" u8 lbl_8033DAEC[];
extern "C" u8 lbl_8033E140[];
extern f32 lbl_80563544;
extern f32 lbl_805634E0;
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_8022553C(void *arg0, void *arg1, void *arg2) {
register u8 *obj = (u8 *)arg0;
register u8 *ctx = (u8 *)arg2;
s32 count;
register s32 offset;
register s32 row;
register s32 frame;
f32 half;
f32 value;
f32 temp_f4;
f32 temp_f3;
f32 temp_f2;
f32 temp_f1;

((void (*)(void *, void *))fn_80218F80)(arg0, ctx);
*(s32 *)(obj + 0x244) = (s32)arg1;
*(void **)obj = lbl_8033E140;
*(s32 *)(obj + 0x248) = fn_80232578((s32)lbl_8033DA84);
count = 1;
if (*(s32 *)(ctx + 0x9C) > count)
count = *(s32 *)(ctx + 0x9C);
count = count < 3 ? count : 3;
*(s32 *)(obj + 0x24C) = count;
temp_f4 = (f32)lbl_8055FB9C;
temp_f3 = temp_f4 / lbl_80563544;
*(f32 *)(obj + 0x254) =
(f32)*(s32 *)(obj + 4) + temp_f3;
temp_f2 = (f32)lbl_8055FBA0;
temp_f1 = temp_f2 * lbl_805634C4;
*(f32 *)(obj + 0x258) =
temp_f1 - (f32)*(s32 *)(obj + 8);
*(f32 *)(obj + 0x25C) =
(f32)fn_80232B70(*(s32 *)(obj + 0x248)) + lbl_805634E0;
value = *(f32 *)(obj + 0x25C) * (f32)*(s32 *)(*(s32 *)(obj + 0x244) + 8);
half = lbl_805634C4 * value;
*(f32 *)(obj + 0x260) = value;
*(f32 *)(obj + 0x264) = *(f32 *)(obj + 0x258) + half;
*(f32 *)(obj + 0x268) = *(f32 *)(obj + 0x258) - half;
*(s32 *)(obj + 0x278) = fn_8012850C(
(void *)(*(s32 *)(*(s32 *)(obj + 0x244) + 8) * 0xC),
(const char *)lbl_8033DAEC);
count = *(s32 *)(*(s32 *)(obj + 0x244) + 0xC);
offset = count * 0xC;
row = count;
frame = 0;
while (row < *(s32 *)(*(s32 *)(obj + 0x244) + 8)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) =
*(f32 *)(obj + 0x258) - *(f32 *)(obj + 0x25C) * (f32)frame;
if (*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) <
*(f32 *)(obj + 0x268)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) =
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) +
*(f32 *)(obj + 0x260);
}
frame++;
row++;
value = *(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset);
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset + 8) = value;
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset + 4) = value;
offset += 0xC;
}
row = 0;
offset = 0;
while (row < *(s32 *)(*(s32 *)(obj + 0x244) + 0xC)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) =
*(f32 *)(obj + 0x258) - *(f32 *)(obj + 0x25C) * (f32)frame;
if (*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) <
*(f32 *)(obj + 0x268)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) =
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) +
*(f32 *)(obj + 0x260);
}
frame++;
row++;
value = *(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset);
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset + 8) = value;
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset + 4) = value;
offset += 0xC;
}
*(s32 *)(obj + 0x274) = 0;
*(f32 *)(obj + 0x250) = fn_8023659C();
*(f32 *)(obj + 0x26C) = lbl_805634A8;
*(f32 *)(obj + 0x270) = fn_8023659C();
*(s32 *)(obj + 0x27C) = 0;
*(s32 *)(obj + 0x280) = fn_80228F40(*(s32 *)(obj + 4), *(s32 *)(obj + 8));
return arg0;
}
#pragma scheduling on
#pragma pop
extern "C" void *fn_80225828(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 ptr = *(s32 *)((u8 *)arg0 + 0x278);
        *(void **)arg0 = lbl_8033E140;
        if (ptr != 0) {
            fn_80128670(ptr);
        }
        void *resource = *(void **)((u8 *)arg0 + 0x248);
        *(s32 *)((u8 *)arg0 + 0x278) = 0;
        if (resource != 0) {
            fn_802328D4(resource);
        }
        *(s32 *)((u8 *)arg0 + 0x248) = 0;
        *(s32 *)((u8 *)arg0 + 0x244) = 0;
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802258C8(void *arg0) {
    void *result;
    result = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C), *(s32 *)((u8 *)arg0 + 0x280), arg0);
    *(void **)((u8 *)arg0 + 0x27C) = result;
    fn_80219440(arg0, 1, result, 4);
}

#pragma pop
extern "C" void fn_80225918(void *arg0) {
    fn_802192AC(arg0);
}

extern "C" f32 lbl_80563548;

/* The row table the scrolling list walks (built elsewhere; fn_8022553C reads its
 * counts and fn_802263CC asks it before accepting a message). */
typedef struct ScrollRowTable {
    u8   header[8];
    s32  rowCount;        /* 0x08: rows in the list */
    s32  topRowCount;     /* 0x0C: rows stacked before the list wraps */
    u8   pad_10[4];
    s32 (*callback)(void);/* 0x14: optional gate for message 0xD */
    u8   enabled;         /* 0x18: gates the up/down messages */
} ScrollRowTable;

/* One row of the scrolling list: where it draws, and the two ends of the
 * scroll it is settling. */
typedef struct ScrollRow {
    f32 y;      /* 0x00: the row's current y */
    f32 fromY;  /* 0x04: the y the current scroll started from */
    f32 toY;    /* 0x08: the y the scroll leaves the row at */
} ScrollRow;

/* The scrolling list of text rows fn_8022553C builds (a results/credits
 * roller): rows sit rowHeight apart inside the band [yMin, yMax] and wrap by
 * loopHeight.  A scroll message moves every row's target one rowHeight and
 * starts a SCROLL_TWEEN_TIME second settle; only the fields used by the
 * functions here are named. */
typedef struct ScrollList {
    u8             header[0x244];
    ScrollRowTable *rowTable;   /* 0x244 */
    void           *fontRes;    /* 0x248: text resource, see fn_80232578 */
    s32            drawRows;    /* 0x24C: rows drawn, 1..3 */
    f32            scrollStart; /* 0x250: fn_8023659C() time the scroll began */
    f32            x;           /* 0x254 */
    f32            yCenter;     /* 0x258 */
    f32            rowHeight;   /* 0x25C: one row step */
    f32            loopHeight;  /* 0x260: rowHeight * rowCount, one full wrap */
    f32            yMax;        /* 0x264: top of the band rows wrap inside */
    f32            yMin;        /* 0x268: bottom of that band */
    f32            fade;        /* 0x26C */
    f32            time;        /* 0x270 */
    s32            scrollDir;   /* 0x274: 0 settled, 1 rows moving down, 2 up */
    ScrollRow     *rows;        /* 0x278: rowCount of them */
} ScrollList;

#define SCROLL_TWEEN_TIME lbl_80563548 /* 0.2f: how long a one-row scroll takes */

#pragma push
#pragma unroll off
#pragma opt_loop_invariants off
/* Runs one frame of the list's one-row scroll.  A scroll message (fn_802263CC,
 * after fn_80226570 moved every row's target one rowHeight and wrapped it into
 * the band) leaves scrollDir 1 for rows moving down or 2 for rows moving up and
 * stamps scrollStart; here each row's y is interpolated from the y that scroll
 * started at toward its target over SCROLL_TWEEN_TIME seconds.  A target that
 * wrapped past the band's edge is reached through the wrapped side, so a row
 * keeps going the way it was heading instead of turning back across the screen.
 * Once the time is up every row is left exactly on its target and the scroll
 * ends. */
extern "C" void fn_8022591C(void *arg0) {
    ScrollList *list = (ScrollList *)arg0;
    if (list->scrollDir == 0)
        return;
    f32 now = fn_8023659C();
    f32 *startTime = &list->scrollStart;
    if (*startTime > now)
        *startTime = now - SCROLL_TWEEN_TIME;
    f32 duration = SCROLL_TWEEN_TIME;
    f32 elapsed = now - *startTime;
    if (elapsed > duration) {
        for (s32 i = 0; i < list->rowTable->rowCount; i++) {
            f32 end = list->rows[i].toY;
            list->rows[i].y = end;
            list->rows[i].fromY = end;
        }
        list->scrollDir = 0;
        return;
    }
    for (s32 i = 0; i < list->rowTable->rowCount; i++) {
        switch (list->scrollDir) {
        case 0: break;
        case 2: { /* rows moving up */
            ScrollRow *row = &list->rows[i];
            f32 low, high;
            high = row->toY;
            low = row->fromY;
            if (high > low)
                row->y = low + (elapsed / duration) * (high - low);
            else if (high < low) { /* the target wrapped below the band */
                if (row->y > high) {
                    f32 base = list->yMax + (high - list->yMin);
                    row->y = low + (elapsed / duration) * (base - low);
                } else if (row->y < high) {
                    f32 base = list->yMin - (list->yMax - low);
                    row->y = base + (elapsed / duration) * (high - base);
                }
            }
            break;
        }
        case 1: { /* rows moving down */
            ScrollRow *row = &list->rows[i];
            f32 low, high;
            high = row->toY;
            low = row->fromY;
            if (high < low)
                row->y = low + (elapsed / duration) * (high - low);
            else if (high > low) { /* the target wrapped above the band */
                if (row->y < high) {
                    f32 base = list->yMin - (list->yMax - high);
                    row->y = low + (elapsed / duration) * (base - low);
                } else if (row->y > high) {
                    f32 base = list->yMax + (low - list->yMin);
                    row->y = base + (elapsed / duration) * (high - base);
                }
            }
            break;
        }
        }
        ScrollRow *row = &list->rows[i];
        if (row->y > list->yMax)
            row->y -= list->loopHeight;
        else if (row->y < list->yMin)
            row->y += list->loopHeight;
    }
}

extern "C" void fn_80225B6C(void *arg0) {
    fn_8022591C(arg0);
}

#pragma pop
extern "C" s32 fn_80217C4C(s32);
extern "C" s32 fn_80217D84(s32);
extern "C" void fn_80226570(void *, s32);
extern "C" s32 fn_8022DBE8(void *);
extern "C" s32 fn_8022DBFC(void *);
extern "C" s32 fn_8022DC20(void *);
extern "C" s32 fn_802263CC(void *arg0, s32 arg1) {
    /* Handles UI/menu input events for this widget: validates the active selection, then
       dispatches button/action codes (0xD/0x125-0x128) to step/select items, update state and
       timestamp, or invoke a confirm callback. Returns 1 if handled, 0 otherwise. */
    void *activeEntry = *(void **)((u8 *)arg0 + 0x27C);
    s32 result;
    if (activeEntry != 0 && (s32)*(void **)((u8 *)arg0 + 0x280) != (s32)*(void **)activeEntry)
        return 0;

    switch (arg1) {
    case 0x127:
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x244) + 0x18) == 0)
            goto default_case;
        fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C));
        return 1;
    case 0x125:
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x244) + 0x18) == 0)
            goto default_case;
        fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C));
        return 1;
    case 0x128:
        fn_8022DBFC(*(void **)((u8 *)arg0 + 0x244));
        fn_80226570(arg0, -1);
        *(s32 *)((u8 *)arg0 + 0x274) = 2;
        *(f32 *)((u8 *)arg0 + 0x250) = fn_8023659C();
        return 1;
    case 0x126:
        fn_8022DC20(*(void **)((u8 *)arg0 + 0x244));
        fn_80226570(arg0, 1);
        *(s32 *)((u8 *)arg0 + 0x274) = 1;
        *(f32 *)((u8 *)arg0 + 0x250) = fn_8023659C();
        return 1;
    case 0xD: {
        void *obj = *(void **)((u8 *)arg0 + 0x244);
        s32 (*callback)(void) = *(s32 (**)(void))((u8 *)obj + 0x14);
        result = fn_8022DBE8(obj);
        if (callback == 0 || callback() != 0)
            fn_802168BC((void *)(u32)result);
        return 1;
    }
    default_case:
    default:
        return 0;
    }
}

extern "C" void *fn_802224B4(void *, s32, s32, s32, s32, s32, s32, s32, u8, u8);
extern "C" char lbl_8033F7F4[];
extern "C" s32 fn_80226528(void *arg0, s32 arg1) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x27C);
    if (p != 0 && *(s32 *)((u8 *)arg0 + 0x280) != *p)
        return 0;
    return arg1 == 0xD || (u32)arg1 == 0x126 || (u32)arg1 == 0x128;
}

extern "C" void fn_80226570(void *arg0, s32 arg1) {
    /* Update each scroll item's previous/current Y: copy current to previous, advance by step*arg1, and wrap into [min,max] range. */
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    for (; i < *(s32 *)(*(u8 **)((u8 *)arg0 + 0x244) + 8); offset += 12, i++) {
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 4) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset);
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 8) -=
            *(f32 *)((u8 *)arg0 + 0x25C) * (f32)arg1;
        if (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 8) >
            *(f32 *)((u8 *)arg0 + 0x264)) {
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 8) -=
                *(f32 *)((u8 *)arg0 + 0x260);
        }
        if (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 8) <
            *(f32 *)((u8 *)arg0 + 0x268)) {
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x278) + offset + 8) +=
                *(f32 *)((u8 *)arg0 + 0x260);
        }
    }
}

extern "C" void *fn_80226630(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    fn_802224B4(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 1, 0);
    *(void **)arg0 = (void *)&lbl_8033F7F4;
    *(s32 *)((u8 *)arg0 + 0x260) = fn_80228F40(arg2, arg3);
    *(s32 *)((u8 *)arg0 + 0x264) = 0;
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802266B0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802223C4(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80226708(void *arg0) {
    void *result;
    result = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C), *(s32 *)((u8 *)arg0 + 0x260), arg0);
    *(void **)((u8 *)arg0 + 0x264) = result;
    fn_80219440(arg0, 1, result, 4);
}

extern "C" void fn_80226758(void *arg0) {
    *(s32 *)*(u32 *)((u8 *)arg0 + 0x264) = *(s32 *)((u8 *)arg0 + 0x260);
}

extern "C" void fn_80226768(void *arg0) {
    s32 (*callback)(s32);
    if (*(u8 *)((u8 *)arg0 + 0x18) != 0) {
        callback = *(s32 (**)(s32))((u8 *)arg0 + 0x258);
        if (callback == 0 || callback(*(s32 *)((u8 *)arg0 + 0x25C)) != 0)
            fn_802168BC((void *)*(s32 *)((u8 *)arg0 + 0x25C));
    }
}

extern "C" s32 fn_802267C4(void *arg0, s32 arg1) {
    /* Handle action codes for this object when its tracked/validated id matches: confirm callback, close, or play forward/back. */
    s32 *trackedIdPtr = *(s32 **)((u8 *)arg0 + 0x264);
    s32 (*confirmCallback)(s32);
    if (!trackedIdPtr) return 0;
    if (*(s32 *)((u8 *)arg0 + 0x260) != *trackedIdPtr) return 0;
    switch (arg1) {
    case 0xD:
        confirmCallback = *(s32 (**)(s32))((u8 *)arg0 + 0x258);
        if (confirmCallback == 0 || confirmCallback(*(s32 *)((u8 *)arg0 + 0x25C)) != 0)
            fn_802168BC((void *)*(s32 *)((u8 *)arg0 + 0x25C));
        return 1;
    case 0x126: fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C)); fn_80230E90(0); return 1;
    case 0x128: fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C)); fn_80230E90(0); return 1;
    default: return 0;
    }
}

extern "C" s32 fn_802268A0(void *arg0, s32 arg1) {
    s32 *p = *(s32 **)((u8 *)arg0 + 0x264);
    if (p != 0 && *(s32 *)((u8 *)arg0 + 0x260) != *p)
        return 0;
    return arg1 == 0xD || (u32)arg1 == 0x126 || (u32)arg1 == 0x128;
}

extern "C" u32 fn_802268E8(void *arg0) {
    class Obj7 { public: virtual s32 f0(); virtual s32 f1(); virtual s32 f2(); virtual s32 f3(); virtual s32 f4(); virtual s32 f5(); virtual s32 f6(); virtual s32 f7(); };
    /* Compute a UI/state result from tracked/flag fields and a related object's vtable query. */
    s32 *trackedValue;
    s32 isMatch;
    u32 state;
    void *obj;
    trackedValue = *(s32 **)((char *)arg0 + 0x264);
    if (trackedValue == 0) return 0;
    isMatch = (*(s32 *)((char *)arg0 + 0x260) == *trackedValue);
    if (*(u8 *)((char *)arg0 + 0x18) != 0)
        state = (u32)(isMatch != 0) + 2;
    else
        state = (u32)(isMatch != 0);
    obj = *(void **)((char *)arg0 + 0x244);
    if (((Obj7 *)obj)->f5() == 3 && state == 3) state = 1;
    if (*(u8 *)((char *)arg0 + 0x1B) == 0) state = 4;
    return state;
}

extern char lbl_8033DAF8[];
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void *fn_8022EE9C(void);
extern "C" void *fn_802269A8(void *obj, void *arg1) {
    class Obj28 { public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
        virtual void f25(); virtual void f26(); virtual void f27(); virtual s32 f28();
        s32 width; s32 height; s32 padC; s32 total; u8 pad14[0x230];
        s32 result; void *region; f32 coords[2]; f32 diff; f32 elapsed; s32 count;
    };
    register Obj28 *self = (Obj28 *)obj;
    fn_80218F80();
    *(void **)self = lbl_8033E0BC;
    if ((self->result = ((s32 (*)(void *))fn_802C5130)((u8 *)arg1 + 0x40)) == 0)
        fn_802E30C8(lbl_8033DAF8, (u8 *)((u32)arg1 + 0x40));
    self->region = fn_8022EE9C();
    fn_80230C30(&self->coords[0], &self->coords[1], self->width, self->height);
    s32 h = self->total - self->height;
    self->diff = (f32)h;
    s32 v = self->f28();
    f32 elapsed = (f32)v;
    f32 scale = lbl_805634C4;
    f32 offset = scale * elapsed;
    self->elapsed = elapsed;
    *(f32 *)((u8 *)self->region + 0x24) = self->coords[0] + offset;
    *(f32 *)((u8 *)self->region + 0x28) =
        self->coords[1] - self->diff * scale;
    self->count = *(s32 *)((u8 *)arg1 + 0x9C);
    return obj;
}

extern "C" void *fn_80226AD0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        void *ptr = *(void **)((u8 *)arg0 + 0x248);
        *(void **)arg0 = lbl_8033E0BC;
        if (ptr != 0)
            fn_8022EE98(ptr);
        *(void **)((u8 *)arg0 + 0x248) = 0;
        void *p2 = *(void **)((u8 *)arg0 + 0x244);
        if (p2 != 0)
            fn_802C519C(p2);
        *(volatile u32 *)((u8 *)arg0 + 0x244) = 0;
        register void *self = arg0;
        fn_8021915C(self, 0);
        if (arg1 > 0)
            fn_80128668(self);
    }
    return arg0;
}

extern "C" void fn_80015A20(void *, f32 *, s32, f32, f32, f32);
extern "C" void fn_80015B20(void *, void *, void *);
extern "C" f32 lbl_805634E4;
extern "C" f32 lbl_805634A4;
extern "C" extern f64 lbl_805634B8;
#pragma scheduling invalid_target
extern "C" void fn_80226B6C(void *arg0) {
    u8 *p = (u8 *)arg0;
    u8 scratch[0x78];
    f32 now = fn_8023659C();
    f32 scale;
    volatile f32 *matrix = (volatile f32 *)*(void **)(p + 0x248);
    f32 zero;
    f32 one;
    f32 x;
    f32 delta;
    f32 factor;
    f32 y;
    f32 delta2;

    one = lbl_805634A4;
    zero = lbl_805634A8;
    matrix[0] = one;
    scale = now / lbl_805634E4;
    matrix[1] = zero;
    matrix[2] = zero;
    matrix[3] = zero;
    matrix[4] = one;
    matrix[5] = zero;
    matrix[6] = zero;
    matrix[7] = zero;
    matrix[8] = one;
    matrix[9] = zero;
    matrix[10] = zero;
    matrix[11] = zero;

    *(u32 *)(scratch + 0x74) =
        *(u32 *)(p + 0x25c) ^ 0x80000000;
    *(u32 *)(scratch + 0x70) = 0x43300000;
    *(f32 *)(scratch + 0x00) = zero;
    *(f32 *)(scratch + 0x04) = zero;
    *(f32 *)(scratch + 0x08) =
        scale * (f32)(*(f64 *)(scratch + 0x70) - lbl_805634B8);

    {
        void *obj = *(void **)(p + 0x248);
        ((void (*)(void *, void *))fn_80015A20)(scratch + 0x0c, scratch);
        fn_80015B20(obj, scratch + 0x0c, obj);
    }

    delta = *(f32 *)(p + 0x258);
    factor = lbl_805634C4;
    x = *(f32 *)(p + 0x24c);
    delta *= factor;
    x += delta;
    *(f32 *)((u8 *)*(void **)(p + 0x248) + 0x24) = x;

    delta2 = *(f32 *)(p + 0x254);
    y = *(f32 *)(p + 0x250);
    delta2 *= factor;
    y -= delta2;
    *(f32 *)((u8 *)*(void **)(p + 0x248) + 0x28) = y;

    if (*(s32 *)(p + 0x244) != 0) {
        s32 value = fn_8022EDC4();
        fn_8022EEF8(scratch + 0x30,
                    (s32)*(void **)(p + 0x248), value);
        fn_8022ED00(scratch + 0x30);
        f32 a = *(f32 *)(p + 0x258);
        f32 b = *(f32 *)(p + 0x254);
        fn_802C5320(*(s32 *)(p + 0x244), 0, -a * lbl_805634C4,
                    b * lbl_805634C4, lbl_805634A8, a, b);
        fn_8022EDB8();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma processor 750
extern "C" void *fn_80226CBC(void *arg0, void *arg1) {
    u8 *self = (u8 *)arg0;
    u8 *arg = (u8 *)arg1;
    char *base = lbl_8033D878;
    f32 x, y, z;
    ((void *(*)(void *, void *))fn_80218F80)(arg0, arg1);
    *(void **)self = &lbl_8033E038;
    *(f32 *)(self + 0x250) = (f32)(*(s32 *)(self + 0x10) - *(s32 *)(self + 8));
    *(f32 *)(self + 0x254) = (f32)((Vf78 *)self)->get();
    s32 type = *(s32 *)(arg + 0x9C);
    *(s32 *)(self + 0x258) = type;
    if (type < 0 || type > 15) fn_802E30C8(base + 0x2A4, type);
    if (*(s32 *)(self + 0x258) == 0 || *(s32 *)(self + 0x258) == 1) {
        if (!lbl_8055EFBC) {
            lbl_8055EFBC = 1;
            fn_802E30C8(lbl_8055B8A4, base + 0x2D0);
        }
        if (*(s32 *)(self + 0x258) == 0) *(s32 *)(self + 0x258) = 4;
        else *(s32 *)(self + 0x258) = 7;
    }
    char *name = base + 0x328;
    *(s32 *)(self + 0x244) = fn_8023512C((s32)name);
    if (!*(s32 *)(self + 0x244)) fn_802E30C8(base + 0x338, name);
    if (*(s32 *)(self + 0x244) && fn_80235FD8(*(s32 *)(self + 0x244)) != 15) {
        fn_802E30C8(base + 0x368, name, fn_80235FD8(*(s32 *)(self + 0x244)));
        fn_80235380(*(void **)(self + 0x244));
        *(s32 *)(self + 0x244) = 0;
    }
    *(u8 *)(self + 0x260) = 0;
    *(s32 *)(self + 0x25C) = 0;
    memcpy(&x, arg + 0xA4, 4);
    memcpy(&y, arg + 0xA8, 4);
    memcpy(&z, arg + 0xAC, 4);
    f32 lim = *(f32 *)lbl_80558DC4;
    if (! (lim >= (f32)__fabs((double)x)) || ! (lim >= (f32)__fabs((double)y)) || ! (lim >= (f32)__fabs((double)z)))
        fn_80227044(self, x, y, z);
    return self;
}
#pragma pop

extern "C" { __declspec(section ".data") extern char lbl_8033E038; }
extern "C" void fn_80235380(void *);
extern "C" void *fn_80226F00(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8033E038;
        if (*(u8 *)((u8 *)arg0 + 0x260) != 0)
            fn_8022EE98(*(void **)((u8 *)arg0 + 0x25C));
        void *old = *(void **)((u8 *)arg0 + 0x244);
        if (old != 0)
            fn_80235380(old);
        *(volatile s32 *)((u8 *)arg0 + 0x244) = 0;
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80226F94(void *arg0) {
    /* Renders/transforms this UI element when its drawable and index are valid,
       optionally bracketing with a temporary matrix/state when flag is set. */
    struct Widget {
        u8 pad0[4];
        s32 width;
        s32 height;
        u8 pad1[0x238];
        void *drawable;
        f32 x;
        f32 y;
        f32 scaleZ;
        f32 scaleW;
        s32 index;
        s32 matrixValue;
        u8 useMatrix;
    };
    u8 matrixScratch[0x40];
    Widget *widget = (Widget *)arg0;

    if (widget->useMatrix != 0) {
        fn_8022EEF8(matrixScratch, widget->matrixValue, fn_8022EDC4());
        fn_8022ED00(matrixScratch);
    }
    fn_80230C30(&widget->x, &widget->y, widget->width, widget->height);
    if (widget->drawable != 0 && widget->index >= 0 && widget->index < 0xF) {
        fn_802354A0((s32)widget->drawable, widget->index, -1,
                    widget->x, widget->y, lbl_805634A8, widget->scaleW, widget->scaleZ);
    }
    if (widget->useMatrix != 0) {
        fn_8022EDB8();
    }
}

#pragma push
#pragma processor 750
extern "C" void fn_80227044(void *arg0, float x, float y, float z) {
    float result[11];
    float scaled[3];
    *(unsigned char *)((char *)arg0 + 0x260) = 1;
    void *tmp = fn_8022EE9C();
    float k = lbl_805634F8;
    *(void **)((char *)arg0 + 0x25C) = tmp;
    float sz = k * z;
    float sy = k * y;
    float sx = k * x;
    scaled[0] = sx;
    scaled[1] = sy;
    scaled[2] = sz;
    void *handle = *(void **)((char *)arg0 + 0x25C);
    ((void (*)(void *, void *, float, float))fn_80015A20)(&result[0], &scaled[0], sx, sy);
    fn_80015B20(handle, &result[0], handle);
}
#pragma pop
extern "C" void *fn_802270DC(void *arg0, void *arg1) {
    register s32 context = (s32)arg1;
    register u8 *obj = (u8 *)arg0;

    fn_80218F80();
    *(void **)obj = lbl_8033DFB4;

    fn_80230C30((f32 *)(obj + 0x244), (f32 *)(obj + 0x248),
                *(s32 *)(obj + 4), *(s32 *)(obj + 8));
    *(f32 *)(obj + 0x250) =
        (f32)(*(s32 *)(obj + 0x10) - *(s32 *)(obj + 8));

    *(f32 *)(obj + 0x24c) = (f32)((VfObj *)obj)->vf28();

    *(s32 *)(obj + 0x254) = -1;
    if ((u8 *)(context + 0x40) != 0)
        *(s32 *)(obj + 0x254) = fn_802CAC28((void *)(context + 0x40), 0);

    s32 handle = *(s32 *)(obj + 0x254);
    if (handle != -2 && handle == -1)
        fn_802E30C8(lbl_8033DC20);

    u32 count = *(u32 *)(context + 0x9c);
    *(f32 *)(obj + 0x258) = (f32)count / lbl_805634C8;
    *(f32 *)(obj + 0x25c) = fn_8023659C();
    *(void **)(obj + 0x260) = fn_8022EE9C();
    *(u8 *)(obj + 0x264) = 1;
    *(f32 *)(obj + 0x268) = lbl_805634A8;
    *(f32 *)(obj + 0x26c) = lbl_805634A8;
    *(u8 *)(obj + 0x270) = *(s32 *)(context + 0xb0) != 0;
    return obj;
}
#pragma scheduling on

#pragma pop
extern "C" void *fn_80227244(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8033DFB4;
        fn_8022EE98(*(void **)((u8 *)arg0 + 0x260));
        if (*(s32 *)((u8 *)arg0 + 0x254) != -2 && *(s32 *)((u8 *)arg0 + 0x254) != -1)
            fn_802CAC54();
        *(s32 *)((u8 *)arg0 + 0x254) = -1;
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" f32 lbl_805634C4;
extern "C" f32 lbl_805634E8;
extern "C" f32 lbl_805634FC;
extern "C" f32 lbl_80563560;
#pragma push
#pragma processor 750
extern "C" void fn_802272D4(void *arg0) {
    u8 *p = (u8 *)arg0;
    f32 sp2C[9];
    RotV3 v;
    RotV3 r;
    RotV3 t;
    f32 now = fn_8023659C();
    s32 id = *(s32 *)(p + 0x254);
    if (id != -2 && id != -1) {
        f32 d = (now - *(f32 *)(p + 0x25C)) / *(f32 *)(p + 0x258);
        if (*(u8 *)(p + 0x264) != 0) {
            *(f32 *)(p + 0x268) += d;
            if (*(f32 *)(p + 0x268) > lbl_805634A4) {
                *(f32 *)(p + 0x268) = lbl_805634A4;
                *(u8 *)(p + 0x264) = 0;
            }
        } else {
            *(f32 *)(p + 0x268) -= d;
            if (*(f32 *)(p + 0x268) < lbl_805634A8) {
                *(f32 *)(p + 0x268) = lbl_805634A8;
                *(u8 *)(p + 0x264) = 1;
            }
        }
        f32 *m = *(f32 **)(p + 0x260);
        f32 one = lbl_805634A4;
        f32 zero = lbl_805634A8;
        m[0] = one;
        m[1] = zero;
        m[2] = zero;
        m[3] = zero;
        m[4] = one;
        m[5] = zero;
        m[6] = zero;
        m[7] = zero;
        m[8] = one;
        m[9] = zero;
        m[10] = zero;
        m[11] = zero;
        v.z = zero;
        v.x = (f32)-lbl_8055FB9C * lbl_805634C4;
        v.y = (f32)-lbl_8055FBA0 * lbl_805634C4;
        m = *(f32 **)(p + 0x260);
        Rot3Vec(m, (RotV3 *)(u32)&v, (RotV3 *)(u32)&r);
        m[9] += r.x;
        m[10] += r.y;
        m[11] += r.z;
        if (*(u8 *)(p + 0x270) != 0) {
            *(f32 *)(p + 0x26C) = *(f32 *)(p + 0x26C) - (now - *(f32 *)(p + 0x25C)) / lbl_805634E4;
        } else {
            *(f32 *)(p + 0x26C) = *(f32 *)(p + 0x26C) + (now - *(f32 *)(p + 0x25C)) / lbl_805634FC;
        }
        v.x = lbl_805634A8;
        v.y = lbl_805634A8;
        v.z = *(f32 *)(p + 0x26C);
        void *h = *(void **)(p + 0x260);
        ((void (*)(void *, f32 *))fn_80015A20)(sp2C, &v.x);
        fn_80015B20(h, sp2C, h);
        v.z = lbl_805634A8;
        v.x = (f32)lbl_8055FB9C * lbl_805634C4;
        v.y = (f32)lbl_8055FBA0 * lbl_805634C4;
        m = *(f32 **)(p + 0x260);
        Rot3Vec(m, (RotV3 *)(u32)&v, (RotV3 *)(u32)&t);
        m[9] += t.x;
        m[10] += t.y;
        m[11] += t.z;
        *(f32 *)(*(u8 **)(p + 0x260) + 0x30) = lbl_805634E8 + lbl_80563560 * *(f32 *)(p + 0x268);
        fn_8022ED00(*(void **)(p + 0x260));
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244), *(f32 *)(p + 0x248), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), lbl_805634A8, lbl_805634A8, lbl_805634A4, lbl_805634A4);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244) - (f32)lbl_8055FB9C, *(f32 *)(p + 0x248), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), lbl_805634A8, lbl_805634A8, lbl_805634A4, lbl_805634A4);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244), *(f32 *)(p + 0x248) - (lbl_805634E4 + (f32)lbl_8055FBA0), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), lbl_805634A8, lbl_805634A8, lbl_805634A4, lbl_805634A4);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244) - (f32)lbl_8055FB9C, *(f32 *)(p + 0x248) - (lbl_805634E4 + (f32)lbl_8055FBA0), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), lbl_805634A8, lbl_805634A8, lbl_805634A4, lbl_805634A4);
        fn_8022EDB8();
    }
    *(f32 *)(p + 0x25C) = now;
}
#pragma push
#pragma processor 750
extern "C" void fn_80227880(s32 unused, f32 x, f32 y, f32 width, f32 height) {
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x40FFFFFF, x, y, x + width, y - height, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(
        0x99000000, x, y, x + width, y - height, lbl_805634A8);
}
#pragma pop
extern "C" void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
#pragma scheduling invalid_target
#pragma processor 750
extern "C" void fn_802278F0(s32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    if (arg0) {
        {
            f32 var_f25 = lbl_805634A8;
            s32 var_r31 = 8;
            f32 temp_f26 = lbl_805634A4;
            do {
                do {
                    f32 temp_f1 = fn_80235EF0(arg0, var_r31);
                    f32 temp_f27 = temp_f1;
                    if (temp_f1 - temp_f26 < farg2 - var_f25) {
                        fn_802353F4(arg0, var_r31, farg0 + var_f25, farg1, lbl_805634A8);
                    } else {
                        f32 temp_f29 = fn_80235F64(arg0, var_r31);
                        fn_802354A0(arg0, var_r31, -1, farg0 + var_f25, farg1, lbl_805634A8, farg2 - var_f25, temp_f29);
                    }
                    var_f25 += temp_f27 - temp_f26;
                    var_r31++;
                } while (var_r31 < 10);
                var_r31 = 8;
            } while (var_f25 < farg2);
        }
        {
            f32 var_f25 = lbl_805634A8;
            s32 var_r31 = 10;
            f32 temp_f0;
            f32 temp_f23;
            f32 temp_f24 = fn_80235F64(arg0, 10);
            temp_f0 = farg1 - farg3;
            f32 temp_f26 = lbl_805634A4;
            temp_f23 = temp_f24 + temp_f0;
            do {
                do {
                    f32 temp_f1 = fn_80235EF0(arg0, var_r31);
                    f32 temp_f27 = temp_f1;
                    if (temp_f1 - temp_f26 < farg2 - var_f25) {
                        fn_802353F4(arg0, var_r31, farg0 + var_f25, temp_f23, lbl_805634A8);
                    } else {
                        fn_802354A0(arg0, var_r31, -1, farg0 + var_f25, temp_f23, lbl_805634A8, farg2 - var_f25, temp_f24);
                    }
                    var_f25 += temp_f27 - temp_f26;
                    var_r31++;
                } while (var_r31 < 12);
                var_r31 = 10;
            } while (var_f25 < farg2);
        }
        {
            f32 var_f23 = lbl_805634A8;
            s32 var_r31 = 4;
            f32 temp_f26 = lbl_805634A4;
            do {
                do {
                    f32 temp_f1 = fn_80235F64(arg0, var_r31);
                    f32 temp_f27 = temp_f1;
                    if (temp_f1 - temp_f26 < farg3 - var_f23) {
                        fn_802353F4(arg0, var_r31, farg0, farg1 - var_f23, lbl_805634A8);
                    } else {
                        f32 temp_f29 = fn_80235EF0(arg0, var_r31);
                        fn_802354A0(arg0, var_r31, -1, farg0, farg1 - var_f23, lbl_805634A8, temp_f29, farg3 - var_f23);
                    }
                    var_f23 += temp_f27 - temp_f26;
                    var_r31++;
                } while (var_r31 < 6);
                var_r31 = 4;
            } while (var_f23 < farg3);
        }
        {
            f32 var_f23 = lbl_805634A8;
            s32 var_r31 = 4;
            f32 temp_f1;
            f32 temp_f0;
            temp_f1 = fn_80235EF0(arg0, 4);
            temp_f0 = farg0 + farg2;
            f32 temp_f27 = lbl_805634A4;
            f32 temp_f24 = temp_f0 - temp_f1;
            do {
                var_r31 = 4;
                do {
                    f32 temp_f1 = fn_80235F64(arg0, var_r31);
                    f32 temp_f26 = temp_f1;
                    if (temp_f1 - temp_f27 < farg3 - var_f23) {
                        fn_802353F4(arg0, var_r31, temp_f24, farg1 - var_f23, lbl_805634A8);
                    } else {
                        f32 temp_f29 = fn_80235EF0(arg0, var_r31);
                        fn_802354A0(arg0, var_r31, -1, temp_f24, farg1 - var_f23, lbl_805634A8, temp_f29, farg3 - var_f23);
                    }
                    var_f23 += temp_f26 - temp_f27;
                    var_r31++;
                } while (var_r31 < 8);
                var_r31 = 6;
            } while (var_f23 < farg3);
        }
        fn_802353F4(arg0, 0, farg0 - lbl_805634EC, lbl_805634EC + farg1, lbl_805634A8);
        {
            f32 offset = fn_80235EF0(arg0, 1);
            f32 width = farg0 + farg2;
            f32 x = (lbl_805634EC + width) - offset;
            fn_802353F4(arg0, 1, x, lbl_805634EC + farg1, lbl_805634A8);
        }
        {
            f32 offset = fn_80235F64(arg0, 2);
            f32 difference = farg1 - farg3;
            f32 y = offset + (difference - lbl_805634EC);
            fn_802353F4(arg0, 2, farg0 - lbl_805634EC, y, lbl_805634A8);
        }
        {
            f32 offset = fn_80235F64(arg0, 3);
            f32 difference = farg1 - farg3;
            f32 y = (difference - lbl_805634EC) + offset;
            f32 xoffset = fn_80235EF0(arg0, 3);
            f32 width = farg0 + farg2;
            f32 x = (lbl_805634EC + width) - xoffset;
            fn_802353F4(arg0, 3, x, y, lbl_805634A8);
        }
    }
}

extern "C" void fn_80227C9C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    fn_80227880(arg0, arg1, arg2, arg3, arg4);
    fn_802278F0(arg0, arg1, arg2, arg3, arg4);
}

extern "C" void *fn_80227D00(void *arg0) {
    s32 result;
    void *vtable;

    fn_80218F80();
    vtable = lbl_8033DEAC;
    *(void **)arg0 = vtable;
    result = ((s32 (*)(void *, void *))fn_8023512C)(lbl_8033DC4C, lbl_8033DEAC);
    *(s32 *)((u8 *)arg0 + 0x244) = result;
    if (result == 0)
        fn_802E30C8(lbl_8033DC58);
    return arg0;
}

extern "C" void *fn_80227D64(void *arg0, s32 arg1) {
    s32 ptr;
    if (arg0) {
        ptr = *(s32 *)((u8 *)arg0 + 0x244);
        *(void ***)arg0 = lbl_8033DEAC;
        if (ptr)
            fn_80235380((void *)ptr);
        *(s32 *)((u8 *)arg0 + 0x244) = 0;
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *fn_80227E84(void *self, s32 arg1, void *arg2, s32 arg3) {
    /* Initialize this UI widget: run base setup, store vtable/config fields, load resources and log on failure. */
    char *base = lbl_8033D878;
    s32 resource;

    ((void *(*)(void *, void *))fn_80218F80)(self, arg2);
    *(s32 *)((u8 *)self + 0x248) = arg1;
    *(void **)self = lbl_8033DF30;
    *(s32 *)((u8 *)self + 0x24C) = arg3;
    resource = *(s32 *)((u8 *)arg2 + 0xB0);
    *(u8 *)((u8 *)self + 0x244) = (s8)((resource - 1) == 0);
    resource = ((s32 (*)(const char *, s32))fn_80232578)(base + 0x20C, resource);
    *(s32 *)((u8 *)self + 0x250) = resource;
    if (resource == 0)
        fn_802E30C8(base + 0x408);
    resource = ((s32 (*)(const char *))fn_8023512C)(base + 0x42C);
    *(s32 *)((u8 *)self + 0x254) = resource;
    if (resource == 0)
        fn_802E30C8(base + 0x438);
    resource = ((s32 (*)(const char *))fn_8023512C)(base + 0x3D4);
    *(s32 *)((u8 *)self + 0x258) = resource;
    if (resource == 0)
        fn_802E30C8(base + 0x3E0);
    return self;
}

extern "C" void *fn_80227F5C(void *obj, s32 shouldFree) {
    if (obj != 0) {
        s32 resource0 = *(s32 *)((u8 *)obj + 0x250);
        *(void **)obj = lbl_8033DF30;
        if (resource0 != 0) {
            fn_802328D4((void *)resource0);
        }
        s32 resource1 = *(s32 *)((u8 *)obj + 0x254);
        *(s32 *)((u8 *)obj + 0x250) = 0;
        if (resource1 != 0) {
            fn_80235380((void *)resource1);
        }
        s32 resource2 = *(s32 *)((u8 *)obj + 0x258);
        *(s32 *)((u8 *)obj + 0x254) = 0;
        if (resource2 != 0) {
            fn_80235380((void *)resource2);
        }
        *(s32 *)((u8 *)obj + 0x258) = 0;
        fn_8021915C(obj, 0);
        if (shouldFree > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
}

extern "C" s32 fn_8022DD80(s32);
extern "C" s32 fn_8022DD88(s32);
extern "C" s32 fn_8022DD90(s32, s32);
extern "C" void fn_80227880(s32, f32, f32, f32, f32);
extern f32 lbl_805634EC;
extern f32 lbl_80563564;
extern f32 lbl_80563568;
extern f32 lbl_8056356C;
extern f32 lbl_80563570;
extern f32 lbl_80563574;
extern f32 lbl_80563578;
#pragma push
#pragma ppc_psq_save off
#pragma scheduling invalid_target
extern "C" void fn_80228010(void* arg0) {
union Conv { f64 d; u32 word[2]; } cvtVirtual;
if (*(s32*)((u8*)arg0 + 0x250) != 0 && *(s32*)((u8*)arg0 + 0x254) != 0 && *(s32*)((u8*)arg0 + 0x258) != 0) {
f32 duration, initial, radius;
s32 lastIndex;
duration = fn_80235EF0(*(s32*)((u8*)arg0 + 0x254), 0);
initial = fn_80235EF0(*(s32*)((u8*)arg0 + 0x254), 2);
radius = fn_80235F64(*(s32*)((u8*)arg0 + 0x254), 1);
lastIndex = fn_8022DD88(*(s32*)((u8*)arg0 + 0x248));
f32 negRadius = -radius;
f32 spC = lbl_80563564;
volatile f32 sp8 = lbl_80563568;

if (*(u8*)((u8*)arg0 + 0x244) == 0) {
fn_80230C30(&spC, (f32 *)&sp8, *(s32*)((u8*)arg0 + 4),
*(s32*)((u8*)arg0 + 8));
sp8 -= negRadius;
spC -= lbl_8056356C;
}

s32 count = fn_8022DD80(*(s32*)((u8*)arg0 + 0x248));
s32 temp = count ^ 1;
u32 flag = (u32)((temp >> 1) - (temp & count)) >> 31;
f32 progress = lbl_805634EC + spC;

if (flag != 0) {
f32 scale = lbl_805634C4;
s32 index = 0;
f32 radiusScale = radius * scale;
f32 step = lbl_80563570 + initial;
f32 charWidthDefault = lbl_805634A8;
s32 isLast;
do {
isLast = index == lastIndex;
s32 glyph = fn_8022DD90(*(s32*)((u8*)arg0 + 0x248), index);
f32 width = fn_8023293C(*(s32*)((u8*)arg0 + 0x250), glyph,
lbl_805634A4);
f32 charWidth = charWidthDefault > width ? charWidthDefault : width;
f32 y = sp8;
fn_802353F4(*(s32*)((u8*)arg0 + 0x254), 0, progress, y,
lbl_805634A8);
progress += duration;
fn_802354A0(*(s32*)((u8*)arg0 + 0x254), 1, -1, progress, y,
lbl_805634A8, charWidth, radius);

fn_80232BA4((char*)glyph, *(s32*)((u8*)arg0 + 0x250),
isLast ? -1 : 0xFF707070, 0x14,
progress + charWidth * scale, y - radiusScale,
lbl_805634A4, lbl_805634A8, lbl_805634A4);
progress += charWidth;
fn_802353F4(*(s32*)((u8*)arg0 + 0x254), 2, progress, y,
lbl_805634A8);
progress += step;
index++;
} while (index < count);
}

f32 endPos = lbl_8056356C + spC;
f32 negTop = sp8 + negRadius;
s32 virtualInt = ((VfObj*)arg0)->vf28();
cvtVirtual.word[1] = (u32)virtualInt ^ 0x80000000;
cvtVirtual.word[0] = 0x43300000;
f32 virtualPos = (f32)(cvtVirtual.d - lbl_805634B8);
f32 top = sp8 - radius;
f32 topAdjusted = top - lbl_80563574;
f32 offset3 = fn_80235EF0(*(s32*)((u8*)arg0 + 0x254), 3);
f32 offset4 = fn_80235EF0(*(s32*)((u8*)arg0 + 0x254), 4);
f32 padding = flag != 0 ? offset3 + offset4 : lbl_805634A8;
f32 remaining = virtualPos - padding;
f32 width5 = fn_80235F64(*(s32*)((u8*)arg0 + 0x254), 5);
s32 span = *(s32*)((u8*)arg0 + 0x10) - *(s32*)((u8*)arg0 + 8);
fn_80227880(span, endPos, sp8 - radius, virtualPos, (f32)span);

f32 phase3Pos = endPos;
if (flag != 0) {
fn_802353F4(*(s32*)((u8*)arg0 + 0x254), 3, endPos, topAdjusted,
lbl_805634A8);
phase3Pos = endPos + offset3;
}
fn_802354A0(*(s32*)((u8*)arg0 + 0x254), 5, -1, phase3Pos, topAdjusted,
lbl_805634A8, remaining, width5);

f32 finalX = phase3Pos + lbl_805634C4 * remaining;
s32 text = *(s32*)((u8*)arg0 + 0x24C);
if (text == 0)
text = fn_8022DD90(*(s32*)((u8*)arg0 + 0x248), lastIndex);
fn_80232BA4((char*)text, *(s32*)((u8*)arg0 + 0x250), -1, 0x14, finalX,
(lbl_805634E0 + topAdjusted) - lbl_805634C4 * width5,
lbl_80563578, lbl_805634A8, lbl_805634A4);

if (flag != 0)
fn_802353F4(*(s32*)((u8*)arg0 + 0x254), 4, phase3Pos + remaining,
topAdjusted, lbl_805634A8);

fn_802278F0(*(s32*)((u8*)arg0 + 0x258), endPos, negTop, virtualPos,
(f32)span);
}
}
#pragma pop
#pragma push
#pragma small_data off
extern "C" char lbl_8033DC4C[];
extern "C" char lbl_8033DC58[];
extern "C" void *lbl_8033DEAC[];
#pragma pop

extern "C" void *fn_80228418(void *p, void *q, s32 a) {
    /* Initialize a movie widget, attaching an external movie handle or creating and
     * owning one, then bind it to data at q+0x40. */
    s32 r;
    fn_80218F80();
    *(s32 *)((u8 *)p + 0x244) = 0;
    *(void **)p = lbl_8033DE28;
    *(u8 *)((u8 *)p + 0x248) = 0;
    if (a) {
        *(s32 *)((u8 *)p + 0x244) = a;
    } else {
        r = fn_801284F8(0x18, lbl_8033DCDC);
        if (r)
            r = fn_8023964C();
        *(s32 *)((u8 *)p + 0x244) = r;
        *(u8 *)((u8 *)p + 0x248) = 1;
    }
    fn_80239784(*(s32 *)((u8 *)p + 0x244), (u8 *)q + 0x40);
    return p;
}

extern "C" void *fn_802284BC(void *p,s32 a){if(p){*(void**)p=lbl_8033DE28;fn_8023986C(*(s32*)((u8*)p+0x244));if(*(u8*)((u8*)p+0x248))fn_8023967C(*(s32*)((u8*)p+0x244),1);*(s32*)((u8*)p+0x244)=0;register void *q=p;fn_8021915C(q,0);if(a>0)fn_80128668(p);}return p;}

extern "C" void fn_8022854C(void *p){fn_8023976C(*(s32*)((u8*)p+0x244));}

extern "C" void fn_802396BC(s32);
extern "C" void fn_80228554(void *p){fn_802396BC(*(s32*)((u8*)p+0x244));}

extern "C" void *fn_8022855C(void *p,s32 unused,s32 a,s32 b){fn_80218F80();*(s32*)((u8*)p+0x244)=a;*(void**)p=lbl_8033DDA4;*(s32*)((u8*)p+0x248)=b;return (void*)((char*)p+0);}

extern "C" void fn_802361E8(s32, s32, s32, s32, s32, s32);
extern "C" void fn_80230924(s32, s32, f32, f32, f32, f32, f32);
extern "C" void fn_802285B8(void *arg0) {
    /* Compute screen bounds for this element and draw via object-specific or
     * default rectangle rendering depending on whether a target handle is set. */
    f32 x, y;
    s32 stateValue;
    s32 *statePtr;
    fn_80230C30(&x, &y, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    statePtr = *(s32 **)((u8 *)arg0 + 0x248);
    stateValue = statePtr ? *statePtr : 0;
    if (*(s32 *)((u8 *)arg0 + 0x244) != 0) {
        fn_802361E8(*(s32 *)((u8 *)arg0 + 0x244), stateValue, (s32)x, (s32)y,
                    ((Vf78 *)arg0)->get(),
                    *(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
        return;
    }
    fn_80230924(0x8FAFBFCF, *(s32 *)((u8 *)arg0 + 8), x, y,
                x + (f32)((Vf78 *)arg0)->get(),
                y - (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8)),
                lbl_805634A8);
}

#pragma push
#pragma fp_contract on
extern "C" void *fn_802286E4(void *arg0, void *arg1, s32 arg2) {
    union Conv { f64 d; u32 word[2]; } cvt;
    void *obj;
    s32 count;

    fn_80218F80();
    *(s32 *)((u8 *)arg0 + 0x244) = arg2;
    *(void **)((u8 *)arg0 + 0x268) = 0;
    *(void **)arg0 = lbl_8033DD20;
    *(u8 *)((u8 *)arg0 + 0x26C) = 0;
    memset((u8 *)arg0 + 0x248, 0, 0x20);

    obj = (void *)fn_801284F8(0x40, lbl_8033DCE8);
    if (obj != 0) {
        f32 defaultValue = lbl_805634A8;
        *(void **)obj = lbl_8033DCF8;
        *(s32 *)((u8 *)obj + 4) = -1;
        *(f32 *)((u8 *)obj + 0x38) = defaultValue;
        *(f32 *)((u8 *)obj + 0x3C) = defaultValue;
        if (fn_8012C33C((u8 *)arg1 + 0x40) != 0)
            *(s32 *)((u8 *)obj + 4) = fn_802C6FC0((void *)((s32)arg1 + 0x40), 0, 0);

        count = *(s32 *)((u8 *)arg1 + 0x9C);
        if (count != 0) {
            cvt.word[1] = (u32)count;
            cvt.word[0] = 0x43300000;
            f32 denominator = (f32)(cvt.d - lbl_80563520);
            f32 ratio = lbl_805634D8 / denominator;
            *(f32 *)((u8 *)obj + 0x3C) = ratio;
        }

        f32 a8 = lbl_805634A8;
        f32 a4 = lbl_805634A4;
        *(f32 *)((u8 *)obj + 8) = a4;
        *(f32 *)((u8 *)obj + 0xC) = a8;
        *(f32 *)((u8 *)obj + 0x10) = a8;
        *(f32 *)((u8 *)obj + 0x14) = a8;
        *(f32 *)((u8 *)obj + 0x18) = a4;
        *(f32 *)((u8 *)obj + 0x1C) = a8;
        *(f32 *)((u8 *)obj + 0x20) = a8;
        *(f32 *)((u8 *)obj + 0x24) = a8;
        *(f32 *)((u8 *)obj + 0x28) = a4;
        *(f32 *)((u8 *)obj + 0x2C) = a8;
        *(f32 *)((u8 *)obj + 0x30) = a8;
        *(f32 *)((u8 *)obj + 0x34) = a8;
    }

    *(void **)((u8 *)arg0 + 0x268) = obj;
    *(u8 *)((u8 *)arg0 + 0x26C) = 1;
    return arg0;
}
#pragma pop
extern "C" void *memset(void *, int, unsigned long);
extern "C" void *lbl_8033DD20[];
extern "C" s32 fn_8022882C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

extern "C" void *fn_8022886C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
 fn_80218F80();
 *(s32 *)((u8 *)arg0 + 0x244) = arg3;
 *(s32 *)arg0 = (s32)lbl_8033DD20;
 *(s32 *)((u8 *)arg0 + 0x268) = arg2;
 *(u8 *)((u8 *)arg0 + 0x26C) = 0;
 memset((u8 *)arg0 + 0x248, 0, 0x20);
 return arg0;
}

extern "C" void *__dt__10J2DTextBoxFv(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        u8 flag = *(u8 *)((u8 *)arg0 + 0x26C);
        *(void ***)arg0 = (void **)&lbl_8033DD20;
        if (flag != 0) {
            void *obj = *(void **)((u8 *)arg0 + 0x268);
            if (obj != 0) ((VfObjCall *)obj)->vf2(1);
            *(void **)((u8 *)arg0 + 0x268) = 0;
        }
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8022897C(void *arg0) {
 ((VfObj *)*(void **)((u8 *)arg0 + 0x268))->vf2();
}

extern "C" void fn_80228990(void) {
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80228994(void *arg0) {
    /* If the source string (+0x244) differs from the cached text (+0x248),
     * copy up to 0x20 bytes into the cache (null-terminating on truncation),
     * then notify the dispatch object (+0x268, vtable slot at 0xC). Finally
     * refresh via fn_80228AEC with the current time/value from fn_80214D48. */
    class CopyDispatch {
    public:
        virtual void v0();
        virtual void copy(char *);
    };
    struct Object {
        u8 pad[0x244];
        char *source;
        char text[0x20];
        CopyDispatch *dispatch;
    };
    Object *object = (Object *)arg0;
    if (object->source != 0 && stricmp(object->text, object->source) != 0) {
        u8 c;
        char *source = object->source;
        s32 count = 0x20;
        char *destination = object->text;
        goto copy_loop;
    count_loop:
        count--;
        if (count > 0) goto copy_loop;
        destination[-1] = 0;
        goto copy_done;
    copy_loop:
        c = *source++;
        *destination++ = c;
        if ((s8)c != 0) goto count_loop;
    copy_done:
        object->dispatch->copy(object->text);
    }
    fn_80228AEC((s32)object, fn_80214D48());
}
#pragma pop
extern "C" f32 fn_80214D48(void);
extern "C" void fn_80228AEC(s32, f32);
extern "C" void fn_802C86F0(void *, s32, s32, s32, s32);
extern "C" void fn_802C88BC(s32);
extern "C" void fn_802C8750(void *, s32);
extern "C" void fn_80228A38(s32 arg0) {
    fn_80228AEC(arg0, fn_80214D48());
}

extern "C" void fn_80228A6C(void *arg0) {
    void *obj = *(void **)((u8 *)arg0 + 0x268);
    ((VfObj *)obj)->vf4();
}

extern "C" void fn_80228A80(void) {
}

extern "C" void fn_80228A84(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x270);
    s32 work[2];
    fn_802C86F0(work, value, *(s32 *)((u8 *)arg0 + 0x274),
        *(s32 *)((u8 *)arg0 + 0x278), *(s32 *)((u8 *)arg0 + 0x27C));
    fn_802C88BC(2);
    ((VfObj *)*(void **)((u8 *)arg0 + 0x268))->vf5();
    fn_802C8750(work, -1);
}

#pragma push
#pragma processor 750
extern "C" void fn_80228AEC(s32 arg0, f32 farg0) {
    f32 saved_arg = farg0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f4;
    f32 var_f4_2;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r4;
    s32 var_r7;
    s32 got;

    temp_r30 = lbl_8055CFF0;
    var_r4 = temp_r30 - 2;
    var_f4 = lbl_805634A4;
    temp_f0 = ((f32)*(s32 *)(arg0 + 4) - lbl_805634A8) / lbl_8056357C;
    var_f4 = var_f4 < temp_f0 ? temp_f0 : var_f4;
    var_f4 = var_f4 > lbl_805634A8 ? lbl_805634A8 : var_f4;
    temp_r0 = (s32)(lbl_805634A8 + (var_f4 * ((f32)temp_r30 - lbl_805634A8)));
    var_r4 = temp_r0 < var_r4 ? temp_r0 : var_r4;
    *(s32 *)(arg0 + 0x270) = var_r4;

    var_f4_2 = lbl_805634A4;
    temp_f0_2 = ((f32)*(s32 *)(arg0 + 8) - lbl_805634A8) / lbl_80563580;
    var_f4_2 = var_f4_2 < temp_f0_2 ? temp_f0_2 : var_f4_2;
    var_f4_2 = var_f4_2 > lbl_805634A8 ? lbl_805634A8 : var_f4_2;
    var_r0 = lbl_8055CFF4 - 2;
    temp_r4 = (s32)(lbl_805634A8 + (var_f4_2 * ((f32)lbl_8055CFF4 - lbl_805634A8)));
    var_r0 = temp_r4 < var_r0 ? temp_r4 : var_r0;
    *(s32 *)(arg0 + 0x274) = var_r0;

    got = ((Vf78 *)arg0)->get();
    temp_f1 = ((f32)temp_r30 * (f32)got) / lbl_8056357C;
    if (temp_f1 < lbl_805634A8) {
        var_f0 = temp_f1 - lbl_805634C4;
    } else {
        var_f0 = lbl_805634C4 + temp_f1;
    }
    var_r0_2 = temp_r30 - *(s32 *)(arg0 + 0x270);
    temp_r3 = (s32)var_f0;
    if (temp_r3 < var_r0_2)
        var_r0_2 = temp_r3;
    *(s32 *)(arg0 + 0x278) = var_r0_2;

    temp_f1_2 = ((f32)lbl_8055CFF4 * (f32)(*(s32 *)(arg0 + 0x10) - *(s32 *)(arg0 + 8))) / lbl_80563580;
    if (temp_f1_2 < lbl_805634A8) {
        var_f0_2 = temp_f1_2 - lbl_805634C4;
    } else {
        var_f0_2 = lbl_805634C4 + temp_f1_2;
    }
    var_r7 = lbl_8055CFF4 - *(s32 *)(arg0 + 0x274);
    temp_r0_2 = (s32)var_f0_2;
    if (temp_r0_2 < var_r7)
        var_r7 = temp_r0_2;
    *(s32 *)(arg0 + 0x27C) = var_r7;
    ((Vf14Apply *)*(void **)(arg0 + 0x268))->apply(
        *(s32 *)(arg0 + 0x270), *(s32 *)(arg0 + 0x274),
        *(s32 *)(arg0 + 0x278), saved_arg);
}
#pragma pop
extern "C" void fn_80228D90(void *arg0) {
    TruckIface *obj = *(TruckIface **)((u8 *)arg0 + 0x268);
    obj->vf6();
}

extern "C" s32 fn_80228DA4(void) { return 0; }

extern "C" void fn_80228DAC(void *arg0) {
    TruckIface *obj = *(TruckIface **)((u8 *)arg0 + 0x268);
    obj->vf7();
}

extern "C" void fn_80228DC0(void) { }

extern "C" void fn_80228DC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    /* Draw an image in two clipped pieces split horizontally at the midpoint of arg4,
     * saving/restoring the draw rectangle around each piece. */
    s32 savedRect;
    s32 imageHeight;
    s32 midX;
    u32 halfRounded;

    fn_802C3034(arg0);
    fn_80218E98((void *)arg0, &savedRect);
    fn_802C51C0(arg1);
    imageHeight = fn_802C5220(arg1);
    halfRounded = (u32)arg4 >> 31;
    halfRounded += (u32)arg4;
    midX = arg2 + ((s32)halfRounded >> 1);
    fn_80218EE0((void *)arg0, arg2, arg3, midX, arg3 + imageHeight);
    fn_80218EBC((void *)arg0, &savedRect);
    fn_80218EE0((void *)arg0, midX, arg3, arg2 + arg4, arg3 + imageHeight);
    fn_80218EBC((void *)arg0, &savedRect);
}

extern "C" void fn_80218E98(void *, void *);
extern "C" void fn_80218EBC(void *, void *);
extern "C" void fn_80218EE0(void *, s32, s32, s32, s32);
extern "C" void fn_80228E80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    /* Draw an image in two clipped pieces split vertically at the midpoint of arg4, saving/restoring the draw rectangle around each piece. */
    s32 savedRect;
    s32 imageWidth;
    s32 imageHeight;
    s32 midY;
    u32 halfRounded;

    fn_802C3034(arg0);
    fn_80218E98((void *)arg0, &savedRect);
    imageWidth = fn_802C51C0(arg1);
    imageHeight = fn_802C5220(arg1);
    halfRounded = (u32)arg4 >> 31;
    halfRounded += (u32)arg4;
    midY = arg3 + ((s32)halfRounded >> 1);
    fn_80218EE0((void *)arg0, arg2, arg3, arg2 + imageHeight, midY);
    fn_80218EBC((void *)arg0, &savedRect);
    fn_80218EE0((void *)arg0, arg2, midY, arg2 + imageWidth, arg3 + arg4);
    fn_80218EBC((void *)arg0, &savedRect);
}

extern "C" s32 fn_80228F40(s32 arg0, s32 arg1) {
    return arg0 + arg1 * 1000;
}

extern "C" void *fn_80223208(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228F4C(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80223208(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FA4(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FFC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229054(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802290B0(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022910C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229168(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802291C4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229220(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022927C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802292D8(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229330(void *arg0, int arg1) {
    if (arg0 != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229388(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802223C4(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802293E0(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022943C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229498(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802294F4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma dont_inline on
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229550(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_802223C4(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}
#pragma dont_inline reset
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802295AC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80229604(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x24C) = 0;
}

extern "C" void fn_80229610(void) {
}

extern "C" u32 fn_80229614(void) { return 1; }

extern "C" void fn_8022961C(void) {
}

extern "C" u32 fn_80229620(void) { return 1; }

extern "C" void fn_80229628(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x254) = 1;
    ((VfObj *)arg0)->vf31();
}

extern "C" void fn_80229640(void *arg0) {
    s32 (*callback)();
    ((VfObj *)arg0)->vf31();
    *(u8 *)((u8 *)arg0 + 0x254) = 0;
    if (*(u8 *)((u8 *)arg0 + 0x18) == 0) return;
    if ((u32)(*(s32 *)((u8 *)arg0 + 0x25C) + 0x20000) == 0xFB96) return;
    callback = *(s32 (**)())((u8 *)arg0 + 0x258);
    if (callback != 0) {
        if (callback() == 0) return;
    }
    fn_802168BC((void *)*(s32 *)((u8 *)arg0 + 0x25C));
}

extern "C" s32 fn_802296C0(void *arg0) {
    class Obj5 {
    public:
        virtual s32 f0(); virtual s32 f1(); virtual s32 f2();
        virtual s32 f3(); virtual s32 f4(); virtual s32 f5();
    };
    void *obj;
    u32 result;
    if ((u32)(*(s32 *)((u8 *)arg0 + 0x25C) + 0x20000) != 0xFB96U) {
        if (*(u8 *)((u8 *)arg0 + 0x18) != 0)
            result = (*(u8 *)((u8 *)arg0 + 0x254) != 0) + 2;
        else
            result = 0;
    } else {
        result = 1;
    }
    obj = *(void **)((u8 *)arg0 + 0x244);
    if (((Obj5 *)obj)->f5() == 3 && result == 3)
        result = 1;
    return result;
}

extern "C" void fn_802192AC(void *);
extern "C" void fn_80229750(void *arg0) {
    ((VfObj *)arg0)->vf31();
    *(u8 *)((u8 *)arg0 + 0x18) = 1;
}

extern "C" void fn_80229790(void *arg0) {
    ((VfObj *)arg0)->vf31();
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
}

#pragma scheduling on
extern "C" void fn_802297D0(void *arg0) {
    s32 (*callback)(s32);
    if (*(u8 *)((u8 *)arg0 + 0x257) != 0 &&
        *(u8 *)((u8 *)arg0 + 0x254) != 0 &&
        *(u8 *)((u8 *)arg0 + 0x18) != 0) {
        callback = *(s32 (**)(s32))((u8 *)arg0 + 0x258);
        if (callback == 0 || callback(*(s32 *)((u8 *)arg0 + 0x25C)) != 0) {
            fn_802168BC((void *)*(s32 *)((u8 *)arg0 + 0x25C));
        }
    }
    fn_802192AC(arg0);
}
#pragma scheduling invalid_target
extern "C" void fn_8022984C(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x254);
    *p = (u8)((s8)(*p == 0));
}

extern "C" void fn_80229864(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229884(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_802298A4(s32 arg0) {
    return arg0 + 0x258;
}

extern "C" s32 fn_802298AC(void *arg0) {
    s32 result = 0;
    if (*(u8 *)((char *)arg0 + 0x18) != 0) {
        result = 2;
    }
    return (*(*(u8 **)((char *)arg0 + 0x254)) != 0) | result;
}

extern "C" int fn_802298DC(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        return *p;
    }
    return 0;
}

extern "C" void fn_802298F8(void) {
}

extern "C" void fn_802298FC(void) {
}

extern "C" void fn_80229900(void *arg0) {
    ((Fn80229900VTable *)arg0)->Call(0, 0);
}

extern "C" void fn_80229918(void *arg0) {
    ((VfObj *)arg0)->vf31();
    *(u8 *)((u8 *)arg0 + 0x18) = 1;
}

extern "C" void fn_80229958(void *arg0) {
    ((VfObj *)arg0)->vf31();
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
}

extern "C" void fn_80229998(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        *p = *(int *)((char *)arg0 + 0x258);
    }
}

#pragma scheduling invalid_target
extern "C" s32 fn_802299B0(void *arg0) {
    s32 result = 0;
    s32 *p;
    s32 value;

    if (*(u8 *)((u8 *)arg0 + 0x18) != 0)
        result = 2;
    p = *(s32 **)((u8 *)arg0 + 0x254);
    value = 0;
    if (p != 0) {
        if (*p == *(s32 *)((u8 *)arg0 + 0x258))
            value = 1;
    }
    return (((u32)(-value | value)) >> 31) | result;
}
#pragma scheduling reset
extern "C" void fn_802299FC(void *arg0) {
    class LocalObject {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual s32 At78();
        virtual void v29(); virtual void v30(); virtual void v31();
        virtual s32 At88(s32);
    };
    class LocalApply {
    public:
        virtual void v0();
        virtual void Apply(s32, s32, s32, s32, s32, s32);
    };
    s32 a = *(s32 *)((u8 *)arg0 + 8);
    s32 x;
    s32 diff;
    diff = *(s32 *)((u8 *)arg0 + 0x10) - a;
    x = ((LocalObject *)arg0)->At88(a);
    s32 y = ((LocalObject *)arg0)->At78();
    LocalApply *p = *(LocalApply **)((u8 *)arg0 + 0x244);
    p->Apply(*(s32 *)((u8 *)arg0 + 0x248),
             *(s32 *)((u8 *)arg0 + 0x24C),
             *(s32 *)((u8 *)arg0 + 0x250), y, diff, x);
}

extern "C" void *lbl_8033DF30[];
extern "C" void *lbl_8033DEAC[];
extern "C" void fn_802328D4(void *);
extern "C" void fn_80227C9C(s32, f32, f32, f32, f32);
extern "C" f64 lbl_805634B8;
extern "C" void fn_80229A94(void *arg0) {
    register u32 one = 1;
    *(u8 *)((u8 *)arg0 + 0x19) = one;
    if (*(u8 *)((u8 *)arg0 + 0x1A)) {
        *(u8 *)((u8 *)arg0 + 0x234) = one;
    }
    ((Fn80229A94Dispatch *)arg0)->Call(
        *(s32 *)((u8 *)arg0 + 4),
        *(s32 *)((u8 *)arg0 + 8));
}

extern "C" void fn_80229AC4(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        *p = *(int *)((char *)arg0 + 0x258);
    }
}

extern "C" u32 fn_80229ADC(void) { return 1; }

extern "C" void fn_80229AE4(void *arg0, s32 arg1, s32 arg2) {
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    ((Fn80229AE4Dispatch *)obj)->Call(
        *(s32 *)((u8 *)arg0 + 0x248),
        *(s32 *)((u8 *)arg0 + 0x24C),
        arg1,
        arg2);
}

extern "C" void fn_80229B0C(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void *, s32, s32))fn_80219264)(arg0, arg1, arg2);
    s32 temp_r3 = *(s32 *)((u8 *)arg0 + 0x248) + arg1;
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 0x24C) + arg2;
    *(s32 *)((u8 *)arg0 + 0x24C) = temp_r0;
    *(s32 *)((u8 *)arg0 + 0x248) = temp_r3;
}

extern "C" s32 fn_80229B68(void) { return 0; }

extern "C" s32 fn_80229B70(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x254);
}

extern "C" char lbl_8033EFF4[];
extern "C" s32 fn_801E4A2C(s32, const char *);
extern "C" void * __dt__Q34Game10MemoryCard8ResourceFv_80229B78(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033EFF4;
        fn_801E4A2C(*(s32 *)((u8 *)arg0 + 0x348), lbl_8033EFF4);
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/*
 * Text pane: bring the drawn string up to date.
 *
 * First flushes the values bound to this pane (fn_802192AC() copies every
 * watched block that changed and calls the notification slot for it). Then, if
 * the string the pane was asked to show (this+0x244, a char*) differs from the
 * one it currently draws (the buffer at this+0x248), the new string is copied
 * in, measured in the pane's font (this+0x348) and the pane's bounding box is
 * grown by that width - never less than the pane's own minimum width, from
 * vtable slot 0x78 - and by the font's line height. A pane that is attached to
 * a layout (this+0x1A) marks itself dirty (this+0x234) so it gets redrawn.
 */
extern "C" void fn_80229BE8(void *this_) {
    struct TextPaneVTable {
        // Two destructor slots lead this ABI's vtables, so the 29th declared
        // method is the one at 0x78.
        virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
        virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
        virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual s32 getMinWidth();
    };
    fn_802192AC(this_);
    char *text = TB(0x244, char *);
    if (strcmp(text, (char *)this_ + 0x248) != 0) {
        strcpy((char *)this_ + 0x248, text);
        s32 textWidth = fn_801E4A6C(TB(0x348, s32), TB(0x244, s32));
        s32 ownWidth = ((TextPaneVTable *)this_)->getMinWidth();
        if (ownWidth > textWidth)
            textWidth = ownWidth;
        fn_80219284(this_, textWidth, fn_801E4BA8(TB(0x348, s32)));
        if (TB(0x1A, u8) != 0)
            TB(0x234, u8) = 1;
    }
}

extern "C" s32 fn_80229C9C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" s32 fn_80229CA4(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" s32 fn_80229CAC(s32);
extern "C" s32 fn_80229CAC(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_80229CB4(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 1;
    (*(f32 *)((u8 *)arg0 + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_80229CD8(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 0;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_802C5280(void *, s32, s32, s32, s32, void *);
extern "C" f32 lbl_805634A8;
extern "C" void fn_80229CF8(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
    (*(f32 *)((u8 *)arg0 + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}
extern "C" void fn_80229D1C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
    }
}

#pragma scheduling reset
extern "C" void fn_80229D3C(void *arg0, s32 arg1, s32 arg2) {
    void *self = arg0;
    arg0 = *(void **)((u8 *)arg0 + 0x250);
    fn_802C5280(arg0,
                arg1 - *(s32 *)((u8 *)self + 4),
                arg2 - *(s32 *)((u8 *)self + 8),
                0,
                *(s32 *)((u8 *)self + 4),
                self);
}
extern "C" s32 fn_80229D5C(s32);
extern "C" s32 fn_80229D5C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229D64(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80229DC0(s32 arg0) {
    return arg0 + 0x268;
}

#pragma peephole off
extern "C" void fn_80229DC8(void *arg0, s32 unused, s32 arg2) {
    *(u32 *)((u8 *)arg0 + 0x260) = 0;
    *(u8 *)((u8 *)arg0 + 0x268) = 1;
    ((Fn80229DE8Dispatch2 *)arg0)->Call(unused, arg2);
}
#pragma peephole reset
extern "C" void fn_80229DE8(void *arg0, s32 unused, s32 arg2) {
    register u32 zero = 0;
    register u32 one = 1;
    s32 start = *(s32 *)((u8 *)arg0 + 8);
    *(u32 *)((u8 *)arg0 + 0x260) = zero;
    s32 end = *(s32 *)((u8 *)arg0 + 0x10);
    *(u8 *)((u8 *)arg0 + 0x268) = one;
    ((Fn80229DE8Dispatch2 *)arg0)->Call(unused, arg2 - (end - start) - 3);
}

extern s32 fn_8021E1C8(void *, s32, s32);
extern "C" void fn_80229E1C(void *arg0, s32 unused, s32 arg2) {
    s32 start = *(s32 *)((u8 *)arg0 + 8);
    s32 end = *(s32 *)((u8 *)arg0 + 0x10);
    fn_8021E1C8(arg0, unused, arg2 - (end - start) - 3);
}

extern "C" void fn_80229E34(void *arg0) {
    s32 temp_r0;
    s32 temp_r4;
    void *temp_r5;

    temp_r5 = *(void **)((u8 *)arg0 + 0x248);
    temp_r4 = *(s32 *)((u8 *)temp_r5 + 8) + 1;
    *(s32 *)((u8 *)temp_r5 + 8) = temp_r4;
    temp_r0 = *(s32 *)((u8 *)temp_r5 + 0) - *(s32 *)((u8 *)temp_r5 + 4);
    if (temp_r4 > temp_r0) {
        *(s32 *)((u8 *)temp_r5 + 8) = temp_r0;
    }
    if (*(s32 *)((u8 *)temp_r5 + 8) < 0) {
        *(s32 *)((u8 *)temp_r5 + 8) = 0;
    }
}

extern "C" void fn_80229E74(void *arg0) {
    s32 temp_r0;
    s32 temp_r4;
    void *temp_r5;

    temp_r5 = *(void **)((u8 *)arg0 + 0x248);
    temp_r4 = *(s32 *)((u8 *)temp_r5 + 8) - 1;
    *(s32 *)((u8 *)temp_r5 + 8) = temp_r4;
    temp_r0 = *(s32 *)((u8 *)temp_r5 + 0) - *(s32 *)((u8 *)temp_r5 + 4);
    if (temp_r4 > temp_r0) {
        *(s32 *)((u8 *)temp_r5 + 8) = temp_r0;
    }
    if (*(s32 *)((u8 *)temp_r5 + 8) < 0) {
        *(s32 *)((u8 *)temp_r5 + 8) = 0;
    }
}

extern "C" void fn_80229EB4(void *arg0) {
    *(u8 *)((char *)arg0 + 0x268) = 0;
    *(s32 *)((char *)arg0 + 0x260) = 0;
}

extern "C" u32 fn_80229EC4(void) { return 1; }

extern "C" u32 fn_80229ECC(void) { return 1; }

extern "C" void fn_80229ED4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229EF4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_80229F14(void *arg0) {
    return *(s32 *)((char *)arg0 + 0xA5C);
}

extern "C" void fn_80229F1C(void *arg0) {
    *(u8 *)((char *)arg0 + 0x18) = 1;
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80229F38(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
    }
}

extern "C" s32 fn_80229F58(s32);
extern "C" s32 fn_80229F58(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" s32 fn_80229F60(void *arg0) {
    volatile u8 *value = (volatile u8 *)((char *)arg0 + 0x18);
    s32 result = 0;
    if (*value != 0) {
        result = 2;
    }
    return result;
}

extern "C" void *fn_80229F78(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E878;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x25C));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x260));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void *lbl_8033E878[];
extern "C" void *lbl_8033DCF8[];
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_80229FF0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x244) = 1;
    ((VfObj *)arg0)->vf17();
}

extern "C" void fn_8022A008(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x244) = 0;
}

extern "C" void fn_8022A014(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_8022A034(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" void *lbl_8033E770[];
extern "C" void *fn_8022A054(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E770;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x248));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x24C));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8022A0CC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *fn_8022A124(void *arg0, s32 arg1) {
    s32 temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(s32 *)((u8 *)arg0 + 4);
        *(void **)arg0 = lbl_8033DCF8;
        if (temp_r0 != -1) {
            fn_802C6CF8(temp_r0);
            *(s32 *)((u8 *)arg0 + 4) = -1;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_8012C33C(void *);
extern "C" s32 fn_802C6FC0(void *, s32, s32);
extern "C" void fn_8022A19C(void *arg0, void *arg1) {
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 4);
    if (temp_r0 != -1) {
        fn_802C6CF8(temp_r0);
        *(s32 *)((u8 *)arg0 + 4) = -1;
    }
    if (fn_8012C33C(arg1) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = fn_802C6FC0(arg1, 0, 0);
    }
}

extern "C" void *fn_802C86DC(void);
extern "C" void fn_802C77F0(s32, f32 *);
extern "C" void fn_802C98DC(f32 *, f32 *, f32 *, f32 *);
extern "C" f64 fn_8002F234(f32);
extern "C" f64 atan(f32);
extern "C" f32 lbl_80563584;


#pragma push
#pragma processor 750
extern "C" void fn_8022A210(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    register s32 width = arg3; register void *obj = arg0; register s32 height = arg4;
    f32 scratch[24];
    register f32 temp_f31, var_f30, var_f2, temp_f0, temp_f0_2, temp_f11, temp_f12;
    register f32 axisValue, axisZero, deltaY, deltaX, deltaZ;
    u32 *source; u32 second, first; s32 matrixValue;
    if (*(s32 *)((u8 *)obj + 4) == -1) return;
    *(f32 *)((u8 *)obj + 0x38) += *(f32 *)((u8 *)obj + 0x3C) * arg5;
    source = (u32 *)fn_802C86DC();
    first = source[0]; second = source[1];
    axisValue = *(f32 *)((u8 *)obj + 0x38);
    *(u32 *)((u8 *)obj + 8) = first;
    axisZero = lbl_805634A8;
    *(u32 *)((u8 *)obj + 0xC) = second;
    second = source[2]; first = source[3];
    *(u32 *)((u8 *)obj + 0x10) = second; *(u32 *)((u8 *)obj + 0x14) = first;
    second = source[4]; first = source[5];
    *(u32 *)((u8 *)obj + 0x18) = second; *(u32 *)((u8 *)obj + 0x1C) = first;
    second = source[6]; first = source[7];
    *(u32 *)((u8 *)obj + 0x20) = second; *(u32 *)((u8 *)obj + 0x24) = first;
    first = source[8];
    *(u32 *)((u8 *)obj + 0x28) = first;
    second = source[9]; first = source[10];
    *(u32 *)((u8 *)obj + 0x2C) = second; *(u32 *)((u8 *)obj + 0x30) = first;
    first = source[11];
    *(u32 *)((u8 *)obj + 0x34) = first;
    matrixValue = (s32)second;
    scratch[4] = axisZero; scratch[5] = axisValue; scratch[6] = axisZero;
    ((void (*)(void *, f32 *, s32, f32))fn_80015A20)(&scratch[16], &scratch[4], matrixValue, scratch[5]);
    fn_80015B20((u8 *)obj + 8, &scratch[16], (u8 *)obj + 8);
    fn_802C77F0(*(s32 *)((u8 *)obj + 4), &scratch[10]);
    deltaY = scratch[13] - scratch[12];
    deltaX = scratch[11] - scratch[10];
    deltaZ = scratch[15] - scratch[14];
    temp_f31 = deltaY * deltaY + deltaX * deltaX;
    temp_f31 += deltaZ * deltaZ;
    temp_f31 = (f32)fn_8002F234(temp_f31); temp_f31 = lbl_805634C4 * temp_f31;
    fn_802C98DC(&scratch[1], &scratch[3], &scratch[2], &scratch[0]);
    var_f30 = temp_f31 / scratch[0];
    var_f2 = temp_f31 / (f32)sin((f64)(f32)atan((scratch[1] * (f32)height) / (f32)width));
    temp_f0 = temp_f31 + lbl_80563584 * scratch[3];
    var_f2 = var_f2 > temp_f0 ? var_f2 : temp_f0;
    var_f30 = var_f30 > var_f2 ? var_f30 : var_f2;
    *(f32 *)((u8 *)obj + 0x34) += var_f30;
    temp_f0_2 = scratch[14] + ((scratch[15] - scratch[14]) * lbl_805634C4);
    temp_f11 = scratch[12] + ((scratch[13] - scratch[12]) * lbl_805634C4);
    temp_f12 = scratch[10] + ((scratch[11] - scratch[10]) * lbl_805634C4);
    scratch[7] = temp_f12; scratch[8] = temp_f11; scratch[9] = temp_f0_2;
    f32 *out = &scratch[7];
    volatile f32 *in = &scratch[7];
    f32 x, y, z, a, b, c;
    if (out == in) {
        volatile f32 *mat = (volatile f32 *)obj;
        f32 m3 = mat[5], m0 = mat[2], m4 = mat[6], m1 = mat[3], m5 = mat[7];
        f32 m6 = mat[8], m2 = mat[4], m7 = mat[9], m8 = mat[10];
        f32 p0 = temp_f12 * m0, p1 = temp_f11 * m3;
        f32 p3 = temp_f12 * m1, p4 = temp_f11 * m4, p2 = temp_f12 * m2;
        f32 p5 = temp_f0_2 * m6;
        out[0] = (p0 + p1) + p5;
        f32 p6 = temp_f11 * m5, p7 = temp_f0_2 * m7, p8 = temp_f0_2 * m8;
        out[1] = (p3 + p4) + p7;
        out[2] = (p2 + p6) + p8;
    } else {
        a = temp_f12 * (*(f32 *)((u8 *)obj + 8)); b = temp_f11 * (*(f32 *)((u8 *)obj + 0x14)); c = temp_f0_2 * (*(f32 *)((u8 *)obj + 0x20));
        out[0] = (a + b) + c;
        a = x * (*(f32 *)((u8 *)obj + 0xC)); b = y * (*(f32 *)((u8 *)obj + 0x18)); c = z * (*(f32 *)((u8 *)obj + 0x24));
        out[1] = (a + b) + c;
        a = x * (*(f32 *)((u8 *)obj + 0x10)); b = y * (*(f32 *)((u8 *)obj + 0x1C)); c = z * (*(f32 *)((u8 *)obj + 0x28));
        out[2] = (a + b) + c;
    }
    *(f32 *)((u8 *)obj + 0x2C) -= scratch[7];
    *(f32 *)((u8 *)obj + 0x30) -= scratch[8];
    *(f32 *)((u8 *)obj + 0x34) -= scratch[9];
}
#pragma pop
extern "C" void fn_802C744C(s32, void *);
extern "C" void fn_8022A574(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 4);
    if (value == -1) {
        return;
    }
    fn_802C744C(value, (u8 *)arg0 + 8);
}

extern "C" s32 fn_80229CA4(s32);
extern "C" s32 fn_80229C9C(s32);
extern "C" void fn_80229CB4(void *);
extern "C" void fn_80229CD8(void *);

extern "C" int sprintf(char *, const char *, ...);
extern "C" void fn_801E4BEC(s32, s32, s32, s32, s32, s32);
extern "C" void *lbl_8033E1C4[];
class CallObj80223880 {
public:
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void call(s32, s32);
};

