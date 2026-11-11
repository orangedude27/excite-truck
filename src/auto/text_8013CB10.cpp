#include "types.h"
extern "C" void *memset(void *, s32, u32);
extern "C" f32 fn_801B306C(void);
extern "C" s32 fn_80009C84(void);
extern "C" s32 fn_80179630(s32);
extern "C" void fn_801CB5DC(s32, s32, s32);
extern "C" void fn_801CB648(s32, s32, f32);
extern "C" f32 lbl_8056158C, lbl_80561590;
extern "C" f32 lbl_80558DC4[];
extern "C" u8 lbl_802F93B0[];
struct SubArray8013D2C4 {
    void **ptr;
    s32 count;
    s32 cap;
    void *storage[16];
    inline SubArray8013D2C4() : ptr(storage), count(0), cap(0x10) {}
    inline void init() {
        ptr = storage;
        cap = 0x10;
        count = 0;
    }
    inline void push(void *w) {
        s32 idx = count;
        void **arr = ptr;
        count = idx + 1;
        arr[idx] = w;
    }
};
struct RingBuf8013D2C4 {
    void *ptr;
    s32 cap;
    s32 head;
    s32 tail;
    u8 storage[0x64];
    inline RingBuf8013D2C4() : ptr(storage), cap(8), head(0), tail(0) {}
    inline void init() {
        head = 0;
        cap = 8;
        ptr = storage;
        tail = 0;
    }
};
extern "C" s32 fn_80207848(void *, s32);
extern "C" void fn_802E317C(const char *, ...);
struct Sub134_8013D2C4 {
    u8 pad0[0x8];
    void *p140;
    u8 pad1[4];
    void *p148;
    void *p14C;
    void *p150;
    u8 pad2[4];
    void *p158;
    void *p15C;
    void *p160;
    char s164[0x14];
    char s178[0x14];
    char s18C[0x14];
    char s1A0[0x14];
    char s1B4[0x14];
    char s1C8[0xA];
    char s1D2[0x14];
    char s1E6[0x14];
    char s1FA[0x14];
    char s20E[0x14];
    char s222[0x1A];
    inline Sub134_8013D2C4() : p140(0), p148(0), p14C(0), p150(0), p158(0), p15C(0), p160(0) {
        memset(s164, 0x7A, 3); s164[3] = 0;
        memset(s178, 0x7A, 3); s178[3] = 0;
        memset(s18C, 0x7A, 3); s18C[3] = 0;
        memset(s1A0, 0x7A, 3); s1A0[3] = 0;
        memset(s1B4, 0x7A, 3); s1B4[3] = 0;
        memset(s1C8, 0x7A, 3); s1C8[3] = 0;
        memset(s1D2, 0x7A, 3); s1D2[3] = 0;
        memset(s1E6, 0x7A, 3); s1E6[3] = 0;
        memset(s1FA, 0x7A, 3); s1FA[3] = 0;
        memset(s20E, 0x7A, 3); s20E[3] = 0;
        memset(s222, 0x7A, 3); s222[3] = 0;
    }
    inline void init(s32 z = 0) {
        p140 = (void *)z;
        p148 = (void *)z;
        p14C = (void *)z;
        p150 = (void *)z;
        p158 = (void *)z;
        p15C = (void *)z;
        p160 = (void *)z;
        memset(s164, 0x7A, 3); s164[3] = z;
        memset(s178, 0x7A, 3); s178[3] = z;
        memset(s18C, 0x7A, 3); s18C[3] = z;
        memset(s1A0, 0x7A, 3); s1A0[3] = z;
        memset(s1B4, 0x7A, 3); s1B4[3] = z;
        memset(s1C8, 0x7A, 3); s1C8[3] = z;
        memset(s1D2, 0x7A, 3); s1D2[3] = z;
        memset(s1E6, 0x7A, 3); s1E6[3] = z;
        memset(s1FA, 0x7A, 3); s1FA[3] = z;
        memset(s20E, 0x7A, 3); s20E[3] = z;
        memset(s222, 0x7A, 3); s222[3] = z;
    }
};
extern "C" void fn_8001DAE0(void *, f32);
extern "C" void *fn_801414A4(void *);
extern "C" f32 lbl_805614C0;
extern "C" f32 lbl_805614AC;
extern "C" f32 lbl_805614C4;
struct Timer8013D2C4 {
    u32 t[2];
    inline Timer8013D2C4(f32 v) { fn_8001DAE0(this, v); }
    inline void init(f32 v) { fn_8001DAE0(this, v); }
};
struct Perc8013D2C4 {
    void *a;
    void *b;
    inline Perc8013D2C4() { fn_801414A4(this); }
    inline void init() { fn_801414A4(this); }
};
extern "C" u8 lbl_8032CAF0[];
/* ZoneMaster - the zone system's owner object (vtable lbl_8032CAF0).
 * It loads zlmain/zlclosure/zlresult, the zone textures and the zone table
 * it allocates from the heap it names "ZoneMaster::tab" (lbl_8032C530+0x78);
 * the game keeps its single instance in lbl_8055E1C0. */
struct ZoneMaster {
    void *vt;
    u32 unk4;
    SubArray8013D2C4 sa;
    void *w54;
    void *w58;
    void *w5C;
    s32 f60;
    void **p64;
    s32 f68;
    Timer8013D2C4 t6C;
    Timer8013D2C4 t74;
    Timer8013D2C4 t7C;
    Timer8013D2C4 t84;
    Timer8013D2C4 t8C;
    u8 pad94[0xC];
    void *a0;
    void *a4;
    void *a8;
    void *ac;
    void *b0;
    void *b4;
    void *b8;
    s32 bc;
    RingBuf8013D2C4 rb;
    s32 f130;
    Sub134_8013D2C4 sub;
    u8 pad23C[0x18];
    s32 f254;
    u8 f258;
    u8 pad259[0xF];
    f32 f268;
    u8 f26C;
    u8 pad26D[3];
    s32 f270;
    s32 f274;
    s32 f278;
    s32 f27C;
    Perc8013D2C4 perc;
    s32 f288;
    inline void *operator new(u32, void *p) { return p; }
    inline void init() {
        f32 fc0 = lbl_805614C0;
        vt = lbl_8032CAF0;
        sa.init();
        t6C.init(fc0);
        t74.init(lbl_805614C0);
        t7C.init(lbl_805614AC);
        t84.init(lbl_805614AC);
        t8C.init(lbl_805614C4);
        rb.init();
        sub.init();
        perc.init();
    }
    inline ZoneMaster() : vt(lbl_8032CAF0), sa(), t6C(lbl_805614C0), t74(lbl_805614C0), t7C(lbl_805614AC), t84(lbl_805614AC), t8C(lbl_805614C4), rb(), sub(), perc() {}
    inline void initWidgets(const char *base);
};
extern "C" void *fn_80145E70(const char *);
extern "C" void *fn_802CAC28(const char *, s32);
inline void ZoneMaster::initWidgets(const char *base) {
    void *w0 = fn_80145E70(base + 0x0);
    w54 = w0;
    sa.push(w0);
    void *w1 = fn_80145E70(base + 0xC);
    w58 = w1;
    sa.push(w1);
    void *w2 = fn_80145E70(base + 0x1C);
    w5C = w2;
    sa.push(w2);
    a0 = fn_802CAC28(base + 0x2C, 0);
    a4 = fn_802CAC28(base + 0x38, 0);
    a8 = fn_802CAC28(base + 0x48, 0);
    ac = fn_802CAC28(base + 0x58, 0);
    b0 = fn_802CAC28(base + 0x68, 0);
}
static inline void LoadWidget8013D2C4(s32 *dst, const char *base, s32 off) {
    const char *s = base + off;
    s32 r = fn_80207848((void *)s, 1);
    *dst = r;
    if (r == 0) {
        fn_802E317C(base + 0x148, s);
    }
}
extern "C" s32 lbl_8055E1C0;
extern "C" void *fn_80145E70(const char *);
extern "C" void **__AXFXGetLfoSinTable_801769CC(void);
extern "C" u8 *fn_8001285C(void *);
extern "C" s32 fn_80171698(void);
extern "C" s32 __AXGetStudio_8000AC2C(void);
extern "C" void *fn_80131810(const char *);
extern "C" void fn_80131818(void *);
extern "C" void fn_802049DC(const char *, void *, f32, f32, f32);
extern "C" char lbl_80559D20;
extern "C" void *fn_8013E6E4(void *arg0);
extern "C" void fn_8002F30C(void *, s32, s32, void (*)(), void (*)());
extern "C" void *fn_801F181C(void *, const char *, void *, void *);
extern "C" void fn_8013E3A8(void *, void *);
extern "C" void fn_8013CC20(void *, s32);
extern "C" void fn_801331C4(void *, void *, const char *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" void *fn_802C6FC0(const char *, s32, s32);
extern "C" f32 lbl_805614C4;
class TPathDocument;
extern "C" void *fn_8013D8D0(void *out, TPathDocument *document);
extern "C" void fn_80141B58(void *);
extern "C" f32 lbl_80561494;
extern "C" f32 lbl_8056149C;
extern "C" f32 lbl_805614A0;
extern "C" u8 lbl_8032CAF0[];
extern "C" u8 lbl_8032CBB8[];
extern "C" u8 lbl_8032CC04[];
extern "C" f32 lbl_805614C0;
extern "C" f32 lbl_805614C4;
extern "C" f32 lbl_805614C8;
extern "C" f32 lbl_805614CC;
extern "C" f32 lbl_805614D0;
extern "C" f32 lbl_805614D4;
extern "C" void *fn_8007DF60(void *);
extern "C" void fn_8001DA84(void *);
extern "C" s32 fn_80207848(void *, s32);
extern "C" void *fn_801414A4(void *);
extern "C" void fn_80141748(void *);
extern "C" void fn_80141890(void *, void *, const char *, const char *, const char *, s32);
extern "C" void *fn_802CAC28(const char *, s32);
extern "C" void *fn_802AE340(s32);
extern "C" s32 fn_802ADBA8(void *, const char *, void *, void *);
extern "C" void *fn_802AE0A4(s32, const char *);
extern "C" void *fn_801686B0(void *, const char *, f32, f32);
extern "C" void fn_80168734(void *, f32, f32, f32, f32);
extern "C" void *fn_80178A9C(void);
extern "C" void *fn_80178AA4(void);
extern "C" f64 fn_8002F234(f32);
extern "C" s32 fn_801E9E30(void *, f32 *);
extern "C" s32 fn_80136594(void **, s32, f32 *, f32);
extern "C" s32 fn_80178C9C(void);
extern "C" f32 PSVECSquareDistance(void *, void *);
extern "C" void fn_802A9BFC(void *, void *, s32, s32, s32, s32, s32, f32);
extern "C" f32 lbl_80561504;
extern "C" f32 lbl_80561508;
struct PathNode { u8 data[0x24]; };
struct PathGroup { s32 count; PathNode *nodes; s32 pad[3]; };
struct PathData { s32 count; PathGroup *groups; };
static inline u8 *NextPathNode(u8 *self, u8 *item) {
    PathGroup *g = &(*(PathData **)(self + 0x64))->groups[*(s32 *)(self + 0x68)];
    PathNode *last = &g->nodes[g->count] - 1;
    return (PathNode *)item == last ? (u8 *)g->nodes : item + 0x24;
}
extern "C" f32 fn_801E7E24(void);
extern "C" void fn_802981F8(void *);
extern "C" f32 *fn_802C86DC(void);
extern "C" s32 fn_801E866C(s32);
extern "C" void fn_80140D1C(void *, void *, void *);
extern "C" void qsort(void *, u32, u32, int (*)(const void *, const void *));
extern "C" void *memset(void *, s32, u32);
extern "C" void fn_802AE0E0(int);
extern "C" f32 lbl_80561594;
extern "C" f32 lbl_80561598;
extern "C" f32 lbl_8056159C;
extern "C" f32 fn_8001DAF0(f32 *);
extern "C" u8 lbl_8042FB3C[];
extern "C" char lbl_8032C96C[];
extern "C" void fn_802ADE60(int, int);
extern "C" void fn_8001DAE0(void *, f32);
extern "C" f32 lbl_805614FC;
extern "C" f32 lbl_80561500;
extern "C" f32 lbl_80558DC4[];
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805614AC;
extern "C" f32 lbl_805614BC;
extern "C" s32 fn_80128670(s32);
extern "C" void fn_80128668(void);
extern "C" f32 fn_8001DAE8(void *);
extern "C" void fn_8001DAE8_2(void *, f32);
extern "C" s32 lbl_802F9398[6];
struct S6_8013D18C { s32 v[6]; };
extern "C" void **fn_801284F8(s32, void *);
extern "C" f32 lbl_80561498;
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805614AC;
extern "C" f32 lbl_80558DC4[];
extern "C" u8 lbl_8055E1BC;
extern "C" f32 fn_8001DAE8(void *);
extern "C" f32 fn_8013CB3C(void);
extern "C" s32 fn_80176A1C(void);
extern "C" int strcmp(const char *, const char *);

extern "C" f32 lbl_80561584;

extern "C" u8 lbl_8032CAC0;
extern "C" s32 fn_8013D224(f32, f32);
extern "C" u8 *fn_801B2EC0(s32);
extern "C" f32 __fabsf(f32);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct S28_80142118 { s32 v[7]; };

struct TVec2 { f32 x; f32 y; };
struct Fn801436E0TextStyle { u32 a, b, c, d; f32 size; u32 f, g, h; };
extern "C" void *fn_801E7E3C(void);
extern "C" void fn_8000FBE4(void);
extern "C" s32 fn_80161C38(void);
extern "C" void fn_80160A74(void);
extern "C" s32 fn_80160998(void);
extern "C" void fn_80130978(void *, s32, f32);
extern "C" f32 fn_80147204(void *, const char *);
extern "C" void fn_8014784C(void *, const char *, const char *, s32);
extern "C" f32 lbl_805614C0, lbl_805614D0, lbl_8056150C, lbl_80561588, lbl_805615AC;
class TPathDocument {
public:
    virtual void *find(const char *);
    virtual void *child(s32);
    virtual s32 has(const char *);
};
class TPathElement {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20();
    virtual void *attribute(const char *);
    virtual void *child(s32);
};
class TPathValue {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual f32 number(const char *, f32);
    virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12();
    virtual TVec2 vector(const char *);
};
extern "C" void *fn_8012850C(s32, const char *);
extern "C" void *fn_8002F37C(void *, void (*)(), void (*)(), s32, s32);
extern "C" int sprintf(char *, const char *, ...);
extern "C" char lbl_80559D28, lbl_80559D30, lbl_80559D38, lbl_80559D44, lbl_80559D4C, lbl_80559D50;
extern "C" f32 lbl_805614C4;

// Quaternion and Vec types for vector/quaternion math
typedef struct Vec { f32 x, y, z; } Vec;
typedef struct Quaternion { f32 x, y, z, w; } Quaternion;

// Forward declarations for vector/quaternion functions
extern "C" void PSVECCrossProduct(const Vec *, const Vec *, Vec *);
extern "C" void PSVECNormalize(const Vec* in, Vec* out);

extern "C" void fn_801E9DC4(s16 *);

extern "C" char lbl_80559D40[4];
extern "C" char lbl_80559D58[7];
extern "C" char lbl_80559D60[7];

extern "C" void fn_80140A6C(void);
extern "C" s32 fn_801B8514(void);
  extern "C" u8 *fn_8017960C(s32);
  extern "C" u32 fn_8013D148(u8 *, f32);
  extern "C" void *fn_802C6C34(s32);
  extern "C" void fn_802C70AC(s32, void *, s32, s32);
  
  // user virtuals start at vtable offset 0x8 (two destructor slots first)
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16();
    virtual void v4C(); // 0x4C
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();
    virtual s32 v68(); // 0x68
};

class TObj24 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual u8 v24(); // 0x24
};

class TObj8 {
public:
    virtual void d0();
    virtual u8 *v8();
};

class TObj10 {
public:
    virtual u8 *v10(); // 0x8
};

class TObj18 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual u8 *v18();
};

class TObjC {
public:
    virtual void d0();
    virtual s32 vC(s32); // 0xC
};

class TObj60 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21();
    virtual s32 v60(s32);
};

class TObj20b {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual s32 v20();
};

class TObj20 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual s32 v20(s32);
};

class TObjCPlus {
public:
    virtual void d0();
    virtual s32 vC(s32);
};

class TDispatchStringInt20 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual s32 v20(const char *, s32);
};

class TDispatchStringFloat28 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual f32 v28(const char *, f32);
};

extern "C" u8 lbl_8032C530[0x500];
extern "C" f32 lbl_805614E0;
extern "C" f32 lbl_805614E4;
extern "C" f32 lbl_805614E8;
extern "C" f32 lbl_805614EC;
extern "C" f32 lbl_805614F0;
extern "C" f32 lbl_805614F4;
extern "C" f32 lbl_805614F8;
extern "C" f64 lbl_805614D8;
extern "C" f32 fn_80204CFC(const char *);
extern "C" void fn_801345D8(void *, s32, const char *, ...);
extern "C" void fn_801308F4(void *, s32, s32);
extern "C" void fn_80130980(void *, s32, s32, f32);
extern "C" void fn_801312EC(void *, void *);
extern "C" void fn_80131318(void *);
extern "C" int fn_801609C4(s32);
extern "C" char *__AXGetStackHead(void);
extern "C" void fn_802ADFF4(s32, s32);
extern "C" void fn_802AE02C(s32, s32);
extern "C" void fn_802AE0B8(s32, s32);
extern "C" void fn_802AE168(s32);
extern "C" unsigned int strlen(const char *);
extern "C" char lbl_80559D6C, lbl_80559D84;
extern "C" char lbl_80559D80[1];
extern "C" u8 lbl_8055E1C8;
extern "C" u32 lbl_8055E044;
extern "C" u8 lbl_8042FB78[], lbl_8032CA74[];
extern "C" f32 lbl_8055E3C8;
extern "C" void *fn_8013E33C(void *, s32);
extern "C" void fn_8013E338(void);

extern "C" s32 fn_8013D1F0(s32);

extern "C" s32 fn_8013CB10(void) {
    return fn_80176A1C() == 2;
}

extern f32 lbl_8055E3C8;
#pragma dont_inline on
extern "C" f32 fn_8013CB3C(void) {
    return lbl_8055E3C8;
}
#pragma dont_inline off

extern "C" s32 fn_8013CB44(const char *arg0, TObj10 *arg1) {
    return strcmp((const char *)arg1->v10(), arg0) == 0;
}

#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8013CB90(void *arg0) {
    f32 y;
    f32 scale;
    f32 x;

    x = *(f32 *)((u8 *)arg0 + 0x10);
    scale = lbl_80561498;
    y = *(f32 *)((u8 *)arg0 + 0x14);
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg0 + 4) - x * scale;
    *(f32 *)((u8 *)arg0 + 8) = *(f32 *)((u8 *)arg0 + 8) - y * scale;
}

extern "C" s32 fn_8013CBC0(void *arg0, s32 arg1) {
    void *obj;
    void *p;
    float scale;
    float x;
    float y;
    float a;
    float b;
    float len;
    float inv;
    s32 result;
    obj = *(void **)((char *)arg0 + 0x104);
    result = 0;
    p = fn_8017960C(arg1);
    scale = *(float *)((char *)p + 0x5BC);
    x = *(float *)((char *)p + 0x94) + *(float *)((char *)p + 0x54) * scale;
    y = *(float *)((char *)p + 0x9C) + *(float *)((char *)p + 0x5C) * scale;
    a = *(float *)obj - x;
    b = *(float *)((char *)obj + 8) - y;
    len = (float)fn_8002F234(a * a + b * b);
    inv = lbl_805614AC / len;
    (void)inv;
    return result;
}

#pragma scheduling on
extern "C" f32 lbl_805614B4;
extern "C" f32 lbl_805614B8;
extern "C" f32 PSVECDotProduct(const f32 *, const f32 *);
extern "C" s32 fn_8013CFF0(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 dx, dy, dz;
    f32 vx, vy, vz;
    f32 dot;
    f32 sp10, spC, sp8;
    f32 sp18, sp14, sp1C;
    dx = arg0[5] - arg0[2];
    dy = arg0[4] - arg0[1];
    dz = arg0[3] - arg0[0];
    vx = arg0[2] + lbl_80561498 * dx;
    vy = arg0[1] + lbl_80561498 * dy;
    vz = arg0[0] + lbl_80561498 * dz;
    sp8 = vz - arg1[9];
    spC = vy - arg1[10];
    sp10 = vx - arg1[11];
    sp14 = vz;
    sp18 = vy;
    sp1C = vx;
    dot = PSVECDotProduct(&sp8, &sp8);
    if (dot < lbl_805614B4) {
        s32 outside = PSVECDotProduct(&sp8, arg1 + 6) > lbl_805614B8;
        if (outside == 0) {
            sp8 = arg0[3] - arg1[9];
            spC = arg0[4] - arg1[10];
            sp10 = arg0[5] - arg1[11];
            s32 intersects = PSVECDotProduct(&sp8, arg1 + 6) > lbl_805614B8;
            if (intersects != 0 && arg2 != 0) *arg2 = dot;
        }
    }
    return 0;
}

extern "C" u32 fn_8013D148(u8 *arg0, f32 arg1) {
    s32 i = 0;
    s32 count = *(s32 *)arg0;
    u8 *items = *(u8 **)(arg0 + 4);
    u8 *result = items + count * 0x24 - 0x24;
    while (count > 0) {
        u8 *item = items + i;
        if (*(f32 *)(item + 0x18) > arg1) return (u32)result;
        result = item;
        i += 0x24;
        count--;
    }
    return (u32)result;
}

extern "C" u32 fn_8013D18C(u32 arg0) {
    u32 idx = arg0 % 6;
    s32 values[6];
    s32 *src = lbl_802F9398;
    values[0] = *src++;
    values[1] = *src++;
    values[2] = *src++;
    values[3] = *src++;
    values[4] = *src++;
    values[5] = *src;
    return values[idx];
}

extern "C" s32 fn_8013D1F0(s32 arg0) {
    struct V {
        virtual void a0();
        virtual void a1();
        virtual u8 *a2();
    };
    V *obj = (V *)((void *(*)(void))fn_801B2EC0)();
    u8 *p = obj->a2();
    return *(s32 *)(p + 0x10);
}

extern "C" s32 fn_8013D224(f32 farg0, f32 farg1) {
    f32 diff = farg0 - farg1;
    f64 abs = __fabs((f64)diff);
    f32 result;
    if ((f32)abs <= lbl_80558DC4[0]) {
        return 0;
    }
    if (diff > lbl_805614A4) {
        result = lbl_805614AC;
    } else {
        result = lbl_805614BC;
    }
    return (s32)result;
}

extern "C" void fn_8013D27C(void *a, void *b) {
    fn_8013D224(*(f32 *)((u8 *)a + 0x18), *(f32 *)((u8 *)b + 0x18));
}

extern "C" u8 lbl_8032CAC0_vt[48];
extern "C" void **fn_801284F8(s32, void *);
extern "C" char lbl_80559D18[5];
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8013D288(void) {
    void **slot = fn_801284F8(4, (void *)lbl_80559D18);
    if (slot != 0) {
        *slot = (void *)lbl_8032CAC0_vt;
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline off
extern "C" void *fn_8013D2C4(void *arg0, void *arg1) {
    struct V18 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual s32 v18(const char *, const char *); };
    struct V30 {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual s32 v30(const char *, s32);
    };
    struct V08_10 {
        virtual void *v08(const char *);
        virtual void d1();
        virtual s32 v10(const char *);
    };

    ZoneMaster *obj = (ZoneMaster *)arg0;
    u8 *self = (u8 *)arg0;
    u8 *src = (u8 *)arg1;
    const char *base = (const char *)lbl_8032C530;

    f32 fc0 = lbl_805614C0;
    obj->vt = lbl_8032CAF0;
    obj->sa.init();
    obj->t6C.init(fc0);
    obj->t74.init(lbl_805614C0);
    obj->t7C.init(lbl_805614AC);
    obj->t84.init(lbl_805614AC);
    obj->t8C.init(lbl_805614C4);
    obj->rb.init();
    obj->sub.init();
    obj->perc.init();

    void *w0 = fn_80145E70(base + 0x0);
    obj->w54 = w0;
    obj->sa.push(w0);

    void *w1 = fn_80145E70(base + 0xC);
    obj->w58 = w1;
    obj->sa.push(w1);

    void *w2 = fn_80145E70(base + 0x1C);
    obj->w5C = w2;
    obj->sa.push(w2);

    obj->a0 = fn_802CAC28(base + 0x2C, 0);
    obj->a4 = fn_802CAC28(base + 0x38, 0);
    obj->a8 = fn_802CAC28(base + 0x48, 0);
    obj->ac = fn_802CAC28(base + 0x58, 0);
    obj->b0 = fn_802CAC28(base + 0x68, 0);

    s32 n = *(s32 *)(src + 0x3E0);
    lbl_8055E1C0 = (s32)self;
    *(s32 *)(self + 0xBC) = n;
    *(void **)(self + 0xB8) = fn_8002F37C(fn_8012850C(n * 0x12C + 0x10, base + 0x78), (void (*)())fn_8013E6E4, 0, 0x12C, n);

    *(s32 *)(self + 0x130) = 0;
    for (s32 off = 0, i = 0; i < *(s32 *)(self + 0xBC); src += 0x78, off += 0x12C, i++) {
        *(bool *)((u8 *)(*(void **)(self + 0xB8)) + off + 0x118) = (*(s32 *)(src + 0x20) == 0x50);
        if (((u8 *)(*(void **)(self + 0xB8)) + off)[0x118] != 0) {
            *(s32 *)(self + 0x130) += 1;
        }
    }

    *(s32 *)(self + 0x60) = 0;
    u8 *mgr = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    if (((V30 *)*(void **)(mgr + 0x20))->v30(base + 0x88, 1) != 0) {
        *(s32 *)(self + 0x60) = fn_80171698();
    }

    mgr = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    s32 res18 = ((V18 *)*(void **)(mgr + 0x20))->v18(base + 0x98, &lbl_80559D20);
    s32 studio = __AXGetStudio_8000AC2C();

    char buf[256];
    fn_801345D8(buf, 0x100, base + 0xA4, studio, res18);
    void *docA = fn_80131810(buf);
    void *docB = fn_80131810(base + 0xB0);

    if (docA != 0) {
        void *attr = 0;
        if (docB != 0 && ((V08_10 *)docB)->v10(&lbl_80559D28) != 0) {
            attr = ((V08_10 *)docB)->v08(&lbl_80559D28);
        }
        fn_8013E3A8(lbl_8042FB3C, attr);
        void **p64 = fn_801284F8(8, (void *)(base + 0xC0));
        if (p64 != 0) {
            p64 = (void **)fn_8013D8D0(p64, (TPathDocument *)docA);
        }
        *(void ***)(self + 0x64) = p64;
        if (docB != 0) {
            fn_80131818(docB);
        }
        fn_80131818(docA);
    } else {
        fn_802E317C(base + 0xCC, buf);
        *(s32 *)(self + 0x64) = 0;
    }

    fn_802049DC(base + 0xE8, lbl_8042FB3C + 0x24, lbl_80561498, lbl_805614C8, lbl_805614CC);
    fn_802049DC(base + 0xFC, lbl_8042FB3C + 0x20, lbl_805614CC, lbl_805614C4, lbl_805614CC);
    fn_802049DC(base + 0x110, lbl_8042FB3C + 0x1C, lbl_805614CC, lbl_805614D0, lbl_805614CC);
    fn_802049DC(base + 0x120, lbl_8042FB3C + 0x18, lbl_805614C4, lbl_805614D4, lbl_805614C4);

    *(f32 *)(self + 0x268) = lbl_805614AC;
    ((void (*)(s32, const char *, void *))fn_801331C4)(4, base + 0x12C, self + 0x268);

    const char *s1 = base + 0x13C;
    s32 r1 = fn_80207848((void *)s1, 1);
    *(s32 *)(self + 0x270) = r1;
    if (r1 == 0) {
        fn_802E317C(base + 0x148, s1);
    }

    const char *s2 = base + 0x15C;
    s32 r2 = fn_80207848((void *)s2, 1);
    *(s32 *)(self + 0x278) = r2;
    if (r2 == 0) {
        fn_802E317C(base + 0x148, s2);
    }

    const char *s3 = base + 0x168;
    s32 r3 = fn_80207848((void *)s3, 1);
    *(s32 *)(self + 0x27C) = r3;
    if (r3 == 0) {
        fn_802E317C(base + 0x148, s3);
    }

    const char *s4 = base + 0x178;
    s32 r4 = fn_80207848((void *)s4, 1);
    *(s32 *)(self + 0x274) = r4;
    if (r4 == 0) {
        fn_802E317C(base + 0x148, s4);
    }

    *(s32 *)(self + 0x288) = -1;
    self[0x26C] = 0;
    *(void **)(self + 0xB4) = fn_802C6FC0(base + 0x184, 0, 0);
    *(s32 *)(self + 0x254) = fn_80207848((void *)(base + 0x194), 1);
    self[0x258] = 0;
    return self;
}
#pragma pop

extern "C" u8 lbl_8032CAF0[];
extern "C" u8 lbl_8032CBB8[];
extern "C" u8 lbl_8032CC04[];
extern "C" f32 lbl_805614C0;
extern "C" f32 lbl_805614C4;
extern "C" f32 lbl_805614C8;
extern "C" f32 lbl_805614CC;
extern "C" f32 lbl_805614D0;
extern "C" f32 lbl_805614D4;
extern "C" void *fn_8007DF60(void *);
extern "C" void fn_8001DA84(void *);
extern "C" s32 fn_80207848(void *, s32);
extern "C" void *fn_801414A4(void *);
extern "C" void fn_80141748(void *);
extern "C" void fn_80141890(void *, void *, const char *, const char *, const char *, s32);
extern "C" void *fn_802CAC28(const char *, s32);
extern "C" void *fn_802AE340(s32);
extern "C" s32 fn_802ADBA8(void *, const char *, void *, void *);
extern "C" void *fn_802AE0A4(s32, const char *);
extern "C" void *fn_801686B0(void *, const char *, f32, f32);
extern "C" void fn_80168734(void *, f32, f32, f32, f32);
extern "C" void *fn_80178A9C(void);
extern "C" void *fn_80178AA4(void);

extern "C" s32 fn_8013D890(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8013DDD4(TObjC *, const char *);
extern "C" s32 fn_8013DE7C(TObj60 *, const char *);
extern "C" void fn_8013DF24(void *, void *, void *);
extern "C" void fn_8013E054(void *, void *, f32);
extern "C" void fn_8013E19C(void *, f32);
extern "C" void fn_8013E2AC(void *, void *);
extern "C" f32 fn_8013E300(void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_8013D8D0(void *out, TPathDocument *document) {
    char name[32];
    PathData *data=(PathData *)out;
    const char *base=(const char *)lbl_8032C530;
    int n=fn_8013DDD4((TObjC *)document,base+0x1a8);
    data->count=n;
    data->groups=(PathGroup *)fn_8002F37C(fn_8012850C(n*0x14+0x10,base+0x1b4),0,(void (*)())fn_8013E33C,0x14,n);
    f32 factor=lbl_805614C4;
    int index=0, groupIndex=0;
    while (document->child(index)) {
        TPathElement *element=(TPathElement *)document->child(index);
        if(fn_8013CB44(base+0x1a8,(TObj10 *)element)) {
            PathGroup *previous=groupIndex>0 ? data->groups : 0;
            PathGroup *group=&data->groups[groupIndex];
            if(previous) {
                int count=previous->count;
                group->count=count;
                group->nodes=(PathNode *)fn_8002F37C(fn_8012850C(count*0x24+0x10,&lbl_80559D30),fn_8013E338,0,0x24,count);
                TPathValue *attr=(TPathValue *)element->attribute(&lbl_80559D38);
                TVec2 tangent=attr->vector(lbl_80559D40);
                float scale=fn_80204CFC(base+0x1c0);
                f32 magnitude=fn_8013E300(&tangent);
                scale=factor*magnitude*scale;
                for(int i=0;i<group->count;i++) {
                    fn_8013E2AC(&group->nodes[i],&previous->nodes[i]);
                    fn_8013E19C(&group->nodes[i],scale);
                }
            } else {
                int count=fn_8013DE7C((TObj60 *)element,&lbl_80559D38);
                group->count=count;
                group->nodes=(PathNode *)fn_8002F37C(fn_8012850C(count*0x24+0x10,&lbl_80559D44),fn_8013E338,0,0x24,count);
                TPathValue *attr=(TPathValue *)element->attribute(&lbl_80559D28);
                float scale=attr->number(base+0x1d0,lbl_805614AC);
                scale=fn_80204CFC(base+0x1c0)*scale;
                int used=0;
                for(int j=0;element->child(j);j++) {
                    TPathElement *node=(TPathElement *)element->child(j);
                    if(fn_8013CB44(&lbl_80559D38,(TObj10 *)node)) {
                        fn_8013E054(&group->nodes[used],node,scale);
                        used++;
                    }
                }
            }
            for(int j=0;j<group->count;j++) {
                PathNode *node=&group->nodes[j];
                if(node->data[0x1e]) {
                    PathNode *before=0,*after=0;
                    for(unsigned int k=1;k<(unsigned int)group->count;k++) {
                        before=&group->nodes[(group->count+(j-k))%group->count];
                        if(!before->data[0x1e])break;
                    }
                    for(int k=1;k<group->count;k++) {
                        after=&group->nodes[(group->count+j+k)%group->count];
                        if(!after->data[0x1e])break;
                    }
                    fn_8013DF24(node,before,after);
                }
            }
            *(f32 *)((char *)group+8)=fn_80204CFC(base+0x1e0);
            group->pad[1]=1;
            group->pad[2]=10;
            sprintf(name,base+0x1f0,groupIndex+1);
            if(document->has(name)) {
                TDispatchStringInt20 *settings=(TDispatchStringInt20 *)document->find(name);
                group=&data->groups[groupIndex];
                if(settings) {
                    group->pad[1]=settings->v20(&lbl_80559D4C,groupIndex+1);
                    group->pad[2]=settings->v20(&lbl_80559D50,10);
                } else {
                    group->pad[1]=groupIndex+1;
                    group->pad[2]=10;
                }
                group->pad[2]=(s32)((f32)group->pad[2]*fn_80204CFC(base+0x200));
            } else {
                group=&data->groups[groupIndex];
                group->pad[1]=groupIndex+1;
                group->pad[2]=10;
                group->pad[2]=(s32)((f32)group->pad[2]*fn_80204CFC(base+0x200));
            }
            groupIndex++;
        }
        index++;
    }
    return out;
}
#pragma pop

#pragma dont_inline off

#pragma dont_inline on
extern "C" s32 fn_8013DDD4(TObjC *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;

    while (arg0->vC(i) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)arg0->vC(i))) {
            count++;
        }
        i++;
    }
    return count;
}

#pragma dont_inline on
extern "C" s32 fn_8013DE7C(TObj60 *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;

    while (arg0->v60(i) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)arg0->v60(i))) {
            count++;
        }
        i++;
    }
    return count;
}

extern "C" void fn_8013DF24(void *arg0, void *arg1, void *arg2) {
    f32 unit = lbl_805614A4;
    f32 *from = (f32 *)arg1;
    f32 *to = (f32 *)arg2;
    f32 *out = (f32 *)arg0;
    volatile f32 temp[10];
    u32 i = 0;
    do {
        f32 startZ;
        f32 startX;
        f32 dz;
        f32 dx;
        f32 endZ;
        f32 endX;
        startX = from[0];
        endX = to[0];
        startZ = from[2];
        endZ = to[2];
        dx = endX - startX;
        temp[8] = startX;
        dz = endZ - startZ;
        temp[9] = startZ;
        f32 xx = dx * dx;
        f32 zz = dz * dz;
        temp[6] = endX;
        temp[7] = endZ;
        f32 squared = xx + zz;
        temp[4] = dx;
        temp[5] = dz;
        f32 length = (f32)fn_8002F234(squared);
        f32 currentX = out[0];
        i++;
        f32 sx = temp[8];
        f32 vx = temp[4];
        f32 scale = lbl_805614AC / length;
        f32 vz = temp[5];
        f32 currentZ = out[2];
        f32 sz = temp[9];
        f32 dirX = vx * scale;
        temp[2] = currentX;
        f32 offsetX = currentX - sx;
        from += 3;
        f32 dirZ = vz * scale;
        to += 3;
        f32 offsetZ = currentZ - sz;
        temp[4] = dirX;
        temp[5] = dirZ;
        f32 projection = dirX * offsetX + dirZ * offsetZ;
        f32 resultX = sx + dirX * projection;
        f32 resultZ = sz + dirZ * projection;
        out[0] = resultX;
        out[1] = unit;
        out[2] = resultZ;
        out += 3;
        temp[2] = resultX;
        temp[3] = resultZ;
    } while (i < 2);
}

extern "C" void fn_8013E054(void *outPtr, void *objPtr, f32 angle) {
    u8 *out = (u8 *)outPtr;
    TVec2 center = ((TVec2 (*)(void *, const char *))(*(void ***)objPtr)[0x3C / 4])(objPtr, lbl_80559D58);
    TVec2 tanv = ((TVec2 (*)(void *, const char *))(*(void ***)objPtr)[0x3C / 4])(objPtr, lbl_80559D40);
    f32 a = center.x;
    f32 b = center.y;
    f32 c = tanv.x;
    f32 d = tanv.y;
    f32 negAngle = -angle;
    f32 nc = -c;
    *(f32 *)(out + 0x10) = lbl_805614A4;
    *(f32 *)(out + 4) = lbl_805614A4;
    *(f32 *)(out + 0xC) = a + d * angle;
    *(f32 *)(out + 0x0) = a + d * negAngle;
    *(f32 *)(out + 0x8) = b + nc * negAngle;
    *(f32 *)(out + 0x14) = b + nc * angle;
    fn_801E9DC4((s16 *)(out + 0x1C));
    u8 flag = ((u8 (*)(void *, const char *))(*(void ***)objPtr)[0xC / 4])(objPtr, lbl_80559D60);
    *(u8 *)(out + 0x1E) = flag;
    if (flag) {
        *(f32 *)(out + 0x20) = ((f32 (*)(void *, const char *))(*(void ***)objPtr)[0x24 / 4])(objPtr, lbl_80559D60);
    }
}

#pragma push
#pragma scheduling invalid_target
// Overload: used by fn_8013E19C for f32 return, fn_80140B98 uses the void version
extern "C" f32 PSQUATMultiply(void *, void *);
extern "C" void PSQUATMultiply_v(const Quaternion* a, const Quaternion* b, Quaternion* prod);

// Wrapper that matches the 2-arg call signature used in fn_80140B98 and fn_8013E19C
static inline f32 PSQUATMultiply_f32(void *a, void *b) {
    return PSQUATMultiply(a, b);
}
extern "C" f32 lbl_80561498, lbl_805614A4;
extern "C" void fn_8013E19C(void *arg0, f32 arg1) {
    f32 *p = (f32 *)arg0;
    f32 unit = *(volatile f32 *)&lbl_805614A4;
    void *other = (char *)arg0 + 0xC;
    p[4] = unit;
    p[1] = unit;
          f32 t = arg1 / PSQUATMultiply(arg0, other);
    f32 d = p[1];
    f32 b = p[2];
    f32 g = p[0];
    f32 e = p[3];
    f32 c = p[4];
    f32 a = p[5];
    f32 x = b + lbl_80561498 * (a - b);
    f32 y = d + lbl_80561498 * (c - d);
    f32 z = g + lbl_80561498 * (e - g);
    f32 bx = b - x;
    f32 by = d - y;
    f32 bz = g - z;
    f32 ax = a - x;
    f32 ay = c - y;
    f32 az = e - z;
    f32 qx = x + t * bx;
    f32 qy = y + t * by;
    f32 qz = z + t * bz;
    f32 rx = x + t * ax;
    f32 ry = y + t * ay;
    f32 rz = z + t * az;
    p[2] = qx;
    p[0] = qz;
    p[1] = qy;
    p[3] = rz;
    p[4] = ry;
    p[5] = rx;
}
#pragma scheduling reset
#pragma pop

extern "C" void fn_8013E2AC(void *arg0, void *arg1) {
    volatile u32 *src = (volatile u32 *)arg1;
    u32 word5, word4, word3, word2, word1, word0;
    f32 value3, value2, value1, value0;
    s16 half;
    u8 byte;

    word0 = src[0];
    word1 = src[1];
    word2 = src[2];
    word3 = src[3];
    word4 = src[4];
    word5 = src[5];
    value0 = *(volatile f32 *)((u8 *)arg1 + 0x18);
    half = *(volatile s16 *)((u8 *)arg1 + 0x1C);
    byte = *((volatile u8 *)arg1 + 0x1E);
    value3 = *(volatile f32 *)((u8 *)arg1 + 0x20);

    ((u32 *)arg0)[0] = word0;
    ((u32 *)arg0)[1] = word1;
    ((u32 *)arg0)[2] = word2;
    ((u32 *)arg0)[3] = word3;
    ((u32 *)arg0)[4] = word4;
    ((u32 *)arg0)[5] = word5;
    *(f32 *)((u8 *)arg0 + 0x18) = value0;
    *(s16 *)((u8 *)arg0 + 0x1C) = half;
    *((u8 *)arg0 + 0x1E) = byte;
    *(f32 *)((u8 *)arg0 + 0x20) = value3;
}

#pragma dont_inline off
extern "C" f64 fn_8002F234(f32);
#pragma scheduling on
extern "C" f32 fn_8013E300(void *arg0) {
    f32 y = *(f32 *)((u8 *)arg0 + 4);
    f32 x = *(f32 *)arg0;
    return (f32)fn_8002F234(x * x + y * y);
}
extern "C" void fn_8013E338(void) {

}

extern "C" void *fn_8013E33C(void *arg0, s32 arg1) {
    void *field;
    if (arg0 != 0) {
        field = *(void **)((u8 *)arg0 + 4);
        if (field != 0) {
            fn_80128670((s32)field - 0x10);
        }
        *(void **)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}

#pragma scheduling invalid_target
extern "C" void fn_8013E3A8(void *arg0, void *arg1) {
    u8 *dst = (u8 *)arg0;
    u8 *base = lbl_8032C530;
    s32 value;
    f32 fvalue;
    f32 scale;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x210), 0x19);
    else value = 0x19;
    *(s32 *)(dst + 0xC) = value;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x220), 0xA);
    else value = 0xA;
    *(s32 *)(dst + 4) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x230), lbl_805614E0);
    else fvalue = lbl_805614E0;
    *(f32 *)(dst + 0) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x248), lbl_805614E4);
    else fvalue = lbl_805614E4;
    *(f32 *)(dst + 8) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x258), lbl_805614E8);
    else fvalue = lbl_805614E8;
    *(f32 *)(dst + 0x10) = fvalue;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x270), 0xA);
    else value = 0xA;
    *(s32 *)(dst + 0x14) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x280), lbl_805614EC);
    else fvalue = lbl_805614EC;
    *(f32 *)(dst + 0x18) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x290), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x1C) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x29C), lbl_805614F0);
    else fvalue = lbl_805614F0;
    *(f32 *)(dst + 0x24) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2B0), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x20) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2C0), lbl_805614F4);
    else fvalue = lbl_805614F4;
    *(f32 *)(dst + 0x28) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2D4), lbl_805614E8);
    else fvalue = lbl_805614E8;
    *(f32 *)(dst + 0x30) = fvalue;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x2E8), 0x186A0);
    else value = 0x186A0;
    *(s32 *)(dst + 0x2C) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x300), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x38) = fvalue;

    *(f32 *)(dst + 0x34) = fn_80204CFC((const char *)(base + 0x310));
    scale = fn_80204CFC((const char *)(base + 0x200));
    *(f32 *)(dst + 0x24) = lbl_805614F8;
    *(s32 *)(dst + 0x2C) = (s32)((f32)*(s32 *)(dst + 0x2C) * scale);
}
#pragma push
#pragma processor 750
extern "C" void *fn_8013E6E4(void *arg0) {
    fn_8001DAE0((u8 *)arg0 + 0x98, 1.0f);
    fn_8001DAE0((u8 *)arg0 + 0xA0, 1.25f);
    fn_8001DAE0((u8 *)arg0 + 0xA8, 1.25f);
    fn_8001DAE0((u8 *)arg0 + 0xB0, 1.25f);
    fn_8001DAE0((u8 *)arg0 + 0xB8, 1.65f);
    fn_8001DAE0((u8 *)arg0 + 0xC0, 1.0f);
    fn_8001DAE0((u8 *)arg0 + 0xC8, 0.5f);
    fn_8001DAE0((u8 *)arg0 + 0xD0, 0.5f);
    fn_8001DAE0((u8 *)arg0 + 0xD8, 0.5f);
    return arg0;
}
#pragma pop
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_802CAC54(s32);
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *fn_8013E33C(void *, s32);
extern "C" void *__dt__Q210JASDrumSet5TPercFv(void *, s32);
extern "C" u8 lbl_8032CAF0[];
extern "C" s32 lbl_8055E1C0;
/* ZoneMaster::~ZoneMaster() - the deleting destructor of the zone master
 * object (vtable lbl_8032CAF0, layout at the top of this file).  Everything
 * the master owns goes with it: the child at +0x254, the objects it loaded
 * into its +8 array (zlmain/zlclosure/zlresult), the five zone texture
 * handles at +0xA0..+0xB0, the path data at +0x64, the zone table heap
 * "ZoneMaster::tab" at +0xB8, the JASDrumSet::TPerc member at +0x280 and the
 * sub-objects at +0x134, +0xC0 and +8.  The instance pointer lbl_8055E1C0 is
 * cleared on the way, and delete_flag > 0 (the object was allocated) frees
 * the ZoneMaster itself at the end. */
extern "C" void *fn_8013E77C(void *instance, s32 delete_flag) {
    class VObj { public: virtual void destroy(int); };  /* owned object: slot +8 is its destructor */
    u8 *self=(u8 *)instance;
    VObj *obj;
    VObj *child;
    s32 i,offset;
    if (self != 0) {
        child=*(VObj **)(self+0x254);
        *(void **)self=lbl_8032CAF0;  /* destroy from this class down */
        if (child != 0) { if (child != 0) child->destroy(1); }
        fn_802C6CF8(*(s32 *)(self+0xB4));  /* release the stream/handle at +0xB4 */
        i=0; offset=0;
        while (i<*(s32 *)(self+0xC)) {  /* every object loaded into the +8 array */
            obj=*(VObj **)(*(u8 **)(self+8)+offset);
            if (obj != 0) obj->destroy(1);
            offset+=4; i++;
        }
        fn_802CAC54(*(s32 *)(self+0xA0));  /* the five zone textures */
        fn_802CAC54(*(s32 *)(self+0xA4));
        fn_802CAC54(*(s32 *)(self+0xA8));
        fn_802CAC54(*(s32 *)(self+0xAC));
        fn_802CAC54(*(s32 *)(self+0xB0));
        obj=*(VObj **)(self+0x64);  /* the path data ... */
        if (obj != 0) {
            fn_8002F6AC(*(s32 *)((u8 *)obj+4),(void *)fn_8013E33C);  /* ... whose groups were allocated with fn_8013E33C as their destructor */
            *(s32 *)((u8 *)obj+4)=0;
            ((void (*)(void *))fn_80128668)(obj);
        }
        /* the owned objects, each cleared as the next one is taken over */
        obj=*(VObj **)(self+0x27C);
        *(VObj **)(self+0x64)=0;
        if (obj != 0) obj->destroy(1);
        obj=*(VObj **)(self+0x278);
        *(VObj **)(self+0x27C)=0;
        if (obj != 0) obj->destroy(1);
        obj=*(VObj **)(self+0x270);
        *(VObj **)(self+0x278)=0;
        if (obj != 0) obj->destroy(1);
        obj=*(VObj **)(self+0x274);
        *(VObj **)(self+0x270)=0;
        if (obj != 0) obj->destroy(1);
        obj=*(VObj **)(self+0x60);
        *(VObj **)(self+0x274)=0;
        if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x60)=0; }
        obj=*(VObj **)(self+0xB8);
        if (obj != 0) fn_80128670((s32)obj-0x10);  /* destroy the "ZoneMaster::tab" heap */
        *(VObj **)(self+0xB8)=0;
        lbl_8055E1C0=0;  /* the instance is gone */
        __dt__Q210JASDrumSet5TPercFv(self+0x280,-1);  /* the drum set member */
        if ((u32)self+0x134 != 0) {  /* ~Sub134_8013D2C4(), "if (this)" guard and all */
            obj=*(VObj **)(self+0x140);
            if (obj != 0) { fn_802ADE60((s32)obj,1); *(VObj **)(self+0x140)=0; }
            obj=*(VObj **)(self+0x148);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x148)=0; }
            obj=*(VObj **)(self+0x14C);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x14C)=0; }
            obj=*(VObj **)(self+0x150);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x150)=0; }
            obj=*(VObj **)(self+0x158);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x158)=0; }
            obj=*(VObj **)(self+0x15C);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x15C)=0; }
            obj=*(VObj **)(self+0x160);
            if (obj != 0) { if (obj != 0) obj->destroy(1); *(VObj **)(self+0x160)=0; }
        }
        if ((u32)self+0xC0 != 0) { if ((u32)self+0xC0 != 0) *(s32 *)(self+0xC0)=0; }  /* ~RingBuf8013D2C4() */
        if ((u32)self+8 != 0) {  /* ~SubArray8013D2C4(): the loaded-object array */
            if ((u32)self+8 != 0) {
                if ((u32)self+8 != 0) {
                    *(s32 *)(self+8)=0; *(s32 *)(self+0xC)=0; *(s32 *)(self+0x10)=0;
                }
            }
        }
        if (delete_flag>0) ((void (*)(void *))fn_80128668)(instance);  /* operator delete, deleting destructor */
    }
    return instance;
}

extern "C" void fn_8013EB0C(void *arg0, s32 arg1) {
    u8 *entry = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    if (*(u8 *)(entry + 0x118))
        *(s32 *)entry = 1;
}

extern "C" void fn_8013EB30(void *arg0) {
    struct Vec3 {
        f32 x, y, z;
    };
    u8 *self = (u8 *)arg0;
    f32 elapsed = fn_8013CB3C() - *(f32 *)(self + 0x290);
    u8 *obj = *(u8 **)(self + 0xB8) + fn_801E866C(0) * 0x12C;
    u8 *item = *(u8 **)(obj + 0x104);
    if (item != 0) {
        s32 idx = *(s32 *)(obj + 0xE8);
        s32 total = *(s32 *)(lbl_8042FB3C + 4);
        if (total - idx < 3) {
            Vec3 a, b;
            while (item[0x1E] != 0) {
                item = NextPathNode(self, item);
            }
            {
                s32 n = idx + 1;
                if (n < total) {
                    s32 count = total - n;
                    s32 j;
                    for (j = n; j < total; j++) {
                        do {
                            item = NextPathNode(self, item);
                        } while (item[0x1E] != 0);
                    }
                }
            }
            if (item == *(u8 **)(self + 0x28C) ||
                PSVECSquareDistance(item, (u8 *)fn_802C86DC() + 0x24) < lbl_80561504) {
                s32 r7, r9;
                f32 y;
                if (*(u8 **)(self + 0x28C) != item) {
                    *(u8 **)(self + 0x28C) = item;
                    *(f32 *)(self + 0x290) = fn_8013CB3C();
                }
                a = *(Vec3 *)item;
                b = *(Vec3 *)(item + 0xC);
                y = a.y;
                if (!(y > b.y)) y = b.y;
                y = lbl_80561508 + y;
                b.y = y;
                a.y = y;
                r7 = 0;
                r9 = 0x48;
                if (*(s32 *)(self + 0x68) == *(s32 *)(lbl_8042FB3C + 0x14) - 1) {
                    r7 = 0x48;
                    r9 = 0x72;
                }
                fn_802A9BFC(&a, &b, *(s32 *)(self + 0xA4), 0, r7, 0x100, r9, elapsed);
            }
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8013ED74(void *arg0) {
    struct Entry {
        u8 *item;
        f32 dist;
    };
    struct List {
        Entry *data;
        s32 count;
        s32 cap;
    };
    Entry storage[8];
    List list;
    f32 dist;
    u8 *self = (u8 *)arg0;
    s32 i;
    f32 *pos;
    s32 a, b;
    u8 *item;

    list.data = storage;
    list.cap = 8;
    list.count = 0;
    {
        s32 idx = fn_801E866C(-1);
        u8 *obj = *(u8 **)(self + 0xB8) + idx * 0x12C;
        item = *(u8 **)(obj + 0x104);
        if (*(u8 *)(obj + 0x118) != 0 && item != 0) {
            f32 spread;
            b = 0;
            a = 0;
            pos = fn_802C86DC();
            spread = lbl_80561498;
            i = 0;
            do {
                s32 ok = 1;
                u8 flag = item[0x1E];
                if (flag != 0 && a < 5) {
                    a++;
                } else if (flag == 0 && b < 2) {
                    b++;
                } else {
                    ok = 0;
                }
                if (ok != 0 && fn_8013CFF0((f32 *)item, pos, &dist) != 0) {
                    s32 v;
                    u8 *p;
                    if (list.count + 1 > list.cap) break;
                    p = item;
                    v = 0;
                    do {
                        fn_801E9E30(item + 0x1C, (f32 *)p);
                        *(f32 *)(p + 4) += spread;
                        v++;
                        p += 0xC;
                    } while ((u32)v < 2);
                    {
                        s32 n = list.count;
                        Entry *e;
                        list.count = n + 1;
                        e = &list.data[n];
                        e->item = item;
                        e->dist = (f32)fn_8002F234(dist);
                    }
                }
                {
                    u8 *group = *(u8 **)(*(u8 **)(self + 0x64) + 4) + *(s32 *)(self + 0x68) * 0x14;
                    u8 *array = *(u8 **)(group + 4);
                    u8 *last = array + *(s32 *)group * 0x24 - 0x24;
                    if (item != last) array = item + 0x24;
                    item = array;
                }
                i++;
            } while (i < 10);
        }
    }
    if (list.count > 0) {
        f32 v = fn_801E7E24();
        if (!((f32)__fabs((f64)v) <= *(f32 *)&lbl_80558DC4)) {
            s32 k;
            s32 off;
            k = 0;
            off = 0;
            for (; k < list.count; off += 8, k++) {
                u8 *it = *(u8 **)((u8 *)list.data + off);
                if (it[0x1E] == 0) {
                    u32 w = 0;
                    do {
                        fn_802981F8(it);
                        w++;
                        it += 0xC;
                    } while (w < 2);
                }
            }
        }
        ((void (*)(void *, void *))fn_80140D1C)(arg0, &list);
    }
    list.data = 0;
    list.count = 0;
    list.cap = 0;
}
#pragma pop
extern "C" f32 lbl_80561510;
extern "C" f32 lbl_80561514;
extern "C" void fn_802AE220(int);
extern "C" int fn_8001DFCC(void);
extern "C" f32 fn_8013EFB0(f32 arg0) {
    return arg0 - lbl_80561510;
}

extern f32 lbl_80561514;
extern f32 lbl_80561510;
extern void fn_802AE220(int);
extern int fn_8001DFCC(void);
extern f32 lbl_805614A4;
extern f32 lbl_805614AC;
extern f32 lbl_80561530;
extern f32 lbl_80561538;
extern f32 lbl_8056153C;
extern f32 lbl_80561540;
extern f32 lbl_80561498;
extern f32 lbl_805614FC;
extern f32 lbl_80561500;
extern "C" void fn_8001DAE0(void *, f32);
extern "C" f32 fn_8013EFBC(f32 arg0) { return lbl_80561514 - arg0; }

#pragma scheduling invalid_target
extern "C" unsigned int fn_8013EFC8(void *arg0) {
    f32 magnitude = __fabsf(*(f32 *)((u8 *)arg0 + 0x250));
    if (magnitude <= *(f32 *)&lbl_80558DC4) {
        if (*(u8 *)((u8 *)arg0 + 0x13C) != 0)
            ((TObj4C *)arg0)->v4C();
        s32 object = *(s32 *)((u8 *)arg0 + 0x140);
        if (object != 0)
            ((void (*)(s32, s32))fn_802AE220)(object, 0);
    } else {
        ((TObj4C *)arg0)->v4C();
    }
    if (((TObj4C *)arg0)->v68())
        fn_8001DFCC();
    return *(s32 *)((u8 *)arg0 + 0x134) != 4;
}
#pragma scheduling on
extern "C" s32 fn_8013F088(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x134) - 2) == 0;
}

extern "C" void fn_8013F09C(void) {
    ((void(*)())fn_80140A6C)();
}

extern "C" f32 lbl_80561520;
extern "C" f32 lbl_80561524;
extern "C" f32 lbl_80561528;
extern "C" f32 lbl_8056152C;
extern "C" f32 lbl_80561534;
extern "C" f32 lbl_8056151C;
extern "C" f32 lbl_80561544;
extern "C" f32 lbl_80561548;
extern "C" f32 lbl_80561550;
extern "C" f32 lbl_80561554;
extern "C" f32 lbl_80561558;
extern "C" f32 lbl_8056155C;
extern "C" f32 lbl_80561560;
extern "C" f32 lbl_80561564;
extern "C" f32 lbl_80561568;
extern "C" void fn_80147F30(unsigned long, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void *fn_80147C50(u32, s32, f32);
extern "C" void fn_801476D8(void *, void *, s32);
extern "C" void fn_80147EE0(void *, f32);
extern "C" void fn_80147BD0(s32, s32, s32, s32, s32, f32);
extern "C" void fn_801479A8(void *, void *, const char *, f64, ...);
extern "C" f32 lbl_8056154C;
extern "C" void fn_801476C4(void *arg0);
extern "C" void fn_8013CB90(void *arg0);
struct RenderData { u32 f0; f32 f4; f32 f8; u32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; };
#pragma scheduling invalid_target
extern "C" void fn_8013F0A0(void *arg0, void *arg1, void *arg2) {
    struct VStringFloat { virtual void d0(); virtual void d1(); virtual u8 *v10(const char *, f32); };
    struct RenderData { u32 f0; f32 f4; f32 f8; u32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; };
    f32 delta, progress, normalized, scale, factor;
    f32 f28, f27, f29;
    register u8 *dataObj;
    register char *labels;
    s32 drawCount, active = 0;
    s32 enabled;
    void *result;
    void *firstResult;
    RenderData data;
    enabled = *(s32 *)((u8 *)arg2 + 0x104);
    dataObj = (u8 *)arg2;
    labels = (char *)lbl_8032C530;
    if (enabled != 0) {
        delta = fn_8001DAE8(dataObj + 0xC8) - *(f32 *)(dataObj + 0xCC);
        scale = lbl_805614A4;
        active = 0;
        if (delta >= scale) {
            if (delta < *(f32 *)(dataObj + 0xC8)) active = 1;
        }
        if (active != 0) {
            delta = (fn_8001DAF0((f32 *)(dataObj + 0xC8)) - lbl_80561498) / lbl_80561498;
            factor = lbl_805614AC;
            factor = factor < delta ? delta : factor;
            factor = factor > lbl_805614A4 ? lbl_805614A4 : factor;
            scale = lbl_805614A4 + factor * lbl_805614AC;
        } else scale = lbl_805614AC;
        delta = fn_8013CB3C() - *(f32 *)(dataObj + 0x84);
        delta = (delta - *(f32 *)(lbl_8042FB3C + 0x24) - lbl_805614A4) / (*(f32 *)(lbl_8042FB3C + 0x20) - lbl_805614A4);
        normalized = lbl_805614AC;
        normalized = normalized < delta ? delta : normalized;
        normalized = normalized > lbl_805614A4 ? lbl_805614A4 : normalized;
        factor = normalized * lbl_805614BC;
        progress = lbl_805614AC + factor;
        firstResult = ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x394, factor);
        f28 = *(f32 *)((u8 *)firstResult + 0x10) * scale;
        f27 = *(f32 *)((u8 *)firstResult + 4);
        f29 = *(f32 *)((u8 *)firstResult + 8);
        drawCount = (s32)(lbl_80561520 * progress);
        if (drawCount > 0) {
            ((void (*)(unsigned long, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32))fn_80147F30)((unsigned long)0xFF00FF00, drawCount, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524, lbl_80561528, lbl_805614A4, lbl_805614A4, lbl_805614AC, lbl_805614AC);
            ((void (*)(unsigned long, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32))fn_80147F30)((unsigned long)0xFF000000, 1, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524, lbl_8056152C, lbl_805614A4, lbl_805614A4, lbl_805614AC, lbl_805614AC);
            ((void (*)(unsigned long, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32))fn_80147F30)((unsigned long)0xFF000000, 1, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524 + lbl_80561528 * (f32)drawCount, lbl_8056152C, lbl_805614A4, lbl_805614A4, lbl_805614AC, lbl_805614AC);
        }
        ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x3A0, 0.0f);
        result = ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x3B0, 0.0f);
        data = *(RenderData *)result;
        data.f4 = *(f32 *)((u8 *)firstResult + 4);
        data.f8 = *(f32 *)((u8 *)firstResult + 8);
        fn_8013CB90(&data);
        fn_80147EE0(&data, scale);
        delta = (progress - lbl_80561530) / lbl_80561534;
        factor = lbl_805614AC;
        factor = factor < delta ? delta : factor;
        factor = factor > lbl_805614A4 ? lbl_805614A4 : factor;
        fn_801476D8(&data, fn_80147C50(0xFFFFFF, -1, lbl_805614AC + factor * lbl_805614BC), *(s32 *)((u8 *)arg0 + 0xAC));
    }
}
#pragma scheduling on
extern "C" void fn_8013F434(void) {

}

extern "C" f32 lbl_80561530;
extern "C" f32 lbl_80561538;
extern "C" f32 lbl_8056153C;
extern "C" f32 lbl_80561540;
extern "C" f32 lbl_805614A4, lbl_805614AC, lbl_80561530, lbl_80561538, lbl_8056153C, lbl_80561540;
#pragma push
#pragma processor 750
#pragma scheduling on
extern "C" s32 fn_8013F438(f32 x) {
    f32 t = (x - lbl_80561530) / lbl_80561538;
    f32 v = (lbl_805614AC < t) ? lbl_805614AC : t;
    v = (v > lbl_805614A4) ? v : lbl_805614A4;
    return (s32)(lbl_8056153C + v * lbl_80561540);
}
#pragma pop
extern float lbl_805614A4, lbl_805614AC, lbl_805614F8, lbl_80561518, lbl_80561544, lbl_80561548;
#pragma scheduling invalid_target
extern "C" void fn_8013F498(void *arg0, void *arg1, f32 farg0) {
    volatile f32 scratch[6];
    f32 temp_f0, temp_f0_2, temp_f6, temp_f7, temp_f8;
    f32 var_f3 = lbl_805614AC;
    f32 var_f4;
    f64 temp_f2, temp_f5;
    temp_f0 = (farg0 - lbl_805614A4) / var_f3;
    var_f3 = var_f3 < temp_f0 ? var_f3 : temp_f0;
    var_f3 = var_f3 > lbl_805614A4 ? var_f3 : lbl_805614A4;
    var_f4 = lbl_805614AC;
    temp_f0_2 = (farg0 * farg0 - lbl_805614A4) / var_f4;
    temp_f6 = lbl_80561544 + var_f3 * lbl_805614F8;
    temp_f8 = temp_f6 * lbl_80561518;
    var_f4 = var_f4 < temp_f0_2 ? var_f4 : temp_f0_2;
    var_f4 = var_f4 > lbl_805614A4 ? var_f4 : lbl_805614A4;
    temp_f5 = -temp_f6;
    temp_f2 = -temp_f8;
    scratch[4] = lbl_805614A4;
    temp_f7 = lbl_805614A4 + var_f4 * lbl_80561548;
    scratch[5] = temp_f7;
    f32 out0 = lbl_805614A4 + (f32)temp_f5;
    f32 out2 = lbl_805614A4 + temp_f6;
    f32 out1 = temp_f7 + temp_f8;
    f32 out3 = temp_f7 + (f32)temp_f2;
    *(f32 *)arg0 = out0;
    *(f32 *)((u8 *)arg0 + 4) = out1;
    scratch[2] = (f32)temp_f5;
    scratch[3] = temp_f8;
    scratch[0] = temp_f6;
    scratch[1] = (f32)temp_f2;
    *(f32 *)arg1 = out2;
    *(f32 *)((u8 *)arg1 + 4) = out3;
}

#pragma use_lmw_stmw off
extern "C" void fn_8013F580(void *arg0, void *arg1, void *arg2) {
    struct Lookup {
        virtual void dummy();
        virtual void *find(const char *);
        virtual void *get(const char *);
    };
    struct TextStyle { u32 a; u32 b[2]; u32 d; f32 size; u32 f, color, h; };
    struct DrawStyle { u32 a; u32 b[2]; u32 d; f32 size, f, g, h, i, j; };
    u8 *self = (u8 *)arg0;
    u8 *other = (u8 *)arg2;
    char *labels = (char *)lbl_8032C530;
    f32 diff, ratio, opacity;
    s32 i, active;
    void *item, *icon;
    TextStyle text;
    DrawStyle draw;
    Lookup *lookup;
    if (*(s32 *)(self + 0x68) > 0) {
        diff = fn_8001DAE8(self + 0x74) - *(f32 *)(self + 0x78);
        active = 0;
        if (diff >= lbl_805614A4 && diff < *(f32 *)(self + 0x74)) active = 1;
        if (active) {
            ratio = (fn_8001DAF0((f32 *)(self + 0x74)) - lbl_80561538) / lbl_8056154C;
            ratio = ratio > lbl_805614AC ? ratio : lbl_805614AC;
            ratio = ratio > lbl_805614A4 ? lbl_805614A4 : ratio;
            opacity = lbl_805614A4 + ratio * lbl_805614AC;
            lookup = *(Lookup **)(self + 0x54);
            item = lookup->find(labels + 0x3FC);
            if (item) {
                text = *(TextStyle *)item;
                text.size *= lbl_80561550;
                text.color = 0xFFFFFF;
                fn_801479A8(item, &text, labels + 0x40C, opacity);
            }
            item = (*(Lookup **)(self + 0x54))->get(labels + 0x41C);
            icon = (*(Lookup **)(self + 0x54))->get(labels + 0x3A0);
            if (item) {
                draw = *(DrawStyle *)item;
                *(f32 *)&draw.b[0] -= draw.size * lbl_80561498 * (f32)*(s32 *)(other + 0x74);
                for (i = 0; i < *(s32 *)(other + 0x74); ++i) {
                    fn_80147BD0((s32)&draw, (s32)icon, -1, -1, *(s32 *)(self + 0xAC), opacity);
                    *(f32 *)&draw.b[0] += draw.size;
                }
            }
        } else {
            diff = fn_8001DAE8(self + 0x6C) - *(f32 *)(self + 0x70);
            active = 0;
            if (diff >= lbl_805614A4 && diff < *(f32 *)(self + 0x6C)) active = 1;
            if (active) {
                ratio = (fn_8001DAF0((f32 *)(self + 0x6C)) - lbl_80561538) / lbl_8056154C;
                ratio = ratio > lbl_805614AC ? ratio : lbl_805614AC;
                ratio = ratio > lbl_805614A4 ? lbl_805614A4 : ratio;
                opacity = lbl_805614A4 + ratio * lbl_805614AC;
                item = (*(Lookup **)(self + 0x54))->find(labels + 0x3FC);
                if (item) {
                    TextStyle text2 = *(TextStyle *)item;
                    text2.size *= lbl_80561550;
                    text2.color = 0xFFFFFF;
                    fn_801479A8(item, &text2, labels + 0x430, opacity, *(s32 *)(self + 0x68) + 1);
                }
            }
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" s32 fn_8013F438(f32);
extern "C" void fn_8013F498(void *, void *, f32);
extern "C" f32 fn_8013EFBC(f32);
extern "C" void fn_8000FF88(s32, s32, void *, f32, f32, f32);
extern "C" void fn_8013F918(void *arg0, void *arg2) {
    f32 temp_f1;
    f32 temp_f0;
    f32 var_f2;
    f32 temp_f31;
    s32 temp_r31;
    s32 var_r0;
    s32 temp_r3;
    f32 sp1C;
    f32 temp_f2;
    f32 temp_f3;
    
    temp_f1 = fn_8001DAE8((u8 *)arg2 + 0xA8) - *(f32 *)((u8 *)arg2 + 0xAC);
    var_r0 = 0;
    if ((temp_f1 == lbl_805614A4) && (temp_f1 < *(f32 *)((u8 *)arg2 + 0xA8))) {
        var_r0 = 1;
    }
    if (var_r0 != 0) {
        temp_f31 = fn_8001DAF0((f32 *)((u8 *)arg2 + 0xA8));
        temp_r3 = fn_8013F438(temp_f31);
        temp_r31 = (temp_r3 << 0x18) | 0xFF0000 | 0x7F00;
        fn_8013F498((void *)((u8 *)arg2 + 0x18), (void *)((u8 *)arg2 + 0x10), temp_f31);
        var_f2 = lbl_805614AC;
        temp_f0 = (temp_f31 - lbl_805614E4) / lbl_80561554;
        if (var_f2 < temp_f0) {
            var_f2 = temp_f0;
        }
        if (var_f2 > lbl_805614A4) {
            var_f2 = lbl_805614A4;
        }
        temp_f2 = var_f2 * lbl_8056155C;
        temp_f31 = lbl_80561558 + temp_f2;
        sp1C = *(f32 *)((u8 *)arg2 + 0x1C);
        fn_8000FF88(temp_r31, 0xC, &lbl_8032C96C, temp_f31, lbl_805614A4, fn_8013EFBC(sp1C));
    }
    
    temp_f1 = *(f32 *)((u8 *)arg2 + 0x94);
    if (temp_f1 < *(f32 *)((u8 *)lbl_8042FB3C + 8)) {
        var_f2 = lbl_805614AC;
        temp_f3 = *(f32 *)((u8 *)arg2 + 0xAC);
        var_f2 = var_f2 < (temp_f1 / *(f32 *)((u8 *)lbl_8042FB3C + 8)) ? var_f2 : (temp_f1 / *(f32 *)((u8 *)lbl_8042FB3C + 8));
        var_f2 = var_f2 > lbl_805614A4 ? lbl_805614A4 : var_f2;
        temp_f2 = lbl_805614AC - var_f2;
        temp_r3 = (s32)(lbl_8056151C * temp_f2);
        temp_r3 = (temp_r3 << 0x18) | 0xFF0000 | 0xFFFF;
        s32 temp_r4 = (s32)(lbl_80561568 * (lbl_805614AC - temp_f2));
        fn_80147F30((unsigned long)temp_r3, temp_r4, *(s32 *)((u8 *)arg0 + 0xA8), 
                    lbl_80561510, lbl_80561560, lbl_80561548, lbl_805614A4, lbl_80561524, 
                    lbl_80561564, lbl_805614A4, lbl_805614A4);
    }
}

#pragma scheduling on
extern "C" int fn_8013FC6C(void* arg0) {
    struct V {
        virtual int a0(int); virtual int a1(int); virtual int a2(int);
        virtual int a3(int); virtual int a4(int); virtual int a5(int);
        virtual int a6(int);
    };
    int a = 0, b = 0, c = 0;
    V* obj = (V*)arg0;
    while (c < *(int*)((char*)arg0 + 0xBC)) {
        if (*(unsigned char*)(*(char**)((char*)arg0 + 0xB8) + a + 0x118)) {
            if (obj->a6(c) == 0) {
                b++;
                if (b >= *(int*)((char*)arg0 + 0x130)) return 1;
            }
        }
        a += 0x12C;
        c++;
    }
    return 0;
}
#pragma scheduling on
extern "C" int fn_8013FD20(void *arg0, int arg1) {
    int result = 1;
    int valid = 0;
    if (*(int *)(*(char **)((char *)arg0 + 0xB8) + arg1 * 0x12C + 0x11C) != 0) {
        float diff = fn_8001DAE8((char *)arg0 + 0x74) -
                     *(float *)((char *)arg0 + 0x78);
        if (diff >= lbl_805614A4 && diff < *(float *)((char *)arg0 + 0x74)) {
            valid = 1;
        }
        if (valid == 0) {
            result = 0;
        }
    }
    return result;
}

extern "C" void fn_8013FDB0(void *arg0, void *arg2) {
    return;
}

extern "C" f32 fn_8001DAF0(f32 *);
extern "C" s32 fn_801E866C(s32);
extern "C" void fn_8001DF08(s32, s32);
extern "C" f64 lbl_805614D8;
/* Compute a clamped/adjusted value and forward it to fn_8001DF08 for the given handle/state. */
extern "C" void fn_8014052C(void *unused, s32 arg0, u8 *arg1) {
    s32 v = *(s32 *)(arg1 + 0x10C) - *(s32 *)(arg1 + 0x114);
    f32 f = fn_8001DAE8((void *)(arg1 + 0x98)) - *(f32 *)(arg1 + 0x9C);
    s32 flag = 0;
    if (f >= lbl_805614A4 && f < *(f32 *)(arg1 + 0x98))
        flag = 1;
    if (flag != 0 && *(s32 *)(arg1 + 0x80) > 0x32) {
        f32 delta = lbl_805614AC - fn_8001DAF0((f32 *)(arg1 + 0x98));
        f32 count = (f32)*(s32 *)(arg1 + 0x80);
        v = *(s32 *)(arg1 + 0x10C) - (s32)(count * delta);
    }
    fn_8001DF08(fn_801E866C(arg0), v);
}

extern "C" s32 fn_80147ABC(void *, void *, const char *, f64, ...);
extern "C" char lbl_8032CA48[];
extern "C" char lbl_8032CA58[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80140614(void *arg0, void *arg1, void *arg2) {
    class Item {
    public:
        virtual void d0();
        virtual void *lookup(void *);
    };
    struct Bounds {
        u8 pad[0xA0];
        volatile f32 low0;
        volatile f32 high0;
        volatile f32 low1;
        volatile f32 high1;
    };
    Bounds *bounds = (Bounds *)arg2;
    f32 d1 = fn_8001DAE8((void *)&bounds->low1) - bounds->high1;
    s32 flag = 0;
    if (d1 >= lbl_805614A4) {
        if (d1 < bounds->low1)
            flag = 1;
    }
    if (flag == 0) {
        f32 d2 = fn_8001DAE8((void *)&bounds->low0) - bounds->high0;
        flag = 0;
        if (d2 >= lbl_805614A4) {
            if (d2 < bounds->low0)
                flag = 1;
        }
    }
    if (flag != 0) {
        void *r1 = ((Item *)*(void **)((char *)arg0 + 0x54))->lookup(lbl_8032CA48);
        void *r2 = ((Item *)*(void **)((char *)arg0 + 0x54))->lookup(lbl_8032CA58);
        f32 d = fn_8001DAF0((f32 *)&bounds->low0);
        fn_80147ABC(r1, r2, (const char *)*(s32 *)((char *)r1 + 0x1C), (f64)(d * d));
    }
  }

#pragma processor 750
#pragma push
#pragma optimize level=4
#pragma scheduling invalid_target
extern void fn_80147BD0(s32, s32, s32, s32, s32, f32);
extern f32 lbl_805614C4;
extern f32 fn_8001DAF0(f32 *);
extern f32 fn_8013CB3C(void);
#pragma processor 750
#pragma push
#pragma optimize level=4
#pragma scheduling invalid_target
extern "C" void fn_80140728(void *arg0, void *arg1, void *arg2) {
    u8 *base = lbl_8032C530;
    f32 temp_f1 = fn_8001DAE8((u8 *)arg2 + 0xD8) - *(f32 *)((u8 *)arg2 + 0xDC);
    s32 var_r0 = 0;
    void *temp_r28;
    void *temp_r29;
    void *temp_r3;
    if ((temp_f1 >= lbl_805614A4) && (temp_f1 < *(f32 *)((u8 *)arg2 + 0xD8))) {
        var_r0 = 1;
    }
    if (var_r0 != 0) {
        fn_8001DAF0((f32 *)((u8 *)arg2 + 0xD8));
        temp_r28 = ((void *(*)(void *, void *))(*(void ***) *(void **)((u8 *)arg0 + 0x54))[4])(*(void **)((u8 *)arg0 + 0x54), base + 0x3B0);
        temp_r29 = ((void *(*)(void *, void *))(*(void ***) *(void **)((u8 *)arg0 + 0x54))[4])(*(void **)((u8 *)arg0 + 0x54), base + 0x448);
        temp_r3 = ((void *(*)(void *, void *))(*(void ***) *(void **)((u8 *)arg0 + 0x54))[4])(*(void **)((u8 *)arg0 + 0x54), base + 0x3A0);
        if ((temp_r28 != NULL) && (temp_r29 != NULL) && (temp_r3 != NULL)) {
            u8 sp58[0x28];
            u8 sp30[0x28];
            u8 sp8[0x28];
            *(s32 *)sp58 = *(s32 *)temp_r28;
            *(s32 *)(sp58 + 4) = *(s32 *)((u8 *)temp_r28 + 4);
            *(s32 *)(sp58 + 8) = *(s32 *)((u8 *)temp_r28 + 8);
            *(s32 *)(sp58 + 0xC) = *(s32 *)((u8 *)temp_r28 + 0xC);
            *(f32 *)(sp58 + 0x10) = *(f32 *)((u8 *)temp_r28 + 0x10);
            *(f32 *)(sp58 + 0x14) = *(f32 *)((u8 *)temp_r28 + 0x14);
            *(f32 *)(sp58 + 0x18) = *(f32 *)((u8 *)temp_r28 + 0x18);
            *(f32 *)(sp58 + 0x1C) = *(f32 *)((u8 *)temp_r28 + 0x1C);
            *(f32 *)(sp58 + 0x20) = *(f32 *)((u8 *)temp_r28 + 0x20);
            *(f32 *)(sp58 + 0x24) = *(f32 *)((u8 *)temp_r28 + 0x24);
            *(s32 *)sp30 = *(s32 *)temp_r29;
            *(s32 *)(sp30 + 4) = *(s32 *)((u8 *)temp_r29 + 4);
            *(s32 *)(sp30 + 8) = *(s32 *)((u8 *)temp_r29 + 8);
            *(s32 *)(sp30 + 0xC) = *(s32 *)((u8 *)temp_r29 + 0xC);
            *(f32 *)(sp30 + 0x10) = *(f32 *)((u8 *)temp_r29 + 0x10);
            *(f32 *)(sp30 + 0x14) = *(f32 *)((u8 *)temp_r29 + 0x14);
            *(f32 *)(sp30 + 0x18) = *(f32 *)((u8 *)temp_r29 + 0x18);
            *(f32 *)(sp30 + 0x1C) = *(f32 *)((u8 *)temp_r29 + 0x1C);
            *(f32 *)(sp30 + 0x20) = *(f32 *)((u8 *)temp_r29 + 0x20);
            *(f32 *)(sp30 + 0x24) = *(f32 *)((u8 *)temp_r29 + 0x24);
            *(s32 *)sp8 = *(s32 *)temp_r3;
            *(s32 *)(sp8 + 4) = *(s32 *)((u8 *)temp_r3 + 4);
            *(s32 *)(sp8 + 8) = *(s32 *)((u8 *)temp_r3 + 8);
            *(s32 *)(sp8 + 0xC) = *(s32 *)((u8 *)temp_r3 + 0xC);
            *(f32 *)(sp8 + 0x10) = *(f32 *)((u8 *)temp_r3 + 0x10);
            *(f32 *)(sp8 + 0x14) = *(f32 *)((u8 *)temp_r3 + 0x14);
            *(f32 *)(sp8 + 0x18) = *(f32 *)((u8 *)temp_r3 + 0x18);
            *(f32 *)(sp8 + 0x1C) = *(f32 *)((u8 *)temp_r3 + 0x1C);
            *(f32 *)(sp8 + 0x20) = *(f32 *)((u8 *)temp_r3 + 0x20);
            *(f32 *)(sp8 + 0x24) = *(f32 *)((u8 *)temp_r3 + 0x24);
            fn_8013CB90(sp30);
            fn_8013CB90(sp58);
            if (*(s32 *)((u8 *)arg2 + 0x60) > 0) {
                f32 delta = fn_8013CB3C() - *(f32 *)((u8 *)arg2 + 0xDC);
                f32 x = *(f32 *)((u8 *)arg2 + 0xD8);
                f32 scaled = x * lbl_80561498;
                f32 ratio = ((delta - lbl_805614A4)) / (scaled - lbl_805614A4);
                f32 v = (lbl_805614AC < ratio) ? ratio : lbl_805614AC;
                v = (v > lbl_805614A4) ? v : lbl_805614A4;
                fn_80147BD0((s32)sp58, (s32)sp8, -1, 0xFFFFFF, *(s32 *)((u8 *)arg0 + 0xAC), lbl_805614A4 + (v * lbl_805614AC));
                delta = fn_8013CB3C() - *(f32 *)((u8 *)arg2 + 0xDC);
                x = *(f32 *)((u8 *)arg2 + 0xD8);
                scaled = x * lbl_80561498;
                ratio = (delta - scaled) / (x - scaled);
                v = (lbl_805614AC < ratio) ? ratio : lbl_805614AC;
                v = (v > lbl_805614A4) ? v : lbl_805614A4;
                fn_80147BD0((s32)sp30, (s32)sp8, -1, 0xFFFFFF, *(s32 *)((u8 *)arg0 + 0xAC), lbl_805614A4 + (v * lbl_805614AC));
            } else {
                f32 ratio = lbl_805614C4 * fn_8001DAF0((f32 *)((u8 *)arg2 + 0xD8));
                f32 v = (lbl_805614AC < ratio) ? ratio : lbl_805614AC;
                v = (v > lbl_805614A4) ? v : lbl_805614A4;
                fn_80147BD0((s32)sp30, (s32)sp8, -1, 0xFFFFFF, *(s32 *)((u8 *)arg0 + 0xAC), v);
            }
        }
    }
}
#pragma optimize reset
#pragma pop

  
extern "C" void fn_80140B98(void *arg0, void *arg1, s32 arg2) {
    f32 temp_f0 = ((f32 *)arg1)[5];  // 0x14/4
    f32 temp_f8 = ((f32 *)arg1)[2];  // 0x8/4
    f32 temp_f5 = ((f32 *)arg1)[4];  // 0x10/4
    f32 temp_f7 = ((f32 *)arg1)[1];  // 0x4/4
    f32 temp_f6 = ((f32 *)arg1)[3];  // 0xC/4
    f32 temp_f5_2 = ((f32 *)arg1)[0];  // 0x0/4

    f32 temp_f1 = temp_f0 - temp_f8;  // fsubs f1, f0, f8
    f32 temp_f4 = lbl_80561498;
    f32 temp_f2 = temp_f8 - temp_f0;  // fsubs f0, f8, f0
    f32 temp_f3 = temp_f5 - temp_f7;  // fsubs f3, f5, f7
    f32 temp_f5_3 = temp_f7 - temp_f5;  // fsubs f5, f7, f5
    f32 temp_f1_2 = temp_f5_2 - temp_f6;  // fsubs f1, f5_2, f6
    f32 temp_f2_2 = temp_f6 - temp_f5_2;  // fsubs f2, f6, f5_2

    f32 temp_f8_2 = temp_f8 + (temp_f4 * temp_f1);  // fadds f8, f8, f2 (fmuls f2, f4, f1)
    f32 temp_f3_2 = temp_f7 + (temp_f4 * temp_f3);  // fadds f3, f7, f3 (fmuls f3, f4, f3)
    f32 temp_f2_3 = temp_f5_2 + (temp_f4 * temp_f1_2);  // fadds f2, f5_2, f2 (fmuls f2, f4, f1_2)
    f32 temp_f3_3 = temp_f8 + (temp_f4 * temp_f2);  // fadds f3, f8, f2 (fmuls f2, f4, f2)
    f32 temp_f5_4 = temp_f7 + (temp_f4 * temp_f5_3);  // fadds f5, f7, f3 (fmuls f3, f4, f5_3)
    f32 temp_f2_4 = temp_f5_2 + (temp_f4 * temp_f2_2);  // fadds f2, f5_2, f2 (fmuls f2, f4, f2_2)

    f32 sp18[3] = {temp_f8_2, temp_f3_2, temp_f2_3};
    f32 sp24[3] = {temp_f3_3, temp_f5_4, temp_f2_4};
    f32 sp30[3] = {temp_f1_2, temp_f3, temp_f1};

    PSVECNormalize((Vec*)sp30, (Vec*)sp30);

    sp24[0] = lbl_805614A4;
    sp24[1] = lbl_805614AC;
    sp24[2] = lbl_805614A4;
    f32 sp34[3];
    PSVECCrossProduct((Vec*)sp30, (Vec*)sp24, (Vec*)sp34);

    f32 temp_f31 = lbl_80561584;
    f32 temp_f10 = PSQUATMultiply_f32(arg1, (char*)arg1 + 0xC) / temp_f31;

    f32 sp24_mul[3] = {sp18[0] * temp_f10, sp18[1] * temp_f10, sp18[2] * temp_f10};

    f32 sp30_2[3] = {sp24_mul[0], sp24_mul[1], sp24_mul[2]};

    f32 sp34_2[3] = {sp24_mul[0], sp24_mul[1], sp24_mul[2]};
    f32 sp38[3] = {sp30_2[0], sp30_2[1], sp30_2[2]};

    s32 temp_r3 = ((s32*)arg0)[0xB4/4];
    fn_802C70AC(temp_r3, sp24_mul, -1, arg2);
}

#pragma scheduling reset
#pragma pop
extern "C" void fn_8013EB30(void *);
extern "C" void fn_80140B98(void *, void *, s32);
extern "C" void fn_80141558(void *, s32, s32, s32);
// fn_80140D1C: processes array items, flushing buffer to fn_80141558 when item[0x1E] set, or stores to dst
extern "C" void fn_80140D1C(void *arg0, void *arg1, void *arg2) {
 f32 buffer[16]; f32 *dst=buffer; s32 count=*(s32 *)((u8 *)arg1+4)-1, idx=0, i, cap, head, end; u8 *item;
 fn_8013EB30(arg0);
 while(count>=0){ item=*(u8 **)(*(u8 **)arg1+count*8);
 if(item[0x1E]){ if(idx>0){fn_80141558((u8 *)arg0+0x280,(s32)dst,idx,*(s32 *)((u8 *)arg0+0x288));idx=0;} fn_80140B98(arg0,*(void **)(*(u8 **)arg1+count*8),2);}
 else {dst[idx*3]=*(f32 *)item;dst[idx*3+1]=*(f32 *)(item+4);dst[idx*3+2]=*(f32 *)(item+8);idx++;dst[idx*3]=*(f32 *)(item+0xC);dst[idx*3+1]=*(f32 *)(item+0x10);dst[idx*3+2]=*(f32 *)(item+0x14);idx++;} count--;}
 if(idx>0){fn_80141558((u8 *)arg0+0x280,(s32)dst,idx,*(s32 *)((u8 *)arg0+0x288));idx=0;}
 i=0; do {cap=*(s32 *)((u8 *)arg0+0xC4);head=*(s32 *)((u8 *)arg0+0xCC);end=(cap+(*(s32 *)((u8 *)arg0+0xC8)-head))%cap;if(i>=end)break;item=*(u8 **)((u8 *)arg0+0xC0);fn_80140B98(arg0,*(void **)(item+((i+cap+head)%cap)*12+8),4);i++;}while(1);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" u32 fn_80140F10(void *arg0, void *arg1) {
    u8 *p=(u8 *)arg0, *input=(u8 *)arg1;
    if (*(s32 *)(p+0xc)==0) return 0;
    s32 other=*(s32 *)(input+0x110);
    s32 total=*(s32 *)(input+0x88);
    s32 count=*(s32 *)(input+0x114);
    s32 completed=0, remaining=count;
    fn_801345D8(p+0x30,0x14,&lbl_80559D6C,*(s32 *)(input+0x18)+(*(s32 *)(input+0x10)+*(s32 *)(input+0x14)));
    if(count && *(f32 *)(p+4)>lbl_805614A4) {
        f32 fraction=((lbl_8055E3C8-*(f32 *)(p+4))-lbl_805614A4)/lbl_805614AC;
        fraction=lbl_805614AC<fraction ? lbl_805614AC : fraction;
        fraction=fraction>lbl_805614A4 ? fraction : lbl_805614A4;
        completed=(s32)(lbl_805614A4+fraction*((lbl_80561498+(f32)count)-lbl_805614A4));
        remaining=count-completed;
    }
    fn_801345D8(p+0x44,0x14,&lbl_80559D6C,completed);
    if(p[0x10]) {
        {const char *s=lbl_80559D80; char *d=(char*)p+0xb2; int count=0x14; char c;
       goto check0;
check0: if (--count>0) goto copy0; d[-1]=0; goto done0;
copy0: c=*s++; *d++=c; if ((signed char)c != 0) goto check0;
done0:;}
        {const char *s=lbl_80559D80; char *d=(char*)p+0x58; int count=0x14; char c;
       goto check1;
check1: if (--count>0) goto copy1; d[-1]=0; goto done1;
copy1: c=*s++; *d++=c; if ((signed char)c != 0) goto check1;
done1:;}
    } else {
        if(!lbl_8055E1C8){fn_801312EC(lbl_8042FB78,lbl_8032CA74);lbl_8055E1C8=1;}
        fn_80130980(p+0xb2,0x14,2,(f32)remaining);
        if(*(u32 *)(lbl_8042FB78+8)!=lbl_8055E044)fn_80131318(lbl_8042FB78);
        {const char *s=*(char **)(lbl_8042FB78+4); char *d=(char*)p+0x58; int count=0x14; char c;
       goto check2;
check2: if (--count>0) goto copy2; d[-1]=0; goto done2;
copy2: c=*s++; *d++=c; if ((signed char)c != 0) goto check2;
done2:;}
    }
    fn_801345D8(p+0x6c,0x14,&lbl_80559D6C,other);
    fn_801308F4(p+0x80,0x14,total);
    fn_801308F4(p+0x9e,0x14,total-count);
    if(fn_801609C4(total)!=-1) {
        {const char *s=__AXGetStackHead(); char *d=(char*)p+0x94; int count=10; char c;
       goto check3;
check3: if (--count>0) goto copy3; d[-1]=0; goto done3;
copy3: c=*s++; *d++=c; if ((signed char)c != 0) goto check3;
done3:;}
    } else {
        {const char *s=&lbl_80559D84; char *d=(char*)p+0x94; int count=10; char c;
       goto check4;
check4: if (--count>0) goto copy4; d[-1]=0; goto done4;
copy4: c=*s++; *d++=c; if ((signed char)c != 0) goto check4;
done4:;}
    }
    if(*(s32 *)(p+0x10c))p[8]=0;
    switch(*(s32 *)p) {
    case 0:
        fn_802ADFF4(*(s32 *)(p+0xc),*(s32 *)(p+0x108));
        if(strlen((char *)p+0xee)) {
            u8 *widget=*(u8 **)(p+0x2c);
                if(widget && !widget[0x19]){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
        } else {
            u8 *widget=*(u8 **)(p+0x28);
            if(widget && !widget[0x19]){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
        }
        if(count>0) {
            u8 *widget=*(u8 **)(p+0x14);
            if(widget){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
        } else {
            u8 *widget=*(u8 **)(p+0x18);
            if(widget){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
        }
        *(s32 *)p=1;
        break;
    case 1:
        if(*(s32 *)(p+0x110) && *(f32 *)(p+4)<lbl_805614A4) *(f32 *)(p+4)=lbl_8055E3C8;
        if(*(s32 *)(p+0x110)==2 && !p[0x20]) {
            u8 *widget=*(u8 **)(p+0x1c);
            p[0x20]=1;
            if(widget){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
        }
        if(*(s32 *)(p+0x114)) {
            fn_802AE02C(*(s32 *)(p+0xc),*(s32 *)(p+0x108));
            *(s32 *)p=2;
        }
        break;
    case 2:
        if(p[9]) {
            fn_802AE0B8(*(s32 *)(p+0xc),*(s32 *)(p+0x108));
            u8 *widget=*(u8 **)(p+0x24);
            if(widget){widget[0x49]=1;widget[0x4b]=0;widget[0x4a]=0;}
            *(s32 *)p=3;
        }
        break;
    case 3:
        if(*(s32 *)(p+0x118)) {
            fn_802AE02C(*(s32 *)(p+0xc),*(s32 *)(p+0x108));
            *(s32 *)p=4;
        }
        break;
    }
    fn_802AE168(*(s32 *)(p+0xc));
    return *(s32 *)p!=4;
}
#pragma pop

extern "C" void fn_80141454(void) {

}

extern "C" void fn_80141458(void) {

}

extern "C" char lbl_8032CA94[];
extern "C" void *fn_8013D2C4(void *, void *);
extern "C" void fn_8014145C(void *arg0) {
    void **object = fn_801284F8(0x298, lbl_8032CA94);
    if (object != 0) {
        fn_8013D2C4(object, arg0);
    }
}

extern "C" char lbl_8032CAA0[];
extern "C" char lbl_8032CAB0[];
extern "C" void *fn_802CAC28(const char *, s32);
extern "C" void *fn_801414A4(void *arg0) {
    void **fields = (void **)arg0;
    fields[0] = fn_802CAC28(lbl_8032CAA0, 0);
    fields[1] = fn_802CAC28(lbl_8032CAB0, 0);
    return arg0;
}

extern "C" void *__dt__Q210JASDrumSet5TPercFv(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(s32 *)arg0);
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 4));
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_802A96E8(s32, s32, s32, s32, s32, void *);
extern "C" void fn_80141558(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_802A96E8(arg1, arg2, arg3, *(s32 *)((char *)arg0 + 0), *(s32 *)((char *)arg0 + 4), arg0);
}

extern "C" void fn_80141574(char *arg0) {
    return;
}

extern "C" void fn_80141C84(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    *(s32 *)(p + 0x88) = *(s32 *)(p + 0x10C);
}

extern "C" double floor(double);
extern "C" f32 lbl_805614AC;
extern "C" u8 *fn_80131234(const char *);
extern "C" char lbl_80559D80[1];
extern "C" char lbl_8032CC1C[];
extern "C" char lbl_8032CC40[];
extern "C" char lbl_8032CC64[];
extern "C" f32 fn_80141C9C(f32 arg0) {
    return floor(arg0);
}

#pragma push
#pragma scheduling invalid_target
/* Copy three bounded (20-byte) name strings into fixed fields of the record:
   offsets 0xC6 and 0xDA from looked-up names, and 0xEE from a default string. */
extern "C" void fn_80141CC0(char *arg0) {
    {
        char *src = (char *)fn_80131234(lbl_8032CC1C);
        char c;
        long len = 20;
        char *dst = arg0 + 0xC6;

        goto copy_a;
    check_a:
        if (--len > 0)
            goto copy_a;
        dst[-1] = 0;
        goto done_a;
    copy_a:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_a;
        goto check_a;
    done_a:
        ;
    }

    {
        char *src = (char *)fn_80131234(lbl_8032CC40);
        char c;
        long len = 20;
        char *dst = arg0 + 0xDA;

        goto copy_b;
    check_b:
        if (--len > 0)
            goto copy_b;
        dst[-1] = 0;
        goto done_b;
    copy_b:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_b;
        goto check_b;
    done_b:
        ;
    }

    {
        char c;
        char *src = lbl_80559D80;
        long len = 20;
        char *dst = arg0 + 0xEE;

        goto copy_c;
    check_c:
        if (--len > 0)
            goto copy_c;
        dst[-1] = 0;
        goto done_c;
    copy_c:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_c;
        goto check_c;
    done_c:
        ;
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80141DAC(char *arg0) {
    {
        char *src = (char *)fn_80131234(lbl_8032CC64);
        char c;
        long len = 20;
        char *dst = arg0 + 0xEE;

        goto copy_a;
    check_a:
        if (--len > 0)
            goto copy_a;
        dst[-1] = 0;
        goto done_a;
    copy_a:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_a;
        goto check_a;
    done_a:
        ;
    }

    {
        char c;
        char *src = lbl_80559D80;
        long len = 20;
        char *dst = arg0 + 0xC6;

        goto copy_b;
    check_b:
        if (--len > 0)
            goto copy_b;
        dst[-1] = 0;
        goto done_b;
    copy_b:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_b;
        goto check_b;
    done_b:
        ;
    }

    {
        char c;
        char *src = lbl_80559D80;
        long len = 20;
        char *dst = arg0 + 0xDA;

        goto copy_c;
    check_c:
        if (--len > 0)
            goto copy_c;
        dst[-1] = 0;
        goto done_c;
    copy_c:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_c;
        goto check_c;
    done_c:
        ;
    }
}
#pragma pop
extern "C" s32 fn_80141E90(f32 *arg0, f32 arg1) {
    return arg1 - *arg0 >= lbl_805614AC;
}

extern "C" void *fn_80141EB0(s32 *arg0) {
    s32 count = arg0[1];
    void *result;
    if ((count + (arg0[2] - arg0[3])) % count <= 0) {
        result = 0;
    } else {
        result = (void *)(arg0[0] + ((count + ((volatile s32 *)arg0)[3]) % count) * 12);
    }
    if (result != 0) {
        arg0[3] = (((volatile s32 *)arg0)[3] + 1) % ((volatile s32 *)arg0)[1];
    }
    return result;
}

extern "C" s32 fn_80141F28(void *arg0, s32 arg1) {
    s32 head = ((s32 *)arg0)[3];
    s32 capacity = ((s32 *)arg0)[1];
    s32 count = capacity + (((s32 *)arg0)[2] - head);
    if (arg1 >= count % capacity)
        return 0;
    s32 tmp = capacity + head;
    s32 *base = (s32 *)((s32 *)arg0)[0];
    s32 index = (arg1 + tmp) % capacity;
    return (s32)base + index * 12;
}

#pragma small_data off
extern "C" s32 fn_80141F7C(f32 arg0) {
    return (f32)__fabs((f64)arg0) <= lbl_80558DC4[0];
}
#pragma small_data on
extern "C" u8 lbl_8055E1BC;
extern "C" u8 fn_80141FA0(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x19);
}

extern "C" u8 lbl_8055E1BC;
extern "C" f32 lbl_8056149C;
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805614AC;
extern "C" u8 lbl_8055E1BC;
extern "C" f32 fn_8001DAE8(void *);
extern "C" f32 fn_8013CB3C(void);
extern "C" void fn_8001DAE8_2(void *, f32);
#pragma small_data off
extern "C" s32 fn_80141FA8(void *arg0, f32 arg1) {
    s32 result = 1;
    if (lbl_8055E1BC != 0) {
        f32 old = *(f32 *)((u8 *)arg0 + 0x94);
        f32 step = arg1 / lbl_8056149C;
        f32 v = old + step;
        v = v < lbl_805614AC ? lbl_805614AC : v;
        v = v > lbl_805614A4 ? lbl_805614A4 : v;
        f32 r = v;
        *(f32 *)((u8 *)arg0 + 0x94) = v;
        if (old < r) {
            *(f32 *)((u8 *)arg0 + 0xEC) = r - old;
        } else {
                    s32 close = (f32)__fabs((f64)r) <= *(f32 *)&lbl_80558DC4;
        if (close != 0) {
            if ((f32)__fabs((f64)old) <= *(f32 *)&lbl_80558DC4) {
                    s32 n = *(volatile s32 *)((u8 *)arg0 + 0xE4);
                    if (n > 0) {
                        *(s32 *)((u8 *)arg0 + 0xF4) = n;
                        *(f32 *)((u8 *)arg0 + 0xF0) = fn_8013CB3C();
                    }
                    *(volatile s32 *)((u8 *)arg0 + 0xE4) = 0;
                    n = *(volatile s32 *)((u8 *)arg0 + 0x100);
                    if (n > 0) *(f32 *)((u8 *)arg0 + 0xD4) = fn_8001DAE8((u8 *)arg0 + 0xD0);
                    *(volatile s32 *)((u8 *)arg0 + 0x100) = 0;
                    *(f32 *)((u8 *)arg0 + 0xAC) = fn_8001DAE8((u8 *)arg0 + 0xA8);
                    if (lbl_8055E1BC == 0) *(u8 *)((u8 *)arg0 + 0xF8) = 1;
                    result = 0;
                }
            }
        }
    }
    return result;
}
extern "C" s32 fn_801420D4(void *arg0) {
    return !((f32)__fabs((f64)*(f32 *)((u8 *)arg0 + 0x2690)) <= lbl_80558DC4[0]);
}

extern "C" void fn_80142104(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0xE8) = 0;
    *(s32 *)((u8 *)arg0 + 0x104) = 0;
    *(s32 *)((u8 *)arg0 + 0x100) = 0;
}

extern "C" S28_80142118 fn_80142118(S28_80142118 arg0) {
    return arg0;
}

extern "C" s32 fn_80142154(void *arg0) {
    s32 result = 0;
    if (*(s32 *)((u8 *)arg0 + 0x68) < *(s32 *)(*(s32 **)((u8 *)arg0 + 0x64)) - 1) {
        *(s32 *)((u8 *)arg0 + 0x68) += 1;
        *(f32 *)((u8 *)arg0 + 0x70) = fn_8001DAE8((u8 *)arg0 + 0x6C);
        *(s32 *)((u8 *)arg0 + 0x288) = fn_8013D18C(*(s32 *)((u8 *)arg0 + 0x68));
        result = 1;
    }
    return result;
}
#pragma dont_inline off
extern "C" u8 *fn_801421C0(u8 *arg0) {
    s32 index = *(s32 *)(arg0 + 0x68);
    u8 *items = *(u8 **)(arg0 + 0x64);
    return *(u8 **)(items + 4) + index * 0x14;
}

extern "C" f32 fn_8013CB3C(void);
extern "C" u8 lbl_8042FB3C[];
#pragma scheduling invalid_target
extern "C" void fn_801421D8(void *arg0, void *arg1) {
    u8 *a = (u8 *)arg0;
    u8 *b = (u8 *)arg1;
    s32 m, n2;
    s32 n;
    u8 *row;
    *(f32 *)(b + 0xB4) = fn_8001DAE8(b + 0xB0);
    f32 time = fn_8013CB3C() - *(f32 *)(b + 0x84);
    time -= *(f32 *)(lbl_8042FB3C + 0x24);
    f32 one = lbl_805614A4;
    f32 span = *(f32 *)(lbl_8042FB3C + 0x20);
    f32 value = lbl_805614AC;
    f32 position = *(f32 *)(lbl_8042FB3C + 0x1C);
    time -= one;
    f32 ratio = time / (span - one);
    value = value < ratio ? ratio : value;
    value = value > lbl_805614A4 ? lbl_805614A4 : value;
    f32 result = position + value * (lbl_805614A4 - position);
    if (result > lbl_805614A4) {
        f32 current = *(f32 *)(lbl_8042FB3C + 0x1C);
        f32 rounded;
        if (!(current < lbl_805614A4)) {
            rounded = lbl_80561498 + current;
        } else {
            rounded = current - lbl_80561498;
        }
        n = (s32)rounded;
    } else {
        n = 0;
    }
    row = fn_801421C0(a);
    {
        f32 scale = *(f32 *)(lbl_8042FB3C + 0x1C);
        f32 first = (f32)*(s32 *)(row + 0x10);
        f32 second = (f32)*(s32 *)(row + 0xC);
        f32 scaled = scale * first * second;
        f32 adj;
        if (scaled < lbl_805614A4) {
            adj = scaled - lbl_80561498;
        } else {
            adj = lbl_80561498 + scaled;
        }
        m = (s32)adj;
    }
    if (n == m) *(s32 *)b = 3;
    else if (n > 0) *(s32 *)b = 2;
    else *(s32 *)b = 1;
    *(s32 *)(b + 0x5C) = *(s32 *)(fn_801421C0(a) + 0x10);
    *(s32 *)(b + 0x48) = *(s32 *)(fn_801421C0(a) + 0xC);
    *(s32 *)(b + 0x4C) = 1;
    if (*(s32 *)(b + 0x100) == *(s32 *)(lbl_8042FB3C + 4))
        *(s32 *)(b + 0x58) = (*(s32 *)(a + 0x68) + 1) * *(s32 *)(lbl_8042FB3C + 0x2C);
    else *(s32 *)(b + 0x58) = 0;
    *(s32 *)(b + 0x50) = 1;
    *(s32 *)(b + 0x54) = *(s32 *)b;
    time = fn_8013CB3C() - *(f32 *)(b + 0x84);
    time -= *(f32 *)(lbl_8042FB3C + 0x24);
    one = lbl_805614A4;
    span = *(f32 *)(lbl_8042FB3C + 0x20);
    value = lbl_805614AC;
    position = *(f32 *)(lbl_8042FB3C + 0x1C);
    time -= one;
    ratio = time / (span - one);
    value = value < ratio ? ratio : value;
    value = value > lbl_805614A4 ? lbl_805614A4 : value;
    result = position + value * (lbl_805614A4 - position);
    if (result > lbl_805614A4) {
        f32 current = *(f32 *)(lbl_8042FB3C + 0x1C);
        f32 rounded;
        if (!(current < lbl_805614A4)) {
            rounded = lbl_80561498 + current;
        } else {
            rounded = current - lbl_80561498;
        }
        n2 = (s32)rounded;
    } else {
        n2 = 0;
    }
    *(s32 *)(b + 0x60) = n2;
    *(s32 *)(b + 0x80) = *(s32 *)(b + 0x48) * *(s32 *)(b + 0x4C) * (*(s32 *)(b + 0x5C) * *(s32 *)(b + 0x50)) + (n2 + *(s32 *)(b + 0x58));
    *(f32 *)(b + 0x84) = fn_8013CB3C();
    *(f32 *)(b + 0xDC) = fn_8001DAE8(b + 0xD8);
    *(f32 *)(b + 0xCC) = fn_8001DAE8(b + 0xC8);
    *(s32 *)(b + 0x10C) += *(s32 *)(b + 0x80);
    *(f32 *)(b + 0x9C) = fn_8001DAE8(b + 0x98);
    row = fn_801421C0(a);
    if (lbl_8055E1BC) {
        f32 x = *(f32 *)(b + 0x94);
        f32 f = x + *(f32 *)(row + 8) / lbl_8056149C;
        f = f < lbl_805614AC ? lbl_805614AC : f;
        f = f > lbl_805614A4 ? lbl_805614A4 : f;
        f64 r = f;
        *(f32 *)(b + 0x94) = f;
        if (x < (f32)r) {
            *(f32 *)(b + 0xEC) = (f32)r - x;
        } else {
            s32 close = (f32)__fabs(r) <= *(f32 *)&lbl_80558DC4;
            if (close != 0) {
                if (!((f32)__fabs((f64)x) <= *(f32 *)&lbl_80558DC4)) {
                    if (*(s32 *)(b + 0xE4) > 0) {
                        *(s32 *)(b + 0xF4) = *(s32 *)(b + 0xE4);
                        *(f32 *)(b + 0xF0) = fn_8013CB3C();
                        *(s32 *)(b + 0xE4) = 0;
                    }
                    if (*(s32 *)(b + 0x100) > 0) {
                        f32 d4 = fn_8001DAE8(b + 0xD0);
                        *(f32 *)(b + 0xD4) = d4;
                        *(s32 *)(b + 0x100) = 0;
                    }
                    *(f32 *)(b + 0xAC) = fn_8001DAE8(b + 0xA8);
                    if (!lbl_8055E1BC) b[0xF8] = 1;
                }
            }
        }
    }
    ++*(s32 *)(b + *(s32 *)(b + 0x54) * 4 + 0xC);
}
#pragma scheduling on
  extern "C" f32 __fabsf(f32);
#pragma dont_inline on
extern "C" void fn_80142650(void *arg0) {
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r0;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f2;
    f32 rounded_f2;

    u8 *base = (u8 *)arg0;

    temp_r5 = *(s32 *)(base + 0xE4) + 1;
    temp_r6 = *(s32 *)(base + 0xE0);
    *(s32 *)(base + 0xE4) = temp_r5;
    *(s32 *)(base + 0xE8) = *(s32 *)(base + 0xE8) + 1;

    if (temp_r6 > temp_r5) {
        temp_r5 = temp_r6;
    }
    *(s32 *)(base + 0xE0) = temp_r5;

    if (*(u8 *)(base + 0xF8) != 0) {
        *(u8 *)(base + 0xF8) = 0;

        if (lbl_8055E1BC != 0) {
            temp_f1 = *(f32 *)(base + 0x94);
            var_f2 = lbl_805614AC;
            temp_f0 = temp_f1 + (lbl_8056149C / lbl_8056149C);
            if (var_f2 < temp_f0) {
                var_f2 = temp_f0;
            }
            if (var_f2 > lbl_805614A4) {
                var_f2 = lbl_805614A4;
            }
            rounded_f2 = var_f2;
            *(f32 *)(base + 0x94) = var_f2;

            if (temp_f1 < rounded_f2) {
                *(f32 *)(base + 0xEC) = rounded_f2 - temp_f1;
            } else {
                f32 diff = rounded_f2 - temp_f1;
                if (diff < 0.0f) diff = -diff;
                if (diff > *(f32 *)&lbl_80558DC4) {
                    if (*(s32 *)(base + 0xE4) > 0) {
                        *(s32 *)(base + 0xF4) = *(s32 *)(base + 0xE4);
                        fn_8013CB3C();
                        *(s32 *)(base + 0xF0) = 0;
                        *(s32 *)(base + 0xE4) = 0;
                    }
                    if (*(s32 *)(base + 0x100) > 0) {
                        temp_r6 = *(s32 *)(base + 0x100);
                        *(f32 *)(base + 0xD4) = fn_8001DAE8(base + 0xD0);
                        *(s32 *)(base + 0x100) = 0;
                        *(f32 *)(base + 0xAC) = fn_8001DAE8(base + 0xA8);
                    }
                    if (lbl_8055E1BC == 0) {
                        *(u8 *)(base + 0xF8) = 1;
                    }
                }
            }
        }
    }

    if ((*(s32 *)(base + 0xE4) % ((s32)&lbl_8042FB3C[0xC])) == 0) {
        *(f32 *)(base + 0xBC) = fn_8001DAE8(base + 0xB8);
    }
}
  extern "C" f32 lbl_8042FB3C_arr[8];
#pragma scheduling invalid_target
extern "C" s32 fn_801427DC(void *arg0, s32 arg1) {
    u8 *table = *(u8 **)((u8 *)arg0 + 0x64);
    u8 *items = *(u8 **)(table + 4);
    u8 *item = items + arg1 * 0x14;
    f32 first = (f32)*(s32 *)(item + 0x10);
    f32 scale = *(f32 *)(lbl_8042FB3C + 0x1C);
    f32 second = (f32)*(s32 *)(item + 0xC);
    f32 value = first * scale * second;
    if (value < lbl_805614A4) {
        value -= lbl_80561498;
    } else {
        value += lbl_80561498;
    }
    return (s32)value;
}
#pragma scheduling on
extern "C" s32 fn_80142870(void *arg0, void *arg1) {
    f32 time = fn_8013CB3C() - *(f32 *)((u8 *)arg1 + 0x84);
    time -= *(f32 *)(lbl_8042FB3C + 0x24);
    f32 one = lbl_805614A4;
    f32 span = *(f32 *)(lbl_8042FB3C + 0x20);
    f32 value = lbl_805614AC;
    f32 position = *(f32 *)(lbl_8042FB3C + 0x1C);
    time -= one;
    f32 ratio = time / (span - one);

    value = value < ratio ? ratio : value;
    value = value > lbl_805614A4 ? lbl_805614A4 : value;

    f32 result = position + value * (lbl_805614A4 - position);
    if (result > lbl_805614A4) {
        f32 current = *(f32 *)(lbl_8042FB3C + 0x1C);
        f32 rounded;
        if (!(current < lbl_805614A4)) {
            rounded = lbl_80561498 + current;
        } else {
            rounded = current - lbl_80561498;
        }
        return (s32)rounded;
    }
    return 0;
}

extern "C" void fn_80142948(void *arg0) {
    *(f32 *)((u8 *)arg0 + 4) = fn_8001DAE8(arg0);
}

extern "C" s32 fn_80142978(void *arg0) {
    f32 diff = fn_8001DAE8(arg0) - *(f32 *)((u8 *)arg0 + 4);
    return diff >= lbl_805614A4 && diff < *(f32 *)arg0;
}

extern "C" f32 fn_801429D0(f32 arg0, f32 arg1) {
    if (!(arg0 > arg1)) return arg1;
    return arg0;
}

extern "C" f32 fn_801429E0(f32 arg0, f32 arg1) {
    if (!(arg0 < arg1)) return arg1;
    return arg0;
}

extern "C" f32 fabs(f32);
#pragma dont_inline fn_8013CB3C
extern "C" void fn_801429F0(void *arg0) {
    u8 *p = (u8 *)arg0;
    *(f32 *)(p + 0xA4) = fn_8001DAE8(p + 0xA0);
    s32 temp_r0 = *(s32 *)(p + 0xE4);
    if (temp_r0 > 0) {
        *(s32 *)(p + 0xF4) = temp_r0;
        *(f32 *)(p + 0xF0) = fn_8013CB3C();
        *(s32 *)(p + 0xE4) = 0;
    }
    if (*(s32 *)(p + 0x100) > 0)
        *(f32 *)(p + 0xD4) = fn_8001DAE8(p + 0xD0);
    *(s32 *)(p + 0x100) = 0;
    if (lbl_8055E1BC != 0) goto done;
    if (lbl_8055E1BC == 0) goto done;

    f32 old = *(f32 *)(p + 0x94);
    f32 var_f2 = lbl_805614AC;
    var_f2 = var_f2 < (old + lbl_8056149C / lbl_8056149C) ? (old + lbl_8056149C / lbl_8056149C) : var_f2;
    var_f2 = var_f2 > lbl_805614A4 ? lbl_805614A4 : var_f2;
    *(f32 *)(p + 0x94) = var_f2;
    f32 rounded = (f32)(f64)var_f2;
    if (old < rounded) {
        *(f32 *)(p + 0xEC) = rounded - old;
        goto done;
    }
    var_f2 = (f32)__fabs((f64)rounded);
    s32 close = var_f2 <= lbl_80558DC4[0];
    if (close == 0) goto done;
    old = (f32)__fabs((f64)old);
    if (old <= lbl_80558DC4[0]) goto done;

    temp_r0 = *(s32 *)(p + 0xE4);
    if (temp_r0 > 0) {
        *(s32 *)(p + 0xF4) = temp_r0;
        *(f32 *)(p + 0xF0) = fn_8013CB3C();
        *(s32 *)(p + 0xE4) = 0;
    }
    temp_r0 = *(s32 *)(p + 0x100);
    if (temp_r0 > 0)
        *(f32 *)(p + 0xD4) = fn_8001DAE8(p + 0xD0);
    *(s32 *)(p + 0x100) = 0;
    *(f32 *)(p + 0xAC) = fn_8001DAE8(p + 0xA8);
    if (lbl_8055E1BC == 0) *(u8 *)(p + 0xF8) = 1;
done:
    ;
}
extern "C" void fn_80142B60(void *arg0) {
    u8 *p = (u8 *)arg0;
    p[0x49] = 1;
    p[0x4B] = 0;
    p[0x4A] = 0;
}

extern "C" void fn_80142B78(void *arg0, f32 arg1) {
    if (arg1 != *(f32 *)((u8 *)arg0 + 4)) {
        *(f32 *)((u8 *)arg0 + 4) = arg1;
        *(u8 *)((u8 *)arg0 + 0x4E) = 1;
    }
}

extern "C" s32 fn_80142B94(s32 arg0, s32 arg1, s32 arg2) {
    s32 v = arg1;
    if (arg0 > v) v = arg0;
    if (v < arg2) arg2 = v;
    return arg2;
}

extern "C" s32 fn_80142BB4(void *arg0) {
    s32 count = *(s32 *)((u8 *)arg0 + 4);
    return (count + (*(s32 *)((u8 *)arg0 + 8) - *(s32 *)((u8 *)arg0 + 0xC))) % count;
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void *fn_80142BD8(void *arg0) {
    s32 *ring = (s32 *)arg0;
    s32 count;
    u8 *base;
    s32 write;
    s32 read;
    register s32 next;
    void *result;
    write = ring[2];
    count = ring[1];
    read = ring[3];
    base = (u8 *)ring[0];
    next = (write + 1) % count;
    result = base + write * 12;
    ring[2] = next;
    if (next == read)
        ring[3] = (read + 1) % count;
    return result;
}
#pragma pop
extern "C" void *fn_80142C28(void *arg0, void *arg1) {
 u8 *p=(u8 *)*(void **)((u8 *)arg0+0x64);
 s32 index=*(s32 *)((u8 *)arg0+0x68);
 u8 *entry=*(u8 **)(p+4)+index*0x14;
 u8 *items=*(u8 **)(entry+4);
 u8 *end=items+*(s32 *)entry*0x24;
 if(arg1==end-0x24) return items;
 return (u8 *)arg1+0x24;
}

#pragma dont_inline off
extern "C" void fn_80142C5C(void *arg0, u8 *arg1) {
    void *obj = fn_802C6C34(*(s32 *)(arg1 + 0x59C));
    *(f32 *)((u8 *)arg0 + 0x128) = *(f32 *)((u8 *)obj + 0x30) - *(f32 *)((u8 *)obj + 0x2C);
}

extern "C" u8 *fn_8017960C(s32);
extern "C" u32 fn_8013D148(u8 *, f32);
extern "C" void *fn_802C6C34(s32);
extern "C" u8 *fn_80142C9C(u8 *arg0, s32 arg1) {
    struct Object {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual u8 *get();
    };
    register u8 *self = arg0;
    u8 *manager = (u8 *)fn_8017960C(arg1);
    u8 *base = *(u8 **)(manager + 0x270);
    u8 *object = ((Object *)base)->get();
    s32 index = *(s32 *)(self + 0x68);
    f32 value = *(f32 *)(object + 0x48);
    u8 *items = *(u8 **)(self + 0x64);
    u8 *item = *(u8 **)(items + 4) + index * 0x14;
    u8 *result = (u8 *)fn_8013D148(item, value);

    index = *(s32 *)(self + 0x68);
    items = *(u8 **)(self + 0x64);
    base = *(u8 **)(items + 4);
    s32 offset = *(s32 *)(base += index * 0x14);
    u8 *array = *(u8 **)(base + 4);
    u8 *end = array + offset * 0x24;
    u8 *out = array;
    if (result != end - 0x24) {
        out = result + 0x24;
    }
    return out;
}

extern "C" s32 fn_80142D34(void) { return 0; }

extern "C" u8 *fn_80142D3C(void *arg0, s32 arg1) { return *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C; }

#pragma use_lmw_stmw off
extern "C" void fn_80142D4C(void *arg0) {
    u8 *self = (u8 *)arg0;
    {
        register f32 spread = lbl_80561498;
        s32 groupOffset, groupIndex;

    lbl_8055E1BC = 0;
    *(u8 *)(self + 0x294) = 0;
    *(s32 *)(self + 0x28C) = 0;
    groupIndex = 0;
    groupOffset = 0;
    for (; groupIndex < *(s32 *)(*(u8 **)(self + 0x64)); groupOffset += 0x14, groupIndex++) {
        s32 itemIndex, itemOffset;
        u8 *group;
        u8 *groupBase = *(u8 **)(*(u8 **)(self + 0x64) + 4);
        group = groupBase + groupOffset;
        itemIndex = 0;
        itemOffset = 0;
        for (; itemIndex < *(s32 *)group; itemOffset += 0x24, itemIndex++) {
            u8 *item = *(u8 **)(group + 4) + itemOffset;
            {
                s32 vertex;
                u8 *point;
                vertex = 0;
                point = item;
                do {
                    fn_801E9E30(point + 0x1C, (f32 *)point);
                    *(f32 *)(point + 4) += spread;
                    point += 0xC;
                    vertex++;
                } while (vertex < 2);
            }
            {
                f32 x0, x1, y0, y1, z0, z1;
                z1 = *(f32 *)(item + 0x14);
                z0 = *(f32 *)(item + 8);
                y1 = *(f32 *)(item + 0x10);
                y0 = *(f32 *)(item + 4);
                x1 = *(f32 *)(item + 0xC);
                x0 = *(f32 *)(item + 0);
                f32 z = z0 + spread * (z1 - z0);
                f32 y = y0 + spread * (y1 - y0);
                f32 x = x0 + spread * (x1 - x0);
                f32 coords[4];
                volatile f32 padding;
                struct Out { void *ptr; f32 weight; } out;
                f32 pair[2];
                coords[3] = z;
                coords[2] = y;
                coords[1] = x;
                s32 handle = fn_80178C9C();
                pair[0] = coords[1];
                pair[1] = coords[3];
                fn_80136594((void **)&out, handle, pair, coords[3]);
                *(f32 *)(item + 0x18) =
                    *(f32 *)((u8 *)out.ptr + 0x1C) +
                    *(f32 *)((u8 *)out.ptr + 0x18) * out.weight;
            }
        }
        qsort(*(u8 **)(group + 4), *(u32 *)group, 0x24,
              (int (*)(const void *, const void *))fn_8013D27C);
    }

    }

    *(s32 *)(self + 0x68) = 0;
    *(f32 *)(self + 0x70) = lbl_80561594;
    *(f32 *)(self + 0x78) = lbl_80561594;
    *(f32 *)(self + 0x80) = lbl_80561594;
    *(f32 *)(self + 0x88) = lbl_80561594;
    *(f32 *)(self + 0x90) = lbl_80561594;
    *(s32 *)(self + 0x288) = fn_8013D18C(0);
    {
        register f32 negative = lbl_805614AC;
        register f32 defaultValue = lbl_80561598;
        register f32 one = lbl_805614A4;
        register f32 zero = lbl_80561594;
        s32 index = 0;
        s32 offset = 0;
        for (; index < *(s32 *)(self + 0xBC); offset += 0x12C, index++) {
            u8 *p = *(u8 **)(self + 0xB8) + offset;
            memset(p + 0xC, 0, 0x10);
            *(f32 *)(p + 0xC4) = zero;
            *(s32 *)(p + 0x0) = 1;
            *(s32 *)(p + 0x4) = 1;
            *(f32 *)(p + 0x8) = one;
            *(s32 *)(p + 0x1C) = 0;
            *(u8 *)(p + 0xF8) = 0;
            *(s32 *)(p + 0x80) = 0;
            *(f32 *)(p + 0x84) = defaultValue;
            *(s32 *)(p + 0x20) = 4;
            *(s32 *)(p + 0x24) = 4;
            *(s32 *)(p + 0x28) = 4;
            *(s32 *)(p + 0x2C) = 4;
            *(s32 *)(p + 0x30) = 4;
            *(s32 *)(p + 0x34) = 4;
            *(s32 *)(p + 0x38) = 4;
            *(s32 *)(p + 0x3C) = 4;
            *(s32 *)(p + 0x40) = 4;
            *(s32 *)(p + 0x44) = 4;
            *(f32 *)(p + 0xA4) = zero;
            *(f32 *)(p + 0xAC) = zero;
            *(f32 *)(p + 0xB4) = zero;
            *(f32 *)(p + 0xBC) = zero;
            *(f32 *)(p + 0x9C) = zero;
            *(f32 *)(p + 0xCC) = zero;
            *(f32 *)(p + 0xDC) = zero;
            *(f32 *)(p + 0xEC) = one;
            *(s32 *)(p + 0x88) = -1;
            *(s32 *)(p + 0x8C) = -1;
            *(f32 *)(p + 0x94) = negative;
            *(s32 *)(p + 0xE4) = 0;
            *(s32 *)(p + 0xE0) = 0;
            *(s32 *)(p + 0xE8) = 0;
            *(s32 *)(p + 0x104) = 0;
            *(f32 *)(p + 0xF0) = defaultValue;
            *(s32 *)(p + 0x100) = 0;
            *(s32 *)(p + 0xFC) = 0;
            *(f32 *)(p + 0x108) = *(f32 *)(lbl_8042FB3C + 0x18);
            *(u8 *)(p + 0x92) = 0;
            *(u8 *)(p + 0x91) = 0;
            *(u8 *)(p + 0x90) = 0;
            *(s32 *)(p + 0x11C) = 0;
            *(s32 *)(p + 0x10C) = 0;
            *(s32 *)(p + 0x110) = 0;
            *(s32 *)(p + 0x114) = 0;
            *(s32 *)(p + 0x124) = 3;
            *(f32 *)(p + 0x120) = defaultValue;
        }
    }

    {
        s32 handle = *(s32 *)(self + 0x140);
        s32 zero = 0;
        f32 reset = lbl_805614BC;
        *(s32 *)(self + 0xC8) = zero;
        *(s32 *)(self + 0xCC) = zero;
        *(s32 *)(self + 0x134) = zero;
        *(f32 *)(self + 0x138) = reset;
        *(u8 *)(self + 0x13C) = 1;
        *(u8 *)(self + 0x13D) = 0;
        *(u8 *)(self + 0x144) = 0;
        *(s32 *)(self + 0x240) = zero;
        *(s32 *)(self + 0x244) = zero;
        *(s32 *)(self + 0x248) = zero;
        *(s32 *)(self + 0x24C) = zero;
        if (handle != 0) fn_802AE0E0(handle);
    }
    {
        u8 *resource = *(u8 **)(self + 0x148);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x14C);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x150);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x158);
        *(u8 *)(self + 0x154) = 0;
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x15C);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x160);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x254);
        *(f32 *)(self + 0x250) = lbl_8056159C;
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    *(u8 *)(self + 0x258) = 0;
}
#pragma use_lmw_stmw reset
extern "C" u8 *fn_801B2EC0(s32);

extern "C" void fn_80143128(u8 *arg0) {
    ((TObj4C *)arg0)->v4C();
}

#pragma use_lmw_stmw off

#pragma scheduling invalid_target
extern "C" void fn_80143138(u8 *self, u8 *out) {
    class TObj10Local {
    public:
        virtual void d0();
        virtual void d1();
        virtual u8 *v10();
    };
    *(s32 *)out = *(s32 *)(self + 0xBC);
    *(s32 *)(out + 4) = *(s32 *)(self + 0x130);
    *(u8 *)(out + 0xD) = ((TObj24 *)self)->v24();
    s32 z = 0;
    u8 *p = out + 0x10;
    *(u8 *)(out + 0xC) = z;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < *(s32 *)(self + 0xBC)) {
        *(u8 *)(p + 0x10) = z;
        u8 *q = ((TObj10Local *)fn_801B2EC0(i))->v10();
        i++;
        *(s32 *)(p + 4) = *(s32 *)(q + 4);
        *(s32 *)(p + 8) = *(s32 *)(*(u8 **)(self + 0xB8) + off + 0x10C);
        off += 0x12C;
        p += 0x14;
    }
}
#pragma scheduling on
extern "C" void fn_801431F4(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 1;
}

extern "C" void fn_80143200(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 0;
}

extern "C" s32 fn_8014320C(void) {
    return 0x1008;
}

extern "C" void fn_8013D288(void);

extern "C" void fn_80143214(void) {
    fn_8013D288();
}

extern "C" void fn_801352B8(void *);
extern "C" void fn_80135D60(void *, s32);
extern "C" s32 fn_80156A40(void);
extern "C" void fn_801B8048(void *, void *, void *, f32, f32);
extern "C" void fn_8013530C(void *, s32, f32, f32, f32);
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805615A0;
extern "C" f32 lbl_805615A4;
extern "C" f32 lbl_805615A8;
#pragma scheduling invalid_target
extern "C" s32 fn_80143218(s32 arg0, u8 *arg1) {
    u8 obj[0x38];
    volatile f32 *input = (volatile f32 *)(arg1 + 0x18);
    f32 *output = (f32 *)(arg1 + 0x30);
    f32 fx, fy, fz;

    fn_801352B8(obj);
    fn_80135D60(obj, ((TObjC *)fn_80156A40())->vC(0));
    u8 *v = *(u8 **)(obj + 0x2C);
    fn_801B8048(arg1, obj, v, lbl_805614A4,
                (*(f32 *)(v + 8) - lbl_805615A0) - lbl_805615A4);

    fx = input[0];
    register f32 scale = *(volatile f32 *)&lbl_805615A8;
    fy = input[1];
    fz = input[2];
    fx *= scale;
    fy *= scale;
    fz *= scale;
    output[0] = fx;
    output[1] = fy;
    *(s32 *)(arg1 + 0x44) = 1;
    output[2] = fz;
    fn_8013530C(obj, -1, fy, fx, scale);
    return 1;
}
#pragma scheduling on
extern "C" void fn_801B8A68(void *, s32);
extern "C" void fn_801432D4(TObj20b *arg0, s32 arg1) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    s32 zero = 0;
    if (obj[0x118] != 0 && arg0->v20() != 0) {
        *(s32 *)(obj + 0x104) = zero;
        if (*(s32 *)(obj + 0xE4) > 0) {
            *(s32 *)(obj + 0xF4) = *(s32 *)(obj + 0xE4);
            *(f32 *)(obj + 0xF0) = fn_8013CB3C();
            *(s32 *)(obj + 0xE4) = zero;
        }
        if (*(s32 *)(obj + 0x100) > 0) {
            *(f32 *)(obj + 0xD4) = fn_8001DAE8(obj + 0xD0);
        }
        *(s32 *)(obj + 0x100) = zero;
    }
    fn_801B8A68(arg0, arg1);
}

class VTable43398 { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); }; extern "C" void fn_80143398(void *arg0) { ((VTable43398 *)arg0)->f41(); }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" s32 fn_801436E0(void *arg0, s32 arg1) {
    void *style;
    u8 *self=(u8 *)arg0;
    char *base=(char *)lbl_8032C530;
    f32 a,time,c,d,e,opacityScratch,end,b;
    f32 opacitySecond;
    time=*(f32 *)((u8 *)fn_801E7E3C()+0x10);
    end=lbl_80561588;
    a=end-lbl_805614C0;
    b=a-lbl_80561550;
    c=b-lbl_805615AC;
    d=c-lbl_805614C0;
    e=d-lbl_80561550;
    void *one=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x7a8));
    void *two=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x7b8));
    if(time<e)fn_8000FBE4();
    if(fn_80161C38()==0) {
        if(time<end) {
            f32 value=(time-a)/(b-a);
            value=lbl_805614AC<value ? lbl_805614AC : value;
            value=value>lbl_805614A4 ? value : lbl_805614A4;
            value=lbl_805614A4+value*lbl_805614AC;
            style=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x7c8));
            void *target=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x7d4));
            fn_8001DF08(fn_801E866C(arg1),0);
            if(one && two && style && target) {
                if(value<lbl_805614BC) {
    opacityScratch=lbl_805614BC;
} else if(value>lbl_805614AC) {
    opacityScratch=lbl_805614AC;
} else {
    {
        if(value>lbl_805614A4)
            opacityScratch=(value*(lbl_8056150C*value*value))+(lbl_805614D0*value*value);
        else
            opacityScratch=(value*(lbl_8056150C*value*value))-(lbl_805614D0*value*value);
    }
}
                fn_801479A8(one,two,(const char *)fn_80131234(base+0x7e0),opacityScratch);
                fn_80160A74();
                char buf[0x14];
                fn_801308F4(buf,0x14,fn_80160998());
                Fn801436E0TextStyle local;
                Fn801436E0TextStyle *src=(Fn801436E0TextStyle *)style;
                local.a=src->a;
                u32 bword=src->b, cword=src->c;
                local.b=bword;local.c=cword;
                local.d=src->d;local.size=src->size;
                local.f=src->f;local.g=src->g;local.h=src->h;
                *(f32 *)&local.b-=lbl_80561498*fn_80147204(&local,buf);
                f32 opacityScratch2;
                if(value<lbl_805614BC) {
    opacityScratch2=lbl_805614BC;
} else if(value>lbl_805614AC) {
    opacityScratch2=lbl_805614AC;
} else {
    {
        if(value>lbl_805614A4)
            opacityScratch2=(value*(lbl_8056150C*value*value))+(lbl_805614D0*value*value);
        else
            opacityScratch2=(value*(lbl_8056150C*value*value))-(lbl_805614D0*value*value);
    }
}
                fn_801479A8(&local,target,buf,opacityScratch2);
            }
        }
        if(time<c) {
            fn_8014784C(*(void **)(self+0x54),base+0x47c,base+0x48c,0);
            f32 value=(time-d)/(e-d);
            value=lbl_805614AC<value ? lbl_805614AC : value;
            value=value>lbl_805614A4 ? value : lbl_805614A4;
            value=lbl_805614A4+value*lbl_805614AC;
            style=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x7fc));
            void *target=(void *)((TObjC *)*(void **)(self+0x54))->vC((s32)(base+0x470));
            if(one && two && style && target) {
                if(value<lbl_805614BC) {
    opacitySecond=lbl_805614BC;
} else if(value>lbl_805614AC) {
    opacitySecond=lbl_805614AC;
} else {
    {
        if(value>lbl_805614A4)
            opacitySecond=(value*(lbl_8056150C*value*value))+(lbl_805614D0*value*value);
        else
            opacitySecond=(value*(lbl_8056150C*value*value))-(lbl_805614D0*value*value);
    }
}
                fn_801479A8(one,two,(const char *)fn_80131234(base+0x808),opacitySecond);
                int player=fn_801E866C(0);
                f32 number=*(f32 *)(*(u8 **)(self+0xb8)+player*0x12c+0x108);
                char buf[0x14];
                fn_80130978(buf,0x14,number);
                Fn801436E0TextStyle local;
                Fn801436E0TextStyle *src=(Fn801436E0TextStyle *)style;
                local.a=src->a;
                u32 bword=src->b, cword=src->c;
                local.b=bword;local.c=cword;
                local.d=src->d;local.size=src->size;
                local.f=src->f;local.g=src->g;local.h=src->h;
                *(f32 *)&local.b+=lbl_80561498*fn_80147204(&local,buf);
                f32 opacitySecond2;
                if(value<lbl_805614BC) {
    opacitySecond2=lbl_805614BC;
} else if(value>lbl_805614AC) {
    opacitySecond2=lbl_805614AC;
} else {
    {
        if(value>lbl_805614A4)
            opacitySecond2=(value*(lbl_8056150C*value*value))+(lbl_805614D0*value*value);
        else
            opacitySecond2=(value*(lbl_8056150C*value*value))-(lbl_805614D0*value*value);
    }
}
                fn_801479A8(&local,target,buf,opacitySecond2);
            }
        }
    }
    return 1;
}
#pragma pop

extern f32 lbl_805615B0;
extern "C" f32 fn_80143C44(void) {
    return lbl_805615B0;
}

extern "C" u32 fn_80143C4C(void) { return 1; }

extern "C" s32 fn_802ADDD8(s32);
extern "C" void fn_80143DC8(void *);
extern "C" void fn_80143CB0(void *);
extern "C" char lbl_8032CD54[];
extern "C" void fn_80143C54(void *arg0) {
    void *check = fn_801284F8(8, lbl_8032CD54);
    if (check != 0) {
        check = (void *)((s32 (*)(void *, s32))fn_802ADDD8)(check, 1);
    }
    *(void **)((u8 *)arg0 + 0x140) = check;
    volatile u8 *p = (volatile u8 *)arg0;
    fn_80143DC8((void *)(p + 0x134));
    fn_80143CB0((void *)(p + 0x134));
}

extern "C" void fn_802AE0E0(int);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80143CB0(void *arg0) {
    struct Item {
        u8 pad0[0x4A];
        u8 active;
        u8 pad4B;
        u8 state;
    };
    struct Manager {
        int value0;
        float value4;
        u8 flag8;
        u8 flag9;
        u8 padA[2];
        int ref;
        u8 flag10;
        u8 pad11[3];
        Item *item14;
        Item *item18;
        Item *item1C;
        u8 flag20;
        u8 pad21[3];
        Item *item24;
        Item *item28;
        Item *item2C;
        u8 pad30[0xDC];
        int value10C;
        int value110;
        int value114;
        int value118;
    };
    Manager *p = (Manager *)arg0;
    int ref = p->ref;
    Item *item14;
    Item *item18;
    Item *item1C;
    Item *item24;
    Item *item28;
    Item *item2C;
    p->value0 = 0;
    p->value4 = lbl_805614BC;
    p->flag8 = 1;
    p->flag9 = 0;
    p->flag10 = 0;
    p->value10C = 0;
    p->value110 = 0;
    p->value114 = 0;
    p->value118 = 0;
    if (ref != 0) fn_802AE0E0(ref);
    item14 = p->item14;
    if (item14 != 0) { item14->active = 1; item14->state = 0; }
    item18 = p->item18;
    if (item18 != 0) { item18->active = 1; item18->state = 0; }
    item1C = p->item1C;
    if (item1C != 0) { item1C->active = 1; item1C->state = 0; }
    item24 = p->item24;
    p->flag20 = 0;
    if (item24 != 0) { item24->active = 1; item24->state = 0; }
    item28 = p->item28;
    if (item28 != 0) { item28->active = 1; item28->state = 0; }
    item2C = p->item2C;
    if (item2C != 0) { item2C->active = 1; item2C->state = 0; }
}
#pragma pop
extern "C" void fn_80130980(void *, s32, s32, f32);
extern "C" s32 fn_80204CF0(void);
extern "C" s32 fn_80207848(void *, s32);
extern "C" s32 fn_802ADF34(void *, char *, s32 *);
extern "C" s32 lbl_802FAA40[3];
extern "C" u8 lbl_80559D8C, lbl_80559D94, lbl_80559D98, lbl_80559D9C;
extern "C" f32 lbl_805615B4;
#pragma push
#pragma optimize_for_size on
#pragma scheduling invalid_target
extern "C" void fn_80143DC8(void *arg0) {
    union Word { s32 i; void *p; } stack[95];
    register u8 *obj;
    register char *base;
    volatile s32 *var_r4;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r12_2;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r8;
    s32 temp_r9;
    register u32 var_ctr;
    s32 var_r20;
    s32 var_r6;
    s32 var_r6_2;
    u8 *var_r24;
    u8 *var_r4_2;
    u8 *var_r5;
    u8 *var_r5_2;
    u8 *var_r7;
    u8 *var_r7_2;
    u8 temp_r4_2;
    u8 temp_r4_3;
    u8 temp_r5_2;
    s32 one;
    s32 three;
    s32 sp188;
    s32 sp18c;
    s32 sp190;
    void *temp_r12;
    void *temp_r21;
    void *temp_r22;
    void *temp_r23;
    void *temp_r24;
    void *temp_r25;
    void *temp_r25_2;
    void *temp_r26;
    void *temp_r26_2;
    void *temp_r27;
    void *temp_r29;

    obj = (u8 *)arg0;
    base = (char *)lbl_8032C530;
    var_r4 = (volatile s32 *)&stack[47].i;
    for (var_ctr = 0; var_ctr < 0x19; var_ctr++) {
        var_r4[1] = 0;
        var_r4 += 2;
        var_r4[0] = 0;
    }
    var_r4[1] = 0;

    one = 1;
    temp_r0 = (s32)(obj + 0x10C);
    stack[47].i = temp_r0;
    temp_r12 = base + 0x290;
    temp_r26 = base + 0x840;
    stack[50].i = temp_r0;
    temp_r27 = base + 0x834;
    temp_r10 = (s32)(obj + 0x110);
    three = 3;
    stack[45].i = three;
    temp_r9 = (s32)(obj + 0x114);
    temp_r7 = (s32)(obj + 0x118);
    stack[48].i = three;
    temp_r29 = base + 0x84C;
    temp_r6 = (s32)(obj + 0x30);
    stack[46].p = temp_r27;
    temp_r5 = (s32)(obj + 0x44);
    temp_r25 = base + 0x858;
    stack[49].p = temp_r27;
    temp_r4 = (s32)(obj + 0x58);
    temp_r24 = base + 0x870;
    stack[42].i = three;
    temp_r0_2 = (s32)(obj + 0x6C);
    stack[43].p = temp_r12;
    stack[44].i = temp_r10;
    stack[51].i = three;
    stack[52].p = temp_r12;
    stack[53].i = temp_r10;
    stack[39].i = three;
    stack[40].p = &lbl_80559D8C;
    stack[41].i = temp_r9;
    stack[54].i = three;
    stack[55].p = &lbl_80559D8C;
    stack[56].i = temp_r9;
    stack[36].i = three;
    stack[37].p = temp_r26;
    stack[38].i = temp_r7;
    stack[57].i = three;
    stack[58].p = temp_r26;
    stack[59].i = temp_r7;
    stack[33].i = one;
    stack[34].p = temp_r29;
    stack[35].i = temp_r6;
    stack[60].i = one;
    stack[61].p = temp_r29;
    stack[62].i = temp_r6;
    stack[30].i = one;
    stack[31].p = temp_r12;
    stack[32].i = temp_r5;
    stack[63].i = one;
    stack[64].p = temp_r12;
    stack[65].i = temp_r5;
    stack[27].i = one;
    stack[28].p = temp_r25;
    stack[29].i = temp_r4;
    stack[66].i = one;
    stack[67].p = temp_r25;
    stack[68].i = temp_r4;
    stack[24].i = one;
    stack[25].p = temp_r24;
    stack[26].i = temp_r0_2;
    stack[69].i = one;
    stack[70].p = temp_r24;
    stack[71].i = temp_r0_2;
    stack[21].i = one;

    sp188 = lbl_802FAA40[0];
    temp_r8 = (s32)(obj + 0x80);
    sp18c = lbl_802FAA40[1];
    temp_r4 = (s32)(obj + 0x9E);
    sp190 = lbl_802FAA40[2];
    temp_r29 = obj + 0x94;
    stack[72].i = one;
    temp_r26_2 = base + 0x840;
    temp_r12_2 = (s32)(obj + 0xB2);
    stack[23].i = temp_r8;
    temp_r25_2 = base + 0x87C;
    temp_r11_2 = (s32)(obj + 0xC6);
    stack[73].p = temp_r26_2;
    temp_r23 = base + 0x898;
    temp_r10_2 = (s32)(obj + 0xDA);
    stack[74].i = temp_r8;
    temp_r22 = base + 0x8B0;
    stack[18].i = one;
    temp_r9 = (s32)(obj + 0xEE);
    temp_r21 = base + 0x8DC;
    stack[20].i = (s32)temp_r29;
    temp_r7_2 = (s32)(obj + 0x104);
    stack[75].i = one;
    var_r24 = &lbl_80559D8C;
    temp_r8 = 2;
    stack[19].p = var_r24;
    var_r20 = 0x14;
    stack[76].p = var_r24;
    var_r24 = &lbl_80559D94;
    stack[77].i = (s32)temp_r29;
    stack[15].i = one;
    stack[16].p = temp_r25_2;
    stack[17].i = temp_r4;
    stack[78].i = one;
    stack[79].p = temp_r25_2;
    stack[80].i = temp_r4;
    stack[12].i = one;
    stack[13].p = temp_r27;
    stack[14].i = temp_r12_2;
    stack[81].i = one;
    stack[82].p = temp_r27;
    stack[83].i = temp_r12_2;
    stack[9].i = one;
    stack[10].p = temp_r23;
    stack[11].i = temp_r11_2;
    stack[84].i = one;
    stack[85].p = temp_r23;
    stack[86].i = temp_r11_2;
    stack[6].i = one;
    stack[7].p = temp_r22;
    stack[8].i = temp_r10_2;
    stack[87].i = one;
    stack[88].p = temp_r22;
    stack[89].i = temp_r10_2;
    stack[3].i = one;
    stack[4].p = temp_r21;
    stack[5].i = temp_r9;
    stack[90].i = one;
    stack[91].p = temp_r21;
    stack[92].i = temp_r9;
    stack[0].i = 2;
    stack[1].p = temp_r21;
    stack[2].i = temp_r7_2;
    stack[93].i = 2;
    stack[94].p = temp_r21;
    stack[95].i = temp_r7_2;
    stack[96].i = sp188;
    stack[97].i = sp18c;
    stack[98].i = sp190;

    var_r4_2 = obj + 0x9E;
    var_r24 = &lbl_80559D94;
    var_r20 = 0x14;
    goto loop_5_copy;
loop_5_count:
    var_r20 -= 1;
    if (var_r20 > 0) goto loop_5_copy;
    *(signed char *)(var_r4_2 - 1) = 0;
    goto loop_5_done;
loop_5_copy:
    temp_r5_2 = *var_r24;
    var_r24 += 1;
    *var_r4_2 = temp_r5_2;
    var_r4_2 += 1;
    if ((signed char)temp_r5_2 != 0) goto loop_5_count;
loop_5_done:
    var_r7 = obj + 0x44;
    var_r5 = &lbl_80559D98;
    var_r6 = 0x14;
    goto loop_9_copy;
loop_9_count:
    var_r6 -= 1;
    if (var_r6 > 0) goto loop_9_copy;
    *(signed char *)(var_r7 - 1) = 0;
    goto loop_9_done;
loop_9_copy:
    temp_r4_2 = *var_r5;
    var_r5 += 1;
    *var_r7 = temp_r4_2;
    var_r7 += 1;
    if ((signed char)temp_r4_2 != 0) goto loop_9_count;
loop_9_done:
    var_r7_2 = obj + 0x80;
    var_r5_2 = &lbl_80559D9C;
    var_r6_2 = 0x14;
    goto loop_13_copy;
loop_13_count:
    var_r6_2 -= 1;
    if (var_r6_2 > 0) goto loop_13_copy;
    *(signed char *)(var_r7_2 - 1) = 0;
    goto loop_13_done;
loop_13_copy:
    temp_r4_3 = *var_r5_2;
    var_r5_2 += 1;
    *var_r7_2 = temp_r4_3;
    var_r7_2 += 1;
    if ((signed char)temp_r4_3 != 0) goto loop_13_count;
loop_13_done:
    fn_80130980(obj + 0xB2, 0x14, 2, lbl_805615B4);
    *(s32 *)(obj + 0x104) = fn_80204CF0() + 1;
    *(s32 *)(obj + 0x108) = fn_802ADF34(*(void **)(obj + 0xC), base + 0x8F0, &stack[48].i);
    *(s32 *)(obj + 0x14) = fn_80207848(base + 0x904, 1);
    *(s32 *)(obj + 0x18) = fn_80207848(base + 0x918, 1);
    *(s32 *)(obj + 0x1C) = fn_80207848(base + 0x934, 1);
    *(s32 *)(obj + 0x24) = fn_80207848(base + 0x948, 1);
    *(s32 *)(obj + 0x28) = fn_80207848(base + 0x15C, 1);
    *(s32 *)(obj + 0x2C) = fn_80207848(base + 0x95C, 1);
}
#pragma scheduling on
#pragma optimize_for_size reset
#pragma pop

extern "C" void fn_802ADE60(int, int);
extern "C" void fn_80144184(void *arg0) {
 class VObj { public: virtual void destroy(int); };
 /* Frees the resource at +0x140 and destroys owned objects at +0x148..+0x160. */
 int resource = *(int*)((char*)arg0+0x140);
 if(resource){fn_802ADE60(resource,1);*(int*)((char*)arg0+0x140)=0;}
 VObj *object;
 object=*(VObj**)((char*)arg0+0x148);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x148)=0;}
 object=*(VObj**)((char*)arg0+0x14C);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x14C)=0;}
 object=*(VObj**)((char*)arg0+0x150);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x150)=0;}
 object=*(VObj**)((char*)arg0+0x158);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x158)=0;}
 object=*(VObj**)((char*)arg0+0x15C);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x15C)=0;}
 object=*(VObj**)((char*)arg0+0x160);
 if(object){if(object)object->destroy(1);*(VObj**)((char*)arg0+0x160)=0;}
}

extern "C" void fn_801442D4(void) {

}

extern "C" void fn_801442D8(void) {

}

extern "C" void fn_801442DC(void *arg0) {
    class TObj20 {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
    };
    ((TObj20 *)arg0)->f6();
}

extern "C" s32 fn_801442EC(void) { return 0; }

extern "C" s32 fn_801442F4(void) { return 0; }

extern "C" void fn_801442FC(void) {
}

extern "C" void fn_80144300(void) {
}

extern "C" void fn_80144308(void) {
}

extern "C" void fn_80144304(void) {
}

extern "C" void fn_8014430C(void) {
}

extern "C" void fn_80144310(void) {
}

extern "C" s32 fn_80144314(void) { return 0; }

extern "C" s32 fn_8014431C(void) { return 0; }

extern "C" s32 fn_80144324(void) { return 0; }

extern "C" s32 fn_8014432C(void) { return 0; }

extern "C" void fn_80144334(void) {
}

extern "C" void fn_80144338(void) {
}

extern "C" void fn_8014433C(void) {
}

extern "C" void fn_80144340(void) {
}

extern "C" s32 fn_80144344(void) { return 0; }

extern "C" void fn_8014434C(void) {
}

extern "C" s32 fn_80144350(void) { return 0; }

extern "C" void fn_80144358(void) {
}

extern "C" u32 fn_8014435C(void) { return 1; }

extern "C" s32 fn_80144364(void) { return 0; }

extern "C" s32 fn_8014436C(TObj20 *arg0, s32 arg1) {
    s32 result = 0;
    if (fn_801B8514() != 0 && arg0->v20(arg1) == 0)
        result = 1;
    return result;
}

extern "C" s32 fn_801B8514(void);
extern "C" s32 fn_801443E0(void) { return 0; }

extern "C" u32 fn_801443E8(void) { return 1; }

extern "C" s32 fn_801443F0(void) { return 0; }

extern "C" s32 fn_801443F8(void) { return 0; }

extern "C" s32 fn_80144400(void) { return 0; }

extern "C" void fn_80144408(void) {

}

extern "C" void fn_80128668(void);
extern "C" s32 fn_8014440C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8014444C(void) { return 0; }

extern "C" s32 fn_80144454(void) { return 0; }

extern "C" s32 fn_8013D1F0(s32);
#pragma dont_inline on
extern "C" s32 fn_8014445C(s32 arg0, s32 arg1) {
    s32 v = fn_8013D1F0(arg1) ^ 0xA;
    return ((v >> 1) - (v & 0xA)) < 0;
}
#pragma dont_inline off
extern "C" s32 fn_80144494(s32 arg0, s32 arg1) { return arg1; }
struct Fn8013FC6CDispatch {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual int test(int);
};
class TObj10DispatchA6C { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void v10(const char *); };
struct TObj24A { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void *v24(); };
struct S3FAC4 { s32 a, b, c, d; f32 e, f, g, h, i, j; };
struct S32_80140728 { s32 v[8]; f32 f[6]; };
extern "C" f32 lbl_805614C4;
extern "C" u8 lbl_8032C530[0x500];
extern "C" void fn_80147BD0(s32, s32, s32, s32, s32, f32);

#pragma processor 750
#pragma push
#pragma optimize level=4
#pragma scheduling invalid_target
extern "C" void fn_8013FAC4(void *arg0, void *arg2) {
    s32 enabled = *(s32 *)((u8 *)arg2 + 0x104);
    f32 temp_f1;
    s32 var_r0;
    f32 temp_f0;
    f32 var_f3;
    f32 var_f31;
    void *temp_r3_2;
    s32 sp14, sp10, spC, sp8;
    f32 sp18, sp1C, sp20, sp24, sp28, sp2C;
    extern char lbl_8032C978[];
    extern char lbl_8032C988[];
    extern f32 fn_8001DAE8(void *);
    extern f32 fn_8001DAF0(void *);
    extern void fn_8013CB90(void *);
    extern void fn_80147EE0(void *, f32);
    extern void fn_801476D8(void *, void *, s32);
    extern void fn_801476C4(void *);
    if (enabled != 0) {
        temp_r3_2 = ((void *(*)(void *, void *))(*(void ***)arg0)[9])(arg0, &lbl_8032C978);
        if (temp_r3_2 != NULL) {
            temp_f1 = fn_8001DAE8((u8 *)arg2 + 0xC8) - *(f32 *)((u8 *)arg2 + 0xCC);
            var_r0 = 0;
            if ((temp_f1 >= lbl_805614A4) && (temp_f1 < *(f32 *)((u8 *)arg2 + 0xC8))) {
                var_r0 = 1;
            }
            if (var_r0 != 0) {
                var_f3 = lbl_805614AC;
                temp_f0 = (fn_8001DAF0((u8 *)arg2 + 0xC8) - lbl_80561498) / lbl_80561498;
                if (var_f3 < temp_f0) {
                    var_f3 = temp_f0;
                }
                if (var_f3 > lbl_805614A4) {
                    var_f3 = lbl_805614A4;
                }
                var_f31 = lbl_805614A4 + (var_f3 * lbl_805614AC);
            } else {
                var_f31 = lbl_805614AC;
            }
            sp8 = *(s32 *)((u8 *)temp_r3_2 + 0);
            sp10 = *(s32 *)((u8 *)temp_r3_2 + 4);
            spC = *(s32 *)((u8 *)temp_r3_2 + 8);
            sp14 = *(s32 *)((u8 *)temp_r3_2 + 0xC);
            sp18 = *(f32 *)((u8 *)temp_r3_2 + 0x10);
            sp1C = *(f32 *)((u8 *)temp_r3_2 + 0x14);
            sp20 = *(f32 *)((u8 *)temp_r3_2 + 0x18);
            sp24 = *(f32 *)((u8 *)temp_r3_2 + 0x1C);
            sp28 = *(f32 *)((u8 *)temp_r3_2 + 0x20);
            sp2C = *(f32 *)((u8 *)temp_r3_2 + 0x24);
            fn_8013CB90(&sp8);
            fn_80147EE0(&sp8, var_f31);
            fn_801476D8(&sp8, fn_80147C50(0xFFFFFF, -1, lbl_805614AC + var_f3 * lbl_805614BC), *(s32 *)((u8 *)arg0 + 0xAC));
        }
        ((void (*)(void *, void *))(*(void ***)arg0)[3])(arg0, &lbl_8032C988);
        fn_801476C4(NULL);
    }
}
#pragma optimize reset
#pragma pop
// fn_80140B98 - quaternion-based vector transformation
extern "C" void fn_80140B98(void *arg0, void *arg1, s32 arg2);