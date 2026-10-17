#include "types.h"
#pragma small_data on
extern const char lbl_8055CE40[];
#pragma small_data off
typedef signed long s32;
typedef unsigned long u32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void **lbl_8055FA48;
extern char lbl_8034A598[];
extern char lbl_8034A8B0[];
extern float lbl_80564C98;
extern s32 fn_802B6568(void *);
extern s32 fn_802B7B08(void);

extern char lbl_8055FA31;
extern s32 lbl_8055FA3C;
extern s32 lbl_8055FA40;
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

void fn_802B5B6C(void) {
    fn_802B59A4(lbl_8055FA3C);
}

void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802B05DC(void);
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
__declspec(section ".sdata") extern const char lbl_8055CE40[];
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

    temp_r31 = fn_802B5D2C((const char *)&lbl_8055CE48, arg0);
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
#pragma small_data on
#pragma small_data off
void fn_802B5E24(s32 arg0) {
    lbl_8055FA28 = fn_802B5D2C(lbl_8055CE48, arg0);
    lbl_8055FA08 = lbl_80564C5C;
}
u32 fn_802B5E8C(s32 arg0) {
    s32 result = fn_802B5D2C(lbl_8055CE50, arg0);
    return (u32)((-1 - result) | (result + 1)) >> 31;
}

extern void* lbl_8055FA44;

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
    fn_80128684();
    i = 0;
    do {
        result = (*(s32 (**)(s32))(*(s32 *)fn_80156A40() + 3))(0);
        if (result == 0) break;
        fn_802A7BDC(arg0);
        i++;
    } while (i < 10);
    fn_80128678();
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
void fn_802B61E0(void) { volatile double temp = lbl_80564C68; lbl_8055FA08 = (float)fn_802E2C20() / lbl_80564C70; }

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
#pragma dont_inline on
s16 fn_802B6E7C(s32 arg0, s32 arg1, u32 arg2) {
    s32 scale = fn_802B6E30();
    s32 delta = arg1 - (arg2 >> 1);
    return (s16)(arg0 + delta * scale);
}
#pragma dont_inline reset
extern float lbl_80564C8C;
extern s32 fn_802B7300(s16, s16, s32, float);
void fn_802B7420(s16 arg0, s16 arg1) {
    fn_802B7300(arg0, arg1, -1, lbl_80564C8C);
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

#pragma dont_inline on
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
#pragma dont_inline reset
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

void fn_802B87A0(void) {
    fn_8026E214((void *)lbl_8055FA00, 0);
    deleteThreads__6SystemFv(lbl_8055FA48);
    if (lbl_8055FA34 != -1) {
        fn_802C6CF8();
        lbl_8055FA34 = -1;
    }
    *(s32 *)((u8 *)&lbl_804BFA70 + 4) = 0;
}

void fn_802B87F4(void) {
    if (lbl_8055FA48 != 0) {
        fn_802B869C();
        fn_802B59A4(lbl_8055FA3C);
        fn_802B0288();
        if (lbl_8055FA38 != 1 && lbl_8055FA40 != 6) {
            fn_802B4E3C();
        }
    }
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
