// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
__declspec(section ".sdata") extern const char lbl_8055B2A8[], lbl_8055B2B0[], lbl_8055B2B8[], lbl_8055B2C0[];
extern s32 lbl_8055EC48;
extern "C" s32 fn_802C6B44(void *);
extern "C" s32 fn_802C6C20(f32);
extern "C" s32 lbl_8055EC64;
extern "C" const char lbl_8033AFDC[];
extern "C" const f32 lbl_80562FF8;
extern "C" {
__declspec(section ".sdata") extern const char lbl_8055B3B8[];
__declspec(section ".sdata") extern const char lbl_8055B3C0[];
extern const char lbl_8033B578[];
extern const char lbl_80488898[];
extern u8 lbl_8055EC6C;
extern u8 lbl_8055EC40;
extern s32 lbl_8055EC70;
void fn_801FC644(void **, void *);
void *fn_802077A4(s32, s32, void *, void *);
}
extern "C" void fn_801EF024(void *);
extern "C" {
extern u8 lbl_8033B418[], lbl_8033B53C[], lbl_8033B52C[], lbl_8033B51C[];
extern u8 lbl_80333B98[], lbl_803337C8[], lbl_80333918[];
extern f32 lbl_80563010, lbl_80562FFC;
void fn_801A324C(void*, s32, void*, f32, f32);
}
struct FAAVec { f32 x; f32 y; f32 z; };
struct FAANames { char *n[24]; };
struct FAANames2 { u32 w[24]; };
struct FAADest { u8 b[0x80]; };
class FAAMgr {
public:
    virtual void a8();
    virtual void aC();
    virtual void a10();
    virtual void *get(const char *);
    virtual const char *getD(const char *, const char *);
    virtual void a1C();
    virtual void a20();
    virtual f32 getF(const char *);
    virtual f32 getFD(const char *, f32);
    virtual void a2C();
    virtual void a30();
    virtual FAAVec getV(const char *);
};
extern "C" void *memcpy(void *, const void *, unsigned int);
extern u32 lbl_802F9B40[];
__declspec(section ".sdata") extern const char lbl_8055B328[], lbl_8055B32C[], lbl_8055B330[], lbl_8055B334[], lbl_8055B338[], lbl_8055B340[], lbl_8055B344[], lbl_8055B348[], lbl_8055B34C[], lbl_8055B354[], lbl_8055B35C[], lbl_8055B364[];
extern const f32 lbl_8056300C;
extern "C" char *fn_80029004(char *, s32);


extern "C" {
extern void **lbl_8055EC74;
extern s32 lbl_8055EC78;
extern u8 lbl_8055EC3C;
extern void *lbl_8055EC4C;
extern u8 lbl_8033B5B8[];
void fn_801F9BE8(void);
void fn_801B5D30(void *);
void fn_801792F4(void);
void *fn_8013184C(void);
void *fn_801284F8(u32, void *);
void *fn_801A4A8C(void *, s32, s32, s32, s32, void *);
void *fn_801E87A8(void);
s32 fn_802C9C58(s32);
void fn_802C7A44(void);
void fn_802C7A50(void);
void fn_802C7AD4(void);
}


extern "C" {
extern char lbl_8033AF80[];
extern char lbl_8033B440[];
__declspec(section ".sdata") extern char lbl_8055B300[];
__declspec(section ".sdata") extern char lbl_8055B308[];
__declspec(section ".sdata") extern char lbl_8055B310[];
extern s32 lbl_8055B388;
extern void **lbl_8055EC54;
extern s32 lbl_8055EC58;
void **fn_80131810(void *);
void fn_80131818(void *);
void fn_8013A0B0(void **, void *, void *);
void fn_8013A198(void **, s32);
void *fn_8000AC38(void);
void fn_801F9AA4(void *, s32);
void fn_801F8988(void *, void *);
}

extern "C" {
extern s32 lbl_8055B1C8;
s32 fn_80204014(s32, s32, s32, void *);
void *fn_802C86DC(void);
void fn_802C70AC(s32, void *, s32, s32);
f32 PSVECDotProduct(const f32 *, const f32 *);
}

class F9CleanCall {
public:
    virtual void first();
    virtual void next(s32);
};

class F7A88Class {
public:
    virtual void v8();
    virtual int vC();
    virtual void v10();
    virtual void *v14(s32);
};
extern "C" int fn_8012F9E8(void *, s32, void *);
class F9Resource {
public:
    virtual void *s8(void *);
    virtual void sC();
    virtual s32 s10(void *);
};
class F9Manager {
public:
    virtual void s8();
    virtual void sC();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual s32 s30(void *, s32);
};

class F7E20VTable {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual f32 apply(const char *, f32);
};

struct FIterVT {
    void *vtable; // 0x0
    void *vtbl;   // 0x8
};

struct FIter60 {
    void *vtable; // 0x0
    void *unused[23];
    void *vtbl; // 0x60
};

extern u8 lbl_8033B468[];
extern const f32 lbl_80562FF0;
extern const f32 lbl_80563000;
extern "C" void *memset(void *, s32, u32);

struct F92VT {
    u8 pad[8];
    void (*fn8)(void *, s32); // 0x8
};

struct FListVT {
    u8 pad[0x60];
    void *(*get)(void *self, s32 idx); // 0x60
};

struct FNodeVT {
    u8 pad[8];
    char *(*name)(void *self); // 0x8
};

struct F92Obj {
    u8 pad0[0x20];
    void *f20;  // 0x20
    void *f24;  // 0x24
    f32 f28;    // 0x28
    u8 pad2[0x60 - 0x2c];
    s8 b60;     // 0x60
    u8 pad3[0x74 - 0x61];
    s32 w74;    // 0x74
    s32 w78;    // 0x78
    f32 f7c;    // 0x7c
    f32 f80;    // 0x80
    u8 pad4[0x104 - 0x84];
    void *w104; // 0x104
    void *w108; // 0x108
};
extern "C" void *fn_801F92AC(F92Obj *);
extern "C" void fn_801F92A8(void);
extern "C" int fn_801F88F4(void *);

struct F92Node {
    u8 pad0[0x20];
    F92Node *next; // 0x20
    F92Node *f24;  // 0x24
};

extern "C" void fn_801FA010(void **);
extern "C" void fn_80204020(void);
extern "C" void fn_80128670(void *);
extern "C" void fn_801FA0B0(void **);
extern "C" void fn_801F9A24(F92Node **);
extern "C" s32 fn_801F9CF8(void *);
extern "C" void fn_801FA138(void **);
extern "C" void clear__Q211J2DBloSaver19CTextureNameConnectFv(void **);
extern "C" void *lbl_8055EC50;
extern "C" void *lbl_8055EC5C;
extern "C" void *lbl_8055EC60;
extern "C" void *lbl_8055EC38;
extern "C" void *lbl_8055EC44;
extern "C" {

extern u8 lbl_8033B1EC[];
extern u8 lbl_8033B210[];
extern u8 lbl_8033B024[];
extern u32 lbl_802F9BA0[8];
__declspec(section ".sdata") extern u8 lbl_8055B2CC[];
__declspec(section ".sdata") extern u8 lbl_8055B2D4[];
__declspec(section ".sdata") extern u8 lbl_8055B2DC[];
extern s32 lbl_8055B36C;
__declspec(section ".sdata") extern const char lbl_8055B37C[];
extern u8 lbl_8055B374[];
extern void *lbl_8055EC38;
extern void *lbl_8055EC44;
int stricmp(const char *, const char *);
    void *fn_801F8188(void *a, s32 b, s32 c);
  void fn_802E317C(const char *, ...);
  s32 fn_801F9450(void *node);
      void *fn_801F95C4(void *fn, void *node);
          void fn_801F96A8(void *node);
              void *fn_801F93FC(void *node = 0);
        }
extern "C" void *fn_801F981C(void *node, s32 arg);
extern "C" void fn_801F9928(void *list, s32 arg);
extern "C" void fn_801F9440(F92Node **list, F92Node *node);

struct F9Node {
    void *vtable; // 0x0
    char *name;   // 0x4
    void *next;   // 0x8
    // 0x20
    void *next2;
};

class FNode2 {
public:
    virtual void v4();
    virtual const char *name();
};

class FList2 {
public:
    virtual void *s4();
    virtual void *s8();
    virtual void *sC();
    virtual void *s10();
    virtual void *s14();
    virtual void *s18();
    virtual void *s1C();
    virtual void *s20();
    virtual void *s24();
    virtual void *s28();
    virtual void *s2C();
    virtual void *s30();
    virtual void *s34();
    virtual void *s38();
    virtual void *s3C();
    virtual void *s40();
    virtual void *s44();
    virtual void *s48();
    virtual void *s4C();
    virtual void *s50();
    virtual void *s54();
    virtual void *s58();
    virtual void *s5C();
    virtual void *get(s32 idx);
};

struct F92Tbl {
    u8 pad[8];
    void (*fn8)(void *, s32); // 0x8
};

struct F92Elem {
    u8 pad0[0x24];
    F92Elem *next;          // 0x24
    u8 pad1[0x108 - 0x28];
    F92Tbl *tbl;            // 0x108
};

struct F9NodeFn {
    void *vtable; // 0x0
    void (*fn)(void *); // 0x8
};

struct F9List {
    void *vtable; // 0x0
    char *name;   // 0x4
    void *next;   // 0x8
    void *next2;  // 0x20
};

#pragma dont_inline on
extern "C" u32 fn_801F7A0C(void) { return 1; }

extern "C" void PSVECCrossProduct(const f32 *, f32 *);
extern "C" f32 PSVECDotProduct(const f32 *, const f32 *);
extern const f32 lbl_80562FF4;
extern "C" void fn_801F7A14(void *arg0) {
    f32 cross[3];
    ((void (*)(void *, void *, void *))PSVECCrossProduct)(arg0, (u8 *)arg0 + 0xC, cross);
    if (PSVECDotProduct(cross, (f32 *)((u8 *)arg0 + 0x18)) < lbl_80562FF0) {
        ((f32 *)arg0)[0] *= lbl_80562FF4;
        ((f32 *)arg0)[1] *= lbl_80562FF4;
        ((f32 *)arg0)[2] *= lbl_80562FF4;
    }
}

extern "C" void fn_801F7A14(void *);
extern "C" s32 fn_801F7A88(void *, s32, void *, s32);
__declspec(section ".sdata") extern const char lbl_8055B280[];
__declspec(section ".sdata") extern const char lbl_8055B288[];
__declspec(section ".sdata") extern const char lbl_8055B290[];
__declspec(section ".sdata") extern const char lbl_8055B298[];
extern "C" s32 fn_801F7A88(void *, s32, void *, s32);
extern "C" void fn_801F7A14(void *);
#pragma scheduling invalid_target
extern "C" s32 fn_801F7B10(void *arg0, void *arg1, s32 arg2) {
    volatile u8 *dst = (volatile u8 *)arg0;
    s32 i;
    if (fn_801F7A88(arg1, arg2, (void *)dst, 0x30) != 0) {
        for (i = 0; i < 2; i++) {
            volatile u8 *p = dst + i * 0x18;
            u8 t;
            t=p[0];p[0]=p[3];p[3]=t;t=p[1];p[1]=p[2];p[2]=t;
            t=p[4];p[4]=p[7];p[7]=t;t=p[5];p[5]=p[6];p[6]=t;
            t=p[8];p[8]=p[0xB];p[0xB]=t;t=p[9];p[9]=p[0xA];p[0xA]=t;
            t=p[0xC];p[0xC]=p[0xF];p[0xF]=t;t=p[0xD];p[0xD]=p[0xE];p[0xE]=t;
            t=p[0x10];p[0x10]=p[0x13];p[0x13]=t;t=p[0x11];p[0x11]=p[0x12];p[0x12]=t;
            t=p[0x14];p[0x14]=p[0x17];p[0x17]=t;t=p[0x15];p[0x15]=p[0x16];p[0x16]=t;
        }
    } else {
        f32 a[3], b[3], c[3], d[3];
        ((void (*)(void *, void *, const char *))(*(void ***)arg1)[13])(a, arg1, lbl_8055B280);
        ((f32 *)dst)[0]=a[0]; ((f32 *)dst)[1]=a[1]; ((f32 *)dst)[2]=a[2];
        ((void (*)(void *, void *, const char *))(*(void ***)arg1)[13])(b, arg1, lbl_8055B288);
        ((f32 *)dst)[3]=b[0]; ((f32 *)dst)[4]=b[1]; ((f32 *)dst)[5]=b[2];
        ((void (*)(void *, void *, const char *))(*(void ***)arg1)[13])(c, arg1, lbl_8055B290);
        ((f32 *)dst)[6]=c[0]; ((f32 *)dst)[7]=c[1]; ((f32 *)dst)[8]=c[2];
        ((void (*)(void *, void *, const char *))(*(void ***)arg1)[13])(d, arg1, lbl_8055B298);
        ((f32 *)dst)[9]=d[0]; ((f32 *)dst)[10]=d[1]; ((f32 *)dst)[11]=d[2];
    }
    fn_801F7A14((void *)dst);
}
#pragma scheduling on
extern "C" s32 fn_80204BB4(void);
extern "C" s32 fn_80204CF0(void);
extern "C" char lbl_8033AFB8[];
extern "C" char lbl_8033AFC8[];
#pragma scheduling invalid_target
extern "C" void fn_801F7D10(void *arg0, void *arg1, void *arg2) {
    /* Initializes output record arg1 from queried object arg2:
       if "unfloat_frame64" is present, loads base data via fn_801F7B10 then scales/adds offsets 0x0C/0x10/0x14 into 0x24/0x28/0x2C using scale at arg0+0x28;
       if "difficulty_level" is present, sets arg1+0x38 from fn_80204BB4() and finishes it, else uses fn_80204CF0();
       stores arg2 at arg1+0x34. */
    struct VTable {
        virtual void slot0();
        virtual s32 check(const char *);
        virtual void slot2();
        virtual void finish(const char *);
    };
    if (((VTable *)arg2)->check(lbl_8033AFB8) != 0) {
        fn_801F7B10(arg1, arg2, (s32)lbl_8033AFB8);
        f32 scale = *(f32 *)((u8 *)arg0 + 0x28);
        *(f32 *)((u8 *)arg1 + 0x24) =
            *(f32 *)((u8 *)arg1 + 0x24) + *(f32 *)((u8 *)arg1 + 0x0C) * scale;
        *(f32 *)((u8 *)arg1 + 0x28) =
            *(f32 *)((u8 *)arg1 + 0x28) + *(f32 *)((u8 *)arg1 + 0x10) * scale;
        *(f32 *)((u8 *)arg1 + 0x2C) =
            *(f32 *)((u8 *)arg1 + 0x2C) + *(f32 *)((u8 *)arg1 + 0x14) * scale;
    }
    if (((VTable *)arg2)->check(lbl_8033AFC8) != 0) {
        ((VTable *)arg2)->finish(lbl_8033AFC8);
        *(s32 *)((u8 *)arg1 + 0x38) = fn_80204BB4();
    } else {
        *(s32 *)((u8 *)arg1 + 0x38) = fn_80204CF0();
    }
    *(void **)((u8 *)arg1 + 0x34) = arg2;
}
#pragma scheduling on
extern "C" void fn_801F7E20(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg1;
    f32 temp;
    f32 value;
    if (*(s8 *)(obj + 0x61) != 0) {
        temp = -*(f32 *)((u8 *)fn_802C6B44(obj + 0x61) + 0x34);
        value = lbl_80562FF8 + temp;
        *(f32 *)(obj + 0x28) = value;
        fn_802C6C20(temp);
    } else {
        *(f32 *)(obj + 0x28) = lbl_80562FF0;
    }
    *(f32 *)(obj + 0x28) =
        ((F7E20VTable *)arg0)->apply(lbl_8033AFDC, *(f32 *)(obj + 0x28));
}
#pragma scheduling on
extern u8 lbl_8033AFE8[];
extern s32 lbl_8055B2A0;
extern f32 lbl_80562FFC;
s32 fn_801F7B10(void *, void *, s32);
s32 fn_801BFD34(void *, void *, s32);
extern "C" void fn_801BFD34(void *, void *, void *);
s32 fn_80015B20(void *, void *, s32);
extern "C" void fn_80015B20(void *, void *, void *);
#pragma scheduling invalid_target
/* Gets "local_frame" via vtable slot get() into a 3x4 matrix (out); on success fills from frame64 data, else writes identity. If arg is non-null, transforms the translation/rotation parts with arg and returns 1 when a frame or arg was applied. */
extern "C" s32 fn_801F7EB0(void *out, void *self, s32 arg) {
    struct VCall {
        virtual s32 f0();
        virtual s32 f1();
        virtual s32 f2();
        virtual s32 f3();
        virtual s32 f4();
        virtual s32 f5();
        virtual s32 f6();
        virtual s32 f7();
        virtual s32 f8();
        virtual s32 f9();
        virtual s32 f10();
        virtual s32 f11();
        virtual s32 f12();
        virtual s32 f13();
        virtual s32 f14();
        virtual s32 f15();
        virtual s32 f16();
        virtual s32 f17();
        virtual s32 f18();
        virtual s32 f19();
        virtual s32 f20();
        virtual s32 get(const u8 *);
    };
    s32 result = ((VCall *)self)->get(lbl_8033AFE8);
    if (result != 0) {
        fn_801F7B10(out, (void *)result, (s32)&lbl_8055B2A0);
    } else {
        f32 value0 = lbl_80562FF0;
        f32 value1 = lbl_80562FFC;
        volatile f32 *dst = (volatile f32 *)out;
        dst[1] = value0;
        dst[0] = value1;
        dst[2] = value0;
        dst[3] = value0;
        dst[4] = value1;
        dst[5] = value0;
        dst[6] = value0;
        dst[7] = value0;
        dst[8] = value1;
        dst[9] = value0;
        dst[10] = value0;
        dst[11] = value0;
    }
    if (arg != 0) {
        fn_801BFD34((u8 *)out + 0x24, (u8 *)out + 0x24, (void *)arg);
        fn_80015B20(out, out, (void *)arg);
    }
    s32 ret = 0;
    if (result != 0) goto set_result;
    if (arg == 0) goto done;
set_result:
    ret = 1;
done:
    return ret;
}
// Reads a parent descriptor into output: stores model/extend_dist/cutoff_dist, then copies
// each child named "offset" as (vector xyz, value) records and writes the record count.
extern "C" void fn_801F7FA0(void *output, void *input, void *unused) {
    struct Vector {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Child {
        virtual const char *name();
        virtual void v0C();
        virtual void v10();
        virtual void v14();
        virtual void v18();
        virtual s32 value(const char *);
        virtual void v20();
        virtual void v24();
        virtual void v28();
        virtual void v2C();
        virtual void v30();
        virtual Vector vector(const char *);
    };
    struct Parent {
        virtual void v08();
        virtual void v0C();
        virtual void v10();
        virtual void *first(const char *);
        virtual void v18();
        virtual void v1C();
        virtual void v20();
        virtual f32 getFloat(const char *);
        virtual void v28();
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual void v38();
        virtual void v3C();
        virtual void v40();
        virtual void v44();
        virtual void v48();
        virtual void v4C();
        virtual void v50();
        virtual void v54();
        virtual void v58();
        virtual void v5C();
        virtual Child *getChild(s32);
    };
    extern const char lbl_8033AFF4[];
    extern const char lbl_8033B000[];
    extern int stricmp(const char *, const char *);

    register u8 *record;
    register s32 count;
    register s32 index;
    register Child *child;
    register Parent *parent = (Parent *)input;
    register u8 *out = (u8 *)output;

    *(void **)out = parent->first(lbl_8055B2A8);
    *(f32 *)(out + 4) = parent->getFloat(lbl_8033AFF4);
    *(f32 *)(out + 8) = parent->getFloat(lbl_8033B000);

    record = out;
    count = 0;
    index = 0;
    while (parent->getChild(index) != 0) {
        child = parent->getChild(index);
        if (stricmp(child->name(), lbl_8055B2B0) == 0) {
            const Vector& values = child->vector(lbl_8055B2B8);
            *(f32 *)(record + 0x0C) = values.x;
            *(f32 *)(record + 0x10) = values.y;
            *(f32 *)(record + 0x14) = values.z;
            *(s32 *)(record + 0x18) = child->value(lbl_8055B2C0);
            record += 0x10;
            count++;
        }
        index++;
    }
    *(s32 *)(out + 0x8C) = count;
}

#pragma scheduling on

extern "C" int stricmp(const char *, const char *);
extern "C" const char lbl_8033B00C[];
extern "C" __declspec(section ".sdata") const char lbl_8055B2C4[];
extern "C" s32 fn_802C6B44(void *);
extern "C" s32 fn_802C6C20(f32);
extern "C" void fn_80128668(void);
extern "C" const char lbl_8033AFDC[];
extern "C" const f32 lbl_80562FF8;
extern "C" s32 fn_801F80FC(const char *arg) {
    return stricmp(arg, lbl_8033B00C) == 0;
}

extern "C" const char lbl_8033B018[];
extern "C" s32 fn_801F812C(const char *arg) {
    return stricmp(arg, lbl_8033B018) == 0;
}

#pragma push
#pragma small_data on
#pragma pop
extern "C" const f32 lbl_80562FF0;
extern "C" s32 fn_801F815C(const char *arg) { return stricmp(arg, lbl_8055B2C4) == 0; }

/* Keys fn_801F8188 reads out of the parameter node (the game's object/parameter files). */
#define OBJ_KEY_TYPE        ((const char *)lbl_8055B2CC)  /* "type": composite / animation / sound */
#define OBJ_KEY_MODEL       lbl_8055B2A8                  /* "model" */
#define OBJ_KEY_NAME        ((const char *)lbl_8055B2DC)  /* "name" */
#define OBJ_KEY_SHADOW      ((const char *)lbl_8055B2D4)  /* "shadow" */
#define OBJ_KEY_DROP_HEIGHT lbl_8033AFDC                  /* "drop_height" */
#define OBJ_KEY_FORBIDDEN   ((const char *)lbl_8033B024)  /* "forbidden_in_objects_file" */

/* The shadow description fn_801F7FA0 builds at +0x78 of a created object. */
struct ShadowDesc {
    void *model;   /* 0x00 the shadow's model node */
    f32 f04;       /* 0x04 */
    f32 f08;       /* 0x08 */
    u8 parts[0x8C - 0xC];
    s32 count;     /* 0x8C how many shadow parts were found */
};

/* The part of a created object that the factory fills in; composite/animation/sound
 * objects carry more after this (see fn_801F861C and fn_801F86C8). */
struct PlacedObj {
    char name[0x20];      /* 0x00 "name", copied when the caller asks for it */
    u8 pad20[0x28 - 0x20];
    f32 dropHeight;       /* 0x28 height the object may drop, from "drop_height" */
    u8 forbidden;         /* 0x2C "forbidden_in_objects_file" flag */
    u8 pad2D[3];
    f32 placement[12];    /* 0x30 3x4 placement matrix built by fn_801F7EB0 */
    u8 hasPlacement;      /* 0x60 set when the placement came from the node */
    char model[0x10];     /* 0x61 "model" */
    u8 pad71[0x78 - 0x71];
    ShadowDesc shadow;    /* 0x78 */
};

/* fn_801F8188 - object factory: looks at the parameter node's "type" ("composite", "animation",
 * "sound", or none of them) and lets the matching creator in the table at 0x802F9BA0 allocate the
 * object, then fills in what every type shares: its placement matrix (optionally transformed by
 * `transform`), model name, drop height, "forbidden in objects file" flag and shadow description,
 * and finally its "name" when the caller asks for it. Returns the new object. */
extern "C" void *fn_801F8188(void *node, s32 transform, s32 copyName) {
    /* The parameter node: reads values and child nodes by key through its vtable. */
    class Node {
    public:
        virtual void s8();
        virtual void sC();
        virtual void s10();
        virtual const char *getString(const char *);   /* 0x14: a string value */
        virtual void s18();
        virtual void s1C();
        virtual void s20();
        virtual void s24();
        virtual f32 getFloat(const char *, f32);       /* 0x28: a float, with a default */
        virtual void s2C();
        virtual u8 getFlag(const char *, s32);         /* 0x30: a boolean, with a default */
        virtual void s34();
        virtual void s38();
        virtual void s3C();
        virtual void s40();
        virtual void s44();
        virtual void s48();
        virtual void s4C();
        virtual void s50();
        virtual void s54();
        virtual void s58();
        virtual void *getNode(const char *);           /* 0x58: a child node */
    };
    /* One row of the type table: a "is this our type?" test (0 = take anything) and a creator. */
    struct TypeEntry {
        s32 (*matches)(const char *);
        void *(*create)(void *);
    };
    struct TypeTable { TypeEntry entry[4]; };
    TypeEntry *entry;
    const char *typeName = ((Node *)node)->getString(OBJ_KEY_TYPE);
    TypeTable table = *(TypeTable *)lbl_802F9BA0;
    PlacedObj *obj = 0;
    entry = table.entry;
    for (u32 i = 0; i < 4; i++, entry++) {
        if (entry->matches == 0 || entry->matches(typeName) != 0) {
            obj = (PlacedObj *)table.entry[i].create(node);
            break;
        }
    }
    if (fn_801F80FC(typeName) == 0) {  /* not a "composite": it is placed in the world itself */
        const char *s = ((Node *)node)->getString(OBJ_KEY_MODEL);
        s32 n = 0x10;
        char *d = obj->model;
        u8 c;
        goto copyModel;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }   /* model name truncated to 15 characters */
copyModel:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        obj->hasPlacement = fn_801F7EB0(obj->placement, node, transform);
        fn_801F7E20(node, obj);
        obj->forbidden = ((Node *)node)->getFlag(OBJ_KEY_FORBIDDEN, 0);
        if (((Node *)node)->getNode(OBJ_KEY_SHADOW) != 0) {
            ((void (*)(void *, void *))fn_801F7FA0)(&obj->shadow, ((Node *)node)->getNode(OBJ_KEY_SHADOW));
        }
    } else {  /* a composite has no model: only how far it may fall */
        obj->dropHeight = ((Node *)node)->getFloat(OBJ_KEY_DROP_HEIGHT, obj->dropHeight);
    }
    if (copyName != 0) {
        const char *s = ((Node *)node)->getString(OBJ_KEY_NAME);
        s32 n = 0x20;
        char *d = obj->name;
        u8 c;
        goto copyNameLoop;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }   /* name truncated to 31 characters */
copyNameLoop:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
    }
    return obj;
}

__declspec(section ".sdata") extern const char lbl_8055B2A8[], lbl_8055B2B0[], lbl_8055B2B8[], lbl_8055B2C0[], lbl_8055B2E4[], lbl_8055B2EC[];
extern "C" int sprintf(char *, const char *, ...);
// Allocates and initializes a 0x168-byte object: sets vtables/default fields, resolves
// named resources and flags from the manager, and returns the initialized object.
extern "C" void *fn_801F83E4(void *arg0) {
    class Manager {
    public:
        virtual void m8();
        virtual int has(const char *);
        virtual void m10();
        virtual void *get(const char *);
        virtual void *combine(const char *, void *);
        virtual void m1C();
        virtual void m20();
        virtual void m24();
        virtual void m28();
        virtual void m2C();
        virtual u8 flag(const char *, s32);
    };
    register const char *base = lbl_8033AF80;
    u8 *object = (u8 *)fn_801284F8(0x168, (void *)lbl_8055B2E4);
    char resourceName[0x20];
    if (object != 0) {
        *(void **)(object + 0x108) = lbl_8033B468;
        *(s32 *)(object + 0x78) = 0;
        *(f32 *)(object + 0x7C) = lbl_80562FF0;
        *(f32 *)(object + 0x80) = lbl_80562FF0;
        *(s32 *)(object + 0x104) = 0;
        *(s32 *)(object + 0x24) = 0;
        *(s32 *)(object + 0x20) = 0;
        *(f32 *)(object + 0x28) = lbl_80563000;
        object[0x60] = 1;
        memset(object, 0x61, 0x20);
        memset(object + 0x61, 0x61, 0x10);
        *(s32 *)(object + 0x74) = -1;
        *(void **)(object + 0x108) = lbl_8033B418;
        *(void **)(object + 0x13C) = ((Manager *)arg0)->combine(base + 0xC0, ((Manager *)arg0)->get(lbl_8055B2A8));
        *(void **)(object + 0x140) = ((Manager *)arg0)->get(base + 0xCC);
        *(s32 *)(object + 0x160) = 1;
        while (*(s32 *)(object + 0x160) < 8) {
            sprintf(resourceName, base + 0xD8, *(s32 *)(object + 0x160) + 1);
            if (((Manager *)arg0)->has(resourceName) == 0) {
                break;
            }
            *(void **)(object + 0x140 + (*(s32 *)(object + 0x160) * 4)) = ((Manager *)arg0)->get(resourceName);
            *(s32 *)(object + 0x160) = *(s32 *)(object + 0x160) + 1;
        }
        object[0x164] = ((Manager *)arg0)->flag(lbl_8055B2EC, 1);
        object[0x165] = ((Manager *)arg0)->flag(base + 0xE8, 1);
        ((Manager *)arg0)->get((const char *)lbl_8055B2DC);
    }
    return object;
}

extern "C" s32 fn_801F85DC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void *lbl_8055B2F8;
extern u8 lbl_8033B3F0[];
#pragma scheduling invalid_target
extern "C" void *fn_801F861C(void) {
    /* Allocate and initialize a SoundDI object (0x10C bytes): set initial/final vtables,
     * default fields, fill the first 0x30 bytes with 0x61, and mark index -1. */
    F92Obj *obj = (F92Obj *)fn_801284F8(0x10C, &lbl_8055B2F8);
    if (obj) {
        f32 b = lbl_80563000;
        f32 a = lbl_80562FF0;
        obj->w108 = lbl_8033B468;
        obj->w78 = 0;
        obj->f7c = a;
        obj->f80 = a;
        obj->w104 = 0;
        obj->f24 = 0;
        obj->f20 = 0;
        obj->f28 = b;
        obj->b60 = 1;
        memset(obj, 0x61, 0x20);
        memset((char *)obj + 0x61, 0x61, 0x10);
        obj->w74 = -1;
        obj->w108 = lbl_8033B3F0;
    }
    return obj;
}
#pragma scheduling on
/* Keys the obstacle creator reads from the parameter node.  The strings sit in the pool at
 * lbl_8033AF80 ("polyhedra") unless they are named out of small data. */
#define OBS_TAG_OBSTACLE      (base + 0xF4)   /* "ObstacleDI": what to call the allocation */
#define OBS_KEY_FACING_TEST   (base + 0x100)  /* "facing_test" */
#define OBS_KEY_REFLECT_LOAD  (base + 0x110)  /* "reflect_on_load" */
#define OBS_KEY_FACING_X_TEST (base + 0x120)  /* "facing_x_test" */
#define OBS_KEY_FABRIC        lbl_8055B300    /* "fabric" */
#define OBS_KEY_EFFECT        lbl_8055B308    /* "effect": the fabric's effect name */
#define OBS_NO_EFFECT         lbl_8055B310    /* "" - the node asked for no effect */
#define OBS_KEY_DRAW_LAST     (base + 0x130)  /* "draw_last" */
#define OBS_KEY_ONESIDED      (base + 0x13C)  /* "onesided" */
#define OBS_KEY_SOBJ_EVENT    (base + 0x148)  /* "sobj_event" */
#define OBS_KEY_DEFAULT_PROPS (base + 0x154)  /* "default_properties" */

/* The obstacle's option word, at +0x190 of the object. */
#define OBS_OPT_FACING_TEST   0x1   /* turn to face the camera (fn_801FB354) */
#define OBS_OPT_NOT_FLOATER   0x4   /* its "type" is neither "floater" nor "gfx" (fn_801F88F4) */
#define OBS_OPT_FACING_X      0x20  /* "facing_x_test" */
#define OBS_OPT_FABRIC        0x40  /* "fabric": cloth, with its effect name at +0x194 */
#define OBS_OPT_DRAW_LAST     0x80  /* "draw_last": drawn after everything else */
#define OBS_OPT_REFLECT_LOAD  0x100 /* "reflect_on_load": mirror the placement (fn_801FB284) */
#define OBS_OPT_ONESIDED      0x200 /* "onesided": nothing shows through it */

/* fn_801F86C8 - the obstacle creator.  The object factory (fn_801F8188) falls through to it for
 * any node whose "type" is none of composite / animation / sound, so an obstacle is what a plain
 * object in the game's object files becomes.  It allocates the object under the "ObstacleDI" tag,
 * builds the part every created object shares plus the "OBST" record at +0x10C (fn_801F8988), and
 * finally reads the obstacle-only switches and values out of the parameter node. */
extern "C" void *fn_801F86C8(void *node) {
    /* What this creator adds past the part every created object shares. */
    struct Obstacle {
        u8 pad[0x108];
        void *vtable;        /* 0x108 the obstacle's own vtable, lbl_8033B440 */
        s32 obst;            /* 0x10C the "OBST" record fn_801F8988 fills in */
        u8 pad110[0x190 - 0x110];
        u32 options;         /* 0x190 the OBS_OPT_* bits */
        const char *effect;  /* 0x194 the fabric's effect name, "" when there is none */
        s32 sobjEvent;       /* 0x198 "sobj_event", -1 when the node has none */
        void *defaultProps;  /* 0x19C the "default_properties" child node */
    };
    /* The parameter node: reads values and child nodes by key through its vtable. */
    class Node {
    public:
        virtual void s8();
        virtual void sC();
        virtual void s10();
        virtual const char *getString(const char *);  /* 0x14: a string value */
        virtual void s18();
        virtual void s1C();
        virtual s32 getInt(const char *, s32);   /* 0x20: an int, with a default */
        virtual void s24();
        virtual void s28();
        virtual void s2C();
        virtual s32 getFlag(const char *, s32);  /* 0x30: a boolean, with a default */
        virtual void s34();
        virtual void s38();
        virtual void s3C();
        virtual void s40();
        virtual void s44();
        virtual void s48();
        virtual void s4C();
        virtual void s50();
        virtual void s54();
        virtual void s58();
        virtual void *getNode(const char *);     /* 0x5C: a child node */
    };
    const char *base = lbl_8033AF80;
    void *object;
    object = fn_801284F8(0x1A0, (void *)OBS_TAG_OBSTACLE);
    if (object != 0) {
        fn_801F92AC((F92Obj *)object);                 /* what every created object starts with */
        ((Obstacle *)object)->vtable = lbl_8033B440;   /* ... drawn and updated as an obstacle */
        ((void (*)(void *))fn_801F92A8)(&((Obstacle *)object)->obst);
        ((Obstacle *)object)->options = 0;
        {
            Obstacle *sub = (Obstacle *)object;
            sub->obst = 0;                             /* the "OBST" fourcc, which fn_801F8988 rewrites */
            fn_801F8988(&sub->obst, node);             /* the obstacle settings held in the node */
        }
        if (fn_801F88F4(node) == 0) ((Obstacle *)object)->options |= OBS_OPT_NOT_FLOATER;
        if (((Node *)node)->getFlag(OBS_KEY_FACING_TEST, 0)) ((Obstacle *)object)->options |= OBS_OPT_FACING_TEST;
        if (((Node *)node)->getFlag(OBS_KEY_REFLECT_LOAD, 0)) ((Obstacle *)object)->options |= OBS_OPT_REFLECT_LOAD;
        if (((Node *)node)->getFlag(OBS_KEY_FACING_X_TEST, 0)) ((Obstacle *)object)->options |= OBS_OPT_FACING_X;
        if (((Node *)node)->getFlag(OBS_KEY_FABRIC, 0)) {
            ((Obstacle *)object)->options |= OBS_OPT_FABRIC;
            ((Obstacle *)object)->effect = ((Node *)node)->getString(OBS_KEY_EFFECT);
        } else {
            ((Obstacle *)object)->effect = OBS_NO_EFFECT;
        }
        if (((Node *)node)->getFlag(OBS_KEY_DRAW_LAST, 0)) ((Obstacle *)object)->options |= OBS_OPT_DRAW_LAST;
        if (((Node *)node)->getFlag(OBS_KEY_ONESIDED, 0)) ((Obstacle *)object)->options |= OBS_OPT_ONESIDED;
        ((Obstacle *)object)->sobjEvent = ((Node *)node)->getInt(OBS_KEY_SOBJ_EVENT, -1);
        ((Obstacle *)object)->defaultProps = ((Node *)node)->getNode(OBS_KEY_DEFAULT_PROPS);
    }
    return object;
}

extern u32 lbl_802F9B30[];
extern "C" u32 lbl_802F9BA0[8];
extern u8 lbl_8055B2CC[];
__declspec(section ".sdata") extern u8 lbl_8055B2CC[];
extern "C" int fn_801F88F4(void *arg0) {
    class F88Node {
    public:
        virtual void v0();
        virtual void v4();
        virtual void v8();
        virtual char *v14(const char *, u32, u32);
    };
    u32 table[3];
    u32 *source = lbl_802F9B30;
    table[0] = *source++;
    table[1] = *source++;
    table[2] = *source;
    char *name = ((F88Node *)arg0)->v14((const char *)lbl_8055B2CC, table[1], table[0]);
    u32 *entry = table;
    while (*entry != 0) {
        if (stricmp((const char *)*entry, name) == 0) return 1;
        entry++;
    }
    return 0;
}

extern "C" void fn_801F92A8(void) {

}

#pragma scheduling invalid_target
extern "C" void *fn_801F92AC(F92Obj *obj) {
    f32 b = lbl_80563000;
    f32 a = lbl_80562FF0;
    obj->w108 = lbl_8033B468;
    obj->w78 = 0;
    obj->f7c = a;
    obj->f80 = a;
    obj->w104 = 0;
    obj->f24 = 0;
    obj->f20 = 0;
    obj->f28 = b;
    obj->b60 = 1;
    memset(obj, 0x61, 0x20);
    memset((char *)obj + 0x61, 0x61, 0x10);
    obj->w74 = -1;
    return obj;
}
#pragma scheduling on
extern "C" s32 fn_801F7EB0(void *out, void *self, s32 arg);
extern "C" int strcmp(const char *, const char *);
#pragma use_lmw_stmw off
extern "C" void *fn_801F9338(void *self) {
    /* Collect child nodes named "object" and build a linked list of placed instances. */
    class Node {
    public:
        virtual const char *name();
    };
    class List {
    public:
        virtual void *s4();
        virtual void *s8();
        virtual void *sC();
        virtual void *s10();
        virtual void *s14();
        virtual void *s18();
        virtual void *s1C();
        virtual void *s20();
        virtual void *s24();
        virtual void *s28();
        virtual void *s2C();
        virtual void *s30();
        virtual void *s34();
        virtual void *s38();
        virtual void *s3C();
        virtual void *s40();
        virtual void *s44();
        virtual void *s48();
        virtual void *s4C();
        virtual void *s50();
        virtual void *s54();
        virtual void *s58();
        virtual void *get(s32);
    };

    u8 frameData[0x30];
    void *transform;
    void *head;
    void *child;
    s32 index;

    transform = 0;
    if (fn_801F7EB0(frameData, self, 0) != 0) {
        transform = frameData;
    }
    head = 0;
    index = 0;
    goto get_node;

body:
    if (strcmp(((Node *)child)->name(), (const char *)&lbl_8055B36C) == 0) {
        void *placed = fn_801F8188(child, (s32)transform, 0);
        *(void **)((u8 *)placed + 0x24) = head;
        head = placed;
    }
    index++;

get_node:
    child = ((List *)self)->get(index);
    if (child != 0) {
        goto body;
    }

    return head;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_801F93FC(void *node) {
    void *n = fn_801F8188(node, 0, 1);
    fn_801F9440((F92Node **)&lbl_8055EC38, (F92Node *)n);
    return n;
}
#pragma scheduling on
#pragma pop
extern "C" void fn_801F9440(F92Node **list, F92Node *node) {
    node->next = *list;
    *list = node;
}

__declspec(section ".sdata") extern u8 lbl_8055B374[];
extern "C" s32 fn_801F9450(void *node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)lbl_8055B374) == 0;
}

extern "C" s32 fn_801F948C(void *node) {
    struct V { virtual const char *get(); };
    return stricmp(((V *)node)->get(), (const char *)lbl_8033B1EC) == 0;
}

extern u8 lbl_8033B200[];
void *fn_80131810(char *);
void fn_80131818(void);
int vsprintf(char *, const char *, va_list);
extern int vsprintf(char *, const char *, va_list);
extern void *fn_801284F8(u32, void *);
extern void *fn_80131810(char *);
extern void fn_80131818(void);
extern "C" void fn_801F94CC(const char *format, ...) {
    char buffer[0x100];
    void *node;
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    node = fn_801284F8(8, lbl_8033B200);
    if (node != 0) {
        *(void * volatile *)node = fn_80131810((void *)buffer);
    }
    if (node != 0 && *(void * volatile *)node != 0) {
        *(void **)((u8 *)node + 4) = lbl_8055EC44;
        lbl_8055EC44 = node;
    } else if (node != 0) {
        fn_80131818(*(void * volatile *)node);
        *(void * volatile *)node = 0;
        ((void (*)(void *))fn_80128668)(node);
    }
}

__declspec(section ".sdata") extern u8 lbl_8055B2DC[];
extern "C" void *fn_801F95C4(void *arg0, void *arg1) {
    /* Search the linked list of owners in lbl_8055EC44 for a node accepted by
       the predicate arg0 whose name (looked up with key "name" / lbl_8055B2DC)
       matches arg1. Walks each owner's get(index) sequence; aborts with
       "Can't find \"%s\"" if not found. */
    class Owner {
    public:
        virtual void f0();
        virtual void *get(s32 index);
    };
    class Node {
    public:
        virtual void f0();
        virtual void f4();
        virtual void f8();
        virtual const char *name(const char *key);
    };
    void *node = 0;
    void *list = *(void * volatile *)&lbl_8055EC44;
    s32 index = 0;
    goto outer_check;
next_list:
    index = 0;
    goto get_next;
check_node:
    if (((s32 (*)(void *))arg0)(node) == 0) goto increment;
    if (stricmp(((Node *)node)->name((const char *)lbl_8055B2DC),
                (const char *)arg1) == 0) goto list_advance;
increment:
    index++;
get_next:
    node = ((Owner *)*(void **)list)->get(index);
    if (node != 0) goto check_node;
list_advance:
    list = *(void **)((char *)list + 4);
outer_check:
    if (node != 0) goto done;
    if (list != 0) goto next_list;
done:
    if (node == 0) fn_802E317C((const char *)lbl_8033B210, (const char *)arg1);
    return node;
}

extern "C" void fn_801F96A8(void *node) {
    fn_801F95C4((void *)fn_801F9450, node);
}

extern "C" void fn_801F96B8(void *node) {
    fn_801F95C4((void *)fn_801F948C, node);
}

#pragma dont_inline on
extern "C" void *fn_801F96C8(void *node) {
    void *list = lbl_8055EC38;
    while (list != NULL) {
        if (stricmp((char *)node, (char *)list) == 0) {
            break;
        }
        list = *(void **)((char *)list + 0x20);
    }
    if (list == NULL) {
        fn_801F96A8(node);
        list = ((void *(*)(void))fn_801F93FC)();
    }
    return list;
}
#pragma dont_inline reset
extern "C" void fn_801BFD34(void *, void *, void *);
extern "C" void fn_80015B20(void *, void *, void *);
extern "C" void fn_80204018(void *, void *);
extern "C" u8 lbl_8055EC7C;
extern "C" void fn_801F973C(void *arg0, void *arg1, u32 arg2) {
    u8 scratch[0x38];
    u32 state;
    u32 flags;
    register s32 zero;
    void *node;

    if (arg2 & 2) {
        state = *(volatile u8 *)&lbl_8055EC7C;
        flags = *(volatile s32 *)((u8 *)arg0 + 0x24);
        state = (state == 0);
        *(volatile u8 *)&lbl_8055EC7C = state;
        flags = flags != 0;
        if (state != 0) {
            flags |= 2;
            node = arg0;
            zero = 0;
            goto next_node;
        loop_body:
            *(s32 *)(scratch + 0x34) = zero;
            *(s32 *)(scratch + 0x30) = zero;
            fn_801BFD34(scratch + 0x24, (u8 *)node + 0x54, arg1);
            fn_80015B20(scratch, (u8 *)node + 0x30, arg1);
            s32 value = *(s32 *)((u8 *)arg1 + 0x34);
            *(s32 *)(scratch + 0x30) = flags;
            *(s32 *)(scratch + 0x34) = value;
            ((void (**)(void *, void *))*(void **)((u8 *)node + 0x108))[4](node, scratch);
        next_node:
            node = *(void **)((u8 *)node + 0x24);
            if (node != 0) goto loop_body;
        }
    }
    if (arg2 & 1) fn_80204018(arg0, arg1);
}

extern "C" void *fn_801F981C(void *object, s32 flags) {
    struct Lookup {
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void *find(const char *);
    };
    struct Dispatch {
        u8 padding[0x108];
        virtual void a();
        virtual void run(void *, void *);
    };
    extern void fn_802E30C8(const char *, ...);
    extern s32 fn_80204CF0(void);
    extern int strcmp(const char *, const char *);
    extern u8 lbl_8055EC42;
    register char *base = lbl_8033AF80;
    char *name = (char *)((Lookup *)object)->find((const char *)lbl_8055B374);
    void *current = fn_801F96C8(name);
    u8 result[0x40];

    *(s32 *)(result + 0x34) = 0;
    *(s32 *)(result + 0x30) = 0;
    ((Dispatch *)current)->run(result, object);

    if (*(u8 *)((u8 *)current + 0x2C) != 0 && (flags & 4) == 0) {
        fn_802E317C(base + 0x2A0, current);
        if (*(s32 *)(result + 0x38) != fn_80204CF0()) {
            fn_802E30C8(base + 0x2E0, name);
            goto call_tail;
        }
    }
    if (lbl_8055EC42 != 0) {
        if (strcmp(name, (const char *)lbl_8055B37C) == 0) {
            fn_802E30C8(base + 0x318, name);
            goto call_tail;
        }
        goto call_tail;
    }
call_tail:
    return ((void *(*)(void *, void *, u32))fn_801F973C)(
        current, result, (u32)flags);
}

#pragma dont_inline on
extern "C" void fn_801F9928(void *list, s32 arg) {
    class Node {
    public:
        virtual const char *name();
    };
    class List {
    public:
        virtual void *s4();
        virtual void *s8();
        virtual void *sC();
        virtual void *s10();
        virtual void *s14();
        virtual void *s18();
        virtual void *s1C();
        virtual void *s20();
        virtual void *s24();
        virtual void *s28();
        virtual void *s2C();
        virtual void *s30();
        virtual void *s34();
        virtual void *s38();
        virtual void *s3C();
        virtual void *s40();
        virtual void *s44();
        virtual void *s48();
        virtual void *s4C();
        virtual void *s50();
        virtual void *s54();
        virtual void *s58();
        virtual void *get(s32);
    };
    void *cur;
    char *name;
    s32 i = 0;
    goto get_cur;
body:
    name = (char *)((Node *)cur)->name();
    if (stricmp(name, (const char *)&lbl_8055B36C) == 0) {
        fn_801F981C(cur, arg);
    }
    i++;
get_cur:
    cur = ((List *)list)->get(i);
    if (cur != 0) {
        goto body;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801F99CC(F92Obj *obj) {
    F92Obj *cur = (F92Obj *)*(void **)((char *)obj + 0x24);
    F92Obj *next;
    while (cur != NULL) {
        next = (F92Obj *)*(void **)((char *)cur + 0x24);
        if (cur != NULL) {
            ((void (*)(F92Obj *, s32))(*(void **)((u8 *)*(void **)((char *)cur + 0x108) + 8)))(cur, 1);
        }
        cur = next;
    }
}
#pragma scheduling on
extern "C" void fn_801F9A24(F92Node **arg0) {
    F92Node *node = *arg0;
    F92Node *next;
    while (node != 0) {
        fn_801F99CC((F92Obj *)node);
        next = (F92Node *)*(void **)((char *)node + 0x20);
        if (node != 0) {
            ((void (*)(F92Obj *, s32))(*(void **)((u8 *)*(void **)((char *)node + 0x108) + 8)))((F92Obj *)node, 1);
        }
        node = next;
    }
    *arg0 = 0;
}

#pragma dont_inline on
extern "C" void fn_801F9AA4(void *arg0, s32 arg1) {
    F9Resource *obj = (F9Resource *)fn_80131810(arg0);
    if (obj != 0) {
        if (obj->s10(&lbl_8055B388) != 0) {
            fn_801F9928(obj->s8(&lbl_8055B388), arg1);
        }
        fn_80131818(obj);
    }
}
extern "C" int fn_801F9B28(void) {
    void *list;
    char *base = lbl_8033AF80;
    fn_8013A0B0(&list, base + 0x35C, &lbl_8055B388);
    if (list != 0) fn_801F9928(list, 3);
    fn_801F9AA4(base + 0x368, 3);
    F9Manager *obj = *(F9Manager **)((u8 *)fn_8000AC38() + 0x20);
    if (obj->s30(base + 0x378, 0) != 0)
        fn_801F9AA4(base + 0x38C, 3);
    fn_801F9AA4(base + 0x39C, 2);
    fn_8013A198(&list, -1);
}
#pragma dont_inline reset

// One node of the static-object ("StaticObject"/GOB) lists chained through
// `next`. Only the fields this unit reads are named; the rest is id, name and
// position data handled by the code that creates the nodes.
struct StaticGob {
    u8 pad[0x3C];
    s32 gobId;        // +0x3C GOB id to sort/search on (negative: not in the table)
    u8 flag40;        // +0x40
    u8 flag41;        // +0x41
    StaticGob *next;  // +0x44 next GOB in the list
};

extern "C" s32 fn_801F9BD0(s32 **arg0, s32 **arg1) {
    return (*arg0)[15] - (*arg1)[15];
}

#pragma scheduling invalid_target
extern "C" void fn_801F9BE8(void) {
    extern void *lbl_8055EC4C, *lbl_8055EC50;   // heads of the two GOB lists
    extern void **lbl_8055EC54;                 // the sorted GOB pointer table
    extern s32 lbl_8055EC58;                    // entries in that table
    extern char lbl_8033B32C[];                 // "StaticGOB tab": alloc name
    extern void *fn_8012850C(u32, void *);
    extern int qsort(void *, u32, u32, int (*)(const void *, const void *));
    extern int fn_801F9BD0(const void *, const void *);
    s32 index;
    lbl_8055EC58 = 0;
    {
        StaticGob *node = (StaticGob *)lbl_8055EC4C;
        while (node != 0) {
            if (node->gobId >= 0)
                ++lbl_8055EC58;
            node = node->next;
        }
    }
    {
        StaticGob *node = (StaticGob *)lbl_8055EC50;
        while (node != 0) {
            if (node->gobId >= 0)
                ++lbl_8055EC58;
            node = node->next;
        }
    }
    if (lbl_8055EC58 >= 1) {
        lbl_8055EC54 = (void **)fn_8012850C(lbl_8055EC58 * 4, lbl_8033B32C);
        index = 0;
        {
            StaticGob *node = (StaticGob *)lbl_8055EC4C;
            while (node != 0) {
                if (node->gobId >= 0)
                    ((StaticGob **)lbl_8055EC54)[index++] = node;
                node = node->next;
            }
        }
        {
            StaticGob *node = (StaticGob *)lbl_8055EC50;
            while (node != 0) {
                if (node->gobId >= 0)
                    ((StaticGob **)lbl_8055EC54)[index++] = node;
                node = node->next;
            }
        }
        qsort(lbl_8055EC54, lbl_8055EC58, 4, fn_801F9BD0);
    }
}
#pragma scheduling on

extern "C" s32 fn_801F9CF8(void *arg0) {
    if (lbl_8055EC54 != 0) {
        s32 low = 0;
        s32 high = lbl_8055EC58 - 1;
        while (low <= high) {
            s32 mid = (low + high) / 2;
            void *node = lbl_8055EC54[mid];
            if (*(s32 *)arg0 > *(s32 *)((u8 *)node + 0x3C)) low = mid + 1;
            else if (*(s32 *)arg0 < *(s32 *)((u8 *)node + 0x3C)) high = mid - 1;
            else {
                *((u8 *)node + 0x40) = *((u8 *)arg0 + 4);
                return 8;
            }
        }
    }
    return 8;
}

extern "C" void *fn_80016544(s32);
extern "C" s32 fn_801F9D70(void *arg0) {
    char *item;
    s32 ret = 0;
    char *base = (char *)arg0 + 0x20;
    s32 i;

    item = base;
    for (i = 0; i < *(s32 *)(base + 0x3c0); item += 0x78, i++) {
        if (*(s32 *)item == 0x50) {
            ret = 1;
            if (!(*(u32 *)((char *)fn_80016544(*(s32 *)(item + 0x6c)) + 0xa0) & 4)) {
                return 0;
            }
        }
    }
    return ret;
}

extern "C" void fn_801EEFDC(void *, s32);
extern "C" void fn_8020401C(void);
__declspec(section ".sdata") extern const char lbl_8055B390[];
extern "C" void fn_801F9E04(void *context) {
    /* Initializes global subsystem state, logs setup strings, allocates a small handle slot, and registers callbacks. */
    extern s32 lbl_8055EC64;
    extern void *lbl_8055EC68;
    extern void *lbl_8055EC50;
    extern u8 lbl_8055EC42;
    register u32 zero = 0;
    s32 stringsBase = (s32)lbl_8033AF80;
    void *allocated;

    lbl_8055EC38 = (void *)zero;
    fn_801F94CC((const char *)(stringsBase + 0x3BC));
    fn_801F94CC((const char *)(stringsBase + 0x3D4), context);
    fn_801F94CC((const char *)(stringsBase + 0x39C));
    fn_801F94CC((const char *)(stringsBase + 0x3E8));

    lbl_8055EC4C = (void *)zero;
    lbl_8055EC3C = 1;
    lbl_8055EC50 = (void *)zero;
    lbl_8055EC54 = (void **)zero;
    lbl_8055EC58 = zero;
    lbl_8055EC42 = (u8)fn_801F9D70(context);
    lbl_8055B1C8 = -0x4E20;

    allocated = fn_801284F8(4, (void *)(stringsBase + 0x3F8));
    if (allocated != 0)
        *(s32 *)allocated = zero;
    lbl_8055EC74 = (void **)allocated;
    lbl_8055EC78 = 0x2710;
    lbl_8055EC64 = zero;
    lbl_8055EC68 = ((void *(*)(void *))fn_801F96B8)((void *)lbl_8055B390);
    lbl_8055EC70 = (s32)(u32)((void *(*)(void *))fn_801F96B8)((void *)lbl_8055B2C4);
    ((void (*)(void *))fn_8020401C)(context);
    fn_801EEFDC((void *)fn_801F9CF8, 0xC);
}

extern void fn_801EF024(void *);
extern void fn_80204020(void);
extern void fn_80128668(void);
extern void fn_80128670(void *);
extern "C" void fn_801F9F08(void) {
    fn_801EF024((void *)fn_801F9CF8);
    fn_80204020();
    lbl_8055EC70 = 0;
    if (lbl_8055EC74 != 0) {
        *lbl_8055EC74 = 0;
        fn_80128668();
    }
    lbl_8055EC74 = 0;
    if (lbl_8055EC54 != 0) {
        fn_80128670((void *)lbl_8055EC54);
    }
    clear__Q211J2DBloSaver19CTextureNameConnectFv((void **)&lbl_8055EC4C);
    clear__Q211J2DBloSaver19CTextureNameConnectFv((void **)&lbl_8055EC50);
    fn_801FA010((void **)&lbl_8055EC5C);
    fn_801FA010((void **)&lbl_8055EC60);
    fn_801F9A24((F92Node **)&lbl_8055EC38);
    fn_801FA0B0((void **)&lbl_8055EC44);
    fn_801FA138((void **)&lbl_8055EC6C);
}

extern "C" void fn_802C6CF8(s32);
void fn_801EF024(void *);
void fn_80204020(void);
void fn_80128668(void);
void fn_80128670(void);
extern "C" void fn_801FA010(void **);
void fn_801F9A24(void *);
extern "C" void fn_801FA0B0(void **);
void fn_801FA138(void *);
extern "C" void clear__Q211J2DBloSaver19CTextureNameConnectFv(void **);
void fn_80128668(void);
extern "C" void fn_801E6CD0(void *, s32, f32);
extern "C" void fn_801E6CC4(void *);
extern "C" void fn_801E6B98(void *);
void fn_801EF024(void *);
void fn_80204020(void);
void fn_80128670(void);
void fn_801F9A24(void *);
void fn_801FA138(void *);
extern "C" void clear__Q211J2DBloSaver19CTextureNameConnectFv(void **arg0) {
    void *node;
    void *next;
    node = *arg0;
    while (node != 0) {
        next = *(void **)((char *)node + 0x44);
        if (node != 0) {
            fn_802C6CF8(*(s32 *)node);
            ((void (*)(void *))fn_80128668)(node);
        }
        node = next;
    }
    *arg0 = 0;
}

extern "C" void fn_801FA010(void **arg0) {
    int i;
    void *p;
    void *node;
    void *next;

    node = *arg0;
    while (node != 0) {
        next = *(void **)((char *)node + 0x68);
        if (node != 0) {
            fn_801E6CD0(*(void **)((char *)node + 0x30), 0, lbl_80562FF0);
            p = node;
            for (i = 0; i < *(s32 *)((char *)node + 0x54); i++) {
                fn_801E6CC4(*(void **)((char *)p + 0x34));
                p = (char *)p + 4;
            }
            fn_801E6B98(*(void **)((char *)node + 0x30));
            ((void (*)(void *))fn_80128668)(node);
        }
        node = next;
    }
    *arg0 = 0;
}

extern "C" void fn_801FA0B0(void **arg0) {
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 4);
        if (node != 0) {
            void *value = *(void **)node;
            if (value != 0) fn_80131818(value);
            *(s32 *)node = 0;
            ((void (*)(void *))fn_80128668)(node);
        }
        node = next;
    }
    *arg0 = 0;
}

extern "C" void fn_801FA138(void **arg0) {
    struct Item {
        virtual void next(s32);
    };
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((u8 *)node + 0x14);
        if (node != 0) {
            void *obj = *(void **)((u8 *)node + 0x10);
            if (obj != 0 && obj != 0) {
                ((Item *)obj)->next(1);
            }
            *(void **)((u8 *)node + 0x10) = 0;
            ((void (*)(void *))fn_80128668)(node);
        }
        node = next;
    }
    *arg0 = 0;
}

extern void* lbl_8055EC4C;
extern void* lbl_8055EC50;
extern void* lbl_8055EC5C;
extern s32 fn_80129D90(s32, s32);
extern s32 fn_801E6CD0(s32, s32, f32);
s32 fn_80129D90(s32, s32, s32);
/* Marks flag/list nodes as active and starts playback for each active animation
 * group node in the third list (random choice when multiple clips, or clip 0). */
extern "C" void fn_801FA1D4(void) {
    unsigned char *node;
    void *groupNode;
    s32 clipIndex;
    s32 clipCount;
    node = (unsigned char *)lbl_8055EC4C;
    while (node != 0) {
        node[0x40] = 1;
        node = *(unsigned char **)(node + 0x44);
    }
    node = (unsigned char *)lbl_8055EC50;
    while (node != 0) {
        node[0x40] = 1;
        node = *(unsigned char **)(node + 0x44);
    }
    groupNode = lbl_8055EC5C;
    while (groupNode != 0) {
        clipCount = *(s32 *)((char *)groupNode + 0x54);
        if (clipCount > 0) {
            if (*(s32 *)((char *)groupNode + 0x60) != 1) {
                clipIndex = fn_80129D90(0, 0, clipCount);
                fn_801E6CD0(*(s32 *)((char *)groupNode + 0x30),
                            *(s32 *)((char *)groupNode + 0x34 + clipIndex * 4),
                            lbl_80562FF0);
            } else {
                fn_801E6CD0(*(s32 *)((char *)groupNode + 0x30), 0, lbl_80562FF0);
            }
        }
        groupNode = *(void **)((char *)groupNode + 0x68);
    }
}

extern "C" int fn_8020402C(void);
extern "C" int fn_801F9B28();
extern "C" void fn_801FA298(void) {
    if (fn_8020402C() == 0) {
        fn_801F9B28();
    }
}

#pragma push
#pragma always_inline on
inline void fn_801FA2C4_setAnim(u8 *p, s32 mode) {
    typedef s32 (*Fn3)(s32, s32, s32);
    if (mode == 1)
        fn_801E6CD0(*(void **)(p + 0x30), 0, lbl_80562FF0);
    else
        fn_801E6CD0(*(void **)(p + 0x30), *(s32 *)(p + ((Fn3)fn_80129D90)(0, 0, *(s32 *)(p + 0x54)) * 4 + 0x34), lbl_80562FF0);
}
extern "C" f32 fn_801E7E24(void);
extern "C" u8 *fn_801E8718(s32);
extern "C" f32 PSVECSquareDistance(const void *, const void *);
extern "C" void fn_801E6E9C(void *, f32);
extern "C" s32 fn_801E7650(void *);
extern "C" s32 fn_801E7698(void);
extern "C" void fn_80203FF8(void);
#pragma push
#pragma processor 750
extern "C" void fn_801FA2C4(void) {
    f32 dt = fn_801E7E24();
    u8 *p = (u8 *)lbl_8055EC5C;
    for (; p != 0; p = *(u8 **)(p + 0x68)) {
        s32 close = PSVECSquareDistance(fn_801E8718(0) + 0x24, p + 0x24) < *(f32 *)(p + 0x5c);
        s32 state = *(s32 *)(p + 0x60);
        if (state != 2) {
            s32 flag = 0;
            s32 near = 0;
            if (p[0x59] != 0 && close)
                near = 1;
            if (near != 0 && p[0x58] == (&lbl_8055EC40)[1])
                flag = 1;
            switch (state) {
            case 0:
                if (flag == 0) {
                    lbl_8055EC64 = lbl_8055EC64 - 1;
                    *(s32 *)(p + 0x60) = 1;
                    fn_801FA2C4_setAnim(p, 1);
                }
                break;
            case 1:
                if (flag != 0 && lbl_8055EC64 < fn_801E7698()) {
                    lbl_8055EC64 = lbl_8055EC64 + 1;
                    *(s32 *)(p + 0x60) = 0;
                    fn_801FA2C4_setAnim(p, 0);
                }
                break;
            }
        }
        fn_801E6E9C(*(void **)(p + 0x30), dt);
        if (*(s32 *)(p + 0x54) > 1 && fn_801E7650(*(void **)(p + 0x30)) != 0)
            fn_801FA2C4_setAnim(p, *(s32 *)(p + 0x60));
    }
    u8 *q = *(u8 **)&lbl_8055EC6C;
    for (; q != 0; q = *(u8 **)(q + 0x14)) {
        u8 *r = *(u8 **)(q + 0x10);
        if (r != 0) {
            if (q[0xc] == (&lbl_8055EC40)[1]) {
                r[0x4a] = 0;
                r[0x4b] = 1;
                r[0x49] = 1;
            } else {
                r[0x4a] = 1;
                r[0x4c] = 0;
            }
        }
    }
    fn_80203FF8();
}
#pragma pop
#pragma pop
extern "C" void fn_801E75C8(s32, void *);
extern "C" u32 fn_801F7A0C(void);
extern "C" void fn_802C70AC(s32, void *, s32, s32);
extern "C" void *lbl_8055EC50;
extern "C" void *lbl_8055EC5C;
extern "C" u8 lbl_8055EC40;
#pragma scheduling invalid_target
extern "C" void fn_801FA550(void) {
    /* Iterates two global lists: for each active node in the first list triggers fn_802C70AC when enabled, and for each node in the second list matching lbl_8055EC40's second byte calls fn_801E75C8. */
    void *node;
    void *otherNode;
    node = lbl_8055EC50;
    while (node != 0) {
        if (*((u8 *)node + 0x41) == 0 &&
            *((u8 *)node + 0x40) != 0 &&
            fn_801F7A0C() != 0) {
            fn_802C70AC(*(s32 *)node, *(void **)((u8 *)node + 0x34) ? *(void **)((u8 *)node + 0x34) : (u8 *)node + 4, -1, -0xF);
        }
        node = *(void **)((u8 *)node + 0x44);
    }
    otherNode = lbl_8055EC5C;
    while (otherNode != 0) {
        if (fn_801F7A0C() != 0 &&
            *(u8 *)((u8 *)otherNode + 0x58) == *((u8 *)&lbl_8055EC40 + 1)) {
            fn_801E75C8(*(s32 *)((u8 *)otherNode + 0x30), otherNode);
        }
        otherNode = *(void **)((u8 *)otherNode + 0x68);
    }
}

extern "C" void fn_801FA618(void) {
    u32 flags = *(u32 *)((u8 *)fn_801E87A8() + 0x10);
    s32 mode = 2;
    if (flags & 2) mode = 1;
    s32 old = fn_802C9C58(mode);
    fn_802C7A44();
    void *node = (void *)lbl_8055EC48;
    while (node != 0) {
        if (*(u8 *)((u8 *)node + 0x50) != 0 && fn_801F7A0C() != 0) {
            fn_802C70AC(*(s32 *)((u8 *)node + 0x3C), (u8 *)node + 4, -1, -0xF);
        }
        node = *(void **)((u8 *)node + 0x54);
    }
    fn_802C7A50();
    fn_802C7AD4();
    fn_802C9C58(old);
}

#pragma scheduling on
extern "C" void fn_801FA6B8(void) {
    void *node = lbl_8055EC4C;
    while (node != 0) {
        if (*((u8 *)node + 0x41) == 0 && *((u8 *)node + 0x40) != 0 && fn_801F7A0C() != 0) {
            fn_802C70AC(*(s32 *)node, *(void **)((u8 *)node + 0x34) ? *(void **)((u8 *)node + 0x34) : (u8 *)node + 4, -1, -0xF);
        }
        node = *(void **)((u8 *)node + 0x44);
    }
}
#pragma dont_inline reset

extern "C" void fn_801FA738(void) {
    // Selects mode from game flags, then iterates lbl_8055EC4C nodes (flag +0x41 set, +0x40 set) to trigger fn_802C70AC while audio/state is prepared.
    u32 flags = *(u32 *)((u8 *)fn_801E87A8() + 0x10);
    s32 mode = 2;
    if (flags & 2) mode = 1;
    s32 old = fn_802C9C58(mode);
    fn_802C7A44();
    void *node = lbl_8055EC4C;
    while (node != 0) {
        if (*((u8 *)node + 0x41) != 0 && *((u8 *)node + 0x40) != 0 && fn_801F7A0C() != 0) {
            fn_802C70AC(*(s32 *)node, *(void **)((u8 *)node + 0x34) ? *(void **)((u8 *)node + 0x34) : (u8 *)node + 4, -1, -0xF);
        }
        node = *(void **)((u8 *)node + 0x44);
    }
    fn_802C7A50();
    fn_802C7AD4();
    fn_802C9C58(old);
}

extern "C" void *fn_801F96C8(void *);
extern "C" void fn_801F973C(void *, void *, u32);
#pragma dont_inline on
#pragma use_lmw_stmw on
extern "C" void fn_801FA7F4(void *arg0, u32 *arg1, s32 arg2) {
    volatile u32 *src = (volatile u32 *)arg1;
    s32 t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    s32 zero = 0;
    f32 data[14];
    t0 = src[0];
    ((u32 *)data)[13] = zero;
    t1 = src[1];
    t2 = src[2];
    t3 = src[3];
    t4 = src[4];
    t5 = src[5];
    t6 = src[6];
    t7 = src[7];
    t8 = src[8];
    t9 = src[9];
    t10 = src[10];
    t11 = src[11];
    ((u32 *)data)[12] = zero;
    *(u32 *)&data[0] = t0;
    *(u32 *)&data[1] = t1;
    *(u32 *)&data[2] = t2;
    *(u32 *)&data[3] = t3;
    *(u32 *)&data[4] = t4;
    *(u32 *)&data[5] = t5;
    *(u32 *)&data[6] = t6;
    *(u32 *)&data[7] = t7;
    *(u32 *)&data[8] = t8;
    *(u32 *)&data[9] = t9;
    *(u32 *)&data[10] = t10;
    *(u32 *)&data[11] = t11;
    *(s32 *)&data[13] = arg2;
    {
        void *obj = fn_801F96C8(arg0);
        f32 scale = *(f32 *)((u8 *)obj + 0x28);
        data[9] += data[3] * scale;
        data[10] += data[4] * scale;
        data[11] += data[5] * scale;
        fn_801F973C(obj, data, 2);
    }
}
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_801FA8E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 id = lbl_8055EC78++;
    void **list;
    void *context;
    context = fn_8013184C();
    list = lbl_8055EC74;
    void *node = fn_801284F8(0x4C, lbl_8033B5B8);
    if (node != 0) node = fn_801A4A8C(node, id, arg2, arg0, arg1, context);
    *(void **)((u8 *)node + 0x44) = *list;
    *list = node;
    return (u8 *)node + 4;
}
#pragma pop
extern void **lbl_8055EC74;
extern s32 lbl_8055EC78;
extern u8 lbl_8055EC3C;
extern void *lbl_8055EC4C;
extern u8 lbl_8033B5B8[];
void fn_801F9BE8(void);
void fn_801B5D30(void *);
void fn_801792F4(void);
void *fn_8013184C(void);
void *fn_801284F8(u32, void *);
void *fn_801A4A8C(void *, s32, s32, s32, s32, void *);
void *fn_801E87A8(void);
s32 fn_802C9C58(s32);
void fn_802C7A44(void);
void fn_802C7A50(void);
void fn_802C7AD4(void);
extern "C" void fn_801FA978(void) {
    fn_801F9BE8();
    fn_801B5D30(lbl_8055EC74);
    fn_801792F4();
    lbl_8055EC3C = 0;
}

extern "C" void *fn_801A4548(void *);
extern "C" void fn_801EA1E0(void *, s32, f32, f32);
extern "C" void fn_80204050(void);
extern "C" u8 lbl_8033B384[];
extern "C" void fn_801FA9AC(void) {
    void *data = fn_801A4548(lbl_8033B384);
    s32 i, j;
    if (data != 0) {
        for (i = 0; i < lbl_8055EC58; i++) {
            s32 count = *(s32 *)data;
            void *obj = lbl_8055EC54[i];
            for (j = 0; j < count; j++) {
                void *entry = *(void **)((u8 *)*(void **)((u8 *)data + 4) + j * 4);
                if (*(s32 *)((u8 *)entry + 0x38) == *(s32 *)((u8 *)obj + 0x3C)) {
                    *(void **)((u8 *)obj + 0x34) = (u8 *)entry + 4;
                    break;
                }
            }
        }
        ((void (*)(void *))(*(void **)((u8 *)data + 0x14)))(data);
    }
    fn_80204050();
    for (void *node = lbl_8055EC4C; node != 0; node = *(void **)((u8 *)node + 0x44)) {
        if (*(s32 *)((u8 *)node + 0x34) == 0)
            fn_801EA1E0((u8 *)node + 0x2C, 0, *(f32 *)((u8 *)node + 0x28), *(f32 *)((u8 *)node + 0x30));
    }
    for (void *node = lbl_8055EC50; node != 0; node = *(void **)((u8 *)node + 0x44)) {
        if (*(s32 *)((u8 *)node + 0x34) == 0)
            fn_801EA1E0((u8 *)node + 0x2C, 0, *(f32 *)((u8 *)node + 0x28), *(f32 *)((u8 *)node + 0x30));
    }
}

extern "C" void fn_801FAAC4(char *dest, void *arg1) {
    const char *base = lbl_8033AF80;
    u32 idx;
    char *name;
    char **p;
    FAANames2 names = *(FAANames2 *)lbl_802F9B40;
    name = (char *)((FAAMgr *)arg1)->get((const char *)lbl_8055B2CC);
    p = (char **)names.w;
    idx = 0;
    while (stricmp(*p, name) != 0) {
        idx++;
        p++;
        if (idx == 0x18) {
            fn_802E317C(base + 0x190, name);
        }
    }
    *(s32 *)((u8 *)dest + 0x50) = idx;
    switch (idx) {
    case 0:
    case 14:
    case 17:
    case 19:
        *(f32 *)((u8 *)dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B328);
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 15:
        *(f32 *)((u8 *)dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B32C);
        *(f32 *)((u8 *)dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B330);
        *(f32 *)((u8 *)dest + 0x60) = ((FAAMgr *)arg1)->getF(lbl_8055B334);
        break;
    case 4:
        *(f32 *)((u8 *)dest + 0x58) = ((FAAMgr *)arg1)->getF(base + 0x1A8);
        *(f32 *)((u8 *)dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B338);
        *(f32 *)(dest + 0x60) = ((FAAMgr *)arg1)->getF(lbl_8055B340);
        break;
    case 8:
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B340);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B344);
        *(f32 *)(dest + 0x60) = ((FAAMgr *)arg1)->getF(lbl_8055B348);
        break;
    case 5:
    case 7:
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B328);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B340);
        break;
    case 9:
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(base + 0x1B4);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(base + 0x1C0);
        break;
    case 10:
    {
        const char *s = ((FAAMgr *)arg1)->getD(base + 0x1CC, lbl_8055B310);
        s32 n = 0x10;
        char *d = dest + 0x58;
        u8 c;
        goto body1;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body1:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        if (*(s8 *)(dest + 0x58) != 0) {
            return;
        }
        s = ((FAAMgr *)arg1)->getD(lbl_8055B2A8, lbl_8055B310);
        n = 0x10;
        d = dest + 0x58;
        goto body2;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body2:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        {
            char *dot = fn_80029004(dest + 0x58, 0x2E);
            if (dot == 0) {
                return;
            }
            *dot = 0;
        }
        d = dest + 0x58;
        n = 0x10;
        s = lbl_8055B34C;
        {
            volatile char *vd = d;
            do {
                n--;
                vd++;
            } while (*(s8 *)vd != 0);
            d = (char *)vd;
        }
        if (n <= 0) {
            return;
        }
        goto body3;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body3:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        break;
    }
    case 20:
    {
        const char *s = ((FAAMgr *)arg1)->getD(base + 0x1CC, lbl_8055B310);
        s32 n = 0x10;
        char *d = dest + 0x58;
        u8 c;
        goto body4;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body4:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        if (*(s8 *)(dest + 0x58) != 0) {
            return;
        }
        s = ((FAAMgr *)arg1)->getD(lbl_8055B2A8, lbl_8055B310);
        n = 0x10;
        d = dest + 0x58;
        goto body5;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body5:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        {
            char *dot = fn_80029004(dest + 0x58, 0x2E);
            if (dot == 0) {
                return;
            }
            *dot = 0;
        }
        d = dest + 0x58;
        n = 0x10;
        s = lbl_8055B354;
        {
            volatile char *vd = d;
            do {
                n--;
                vd++;
            } while (*(s8 *)vd != 0);
            d = (char *)vd;
        }
        if (n <= 0) {
            return;
        }
        goto body6;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body6:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        break;
    }
    case 11:
    {
        void *model = ((FAAMgr *)arg1)->get(lbl_8055B2A8);
        void *res = (void *)fn_802C6B44(model);
        memcpy(dest + 0x58, (u8 *)res + 0x2C, 0x1C);
        *(f32 *)(dest + 0x70) = ((FAAMgr *)arg1)->getFD(base + 0x1D8, lbl_80562FF0);
        ((void (*)(void *))fn_802C6C20)(res);
        break;
    }
    case 12:
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B328);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B340);
        break;
    case 13:
    case 18:
    case 22:
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B328);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B348);
        *(f32 *)(dest + 0x60) = lbl_8056300C * ((FAAMgr *)arg1)->getFD(base + 0x1EC, lbl_80562FF0);
        break;
    case 16:
    {
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B32C);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getF(lbl_8055B330);
        *(f32 *)(dest + 0x60) = ((FAAMgr *)arg1)->getF(lbl_8055B334);
        const FAAVec &v = ((FAAMgr *)arg1)->getV(base + 0x204);
        *(f32 *)(dest + 0x64) = v.x;
        *(f32 *)(dest + 0x68) = v.y;
        *(f32 *)(dest + 0x6C) = v.z;
        break;
    }
    case 21:
    {
        const char *s = (const char *)((FAAMgr *)arg1)->get(lbl_8055B2A8);
        s32 n = 0x10;
        char *d = dest + 0x6C;
        u8 c;
        goto body7;
        for (;;) {
            if (--n <= 0) { d[-1] = 0; break; }
        body7:
            c = *s++;
            *d++ = c;
            if ((s8)c == 0) break;
        }
        *(f32 *)(dest + 0x58) = ((FAAMgr *)arg1)->getF(lbl_8055B328);
        *(f32 *)(dest + 0x5C) = ((FAAMgr *)arg1)->getFD(lbl_8055B35C, *(f32 *)(dest + 0x58));
        const FAAVec &v = ((FAAMgr *)arg1)->getV(lbl_8055B364);
        *(f32 *)(dest + 0x60) = v.x;
        *(f32 *)(dest + 0x64) = v.y;
        *(f32 *)(dest + 0x68) = v.z;
        break;
    }
    default:
        return;
    }
}

extern "C" s32 fn_801FB1F4(s32 arg0) {
    return lbl_8055B1C8 -= arg0;
}

extern "C" s32 fn_801FB204(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801FB244(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801EA0E8(f32, f32, f32, f32, f32, f32);
extern "C" void fn_801F7D10(void *, void *, void *);
extern "C" void fn_801FB284(void *arg0, void *arg1) {
    f32 temp_f1, temp_f1_2, temp_f2, temp_f3, temp_f3_2, temp_f4, temp_f5, temp_f6, temp_f6_2;
    ((void (*)(void))fn_801F7D10)();
    if (*(u32 *)((u8 *)arg0 + 0x190) & 0x100) {
        temp_f3 = -*(f32 *)((u8 *)arg0 + 0x28);
        temp_f5 = *(f32 *)((u8 *)arg1 + 0x24);
        temp_f6 = *(f32 *)((u8 *)arg1 + 0x0C) * temp_f3;
        temp_f4 = *(f32 *)((u8 *)arg1 + 0x10) * temp_f3;
        temp_f3_2 = *(f32 *)((u8 *)arg1 + 0x28);
        temp_f2 = *(f32 *)((u8 *)arg1 + 0x2C) + (*(f32 *)((u8 *)arg1 + 0x14) * temp_f3);
        temp_f1 = temp_f5 + temp_f6;
        *(f32 *)((u8 *)arg1 + 0x2C) = temp_f2;
        *(f32 *)((u8 *)arg1 + 0x24) = temp_f1;
        *(f32 *)((u8 *)arg1 + 0x28) = temp_f3_2 + temp_f4;
        temp_f1_2 = fn_801EA0E8(temp_f1, temp_f2, temp_f3_2, temp_f4, temp_f5, temp_f6);
        *(f32 *)((u8 *)arg1 + 0x28) = temp_f1_2;
        temp_f6_2 = *(f32 *)((u8 *)arg0 + 0x28);
        *(f32 *)((u8 *)arg1 + 0x24) += *(f32 *)((u8 *)arg1 + 0x0C) * temp_f6_2;
        *(f32 *)((u8 *)arg1 + 0x28) = temp_f1_2 + *(f32 *)((u8 *)arg1 + 0x10) * temp_f6_2;
        *(f32 *)((u8 *)arg1 + 0x2C) += *(f32 *)((u8 *)arg1 + 0x14) * temp_f6_2;
    }
}

extern "C" void fn_801FB354(void *arg0, void *arg1) {
    s32 result;
    s32 flags;
    f32 cz;
    f32 cy;
    f32 cx;
    f32 z;
    f32 y;
    f32 x;
    f32 delta[3];
    void *camera;

    if (((u32 *)arg0)[100] & 1) {
        camera = fn_802C86DC();
        x = *(f32 *)((u8 *)arg1 + 0x24);
        y = *(f32 *)((u8 *)arg1 + 0x28);
        cx = *(f32 *)((u8 *)camera + 0x24);
        z = *(f32 *)((u8 *)arg1 + 0x2C);
        delta[0] = x - cx;
        cy = *(f32 *)((u8 *)camera + 0x28);
        delta[1] = y - cy;
        cz = *(f32 *)((u8 *)camera + 0x2C);
        delta[2] = z - cz;
        result = PSVECDotProduct(delta, (const f32 *)((u8 *)arg1 + 0x18)) < lbl_80562FF0;
        flags = (result ? 0x10 : 0x20) | 1;
    } else {
        flags = -0xF;
    }
    fn_802C70AC(*(s32 *)((u8 *)arg0 + 0x74), arg1, -1, flags);
}

extern "C" void fn_801FB40C(void *arg0, s32 arg1, void *arg2) {
    fn_80204014(arg1, *(s32 *)((u8 *)arg2 + 0x34), *(s32 *)((u8 *)arg0 + 0x19C), arg0);
}

extern "C" void fn_801FBCF4(void **arg0, void *arg1) {
    *(void **)((u8 *)arg1 + 0x44) = *arg0;
    *arg0 = arg1;
}

extern "C" s32 fn_801FBD04(void) {
    return -0xF;
}

extern "C" s32 fn_801FBD0C(void *arg0) {
    s32 result;
    s32 flags;
    f32 cz;
    f32 cy;
    f32 cx;
    f32 z;
    f32 y;
    f32 x;
    f32 delta[3];
    void *camera;

    camera = fn_802C86DC();
    x = *(f32 *)((u8 *)arg0 + 0x24);
    y = *(f32 *)((u8 *)arg0 + 0x28);
    cx = *(f32 *)((u8 *)camera + 0x24);
    z = *(f32 *)((u8 *)arg0 + 0x2C);
    delta[0] = x - cx;
    cy = *(f32 *)((u8 *)camera + 0x28);
    delta[1] = y - cy;
    cz = *(f32 *)((u8 *)camera + 0x2C);
    delta[2] = z - cz;
    result = PSVECDotProduct(delta, (const f32 *)((u8 *)arg0 + 0x18)) < lbl_80562FF0;
    flags = 0x20;
    if (result) flags = 0x10;
    return flags | 1;
}

extern "C" s32 fn_801FBD94(void *arg0) {
    s32 result;
    s32 flags;
    f32 cz;
    f32 cy;
    f32 cx;
    f32 z;
    f32 y;
    f32 x;
    f32 delta[3];
    void *camera;

    camera = fn_802C86DC();
    x = *(f32 *)((u8 *)arg0 + 0x24);
    y = *(f32 *)((u8 *)arg0 + 0x28);
    cx = *(f32 *)((u8 *)camera + 0x24);
    z = *(f32 *)((u8 *)arg0 + 0x2C);
    delta[0] = x - cx;
    cy = *(f32 *)((u8 *)camera + 0x28);
    delta[1] = y - cy;
    cz = *(f32 *)((u8 *)camera + 0x2C);
    delta[2] = z - cz;
    result = PSVECDotProduct(delta, (const f32 *)arg0) < lbl_80562FF0;
    flags = 0x20;
    if (result) flags = 0x10;
    return flags | 1;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_801FBE1C(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    void *obj = fn_801284F8(0x4C, lbl_8033B5B8);
    if (obj != 0) {
        obj = fn_801A4A8C(obj, arg1, arg2, arg3, arg4, arg5);
    }
    *(void **)((u8 *)obj + 0x44) = *arg0;
    *arg0 = obj;
    return (u8 *)obj + 4;
}
#pragma scheduling invalid_target
extern "C" void fn_801FBEA8(void *arg0) {
    void *obj = fn_801284F8(0x2C, lbl_8033B51C);
    if (obj != 0) {
        f32 zero, one, x, y;
        one = lbl_80563010;
        zero = lbl_80562FFC;
        *(volatile void **)obj = lbl_80333B98;
        x = *(f32 *)((char *)arg0 + 0x58);
        *(volatile s32 *)((char *)obj + 0xC) = 0;
        y = *(f32 *)((char *)arg0 + 0x5C);
        *(volatile s32 *)((char *)obj + 4) = 0;
        *(volatile s32 *)((char *)obj + 8) = 0;
        *(volatile s32 *)((char *)obj + 0x18) = 0x54554245;
        *(volatile f32 *)((char *)obj + 0x10) = one;
        *(volatile f32 *)((char *)obj + 0x14) = zero;
        *(volatile s32 *)((char *)obj + 0x20) = 100;
        *(volatile s32 *)((char *)obj + 0x1C) = 0;
        *(volatile f32 *)((char *)obj + 0x24) = x;
        *(volatile f32 *)((char *)obj + 0x28) = y;
        *(volatile void **)obj = lbl_80333918;
    }
}
#pragma scheduling on
extern "C" void fn_801FBF48(void *arg0) {
    void *obj = fn_801284F8(0x2C, lbl_8033B52C);
    if (obj != 0) {
        f32 zero, one, x, y;
        void *vt1 = lbl_80333B98;
        void *vt2 = lbl_803337C8;
        one = lbl_80563010;
        zero = lbl_80562FFC;
        *(volatile void **)obj = vt1;
        x = *(f32 *)((char *)arg0 + 0x58);
        *(volatile s32 *)((char *)obj + 0xC) = 0;
        y = *(f32 *)((char *)arg0 + 0x5C);
        *(volatile s32 *)((char *)obj + 4) = 0;
        *(volatile s32 *)((char *)obj + 8) = 0;
        *(volatile s32 *)((char *)obj + 0x18) = 0x52494E47;
        *(volatile f32 *)((char *)obj + 0x10) = one;
        *(volatile f32 *)((char *)obj + 0x14) = zero;
        *(volatile s32 *)((char *)obj + 0x20) = 100;
        *(volatile s32 *)((char *)obj + 0x1C) = 0;
        *(volatile void **)obj = vt2;
        *(volatile f32 *)((char *)obj + 0x24) = x;
        *(volatile f32 *)((char *)obj + 0x28) = y;
    }
}
extern "C" void fn_801FBFE8(void* arg0) {
    register f32 value = lbl_80563010;
    void* obj = fn_801284F8(0xE0, lbl_8033B53C);
    if (obj != 0) fn_801A324C(obj, 0, (char*)arg0 + 0x58, value, *(f32*)((char*)arg0 + 0x4C));
}
#pragma pop

extern u8 lbl_8033B54C[], lbl_80333B48[];
extern f32 lbl_80563014;
extern "C" void fn_8019EECC(void);
#pragma push
#pragma processor 750
extern "C" void fn_8019EECC(void);
#pragma scheduling invalid_target
extern "C" void fn_801FC048(void *arg0) {
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    register f32 temp_f31 = lbl_80563010;
    void *heap = lbl_8033B54C;
    void *obj = fn_801284F8(0x54, heap);
    if (obj != 0) {
        f32 value, zero;
        register f32 x;
        value = lbl_80563014;
        zero = lbl_80562FF0;
        *(volatile void **)obj = lbl_80333B98;
        *(volatile s32 *)((u8 *)obj + 0xC) = 0;
        *(volatile s32 *)((u8 *)obj + 4) = 0;
        *(volatile s32 *)((u8 *)obj + 8) = 0;
        x = *(f32 *)((u8 *)arg0 + 0x58);
        *(volatile s32 *)((u8 *)obj + 0x18) = 0x53504852;
        *(volatile f32 *)((u8 *)obj + 0x10) = temp_f31;
        *(volatile f32 *)((u8 *)obj + 0x14) = value;
        *(volatile s32 *)((u8 *)obj + 0x20) = 0x64;
        *(volatile s32 *)((u8 *)obj + 0x1C) = 0;
        *(volatile void **)obj = lbl_80333B48;
        *(volatile f32 *)((u8 *)obj + 0x24) = x;
        *(volatile f32 *)((u8 *)obj + 0x34) = zero;
        *(volatile f32 *)((u8 *)obj + 0x38) = zero;
        *(volatile f32 *)((u8 *)obj + 0x3C) = zero;
        *(volatile f32 *)((u8 *)obj + 0x40) = zero;
        *(volatile f32 *)((u8 *)obj + 0x44) = zero;
        *(volatile f32 *)((u8 *)obj + 0x48) = zero;
        *(volatile u8 *)((u8 *)obj + 0x4C) = 0;
        *(volatile f32 *)((u8 *)obj + 0x50) = zero;
        *(volatile f32 *)((u8 *)obj + 0x28) = zero;
        *(volatile f32 *)((u8 *)obj + 0x2C) = zero;
        sp8 = zero;
        spC = zero;
        sp10 = zero;
        *(volatile f32 *)((u8 *)obj + 0x30) = zero;
    } else {
        fn_8019EECC();
    }
}
extern f32 lbl_80563014, lbl_80563018;
extern u8 lbl_803338C0[], lbl_8033B55C[];
extern "C" f64 fn_8002F234(void);
extern u8 lbl_803338C0[], lbl_3B55C[], lbl_8033B55C[];
#pragma scheduling invalid_target
extern "C" void *fn_801FC12C(void *arg0) {
    f32 save = lbl_80563010;
    u8 *obj = (u8 *)fn_801284F8(0x38, lbl_8033B55C);
    if (obj != 0) {
        f32 half = lbl_80563018;
        f32 val14 = lbl_80563014;
        f32 x, y, z;
        f32 sum;
        *(void **)obj = lbl_80333B98;
        *(u32 *)(obj + 0xC) = 0;
        *(u32 *)(obj + 0x4) = 0;
        x = *(f32 *)((u8 *)arg0 + 0x58) * half;
        *(u32 *)(obj + 0x8) = 0;
        y = *(f32 *)((u8 *)arg0 + 0x5C) * half;
        *(u32 *)(obj + 0x18) = 0x424F5820;
        z = *(f32 *)((u8 *)arg0 + 0x60) * half;
        *(f32 *)(obj + 0x10) = save;
        *(f32 *)(obj + 0x14) = val14;
        *(u32 *)(obj + 0x20) = 100;
        *(u32 *)(obj + 0x1C) = 0;
        *(void **)obj = lbl_803338C0;
        *(f32 *)(obj + 0x24) = x;
        *(f32 *)(obj + 0x28) = y;
        *(f32 *)(obj + 0x2C) = z;
        *(u32 *)(obj + 0x34) = 0;
        sum = (z * z) + ((x * x) + (y * y));
        *(f32 *)(obj + 0x30) = lbl_80563014 + (f32)((f64 (*)(f32))fn_8002F234)(sum);
    }
    return obj;
}

#pragma pop
extern "C" void* fn_801FC228(void* arg0, s32 arg1) {
    if (arg0 == 0) goto done;
    *(volatile void**)((char*)arg0 + 0x108) = lbl_8033B418;
    if (arg1 <= 0) goto done;
    fn_80128668();
done:
    return arg0;
}

extern "C" void *fn_801E6A3C(s32, s32, s32);
extern "C" void *fn_801E6BEC(char *);
extern "C" void fn_801E6CC8(void *, s32);
extern "C" s32 fn_80129D90(s32, s32, s32);
extern "C" void fn_801FC4D8(void **, void *);
extern "C" __declspec(section ".sdata") const char lbl_8055B3A8[];
extern "C" __declspec(section ".sdata") const char lbl_8055B3B0[];
extern "C" const char lbl_8033B56C[];
extern "C" const f32 lbl_8056301C;
extern "C" void *lbl_8055EC68;
extern "C" void fn_801FC274(void *arg0, void *arg1) {
    struct ManagerAt24 {
        virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
        virtual void a4(); virtual void a5(); virtual void a6(); virtual void action(const char *);
    };
    struct ManagerAt28 {
        virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
        virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
        virtual f32 value(const char *);
    };
    volatile u32 *input = (volatile u32 *)arg1;
    u32 w0 = input[0], w1 = input[1], w2 = input[2], w3 = input[3];
    u32 w4 = input[4], w5 = input[5], w6 = input[6], w7 = input[7];
    u32 w8 = input[8], w9 = input[9], w10 = input[10], w11 = input[11];
    *(u32 *)((u8 *)arg0 + 0x10c) = w0;
    *(u32 *)((u8 *)arg0 + 0x110) = w1;
    *(u32 *)((u8 *)arg0 + 0x114) = w2;
    *(u32 *)((u8 *)arg0 + 0x118) = w3;
    *(u32 *)((u8 *)arg0 + 0x11c) = w4;
    *(u32 *)((u8 *)arg0 + 0x120) = w5;
    *(u32 *)((u8 *)arg0 + 0x124) = w6;
    *(u32 *)((u8 *)arg0 + 0x128) = w7;
    *(u32 *)((u8 *)arg0 + 0x12c) = w8;
    *(u32 *)((u8 *)arg0 + 0x130) = w9;
    *(u32 *)((u8 *)arg0 + 0x134) = w10;
    *(u32 *)((u8 *)arg0 + 0x138) = w11;

    void *object = fn_801284F8(0x6c, (void *)lbl_8055B3A8);
    if (object != 0) {
        *(const char **)((u8 *)object + 0x64) = lbl_8055B3B0;
        void *resource = *(void **)((u8 *)arg1 + 0x34);
        *(void **)((u8 *)object + 0x30) =
            fn_801E6A3C(*(s32 *)((u8 *)arg0 + 0x13c),
                        *(u8 *)((u8 *)arg0 + 0x165) != 0, 0);
        *(s32 *)((u8 *)object + 0x54) = *(s32 *)((u8 *)arg0 + 0x160);
        s32 i = 0;
        void *source = arg0;
        void *destination = object;
        while (i < *(s32 *)((u8 *)object + 0x54)) {
            *(void **)((u8 *)destination + 0x34) =
                fn_801E6BEC(*(char **)((u8 *)source + 0x140));
            source = (u8 *)source + 4;
            destination = (u8 *)destination + 4;
            i++;
        }
        fn_801E6CC8(*(void **)((u8 *)object + 0x30),
                    *(s32 *)((u8 *)object + 0x54) <= 1);
        if (*(u8 *)((u8 *)arg0 + 0x165) != 0) {
            *(s32 *)((u8 *)object + 0x60) = 1;
            *(u8 *)((u8 *)object + 0x59) = 1;
            if (resource != 0 && lbl_8055EC68 != 0) {
                ((ManagerAt24 *)lbl_8055EC68)->action(lbl_8033B56C);
                *(f32 *)((u8 *)object + 0x5c) =
                    ((ManagerAt28 *)resource)->value(lbl_8033B56C);
            } else {
                *(f32 *)((u8 *)object + 0x5c) = lbl_8056301C;
            }
            *(f32 *)((u8 *)object + 0x5c) =
                *(f32 *)((u8 *)object + 0x5c) * *(f32 *)((u8 *)object + 0x5c);
        } else {
            *(s32 *)((u8 *)object + 0x60) = 2;
            s32 index = fn_80129D90(0, 0, *(s32 *)((u8 *)object + 0x54));
            volatile s32 *entries = (volatile s32 *)((u8 *)object + index * 4);
            fn_801E6CD0(*(void **)((u8 *)object + 0x30),
                        entries[0x34 / 4], lbl_80562FF0);
        }
        *(u8 *)((u8 *)object + 0x5a) = 0;
        u32 a = *(u32 *)((u8 *)arg0 + 0x10c);
        u32 b = *(u32 *)((u8 *)arg0 + 0x110);
        *(u32 *)object = a;
        *(u32 *)((u8 *)object + 4) = b;
        a = *(u32 *)((u8 *)arg0 + 0x114);
        b = *(u32 *)((u8 *)arg0 + 0x118);
        *(u32 *)((u8 *)object + 8) = a;
        *(u32 *)((u8 *)object + 0xc) = b;
        a = *(u32 *)((u8 *)arg0 + 0x11c);
        b = *(u32 *)((u8 *)arg0 + 0x120);
        *(u32 *)((u8 *)object + 0x10) = a;
        *(u32 *)((u8 *)object + 0x14) = b;
        a = *(u32 *)((u8 *)arg0 + 0x124);
        b = *(u32 *)((u8 *)arg0 + 0x128);
        *(u32 *)((u8 *)object + 0x18) = a;
        *(u32 *)((u8 *)object + 0x1c) = b;
        a = *(u32 *)((u8 *)arg0 + 0x12c);
        *(u32 *)((u8 *)object + 0x20) = a;
        a = *(u32 *)((u8 *)arg0 + 0x130);
        b = *(u32 *)((u8 *)arg0 + 0x134);
        *(u32 *)((u8 *)object + 0x24) = a;
        *(u32 *)((u8 *)object + 0x28) = b;
        a = *(u32 *)((u8 *)arg0 + 0x138);
        *(u32 *)((u8 *)object + 0x2c) = a;
        *(u32 *)((u8 *)object + 0x68) = 0;
        *(u8 *)((u8 *)object + 0x58) = lbl_8055EC40;
    }
    fn_801FC4D8((void **)&lbl_8055EC5C, object);
}

extern "C" void fn_801FC4D8(void **arg0, void *arg1) {
    *(void **)((u8 *)arg1 + 0x68) = *arg0;
    *arg0 = arg1;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
// Creates an EWSound data entry from resource fields, resolves/instantiates its sound item,
// syncs volume/update params onto the item when present, tags it, and appends it to the list.
extern "C" void fn_801FC4E8(void *self, void *arg1) {
    struct ManagerLookup { virtual void a0(); virtual void a1(); virtual void a2(); virtual s32 lookup(const char *, s32); };
    struct ManagerFinish { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void finish(const char *); };
    struct ResourceGet { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual s32 get(const char *, s32); };
    struct ResourceValue { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual f32 value(const char *); };
    struct ResourceUpdate { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual f32 update(const char *, void *, f32); };
    struct Data { s32 a; s32 b; s32 c; u8 d; u8 pad[3]; void *item; };
    Data *data = (Data *)fn_801284F8(0x18, (void *)lbl_8055B3B8);
    if (data != 0) {
        volatile s32 *input = (volatile s32 *)arg1;
        s32 a = input[9];
        const char *name = lbl_8055B2C4;
        s32 b = input[10];
        data->a = a;
        s32 c = input[11];
        data->b = b;
        ResourceGet *resource = *(ResourceGet **)((u8 *)arg1 + 0x34);
        data->c = c;
        s32 first = ((ManagerLookup *)lbl_8055EC70)->lookup(name, data->b);
        s32 key = resource->get(name, first);
        ((ManagerFinish *)lbl_8055EC70)->finish(lbl_8055B3C0);
        f32 value = ((ResourceValue *)resource)->value(lbl_8055B3C0);
        data->item = fn_802077A4(key, 8, (void *)lbl_80488898, data);
        if (data->item != 0) {
            void *item = data->item;
            if (value != *(f32 *)((u8 *)item + 8)) {
                *((u8 *)item + 0x4D) = 1;
                *(f32 *)((u8 *)item + 8) = value;
            }
            *(f32 *)((u8 *)data->item + 0x6C) =
                ((ResourceUpdate *)resource)->update(lbl_8033B578, data->item, *(f32 *)((u8 *)data->item + 0x6C));
        }
        data->d = lbl_8055EC40;
    }
    fn_801FC644((void **)&lbl_8055EC6C, data);
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
extern "C" void fn_801FC644(void **arg0, void *arg1) {
    *(void **)((u8 *)arg1 + 0x14) = *arg0;
    *arg0 = arg1;
}

extern "C" s32 lbl_8055EC70;
extern "C" void fn_801FC654(void *arg0, s32 arg1, void *arg2) {
    ((void (*)(s32, s32, s32))fn_80204014)(arg1, *(s32 *)((u8 *)arg2 + 0x34), lbl_8055EC70);
}

extern "C" f32 fn_801FC664(void) {
    return lbl_80562FF0;
}

extern "C" void fn_801FC66C(void) {

}

extern "C" void fn_801FC670(void) {

}

extern u8 lbl_8033B588[];
extern s32 lbl_8055EC48;
void fn_802C6CF8(s32);
void *__dt__Q28PSSystem7SeqHeapFv_801EACF8(void *, s32);
void fn_80128668(void *);
#pragma small_data off
/* Destroy this object: set its vtable, unlink it from the global list, release its owned resource/id, run base destruction, and optionally free it. */
extern "C" void *fn_801FC674(void *arg0, s32 shouldDelete) {
    void **link;
    void *next;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033B588;
        link = (void **)&lbl_8055EC48;
        while ((next = *link) != 0) {
            if (next == arg0) { *link = *(void **)((u8 *)arg0 + 0x54); break; }
            link = (void **)((u8 *)next + 0x54);
        }
        if ((u32)arg0 + 0x44 != 0 && ((s32 *)arg0)[17] != -1) fn_802C6CF8(((s32 *)arg0)[17]);
        __dt__Q28PSSystem7SeqHeapFv_801EACF8(arg0, 0);
        if (shouldDelete > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FC720(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x50) == 0 && fn_801F7A0C() != 0) {
        fn_802C70AC(*(s32 *)((u8 *)arg0 + 0x3C), (u8 *)arg0 + 4, -1, -15);
    }
}

extern "C" f32 fn_801E88F0(s32);
extern "C" f32 fn_802C88E8(void *);
extern "C" f64 fn_8002F234(void);
extern "C" void fn_802C7AE0(s32, void *, s32);
extern f32 lbl_80558DC4;
extern f32 lbl_80563020;
#pragma push
#pragma processor 750
__declspec(section ".data") extern f32 lbl_80558DC4;
extern "C" f32 fn_801E88F0(s32);
extern "C" f32 fn_802C88E8(void *);
extern "C" f64 fn_8002F234(void);
extern "C" void fn_802C7AE0(s32, void *, s32);
#pragma push
#pragma processor 750
extern "C" void fn_801FC774(void *arg0) {
    f32 speed = fn_801E88F0(-1);
    f32 speed2 = speed * speed;
    f32 value;
    if (speed2 * fn_802C88E8((u8 *)arg0 + 0x28) >
        *(f32 *)((u8 *)arg0 + 0x4C) * *(f32 *)((u8 *)arg0 + 0x4C)) {
        f32 time = (f32)fn_8002F234();
        f32 current = *(f32 *)((u8 *)arg0 + 0x4C);
        f32 start = *(f32 *)((u8 *)arg0 + 0x48);
        f32 t = ((time - current) - lbl_80562FF0) / lbl_80563020;
        f32 blend = lbl_80562FFC;
        blend = (blend < t) ? t : blend;
        blend = (blend > lbl_80562FF0) ? lbl_80562FF0 : blend;
        value = start + blend * (lbl_80562FF0 - start);
    } else {
        value = *(f32 *)((u8 *)arg0 + 0x48);
    }
    if (!( (f32)__fabs((f64)value) <= lbl_80558DC4))
        fn_802C7AE0(*(s32 *)((u8 *)arg0 + 0x44), (u8 *)arg0 + 4, -1);
}
#pragma pop
extern "C" {
extern u8 lbl_8033B418[], lbl_8033B53C[], lbl_8033B52C[], lbl_8033B51C[];
extern u8 lbl_80333B98[], lbl_803337C8[], lbl_80333918[];
extern f32 lbl_80563010, lbl_80562FFC;
void fn_801A324C(void*, s32, void*, f32, f32);
}
struct FC048Obj {
    void *vtable;
    s32 f4;
    s32 f8;
    s32 fc;
    f32 f10;
    f32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    f32 f48;
    u8 f4c;
    u8 pad[3];
    f32 f50;
};

