// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

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

extern "C" u32 fn_801F7A0C(void) { return 1; }

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

extern "C" s32 fn_801F815C(void) {
    return stricmp(lbl_8055B2C4, "") == 0;
}

extern "C" s32 fn_801F85DC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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

extern "C" int fn_8020402C(void);
extern "C" int fn_801F9B28();
extern "C" void fn_801FA298(void) {
    if (fn_8020402C() == 0) {
        fn_801F9B28();
    }
}

extern "C" s32 fn_801FB204(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801FC66C(void) {

}

extern "C" void fn_801FC670(void) {

}

