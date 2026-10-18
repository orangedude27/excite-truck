// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
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
extern s32 lbl_8055B388;
extern void **lbl_8055EC54;
extern s32 lbl_8055EC58;
void **fn_80131810(void *);
void fn_80131818(void *);
void fn_8013A0B0(void **, void *, void *);
void fn_8013A198(void **, s32);
void *fn_8000AC38(void);
void fn_801F9AA4(void *, s32);
}

extern "C" {
extern s32 lbl_8055B1C8;
s32 fn_80204014(s32, s32, s32, void *);
void *fn_802C86DC(void);
void fn_802C70AC(s32, void *, s32, s32);
f32 PSVECDotProduct(const f32 *, const f32 *);
}

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
extern u8 lbl_8055B37C[];
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
extern void *fn_801F9440(void *list, void *node);

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
 PSVECCrossProduct((f32 *)((u8 *)arg0 + 0xC), cross);
 if (PSVECDotProduct(cross, (f32 *)((u8 *)arg0 + 0x18)) < lbl_80562FF0) {
  ((f32 *)arg0)[0] *= lbl_80562FF4; ((f32 *)arg0)[1] *= lbl_80562FF4; ((f32 *)arg0)[2] *= lbl_80562FF4;
 }
}

#pragma dont_inline reset

extern "C" int stricmp(const char *, const char *);
extern "C" const char lbl_8033B00C[];
extern "C" const char lbl_8055B2C4[];
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

extern u32 lbl_802F9B30[];
extern u8 lbl_8055B2CC[];
extern "C" int fn_801F88F4(void *arg0) {
 u32 table[3]; table[0]=lbl_802F9B30[0];table[1]=lbl_802F9B30[1];table[2]=lbl_802F9B30[2];
 char *name=((FNodeVT*)*(void**)arg0)->name(arg0);
 for(int i=0;i<3&&table[i];i++)if(stricmp((char*)table[i],name)==0)return 1;
 return 0;
}

extern "C" void fn_801F92A8(void) {

}

extern "C" void *fn_801F92AC(F92Obj *obj) {
    f32 a = lbl_80562FF0;
    f32 b = lbl_80563000;

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

extern "C" s32 fn_801F7EB0(void *out, void *self, s32 arg);
extern "C" int strcmp(const char *, const char *);
extern "C" void *fn_801F9338(void *self) {
    u8 pad[0x20];
    s32 sp8;
    void *data;
    void *result;
    void *node;
    s32 index;

    data = 0;
    if (fn_801F7EB0(&sp8, self, 0) != 0) {
        data = &sp8;
    }
    result = 0;
    index = 0;
    node = (*(FListVT **)self)->get(self, 0);
    while (node != 0) {
        if (strcmp(((FNodeVT *)*(void **)node)->name(node), (const char *)&lbl_8055B36C) == 0) {
            void *newNode = fn_801F8188(node, (s32)data, 0);
            *(void **)((u8 *)newNode + 0x24) = result;
            result = newNode;
        }
        index++;
        node = (*(FListVT **)self)->get(self, index);
    }
    return result;
}

extern "C" void *fn_801F93FC(void *node) {
    void *n = fn_801F8188(node, 0, 1);

    fn_801F9440((struct F9Node *)&lbl_8055EC38, (struct F9Node *)n);
    return n;
}

extern "C" void *fn_801F9440(F9Node *list, F9Node *node) {
    ((F92Node *)node)->next = ((F92Node *)list)->next;
    ((F92Node *)list)->next = (F92Node *)node;
}

extern "C" s32 fn_801F948C(F9Node *node) {
    ((F9NodeFn *)node)->fn(node);
    return stricmp((char *)node->name, (char *)lbl_8033B1EC) == 0;
}

extern "C" void *fn_801F95C4(void *arg0, void *arg1) {
    void *list = lbl_8055EC44;
    void *node = 0;
    s32 index;
    while (node == 0 && list != 0) {
        index = 0;
        do {
            void *owner = *(void **)list;
            void *table = *(void **)owner;
            node = ((void *(*)(void *, s32))((void **)table)[3])(owner, index);
            if (node == 0) break;
            if (((s32 (*)(void *))arg0)(node) != 0) {
                char *name = ((char *(*)(void *, void *))(*(void ***)node)[5])(node, lbl_8055B2DC);
                if (stricmp(name, (const char *)arg1) == 0) break;
            }
            index++;
        } while (1);
        list = *(void **)((u8 *)list + 4);
    }
    if (node == 0) fn_802E317C((const char *)lbl_8033B210, (const char *)arg1);
    return node;
}

extern "C" void fn_801F96A8(void *node) {
    fn_801F95C4((void *)fn_801F9450, node);
}

extern "C" void fn_801F96B8(void *node) {
    fn_801F95C4((void *)fn_801F948C, node);
}

extern "C" void *fn_801F96C8(void *node) {
    void *list = lbl_8055EC38;
    for (;;) {
        if (list == NULL) {
            break;
        }
        if (stricmp((char *)node, (char *)list) != 0) {
            list = *(void **)((char *)list + 0x20);
            continue;
        }
        if (list != NULL) {
            break;
        }
        fn_801F96A8(node);
        list = fn_801F93FC();
    }
    return list;
}

extern "C" void fn_801BFD34(void *, void *, void *);
extern "C" void fn_80015B20(void *, void *, void *);
extern "C" void fn_80204018(void *, void *);
extern "C" u8 lbl_8055EC7C;
extern "C" void fn_801F973C(void *arg0, void *arg1, u32 arg2) {
    u32 temp;
    u32 flags;
    u8 data2c[16];
    u8 data8[32];
    s32 sp3c;
    s32 sp38;
    void *node;

    if ((arg2 & 2) != 0) {
        temp = lbl_8055EC7C == 0;
        lbl_8055EC7C = temp;
        flags = *(s32 *)((u8 *)arg0 + 0x24) != 0;
        if (temp != 0) flags |= 2;
        node = arg0;
        sp3c = 0;
        sp38 = 0;
        while (node != 0) {
            fn_801BFD34(data2c, (u8 *)node + 0x54, arg1);
            fn_80015B20(data8, (u8 *)node + 0x30, arg1);
            sp38 = flags;
            sp3c = *(s32 *)((u8 *)arg1 + 0x34);
            ((void (*)(void *, void *, s32 *, s32 *))(*(u32 **)*(void **)((u8 *)node + 0x108))[4])(node, data8, &sp38, &sp3c);
            node = *(void **)((u8 *)node + 0x24);
        }
    }
    if ((arg2 & 1) != 0) fn_80204018(arg0, arg1);
}

#pragma dont_inline on
extern "C" void fn_801F9928(void *list, s32 arg) {
    s32 i = 0;
    void *cur = (*(FListVT **)list)->get(list, 0);

    for (;;) {
        void *next;
        FNodeVT *vt;

        if (cur == NULL) {
            break;
        }
        vt = *(FNodeVT **)cur;
        next = (*(FListVT **)list)->get(list, i);
        vt->name(cur);
        if (stricmp((char *)(&lbl_8055B36C), (char *)(&lbl_8055B36C)) == 0) {
            fn_801F981C(cur, arg);
        }
        i++;
        cur = next;
    }
}

extern "C" void fn_801F99CC(F92Obj *obj) {
    F92Obj *cur = *(F92Obj **)((char *)&obj->w108 + 0x24 - 0x108);
    F92Obj *next;

    while (cur != NULL) {
        next = *(F92Obj **)((char *)&cur->w108 + 0x24 - 0x108);
        if (cur != NULL) {
            (*(void (**)(F92Obj *, s32))((char *)&cur->w108 + 0x100 - 0x108))(cur, 1);
        }
        cur = next;
    }
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

void fn_802C6CF8(s32);
void fn_80128668(void);
void fn_801E6CD0(void *, s32, f32);
void fn_801E6CC4(void *);
void fn_801E6B98(void *);
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
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 0x68);
        fn_801E6CD0(*(void **)((char *)node + 0x30), 0, lbl_80562FF0);
        int i;
        for (i = 0; i < *(s32 *)((char *)node + 0x54); i++)
            fn_801E6CC4(*(void **)((char *)node + 0x34 + i * 4));
        fn_801E6B98(*(void **)((char *)node + 0x30));
        ((void (*)(void *))fn_80128668)(node);
        node = next;
    }
    *arg0 = 0;
}

extern "C" void fn_801FA0B0(void **arg0) {
    void *node = *arg0;
    while (node != 0) {
        void *next = *(void **)((char *)node + 4);
        if (*(void **)node != 0) fn_80131818(node);
        *(s32 *)node = 0;
        ((void (*)(void *))fn_80128668)(node);
        node = next;
    }
    *arg0 = 0;
}

extern void* lbl_8055EC4C;
extern void* lbl_8055EC50;
extern void* lbl_8055EC5C;
extern s32 fn_80129D90(s32, s32);
extern s32 fn_801E6CD0(s32, s32, f32);
void fn_801FA1D4(void) {
    unsigned char* p;
    void* cur;
    s32 i;
    p = (unsigned char*)lbl_8055EC4C;
    while (p != 0) { p[0x40] = 1; p = *(unsigned char**)(p + 0x44); }
    p = (unsigned char*)lbl_8055EC50;
    while (p != 0) { p[0x40] = 1; p = *(unsigned char**)(p + 0x44); }
    cur = lbl_8055EC5C;
    while (cur != 0) {
        if (*(s32*)((char*)cur + 0x54) > 0) {
            if (*(s32*)((char*)cur + 0x60) != 1) {
                i = fn_80129D90(0, 0);
                fn_801E6CD0(*(s32*)((char*)cur + 0x30), *(s32*)((char*)cur + 0x34 + i * 4), lbl_80562FF0);
            } else fn_801E6CD0(*(s32*)((char*)cur + 0x30), 0, lbl_80562FF0);
        }
        cur = *(void**)((char*)cur + 0x68);
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
extern "C" void fn_801FA550(void) {
    void *node = lbl_8055EC50;
    void *other;
    while (node != 0) {
        if (*(u8 *)((u8 *)node + 0x41) == 0 &&
            *(u8 *)((u8 *)node + 0x40) != 0 &&
            fn_801F7A0C() != 0) {
            void *arg = *(void **)((u8 *)node + 0x34);
            s32 id = *(s32 *)node;
            if (arg == 0) {
                arg = (u8 *)node + 4;
            } else {
                arg = *(void **)((u8 *)node + 0x34);
            }
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

#pragma use_lmw_stmw off
extern "C" void *fn_801FA8E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 id;
    void **list;
    void *context;
    void *node;
    id = lbl_8055EC78;
    lbl_8055EC78 = id + 1;
    context = fn_8013184C();
    list = lbl_8055EC74;
    void *tag = lbl_8033B5B8;
    node = fn_801284F8(0x4C, tag);
    if (node != 0) node = fn_801A4A8C(node, id, arg2, arg0, arg1, context);
    *(void **)((u8 *)node + 0x44) = *list;
    *list = node;
    return (u8 *)node + 4;
}
#pragma use_lmw_stmw reset
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

extern "C" void fn_801FB1F4(s32 arg0) {
    volatile s32 *p = &lbl_8055B1C8;
    arg0 = *p - arg0;
    *p = arg0;
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
extern "C" void fn_801F7D10(void);
extern "C" void fn_801FB284(void *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f6_2;

    fn_801F7D10();
    if (*(u32 *)((u8 *)arg0 + 0x190) & 0x100) {
        temp_f3 = -*(f32 *)((u8 *)arg0 + 0x28);
        temp_f5 = *(f32 *)((u8 *)arg1 + 0x24);
        temp_f6 = *(f32 *)((u8 *)arg1 + 0x0C) * temp_f3;
        temp_f4 = *(f32 *)((u8 *)arg1 + 0x10) * temp_f3;
        temp_f2 = *(f32 *)((u8 *)arg1 + 0x2C) + (*(f32 *)((u8 *)arg1 + 0x14) * temp_f3);
        temp_f1 = temp_f5 + temp_f6;
        temp_f3_2 = *(f32 *)((u8 *)arg1 + 0x28);
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

extern "C" void *fn_801FBE1C(void **arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6) {
    void *obj = fn_801284F8(0x4C, lbl_8033B5B8);
    if (obj != 0) {
        obj = fn_801A4A8C(arg1, arg2, arg3, arg4, arg5, arg6);
    }
    *(void **)((u8 *)obj + 0x44) = *arg0;
    *arg0 = obj;
    return (u8 *)obj + 4;
}

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

extern "C" void fn_801FBF48(void* arg0) {
 void* obj = fn_801284F8(0x2C, lbl_8033B52C);
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
 *(s32*)((char*)obj + 0x18) = 0x52494E47;
 *(f32*)((char*)obj + 0x10) = one;
 *(f32*)((char*)obj + 0x14) = zero;
 *(s32*)((char*)obj + 0x20) = 100;
 *(s32*)((char*)obj + 0x1C) = 0;
 *(void**)obj = lbl_803337C8;
 *(f32*)((char*)obj + 0x24) = x;
 *(f32*)((char*)obj + 0x28) = y;
 
 }
}

#pragma push
#pragma paired_single off
extern "C" void fn_801FBFE8(void* arg0) {
 f64 value = lbl_80563010;
 void* obj = fn_801284F8(0xE0, lbl_8033B53C);
 if (obj != 0) fn_801A324C(obj, 0, (char*)arg0 + 0x58, value, *(f32*)((char*)arg0 + 0x4C));
}
extern "C" void* fn_801FC228(void* arg0, s32 arg1) {
 if (arg0 != 0) {
 *(void**)((char*)arg0 + 0x108) = lbl_8033B418;
 if (arg1 > 0) fn_80128668();
 }
 return arg0;
}

extern "C" void fn_801FC4D8(void **arg0, void *arg1) {
    *(void **)((u8 *)arg1 + 0x68) = *arg0;
    *arg0 = arg1;
}

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
    if (arg0 != 0) {
        *(void **)arg0 = (void *)((u8 *)&lbl_8033B588)[0];
        link = (void **)&lbl_8055EC48;
        while ((next = *link) != 0) {
            if (next == arg0) { *link = *(void **)((u8 *)arg0 + 0x54); break; }
            link = (void **)((u8 *)next + 0x54);
        }
        if ((u8 *)arg0 + 0x44 != 0 && *(s32 *)((u8 *)arg0 + 0x44) != -1) fn_802C6CF8();
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

#pragma small_data reset
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
