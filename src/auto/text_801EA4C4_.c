// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
typedef float f32;
extern s32 lbl_8055EB78;
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
    s32 value;
    s32 index;
    u8 *entry;

    value = *(s32 *)((u8 *)arg1 + 4);
    entry = (u8 *)&lbl_8055EB78 + arg0 * 0xBC;
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
    if (index < 0) {
        index = *(s32 *)((u8 *)&lbl_8055EB78 + 0x5E0) - 1;
    }
    value = *(s32 *)((u8 *)&lbl_8055EB78 + 0x5E0) - 1;
    if (value < index) {
        index = value;
    }
    *(s32 *)((u8 *)&lbl_8055EB78 + (index << 2) + 0x5E8) = arg0;
}

