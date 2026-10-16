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
