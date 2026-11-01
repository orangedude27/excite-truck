#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u32 lbl_80498C30;
typedef struct { u32 a; u32 b; } E;
typedef struct { s32 id; u8 flag; E e[8]; } T;
extern T lbl_80498C48;
extern u32 lbl_8055F2D8;
extern u32 lbl_8055F2E0;
extern void fn_8000D838(void *);
void fn_802524D0(void) {
    u32 *p, *end, *q;
    s32 n, t;
    fn_8000D838(&lbl_8055F2D8);
    *(u32 *)&lbl_80498C30 = 0;
    *((u32 *)&lbl_80498C30 + 2) = 0;
    *((u32 *)&lbl_80498C30 + 1) = 0x7b;
    *((u32 *)&lbl_80498C30 + 3) = 0;
    *((u32 *)&lbl_80498C30 + 4) = 0;
    lbl_8055F2E0 = 0x7f000000;
    p = (u32 *)((u8 *)&lbl_80498C48 + 0x18);
    end = (u32 *)((u8 *)&lbl_80498C48 + 0x48);
    *((u32 *)&lbl_80498C48 + 4) = 0;
    *((u32 *)&lbl_80498C48 + 2) = 0;
    *((u32 *)&lbl_80498C48 + 5) = 2;
    *((u32 *)&lbl_80498C48 + 3) = 2;
    if (p < end) {
        n = ((u8 *)end - (u8 *)p + 0xf) >> 4;
        q = (u32 *)((u8 *)&lbl_80498C48 - 0x38);
        if (n > 8) {
            t = 0;
            if (p <= end && (((u8 *)end - (u8 *)p) >= 0) && (((u8 *)end - (u8 *)p) & 1))
                t = 1;
            if (t && ((n & 1) || ((n + 1) & 1))) {
                u32 count = ((u32)((u8 *)q + 0x7f - (u8 *)p)) >> 7;
                while (p < q) {
                    p[2]=0; p[0]=0; p[3]=2; p[1]=2; p[6]=0; p[4]=0; p[7]=2; p[5]=2;
                    p[10]=0; p[8]=0; p[11]=2; p[9]=2; p[14]=0; p[12]=0; p[15]=2; p[13]=2;
                    p[18]=0; p[16]=0; p[19]=2; p[17]=2; p[22]=0; p[20]=0; p[23]=2; p[21]=2;
                    p[26]=0; p[24]=0; p[27]=2; p[25]=2; p[30]=0; p[28]=0; p[31]=2; p[29]=2;
                    p += 32; --count;
                }
            }
        }
        end = (u32 *)((u8 *)&lbl_80498C48 + 0x48);
        while (p < end) { p[2]=0; p[0]=0; p[3]=2; p[1]=2; p += 4; }
    }
    *(u32 *)&lbl_80498C48 = -1;
    *((u8 *)&lbl_80498C48 + 4) = 0;
}
