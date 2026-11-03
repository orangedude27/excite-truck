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

extern struct BigObj lbl_804872B0;
extern unsigned char lbl_8055AE2C;
extern unsigned char lbl_8055E9D0;
extern int lbl_8055E9D8;

#define FIELD_PTR(base, offset) (*(void **)((char *)(base) + (offset)))
#define FIELD_S32(base, offset) (*(s32 *)((char *)(base) + (offset)))
#define FIELD_S8(base, offset) (*(s8 *)((char *)(base) + (offset)))

void fn_801DF3BC(void) {
    struct BigObj *base = &lbl_804872B0;
    struct Container *c;
    struct Elem *p;
    struct Elem *end;

    fn_8000D838(&lbl_8055E9D0);
    lbl_8055E9D8 = 0x7F000000;
    fn_8002F53C(base->arr, &fn_801DF6D0, 0, 0x1C, 9);

    c = &base->container;
    c->elems = c->buf;
    c->count = 0;
    c->capacity = 8;
    end = c->buf + 8;

    p = c->buf;
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

    __register_global_object(c, (void *)&fn_801DF678, (char *)base + 0xFC);
}
