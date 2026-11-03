// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int __register_global_object(void *, void *, void *);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801DF678(void);
extern void fn_801DF6D0(void);
extern char lbl_804872B0[];
extern unsigned char lbl_8055AE2C;
extern unsigned char lbl_8055E9D0;
extern int lbl_8055E9D8;

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

#define FIELD_PTR(base, offset) (*(void **)((char *)(base) + (offset)))
#define FIELD_S32(base, offset) (*(s32 *)((char *)(base) + (offset)))
#define FIELD_S8(base, offset) (*(s8 *)((char *)(base) + (offset)))

static inline void init_container(char *c, char *base) {
    char *buf = c + 0xC;
    char *p = buf + 0x1C;
    char *end = c + 0xEC;

    FIELD_PTR(base, 0x108) = buf;
    FIELD_S32(c, 4) = 0;
    end = c + 0xEC;
    FIELD_PTR(c, 0x10) = &lbl_8055AE2C;
    FIELD_S32(c, 8) = 8;
    FIELD_PTR(c, 0x14) = &lbl_8055AE2C;
    FIELD_S32(c, 0x24) = 0;
    FIELD_S8(c, 0xC) = 0;
    FIELD_S32(c, 0x18) = 0;
    FIELD_S32(c, 0x1C) = 0;
    FIELD_S32(c, 0x20) = -1;

    while (p < end) {
        FIELD_PTR(p, 4) = &lbl_8055AE2C;
        FIELD_PTR(p, 8) = &lbl_8055AE2C;
        FIELD_S32(p, 0x18) = 0;
        FIELD_S8(p, 0) = 0;
        FIELD_S32(p, 0xC) = 0;
        FIELD_S32(p, 0x10) = 0;
        FIELD_S32(p, 0x14) = -1;
        p += 0x1C;
    }
}

#pragma scheduling invalid_target
void fn_801DF3BC(void) {
    char *base;
    char *c;
    char *buf;
    char *p;
    char *end;

    base = lbl_804872B0;
    fn_8000D838(&lbl_8055E9D0);
    lbl_8055E9D8 = 0x7F000000;
    fn_8002F53C(base + 0, &fn_801DF6D0, 0, 0x1C, 9);

    c = base + 0x108;
    buf = c + 0xC;
    p = buf + 0x1C;
    FIELD_PTR(base, 0x108) = buf;
    FIELD_S32(c, 4) = 0;
    end = c + 0xEC;
    FIELD_PTR(c, 0x10) = &lbl_8055AE2C;
    FIELD_S32(c, 8) = 8;
    FIELD_PTR(c, 0x14) = &lbl_8055AE2C;
    FIELD_S32(c, 0x24) = 0;
    FIELD_S8(c, 0xC) = 0;
    FIELD_S32(c, 0x18) = 0;
    FIELD_S32(c, 0x1C) = 0;
    FIELD_S32(c, 0x20) = -1;

    while (p < end) {
        FIELD_PTR(p, 4) = &lbl_8055AE2C;
        FIELD_PTR(p, 8) = &lbl_8055AE2C;
        FIELD_S32(p, 0x18) = 0;
        FIELD_S8(p, 0) = 0;
        FIELD_S32(p, 0xC) = 0;
        FIELD_S32(p, 0x10) = 0;
        FIELD_S32(p, 0x14) = -1;
        p += 0x1C;
    }

    __register_global_object(base + 0x108, (void *)&fn_801DF678, base + 0xFC);
}
#pragma scheduling on
