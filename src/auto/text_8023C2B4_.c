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

/* Menu callback: hide UI group 0x1F when the nearby-racer score flag
 * (fn_8027AA48) is off, so that overlay is not left on screen. */
void fn_8023C2B4(void) {
    if (fn_8027AA48() == 0) {
        fn_80214A9C(0x1F);
    }
}

/* Sequence-event callback: clear the active display flag via fn_80236900, then report the event handled. */
s32 fn_8023C2E4(void *context) {
    fn_80236900(context);
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
s32 fn_8023C308(s32 allowAdjust) {
    /* Settings-menu tick: when allowed, nudge the 0..70 value lbl_8055F154 up/down
       by 5 (down when the active menu index is 2), clamping to 0..70 and notifying
       the UI on change; then propagate changed display-mode (lbl_8055F148/lbl_8055F150)
       and sound-mode (lbl_8055F144/lbl_8055F14C) settings to their handlers. */
    s32 newValue, currentValue, delta, decrease;
    if (allowAdjust) {
        decrease = (u32)(fn_80214D04() - 2) == 0;
        currentValue = lbl_8055F154;
        if (decrease) {
            newValue = currentValue - 5;
            newValue = newValue & ~(newValue >> 31);
        } else {
            s32 raised = currentValue + 5;
            if (raised > 0x46)
                newValue = 0x46;
            else
                newValue = raised;
        }
        delta = newValue - currentValue;
        lbl_8055F154 = lbl_8055F154 + delta;
        if (delta) ((void (*)(s32, s32, s32))fn_80214BE4)(7, 0, delta);
    }
    {
        s32 displayMode = lbl_8055F148;
        if (displayMode != lbl_8055F150) {
            lbl_8055F150 = displayMode;
            ((void (*)(void *, s32, ...))fn_802E30C8)(lbl_8055BB48, displayMode);
            fn_802C82C4(lbl_8055F148);
        }
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
    /* Default callback registered in the fn_8023C3D4 table: a no-op that always reports 0 (event not handled). */
    return 0;
}

extern s32 lbl_802FA068[];
extern s32 lbl_802FA07C[];
extern char lbl_803413C0[];
extern char lbl_8055BB50[4];
extern char lbl_8055BB58[4];
extern char lbl_8055BB60[4];
extern s32 lbl_80341448;
__declspec(section ".data") extern s32 lbl_80341448;
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
    data[9] = -1;
    data[10] = 0x1B;
    data[12] = 6;
    data[11] = (s32)&lbl_8055B860;
    data[13] = (s32)fn_8023C3CC;
    data[14] = -10;
    data[15] = 0x126;
    data[17] = 6;
    data[16] = (s32)&lbl_8055B860;
    data[18] = (s32)fn_8023C3CC;
    data[19] = 10;
    data[20] = 0x128;
    data[22] = 6;
    data[21] = (s32)&lbl_8055B860;
    data[23] = (s32)fn_8023C3CC;
    data[24] = -1;
    data[25] = 0x125;
    data[27] = 6;
    data[26] = (s32)&lbl_8055B860;
    data[28] = (s32)fn_8023C3CC;
    data[29] = 1;
    data[30] = 0x127;
    data[32] = 8;
    data[31] = (s32)&lbl_8055BAB8;
    data[33] = (s32)fn_80236914;
    data[34] = 2;
    data[35] = 0;
    data[37] = 8;
    data[36] = (s32)&lbl_8055BAC0;
    data[38] = (s32)fn_8023C2B4;
    data[39] = 0;
    data[40] = 0;
    data[41] = w[0];
    data[42] = w[1];
    data[43] = w[2];
    data[44] = w[3];
    data[45] = w[4];
    fn_802146BC(data, -0x3E7, -0x3E7, 1, v[3], v[2], v[0], w[4]);
}

#pragma scheduling invalid_target
void fn_8023C55C(void *arg0) {
    char obj1[0x1C];
    char obj2[0x1C];
    s32 hdr[5];
    s32 data[35];
    s32 *s = lbl_80498788;
    register s32 *v = lbl_802FA07C;

    lbl_8055F148 = fn_802C83C4();
    lbl_8055F150 = lbl_8055F148;
    fn_8023C800(obj1, (s32)&lbl_8055F148, fn_80131234(lbl_803413C0 + 0x10), fn_80131234(lbl_803413C0 + 0x24), 0);
    lbl_8055F144 = fn_802090CC();
    lbl_8055F14C = lbl_8055F144;
    fn_8023C800(obj2, (s32)&lbl_8055F144, fn_80131234(lbl_803413C0 + 0x38), fn_80131234(lbl_803413C0 + 0x44), fn_80131234(lbl_803413C0 + 0x54), 0);

    data[0] = (s32)lbl_8055BB50;
    data[3] = (s32)obj1;
    data[1] = 0x10;
    data[6] = 0x10;
    data[2] = 0;
    data[4] = 0x10;
    data[5] = (s32)lbl_8055BB58;
    data[7] = 0;
    data[8] = (s32)obj2;
    data[9] = 0;
    data[11] = 6;
    data[10] = (s32)&lbl_8055B860;
    data[12] = (s32)fn_8023C2E4;
    data[13] = -1;
    data[14] = 0x1B;
    data[16] = 0;
    data[15] = (s32)lbl_8055BB60;
    data[17] = 0;
    data[18] = 3;
    data[19] = 0;
    data[21] = 8;
    data[20] = (s32)&lbl_8055BAB8;
    data[22] = (s32)fn_80236914;
    data[23] = 2;
    data[24] = 0;
    data[26] = 8;
    data[25] = (s32)&lbl_8055BAC0;
    data[27] = (s32)fn_8023C2B4;
    data[28] = 0;
    data[29] = 0;
    data[30] = s[0];
    data[31] = s[1];
    data[32] = s[2];
    data[33] = s[3];
    data[34] = s[4];
    hdr[0] = v[0];
    hdr[2] = v[2];
    hdr[3] = v[3];
    hdr[4] = v[4];
    hdr[0] = (s32)arg0;
    hdr[1] = (s32)data;
    lbl_8055F154 = 0;
    while (1) {
        if (((s32 (*)(s32 *, s32, s32, s32))fn_802146BC)(hdr, -0x3E7, -0x3E7, 1) == 3)
            fn_8023C3D4();
        else
            break;
    }
    fn_8023C308(0);
    *(s32 **)(obj2 + 0xC) = &lbl_80341448;
    fn_80128670(*(s32 *)(obj2 + 0x10));
    *(s32 **)(obj1 + 0xC) = &lbl_80341448;
    fn_80128670(*(s32 *)(obj1 + 0x10));
}
extern s32 fn_80128668();
extern s32 fn_80128670(s32);
extern s32 lbl_80341448;
__declspec(section ".data") extern s32 lbl_80341448;
void *__dt__Q28PSSystem7SeqHeapFv_8023C79C(void *object, s32 deleting) {
    /* PSSystem::SeqHeap destructor: install vtable, release the owned heap buffer, and optionally delete the object. */
    if (object != 0) {
        *(s32 **)((char *)object + 0xC) = &lbl_80341448;
        fn_80128670(*(s32 *)((char *)object + 0x10));
        if (deleting > 0) {
            fn_80128668(object);
        }
    }
    return object;
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

/* Initialise the sound-sequence heap from the "audio.lyt" layout resource. */
void fn_8023C94C(void) {
    fn_8023C55C(lbl_80341430);
}

/* Initialise the sound-sequence heap/layout from the "display.lyt" layout resource. */
void fn_8023C958(void) {
    fn_8023C55C(lbl_8034143C);
}

// Steps a sound-sequence's first cursor back by one entry, wrapping around:
// +0x14 is the entry count and +0x18 points at the cursor variable.
void fn_8023C964(void *sequence) {
    s32 count = *(s32 *)((char *)sequence + 0x14);
    s32 *index = *(s32 **)((char *)sequence + 0x18);
    *index = (count + *index - 1) % count;
}

// Steps a sound-sequence's first cursor forward by one entry, wrapping around:
// +0x14 is the entry count and +0x18 points at the cursor variable.
void fn_8023C98C(void *sequence) {
    s32 *index = *(s32 **)((char *)sequence + 0x18);
    s32 count = *(s32 *)((char *)sequence + 0x14);
    *index = (*index + 1) % count;
}

// Return the item in the sequence's +0x10 table at its current cursor index (+0x18).
s32 fn_8023C9B0(void *sequence) {
    return ((s32 *)*(char **)((char *)sequence + 0x10))[*(s32 *)(*(char **)((char *)sequence + 0x18))];
}

