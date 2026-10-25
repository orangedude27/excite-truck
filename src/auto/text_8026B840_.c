#include "types.h"

extern s32 fn_8026A344(s32);
extern void *fn_8017960C(s32);

extern char lbl_80346A50[];
extern s32 lbl_8055F4F0;
extern s32 lbl_8055F508;
extern f32 lbl_8055F50C;
extern f32 lbl_8055F510;
extern s32 lbl_8055F514;
extern f32 lbl_80563D94;
extern f32 lbl_80563D98;
extern f32 lbl_80563DA0;
extern f32 lbl_80563DB0;
extern f32 lbl_80563DE8;
extern f32 lbl_80563DEC;
extern f32 lbl_80563DF0;
extern f32 lbl_80563DF4;
extern f32 lbl_80563DF8;
extern f32 lbl_80563DFC;
extern f32 lbl_80563E00;
extern f32 lbl_80563E04;
extern f32 lbl_80563E08;
extern f32 lbl_80563E0C;

extern void *lbl_8055F4E0;
extern void *lbl_8055F4E4;
extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;
extern f32 lbl_8055F47C;
extern u32 lbl_80499050[];
extern void fn_80015B20(void *, void *, void *);

void fn_8026B840(void) {}

f32 fn_8026B844(f32 f) {
    f32 c = lbl_80563D78;
    if (f > c) {
        f32 t = (f - lbl_80563D7C) / lbl_80563D80;
        if (c > t) {
            goto set_first;
        }
        goto done_first;
set_first:
        c = t;
done_first:
        return c;
    }
    {
        f32 t = (lbl_80563D7C + f) / lbl_80563D84;
        if (c < t) {
            goto set_second;
        }
        goto done_second;
set_second:
        c = t;
done_second:
        return c;
    }
}

BOOL fn_8026BFF0(s32 x) {
    switch (x) { case 3: case 4: return TRUE; default: return FALSE; }
}

extern s32 fn_802D3EBC(void);
extern s32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_801298E8(f32 *, s32);
extern u8 *__AXFXGetLfoSinTable_801297F4(void);
extern s32 lbl_8055F4EC;
extern u8 lbl_8055F500;
extern s32 fn_802E4A60(f32 *);
extern void fn_8026B8A0(void);
extern s32 fn_802E2C20(void);
extern u8 lbl_8055F501;
extern u8 lbl_8055F502;
extern s32 lbl_8055F504;
extern char lbl_8049A168[];
extern f32 lbl_80563D88;
extern f32 lbl_80563D8C;
extern f64 lbl_80563DD0;
extern s32 fn_802E4A1C();
extern f32 lbl_80563DD8;
extern f32 lbl_80563D9C;
extern f32 lbl_80563DDC;
extern f32 lbl_80563DE0;
extern f32 lbl_80563DE4;
extern u32 lbl_802FA768[4];
extern u32 lbl_802FA778[4];
extern void fn_80015A20();
void fn_8026C014(s32 arg0, void *arg1) {
    struct Snapshot { f32 f[8]; s32 i[16]; u8 flag; };
    u8 localFrame[0x328];
    s32 stackHead;
    s32 index;
    s32 counter;
    s32 ok;
    s32 command;
    s32 flag;
    u8 active;
    f32 *base = (f32 *)(void *)lbl_8049A168;
    f32 dt;
    f32 step;
    f32 scale;
    f32 ax, ay, az;
    f32 bx, by, bz;
    f32 a, b, c;
    f32 *matrix;
    s32 now;
    (void)arg1;
    *(u32 *)(localFrame + 0x300) = 0x43300000;
    *(u32 *)(localFrame + 0x308) = 0x43300000;
    if (fn_802D3EBC() != 0) return;
    stackHead = arg0 != 0 ? __AXGetStackHead_80137CFC(0) : 0;
    ok = fn_801298E8((f32 *)(localFrame + 0x29C), stackHead);
    if (ok != 0) {
        index = *(s32 *)(__AXFXGetLfoSinTable_801297F4() + 0x28);
        if (index >= 0) {
            active = localFrame[0x2BC + index];
            if (active != 0 && lbl_8055F500 == 0) {
                counter = (lbl_8055F4EC + 1) % 3;
                *(volatile s32 *)&lbl_8055F4EC = counter;
                *(volatile u8 *)&lbl_8055F500 = active;
            }
        }
    }
    if (fn_802E4A60((f32 *)(localFrame + 0x238)) != 0) {
        struct Snapshot *state = (struct Snapshot *)(localFrame + 0x29C);
        struct Snapshot *scratch = (struct Snapshot *)(localFrame + 0x238);
        state->f[0] = scratch->f[0]; state->f[1] = scratch->f[1];
        state->f[2] = scratch->f[2]; state->f[3] = scratch->f[3];
        state->f[4] = scratch->f[4]; state->f[5] = scratch->f[5];
        state->f[6] = scratch->f[6]; state->f[7] = scratch->f[7];
        state->i[0] = scratch->i[0]; state->i[1] = scratch->i[1];
        state->i[2] = scratch->i[2]; state->i[3] = scratch->i[3];
        state->i[4] = scratch->i[4]; state->i[5] = scratch->i[5];
        state->i[6] = scratch->i[6]; state->i[7] = scratch->i[7];
        state->i[8] = scratch->i[8]; state->i[9] = scratch->i[9];
        state->i[10] = scratch->i[10]; state->i[11] = scratch->i[11];
        state->i[12] = scratch->i[12]; state->i[13] = scratch->i[13];
        state->i[14] = scratch->i[14]; state->i[15] = scratch->i[15];
        state->flag = scratch->flag;
    }
    counter = lbl_8055F4EC;
    if (counter == 0) {
        counter = counter + 1;
        counter %= 3;
        lbl_8055F4EC = counter;
    }
    if (counter == 2) {
        fn_8026B8A0();
        return;
    }
    if (counter == 0) {
        if (lbl_8055F501 == 0) {
            base[0x22] = lbl_80563D78;
            base[0x23] = lbl_80563D78;
            base[0x24] = lbl_80563D78;
            lbl_8055F501 = 1;
        }
        if (lbl_8055F502 == 0) {
            base[0x25] = lbl_80563D78;
            base[0x26] = lbl_80563D78;
            base[0x27] = lbl_80563D78;
            lbl_8055F502 = 1;
        }
        ax = ay = az = bx = by = bz = lbl_80563D78;
        counter = fn_802E2C20() - lbl_8055F504;
        *(u32 *)(localFrame + 0x304) = (u32)counter ^ 0x80000000;
        dt = (f32)(*(f64 *)(localFrame + 0x300) - lbl_80563DD0) / lbl_80563D88;
        if (dt < lbl_80563D8C) dt = lbl_80563D8C;
        now = fn_802E2C20();
        lbl_8055F504 = now;
        step = lbl_80563DD8;
        base[0x22] = base[0x22] * step;
        base[0x23] = base[0x23] * step;
        base[0x24] = base[0x24] * step;
        base[0x25] = base[0x25] * step;
        base[0x26] = base[0x26] * step;
        base[0x27] = base[0x27] * step;
        command = fn_802E4A1C(0xFD, &base[0x25], &base[0x22]);
        flag = 0;
        if (fn_802E4A1C(0xFE) == 0 && fn_802E4A1C(0x3A) != 0) flag = 1;
        scale = dt / lbl_80563D8C;
        for (index = 0; index < 4; index++) {
            *(u32 *)(localFrame + 0x128 + index * 4) = lbl_802FA768[index];
            *(u32 *)(localFrame + 0x118 + index * 4) = lbl_802FA778[index];
        }
        index = ((command << 1) | flag) * 4;
        b = scale * *(f32 *)(localFrame + 0x118 + index);
        a = scale * *(f32 *)(localFrame + 0x128 + index);
        if (fn_802E4A1C(0x1E) != 0) az = a;
        else if (fn_802E4A1C(0x2C) != 0) az = -a;
        if (fn_802E4A1C(0x51) != 0) ax = a;
        else if (fn_802E4A1C(0x4F) != 0) ax = -a;
        if (fn_802E4A1C(0x53) != 0) ay = a * lbl_80563D9C;
        else if (fn_802E4A1C(0x52) != 0) ay = -a * lbl_80563D9C;
        if (fn_802E4A1C(0x4D) != 0) {
            if (fn_802E4A1C(0x4F) != 0) by = b * lbl_80563D9C;
            else by = b;
        } else if (fn_802E4A1C(0x4B) != 0) {
            if (fn_802E4A1C(0x51) != 0) by = -b * lbl_80563D9C;
            else by = -b;
        }
        if (fn_802E4A1C(0x48) != 0) bx = b * lbl_80563D9C;
        else if (fn_802E4A1C(0x50) != 0) bx = -b * lbl_80563D9C;
        if (fn_802E4A1C(0x47) != 0) bz = b;
        else if (fn_802E4A1C(0x49) != 0) bz = -b;
        if (fn_802E4A1C(0x37) != 0) lbl_8055F47C += lbl_80563DDC;
        else if (fn_802E4A1C(0xB5) != 0) lbl_8055F47C -= lbl_80563DDC;
        if (lbl_8055F47C < lbl_80563DE0) lbl_8055F47C = lbl_80563DE0;
        if (lbl_8055F47C > lbl_80563DE4) lbl_8055F47C = lbl_80563DE4;
        *(f32 *)(localFrame + 0x138) = bx;
        *(f32 *)(localFrame + 0x13C) = by;
        *(f32 *)(localFrame + 0x140) = bz;
        *(f32 *)(localFrame + 0x144) = ax;
        *(f32 *)(localFrame + 0x148) = ay;
        *(f32 *)(localFrame + 0x14C) = az;
        if (bx != lbl_80563D78 || by != lbl_80563D78 || bz != lbl_80563D78) {
            base[0x25] = bx;
            base[0x26] = by;
            base[0x27] = bz;
        }
        if (ax != lbl_80563D78 || ay != lbl_80563D78 || az != lbl_80563D78) {
            base[0x22] = ax;
            base[0x23] = ay;
            base[0x24] = az;
        }
        matrix = (f32 *)lbl_80499050;
        a = base[0x22] * matrix[0] + (base[0x23] * matrix[3] + base[0x24] * matrix[6]);
        b = base[0x22] * matrix[1] + (base[0x23] * matrix[4] + base[0x24] * matrix[7]);
        c = base[0x22] * matrix[2] + base[0x23] * matrix[5] + base[0x24] * matrix[8];
        *(f32 *)(localFrame + 0x60) = a;
        *(f32 *)(localFrame + 0x64) = b;
        *(f32 *)(localFrame + 0x68) = c;
        matrix[9] += a;
        matrix[10] += b;
        matrix[11] += c;
        fn_80015A20(localFrame + 0x1E0, base + 0x25, a, b, c, 0.0f);
        fn_80015B20(matrix, matrix, localFrame + 0x1E0);
    }
}

extern u32 lbl_80499050[];
extern u32 lbl_8049A1C0[];
extern f32 lbl_8055F47C;
extern s32 lbl_8055F4F0;
extern f32 lbl_80563D94;
extern BOOL fn_8026BFF0(s32);
extern s32 fn_8026A344(s32);
extern void *fn_8017960C(s32);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern void fn_8026E688(f32 *, f32 *, f32 *, f32 *);
#pragma dont_inline on
void fn_8026DAA8(void *arg0) {
    void *self = arg0;

    if (*(u8 *)((u8 *)self + 0x138) != 0 &&
        !fn_8026BFF0((s32)lbl_8055F4E0)) {
        u32 *p = (u32 *)((u8 *)self + 0x58);
        u32 *q = lbl_80499050;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        q[4] = p[4];
        q[5] = p[5];
        q[6] = p[6];
        q[7] = p[7];
        q[8] = p[8];
        q[9] = p[9];
        q[10] = p[10];
        q[11] = p[11];
        lbl_8055F47C = *(f32 *)((u8 *)self + 0x194);
    }

    switch ((s32)lbl_8055F4E0) {
    case 3:
        if (lbl_8055F4F0 >= 0) {
            u32 local[12];
            f32 up[3];
            s32 id = fn_8026A344(0);
            u32 *source = (u32 *)((u8 *)fn_8017960C(lbl_8055F4F0) + 0x3C);
            f32 *other = (f32 *)((u8 *)fn_8017960C(id) + 0x60);
            f32 *target = (f32 *)&local[9];

            local[0] = source[0];
            local[1] = source[1];
            local[2] = source[2];
            local[3] = source[3];
            local[4] = source[4];
            local[5] = source[5];
            local[6] = source[6];
            local[7] = source[7];
            local[8] = source[8];
            local[9] = source[9];
            local[10] = source[10];
            local[11] = source[11];

            target[0] += ((f32 *)lbl_80499050)[9];
            target[1] += ((f32 *)lbl_80499050)[10];
            target[2] += ((f32 *)lbl_80499050)[11];

            up[0] = lbl_80563D78;
            up[1] = lbl_80563D94;
            up[2] = lbl_80563D78;
            fn_8026E688((f32 *)((u8 *)self + 0x58), target, other, up);
        } else {
            f32 *matrix = (f32 *)((u8 *)self + 0x58);
            matrix[0] = lbl_80563D94;
            matrix[1] = lbl_80563D78;
            matrix[2] = lbl_80563D78;
            matrix[3] = lbl_80563D78;
            matrix[4] = lbl_80563D94;
            matrix[5] = lbl_80563D78;
            matrix[6] = lbl_80563D78;
            matrix[7] = lbl_80563D78;
            matrix[8] = lbl_80563D94;
            matrix[9] = lbl_80563D78;
            matrix[10] = lbl_80563D78;
            matrix[11] = lbl_80563D78;
        }
        break;
    case 4: {
        s32 id = fn_8026A344(0);
        u8 *base = (u8 *)fn_8017960C(id) + 0x3C;
        fn_801BFD34((u8 *)self + 0x7C, (u8 *)lbl_80499050 + 0x24, base);
        fn_80015B20((u8 *)self + 0x58, lbl_80499050, base);
        break;
    }
    default: {
        u32 *q = lbl_80499050 - 1;
        u32 *matrix = (u32 *)((u8 *)self + 0x58);
        matrix[0] = *++q;
        matrix[1] = *++q;
        matrix[2] = *++q;
        matrix[3] = *++q;
        matrix[4] = *++q;
        matrix[5] = *++q;
        matrix[6] = *++q;
        matrix[7] = *++q;
        matrix[8] = *++q;
        matrix[9] = *++q;
        matrix[10] = *++q;
        matrix[11] = *++q;
        break;
    }
    }

    *(f32 *)((u8 *)self + 0xBC) = lbl_8055F47C;
    *(f32 *)((u8 *)self + 0x120) = lbl_80563D78;
    *(f32 *)((u8 *)self + 0x124) = lbl_80563D78;
    *(f32 *)((u8 *)self + 0x128) = lbl_80563D78;

    lbl_8049A1C0[0] = *(u32 *)((u8 *)self + 0x58);
    lbl_8049A1C0[1] = *(u32 *)((u8 *)self + 0x5C);
    lbl_8049A1C0[2] = *(u32 *)((u8 *)self + 0x60);
    lbl_8049A1C0[3] = *(u32 *)((u8 *)self + 0x64);
    lbl_8049A1C0[4] = *(u32 *)((u8 *)self + 0x68);
    lbl_8049A1C0[5] = *(u32 *)((u8 *)self + 0x6C);
    lbl_8049A1C0[6] = *(u32 *)((u8 *)self + 0x70);
    lbl_8049A1C0[7] = *(u32 *)((u8 *)self + 0x74);
    lbl_8049A1C0[8] = *(u32 *)((u8 *)self + 0x78);
    lbl_8049A1C0[9] = *(u32 *)((u8 *)self + 0x7C);
    lbl_8049A1C0[10] = *(u32 *)((u8 *)self + 0x80);
    lbl_8049A1C0[11] = *(u32 *)((u8 *)self + 0x84);
}
void* fn_8026DDD0(void) {
    return lbl_8055F4E0;
}

void fn_8026E204(void* hi) {
    lbl_8055F4E4 = hi;
}

extern void *lbl_8055F4E4;
void* fn_8026E20C(void) {
    return lbl_8055F4E4;
}

void* fn_8026E214(void* value) {
    void* old = lbl_8055F4E8;
    lbl_8055F4E8 = value;
    return old;
}

extern void *lbl_8055F4E8;
extern f32 lbl_80563D78;
extern f32 lbl_80563D7C;
extern f32 lbl_80563D80;
extern f32 lbl_80563D84;

