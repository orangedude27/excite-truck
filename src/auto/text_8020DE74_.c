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
extern void fn_80128668(void *);
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
