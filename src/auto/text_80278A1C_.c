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
    s32 count; /* refCount */
    struct Node_80279254* next;
} Node_80279254;
typedef Node_80279254 CarResourceNode;
#define gCarResourceList lbl_8055F5F0 /* head of loaded car resource list */

extern void* fn_801284F8(s32, const char*);
extern s32 fn_8012C33C(char*);
extern void* fn_80131808(char*);
extern void fn_80131818(void*);
extern void fn_802E30C8(const char*, ...);
extern void fn_802E317C(const char*, ...);
extern void* fn_8012850C(s32, const char*);
extern f32 lbl_805640CC;
extern f32 lbl_805640D0;
extern const char* lbl_802FA838[4];
__declspec(section ".sdata") extern const char lbl_8055C678[];
__declspec(section ".sdata") extern const char lbl_8055C680[];
__declspec(section ".sdata") extern const char lbl_8055C688[];
__declspec(section ".sdata") extern const char lbl_8055C68C[];
__declspec(section ".sdata") extern const char lbl_8055C690[];
__declspec(section ".sdata") extern const char lbl_8055C698[];
__declspec(section ".sdata") extern const char lbl_8055C6A0[];
__declspec(section ".sdata") extern const char lbl_8055C6A8[];
__declspec(section ".sdata") extern const char lbl_8055C6B0[];
__declspec(section ".sdata") extern const char lbl_8055C6B8[];
__declspec(section ".sdata") extern const char lbl_8055C6C0[];
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
struct LayoutStrings {
    char travel_min[0xC];
    char travel_max[0xC];
    char link_center[0xC];
    char is_welded[0xC];
    char weakness[0xC];
    char dmg_dist[0xC];
    char warn_bad_bone[0x3C];
    char bone_conn[0x14];
    char link_out_of_range[0x24];
    char wheel[0xC];
    char warn_no_bone[0x2C];
};
struct CarObject {
    s32 count;
    s32 unk4;
    u8 pad8[0x30];
    Element_80278A64 elems[0xA1];
    void* items20EC;
    s32 count20F0;
    Entry20F4 wheels[4];
};
#pragma cplusplus reset

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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80278A64(CarObject* car, File_80279004* file, File_80279004* file2, s32 name) {
    LayoutStrings* base = (LayoutStrings*)lbl_80347690;
    Res_80279004* res2;
    Res_80279004* res;
    Element_80278A64* elem;
    s32 i;
    char boneName[0x20];
    char wheelName[0x20];
    struct Keys { const char* k[4]; } keys;
    Vec3_80279004 v1;
    Vec3_80279004 v2;
    Vec3_80279004 v3;
    if (file != NULL) {
        car->count = 0;
        f32 scale = lbl_805640CC;
        elem = car->elems;
        car->unk4 = 0;
        i = 1;
        elem->id = 1;

        for (; i < 0xA2; i++, elem++) {
            sprintf(boneName, lbl_8055C678, i);
            if (!file->hasRes(boneName)) {
                break;
            }
            res = file->getRes(boneName);
            car->count = i + 1;
            res2 = res;
            if (file2 != NULL) {
                if (file2->hasRes(boneName)) {
                    res2 = file2->getRes(boneName);
                }
            }
            if (res != NULL) {
                v1 = res2->getVec(base->travel_min);
                elem->v1.x = v1.x;
                elem->v1.y = v1.y;
                elem->v1.z = v1.z;
                elem->v1.x *= scale;
                elem->v1.y *= scale;
                elem->v1.z *= scale;

                v2 = res2->getVec(base->travel_max);
                elem->v2.x = v2.x;
                elem->v2.y = v2.y;
                elem->v2.z = v2.z;
                elem->v2.x *= scale;
                elem->v2.y *= scale;
                elem->v2.z *= scale;

                v3 = res2->getVec(base->link_center);
                elem->v3.x = v3.x;
                elem->v3.y = v3.y;
                elem->v3.z = v3.z;
                elem->v3.x *= scale;
                elem->v3.y *= scale;
                elem->v3.z *= scale;

                elem->b30 = res->getByte(base->is_welded, 0);
                elem->f2C = res->getFloat(base->weakness);
                f32 def = lbl_805640D0;
                elem->f28 = res->getFloatDefault(base->dmg_dist, def);
            } else {
                fn_802E30C8(base->warn_bad_bone, name, i);
                fn_80278A28(elem);
            }
        }

        car->count20F0 = 0;
        i = 0;
        while ((res = file->getChild(i++)) != NULL) {
            if (stricmp(res->getName(), lbl_8055C680) == 0) {
                car->count20F0 += 1;
            }
        }

        car->items20EC = fn_8012850C(car->count20F0 * 0x14, base->bone_conn);
        car->count20F0 = 0;

        i = 0;
        Entry20EC* entry;
        Res_80279004* child;
        while ((child = file->getChild(i++)) != NULL) {
            if (stricmp(child->getName(), lbl_8055C680) == 0) {
                s32 idx = car->count20F0;
                car->count20F0 = idx + 1;
                entry = (Entry20EC*)((u8*)car->items20EC + idx * 0x14);
                entry->id1 = child->getInt(lbl_8055C688);
                entry->id2 = child->getInt(lbl_8055C68C);
                entry->f8 = child->getFloat(lbl_8055C690);
                entry->fC = child->getFloat(lbl_8055C698);
                entry->f10 = child->getFloatDefault(lbl_8055C6A0, lbl_805640C4);
                if (entry->id1 < 1 || entry->id1 >= 0xA2) {
                    fn_802E317C(base->link_out_of_range, entry->id1);
                }
                if (entry->id2 < 1 || entry->id2 >= 0xA2) {
                    fn_802E317C(base->link_out_of_range, entry->id2);
                }
            }
        }

        const char* const* tbl = lbl_802FA838;
        keys = *(struct Keys*)tbl;
        const char** key_ptr = keys.k;
        Entry20F4* entry20F4 = car->wheels;
        for (i = 0; i < 4; i++, key_ptr++, entry20F4++) {
            sprintf(wheelName, base->wheel, *key_ptr);
            Res_80279004* wres = file->hasRes(wheelName) ? file->getRes(wheelName) : NULL;
            memset(entry20F4, 0, sizeof(Entry20F4));
            if (wres != NULL) {
                entry20F4->id = wres->getInt(lbl_8055C6A8);
                entry20F4->f4 = wres->getFloatDefault(lbl_8055C6B0, lbl_805640C4);
                entry20F4->f8 = wres->getFloatDefault(lbl_8055C6B8, lbl_805640C4);
                entry20F4->fC = wres->getFloatDefault(lbl_8055C6C0, lbl_805640C4);
            }
        }
        return;
    }
    fn_802E30C8(base->warn_no_bone, name);
    memset((u8*)car + 4, 0, 0x20E8);
    car->count20F0 = 0;
    memset(car->wheels, 0, 0x40);
}
#pragma cplusplus reset
#pragma pop

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
    fn_80278A64((CarObject*)object, (File_80279004*)file, (File_80279004*)file2, (s32)arg0);
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

