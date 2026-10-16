// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

typedef struct SrcCoef {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
} SrcCoef;

extern SrcCoef lbl_802FDF30[8];
extern s32 lbl_8055D610;
extern s32 fn_8000DA10(void);
void fn_80128668(void*);
void fn_80128670(s32);
void fn_80131818(s32);
s32 fn_8001F89C();

void fn_8001EF38(void* alarm) {
    fn_8001EFF0(fn_8001F528(alarm));
}

void fn_8001EF5C(void) {
    fn_8001F7E4();
}

void fn_8001EF60(void* alarm) {
    fn_8001F89C(alarm, fn_8000DA10());
}

void fn_8001EF98(void) {
    fn_8001F89C();
}

void fn_8001EF9C(void) {
    fn_8001F388();
}

void fn_8001EFA0(void) {
    fn_8001F9A4();
}

void fn_8001EFA4(void) {
    fn_8001FA20();
}

void fn_8001EFA8(void) {
    fn_8001FA8C();
}

void fn_8001EFAC(void) {
    fn_8001F3AC();
}

void fn_8001EFB0(void) {
    fn_8001F908();
}

void fn_8001EFB4(void) {
    fn_8001F724();
}

void fn_8001EFB8(void) {
    fn_8001F76C();
}

void fn_8001EFBC(void) {
    fn_8001F780();
}

void fn_8001EFC0(void) {
    fn_8001FAC8();
}

void fn_8001EFC4(void) {
    fn_8001FBE4();
}

void fn_8001EFC8(void) {
    fn_8001F578();
}

void fn_8001EFCC(void* alarm) {
    fn_8001F578(fn_8001F2C8(alarm));
}

f32* __AXFXGetSrcCoef(u32 i) {
    return (f32*)&lbl_802FDF30[i];
}

