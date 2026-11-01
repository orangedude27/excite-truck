#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { u32 a; u32 b; u32 c; u32 d; u32 e; } U;
extern U lbl_80498C30;
typedef struct { u32 a; u32 b; } E;
typedef struct { s32 id; u8 flag; E e[8]; } T;
extern T lbl_80498C48;
extern u32 lbl_8055F2D8;
extern u32 lbl_8055F2E0;
extern void fn_8000D838(void *);
void fn_802524D0(void) {
    E *p;
    E *end;
    fn_8000D838(&lbl_8055F2D8);
    *(u32 *)&lbl_80498C30 = 0;
    *((u32 *)&lbl_80498C30 + 2) = 0;
    *((u32 *)&lbl_80498C30 + 1) = 0x7b;
    *((u32 *)&lbl_80498C30 + 3) = 0;
    *((u32 *)&lbl_80498C30 + 4) = 0;
    lbl_8055F2E0 = 0x7f000000;
    lbl_80498C48.e[1].a = 0;
    lbl_80498C48.e[0].a = 0;
    lbl_80498C48.e[1].b = 2;
    lbl_80498C48.e[0].b = 2;
    end = &lbl_80498C48.e[8];
    for (p = &lbl_80498C48.e[2]; p < end; p += 2) {
        p[1].a = 0;
        p[0].a = 0;
        p[1].b = 2;
        p[0].b = 2;
    }
    lbl_80498C48.id = -1;
    lbl_80498C48.flag = 0;
}
