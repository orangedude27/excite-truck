// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma use_lmw_stmw off
#include <revolution/MTX/mtxtypes.h>

extern float lbl_80562B54;
void fn_801DA198(int, float);
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
void fn_801DA6EC(void) {
    void *obj;
    void **table;
    obj = fn_801284F8(0x580C, &lbl_8055AD98);
    if (obj != 0) {
        *(void **)obj = lbl_803381C0;
        fn_801D0DDC(obj);
        table = (void **)lbl_80339258;
        *(void **)obj = table;
        table = (void **)((char *)table + 0x1C);
        *(void **)((char *)obj + 4) = table;
        lbl_8055E984 = obj;
        *(int *)((char *)obj + 0x5808) = 0;
    }
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
    register unsigned char *dst;
    register unsigned char *src;
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
    dst = (unsigned char *)record;
    src = name;
    while (--count > 0) {
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
extern char lbl_8055ADB0[];
extern char lbl_80339240[];
extern char lbl_8033924C[];
void *fn_801DA8C8(const char *arg0, const char *arg1) {
    void *space;
    const char *name;
    const char *text;
    char *stack[512];
    char *entry;
    char *result;
    int count;
    int offset;
    int i;
    int matchAll;

    space = lbl_8055E984;
    name = arg0;
    text = arg1;
    offset = 0;
    count = 0;
    result = 0;
    matchAll = strcmp(name, lbl_8055ADB0) == 0;
    entry = (char *)space + 8;
    i = 0;
    while (i < *(int *)((char *)space + 0x5808)) {
        if (matchAll || strcmp(entry, name) == 0) {
            if (fn_801D9FC4((char **)*(void **)((char *)entry + 0x28), text) != 0) {
                *(char **)((char *)stack + offset) = entry;
                count += 1;
                offset += 4;
            }
        }
        entry += 0x2C;
        i += 1;
    }
    if (count > 0) {
        char *dst;
        int len;

        result = fn_801284F8(0x20, lbl_80339240);
        if (result != 0) {
            signed char c;

            *(void **)result = lbl_80339288;
            *(int *)((char *)result + 0xC) = count;
            dst = (char *)result + 0x10;
            len = 0x10;
            for (;;) {
                c = *text;
                text += 1;
                *dst = c;
                dst += 1;
                if (c == 0)
                    break;
                if (--len <= 0) {
                    *(dst - 1) = 0;
                    break;
                }
            }
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
void *__dt__14CollisionSpaceFv_801DAB70(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80339288;
        fn_80128670(*(void **)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

float fn_801DABD4(void *arg0) {
    float value;
    register float max = lbl_80562B54;
    register int i = 0;
    register int offset = 0;

    goto check;
loop:
    value = fn_801DA6B8(*(int *)((char *)(*(void ***)((char *)arg0 + 4))[offset / 4] + 0x28));
    if (max <= value)
        max = value;
    offset += 4;
    i++;
check:
    if (i < *(int *)((char *)arg0 + 8))
        goto loop;
    return max;
}

#pragma scheduling invalid_target
float fn_801DAC5C(void *arg0) {
    int count = *(int *)((char *)arg0 + 8);
    int index;
    float max = lbl_80562B54;
    for (index = 0; index < count; index++) {
        void **items = *(void ***)((char *)arg0 + 4);
        void *entry = items[index];
        void *data = *(void **)((char *)entry + 0x28);
        float value = *(float *)((char *)data + 0xC);
        if (max <= value) {
            max = value;
        }
    }
    return max;
}
#pragma scheduling on
extern void fn_801DA064(int, void *);
extern void fn_801DA198(int, float);
extern void fn_802E30C8(char *, int, void *);
extern char lbl_803392F0[];
#pragma scheduling invalid_target
void fn_801DACA0(void *arg0, float arg1) {
    float value;
    int count;
    int offset;
    void *entry;

    value = lbl_80562B54;
    if (arg1 < value)
        value = ((float (*)(void *))(*(void ***)(arg0) + 3)[0])(arg0);

    count = 0;
    offset = 0;
    while (count < *(int *)((char *)arg0 + 8)) {
        entry = *(void **)((char *)*(void ***)((char *)arg0 + 4) + offset);
        if (*((unsigned char *)entry + 0x18) != 0)
            ((void (*)(char *, ...))fn_802E30C8)((char *)lbl_803392F0, count, (void *)((int *)arg0 + 4));
        *((unsigned char *)entry + 0x18) = 1;
        *((float *)((char *)entry + 0x1C)) = arg1;
        fn_801DA064(*(int *)((char *)entry + 0x28), (char *)arg0 + 0x10);
        fn_801DA198(*(int *)((char *)entry + 0x28), value);
        offset += 4;
        count += 1;
    }
}
#pragma scheduling on
int fn_801DAD7C(void *arg0) {
    int count = *(int *)((char *)arg0 + 8);
    int index;
    for (index = 0; index < count; index++) {
        void **items = *(void ***)((char *)arg0 + 4);
        if (*((unsigned char *)items[index] + 0x18) != 0) {
            return 0;
        }
    }
    return 1;
}
#pragma scheduling on
void fn_801DADBC(void *arg0) {
    int i = 0;
    int offset = 0;
    void **items;
    while (i < *(int *)((char *)arg0 + 8)) {
        items = *(void ***)((char *)arg0 + 4);
        fn_801DA198(*(int *)((char *)items[offset / 4] + 0x28), lbl_80562B54);
        offset += 4;
        i++;
    }
}
#pragma scheduling off
extern void fn_801D9F44(void *, int);
extern void fn_801D9F24(void *);
extern void fn_801D0DFC(void *);
#pragma scheduling off
void *fn_801DAE28(void *arg0, int arg1) {
    unsigned char *entry;
    int i;
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 4) = (char *)lbl_80339258 + 0x1C;
        *(void **)arg0 = lbl_80339258;
        entry = (unsigned char *)arg0 + 8;
        i = 0;
        lbl_8055E984 = 0;
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

void fn_801DAEFC(void *arg0) {
    unsigned char *entry = (unsigned char *)arg0 + 8;
    int i;
    for (i = 0; i < *(int *)((char *)arg0 + 0x5808); i++) {
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
void fn_801DAF68(void *arg0) {
    register void *base;
    register unsigned char *entry;
    register int index;
    register f32 rate;
    register f32 threshold;
    register f32 scale;
    Mtx transform;
    Vec first;
    Vec second;

    scale = lbl_80562B5C;
    base = arg0;
    rate = lbl_80562B58;
    entry = (unsigned char *)base + 8;
    threshold = lbl_80562B54;
    index = 0;
    for (; index < *(int *)((char *)base + 0x5808); entry += 0x2C, index++) {
        if (entry[0x18] == 0 && entry[0x10] == 0)
            continue;
        if (entry[0x18] != 0)
            fn_801DA0EC(*(int *)(entry + 0x28), rate * *(float *)(entry + 0x1C));
        if (fn_801DA294(*(int *)(entry + 0x28), transform, &first.x, &second.x) != 0) {
            first.x *= scale;
            first.y *= scale;
            first.z *= scale;
            second.x *= scale;
            second.y *= scale;
            second.z *= scale;
            if (entry[0x10] != 0)
                transform[2][2] = *(float *)(entry + 0x14) + fn_801EA0E8(transform[2][1], transform[2][3]);
            fn_8017CFFC(*(int *)(entry + 0x20), transform, &first.x, &second.x);
        } else if (lbl_8055E980 == 0) {
            lbl_8055E980 = 1;
            ((void (*)(char *, ...))fn_802E30C8)(&lbl_8055ADB4, lbl_80339318);
        }
        if (*(float *)(entry + 0x1C) >= threshold) {
            if (fn_801DA648(*(int *)(entry + 0x28)) != 0) {
                if (entry[0x19] != 0)
                    fn_801DA198(*(int *)(entry + 0x28), lbl_80562B54);
                else
                    entry[0x18] = 0;
            }
        } else if (fn_801DA688(*(int *)(entry + 0x28)) != 0 && entry[0x19] == 0) {
            entry[0x18] = 0;
        }
    }
}

extern int sscanf(const char *, const char *, ...);
extern void DBPrintf_8013B490(const char *, ...);
extern char lbl_8055ADB8;
int fn_801DB13C(void *arg0, const char *arg1) {
    char key[64];
    char text[64];
    char *entry;
    int matchAll;
    int found;
    int i;
    int one;
    float value;

    if (sscanf(arg1, &lbl_8055ADB8, key, text) == 2) {
        matchAll = strcmp(key, lbl_8055ADB0) == 0;
        value = lbl_80562B50;
        entry = (char *)arg0 + 8;
        found = 0;
        i = 0;
        one = 1;
        do {
            if ((matchAll != 0 || strcmp(entry, key) == 0) &&
                ((int (*)(int, void *))fn_801DA064)(*(int *)(entry + 0x28), text) != 0) {
                fn_801DA198(*(int *)(entry + 0x28), lbl_80562B54);
                *(unsigned char *)(entry + 0x18) = (unsigned char)one;
                found = 1;
                *(float *)(entry + 0x1C) = value;
            }
            entry += 0x2C;
            i++;
        } while (i < *(int *)((char *)arg0 + 0x5808));
        if (found != 0)
            DBPrintf_8013B490(lbl_80339240 + 0x110, key, text);
        else
            DBPrintf_8013B490(lbl_80339240 + 0x12C, key, text);
    } else if (sscanf(arg1, &lbl_8055ADB4, text) == 1) {
        matchAll = strcmp(lbl_8055ADB0, lbl_8055ADB0) == 0;
        value = lbl_80562B50;
        entry = (char *)arg0 + 8;
        found = 0;
        i = 0;
        one = 1;
        do {
            if ((matchAll != 0 || strcmp(entry, lbl_8055ADB0) == 0) &&
                ((int (*)(int, void *))fn_801DA064)(*(int *)(entry + 0x28), text) != 0) {
                fn_801DA198(*(int *)(entry + 0x28), lbl_80562B54);
                *(unsigned char *)(entry + 0x18) = (unsigned char)one;
                found = 1;
                *(float *)(entry + 0x1C) = value;
            }
            entry += 0x2C;
            i++;
        } while (i < *(int *)((char *)arg0 + 0x5808));
        if (found != 0)
            DBPrintf_8013B490(lbl_80339240 + 0x148, text);
        else
            DBPrintf_8013B490(lbl_80339240 + 0x160, text);
    }
    return 1;
}

#pragma pop
