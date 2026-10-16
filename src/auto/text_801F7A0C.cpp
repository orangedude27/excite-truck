// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" {
extern u8 lbl_8033B1EC[];
extern u8 lbl_8033B210[];
extern u8 lbl_8055B2DC[];
extern u8 lbl_8055B374[];
extern void *lbl_8055EC38;
extern void *lbl_8055EC44;
int stricmp(const char *, const char *);
void *fn_801F8188(s32 a, s32 b);
  void fn_802E317C(const char *, ...);
  s32 fn_801F9450(void *node);
  void *fn_801F95C4(void *node, s32 index, s32 arg);
  void fn_801F96A8(void *node);
  void *fn_801F93FC(void);
  }

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

extern "C" void fn_801F9440(F9List *list, F9List *node) {
    node->next2 = list->next2;
    list->next2 = node;
}

extern "C" s32 fn_801F948C(F9Node *node) {
    ((F9NodeFn *)node)->fn(node);
    return stricmp((char *)node->vtable, (char *)lbl_8033B1EC) == 0;
}

extern "C" void *fn_801F96C8(F9Node *node) {
    F9List *list = (F9List *)lbl_8055EC38;
    for (;;) {
        if (list == NULL) {
            break;
        }
        if (stricmp((char *)list->vtable, (char *)lbl_8033B1EC) != 0) {
            list = (F9List *)list->next2;
            continue;
        }
        if (list != NULL) {
            break;
        }
        fn_801F96A8(node);
        list = (F9List *)fn_801F93FC();
    }
    return list;
}

extern "C" void fn_801FC66C(void) {

}

extern "C" void fn_801FC670(void) {

}

