// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

typedef struct {
    f32 x, y, z;
    s32 unk_0xC;
    f32 unk_0x10, unk_0x14;
} Unk801E4E44Vertex;

typedef struct {
    u8 unk_0x0[0x28];
    s32 unk_0x28, unk_0x2C, unk_0x30;
    f32 unk_0x34;
} Unk801E4E44State;

extern Unk801E4E44Vertex lbl_80487578[];
extern u16 lbl_80487B18[];
extern Unk801E4E44State lbl_80487C88;
extern s32 lbl_8055EAA8, lbl_8055EAAC, lbl_8055EAB0;
void fn_801E4E44(void);

extern void fn_802D68C4(s32, s32, s32, s32);
#pragma scheduling invalid_target
void fn_801E4E44(void) {
    if ((s32)lbl_8055EAA8 > 2) {
        s32 indexCount = lbl_8055EAAC;
        if (indexCount > 2) {
            fn_802D68C4((s32)&lbl_80487578, lbl_8055EAA8, (s32)&lbl_80487B18, indexCount);
        }
        {
            s32 count = lbl_8055EAA8;
            s32 base = (s32)&lbl_80487578;
            s32 index = count - 2;
            s32 offset = index * 0x18;
            s32 source = base + offset;
            s32 first = *(volatile s32 *)(base + offset);
            s32 secondWord = *(s32 *)(source + 4);
            lbl_8055EAA8 = 2;
            *(s32 *)(base + 4) = secondWord;
            *(s32 *)base = first;
            {
                s32 lastIndex = count - 1;
                s32 lastOffset = lastIndex * 0x18;
                register s32 *last asm("r4") = (s32 *)(base + lastOffset);
                s32 thirdWord = *(s32 *)(source + 8);
                lbl_8055EAAC = 0;
                *(s32 *)(base + 8) = thirdWord;
                *(s32 *)(base + 0xC) = *(s32 *)(source + 0xC);
                *(f32 *)(base + 0x10) = *(f32 *)(source + 0x10);
                *(f32 *)(base + 0x14) = *(f32 *)(source + 0x14);
                *(s32 *)(base + 0x18) = last[0];
                *(s32 *)(base + 0x1C) = last[1];
                *(s32 *)(base + 0x20) = last[2];
                *(s32 *)(base + 0x24) = last[3];
                *(f32 *)(base + 0x28) = *(f32 *)&last[4];
                *(f32 *)(base + 0x2C) = *(f32 *)&last[5];
            }
        }
    }
}
#pragma scheduling on
/* Begin a mode-1 mesh pass: clear the vertex/index counters, set the mesh mode to 1, and report success. */
s32 fn_801E4F20(void) {
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_8055EAB0 = 1;
    return 1;
}

#pragma scheduling invalid_target
#pragma scheduling on
s32 fn_801E4F3C(s32 arg0, s32 arg1, f32 x, f32 y, f32 z, f32 u, f32 v) {
    Unk801E4E44Vertex* vertex;
    s32 count;
    (vertex = &lbl_80487578[lbl_8055EAA8])->x = x;
    count = lbl_8055EAA8 + 1;
    vertex->y = y;
    vertex->z = z;
    vertex->unk_0x10 = u;
    vertex->unk_0x14 = v;
    lbl_8055EAA8 = count;
    vertex->unk_0xC = arg0;
    if (arg1 && count > 2) {
        s32 b = lbl_8055EAAC + 1;
        s32 c = b + 1;
        lbl_80487B18[lbl_8055EAAC] = count - 3;
        lbl_8055EAAC = c + 1;
        lbl_80487B18[b] = count - 2;
        lbl_80487B18[c] = count - 1;
    }
    if (count == 60 || lbl_8055EAAC == 174) fn_801E4E44();
    return 0;
}
/* End the current mesh pass: flush/compact the vertex and index buffers
 * (fn_801E4E44) and reset the mesh mode (lbl_8055EAB0) to 0 (idle). */
void fn_801E4FF4(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

extern f32 lbl_80562D40;
extern f32 lbl_80487C78[];
s32 fn_801E501C(s32 unused, void *xyz, u8 color, f32 scale) {
    f32 y = *(f32 *)((char *)xyz + 4);
    f32 x = *(f32 *)((char *)xyz + 0);
    f32 z = *(f32 *)((char *)xyz + 8);
    f32 w = lbl_80562D40 * scale;
    u32 packed = ((u32)color << 24) | 0x00FFFFFF;
    s32 i;
    for (i = 0; i < 60; i++) lbl_80487578[i].unk_0xC = packed;
    lbl_8055EAA8 = 0;
    lbl_8055EAAC = 0;
    lbl_80487C78[0] = x;
    lbl_80487C78[1] = y;
    lbl_80487C78[2] = z;
    lbl_80487C78[3] = w;
    lbl_8055EAB0 = 2;
    return 1;
}

extern f32 lbl_80562D44, lbl_80562D48;
#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_propagation off
void fn_801E5174(f32 arg0, f32 arg1, f32 arg2) {
    Unk801E4E44Vertex *vertices = lbl_80487578;
    f32 *center = (f32 *)((u8 *)lbl_80487578 + 0x700);
    s32 count;
    s32 index;
    register s32 base;

    if (lbl_8055EAA8 + 4 > 60 || lbl_8055EAAC + 6 > 174) fn_801E4E44();

    base = lbl_8055EAA8;
    count = base + 3;
    vertices[base].x = arg0 - center[3];
    vertices[base].y = arg1;
    vertices[base].z = arg2;
    vertices[base + 1].x = arg0 + center[3];
    vertices[base + 1].y = arg1;
    vertices[base + 1].z = arg2;
    vertices[base + 2].x = vertices[base].x + center[0];
    vertices[base + 2].y = vertices[base].y + center[1];
    vertices[base + 2].z = vertices[base].z + center[2];
    vertices[base + 3].x = vertices[base + 1].x + center[0];
    vertices[base + 3].y = vertices[base + 1].y + center[1];
    vertices[base + 3].z = vertices[base + 1].z + center[2];
    vertices[base].unk_0x10 = lbl_80562D44;
    vertices[base + 1].unk_0x10 = lbl_80562D48;
    vertices[base + 2].unk_0x10 = lbl_80562D44;
    vertices[base + 3].unk_0x10 = lbl_80562D48;
    vertices[base].unk_0x14 = lbl_80562D48;
    vertices[base + 1].unk_0x14 = lbl_80562D44;
    vertices[base + 2].unk_0x14 = lbl_80562D48;
    vertices[base + 3].unk_0x14 = lbl_80562D44;

    if (count > 2) {
        index = lbl_8055EAAC;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + index * 2) = count - 3;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + (index + 1) * 2) = count - 2;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + (index + 2) * 2) = count - 1;
        lbl_8055EAAC = index + 3;
    }
    lbl_8055EAA8 = count + 1;
    if (count + 1 > 2) {
        index = lbl_8055EAAC;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + index * 2) = count - 2;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + (index + 1) * 2) = count - 1;
        *(u16 *)((u8 *)lbl_80487578 + 0x5a0 + (index + 2) * 2) = count;
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

void fn_801E53A8(void *arg0, void *arg1, void *arg2, s32 arg3, f32 arg4) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sx;
    f32 sy;
    f32 sz;
    (void)arg1;
    (void)arg4;
    if (lbl_80487C88.unk_0x28 >= lbl_80487C88.unk_0x30) {
        fn_802E317C((void *)0);
    }
    ax = *(f32 *)((u8 *)arg0 + 0x0);
    cx = *(f32 *)((u8 *)arg2 + 0x0);
    dx = ax - cx;
    sx = ax + cx;
    ay = *(f32 *)((u8 *)arg0 + 0x4);
    cy = *(f32 *)((u8 *)arg2 + 0x4);
    dy = ay - cy;
    sy = ay + cy;
    az = *(f32 *)((u8 *)arg0 + 0x8);
    cz = *(f32 *)((u8 *)arg2 + 0x8);
    dz = az - cz;
    sz = az + cz;
    (void)dx; (void)dy; (void)dz; (void)sx; (void)sy; (void)sz;
    (void)arg3;
}

#pragma pop
/* End the current mesh pass: flush/compact the vertex and index buffers
 * (fn_801E4E44) and reset the mesh mode (lbl_8055EAB0) to 0 (idle). */
void fn_801E58FC(void) {
    fn_801E4E44();
    lbl_8055EAB0 = 0;
}

