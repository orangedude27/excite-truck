// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef signed char s8;
typedef long s32;

void fn_801E6CC4(void) {
    fn_8012C4D8();
}

extern void fn_801E6924(void*);
extern void fn_801E598C(s32);
extern void fn_802C6CF8(s32);
extern void fn_80128668(s32);
extern void fn_8012ED20(s32);
extern s32 fn_8012EC90(s32);
extern s8 lbl_8055EAC8[8];
extern s32 lbl_80487CC0[8];

extern s32 fn_801E5E24(s32, void*, s32, void*);
extern void fn_801BFD34(void*, void*, s32);
extern void fn_80015B20(void*, void*, s32);
extern void fn_802C70AC(s32, void*, s32, s32);
extern void fn_802E317C(const char*, ...);
extern char lbl_80339A20[];
s32 fn_801E68D4(void) {
    u8* var_r3 = (u8*)lbl_8055EAC8;
    s32 var_r6 = 0;
    do {
        if (var_r3[0] == 0) {
            lbl_8055EAC8[var_r6] = 1;
            return lbl_80487CC0[var_r6];
        }
        var_r3 += 1;
        var_r6 += 1;
    } while (var_r6 < 8);
    return 0;
}

#pragma dont_inline on
void fn_801E6924(void* arg0) {
    s32* var_r31 = lbl_80487CC0;
    s8* var_r30 = lbl_8055EAC8;
    s32 var_r6;
    for (var_r6 = 0; var_r6 < 8; var_r6++) {
        if (var_r31[var_r6] == (s32)arg0) {
            var_r30[var_r6] = 0;
            return;
        }
    }
    fn_802E317C(&lbl_80339A20[0], arg0);
}
#pragma dont_inline off

extern char lbl_80339A20[0x40];
void fn_801E6978(void) {
    s32* var_r30 = lbl_80487CC0;
    s8* var_r29 = lbl_8055EAC8;
    s8* var_r28_2 = lbl_8055EAC8;
    s32 var_r28 = 0;
    do {
        *var_r30++ = fn_8012EC90(0x4000);
        var_r28 += 1;
        *var_r29++ = 0;
    } while (var_r28 < 8);
}

void fn_801E69EC(void) {
    s32* var_r31 = lbl_80487CC0;
    s32 var_r30 = 0;
    do {
        fn_8012ED20(*var_r31);
        var_r30 += 1;
        var_r31 += 1;
    } while (var_r30 < 8);
}

void fn_801E6B98(void* arg0) {
    s32* var_r31 = (s32*)arg0;
    s32 temp = var_r31[5];
    if (temp != 0) {
        fn_801E6924((void*)temp);
    }
    fn_801E598C(var_r31[1]);
    fn_802C6CF8(var_r31[0]);
    fn_80128668((s32)arg0);
}
void fn_801E6CC8(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

void fn_801E75C8(void* arg0, s32 arg1) {
    u8 sp2C[0xC];
    u8 sp5C[0x18];
    s32 temp_r31;
    u8 sp38[0x24];
    u8 sp8[0x24];
    temp_r31 = fn_801E5E24(*(s32*)((u8*)arg0 + 4), (u8*)arg0 + 0x53c,
                             *(s32*)((u8*)arg0 + 8), sp38);
    fn_801BFD34(sp2C, sp5C, arg1);
    fn_80015B20(sp8, sp38, arg1);
    fn_802C70AC(*(s32*)arg0, sp8, temp_r31, -1);
}

s32 fn_801E7650(void* arg0) {
    s32 result;
    s32* ptr;
    ptr = *(s32**)((u8*)arg0 + 0x10);
    if (ptr != 0) {
        result = 0;
        if (*(s32*)((u8*)arg0 + 0x18) >= ptr[0] && *(float*)((u8*)arg0 + 0x38) >= *(float*)((u8*)ptr + 0xC)) {
            result = 1;
        }
        return result;
    }
    return 0;
}

int fn_801E7698(void) {
    return 8;
}

