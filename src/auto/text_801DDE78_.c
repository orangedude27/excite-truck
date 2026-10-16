// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef s32 (*UnkFunc)(s32);
extern void* lbl_8055E9C0;
extern void* lbl_8055E9BC;
extern s32 lbl_8055E9C4;
extern void* lbl_8055E9C8;
extern void* lbl_8055E9CC;
extern u32 lbl_80339478[];
extern u32 lbl_80486F30[];
s32 fn_80145E70(void*);
s32 fn_802E2C20(void);
void fn_801DDFE8(void* arg0) {
    f32 temp_e8, temp_e4, temp_e0, temp_dc;
    f32 temp_d8, temp_d4, temp_d0, temp_cc, temp_c8;
    f32 temp_a0, temp_9c, temp_98, temp_94, temp_90;
    f32 temp_8c, temp_88, temp_84, temp_80;

    temp_80 = *(f32*)((u8*)arg0 + 0x80);
    temp_84 = *(f32*)((u8*)arg0 + 0x84);
    temp_88 = *(f32*)((u8*)arg0 + 0x88);
    temp_8c = *(f32*)((u8*)arg0 + 0x8c);
    temp_90 = *(f32*)((u8*)arg0 + 0x90);
    temp_94 = *(f32*)((u8*)arg0 + 0x94);
    temp_98 = *(f32*)((u8*)arg0 + 0x98);
    temp_9c = *(f32*)((u8*)arg0 + 0x9c);
    temp_a0 = *(f32*)((u8*)arg0 + 0xa0);
    temp_c8 = *(f32*)((u8*)arg0 + 0xc8);
    temp_cc = *(f32*)((u8*)arg0 + 0xcc);
    temp_d0 = *(f32*)((u8*)arg0 + 0xd0);
    temp_d4 = *(f32*)((u8*)arg0 + 0xd4);
    temp_d8 = *(f32*)((u8*)arg0 + 0xd8);
    temp_dc = *(f32*)((u8*)arg0 + 0xdc);
    temp_e0 = *(f32*)((u8*)arg0 + 0xe0);
    temp_e4 = *(f32*)((u8*)arg0 + 0xe4);
    temp_e8 = *(f32*)((u8*)arg0 + 0xe8);

    *(f32*)((u8*)arg0 + 0xa4) = temp_80;
    *(f32*)((u8*)arg0 + 0xa8) = temp_84;
    *(f32*)((u8*)arg0 + 0xac) = temp_88;
    *(f32*)((u8*)arg0 + 0xb0) = temp_8c;
    *(f32*)((u8*)arg0 + 0xb4) = temp_90;
    *(f32*)((u8*)arg0 + 0xb8) = temp_94;
    *(f32*)((u8*)arg0 + 0xbc) = temp_98;
    *(f32*)((u8*)arg0 + 0xc0) = temp_9c;
    *(f32*)((u8*)arg0 + 0xc4) = temp_a0;
    *(f32*)((u8*)arg0 + 0xec) = temp_c8;
    *(f32*)((u8*)arg0 + 0xf0) = temp_cc;
    *(f32*)((u8*)arg0 + 0xf4) = temp_d0;
    *(f32*)((u8*)arg0 + 0xf8) = temp_d4;
    *(f32*)((u8*)arg0 + 0xfc) = temp_d8;
    *(f32*)((u8*)arg0 + 0x100) = temp_dc;
    *(f32*)((u8*)arg0 + 0x104) = temp_e0;
    *(f32*)((u8*)arg0 + 0x108) = temp_e4;
    *(f32*)((u8*)arg0 + 0x10c) = temp_e8;
}

void fn_801DE0A4(void) {
    lbl_8055E9BC = 0;
    lbl_8055E9C8 = 0;
    lbl_8055E9C4 = 0;
    lbl_8055E9C0 = (void*)fn_80145E70(&lbl_80339478);
    lbl_8055E9CC = (void*)fn_802E2C20();
}

void fn_801DE0E8(void) {
    if (lbl_8055E9C0 != 0) {
        (*(UnkFunc*)(*(u32*)((u32*)lbl_8055E9C0 + 2) + 8))(1);
    }
    lbl_8055E9C0 = 0;
}

void fn_801DE12C(void) {
    lbl_8055E9CC = (void*)fn_802E2C20();
}

void fn_801DE150(void) {

}
