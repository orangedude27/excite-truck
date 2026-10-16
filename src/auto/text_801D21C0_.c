// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80438958[];
extern s32 lbl_8055E930;
extern s32 fn_801D2BF4(s32 *, s32 *);
extern void fn_802C6CF8(s32);
extern s32 fn_800241DC(s32 *, void *, s32, s32, void *);
extern void qsort(void *, s32, s32, void *);
extern void *fn_80131810(void);
extern void fn_80131818(void *);
extern void fn_801D25BC(void *, void *);
extern void fn_801D26C8(void *, void *);
extern void fn_801D2A24(void *);
extern s32 strncmp(char *, char *, s32);
extern char lbl_8055AC28[];
extern void *lbl_80338300;
extern void *lbl_8055ABE0;
extern void *lbl_8055AC18;
extern void *lbl_8055AC20;
extern f32 lbl_80562A90;

typedef struct UnkObj UnkObj;
typedef struct {
    char pad0[8];
    void *(*fn8)(void *);
    char pad1[4];
    void *(*child)(void *, s32);
    char pad2[0x0C];
    s32 (*fn1C)(void *, void *);
    char pad3[8];
    f32 (*fn28)(void *, void *, f32);
    char pad4[0x2C];
    void *(*fn5C)(void *, void *);
} Vt801D;
struct UnkObj { const Vt801D *vt; };

#pragma dont_inline on
void fn_801D2B94(void) {
    u8 *var_r31;
    s32 var_r30;
    s32 temp;
    var_r31 = lbl_80438958;
    var_r30 = 0;
    while (var_r30 < lbl_8055E930) {
        temp = *(s32 *)(var_r31 + 0x6C);
        if (temp != -1) {
            fn_802C6CF8(temp);
        }
        var_r31 += 0x4C4;
        var_r30 += 1;
    }
}
#pragma dont_inline off

s32 fn_801D2BF4(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

#pragma dont_inline on
void fn_801D2C04(void) {
    s32 cmp = (s32)fn_801D2BF4;
    s32 count = lbl_8055E930;
    qsort(lbl_80438958, count, 0x4C4, (void *)cmp);
}

s32 fn_801D2C20(s32 arg0) {
    s32 sp8;
    s32 cmp;
    s32 count;

    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    cmp = (s32)fn_801D2BF4;
    count = lbl_8055E930;
    return fn_800241DC(&sp8, lbl_80438958, count, 0x4C4, (void *)cmp);
}
#pragma dont_inline off

void fn_801D2210(void) {
    fn_801D2B94();
}
