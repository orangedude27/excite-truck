// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma use_lmw_stmw off
#include <revolution/MTX/mtxtypes.h>

extern float lbl_80562B54;
void fn_801DA198(int, float);
#pragma cplusplus on
struct Obj801DACA0 {
    virtual float f0();
    virtual float get();
};
struct Ctx801DACA0 {
    void *vtable;
    void **items;
    int count;
    char padC[4];
    char info[16];
};
#pragma cplusplus reset
extern void *fn_80128668(void *);
extern void fn_80128670(void *);
extern int lbl_80339288[];
extern float fn_801DA6B8(int);
extern void *fn_801284F8(int, void *);
extern void fn_801D0DDC(void *);
extern int lbl_803381C0[];
extern int lbl_80339258[];
extern void *lbl_8055AD98;
extern void *lbl_8055E984;

#pragma push
#pragma scheduling invalid_target
/* Allocates and initializes the global PathMan instance (0x580C bytes, "pathman" tag),
 * sets up nw4r effect/PathMan vtables, registers it, and clears its entry count. */
void fn_801DA6EC(void) {
#define gPathManInstance lbl_8055E984
#define sPathManAllocTag lbl_8055AD98
#define sNw4rEffectVTable_Base lbl_803381C0
#define sPathManVTable lbl_80339258
#define AllocWithTag fn_801284F8
#define nw4rRegisterEffect fn_801D0DDC
    void *pathMan;
    void **vtable;
    pathMan = AllocWithTag(0x580C, &sPathManAllocTag);
    if (pathMan != 0) {
        *(void **)pathMan = sNw4rEffectVTable_Base;
        nw4rRegisterEffect(pathMan);
        vtable = (void **)sPathManVTable;
        *(void **)pathMan = vtable;
        vtable = (void **)((char *)vtable + 0x1C);
        *(void **)((char *)pathMan + 4) = vtable;
        gPathManInstance = pathMan;
        *(int *)((char *)pathMan + 0x5808) = 0;
    }
#undef gPathManInstance
#undef sPathManAllocTag
#undef sNw4rEffectVTable_Base
#undef sPathManVTable
#undef AllocWithTag
#undef nw4rRegisterEffect
}
#pragma pop
extern void *fn_801D9F28(void);
extern int fn_801D9CC4(int);
extern void fn_801D9F84(int, int);
extern char *fn_801DA03C(int, int);
extern float fn_801DD88C(int, int, int);
extern int fn_8029F458(unsigned char *, int);
extern char lbl_8055ADA0;
extern char lbl_8055ADA8;
extern float lbl_80562B50;
#pragma push
#pragma scheduling invalid_target
void fn_801DA758(int arg0, unsigned char *arg1, int arg2) {
    register unsigned char *name = arg1;
    register int value = arg0;
    register int category = arg2;
    register char *record;
    register unsigned char *src;
    register unsigned char *dst;
    char *space;
    unsigned int zero[3];
    int count;
    int i;
    int entryAddress;
    char *text;
    unsigned char c;
    float result;

    space = (char *)lbl_8055E984;
    i = *(int *)(space + 0x5808);
    entryAddress = (int)space + i * 0x2C;
    *(int *)(space + 0x5808) = i + 1;
    record = (char *)(entryAddress + 8);

    count = 0x10;
    src = name;
    dst = (unsigned char *)record;
    while (--count > 0) {
        dst = dst;
    }
    dst[-1] = 0;
    do {
        c = *src++;
        *dst++ = c;
    } while ((signed char)c != 0);

    *(int *)(record + 0x20) = value;
    if (fn_801284F8(0x10, &lbl_8055ADA0) != 0)
        *(int *)(record + 0x28) = (int)fn_801D9F28();
    *(int *)(record + 0x24) = fn_801D9CC4(category);
    fn_801D9F84(*(int *)(record + 0x28), *(int *)(record + 0x24));

    record[0x19] = 0;
    i = 0;
    for (;;) {
        text = fn_801DA03C(*(int *)(record + 0x28), i++);
        if (text == 0)
            break;
        if (strstr(text, &lbl_8055ADA8) != 0) {
            record[0x19] = 1;
            break;
        }
    }
    record[0x18] = record[0x19];
    if ((unsigned char)record[0x19] != 0) {
        *(float *)(record + 0x1C) = lbl_80562B50;
        record[0x10] = 0;
    } else {
        zero[0] = 0;
        zero[2] = 0;
        zero[1] = 0;
        result = ((float (*)(void))fn_801DD88C)();
        *(float *)(record + 0x14) = (*(float *)&zero[1]) - result;
        goto finished;
    }
    *(float *)(record + 0x14) = lbl_80562B54;
finished:
    fn_8029F458(name, value);
}
#pragma pop
extern int fn_801D9FC4(char **, const char *);
extern void *fn_8012850C(int, void *);
extern int strcmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055ADB0[];
extern char lbl_80339240[];
extern char lbl_8033924C[];
void *fn_801DA8C8(const char *arg0, const char *arg1) {
#pragma scheduling invalid_target
    char *stack[512];
    void *space;
    const char *name;
    const char *text;
    char *entry;
    char *result;
    int count;
    int off;
    int i;
    int matchAll;

    space = lbl_8055E984;
    name = arg0;
    text = arg1;
    count = 0;
    off = 0;
    result = 0;
    matchAll = strcmp(name, lbl_8055ADB0) == 0;
    entry = (char *)space + 8;
    for (i = 0; i < *(int *)((char *)space + 0x5808); i++) {
        if (matchAll == 0) {
            if (strcmp(entry, name) != 0) goto next;
        }
        if (fn_801D9FC4((char **)*(void **)((char *)entry + 0x28), text) != 0) {
            *(char **)((char *)stack + off) = entry;
            count++;
            off += 4;
        }
    next:
        entry += 0x2C;
    }
    if (count > 0) {
        char *dst;
        int len;
        unsigned char c;
        unsigned char *src;
        result = fn_801284F8(0x20, lbl_80339240);
        if (result != 0) {
            *(void **)result = lbl_80339288;
            dst = (char *)result + 0x10;
            len = 0x10;
            *(int *)((char *)result + 0xC) = count;
            for (; --len > 0;) {
            }
            dst[-1] = 0;
            src = (unsigned char *)text;
            do {
                c = *src++;
                *dst++ = c;
            } while ((signed char)c != 0);
            *(int *)((char *)result + 8) = 0;
            *(void **)((char *)result + 4) = (void *)fn_8012850C(*(int *)((char *)result + 0xC) * 4, lbl_8033924C);
            for (i = 0; i < count; i++) {
                void **arr;
                int pos;
                arr = *(void ***)((char *)result + 4);
                pos = *(int *)((char *)result + 8);
                *(void **)((char *)arr + pos * 4) = stack[i];
                pos += 1;
                *(int *)((char *)result + 8) = pos;
            }
        }
    }
    return result;
}

#pragma scheduling on
#pragma push
#pragma use_lmw_stmw off
#pragma pop
/* CollisionSpace::~CollisionSpace (scalars deleting): restore vtable, free owned buffer, and optionally delete. */
void *__dt__14CollisionSpaceFv_801DAB70(void *this_, int flag) {
    if (this_ != 0) {
        *(void **)this_ = lbl_80339288;
        fn_80128670(*(void **)((char *)this_ + 4));
        if (flag > 0)
            fn_80128668(this_);
    }
    return this_;
}

#pragma scheduling invalid_target
float fn_801DABD4(void *arg0) {
    float value;
    float max = lbl_80562B54;
    register int i = 0;
    register int offset = 0;

    goto check;
loop:
    value = fn_801DA6B8(*(int *)((char *)(*(void ***)((char *)arg0 + 4))[offset / 4] + 0x28));
    if (max <= value)
        max = value;
    i++;
    offset += 4;
check:
    if (i < *(int *)((char *)arg0 + 8))
        goto loop;
    return max;
}
#pragma scheduling on
float fn_801DAC5C(void *arg0)
{
    /* Returns the maximum float value at offset +0xC of each item's +0x28 data, or 0.0 if there are no items. */
    int itemCount = *(int *)((char *)arg0 + 8);
    int itemIndex;
    float maxValue = lbl_80562B54;

    for (itemIndex = 0; itemIndex < itemCount; itemIndex++) {
        void **items = *(void ***)((char *)arg0 + 4);
        void *item = items[itemIndex];
        void *itemData = *(void **)((char *)item + 0x28);
        float value = *(float *)((char *)itemData + 0xC);

        maxValue = (maxValue > value) ? maxValue : value;
    }

    return maxValue;
}
#pragma scheduling on
extern void fn_801DA064(int, void *);
extern void fn_801DA198(int, float);
extern void fn_802E30C8(char *, int, void *);
extern char lbl_803392F0[];
#pragma scheduling invalid_target
#pragma push
#pragma processor 750
void fn_801DACA0(void *arg0, float arg1) {
    float value;
    int offset;
    int count;
    void *entry;
    struct Ctx801DACA0 *ctx;

    value = lbl_80562B54;
    if (arg1 < value)
        value = ((struct Obj801DACA0 *)arg0)->get();
    ctx = (struct Ctx801DACA0 *)arg0;

    count = 0;
    offset = 0;
    while (count < ctx->count) {
        entry = *(void **)((char *)ctx->items + offset);
        if (*((unsigned char *)entry + 0x18) != 0)
            ((void (*)(char *, ...))fn_802E30C8)((char *)lbl_803392F0, count, ctx->info);
        *((unsigned char *)entry + 0x18) = 1;
        *((float *)((char *)entry + 0x1C)) = arg1;
        fn_801DA064(*(int *)((char *)entry + 0x28), ctx->info);
        fn_801DA198(*(int *)((char *)entry + 0x28), value);
        offset += 4;
        count += 1;
    }
}
#pragma scheduling on
/* Return 1 only if none of the context's items have the active flag (+0x18) set. */
int fn_801DAD7C(void *ctx) {
    int count = *(int *)((char *)ctx + 8);
    int index;
    for (index = 0; index < count; index++) {
        void **items = *(void ***)((char *)ctx + 4);
        if (*((unsigned char *)items[index] + 0x18) != 0) {
            return 0;
        }
    }
    return 1;
}
#pragma scheduling on
void fn_801DADBC(void *arg0) {
    register int *object = (int *)arg0;
    register int byteOffset = 0;
    register int index = 0;
    goto check;
loop:
    fn_801DA198(*(int *)(*(int *)((unsigned char *)object[1] + byteOffset) + 0x28), lbl_80562B54);
    byteOffset += 4;
    index++;
check:
    if (index < object[2]) goto loop;
}
#pragma scheduling reset
extern void fn_801D9F44(void *, int);
extern void fn_801D9F24(void *);
extern void fn_801D0DFC(void *);
#pragma scheduling off
void *fn_801DAE28(void *arg0, int arg1) {
    #pragma scheduling invalid_target
    unsigned char *entry;
    int i;
    if (arg0 != 0) {
        void *base = lbl_80339258;
        *(void **)arg0 = base;
        *(void **)((char *)arg0 + 4) = (char *)base + 0x1C;
        entry = (unsigned char *)arg0 + 8;
        i = 0;
        lbl_8055E984 = (void *)0;
        while (i < *(int *)((char *)arg0 + 0x5808)) {
            fn_801D9F44(*(void **)(entry + 0x28), 1);
            fn_801D9F24(*(void **)(entry + 0x24));
            entry += 0x2C;
            i++;
        }
        if (arg0 != 0) {
            *(void **)arg0 = lbl_803381C0;
            fn_801D0DFC(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
void fn_801DAEF4(void) {

}

void fn_801DAEF8(void) {

}

/* Copies each entry's pending flag to its active flag and resets its timer. */
void fn_801DAEFC(void *container) {
    unsigned char *entry = (unsigned char *)container + 8;
    int index;
    for (index = 0; index < *(int *)((char *)container + 0x5808); index++) {
        unsigned char flag = *(volatile unsigned char *)(entry + 0x19);
        float value = *(volatile float *)&lbl_80562B54;
        *(volatile unsigned char *)(entry + 0x18) = flag;
        fn_801DA198(*(int *)(entry + 0x28), value);
        entry += 0x2C;
    }
}

extern float lbl_80562B58, lbl_80562B5C;
extern unsigned char lbl_8055E980;
extern char lbl_8055ADB4;
extern char lbl_80339318[];
extern void fn_801DA0EC(int, float);
extern int fn_801DA294(int, void *, float *, float *);
extern void fn_8017CFFC(int, void *, float *, float *);
extern float fn_801EA0E8(float, float);
extern int fn_801DA648(int);
extern int fn_801DA688(int);
#pragma push
#pragma scheduling invalid_target
void fn_801DAF68(void *space) {
    // Advance each active pathman slot: step its timer, sample/scale its bounds, write back, retire finished slots.
    register void *base;
    register unsigned char *slot;
    register int i;
    register f32 step;
    register f32 limit;
    register f32 extent;
    Mtx transform;
    Vec first;
    Vec second;

    extent = lbl_80562B5C;
    base = space;
    step = lbl_80562B58;
    slot = (unsigned char *)base + 8;
    limit = lbl_80562B54;
    i = 0;
    for (; i < *(int *)((char *)base + 0x5808); slot += 0x2C, i++) {
        if (slot[0x18] == 0 && slot[0x10] == 0)
            continue;
        if (slot[0x18] != 0)
            fn_801DA0EC(*(int *)(slot + 0x28), step * *(float *)(slot + 0x1C));
        if (fn_801DA294(*(int *)(slot + 0x28), transform, &first.x, &second.x) != 0) {
            first.x *= extent;
            first.y *= extent;
            first.z *= extent;
            second.x *= extent;
            second.y *= extent;
            second.z *= extent;
            if (slot[0x10] != 0)
                transform[2][2] = *(float *)(slot + 0x14) + fn_801EA0E8(transform[2][1], transform[2][3]);
            fn_8017CFFC(*(int *)(slot + 0x20), transform, &first.x, &second.x);
        } else if (lbl_8055E980 == 0) {
            lbl_8055E980 = 1;
            ((void (*)(char *, ...))fn_802E30C8)(&lbl_8055ADB4, lbl_80339318);
        }
        if (*(float *)(slot + 0x1C) >= limit) {
            if (fn_801DA648(*(int *)(slot + 0x28)) != 0) {
                if (slot[0x19] != 0)
                    fn_801DA198(*(int *)(slot + 0x28), lbl_80562B54);
                else
                    slot[0x18] = 0;
            }
        } else if (fn_801DA688(*(int *)(slot + 0x28)) != 0 && slot[0x19] == 0) {
            slot[0x18] = 0;
        }
    }
}

extern int sscanf(const char *, const char *, ...);
extern void DBPrintf_8013B490(const char *, ...);
extern char lbl_8055ADB8;
#pragma push
#pragma scheduling invalid_target
int fn_801DB13C(void *arg0, const char *arg1) {
    char key[64];
    char text[64];
    char *messageBase;

    messageBase = lbl_80339240;
    if (sscanf(arg1, &lbl_8055ADB8, key, text) == 2) {
        int i;
        int found;
        int matchAll;
        int one;
        float value;
        char *entry;
        matchAll = strcmp(key, lbl_8055ADB0) == 0;
        value = lbl_80562B50;
        entry = (char *)arg0 + 8;
        found = 0;
        i = 0;
        one = 1;
        while (i < *(int *)((char *)arg0 + 0x5808)) {
            if ((matchAll != 0 || strcmp(entry, key) == 0) &&
                ((int (*)(int, void *))fn_801DA064)(*(int *)(entry + 0x28), text) != 0) {
                fn_801DA198(*(int *)(entry + 0x28), lbl_80562B54);
                *(unsigned char *)(entry + 0x18) = (unsigned char)one;
                found = 1;
                *(float *)(entry + 0x1C) = value;
            }
            entry += 0x2C;
            i++;
        }
        if (found != 0)
            DBPrintf_8013B490(messageBase + 0x110, key, text);
        else
            DBPrintf_8013B490(messageBase + 0x12C, key, text);
    } else if (sscanf(arg1, &lbl_8055ADB4, text) == 1) {
        int matchAll;
        const char *empty;
        int i;
        int found;
        int one;
        float value;
        char *entry;
        empty = lbl_8055ADB0;
        matchAll = strcmp(empty, empty) == 0;
        value = lbl_80562B50;
        entry = (char *)arg0 + 8;
        found = 0;
        i = 0;
        one = 1;
        while (i < *(int *)((char *)arg0 + 0x5808)) {
            if ((matchAll != 0 || strcmp(entry, empty) == 0) &&
                ((int (*)(int, void *))fn_801DA064)(*(int *)(entry + 0x28), text) != 0) {
                fn_801DA198(*(int *)(entry + 0x28), lbl_80562B54);
                *(unsigned char *)(entry + 0x18) = (unsigned char)one;
                found = 1;
                *(float *)(entry + 0x1C) = value;
            }
            entry += 0x2C;
            i++;
        }
        if (found != 0)
            DBPrintf_8013B490(messageBase + 0x148, text);
        else
            DBPrintf_8013B490(messageBase + 0x160, text);
    }
    return 1;
}
#pragma pop
