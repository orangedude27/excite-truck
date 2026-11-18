// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int __register_global_object(void *, void *, void *);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801DF678(void);
extern void fn_801DF6D0(void);
struct Elem {
    s8 f0;
    void *f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
};

struct Container {
    struct Elem *elems;
    s32 count;
    s32 capacity;
    struct Elem buf[8];
};

struct BigObj {
    struct Elem arr[9];
    char pad[0xC];
    struct Container container;
};

struct Glob {
    char f0[0xFC];
    char fFC[0xC];
    struct Container container;
};

struct Root {
    char pad[0xFC];
    char mid[0xC];
    struct Container c;
};

extern struct Root lbl_804872B0;
extern unsigned char lbl_8055AE2C;
extern unsigned char lbl_8055E9D0;
extern int lbl_8055E9D8;

#pragma scheduling invalid_target
void fn_801DF3BC(void) {
    register struct Root *root asm("r31") = &lbl_804872B0;
    struct Elem *p;
    struct Elem *end;

    fn_8000D838(&lbl_8055E9D0);
    lbl_8055E9D8 = 0x7F000000;
    fn_8002F53C(root, &fn_801DF6D0, 0, 0x1C, 9);

    root->c.elems = root->c.buf;
    root->c.count = 0;
    root->c.capacity = 8;
    end = root->c.buf + 8;

    p = root->c.buf;
    do {
        p->f4 = &lbl_8055AE2C;
        p->f8 = &lbl_8055AE2C;
        p->f18 = 0;
        p->f0 = 0;
        p->fC = 0;
        p->f10 = 0;
        p->f14 = -1;
        p++;
    } while (p < end);

    __register_global_object(&root->c, (void *)&fn_801DF678, &root->pad[0xFC]);
}
#pragma scheduling reset
