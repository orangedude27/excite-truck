#include "types.h"
extern f32 lbl_8056411C;
extern f32 lbl_80564198;
extern f32 lbl_8056419C;
extern f32 lbl_805641A0;
extern f32 lbl_805641A4;
extern f32 lbl_805641A8;
extern f32 lbl_805641AC;
extern f32 lbl_805641B0;
extern f32 lbl_805641B4;
extern f32 lbl_805641B8;
extern f32 lbl_805641BC;
extern f32 lbl_805641C0;
extern f32 lbl_805641C4;
extern f32 lbl_805641C8;
extern f32 lbl_805641CC;
extern f32 lbl_805641D0;
extern f32 lbl_805641D4;
extern f32 lbl_805641D8;
extern f32 lbl_805641DC;
extern f32 lbl_805641E0;
extern f32 lbl_805641E4;
extern f32 lbl_805641E8;
__declspec(section ".sdata") extern const char lbl_8055C6E8[];
__declspec(section ".sdata") extern const char lbl_8055C6F0[];
__declspec(section ".sdata") extern const char lbl_8055C6F8[];
__declspec(section ".sdata") extern const char lbl_8055C6FC[];
__declspec(section ".sdata") extern const char lbl_8055C700[];
__declspec(section ".sdata") extern const char lbl_8055C704[];
__declspec(section ".sdata") extern const char lbl_8055C70C[];
__declspec(section ".sdata") extern const char lbl_8055C714[];
__declspec(section ".sdata") extern const char lbl_8055C718[];
__declspec(section ".sdata") extern const char lbl_8055C720[];
__declspec(section ".sdata") extern const char lbl_8055C728[];
__declspec(section ".sdata") extern const char lbl_8055C730[];
__declspec(section ".sdata") extern const char lbl_8055C738[];
__declspec(section ".sdata") extern const char lbl_8055C740[];
__declspec(section ".sdata") extern const char lbl_8055C748[];
__declspec(section ".sdata") extern const char lbl_8055C750[];
extern char lbl_80347848[];
typedef struct Vec3_80279F58 { f32 x, y, z; } Vec3_80279F58;
#pragma cplusplus on
struct Res_80279F58 {
    virtual const char *getName();
    virtual int slot3(const char *, f32, f32, f32, f32, f32);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int getInt(const char *);
    virtual void slot8();
    virtual f32 getFloat(const char *);
    virtual f32 getFloatDefault(const char *, f32);
    virtual void slot11();
    virtual u8 getByte(const char *, s32);
    virtual Vec3_80279F58 getVec(const char *);
};
struct File_80279F58 {
    virtual Res_80279F58 *getRes(const char *);
    virtual void slot1();
    virtual void slot2();
};
#pragma cplusplus reset


extern unsigned char lbl_804A1968[];
extern void *memset(void *, int, unsigned int);
extern int fn_80131808(const char *);
extern void fn_80131818(void *);
extern void fn_80279F58(void *, void *);
extern void fn_802E317C(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80347A08[];
extern const char lbl_80347A1C[];
extern const float lbl_80564120;
void fn_80279CE4(void) {
    unsigned char *p = lbl_804A1968;
    int i = 0;
    int cont;
loop:
    memset(p, 0, 0x44);
    i++;
    cont = i < 0x20;
#pragma scheduling off
    p += 0x44;
#pragma scheduling on
    if (cont)
        goto loop;
}

void fn_80279D3C(void) {
}

extern float lbl_80564108,lbl_8056410C,lbl_80564110,lbl_80564114,lbl_80564118,lbl_8056411C,lbl_80564124,lbl_80564128,lbl_8056412C,lbl_80564130,lbl_80564134,lbl_80564138,lbl_8056413C,lbl_80564140,lbl_80564144,lbl_80564148,lbl_8056414C,lbl_80564150,lbl_80564154,lbl_80564158,lbl_8056415C,lbl_80564160,lbl_80564164,lbl_80564168,lbl_8056416C,lbl_80564170,lbl_80564174,lbl_80564178,lbl_8056417C,lbl_80564180,lbl_80564184,lbl_80564188,lbl_8056418C,lbl_80564190,lbl_80564194;
#pragma push
#pragma processor 750
void fn_80279D40(void *arg0, int arg1) {
    float *f = (float *)arg0;
    int *w = (int *)arg0;
    float c20, c0C, c14, c38, c08, c10, c18, c1C, c24, c28, c2C, c30, c34, c3C, c40, c44, c48, c4C, c50, c54, c58, c5C, c60;
    float c64, c70, c74, c78, c84, c88, c7C, c68, c80;
    memset(arg0, 0, 0x138);
    c20 = lbl_80564120;
    c0C = lbl_8056410C;
    c14 = lbl_80564114;
    c38 = lbl_80564138;
    c08 = lbl_80564108;
    c10 = lbl_80564110;
    c18 = lbl_80564118;
    c1C = lbl_8056411C;
    c24 = lbl_80564124;
    c28 = lbl_80564128;
    c2C = lbl_8056412C;
    c30 = lbl_80564130;
    c34 = lbl_80564134;
    c3C = lbl_8056413C;
    c40 = lbl_80564140;
    c44 = lbl_80564144;
    c48 = lbl_80564148;
    c4C = lbl_8056414C;
    c50 = lbl_80564150;
    c54 = lbl_80564154;
    c58 = lbl_80564158;
    c5C = lbl_8056415C;
    c60 = lbl_80564160;
    f[0] = c08; f[3] = c10; f[6] = c18; f[7] = c1C; f[24] = c60;
    f[1] = c0C; f[2] = c0C; f[4] = c14; f[5] = c14;
    f[11] = c20; f[12] = c24; w[13] = 4; f[14] = c28; f[15] = c2C; f[16] = c30; f[17] = c34;
    f[8] = c38; f[9] = c38; f[10] = c3C;
    f[30] = c40; f[31] = c44; f[20] = c48; f[21] = c4C; f[22] = c50; f[23] = c54; f[25] = c58; f[26] = c5C;
    f[27] = c20; f[28] = c20; f[29] = c20;
    c64 = lbl_80564164; c70 = lbl_80564170; c74 = lbl_80564174; c78 = lbl_80564178;
    c84 = lbl_80564184; c88 = lbl_80564188; c7C = lbl_8056417C; c68 = lbl_80564168; c80 = lbl_80564180;
    f[32] = c64; f[33] = c68; f[34] = c70; f[35] = c74; f[36] = c78; f[37] = c7C; f[39] = c80; f[40] = c84; f[38] = c88;
    f[41] = c64; f[42] = c68; f[43] = c70; f[44] = c74; f[45] = c78; f[46] = c7C; f[48] = c80; f[49] = c84; f[47] = c88; f[50] = c64;
    c68 = lbl_8056416C;
    f[51] = c68; f[52] = c70; f[53] = c74; f[54] = c78; f[55] = c7C; f[57] = c80; f[58] = c84; f[56] = c88; f[59] = c64;
    f[60] = c68; f[61] = c70; f[62] = c74; f[63] = c78; f[64] = c7C; f[66] = c80; f[67] = c84; f[65] = c88;
    f[68] = lbl_80564120; f[69] = lbl_80564120; f[70] = lbl_80564120;
    f[71] = lbl_8056418C; f[72] = lbl_80564190; f[73] = lbl_80564120; f[74] = lbl_80564194;
}

#pragma cplusplus on
void fn_80279F58(void *arg0, void *arg1) {
    float *f = (float *)arg0;
    int *w = (int *)arg0;
    char name[32];
    Vec3_80279F58 tmpVec;
    File_80279F58 *file = (File_80279F58 *)arg1;
    Res_80279F58 *res;
    Res_80279F58 *res2;
    Res_80279F58 *res3;
    char *base = lbl_80347848;
    int i;
    float *dest;
    f32 v;
    f32 v2;
    fn_80279D40(arg0, (int)arg1);
    res = file->getRes(lbl_8055C6E8);
    f[0] = lbl_80564198 * res->getFloat(lbl_8055C6F0);
    f[1] = lbl_8056419C * (lbl_8056419C * (lbl_80564198 * res->getFloat(lbl_8055C6F8)));
    f[2] = lbl_8056419C * (lbl_8056419C * (lbl_80564198 * res->getFloat(lbl_8055C6FC)));
    f[3] = lbl_8056419C * (lbl_8056419C * (lbl_80564198 * res->getFloat(lbl_8055C700)));
    f[6] = lbl_805641A0 * res->getFloat(base);
    f[4] = lbl_805641A0 * res->getFloat(lbl_8055C704);
    f[7] = lbl_8056411C;
    f[5] = lbl_805641A0 * res->getFloat(lbl_8055C70C);
    f[9] = lbl_805641A0 * res->getFloat(base + 0xC);
    f[8] = lbl_805641A0 * res->getFloatDefault(base + 0x18, lbl_805641A4);
    f[10] = lbl_805641AC * res->getFloatDefault(base + 0x2C, lbl_805641A8);
    res2 = file->getRes(base + 0x38);
    f[11] = res2->getFloat(base + 0x48);
    w[13] = res2->getInt(base + 0x58);
    dest = f + 14;
    for (i = 0; i < w[13]; i++) {
        sprintf(name, lbl_8055C714, i + 1);
        *dest++ = res2->getFloat(name);
    }
    res3 = file->getRes(base + 0x64);
    v = lbl_805641B0 * res3->getFloat(base + 0x74);
    f[20] = lbl_8056419C * v;
    f[22] = res3->getFloat(base + 0x80);
    f[21] = lbl_805641B4 * res3->getFloat(base + 0x8C);
    f[23] = res3->getFloat(base + 0x98);
    v = lbl_805641B0 * res3->getFloat(lbl_8055C718);
    f[24] = lbl_8056419C * v;
    f[26] = res3->getFloat(base + 0xA4);
    f[25] = res3->getFloat(lbl_8055C720);
    f[27] = res3->getFloatDefault(base + 0xB0, lbl_80564120);
    f[28] = res3->getFloatDefault(base + 0xC0, lbl_80564120);
    f[29] = res3->getFloatDefault(base + 0xD4, lbl_80564120);
    v2 = res->getFloatDefault(lbl_8055C728, lbl_805641B8);
    if (v2 > lbl_805641BC) {
        v2 = lbl_805641BC;
    }
    if (v2 < lbl_805641C0) {
        v2 = lbl_805641C0;
    }
    f[68] = lbl_805641C4 * v2;
    f[69] = lbl_805641C8 * res->getFloatDefault(lbl_8055C730, lbl_80564120);
    f[70] = res->getFloatDefault(base + 0xE4, lbl_80564120);
    f[72] = f[72] * res->getFloatDefault(base + 0xF0, lbl_80564120);
    v = lbl_805641B0 * res->getFloatDefault(lbl_8055C738, lbl_805641CC);
    f[30] = v / lbl_805641A0;
    v = lbl_805641B0 * res->getFloatDefault(lbl_8055C740, lbl_805641D0);
    f[31] = v / lbl_805641A0;
    tmpVec = res->getVec(base + 0x100);
    f[75] = lbl_805641D8;
    f[76] = -f[8];
    f[77] = -(f[7] - lbl_8056411C) * f[6];
    if (res->slot3(base + 0x10C, tmpVec.x, tmpVec.y, tmpVec.z, lbl_805641A0, f[76]) != 0) {
        Vec3_80279F58 add = res->getVec(base + 0x10C);
        f[75] += add.x * lbl_805641A0;
        f[76] += add.y * lbl_805641A0;
        f[77] += add.z * lbl_805641A0;
    }
    file->getRes(lbl_8055C748);
    file->getRes(lbl_8055C750);
    dest = f + 32;
    for (i = 0; i < 4; i++) {
        int useAlt;
        f32 a;
        f32 b;
        f32 c;
        useAlt = 0;
        if (i == 0 || i == 1) {
            useAlt = 1;
        }
        a = res->getFloatDefault(base + 0x11C, lbl_80564120);
        b = res->getFloatDefault(base + 0x12C, lbl_80564120);
        c = res->getFloatDefault(base + 0x13C, lbl_80564120);
        if (useAlt) {
            tmpVec = res->getVec(base + 0x158);
        } else {
            tmpVec = res->getVec(base + 0x168);
        }
        dest[6] = lbl_805641C8;
        dest[1] = dest[1] * a;
        dest[2] = dest[2] * c;
        dest[3] = dest[3] * tmpVec.x;
        dest[0] = lbl_805641A0 * res->getFloatDefault(base + 0x178, lbl_805641DC);
        dest[4] = lbl_805641A0 * res->getFloatDefault(base + 0x188, lbl_805641D8);
        dest[5] = lbl_805641B0 * res->getFloatDefault(base + 0x188, lbl_805641D8) / lbl_805641A0;
        dest += 9;
    }
    f[73] = res->getFloatDefault(base + 0x198, lbl_805641E0);
    f[74] = lbl_805641E8 * res->getFloatDefault(base + 0x1B4, lbl_805641E4);
}
#pragma cplusplus reset

#pragma scheduling invalid_target
void fn_8027A714(void *arg0, const char *arg1) {
    char buf[0x100];
    void *result;

    sprintf(buf, lbl_80347A08, arg1);
    result = (void *)fn_80131808(buf);
    if (result == 0) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347A1C, buf);
    }
    fn_80279F58(arg0, result);
    fn_80131818(result);
}

extern int strcmp(const char *, const char *);
extern const char lbl_80347A34[];
extern void fn_8027A888(float *);
#pragma scheduling invalid_target
char *fn_8027A798(char *arg0) {
    char *entry;
    char *input;
    int i;
    char c;
    int left;
    char *dst;

    input = arg0;
    entry = (char *)lbl_804A1968;
    i = 0;
    /* Search the fixed 32-entry name table for an existing match; if found,
       return the pointer to its associated data (entry + 0x20). */
    while (i < 0x20) {
        if (strcmp(entry, input) == 0) {
            return entry + 0x20;
        }
        i++;
        entry += 0x44;
    }

    /* Otherwise claim the first empty slot, copy the name (up to 0x20 bytes),
       initialize its data, and return it; log and fail if the table is full. */
    entry = (char *)lbl_804A1968;
    for (i = 0; i < 0x20; i++) {
        if (*entry == 0) {
            dst = entry;
            left = 0x20;
            goto copy_start;
        dec:
            if (--left <= 0) {
                dst[-1] = 0;
                goto done;
            }
        copy_start:
            c = *input++;
            *dst++ = c;
            if (c != 0) {
                goto dec;
            }
        done:
            fn_8027A888((float *)(entry + 0x20));
            return entry + 0x20;
        }
        entry += 0x44;
    }
    ((void (*)(const char *, ...))fn_802E317C)(lbl_80347A34);
    return 0;
}
#pragma scheduling on

void fn_8027A888(float *arg0) {
    float zero = lbl_80564120;
    arg0[0] = zero;
    arg0[1] = zero;
    arg0[2] = zero;
    arg0[3] = zero;
    arg0[4] = zero;
    arg0[5] = zero;
    arg0[6] = zero;
    arg0[7] = zero;
    arg0[8] = zero;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8027A8B4(void *arg0, void *arg1) {
    float s0 = *(float *)((char *)arg1 + 0);
    float s4 = *(float *)((char *)arg1 + 4);
    float s8 = *(float *)((char *)arg1 + 8);
    float sC = *(float *)((char *)arg1 + 0xC);
    float s10 = *(float *)((char *)arg1 + 0x10);
    float s14 = *(float *)((char *)arg1 + 0x14);
    float s18 = *(float *)((char *)arg1 + 0x18);
    float s1C = *(float *)((char *)arg1 + 0x1C);
    float s20 = *(float *)((char *)arg1 + 0x20);
    float p0 = *(float *)((char *)arg0 + 0) * s0;
    float p4 = *(float *)((char *)arg0 + 4) * s4;
    float p8 = *(float *)((char *)arg0 + 8) * s4;
    float pC = *(float *)((char *)arg0 + 0xC) * s4;
    float p50 = *(float *)((char *)arg0 + 0x50) * s8;
    float p54 = *(float *)((char *)arg0 + 0x54) * s8;
    float p30 = *(float *)((char *)arg0 + 0x30) * sC;
    float p110 = *(float *)((char *)arg0 + 0x110) * s1C;
    float p114 = *(float *)((char *)arg0 + 0x114) * s20;
    float p84 = *(float *)((char *)arg0 + 0x84) * s18;
    float p88 = *(float *)((char *)arg0 + 0x88) * s10;
    float p8C = *(float *)((char *)arg0 + 0x8C) * s14;
    float pA8 = *(float *)((char *)arg0 + 0xA8) * s18;
    float pAC = *(float *)((char *)arg0 + 0xAC) * s10;
    float pB0 = *(float *)((char *)arg0 + 0xB0) * s14;
    float pCC = *(float *)((char *)arg0 + 0xCC) * s18;
    float pD0 = *(float *)((char *)arg0 + 0xD0) * s10;
    float pD4 = *(float *)((char *)arg0 + 0xD4) * s14;
    float pF0 = *(float *)((char *)arg0 + 0xF0) * s18;
    float pF4 = *(float *)((char *)arg0 + 0xF4) * s10;
    float pF8 = *(float *)((char *)arg0 + 0xF8) * s14;
    *(float *)((char *)arg0 + 0) = p0;
    *(float *)((char *)arg0 + 4) = p4;
    *(float *)((char *)arg0 + 8) = p8;
    *(float *)((char *)arg0 + 0xC) = pC;
    *(float *)((char *)arg0 + 0x54) = p54;
    *(float *)((char *)arg0 + 0x50) = p50;
    *(float *)((char *)arg0 + 0x30) = p30;
    *(float *)((char *)arg0 + 0x110) = p110;
    *(float *)((char *)arg0 + 0x114) = p114;
    *(float *)((char *)arg0 + 0x84) = p84;
    *(float *)((char *)arg0 + 0x88) = p88;
    *(float *)((char *)arg0 + 0x8C) = p8C;
    *(float *)((char *)arg0 + 0xA8) = pA8;
    *(float *)((char *)arg0 + 0xAC) = pAC;
    *(float *)((char *)arg0 + 0xB0) = pB0;
    *(float *)((char *)arg0 + 0xCC) = pCC;
    *(float *)((char *)arg0 + 0xD0) = pD0;
    *(float *)((char *)arg0 + 0xD4) = pD4;
    *(float *)((char *)arg0 + 0xF0) = pF0;
    *(float *)((char *)arg0 + 0xF4) = pF4;
    *(float *)((char *)arg0 + 0xF8) = pF8;
}
#pragma scheduling on
#pragma pop
