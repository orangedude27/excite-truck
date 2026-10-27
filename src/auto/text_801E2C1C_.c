// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <math.h>
#include "types.h"

typedef struct {
    f32 x[9];
} Mat3x3;

extern f32 lbl_80562CE8;
extern f32 lbl_80562CEC;
extern void fn_801E35D4(void *dst, void *src);
extern void fn_801E3284(void *out, void *in, s32 arg2);
extern void fn_802C744C(s32 arg0, void *out);
extern int sscanf(const char *, const char *, ...);
extern int stricmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern char lbl_8055AEB4;
extern const char lbl_8055AEB0[];

void fn_8012A260(void*, unsigned int);
void fn_80128668(void*);
extern char lbl_803398D8[];
extern char lbl_80339904[];
extern void *lbl_8055EA50;
extern void *fn_801284F8(s32, void *);
extern void fn_8012A13C(void *, s32, s32);
#pragma push
#pragma small_data off
#pragma pop
int fn_801E2C1C(void *arg0, int arg1, void **arg2, void **arg3) {
    int table = fn_802C6C34();
    int count = *(int *)(table + 0x10);
    int offset = 0;
    while (count > 0) {
        int entry = *(int *)(*(int *)(table + 0x14) + offset);
        if (*(unsigned int *)entry == 0x4D524A54 && arg1 >= 0 && arg1 < *(int *)(entry + 8)) {
            int item = entry + arg1 * 0x50;
            *arg2 = (void *)(item + 0xC);
            *arg3 = (void *)(item + 0x2C);
            return 1;
        }
        offset += 4;
        count--;
    }
    return 0;
}

#pragma push
#pragma small_data on
extern const char lbl_8055AEB0[3];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
int fn_801E2CCC(void *arg0, const char *arg1, void **arg2) {
    void *value;
    void *name;
    int buffer[16];
    BOOL hasSpace;
    int index;
    register int zero;

    zero = 0;
    value = (void *)zero;
    name = (void *)zero;
    hasSpace = strchr(arg1, ' ') != 0;
    for (index = 0; fn_801E2C1C(arg0, index, &name, &value) != 0; index++) {
        buffer[0] = zero;
        buffer[1] = zero;
        buffer[2] = zero;
        buffer[3] = zero;
        buffer[4] = zero;
        buffer[5] = zero;
        buffer[6] = zero;
        buffer[7] = zero;
        buffer[8] = zero;
        buffer[9] = zero;
        buffer[10] = zero;
        buffer[11] = zero;
        buffer[12] = zero;
        buffer[13] = zero;
        buffer[14] = zero;
        buffer[15] = zero;
        if (!hasSpace)
            sscanf((const char *)name, lbl_8055AEB0, (char *)buffer);
        else
            strcpy((char *)buffer, (const char *)name);
        if (stricmp((char *)buffer, arg1) == 0) {
            *arg2 = value;
            return 1;
        }
    }
    *arg2 = 0;
    return 0;
}
#pragma use_lmw_stmw reset
#pragma scheduling on

#pragma push
#pragma small_data on
#pragma use_lmw_stmw off
s32 fn_801E2DEC(s32 arg0, s32 arg1, s32 arg2) {
    struct Group {
        int magic;
        int itemCount;
    };
    struct Archive {
        char pad[0x10];
        int groupCount;
        int groups;
    } *archive;
    struct Group *group;
    char *item;
    char name[32];
    char valueBuf[32];
    int groupIndex;
    int groupOffset;
    int index;
    register int zero;

    zero = 0;
    archive = (struct Archive *)fn_802C6C34();
    groupIndex = zero;
    groupOffset = zero;
    while (groupIndex < archive->groupCount) {
        group = (struct Group *)(*(int *)(archive->groups + groupOffset));
        if (group->magic == 0x4D524A54) {
            item = (char *)group + 0xC;
            index = zero;
            while (index < group->itemCount) {
                ((int *)valueBuf)[0] = zero; ((int *)valueBuf)[1] = zero; ((int *)valueBuf)[2] = zero;
                ((int *)valueBuf)[3] = zero; ((int *)valueBuf)[4] = zero; ((int *)valueBuf)[5] = zero;
                ((int *)valueBuf)[6] = zero;
                ((int *)name)[0] = zero; ((int *)name)[1] = zero; ((int *)name)[2] = zero;
                ((int *)name)[3] = zero; ((int *)name)[4] = zero; ((int *)name)[5] = zero;
                ((int *)name)[6] = zero;
                if (sscanf(item, (const char *)&lbl_8055AEB4, name, valueBuf) >= 1 &&
                    stricmp(name, (const char *)arg0) == 0) {
                    if (arg1 != 0) {
                        strcpy((char *)arg1, valueBuf);
                    }
                    return (s32)group + index * 0x50 + 0xC;
                }
                item += 0x50;
                index++;
            }
        }
        groupOffset += 4;
        groupIndex++;
    }
    return 0;
}
#pragma pop

#pragma pop
void fn_801E2F00(void) {
    void *p = fn_801284F8(0x20, lbl_803398D8);
    if (p != 0) {
        ((void (*)(void *, void *, s32, s32))fn_8012A13C)(p, lbl_803398D8, 0x128, 0x68);
        *(void **)p = lbl_80339904;
    }
    lbl_8055EA50 = p;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801E2F68(void) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055EA50 != 0) {
        ((Obj*)lbl_8055EA50)->destroy(1);
    }
    lbl_8055EA50 = 0;
}
#pragma cplusplus reset
#pragma pop
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801E2FAC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_8012A260((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma small_data off
void fn_801E31D8(s32 *arg0) {
    *(s32 **)((u8 *)fn_801E3004(*arg0) + 4) = arg0;
}

s32 fn_801E320C(s32 arg0, s32 arg1) {
    extern s32 fn_801E2DEC(s32, s32, s32);
    return fn_801E2DEC(arg0, arg1, 0) != 0;
}

void fn_801E323C(s32 *arg0) {
    s32 value = *arg0;
    if (value != -1) {
        fn_802C6CF8(value);
    }
    fn_8012A364((s32)lbl_8055EA50, arg0);
}

#pragma scheduling invalid_target
void fn_801E3284(void *out, void *in, s32 arg2) {
    struct Pair { s32 x[2]; };
    struct Locals {
        union {
            s32 sp8[12];
            struct { s32 pad[9]; s32 sp2c[3]; } overlap;
        } result;
        s32 sp38[9];
        s32 sp5c[3];
        s32 sp68[12];
    } local;
    if (*(void **)((u8 *)in + 4) != 0) {
        fn_801E3284(local.sp68, *(void **)((u8 *)in + 4), arg2);
    } else {
        s32 *src = (s32 *)arg2;
        register s32 a11;
        register s32 a10;
        register s32 a9;
        register s32 a8;
        register s32 a7;
        register s32 a6;
        register s32 a5;
        register s32 a4;
        register s32 a3;
        register s32 a2;
        register s32 a0;
        register s32 a1;
        a0=src[0]; a1=src[11]; a2=src[1]; a3=src[2];
        a4=src[3]; a5=src[4]; a6=src[5]; a7=src[6];
        a8=src[7]; a9=src[8]; a10=src[9]; a11=src[10];
        local.sp68[0]=a0; local.sp68[1]=a2; local.sp68[2]=a3; local.sp68[3]=a4;
        local.sp68[4]=a5; local.sp68[5]=a6; local.sp68[6]=a7; local.sp68[7]=a8;
        local.sp68[8]=a9; local.sp68[9]=a10; local.sp68[10]=a11; local.sp68[11]=a1;
    }
    fn_801BFD34(local.sp5c, (u8 *)in + 0x5C, local.sp68);
    fn_80015B20(local.sp38, (u8 *)in + 0x38, local.sp68);
    fn_801BFD34(local.result.overlap.sp2c, (u8 *)in + 0x2C, local.sp38);
    fn_80015B20(local.result.sp8, (u8 *)in + 8, local.sp38);
    *(struct Pair *)((u8 *)out + 0x00) = *(struct Pair *)((u8 *)local.result.sp8 + 0x00);
    *(struct Pair *)((u8 *)out + 0x08) = *(struct Pair *)((u8 *)local.result.sp8 + 0x08);
    *(struct Pair *)((u8 *)out + 0x10) = *(struct Pair *)((u8 *)local.result.sp8 + 0x10);
    *(struct Pair *)((u8 *)out + 0x18) = *(struct Pair *)((u8 *)local.result.sp8 + 0x18);
    ((s32 *)out)[8] = local.result.sp8[8];
    *(struct Pair *)((u8 *)out + 0x24) = *(struct Pair *)((u8 *)local.result.sp8 + 0x24);
    ((s32 *)out)[11] = local.result.sp8[11];
}
#pragma scheduling on
void fn_801E33E4(void *arg0, void *arg1) {
    f32 sp[12];
    sp[0] = 1.0f;
    sp[1] = 0.0f;
    sp[2] = 0.0f;
    sp[3] = 0.0f;
    sp[4] = 1.0f;
    sp[5] = 0.0f;
    sp[6] = 0.0f;
    sp[7] = 0.0f;
    sp[8] = 1.0f;
    sp[9] = 0.0f;
    sp[10] = 0.0f;
    sp[11] = 0.0f;
    fn_801E3284(arg0, arg1, (s32)sp);
}
void fn_801E3440(void* arg0) {
    f32 sp[12];
    ((void (*)(void*))fn_801E3284)(sp);
    *(f32*)((u8*)arg0 + 0) = sp[9];
    *(f32*)((u8*)arg0 + 4) = sp[10];
    *(f32*)((u8*)arg0 + 8) = sp[11];
}

#pragma push
#pragma small_data off
void fn_801E3488(void *arg0, void *arg1) {
    f32 sp[12];
    sp[0] = 1.0f;
    sp[1] = 0.0f;
    sp[2] = 0.0f;
    sp[3] = 0.0f;
    sp[4] = 1.0f;
    sp[5] = 0.0f;
    sp[6] = 0.0f;
    sp[7] = 0.0f;
    sp[8] = 1.0f;
    sp[9] = 0.0f;
    sp[10] = 0.0f;
    sp[11] = 0.0f;
    ((void (*)(void *, void *, f32 *))fn_801E3440)(arg0, arg1, sp);
}

#pragma scheduling invalid_target
void fn_801E34E4(s32 *arg0, s32 arg1) {
    s32 sp8[12];
    register s32 sentinel = *arg0;
    if (sentinel != -1) {
        fn_801E3284(&sp8[0], arg0, arg1);
        fn_802C744C(*arg0, &sp8[0]);
    }
}
#pragma scheduling on
s32 fn_801E3534(s32 *arg0) {
    return *arg0;
}

void fn_801E353C(s32 arg0, f32 angle) {
    Mat3x3 m;
    f32 c;
    f32 s;

    c = (f32)cos(angle);
    s = (f32)sin(angle);
    m.x[0] = c;
    m.x[1] = s;
    m.x[2] = lbl_80562CEC;
    m.x[3] = -s;
    m.x[4] = c;
    m.x[5] = lbl_80562CEC;
    m.x[6] = lbl_80562CEC;
    m.x[7] = lbl_80562CEC;
    m.x[8] = lbl_80562CE8;
    fn_801E35D4((void *)arg0, &m);
}

void fn_801E35D4(void *arg0, void *arg1) {
    f32 val = lbl_80562CEC;
    s32 *src = (s32 *)arg1;
    s32 *dst = (s32 *)arg0;
    f32 *fdst = (f32 *)((u8 *)arg0 + 0x2C);
    s32 i, h, g, f, e, d, c, b, a;
    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    e = src[4];
    f = src[5];
    g = src[6];
    h = src[7];
    i = src[8];
    fdst[0] = val;
    fdst[1] = val;
    fdst[2] = val;
    dst[2] = a;
    dst[3] = b;
    dst[4] = c;
    dst[5] = d;
    dst[6] = e;
    dst[7] = f;
    dst[8] = g;
    dst[9] = h;
    dst[10] = i;
}

#pragma push
#pragma small_data off
s32 fn_801E3630(s32 arg0) { return arg0 + 0x5C; }

