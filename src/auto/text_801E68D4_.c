// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef long s32;

void fn_801E6CC4(void) {
    fn_8012C4D8();
}

extern s32 fn_801E6924(void*);
extern void fn_801E598C(void);
extern void fn_802C6CF8(s32);
extern void fn_80128668(s32, s32);
extern void fn_8012ED20(s32);
extern s32 fn_8012EC90(s32);
extern s8 lbl_8055EAC8[8];
extern s32 lbl_80487CC0[8];

void fn_801E6978(void) {
    s32* var_r30 = lbl_80487CC0;
    s8* var_r29 = lbl_8055EAC8;
    s32 var_r28 = 0;
    do {
        *var_r30 = fn_8012EC90(0x4000);
        var_r28 += 1;
        *var_r29 = 0;
        var_r30 += 1;
        var_r29 += 1;
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
    fn_801E598C();
    fn_802C6CF8(var_r31[0]);
    fn_80128668((s32)arg0, 3);
}
void fn_801E6CC8(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

int fn_801E7698(void) {
    return 8;
}

