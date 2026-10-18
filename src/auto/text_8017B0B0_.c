// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E490;
extern int lbl_8055E488;
extern int lbl_8055E48C;
extern void fn_80128670(void*);
extern void fn_8012850C(void*, void*);
extern int fn_8002F37C(void*, int, int, int);
extern char lbl_80331CB8[16];
extern void fn_8017D330(void);
extern void fn_80179E00(void*);
extern void fn_8017B198(void*);
extern void fn_80179D94(void);
extern void fn_8017B2D0(void*, float, float, float, float);
extern void fn_80179D08(void);
extern char lbl_80331CC4[];
extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80558DC4;

void *fn_8017B0B0(void *arg0) {
    fn_80179D08();
    *(int *)((char *)arg0 + 0x184) = 0;
    *(char **)arg0 = lbl_80331CC4;
    *((char *)arg0 + 0x1E8) = 0;
    return arg0;
}

void fn_8017B0F8(void *arg0, float *arg1) {
    fn_80179D94();
    *(volatile int *)((char *)arg0 + 0xD0) = 0;
    fn_8017B2D0(arg0, arg1[2], arg1[3], arg1[4], arg1[5]);
    *(int *)((char *)arg0 + 0x184) = 0;
    fn_8017B198(arg0);
}

void fn_8017B164(void *arg0) {
    fn_80179E00(arg0);
    fn_8017B198(arg0);
}

extern float lbl_80561BA8, lbl_80561BAC, lbl_80561BB0, lbl_80561BB4;
void fn_8017B2D0(void *arg0, float a, float b, float c, float d) {
    float x = lbl_80561BAC * b;
    float y = lbl_80561BAC * c;
    float z = lbl_80561BAC * d;
    float sx = lbl_80561BB0 * x;
    float sy = lbl_80561BB0 * y;
    float sz = lbl_80561BB0 * z;
    float sa = lbl_80561BAC * a;
    float ia = lbl_80561BB4 / sa;
    float ix = lbl_80561BB4 / sx;
    float iy = lbl_80561BB4 / sy;
    float iz = lbl_80561BB4 / sz;
    *(float *)((char *)arg0 + 0xf8) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0xfc) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0x100) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0x108) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0x10c) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0x110) = lbl_80561BA8;
    *(float *)((char *)arg0 + 0x104) = iz;
    *(float *)((char *)arg0 + 0x114) = iy;
    *(float *)((char *)arg0 + 0xd4) = sa;
    *(float *)((char *)arg0 + 0xd8) = sx;
    *(float *)((char *)arg0 + 0xf4) = ix;
    *(float *)((char *)arg0 + 0xdc) = sy;
    *(float *)((char *)arg0 + 0xe0) = sz;
    *(float *)((char *)arg0 + 0xe4) = ia;
    *(float *)((char *)arg0 + 0xe8) = ix;
    *(float *)((char *)arg0 + 0xec) = iz;
    *(float *)((char *)arg0 + 0xf0) = iy;
    *(unsigned int *)((char *)arg0 + 0x148) = *(unsigned int *)((char *)arg0 + 0xf4);
    *(unsigned int *)((char *)arg0 + 0x14c) = *(unsigned int *)((char *)arg0 + 0xf8);
    *(unsigned int *)((char *)arg0 + 0x150) = *(unsigned int *)((char *)arg0 + 0xfc);
    *(unsigned int *)((char *)arg0 + 0x154) = *(unsigned int *)((char *)arg0 + 0x100);
    *(unsigned int *)((char *)arg0 + 0x158) = *(unsigned int *)((char *)arg0 + 0x104);
    *(unsigned int *)((char *)arg0 + 0x15c) = *(unsigned int *)((char *)arg0 + 0x108);
    *(unsigned int *)((char *)arg0 + 0x160) = *(unsigned int *)((char *)arg0 + 0x10c);
    *(unsigned int *)((char *)arg0 + 0x164) = *(unsigned int *)((char *)arg0 + 0x110);
    *(unsigned int *)((char *)arg0 + 0x168) = *(unsigned int *)((char *)arg0 + 0x114);
}

void fn_8017B4AC(float *arg0, float *arg1) {
    float x = arg0[0x13C / 4] + arg1[0];
    float y = arg0[0x140 / 4] + arg1[1];
    float z = arg0[0x144 / 4] + arg1[2];
    arg0[0x13C / 4] = x;
    arg0[0x140 / 4] = y;
    arg0[0x144 / 4] = z;
}

extern void fn_8017B4E0(void *, void *);
void fn_8017B5D4(void *arg0, int arg1, int arg2, float *arg3, float *arg4, int arg5, float *arg6, int arg7, float arg8) {
    int count;
    int index;
    void *entry;
    if (*(int *)((char *)arg0 + 0x1E4) < 16) {
        if (lbl_8055E488 < lbl_8055E48C) {
            index = lbl_8055E488;
            count = index * 0x28;
            lbl_8055E488 = index + 1;
            entry = (char *)lbl_8055E490 + count;
        } else {
            entry = 0;
        }
        if (entry != 0) {
            *(int *)((char *)entry + 0) = arg1;
            *(int *)((char *)entry + 4) = arg2;
            *(float *)((char *)entry + 8) = arg3[0] * arg8;
            *(float *)((char *)entry + 0xC) = arg3[1] * arg8;
            *(float *)((char *)entry + 0x10) = arg3[2] * arg8;
            if (arg6 != 0) {
                *(float *)((char *)entry + 0x14) = arg6[0];
                *(float *)((char *)entry + 0x18) = arg6[1];
                *(float *)((char *)entry + 0x1C) = arg6[2];
            } else {
                *(float *)((char *)entry + 0x14) = arg4[0];
                *(float *)((char *)entry + 0x18) = arg4[1];
                *(float *)((char *)entry + 0x1C) = arg4[2];
            }
            *(int *)((char *)entry + 0x20) = arg5;
            *(int *)((char *)entry + 0x24) = arg7;
            count = *(int *)((char *)arg0 + 0x1E4);
            *(void **)((char *)arg0 + 0x1A4 + count * 4) = entry;
            *(int *)((char *)arg0 + 0x1E4) = count + 1;
        }
    }
    fn_8017B4E0(arg3, arg4);
}

extern float lbl_80561BA8;
#pragma scheduling off
void fn_8017B6A8(void *arg0) {
    float value = lbl_80561BA8;
    *(int *)((char *)arg0 + 0x1E4) = 0;
    *(float *)((char *)arg0 + 0x188) = value;
    *(float *)((char *)arg0 + 0x18C) = value;
    *(float *)((char *)arg0 + 0x190) = value;
    *(float *)((char *)arg0 + 0x194) = value;
    *(float *)((char *)arg0 + 0x198) = value;
    *(float *)((char *)arg0 + 0x19C) = value;
    *(float *)((char *)arg0 + 0x1A0) = value;
}

extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80558DC4;
extern void PSVECCrossProduct(void *, const void *, const void *);
void fn_8017B6D4(void *arg0, float *arg1, float *arg2) {
    float sp8, spC, sp10;
    sp8 = arg2[0] - *(float *)((char *)arg0 + 0x60);
    spC = arg2[1] - *(float *)((char *)arg0 + 0x64);
    sp10 = arg2[2] - *(float *)((char *)arg0 + 0x68);
    PSVECCrossProduct((char *)arg0 + 0x124, &sp8, arg1);
    arg1[0] += *(float *)((char *)arg0 + 0x118);
    arg1[1] += *(float *)((char *)arg0 + 0x11c);
    arg1[2] += *(float *)((char *)arg0 + 0x120);
}

void fn_8017B778(void *arg0, float *arg1, float *arg2) {
    float sp8, spC, sp10;
    sp8 = arg2[0] - *(float *)((char *)arg0 + 0x60);
    spC = arg2[1] - *(float *)((char *)arg0 + 0x64);
    sp10 = arg2[2] - *(float *)((char *)arg0 + 0x68);
    PSVECCrossProduct((char *)arg0 + 0x178, &sp8, arg1);
    arg1[0] += *(float *)((char *)arg0 + 0x16c);
    arg1[1] += *(float *)((char *)arg0 + 0x170);
    arg1[2] += *(float *)((char *)arg0 + 0x174);
}

#pragma scheduling on
void fn_8017C7BC(void) {

}

void fn_8017C7C0(void) {

}

void fn_8017C7C4(void) {

}

typedef unsigned int u32;
typedef float f32;
extern void fn_8017A580(u32, u32, u32, u32, u32, u32);
void fn_8017CFFC(void* arg0, u32* arg1, f32* arg2, f32* arg3, u32 arg_sp0) {
    u32 a0 = arg1[0];
    u32 a1 = arg1[1];
    u32 a2 = arg1[2];
    u32 a3 = arg1[3];
    u32 a4 = arg1[4];
    u32 a5 = arg1[5];
    u32 a6 = arg1[6];
    u32 a7 = arg1[7];
    u32 a8 = arg1[8];
    u32 a9 = arg1[9];
    u32 a10 = arg1[10];
    u32 a11 = arg1[11];
    *(u32*)((char*)arg0 + 0x3C) = a0;
    *(u32*)((char*)arg0 + 0x40) = a1;
    *(u32*)((char*)arg0 + 0x44) = a2;
    *(u32*)((char*)arg0 + 0x48) = a3;
    *(u32*)((char*)arg0 + 0x4C) = a4;
    *(u32*)((char*)arg0 + 0x50) = a5;
    *(u32*)((char*)arg0 + 0x54) = a6;
    *(u32*)((char*)arg0 + 0x58) = a7;
    *(u32*)((char*)arg0 + 0x5C) = a8;
    *(u32*)((char*)arg0 + 0x60) = a9;
    *(u32*)((char*)arg0 + 0x64) = a10;
    *(u32*)((char*)arg0 + 0x68) = a11;
    fn_8017A580(a5, a6, a7, a8, a9, a10);
    *(f32*)((char*)arg0 + 0x118) = arg2[0];
    *(f32*)((char*)arg0 + 0x11C) = arg2[1];
    *(f32*)((char*)arg0 + 0x120) = arg2[2];
    *(f32*)((char*)arg0 + 0x124) = arg3[0];
    *(f32*)((char*)arg0 + 0x128) = arg3[1];
    *(f32*)((char*)arg0 + 0x12C) = arg3[2];
}

extern unsigned int fn_801B60F4(void *, float);
extern void fn_801B6428(unsigned int, void *);
extern void fn_801B63E0(unsigned int, void *);
void fn_8017D0C8(void *arg0) {
    unsigned int next = fn_801B60F4((char *)arg0 + 0x60, *(float *)((char *)arg0 + 0x2C));
    unsigned int old = *(unsigned int *)((char *)arg0 + 0x184);
    if (next != old) {
        if (old != 0) fn_801B6428(old, arg0);
        *(unsigned int *)((char *)arg0 + 0x184) = next;
        if (next != 0) fn_801B63E0(next, arg0);
    }
}

void fn_8017D140(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}

extern void fn_8017A804(void);
int fn_8017D274(void *arg0, void *arg1) {
    fn_8017A804();
    *(float *)((char *)arg1 + 0x14) = *(float *)((char *)arg0 + 0x118);
    *(float *)((char *)arg1 + 0x18) = *(float *)((char *)arg0 + 0x11C);
    *(float *)((char *)arg1 + 0x1C) = *(float *)((char *)arg0 + 0x120);
    return 0x20;
}

void fn_8017D2C8(void) {
    fn_8017B3A8();
}

void fn_8017D2CC(int arg0) {
    lbl_8055E48C = arg0;
    lbl_8055E488 = 0;
    fn_8012850C((char*)(arg0 * 0x28 + 0x10), &lbl_80331CB8);
    lbl_8055E490 = fn_8002F37C(fn_8017D330, 0, 0x28, arg0);
}

void fn_8017D330(void) {

}

void fn_8017D334(void) {
    int value = lbl_8055E490;
    lbl_8055E488 = 0;
    lbl_8055E48C = 0;
    if (value != 0) fn_80128670((char*)value - 0x10);
}

void fn_8017D358(void) {

}

int fn_8017D35C(void) { return 0x20; }

unsigned int fn_8017D364(void) { return 1; }

void fn_8017D36C(void) {

}

