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
    u8 *p;
    u32 i;
    s32 j;
    u32 *data;
    u32 index;
    u32 n;

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
            while (data[0] != 0) {
                n = data[1];
                index = data[0];
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

extern s32 fn_802BBD38(s16, s16, s32);
void fn_802BE8B4(s16 arg0, s16 arg1, s32 arg2) {
    s32 sp8[6];
    s16 var_r21;
    s16 var_r22;
    s32 *var_r23;
    s32 temp_r24;
    s32 temp_r25;
    s32 temp_r3;
    s32 var_r0;
    s32 var_r20;
    s32 var_r20_2;
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;
    u32 temp_r0;
    void *temp_r3_2;

    var_r31 = 0;
    memset(sp8, 0, 0x18);
    if (arg2 == 4) {
        var_r22 = arg0 - arg2;
loop_10:
        if (var_r22 <= (s32)(arg0 + arg2)) {
            var_r21 = arg1 - arg2;
loop_8:
            if (var_r21 <= (s32)(arg1 + arg2)) {
                var_r23 = sp8;
                var_r20 = 0;
                do {
                    temp_r3 = fn_802BBD38(var_r22, var_r21, var_r20);
                    *var_r23 += temp_r3;
                    if (temp_r3 != 0)
                        var_r31 |= 1 << var_r20;
                    var_r20++;
                    var_r23++;
                } while (var_r20 < 6);
                var_r21 += 2;
                goto loop_8;
            }
            var_r22 += 2;
            goto loop_10;
        }
    } else {
        temp_r25 = (s32)(((u32)arg2 >> 31) + arg2) >> 1;
        temp_r24 = -temp_r25;
        var_r30 = 0;
        do {
            var_r3 = temp_r24;
            if (var_r30 & 1)
                var_r3 = temp_r25;
            var_r0 = temp_r24;
            if (var_r30 & 2)
                var_r0 = temp_r25;
            temp_r0 = *(u32 *)((char *)fn_802BE844((s16)(arg0 + var_r3),
                      (s16)(arg1 + var_r0), temp_r25) + 8);
            var_r30++;
            var_r31 |= temp_r0 & 0x3F;
            sp8[(temp_r0 >> 4) & 7]++;
        } while (var_r30 < 4);
    }
    var_r20_2 = 0;
    if (sp8[0] < sp8[1])
        var_r20_2 = 1;
    if (sp8[var_r20_2] < sp8[2])
        var_r20_2 = 2;
    if (sp8[var_r20_2] < sp8[3])
        var_r20_2 = 3;
    if (sp8[var_r20_2] < sp8[4])
        var_r20_2 = 4;
    if (sp8[var_r20_2] < sp8[5])
        var_r20_2 = 5;
    temp_r3_2 = fn_802BE844(arg0, arg1, arg2);
    *(u32 *)((char *)temp_r3_2 + 8) =
        ((*(u32 *)((char *)temp_r3_2 + 8) & ~0x3FU) | var_r31) & ~0x1C0U
        | (var_r20_2 << 6);
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

