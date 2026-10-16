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

void fn_8022EAB8(void) {
    if (lbl_8055EFFC == 0) {
        void *p = fn_801284F8(0x20, (void *)&lbl_80340290);
        if (p) p = fn_8012A13C(p, lbl_80340290, 0x20, 0x3C);
        lbl_8055F000 = (void **)p;
    }
    if (fn_8012A2D8(lbl_8055F000)) ++lbl_8055EFFC;
}
