// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern f64 fn_8002F234(f32);
extern void *fn_801284E8(void *, s32);
__declspec(section ".data") extern unsigned int lbl_8032C108;
extern f32 lbl_80562C78;
extern f32 lbl_80562C7C;
extern s32 fn_802C8DBC(s32);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);

extern void *lbl_8055EA10;
extern void *fn_8017960C();
extern s32 fn_80139B70(s32, f32, f32);
typedef struct Vec_801E1048 { f32 x, y, z; } Vec_801E1048;

static inline void fn_801E1048_xf(const f32 *m, const f32 *src, f32 *dst, f32 x, f32 y, f32 z) {
    if (src == dst) {
        f32 nx = z * m[6] + (x * m[0] + y * m[3]);
        f32 ny = z * m[7] + (x * m[1] + y * m[4]);
        f32 nz = z * m[8] + (x * m[2] + y * m[5]);
        dst[0] = nx;
        dst[1] = ny;
        dst[2] = nz;
    } else {
        x = z * m[6] + (x * m[0] + y * m[3]);
        dst[0] = x;
        y = z * m[7] + (x * m[1] + y * m[4]);
        dst[1] = y;
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    }
}

static inline void fn_801E1048_xg(const f32 *m, const f32 *src, f32 *dst) {
    if (src == dst) {
        f32 nx = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        f32 ny = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        f32 nz = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
        dst[0] = nx;
        dst[1] = ny;
        dst[2] = nz;
    } else {
        f32 x = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        f32 y;
        dst[0] = x;
        y = src[2] * m[7] + (x * m[1] + src[1] * m[4]);
        dst[1] = y;
        dst[2] = src[2] * m[8] + (x * m[2] + y * m[5]);
    }
}

static inline void fn_801E1048_xh(const f32 *m, const f32 *src, f32 *dst) {
    f32 x, y, z;
    if (src == dst) {
        f32 xy3, xx0, xx1, yy4, xx2, yy5;
        x = src[0];
        y = src[1];
        z = src[2];
        xy3 = y * m[3];
        xx0 = x * m[0];
        xx1 = x * m[1];
        yy4 = y * m[4];
        xx2 = x * m[2];
        yy5 = y * m[5];
        dst[0] = z * m[6] + (xx0 + xy3);
        dst[1] = z * m[7] + (xx1 + yy4);
        dst[2] = z * m[8] + (xx2 + yy5);
    } else {
        x = src[0];
        y = src[1];
        z = src[2];
        x = z * m[6] + (x * m[0] + y * m[3]);
        dst[0] = x;
        y = z * m[7] + (x * m[1] + y * m[4]);
        dst[1] = y;
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    }
}

static inline void fn_801E1048_xi(const f32 *m, const f32 *src, f32 *dst) {
    f32 x, y, z;
    if (src == dst) {
        f32 a, b, c, d, e, f, nx, ny, nz;
        a = m[3];
        b = m[4];
        y = src[1];
        c = m[0];
        a = y * a;
        x = src[0];
        b = y * b;
        d = m[1];
        e = m[2];
        c = x * c;
        d = x * d;
        e = x * e;
        f = y * m[5];
        z = src[2];
        nx = z * m[6] + (c + a);
        ny = z * m[7] + (d + b);
        nz = z * m[8] + (e + f);
        dst[0] = nx;
        dst[1] = ny;
        dst[2] = nz;
    } else {
        x = src[0];
        y = src[1];
        z = src[2];
        x = z * m[6] + (x * m[0] + y * m[3]);
        dst[0] = x;
        y = z * m[7] + (x * m[1] + y * m[4]);
        dst[1] = y;
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    }
}

static inline void fn_801E1048_xv(f32 *m, Vec_801E1048 *src, Vec_801E1048 *dst, f32 x, f32 y, f32 z) {
    if (src == dst) {
        f32 nx = z * m[6] + (x * m[0] + y * m[3]);
        f32 ny = z * m[7] + (x * m[1] + y * m[4]);
        f32 nz = z * m[8] + (x * m[2] + y * m[5]);
        dst->x = nx;
        dst->y = ny;
        dst->z = nz;
    } else {
        x = z * m[6] + (x * m[0] + y * m[3]);
        dst->x = x;
        y = z * m[7] + (x * m[1] + y * m[4]);
        dst->y = y;
        dst->z = z * m[8] + (x * m[2] + y * m[5]);
    }
}

static inline void fn_801E1048_xform(f32 *m, Vec_801E1048 *src, Vec_801E1048 *dst) {
    f32 x, y;
    if (src == dst) {
        f32 nx = src->z * m[6] + (src->x * m[0] + src->y * m[3]);
        f32 ny = src->z * m[7] + (src->x * m[1] + src->y * m[4]);
        f32 nz = src->z * m[8] + (src->x * m[2] + src->y * m[5]);
        dst->x = nx;
        dst->y = ny;
        dst->z = nz;
    } else {
        x = src->z * m[6] + (src->x * m[0] + src->y * m[3]);
        dst->x = x;
        y = src->z * m[7] + (x * m[1] + src->y * m[4]);
        dst->y = y;
        dst->z = src->z * m[8] + (x * m[2] + y * m[5]);
    }
}

#pragma cplusplus on
class Dummy801E1520 {
public:
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5(s32 arg0) {}
    virtual void d6() {}
    virtual void d7(s32 arg0) {}
};
#pragma cplusplus off

extern void NWC24Data_Init_801E1028(void *);
extern void *fn_801E07E8(void *, s32);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_801284F8(s32, void *);
extern void fn_801E1038(void **);
extern void *fn_801E0FC4(void *);
extern void fn_801E0890(void *);
extern void fn_801E0864(void *);
extern s32 fn_802CAC28(void *, s32);
extern void fn_801777CC(void *);
extern u8 lbl_80339780[];
extern u8 lbl_80339818[];
typedef struct Vec2_801E0890 {
    f32 x, y;
} Vec2_801E0890;
typedef struct Poly_801E0890 {
    s32 n;
    s32 pad;
    Vec2_801E0890 p[4];
} Poly_801E0890;
typedef struct Cell_801E0890 {
    f32 x, y, z;
    s32 id;
    f32 u, v;
} Cell_801E0890;
typedef struct Rec_801E0890 {
    Poly_801E0890 *quad;
    Cell_801E0890 *cells;
    s32 nv;
    s32 nu;
    f32 cx, cy, cz;
} Rec_801E0890;
typedef struct Obj_801E0890 {
    u8 pad[0x7C];
    Rec_801E0890 *recs;
    s32 count;
} Obj_801E0890;
typedef struct List_801E0890 {
    Rec_801E0890 *data;
    s32 count;
    s32 cap;
} List_801E0890;

/* One player's boost-area draw state (BoostMan.slots[], 0x18 bytes each). */
typedef struct BoostSlot_801E0710 {
    s32 areaId;      /* +0x00 area the player is on, -1 = none */
    u8 pad04;        /* +0x04 set when the player is on the area */
    f32 speed;       /* +0x08 player speed on the previous frame */
    f32 timer;       /* +0x0C glow countdown, raised while boosting */
    s32 arrowColor;  /* +0x10 RGBA used for the arrow pass */
    s32 lineColor;   /* +0x14 RGBA used for the outline pass */
} BoostSlot_801E0710;

/* The draw code reaches a player's colours from a base of BoostMan + slot *
 * 0x18 instead of the slot itself (which starts at +0xC), so the two RGBA
 * fields land at +0x1C and +0x20 of that base. */
typedef struct BoostColors_801E12A4 {
    u8 pad00[0x1C];
    s32 arrowColor;  /* +0x1C: slots[slot].arrowColor */
    s32 lineColor;   /* +0x20: slots[slot].lineColor */
} BoostColors_801E12A4;

/* BoostMan (lbl_8055EA10, allocated 0xB78 bytes under the name "BoostMan"):
 * subdivides every boost area into a grid of cells and redraws the grids into
 * two draw lists, the area outlines (bstrlines.tex) and the arrows on them
 * (bstrarrows.tex).  fn_801E0710 builds it, fn_801E1710 updates the colours. */
typedef struct BoostMan_801E0710 {
    void *vtable;                  /* +0x00 */
    void *lineList;                /* +0x04 draw list of the outlines */
    void *arrowList;               /* +0x08 draw list of the arrows */
    BoostSlot_801E0710 slots[4];   /* +0x0C one per player */
    s32 slotArea[4];               /* +0x6C area each player is on */
    List_801E0890 areas;           /* +0x7C boost areas, at most 100 */
    Rec_801E0890 areaStore[100];   /* +0x88 areas.data points here */
} BoostMan_801E0710;

static inline void List_801E0890_Remove(List_801E0890 *l, s32 idx) {
    if (idx >= 0 && idx < l->count) {
        s32 last = l->count - 1;
        if (idx != last)
            l->data[idx] = l->data[last];
        l->count--;
    }
}

extern void *fn_8001285C(s32);
extern void *fn_80131810();
extern void fn_80131818(void *);
extern Poly_801E0890 *fn_801399FC(void *);
extern Vec2_801E0890 fn_80139C5C(void *);
extern Vec2_801E0890 fn_8014C770(Vec2_801E0890 *, Vec2_801E0890 *, f32);
extern f32 fn_80160BE0(Vec2_801E0890 *, Vec2_801E0890 *);
extern void fn_80160288(Vec2_801E0890 *, Vec2_801E0890 *);
extern void fn_801602B0(Vec2_801E0890 *);
extern void fn_80160BBC(Vec2_801E0890 *, Vec2_801E0890 *, Vec2_801E0890 *);
extern void fn_80160BA0(Vec2_801E0890 *, Vec2_801E0890 *, f32);
extern void fn_80160B7C(Vec2_801E0890 *, Vec2_801E0890 *, Vec2_801E0890 *);
extern void fn_80160B18(Vec2_801E0890 *);
extern void fn_80160B14(void *);
extern void fn_80160230(void *, Vec2_801E0890 *);
extern f32 fn_801DD88C(f32, f32);
extern void fn_801EA1E0(f32 *, s32, f32, f32);
extern void *fn_8012850C(s32, void *);
extern void fn_802E30C8(const char *, ...);
extern void *fn_801E0F34(int);
extern void fn_801E0F78(f32 *, f32 *, f32 *, f32);
extern f32 fn_801E0FA4(f32 *, f32 *);
extern float fn_801E0EE4(void *, void *);
extern int fn_801E0ED4(int, int);
extern f32 lbl_80562C8C;
extern f32 lbl_80562C80, lbl_80562C84, lbl_80562C88, lbl_80562C90, lbl_80562C94;

#pragma scheduling invalid_target
void fn_801E0710(void) {
    u8 *ref = lbl_80339780;
    void *obj;
    s32 i;
    s32 value;
    void *base;
    void *row;
    if (((u32 *)__AXFXGetLfoSinTable_801769CC())[1] & 0x200000) {
        obj = fn_801284F8(0xB78, ref + 0);
        if (obj != 0) {
            fn_801E1038((void **)obj);
            *(void **)obj = lbl_80339818;
            fn_801E0FC4((u8 *)obj + 0x7C);
            *(s32 *)((u8 *)obj + 4) = fn_802CAC28(ref + 0xC, 0);
            *(s32 *)((u8 *)obj + 8) = fn_802CAC28(ref + 0x1C, 0);
            fn_801E0890(obj);
            base = obj;
            row = (u8 *)obj + 0xC;
            value = -1;
            for (i = 0; i < 4; i++, base = (u8 *)base + 4, row = (u8 *)row + 0x18) {
                *(s32 *)((u8 *)base + 0x6C) = value;
                fn_801E0864(row);
            }
            fn_801777CC(obj);
            lbl_8055EA10 = obj;
        }
    }
}
#pragma scheduling on
extern void fn_80128658();
void *fn_801E07E8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)arg0;
        if (value != 0) {
            ((void (*)(s32))fn_80128658)(value);
            *(s32 *)arg0 = 0;
            fn_80128670(*(s32 *)((u8 *)arg0 + 4));
            *(s32 *)((u8 *)arg0 + 4) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
void fn_801E0864(void *arg0) {
    float b;
    float a;
    int z;
    int m;
    a = lbl_80562C78;
    z = 0;
    b = lbl_80562C7C;
    m = -1;
    *(int *)arg0 = m;
    *((char *)arg0 + 4) = z;
    *(int *)((char *)arg0 + 0x10) = z;
    *(int *)((char *)arg0 + 0x14) = z;
    *(float *)((char *)arg0 + 8) = a;
    *(float *)((char *)arg0 + 0xC) = b;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801E0890(void *arg0) {
    Obj_801E0890 *obj = (Obj_801E0890 *)arg0;
    u8 *ref = lbl_80339780;
    Vec2_801E0890 sp8, sp10, sp18, sp20;
    Vec2_801E0890 sp28, sp30, sp38, sp40;
    Vec2_801E0890 t1, t2, t3, t4;
    s32 best, j, i;
    s32 ok;
    void *item;
    Poly_801E0890 *poly;
    Rec_801E0890 *rec;
    Vec2_801E0890 *a;
    void *it;
    s32 idx;
    f32 k2, w1, d, k1, k3, v, w;
    void *p;
    Cell_801E0890 *cell;

    p = *(void **)((u8 *)fn_8001285C(*(s32 *)__AXFXGetLfoSinTable_801769CC()) + 0x20);
    ((void (*)(void *, void *, void *))(*(void ***)p)[6])(p, ref + 0x2C, ref + 0x3C);
    it = fn_80131810();
    if (it != 0) {
        k1 = lbl_80562C8C;
        k2 = lbl_80562C84;
        k3 = lbl_80562C88;
        for (idx = 0; (item = ((void *(*)(void *, s32))(*(void ***)it)[3])(it, idx)) != 0; idx++) {
            rec = &obj->recs[obj->count++];
            poly = fn_801399FC(item);
            ok = 0;
            if (poly->n == 3) {
                best = -1;
                a = &poly->p[0];
                for (i = 0; i < poly->n; i++, a++) {
                    if (best < 0 || (d = fn_80160BE0(a, &poly->p[i % poly->n]), fn_80160BE0(&poly->p[best], &poly->p[best % poly->n]) > d))
                        best = i;
                }
                fn_80160288(&sp8, &poly->p[(best + 2) % poly->n]);
                fn_801602B0(&sp10);
                a = &poly->p[best];
                fn_80160BBC(&sp10, a, &poly->p[(best + 1) % poly->n]);
                fn_80160BA0(&sp10, &sp10, lbl_80562C80);
                fn_801602B0(&sp18);
                fn_80160B7C(&sp18, &sp8, &sp10);
                fn_80160B18(&sp18);
                fn_801602B0(&sp20);
                fn_80160B7C(&sp20, a, &sp10);
                fn_801E0F78((f32 *)&sp20, (f32 *)&sp20, (f32 *)&sp18, -fn_801E0FA4((f32 *)&sp18, (f32 *)&sp20));
                rec->quad = fn_801E0F34(4);
                fn_80160BBC(&rec->quad->p[0], &sp10, &sp20);
                fn_801E0F78((f32 *)&rec->quad->p[1], (f32 *)&sp10, (f32 *)&sp20, lbl_80562C78);
                fn_801E0F78((f32 *)&rec->quad->p[2], (f32 *)&sp8, (f32 *)&sp20, lbl_80562C78);
                fn_80160BBC(&rec->quad->p[3], &sp8, &sp20);
                rec->quad->n = 4;
                rec->nu = fn_801E0ED4(2, (s32)((k2 + fn_801E0EE4(&rec->quad->p[0], &rec->quad->p[1])) / k3));
                rec->nv = fn_801E0ED4(2, (s32)((k2 + fn_801E0EE4(&rec->quad->p[1], &rec->quad->p[2])) / k3));
                rec->cells = fn_8012850C(rec->nu * rec->nv * 0x18, ref + 0x4C);
                for (i = 0; i < rec->nv; i++) {
                    v = (f32)i / (f32)(rec->nv - 1);
                    t1 = fn_8014C770(&rec->quad->p[1], &rec->quad->p[2], v);
                    fn_80160288(&sp28, &t1);
                    t2 = fn_8014C770(&rec->quad->p[0], &rec->quad->p[3], v);
                    fn_80160288(&sp30, &t2);
                    w1 = k1 - v;
                    for (j = 0; j < rec->nu; j++) {
                        w = (f32)j / (f32)(rec->nu - 1);
                        t3 = fn_8014C770(&sp28, &sp30, w);
                        fn_80160288(&sp38, &t3);
                        cell = &rec->cells[i * rec->nu + j];
                        fn_80160230(cell, &sp38);
                        cell->y = fn_801DD88C(cell->x, cell->z);
                        fn_801EA1E0(&cell->y, 0, cell->x, cell->z);
                        cell->id = -1;
                        cell->u = w;
                        cell->v = w1;
                    }
                }
                fn_80160B18(&sp20);
                fn_801E0F78((f32 *)&rec->quad->p[0], (f32 *)&rec->quad->p[0], (f32 *)&sp20, lbl_80562C8C);
                fn_801E0F78((f32 *)&rec->quad->p[0], (f32 *)&rec->quad->p[0], (f32 *)&sp18, lbl_80562C90);
                fn_801E0F78((f32 *)&rec->quad->p[1], (f32 *)&rec->quad->p[1], (f32 *)&sp20, lbl_80562C78);
                fn_801E0F78((f32 *)&rec->quad->p[1], (f32 *)&rec->quad->p[1], (f32 *)&sp18, lbl_80562C90);
                fn_801E0F78((f32 *)&rec->quad->p[2], (f32 *)&rec->quad->p[2], (f32 *)&sp20, lbl_80562C78);
                fn_801E0F78((f32 *)&rec->quad->p[2], (f32 *)&rec->quad->p[2], (f32 *)&sp18, lbl_80562C94);
                fn_801E0F78((f32 *)&rec->quad->p[3], (f32 *)&rec->quad->p[3], (f32 *)&sp20, lbl_80562C8C);
                fn_801E0F78((f32 *)&rec->quad->p[3], (f32 *)&rec->quad->p[3], (f32 *)&sp18, lbl_80562C94);
                t4 = fn_80139C5C(rec->quad);
                fn_80160288(&sp40, &t4);
                fn_80160230(&rec->cx, &sp40);
                rec->cy = fn_801DD88C(rec->cx, rec->cz);
                ok = 1;
            } else {
                fn_802E30C8((const char *)(ref + 0x58), ((s32 (*)(void *))(*(void ***)item)[2])(item));
            }
            fn_80160B14(poly);
            if (ok == 0) {
                s32 ri = *(volatile s32 *)&obj->count - 1;
                if (ri >= 0 && ri < *(volatile s32 *)&obj->count) {
                    s32 last = *(volatile s32 *)&obj->count - 1;
                    if (ri != last)
                        obj->recs[ri] = obj->recs[last];
                    obj->count = *(volatile s32 *)&obj->count - 1;
                }
            }
        }
        fn_80131818(it);
    }
}
#pragma pop
int fn_801E0ED4(int arg0, int arg1) {
    return arg1 > arg0 ? arg1 : arg0;
}

#pragma scheduling off
float fn_801E0EE4(void *arg0, void *arg1) {
    float delta[2];
    delta[1] = *(float *)((char *)arg0 + 4) - *(float *)((char *)arg1 + 4);
    delta[0] = *(float *)arg0 - *(float *)arg1;
    return (float)fn_8002F234(delta[0] * delta[0] + delta[1] * delta[1]);
}
#pragma scheduling on
void *fn_801E0F34(int arg0) {
    void *ptr;
    void *pool;
    int value;
    int size;
    value = arg0;
    size = (arg0 << 3) + 8;
    pool = (void *)&lbl_8032C108;
    ptr = fn_801284E8(pool, size);
    *(int *)((char *)ptr + 4) = value;
    *(int *)ptr = value;
    return ptr;
}

void fn_801E0F78(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    f32 x = arg1[0] + arg2[0] * arg3;
    f32 y = arg1[1] + arg2[1] * arg3;
    arg0[0] = x;
    arg0[1] = y;
}

#pragma push
#pragma scheduling off
f32 fn_801E0FA4(f32 *arg0, f32 *arg1) {
    f32 a = arg1[1];
    f32 b = arg0[1];
    f32 c = arg1[0];
    f32 d = arg0[0];
    f32 x = b * a;
    f32 y = d * c;
    return y + x;
}
#pragma pop
void *fn_801E0FC4(void *arg0) {
    void *temp_r6 = (u8 *)arg0 + 0xC;
    ((s32 *)arg0)[2] = 0x64;
    ((void **)arg0)[0] = temp_r6;
    ((s32 *)arg0)[1] = 0;
    fn_8002F53C(temp_r6, NWC24Data_Init_801E1028, fn_801E07E8, 0x1C, 0x64);
    return arg0;
}

void NWC24Data_Init_801E1028(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
}

extern void lbl_8032CE98(void);
void fn_801E1038(void **arg0) {
    *arg0 = (void *)&lbl_8032CE98;
}

s32 fn_801E1048(void) {
    Vec_801E1048 v;
    u8 *player;
    s32 j;
    s32 i;
    u8 *vec;
    s32 found;
    s32 offset;
    u8 *p;
    u8 *obj = (u8 *)lbl_8055EA10;
    u32 valid = (u32)(-(s32)obj | (s32)obj) >> 31;
    if (valid != 0) {
        player = (u8 *)fn_8017960C();
        vec = player + 0x23AC;
        i = 0;
        offset = 0;
        for (; i < *(s32 *)(obj + 0x80); i++, offset += 0x1C) {
            p = vec;
            for (j = 0; j < 4; j++, p += 0x74) {
                f32 *m = (f32 *)(player + 0x3C);
                v = *(Vec_801E1048 *)(p + 0x30);
                fn_801E1048_xi(m, (f32 *)&v, (f32 *)&v);
                v.x += m[9];
                v.y += m[10];
                v.z += m[11];
                found = 0;
                {
                    s32 id = *(s32 *)(*(u8 **)(obj + 0x7C) + offset);
                    if (id != 0 && fn_80139B70(id, v.x, v.z) != 0)
                        found = 1;
                }
                if (found != 0)
                    return 1;
            }
        }
        return 0;
    }
    return 0;
}

void fn_801E1250(s32 arg0, s8 arg1) {
    u8 *p = (u8 *)lbl_8055EA10;
    if (!p) return;
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
    if (arg0 == *(s32 *)(p + 0xC)) *(p + 0x10) = arg1;
    if (arg0 == *(s32 *)(p + 0x24)) *(p + 0x28) = arg1;
    p += 0x30;
}

extern s32 fn_801E85B4(void);
extern s32 fn_801E866C(void);
extern void fn_801E1384(s32, s32);
extern s32 fn_801E1510(s32 *, s32);
extern s32 fn_801E137C(void *);
extern void fn_802C8BD0(void *);
extern void fn_802C8D74(void);
#pragma scheduling invalid_target
/* Redraw every boost area into the two boost draw lists, tinted with the
 * colours the current player's slot holds (fn_801E1710 works out their RGBA
 * from how much boost that player has built up). */
void fn_801E12A4(void) {
    BoostMan_801E0710 *man = (BoostMan_801E0710 *)lbl_8055EA10;
    s32 slot;
    s32 i;
    BoostColors_801E12A4 *colors;
    if (man != 0) {
        slot = fn_801E85B4();
        man->slotArea[slot] = fn_801E866C();
        fn_802C8BD0(man->lineList);
        colors = (BoostColors_801E12A4 *)((u8 *)man + slot * 0x18);
        for (i = 0; i < fn_801E137C(&man->areas); i++) {
            fn_801E1384(fn_801E1510((s32 *)&man->areas, i), colors->lineColor);
        }
        fn_802C8D74();
        fn_802C8BD0(man->arrowList);
        for (i = 0; i < fn_801E137C(&man->areas); i++) {
            fn_801E1384(fn_801E1510((s32 *)&man->areas, i), colors->arrowColor);
        }
        fn_802C8D74();
    }
}
#pragma scheduling on
s32 fn_801E137C(void *arg0) { return ((s32 *)arg0)[1]; }

void fn_801E1384(s32 arg0, s32 arg1) {
    register s32 *desc = (s32 *)arg0;
    register s32 x;
    register s32 y;
    register s32 left = arg1;
    register s32 color;
    char *record;
    f32 xval, yval, zval, uval, vval;

    if (*(volatile s32 *)desc != 0) {
        {
            s32 width = *(volatile s32 *)((char *)desc + 8);
            s32 height = *(volatile s32 *)((char *)desc + 0xC);
            fn_802C8DBC(height * ((width - 1) << 1));
        }
        for (x = 1; x < *(volatile s32 *)((char *)desc + 8); x++) {
            color = x - 1;
            {
                s32 height = *(volatile s32 *)((char *)desc + 0xC);
                char *base = (char *)*(volatile s32 *)((char *)desc + 4);
                s32 row = color * height;
                record = base + row * 0x18;
            }
            *(volatile s32 *)(record + 0xC) = left;
            vval = *(f32 *)(record + 0x14);
            uval = *(f32 *)(record + 0x10);
            xval = *(f32 *)(record + 0);
            yval = *(f32 *)(record + 4);
            zval = *(f32 *)(record + 8);
            fn_802C8E00(left, 0, xval, yval, zval, uval, vval);
            {
                s32 height = *(volatile s32 *)((char *)desc + 0xC);
                char *base = (char *)*(volatile s32 *)((char *)desc + 4);
                record = base + (x * height * 0x18);
            }
            *(volatile s32 *)(record + 0xC) = left;
            vval = *(f32 *)(record + 0x14);
            uval = *(f32 *)(record + 0x10);
            xval = *(f32 *)(record + 0);
            yval = *(f32 *)(record + 4);
            zval = *(f32 *)(record + 8);
            fn_802C8E00(left, 0, xval, yval, zval, uval, vval);
            for (y = 1; y < *(volatile s32 *)((char *)desc + 0xC); y++) {
                {
                    s32 height = *(volatile s32 *)((char *)desc + 0xC);
                    char *base = (char *)*(volatile s32 *)((char *)desc + 4);
                    record = base + ((y + color * height) * 0x18);
                }
                *(volatile s32 *)(record + 0xC) = left;
                {
                    s32 recordColor = *(volatile s32 *)(record + 0xC);
                    vval = *(f32 *)(record + 0x14);
                    uval = *(f32 *)(record + 0x10);
                    xval = *(f32 *)(record + 0);
                    yval = *(f32 *)(record + 4);
                    zval = *(f32 *)(record + 8);
                    fn_802C8E00(recordColor, 1, xval, yval, zval, uval, vval);
                }
                {
                    s32 height = *(volatile s32 *)((char *)desc + 0xC);
                    char *base = (char *)*(volatile s32 *)((char *)desc + 4);
                    record = base + ((y + x * height) * 0x18);
                }
                *(volatile s32 *)(record + 0xC) = left;
                vval = *(f32 *)(record + 0x14);
                uval = *(f32 *)(record + 0x10);
                xval = *(f32 *)(record + 0);
                yval = *(f32 *)(record + 4);
                zval = *(f32 *)(record + 8);
                fn_802C8E00(left, 1, xval, yval, zval, uval, vval);
            }
        }
        fn_802C8E48();
    }
}

s32 fn_801E1510(s32 *arg0, s32 arg1) { return *arg0 + arg1 * 0x1C; }

void fn_801E1520(void);
#pragma cplusplus on
void fn_801E1520(void) {
    Dummy801E1520 *obj = (Dummy801E1520 *)lbl_8055EA10;
    if (obj != 0) {
        if (obj != 0)
            obj->d5(1);
        lbl_8055EA10 = 0;
    }
}
#pragma cplusplus off
#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
void *fn_801E1568(void *self, int shouldDelete) {
    // Destructor/teardown: set vtable (lbl_80339818), release owned items and
    // resources/IDs, reset internal arrays/state, and optionally free the object.
    int i;
    void **item;
    int offset;
    int zero;

    if (self != 0) {
        int val1;
        int val2;
        *(void **)self = &lbl_80339818;
        fn_801777D0(self);
        i = 0;
        offset = 0;
        zero = 0;
        for (; i < *(int *)((char *)self + 0x80); offset += 0x1c, i++) {
            item = (void **)(*(char **)((char *)self + 0x7c) + offset);
            if (*item != 0) {
                fn_80128658(*item);
                item[0] = (void *)zero;
                fn_80128670(item[1]);
                item[1] = (void *)zero;
            }
        }
        val1 = *(int *)((char *)self + 4);
        *(int *)((char *)self + 0x80) = 0;
        if (val1 != -2) {
            fn_802CAC54(val1);
            *(int *)((char *)self + 4) = -2;
        }
        val2 = *(int *)((char *)self + 8);
        if (val2 != -2) {
            fn_802CAC54(val2);
            *(int *)((char *)self + 8) = -2;
        }
        if ((char *)self + 0x7c != 0) {
            fn_8002F634((char *)self + 0x88, fn_801E07E8, 0x1c, 0x64);
            if ((char *)self + 0x7c != 0) {
                *(int *)((char *)self + 0x7c) = 0;
                *(int *)((char *)self + 0x80) = 0;
                *(int *)((char *)self + 0x84) = 0;
            }
        }
        if (shouldDelete > 0) {
            fn_80128668(self);
        }
    }
    return self;
}
#pragma pop

void fn_801E1684(void) {

}

void fn_801E1688(void) {

}

#pragma push
#pragma scheduling off
void fn_801E168C(void *arg0) {
    f32 y = lbl_80562C7C;
    f32 x = lbl_80562C78;
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x0C) = -1;
    *(u8 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(f32 *)((u8 *)arg0 + 0x14) = x;
    *(f32 *)((u8 *)arg0 + 0x18) = y;
    *(s32 *)((u8 *)arg0 + 0x70) = -1;
    *(s32 *)((u8 *)arg0 + 0x24) = -1;
    *(u8 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(f32 *)((u8 *)arg0 + 0x2C) = x;
    *(f32 *)((u8 *)arg0 + 0x30) = y;
    *(s32 *)((u8 *)arg0 + 0x74) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C) = -1;
    *(u8 *)((u8 *)arg0 + 0x40) = 0;
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;
    *(f32 *)((u8 *)arg0 + 0x44) = x;
    *(f32 *)((u8 *)arg0 + 0x48) = y;
    *(s32 *)((u8 *)arg0 + 0x78) = -1;
    *(s32 *)((u8 *)arg0 + 0x54) = -1;
    *(u8 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x64) = 0;
    *(s32 *)((u8 *)arg0 + 0x68) = 0;
    *(f32 *)((u8 *)arg0 + 0x5C) = x;
    *(f32 *)((u8 *)arg0 + 0x60) = y;
}
#pragma pop

extern void *fn_8017960C(s32);
extern s32 fn_801E85A4(void);
extern f32 lbl_80562C78, lbl_80562C7C, lbl_80562C8C, lbl_80562CA0, lbl_80562CA4;
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801E1710(void *arg0) {
    register f32 decrement;
    register f32 reset;
    register f32 threshold;
    register f32 initialB;
    register f32 initialA;

    register u8 *base;
    register u8 *row;
    register s32 i;

    initialA = lbl_80562C78;
    base = (u8 *)arg0;
    initialB = lbl_80562C7C;
    row = (u8 *)arg0;
    threshold = lbl_80562CA0;
    decrement = lbl_80562CA4;
    i = 0;
    reset = lbl_80562C8C;

    for (; i < fn_801E85A4(); base += 4, row += 0x18, i++) {
        s32 value = *(s32 *)(base + 0x6C);
        if (value != *(s32 *)(row + 0x0C)) {
            *(u8 *)(row + 0x10) = 0;
            *(s32 *)(row + 0x1C) = 0;
            *(s32 *)(row + 0x20) = 0;
            *(f32 *)(row + 0x14) = initialA;
            *(f32 *)(row + 0x18) = initialB;
            *(s32 *)(row + 0x0C) = value;
        }
        if (*(s32 *)(row + 0x0C) != -1) {
            f32 current2;
            int cond;
            int gt;
            void *obj = fn_8017960C(*(s32 *)(row + 0x0C));
            f32 current = *(f32 *)((u8 *)obj + 0x258C);
            cond = 0;
            gt = current > threshold;
            if (gt && *(u8 *)((u8 *)obj + 0x259D) != 0) {
                cond = 1;
            }
            current2 = *(f32 *)((u8 *)obj + 0x258C);
            if (cond && current2 > *(f32 *)(row + 0x14)) {
                *(f32 *)(row + 0x18) = reset;
            } else {
                *(f32 *)(row + 0x18) -= decrement;
            }
            *(f32 *)(row + 0x14) = current2;
            if (*(f32 *)(row + 0x18) > initialB) {
                *(s32 *)(row + 0x20) = -1;
                *(s32 *)(row + 0x1C) = -0x100;
            } else if (*(u8 *)(row + 0x10) != 0) {
                *(s32 *)(row + 0x20) = -1;
                *(s32 *)(row + 0x1C) = 0xFFFF0000;
            } else {
                *(s32 *)(row + 0x20) = 0xFF7F7F7F;
                *(s32 *)(row + 0x1C) = 0;
            }
        }
    }
}
void fn_801E1868(void) {

}

