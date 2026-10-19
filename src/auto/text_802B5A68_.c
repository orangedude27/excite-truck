#include "types.h"
#pragma small_data on
__declspec(section ".sdata") extern const char lbl_8055CE40[];
#pragma small_data off
typedef signed long s32;
typedef unsigned long u32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
extern void fn_802B6568(void *, ...);
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

void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

#pragma push
#pragma dont_inline on
s32 fn_802B5D94(s32 arg0) {
    return fn_802B5D2C(lbl_8055CE40, arg0);
}
#pragma pop

extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802B05DC(void);
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
__declspec(section ".sdata") extern const char lbl_8055CE48[];
__declspec(section ".sdata") extern const char lbl_8055CE50[];
extern s32 lbl_804BFF80;
extern void fn_802B83CC(void);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
extern s32 lbl_8055FA28;
extern float lbl_8055FA08;
extern float lbl_80564C5C;
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern s32 sscanf(const char *, const char *, ...);
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
#pragma scheduling off
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

#pragma pop
u32 fn_802B5E8C(s32 arg0) {
    s32 result = fn_802B5D2C(lbl_8055CE50, arg0);
    return (u32)((-1 - result) | (result + 1)) >> 31;
}

extern void* lbl_8055FA44;
extern s32 fn_802B5D94();

void fn_802B5EC4(void) {
    lbl_8055FA44 = (void*)fn_802B5D94();
}

extern s32 lbl_8055FA38;
extern s32 fn_80128678(void);
extern s32 fn_80128684(void);
extern void *fn_80156A40(void);
extern s32 fn_802A7BDC(s32);
extern void fn_802BBEE4(void);
extern void fn_802C21C0(void);
void fn_802B5F24(s32 arg0) {
    s32 i;
    s32 result;
    void *object;
    void **vtable;
    s32 (*method)(void *, s32);
    fn_80128684();
    i = 0;
    do {
        object = fn_80156A40();
        vtable = *(void ***)object;
        method = (s32 (*)(void *, s32))vtable[3];
        result = method(object, 0);
        if (result == 0)
            break;
        fn_802A7BDC(arg0);
        i++;
    } while (i < 10);
    fn_80128678();
}

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
        fn_802C21C0();
    } else if (lbl_8055FA38 == 2) {
        fn_802BBEE4();
    }
}

extern char lbl_8034A980[];
extern s32 lbl_804BE7D8;
extern s32 lbl_8055FA00;
extern s32 lbl_8055FA34;
extern s32 fn_80145E70(char *);
extern s32 fn_8026E214(void *, void *);
extern void deleteThreads__6SystemFv(void *);
extern s32 fn_802C6CF8(void);
extern s32 lbl_804BFA70;
void fn_802B61E0(void) {
    s32 val = fn_802E2C20();
    double magic = lbl_80564C68;
    (void)magic;
    lbl_8055FA08 = (float)val / lbl_80564C70;
}

s32 fn_802B6270(void) {
    return lbl_8055FA40 == 7;
}

void fn_802B6284(void) {
    lbl_8055FA40 = ((s32) ~((lbl_8055FA40 - 7) | (7 - lbl_8055FA40)) >> 31) + 7;
}

extern s32 lbl_8034A670;
extern s32 lbl_8034A70C;
extern int strcmp(const char *, const char *);
void fn_802B62A4(const char **arg) {
    s32 i = 0;
    s32 *entry = &lbl_8034A670;
    do {
        if (entry[0] != 0 && strcmp((const char *)entry[0], *arg) == 0) break;
        if (entry[1] != 0 && ((s32 (*)(const char *))entry[1])(*arg) != 0) {
            ((void (*)(const char *, void *))entry[2])(*arg, (void *)entry);
            return;
        }
        i++;
        entry += 3;
    } while (i < 4);
}

void fn_802B6358(const char **arg) {
    s32 i = 0;
    s32 *entry = &lbl_8034A70C;
    do {
        if (entry[0] != 0 && strcmp((const char *)entry[0], *arg) == 0) break;
        if (entry[1] != 0 && ((s32 (*)(const char *))entry[1])(*arg) != 0) {
            ((void (*)(const char *, void *))entry[2])(*arg, (void *)entry);
            return;
        }
        i++;
        entry += 3;
    } while (i < 11);
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

extern s32 fn_80147FF0(s32);
void fn_802B67C8(s32 arg0) {
    void *(*method)(void *, s32) = (void *(*)(void *, s32))(*(void ***)lbl_8055FA48)[5];
    fn_80147FF0(*(s32 *)((char *)method(lbl_8055FA48, arg0) + 0x18));
}

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

extern s32 lbl_8055CE78;
extern s32 lbl_8055CE80;
extern s32 lbl_8034A808;
extern s32 lbl_8034A814;
s32 fn_802B6E30(void);
#pragma push
#pragma scheduling off
s16 fn_802B6E7C(s32 arg0, s32 arg1, u32 arg2) {
    s32 scale = fn_802B6E30();
    s32 delta = arg1 - (arg2 >> 1);
    return (s16)(arg0 + delta * scale);
}

s16 fn_802B6ED8(s32 arg0, s32 arg1, u32 arg2) {
    return (s16)(arg0 + ((arg1 - (arg2 >> 1)) * fn_802B6E30()));
}

#pragma pop
extern float lbl_80564C8C;
extern s32 fn_802B7300(s16, s16, s32, s32, float);
void fn_802B7420(s16 arg0, s16 arg1, s32 arg2) {
    fn_802B7300(arg0, arg1, arg2, -1, lbl_80564C8C);
}

extern s16 lbl_8055FA50[4];
extern s32 fn_802BE8B4(s16, s16, s16);
void fn_802B7434(void) {
    s16 size, x, y;
    s16 endX, endY;
    s32 step;
    if (lbl_8055FA38 != 2)
        return;
    for (size = 4; size <= 0x40; size *= 2) {
        step = size * 2;
        for (x = (s16)(size - 0x200); x < 0x200; x = (s16)(x + step)) {
            endX = x + size;
            for (y = (s16)(size - 0x200); y < 0x200; y = (s16)(y + step)) {
                endY = y + size;
                if (x - size <= lbl_8055FA50[1] &&
                    endX >= lbl_8055FA50[0] &&
                    y - size <= lbl_8055FA50[3] &&
                    endY >= lbl_8055FA50[2]) {
                    fn_802BE8B4(x, y, size);
                }
            }
        }
    }
}

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
    s32 changed = 0;
    float *values;
    float value;
    if (fn_802B5B74(&result) != 0) {
        values = result.values;
        value = values[0] + fn_802B822C(arg0);
        if (values[1] < value) {
        } else {
            value = values[1];
        }
        if (value > lbl_80564C98) {
        } else {
            value = lbl_80564C98;
        }
        if (value != values[0]) {
            values[0] = value;
            changed = 1;
            *(u8 *)((u8 *)values + 8) = 1;
        }
    }
    return changed;
}

s32 fn_802B8310(s32 arg0) {
    struct { s32 pad[2]; float *values; } result;
    s32 changed = 0;
    float *values;
    float value;
    float bound = lbl_80564C9C;
    if (fn_802B5B74(&result) != 0) {
        values = result.values;
        value = values[1] + fn_802B822C(arg0);
        if (bound < value) {
        } else {
            bound = value;
        }
        if (bound > values[0]) {
        } else {
            bound = values[0];
        }
        if (bound != values[1]) {
            values[1] = bound;
            changed = 1;
            *(u8 *)((u8 *)values + 8) = 1;
        }
    }
    return changed;
}

#pragma dont_inline on
void fn_802B84E4(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = (*(s32 *)((u8 *)arg0 + 4) * 0x280) / lbl_8055CFF0;
    *(s32 *)((u8 *)arg0 + 8) = (*(s32 *)((u8 *)arg0 + 8) * 0x1E0) / lbl_8055CFF4;
}

#pragma push
#pragma small_data off
void fn_802B8624(void *arg0) {
    #pragma small_data off
    s32 *p = &lbl_804BFF80;
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
extern s32 lbl_804BFF80;
extern void fn_802B83CC(void);
extern void fn_802B84E4(void *);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
void fn_802B869C(void) {
    s32 sp8[6];
    void **obj = lbl_8055FA48;
    s32 (**vtable)(void) = (s32 (**)(void))*obj;
    if (vtable[9]() == 0) {
        if (fn_80127A50(sp8) != 0) {
            fn_802B8624(sp8);
        } else {
            fn_802B8624(0);
        }
    }
}

void fn_802B86F8(void) {
    u8 *base = (u8 *)&lbl_804BFF80;
    u8 value = base[0x14];
    base[0x34] = 0;
    if (value == 0)
        return;
    if (*(s32 *)(base + 0xC) & 1)
        return;
    base[0x14] = 0;
}

s32 fn_802B8728(void) {
    return (s8)*((u8 *)&lbl_804BFF80 + 0x34) == 0;
}

void fn_802B8744(void) {
    lbl_8055FA48 = (void **)fn_80145E70(lbl_8034A980);
    lbl_8055FA40 = 6;
    *(s32 *)((u8 *)&lbl_804BE7D8 + 4) = 0;
    lbl_8055FA00 = fn_8026E214((void *)fn_802B8728, &lbl_804BE7D8);
    lbl_8055FA34 = -1;
}

#pragma push
#pragma small_data off
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
    s32 value;
    if (lbl_8055FA48 != 0) {
        fn_802B869C();
        fn_802B59A4(lbl_8055FA3C);
        fn_802B0288();
        if (lbl_8055FA38 == 1)
            return;
        value = lbl_8055FA40;
        if (value != 6)
            fn_802B4E3C();
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
        ((void (*)(void *, void *))(*(u32 **)*lbl_8055FA48)[3])(*lbl_8055FA48,lbl_8034A6C0);
        fn_802B6568((void *)temp_r31);
        ((void (*)(void *))(*(u32 **)*lbl_8055FA48)[7])(*lbl_8055FA48);
        fn_8001123C(0); fn_80011A2C();
    }
}

extern char lbl_8055FA59;
s32 fn_802B8998(s32 arg0) {
    if (lbl_8055FA48 == 0) return 0;
    switch (arg0) {
    case 0x125:
    case 0x127:
        if (lbl_8055FA38 == 0) fn_802B5C24(arg0 == 0x125 ? -1 : 1);
        *(s32 *)&lbl_804BFF80 = 8;
        *(s32 *)&lbl_8055FA44 = -1;
        *(unsigned char *)((char *)&lbl_804BFF80 + 0x34) = 0;
        *(unsigned char *)((char *)&lbl_804BFF80 + 0x14) = 0;
        break;
    case 0x5: {
        void *obj = lbl_8055FA48;
        ((void (*)(void *))(*(void ***)obj)[8])(obj);
        break;
    }
    case 0x65:
        fn_802B8510(6);
        break;
    case 0x6d:
        break;
    case 0x6e:
        lbl_8055FA59 = lbl_8055FA59 == 0;
        break;
    case 0x73: {
        void *obj = lbl_8055FA48;
        ((void (*)(void *))(*(void ***)obj)[10])(obj);
        break;
    }
    case 0x77:
        lbl_8055FA32 = lbl_8055FA32 == 0;
        break;
    default:
        return 0;
    }
    return 1;
}

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
typedef struct UIObj UIObj;
typedef struct UIObjVtable {
    void *m0;
    void *m1;
    void *m2;
    void *(*m3)(UIObj *, const char *);
    void *m4;
    void *(*m5)(UIObj *, const char *);
} UIObjVtable;
struct UIObj {
    UIObjVtable *vtable;
};

typedef struct UIThing {
    void *unk0;
    s32 unk4;
    f32 unk8;
    s32 unkc;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1c;
} UIThing;

struct EntryList {
    void *ptr;
    s32 count;
};

