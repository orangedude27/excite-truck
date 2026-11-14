#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct PhobNode {
    s32 value;
    struct PhobNode *next;
} PhobNode;

extern s32 lbl_8055E708;
extern s32 lbl_8055E70C;
extern s32 lbl_8055E714;
extern void fn_80128668(s32);
extern void fn_80128670(s32);
extern f32 lbl_805626B0;
extern f32 lbl_805626B4;
extern void *lbl_8055E710;
extern char lbl_80335EE0[];
extern void fn_802E317C(const char *, ...);
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_801B5F40(void) {
    void *node = lbl_8055E710;
    if (node) {
        lbl_8055E710 = ((void **)node)[1];
        ((void **)node)[1] = 0;
        return node;
    }
    fn_802E317C(lbl_80335EE0);
    return 0;
}
#pragma scheduling on
#pragma dont_inline reset

void __AXPushCallbackStack(void *arg0) {
    *((void **)arg0 + 1) = lbl_8055E710;
    lbl_8055E710 = arg0;
}

extern void *fn_8012850C(s32, void *);
extern s32 fn_8002F37C(void *, void *, s32, s32, s32);
extern void *fn_801284F8(s32, void *);
extern void NWC24Data_Init_801B6098(s32 *);
extern void fn_801B608C(s32 *);
extern s32 lbl_8055A8D0;
#pragma scheduling invalid_target
void fn_801B5FA0(void) {
    /* Initialize the Phob (physics object) node pools and free list. */
    s32 count;
    s32 offset;
    s32 i;
    void *node;
    void *memory;

    count = lbl_8055A8D0;
    memory = fn_8012850C((count << 3) + 0x10, lbl_80335EE0 + 0x18);
    lbl_8055E708 = fn_8002F37C(memory, (void *)NWC24Data_Init_801B6098, 0, 8, count);
    memory = fn_8012850C(0x9C50, lbl_80335EE0 + 0x28);
    lbl_8055E70C = fn_8002F37C(memory, (void *)fn_801B608C, 0, 4, 0x2710);
    count = 0;
    lbl_8055E710 = 0;
    node = fn_801284F8(4, lbl_80335EE0 + 0x34);
    if (node != 0) {
        *(s32 *)node = count;
    }
    lbl_8055E714 = (s32)node;
    i = 0;
    offset = 0;
    while (i < lbl_8055A8D0) {
        i++;
        node = (u8 *)lbl_8055E708 + offset;
        *(void **)((u8 *)node + 4) = lbl_8055E710;
        offset += 8;
        lbl_8055E710 = node;
    }
}
#pragma scheduling on
void fn_801B608C(s32 *arg0) {
    *arg0 = 0;
}

void NWC24Data_Init_801B6098(s32 *arg0) { arg0[0] = 0; arg0[1] = 0; }

void fn_801B60A8(void) {
    fn_80128668(lbl_8055E714);
    if (lbl_8055E708 != 0) fn_80128670(lbl_8055E708 - 0x10);
    if (lbl_8055E70C != 0) fn_80128670(lbl_8055E70C - 0x10);
}

extern float lbl_805626B8;
static inline s32 GridCell(f32 v) {
    s32 i;
    v += 1000.0f;
    i = (s32)(v / 20.0f);
    if (i < 0)
        i = 0;
    else if (i >= 0x64)
        i = 0x63;
    return i;
}

/* Returns the PhobList head for an object at pos with bounding radius: objects
   larger than one 20-unit grid cell go into the global bigphoblist (lbl_8055E714),
   and smaller ones go into the 100x100 XZ cell grid (lbl_8055E70C). */
s32 fn_801B60F4(void *pos, f32 radius) {
    s32 cellX;
    s32 cellZ;
    if (radius > 20.0f)
        return lbl_8055E714;
    cellX = GridCell(((f32 *)pos)[0]);
    cellZ = GridCell(((f32 *)pos)[2]);
    return lbl_8055E70C + ((cellX + cellZ * 0x64) * 4);
}

#pragma sym off
/*
 * PhobList gather: collects the phob (physics object) lists to test against a
 * point. The world's XZ plane is a 100x100 grid of 20-unit cells starting at
 * -1000 (lbl_8055E70C, "phoblist": one list head per cell). Returns in outLists
 * the cells touched by a 9.6-unit box around pos (1, 2 or 4 of them), followed
 * by the "bigphoblist" (lbl_8055E714) of objects too large for a cell;
 * *outCount receives how many lists were written.
 */
void fn_801B619C(u32 *outLists, s32 *outCount, const f32 *pos) {
    s32 minX = GridCell(pos[0] - 9.599999f);
    s32 maxX = GridCell(9.599999f + pos[0]);
    s32 minZ = GridCell(pos[2] - 9.599999f);
    s32 maxZ = GridCell(9.599999f + pos[2]);
    if (minX != maxX) {
        if (minZ != maxZ) {
            *outCount = 4;
            outLists[0] = lbl_8055E70C + ((minX + minZ * 100) * 4);
            outLists[1] = lbl_8055E70C + ((maxX + minZ * 100) * 4);
            outLists[2] = lbl_8055E70C + ((minX + maxZ * 100) * 4);
            outLists[3] = lbl_8055E70C + ((maxX + maxZ * 100) * 4);
        } else {
            *outCount = 2;
            outLists[0] = lbl_8055E70C + ((minX + minZ * 100) * 4);
            outLists[1] = lbl_8055E70C + ((maxX + minZ * 100) * 4);
        }
    } else if (minZ != maxZ) {
        *outCount = 2;
        outLists[0] = lbl_8055E70C + ((minX + minZ * 100) * 4);
        outLists[1] = lbl_8055E70C + ((minX + maxZ * 100) * 4);
    } else {
        *outCount = 1;
        outLists[0] = lbl_8055E70C + ((minX + minZ * 100) * 4);
    }
    {
        /* Big phobs are always tested. */
        outLists[(*outCount)++] = lbl_8055E714;
    }
}
#pragma sym on
extern void *fn_801B5F40(void);
extern void __AXPushCallbackStack(void *);
extern char lbl_80335F20[];
void fn_801B63E0(void **head, s32 value) {
    void *node = fn_801B5F40();
    *(s32 *)node = value;
    *(void **)((u8 *)node + 4) = *head;
    *head = node;
}

#pragma scheduling on
#pragma dont_inline on
void fn_801B6428(void **head, void *value) {
    void *node = *head;
    void *prev;
    void *cur;
    if (*(void **)node == value) {
        *head = *(void **)((u8 *)node + 4);
        __AXPushCallbackStack(node);
        return;
    }
    prev = node;
    cur = *(void **)((u8 *)node + 4);
    while (cur != 0) {
        if (*(void **)cur == value) {
            *(void **)((u8 *)prev + 4) = *(void **)((u8 *)cur + 4);
            __AXPushCallbackStack(cur);
            return;
        }
        prev = cur;
        cur = *(void **)((u8 *)cur + 4);
    }
    fn_802E317C(lbl_80335F20);
}
