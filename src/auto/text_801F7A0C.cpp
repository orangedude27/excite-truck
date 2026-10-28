// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
__declspec(section ".sdata") extern const char lbl_8055B2A8[], lbl_8055B2B0[], lbl_8055B2B8[], lbl_8055B2C0[];
extern s32 lbl_8055EC48;
extern "C" s32 fn_802C6B44(void *);
extern "C" s32 fn_802C6C20(f32);
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

extern "C" {
extern u8 lbl_8033B1EC[];
extern u8 lbl_8033B210[];
extern u8 lbl_8055B2DC[];
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

void fn_801F7A14(void *);
s32 fn_801F7A88(void *, s32, void *, s32);
extern const char lbl_8055B280[];
extern const char lbl_8055B288[];
extern const char lbl_8055B290[];
extern const char lbl_8055B298[];
extern "C" s32 fn_801F7B10(void *arg0, void *arg1, s32 arg2) {
    u8 *dst=(u8 *)arg0; s32 i;
    if (fn_801F7A88(arg1,arg2,arg0,0x30)) {
        for(i=0;i<2;i++) {
            u8 *p=dst+i*0x18; u8 t;
            t=p[0];p[0]=p[3];p[3]=t;t=p[1];p[1]=p[2];p[2]=t;
            t=p[4];p[4]=p[7];p[7]=t;t=p[5];p[5]=p[6];p[6]=t;
            t=p[8];p[8]=p[0xB];p[0xB]=t;t=p[9];p[9]=p[0xA];p[0xA]=t;
            t=p[0xC];p[0xC]=p[0xF];p[0xF]=t;t=p[0xD];p[0xD]=p[0xE];p[0xE]=t;
            t=p[0x10];p[0x10]=p[0x13];p[0x13]=t;t=p[0x11];p[0x11]=p[0x12];p[0x12]=t;
            t=p[0x14];p[0x14]=p[0x17];p[0x17]=t;t=p[0x15];p[0x15]=p[0x16];p[0x16]=t;
        }
    } else {
        f32 a[3],b[3],c[3],d[3]; void **v=*(void ***)arg1;
        ((void (*)(void *,void *,const char *))v[13])(a,arg1,lbl_8055B280);
        ((void (*)(void *,void *,const char *))v[13])(b,arg1,lbl_8055B288);
        ((void (*)(void *,void *,const char *))v[13])(c,arg1,lbl_8055B290);
        ((void (*)(void *,void *,const char *))v[13])(d,arg1,lbl_8055B298);
        ((f32 *)arg0)[0]=a[0];((f32 *)arg0)[1]=a[1];((f32 *)arg0)[2]=a[2];
        ((f32 *)arg0)[3]=b[0];((f32 *)arg0)[4]=b[1];((f32 *)arg0)[5]=b[2];
        ((f32 *)arg0)[6]=c[0];((f32 *)arg0)[7]=c[1];((f32 *)arg0)[8]=c[2];
        ((f32 *)arg0)[9]=d[0];((f32 *)arg0)[10]=d[1];((f32 *)arg0)[11]=d[2];
    }
    fn_801F7A14(arg0);
}

extern "C" s32 fn_80204BB4(void);
extern "C" s32 fn_80204CF0(void);
extern "C" char lbl_8033AFB8[];
extern "C" char lbl_8033AFC8[];
#pragma scheduling invalid_target
extern "C" void fn_801F7D10(void *arg0, void *arg1, void *arg2) {
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

extern "C" void fn_801F7FA0(void *output, void *input, void *unused) {
    struct Child {
        virtual const char *name();
        virtual void v0C();
        virtual void v10();
        virtual void v14();
        virtual void v18();
        virtual s32 value(const char *);
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
            f32 values[3];
            ((void (*)(f32 *, Child *, const char *))(*(void ***)child)[13])(
                values, child, lbl_8055B2B8);
            *(f32 *)(record + 0x0C) = values[0];
            *(f32 *)(record + 0x10) = values[1];
            *(f32 *)(record + 0x14) = values[2];
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

__declspec(section ".sdata") extern const char lbl_8055B2A8[], lbl_8055B2B0[], lbl_8055B2B8[], lbl_8055B2C0[];
extern const char lbl_8055B2E4[], lbl_8055B2EC[];
int sprintf(char *, const char *, ...);
void *fn_801F83E4(void **arg0) {
    u8 *obj = (u8 *)fn_801284F8(0x168, (void *)lbl_8055B2E4);
    char name[0x20]; s32 i; void **vt;
    if (obj != 0) {
        vt = (void **)*arg0;
        *(void **)(obj+0x108)=lbl_8033B468; *(s32 *)(obj+0x78)=0;
        *(f32 *)(obj+0x7c)=lbl_80562FF0; *(f32 *)(obj+0x80)=lbl_80562FF0;
        *(s32 *)(obj+0x104)=0; *(s32 *)(obj+0x24)=0; *(s32 *)(obj+0x20)=0;
        *(f32 *)(obj+0x28)=lbl_80563000; obj[0x60]=1;
        memset(obj,0x61,0x20); memset(obj+0x61,0x61,0x10);
        *(s32 *)(obj+0x74)=-1; *(void **)(obj+0x108)=lbl_8033B418;
        *(void **)(obj+0x13c)=((void *(*)(void *, const char *))vt[5])(arg0,lbl_8055B2A8);
        *(void **)(obj+0x13c)=((void *(*)(void *, const char *, void *))vt[6])(arg0,lbl_8033AF80+0xc0,*(void **)(obj+0x13c));
        *(void **)(obj+0x140)=((void *(*)(void *, const char *))vt[5])(arg0,lbl_8033AF80+0xcc);
        *(s32 *)(obj+0x160)=1; i=1;
        while(i<8) {
            sprintf(name,lbl_8033AF80+0xd8,i+1);
            if(((s32(*)(void *,const char *))vt[3])(arg0,name)!=0) {
                *(void **)(obj+0x140+i*4)=((void *(*)(void *,const char *))vt[5])(arg0,name);
                i++; *(s32 *)(obj+0x160)=i;
            } else break;
        }
        obj[0x164]=((u8(*)(void *,const char *,s32))vt[12])(arg0,lbl_8055B2EC,1);
        obj[0x165]=((u8(*)(void *,const char *,s32))vt[12])(arg0,lbl_8033AF80+0xe8,1);
        ((void *(*)(void *,const char *))vt[5])(arg0,(const char *)lbl_8055B2DC);
    }
    return obj;
}

extern "C" s32 fn_801F85DC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void *lbl_8055B2F8;
extern u8 lbl_8033B3F0[];
extern "C" void *fn_801F861C(void) {
 F92Obj *obj=(F92Obj*)fn_801284F8(0x10C,lbl_8055B2F8);
 if(obj){obj->w108=lbl_8033B468;obj->w78=0;obj->f7c=lbl_80562FF0;obj->f80=lbl_80562FF0;obj->w104=0;obj->f24=0;obj->f20=0;obj->f28=lbl_80563000;obj->b60=1;memset(obj,0x20,0x61);memset((u8*)obj+0x61,0x61,0x10);obj->w74=-1;obj->w108=lbl_8033B3F0;}return obj;
}

extern "C" void *fn_801F86C8(void *arg0) {
class NodeVTable { public: virtual void v0();virtual void v1();virtual void v2();virtual void *getString(const char *);virtual void v6();virtual void v7();virtual int query20(const char *,int);virtual void v9();virtual void v10();virtual void v11();virtual int query30(const char *,int);virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void *query5C(const char *);};
const char *base=lbl_8033AF80;void *saved=arg0;void *object;
object=fn_801284F8(0x1A0,(void *)(base+0xF4));
if(object){
fn_801F92AC((F92Obj *)object);*(void **)((char *)object+0x108)=lbl_8033B440;
((void (*)(void *))fn_801F92A8)((char *)object+0x10C);
*(int *)((char *)object+0x190)=0;*(volatile int *)((char *)object+0x10C)=0;
fn_801F8988((char *)object+0x10C,saved);
if(fn_801F88F4(saved)==0)*(int *)((char *)object+0x190)|=4;
if(((NodeVTable *)saved)->query30(base+0x100,0))*(int *)((char *)object+0x190)|=1;
if(((NodeVTable *)saved)->query30(base+0x110,0))*(int *)((char *)object+0x190)|=0x100;
if(((NodeVTable *)saved)->query30(base+0x120,0))*(int *)((char *)object+0x190)|=0x20;
if(((NodeVTable *)saved)->query30(lbl_8055B300,0)){*(int *)((char *)object+0x190)|=0x40;*(void **)((char *)object+0x194)=((NodeVTable *)saved)->getString(lbl_8055B308);}
else *(void **)((char *)object+0x194)=lbl_8055B310;
if(((NodeVTable *)saved)->query30(base+0x130,0))*(int *)((char *)object+0x190)|=0x80;
if(((NodeVTable *)saved)->query30(base+0x13C,0))*(int *)((char *)object+0x190)|=0x200;
*(int *)((char *)object+0x198)=((NodeVTable *)saved)->query20(base+0x148,-1);
*(void **)((char *)object+0x19C)=((NodeVTable *)saved)->query5C(base+0x154);}
return object;
}

extern u32 lbl_802F9B30[];
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
    do {
        if (stricmp(name, (const char *)*entry) == 0) return 1;
        entry++;
    } while (*entry != 0);
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

    u8 sp8[0x30];
    void *data;
    void *result;
    void *node;
    s32 index;

    data = 0;
    if (fn_801F7EB0(sp8, self, 0) != 0) {
        data = sp8;
    }
    result = 0;
    index = 0;
    goto get_node;

body:
    if (strcmp(((Node *)node)->name(), (const char *)&lbl_8055B36C) == 0) {
        void *newNode = fn_801F8188(node, (s32)data, 0);
        *(void **)((u8 *)newNode + 0x24) = result;
        result = newNode;
    }
    index++;

get_node:
    node = ((List *)self)->get(index);
    if (node != 0) {
        goto body;
    }

    return result;
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
        if (*(void * volatile *)node != 0) {
            *(void **)((u8 *)node + 4) = lbl_8055EC44;
            lbl_8055EC44 = node;
        } else {
            fn_80131818(0);
            *(void * volatile *)node = 0;
            ((void (*)(void *))fn_80128668)(node);
        }
    }
}

__declspec(section ".sdata") extern u8 lbl_8055B2DC[];
extern "C" void *fn_801F95C4(void *arg0, void *arg1) {
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
    for (;;) {
        if (stricmp((char *)node, (char *)list) != 0) {
            list = *(void **)((char *)list + 0x20);
            if (list != NULL) {
                continue;
            }
        }
        if (list != NULL) {
            break;
        }
        fn_801F96A8(node);
        list = ((void *(*)(void))fn_801F93FC)();
        break;
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

    if ((arg2 & 2) != 0) {
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
    if ((arg2 & 1) != 0) fn_80204018(arg0, arg1);
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
    do {
        fn_801F99CC((F92Obj *)node);
        F92Node *next = node->next;
        if (node != 0) {
            ((F92VT *)((F92Obj *)node)->w108)->fn8(node, 1);
        }
        node = next;
    } while (node != 0);
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

extern "C" s32 fn_801F9BD0(s32 **arg0, s32 **arg1) {
    return (*arg0)[15] - (*arg1)[15];
}

#pragma scheduling invalid_target
extern "C" void fn_801F9BE8(void) {
    extern void *lbl_8055EC4C, *lbl_8055EC50;
    extern void **lbl_8055EC54;
    extern s32 lbl_8055EC58;
    extern char lbl_8033B32C[];
    extern void *fn_8012850C(u32, void *);
    extern int qsort(void *, u32, u32, int (*)(const void *, const void *));
    extern int fn_801F9BD0(const void *, const void *);
    s32 index;
    lbl_8055EC58 = 0;
    {
        void *node = lbl_8055EC4C;
        while (node != 0) {
            if (*(s32 *)((u8 *)node + 0x3C) >= 0)
                ++lbl_8055EC58;
            node = *(void **)((u8 *)node + 0x44);
        }
    }
    {
        void *node = lbl_8055EC50;
        while (node != 0) {
            if (*(s32 *)((u8 *)node + 0x3C) >= 0)
                ++lbl_8055EC58;
            node = *(void **)((u8 *)node + 0x44);
        }
    }
    if (lbl_8055EC58 >= 1) {
        lbl_8055EC54 = (void **)fn_8012850C(lbl_8055EC58 * 4, lbl_8033B32C);
        index = 0;
        {
            void *node = lbl_8055EC4C;
            while (node != 0) {
                if (*(s32 *)((u8 *)node + 0x3C) >= 0)
                    ((void **)lbl_8055EC54)[index++] = node;
                node = *(void **)((u8 *)node + 0x44);
            }
        }
        {
            void *node = lbl_8055EC50;
            while (node != 0) {
                if (*(s32 *)((u8 *)node + 0x3C) >= 0)
                    ((void **)lbl_8055EC54)[index++] = node;
                node = *(void **)((u8 *)node + 0x44);
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
extern "C" void fn_801F9E04(void *arg0) {
    extern s32 lbl_8055EC64;
    extern void *lbl_8055EC68;
    extern void *lbl_8055EC50;
    extern u8 lbl_8055EC42;
    register u32 zero = 0;
    s32 base = (s32)lbl_8033AF80;
    void *memory;

    lbl_8055EC38 = (void *)zero;
    fn_801F94CC((const char *)(base + 0x3BC));
    fn_801F94CC((const char *)(base + 0x3D4), arg0);
    fn_801F94CC((const char *)(base + 0x39C));
    fn_801F94CC((const char *)(base + 0x3E8));

    lbl_8055EC4C = (void *)zero;
    lbl_8055EC3C = 1;
    lbl_8055EC50 = (void *)zero;
    lbl_8055EC54 = (void **)zero;
    lbl_8055EC58 = zero;
    lbl_8055EC42 = (u8)fn_801F9D70(arg0);
    lbl_8055B1C8 = -0x4E20;

    memory = fn_801284F8(4, (void *)(base + 0x3F8));
    if (memory != 0)
        *(s32 *)memory = zero;
    lbl_8055EC74 = (void **)memory;
    lbl_8055EC78 = 0x2710;
    lbl_8055EC64 = zero;
    lbl_8055EC68 = ((void *(*)(void *))fn_801F96B8)((void *)lbl_8055B390);
    lbl_8055EC70 = (s32)(u32)((void *(*)(void *))fn_801F96B8)((void *)lbl_8055B2C4);
    ((void (*)(void *))fn_8020401C)(arg0);
    fn_801EEFDC((void *)fn_801F9CF8, 0xC);
}

extern "C" void fn_802C6CF8(s32);
void fn_801EF024(void *);
void fn_80204020(void);
void fn_80128668(void);
void fn_80128670(void);
extern "C" void fn_801FA010(void **);
void fn_801F9A24(void *);
void fn_801FA0B0(void **);
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
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 0x44);
        fn_802C6CF8(*(s32 *)node);
        ((void (*)(void *))fn_80128668)(node);
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
    goto check;
loop:
    {
        void *next = *(void **)((char *)node + 4);
        void *value = *(void **)node;
        if (value != 0) fn_80131818(value);
        *(s32 *)node = 0;
        ((void (*)(void *))fn_80128668)(node);
        node = next;
    }
check:
    if (node != 0) goto loop;
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
extern "C" void fn_801FA1D4(void) {
    unsigned char *p;
    void *cur;
    s32 i;
    p = (unsigned char *)lbl_8055EC4C;
    while (p != 0) {
        p[0x40] = 1;
        p = *(unsigned char **)(p + 0x44);
    }
    p = (unsigned char *)lbl_8055EC50;
    while (p != 0) {
        p[0x40] = 1;
        p = *(unsigned char **)(p + 0x44);
    }
    cur = lbl_8055EC5C;
    while (cur != 0) {
        if (*(volatile s32 *)((char *)cur + 0x54) > 0) {
            if (*(s32 *)((char *)cur + 0x60) != 1) {
                i = fn_80129D90(0, 0);
                fn_801E6CD0(*(s32 *)((char *)cur + 0x30),
                            *(s32 *)((char *)cur + 0x34 + i * 4),
                            lbl_80562FF0);
            } else {
                fn_801E6CD0(*(s32 *)((char *)cur + 0x30), 0, lbl_80562FF0);
            }
        }
        cur = *(void **)((char *)cur + 0x68);
    }
}

extern "C" int fn_8020402C(void);
extern "C" int fn_801F9B28();
extern "C" void fn_801FA298(void) {
    if (fn_8020402C() == 0) {
        fn_801F9B28();
    }
}

extern "C" void fn_801E75C8(s32, void *);
extern "C" u32 fn_801F7A0C(void);
extern "C" void fn_802C70AC(s32, void *, s32, s32);
extern "C" void *lbl_8055EC50;
extern "C" void *lbl_8055EC5C;
extern "C" u8 lbl_8055EC40;
#pragma scheduling invalid_target
extern "C" void fn_801FA550(void) {
    void *node;
    void *other;
    node = lbl_8055EC50;
    while (node != 0) {
        if (*(u8 *)((u8 *)node + 0x41) == 0 &&
            *(u8 *)((u8 *)node + 0x40) != 0 &&
            fn_801F7A0C() != 0) {
            void *arg = *(void **)((u8 *)node + 0x34);
            s32 id = *(s32 *)node;
            if (arg == 0) arg = (u8 *)node + 4;
            fn_802C70AC(id, arg, -1, -15);
        }
        node = *(void **)((u8 *)node + 0x44);
    }
    other = lbl_8055EC5C;
    while (other != 0) {
        if (fn_801F7A0C() != 0 &&
            *(u8 *)((u8 *)other + 0x58) == *((u8 *)&lbl_8055EC40 + 1)) {
            fn_801E75C8(*(s32 *)((u8 *)other + 0x30), other);
        }
        other = *(void **)((u8 *)other + 0x68);
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
#pragma use_lmw_stmw off
extern "C" void fn_801FA7F4(void *arg0, s32 *arg1, s32 arg2) {
    volatile u32 *src = (volatile u32 *)arg1;
    u32 zero, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    f32 data[14];

    zero = 0;
    t0 = src[0];
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

    ((u32 *)data)[13] = zero;
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
    s32 flags;
    s32 result;
    f32 delta[3];
    void *camera;
    f32 x;
    f32 y;
    f32 z;
    f32 cx;
    f32 cy;
    f32 cz;

    if (*(u32 *)((u8 *)arg0 + 0x190) & 1) {
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
        flags = 0x20;
        if (result) {
            flags = 0x10;
        }
        flags |= 1;
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
extern "C" void fn_801FBEA8(void* arg0) {
 void* obj = fn_801284F8(0x2C, lbl_8033B51C);
 if (obj != 0) {
 f32 zero, one, x, y;
 one = lbl_80563010;
 zero = lbl_80562FFC;
 *(void**)obj = lbl_80333B98;
 x = *(f32*)((char*)arg0 + 0x58);
 *(s32*)((char*)obj + 0xC) = 0;
 y = *(f32*)((char*)arg0 + 0x5C);
 *(s32*)((char*)obj + 4) = 0;
 *(s32*)((char*)obj + 8) = 0;
 *(s32*)((char*)obj + 0x18) = 0x54554245;
 *(f32*)((char*)obj + 0x10) = one;
 *(f32*)((char*)obj + 0x14) = zero;
 *(s32*)((char*)obj + 0x20) = 100;
 *(s32*)((char*)obj + 0x1C) = 0;
 
 *(f32*)((char*)obj + 0x24) = x;
 *(f32*)((char*)obj + 0x28) = y;
 *(void**)obj = lbl_80333918;
 }
}
#pragma scheduling invalid_target
extern "C" void fn_801FBF48(void *arg0) {
    void *obj = fn_801284F8(0x2C, lbl_8033B52C);
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
        *(volatile s32 *)((char *)obj + 0x18) = 0x52494E47;
        *(volatile f32 *)((char *)obj + 0x10) = one;
        *(volatile f32 *)((char *)obj + 0x14) = zero;
        *(volatile s32 *)((char *)obj + 0x20) = 100;
        *(volatile s32 *)((char *)obj + 0x1C) = 0;
        *(volatile void **)obj = lbl_803337C8;
        *(volatile f32 *)((char *)obj + 0x24) = x;
        *(volatile f32 *)((char *)obj + 0x28) = y;
    }
}
#pragma scheduling on
extern "C" void fn_801FBFE8(void* arg0) {
 f64 value = lbl_80563010;
 void* obj = fn_801284F8(0xE0, lbl_8033B53C);
 if (obj != 0) fn_801A324C(obj, 0, (char*)arg0 + 0x58, value, *(f32*)((char*)arg0 + 0x4C));
}

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
        f32 value, zero, x;
        zero = lbl_80562FF0;
        value = lbl_80563014;
        *(void **)obj = lbl_80333B98;
        x = *(f32 *)((u8 *)arg0 + 0x58);
        *(s32 *)((u8 *)obj + 0xC) = 0;
        *(s32 *)((u8 *)obj + 4) = 0;
        *(s32 *)((u8 *)obj + 8) = 0;
        *(s32 *)((u8 *)obj + 0x18) = 0x53504852;
        *(f32 *)((u8 *)obj + 0x10) = temp_f31;
        *(f32 *)((u8 *)obj + 0x14) = value;
        *(s32 *)((u8 *)obj + 0x20) = 0x64;
        *(s32 *)((u8 *)obj + 0x1C) = 0;
        *(void **)obj = lbl_80333B48;
        *(f32 *)((u8 *)obj + 0x24) = x;
        *(f32 *)((u8 *)obj + 0x34) = zero;
        *(f32 *)((u8 *)obj + 0x38) = zero;
        *(f32 *)((u8 *)obj + 0x3C) = zero;
        *(f32 *)((u8 *)obj + 0x40) = zero;
        *(f32 *)((u8 *)obj + 0x44) = zero;
        *(f32 *)((u8 *)obj + 0x48) = zero;
        *(u8 *)((u8 *)obj + 0x4C) = 0;
        *(f32 *)((u8 *)obj + 0x50) = zero;
        *(f32 *)((u8 *)obj + 0x28) = zero;
        *(f32 *)((u8 *)obj + 0x2C) = zero;
        sp8 = zero;
        spC = zero;
        sp10 = zero;
        *(f32 *)((u8 *)obj + 0x30) = zero;
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

extern "C" void fn_801FC4D8(void **arg0, void *arg1) {
    *(void **)((u8 *)arg1 + 0x68) = *arg0;
    *arg0 = arg1;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
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

extern u32 lbl_8033B588;
extern s32 lbl_8055EC48;
void fn_802C6CF8(void);
void *__dt__Q28PSSystem7SeqHeapFv_801EACF8(void *, s32);
void fn_80128668(void *);
#pragma small_data off
extern "C" void *fn_801FC674(void *arg0, s32 arg1) {
    void **link;
    void *next;
    volatile u8 *field;
    if (arg0 != 0) {
        *(void **)arg0 = (void *)((u8 *)&lbl_8033B588)[0];
        link = (void **)&lbl_8055EC48;
        while ((next = *link) != 0) {
            if (next == arg0) { *link = *(void **)((u8 *)arg0 + 0x54); break; }
            link = (void **)((u8 *)next + 0x54);
        }
        field = (volatile u8 *)arg0 + 0x44;
        if (field != 0 && *(s32 *)field != -1) fn_802C6CF8(*(s32 *)field);
        __dt__Q28PSSystem7SeqHeapFv_801EACF8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
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
    if (fn_802C88E8((u8 *)arg0 + 0x28) * speed2 >
        *(f32 *)((u8 *)arg0 + 0x4C) * *(f32 *)((u8 *)arg0 + 0x4C)) {
        f32 time = (f32)fn_8002F234();
        f32 current = *(f32 *)((u8 *)arg0 + 0x4C);
        f32 start = *(f32 *)((u8 *)arg0 + 0x48);
        f32 t = ((time - current) - lbl_80562FF0) / lbl_80563020;
        f32 blend = lbl_80562FFC;
        if (blend < t) blend = t;
        if (blend > lbl_80562FF0) blend = lbl_80562FF0;
        value = start + blend * (lbl_80562FF0 - start);
    } else {
        value = *(f32 *)((u8 *)arg0 + 0x48);
    }
    if ((f32)__fabs((f64)value) > lbl_80558DC4)
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
