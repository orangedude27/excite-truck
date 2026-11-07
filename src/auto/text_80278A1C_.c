// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern f32 lbl_805640C0;
extern f32 lbl_805640C4;
extern f32 lbl_805640C8;
extern void* lbl_8055F5F0;
s32 stricmp(const char*, const char*);
extern int sprintf(char*, const char*, ...);
extern void* memset(void*, int, unsigned long);
extern char* strncpy(char*, const char*, unsigned long);
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
extern void fn_802E30C8(const char*, ...);
extern void fn_802E317C(const char*, ...);
extern void* fn_8012850C(s32, const char*);
extern f32 lbl_805640CC;
extern f32 lbl_805640D0;
extern const char* lbl_802FA838[4];
extern const char lbl_8055C678[];
extern const char lbl_8055C680[];
extern const char lbl_8055C688[];
extern const char lbl_8055C68C[];
extern const char lbl_8055C690[];
extern const char lbl_8055C698[];
extern const char lbl_8055C6A0[];
extern const char lbl_8055C6A8[];
extern const char lbl_8055C6B0[];
extern const char lbl_8055C6B8[];
extern const char lbl_8055C6C0[];
extern char lbl_80347690[];
extern const char lbl_8055C6C8[4];
extern const char lbl_8055C6D0[4];
extern const char lbl_8055C6D8[4];
extern const char lbl_8055C6E0[4];
typedef struct Vec3_80279004 { f32 x, y, z; } Vec3_80279004;
#pragma cplusplus on
struct Res_80279004 {
    virtual const char* getName();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual s32 getInt(const char*);
    virtual void slot6();
    virtual f32 getFloat(const char*);
    virtual f32 getFloatDefault(const char*, f32);
    virtual void slot9();
    virtual u8 getByte(const char*, s32);
    virtual Vec3_80279004 getVec(const char*);
};
struct File_80279004 {
    virtual Res_80279004* getRes(const char*);
    virtual Res_80279004* getChild(s32);
    virtual int hasRes(const char*);
};
struct Element_80278A64 {
    s32 id;
    Vec3_80279004 v1;
    Vec3_80279004 v2;
    Vec3_80279004 v3;
    f32 f28;
    f32 f2C;
    u8 b30;
    u8 pad[3];
};
struct Entry20EC {
    s32 id1;
    s32 id2;
    f32 f8;
    f32 fC;
    f32 f10;
};
struct Entry20F4 {
    s32 id;
    f32 f4;
    f32 f8;
    f32 fC;
};
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void* fn_80279004(s32 name, s32 arg1) {
    char path[0x80];
    char path2[0x80];
    char key[0x20];
    char* base = lbl_80347690;
    char* arg0 = (char*)name;
    char* object;
    void* file;
    void* file2;
    void* resource;
    s32 i;
    f32* dst;
    Vec3_80279004 v;
    Vec3_80279004 w;

    object = (char*)fn_801284F8(0x2464, lbl_8055C6C8);
    sprintf(path, base + 0xF4, arg0);
    *(void**)(object + 0x2438) = fn_80131808(path);
    sprintf(path, base + 0x108, arg0);
    if (fn_8012C33C(path) == 0) {
        sprintf(path, base + 0x118, arg0);
    }
    file = fn_80131808(path);
    sprintf(path2, base + 0x128, arg0);
    if (fn_8012C33C(path2) != 0) {
        file2 = fn_80131808(path2);
    } else {
        file2 = NULL;
    }
    fn_80278A64(object, file, file2, (s32)arg0);
    memset(object + 0x2138, 0, 0x300);
    if (((s32 (**)(void*, const char*))(*(void**)file))[4](file, lbl_8055C6D0) != 0) {
        resource = ((void* (**)(void*, const char*))(*(void**)file))[2](file, lbl_8055C6D0);
        dst = (f32*)(object + 0x2138);
        for (i = 0; i < 0x20; i++) {
            sprintf(key, lbl_8055C6D8, i);
            v = ((Vec3_80279004 (**)(void*, char*))(*(void**)resource))[13](resource, key);
            dst[0] = v.x; dst[1] = v.y; dst[2] = v.z;
            sprintf(key, lbl_8055C6E0, i);
            w = ((Vec3_80279004 (**)(void*, char*))(*(void**)resource))[13](resource, key);
            dst[3] = w.x; dst[4] = w.y; dst[5] = w.z;
            dst += 6;
        }
    } else {
        fn_802E30C8(base + 0x13C, (s32)arg0);
    }
    fn_80131818(file);
    if (file2 != NULL) fn_80131818(file2);
    *(s32*)(object + 0x245C) = 1;
    strncpy(object + 0x243C, arg0, 0x20);
    *(u8*)(object + 0x245B) = 0;
    *(void**)(object + 0x2134) = *(void**)(object + 0x2438);
    *(void**)(object + 0x2460) = lbl_8055F5F0;
    lbl_8055F5F0 = object;
    return object;
}
#pragma cplusplus reset

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

