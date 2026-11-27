#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern char lbl_804BD740[];
typedef struct { s32 a, b, c; f32 d; } Unk804BD790;
__declspec(section ".data") extern Unk804BD790 lbl_804BD790[2];
extern f32 lbl_80564978;
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F8F1;
extern char lbl_804BD6F8[];
extern f32 lbl_80564970, lbl_80564974, lbl_8056497C, lbl_80564980;
extern void MRModel_GetBoundingBoxArray(void *, f32 *);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern void PSVECNormalize(f32 *, f32 *);
extern void fn_80128668(void*);
void *fn_802A8F94(void *obj, s32 shouldFree) {
    /* Clear a 3-word object and optionally free it. */
    if (obj != 0) {
        if (obj != 0) {
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (shouldFree > 0)
            fn_80128668(obj);
    }
    return obj;
}

extern f32 fn_801EA0E8(f32, f32);
#pragma scheduling invalid_target
#pragma processor 750
void fn_802A8FEC(void *arg0, void *arg1) {
    f32 *dst = (f32 *)arg0;
    const f32 *src = (const f32 *)arg1;
    f32 y = src[1];
    f32 r = fn_801EA0E8(src[0], y);
    f32 x2 = src[0];
    dst[1] = r;
    dst[0] = x2;
    dst[2] = y;
}
s32 fn_802A9048(void) {
    /* Returns nonzero when the flag at bit 8 of the mode word (offset +4 of
     * fn_801E87A8()) is set and the mode ID, after subtracting 0x180000, is
     * neither 0x303 nor 0x304. */
    u32 modeWord;
    s32 isMatch;

    modeWord = *((u32 *)fn_801E87A8() + 1);
    isMatch = 0;
    if (modeWord & 0x100) {
        modeWord -= 0x180000;
        if (modeWord != 0x303U && modeWord != 0x304U) {
            isMatch = 1;
        }
    }
    return isMatch;
}

#pragma dont_inline on
void fn_802A9090(f32 *pos, f32 *dir)
{
  struct V2
  {
    f32 x;
    f32 y;
  };
  f32 *g = (f32 *) lbl_804BD6F8;
  f32 *m;
  f32 w[6];
  f32 c[3];
  f32 d[3];
  f32 r[2];
  f32 a[2];
  f32 b[2];
  f32 s;
  f32 ns;
  f32 f9;
  f32 p0;
  f32 p1;
  f32 t1;
  f32 t0;
  f32 dx = dir[0];
  f32 dy = dir[1];
  r[0] = dx;
  r[1] = dy;
  ns = -r[0];
  r[0] = r[1];
  r[1] = ns;
  if ((*((s32 *) (lbl_804BD6F8 + 0x4C))) != ((-1) & 0xFFFFu))
  {
    MRModel_GetBoundingBoxArray(*((void **) (lbl_804BD6F8 + 0x4C)), w);
    if (1)
    {
    }
    s = w[1] - w[0];
  }
  else
  {
    s = lbl_80564970;
  }
  ns = -s;
  p0 = pos[0];
  p1 = pos[1];
  t0 = r[0] * ns;
  t1 = r[1] * ns;
  a[0] = p0 + t0;
  a[1] = p1 + t1;
  b[0] = p0 + (r[0] * s);
  b[1] = p1 + (r[1] * s);
  fn_802A8FEC(c, a);
  ((f32 *) lbl_804BD6F8)[0] = c[0];
  g[1] = c[1];
  g[2] = c[2];
  fn_802A8FEC(d, b);
  m = ((f32 *) lbl_804BD6F8) + (0x68 / 4);
  {
    f32 x = g[0] + d[0];
    f32 y = g[1] + d[1];
    f32 z = g[2] + d[2];
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
  if (f9 > d[1])
  {
  }
  else
  {
    f9 = d[1];
  }
  m = g + (0x68 / 4);
  {
    f32 dx2 = g[3] - g[0];
    f32 dy2 = g[4] - g[1];
    f32 dz = ((0, g[5])) - ((0, g[2]));
    m[1] = dy2;
    m[0x28 / 4] = f9;
    m[0] = dx2;
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
  if ((*((u32 *) (((char *) fn_801E87A8()) + 0x10))) & 2)
  {
    m[0] *= lbl_80564980;
    m[1] *= lbl_80564980;
    m[2] *= lbl_80564980;
  }
}
extern u8 lbl_8055F8F8;
extern volatile f32 lbl_8055F900[2];
extern volatile f32 lbl_8055F908[2];
extern char lbl_80349D88[];
extern s32 fn_8012C33C(s32);
extern void findDecalTrackCrossing(void *, void *);
extern void fn_802A9090();
extern s32 fn_802C6FC0(s32, s32, s32);
extern s32 RegisterTextureByName(void *, s32);
extern void fn_802A9574(void);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802A92CC(void) {
    f32 value1;
    f32 value0;
    u8 result;
    s32 *entry;
    u32 i;

    result = (u8)fn_802A9048();
    lbl_8055F8F0 = result;
    if (result != 0) {
        findDecalTrackCrossing(&lbl_8055F8F8, (void *)lbl_8055F908);
        value0 = lbl_8055F908[0];
        value1 = lbl_8055F908[1];
        lbl_8055F900[0] = value0;
        lbl_8055F900[1] = value1;
        lbl_8055F900[0] = value1;
        lbl_8055F900[1] = -value0;
        entry = (s32 *)lbl_804BD740;
        i = 0;
        do {
            if (fn_8012C33C(entry[0]) != 0)
                entry[1] = fn_802C6FC0(entry[0], 0, 0);
            i++;
            entry += 2;
        } while (i < 4U);
        fn_802A9090(&lbl_8055F8F8, (void *)lbl_8055F908);
        lbl_8055F8F1 = 0;
        lbl_8055CC58 = RegisterTextureByName(lbl_80349D88, 0);
        fn_802A9574();
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_802A93A4(void) {
    /* Release all four active model-slot references and clear the cached texture id. */
    s32 *slot;
    s32 ref;
    u32 i;
    if (lbl_8055F8F0 != 0) {
        slot = (s32 *)lbl_804BD740;
        i = 0;
        do {
            ref = slot[1];
            if (ref != -1) {
                fn_802C6CF8(ref);
                slot[1] = -1;
            }
            i++;
            slot += 2;
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
extern void MRModel_SetInstanceTransform(s32, void *);
#pragma push
#pragma use_lmw_stmw off
void fn_802A9428(void) {
    char *base = lbl_804BD6F8;
    s32 index, kind, value, selected;
    s32 *current;
    f32 elapsed;
    if (lbl_8055F8F0 == 0)
        return;
    selected = -1;
    index = fn_801E85B4();
    kind = fn_801E866C(-1);
    value = *(s32 *)((u8 *)fn_801EA9A0() + 0x1C);
    if (kind != ((Unk804BD790 *)(base + 0x98))[index].a ||
        value < ((Unk804BD790 *)(base + 0x98))[index].c) {
        ((Unk804BD790 *)(base + 0x98))[index].d = lbl_80564978;
        ((Unk804BD790 *)(base + 0x98))[index].a = kind;
        ((Unk804BD790 *)(base + 0x98))[index].b = value;
        ((Unk804BD790 *)(base + 0x98))[index].c = value;
    } else if (value != ((Unk804BD790 *)(base + 0x98))[index].c) {
        ((Unk804BD790 *)(base + 0x98))[index].b = ((Unk804BD790 *)(base + 0x98))[index].c;
        ((Unk804BD790 *)(base + 0x98))[index].c = value;
        ((Unk804BD790 *)(base + 0x98))[index].d = lbl_80564984;
    } else if (((Unk804BD790 *)(base + 0x98))[index].d < lbl_80564988) {
        ((Unk804BD790 *)(base + 0x98))[index].b = ((Unk804BD790 *)(base + 0x98))[index].c;
    } else {
        elapsed = fn_801E7E24();
        ((Unk804BD790 *)(base + 0x98))[index].d -= elapsed;
    }
    kind = ((Unk804BD790 *)(base + 0x98))[index].b;
    current = (s32 *)fn_801E7E3C(&((Unk804BD790 *)(base + 0x98))[index].a);
    if (lbl_8055F8F1 != 0 || kind >= current[2])
        selected = 3;
    else if ((u32)(kind + 1) < 4U)
        selected = kind;
    if (selected >= 0) {
        s32 *slot = (s32 *)(base + 0x48) + selected * 2;
        if (slot[1] != -1)
            MRModel_SetInstanceTransform(slot[1], base + 0x68);
    }
}
#pragma pop
void fn_802A9574(void) {
    u32 base = (u32)lbl_804BD790;
    f32 f = lbl_80564978;
    volatile s32 *p = (volatile s32 *)base;
    p[2] = -1;
    p[1] = -1;
    p[0] = -1;
    *(volatile f32 *)(p + 3) = f;
    p[6] = -1;
    p[5] = -1;
    p[4] = -1;
    *(volatile f32 *)(p + 7) = f;
}
/* Tail-call alias: forwards the (pos, dir) pair straight to fn_802A9090. */
void fn_802A95A8(f32 *pos, f32 *dir) {
    fn_802A9090(pos, dir);
}

/* Set the global flag read by fn_802A9428 when choosing a model slot. */
void fn_802A95AC(u8 value) {
    lbl_8055F8F1 = value;
}
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern f32 lbl_80564978;
