#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern char lbl_804BD740[];
extern s32 lbl_804BD790;
extern f32 lbl_80564978;
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F8F1;
extern void fn_80128668(void*);
void* fn_802A8F94(void* arg0, s32 arg1) {
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

extern f32 fn_801EA0E8(f32, f32);
#pragma scheduling invalid_target
void fn_802A8FEC(void *arg0, void *arg1) {
    f32 *dst = (f32 *)arg0;
    f32 *src = (f32 *)arg1;
    f32 y = src[1];
    dst[1] = fn_801EA0E8(src[0], y);
    dst[0] = src[0];
    dst[2] = y;
}
#pragma scheduling on
s32 fn_802A9048(void) {
    u32 value;
    s32 result;
    value = *((u32 *)fn_801E87A8() + 1);
    result = 0;
    if (value & 0x100) {
        value -= 0x180000;
        if (value != 0x303U && value != 0x304U)
            result = 1;
    }
    return result;
}

#pragma dont_inline on
extern u8 lbl_8055F8F8;
extern f32 lbl_8055F900;
extern f32 lbl_8055F908;
extern char lbl_80349D88[];
extern s32 fn_8012C33C(s32);
extern void fn_802A1120(void *, void *);
extern void fn_802A9090();
extern s32 fn_802C6FC0(s32, s32, s32);
extern s32 fn_802CAC28(void *, s32);
extern void fn_802A9574(void);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802A92CC(void) {
    f32 value1;
    f32 value0;
    u8 result;
    register s32 *entry;
    u32 i;

    result = (u8)fn_802A9048();
    lbl_8055F8F0 = result;
    if (result != 0) {
        fn_802A1120(&lbl_8055F8F8, &lbl_8055F908);
        value0 = *(volatile f32 *)&lbl_8055F908;
        value1 = *((volatile f32 *)&lbl_8055F908 + 1);
        *(volatile f32 *)&lbl_8055F900 = value0;
        entry = (s32 *)lbl_804BD740;
        *((volatile f32 *)&lbl_8055F900 + 1) = value1;
        i = 0;
        *(volatile f32 *)&lbl_8055F900 = value1;
        *((volatile f32 *)&lbl_8055F900 + 1) = -value0;
        do {
            if (fn_8012C33C(entry[0]) != 0)
                entry[1] = fn_802C6FC0(entry[0], 0, 0);
            i++;
            entry += 2;
        } while (i < 4U);
        fn_802A9090(&lbl_8055F8F8, &lbl_8055F908);
        lbl_8055F8F1 = 0;
        lbl_8055CC58 = fn_802CAC28(lbl_80349D88, 0);
        fn_802A9574();
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_802A93A4(void) {
    register s32 *p;
    register s32 value;
    register u32 i;
    if (lbl_8055F8F0 != 0) {
        p = (s32 *)lbl_804BD740;
        i = 0;
        do {
            value = p[1];
            if (value != -1) {
                fn_802C6CF8();
                p[1] = -1;
            }
            i++;
            p += 2;
        } while (i < 4);
        fn_802CAC54(lbl_8055CC58);
        lbl_8055CC58 = -2;
    }
}
#pragma scheduling on
extern char lbl_804BD6F8[];
extern f32 lbl_80564984;
extern f32 lbl_80564988;
extern s32 fn_801E85B4(void);
extern s32 fn_801E866C(s32);
extern void *fn_801EA9A0(void);
extern f32 fn_801E7E24(void);
extern void *fn_801E7E3C(void *);
extern void fn_802C744C(s32, void *);
void fn_802A9428(void) {
    s32 index;
    s32 kind;
    s32 value;
    s32 *entry;
    s32 *current;
    s32 selected;
    f32 elapsed;
    if (lbl_8055F8F0 == 0)
        return;
    selected = -1;
    index = fn_801E85B4();
    kind = fn_801E866C(-1);
    value = *(s32 *)((u8 *)fn_801EA9A0() + 0x1C);
    entry = (s32 *)((u8 *)&lbl_804BD6F8 + 0x98 + index * 16);
    if (kind != entry[0] || value < entry[2]) {
        entry[0] = kind;
        entry[1] = value;
        entry[2] = value;
        *(f32 *)(entry + 3) = lbl_80564978;
    } else if (value != entry[2]) {
        entry[1] = entry[2];
        entry[2] = value;
        *(f32 *)(entry + 3) = lbl_80564984;
    } else if (*(f32 *)(entry + 3) < lbl_80564988) {
        entry[1] = entry[2];
    } else {
        elapsed = fn_801E7E24();
        *(f32 *)(entry + 3) -= elapsed;
    }
    current = entry;
    selected = current[1];
    selected = ((s32 *)fn_801E7E3C(current))[2] <= selected ? 3 : selected;
    if (lbl_8055F8F1 != 0)
        selected = 3;
    else if ((u32)(current[1] + 1) < 4)
        selected = current[1];
    if (selected >= 0) {
        s32 *slot = (s32 *)((u8 *)&lbl_804BD6F8 + 0x48 + selected * 8);
        if (slot[1] != -1)
            fn_802C744C(slot[1], (u8 *)&lbl_804BD6F8 + 0x68);
    }
}

void fn_802A9574(void) {
    s32 *p = (s32 *)&lbl_804BD790;
    f32 f = lbl_80564978;
    p[2] = -1;
    p[1] = -1;
    p[0] = -1;
    *(f32 *)(p + 3) = f;
    p[6] = -1;
    p[5] = -1;
    p[4] = -1;
    *(f32 *)(p + 7) = f;
}

void fn_802A95A8(void) {
    fn_802A9090();
}

void fn_802A95AC(u8 arg0) {
    lbl_8055F8F1 = arg0;
}
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern s32 lbl_804BD790;
extern f32 lbl_80564978;
