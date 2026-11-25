// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

typedef struct {
    f32 x, y, z;
    s32 unk_0xC;
    f32 unk_0x10, unk_0x14;
} Unk801E4E44Vertex;

typedef struct {
    f32 unk_0x0, unk_0x4, unk_0x8, unk_0xC, unk_0x10, unk_0x14;
    f32 unk_0x18, unk_0x1C, unk_0x20, unk_0x24;
    s32 unk_0x28, unk_0x2C, unk_0x30;
    f32 unk_0x34;
} Unk801E4E44State;

extern Unk801E4E44Vertex lbl_80487578[];
extern u16 lbl_80487B18[];
extern Unk801E4E44State lbl_80487C88;
extern s32 lbl_8055EAA8, lbl_8055EAAC, lbl_8055EAB0;
void fn_801E4E44(void);

extern void drawFifoTriangles(s32, s32, s32, s32);
#pragma scheduling invalid_target
void fn_801E4E44(void) {
    if ((s32)lbl_8055EAA8 > 2) {
        {
            register s32 indexCount asm("r6") = lbl_8055EAAC;
            if (indexCount > 2) {
                drawFifoTriangles((s32)&lbl_80487578, lbl_8055EAA8, (s32)&lbl_80487B18, indexCount);
            }
        }
        {
            register s32 count asm("r4") = lbl_8055EAA8;
            register s32 base asm("r6") = (s32)&lbl_80487578;
            register s32 source asm("r7");
            register s32 first asm("r5");
            s32 index, offset, lastIndex, lastOffset, secondWord, thirdWord, last;
            index = count - 2;
            offset = index * 0x18;
            source = base + offset;
            first = *(volatile s32 *)(base + offset);
            lastIndex = count - 1;
            secondWord = *(s32 *)(source + 4);
            lastOffset = lastIndex * 0x18;
            last = base + lastOffset;
            lbl_8055EAA8 = 2;
            *(s32 *)(base + 4) = secondWord;
            *(s32 *)base = first;
            thirdWord = *(s32 *)(source + 8);
            lbl_8055EAAC = 0;
            *(s32 *)(base + 8) = thirdWord;
            *(s32 *)(base + 0xC) = *(s32 *)(source + 0xC);
            *(f32 *)(base + 0x10) = *(f32 *)(source + 0x10);
            *(f32 *)(base + 0x14) = *(f32 *)(source + 0x14);
            *(s32 *)(base + 0x18) = *(s32 *)last;
            *(s32 *)(base + 0x1C) = *(s32 *)(last + 4);
            *(s32 *)(base + 0x20) = *(s32 *)(last + 8);
            *(s32 *)(base + 0x24) = *(s32 *)(last + 0xC);
            *(f32 *)(base + 0x28) = *(f32 *)(last + 0x10);
            *(f32 *)(base + 0x2C) = *(f32 *)(last + 0x14);
        }
    }
}
#pragma scheduling on
/* Begin a mode-1 mesh pass: clear the vertex/index counters, set the mesh mode to 1, and report success. */
s32 beginMeshPass(void) {
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_8055EAB0 = 1;
    return 1;
}

#pragma scheduling invalid_target
#pragma scheduling on
/* Appends a vertex to the active mesh buffer and emits a triangle index strip when requested, flushing if buffers fill. */
s32 fn_801E4F3C(s32 color, s32 emitTriangle, f32 x, f32 y, f32 z, f32 u, f32 v) {
    Unk801E4E44Vertex* vertex;
    s32 vertexCount;
    vertex = &lbl_80487578[lbl_8055EAA8++];
    vertex->x = x;
    vertex->y = y;
    vertex->z = z;
    vertex->unk_0x10 = u;
    vertex->unk_0x14 = v;
    vertex->unk_0xC = color;
    vertexCount = lbl_8055EAA8;
    if (emitTriangle && vertexCount > 2) {
        lbl_80487B18[lbl_8055EAAC++] = vertexCount - 3;
        lbl_80487B18[lbl_8055EAAC++] = vertexCount - 2;
        lbl_80487B18[lbl_8055EAAC++] = vertexCount - 1;
    }
    if (vertexCount == 60 || lbl_8055EAAC == 174) fn_801E4E44();
    return 0;
}
/* End the current mesh pass: flush/compact the vertex and index buffers
 * (fn_801E4E44) and reset the mesh mode (lbl_8055EAB0) to 0 (idle). */
void endMeshPass(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

extern f32 lbl_80562D40;
extern f32 lbl_80487C78[];
#pragma scheduling invalid_target
#pragma scheduling on
/* Begin a point/particle draw batch: reset the vertex and index counts, give all 60 vertices the same packed alpha-over-white color, store the center position and scaled point size, and switch the batch draw mode to 2. */ s32 fn_801E501C(s32 count, const void *position, u8 alpha, f32 scale) {
    f32 size, z, y, x;
    u32 packedColor;
    s32 i;
    s32 zero = 0;
    x = *(f32 *)((char *)position + 0);
    size = lbl_80562D40 * scale;
    y = *(f32 *)((char *)position + 4);
    z = *(f32 *)((char *)position + 8);
    packedColor = ((u32)alpha << 24) | 0x00FFFFFF;
    lbl_8055EAA8 = zero;
    lbl_8055EAAC = zero;
    for (i = 0; i < 60; i++) lbl_80487578[i].unk_0xC = packedColor;
    lbl_80487C78[0] = x;
    lbl_80487C78[1] = y;
    lbl_80487C78[2] = z;
    lbl_80487C78[3] = size;
    lbl_8055EAB0 = 2;
    return 1;
}
extern f32 lbl_80562D44, lbl_80562D48;
#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801E5174(f32 arg0, f32 arg1, f32 arg2)
{
  u8 *baseptr = (u8 *) lbl_80487578;
  Unk801E4E44Vertex *vertices = (Unk801E4E44Vertex *) baseptr;
  f32 *center = (f32 *) (((u8 *) ((Unk801E4E44Vertex *) baseptr)) + 0x700);
  s32 count;
  s32 index;
  s32 base;
  if (((lbl_8055EAA8 + 4) > 60) || ((lbl_8055EAAC + 6) > 174))
  {
    fn_801E4E44();
  }
  count = (base = lbl_8055EAA8) + 3;
  {
    f32 c0 = center[count * 0];
    f32 c1 = center[1];
    Unk801E4E44Vertex *v3 = &vertices[base + 3];
    Unk801E4E44Vertex *v2 = &vertices[base + 2];
    f32 c2 = center[2];
    f32 c3 = center[3];
    Unk801E4E44Vertex *v0 = &vertices[base];
    Unk801E4E44Vertex *v1 = &vertices[(base & 0xFFFFu) + 1];
    v0->x = arg0 - c3; v0->y = arg1; v0->z = arg2;
    v1->x = arg0 + c3; v1->y = arg1; v1->z = arg2;
    v2->x = v0->x + c0; v2->y = v0->y + c1; v2->z = v0->z + c2;
    v3->x = v1->x + c0; v3->y = v1->y + c1; v3->z = v1->z + c2;
    v0->unk_0x10 = lbl_80562D44; v1->unk_0x10 = lbl_80562D48;
    v2->unk_0x10 = lbl_80562D44; v3->unk_0x10 = lbl_80562D48;
    v0->unk_0x14 = lbl_80562D48; v1->unk_0x14 = lbl_80562D44;
    v2->unk_0x14 = lbl_80562D48; v3->unk_0x14 = lbl_80562D44;
  }
  if (count > 2)
  {
    index = lbl_8055EAAC;
    *((u16 *) ((((u8 *) vertices) + 0x5a0) + (index * 2))) = (base + 3) - 3;
    *((0, (u16 *) ((((u8 *) vertices) + 0x5a0) + (((index & 0xFFFF) + 1) * 2)))) = count - 2;
    *((u16 *) ((((u8 *) vertices) + 0x5a0) + ((index + 2) * 2))) = count - 1;
    lbl_8055EAAC = (((((((index & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) + (((3 & 0xFFFFu) & 0xFFFFu) & 0xFFFFu);
  }
  lbl_8055EAA8 = count - (-1);
  if ((count + 1) > 2)
  {
    index = lbl_8055EAAC;
    *((u16 *) ((((u8 *) vertices) + 0x5a0) + (index * 2))) = ((base & 0xFFFFu) + 3) - 2;
    *((u16 *) ((((u8 *) vertices) + 0x5a0) + ((((char) index) + 1) * 2))) = count - 1;
    *((u16 *) ((0x5a0 + ((u8 *) vertices)) + ((index + 2) * 2))) = base + 3;
    lbl_8055EAAC = index + 3;
  }
}
#pragma pop
/* End the current mesh pass: flush/compact the vertex and index buffers
 * (fn_801E4E44) and reset the mesh mode (lbl_8055EAB0) to 0 (idle). */
void fn_801E5348(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
s32 fn_801E5370(s32 value, s32 lastIndex, f32 scale) {
    /* Begin a mode-3 mesh pass: clear the vertex/index counters, seed the state (value, index limit + 1, scale), and report success. */
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_80487C88.unk_0x2C = value;
    lbl_80487C88.unk_0x28 = 0;
    lbl_80487C88.unk_0x30 = lastIndex + 1;
    lbl_80487C88.unk_0x34 = scale;
    lbl_8055EAB0 = 3;
    return 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801E53A8(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3, f32 arg4) {
    extern char lbl_803399F8[];
    extern void Abend_Panic(const char *, ...);
    extern f32 fn_802C88D4(void *);
    extern f32 lbl_80562D44, lbl_80562D48, lbl_80562D4C, lbl_80562D50, lbl_80562D54, lbl_80562D58;
    Unk801E4E44Vertex *verts = lbl_80487578;
    Unk801E4E44State *state = (Unk801E4E44State *)((u8 *)lbl_80487578 + 0x710);
    Unk801E4E44Vertex *vtx;
    f32 delta[3];
    f32 sum[3];
    f32 mid[3];
    f32 step, t, t2, t3, h10, h11;
    f32 p0x, p0y, p0z, p1x, p1y, p1z, prev4, range, speed;
    s32 n, i, a, c, alpha, count, index, color;

    if (state->unk_0x28 >= state->unk_0x2C) {
        Abend_Panic(lbl_803399F8);
    }

    delta[0] = arg0[0] - arg2[0];
    delta[1] = arg0[1] - arg2[1];
    delta[2] = arg0[2] - arg2[2];
    sum[0] = arg0[0] + arg2[0];
    sum[1] = arg0[1] + arg2[1];
    sum[2] = arg0[2] + arg2[2];

    if (state->unk_0x28 > 0 && arg3 != 0) {
        speed = fn_802C88D4(state);
        n = state->unk_0x30;
        a = (s32)((f32)n - speed * state->unk_0x34);
        c = 1;
        if (a > 1) {
            c = a;
            if (c < n) {
                n = c;
            }
        }

        step = lbl_80562D48 / (f32)n;
        if (lbl_8055EAA8 + n * 2 + 2 > 60 || lbl_8055EAAC + n * 6 > 174) {
            fn_801E4E44();
        }

        a = (s32)(lbl_80562D4C * state->unk_0x24);
        a = a & (((-a) & ~a) >> 31);
        alpha = 0xFF;
        if (a < 0xFF) {
            alpha = a;
        }
        color = (alpha << 24) | 0xFFFFFF;

        p0x = state->unk_0x0;
        p0y = state->unk_0x4;
        p0z = state->unk_0x8;
        p1x = state->unk_0xC;
        p1y = state->unk_0x10;
        p1z = state->unk_0x14;

        count = lbl_8055EAA8;
        vtx = &verts[count];
        vtx->x = p0x;
        vtx->y = p0y;
        vtx->z = p0z;
        vtx->unk_0x10 = lbl_80562D44;
        vtx->unk_0x14 = lbl_80562D44;
        vtx->unk_0xC = color;
        count++;
        vtx = &verts[count];
        vtx->x = p1x;
        vtx->y = p1y;
        vtx->z = p1z;
        vtx->unk_0x10 = lbl_80562D48;
        vtx->unk_0x14 = lbl_80562D44;
        vtx->unk_0xC = color;
        count++;
        lbl_8055EAA8 = count;

        index = lbl_8055EAAC;
        prev4 = state->unk_0x24;
        range = arg4 - prev4;
        for (i = 1; i <= n; i++) {
            t = (f32)i * step;
            t2 = t * t;
            t3 = t2 * t;
            h11 = t3 - t2;
            h10 = t + (t3 - lbl_80562D50 * t2);

            a = (s32)(lbl_80562D4C * (prev4 + t * range));
            a = a & (((-a) & ~a) >> 31);
            alpha = 0xFF;
            if (a < 0xFF) {
                alpha = a;
            }
            color = (alpha << 24) | 0xFFFFFF;

            mid[0] = state->unk_0x18 * h10 + arg1[0] * h11;
            mid[1] = state->unk_0x1C * h10 + arg1[1] * h11;
            mid[2] = state->unk_0x20 * h10 + arg1[2] * h11;

            vtx = &verts[count];
            vtx->x = mid[0] + p0x * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + delta[0] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->y = mid[1] + p0y * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + delta[1] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->z = mid[2] + p0z * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + delta[2] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->unk_0x10 = lbl_80562D44;
            vtx->unk_0x14 = t;
            vtx->unk_0xC = color;
            count++;
            if (count > 2) {
                s32 i0 = index;
                s32 i1 = i0 + 1;
                s32 i2 = i1 + 1;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i0 * 2) = count - 3;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i1 * 2) = count - 2;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i2 * 2) = count - 1;
                index = i2 + 1;
                lbl_8055EAAC = index;
            }

            vtx = &verts[count];
            vtx->x = mid[0] + p1x * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + sum[0] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->y = mid[1] + p1y * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + sum[1] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->z = mid[2] + p1z * (lbl_80562D48 + (lbl_80562D50 * t3 - lbl_80562D54 * t2)) + sum[2] * (lbl_80562D58 * t3 + lbl_80562D54 * t2);
            vtx->unk_0x10 = lbl_80562D48;
            vtx->unk_0x14 = t;
            vtx->unk_0xC = color;
            count++;
            if (count > 2) {
                s32 i0 = index;
                s32 i1 = i0 + 1;
                s32 i2 = i1 + 1;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i0 * 2) = count - 3;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i1 * 2) = count - 2;
                *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + i2 * 2) = count - 1;
                index = i2 + 1;
                lbl_8055EAAC = index;
            }
        }
        lbl_8055EAA8 = count;
    }

    state->unk_0x20 = arg1[2];
    state->unk_0x0 = delta[0];
    state->unk_0x4 = delta[1];
    state->unk_0x8 = delta[2];
    state->unk_0xC = sum[0];
    state->unk_0x10 = sum[1];
    state->unk_0x14 = sum[2];
    state->unk_0x18 = arg1[0];
    state->unk_0x1C = arg1[1];
    state->unk_0x24 = arg4;
    state->unk_0x28 = state->unk_0x28 + 1;
}
#pragma pop
/* End the current mesh pass: flush/compact the vertex and index buffers
 * (fn_801E4E44) and reset the mesh mode (lbl_8055EAB0) to 0 (idle). */
void fn_801E58FC(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

