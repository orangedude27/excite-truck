void fn_802BD814(void);
#include "revolution/MTX/mtxtypes.h"
extern int lbl_8034AC48, lbl_8055FAA8, lbl_8055FAAC;
extern void fn_802C126C(void);
extern void fn_802B8AE0(void *, void *);
extern int fn_802B05E4(void);
extern int fn_802BD210();
extern void fn_802C2914(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FAB8;
extern int lbl_804C00D4;
extern void *lbl_8055FABC;
int fn_8012C33C(void);
extern float lbl_80564D14;
extern float lbl_80564D18;
int fn_802CAC28(int, int);
void fn_802BD018(void *);
int fn_802BD070(void *);
void fn_80128668(void *);
extern int fn_802C9C24(int);
extern void Abend_Panic(const char *, ...);
extern int fn_802B110C(void *, int);
/* The tree list loaded from "treelist.trl" (its "TLST" block, held in
   lbl_8055FAB8): entryCount entries of TREE_ENTRY_SIZE bytes at `entries`,
   every entry beginning with the tree's name (fn_802BD194 looks one up).
   Each entry carries three lists: the frame list at +0x20 and two near
   lists at +0x28 and +0x30 (see fn_802BD210). */
#define TREE_ENTRY_SIZE 0x38
struct TreeList {
    unsigned int entryCount;
    char *entries;
};
__declspec(section ".data") extern int lbl_8034AB38;
/* Returns a handle for the given resource path if valid and initialized, or -2 on failure. */
int fn_802BC334(int path) {
    int valid = 0;
    if (path != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(path, 0);
    return -2;
}

#pragma dont_inline on
  int stricmp(const char *, const char *);
  __declspec(section ".sdata") extern const char lbl_8055CF38[];
#define kDynoName lbl_8055CF38 /* .sdata: "dyno", the material-item name tested below */
#pragma push
#pragma cplusplus on
extern "C" int fn_802BC39C(void *item) {
    /* RealName: UMatItem_IsDyno (returns nonzero if the item's name is "dyno"). */
    class UMatNamedItem {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&kDynoName, ((UMatNamedItem *)item)->getName()) == 0;
}
#pragma cplusplus reset
#pragma pop

void *fn_802BE844(short, short, short);
int fn_802BC39C();
/* Receiver-preserving tail call to fn_802BC39C (UMatItem_IsDyno): forwards the
   material item in r3 and its boolean result in r3, acting as the "is a dyno item"
   filter predicate in the material-item list. */
void fn_802BC3DC(void) {
    fn_802BC39C();
}

#pragma scheduling invalid_target
void fn_802BC3E0(short x, short y, short cellSize, char *node) {
    /* Insert `node` at the head of the linked list stored in the grid cell
     * for (x, y, cellSize): node's next pointer (at +0) becomes the old head,
     * and the cell's head (at +4) is set to `node`. */
    char *cell = fn_802BE844(x, y, cellSize);
    *(char **)node = *(char **)(cell + 4);
    *(char **)(cell + 4) = node;
}
#pragma scheduling on
/* Grid cell size from a coordinate: the power of two equal to the lowest set bit
 * of (coord + 512) within 9 bits, or 512 when no such bit is set. */
short fn_802BC424(int coord) {
    int mask = 0x1FF;
    short biased = coord + 0x200;
    while ((biased & mask) != 0)
        mask >>= 1;
    return mask + 1;
}

/* Initialize and link each 16-byte entry in a table. */
void fn_802BC44C(void *table) {
    char *entry;
    int offset;
    int index;

    offset = 0;
    index = 0;
    goto check;
loop:
    entry = *(char **)table + offset;
    fn_802BC3E0(*(short *)(entry + 4), *(short *)(entry + 6), fn_802BC424(*(short *)(entry + 4)), entry);
    offset += 0x10;
    index++;
check:
    if (index < *(int *)((char *)table + 4)) goto loop;
}

/* Fetch the model pointer held at +0xC of the resource referenced by node+4;
   callers pass it to fn_802B1DA0 to count that model's entries. */
void *fn_802BC4D4(void *node) {
    return *(void **)(*(char **)((char *)node + 4) + 0xC);
}

#pragma scheduling on
int fn_802BC4E0(void *__restrict node) {
    /* Resolve a texture handle for node+4; warn if missing, then invoke callback fn_802BC334 with it. */
    int texture = fn_802C9C24(*(int *)((char *)node + 4));
    if (fn_8012C33C() == 0)
        Abend_Panic((const char *)&lbl_8034AB38, texture);
    return fn_802B110C(&fn_802BC334, texture);
}
double fn_8002F234(float, float);
#pragma push
#pragma processor 750
// Scaled XZ-plane length of a Vec at `vec`: returns scale * sqrt(x*x + z*z),
// using the IEEE sqrt helper (the second argument it is passed is ignored).
float fn_802BC540(void *vec, float scale) {
    float x = *(float *)vec;
    float z = *(float *)((char *)vec + 8);
    float xSquared = x * x;
    float zSquared = z * z;
    float lengthSquared = xSquared + zSquared;
    return scale * (float)fn_8002F234(lengthSquared, z);
}
#pragma pop
void PSVECCrossProduct(Vec *, Vec *, Vec *);
void PSVECNormalize(const Vec *, Vec *);
void fn_801EA18C(void *, s32, s32);
#pragma push
#pragma scheduling invalid_target
void fn_802BC588(float *arg0, float *arg1, float *arg2, float *arg3, float *arg4) {
float sp14[3];
float sp8[3];
float one, f1, f2, f3, zero, f5;

zero = 0.0f;
f5 = arg3[0];
f3 = arg3[1];
f2 = arg3[2];
f1 = arg3[3];
one = lbl_80564D18;

arg0[9] = f5;
arg0[10] = zero;
arg0[11] = f3;
arg0[6] = f2;
arg0[7] = zero;
arg0[8] = f1;
arg0[3] = zero;
arg0[4] = one;
arg0[5] = zero;
PSVECCrossProduct((Vec *)(arg0 + 3), (Vec *)(arg0 + 6), (Vec *)arg0);

sp14[0] = 0.0f;
sp14[1] = lbl_80564D18;
sp14[2] = 0.0f;
fn_801EA18C(arg0 + 9, (s32)sp14, 0);
arg2[0] = sp14[0];
arg2[1] = sp14[1];
arg2[2] = sp14[2];
arg0[10] -= fn_802BC540((void *)sp14, arg4[21]);

if ((u32)sp8 == (u32)((char *)arg4 + 0x34)) {
float x0 = arg0[0], x1 = arg0[1], x2 = arg0[2];
float x3 = arg0[3], x4 = arg0[4], x5 = arg0[5];
float x6 = arg0[6], x7 = arg0[7], x8 = arg0[8];
float a = arg4[13], b = arg4[14], c = arg4[15];
sp8[0] = a * x0 + b * x3 + c * x6;
sp8[1] = a * x1 + b * x4 + c * x7;
sp8[2] = a * x2 + b * x5 + c * x8;
} else {
{
float tb = arg0[3] * arg4[14];
float ta = arg0[0] * arg4[13];
float tc = arg0[6] * arg4[15];
sp8[0] = tc + (ta + tb);
}
{
float tb = arg0[4] * arg4[14];
float ta = arg0[1] * arg4[13];
float tc = arg0[7] * arg4[15];
sp8[1] = tc + (ta + tb);
}
{
float tb = arg0[5] * arg4[14];
float ta = arg0[2] * arg4[13];
float tc = arg0[8] * arg4[15];
sp8[2] = tc + (ta + tb);
}
}
{
float scale = arg3[4];
sp8[0] *= scale;
sp8[1] *= scale;
sp8[2] *= scale;
arg1[9] = arg0[9] + sp8[0];
arg1[10] = arg0[10] + sp8[1];
arg1[11] = arg0[11] + sp8[2];
}

if ((u32)(arg1 + 6) == (u32)((char *)arg4 + 0x40)) {
float x0 = arg0[0], x1 = arg0[1], x2 = arg0[2];
float x3 = arg0[3], x4 = arg0[4], x5 = arg0[5];
float x6 = arg0[6], x7 = arg0[7], x8 = arg0[8];
float a = arg4[16], b = arg4[17], c = arg4[18];
arg1[6] = a * x0 + b * x3 + c * x6;
arg1[7] = a * x1 + b * x4 + c * x7;
arg1[8] = a * x2 + b * x5 + c * x8;
} else {
{
float t1 = arg0[3] * arg4[17];
float t0 = arg0[0] * arg4[16];
float t2 = arg0[6] * arg4[18];
arg1[6] = t2 + (t0 + t1);
}
{
float t1 = arg0[4] * arg4[17];
float t0 = arg0[1] * arg4[16];
float t2 = arg0[7] * arg4[18];
arg1[7] = t2 + (t0 + t1);
}
{
float t1 = arg0[5] * arg4[17];
float t0 = arg0[2] * arg4[16];
float t2 = arg0[8] * arg4[18];
arg1[8] = t2 + (t0 + t1);
}
}
{
float z = 0.0f;
float o = lbl_80564D18;
arg1[1] = z;
arg1[0] = o;
arg1[2] = z;
}
do { PSVECCrossProduct((Vec *)(arg1 + 6), (Vec *)arg1, (Vec *)(arg1 + 3)); } while (0);
PSVECCrossProduct((Vec *)(arg1 + 3), (Vec *)(arg1 + 6), (Vec *)arg1);
PSVECNormalize((Vec *)(arg1 + 3), (Vec *)(arg1 + 3));
PSVECNormalize((Vec *)arg1, (Vec *)arg1);

{
float scale = arg3[4];
arg0[0] *= scale;
arg0[1] *= scale;
arg0[2] *= scale;
arg0[3] *= scale;
arg0[4] *= scale;
arg0[5] *= scale;
arg0[6] *= scale;
arg0[7] *= scale;
arg0[8] *= scale;
}
}
#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void *fn_802BC9B0(const void *arg0, int arg1, float scale) {
    class Dummy {
    public:
        virtual void m0() = 0;
        virtual void m1() = 0;
        virtual void m2() = 0;
        virtual void m3() = 0;
        virtual void m4() = 0;
        virtual void m5() = 0;
        virtual void m6() = 0;
        virtual void m7() = 0;
        virtual void m8() = 0;
        virtual void m9() = 0;
        virtual void m10() = 0;
        virtual void m11() = 0;
        virtual void m12() = 0;
        virtual void m13() = 0;
        virtual void m14(int) = 0;
    };
    extern void *fn_801284F8(int, int);
    extern float lbl_80564D20;
    extern int lbl_8034AB54[], lbl_80333918[];
    float value = 50000.0f;
    float aInput, bInput;
    bInput = *(const float *)((const char *)arg0 + 0x1C);
    aInput = *(const float *)((const char *)arg0 + 0x18);
    float b = bInput * scale;
    float a = aInput * scale;
    char *obj = (char *)fn_801284F8(0x2C, (int)&lbl_8034AB54);
    if (obj != 0) {
        *(int *)(obj + 0xC) = 0;
        *(int *)(obj + 4) = 0;
        *(int *)(obj + 8) = 0;
        *(int *)(obj + 0x18) = 0x54554245;
        *(float *)(obj + 0x10) = value;
        *(float *)(obj + 0x14) = lbl_80564D20;
        *(int *)(obj + 0x20) = 100;
        *(int *)(obj + 0x1C) = 0;
        *(float *)(obj + 0x24) = b;
        *(float *)(obj + 0x28) = a;
        *(void **)obj = &lbl_80333918;
    }
    ((Dummy *)obj)->m14(arg1);
    return obj;
}
#pragma cplusplus reset

struct CurveData {
    int w0, w1, w2, w3, w4, w5;
    float f6;
    float f7;
};
struct Arg2 {
    char pad[0x28];
    int val28;
    int type2c;
    u8 flag30;
    char pad31[3];
    struct CurveData curve;
};
extern void fn_802BC588();
extern int fn_802C1500(void *, int);
extern void *fn_801FA8E0(void *, void *, int);
extern int lbl_8055FAB0;
extern float lbl_80564D14, lbl_80564D24, lbl_80564D28;
#pragma opt_common_subs off
void fn_802BCA8C(void *arg0, void *arg1, struct Arg2 *arg2) {
    struct CurveData curveData;
    char sp28[0x38];
    int value;
    void *result;
    float scale;
    int flag;
    fn_802BC588((char *)arg0 + 0xC, sp28, arg0, arg1, arg2);
    value = fn_802C1500((char *)arg0 + 0xC, arg2->val28);
    if (*(unsigned char *)&lbl_8055FAB0 != 0) {
        scale = *(volatile float *)((char *)arg1 + 0x10);
        result = fn_801FA8E0(fn_802BC9B0(&arg2->curve, arg2->type2c, scale), sp28, value);
        *(void **)((char *)arg0 + 0x3C) = result;
        flag = *(volatile unsigned char *)&arg2->flag30;
        *(float *)((char *)arg0 + 0x40) = *(float *)((char *)arg0 + 0x34) - *(float *)((char *)result + 0x28);
        if (flag != 0 && arg2->type2c != 0x74) {
            float f3 = arg2->curve.f6;
            float f2 = arg2->curve.f7;
            float f0;
            int w4, w3, w2, w1, w0, w5;
            curveData.f6 = f3;
            f0 = f3 + lbl_80564D28;
            f2 += lbl_80564D24;
            w4 = arg2->curve.w4;
            w3 = arg2->curve.w3;
            w2 = arg2->curve.w2;
            w1 = arg2->curve.w1;
            w0 = arg2->curve.w0;
            w5 = arg2->curve.w5;
            curveData.w0 = w0;
            scale = *(volatile float *)((char *)arg1 + 0x10);
            curveData.w1 = w1;
            curveData.w2 = w2;
            curveData.w3 = w3;
            curveData.w4 = w4;
            curveData.w5 = w5;
            curveData.f7 = f2;
            curveData.f6 = f0;
            fn_801FA8E0(fn_802BC9B0(&curveData, 0x3EB, scale), sp28, value);
        }
    } else {
        float neg = lbl_80564D14;
        *(void **)((char *)arg0 + 0x3C) = 0;
        *(float *)((char *)arg0 + 0x40) = neg;
    }
    *(int *)((char *)arg0 + 4) = 0;
}
#pragma opt_common_subs reset
extern void fn_80131810(void);
extern void fn_802C6B44(void);
extern void *fn_802B561C(void *, const char *);
extern void *fn_802B2C34(void *, int);
extern int fn_802BC4E0(void *);
void fn_802BCFB0(int *);
void fn_802CAC54(int);
int fn_802C6C20(int);
void fn_80131818();
extern int fn_802B1DA0(void *);
extern int fn_801D04D0(void);
extern int fn_802C143C(void *);
extern float PSVECMag(const Vec *);
extern void PSVECNormalize(const Vec *, Vec *);
extern int lbl_8034AB38;
extern void *lbl_8055FAB4;
__declspec(section ".sdata") extern const char lbl_8055CF40[];
__declspec(section ".sdata") extern const char lbl_8055CF48[];
__declspec(section ".sdata") extern const char lbl_8055CF50[];
__declspec(section ".sdata") extern const char lbl_8055CF58[];
__declspec(section ".sdata") extern const char lbl_8055CF60[];
extern float lbl_80564D2C;
__declspec(section ".data") extern int lbl_8034AB38;
__declspec(section ".data") extern int lbl_804C00D4;
extern void *fn_802BC4D4(void *);
#pragma push
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
extern "C" void fn_802BCBDC(void) {
    class Query {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual Vec get(const char *, ...);
    };
    void *list;
    register void *item;
    register int i;
    int count;
    register char *entry;
    register char *rdata = (char *)&lbl_8034AB38;
    float half;
    Vec bounds[2];
    Vec center;
    float dx, nx, dy, dz;
    float cx, cy, cz;
    void *value;

    list = fn_802B561C(fn_80131810, rdata + 0x28);
    lbl_8055FAB4 = list;
    if (list == 0)
        return;
    half = lbl_80564D2C;
    for (i = 0; (item = ((void *(*)(void *, int))(*(void ***)lbl_8055FAB4)[3])(lbl_8055FAB4, i)) != 0; i++) {
        if (((int (*)(void *))fn_802BC3DC)(item) != 0) {
            count = *(int *)((char *)&lbl_804C00D4 + 4);
            *(int *)((char *)&lbl_804C00D4 + 4) = count + 1;
            entry = *(char **)&lbl_804C00D4 + count * 0x60;
            *(void **)entry = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, lbl_8055CF40);
            *(void **)(entry + 4) = ((void *(*)(void *, const char *))(*(void ***)item)[23])(item, rdata + 0x38);
            value = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, rdata + 0x44);
            *(void **)(entry + 0x18) = fn_802B2C34(fn_802C6B44, (int)value);
            *(void **)(entry + 0x1C) = fn_802BC4D4(*(void **)(entry + 0x18));
            *(int *)(entry + 0x20) = fn_802BC4E0(*(void **)(entry + 0x18));
            *(int *)(entry + 0x24) = fn_802B1DA0(*(void **)(entry + 0x1C));
            value = ((void *(*)(void *, const char *))(*(void ***)item)[5])(item, rdata + 0x50);
            *(void **)(entry + 8) = fn_802B2C34(fn_802C6B44, (int)value);
            *(void **)(entry + 0xC) = fn_802BC4D4(*(void **)(entry + 8));
            *(int *)(entry + 0x10) = fn_802BC4E0(*(void **)(entry + 8));
            *(int *)(entry + 0x14) = fn_802B1DA0(*(void **)(entry + 0xC));
            *(float *)(entry + 0x5C) = ((float (*)(void *, const char *, float))(*(void ***)item)[10])(item, rdata + 0x5C, lbl_80564D14);
            *(unsigned char *)(entry + 0x30) = ((int (*)(void *, const char *, int))(*(void ***)item)[12])(item, rdata + 0x68, 1);
            ((void (*)(void *, const char *, const char *))(*(void ***)item)[6])(item, rdata + 0x74, lbl_8055CF48);
            *(int *)(entry + 0x2C) = fn_801D04D0();
            *(int *)(entry + 0x28) = fn_802C143C(item);
            *(Vec *)&bounds[0].x = ((Query *)item)->get(lbl_8055CF50);
            *(Vec *)&bounds[1].x = ((Query *)item)->get(lbl_8055CF58, *(unsigned int *)&bounds[0].x, *(unsigned int *)&bounds[0].y, *(unsigned int *)&bounds[0].z);
            {
                float minX = bounds[0].x, minY = bounds[0].y, minZ = bounds[0].z;
                float maxX = bounds[1].x, maxY = bounds[1].y, maxZ = bounds[1].z;
                dx = maxX - minX;
                nx = minX - maxX;
                dy = maxY - minY;
                dz = maxZ - minZ;
                cx = minX + half * dx;
                cy = minY + half * dy;
                cz = minZ + half * dz;
            }
            *(float *)(entry + 0x34) = cx;
            *(float *)(entry + 0x38) = cy;
            *(float *)(entry + 0x3C) = cz;
            center.x = cx;
            center.y = cy;
            center.z = cz;
            *(float *)(entry + 0x40) = nx;
            *(float *)(entry + 0x44) = bounds[0].y - bounds[1].y;
            *(float *)(entry + 0x48) = bounds[0].z - bounds[1].z;
            *(float *)(entry + 0x4C) = PSVECMag((Vec *)(entry + 0x40)) * half;
            PSVECNormalize((Vec *)(entry + 0x40), (Vec *)(entry + 0x40));
            *(float *)(entry + 0x50) = ((float (*)(void *, const char *))(*(void ***)item)[9])(item, lbl_8055CF60);
            *(float *)(entry + 0x54) = ((float (*)(void *, const char *))(*(void ***)item)[9])(item, rdata + 0x80);
            *(int *)(entry + 0x58) = 0;
        }
        i++;
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_802BCF04(void) {
#pragma scheduling invalid_target
    char *entry;
    int offset;
    int i;
    char *flag;
    i = 0;
    offset = 0;
    for (; i < *(int *)((char *)&lbl_804C00D4 + 4); i++) {
        entry = *(char **)&lbl_804C00D4 + offset;
        fn_802BCFB0((int *)(entry + 0x58));
        fn_802CAC54(*(int *)(entry + 0x20));
        fn_802C6C20(*(int *)(entry + 0x18));
        *(int *)(entry + 0x18) = 0;
        fn_802CAC54(*(int *)(entry + 0x10));
        fn_802C6C20(*(int *)(entry + 8));
        *(int *)(entry + 8) = 0;
        offset += 0x60;
    }
    flag = (char *)lbl_8055FAB4;
    *(int *)((char *)&lbl_804C00D4 + 4) = 0;
    if (flag != 0) {
        fn_80131818(flag);
        lbl_8055FAB4 = 0;
    }
}
#pragma pop
/* Release and clear the object pointer stored at *slot: if non-null, destroy
 * the subobjects held at +8 and +4, run fn_802BD070 on the object, free it
 * with fn_80128668, and set *slot to null. */
void fn_802BCFB0(int *slot) {
    int object;
    object = *slot;
    if (object != 0) {
        if (object != 0) {
            fn_802BD018((char *)object + 8);
            fn_802BD018((char *)object + 4);
            fn_802BD070((void *)object);
            fn_80128668((void *)object);
        }
        *slot = 0;
    }
}

#pragma pop

/* Returns the cached value at +4 of the first item in the container held at entry+0x58,
 * or 0 when the entry's context (+4) or the container is null. */
int fn_802BD0C8(void *entry) {
    int value = 0;
    if (*(int *)((char *)entry + 4) != 0) {
        void **container = *(void ***)((char *)entry + 0x58);
        if (container != 0)
            value = *(int *)((char *)*container + 4);
    }
    return value;
}

int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD0F4(void *owner) {
    /* Refresh each list entry's computed value from its position/radius via fn_802BA580. */
    char *entry;
    char *list;
    void *container;
    int offset;
    int count;
    int index;
    float position[2];

    if (*(int *)((char *)owner + 4) != 0 && (container = *(void **)((char *)owner + 0x58)) != 0) {
        list = *(char **)container;
        count = *(int *)(list + 4);
        index = 0;
        offset = 0;
        while (index < count) {
            int context;
            float radius;
            container = *(void **)((char *)owner + 0x58);
            list = *(char **)container;
            entry = *(char **)list + offset;
            position[0] = *(float *)(entry + 0x30);
            position[1] = *(float *)(entry + 0x38);
            radius = *(float *)(entry + 0x1c);
            context = *(int *)((char *)owner + 4);
            *(int *)(entry + 4) = fn_802BA580(context, position, radius);
            offset += 0x44;
            index++;
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Find a tree by name in the loaded tree list: its entries are TREE_ENTRY_SIZE
   bytes each and start with the tree's name. Returns the entry, or 0 when the
   list holds no tree of that name. */
void *fn_802BD194(void *treeList, const char *name) {
    unsigned int offset;
    unsigned int entryCount = ((struct TreeList *)treeList)->entryCount;
    char *entries;
    unsigned int index = 0;
    offset = 0;
    while (index < entryCount) {
        entries = ((struct TreeList *)treeList)->entries;
        if (strcmp(entries + offset, name) == 0)
            return entries + index * TREE_ENTRY_SIZE;
        offset += TREE_ENTRY_SIZE;
        index++;
    }
    return 0;
}

#pragma push
#pragma processor 750
int fn_802BD210(void *arg0) {
    #pragma unused(arg0)
    extern void *fn_8012C370(void *, unsigned int, unsigned int *, int, int, unsigned char *);
    extern void *fn_801284F8(int, int);
    extern void fn_802BD414(int, volatile int *);
    extern void fn_802BD478(int, volatile int *);
    extern void fn_802BD4DC(void *, int);
    extern void fn_80127464(void);
    register char *strings = (char *)&lbl_8034AB38;
    unsigned int spC = 0;
    unsigned char sp8;
    void *object = fn_8012C370(strings + 0x8C, 0x544C5354, &spC, 0, 0, &sp8);
    lbl_8055FAB8 = (int)object;
    if (object != 0) {
        if (spC == 2) {
            if (sp8 != 0)
                fn_802BD4DC(object, (int)((char *)object + 8));
            {
                register float normalization = lbl_80564D18;
                register void *zero = 0;
                register int offset = 0;
                register int index = 0;
                while (index < *(int *)((char *)&lbl_804C00D4 + 4)) {
                    register char *entry = *(char **)&lbl_804C00D4 + offset;
                    const char *name = *(const char **)entry;
                    void *descriptor = fn_802BD194((void *)lbl_8055FAB8, name);
                    if (descriptor != 0) {
                        void *wrapper = fn_801284F8(0xC, (int)(strings + 0x9C));
                        if (wrapper != 0) {
                            *(void **)wrapper = ((void *(*)(int, volatile int *))fn_802BD414)((int)(strings + 0xA8), (volatile int *)((char *)descriptor + 0x20));
                            *(void **)((char *)wrapper + 4) = ((void *(*)(int, volatile int *))fn_802BD478)((int)(strings + 0xB8), (volatile int *)((char *)descriptor + 0x28));
                            *(void **)((char *)wrapper + 8) = ((void *(*)(int, volatile int *))fn_802BD478)((int)(strings + 0xB8), (volatile int *)((char *)descriptor + 0x30));
                            {
                                int pointCount = *(int *)((char *)*(void **)wrapper + 4);
                                int pointIndex = 0;
                                int pointOffset = 0;
                                volatile float sp[5];
                                while (pointIndex < pointCount) {
                                    char *point = *(char **)*(void **)wrapper + pointOffset;
                                    volatile float *pointValues = (volatile float *)point;
                                    float x, xx, z, zz, xValue, zValue, scale;
                                    double root;
                                    sp[0] = *(float *)(point + 0x30);
                                    sp[1] = *(float *)(point + 0x38);
                                    sp[4] = PSVECMag((const Vec *)(point + 0x24));
                                    x = pointValues[9];
                                    sp[2] = x;
                                    xx = x * x;
                                    z = pointValues[11];
                                    sp[3] = z;
                                    zz = z * z;
                                    root = fn_8002F234(xx + zz, z);
                                    xValue = sp[2];
                                    zValue = sp[3];
                                    scale = normalization / (float)root;
                                    sp[2] = xValue * scale;
                                    sp[3] = zValue * scale;
                                    fn_802BCA8C(*(char **)*(void **)wrapper + pointOffset, (void *)sp, (struct Arg2 *)entry);
                                    if ((pointIndex & 0x3F) == 0)
                                        fn_80127464();
                                    pointOffset += 0x44;
                                    pointIndex += 1;
                                }
                            }
                            fn_802BC44C(*(void **)((char *)wrapper + 4));
                            fn_802BC44C(*(void **)((char *)wrapper + 8));
                        }
                        *(void **)(entry + 0x58) = wrapper;
                    } else {
                        *(void **)(entry + 0x58) = zero;
                    }
                    offset += 0x60;
                    index += 1;
                }
            }
        } else {
            ((void (*)(void *))Abend_Panic)(strings + 0xC8);
        }
    }
}
#pragma pop

#pragma pop
void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
#pragma processor 750
#pragma scheduling invalid_target
void fn_802BD414(int arg0, volatile int *arg1)
{
    volatile int *result;
    int first;
    result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result == 0)
        return;
    first = arg1[0];
    result[0] = arg1[1];
    result[2] = first;
    result[1] = 0;
    result[1] = result[1] + arg1[0];
}
#pragma scheduling on
void fn_802BD478(int arg0, volatile int *arg1)
{
  volatile int *result = (volatile int *) fn_801284F8(0xC, arg0);
  if (result != 0)
  {
    int first = (int)arg1[0];
    result[0] = (int)arg1[1];
    result[2] = first;
    result[1] = 0;
    result[1] = (int)(result[1] + arg1[0]);
  }
}
#pragma peephole reset
#pragma scheduling reset
void fn_802BD4DC(void *data, int dataBase) {
    extern void fn_802BD69C(void *, int);
    extern void fn_802BD5B0(void *, int);
#define SwapTreeFrameList fn_802BD69C
#define SwapTreeNearList  fn_802BD5B0
#define RelocateOffset    fn_802BD5A8
    /* RealName: SwapTreeListBlock. Byte-swap the loaded "treelist.trl" TLST
       block in place and relocate its offsets: convert the header and each
       tree entry's frame list (+0x20) and near lists (+0x28/+0x30) from
       big-endian, then add `dataBase` to every stored offset to turn it into
       a real pointer. */
    unsigned char *bytes = data;
    struct TreeList *list = data;
    char *entry;
    int offset;
    unsigned int index;
    unsigned char b7, b2, b3, b0, b1, b4, b5;
    b4 = bytes[4]; b5 = bytes[5];
    b7 = bytes[7];
    bytes[4] = b7; b0 = bytes[0]; b3 = bytes[3]; bytes[7] = b4;
    b1 = bytes[1]; b2 = bytes[2]; bytes[5] = bytes[6]; bytes[6] = b5;
    bytes[0] = b3; bytes[3] = b0; bytes[1] = b2; bytes[2] = b1;
    *(int *)(bytes + 4) = RelocateOffset(*(int *)(bytes + 4), dataBase);
    index = 0;
    offset = 0;
    while (index < list->entryCount) {
        entry = list->entries + offset;
        SwapTreeFrameList(entry + 0x20, dataBase);
        SwapTreeNearList(entry + 0x28, dataBase);
        SwapTreeNearList(entry + 0x30, dataBase);
        offset += TREE_ENTRY_SIZE;
        index++;
    }
#undef SwapTreeFrameList
#undef SwapTreeNearList
#undef RelocateOffset
}
#pragma pop

/* Return the sum of two integers (used to advance a stored value by a delta). */
int fn_802BD5A8(int value, int delta) { return value + delta; }

#pragma cplusplus on
extern "C" void fn_802BD5B0(void *arg0, int arg1) {
    extern int fn_802BD694(int, int);
    extern float lbl_80564D30;
    unsigned char *p = (unsigned char *)arg0;
    register unsigned char *entry;
    int offset;
    unsigned int i;
    float zero;
    unsigned char b7, b2, b3, b0, b1, b4, b5;
    b4 = p[4]; b5 = p[5];
    b7 = p[7];
    p[4] = b7; b0 = p[0]; b3 = p[3]; p[7] = b4;
    b1 = p[1]; b2 = p[2]; p[5] = p[6]; p[6] = b5;
    p[0] = b3; p[3] = b0; p[1] = b2; p[2] = b1;
    *(int *)(p + 4) = fn_802BD694(*(int *)(p + 4), arg1);
    i = 0; zero = -1.0f; offset = 0;
    while (i < *(unsigned int *)p) {
        unsigned char tmp;
        entry = *(unsigned char **)(p + 4) + offset;
        tmp = entry[4]; entry[4] = entry[5]; entry[5] = tmp;
        tmp = entry[6]; entry[6] = entry[7]; entry[7] = tmp;
        tmp = entry[8]; entry[8] = entry[9]; entry[9] = tmp;
        tmp = entry[10]; entry[10] = entry[11]; entry[11] = tmp;
        *(float *)(entry + 12) = zero;
        offset += 0x10; i++;
    }
}
#pragma cplusplus reset

/* Return the sum of two integers (used to advance a stored value by a delta). */
int fn_802BD694(int value, int delta) { return value + delta; }

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802BD69C(void *arg0, int arg1)
{
  extern int fn_802BD80C(int, int);
  unsigned char *p = arg0;
  unsigned char *entry;
  int offset;
  unsigned int i;
  unsigned char b7;
  unsigned char b2;
  unsigned char b3;
  unsigned char b0;
  unsigned char b1;
  unsigned char b4;
  unsigned char b5;
  unsigned char tmp;
  b4 = p[4];
  b5 = p[5];
  b7 = p[7];
  p[4] = b7;
  b0 = p[0];
  b3 = p[3];
  p[7] = b4;
  b1 = p[1];
  b2 = p[2];
  p[5] = p[6];
  p[6] = b5;
  p[0] = b3;
  p[3] = b0;
  p[1] = b2;
  p[2] = b1;
  *((int *) (p + 4)) = fn_802BD80C(*((int *) (p + 4)), arg1);
  i = 0;
  offset = 0;
  while (i < (*((unsigned int *) p)))
  {
    int j;
    entry = ((*((unsigned char **) (p + 4))) + offset) + 0xC;
    for (j = 0; j < 2; j++, entry += 0x18)
    {
      tmp = entry[0];
      entry[0] = entry[3];
      entry[3] = tmp;
      i = entry[1];
      tmp = i;
      entry[1] = entry[2];
      entry[2] = tmp;
      tmp = entry[4];
      entry[4] = entry[7];
      entry[7] = tmp;
      tmp = entry[5];
      entry[5] = entry[6];
      entry[6] = tmp;
      tmp = entry[8];
      entry[8] = entry[0xB];
      entry[0xB] = tmp;
      tmp = entry[9];
      entry[9] = entry[0xA];
      entry[0xA] = tmp;
      offset = 0xC;
      tmp = entry[0xC];
      entry[offset] = entry[0xF];
      entry[0xF] = tmp;
      tmp = entry[0xD];
      entry[0xD] = entry[0xE];
      entry[0xE] = tmp;
      tmp = entry[0x10];
      entry[0x10] = entry[0x13];
      entry[0x13] = tmp;
      tmp = entry[0x11];
      entry[0x11] = entry[0x12];
      entry[0x12] = tmp;
      tmp = entry[0x14];
      entry[0x14] = entry[0x17];
      entry[0x17] = tmp;
      tmp = entry[0x15];
      entry[0x15] = entry[0x16];
      entry[0x16] = tmp;
    }

    offset += 0x44;
    i++;
  }

}
#pragma scheduling on
#pragma pop

// Relocation fixup helper: add a delta to a stored pointer/value and return the adjusted result.
int fn_802BD80C(int base, int delta) { return base + delta; }

__declspec(section ".data") extern int lbl_8034AC48;
#pragma scheduling invalid_target
extern int __cntlzw(unsigned int);
#pragma scheduling invalid_target
/* Tree-system startup for a level: primes the tree-hit and tree-descriptor
   subsystems, registers the two debug counters, loads the tree list when a
   software map is present, and creates and publishes the System dispatch
   object. */
void fn_802BDBA8(void) {
#define treeStrings     lbl_8034AB38
#define counterHits     lbl_8055FAA8
#define counterCost     lbl_8055FAAC
#define noMapFlag       lbl_8055FAB0
#define systemObject    lbl_8055FABC
#define objectVtable    lbl_8034AC48
#define InitTreeHit     fn_802C126C
#define InitTreeDesc    fn_802BCBDC
#define RegisterCounter fn_802B8AE0
#define HasMapTexture   fn_802B05E4
#define LoadTreeList    fn_802BD210
#define AllocNamed      fn_801284F8
#define InitDispatch    fn_802C2914

    char *strings = (char *)&treeStrings;
    void *object;
    int hasMapTexture;

    InitTreeHit();
    InitTreeDesc();
    RegisterCounter(strings + 0xE8, &counterHits);
    RegisterCounter(strings + 0xF4, &counterCost);
    hasMapTexture = HasMapTexture();
    *(char *)&noMapFlag = hasMapTexture == 0;
    if (hasMapTexture != 0) {
        ((void (*)(void))LoadTreeList)();
    }
    object = AllocNamed(8, (int)(strings + 0x104));
    if (object != 0) {
        InitDispatch(object);
        *(void **)((char *)object + 4) = &objectVtable;
    }
    systemObject = object;
    return;

#undef treeStrings
#undef counterHits
#undef counterCost
#undef noMapFlag
#undef systemObject
#undef objectVtable
#undef InitTreeHit
#undef InitTreeDesc
#undef RegisterCounter
#undef HasMapTexture
#undef LoadTreeList
#undef AllocNamed
#undef InitDispatch
}
#pragma scheduling on
/* Chained initializer: parses the tree/resource data (fn_802BD210) and then
 * sets up each entry's render state (fn_802C1550). */
void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

void fn_802BCF04(void);
void fn_8012C4D8(void);
void fn_802C13A4(void);
void deleteThreads__6SystemFv_802BDCA4(void **);
void fn_802BDC60(void) {
    /* Shuts down the subsystem: finalizes it, releases the active handle if set, performs cleanup, and deletes the system thread object. */
#define activeHandle lbl_8055FAB8
#define systemThreadSlot lbl_8055FABC
#define Subsystem_Finalize fn_802BCF04
#define Handle_Release fn_8012C4D8
#define Subsystem_Cleanup fn_802C13A4
#define System_DeleteThreadSlot deleteThreads__6SystemFv_802BDCA4

    int handle;

    Subsystem_Finalize();
    handle = activeHandle;
    if (handle != 0) {
        ((int (*)(int))Handle_Release)(handle);
        activeHandle = 0;
    }
    Subsystem_Cleanup();
    System_DeleteThreadSlot(&systemThreadSlot);

#undef activeHandle
#undef systemThreadSlot
#undef Subsystem_Finalize
#undef Handle_Release
#undef Subsystem_Cleanup
#undef System_DeleteThreadSlot
}

extern int lbl_8034AB38, lbl_8034AC48;
extern int lbl_8055FAA8, lbl_8055FAAC, lbl_8055FAB0;
extern void *lbl_8055FABC;
#pragma push
#pragma cplusplus on
/* Deletes the System thread object stored in *threadSlot, if any, then clears the slot. */
extern "C" void deleteThreads__6SystemFv_802BDCA4(void **threadSlot) {
    class Base {
    public:
        void *unk0;
    };
    class ThreadObject : public Base {
    public:
        virtual void dummy1();
        virtual void dummy2();
        virtual void destroy(int);
    };
    ThreadObject *thread = *(ThreadObject **)threadSlot;
    if (thread) {
        if (thread)
            thread->destroy(1);
        *(ThreadObject **)threadSlot = 0;
    }
}
#pragma cplusplus reset
#pragma pop
void fn_802C2930(void*, unsigned int);
#pragma push
#pragma scheduling invalid_target
/* Release the pointer list stored at *slot (an owner's +4 / +8 subobject slot, see
 * fn_802BCFB0): clear its { item array, count, capacity } header, free it with
 * fn_80128668 and set the slot to null. */
void fn_802BD018(void *slot) {
    struct PtrTable {
        /* 0x0 */ void **items;
        /* 0x4 */ int count;
        /* 0x8 */ int capacity;
    } *table = *(void **)slot;

    if (table) {
        if (table) {
            table->items = 0;
            table->count = 0;
            table->capacity = 0;
            fn_80128668(table);
        }
        *(void **)slot = 0;
    }
}

int fn_802BD070(void *slot) {
    /* Clear the 3-word object stored at *slot, free it (mode 3), and clear the slot. */
    void *obj = *(void **)slot;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)slot = 0;
    }
}

#pragma pop
/* Destructor for nw4hbm::snd::MemorySoundArchive: runs base destruction with
 * shouldDelete=0, then if requested frees this object. Returns this. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long self, long shouldDelete) {
    if (self != 0) {
        fn_802C2930((void *)self, 0);
        if (shouldDelete > 0) {
            fn_80128668((void *)self);
        }
    }
    return self;
}

/* Forward to the instanced debug-entry drawer (drawDebugEntries / fn_802BD814),
 * used here to draw pending entries during a scene transition. */
void fn_802BDD54(void) {
    fn_802BD814();
}

void fn_802BDD58(void) {
#define getCurrentTime fn_801E7E18
#define updateEffectTransforms fn_802C173C
#define isDebugDrawEnabled fn_8020403C
#define drawDebugEntries fn_802BD814
    /* Per-frame debug draw: read the current time to drive effect transforms, then draw debug entries when enabled. */
    getCurrentTime();
    updateEffectTransforms();
    if (isDebugDrawEnabled() != 0) drawDebugEntries();
#undef drawDebugEntries
#undef isDebugDrawEnabled
#undef updateEffectTransforms
#undef getCurrentTime
}

extern int lbl_8055FAA8;
extern int lbl_8055FAAC;
extern float lbl_80564D4C;
void fn_802DBE4C(void);
int fn_8020403C(void);
void fn_802C28C0(void);
void fn_802C8BD0(void);
void fn_802DC71C(int, int);
void fn_801F1C24(float *);
char *fn_801E8718(int);
float PSVECSquareDistance(void *, void *);
void fn_802DCAE4(int, float *, float);
void fn_802DC8B4(void);
void DrawList_RestoreNormalMode(void);
void fn_802DBECC(void);

/* One "tree-volume" entry of the list at lbl_804C00D4 (fn_802BCBDC fills one in
 * per tree-volume item, fn_802BD210 hangs the treelist.trl wrapper on it at
 * +0x58).  The CPU-light pass reads the far model's light handle (+0x1C) and
 * texture set (+0x20), that model's level (+0x24) and the wrapper (+0x58). */
#define TREE_VOLUME_SIZE 0x60
struct TreeVolume {
    /* 0x00 */ const char *name;
             char pad04[0x18];
    /* 0x1C */ int lightModel;   /* fn_802BC4D4(far model) */
    /* 0x20 */ int lightTexture; /* fn_802BC4E0(far model) */
    /* 0x24 */ int modelLevel;   /* fn_802B1DA0(lightModel); lights draw up to 10 */
             char pad28[0x30];
    /* 0x58 */ struct TreeLightObject *lightObject;
             char pad5C[4];
};

/* The treelist.trl wrapper allocated by fn_802BD210: the tree's frame-list
 * points and the two near-list groups built over them (fn_802BCFB0 releases
 * all three lists). */
struct TreeLightObject {
    /* 0x00 */ struct TreePointList *frames;
    /* 0x04 */ struct TreeGroupList *nearA;
    /* 0x08 */ struct TreeGroupList *nearB;
};

/* { items, count, count-at-load } list headers (fn_802BD414 / fn_802BD478). */
struct TreePointList {
    /* 0x00 */ struct TreePoint *points;
    /* 0x04 */ int count;
    /* 0x08 */ int total;
};
struct TreeGroupList {
    /* 0x00 */ struct TreeGroup *groups;
    /* 0x04 */ int count;
    /* 0x08 */ int total;
};

/* One frame-list point (0x44 bytes, byte-swapped by fn_802BD69C): the CPU-light
 * pass uses its radius (+0x1C, refreshed by fn_802BD0F4) and its world
 * position (+0x30). */
#define TREE_POINT_SIZE 0x44
struct TreePoint {
             char pad0[4];
    /* 0x04 */ int value;
             char pad08[0x14];
    /* 0x1C */ float radius;
             char pad20[4];
    /* 0x24 */ float direction[3];
    /* 0x30 */ float position[3];
             char pad3C[8];
};

/* One near-list group (0x10 bytes, byte-swapped by fn_802BD5B0): the range of
 * frame-list points it covers and a weight fn_802BD5B0 clears to -1.0f; a
 * negative weight disables the group. */
#define TREE_GROUP_SIZE 0x10
struct TreeGroup {
             char pad0[8];
    /* 0x08 */ short pointCount;
    /* 0x0A */ short pointStart;
    /* 0x0C */ float weight;
};

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* RealName: DrawTreeVolumeCpuLights (see the comment in the body). */
void fn_802BDD8C(float radius) {
#define BeginCpuLighting   fn_802DBE4C
#define EndCpuLighting     fn_802DBECC
#define isDebugDrawEnabled fn_8020403C
#define GetSwlMapSlot      fn_802C28C0
#define BeginDrawList      fn_802C8BD0
#define EndDrawList        DrawList_RestoreNormalMode
#define BeginLightBatch    fn_802DC71C
#define FlushLightBatch    fn_802DC8B4
#define QueueLightSprite   fn_802DCAE4
#define BuildCameraBasis   fn_801F1C24
#define GetPlayerEntry     fn_801E8718
#define kZero              lbl_80564D14 /* 0.0f */
#define kOne               lbl_80564D18 /* 1.0f */
#define kFadeRange         lbl_80564D4C /* 50.0f */
#define treeList           lbl_804C00D4 /* { char *entries; int count; } of TreeVolume records */
#define lightCount         lbl_8055FAA8 /* debug counter "tree-count" */
#define lightCost          lbl_8055FAAC /* debug counter "tree-tri-count" */
    /* CPU-light pass over the tree list: for every tree volume that has a
     * treelist wrapper at +0x58 and a far model of level 10 or below, open a
     * light batch on that model and queue one camera-facing light sprite for
     * every frame-list point of the volume's near-list groups that lies within
     * `radius` of the current player.  A sprite's alpha fades from full at
     * radius-50 to none at `radius`; the sprite's 3x3 part is the camera basis
     * scaled by the point's radius. */
    float sprite[12];
    float basis[12];
    struct TreePointList *points;
    struct TreeGroupList *groups;
    int pointIdx;
    int model;
    int j;
    char *camPos;
    struct TreeVolume *tree;
    struct TreeGroup *group;
    int treeOff;
    int groupOff;
    int pointOff;
    int i;
    int *list;
    struct TreePoint *point;
    BeginCpuLighting();
    if (isDebugDrawEnabled() != 0) {
        float one = kOne;
        float minWeight = kZero;
        float falloff;
        float fadeRange = kFadeRange;
        float outerSq;
        lightCost = 0;
        lightCount = 0;
        list = &treeList;
        i = 0;
        treeOff = 0;
        while (i < list[1]) {
            tree = (struct TreeVolume *)(*(char **)&treeList + treeOff);
            {
                struct TreeLightObject *lightObject = tree->lightObject;
                if (lightObject != 0) {
                    groups = lightObject->nearA;
                    points = lightObject->frames;
                    if (tree->modelLevel <= 10) {
                        GetSwlMapSlot(); /* its result reaches BeginDrawList in r3 */
                        BeginDrawList();
                        BeginLightBatch(tree->lightModel, tree->lightTexture);
                        outerSq = radius * radius;
                        falloff = outerSq - (radius - fadeRange) * (radius - fadeRange);
                        BuildCameraBasis(basis);
                        camPos = GetPlayerEntry(-1) + 0x24;
                        j = 0;
                        groupOff = 0;
                        while (j < groups->count) {
                            group = (struct TreeGroup *)((char *)groups->groups + groupOff);
                            {
                                int enabled = (group->weight >= minWeight);
                                if (enabled) {
                                    pointIdx = group->pointStart;
                                    model = tree->lightModel;
                                    pointOff = pointIdx * TREE_POINT_SIZE;
                                    while (pointIdx < group->pointStart + group->pointCount) {
                                        point = (struct TreePoint *)((char *)points->points + pointOff);
                                        {
                                            float distSq = PSVECSquareDistance(point->position, camPos);
                                            if (distSq <= outerSq) {
                                                float alpha = (outerSq - distSq) / falloff;
                                                float scale;
                                                if (one < alpha) alpha = one;
                                                scale = point->radius;
                                                sprite[9] = point->position[0];
                                                sprite[10] = point->position[1];
                                                sprite[11] = point->position[2];
                                                sprite[0] = basis[0] * scale;
                                                sprite[1] = basis[1] * scale;
                                                sprite[2] = basis[2] * scale;
                                                sprite[3] = basis[3] * scale;
                                                sprite[4] = basis[4] * scale;
                                                sprite[5] = basis[5] * scale;
                                                sprite[6] = basis[6] * scale;
                                                sprite[7] = basis[7] * scale;
                                                sprite[8] = basis[8] * scale;
                                                QueueLightSprite(model, sprite, alpha);
                                            }
                                        }
                                        pointOff += TREE_POINT_SIZE;
                                        pointIdx++;
                                    }
                                }
                            }
                            groupOff += TREE_GROUP_SIZE;
                            j++;
                        }
                        FlushLightBatch();
                        EndDrawList();
                    }
                }
            }
            treeOff += TREE_VOLUME_SIZE;
            i++;
        }
    }
    EndCpuLighting();
#undef EndCpuLighting
#undef BeginCpuLighting
#undef isDebugDrawEnabled
#undef GetSwlMapSlot
#undef BeginDrawList
#undef EndDrawList
#undef BeginLightBatch
#undef FlushLightBatch
#undef QueueLightSprite
#undef BuildCameraBasis
#undef GetPlayerEntry
#undef kZero
#undef kOne
#undef kFadeRange
#undef treeList
#undef lightCount
#undef lightCost
}
#pragma pop
/* Stamp a band-selected weight into the +0xC field of every node in a grid
 * cell's list: 1.0 (lbl_80564D18) below band 8, fadeWeight at band 8, and
 * 0.0 (lbl_80564D14) above band 8. The cell's head pointer is at +4 and each
 * node's next pointer is at +0. */
void fn_802BDFBC(void *cell, int distanceBand, float fadeWeight) {
    float weight = fadeWeight;
    void *node;
    if (distanceBand < 8) {
        weight = lbl_80564D18;
    } else if (distanceBand == 8) {
        weight = fadeWeight;
    } else {
        weight = lbl_80564D14;
    }
    node = *(void **)((char *)cell + 4);
    while (node != 0) {
        *(float *)((char *)node + 0xC) = weight;
        node = *(void **)node;
    }
}

extern float lbl_80564D14;
extern float lbl_80564D18;
void fn_802BAF98(void *, int);
/* If the owner back-pointer stored 8 bytes before `node` is non-null, set the
 * owner's +0xC byte field to `value` via fn_802BAF98. */
void fn_802BDFF4(void *node, int value) {
    node = *(void **)((char *)node - 8);
    if (node != 0) {
        fn_802BAF98(node, value);
    }
}

#pragma scheduling invalid_target
void *fn_802BE008(void *arg0) {
    int count = *(int *)((char *)&lbl_804C00D4 + 4);
    int found;
    char *entry = *(char **)&lbl_804C00D4;
    int i;
    for (i = 0; i < count; i++, entry += 0x60) {
        char *list = *(char **)(entry + 0x58);
        if (list != 0) {
            char *item = *(char **)(list + 8);
            found = 0;
            if ((unsigned)arg0 >= (unsigned)*(int *)item && (unsigned)arg0 < (unsigned)*(int *)item + (unsigned)*(int *)(item + 4) * 0x10) {
                found = 1;
            }
            if (found != 0) {
                return entry;
            }
        }
    }
    return 0;
}
#pragma scheduling on
extern void *fn_802BE008(void *);
extern void *fn_802BE844(short, short, short);
extern float lbl_80564D10, lbl_80564D2C;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802BE07C(void *arg0, float (*arg1)(int, int, int, short, float, float, float)) {
    float worldZ, worldX, scale, weight;
    int baseX, baseZ;
    int zCell, xCell, zOffset, xOffset;
    void *cell, *node, *obj, *map, *mesh;
    short ix, iz;
    float dx, dz;
    worldX = *(volatile float *)arg0;
    scale = lbl_80564D10;
    xOffset = -0x80;
    worldZ = *(volatile float *)((char *)arg0 + 8);
    baseX = (short)(((short)(int)(worldX / scale)) / 0x80 * 0x80 + 0x40);
    weight = lbl_80564D2C;
    baseZ = (short)(((short)(int)(worldZ / scale)) / 0x80 * 0x80 + 0x40);
    for (xCell = baseX - 0x80; xOffset <= 0x80; xOffset += 0x80, xCell += 0x80) {
        for (zOffset = -0x80, zCell = baseZ - 0x80; zOffset <= 0x80; zOffset += 0x80, zCell += 0x80) {
            cell = fn_802BE844((short)xCell, (short)zCell, 0x40);
            node = *(void **)((char *)cell + 4);
            while (node != 0) {
                obj = fn_802BE008(node);
                map = *(void **)((char *)obj + 0x58);
                if (map != 0 && *(int *)((char *)obj + 0x24) <= 10) {
                    mesh = *(void **)((char *)obj + 0x18);
                    ix = *(short *)((char *)node + 0xA);
                    iz = *(short *)((char *)node + 8);
                    dx = *(float *)((char *)mesh + 0x30) - *(float *)((char *)mesh + 0x2C);
                    dz = *(float *)((char *)mesh + 0x38) - *(float *)((char *)mesh + 0x34);
                    arg1(*(int *)((char *)obj + 0x20), ix * 0x44 + *(int *)*(void **)map + 0x30, 0x44, iz, dx * weight, dz, dx);
                }
                node = *(void **)node;
            }
        }
    }
}
#pragma pop
extern int lbl_804C00D4;
#pragma push
#pragma use_lmw_stmw off
/* Sum fn_802BD0C8 over each 0x60-byte entry in the list at lbl_804C00D4. */
int fn_802BE1D8(void) {
    int entryOffset;
    int total;
    int index;
    total = 0;
    index = 0;
    entryOffset = 0;
    while (index < *(int *)((char *)&lbl_804C00D4 + 4)) {
        total += fn_802BD0C8(*(char **)&lbl_804C00D4 + entryOffset);
        entryOffset += 0x60;
        index++;
    }
    return total;
}
#pragma pop
/* Calls fn_802BD0F4 for each 0x60-byte entry in the global list at lbl_804C00D4. */
void fn_802BE244(void) {
    int entryOffset = 0;
    int index = 0;
    while (index < *(int *)((char *)&lbl_804C00D4 + 4)) {
        fn_802BD0F4(*(char **)&lbl_804C00D4 + entryOffset);
        entryOffset += 0x60;
        index++;
    }
}

void *fn_801284F8(int, int);

/* Two draw passes at 0x802BD814. Layouts below follow the indexed load strides:
 * 0x60 per entry, 0x10 per group, 0x44 per instance. */
typedef struct { unsigned char pad[0x28]; float height; } DrawAnchorBD814;
typedef struct {
    unsigned char pad0[0xC];
    float transform[9];
    float position[3];
    DrawAnchorBD814 *anchor;
    float heightOffset;
} DrawInstanceBD814;
typedef struct { DrawInstanceBD814 *data; int count; } DrawInstancesBD814;
typedef struct { int pad[2]; short count, first; float time; } DrawGroupBD814;
typedef struct { DrawGroupBD814 *data; int count; } DrawGroupsBD814;
typedef struct {
    DrawInstancesBD814 *instances;
    DrawGroupsBD814 *firstPass, *secondPass;
} DrawDataBD814;
typedef struct {
    int pad0[3];
    int firstHandle, firstState, firstCost;
    int pad18;
    int secondHandle, secondState, secondCost;
    unsigned char pad28[0x30];
    DrawDataBD814 *data;
    int pad5C;
} DrawEntryBD814;
typedef struct { DrawEntryBD814 *data; int count; } DrawEntriesBD814;
extern float lbl_80564D30, lbl_80564D34, lbl_80564D38;
extern float lbl_80564D3C, lbl_80564D40, lbl_80564D44, lbl_80564D48;
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_802BD814(void)
{
  float constant40;
  float constant3C;
  float constant30;
  float constant48;
  float new_var3;
  float new_var2;
  float constant44;
  float constant14;
  float constant38;
  float constant34;
  float constant18;
  float transform[12];
  float matrix[12];
  DrawEntriesBD814 *entries = (DrawEntriesBD814 *) (&lbl_804C00D4);
  int entryIndex;
  float new_var;
  new_var2 = lbl_80564D40;
  new_var = lbl_80564D14;
  constant18 = lbl_80564D18;
  constant14 = new_var;
  constant40 = new_var2;
  constant44 = lbl_80564D44;
  constant48 = lbl_80564D48;
  constant30 = lbl_80564D30;
  constant3C = lbl_80564D3C;
  constant34 = lbl_80564D34;
  constant38 = lbl_80564D38;
  lbl_8055FAAC = 0;
  lbl_8055FAA8 = 0;
  for (entryIndex = 0; entryIndex < entries->count; ++entryIndex)
  {
    DrawEntryBD814 *entry = &entries->data[entryIndex];
    DrawDataBD814 *data = entry->data;
    DrawGroupsBD814 *groups;
    DrawInstancesBD814 *instances;
    int groupIndex;
    if (!data)
    {
      continue;
    }
    groups = data->firstPass;
    instances = data->instances;
    fn_802C28C0();
    fn_802C8BD0();
    fn_802DC71C(entry->firstHandle, entry->firstState);
    for (groupIndex = 0; groupIndex < groups->count; ++groupIndex)
    {
      DrawGroupBD814 *group = &groups->data[groupIndex];
      float t = (group->time - constant34) / constant38;
      float alpha;
      int visible;
      if (constant18 < t)
      {
        t = constant18;
      }
      t = (t > constant14) ? (t) : (constant14);
      alpha = constant14 + (t * constant18);
      visible = group->time >= constant14;
      new_var3 = constant40;
      if (visible && (alpha > constant3C))
      {
        int index;
        int handle = entry->firstHandle;
        int cost = entry->firstCost;
        for (index = group->first; index < (group->first + group->count); ++index)
        {
          DrawInstanceBD814 *instance = &instances->data[index];
          if (instance->anchor && (instance->position[1] > new_var3))
          {
            instance->position[1] = instance->anchor->height + instance->heightOffset;
          }
          fn_802DCAE4(handle, instance->transform, alpha);
          ++lbl_8055FAA8;
          lbl_8055FAAC += cost;
        }

        group->time = constant30;
      }
    }

    fn_802DC8B4();
    DrawList_RestoreNormalMode();
    groups = entry->data->secondPass;
    instances = entry->data->instances;
    if (entry->secondCost <= 10)
    {
      fn_802C28C0();
      fn_802C8BD0();
      fn_802DC71C(entry->secondHandle, entry->secondState);
      fn_801F1C24(matrix);
      for (groupIndex = 0; groupIndex < groups->count; ++groupIndex)
      {
        DrawGroupBD814 *group = &groups->data[groupIndex];
        int visible = group->time >= constant14;
        if (visible)
        {
          float t = (group->time - constant44) / constant48;
          float alpha;
          if (constant18 < t)
          {
            t = constant18;
          }
          t = (t > constant14) ? (t) : (constant14);
          alpha = constant18 + (t * constant30);
          if (alpha > constant3C)
          {
            int index;
            int handle = entry->secondHandle;
            int cost = entry->secondCost;
            for (index = group->first; index < (group->first + group->count); ++index)
            {
              DrawInstanceBD814 *instance = &instances->data[index];
              float scale;
              if (instance->anchor && (instance->position[1] > new_var3))
              {
                instance->position[1] = instance->anchor->height + instance->heightOffset;
              }
              scale = instance->transform[4];
              transform[9] = instance->position[0];
              transform[10] = instance->position[1];
              transform[11] = instance->position[2];
              transform[0] = matrix[0] * scale;
              transform[1] = matrix[1] * scale;
              transform[2] = matrix[2] * scale;
              transform[3] = matrix[3] * scale;
              transform[4] = matrix[4] * scale;
              transform[5] = matrix[5] * scale;
              transform[6] = matrix[6] * scale;
              transform[7] = matrix[7] * scale;
              transform[8] = matrix[8] * scale;
              fn_802DCAE4(handle, transform, alpha);
              ++lbl_8055FAA8;
              lbl_8055FAAC += cost;
            }

          }
          group->time = constant30;
        }
      }

      fn_802DC8B4();
      DrawList_RestoreNormalMode();
    }
  }

}
#pragma pop

#pragma cplusplus reset
