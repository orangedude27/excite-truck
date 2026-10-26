#include <types.h>
#include <revolution/MTX/vec.h>
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
typedef struct E2640Query { Vec position; Vec direction; f32 *dot; u8 found; u8 pad[3]; s32 (*filter)(s32); } E2640Query;
typedef struct E2640Scratch { s32 count; f32 dot; } E2640Scratch;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
#pragma scheduling off
void fn_801E1F8C(void *arg0, void *arg1) {
    void *obj;
    void *item;
    int j;
    int i;
    void **p1;
    void **p0;
    int count1;
    int count0;
    count0 = *(int *)((char *)arg0 + 0x24);
    if (count0 == 0) return;
    p0 = (count0 > 0) ? *(void ***)((char *)arg0 + 0x14) : 0;
    if (*(int *)((char *)p0 + 0x20) != 0x72) return;
    count1 = *(int *)((char *)arg1 + 0x24);
    if (count1 == 0) return;
    p1 = (count1 > 0) ? *(void ***)((char *)arg1 + 0x14) : 0;
    if (*(int *)((char *)p1 + 0x20) != 0x72) return;
    i = 0;
    while (i < *(int *)((char *)arg1 + 0x24)) {
        item = p1[i];
        j = 0;
        while (j < *(int *)((char *)arg0 + 0x24)) {
            obj = p0[j];
            ((void (*)(void *, void *))(*(void ***)obj)[4])(obj, item);
            j++;
        }
        i++;
    }
}

void fn_801E2084(void *arg0, void *arg1) {
    int i = 0;
    void **entry = (void **)arg1;
    while (i < *(int *)((char *)arg1 + 0x24)) {
        void *obj = *(void **)((char *)entry + 0x14);
        ((void (*)(void *, void *))(*(void ***)obj)[4])(obj, arg0);
        entry++;
        i++;
    }
}
#pragma scheduling on
#pragma dont_inline on
void fn_801E2100(void *arg0, void *arg1) {
    int result;
    int (*first)(int);
    int (*second)(void *, void *, void *, int, int *);
    first = *(int (**)(int))((char *)arg1 + 0x20);
    if (first == 0 || first(*(int *)((char *)arg0 + 0x20)) != 0) {
        int arg4 = *(int *)((char *)arg1 + 0x18);
        result = ((int (*)(void *, void *, void *, int, int *))(*(void ***)arg0)[3])(arg0, arg1, (char *)arg1 + 0xC, arg4, &result);
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

void fn_801E21BC(void) {
    int values[2];
    int i;
    values[0] = (int)lbl_8055EA3C;
    values[1] = (int)lbl_8055EA40;
    lbl_8055EA38 = 1;
    for (i = 0; i < 2; i++)
        fn_801A47FC(values[i]);
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

extern double __fabs(double);
#pragma ppc_psq_save off
#pragma scheduling invalid_target
s32 fn_801E2640(f32 *arg0, f32 *arg1, register f32 *arg2, s32 arg3, s32 *arg4, void **arg5, void **arg6, s32 arg7, s32 (*arg_sp8)(s32)) {
    f32 delta[3], normal[3], dot, mag, scale, clampMag;
    f32 diffX, diffY, targetY, targetZ;
    struct { E2640Query query; } queryStorage;
    f32 rangeScale;
    void *hits[5];
    struct { u32 pad[2]; void *items[2]; } listStorage;
    register s32 found;
    s32 count, finalResult, i, j;
    u32 meshIndex;
    diffX = arg1[0] - arg0[0];
    targetY = arg1[1];
    diffY = targetY - arg0[1];
    targetZ = arg1[2];
    delta[0] = diffX;
    delta[1] = diffY;
    delta[2] = targetZ - arg0[2];
    mag = PSVECMag((Vec *)delta);
    clampMag = lbl_80562CDC;
    clampMag = (clampMag > mag) ? clampMag : mag;
    scale = lbl_80562CE0 / clampMag;
    normal[0] = delta[0] * scale;
    normal[1] = delta[1] * scale;
    normal[2] = delta[2] * scale;
    dot = PSVECDotProduct((Vec *)normal, (Vec *)delta);
    *arg5 = 0;
    found = 0;
    if ((f32)__fabs((f64)normal[1]) > lbl_80562CE4) {
        count = 5;
        fn_801B619C(hits, &count, arg0);
        for (i = 0; i < count; i++) {
            void **node = *(void ***)hits[i];
            while (node != 0) {
                void *obj = *node;
                if (obj && (*(s32 (**)(void *))(*(void ***)obj + 0x11))(obj)) {
                    void *slot = obj;
                    for (j = 0; j < *(s32 *)((char *)obj + 0x24); j++) {
                        void *item;
                        s32 value;
                        if (j >= 0 && j < *(s32 *)((char *)obj + 0x24)) item = *(void **)((char *)slot + 0x14);
                        else item = 0;
                        value = *(s32 *)((char *)item + 0x20);
                        if ((!arg_sp8 || arg_sp8(value)) &&
                            (*(s32 (**)(void *, void *, f32 *, f32 *, s32))(*(void ***)item + 6))
                            (item, arg0, normal, &dot, arg3)) {
                            *arg4 = value;
                            found = 1;
                            *arg5 = obj;
                        }
                        slot = (void *)((char *)slot + 4);
                    }
                }
                node = *(void ***)((char *)node + 4);
            }
        }
        listStorage.items[0] = lbl_8055EA3C;
        listStorage.items[1] = lbl_8055EA40;
        rangeScale = lbl_80562CD8;
        queryStorage.query.position.x = arg0[0];
        queryStorage.query.position.y = arg0[1];
        queryStorage.query.position.z = arg0[2];
        queryStorage.query.direction.x = normal[0];
        queryStorage.query.direction.y = normal[1];
        queryStorage.query.direction.z = normal[2];
        queryStorage.query.dot = &dot;
        queryStorage.query.found = found;
        queryStorage.query.filter = arg_sp8;
        for (meshIndex = 0; meshIndex < 2; meshIndex++) {
            void *mesh = listStorage.items[meshIndex];
            if (mesh) {
                s32 minX = -0x2625A00, maxX = 0x2625A00;
                s32 minZ = -0x2625A00, maxZ = 0x2625A00;
                s32 x, z, index;
                x = (s32)(rangeScale * arg0[0]);
                z = (s32)(rangeScale * arg0[2]);
                index = 0;
                for (;;) {
                    u16 *range = (u16 *)((char *)*(void **)((char *)mesh + 0x10) + index * 8);
                    s32 k, end, midX, midZ;
                    k = range[0];
                    end = range[1];
                    for (; k < end; k++) {
                        u16 tri = *(u16 *)((char *)*(void **)((char *)mesh + 0x0C) + k * 2);
                        void *obj = *(void **)((char *)*(void **)((char *)mesh + 4) + tri * 4);
                        if (*(u8 *)((char *)obj + 0x40))
                            fn_801E2100(*(void **)((char *)obj + 0x3C), &queryStorage.query);
                    }
                    if (range[2] == 0) break;
                    {
                        index = range[2];
                        midX = (minX + maxX) >> 1;
                        midZ = (minZ + maxZ) >> 1;
                        if (z <= midZ) {
                            maxZ = midZ;
                            if (x <= midX) maxX = midX;
                            else { minX = midX; index++; }
                        } else {
                            minZ = midZ;
                            if (x <= midX) { maxX = midX; index += 2; }
                            else { minX = midX; index += 3; }
                        }
                    }
                }
            }
        }
        found = queryStorage.query.found;
    } else {
        fn_802E30C8((const char *)&lbl_8033989C, lbl_8055E3C4);
        for (i = 0; i < arg7; i++) {
            void *obj = arg6[i];
            if (obj && (*(s32 (**)(void *))(*(void ***)obj + 0x11))(obj)) {
                void *slot = obj;
                for (j = 0; j < *(s32 *)((char *)obj + 0x24); j++) {
                    void *item;
                    s32 value;
                    if (j >= 0 && j < *(s32 *)((char *)obj + 0x24))
                        item = *(void **)((char *)slot + 0x14);
                    else
                        item = 0;
                    value = *(s32 *)((char *)item + 0x20);
                    if ((!arg_sp8 || arg_sp8(value)) &&
                        (*(s32 (**)(void *, void *, f32 *, f32 *, s32))(*(void ***)item + 6))
                        (item, arg0, normal, &dot, arg3)) {
                        *arg4 = value;
                        found = 1;
                        *arg5 = obj;
                    }
                    slot = (void *)((char *)slot + 4);
                }
            }
        }
        listStorage.items[0] = lbl_8055EA3C;
        listStorage.items[1] = lbl_8055EA40;
        for (i = 0; i < 2; i++) {
            void *list = listStorage.items[i];
            if (list) {
                void **items = *(void ***)((char *)list + 4);
                for (j = 0; j < *(s32 *)list; j++) {
                    void *item = items[j];
                    if (*(u8 *)((char *)item + 0x40)) {
                        void *hit = *(void **)((char *)item + 0x3C);
                        if ((*(s32 (**)(void *, void *, f32 *, f32 *, s32))(*(void ***)hit + 6))
                            (hit, arg0, normal, &dot, arg3)) {
                            found = 1;
                            *arg4 = *(s32 *)((char *)hit + 0x20);
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
        arg2[0] = arg0[0] + normal[0] * dot;
        arg2[1] = arg0[1] + normal[1] * dot;
        arg2[2] = arg0[2] + normal[2] * dot;
    }
    return found;
}
#pragma scheduling on
#pragma ppc_psq_save reset
typedef struct VTable_801E2084 { void *unk0; void *unk4; void *unk8; void *unkC; void (*call)(void *, void *); } VTable_801E2084;
typedef struct Obj_801E2084 { VTable_801E2084 *vtable; } Obj_801E2084;
