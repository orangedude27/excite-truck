#include "types.h"
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
extern "C" void *fn_8020DE74(void *arg0) {
    char name[0x20];
    void *obj;
    void *group;
    void *left;
    void *right;
    void *child;
    u8 *base;
    const char *labels;
    float initial;
    u32 is_race;
    u32 i;
    u32 bit;
    u32 offset;
    u8 *slot;

    labels = lbl_8033C7A0;
    base = (u8 *)arg0;
    obj = fn_801284F8(0x74, (const char *)&lbl_8055B648);
    if (obj == 0) return obj;

    *(void **)obj = lbl_8033C8C4;
    *(void **)((u8 *)obj + 4) = base;
    group = *(void **)(base + 0x1ec);
    is_race = *(u32 *)(base + 0x10) == 0x50434152;
    left = base + 0x118;
    right = base + 0x60;

    if (is_race != 0) {
        *(void **)((u8 *)obj + 0x28) = fn_802077A4(labels, 5, left, right);
        *(void **)((u8 *)obj + 0x30) = fn_802077A4(labels + 0x10, 8, left, right);
    } else {
        *(void **)((u8 *)obj + 0x28) = 0;
        *(void **)((u8 *)obj + 0x30) = 0;
    }
    *(void **)((u8 *)obj + 8) = fn_802077A4(labels + 0x1c, 5, left, right);
    *(u32 *)((u8 *)obj + 0x5c) = 0;
    memset((u8 *)obj + 0x10, 0, 8);
    *(void **)((u8 *)obj + 0x0c) = 0;

    initial = lbl_80563368;
    i = 0;
    offset = 0;
    do {
        fn_801345D8(name, 0x20, labels + 0x2c, i + 1);
        slot = (u8 *)obj + offset;
        child = fn_802077A4(name, 5, left, right);
        *(void **)(slot + 0x10) = child;
        if (child == 0) break;
        *(void **)((u8 *)child + 0x10) = group;
        child = *(void **)(slot + 0x10);
        if (initial != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = 1;
            *(float *)((u8 *)child + 4) = initial;
        }
        i++;
        *(void **)((u8 *)obj + 0x0c) = *(void **)(slot + 0x10);
        offset += 4;
        *(u32 *)((u8 *)obj + 0x5c) += 1;
    } while (i < 2);

    if (is_race != 0) *(void **)((u8 *)obj + 0x18) = fn_802077A4(labels + 0x38, 5, left, right);
    else *(void **)((u8 *)obj + 0x18) = 0;
    child = *(void **)((u8 *)obj + 8);
    if (child != 0) {
        float desired = lbl_8056336C;
        *(void **)((u8 *)child + 0x10) = group;
        if (desired != *(float *)((u8 *)child + 4)) {
            *(u8 *)((u8 *)child + 0x4e) = 1;
            *(float *)((u8 *)child + 4) = desired;
        }
    }
    child = *(void **)((u8 *)obj + 0x28);
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = *(void **)((u8 *)obj + 0x30);
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) *(void **)((u8 *)obj + 0x1c) = fn_802077A4(labels + 0x4c, 5, left, right);
    else *(void **)((u8 *)obj + 0x1c) = 0;
    *(void **)((u8 *)obj + 0x20) = fn_802077A4(labels + 0x5c, 5, left, right);
    *(void **)((u8 *)obj + 0x34) = fn_802077A4(labels + 0x68, 5, left, right);
    if (is_race != 0) {
        *(void **)((u8 *)obj + 0x38) = fn_802077A4(labels + 0x78, 5, left, right);
        *(void **)((u8 *)obj + 0x3c) = fn_802077A4(labels + 0x88, 5, left, right);
    } else {
        *(void **)((u8 *)obj + 0x38) = 0;
        *(void **)((u8 *)obj + 0x3c) = 0;
    }
    child = *(void **)((u8 *)obj + 0x34);
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = *(void **)((u8 *)obj + 0x38);
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = *(void **)((u8 *)obj + 0x3c);
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;
    child = fn_802077A4(labels + 0x98, 5, left, right);
    *(void **)((u8 *)obj + 0x40) = child;
    if (child != 0) *(void **)((u8 *)child + 0x10) = group;

    if (is_race != 0) {
        *(void **)((u8 *)obj + 0x24) = fn_802077A4(labels + 0xa8, 5, left, right);
        *(void **)((u8 *)obj + 0x2c) = fn_802077A4(labels + 0xb8, 5, left, right);
        *(void **)((u8 *)obj + 0x48) = fn_802076A0(labels + 0xcc, 1, group, 2);
        *(void **)((u8 *)obj + 0x4c) = fn_802076A0(labels + 0xdc, 1, group, 2);
        *(void **)((u8 *)obj + 0x50) = fn_802076A0(labels + 0xec, 1, group, 2);
        *(void **)((u8 *)obj + 0x44) = fn_802076A0(labels + 0x100, 1, group, 0);
        *(void **)((u8 *)obj + 0x54) = fn_802076A0(labels + 0x110, 1, group, 0);
    } else {
        *(void **)((u8 *)obj + 0x24) = 0;
        *(void **)((u8 *)obj + 0x2c) = 0;
        *(void **)((u8 *)obj + 0x48) = 0;
        *(void **)((u8 *)obj + 0x4c) = 0;
        *(void **)((u8 *)obj + 0x50) = 0;
        *(void **)((u8 *)obj + 0x44) = 0;
        *(void **)((u8 *)obj + 0x54) = 0;
    }
    {
        float reset = lbl_80563370;
        *(float *)((u8 *)obj + 0x60) = reset;
        *(u8 *)((u8 *)obj + 0x70) = 0;
        *(float *)((u8 *)obj + 0x64) = reset;
        *(float *)((u8 *)obj + 0x68) = reset;
        *(float *)((u8 *)obj + 0x6c) = reset;
    }
    *(u8 *)((u8 *)obj + 0x58) = 0;
    *(u8 *)((u8 *)obj + 0x72) = 0;
    child = fn_80016544(*(s32 *)(base + 0x25c));
    bit = (*(u32 *)((u8 *)child + 0xa0) >> 2) & 1;
    *(u8 *)((u8 *)obj + 0x71) = bit;
    return obj;
}

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
