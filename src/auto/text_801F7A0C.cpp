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

extern "C" {
extern u8 lbl_8033B1EC[];
extern u8 lbl_8033B210[];
extern u8 lbl_8055B2DC[];
extern u8 lbl_8055B36C[];
extern u8 lbl_8055B37C[];
extern u8 lbl_8055B374[];
extern void *lbl_8055EC38;
extern void *lbl_8055EC44;
int stricmp(const char *, const char *);
void *fn_801F8188(s32 a, s32 b);
  void fn_802E317C(const char *, ...);
  s32 fn_801F9450(void *node);
      void *fn_801F95C4(void *fn, void *node);
          void fn_801F96A8(void *node);
      void *fn_801F93FC(void);
      }
extern void *fn_801F981C(void *node, s32 arg);
extern void fn_801F99CC(void *node);
extern void fn_801F9928(void *list, s32 arg);
extern void *fn_801F9440(void *list, void *node);

struct F9Node {
    void *vtable; // 0x0
    char *name;   // 0x4
    void *next;   // 0x8
    // 0x20
    void *next2;
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

extern "C" void fn_801F92A8(void) {

}

extern "C" void fn_801F9440(F9Node *list, F9Node *node) {
    node->next = list->next;
    list->next = node;
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

extern "C" void fn_801FC66C(void) {

}

extern "C" void fn_801FC670(void) {

}

