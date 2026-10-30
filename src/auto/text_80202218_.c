// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "revolution/MTX/vec.h"

extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern void fn_8012850C(s32, const char *);
extern void *fn_8002F37C(void (*)(void), void *, s32, s32);
extern void *fn_802CE3A4(s32, s32, s32);
extern s32 fn_802CE630(void *, const char *, s32);
extern void fn_802E30C8(const char *);
extern void fn_802025D4(void);
extern int sprintf(char *, const char *, ...);
extern char lbl_8033B9F8[];
extern char lbl_804888B8[];
extern char lbl_8055B418[];
extern char lbl_8055B420[];
extern float lbl_805630A4;
extern int lbl_8055B414, lbl_8055ECDC;
extern int lbl_8055ECC0;
extern int lbl_8055ECC4;
extern int lbl_8055ECC8;
extern int lbl_8055ECCC;
extern int lbl_8055ECD0;
extern unsigned char lbl_8055ECE0;
extern void fn_802CE6C0(int);
extern int fn_802CE49C(int);
extern int fn_802CE850(int);
extern int fn_80128670(int);
extern void *fn_801E87A8(void);
extern int fn_802C9C58(int);
extern void fn_802C7A44(void);
extern int fn_802C7040(int);
extern void fn_802C7A50(void);
extern float lbl_805630A0;
extern unsigned char lbl_80488964[];
extern void fn_802C6CF8(int);

extern int lbl_8055B410;
extern int lbl_8055ECD4;
extern int fn_801E85A4(void);
extern int fn_8012C33C(void);
extern int fn_802C6FC0(int, int, int);
int fn_80202218(void) {
    if (fn_801E85A4() == 1) {
        return lbl_8055ECD4;
    }
    return lbl_8055B410;
}

int fn_80202248(int arg0) {
    int result = -1;
    if (fn_8012C33C() != 0) {
        result = fn_802C6FC0(arg0, 0, 0);
    }
    return result;
}

#pragma push
#pragma dont_inline on
void fn_802022A0(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -1) {
        fn_802C6CF8(temp_r0);
        *arg0 = -1;
    }
}
#pragma pop

#pragma push
#pragma paired_single off
#pragma paired off
int fn_802022E4(const Vec *arg0) {
    f32 temp_f1;
    f32 var_f31;
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    var_f31 = lbl_805630A0;
    var_r31 = 0;
    var_r30 = 0;
    var_r29 = 0;
    goto test;
loop:
    temp_f1 = PSVECSquareDistance(arg0, (const Vec *)((char *)lbl_8055ECC4 + var_r31));
    if (temp_f1 < var_f31) {
        var_f31 = temp_f1;
        var_r30 = var_r29;
    }
    var_r31 += 0x10;
    var_r29 += 1;
test:
    if (var_r29 < lbl_8055ECC0)
        goto loop;
    return var_r30;
}
#pragma pop

int fn_80202378(int arg0, int arg1, int arg2, int arg3) {
    if (arg3 >= lbl_8055ECC0) return -1;
    if (arg3 >= (arg1 * 2) + 1) return -1;
    return ((arg2 * (arg3 - arg1)) + ((lbl_8055ECC0 * 0x64) + arg0)) % lbl_8055ECC0;
}

void *fn_802023C8(void) { return lbl_80488964; }

#pragma push
#pragma dont_inline on
void fn_802023D4(void) {
    void *manager;
    void *interface;
    void **vtable;
    s32 count;
    s32 i;
    s32 offset;
    s32 *entry;
    char name1[32];
    char name2[32];
    f32 position[3];

    lbl_8055ECD4 = 7;
    manager = fn_80131808(lbl_8033B9F8);
    vtable = *(void ***)manager;
    interface = ((void *(*)(void *, void *))vtable[2])(manager, lbl_8033B9F8 + 0x10);
    vtable = *(void ***)interface;
    count = ((s32 (*)(void *, void *))vtable[7])(interface, lbl_8055B418);
    lbl_8055ECC0 = count;
    if (count > 0) {
        fn_8012850C((count << 4) + 0x10, lbl_8033B9F8 + 0x1C);
        lbl_8055ECC4 = (s32)fn_8002F37C(fn_802025D4, NULL, 0x10, count);
        lbl_8055ECC8 = (s32)fn_802CE3A4(lbl_8055ECC0, 0x20, 0x20000);
        i = 0;
        offset = 0;
        while (i < lbl_8055ECC0) {
            entry = (s32 *)((char *)lbl_8055ECC4 + offset);
            sprintf(name1, lbl_8055B420, i);
            vtable = *(void ***)interface;
            ((void (*)(void *, void *, void *))vtable[13])(position, interface, name1);
            ((f32 *)entry)[0] = position[0];
            ((f32 *)entry)[1] = position[1];
            ((f32 *)entry)[2] = position[2];
            sprintf(name2, lbl_8033B9F8 + 0x28, i);
            entry[3] = fn_802CE630((void *)lbl_8055ECC8, name2, 0);
            offset += 0x10;
            i++;
        }
    } else {
        lbl_8055ECC4 = 0;
        lbl_8055ECC8 = 0;
    }
    fn_80131818(manager);
    lbl_8055ECCC = fn_80202248((int)(lbl_8033B9F8 + 0x34));
    if (lbl_8055ECCC != -1) {
        fn_802E30C8(lbl_8033B9F8 + 0x44);
    }
    lbl_8055ECD0 = fn_80202248((int)(lbl_8033B9F8 + 0x5C));
    if (lbl_8055ECD0 != -1) {
        fn_802E30C8(lbl_8033B9F8 + 0x6C);
    }
    lbl_8055B414 = -1;
    *(f32 *)(lbl_804888B8 + 0xAC) = lbl_805630A4;
    *(f32 *)(lbl_804888B8 + 0xB0) = lbl_805630A4;
    *(f32 *)(lbl_804888B8 + 0xB4) = lbl_805630A4;
    lbl_8055ECE0 = 0;
    lbl_8055ECDC = -1;
    *(s32 *)(lbl_804888B8 + 0x18) = -1;
    *(s32 *)(lbl_804888B8 + 0x1C) = -1;
    *(s32 *)(lbl_804888B8 + 0x20) = -1;
    *(s32 *)(lbl_804888B8 + 0x24) = -1;
    *(s32 *)(lbl_804888B8 + 0xA8) = 0;
}

void fn_802025D4(void) {

}

void fn_802025D8(void) {
    extern int lbl_8055ECC0;
    extern int lbl_8055ECC4;
    extern int lbl_8055ECC8;
    extern int lbl_8055ECCC;
    extern int lbl_8055ECD0;
    extern int lbl_804888E0[];
    extern void fn_802022A0(int *);
    extern void fn_802CE6C0(int);
    extern int fn_802CE49C(int);
    extern int fn_80128670(int);
    int offset;
    int count;

    fn_802022A0(&lbl_8055ECD0);
    fn_802022A0(&lbl_8055ECCC);
    count = 0;
    offset = 0;
    goto test;
loop:
    fn_802CE6C0(*(int *)((char *)lbl_8055ECC4 + offset + 12));
    offset += 0x10;
    count += 1;
test:
    if (count < lbl_8055ECC0)
        goto loop;
    if (lbl_8055ECC0 > 0) {
        fn_802CE49C(lbl_8055ECC8);
        lbl_8055ECC8 = 0;
        if (lbl_8055ECC4 != 0)
            fn_80128670(lbl_8055ECC4 - 0x10);
        lbl_8055ECC4 = 0;
    }
    lbl_8055ECC0 = 0;
    lbl_804888E0[0x20] = 0;
}

void fn_8020268C(void) {
    int saved;
    unsigned int flags = *(unsigned int *)((char *)fn_801E87A8() + 16);
    int arg = 2;
    if ((flags >> 1) & 1) arg = 1;
    saved = fn_802C9C58(arg);
    if (lbl_8055ECCC != -1) { fn_802C7A44(); fn_802C7040(lbl_8055ECCC); fn_802C7A50(); }
    fn_802C9C58(0);
    if (lbl_8055ECD0 != -1) { fn_802C7A44(); fn_802C7040(lbl_8055ECD0); fn_802C7A50(); }
    fn_802C9C58(saved);
}

void fn_80202718(int arg0) {
    extern int lbl_804888E0[], lbl_804888D0[];
    extern int lbl_8055B414, lbl_8055ECC0, lbl_8055ECC4;
    extern unsigned char lbl_8055ECD8;
    extern float lbl_805630A4;
    extern void *fn_802C86DC(void);
    extern int fn_801E85B4(void);
    extern void fn_801E86F8(int);
    extern void *fn_801EA9A0(void);
    extern void fn_801DCEF0(void);
    extern int fn_802CE728(int);
    extern void fn_802C7458(int);
    int i, center, result, count, selected;
    int *data; float x, y, z, a, b, c; void *obj;
    lbl_804888E0[0x20] = 0;
    if (lbl_8055ECD8) { fn_801E86F8(-1); if (*(short *)(*(int *)((char *)fn_801EA9A0() + 8) + 0x30) >= 0) fn_801DCEF0(); return; }
    if (lbl_8055ECC0 == 0) { fn_8020268C(); return; }
    obj = fn_802C86DC();
    center = fn_802022E4((Vec *)((char *)obj + 0x24));
    lbl_804888D0[fn_801E85B4()] = center;
    data = (int *)(lbl_8055ECC4 + (((center + 1) % lbl_8055ECC0) * 16));
    x = *(float *)data - *(float *)((char *)obj + 0x24);
    y = *(float *)((char *)data + 4) - *(float *)((char *)obj + 0x28);
    z = *(float *)((char *)data + 8) - *(float *)((char *)obj + 0x2C);
    a = x * *(float *)((char *)obj + 0x18) + y * *(float *)((char *)obj + 0x1C) + z * *(float *)((char *)obj + 0x20);
    b = x * *(float *)obj + y * *(float *)((char *)obj + 4) + z * *(float *)((char *)obj + 8);
    c = x * *(float *)((char *)obj + 0xC) + y * *(float *)((char *)obj + 0x10) + z * *(float *)((char *)obj + 0x14);
    selected = a < lbl_805630A4 ? -1 : 1;
    center = fn_80202218();
    count = lbl_8055B414;
    if (count >= 0) { center = 0; selected = count; }
    i = 0;
    while ((result = fn_80202378(selected, center, (a < lbl_805630A4) ? -1 : 1, i)) >= 0) {
        data = (int *)(lbl_8055ECC4 + result * 16);
        fn_802CE744(data[3], 0); result = fn_802CE728(data[3]);
        if (result != -1) { fn_802C7458(-13); count = lbl_804888E0[0x20]; if ((unsigned int)count < 0x20) { lbl_804888E0[count] = result; lbl_804888E0[0x20] = count + 1; } }
        i++;
    }
    fn_8020268C();
}

extern int lbl_8055ECDC;
extern int fn_802023E4(void);
extern int fn_80202218(void);
extern void *fn_802023C8(void);
extern int fn_802022E4(const Vec *);
extern int fn_80202378(int, int, int, int);
extern int fn_802CE744(int, int);
extern int fn_802CE4F4(int);
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80202924(void) {
    int temp, center, index, result;
    int *data;
    Vec local;

    if (lbl_8055ECC0 <= 0)
        return;
    lbl_8055ECDC = -1;
    if (lbl_8055ECE0 != 0) {
        local = *(Vec *)fn_802023C8();
        temp = fn_802022E4(&local);
        lbl_8055ECDC = temp;
        center = fn_80202218();
        index = 0;
        goto test;
loop:
        data = (int *)(lbl_8055ECC4 + (result << 4));
        fn_802CE744(data[3], 0);
        index++;
test:
        result = fn_80202378(temp, center, 1, index);
        if (result >= 0)
            goto loop;
    }
    lbl_8055ECE0 = 0;
    fn_802CE4F4(lbl_8055ECC8);
}

void fn_802029FC(void) {
    extern double lbl_805630A8;
    extern float lbl_805630A4, lbl_805630B0, lbl_805630B4;
    extern int lbl_804888E0[];
    extern float fn_801E7E18(void);
    extern double fn_8002EFB4();
    extern int fn_802C7A3C(float, float, float);
    extern void fn_802C70AC(int, float *, int, int);
    float values[12];
    float first;
    int *base, *entry;
    int result, index;

    first = fn_801E7E18();
    result = fn_802C7A3C(lbl_805630B0 - (float)fn_8002EFB4(first, lbl_805630A8),
                         lbl_805630A4, lbl_805630B4);
    values[0] = lbl_805630B0;
    values[1] = lbl_805630A4;
    values[2] = lbl_805630A4;
    values[3] = lbl_805630A4;
    values[4] = lbl_805630B0;
    values[5] = lbl_805630A4;
    values[6] = lbl_805630A4;
    values[7] = lbl_805630A4;
    values[8] = lbl_805630B0;
    values[9] = lbl_805630A4;
    values[10] = lbl_805630A4;
    values[11] = lbl_805630A4;
    entry = lbl_804888E0;
    base = entry;
    index = 0;
    goto test;
loop:
    fn_802C70AC(*entry, values, result, 8);
    entry++;
    index++;
test:
    if (index < base[0x20])
        goto loop;
}

#pragma scheduling on
#pragma pop
extern unsigned char lbl_8055ECE0;
extern int lbl_8055ECC8, lbl_8055ECCC, lbl_8055ECD0;
extern int lbl_804888E0[];
extern float lbl_805630A4, lbl_805630B0, lbl_805630B4;
extern double lbl_805630A8;
extern double fn_8002EFB4(double);
extern int fn_802C7A3C(float, float, float);
extern void fn_802C70AC(int, float *, int, int);
int fn_802CE850(int);
void fn_802CE6C0(int);
int fn_802CE49C(int);
int fn_80128670(int);
void fn_802022A0(int *);
void *fn_801E87A8(void);
int fn_802C9C58(int);
void fn_802C7A44(void);
int fn_802C7040(int);
void fn_802C7A50(void);
#pragma scheduling invalid_target
void fn_80202AD4(float *arg0) {
    float c, b, a;
    a = arg0[0];
    b = arg0[1];
    c = arg0[2];
    ((float *)lbl_80488964)[0] = a;
    ((float *)lbl_80488964)[1] = b;
    ((float *)lbl_80488964)[2] = c;
    lbl_8055ECE0 = 1;
}
#pragma scheduling on
int fn_80202B00(void) {
    extern int lbl_8055ECC0;
    extern int lbl_8055ECC4;
    extern int fn_802CE850(int);
    int offset;
    int count;
    int i;

    if (lbl_8055ECC0 <= 0)
        goto return_zero;
    count = 0;
    i = 0;
    offset = 0;
    goto test;
loop:
    if (fn_802CE850(*(int *)((char *)lbl_8055ECC4 + offset + 12)) == 1)
        count++;
    offset += 16;
    i++;
test:
    if (i < lbl_8055ECC0)
        goto loop;
    return count;
return_zero:
    return 0;
}

