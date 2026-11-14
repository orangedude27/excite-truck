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
extern void fn_802E317C(const char *, ...);
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
int fn_802BC334(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

#pragma dont_inline on
  int stricmp(const char *, const char *);
  __declspec(section ".sdata") extern const char lbl_8055CF38[];
#pragma push
#pragma cplusplus on
extern "C" int fn_802BC39C(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&lbl_8055CF38, ((Obj *)arg0)->getName()) == 0;
}
#pragma cplusplus reset
#pragma pop

void *fn_802BE844(short, short, short);
int fn_802BC39C();
void fn_802BC3DC(void) {
    fn_802BC39C();
}

#pragma scheduling invalid_target
void fn_802BC3E0(short arg0, short arg1, short arg2, char *arg3) {
    char *obj = fn_802BE844(arg0, arg1, arg2);
    *(char **)arg3 = *(char **)(obj + 4);
    *(char **)(obj + 4) = arg3;
}
#pragma scheduling on
short fn_802BC424(int arg0) {
    int mask = 0x1FF;
    short value = arg0 + 0x200;
    while ((value & mask) != 0)
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

void *fn_802BC4D4(void *arg0) {
    return *(void **)(*(char **)((char *)arg0 + 4) + 0xC);
}

#pragma scheduling on
int fn_802BC4E0(void *__restrict arg0) {
    int result = fn_802C9C24(*(int *)((char *)arg0 + 4));
    if (fn_8012C33C() == 0)
        fn_802E317C((const char *)&lbl_8034AB38, result);
    return fn_802B110C(&fn_802BC334, result);
}
double fn_8002F234(float, float);
#pragma push
#pragma processor 750
float fn_802BC540(void *arg0, float farg0) {
    float x = *(float *)arg0;
    float z = *(float *)((char *)arg0 + 8);
    float s = x * x + z * z;
    return farg0 * (float)fn_8002F234(s, z);
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
PSVECCrossProduct((Vec *)(arg1 + 6), (Vec *)arg1, (Vec *)(arg1 + 3));
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
#pragma pop
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_802BC9B0(void *arg0, int arg1, float scale) {
    extern void *fn_801284F8(int, int);
    extern float lbl_80564D1C, lbl_80564D20;
    extern int lbl_8034AB54[], lbl_80333918[];
    float bInput = *(float *)((char *)arg0 + 0x1C);
    float aInput = *(float *)((char *)arg0 + 0x18);
    float value = lbl_80564D1C;
    float b = bInput * scale;
    float a = aInput * scale;
    char *obj = fn_801284F8(0x2C, (int)&lbl_8034AB54);
    if (obj != 0) {
        float initial = lbl_80564D20;
        *(int *)(obj + 0xC) = 0;
        *(int *)(obj + 4) = 0;
        *(int *)(obj + 8) = 0;
        *(int *)(obj + 0x18) = 0x54554245;
        *(float *)(obj + 0x10) = value;
        *(float *)(obj + 0x14) = initial;
        *(int *)(obj + 0x20) = 100;
        *(int *)(obj + 0x1C) = 0;
        *(float *)(obj + 0x24) = b;
        *(float *)(obj + 0x28) = a;
        *(void **)obj = &lbl_80333918;
    }
    ((void (*)(void *, int))(*(void (**)(void *, int))((char *)*(void **)obj + 0x40)))(obj, arg1);
    return obj;
}
#pragma pop

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
    fn_802BC588((char *)arg0 + 0xC, sp28, arg0, arg1, arg2);
    value = fn_802C1500((char *)arg0 + 0xC, arg2->val28);
    if (*(unsigned char *)&lbl_8055FAB0 != 0) {
        scale = *(volatile float *)((char *)arg1 + 0x10);
        result = fn_801FA8E0(fn_802BC9B0(&arg2->curve, arg2->type2c, scale), sp28, value);
        *(void **)((char *)arg0 + 0x3C) = result;
        *(float *)((char *)arg0 + 0x40) = *(float *)((char *)arg0 + 0x34) - *(float *)((char *)result + 0x28);
        if (arg2->flag30 != 0 && arg2->type2c != 0x74) {
            float f3 = arg2->curve.f6;
            float f2 = arg2->curve.f7;
            float f0;
            int r9, r8, r7, r6, r5, r0;
            curveData.f6 = f3;
            f0 = f3 + lbl_80564D28;
            f2 += lbl_80564D24;
            r9 = arg2->curve.w0;
            r8 = arg2->curve.w1;
            r7 = arg2->curve.w2;
            r6 = arg2->curve.w3;
            r5 = arg2->curve.w4;
            r0 = arg2->curve.w5;
            curveData.w0 = r9;
            curveData.w1 = r8;
            curveData.w2 = r7;
            curveData.w3 = r6;
            curveData.w4 = r5;
            curveData.w5 = r0;
            curveData.f7 = f2;
            curveData.f6 = f0;
            scale = *(volatile float *)((char *)arg1 + 0x10);
            fn_801FA8E0(fn_802BC9B0(&curveData, 0x3EB, scale), sp28, value);
        }
    } else {
        *(void **)((char *)arg0 + 0x3C) = 0;
        *(float *)((char *)arg0 + 0x40) = lbl_80564D14;
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
void fn_80131818(void);
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
    float min[3], max[3], center[3];
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
            *(Vec *)min = ((Query *)item)->get(lbl_8055CF50);
            *(Vec *)max = ((Query *)item)->get(lbl_8055CF58, *(unsigned int *)&min[0], *(unsigned int *)&min[1], *(unsigned int *)&min[2]);
            {
                float minX = min[0], minY = min[1], minZ = min[2];
                float maxX = max[0], maxY = max[1], maxZ = max[2];
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
            center[0] = cx;
            center[1] = cy;
            center[2] = cz;
            *(float *)(entry + 0x40) = nx;
            *(float *)(entry + 0x44) = min[1] - max[1];
            *(float *)(entry + 0x48) = min[2] - max[2];
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
    void *base;
    char *entry;
    int i;
    int offset;
    base = *(void **)&lbl_804C00D4;
    i = 0;
    offset = 0;
    goto check;
loop:
    entry = (char *)base + offset;
    fn_802BCFB0((int *)(entry + 0x58));
    fn_802CAC54(*(int *)(entry + 0x20));
    fn_802C6C20(*(int *)(entry + 0x18));
    *(int *)(entry + 0x18) = 0;
    fn_802CAC54(*(int *)(entry + 0x10));
    fn_802C6C20(*(int *)(entry + 8));
    *(int *)(entry + 8) = 0;
    offset += 0x60;
    i++;
check:
    if (i < *(int *)((char *)&lbl_804C00D4 + 4)) goto loop;
    *(int *)((char *)&lbl_804C00D4 + 4) = 0;
    if (lbl_8055FAB4 != 0) {
        fn_80131818();
        lbl_8055FAB4 = 0;
    }
}
#pragma pop
void fn_802BCFB0(int *arg0) {
    int temp_r31;
    temp_r31 = *arg0;
    if (temp_r31 != 0) {
        if (temp_r31 != 0) {
            fn_802BD018((char *)temp_r31 + 8);
            fn_802BD018((char *)temp_r31 + 4);
            fn_802BD070((void *)temp_r31);
            fn_80128668((void *)temp_r31);
        }
        *arg0 = 0;
    }
}

#pragma pop

int fn_802BD0C8(void *arg0) {
    int result = 0;
    if (*(int *)((char *)arg0 + 4) != 0) {
        void **ptr = *(void ***)((char *)arg0 + 0x58);
        if (ptr != 0)
            result = *(int *)((char *)*ptr + 4);
    }
    return result;
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
            ((void (*)(void *))fn_802E317C)(strings + 0xC8);
        }
    }
}
#pragma pop

#pragma pop
void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
#pragma scheduling on
void fn_802BD414(int arg0, volatile int *arg1)
{
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result == 0)
        return;
    {
        int first = arg1[0];
        result[0] = arg1[1];
        result[2] = first;
        result[1] = 0;
        result[1] = result[1] + arg1[0];
    }
}
#pragma scheduling reset
void fn_802BD478(int arg0, volatile int *arg1)
{
  volatile int *result = (volatile int *) fn_801284F8(0xC, arg0);
  if (result != 0)
  {
    int second;
    int first = arg1[0];
    result[0] = arg1[1];
    result[2] = first;
    result[1] = 0;
    result[1] = result[1] + arg1[0];
  }
}

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD4DC(void *arg0, int arg1) {
    extern void fn_802BD69C(void *, int);
    extern void fn_802BD5B0(void *, int);
    unsigned char *p = arg0;
    char *entry;
    int offset;
    unsigned int i;
    unsigned char b7, b6, b2, b3, b0, b1, b4, b5;
    b4 = p[4];
    b7 = p[7];
    p[4] = b7;
    b5 = p[5];
    b6 = p[6];
    b0 = p[0];
    b3 = p[3];
    p[7] = b4;
    b1 = p[1];
    b2 = p[2];
    p[5] = b6;
    p[6] = b5;
    p[0] = b3;
    p[3] = b0;
    p[1] = b2;
    p[2] = b1;
    *(int *)(p + 4) = fn_802BD5A8(*(int *)(p + 4), arg1);
    i = 0;
    offset = 0;
    while (i < *(unsigned int *)p) {
        entry = *(char **)(p + 4) + offset;
        fn_802BD69C(entry + 0x20, arg1);
        fn_802BD5B0(entry + 0x28, arg1);
        fn_802BD5B0(entry + 0x30, arg1);
        offset += 0x38;
        i++;
    }
}
#pragma pop

int fn_802BD5A8(int arg0, int arg1) { return arg0 + arg1; }

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD5B0(void *arg0, int arg1) {
    extern int fn_802BD694(int, int);
    extern float lbl_80564D30;
    unsigned char *p = arg0;
    unsigned char *entry;
    register unsigned char tmp;
    float zero;
    int offset;
    unsigned int i;
    unsigned char b6, b2, b3, b0, b1, b4, b5;
    b4 = p[4]; b5 = p[5]; b6 = p[6];
    p[4] = p[7]; b0 = p[0]; b3 = p[3]; p[7] = b4;
    b1 = p[1]; b2 = p[2]; p[5] = b6; p[6] = b5;
    p[0] = b3; p[3] = b0; p[1] = b2; p[2] = b1;
    *(int *)(p + 4) = fn_802BD694(*(int *)(p + 4), arg1);
    zero = lbl_80564D30; i = 0; offset = 0;
    while (i < *(unsigned int *)p) {
        entry = *(unsigned char **)(p + 4) + offset;
        tmp = entry[4]; entry[4] = entry[5]; entry[5] = tmp;
        tmp = entry[6]; entry[6] = entry[7]; entry[7] = tmp;
        tmp = entry[8]; entry[8] = entry[9]; entry[9] = tmp;
        tmp = entry[10]; entry[10] = entry[11]; entry[11] = tmp;
        *(float *)(entry + 12) = zero;
        offset += 0x10; i++;
    }
}
#pragma pop

int fn_802BD694(int arg0, int arg1) { return arg0 + arg1; }

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802BD69C(void *arg0, int arg1) {
    unsigned char *p = arg0;
    unsigned char *entry;
    unsigned int i;
    int offset;
    unsigned char b5, b4, b1, b0, b3, b2, b6, b7;
    b4=p[4]; b7=p[7]; b5=p[5]; b6=p[6];
    p[4]=b7; b0=p[0]; b3=p[3]; p[7]=b4;
    b1=p[1]; b2=p[2]; p[5]=b6; p[6]=b5;
    p[0]=b3; p[3]=b0; p[1]=b2; p[2]=b1;
    *(int *)(p+4)=fn_802BD80C(*(int *)(p+4),arg1);
    i=0; offset=0;
    while (i < *(unsigned int *)p) {
        int j;
        entry=*(unsigned char **)(p+4)+offset+0xC;
        for (j=0;j<2;j++,entry+=0x18) {
            b4=entry[0]; b7=entry[3]; entry[0]=b7; entry[3]=b4;
            b4=entry[1]; b7=entry[2]; entry[1]=b7; entry[2]=b4;
            b4=entry[4]; b7=entry[7]; entry[4]=b7; entry[7]=b4;
            b4=entry[5]; b7=entry[6]; entry[5]=b7; entry[6]=b4;
            b4=entry[8]; b7=entry[11]; entry[8]=b7; entry[11]=b4;
            b4=entry[9]; b7=entry[10]; entry[9]=b7; entry[10]=b4;
            b4=entry[12]; b7=entry[15]; entry[12]=b7; entry[15]=b4;
            b4=entry[13]; b7=entry[14]; entry[13]=b7; entry[14]=b4;
            b4=entry[16]; b7=entry[19]; entry[16]=b7; entry[19]=b4;
            b4=entry[17]; b7=entry[18]; entry[17]=b7; entry[18]=b4;
            b4=entry[20]; b7=entry[23]; entry[20]=b7; entry[23]=b4;
            b4=entry[21]; b7=entry[22]; entry[21]=b7; entry[22]=b4;
        }
        offset+=0x44; i++;
    }
}
#pragma scheduling on
#pragma pop

int fn_802BD80C(int arg0, int arg1) { return arg0 + arg1; }

__declspec(section ".data") extern int lbl_8034AC48;
#pragma scheduling invalid_target
extern int __cntlzw(unsigned int);
void fn_802BDBA8(void) {
    char *strings = (char *)&lbl_8034AB38;
    void *object;
    int result;
    int isZero;
    fn_802C126C();
    fn_802BCBDC();
    fn_802B8AE0(strings + 0xE8, &lbl_8055FAA8);
    fn_802B8AE0(strings + 0xF4, &lbl_8055FAAC);
    result = fn_802B05E4();
    isZero = (int)((unsigned int)__cntlzw((unsigned int)result) >> 5);
    *(unsigned char *)&lbl_8055FAB0 = isZero;
    if (result == 0) {
        return;
    }
    ((int (*)(void))fn_802BD210)();
    object = fn_801284F8(8, (int)(strings + 0x104));
    if (object != 0) {
        fn_802C2914(object);
        *(void **)((char *)object + 4) = &lbl_8034AC48;
    }
    lbl_8055FABC = object;
}
#pragma scheduling on
void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

void fn_802BCF04(void);
void fn_8012C4D8(void);
void fn_802C13A4(void);
void deleteThreads__6SystemFv_802BDCA4(void **);
void fn_802BDC60(void) {
    int flag;
    fn_802BCF04();
    flag = lbl_8055FAB8;
    if (flag != 0) {
        ((int (*)(int))fn_8012C4D8)(flag);
        lbl_8055FAB8 = 0;
    }
    fn_802C13A4();
    deleteThreads__6SystemFv_802BDCA4(&lbl_8055FABC);
}

extern int lbl_8034AB38, lbl_8034AC48;
extern int lbl_8055FAA8, lbl_8055FAAC, lbl_8055FAB0;
extern void *lbl_8055FABC;
#pragma push
#pragma cplusplus on
extern "C" void deleteThreads__6SystemFv_802BDCA4(void **arg0) {
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
    ThreadObject *p = *(ThreadObject **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
        *(ThreadObject **)arg0 = 0;
    }
}
#pragma cplusplus reset
#pragma pop
void fn_802C2930(void*, unsigned int);
#pragma push
#pragma scheduling invalid_target
void fn_802BD018(void *arg0) {
    void *obj = *(void **)arg0;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)arg0 = 0;
    }
}

int fn_802BD070(void *arg0) {
    void *obj = *(void **)arg0;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)arg0 = 0;
    }
}

#pragma pop
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802C2930((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_802BDD54(void) {
    fn_802BD814();
}

void fn_802BDD58(void) {
    fn_801E7E18();
    fn_802C173C();
    if (fn_8020403C() != 0) fn_802BD814();
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
void fn_802C8D74(void);
void fn_802DBECC(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802BDD8C(float arg0) {
    float out[12];
    float mtx[9];
    int i, j;
    fn_802DBE4C();
    if (fn_8020403C() != 0) {
        float one = lbl_80564D18;
        float lim = lbl_80564D14;
        float sq, den;
        float half = lbl_80564D4C;
        lbl_8055FAAC = 0;
        lbl_8055FAA8 = 0;
        for (i = 0; i < *(int *)((char *)&lbl_804C00D4 + 4); i++) {
            char *e = *(char **)&lbl_804C00D4 + i * 0x60;
            int *obj = *(int **)(e + 0x58);
            if (obj != 0) {
                int *data = (int *)obj[1];
                int *pts = (int *)obj[0];
                if (*(int *)(e + 0x24) <= 10) {
                    char *cam;
                    fn_802C28C0();
                    fn_802C8BD0();
                    fn_802DC71C(*(int *)(e + 0x1c), *(int *)(e + 0x20));
                    sq = arg0 * arg0;
                    den = sq - (arg0 - half) * (arg0 - half);
                    fn_801F1C24(mtx);
                    cam = fn_801E8718(-1) + 0x24;
                    for (j = 0; j < data[1]; j++) {
                        char *r = (char *)data[0] + j * 0x10;
                        {
                            int cond = (*(float *)(r + 0xc) >= lim);
                            if (cond) {
                                int idx = *(short *)(r + 0xa);
                                int h = *(int *)(e + 0x1c);
                                for (; idx < *(short *)(r + 0xa) + *(short *)(r + 8); idx++) {
                                    char *p = (char *)pts[0] + idx * 0x44;
                                    float d = PSVECSquareDistance(p + 0x30, cam);
                                    if (d <= sq) {
                                        float f = (sq - d) / den;
                                        float s = *(float *)(p + 0x1c);
                                        float m0, m1, m2, m3, m4, m5, m6, m7, m8;
                                        if (one < f) f = one;
                                        m0 = mtx[0] * s;
                                        m1 = mtx[1] * s;
                                        m2 = mtx[2] * s;
                                        m3 = mtx[3] * s;
                                        m4 = mtx[4] * s;
                                        m5 = mtx[5] * s;
                                        m6 = mtx[6] * s;
                                        m7 = mtx[7] * s;
                                        m8 = mtx[8] * s;
                                        out[0] = m0;
                                        out[1] = m1;
                                        out[2] = m2;
                                        out[3] = m3;
                                        out[4] = m4;
                                        out[5] = m5;
                                        out[6] = m6;
                                        out[7] = m7;
                                        out[8] = m8;
                                        out[9] = *(float *)(p + 0x30);
                                        out[10] = *(float *)(p + 0x34);
                                        out[11] = *(float *)(p + 0x38);
                                        fn_802DCAE4(h, out, f);
                                    }
                                }
                            }
                        }
                    }
                    fn_802DC8B4();
                    fn_802C8D74();
                }
            }
        }
        fn_802DBECC();
    }
}
#pragma pop
void fn_802BDFBC(void *arg0, int arg1, float farg0) {
    float value = farg0;
    void *node;
    if (arg1 < 8) {
        value = lbl_80564D18;
    } else if (arg1 == 8) {
        value = farg0;
    } else {
        value = lbl_80564D14;
    }
    node = *(void **)((char *)arg0 + 4);
    while (node != 0) {
        *(float *)((char *)node + 0xC) = value;
        node = *(void **)node;
    }
}

extern float lbl_80564D14;
extern float lbl_80564D18;
void fn_802BAF98(void *, int);
void fn_802BDFF4(void *arg0, int arg1) {
    arg0 = *(void **)((char *)arg0 - 8);
    if (arg0 != 0) {
        fn_802BAF98(arg0, arg1);
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
    register float normZ;
    register float normX;
    int coordX, coordZ, baseX, baseZ;
    int zCell, xCell, zOffset, xOffset;
    void *cell, *node, *obj, *map, *mesh;
    short ix, iz;
    float dx, dz;
    worldX = *(volatile float *)arg0;
    scale = lbl_80564D10;
    xOffset = -0x80;
    worldZ = *(volatile float *)((char *)arg0 + 8);
    normX = worldX / scale;
    weight = lbl_80564D2C;
    normZ = worldZ / scale;
    coordZ = (short)(int)normZ;
    coordX = (short)(int)normX;
    baseX = (short)((coordX / 0x80) * 0x80 + 0x40);
    baseZ = (short)((coordZ / 0x80) * 0x80 + 0x40);
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
                    arg1(*(int *)((char *)obj + 0x20), *(int *)*(void **)map + ix * 0x44 + 0x30, 0x44, iz, dx * weight, dz, dx);
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
int fn_802BE1D8(void) {
    int offset;
    int sum;
    int i;
    sum = 0;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        sum += fn_802BD0C8(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
    }
    return sum;
}
#pragma pop
void fn_802BE244(void) {
    int offset = 0;
    int i = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        fn_802BD0F4(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
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
extern "C" void fn_802BD814(void) {
    float constant18 = lbl_80564D18;
    float constant14 = lbl_80564D14;
    float constant40 = lbl_80564D40;
    float constant44 = lbl_80564D44;
    float constant48 = lbl_80564D48;
    float constant30 = lbl_80564D30;
    float constant3C = lbl_80564D3C;
    float constant34 = lbl_80564D34;
    float constant38 = lbl_80564D38;
    float matrix[9];
    float transform[12];
    DrawEntriesBD814 *entries = (DrawEntriesBD814 *)&lbl_804C00D4;
    int entryIndex;
    lbl_8055FAAC = 0;
    lbl_8055FAA8 = 0;
    for (entryIndex = 0; entryIndex < entries->count; ++entryIndex) {
        DrawEntryBD814 *entry = &entries->data[entryIndex];
        DrawDataBD814 *data = entry->data;
        DrawGroupsBD814 *groups;
        DrawInstancesBD814 *instances;
        int groupIndex;
        if (!data) continue;
        groups = data->firstPass;
        instances = data->instances;
        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC71C(entry->firstHandle, entry->firstState);
        for (groupIndex = 0; groupIndex < groups->count; ++groupIndex) {
            DrawGroupBD814 *group = &groups->data[groupIndex];
            float t = (group->time - constant34) / constant38;
            float alpha;
            if (constant18 < t) t = constant18;
            t = t > constant14 ? t : constant14;
            alpha = constant14 + t * constant18;
            if (group->time >= constant14 && alpha > constant3C) {
                int index;
                int handle = entry->firstHandle;
                int cost = entry->firstCost;
                for (index = group->first; index < group->first + group->count; ++index) {
                    DrawInstanceBD814 *instance = &instances->data[index];
                    if (instance->anchor && instance->position[1] > constant40)
                        instance->position[1] = instance->anchor->height + instance->heightOffset;
                    fn_802DCAE4(handle, instance->transform, alpha);
                    ++lbl_8055FAA8;
                    lbl_8055FAAC += cost;
                }
                group->time = constant30;
            }
        }
        fn_802DC8B4();
        fn_802C8D74();
        groups = entry->data->secondPass;
        instances = entry->data->instances;
        if (entry->secondCost <= 10) {
            fn_802C28C0();
            fn_802C8BD0();
            fn_802DC71C(entry->secondHandle, entry->secondState);
            fn_801F1C24(matrix);
            for (groupIndex = 0; groupIndex < groups->count; ++groupIndex) {
                DrawGroupBD814 *group = &groups->data[groupIndex];
                if (group->time >= constant14) {
                    float t = (group->time - constant44) / constant48;
                    float alpha;
                    if (constant18 < t) t = constant18;
                    t = t > constant14 ? t : constant14;
                    alpha = constant18 + t * constant30;
                    if (alpha > constant3C) {
                        int index;
                        int handle = entry->secondHandle;
                        int cost = entry->secondCost;
                        for (index = group->first; index < group->first + group->count; ++index) {
                            DrawInstanceBD814 *instance = &instances->data[index];
                            float scale;
                            if (instance->anchor && instance->position[1] > constant40)
                                instance->position[1] = instance->anchor->height + instance->heightOffset;
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
            fn_802C8D74();
        }
    }
}
#pragma pop

#pragma cplusplus reset
