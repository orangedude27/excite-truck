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
extern char lbl_8055AEB4[];
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
#pragma scheduling on

#pragma push
#pragma small_data on
s32 fn_801E2DEC(s32 arg0, s32 arg1, s32 arg2) {
    struct Group {
        int itemCount;
        int magic;
    };
    struct Archive {
        char pad[0x10];
        int groupCount;
        int groups;
    } *archive;
    struct Group *group;
    char *item;
    int name[8];
    int valueBuf[8];
    int groupIndex;
    int groupOffset;
    int index;

    archive = (struct Archive *)fn_802C6C34();
    groupIndex = 0;
    groupOffset = 0;
    while (groupIndex < archive->groupCount) {
        group = (struct Group *)(*(int *)(archive->groups + groupOffset));
        if (group->magic == 0x4D524A54) {
            item = (char *)group + 0xC;
            index = 0;
            while (index < group->itemCount) {
                name[0] = 0; name[1] = 0; name[2] = 0; name[3] = 0;
                name[4] = 0; name[5] = 0; name[6] = 0; name[7] = 0;
                valueBuf[0] = 0; valueBuf[1] = 0; valueBuf[2] = 0; valueBuf[3] = 0;
                valueBuf[4] = 0; valueBuf[5] = 0; valueBuf[6] = 0; valueBuf[7] = 0;
                if (sscanf(item, lbl_8055AEB4, name, valueBuf) >= 1 &&
                    stricmp((const char *)name, (const char *)arg0) == 0) {
                    if (arg1 != 0) {
                        strcpy((char *)arg1, (char *)valueBuf);
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

void fn_801E3284(void *out, void *in, s32 arg2) {
    s32 sp68[12];
    s32 sp5C[3];
    s32 sp38[9];
    s32 sp2C[3];
    s32 sp8[12];
    s32 *src = (s32 *)arg2;
    if (*(void **)((u8 *)in + 4) != 0) {
        fn_801E3284(sp68, *(void **)((u8 *)in + 4), arg2);
    } else {
        sp68[0]=src[0]; sp68[1]=src[1]; sp68[2]=src[2]; sp68[3]=src[3];
        sp68[4]=src[4]; sp68[5]=src[5]; sp68[6]=src[6]; sp68[7]=src[7];
        sp68[8]=src[8]; sp68[9]=src[9]; sp68[10]=src[10]; sp68[11]=src[11];
    }
    fn_801BFD34(sp5C, (u8 *)in + 0x5C, sp68);
    fn_80015B20(sp38, (u8 *)in + 0x38, sp68);
    fn_801BFD34(sp2C, (u8 *)in + 0x2C, sp38);
    fn_80015B20(sp8, (u8 *)in + 8, sp38);
    ((s32*)out)[0]=sp8[0]; ((s32*)out)[1]=sp8[1]; ((s32*)out)[2]=sp8[2]; ((s32*)out)[3]=sp8[3];
    ((s32*)out)[4]=sp8[4]; ((s32*)out)[5]=sp8[5]; ((s32*)out)[6]=sp8[6]; ((s32*)out)[7]=sp8[7];
    ((s32*)out)[8]=sp8[8]; ((s32*)out)[9]=sp8[9]; ((s32*)out)[10]=sp8[10]; ((s32*)out)[11]=sp8[11];
}

#pragma push
#pragma small_data off
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

