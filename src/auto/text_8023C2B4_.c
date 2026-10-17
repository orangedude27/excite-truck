#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */

void fn_8023C2B4(void) {
    if (fn_8027AA48() == 0) {
        fn_80214A9C(0x1F);
    }
}

s32 fn_8023C2E4(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

s32 fn_80214D04(void);
s32 fn_80214BE4(s32, s32);
void fn_802E30C8(void *);
void fn_802C82C4(s32);
void fn_802090BC(void);
extern s32 lbl_8055F144, lbl_8055F148, lbl_8055F14C, lbl_8055F150, lbl_8055F154;
extern char lbl_8055BB48[];
__declspec(section ".sdata") extern char lbl_8055BB48[];
s32 fn_8023C308(s32 arg0) {
    s32 mode, cur, val, diff;
    if (arg0) {
        mode = (u32)(fn_80214D04() - 2) == 0;
        cur = lbl_8055F154;
        if (mode) {
            val = cur - 5;
            val = val & ~(val >> 31);
        } else {
            val = cur + 5;
            if (val > 0x46) val = 0x46;
        }
        diff = val - cur;
        lbl_8055F154 = cur + diff;
        if (diff) fn_80214BE4(7, 0);
    }
    if (lbl_8055F148 != lbl_8055F150) {
        lbl_8055F150 = lbl_8055F148;
        fn_802E30C8(lbl_8055BB48);
        fn_802C82C4(lbl_8055F148);
    }
    if (lbl_8055F144 != lbl_8055F14C) {
        lbl_8055F14C = lbl_8055F144;
        fn_802090BC();
    }
    return 0;
}

s32 fn_80236914(void*); /* extern */
void fn_8023C55C(void*); /* extern */
int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */
extern char lbl_80341430[16];
extern char lbl_8034143C[16];
s32 fn_8023C3CC(void) {
    return 0;
}

extern s32 fn_80128668();
extern s32 fn_80128670(s32);
extern s32 lbl_80341448;
__declspec(section ".data") extern s32 lbl_80341448;
void *__dt__Q28PSSystem7SeqHeapFv_8023C79C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 **)((char *)arg0 + 0xC) = &lbl_80341448;
        fn_80128670(*(s32 *)((char *)arg0 + 0x10));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_8023C94C(void) {
    fn_8023C55C(lbl_80341430);
}

void fn_8023C958(void) {
    fn_8023C55C(lbl_8034143C);
}

void fn_8023C964(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 *index = *(s32 **)((char *)arg0 + 0x18);
    *index = (count + *index - 1) % count;
}

void fn_8023C98C(void *arg0) {
    s32 *index = *(s32 **)((char *)arg0 + 0x18);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    *index = (*index + 1) % count;
}

s32 fn_8023C9B0(void *arg0) {
    return ((s32 *)*(char **)((char *)arg0 + 0x10))[*(s32 *)(*(char **)((char *)arg0 + 0x18))];
}

