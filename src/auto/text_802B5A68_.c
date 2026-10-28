#include "types.h"
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern float lbl_8055FA10;

#pragma small_data on
__declspec(section ".sdata") extern const char lbl_8055CE40[];
#pragma small_data off
typedef signed long s32;
typedef unsigned long u32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055FA38;
extern float lbl_8055FA18;
extern s32 lbl_8055FA2C;
extern u8 lbl_8055FA58;
extern s32 fn_80204054(void *, s32, s32, void *, s32, s32);
extern void *fn_802C86DC(void);
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern void **lbl_8055FA48;
extern char lbl_8034A598[];
extern const char lbl_8055CE58[];
extern const char lbl_8055CE60[];
extern double lbl_80564C68;
extern float lbl_80564C58;
extern float lbl_80564C60;
extern s32 fn_802E3D68(void *);
extern void fn_802E3AD0(s32, const char *, ...);
extern void fn_802E3734(void *);
extern float fn_801DCF48(float *, float, float);
extern char lbl_8034A8B0[];
extern float lbl_80564C98;
extern void fn_802B6568(void *, const char *, ...);
extern s32 fn_802B05E4(void);
extern s32 fn_802B7B08(void);

extern char lbl_8055FA31;
extern s32 lbl_8055FA3C;
extern s32 lbl_8055FA40;
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
extern s32 fn_802B59A4(s32);
extern s32 fn_802B321C(s32, void **, s32, s32);
extern s32 fn_802B3F0C(s32);
extern void fn_80128668(void*);
extern const char lbl_8055CE48[];
void* fn_802B5A68(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_802B5AC0(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

__declspec(section ".data") extern u32 lbl_802FAB30;
extern u32 lbl_8055CE30;
u32 fn_802B5B18(s32 arg0) {
    u32 vals[4];
    u32 *p = (u32 *)&lbl_802FAB30;
    vals[0] = *p++;
    vals[1] = *p++;
    vals[2] = *p++;
    vals[3] = *p;
    if (arg0 >= 0 && (u32)arg0 < 4) return vals[arg0];
    return (u32)&lbl_8055CE30;
}

void fn_802B5B6C(void) {
    fn_802B59A4(lbl_8055FA3C);
}

extern void *lbl_8055FA44;
s32 fn_802B5B74(void *arg0) {
    s32 workspace[51];
    s32 result;
    s32 index;
    void *object;

    workspace[2] = 0x10;
    workspace[0] = (s32)&workspace[3];
    workspace[1] = 0;
    object = ((void *(*)(void))fn_802B5B6C)();
    ((void (*)(void *, s32, s32, s32))fn_802B321C)(
        workspace, 0, *(s32 *)((u8 *)object + 8), lbl_8055FA40);

    index = (s32)lbl_8055FA44;
    result = 0;
    if (index >= 0 && index < workspace[1]) {
        result = 1;
    }
    if (result != 0) {
        s32 *entry = (s32 *)workspace[0] + index * 3;
        ((s32 *)arg0)[0] = entry[0];
        ((s32 *)arg0)[1] = entry[1];
        ((s32 *)arg0)[2] = entry[2];
    }
    workspace[0] = 0;
    workspace[1] = 0;
    workspace[2] = 0;
    return result;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802B5C24(s32 arg0) {
    register s32 temp_r31;
    s32 temp_r3;
    register s32 value;

loop_1:
    temp_r3 = arg0 + lbl_8055FA40;
    value = temp_r3 + 7;
    temp_r31 = value % 7;
    lbl_8055FA40 = temp_r31;
    if (temp_r31 >= fn_802B3F0C(*(s32 *)((u8 *)((void *(*)(void))fn_802B5B6C)() + 8))) {
        if (temp_r31 != 6) {
            goto loop_1;
        }
    }
}
#pragma pop

void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

#pragma push
#pragma dont_inline on
void fn_802B5CB4(s32 arg0) {
    lbl_8055FA3C += arg0;
}
#pragma pop

void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

extern int __cntlzw(unsigned int);
void fn_802B5CCC(void) {
    u8 *sp8;
    u8 *object;

    object = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B321C(0, (void **)&sp8, *(s32 *)(object + 8), lbl_8055FA40);
    *sp8 = (u32)__cntlzw(*sp8) / 32U;
    object = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B32E0(*(s32 *)(object + 8));
    object = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B4E44(*(s32 *)(object + 8));
}

#pragma push
#pragma dont_inline on
s32 fn_802B5D94(s32 arg0) {
    return fn_802B5D2C(lbl_8055CE40, arg0);
}

u32 fn_802B5DA0(void) {
    s32 temp_r3 = ((s32 (*)())fn_802B5D94)();
    return (u32)((-1 - temp_r3) | (temp_r3 + 1)) >> 31;
}

#pragma pop

extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802B05DC(void);
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
__declspec(section ".sdata") extern const char lbl_8055CE48[];
__declspec(section ".sdata") extern const char lbl_8055CE50[];
typedef struct {
    s32 w[5];
} Struct804BFF80_Entry;

typedef struct {
    s32 unk0[5];
    char str1[32];
    char str2[32];
    s32 unk54[5];
} Struct804BFF80;
extern s32 lbl_804BFF80[26];
extern void fn_802B83CC(void);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
extern s32 lbl_8055FA28;
extern float lbl_8055FA08;
extern float lbl_80564C5C;
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern s32 sscanf(const char *, const char *, ...);
typedef s32 (*Fn802B83CCPredicate)(const char *);
typedef s32 (*Fn802B83CCAction)(s32, const char *);
typedef struct {
    const char *name;
    Fn802B83CCPredicate predicate;
    Fn802B83CCAction action;
} Fn802B83CCEntry;
extern Fn802B83CCEntry lbl_8034A95C[];
s32 fn_802B5DD0(s32 arg0) {
    s32 temp_r31;
    s32 temp_r3;
    s32 result;
    temp_r31 = fn_802B5D2C(lbl_8055CE48, arg0);
    temp_r3 = fn_802B05DC();
    result = 0;
    if ((temp_r31 != -1) && (temp_r31 != temp_r3)) {
        result = 1;
    }
    return result;
}

#pragma push
#pragma small_data off
#pragma pop
extern double lbl_80564C68;
extern float lbl_80564C70;
extern s32 fn_802E2C20(void);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802B5E24(s32 arg0) {
    lbl_8055FA28 = fn_802B5D2C(lbl_8055CE48, arg0);
    lbl_8055FA08 = lbl_80564C5C;
}

void fn_802B5E58(s32 arg0) {
    extern s32 lbl_8055FA2C;
    extern float lbl_8055FA10;
    extern float lbl_80564C5C;
    extern const char lbl_8055CE50[];
    lbl_8055FA2C = fn_802B5D2C(lbl_8055CE50, arg0);
    lbl_8055FA10 = lbl_80564C5C;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
u32 fn_802B5E8C(s32 arg0) {
    s32 result = fn_802B5D2C(lbl_8055CE50, arg0);
    return (u32)((-1 - result) | (result + 1)) >> 31;
}
#pragma pop
extern void* lbl_8055FA44;
extern s32 fn_802B5D94();

void fn_802B5EC4(void) {
    lbl_8055FA44 = (void*)fn_802B5D94();
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802B5EE8(void) {
    u32 temp_r4;
    u32 temp_r0;

    temp_r4 = lbl_8055FA38 + 1;
    temp_r0 = temp_r4 << 30;
    lbl_8055FA18 = lbl_80564C5C;
    temp_r4 = temp_r4 >> 31;
    temp_r0 = temp_r0 - temp_r4;
    temp_r0 = (temp_r0 << 2) | (temp_r0 >> 30);
    temp_r4 = temp_r0 + temp_r4;
    temp_r0 = 0;
    *(volatile s32 *)&lbl_8055FA38 = temp_r4;
    *(s32 *)((u8 *)&lbl_804BE7D8 + 4) = temp_r0;
}
#pragma pop
extern s32 lbl_8055FA38;
extern float lbl_8055FA18;
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern s32 fn_80128678(void);
extern s32 fn_80128684(void);
extern void *fn_80156A40(void);
extern s32 fn_802A7BDC(s32, s32);
extern void fn_802BBEE4(void);
extern void fn_802C21C0(void);
#pragma push
#pragma cplusplus on
extern "C" void fn_802B5F24(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual s32 b(s32);
    };
    s32 i;
    s32 result;
    V *object;
    fn_80128684();
    i = 0;
    do {
        object = (V *)fn_80156A40();
        result = object->b(0);
        if (result == 0)
            break;
        fn_802A7BDC(arg0, result);
        i++;
    } while (i < 10);
    fn_80128678();
}
#pragma cplusplus reset
#pragma pop
void fn_802B5F98(void) {
    s32 handle;
    s32 i, j, index;
    float height, x, z;
    float points[3];
    handle = fn_802E3D68(lbl_8034A598 + 0x2c);
    if (handle == -1) return;
    fn_802E3AD0(handle, lbl_8055CE58);
    fn_802E3AD0(handle, lbl_8034A598 + 0x3c);
    fn_802E3AD0(handle, lbl_8034A598 + 0x50);
    for (i = -0x200, index = 0; i <= 0x200; i += 8) {
        for (j = -0x200; j <= 0x200; j += 8, index++) {
            x = (float)i * lbl_80564C58;
            z = (float)j * lbl_80564C58;
            height = fn_801DCF48(points, x, z);
            fn_802E3AD0(handle, lbl_8034A598 + 0x60, x, height, z, (float)(i + 0x200));
            fn_802E3AD0(handle, lbl_8034A598 + 0x78,
                        (float)(i + 0x200) * lbl_80564C60,
                        (float)(j + 0x200) * lbl_80564C60);
            fn_802E3AD0(handle, lbl_8034A598 + 0x8c, points[0], points[1], points[2]);
            if (i > -0x200 && j > -0x200) {
                fn_802E3AD0(handle, lbl_8034A598 + 0xa4, index, index - 1, index - 0x81);
                fn_802E3AD0(handle, lbl_8034A598 + 0xa4, index - 0x81, index - 1, index - 0x82);
            }
        }
    }
    fn_802E3AD0(handle, lbl_8055CE60);
    fn_802B5F24(handle);
    fn_802E3AD0(handle, lbl_8055CE60);
    fn_802E3734(&handle);
}

#pragma push
#pragma small_data off
#pragma pop
void fn_802B618C(void) {
    fn_802B59A4(lbl_8055FA3C);
    fn_80128684();
    fn_80128678();
}

void fn_802B61B8(void) {
    if (lbl_8055FA38 == 3) {
        goto call_c;
    }
    if (lbl_8055FA38 >= 3) {
        goto done;
    }
    if (lbl_8055FA38 >= 2) {
        goto call_b;
    }
done:
    return;
call_b:
    fn_802BBEE4();
    return;
call_c:
    fn_802C21C0();
}

extern char lbl_8034A980[];
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern s32 lbl_8055FA00;
extern s32 lbl_8055FA34;
extern s32 fn_80145E70(char *);
extern s32 fn_8026E214(void *, void *);
extern void deleteThreads__6SystemFv(void *);
extern s32 fn_802C6CF8(void);
extern s32 lbl_804BFA70;
#pragma push
#pragma processor 750
#pragma scheduling 750
__declspec(section ".sdata") extern double lbl_80564C68;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802B61E0(void) {
    s32 val = fn_802E2C20();
    lbl_8055FA08 = (float)val / lbl_80564C70;
}

void fn_802B6228(void) {
    s32 val = fn_802E2C20();
    lbl_8055FA10 = (float)val / lbl_80564C70;
}

#pragma pop
s32 fn_802B6270(void) {
    return lbl_8055FA40 == 7;
}

void fn_802B6284(void) {
    lbl_8055FA40 = ((s32) ~((lbl_8055FA40 - 7) | (7 - lbl_8055FA40)) >> 31) + 7;
}

extern char lbl_8034A670[];
extern char lbl_8034A70C[];
extern int strcmp(const char *, const char *);
#pragma dont_inline on
void fn_802B62A4(const char **arg) {
    register s32 *entry = (s32 *)lbl_8034A670;
    register u32 i = 0;

loop:
    if (entry[0] != 0 && strcmp((const char *)entry[0], *arg) == 0) {
        goto action;
    }
    if (entry[1] == 0 || ((s32 (*)(const char *))entry[1])(*arg) == 0) {
        goto next;
    }
action:
    ((void (*)(const char *, void *))*(s32 *)(lbl_8034A670 + i * 12 + 8))(
        *arg, (void *)(lbl_8034A670 + i * 12));
    return;
next:
    i++;
    entry += 3;
    if (i < 4) {
        goto loop;
    }
}

void fn_802B6358(const char **arg) {
    register s32 *entry = (s32 *)lbl_8034A70C;
    register u32 i = 0;

loop:
    if (entry[0] != 0 && strcmp((const char *)entry[0], *arg) == 0) {
        goto action;
    }
    if (entry[1] != 0 && ((s32 (*)(const char *))entry[1])(*arg) != 0) {
        goto action;
    }
    goto next;
action:
    {
        s32 *actionEntry = (s32 *)(lbl_8034A70C + i * 12);
        ((void (*)(const char *, void *))actionEntry[2])(*arg, (void *)actionEntry);
        return;
    }
next:
    i++;
    if (i < 11) {
        entry += 3;
        goto loop;
    }
    entry += 3;
}

extern f32 fn_800108C8(s32, f32);
extern f32 fn_8001090C(f32);
extern float lbl_80564C74;
extern float lbl_80564C78;
s32 fn_802B640C(void *arg0, s32 arg1) {
    f32 temp_f1, temp_f31, temp_f5, var_f4;
    s32 temp_r3, var_r3=0, var_r4=0, var_r5=0;
    temp_f31 = fn_800108C8(arg1, *(f32 *)((char *)arg0 + 0x10));
    temp_f1 = fn_8001090C(*(f32 *)((char *)arg0 + 0x10));
    temp_r3 = *(s32 *)((char *)arg0 + 0x14);
    temp_f5 = *(f32 *)((char *)arg0 + 4);
    if (temp_r3 & 1) var_f4 = lbl_80564C74;
    else if (temp_r3 & 2) var_f4 = -temp_f31;
    else var_f4 = -temp_f31 * lbl_80564C78;
    if ((double)*(s32 *)((char *)&lbl_804BFF80 + 4) >= (double)(temp_f5 + var_f4) &&
        (double)*(s32 *)((char *)&lbl_804BFF80 + 4) < (double)(temp_f5 + temp_f31 + var_f4)) var_r4=1;
    if (var_r4 && (double)*(s32 *)((char *)&lbl_804BFF80 + 8) >= (double)*(f32 *)((char *)arg0+8)) var_r5=1;
    if (var_r5 && (double)*(s32 *)((char *)&lbl_804BFF80 + 8) < (double)(*(f32 *)((char *)arg0+8)+temp_f1)) var_r3=1;
    return var_r3;
}

__declspec(section ".sdata") extern const char lbl_8055CE70[];
extern int vsprintf(char *, const char *, va_list);
extern int stricmp(const char *, const char *);
extern void fn_80147230(void *, const char *, ...);
#pragma scheduling invalid_target
void fn_802B6568(void *arg0, const char *fmt, ...) {
    char buf[256];
    va_list args;
    Struct804BFF80 *s;

    va_start(args, fmt);
    vsprintf(buf, fmt, args);

    s = (Struct804BFF80 *)&lbl_804BFF80;
    *(s32 *)((char *)arg0 + 0x18) = 0xFFD8D8D8;

    if (s->str1[0] != 0) {
        if (stricmp(s->str1, *(char **)arg0) == 0) {
            *(s32 *)((char *)arg0 + 0x18) = -0x100;
        }
    } else if (s->str2[0] != 0) {
        if (stricmp(s->str2, *(char **)arg0) == 0) {
            *(s32 *)((char *)arg0 + 0x18) = -1;
        }
    } else if (fn_802B640C(arg0, (s32)buf) != 0) {
        {
            char *src = *(char **)arg0;
            s32 n = 32;
            char *dst = s->str2;
            while ((*dst++ = *src++) != 0) {
                if (--n <= 0) {
                    dst[-1] = 0;
                    break;
                }
            }
        }
        *(s32 *)((char *)arg0 + 0x18) = -1;
        fn_802B62A4(arg0);
        if (*(s32 *)&lbl_804BFF80 == 0) {
            fn_802B6358(arg0);
            {
                char *src = *(char **)arg0;
                s32 n = 32;
                char *dst = (char *)&lbl_804BFF80 + 0x14;
                while ((*dst++ = *src++) != 0) {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                }
            }
            *(s32 *)((char *)&lbl_804BFF80 + 0x54) = *(s32 *)&lbl_804BFF80;
            *(s32 *)((char *)&lbl_804BFF80 + 0x58) = *(s32 *)((char *)&lbl_804BFF80 + 4);
            *(s32 *)((char *)&lbl_804BFF80 + 0x5C) = *(s32 *)((char *)&lbl_804BFF80 + 8);
            *(s32 *)((char *)&lbl_804BFF80 + 0x60) = *(s32 *)((char *)&lbl_804BFF80 + 0xC);
            *(s32 *)((char *)&lbl_804BFF80 + 0x64) = *(s32 *)((char *)&lbl_804BFF80 + 0x10);
        }
    }
    fn_80147230(arg0, lbl_8055CE70, buf);
}
#pragma scheduling on
__declspec(section ".sdata") extern const char lbl_8055CE78[], lbl_8055CE80[];
extern const char lbl_8034A808[], lbl_8034A814[];
extern s32 fn_80147FF0(s32);
void fn_802B67C8(s32 arg0) {
    void *(*method)(void *, s32) = (void *(*)(void *, s32))(*(void ***)lbl_8055FA48)[5];
    fn_80147FF0(*(s32 *)((char *)method(lbl_8055FA48, arg0) + 0x18));
}

#pragma cplusplus on
extern "C" void fn_802B69FC(void) {
    class Dummy_802B69FC {
    public:
        virtual void m0();
        virtual Dummy_802B69FC *m1(void *);
    };
    char *base = lbl_8034A598;
    Dummy_802B69FC *obj = (Dummy_802B69FC *)lbl_8055FA48;

    obj = obj->m1(base + 0x134);
    fn_802B6568(obj, base + 0x244);
    obj = (Dummy_802B69FC *)lbl_8055FA48;
    obj = obj->m1(base + 0x160);
    fn_802B6568(obj, base + 0x258);
}
#pragma cplusplus reset

#pragma push
#pragma small_data off
s32 fn_802B6A70(s32 arg0) {
    switch (arg0) {
    case 2:
        return (s32)&lbl_8055CE78;
    case 3:
        return (s32)&lbl_8034A808;
    case 5:
        return (s32)&lbl_8034A814;
    default:
    case 4:
        return (s32)&lbl_8055CE80;
    }
}
#pragma pop
extern float lbl_8055FA18;
extern s32 fn_802B6A70(s32);
extern void *fn_802B5240(void *);
extern void fn_802B52B4(void);
extern s32 fn_802E3BB4(void *, void *, s32);
extern s32 fn_802E3C24(s32, void *, s32);
extern void fn_802E3CA4(s32);
extern char *strchr(char *, int);
extern const char lbl_8055CE88[];
extern const char lbl_8055CE90[];
extern const char lbl_8055CE98[];
__declspec(section ".sdata") extern const char lbl_8055CE88[];
__declspec(section ".sdata") extern const char lbl_8055CE90[];
__declspec(section ".sdata") extern const char lbl_8055CE98[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma small_data off
void fn_802B6AC0(void) {
    struct Texture { s32 width; s32 height; u32 *pixels; };
    struct Entry { char name[0x20]; s32 width; s32 height; u8 pixels[1]; };
    struct Scratch { char path[0x20]; char formatBuffer[0x40]; char imageBuffer[0x40]; } scratch;
    s32 *state;
    s32 zero;
    register s32 result;
    s32 mode;
    s32 index;
    s32 row;
    s32 column;
    s32 height;
    s32 width;
    u32 color;
    u32 component;
    u32 pixel;
    s32 exists;
    char *entryName;
    register struct Entry *entry;
    struct Texture *texture;
    float seconds;
    s32 val;

    val = fn_802E2C20();
    seconds = (float)val / lbl_80564C70;
    if (seconds - *(float *)((u8 *)&lbl_8055FA18 + 4) < lbl_8055FA18)
        return;
    val = fn_802E2C20();
    state = (s32 *)&lbl_804BE7D8;
    zero = 0;
    state[1] = zero;
    seconds = (float)val / lbl_80564C70;
    *(float *)((u8 *)&lbl_8055FA18) = seconds;
    mode = fn_802B6A70(lbl_8055FA38);
    ((s32 (*)(char *, s32, const char *, ...))fn_801345D8)(scratch.imageBuffer, 0x40, lbl_8055CE88, mode);
    result = fn_802E3BB4(scratch.imageBuffer, scratch.path, 0x20);
    if ((u32)result + 0x10000U != 0xFFFFU) {
        register char *suffix = (char *)lbl_8055CE98;
        do {
            index = state[1];
            entry = (struct Entry *)(*(u32 *)&lbl_804BE7D8 + index * 0x128);
            state[1] = index + 1;
            {
                s32 remaining = 0x20;
                char *dst = entry->name;
                char *src = scratch.path;
                do {
                    char c = *src++;
                    *dst++ = c;
                    if ((signed char)c != 0) {
                        remaining--;
                        if (remaining > 0) continue;
                        dst[-1] = 0;
                    }
                    break;
                } while (1);
            }
            if (strchr(entry->name, '.') != 0)
                *strchr(entry->name, '.') = 0;
            entry->height = zero;
            entry->width = zero;
            exists = fn_80128690();
            if ((u8)exists == 0) fn_80128684();
            ((s32 (*)(char *, s32, const char *, ...))fn_801345D8)(scratch.formatBuffer, 0x40, lbl_8055CE90, mode, scratch.path);
            texture = (struct Texture *)fn_802B5240(scratch.formatBuffer);
            if (texture != 0) {
                width = texture->width;
                entry->width = width;
                height = texture->height;
                entry->height = height;
                if ((u32)(width * height) > 0x100U) {
                    width = (u32)width > 0x10U ? 0x10 : width;
                    entry->width = width;
                    height = (u32)height > 0x10U ? 0x10 : height;
                    entry->height = height;
                }
                {
                    s32 byteOffset = 0;
                    for (row = 0; row < entry->width; row++, byteOffset += 4) {
                        for (column = 0; column < entry->height; column++) {
                            pixel = *(u32 *)((u8 *)texture->pixels + byteOffset +
                                ((texture->height - 1 - column) * texture->width * 4));
                            color = (pixel >> 8) & 0xFF;
                            component = pixel & 0xFF;
                            if (component > color) color = component;
                            component = (pixel >> 16) & 0xFF;
                            if (component > color) color = component;
                            component = pixel >> 24;
                            if (component > color) color = component;
                            entry->pixels[row + column * entry->width] = (u8)color;
                        }
                    }
                }
                fn_802B52B4();
            }
            if ((u8)exists == 0) fn_80128678();
            if (entry->width == 0) {
                s32 remaining = 0x20;
                entryName = entry->name;
                while ((signed char)*entryName != 0) {
                    remaining--;
                    entryName++;
                }
                if (remaining > 0) {
                    do {
                        char c = *suffix++;
                        *entryName++ = c;
                        if ((signed char)c != 0) {
                            remaining--;
                            if (remaining > 0) continue;
                            entryName[-1] = 0;
                        }
                        break;
                    } while (1);
                }
            }
        } while ((state[1] + 1 <= state[2]) &&
                 fn_802E3C24(result, scratch.path, 0x20) != 0);
        fn_802E3CA4(result);
    }
}
#pragma pop
__declspec(section ".sdata") extern s32 lbl_8055CEA0;
s32 fn_802B6E00(s32 arg0, s32 arg1) {
    s32 var_r0 = 0;
    if ((arg0 < -0x200) || (arg0 > 0x200) || (arg1 < -0x200) || (arg1 > 0x200))
        var_r0 = 1;
    return var_r0;
}

s32 fn_802B6E30(void) {
    switch (lbl_8055FA38) {
    case 2: return 2;
    case 3: return 4;
    case 5: return 1;
    default:
    case 4: return 0;
    }
}

s32 fn_802B6E30(void);
#pragma push
#pragma scheduling on
s16 fn_802B6E7C(s32 arg0, s32 arg1, u32 arg2) {
    return (s16)(arg0 + ((arg1 - (arg2 >> 1)) * (s16)fn_802B6E30()));
}

s16 fn_802B6ED8(s32 arg0, s32 arg1, u32 arg2) {
    return (s16)(arg0 + ((arg1 - (arg2 >> 1)) * (s16)fn_802B6E30()));
}

extern void fn_80204048();
extern void fn_8020404C(void);
#pragma push
#pragma processor 750
void fn_802B6F34(void *arg0, void *arg1, void (*arg2)(s16, s16, u8)) {
    f32 sp[4];
    f32 x, y, adjusted;
    s32 rounded;
    s16 xBase, yBase;
    u32 scale, width, height;
    register u32 row, column;

    if (*(s32 *)((u8 *)arg1 + 0x20) != 0) {
        x = *(f32 *)arg0 / lbl_80564C58;
        if (x < lbl_80564C74)
            adjusted = x - lbl_80564C78;
        else
            adjusted = lbl_80564C78 + x;
        rounded = (s32)adjusted;
        scale = fn_802B6E30();
        xBase = (s16)rounded & ~(scale - 1);

        y = *(f32 *)((u8 *)arg0 + 8) / lbl_80564C58;
        if (y < lbl_80564C74)
            adjusted = y - lbl_80564C78;
        else
            adjusted = lbl_80564C78 + y;
        rounded = (s32)adjusted;
        scale = fn_802B6E30();
        width = lbl_8055CEA0 * *(u32 *)((u8 *)arg1 + 0x20);
        height = lbl_8055CEA0 * *(u32 *)((u8 *)arg1 + 0x24);
        yBase = (s16)rounded & ~(scale - 1);
        if (lbl_8055FA38 == 5) {
            f32 temp = lbl_80564C58 * (f32)fn_802B6ED8(yBase, 0, height);
            f32 raw = (f32)fn_802B6E7C(xBase, 0, width);
            sp[2] = lbl_80564C58 * raw;
            sp[3] = temp;
            temp = lbl_80564C58 * (f32)fn_802B6ED8(yBase, height - 1, height);
            raw = (f32)fn_802B6E7C(xBase, width - 1, width);
            sp[1] = temp;
            sp[0] = lbl_80564C58 * raw;
            fn_80204048(&sp[2], &sp[0], raw);
        }

        for (row = 0; row < width; row++) {
            for (column = 0; column < height; column++) {
                s16 xCoord = fn_802B6E7C(xBase, row, width);
                s16 yCoord = fn_802B6E7C(yBase, column, height);
                if (fn_802B6E00(xCoord, yCoord) == 0) {
                    register u32 scale = lbl_8055CEA0;
                    u32 blockX = row / scale;
                    u32 blockY = column / scale;
                    u32 remX = row - blockX * scale;
                    u32 remY = column - blockY * scale;
                    u8 pixel;

                    if ((remX != 0) || (remY != 0)) {
                        u32 imageWidth = *(u32 *)((u8 *)arg1 + 0x20);
                        u32 nextX = imageWidth - 1;
                        u32 x1 = blockX + 1;
                        u32 nextY;
                        u32 y1;
                        u32 rowOffset;
                        u32 nextRowOffset;

                        if (x1 < nextX)
                            nextX = x1;
                        nextY = *(u32 *)((u8 *)arg1 + 0x24) - 1;
                        y1 = blockY + 1;
                        if (y1 < nextY)
                            nextY = y1;
                        rowOffset = blockY * imageWidth;
                        nextRowOffset = nextY * imageWidth;

                        {
                            f32 fx = (f32)remX / (f32)scale;
                            f32 c00 = (f32)*((u8 *)arg1 + 0x28 + blockX + rowOffset);
                            f32 c10 = (f32)*((u8 *)arg1 + 0x28 + nextX + rowOffset);
                            f32 c01 = (f32)*((u8 *)arg1 + 0x28 + blockX + nextRowOffset);
                            f32 c11 = (f32)*((u8 *)arg1 + 0x28 + nextX + nextRowOffset);
                            f32 top = c00 + fx * (c10 - c00);
                            f32 bottom = c01 + fx * (c11 - c01);
                            pixel = (u8)(s32)(top + ((f32)remY / (f32)scale) * (bottom - top));
                        }
                    } else {
                        u32 imageWidth = *(u32 *)((u8 *)arg1 + 0x20);
                        pixel = *((u8 *)arg1 + 0x28 + blockX + blockY * imageWidth);
                    }
                    arg2(xCoord, yCoord, pixel);
                }
            }
        }

        if (lbl_8055FA38 == 5)
            fn_8020404C();
    }
}
#pragma pop
s32 fn_802B7300(s16 x, s16 y, s32 arg2, s32 arg3, f32 farg0) {
    extern float lbl_80564C74;
    extern float lbl_80564C78;
    extern float lbl_80564C88;
    extern void fn_801E41D8(void *, void *, s32, f32);
    union ScaleConvert {
        double d;
        u32 word[2];
    } scaleConvert;
    f32 points[6];
    f32 x1;
    f32 y1;
    f32 height;
    f32 scale;
    u32 magic;
    s16 scaleValue;
    s32 color;
    s32 alpha;

    magic = 0x43300000;
    points[4] = lbl_80564C74;
    x1 = lbl_80564C88 + (f32)x * lbl_80564C58;
    points[3] = x1;
    y1 = lbl_80564C88 + (f32)y * lbl_80564C58;
    points[5] = y1;
    height = lbl_80564C78 + fn_801DCF48(0, x1, y1);

    *(u32 *)&points[0] = *(u32 *)&points[3];
    points[4] = height;
    *(u32 *)&points[2] = *(u32 *)&points[5];
    *(u32 *)&points[1] = *(u32 *)&points[4];
    points[4] = height + farg0;

    scaleValue = (s16)fn_802B6E30();
    scaleConvert.word[0] = magic;
    scaleConvert.word[1] = (u32)scaleValue ^ 0x80000000;
    scale = lbl_80564C88 * (f32)(scaleConvert.d - lbl_80564C68);

    color = arg2;
    alpha = arg3;
    if (arg2 == 0) {
        alpha = 0xFF000000;
        color = 0x20;
    }
    fn_801E41D8(&points[3], &points[0],
                 (color << 24) | (alpha & 0xFFFFFF), scale);
    return 0;
}

#pragma pop
extern float lbl_80564C8C;
extern double lbl_80564C80;
extern float lbl_80564C90;
extern float lbl_80564C94;
extern s32 fn_802BC09C();
extern void fn_80204044();
extern s32 fn_802C21DC();
extern s32 fn_802B7300(s16, s16, s32, s32, float);
void fn_802B7420(s16 arg0, s16 arg1, s32 arg2) {
    fn_802B7300(arg0, arg1, arg2, -1, lbl_80564C8C);
}

extern s16 lbl_8055FA50[4];
extern s32 fn_802BE8B4(s16, s16, s16);
#pragma use_lmw_stmw off
/* use_lmw_stmw off selects the matching save helpers; scoped nextX/nextY temporaries defer sign extension until after end-coordinate increments. */
void fn_802B7434(void) {
    s32 endX, endY, xMinusSize, start, step;
    s16 size, x, y;

    if (lbl_8055FA38 != 2)
        return;
    for (size = 4; size <= 0x40; size *= 2) {
        start = size - 0x200;
        x = (s16)start;
        endX = x + size;
        step = size * 2;
        while (x < 0x200) {
            y = (s16)start;
            endY = y + size;
            xMinusSize = x - size;
            while (y < 0x200) {
                if (xMinusSize <= lbl_8055FA50[1] &&
                    endX >= lbl_8055FA50[0] &&
                    y - size <= lbl_8055FA50[3] &&
                    endY >= lbl_8055FA50[2]) {
                    fn_802BE8B4(x, y, size);
                }
                {
                    s32 nextY = y + step;
                    endY += step;
                    y = (s16)nextY;
                }
            }
            {
                s32 nextX = x + step;
                endX += step;
                x = (s16)nextX;
            }
        }
    }
}
#pragma use_lmw_stmw reset
void fn_802B7518(s16 arg0, s16 arg1, s32 arg2) {
    s16 x;
    s16 y;
    s16 value;

    x = arg0;
    y = arg1;
    switch (lbl_8055FA38) {
    case 2:
        if (arg2 != 0) {
            if (fn_802BC09C(lbl_8055FA28, 0xFF, (float)(u32)arg2 / lbl_80564C90)) {
                value = lbl_8055FA50[0];
                if (value < x)
                    value = x;
                lbl_8055FA50[0] = value;
                value = lbl_8055FA50[1];
                if (value > x)
                    x = value;
                lbl_8055FA50[1] = x;
                value = lbl_8055FA50[2];
                if (value < y)
                    value = y;
                lbl_8055FA50[2] = value;
                value = lbl_8055FA50[3];
                if (value > y)
                    y = value;
                lbl_8055FA50[3] = y;
            } else {
                fn_802B7300(x, y, arg2, (s32)0xFFFF0000, lbl_80564C94);
            }
        }
        break;
    case 3:
        fn_802C21DC();
        break;
    case 5:
        fn_80204044(arg2, (float)arg0 * lbl_80564C58, (float)arg1 * lbl_80564C58);
        break;
    }
}

extern float lbl_8055FA20[];
#pragma small_data on
__declspec(section ".sdata") extern float lbl_8055FA20[];
#pragma small_data on
#pragma small_data off
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
s32 fn_802B7694(void) {
    s32 result = 0;
    f32 value = (f32)fn_802E2C20() / lbl_80564C70;
    s32 less = value - lbl_8055FA20[1] < lbl_8055FA20[0];

    if (!less) {
        f32 newValue = (f32)fn_802E2C20() / lbl_80564C70;
        result = 1;
        lbl_8055FA20[0] = newValue;
    }
    return result;
}
#pragma pop

extern s32 fn_802B6270(void);
#pragma cplusplus on
extern "C" void fn_802B7884(void *arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void *call(const char *);
    };
    register char *base = lbl_8034A598;
    register void *saved = arg0;
    Dummy *obj = (Dummy *)lbl_8055FA48;
    void *result = obj->call(base + 0x144);
    fn_802B6568(result, (const char *)saved);
    char *selection = fn_802B6270() ? base + 0x288 : base + 0x294;
    obj = (Dummy *)lbl_8055FA48;
    result = obj->call(base + 0x150);
    fn_802B6568(result, selection);
}
#pragma cplusplus reset

extern void lbl_8034A898(void);
void fn_802B7884(void *);
void fn_802B7918(void);
void fn_802B7CF0(void) {
    fn_802B7884(lbl_8034A898);
    fn_802B7918();
}

void fn_802B7D1C(void) {
    fn_802B7884(lbl_8034A8B0);
    fn_802B7918();
    fn_802B7B08();
}

#pragma scheduling invalid_target
s32 fn_802B8110(u32 arg0, s32 arg1) {
    struct Work {
        s32 *items;
        s32 count;
        s32 capacity;
        s32 entries[51];
    } work;
    s32 *temp_r6;
    s32 temp_r29;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r30;
    void *temp_r3;

    /* Match note: reserve the stack entry table and cast the void helper to its pointer-returning convention. */
    var_r30 = 0;
    temp_r29 = fn_802B5D94(arg1);
    temp_r3 = ((void *(*)(void))fn_802B5B6C)();
    work.items = work.entries;
    work.capacity = 0x10;
    work.count = 0;
    ((void (*)(void *, s32, s32, s32))fn_802B321C)(
        &work.items, 0, *(s32 *)((u8 *)temp_r3 + 8), lbl_8055FA40);
    temp_r6 = *(s32 **)((u8 *)work.items + temp_r29 * 0xC + 4);
    temp_r4 = *temp_r6;
    var_r0 = 0x80;
    temp_r5 = temp_r4 + (((s32)((arg0 >> 31) + arg0)) >> 1);
    temp_r3_2 = temp_r5 & (s32)((-temp_r5 & ~temp_r5) >> 31);
    if (temp_r3_2 < 0x80)
        var_r0 = temp_r3_2;
    if (temp_r4 != var_r0) {
        temp_r3_3 = temp_r5 & (s32)((~(temp_r5 - 1) & ~temp_r5) >> 31);
        var_r0_2 = 0x80;
        if (temp_r3_3 < 0x80)
            var_r0_2 = temp_r3_3;
        *temp_r6 = var_r0_2;
        fn_802B32E0(*(s32 *)((u8 *)temp_r3 + 8));
        fn_802B4E44(*(s32 *)((u8 *)temp_r3 + 8));
        var_r30 = 1;
    }
    work.items = 0;
    work.count = 0;
    work.capacity = 0;
    return var_r30;
}
#pragma scheduling on
f32 fn_802B822C(s32 arg0) {
    return lbl_80564C98 * (f32)arg0;
}

extern s32 fn_802B5B74(void *);
extern f32 fn_802B822C(s32);
extern float lbl_80564C9C;
extern s32 lbl_8055CFF0;
extern s32 lbl_8055CFF4;
s32 fn_802B825C(s32 arg0) {
    struct { s32 pad[2]; float *values; } result;
    float *values;
    float value;
    float delta;
    float next;
    s32 changed = 0;

    if (fn_802B5B74(&result) != 0) {
        values = result.values;
        value = values[1];
        delta = fn_802B822C(arg0);
        next = values[0] + delta;
        value = value < next ? value : next;
        value = lbl_80564C98 < value ? lbl_80564C98 : value;
        if (value != values[0]) {
            values[0] = value;
            changed = 1;
            *(volatile u8 *)((u8 *)result.values + 8) = 1;
        }
    }
    return changed;
}

s32 fn_802B8310(s32 arg0) {
    struct Result {
        s32 pad[2];
        float *values;
    };
    register f32 lower;
    register f32 bound = lbl_80564C9C;
    register float *values;
    register s32 changed = 0;
    struct Result result;
    f32 value;
    s32 valid;

    valid = fn_802B5B74(&result);
    if (valid != 0) {
        values = result.values;
        lower = values[0];
        value = values[1] + fn_802B822C(arg0);
        bound = (bound < value) ? bound : value;
        bound = (bound > lower) ? bound : lower;
        if (bound != values[1]) {
            values[1] = bound;
            *(u8 *)((u8 *)result.values + 8) = 1;
            changed = 1;
        }
    }
    return changed;
}

void fn_802B83CC(void) {
    Struct804BFF80 *state = (Struct804BFF80 *)&lbl_804BFF80;
    Struct804BFF80 *callbackState;
    char *callbackName;
    Fn802B83CCEntry *entry;
    Fn802B83CCEntry *actionEntry;
    s32 difference;
    u32 i;

    if (state->str1[0] == 0)
        return;
    difference = state->unk0[1] - state->unk54[1];
    if (difference == 0)
        return;

    for (i = 0; i < 3; i++) {
        entry = &lbl_8034A95C[i];
        if (entry->name == 0 || strcmp(entry->name, state->str1) != 0) {
            if (entry->predicate == 0 || entry->predicate(state->str1) == 0)
                continue;
        }

        actionEntry = (Fn802B83CCEntry *)(volatile void *)&lbl_8034A95C[i];
        callbackState = (Struct804BFF80 *)&lbl_804BFF80;
        callbackName = callbackState->str1;
        if (actionEntry->action(difference, callbackName) != 0) {
            callbackState->unk54[0] = *(u32 *)&lbl_804BFF80;
            callbackState->unk54[1] = callbackState->unk0[1];
            callbackState->unk54[2] = callbackState->unk0[2];
            callbackState->unk54[3] = callbackState->unk0[3];
            callbackState->unk54[4] = callbackState->unk0[4];
        }
        return;
    }
}

#pragma dont_inline on
void fn_802B84E4(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = (*(s32 *)((u8 *)arg0 + 4) * 0x280) / lbl_8055CFF0;
    *(s32 *)((u8 *)arg0 + 8) = (*(s32 *)((u8 *)arg0 + 8) * 0x1E0) / lbl_8055CFF4;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma opt_propagation off
s32 fn_802B8510(s32 arg0) {
    struct Entry {
        u8 unk[0x20];
        u32 first;
        u32 second;
        u8 pixels[0x100];
    } copy;
    struct Entry *entry;
    s32 index;
    s32 width;
    s32 height;
    u32 row;
    u32 col;
    u8 *pixelData;

    if ((u32)(arg0 - 6) > 1U) return;
    index = lbl_8055FA2C;
    if (index < 0) return;
    if (index >= *(s32 *)((u8 *)&lbl_804BE7D8 + 4)) return;
    entry = (struct Entry *)(*(u32 *)&lbl_804BE7D8) + index;
    copy = *entry;

    width = copy.second;
    pixelData = copy.pixels;
    row = 0;
    entry->first = width;
    height = copy.first;
    entry->second = height;

    while (row < entry->first) {
        col = 0;
        while (col < entry->second) {
            if (arg0 == 6) {
                entry->pixels[row + col * entry->first] =
                    height * (row + 1) - 1 - col;
            } else {
                entry->pixels[row + col * entry->first] =
                    (width - row - 1) * height + col;
            }
            col++;
        }
        row++;
    }
}
#pragma pop
void fn_802B8624(void *arg0) {
    #pragma small_data off
    s32 *p = (s32 *)&lbl_804BFF80;
    *p = 8;
    if (arg0 != 0) {
        *p = *(s32 *)arg0;
        p[1] = ((s32 *)arg0)[1];
        p[2] = ((s32 *)arg0)[2];
        p[3] = ((s32 *)arg0)[3];
        p[4] = ((s32 *)arg0)[4];
        fn_802B84E4(p);
        fn_802B83CC();
        fn_802B8510(*p);
    }
}
#pragma pop
extern void fn_802B83CC(void);
extern void fn_802B84E4(void *);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
#pragma cplusplus on
class Dummy_802B869C {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f8();
};
#pragma cplusplus on
extern "C" void fn_802B869C(void) {
    s32 sp8[6];
    if (((Dummy_802B869C *)lbl_8055FA48)->f8() == 0) {
        if (fn_80127A50(sp8) != 0) {
            fn_802B8624(sp8);
        } else {
            fn_802B8624(0);
        }
    }
}
#pragma cplusplus off

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802B86F8(void) {
    s8 value;
    u8 *base;
    value = ((s8 *)&lbl_804BFF80)[0x14];
    base = (u8 *)&lbl_804BFF80;
    base[0x34] = 0;
    if (value == 0)
        return;
    if (*(s32 *)(base + 0xC) & 1)
        return;
    base[0x14] = 0;
}
#pragma pop
s32 fn_802B8728(void) {
    return (s8)*((u8 *)&lbl_804BFF80 + 0x34) == 0;
}

#pragma push
#pragma opt_propagation off
void fn_802B8744(void) {
    s32 result;
    void *state;

    result = fn_80145E70(lbl_8034A980);
    state = &lbl_804BE7D8;
    lbl_8055FA48 = (void **)result;
    lbl_8055FA40 = 6;
    *(s32 *)((u8 *)state + 4) = 0;
    lbl_8055FA00 = fn_8026E214((void *)fn_802B8728, state);
    lbl_8055FA34 = -1;
}
#pragma pop
void fn_802B87A0(void) {
    fn_8026E214((void *)lbl_8055FA00, 0);
    deleteThreads__6SystemFv((void *)((u8 *)&lbl_8055FA48));
    {
        register s32 state = lbl_8055FA34;
        if (state != -1) {
            fn_802C6CF8();
            lbl_8055FA34 = -1;
        }
    }
    *(s32 *)((u8 *)&lbl_804BFA70 + 4) = 0;
}
#pragma pop
void fn_802B87F4(void) {
    if (lbl_8055FA48 != 0) {
        fn_802B869C();
        fn_802B59A4(lbl_8055FA3C);
        fn_802B0288();
        if (lbl_8055FA38 != 1) {
            switch (lbl_8055FA40) {
            case 6:
                break;
            default:
                fn_802B4E3C();
                break;
            }
        }
    }
}

extern char lbl_8055FA32;
extern float lbl_80564CA0, lbl_80564CA4;
extern char lbl_8034A6C0[];
extern void fn_802B773C(void), fn_802C7040(void), fn_80230B5C(void *), fn_802C8638(void *);
extern void fn_802C974C(float,float,float), fn_802B86F8(void), fn_802B676C(void), fn_802B6804(void);
extern void fn_802B7D4C(void), fn_802B69FC(void), fn_802B7D1C(void), fn_802B7CF0(void);
extern void fn_8001123C(s32), fn_80011A2C(void);
void fn_802B8848(void) {
    s32 sp8[12], temp_r31;
    s32 temp_r34;
    s32 state;
    if (lbl_8055FA48 != 0) {
        if ((u32)(lbl_8055FA38 - 2) <= 1U) fn_802B773C();
        if ((u8)lbl_8055FA32 != 0 && (temp_r34=lbl_8055FA34) != -1) fn_802C7040();
        fn_80230B5C(sp8); fn_802C8638(sp8);
        fn_802C974C(lbl_80564CA0, lbl_80564C70, lbl_80564CA4);
        fn_802B86F8(); fn_802B676C();
        if (lbl_8055FA38 != 2 && lbl_8055FA38 != 3) fn_802B6804();
        switch (lbl_8055FA38) { case 0: fn_802B7D4C(); break; case 1: fn_802B69FC(); break; case 2: fn_802B7D1C(); break; case 3: fn_802B7CF0(); break; }
        state = lbl_8055FA38;
        temp_r31=fn_802B5B18(((state << 30) - (state >> 31) << 2) + (state >> 31));
        fn_802B6568(((void *(*)(void *, void *))(*(u32 **)*lbl_8055FA48)[3])(*lbl_8055FA48,lbl_8034A6C0), (const char *)temp_r31);
        ((void (*)(void *))(*(u32 **)*lbl_8055FA48)[7])(*lbl_8055FA48);
        fn_8001123C(0); fn_80011A2C();
    }
}

extern char lbl_8055FA59;
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_802B8998(s32 arg0) {
    struct Handler {
        virtual void method0();
        virtual void method1();
        virtual void method2();
        virtual void method3();
        virtual void method4();
        virtual void method5();
        virtual void method6();
        virtual void method7();
        virtual void method8();
    };

    /* Match note: retain target virtual dispatch, unsigned zero tests, and explicit state writes. */
    if (lbl_8055FA48 != 0) {
        switch (arg0) {
        case 0x125:
        case 0x127:
            if (lbl_8055FA38 == 0)
                fn_802B5C24((u32)arg0 == 0x125U ? -1 : 1);
            *(s32 *)&lbl_804BFF80 = 8;
            *(s32 *)&lbl_8055FA44 = -1;
            *(u8 *)((u8 *)&lbl_804BFF80 + 0x34) = 0;
            *(u8 *)((u8 *)&lbl_804BFF80 + 0x14) = 0;
            break;
        case 0x5:
            ((Handler *)(void *)lbl_8055FA48)->method6();
            break;
        case 0x65:
            fn_802B8510(6);
            break;
        case 0x6d:
            break;
        case 0x73:
            ((Handler *)(void *)lbl_8055FA48)->method8();
            break;
        case 0x6e:
            lbl_8055FA59 = ((u8)lbl_8055FA59 == 0);
            break;
        case 0x77:
            lbl_8055FA32 = ((u8)lbl_8055FA32 == 0);
            break;
        default:
            return 0;
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop
void fn_802B8AE0(const char *arg0, s32 arg1) {
    struct Local { char name[32]; volatile s32 savedArg; volatile s32 zero; } local;
    s32 i, count;
    char *base,*dst;
    if(fn_802B05E4()!=0) return;
    local.name[31]=0;
    dst=local.name;
    do { char c=*arg0++; *dst++=c; } while((signed char)dst[-1]!=0);
    count=*(s32*)((u8*)&lbl_804BFA70+4);
    base=*(char**)&lbl_804BFA70;
    *(s32*)((u8*)&lbl_804BFA70+4)=count+1;
    dst=base+count*0x28;
    dst[0]=local.name[0];
    dst[1]=local.name[1];
    dst[2]=local.name[2];
    dst[3]=local.name[3];
    dst[4]=local.name[4];
    dst[5]=local.name[5];
    dst[6]=local.name[6];
    dst[7]=local.name[7];
    dst[8]=local.name[8];
    dst[9]=local.name[9];
    dst[10]=local.name[10];
    dst[11]=local.name[11];
    dst[12]=local.name[12];
    dst[13]=local.name[13];
    dst[14]=local.name[14];
    dst[15]=local.name[15];
    dst[16]=local.name[16];
    dst[17]=local.name[17];
    dst[18]=local.name[18];
    dst[19]=local.name[19];
    dst[20]=local.name[20];
    dst[21]=local.name[21];
    dst[22]=local.name[22];
    dst[23]=local.name[23];
    dst[24]=local.name[24];
    dst[25]=local.name[25];
    dst[26]=local.name[26];
    dst[27]=local.name[27];
    dst[28]=local.name[28];
    dst[29]=local.name[29];
    dst[30]=local.name[30];
    dst[31]=local.name[31];
    *(s32*)(dst+0x20)=arg1;
    local.savedArg=arg1;
    local.zero=0;
    *(s32*)(dst+0x24)=0;
}
#pragma small_data on
extern s32 lbl_8055CEA0;
void fn_802B8C88(void) {
    lbl_8055FA31 = 1;
    lbl_8055CEA0 = 1;
}

#pragma small_data on
void fn_802B8C98(void) {
    lbl_8055FA31 = 0;
}
struct Texture802B { s32 width; s32 height; u32 *pixels; };
struct Entry802B { char name[0x20]; s32 width; s32 height; char pixels[1]; };
struct Entries802B { s32 pad; s32 count; struct Entry802B *entries; };

