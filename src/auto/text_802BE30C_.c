#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"

extern s32 fn_8012C370(s32, s32, s32, s32, s32, s32);
extern void fn_8012E96C(s32);
extern void fn_8012C4D8(void *);
extern void fn_802E317C(const char *, ...);
extern char lbl_8034AC68[];
extern char lbl_8034AC74[];
extern void *lbl_804C06E0[];
extern u8 lbl_8055FACC;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 field;
} FanEntry;

typedef struct {
    u32 index;
    u32 count;
} FanHeader;

extern void *fn_8012850C(s32, void *);
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

void fn_802BE38C(void) {
    void *buf;
    u32 name;
    u32 size;
    u32 length;
    u8 flag;
    u32 *data;
    u32 index;
    u32 n;
    u8 *p;
    u32 i;
    s32 j;

    name = (u32)lbl_8034AC68;
    fn_8012E96C(name);
    lbl_8055FACC = 0;
    buf = (void *)fn_8012C370(name, 0x46494E46, (s32)&size, (s32)&length, 0, (s32)&flag);
    if (buf != NULL) {
        if (size == 2) {
            data = (u32 *)buf;
            if (flag != 0) {
                p = (u8 *)buf;
                for (i = 0; i < (length >> 2); i++) {
                    u8 t = p[0];
                    p[0] = p[3];
                    p[3] = t;
                    t = p[1];
                    p[1] = p[2];
                    p[2] = t;
                    p += 4;
                }
            }
            while (((FanHeader *)data)->index != 0) {
                FanHeader *h = (FanHeader *)data;
                n = h->count;
                index = h->index;
                data += 2;
                for (j = 0; j < (s32)n; j++) {
                    FanEntry *e = (FanEntry *)lbl_804C06E0[index] + j;
                    e->field = (e->field & 0xFF800200) | (*data & 0x7FFDFF);
                    data++;
                }
            }
            lbl_8055FACC = 1;
        } else {
            fn_802E317C(lbl_8034AC74);
        }
        fn_8012C4D8(buf);
    }
}
extern void *fn_8012850C(s32, void *);
extern s32 fn_802BE378(s32);
extern void fn_802BE364(void *);
extern s32 fn_802BE7C4(s32, s32, s32);
extern char lbl_8034AC90[];
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802BE694(void) {
    s32 size;
    s32 off;
    u32 i;
    s32 j;
    for (i = 4; i < 0x41U; i <<= 1) {
        size = fn_802BE378((s16)i);
        lbl_804C06E0[i] = fn_8012850C(size * 0xC, lbl_8034AC90);
        for (j = 0, off = 0; j < size; off += 0xC, j++) {
            fn_802BE364((char *)lbl_804C06E0[i] + off);
        }
    }
    fn_802BE38C();
}
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma dont_inline off
extern void fn_802BE780(void *);
void fn_802BE72C(void) {
    u32 i;
    for (i = 4; i < 0x41U; i <<= 1) {
        fn_802BE780(&lbl_804C06E0[i]);
    }
}

void fn_802BE780(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

#pragma scheduling invalid_target
s32 fn_802BE7C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 denominator;
    s32 value;
    arg1 -= arg2;
    denominator = arg2 * 2;
    arg1 = (arg1 + 0x200) / denominator;
    value = 0x400 / denominator;
    arg0 = (arg0 - arg2 + 0x200) / denominator;
    return arg0 + arg1 * value;
}
#pragma scheduling on
void fn_802BE7F4(void) {}

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802BE7F8(void) {
    s32 flags;
    fn_802BE694();
    flags = 0x200;
    flags |= 0x84;
    lbl_804C07E4.ptr = lbl_8055FAC8;
    lbl_804C07E4.flags = flags | 0x800000;
    lbl_804C07E4.value = 0;
}
#pragma scheduling on
void fn_802BE840(void) { fn_802BE72C(); }

void *fn_802BE844(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 < -0x200 || arg0 >= 0x200 || arg1 < -0x200 || arg1 >= 0x200)
        return &lbl_804C07E4;
    return (char *)lbl_804C06E0[arg2] + fn_802BE7C4(arg0, arg1, arg2) * 0xC;
}

extern s32 fn_802BBD38(s16, s16, s32);
#pragma use_lmw_stmw off
void fn_802BE8B4(s16 arg0, s16 arg1, s32 arg2) {
    s32 counts[6];
    s32 *countPtr;
    s32 flags;
    s16 x;
    s16 y;
    s32 i;
    s32 value;
    s32 half;
    s32 xOffset;
    s32 yOffset;
    s32 best;
    void *entry;

    flags = 0;
    memset(counts, 0, 0x18);
    if (arg2 == 4) {
        x = arg0 - arg2;
        while (x <= arg0 + arg2) {
            y = arg1 - arg2;
            while (y <= arg1 + arg2) {
                i = 0;
                do {
                    value = fn_802BBD38(x, y, i);
                    counts[i] += value;
                    if (value != 0)
                        flags |= 1 << i;
                    i++;
                } while (i < 6);
                y += 2;
            }
            x += 2;
        }
    } else {
        half = (s32)(((u32)arg2 >> 31) + arg2) >> 1;
        i = 0;
        do {
            xOffset = (i & 1) ? half : -half;
            yOffset = (i & 2) ? half : -half;
            entry = fn_802BE844((s16)(arg0 + xOffset), (s16)(arg1 + yOffset), half);
            value = *(u32 *)((char *)entry + 8);
            i++;
            countPtr = counts + ((value >> 6) & 7);
            (*countPtr)++;
            flags |= value & 0x3f;
        } while (i < 4);
    }
    countPtr = counts;
    best = 0;
    if (countPtr[0] < countPtr[1])
        best = 1;
    if (countPtr[best] < countPtr[2])
        best = 2;
    if (countPtr[best] < countPtr[3])
        best = 3;
    if (countPtr[best] < countPtr[4])
        best = 4;
    if (countPtr[best] < countPtr[5])
        best = 5;
    entry = fn_802BE844(arg0, arg1, arg2);
    value = *(u32 *)((char *)entry + 8);
    value = (value & ~0x3fU) | flags;
    value &= ~0x1c0U;
    value |= best << 6;
    *(u32 *)((char *)entry + 8) = value;
}
#pragma use_lmw_stmw off
void fn_802BEAB0(void) {
    s16 size, y, x;
    s32 value, step;
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

extern f32 fn_801DCF48(s32, f32, f32);
extern f64 ceil(f64);
extern f64 lbl_80564D70;
extern f32 lbl_80564D50;
extern f32 lbl_80564D54;
extern f32 lbl_80564D5C;
extern f32 lbl_80564D58;
extern f64 lbl_80564D60;
extern f32 lbl_80564D68;
void fn_802BEB70(void) {
    s32 size;
    s32 start;
    s32 step;
    s16 x;
    s16 y;
    s32 *field;
    s32 raw;
    f64 convert_bias;
    f32 scale;
    f32 offset;
    f32 threshold;
    f32 correction;
    f32 subtract_value;
    f32 rounded;

    if (lbl_8055FACC != 0)
        return;

    convert_bias = lbl_80564D70;
    scale = lbl_80564D50;
    offset = lbl_80564D54;
    threshold = lbl_80564D5C;
    correction = lbl_80564D58;
    subtract_value = lbl_80564D68;
    size = 4;
    goto size_check;

size_loop:
    start = size - 0x200;
    x = (s16)start;
    step = size * 2;
    goto x_check;

x_loop:
    y = (s16)start;
    goto y_check;

y_loop:
    {
        void *cell = fn_802BE844(x, y, size);
        f32 height = fn_801DCF48(0, (f32)x * scale, (f32)y * scale) - offset;
        if (height < threshold)
            height -= correction;
        else
            height += correction;

        raw = *(s32 *)((char *)cell + 8);
        *(s32 *)((char *)cell + 8) = (raw & 0xFF803FFF) | ((s32)height << 14);

        rounded = (f32)ceil(lbl_80564D60) - subtract_value;
        raw = *(s32 *)((char *)cell + 8);
        *(s32 *)((char *)cell + 8) =
            (raw & 0xFFFFC3FF) | ((s32)rounded << 10);
    }

    y = (s16)(y + step);
y_check:
    if (y < 0x200)
        goto y_loop;

    x = (s16)(x + step);
x_check:
    if (x < 0x200)
        goto x_loop;

    size *= 2;
size_check:
    if (size <= 0x40)
        goto size_loop;

    fn_802BE7F4();
}

