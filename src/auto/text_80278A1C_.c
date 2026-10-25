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

#pragma cplusplus on
extern "C" void fn_80278A28(void* arg0) {
    f32 d;
    f32 b = lbl_805640C4;
    f32 c;
    f32 a = lbl_805640C0;
    f32 *p = (f32*)arg0;

    c = -a;
    d = lbl_805640C8;
    p[4] = a;
    p[1] = c;
    p[2] = c;
    p[3] = c;
    p[5] = a;
    p[6] = a;
    p[7] = b;
    p[8] = b;
    p[9] = b;
    p[11] = d;
}
#pragma cplusplus reset
extern void* fn_801284F8(s32, const char*);
extern s32 fn_8012C33C(char*);
extern void* fn_80131808(char*);
extern void fn_80131818(void*);
extern void fn_80278A64(void*, void*, void*, s32);
extern void fn_802E30C8(char*, s32);
extern char lbl_80347690[];
extern const char lbl_8055C6C8[];
extern const char lbl_8055C6D0[];
extern const char lbl_8055C6D8[];
extern const char lbl_8055C6E0[];
void* fn_80279004(s32 arg0, s32 arg1) {
    char path[0xC0];
    char path2[0x80];
    char key[0x20];
    f32 values[6];
    void* object;
    void* file;
    void* file2 = NULL;
    void* resource;
    s32 i;
    f32* dst;

    object = fn_801284F8(0x2464, lbl_8055C6C8);
    sprintf(path, lbl_80347690 + 0xF4, arg0);
    *(void**)((u8*)object + 0x2438) = fn_80131808(path);
    sprintf(path, lbl_80347690 + 0x108, arg0);
    if (fn_8012C33C(path) == 0) {
        sprintf(path, lbl_80347690 + 0x118, arg0);
    }
    file = fn_80131808(path);
    sprintf(path2, lbl_80347690 + 0x128, arg0);
    if (fn_8012C33C(path2) != 0) {
        file2 = fn_80131808(path2);
    }
    fn_80278A64(object, file, file2, arg0);
    memset((u8*)object + 0x2138, 0, 0x300);
    if (((s32 (**)(void*, const char*))(*(void**)file))[2](file, lbl_8055C6D0) != 0) {
        resource = ((void* (**)(void*, const char*))(*(void**)file))[1](file, lbl_8055C6D0);
        dst = (f32*)((u8*)object + 0x2138);
        for (i = 0; i < 0x20; i++) {
            sprintf(key, lbl_8055C6D8, i);
            ((void (**)(void*, f32*, char*))(*(void**)resource))[6](resource, values, key);
            dst[0] = values[0]; dst[1] = values[1]; dst[2] = values[2];
            sprintf(key, lbl_8055C6E0, i);
            ((void (**)(void*, f32*, char*))(*(void**)resource))[6](resource, values + 3, key);
            dst[3] = values[3]; dst[4] = values[4]; dst[5] = values[5];
            dst += 6;
        }
    } else {
        fn_802E30C8(lbl_80347690 + 0x13C, arg0);
    }
    fn_80131818(file);
    if (file2 != NULL) fn_80131818(file2);
    *(s32*)((u8*)object + 0x245C) = 1;
    strncpy((char*)object + 0x243C, (char*)arg0, 0x20);
    *((u8*)object + 0x245B) = 0;
    *(void**)((u8*)object + 0x2134) = *(void**)((u8*)object + 0x2438);
    *(void**)((u8*)object + 0x2460) = lbl_8055F5F0;
    lbl_8055F5F0 = object;
    return object;
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
    Node_80279254* node3 = arg0;
    s32 temp_r0;

    temp_r0 = node3->count - 1;
    node3->count = temp_r0;
    if (temp_r0 == 0) {
        Node_80279254* temp_r5;
        Node_80279254** var_r4 = (Node_80279254**)&lbl_8055F5F0;
        while ((temp_r5 = *var_r4) != NULL) {
            if (temp_r5 == node3) {
                *var_r4 = temp_r5->next;
                break;
            }
            var_r4 = &temp_r5->next;
        }
        fn_80131818(*(void**)((u8*)arg0 + 0x2438));
        fn_80128670(*(s32*)((u8*)arg0 + 0x20EC));
        fn_80128668(arg0);
    }
}

