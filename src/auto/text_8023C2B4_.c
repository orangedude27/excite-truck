#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stdarg.h>

__declspec(section ".data") extern s32 lbl_803414C0;

typedef signed long s32;

int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */

typedef struct { s32 w[5]; } Fn8023C55C_Rec;

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
#pragma scheduling invalid_target
s32 fn_8023C308(s32 arg0) {
    s32 val, cur;
    u32 mode;
    s32 diff;
    if (arg0) {
        mode = (u32)(fn_80214D04() - 2) == 0;
        cur = lbl_8055F154;
        if (mode) {
            val = cur - 5;
            val = val & ~(val >> 31);
        } else {
            s32 tmp = cur + 5;
            if (tmp > 0x46)
                val = 0x46;
            else
                val = tmp;
        }
        diff = val - cur;
        lbl_8055F154 += diff;
        if (diff) fn_80214BE4(7, 0);
    }
    if (lbl_8055F148 != lbl_8055F150) {
        lbl_8055F150 = lbl_8055F148;
        ((void (*)(void *, ...))fn_802E30C8)(lbl_8055BB48);
        fn_802C82C4(lbl_8055F148);
    }
    if (lbl_8055F144 != lbl_8055F14C) {
        lbl_8055F14C = lbl_8055F144;
        fn_802090BC();
    }
    return 0;
}
#pragma scheduling on
s32 fn_80236914(void*); /* extern */
void fn_8023C55C(void*); /* extern */
int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */
extern char lbl_80341430[16];
extern char lbl_8034143C[16];
s32 fn_8023C3CC(void) {
    return 0;
}

extern s32 lbl_802FA068[];
extern s32 lbl_802FA07C[];
extern char lbl_803413C0[];
extern char lbl_8055BB50[4];
extern char lbl_8055BB58[4];
extern char lbl_8055BB60[4];
extern s32 lbl_80341448;
extern s32 fn_802C83C4(void);
extern s32 fn_80128670(s32);
extern s32 fn_802090CC(void);
extern s32 fn_80131234(char *);
extern void *fn_8023C800(register void *arg0, register s32 arg1, register s32 arg2, ...);
extern s32 lbl_80498788[];
extern s32 lbl_8055B860;
extern s32 lbl_8055BAB8;
extern s32 lbl_8055BAC0;
extern s32 fn_8023C2E4(void *);
extern s32 fn_80236914(void *);
extern void fn_8023C2B4(void);
extern s32 fn_8023C3CC(void);
extern void fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8023C3D4(void) {
    s32 data[46];
    s32 *v = lbl_802FA068;
    s32 *w = lbl_80498788;

    data[0] = v[0];
    data[1] = (s32)&data[6];
    data[2] = v[2];
    data[3] = v[3];
    data[4] = v[4];
    data[6] = (s32)&lbl_8055B860;
    data[7] = 6;
    data[8] = (s32)fn_8023C2E4;
    data[9] = 0x1B;
    data[10] = -1;
    data[11] = (s32)&lbl_8055B860;
    data[12] = 6;
    data[13] = (s32)fn_8023C3CC;
    data[14] = -10;
    data[15] = (s32)&lbl_8055B860;
    data[16] = 6;
    data[17] = (s32)fn_8023C3CC;
    data[18] = 10;
    data[19] = 0x128;
    data[20] = (s32)&lbl_8055B860;
    data[21] = 6;
    data[22] = (s32)fn_8023C3CC;
    data[23] = -1;
    data[24] = 0x125;
    data[25] = (s32)&lbl_8055B860;
    data[26] = 6;
    data[27] = (s32)fn_8023C3CC;
    data[28] = 1;
    data[29] = 0x127;
    data[30] = (s32)&lbl_8055BAB8;
    data[31] = 8;
    data[32] = (s32)fn_80236914;
    data[33] = 2;
    data[34] = 0;
    data[35] = (s32)&lbl_8055BAC0;
    data[36] = 8;
    data[37] = (s32)fn_8023C2B4;
    data[38] = 0;
    data[39] = 0;
    data[40] = 0;
    data[41] = w[0];
    data[42] = w[1];
    data[43] = w[2];
    data[44] = w[3];
    data[45] = w[4];
    fn_802146BC(data, -0x3E7, -0x3E7, 1, v[3], v[2], v[0], w[4]);
}

void fn_8023C55C(void *arg0) {
    char *base = lbl_803413C0;
    char obj1[0x1C];
    char obj2[0x1C];
    s32 hdr[5];
    s32 data[35];
    s32 *v;

    lbl_8055F148 = fn_802C83C4();
    lbl_8055F150 = lbl_8055F148;
    fn_8023C800(obj1, (s32)&lbl_8055F148, fn_80131234(base + 0x10), fn_80131234(base + 0x24), 0);
    lbl_8055F144 = fn_802090CC();
    lbl_8055F14C = lbl_8055F144;
    fn_8023C800(obj2, (s32)&lbl_8055F144, fn_80131234(base + 0x38), fn_80131234(base + 0x44), fn_80131234(base + 0x54), 0);

    data[0] = (s32)lbl_8055BB50;
    data[1] = 0x10;
    data[2] = 0;
    data[3] = (s32)obj1;
    data[4] = 0x10;
    data[5] = (s32)lbl_8055BB58;
    data[6] = 0x10;
    data[7] = 0;
    data[8] = (s32)obj2;
    data[9] = 0;
    data[10] = (s32)&lbl_8055B860;
    data[11] = 6;
    data[12] = (s32)fn_8023C2E4;
    data[13] = -1;
    data[14] = 0x1B;
    data[15] = (s32)lbl_8055BB60;
    data[16] = 0;
    data[17] = 0;
    data[18] = 3;
    data[19] = 0;
    data[20] = (s32)&lbl_8055BAB8;
    data[21] = 8;
    data[22] = (s32)fn_80236914;
    data[23] = 2;
    data[24] = 0;
    data[25] = (s32)&lbl_8055BAC0;
    data[26] = 8;
    data[27] = (s32)fn_8023C2B4;
    data[28] = 0;
    data[29] = 0;
    data[30] = lbl_80498788[0];
    data[31] = lbl_80498788[1];
    data[32] = lbl_80498788[2];
    data[33] = lbl_80498788[3];
    data[34] = lbl_80498788[4];
    v = lbl_802FA07C;
    hdr[0] = v[0];
    hdr[2] = v[2];
    hdr[3] = v[3];
    hdr[4] = v[4];
    hdr[0] = (s32)arg0;
    hdr[1] = (s32)data;
    lbl_8055F154 = 0;
    while (((s32 (*)(s32 *, s32, s32, s32))fn_802146BC)(hdr, -0x3E7, -0x3E7, 1) == 3) {
        fn_8023C3D4();
    }
    fn_8023C308(0);
    *(s32 **)(obj2 + 0xC) = &lbl_80341448;
    fn_80128670(*(s32 *)(obj2 + 0x10));
    *(s32 **)(obj1 + 0xC) = &lbl_80341448;
    fn_80128670(*(s32 *)(obj1 + 0x10));
}

#pragma pop
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

extern void *fn_8012850C(s32, s32 *);
#pragma push
#pragma scheduling invalid_target
void *fn_8023C800(register void *obj, register s32 value, register s32 firstItem, ...) {
  va_list ap;
  s32 offset;
  /* Initialize a variadic item-list object: set vtable, count items until 0 sentinel, allocate and copy them, and store value. */
  *(unsigned char *)obj = 0;
  *(s32 *)((char *)obj + 4) = -1;
  *(unsigned char *)((char *)obj + 8) = 0;
  *(s32 **)((char *)obj + 0xC) = &lbl_80341448;
  va_start(ap, firstItem);
  *(s32 *)((char *)obj + 0x14) = 0;
  do {
    (*(s32 *)((char *)obj + 0x14))++;
  } while (va_arg(ap, s32) != 0);
  va_end(ap);
  *(s32 **)((char *)obj + 0x10) = fn_8012850C(*(s32 *)((char *)obj + 0x14) * 4, &lbl_803414C0);
  va_start(ap, firstItem);
  offset = 0;
  do {
    *(s32 *)((char *)*(s32 **)((char *)obj + 0x10) + offset) = firstItem;
    offset += 4;
    firstItem = va_arg(ap, s32);
  } while (firstItem != 0);
  va_end(ap);
  *(s32 *)((char *)obj + 0x18) = value;
  return obj;
}
#pragma pop

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

