// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct {
    s32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 ba;
    u8 bb;
    u8 bc;
    u8 bd;
    u8 be;
    u8 bf;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
    u8 b1a;
    u8 b1b;
    u8 b1c;
    u8 b1d;
    u8 b1e;
    u8 b1f;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u8 b27;
    u8 b28;
    u8 b29;
    u8 b2a;
    u8 b2b;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u8 b2f;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
    u8 b36;
    u8 b37;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    u8 b44;
    u8 b45;
    u8 b46;
    u8 b47;
    u8 b48;
    u8 b49;
    u8 b4a;
    u8 b4b;
    u8 b4c;
    u8 b4d;
    u8 b4e;
    u8 b4f;
    u8 b50;
    u8 b51;
    u8 b52;
    u8 b53;
    u8 b54;
    u8 b55;
    u8 b56;
    u8 b57;
    u8 b58;
    u8 b59;
    u8 b5a;
    u8 b5b;
    u8 b5c;
    u8 b5d;
    u8 b5e;
    u8 b5f;
    u8 b60;
    u8 b61;
    u8 b62;
    u8 b63;
    s32 w64;
    s32 w68;
    s32 w6c;
    u8 b70;
    u8 pad71[3];
    s32 w74;
} Fn801EA59CData;
extern s32 lbl_8055EB78;
extern s32 lbl_8055EB7C;
extern char lbl_80339E08;
extern s32 fn_80265D7C(void);
extern void fn_80128668(s32);
extern void *fn_801284F8(s32, void *);
extern s32 fn_80265D7C(void);
extern void fn_80128668(s32);
extern s32 lbl_8055EB7C;
extern void *fn_801284F8(s32, void *);
extern unsigned int memset(void *, int, unsigned int);
extern char lbl_80339E08;
void fn_801EA4C4(void) {
    s32 *base;
    lbl_8055EB7C = 1;
    lbl_8055EB78 = (s32)fn_801284F8(0x608, &lbl_80339E08);
    memset((void *)0, 0, 0x608);
    base = (s32 *)*(s32 *)&lbl_8055EB78;
    base[0x5E8 / 4] = 0;
    base[0x5EC / 4] = 1;
    base[0x5F0 / 4] = 2;
    base[0x5F4 / 4] = 3;
    base[0x5F8 / 4] = 4;
    base[0x5FC / 4] = 5;
    base[0x600 / 4] = 6;
    base[0x604 / 4] = 7;
}

void fn_801EA56C(void) {
    fn_80128668(*(s32 *)&lbl_8055EB78);
    lbl_8055EB78 = 0;
    lbl_8055EB7C = 0;
}

void fn_801EA59C(s32 arg0, s32 arg1, void *arg2) {
    u8 *entry;
    s32 version;
    s32 allow;
    u8 active;

    entry = (u8 *)(*(s32 *)&lbl_8055EB78 + arg0 * 0xBC);
    version = *(s32 *)arg2;
    *(s32 *)(entry + 0x44) = version;
    entry[0x48] = ((u8 *)arg2)[0x4];
    entry[0x49] = ((u8 *)arg2)[0x5];
    entry[0x4a] = ((u8 *)arg2)[0x6];
    entry[0x4b] = ((u8 *)arg2)[0x7];
    entry[0x4c] = ((u8 *)arg2)[0x8];
    entry[0x4d] = ((u8 *)arg2)[0x9];
    entry[0x4e] = ((u8 *)arg2)[0xa];
    entry[0x4f] = ((u8 *)arg2)[0xb];
    entry[0x50] = ((u8 *)arg2)[0xc];
    entry[0x51] = ((u8 *)arg2)[0xd];
    entry[0x52] = ((u8 *)arg2)[0xe];
    entry[0x53] = ((u8 *)arg2)[0xf];
    entry[0x54] = ((u8 *)arg2)[0x10];
    entry[0x55] = ((u8 *)arg2)[0x11];
    entry[0x56] = ((u8 *)arg2)[0x12];
    entry[0x57] = ((u8 *)arg2)[0x13];
    entry[0x58] = ((u8 *)arg2)[0x14];
    entry[0x59] = ((u8 *)arg2)[0x15];
    entry[0x5a] = ((u8 *)arg2)[0x16];
    entry[0x5b] = ((u8 *)arg2)[0x17];
    entry[0x5c] = ((u8 *)arg2)[0x18];
    entry[0x5d] = ((u8 *)arg2)[0x19];
    entry[0x5e] = ((u8 *)arg2)[0x1a];
    entry[0x5f] = ((u8 *)arg2)[0x1b];
    entry[0x60] = ((u8 *)arg2)[0x1c];
    entry[0x61] = ((u8 *)arg2)[0x1d];
    entry[0x62] = ((u8 *)arg2)[0x1e];
    entry[0x63] = ((u8 *)arg2)[0x1f];
    entry[0x64] = ((u8 *)arg2)[0x20];
    entry[0x65] = ((u8 *)arg2)[0x21];
    entry[0x66] = ((u8 *)arg2)[0x22];
    entry[0x67] = ((u8 *)arg2)[0x23];
    entry[0x68] = ((u8 *)arg2)[0x24];
    entry[0x69] = ((u8 *)arg2)[0x25];
    entry[0x6a] = ((u8 *)arg2)[0x26];
    entry[0x6b] = ((u8 *)arg2)[0x27];
    entry[0x6c] = ((u8 *)arg2)[0x28];
    entry[0x6d] = ((u8 *)arg2)[0x29];
    entry[0x6e] = ((u8 *)arg2)[0x2a];
    entry[0x6f] = ((u8 *)arg2)[0x2b];
    entry[0x70] = ((u8 *)arg2)[0x2c];
    entry[0x71] = ((u8 *)arg2)[0x2d];
    entry[0x72] = ((u8 *)arg2)[0x2e];
    entry[0x73] = ((u8 *)arg2)[0x2f];
    entry[0x74] = ((u8 *)arg2)[0x30];
    entry[0x75] = ((u8 *)arg2)[0x31];
    entry[0x76] = ((u8 *)arg2)[0x32];
    entry[0x77] = ((u8 *)arg2)[0x33];
    entry[0x78] = ((u8 *)arg2)[0x34];
    entry[0x79] = ((u8 *)arg2)[0x35];
    entry[0x7a] = ((u8 *)arg2)[0x36];
    entry[0x7b] = ((u8 *)arg2)[0x37];
    entry[0x7c] = ((u8 *)arg2)[0x38];
    entry[0x7d] = ((u8 *)arg2)[0x39];
    entry[0x7e] = ((u8 *)arg2)[0x3a];
    entry[0x7f] = ((u8 *)arg2)[0x3b];
    entry[0x80] = ((u8 *)arg2)[0x3c];
    entry[0x81] = ((u8 *)arg2)[0x3d];
    entry[0x82] = ((u8 *)arg2)[0x3e];
    entry[0x83] = ((u8 *)arg2)[0x3f];
    entry[0x84] = ((u8 *)arg2)[0x40];
    entry[0x85] = ((u8 *)arg2)[0x41];
    entry[0x86] = ((u8 *)arg2)[0x42];
    entry[0x87] = ((u8 *)arg2)[0x43];
    entry[0x88] = ((u8 *)arg2)[0x44];
    entry[0x89] = ((u8 *)arg2)[0x45];
    entry[0x8a] = ((u8 *)arg2)[0x46];
    entry[0x8b] = ((u8 *)arg2)[0x47];
    entry[0x8c] = ((u8 *)arg2)[0x48];
    entry[0x8d] = ((u8 *)arg2)[0x49];
    entry[0x8e] = ((u8 *)arg2)[0x4a];
    entry[0x8f] = ((u8 *)arg2)[0x4b];
    entry[0x90] = ((u8 *)arg2)[0x4c];
    entry[0x91] = ((u8 *)arg2)[0x4d];
    entry[0x92] = ((u8 *)arg2)[0x4e];
    entry[0x93] = ((u8 *)arg2)[0x4f];
    entry[0x94] = ((u8 *)arg2)[0x50];
    entry[0x95] = ((u8 *)arg2)[0x51];
    entry[0x96] = ((u8 *)arg2)[0x52];
    entry[0x97] = ((u8 *)arg2)[0x53];
    entry[0x98] = ((u8 *)arg2)[0x54];
    entry[0x99] = ((u8 *)arg2)[0x55];
    entry[0x9a] = ((u8 *)arg2)[0x56];
    entry[0x9b] = ((u8 *)arg2)[0x57];
    entry[0x9c] = ((u8 *)arg2)[0x58];
    entry[0x9d] = ((u8 *)arg2)[0x59];
    entry[0x9e] = ((u8 *)arg2)[0x5a];
    entry[0x9f] = ((u8 *)arg2)[0x5b];
    entry[0xa0] = ((u8 *)arg2)[0x5c];
    entry[0xa1] = ((u8 *)arg2)[0x5d];
    entry[0xa2] = ((u8 *)arg2)[0x5e];
    entry[0xa3] = ((u8 *)arg2)[0x5f];
    entry[0xa4] = ((u8 *)arg2)[0x60];
    entry[0xa5] = ((u8 *)arg2)[0x61];
    entry[0xa6] = ((u8 *)arg2)[0x62];
    entry[0xa7] = ((u8 *)arg2)[0x63];
    *(s32 *)(entry + 0xa8) = *(s32 *)((u8 *)arg2 + 0x64);
    *(s32 *)(entry + 0xac) = *(s32 *)((u8 *)arg2 + 0x68);
    *(s32 *)(entry + 0xb0) = *(s32 *)((u8 *)arg2 + 0x6c);
    *(s32 *)(entry + 0xb4) = *(s32 *)((u8 *)arg2 + 0x70);
    entry[0xB4] = ((u8 *)arg2)[0x70];
    *(s32 *)(entry + 0xB8) = *(s32 *)((u8 *)arg2 + 0x74);

    active = 1;
    if (version != 0x50) {
        allow = 0;
        if (version == 0x52 && fn_80265D7C() != 0) {
            allow = 1;
        }
        if (allow == 0) active = 0;
    }

    entry[0] = active;
    *(s32 *)(entry + 8) = arg1;
    *(s32 *)(entry + 4) = arg0;

    if (arg0 >= *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0)) {
        *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E0) = arg0 + 1;
    }

    if (fn_802794AC(*(s32 *)arg2, 0) != 0
        && arg0 >= *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4)) {
        *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4) = arg0 + 1;
    }
}

s32 fn_801EA994(void) {
    return *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + 0x5E4);
}

s32 fn_801EA9A0(s32 arg0) {
    return lbl_8055EB78 + (arg0 * 0xBC);
}

s32 fn_801EA9B0(s32 arg0) {
    return *(s32 *)&lbl_8055EB78 + (*(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78) + (arg0 << 2) + 0x5E8) * 0xBC);
}

s32 fn_801EA9CC(s32 arg0) {
    return lbl_8055EB78 + (arg0 * 0xBC);
}

void fn_801EA9DC(s32 arg0, void *arg1) {
    s32 base;
    s32 value;
    s32 index;
    u8 *entry;

    base = *(s32 *)&lbl_8055EB78;
    value = *(s32 *)((u8 *)arg1 + 4);
    entry = (u8 *)base + arg0 * 0xBC;
    *(s32 *)(entry + 0xC) = *(s32 *)arg1;
    index = value - 1;
    *(s32 *)(entry + 0x10) = value;
    *(s32 *)(entry + 0x14) = *(s32 *)((u8 *)arg1 + 8);
    *(f32 *)(entry + 0x18) = *(f32 *)((u8 *)arg1 + 0xC);
    *(s32 *)(entry + 0x1C) = *(s32 *)((u8 *)arg1 + 0x10);
    *(f32 *)(entry + 0x20) = *(f32 *)((u8 *)arg1 + 0x14);
    *(f32 *)(entry + 0x24) = *(f32 *)((u8 *)arg1 + 0x18);
    *(f32 *)(entry + 0x28) = *(f32 *)((u8 *)arg1 + 0x1C);
    *(f32 *)(entry + 0x2C) = *(f32 *)((u8 *)arg1 + 0x20);
    *(s32 *)(entry + 0x30) = *(s32 *)((u8 *)arg1 + 0x24);
    *(u8 *)(entry + 0x34) = *(u8 *)((u8 *)arg1 + 0x28);
    *(f32 *)(entry + 0x38) = *(f32 *)((u8 *)arg1 + 0x2C);
    *(s32 *)(entry + 0x3C) = *(s32 *)((u8 *)arg1 + 0x30);
    *(s32 *)(entry + 0x40) = *(s32 *)((u8 *)arg1 + 0x34);
    if (index < 0) index = *(s32 *)((u8 *)base + 0x5E0) - 1;
    value = *(s32 *)((u8 *)base + 0x5E0) - 1;
    if (value < index) index = value;
    *(s32 *)((u8 *)base + (index << 2) + 0x5E8) = arg0;
}

void fn_801EAA94(s32 arg0, s32 arg1) {
    u8 flag;
    s32 result;
    u8 *entry;
    flag = 1;
    entry = (u8 *)(*(s32 *)&lbl_8055EB78 + arg0 * 0xBC);
    *(s32 *)(entry + 0x44) = arg1;
    if (arg1 != 0x50) {
        result = 0;
        if (arg1 == 0x52 && fn_80265D7C() != 0) result = 1;
        if (result == 0) flag = 0;
    }
    *entry = flag;
}

void fn_801EAB10(s32 arg0, s32 arg1) {
    *(s32 *)((u8 *)(*(s32 *)&lbl_8055EB78 + arg0 * 0xBC) + 8) = arg1;
}

