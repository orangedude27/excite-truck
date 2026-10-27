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

#pragma scheduling invalid_target
void fn_801D2C04(void) {
    qsort(lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}
#pragma scheduling on
s32 fn_801D2C20(s32 arg0) {
    s32 sp8;
    sp8 = arg0;
    if (arg0 <= 0) {
        return 0;
    }
    return fn_800241DC(&sp8, lbl_80438958, lbl_8055E930, 0x4C4, fn_801D2BF4);
}

extern u8 lbl_80438898[];
extern f32 lbl_8055E3C8;
extern void fn_801796CC(s32, f32 *, s32);
void fn_801D2C70(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 i;
    u8 *entry;
    f32 *vec;
    f32 x, y, z;
    s32 index;

    vec = (f32 *)arg1;
    i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x28)) {
        entry = (u8 *)arg0 + i * 8;
        if (*(s32 *)(entry + 8) < 0) {
            f32 tmp[8];
            s32 id = arg3;
            tmp[0] = vec[0]; tmp[1] = vec[1]; tmp[2] = vec[2];
            tmp[3] = *(f32 *)((u8 *)arg2 + 0x118);
            tmp[4] = *(f32 *)((u8 *)arg2 + 0x11C);
            tmp[5] = *(f32 *)((u8 *)arg2 + 0x120);
            *(s16 *)(tmp + 6) = *(s16 *)((u8 *)arg2 + 0x6C);
            fn_801796CC(10, tmp, 0x20);
            if (*(u32 *)((u8 *)arg2 + 0x10) == 0x43415220 ||
                *(u32 *)((u8 *)arg2 + 0x10) == 0x50434152 ||
                *(u32 *)((u8 *)arg2 + 0x10) == 0x41434152 ||
                *(u32 *)((u8 *)arg2 + 0x10) == 0x4E434152) {
                index = *(s32 *)((u8 *)arg2 + 0x1EC) * 0x18;
                *(u8 *)(lbl_80438898 + index) = 1;
                *(s32 *)(lbl_80438898 + index + 4) = id;
                *(f32 *)(lbl_80438898 + index + 8) = *(f32 *)(entry + 0xC) + lbl_8055E3C8;
                x = vec[0] - *(f32 *)((u8 *)arg2 + 0x60);
                y = vec[1] - *(f32 *)((u8 *)arg2 + 0x64);
                z = vec[2] - *(f32 *)((u8 *)arg2 + 0x68);
                *(f32 *)(lbl_80438898 + index + 0xC) = x;
                *(f32 *)(lbl_80438898 + index + 0x10) = y;
                *(f32 *)(lbl_80438898 + index + 0x14) = z;
                *(f32 *)(lbl_80438898 + index + 0xC) = x * *(f32 *)((u8 *)arg2 + 0x3C) + y * *(f32 *)((u8 *)arg2 + 0x40) + z * *(f32 *)((u8 *)arg2 + 0x44);
                *(f32 *)(lbl_80438898 + index + 0x10) = x * *(f32 *)((u8 *)arg2 + 0x48) + y * *(f32 *)((u8 *)arg2 + 0x4C) + z * *(f32 *)((u8 *)arg2 + 0x50);
                *(f32 *)(lbl_80438898 + index + 0x14) = x * *(f32 *)((u8 *)arg2 + 0x54) + y * *(f32 *)((u8 *)arg2 + 0x58) + z * *(f32 *)((u8 *)arg2 + 0x5C);
            }
        }
        i++;
    }
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

#pragma cplusplus on
extern "C" u8 fn_801D2550(void *arg0, void *arg1) {
    struct Dummy {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual f32 fn28(f32, void *);
    };
    if (arg1 != NULL) {
        u8 flag = 1;
        f32 value = lbl_80562A90;
        *(u8 *)arg0 = flag;
        *(f32 *)((u8 *)arg0 + 4) = ((Dummy *)arg1)->fn28(value, lbl_80338300);
    } else {
        *(u8 *)arg0 = 0;
    }
    return *(u8 *)arg0;
}
#pragma cplusplus reset
extern void fn_801345D8(char*, int, const char*, ...);
extern const char lbl_8033830C[];
extern const char lbl_8055ABE4[];
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801D25BC(void* arg0, void* arg1) {
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
#pragma cplusplus reset
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801D2A24(void *obj_) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual s32 fn1C(u32);
        virtual void v20();
        virtual void v24();
        virtual void v28();
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual void v38();
        virtual void v3C();
        virtual void v40();
        virtual void v44();
        virtual void v48();
        virtual void v4C();
        virtual void v50();
        virtual void v54();
        virtual void v58();
        virtual void *fn5C(u32);
    };
    s32 *entry = (s32 *)(lbl_80438958 + lbl_8055E930 * 0x4C4);
    Dummy *obj = (Dummy *)obj_;
    entry[0] = obj->fn1C((u32)&lbl_8055ABE0);
    fn_801D25BC(&entry[1], obj->fn5C((u32)&lbl_8055AC18));
    fn_801D26C8(&entry[12], obj->fn5C((u32)&lbl_8055AC20));
    lbl_8055E930 += 1;
}
#pragma scheduling on
#pragma cplusplus reset

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801D2AD4(void *arg0) {
    struct Dummy {
        virtual char *fn8();
        virtual Dummy *child(s32);
    };
    Dummy *list = (Dummy *)fn_80131810();
    s32 i;

    if (list == NULL) {
        return;
    }
    i = 0;
    while (list->child(i) != NULL) {
        Dummy *obj = list->child(i);
        if (strncmp(obj->fn8(), (char *)&lbl_8055AC28, 7) == 0) {
            fn_801D2A24(obj);
        }
        i++;
    }
    fn_80131818(list);
}
#pragma scheduling on
#pragma cplusplus reset

