// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern f32 lbl_805640C0;
extern f32 lbl_805640C4;
extern f32 lbl_805640C8;
#define DEFAULT_RANGE lbl_805640C0 /* 10.0f: fallback bone-field magnitude */
#define DEFAULT_ZERO lbl_805640C4  /* 0.0f */
#define DEFAULT_ONE lbl_805640C8   /* 1.0f */
extern void* lbl_8055F5F0;
s32 stricmp(const char*, const char*);
extern int sprintf(char*, const char*, ...);
extern void* memset(void*, int, unsigned long);
extern char* strncpy(char*, const char*, unsigned long);
void* loadCarResource(s32, s32);

typedef struct Node_80279254 {
    u8 pad0[0x20EC];
    s32 boneConnections;        /* 0x20EC allocated bone-connection array */
    u8 pad20F0[0x348];
    void* modelFile;            /* 0x2438 loaded car resource file handle */
    char name[0x20];            /* 0x243C resource name */
    s32 count;                  /* 0x245C reference count */
    struct Node_80279254* next; /* 0x2460 next node in gCarResourceList */
} Node_80279254;
typedef Node_80279254 CarResourceNode;
#define gCarResourceList     lbl_8055F5F0 /* head of loaded car resource list */
#define ResourceFile_release releaseValueFile
#define Mem_freeArray        fn_80128670
#define Mem_freeObject       fn_80128668

extern void* fn_801284F8(s32, const char*);
extern s32 fn_8012C33C(char*);
extern void* getValueFile(char*);
extern void releaseValueFile(void*);
extern void fn_802E30C8(const char*, ...);
extern void Abend_Panic(const char*, ...);
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
extern const char carLayoutAllocLabel[4];
extern const char boundsResourceName[4];
extern const char minBoundKeyFormat[4];
extern const char maxBoundKeyFormat[4];
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
 struct Res_Vtable_80279004 {
     virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
     virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
     virtual void s8(); virtual void s9(); virtual void s10();
     virtual Vec3_80279004 getVec(const char*);
 };
 struct File_Vtable_80279004 {
     virtual Res_Vtable_80279004* getRes(const char*);
     virtual void slot1();
     virtual int hasRes(const char*);
 };
 #pragma cplusplus reset

 s32 fn_80278A1C(void) {
    /* Default predicate stub: unconditionally returns FALSE (0) to callers that test its result. */
    return 0;
}

/* No-op menu action handler: the UI-command dispatch in fn_802399AC calls this
 * for one of its commands, which does nothing in this build. */
void fn_80278A24(void) {
}

#pragma cplusplus on
/* RealName: InitDefaultBoneFields. Fill a car-model element's fields with fallback defaults (+/-10, 0 and 1) when its bone data is missing. */
extern "C" void fn_80278A28(void* elem) {
    f32 one;
    f32 zero = DEFAULT_ZERO;
    f32 negRange;
    f32 range = DEFAULT_RANGE;
    f32 *values = (f32*)elem;

    negRange = -range;
    one = DEFAULT_ONE;
    values[4] = range;
    values[1] = negRange;
    values[2] = negRange;
    values[3] = negRange;
    values[5] = range;
    values[6] = range;
    values[7] = zero;
    values[8] = zero;
    values[9] = zero;
    values[11] = one;
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
        f32 scale = 0.0254f;
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
                entry->f10 = child->getFloatDefault(lbl_8055C6A0, 0.0f);
                if (entry->id1 < 1 || entry->id1 >= 0xA2) {
                    Abend_Panic(base->link_out_of_range, entry->id1);
                }
                if (entry->id2 < 1 || entry->id2 >= 0xA2) {
                    Abend_Panic(base->link_out_of_range, entry->id2);
                }
            }
        }

        const char* const* volatile tbl = lbl_802FA838;
        keys = *(struct Keys*)tbl;
        const char** key_ptr = keys.k;
        Entry20F4* entry20F4 = car->wheels;
        for (i = 0; i < 4; i++, key_ptr++, entry20F4++) {
            sprintf(wheelName, base->wheel, *key_ptr);
            Res_80279004* wres = file->hasRes(wheelName) ? file->getRes(wheelName) : NULL;
            memset(entry20F4, 0, sizeof(Entry20F4));
            if (wres != NULL) {
                entry20F4->id = wres->getInt(lbl_8055C6A8);
                entry20F4->f4 = wres->getFloatDefault(lbl_8055C6B0, 0.0f);
                entry20F4->f8 = wres->getFloatDefault(lbl_8055C6B8, 0.0f);
                entry20F4->fC = wres->getFloatDefault(lbl_8055C6C0, 0.0f);
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
extern "C" void* loadCarResource(s32 name, s32 arg1) {
    #pragma scheduling invalid_target
    char physicsPath[0x80];
    char boneModPath[0x80];
    char boundKey[0x20];
    char* layoutStrings = lbl_80347690;
    char* boundsDst;
    char* resource;
    void* boneModFile;
    void* boneFile;
    Res_Vtable_80279004* boundsRes;
    s32 boundIndex;
    char* resourceName = (char*)name;
    Vec3_80279004 minVec;
    Vec3_80279004 maxVec;

    /* Allocate a car layout resource, attach its physics file and build the bone
     * layout from the bone .mvl/.val files (plus an optional bonemod .bvl), copy
     * the 32 per-bone min/max bounds out of the "bounds" resource, then push the
     * new resource onto the head of gCarResourceList. */
    resource = (char*)fn_801284F8(0x2464, carLayoutAllocLabel);
    sprintf(physicsPath, layoutStrings + 0xF4, resourceName);
    *(void**)(resource + 0x2438) = getValueFile(physicsPath);
    sprintf(physicsPath, layoutStrings + 0x108, resourceName);
    if (fn_8012C33C(physicsPath) == 0) {
        sprintf(physicsPath, layoutStrings + 0x118, resourceName);
    }
    boneFile = getValueFile(physicsPath);
    sprintf(boneModPath, layoutStrings + 0x128, resourceName);
    if (fn_8012C33C(boneModPath) != 0) {
        boneModFile = getValueFile(boneModPath);
    } else {
        boneModFile = NULL;
    }
    fn_80278A64((CarObject*)resource, (File_80279004*)boneFile, (File_80279004*)boneModFile, (s32)resourceName);
    memset(resource + 0x2138, 0, 0x300);
    if (((File_Vtable_80279004*)boneFile)->hasRes(boundsResourceName) != 0) {
        boundsRes = ((File_Vtable_80279004*)boneFile)->getRes(boundsResourceName);
        boundsDst = resource;
        for (boundIndex = 0; boundIndex < 0x20; boundIndex++) {
            sprintf(boundKey, minBoundKeyFormat, boundIndex);
            minVec = boundsRes->getVec(boundKey);
            *(f32*)(boundsDst + 0x2138) = minVec.x;
            *(f32*)(boundsDst + 0x213C) = minVec.y;
            *(f32*)(boundsDst + 0x2140) = minVec.z;
            sprintf(boundKey, maxBoundKeyFormat, boundIndex);
            maxVec = boundsRes->getVec(boundKey);
            *(f32*)(boundsDst + 0x2144) = maxVec.x;
            *(f32*)(boundsDst + 0x2148) = maxVec.y;
            *(f32*)(boundsDst + 0x214C) = maxVec.z;
            boundsDst += 0x18;
        }
    } else {
        fn_802E30C8(layoutStrings + 0x13C, (s32)resourceName);
    }
    releaseValueFile(boneFile);
    if (boneModFile != NULL) releaseValueFile(boneModFile);
    *(s32*)(resource + 0x245C) = 1;
    strncpy(resource + 0x243C, resourceName, 0x20);
    *(u8*)(resource + 0x245B) = 0;
    *(void**)(resource + 0x2134) = *(void**)(resource + 0x2438);
    *(void**)(resource + 0x2460) = gCarResourceList;
    gCarResourceList = resource;
    return resource;
}
#pragma cplusplus reset

/* Find a loaded car resource by name, incrementing its refcount; load/create it if missing. */
void* fn_80279254(s32 name, s32 arg1) {
    CarResourceNode* node = gCarResourceList;

    while (node != NULL) {
        if (stricmp(node->name, (char*)name) == 0) {
            node->count = node->count + 1;
            break;
        }
        node = node->next;
    }
    if (node == NULL) {
        node = loadCarResource(name, arg1);
    }
    return node;
}

void releaseValueFile(void*);
void fn_80128670(s32);
void fn_80128668(void*);
#pragma dont_inline on
/* RealName: GetCarResource. Look up the car layout named carName in
 * gCarResourceList, raising its reference count, and load it through
 * loadCarResource when it is not there yet; the loader's second argument is
 * unused, so this wrapper passes 0. Returns the car resource. */
void* fn_802792E4(char* carName) {
    return fn_80279254((s32)carName, 0);
}
#pragma dont_inline off
/* Release a reference to a loaded car resource node; when its reference count
 * reaches zero, unlink it from gCarResourceList and free its model file and memory. */
void fn_802792EC(void* resource) {
    CarResourceNode* node = resource;
    s32 refCount;

    refCount = node->count - 1;
    node->count = refCount;
    if (refCount == 0) {
        CarResourceNode* curr;
        CarResourceNode** link = (CarResourceNode**)&gCarResourceList;
        while ((curr = *link) != NULL) {
            if (curr == node) {
                *link = curr->next;
                break;
            }
            link = &curr->next;
        }
        ResourceFile_release(((CarResourceNode*)resource)->modelFile);
        Mem_freeArray(((CarResourceNode*)resource)->boneConnections);
        Mem_freeObject(resource);
    }
}
