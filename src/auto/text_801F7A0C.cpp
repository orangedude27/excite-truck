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
    void *next;   // 0x20
};

extern "C" void fn_801F92A8(void) {

}

extern "C" void fn_801F9440(F9Node *list, F9Node *node) {
    node->next = list->next;
    list->next = node;
}

extern "C" s32 fn_801F948C(F9Node *node) {
    return stricmp((char *)node->vtable, (char *)lbl_8033B1EC) == 0;
}

extern "C" void fn_801FC66C(void) {

}

extern "C" void fn_801FC670(void) {

}

