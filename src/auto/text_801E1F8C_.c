#include <types.h>
#include <revolution/MTX/vec.h>
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
typedef struct E2640Query { Vec position; Vec direction; f32 *dot; u8 found; u8 pad[3]; s32 (*filter)(s32); } E2640Query;
typedef struct E2640Scratch { s32 count; f32 dot; } E2640Scratch;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct VTable_801E2084 { void *unk0; void *unk4; void *unk8; void *unkC; void (*call)(void *, void *); } VTable_801E2084;
typedef struct Obj_801E2084 { VTable_801E2084 *vtable; } Obj_801E2084;
/* A collision group: solidCount solid pointers in an array that starts at +0x14
   (the walkers below step a one-word cursor over it, so slot[5] is the first
   solid); fn_801E1F8C pairs two groups up, fn_801E2084 hands one object to
   every solid of a group. */
struct SolidGroup {
    u8 pad_0[0x24];
    s32 solidCount;
};
#pragma cplusplus on
struct Dummy_801E2100 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f6(void *a1, void *a2, int a3, int *a4);
};
#pragma cplusplus off
extern void *lbl_8055EA40;
extern void *lbl_8055EA3C;
extern char lbl_8055EA38;
extern f32 lbl_80562CD8;
extern f32 lbl_80562CDC;
extern f32 lbl_80562CE0;
extern f32 lbl_80562CE4;
extern s32 lbl_8055E3C4;
extern char lbl_8033989C[];
void fn_801B619C(void *, s32 *, f32 *);
s32 fn_801A4E88(void *, f32 *, f32 *, s32, s32 *);
void fn_802E30C8(const char *, ...);
void fn_801A47C8(void);
void fn_801A47FC(int);
void fn_8015F670(int *, int);
#pragma use_lmw_stmw off
#pragma push
#pragma cplusplus on
extern "C" void fn_801E1F8C(void *group, void *other) {
    /* Broadphase pair test: hand every solid of `other` to every solid of
     * `group` (their collide method, vtable +0x10).  Two groups whose first
     * solid is of collision type 'r' are left alone -- that type does not
     * collide with itself.  A group is a solid list at +0x14 with its count
     * at +0x24; the loops below walk the list with a one-word cursor, so
     * entry[5] is the cursor's solid. */
    class Solid {
      public:
        virtual void v0();
        virtual void v1();
        virtual void collide(void *other);  /* vtable +0x10 */
        char pad_4[0x1C];
        s32 type;                           /* +0x20 collision type */
    };
    s32 count = *(s32 *)((char *)group + 0x24);
    s32 otherCount;
    void *otherSolid;
    s32 j;
    void **otherSlot;
    void **slot;
    s32 i;
    Solid *solid;
    if (count != 0) {
        solid = count > 0 ? (Solid *)((void **)group)[5] : (Solid *)0;
        if (solid->type == 0x72 /* 'r' */) {
            otherCount = *(s32 *)((char *)other + 0x24);
            if (otherCount != 0) {
                otherSolid = otherCount > 0 ? ((void **)other)[5] : 0;
                if (((Solid *)otherSolid)->type == 0x72 /* 'r' */)
                    return;
            }
        }
    }
    otherSlot = (void **)other;
    i = 0;
    while (i < *(s32 *)((char *)other + 0x24)) {
        if (i >= 0 && i < *(s32 *)((char *)other + 0x24))
            otherSolid = otherSlot[5];
        else
            otherSolid = 0;
        slot = (void **)group;
        j = 0;
        while (j < *(s32 *)((char *)group + 0x24)) {
            solid = (Solid *)slot[5];
            solid->collide(otherSolid);
            slot++;
            j++;
        }
        otherSlot++;
        i++;
    }
}
#pragma pop
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
/* Hand `object` to every solid of the collision group `group`: its solids are an
 * array at +0x14 with their count at +0x24, and each one's collide method
 * (vtable +0x10) is called with `object`.  The one-sided form of fn_801E1F8C,
 * which hands every solid of one group to every solid of another. */
extern "C" void fn_801E2084(void *object, void *group) {
    class Solid {
      public:
        virtual void v0();
        virtual void v1();
        virtual void collide(void *other);  /* vtable +0x10 */
    };
    s32 i = 0;
    void **slot = (void **)group;
    while (i < ((struct SolidGroup *)group)->solidCount) {
        Solid *solid = *(Solid **)((char *)slot + 0x14);
        solid->collide(object);
        slot++;
        i++;
    }
}
#pragma pop
void fn_801E2100(void *solid, void *query) {
    /* Test ray/direction query `query` (E2640Query) against `solid`: if `query`'s
     * optional collision-type filter (+0x20) accepts `solid`'s type (+0x20) and
     * `solid`'s virtual intersection test (vtable +0x18) hits, set `query->found` (+0x1C). */
    int hit;
    int (*filter)(int);
    filter = *(int (**)(int))((char *)query + 0x20);
    if (filter == 0 || filter(*(int *)((char *)solid + 0x20)) != 0) {
        hit = ((struct Dummy_801E2100 *)solid)->f6(query, (char *)query + 0xC, *(int *)((char *)query + 0x18), &hit);
        if (hit != 0)
            *((unsigned char *)query + 0x1C) = 1;
    }
}
#pragma dont_inline reset

void *fn_801A4548(void *);
extern void *lbl_80339890[];
void fn_801E2188(void) {
    /* Static initializer: load the "track.sol" collision-group resource and cache
     * the resulting pointer as the primary collision group in lbl_8055EA3C. */
    lbl_8055EA3C = fn_801A4548(&lbl_80339890[0]);
}

void fn_801E21B4(void *collisionGroup) {
    /* Cache `collisionGroup` as the active secondary collision group, paired
     * with the primary group cached by fn_801E2188. */
    #define gSecondaryCollisionGroup lbl_8055EA40
    gSecondaryCollisionGroup = collisionGroup;
    #undef gSecondaryCollisionGroup
}

#pragma scheduling invalid_target
/* Submits the two active collision-group resources for processing and marks the
 * collision system as initialized. */
void fn_801E21BC(void) {
#define gCollisionGroupsReady lbl_8055EA38
#define gPrimaryCollisionGroup lbl_8055EA3C
#define gSecondaryCollisionGroup lbl_8055EA40
#define CollisionGroup_prepare fn_801A47FC
#define CollisionSystem_commit fn_8015F670
    int resourceHandles[2];
    int *resourceCursor;
    u32 index;

    resourceCursor = resourceHandles;
    index = 0U;
    gCollisionGroupsReady = 1;
    resourceHandles[0] = (int)gPrimaryCollisionGroup;
    resourceHandles[1] = (int)gSecondaryCollisionGroup;
    do {
        CollisionGroup_prepare(*resourceCursor);
        index += 1;
        resourceCursor++;
    } while (index < 2U);
    CollisionSystem_commit(resourceHandles, 2);
#undef gCollisionGroupsReady
#undef gPrimaryCollisionGroup
#undef gSecondaryCollisionGroup
#undef CollisionGroup_prepare
#undef CollisionSystem_commit
}
/* Clears collision-group readiness and tears down both active collision groups (vtable slot at +0x14), then clears their pointers. */
void fn_801E222C(void) {
    lbl_8055EA38 = 0;
    if (lbl_8055EA3C != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA3C + 0x14)))();
        lbl_8055EA3C = 0;
    }
    if (lbl_8055EA40 != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA40 + 0x14)))();
        lbl_8055EA40 = 0;
    }
}

/* Enables every solid in both active collision groups by marking each entry active. */
void fn_801E2294(void) {
#define gPrimaryCollisionGroup lbl_8055EA3C
#define gSecondaryCollisionGroup lbl_8055EA40
#define CollisionGroup_enableAll fn_801A47C8
    if (gPrimaryCollisionGroup != 0)
        ((void (*)(void *))CollisionGroup_enableAll)(gPrimaryCollisionGroup);
    if (gSecondaryCollisionGroup != 0)
        ((void (*)(void *))CollisionGroup_enableAll)(gSecondaryCollisionGroup);
#undef gPrimaryCollisionGroup
#undef gSecondaryCollisionGroup
#undef CollisionGroup_enableAll
}

/* Descends one quadtree (lbl_8055EA3C / lbl_8055EA40) towards p's x/z cell and
   tests p against every enabled entry of each node on the way down. */
static inline void QueryTree(void *g, void *p, f32 scale) {
    if (g != 0) {
        s32 minX, maxX, minZ, maxZ;
        s32 xi, zi;
        s32 idx;
        minX = -0x2625A00;
        maxX = 0x2625A00;
        minZ = minX;
        maxZ = maxX;
        xi = (s32)(scale * ((f32 *)p)[24]);
        zi = (s32)(scale * ((f32 *)p)[26]);
        idx = 0;
        for (;;) {
            u16 *range = (u16 *)((char *)*(void **)((char *)g + 0x10) + idx * 8);
            s32 end, k, midX, midZ;
            k = range[0];
            end = range[1];
            for (; k < end; k++) {
                u16 tri = *(u16 *)((char *)*(void **)((char *)g + 0x0C) + k * 2);
                void *tobj = *(void **)((char *)*(void **)((char *)g + 4) + tri * 4);
                if (*(u8 *)((char *)tobj + 0x40))
                    fn_801E2084(*(void **)((char *)tobj + 0x3C), p);
            }
            if (range[2] == 0)
                break;
            idx = range[2];
            midX = (minX + maxX) >> 1;
            midZ = (minZ + maxZ) >> 1;
            if (zi <= midZ) {
                maxZ = midZ;
                if (xi <= midX)
                    maxX = midX;
                else {
                    minX = midX;
                    idx += 1;
                }
            } else {
                minZ = midZ;
                if (xi <= midX) {
                    maxX = midX;
                    idx += 2;
                } else {
                    minX = midX;
                    idx += 3;
                }
            }
        }
    }
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma auto_inline off
#pragma cplusplus on
extern "C" void fn_801E22D0(void **arg0, s32 arg1) {
    class V1 {
      public:
        virtual s32 v0();
        virtual s32 v1();
    };
    class V15 {
      public:
        virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
        virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7();
        virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11();
        virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15();
    };
    void **slot;
    s32 i;
    void *grp;
    s32 j;
    void *it;
    register void *item;
    void **node;
    void **cellp;
    void *hits[5];
    s32 cnt;
    f32 scale;
    s32 xi, zi;
    s32 minX, minZ, maxX, maxZ;
    unsigned int idx;
    s32 i2, j2;
    void *p;
    for (i = 0; i < arg1; i++) {
        grp = arg0[i];
        slot = (void **)grp;
        for (j = 0; j < *(s32 *)((char *)grp + 0x24); j++) {
            if (j >= 0 && j < *(s32 *)((char *)grp + 0x24))
                it = slot[5];
            else
                it = 0;
            ((V1 *)it)->v1();
            slot++;
        }
    }
    scale = lbl_80562CD8;
    for (i2 = 0; i2 < arg1; i2++) {
        p = arg0[i2];
        if (*(s32 *)((char *)p + 0x24) > 0) {
            cnt = 5;
            fn_801B619C(hits, &cnt, (f32 *)((char *)p + 0x60));
            cellp = (void **)hits;
            for (j2 = 0; j2 < cnt; cellp++, j2++) {
                node = *(void ***) *cellp;
                while (node != 0) {
                    item = *node;
                    if ((p < item) || (((V15 *)item)->v15() == 0))
                        fn_801E1F8C(p, item);
                    node = *(void ***)((char *)node + 4);
                }
            }
            item = lbl_8055EA3C;
            if (item) {
                minX = -0x2625A00;
                maxX = 0x2625A00;
                minZ = minX;
                maxZ = maxX;
                register xi = (s32)(scale * ((f32 *)p)[24]);
                zi = (s32)(scale * ((f32 *)p)[26]);
                idx = 0;
                for (;;) {
                    u16 *range = (u16 *)((char *)*(void **)((char *)item + 0x10) + idx * 8);
                    s32 end, k, midX, midZ;
                    k = range[0];
                    end = range[1];
                    for (; k < end; k++) {
                        u16 tri = *(u16 *)((char *)*(void **)((char *)item + 0x0C) + k * 2);
                        void *tobj = *(void **)((char *)*(void **)((char *)item + 4) + tri * 4);
                        if (*(u8 *)((char *)tobj + 0x40))
                            fn_801E2084(*(void **)((char *)tobj + 0x3C), p);
                    }
                    if (range[2] == 0)
                        break;
                    {
                        idx = range[2];
                        midX = (minX + maxX) >> 1;
                        midZ = (minZ + maxZ) >> 1;
                        if (zi <= midZ) {
                            maxZ = midZ;
                            if (xi <= midX)
                                maxX = midX;
                            else {
                                minX = midX;
                                idx += 1;
                            }
                        } else {
                            minZ = midZ;
                            if (xi <= midX) {
                                maxX = midX;
                                idx += 2;
                            } else {
                                minX = midX;
                                idx += 3;
                            }
                        }
                    }
                }
            }
            item = lbl_8055EA40;
            if ((s32)item != 0) {
                minX = -0x2625A00;
                maxX = 0x2625A00;
                minZ = minX;
                maxZ = maxX;
                xi = (s32)(scale * ((f32 *)p)[24]);
                zi = (s32)(scale * ((f32 *)p)[26]);
                idx = 0;
                for (;;) {
                    u16 *range = (u16 *)((char *)*(void **)((char *)item + 0x10) + idx * 8);
                    s32 end, k, midX, midZ;
                    k = range[0];
                    end = range[1];
                    for (; k < end; k++) {
                        u16 tri = *(u16 *)((char *)*(void **)((char *)item + 0x0C) + k * 2);
                        void *tobj = *(void **)((char *)*(void **)((char *)item + 4) + tri * 4);
                        if (*(u8 *)((char *)tobj + 0x40))
                            fn_801E2084(*(void **)((char *)tobj + 0x3C), p);
                    }
                    if (range[2] == 0)
                        break;
                    {
                        idx = range[2];
                        midX = (minX + maxX) >> 1;
                        midZ = (minZ + maxZ) >> 1;
                        if (zi <= midZ) {
                            maxZ = midZ;
                            if (xi <= midX)
                                maxX = midX;
                            else {
                                minX = midX;
                                idx += 1;
                            }
                        } else {
                            minZ = midZ;
                            if (xi <= midX) {
                                maxX = midX;
                                idx += 2;
                            } else {
                                minX = midX;
                                idx += 3;
                            }
                        }
                    }
                }
            }
        }
    }
}
#pragma pop
extern double __fabs(double);
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
#pragma auto_inline off
extern "C" s32 fn_801E2640(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 *arg4, void **arg5, void **arg6, s32 arg7, s32 (*arg_sp8)(s32)) {
    class Item {
      public:
        virtual s32 m0(); virtual s32 m1(); virtual s32 m2(); virtual s32 m3();
        virtual s32 m4(f32 *, f32 *, f32 *, s32);
    };
    class Node {
      public:
        virtual s32 v0(); virtual s32 v1(); virtual s32 v2(); virtual s32 v3();
        virtual s32 v4(); virtual s32 v5(); virtual s32 v6(); virtual s32 v7();
        virtual s32 v8(); virtual s32 v9(); virtual s32 v10(); virtual s32 v11();
        virtual s32 v12(); virtual s32 v13(); virtual s32 v14(); virtual s32 v15();
        void *pad[4];
        Item *items[4];
        s32 count;
        Item *getItem(s32 idx) {
            if (idx >= 0 && idx < count) return items[idx];
            return 0;
        }
    };
    f32 dot;
    s32 count;
    s32 finalResult;
    void *meshLists[2];
    void *objLists[2];
    f32 delta[3];
    f32 normal[3];
    void *hits[5];
    E2640Query queryStorage;
    s32 xIndex;
    s32 zIndex;
    f32 rangeScale;
    f32 mag, scale, clampMag;
    f32 diffX, diffY, diffZ;
    f32 threshold;
    f32 dirZ, dirY, dirX, posZ, posY, posX;
    register s32 found;
    Item *item;
    Node *obj;
    void **node;
    void **hitp;
    void **slot;
    s32 i, j;
    s32 value;
    u32 meshIndex;
    diffX = arg1[0] - arg0[0];
    diffY = arg1[1] - arg0[1];
    diffZ = arg1[2] - arg0[2];
    delta[0] = diffX;
    delta[1] = diffY;
    delta[2] = diffZ;
    mag = PSVECMag((Vec *)delta);
    clampMag = lbl_80562CDC;
    clampMag = (clampMag > mag) ? clampMag : mag;
    scale = lbl_80562CE0 / clampMag;
    normal[0] = delta[0] * scale;
    normal[1] = delta[1] * scale;
    normal[2] = delta[2] * scale;
    dot = PSVECDotProduct((Vec *)normal, (Vec *)delta);
    found = 0;
    threshold = lbl_80562CE4;
    *arg5 = 0;
    if (threshold < (f32)__fabs((f64)normal[1])) {
        count = 5;
        fn_801B619C(hits, &count, arg0);
        hitp = hits;
        for (i = 0; i < count; hitp++, i++) {
            node = *(void ***)*hitp;
            while (node) {
                obj = (Node *)*node;
                if (obj && obj->v15()) {
                    slot = (void **)obj;
                    for (j = 0; j < *(s32 *)((char *)obj + 0x24); j++) {
                        if (j >= 0 && j < *(s32 *)((char *)obj + 0x24)) item = (Item *)slot[5];
                        else item = 0;
                        value = *(s32 *)((char *)item + 0x20);
                        if ((!arg_sp8 || arg_sp8(value)) &&
                            item->m4(arg0, normal, &dot, arg3)) {
                            *arg4 = value;
                            found = 1;
                            *arg5 = obj;
                        }
                        slot++;
                    }
                }
                node = *(void ***)((char *)node + 4);
            }
        }
        posX = arg0[0];
        posY = arg0[1];
        posZ = arg0[2];
        dirX = normal[0];
        dirY = normal[1];
        dirZ = normal[2];
        meshLists[0] = lbl_8055EA3C;
        meshLists[1] = lbl_8055EA40;
        rangeScale = lbl_80562CD8;
        queryStorage.position.x = posX;
        queryStorage.position.y = posY;
        queryStorage.position.z = posZ;
        queryStorage.direction.x = dirX;
        queryStorage.direction.y = dirY;
        queryStorage.direction.z = dirZ;
        queryStorage.dot = &dot;
        queryStorage.found = found;
        queryStorage.filter = arg_sp8;
        for (meshIndex = 0; meshIndex != 2; meshIndex++) {
            void *mesh = meshLists[meshIndex];
            if (mesh) {
                s32 minX = -0x2625A00, maxX = 0x2625A00;
                s32 minZ = -0x2625A00, maxZ = 0x2625A00;
                s32 index;
                xIndex = (s32)(rangeScale * arg0[0]);
                zIndex = (s32)(rangeScale * arg0[2]);
                index = 0;
                for (;;) {
                    u16 *range = (u16 *)((char *)*(void **)((char *)mesh + 0x10) + index * 8);
                    s32 k, end, midX, midZ;
                    k = range[0];
                    end = range[1];
                    for (; k < end; k++) {
                        u16 tri = *(u16 *)((char *)*(void **)((char *)mesh + 0x0C) + k * 2);
                        void *tobj = *(void **)((char *)*(void **)((char *)mesh + 4) + tri * 4);
                        if (*(u8 *)((char *)tobj + 0x40))
                            fn_801E2100(*(void **)((char *)tobj + 0x3C), &queryStorage);
                    }
                    if (range[2] == 0) break;
                    {
                        index = range[2];
                        midX = (minX + maxX) >> 1;
                        midZ = (minZ + maxZ) >> 1;
                        if (zIndex <= midZ) {
                            maxZ = midZ;
                            if (xIndex <= midX) maxX = midX;
                            else { minX = midX; index += 1; }
                        } else {
                            minZ = midZ;
                            if (xIndex <= midX) { maxX = midX; index += 2; }
                            else { minX = midX; index += 3; }
                        }
                    }
                }
            }
        }
        found = queryStorage.found;
    } else {
        fn_802E30C8((const char *)&lbl_8033989C, lbl_8055E3C4);
        for (i = 0; i < arg7; i++) {
            obj = (Node *)arg6[i];
            if (obj && obj->v15()) {
                for (j = 0; j < obj->count; j++) {
                    item = obj->getItem(j);
                    value = *(s32 *)((char *)item + 0x20);
                    if ((!arg_sp8 || arg_sp8(value)) &&
                        item->m4(arg0, normal, &dot, arg3)) {
                        *arg4 = value;
                        found = 1;
                        *arg5 = obj;
                    }
                }
            }
        }
        objLists[0] = lbl_8055EA3C;
        objLists[1] = lbl_8055EA40;
        for (meshIndex = 0; meshIndex != 2; meshIndex++) {
            if (objLists[meshIndex]) {
                for (j = 0; j < *(s32 *)objLists[meshIndex]; j++) {
                    item = *(Item **)(*(char **)((char *)objLists[meshIndex] + 4) + j * 4);
                    if (*(u8 *)((char *)item + 0x40)) {
                        void *sub = *(void **)((char *)item + 0x3C);
                        if (((Item *)sub)->m4(arg0, normal, &dot, arg3)) {
                            found = 1;
                            *arg4 = *(s32 *)((char *)*(void **)((char *)item + 0x3C) + 0x20);
                            *arg5 = 0;
                        }
                    }
                }
            }
        }
    }
    if (fn_801A4E88(arg0, normal, &dot, arg3, &finalResult)) {
        found = 1;
        *arg4 = finalResult;
        *arg5 = 0;
    }
    if (found) {
        f32 tailScale = dot;
        arg2[0] += normal[0] * tailScale;
        arg2[1] += normal[1] * tailScale;
        arg2[2] += normal[2] * tailScale;
    }
    return found;
}
#pragma pop

