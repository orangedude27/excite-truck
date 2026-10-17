#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F834[];
extern int lbl_8055CB68;
extern int fn_80128670(int);
extern int fn_801EF024(int (*)(void *));
extern void fn_802CAC54(int);
extern void fn_80128668(void*);
void* fn_802A08E8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802A0940(void) {
}

s32 fn_802A0944(void *arg0) {
    s32 index;
    u32 *src;
    u32 *dst;
    u32 *record;
    index = *(s32 *)arg0;
    if (index == 1)
        index = 0x3F - *((s32 *)arg0 + 1);
    else
        index = *((s32 *)arg0 + 1);
    record = (u32 *)(lbl_8055F834 + index * 0x54);
    *record = *(u32 *)arg0;
    record[1] = *((u32 *)arg0 + 1);
    record[2] = *((u32 *)arg0 + 2);
    src = (u32 *)((u8 *)arg0 + 0xC);
    dst = record + 3;
    do {
        *dst++ = *src++;
        *dst++ = *src++;
    } while (src < (u32 *)((u8 *)arg0 + 0x54));
    return 0x54;
}

void fn_802A0AF8(void) {
}

void fn_802A0B50(void) {
}

#include <types.h>
extern u8 lbl_8055F834[];
