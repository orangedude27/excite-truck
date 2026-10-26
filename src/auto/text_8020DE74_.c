#include "types.h"

typedef struct UiObj {
    void *vtable;
    void *owner;
    void *child8;
    void *last_child;
    void *children[2];
    void *child18;
    void *child1c;
    void *child20;
    void *child24;
    void *child28;
    void *child2c;
    void *child30;
    void *child34;
    void *child38;
    void *child3c;
    void *child40;
    void *child44;
    void *child48;
    void *child4c;
    void *child50;
    void *child54;
    u8 flags58;
    u8 pad59[3];
    u32 child_count;
    float value60;
    float value64;
    float value68;
    float value6c;
    u8 flag70;
    u8 flag71;
    u8 flag72;
    u8 pad73;
} UiObj;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80563368;
extern float lbl_80563370;
extern float lbl_805633DC;
extern float lbl_805633F4;
extern float lbl_805633F8;
extern float lbl_805633FC;

#pragma scheduling invalid_target
#pragma cplusplus on
extern void *lbl_8033C8C4[];
extern "C" void fn_80128668(void *);
extern "C" void *fn_801284F8(int, const char *);
extern "C" void *fn_802077A4(const char *, int, void *, void *);
extern "C" void *fn_802076A0(const char *, int, void *, int);
extern "C" int fn_801345D8(char *, int, const char *, ...);
extern "C" void *fn_80016544(s32);
extern "C" void *memset(void *, int, unsigned int);
extern const char lbl_8033C7A0[];
extern const char lbl_8055B648;
extern float lbl_8056336C;
#pragma cplusplus reset
void *fn_8020DE74(void *arg0) {
    char name[0x20];
    register const char *labels asm("r31") = lbl_8033C7A0;
    register UiObj *obj asm("r30");
    register void *right asm("r29");
    register s32 is_race asm("r28");
    register void *left asm("r27");
    register void *group asm("r26");
    register u32 one asm("r24") = 1;
    register u32 offset asm("r23");
    register u32 i asm("r22");
    register u8 *slot asm("r21");
    void *child;
    u32 bit;

    obj = (UiObj *)fn_801284F8(0x74, (const char *)&lbl_8055B648);
    if (obj != 0) {
    obj->vtable = lbl_8033C8C4;
    obj->owner = arg0;
    left = (u8 *)arg0 + 0x118;
    right = (u8 *)arg0 + 0x60;
    group = *(void **)((u8 *)arg0 + 0x1ec);
    is_race = *(u32 *)((u8 *)arg0 + 0x10) == 0x50434152;

    if (is_race != 0) {
        obj->child28 = fn_802077A4(lbl_8033C7A0, 5, left, right);
        obj->child30 = fn_802077A4(labels + 0x10, 8, left, right);
    } else {
        obj->child28 = 0;
        obj->child30 = 0;
    }
    obj->child8 = fn_802077A4(labels + 0x1c, 5, left, right);
    obj->child_count = 0;
    memset(obj->children, 0, 8);
    obj->last_child = 0;

    {
    register float initial asm("f31");
    initial = lbl_80563368;
    offset = 0;
    i = 0;
    do {
        fn_801345D8(name, 0x20, labels + 0x2c, i + 1);
        slot = (u8 *)obj + offset;
        child = fn_802077A4(name, 5, left, right);
        *(void **)(slot + 0x10) = child;
        if (child == 0) break;
        *(void **)((u8 *)child + 0x10) = group;
        child = *(void **)(slot + 0x10);
        if (initial != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = one;
            *(float *)((u8 *)child + 4) = initial;
        }
        i++;
        obj->last_child = *(void **)(slot + 0x10);
        offset += 4;
        obj->child_count += 1;
    } while (i < 2);
    }

    if (is_race != 0) obj->child18 = fn_802077A4(labels + 0x38, 5, left, right);
    else obj->child18 = 0;
    child = *(void * volatile *)((u8 *)obj + 8);
    if (child != 0) {
        *(void **)((u8 *)child + 0x10) = group;
        {
            float desired = lbl_8056336C;
            child = *(void * volatile *)((u8 *)obj + 8);
            if (desired != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = 1;
            *(float *)((u8 *)child + 4) = desired;
            }
        }
    }
    child = obj->child28;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->child30;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) obj->child1c = fn_802077A4(labels + 0x4c, 5, left, right);
    else obj->child1c = 0;
    obj->child20 = fn_802077A4(labels + 0x5c, 5, left, right);
    obj->child34 = fn_802077A4(labels + 0x68, 5, left, right);
    if (is_race != 0) {
        obj->child38 = fn_802077A4(labels + 0x78, 5, left, right);
        obj->child3c = fn_802077A4(labels + 0x88, 5, left, right);
    } else {
        obj->child38 = 0;
        obj->child3c = 0;
    }
    child = obj->child34;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->child38;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = obj->child3c;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = fn_802077A4(labels + 0x98, 5, left, right);
    obj->child40 = child;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) {
        obj->child24 = fn_802077A4(labels + 0xa8, 5, left, right);
        obj->child2c = fn_802077A4(labels + 0xb8, 5, left, right);
        obj->child48 = fn_802076A0(labels + 0xcc, 1, group, 2);
        obj->child4c = fn_802076A0(labels + 0xdc, 1, group, 2);
        obj->child50 = fn_802076A0(labels + 0xec, 1, group, 2);
        obj->child44 = fn_802076A0(labels + 0x100, 1, group, 0);
        obj->child54 = fn_802076A0(labels + 0x110, 1, group, 0);
    } else {
        obj->child24 = 0;
        obj->child2c = 0;
        obj->child48 = 0;
        obj->child4c = 0;
        obj->child50 = 0;
        obj->child44 = 0;
        obj->child54 = 0;
    }
    {
        float reset = lbl_80563370;
        obj->value60 = reset;
        obj->flag70 = 0;
        obj->value64 = reset;
        obj->value68 = reset;
        obj->value6c = reset;
    }
    obj->flags58 = 0;
    obj->flag72 = 0;
    child = fn_80016544(*(s32 *)((u8 *)arg0 + 0x25c));
    bit = (*(u32 *)((u8 *)child + 0xa0) >> 2) & 1;
    obj->flag71 = bit;
    }
    return obj;
}
#pragma cplusplus on
extern "C" void *fn_8020E288(void *arg0, s32 arg1) {
    struct Dummy { virtual void release(s32); virtual void v1(); virtual void v2(); };
    void *child;
    u8 *p;
    u32 i;
    if (arg0 != 0) {
        child = *(void **)((u8 *)arg0 + 8);
        *(void **)arg0 = lbl_8033C8C4;
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        p = (u8 *)arg0;
        i = 0;
        do {
            child = *(void **)(p + 0x10);
            if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
            p += 4;
            i++;
        } while (i < 2);
        child = *(void **)((u8 *)arg0 + 0x18);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x28);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x30);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x1C);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x20);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x24);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x2C);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x48);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x4C);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x50);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x44);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x34);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x38);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x3C);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x40);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        child = *(void **)((u8 *)arg0 + 0x54);
        if (child != 0) { if (child != 0) ((Dummy *)child)->release(1); }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" s32 fn_80009C84();
extern "C" void fn_80206750(s32, s32, s32);
void fn_8020F15C(void *arg0) {
    s32 value;
    s32 mode;
    void *p;
    p = *(void **)((u8 *)arg0 + 4);
    value = *(s32 *)((u8 *)p + 0x1EC);
    if (fn_80009C84() == 0) {
        mode = 2;
    } else {
        mode = 0;
    }
    if (*(s32 *)((u8 *)arg0 + 0x48) != 0)
        fn_80206750(*(s32 *)((u8 *)arg0 + 0x48), value, mode);
    if (*(s32 *)((u8 *)arg0 + 0x4C) != 0)
        fn_80206750(*(s32 *)((u8 *)arg0 + 0x4C), value, mode);
    if (*(s32 *)((u8 *)arg0 + 0x50) != 0)
        fn_80206750(*(s32 *)((u8 *)arg0 + 0x50), value, mode);
}

#pragma scheduling on
#pragma scheduling off
#pragma cplusplus reset

void fn_8020F1F8(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x50);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

void fn_8020F21C(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x28);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

#pragma scheduling off
void fn_8020F240(void *arg0) {
    register void *p;
    float value;
    p = *(void **)((char *)arg0 + 8);
    if (p != 0) {
        value = lbl_80563368;
        if (value != *(float *)((char *)p + 8)) {
            *(signed char *)((char *)p + 0x4D) = 1;
            *(float *)((char *)p + 8) = value;
        }
        p = *(void **)((char *)arg0 + 8);
        *(signed char *)((char *)p + 0x49) = 1;
        *(signed char *)((char *)p + 0x4B) = 0;
        *(signed char *)((char *)p + 0x4A) = 0;
    }
}
void fn_8020F284(void *arg0, float farg0) {
    float temp_f0;
    float temp_f1;
    float var_f2;
    void *temp_r4;
    void *temp_r4_2;
    temp_r4 = *(void **)((char *)arg0 + 0x1C);
    if (temp_r4 != 0) {
        var_f2 = lbl_80563368;
        temp_f0 = (farg0 - lbl_805633DC) / lbl_805633F4;
        if (var_f2 < temp_f0) {
        } else {
            var_f2 = temp_f0;
        }
        if (var_f2 > lbl_80563370) {
        } else {
            var_f2 = lbl_80563370;
        }
        temp_f1 = lbl_805633F8 + (var_f2 * lbl_805633FC);
        if (temp_f1 != *(float *)((char *)temp_r4 + 8)) {
            *(signed char *)((char *)temp_r4 + 0x4D) = 1;
            *(float *)((char *)temp_r4 + 8) = temp_f1;
        }
        temp_r4_2 = *(void **)((char *)arg0 + 0x1C);
        *(signed char *)((char *)temp_r4_2 + 0x49) = 1;
        *(char *)((char *)temp_r4_2 + 0x4B) = 0;
        *(char *)((char *)temp_r4_2 + 0x4A) = 0;
    }
}

void fn_8020F30C(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x24);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}

void fn_8020F330(void *arg0) {
    void *temp_r3;

    temp_r3 = *(void **)((char *)arg0 + 0x20);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
#pragma scheduling off
void fn_8020F354(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((char *)arg0 + 0x2C);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
void fn_8020F378(void *arg0) {
    void *temp_r3;

    temp_r3 = *(void **)((char *)arg0 + 0x44);
    if (temp_r3 != 0) {
        *(signed char *)((char *)temp_r3 + 0x49) = 1;
        *(signed char *)((char *)temp_r3 + 0x4B) = 0;
        *(signed char *)((char *)temp_r3 + 0x4A) = 0;
    }
}
void fn_8020F39C(void) {

}

void fn_8020F3A0(void *arg0) {
    *(signed char *)((char *)arg0 + 0x72) = 1;
}
extern float lbl_80563368;
extern float lbl_80563370;
extern float lbl_805633DC;
extern float lbl_805633F4;
extern float lbl_805633F8;
extern float lbl_805633FC;
