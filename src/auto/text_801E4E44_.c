// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

typedef struct {
    f32 x, y, z;
    s32 unk_0xC;
    f32 unk_0x10, unk_0x14;
} Unk801E4E44Vertex;

typedef struct {
    u8 unk_0x0[0x28];
    s32 unk_0x28, unk_0x2C, unk_0x30;
    f32 unk_0x34;
} Unk801E4E44State;

extern Unk801E4E44Vertex lbl_80487578[];
extern u16 lbl_80487B18[];
extern Unk801E4E44State lbl_80487C88;
extern s32 lbl_8055EAA8, lbl_8055EAAC, lbl_8055EAB0;
void fn_801E4E44(void);

s32 fn_801E4F20(void) {
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_8055EAB0 = 1;
    return 1;
}

s32 fn_801E4F3C(s32 arg0, s32 arg1, f32 x, f32 y, f32 z, f32 u, f32 v) {
    Unk801E4E44Vertex* vertex = &lbl_80487578[lbl_8055EAA8];
    vertex->x = x;
    lbl_8055EAA8++;
    vertex->y = y;
    vertex->z = z;
    vertex->unk_0x10 = u;
    vertex->unk_0x14 = v;
    vertex->unk_0xC = arg0;
    if (arg1 && lbl_8055EAA8 > 2) {
        lbl_80487B18[lbl_8055EAAC++] = lbl_8055EAA8 - 3;
        lbl_80487B18[lbl_8055EAAC++] = lbl_8055EAA8 - 2;
        lbl_80487B18[lbl_8055EAAC++] = lbl_8055EAA8 - 1;
    }
    if (lbl_8055EAA8 == 60 || lbl_8055EAAC == 174) fn_801E4E44();
    return 0;
}

void fn_801E4FF4(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

extern f32 lbl_80562D44, lbl_80562D48;
void fn_801E5174(f32 arg0, f32 arg1, f32 arg2) {
    s32 i, j;
    s32 base = lbl_8055EAA8;
    s32 next = base + 3;
    f32 *p = (f32 *)lbl_80487578;
    f32 *a, *b, *c, *d;
    if (base + 4 > 60) fn_801E4E44();
    if (lbl_8055EAAC + 6 > 174) fn_801E4E44();
    a = p + base * 6;
    b = a + 6;
    c = a + 12;
    d = a + 18;
    a[0] = arg0 - p[0x70C/4]; a[1] = arg1; a[2] = arg2;
    b[0] = arg0 + p[0x70C/4]; b[1] = arg1; b[2] = arg2;
    c[0] = a[0] + p[0x700/4]; c[1] = a[1] + p[0x704/4]; c[2] = a[2] + p[0x708/4];
    d[0] = b[0] + p[0x700/4]; d[1] = b[1] + p[0x704/4]; d[2] = b[2] + p[0x708/4];
    a[4] = c[4] = lbl_80562D44; b[4] = d[4] = lbl_80562D48;
    a[5] = c[5] = lbl_80562D48; b[5] = d[5] = lbl_80562D44;
    if (next > 2) {
        i = lbl_8055EAAC;
        lbl_80487B18[i] = next-3; lbl_80487B18[i+1] = next-2; lbl_80487B18[i+2] = next-1;
        lbl_8055EAAC = i+3;
    }
    lbl_8055EAA8 = next+1;
    if (next+1 > 2) {
        j = lbl_8055EAAC;
        lbl_80487B18[j] = next-2; lbl_80487B18[j+1] = next-1; lbl_80487B18[j+2] = next;
        lbl_8055EAAC = j+3;
    }
}

void fn_801E5348(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
s32 fn_801E5370(s32 arg0, s32 arg1, f32 arg2) {
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_80487C88.unk_0x2C = arg0;
    lbl_80487C88.unk_0x28 = 0;
    lbl_80487C88.unk_0x30 = arg1 + 1;
    lbl_80487C88.unk_0x34 = arg2;
    lbl_8055EAB0 = 3;
    return 1;
}
#pragma pop
void fn_801E58FC(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

