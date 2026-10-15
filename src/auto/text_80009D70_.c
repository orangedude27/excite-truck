#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000A7A8(void);
extern void fn_8000A6D8(void);
extern void fn_8000A808(void);
extern void fn_80128668(void*);
extern void fn_80009DC8(void);
extern void fn_801345D8(void*, s32, void*, s32);
extern u8 lbl_80558A14;
extern void fn_8012DDA8(void*);
extern void fn_8012E498(void*);
extern void fn_801DCDA0(void);
extern void fn_801DCDA4(void);
extern u8 lbl_8055D3B4;
extern u8 lbl_8055D3B5;
extern char lbl_8034F4C8[];
extern void fn_8012E81C(void*);
extern void fn_80129324(s32);
extern void fn_80206518(void);
extern u32 lbl_8055D3B0;
extern u32 lbl_8055D3B8;

void* fn_80009D70(void* arg0, s32 arg1) {
    void* var_r31;
    var_r31 = arg0;
    if (var_r31 == NULL) goto lbl_80009DB4;
    if (var_r31 == NULL) goto lbl_80009DB4;
    *(s32*)var_r31 = 0;
    ((s32*)var_r31)[1] = 0;
    ((s32*)var_r31)[2] = 0;
    if (arg1 <= 0) goto lbl_80009DB4;
    ((void*)var_r31);
    fn_80128668(var_r31);
lbl_80009DB4:
    return var_r31;
}

void fn_8000A644(void* arg0, void* arg1) {
    s32 count = 0;
    s32* var_r6 = (s32*)((u8*)arg0 + 0x20);
    ((s32*)arg0)[0x3E0 / 4] = ((s32*)arg1)[0x24 / 4];
    while (count < ((s32*)arg0)[0x3C0 / 4]) {
        var_r6[0x68 / 4] = ((s32*)arg1)[4 / 4];
        var_r6[0x6C / 4] = ((s32*)arg1)[0x28 / 4];
        var_r6 += 0x78 / 4;
        arg1 = (void*)((u8*)arg1 + 4);
        count++;
    }
    fn_80009DC8();
}

void fn_8000A688(void (*arg0)(void*), s32 arg1) {
    u8 sp8[0x20];
    fn_801345D8(sp8, 0x20, &lbl_80558A14, arg1);
    arg0(sp8);
}

void fn_8000AADC(void) {
    fn_8000A7A8();
}

void fn_8000AAE0(void) {
    fn_8000A808();
}

void fn_8000AB44(void) {
    fn_8000A6D8();
}

void fn_8000A7A8(void) {
    char* base = (char*)&lbl_8034F4C8;
    if (lbl_8055D3B4 != 0) {
        fn_8012DDA8(base + 0x58);
    }
    fn_8012DDA8(base + 0x18);
    if (lbl_8055D3B5 != 0) {
        fn_8012DDA8(base + 0x98);
    }
    fn_801DCDA0();
}

void fn_8000A808(void) {
    char* lbl_8034F4C8_ptr = (char*)&lbl_8034F4C8;
    fn_801DCDA4();
    fn_8012E498(lbl_8034F4C8_ptr + 0x18);
    if (lbl_8055D3B4 != 0) {
        fn_8012E498(lbl_8034F4C8_ptr + 0x58);
    }
    if (lbl_8055D3B5 != 0) {
        fn_8012E498(lbl_8034F4C8_ptr + 0x98);
    }
}

