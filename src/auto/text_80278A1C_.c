// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern f32 lbl_805640C0;
extern f32 lbl_805640C4;
extern f32 lbl_805640C8;
extern void* lbl_8055F5F0;
s32 stricmp(const char*, const char*);
void* fn_80279004(s32, s32);

typedef struct Node_80279254 {
    u8 pad0[0x243C];
    char name[0x20];
    s32 count;
    struct Node_80279254* next;
} Node_80279254;

s32 fn_80278A1C(void) {
    return 0;
}

void fn_80278A24(void) {
}

void fn_80278A28(void* arg0) {
    f32 v1 = lbl_805640C4;
    f32 v0 = lbl_805640C8;
    f32 v3 = lbl_805640C0;
    f32 v2 = -v3;

    *(f32*)((u8*)arg0 + 0x10) = v3;
    *(f32*)((u8*)arg0 + 0x04) = v2;
    *(f32*)((u8*)arg0 + 0x08) = v2;
    *(f32*)((u8*)arg0 + 0x0C) = v2;
    *(f32*)((u8*)arg0 + 0x14) = v3;
    *(f32*)((u8*)arg0 + 0x18) = v3;
    *(f32*)((u8*)arg0 + 0x1C) = v1;
    *(f32*)((u8*)arg0 + 0x20) = v1;
    *(f32*)((u8*)arg0 + 0x24) = v1;
    *(f32*)((u8*)arg0 + 0x2C) = v0;
}

void* fn_80279254(s32 arg0, s32 arg1) {
    Node_80279254* var_r31 = lbl_8055F5F0;

    while (var_r31 != NULL) {
        if (stricmp(var_r31->name, (char*)arg0) == 0) {
            var_r31->count = var_r31->count + 1;
            break;
        }
        var_r31 = var_r31->next;
    }
    if (var_r31 == NULL) {
        var_r31 = fn_80279004(arg0, arg1);
    }
    return var_r31;
}

void* fn_80279254(s32, s32);
void fn_80131818(void*);
void fn_80128670(s32);
void fn_80128668(void*);
#pragma dont_inline on
void fn_802792E4(s32 arg0) {
    fn_80279254(arg0, 0);
}
#pragma dont_inline off
void fn_802792EC(void* arg0) {
    Node_80279254* node = arg0;
    s32 temp_r0;

    temp_r0 = node->count - 1;
    node->count = temp_r0;
    if (temp_r0 == 0) {
        Node_80279254** var_r5 = (Node_80279254**)&lbl_8055F5F0;
        Node_80279254* temp_r4;
        while ((temp_r4 = *var_r5) != NULL) {
            if (temp_r4 == node) {
                *var_r5 = temp_r4->next;
                break;
            }
            var_r5 = &temp_r4->next;
        }
        fn_80131818(*(void**)((u8*)arg0 + 0x2438));
        fn_80128670(*(s32*)((u8*)arg0 + 0x20EC));
        fn_80128668(arg0);
    }
}

