#include <types.h>

extern s32 lbl_8055EFF4;
extern void **lbl_8055EFF8;
extern s32 lbl_8055EFFC;
extern void **lbl_8055F000;
extern char lbl_80340280[];
extern char lbl_80340290[];
extern void *fn_801284F8(u32, void *);
typedef void (*VFunc)(s32);
extern void *fn_8012A13C(void *, void *, u32, u32);
extern void *fn_8012A2D8(void **);
extern void fn_8012A364(void **, void *);
extern void fn_8012A570(u32, void *);
extern void fn_8012A5E8(void *);
extern s32 lbl_8055F004;
extern char lbl_803402A0[];
extern char lbl_803402F4[];
extern char lbl_80340308[];
extern void fn_802E317C(char *);
extern void fn_802E30C8(char *);
extern void fn_8022ED50(s32);
extern void fn_80128668(void *);
extern void *fn_8022EC7C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8022E9E0(void) {
    void *addr;
    void *p;
    if (lbl_8055EFF4 == 0) {
        addr = (void *)&lbl_80340280;
        p = fn_801284F8(0x20, addr);
        if (p) p = fn_8012A13C(p, lbl_80340280, 0x20, 8);
        lbl_8055EFF8 = (void **)p;
    }
    if (fn_8012A2D8(lbl_8055EFF8)) {
        s32 tmp = lbl_8055EFF4;
        lbl_8055EFF4 = tmp + 1;
    }
}

void fn_8022EA58(void *arg0) {
    void **p;
    fn_8012A364(lbl_8055EFF8, arg0);
    if (--lbl_8055EFF4 == 0) {
        p = lbl_8055EFF8;
        if (p) {
            ((VFunc *)*p)[2](1);
        }
        lbl_8055EFF8 = 0;
    }
}

void fn_8022EAB8(void) {
    if (lbl_8055EFFC == 0) {
        void *p = fn_801284F8(0x20, (void *)&lbl_80340290);
        if (p) p = fn_8012A13C(p, lbl_80340290, 0x20, 0x3C);
        lbl_8055F000 = (void **)p;
    }
    if (fn_8012A2D8(lbl_8055F000)) {
        s32 tmp = lbl_8055EFFC;
        lbl_8055EFFC = tmp + 1;
    }
}

void fn_8022EB30(void *arg0) {
    fn_8012A364(lbl_8055F000, arg0);
    if (--lbl_8055EFFC == 0) {
        if (lbl_8055F000) {
            ((VFunc *)*lbl_8055F000)[2](1);
        }
        lbl_8055F000 = 0;
    }
}

void fn_8022EB90(void) {
    s32 *p;
    if (lbl_8055F004) fn_802E317C(lbl_803402A0);
    p = (s32 *)fn_801284F8(8, lbl_803402F4);
    lbl_8055F004 = (s32)p;
    *p = 0;
    p[1] = p[0];
}

void fn_8022EBF0(void) {
    s32 *p = (s32 *)lbl_8055F004;
    if (p[1]) {
        fn_802E30C8(lbl_80340308);
        while (fn_8022EC7C()) fn_802ED50(p[1]);
        fn_8022EA58((void *)p[1]);
        p[1] = 0;
        p[0] = 0;
    }
    fn_80128668(p);
    lbl_8055F004 = 0;
}

void *fn_8022EC7C(void) {
    u32 *p = (u32 *)lbl_8055F004;
    u32 *node = (u32 *)p[0];
    u32 tail = p[1];
    if (!node) return 0;
    if ((u32)node == tail) return 0;
    while (node[1] != tail) node = (u32 *)node[1];
    return node;
}

void fn_8022ED00(void) {
    s32 *p;
    s32 *tail;
    p = (s32 *)fn_8022ECC0();
    tail = (s32 *)lbl_8055F004;
    if (tail[1] == 0) {
        tail[0] = (s32)p;
        tail[1] = tail[0];
    } else {
        ((s32 *)tail[1])[1] = (s32)p;
        tail[1] = (s32)p;
    }
}

void fn_8022ED50(s32 arg0) {
    void *node;
    node = fn_8022EC7C();
    if (node == 0) {
        ((s32 *)lbl_8055F004)[1] = 0;
        ((s32 *)lbl_8055F004)[0] = ((s32 *)lbl_8055F004)[1];
    } else {
        ((s32 *)node)[1] = 0;
        ((s32 *)lbl_8055F004)[1] = (s32)node;
    }
    fn_8022EA58((void *)arg0);
}

void fn_8022EDB8(void) {
    fn_8022ED50(((s32 *)lbl_8055F004)[1]);
}

s32 fn_8022EDC4(void) {
    s32 *p = (s32 *)((s32 *)lbl_8055F004)[1];
    if (p) return *p;
    return 0;
}

