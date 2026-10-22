// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80438958[];
extern s32 lbl_8055E930;
extern s32 fn_801D2BF4(s32 *, s32 *);
extern void fn_802C6CF8(s32);
extern s32 fn_800241DC(s32 *, u8 *, s32, s32, s32 (*)(s32 *, s32 *));
extern void qsort(void *, s32, s32, void *);
extern void *fn_80131810(void);
extern void fn_80131818(void *);
extern void fn_801D25BC(void *, void *);
extern void fn_801D26C8(void *, void *);
extern void fn_801D2A24(void *);
extern s32 strncmp(char *, char *, s32);
extern s32 lbl_8055AC28;
extern u8 lbl_80338300[];
extern u32 lbl_8055ABE0;
extern u32 lbl_8055AC18;
extern u32 lbl_8055AC20;
extern f32 lbl_80562A90;

typedef struct UnkObj UnkObj;
typedef struct {
    char pad0[8];
    char *(*fn8)(void *);
    void *(*child)(void *, s32);
    char pad2[0x0C];
    s32 (*fn1C)(void *, u32);
    char pad3[8];
    f32 (*fn28)(void *, void *, f32);
    char pad4[0x30];
    void *(*fn5C)(void *, u32);
} Vt801D;
struct UnkObj { const Vt801D *vt; };

#pragma dont_inline on
void fn_801D2B94(void) {
    u8 *var_r31;
    s32 var_r30;
    s32 temp;
    var_r31 = lbl_80438958;
    var_r30 = 0;
    while (var_r30 < lbl_8055E930) {
        temp = *(s32 *)(var_r31 + 0x6C);
        if (temp != -1) {
            fn_802C6CF8(temp);
        }
        var_r31 += 0x4C4;
        var_r30 += 1;
    }
}
#pragma dont_inline off

s32 fn_801D2BF4(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

#pragma dont_inline on
void fn_801D2C04(void) {
    s32 cmp = (s32)fn_801D2BF4;
    s32 count = lbl_8055E930;
    qsort(lbl_80438958, count, 0x4C4, (void *)cmp);
}

#pragma scheduling invalid_target
s32 fn_801D2C20(s32 arg0) {
    s32 sp8;
    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    return fn_800241DC(&sp8, lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}
#pragma scheduling on

void fn_801D2210(void) {
    fn_801D2B94();
}

extern f32 PSVECMag(void*);
extern void fn_801A4868(void*, int);
extern void fn_801D2C70(void*, s32, void*, s32);
extern void fn_801D2E38(void*, void*, s32, void*, f32);
extern void fn_802E317C(const char*, ...);
extern const char lbl_803382DC[];
void fn_801D2414(void *arg0, s32 arg1, void *arg2) {
    u32 type = *(u32*)((char*)arg2 + 0x10);
    int match = 0;
    void *entry;
    f32 magnitude;
    if (type == 0x43415220 || type == 0x50434152 ||
        type == 0x41434152 || type == 0x4E434152) {
        match = 1;
    }
    if (match != 0) {
        entry = (void*)fn_801D2C20(*(s32*)((char*)arg0 + 0x34));
        if (entry != 0) {
            magnitude = PSVECMag((char*)arg2 + 0x118);
            if (*((u8*)entry + 4) != 0 && magnitude > *(f32*)((char*)entry + 8)) {
                fn_801D2C70((char*)entry + 4, arg1, arg2, *(s32*)((char*)arg0 + 0x34));
            }
            if (*((u8*)entry + 0x30) != 0 && magnitude > *(f32*)((char*)entry + 0x34)) {
                fn_801D2E38((char*)entry + 0x30, arg0, arg1, (char*)arg2 + 0x118, *(f32*)((char*)arg2 + 0xD4));
                fn_801A4868(arg0, 0);
            }
        } else if (*(s32*)((char*)arg0 + 0x34) > 0) {
            fn_802E317C(lbl_803382DC);
        }
    }
}

u8 fn_801D2550(void *arg0, UnkObj *arg1) {
    if (arg1 != NULL) {
        *(u8 *)arg0 = 1;
        *(f32 *)((u8 *)arg0 + 4) = arg1->vt->fn28(arg1, lbl_80338300, lbl_80562A90);
    } else {
        *(u8 *)arg0 = 0;
    }
    return *(u8 *)arg0;
}

extern void fn_801345D8(char*, int, const char*, ...);
extern const char lbl_8033830C[];
extern const char lbl_8055ABE4[];
#pragma dont_inline on
void fn_801D25BC(void* arg0, void* arg1) {
    char name[0x20];
    s32 i;
    UnkObj *item;
    Vt801D *vt;
    s32 index;
    if (((u8 (*)(void))fn_801D2550)() != 0) {
        *(s32*)((char*)arg0 + 8) = -1;
        *(s32*)((char*)arg0 + 0x28) = 1;
        i = 0;
        do {
            fn_801345D8(name, 0x20, lbl_8033830C);
            item = (UnkObj*)((UnkObj*)arg1)->vt->fn5C(arg1, (u32)name);
            if (item == 0) break;
            vt = (Vt801D*)item->vt;
            index = vt->fn1C(item, lbl_8055ABE0);
            *(s32*)((char*)arg0 + *(s32*)((char*)arg0 + 0x28) * 8 + 8) = index;
            vt->fn28(item, (void*)lbl_8055ABE4, lbl_80562A90);
            *(f32*)((char*)arg0 + *(s32*)((char*)arg0 + 0x28) * 8 + 0xC) = lbl_80562A90;
            *(s32*)((char*)arg0 + 0x28) += 1;
            i++;
        } while (*(s32*)((char*)arg0 + 0x28) < 4);
    }
}
#pragma dont_inline off
void fn_801D2A24(void *obj_) {
    s32 *entry = (s32 *)(lbl_80438958 + lbl_8055E930 * 0x4C4);
    UnkObj *obj = (UnkObj *)obj_;

    entry[0] = obj->vt->fn1C(obj, (u32)&lbl_8055ABE0);
    fn_801D25BC(&entry[1], obj->vt->fn5C(obj, (u32)&lbl_8055AC18));
    fn_801D26C8(&entry[12], obj->vt->fn5C(obj, (u32)&lbl_8055AC20));
    lbl_8055E930 += 1;
}
#pragma dont_inline off

void fn_801D2AD4(void *arg0) {
    UnkObj *list = (UnkObj *)fn_80131810();
    s32 i;

    if (list == NULL) {
        return;
    }
    i = 0;
    while (list->vt->child(list, i) != NULL) {
        UnkObj *obj = (UnkObj *)list->vt->child(list, i);
        if (strncmp(obj->vt->fn8(obj), (char *)&lbl_8055AC28, 7) == 0) {
            fn_801D2A24(obj);
        }
        i++;
    }
    fn_80131818(list);
}
#pragma dont_inline off

