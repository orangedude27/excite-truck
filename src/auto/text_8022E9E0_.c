#include <types.h>

extern s32 lbl_8055EFF4;
extern void **lbl_8055EFF8;
extern s32 lbl_8055EFFC;
extern void **lbl_8055F000;
extern char lbl_80340280[];
extern char lbl_80340290[];
extern void *fn_801284F8(u32, void *);
typedef void (*VFunc)(s32);
struct Vtbl8022E { void *pad; VFunc dtor; };
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
extern f32 lbl_805635E0;
extern f32 lbl_805635E4;
extern void fn_80128668(void *);
extern void *fn_8022EC7C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8022E9E0(void) {
    if (lbl_8055EFF4 == 0) {
        void *p = fn_801284F8(0x20, (void *)&lbl_80340280);
        if (p) p = fn_8012A13C(p, lbl_80340280, 0x20, 8);
        lbl_8055EFF8 = (void **)p;
    }
    if (fn_8012A2D8(lbl_8055EFF8)) ++lbl_8055EFF4;
}

void fn_8022EA58(void *arg0) {
    fn_8012A364(lbl_8055EFF8, arg0);
    if (--lbl_8055EFF4 == 0) {
        if (lbl_8055EFF8) {
            ((void (**)(void *, int))*lbl_8055EFF8)[2](lbl_8055EFF8, 1);
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
    if (fn_8012A2D8(lbl_8055F000)) ++lbl_8055EFFC;
}

#pragma dont_inline on
void fn_8022EB30(void *arg0) {
    fn_8012A364(lbl_8055F000, arg0);
    if (--lbl_8055EFFC == 0) {
        if (lbl_8055F000) {
            ((void (*)(void *, int))(*(void ***)lbl_8055F000)[2])(lbl_8055F000, 1);
        }
        lbl_8055F000 = 0;
    }
}
#pragma dont_inline off
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
    u32 tail;
    if (!node) return 0;
    tail = p[1];
    if ((u32)node == tail) return 0;
    while (node[1] != tail) node = (u32 *)node[1];
    return node;
}

void fn_8022ED00(void) {
    s32 *p = (s32 *)fn_8022ECC0();
    if (((s32 *)lbl_8055F004)[1] == 0) {
        ((s32 *)lbl_8055F004)[0] = (s32)p;
        ((s32 *)lbl_8055F004)[1] = ((s32 *)lbl_8055F004)[0];
    } else {
        ((s32 *)((s32 *)lbl_8055F004)[1])[1] = (s32)p;
        ((s32 *)lbl_8055F004)[1] = (s32)p;
    }
}

#pragma dont_inline on
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
#pragma dont_inline reset

void fn_8022EDB8(void) {
    fn_8022ED50(((s32 *)lbl_8055F004)[1]);
}

s32 fn_8022EDC4(void) {
    s32 *p = (s32 *)((s32 *)lbl_8055F004)[1];
    if (p) return *p;
    return 0;
}

void fn_8022EE98(void *arg0) {
    fn_8022EB30(arg0);
}

extern f32 lbl_805635E0;
extern f32 lbl_805635E4;
extern void fn_8022EDE4(f32 *);
void fn_8022EE9C(void) {
    f32 a[12];
    a[0] = lbl_805635E0;
    a[1] = lbl_805635E4;
    a[2] = lbl_805635E4;
    a[3] = lbl_805635E4;
    a[4] = lbl_805635E0;
    a[5] = lbl_805635E4;
    a[6] = lbl_805635E4;
    a[7] = lbl_805635E4;
    a[8] = lbl_805635E0;
    a[9] = lbl_805635E4;
    a[10] = lbl_805635E4;
    a[11] = lbl_805635E4;
    fn_8022EDE4(a);
}

