// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#pragma push
#pragma cplusplus off
typedef struct { u32 words[9]; } MatrixCopy_8021AA18;
typedef struct { u32 words[3]; } VectorCopy_8021AA18;
#pragma always_inline on
static inline void CopyMatrix_8021AA18(void *dst, const void *src) {
    *(MatrixCopy_8021AA18 *)dst = *(const MatrixCopy_8021AA18 *)src;
}
static inline void CopyVector_8021AA18(void *dst, const void *src) {
    *(VectorCopy_8021AA18 *)dst = *(const VectorCopy_8021AA18 *)src;
}
#pragma pop

/* Keys a menu item's handler sees.  The arrows are the Windows virtual-key
   codes with a 0x100 base; Return and Escape keep their plain codes. */
enum {
    MENU_KEY_RETURN = 0xD,
    MENU_KEY_ESCAPE = 0x1B,
    MENU_KEY_LEFT = 0x125,
    MENU_KEY_UP = 0x126,
    MENU_KEY_RIGHT = 0x127,
    MENU_KEY_DOWN = 0x128
};

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
#define RET_802223C4 void*
extern "C" RET_802223C4 fn_802223C4(void *arg0, s32 arg1);
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
extern "C" void fn_802CAC54(int);
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

/* Save the drawing object's clip rectangle -- the four words left/top/right/bottom
 * at +0x14 -- into the caller's savedRect buffer (fn_80218EBC restores it). */
extern "C" void fn_80218E98(void *obj, void *savedRect) {
    s32 bottom, right, top, left;
    volatile s32 *clip = (volatile s32 *)((u8 *)obj + 0x14);
    s32 *save = (s32 *)savedRect;
    left = clip[0];
    top = clip[1];
    right = clip[2];
    bottom = clip[3];
    save[0] = left;
    save[1] = top;
    save[2] = right;
    save[3] = bottom;
}

extern "C" void fn_80218EBC(void *drawObj, void *savedRect) {
    /* Restore a drawing object's clip rectangle (the four s32 words at +0x14) from a saved buffer; inverse of fn_80218E98. */
    s32 bottom, right, top, left;
    volatile s32 *src = (volatile s32 *)savedRect;
    s32 *dst = (s32 *)((u8 *)drawObj + 0x14);
    left = src[0];
    top = src[1];
    right = src[2];
    bottom = src[3];
    dst[0] = left;
    dst[1] = top;
    dst[2] = right;
    dst[3] = bottom;
}

/* Clip the drawing object's rectangle to the one given: the object keeps only the part
 * it shares with (left, top, right, bottom) -- the later of the two left and top edges,
 * the earlier of the two right and bottom ones. fn_80218E98 and fn_80218EBC save and
 * restore these same four words around a clipped draw. */
extern "C" void fn_80218EE0(void *arg0, s32 left, s32 top, s32 right, s32 bottom) {
    /* the object's clip rectangle, the four words at +0x14 */
    struct ClipRect {
        u8 pad[0x14];
        s32 left;
        s32 top;
        s32 right;
        s32 bottom;
    };
    ClipRect *clip = (ClipRect *)arg0;
    s32 ownLeft;
    s32 ownTop;
    s32 ownRight;
    s32 ownBottom;
    s32 newLeft = left;
    s32 newTop = top;
    s32 newRight = right;
    s32 newBottom = bottom;

    ownLeft = clip->left;
    if (ownLeft > newLeft)
        newLeft = ownLeft;
    ownTop = clip->top;
    clip->left = newLeft;
    if (ownTop > newTop)
        newTop = ownTop;
    ownRight = clip->right;
    clip->top = newTop;
    if (ownRight < newRight)
        newRight = ownRight;
    ownBottom = clip->bottom;
    clip->right = newRight;
    if (ownBottom < newBottom)
        newBottom = ownBottom;
    clip->bottom = newBottom;
}

#pragma dont_inline on
extern "C" s32 fn_80218F34(void *object, s32 left, s32 top, s32 right, s32 bottom, s32 flags) {
    /* Construct a UI/widget object: install its vtable, initialize base fields, cache a shared object, and clear its state. */
    *(void **)object = lbl_8033FB38;
    fn_80218FEC(object, left, top, right, bottom, flags);
    *(void **)((u8 *)object + 0x23C) = fn_8021525C();
    *(s32 *)((u8 *)object + 0x240) = 0;
    return (s32)object;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_80218F80(void *arg0, void *arg1) {
    /* Constructs an object: installs vtable lbl_8033FB38, initializes its bounds
     * from arg1 (x, y, w, h, flags), sets field +0x23C from fn_8021525C(), and
     * clears field +0x240. */
    *(void **)arg0 = lbl_8033FB38;
    register void *bounds = arg1;
    s32 y = *(s32 *)((u8 *)arg1 + 0xC);
    s32 x = *(s32 *)((u8 *)arg1 + 8);
    fn_80218FEC(arg0, x, y,
                x + *(s32 *)((u8 *)bounds + 0x14),
                y + *(s32 *)((u8 *)bounds + 0x18),
                *(s32 *)((u8 *)bounds + 0x10));
    *(void **)((u8 *)arg0 + 0x23C) = fn_8021525C();
    *(s32 *)((u8 *)arg0 + 0x240) = 0;
    return arg0;
}
#pragma pop
#define fn_80218F80() ((void (*)(void))fn_80218F80)()

/* Initializes UI bounds/state fields: enables flags, sets default scales/extents, stores bounds/flags, and clears transient state. */
extern "C" void fn_80218FEC(void *obj, s32 left, s32 top, s32 right, s32 bottom, s32 flags) {
    *(u8 *)((u8 *)obj + 0x1A) = 1;
    *(u8 *)((u8 *)obj + 0x1B) = 1;
    *(f32 *)((u8 *)obj + 0x1C) = -1.0f;
    *(f32 *)((u8 *)obj + 0x20) = -1.0f;
    *(f32 *)((u8 *)obj + 0x24) = 1.0f;
    *(f32 *)((u8 *)obj + 0x28) = 1.0f;
    *(u8 *)((u8 *)obj + 0x234) = 1;
    *(s32 *)((u8 *)obj + 0x238) = 0;
    *(u8 *)((u8 *)obj + 0x18) = 0;
    *(s32 *)((u8 *)obj + 0x230) = 0;
    *(s32 *)((u8 *)obj + 4) = left;
    *(s32 *)((u8 *)obj + 0xC) = right;
    *(s32 *)((u8 *)obj + 8) = top;
    *(s32 *)((u8 *)obj + 0x10) = bottom;
    *(s32 *)((u8 *)obj + 0x14) = flags;
    *(u8 *)((u8 *)obj + 0x19) = 0;
    *(s32 *)((u8 *)obj + 0x2C) = 0;
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
/* Destructor: install vtable, release each owned subobject, and optionally free this object. */
extern "C" void *fn_8021915C(void *self, u32 deletingFlag) {
    u8 *entry;
    s32 i;

    if (self != 0) {
        *(void **)self = lbl_8033FB38;
        entry = (u8 *)self;
        i = 0;
        while (i < *(s32 *)((u8 *)self + 0x230)) {
            fn_80128670(*(s32 *)(entry + 0x3C));
            entry += 0x10;
            i++;
        }
        if ((s32)deletingFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}
#pragma pop
#pragma dont_inline off

struct MovieWidgetLayout {
    void *vtable;    /* 0x000 */
    u8 pad_004[0x250];
    s32 movieHandle; /* 0x254 active movie handle opened by fn_802ECF08 */
};
#define MovieWidget_vtable lbl_8033E350
#define Movie_destroy      fn_802ECFF4
#define Widget_dtor        fn_8021915C
#define Mem_freeObject     fn_80128668

extern "C" void fn_802191F0(void *widget, s32 left, s32 top) {
    /* Move the widget to (left, top), updating its right/bottom edges from its width and current height. */
    s32 temp_r0;
    s32 temp_r3;
    temp_r3 = left + ((VfObj *)widget)->vf28();
    *(s32 *)((u8 *)widget + 4) = left;
    temp_r0 = top + (*(s32 *)((u8 *)widget + 0x10) - *(s32 *)((u8 *)widget + 8));
    *(s32 *)((u8 *)widget + 0xC) = temp_r3;
    *(s32 *)((u8 *)widget + 8) = top;
    *(s32 *)((u8 *)widget + 0x10) = temp_r0;
}

#pragma scheduling invalid_target
// Invokes the widget's virtual Call with its stored left/top plus the given x/y offsets.
extern "C" void fn_80219264(void *widget, s32 dx, s32 dy) {
    ((Fn80219264VTable *)widget)->Call(
        *(s32 *)((u8 *)widget + 4) + dx,
        *(s32 *)((u8 *)widget + 8) + dy);
}
#pragma scheduling on
extern "C" void fn_80219284(void *widget, s32 width, s32 height) {
    /* Set the widget's right/bottom edges (+0xC/+0x10) from its left/top position plus the given width and height. */
    *(s32 *)((u8 *)widget + 0xC) = *(s32 *)((u8 *)widget + 4) + width;
    *(s32 *)((u8 *)widget + 0x10) = *(s32 *)((u8 *)widget + 8) + height;
}

extern "C" void fn_802192A0(void) {

}

#pragma dont_inline on
/* Base widget message handler (vtable lbl_8033FB38, slot 0x64).  The base
 * widget class claims no message, so it always answers 0 ("not handled");
 * derived widgets' handlers call it as the fallback for every key they do not
 * use themselves (see fn_8021AB90, fn_802239C8 and the text field's handler). */
extern "C" s32 fn_802192A4(void *widget, s32 message) { return 0; }
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
extern "C" void fn_80219358(void *obj, f32 value) {
    /* Update fade flags/timers based on a threshold: mark active when below it, otherwise initialize/reset fade timing. */
    register f32 threshold = lbl_805634B0;
    if (value < threshold) {
        if (*(u8 *)((u8 *)obj + 0x1A) != 0)
            return;
        *(u8 *)((u8 *)obj + 0x1A) = 1;
        *(u8 *)((u8 *)obj + 0x234) = 1;
        return;
    }
    if (*(u8 *)((u8 *)obj + 0x1A) == 0) {
        if (*(f32 *)((u8 *)obj + 0x20) < lbl_805634B4) {
            f32 divisor;
            *(f32 *)((u8 *)obj + 0x20) = lbl_805634A4;
            if (value > threshold)
                divisor = value;
            else
                divisor = threshold;
            *(f32 *)((u8 *)obj + 0x28) = lbl_805634A4 / divisor;
        }
    }
    *(f32 *)((u8 *)obj + 0x1C) = lbl_805634A0;
}
#pragma scheduling on
#pragma pop
extern "C" void fn_802193C8(void *obj, f32 value) {
    const f32 threshold = 0.1f;
    if (value < threshold) {
        u8 enabled = *(u8 *)((u8 *)obj + 0x1A);
        if (enabled == 0)
            return;
        if (enabled != 0)
            *(u8 *)((u8 *)obj + 0x234) = 1;
        *(u8 *)((u8 *)obj + 0x1A) = 0;
        return;
    }
    if (*(u8 *)((u8 *)obj + 0x1A) != 0) {
        if (*(f32 *)((u8 *)obj + 0x1C) < lbl_805634B4) {
            *(f32 *)((u8 *)obj + 0x1C) = lbl_805634A4;
            *(f32 *)((u8 *)obj + 0x24) = lbl_805634A4 / MAX(value, threshold);
        }
    }
    *(f32 *)((u8 *)obj + 0x20) = lbl_805634A0;
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
// Tab handler: advance the focus of the menu group this widget belongs to
// (its pointer is held at +0x2C) to the next selectable widget.
extern "C" void fn_802194F4(void* widget) {
    fn_802179A0(*(s32*)((u8*)widget + 0x2C));
}
#pragma dont_inline reset

// Clear the current selection on the menu screen (held at +0x2C) of this widget.
extern "C" void fn_802194FC(void* widget) {
    fn_80218198(*(s32*)((u8*)widget + 0x2C), 0);
}

extern "C" void fn_80217AC0(s32);
#pragma dont_inline on
// Tab navigation: hand the menu-group pointer held by this widget at +0x2C to
// the group's selectable-widget focus search.
extern "C" void fn_80219508(void* widget) {
    fn_80217AC0(*(s32*)((u8*)widget + 0x2C));
}
#pragma dont_inline reset

/* Enable text scrolling on this menu widget: store the negated x/y offsets as the
 * scroll origin (+0x244/+0x248) and set the scroll-enabled flag byte (+0x24C),
 * which fn_8021952C later applies to the widget's target position (+0x454/+0x458). */
extern "C" void fn_80219510(void *widget, s32 offsetX, s32 offsetY) {
    s32 scrollX = -offsetX;
    s32 scrollY = -offsetY;
    *(s32 *)((u8 *)widget + 0x244) = scrollX;
    *(u8 *)((u8 *)widget + 0x24C) = 1;
    *(s32 *)((u8 *)widget + 0x248) = scrollY;
}

#pragma scheduling invalid_target
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
extern "C" void *fn_80219568(void *obj, s32 x, s32 y, s32 arg3, s32 arg4, s32 width, s32 height, s32 arg7) {
    /* Initialize a menu text widget: set up base bounds, vtable, and fields at 0x244-0x250. */
    fn_80218F34(obj, x, y, x + width, y + height, arg3);
    *(s32 *)((u8 *)obj + 0x244) = 0;
    *(void **)obj = lbl_8033FA28;
    *(s32 *)((u8 *)obj + 0x248) = 0;
    *(s32 *)((u8 *)obj + 0x24C) = arg3;
    *(s32 *)((u8 *)obj + 0x250) = arg4;
    return obj;
}

/* Draw this menu text widget (its draw method, vtable slot 0x24 of the widget
 * vtables lbl_8033F768 and lbl_8033FA28): first make arg1 the canvas drawing
 * happens on -- fn_802C3034 swaps it into gxcanvas' current-canvas global
 * lbl_8055FC00 -- then hand the text drawer fn_8022B91C the widget's +0x250
 * field (an argument the drawer no longer uses), its own offsets +0x244 and
 * +0x248, the string vf32() (vtable 0x88) answers with, and the draw style
 * vf31() (vtable 0x84) answers with: bit 0 marks the entry the menu cursor
 * stands on and bit 1 the UI mode, which pick the drawer's colour and offset
 * pair. */
extern "C" void fn_802195DC(void *widget, s32 canvas) {
    fn_802C3034(canvas);
    VfObj *obj = (VfObj *)widget;
    s32 style = obj->vf31();
    s32 text = obj->vf32();
    fn_8022B91C(*(s32 *)((u8 *)widget + 0x250), *(s32 *)((u8 *)widget + 0x244), *(s32 *)((u8 *)widget + 0x248), text, style);
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
    /* Recompute this label/widget's bounds from its layout data and update its position/size. */
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 originY;
    s32 width;
    s32 rightEdge;
    s32 bottomEdge;

    fn_8022AC1C(*(s32 *)((u8 *)arg0 + 0x250), ((VfObj *)arg0)->vf32(),
        *(s32 *)((u8 *)arg0 + 0x244) + *(s32 *)((u8 *)arg0 + 4),
        *(s32 *)((u8 *)arg0 + 0x248) + *(s32 *)((u8 *)arg0 + 8),
        &left, &top, &right, &bottom);
    left = left < *(s32 *)((u8 *)arg0 + 4) ? left : *(s32 *)((u8 *)arg0 + 4);
    originY = *(s32 *)((u8 *)arg0 + 4);
    width = ((VfObj *)arg0)->vf28();
    right = right > originY + width ? right : originY + width;
    top = top < *(s32 *)((u8 *)arg0 + 8) ? top : *(s32 *)((u8 *)arg0 + 8);
    bottom = bottom > *(s32 *)((u8 *)arg0 + 0x10) ? bottom : *(s32 *)((u8 *)arg0 + 0x10);
    *(s32 *)((u8 *)arg0 + 0x244) += *(s32 *)((u8 *)arg0 + 4) - left;
    *(s32 *)((u8 *)arg0 + 0x248) += *(s32 *)((u8 *)arg0 + 8) - top;
    ((Dispatch19718_1C *)arg0)->set(left, top);
    rightEdge = right - left;
    bottomEdge = bottom - top;
    fn_80219284(arg0, rightEdge, bottomEdge);
}

extern "C" void *fn_80219870(void *object, s32 arg1, s32 arg2, char *name, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    /* Initialize the object, install its vtable, copy the name, store arg4, and run setup. */
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32, s32))fn_80219568)(object, arg1, arg2, 0, arg5, 0, 0, arg7);
    *(void **)object = lbl_8033F768;
    strcpy((char *)object + 0x258, name);
    *(s32 *)((u8 *)object + 0x254) = arg4;
    fn_80219440(object, 0, (void *)arg4, 1);
    fn_80219718(object);
    return object;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80219900(void *self, int shouldDelete) {
    /* Destroys a MemorySoundArchive instance and optionally deletes it. */
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

#pragma dont_inline on
extern "C" s32 fn_80219958(void *arg0, s32 arg1) {
    return fn_802192A4(arg0, arg1);
}
#pragma dont_inline reset
extern "C" void *fn_8021995C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    /* Initialize a UI object: set up base layout, store arg5 at 0x254, install vtable lbl_8033F4B8, and optionally attach data when arg5 is nonzero. */
    fn_80222340(arg0, arg1, arg2, arg3, 0, 0, arg4);
    *(s32 *)((u8 *)arg0 + 0x254) = arg5;
    *(void **)arg0 = lbl_8033F4B8;
    if (arg5 != 0) {
        fn_80219440(arg0, 0, (void *)arg5, 4);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802199D0(void *self, int shouldDelete) {
    /* Destroy a base subobject and optionally delete storage. */
    if (self != 0) {
        fn_802223C4(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* One record of the menu layout script; the widget factory fn_802123B8 builds
   an object from each record.  Only the fields the text-label constructor
   reads are named here. */
struct LayoutEntry {
    u8 pad0[0x4];
    s32 drawKind; /* 0x04: which draw routine the label runs (see fn_80219FE0) */
    u8 pad8[0x94];
    s32 field9C;  /* -> label+0x250: value shown when nothing is being watched */
    s32 fieldA0;  /* -> label+0x254: text style handed to the draw call */
    s32 fieldA4;  /* -> label+0x280: draw the glyph at its own size */
};

/* The dynamic text-label widget's vtable (0x284-byte object; built by
   fn_80219A28, drawn by fn_80219FE0, destroyed by fn_80219E44). */
#define TextLabelVTable lbl_8033F434

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_80219A28(void *label, LayoutEntry *entry, s32 text, s32 watched) {
    /* Build one dynamic text label (0x284 bytes) for a layout record: run the
       base widget constructor over the raw object, install this class's
       vtable, then let fn_80219AB4 pick the font and the scale that fits the
       string in the box.  `text` is the string to draw and `watched` the
       value (or font file name) the label follows; the factory picks both out
       of the record. */
    fn_80218F80(); /* base constructor; label and entry are still in r3/r4 */
    *(void **)label = TextLabelVTable;
    fn_80219AB4(label, entry->drawKind, text, entry->field9C, watched,
        entry->fieldA0, entry->fieldA4 != 0);
    return label;
}

extern "C" s32 fn_80232B70(s32);
extern "C" f32 fn_8023293C(s32, s32, f32);
extern "C" s32 fn_8023512C(s32);
extern "C" void fn_80235380(void *);
extern char lbl_8033D8B8[];

/* The fields fn_80219AB4 sets up below the 0x244-byte base widget, which the
 * drawer fn_80219FE0 and the destructor fn_80219E44 read back:
 *   0x244 kind: what the label draws (2,4,5 text; 3,6,8,9 a picture)
 *   0x248 the loaded resource: a gText font (text) or an ArtSet (picture)
 *   0x24C the font file name, or the value the label follows (3,6)
 *   0x250 value shown while nothing is being followed (layout field 9C)
 *   0x254 text style handed to the draw call (layout field A0)
 *   0x258 the string as handed in, and 0x25C the label's own 32-byte copy
 *   0x27C the scale the string is drawn at (f32)
 *   0x280 draw the glyphs at their own size (layout field A4)
 * The base widget holds its box at 0x08/0x10 (bottom - top is its height) and
 * answers its width through vtable slot 0x70 (VfObj::vf28). */
#pragma push
#pragma processor 750
extern "C" void fn_80219AB4(void *widget, s32 kind, s32 text, s32 idleValue, s32 watched, s32 style, s32 ownSize) {
    /* Set up one dynamic text label (fn_80219A28 builds the object this runs on):
     * remember what it draws -- the string `text`, the value or font name it
     * follows, where to put it -- and work out the scale to draw the string at so
     * it fits the widget.  Kinds 2, 4 and 5 draw text, so the gText font named by
     * `watched` is loaded; kinds 3, 6, 8 and 9 draw a picture, so the ArtSet named
     * by the string is loaded instead, and kinds 3 and 6 also start following the
     * value at `watched`.  The scale is the smaller of two ratios, the widget's
     * width over the font's own height and the box's height over the width of the
     * string -- kinds 2 and 5 pair those two the other way round.  An unknown kind
     * is only reported. */
    #define GTexLoadFont   fn_80232578 /* gText: the font texture of an archive file name */
    #define GTexFontHeight fn_80232B70 /* gText: a font's nominal glyph height */
    #define GTexMeasure    fn_8023293C /* gText: how wide a string is in a font */
    #define ArtSetLoad     fn_8023512C /* the ArtSet picture set of a resource name */
    #define WatchValue     fn_80219440 /* start following the value at a pointer */
    #define FLOAT_ONE      lbl_805634A4 /* 1.0f */
    #define UNKNOWN_KIND   lbl_8033D8B8 /* "ArtWidget: unknown type %d" */

    const char *str = (const char *)text;
    const char *src = str;
    s32 count = 32;
    u8 *obj = (u8 *)widget;
    char *dst = (char *)obj + 0x25C;
    *(s32 *)(obj + 0x24C) = watched;
    *(s32 *)(obj + 0x258) = (s32)str;
    *(s32 *)(obj + 0x254) = style;
    *(s32 *)(obj + 0x250) = idleValue;
    *(s32 *)(obj + 0x244) = kind;
    while ((*dst++ = *src++) != 0) {
        if (--count <= 0) { dst[-1] = 0; break; }
    }
    f32 one = FLOAT_ONE;
    *(u8 *)(obj + 0x280) = ownSize;
    *(s32 *)(obj + 0x248) = 0;
    s32 fontName = 0;
    *(f32 *)(obj + 0x27C) = one;
    if (kind != 6 && kind != 3) fontName = watched;
    switch (kind) {
    case 4:
        if (fontName) {
            *(s32 *)(obj+0x248) = GTexLoadFont(fontName);
            s32 fontHeight = GTexFontHeight(*(s32 *)(obj+0x248));
            s32 minFontHeight = fontHeight < 1 ? 1 : fontHeight;
            f32 heightScale = (f32)((VfObj *)obj)->vf28() / (f32)minFontHeight;
            f32 textWidth = GTexMeasure(*(s32 *)(obj+0x248),(s32)str,FLOAT_ONE);
            textWidth = textWidth > FLOAT_ONE ? textWidth : FLOAT_ONE;
            f32 widthScale = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / textWidth;
            *(f32 *)(obj+0x27C) = heightScale < widthScale ? heightScale : widthScale;
        }
        break;
    case 2:
        if (fontName) {
            *(s32 *)(obj+0x248) = GTexLoadFont(fontName);
            s32 fontHeight = GTexFontHeight(*(s32 *)(obj+0x248));
            f32 heightScale = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / (f32)(fontHeight < 1 ? 1 : fontHeight);
            f32 textWidth = GTexMeasure(*(s32 *)(obj+0x248),(s32)str,FLOAT_ONE);
            textWidth = textWidth > FLOAT_ONE ? textWidth : FLOAT_ONE;
            f32 widthScale = (f32)((VfObj *)obj)->vf28() / textWidth;
            *(f32 *)(obj+0x27C) = heightScale < widthScale ? heightScale : widthScale;
        }
        break;
    case 9:
        *(s32 *)(obj+0x248) = ArtSetLoad((s32)str);
        break;
    case 3: case 6: case 8:
        *(s32 *)(obj+0x248) = ArtSetLoad((s32)str);
        if(watched) WatchValue(obj,0,(void *)watched,4);
        break;
    case 5:
        if (fontName) {
            *(s32 *)(obj+0x248) = GTexLoadFont(fontName);
            s32 fontHeight = GTexFontHeight(*(s32 *)(obj+0x248));
            f32 heightScale = (f32)(*(s32 *)(obj+0x10)-*(s32 *)(obj+8)) / (f32)(fontHeight < 1 ? 1 : fontHeight);
            f32 textWidth = GTexMeasure(*(s32 *)(obj+0x248),(s32)str,FLOAT_ONE);
            textWidth = textWidth > FLOAT_ONE ? textWidth : FLOAT_ONE;
            f32 widthScale = (f32)((VfObj *)obj)->vf28() / textWidth;
            *(f32 *)(obj+0x27C) = heightScale < widthScale ? heightScale : widthScale;
        }
        break;
    default: fn_802E317C(UNKNOWN_KIND); break;
    }
    #undef GTexLoadFont
    #undef GTexFontHeight
    #undef GTexMeasure
    #undef ArtSetLoad
    #undef WatchValue
    #undef FLOAT_ONE
    #undef UNKNOWN_KIND
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

#pragma opt_common_subs off
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
#pragma opt_common_subs reset
extern "C" void fn_80219AB4(void *, s32, s32, s32, s32, s32, s32);
extern "C" u8 lbl_8033F3B0[];
extern "C" u8 lbl_8033F434[];
/* Initialize an object: run base setup, install lbl_8033F3B0 vtable, and store the provided config fields. */
extern "C" void *fn_8021A5B8(void *object, s32 id, u8 flagA, u8 flagB, s32 value, f32 amount) {
    fn_80218F34(object, 0, 0, 0, 0, (s32)amount);
    *(s32 *)((u8 *)object + 0x248) = id;
    *(void **)object = lbl_8033F3B0;
    *(f32 *)((u8 *)object + 0x24C) = amount;
    *(u8 *)((u8 *)object + 0x250) = flagA;
    *(u8 *)((u8 *)object + 0x251) = flagB;
    *(s32 *)((u8 *)object + 0x254) = value;
    *(s32 *)((u8 *)object + 0x244) = 0;
    return object;
}

/* Destroys a nw4hbm::snd::MemorySoundArchive variant (base subobject via fn_8021915C)
 * and, if shouldDelete > 0, frees the storage. */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021A650(void *self, int shouldDelete) {
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

extern "C" void fn_8021A6A8(void *arg0) {
    /* RealName: ReleaseCachedDisplayObject (finalizes and frees the cached object at offset 0x244, if present). */
    s32 cachedObject = *(s32 *)((u8 *)arg0 + 0x244);
    if (cachedObject != 0) {
        fn_8022FFE8(cachedObject);
        fn_8022F8CC(*(s32 *)((u8 *)arg0 + 0x244));
    }
}

/* Initialize this object's display/state fields and create its drawable handle. */
extern "C" void fn_8021A6EC(void *object) {
    u8 *p = (u8 *)object;
    *(u8 *)(p + 0x250) = 1;
    *(u8 *)(p + 0x251) = 1;
    *(f32 *)(p + 0x24C) = 30.0f;
    *(s32 *)(p + 0x254) = 1;
    *(s32 *)(p + 0x244) = fn_8022F638(*(s32 *)(p + 0x248), 1, 1, 1, 30.0f);
}

extern "C" void fn_8022F824(s32);
extern "C" void fn_8021A744(void *widget) {
    /* Release this cursor-bound icon widget's cached display object (the
       graphic handle at +0x244) and clear the slot. */
    fn_8022F824(*(s32 *)((u8 *)widget + 0x244));
    *(s32 *)((u8 *)widget + 0x244) = 0;
}

extern "C" int lbl_8033F324[];
/* Construct a cursor-bound icon widget (vtable lbl_8033F324) at (x, y), bound to *cursorPtr == cursorId. */
extern "C" void *fn_8021A77C(void *self, s32 x, s32 y, s32 cursorId, s32 cursorPtr, s32 drawer) {
    fn_80222340(self, x, y, 0, 0, 0, drawer);
    *(s32 *)((u8 *)self + 0x254) = cursorPtr;
    *(void **)self = lbl_8033F324;
    *(s32 *)((u8 *)self + 0x258) = cursorId;
    if (cursorPtr != 0) {
        fn_80219440(self, 0, (void *)cursorPtr, 4);
    }
    return self;
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
/* Builds a cursor-bound icon widget at (x, y): the drawer names the graphic it
 * shows, cursor is the selection this menu entry is bound to and cursorId the
 * value that selects it.  Both the selection (tag 0, only when there is one)
 * and the UI mode byte (tag 1) are handed to fn_80219440 to watch, so the
 * widget is told when either changes. */
extern "C" void *fn_8021A808(void *object, s32 x, s32 y, s32 cursorId, s32 *cursor, s32 drawer) {
    CursorIconWidget *widget = (CursorIconWidget *)object;

    fn_80222340(object, x, y, 0, 0, 0, drawer);
    widget->cursor = cursor;
    *(void **)object = lbl_8033F298;
    widget->cursorId = cursorId;
    if (cursor != 0) {
        fn_80219440(object, 0, cursor, 4);
    }
    fn_80219440(object, 1, fn_80216708(), 1);
    return object;
}

#pragma dont_inline reset
extern "C" void *fn_8021D044(void *, s32, s32, s32, const char *, s32, s32, s32, s32);
extern "C" s32 fn_8022A86C(void *);
extern "C" void fn_8021818C(s32);
extern "C" void fn_80218198(s32, void *);
/* Notify this widget of a state change, clear its bound value, and if its cursor still selects it, mark this widget as the current selection. */
extern "C" void fn_8021A8A8(void *widget) {
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
    ((Dispatch *)widget)->call(2, 0);
    fn_8021818C(*(s32 *)((u8 *)widget + 0x2C));
    if (*(s32 *)*(s32 **)((u8 *)widget + 0x254) == *(s32 *)((u8 *)widget + 0x258))
        fn_80218198(*(s32 *)((u8 *)widget + 0x2C), widget);
}

extern "C" void fn_8021A910(void *arg0, s32 arg1) {
    /* Apply a fade-in or fade-out to the sound slots for the object's current sound ID, then perform a final virtual callback. */
    s32 soundId = *(s32 *)((u8 *)arg0 + 0x258);
    if (*(s32 *)*(s32 **)((u8 *)arg0 + 0x254) == soundId) {
        fn_80218968(*(s32 *)((u8 *)arg0 + 0x2C), soundId,
                    arg1 == 2 ? lbl_805634A8 : lbl_805634E8);
    } else {
        fn_8021889C(*(s32 *)((u8 *)arg0 + 0x2C), soundId,
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
#pragma dont_inline off
extern "C" void fn_8021AA18(void *widget) {
    /* Draw a cursor-bound icon: copy the current transform, damp its X
     * translation when the entry is not selected, apply it, then hand the
     * graphic and its box to the drawer callback. */
    struct State { u32 a[12]; f32 x, y, z; } transform;
    u32 *src = (u32 *)fn_8022EDC4();
    s32 selected = 0;
    CopyMatrix_8021AA18(transform.a, src);
    CopyVector_8021AA18(transform.a + 9, src + 9);
    transform.x = ((f32 *)src)[12];
    transform.y = ((f32 *)src)[13];
    transform.z = ((f32 *)src)[14];
    struct Callback { virtual void first(); virtual void call(s32, s32, s32, s32, s32, s32); };
    u8 *p = (u8 *)widget;
    s32 *cursor = *(s32 **)(p + 0x254);
    if (cursor && *cursor == *(s32 *)(p + 0x258)) selected = 1;
    if (((u8 *)fn_80216708())[0] == 0 && selected == 0) transform.x *= lbl_805634E8;
    fn_8022ED00((s32 *)&transform);
    s32 height;
    s32 boxSpan;
    s32 width;
    boxSpan = *(s32 *)(p + 0x10) - *(s32 *)(p + 8);
    height = ((VfObj *)widget)->vf32();
    width = ((VfObj *)widget)->vf28();
    ((Callback *)*(void **)(p + 0x244))->call(
        *(s32 *)(p + 0x248), *(s32 *)(p + 0x24C), *(s32 *)(p + 0x250), width, boxSpan, height);
    fn_8022EDB8();
}
#pragma dont_inline reset
/* Reports a default value of 0 for the cursor-icon widget code: takes no
 * input and has no side effects. */
extern "C" s32 fn_8021AB88(void) { return 0; }

/* The cursor-icon widget's own key handling defers to its owning menu group
 * (stored at widget+0x2C): step the selection back to the previous widget on UP
 * and forward to the next on DOWN; every other message goes to the base
 * widget's handler. */
#define SelectPrevWidget fn_80217AC0
#define SelectNextWidget fn_802179A0
#define BaseOnMessage fn_802192A4

#pragma push
#pragma scheduling invalid_target
/* Cursor-icon widget message handler.  While the UI mode byte is set, the UP
 * key steps the owning menu group's selection back to the previous widget and
 * the DOWN key forward to the next; the RIGHT key, the key past DOWN and every
 * other message (or the UI mode being clear) fall through to the base widget's
 * handler.  Returns 1 when the key was used. */
extern "C" s32 fn_8021AB90(void *widget, s32 message) {
    if (*(u8 *)fn_80216708() == 0)
        goto fallback;
    if (message == MENU_KEY_RIGHT)
        goto fallback;
    if (message >= MENU_KEY_RIGHT)
        goto checkUpper;
    if (message < MENU_KEY_UP)
        goto fallback;
    goto callLower;
checkUpper:
    if (message < MENU_KEY_DOWN + 1)
        goto callUpper;
    goto fallback;
callLower:
    SelectPrevWidget(*(s32 *)((u8 *)widget + 0x2C));
    return 1;
callUpper:
    SelectNextWidget(*(s32 *)((u8 *)widget + 0x2C));
    return 1;
fallback:
    return BaseOnMessage(widget, message);
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

extern "C" void fn_8021ACC0(void *widget, s32 value) {
    /* Stores a value and queries the widget's image/resource handle count. */
    fn_802C3034(value);
    fn_802C51AC(*(s32 *)((u8 *)widget + 0x250));
    if (fn_802C51AC(*(s32 *)((u8 *)widget + 0x250)) > 0)
        fn_802C51AC(*(s32 *)((u8 *)widget + 0x250));
}

#pragma push
#pragma scheduling invalid_target
/* Draw an animated image widget: pick a frame index from its state flags, wrap
 * it to the image's frame count, then draw centred on the screen at its position. */
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

    screenX = *(s32 *)((u8 *)arg0 + 4) - lbl_8055FB9C / 2;
    screenY = lbl_8055FBA0 / 2 - *(s32 *)((u8 *)arg0 + 8);

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
extern "C" void *fn_8021AF0C(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 x, f32 y) {
    fn_8021AC24(obj, a1, a2, a6, a4);
    *(s32 *)((u8 *)obj + 0x254) = a3;
    *(void **)obj = lbl_8033F658;
    *(f32 *)((u8 *)obj + 0x258) = x;
    *(f32 *)((u8 *)obj + 0x25C) = y;
    *(s32 *)((u8 *)obj + 0x260) = a4;
    *(s32 *)((u8 *)obj + 0x264) = a5;
    return obj;
}
#pragma dont_inline reset
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021AF9C(void *self, int shouldDelete) {
    /* Scalar deleting destructor: destroy contents, then free this object when requested. */
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
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
/* Initialize a UI object that steps/clamps an integer value: set up the base
   widget state, install this type's vtable, and store the value pointer, range
   bounds, and step amount. */
extern "C" void *fn_8021B0CC(void *obj, s32 x, s32 y, s32 valuePtr, s32 rangeMin, s32 rangeMax, s32 step, s32 resourceId, s32 unused) {
    fn_8021AC24(obj, x, y, resourceId, rangeMin);
    *(void **)obj = lbl_8033F5D0;
    *(s32 *)((u8 *)obj + 0x254) = valuePtr;
    *(s32 *)((u8 *)obj + 0x258) = rangeMin;
    *(s32 *)((u8 *)obj + 0x25C) = rangeMax;
    *(s32 *)((u8 *)obj + 0x260) = step;
    return obj;
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
    u32 t = __cntlzw(end - start - 2);
    s32 *check = *(s32 **)((u8 *)arg0 + 0x254);
    s32 end2 = *(s32 *)((u8 *)arg0 + 0x25C);
    int flag = t >> 5;
    if (*check >= end2) {
        if (flag)
            *check = *(s32 *)((u8 *)arg0 + 0x258);
        else
            *check = end2 - 1;
    }
    {
        s32 *check2 = *(s32 **)((u8 *)arg0 + 0x254);
        s32 start2 = *(s32 *)((u8 *)arg0 + 0x258);
        if (*check2 < start2) {
            if (flag)
                *check2 = *(s32 *)((u8 *)arg0 + 0x25C) - 1;
            else
                *check2 = start2;
        }
    }
}
#pragma scheduling on
#pragma pop
/* Initializes this widget with a base image widget, sets its vtable, and stores the range and output pointers. */
extern "C" void *fn_8021B1C4(void *widget, s32 x, s32 y, s32 outputPtr, s32 rangeMin, s32 resourceId) {
    void *vtable;

    fn_8021AC24(widget, x, y, resourceId, rangeMin);
    vtable = lbl_8033F548;
    *(s32 *)((u8 *)widget + 0x254) = rangeMin;
    *(void **)widget = vtable;
    *(s32 *)((u8 *)widget + 0x258) = outputPtr;
    return widget;
}
#pragma dont_inline reset

extern "C" char lbl_8033F20C[];
/* Steps the state object's clamped index (+8) up or down by 1 based on the direction flag at +0x254. */
extern "C" void fn_8021B224(void *obj) {
    s32 limit;
    s32 count;
    s32 limit2;
    s32 count2;
    void *state;
    void *state2;
    if (*(s32 *)((u8 *)obj + 0x254) == 1) {
        state = *(void **)((u8 *)obj + 0x258);
        count = *(s32 *)((u8 *)state + 8) + 1;
        *(s32 *)((u8 *)state + 8) = count;
        limit = *(s32 *)state - *(s32 *)((u8 *)state + 4);
        if (count > limit)
            *(s32 *)((u8 *)state + 8) = limit;
        if (*(s32 *)((u8 *)state + 8) < 0)
            *(s32 *)((u8 *)state + 8) = 0;
    } else {
        state2 = *(void **)((u8 *)obj + 0x258);
        count2 = *(s32 *)((u8 *)state2 + 8) - 1;
        *(s32 *)((u8 *)state2 + 8) = count2;
        limit2 = *(s32 *)state2 - *(s32 *)((u8 *)state2 + 4);
        if (count2 > limit2)
            *(s32 *)((u8 *)state2 + 8) = limit2;
        if (*(s32 *)((u8 *)state2 + 8) < 0)
            *(s32 *)((u8 *)state2 + 8) = 0;
    }
}

#pragma dont_inline fn_80219568
/* Constructs a dynamic text label widget: initializes the base label at (x, y), binds the watched string pointer (+0x254) and caches its initial text (+0x268), stores the state pointer (+0x264), and computes the text bounds. */
extern "C" void *fn_8021B2B0(void *widget, s32 x, s32 y, const char *textPtr, s32 fontId, s32 statePtr, s32 align) {
#define UILabel_InitBase fn_80219568
#define UILabel_UpdateBounds fn_80219718
#define gDynamicLabelVtable lbl_8033F20C
    ((void *(*)(void *, s32, s32, s32, s32, s32, s32))UILabel_InitBase)(widget, x, y, align, fontId, 0, 0);
    *(s32 *)((u8 *)widget + 0x254) = (s32)textPtr;
    *(void **)widget = gDynamicLabelVtable;
    strcpy((char *)widget + 0x268, textPtr);
    *(s32 *)((u8 *)widget + 0x264) = statePtr;
    UILabel_UpdateBounds(widget);
    return widget;
#undef gDynamicLabelVtable
#undef UILabel_UpdateBounds
#undef UILabel_InitBase
}
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_8021B32C(void *widget) {
    /* Refresh a dynamic text label: if the watched string changed, copy it into the cache, recompute bounds, and mark dirty when active. */
    s32 textPtr;
    fn_802192AC(widget);
    textPtr = *(s32 *)((u8 *)widget + 0x254);
    if (strcmp((char *)textPtr, (char *)widget + 0x268) != 0) {
        strcpy((char *)widget + 0x268, (char *)textPtr);
        fn_80219718(widget);
        if (*(u8 *)((u8 *)widget + 0x1A) != 0) {
            *(u8 *)((u8 *)widget + 0x234) = 1;
        }
    }
}

#pragma dont_inline reset

/* Return the int bound to this object at +0x264, or 0 when no value is bound. */
extern "C" s32 fn_8021B3A0(void *widget) {
    s32 *valuePtr = *(s32 **)((u8 *)widget + 0x264);
    if (valuePtr != 0) return *valuePtr;
    return 0;
}

extern "C" s32 fn_802C3424(s32, s32, s32, s32, s32);
/* Set the canvas state, then draw the object's stored rectangle. */
extern "C" void fn_8021B3BC(void *object, s32 canvasState) {
    fn_802C3034(canvasState);
    fn_802C3424(*(s32 *)((u8 *)object + 0x244), *(s32 *)((u8 *)object + 0x248), *(s32 *)((u8 *)object + 0x24C), *(s32 *)((u8 *)object + 0x250), *(s32 *)((u8 *)object + 0x254));
}

extern "C" s32 fn_80128668(void*);
/* DisposeCallbackManager destructor helper: if object is non-null, run base
 * destructor logic via fn_8021915C(object, 0), and if shouldDelete > 0, free it. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8021B404(
    void* object, s32 shouldDelete) {
    if (object) {
        if (object != NULL) {
            fn_8021915C(object, 0);
        }

        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

#pragma dont_inline on
extern "C" void *fn_8021B460(void *arg0, void *arg1, s32 arg2, s32 arg3) {
union Scratch { volatile u32 zeros[22]; u8 bytes[0x58]; } scratch;
f32 matrix[12];
volatile f32 matrix2[9];
volatile f32 vector[3];
f32 rot[3];
volatile f32 pad[3];
f32 transformed[3];
f32 vector2[3];
volatile f32 *input;
f32 *output;
s32 i, made;
f32 t5, t3, t6, t2, t0;
fn_8021B2B0(arg0, *(s32 *)((u8 *)arg1 + 8), *(s32 *)((u8 *)arg1 + 0xC),
(const char *)arg2, 8, arg3, *(s32 *)((u8 *)arg1 + 0x10));
*(void **)arg0 = (void *)&lbl_8033F180;
u8 *parms = scratch.bytes;
volatile u32 *zp = (volatile u32 *)(scratch.bytes - 4);
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
matrix[1]=lbl_805634A8;
matrix[0]=lbl_805634A4;
matrix[2]=lbl_805634A8; matrix[3]=lbl_805634A8;
matrix[4]=lbl_805634A4; matrix[5]=lbl_805634A8; matrix[6]=lbl_805634A8; matrix[7]=lbl_805634A8;
matrix[8]=lbl_805634A4; matrix[9]=lbl_805634A8; matrix[10]=lbl_805634A8; matrix[11]=lbl_805634A8;
t2=(f32)*(s32 *)((u8 *)arg1+8)-lbl_805634F0;
vector[0]=t2;
t0=lbl_805634F4-(f32)*(s32 *)((u8 *)arg1+0xC);
vector[1]=t0;
vector[2]=0.0f;
pad[0]=0.0f; pad[1]=0.0f; pad[2]=0.0f;
input=vector; output=transformed;
if (output == input) {
t5=t0*lbl_805634A8; t3=t2*lbl_805634A8; t6=vector[2]*lbl_805634A8;
output[0]=t6+((t2*lbl_805634A4)+t5);
output[1]=t6+(t3+(t0*lbl_805634A4));
output[2]=(vector[2]*lbl_805634A4)+(t3+t5);
} else {
t5=t0*lbl_805634A8; t3=t2*lbl_805634A8; t6=vector[2]*lbl_805634A8;
output[0]=t6+((t2*lbl_805634A4)+t5);
output[1]=t6+(t3+(t0*lbl_805634A4));
output[2]=(vector[2]*lbl_805634A4)+(t3+t5);
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
t2=-vector[0]; t0=-vector[1];
vector[0]=t2; vector[1]=t0;
t5=(f32)t0; t3=(f32)t2;
transformed[0]=matrix[0]*t3+matrix[3]*t5+matrix[6]*vector[2];
transformed[1]=matrix[1]*t3+matrix[4]*t5+matrix[7]*vector[2];
transformed[2]=matrix[2]*t3+matrix[5]*t5+matrix[8]*vector[2];
matrix[9]+=transformed[0]; matrix[10]+=transformed[1]; matrix[11]+=transformed[2];
*(s32 *)((u8 *)arg0+0x370)=((s32 (*)(f32 *,f32))fn_8022EDE4)(matrix,lbl_805634A4);
}
return arg0;
}

extern "C" void *fn_8021B8AC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        /* Destructor: reset vtable, free owned resources, run base cleanup, optionally delete. */
        void *ownedPtr = *(void **)((u8 *)arg0 + 0x370);
        *(void **)arg0 = lbl_8033F180;
        if (ownedPtr != 0) {
            fn_8022EE98(ownedPtr);
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
    /* If this object has a local UI transform, push it onto the draw-context stack, draw, then restore. */
    u8 localContext[0x40];
    if (*(void **)((u8 *)arg0 + 0x370) != 0) {
        fn_8022EEF8(localContext, (s32)*(void **)((u8 *)arg0 + 0x370), fn_8022EDC4());
        fn_8022ED00(localContext);
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
/* Destructor for a UI/object type: install its vtable, release owned resources, run base teardown, and optionally free the object. */
extern "C" void *fn_8021BBA0(void *object, s32 shouldDelete) {
    if (object != 0) {
        *(void **)object = lbl_8033F0FC;
        fn_8022A8E4(*(s32 *)((u8 *)object + 0x244));
        {
            void *ownedPtr = *(void **)((u8 *)object + 0x258);
            if (ownedPtr != 0) {
                fn_802C519C(ownedPtr);
            }
        }
        fn_8021915C(object, 0);
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}
#pragma pop
extern "C" s32 fn_8022D850(void *, s32, s32, s32 *);
extern f32 lbl_805634FC;
 #pragma push
 #pragma scheduling 750
 extern "C" void fn_8021BC20(void *arg0, void *arg1) {
    s32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    void *temp_r4_2;
    register s32 temp_r4;
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
extern "C" void fn_8021BD48(void *widget, s32 textStyle) {
#define SetTextStyle fn_802C3034
#define DrawFormattedText fn_801E4BEC
    /* Draws this widget's label/text using its font, position, and string id/data field. */
    SetTextStyle(textStyle);
    ((void (*)(s32, ...))DrawFormattedText)(
        *(s32 *)((u8 *)widget + 0x348),
        0,
        9,
        *(s32 *)((u8 *)widget + 4),
        *(s32 *)((u8 *)widget + 8),
        *(s32 *)((u8 *)widget + 0x244)
    );
#undef SetTextStyle
#undef DrawFormattedText
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
/* Format the text readout widget's display string from its watched value
 * (value = *ptr@0x25C, formatted as offset@0x258 + value*scale@0x254 using
 * format@0x260 into buffer@0x264), normalize the buffer, refresh layout, and
 * mark it dirty if active (flag@0x1A / dirty@0x234). */
extern "C" void fn_8021BE48(void *widget) {
    f32 value = *(f32 *)*(void **)((u8 *)widget + 0x25C);
    volatile char *buf = (char *)widget + 0x264;
    sprintf((char *)buf,
            *(const char **)((u8 *)widget + 0x260),
            *(f32 *)((u8 *)widget + 0x258) +
                value * *(f32 *)((u8 *)widget + 0x254),
            value);
    fn_80130568((char *)widget + 0x264);
    fn_80219718(widget);
    if (*(u8 *)((u8 *)widget + 0x1A) != 0)
        *(u8 *)((u8 *)widget + 0x234) = 1;
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
/* When active, registers this widget's key/value pair and caches the resulting handle. */
extern "C" void fn_8021BF90(void *widget) {
    void *handle;
    if (fn_80129BC4() != 0) {
        handle = fn_80217BD8(*(s32 *)((u8 *)widget + 0x2C),
                             *(s32 *)((u8 *)widget + 0x2AC), widget);
        *(void **)((u8 *)widget + 0x2A8) = handle;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(widget, 1, handle, 4);
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
    /* Invoke a virtual method on the object at +0x2A4 for the buffer at +0x254, refresh layout, and flag when active (+0x1A). */
    class Local {
    public:
        virtual void a0();
        virtual void a1();
        virtual void apply(void *, s32);
    };
    void *object = *(void **)((u8 *)arg0 + 0x2A4);
    ((Local *)object)->apply((u8 *)arg0 + 0x254, 0x50);
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
/* Status query: 0 if no status pointer is set, otherwise 1 when the pointed-to status equals the +0x2AC expected value. */
extern "C" s32 fn_8021C318(void *widget) {
    s32 *statusPtr = *(s32 **)((u8 *)widget + 0x2A8);
    if (statusPtr == 0) return 0;
    return *statusPtr == *(s32 *)((u8 *)widget + 0x2AC);
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

/* If active (fn_80129BC4), inserts the pair (field +0x2C, field +0x2AC) for self
 * into the table via fn_80217BD8, stores the result at +0x2A8, and notifies via
 * fn_80219440 with tag 1 and size 4. */
extern "C" void fn_8021C478(void *self) {
    void *value;
    if (fn_80129BC4() != 0) {
        value = fn_80217BD8(*(s32 *)((u8 *)self + 0x2C),
                            *(s32 *)((u8 *)self + 0x2AC), self);
        *(void **)((u8 *)self + 0x2A8) = value;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(self, 1, value, 4);
    }
}

/* Update a scrollable text/list widget: notify the base, register a selection
 * rectangle for the current line based on its mode, then draw start/end
 * markers through the callback when the two line positions differ. */
extern "C" void fn_8021C4D4(void *widget) {
    register u8 *self = (u8 *)widget;
    s32 *statusPtr;
    s32 mode;
    s32 isActive;
    s32 markerActive;
    s32 handleA;
    s32 handleB;
    f32 posX;
    f32 posY;
    fn_80219660((void *)self);
    statusPtr = *(s32 **)(self + 0x2A8);
    isActive = 0;
    if (statusPtr != 0) {
        if (*statusPtr == *(s32 *)(self + 0x2AC))
            isActive = 1;
    }
    mode = *(s32 *)(self + 0x2CC);
    isActive = (s32)(((u32)((-isActive) | isActive)) >> 31);
    if (mode == 0 && *(s32 *)(self + 0x2C8) != 0) {
        ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32))fn_8022BAD0)(
            *(s32 *)(self + 0x2C4), *(s32 *)(self + 0x2BC),
            *(s32 *)(self + 0x2B8) - 3, 0, 0, 0,
            *(s32 *)(self + 0x2C8), isActive, 0.0f, 1);
    } else if (mode == 1 && *(s32 *)(self + 0x2C8) != 0) {
        ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32))fn_8022BAD0)(
            *(s32 *)(self + 0x2C4), *(s32 *)(self + 0x2C0),
            *(s32 *)(self + 0x2B8) - 3, 0, 0, 0,
            *(s32 *)(self + 0x2C8), isActive, 0.0f, 1);
    }
    if (*(s32 *)(self + 0x2B0) != *(s32 *)(self + 0x2B4) &&
        *(u8 *)(self + 0x2D0) != 0) {
        markerActive = 0;
        statusPtr = *(s32 **)(self + 0x2A8);
        if (statusPtr != 0 &&
            *(s32 *)(self + 0x2AC) == *statusPtr)
            markerActive = 1;
        handleA = fn_8021165C(0, 2);
        handleB = fn_8021165C(1, 2);
        posX = lbl_805634A8;
        posY = lbl_805634A8;
        fn_80230C30(&posX, &posY, *(s32 *)(self + 0x2B0), *(s32 *)(self + 0x2B8));
        if (((Fn8021C4D4VTable *)*(void **)(self + 0x2A4))->At20() != 0)
            fn_802C5310(handleA, markerActive, posX, posY, lbl_805634A8);
        fn_80230C30(&posX, &posY, *(s32 *)(self + 0x2B4), *(s32 *)(self + 0x2B8));
        if (((Fn8021C4D4VTable *)*(void **)(self + 0x2A4))->At1C() != 0)
            fn_802C5310(handleB, markerActive, posX, posY, lbl_805634A8);
    }
}

extern "C" void fn_8021C6D0(void *);
extern "C" void fn_8022EE98(void *);
extern "C" void *lbl_8033E248[];
extern "C" u8 lbl_8033E0BC[];
extern "C" void fn_8021C6CC(void) { ((void (*)())fn_8021C6D0)(); }

extern "C" void fn_8021C6D0(void *arg0) {
    /* Invoke a virtual method on the object at +0x2A4 for the buffer at +0x254, refresh layout, and flag when active (+0x1A). */
    class Local {
    public:
        virtual void vf0();
        virtual void vf4();
        virtual void apply(void *target, s32 value);
    };
    void *object = *(void **)((u8 *)arg0 + 0x2A4);
    ((Local *)object)->apply((u8 *)arg0 + 0x254, 0x50);
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
/* Default no-op handler for this menu object: returns 0 (nothing handled /
   no value).  Neighbouring menu-item handlers return 1 when they consume a
   key; this stub is the zero-returning default. */
extern "C" s32 fn_8021C974(void) { return 0; }

extern "C" void *fn_8021C97C(void *obj, s32 arg1, s32 arg2, s32 arg3, s32 value258, s32 value254)
{
    /* Constructor/init: initializes base via fn_8021AC24, stores value258 at +0x258,
     * installs vtable lbl_8033EDC8, stores value254 at +0x254, and returns obj. */
    fn_8021AC24(obj, arg1, arg2, arg3, value258);
    *(s32 *)((u8 *)obj + 0x258) = value258;
    *(void **)obj = lbl_8033EDC8;
    *(s32 *)((u8 *)obj + 0x254) = value254;
    return (void *)((char *)obj + 0);
}

extern "C" void fn_8021C9D8(void *item) {
    /* Call First() on the +0x254 helper when the +0x258 count is positive, otherwise Second(). */
    if (*(s32 *)((u8 *)item + 0x258) > 0) {
        (*(Fn8021C9D8Object **)((u8 *)item + 0x254))->First();
    } else {
        (*(Fn8021C9D8Object **)((u8 *)item + 0x254))->Second();
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
/* Deleting destructor of the slider/tab widget fn_8021CA0C builds: restore its vtable,
 * release the two images it loaded, run the base Widget destructor and, when the deleting
 * flag is set (scalar deleting destructor), free the object itself. */
extern "C" void *fn_8021CAD4(void *self, s32 deletingFlag) {
    /* The slider/tab widget fn_8021CA0C builds into a 0x25C-byte UI node. */
    struct SliderWidget {
        void *vtable;      /* +0x000 */
        u8 widget[0x240];  /* +0x004 base Widget state */
        u8 flag;           /* +0x244 cleared by fn_8021CA0C */
        u8 pad_0x245[3];   /* +0x245 */
        void *resource;    /* +0x248 image resource the widget size comes from */
        void *sliderImage; /* +0x24C HGSlider.img */
        void *tabImage;    /* +0x250 HGTab.img */
    };
    #define Slider_vtable lbl_8033ED44
    #define Image_release fn_802C519C

    if (self != NULL) {
        ((SliderWidget *)self)->vtable = Slider_vtable;
        Image_release(((SliderWidget *)self)->sliderImage);
        Image_release(((SliderWidget *)self)->tabImage);
        Widget_dtor(self, 0);
        if (deletingFlag > 0) {
            Mem_freeObject(self);
        }
    }

    #undef Slider_vtable
    #undef Image_release
    return self;
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
/* Draw a slider/tab widget: draw its track at the widget's screen-centred
 * position, then offset the tab by scrollRate * (current value - base value)
 * and draw it there.  The integer scratch registers hold the centred screen
 * position first, then the tab's screen position. */
extern "C" void fn_8021CBBC(void *widget) {
    register s32 screenX;
    register s32 screenY;
    f32 drawX;
    f32 drawY;
    register f32 scrollRate;
    screenX = *(s32 *)((u8 *)widget + 4) - lbl_8055FB9C / 2;
    drawX = (f32)screenX;
    screenY = lbl_8055FBA0 / 2 - *(s32 *)((u8 *)widget + 8);
    drawY = (f32)screenY;
    fn_802C5310(*(s32 *)((u8 *)widget + 0x24C), 0,
                drawX, drawY - 8.0f, 0.0f);
    scrollRate = (*(V24x **)((u8 *)widget + 0x248))->get();
    screenX = ((VfObj *)widget)->vf28();
    screenY = *(s32 *)((u8 *)widget + 0x254);
    screenX = (s32)(scrollRate * (f32)(screenX - screenY));
    fn_80230C30(&drawX, &drawY,
                screenX + *(s32 *)((u8 *)widget + 4),
                3 + *(s32 *)((u8 *)widget + 8));
    fn_802C5310(*(s32 *)((u8 *)widget + 0x250), 0, drawX, drawY, 0.0f);
}

#pragma push
#pragma scheduling invalid_target
/* Drive a slider widget from a screen point.  The first time it is called the
 * widget caches the value its target object (+0x248) holds; a point outside the
 * widget's box (its left/top/width/bottom grown by 32 pixels) puts that cached
 * value back, and a point on the box sets the target to where the point sits
 * along the tab's travel -- (x - left - tabSize/2) / (width - tabSize), clamped
 * to [0,1] -- so dragging across the slider scrubs the value. */
extern "C" void fn_8021CD04(void *widget, s32 x, s32 y) {
    #define FLOAT_ONE  lbl_805634A4 /* 1.0f: the slider's far end */
    #define FLOAT_ZERO lbl_805634A8 /* 0.0f: its near end */
    /* The value this slider drives (+0x248): get() at vtable +0x24, set() at
     * +0x28.  V24x is the project's name for the class up to get(). */
    class SliderValue : public V24x {
    public:
        virtual void set(f32);
    };
    u8 *self = (u8 *)widget;
    if (self[0x244] == 0) {
        /* First pass: keep hold of the value the slider had before it was moved. */
        self[0x244] = 1;
        SliderValue *value = *(SliderValue **)(self + 0x248);
        *(f32 *)(self + 0x258) = value->get();
    }
    s32 left = *(s32 *)(self + 4);
    if (x < left - 0x20 ||
        y < *(s32 *)(self + 8) - 0x20 ||
        x > left + ((VfObj *)widget)->vf28() + 0x20 ||
        y > *(s32 *)(self + 0x10) + 0x20) {
        /* The point is off the slider (its box grown by 32 pixels): put the
         * value back the way it was. */
        SliderValue *value = *(SliderValue **)(self + 0x248);
        value->set(*(f32 *)(self + 0x258));
        return;
    }
    /* On the slider: where the point sits along the track the tab can travel,
     * measured from the tab's centre, becomes the new value in [0,1]. */
    left = *(s32 *)(self + 4);
    s32 tabSize = *(s32 *)(self + 0x254);
    s32 trackWidth = ((VfObj *)widget)->vf28();
    f32 clamped = FLOAT_ONE;
    s32 travel = trackWidth - tabSize;
    s32 offset = x - left - tabSize / 2;
    f32 fTravel = (f32)travel;
    f32 fOffset = (f32)offset;
    f32 fraction = fOffset / fTravel;
    clamped = (clamped < fraction) ? clamped : fraction;    /* MIN(1.0f, fraction) */
    clamped = (clamped > FLOAT_ZERO) ? clamped : FLOAT_ZERO; /* MAX(fraction, 0.0f) */
    SliderValue *value = *(SliderValue **)(self + 0x248);
    value->set(clamped);
    #undef FLOAT_ONE
    #undef FLOAT_ZERO
}
#pragma pop
extern "C" void fn_8021CE8C(void *widget) {
    /* If this widget has a pending update (+0x244), run its vf13() handler. */
    if (*(u8 *)((u8 *)widget + 0x244) != 0)
        ((VfObj *)widget)->vf13();
}

extern "C" void fn_8021CEAC(void *self) {
    /* Runs this widget's vf17() update, then clears its pending flag (+0x244). */
    struct PendingWidget {
        VfObj obj;          /* 0x00: vtable */
        u8 pad_0x4[0x240];
        u8 pending;         /* 0x244: set while an update is pending */
    };
    PendingWidget *widget = (PendingWidget *)self;

    widget->obj.vf17();
    widget->pending = 0;
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

extern "C" void fn_8021D154(void *widget) {
    void *entry;

    /* If enabled, register (+0x2C0, +0x2C) and cache the returned entry at +0x2BC, then notify (tag 1, size 4). */
    if (fn_80129BC4() != 0) {
        entry = fn_80217BD8(*(s32 *)((u8 *)widget + 0x2C),
                            *(s32 *)((u8 *)widget + 0x2C0), widget);
        *(void **)((u8 *)widget + 0x2BC) = entry;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(widget, 1, entry, 4);
    }
}

extern "C" s32 fn_8021D1B0(void *widget) {
    /* Status query: 0 if no status pointer is set, 4 if the +0x1B flag is clear,
     * otherwise 1 when the pointed-to status equals the +0x2C0 expected value. */
    s32 *statusPtr = *(s32 **)((u8 *)widget + 0x2BC);
    if (statusPtr == 0)
        return 0;
    if (*(u8 *)((u8 *)widget + 0x1B) != 0)
        return *statusPtr == *(s32 *)((u8 *)widget + 0x2C0);
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

/* Destructor of the option widget fn_8021D044 builds (its vtable lbl_8033EBA0):
 * hand the object back its base-widget vtable, free the table of option strings
 * it was given at +0x2B8, run the base Widget destructor and then free the
 * object itself when shouldDelete > 0.  The derived-class part is already gone
 * by here, which is why the base destructor is called with 0 and the freeing is
 * done by hand. */
extern "C" void *fn_8021D300(void *self, s32 shouldDelete) {
    if (self != 0) {
        *(void **)self = lbl_8033EBA0; /* back to the base widget's vtable */
        fn_80128670(*(s32 *)((u8 *)self + 0x2B8)); /* the option strings */
        if (self != 0)
            Widget_dtor(self, 0);
        if (shouldDelete > 0)
            Mem_freeObject(self);
    }
    return self;
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

extern "C" void fn_8021D61C(void *self) {
    /* Copies the currently selected option string into self+0x268 (or "???" if out of range), refreshes layout, and sets a dirty flag. */
    s32 index = *(s32 *)*(s32 **)((u8 *)self + 0x254);
    if (index >= 0 && index < *(s32 *)((u8 *)self + 0x258)) {
        strcpy((char *)self + 0x268,
               *(char **)(*(s32 *)((u8 *)self + 0x2B8) + index * 4));
    } else {
        strcpy((char *)self + 0x268, (char *)&lbl_8055B87C);
    }
    fn_80219718(self);
    if (*(u8 *)((u8 *)self + 0x1A) != 0)
        *(u8 *)((u8 *)self + 0x234) = 1;
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

extern "C" void *__dt__Q34Game10MemoryCard8ResourceFv(void *self, s32 shouldDelete) {
    /* Deleting destructor: restore the vtable, release the resource slot at +0x2C4, run the base destructor, and optionally delete. */
    if (self != 0) {
        *(void **)self = lbl_8033EB14;
        fn_8022A8E4(*(s32 *)((u8 *)self + 0x2C4));
        fn_8021D300(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
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

extern "C" void fn_8021D864(void *widget) {
    /* Forward the sixth virtual method (vtable slot at +0x1C) to the polymorphic
       helper object bound at +0x254 of this UI widget. */
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
    ClassB *helper = *(ClassB **)((u8 *)widget + 0x254);
    helper->v5();
}

extern "C" void fn_8021D878(void *widget) {
    /* If enabled, register (+0x25C, +0x2C) and cache the returned entry at +0x258, then notify (tag 1, size 4). */
    void *entry;
    if (fn_80129BC4() != 0) {
        entry = fn_80217BD8(*(s32 *)((u8 *)widget + 0x2C), *(s32 *)((u8 *)widget + 0x25C), widget);
        *(void **)((u8 *)widget + 0x258) = entry;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(widget, 1, entry, 4);
    }
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
    /* Handle a menu/navigation input for this object: verify its bound resource state,
     * then process command ids (0x125/0x127 trigger actions and stamp fn_8023659C time,
     * 0x126/0x128 navigate the parent list at +0x2C when allowed), returning 1 if handled. */
    struct BaseA {
        int a, b, c;
    };
    struct ClassB : public BaseA {
        virtual s32 v0();
        virtual void v1();
        virtual s32 v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual s32 v8();
        virtual s32 v9();
    };

    if ((*(ClassB **)((u8 *)arg0 + 0x254))->v0() != 0) {
        if ((*(ClassB **)((u8 *)arg0 + 0x254))->v2() == 0)
            return 0;
    } else {
        s32 *p = *(s32 **)((u8 *)arg0 + 0x258);
        if (p == 0)
            return 0;
        if (*(s32 *)((u8 *)arg0 + 0x25C) != *p)
            return 0;
    }

    switch (arg1) {
    case 0x127:
        if ((*(ClassB **)((u8 *)arg0 + 0x254))->v9() != 0) {
            (*(ClassB **)((u8 *)arg0 + 0x254))->v7();
            *(f32 *)((u8 *)arg0 + 0x264) = fn_8023659C();
        } else {
            fn_80216D28();
        }
        return 1;

    case 0x125:
        if ((*(ClassB **)((u8 *)arg0 + 0x254))->v8() != 0) {
            (*(ClassB **)((u8 *)arg0 + 0x254))->v6();
            *(f32 *)((u8 *)arg0 + 0x260) = fn_8023659C();
        } else {
            fn_80216D28();
        }
        return 1;

    case 0x126:
        if ((*(ClassB **)((u8 *)arg0 + 0x254))->v0() == 0 && *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
            return 1;
        }
        break;

    case 0x128:
        if ((*(ClassB **)((u8 *)arg0 + 0x254))->v0() == 0 && *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C));
            fn_80230E90(0);
            return 1;
        }
        break;

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
    s32 *temp_r4_3 = 0;
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
            void *dst = *(void **)((u8 *)arg0 + 0x25C);
            *(s32 *)dst = var_r5;
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
        if (**(s32 **)((u8 *)arg0 + 0x25C) > 0)
            (**(s32 **)((u8 *)arg0 + 0x25C))--;
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x122: {
        s32 *p = *(s32 **)((u8 *)arg0 + 0x25C);
        s32 v = *p + 1;
        if (v < *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x244) + 8))
            *p = v;
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
        register s32 sum = st + rg1;
        if (lim < sum) {
            sum = lim;
            *statePtr = sum;
        }
        {
            s32 *range = *(s32 **)((u8 *)arg0 + 0x248);
            range[2] += range[1];
            if (range[2] > range[0] - range[1])
                range[2] = range[0] - range[1];
            if (range[2] < 0)
                range[2] = 0;
        }
        fn_8021E7D4(arg0);
        return 1;
    }
    case 0x124: {
        s32 *p = *(s32 **)((u8 *)arg0 + 0x25C);
        s32 st = *p;
        s32 rg1 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x248) + 4);
        s32 v = st - rg1;
        *p = v & ~(v >> 31);
        {
            s32 *range = *(s32 **)((u8 *)arg0 + 0x248);
            range[2] -= range[1];
            if (range[2] > range[0] - range[1])
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

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021E884(void *this_, int flag) {
    /* nw4hbm::snd::MemorySoundArchive scalar-deleting destructor (8021E884):
       if non-null, run the base destructor fn_8021915C(this_, 0), then free
       storage with the deleting operator fn_80128668 when flag > 0. Returns
       this_. (Mirrors __dt__...Fv_80111BB8 but with base fn_8021915C.) */
    if (this_ != 0) {
        fn_8021915C(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
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
/* Destructor-like cleanup: install this object's vtable, release resources at
   offsets 0xA5C and 0xA60, run base cleanup, and optionally free the object. */
extern "C" void *fn_8021EB9C(void *self, s32 deletingFlag) {
    if (self != 0) {
        *(void **)self = lbl_8033E988;
        fn_802C519C(*(void **)((u8 *)self + 0xA5C));
        if (*(void **)((u8 *)self + 0xA60) != 0)
            fn_802C519C(*(void **)((u8 *)self + 0xA60));
        fn_8021915C(self, 0);
        if (deletingFlag > 0)
            fn_80128668(self);
    }
    return self;
}

extern "C" void fn_802C2FC8(s32, s32, s32, s32, s32);
extern "C" void fn_80228DC4(s32, s32, s32, s32, s32, s32);
extern "C" void fn_8022B390(s32, s32, s32, s32*, s32*);
extern "C" void fn_802C47B8(s32, s32, s32, s32, s32, s32);
extern "C" void fn_802C3014(s32);
extern "C" s32 lbl_8055FBF8;
// Renders entity onto canvas: sets the canvas clip rect from the entity's position and vtable size,
// runs its per-frame hook and optional marker, then draws its textured quad when flag 0x19 is set.
extern "C" void fn_8021EC1C(void* entity, s32 canvas) {
    s32 outX, outY;
    s32 posY, posX, posX_2, posY_2, posX_3, posY_3, drawX, drawY;
    fn_802C3034(canvas);
    posX = *(s32*)((u8*)entity+4);
    posY = *(s32*)((u8*)entity+8);
    fn_802C2FC8(canvas, posX, posY, posX + ((Vf78*)entity)->get(), *(s32*)((u8*)entity+0x10));
    ((void(*)(void*,s32))fn_802192A0)(entity,canvas);
    if (*(s32*)((u8*)entity+0xA60)) {
        posY_2 = *(s32*)((u8*)entity+8);
        posX_2 = *(s32*)((u8*)entity+4);
        fn_80228DC4(canvas, *(s32*)((u8*)entity+0xA60), posX_2, posY_2, ((Vf78*)entity)->get(), 0);
    }
    posX_3 = *(s32*)((u8*)entity+4);
    posY_3 = *(s32*)((u8*)entity+8);
    fn_802C2FC8(canvas, posX_3, posY_3, posX_3 + ((Vf78*)entity)->get(), *(s32*)((u8*)entity+0x10));
    fn_8022B91C(*(s32*)((u8*)entity+0xA58),*(s32*)((u8*)entity+4),*(s32*)((u8*)entity+8),*(s32*)((u8*)entity+0xA54),(*(u8*)((u8*)entity+0x19)!=0));
    if (*(u8*)((u8*)entity+0x19)) {
        fn_8022B390(*(s32*)((u8*)entity+0xA58),*(s32*)((u8*)entity+0xA54),*(s32*)((u8*)entity+0x250),&outX,&outY);
        drawY = outY + *(s32*)((u8*)entity+8);
        drawX = outX + *(s32*)((u8*)entity+4);
        ((void(*)(s32,s32,s32,s32,s32))fn_802C47B8)(drawX,drawY+2,drawX,drawY+0xC,lbl_8055FBF8);
    }
    fn_802C3014(canvas);
}

#pragma push
#pragma processor 750
/* Draws one text box on the canvas being drawn on: first its "slider.img"
 * graphic, stretched to the box' width (a single-row box only, the field is 0
 * otherwise), then its text in the box' UI style, and finally the caret - a
 * one-pixel-wide 0xFFFFFF00 bar at the x the text reaches when cut at the caret
 * index.  Nothing is drawn at the box' own coordinates: +0x04/+0x08 count from
 * the middle of the screen with y upwards, so every position goes through the
 * same centring before fn_802C5320/fn_8022BAD0/fn_80230924 see it.  No code
 * calls this; it is reached through the object' vtable. */
extern "C" void fn_8021EDA4(void *self) {
    /* The text box being drawn; only the fields used here are named. */
    struct TextBox {
        void *vtable;                /* 0x00; the virtual at 0x78 is the width */
        s32 x;                       /* 0x04 left, from the screen centre */
        s32 y;                       /* 0x08 top, from the screen centre */
        u8 pad0C[0x19 - 0x0C];
        u8 showCaret;                /* 0x19: the box is being edited */
        u8 pad1A[0x250 - 0x1A];
        s32 caretIndex;              /* 0x250 character the caret stands before */
        u8 pad254[0xA54 - 0x254];
        char *text;                  /* 0xA54 the string shown */
        s32 style;                   /* 0xA58 UI style index, see fn_8022CA2C */
        u8 padA5C[4];                /* 0xA5C the "ibeam.img" cursor graphic */
        s32 sliderArt;               /* 0xA60 "slider.img", single-row boxes */
    };
    TextBox *box = (TextBox *)self;
    char caretText[256]; /* the box' text, cut where the caret stands */
    if (box->sliderArt) {
        f32 height, x, y;
        x = (f32)(box->x - lbl_8055FB9C / 2);
        y = (f32)(lbl_8055FBA0 / 2 - box->y);
        height = (f32)fn_802C5220(box->sliderArt);
        f32 width = (f32)((Vf78 *)self)->get();
        fn_802C5320(box->sliderArt, 0, x, y, lbl_805634A8, width, height);
    }
    s32 zero = 0;
    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32, f32))fn_8022BAD0)(
        box->style, box->x, box->y,
        0, 0, 0, (s32)box->text, box->showCaret != 0,
        zero, 1.0f);
    if (box->showCaret) {
        f32 x = (f32)(box->x - lbl_8055FB9C / 2);
        f32 y = (f32)(lbl_8055FBA0 / 2 - box->y);
        strcpy(caretText, box->text);
        if (box->caretIndex >= 0) caretText[box->caretIndex] = zero;
        x += (f32)fn_8022B498(box->style, (s32)caretText);
        f32 height = (f32)fn_8022B620(box->style, caretText);
        ((void (*)(s32,f32,f32,f32,f32,f32))fn_80230924)(-0x100, x, y - lbl_80563514, lbl_805634A4 + x, lbl_80563514 + (y - height), lbl_805634A8);
    }
}

#pragma pop

extern "C" void fn_8021EFE0(void *self, s32 x, s32 y) {
    /* Set the text caret index (at +0x250) to the character position nearest the given point,
     * computed relative to this object's position, and mark it dirty if it is active. */
    s32 dx = x - *(s32 *)((u8 *)self + 4);
    s32 dy = y - *(s32 *)((u8 *)self + 8);
    *(s32 *)((u8 *)self + 0x250) = ((s32 (*)(s32, s32, s32, s32))fn_8022B2D4)(
        *(s32 *)((u8 *)self + 0xA58), *(s32 *)((u8 *)self + 0xA54), dx, dy);
    if (*(u8 *)((u8 *)self + 0x1A) != 0)
        *(u8 *)((u8 *)self + 0x234) = 1;
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

/* Mark a text widget dirty when it is active, then forward a dispatch call
 * (code 0) through the widget's virtual table. */
extern "C" void fn_8021F044(void *widget) {
    if (((TextField *)widget)->active != 0)
        ((TextField *)widget)->dirty = 1;
    class Dispatch {
    public:
        virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03(); virtual void f04();
        virtual void f05(); virtual void f06(); virtual void f07(); virtual void f08(); virtual void f09();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22();
        virtual void DispatchCall(s32);
    };
    ((Dispatch *)widget)->DispatchCall(0);
}

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
/* A control the player can bind: which kind of input, from which of the four
   devices, and which key, button or axis of it.  The input-binding helpers of
   the text_801A75B4 unit look a descriptor like this up in the binding table,
   and write one when a bound control is triggered; the recovered prototypes
   above pass it as an int. */
typedef struct KeyBinding {
    s32 type;   /* 0x00 1 keyboard key, 2 pad axis, 3 pad byte, 4 pad button
                   mask, 5 pointer axis, 6 pointer button */
    s32 device; /* 0x04 device, 0..3 */
    s32 value;  /* 0x08 key code, or axis/button number */
    u8 flag;    /* 0x0C cleared by the poller */
} KeyBinding;
/* What the key-binding field of fn_8021F394 keeps while its dialog is open:
   the name the field shows, and the descriptor of the control that name was
   resolved from. */
typedef struct KeyPrompt {
    char name[0x18];     /* 0x00 display name of the bound control */
    KeyBinding *binding; /* 0x18 the control that name names */
} KeyPrompt;
#define gKeyPrompt       lbl_80490934 /* the KeyPrompt record above */
#define Input_Update     fn_801A7844  /* re-read the devices (1: reset them) and the pointer */
#define Input_NextKey    fn_801A7C8C  /* next triggered control -> its descriptor */
#define Input_KeyName    fn_801A7E54  /* descriptor -> display name */
#define KeyHistory_Clear fn_802E47E8  /* drop the typed-key history */
#pragma push
#pragma small_data off
extern "C" void *fn_8021F394(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    /* Initialize object, set vtable lbl_8033E8FC, store arg3/arg4, and prepare subdata. */
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
/* Refreshes the key-binding field's display name from its stored control id and marks it changed when active. */
extern "C" void fn_8021F42C(void *obj) {
    fn_801A7E54((u8 *)obj + 0x254, 0x18, *(s32 *)((u8 *)obj + 0x270));
    if (*(u8 *)((u8 *)obj + 0x1A) != 0)
        *(u8 *)((u8 *)obj + 0x234) = 1;
}

#pragma push
#pragma small_data off
/* While the key-binding field of fn_8021F394 has its dialog open, take the
   next control the player triggers: refresh the input state, ask the input
   bindings for one that is triggered (the poll writes it over the descriptor
   the staged binding points at), put that control's display name in the
   staging record, drop the typed-key history and hand back the dialog result
   -2, which tells the dialog its value changed.  Returns whether a control
   was taken. */
extern "C" s32 fn_8021F478(s32 *result) {
    KeyPrompt *prompt;

    Input_Update(1);
    prompt = (KeyPrompt *) gKeyPrompt;
    if (Input_NextKey((s32) prompt->binding) != 0) {
        Input_KeyName(prompt->name, 0x18, (s32) prompt->binding);
        KeyHistory_Clear();
        *result = -2;
        return 1;
    }
    return 0;
}
#pragma pop
extern "C" void fn_801A7A5C(void);
extern "C" s32 fn_802146BC(void *, s32, s32, s32, void *, s32, s32, s32);
extern "C" void fn_802194FC(void *);
#pragma use_lmw_stmw off
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
/* Horizontal slider widget (vtable lbl_8033E878, constructed by fn_8021F678). */
typedef struct SliderWidget {
    char pad000[0x244];
    u8 dragging;      /* 0x244 non-zero while the user is dragging the thumb */
    char pad245[3];
    f32 minValue;     /* 0x248 minimum slider value */
    f32 maxValue;     /* 0x24C maximum slider value */
    f32 *valuePtr;    /* 0x250 bound float value */
    s32 stepCount;    /* 0x254 number of discrete positions */
    u8 reversed;      /* 0x258 sign bit of stepCount argument */
    char pad259[3];
    s32 trackImg;     /* 0x25C "slider1.img" texture handle */
    s32 fillImg;      /* 0x260 fill/thumb texture handle */
    s32 trackX;       /* 0x264 track left X in pixels */
    s32 trackY;       /* 0x268 track top Y in pixels */
    s32 trackWidth;   /* 0x26C track width in pixels */
    s32 trackHeight;  /* 0x270 track height in pixels */
    s32 *cursorPtr;   /* 0x274 pointer to active menu cursor index */
    s32 cursorId;     /* 0x278 this widget's menu cursor id */
} SliderWidget;

enum {
    SLIDER_HIT_MARGIN = 0x14
};

extern "C" char lbl_8033D9B0[];
extern "C" char lbl_8033D9BC[];
#pragma push
#pragma scheduling on
extern "C" void *fn_8021F678(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg0, f32 farg1) {
    s32 *words = (s32 *)arg0;
    s32 end;
    s32 count;
    s32 len;
    fn_80218F34(arg0, arg1, arg2, arg1 + arg3, arg2 + arg4, 0);
    *(void **)arg0 = lbl_8033E878;
    words[0x250 / 4] = arg5;
    *(f32 *)((u8 *)arg0 + 0x248) = farg0;
    *(f32 *)((u8 *)arg0 + 0x24C) = farg1;
    *(u8 *)((u8 *)arg0 + 0x244) = 0;
    words[0x254 / 4] = ((arg6 >> 31) ^ arg6) - (arg6 >> 31);
    *(u8 *)((u8 *)arg0 + 0x258) = (u32)arg6 >> 31;
    words[0x25C / 4] = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9B0);
    words[0x260 / 4] = ((s32 (*)(void *))fn_802C5130)(lbl_8033D9BC);
    words[0x264 / 4] = words[1];
    words[0x268 / 4] = words[2];
    words[0x26C / 4] = ((Vf78 *)arg0)->get();
    len = words[2];
    end = words[4];
    words[0x270 / 4] = end - len;
    count = ((s32 (*)(s32))fn_802C5220)(words[0x25C / 4]);
    len = words[2];
    end = words[4];
    if (end - len > count) count = end - len;
    ((void (*)(void *, s32, s32))fn_80219284)(arg0, ((Vf78 *)arg0)->get() - 1, count);
    ((void (*)(void *, s32, void *, s32))fn_80219440)(arg0, 0, (void *)arg5, 4);
    words[0x274 / 4] = 0;
    words[0x278 / 4] = fn_80228F40(arg1, arg2);
    return arg0;
}
#pragma pop
/* Initialize this object's cached handle (+0x274) from table entry +0x278
 * under key +0x2C when fn_80129BC4() allows, then register it via fn_80219440
 * with tag 1 and size 4. */
extern "C" void fn_8021F7EC(void *object) {
    void *handle;

    if (fn_80129BC4() != 0) {
        handle = fn_80217BD8(*(s32 *)((u8 *)object + 0x2C),
                             *(s32 *)((u8 *)object + 0x278), object);
        *(void **)((u8 *)object + 0x274) = handle;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(object, 1, handle, 4);
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
    s32 span;
    s32 step;
    f32 high;
    f32 low;
    f32 range;
    f32 dist;
    f32 fraction;
    f32 result;

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
/* Returns whether cursor position (x, y) lies within the slider track's
   bounding box expanded by SLIDER_HIT_MARGIN (20 pixels) on each side. */
extern "C" s32 fn_8021FBC4(void *widget, s32 x, s32 y) {
    SliderWidget *slider = (SliderWidget *)widget;
    s32 trackX;
    s32 insideAll = 0;
    s32 insideTop = 0;
    s32 insideX = 0;
    trackX = slider->trackX;
    if ((x >= trackX - SLIDER_HIT_MARGIN) && (x < trackX + slider->trackWidth + SLIDER_HIT_MARGIN)) {
        insideX = 1;
    }
    if ((insideX != 0) && (y >= slider->trackY - SLIDER_HIT_MARGIN)) {
        insideTop = 1;
    }
    if ((insideTop != 0) && (y < slider->trackY + slider->trackHeight + SLIDER_HIT_MARGIN)) {
        insideAll = 1;
    }
    return insideAll;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8021FC40(void *arg0, s32 arg1) {
    s32 *temp_r5;
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;
    s32 var_r28;

    fn_802C3034(arg1);
    ((void (*)(void *, s32))fn_802192A0)(arg0, arg1);

    temp_r29 = (s32)(((f32)(((VfObj *)arg0)->vf28() - 11) *
        (**(f32 **)((u8 *)arg0 + 0x250) - *(f32 *)((u8 *)arg0 + 0x248))) /
        (*(f32 *)((u8 *)arg0 + 0x24C) - *(f32 *)((u8 *)arg0 + 0x248)));

    temp_r5 = *(s32 **)((u8 *)arg0 + 0x274);
    var_r28 = (temp_r5 != 0 && *temp_r5 == *(s32 *)((u8 *)arg0 + 0x278)) ? 1 : 0;
    if (var_r28) {
        temp_r31 = *(s32 *)((u8 *)arg0 + 8);
        temp_r30 = *(s32 *)((u8 *)arg0 + 4);
        fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x25C),
            temp_r30, temp_r31, ((VfObj *)arg0)->vf28(), var_r28);
    }

    fn_80228DC4(arg1, *(s32 *)((u8 *)arg0 + 0x260),
        *(s32 *)((u8 *)arg0 + 4) + 5, *(s32 *)((u8 *)arg0 + 8) + 5,
        temp_r29, var_r28);
}
#pragma pop
extern "C" s32 fn_802C5334(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
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
/* Construct a slider widget: set up base bounds and vtable, then store its type,
 * value range and per-step size, load the slider2.img handle, assign a packed cell
 * id, and cache the current time minus a fixed 0.3s offset. */
extern "C" void *fn_8021FF34(void *self, void *bounds, s32 type, s32 steps, f32 minValue, f32 maxValue) {
    f32 timeOffset;
    f32 range;
    s32 left;
    s32 top;
    top = *(s32 *)((u8 *)bounds + 0xC);
    left = *(s32 *)((u8 *)bounds + 8);
    fn_80218F34(self, left, top,
                left + *(s32 *)((u8 *)bounds + 0x14),
                top + *(s32 *)((u8 *)bounds + 0x18), 0);
    range = maxValue - minValue;
    *(void **)self = lbl_8033E7F4;
    *(s32 *)((u8 *)self + 0x244) = type;
    *(f32 *)((u8 *)self + 0x248) = minValue;
    *(f32 *)((u8 *)self + 0x24C) = maxValue;
    *(f32 *)((u8 *)self + 0x250) = range / (f32)steps;
    *(s32 *)((u8 *)self + 0x254) =
        ((s32 (*)(void *, void *))fn_802C5130)(lbl_8033D9BC, lbl_8033E7F4);
    *(s32 *)((u8 *)self + 0x258) = 0;
    *(s32 *)((u8 *)self + 0x25C) =
        fn_80228F40(*(s32 *)((u8 *)bounds + 8),
                    *(s32 *)((u8 *)bounds + 0xC));
    timeOffset = fn_8023659C() - lbl_805634E8;
    *(f32 *)((u8 *)self + 0x264) = timeOffset;
    *(f32 *)((u8 *)self + 0x260) = timeOffset;
    return self;
}
extern "C" u8 lbl_8033E7F4[];
/* Destroys a Game::MemoryCard::Resource instance and optionally frees its storage. */
extern "C" void* __dt__Q34Game10MemoryCard8ResourceFv_8022003C(void* self, s32 shouldDelete) {
    if (self != 0) {
        *(void**)self = lbl_8033E7F4;
        fn_802C519C(*(void**)((u8*)self + 0x254));
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
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
    s32 width = fn_802C51C0(*(s32 *)((u8 *)arg0 + 0x254));
    f32 adj = step - (f32)width;
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
    /* Key handler of the continuous-value slider built by fn_8021FF34 (vtable
     * lbl_8033E7F4). While its cached selection entry (+0x258) still matches the
     * id at +0x25C: LEFT/RIGHT step the value at *+0x244 by +0x250 within the
     * bounds +0x248/+0x24C and stamp the decrease/increase time at +0x260/+0x264
     * (the draw fn_802200AC fades the bar ends from it); UP/DOWN move the
     * selection in the parent list at +0x2C when it has several entries.
     * Returns 1 when the key was handled. */
    struct ValueSlider {
        u8 widget[0x244];   /* +0x000 base Widget state */
        f32 *value;         /* +0x244 value the slider steps */
        f32 minValue;       /* +0x248 lowest value */
        f32 maxValue;       /* +0x24C highest value */
        f32 step;           /* +0x250 range / steps */
        u32 barImage;       /* +0x254 bar image */
        s32 *entry;         /* +0x258 cached selection entry */
        s32 entryId;        /* +0x25C id the cached entry must still match */
        f32 decreaseTime;   /* +0x260 time LEFT last moved the value */
        f32 increaseTime;   /* +0x264 time RIGHT last moved the value */
    };
    s32 *entry;
    f32 *value;
    f32 bound;
    f32 result;
    s32 handled;
    entry = ((ValueSlider *)arg0)->entry;
    if (entry == 0 || *entry != ((ValueSlider *)arg0)->entryId)
        return 0;
    handled = 1;
    switch (arg1) {
    case MENU_KEY_RIGHT:
        value = ((ValueSlider *)arg0)->value;
        if (value != 0 && *value != ((ValueSlider *)arg0)->maxValue) {
            ((ValueSlider *)arg0)->increaseTime = fn_8023659C();
            value = ((ValueSlider *)arg0)->value;
            bound = ((ValueSlider *)arg0)->maxValue;
            result = *value + ((ValueSlider *)arg0)->step;
            result = result < bound ? result : bound;
            *value = result;
        }
        break;
    case MENU_KEY_LEFT:
        value = ((ValueSlider *)arg0)->value;
        if (value != 0 && *value != ((ValueSlider *)arg0)->minValue) {
            ((ValueSlider *)arg0)->decreaseTime = fn_8023659C();
            value = ((ValueSlider *)arg0)->value;
            bound = ((ValueSlider *)arg0)->minValue;
            result = *value - ((ValueSlider *)arg0)->step;
            result = result > bound ? result : bound;
            *value = result;
        }
        break;
    case MENU_KEY_UP:
        if (*(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217D84(*(s32 *)((u8 *)arg0 + 0x2C)); /* previous entry */
            fn_80230E90(0);
        } else {
            return 0;
        }
        break;
    case MENU_KEY_DOWN:
        if (*(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x2C) + 0x494) > 1) {
            fn_80217C4C(*(s32 *)((u8 *)arg0 + 0x2C)); /* next entry */
            fn_80230E90(0);
        } else {
            return 0;
        }
        break;
    default:
        return 0;
    }
    return handled;
}

extern "C" void fn_8022071C(void *widget) {
    /* If enabled, register the current selection (+0x25C) with its id (+0x2C), store the returned table entry at +0x258, and notify (tag 1, size 4). */
    void *entry;
    if (fn_80129BC4() != 0) {
        entry = fn_80217BD8(*(s32 *)((u8 *)widget + 0x2C), *(s32 *)((u8 *)widget + 0x25C), widget);
        *(void **)((u8 *)widget + 0x258) = entry;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(widget, 1, entry, 4);
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
/* Deleting destructor of the slider bar widget fn_80220778 builds (vtable
 * lbl_8033E668): restore its vtable, release the two slider images it loaded,
 * run the base Widget destructor and, when the deleting flag is set (scalar
 * deleting destructor), free the object itself. */
extern "C" void *fn_80220874(void *self, s32 deletingFlag) {
    /* The slider bar fn_80220778 builds into a 0x264-byte UI node: the groove
       (slider1.img) drawn full size with a fill (slider2.img) scaled to
       *value between minValue and maxValue (fn_80220C54). */
    struct SliderBarWidget {
        void *vtable;     /* +0x000 */
        u8 widget[0x240]; /* +0x004 base Widget state */
        s32 *value;       /* +0x244 index the slider moves */
        void *trackImage; /* +0x248 slider1.img */
        void *barImage;   /* +0x24C slider2.img */
        s32 minValue;     /* +0x250 lowest index */
        s32 maxValue;     /* +0x254 one past the highest */
    };
    #define SliderBar_vtable lbl_8033E668
    #define Image_release    fn_802C519C

    if (self != NULL) {
        ((SliderBarWidget *)self)->vtable = SliderBar_vtable;
        Image_release(((SliderBarWidget *)self)->trackImage);
        Image_release(((SliderBarWidget *)self)->barImage);
        Widget_dtor(self, 0);
        if (deletingFlag > 0) {
            Mem_freeObject(self);
        }
    }

    #undef SliderBar_vtable
    #undef Image_release
    return self;
}

extern "C" void fn_802208EC(void *widget) {
    /* If enabled, register (+0x260, +0x2C) and cache the returned entry at +0x25C, then notify (tag 1, size 4). */
    void *entry;
    if (fn_80129BC4() != 0) {
        entry = fn_80217BD8(*(s32 *)((u8 *)widget + 0x2C),
                            *(s32 *)((u8 *)widget + 0x260), widget);
        *(void **)((u8 *)widget + 0x25C) = entry;
        ((void (*)(void *, s32, void *, s32))fn_80219440)(widget, 1, entry, 4);
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
    register s32 duration = ((Dispatch *)arg0)->get();
    register s32 range = *(volatile s32 *)((u8 *)arg0 + 0x254);
    s32 time = frame - field4 - 5;
    s32 distance = range - field250;
    register s32 result = field250 + distance * time / (duration - 10);
    result = result < field250 ? field250 : result;
    register s32 max = *(volatile s32 *)((u8 *)arg0 + 0x254);
    max -= 1;
    result = result >= max ? max : result;
    *(s32 *)*(void **)((u8 *)arg0 + 0x244) = result;
}

extern "C" void fn_80220AFC(void *self) {
    /* Deactivates this menu widget: runs its virtual update (vtable slot +0x4C) then clears its active flag (+0x258). */
    struct VfWidget {
        VfObj obj;          /* 0x00: vtable; slot +0x4C advances the widget */
        u8 pad_0x4[0x254];
        u8 active;          /* 0x258: nonzero while the widget is active */
    };
    VfWidget *widget = (VfWidget *)self;

    widget->obj.vf17();
    widget->active = 0;
}

extern "C" void fn_80220B3C(void *widget) {
    /* If this widget's +0x258 flag byte is set, run its vf13() handler. */
    if (*(u8 *)((u8 *)widget + 0x258) != 0)
        ((VfObj *)widget)->vf13();
}

extern "C" void fn_80220B5C(void *arg0, s32 arg1) {
    s32 *entries;
    u32 cur;
    s32 *p;
    s32 f8b;
    s32 f4b;
    s32 div;
    s32 v1;
    fn_802C3034(arg1);
    s32 v0 = ((VfObj *)arg0)->vf28() - 11;
    entries = *(s32 **)((u8 *)arg0 + 0x244);
    p = *(s32 **)((u8 *)arg0 + 0x25C);
    s32 flag = 0;
    cur = *(u32 *)((u8 *)arg0 + 0x250);
    div = ((*entries - (s32)cur) * v0) / ((s32)*(s32 *)((u8 *)arg0 + 0x254) - (s32)cur - 1);
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
extern "C" void fn_80220C54(void *arg0)
{
  register void *self = arg0;
  s32 *entries;
  register s32 size;
  s32 current;
  s32 *check;
  s32 target;
  register s32 enabled;
  s32 e0;
  s32 h = ((Vf78 *) self)->get() - 0xB;
  entries = *((s32 **) (((u8 *) self) + 0x244));
  check = *((s32 **) (((u8 *) self) + 0x25C));
  enabled = 0;
  current = *((s32 *) (((u8 *) self) + 0x250));
  e0 = *entries;
  target = *((s32 *) (((u8 *) self) + 0x254));
  size = (h * (e0 - current)) / ((target - current) - 1);
  if ((check != 0) && ((*check) == (*((s32 *) (((u8 *) self) + 0x260)))))
  {
    enabled = 1;
  }
  s32 centerX = ((s32) (lbl_8055FB9C + (((u32) lbl_8055FB9C) >> 31))) >> 1;
  s32 centerY = ((s32) (lbl_8055FBA0 + (((u32) lbl_8055FBA0) >> 31))) >> 1;
  f32 x = (f32) ((*((s32 *) (((u8 *) self) + 4))) - centerX);
  f32 y = (f32) (centerY - (*((s32 *) (((u8 *) self) + 8))));
  f32 previous = (f32) fn_802C5220(*((s32 *) (((u8 *) self) + 0x248)));
  f32 value = (float) ((f32) ((Vf78 *) self)->get());
  fn_802C5320(*(((u8 *) self) + 0x248), enabled, x, y, lbl_805634A8, value, previous);
  f32 following = (f32) fn_802C5220(*((s32 *) (((u8 *) self) + 0x24C)));
  fn_802C5320(*((s32 *) (((u8 *) self) + 0x24C)), enabled, lbl_805634E0 + x, y - lbl_805634E0, lbl_805634A8, (f32) size, following);
}
#pragma pop

extern "C" void fn_802C40B8(s32, s32, s32);
/* Sets the active text/canvas style, then blits this widget's stored picture
 * rectangle (at +0x244) onto the canvas at the widget's (x,y) position. */
extern "C" void fn_80220E08(void *widget, s32 canvasState) {
#define SetTextStyle fn_802C3034
#define DrawPicture  fn_802C40B8
    SetTextStyle(canvasState);
    DrawPicture(*(s32 *)((u8 *)widget + 0x244), *(s32 *)((u8 *)widget + 4), *(s32 *)((u8 *)widget + 8));
#undef DrawPicture
#undef SetTextStyle
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

/* Scroll bar drag: if pos is on the thumb, remember the grab offset; otherwise
 * page the child's scroll position (+8, clamped to [0, total - visible]) toward pos.
 * Returns 1 when it paged. */
static inline BOOL ScrollBarDrag(s32 *child, f32 scale, s32 base, s32 pos, s32 *grab) {
    s32 begin = base + (s32)(scale * (f32)child[2]) + 5;
    s32 end = base + (s32)(scale * (f32)(child[2] + child[1])) - 5;
    s32 size;
    s32 limit;

    if (pos >= begin && pos <= end) {
        *grab = (s32)(scale * (f32)child[2]) - pos;
        return FALSE;
    }
    if (pos < begin) {
        size = (s32)((f32)child[2] - (lbl_805634A4 / scale) * (f32)((end - begin) + 5));
    } else {
        size = (s32)((lbl_805634A4 / scale) * (f32)((end - begin) + 5) + (f32)child[2]);
    }
    child[2] = size;
    limit = child[0] - child[1];
    if (size > limit) {
        child[2] = limit;
    }
    if (child[2] < 0) {
        child[2] = 0;
    }
    return TRUE;
}

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
    void *child;

    *(s8 *)((u8 *)arg0 + 0x250) = 1;
    if (*(s32 *)((u8 *)arg0 + 0x254) == 0) {
        f32 scale;
        s32 begin;
        s32 end;
        s32 size;
        s32 limit;
        child = *(void **)((u8 *)arg0 + 0x244);
        scale = (f32)(*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8)) / (f32)*(s32 *)child;
        begin = *(s32 *)((u8 *)arg0 + 8) + (s32)(scale * (f32)(*(s32 *)((u8 *)child + 8))) + 5;
        end = *(s32 *)((u8 *)arg0 + 8) + (s32)(scale * (f32)((*(s32 *)((u8 *)child + 8)) + *(s32 *)((u8 *)child + 4))) - 5;
        if (arg2 >= begin && arg2 <= end) {
            *(s32 *)((u8 *)arg0 + 0x25C) = (s32)(scale * (f32)(*(s32 *)((u8 *)child + 8))) - arg2;
            return;
        }
        if (arg2 < begin) {
            size = (s32)((f32)(*(s32 *)((u8 *)child + 8)) - ((lbl_805634A4 / scale) * (f32)((end - begin) + 5)));
            *(s32 *)((u8 *)child + 8) = size;
            limit = *(s32 *)child - *(s32 *)((u8 *)child + 4);
            if (size > limit) {
                *(s32 *)((u8 *)child + 8) = limit;
            }
            if (*(s32 *)((u8 *)child + 8) < 0) {
                *(s32 *)((u8 *)child + 8) = 0;
            }
        } else {
            f32 factor = lbl_805634A4 / scale;
            f32 distance = (f32)((end - begin) + 5);
            f32 adjusted = distance * factor;
            size = (s32)(adjusted + (f32)(*(s32 *)((u8 *)child + 8)));
            *(s32 *)((u8 *)child + 8) = size;
            limit = *(s32 *)child - *(s32 *)((u8 *)child + 4);
            if (size > limit) {
                *(s32 *)((u8 *)child + 8) = limit;
            }
            if (*(s32 *)((u8 *)child + 8) < 0) {
                *(s32 *)((u8 *)child + 8) = 0;
            }
        }
        *(s8 *)((u8 *)arg0 + 0x250) = 0;
        return;
    }

    {
        f32 scale2;
        s32 begin2;
        s32 end3;
        s32 size2;
        s32 end4;
        s32 childBase;
        void *child2;
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
            f32 factor2 = lbl_805634A4 / scale2;
            f32 distance2 = (f32)((end3 - begin2) + 5);
            f32 adjusted2 = distance2 * factor2;
            size2 = (s32)(adjusted2 + (f32)*(s32 *)((u8 *)child + 8));
            *(s32 *)((u8 *)child + 8) = size2;
            end4 = *(s32 *)child - *(s32 *)((u8 *)child + 4);
            if (size2 > end4) {
                *(s32 *)((u8 *)child + 8) = end4;
            }
            if (*(s32 *)((u8 *)child + 8) < 0) {
                *(s32 *)((u8 *)child + 8) = 0;
            }
        }
        *(s8 *)((u8 *)arg0 + 0x250) = 0;
    }
}
#pragma scheduling on
extern "C" void fn_802213A4(void *scrollBar, s32 pointerX, s32 pointerY) {
    /* While dragging a scroll bar, turn the pointer position into a content
     * offset using the track length and clamp it to [0, total - page size]. */
    void *scrollState;
    s32 newOffset;
    if (*(u8 *)((u8 *)scrollBar + 0x250) == 0) return;
    if (*(s32 *)((u8 *)scrollBar + 0x254) == 0) {
        scrollState = *(void **)((u8 *)scrollBar + 0x244);
        newOffset = (s32)(((f32)*(s32 *)scrollState / (f32)(*(s32 *)((u8 *)scrollBar + 0x10) - *(s32 *)((u8 *)scrollBar + 8))) * (f32)(pointerY + *(s32 *)((u8 *)scrollBar + 0x25C)));
        *(s32 *)((u8 *)scrollState + 8) = newOffset;
        if (newOffset > *(s32 *)scrollState - *(s32 *)((u8 *)scrollState + 4)) *(s32 *)((u8 *)scrollState + 8) = *(s32 *)scrollState - *(s32 *)((u8 *)scrollState + 4);
        if (*(s32 *)((u8 *)scrollState + 8) < 0) *(s32 *)((u8 *)scrollState + 8) = 0;
    } else {
        s32 totalSize = *(s32 *)(*(void **)((u8 *)scrollBar + 0x244));
        f32 unitsPerPixel = (f32)totalSize / (f32)((Vf78 *)scrollBar)->get();
        newOffset = (s32)(unitsPerPixel * (f32)(pointerX + *(s32 *)((u8 *)scrollBar + 0x258)));
        scrollState = *(void **)((u8 *)scrollBar + 0x244);
        *(s32 *)((u8 *)scrollState + 8) = newOffset;
        if (newOffset > *(s32 *)scrollState - *(s32 *)((u8 *)scrollState + 4)) *(s32 *)((u8 *)scrollState + 8) = *(s32 *)scrollState - *(s32 *)((u8 *)scrollState + 4);
        if (*(s32 *)((u8 *)scrollState + 8) < 0) *(s32 *)((u8 *)scrollState + 8) = 0;
    }
}

extern "C" void fn_80221538(void *scrollBar) {
    /* End a scroll-bar drag: clear the "dragging" flag checked by fn_802213A4. */
    *(u8 *)((u8 *)scrollBar + 0x250) = 0;
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
struct Fn80221970Child { s32 base; s32 length; s32 offset; };
struct Fn80221970Object {
    u8 pad0[4]; s32 x; s32 y; u8 padC[4]; s32 end;
    u8 pad14[0x230]; Fn80221970Child *child; s32 texture; s32 overlay; s32 state; s32 flag;
};
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
extern "C" void fn_80221970(Fn80221970Object *self) {
    typedef Fn80221970Child Child;
    s32 scroll;
    Child *child;
    Child *child0;
    Child *child1;
    s32 x;
    s32 left;
    long right;
    s32 y0;
    s32 diff;
    s32 y1;
    s32 color;
    s32 base;
    s32 bottom;
    s32 top;
    f32 scale;
    f32 spC;
    f32 sp8;

    spC = (f32)(self->x - lbl_8055FB9C / 2);
    sp8 = (f32)(lbl_8055FBA0 / 2 - self->y);
    fn_802C5320(self->texture, 0, spC, sp8, lbl_805634A8,
                (f32)((Vf78 *)self)->get(), (f32)(self->end - self->y));
    child = self->child;
    base = child->base;
    if (child->length < base) {
        if (self->flag == 0) {
            x = self->x;
            left = x + 1;
            scale = (f32)(self->end - self->y) / (f32)base;
            scroll = ((Vf78 *)self)->get();
            right = x + scroll - 1;
            child0 = self->child;
            y0 = self->y + (s32)(scale * (f32)child0->offset) + 5;
            y1 = self->y + (s32)(scale * (f32)(child0->offset + child0->length)) - 5;
            if (y1 - 1 > y0 + 1 && right - 1 > left + 1) {
                if (self->overlay != 0) {
                    diff = fn_802C51C0(self->texture) - fn_802C51C0(self->overlay);
                    fn_80230C30(&spC, &sp8, left + diff / 2, y0);
                    fn_802C5320(self->overlay, 0, spC, sp8, lbl_805634A8,
                                (f32)fn_802C51C0(self->overlay), (f32)(y1 - y0));
                } else {
                    fn_802E30C8(lbl_8033D9F8);
                    fn_802C3424(left, y0, right, y1, lbl_8055FBDC);
                    color = lbl_8055FBE0;
                    fn_802C3424(left, y1 - 1, right, y1, color);
                    fn_802C3424(right - 1, y0, right, y1, color);
                    color = lbl_8055FBFC;
                    fn_802C3424(left, y0, right, y0 + 1, color);
                    fn_802C3424(left, y0, left + 1, y1, color);
                }
            }
        } else {
            scroll = ((Vf78 *)self)->get();
            child1 = self->child;
            scale = (f32)scroll / (f32)base;
            top = self->y + 1;
            bottom = self->end - 1;
            register left = self->x + (s32)(scale * (f32)child1->offset) + 5;
            right = self->x + (s32)(scale * (f32)(child1->offset + child1->length)) - 5;
            if (right - 1 > left + 1 && bottom - 1 > top + 1) {
                if (self->overlay != 0) {
                    diff = fn_802C5220(self->texture) - fn_802C5220(self->overlay);
                    fn_80230C30(&spC, &sp8, left, top + diff / 2);
                    fn_802C5320(self->overlay, 0, spC, sp8, lbl_805634A8,
                                (f32)(right - left), (f32)fn_802C5220(self->overlay));
                } else {
                    fn_802E30C8(lbl_8033D9F8);
                    fn_802C3424(left, top, right, bottom, lbl_8055FBDC);
                    color = lbl_8055FBE0;
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
#pragma pop

#pragma pop
/**
 * Marks the child widget held at parent+0x14 as needing a redraw, but only
 * if it is currently active (flag at +0x1A); the dirty flag is at +0x234.
 */
extern "C" void fn_80221E7C(void *parent) {
    void *widget = *(void **)((u8 *)parent + 0x14);
    if (widget != 0 && *(u8 *)((u8 *)widget + 0x1A) != 0)
        *(u8 *)((u8 *)widget + 0x234) = 1;
}

#pragma dont_inline on
/**
 * Registers one tracked field with the field-list manager held at `panel`+0x14:
 * forwards the field id, a pointer to its value and that value's byte size,
 * which the manager copies and records for change notification.
 */
extern "C" void fn_80221EA0(void *panel, s32 fieldId, void *value, s32 size) {
    fn_80219440(*(void **)((u8 *)panel + 0x14), fieldId, value, size);
}
#pragma dont_inline reset
extern "C" s32 fn_80221EA8(void *arg0) {
    extern char lbl_8033DA2C[];
    u32 value = *(u32 *)((u8 *)*(void **)((u8 *)arg0 + 0x14) + 0x238);
    for (s32 i = 0; i < 32; i++) {
        if (value == (1 << i)) {
            return i;
        }
    }
    fn_802E317C(lbl_8033DA2C);
    return 0;
}

extern "C" void fn_80221F94(void *context, s32 result) {
    /* Callback thunk: ignore the context and request a fade with the given result. */
    fn_802168BC((void *)result);
}

extern "C" s32 lbl_8055FBE4;
extern "C" void fn_802C4F58(s32, s32, const char *, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80221F9C(void *arg0, s32 arg1) {
    s32 var_r31;
    s32 temp_r30;
    s32 temp_r29;
    s32 temp_r28;
    long var_r26;
    s32 var_r20;
    u32 temp_r20;
    s32 var_r27;
    s32 temp_r23;
    s32 var_r22;
    void *temp_r21;
    s32 var_r25;
    s32 var_r18;
    s32 temp_r18;
    unsigned int var_r24;
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
        register temp_r20 = *(s32 *)((u8 *)temp_r21 + 8);
        fn_802C3424(var_r24, temp_r23 + 0xA, var_r24 + 0x32, temp_r23 + (temp_r20 + 1) * 0xA, temp_r29);
        var_r26 = temp_r23 + 0xB;
        var_r25 = temp_r23 + 0xC;
        var_r20 = 0;
        var_r27 = 0;
        while (var_r20 < *(s32 *)((u8 *)temp_r21 + 8)) {
            if (var_r20 == *(s32 *)((u8 *)arg0 + 0x250))
                fn_802C3424(var_r24 + 1, var_r26, var_r24 + 0x31, temp_r23 + var_r27 + 0x13, temp_r30);
            temp_r18 = temp_r30;
            if (var_r20 == *(s32 *)((u8 *)arg0 + 0x250))
                temp_r18 = temp_r28;
            fn_802C4F58(var_r24 + 2, var_r25, (const char *)((s32 (*)(s32 *, s32))fn_8022D97C)((s32 *)temp_r21, var_r20), temp_r18);
            var_r26 += 0xA;
            var_r27 += 0xA;
            var_r25 += 0xA;
            var_r20 += 1;
        }
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
extern "C" void fn_80222120(void *self) {
    /* Marks selection pending, refreshes, and flags redraw when active. */
    *(u8 *)((u8 *)self + 0x248) = 1;
    ((VfObj *)self)->vf17();
    if (*(u8 *)((u8 *)self + 0x1A) != 0)
        *(u8 *)((u8 *)self + 0x234) = 1;
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
    s32 left, current, top, count;
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
        s32 col = (x - left) / 50;
        if (col < 0) return;
        s32 *items2 = *(s32 **)((u8 *)obj + 0x244);
        if (col >= items2[0x120 / 4]) return;
        state[0x24C / 4] = col;
        state[0x250 / 4] = -1;
        return;
    }
    current = state[0x24C / 4];
    if (current < 0) return;
    left = state[1];
    if (x < left + current * 50) goto fail_x;
    if (x > left + (current + 1) * 50) goto fail_x;
    {
        s32 *list = *(s32 **)((u8 *)obj + 0x244);
        s32 row = (y - top - 10) / 10;
        entry = *(s32 **)((u8 *)list + current * 0x24);
        if (row < 0) goto fail_row;
        if (row >= entry[2]) goto fail_row;
        state[0x250 / 4] = row;
    }
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
    /* Initialize a UI/widget object: set up its base bounds, store its position/
       size and associated id, install its vtable, then run its Init method. */
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

#pragma scheduling invalid_target
extern "C" RET_802223C4 fn_802223C4(void *arg0, s32 arg1) {
    s32 value;
    if (arg0 != 0) {
        value = *(s32 *)((u8 *)arg0 + 0x244);
        *(void **)arg0 = lbl_8033F90C;
        if (value != 0) {
            struct Dispatch { virtual void call(s32); };
            ((Dispatch *)value)->call(1);
        }
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return (RET_802223C4)arg0;
}
#pragma scheduling on
extern "C" void fn_80222450(void *widget) {
    /* Mark this VfWidget dirty (+0x234) when its layout option (+0x1A) is set. */
    if (*(u8 *)((char *)widget + 0x1A) != 0) {
        *(u8 *)((char *)widget + 0x234) = 1;
    }
}

/* Repositions the widget by delegating to the base move handler, then stores the requested origin coordinates. */
extern "C" void fn_80222468(void *widget, s32 x, s32 y) {
    ((void (*)(void))fn_802191F0)();
    *(s32 *)((u8 *)widget + 0x248) = x;
    *(s32 *)((u8 *)widget + 0x24C) = y;
}

/* Constructs a derived UI widget: initializes the base widget via fn_80222340 with position (x, y), size (width, height), and id, installs vtable lbl_8033F880, and initializes derived fields at +0x254..+0x25C. */
extern "C" void *fn_802224B4(void *self, s32 value25C, s32 x, s32 y,
                             s32 width, s32 height, s32 id, s32 value258,
                             u8 flag256, u8 flag257) {
    fn_80222340(self, x, y, 0, width, height, id);
    *(void **)self = lbl_8033F880;
    *(s32 *)((u8 *)self + 0x25C) = value25C;
    *(s32 *)((u8 *)self + 0x258) = value258;
    *(u8 *)((u8 *)self + 0x256) = flag256;
    *(u8 *)((u8 *)self + 0x257) = flag257;
    *(u8 *)((u8 *)self + 0x255) = 0;
    *(u8 *)((u8 *)self + 0x254) = 0;
    return self;
}
#pragma scheduling invalid_target
extern "C" void fn_802328D4(void*);
extern "C" s32 lbl_8033F9E0[];
extern "C" s32 fn_80232578(s32);
#pragma scheduling invalid_target
/* Constructs a gText display item: loads the font file named by fontName through
 * the gText loader, remembers the string to draw with it, and installs the text
 * item's vtable (draw fn_802225E8, measure fn_8022264C, dtor fn_80222584). */
extern "C" void *fn_80222530(void *self, const char *fontName, const char *text) {
    #define GTextItemVTable lbl_8033F9E0 /* this item's vtable */
    #define GTexLoadFont fn_80232578     /* gText: load a font by archive file name */
    struct GTextItem {
        void *vtable;      /* 0x0 */
        void *font;        /* 0x4: the loaded gText font block */
        const char *text;  /* 0x8: the string to draw */
    };

    ((GTextItem *)self)->vtable = &GTextItemVTable;
    ((GTextItem *)self)->font = (void *)GTexLoadFont((s32)fontName);
    ((GTextItem *)self)->text = text;
    #undef GTextItemVTable
    #undef GTexLoadFont
    return self;
}
#pragma scheduling invalid_target
#pragma scheduling invalid_target
/* Destructor for CollisionSpace: restores its vtable, releases the owned
 * resource at offset +4, and deletes the object when shouldDelete > 0. */
extern "C" void* __dt__14CollisionSpaceFv_80222584(void* self, s32 shouldDelete) {
    if (self != 0) {
        *(void**)self = &lbl_8033F9E0;
        fn_802328D4(((void**)self)[1]);
        if (shouldDelete > 0) {
            ((s32 (*)(void*))fn_80128668)(self);
        }
    }
    return self;
}
extern "C" void fn_802336AC(s32, s32, s32, const char *, f32, f32, f32, ...);
extern "C" char lbl_8055B8A4[4];
extern "C" void fn_802225E8(void *obj, s32 gridX, s32 gridY) {
    /* Convert grid coordinates to world position and draw the object's text at offset +4 with format "%s". */
    f32 worldX;
    f32 worldY;

    fn_80230C30(&worldX, &worldY, gridX, gridY);
    f32 z = lbl_805634A8;
    fn_802336AC(*(s32 *)((u8 *)obj + 4), -1, 9, lbl_8055B8A4, worldX, worldY, z,
                *(s32 *)((u8 *)obj + 8));
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
extern "C" void *fn_802226D4(void *self, s32 resourceId) {
    /* RealName: InitWithVTableAndResource_802226D4. Initialize object with vtable lbl_8033F9BC and store resource loaded from resourceId. */
    extern char lbl_8033F9BC[];
    extern s32 fn_8023512C(s32);
    *(volatile char **)self = lbl_8033F9BC;
    *(s32 *)((u8 *)self + 4) = fn_8023512C(resourceId);
    return self;
}

void fn_80235380(int);
extern "C" char lbl_8033F9BC[];
/* Destructor-like cleanup: saves the owned resource handle at +4, resets the
 * vtable to lbl_8033F9BC, releases the previous handle via fn_80235380 if set,
 * and optionally frees the object when deleting > 0. */
extern "C" void *fn_80222718(void *object, s32 deleting) {
    s32 ownedHandle;
    if (object != 0) {
        ownedHandle = *(s32 *)((char *)object + 4);
        *(char **)object = lbl_8033F9BC;
        if (ownedHandle != 0) fn_80235380(ownedHandle);
        if (deleting > 0) ((s32 (*)(void *))fn_80128668)(object);
    }
    return object;
}

#pragma push
#pragma processor 750
extern "C" void fn_80222788(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    /* If the object has an associated handle, convert (arg1,arg2) and forward the result with a constant scale. */
    f32 outX;
    f32 outY;

    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        f32 scale = lbl_805634A8;
        fn_80230C30(&outX, &outY, arg1, arg2);
        fn_802353F4(*(s32 *)((u8 *)arg0 + 4), arg4, outX, outY, scale);
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
/* CollisionSpace::~CollisionSpace (scalars deleting): restore vtable, release resource handle, and optionally delete. */
extern "C" void* __dt__14CollisionSpaceFv_80222998(void* this_, s32 flag) {
    if (this_ != 0) {
        *(void**)this_ = &lbl_8033F998;
        fn_802C519C(((void**)this_)[1]);
        if (flag > 0) {
            ((s32 (*)(void*))fn_80128668)(this_);
        }
    }
    return this_;
}

extern "C" void fn_802229FC(void *object) {
    /* Dispose of an object's art-set handle at +0x4: if it still holds pictures,
     * the picture-count helper is invoked a second time (as in the original). */
    if (fn_802C51AC(*(s32 *)((u8 *)object + 4)) != 0) {
        fn_802C51AC(*(s32 *)((u8 *)object + 4));
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
    /* Compute an axis-aligned bounding box at (arg1,arg2) with size from arg0+8/+C (floats). */
    *arg3 = arg1;
    *arg4 = arg2;
    *arg5 = *arg3 + (s32) *(f32 *)((u8 *)arg0 + 8);
    *arg6 = *arg4 + (s32) *(f32 *)((u8 *)arg0 + 0xC);
}

extern "C" s32 fn_80222B48(void *self, s32 unused1, s32 unused2, s32 x, s32 y) {
    struct V {
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void Call(s32, s32, s32*, s32*, s32*, s32*);
    };
    s32 sp14, sp10, spC, sp8, result;

    /* Query bounds via virtual call and return 1 if (x,y) is inside [left,right) x [top,bottom). */
    ((V*)self)->Call(unused1, unused2, &sp8, &spC, &sp10, &sp14);
    result = 0;
    if (x >= sp8 && x < sp10 && y >= spC && y < sp14) {
        result = 1;
    }
    return result;
}

extern "C" s32 fn_80222BD4(void *self) {
    /* Query the image/resource-set handle stored at +4 of this object. */
    return fn_802C51AC(*(s32*)((u8*)self + 4));
}

extern "C" char lbl_8033E560[];
extern "C" char lbl_8033DA60[];
extern "C" void fn_802E317C(const char *, ...);
extern f32 lbl_8056351C;
extern f64 lbl_80563520;
#pragma push
#pragma scheduling invalid_target
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
#pragma pop
extern "C" void * __dt__Q34Game10MemoryCard8ResourceFv_80222C8C(void *arg0, s32 arg1) {
    /* Deleting destructor for the object using vtable lbl_8033E560: reset the
       vtable, destroy the owned object at +0x248 (fn_802328D4), run the base
       destructor (fn_8021915C), and delete if arg1 > 0. */
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033E560;
        fn_802328D4((void *)*(s32 *)((u8 *)arg0 + 0x248));
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma processor 750
extern "C" char lbl_8055B8A8[4];
extern "C" void fn_80222CFC(void *arg0, s32 arg1) {
    struct TransformArgs { s32 x, y; f32 z; };
    f32 sp38[10];
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
    register s32 var_r30;
    register void *temp_r29;
    register void *temp_r28;
    register void *temp_r27;
    register s32 var_r26;
    register void *temp_r25;
    register char *temp_r24;
    register s32 var_r21;
    void *temp_r3;
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
    var_r21 = 0;
    goto loop3_test;
loop3_body:
    temp_r3 = ((char *(*)(s32, s32, s32))fn_8022D3F8)(
        *(s32 *)((u8 *)temp_r25 + 0x244), var_r21, 0);
    temp_f28 += fn_8023293C(*(s32 *)((u8 *)temp_r25 + 0x248),
        (s32)temp_r3, lbl_805634A4);
    var_r21++;
loop3_test:
    if (var_r21 < temp_r31) goto loop3_body;

    temp_f3 = lbl_805634D8 * *(f32 *)((u8 *)temp_r25 + 0x250);
    temp_f3 -= temp_f28;
    temp_f30 = temp_f3 / (f32)temp_r31;
    temp_f1 = temp_f30 * (f32)temp_r31;
    temp_f1 = temp_f28 + temp_f1;
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
    var_r21 = 0;
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
    *(volatile u32 *)&stack.sp2C = var_r21;
    *(volatile u32 *)&stack.sp30 = var_r21;
    *(volatile u32 *)&stack.sp34 = var_r21;
    *(volatile f32 *)&stack.sp2C = stack.sp10;
    *(volatile f32 *)&stack.sp30 = stack.spC;

    if (var_r23 == var_r22) {
        stack.sp14 = (stack.sp10 * ((f32 *)temp_r28)[0] +
            stack.spC * ((f32 *)temp_r28)[3]) +
            stack.sp34 * ((f32 *)temp_r28)[6];
        stack.sp18 = (stack.sp10 * ((f32 *)temp_r28)[1] +
            stack.spC * ((f32 *)temp_r28)[4]) +
            stack.sp34 * ((f32 *)temp_r28)[7];
        stack.sp1C = (stack.sp10 * ((f32 *)temp_r28)[2] +
            stack.spC * ((f32 *)temp_r28)[5]) +
            stack.sp34 * ((f32 *)temp_r28)[8];
    } else {
        stack.sp14 = (stack.sp10 * ((f32 *)temp_r28)[0] +
            stack.spC * ((f32 *)temp_r28)[3]) +
            stack.sp34 * ((f32 *)temp_r28)[6] +
            ((f32 *)temp_r28)[9];
        stack.sp18 = (stack.sp10 * ((f32 *)temp_r28)[1] +
            stack.spC * ((f32 *)temp_r28)[4]) +
            stack.sp34 * ((f32 *)temp_r28)[7] +
            ((f32 *)temp_r28)[10];
        stack.sp1C = (stack.sp10 * ((f32 *)temp_r28)[2] +
            stack.spC * ((f32 *)temp_r28)[5]) +
            stack.sp34 * ((f32 *)temp_r28)[8] +
            ((f32 *)temp_r28)[11];
    }

    ((f32 *)temp_r28)[9] += stack.sp14;
    ((f32 *)temp_r28)[10] += stack.sp18;
    temp_f2 = ((f32 *)temp_r28)[11];
    temp_f1_2 = temp_f2 + stack.sp1C;
    ((f32 *)temp_r28)[11] = temp_f1_2;

    *(volatile u32 *)&stack.sp20.z = var_r21;
    stack.sp20.x = var_r21;
    stack.sp20.y = var_r21;
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
    register u8 *obj = (u8 *)self;
    register u8 *input = (u8 *)arg3;
    register s32 data = arg4;
    register s32 i;
    register u8 *row;
    register s32 offset;
    register s32 zero;
    register s32 one;
    register s32 minusOne;
    s32 scratch;
    s32 count;
    s32 texture;
    register f32 defaultValue;
    f32 baseValue;
    f32 scale;
    f32 lastValue;
    f32 resetValue;

    fn_80218F34(obj, arg1, arg2, 0, 0, 0);
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
    row = obj + offset;
    *(s32 *)(row + 0x378) = (scratch >> 2) & 0x3F;
    {
        f32 width = fn_8023293C(*(s32 *)(obj + 0x3FC), data, lbl_805634A4);
        *(f32 *)(row + 0x2F4) = *(f32 *)(obj + 0x404) * width;
    }
    *(s32 *)(row + 0x244) = data;
    goto next;
empty:
    row = obj + offset;
    *(s32 *)(row + 0x244) = zero;
    *(f32 *)(row + 0x2F4) = defaultValue;
    *(s32 *)(row + 0x378) = minusOne;
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
    ((void (*)(void *))fn_8022375C)(obj);
    return obj;
}

/* Deleting destructor of the gText text widget built by fn_802230A4: releases
 * the "uifnt.gtx" font block the widget holds at +0x3FC, runs the widget base
 * destructor and frees the object when called through delete. */
extern "C" void *fn_80223208(void *self, unsigned int deletingFlag) {
    #define TextWidgetVTable lbl_8033E4DC /* this widget's vtable */
    #define ReleaseFontBlock fn_802328D4  /* gText: drop a loaded font block */
    #define WidgetBaseDtor fn_8021915C    /* the widget base class destructor */
    #define HeapFree fn_80128668          /* operator delete */
    if (self != 0) {
        *(void **)self = TextWidgetVTable;
        ReleaseFontBlock(*(void **)((u8 *)self + 0x3FC)); // the loaded font block
        *(s32 *)((u8 *)self + 0x3FC) = 0;
        WidgetBaseDtor(self, 0);
        if ((s32)deletingFlag > 0) {
            HeapFree(self);
        }
    }
    #undef TextWidgetVTable
    #undef ReleaseFontBlock
    #undef WidgetBaseDtor
    #undef HeapFree
    return self;
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
            temp_f30 += *(f32 *)((u8 *)arg0 + 0x400) + (temp_f28 * *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F4));
            if (var_r28 + 1 < temp_r4) {
                temp_f30 += temp_f28 * *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F8);
            }
        } else {
            fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + var_r28 * 4 + 0x244), *(s32 *)((u8 *)arg0 + 0x3FC), 0xFF000000, 0xC, temp_f27 + temp_f30, temp_f31 - temp_f27, *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
            fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + var_r28 * 4 + 0x244), *(s32 *)((u8 *)arg0 + 0x3FC), fn_802236C8(arg0, var_r28), 0xC, temp_f30, temp_f31, *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
            temp_f30 += *(f32 *)((u8 *)arg0 + 0x400) + (temp_f28 * *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F4));
            if (var_r28 + 1 < *(s32 *)((u8 *)arg0 + 0x2C8)) {
                temp_f30 += temp_f28 * *(f32 *)((u8 *)arg0 + var_r28 * 4 + 0x2F8);
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
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(0x966464, temp_f30_2, temp_f31 - lbl_805634EC, temp_f30_2 + temp_f28_2, temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(0x962828, temp_f30_2, temp_f31 - lbl_805634EC, lbl_805634EC + temp_f30_2, temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(0x962828, temp_f30_2, temp_f31 - lbl_805634EC, temp_f30_2 + temp_f28_2, temp_f31 - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(0x96AAAAAA, temp_f30_2, (temp_f31 - temp_f27_2) - lbl_805634EC, temp_f30_2 + temp_f28_2, (temp_f31 - temp_f27_2) - lbl_80563534, lbl_805634A8);
    ((void (*)(s32, f32, f32, f32, f32, f32))fn_80230924)(0x96AAAAAA, temp_f30_2 + temp_f28_2 - lbl_805634EC, temp_f31 - lbl_805634EC, temp_f30_2 + temp_f28_2, temp_f31 - temp_f27_2 - lbl_80563534, lbl_805634A8);
    fn_80232BA4((char *)*(s32 *)((u8 *)arg0 + temp_r29 + 0x244), *(s32 *)((u8 *)arg0 + 0x3FC), 0xFF000000, 0xC, lbl_80563534 + temp_f29, temp_f31 - lbl_80563534, *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
    fn_80232BA4((char *)*(s32 *)(temp_r30_2 + 0x244), *(s32 *)((u8 *)arg0 + 0x3FC), fn_802236C8(arg0, temp_r28), 0xC, lbl_805634EC + temp_f29, temp_f31 - lbl_805634EC, *(f32 *)((u8 *)arg0 + 0x404), lbl_805634A8, lbl_805634A4);
}
#pragma pop
extern "C" void fn_802235B4(void *arg0) {
    /* Move selection forward to the next enabled item (flag at +0x2D0), wrapping
     * by scanning backward from the current index if none found ahead. */
    s32 *pSelectedIndex = *(s32 **)((u8 *)arg0 + 0x2CC);
    s32 nextIndex;
    s32 itemCount = *(s32 *)((u8 *)arg0 + 0x2C8);
    s32 curIndex = *pSelectedIndex;
    u32 baseAddr = (u32)arg0 + curIndex;
    s32 step;
    for (step = 1, nextIndex = curIndex + 1; nextIndex < itemCount; step++, nextIndex++) {
        if (*(u8 *)(step + baseAddr + 0x2D0) != 0) {
            *pSelectedIndex += step;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
    for (step = curIndex; step > 0; step--) {
        if (((u8 *)arg0)[curIndex - step + 0x2D0] != 0) {
            *pSelectedIndex -= step;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
}

#pragma opt_common_subs off
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
        u8 *p = (u8 *)((u32)j + (u32)base);
        if (p[0x2D0]) {
            *pIndex += j;
            ((void (*)(void *))fn_8022375C)(arg0);
            return;
        }
    }
}
#pragma opt_common_subs reset
extern "C" void fn_8022375C(void);
extern "C" void fn_802235B4(void *);
extern "C" void fn_80223644(void *);
/* Returns a display/color code for entry arg1: special value when disabled (0x41C), highlight when it's the selected entry (0x2CC) and the marker (0x414) matches, otherwise enabled/disabled based on flag at 0x2D0. */
extern "C" s32 fn_802236C8(void *arg0, s32 arg1) {
    if (*(u8 *)((u8 *)arg0 + 0x41C) != 0)
        return (s32)0xE6969696;
    u8 *entry = (u8 *)arg0 + arg1;
    u8 enabledFlag = entry[0x2D0];
    s32 result = (s32)0xFF9F9F9F;
    if (enabledFlag != 0)
        result = -1;
    if (arg1 == *(s32 *)*(s32 **)((u8 *)arg0 + 0x2CC) &&
        lbl_805634A4 == *(f32 *)((u8 *)arg0 + 0x414))
        result = -0x2FC1;
    return result;
}

extern "C" void fn_80223728(void *menu) {
    /* Commit pending tracked changes, then set the +0x414 marker to 1.0 so the current entry highlights. */
    fn_802192AC(menu);
    *(f32 *)((u8 *)menu + 0x414) = lbl_805634A4;
}

extern "C" void fn_8022375C(void) {
}

extern "C" s32 fn_80223760(void *arg0, s32 arg1) {
    /* Handles left/right key input for this menu item unless it is disabled;
       returns 1 if the key was handled. */
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

/* Set the sound-list's input-disabled flag (MenuSoundList.disabled at 0x41C). */
extern "C" void fn_802237D0(void *list) {
    *(u8 *)((u8 *)list + 0x41C) = 1;
}

extern "C" void fn_802237DC(void *list) {
    /* Clear the sound-list's input-disabled flag (MenuSoundList.disabled at 0x41C). */
    *(u8 *)((u8 *)list + 0x41C) = 0;
}

/* Return the number of rows in a sound list (MenuSoundList.rowCount at +0x2C8). */
extern "C" s32 fn_802237E8(void *list) {
    return *(s32 *)((u8 *)list + 0x2C8);
}

/* Return the sound id of row `row` from a sound-list's id table at +0x378. */
extern "C" s32 fn_802237F0(s32 list, s32 row) {
    return *(s32 *)(list + (row << 2) + 0x378);
}


extern "C" int lbl_8033E458[];
extern "C" void *fn_80223800(void *self, s32 arg1, s32 arg2, s32 arg3, void *param) {
    /* Constructor: init base, set vtable and field +0x420, register param (if non-null) and current data source. */
    ((void (*)(void))fn_802230A4)();
    *(void **)((u8 *)self + 0x420) = param;
    *(void **)self = lbl_8033E458;
    if (param != 0) {
        fn_80219440(self, 0, param, 4);
    }
    fn_80219440(self, 1, fn_80216708(), 1);
    return self;
}

extern "C" void fn_802237DC(void *);
extern "C" void fn_80223880(void *obj) {
    /* Invoke vtable action 2, clear pending flag, and reset linked object. */
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
    ((CallIface *)obj)->call(2, 0);
    fn_802237DC(obj);
    fn_8021818C(*(s32 *)((u8 *)obj + 0x2C));
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
    u8 pad_0x37C[0x41C - 0x37C];
    u8 disabled;                 // 0x41C cursor keys ignored while set (fn_802237D0/fn_802237DC)
    u8 pad_0x41D[0x420 - 0x41D];
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
extern "C" s32 fn_802239C8(void *object, s32 message) {
    if (*(u8 *)fn_80216708() == 0)
        goto fallback;
    if (message == 0x126)
        goto fallback;
    if (message < 0x126) {
        if (message < 0x125)
            goto fallback;
        goto lower;
    }
    if (message >= 0x128)
        goto fallback;
    ((void (*)(void *))fn_802235B4)(object);
    return 1;
lower:
    ((void (*)(void *))fn_80223644)(object);
    return 1;
fallback:
    return fn_802192A4(object, message);
}

/* Row-draw override for the sound-list menu (it replaces the base class's
 * fn_80223280 in slot 0x28 of vtable lbl_8033E458): the menu only takes
 * left/right cursor input while the UI mode byte behind fn_80216708() is set,
 * so this clears the list's input-disabled flag when it is and sets it when
 * clear, then runs the base class's row drawer. */
extern "C" void fn_80223A58(MenuSoundList *list) {
#define uiModeFlag  fn_80216708
#define enableList  fn_802237DC
#define disableList fn_802237D0
#define drawRows    fn_80223280

    if (*(u8 *)uiModeFlag() != 0) {
        enableList(list);
    } else {
        disableList(list);
    }
    ((void (*)(void *))drawRows)(list);

#undef uiModeFlag
#undef enableList
#undef disableList
#undef drawRows
}

/* Always-true stub of the menu-list class family implemented here: reports 1
 * ("yes" / "message handled") without looking at the object or its arguments.
 * The base version of the same hook answers 0 (fn_802192A4) and the working
 * overrides are fn_80223760 (cursor keys) and fn_802239C8.  It is not one of
 * the first 24 slots of the sibling vtables lbl_8033E3D4, lbl_8033E458 or
 * lbl_8033E4DC, so it overrides a later slot or is used as a plain callback. */
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
/* Destructor-like cleanup: reset vtable, release owned resources/children, run
 * base cleanup, and optionally delete the object. */
extern "C" void *fn_80223B94(void *self, s32 deleting) {
    if (self != 0) {
        void *ownedPtr = *(void **)((u8 *)self + 0x250);
        *(void **)self = lbl_8033E3D4;
        if (ownedPtr != 0)
            fn_802C519C(ownedPtr);
        *(void **)((u8 *)self + 0x250) = 0;
        fn_8022EE98(*(void **)((u8 *)self + 0x260));
        fn_8021915C(self, 0);
        if (deleting > 0)
            fn_80128668(self);
    }
    return self;
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
/* Refresh this widget's match flag: store 0.0f at +0x25C when the cached id at +0x24C equals the watched object's id at +0xC, otherwise 1.0f, then notify watchers through fn_802192AC. */
extern "C" void fn_80223CC4(void *widget) {
#define FLOAT_ZERO lbl_805634A8
#define FLOAT_ONE  lbl_805634A4
    void *watchedObj = *(void **)((u8 *)widget + 0x264);
    s32 cachedId = *(s32 *)((u8 *)widget + 0x24C);
    s32 watchedId = *(s32 *)((u8 *)watchedObj + 0xC);
    if (cachedId == watchedId)
        *(f32 *)((u8 *)widget + 0x25C) = FLOAT_ZERO;
    else
        *(f32 *)((u8 *)widget + 0x25C) = FLOAT_ONE;
    fn_802192AC(widget);
}

extern "C" s32 fn_802C9A58(s32, void *);
extern "C" f32 lbl_80563538;
#pragma push
#pragma scheduling invalid_target
/* Constructor for a movie widget - a widget that plays a movie over its box.
   Runs the base widget constructor, then, when the display is not in widescreen
   mode, re-centres a full-screen widget's box and stretches it horizontally by
   4/3 about the screen centre so it still fills a 4:3 television.  It finishes
   by storing the box in screen-centre coordinates, choosing the movie to play
   (the caller's own when given, otherwise the descriptor's name at +0x40) and
   whether it loops, and clearing the movie handle and completion callback. */
extern "C" void *fn_80223CF0(void *widget, void *descriptor, s32 movieName, s32 arg3) {
#define IsWidescreen    fn_802C9A58
#define Screen_toCentre fn_80230C30
#define Screen_width    lbl_8055CFF0
#define Screen_height   lbl_8055CFF4
#define STRETCH_4_TO_3  lbl_80563538 /* 4/3: what a 4:3 display squashes by */
#define FLOAT_ZERO      lbl_805634A8
    f32 scaledLeft;
    f32 scaledTop;
    f32 rawHeight;
    f32 roundedLeft;
    f32 roundedTop;
    f32 roundedWidth;
    f32 roundedHeight;
    register s32 newLeft;
    register s32 newTop;
    f32 scaledWidth;

    fn_80218F80();

    *(void **)widget = MovieWidget_vtable;
    *(s32 *)((u8 *)widget + 0x258) = 0;
    *(u8 *)((u8 *)widget + 0x25C) = 0;
    *(s32 *)((u8 *)widget + 0x264) = -2;
    *(s32 *)((u8 *)widget + 0x260) = 0;

    if (((s32 (*)(void))IsWidescreen)() == 0) {
        /* Only a widget covering nearly the whole screen needs the 4:3 stretch. */
        if (((VfObj *)widget)->vf28() > 0x258) {
            s32 top = *(s32 *)((u8 *)widget + 8);
            if (*(s32 *)((u8 *)widget + 0x10) - top > 0x1CC) {
                s32 centreX = (Screen_width / 2);
                scaledLeft = STRETCH_4_TO_3 * (f32)(*(s32 *)((u8 *)widget + 4) - centreX);
                if (scaledLeft < FLOAT_ZERO) {
                    roundedLeft = scaledLeft - WIDGET_ROUND_HALF;
                } else {
                    roundedLeft = WIDGET_ROUND_HALF + scaledLeft;
                }
                s32 centreY = (Screen_height / 2);
                newLeft = centreX + (s32)roundedLeft;
                scaledTop = (f32)(top - centreY);
                if (scaledTop < FLOAT_ZERO) {
                    roundedTop = scaledTop - WIDGET_ROUND_HALF;
                } else {
                    roundedTop = WIDGET_ROUND_HALF + scaledTop;
                }
                newTop = centreY + (s32)roundedTop;
                scaledWidth = STRETCH_4_TO_3 * (f32)((VfObj *)widget)->vf28();
                roundedWidth = (scaledWidth < FLOAT_ZERO) ? scaledWidth - WIDGET_ROUND_HALF : WIDGET_ROUND_HALF + scaledWidth;
                s32 scaledWidthInt = (s32)roundedWidth;
                rawHeight = (f32)(*(s32 *)((u8 *)widget + 0x10) - *(s32 *)((u8 *)widget + 8));
                roundedHeight = (rawHeight < FLOAT_ZERO) ? rawHeight - WIDGET_ROUND_HALF : WIDGET_ROUND_HALF + rawHeight;
                *(s32 *)((u8 *)widget + 4) = newLeft;
                *(s32 *)((u8 *)widget + 8) = newTop;
                *(s32 *)((u8 *)widget + 0xC) = newLeft + scaledWidthInt;
                *(s32 *)((u8 *)widget + 0x10) = newTop + (s32)roundedHeight;
            }
        }
    }
    Screen_toCentre((f32 *)((u8 *)widget + 0x244), (f32 *)((u8 *)widget + 0x248), *(s32 *)((u8 *)widget + 4), *(s32 *)((u8 *)widget + 8));
    *(f32 *)((u8 *)widget + 0x24C) = (f32)((VfObj *)widget)->vf28();
    *(f32 *)((u8 *)widget + 0x250) = (f32)(*(s32 *)((u8 *)widget + 0x10) - *(s32 *)((u8 *)widget + 8));
    if (movieName != 0) {
        *(s32 *)((u8 *)widget + 0x258) = movieName;
    } else {
        *(s32 *)((u8 *)widget + 0x258) = (s32)((u8 *)descriptor + 0x40);
    }
    s32 loopFlag = *(s32 *)((u8 *)descriptor + 0xA4);
    *(u8 *)((u8 *)widget + 0x25C) = loopFlag != 0;
    *(s32 *)((u8 *)widget + 0x254) = 0;
    return widget;
}
#pragma pop
#undef FLOAT_ZERO
#undef STRETCH_4_TO_3
#undef Screen_height
#undef Screen_width
#undef Screen_toCentre
#undef IsWidescreen
/* MovieWidget deleting destructor: restore MovieWidget's vtable, destroy any
 * active movie handle at +0x254, run the base Widget destructor, and free the
 * widget when deletingFlag > 0. */
extern "C" void* fn_80223FAC(void* self, s32 deletingFlag) {
    if (self != NULL) {
        s32 movieHandle = ((MovieWidgetLayout*)self)->movieHandle;
        ((MovieWidgetLayout*)self)->vtable = MovieWidget_vtable;
        if (movieHandle != 0) Movie_destroy(movieHandle);
        Widget_dtor(self, 0);
        if (deletingFlag > 0) Mem_freeObject(self);
    }
    return self;
}

extern "C" const char lbl_8033DA90[];
extern "C" void fn_80224028(void *widget) {
    s32 movie;
    s32 (*onMovieEnd)(void *);

    /* Per-frame MovieWidget update: keep the requested movie loaded (reload it
       when the name changes), fire the completion callback when playback ends
       or a load fails, and advance the active movie at the end. */
    fn_802192AC(widget);
    movie = *(s32 *)((u8 *)widget + 0x254);
    if (movie != 0) {
        goto active;
    }
    if (*(s32 *)((u8 *)widget + 0x258) == 0) {
        goto done;
    }
    movie = fn_802ECF08(*(s32 *)((u8 *)widget + 0x258),
        *(u8 *)((u8 *)widget + 0x25C) == 0);
    *(s32 *)((u8 *)widget + 0x254) = movie;
    if (movie != 0) {
        goto done;
    }
    if (*(u8 *)((u8 *)widget + 0x25C) == 0) {
        goto done;
    }
    onMovieEnd = *(s32 (**)(void *))((u8 *)widget + 0x260);
    if ((onMovieEnd == 0) || (onMovieEnd(*(void **)((u8 *)widget + 0x264)) != 0)) {
        fn_802168BC(*(void **)((u8 *)widget + 0x264));
    }
    goto done;

active:
    if (*(u8 *)((u8 *)widget + 0x25C) != 0) {
        if (((s32 (*)(s32))fn_802ED040)(movie) != 0) {
            onMovieEnd = *(s32 (**)(void *))((u8 *)widget + 0x260);
            if ((onMovieEnd == 0) || (onMovieEnd(*(void **)((u8 *)widget + 0x264)) != 0)) {
                fn_802168BC(*(void **)((u8 *)widget + 0x264));
            }
        }
    }
    if (*(s32 *)((u8 *)widget + 0x258) != 0 &&
        ((s32 (*)(s32, s32))fn_802ECF90)(*(s32 *)((u8 *)widget + 0x254), *(s32 *)((u8 *)widget + 0x258)) == 0) {
        fn_802ECFF4(*(s32 *)((u8 *)widget + 0x254));
        fn_802E30C8(lbl_8033DA90, *(s32 *)((u8 *)widget + 0x258));
        *(s32 *)((u8 *)widget + 0x254) = fn_802ECF08(
            *(s32 *)((u8 *)widget + 0x258),
            *(u8 *)((u8 *)widget + 0x25C) == 0);
    }

done:
    if (*(s32 *)((u8 *)widget + 0x254) != 0) {
        ((void (*)(s32))fn_802ECFEC)(*(s32 *)((u8 *)widget + 0x254));
    }
}

/* Clean up a UI image widget: advance the global timers, then release the
 * image resource it holds (if any). */
extern "C" void fn_80224160(void *widget) {
#define tickGlobalTimers fn_80219354
#define releaseImageResource fn_802ECFEC
    s32 imageRes;
    tickGlobalTimers();
    imageRes = *(s32 *)((u8 *)widget + 0x254);
    if (imageRes != 0) {
        ((void (*)(s32))releaseImageResource)(imageRes);
    }
#undef releaseImageResource
#undef tickGlobalTimers
}

extern "C" void fn_802ED038(s32, f32, f32, f32, f32);
extern "C" void fn_802ECFEC(void);
extern "C" void *lbl_8033E2CC[];
extern "C" void fn_8022419C(void *self) {
    /* If this image widget owns a resource at +0x254, forward it along with the
     * cached position/size floats at +0x244..+0x250 to the update wrapper. */
    s32 resource = *(s32 *)((u8 *)self + 0x254);
    if (resource)
        fn_802ED038(resource, *(f32 *)((u8 *)self + 0x244), *(f32 *)((u8 *)self + 0x248), *(f32 *)((u8 *)self + 0x24C), *(f32 *)((u8 *)self + 0x250));
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

/* Destructor for a UI image object: restores its vtable, releases the owned image resource, resets base state, and optionally deletes the object. */
extern "C" void *fn_802242A4(void *self, s32 deleteFlag) {
    s32 ownedResource;
    if (self) {
        ownedResource = *(s32 *)((u8 *)self + 0x254);
        *(void ***)self = lbl_8033E2CC;
        if (ownedResource)
            fn_802C519C((void *)ownedResource);
        *(s32 *)((u8 *)self + 0x254) = 0;
        fn_8021915C(self, 0);
        if (deleteFlag > 0)
            fn_80128668(self);
    }
    return self;
}

/* Draw this UI image's owned resource (the handle at +0x254), if present,
 * using the cached position/size floats at +0x244..+0x250 and z=0
 * (lbl_805634A8) through the image draw wrapper fn_802C5320. */
extern "C" void fn_80224328(void *self) {
    s32 resource = *(s32 *)((u8 *)self + 0x254);
    if (resource)
        fn_802C5320(resource, 0, *(f32 *)((u8 *)self + 0x244), *(f32 *)((u8 *)self + 0x248), lbl_805634A8, *(f32 *)((u8 *)self + 0x24C), *(f32 *)((u8 *)self + 0x250));
}

#pragma push
#pragma fp_contract on
extern "C" void *fn_8022435C(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 *arg4, void *unused) {
    register u8 *resource = (u8 *)arg2;
    register u8 *self = (u8 *)arg0;
    register s32 initial = arg1;
    register s32 length = arg3;
    register s32 *link = arg4;
    register s32 scratch;
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
    scratch = 0;
    *(s32 *)(self + 0x258) = scratch;
    *(s32 *)(self + 0x25c) = length;
    *(s32 *)(self + 0x250) = initial;
    s32 flags = *(s32 *)(resource + 0x9c);
    s32 sign = flags >> 31;
    *(s32 *)(self + 0x264) = (flags ^ sign) - sign;

    *(void **)(self + 0x284) = fn_8022EE9C();
    *(void **)(self + 0x288) = fn_8022EE9C();
    *(f32 *)(self + 0x24c) = lbl_805634A8;

    if (link != 0) {
        scratch = *link;
        *(s32 *)(self + 0x244) = scratch;
        strcpy(name, (char *)(resource + 0x40));
        s32 handle = ((s32 (*)(void *))fn_802C5130)(name);
        *(s32 *)(self + 0x280) = handle;
        if (handle == 0)
            fn_802E30C8(lbl_8033DABC, name);
    }
    return self;
}
#pragma pop
/* Destructor: reset vtable, release owned resources, destroy base, and optionally delete self. */
extern "C" void *fn_802244C8(void *self, s32 shouldDelete) {
    if (self != 0) {
        void *ownedPtr = *(void **)((u8 *)self + 0x280);
        *(void **)self = lbl_8033E248;
        if (ownedPtr != 0)
            fn_802C519C(ownedPtr);
        *(void **)((u8 *)self + 0x280) = 0;
        fn_8022EE98(*(void **)((u8 *)self + 0x288));
        fn_8022EE98(*(void **)((u8 *)self + 0x284));
        fn_8021915C(self, 0);
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}

extern "C" void fn_8022455C(void *arg0) {
    /* Register the widget's notify slot (key 0x254) in its table and save its previous 4-byte value
       as a "WidgetNotify::old_data" record (tag 0) so the change can be observed/notified. */
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
    u8 wasActive = *(u8 *)((u8 *)arg0 + 0x260);

    if (wasActive == 0) {
        if (*(s32 *)((u8 *)arg0 + 0x254) ==
            *(volatile s32 *)*(volatile s32 **)((u8 *)arg0 + 0x258)) {
            *(u8 *)((u8 *)arg0 + 0x261) = 0;
            *(u8 *)((u8 *)arg0 + 0x260) = 1;
            goto after_state_update;
        }
    }
    if (wasActive != 0) {
        if (*(s32 *)((u8 *)arg0 + 0x254) !=
            *(volatile s32 *)*(volatile s32 **)((u8 *)arg0 + 0x258)) {
            *(u8 *)((u8 *)arg0 + 0x260) = 0;
            *(u8 *)((u8 *)arg0 + 0x261) = 1;
        }
    }
after_state_update:
    /* Sample current time and refresh cached value from +0x268. */
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

extern "C" s32 fn_80224B0C(void *widget, s32 action) {
    /* Return whether this action is handled, but only while the tracked object id still matches. */
    void *tracking = *(void **)((u8 *)widget + 0x258);
    if (tracking != 0 && *(s32 *)((u8 *)widget + 0x254) != *(s32 *)tracking)
        return 0;
    return action == 0xD || (u32)action == 0x126 || (u32)action == 0x128;
}

#pragma push
#pragma opt_propagation off
extern "C" void *fn_80224B54(void *arg0, void *arg1, void *arg2) {
    u8 *self = (u8 *)arg0;
    s32 first;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ((void *(*)(void *, void *))fn_80218F80)((void *)self, arg2);
    *(void **)self = lbl_8033E1C4;
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
    if (!((f32)FN8021C18C_ABS((double)sp10) <= *(f32 *)&lbl_80558DC4) ||
        !((f32)FN8021C18C_ABS((double)spC) <= *(f32 *)&lbl_80558DC4) ||
        !((f32)FN8021C18C_ABS((double)sp8) <= *(f32 *)&lbl_80558DC4)) {
        fn_80224DDC((void *)self, sp10, spC, sp8);
    }
    return (void *)self;
}
#pragma pop
extern "C" void *fn_80224D40(void *obj, s32 deleteFlags) {
    // Destructor-like cleanup: reset vtable, conditionally destroy owned subobjects, clear fields, reset string/base, optional delete.
    if (obj != 0) {
        u8 ownsSubobject = *(u8 *)((u8 *)obj + 0x299);

        *(void **)obj = lbl_8033E1C4;
        if (ownsSubobject != 0) {
            fn_8022EE98(*(void **)((u8 *)obj + 0x29C));
        }

        fn_802328D4(*(void **)((u8 *)obj + 0x248));
        *(s32 *)((u8 *)obj + 0x248) = 0;

        char *nameDst = (char *)obj + 0x259;
        char *emptyStr = (char *)&lbl_8055B88C;
        *(s32 *)((u8 *)obj + 0x244) = 0;
        strcpy(nameDst, emptyStr);

        fn_8021915C(obj, 0);
        if (deleteFlags > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
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
    f32 half = lbl_805634C4;
    f32 inv = lbl_80563544;
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
        f32 x = (f32)W / inv + xx;
        f32 y = (f32)H * half - ((f32)f31 + (f32)row * (TB(0x254, f32) * (f32)fn_80232B70(TB(0x248, s32))));
        row++;
        if (TB(0x258, u8) == 0 && y < (f32)H * half - (hf + (f32)TB(8, s32))) {
            fn_80232BA4((char *)this_ + 0x259, TB(0x248, s32), TB(0x24C, s32), 10, x + hh, y, TB(0x254, f32) - lbl_805634B0, lbl_805634A8, lbl_805634A4);
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
#define ScrollList_vtable lbl_8033E140 /* vtable of the scrolling list widget; its
                                        * deleting destructor is slot 0x8 */
extern f32 lbl_80563544;
extern f32 lbl_805634E0;
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_8022553C(void *arg0, void *arg1, void *arg2) {
u8 *obj = (u8 *)arg0;
u8 *ctx = (u8 *)arg2;
s32 count;
s32 offset;
s32 row;
s32 frame;
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
*(f32 *)(obj + 0x254) = (f32)*(s32 *)(obj + 4) + temp_f3;
temp_f2 = (f32)lbl_8055FBA0;
temp_f1 = temp_f2 * lbl_805634C4;
*(f32 *)(obj + 0x258) = temp_f1 - (f32)*(s32 *)(obj + 8);
*(f32 *)(obj + 0x25C) = (f32)fn_80232B70(*(s32 *)(obj + 0x248)) + lbl_805634E0;
value = *(f32 *)(obj + 0x25C) * (f32)*(s32 *)(*(s32 *)(obj + 0x244) + 8);
half = lbl_805634C4 * value;
*(f32 *)(obj + 0x260) = value;
*(f32 *)(obj + 0x264) = *(f32 *)(obj + 0x258) + half;
*(f32 *)(obj + 0x268) = *(f32 *)(obj + 0x258) - half;
*(s32 *)(obj + 0x278) = fn_8012850C((void *)(*(s32 *)(*(s32 *)(obj + 0x244) + 8) * 0xC), (const char *)lbl_8033DAEC);
count = *(s32 *)(*(s32 *)(obj + 0x244) + 0xC);
offset = count * 0xC;
row = count;
frame = 0;
while (row < *(s32 *)(*(s32 *)(obj + 0x244) + 8)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) = *(f32 *)(obj + 0x258) - *(f32 *)(obj + 0x25C) * (f32)frame;
if (*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) < *(f32 *)(obj + 0x268)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) = *(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) + *(f32 *)(obj + 0x260);
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
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) = *(f32 *)(obj + 0x258) - *(f32 *)(obj + 0x25C) * (f32)frame;
if (*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) < *(f32 *)(obj + 0x268)) {
*(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) = *(f32 *)((u8 *)*(s32 *)(obj + 0x278) + offset) + *(f32 *)(obj + 0x260);
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

/* Deleting destructor of the scrolling text-list widget fn_8022553C builds (this
 * is slot 0x8 of ScrollList_vtable): frees the row table it allocated, releases
 * the text resource it borrowed, drops its row-table pointer, runs the base
 * class's destructor and, when called through delete (deleting > 0), frees the
 * object itself. */
extern "C" void *fn_80225828(void *self, s32 deleting) {
    ScrollList *list = (ScrollList *)self;

    if (self != 0) {
        ScrollRow *rows = list->rows;
        *(void **)self = ScrollList_vtable;
        if (rows != 0) {
            fn_80128670((s32)rows);
        }
        void *fontRes = list->fontRes;
        list->rows = 0;
        if (fontRes != 0) {
            fn_802328D4(fontRes);
        }
        list->fontRes = 0;
        list->rowTable = 0;
        fn_8021915C(self, 0);
        if (deleting > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

extern "C" void fn_802258C8(void *arg0) {
    /* Register the object at +0x280 in the table at +0x2C and append a copy of it to the entry list. */
    void *entry;

    entry = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C), *(s32 *)((u8 *)arg0 + 0x280), arg0);
    *(void **)((u8 *)arg0 + 0x27C) = entry;
    fn_80219440(arg0, 1, entry, 4);
}

#pragma pop
extern "C" void fn_80225918(void *arg0) {
    fn_802192AC(arg0);
}

extern "C" f32 lbl_80563548;

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

extern "C" f32 lbl_8056354C;
extern "C" f32 lbl_80563550;
extern "C" f32 lbl_80563554;
extern "C" f32 lbl_80563558;
extern "C" f32 lbl_8056355C;
extern "C" f64 lbl_80563520;
extern "C" int fn_8022DC68(void *, int);
extern "C" void fn_80233600(u8 *, s32, s32, s32, f32, f32, f32);
extern "C" void fn_8022591C(void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80225B6C(void *arg0) {
    u8 *o = (u8 *)arg0;
    f32 sp68[9];
    f32 sp44v, sp48v, sp4Cv, sp50v;
    s32 sp54v;
    f32 sp58v, sp5Cv, sp60v, sp64v;
    u8 sp14v[9], sp8v[9];
    f32 sp20v;
    s32 sp24v, sp28v, sp2Cv, sp30v, sp34v, sp38v, sp3Cv, sp40v;
    f32 *tab = (f32 *)&lbl_802F9EE0;
    fn_8022591C(arg0);
    if (*(u8 *)(o + 0x1B) == 0) {
        if ((f32)FN8021C18C_ABS((double)*(f32 *)(o + 0x26C)) <= *(f32 *)&lbl_80558DC4 || fn_8023659C() < *(f32 *)(o + 0x270)) *(f32 *)(o + 0x270) = fn_8023659C();
        f32 v = lbl_805634A4;
        f32 t = *(f32 *)(o + 0x26C) + lbl_80563534 * (fn_8023659C() - *(f32 *)(o + 0x270));
        v = (v < t) ? v : t;
        v = (v > lbl_8056354C) ? v : lbl_8056354C;
        *(f32 *)(o + 0x26C) = v;
        *(f32 *)(o + 0x270) = fn_8023659C();
    } else {
        if ((f32)FN8021C18C_ABS((double)(*(f32 *)(o + 0x26C) - lbl_805634A4)) <= *(f32 *)&lbl_80558DC4 || fn_8023659C() < *(f32 *)(o + 0x270)) *(f32 *)(o + 0x270) = fn_8023659C();
        f32 v = lbl_80563550;
        f32 t = *(f32 *)(o + 0x26C) - lbl_80563534 * (fn_8023659C() - *(f32 *)(o + 0x270));
        v = (v < t) ? v : t;
        v = (v > lbl_805634A8) ? v : lbl_805634A8;
        *(f32 *)(o + 0x26C) = v;
        *(f32 *)(o + 0x270) = fn_8023659C();
    }
    f32 f11 = *(f32 *)(o + 0x258);
    f32 f3 = *(f32 *)(o + 0x25C);
    f32 f4 = lbl_80563534 * f3;
    f32 f2 = lbl_80563514 * f3;
    f32 f03 = lbl_805634EC * f3;
    sp44v = tab[5]; sp48v = tab[6]; sp4Cv = tab[7]; sp50v = tab[8];
    sp54v = *(s32 *)&tab[9];
    sp58v = tab[10]; sp5Cv = tab[11]; sp60v = tab[12]; sp64v = tab[13];
    sp68[0] = f11 + f4; sp68[1] = f11 + f2; sp68[2] = f11 + f03; sp68[3] = f11 + f3; sp68[4] = f11;
    sp68[5] = f11 - f3; sp68[6] = f11 - f03; sp68[7] = f11 - f2; sp68[8] = f11 - f4;
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_80563514) / v; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp44v = lbl_805634A8 + v * lbl_80563504; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_805634EC) / v; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp48v = lbl_805634A8 + v * lbl_80563504; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - v) * lbl_805634C4; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp4Cv = lbl_805634A8 + v * lbl_80563554; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_805634A8) / lbl_80563514; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp50v = lbl_805634A8 + v * lbl_80563558; }
    sp54v = *(s32 *)&tab[9];
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_805634A8) / lbl_80563514; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp58v = lbl_805634A8 + v * lbl_80563558; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - v) * lbl_805634C4; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp5Cv = lbl_805634A8 + v * lbl_80563554; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_805634EC) / v; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp60v = lbl_805634A8 + v * lbl_80563504; }
    { f32 v = lbl_805634A4; f32 t = ((f32)*(s32 *)(o + 0x24C) - lbl_80563514) / v; v = (v < t) ? v : t; v = (v > lbl_805634A8) ? v : lbl_805634A8; sp64v = lbl_805634A8 + v * lbl_80563504; }
    u8 *srcTable = (u8 *)&lbl_802F9EE0 + 0x38;
    u8 *srcTable2 = (u8 *)&lbl_802F9EE0 + 0x44;
    for (s32 i = 0; i < 9; i++) { sp14v[i] = srcTable[i]; sp8v[i] = srcTable2[i]; }
    sp20v = *(f32 *)((u8 *)&lbl_802F9EE0 + 0x50);
    sp24v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x54); sp28v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x58);
    sp2Cv = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x5C); sp30v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x60);
    sp34v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x64); sp38v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x68);
    sp3Cv = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x6C); sp40v = *(s32 *)((u8 *)&lbl_802F9EE0 + 0x70);
    s32 swapped = 0;
    if (*(s32 **)(o + 0x27C) != 0 && *(s32 *)(o + 0x280) != **(s32 **)(o + 0x27C)) swapped = 1;
    u8 *useC = swapped ? sp8v : sp14v;
    f32 *useB = swapped ? &sp20v : &sp44v;
    s32 cnt;
    for (cnt = 0; cnt < *(s32 *)((u8 *)*(void **)(o + 0x244) + 8); cnt++) {
        f32 v = *(f32 *)((u8 *)*(void **)(o + 0x278) + cnt * 4);
        if (!((f32)FN8021C18C_ABS((double)(v - *(f32 *)(o + 0x258))) > lbl_805634C4 + lbl_80563514 * *(f32 *)(o + 0x25C))) { (void)useC; (void)useB; }
    }
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
#define selfStatePtr  (*(s32 **)((u8 *)arg0 + 0x27C))
#define selfStateId   (*(s32 *)((u8 *)arg0 + 0x280))
    /* Return true for accepted command IDs when the linked state object matches this instance. */
    s32 *statePtr = selfStatePtr;
    if (statePtr != 0 && selfStateId != *statePtr)
        return 0;
    return arg1 == 0xD || (u32)arg1 == 0x126 || (u32)arg1 == 0x128;
#undef selfStatePtr
#undef selfStateId
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

extern "C" void *fn_80226630(void *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    /* Constructor: initialize base (fn_802224B4), set vtable, cache computed value at +0x260 and clear +0x264. */
    fn_802224B4(self, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 1, 0);
    *(void **)self = (void *)&lbl_8033F7F4;
    *(s32 *)((u8 *)self + 0x260) = fn_80228F40(arg2, arg3);
    *(s32 *)((u8 *)self + 0x264) = 0;
    return self;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802266B0(void *self, s32 shouldDelete) {
    /* Scalar deleting destructor: destroy contents, then free this object when requested. */
    if (self != 0) {
        fn_802223C4(self, 0);
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}

// Loads an object resource and registers it with the owner at a fixed slot.
extern "C" void fn_80226708(void *arg0) {
    void *result;
    result = fn_80217BD8(*(s32 *)((u8 *)arg0 + 0x2C), *(s32 *)((u8 *)arg0 + 0x260), arg0);
    *(void **)((u8 *)arg0 + 0x264) = result;
    fn_80219440(arg0, 1, result, 4);
}

extern "C" void fn_80226758(void *self) {
    /* Update the id this object tracks (+0x264) to its cached value (+0x260). */
    s32 value = *(s32 *)((u8 *)self + 0x260);
    s32 *tracked = *(s32 **)((u8 *)self + 0x264);
    *tracked = value;
}

extern "C" void fn_80226768(void *self) {
    /* If active (+0x18) and the optional callback at +0x258 allows it, notify via fn_802168BC with the value at +0x25C. */
    s32 (*callback)(s32);
    if (*(u8 *)((u8 *)self + 0x18) != 0) {
        callback = *(s32 (**)(s32))((u8 *)self + 0x258);
        if (callback == 0 || callback(*(s32 *)((u8 *)self + 0x25C)) != 0)
            fn_802168BC((void *)*(s32 *)((u8 *)self + 0x25C));
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

/* Returns 1 if arg1 is an accepted command id (0xD, 0x126, 0x128), but first
 * rejects (returns 0) when the object's state pointer at +0x264 is set and its
 * value differs from the current state id stored at +0x260.
 */
extern "C" s32 fn_802268A0(void *arg0, s32 commandId) {
    s32 *statePtr = *(s32 **)((u8 *)arg0 + 0x264);
    if (statePtr != 0 && *(s32 *)((u8 *)arg0 + 0x260) != *statePtr)
        return 0;
    return commandId == 0xD || (u32)commandId == 0x126 || (u32)commandId == 0x128;
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
/* Set up a "RotImage" UI element: resolve its named image, grab a draw region,
 * compute centering offsets from its size, and position the region from the
 * current f28() value using a half scale. */
extern "C" void *fn_802269A8(void *obj, void *param) {
    #define ROT_VTABLE   lbl_8033E0BC
    #define ROT_ERR_MSG  lbl_8033DAF8   /* "RotImage: couldn't find image %s!" */
    #define ROT_SCALE    lbl_805634C4   /* 0.5f */

    class Obj28 { public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
        virtual void f25(); virtual void f26(); virtual void f27(); virtual s32 f28();
        s32 width; s32 height; s32 padC; s32 total; u8 pad14[0x230];
        s32 result; void *region; f32 coords[2]; f32 diff; f32 elapsedTime; s32 count;
    };
    register Obj28 *image = (Obj28 *)obj;
    fn_80218F80();
    *(void **)image = ROT_VTABLE;
    if ((image->result = ((s32 (*)(void *))fn_802C5130)((u8 *)param + 0x40)) == 0)
        fn_802E30C8(ROT_ERR_MSG, (u8 *)((u32)param + 0x40));
    image->region = fn_8022EE9C();
    fn_80230C30(&image->coords[0], &image->coords[1], image->width, image->height);
    image->diff = (f32)(image->total - image->height);
    struct { f32 value; } scaleStorage;
    f32 &factor = scaleStorage.value;
    f32 elapsedNow;
    elapsedNow = (f32)image->f28();
    factor = ROT_SCALE;
    image->elapsedTime = elapsedNow;
    *(f32 *)((u8 *)image->region + 0x24) = image->coords[0] + elapsedNow * factor;
    *(f32 *)((u8 *)image->region + 0x28) = image->coords[1] - image->diff * factor;
    image->count = *(s32 *)((u8 *)param + 0x9C);
    return obj;

    #undef ROT_VTABLE
    #undef ROT_ERR_MSG
    #undef ROT_SCALE
}

extern "C" void *fn_80226AD0(void *arg0, s32 arg1) {
    /* Scalar deleting destructor for the lbl_8033E0BC class: release owned
     * resources at +0x248/+0x244, run the base destructor, and optionally
     * free storage. */
    if (arg0 != 0) {
        void *resource248 = *(void **)((u8 *)arg0 + 0x248);
        *(void **)arg0 = lbl_8033E0BC;
        if (resource248 != 0)
            fn_8022EE98(resource248);
        *(void **)((u8 *)arg0 + 0x248) = 0;

        void *resource244 = *(void **)((u8 *)arg0 + 0x244);
        if (resource244 != 0)
            fn_802C519C(resource244);
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
extern "C" void *fn_80226F00(void *self, s32 shouldDelete) {
    /* Deleting destructor: restore vtable lbl_8033E038, release optional resource at +0x25C when flag +0x260 is set (fn_8022EE98), release object at +0x244 (fn_80235380) and clear it, run base destructor fn_8021915C, then free if shouldDelete > 0. */
    if (self != 0) {
        *(void **)self = &lbl_8033E038;
        if (*(u8 *)((u8 *)self + 0x260) != 0)
            fn_8022EE98(*(void **)((u8 *)self + 0x25C));
        void *old = *(void **)((u8 *)self + 0x244);
        if (old != 0)
            fn_80235380(old);
        *(volatile s32 *)((u8 *)self + 0x244) = 0;
        fn_8021915C(self, 0);
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
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
    register u8 *obj = (u8 *)arg0;
    register s32 context = (s32)arg1;

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
extern "C" void *fn_80227244(void *object, s32 shouldFree) {
    /* Widget destructor: reinstall vtable lbl_8033DFB4, release the buffer at +0x260
       and the handle at +0x254, run the base destructor, then free on request. */
    if (object != 0) {
        *(void **)object = &lbl_8033DFB4;
        fn_8022EE98(*(void **)((u8 *)object + 0x260));
        s32 handle = *(s32 *)((u8 *)object + 0x254);
        if (handle != -2 && handle != -1)
            ((void (*)(int))fn_802CAC54)(handle);
        *(s32 *)((u8 *)object + 0x254) = -1;
        fn_8021915C(object, 0);
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

extern "C" f32 lbl_805634C4;
extern "C" f32 lbl_805634E8;
extern "C" f32 lbl_805634FC;
extern "C" f32 lbl_80563560;
#pragma dont_inline off
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
            f32 tmp = *(f32 *)(p + 0x268) + d;
            *(f32 *)(p + 0x268) = tmp;
            if (tmp > 1.0f) {
                *(f32 *)(p + 0x268) = 1.0f;
                *(u8 *)(p + 0x264) = 0;
            }
        } else {
            f32 tmp = *(f32 *)(p + 0x268) - d;
            *(f32 *)(p + 0x268) = tmp;
            if (tmp < 0.0f) {
                *(f32 *)(p + 0x268) = 0.0f;
                *(u8 *)(p + 0x264) = 1;
            }
        }
        f32 *m = *(f32 **)(p + 0x260);
        m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f; m[3] = 0.0f; m[4] = 1.0f; m[5] = 0.0f; m[6] = 0.0f; m[7] = 0.0f; m[8] = 1.0f; m[9] = 0.0f; m[10] = 0.0f; m[11] = 0.0f;
        v.z = 0.0f;
        v.x = (f32)-lbl_8055FB9C * lbl_805634C4;
        v.y = (f32)-lbl_8055FBA0 * lbl_805634C4;
        m = *(f32 **)(p + 0x260);
        Rot3Vec(m, (RotV3 *)(u32)&v, (RotV3 *)(u32)&r);
        m[9] += r.x; m[10] += r.y; m[11] += r.z;
        if (*(u8 *)(p + 0x270) != 0) {
            *(f32 *)(p + 0x26C) = *(f32 *)(p + 0x26C) - (now - *(f32 *)(p + 0x25C)) / lbl_805634E4;
        } else {
            *(f32 *)(p + 0x26C) = *(f32 *)(p + 0x26C) + (now - *(f32 *)(p + 0x25C)) / lbl_805634FC;
        }
        v.x = 0.0f; v.y = 0.0f; v.z = *(f32 *)(p + 0x26C);
        void *h = *(void **)(p + 0x260);
        ((void (*)(void *, f32 *))fn_80015A20)(sp2C, &v.x);
        fn_80015B20(h, sp2C, h);
        v.z = 0.0f;
        v.x = (f32)lbl_8055FB9C * lbl_805634C4;
        v.y = (f32)lbl_8055FBA0 * lbl_805634C4;
        m = *(f32 **)(p + 0x260);
        Rot3Vec(m, (RotV3 *)(u32)&v, (RotV3 *)(u32)&t);
        m[9] += t.x; m[10] += t.y; m[11] += t.z;
        *(f32 *)(*(u8 **)(p + 0x260) + 0x30) = lbl_805634E8 + lbl_80563560 * *(f32 *)(p + 0x268);
        fn_8022ED00(*(void **)(p + 0x260));
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244), *(f32 *)(p + 0x248), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), 0.0f, 0.0f, 1.0f, 1.0f);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244) - (f32)lbl_8055FB9C, *(f32 *)(p + 0x248), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), 0.0f, 0.0f, 1.0f, 1.0f);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244), *(f32 *)(p + 0x248) - (lbl_805634E4 + (f32)lbl_8055FBA0), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), 0.0f, 0.0f, 1.0f, 1.0f);
        fn_80231220(*(s32 *)(p + 0x254), -1, *(f32 *)(p + 0x244) - (f32)lbl_8055FB9C, *(f32 *)(p + 0x248) - (lbl_805634E4 + (f32)lbl_8055FBA0), *(f32 *)(p + 0x24C), *(f32 *)(p + 0x250), 0.0f, 0.0f, 1.0f, 1.0f);
        fn_8022EDB8();
    }
    *(f32 *)(p + 0x25C) = now;
}
extern "C" void fn_80227880(s32 unused, f32 x, f32 y, f32 width, f32 height) {
    /* Draw a filled rectangle (x,y)-(x+width,y-height) with two passes: light overlay then dark overlay. */
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
            f32 temp_f26 = lbl_805634A4;
            f32 var_f25 = lbl_805634A8;
            s32 var_r31 = 8;
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

extern "C" void fn_80227C9C(s32 unused, f32 x, f32 y, f32 width, f32 height) {
    /* Draw a filled background and its border for the same rectangle. */
    fn_80227880(unused, x, y, width, height);
    fn_802278F0(unused, x, y, width, height);
}

extern "C" void *fn_80227D00(void *object) {
    /* Construct a TabItemBox object: run base init, install its vtable, load box artwork, and warn on failure. */
    s32 result;
    void *vtable;

    fn_80218F80();
    vtable = lbl_8033DEAC;
    *(void **)object = vtable;
    result = ((s32 (*)(void *, void *))fn_8023512C)(lbl_8033DC4C, lbl_8033DEAC);
    *(s32 *)((u8 *)object + 0x244) = result;
    if (result == 0)
        fn_802E30C8(lbl_8033DC58);
    return object;
}

/* Destructor-like cleanup: installs vtable, releases owned object at +0x244, runs base destructor, optionally frees self. */
extern "C" void *fn_80227D64(void *self, s32 deleteFlag) {
    s32 ownedObject;
    if (self) {
        ownedObject = *(s32 *)((u8 *)self + 0x244);
        *(void ***)self = lbl_8033DEAC;
        if (ownedObject)
            fn_80235380((void *)ownedObject);
        *(s32 *)((u8 *)self + 0x244) = 0;
        fn_8021915C(self, 0);
        if (deleteFlag > 0)
            fn_80128668(self);
    }
    return self;
}

#pragma scheduling reset
extern "C" void fn_80227DE8(void *arg0) {
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
    f32 spC;
    f32 sp8;
    fn_80230C30(&spC, &sp8, *(s32 *)((char *)arg0 + 4), *(s32 *)((char *)arg0 + 8));
    fn_80227C9C(*(s32 *)((char *)arg0 + 0x244), spC, sp8,
                (f32)((LocalObject *)arg0)->At78(),
                (f32)(*(s32 *)((char *)arg0 + 0x10) - *(s32 *)((char *)arg0 + 8)));
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
s32 index;
f32 radiusScale = radius * scale;
f32 step = lbl_80563570 + initial;
f32 charWidthDefault = lbl_805634A8;
for (index = 0; index < count; index++) {
s32 isLast = index == lastIndex;
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
}
}
f32 endPos = lbl_8056356C + spC;
f32 negTop = sp8 + negRadius;
s32 virtualInt = ((VfObj*)arg0)->vf28();
f32 virtualPos = (f32)virtualInt;
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

/* Destructor-like teardown: release owned movie handle/resources, run base dtor, optionally free. */
extern "C" void *fn_802284BC(void *obj, s32 shouldFree) {
    if (obj) {
        *(void **)obj = lbl_8033DE28;
        fn_8023986C(*(s32 *)((u8 *)obj + 0x244));
        if (*(u8 *)((u8 *)obj + 0x248))
            fn_8023967C(*(s32 *)((u8 *)obj + 0x244), 1);
        *(s32 *)((u8 *)obj + 0x244) = 0;
        register void *self = obj;
        fn_8021915C(self, 0);
        if (shouldFree > 0)
            fn_80128668(obj);
    }
    return obj;
}

// Draw the current frame of the SWF animation this UI element owns (state handle at +0x244).
extern "C" void fn_8022854C(void *obj){fn_8023976C(*(s32*)((u8*)obj+0x244));}

extern "C" void fn_802396BC(s32);
// Advance the SWF animation this UI element owns (state handle at +0x244) to its next frame.
extern "C" void fn_80228554(void *obj){fn_802396BC(*(s32*)((u8*)obj+0x244));}

extern "C" void *fn_8022855C(void *obj, void *config, s32 value244, s32 value248)
{
    /* Constructor/init: runs base fn_80218F80(obj, config) via the file's no-arg macro,
     * stores value244 at +0x244, installs vtable lbl_8033DDA4, stores value248 at +0x248. */
    fn_80218F80();
    *(s32 *)((u8 *)obj + 0x244) = value244;
    *(void **)obj = lbl_8033DDA4;
    *(s32 *)((u8 *)obj + 0x248) = value248;
    return (void *)((char *)obj + 0);
}

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
extern "C" void *fn_802286E4(void *widget, void *config, s32 field244) {
    void *modelView;
    u32 itemCount;

    /* Initialize a spinning 3D-model-view text widget: install its vtable,
       clear its state, and allocate the ModelView subobject it owns at +0x268.
       The subobject gets an identity transform, an mrModel handle loaded from
       config (+0x40) when present, and a spin speed of 2*pi / item count. */
    fn_80218F80();
    *(s32 *)((u8 *)widget + 0x244) = field244;
    *(void **)((u8 *)widget + 0x268) = 0;
    *(void **)widget = lbl_8033DD20;
    *(u8 *)((u8 *)widget + 0x26C) = 0;
    memset((u8 *)widget + 0x248, 0, 0x20);

    modelView = (void *)fn_801284F8(0x40, lbl_8033DCE8);
    if (modelView != 0) {
        f32 initialSpin = lbl_805634A8;
        f32 identityZero, identityOne;
        *(void **)modelView = lbl_8033DCF8;
        *(s32 *)((u8 *)modelView + 4) = -1;
        *(f32 *)((u8 *)modelView + 0x38) = initialSpin;
        *(f32 *)((u8 *)modelView + 0x3C) = initialSpin;
        if (fn_8012C33C((u8 *)config + 0x40) != 0)
            *(s32 *)((u8 *)modelView + 4) = fn_802C6FC0((void *)((s32)config + 0x40), 0, 0);

        itemCount = *(u32 *)((u8 *)config + 0x9C);
        if (itemCount != 0) {
            f32 denominator = (f32)itemCount;
            f32 spinSpeed = lbl_805634D8 / denominator;
            *(f32 *)((u8 *)modelView + 0x3C) = spinSpeed;
        }

        identityOne = lbl_805634A4;
        identityZero = lbl_805634A8;
        *(f32 *)((u8 *)modelView + 8) = identityOne;
        *(f32 *)((u8 *)modelView + 0xC) = identityZero;
        *(f32 *)((u8 *)modelView + 0x10) = identityZero;
        *(f32 *)((u8 *)modelView + 0x14) = identityZero;
        *(f32 *)((u8 *)modelView + 0x18) = identityOne;
        *(f32 *)((u8 *)modelView + 0x1C) = identityZero;
        *(f32 *)((u8 *)modelView + 0x20) = identityZero;
        *(f32 *)((u8 *)modelView + 0x24) = identityZero;
        *(f32 *)((u8 *)modelView + 0x28) = identityOne;
        *(f32 *)((u8 *)modelView + 0x2C) = identityZero;
        *(f32 *)((u8 *)modelView + 0x30) = identityZero;
        *(f32 *)((u8 *)modelView + 0x34) = identityZero;
    }

    *(void **)((u8 *)widget + 0x268) = modelView;
    *(u8 *)((u8 *)widget + 0x26C) = 1;
    return widget;
}
#pragma pop
extern "C" void *memset(void *, int, unsigned long);
extern "C" void *lbl_8033DD20[];
extern "C" s32 fn_8022882C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668((void *)object);
    return object;
}

extern "C" void *fn_8022886C(void *textBox, s32 unused, s32 modelView, s32 field244) {
    /* Initialize a J2DTextBox-derived widget with its model view and default state. */
    fn_80218F80();
    *(s32 *)((u8 *)textBox + 0x244) = field244;
    *(s32 *)textBox = (s32)lbl_8033DD20;
    *(s32 *)((u8 *)textBox + 0x268) = modelView;
    *(u8 *)((u8 *)textBox + 0x26C) = 0;
    memset((u8 *)textBox + 0x248, 0, 0x20);
    return textBox;
}

extern "C" void *__dt__10J2DTextBoxFv(void *self, s32 shouldDelete) {
    /* J2DTextBox destructor: release owned subobject (+0x268) if flagged (+0x26C), chain to base destructor, and optionally delete. */
    if (self != 0) {
        u8 ownsSubObject = *(u8 *)((u8 *)self + 0x26C);
        *(void ***)self = (void **)&lbl_8033DD20;
        if (ownsSubObject != 0) {
            void *subObject = *(void **)((u8 *)self + 0x268);
            if (subObject != 0) ((VfObjCall *)subObject)->vf2(1);
            *(void **)((u8 *)self + 0x268) = 0;
        }
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* Forward vf2 (vtable slot 0x10) to the child object held at +0x268. */
extern "C" void fn_8022897C(void *object) {
    ((VfObj *)*(void **)((u8 *)object + 0x268))->vf2();
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
/* Callback wrapper: invoke fn_80228AEC on the given object (passed as a raw
 * pointer), supplying the global float setting returned by fn_80214D48(). */
extern "C" void fn_80228A38(s32 object) {
    fn_80228AEC(object, fn_80214D48());
}

/* Forward vf4() to the child VfObj stored at +0x268 of the given container. */
extern "C" void fn_80228A6C(void *container) {
    void *child = *(void **)((u8 *)container + 0x268);
    ((VfObj *)child)->vf4();
}

extern "C" void fn_80228A80(void) {
}

/* Set a draw/color state from this object's parameters, invoke a virtual
   callback on its child object, then restore the previous state. */
extern "C" void fn_80228A84(void *object) {
    s32 mode = *(s32 *)((u8 *)object + 0x270);
    s32 savedState[2];
    fn_802C86F0(savedState, mode, *(s32 *)((u8 *)object + 0x274),
        *(s32 *)((u8 *)object + 0x278), *(s32 *)((u8 *)object + 0x27C));
    fn_802C88BC(2);
    ((VfObj *)*(void **)((u8 *)object + 0x268))->vf5();
    fn_802C8750(savedState, -1);
}

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

    var_f4 = lbl_805634A4;
    temp_f0 = ((f32)*(s32 *)(arg0 + 4) - lbl_805634A8) / lbl_8056357C;
    var_f4 = var_f4 < temp_f0 ? temp_f0 : var_f4;
    var_f4 = var_f4 > lbl_805634A8 ? lbl_805634A8 : var_f4;
    var_r4 = lbl_8055CFF0 - 2;
    temp_r0 = (s32)(lbl_805634A8 + (var_f4 * ((f32)lbl_8055CFF0 - lbl_805634A8)));
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

    temp_r30 = lbl_8055CFF0;
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
// Forward vf6() to the TruckIface stored at offset 0x268 of the given widget.
extern "C" void fn_80228D90(void *widget) {
    TruckIface *iface = *(TruckIface **)((u8 *)widget + 0x268);
    iface->vf6();
}

/* Default no-op virtual for this TruckIface widget: returns 0.  Sits among
   the vf6()/vf7() forwarding methods, supplying a zero for a query the base
   interface leaves unimplemented. */
extern "C" s32 fn_80228DA4(void) { return 0; }

// Forward vf7() to the TruckIface stored at offset 0x268 of the given widget.
extern "C" void fn_80228DAC(void *widget) {
    TruckIface *iface = *(TruckIface **)((u8 *)widget + 0x268);
    iface->vf7();
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

/* Pack a screen-grid position into a unique element id (1000 columns per row). */
extern "C" s32 fn_80228F40(s32 column, s32 row) {
    return column + row * 1000;
}

extern "C" void *fn_80223208(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228F4C(void *archive, int shouldDelete) {
    /* Destruct this MemorySoundArchive variant (via fn_80223208 base
     * destructor), deleting the object when shouldDelete > 0. */
    if (archive != 0) {
        fn_80223208(archive, 0);
        if (shouldDelete > 0) fn_80128668(archive);
    }
    return archive;
}

/* nw4hbm::snd::MemorySoundArchive deleting destructor: tears down base sound-archive state via fn_8021915C, then frees storage when deletingFlag > 0. (rename_symbol unavailable for mangled/game symbols) */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FA4(void *object, int deletingFlag) {
    if (object != 0) {
        fn_8021915C(object, 0);
        if (deletingFlag > 0) fn_80128668(object);
    }
    return object;
}

/* Scalar deleting destructor for nw4hbm::snd::MemorySoundArchive: runs the base
 * subobject destructor (fn_8021915C, deletingFlag 0) and, when deletingFlag > 0,
 * frees the object (fn_80128668 = operator delete, mode 3). Returns this_. */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FFC(void *this_, int deletingFlag) {
    if (this_ != 0) {
        fn_8021915C(this_, 0);
        if (deletingFlag > 0) fn_80128668(this_);
    }
    return this_;
}

/* Destroys a DisposeCallbackManager's base list (via fn_8021915C) and, if requested, frees the object storage. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229054(
    void* this_, s32 deleteFlag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (deleteFlag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* Deleting destructor for nw4hbm::snd::detail::DisposeCallbackManager. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802290B0(
    void* this_, s32 deletingFlag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* Deleting destructor for nw4hbm::snd::detail::DisposeCallbackManager. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022910C(
    void* this_, s32 deletingFlag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* nw4hbm::snd::detail::DisposeCallbackManager destructor helper:
 * destroys the base/subobject when non-null, then optionally frees storage. */
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

/* nw4hbm::snd::detail::DisposeCallbackManager destructor helper:
 * destroys the base/subobject when non-null, then optionally frees storage. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802291C4(
    void* object, s32 shouldDelete) {
    if (object) {
        if (object != NULL) {
            fn_8021915C(object, 0);
        }

        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

extern "C" void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229220(void *self, s32 deletingFlag) {
    /* nw4hbm::snd::detail::DisposeCallbackManager deleting destructor: run cleanup, then free storage if requested. */
    if (self) {
        if (self != NULL) {
            fn_8021915C(self, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

/* nw4hbm::snd::detail::DisposeCallbackManager destructor helper:
 * destroys the base/subobject when non-null, then optionally frees storage. */
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

/* Scalar deleting destructor for nw4hbm::snd::MemorySoundArchive: runs the base
 * subobject destructor (fn_8021915C, deletingFlag 0) and, when deletingFlag > 0,
 * frees the object (fn_80128668 = operator delete, mode 3). Returns this_. */
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802292D8(void *this_, int deletingFlag) {
    if (this_ != 0) {
        fn_8021915C(this_, 0);
        if (deletingFlag > 0) fn_80128668(this_);
    }
    return this_;
}

extern "C" void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229330(void *self, int shouldDelete) {
    /* Destroy an embedded LinkListImpl subobject and optionally delete storage. */
    if (self != 0) {
        __dt__Q46nw4hbm2ut6detail12LinkListImplFv(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80229388(void *self, int shouldDelete) {
    /* Scalar deleting destructor: destroy base/subobject, then free storage when requested. */
    if (self != 0) {
        fn_802223C4(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* nw4hbm::snd::detail::DisposeCallbackManager scalar deleting destructor.
 * Destroys the subobject via fn_8021915C when non-null, then frees storage
 * with fn_80128668 (operator delete, mode 3) if deletingFlag > 0. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802293E0(
    void* thisPtr, s32 deletingFlag) {
    if (thisPtr) {
        if (thisPtr != NULL) {
            fn_8021915C(thisPtr, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(thisPtr);
        }
    }
    return thisPtr;
}

/* nw4hbm::snd::detail::DisposeCallbackManager destructor helper:
 * destroys the base/subobject when non-null, then optionally frees storage. */
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

extern "C" void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229498(void *self, s32 deletingFlag) {
    /* nw4hbm::snd::detail::DisposeCallbackManager deleting destructor: run cleanup, then free storage if requested. */
    if (self) {
        if (self != NULL) {
            fn_8021915C(self, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

/* Deleting destructor for nw4hbm::snd::detail::DisposeCallbackManager. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802294F4(
    void* this_, s32 deletingFlag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma dont_inline on
/* Deleting destructor for nw4hbm::snd::detail::DisposeCallbackManager. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229550(
    void* self, s32 deletingFlag) {
    if (self) {
        if (self != NULL) {
            fn_802223C4(self, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}
#pragma dont_inline reset
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802295AC(void *this_, int flag) {
    /* nw4hbm::snd::MemorySoundArchive scalar-deleting destructor (802295AC):
       if non-null, run the base destructor fn_8021915C(this_, 0), then free
       storage with the deleting operator fn_80128668 when flag > 0. Returns
       this_. */
    if (this_ != 0) {
        fn_8021915C(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
}

/* Clear the byte flag at offset 0x24C of the given widget. */
extern "C" void fn_80229604(void *widget) {
    *(u8 *)((u8 *)widget + 0x24C) = 0;
}

extern "C" void fn_80229610(void) {
}

/* Default widget-manager callback: an always-true predicate, reporting success to its caller. */
extern "C" u32 fn_80229614(void) { return 1; }

extern "C" void fn_8022961C(void) {
}

/* Default widget-manager callback: an always-true predicate, reporting success to its caller. */
extern "C" u32 fn_80229620(void) { return 1; }

extern "C" void fn_80229628(void *widget) {
    /* Mark the widget busy (+0x254) and run its virtual update (vtable slot +0x84). */
    *(u8 *)((u8 *)widget + 0x254) = 1;
    ((VfObj *)widget)->vf31();
}

extern "C" void fn_80229640(void *self) {
    /* Update via vf31, clear busy flag (+0x254), and if enabled (+0x18) and the
     * value at +0x25C is not the sentinel (value + 0x20000 == 0xFB96), invoke an
     * optional callback at +0x258 (returning nonzero to proceed) then notify with
     * fn_802168BC(+0x25C). */
    s32 (*callback)();
    ((VfObj *)self)->vf31();
    *(u8 *)((u8 *)self + 0x254) = 0;
    if (*(u8 *)((u8 *)self + 0x18) == 0) return;
    if ((u32)(*(s32 *)((u8 *)self + 0x25C) + 0x20000) == 0xFB96) return;
    callback = *(s32 (**)())((u8 *)self + 0x258);
    if (callback != 0) {
        if (callback() == 0) return;
    }
    fn_802168BC((void *)*(s32 *)((u8 *)self + 0x25C));
}

extern "C" s32 fn_802296C0(void *self) {
    /* Return a player/archive state code based on flags and the linked player's f5() result. */
    class Obj5 {
    public:
        virtual s32 f0(); virtual s32 f1(); virtual s32 f2();
        virtual s32 f3(); virtual s32 f4(); virtual s32 f5();
    };
    void *player;
    u32 state;
    if ((u32)(*(s32 *)((u8 *)self + 0x25C) + 0x20000) != 0xFB96U) {
        if (*(u8 *)((u8 *)self + 0x18) != 0)
            state = (*(u8 *)((u8 *)self + 0x254) != 0) + 2;
        else
            state = 0;
    } else {
        state = 1;
    }
    player = *(void **)((u8 *)self + 0x244);
    if (((Obj5 *)player)->f5() == 3 && state == 3)
        state = 1;
    return state;
}

extern "C" void fn_802192AC(void *);
extern "C" void fn_80229750(void *self) {
    /* Turns this widget on: runs its virtual update (vtable slot +0x84) and then
     * sets its active flag (+0x18). fn_80229790 is the mirror that clears it. */
    struct VfWidget {
        VfObj obj;          /* 0x00: vtable; slot +0x84 updates the widget */
        u8 pad_0x4[0x14];
        u8 active;          /* 0x18: nonzero while the widget is turned on */
    };
    VfWidget *widget = (VfWidget *)self;

    widget->obj.vf31();
    widget->active = 1;
}

extern "C" void fn_80229790(void *self) {
    /* Turns this widget off: runs its virtual update (vtable slot +0x84) and then
     * clears its active flag (+0x18), the mirror image of fn_80229750. */
    struct VfWidget {
        VfObj obj;          /* 0x00: vtable; slot +0x84 updates the widget */
        u8 pad_0x4[0x14];
        u8 active;          /* 0x18: nonzero while the widget is turned on */
    };
    VfWidget *widget = (VfWidget *)self;

    widget->obj.vf31();
    widget->active = 0;
}

#pragma scheduling on
extern "C" void fn_802297D0(void *self) {
    /* If active/busy flags (+0x257, +0x254, +0x18) are set and the optional callback at +0x258
     * allows it, notifies via fn_802168BC with the status value at +0x25C, then updates tracked slots via fn_802192AC. */
    s32 (*callback)(s32);
    if (*(u8 *)((u8 *)self + 0x257) != 0 &&
        *(u8 *)((u8 *)self + 0x254) != 0 &&
        *(u8 *)((u8 *)self + 0x18) != 0) {
        callback = *(s32 (**)(s32))((u8 *)self + 0x258);
        if (callback == 0 || callback(*(s32 *)((u8 *)self + 0x25C)) != 0) {
            fn_802168BC((void *)*(s32 *)((u8 *)self + 0x25C));
        }
    }
    fn_802192AC(self);
}
extern "C" void fn_8022984C(void *widget) {
    /* Toggle the boolean flag this widget points to through its +0x254 field:
     * set it to 1 when clear, back to 0 when set. */
    u8 *flag = *(u8 **)((u8 *)widget + 0x254);
    *flag = (u8)((s8)(*flag == 0));
}

extern "C" void fn_80229864(void *widget) {
    /* Turn this VfWidget on: set its active flag (+0x18) and, when its layout
     * option (+0x1A) is set, mark it dirty (+0x234) so it gets redrawn. */
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 1;
}

// Deactivate a UI widget: clear its active flag (+0x18), and if it is still live
// (+0x1A) mark it dirty (+0x234) so the screen redraws it.
extern "C" void fn_80229884(void *widget) {
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 0;
}

extern "C" s32 fn_802298A4(s32 widget) {
    /* Field-offset helper: return a pointer to a UI widget's field at +0x258. */
    return widget + 0x258;
}

extern "C" s32 fn_802298AC(void *self) {
    /* Status bits: bit 1 (2) if this widget's active flag (+0x18) is set,
     * bit 0 (1) if the byte pointed to by +0x254 is nonzero. */
    s32 status = 0;
    if (*(u8 *)((char *)self + 0x18) != 0) {
        status = 2;
    }
    return (*(*(u8 **)((char *)self + 0x254)) != 0) | status;
}

extern "C" int fn_802298DC(void *widget) {
    /* Return the value pointed to by the widget's +0x254 field, or 0 if unset. */
    int *valuePtr = *(int **)((char *)widget + 0x254);
    if (valuePtr != 0) {
        return *valuePtr;
    }
    return 0;
}

extern "C" void fn_802298F8(void) {
}

extern "C" void fn_802298FC(void) {
}

/* Invokes the object's virtual Call callback with both arguments zeroed. */
extern "C" void fn_80229900(void *self) {
    ((Fn80229900VTable *)self)->Call(0, 0);
}

extern "C" void fn_80229918(void *self) {
    /* Turns this widget on: runs its virtual update (vtable slot +0x84) and then
     * sets its active flag (+0x18), the flag that makes its state queries report
     * the "on" bit and lets its notification callback run.  fn_80229958 is the
     * mirror image that clears the same flag. */
    struct VfWidget {
        VfObj obj;          /* 0x00: vtable; slot +0x84 updates the widget */
        u8 pad_0x4[0x14];
        u8 active;          /* 0x18: nonzero while the widget is turned on */
    };
    VfWidget *widget = (VfWidget *)self;

    widget->obj.vf31();
    widget->active = 1;
}

extern "C" void fn_80229958(void *self) {
    /* Turns this widget off: runs its virtual update (vtable slot +0x84) and then
     * clears its active flag (+0x18), the mirror image of fn_80229918. */
    struct VfWidget {
        VfObj obj;          /* 0x00: vtable; slot +0x84 updates the widget */
        u8 pad_0x4[0x14];
        u8 active;          /* 0x18: nonzero while the widget is turned on */
    };
    VfWidget *widget = (VfWidget *)self;

    widget->obj.vf31();
    widget->active = 0;
}

extern "C" void fn_80229998(void *widget) {
    /* Select this entry: if the widget is bound to a cursor (+0x254), write its own id (+0x258) into it. */
    int *cursor = *(int **)((char *)widget + 0x254);
    if (cursor != 0) {
        *cursor = *(int *)((char *)widget + 0x258);
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
/* Dispatch current object range/state to the target callback at +0x244 with args from +0x248/+0x24C/+0x250. */
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
    s32 start = *(s32 *)((u8 *)arg0 + 8);
    s32 convertedStart;
    s32 rangeLength;
    rangeLength = *(s32 *)((u8 *)arg0 + 0x10) - start;
    convertedStart = ((LocalObject *)arg0)->At88(start);
    s32 currentValue = ((LocalObject *)arg0)->At78();
    LocalApply *callback = *(LocalApply **)((u8 *)arg0 + 0x244);
    callback->Apply(*(s32 *)((u8 *)arg0 + 0x248),
             *(s32 *)((u8 *)arg0 + 0x24C),
             *(s32 *)((u8 *)arg0 + 0x250), currentValue, rangeLength, convertedStart);
}

extern "C" void *lbl_8033DF30[];
extern "C" void *lbl_8033DEAC[];
extern "C" void fn_802328D4(void *);
extern "C" void fn_80227C9C(s32, f32, f32, f32, f32);
extern "C" f64 lbl_805634B8;
extern "C" void fn_80229A94(void *self) {
    /* Mark the object active (and flag +0x234 when the +0x1A option is set), then dispatch Call with the two stored arguments. */
    register u32 one = 1;
    *(u8 *)((u8 *)self + 0x19) = one;
    if (*(u8 *)((u8 *)self + 0x1A)) {
        *(u8 *)((u8 *)self + 0x234) = one;
    }
    ((Fn80229A94Dispatch *)self)->Call(
        *(s32 *)((u8 *)self + 4),
        *(s32 *)((u8 *)self + 8));
}

extern "C" void fn_80229AC4(void *widget) {
    /* Select this entry: if the widget is bound to a cursor (+0x254), write its own id (+0x258) into it. */
    int *cursor = *(int **)((char *)widget + 0x254);
    if (cursor != 0) {
        *cursor = *(int *)((char *)widget + 0x258);
    }
}

/* Default widget-manager callback: an always-true predicate, reporting success to its caller. */
extern "C" u32 fn_80229ADC(void) { return 1; }

extern "C" void fn_80229AE4(void *self, s32 value1, s32 value2) {
    /* Forward a call to this widget's dispatch target with its two stored arguments plus value1/value2. */
    void *dispatch = *(void **)((u8 *)self + 0x244);
    ((Fn80229AE4Dispatch *)dispatch)->Call(
        *(s32 *)((u8 *)self + 0x248),
        *(s32 *)((u8 *)self + 0x24C),
        value1,
        value2);
}

extern "C" void fn_80229B0C(void *arg0, s32 arg1, s32 arg2) {
    /* Forward (arg1,arg2) via fn_80219264, then add them to the object's fields at +0x248 and +0x24C. */
    ((void (*)(void *, s32, s32))fn_80219264)(arg0, arg1, arg2);
    s32 temp_r3 = *(s32 *)((u8 *)arg0 + 0x248) + arg1;
    s32 temp_r0 = *(s32 *)((u8 *)arg0 + 0x24C) + arg2;
    *(s32 *)((u8 *)arg0 + 0x24C) = temp_r0;
    *(s32 *)((u8 *)arg0 + 0x248) = temp_r3;
}

/* Default no-op virtual for this UI widget: returns 0 (unimplemented query). */
extern "C" s32 fn_80229B68(void) { return 0; }

// Getter: return the 32-bit value this object stores at +0x254 (a bound handle/selection used by UI widgets).
extern "C" s32 fn_80229B70(void *self) {
    return *(s32 *)((u8 *)self + 0x254);
}

extern "C" char lbl_8033EFF4[];
extern "C" s32 fn_801E4A2C(s32, const char *);
extern "C" void * __dt__Q34Game10MemoryCard8ResourceFv_80229B78(void *arg0, s32 arg1) {
    /* Deleting destructor for the object using vtable lbl_8033EFF4: reset the
       vtable, release the resource handle at +0x348 (fn_801E4A2C), run the base
       destructor (fn_8021915C), and delete if arg1 > 0. */
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

extern "C" s32 fn_80229C9C(s32 widget) {
    /* Field-offset helper: return a pointer to a UI widget's field at +0x264,
     * where these widgets keep the value or state they watch. */
    return widget + 0x264;
}

extern "C" s32 fn_80229CA4(s32 base) {
    /* Return the address of a field at offset 0x254 within a UI widget (base + 0x254). */
    return base + 0x254;
}

extern "C" s32 fn_80229CAC(s32);
extern "C" s32 fn_80229CAC(s32 base) {
    /* Return the address of a field at offset 0x254 within a UI widget (base + 0x254). */
    return base + 0x254;
}

extern "C" void fn_80229CB4(void *widget) {
    /* Start a UI widget's animation clock: set its animating flag (+0x244),
       restart its timer at zero (+0x248), and mark it dirty (+0x234) so it
       gets redrawn when it is enabled (+0x1A). */
    (*(u8 *)((u8 *)widget + 0x244)) = 1;
    (*(f32 *)((u8 *)widget + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
}

extern "C" void fn_80229CD8(void *widget) {
    /* Clear this VfWidget's flag byte at +0x244 and, when its layout option
     * (+0x1A) is set, mark it dirty (+0x234) so it gets redrawn. */
    (*(u8 *)((u8 *)widget + 0x244)) = 0;
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
}

extern "C" void fn_802C5280(void *, s32, s32, s32, s32, void *);
extern "C" f32 lbl_805634A8;
extern "C" void fn_80229CF8(void *widget) {
    /* Show a UI widget: set its visible flag (+0x18), restart its animation
     * timer at zero (+0x248), and mark it dirty (+0x234) so it gets redrawn
     * when it is enabled (+0x1A). */
    (*(u8 *)((u8 *)widget + 0x18)) = 1;
    (*(f32 *)((u8 *)widget + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
}
/* Deactivate a UI widget: clear its active flag (+0x18), and if it is still live
 * (+0x1A) mark it dirty (+0x234) so the screen redraws it. */
extern "C" void fn_80229D1C(void *widget) {
    *(u8 *)((u8 *)widget + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)widget + 0x1A) != 0) {
        *(u8 *)((u8 *)widget + 0x234) = 1;
    }
}

#pragma scheduling reset
extern "C" void fn_80229D3C(void *widget, s32 screenX, s32 screenY) {
    /* Hit-test a UI widget: translate the screen point into the image held at
     * widget+0x250 by subtracting the widget's position (+4,+8), and ask
     * fn_802C5280 whether the resulting point lies inside that image. */
    void *self = widget;
    widget = *(void **)((u8 *)widget + 0x250);
    fn_802C5280(widget,
                screenX - *(s32 *)((u8 *)self + 4),
                screenY - *(s32 *)((u8 *)self + 8),
                0,
                *(s32 *)((u8 *)self + 4),
                self);
}
extern "C" s32 fn_80229D5C(s32);
extern "C" s32 fn_80229D5C(s32 widget) {
    /* Field-offset helper: return a pointer to a UI widget's field at +0x264. */
    return widget + 0x264;
}

extern "C" void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229D64(void *self, s32 deletingFlag) {
    /* nw4hbm::snd::detail::DisposeCallbackManager deleting destructor: run cleanup, then free storage if requested. */
    if (self) {
        if (self != NULL) {
            fn_8021915C(self, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

/* Add the 0x268 field offset to a base value (address of the field at +0x268). */
extern "C" s32 fn_80229DC0(s32 base) {
    return base + 0x268;
}

#pragma peephole off
extern "C" void fn_80229DC8(void *self, s32 unused, s32 value) {
    /* Reset the sound object's bookkeeping flags at +0x260/+0x268, then dispatch
     * its virtual Call with both arguments passed through unchanged. */
    *(u32 *)((u8 *)self + 0x260) = 0;
    *(u8 *)((u8 *)self + 0x268) = 1;
    ((Fn80229DE8Dispatch2 *)self)->Call(unused, value);
}
#pragma peephole reset
/* Reset the object's bookkeeping flags at +0x260 and +0x268, then dispatch its
 * virtual Call with `unused` and `value` reduced by the index span
 * (end - start) plus 3. */
extern "C" void fn_80229DE8(void *self, s32 unused, s32 value) {
    register u32 zero = 0;
    register u32 one = 1;
    s32 start = *(s32 *)((u8 *)self + 8);
    *(u32 *)((u8 *)self + 0x260) = zero;
    s32 end = *(s32 *)((u8 *)self + 0x10);
    *(u8 *)((u8 *)self + 0x268) = one;
    ((Fn80229DE8Dispatch2 *)self)->Call(unused, value - (end - start) - 3);
}

extern s32 fn_8021E1C8(void *, s32, s32);
/* Delegate to fn_8021E1C8 with value reduced by the object's index span (end - start) plus 3. */
extern "C" void fn_80229E1C(void *self, s32 unused, s32 value) {
    s32 start = *(s32 *)((u8 *)self + 8);
    s32 end = *(s32 *)((u8 *)self + 0x10);
    fn_8021E1C8(self, unused, value - (end - start) - 3);
}

extern "C" void fn_80229E34(void *sound) {
    /* Advance the +8 index of the sub-object stored at +0x248 by one,
     * saturating it into the range [0, (+0)-(+4)]. */
    s32 limit;
    s32 next;
    void *counter;

    counter = *(void **)((u8 *)sound + 0x248);
    next = *(s32 *)((u8 *)counter + 8) + 1;
    *(s32 *)((u8 *)counter + 8) = next;
    limit = *(s32 *)((u8 *)counter + 0) - *(s32 *)((u8 *)counter + 4);
    if (next > limit) {
        *(s32 *)((u8 *)counter + 8) = limit;
    }
    if (*(s32 *)((u8 *)counter + 8) < 0) {
        *(s32 *)((u8 *)counter + 8) = 0;
    }
}

extern "C" void fn_80229E74(void *arg0) {
    /* Decrement the visible-range count at range+8 by one, clamped to [0, range+0 - range+4]. */
    s32 maxVisible;
    s32 count;
    void *range;

    range = *(void **)((u8 *)arg0 + 0x248);
    count = *(s32 *)((u8 *)range + 8) - 1;
    *(s32 *)((u8 *)range + 8) = count;
    maxVisible = *(s32 *)((u8 *)range + 0) - *(s32 *)((u8 *)range + 4);
    if (count > maxVisible) {
        *(s32 *)((u8 *)range + 8) = maxVisible;
    }
    if (*(s32 *)((u8 *)range + 8) < 0) {
        *(s32 *)((u8 *)range + 8) = 0;
    }
}

extern "C" void fn_80229EB4(void *widget) {
    /* Reset the list widget's selection/step result (+0x260) and its active flag (+0x268). */
    *(u8 *)((char *)widget + 0x268) = 0;
    *(s32 *)((char *)widget + 0x260) = 0;
}

/* Default widget-manager callback: an always-true predicate, reporting success to its caller. */
extern "C" u32 fn_80229EC4(void) { return 1; }

/* Default widget-manager callback: an always-true predicate, reporting success to its caller. */
extern "C" u32 fn_80229ECC(void) { return 1; }

extern "C" void fn_80229ED4(void *widget) {
    // Activate the widget (flag +0x18 = 1) and, if it tracks a live value (+0x1A), request a redraw (+0x234).
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 1;
}

extern "C" void fn_80229EF4(void *widget) {
    /* Turn this VfWidget off: clear its active flag (+0x18) and, when its layout
     * option (+0x1A) is set, mark it dirty (+0x234) so it gets redrawn. */
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 0;
}

/* Return this text widget's s32 field at +0xA5C (its ibeam cursor graphic handle). */
extern "C" s32 fn_80229F14(void *widget) {
    return *(s32 *)((char *)widget + 0xA5C);
}

extern "C" void fn_80229F1C(void *widget) {
    /* Activate this widget (flag +0x18) and, if it tracks a live value (+0x1A), mark it dirty for a redraw (+0x234). */
    *(u8 *)((char *)widget + 0x18) = 1;
    if (*(u8 *)((char *)widget + 0x1A) != 0) {
        *(u8 *)((char *)widget + 0x234) = 1;
    }
}

// Deactivate a UI widget: clear its active flag (+0x18), and if it is still live
// (+0x1A) mark it dirty (+0x234) so the screen redraws it.
extern "C" void fn_80229F38(void *widget) {
    *(u8 *)((u8 *)widget + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)widget + 0x1A) != 0) {
        *(u8 *)((u8 *)widget + 0x234) = 1;
    }
}

extern "C" s32 fn_80229F58(s32);
extern "C" s32 fn_80229F58(s32 widget) {
    /* Field-offset helper: return a pointer to a UI widget's field at +0x254. */
    return widget + 0x254;
}

extern "C" s32 fn_80229F60(void *widget) {
    /* Return state 2 when this widget is active (flag +0x18), otherwise 0. */
    volatile u8 *active = (volatile u8 *)((char *)widget + 0x18);
    s32 state = 0;
    if (*active != 0) {
        state = 2;
    }
    return state;
}

/* Deleting destructor of the horizontal slider widget fn_8021F678 builds
 * (vtable lbl_8033E878): restore the widget's own vtable, release the two
 * images it loaded -- the track (slider1.img) at +0x25C and the fill
 * (slider2.img) at +0x260 -- run the base Widget destructor, and free the
 * widget when deletingFlag > 0. */
extern "C" void *fn_80229F78(void *self, s32 deletingFlag) {
    #define Slider_vtable lbl_8033E878
    #define Image_release fn_802C519C

    if (self != NULL) {
        *(void **)self = Slider_vtable;
        Image_release((void *)((SliderWidget *)self)->trackImg);
        Image_release((void *)((SliderWidget *)self)->fillImg);
        Widget_dtor(self, 0);
        if (deletingFlag > 0) {
            Mem_freeObject(self);
        }
    }

    #undef Slider_vtable
    #undef Image_release
    return self;
}

extern "C" void *lbl_8033E878[];
extern "C" void *lbl_8033DCF8[];
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_80229FF0(void *widget) {
    /* Enable a UI widget (flag +0x244) and run its virtual vf17() update. */
    *(u8 *)((u8 *)widget + 0x244) = 1;
    ((VfObj *)widget)->vf17();
}

/* Disable a UI widget by clearing its enabled flag byte at +0x244
   (the mirror of fn_80229FF0). */
extern "C" void fn_8022A008(void *widget) {
    *(u8 *)((u8 *)widget + 0x244) = 0;
}

extern "C" void fn_8022A014(void *widget) {
    /* Activate a UI widget's +0x18 state flag; when the widget is enabled
     * (+0x1A) also set +0x234 so the next redraw picks up the change. */
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 1;
}

extern "C" void fn_8022A034(void *widget) {
    // Deactivate the widget (flag +0x18 = 0) and, if it tracks a live value (+0x1A), request a redraw (+0x234).
    if ((*(u8 *)((u8 *)widget + 0x1A)) != 0) {
        (*(u8 *)((u8 *)widget + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)widget + 0x18)) = 0;
}

extern "C" void *lbl_8033E770[];
/* Scroll bar widget deleting destructor (vtable lbl_8033E770, widget built by
 * fn_80220E48): restore the widget's own vtable, release the two images it
 * loaded -- the bar (vscroll/hscroll.img) at +0x248 and the thumb
 * (vthumb/hthumb.img) at +0x24C -- run the base Widget destructor, and free the
 * widget when deletingFlag > 0. */
extern "C" void *fn_8022A054(void *self, s32 deletingFlag) {
    /* the scroll bar widget built by fn_80220E48; mode 0 is the vertical bar */
    struct ScrollBarWidget {
        void *vtable;     /* +0x00 */
        u8 widget[0x240]; /* +0x04 base Widget state */
        u8 enabled;       /* +0x244 set by fn_80229FF0, cleared by fn_8022A008 */
        u8 pad_0x245[3];  /* +0x245 */
        void *barImage;   /* +0x248 vscroll.img (mode 0) or hscroll.img (mode 1) */
        void *thumbImage; /* +0x24C vthumb.img (mode 0) or hthumb.img (mode 1) */
    };
    #define ScrollBar_vtable lbl_8033E770
    #define Image_release    fn_802C519C

    if (self != NULL) {
        ((ScrollBarWidget *)self)->vtable = ScrollBar_vtable;
        Image_release(((ScrollBarWidget *)self)->barImage);
        Image_release(((ScrollBarWidget *)self)->thumbImage);
        Widget_dtor(self, 0);
        if (deletingFlag > 0) {
            Mem_freeObject(self);
        }
    }

    #undef ScrollBar_vtable
    #undef Image_release
    return self;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8022A0CC(void *self, int shouldDelete) {
    /* nw4hbm::snd::MemorySoundArchive scalar deleting destructor: run the base
     * teardown, then free the storage when shouldDelete > 0. */
    if (self != 0) {
        fn_8021915C(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

/* Deleting destructor of the spinning 3D model view a text widget builds in
 * fn_802286E4 (vtable lbl_8033DCF8): restore the object's own vtable, release
 * the mrModel instance it holds at +0x04, and free the object itself when
 * deletingFlag > 0. */
extern "C" void *fn_8022A124(void *self, s32 deletingFlag) {
    /* the model view allocated by fn_802286E4, owned by its widget at +0x268 */
    struct ModelView {
        void *vtable;   /* +0x00 */
        s32 modelId;    /* +0x04 mrModel instance id, -1 when none */
        f32 matrix[12]; /* +0x08 3x4 transform plus translation */
        f32 spinAngle;  /* +0x38 advanced by spinSpeed every frame */
        f32 spinSpeed;  /* +0x3C */
    };
    #define ModelView_vtable       lbl_8033DCF8
    #define mrModelReleaseInstance fn_802C6CF8

    s32 modelId;

    if (self != NULL) {
        modelId = ((ModelView *)self)->modelId;
        ((ModelView *)self)->vtable = ModelView_vtable;
        if (modelId != -1) {
            mrModelReleaseInstance(modelId);
            ((ModelView *)self)->modelId = -1;
        }
        if (deletingFlag > 0) {
            Mem_freeObject(self);
        }
    }

    #undef ModelView_vtable
    #undef mrModelReleaseInstance
    return self;
}

extern "C" s32 fn_8012C33C(void *);
extern "C" s32 fn_802C6FC0(void *, s32, s32);
extern "C" void fn_8022A19C(void *arg0, void *arg1) {
#define MrModel_ReleaseHandle fn_802C6CF8
#define MrModel_LoadHandle fn_802C6FC0
#define Resource_Exists fn_8012C33C
    /* Reload the model-view's mrModel handle from a resource path when the resource exists. */
    s32 modelHandle = *(s32 *)((u8 *)arg0 + 4);
    if (modelHandle != -1) {
        MrModel_ReleaseHandle(modelHandle);
        *(s32 *)((u8 *)arg0 + 4) = -1;
    }
    if (Resource_Exists(arg1) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = MrModel_LoadHandle(arg1, 0, 0);
    }
#undef MrModel_ReleaseHandle
#undef MrModel_LoadHandle
#undef Resource_Exists
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
extern "C" void fn_8022A574(void *object) {
    /* Submit this object's model (handle at +4) for drawing with its embedded transform at +8; -1 means no model. */
    s32 modelHandle = *(s32 *)((u8 *)object + 4);
    if (modelHandle == -1) {
        return;
    }
    fn_802C744C(modelHandle, (u8 *)object + 8);
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

