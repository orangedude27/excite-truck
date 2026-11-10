#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern char lbl_804BD740[];
typedef struct { s32 a, b, c; f32 d; } Unk804BD790;
extern Unk804BD790 lbl_804BD790[2];
extern f32 lbl_80564978;
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F8F1;
extern char lbl_804BD6F8[];
extern f32 lbl_80564970, lbl_80564974, lbl_8056497C, lbl_80564980;
extern void fn_802C77F0(void *, f32 *);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern void PSVECNormalize(f32 *, f32 *);
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
#pragma push
#pragma processor 750
void fn_802A8FEC(void *arg0, void *arg1) {
    f32 y = ((f32 *)arg1)[1];
    f32 *dst = (f32 *)arg0;
    f32 *src = (f32 *)arg1;
    dst[1] = fn_801EA0E8(src[0], y);
    dst[0] = src[0];
    dst[2] = y;
}
#pragma pop
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
void fn_802A9090(f32 *pos, f32 *dir) {
    struct V2 { f32 x, y; };
    f32 *g = (f32 *)lbl_804BD6F8;
    f32 *m;
    f32 w[6];
    f32 c[3];
    f32 d[3];
    f32 r[2];
    f32 a[2];
    f32 b[2];
    f32 s, ns, f9, p0, p1, t0, t1;
    *(struct V2 *)r = *(struct V2 *)dir;
    ns = -r[0];
    r[0] = r[1];
    r[1] = ns;
    if (*(s32 *)(lbl_804BD6F8 + 0x4C) != -1) {
        fn_802C77F0(*(void **)(lbl_804BD6F8 + 0x4C), w);
        s = w[1] - w[0];
    } else {
        s = lbl_80564970;
    }
    ns = -s;
    p0 = pos[0];
    p1 = pos[1];
    t0 = r[0] * ns;
    t1 = r[1] * ns;
    a[0] = p0 + t0;
    a[1] = p1 + t1;
    b[0] = p0 + r[0] * s;
    b[1] = p1 + r[1] * s;
    fn_802A8FEC(c, a);
    g[0] = c[0];
    g[1] = c[1];
    g[2] = c[2];
    fn_802A8FEC(d, b);
    m = g + 0x68 / 4;
    {
        f32 x = g[0] + d[0], y = g[1] + d[1], z = g[2] + d[2];
        f9 = g[1];
        m[0x24 / 4] = x;
        m[0x28 / 4] = y;
        m[0x2C / 4] = z;
        g[3] = d[0];
        g[4] = d[1];
        g[5] = d[2];
        m[0x24 / 4] = x * lbl_80564974;
        m[0x28 / 4] = y * lbl_80564974;
        m[0x2C / 4] = z * lbl_80564974;
    }
    if (f9 > d[1]) {
    } else {
        f9 = d[1];
    }
    m = g + 0x68 / 4;
    {
        f32 dx = g[3] - g[0], dy = g[4] - g[1], dz = g[5] - g[2];
        m[1] = dy;
        m[0x28 / 4] = f9;
        m[0] = dx;
        m[2] = dz;
        m[1] = lbl_80564978;
        m[3] = lbl_80564978;
        m[4] = lbl_8056497C;
        m[5] = lbl_80564978;
    }
    PSVECCrossProduct(m, m + 3, m + 6);
    PSVECNormalize(m, m);
    PSVECNormalize(m + 6, m + 6);
    PSVECCrossProduct(m + 6, m, m + 3);
    if (*(u32 *)((char *)fn_801E87A8() + 0x10) & 2) {
        m[0] *= lbl_80564980;
        m[1] *= lbl_80564980;
        m[2] *= lbl_80564980;
    }
}
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
#pragma scheduling off
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
        value0 = lbl_8055F908;
        value1 = *(((volatile f32 *)&lbl_8055F908) + 1);
        *(volatile f32 *)&lbl_8055F900 = value0;
        *(((volatile f32 *)&lbl_8055F900) + 1) = value1;
        entry = (s32 *)lbl_804BD740;
        i = 0;
        *(volatile f32 *)&lbl_8055F900 = value1;
        *(((volatile f32 *)&lbl_8055F900) + 1) = -value0;
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
    s32 *p;
    s32 value;
    u32 i;
    if (lbl_8055F8F0 != 0) {
        p = (s32 *)lbl_804BD740;
        i = 0;
        do {
            value = p[1];
            if (value != -1) {
                fn_802C6CF8(value);
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
    volatile u8 enabled = lbl_8055F8F0;
    register char *base = lbl_804BD6F8;
    char *entries;
    register s32 index;
    register s32 kind;
    s32 value;
    s32 *entry;
    s32 *current;
    register s32 selected;
    f32 elapsed;

    entries = base + 0x98;
    if (enabled == 0)
        return;

    selected = -1;
    index = fn_801E85B4();
    kind = fn_801E866C(-1);
    value = *(s32 *)((u8 *)fn_801EA9A0() + 0x1C);
    entry = (s32 *)(entries + index * 16);
    if (kind != ((s32 *)entries)[index * 4] || value < ((s32 *)entries)[index * 4 + 2]) {
        entry[0] = kind;
        entry[1] = value;
        entry[2] = value;
        *(f32 *)(entry + 3) = lbl_80564978;
    } else if (value != ((s32 *)entries)[index * 4 + 2]) {
        entry[1] = entry[2];
        entry[2] = value;
        *(f32 *)(entry + 3) = lbl_80564984;
    } else if (*(f32 *)(entry + 3) < lbl_80564988) {
        entry[1] = entry[2];
    } else {
        elapsed = fn_801E7E24();
        *(f32 *)(entry + 3) -= elapsed;
    }

    current = (s32 *)fn_801E7E3C(entry);
    index = entry[1];
    if (lbl_8055F8F1 == 0 && index >= current[2])
        selected = 3;
    else if ((u32)(index + 1) < 4)
        selected = index;

    if (selected >= 0) {
        s32 *slot = (s32 *)(base + 0x48 + selected * 8);
        if (slot[1] != -1)
            fn_802C744C(slot[1], base + 0x68);
    }
}

void fn_802A9574(void) {
    Unk804BD790 *p = lbl_804BD790;
    f32 f = lbl_80564978;
    s32 i;
    for (i = 0; i < 2; i++) {
        p[i].c = -1;
        p[i].b = -1;
        p[i].a = -1;
        p[i].d = f;
    }
}

void fn_802A95A8(void) {
    fn_802A9090();
}

void fn_802A95AC(u8 arg0) {
    lbl_8055F8F1 = arg0;
}
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern f32 lbl_80564978;
