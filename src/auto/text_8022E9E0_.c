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
            VFunc fn = ((VFunc *)*p)[2];
            fn(1);
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
            void **v = lbl_8055F000;
            VFunc fn = ((VFunc *)*v)[2];
            fn(1);
        }
        lbl_8055F000 = 0;
    }
}

