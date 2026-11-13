#include <types.h>
#include <revolution/MTX/vec.h>
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
typedef struct E2640Query { Vec position; Vec direction; f32 *dot; u8 found; u8 pad[3]; s32 (*filter)(s32); } E2640Query;
typedef struct E2640Scratch { s32 count; f32 dot; } E2640Scratch;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct VTable_801E2084 { void *unk0; void *unk4; void *unk8; void *unkC; void (*call)(void *, void *); } VTable_801E2084;
typedef struct Obj_801E2084 { VTable_801E2084 *vtable; } Obj_801E2084;
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
extern "C" void fn_801E1F8C(void *arg0, void *arg1) {
    class Obj {
      public:
        virtual void v0();
        virtual void v1();
        virtual void call(void *);
    };
    int count0 = *(int *)((char *)arg0 + 0x24);
    int count1;
    void *item;
    int j;
    void **entry1;
    void **entry0;
    int i;
    Obj *obj;
    if (count0 != 0) {
        obj = count0 > 0 ? (Obj *)((void **)arg0)[5] : (Obj *)0;
        if (*(int *)((char *)obj + 0x20) == 0x72) {
            count1 = *(int *)((char *)arg1 + 0x24);
            if (count1 != 0) {
                item = count1 > 0 ? ((void **)arg1)[5] : 0;
                if (*(int *)((char *)item + 0x20) == 0x72)
                    return;
            }
        }
    }
    entry1 = (void **)arg1;
    i = 0;
    while (i < *(int *)((char *)arg1 + 0x24)) {
        if (i >= 0 && i < *(int *)((char *)arg1 + 0x24))
            item = entry1[5];
        else
            item = 0;
        entry0 = (void **)arg0;
        j = 0;
        while (j < *(int *)((char *)arg0 + 0x24)) {
            obj = (Obj *)entry0[5];
            obj->call(item);
            entry0++;
            j++;
        }
        entry1++;
        i++;
    }
}
#pragma pop
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
extern "C" void fn_801E2084(void *arg0, void *arg1) {
    class Obj {
      public:
        virtual void v0();
        virtual void v1();
        virtual void call(void *);
    };
    int i = 0;
    void **entry = (void **)arg1;
    while (i < *(int *)((char *)arg1 + 0x24)) {
        Obj *obj = *(Obj **)((char *)entry + 0x14);
        obj->call(arg0);
        entry++;
        i++;
    }
}
#pragma pop
void fn_801E2100(void *arg0, void *arg1) {
    int result;
    int (*first)(int);
    first = *(int (**)(int))((char *)arg1 + 0x20);
    if (first == 0 || first(*(int *)((char *)arg0 + 0x20)) != 0) {
        result = ((struct Dummy_801E2100 *)arg0)->f6(arg1, (char *)arg1 + 0xC, *(int *)((char *)arg1 + 0x18), &result);
        if (result != 0)
            *((unsigned char *)arg1 + 0x1C) = 1;
    }
}
#pragma dont_inline reset

void *fn_801A4548(void *);
extern void *lbl_80339890[];
void fn_801E2188(void) {
    lbl_8055EA3C = fn_801A4548(&lbl_80339890[0]);
}

void fn_801E21B4(void* hi) {
    lbl_8055EA40 = hi;
}

#pragma scheduling invalid_target
void fn_801E21BC(void) {
    int values[2];
    int *var_r31;
    u32 var_r30;
    var_r31 = values;
    var_r30 = 0U;
    lbl_8055EA38 = 1;
    values[0] = (int)lbl_8055EA3C;
    values[1] = (int)lbl_8055EA40;
    do {
        fn_801A47FC(*var_r31);
        var_r30 += 1;
        var_r31++;
    } while (var_r30 < 2U);
    fn_8015F670(values, 2);
}
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

void fn_801E2294(void) {
    if (lbl_8055EA3C != 0)
        ((void (*)(void *))fn_801A47C8)(lbl_8055EA3C);
    if (lbl_8055EA40 != 0)
        ((void (*)(void *))fn_801A47C8)(lbl_8055EA40);
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
    void *item;
    void *g;
    void **node;
    void **cellp;
    void *hits[5];
    s32 cnt;
    f32 scale;
    s32 xi, zi;
    s32 minX, maxX, minZ, maxZ;
    s32 idx;
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
            g = lbl_8055EA3C;
            if (g != 0) {
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
            g = lbl_8055EA40;
            if (g != 0) {
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

