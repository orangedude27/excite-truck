#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"

extern s32 fn_8012C370(s32, s32, s32, s32, s32, s32);
extern void fn_8012E96C(s32);
extern void fn_8012C4D8(void *);
extern void fn_802E317C(const char *, ...);
extern void *lbl_8034AC68;
extern void *lbl_8034AC74;
extern void *lbl_804C06E0[];
extern u8 lbl_8055FACC;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void*);
extern void fn_802BE694(void);
extern void fn_802BE72C(void);
extern void *lbl_8055FAC8;
extern struct {
    void *ptr;
    s32 value;
    s32 flags;
} lbl_804C07E4;
void* fn_802BE30C(void* arg0, s32 arg1) {
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

void fn_802BE364(void *arg0) {
    *(s32 *)((char *)arg0 + 4) = 0;
    *(s32 *)((char *)arg0 + 0) = 0;
    *(s32 *)((char *)arg0 + 8) = 0;
}

s32 fn_802BE378(s32 arg0) {
    s32 temp = 0x400 / (arg0 * 2);
    return temp * temp;
}

extern void *fn_8012850C(s32, void *);
extern s32 fn_802BE378(s32);
extern void fn_802BE364(void *);
extern s32 fn_802BE7C4(s32, s32, s32);
extern void *lbl_8034AC90;
extern void *lbl_804C06E0[];
extern u8 lbl_8055FACC;
void fn_802BE694(void) {
    s32 size;
    s32 i;
    s32 j;
    for (i = 4; i < 0x41; i <<= 1) {
        size = fn_802BE378(i);
        lbl_804C06E0[i] = fn_8012850C(size * 0xC, &lbl_8034AC90);
        for (j = 0; j < size; j++)
            fn_802BE364((char *)lbl_804C06E0[i] + j * 0xC);
    }
}

void fn_802BE780(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

s32 fn_802BE7C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    s32 scale;
    s32 value;
    result = arg0 - arg2;
    scale = arg2 * 2;
    result = (result + 0x200) / scale;
    value = 0x400 / scale;
    arg1 = (arg1 - arg2 + 0x200) / scale;
    return arg1 + result * value;
}

void fn_802BE7F4(void) {}

void fn_802BE7F8(void) {
    s32 flags = 0x200;
    flags |= 0x84;
    fn_802BE694();
    lbl_804C07E4.ptr = lbl_8055FAC8;
    lbl_804C07E4.flags = flags | 0x800000;
    lbl_804C07E4.value = 0;
}

void fn_802BE840(void) { fn_802BE72C(); }

void *fn_802BE844(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 < -0x200 || arg0 >= 0x200 || arg1 < -0x200 || arg1 >= 0x200)
        return &lbl_804C07E4;
    return (char *)lbl_804C06E0[arg2] + fn_802BE7C4(arg0, arg1, arg2) * 0xC;
}

void fn_802BEAB0(void) {
    s16 x, y, size;
    s32 step, value;
    void *p;
    if (lbl_8055FACC == 0) {
        for (size = 4; size <= 0x40; size <<= 1) {
            x = size - 0x200;
            step = size * 2;
            for (; x < 0x200; x += step) {
                for (y = size - 0x200; y < 0x200; y += step) {
                    fn_802BE844(x, y, size);
                    p = fn_802BE844(x, y, size);
                    value = *(s32 *)((char *)p + 8);
                    *(s32 *)((char *)p + 8) = (((value & ~0x3F) | 2) & ~0x1C0) | 0x40;
                }
            }
        }
    }
}

